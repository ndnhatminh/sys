from flask import Blueprint, request
from flaskr.student.student_models import Student
from flaskr.assignment.assignment_student_models import StudentOnAssignment
from flaskr.assignment.assignment_services import AssignmentService
from flaskr.teacher.teacher_models import Teacher
from flaskr.utils.exceptions import BadRequestException, NotFoundException
from flaskr.account.account_services import AccountService, Account
from flaskr.utils.base_response import BaseResponse
from flaskr.assignment.assignment_models import Assignment
from datetime import datetime
import pandas as pd
date_format = date_format = '%Y-%m-%dT%H:%M:%SZ'  # The format of the date string


class AssignmentController:
  assignment_controller = Blueprint('assignment_controller', __name__)
  
  @classmethod
  @assignment_controller.route('/api/assignments', methods=['POST'])
  @AccountService.authenticate
  def create_assignment():
    '''
    TEACHER
    '''
    account = request.account
    if account.type.name == 'STUDENT':
      raise BadRequestException('PERMISSION_DENIED')
    body = request.get_json()
    if not 'name' in body:
      raise BadRequestException('NAME_IS_NOT_FOUND')
    if (not 'start_date' in body) or (not 'end_date' in body):
      raise BadRequestException('DEADLINE_IS_NOT_FOUND')
    try:
      start_date = datetime.strptime(request.json.get('start_date'), date_format)
      end_date = datetime.strptime(request.json.get('end_date'), date_format)
    except ValueError:
      raise BadRequestException('TIME_VALUE_ERROR')
    
    teacher = Teacher.query.filter_by(account_id=account.id).first()
    AssignmentService.create(request.json.get('name'), start_date, end_date, teacher.id, request.json.get('description'))
    
    file = request.files['file']
    
    if file and AssignmentService.allowed_file(file.filename): 
      df = pd.read_excel(file)
      failed_account = []
      for index, row in df.iterrows():
        try:
          name = row.iloc[0] + ' ' + row[1]
          mssv = row[2]
          email = row[5]
          is_create = AccountService.create_account(name, email, mssv)
          if not is_create:
            failed_account.append({ index: index, mssv: mssv, email: email})
        except:
          print(f'Assignment: Failed to create account email: {email}, mssv: {mssv}')
    return BaseResponse.ok()
  
  @classmethod
  @assignment_controller.route('/api/assignments', methods=['GET'])
  @AccountService.authenticate
  def get_list():
    '''
    TEACHER & STUDENT
    '''
    account = request.account
    if account.type.name == 'STUDENT':
      print('haha',account)
      assignment_list = [
        dict(zip(['id', 'name', 'start_date', 'end_date', 'author_id', 'author_name'], row))
        for row in Assignment.query
        .join(StudentOnAssignment, StudentOnAssignment.assignment_id == Assignment.id)  # Join with StudentOnAssignment
        .join(Teacher, Assignment.author_id == Teacher.id)  # Separate join for Teacher
        .join(Account, Teacher.account_id == Account.id)
        .filter(StudentOnAssignment.student_id == account.student.id)
        .with_entities(
            Assignment.id,
            Assignment.name,
            Assignment.start_date,
            Assignment.end_date,
            Assignment.author_id,
            Account.name.label('author_name'),
        ).all()
]
      print(assignment_list)
      
    else:
      assignment_list = [
        dict(zip(['id', 'name', 'start_date', 'end_date', 'author_id', 'author_name'], row))
        for row in Assignment.query.with_entities(
        Assignment.id, 
        Assignment.name, 
        Assignment.start_date, 
        Assignment.end_date, 
        Assignment.author_id,
      ).filter_by(author_id=account.teacher.id).all()]
    print(assignment_list)
    return BaseResponse.of(assignment_list)

    
  @classmethod
  @assignment_controller.route('/api/assignments/<string:id>', methods=['PATCH'])
  @AccountService.authenticate
  def assign_student(id):
    '''
    TEACHER
    '''
    assignment = Assignment.query.filter_by(id=id).first()
    if not assignment:
      raise BadRequestException('ASSIGNMENT_NOT_FOUND')
    if request.account.type.name == 'STUDENT':
      raise BadRequestException('PERMISSION_DENIED')
    ids = request.json.get('ids', [])
    if ids and len(ids) > 0: 
      existing_ids = list(map(lambda x: str(x.id), Student.query.filter(Student.id.in_(ids)).all()))
      not_found_list = list(set(ids) - set(existing_ids))
      for id in existing_ids:
        student_on_assignment = StudentOnAssignment(student_id=id, assignment_id=assignment.id)
        student_on_assignment.save()
    if request.json.get('description'):
      assignment.description = request.json.get('description')
    if request.json.get('name'):
      assignment.name = request.json.get('name')
    assignment.save()  
    return BaseResponse.of({'not_found_list': not_found_list}) 
  
  @classmethod
  @assignment_controller.route('/api/assignments/<string:id>', methods=['GET'])
  @AccountService.authenticate
  def get_detail(id):
    '''
    TEACHER & STUDENT
    '''
    if request.account.type.name == 'STUDENT':
      is_on_assignment = StudentOnAssignment.query.filter_by(student_id=request.account.student.id).first()
      if not is_on_assignment:
        raise BadRequestException('PERMISSION_DENIED')
    else:
      assignment = Assignment.query.filter_by(author_id=request.account.teacher.id).first()
      if not assignment:
        raise BadRequestException('PERMISSION_DENIED')
    assignment = Assignment.query.with_entities(
      Assignment.name,
      Assignment.start_date,
      Assignment.end_date,
      Assignment.author_id,
      Assignment.description
      ).filter_by(id=id).first()
    if not assignment:
      raise BadRequestException('ASSIGNMENT_NOT_FOUND')
      
    if request.account.type.name == 'TEACHER':
      
      student_list = [
        dict(zip(['id', 'mssv', 'name' ], row))
        for row in
        Student.query.join(StudentOnAssignment, StudentOnAssignment.assignment_id == id, is_active= True).with_entities(
          Student.id,
          Student.mssv,
          Student.name,
        )
      ]
    author_name = Teacher.query.filter_by(id=assignment[3]).first()
    
    return BaseResponse.of({
      'name': assignment[0],
      'start_date': assignment[1],
      'end_date': assignment[2],
      'author_name': author_name.name,
      'description': assignment[3],
      'student_list': student_list if student_list else []
    }) 
