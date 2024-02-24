import sys, os
from typing import List
sys.path.append(os.getcwd())
import shutil

from grading_app.utils.path import listdir
from grading_app.utils.config import ConfigTestcase, ConfigDirectory
from grading_app.utils.run import runManyFolders
from grading_app.utils.path import writeToFile
import grading_app.utils.prepare as utilsPrepare
from grading_app.utils.path import removeAllFiles
from grading_app.utils.compile import compileManyFolders, compileManyFoldersOneTime
from grading_app.utils.report import report
from flaskr.submission.submission_models import Submission
from grading_app.utils.report import report, reportOneSubmission
from grading_app.utils.compile import compileOneFolder_v2_OneTime
from grading_app.utils.run import runOneFolder_v2

def prepare(list_configs: List[ConfigTestcase], config_directory: ConfigDirectory):
  '''
  '''
  # export file from downloaded dir to 'temp/grad_sub'
  utilsPrepare.export(config_directory.download_dir, config_directory.abs_grad_sub)
  # # copy support files to each folder student
  # utilsPrepare.prepareNotMainManyFolders(
  #   config_directory.abs_support_files,
  #   config_directory.abs_grad_sub,
  #   config_directory.name_main
  # )
  # utilsPrepare.prepareMainManyFolders(
  #   config_directory.abs_support_files,
  #   config_directory.abs_testcodes_dir,
  #   config_directory.abs_grad_sub,
  #   name_main=config_directory.name_main,
  #   testline='#include "tc#.cpp"\n'
  # )
  for subdir in listdir(config_directory.abs_grad_sub):
    # copy support files to dir
    for fname in ['main.cpp', 'main.h']:
      src = os.path.join(config_directory.abs_support_files, fname)
      dst = os.path.join(subdir, fname)
      shutil.copy(src, dst)
    # copy testcases to dir
    for tc_config in list_configs:
      tc_num = tc_config.tc_num
      src = os.path.join(config_directory.abs_support_files, 'testcases-fileinput', str(tc_num))
      dst = subdir
      shutil.copytree(src, dst, dirs_exist_ok=True)
    
  print('Prepare done')
  
def initConfigDirectory():
  config_directory = ConfigDirectory(
    folder_object='objs',
    folder_output='outputs',
    name_main='main.cpp',
    download_dir=os.path.join(os.getcwd(), 'output/Assignment2-Submission'),
    abs_grad_sub=os.path.join(os.getcwd(), 'grading_app/temp/init_grad_sub'),
    abs_testcodes_dir=os.path.join(os.getcwd(), 'testcodes'),
    abs_sol_code=os.path.join(os.getcwd(), 'solution/code'),
    abs_sol_workspace=os.path.join(os.getcwd(), 'solution/workspace'),
    abs_report_dir=os.path.join(os.getcwd(), 'grading_app/reports'),
    abs_support_files=os.path.join(os.getcwd(), 'support-files')
  )
  return config_directory

def initListConfigTestcases(config_directory: ConfigDirectory):
  list_configs = []
  l_tc = list(range(1001, 1083)) + list(range(2001, 2070))
  for i in l_tc: # tc01 - tc30
    list_configs.append(ConfigTestcase(
      cmd_compile=f'g++ -g -o main main.cpp knight2.cpp -I . -std=c++11',
      cmd_run=['./main', f'tc{i}_armyknights', f'tc{i}_events'],
      testcode_dir=os.path.join(config_directory.abs_testcodes_dir, f'tc{i}.cpp'),
      
      file_compiled_error=f'co_error{i}',
      file_run_error=f'run_error{i}',
      file_output=f'output{i}',
      
      timelimit=5,
      tc_num=i
    ))
  # return list_configs[90:101]
  return list_configs

def compile(list_configs: List[ConfigTestcase], config_directory: ConfigDirectory):
  compileManyFoldersOneTime(
    list_configs,
    config_directory.abs_grad_sub
  )

def run(list_configs: List[ConfigTestcase], config_directory: ConfigDirectory):
  runManyFolders(
    list_configs,
    config_directory.abs_grad_sub
  )
  
def testGradeAllSubmissions():
  '''In A2 it is actually prepareMany'''
  config_directory = initConfigDirectory()
  list_configs = initListConfigTestcases(config_directory)
  prepare(list_configs, config_directory)
  print('prepare done')
  # compile(list_configs, config_directory)
  # run(list_configs, config_directory)

def insertSubmissionToDB():
  config_directory = initConfigDirectory()
  list_configs = initListConfigTestcases(config_directory)
  
  for dir in listdir(config_directory.abs_grad_sub):
    student_id = dir.split('/')[-1]
    list_scores = reportOneSubmission(list_configs, config_directory, student_id)
    assignment_id = '2a1bff09-f3fa-4cd3-b88f-932de6adb0e4'
    
    sub = Submission(assignment_id=assignment_id, student_id=student_id, scores=list_scores, files=[])
    sub.save()
    
    print(f'done: {student_id}')
    
  print('insert done')
  
def insertSubmissionToDB_A2():
  config_directory = initConfigDirectory()
  list_configs = initListConfigTestcases(config_directory)
  
  for dir in listdir(config_directory.abs_grad_sub):
    student_id = dir.split('/')[-1]
    print(f'compile start: {student_id}')
    compileOneFolder_v2_OneTime(list_configs, abs_dst_dir=dir)
    print(f'run start: {student_id}')
    runOneFolder_v2(list_configs, abs_dst_dir=dir)
    
    list_scores = reportOneSubmission(list_configs, config_directory, student_id)
    assignment_id = '2a1bff09-f3fa-4cd3-b88f-932de6adb0e4'
    
    sub = Submission(assignment_id=assignment_id, student_id=student_id, scores=list_scores, files=[])
    sub.save()
    
    removeAllFiles(dir)
    print(f'done: {student_id}')
    
  print('insert done')

if __name__ == '__main__':
  testGradeAllSubmissions()
  # insertSubmissionToDB_A2()