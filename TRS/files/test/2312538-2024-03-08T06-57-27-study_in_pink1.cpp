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

int maximumE = 99;
int minimumE = 0;

int calculateEXP(int &EXP)
{
    int maximumEXP = 600;
    int minimumEXP = 0;
    if (EXP > maximumEXP)
    {
        EXP = maximumEXP;
    }
    else if (EXP < minimumEXP)
    {
        EXP = minimumEXP;
    }
    return EXP;
}

int calculateHP(int &HP)
{
    int maximumHP = 666;
    int minimumHP = 0;
    if (HP > maximumHP)
    {
        HP = maximumHP;
    }
    else if (HP < minimumHP)
    {
        HP = minimumHP;
    }
    return HP;
}

int calculateM(int &M)
{
    int maximumM = 3000;
    int minimumM = 0;
    if (M > maximumM)
    {
        M = maximumM;
    }
    else if (M < minimumM)
    {
        M = minimumM;
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
    int maximumValE1Case01 = 4;

    if (e1 < minimumE || e1 > maximumE)
    {
        return -99;
    }

    if (e1 < maximumValE1Case01)
    {
        theReturnFromAfghanistanOfWatson(exp1, exp2, e1);
    }
    else
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
    int minimumInfo01OfE1 = 4;
    int maximumInfo01OfE1 = 19;
    int minimumInfo02OfE1 = 20;
    int maximumInfo02OfE1 = 49;
    int minimumInfo03OfE1 = 50;
    int maximumInfo03OfE1 = 65;
    int minimumInfo04OfE1 = 66;
    int maximumInfo04OfE1 = 79;
    int minimumInfo05OfE1 = 80;
    int maximumInfo05OfE1 = 99;

    if (e1 >= minimumInfo01OfE1 && e1 <= maximumInfo01OfE1)
    {
        exp2_tmp += (e1 / 4.0 + 19);
        exp2 = ceilNum(exp2_tmp, 0);
    }
    else if (e1 >= minimumInfo02OfE1 && e1 <= maximumInfo02OfE1)
    {
        exp2_tmp += (e1 / 9.0 + 21);
        exp2 = ceilNum(exp2_tmp, 0);
    }
    else if (e1 >= minimumInfo03OfE1 && e1 <= maximumInfo03OfE1)
    {
        exp2_tmp += (e1 / 16.0 + 17);
        exp2 = ceilNum(exp2_tmp, 0);
    }
    else if (e1 >= minimumInfo04OfE1 && e1 <= maximumInfo04OfE1)
    {
        exp2_tmp += (e1 / 4.0 + 19);
        exp2 = ceilNum(exp2_tmp, 0);
        if (exp2_tmp > 200)
        {
            exp2_tmp += (e1 / 9.0 + 21);
            exp2 = ceilNum(exp2_tmp, 0);
        }
    }
    else if (e1 >= minimumInfo05OfE1 && e1 <= maximumInfo05OfE1)
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

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function

    if (E2 < minimumE || E2 > maximumE)
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
    float HP1_tmp = HP1;
    float EXP1_tmp = EXP1;
    int maximumValHP1Event01 = 200;
    int maximumValEXPEvent02 = 400;
    int maximumValEXPEvent03 = 300;

    while (isGroceryStore && !forEvenE2)
    {
        if (HP1 < maximumValHP1Event01)
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
            if (EXP1_tmp < maximumValEXPEvent02)
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
            if (EXP1_tmp < maximumValEXPEvent03)
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
    float finalP;
    float EXP1_tmp = EXP1;
    float HP1_tmp = HP1;

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
    if (E3 < minimumE || E3 > maximumE)
    {
        return -99;
    }

    int mapTaxi[10][10] = {};
    int pointsHolmesWatson = 0;
    int pointsTaxi = 0;

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

    int countPositive = 0;
    int countNegative = 0;

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

    float EXP1_tmp = EXP1;
    float HP1_tmp = HP1;
    float EXP2_tmp = EXP2;
    float HP2_tmp = HP2;

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
    int row = i;
    int j_map = j;
    int orderOfFirstSideOfDiagonalVal = 0;
    int orderOfSecondSideOfDiagonalVal = 0;

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

    row = i;
    orderOfFirstSideOfDiagonalVal = 0;
    orderOfSecondSideOfDiagonalVal = 0;
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
    int emailLength = calculateEmailLength(email);
    int passLength = calculatePassLength(s);

    bool isValidEmail = checkValidEmail(email, emailLength);

    int seLength = calculateseLength(email, emailLength);
    char *se = defse(email, seLength);

    bool isValidPass = false;
    return checkValidPass(s, email, se, emailLength, passLength, seLength, isValidPass);
    delete[] se;
}

int calculateEmailLength(const char *email)
{
    int emailLength = 0;
    while (email[emailLength] != '\0')
    {
        ++emailLength;
    }
    return emailLength;
}

int calculatePassLength(const char *s)
{
    int passLength = 0;
    while (s[passLength] != '\0')
    {
        ++passLength;
    }
    return passLength;
}

int calculateseLength(const char *email, int emailLength)
{
    int seLength = 0;
    while (email[seLength] != '\0')
    {
        if (email[seLength] == '@')
        {

            break;
        }
        ++seLength;
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

    int sSimilar = 0;
    int sci = 0;
    int valWhenExistSimilarRespectiveTwoChar = 1;
    similarRespectiveTwoChar(s, passLength, sSimilar, sci);
    if (sSimilar == valWhenExistSimilarRespectiveTwoChar)
    {
        return -(400 + sci);
    }

    int sNotPunct = 0;
    int sValidPunct = 0;
    int sErrorPunct = 0;
    int iPunct = 0;
    for (int i = 0; i < passLength; i++)
    {
        char c = s[i];
        if (!ispunct(c))
        {
            ++sNotPunct;
        }
        else if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!')
        {
            ++sValidPunct;
        }
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
    else if (sValidPunct == 0 || sErrorPunct > 0)
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