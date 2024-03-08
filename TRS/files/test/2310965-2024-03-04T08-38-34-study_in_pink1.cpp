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
    // DO NOT MODIFY THIS FUNCTION
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

void checkHP(int &HP)
{
    if (HP < 0)
        HP = 0;
    else if (HP > 666)
        HP = 666;
}

void checkEXP(int &EXP)
{
    if (EXP < 0)
        EXP = 0;
    else if (EXP > 600)
        EXP = 600;
}

void checkM(int &M)
{
    if (M < 0)
        M = 0;
    else if (M > 3000)
        M = 3000;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    if (e1 < 0 || e1 > 99)
        return -99;

    if (e1 >= 0 && e1 <= 3)
    {
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
            exp2 += 149;
            break;
        }
        int D;
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            exp1 = ceil(exp1 + D / 200.0);
        else
            exp1 = ceil(exp1 - D / 100.0);
    }
    else if (e1 <= 99)
    {
        if (e1 <= 19)
            exp2 += ceil(e1 / 4.0 + 19);
        else if (e1 <= 49)
            exp2 += ceil(e1 / 9.0 + 21);
        else if (e1 <= 65)
            exp2 += ceil(e1 / 16.0 + 17);
        else if (e1 <= 79)
        {
            exp2 += ceil(e1 / 4.0 + 19);
            if (exp2 > 200)
                exp2 += ceil(e1 / 9.0 + 21);
        }
        else if (e1 <= 99)
        {
            exp2 += ceil(e1 / 4.0 + 19);
            exp2 += ceil(e1 / 9.0 + 21);
            if (exp2 > 400)
            {
                exp2 += ceil(e1 / 16.0 + 17);
                exp2 = ceil(exp2 * 1.15);
            }
        }
        exp1 -= e1;
    }
    checkEXP(exp1);
    checkEXP(exp2);

    return exp1 + exp2;
}

// Task 2
int findSquareNumber(int EXP1)
{
    int i = sqrt(EXP1), S = 0;
    int PreNum = i * i;
    int PostNum = (i + 1) * (i + 1);
    if (abs(PreNum - EXP1) <= abs(PostNum - EXP1))
        S = PreNum;
    else
        S = PostNum;
    return S;
}

bool checkPaid(int initialM, long double totalCost)
{
    long double baseMoney = initialM * 0.5;
    if (totalCost > baseMoney)
        return true;
    else
        return false;
}

void roadEvent1(int &HP1, int &M1, long double &totalCost)
{
    if (HP1 < 200)
    {
        HP1 = ceil(HP1 * 13.0 / 10);
        M1 -= 150;
        totalCost += 150;
    }
    else
    {
        HP1 = ceil(HP1 * 11.0 / 10);
        M1 -= 70;
        totalCost += 70;
    }
    checkHP(HP1);
    checkM(M1);
}

void roadEvent2(int &EXP1, int &M1, long double &totalCost)
{
    if (EXP1 < 400)
    {
        M1 -= 200;
        totalCost += 200;
    }
    else
    {
        M1 -= 120;
        totalCost += 120;
    }
    EXP1 = ceil(EXP1 * 113.0 / 100.0);
    checkEXP(EXP1);
    checkM(M1);
}

void roadEvent3(int &EXP1, int &M1, long double &totalCost)
{
    if (EXP1 < 300)
    {
        M1 -= 100;
        totalCost += 100;
    }
    else
    {
        M1 -= 120;
        totalCost += 120;
    }
    EXP1 = ceil(EXP1 * 9.0 / 10);
    checkEXP(EXP1);
    checkM(M1);
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (E2 < 0 || E2 > 99)
        return -99;

    int S = findSquareNumber(EXP1);
    long double P1 = 0;
    if (EXP1 >= S)
        P1 = 100;
    else
        P1 = (EXP1 * 1.0 / S + 80) / 123.0 * 100.0;

    long double totalCost = 0;
    int initialM = M1;

    if (E2 % 2 != 0)
    {
        while (true)
        {
            if (M1 == 0)
                break;
            roadEvent1(HP1, M1, totalCost);
            if (checkPaid(initialM, totalCost) || M1 == 0)
                break;
            roadEvent2(EXP1, M1, totalCost);
            if (checkPaid(initialM, totalCost) || M1 == 0)
                break;
            roadEvent3(EXP1, M1, totalCost);
            if (checkPaid(initialM, totalCost) || M1 == 0)
                break;
        }
    }
    else
    {
        while (true)
        {

            if (M1 == 0)
                break;
            roadEvent1(HP1, M1, totalCost);
            if (M1 == 0)
                break;
            roadEvent2(EXP1, M1, totalCost);
            if (M1 == 0)
                break;
            roadEvent3(EXP1, M1, totalCost);
            if (M1 == 0)
                break;
            break;
        }
    }

    HP1 = ceil(HP1 * 83.0 / 100.0);
    EXP1 = ceil(EXP1 * 117.0 / 100.0);
    checkHP(HP1);
    checkEXP(EXP1);
    checkM(M1);

    S = findSquareNumber(EXP1);
    long double P2 = 0;
    if (EXP1 >= S)
        P2 = 100;
    else
        P2 = (EXP1 * 1.0 / S + 80) / 123.0 * 100.0;

    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = 0;
    if (E2 < 10)
        i = E2;
    else
        i = ((E2 / 10) + (E2 % 10)) % 10;
    long double P3 = P[i];

    if (P1 == 100 && P2 == 100 && P3 == 100)
    {
        EXP1 = ceil(EXP1 * 75.0 / 100.0);
    }
    else
    {
        double averP = 0;
        averP = (P1 + P2 + P3) / 3.0;
        if (averP < 50.0)
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
    checkHP(HP1);
    checkEXP(EXP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int findMaxVal(int matrix[][10], int i, int j)
{
    int maxVal = 0;
    // Right Diagonal
    for (int a = i, b = j; a <= 9 && b >= 0; a++, b--)
    {
        maxVal = maxVal > matrix[a][b] ? maxVal : matrix[a][b];
    }
    for (int a = i, b = j; a >= 0 && b <= 9; a--, b++)
    {
        maxVal = maxVal > matrix[a][b] ? maxVal : matrix[a][b];
    }
    // Left Diagonal
    for (int a = i, b = j; a <= 9 && b <= 9; a++, b++)
    {
        maxVal = maxVal > matrix[a][b] ? maxVal : matrix[a][b];
    }
    for (int a = i, b = j; a >= 0 && b >= 0; a--, b--)
    {
        maxVal = maxVal > matrix[a][b] ? maxVal : matrix[a][b];
    }
    return abs(maxVal);
}

void fixIndex(int &n)
{
    while (true)
    {
        if (n >= 10)
            n = (n / 10) + (n % 10);
        else
            break;
    }
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 < 0 || E3 > 99)
        return -99;
    int matrix[10][10] = {0};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    int mapSW[10][10] = {0};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            mapSW[i][j] = findMaxVal(matrix, i, j);
        }
    }
    int a = 0, b = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            a += (matrix[i][j] > E3 * 2) ? 1 : 0;
            b += (matrix[i][j] < -E3) ? 1 : 0;
        }
    }
    fixIndex(a);
    fixIndex(b);
    if (abs(matrix[a][b]) > mapSW[a][b])
    {
        EXP1 = ceil(EXP1 * 88.0 / 100.0);
        HP1 = ceil(HP1 * 9.0 / 10.0);
        EXP2 = ceil(EXP2 * 88.0 / 100.0);
        HP2 = ceil(HP2 * 9.0 / 10.0);
    }
    else
    {
        EXP1 = ceil(EXP1 * 112.0 / 100.0);
        HP1 = ceil(HP1 * 11.0 / 10.0);
        EXP2 = ceil(EXP2 * 112.0 / 100.0);
        HP2 = ceil(HP2 * 11.0 / 10.0);
    }
    checkHP(HP1);
    checkHP(HP2);
    checkEXP(EXP1);
    checkEXP(EXP2);

    return (abs(matrix[a][b]) > mapSW[a][b]) ? matrix[a][b] : mapSW[a][b];
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // Find se
    size_t pos = strchr(email, '@') - email;
    char se[pos + 1];
    strncpy(se, email, pos);
    se[pos] = '\0';

    // Length
    if (strlen(s) < 8)
    {
        return -1;
    }
    else if (strlen(s) > 20)
    {
        return -2;
    }

    // Check if s contain se
    const char *sei = strstr(s, se);
    if (sei != nullptr)
    {
        return -(300 + (int)(sei - s));
    }

    // Check if s contain more 2 char similar
    for (int i = 0; i < strlen(s) - 2; i++)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            return -(400 + i);
        }
    }

    // Check if s contain at least 1 char special
    const char *SpecChar = strpbrk(s, "@#%$!");
    if (SpecChar == nullptr)
    {
        return -5;
    }

    // The last one
    for (int i = 0; i < strlen(s); i++)
    {
        if (!((s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= 'A' && s[i] <= 'Z') ||
              (s[i] >= '0' && s[i] <= '9') ||
              (s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%' || s[i] == '!')))
            return i;
    }

    // End of Func: s is valid
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int count = 0;
    int length = 0;
    int index = -1;

    for (int i = 0; i < num_pwds; i++)
    {
        const char *passwordArr = arr_pwds[i];
        int countTemp = 0;
        for (int j = 0; j < num_pwds; j++)
        {
            if (strcmp(passwordArr, arr_pwds[j]) == 0)
            {
                countTemp += 1;
            }
        }
        if (count < countTemp || (count == countTemp && length < strlen(passwordArr)))
        {
            count = countTemp;
            index = i;
            length = strlen(passwordArr);
        }
    }

    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////