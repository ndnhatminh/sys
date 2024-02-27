from flask import Blueprint, request
from flaskr.utils.base_response import BaseResponse
from flaskr.account.account_services import AccountService




# credentials = AnonymousCredentials.from_client_config(
#   None,
#   client_id= GOOGLE_CLIENT_ID,
#   client_secret=GOOGLE_CLIENT_SECRET,
#   token_uri='https://accounts.google.com/o/oauth2/token',
#   scopes=['openid', 'email']  # Add any additional scopes you need
# )

class AccountController:
  account_controller = Blueprint('account_controller', __name__)

  @classmethod
  @account_controller.route('/api/accounts/login/google', methods=['POST'])
  def login():
    token = request.json.get('token')
    account = AccountService.verify_token(token)
    return BaseResponse.of({
      'id': account.id,
      'name': account.name,
      'type': account.type.name,
      'email':account.email, 
    })

  @account_controller.route('/api/accounts', methods=['POST'])
  def create_account():
    email = request.json.get('email')
    type = request.json.get('type')
    name = request.json.get('name')
    account = AccountService.create_account(name, email, type)
    return BaseResponse.of(account.__str__())
    
  @classmethod
  @account_controller.route('/api/accounts', methods=['GET'])
  @AccountService.authenticate
  def get_account(cls):
    return AccountService.get_detail(account_id=request.account_id)
  

    
  
  