import copy
from flaskr.submission.submission_models import Submission
from sqlalchemy import not_, select
from flaskr.database import db
import pandas as pd
from surprise import Dataset, Reader, SVD
from surprise.model_selection import GridSearchCV
from flaskr.utils.preprocessing import LSTMDataSet
from flaskr.utils.exceptions import InternalServerException
from flaskr.assignment.assignment_models import Assignment
from flaskr.student.student_models import Student
from flaskr.matrixfactorization.MF_models import MatrixFactorization, saveMatrix, loadMatrix
from flaskr.utils.time import timeNow
import numpy as np
from sqlalchemy.sql import text
from datetime import datetime
from flaskr.utils.dataProcessing import Dataset
from flaskr.utils.model import LSTMModel, timeSVD, RSVD

def buidLSTM(app):
  with app.app_context():
    assignement_id = '0b13d244-785c-4319-b764-16bfb29a42c1'
    records = Submission.query \
      .join(Assignment, Assignment.id == assignement_id) \
      .join(Student, Student.id == Submission.student_id) \
      .filter(not_(Submission.scores == [])) \
      .with_entities(
        Student.id, 
        Submission.update_at, 
        Submission.scores
      )
    start_date = Assignment.query.filter_by(Assignment.id == assignement_id).with_entities(Assignment.start_date).first()[0]
    
    if len(records) == 0: 
      raise InternalServerException('LSTM_ERROR')
    if start_date is None:
      raise InternalServerException('ASSIGNMENT_DO_NOT_START_DATE')
    df = pd.DataFrame()
    df['student_id'] = records[0]   #integer
    df['update_at'] = records[1] #integer
    df['scores'] = [int(score) for score in records[2]]         #integer 1 or 0
    dataset = LSTMDataSet(df)
    
    from constants import list_testcase_ids as list_tcs
    model = LSTMModel()
    X_train, y_train = dataset.train_all()
    model.define_model(dataset.shape(), 
                      learning_rate=0.001, 
                      hidden_unit=50, 
                      direct_dropout=False, 
                      dropout= 0.3, num_lstm_layer=1
                      )
    model.train(X_train, y_train, 72, 150)
    
    db_list_students_id = []
    
    db_matrix = []
    for record in records:
      student_id = record[0]
      scores =record[2]
      latest_submissions = dataset.padding(scores[-(dataset.timesteps+1):])
      
      score_predicts = model.predict(latest_submissions)
      db_matrix.append(score_predicts)
      db_list_students_id.append(student_id)
      
    time_now = timeNow()
    npz_name = f'{time_now}_mf_LSTM.npz'
    npz_path = f'files/matries/{npz_name}'
    db_matrix = np.array(db_matrix)
    saveMatrix(db_matrix, npz_path)
    mf = MatrixFactorization(list_student_ids=db_list_students_id, list_testcase_ids=list_tcs, assignment_id=assignement_id, model_name='LSTM', matrix_npz_path=npz_path)
    mf.save()
    print('buildMF done')
  
def buildRSVD(app):
  with app.app_context():
    assignment_id = '0b13d244-785c-4319-b764-16bfb29a42c1'
    #Truy vấn tất cả lần nộp bài của sinh viên
    query = '''
    select s2.student_id, max(s2.updated_at) as updated_at, max(scores) as scores 
    from ( 
      select siner.student_id, max(siner.updated_at) as max_updated_at 
      from submissions siner 
      group by student_id 
    ) s1 
    right outer join submissions s2 
    on (s1.student_id = s2.student_id 
      and s1.max_updated_at = s2.updated_at) 
    group by s2.student_id
    '''

    result = db.session.execute(text(query))
    list_subs = result.all() # list of (student_id, updated_at, scores)

    from constants import list_testcase_ids as list_tcs
    if len(list_subs)>0:
      list_student_ids = []
      list_testcase_ids = []
      list_ratings = []
      # print("TIME: ", list_created_at)
      for sub in list_subs:
        student_id = sub[0]
        scores = sub[2]
        
        for idx, sc in enumerate(scores):
          list_student_ids.append(student_id)
          list_testcase_ids.append(list_tcs[idx])
          list_ratings.append(1 if sc else 0)

      df = pd.DataFrame()
      df['student_id'] = list_student_ids   #integer
      df['testcase_id'] = list_testcase_ids #integer
      df['rating'] = list_ratings           #integer 1 or 0
      
      # lst = list(map(lambda idx: [list_student_ids[idx], list_testcase_ids[idx], list_ratings[idx], list_created_at[idx]], range(len(list_student_ids))))
      # RSVD
      dataset = Dataset().load_dataset(df)

      model = RSVD(dataset)
      model.train(steps=10, gamma=0.001, Lambda=0.05)

      # insert into database: MF
      query = 'SELECT id FROM students;'
      result = db.session.execute(text(query))
      list_stds = result.all()


      db_list_tc_ids = list_tcs
      db_list_students_id = []
      db_matrix = []

      for idx in range(len(db_list_students_id)):
        student_id = db_list_students_id[idx]
      
      for sub in list_subs:
        student_id = sub[0]
        scores = sub[2]
        
        db_list_students_id.append(student_id)
        scores = [1 if x else 0 for x in scores]
        scores_predict = [None for x in scores]
        
        for idx, sc in enumerate(scores):
          scores_predict[idx] = model.predict(student_id, db_list_tc_ids[idx])
          
        db_matrix.append(scores_predict)

      time_now = timeNow()
      npz_name = f'{time_now}_mf_RSVD.npz'
      npz_path = f'files/matries/{npz_name}'
      db_matrix = np.array(db_matrix)
      saveMatrix(db_matrix, npz_path)
      mf = MatrixFactorization(list_student_ids=db_list_students_id, list_testcase_ids=db_list_tc_ids, assignment_id=assignment_id, model_name = 'RSVD', matrix_npz_path=npz_path)
      mf.save()
      print('buildMF done')

def buildTimeSVD(app):
  with app.app_context():
    assignment_id = '0b13d244-785c-4319-b764-16bfb29a42c1'
    #Truy vấn tất cả lần nộp bài của sinh viên
    query = '''
    SELECT
        s.student_id,
        s.updated_at,
        s.scores
    FROM
        submissions s
    ORDER BY
        s.student_id,
        s.updated_at DESC;
    '''

    result = db.session.execute(text(query))
    list_subs = result.all() # list of (student_id, updated_at, scores)

    from constants import list_testcase_ids as list_tcs
    if len(list_subs)>0:
      list_student_ids = []
      list_testcase_ids = []
      list_ratings = []
      list_created_at = []
      # print("TIME: ", list_created_at)
      for sub in list_subs:
        student_id = sub[0]
        created_at = sub[1].replace(minute=0, second=0, microsecond=0)
        scores = sub[2]
        
        for idx, sc in enumerate(scores):
          list_student_ids.append(student_id)
          list_testcase_ids.append(list_tcs[idx])
          list_ratings.append(1 if sc else 0)
          list_created_at.append(created_at.timestamp())

      df = pd.DataFrame()
      df['student_id'] = list_student_ids   #integer
      df['testcase_id'] = list_testcase_ids #integer
      df['rating'] = list_ratings           #integer 1 or 0 
      df['created_at'] = list_created_at    #integer
      
      # lst = list(map(lambda idx: [list_student_ids[idx], list_testcase_ids[idx], list_ratings[idx], list_created_at[idx]], range(len(list_student_ids))))
      # TimeSVD
      dataset = Dataset().load_dataset(df)

      model = timeSVD(dataset)
      model.train(steps=10, gamma=0.001, Lambda=0.05)

      # insert into database: MF
      query = 'SELECT id FROM students;'
      result = db.session.execute(text(query))
      list_stds = result.all()


      db_list_tc_ids = list_tcs
      db_list_students_id = []
      db_matrix = []
      created_at = datetime.now().timestamp()

      for idx in range(len(db_list_students_id)):
        student_id = db_list_students_id[idx]
      
      for sub in list_subs:
        student_id = sub[0]
        scores = sub[2]
        
        db_list_students_id.append(student_id)
        scores = [1 if x else 0 for x in scores]
        scores_predict = [None for x in scores]
        
        for idx, sc in enumerate(scores):
          scores_predict[idx] = model.predict(student_id, db_list_tc_ids[idx], created_at)
          
        db_matrix.append(scores_predict)

      time_now = timeNow()
      npz_name = f'{time_now}_mf_timeSVD.npz'
      npz_path = f'files/matries/{npz_name}'
      db_matrix = np.array(db_matrix)
      saveMatrix(db_matrix, npz_path)
      mf = MatrixFactorization(list_student_ids=db_list_students_id, list_testcase_ids=db_list_tc_ids, assignment_id=assignment_id, model_name='timeSVD', matrix_npz_path=npz_path)
      mf.save()
      print('buildMF done')
  
def exportInitMF(app):
  with app.app_context():
    mf = MatrixFactorization.query.first()
    print(mf.id)
    m = mf.matrix
    saveMatrix(m, 'files/matries/m.npz')