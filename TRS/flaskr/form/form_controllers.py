
from flask import Blueprint, request
from flaskr.submission.submission_models import Submission
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
    used_testcases = request.json.get('used_testcases')
    ordered_testcases = request.json.get('ordered_testcases')
    feedback = request.json.get('feedback')
    submission = (Submission.query
      .join(Student, Student.id == Submission.student_id)
      .join(Recommendation, Recommendation.submission_id == Submission.id)
      .filter(Student.id == request.student.id, Recommendation.status == 6)
      .filter_by(id=submission_id)
      .with_entities()
      .first())
    if not submission:
      raise NotFoundException('SUBMISSION_NOT_FOUND')
    if not request.json.get('scores') or not (0 < int(request.json.get('score')) <= 10):
      raise BadRequestException('SCORE_REQUIRED')
    if not ordered_testcases or len(ordered_testcases) <= 0:
      raise BadRequestException('ORDERED_TESTCASE_REQUIRED')
    form = Form(
      submission_id=submission_id,
      list_used_tcids=used_testcases, 
      time_ordered_tcids=ordered_testcases,
      feedback=feedback
    )
    form.save()
    
    # Update current recommendation
    recommendation = Recommendation.query.filter_by(submission_id=submission_id).first()
    recommendation.is_filled_form = True
    return BaseResponse.ok()
    
    
  

    