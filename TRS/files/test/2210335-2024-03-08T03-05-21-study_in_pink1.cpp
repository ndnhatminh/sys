#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
        cerr << "The file is not found" << endl;
        return false;
    }
}
void kthp(int &hp)
{
    if (hp < 0)
        hp = 0;
    if (hp > 666)
        hp = 666;
}
void ktexp(int &exp)
{
    if (exp < 0)
        exp = 0;
    if (exp > 600)
        exp = 600;
}
void ktM(int &M)
{
    if (M < 0)
        M = 0;
    if (M > 3000)
        M = 3000;
}
////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
        return -99;
    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0)
        {
            exp2 += 29;
            ktexp(exp2);
        }
        else if (e1 == 1)
        {
            exp2 += 45;
            ktexp(exp2);
        }
        else if (e1 == 2)
        {
            exp2 += 75;
            ktexp(exp2);
        }
        else
            exp2 += 149;
        ktexp(exp2);

        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 += (D % 200 == 0) ? (D / 200) : round(D / 200 + 0.5);
            ktexp(exp1);
        }
        else
        {
            exp1 -= D / 100;
            // exp1 = (D % 100 == 0) ? (exp1) : round(exp1 + 0.5);
            ktexp(exp1);
        }
    }
    else
    {
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 += ((e1 % 4 == 0) ? (e1 / 4 + 19) : round(e1 / 4 + 0.5) + 19); // thong tin 1
            ktexp(exp2);
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 += ((e1 % 9 == 0) ? (e1 / 9 + 21) : round(e1 / 9 + 0.5) + 21); // thong tin 2
            ktexp(exp2);
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 += ((e1 % 16 == 0) ? (e1 / 16 + 17) : round(e1 / 16 + 0.5) + 17); // thong tin 3
            ktexp(exp2);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 += ((e1 % 4 == 0) ? (e1 / 4 + 19) : round(e1 / 4 + 0.5) + 19); // thong tin 1

            ktexp(exp2);

            if (exp2 > 200)
            {
                exp2 += ((e1 % 9 == 0) ? (e1 / 9 + 21) : round(e1 / 9 + 0.5) + 21); // thong tin 2

                ktexp(exp2);
            }
        }
        else
        {
            exp2 += ((e1 % 4 == 0) ? (e1 / 4 + 19) : round(e1 / 4 + 0.5) + 19); // thong tin 1

            exp2 += ((e1 % 9 == 0) ? (e1 / 9 + 21) : round(e1 / 9 + 0.5) + 21); // thong tin 2

            ktexp(exp2);
            if (exp2 > 400)
            {
                exp2 += ((e1 % 16 == 0) ? (e1 / 16 + 17) : round(e1 / 16 + 0.5) + 17); // thong tin 3

                ktexp(exp2);
                exp2 = (exp2 * 23 % 20 == 0) ? (exp2 * 23 / 20) : (round(exp2 * 23 / 20 + 0.5));
                ktexp(exp2);
            }
        }
        exp1 -= e1;
        ktexp(exp1);
    }
    return exp1 + exp2;
}

// Task 2
void conduong2(int &HP1, int &EXP1, int &M1, int E2)
{
    if (M1 == 0)
        return;
    if (E2 % 2 != 0)
    {
        double m = 1.0 * M1 * 50 / 100;
        int m1 = 0;
        while (true)
        {
            if (HP1 < 200)
            {
                HP1 = (HP1 * 13 % 10 == 0) ? (HP1 * 13 / 10) : round(HP1 * 13 / 10 + 0.5);
                m1 += 150;
                M1 -= 150;
            }
            else if (HP1 >= 200)
            {
                HP1 = (HP1 * 11 % 10 == 0) ? (HP1 * 11 / 10) : round(HP1 * 11 / 10 + 0.5);
                kthp(HP1);
                m1 += 70;
                M1 -= 70;
            }
            if (m1 > m)
                return;
            if (EXP1 < 400)
            {
                m1 += 200;
                M1 -= 200;
            }
            else if (EXP1 >= 400)
            {
                m1 += 120;
                M1 -= 120;
            }
            EXP1 = (EXP1 * 113 % 100 == 0) ? (EXP1 * 113 / 100) : round(EXP1 * 113 / 100 + 0.5);
            if (m1 > m)
                return;
            if (EXP1 < 300)
            {
                m1 += 100;
                M1 -= 100;
            }
            else if (EXP1 >= 300)
            {
                m1 += 120;
                M1 -= 120;
            }
            EXP1 = (EXP1 * 9 % 10 == 0) ? (EXP1 * 9 / 10) : round(EXP1 * 9 / 10 + 0.5);
            if (m1 > m)
                return;
        }
    }
    else
    {
        if (HP1 < 200)
        {
            HP1 = (HP1 * 13 % 10 == 0) ? (HP1 * 13 / 10) : round(HP1 * 13 / 10 + 0.5);
            M1 -= 150;
        }
        else if (HP1 >= 200)
        {
            HP1 = (HP1 * 11 % 10 == 0) ? (HP1 * 11 / 10) : round(HP1 * 11 / 10 + 0.5);
            kthp(HP1);
            M1 -= 70;
        }
        if (M1 <= 0)
            return;
        if (EXP1 < 400)
        {
            M1 -= 200;
        }
        else if (EXP1 >= 400)
        {
            M1 -= 120;
        }
        EXP1 = (EXP1 * 113 % 100 == 0) ? (EXP1 * 113 / 100) : round(EXP1 * 113 / 100 + 0.5);
        if (M1 <= 0)
            return;
        if (EXP1 < 300)
        {
            M1 -= 100;
        }
        else if (EXP1 >= 300)
        {
            M1 -= 120;
        }
        EXP1 = (EXP1 * 9 % 10 == 0) ? (EXP1 * 9 / 10) : round(EXP1 * 9 / 10 + 0.5);
        if (M1 <= 0)
            return;
    }
}
int calculate_i(int E2)
{
    if (E2 < 10)
    { // Nếu E2 là số có một chữ số
        return E2;
    }
    else
    {                                      // Nếu E2 là số có hai chữ số
        int digit_sum = E2 / 10 + E2 % 10; // Tính tổng của hai chữ số
        return digit_sum % 10;             // Lấy số hàng đơn vị của tổng làm giá trị cho i
    }
}
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
        return -99;
    double P1, P2, P3;
    // con duong 1
    int S = (int(sqrt(EXP1) + 0.5)) * (int(sqrt(EXP1) + 0.5));
    if (EXP1 >= S)
        P1 = 1;
    else
    {
        P1 = 1.0 * (1.0 * EXP1 / S + 80.0) / 123;
    }
    // con duong 2
    conduong2(HP1, EXP1, M1, E2);
    kthp(HP1);
    ktexp(EXP1);
    ktM(M1);
    HP1 = (HP1 * 83 % 100 == 0) ? (HP1 * 83 / 100) : round(HP1 * 83 / 100 + 0.5);
    EXP1 = (EXP1 * 117 % 100 == 0) ? (EXP1 * 117 / 100) : round(EXP1 * 117 / 100 + 0.5);
    ktexp(EXP1);
    int S2 = (int(sqrt(EXP1) + 0.5)) * (int(sqrt(EXP1) + 0.5));
    if (EXP1 >= S2)
        P2 = 1.0;
    else
    {
        P2 = 1.0 * (1.0 * EXP1 / S2 + 80.0) / 123;
    }
    // con duong 3
    int arr[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = calculate_i(E2);
    P3 = 1.0 * arr[i] / 100;
    if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0)
    {
        EXP1 = (EXP1 * 75 % 100 == 0) ? (EXP1 * 75 / 100) : round(EXP1 * 75 / 100 + 0.5);
    }
    else
    {
        double P = (P1 + P2 + P3) / 3 * 1.0;
        if (P < 0.5)
        {
            HP1 = (HP1 * 85 % 100 == 0) ? (HP1 * 85 / 100) : round(HP1 * 85 / 100 + 0.5);
            EXP1 = (EXP1 * 115 % 100 == 0) ? (EXP1 * 115 / 100) : round(EXP1 * 115 / 100 + 0.5);
            ktexp(EXP1);
        }
        else
        {
            HP1 = (HP1 * 90 % 100 == 0) ? (HP1 * 90 / 100) : round(HP1 * 90 / 100 + 0.5);
            EXP1 = (EXP1 * 120 % 100 == 0) ? (EXP1 * 120 / 100) : round(EXP1 * 120 / 100 + 0.5);
            ktexp(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}
int sumDigits(int num)
{
    if (num < 10)
    {
        return num;
    }
    else
    {
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sumDigits(sum);
    }
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;
    int matrix[10][10];
    // Gán giá trị 0 cho từng phần tử trong ma trận
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = 0;
        }
    }
    int sd = 0;
    int sa = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (matrix[i][j] > (E3 * 2))
                sd++;
            if (matrix[i][j] < (-E3))
                sa++;
        }
    }
    sd = sumDigits(sd);
    sa = sumDigits(sa);
    // duong cheo trai
    int maxtrai = matrix[sd][sa];
    int col1 = sd;
    int row1 = sa;
    while (col1 > 0 && row1 > 0)
    {
        col1--;
        row1--;
        maxtrai = max(maxtrai, matrix[col1][row1]);
    }
    int col11 = sd;
    int row11 = sa;
    while (col11 < 9 && row11 < 9)
    {
        col11++;
        row11++;
        maxtrai = max(maxtrai, matrix[col1][row1]);
    }
    // duong cheo phai
    int maxphai = matrix[sd][sa];
    int col2 = sd;
    int row2 = sa;
    while (col2 < 9 && row2 > 0)
    {
        col2++;
        row2--;
        maxphai = max(maxphai, matrix[col2][row2]);
    }
    int col22 = sd;
    int row22 = sa;
    while (col22 > 0 && row22 < 9)
    {
        col22--;
        row22++;
        maxphai = max(maxphai, matrix[col22][row22]);
    }
    int diemso = max(maxtrai, maxphai);
    if (abs(matrix[sd][sa]) > diemso)
    {
        HP1 = (HP1 * 90 % 100 == 0) ? (HP1 * 90 / 100) : round(HP1 * 90 / 100 + 0.5);
        EXP1 = (EXP1 * 88 % 100 == 0) ? (EXP1 * 88 / 100) : round(EXP1 * 88 / 100 + 0.5);
        HP2 = (HP2 * 90 % 100 == 0) ? (HP2 * 90 / 100) : round(HP2 * 90 / 100 + 0.5);
        EXP2 = (EXP2 * 88 % 100 == 0) ? (EXP2 * 88 / 100) : round(EXP2 * 88 / 100 + 0.5);
        kthp(HP1);
        kthp(HP2);
        ktexp(EXP1);
        ktexp(EXP2);

        return matrix[sd][sa];
    }
    else
    {
        HP1 = (HP1 * 110 % 100 == 0) ? (HP1 * 110 / 100) : round(HP1 * 110 / 100 + 0.5);
        EXP1 = (EXP1 * 112 % 100 == 0) ? (EXP1 * 112 / 100) : round(EXP1 * 112 / 100 + 0.5);
        HP2 = (HP2 * 110 % 100 == 0) ? (HP2 * 110 / 100) : round(HP2 * 110 / 100 + 0.5);
        EXP2 = (EXP2 * 112 % 100 == 0) ? (EXP2 * 112 / 100) : round(EXP2 * 112 / 100 + 0.5);
        kthp(HP1);
        kthp(HP2);
        ktexp(EXP1);
        ktexp(EXP2);

        return diemso;
    }
    return 0;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    // Kiểm tra độ dài của mật khẩu
    if (strlen(s) < 8)
    {
        return -1;
    }
    else if (strlen(s) > 20)
    {
        return -2;
    }
    string emailString(email);
    string se = "";
    for (unsigned int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
        {
            break;
        }
        se += email[i];
    }
    const char *tmp = se.c_str();
    const char *p = strstr(s, tmp);
    if (p)
    {
        return -(300 + (p - s));
    }
    // Kiểm tra sự tồn tại của nhiều hơn 2 ký tự liên tiếp và giống nhau
    for (int i = 0; i < strlen(s) - 2; i++)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            return -(400 + i);
        }
    }
    // Kiểm tra sự tồn tại của ít nhất 1 ký tự đặc biệt
    bool hasSpecialChar = false;
    for (int i = 0; i < strlen(s); i++)
    {
        char c = s[i];
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!')
        {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar)
    {
        return -5;
    }
    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]) || isalpha(s[i]) || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            continue;
        else
        {
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int maxsoluong = 0;
    bool timthay = false;
    int vitri = 0;
    for (int i = 0; i < num_pwds - 1; i++)
    {
        int soluong = 1;
        for (int j = i + 1; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                timthay = true;
                soluong++;
                if (soluong > maxsoluong)
                {
                    maxsoluong = soluong;
                    vitri = i;
                }
                if (soluong == maxsoluong)
                {
                    if (strlen(arr_pwds[j]) > strlen(arr_pwds[vitri]))
                    {
                        vitri = i;
                    }
                }
            }
        }
    }
    if (!timthay)
    {
        int maxkitu = 0;
        for (int i = 0; i < num_pwds; i++)
        {
            if (strlen(arr_pwds[i]) > maxkitu)
            {
                vitri = i;
                maxkitu = strlen(arr_pwds[i]);
            }
        }
    }
    return vitri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
// using namespace std;