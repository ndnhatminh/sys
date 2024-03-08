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

int verifyValue(int value, int bottom, int top)
{
    return value < bottom ? bottom : value > top ? top
                                                 : value;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
        return -99;
    exp1 = verifyValue(exp1, 0, 600);
    exp2 = verifyValue(exp2, 0, 600);
    if (e1 < 4)
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
            exp2 += (29 + 45 + 75);
            break;
        }
        int d = e1 * 3 + exp1 * 7;
        if (d % 2)
            exp1 = ceil(exp1 - (float)d / 100);
        else
            exp1 = ceil(exp1 + (float)d / 200);
    }
    else
    {
        if (e1 < 20)
        {
            exp2 += ceil((float)e1 / 4 + 19);
        }
        else if (e1 < 50)
        {
            exp2 += ceil((float)e1 / 9 + 21);
        }
        else if (e1 < 66)
        {
            exp2 += ceil((float)e1 / 16 + 17);
        }
        else if (e1 < 80)
        {
            exp2 += ceil((float)e1 / 4 + 19);
            if (exp2 > 200)
                exp2 += ceil((float)e1 / 9 + 21);
        }
        else
        {
            exp2 += ceil((float)e1 / 4 + 19);
            exp2 += ceil((float)e1 / 9 + 21);
            if (exp2 > 400)
            {
                exp2 += ceil((float)e1 / 16 + 17);
                exp2 = ceil((float)exp2 * 115 / 100);
            }
        }
        exp1 -= e1;
    }
    exp1 = verifyValue(exp1, 0, 600);
    exp2 = verifyValue(exp2, 0, 600);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
        return -99;

    HP1 = verifyValue(HP1, 0, 666);
    EXP1 = verifyValue(EXP1, 0, 600);
    M1 = verifyValue(M1, 0, 3000);

    // First road
    int sqrtExp1 = sqrt(EXP1);
    float P1 = EXP1 - pow(sqrtExp1, 2) < pow(sqrtExp1 + 1, 2) - EXP1 ? 1 : (EXP1 / pow(sqrtExp1 + 1, 2) + 80) / 123;

    // Second road
    float halfMoney = M1 / 2;
    int paid = 0;
    do
    {
        if (M1 == 0)
            break;
        // sk1
        if (HP1 < 200)
        {
            HP1 = verifyValue(ceil((float)HP1 * 130 / 100), 0, 666);
            paid += 150;
            M1 = verifyValue(M1 - 150, 0, 3000);
        }
        else
        {
            HP1 = verifyValue(ceil((float)HP1 * 110 / 100), 0, 666);
            paid += 70;
            M1 = verifyValue(M1 - 70, 0, 3000);
        }
        if (M1 == 0 || (E2 % 2 && paid > halfMoney))
            break;

        // sk2
        paid += EXP1 < 400 ? 200 : 120;
        M1 = verifyValue(M1 - (EXP1 < 400 ? 200 : 120), 0, 3000);
        EXP1 = verifyValue(ceil((float)EXP1 * 113 / 100), 0, 600);

        if (M1 == 0 || (E2 % 2 && paid > halfMoney))
            break;

        // sk3
        paid += EXP1 < 300 ? 100 : 120;
        M1 = verifyValue(M1 - (EXP1 < 300 ? 100 : 120), 0, 3000);
        EXP1 = verifyValue(ceil((float)EXP1 * 90 / 100), 0, 600);

        if (M1 == 0 || (E2 % 2 && paid > halfMoney))
            break;

    } while (E2 % 2);

    EXP1 = verifyValue(ceil((float)EXP1 * 117 / 100), 0, 600);
    HP1 = verifyValue(ceil((float)HP1 * 83 / 100), 0, 666);

    sqrtExp1 = sqrt(EXP1);
    float P2 = EXP1 - pow(sqrtExp1, 2) < pow(sqrtExp1 + 1, 2) - EXP1 ? 1 : (EXP1 / pow(sqrtExp1 + 1, 2) + 80) / 123;

    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float P3 = (float)P[(E2 / 10 + E2 % 10) % 10] / 100;

    if (P1 == 1 && P1 == P2 && P2 == P3)
    {
        EXP1 = verifyValue(ceil((float)EXP1 * 75 / 100), 0, 600);
    }
    else if ((P1 + P2 + P3) / 3 < 0.5)
    {
        HP1 = verifyValue(ceil((float)HP1 * 85 / 100), 0, 666);
        EXP1 = verifyValue(ceil((float)EXP1 * 115 / 100), 0, 600);
    }
    else
    {
        HP1 = verifyValue(ceil((float)HP1 * 90 / 100), 0, 666);
        EXP1 = verifyValue(ceil((float)EXP1 * 120 / 100), 0, 600);
    }

    return HP1 + EXP1 + M1;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;

    HP1 = verifyValue(HP1, 0, 666);
    HP2 = verifyValue(HP2, 0, 666);
    EXP1 = verifyValue(EXP1, 0, 600);
    EXP2 = verifyValue(EXP2, 0, 600);

    int arr[10][10];
    int positiveNum = 0;
    int negativeNum = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            positiveNum += (arr[i][j] > E3 * 2) ? 1 : 0;
            negativeNum += (arr[i][j] < -E3) ? 1 : 0;
        }
    }

    positiveNum = (positiveNum / 10 + positiveNum % 10) / 10 + (positiveNum / 10 + positiveNum % 10) % 10;
    negativeNum = (negativeNum / 10 + negativeNum % 10) / 10 + (negativeNum / 10 + negativeNum % 10) % 10;

    int taxi = arr[positiveNum][negativeNum];
    int maxOfSherlock = arr[positiveNum][negativeNum];
    int forLoop = max(max(positiveNum, 9 - positiveNum), max(negativeNum, 9 - negativeNum));
    for (int i = 0; i < forLoop; i++)
    {
        if (positiveNum + i < 10 && negativeNum + i < 10)
            maxOfSherlock = max(maxOfSherlock, arr[positiveNum + i][negativeNum + i]);
        if (positiveNum + i < 10 && negativeNum - i > 0)
            maxOfSherlock = max(maxOfSherlock, arr[positiveNum + i][negativeNum - i]);
        if (positiveNum - i > 0 && negativeNum + i < 10)
            maxOfSherlock = max(maxOfSherlock, arr[positiveNum - i][negativeNum + i]);
        if (positiveNum - i > 0 && negativeNum - i > 0)
            maxOfSherlock = max(maxOfSherlock, arr[positiveNum - i][negativeNum - i]);
    }
    if (abs(taxi) > maxOfSherlock)
    {
        EXP1 = verifyValue(ceil((float)EXP1 * 88 / 100), 0, 600);
        EXP2 = verifyValue(ceil((float)EXP2 * 88 / 100), 0, 600);
        HP1 = verifyValue(ceil((float)HP1 * 90 / 100), 0, 666);
        HP2 = verifyValue(ceil((float)HP2 * 90 / 100), 0, 666);
        return taxi;
    }
    else
    {
        EXP1 = verifyValue(ceil((float)EXP1 * 112 / 100), 0, 600);
        EXP2 = verifyValue(ceil((float)EXP2 * 112 / 100), 0, 600);
        HP1 = verifyValue(ceil((float)HP1 * 110 / 100), 0, 666);
        HP2 = verifyValue(ceil((float)HP2 * 110 / 100), 0, 666);
        return maxOfSherlock;
    }
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    if (strlen(s) < 8)
        return -1;
    else if (strlen(s) > 20)
        return -2;
    bool verifyEmail = true;
    int includeEmail = -1;
    int includeDoubleLetter = -1;
    bool includeSpecialLetter = false;
    int curEmailIndex = 0;
    int wrongKeyPlace = -1;
    for (int i = 0; i < strlen(s); i++)
    {

        if (wrongKeyPlace == -1 && !(s[i] == 33 || (s[i] > 34 && s[i] < 38) || (s[i] > 47 && s[i] < 58) || (s[i] > 63 && s[i] < 91) || (s[i] > 96 && s[i] < 123)))
            wrongKeyPlace = i;

        // if (verifyEmail && s[i] == email[curEmailIndex])
        // {
        //     includeEmail = includeEmail == -1 ? i : includeEmail;
        //     curEmailIndex++;
        // }
        // else if (verifyEmail && s[i] == email[0])
        // {
        //     includeEmail = i;
        //     curEmailIndex = 1;
        // }
        // else if (verifyEmail)
        // {
        //     includeEmail = -1;
        //     curEmailIndex = 0;
        // }
        // if (email[curEmailIndex] == '@')
        //     verifyEmail = false;

        if (includeEmail == -1 && verifyEmail)
        {
            for (int j = 0; j < strlen(email); j++)
            {
                if (email[j] == '@')
                {
                    verifyEmail = false;
                    break;
                }
                else if (i + j >= strlen(s)) {
                    break;
                }
                else if (s[i + j] != email[j])
                {
                    includeEmail = -1;
                    break;
                }
                else
                    includeEmail = includeEmail == -1 ? i : includeEmail;
            }
        }

        if (!includeSpecialLetter && (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))
            includeSpecialLetter = true;
        if (i == 0 || i == 1)
            continue;
        includeDoubleLetter = includeDoubleLetter != -1 ? includeDoubleLetter : (s[i] == s[i - 1] && s[i] == s[i - 2]) ? i - 2
                                                                                                                       : -1;
    }

    if (includeEmail != -1 && !verifyEmail)
        return -(300 + includeEmail);
    else if (includeDoubleLetter != -1)
        return -(400 + includeDoubleLetter);
    else if (!includeSpecialLetter)
        return -5;
    else
        return wrongKeyPlace == -1 ? -10 : wrongKeyPlace;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    // int *countArr = new int[num_pwds]();
    // int maxPlace = -1;
    // for (int i = 0; i < num_pwds; i++)
    // {
    //     for (int j = i + 1; j < num_pwds; j++)
    //     {
    //         if (arr_pwds[i] == arr_pwds[j])
    //             countArr[i] += 1;
    //     }
    //     if ((maxPlace == -1) || (countArr[i] > countArr[maxPlace]) || (countArr[i] == countArr[maxPlace] && strlen(arr_pwds[i]) > strlen(arr_pwds[maxPlace])))
    //         maxPlace = i;
    // }
    // delete[] countArr;
    // return maxPlace;
    
    int temp = 0;
    int maxPlaceCount = 0;
    int maxPlace = -1;
    for (int i = 0; i < num_pwds; i++)
    {
        for (int j = i + 1; j < num_pwds; j++)
        {
            if (arr_pwds[i] == arr_pwds[j])
                temp++;
        }
        if ((maxPlace == -1) || (temp > maxPlaceCount) || (temp == maxPlaceCount && strlen(arr_pwds[i]) > strlen(arr_pwds[maxPlace]))) {
            maxPlace = i;
            maxPlaceCount = temp;
            temp = 0;
        }
    }
    return maxPlace;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////