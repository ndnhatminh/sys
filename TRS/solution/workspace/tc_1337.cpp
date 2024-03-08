void tc_1337()
{
    cout << "----- Testcase 337 -----" << endl;

    char email[] = "pf23@hcmut.edu.vn";
    char s[] = "Apf23$%pf23mnpf23#";
    cout << "email: \"" << email << "\", s: \"" << s << "\"\n";

    int result = checkPassword(s, email);
    cout << "email: \"" << email << "\", s: \"" << s
         << "\", result: " << result << endl;
}