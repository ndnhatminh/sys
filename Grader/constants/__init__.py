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

lst_tc_id = list(range(1001,1015)) + list(range(1027,1081)) \
            + list(range(1153, 1249)) + list(range(1297,1303)) + list(range(1315, 1321)) + list(range(1333, 1346)) + list(range(1357, 1360))