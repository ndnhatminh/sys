#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & E1,
        int & E2,
        int & E3
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
    }
    else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

int roundUp(float Num)
{
    return Num + 0.999;
}
void moneyCheck(int* M)
{
    if (*M > 3000) *M = 3000;
    else if (*M < 0) *M = 0;
}
void expCheck(int* EXP)
{
    if (*EXP > 600) *EXP = 600;
    else if (*EXP < 0) *EXP = 0;
}
void hpCheck(int* HP)
{
    if (*HP > 666) *HP = 666;
    else if (*HP < 0) *HP = 0;
}
int maxArray(int* Array, int n)
{
    int MAX = Array[0];
    for (int i = 1; i < n; i++)
        if (Array[i] > MAX) MAX = Array[i];

    return MAX;
}

// Task 1
void sherlockGuess(int *EXP1, int E1)
{
    int D = E1 * 3 + (*EXP1) * 7;
    if (D % 2 == 0)
    {
        *EXP1 = roundUp(1.0f * (*EXP1) + ((1.0f * D) / 200));
        expCheck(EXP1);
    }
    else if (D % 2 == 1)
    {
        *EXP1 = roundUp(1.0f * (*EXP1) - ((1.0f * D) / 100));
        expCheck(EXP1);
    }
} 
int branch(int E1)
{
    if (E1 == 0) return 0;
    else if (E1 == 1) return 1;
    else if (E1 == 2) return 2;
    else if (E1 == 3) return 3;
    else if ((E1 > 3) && (E1 <= 19)) return 4;
    else if ((E1 >= 20) && E1 <= 49) return 5;
    else if ((E1 >= 50) && E1 <= 65) return 6;
    else if ((E1 >= 66) && E1 <= 79) return 7;
    else if ((E1 >= 80) && E1 <= 99) return 8;
    else return 9;
} 

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ((e1 < 0) || (e1 > 99)) return -99;
    expCheck(&exp1); expCheck(&exp2); 

    if ((e1 >= 0) && (e1 < 4)) sherlockGuess(&exp1, e1);
        else if (e1 <= 99) exp1 -= e1; 
    expCheck(&exp1);

    switch (branch(e1))
    {
    default:
        return -99;
    case 0:
        exp2 += 29;
        expCheck(&exp2);

        return exp1 + exp2;
    case 1:
        exp2 += 45;
        expCheck(&exp2);

        return exp1 + exp2;
    case 2:
        exp2 += 75;
        expCheck(&exp2);

        return exp1 + exp2;
    case 3:
        exp2 += 149;
        expCheck(&exp2);

        return exp1 + exp2;
    case 4:
        exp2 = roundUp(1.0f * exp2 + ((1.0f * e1) / 4) + 19);
        expCheck(&exp2);

        return exp1 + exp2;
    case 5:
        exp2 = roundUp(1.0f * exp2 + ((1.0f * e1) / 9) + 21);
        expCheck(&exp2);

        return exp1 + exp2;
    case 6:
        exp2 = roundUp(1.0f * exp2 + ((1.0f * e1) / 16) + 17);
        expCheck(&exp2);

        return exp1 + exp2;
    case 7:
        exp2 = roundUp(1.0f * exp2 + ((1.0f * e1) / 4) + 19);

        if (exp2 > 200) exp2 = roundUp(1.0f * exp2 + ((1.0f * e1) / 9) + 21);
        expCheck(&exp2);

        return exp1 + exp2;
    case 8:
        exp2 = roundUp(1.0f * exp2 + ((1.0f * e1) / 4) + 19);
        exp2 = roundUp(1.0f * exp2 + ((1.0f * e1) / 9) + 21);

        if (exp2 > 400)
        {
            exp2 = roundUp(1.0f * exp2 + ((1.0f * e1) / 16) + 17);
            exp2 = roundUp(exp2 * 1.15f);
        }
        expCheck(&exp2);

        return exp1 + exp2;
    }
}

// Task 2
void findSquare(int* Array)
{
    for (int i = 0; i < 25; i++) Array[i] = i * i;
}
float firstRoad(int EXP1)
{
    int* Array = new int[25];
    int* DistanceArray = new int[25];

    findSquare(Array);

    for (int i = 0; i < 25; i++) DistanceArray[i] = EXP1 - Array[i];

    int Min = std::abs(DistanceArray[0]), SignedMin = 0, SquaRes = 0;
    for (int i = 1; i < 25; i++)
        if(Min > std::abs(DistanceArray[i])) Min = std::abs(DistanceArray[i]);

    for (int i = 0; i < 25; i++)
        if (Min == abs(DistanceArray[i]))
        {
            SignedMin = DistanceArray[i];
            SquaRes = Array[i];
        }
    delete[] Array; delete[] DistanceArray;

    float Res = 100 * (((1.0f * EXP1) / (1.0f * SquaRes) + 80) / 123.0f);

    if (SignedMin >= 0) return 100;
    else return Res;
}

void roadAction1(int* HP1, int* M1)
{
    if (*HP1 < 200)
    {
        *HP1 = roundUp((*HP1) * 1.3f); *M1 -= 150; TotalSpend += 150;

        moneyCheck(M1);
        hpCheck(HP1);
    }
    else
    {
        *HP1 = roundUp((*HP1) * 1.1f); *M1 -= 70; TotalSpend += 70;

        moneyCheck(M1);
        hpCheck(HP1);
    }
}
void roadAction2(int* EXP1, int* HP1, int* M1)
{
    if (*EXP1 < 400)
    {
        (*M1) -= 200; TotalSpend += 200;

        moneyCheck(M1);
    }
    else
    {
        (*M1) -= 120; TotalSpend += 120;

        moneyCheck(M1);
    }
    *EXP1 = roundUp((*EXP1) * 1.13f);
    
    expCheck(EXP1);
}
void roadAction3(int* EXP1, int* HP1, int* M1)
{
    if ((*EXP1) < 300)
    {
        (*M1) -= 100; TotalSpend += 100;

        moneyCheck(M1);
    }
    else
    {
        (*M1) -= 120; TotalSpend += 120;

        moneyCheck(M1);
    }
    *EXP1 = roundUp((*EXP1) * 0.9f);
    
    expCheck(EXP1);
}
float secondRoad(int* EXP1, int* M1, int* HP1, int* E2)
{   
    int OriginalMoney = *M1;
    
    TotalSpend = 0;
    if ((*E2 % 2 == 1) && (*M1 != 0))
    {
        while (true)
        {
            roadAction1(HP1, M1); 
            if ((TotalSpend > 0.5f * OriginalMoney)) break;
            roadAction2(EXP1, HP1, M1); 
            if ((TotalSpend > 0.5f * OriginalMoney)) break;
            roadAction3(EXP1, HP1, M1); 
            if ((TotalSpend > 0.5f * OriginalMoney)) break;
        }
    }
    else if ((*E2 % 2 == 0) && (*M1 != 0))
    {
        for (int i = 0; i < 1; i++)
        {
            roadAction1(HP1, M1); if ((*M1) == 0) break;
            roadAction2(EXP1, HP1, M1); if ((*M1) == 0) break;
            roadAction3(EXP1, HP1, M1); if ((*M1) == 0) break;
        }
    }
    *HP1 = roundUp((*HP1) * 0.83f); hpCheck(HP1);
    *EXP1 = roundUp((*EXP1) * 1.17f); expCheck(EXP1);
    return firstRoad(*EXP1);
}

float thirdRoad(int E2)
{
    const int Array[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2 < 10) return Array[E2];
    else
    {
        int E2_1 = E2 / 10;
        int E2_2 = E2 % 10;
        return 1.0f * Array[(E2_1 + E2_2) % 10];
    }
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if ((E2 < 0) || (E2 > 99)) return -99;

    expCheck(&EXP1); hpCheck(&HP1); moneyCheck(&M1);

    double P1 = firstRoad(EXP1); 
    double P2 = secondRoad(&EXP1, &M1, &HP1, &E2); 
    double P3 = thirdRoad(E2); 

    if ((P1 + P2 + P3) / 3 == 100)
    {
        EXP1 = roundUp(EXP1 * 0.75f);
        expCheck(&EXP1);
    }
    else if ((P1 + P2 + P3) / 3 <= 50)
    {
        HP1 = roundUp(HP1 * 0.85f);
        hpCheck(&HP1);
        EXP1 = roundUp(EXP1 * 1.15f);
        expCheck(&EXP1);
    }
    else if ((P1 + P2 + P3) / 3 > 50)
    {
        HP1 = roundUp(HP1 * 0.9f);
        hpCheck(&HP1);
        EXP1 = roundUp(EXP1 * 1.2f);
        expCheck(&EXP1);
    }
    
    return HP1 + EXP1 + M1;
}

// Task 3
void fillArraywith(int* Arr, int MaxSize, int Value = 0)
{
    for (int i = 0; i < MaxSize; i++) Arr[i] = Value;
}

void taxiFill(int Taxi[10][10], int E3)
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) Taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
}

void findLeftCross(int Taxi[10][10], int PosX, int PosY, int* SizeLeft, int* LeftCross)
{
    int i = PosX; int j = PosY;
    for (; (i != -1) && (i != 10) && (j != -1) && (j != 10); i++)
    {
        LeftCross[*SizeLeft] = Taxi[i][j];
        (*SizeLeft)++; j++;
    }

    i = PosX - 1; j = PosY - 1;
    for (; (i != -1) && (i != 10) && (j != -1) && (j != 10); i--)
    {
        LeftCross[*SizeLeft] = Taxi[i][j];
        (*SizeLeft)++; j--;
    }
}
void findRightCross(int Taxi[10][10], int PosX, int PosY, int* SizeRight, int* RightCross)
{
    int i = PosX; int j = PosY;
    for (; (i != -1) && (i != 10) && (j != -1) && (j != 10); i++)
    {
        RightCross[*SizeRight] = Taxi[i][j];
        (*SizeRight)++; j--;
    }

    i = PosX - 1; j = PosY - 1;
    for (; (i != -1) && (i != 10) && (j != -1) && (j != 10); i--)
    {
        RightCross[*SizeRight] = Taxi[i][j];
        (*SizeRight)++; j++;
    }
}
void sherlockFill(int SherlockWatson[10][10], int Taxi[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int LeftCrossSize = 0, RightCrossSize = 0;
            int* LeftCross = new int[10]; int* RightCross = new int[10];

            fillArraywith(LeftCross, 10); fillArraywith(RightCross, 10);
            findLeftCross(Taxi, i, j, &LeftCrossSize, LeftCross);
            findRightCross(Taxi, i, j, &RightCrossSize, RightCross);
            
            SherlockWatson[i][j] = abs(std::max(maxArray(LeftCross, LeftCrossSize), maxArray(RightCross, RightCrossSize)));
            
            delete[] LeftCross; delete[] RightCross;
        }
    }
}

void countPos(int Taxi[10][10], int E3)
{
    PositiveNumber = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (Taxi[i][j] > (2 * E3)) PositiveNumber++;
        }
    }
    
    if (PositiveNumber >= 10) PositiveNumber = (PositiveNumber / 10) + (PositiveNumber % 10);
    if (PositiveNumber >= 10) PositiveNumber = (PositiveNumber / 10) + (PositiveNumber % 10);
}
void countNeg(int Taxi[10][10], int E3)
{
    NegativeNumber = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (Taxi[i][j] < -E3) NegativeNumber++;
        }
    }
    
    if (NegativeNumber > 10) NegativeNumber = (NegativeNumber / 10) + (NegativeNumber % 10);
    if (NegativeNumber > 10) NegativeNumber = (NegativeNumber / 10) + (NegativeNumber % 10);
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ((E3 < 0) || (E3 > 99)) return -99;

    hpCheck(&HP1); hpCheck(&HP2);
    expCheck(&EXP1); expCheck(&EXP2);

    int Taxi[10][10];
    taxiFill(Taxi, E3);

    int SherlockWatson[10][10];
    sherlockFill(SherlockWatson, Taxi);

    countPos(Taxi, E3); countNeg(Taxi, E3);

    if (abs(Taxi[PositiveNumber][NegativeNumber]) > SherlockWatson[PositiveNumber][NegativeNumber])
    {   
        EXP1 = roundUp(EXP1 * 0.88f);
        EXP2 = roundUp(EXP2 * 0.88f);
        HP1 = roundUp(HP1 * 0.9f);
        HP2 = roundUp(HP2 * 0.9f);
        hpCheck(&HP1); hpCheck(&HP2);
        expCheck(&EXP1); expCheck(&EXP2);

        return Taxi[PositiveNumber][NegativeNumber];
    }
    else
    {
        EXP1 = roundUp(EXP1 * 1.12f);
        EXP2 = roundUp(EXP2 * 1.12f);
        HP1 = roundUp(HP1 * 1.1f);
        HP2 = roundUp(HP2 * 1.1f);
        hpCheck(&HP1); hpCheck(&HP2);
        expCheck(&EXP1); expCheck(&EXP2);

        return SherlockWatson[PositiveNumber][NegativeNumber];
    }
}

// Task 4
bool checkSEI(const char* S, const char* SE, int* SEI, int SizeS, int SizeSE)
{
    if ((SizeS - (*SEI)) < SizeSE) return false;

    int j = 0;
    for (int i = (*SEI); SE[j] != '\0'; i++)
    {
        if (SE[j] != S[i])
        {
            (*SEI) += 1;
            return checkSEI(S, SE, SEI, SizeS, SizeSE);
        }
        j++;
    }

    return true;
}
bool checkSCI(const char* s, int* sci)
{

    for (; s[*sci] != '\0'; (*sci)++)
    {
        if ((s[*sci] == s[(*sci) + 1]) && (s[(*sci) + 1] == s[(*sci) + 2]))
        {
            return true;
        }
    }

    return false;
}
bool checkSpecial(const char* s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] == '@') || (s[i] == '#') || (s[i] == '%') || (s[i] == '$') || (s[i] == '!'))
            return true;
    }

    return false;
}
bool checkOther(const char* s, int* ot)
{
    for (; s[*ot] != '\0'; (*ot)++)
    {
        if (s[*ot] < 33) return true;
        if (s[*ot] == 34) return true;
        if ((s[*ot] > 37) && (s[*ot] < 48)) return true;
        if ((s[*ot] > 57) && (s[*ot] < 64)) return true;
        if ((s[*ot] > 90) && (s[*ot] < 97)) return true;
        if (s[*ot] > 122) return true;
    }

    return false;
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    int sizeSe = 0, i = 0, sizeS = 0, sei = 0, sci = 0, ot = 0;
    char* se = new char[100];
    se[0] = '\0';

    for (int i = 0; email[i] != '@'; i++)
    {
        se[i] = email[i];
        sizeSe++;
        se[i + 1] = '\0';
    }

    for (i = 0; s[i] != '\0'; i++)
    {
        sizeS++;
    }
  
    if (sizeS < 8)
    {
        delete[] se;
        return -1;
    }

    if (sizeS > 20)
    {
        delete[] se;
        return -2;
    }

    if (checkSEI(s, se, &sei, sizeS, sizeSe))
    {
        delete[] se;
        return -(300 + sei);
    }

    if (checkSCI(s, &sci))
    {
        delete[] se;
        return -(400 + sci);
    }

    if (!checkSpecial(s))
    {
        delete[] se;
        return -5;
    }

    if (checkOther(s, &ot))
    {
        delete[] se;
        return ot;
    }

    delete[] se;
    return -10;
}

// Task 5
bool checkDupe(const char* arr_pwds[], int *i, int position)
{
    if ((*i) == position) return false;

    if (findLength(arr_pwds[*i]) != findLength(arr_pwds[position]))
    {
        (*i)++;
        return checkDupe(arr_pwds, i, position);
    };

    for (int j = 0; ((arr_pwds[*i][j] != '\0') || (arr_pwds[position][j] != '\0')); j++)
    {
        if (arr_pwds[*i][j] != arr_pwds[position][j])
        {
            (*i)++;
            return checkDupe(arr_pwds, i, position);
        }
    }

    return true;
}
int findDupeinArray(int* pos, int poss)
{
    for (int i = 0; i < 30; i++)
    {
        if (pos[i] == poss) return i;
    }

    return -1;
}
int findLength(const char* pwds)
{
    int count = 0;
    for (int i = 0; pwds[i] != '\0'; i++) count++;

    return count;
}
void findMaxesinArray(int* arr, int* ResultArr, int *NumberOfMaxes)
{
    int MAX = arr[0];

    for (int i = 1; i < 30; i++) 
        if (MAX < arr[i]) MAX = arr[i];
    
    fillArraywith(ResultArr, 30, -1);

    for (int i = 0; i < 30; i++)
    {
        if (MAX == arr[i]) 
        {
            ResultArr[*NumberOfMaxes] = i;
            (*NumberOfMaxes)++;
        }
    }
}

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int pos[30] = { -1 }, count[30] = { 0 }, length[30] = { 0 };
    int* MaxCountsPos = new int[30];

    int MaxNumberOfDifferentPass = 0, NumberOfMaxDupes = 0, MaxLengthPos = 0;

    for (int i = 0; i < num_pwds; i++)
    {
        int OriginalDupePos = 0;
        if (checkDupe(arr_pwds, &OriginalDupePos, i))
        {
            count[findDupeinArray(pos, OriginalDupePos)]++;
        }
        else
        {
            pos[MaxNumberOfDifferentPass] = i;
            count[MaxNumberOfDifferentPass]++;
            length[MaxNumberOfDifferentPass] = findLength(arr_pwds[i]);
            MaxNumberOfDifferentPass++;
        }
    }

    findMaxesinArray(count, MaxCountsPos, &NumberOfMaxDupes);
    
    if (NumberOfMaxDupes == 1)
    {
        int MAX = pos[MaxCountsPos[0]];
        delete[] MaxCountsPos;

        return MAX;
    }

    for (int i = 0; MaxCountsPos[i] != -1; i++)
    {
        if (length[MaxCountsPos[i]] > length[MaxCountsPos[MaxLengthPos]]) MaxLengthPos = i;
    }

    int MAX = pos[MaxCountsPos[MaxLengthPos]];
    delete[] MaxCountsPos;

    return MAX;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////