from datetime import datetime
from flaskr.utils.exceptions import BadRequestException

from flaskr.assignment.assignment_models import Assignment


class AssignmentService:
  @staticmethod
  def create(name: str, start_date: datetime, end_date: datetime, author_id: str, description):
    try: 
      a = Assignment(name=name, start_date=start_date, end_date=end_date, author_id=author_id, description=description)
      a.save()
    except:
      raise BadRequestException('INVALID_ERROR')