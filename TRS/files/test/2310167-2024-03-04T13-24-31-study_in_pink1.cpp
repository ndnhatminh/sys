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

// My function
int roundUP(float a)
{
    if (int(a) != a)
        return int(a) + 1;
    else
        return a;
}

int roundHP(float a)
{
    if (a > 666 || a < 0)
    {
        if (a > 666)
            return 666;
        else
            return 0;
    }
    else
        return roundUP(a);
}

int roundEXP(float a)
{
    if (a > 600 || a < 0)
    {
        if (a > 600)
            return 600;
        else
            return 0;
    }
    else
        return roundUP(a);
}

int roundM(float a)
{
    if (a > 3000 || a < 0)
    {
        if (a > 3000)
            return 3000;
        else
            return 0;
    }
    else
        return roundUP(a);
}

bool checkE(int a)
{
    if (a < 0 || a > 99)
        return false;
    else
        return true;
}

float P(int a) // task2
{
    int s;
    if (a - pow(int(sqrt(a)), 2) < pow(int(sqrt(a)) + 1, 2) - a)
        return 1;
    else
    {
        s = pow(int(sqrt(a)) + 1, 2);
        return (float(a) / s + 80) / 123;
    }
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    if (!checkE(e1))
        return -99;
    else
    {
        exp1 = roundEXP(exp1);
        exp2 = roundEXP(exp2);
        if (e1 <= 3)
        {
            if (e1 == 0)
                exp2 += 29;
            else if (e1 == 1)
                exp2 += 45;
            else if (e1 == 2)
                exp2 += 75;
            else
                exp2 = exp2 + 29 + 45 + 75;
            exp2 = roundEXP(exp2);

            int d;
            d = e1 * 3 + exp1 * 7;
            if (d % 2 == 0)
                exp1 = roundEXP(exp1 + float(d) / 200);
            else
                exp1 = roundEXP(exp1 - float(d) / 100);
        }
        else
        {
            if (e1 <= 19)
                exp2 = roundEXP(exp2 + float(e1) / 4 + 19);
            else if (e1 <= 49)
                exp2 = roundEXP(exp2 + float(e1) / 9 + 21);
            else if (e1 <= 65)
                exp2 = roundEXP(exp2 + float(e1) / 16 + 17);
            else if (e1 <= 79)
            {
                exp2 = roundEXP(exp2 + float(e1) / 4 + 19);
                if (exp2 > 200)
                    exp2 = roundEXP(exp2 + float(e1) / 9 + 21);
            }
            else
            {
                exp2 = roundEXP(roundEXP(exp2 + float(e1) / 4 + 19) + float(e1) / 9 + 21);
                if (exp2 > 400)
                {
                    exp2 = roundEXP(exp2 + float(e1) / 16 + 17);
                    exp2 = roundEXP(exp2 * 1.15);
                }
            }
            exp1 = roundEXP(exp1 - e1);
        }
        return exp1 + exp2;
    }
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (!checkE(E2))
        return -99;
    else
    {
        EXP1 = roundEXP(EXP1);
        HP1 = roundHP(HP1);
        M1 = roundM(M1);
        int n = M1;
        // Road 1
        float p1 = P(EXP1);
        // Road 2
        if (M1 == 0) // No money
        {
            HP1 = roundHP(HP1 * 0.83);
            EXP1 = roundEXP(EXP1 * 1.17);
        }
        else
        {
            if (E2 % 2 != 0)
            {
                int pay = 0;
                while (pay <= 0.5 * n)
                {
                    // Event 1
                    if (HP1 < 200)
                    {
                        HP1 = roundHP(HP1 * 1.3);
                        pay += 150;
                        M1 = roundM(M1 - 150);
                        if (pay > 0.5 * n)
                            break;
                    }
                    else
                    {
                        HP1 = roundHP(HP1 * 1.1);
                        pay += 70;
                        M1 = roundM(M1 - 70);
                        if (pay > 0.5 * n)
                            break;
                    }
                    // Event 2
                    if (EXP1 < 400)
                    {
                        pay += 200;
                        EXP1 = roundEXP(EXP1 * 1.13);
                        M1 = roundM(M1 - 200);
                        if (pay > 0.5 * n)
                            break;
                    }
                    else
                    {
                        pay += 120;
                        EXP1 = roundEXP(EXP1 * 1.13);
                        M1 = roundM(M1 - 120);
                        if (pay > 0.5 * n)
                            break;
                    }
                    // Event 3
                    if (EXP1 < 300)
                    {
                        pay += 100;
                        EXP1 = roundEXP(EXP1 * 0.9);
                        M1 = roundM(M1 - 100);
                        if (pay > 0.5 * n)
                            break;
                    }
                    else
                    {
                        pay += 120;
                        EXP1 = roundEXP(EXP1 * 0.9);
                        M1 = roundM(M1 - 120);
                        if (pay > 0.5 * n)
                            break;
                    }
                }
                HP1 = roundHP(HP1 * 0.83);
                EXP1 = roundEXP(EXP1 * 1.17);
            }
            else
            {
                int count = 0;
                while (count == 0)
                {
                    // Event 1
                    if (HP1 < 200)
                    {
                        HP1 = roundHP(HP1 * 1.3);
                        M1 = roundM(M1 - 150);
                        if (M1 == 0)
                            break;
                    }
                    else
                    {
                        HP1 = roundHP(HP1 * 1.1);
                        M1 = roundM(M1 - 70);
                        if (M1 == 0)
                            break;
                    }
                    // Event 2
                    if (EXP1 < 400)
                    {
                        EXP1 = roundEXP(EXP1 * 1.13);
                        M1 = roundM(M1 - 200);
                        if (M1 == 0)
                            break;
                    }
                    else
                    {
                        EXP1 = roundEXP(EXP1 * 1.13);
                        M1 = roundM(M1 - 120);
                        if (M1 == 0)
                            break;
                    }
                    // Event 3
                    if (EXP1 < 300)
                    {
                        EXP1 = roundEXP(EXP1 * 0.9);
                        M1 = roundM(M1 - 100);
                        if (M1 == 0)
                            break;
                    }
                    else
                    {
                        EXP1 = roundEXP(EXP1 * 0.9);
                        M1 = roundM(M1 - 120);
                        if (M1 == 0)
                            break;
                    }
                    count++;
                }
                HP1 = roundHP(HP1 * 0.83);
                EXP1 = roundEXP(EXP1 * 1.17);
            }
        }
        float p2 = P(EXP1);
        // Road 3
        const int p[10] = {
            32,
            47,
            28,
            79,
            100,
            50,
            22,
            83,
            64,
            11};
        int i;
        if ((float)E2 / 10 < 1)
            i = E2;
        else
            i = (E2 / 10 + E2 % 10) % 10;
        float p3 = float(p[i]) / 100;
        if (p1 == 1 && p2 == 1 && p[i] == 100)
            EXP1 = roundEXP(EXP1 * 0.75);
        else
        {
            if ((p1 + p2 + p3) / 3 < 0.5)
            {
                HP1 = roundHP(HP1 * 0.85);
                EXP1 = roundEXP(EXP1 * 1.15);
            }
            else
            {
                HP1 = roundHP(HP1 * 0.9);
                EXP1 = roundEXP(EXP1 * 1.2);
            }
        }
        return HP1 + EXP1 + M1;
    }
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (!checkE(E3))
        return -99;
    else
    {
        HP1 = roundHP(HP1);
        EXP1 = roundEXP(EXP1);
        HP2 = roundHP(HP2);
        EXP2 = roundEXP(EXP2);
        int marktaxi[10][10];
        int imeet = 0, ymeet = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                marktaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                if (marktaxi[i][j] > E3 * 2)
                    imeet++;
                if (marktaxi[i][j] < -E3)
                    ymeet++;
            }
        }
        // Tọa độ gặp nhau
        while (float(imeet) / 10 >= 1)
            imeet = imeet / 10 + imeet % 10;
        while (float(ymeet) / 10 >= 1)
            ymeet = ymeet / 10 + ymeet % 10;
        // Max of cross
        int maxsw = marktaxi[imeet][ymeet];
        int i = imeet + 1, j = ymeet + 1;
        while (i < 10 && j < 10)
        {
            if (maxsw < marktaxi[i][j])
                maxsw = marktaxi[i][j];
            i++;
            j++;
        }
        i = imeet - 1;
        j = ymeet - 1;
        while (i >= 0 && j >= 0)
        {
            if (maxsw < marktaxi[i][j])
                maxsw = marktaxi[i][j];
            i--;
            j--;
        }
        i = imeet - 1;
        j = ymeet + 1;
        while (i >= 0 && j < 10)
        {
            if (maxsw < marktaxi[i][j])
                maxsw = marktaxi[i][j];
            i--;
            j++;
        }
        i = imeet + 1;
        j = ymeet - 1;
        while (i < 10 && j >= 0)
        {
            if (maxsw < marktaxi[i][j])
                maxsw = marktaxi[i][j];
            i++;
            j--;
        }
        maxsw = abs(maxsw);
        // End
        if (abs(marktaxi[imeet][ymeet]) > maxsw)
        {
            EXP1 = roundEXP(EXP1 * 0.88);
            HP1 = roundHP(HP1 * 0.9);
            EXP2 = roundEXP(EXP2 * 0.88);
            HP2 = roundHP(HP2 * 0.9);
            return marktaxi[imeet][ymeet];
        }
        else
        {
            EXP1 = roundEXP(EXP1 * 1.12);
            HP1 = roundHP(HP1 * 1.1);
            EXP2 = roundEXP(EXP2 * 1.12);
            HP2 = roundHP(HP2 * 1.1);
            return maxsw;
        }
    }
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    string s1(s);
    string email1(email);
    string se = email1.substr(0, email1.find('@'));

    if (s1.length() < 8 || s1.length() > 20)
    {
        if (s1.length() < 8)
            return -1;
        else
            return -2;
    }

    int index = s1.find(se);
    if (s1.find(se) != string::npos)
        return -(300 + index);

    int count = 0;
    for (int i = 1; i < s1.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            count++;
            if (count == 2)
                return -(400 + (i - 2));
        }
        else
            count = 0;
    }

    if (s1.find('@') == string::npos && s1.find('#') == string::npos && s1.find('%') == string::npos && s1.find('$') == string::npos && s1.find('!') == string::npos)
        return -5;

    for (int i = 0; i < s1.length(); i++)
    {
        if ((s1[i] >= '0' && s1[i] <= '9') || (s1[i] >= 'A' && s1[i] <= 'Z') ||
            (s1[i] >= 'a' && s1[i] <= 'z') || s1[i] == '!' || s1[i] == '#' || s1[i] == '$' || s1[i] == '%' || s1[i] == '@')
            continue;
        else
            return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    const int n = num_pwds;
    int count = 0;
    int imax = 0;
    int max = 0;
    string s[n];
    for (int i = 0; i < n; i++)
        s[i] = arr_pwds[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
            if (s[j] == s[i])
                count++;
        if (count >= max)
        {
            if (count > max)
            {
                max = count;
                imax = i;
            }
            else if (s[i].length() > s[imax].length())
                imax = i;
        }
        count = 0;
    }
    return imax;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////