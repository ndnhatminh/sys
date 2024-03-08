void tc_1359()
{
    cout << "----- Testcase 359 -----" << endl;

    int num_pwds = 11;
    const char *arr_pwds[] = {"123cbhLm@#", "70@#aj6qE", "70@#aj6qE", "89@#okcneuRY45", "cbw#mc@$7819kcj",
                              "70@#aj6qE", "cbw#mc@$7819kcj", "cbw#mc@$7819kcj", "124cbhKq2#", "70@#aj6qE", "cbw#mc@$7819kcj"};

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