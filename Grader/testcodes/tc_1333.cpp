void tc_1333()
{
    cout << "----- Testcase 333 -----" << endl;

    char email[] = "cse2023@hcmut.edu.vn";
    char s[] = "Abc12#";
    cout << "email: \"" << email << "\", s: \"" << s << "\"\n";

    int result = checkPassword(s, email);
    cout << "email: \"" << email << "\", s: \"" << s
         << "\", result: " << result << endl;
}