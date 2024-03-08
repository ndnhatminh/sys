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
void EXP1limit(int &EXP1)
{
    if (EXP1 < 0)
        EXP1 = 0;
    if (EXP1 > 600)
        EXP1 = 600;
}
void EXP2limit(int &EXP2)
{
    if (EXP2 > 600)
        EXP2 = 600;
    if (EXP2 < 0)
        EXP2 = 0;
}

void HP1limit(int &HP1)
{
    if (HP1 < 0)
        HP1 = 0;
    if (HP1 > 666)
        HP1 = 666;
}
void HP2limit(int &HP2)
{
    if (HP2 > 666)
        HP2 = 666;
    if (HP2 < 0)
        HP2 = 0;
}
void M1limit(int &M1)
{
    if (M1 < 0)
        M1 = 0;
    if (M1 > 3000)
        M1 = 3000;
}
void M2limit(int &M2)
{
    if (M2 > 3000)
        M2 = 3000;
    if (M2 < 0)
        M2 = 0;
}
int checkE(int E, int minRange, int maxRange)
{
    if (E < minRange || E > maxRange)
    {
        return -99;
    }
    return E;
}

// Task 1
void info1(int &exp2, float e1)
{
    exp2 += (e1*1.0 / 4) + 19 + 0.999;
    EXP2limit(exp2);
}
void info2(int &exp2, float e1)
{
    exp2 += (e1*1.0 / 9) + 21 + 0.999;
    EXP2limit(exp2);
}
void info3(int &exp2, float e1)
{
    exp2 += (e1*1.0 / 16) + 17 + 0.999;
    EXP2limit(exp2);
}
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    int check = checkE(e1, 0, 99);
    if (check == -99)
        return -99;
    else
    {
        EXP1limit(exp1);
        EXP2limit(exp2);
        if ((e1 <= 3) && (e1 >= 0))
        {
            if (e1 == 0)
                exp2 = exp2 + 29;
            if (e1 == 1)
                exp2 = exp2 + 45;
            if (e1 == 2)
                exp2 = exp2 + 75;
            if (e1 == 3)
                exp2 = exp2 + 29 + 45 + 75;
            EXP2limit(exp2);
            int D;
            D = (e1 * 3) + (exp1 * 7);
            float N;
            float M = 0.0;
            N = D * 1.0 / 200;
            if (D % 2 == 0)
            {
                exp1 = exp1 + N + 0.999;
                EXP1limit(exp1);
            }
            else
            {
                M += D / 100;
                exp1 = exp1 - M + 0.999;
                EXP1limit(exp1);
            }
        }
        else
        {
            if ((e1 >= 4) && (e1 <= 19))
            {
                info1(exp2, e1);
            }
            else if ((e1 >= 20) && (e1 <= 49))
            {
                info2(exp2, e1);
            }
            else if ((e1 >= 50) && (e1 <= 65))
            {
                info3(exp2, e1);
            }
            else if ((e1 >= 66) && (e1 <= 79))
            {
                info1(exp2, e1);
                if (exp2 > 200)
                    info2(exp2, e1);
            }
            else if ((e1 >= 80) && (e1 <= 99))
            {
                info1(exp2, e1);
                info2(exp2, e1);
                if (exp2 > 400)
                {
                    info3(exp2, e1);
                    exp2 = exp2*1.15+0.999;
                }
                EXP2limit(exp2);
            }
            exp1 -= e1;
        }
        EXP1limit(exp1);
        return exp1 + exp2;
    }
}

// Task 2

int getClosestPerfectSquare(int &S, int N)
{
    int x = sqrt(N);
    if ((x * x) == N)
    {
        S += N;
        return S;
    }
    else{
    int aboveN = (x + 1) * (x + 1), belowN = x * x;
    int diff1 = aboveN - N;
    int diff2 = N - belowN;

    if (diff1 > diff2)
        S = S + belowN;
    else
        S = S + aboveN;
        return S;}
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    // 4.2.1
    int result = checkE(E2, 0, 99);
    if (result == -99)
        return -99;
    EXP1limit(EXP1);
    M1limit(M1);
    HP1limit(HP1);
    float P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float P1;
    float P2;
    float P3;
    int Mpay = 0;
    int M_static = 0;
    int S=0;
    int S1=0;
    int i;
    M_static = M1;
    getClosestPerfectSquare(S, EXP1);
    if (EXP1 >= S)
    {
        P1 = 1.0;
    }
    else
    {
        P1 = ((((EXP1 * 1.0)) / S) + 80) / 123;
    }
    // 4.2.2
    HP1limit(HP1);
    M1limit(M1);
    if ((E2 % 2) != 0)
    {
        if (M1 != 0)
        {
            while (true)
            {
                if (HP1 < 200)
                {
                    HP1 = HP1 * 1.3 + 0.999;
                    HP1limit(HP1);
                    Mpay = Mpay + 150;
                    M1 = M1 - 150;
                    M1limit(M1);
                }
                else
                {
                    HP1 = HP1 * 1.1 + 0.999;
                    HP1limit(HP1);
                    Mpay = Mpay + 70;
                    M1 = M1 - 70;
                    M1limit(M1);
                }
                if (M_static / 2 < Mpay)
                    break;
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    Mpay += 200;
                    M1limit(M1);
                }
                else
                {
                    M1 -= 120;
                    Mpay += 120;
                    M1limit(M1);
                }
                EXP1 = EXP1 * 1.13 + 0.999;
                EXP1limit(EXP1);
                if (M_static / 2 < Mpay)
                    break;
                if (EXP1 < 300)
                {
                    Mpay += 100;
                    M1 -= 100;
                }
                else
                {
                    M1 -= 120;
                    Mpay += 120;
                }
                EXP1 = EXP1 * 0.9 + 0.999;
                EXP1limit(EXP1);
                M1limit(M1);
                if (M_static / 2 < Mpay)
                    break;
            }
        }
    }
    else
    {
        if (M1 > 0)
        {
            if (HP1 < 200)
            {
                HP1 = HP1 * 1.3 + 0.999;
                HP1limit(HP1);
                M1 = M1 - 150;
                M1limit(M1);
            }
            else
            {
                HP1 = HP1 * 1.1 + 0.999;
                HP1limit(HP1);
                M1 = M1 - 70;
                M1limit(M1);
            }
        }
        if (M1 > 0)
        {
            if (EXP1 < 400)
                M1 -= 200;
            else
                M1 -= 120;

            EXP1 = EXP1 * 1.13 + 0.999;
            EXP1limit(EXP1);
        }
        if (M1 > 0)
        {
            if (EXP1 < 300)
                M1 -= 100;
            else
                M1 -= 120;
            EXP1 = EXP1 * 0.9 + 0.999;
            EXP1limit(EXP1);
            M1limit(M1);
        }
    }
    HP1 = HP1 * 0.83 + 0.999;
    EXP1 = EXP1 * 1.17 + 0.999;
    EXP1limit(EXP1);
    getClosestPerfectSquare(S1, EXP1);
    if (EXP1 >= S1)
    {
        P2 = 1.0;
    }
    else if (EXP1 < S1)
    {
        P2 = ((((EXP1 * 1.0)) / S1) + 80) / 123;
    }
    // 4.2.3
    if (E2 < 10)
    {
        i = E2;
    }
    else
    {
        i = ((E2 / 10) + (E2 % 10)) % 10;
    }
    P3 = P[i] / 100;
    if ((P1 == 1) && (P2 == 1) && (P3 == 1))
    {
        EXP1 = EXP1 * 0.75 + 0.999;
        EXP1limit(EXP1);
    }
    else
    {
        double p = 0.0;
        p += (P1 + P2 + P3) / 3;
        if (p < 0.5)
        {
            HP1 = HP1 * 0.85 + 0.999;
            HP1limit(HP1);
            EXP1 = EXP1 * 1.15 + 0.999;
            EXP1limit(EXP1);
        }
        else
        {
            HP1 = HP1 * 0.9 + 0.999;
            HP1limit(HP1);
            EXP1 = EXP1 * 1.2 + 0.999;
            EXP1limit(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    int checker = checkE(E3, 0, 99);
    if (checker == -99)
        return -99;
        else{
    HP1limit(HP1);
    EXP1limit(EXP1);
    HP2limit(HP2);
    EXP2limit(EXP2);
    int map_taxi[10][10];
    int taxi, sw, x, y, l;
    float check1, check2, check3, check4;
    int num_i = 0, num_j = 0;

    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            map_taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (map_taxi[i][j] > (E3 * 2))
            {
                num_i++;
            }
            if (map_taxi[i][j] < -E3)
            {
                num_j++;
            }
        }
    }

    if (num_i < 10)
    {
        x = num_i;
    }
    else if (num_i >= 10)
    {
        while (num_i >= 10)
        {
            num_i = num_i / 10 + num_i % 10;
        }
        x = num_i;
    }

    if (num_j < 10)
    {
        y = num_j;
    }
    else if (num_j >= 10)
    {
        while (num_j >= 10)
        {
            num_j = num_j / 10 + num_j % 10;
        }
        y = num_j;
    }

    taxi = map_taxi[x][y];
    for (int a = 0; a < 9; a++)
    {
        check1 = map_taxi[x][y];
        if (check1 <= map_taxi[x + a][y - a])
        {
            check1 = map_taxi[x + a][y - a];
        }
        check2 = map_taxi[x][y];
        if (check2 <= map_taxi[x - a][y + a])
        {
            check2 = map_taxi[x - a][y + a];
        }
    
        if ((x + a) == 9 || (y + a) == 9|| (y - a) == 0|| (x - a) == 0)
            break;
    }
    for (int b = 0; b < 9; b++)
    {
        check3 = map_taxi[x][y];
        if (check3 <= map_taxi[x + b][y + b])
        {
            check3 = map_taxi[x + b][y + b];
        }
        check4 = map_taxi[x][y];
        if (check4 <= map_taxi[x - b][y - b])
        {
            check4 = map_taxi[x - b][y - b];
        }
        if ((x + b) == 9 || (y + b) == 9 || (x - b) == 0 || (y - b) == 0)
            break;
        }
    l = check1;
    if (check2 > l)
        l = check2;
    if (check3 > l)
        l = check3;
    if (check4 > l)
        l = check4;
    sw = abs(l);
    if (sw >= abs(taxi))
    {
        EXP1 = EXP1 * 1.12 + 0.999;
        EXP1limit(EXP1);
        HP1 = HP1 * 1.1 + 0.999;
        HP1limit(HP1);
        EXP2 = EXP2 * 1.12 + 0.999;
        EXP1limit(EXP2);
        HP2 = HP2 * 1.1 + 0.999;
        HP2limit(HP2);
        return sw;
    }

    else
    {
        EXP1 = EXP1 * 0.88 + 0.999;
        EXP1limit(EXP1);
        HP1 = HP1 * 0.9 + 0.999;
        HP1limit(HP1);
        EXP2 = EXP2 * 0.88 + 0.999;
        EXP1limit(EXP2);
        HP2 = HP2 * 0.9 + 0.999;
        HP2limit(HP2);
        return taxi;
    }
    return -1;
}}
// Task 4
int checkPassword(const char *s, const char *email)
{
    char q[strlen(email + 1)];
    strcpy(q, email);
    char *se;
    char special[] = "@#%$!";
    se = strtok(q, "@");
    int s_length = strlen(s);
    int special_num = 0;
    if (s_length < 8)
    {
        return -1;
    }

    if (s_length > 20)
    {
        return -2;
    }
    const char *p = strstr(s, se);
    if (p)
    {
        int sei = p - s;
        return -(300 + sei);
    }
    for (int i = 0; i < s_length; i++)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            return -(400 + i);
        }
    }
    const char *spcharpwd = strpbrk(s, special);
    if (spcharpwd == nullptr)
    {
        return -5;
    }
    for (size_t i = 0; i < s_length; ++i)
    {
        char c = s[i];
        if (!isalnum(c) && c != '@' && c != '#' && c != '%' && c != '$' && c != '!')
        {
            return static_cast<int>(i);
        }
    }
    return -10;

    // TODO: Complete this function
    return -99;
}
// Task 5
int same(const char **arr, size_t size)
{

    int maxcount = 0, maxlength = 0, out = -1;
    for (int i = 0; i < size; ++i)
    {
        const string &pwd = arr[i];
        int count = 0;
        int length = pwd.length();
        for (int j = 0; j < size; ++j)
        {
            if (arr[j] == pwd)
            {
                ++count;
            }
        }
        if (count > maxcount || (count == maxcount && length > maxlength))
        {
            maxcount = count;
            maxlength = length;
            out = i;
        }
    }

    return out;
}
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int result = same(arr_pwds, num_pwds);
    return result;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////