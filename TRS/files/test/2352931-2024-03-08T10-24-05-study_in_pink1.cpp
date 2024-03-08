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
void HP(int &HP1, int &HP2)
{

    if (HP1 > 666)
        HP1 = 666;
    else if (HP1 < 0)
        HP1 = 0;
    if (HP2 > 666)
        HP2 = 666;
    else if (HP2 < 0)
        HP2 = 0;
}
void EXP(int &EXP1, int &EXP2)
{

    if (EXP1 > 600)
        EXP1 = 600;
    else if (EXP1 < 0)
        EXP1 = 0;
    if (EXP2 > 600)
        EXP2 = 600;
    else if (EXP2 < 0)
        EXP2 = 0;
}
void M(int &M1, int &M2)
{

    if (M1 > 3000)
        M1 = 3000;
    else if (M1 < 0)
        M1 = 0;
    if (M2 > 3000)
        M2 = 3000;
    else if (M2 < 0)
        M2 = 0;
}
// Task 1
void firstMeet_case1(int &exp1, int &exp2, int e1)
{
    float a;
    EXP(exp1, exp2);
    if (e1 == 0)
        exp2 = exp2 + 29;
    if (e1 == 1)
        exp2 = exp2 + 45;
    if (e1 == 2)
        exp2 = exp2 + 75;
    if (e1 == 3)
        exp2 = exp2 + 29 + 45 + 75;
    int D = e1 * 3 + exp1 * 7;
    if (D % 2 == 0)
    {
        a = exp1 + D / 200.0;
    }
    else
    {
        a = exp1 - D / 100.0;
    }
    exp1 = ceil(a);
    EXP(exp1, exp2);
}
void firstMeet_case2(int &exp1, int &exp2, int e1)
{
    float a, b, c;
    EXP(exp1, exp2);
    if (e1 <= 19)
    {
        a = exp2 + e1 / 4.0 + 19;
        exp2 = ceil(a);
        EXP(exp1, exp2);
    }
    else if (e1 <= 49)
    {
        a = exp2 + e1 / 9.0 + 21;
        exp2 = ceil(a);
        EXP(exp1, exp2);
    }
    else if (e1 <= 65)
    {
        a = exp2 + e1 / 16.0 + 17;
        exp2 = ceil(a);
        EXP(exp1, exp2);
    }
    else if (e1 <= 79)
    {
        a = exp2 + e1 / 4.0 + 19;
        exp2 = ceil(a);
        EXP(exp1, exp2);
        if (exp2 > 200)
        {
            b = exp2 + e1 / 9.0 + 21;

            exp2 = ceil(b);

            EXP(exp1, exp2);
        }
    }
    else if (e1 <= 99)
    {
        a = exp2 + e1 / 4.0 + 19;
        exp2 = ceil(a);
        EXP(exp1, exp2);
        b = exp2 + e1 / 9.0 + 21;
        exp2 = ceil(b);
        EXP(exp1, exp2);
        if (exp2 > 400)
        {
            c = exp2 + e1 / 16.0 + 17;
            exp2 = ceil(c);
            c = exp2 * 1.15;
            exp2 = ceil(c);
            EXP(exp1, exp2);
        }
    }
    exp1 = exp1 - e1;
    EXP(exp1, exp2);
}
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
        return -99;
    else
    {
        EXP(exp1, exp2);
        if (e1 >= 0 && e1 <= 3)
        {
            firstMeet_case1(exp1, exp2, e1);
        }
        if (e1 >= 4 && e1 <= 99)
        {
            firstMeet_case2(exp1, exp2, e1);
        }
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage_Road1(int &HP1, int &EXP1, int &M1, int E2)
{
    float S, a, b, c;
    int P1;
    a = sqrt(EXP1);
    b = floor(a);
    c = ceil(a);
    if (abs(pow(b, 2) - EXP1) < abs(pow(c, 2) - EXP1))
        S = pow(b, 2);
    else
        S = pow(c, 2);
    if (EXP1 >= S)
        P1 = 100;
    else
    {
        a = (EXP1 / S + 80) / 123.0 * 100;
        P1 = int(a + 0.5);
    }
    return P1;
}
void traceLuggage_Road2_Odd(int &HP1, int &EXP1, int &M1, int E2)
{
    float a, paid = 0, c = 0.5 * M1;
    int b = 0;
    for (int i = 0; i < 100; i++)
    {
        if (M1 >= c)
        {
            if (HP1 < 200)
            {
                paid += 150;
                M1 -= 150;
                M(M1, b);
                a = HP1 * 1.3;
                HP1 = ceil(a);
                HP(HP1, b);
            }
            else if (HP1 >= 200)
            {
                paid += 70;
                M1 -= 70;
                M(M1, b);
                a = HP1 * 1.1;
                HP1 = ceil(a);
                HP(HP1, b);
            }
        }
        else
            break;
        if (M1 >= c)
        {
            if (EXP1 < 400)
            {
                paid += 200;
                M1 -= 200;
                M(M1, b);
                a = EXP1 * 1.13;
                EXP1 = ceil(a);
                EXP(EXP1, b);
            }

            else if (EXP1 >= 400)
            {
                paid += 120;
                M1 -= 120;
                M(M1, b);
                a = EXP1 * 1.13;
                EXP1 = ceil(a);
                EXP(EXP1, b);
            }
        }
        else
            break;
        if (M1 >= c)
        {

            if (EXP1 < 300)
            {
                paid += 100;
                M1 -= 100;
                M(M1, b);
                a = EXP1 * 0.9;
                EXP1 = ceil(a);
                EXP(EXP1, b);
            }
            else if (EXP1 >= 300)
            {
                paid += 120;
                M1 -= 120;
                M(M1, b);
                a = EXP1 * 0.9;
                EXP1 = ceil(a);
                EXP(EXP1, b);
            }
        }
        else
            break;
    }
    a = HP1 * 0.83;
    HP1 = ceil(a);
    HP(HP1, b);
    a = EXP1 * 1.17;
    EXP1 = ceil(a);
    EXP(EXP1, b);
}
void traceLuggage_Road2_Even(int &HP1, int &EXP1, int &M1, int E2)
{
    float a, paid = 0;
    int b = 0;
    for (int i = 0; i < 1; i++)
    {
        if (M1 > 0)
        {
            if (HP1 < 200)
            {
                M1 -= 150;
                M(M1, b);
                a = HP1 * 1.3;
                HP1 = ceil(a);
                HP(HP1, b);
            }
            else if (HP1 >= 200)
            {
                M1 -= 70;
                M(M1, b);
                a = HP1 * 1.1;
                HP1 = ceil(a);
                HP(HP1, b);
            }
        }
        else
            break;
        if (M1 > 0)
        {
            if (EXP1 < 400)
            {
                M1 -= 200;
                M(M1, b);
                a = EXP1 * 1.13;
                EXP1 = ceil(a);
                EXP(EXP1, b);
            }
            else if (EXP1 >= 400)
            {
                M1 -= 120;
                M(M1, b);
                a = EXP1 * 1.13;
                EXP1 = ceil(a);
                EXP(EXP1, b);
            }
        }
        else
            break;
        if (M1 > 0)
        {
            if (EXP1 < 300)
            {
                M1 -= 100;
                M(M1, b);
                a = EXP1 * 0.9;
                EXP1 = ceil(a);
                EXP(EXP1, b);
            }
            else if (EXP1 >= 300)
            {
                M1 -= 120;
                M(M1, b);
                a = EXP1 * 0.9;
                EXP1 = ceil(a);
                EXP(EXP1, b);
            }
        }
        else
            break;
    }

    a = HP1 * 0.83;
    HP1 = ceil(a);
    HP(HP1, b);
    a = EXP1 * 1.17;
    EXP1 = ceil(a);
    EXP(EXP1, b);
}
int traceLuggage_Road3(int &HP1, int &EXP1, int &M1, int E2)
{
    int P3;
    int a[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (E2 == j + 10 * i)
            {
                if (i + j >= 10)
                {
                    P3 = a[i + j - 10];
                }
                else
                    P3 = a[i + j];
                break;
            }
        }
    }
    return P3;
}
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
        return -99;
    else
    {

        float a;
        int b = 0, P1, P2, P3, P4;
        HP(HP1, b);
        EXP(EXP1, b);
        M(M1, b);
        P1 = traceLuggage_Road1(HP1, EXP1, M1, E2);
        if (E2 % 2 != 0)
        {
            traceLuggage_Road2_Odd(HP1, EXP1, M1, E2);
            P2 = traceLuggage_Road1(HP1, EXP1, M1, E2);
            P3 = traceLuggage_Road3(HP1, EXP1, M1, E2);
        }
        else
        {
            traceLuggage_Road2_Even(HP1, EXP1, M1, E2);
            P2 = traceLuggage_Road1(HP1, EXP1, M1, E2);
            P3 = traceLuggage_Road3(HP1, EXP1, M1, E2);
        }
        a = (P1 + P2 + P3) / 3.0;
        P4 = int(a + 0.5);

        if (P4 == 100)
        {
            a = EXP1 * 0.75;
            EXP1 = ceil(a);
        }
        else if (P4 < 50)
        {
            a = HP1 * 0.85;
            HP1 = ceil(a);
            a = EXP1 * 1.15;
            EXP1 = ceil(a);
        }
        else if (P4 >= 50 && P4 < 100)
        {
            a = HP1 * 0.9;
            HP1 = ceil(a);
            a = EXP1 * 1.2;
            EXP1 = ceil(a);
        }
        EXP(EXP1, b);
        HP(HP1, b);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int max_left_diagonal1(int map[10][10], int n, int m)
{
    int left_diagonal[10], a = 0, b, max_element = 0;
    for (int i = 0; i < 10; i++)
    {
        if (m != 0 && n != 0)
        {
            n--;
            m--;
        }
        else
            break;
    }
    for (int i = 0; i < 10; i++)
    {
        if (n == 0 && m + i < 10 && m != 0)
        {
            left_diagonal[i] = map[i][m + i];

            a++;
        }
        else if (m == 0 && n + i < 10 && n != 0)
        {
            left_diagonal[i] = map[n + i][i];

            a++;
        }
        else if (n == 0 && m == 0)
        {
            left_diagonal[i] = 0;
            a++;
        }
        else
            break;
    }

    for (int i = 0; i < a; i++)
    {
        if (left_diagonal[0] < left_diagonal[i])
        {
            left_diagonal[0] = left_diagonal[i];
        }
    }
    b = left_diagonal[0];
    return b;
}

int max_right_diagonal1(int map[10][10], int n, int m)
{
    int right_diagonal[10], a = 0, b, max_element = 0;
    for (int i = 0; i < 10; i++)
    {
        if (n != 0 && m != 9)
        {
            n--;
            m++;
        }
        else
            break;
    }
    for (int i = 0; i < 10; i++)
    {
        if (n == 0 && m - i >= 0)
        {
            right_diagonal[i] = map[i][m - i];
            a++;
        }
        else if (m == 9 && n + i < 10)
        {
            right_diagonal[i] = map[n + i][m - i];

            a++;
        }
        else
            break;
    }
    for (int i = 0; i < a; i++)
    {
        if (right_diagonal[0] < right_diagonal[i])
        {
            right_diagonal[0] = right_diagonal[i];
        }
    }
    b = right_diagonal[0];
    return b;
}
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;
    else
    {
        HP(HP1, HP2);
        EXP(EXP1, EXP2);
        int map[10][10] = {}, row = 0, collum = 0, a, b, Sherlock_Grade, Taxi_Grade,
            max_left_diagonal, max_right_diagonal;
        float c;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                if (map[i][j] > E3 * 2)
                {
                    row++;
                }
                if (map[i][j] < -E3)
                {
                    collum++;
                }
            }
        }

        for (int i = 0; i < 10; i++)
        {
            if (row >= 10)
            {
                a = row / 10;
                b = row - a * 10;
                row = a + b;
            }
            if (collum >= 10)
            {
                a = collum / 10;
                b = collum - a * 10;
                collum = a + b;
            }
            if (row < 10 && collum < 10)
            {
                break;
            }
        }
        max_left_diagonal = max_left_diagonal1(map, row, collum);
        max_right_diagonal = max_right_diagonal1(map, row, collum);
        Sherlock_Grade = max(max_left_diagonal, max_right_diagonal);
        Taxi_Grade = map[row][collum];
        if (abs(Taxi_Grade) <= Sherlock_Grade)
        {
            c = EXP1 * 1.12;
            EXP1 = ceil(c);
            c = EXP2 * 1.12;
            EXP2 = ceil(c);
            c = HP1 * 1.1;
            HP1 = ceil(c);
            c = HP2 * 1.1;
            HP2 = ceil(c);
            EXP(EXP1, EXP2);
            HP(HP1, HP2);
            return Sherlock_Grade;
        }
        else
        {
            c = EXP1 * 0.88;
            EXP1 = ceil(c);
            c = EXP2 * 0.88;
            EXP2 = ceil(c);
            c = HP1 * 0.9;
            HP1 = ceil(c);
            c = HP2 * 0.9;
            HP2 = ceil(c);
            EXP(EXP1, EXP2);
            HP(HP1, HP2);
            return Taxi_Grade;
        }
    }
}
// Task 4
int checkPassword(const char *s, const char *email)
{
    int a = strlen(s), b = strlen(email);
    string character = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#$%!";
    string se = "";
    int se_length = 0;

    for (int i = 0; i < b; i++)
    {
        if (email[i] == '@')
        {
            break;
        }
        se += email[i];
        se_length++;
    }
    if (a < 8)
    {
        return -1;
    }
    else if (a > 20)
    {
        return -2;
    }

    for (int i = 0; i < a; i++)
    {
        if (se == "")
        {
            return -300;
            break;
        }
        else if (s[i] == se[0])
        {
            bool contain = true;
            for (int j = 0; j < se_length; j++)
            {
                if (i + j > a - 1)
                {
                    contain = false;
                    break;
                }
                if (s[i + j] != se[j])
                {
                    contain = false;
                    break;
                }
            }

            if (contain)
            {
                return -(300 + i);
            }
        }
    }
    for (int i = 0; i < a; i++)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            return -(400 + i);
        }
    }
    bool found1 = true;
    for (int i = 0; i < a; i++)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            found1 = false;
        }
    }
    if (found1)
    {
        return -5;
    }
    for (int i = 0; i < a; i++)
    {
        bool found2 = false;
        for (int j = 0; j < character.length(); j++)
        {
            if (s[i] == character[j])
            {
                found2 = true;
                break;
            }
        }

        if (!found2)
        {
            return i;
        }
    }
    return -10;
}
// Task 5
int str_compare(string a, string b)
{
    if (a.length() != b.length())
    {
        return 0;
    }
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    string most_frequentA[40] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""};
    int frequency = 0, most_frequent = 0, password, compare;
    for (int i = 0; i < num_pwds; i++)
    {
        for (int j = 0; j < num_pwds; j++)
        {
            compare = str_compare(arr_pwds[i], arr_pwds[j]);
            if (compare == 1)
            {
                frequency++;
            }
        }
        if (frequency > most_frequent)
        {
            most_frequent = frequency;
        }
        frequency = 0;
    }
    for (int i = 0; i < num_pwds; i++)
    {
        for (int j = 0; j < num_pwds; j++)
        {
            compare = str_compare(arr_pwds[i], arr_pwds[j]);
            if (compare == 1)
            {
                frequency++;
            }
        }
        if (frequency == most_frequent)
        {
            most_frequentA[i] = arr_pwds[i];
        }
        frequency = 0;
    }
    for (int i = 0; i < num_pwds; i++)
    {
        for (int n = 0; n < num_pwds; n++)
        {
            if (most_frequentA[i].length() >= most_frequentA[n].length())
            {
                password = i;
            }
            else
            {
                password = -1;
                break;
            }
        }
        if (password != -1)
            break;
    }
    return password;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////

