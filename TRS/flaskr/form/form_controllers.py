
from flask import Blueprint, request
from flaskr.submission.submission_models import Submission
from sqlalchemy import not_, or_
from sqlalchemy import false
from flaskr.utils.base_response import BaseResponse
from flaskr.form.form_models import Form
from flaskr.utils.exceptions import BadRequestException, NotFoundException
from flaskr.recsys.recsys_models import Recommendation
from flaskr.student.student_models import Student

from flaskr.account.account_services import AccountService


class FormController:
  form_controller = Blueprint('form_controller', __name__)
  
  @classmethod
  @form_controller.route('/api/forms', methods=['POST'])
  @AccountService.authenticate
  @AccountService.verify_student
  def create_form():
    '''
    Student need to fill out form first before getting new testcase sample.
    '''
    submission_id = request.json.get('submission_id')
    used_testcases = list(request.json.get('used_testcases'))
    ordered_testcases = list(request.json.get('ordered_testcases'))
    scores = request.json.get('scores')
    feedback = request.json.get('feedback')
    last_recommendation = (Recommendation.query
      .join(Submission, Submission.id == Recommendation.submission_id)
      .join(Student, Student.id == Submission.student_id)
      .order_by(Recommendation.created_at.desc())
      .filter(
        Student.id == request.student.id, 
        Submission.id == submission_id, 
        Recommendation.is_filled_form == False,
        (Recommendation.status == 3),
        )
      .first())
    if not last_recommendation:
      raise NotFoundException('SUBMISSION_NOT_FOUND_OR_NOT_AVAILABLE')
    if not request.json.get('scores') or not (0 < int(scores) <= 5):
      raise BadRequestException('SCORE_REQUIRED')
    if not ordered_testcases or len(ordered_testcases) <= 0:
      raise BadRequestException('ORDERED_TESTCASE_REQUIRED')
    if not used_testcases or len(used_testcases) <= 0:
      raise BadRequestException('USED_TESTCASE_LIST_TESTCASE_REQUIRED')
    if last_recommendation and len(last_recommendation.list_testcase_id) > 0:
      for item in used_testcases:
        if item not in last_recommendation.list_testcase_id:
          raise BadRequestException('USED_TESTCASE_LIST_NOT_CORRECT')
      for item in ordered_testcases:
        if item not in last_recommendation.list_testcase_id:
          raise BadRequestException('USED_TIMES_TESTCASE_LIST_NOT_CORRECT')

    exist_form = Form.query.filter_by(submission_id=submission_id).first()
    if exist_form:
      raise BadRequestException('FORM_IS_EXISTED')
    
    form = Form(
      submission_id=submission_id,
      list_used_tcids=used_testcases, 
      time_ordered_tcids=ordered_testcases,
      scores=int(scores),
      feedback=feedback
    )
    form.save()
    
    # Update previous recommendation
    recommendation = Recommendation.query.filter_by(submission_id=submission_id).first()
    recommendation.is_filled_form = True
    recommendation.save()
    return BaseResponse.ok()
    

  

    