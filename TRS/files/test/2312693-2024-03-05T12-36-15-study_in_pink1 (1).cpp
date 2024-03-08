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

int cHP(int HP)
{
    // check hp
    if (HP > 666)
        HP = 666;
    if (HP < 0)
        HP = 0;
    return HP;
}

int cEXP(int EXP)
{
    // check exp
    if (EXP > 600)
        EXP = 600;
    if (EXP < 0)
        EXP = 0;
    return EXP;
}

int cM(int M)
{
    // check money
    if (M > 3000)
        M = 3000;
    if (M < 0)
        M = 0;
    return M;
}

int chialen(int num1, int num2)
{
    float d = num1 * 1.0 / num2;
    if (d - int(d) != 0)
        return int(d) + 1;
    else
        return d;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function

    exp1 = cEXP(exp1);
    exp2 = cEXP(exp2);

    if ((e1 < 0) || (e1 > 99))
        return -99;

    switch (e1)
    {
    case 0:
        exp2 += 29;
        exp2 = cEXP(exp2);
        break;
    case 1:
        exp2 += 45;
        exp2 = cEXP(exp2);
        break;
    case 2:
        exp2 += 75;
        exp2 = cEXP(exp2);
        break;
    case 3:
        exp2 += 29 + 45 + 75;
        exp2 = cEXP(exp2);
        break;
    default:
        if (e1 <= 19)
        {
            exp2 += chialen(e1, 4) + 19;
            exp2 = cEXP(exp2);
        }
        else if (e1 <= 49)
        {
            exp2 += chialen(e1, 9) + 21;
            exp2 = cEXP(exp2);
        }
        else if (e1 <= 65)
        {
            exp2 += chialen(e1, 16) + 17;
            exp2 = cEXP(exp2);
        }
        else if (e1 <= 79)
        {
            exp2 += chialen(e1, 4) + 19;
            exp2 = cEXP(exp2);
            if (exp2 > 200)
                exp2 += chialen(e1, 9) + 21;
            exp2 = cEXP(exp2);
        }
        else
        {
            exp2 += chialen(e1, 4) + 19;
            exp2 = cEXP(exp2);
            exp2 += chialen(e1, 9) + 21;
            exp2 = cEXP(exp2);
            if (exp2 > 400)
            {
                exp2 += chialen(e1, 16) + 17;
                exp2 = cEXP(exp2);
                exp2 += chialen(exp2 * 15, 100);
                exp2 = cEXP(exp2);
            }
        }
        exp1 -= e1;
        break;
    }
    exp1 = cEXP(exp1);

    if (e1 <= 3)
    {
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            exp1 += chialen(D, 200);
        else
            exp1 -= D / 100;
    }
    exp1 = cEXP(exp1);

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    M1 = cM(M1);
    EXP1 = cEXP(EXP1);
    HP1 = cHP(HP1);

    if ((E2 < 0) || (E2 > 99))
        return -99;

    // con duong 1
    int rootexp = sqrt(EXP1);
    float p1;
    if (abs(rootexp * rootexp - EXP1) > abs((rootexp + 1) * (rootexp + 1) - EXP1))
        rootexp++;
    rootexp *= rootexp;
    if (rootexp <= EXP1)
        p1 = 1;
    else
        p1 = ((EXP1 * 1.0 / rootexp) + 80) / 123;

    // con duong 2
    if (E2 % 2 == 0)
    {
        // hanh dong 1
        if (M1 > 0)
        {
            if (HP1 < 200)
            {
                HP1 = chialen(HP1 * 130, 100);
                M1 -= 150;
            }
            else
            {
                HP1 = chialen(HP1 * 110, 100);
                M1 -= 70;
            }
            M1 = cM(M1);
            EXP1 = cEXP(EXP1);
            HP1 = cHP(HP1);
        }
        // hanh dong 2
        if (M1 > 0)
        {
            if (EXP1 < 400)
                M1 -= 200;
            else
                M1 -= 120;
            EXP1 = chialen(EXP1 * 113, 100);

            M1 = cM(M1);
            EXP1 = cEXP(EXP1);
            HP1 = cHP(HP1);
        }
        // hanh dong 3
        if (M1 > 0)
        {
            if (EXP1 < 300)
                M1 -= 100;
            else
                M1 -= 120;

            EXP1 = chialen(EXP1 * 90, 100);

            M1 = cM(M1);
            EXP1 = cEXP(EXP1);
            HP1 = cHP(HP1);
        }
    }
    else
    {
        int tempM1 = M1;
        while (M1 >= tempM1 * 1.0 / 2)
        {
            if (M1 >= tempM1 * 1.0 / 2)
            {
                // hanh dong 1
                if (HP1 < 200)
                {
                    HP1 = chialen(HP1 * 130, 100);
                    M1 -= 150;
                }
                else
                {
                    HP1 = chialen(HP1 * 110, 100);
                    M1 -= 70;
                }

                M1 = cM(M1);
                EXP1 = cEXP(EXP1);
                HP1 = cHP(HP1);
            }
            else
                break;
            // hanh dong 2
            if (M1 >= tempM1 * 1.0 / 2)
            {
                if (EXP1 < 400)
                    M1 -= 200;
                else
                    M1 -= 120;
                EXP1 = chialen(EXP1 * 113, 100);

                M1 = cM(M1);
                EXP1 = cEXP(EXP1);
                HP1 = cHP(HP1);
            }
            else
                break;
            // hanh dong 3
            if (M1 >= tempM1 * 1.0 / 2)
            {
                if (EXP1 < 300)
                    M1 -= 100;
                else
                    M1 -= 120;
                EXP1 = chialen(EXP1 * 90, 100);
                M1 = cM(M1);
                EXP1 = cEXP(EXP1);
                HP1 = cHP(HP1);
            }
            else
                break;
        }
    }
    HP1 = chialen(HP1 * 83, 100);
    EXP1 = chialen(EXP1 * 117, 100);
    M1 = cM(M1);
    EXP1 = cEXP(EXP1);
    HP1 = cHP(HP1);

    rootexp = sqrt(EXP1);
    float p2;
    if (abs(rootexp * rootexp - EXP1) > abs((rootexp + 1) * (rootexp + 1) - EXP1))
        rootexp++;
    rootexp *= rootexp;
    if (rootexp <= EXP1)
        p2 = 1;
    else
        p2 = (EXP1 * 1.0 / rootexp + 80) / 123;

    // con duong 3
    int mangxacsuat[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float p3;
    if (E2 < 9)
        p3 = mangxacsuat[E2] * 1.0 / 100;
    else
        p3 = mangxacsuat[(E2 / 10 + E2 % 10) % 10] * 1.0 / 100;

    float ptb = (p1 + p2 + p3) / 3;

    if (ptb >= 1)
        EXP1 = chialen(EXP1 * 75, 100);
    else if (ptb < 0.5)
    {
        EXP1 = chialen(EXP1 * 115, 100);
        HP1 = chialen(HP1 * 85, 100);
    }
    else
    {
        EXP1 = chialen(EXP1 * 120, 100);
        HP1 = chialen(HP1 * 90, 100);
    }
    M1 = cM(M1);
    EXP1 = cEXP(EXP1);
    HP1 = cHP(HP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if ((E3 < 0) || (E3 > 99))
        return -99;
    EXP1 = cEXP(EXP1);
    HP1 = cHP(HP1);
    EXP2 = cEXP(EXP2);
    HP2 = cHP(HP2);
    int bando[10][10] = {}, bandotrai[10][10], bandophai[10][10];
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            bando[i][j] = (E3 * j + i * 2) * (i - j);
    /*for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
        {
            bandotrai[i][j] = -INT_MAX;
            bandophai[i][j] = -INT_MAX;
        }

    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
        {
            bandotrai[i][j] = max(bando[i][j], bandotrai[i - 1][j - 1]);
        }

    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
        {
            bandophai[i][j] = max(bando[i][j], bandophai[i - 1][j + 1]);
        }

    for (int i = 8; i >= 0; i--)
        for (int j = 8; j >= 0; j--)
        {
            bandotrai[i][j] = bandotrai[i + 1][j + 1];
        }

    for (int i = 8; i >= 0; i--)
        for (int j = 9; j >= 1; j--)
        {
            bandophai[i][j] = bandophai[i + 1][j - 1];
        }*/

    int demhang = 0, demcot = 0;
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            if (bando[i][j] > E3 * 2)
                demhang++;
            else if (bando[i][j] < -E3)
                demcot++;

    while (demhang > 9)
        demhang = demhang / 10 + demhang % 10;
    while (demcot > 9)
        demcot = demcot / 10 + demcot % 10;
    int tempI = demhang, tempJ = demcot;
    int ma = bando[tempI][tempJ];
    while (tempI < 10 && tempJ < 10)
    {
        if (ma < bando[tempI][tempJ])
        {
            ma = bando[tempI][tempJ];
        }
        tempI++;
        tempJ++;
    }
    tempI = demhang;
    tempJ = demcot;
    while (tempI >= 0 && tempJ >= 0)
    { 
        if (ma < bando[tempI][tempJ])
        {
            ma = bando[tempI][tempJ];
        }
        tempI--;
        tempJ--;
    }
    tempI = demhang;
    tempJ = demcot;
    while (tempI < 10 && tempJ >= 0)
    { 
        if (ma < bando[tempI][tempJ])
        {
            ma = bando[tempI][tempJ];
        }
        tempI++;
        tempJ--;
    }
    tempI = demhang;
    tempJ = demcot;
    while (tempI >= 0 && tempJ < 10)
    { 
        if (ma < bando[tempI][tempJ])
        {
            ma = bando[tempI][tempJ];
        }
        tempI--;
        tempJ++;
    }

    if (ma < abs(bando[demhang][demcot]))
    {
        EXP1 = chialen(EXP1 * 88, 100);
        HP1 = chialen(HP1 * 90, 100);
        EXP2 = chialen(EXP2 * 88, 100);
        HP2 = chialen(HP2 * 90, 100);
        EXP1 = cEXP(EXP1);
        HP1 = cHP(HP1);
        EXP2 = cEXP(EXP2);
        HP2 = cHP(HP2);
        return bando[demhang][demcot];
    }
    else
    {
        EXP1 = chialen(EXP1 * 112, 100);
        HP1 = chialen(HP1 * 110, 100);
        EXP2 = chialen(EXP2 * 112, 100);
        HP2 = chialen(HP2 * 110, 100);
        EXP1 = cEXP(EXP1);
        HP1 = cHP(HP1);
        EXP2 = cEXP(EXP2);
        HP2 = cHP(HP2);
        return ma;
    }

    return -1;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    int dai = strlen(s);
    char tempxau[100];
    char tempxau1[100];
    if (dai < 8)
        return -1;
    if (dai > 20)
        return -2;
    int dai2 = 0;

    for (int i = 0; i < strlen(email); i++)
        if (email[i] != '@')
        {
            tempxau[i] = email[i];
        }
        else
        {
            dai2 = i;
            break;
        }

    if (dai2 == 0)
        return -300;

    int dem = 0;

    for (int i = 0; i < dai; i++)
    {
        dem = 0;
        for (int j = i; j < i + dai2; j++)
        {
            tempxau1[dem] = s[j];
            dem++;
        }
        dem = 0;
        for (int j = 0; j < dai2; j++)
        {

            if (tempxau1[j] != tempxau[j])
                break;
            else
                dem++;
        }
        if (dem == dai2)
            return -(300 + i);
    }

    dem = 0;
    for (int i = 0; i < dai; i++)
    {
        if (s[i] == s[i + 1])
            dem++;
        else
            dem = 0;
        if (dem == 2)
            return -(400 + i - 1);
    }

    dem = 0;
    for (int i = 0; i <= dai; i++)
    {
        if ((s[i] == '@') || (s[i] == '#') || (s[i] == '%') || (s[i] == '$') || (s[i] == '!'))
            dem++;
    }
    if (dem == 0)
        return -5;

    for (int i = 0; i < dai; i++)
    {
        if (!((s[i] <= 'z') && (s[i] >= 'a')))
            if (!((s[i] >= 'A') && (s[i] <= 'Z')))
                if (!((s[i] >= '0') && (s[i] <= '9')))
                    if (!(s[i] == '@') && !(s[i] == '#') && !(s[i] == '%') && !(s[i] == '$') && !(s[i] == '!'))
                        return i;
    }
    return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int mdem = 0;
    int mdai = 0;
    int mk = -1;
    for (int i = 0; i < num_pwds; i++)
    {
        int dem = 0;
        int dai = strlen(arr_pwds[i]);
        for (int j = 0; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                dem++;
            }
        }
        if (dem > mdem || (dem == mdem && dai > mdai))
        {
            mdem = dem;
            mdai = dai;
            mk = i;
        }
    }
    return mk;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
