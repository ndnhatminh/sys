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

// Task 1

int conditionEXP(int &EXP)
{
    if (EXP > 600)
        EXP = 600;
    else if (EXP < 0)
        EXP = 0;

    return EXP;
}

int conditionHP(int &HP)
{
    if (HP > 666)
        HP = 666;
    else if (HP < 0)
        HP = 0;

    return HP;
}

int conditionM(int &M)
{
    if (M > 3000)
        M = 3000;
    else if (M < 0)
        M = 0;

    return M;
}

int ceilNum(float &temp)
{
    if (abs(temp - (int)temp) < (1.0e-11))
        return (int)temp;
    else
    {
        temp = ceilf(temp);
    }

    return (int)temp;
}

int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function

    while (e1 > -1 && e1 < 100)
    {
        if (e1 < 4)
            firstMeetCase1(exp1, exp2, e1);

        else if ((e1 > 4 || e1 == 4) && e1 < 100)
            firstMeetCase2(exp1, exp2, e1);

        exp1 = conditionEXP(exp1);
        exp2 = conditionEXP(exp2);

        return exp1 + exp2;
    }

    return -99;
}

void firstMeetCase1(int &exp1, int &exp2, int e1)
{
    switch (e1)
    {
    case 0:
    {
        exp2 += 29;
        break;
    }

    case 1:
    {
        exp2 += 45;
        break;
    }

    case 2:
    {
        exp2 += 75;
        break;
    }

    case 3:
    {
        exp2 = exp2 + 29 + 45 + 75;
        break;
    }
    }

    int D = (e1 * 3) + (exp1 * 7);
    float exp1_tmp = exp1;
    // bool isAfghanistan = false;

    if (D % 2 == 0)
    {
        //    isAfghanistan = true;
        exp1_tmp = exp1 + (D / 200.00);
        exp1 = ceilNum(exp1_tmp);
    }
    else if (D % 2 != 0)
    {
        exp1_tmp = exp1 - (D / 100.00);
        exp1 = ceilNum(exp1_tmp);
    }
}

void firstMeetCase2(int &exp1, int &exp2, int e1)
{
    float exp2_tmp = exp2;
    if ((e1 > 4 || e1 == 4) && (e1 < 19 || e1 == 19))
    {
        exp2_tmp = exp2_tmp + (e1 / 4.00 + 19);
        exp2 = ceilNum(exp2_tmp);
    }
    else if ((e1 > 20 || e1 == 20) && (e1 < 49 || e1 == 49))
    {
        exp2_tmp = exp2_tmp + (e1 / 9.00 + 21);
        exp2 = ceilNum(exp2_tmp);
    }
    else if ((e1 > 50 || e1 == 50) && (e1 < 65 || e1 == 65))
    {
        exp2_tmp = exp2_tmp + (e1 / 16.00 + 17);
        exp2 = ceilNum(exp2_tmp);
    }
    else if ((e1 > 66 || e1 == 66) && (e1 < 79 || e1 == 79))
    {
        exp2_tmp = exp2_tmp + (e1 / 4.00 + 19);
        exp2 = ceilNum(exp2_tmp);

        if (exp2_tmp > 200)
        {
            exp2_tmp = exp2_tmp + (e1 / 9.00 + 21);
            exp2 = ceilNum(exp2_tmp);
        }
    }
    else if ((e1 > 80 || e1 == 80) && (e1 < 99 || e1 == 99))
    {
        exp2_tmp = exp2_tmp + (e1 / 4.00 + 19); //(e1 / 9.00 + 21);
        exp2_tmp = ceilNum(exp2_tmp);
        exp2_tmp = exp2_tmp + (e1 / 9.00 + 21);
        exp2 = ceilNum(exp2_tmp);

        if (exp2_tmp > 400)
        {
            exp2_tmp = (exp2_tmp + (e1 / 16.00 + 17));
            exp2_tmp = ceilNum(exp2_tmp);
            exp2_tmp = 1.15 * exp2_tmp;
            exp2 = ceilNum(exp2_tmp);
        }
    }
    // bool isBrother = false;
    exp1 -= e1;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    while (E2 > -1 && E2 < 100)
    {
        float P1 = traceLuggageRoad01(HP1, EXP1, M1, E2);
        float P2 = traceLuggageRoad02(HP1, EXP1, M1, E2);
        float finalP = traceLuggageRoad03(HP1, EXP1, E2, P1, P2);

        HP1 = conditionHP(HP1);
        EXP1 = conditionEXP(EXP1);
        M1 = conditionM(M1);

        return HP1 + EXP1 + M1;
    }
    return -99;
}

float traceLuggageRoad01(int &HP1, int &EXP1, int &M1, int E2)
{
    int S = squaredNum(EXP1, M1);
    float P1 = probability(EXP1, S);
    return P1;
}

float traceLuggageRoad02(int &HP1, int &EXP1, int &M1, int E2)
{
    bool isGroceryStore = true;
    bool isTransportation = false;
    bool isGivingMoney = false;
    bool isEven = false;
    bool inadequateM = false;
    int M1_tmp = M1;
    float HP1_tmp = HP1, EXP1_tmp = EXP1;

    while (isGroceryStore && !isEven)
    {
        // GROCERY STORE
        if (HP1_tmp < 200)
        {
            HP1_tmp = 1.3 * HP1_tmp;
            HP1 = ceilNum(HP1_tmp);

            M1 -= 150;

            M1 = conditionM(M1);
            HP1_tmp = conditionHP(HP1);

            if ((M1 == 0) && (E2 % 2 == 0))
            {
                inadequateM = true;
                break;
            }

            else if ((M1_tmp - M1 > M1_tmp / 2) && (E2 % 2 != 0))
            {

                HP1_tmp = 0.83 * HP1_tmp;
                HP1 = ceilNum(HP1_tmp);

                EXP1_tmp = 1.17 * EXP1_tmp;
                EXP1 = ceilNum(EXP1_tmp);

                EXP1_tmp = conditionEXP(EXP1);
                HP1_tmp = conditionHP(HP1);
                break;
            }
        }
        else
        {
            HP1_tmp = 1.1 * HP1_tmp;
            HP1 = ceilNum(HP1_tmp);
            M1 -= 70;

            M1 = conditionM(M1);
            HP1_tmp = conditionHP(HP1);

            if ((M1 == 0) && (E2 % 2 == 0))
            {
                inadequateM = true;
                break;
            }

            if ((M1_tmp - M1 > M1_tmp / 2) && (E2 % 2 != 0))
            {
                HP1_tmp = 0.83 * HP1_tmp;
                HP1 = ceilNum(HP1_tmp);

                EXP1_tmp = 1.17 * EXP1_tmp;
                EXP1 = ceilNum(EXP1_tmp);

                EXP1 = conditionEXP(EXP1);
                HP1_tmp = conditionHP(HP1);
                break;
            }
        }
        isTransportation = true;

        // TRANSPORTATION
        if (isTransportation)
        {
            if (EXP1_tmp < 400)
            {
                EXP1_tmp = 1.13 * EXP1_tmp;
                EXP1 = ceilNum(EXP1_tmp);

                M1 -= 200;

                M1 = conditionM(M1);
                EXP1_tmp = conditionEXP(EXP1);

                if ((M1 == 0) && (E2 % 2 == 0))
                {
                    inadequateM = true;
                    break;
                }

                else if ((M1_tmp - M1 > M1_tmp / 2) && (E2 % 2 != 0))
                {
                    HP1_tmp = 0.83 * HP1_tmp;
                    HP1 = ceilNum(HP1_tmp);

                    EXP1_tmp = 1.17 * EXP1_tmp;
                    EXP1 = ceilNum(EXP1_tmp);

                    EXP1_tmp = conditionEXP(EXP1);
                    HP1_tmp = conditionHP(HP1);
                    break;
                }
            }
            else
            {
                EXP1_tmp = 1.13 * EXP1_tmp;
                EXP1 = ceilNum(EXP1_tmp);

                M1 -= 120;

                M1 = conditionM(M1);
                EXP1_tmp = conditionEXP(EXP1);

                if ((M1 == 0) && (E2 % 2 == 0))
                {
                    inadequateM = true;
                    break;
                }

                else if ((M1_tmp - M1 > M1_tmp / 2) && (E2 % 2 != 0))
                {
                    HP1_tmp = 0.83 * HP1_tmp;
                    HP1 = ceilNum(HP1_tmp);

                    EXP1_tmp = 1.17 * EXP1_tmp;
                    EXP1 = ceilNum(EXP1_tmp);

                    EXP1_tmp = conditionEXP(EXP1);
                    HP1_tmp = conditionHP(HP1);

                    break;
                }
            }
            isGivingMoney = true;
        }

        if (isGivingMoney)
        {
            if (EXP1_tmp < 300)
            {
                EXP1_tmp = 0.9 * EXP1_tmp;
                EXP1 = ceilNum(EXP1_tmp);

                M1 -= 100;

                M1 = conditionM(M1);
                EXP1_tmp = conditionEXP(EXP1);

                if ((M1 == 0) && (E2 % 2 == 0))
                {
                    inadequateM = true;
                    break;
                }
                else if ((M1_tmp - M1 > M1_tmp / 2) && (E2 % 2 != 0))
                {
                    HP1_tmp = 0.83 * HP1_tmp;
                    HP1 = ceilNum(HP1_tmp);

                    EXP1_tmp = 1.17 * EXP1_tmp;
                    EXP1 = ceilNum(EXP1_tmp);

                    EXP1_tmp = conditionEXP(EXP1);
                    HP1_tmp = conditionHP(HP1);
                    break;
                }
            }
            else
            {
                EXP1_tmp = 0.9 * EXP1_tmp;
                EXP1 = ceilNum(EXP1_tmp);

                M1 -= 120;

                M1 = conditionM(M1);
                EXP1_tmp = conditionEXP(EXP1);

                if ((M1 == 0) && (E2 % 2 == 0))
                {
                    inadequateM = true;
                    break;
                }
                else if ((M1_tmp - M1 > M1_tmp / 2) && (E2 % 2 != 0))
                {
                    HP1_tmp = 0.83 * HP1_tmp;
                    HP1 = ceilNum(HP1_tmp);

                    EXP1_tmp = 1.17 * EXP1_tmp;
                    EXP1 = ceilNum(EXP1_tmp);

                    EXP1_tmp = conditionEXP(EXP1);
                    HP1_tmp = conditionHP(HP1);
                    break;
                }
            }
        }
        if (E2 % 2 == 0)
        {
            isEven = true;
            HP1_tmp = 0.83 * HP1_tmp;
            HP1 = ceilNum(HP1_tmp);

            EXP1_tmp = 1.17 * EXP1_tmp;
            EXP1 = ceilNum(EXP1_tmp);

            EXP1_tmp = conditionEXP(EXP1);
            HP1_tmp = conditionHP(HP1);
        }
    }

    if (inadequateM)
    {
        HP1_tmp = 0.83 * HP1_tmp;
        HP1 = ceilNum(HP1_tmp);

        EXP1_tmp = 1.17 * EXP1_tmp;
        EXP1 = ceilNum(EXP1_tmp);

        EXP1_tmp = conditionEXP(EXP1);
        HP1_tmp = conditionHP(HP1);
    }

    M1 = conditionM(M1);
    EXP1 = conditionEXP(EXP1);
    HP1 = conditionHP(HP1);
    int S = squaredNum(EXP1, M1);
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
        EXP1_tmp = 0.75 * EXP1_tmp;
        EXP1 = ceilNum(EXP1_tmp);
    }
    else
    {
        finalP = (((P1 + P2 + P[i]) / 3) * 100);
        if (finalP < 50)
        {
            HP1_tmp = 0.85 * HP1_tmp;
            HP1 = ceilNum(HP1_tmp);

            EXP1_tmp = 1.15 * EXP1_tmp;
            EXP1 = ceilNum(EXP1_tmp);
        }
        else
        {
            HP1_tmp = 0.9 * HP1_tmp;
            HP1 = ceilNum(HP1_tmp);

            EXP1_tmp = 1.2 * EXP1_tmp;
            EXP1 = ceilNum(EXP1_tmp);
        }
    }
    EXP1 = conditionEXP(EXP1);
    HP1 = conditionHP(HP1);
    // HP1 = (int)HP1_tmp;
    // EXP1 = (int)EXP1_tmp;

    return (float)finalP / 100;
}

int squaredNum(int &EXP1, int &M1)
{
    int S, tmp_M1 = M1;
    // exp1 = 430 => S = 441 // 21 * 21 = 441 // 20 * 20 = 400 // 19 * 19 = 361
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
    float EXP1_tmp = EXP1;
    if (S < EXP1 || S == EXP1)
    {
        P = 1;
    }
    else
    {
        P = ((EXP1_tmp / (float)S) + 80) / 123.0;
    }
    // P = (int)ceil(P * 100);

    // return (float)P / 100;
    return P;
}
// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    while (E3 > -1 && E3 < 100)
    {
        int mapTaxi[10][10] = {};
        int pointsHolmesWatson = 0, pointsTaxi = 0;

        defMapTaxi(E3, mapTaxi);
        return calPoints(EXP1, EXP2, HP1, HP2, E3, mapTaxi, pointsHolmesWatson, pointsTaxi);
    }

    return -99;
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
        EXP1_tmp = 0.88 * EXP1_tmp;
        EXP1 = ceilNum(EXP1_tmp);

        EXP2_tmp = 0.88 * EXP2_tmp;
        EXP2 = ceilNum(EXP2_tmp);

        HP1_tmp = 0.9 * HP1_tmp;
        HP1 = ceilNum(HP1_tmp);

        HP2_tmp = 0.9 * HP2_tmp;
        HP2 = ceilNum(HP2_tmp);
    }
    else
    {
        EXP1_tmp = 1.12 * EXP1_tmp;
        EXP1 = ceilNum(EXP1_tmp);

        EXP2_tmp = 1.12 * EXP2_tmp;
        EXP2 = ceilNum(EXP2_tmp);

        HP1_tmp = 1.1 * HP1_tmp;
        HP1 = ceilNum(HP1_tmp);

        HP2_tmp = 1.1 * HP2_tmp;
        HP2 = ceilNum(HP2_tmp);
    }

    EXP1 = conditionEXP(EXP1);
    EXP2 = conditionEXP(EXP2);
    HP1 = conditionHP(HP1);
    HP2 = conditionHP(HP2);

    if (abs(pointsTaxi) == abs(pointsHolmesWatson))
        return pointsHolmesWatson;
    else if (abs(pointsTaxi) > abs(pointsHolmesWatson))
        return pointsTaxi;
    else
        return pointsHolmesWatson;
}

int defMaxDiagonalMapVal(int mapTaxi[10][10], int i, int j)
{
    int maxDiagonalMapVal = mapTaxi[i][j];
    bool isFirst = false;

    int diagonalLeftMapVal[10] = {};

    int i_tmp = i, k = 0, n = 0;
    int j_map = j;

    for (int m = 0; m < 10; m++)
    {
        for (; i_tmp >= 0; i_tmp--)
        {
            for (int j_tmp = j; j_tmp >= 0; j_tmp--)
            {
                if (i == i_tmp && j == j_tmp)
                {
                    isFirst = true;
                    diagonalLeftMapVal[k] = mapTaxi[i][j];
                    k++;
                    n++;
                    break;
                }
                if (abs(i_tmp - j_tmp) == abs(i - j) && (j_tmp < j_map))
                {
                    if (j_tmp != j || !isFirst)
                    {
                        diagonalLeftMapVal[k] = mapTaxi[i_tmp][j_tmp];
                        k++;
                        n++;
                        j_map = j_tmp;
                        break;
                    }
                }
            }
        }
    }

    i_tmp = i;
    for (int m = 0; m < 10 - n; m++)
    {
        for (; i_tmp < 10; i_tmp++)
        {
            for (int j_tmp = j + 1; j_tmp < 10; j_tmp++)
            {

                if (abs(i_tmp - j_tmp) == abs(i - j) && (j_tmp > j))
                {
                    diagonalLeftMapVal[n] = mapTaxi[i_tmp][j_tmp];
                    n++;
                }
            }
        }
    }

    int diagonalRightMapVal[10] = {};

    i_tmp = i, k = 0, n = 0;
    for (int m = 0; m < 10; m++)
    {
        for (; i_tmp < 10; i_tmp++)
        {
            for (int j_tmp = j; j_tmp >= 0; j_tmp--)
            {

                if ((i_tmp + j_tmp) == (i + j))
                {
                    diagonalRightMapVal[k] = mapTaxi[i_tmp][j_tmp];
                    k++;
                    n++;
                }
            }
        }
    }

    i_tmp = i;
    for (int m = 0; m < 10 - n; m++)
    {
        for (; i_tmp >= 0; i_tmp--)
        {
            for (int j_tmp = j + 1; j_tmp < 10; j_tmp++)
            {

                if ((i_tmp + j_tmp) == (i + j))
                {
                    diagonalRightMapVal[n] = mapTaxi[i_tmp][j_tmp];
                    n++;
                }
            }
        }
    }

    for (int a = 0; a < 10; a++)
    {
        if (diagonalLeftMapVal[a] > maxDiagonalMapVal)
        {
            if (diagonalRightMapVal[a] > diagonalLeftMapVal[a])
                maxDiagonalMapVal = diagonalRightMapVal[a];
            else
                maxDiagonalMapVal = diagonalLeftMapVal[a];
        }
        else if (diagonalRightMapVal[a] > maxDiagonalMapVal)
        {
            maxDiagonalMapVal = diagonalRightMapVal[a];
        }
    }

    return maxDiagonalMapVal;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // Gọi se là chuỗi ký tự nằm trước ký tự ’@’ trong email của nạn nhân
    string semail = checkPassword_email(s, email);
    int seLength = semail.length();
    char se[seLength];
    for (int i = 0; i < semail.length(); i++)
    {
        se[i] = semail[i];
    }
    //
    bool isValidPass = false;
    return checkPassword_pass(s, email, se, isValidPass, seLength);
}

string checkPassword_email(const char *s, const char *email)
{
    int emailLength = 0;
    while (email[emailLength] != '\0')
        ++emailLength;

    int seLength = 0, count = 0;
    for (int i = 0; i < emailLength; i++)
    {
        char c = email[i];
        if (c == '@')
        {
            seLength = i + 1;
        }
    }
    char se[seLength];

    for (int i = 0; i < seLength - 1; i++)
    {
        se[i] = email[i];
    }

    return se;
}

int checkPassword_pass(const char *s, const char *email, const char *se, bool &isValidPass, int seLength)
{
    int passLength = 0;

    while (s[passLength] != '\0')
        ++passLength;
    if (seLength == 1)
        seLength = 0; // truong hop dac biet

    // – Có ít nhất 8 ký tự và có tối đa 20 ký tự.
    // Nếu s có độ dài ngắn hơn độ dài tối thiểu thì trả về -1.
    // Nếu s có độ dài dài hơn độ dài tối đa thì trả về -2.
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
        isValidPass = true;

    // Nếu s có chứa se thì trả về -(300+<sei>) với <sei> là vị trí xuất hiện đầu tiên của se.
    int sei = 0;
    if (seLength == 0)
        return -300;
    else if ((passLength > seLength) && checkPassword_passDuplicate(s, se, passLength, seLength, sei))
        return -(300 + sei);

    /*
        Nếu s có chứa nhiều hơn 2 ký tự liên tiếp và giống nhau thì trả về -(400+<sci>)
        với <sci> là vị trí đầu tiên của chuỗi đầu tiên gồm nhiều hơn 2 ký tự liên tiếp và
        giống nhau.
    */
    int sSimilar = 0, sci = 0;
    bool isFirst = false;
    for (int i = 1; i < passLength; i++)
    {
        char c = s[i];
        if (s[i] == s[i - 1] && s[i] == s[i + 1])
        {
            if (!isFirst)
            {
                isFirst = true;
                sci = i - 1;
            }
            ++sSimilar;
            break;
        }
    }
    if (sSimilar == 1)
        return -(400 + sci);

    /*
        Mỗi ký tự trong mật khẩu chỉ có thể là chữ số, hoặc chữ cái thường, hoặc chữ cái in
        hoa, hoặc ký tự đặc biệt. Ký tự đặc biệt là một trong các ký tự sau: ’@’, ’#’, ’%’,
        ’$’, ’!
    */

    int sNotPunct = 0, sPunct = 0, sErrorPunct = 0, iP = 0;
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
            iP = i;
        }
    }

    // – Nếu s không chứa ký tự đặc biệt thì trả về -5.
    if (sNotPunct == passLength || (passLength - sNotPunct == sErrorPunct))
        return -5;
    else if (sPunct == 0 || sErrorPunct > 0)
        isValidPass = false;

    if (isValidPass)
        return -10;

    // Các trường hợp còn lại trả về vị trí của ký tự đầu tiên vi phạm yêu cầu hợp lệ đã nêu trong Yêu cầu hàm.
    return iP;
    // Truong hop isValidPass (Co chieu dai ky tu trong khoang yeu cau), nhung co nhieu hon 1 ky tu dac biet
}

bool checkPassword_passDuplicate(const char *s, const char *se, int passLength, int seLength, int &sei)
{
    bool isFirst = false;
    bool isDuplicate = false;
    char passDuplicate[seLength];
    for (int i = 0; i < seLength; i++)
    {
        for (int j = 0; j < passLength; j++)
        {
            char c = s[j];
            if (c == se[i])
            {
                if (s[j - 1] != se[i] && !isFirst)
                {
                    isFirst = true;
                    sei = j;
                }
                passDuplicate[i] = c;
                break;
            }
        }
    }
    for (int i = 0; i < seLength; i++)
    {
        if (passDuplicate[i] == se[i])
        {
            isDuplicate = true;
        }
        else
            isDuplicate = false;
        if (i == (seLength - 1) && (passDuplicate[i] != se[i]))
            isDuplicate = false;
    }
    if (isFirst && isDuplicate)
        return true;
    return false;
}

/*
int checkPasswordValidEmail(const char *email, const char *se, const char *s)
{
    int emailLength = 0;
    while(email[emailLength] != '\0')
        ++emailLength;

    int seLength = 0, count = 0;
    for (int i = 0; i < emailLength; i++)
    {
        char c = email[i];
        if(c == '@')
        {   seLength = i + 1;
            ++count;
        }
    }

    char g[] ="gmail.com";
    int g_length = sizeof(g)/sizeof(char);
    char ase[emailLength - seLength];
    bool isValidEmail = false;
    int iE = 0;
    if (count != 1 || emailLength > 100)
        return seLength;
    else if (count == 1 && emailLength < 101)
    {
        for (int i = seLength; i < emailLength; i++)
        {
            // pink@gmail.com
            // i = 5 // seLength = 5
            int j = i - seLength;
            ase[j] = email[i];
        }
        bool isFirst = false;
        for (int i = 0; i < emailLength - seLength; i++)
        {
            for (int j = 0; j < emailLength - seLength; j++)
            {
                char c = g[j];
                if (c == ase[i])
                {
                    if (g[j - 1] != ase[i] && !isFirst)
                    {
                        isFirst = true;
                        iE = j;
                    }
                    break;
                }
            }
        }
        // if (isFirst && !strcmp(passDuplicate, se))
        //     return true;
        // return false;
    }

    if (!isValidEmail)
        return iE;

    bool isValidPass = false;
    return checkPassword_pass(s, email, se, isValidPass);
}
*/

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

    for (int i = 0; i < num_pwds; i++)
    {
        if (times[i] > times[i + 1] || times[i] == times[i + 1])
        {
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
    return firstRP;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////