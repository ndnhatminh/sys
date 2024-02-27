from flaskr.teacher.teacher_models import Teacher
from flaskr.utils.base_response import BaseResponse
from flaskr.utils.exceptions import BadRequestException
from flaskr.config import SECRET_KEY
from flaskr.account.response.account_response import AccountResponse
from flaskr.student.student_models import Student
from flaskr.account.account_models import db, Account
from flask import request, jsonify, abort
from functools import wraps
from google.oauth2 import id_token
from google.auth.transport import requests
from email_validator import validate_email, EmailNotValidError

import time

class AccountService:
  # @staticmethod
  # def generate_access_token(account_id, email: str, type):
  #   # Define the expiration time for the access token (1 day from now)
  #   expiry = datetime.utcnow() + timedelta(days=1)

  #   # Create the payload for the access token
  #   payload = {
  #       'uid': str(account_id),
  #       'email': email,
  #       'type': str(type),
  #       'exp': expiry
  #   }
  #   # Sign the access token using a secret key
  #   secret_key = SECRET_KEY
  #   access_token = jwt.encode(payload, secret_key, algorithm='HS256')
  #   return access_token
  @staticmethod
  def verify_token(token: str):
    try:
      idinfo = id_token.verify_oauth2_token(token, requests.Request())
      if idinfo['exp'] < time.time():
        raise BadRequestException('TOKEN_EXPIRED')
      email = validate_email(idinfo['email']).email
      account = Account.query.filter_by(email = email, is_active=True).first()
      if not account:
        raise BadRequestException('EMAIL_NOT_FOUND')
      return account
    except EmailNotValidError:
      raise EmailNotValidError
    except ValueError:
      raise BadRequestException('INVALID_TOKENa')

  
  @staticmethod
  def authenticate(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
      try:
        auth_header = request.headers.get('Authorization')
        if auth_header and auth_header.startswith('Bearer'):
          token = auth_header.split(' ')[1]
          request.account = AccountService.verify_token(token)
          return func(*args, **kwargs)
        else:
          raise BadRequestException('INVALID_TOKEN')
      except  Exception as e:
        raise BadRequestException('INVALID_TOKEN' + str(e))
      # if auth_header and auth_header.startswith('Bearer '):
      #   try:
      #     access_token = auth_header.split(' ')[1]
      #     secret_key = SECRET_KEY
      #     decoded_token = jwt.decode(access_token, secret_key, algorithms=['HS256'])
      #     request.account_id = decoded_token['account_id']
      #     return func(*args, **kwargs)
      #   except jwt.ExpiredSignatureError:
      #     return jsonify({'error': 'Token expired'}), 401
      #   except jwt.InvalidTokenError:
      #     return jsonify({'error': 'Invalid token'}), 400
      # return jsonify({'error': 'Missing token'}), 401
    return wrapper
  
  @staticmethod
  def create_account(name, email, type):
    exist_account = Account.query.filter_by(email=email).count()
    if exist_account > 0:
      raise BadRequestException('The email is existed')
    account = Account(name, email, type)
    account.save()
    if type == 'STUDENT':
      student = Student(account_id=account.id)
      student.save()
    else:
      teacher = Teacher(account_id=account.id)
      teacher.save()
    return account
    
  @staticmethod
  def get_detail(account_id) -> AccountResponse:
    account = Account.query.filter_by(id=account_id).with_entities(Account.name, Account.email, Account.created_at, Account.type).first()
    if not account:
      return jsonify({'error': 'The account is not exist'}), 404
    return jsonify({ 'data': account}), 200

