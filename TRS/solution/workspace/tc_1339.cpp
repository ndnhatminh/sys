void tc_1339()
{
    cout << "----- Testcase 339 -----" << endl;

    char email[] = "pf23@hcmut.edu.vn";
    char s[] = "F";
    cout << "email: \"" << email << "\", s: \"" << s << "\"\n";

    int result = checkPassword(s, email);
    cout << "email: \"" << email << "\", s: \"" << s
         << "\", result: " << result << endl;
}