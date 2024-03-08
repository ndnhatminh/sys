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

int ceil_1(double db)
{
    if (db - (int)db <= 1e-9)
        return db;
    else
        return ceil(db);
}

bool invalid_Event(int e)
{
    return e > 99 || e < 0;
}

void fix_exp(int &exp)
{
    if (exp > 600)
        exp = 600;
    if (exp < 0)
        exp = 0;
}

void fix_hp(int &hp)
{
    if (hp > 666)
        hp = 666;
    if (hp < 0)
        hp = 0;
}

void fix_money(int &money)
{
    if (money > 3000)
        money = 3000;
    if (money < 0)
        money = 0;
}

int near_square(int exp1)
{
    double delta = (double)sqrt(exp1) - (int)sqrt(exp1);
    if (delta < 0.5)
        return (int)sqrt(exp1) * (int)sqrt(exp1);
    else
        return ((int)sqrt(exp1) + 1) * ((int)sqrt(exp1) + 1);
}

void stage_1(int &HP1, int &EXP1, int &M1)
{
    if (HP1 < 200)
    {
        HP1 = ceil_1(0.3 * (double)HP1 + HP1);
        M1 -= 150;
    }
    else
    {
        HP1 = ceil_1(0.1 * (double)HP1 + HP1);
        M1 -= 70;
    }
    fix_hp(HP1);
    fix_money(M1);
}

void stage_2(int &HP1, int &EXP1, int &M1)
{
    if (EXP1 < 400)
        M1 -= 200;
    else
    {
        M1 -= 120;
    }
    EXP1 = ceil_1(0.13 * (double)EXP1 + EXP1);
    fix_exp(EXP1);
    fix_money(M1);
}

void stage_3(int &HP1, int &EXP1, int &M1)
{
    if (EXP1 < 300)
        M1 -= 100;
    else
        M1 -= 120;
    EXP1 = ceil_1(-0.1 * (double)EXP1 + EXP1);
    fix_exp(EXP1);
    fix_money(M1);
}

void stage_1(int &HP1, int &EXP1, int &M1, int &m)
{
    if (HP1 < 200)
    {
        HP1 = ceil_1(0.3 * (double)HP1 + HP1);
        M1 -= 150;
        m += 150;
    }
    else
    {
        HP1 = ceil_1(0.1 * (double)HP1 + HP1);
        M1 -= 70;
        m += 70;
    }
    fix_hp(HP1);
    fix_money(M1);
}

void stage_2(int &HP1, int &EXP1, int &M1, int &m)
{
    if (EXP1 < 400)
    {
        M1 -= 200;
        m += 200;
    }
    else
    {
        M1 -= 120;
        m += 120;
    }
    EXP1 = ceil_1(0.13 * (double)EXP1 + EXP1);
    fix_exp(EXP1);
    fix_money(M1);
}

void stage_3(int &HP1, int &EXP1, int &M1, int &m)
{
    if (EXP1 < 300)
    {
        M1 -= 100;
        m += 100;
    }
    else
    {
        M1 -= 120;
        m += 120;
    }
    EXP1 = ceil_1(-0.1 * (double)EXP1 + EXP1);
    fix_exp(EXP1);
    fix_money(M1);
}

void one_Digit(int &i)
{
    if (i >= 10 && i % 9 != 0)
        i %= 9;
    else if (i % 9 == 0)
        i = 9;
}

int maxDiagnose(int a[10][10], int i_row, int j_col)
{
    int max_locate = a[i_row][j_col];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if ((i - j) == (i_row - j_col) || (i + j) == (i_row + j_col))
            {
                if (a[i][j] > max_locate)
                    max_locate = a[i][j];
            }
        }
    }
    return max_locate;
}

double Probality(int EXP)
{
    double P;
    int S = near_square(EXP);
    if (EXP >= S)
        P = 1;
    else
        P = ((double)EXP / S + 80) / 123;
    return P;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    if (invalid_Event(e1))
        return -99;
    fix_exp(exp1);
    fix_exp(exp2);

    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0)
            exp2 += 29;
        else if (e1 == 1)
            exp2 += 45;
        else if (e1 == 2)
            exp2 += 75;
        else if (e1 == 3)
            exp2 += 149;

        double D = e1 * 3 + exp1 * 7;
        if (int(D) & 1)
            exp1 = ceil_1(exp1 - D / 100);
        else
            exp1 = ceil_1(exp1 + D / 200);
    }

    else if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
            exp2 = ceil_1(double(e1) / 4 + 19 + exp2);
        else if (e1 >= 20 && e1 <= 49)
            exp2 = ceil_1(double(e1) / 9 + 21 + exp2);
        else if (e1 >= 50 && e1 <= 65)
            exp2 = ceil_1(double(e1) / 16 + 17 + exp2);
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 = ceil_1(double(e1) / 4 + 19 + exp2);
            fix_exp(exp2);
            if (exp2 > 200)
                exp2 = ceil_1(double(e1) / 9 + 21 + exp2);
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 = ceil_1(double(e1) / 4 + 19 + exp2);
            fix_exp(exp2);
            exp2 = ceil_1(double(e1) / 9 + 21 + exp2);
            fix_exp(exp2);
            if (exp2 > 400)
            {
                exp2 = ceil_1(double(e1) / 16 + 17 + exp2);
                exp2 = ceil_1(double(exp2) * 0.15 + exp2);
            }
        }
        exp1 -= e1;
    }

    fix_exp(exp1);
    fix_exp(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (invalid_Event(E2))
        return -99;
    fix_hp(HP1);
    fix_exp(EXP1);
    fix_money(M1);
    double P_1 = Probality(EXP1);
    if (E2 % 2 == 0)
    {
        if (M1 != 0)
        {
            stage_1(HP1, EXP1, M1);
            if (M1 != 0)
            {
                stage_2(HP1, EXP1, M1);
                if (M1 != 0)
                {
                    stage_3(HP1, EXP1, M1);
                }
            }
        }
    }
    else
    {
        if (M1 != 0)
        {
            int m = 0;
            int half = (float)M1 / 2;
            do
            {
                stage_1(HP1, EXP1, M1, m);
                if (m > half)
                    break;
                else
                {
                    stage_2(HP1, EXP1, M1, m);
                    if (m > half)
                        break;
                    else
                    {
                        stage_3(HP1, EXP1, M1, m);
                        if (m > half)
                            break;
                    }
                }
            } while (m <= half);
        }
    }
    HP1 = ceil_1(HP1 - 0.17 * (double)HP1);
    EXP1 = ceil_1(EXP1 + 0.17 * (double)EXP1);
    fix_exp(EXP1);
    fix_hp(HP1);
    double P_2 = Probality(EXP1);
    if (E2 >= 10)
    {
        E2 = (E2 / 10 + E2 % 10) % 10;
    }
    const int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P_3 = (float)P[E2] / 100;

    if ((P_1 == 1) && (P_2 == 1) && (P_3 == 1))
    {
        EXP1 = ceil_1(EXP1 - 0.25 * (double)EXP1);
    }
    else
    {
        double P_average = (P_1 + P_2 + P_3) / 3;
        if (P_average < 0.5)
        {
            HP1 = ceil_1(HP1 - 0.15 * (double)HP1);
            EXP1 = ceil_1(EXP1 + 0.15 * (double)EXP1);
        }
        else
        {
            HP1 = ceil_1(HP1 - 0.1 * (double)HP1);
            EXP1 = ceil_1(EXP1 + 0.2 * (double)EXP1);
        }
    }
    fix_exp(EXP1);
    fix_hp(HP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (invalid_Event(E3))
        return -99;
    fix_hp(HP1);
    fix_hp(HP2);
    fix_exp(EXP1);
    fix_exp(EXP2);
    int trace_taxi[10][10];
    int i_row = 0;
    int j_col = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            trace_taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (trace_taxi[i][j] > E3 * 2)
                i_row++;
            if (trace_taxi[i][j] < -E3)
                j_col++;
        }
    }
    one_Digit(i_row);
    one_Digit(j_col);
    int shwat_point = abs(maxDiagnose(trace_taxi, i_row, j_col));
    if (abs(trace_taxi[i_row][j_col]) > shwat_point)
    {
        HP1 = ceil_1(HP1 - 0.1 * (double)HP1);
        HP2 = ceil_1(HP2 - 0.1 * (double)HP2);
        EXP1 = ceil_1(EXP1 - 0.12 * (double)EXP1);
        EXP2 = ceil_1(EXP2 - 0.12 * (double)EXP2);
    }
    else
    {
        HP1 = ceil_1(HP1 + 0.1 * (double)HP1);
        HP2 = ceil_1(HP2 + 0.1 * (double)HP2);
        EXP1 = ceil_1(EXP1 + 0.12 * (double)EXP1);
        EXP2 = ceil_1(EXP2 + 0.12 * (double)EXP2);
    }
    fix_hp(HP1);
    fix_hp(HP2);
    fix_exp(EXP1);
    fix_exp(EXP2);

    if (abs(trace_taxi[i_row][j_col]) > shwat_point)
        return trace_taxi[i_row][j_col];
    else
        return shwat_point;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    string pwds = s;
    int size_s = strlen(s);
    string se;
    int i = 0;
    while (email[i] != '@')
    {
        se += email[i];
        i++;
    }
    if (size_s < 8)
        return -1;
    else
    {
        if (size_s > 20)
            return -2;
        else
        {
            for (int i = 0; i < size_s; i++)
            {
                if (pwds.substr(i, se.size()) == se)
                {
                    return -(300 + i);
                }
            }
            for (int i = 0; i < size_s -2; i++)
            {
                if (s[i] == s[i + 1] && s[i] == s[i+2])
                {
                    return -(400 + i);
                }
            }
            bool flag = false;
            for (int i = 0; i < size_s; i++)
            {
                if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                return -5;
            for (int i = 0; i < size_s; i++)
            {
                if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))
                    return i;
            }
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int id;
    int max = -1;
    int max_len = -1;
    int frequent[num_pwds];

    for (int i = 0; i < num_pwds; i++)
    {
        frequent[i] = 0; 
        for (int j = i + 1; j < num_pwds ; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) 
            {
                frequent[i]++;
            }
        }
        if (frequent[i] > max) 
            max = frequent[i];
    }

    for (int i = 0; i < num_pwds; i++)
    {
        if (frequent[i] == max)
        {
            int n_size = strlen(arr_pwds[i]);
            if (n_size > max_len)
            {
                id = i;
                max_len = n_size;
            }
        }
    }
    return id;
}
