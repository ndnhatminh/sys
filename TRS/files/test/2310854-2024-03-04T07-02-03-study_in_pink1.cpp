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
int firstMeet(int &EXP1, int &EXP2, int E1)
{
    // TODO: Complete this function
    int ret;
    if (E1 >= 0 && E1 <= 99)
    {
        if (E1 >= 0 && E1 <= 3)
        {
            if (E1 == 0)
            {
                EXP2 += 29;
            }
            else if (E1 == 1)
            {
                EXP2 += 45;
            }
            else if (E1 == 2)
            {
                EXP2 += 75;
            }
            else if (E1 == 3)
            {
                EXP2 += 149;
            }
            float D = E1 * 3 + EXP1 * 7;
            int W = E1 * 3 + EXP1 * 7;
            if (W % 2 == 0)
            {
                EXP1 = ceil(EXP1 + D / 200);
            }
            else
            {
                EXP1 = ceil(EXP1 - D / 100);
            }
        }
        else if (E1 >= 4 && E1 <= 99)
        {
            if (E1 >= 4 && E1 <= 19)
            {
                EXP2 = ceil((float)EXP2 + (float)E1 / 4 + 19);
            }
            else if (E1 >= 20 && E1 <= 49)
            {
                EXP2 = ceil((float)EXP2 + (float)E1 / 9 + 21);
            }
            else if (E1 >= 50 && E1 <= 65)
            {
                EXP2 = ceil((float)EXP2 + (float)E1 / 16 + 17);
            }
            else if (E1 >= 66 && E1 <= 79)
            {
                EXP2 = ceil((float)EXP2 + (float)E1 / 4 + 19);
                if (EXP2 >= 200)
                {
                    EXP2 = ceil((float)EXP2 + (float)E1 / 9 + 21);
                }
            }
            else if (E1 >= 80 && E1 <= 99)
            {
                EXP2 = ceil((float)EXP2 + (float)E1 / 4 + 19);
                EXP2 = ceil((float)EXP2 + (float)E1 / 9 + 21);
                if (EXP2 >= 400)
                {
                    EXP2 = ceil((float)EXP2 + (float)E1 / 16 + 17);
                    EXP2 = ceil(float(EXP2 * 1.15));
                }
            }
            EXP1 -= E1;
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
        ret = EXP1 + EXP2;
    }
    else
    {
        ret = -99;
    }
    return ret;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    int ret2;
    float P, P1, P2, P3;
    int temp = 600;
    float S = 0;
    // con duong 1

    if (E2 >= 0 && E2 <= 99)
    {

        for (int i = 1; i <= 24; i++)
        {
            if (abs(EXP1 - i * i) < temp)
            {
                temp = abs(EXP1 - i * i);
                S = i * i;
            }
        }
        if (EXP1 >= S)
        {
            P1 = 100;
        }
        else
        {
            P1 = 100 * ((float)EXP1 / S + 80) / 123;
        }

        // con duong 2
        float tien = M1 / 2;
        if (E2 % 2 == 1)
        {
            int cp = 0;

            while (cp <= tien)
            {
                if (HP1 < 200)
                {
                    HP1 = ceil((float)HP1 * 1.3);
                    cp += 150;
                    M1 -= 150;
                }
                else if (HP1 >= 200)
                {
                    HP1 = ceil((float)HP1 * 1.1);
                    cp += 70;
                    M1 -= 70;
                }
                if (cp >= tien)
                    break;

                if (HP1 > 666)
                {
                    HP1 = 666;
                }
                if (M1 <= 0)
                {
                    M1 = 0;
                    break;
                }
                if (EXP1 < 400)
                {
                    cp += 200;
                    M1 -= 200;
                    EXP1 = ceil((float)EXP1 * 1.13);
                }
                else if (EXP1 >= 400)
                {
                    cp += 120;
                    M1 -= 120;
                    EXP1 = ceil((float)EXP1 * 1.13);
                }
                if (cp >= tien)
                    break;

                if (EXP1 > 600)
                {
                    EXP1 = 600;
                }
                if (M1 <= 0)
                {
                    M1 = 0;
                    break;
                }
                if (EXP1 < 300)
                {
                    cp += 100;
                    M1 -= 100;
                    EXP1 = ceil((float)EXP1 * 0.9);
                }
                else if (EXP1 >= 300)
                {
                    cp += 120;
                    M1 -= 120;
                    EXP1 = ceil((float)EXP1 * 0.9);
                }
                if (cp >= tien)
                    break;
                if (EXP1 > 600)
                {
                    EXP1 = 600;
                }
            }
            HP1 = ceil((float)HP1 * 0.83);
            EXP1 = ceil((float)EXP1 * 1.17);

            if (EXP1 > 600)
            {
                EXP1 = 600;
            }
        }
        else if (E2 % 2 == 0)
        {
            do
            {
                if (HP1 < 200)
                {
                    HP1 = ceil((float)HP1 * 1.3);
                    M1 -= 150;
                }
                else if (HP1 >= 200)
                {
                    HP1 = ceil((float)HP1 * 1.1);
                    M1 -= 70;
                }
                if (HP1 > 666)
                {
                    HP1 = 666;
                }
                if (M1 <= 0)
                {
                    M1 = 0;
                    break;
                }
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    EXP1 = ceil((float)EXP1 * 1.13);
                }
                else if (EXP1 >= 400)
                {
                    M1 -= 120;
                    EXP1 = ceil((float)EXP1 * 1.13);
                }
                if (EXP1 > 600)
                {
                    EXP1 = 600;
                }
                if (M1 <= 0)
                {
                    M1 = 0;
                    break;
                }
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    EXP1 = ceil((float)EXP1 * 0.9);
                }
                else if (EXP1 >= 300)
                {
                    M1 -= 120;
                    EXP1 = ceil((float)EXP1 * 0.9);
                }
                if (EXP1 > 600)
                {
                    EXP1 = 600;
                }
                break;
            } while (1 < 1);
            HP1 = ceil((float)HP1 * 0.83);
            EXP1 = ceil((float)EXP1 * 1.17);
            if (EXP1 > 600)
            {
                EXP1 = 600;
            }
        }
        temp = 600;
        S = 0;
        for (int i = 1; i <= 24; i++)
        {
            if (abs(EXP1 - i * i) < temp)
            {
                temp = abs(EXP1 - i * i);
                S = i * i;
            }
        }

        if (EXP1 >= S)
        {
            P2 = 100;
        }
        else
        {
            P2 = 100 * ((float)EXP1 / S + 80) / 123;
        }

        // con duong 3
        int arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int z = 0;
        int y = 0;
        if (E2 <= 9)
        {
            z = E2;
        }
        else if (E2 > 9)
        {
            y = (E2 / 10) + (E2 % 10);
            z = y % 10;
        }
        P3 = arr[z];
        P = (P1 + P2 + P3) / 3;
        if (P == 100)
        {
            EXP1 = ceil((float)EXP1 * 0.75);
            temp = 600;
            S = 0;
            for (int i = 1; i <= 24; i++)
            {
                if (abs(EXP1 - i * i) < temp)
                {
                    temp = abs(EXP1 - i * i);
                    S = i * i;
                }
            }
            if (EXP1 >= S)
            {
                P1 = 100;
                P2 = 100;
            }
            else
            {
                P1 = 100 * ((float)EXP1 / S + 80) / 123;
                P2 = 100 * ((float)EXP1 / S + 80) / 123;
            }
        }
        P = (P1 + P2 + P3) / 3;
        if (P < 50)
        {
            HP1 = ceil((float)HP1 * 0.85);
            EXP1 = ceil((float)EXP1 * 1.15);
        }
        else if (P >= 50)
        {
            HP1 = ceil((float)HP1 * 0.90);
            EXP1 = ceil((float)EXP1 * 1.20);
        }
        if (EXP1 > 600)
        {
            EXP1 = 600;
        }
        ret2 = HP1 + EXP1 + M1;
    }
    else
    {
        ret2 = -99;
    }
    return ret2;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    int ret3;
    int a[10][10];
    int sum1 = 0;
    int sum2 = 0;
    if (E3 >= 0 && E3 <= 99)
    {

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                a[i][j] = 0;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (a[i][j] > (E3 * 2))
                {
                    sum1 += 1;
                }
                if (a[i][j] < (-E3))
                {
                    sum2 += 1;
                }
            }
        }
        if (sum1 > 9)
        {
            sum1 = (sum1 / 10) + (sum1 % 10);
        }
        if (sum1 > 9)
        {
            sum1 = (sum1 / 10) + (sum1 % 10);
        }
        if (sum2 > 9)
        {
            sum2 = (sum2 / 10) + (sum2 % 10);
        }
        if (sum2 > 9)
        {
            sum2 = (sum2 / 10) + (sum2 % 10);
        }
        int d = abs(a[sum1][sum2]);
        int max = -4000;
        int g, h;
        g = sum1;
        h = sum2;
        for (int b = 0; b < 10; b++)
        {
            if (a[g][h] > max)
                max = a[g][h];

            if (g == 9)
                break;
            if (h == 9)
                break;
            g += 1;
            h += 1;
        }
        g = sum1;
        h = sum2;
        for (int b = 0; b < 10; b++)
        {
            if (a[g][h] > max)
                max = a[g][h];

            if (g == 0)
                break;
            if (h == 0)
                break;
            g -= 1;
            h -= 1;
        }
        g = sum1;
        h = sum2;
        for (int b = 0; b < 10; b++)
        {
            if (a[g][h] > max)
                max = a[g][h];

            if (g == 9)
                break;
            if (h == 0)
                break;
            g += 1;
            h -= 1;
        }
        g = sum1;
        h = sum2;
        for (int b = 0; b < 10; b++)
        {
            if (a[g][h] > max)
                max = a[g][h];

            if (g == 0)
                break;
            if (h == 9)
                break;
            g -= 1;
            h += 1;
        }
        if (max <= 0)
        {
            max = abs(max);
        }
        if (d > max)
        {
            ret3 = a[sum1][sum2];
            EXP1 = ceil((float)EXP1 * 0.88);
            HP1 = ceil((float)HP1 * 0.9);
            EXP2 = ceil((float)EXP2 * 0.88);
            HP2 = ceil((float)HP2 * 0.9);
        }
        else if (d <= max)
        {
            ret3 = max;
            EXP1 = ceil((float)EXP1 * 1.12);
            HP1 = ceil((float)HP1 * 1.1);
            EXP2 = ceil((float)EXP2 * 1.12);
            HP2 = ceil((float)HP2 * 1.1);
        }
    }
    else
    {
        ret3 = -99;
    }
    return ret3;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    int ex;
    char se[100];
    char kt[6] = "@#%$!";
    char hop[57] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz@#%$!";
    bool cokt = false;
    bool ng;
    int vitrisai = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (s[i] == kt[j])
            {
                cokt = true;
                break;
            }
        }
        if (cokt == true)
            break;
    }
    for (int i = 0; i < strlen(s); i++)
    {
        ng = false;
        for (int j = 0; j < 57; j++)
        {
            if (s[i] == hop[j])
            {
                ng = true;
            }
        }
        if (ng == false)
        {
            vitrisai = i;
            break;
        }
    }
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
            break;
        se[i] = email[i];
    }

    int v, b, n, l;
    bool es1 = false, es2 = false;
    v = 0;
    while (v < strlen(s) && !es1)
    {
        b = 0;
        if (s[v] == se[b])
        {
            n = v + 1;
            l = b;
            while (n < v + strlen(se) && !es2)
            {
                b = b + 1;
                if (s[n] == se[b])
                {
                    if (n == (v + strlen(se) - 1))
                    {
                        break;
                    }
                    n = n + 1;
                }
                else
                    es2 = true;
            }
            if (s[v + strlen(se) - 1] == se[strlen(se) - 1] && !es2)
                es1 = true;
            else
                v = v + 1;
        }
        else
            v = v + 1;
    }
    int sci;
    bool repeat;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == s[i + 1])
        {
            repeat = true;
            sci = i;
            break;
        }
    }
    if (strlen(s) < 8)
    {
        ex = -1;
    }
    else if (strlen(s) > 20)
    {
        ex = -2;
    }
    else if ((v >= 0) && (v <= strlen(s)))
    {
        ex = -(300 + v);
    }
    else if (repeat == true)
    {
        ex = -(400 + sci);
    }
    else if (cokt == false)
    {
        ex = -5;
    }
    else
    {
        if (ng == false)
        {
            ex = vitrisai;
        }
    }
    return ex;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int out;
    int count[100];
    int maxcount = 0;
    for (int i = 0; i < 100; i++)
    {
        count[i] = 0;
    }
    string maxp = arr_pwds[0];
    for (int i = 0; i < num_pwds; i++)
    {
        int n = i;
        int fl = 0;
        if (i > 0)
        {
            while (n > 0)
            {
                if (arr_pwds[n - 1] == arr_pwds[i])
                {
                    fl = 1;
                }
                n -= 1;
            }
        }
        if (fl == 0)
        {
            for (int j = 0; j < num_pwds; j++)
            {

                if (arr_pwds[j] == arr_pwds[i])
                {
                    count[i] += 1;
                }
            }
        }
    }

    int maxlen;
    for (int i = 0; i < 100; i++)
    {
        if (count[i] >= maxcount)
        {
            maxcount = count[i];
            maxlen = strlen(arr_pwds[i]);
        }
    }

    int vitrimax[100];
    for (int i = 0; i < 100; i++)
    {
        if (count[i] == maxcount)
        {
            if (strlen(arr_pwds[i]) > maxlen)
            {
                maxlen = strlen(arr_pwds[i]);
                out = i;
            }
            else if (strlen(arr_pwds[i]) == maxlen)
            {

                out = i;
            }
        }
    }

    return out;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////