from dotenv import dotenv_values

env_config = dotenv_values('.env')

# Google Setup
GOOGLE_CLIENT_ID = env_config['GOOGLE_CLIENT_ID']
GOOGLE_CLIENT_SECRET = env_config['GOOGLE_CLIENT_SECRET']
SECRET_KEY = env_config['SECRET_KEY']