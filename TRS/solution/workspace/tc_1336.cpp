void tc_1336()
{
    cout << "----- Testcase 336 -----" << endl;

    char email[] = "cse2023@hcmut.edu.vn";
    char s[] = "Abcse2023#$3cse2023!";
    cout << "email: \"" << email << "\", s: \"" << s << "\"\n";

    int result = checkPassword(s, email);
    cout << "email: \"" << email << "\", s: \"" << s
         << "\", result: " << result << endl;
}