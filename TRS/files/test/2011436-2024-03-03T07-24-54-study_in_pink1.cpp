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

//// Helper functions
// hp related
int increaseHP(int &HP, double h)
{
    HP = min(666.0, ceil(HP + h));
    return HP;
}

int decreaseHP(int &HP, double h)
{
    HP = max(0.0, ceil(HP - h));
    return HP;
}

// exp related
int increaseEXP(int &EXP, double e)
{
    EXP = min(600.0, ceil(EXP + e));
    return EXP;
}

int decreaseEXP(int &EXP, double e)
{
    EXP = max(0.0, ceil(EXP - e));
    return EXP;
}

// money related
int increaseMoney(int &M, double m)
{
    M = min(3000.0, ceil(M + m));
    return M;
}

int decreaseMoney(int &M, double m)
{
    M = max(0.0, ceil(M - m));
    return M;
}

bool checkEventCode(int e)
{
    return e >= 0 && e <= 99;
}

//// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{

    // check e1
    if (!checkEventCode(e1))
    {
        return -99;
    }

    // first case
    if (e1 < 5)
    {

        // exp table
        switch (e1)
        {
        case 0:
            increaseEXP(exp2, 29);
            break;
        case 1:
            increaseEXP(exp2, 45);
            break;
        case 2:
            increaseEXP(exp2, 75);
            break;
        case 3:
            increaseEXP(exp2, 45 + 29 + 75);
            break;
        default:
            break;
        }

        // country deduction
        int d = e1 * 3 + exp1 * 7;

        if (d % 2)
            decreaseEXP(exp1, d / 100.0);
        else
            increaseEXP(exp1, d / 200.0);
    }

    // second case
    else
    {

        // exp table
        if (e1 >= 4 && e1 <= 19)
        {
            increaseEXP(exp2, e1 / 4.0 + 19);
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            increaseEXP(exp2, e1 / 9.0 + 21);
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            increaseEXP(exp2, e1 / 16.0 + 17);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            increaseEXP(exp2, e1 / 4.0 + 19);
            if (exp2 > 200)
                increaseEXP(exp2, e1 / 9.0 + 21);
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            increaseEXP(exp2, e1 / 4.0 + 19);
            increaseEXP(exp2, e1 / 9.0 + 21);
            if (exp2 > 400)
            {
                increaseEXP(exp2, e1 / 16.0 + 17);
                increaseEXP(exp2, exp2 * 0.15);
            }
        }

        // sherlock's exp decrease
        decreaseEXP(exp1, e1);
    }

    return exp1 + exp2;
}

//// Task 2
// nearest perfect square
int nearestPerfectSquare(int n)
{
    // square root as double
    double root = sqrt(n);

    // two case
    double floorCase = floor(root) * floor(root), ceilCase = ceil(root) * ceil(root);

    return (n - floorCase) < (ceilCase - n) ? floorCase : ceilCase;
}

double getProbability(int EXP1)
{

    int nearestSquare = nearestPerfectSquare(EXP1);

    if (EXP1 > nearestSquare)
    {
        return 1;
    }
    else
    {
        return (EXP1 * 1.0 / nearestSquare + 80) / 123.0;
    }
}

void buyFood(int &HP1, int &EXP1, int &M1, int E3, bool abruptStop)
{

    if (HP1 < 200)
    {
        increaseHP(HP1, HP1 * 0.3);
        decreaseMoney(M1, 150);
    }
    else
    {
        increaseHP(HP1, HP1 * 0.1);
        decreaseMoney(M1, 70);
    }
}

void travel(int &HP1, int &EXP1, int &M1, int E3, bool abruptStop)
{

    if (EXP1 < 400)
    {
        decreaseMoney(M1, 200);
    }
    else
    {
        decreaseMoney(M1, 120);
    }
    increaseEXP(EXP1, EXP1 * 0.13);
}

void metHomeless(int &HP1, int &EXP1, int &M1, int E3, bool abruptStop)
{

    if (EXP1 < 300)
    {
        decreaseMoney(M1, 100);
    }
    else
    {
        decreaseMoney(M1, 120);
    }
    decreaseEXP(EXP1, EXP1 * 0.1);
}

int thirdRoad(int E3)
{

    int p[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

    if (E3 < 10)
    {
        return p[E3];
    }
    else
    {
        return p[(E3 % 10 + E3 / 10) % 10];
    }
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E3)
{

    // check e
    if (!checkEventCode(E3))
    {
        return -99;
    }

    // first road
    double p1 = getProbability(EXP1);

    // two cases of second road
    if (M1 > 0)
    {
        int startMoney = M1;
        if (E3 % 2)
        {
            while (M1 > startMoney * 0.5)
            {
                buyFood(HP1, EXP1, M1, E3, false);
                if (M1 > startMoney * 0.5)
                    travel(HP1, EXP1, M1, E3, false);

                if (M1 > startMoney * 0.5)
                    metHomeless(HP1, EXP1, M1, E3, false);
            }
        }
        else
        {
            buyFood(HP1, EXP1, M1, E3, false);
            if (M1 > 0)
            {
                travel(HP1, EXP1, M1, E3, false);
            }
            if (M1 > 0)
            {
                metHomeless(HP1, EXP1, M1, E3, false);
            }
        }
    }
    decreaseHP(HP1, HP1 * 0.17);
    increaseEXP(EXP1, EXP1 * 0.17);
    double p2 = getProbability(EXP1);

    // third road
    double p3 = thirdRoad(E3) / 100.0;

    if (p1 == 1 && p2 == 1 && p3 == 1)
    {
        decreaseEXP(EXP1, EXP1 * 0.15);
        return traceLuggage(HP1, EXP1, M1, E3);
    }

    double avgP = (p1 + p2 + p3) / 3.0;
    if (avgP < 0.5)
    {
        decreaseHP(HP1, HP1 * 0.15);
        increaseEXP(EXP1, EXP1 * 0.15);
    }
    else
    {
        decreaseHP(HP1, HP1 * 0.1);
        increaseEXP(EXP1, EXP1 * 0.2);
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{

    // check e3
    if (!checkEventCode(E3))
    {
        return -99;
    }

    // initalize array
    int array[10][10], meetingI = 0, meetingJ = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            int val = ((E3 * j) + i * 2) * (i - j);
            array[i][j] = val;

            // check meeting point
            if (val > E3 * 2)
            {
                meetingI++;
            }
            else if (val < E3 * -1)
            {
                meetingJ++;
            }
        }
    }

    // find meeting spot
    while (meetingI > 9)
        meetingI = (meetingI % 10 + meetingI / 10);
    while (meetingJ > 9)
        meetingJ = (meetingJ % 10 + meetingJ / 10) % 10;
    int score = array[meetingI][meetingJ];

    // left diagonal
    int leftI = max(0, meetingI - meetingJ);
    int leftJ = max(0, meetingJ - meetingI);
    while (leftI >= 0 && leftI < 10 && leftJ >= 0 && leftJ < 10)
    {
        score = max(score, array[leftI++][leftJ++]);
    }
    // right diagonal
    int rightI = min(9, meetingI + meetingJ);
    int rightJ = max(0, meetingI + meetingJ - 9);
    while (rightI >= 0 && rightI < 10 && rightJ >= 0 && rightJ < 10)
    {
        score = max(score, array[rightI--][rightJ++]);
    }

    if (abs(array[meetingI][meetingJ]) > abs(score))
    {
        decreaseHP(HP1, HP1 * 0.1);
        decreaseHP(HP2, HP2 * 0.1);
        decreaseEXP(EXP1, EXP1 * 0.12);
        decreaseEXP(EXP2, EXP2 * 0.12);
    }
    else
    {
        increaseHP(HP1, HP1 * 0.1);
        increaseHP(HP2, HP2 * 0.1);
        increaseEXP(EXP1, EXP1 * 0.12);
        increaseEXP(EXP2, EXP2 * 0.12);
    }

    return abs(array[meetingI][meetingJ]) > abs(score) ? array[meetingI][meetingJ] : score;
}

// Task 4

const char *getUsername(const char *email)
{
    int i = 0;
    while (email[i] != '@')
    {
        i++;
    }
    char *username = new char[i + 1];
    for (int j = 0; j < i; j++)
    {
        username[j] = email[j];
    }
    username[i] = '\0';
    return username;
}

void computeLPSArray(const char *pat, int M, int *lps)
{
    int len = 0;

    lps[0] = 0;

    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPSearch(const char *txt, const char *pat)
{
    int M = strlen(pat);
    int N = strlen(txt);

    int lps[M];

    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    while ((N - i) >= (M - j))
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            return i - j;
        }

        else if (pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    return -1;
}

int checkPassword(const char *s, const char *email)
{

    // get se string
    const char *se = getUsername(email);

    // variable initalization
    int i = 0, specialChar = 0, repeatCharCount = 0, repeatIndex = -1;
    char prevChar = '\0';

    // content loop
    while (s[i] != '\0')
    {
        char c = s[i];

        // repeat char check
        if (repeatCharCount < 3)
        { // only need first occurence
            if (c == prevChar)
            {
                repeatCharCount++;
            }
            else
            {
                repeatCharCount = 0;
                repeatIndex = i;
            }
        }

        // special character check
        if ((c >= 35 && c <= 38) || c == 90)
        {
            specialChar++;
        }

        prevChar = c;
        i++;
    }

    // length check
    if (i < 8)
    {
        return -1;
    }
    else if (i > 20)
    {
        return -2;
    }

    // substr occurence check
    int kmpRes = KMPSearch(s, se);
    if (kmpRes != -1)
    {
        return -300 - kmpRes;
    }

    // repeat char check
    if (repeatCharCount == 3)
    {
        return -400 - repeatIndex;
    }

    // special character check
    if (specialChar == 0)
    {
        return -5;
    }

    return -10;
}

// Task 5
int countOccurrence(const char *target, const char *arr_pwds[], int num_pwds)
{
    int count = 0;
    for (int i = 0; i < num_pwds; ++i)
    {
        if (strcmp(arr_pwds[i], target) == 0)
        {
            count++;
        }
    }
    return count;
}

int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{

    const char *mostFrequentPassword = nullptr;
    int mostFrequentIndex = -1, maxFrequency = 0;

    // loop array list
    for (int i = 0; i < num_pwds; i++)
    {

        int frequency = countOccurrence(arr_pwds[i], arr_pwds, num_pwds);

        if (frequency > maxFrequency || (frequency == maxFrequency && strlen(arr_pwds[i]) > strlen(mostFrequentPassword)))
        {
            mostFrequentPassword = arr_pwds[i];
            mostFrequentIndex = i;
            maxFrequency = frequency;
        }
    }

    return mostFrequentIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////