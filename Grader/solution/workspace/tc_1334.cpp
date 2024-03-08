void tc_1334()
{
    cout << "----- Testcase 334 -----" << endl;

    char email[] = "cse2023@hcmut.edu.vn";
    char s[] = "abc123BlueSky#@0946!@$cdf";
    cout << "email: \"" << email << "\", s: \"" << s << "\"\n";

    int result = checkPassword(s, email);
    cout << "email: \"" << email << "\", s: \"" << s
         << "\", result: " << result << endl;
}