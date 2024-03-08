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
/// STUDENTS ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

int calculateEXP(int &EXP)
{
    if (EXP > 600)
    {
        EXP = 600;
    }
    else if (EXP < 0)
    {
        EXP = 0;
    }
    return EXP;
}

int calculateHP(int &HP)
{
    if (HP > 666)
    {
        HP = 666;
    }
    else if (HP < 0)
    {
        HP = 0;
    }

    return HP;
}

int calculateM(int &M)
{
    if (M > 3000)
    {
        M = 3000;
    }
    else if (M < 0)
    {
        M = 0;
    }
    return M;
}

int ceilNum(float &temp, float changingAmount)
{
    temp *= (1 + changingAmount);
    if (abs(temp - (int)temp) > (1.0e-3))
    {
        temp = ceilf(temp);
    }
    else
    {
        return (int)temp;
    }
    return (int)temp;
}

// Task 1

int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }

    if (e1 < 4)
    {
        theReturnFromAfghanistanOfWatson(exp1, exp2, e1);
    }
    else if (e1 >= 4)
    {
        brotherOfWatson(exp1, exp2, e1);
    }

    exp1 = calculateEXP(exp1);
    exp2 = calculateEXP(exp2);

    return exp1 + exp2;
}

void theReturnFromAfghanistanOfWatson(int &exp1, int &exp2, int e1)
{
    int experienceE1Equals0 = 29;
    int experienceE1Equals1 = 45;
    int experienceE1Equals2 = 75;
    int experienceE1Equals3 = experienceE1Equals0 + experienceE1Equals1 + experienceE1Equals2;

    switch (e1)
    {
    case 0:
        exp2 += experienceE1Equals0;
        break;
    case 1:
        exp2 += experienceE1Equals1;
        break;
    case 2:
        exp2 += experienceE1Equals2;
        break;
    case 3:
        exp2 += experienceE1Equals3;
        break;
    }

    int D = (e1 * 3) + (exp1 * 7);
    float exp1_tmp = exp1;

    if (D % 2 == 0)
    {
        exp1_tmp += (D / 200.0);
        exp1 = ceilNum(exp1_tmp, 0);
    }
    else if (D % 2 != 0)
    {
        exp1_tmp -= (D / 100.0);
        exp1 = ceilNum(exp1_tmp, 0);
    }
}

void brotherOfWatson(int &exp1, int &exp2, int e1)
{
    float exp2_tmp = exp2;
    if (e1 >= 4 && e1 <= 19)
    {
        exp2_tmp += (e1 / 4.0 + 19);
        exp2 = ceilNum(exp2_tmp, 0);
    }
    else if (e1 >= 20 && e1 <= 49)
    {
        exp2_tmp += (e1 / 9.0 + 21);
        exp2 = ceilNum(exp2_tmp, 0);
    }
    else if (e1 >= 50 && e1 <= 65)
    {
        exp2_tmp += (e1 / 16.0 + 17);
        exp2 = ceilNum(exp2_tmp, 0);
    }
    else if (e1 >= 66 && e1 <= 79)
    {
        exp2_tmp += (e1 / 4.0 + 19);
        exp2 = ceilNum(exp2_tmp, 0);
        if (exp2_tmp > 200)
        {
            exp2_tmp += (e1 / 9.0 + 21);
            exp2 = ceilNum(exp2_tmp, 0);
        }
    }
    else if (e1 >= 80 && e1 <= 99)
    {
        exp2_tmp += (e1 / 4.0 + 19);
        exp2_tmp = ceilNum(exp2_tmp, 0);
        exp2_tmp += (e1 / 9.0 + 21);
        exp2 = ceilNum(exp2_tmp, 0);

        if (exp2_tmp > 400)
        {
            exp2_tmp += (e1 / 16.0 + 17);
            exp2 = ceilNum(exp2_tmp, 0);
            exp2 = ceilNum(exp2_tmp, 0.15);
        }
    }

    exp1 -= e1;
}

// Task 2
void eventPoint(int &HP1, int &EXP1, float HP1_tmp, float EXP1_tmp, int M1, int M1_tmp, int E2, bool &eventPointWhenE2Even, bool &eventPointWhenE2Odd);

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function

    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }

    float P1 = traceLuggageRoad01(HP1, EXP1, M1, E2);
    float P2 = traceLuggageRoad02(HP1, EXP1, M1, E2);
    float finalP = traceLuggageRoad03(HP1, EXP1, E2, P1, P2);

    HP1 = calculateHP(HP1);
    EXP1 = calculateEXP(EXP1);
    M1 = calculateM(M1);

    return HP1 + EXP1 + M1;
}

float traceLuggageRoad01(int &HP1, int &EXP1, int &M1, int E2)
{
    int S = squareNum(EXP1, M1);
    float P1 = probability(EXP1, S);
    return P1;
}

float traceLuggageRoad02(int &HP1, int &EXP1, int &M1, int E2)
{
    bool isGroceryStore = true;
    bool isTransportation = false;
    bool isGivingMoney = false;
    bool forEvenE2 = false;
    bool eventPointWhenE2Even = false;
    bool eventPointWhenE2Odd = false;
    int M1_tmp = M1;
    float HP1_tmp = HP1, EXP1_tmp = EXP1;

    while (isGroceryStore && !forEvenE2)
    {
        if (HP1 < 200)
        {
            HP1 = ceilNum(HP1_tmp, 0.3);
            M1 -= 150;
            M1 = calculateM(M1);
            HP1_tmp = calculateHP(HP1);

            eventPoint(HP1, EXP1, HP1_tmp, EXP1_tmp, M1, M1_tmp, E2, eventPointWhenE2Even, eventPointWhenE2Odd);
            if (eventPointWhenE2Even || eventPointWhenE2Odd)
            {
                break;
            }
        }
        else
        {
            HP1 = ceilNum(HP1_tmp, 0.1);
            M1 -= 70;
            M1 = calculateM(M1);
            HP1_tmp = calculateHP(HP1);

            eventPoint(HP1, EXP1, HP1_tmp, EXP1_tmp, M1, M1_tmp, E2, eventPointWhenE2Even, eventPointWhenE2Odd);
            if (eventPointWhenE2Even || eventPointWhenE2Odd)
            {
                break;
            }
        }
        isTransportation = true;

        if (isTransportation)
        {
            if (EXP1_tmp < 400)
            {
                EXP1 = ceilNum(EXP1_tmp, 0.13);
                M1 -= 200;
                M1 = calculateM(M1);
                EXP1_tmp = calculateEXP(EXP1);

                eventPoint(HP1, EXP1, HP1_tmp, EXP1_tmp, M1, M1_tmp, E2, eventPointWhenE2Even, eventPointWhenE2Odd);
                if (eventPointWhenE2Even || eventPointWhenE2Odd)
                {
                    break;
                }
            }
            else
            {
                EXP1 = ceilNum(EXP1_tmp, 0.13);
                M1 -= 120;
                M1 = calculateM(M1);
                EXP1_tmp = calculateEXP(EXP1);

                eventPoint(HP1, EXP1, HP1_tmp, EXP1_tmp, M1, M1_tmp, E2, eventPointWhenE2Even, eventPointWhenE2Odd);
                if (eventPointWhenE2Even || eventPointWhenE2Odd)
                {
                    break;
                }
            }
            isGivingMoney = true;
        }

        if (isGivingMoney)
        {
            if (EXP1_tmp < 300)
            {
                EXP1 = ceilNum(EXP1_tmp, -0.1);
                M1 -= 100;
                M1 = calculateM(M1);
                EXP1_tmp = calculateEXP(EXP1);

                eventPoint(HP1, EXP1, HP1_tmp, EXP1_tmp, M1, M1_tmp, E2, eventPointWhenE2Even, eventPointWhenE2Odd);
                if (eventPointWhenE2Even || eventPointWhenE2Odd)
                {
                    break;
                }
            }
            else
            {
                EXP1 = ceilNum(EXP1_tmp, -0.1);
                M1 -= 120;
                M1 = calculateM(M1);
                EXP1_tmp = calculateEXP(EXP1);

                eventPoint(HP1, EXP1, HP1_tmp, EXP1_tmp, M1, M1_tmp, E2, eventPointWhenE2Even, eventPointWhenE2Odd);
                if (eventPointWhenE2Even || eventPointWhenE2Odd)
                {
                    break;
                }
            }
        }
        if (E2 % 2 == 0)
        {
            forEvenE2 = true;
            HP1 = ceilNum(HP1_tmp, -0.17);
            EXP1 = ceilNum(EXP1_tmp, 0.17);
            EXP1_tmp = calculateEXP(EXP1);
            HP1_tmp = calculateHP(HP1);
        }
    }

    if (eventPointWhenE2Even)
    {
        HP1 = ceilNum(HP1_tmp, -0.17);
        EXP1 = ceilNum(EXP1_tmp, 0.17);
        EXP1_tmp = calculateEXP(EXP1);
        HP1_tmp = calculateHP(HP1);
    }

    M1 = calculateM(M1);
    EXP1 = calculateEXP(EXP1);
    HP1 = calculateHP(HP1);
    int S = squareNum(EXP1, M1);
    float P2 = probability(EXP1, S);

    return P2;
}
float traceLuggageRoad03(int &HP1, int &EXP1, int E2, float P1, float P2)
{
    float P[10] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    int i;
    float finalP, EXP1_tmp = EXP1, HP1_tmp = HP1;

    if (E2 % 10 == E2)
    {
        i = E2;
    }
    else
    {
        i = ((E2 % 10) + (E2 / 10)) % 10;
    }

    if (P1 == 1 && P2 == 1 && P[i] == 1)
    {
        EXP1 = ceilNum(EXP1_tmp, -0.25);
    }
    else
    {
        finalP = (((P1 + P2 + P[i]) / 3) * 100);
        if (finalP < 50)
        {
            HP1 = ceilNum(HP1_tmp, -0.15);
            EXP1 = ceilNum(EXP1_tmp, 0.15);
        }
        else
        {
            HP1 = ceilNum(HP1_tmp, -0.1);
            EXP1 = ceilNum(EXP1_tmp, 0.2);
        }
    }
    EXP1 = calculateEXP(EXP1);
    HP1 = calculateHP(HP1);

    return (float)finalP / 100;
}

void eventPoint(int &HP1, int &EXP1, float HP1_tmp, float EXP1_tmp, int M1, int M1_tmp, int E2, bool &eventPointWhenE2Even, bool &eventPointWhenE2Odd)
{
    if ((M1 == 0) && (E2 % 2 == 0))
    {
        eventPointWhenE2Even = true;
    }

    else if ((M1_tmp - M1 > M1_tmp / 2) && (E2 % 2 != 0))
    {
        HP1 = ceilNum(HP1_tmp, -0.17);
        EXP1 = ceilNum(EXP1_tmp, 0.17);
        EXP1_tmp = calculateEXP(EXP1);
        HP1_tmp = calculateHP(HP1);
        eventPointWhenE2Odd = true;
    }
}

int squareNum(int &EXP1, int &M1)
{
    int S;
    for (int i = 1; i <= sqrt(EXP1) + 1; i++)
    {
        if ((abs((i * i) - EXP1)) < (abs(((i - 1) * (i - 1)) - EXP1)))
        {
            S = i * i;
        }
    }
    return S;
}

float probability(int &EXP1, int S)
{
    float P;
    if (S <= EXP1)
    {
        P = 1;
    }
    else
    {
        P = (((float)EXP1 / (float)S) + 80) / 123.0;
    }
    return P;
}
// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }

    int mapTaxi[10][10] = {};
    int pointsHolmesWatson = 0, pointsTaxi = 0;

    defMapTaxi(E3, mapTaxi);
    return calPoints(EXP1, EXP2, HP1, HP2, E3, mapTaxi, pointsHolmesWatson, pointsTaxi);
}

void defMapTaxi(int E3, int mapTaxi[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            mapTaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
}

int calPoints(int &EXP1, int &EXP2, int &HP1, int &HP2, int E3, int mapTaxi[10][10], int pointsHolmesWatson, int &pointsTaxi)
{

    int countPositive = 0, countNegative = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            if (mapTaxi[i][j] > (E3 * 2) && mapTaxi[i][j] > 0)
            {
                ++countPositive;
            }
            if (mapTaxi[i][j] < (-E3) && mapTaxi[i][j] < 0)
            {
                ++countNegative;
            }
        }
    }

    int i = (countPositive % 10) + (countPositive / 10);
    int j = (countNegative % 10) + (countNegative / 10);

    while ((i % 10 != i) || (j % 10 != j))
    {
        i = ((i % 10) + (i / 10));
        j = ((j % 10) + (j / 10));
    }
    pointsTaxi = mapTaxi[i][j];
    pointsHolmesWatson = defMaxDiagonalMapVal(mapTaxi, i, j);

    float EXP1_tmp = EXP1, HP1_tmp = HP1;
    float EXP2_tmp = EXP2, HP2_tmp = HP2;

    if (abs(pointsTaxi) > abs(pointsHolmesWatson))
    {
        EXP1 = ceilNum(EXP1_tmp, -0.12);
        EXP2 = ceilNum(EXP2_tmp, -0.12);
        HP1 = ceilNum(HP1_tmp, -0.1);
        HP2 = ceilNum(HP2_tmp, -0.1);
    }
    else
    {
        EXP1 = ceilNum(EXP1_tmp, 0.12);
        EXP2 = ceilNum(EXP2_tmp, 0.12);
        HP1 = ceilNum(HP1_tmp, 0.1);
        HP2 = ceilNum(HP2_tmp, 0.1);
    }

    EXP1 = calculateEXP(EXP1);
    EXP2 = calculateEXP(EXP2);
    HP1 = calculateHP(HP1);
    HP2 = calculateHP(HP2);

    if (abs(pointsTaxi) == abs(pointsHolmesWatson))
    {
        return pointsHolmesWatson;
    }
    else if (abs(pointsTaxi) > abs(pointsHolmesWatson))
    {
        return pointsTaxi;
    }
    else
    {
        return pointsHolmesWatson;
    }
}

int defMaxDiagonalMapVal(int mapTaxi[10][10], int i, int j)
{
    int maxDiagonalMapVal = mapTaxi[i][j];
    bool isFirstDiagonalVal = false;
    int diagonalLeftMapVal[10] = {};
    int row = i, orderOfFirstSideOfDiagonalVal = 0, orderOfSecondSideOfDiagonalVal = 0;
    int j_map = j;

    for (int timesLoop = 0; timesLoop < 10; timesLoop++)
    {
        for (; row >= 0; row--)
        {
            for (int col = j; col >= 0; col--)
            {
                if (i == row && j == col)
                {
                    isFirstDiagonalVal = true;
                    diagonalLeftMapVal[orderOfFirstSideOfDiagonalVal] = mapTaxi[i][j];
                    orderOfFirstSideOfDiagonalVal++;
                    orderOfSecondSideOfDiagonalVal++;
                    break;
                }
                if (abs(row - col) == abs(i - j) && (col < j_map))
                {
                    if (col != j || !isFirstDiagonalVal)
                    {
                        diagonalLeftMapVal[orderOfFirstSideOfDiagonalVal] = mapTaxi[row][col];
                        orderOfFirstSideOfDiagonalVal++;
                        orderOfSecondSideOfDiagonalVal++;
                        j_map = col;
                        break;
                    }
                }
            }
        }
    }

    row = i;
    for (int timesLoop = 0; timesLoop < 10 - orderOfSecondSideOfDiagonalVal; timesLoop++)
    {
        for (; row < 10; row++)
        {
            for (int col = j + 1; col < 10; col++)
            {

                if (abs(row - col) == abs(i - j) && (col > j))
                {
                    diagonalLeftMapVal[orderOfSecondSideOfDiagonalVal] = mapTaxi[row][col];
                    orderOfSecondSideOfDiagonalVal++;
                }
            }
        }
    }

    int diagonalRightMapVal[10] = {};

    row = i, orderOfFirstSideOfDiagonalVal = 0, orderOfSecondSideOfDiagonalVal = 0;
    for (int timesLoop = 0; timesLoop < 10; timesLoop++)
    {
        for (; row < 10; row++)
        {
            for (int col = j; col >= 0; col--)
            {

                if ((row + col) == (i + j))
                {
                    diagonalRightMapVal[orderOfFirstSideOfDiagonalVal] = mapTaxi[row][col];
                    orderOfFirstSideOfDiagonalVal++;
                    orderOfSecondSideOfDiagonalVal++;
                }
            }
        }
    }

    row = i;
    for (int timesLoop = 0; timesLoop < 10 - orderOfSecondSideOfDiagonalVal; timesLoop++)
    {
        for (; row >= 0; row--)
        {
            for (int col = j + 1; col < 10; col++)
            {

                if ((row + col) == (i + j))
                {
                    diagonalRightMapVal[orderOfSecondSideOfDiagonalVal] = mapTaxi[row][col];
                    orderOfSecondSideOfDiagonalVal++;
                }
            }
        }
    }

    for (int index = 0; index < 10; index++)
    {
        if (diagonalLeftMapVal[index] > maxDiagonalMapVal)
        {
            if (diagonalRightMapVal[index] > diagonalLeftMapVal[index])
            {
                maxDiagonalMapVal = diagonalRightMapVal[index];
            }
            else
            {
                maxDiagonalMapVal = diagonalLeftMapVal[index];
            }
        }
        else if (diagonalRightMapVal[index] > maxDiagonalMapVal)
        {
            maxDiagonalMapVal = diagonalRightMapVal[index];
        }
    }

    return maxDiagonalMapVal;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    int emailLength = (sizeof(email) / sizeof(char)) - 1;
    bool isValidEmail = checkValidEmail(email, emailLength);
    int passLength = (sizeof(s) / sizeof(char)) - 1;

    int seLength = findseLength(email, emailLength);
    char *se = defse(email, seLength);

    bool isValidPass = false;
    return checkValidPass(s, email, se, emailLength, passLength, seLength, isValidPass);
    delete[] se;
}

int findseLength(const char *email, int emailLength)
{
    // tim do dai cua chuoi ky tu truoc @ cua email
    int seLength = 0;
    while (email[seLength] != '\0')
    {
        ++seLength;
        if (email[seLength] == '@')
        {
            break;
        }
    }

    return seLength;
}

char *defse(const char *email, int seLength)
{
    char *se = new char[seLength];
    for (int i = 0; i < seLength; i++)
    {
        *(se + i) = email[i];
    }
    return se;
}

int checkValidPass(const char *s, const char *email, const char *se, int emailLength, int passLength, int seLength, bool isValidPass)
{
    if (passLength < 8)
    {
        isValidPass = false;
        return -1;
    }
    else if (passLength > 20)
    {
        isValidPass = false;
        return -2;
    }
    else
    {
        isValidPass = true;
    }

    int sei = 0;

    if (isSEsubStrOfPass(s, se, sei))
    {
        return -(300 + sei);
    }
    else if (seLength == 0)
    {
        return -300;
    }

    int sSimilar = 0, sci = 0;
    similarRespectiveTwoChar(s, passLength, sSimilar, sci);
    if (sSimilar == 1)
    {
        return -(400 + sci);
    }

    int sNotPunct = 0, sPunct = 0, sErrorPunct = 0, iPunct = 0;
    for (int i = 0; i < passLength; i++)
    {
        char c = s[i];
        if (!ispunct(c))
            ++sNotPunct;
        else if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!')
            ++sPunct;
        else
        {
            ++sErrorPunct;
            iPunct = i;
        }
    }

    // – Nếu s không chứa ký tự đặc biệt thì trả về -5.
    if (sNotPunct == passLength || (passLength - sNotPunct == sErrorPunct))
    {
        return -5;
    }
    else if (sPunct == 0 || sErrorPunct > 0)
    {
        isValidPass = false;
    }

    if (isValidPass)
    {
        return -10;
    }
    return iPunct;
}

bool isSEsubStrOfPass(const char *s, const char *se, int &sei)
{
    const char *pSEsubStrOfPass;
    pSEsubStrOfPass = strstr(s, se);
    if (pSEsubStrOfPass)
    {
        sei = pSEsubStrOfPass - s;
        return true;
    }
    return false;
}
bool checkValidEmail(const char *email, int emailLength)
{
    int countP = 0;
    for (int i = 0; i < emailLength; i++)
    {
        if (email[i] == '@')
        {
            ++countP;
        }
    }
    if (countP == 1 && emailLength <= 100)
    {
        return true;
    }

    return false;
}
void similarRespectiveTwoChar(const char *s, int passLength, int &sSimilar, int &sci)
{
    bool isFirstChar = false;
    for (int i = 1; i < passLength; i++)
    {
        char c = s[i];
        if (s[i] == s[i - 1] && s[i] == s[i + 1])
        {
            if (!isFirstChar)
            {
                isFirstChar = true;
                sci = i - 1;
            }
            ++sSimilar;
            break;
        }
    }
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int times[num_pwds] = {};

    for (int i = 0; i < num_pwds; i++)
    {
        for (int j = 0; j < num_pwds; j++)
        {
            if (arr_pwds[j] == arr_pwds[i])
            {
                ++times[i];
            }
        }
    }
    int iRP[num_pwds] = {};
    int maxTimes = times[0];
    for (int i = 0; i < num_pwds; i++)
    {
        if ((times[i] > times[i + 1] || times[i] == times[i + 1]) && (times[i] > maxTimes || times[i] == maxTimes))
        {
            maxTimes = times[i];
            iRP[i] = i;
        }
    }

    bool isFirst = false;
    int firstRP = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        if (iRP[i] != 0)
        {
            if (!isFirst)
            {
                isFirst = true;
                firstRP = i;
            }
            if (arr_pwds[i] > arr_pwds[firstRP])
            {
                return i;
            }
        }
    }

    if (arr_pwds[0] == arr_pwds[firstRP])
        return 0;
    return firstRP;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////