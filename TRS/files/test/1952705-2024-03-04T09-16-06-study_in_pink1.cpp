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
int firstMeet(int &exp1, int &exp2, int e1)
{

    if (e1 < 0 || e1 > 99)
        return -99;
    if (e1 >= 0 && e1 <= 3) // task1th1
    {
        switch (e1)
        {
        case 0:
            exp2 = exp2 + 29;
            break;
        case 1:
            exp2 = exp2 + 45;
            break;
        case 2:
            exp2 = exp2 + 75;
            break;
        case 3:
            exp2 = exp2 + 29 + 45 + 75;
            break;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 = ceil(exp1 + D / (200.0));
            if (exp1 > 600)
                exp1 = 600;
        }
        else
            exp1 = ceil(exp1 - D / (100.0));
    }
    if (e1 >= 4 && e1 <= 99) // task1th2
    {
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 = ceil(exp2 + (e1 / 4.0 + 19));
            if (exp2 > 600)
                exp2 = 600;
        }
        if (e1 >= 20 && e1 <= 49)
        {
            exp2 = ceil(exp2 + (e1 / 9.0 + 21));
            if (exp2 > 600)
                exp2 = 600;
        }
        if (e1 >= 50 && e1 <= 65)
        {
            exp2 = ceil(exp2 + (e1 / 16.0 + 17));
            if (exp2 > 600)
                exp2 = 600;
        }
        if (e1 >= 66 && e1 <= 79)
        {
            exp2 = ceil(exp2 + (e1 / 4.0 + 19));
            if (exp2 >= 200)
         {       exp2 = ceil(exp2 + (e1 / 9.0 + 21));
         if(exp2>600)
        exp2=600;
        }
        }
        if (e1 >= 80 && e1 <= 99)
        {
            exp2 = ceil(exp2 + (e1 / 4.0 + 19));
            if(exp2>600)
        exp2=600;
            exp2 = ceil(exp2 + (e1 / 9.0 + 21));
            if(exp2>600)
        exp2=600;
            if (exp2 >= 400)
            {
                exp2 = ceil(exp2 + (e1 / 16.0 + 17));
                exp2 = ceil(exp2 * 1.15);
            }
        }
        exp1 = exp1 - e1;
    }
    if (exp1 > 600)
        exp1 = 600;
    if (exp2 > 600)
        exp2 = 600;
    if (exp1 < 0)
        exp1 = 0;
    if (exp2 < 0)
        exp2 = 0;
    return exp1 + exp2;
}


int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (E2 > 99 || E2 < 0)
        return -99;
    int Ms = M1, MCK = 0;
    double P1, P2, P3;
    int S = round(sqrt(EXP1)) * round(sqrt(EXP1));

    if (EXP1 >= S)
        P1 = 1;
    else
        P1 = (EXP1 * 1.0 / S + 80) / 123;
    if (E2 % 2 != 0)
    {   if(M1!=0)
        while (true)
        {
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 * 1.3);
                if (HP1 > 666)
                    HP1 = 666;
                M1 = M1 - 150;
                if (M1 < 0)
                    M1 = 0;
                MCK += 150;
            }
            else
            {
                HP1 = ceil(HP1 * 11.0/10);
                if (HP1 > 666)
                    HP1 = 666;
                M1 = M1 - 70;
                if (M1 < 0)
                    M1 = 0;
                MCK += 70;
            }
            if (MCK > Ms / 2)
                break;
            if (EXP1 < 400)
            {
                M1 = M1 - 200;
                if (M1 < 0)
                    M1 = 0;
                MCK += 200;
            }
            else
            {
                M1 = M1 - 120;
                if (M1 < 0)
                    M1 = 0;
                MCK += 120;
            }
            EXP1 = ceil(EXP1 * 1.13);
            if (EXP1 > 600)
                EXP1 = 600;

            if (MCK > Ms / 2)
                break;
            if (EXP1 < 300)
            {
                M1 = M1 - 100;
                if (M1 < 0)
                    M1 = 0;
                MCK += 100;
            }
            else
            {
                M1 = M1 - 120;
                if (M1 < 0)
                    M1 = 0;
                MCK += 120;
            }
            EXP1 = ceil(EXP1 * 0.9);
            if (EXP1 > 600)
                EXP1 = 600;
            if (MCK > Ms / 2)
                break;
        }
    }
    else
    {if(M1!=0)
        if (M1 > 0)
        {
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 * 1.3);
                if (HP1 > 666)
                    HP1 = 666;
                M1 = M1 - 150;
                if (M1 < 0)
                    M1 = 0;
            }
            else
            {
                HP1 = ceil(HP1 * 11.0/10);
                if (HP1 > 666)
                    HP1 = 666;
                M1 = M1 - 70;
                if (M1 < 0)
                    M1 = 0;
            }
        }
        if (M1 > 0)
        {
            if (EXP1 < 400)
                M1 = M1 - 200;
            else
                M1 = M1 - 120;
            if (M1 < 0)
                M1 = 0;
            EXP1 = ceil(EXP1 * 1.13);
        }
        if (M1 > 0)
        {
            if (EXP1 < 300)
                M1 = M1 - 100;
            else
                M1 = M1 - 120;
            if (M1 < 0)
                M1 = 0;
            EXP1 = ceil(EXP1 * 0.9);
        }
    }
    HP1 = ceil(HP1 * 0.83);
    EXP1 = ceil(EXP1 * 1.17);
    if (EXP1 > 600)
        EXP1 = 600;
    if (HP1 > 666)
        HP1 = 666;
         S = round(sqrt(EXP1)) * round(sqrt(EXP1));
    if (EXP1 >= S)
        P2 = 1;
    else
        P2 = (EXP1 * 1.0 / S + 80) / 123;
    int a[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 < 10)
        i = E2;
    else
        i = (E2 % 10 + E2 / 10) % 10;
    P3 = a[i] / 100.0;
    if (P1 ==1&& P2==1&&P3==1.0)
        EXP1 = ceil(EXP1 * 0.75);
    else
    {
        if ((P1 + P2 + P3) / 3 < 0.5)
        {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
            if (EXP1 > 600)
                EXP1 = 600;
            if (HP1 > 666)
                HP1 = 666;
        }
        else
        {
            HP1 = ceil(HP1 * 0.90);
            EXP1 = ceil(EXP1 * 1.20);
            if (EXP1 > 600)
                EXP1 = 600;
            if (HP1 > 666)
                HP1 = 666;
        }
    }

    return HP1 + EXP1 + M1;
}
// Task 3
int sumOfDigits(int num)
{
    int total = 0;
    while (num > 0)
    {
        total += num % 10;
        num = num / 10;
    }
    return total;
}
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 < 0 || E3 > 99)
        return -99;
    int a[10][10];
    int big = 0;
    int small = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (a[i][j] > E3 * 2)
                big++;
            if (a[i][j] < -E3)
                small++;
        }
    int totalBig = sumOfDigits(big);
    int totalSmall = sumOfDigits(small);

    while (totalBig >= 10)
    {
        totalBig = sumOfDigits(totalBig);
    }
    while (totalSmall >= 10)
    {
        totalSmall = sumOfDigits(totalSmall);
    }
    int imeet = totalBig;
    int jmeet = totalSmall;
    int x = imeet, y = jmeet;
    int maxcheo1 = INT_MIN, maxcheo2 = INT_MIN;
    while (x < 10 && y < 10)
    {
        maxcheo1 = max(maxcheo1, a[x][y]);
        x++;
        y++;
    }

    x = imeet, y = jmeet;
    while (x < 10 && y >= 0)
    {
        maxcheo2 = max(maxcheo2, a[x][y]);
        x++;
        y--;
    }

    int maxx = max(maxcheo1, maxcheo2);
    if (abs(a[imeet][jmeet]) <= maxx)
    {
        EXP1 = ceil(EXP1 * 112.0 / 100);
        if (EXP1 > 600)
            EXP1 = 600;
        EXP2 = ceil(EXP2 * 112.0 / 100);
        if (EXP2 > 600)
            EXP2 = 600;
        HP1 = ceil(HP1 * 11.0 / 10);
        HP2 = ceil(HP2 * 11.0 / 10);
        return maxx;
    }
    else
    {
        EXP1 = ceil(EXP1 * 0.88);
        EXP2 = ceil(EXP2 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        HP2 = ceil(HP2 * 0.9);
        return a[imeet][jmeet];
    }
}

// Task 4
int checkPassword(const char *s, const char *email)
{

    int length = strlen(s);
    if (length < 8)
        return -1;
    if (length > 20)
        return -2;
    int mail = strlen(email), vitri;
    for (int i = 0; i < mail; i++)
        if (email[i] == '@')
            vitri = i;
    char se[101];
    int endse = 0;
    for (int i = 0; email[i] != '\0' && email[i] != '@'; ++i)
    {
        se[i] = email[i];
        ++endse;
    }
    se[endse] = '\0';
    const char *pos = strstr(s, se);
    if (pos != nullptr)
    {
        return -(300 + (pos - s));
    }
    for (int i = 0; i < length - 2; ++i)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
            return -(400 + i);
    }
    int d = 0;
    for (int i = 0; i < length; ++i)
    {
        if (s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%')
            d++;
    }
    if (d == 0)
        return -5;
    for (int i = 0; i < length; ++i)
    {
        char cc = s[i];
        if (isdigit(cc) == false && isupper(cc) == false && islower(cc) == false && cc != '!' && cc != '@' && cc != '#' && cc != '$' && cc != '%')
            return i;
    }
    return -10;
}
// Task 5

struct password
{
    int position;
    int length;
    int frequency;
};

int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    password tansuatmax = {0, 0, 0};
    for (int i = 0; i < num_pwds; ++i)
    {

        int tansuathientai = 0;
        for (int j = 0; j < num_pwds; ++j)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                ++tansuathientai;
            }
        }
        if (tansuathientai > tansuatmax.frequency || (tansuathientai == tansuatmax.frequency && strlen(arr_pwds[i]) > tansuatmax.length))
        {
            tansuatmax.position = i;
            tansuatmax.length = strlen(arr_pwds[i]);
            tansuatmax.frequency = tansuathientai;
        }
    }
    return tansuatmax.position;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////