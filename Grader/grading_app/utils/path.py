import os, shutil
from datetime import datetime

def timeForName():
  time = datetime.now().strftime("%Y%m%d_%H%M%S")
  return time

def removeAllFiles(folder_to):
  for root, dirs, files in os.walk(folder_to):
    for f in files:
      os.unlink(os.path.join(root, f))
    for d in dirs:
      shutil.rmtree(os.path.join(root, d))

def writeToFile(abs_directory, contents):
  f = open(abs_directory, 'w', errors='ignore')
  f.write(contents)
  f.close()
  
def filterDS_Store(list_dir):
  t = '.DS_Store'
  list_dir = [dir for dir in list_dir if dir[-len(t):] != t]
  return list_dir
      
def makedirs(abs_directory):
  '''
  abs_directory: absolute directory
  '''
  if not os.path.exists(abs_directory):
    os.makedirs(abs_directory)
  else:
    removeAllFiles(abs_directory)
    
def listdir(abs_directory):
  list_dirs = os.listdir(abs_directory)
  list_dirs = [os.path.join(abs_directory, dir) for dir in list_dirs]
  return list_dirs

def replaceTestcaseInMain(abs_main_directory, testline, newline, abs_out_directory):
  f_main = open(abs_main_directory, 'r')
  f_out = open(abs_out_directory, 'w')
  for line in f_main.readlines():
    f_out.write(newline if line == testline else line)
    
  f_main.close()
  f_out.close()

def _test1():
  '''
  Test 'replaceTestcaseInMain'
  '''
  abs_main_directory = '/Users/vuvantien/Desktop/Code/Python/assignment-grader/file-submissions-v2/support-files/main.cpp'
  testline = '#include "tc#.cpp"\n'
  newline = '#include "tc1.cpp"\n'
  abs_out_directory = '/Users/vuvantien/Desktop/Code/Python/assignment-grader/file-submissions-v2/tests/main1.cpp'
  replaceTestcaseInMain(abs_main_directory, testline, newline, abs_out_directory)

if __name__ == "__main__":
  print('path.py')
  _test1()