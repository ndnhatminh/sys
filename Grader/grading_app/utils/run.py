from .path import listdir, makedirs, writeToFile, filterDS_Store
import os
from .command import runWithTimeout, replace
from .config import ConfigTestcase
from typing import List

def _prepareFolderOutputs(abs_dir_std_id, folder_output):
  abs_folder_output = os.path.join(abs_dir_std_id, folder_output)
  makedirs(abs_folder_output)

def runOneFolder(list_configs: List[ConfigTestcase], abs_dst_dir, folder_output, timelimit, file_run_error='run_error#', file_output='output#'):
  _prepareFolderOutputs(abs_dst_dir, folder_output)
  for i, config in enumerate(list_configs):
    success, result = runWithTimeout(
      abs_dst_dir,
      replace(config.cmd_run, '#', i+1),
      timelimit
    )
    if success:
      abs_file_output = os.path.join(folder_output, replace(file_output, '#', i+1))
      writeToFile(abs_file_output, result)
    else:
      abs_file_run_error = os.path.join(abs_file_output, replace(file_run_error, '#', i+1))
      writeToFile(abs_file_run_error, result)

def runOneFolder_v2(
  list_configs: List[ConfigTestcase],
  abs_dst_dir
):
  for config in list_configs:
    success, result = runWithTimeout(
      abs_dst_dir,
      config.cmd_run,
      config.timelimit
    )
    if success:
      abs_file_output = os.path.join(abs_dst_dir, config.file_output)
      writeToFile(abs_file_output, result)
    else:
      abs_file_run_error = os.path.join(abs_dst_dir, config.file_run_error)
      writeToFile(abs_file_run_error, result)

def run(list_configs: List[ConfigTestcase], abs_directory_submissions, folder_output, timelimit, file_run_error='run_error#', file_output='output#'):
  '''
  abs_dir_inputs: [001, 002, 003, 004,...]
  '''
  for abs_dir_std_id in filterDS_Store(listdir(abs_directory_submissions)):
    _prepareFolderOutputs(abs_dir_std_id, folder_output)
    abs_folder_output = os.path.join(abs_dir_std_id, folder_output)
    for i, config in enumerate(list_configs):
      success, result = runWithTimeout(
        abs_dir_std_id,
        replace(config.cmd_run, '#', str(i+1)),
        timelimit
      )
      if success:
        abs_file_output = os.path.join(abs_folder_output, replace(file_output, '#', str(i+1)))
        writeToFile(abs_file_output, result)
      else:
        abs_file_run_error = os.path.join(abs_folder_output, replace(file_run_error, '#', str(i+1)))
        writeToFile(abs_file_run_error, result)
        
def runManyFolders(
  list_configs: List[ConfigTestcase],
  abs_dst_dir
):
  for abs_folder_std in filterDS_Store(listdir(abs_dst_dir)):
    runOneFolder_v2(
      list_configs,
      abs_folder_std
    )
    print(f'runManyFolders: {abs_folder_std}')
  print('runManyFolders done!')