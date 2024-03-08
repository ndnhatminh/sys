void tc_1340()
{
    cout << "----- Testcase 340 -----" << endl;

    char email[] = "pf23@hcmut.edu.vn";
    char s[] = "k3";
    cout << "email: \"" << email << "\", s: \"" << s << "\"\n";

    int result = checkPassword(s, email);
    cout << "email: \"" << email << "\", s: \"" << s
         << "\", result: " << result << endl;
}