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

int myCeil(double num)
{
    int inum = (int)num;
    if (num > inum)
    {
        return inum + 1;
    }
    return inum;
}

int myAbs(int num)
{
    if (num < 0)
    {
        return -num;
    }
    return num;
}

int sumDigits(int num)
{
    if (num < 10)
    {
        return num;
    }
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sumDigits(sum);
}

int limitHP(int &HP)
{
    if (HP < 0)
    {
        HP = 0;
    }
    else if (HP > 666)
    {
        HP = 666;
    }
    HP = myCeil(HP);
    return HP;
}

int limitEXP(int &EXP)
{
    if (EXP < 0)
    {
        EXP = 0;
    }
    else if (EXP > 600)
    {
        EXP = 600;
    }
    EXP = myCeil(EXP);
    return EXP;
}

int limitM(int &M)
{
    if (M < 0)
    {
        M = 0;
    }
    else if (M > 3000)
    {
        M = 3000;
    }
    M = myCeil(M);
    return M;
}

int getNearestSquare(int num)
{
    int i = 0;
    while (i * i <= num)
    {
        i++;
    }
    if (i * i - num < num - (i - 1) * (i - 1))
    {
        return i * i;
    }
    else
    {
        return (i - 1) * (i - 1);
    }
}

double calcProp(int EXP)
{
    int s = getNearestSquare(EXP);
    double p;
    if (EXP >= s)
    {
        p = 1;
    }
    else
    {
        p = ((double)EXP / s + 80) / 123;
    }
    return p;
}

int getMaxBothDiagonal(int A[10][10], int i, int j)
{
    int max = 0;
    int n = 10;
    for (int k = 0; k < n; k++)
    {
        // Left diagonal
        if (i + k < n && j + k < n)
        {
            if (A[i + k][j + k] > max)
            {
                max = A[i + k][j + k];
            }
        }
        if (i - k >= 0 && j - k >= 0)
        {
            if (A[i - k][j - k] > max)
            {
                max = A[i - k][j - k];
            }
        }
        // Right diagonal
        if (i + k < n && j - k >= 0)
        {
            if (A[i + k][j - k] > max)
            {
                max = A[i + k][j - k];
            }
        }
        if (i - k >= 0 && j + k < n)
        {
            if (A[i - k][j + k] > max)
            {
                max = A[i - k][j + k];
            }
        }
    }
    return myAbs(max);
}

bool stringCompare(const char *s1, const char *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            return false;
        }
        i++;
    }
    if (s1[i] != s2[i])
    {
        return false;
    }
    return true;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }
    limitEXP(exp1);
    limitEXP(exp2);
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
            exp2 += 29 + 45 + 75;
            break;
        default:
            break;
        }
        limitEXP(exp2);

        int d = e1 * 3 + exp1 * 7;
        if (d % 2 == 0)
        {
            exp1 = myCeil(exp1 + (double)d / 200); // Afghanistan
        }
        else
        {
            exp1 = myCeil(exp1 - (double)d / 100); // Iraq
        }
        limitEXP(exp1);
    }
    else if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        { // info 1
            exp2 += myCeil((double)e1 / 4 + 19);
        }
        else if (e1 >= 20 && e1 <= 49)
        { // info 2
            exp2 += myCeil((double)e1 / 9 + 21);
        }
        else if (e1 >= 50 && e1 <= 65)
        { // info 3
            exp2 += myCeil((double)e1 / 16 + 17);
        }
        else if (e1 >= 66 && e1 <= 79)
        { // info 4
            exp2 += myCeil((double)e1 / 4 + 19);
            if (exp2 > 200)
            {
                exp2 += myCeil((double)e1 / 9 + 21);
            }
        }
        else if (e1 >= 80 && e1 <= 99)
        { // info 5
            exp2 += myCeil((double)e1 / 4 + 19);
            exp2 += myCeil((double)e1 / 9 + 21);
            if (exp2 > 400)
            {
                exp2 += myCeil((double)e1 / 16 + 17);
                exp2 += myCeil(exp2 * 0.15);
            }
        }
        limitEXP(exp2);

        exp1 -= e1;
        limitEXP(exp1);
    }

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }
    limitHP(HP1);
    limitEXP(EXP1);
    limitM(M1);
    // 1st road: No money spent
    double p1 = calcProp(EXP1);

    // 2nd road
    int limitMoney = myCeil((double)M1 * 0.5);
    int moneySpent = 0;
    while (true)
    {
        // Food
        if ((moneySpent > limitMoney && E2 % 2 == 1) || M1 == 0)
        {
            break;
        }
        if (HP1 < 200)
        {
            HP1 += myCeil((double)HP1 * 0.3);
            M1 -= 150;
            moneySpent += 150;
        }
        else
        {
            HP1 += myCeil((double)HP1 * 0.1);
            M1 -= 70;
            moneySpent += 70;
        }
        limitHP(HP1);
        limitM(M1);
        if ((moneySpent > limitMoney && E2 % 2 == 1) || M1 == 0)
        {
            break;
        }

        // Transportation
        if (EXP1 < 400)
        {
            M1 -= 200;
            moneySpent += 200;
        }
        else
        {
            M1 -= 120;
            moneySpent += 120;
        }
        EXP1 += myCeil((double)EXP1 * 0.13);
        limitM(M1);
        limitEXP(EXP1);
        if ((moneySpent > limitMoney && E2 % 2 == 1) || M1 == 0)
        {
            break;
        }

        // Help the homeless
        if (EXP1 < 300)
        {
            M1 -= 100;
            moneySpent += 100;
        }
        else
        {
            M1 -= 120;
            moneySpent += 120;
        }
        EXP1 = myCeil(EXP1 - (double)EXP1 * 0.1);
        limitM(M1);
        limitEXP(EXP1);
        if ((moneySpent > limitMoney && E2 % 2 == 1) || M1 == 0)
        {
            break;
        }

        // Only repeat if E2 is odd
        if (E2 % 2 == 0)
        {
            break;
        }
    }

    // End of the 2nd road
    HP1 = myCeil(HP1 - (double)HP1 * 0.17);
    limitHP(HP1);
    EXP1 = myCeil(EXP1 + (double)EXP1 * 0.17);
    limitEXP(EXP1);
    double p2 = calcProp(EXP1);

    // 3rd road
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 < 10)
    {
        i = E2;
    }
    else
    {
        i = (E2 % 10 + E2 / 10) % 10;
    }
    double p3 = (double)P[i] / 100;

    if (p1 == 1 && p2 == 1 && p3 == 1)
    {
        EXP1 = myCeil(EXP1 - (double)EXP1 * 0.25);
    }
    else
    {
        double avgProp = (p1 + p2 + p3) / 3;
        if (avgProp < 0.5)
        {
            HP1 = myCeil(HP1 - (double)HP1 * 0.15);
            EXP1 = myCeil(EXP1 + (double)EXP1 * 0.15);
        }
        else
        {
            HP1 = myCeil(HP1 - (double)HP1 * 0.1);
            EXP1 = myCeil(EXP1 + (double)EXP1 * 0.2);
        }
    }
    limitHP(HP1);
    limitEXP(EXP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }
    limitHP(HP1);
    limitEXP(EXP1);
    limitHP(HP2);
    limitEXP(EXP2);
    // Create 10x10 array
    int taxiStrengths[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            taxiStrengths[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    int i = 0, j = 0;
    for (int k = 0; k < 10; k++)
    {
        for (int l = 0; l < 10; l++)
        {
            if (taxiStrengths[k][l] > E3 * 2)
            {
                i++;
            }
            if (taxiStrengths[k][l] < -E3)
            {
                j++;
            }
        }
    }
    i = sumDigits(i);
    j = sumDigits(j);

    int detectiveScore = getMaxBothDiagonal(taxiStrengths, i, j);
    if (myAbs(taxiStrengths[i][j]) > detectiveScore)
    {
        // both exp1 and exp2 are reduced by 12%
        EXP1 = myCeil(EXP1 - (double)EXP1 * 0.12);
        EXP2 = myCeil(EXP2 - (double)EXP2 * 0.12);

        // both hp1 and hp2 are reduced by 10%
        HP1 = myCeil(HP1 - (double)HP1 * 0.1);
        HP2 = myCeil(HP2 - (double)HP2 * 0.1);

        return taxiStrengths[i][j];
    }
    else
    {
        // both exp1 and exp2 are increased by 12%
        EXP1 = myCeil(EXP1 + (double)EXP1 * 0.12);
        EXP2 = myCeil(EXP2 + (double)EXP2 * 0.12);
        limitEXP(EXP1);
        limitEXP(EXP2);

        // both hp1 and hp2 are increased by 10%
        HP1 = myCeil(HP1 + (double)HP1 * 0.1);
        HP2 = myCeil(HP2 + (double)HP2 * 0.1);
        limitHP(HP1);
        limitHP(HP2);

        return detectiveScore;
    }

    return -1;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }

    // Check password length
    if (len < 8)
        return -1;
    else if (len > 20)
        return -2;

    // Check if the password contains the email address part before the @ character
    int emailLen = 0;
    while (email[emailLen] != '@')
    {
        emailLen++;
    }
    for (int i = 0; i <= len - emailLen; i++)
    {
        bool found = true;
        for (int j = 0; j < emailLen; j++)
        {
            if (s[i + j] != email[j])
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            return -(300 + i);
        }
    }

    // Check if the password contains more than 2 consecutive characters that are the same
    for (int i = 0; i < len - 2; i++)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            return -(400 + i);
        }
    }

    // Check if the password contains at least 1 special character
    bool hasSpecialChar = false;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar)
    {
        return -5;
    }

    // Check if the password contains other characters
    for (int i = 0; i < len; i++)
    {
        if (!((s[i] >= '0' && s[i] <= '9') ||
              (s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= 'A' && s[i] <= 'Z') ||
              s[i] == '@' ||
              s[i] == '#' ||
              s[i] == '%' ||
              s[i] == '$' ||
              s[i] == '!'))
        {
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int maxCount = 0;
    int maxLen = 0;
    int maxIndex = -1;
    for (int i = 0; i < num_pwds; i++)
    {
        int count = 0;
        int len = 0;
        while (arr_pwds[i][len] != '\0')
        {
            len++;
        }
        for (int j = 0; j < num_pwds; j++)
        {
            if (stringCompare(arr_pwds[i], arr_pwds[j]))
            {
                count++;
            }
        }
        if (count > maxCount || (count == maxCount && len > maxLen))
        {
            maxCount = count;
            maxLen = len;
            maxIndex = i;
        }
    }
    return maxIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////