void tc_1344()
{
    cout << "----- Testcase 344 -----" << endl;

    char email[] = "pf23@hcmut.edu.vn";
    char s[] = "23$KKKqof@@@@@@34k";
    cout << "email: \"" << email << "\", s: \"" << s << "\"\n";

    int result = checkPassword(s, email);
    cout << "email: \"" << email << "\", s: \"" << s
         << "\", result: " << result << endl;
}