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
        int &E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    } else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

void checkingHP(int &hp)
{
    if (hp > 666)
    {
        hp = 666;
    }
    else if (hp < 0)
    {
        hp = 0;
    }
}

void checkingEXP(int &exp)
{
    if (exp > 600)
    {
        exp = 600;
    }
    else if (exp < 0)
    {
        exp = 0;
    }
}

void checkingMONEY(int &money)
{
    if (money > 3000)
    {
        money = 3000;
    }
    else if (money < 0)
    {
        money = 0;
    }
}

bool checkingEVENT(int &eventCode)
{
    return (eventCode >= 0 && eventCode <= 99);
}

void roundUpAndCalculate(int &value, double factor, char operation)
{
    if (operation == 'p')
    {
        value = (double)value + factor + 0.9999;
    }
    else if (operation == 's')
    {
        value = (double)value - factor + 0.9999;
    }
    else if (operation == 'm')
    {
        value = (double)value * factor + 0.9999;
    }
}

/*=============================================================== TASK 1 =====================================================================*/

int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function

    if (checkingEVENT(e1) == false)
    {
        return -99;
    }

    checkingEXP(exp1);
    checkingEXP(exp2);

    if (e1 >= 0 && e1 <= 3)
    {
        switch (e1)
        {
        case 0:
            exp2 += 29;
            checkingEXP(exp2);
            break;

        case 1:
            exp2 += 45;
            checkingEXP(exp2);
            break;

        case 2:
            exp2 += 75;
            checkingEXP(exp2);
            break;

        case 3:
            exp2 += 149;
            checkingEXP(exp2);
            break;
        }

        int sherlockDecision = e1 * 3 + exp1 * 7;

        if (sherlockDecision % 2 != 0)
        {
            roundUpAndCalculate(exp1, (double)sherlockDecision / 100, 's');
            checkingEXP(exp1);
        }
        else
        {
            roundUpAndCalculate(exp1, (double)sherlockDecision / 200, 'p');
            checkingEXP(exp1);
        }
    }

    if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        {
            roundUpAndCalculate(exp2, (double)e1 / 4 + 19, 'p');
            checkingEXP(exp2);

            exp1 -= e1;
            checkingEXP(exp1);
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            roundUpAndCalculate(exp2, (double)e1 / 9 + 21, 'p');
            checkingEXP(exp2);

            exp1 -= e1;
            checkingEXP(exp1);
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            roundUpAndCalculate(exp2, (double)e1 / 16 + 17, 'p');
            checkingEXP(exp2);

            exp1 -= e1;
            checkingEXP(exp1);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            roundUpAndCalculate(exp2, (double)e1 / 4 + 19, 'p');
            checkingEXP(exp2);

            if (exp2 > 200)
            {
                roundUpAndCalculate(exp2, (double)e1 / 9 + 21, 'p');
                checkingEXP(exp2);
            }

            exp1 -= e1;
            checkingEXP(exp1);
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            roundUpAndCalculate(exp2, (double)e1 / 4 + 19, 'p');
            checkingEXP(exp2);

            roundUpAndCalculate(exp2, (double)e1 / 9 + 21, 'p');
            checkingEXP(exp2);

            if (exp2 > 400)
            {
                roundUpAndCalculate(exp2, (double)e1 / 16 + 17, 'p');
                checkingEXP(exp2);

                roundUpAndCalculate(exp2, 1.15, 'm');
                checkingEXP(exp2);
            }

            exp1 -= e1;
            checkingEXP(exp1);
        }
    }

    return exp1 + exp2;
}

/*=============================================================== TASK 2 =====================================================================*/

double determineProbability(int exp1)
{
    double s = round(sqrt(exp1)) * round(sqrt(exp1));

    double p;

    if (exp1 >= s)
    {
        p = 1;
    }
    else
    {
        p = (exp1 / s + 80) / 123;
    }

    return p;
}

void event01(int &HP1, int &M1, int &paidMoney)
{
    if (HP1 < 200)
    {
        roundUpAndCalculate(HP1, 1.3, 'm');
        checkingHP(HP1);

        paidMoney += 150;
        M1 -= 150;
        checkingMONEY(M1);
    }
    else
    {
        roundUpAndCalculate(HP1, 1.1, 'm');
        checkingHP(HP1);

        paidMoney += 70;
        M1 -= 70;
        checkingMONEY(M1);
    }
}
void event02(int &EXP1, int &M1, int &paidMoney)
{
    if (EXP1 < 400)
    {
        paidMoney += 200;
        M1 -= 200;
        checkingMONEY(M1);
    }
    else
    {
        paidMoney += 120;
        M1 -= 120;
        checkingMONEY(M1);
    }
    roundUpAndCalculate(EXP1, 1.13, 'm');
    checkingEXP(EXP1);
}

void event03(int &EXP1, int &M1, int &paidMoney)
{
    if (EXP1 < 300)
    {
        paidMoney += 100;
        M1 -= 100;
        checkingMONEY(M1);
    }
    else
    {
        paidMoney += 120;
        M1 -= 120;
        checkingMONEY(M1);
    }
    roundUpAndCalculate(EXP1, 0.9, 'm');
    checkingEXP(EXP1);
}
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function

    if (checkingEVENT(E2) == false)
    {
        return -99;
    }

    checkingEXP(EXP1);
    checkingHP(HP1);
    checkingMONEY(M1);

    /*************************************************************** ROAD 01 **********************************************************************/
    double p1;

    p1 = determineProbability(EXP1);

    /*************************************************************** ROAD 02 **********************************************************************/
    double p2;

    double limit = 0.5 * M1;

    int paidMoney = 0;

    if (E2 % 2 != 0 && M1 != 0)
    {
        while (paidMoney <= limit)
        {

            event01(HP1, M1, paidMoney);

            if (paidMoney > limit)
            {
                break;
            }

            event02(EXP1, M1, paidMoney);

            if (paidMoney > limit)
            {
                break;
            }

            event03(EXP1, M1, paidMoney);

            if (paidMoney > limit)
            {
                break;
            }
        }
    }
    else if (E2 % 2 == 0 && M1 != 0)
    {
        while (M1 > 0)
        {

            event01(HP1, M1, paidMoney);

            if (M1 == 0)
            {
                break;
            }

            event02(EXP1, M1, paidMoney);

            if (M1 == 0)
            {
                break;
            }

            event03(EXP1, M1, paidMoney);

            break;
        }
    }
    roundUpAndCalculate(HP1, 0.83, 'm');
    checkingHP(HP1);

    roundUpAndCalculate(EXP1, 1.17, 'm');
    checkingEXP(EXP1);

    p2 = determineProbability(EXP1);

    /*************************************************************** ROAD 03 **********************************************************************/
    double p3;

    double P[10] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};

    int i = 0;

    if (E2 < 10)
    {
        i = E2;

        p3 = P[i];
    }
    else
    {

        i = E2 % 10 + E2 / 10;

        p3 = P[i % 10];
    }

    if (p1 == 1 && p2 == 1 && p3 == 1)
    {
        roundUpAndCalculate(EXP1, 0.75, 'm');
        checkingEXP(EXP1);
    }
    else
    {

        double pAverage = (p1 + p2 + p3) / 3;

        if (pAverage < 0.5)
        {
            roundUpAndCalculate(HP1, 0.85, 'm');
            checkingHP(HP1);

            roundUpAndCalculate(EXP1, 1.15, 'm');
            checkingEXP(EXP1);
        }
        else
        {
            roundUpAndCalculate(HP1, 0.9, 'm');
            checkingHP(HP1);

            roundUpAndCalculate(EXP1, 1.2, 'm');
            checkingEXP(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

/*=============================================================== TASK 3 =====================================================================*/

int sumOfTwoDigits(int meetingPosition)
{
    if (meetingPosition < 10)
    {
        return meetingPosition;
    }
    else
    {
        int sum = 0;
        sum += meetingPosition % 10 + meetingPosition / 10;
        return sumOfTwoDigits(sum);
    }
}

int sherlockWatsonGradeGenerated(int rowIndex, int columnIndex, int taxiMap[10][10])
{
    int sherlockWatsonPositionGrade = taxiMap[rowIndex][columnIndex];
    int sumOfPosition = rowIndex + columnIndex;
    int subtractOfPosition = rowIndex - columnIndex;

    for (int i = 0; i <= 9; i++)
    {
        if (sumOfPosition - i <= 9 && sumOfPosition - i >= 0 && sherlockWatsonPositionGrade < taxiMap[i][sumOfPosition - i])
        {
            sherlockWatsonPositionGrade = abs(taxiMap[i][sumOfPosition - i]);
        }
    }

    for (int i = 0; i <= 9; i++)
    {
        if (i + subtractOfPosition <= 9 && i + subtractOfPosition >= 0 && sherlockWatsonPositionGrade < taxiMap[i + subtractOfPosition][i])
        {
            sherlockWatsonPositionGrade = abs(taxiMap[i + subtractOfPosition][i]);
        }
    }
    return sherlockWatsonPositionGrade;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (checkingEVENT(E3) == false)
    {
        return -99;
    }

    checkingHP(HP1);
    checkingHP(HP2);
    checkingEXP(EXP1);
    checkingEXP(EXP2);

    int meetingColumn = 0, meetingRow = 0;
    int taxiGrade = 0, sherlockWatsonGrade = 0;
    int taxiMap[10][10];
    int sherlockMap[10][10];

    for (int row = 0; row < 10; row++)
    {
        for (int column = 0; column < 10; column++)
        {
            taxiMap[row][column] = 0;
        }
    }

    for (int row = 0; row < 10; row++)
    {
        for (int column = 0; column < 10; column++)
        {
            taxiMap[row][column] = ((E3 * column) + (row * 2)) * (row - column);
        }
    }

    for (int column = 0; column < 10; column++)
    {
        for (int row = 0; row < 10; row++)
        {
            sherlockMap[row][column] = sherlockWatsonGradeGenerated(row, column, taxiMap);
        }
    }

    for (int row = 0; row < 10; row++)
    {
        for (int column = 0; column < 10; column++)
        {
            if (taxiMap[row][column] > 2 * E3)
            {
                meetingRow++;
            }
            else if (taxiMap[row][column] < -E3)
            {
                meetingColumn++;
            }
        }
    }

    meetingColumn = sumOfTwoDigits(meetingColumn);
    meetingRow = sumOfTwoDigits(meetingRow);

    taxiGrade = taxiMap[meetingRow][meetingColumn];
    sherlockWatsonGrade = sherlockMap[meetingRow][meetingColumn];

    if (abs(taxiGrade) > sherlockWatsonGrade)
    {
        roundUpAndCalculate(EXP1, 0.88, 'm');
        checkingEXP(EXP1);

        roundUpAndCalculate(EXP2, 0.88, 'm');
        checkingEXP(EXP2);

        roundUpAndCalculate(HP1, 0.9, 'm');
        checkingHP(HP1);

        roundUpAndCalculate(HP2, 0.9, 'm');
        checkingHP(HP2);

        return taxiGrade;
    }
    else
    {
        roundUpAndCalculate(EXP1, 1.12, 'm');
        checkingEXP(EXP1);

        roundUpAndCalculate(EXP2, 1.12, 'm');
        checkingEXP(EXP2);

        roundUpAndCalculate(HP1, 1.1, 'm');
        checkingHP(HP1);

        roundUpAndCalculate(HP2, 1.1, 'm');
        checkingHP(HP2);

        return sherlockWatsonGrade;
    }
}

/*=============================================================== TASK 4 =====================================================================*/

int sizeOfConstCharX(const char *s)
{
    int sSize = 0;
    while (s[sSize] != '\0')
    {
        sSize++;
    }
    return sSize;
}

int checkingSe(const char *s, string se, int sSize)
{
    if (se == "\0")
    {
        return 0;
    }

    int seSize = se.size();
    int checkSe = -1;

    for (int i = 0; i <= sSize - seSize; i++)
    {
        if (s[i] == se[0] && s[i + seSize - 1] == se[seSize - 1])
        {
            for (int j = 0; j <= seSize - 1; j++)
            {
                if (s[i + j] != se[j])
                {
                    checkSe = -1;
                    break;
                }
                else
                {
                    checkSe = i;
                }
            }
        }
        if (checkSe != -1)
        {
            break;
        }
    }

    return checkSe;
}

int checkingConsecutive(const char *s, int sSize)
{
    int checkConsecutive = -1;

    for (int i = 0; i <= sSize - 3; i++)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            checkConsecutive = i;
            break;
        }
    }

    return checkConsecutive;
}

bool checkingSpecial(const char *s, int sSize)
{
    char specialCharacters[5] = {'@', '#', '%', '$', '!'};

    for (int i = 0; i < sSize; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (specialCharacters[j] == s[i])
            {
                return true;
            }
        }
    }
    return false;
}

int checkingStrange(const char *s, int sSize)
{
    int strangeIndex = 0;
    bool validCheck = false;

    for (int i = 0; i < sSize; i++)
    {
        validCheck = false;

        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            strangeIndex++;
            validCheck = true;
            continue;
        }
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            strangeIndex++;
            validCheck = true;
            continue;
        }
        if (s[i] >= '0' && s[i] <= '9')
        {
            strangeIndex++;
            validCheck = true;
            continue;
        }
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            strangeIndex++;
            validCheck = true;
            continue;
        }
        if (validCheck == false)
        {
            break;
        }
    }
    if (validCheck == true)
    {
        return -1;
    }
    return strangeIndex;
}

int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function

    int sSize = sizeOfConstCharX(s);

    if (sSize < 8)
    {
        return -1;
    }

    if (sSize > 20)
    {
        return -2;
    }

    string se = "\0";

    for (int i = 0; i < sizeOfConstCharX(email); i++)
    {
        if (email[i] == '@')
        {
            break;
        }
        else
        {
            se += email[i];
        }
    }

    int statusSe = checkingSe(s, se, sSize);
    int statusConsecutive = checkingConsecutive(s, sSize);
    int statusStrange = checkingStrange(s, sSize);

    if (statusSe != -1)
    {
        return -(300 + statusSe);
    }

    if (statusConsecutive != -1)
    {
        return -(400 + statusConsecutive);
    }

    if (!checkingSpecial(s, sSize))
    {
        return -5;
    }

    if (statusStrange != -1)
    {
        return statusStrange;
    }
    return -10;
}

/*=============================================================== TASK 5 =====================================================================*/

int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function

    string arr_pwds_string[num_pwds];
    for (int i = 0; i < num_pwds; i++)
    {
        arr_pwds_string[i] = arr_pwds[i];
    }

    int count = 0;

    int max = 0;

    int correctPassIndex;

    for (int i = 0; i < num_pwds; i++)
    {
        count = 0;
        for (int j = i; j < num_pwds; j++)
        {
            if (arr_pwds_string[i] == arr_pwds_string[j])
            {
                count++;
            }
        }
        if (count > max)
        {
            max = count;

            correctPassIndex = i;
        }
        else if (count == max)
        {

            if (sizeOfConstCharX(arr_pwds[i]) > sizeOfConstCharX(arr_pwds[correctPassIndex]))
            {
                correctPassIndex = i;
            }
        }
    }
    return correctPassIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////