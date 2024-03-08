void tc_1342()
{
    cout << "----- Testcase 342 -----" << endl;

    char email[] = "pf23@hcmut.edu.vn";
    char s[] = "aoD1qwr1%%%23";
    cout << "email: \"" << email << "\", s: \"" << s << "\"\n";

    int result = checkPassword(s, email);
    cout << "email: \"" << email << "\", s: \"" << s
         << "\", result: " << result << endl;
}