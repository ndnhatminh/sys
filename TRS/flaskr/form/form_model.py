from flaskr.database import db
from sqlalchemy.dialects.postgresql import UUID
from sqlalchemy.sql.sqltypes import DateTime
from sqlalchemy import CheckConstraint, Column, ForeignKey
from sqlalchemy.dialects.postgresql import ARRAY
from sqlalchemy.orm import relationship
import uuid


class Form(db.Model):
  __tablename__ = 'form'
  
  # id
  id = Column(UUID(as_uuid=True), unique=True, nullable=False, primary_key=True, default=uuid.uuid4)
  submission_id = Column(UUID(as_uuid=True), ForeignKey('submissions.id'), unique=True, nullable=False)
  submission = relationship("Submission", back_populates="form", uselist=False)
  
  # recommend_id = db.Column(UUID(as_uuid=True), unique=False, nullable=False)
  list_used_tcids = db.Column(ARRAY(db.Integer), unique=False, nullable=True)
  time_ordered_tcids = db.Column(ARRAY(db.Integer), unique=False, nullable=True)
  scores = db.Column(db.Integer, unique=False, nullable=False)
  
  
  def __str__(self) -> str:
    s = [
      f'student_id = {self.student_id}',
      # f'assignment_id = {self.recommend_id}',
      f'list_used_tcids = {self.list_used_tcids}',
      f'time_ordered_tcids = {self.time_ordered_tcids}',
      f'scores = {self.scores}',
    ]
    s = ', '.join(s)
    s = f'form[{s}]'
    return s