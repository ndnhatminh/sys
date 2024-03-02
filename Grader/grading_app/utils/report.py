import os
import pandas as pd
from typing import List
from .path import listdir, filterDS_Store, timeForName
import filecmp
import xlsxwriter

from .config import ConfigDirectory, ConfigTestcase

def report(list_configs: List[ConfigTestcase], config_directory: ConfigDirectory):
  report_dir = config_directory.abs_report_dir
  dic = {}
  for abs_folder_std in filterDS_Store(listdir(config_directory.abs_grad_sub)):
    std_id = abs_folder_std[abs_folder_std.rfind('/')+1:] # is a string
    dic[std_id] = {}
    for config in list_configs:
      testcode = config.testcode_dir[config.testcode_dir.rfind('/')+1:]
      if os.path.exists(os.path.join(abs_folder_std, config.file_compiled_error)):
        x = 0
      elif os.path.exists(os.path.join(abs_folder_std, config.file_run_error)):
        x = 0
      else:
        x = filecmp.cmp(
          os.path.join(abs_folder_std, config.file_output),
          os.path.join(config_directory.abs_sol_workspace, config.file_output)
        )
        x = x * 1.0
      dic[std_id][testcode] = x
  
  df_tc_std = pd.DataFrame.from_dict(dic, orient='index')
  df_std = df_tc_std.sum(axis=1) # student
  df_tc = df_tc_std.sum(axis=0) # testcase
  
  saved_dir = f'{report_dir}/report_{timeForName()}.xlsx'
  writer = pd.ExcelWriter(saved_dir, engine='xlsxwriter')
  df_tc_std.to_excel(writer, sheet_name='testcases+students')
  df_std.to_excel(writer, sheet_name='student')
  df_tc.to_excel(writer, sheet_name='testcase')
  writer.close()
  
def reportOneSubmission(list_configs: List[ConfigTestcase], config_directory: ConfigDirectory, student_id):
  list_scores = [False for _ in list_configs]
  for idx, config in enumerate(list_configs):
    tc_num = config.tc_num
    p = os.path.join(config_directory.abs_grad_sub, student_id)
    
    if os.path.exists(os.path.join(p, config.file_compiled_error)):
      x = False
    elif os.path.exists(os.path.join(p, config.file_run_error)):
      x = False
    else:
      x = filecmp.cmp(
        os.path.join(p, config.file_output), #'grading_app/temp/grad_sub/output{i}'
        os.path.join(config_directory.abs_sol_workspace, config.file_output) #solution/workspace/output{i}
      )
    
    list_scores[idx] = x
  
  return list_scores