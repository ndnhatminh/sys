#include "study_in_pink1.h"

#define ceil(val) ceil(float(val))

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

// check Everything
int check(char option, int val)
{
    switch (option)
    {
    case 'h': // hp
        if (val < 0)
            val = 0;
        else if (val > 666)
            val = 666;
        break;
    case 'e': // exp
        if (val < 0)
            val = 0;
        else if (val > 600)
            val = 600;
        break;
    case 'm': // money
        if (val < 0)
            val = 0;
        else if (val > 3000)
            val = 3000;
        break;
    default:
        break;
    }
    return val;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    exp1 = check('e', exp1);
    exp2 = check('e', exp2);
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
        if (int(D) % 2 == 0)
            exp1 = ceil(exp1 + D / 200.0);
        else
            exp1 = ceil(exp1 - D / 100.0);
    }
    else if (e1 >= 4 && e1 <= 99)
    {
        if (e1 <= 19)
            exp2 = ceil(exp2 + e1 / 4.0 + 19); // tt1
        else if (e1 <= 49)
            exp2 = ceil(exp2 + e1 / 9.0 + 21); // tt2
        else if (e1 <= 65)
            exp2 = ceil(exp2 + e1 / 16.0 + 17); // tt3
        else if (e1 <= 79)
        {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);
            if (exp2 > 200)
                exp2 = ceil(exp2 + e1 / 9.0 + 21);
        }
        else if (e1 <= 99)
        {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);
            exp2 = ceil(exp2 + e1 / 9.0 + 21);
            if (exp2 > 400)
            {
                exp2 = ceil(exp2 + e1 / 16.0 + 17);
                exp2 = ceil(exp2 * 1.15);
            }
        }
        exp1 -= e1;
    }
    else
        return -99;
    exp1 = check('e', exp1);
    exp2 = check('e', exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    HP1 = check('h', HP1);
    EXP1 = check('e', EXP1);
    M1 = check('m', M1);
    if (E2 < 0 || E2 > 99)
        return -99;

    double P1, P2, P3;

    // DUONG SO 1:
    int S = sqrt(double(EXP1));
    if (((S + 1) * (S + 1) - EXP1) > (EXP1 - S * S))
        P1 = 1;
    else
    {
        S = (S + 1) * (S + 1);
        P1 = (double(EXP1) / S + 80) / 123.0;
    }

    // DUONG SO 2:
    if (E2 % 2 == 1)
    {
        double limM1 = M1 * 0.5, payM1 = 0;
        while (M1 != 0)
        {
            // Hanh dong 1
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 * 1.3);
                payM1 += 150;
                M1 -= 150;
            }
            else
            {
                HP1 = ceil(HP1 * 1.1);
                payM1 += 70;
                M1 -= 70;
            }
            HP1 = check('h', HP1);
            M1 = check('m', M1);
            if (payM1 > limM1 || M1 == 0)
                break;

            // Hanh dong 2
            if (EXP1 < 400)
            {
                payM1 += 200;
                M1 -= 200;
            }
            else
            {
                payM1 += 120;
                M1 -= 120;
            }
            EXP1 = ceil(EXP1 * 1.13);
            EXP1 = check('e', EXP1);
            M1 = check('m', M1);
            if (payM1 > limM1 || M1 == 0)
                break;

            // Hanh dong 3
            if (EXP1 < 300)
            {
                payM1 += 100;
                M1 -= 100;
            }
            else
            {
                payM1 += 120;
                M1 -= 120;
            }
            EXP1 = ceil(EXP1 * 0.9);
            EXP1 = check('e', EXP1);
            M1 = check('m', M1);
            if (payM1 > limM1)
                break;
        }
    }
    else if (M1 != 0)
    {
        // Hanh dong 1
        if (HP1 < 200)
        {
            HP1 = ceil(HP1 * 1.3);
            M1 -= 150;
        }
        else
        {
            HP1 = ceil(HP1 * 1.1);
            M1 -= 70;
        }
        HP1 = check('h', HP1);
        M1 = check('m', M1);
        if (M1 != 0)
        {
            // Hanh dong 2
            if (EXP1 < 400)
                M1 -= 200;
            else
                M1 -= 120;
            EXP1 = ceil(EXP1 * 1.13);
            EXP1 = check('e', EXP1);
            M1 = check('m', M1);
            if (M1 != 0)
            {
                // Hanh dong 3
                if (EXP1 < 300)
                    M1 -= 100;
                else
                    M1 -= 120;
                EXP1 = ceil(EXP1 * 0.9);
                EXP1 = check('e', EXP1);
                M1 = check('m', M1);
            }
        }
    }
    HP1 = ceil(HP1 * 0.83);
    EXP1 = ceil(EXP1 * 1.17);
    HP1 = check('h', HP1);
    EXP1 = check('e', EXP1);

    S = sqrt(double(EXP1));
    if (abs((S + 1) * (S + 1) - EXP1) > abs(EXP1 - S * S))
        P2 = 1;
    else
    {
        S = (S + 1) * (S + 1);
        P2 = (double(EXP1) / S + 80) / 123.0;
    }
    // DUONG SO 3:
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 / 10 == 0)
        P3 = P[E2] / 100.0;
    else
    {
        int sum = E2 / 10 + E2 % 10;
        P3 = P[sum % 10] / 100.0;
    }

    // CHECK POSSIBILITIES
    if (P1 == 1 && P2 == P1 && P3 == P2)
    {
        EXP1 = ceil(EXP1 * 0.75);
    }
    else
    {
        double Pfinal = (P1 + P2 + P3) / 3;
        if (Pfinal < 0.5)
        {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        }
        else
        {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
        }
    }
    HP1 = check('h', HP1);
    EXP1 = check('e', EXP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    HP1 = check('h', HP1);
    EXP1 = check('e', EXP1);
    HP2 = check('h', HP2);
    EXP2 = check('e', EXP2);
    if (E3 < 0 || E3 > 99)
        return -99;
    int matrix[10][10];
    int iMeet = 0, jMeet = 0, PtHol, PtTaxi;
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (matrix[i][j] > (E3 * 2))
            {
                iMeet++;
            }
            if (matrix[i][j] < -E3)
            {
                jMeet++;
            }
        }
    }
    while (iMeet / 10)
        iMeet = iMeet % 10 + iMeet / 10;
    while (jMeet / 10)
        jMeet = jMeet % 10 + jMeet / 10;
    PtTaxi = matrix[iMeet][jMeet];
    PtHol = matrix[iMeet][jMeet];

    // Find Holmes Point
    {
        for (int i = iMeet + 1, j = jMeet + 1; (i < 10 && j < 10);)
        {
            if (matrix[i][j] > PtHol)
                PtHol = matrix[i][j];
            i++;
            j++;
        }
        for (int i = iMeet - 1, j = jMeet - 1; (i >= 0 && j >= 0);)
        {
            if (matrix[i][j] > PtHol)
                PtHol = matrix[i][j];
            i--;
            j--;
        }
        for (int i = iMeet + 1, j = jMeet - 1; (i < 10 && j >= 0);)
        {
            if (matrix[i][j] > PtHol)
                PtHol = matrix[i][j];
            i++;
            j--;
        }
        for (int i = iMeet - 1, j = jMeet + 1; (i >= 0 && j < 10);)
        {
            if (matrix[i][j] > PtHol)
                PtHol = matrix[i][j];
            i--;
            j++;
        }
    }
    PtHol = abs(PtHol);
    if (PtHol < abs(PtTaxi))
    {
        EXP1 = ceil(EXP1 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        EXP2 = ceil(EXP2 * 0.88);
        HP2 = ceil(HP2 * 0.9);
    }
    else
    {
        EXP1 = ceil(EXP1 * 1.12);
        HP1 = ceil(HP1 * 1.1);
        EXP2 = ceil(EXP2 * 1.12);
        HP2 = ceil(HP2 * 1.1);
    }
    EXP1 = check('e', EXP1);
    HP1 = check('h', HP1);
    EXP2 = check('e', EXP2);
    HP2 = check('h', HP2);
    if (PtHol < abs(PtTaxi))
        return PtTaxi;
    else
        return PtHol;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    char speChar[] = {'@', '#', '%', '$', '!'};
    string s1 = s, email1 = email;
    string se;
    int pos = email1.find_first_of('@');
    se = email1.substr(0, pos);

    if (s1.size() < 8)
        return -1;
    if (s1.size() > 20)
        return -2;
    size_t sei = s1.find(se);
    if (sei != string::npos)
        return -(300 + sei);
    for (int i = 1; i < s1.size() - 1; i++)
    {
        if (s1[i] == s1[i - 1] && s1[i] == s1[i + 1])
        {
            int sci = i - 1;
            return -(400 + sci);
        }
    }
    bool noSpeChar = true, violated = false;
    int vioPos = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        for (auto &&ch : speChar)
        {
            if (s1[i] == ch)
                noSpeChar = false;
        }
        int ch = int(s1[i]);
        if ((ch < 48 || ch > 57) && (ch < 64 || ch > 90) && (ch < 97 || ch > 122) && ch != 33 && (ch < 35 || ch > 37) && !violated)
        {
            violated = true;
            vioPos = i;
        }
    }
    if (noSpeChar)
        return -5;
    if (violated)
        return vioPos;
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    string cor_pass = "";

    int cor_pass_pos = 0, maxCount = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        int count = 1;
        for (int j = i + 1; j < num_pwds; j++)
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
                count++;
        if (count > maxCount)
            maxCount = count;
    }
    for (int i = 0; i < num_pwds; i++)
    {
        int count = 1;
        for (int j = i + 1; j < num_pwds; j++)
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
                count++;
        if (count == maxCount && strlen(arr_pwds[i]) > cor_pass.size())
        {
            cor_pass = arr_pwds[i];
            cor_pass_pos = i;
        }
    }

    return cor_pass_pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////