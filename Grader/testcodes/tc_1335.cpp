void tc_1335()
{
    cout << "----- Testcase 335 -----" << endl;

    char email[] = "cse2023@hcmut.edu.vn";
    char s[] = "0cse2023$%abcB";
    cout << "email: \"" << email << "\", s: \"" << s << "\"\n";

    int result = checkPassword(s, email);
    cout << "email: \"" << email << "\", s: \"" << s
         << "\", result: " << result << endl;
}