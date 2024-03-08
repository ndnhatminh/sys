void tc_1358()
{
    cout << "----- Testcase 358 -----" << endl;

    int num_pwds = 9;
    const char *arr_pwds[] = {"iqj$#32vnhf", "928#vvFH!@cjkl", "02964ngfg!#cC", "abch&53FH@1", "928#vvFH!@cjkl", "1nche$@mcgjj", "abch&53FH@1", "abch&53FH@1", "928#vvFH!@cjkl"};

    cout << "num_pwds: " << num_pwds << endl;
    cout << "arr_pwds = {\"" << arr_pwds[0] << "\"";

    for (int i = 1; i < num_pwds; i++)
    {
        cout << ", \"" << arr_pwds[i] << "\"";
    }
    cout << "}\n";

    int result = findCorrectPassword(arr_pwds, num_pwds);
    cout << "result: " << result << endl;
}