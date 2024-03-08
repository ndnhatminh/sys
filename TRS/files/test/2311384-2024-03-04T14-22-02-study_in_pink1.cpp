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

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
int counter_pwds(string arr_pwds[], int num_pwds, string pwds)
{
    int miss = 0;
    for (int i = 0; i < num_pwds + 1; i++)
    {
        if (arr_pwds[i] == pwds)
        {
            miss++;
        }
    }
    return miss;
}
int counter_pwds_2(string arr_pwds[], int num_pwds, string pwds)
{
    int miss = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        if (arr_pwds[i] == pwds)
        {
            miss++;
        }
    }
    return miss;
}
void checkHP(int &HP)
{
    if (HP < 0)
        HP = 0;
    if (HP >= 666)
        HP = 666;
}
void checkEXP(int &EXP)
{
    if (EXP < 0)
        EXP = 0;
    if (EXP > 600)
        EXP = 600;
}
void checkMoney(int &M)
{
    if (M > 3000)
        M = 3000;
    if (M < 0)
        M = 0;
}
int sum_number(int x)
{
    int hang_chuc, hang_dv, i;
    hang_chuc = x / 10;
    hang_dv = x % 10;
    i = hang_chuc + hang_dv;
    return i;
}
int max_right(int arr[10][10], int i, int j)
{
    int a = i, b = j;
    int c = i, d = j;
    int max = arr[i][j];
    while (b >= 0 && a <= 9)
    {
        if (arr[a][b] > max)
        {
            max = arr[a][b];
        }
        a++;
        b--;
    }
    while (c >= 0 && d <= 9)
    {
        if (arr[c][d] > max)
        {
            max = arr[c][d];
        }
        c--;
        d++;
    }
    return max;
}
int max_left(int arr[10][10], int i, int j)
{
    int a = i, b = j;
    int c = i, d = j;
    int max = arr[i][j];
    while (b >= 0 && a >= 0)
    {
        if (arr[a][b] > max)
        {
            max = arr[a][b];
        }
        a--;
        b--;
    }
    while (d <= 9 && c <= 9)
    {
        if (arr[c][d] > max)
        {
            max = arr[c][d];
        }
        c++;
        d++;
    }
    return max;
}
int max_x(int arr[10][10], int i, int j)
{
    if (max_left(arr, i, j) >= max_right(arr, i, j))
    {
        if (max_left(arr, i, j) < 0)
        {
            return abs(max_left(arr, i, j));
        }
        else
            return max_left(arr, i, j);
    }
    else
    {
        if (max_right(arr, i, j) < 0)
        {
            return abs(max_right(arr, i, j));
        }
        else
            return max_right(arr, i, j);
    }
}
int find_sq(int EXP)
{
    int S;
    if (abs((pow(round(sqrt(EXP)), 2) - EXP)) < abs((pow(round(sqrt(EXP)) + 1, 2) - EXP)))
    {
        S = pow(round(sqrt(EXP)), 2);
    }
    else
        S = pow(round(sqrt(EXP)) + 1, 2);
    return S;
}
// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    int D;
    if (e1 < 0 || e1 > 99)
        return -99;
    checkEXP(exp1);
    checkEXP(exp2);
    // TH1
    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0)
            exp2 = exp2 + 29;
        if (e1 == 1)
            exp2 = exp2 + 45;
        if (e1 == 2)
            exp2 = exp2 + 75;
        if (e1 == 3)
            exp2 = exp2 + 29 + 45 + 75;
        checkEXP(exp2);
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            exp1 = ceil(float(exp1 + (D / 200.0)));
        else
            exp1 = ceil(float(exp1 - (D / 100.0)));
        checkEXP(exp1);
    }
    // TH2
    if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 = ceil(float(exp2 + e1 / 4.0 + 19));
        }
        else if (e1 <= 49)
        {
            exp2 = ceil(float(exp2 + e1 / 9.0 + 21));
        }
        else if (e1 <= 65)
        {
            exp2 = ceil(float(exp2 + e1 / 16.0 + 17));
        }
        else if (e1 <= 79)
        {
            exp2 = ceil(float(exp2 + e1 / 4.0 + 19));
            if (exp2 > 200)
                exp2 = ceil(float(exp2 + e1 / 9.0 + 21));
        }
        else
        {
            exp2 = ceil(float(exp2 + e1 / 4.0 + 19));
            exp2 = ceil(float(exp2 + e1 / 9.0 + 21));
            if (exp2 > 400)
            {
                exp2 = ceil(float(exp2 + e1 / 16.0 + 17));
                exp2 = ceil(float(exp2 * 1.15));
            }
        }
        exp1 = exp1 - e1;
    }
    checkEXP(exp1);
    checkEXP(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (E2 < 0 || E2 > 99)
        return -99;
    checkEXP(EXP1);
    checkHP(HP1);
    checkMoney(M1);
    // road-1
    int S;
    S = find_sq(EXP1);
    double P1;
    if (EXP1 >= S)
        P1 = 100;
    else
        P1 = ((EXP1 * 1.0 / S) + 80) / 123 * 100;
    // road-2
    double P2;
    if (M1 <= 0)
    {
        (HP1 = ceil(float(HP1 * 0.83)));
        EXP1 = (ceil(float(EXP1 * 1.17)));
    }
    else
    {
        float money_if = 0.5 * M1;
        if (E2 % 2 != 0)
        {
            while (1)
            {
                // 1
                if (HP1 < 200)
                {
                    HP1 = ceil(float(HP1 * 1.3));
                    M1 -= 150;
                    checkHP(HP1);
                }
                else
                {
                    HP1 = ceil(float(HP1 * 1.1));
                    M1 -= 70;
                    checkHP(HP1);
                }
                if (M1 < money_if)
                {
                    HP1 = ceil(float(HP1 * 0.83));
                    EXP1 = ceil(float(EXP1 * 1.17));
                    break;
                }
                // 2
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    EXP1 = ceil(float(EXP1 * 1.13));
                    checkEXP(EXP1);
                }
                else
                {
                    M1 -= 120;
                    EXP1 = ceil(float(EXP1 * 1.13));
                    checkEXP(EXP1);
                }
                if (M1 < money_if)
                {
                    HP1 = ceil(float(HP1 * 0.83));
                    EXP1 = ceil(float(EXP1 * 1.17));
                    break;
                }
                // 3
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    EXP1 = ceil(float(EXP1 * 0.9));
                    checkEXP(EXP1);
                }
                else
                {
                    M1 -= 120;
                    EXP1 = ceil(float(EXP1 * 0.9));
                    checkEXP(EXP1);
                }
                if (M1 < money_if)
                {
                    HP1 = ceil(float(HP1 * 0.83));
                    EXP1 = ceil(float(EXP1 * 1.17));
                    break;
                }
            }
            checkEXP(EXP1);
            checkHP(HP1);
        }
        else if (E2 % 2 == 0)
        {
            int i = 1;
            // 1
            while (i == 1)
            {
                if (HP1 < 200)
                {
                    HP1 = ceil(float(HP1 * 1.3));
                    M1 -= 150;
                    checkHP(HP1);
                }
                else
                {
                    HP1 = ceil(float(HP1 * 1.1));
                    M1 -= 70;
                    checkHP(HP1);
                }
                if (M1 <= 0)
                {
                    HP1 = ceil(float(HP1 * 0.83));
                    EXP1 = ceil(float(EXP1 * 1.17));
                    break;
                }
                // 2
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    EXP1 = ceil(float(EXP1 * 1.13));
                    checkEXP(EXP1);
                }
                else
                {
                    M1 -= 120;
                    EXP1 = ceil(float(EXP1 * 1.13));
                    checkEXP(EXP1);
                }
                if (M1 <= 0)
                {
                    HP1 = ceil(float(HP1 * 0.83));
                    EXP1 = ceil(float(EXP1 * 1.17));
                    break;
                }
                // 3
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    EXP1 = ceil(float(EXP1 * 0.9));
                    checkEXP(EXP1);
                }
                else
                {
                    M1 -= 120;
                    EXP1 = ceil(float(EXP1 * 0.9));
                    checkEXP(EXP1);
                }
                HP1 = ceil(float(HP1 * 0.83));
                EXP1 = ceil(float(EXP1 * 1.17));
                i++;
            }
        }
    }
    checkMoney(M1);
    checkHP(HP1);
    checkEXP(EXP1);
    if (EXP1 >= (find_sq(EXP1)))
        P2 = 100.0;
    else
        P2 = ((EXP1 * 1.0 / (find_sq(EXP1))) + 80) / 123 * 100.0;
    // road-3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int P3;
    if (E2 >= 0 && E2 <= 9)
    {
        P3 = P[E2];
    }
    else
    {
        P3 = P[(sum_number(E2) % 10)];
    }
    if (P1 == 100 && P2 == 100 && P3 == 100)
    {
        EXP1 = ceil(float(EXP1 * 0.75));
    }
    else
    {
        float avg_p = (P1 + P2 + P3) / 3;
        if (avg_p < 50)
        {
            HP1 = ceil(float(HP1 * 0.85));
            EXP1 = ceil(float(EXP1 * 1.15));
        };
        if (avg_p >= 50)
        {
            HP1 = ceil(float(HP1 * 0.9));
            EXP1 = ceil(float(EXP1 * 1.2));
        };
    }
    checkEXP(EXP1);
    checkHP(HP1);
    checkMoney(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 < 0 || E3 > 99)
        return -99;
    checkHP(HP1);
    checkHP(HP2);
    checkEXP(EXP1);
    checkEXP(EXP2);
    int matrix_taxi[10][10];
    int matrix_human[10][10];
    // create matrix
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix_taxi[i][j] = 0;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix_human[i][j] = 0;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix_taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            matrix_human[j][i] = max_x(matrix_taxi, j, i);
        }
    }
    // count >E3*2
    int count_1 = 0, count_2 = 0;
    int a, b;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if ((matrix_taxi[i][j]) > (E3 * 2))
            {
                count_1++;
            }
            if ((matrix_taxi[i][j]) < (-E3))
            {
                count_2++;
            }
        }
    }
    a = count_1;
    b = count_2;
    while (a > 9 || b > 9)
    {
        a = sum_number(a);
        b = sum_number(b);
    }
    int result;
    if (abs(matrix_taxi[a][b]) <= matrix_human[a][b])
    {
        HP1 = ceil(float(HP1 * 1.1));
        HP2 = ceil(float(HP2 * 1.1));
        EXP1 = ceil(float(EXP1 * 1.12));
        EXP2 = ceil(float(EXP2 * 1.12));
        checkHP(HP1);
        checkHP(HP2);
        checkEXP(EXP1);
        checkEXP(EXP2);
        return matrix_human[a][b];
    }
    else
    {
        HP1 = ceil(float(HP1 * 0.90));
        HP2 = ceil(float(HP2 * 0.90));
        EXP1 = ceil(float(EXP1 * 0.88));
        EXP2 = ceil(float(EXP2 * 0.88));
        checkHP(HP1);
        checkHP(HP2);
        checkEXP(EXP1);
        checkEXP(EXP2);
        return matrix_taxi[a][b];
    }
}

// Task 4
int checkPassword(const char *pass, const char *email_1)
{
    string s = pass;
    string email = email_1;
    string se;
    int true_value = 0, re_i, true_sletter = 0, sei, key3 = 0;
    if (email.length() <= 100)
    {
        for (int i = 0; i < email.length(); i++)
        {
            if (email[i] == '@')
            {
                true_value++;
                re_i = i;
            }
            if (true_value == 2)
                break;
        }
    }
    if (true_value == 1)
    {
        se = email.substr(0, re_i);
    }
    if (s.length() <= 20 && s.length() >= 8)
    {
        sei = s.find(se);
        if (sei < 0)
        {
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == s[(i + 1)] && s[i] == s[i + 2])
                    return -(400 + i);
                else
                {
                    if (int(s[i]) == 64 || int(s[i]) == 33 || (int(s[i]) <= 37 && int(s[i]) >= 35))
                    {
                        true_sletter++;
                    }
                }
            }
        }
        else
        {
            return -(300 + sei);
        }
    }
    else if (s.length() < 8)
    {
        return -1;
    }
    else if (s.length() > 20)
    {
        return -2;
    }
    if (true_sletter > 0)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (!((48 <= int(s[i]) && int(s[i]) <= 57) || (64 <= (int(s[i])) && (int(s[i])) <= 90) || (97 <= int(s[i]) && int(s[i]) <= 122) || (int(s[i]) == 33) || (35 <= int(s[i]) && int(s[i]) <= 37)))
            {
                return i;
            }
        }
        return -10;
    }
    else
    {
        return -5;
    }
    return -99;
}
// Task 5
int findCorrectPassword(const char *arr_pwds_2[], int num_pwds)
{
    string arr_pwds[num_pwds];
    string longest_string;
    for (int i = 0; i < num_pwds; i++)
        arr_pwds[i] = arr_pwds_2[i];
    int diff_pwds[num_pwds];
    int counter_value[num_pwds];
    int max_i = 0;
    int max = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        diff_pwds[i] = counter_pwds(arr_pwds, i, arr_pwds[i]);
    }
    for (int i = 0; i < num_pwds; i++)
    {
        if (diff_pwds[i] == 1)
        {
            if (counter_pwds_2(arr_pwds, num_pwds, arr_pwds[i]) > max)
            {
                longest_string = arr_pwds[i];
                max_i = i;
                max = counter_pwds_2(arr_pwds, num_pwds, arr_pwds[i]);
            }
            else if (counter_pwds_2(arr_pwds, num_pwds, arr_pwds[i]) == max)
            {
                if (arr_pwds[i].length() > longest_string.length())
                {
                    longest_string = arr_pwds[i];
                    max_i = i;
                }
            }
        }
    }
    return max_i;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////