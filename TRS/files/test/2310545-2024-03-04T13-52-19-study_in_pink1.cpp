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
// Make sure the value is right
void HPRangeControl(int &HP)
{
    HP = (HP < 0) ? 0 : HP;
    HP = (HP > 666) ? 666 : HP;
}

void EXPRangeControl(int &EXP)
{
    EXP = (EXP < 0) ? 0 : EXP;
    EXP = (EXP > 600) ? 600 : EXP;
}

void MRangeControl(int &M)
{
    M = (M < 0) ? 0 : M;
    M = (M > 3000) ? 3000 : M;
}

int percentOfValue(int value, float percent)
{
    if (percent > 1)
    {
        percent -= 1;
        return ceil(value + value * percent);
    }
    else
    {
        percent = 1 - percent;
        return ceil(value - value * percent);
    }
}
// Task 1
int firstMeet(int &EXP1, int &EXP2, int E1)
{
    // TODO: Complete this function
    if (E1 < 0 || E1 > 99)
    {
        return -99;
    }

    // 4.1.1
    if (E1 >= 0 && E1 <= 3)
    {
        int D;
        if (E1 == 0)
        {
            EXP2 += 29;
            D = E1 * 3 + EXP1 * 7;
            if (D % 2 == 0)
            {
                EXP1 = ceil(EXP1 + ((double)D / 200));
            }
            else
            {
                EXP1 = ceil(EXP1 - ((double)D / 100));
            }
        }
        else if (E1 == 1)
        {
            EXP2 += 45;
            D = E1 * 3 + EXP1 * 7;
            if (D % 2 == 0)
            {
                EXP1 = ceil(EXP1 + ((double)D / 200));
            }
            else
            {
                EXP1 = ceil(EXP1 - ((double)D / 100));
            }
        }

        else if (E1 == 2)
        {
            EXP2 += 75;
            D = E1 * 3 + EXP1 * 7;
            if (D % 2 == 0)
            {
                EXP1 = ceil(EXP1 + ((double)D / 200));
            }
            else
            {
                EXP1 = ceil(EXP1 - ((double)D / 100));
            }
        }
        else if (E1 == 3)
        {
            EXP2 += 149;
            D = E1 * 3 + EXP1 * 7;
            if (D % 2 == 0)
            {
                EXP1 = ceil(EXP1 + ((double)D / 200));
            }
            else
            {
                EXP1 = ceil(EXP1 - ((double)D / 100));
            }
        }

        EXPRangeControl(EXP1);
        EXPRangeControl(EXP2);
        return EXP1 + EXP2;
    }

    // 4.1.2
    else
    {
        if (E1 >= 4 && E1 <= 19)
        {
            EXP2 += ceil((double)E1 / 4 + 19);
        }
        else if (E1 >= 20 && E1 <= 49)
        {
            EXP2 += ceil((double)E1 / 9 + 21);
        }
        else if (E1 >= 50 && E1 <= 65)
        {
            EXP2 += ceil((double)E1 / 16 + 17);
        }
        else if (E1 >= 66 && E1 <= 79)
        {
            EXP2 += ceil((double)E1 / 4 + 19);
            if (EXP2 > 200)
            {
                EXP2 += ceil((double)E1 / 9 + 21);
            }
        }
        else if (E1 >= 80 && E1 <= 99)
        {
            EXP2 += ceil((double)E1 / 4 + 19);
            EXP2 += ceil((double)E1 / 9 + 21);
            if (EXP2 > 400)
            {
                EXP2 += ceil((double)E1 / 16 + 17);
                EXP2 = percentOfValue(EXP2, 1.15);
            }
        }
        EXP1 -= E1;
        EXPRangeControl(EXP1);
        EXPRangeControl(EXP2);
        return EXP1 + EXP2;
    }
}

// Task 2
void eventHP(int &HP, int &M, int &MS)
{
    if (HP < 200)
    {
        HP = percentOfValue(HP, 1.3f);
        M -= 150;
        MS += 150;
    }
    else
    {
        HP = percentOfValue(HP, 1.1f);
        M -= 70;
        MS += 70;
    }
}

void eventVehicle(int &EXP, int &M, int &MS)
{
    M -= (EXP < 400) ? 200 : 120;
    MS += (EXP < 400) ? 200 : 120;
    EXP = percentOfValue(EXP, 1.13f);
}

void eventHomeless(int &EXP, int &M, int &MS)
{
    M -= (EXP < 300) ? 100 : 120;
    MS += (EXP < 300) ? 100 : 120;
    EXP = percentOfValue(EXP, 0.9f);
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }

    double P1;
    int i = 0;
    int S1, S2, S;
    while (i * i <= EXP1)
    {
        S1 = i * i;
        ++i;
    }
    S2 = i * i;

    S = ((EXP1 - S1) < (S2 - EXP1)) ? S1 : S2;
    if (S <= EXP1)
    {
        P1 = 1;
    }
    else
    {
        P1 = ((double)EXP1 / (double)S + 80) / 123;
    }
    // Debug
    // cout << "S1: " << S1 << " "
    //      << "S2: " << S2 << " "
    //      << "P1: " << P1 << " "
    //      << "S: " << S;

    int moneySpent = 0;
    double halfOfMoneyBegin = 0.5 * (double)M1;

    while (true)
    {
        if (E2 % 2 != 0)
        {
            eventHP(HP1, M1, moneySpent);
            HPRangeControl(HP1);
            if (moneySpent > halfOfMoneyBegin)
            {
                HP1 = percentOfValue(HP1, 0.83f);
                EXP1 = percentOfValue(EXP1, 1.17f);
                break;
            }
            eventVehicle(EXP1, M1, moneySpent);
            EXPRangeControl(EXP1);
            if (moneySpent > halfOfMoneyBegin)
            {
                HP1 = percentOfValue(HP1, 0.83f);
                EXP1 = percentOfValue(EXP1, 1.17f);
                break;
            }
            eventHomeless(EXP1, M1, moneySpent);
            EXPRangeControl(EXP1);
            if (moneySpent > halfOfMoneyBegin)
            {
                HP1 = percentOfValue(HP1, 0.83f);
                EXP1 = percentOfValue(EXP1, 1.17f);
                break;
            }
        }
        else
        {
            eventHP(HP1, M1, moneySpent);
            HPRangeControl(HP1);
            if (M1 <= 0)
            {
                HP1 = percentOfValue(HP1, 0.83f);
                EXP1 = percentOfValue(EXP1, 1.17f);
                break;
            }
            eventVehicle(EXP1, M1, moneySpent);
            EXPRangeControl(EXP1);
            if (M1 <= 0)
            {
                HP1 = percentOfValue(HP1, 0.83f);
                EXP1 = percentOfValue(EXP1, 1.17f);
                break;
            }
            eventHomeless(EXP1, M1, moneySpent);
            EXPRangeControl(EXP1);
            if (M1 <= 0)
            {
                HP1 = percentOfValue(HP1, 0.83f);
                EXP1 = percentOfValue(EXP1, 1.17f);
                break;
            }
            HP1 = percentOfValue(HP1, 0.83f);
            EXP1 = percentOfValue(EXP1, 1.17f);
            break;
        }
    }

    HPRangeControl(HP1);
    EXPRangeControl(EXP1);
    MRangeControl(M1);

    // P2 Calc
    double P2;
    int j = 0;
    int A1, A2, A;
    while (j * j <= EXP1)
    {
        A1 = j * j;
        ++j;
    }
    A2 = j * j;

    A = ((EXP1 - A1) < (A2 - EXP1)) ? A1 : A2;
    if (A <= EXP1)
    {
        P2 = 1;
    }
    else
    {
        P2 = ((double)EXP1 / (double)A + 80) / 123;
    }

    // Debug
    // cout << "A1: " << A1 << " "
    //      << "A2: " << A2 << " "
    //      << "P2: " << P2 << " "
    //      << "A: " << A << endl
    //      << "EXP1: " << EXP1 << " "
    //      << "HP1: " << HP1 << " "
    //      << "M1: " << M1;

    double listP[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P3;

    if (E2 < 10)
    {
        P3 = listP[E2];
    }
    else
    {
        int a = E2 % 10;
        int temp = E2 / 10;
        int b = temp;
        int sum = a + b;
        P3 = listP[sum % 10];
    }
    // cout << "P3: " << P3;

    if (P1 == 1 && P2 == 1 && P3 == 100)
    {
        EXP1 = percentOfValue(EXP1, 0.75f);
    }
    else
    {
        double P = (P1 * 100 + P2 * 100 + P3) / 3;
        if (P < 50)
        {
            HP1 = percentOfValue(HP1, 0.85f);
            EXP1 = percentOfValue(EXP1, 1.15f);
        }
        else
        {
            HP1 = percentOfValue(HP1, 0.9f);
            EXP1 = percentOfValue(EXP1, 1.2f);
        }
    }

    HPRangeControl(HP1);
    EXPRangeControl(EXP1);
    MRangeControl(M1);

    return HP1 + EXP1 + M1;
}

// Task 3

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    struct Pos
    {
        int row;
        int column;
    };

    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }

    int road[10][10];
    int rowCount = 0;
    int columnCount = 0;
    Pos meetPos;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            road[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (road[i][j] > (E3 * 2))
            {
                rowCount++;
            }
            if (road[i][j] < -E3)
            {
                columnCount++;
            }
        }
    }
    if (rowCount > 9)
    {
        int a = rowCount % 10;
        int b = rowCount / 10;
        int sum = a + b;
        if (sum > 9)
        {
            a = sum % 10;
            b = sum / 10;
            sum = a + b;
        }
        meetPos.row = sum;
        // cout << sum << " ";
    }
    if (columnCount > 9)
    {
        int a = columnCount % 10;
        int b = columnCount / 10;
        int sum = a + b;
        if (sum > 9)
        {
            a = sum % 10;
            b = sum / 10;
            sum = a + b;
        }
        meetPos.column = sum;
        // cout << sum << " ";
    }

    int taxiPoint = road[meetPos.row][meetPos.column];

    Pos leftCross;
    leftCross.row = meetPos.row;
    leftCross.column = meetPos.column;
    while (true)
    {
        if (leftCross.row == 0 || leftCross.column == 0)
        {
            break;
        }
        leftCross.row -= 1;
        leftCross.column -= 1;
        if (leftCross.row == 0 || leftCross.column == 0)
        {
            break;
        }
    }
    // cout << leftCross.row << " " << leftCross.column << " ";
    Pos rightCross;
    rightCross.row = meetPos.row;
    rightCross.column = meetPos.column;
    while (true)
    {
        if (rightCross.row == 0 || rightCross.column == 9)
        {
            break;
        }
        rightCross.row -= 1;
        rightCross.column += 1;
        if (rightCross.row == 0 || rightCross.column == 9)
        {
            break;
        }
    }
    // cout << rightCross.row << " " << rightCross.column << " ";
    int a = road[leftCross.row][leftCross.column];
    while (true)
    {
        leftCross.row += 1;
        leftCross.column += 1;
        cout << "a: " << a << " ";
        if (road[leftCross.row][leftCross.column] > a)
        {
            cout << leftCross.row << " " << leftCross.column;
            a = road[leftCross.row][leftCross.column];
        }
        if (leftCross.row == 9 || leftCross.column == 9)
        {
            break;
        }
    }

    int b = road[rightCross.row][rightCross.column];
    while (true)
    {
        rightCross.row += 1;
        rightCross.column -= 1;
        if (road[rightCross.row][rightCross.column] > b)
        {
            b = road[rightCross.row][rightCross.column];
        }
        if (rightCross.row == 9 || rightCross.column == 0)
        {
            break;
        }
    }
    int SWPoint = (a >= b) ? a : b;
    if (abs(taxiPoint) > abs(SWPoint))
    {
        EXP1 = percentOfValue(EXP1, 0.88f);
        EXP2 = percentOfValue(EXP2, 0.88f);
        HP1 = percentOfValue(HP1, 0.9f);
        HP2 = percentOfValue(HP2, 0.9f);
        HPRangeControl(HP1);
        HPRangeControl(HP2);
        EXPRangeControl(EXP1);
        EXPRangeControl(EXP2);
        return taxiPoint;
    }
    else
    {
        EXP1 = percentOfValue(EXP1, 1.12f);
        EXP2 = percentOfValue(EXP2, 1.12f);
        HP1 = percentOfValue(HP1, 1.1f);
        HP2 = percentOfValue(HP2, 1.1f);
        HPRangeControl(HP1);
        HPRangeControl(HP2);
        EXPRangeControl(EXP1);
        EXPRangeControl(EXP2);
        return SWPoint;
    }
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    string mail = email;
    string PW = s;
    string se;

    se = mail.substr(0, mail.find("@"));

    // check if there are more than two same char
    bool isSameChar = false;
    int count = 0;
    int pos;
    for (int i = 0; i < PW.length() - 1; i++)
    {
        if (PW[i] == PW[i + 1])
        {
            count++;
        }
        else
        {
            count = 0;
        }
        if (count == 2)
        {
            pos = i - count + 1;
            isSameChar = true;
            break;
        }
    }

    // check if there isn't special char
    bool isContainSC = false;
    for (int i = 0; i < PW.length(); i++)
    {
        if (PW[i] == '@' || PW[i] == '#' || PW[i] == '$' || PW[i] == '!' || PW[i] == '%')
        {
            isContainSC = true;
            break;
        }
    }

    // check if password is valid
    bool isValidPW = true;
    int pos2;
    for (int i = 0; i < PW.length(); i++)
    {
        if (PW[i] == '@' || PW[i] == '#' || PW[i] == '$' || PW[i] == '!' || PW[i] == '%')
        {
            continue;
        }
        if ((int)PW[i] < 48)
        {
            isValidPW = false;
            pos2 = i;
            break;
        }
        else if ((int)PW[i] > 57 && (int)PW[i] < 64)
        {
            isValidPW = false;
            pos2 = i;
            break;
        }
        else if ((int)PW[i] > 90 && (int)PW[i] < 97)
        {
            isValidPW = false;
            pos2 = i;
            break;
        }
        else if ((int)PW[i] > 122)
        {
            isValidPW = false;
            pos2 = i;
            break;
        }
    }

    if (PW.length() < 8)
    {
        return -1;
    }
    else if (PW.length() > 20)
    {
        return -2;
    }
    else if (PW.find(se) != string::npos)
    {
        return -(300 + PW.find(se));
    }
    else if (isSameChar)
    {
        return -(400 + pos);
    }
    else if (!isContainSC)
    {
        return -5;
    }
    else if (!isValidPW)
    {
        return pos2;
    }
    else
    {
        return -10;
    }
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int countPW[30] = {0};
    string uniquePW[30];
    int count = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        bool isExisted = false;
        for (int j = 0; j < 30; j++)
        {
            if (arr_pwds[i] == uniquePW[j])
            {
                countPW[j] += 1;
                isExisted = true;
                break;
            }
        }
        if (!isExisted)
        {
            countPW[count] = 1;
            uniquePW[count] = arr_pwds[i];
            count++;
        }
    }
    // debug
    //  cout << countPW[1] << endl;
    //  cout << uniquePW[1];
    // for (int i = 0; i < 10; i++)
    // {
    //     // cout << uniquePW[i] << endl;
    // }
    // find the most frequently password
    int maxCount = 0;
    int mostFrequentIndex;
    for (int i = 0; i < 30; i++)
    {
        if (countPW[i] > maxCount)
        {
            maxCount = countPW[i];
            mostFrequentIndex = i;
        }
    }

    // find the correct password
    int correctIndex = mostFrequentIndex;
    for (int i = 0; i < 30; i++)
    {
        if ((countPW[i] == maxCount) && (uniquePW[i].length() > uniquePW[correctIndex].length()))
        {
            correctIndex = i;
        }
    }
    // find the position of correct password
    for (int i = 0; i < 30; i++)
    {
        if (arr_pwds[i] == uniquePW[correctIndex])
        {
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////