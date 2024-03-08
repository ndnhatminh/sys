void tc_1341()
{
    cout << "----- Testcase 341 -----" << endl;

    char email[] = "pf23@hcmut.edu.vn";
    char s[] = "kjassf5@$124";
    cout << "email: \"" << email << "\", s: \"" << s << "\"\n";

    int result = checkPassword(s, email);
    cout << "email: \"" << email << "\", s: \"" << s
         << "\", result: " << result << endl;
}