import logging
from flask import Blueprint, request, Response
from flask.globals import current_app
from flask.json import jsonify
# from flaskr.utils.file import File
from werkzeug.utils import secure_filename
import os
# from flaskr.utils.time import timeNow
from sqlalchemy import select
from flaskr.database import db
from grading_app.app1sub import gradeOneSubmission
# from flaskr.student.student_models import Student
from flaskr.submission.submission_models import Submission
import threading
from flask import copy_current_request_context
# from grading_app.appallsub import insertSubmissionToDB
import requests
from constants import BACKEND_CORE_URL
from flaskr.utils.limitthread import LimitThread

blueprint = Blueprint('grader', __name__)

@blueprint.route('/api/hello', methods=['GET',])
def hello():
  return 'hello'

@blueprint.route('/api/grader', methods=['POST',])
def grade_and_update_submission():
  # list_fileinfos = request.form.get('list_fileinfos')
  # student_id = request.form.get('student_id')
  # submission_id = request.form.get('submission_id')
  
  '''
  Use thread to run grader
  Then update to submission
  '''
  @copy_current_request_context
  def grade_and_update_submission_thread(dic_data):
    print(f'{dic_data["student_id"]}: start grading', flush=True)
    submission_id = dic_data['submission_id']
    # cham bai
    list_scores = gradeOneSubmission(dic_data)
    print(list_scores, flush=True)
    # cap nhat lai submission da co (co san files)
    sub = Submission.query.filter_by(id=submission_id).first()
    print('sub', sub, flush=True)
    sub.scores = list_scores
    sub.status = 'SUCCESS'
    sub.save()

    print(f'{dic_data["student_id"]}: graded', flush=True)
    # dua ra goi y: remove - chuyen qua ben kia lam
    # Gui api qua ben backend-core de xu ly
    # print(f'{BACKEND_CORE_URL}/api/internalrecommend')
    requests.post(url=f'{BACKEND_CORE_URL}/api/internalrecommend', json=dic_data)
  
  student_id = str(request.json.get('student_id'))
  # print(f'student_id = {student_id}', flush=True)
  dic_data = {
    "list_fileinfos": request.json.get('list_fileinfos'),
    "student_id": student_id,
    "submission_id": request.json.get('submission_id')
  }
  # thread = threading.Thread(target=grade_and_update_submission_thread, args=(dic_data,))
  # thread = LimitThread(target=grade_and_update_submission_thread, args=(dic_data,))
  # thread.start()
  
  grade_and_update_submission_thread(dic_data)
  
  data = {
    'status': 'success',
    'data': [],
    'message': ''
  }
  # print(list_fileinfos, student_id, submission_id)
  return data

# @blueprint.route('/api/grader/insert_init_submissions', methods=['POST',])
# def insert_init_submissions():
#   @copy_current_request_context
#   def insert_init_submissions_thread():
#     insertSubmissionToDB()
  
#   thread = threading.Thread(target=insert_init_submissions_thread, args=())
#   # thread.daemon = True
#   thread.start()
  
#   data = {
#     'status': 'success',
#     'data': [],
#     'message': ''
#   }
#   # print(list_fileinfos, student_id, submission_id)
#   return data