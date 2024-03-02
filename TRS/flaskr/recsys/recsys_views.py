import logging
from flask import Blueprint, request, Response
from flask.globals import current_app
from flask.json import jsonify
from flaskr.utils.base_response import BaseResponse
from flaskr.utils.exceptions import BadRequestException
from flaskr.utils.file import File
from constants import FILE_SUBMISSION_PATH, GRADER_URL
from werkzeug.utils import secure_filename
import os
from flaskr.account.account_services import AccountService, Account
from flaskr.utils.time import timeNow
from sqlalchemy import select
from flaskr.database import db
from flaskr.student.student_models import Student
from flaskr.submission.submission_models import Submission
from flaskr.assignment.assignment_models import Assignment
from flaskr.recsys.recsys_models import Recommendation
from flask import copy_current_request_context
from response import success, fail
from constants.constants import rec_apr1, rec_apr2, rec_apr3
from flaskr.recsys.algorithm import recommendation_1, recommendation_2, recommendation_3, recommendation_4
from datetime import date, timedelta, time, datetime
from constants.constants import list_testcase_ids as Clist_testcase_ids
from flaskr.utils.text import encrypt, decrypt
from flask import render_template
from flaskr.utils.file import readall
from flaskr.utils.limitthread import LimitThread

blueprint = Blueprint('recsys', __name__)

# @blueprint.route('/api/recommend', methods=['POST'])
# @AccountService.authenticate
# @AccountService.verify_student
# def receive_file():
#   submission_id = request.json.get('submission_id')
#   submission = Submission.query \
#     .join(Assignment, Assignment.id == Submission.assignment_id) \
#     .filter(Submission.id == submission_id, 
#             Submission.assignment_id == request.json.get('assignment_id')
#             ) \
#     .first()
#   if not submission:
#     raise BadRequestException('SUBMISSION_NOT_FOUND')
#   list_fileinfos = submission.files
#   mssv = request.student.mssv
#   # Cham bai vua nop
#   jsondata = {
#     "list_fileinfos": list_fileinfos,
#     "student_id": str(mssv),
#     "submission_id": str(submission_id)
#   }
#   requests.post(url=GRADER_URL, json=jsondata)
  
#   # Tao Recommendation tam
#   recr = Recommendation(status=1, submission_id=submission_id, list_testcase_id=[])
#   recr.save()
  
#   # recr_id = recr.id
#   # encrypt_id = encrypt(recr_id)
#   # url = f'https://fp232be.codepractice.net/api/testcases/{encrypt_id}'
#   # recr.url = url
#   # recr.save()
  
#   # message = f'Link:\n{url}'
  
#   return BaseResponse.ok()
  
@blueprint.route('/api/testcases', methods=['GET'])
@AccountService.authenticate
@AccountService.verify_student
def show_recommended_testcases():
  sub_id = request.args.get('submission_id')
  try:
    recr = Recommendation.query.filter_by(submission_id = sub_id).first()
    if not recr:
      return  BaseResponse({
        "files": [],
        "status": None,
      }, None).to_response()
  except:
    return BaseResponse({
        "files": [],
        "status": None,
      }, None).to_response()
  student_id = request.student.mssv
  
  if recr.status == 1:
    m = 'Hệ thống đang chấm điểm bài của bạn, vui lòng reload lại trang sau khoảng 3-5 phút'
  elif recr.status == 2:
    m = 'Hệ thống không còn testcases để bạn kiểm tra.'
  elif recr.status == 3:
    # m = 'Hiển thị kết quả gợi ý'
    m = None
  elif recr.status == 4:
    if recr.list_false_tcids is None:
      m = 'Bạn chưa làm đúng tất cả testcases của lần gợi ý trước. Bạn hãy nộp lại một lần làm bài mới để xem testcases làm sai.'
    else:
      list_false_tcids = [str(x) for x in recr.list_false_tcids]
      m = f'Bạn chưa làm đúng tất cả testcases của lần gợi ý trước.\nCác testcases sai là: {", ".join(list_false_tcids)}'
  elif recr.status == 5:
    m = 'Bạn đã đạt số lần gợi ý tối đa trong 1 ngày'
  else:
    m = 'Error'
  
  if m and recr.status != 4:
    return fail (
      message=m
    )
  else:
    if recr.status == 4:
      last_recr_status_3 = Recommendation.query.join(Submission, Recommendation.submission_id == Submission.id).filter(Submission.student_id == student_id).filter(Recommendation.status == 3).filter(Recommendation.updated_at < recr.updated_at).order_by(Recommendation.updated_at.desc()).first()
      # lấy dữ liệu các testcase lên từ lần Recommendation status == 3 gần nhất
      lids = last_recr_status_3.list_testcase_id
      message = m
    else:
      # lấy dữ liệu các testcase lên từ lần Recommend hiện tại
      lids = recr.list_testcase_id
      message = ''
    lfiles = []
    for id in lids:
      dic_t = {
        "id": id,
        "events": readall(os.path.join('solution/workspace', f'tc_{id}')),
        "expect": readall(os.path.join('solution/workspace', f'tc_{id}.out')),
      }
      lfiles.append(dic_t)
    # message = m if m is not None else ''
    return BaseResponse({
      # "student_id": str(student_id),
      # "list_testcase_id": lids,
      "files": lfiles,
      "status": recr.status,
    }, message).to_response()

@blueprint.route('/api/internalrecommend', methods=['POST',])
def internal_recommend():
  @copy_current_request_context
  def thread_recommend(dic_data):
    submission_id = dic_data['submission_id']
    student_id = str(dic_data['student_id'])
    print('dic data: ', dic_data)
    
    # Note: kiem tra nếu kết quả chấm là đúng tất cả lần recommend trước thì mới thực hiện recommend
    # thông báo kết quả này trên trang web như thế nào? dùng bảng recommendation được ko? - được: dùng status = 4
    pass_all = True
    list_false_tcids = []
    
    student = Student.query.filter_by(mssv=student_id).first()
    # last_r = Recommendation.query.filter(Recommendation.status == 3).order_by(Recommendation.updated_at.desc()).first()
    last_r = Recommendation.query.join(Submission, Recommendation.submission_id == Submission.id).filter(Submission.student_id == student.id).filter(Recommendation.status == 3).order_by(Recommendation.updated_at.desc()).first()
    
    if last_r:
      # kiểm tra thử đúng hết tất cả testcase trong last_recommendation không?
      sub = Submission.query.filter(Submission.id == submission_id).order_by(Submission.updated_at.desc()).first()
      
      list_rtcids = last_r.list_testcase_id
      # print(type(Clist_testcase_ids[0]), type(list_rtcids[0]), list_rtcids[0])
      for tcid in list_rtcids:
        idx = Clist_testcase_ids.index(tcid)
        print(student_id, tcid, idx, sub.scores[idx], flush=True) # in để debug
        if sub.scores[idx] == False:
          list_false_tcids.append(tcid)
          pass_all = False
          # break # comment để debug
    if not pass_all:
      r = Recommendation.query.filter(Recommendation.submission_id == submission_id).first()
      r.status = 4
      r.list_false_tcids = list_false_tcids
      r.save()
      return fail(message='not full pass previous recommended testcases')
    
    # Note: kiểm tra nếu trong ngày hôm nay đã có 5 lần req rồi thì không đưa ra gợi ý, status = 5
    today = date.today()
    start = datetime.combine(today, time=time(0,0,0))
    # list_recommendation = Recommendation.query.filter(Recommendation.status == 3).filter(Recommendation.updated_at >= start).order_by(Recommendation.updated_at.desc()).all()
    list_recommendation = Recommendation.query.join(Submission, Recommendation.submission_id == Submission.id).filter(Submission.student_id == student.id).filter(Recommendation.status == 3).filter(Recommendation.updated_at >= start).order_by(Recommendation.updated_at.desc()).all()
    if len(list_recommendation) >= 5:
      r = db.session.execute(db.select(Recommendation).where(Recommendation.submission_id==submission_id)).scalar_one()
      r.status = 5
      r.save()
      
      return fail(message='limit number of request: 5')
    
    # bắt đầu gợi ý
    submission_id = dic_data['submission_id']
    student_id = str(dic_data['student_id'])

    sub = Submission.query.filter(Submission.id == submission_id).order_by(Submission.updated_at.desc()).first()
    assignment_id = sub.assignment_id
      
    if student_id in rec_apr1:
      recommendation_2(submission_id, assignment_id, student_id)
    elif student_id in rec_apr2:
      recommendation_3(submission_id, assignment_id, student_id)
    elif student_id in rec_apr3:
      recommendation_4(submission_id, assignment_id, student_id)
    else:
      print('Error')
      assert(False)
  
  dic_data = {
    "list_fileinfos": request.json.get('list_fileinfos'),
    "student_id": str(request.json.get('student_id')),
    "submission_id": request.json.get('submission_id')
  }
  # thread = threading.Thread(target=thread_recommend, args=(dic_data,))
  thread = LimitThread(target=thread_recommend, args=(dic_data,))
  # thread.daemon = True
  thread.start()
  
  return success()