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
int check_condition_1(int &HP1, int &EXP1, int &M1)
{
    if (HP1 < 0)
    {
        HP1 = 0;
        return HP1;
    }

    if (HP1 > 666)
    {
        HP1 = 666;
        return HP1;
    }

    if (EXP1 < 0)
    {
        EXP1 = 0;
        return EXP1;
    }

    if (EXP1 > 600)
    {
        EXP1 = 600;
        return EXP1;
    }

    if (M1 > 3000)
    {
        M1 = 3000;
        return M1;
    }

    if (M1 < 0)
    {
        M1 = 0;
        return M1;
    }

    return HP1;
    return EXP1;
    return M1;
}

int check_condition_2(int &exp1, int &exp2)
{
    if (exp1 < 0)
    {
        exp1 = 0;
        return exp1;
    }

    if (exp1 > 600)
    {
        exp1 = 600;
        return exp1;
    }

    if (exp2 < 0)
    {
        exp2 = 0;
        return exp2;
    }

    if (exp2 > 600)
    {
        exp2 = 600;
        return exp2;
    }

    return exp2;
    return exp1;
}

int check_condition_3(int &HP1, int &HP2, int &EXP1, int &EXP2)
{
    if (HP1 < 0)
    {
        HP1 = 0;
        return HP1;
    }

    if (HP1 > 666)
    {
        HP1 = 666;
        return HP1;
    }

    if (HP2 < 0)
    {
        HP2 = 0;
        return HP1;
    }

    if (HP2 > 666)
    {
        HP2 = 666;
        return HP2;
    }

    if (EXP1 < 0)
    {
        EXP1 = 0;
        return EXP1;
    }

    if (EXP1 > 600)
    {
        EXP1 = 600;
        return EXP1;
    }

    if (EXP2 < 0)
    {
        EXP2 = 0;
        return EXP2;
    }

    if (EXP2 > 600)
    {
        EXP2 = 600;
        return EXP2;
    }
    return HP1;
    return HP2;
    return EXP1;
    return EXP2;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }
    check_condition_2(exp1, exp2);
    double d;
    if (e1 >= 0 && e1 <= 3)
    {
        switch (e1)
        {
        case (0):
            exp2 = exp2 + 29;
            break;
        case (1):
            exp2 = exp2 + 45;
            break;
        case (2):
            exp2 = exp2 + 75;
            break;
        case (3):
            exp2 = exp2 + 29 + 45 + 75;
            break;
            check_condition_2(exp1, exp2);
        }
        d = e1 * 3 + exp1 * 7;
        if (ceil(float(fmod(d, 2))) == 0)
        {
            d = d / 200;

            exp1 = ceil(exp1 + d - 1e-8);
            check_condition_2(exp1, exp2);
        }
        else
        {
            d = d / 100;

            exp1 = ceil((float)exp1 - d - 1e-8);
            check_condition_2(exp1, exp2);
        }
    }
    else if (e1 >= 4 && e1 <= 99)
    {
        double n;
        if (e1 >= 4 && e1 <= 19)
        {
            n = ceil((float)(e1 / 4.0) + 19 - 1e-8);

            exp2 = ceil((float)exp2 + n - 1e-8);
            check_condition_2(exp1, exp2);
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            n = ceil((float)(e1 / 9.0) + 21 - 1e-8);

            exp2 = ceil((float)exp2 + n - 1e-8);
            check_condition_2(exp1, exp2);
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            n = ceil((float)(e1 / 16.0) + 17 - 1e-8);

            exp2 = ceil((float)exp2 + n - 1e-8);
            check_condition_2(exp1, exp2);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            n = ceil((float)(e1 / 4.0) + 19 - 1e-8);

            exp2 = ceil((float)exp2 + n - 1e-8);
            check_condition_2(exp1, exp2);
            if (exp2 > 200)
            {
                n = ceil((float)(e1 / 9.0) + 21 - 1e-8);
                exp2 = ceil((float)exp2 + n - 1e-8);
                check_condition_2(exp1, exp2);
            }
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            n = ceil((float)e1 / 4 + 19 - 1e-8);
            exp2 = ceil((float)exp2 + n);
            check_condition_2(exp1, exp2);
            n = ceil((float)e1 / 9 + 21 - 1e-8);
            exp2 = ceil((float)exp2 + n - 1e-8);
            check_condition_2(exp1, exp2);
            if (exp2 > 400)
            {
                n = ceil((float)e1 / 16 + 17 - 1e-8);
                exp2 = ceil((float)exp2 + n - 1e-8);
                exp2 = ceil((float)1.15 * exp2 - 1e-8);
                check_condition_2(exp1, exp2);
            }
        }
        exp1 = exp1 - e1;
    }
    check_condition_2(exp1, exp2);
    return exp1 + exp2;
}

// Task 2

int check_so_chinh_phuong(int &n, int &S)
{
    int a = floor(sqrt(n));
    int b = ceil(sqrt(n));
    S = (n - a * a < b * b - n) ? a * a : b * b;
    return S;
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }
    check_condition_1(HP1, EXP1, M1);
    int P_sum, P1, P2, P3, S;
    check_so_chinh_phuong(EXP1, S);
    if (EXP1 >= S)
    {
        P1 = 100;
    }
    else
    {
        P1 = ceil(((float)((EXP1 / S) + 80) * 100) / 123);
    }

    check_condition_1(HP1, EXP1, M1);
    int m;
    m = ceil((float)M1 * 0.5);
    int cnt = 0;

    if (E2 % 2 != 0)
    {
        if (M1 != 0)
        {
            while (cnt <= m)
            {
                if (cnt <= m)
                {
                    if (HP1 < 200)
                    {
                        HP1 = ceil(((float)HP1 * 1.3) - 1e-8);
                        M1 -= 150;
                        cnt += 150;
                        check_condition_1(HP1, EXP1, M1);
                    }
                    else if (HP1 >= 200)
                    {
                        HP1 = ceil(((float)HP1 * 1.1) - 1e-8);
                        M1 -= 70;
                        cnt += 70;
                        check_condition_1(HP1, EXP1, M1);
                    }
                }

                if (cnt <= m)
                {
                    if (EXP1 < 400)
                    {
                        M1 -= 200;
                        EXP1 = ceil(((float)EXP1 * 1.13) - 1e-8);
                        cnt += 200;
                        check_condition_1(HP1, EXP1, M1);
                    }
                    else if (EXP1 >= 400)
                    {
                        M1 -= 120;
                        EXP1 = ceil(((float)EXP1 * 1.13) - 1e-8);
                        cnt += 120;
                        check_condition_1(HP1, EXP1, M1);
                    }
                }
                if (cnt <= m)
                {
                    if (EXP1 < 300)
                    {
                        M1 -= 100;
                        EXP1 = ceil(((float)EXP1 * 0.9) - 1e-8);
                        cnt += 100;
                        check_condition_1(HP1, EXP1, M1);
                    }
                    else if (EXP1 >= 300)
                    {
                        M1 -= 120;
                        EXP1 = ceil(((float)EXP1 * 0.9) - 1e-8);
                        cnt += 120;
                        check_condition_1(HP1, EXP1, M1);
                    }
                }
            }
            HP1 = ceil(((float)HP1 * 0.83) - 1e-8);
            EXP1 = ceil(((float)EXP1 * 1.17) - 1e-8);
        }
    }
    else if (E2 % 2 == 0)
    {
        check_condition_1(HP1, EXP1, M1);
        if (HP1 < 200)
        {
            HP1 = ceil((float)HP1 * 1.3 - 1e-8);
            M1 -= 150;
            cnt += 150;
            check_condition_1(HP1, EXP1, M1);
        }
        else if (HP1 >= 200)
        {
            HP1 = ceil((float)HP1 * 1.1 - 1e-8);
            M1 -= 70;
            cnt += 70;
            check_condition_1(HP1, EXP1, M1);
        }
        check_condition_1(HP1, EXP1, M1);
        if (M1 > 0)
        {
            if (EXP1 < 400)
            {
                M1 -= 200;
                EXP1 = ceil(((float)EXP1 * 1.13) - 1e-8);
                cnt += 200;
                check_condition_1(HP1, EXP1, M1);
            }
            else if (EXP1 >= 400)
            {
                M1 -= 120;
                EXP1 = ceil(((float)EXP1 * 1.13) - 1e-8);
                cnt += 120;
                check_condition_1(HP1, EXP1, M1);
            }
            check_condition_1(HP1, EXP1, M1);
            if (M1 > 0)
            {
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    EXP1 = ceil(((float)EXP1 * 0.9) - 1e-8);
                    cnt += 100;
                    check_condition_1(HP1, EXP1, M1);
                }
                else if (EXP1 >= 300)
                {
                    M1 -= 120;
                    EXP1 = ceil(((float)EXP1 * 0.9) - 1e-8);
                    cnt += 120;
                    check_condition_1(HP1, EXP1, M1);
                }
            }
        }

        HP1 = ceil(((float)HP1 * 0.83) - 1e-8);
        EXP1 = ceil(((float)EXP1 * 1.17) - 1e-8);
        check_condition_1(HP1, EXP1, M1);
    }
    check_condition_1(HP1, EXP1, M1);
    check_so_chinh_phuong(EXP1, S);
    if (EXP1 >= S)
    {
        P2 = 100;
    }
    else
    {
        P2 = ceil(((float)((EXP1 / S) + 80) * 100) / 123);
    }
    int sum = 0;
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 < 10)
    {
        i = E2;
    }
    else
    {
        i = (E2 / 10 + E2 % 10) % 10;
    }
    P3 = P[i];
    if (P1 == 100 && P2 == 100 && P3 == 100)
    {
        EXP1 = ceil(((float)EXP1 * 0.75) - 1e-8);
    }
    else
    {
        P_sum = ceil((float)((P1 + P2 + P3) / 3) - 1e-8);
        if (P_sum < 50)
        {
            HP1 = ceil(((float)HP1 * 0.85) - 1e-8);
            EXP1 = ceil(((float)EXP1 * 1.15) - 1e-8);
            check_condition_1(HP1, EXP1, M1);
        }
        else if (P_sum >= 50)
        {
            HP1 = ceil(HP1 * 0.9 - 1e-8);
            EXP1 = ceil(((float)EXP1 * 1.2) - 1e-8);
            check_condition_1(HP1, EXP1, M1);
        }
        check_condition_1(HP1, EXP1, M1);
    }
    check_condition_1(HP1, EXP1, M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }
    check_condition_3(HP1, HP2, EXP1, EXP2);
    int a[10][10];
    int cntt(0), cnt(0), tmp1, tmp2, i, j, k, s, p;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (a[i][j] > (E3 * 2))
            {
                cntt++;
            }
            if (a[i][j] < 0 && a[i][j] < -E3)
            {
                cnt++;
            }
        }
    }

    tmp1 = cntt / 10;
    tmp2 = cntt % 10;
    i = tmp1 + tmp2;
    k = i;

    while (i > 9)
    {
        tmp1 = k / 10;
        tmp2 = k % 10;
        i = tmp1 + tmp2;
    }
    k = i;

    tmp1 = cnt / 10;
    tmp2 = cnt % 10;
    s = j;
    j = tmp1 + tmp2;
    while (j > 9)
    {
        tmp1 = s / 10;
        tmp2 = s % 10;
        j = tmp1 + tmp2;
    }
    s = j;

    p = a[0][0];
    int t = k + s;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i + j == t)
            {
                if (a[i][j] > p)
                    swap(p, a[i][j]);
            }
        }
    }
    int e = k - s;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j - i == e)
            {
                if (a[i][j] > p)
                    swap(p, a[i][j]);
            }
        }
    }
    int result;
    if (abs(a[k][s]) > p)
    {
        EXP1 = ceil(EXP1 * 0.88 - 1e-8);
        HP1 = ceil(HP1 * 0.9 - 1e-8);
        EXP2 = ceil(EXP2 * 0.88 - 1e-8);
        HP2 = ceil(HP2 * 0.9 - 1e-8);
        check_condition_3(HP1, HP2, EXP1, EXP2);
        result = a[k][s];
    }
    else if (abs(a[k][s]) < p)
    {
        EXP1 = ceil(EXP1 * 1.12 - 1e-8);
        HP1 = ceil(HP1 * 1.1 - 1e-8);
        EXP2 = ceil(EXP2 * 1.12 - 1e-8);
        HP2 = ceil(HP2 * 1.1 - 1e-8);
        check_condition_3(HP1, HP2, EXP1, EXP2);
        result = p;
    }
    else if (abs(a[k][s]) == p)
    {
        result = p;
        EXP1 = ceil((float)EXP1 * 1.12 - 1e-8);
        HP1 = ceil((float)HP1 * 1.1 - 1e-8);
        EXP2 = ceil((float)EXP2 * 1.12 - 1e-8);
        HP2 = ceil((float)HP2 * 1.1 - 1e-8);
        check_condition_3(HP1, HP2, EXP1, EXP2);
    }
    check_condition_3(HP1, HP2, EXP1, EXP2);
    return result;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    string se(email);
    unsigned long long int att = se.find("@");
    se.erase(att, string::npos);

    int s_length = strlen(s);
    if (s_length < 8)
    {
        return -1;
    }
    else if (s_length > 20)
    {
        return -2;
    }

    if (strstr(s, se.c_str()) != nullptr)
    {
        return -(300 + string(s).find(se));
    }

    for (int i = 0; i < s_length - 2; i++)
    {
        if (s[i] == s[i + 1])
        {
            if (s[i + 1] == s[i + 2])
            {

                return -(400 + i);
            }
        }
    }

    int cntt = 0;
    for (int i = 0; i < s_length; i++)
    {
        char t = s[i];
        if ((t > 'a' || t < 'z') && (t > 'A' || t < 'Z') && (t > '0' || t < '9'))
        {

            if (t == '!' || t == '@' || t == '#' || t == '%' || t == '$')
            {
                cntt++;
            }
        }
    }
    if (cntt < 1)
    {
        return -5;
    }
    int x = 0;
    for (int i = 0; i < s_length; i++)
    {
        char t = s[i];
        x++;
        if (t == '"' || t == '^' || t == '&' || t == '*' || t == '(' || t == ')' || t == '_' || t == '+' || t == '=' || t == '{' || t == '}' || t == '[' || t == ']' || t == '|' || t == ':' || t == ';' || t == '?' || t == '/' || t == '<' || t == '>' || t == ',' || t == '.' || t == '`' || t == '~')
        {
            return x - 1;
        }
    }

    return -10;
}

// Task 5
int time_appears(const char *arr_pwds[], int num_pwds, const char *p)
{
    int cntt = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        if (strcmp(arr_pwds[i], p) == 0)
        {
            cntt++;
        }
    }
    return cntt;
}
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int max_cntt = 0;
    int maxx_len = 0;
    int result = -1;

    for (int i = 0; i < num_pwds; i++)
    {
        const char *p = arr_pwds[i];
        int length = strlen(p);
        int appear = time_appears(arr_pwds, num_pwds, p);

        if (appear > max_cntt || (appear == max_cntt && length > maxx_len))
        {
            max_cntt = appear;
            maxx_len = length;
            result = i;
        }
    }

    return result;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////