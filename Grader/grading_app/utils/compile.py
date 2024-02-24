from .config import ConfigTestcase, ConfigDirectory
from typing import List
import os
from .path import makedirs, writeToFile, filterDS_Store, listdir
from .command import replace
from .command import run as runCommand

def _prepareFolderObjects(abs_dir_std_id, folder_object):
  abs_folder_object = os.path.join(abs_dir_std_id, folder_object)
  makedirs(abs_folder_object)

def compileOneFolder(list_configs: List[ConfigTestcase], abs_dst_dir: str, folder_object='objs', file_compiled_error='co_error#'):
  _prepareFolderObjects(abs_dst_dir, folder_object=folder_object)
  for i, config in enumerate(list_configs):
    success, result = runCommand(
      replace(config.cmd_compile, '#', i+1),
      os.path.join(abs_dst_dir)
    )
    if not success:
      abs_file_compiled_error = os.path.join(
        abs_dst_dir,
        replace(file_compiled_error, '#', i+1)
      )
      writeToFile(abs_file_compiled_error, result)

def compileOneFolder_v2(list_configs: List[ConfigTestcase], abs_dst_dir):
  for config in list_configs:
    success, result = runCommand(
      config.cmd_compile,
      abs_dst_dir
    )
    if not success:
      abs_file_compiled_error = os.path.join(
        abs_dst_dir,
        config.file_compiled_error
      )
      writeToFile(abs_file_compiled_error, result)
      
def compileOneFolder_v2_OneTime(list_configs: List[ConfigTestcase], abs_dst_dir):
  if len(list_configs) == 0:
    print('Error compileOneFolder_v2_OneTime')
    assert(False)
    
  config = list_configs[0]
  success, result = runCommand(
    config.cmd_compile,
    abs_dst_dir
  )
  if not success:
    abs_file_compiled_error = os.path.join(
      abs_dst_dir,
      config.file_compiled_error
    )
    writeToFile(abs_file_compiled_error, result)

def compile(list_configs: List[ConfigTestcase], path_submissions: str, folder_object, file_compiled_error='co_error#'):
  '''
  path_submissions: absolute path
  '''
  # create folder obj in each id folder
  for folder_student_id in filterDS_Store(os.listdir(path_submissions)):
    abs_dir_std_id = os.path.join(path_submissions, folder_student_id)
    _prepareFolderObjects(abs_dir_std_id, folder_object)
    
    for i, config in enumerate(list_configs):
      success, result = runCommand(
        replace(config.cmd_compile, '#', i+1), 
        os.path.join(abs_dir_std_id) # folder_object
      )
      if not success:
        abs_file_compiled_error = os.path.join(
          abs_dir_std_id,
          replace(file_compiled_error, '#', i+1)
        )
        writeToFile(abs_file_compiled_error, result)

def compileManyFolders(list_configs: List[ConfigTestcase], abs_dst_dir):
  for abs_folder_std in filterDS_Store(listdir(abs_dst_dir)):
    compileOneFolder_v2(
      list_configs,
      abs_dst_dir=abs_folder_std
    )
    print(f'compileManyFolders: {abs_folder_std}')
  print('compileManyFolders done!')
  
def compileManyFoldersOneTime(list_configs: List[ConfigTestcase], abs_dst_dir):
  for abs_folder_std in filterDS_Store(listdir(abs_dst_dir)):
    compileOneFolder_v2_OneTime(
      list_configs,
      abs_dst_dir=abs_folder_std
    )