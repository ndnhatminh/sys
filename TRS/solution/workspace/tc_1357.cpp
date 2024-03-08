void tc_1357()
{
    cout << "----- Testcase 357 -----" << endl;

    int num_pwds = 5;
    const char *arr_pwds[] = {"Sherlock221B", "cse2023@abc", "cse2023@abc", "qkdj2847&2&", "cse2023@abc"};

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