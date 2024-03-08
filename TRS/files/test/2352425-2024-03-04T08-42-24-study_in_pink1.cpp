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
void healthpoints(int &hp)
{
    if (hp < 0)
        hp = 0;
    else if (hp > 666)
        hp = 666;
}

void money(int &m)
{
    if (m < 0)
        m = 0;
    else if (m > 3000)
        m = 3000;
}
void event(int e)
{
    if (e < 0 || e > 99)
        e = -99;
}

int nearestPerfectSquare(int n)
{
    int root = sqrt(n);
    if (root * root == n)
    {
        return n;
    }
    else if ((root + 1) * (root + 1) - n < n - root * root)
    {
        return (root + 1) * (root + 1);
    }
    else
    {
        return root * root;
    }
}

int helper(int c)
{
    int a = c / 10;
    int b = c % 10;
    return a + b;
}

// Task 1

void check(int &exp)
{
    if (exp < 0)
        exp = 0;
    else if (exp > 600)
        exp = 600;
    else
        return;
}
int firstMeet(int &exp1, int &exp2, int e1)
{
    bool tt1 = 0;
    bool tt2 = 0;
    bool tt3 = 0;

    if (e1 < 0 || e1 > 99)
        return -99;

    check(exp1);
    check(exp2);

    if (0 <= e1 && e1 <= 3)
    {
        if (e1 == 0)
        {
            exp2 += 29;
            check(exp2);
        }
        else if (e1 == 1)
        {
            exp2 += 45;
            check(exp2);
        }
        else if (e1 == 2)
        {
            exp2 += 75;
            check(exp2);
        }
        else if (e1 == 3)
        {
            exp2 = exp2 + 29 + 45 + 75;
            check(exp2);
        }

        int d = e1 * 3 + exp1 * 7;

        if (d % 2 == 0)
        {
            exp1 += ceil(double(d) / 200);
        }
        else
            exp1 = ceil(exp1 - double(d) / 100);

        check(exp1);
    }
    else if (e1 >= 4 && e1 <= 19)
    {
        tt1 = 1;
        exp2 = exp2 + ceil(static_cast<double>(e1) / 4) + 19;
        check(exp2);
        exp1 -= e1;
        check(exp1);
    }
    else if (e1 >= 20 && e1 <= 49)
    {
        tt2 = 1;
        exp2 = exp2 + ceil(static_cast<double>(e1) / 9) + 21;
        check(exp2);
        exp1 -= e1;
        check(exp1);
    }
    else if (e1 >= 50 && e1 <= 65)
    {
        tt3 = 1;
        exp2 = exp2 + ceil(static_cast<double>(e1) / 16) + 17;
        check(exp2);
        exp1 -= e1;
        check(exp1);
    }

    else if (e1 >= 66 && e1 <= 79)
    {
        exp2 = exp2 + ceil(static_cast<double>(e1) / 4) + 19;
        tt1 = 1;
        check(exp2);
        if (exp2 > 200)
        {
            tt2 = 1;
            exp2 = exp2 + ceil(static_cast<double>(e1) / 9) + 21;
            check(exp2);
        }

        exp1 -= e1;
        check(exp1);
    }
    else if (e1 >= 80 && e1 <= 99)
    {
        tt1 = 1;
        tt2 = 1;
        exp2 = exp2 + ceil(static_cast<double>(e1) / 4) + 19;
        // cout << exp2 << endl;
        check(exp2);
        exp2 = exp2 + ceil(static_cast<double>(e1) / 9) + 21;
        // cout << exp2 << endl;
        check(exp2);
        if (exp2 > 400)
        {
            tt3 = 1;
            exp2 = exp2 + ceil(static_cast<double>(e1) / 16) + 17;
            check(exp2);
        }

        exp1 -= e1;
        check(exp1);
    }

    if (tt1 == 1 && tt2 == 1 && tt3 == 1)
    {
        // cout << " 3sk";
        exp2 = exp2 + ceil(static_cast<double>(exp2) * 15 / 100);
        check(exp2);
    }

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // Calculate the probability P1
    double P1;

    if (E2 < 0 || E2 > 99)
        {
        return -99;
        }
    check(EXP1);
    healthpoints(HP1);
    money(M1);

    float S = nearestPerfectSquare(EXP1);

    if (EXP1 >= S)
    {
        P1 = 100; // 100%
    }
    else
    {
        P1 = (EXP1 / S + 80) / 123.0;
    }

    int c = M1 * 0.5;
    for (int i = 0; i < 100; i++)
    {
        // So LE
        if (E2 % 2 == 1)
        {
            if (M1 > c)
            {
                if (HP1 < 200)
                {
                    float e = (HP1 + HP1 * 0.3);
                    healthpoints(HP1);
                    HP1 = ceil(e);
                    healthpoints(HP1);
                    M1 -= 150;
                    money(M1);
                }
                else
                {
                    float e = (HP1 + HP1 * 0.1);
                    healthpoints(HP1);
                    HP1 = ceil(e);
                    healthpoints(HP1);
                    M1 -= 70;
                    money(M1);
                }
            }
            else
            {
                break;
            }

            if (M1 > c)
            {
                if (EXP1 < 400)
                {
                    M1 -= 200;
                }
                else
                {
                    M1 -= 120;
                }
                float f = (1.13 * EXP1);
                check(EXP1);
                EXP1 = ceil(f);
                check(EXP1);
            }
            else
            {
                break;
            }

            if (M1 > c)
            {
                int m;

                if (EXP1 < 300)
                {
                    m = 100;
                }
                else
                {
                    m = 120;
                }
                M1 -= m;
                money(M1);
                float f = (0.9 * EXP1);
                EXP1 = ceil(f);
                check(EXP1);
            }
            else
            {
                break;
            }
        }
        // so CHAN
        else
        {
            // gach dau dong 1
            if (HP1 < 200)
            {
                float e = (HP1 + HP1 * 0.3);
                HP1 = ceil(e);
                healthpoints(HP1);
                M1 -= 150;
                money(M1);
                if (M1 == 0)
                {
                    break;
                }
            }
            else
            {
                float e = (HP1 * 1.1);
                HP1 = ceil(e);
                healthpoints(HP1);
                M1 -= 70;
                money(M1);
                if (M1 == 0)
                {
                    break;
                }
            }
            // gach dau dong 2
            if (EXP1 < 400)
            {
                M1 -= 200;
                money(M1);
                if (M1 == 0)
                {
                    break;
                }
            }
            else
            {
                M1 -= 120;
                money(M1);
                if (M1 == 0)
                {
                    break;
                }
            }
            float f = (1.13 * EXP1);
            EXP1 = ceil(f);
            check(EXP1);

            // gach dau dong 3
            int m;
            if (EXP1 < 300)
            {
                m = 100;
            }
            else
            {
                m = 120;
            }
            M1 -= m;
            money(M1);
            float z = (0.9 * EXP1);
            EXP1 = ceil(z);
            check(EXP1);
            if (M1 == 0)
            {
                break;
            }

            EXP1 = ceil(f);
            check(EXP1);
            float e = (0.83 * HP1);
            HP1 = ceil(e);
            healthpoints(HP1);
            float u = (1.17 * EXP1);
            EXP1 = ceil(u);
            check(EXP1);

            break;
        }
    }
    check(EXP1);
    float e = (0.83 * HP1);
    HP1 = ceil(e);
    healthpoints(HP1);
    float f = (1.17 * EXP1);
    EXP1 = ceil(f);
    check(EXP1);

    double P2 = 0;
    if (EXP1 >= S)
    {
        P2 = 100; // 100%
    }
    else
    {
        P2 = (EXP1 / S + 80) / 123.0;
    }

    // 3
    int arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int P3;
    if (E2 < 10)
    {
        int P3 = arr[E2];
    }
    else
    {
        int so = E2;
        while (so >= 10)
        {
            so = helper(so);
        }

        P3 = arr[so];
    }

    double P = 0;
    if (P1 == 100 && P2 == 100 && P3 == 100)
    {
        float f = (0.75 * EXP1);
        EXP1 = ceil(f);
        check(EXP1);
    }
    else
    {
        P = (P1 + P2 + P3) / 3;
    }

    if (P < 50)
    {
        float e = (HP1 * 0.85);
        HP1 = ceil(e);
        healthpoints(HP1);
        float f = (EXP1 * 1.15);
        EXP1 = ceil(f);
        check(EXP1);
    }
    else
    {
        float e = (HP1 * 0.9);
        HP1 = ceil(e);
        healthpoints(HP1);
        float f = (EXP1 * 1.2);
        EXP1 = ceil(f);
        check(EXP1);
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    // DIEU KIEN
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }
    healthpoints(HP1);
    check(EXP1);
    healthpoints(HP2);
    check(EXP2);

    // Khoi tao Ma Tran
    int Bando[10][10];
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
            Bando[i][j] = ((E3 * j) + (i * 2)) * (i - j);
    }

    
    int viTrii = 0;
    int viTrij = 0;
    int counti = 0;
    int countj = 0;
    int SaWpoint = 0;
    int TaxiPoint = 0;
    
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (Bando[i][j] > (E3 * 2))
                counti++;
            if (Bando[i][j] < (-1 * E3))
                countj++;
        }
    }

    while (counti * 1.0 / 10 >= 1)
    {
        counti = counti % 10 + (counti - counti % 10) * 1.0 / 10;
    }

    while (countj * 1.0 / 10 >= 1)
    {
        countj = countj % 10 + (countj - countj % 10) * 1.0 / 10;
    }

    viTrii = counti;
    viTrij = countj;

    TaxiPoint = Bando[viTrii][viTrij];
    int max = Bando[viTrii][viTrij];
    
    int hieu = abs(viTrii - viTrij);

    
    int m = viTrii, n = viTrij;
    while (m >= 0 && n >= 0 && abs(m - n) == hieu)
    {
        if (Bando[m][n] > max)
            max = Bando[m][n];
        m--;
        n--;
    }

    m = viTrii;
    n = viTrij;
    while (m < 10 && n < 10 && abs(m - n) == hieu)
    {
        if (Bando[m][n] > max)
            max = Bando[m][n];
        m++;
        n++;
    }

    
    int tong = viTrii + viTrij;

    
    m = viTrii;
    n = viTrij;
    while (m < 10 && n >= 0 && m + n == tong)
    {
        if (Bando[m][n] > max)
            max = Bando[m][n];
        m++;
        n--;
    }
    
    m = viTrii;
    n = viTrij;
    while (m >= 0 && n < 10 && m + n == tong)
    {
        if (Bando[m][n] > max)
            max = Bando[m][n];
        m--;
        n++;
    }

    SaWpoint = max;

    if (abs(TaxiPoint) > SaWpoint)
    {
        max = TaxiPoint;
        EXP1 = ceil(EXP1 * 88.0 / 100);
        EXP2 = ceil(EXP2 * 88.0 / 100);
        HP1 = ceil(HP1 * 90.0 / 100);
        HP2 = ceil(HP2 * 90.0 / 100);
    }
    else
    {
        max = SaWpoint;
        EXP1 = ceil(EXP1 * 112.0 / 100);
        EXP2 = ceil(EXP2 * 112.0 / 100);
        HP1 = ceil(HP1 * 110.0 / 100);
        HP2 = ceil(HP2 * 110.0 / 100);
    }

    healthpoints(HP1);
    check(EXP1);
    healthpoints(HP2);
    check(EXP2);

    return max;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    size_t pos = std::string(email).find('@');
    std::string se = std::string(email).substr(0, pos);

    if (strlen(s) < 8)
    {
        return -1;
    }
    if (strlen(s) > 20)
    {
        return -2;
    }

    size_t sePos = std::string(s).find(se);
    if (sePos != std::string::npos)
    {
        return -(300 + sePos);
    }

    bool flag = 0;
    for (const char *ptr = s; *ptr != '\0'; ++ptr)
    {
        char c = *ptr;
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!')
        {
            flag = true;
            break;
        }
    }

    if (flag == 0)
    {
        return -5;
    }

    for (size_t i = 0; i < strlen(s) - 2; ++i)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            return -(400 + i);
        }
    }

    return -10;
}
// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)

// TODO: Complete this function
{
    int maxFreq = 0;
    int maxLength = 0;
    int maxIndex = 0;

    for (int i = 0; i < num_pwds; ++i)
    {
        int freq = 0;
        for (int j = 0; j < num_pwds; ++j)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                freq++;
            }
        }

        int len = strlen(arr_pwds[i]);
        if (freq > maxFreq || (freq == maxFreq && len > maxLength))
        {
            maxFreq = freq;
            maxLength = len;
            maxIndex = i;
        }
    }

    return maxIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////