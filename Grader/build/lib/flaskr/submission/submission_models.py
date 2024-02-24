from flaskr.database import db
from sqlalchemy.dialects.postgresql import UUID
from sqlalchemy.sql.sqltypes import DateTime
from sqlalchemy import CheckConstraint
from sqlalchemy.dialects.postgresql import ARRAY

class Submission(db.Model):
  __tablename__ = 'submissions'
  
  # id
  student_id = db.Column(db.String, unique=False, nullable=False)
  assignment_id = db.Column(UUID(as_uuid=True), unique=False, nullable=False)
  
  # array of multiple testcase with pass/fail = 1/0
  # each number of testcase is differenct from assignments
  scores = db.Column(ARRAY(db.Boolean), unique=False, nullable=False)
  
  files = db.Column(ARRAY(db.String), unique=False, nullable=False)
  
  def __str__(self) -> str:
    s = [
      f'student_id = {self.student_id}',
      f'assignment_id = {self.assignment_id}',
      f'scores = {self.scores}'
    ]
    s = ', '.join(s)
    s = f'Submission[{s}]'
    return s