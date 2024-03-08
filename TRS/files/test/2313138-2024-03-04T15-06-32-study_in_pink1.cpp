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

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    if (0 <= e1 && e1 <= 3) // Mission 1: case 1
    {
        if (exp2 > 600)
        {
            exp2 = 600;
        }
        else if (exp2 < 0)
        {
            exp2 = 0;
        }
        if (exp1 > 600)
        {
            exp1 = 600;
        }
        else if (exp1 < 0)
        {
            exp1 = 0;
        }
        switch (e1)
        {
        case 0:
            exp2 += 29;
            break;
        case 1:
            exp2 += 45;
            break;
        case 2:
            exp2 += 75;
            break;
        case 3:
            exp2 = exp2 + 29 + 45 + 75;
            break;
        }
        if (exp2 > 600)
        {
            exp2 = 600;
        }
        else if (exp2 < 0)
        {
            exp2 = 0;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 = ceil(exp1 + D * 1.0 / 200);
        }
        else
        {
            exp1 = ceil(exp1 - D * 1.0 / 100);
        }
        if (exp1 > 600)
        {
            exp1 = 600;
        }
        else if (exp1 < 0)
        {
            exp1 = 0;
        }
        return exp1 + exp2;
    }
    else if (4 <= e1 && e1 <= 99) // Mission 1:case 2
    {
        if (exp2 > 600)
        {
            exp2 = 600;
        }
        else if (exp2 < 0)
        {
            exp2 = 0;
        }
        if (exp1 > 600)
        {
            exp1 = 600;
        }
        else if (exp1 < 0)
        {
            exp1 = 0;
        }
        if (4 <= e1 && e1 <= 19)
        {
            exp2 = ceil(exp2 + e1 * 1.0 / 4 + 19);
        }
        if (20 <= e1 && e1 <= 49)
        {
            exp2 = ceil(exp2 + e1 * 1.0 / 9 + 21);
        }
        if (50 <= e1 && e1 <= 65)
        {
            exp2 = ceil(exp2 + e1 * 1.0 / 16 + 17);
        }
        if (66 <= e1 && e1 <= 79)
        {
            exp2 = ceil(exp2 + e1 * 1.0 / 4 + 19);
            if (exp2 > 600)
            {
                exp2 = 600;
            }
            else if (exp2 < 0)
            {
                exp2 = 0;
            }
            if (exp2 > 200)
            {
                exp2 = ceil(exp2 + e1 * 1.0 / 9 + 21);
                if (exp2 > 600)
                {
                    exp2 = 600;
                }
                else if (exp2 < 0)
                {
                    exp2 = 0;
                }
            }
        }
        if (80 <= e1 && e1 <= 99)
        {
            exp2 = ceil(exp2 + e1 * 1.0 / 4 + 19);
            exp2 = ceil(exp2 + e1 * 1.0 / 9 + 21);
            if (exp2 > 600)
            {
                exp2 = 600;
            }
            else if (exp2 < 0)
            {
                exp2 = 0;
            }
            if (exp2 > 400)
            {
                exp2 = ceil(exp2 + e1 * 1.0 / 16 + 17);
                exp2 = ceil(exp2 * 115 / 100.0);
                if (exp2 > 600)
                {
                    exp2 = 600;
                }
                else if (exp2 < 0)
                {
                    exp2 = 0;
                }
            }
        }
        exp1 -= e1;
        if (exp1 > 600)
        {
            exp1 = 600;
        }
        else if (exp1 < 0)
        {
            exp1 = 0;
        }
        if (exp2 > 600)
        {
            exp2 = 600;
        }
        else if (exp2 < 0)
        {
            exp2 = 0;
        }
        return exp1 + exp2;
    }
    else
    {
        return -99;
    }
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (E2 > 99 || E2 < 0)
    {
        return -99;
    }
    else
    {
        if (HP1 > 666)
        {
            HP1 = 666;
        }
        else if (HP1 < 0)
        {
            HP1 = 0;
        }
        if (M1 > 3000)
        {
            M1 = 3000;
        }
        else if (M1 < 0)
        {
            M1 = 0;
        }
        if (EXP1 > 600)
        {
            EXP1 = 600;
        }
        else if (EXP1 < 0)
        {
            EXP1 = 0;
        }
        float P1, P2, P3;
        double x = sqrt(EXP1);
        int sqrtS1 = round(x);
        int S1 = sqrtS1 * sqrtS1;
        if (EXP1 >= S1)
        {
            P1 = 1;
        }
        else
        {
            P1 = (EXP1 * 1.0 / S1 + 80) / 123;
        }
        while (E2 % 2 == 0)
        {
            if (M1 == 0)
            {
                break;
            }
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 * 13 / 10.0);
                M1 -= 150;
                if (HP1 > 666)
                {
                    HP1 = 666;
                }
                else if (HP1 < 0)
                {
                    HP1 = 0;
                }
                if (M1 > 3000)
                {
                    M1 = 3000;
                }
                else if (M1 < 0)
                {
                    M1 = 0;
                }
            }
            else
            {
                HP1 = ceil(HP1 * 11 / 10.0);
                M1 -= 70;
                if (HP1 > 666)
                {
                    HP1 = 666;
                }
                else if (HP1 < 0)
                {
                    HP1 = 0;
                }
                if (M1 > 3000)
                {
                    M1 = 3000;
                }
                else if (M1 < 0)
                {
                    M1 = 0;
                }
            }
            if (M1 == 0)
            {
                break;
            }
            if (EXP1 < 400)
            {
                M1 -= 200;
                EXP1 = ceil(EXP1 * 113 / 100.0);
            }
            else
            {
                M1 -= 120;
                EXP1 = ceil(EXP1 * 113 / 100.0);
            }
            if (EXP1 > 600)
            {
                EXP1 = 600;
            }
            else if (EXP1 < 0)
            {
                EXP1 = 0;
            }
            if (M1 > 3000)
            {
                M1 = 3000;
            }
            else if (M1 < 0)
            {
                M1 = 0;
            }
            if (M1 == 0)
            {
                break;
            }
            if (EXP1 < 300)
            {
                M1 -= 100;
                EXP1 = ceil(EXP1 * 9 / 10.0);
            }
            else
            {
                M1 -= 120;
                EXP1 = ceil(EXP1 * 9 / 10.0);
            }
            if (EXP1 > 600)
            {
                EXP1 = 600;
            }
            else if (EXP1 < 0)
            {
                EXP1 = 0;
            }
            if (M1 > 3000)
            {
                M1 = 3000;
            }
            else if (M1 < 0)
            {
                M1 = 0;
            }
            break;
        }
        float Start = M1 * 1.0 / 2;
        int Spended = 0;
        while (E2 % 2 == 1)
        {
            if (M1 == 0)
            {
                break;
            }
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 * 13 / 10.0);
                M1 -= 150;
                Spended += 150;
            }
            else
            {
                HP1 = ceil(HP1 * 11 / 10.0);
                M1 -= 70;
                Spended += 70;
            }
            if (HP1 > 666)
            {
                HP1 = 666;
            }
            else if (HP1 < 0)
            {
                HP1 = 0;
            }
            if (M1 > 3000)
            {
                M1 = 3000;
            }
            else if (M1 < 0)
            {
                M1 = 0;
            }
            if (Spended > Start)
            {
                break;
            }
            if (EXP1 < 400)
            {
                M1 -= 200;
                Spended += 200;
                EXP1 = ceil(EXP1 * 113 / 100.0);
            }
            else
            {
                M1 -= 120;
                Spended += 120;
                EXP1 = ceil(EXP1 * 113 / 100.0);
            }
            if (M1 > 3000)
            {
                M1 = 3000;
            }
            else if (M1 < 0)
            {
                M1 = 0;
            }
            if (EXP1 > 600)
            {
                EXP1 = 600;
            }
            else if (EXP1 < 0)
            {
                EXP1 = 0;
            }
            if (Spended > Start)
            {
                break;
            }
            if (EXP1 < 300)
            {
                M1 -= 100;
                Spended += 100;
                EXP1 = ceil(EXP1 * 9 / 10.0);
            }
            else
            {
                M1 -= 120;
                Spended += 120;
                EXP1 = ceil(EXP1 * 9 / 10.0);
            }
            if (M1 > 3000)
            {
                M1 = 3000;
            }
            else if (M1 < 0)
            {
                M1 = 0;
            }
            if (EXP1 > 600)
            {
                EXP1 = 600;
            }
            if (Spended > Start)
            {
                break;
            }
        }
        EXP1 = ceil(EXP1 * 117 / 100.0);
        if (EXP1 > 600)
        {
            EXP1 = 600;
        }
        else if (EXP1 < 0)
        {
            EXP1 = 0;
        }
        HP1 = ceil(HP1 * 83 / 100.0);
        if (HP1 > 666)
        {
            HP1 = 666;
        }
        else if (HP1 < 0)
        {
            HP1 = 0;
        }
        double x2 = sqrt(EXP1);
        int sqrtS2 = round(x2);
        int S2 = sqrtS2 * sqrtS2;
        if (EXP1 >= S2)
        {
            P2 = 1;
        }
        else
        {
            P2 = (EXP1 * 1.0 / S2 + 80) / 123;
        }
        int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int i;
        if (E2 / 10 == 0)
        {
            i = E2 % 10;
        }
        else
        {
            int sum;
            sum = (E2 % 10) + (E2 / 10);
            i = sum % 10;
        }
        P3 = P[i] / 100.0;
        if (P1 == 1 && P2 == 1 && P3 == 1)
        {
            EXP1 = ceil(EXP1 * 75 / 100.0);
        }
        else
        {
            float avgP = (P1 + P2 + P3) / 3;
            if (avgP < 0.5)
            {
                EXP1 = ceil(EXP1 * 115 / 100.0);
                HP1 = ceil(HP1 * 85 / 100.0);
            }
            else
            {
                EXP1 = ceil(EXP1 * 12 / 10.0);
                HP1 = ceil(HP1 * 9 / 10.0);
            }
            if (HP1 > 666)
            {
                HP1 = 666;
            }
            else if (HP1 < 0)
            {
                HP1 = 0;
            }
        }
        if (EXP1 > 600)
        {
            EXP1 = 600;
        }
        else if (EXP1 < 0)
        {
            EXP1 = 0;
        }
        return HP1 + EXP1 + M1;
    }
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 > 99 || E3 < 0)
    {
        return -99;
    }
    if (HP1 > 666)
    {
        HP1 = 666;
    }
    else if (HP1 < 0)
    {
        HP1 = 0;
    }
    if (HP2 > 666)
    {
        HP2 = 666;
    }
    else if (HP2 < 0)
    {
        HP2 = 0;
    }
    if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    else if (EXP1 < 0)
    {
        EXP1 = 0;
    }
    if (EXP2 > 600)
    {
        EXP2 = 600;
    }
    else if (EXP2 < 0)
    {
        EXP2 = 0;
    }
    int Arr[10][10];
    int Pos = 0, Neg = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            Arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (Arr[i][j] > (E3 * 2))
            {
                Pos++;
            }
            else if (Arr[i][j] < (-E3))
            {
                Neg++;
            }
        }
    }
    int i, j;
    if (((Pos % 10) + (Pos / 10)) >= 10)
    {
        int x = (Pos % 10) + (Pos / 10);
        i = (x / 10) + (x % 10);
    }
    else
    {
        i = (Pos % 10) + (Pos / 10);
    }
    if (((Neg % 10) + (Neg / 10)) >= 10)
    {
        int x = (Neg % 10) + (Neg / 10);
        j = (x / 10) + (x % 10);
    }
    else
    {
        j = (Neg % 10) + (Neg / 10);
    }
    int taxiPoint = Arr[i][j];
    int swPoint = Arr[i][j];
    int i1 = i, j1 = j;
    while (i != 0 && i != 9 && j != 0 && j != 9)
    {
        if (swPoint < Arr[i - 1][j + 1])
        {
            swPoint = Arr[i - 1][j + 1];
        }
        i--;
        j++;
    }
    i = i1;
    j = j1;
    while (i != 0 && i != 9 && j != 0 && j != 9)
    {
        if (swPoint < Arr[i + 1][j - 1])
        {
            swPoint = Arr[i + 1][j - 1];
        }
        i++;
        j--;
    }
    i = i1;
    j = j1;
    while (i != 0 && i != 9 && j != 0 && j != 9)
    {
        if (swPoint < Arr[i + 1][j + 1])
        {
            swPoint = Arr[i + 1][j + 1];
        }
        i++;
        j++;
    }
    i = i1;
    j = j1;
    while (i != 0 && i != 9 && j != 0 && j != 9)
    {
        if (swPoint < Arr[i - 1][j - 1])
        {
            swPoint = Arr[i - 1][j - 1];
        }
        i--;
        j--;
    }
    i = i1;
    j = j1;
    while (i1 == 0 || j1 == 0)
    {
        if (swPoint < Arr[i + 1][j + 1])
        {
            swPoint = Arr[i + 1][j + 1];
        }
        i++;
        j++;
        if (i == 9 || j == 9)
        {
            break;
        }
    }
    while (i1 == 9 || j1 == 9)
    {
        if (swPoint < Arr[i - 1][j - 1])
        {
            swPoint = Arr[i - 1][j - 1];
        }
        i--;
        j--;
        if (i == 0 || j == 0)
        {
            break;
        }
    }
    int Result;
    if (swPoint >= abs(taxiPoint))
    {
        EXP1 = ceil(EXP1 * 112 / 100.0);
        EXP2 = ceil(EXP2 * 112 / 100.0);
        HP1 = ceil(HP1 * 11 / 10.0);
        HP2 = ceil(HP2 * 11 / 10.0);
        Result = swPoint;
    }
    else
    {
        EXP1 = ceil(EXP1 * 88 / 100.0);
        EXP2 = ceil(EXP2 * 88 / 100.0);
        HP1 = ceil(HP1 * 9 / 10.0);
        HP2 = ceil(HP2 * 9 / 10.0);
        Result = taxiPoint;
    }
    if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    else if (EXP1 < 0)
    {
        EXP1 = 0;
    }
    if (EXP2 > 600)
    {
        EXP2 = 600;
    }
    else if (EXP2 < 0)
    {
        EXP2 = 0;
    }
    if (HP1 > 666)
    {
        HP1 = 666;
    }
    else if (HP1 < 0)
    {
        HP1 = 0;
    }
    if (HP2 > 666)
    {
        HP2 = 666;
    }
    else if (HP2 < 0)
    {
        HP2 = 0;
    }
    return Result;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    int lenthS = strlen(s);
    int lenthEmail = strlen(email);
    if (lenthS < 8)
    {
        return -1;
    }
    else if (lenthS > 20)
    {
        return -2;
    }
    else
    {
        int x; // @ location
        for (int i = 0; i < lenthEmail; i++)
        {
            if (email[i] == '@')
            {
                x = i;
            }
        }
        if (x == 0)
        {
            return -300;
        }
        int se = 0;
        for (int i = 0; i < x; i++)
        {
            se++;
        }
        int sei;
        for (int i = 0; i <= (lenthS - se); i++)
        {
            int j = 0;
            int k = i;
            while (s[k] == email[j])
            {
                if (j == (se - 1))
                {
                    sei = i;
                    return -(300 + sei);
                }
                k++;
                j++;
            }
        }
        int sci;
        for (int i = 0; i < (lenthS - 1); i++)
        {
            if (s[i] == s[i + 1] && s[i] == s[i+2])
            {
                sci = i;
                return -(400 + sci);
            }
        }
        int symbol = 0;
        for (int i = 0; i < lenthS; i++)
        {
            if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            {
                symbol++;
            }
        }
        if (symbol == 0)
        {
            return -5;
        }
        for (int i = 0; i < lenthS; i++)
        {
            if
            (
                (int(s[i]) == 34) || 
                (37 < int(s[i]) && int(s[i]) < 48) ||
                (int(s[i]) > 57 && int(s[i]) < 64) ||
                (int(s[i]) > 90 && int(s[i]) < 97) ||
                (int(s[i]) > 122 && int(s[i]) < 127)
            )
            {
                return i;
            }
        }
        return -10;
    }
    return -99;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int max = 0;
    int locate;
    for (int i = 0; i < num_pwds; i++)
    {
        int times = 0;
        for (int j = 0; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                times++;
            }
        }
        if (times > max)
        {
            max = times;
            locate = i;
        }
        else if (times == max)
        {
            if (strlen(arr_pwds[i]) > strlen(arr_pwds[locate]))
            {
                locate = i;
            }
        }
    }
    return locate;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////