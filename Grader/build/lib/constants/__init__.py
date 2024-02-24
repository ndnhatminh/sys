import os
from dotenv import dotenv_values

env_config = dotenv_values('.env')

# database configuration
DB_USER = env_config['DB_USER']
DB_PWD = env_config['DB_PWD']
DB_HOST = env_config['DB_HOST']
DB_NAME = env_config['DB_NAME']

# Group of student by initial scores
# and group with recommendation method

# 
BACKEND_CORE_URL = env_config['BACKEND_CORE_URL']

MAX_NO_THREADS = int(env_config['MAX_NO_THREADS'])
