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

void check(int &HP, int &EXP, int &M)
{
    if (HP < 0)
        HP = 0;
    else if (HP > 666)
        HP = 666;

    if (EXP < 0)
        EXP = 0;
    else if (EXP > 600)
        EXP = 600;

    if (M < 0)
        M = 0;
    else if (M > 3000)
        M = 3000;
}
void check_Task3(int &HP, int &EXP)
{
    if (HP < 0)
        HP = 0;
    else if (HP > 666)
        HP = 666;

    if (EXP < 0)
        EXP = 0;
    else if (EXP > 600)
        EXP = 600;
}
void Way2_Task2(int &HP1, int &EXP1, int &M1, int condition, bool &flag)
{
    if (HP1 < 200)
    {
        HP1 = (int)(1.3 * HP1 + 0.999);
        M1 -= 150;
    }
    else
    {
        HP1 = (int)(1.1 * HP1 + 0.999);
        M1 -= 70;
    }
    check(HP1, EXP1, M1);
    if (M1 < condition || M1 == 0)
    {
        flag = false;
        return;
    }

    if (EXP1 < 400)
        M1 -= 200;
    else
        M1 -= 120;
    EXP1 = (int)(1.13 * EXP1 + 0.999);
    check(HP1, EXP1, M1);
    if (M1 < condition || M1 == 0)
    {
        flag = false;
        return;
    }

    if (EXP1 < 300)
        M1 -= 100;
    else
        M1 -= 120;
    EXP1 = (int)(0.9 * EXP1 + 0.999);
    check(HP1, EXP1, M1);
    if (M1 < condition || M1 == 0)
    {
        flag = false;
        return;
    }
}
double compute_Probality(int EXP1)
{
    double SquareRoot_EXP1 = sqrt(EXP1);
    double P1;
    int S;
    int temp = (int)(sqrt(EXP1));
    if (temp == SquareRoot_EXP1)
        S = EXP1;
    else
    {
        if ((EXP1 - temp * temp) < ((temp + 1) * (temp + 1) - EXP1))
            S = temp * temp;
        else
            S = (temp + 1) * (temp + 1);
    }
    if (EXP1 >= S)
        P1 = 1;
    else
        P1 = ((EXP1 * 1.0 / S) + 80) / 123;
    return P1;
}
void compute_CoorMeet(int &i, int &j)
{
    if (i < 10 && j < 10)
        return;
    if (i >= 10)
    {
        int temp = 0;
        while (i)
        {
            temp += i % 10;
            i /= 10;
        }
        i = temp;
    }
    if (j >= 10)
    {
        int temp = 0;
        while (j)
        {
            temp += j % 10;
            j /= 10;
        }
        j = temp;
    }
    compute_CoorMeet(i, j);
    return;
}
int maxDiaLineLeft(const int arr[10][10], int i_meet, int j_meet)
{
    int i_temp = i_meet;
    int j_temp = j_meet;
    int res = INT_MIN;
    if (i_meet <= j_meet)
        return arr[i_meet][j_meet];
    while (i_temp <= 9 && j_temp <= 9)
    {
        res = max(res, arr[i_temp++][j_temp++]);
    }
    while (i_meet >= 0 && j_meet >= 0)
    {
        res = max(res, arr[i_meet--][j_meet--]);
    }
    return res;
}
int maxDiaLineRight(const int arr[10][10], int i_meet, int j_meet)
{
    int res = INT_MIN;
    int i_temp = i_meet;
    int j_temp = j_meet;
    while (i_temp <= 9 && j_temp >= 0)
    {
        res = max(res, arr[i_temp++][j_temp--]);
    }
    while (i_meet >= 0 && j_meet <= 9)
    {
        res = max(res, arr[i_meet--][j_meet++]);
    }
    return res;
}
bool checkPwd(const char *s, const char *t)
{
    if (strlen(s) != strlen(t))
        return false;
    int i = 0;
    while (i < strlen(s))
    {
        if (s[i] != t[i])
            return false;
        ++i;
    }
    return true;
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
    if (exp1 < 0)
        exp1 = 0;
    else if (exp1 > 600)
        exp1 = 600;

    if (exp2 < 0)
        exp2 = 0;
    else if (exp2 > 600)
        exp2 = 600;
    if (e1 < 4)
    {
        if (e1 == 0)
            exp2 += 29;
        else if (e1 == 1)
            exp2 += 45;
        else if (e1 == 2)
            exp2 += 75;
        else
            exp2 += 149;
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 += ceil(D / 200.0);
        }
        else
        {
            if (D % 100 == 0)
                exp1 -= D / 100;
            else
                exp1 -= ceil(D / 100.0) - 1;
        }
    }

    else
    {
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 += 19 + ceil(e1 / 4.0);
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 += ceil(e1 / 9.0) + 21;
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 += ceil(e1 / 16.0) + 17;
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 += 19 + ceil(e1 / 4.0);

            if (exp2 > 200)
            {
                exp2 += ceil(e1 / 9.0) + 21;
            }
        }
        else
        {
            exp2 += 19 + ceil(e1 / 4.0);
            exp2 += ceil(e1 / 9.0) + 21;

            if (exp2 > 400)
            {
                exp2 += ceil(e1 / 16.0) + 17;
                exp2 += ceil(0.15 * exp2);
            }
        }
        exp1 -= e1;
    }
    if (exp1 < 0)
        exp1 = 0;
    else if (exp1 > 600)
        exp1 = 600;

    if (exp2 < 0)
        exp2 = 0;
    else if (exp2 > 600)
        exp2 = 600;
    return exp1 + exp2;
}
// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    // WAY 01
    if (E2 < 0 || E2 > 99)
        return -99;
    check(HP1, EXP1, M1);
    double MCondi = 0.5 * M1;
    double P1 = compute_Probality(EXP1);
    bool flag = true;

    // WAY 02
    double P2;
    if(M1>0)
    {
        if (E2 % 2 != 0)
    {
        while (flag && M1 >= MCondi)
            Way2_Task2(HP1, EXP1, M1, MCondi, flag);
    }
    else
        Way2_Task2(HP1, EXP1, M1, 0, flag);
    HP1 = (int)(0.83 * HP1 + 0.999);
    EXP1 = (int)(1.17 * EXP1 + 0.999);
    check(HP1, EXP1, M1);
    }

    P2 = compute_Probality(EXP1);

    // WAY03
    double P3;
    int i;
    if (E2 < 10)
        i = E2;
    else
    {
        int temp = 0;
        while (E2)
        {
            temp += E2 % 10;
            E2 /= 10;
        }
        i = temp % 10;
    }
    double Array_Probality[] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    P3 = Array_Probality[i];

    double P;
    if (P1 == 1 && P2 == 1 & P3 == 1)
    {
        EXP1 = (int)(0.75 * EXP1 + 0.999);
    }
    else
    {
        P = (P1 + P2 + P3) / 3;
        if (P < 0.5)
        {
            HP1 = (int)(0.85 * HP1 + 0.999);
            EXP1 = (int)(1.15 * EXP1 + 0.999);
        }
        else
        {
            HP1 = (int)(0.9 * HP1 + 0.999);
            EXP1 = (int)(1.2 * EXP1 + 0.999);
        }
        check(HP1, EXP1, M1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;
    check_Task3(HP1, EXP1);
    check_Task3(HP2, EXP2);
    int Score_taxi[10][10] = {};
    int i_meet = 0, j_meet = 0;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            Score_taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (Score_taxi[i][j] > (2 * E3))
                ++i_meet;
            if (Score_taxi[i][j] < -E3)
                ++j_meet;
        }
    }
    compute_CoorMeet(i_meet, j_meet);
    int Score_human = max(maxDiaLineLeft(Score_taxi, i_meet, j_meet), maxDiaLineRight(Score_taxi, i_meet, j_meet));
    if (abs(Score_taxi[i_meet][j_meet]) > Score_human)
    {
        EXP1 = (int)(0.88 * EXP1 + 0.999);
        HP1 = (int)(0.9 * HP1 + 0.999);
        EXP2 = (int)(0.88 * EXP2 + 0.999);
        HP2 = (int)(0.9 * HP2 + 0.999);
        return Score_taxi[i_meet][j_meet];
    }
    else
    {
        EXP1 = (int)(1.12 * EXP1 + 0.999);
        HP1 = (int)(1.1 * HP1 + 0.999);
        EXP2 = (int)(1.12 * EXP2 + 0.999);
        HP2 = (int)(1.1 * HP2 + 0.999);
        check_Task3(HP1, EXP1);
        check_Task3(HP2, EXP2);
        return Score_human;
    }
    return -1;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    if (strlen(s) < 8)
        return -1;
    else if (strlen(s) > 20)
        return -2;
    string se = "";
    for (int i = 0; i < strlen(email); ++i)
    {
        if (email[i] == '@')
            break;
        se += email[i];
    }
    int i = 0;
    bool flag = false;
    if(se.length()==0) return -300;
    if (strlen(s) >= se.length())
    {
        while (i < strlen(s))
        {
            if (s[i] == se[0])
            {
                int idx=i;
                flag = true;
                if ((strlen(s) - i) < se.length())
                {
                    flag = false;
                    break;
                }
                else
                {
                    ++i;
                    int j = 1;
                    while (j < se.length())
                    {
                        if (s[i] == se[j])
                        {
                            ++i;
                            ++j;
                        }
                        else
                        {
                            i=idx;
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if (flag)
                break;
            ++i;
        }
        if (flag)
            return -(300 + i - se.length());
    }
    i = 1;
    int cnt_Special_Char = 0;
    while (i < strlen(s))
    {
        if (s[i] == s[i - 1])
        {
            if (i + 1 < strlen(s) && s[i + 1] == s[i])
                return -(400 + i - 1);
        }
        ++i;
    }
    i = 0;
    int idx=0;
    bool flag_diffcase=0;
    while (i < strlen(s))
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            cnt_Special_Char++;
        else if (!isalnum(s[i]) && !flag_diffcase)
        {
            flag_diffcase=1;
            idx=i;
        }
        ++i;
    }
    if (cnt_Special_Char == 0)
        return -5;
    if(flag_diffcase)
        return idx;
    return -10;
}
// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int maxFreq = 0, maxLen = 0, maxIndex = 0;
    for (int i = 0; i < num_pwds; ++i)
    {
        int freq = 1, len = strlen(arr_pwds[i]);
        for (int j = i + 1; j < num_pwds; ++j)
            if (checkPwd(arr_pwds[i], arr_pwds[j]))
                ++freq;
        if (freq > maxFreq || (freq == maxFreq && len > maxLen))
        {
            maxFreq = freq;
            maxLen = len;
            maxIndex = i;
        }
    }
    return maxIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////