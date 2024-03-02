void tc_1343()
{
    cout << "----- Testcase 343 -----" << endl;

    char email[] = "pf23@hcmut.edu.vn";
    char s[] = "qi%$#uur537kfj7!!";
    cout << "email: \"" << email << "\", s: \"" << s << "\"\n";

    int result = checkPassword(s, email);
    cout << "email: \"" << email << "\", s: \"" << s
         << "\", result: " << result << endl;
}