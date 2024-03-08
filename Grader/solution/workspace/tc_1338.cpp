void tc_1338()
{
    cout << "----- Testcase 338 -----" << endl;

    char email[] = "pf23@hcmut.edu.vn";
    char s[] = "pf23@3pf23pf23Bpf23";
    cout << "email: \"" << email << "\", s: \"" << s << "\"\n";

    int result = checkPassword(s, email);
    cout << "email: \"" << email << "\", s: \"" << s
         << "\", result: " << result << endl;
}