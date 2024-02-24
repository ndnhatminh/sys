import subprocess
import os

def replace(cmd, annotation, index):
  return cmd.replace(annotation, str(index))

def run(command, directory):
  '''
  directory: absolute path
  '''
  try:
    result = subprocess.check_output(command.split(sep=' '), cwd=directory, stderr=subprocess.STDOUT).decode('utf-8')
    success = True
  except subprocess.CalledProcessError as e:
    result = e.stdout.decode('utf-8')
    success = False
  return success, result
  
def runWithTimeout(abs_directory, command, timelimit):
  '''
  '''
  success = False
  try:
    result = subprocess.check_output(command, timeout=timelimit, cwd=abs_directory, stderr=subprocess.STDOUT, shell=False).decode('utf-8')
    success = True
  except subprocess.CalledProcessError as e:
    result = e.output.decode('utf-8')
    result += f'\n{e}'
  except subprocess.TimeoutExpired as e:
    # result = e.output.decode('utf-8') if e.output is not None else '' # comment this line to save disk, if run 100 testcases, 1 tc's ouput take large memory
    result = ''
    # print(e)
    result += '\nTime limit exceeds.'
  except Exception as e:
    result = f'[ERROR][SECRET_UUID]{e}'
  
  return success, result