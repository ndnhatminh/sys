import filecmp

x = filecmp.cmp(
        '/root/sys/Grader/grading_app/temp/grad_sub/2311572/tc_1001.out', #'grading_app/temp/grad_sub/output{i}'
        '/root/sys/Grader/solution/workspace/tc_1001.out'#solution/workspace/output{i}
      )

print(x)