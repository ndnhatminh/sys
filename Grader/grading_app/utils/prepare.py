import shutil
import os
from .path import removeAllFiles, listdir, replaceTestcaseInMain
from .compile import compileOneFolder, compileOneFolder_v2, filterDS_Store
from .run import runOneFolder, runOneFolder_v2
  
def renameAllFilesIn(dir):
  for filename in os.listdir(dir):
    src_name = filename
    dst_name = src_name.replace('attachments-', '')
    
    src_dir = os.path.join(dir, src_name)
    dst_dir = os.path.join(dir, dst_name)
    os.rename(src_dir, dst_dir)

# def removeAllFiles(folder_to):
#   for root, dirs, files in os.walk(folder_to):
#     for f in files:
#       os.unlink(os.path.join(root, f))
#     for d in dirs:
#       shutil.rmtree(os.path.join(root, d))

def extractFromDir(dir, folder_to):
  last_dir = dir.split('/')[-1]
  student_id = last_dir.split('-')[0] # maybe: 1711234-attempt5
  if os.path.isdir(f'{dir}/q1-files'):
    # copy all file in this dir to new folder
    src_dir = f'{dir}/q1-files'
    dst_dir = f'{folder_to}/{student_id}'
    shutil.copytree(src_dir, dst_dir)
    # rename
    renameAllFilesIn(dst_dir)
  else:
    # empty folder q1-files
    pass
  
def export(download_dir, dst_dir):
  removeAllFiles(dst_dir)
  
  for dir in os.listdir(download_dir):
    src_dir = os.path.join(os.getcwd(), download_dir, dir)
    extractFromDir(src_dir, dst_dir)

def getNumFromDir(abs_dir: str):
  name = abs_dir.split('/')[-1]
  name = name[:-len('.cpp')][len('tc'):]
  num = int(name)
  return num
  
def prepareMainOneFolder(abs_support_dir, abs_testcodes_dir, dst_dir, name_main='main.cpp', testline='#include "tc#.cpp"\n'):
  abs_main_directory = os.path.join(abs_support_dir, name_main)
  for abs_testcode in filterDS_Store(listdir(abs_testcodes_dir)):
    tc_num = getNumFromDir(abs_testcode)
    newline = f'#include "{abs_testcode}"\n'
    abs_out_directory = os.path.join(dst_dir, f'main{tc_num}.cpp')
    
    replaceTestcaseInMain(abs_main_directory, testline, newline, abs_out_directory)

def prepareMainManyFolders(abs_support_dir, abs_testcodes_dir, dst_dir, name_main='main.cpp', testline='#include "tc#.cpp"\n'):
  abs_main_directory = os.path.join(abs_support_dir, name_main)
  for abs_folder in filterDS_Store(listdir(dst_dir)):
    for abs_testcode in listdir(abs_testcodes_dir):
      tc_num = getNumFromDir(abs_testcode)
      newline = f'#include "{abs_testcode}"\n'
      abs_out_directory = os.path.join(abs_folder, f'main{tc_num}.cpp')
      
      replaceTestcaseInMain(abs_main_directory, testline, newline, abs_out_directory)

def prepareMain(abs_support_dir, abs_testcodes_dir, dst_dir, name_main='main.cpp', testline='#include "tc#.cpp"\n'):
  # dst_dir: contains folders with student id
  # copy each support file into each folder of dst_dir
  ''''''
  abs_main_directory = os.path.join(abs_support_dir, name_main)
  for abs_folder_std in listdir(dst_dir):
    for abs_testcode in listdir(abs_testcodes_dir):
      tc_num = getNumFromDir(abs_testcode)
      newline = f'#include "{abs_testcode}"\n'
      abs_out_directory = os.path.join(abs_folder_std, f'main{tc_num}.cpp')
      
      replaceTestcaseInMain(abs_main_directory, testline, newline, abs_out_directory)

def prepareNotMainOneFolder(support_dir, dst_dir, name_main='main.cpp'):
  shutil.copytree(support_dir, dst_dir, dirs_exist_ok=True, ignore=shutil.ignore_patterns(name_main))

def prepareNotMainManyFolders(support_dir, dst_dir, name_main='main.cpp'):
  for dir in filterDS_Store(os.listdir(dst_dir)):
    # if name_main not in dir:
    abs_dir = os.path.join(dst_dir, dir)
    shutil.copytree(support_dir, abs_dir, dirs_exist_ok=True, ignore=shutil.ignore_patterns(name_main))

def prepareNotMain(support_dir, dst_dir, name_main='main.cpp'):
  # dst_dir: contains folders with student id
  # copy each support file into each folder of dst_dir
  for dir in os.listdir(dst_dir):
    # if name_main not in dir:
    abs_dir = os.path.join(dst_dir, dir)
    shutil.copytree(support_dir, abs_dir, dirs_exist_ok=True, ignore=shutil.ignore_patterns(name_main))

def prepareSolutionOutput(abs_sol_code, abs_workspace, abs_output, abs_support_files, abs_testcodes, name_main, list_configs, folder_object, file_compiled_error, timelimit, file_run_error, file_output):
  '''
  '''
  prepareNotMainOneFolder(abs_support_files, abs_workspace, name_main=name_main)
  prepareNotMainOneFolder(abs_sol_code, abs_workspace, name_main=name_main)
  prepareMainOneFolder(abs_support_files, abs_testcodes, abs_workspace, name_main=name_main)
  
  compileOneFolder(list_configs, abs_workspace, folder_object, file_compiled_error)
  runOneFolder(list_configs, abs_workspace, abs_output, timelimit, file_run_error, file_output)

def test1():
  extractFromDir('1713497')
  extractFromDir('1713497-attempt3')

def test2():
  download_dir = 'output/Assignment2Submission'
  dst_dir = 'grading_app/temp/grad_sub'
  support_dir = 'support-files'
  export(download_dir, dst_dir)
  prepareNotMain(support_dir, dst_dir)
  
if __name__ == '__main__':
  test2()