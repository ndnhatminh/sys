import os
from constants import lst_tc_id

def remove_trailing_newlines(directory):
    for filename in os.listdir(directory):
        filepath = os.path.join(directory, filename)
        if os.path.isfile(filepath):
            with open(filepath, 'r') as file:
                lines = file.readlines()
            with open(filepath, 'w') as file:
                file.write(lines[0].rstrip('\n'))
                for i, line in enumerate(lines[1:]):
                  line = line.rstrip('\n')
                  if line == '':
                    break
                  file.write('\n')
                  file.write(line)

# Usage example
# directory_path = '/root/code-practice/222FPA2-TRS-service-grader/test'
# remove_trailing_newlines(directory_path)

l = lst_tc_id
for tc in l:
  directory_path = f'/root/sys/Grader/support-files/testcases-fileinput/{tc}'
  remove_trailing_newlines(directory_path)