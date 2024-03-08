void tc_1345()
{
    cout << "----- Testcase 345 -----" << endl;

    char email[] = "pf23@hcmut.edu.vn";
    char s[] = "aoooj2#%%%%bjFFFFFF";
    cout << "email: \"" << email << "\", s: \"" << s << "\"\n";

    int result = checkPassword(s, email);
    cout << "email: \"" << email << "\", s: \"" << s
         << "\", result: " << result << endl;
}