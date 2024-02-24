class ConfigTestcase:
  def __init__(self, cmd_compile, cmd_run, testcode_dir, file_compiled_error, file_run_error, file_output, timelimit, tc_num):
    self.cmd_compile = cmd_compile
    self.cmd_run = cmd_run
    self.testcode_dir = testcode_dir
    self.file_compiled_error = file_compiled_error
    self.file_run_error = file_run_error
    self.file_output = file_output
    self.timelimit = timelimit
    self.tc_num = tc_num
    
class ConfigDirectory:
  def __init__(self, folder_object, folder_output, name_main, download_dir, abs_grad_sub, abs_testcodes_dir, abs_sol_code, abs_sol_workspace, abs_report_dir, abs_support_files):
    self.folder_object = folder_object
    self.folder_output = folder_output
    self.name_main = name_main
    self.download_dir = download_dir
    self.abs_grad_sub = abs_grad_sub
    self.abs_testcodes_dir = abs_testcodes_dir
    self.abs_sol_code = abs_sol_code
    self.abs_sol_workspace =abs_sol_workspace
    self.abs_report_dir = abs_report_dir
    self.abs_support_files = abs_support_files