from constants import DB_USER, DB_PWD, DB_HOST, DB_NAME
# Database config
DB_USER = 'postgres'
DB_PWD = 'ibEEAyq9a8VB6qRnPzzgVkeF3J7v0mtGdoyGGCMWjgPwPELEdN'
DB_HOST = '165.22.48.44'
DB_NAME = 'ags_db'

# local
DB_USER = 'postgres'
DB_PWD = '12345'
DB_HOST = '127.0.0.1'
DB_NAME = 'ags_db_2'

INIT_DB = False

# submission path
SUB_PATH = None

# SQLALCHEMY
SQLALCHEMY_DATABASE_URI = f'postgresql://postgres:{DB_PWD}@{DB_HOST}/{DB_NAME}'
SQLALCHEMY_TRACK_MODIFICATIONS = True
SQLALCHEMY_ENGINE_OPTIONS = {
    'isolation_level': "AUTOCOMMIT"
}

# Seed data
SEED_QUESTION_LEVEL = False
