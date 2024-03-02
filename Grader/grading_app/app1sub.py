import sys, os
from typing import List
sys.path.append(os.getcwd())
import shutil
from constants import lst_tc_id
from grading_app.utils.config import ConfigTestcase, ConfigDirectory
from grading_app.utils.run import runManyFolders, runOneFolder_v2
from grading_app.utils.path import writeToFile
import grading_app.utils.prepare as utilsPrepare
from grading_app.utils.path import removeAllFiles
from grading_app.utils.compile import compileManyFolders, compileOneFolder_v2_OneTime
from grading_app.utils.report import report, reportOneSubmission


# def prepare(list_configs, name_main, folder_object, file_compiled_error, timelimit, file_run_error, file_output, download_dir, dst_dir, support_dir, abs_testcodes_dir, abs_sol_code, abs_workspace, abs_sol_output, abs_support_files, abs_testcodes):
#   # download_dir = 'output/Assignment1-Submission'
#   # dst_dir = 'grading_app/temp/grad_sub'
#   # support_dir = 'support-files'
#   # abs_testcodes_dir = 'testcodes'
#   # abs_sol_code = 'solution/code'
#   # abs_workspace = 'solution/workspace'
#   # abs_sol_output = 'solution/output'
#   # abs_support_files = 'support-files'
#   # abs_testcodes = 'testcodes'
  
#   utilsPrepareSolutionOutput(abs_sol_code, abs_workspace, abs_sol_output, abs_support_files, abs_testcodes, name_main, list_configs, folder_object, file_compiled_error, timelimit, file_run_error, file_output)
  
#   utilsExport(download_dir, dst_dir)
#   utilsPrepareNotMain(support_dir, dst_dir, name_main='main.cpp')

#   utilsPrepareMain(support_dir, abs_testcodes_dir, dst_dir, name_main='main.cpp', testline='#include "tc#.cpp"\n')

def prepare(list_configs: List[ConfigTestcase], config_directory: ConfigDirectory):
  # TODO: copy from old system
  pass

def prepareOneSubmission(list_configs: List[ConfigTestcase], config_directory: ConfigDirectory, student_id:str, list_fileinfos: List[str]):
  '''
  person id: student id or lecturer id?
  '''
  # export file from downloaded dir to 'temp/grad_sub'
  # utilsPrepare.export(config_directory.download_dir, config_directory.abs_grad_sub)
  
  removeAllFiles(os.path.join(config_directory.abs_grad_sub, student_id))
  
  # Copy submission file to temp/grad_sub/<student_id>
  
  p = os.path.join(config_directory.abs_grad_sub, student_id)
  if not os.path.exists(p):
    os.makedirs(p)
    
  for fpath in list_fileinfos:
    if 'study_in_pink1.h' in fpath:
      t = 'study_in_pink1.h'
    elif 'study_in_pink1.cpp' in fpath:
      t = 'study_in_pink1.cpp'
    else:
      print('Error')
      assert(False)
    dst = os.path.join(config_directory.abs_grad_sub, student_id, t)
    print(f'dst: {dst}')
    print(f'fpath: {fpath}')
    shutil.copy(fpath, dst)
  
  # copy support files to dir
  for fname in ['main.cpp', 'main.h', 'tc.h']:
    src = os.path.join(config_directory.abs_support_files, fname)
    dst = os.path.join(config_directory.abs_grad_sub, student_id, fname)

    shutil.copy(src, dst)
  # copy testcases to dir
  # for tc_config in list_configs:
  #   tc_num = tc_config.tc_num
  #   src = os.path.join(config_directory.abs_support_files, 'testcases-fileinput', str(tc_num))
  #   dst = os.path.join(config_directory.abs_grad_sub, student_id)
  #   shutil.copytree(src, dst, dirs_exist_ok=True)
  
  
  

def initListConfigTestcases(config_directory: ConfigDirectory):
  list_configs = []
  l_tc = lst_tc_id
  for i in l_tc:
    list_configs.append(ConfigTestcase(
      cmd_compile=f'g++ -g -o main main.cpp study_in_pink1.cpp -I . -std=c++11',
      cmd_run=['./main', f'{i-1000}'],
      testcode_dir=os.path.join(config_directory.abs_testcodes_dir, f'tc_{i}.cpp'),
      
      file_compiled_error=f'co_error{i}',
      file_run_error=f'run_error{i}',
      file_output=f'tc_{i}.out',
      
      timelimit=5,
      tc_num=i
    ))
  return list_configs

def prepareSolutionOutput(list_configs: List[ConfigTestcase], config_directory: ConfigDirectory):
  '''Setup workspace'''
  # prepare solution output: copy file to folder
  removeAllFiles(config_directory.abs_sol_workspace)
  # copy support files to dir
  for fname in ['main.cpp', 'main.h']:
    src = os.path.join(config_directory.abs_support_files, fname)
    dst = os.path.join(config_directory.abs_sol_workspace, fname)
    shutil.copy(src, dst)
  # copy testcases to dir
  for tc_config in list_configs:
    tc_num = tc_config.tc_num
    src = os.path.join(config_directory.abs_support_files, 'testcases-fileinput', str(tc_num))
    dst = os.path.join(config_directory.abs_sol_workspace)
    shutil.copytree(src, dst, dirs_exist_ok=True)
  
  # copy solution to folder workspace
  utilsPrepare.prepareNotMainOneFolder(
    config_directory.abs_sol_code,
    config_directory.abs_sol_workspace,
    name_main=config_directory.name_main
  )
  # compile
  compileOneFolder_v2_OneTime(
    list_configs,
    config_directory.abs_sol_workspace
  )
  # run
  runOneFolder_v2(
    list_configs,
    config_directory.abs_sol_workspace
  )


# def grade(list_configs, folder_object, folder_output, timelimit, file_run_error, file_output):
#   path_submissions = os.path.join(os.getcwd(), 'grading_app', 'temp', 'grad_sub') # absolute path
#   # relative_dir_objs = 'objs'
#   compile(list_configs, path_submissions, folder_object=folder_object) # TODO: uncomment
#   # relative_dir_outputs = 'outputs'
#   run(list_configs, path_submissions, folder_output=folder_output, timelimit=timelimit, file_run_error=file_run_error, file_output=file_output)
  
def compile(list_configs: List[ConfigTestcase], config_directory: ConfigDirectory):
  # compileManyFolders(
  #   list_configs, 
  #   config_directory.abs_grad_sub
  # )
  compileOneFolder_v2_OneTime(
    list_configs,
    config_directory.abs_grad_sub
  )
  
def run(list_configs: List[ConfigTestcase], config_directory: ConfigDirectory):
  runManyFolders(
    list_configs,
    config_directory.abs_grad_sub
  )

def grade(list_configs: List[ConfigTestcase], config_directory: ConfigDirectory):
  compileManyFolders(
    list_configs, 
    config_directory.abs_grad_sub
  )
  
  runManyFolders(
    list_configs,
    config_directory.abs_grad_sub
  )
  
def createTcReadfile():
  for i in range(1, 100+1):
    writeToFile(os.path.join(os.getcwd(), 'tc_readfiles', str(i+1)), str(i+1))
    
def initConfigDirectory():
  config_directory = ConfigDirectory(
    folder_object='objs',
    folder_output='outputs',
    name_main='main.cpp',
    download_dir=os.path.join(os.getcwd(), 'output/Assignment2-Submission'),
    abs_grad_sub=os.path.join(os.getcwd(), 'grading_app/temp/grad_sub'),
    abs_testcodes_dir=os.path.join(os.getcwd(), 'testcodes'),
    abs_sol_code=os.path.join(os.getcwd(), 'solution/code'),
    abs_sol_workspace=os.path.join(os.getcwd(), 'solution/workspace'),
    abs_report_dir=os.path.join(os.getcwd(), 'grading_app/reports'),
    abs_support_files=os.path.join(os.getcwd(), 'support-files')
  )
  return config_directory

def testPrepareSolutionOutput():
  config_directory = initConfigDirectory()
  list_configs = initListConfigTestcases(config_directory)
  prepareSolutionOutput(list_configs, config_directory)
  
def testGradeOneSubmission():
  '''Grade one submission'''
  
  config_directory = initConfigDirectory()
  list_configs = initListConfigTestcases(config_directory)
  student_id = '1713497'
  list_fileinfos = [
    ("20230225_151005_1713497_knight.h", "/root/code-practice/testcases-recommendation-system/files/submissions/20230225_151005_1713497_knight.h"),
    ("20230225_151005_1713497_knight.cpp","/root/code-practice/testcases-recommendation-system/files/submissions/20230225_151005_1713497_knight.cpp")
  ]
  
  prepareOneSubmission(list_configs, config_directory, student_id, list_fileinfos)
  compileOneFolder_v2_OneTime(
    list_configs,
    os.path.join(config_directory.abs_grad_sub, student_id)
  )
  runOneFolder_v2(
    list_configs,
    os.path.join(config_directory.abs_grad_sub, student_id)
  )
  
  list_scores = reportOneSubmission(list_configs, config_directory, student_id)
  print(list_scores)
  print(len(list_scores))
  
def gradeOneSubmission(dic_data: dict):
  list_fileinfos = dic_data['list_fileinfos']
  student_id = str(dic_data['student_id'])
  submission_id = dic_data['submission_id']
  
  config_directory = initConfigDirectory()
  list_configs = initListConfigTestcases(config_directory)
  
  prepareOneSubmission(list_configs, config_directory, student_id, list_fileinfos)
  compileOneFolder_v2_OneTime(
    list_configs,
    os.path.join(config_directory.abs_grad_sub, student_id)
  )
  runOneFolder_v2(
    list_configs,
    os.path.join(config_directory.abs_grad_sub, student_id)
  )
  
  list_scores = reportOneSubmission(list_configs, config_directory, student_id)
  # if student_id != '2210220':
  # removeAllFiles(os.path.join(config_directory.abs_grad_sub, student_id)) # clean to save disk space
  return list_scores

if __name__ == '__main__':
  # testGradeOneSubmission()
  testPrepareSolutionOutput()