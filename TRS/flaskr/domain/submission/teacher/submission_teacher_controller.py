from flask import Blueprint, request
from flaskr.submission.submission_models import Submission
from flaskr.assignment.assignment_student_models import StudentOnAssignment
from flaskr.utils.exceptions import BadRequestException
from flaskr.account.account_services import AccountService
from flaskr.utils.base_response import BaseResponse


# class SubmissionTeacherController:
#   submission_teacher_controller = Blueprint('submission_teacher_controller', __name__)
  
#   @classmethod
#   @submission_teacher_controller.route('/api/submissions', methods=['GET'])
#   @AccountService.authenticate
#   @AccountService.verify_teacher
#   def getList():
