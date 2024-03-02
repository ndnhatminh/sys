import os, sys
from flask import Flask, request
from flask.globals import current_app
# from kafka import KafkaProducer
# from flaskr.extensions import db, migrate
from flaskr.extensions import db
import logging
from datetime import date
import pandas as pd
from dotenv import load_dotenv
from flask_cors import CORS
from flask_config.config import DevelopmentConfig
# from grading_app.appallsub import insertSubmissionToDB_A2

'''
Note: for create table, uncomment following code
'''
# from flaskr.student.student_models import Student
# from flaskr.assignment.assignment_models import Assignment
# from flaskr.submission.submission_models import Submission

PATH_SEP = os.path.sep

sys.path.append(os.path.join(os.getcwd(), 'flaskr'))
sys.path.append(os.path.join(os.getcwd(), 'flask_config'))
sys.path.append(os.path.join(os.getcwd(), 'constants'))
# from .db_raw_query import DB

# sys.path.append(os.getcwd() + f'{PATH_SEP}flaskr')
load_dotenv()

# log to file
if os.getenv('FLASK_ENV') == 'production':
    # logging.basicConfig(filename=f"logs{PATH_SEP}{date.today().strftime('%d-%m-%Y')}.log", level=os.getenv('LOGGING_LEVEL'))
    logging.basicConfig(level=os.getenv('LOGGING_LEVEL'))

elif os.getenv('FLASK_ENV') == 'development':
    logging.basicConfig(stream=sys.stdout, level=os.getenv('LOGGING_LEVEL'))


def create_app(test_config=None):
    # Create and config the app
    app = Flask(__name__, instance_relative_config=True)
    cors = CORS(app)

    # Config logger
    if os.getenv('FLASK_ENV') == 'production':
        config_flask_logger(app)
        
    if test_config is None:
      # Load the instance config, if it exists, when not testing
      # app.config.from_object('config.{}'.format(app.config['ENV']))
      # app.config.from_object('config.development.py')
      app.config.from_object(DevelopmentConfig)
    else:
      # Load the test config if passed in
      app.config.from_mapping(test_config)

    db.init_app(app)
    
    # with app.app_context():
    #   insertSubmissionToDB_A2()
    
    # # Ensure the instance folder exists
    # if not os.path.exists(app.instance_path):
    #     os.makedirs(app.instance_path)

    # register_extensions(app)
    register_blueprints(app)
    # register_shellcontext(app)

    if app.config.get('INIT_DB'):
        with app.app_context():
            # db.create_all()
            pass
    

    # a simple page that says hello
    @app.route('/hello')
    def hello():
        app.logger.info('Receive request to /hello')
        return 'Hello'

    @app.route('/long-hello')
    def long_hello():
        import time
        for i in range(30):
            time.sleep(1)
            print(i)
        return 'Long hello'
      
    return app

# def register_extensions(app):
#     db.init_app(app)
#     migrate.init_app(app, db)

def register_blueprints(app):
  from flaskr.grader.grader_views import blueprint as BPGrader
  app.register_blueprint(BPGrader)
  pass

def seed_exer_ques_level(file_path=f'data{PATH_SEP}KTLT_questions_with_level.csv'):
    df = pd.read_csv(file_path)
    for idx, row in df.iterrows():
        ques_id = row['question_id']
        level = row['label']
        query = f"""
        update questions
        set level = {level}
        where id = '{ques_id}'
        """
        # DB.execute(query)
    # logging.info("seed question's level done")

# def register_shellcontext(app):
#     def shell_context():
#         # db.create_all() # create all tables
        
#         from flaskr.rule.models import Rule
#         from flaskr.suggestion.models import Suggestion
#         from flaskr.classifications.models import Classifications
#         return {
#             # 'db': db,
#             'Rule': Rule,
#             'Suggestion': Suggestion,
#             'Classifications': Classifications,
#             'seed_exer_ques_level': seed_exer_ques_level,
#             # 'DBRQ': DB
#         }
    
#     app.shell_context_processor(shell_context)

def config_flask_logger(app):
    log_file_path = f"logs{PATH_SEP}{date.today().strftime('%d-%m-%Y')}.log"
    if not os.path.exists(log_file_path):
        open(log_file_path, 'w')
        
    fh = logging.FileHandler(log_file_path)
    fh.setLevel(os.getenv('LOGGING_LEVEL'))
    formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
    fh.setFormatter(formatter)
    
    app.logger.setLevel(os.getenv('LOGGING_LEVEL'))
    app.logger.addHandler(fh)

    # app.logger.addHandler(default_handler)

    werkzeug_logger = logging.getLogger('werkzeug')
    werkzeug_logger.setLevel(os.getenv('LOGGING_LEVEL'))
    werkzeug_logger.addHandler(fh)

def register_database(app, db):
  db.init_app(app)