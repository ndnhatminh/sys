import sys, os
from typing import List
sys.path.append(os.getcwd())

from grading_app.utils.config import ConfigTestcase, ConfigDirectory
from grading_app.utils.run import runManyFolders
from grading_app.utils.path import writeToFile
import grading_app.utils.prepare as utilsPrepare
from grading_app.utils.path import removeAllFiles
from grading_app.utils.compile import compileManyFolders
from grading_app.utils.report import report


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
  '''
  '''
  # export file from downloaded dir to 'temp/grad_sub'
  utilsPrepare.export(config_directory.download_dir, config_directory.abs_grad_sub)
  # copy support files to each folder student
  utilsPrepare.prepareNotMainManyFolders(
    config_directory.abs_support_files,
    config_directory.abs_grad_sub,
    config_directory.name_main
  )
  utilsPrepare.prepareMainManyFolders(
    config_directory.abs_support_files,
    config_directory.abs_testcodes_dir,
    config_directory.abs_grad_sub,
    name_main=config_directory.name_main,
    testline='#include "tc#.cpp"\n'
  )
  
  '''Setup workspace'''
  # prepare solution output: copy file to folder
  removeAllFiles(config_directory.abs_sol_workspace)
  utilsPrepare.prepareNotMainOneFolder(
    config_directory.abs_support_files,
    config_directory.abs_sol_workspace,
    name_main=config_directory.name_main
  )
  utilsPrepare.prepareMainOneFolder(
    config_directory.abs_support_files,
    config_directory.abs_testcodes_dir,
    config_directory.abs_sol_workspace,
    name_main=config_directory.name_main,
    testline='#include "tc#.cpp"\n'
  )
  # copy solution to folder workspace
  utilsPrepare.prepareNotMainOneFolder(
    config_directory.abs_sol_code,
    config_directory.abs_sol_workspace,
    name_main=config_directory.name_main
  )
  # compile
  utilsPrepare.compileOneFolder_v2(
    list_configs,
    config_directory.abs_sol_workspace
  )
  # run
  utilsPrepare.runOneFolder_v2(
    list_configs,
    config_directory.abs_sol_workspace
  )

def initListConfigTestcases(config_directory: ConfigDirectory):
  list_configs = []
  for i in range(1, 31): # tc01 - tc30
    list_configs.append(ConfigTestcase(
      cmd_compile=f'g++ -g -o main{i} main{i}.cpp ConcatStringTree.cpp -I . -std=c++11',
      cmd_run=f'./main{i}',
      testcode_dir=os.path.join(config_directory.abs_testcodes_dir, f'tc{i}.cpp'),
      file_compiled_error=f'co_error{i}',
      file_run_error=f'run_error{i}',
      file_output=f'output{i}',
      timelimit=5
    ))
  for i in range(31, 51): # tc30 - tc50
    list_configs.append(ConfigTestcase(
      cmd_compile=f'g++ -g -o main{i} main{i}.cpp ConcatStringTree.cpp -I . -std=c++11',
      cmd_run=f'./main{i}',
      testcode_dir=os.path.join(config_directory.abs_testcodes_dir, f'tc{i}.cpp'),
      file_compiled_error=f'co_error{i}',
      file_run_error=f'run_error{i}',
      file_output=f'output{i}',
      timelimit=5
    ))
  for i in range(51, 101): # tc50 - tc100
    list_configs.append(ConfigTestcase(
      cmd_compile=f'g++ -g -o main{i} main{i}.cpp ConcatStringTree.cpp -I . -std=c++11',
      cmd_run=f'./main{i}',
      testcode_dir=os.path.join(config_directory.abs_testcodes_dir, f'tc{i}.cpp'),
      file_compiled_error=f'co_error{i}',
      file_run_error=f'run_error{i}',
      file_output=f'output{i}',
      timelimit=5
    ))
  # return list_configs[90:101]
  return list_configs

# def grade(list_configs, folder_object, folder_output, timelimit, file_run_error, file_output):
#   path_submissions = os.path.join(os.getcwd(), 'grading_app', 'temp', 'grad_sub') # absolute path
#   # relative_dir_objs = 'objs'
#   compile(list_configs, path_submissions, folder_object=folder_object) # TODO: uncomment
#   # relative_dir_outputs = 'outputs'
#   run(list_configs, path_submissions, folder_output=folder_output, timelimit=timelimit, file_run_error=file_run_error, file_output=file_output)
  
def compile(list_configs: List[ConfigTestcase], config_directory: ConfigDirectory):
  compileManyFolders(
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

if __name__ == '__main__':
  '''Grade all submission'''
  # createTcReadfile() # TODO: uncomment
  config_directory = initConfigDirectory()
  list_configs = initListConfigTestcases(config_directory)
  prepare(list_configs, config_directory)
  compile(list_configs, config_directory)
  run(list_configs, config_directory)
  report(list_configs, config_directory)
  
