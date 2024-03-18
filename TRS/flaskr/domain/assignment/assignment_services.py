from datetime import datetime
from TRS.flaskr.domain.account.account_models import Account
from TRS.flaskr.domain.account.account_services import AccountService
from TRS.flaskr.domain.assignment.assignment_teacher_models import TeacherOnAssignment
from TRS.flaskr.domain.teacher.teacher_models import Teacher
from flaskr.utils.exceptions import BadRequestException

from flaskr.domain.assignment.assignment_models import Assignment


class AssignmentService:
  @staticmethod
  def create(name: str, start_date: datetime, end_date: datetime, author_id: str, description):
    try: 
      a = Assignment(name=name, start_date=start_date, end_date=end_date, author_id=author_id, description=description)
      a.save()
    except:
      raise BadRequestException('INVALID_ERROR')
    
  @staticmethod
  def allowed_file(filename):
    # Define the allowed file extensions
    allowed_extensions = {'xlsx', 'xls'}

    # Check if the file has an allowed extension
    return '.' in filename and \
      filename.rsplit('.', 1)[1].lower() in allowed_extensions
      
  @staticmethod
  def add_teacher_on_assignment(assignment_id: str, author_id: str, email: str, name: str):
    account = Account.query.filter_by(email=email).first()
    # If account student exist
    if account and account.type.name == 'STUDENT':
      raise BadRequestException('ACCOUNT_MUST_BE_TEACHER')
    
    # if account teacher exist. Check if teacher is already on assignment. If not, add teacher to assignment
    elif account and account.type.name == 'TEACHER':
      teacher = Teacher.query.filter_by(account_id=account.id).first()
      teacher_on_assignment = TeacherOnAssignment.query.filter_by(teacher_id=teacher.id, assignment_id=assignment_id).first()
      if teacher_on_assignment:
        raise BadRequestException('TEACHER_ALREADY_ON_ASSIGNMENT')
      if teacher:
        if author_id == teacher.id:
          new_teacher_on_assignment = TeacherOnAssignment(teacher_id=teacher.id, assignment_id=assignment_id, is_leader=True)
          new_teacher_on_assignment.save()
        else:
          new_teacher_on_assignment = TeacherOnAssignment(teacher_id=teacher.id, assignment_id=assignment_id)
          new_teacher_on_assignment.save()
    
    # if account is not found. Create new account and add to teacher on assignment
    else:
      _, teacher = AccountService.create_account(name=name, email=email, type='TEACHER', mssv=None)
      if teacher:
        teacher_on_assignment = TeacherOnAssignment(teacher_id=teacher.id, assignment_id=assignment_id)