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

// Additional functions

void checkValidMission1(int &exp1, int &exp2)
{
    if (exp1 > 600)
        exp1 = 600;
    if (exp1 < 0)
        exp1 = 0;
    if (exp2 > 600)
        exp2 = 600;
    if (exp2 < 0)
        exp2 = 0;
}
void checkValidMission2(int &HP1, int &EXP1, int &M1)
{
    if (HP1 > 666)
        HP1 = 666;
    if (HP1 < 0)
        HP1 = 0;
    if (EXP1 > 600)
        EXP1 = 600;
    if (EXP1 < 0)
        EXP1 = 0;
    if (M1 > 3000)
        M1 = 3000;
    if (M1 < 0)
        M1 = 0;
}
double findNearestPerfectSquare(double exp1)
{
    double a = floor(sqrt(exp1)) * floor(sqrt(exp1));
    double b = ceil(sqrt(exp1)) * ceil(sqrt(exp1));
    return ((exp1 - a) < (b - exp1) ? a : b);
}
double findProb(int EXP1)
{
    double P1;
    double S = findNearestPerfectSquare(EXP1);
    if (EXP1 >= S)
        P1 = 1;
    else
        P1 = (EXP1 / S + 80) / 123.0;
    return P1;
}
int findI(int E2)
{
    int i;
    if (E2 / 10 == 0)
        i = E2;
    else
    {
        int sum = E2 / 10 + E2 % 10;
        i = sum % 10;
    }
    return i;
}
int maxOfDiag(int matrix[10][10], int i, int j) // Find the maximum value in the left and right diagonol of the point (i,j)
{
    int max = matrix[i][j];
    for (int temp1 = i, temp2 = j; temp1 >= 0 && temp2 >= 0 && temp1 < 10 && temp2 < 10; temp1++, temp2++)
    {
        if (matrix[temp1][temp2] > max)
            max = matrix[temp1][temp2];
    }
    for (int temp1 = i, temp2 = j; temp1 >= 0 && temp2 >= 0 && temp1 < 10 && temp2 < 10; temp1--, temp2--)
    {
        if (matrix[temp1][temp2] > max)
            max = matrix[temp1][temp2];
    }
    for (int temp1 = i, temp2 = j; temp1 >= 0 && temp2 >= 0 && temp1 < 10 && temp2 < 10; temp1++, temp2--)
    {
        if (matrix[temp1][temp2] > max)
            max = matrix[temp1][temp2];
    }
    for (int temp1 = i, temp2 = j; temp1 >= 0 && temp2 >= 0 && temp1 < 10 && temp2 < 10; temp1--, temp2++)
    {
        if (matrix[temp1][temp2] > max)
            max = matrix[temp1][temp2];
    }
    return max;
}
void checkValidMission3(int &HP1, int &EXP1, int &HP2, int &EXP2)
{
    if (HP1 > 666)
        HP1 = 666;
    if (HP1 < 0)
        HP1 = 0;
    if (EXP1 > 600)
        EXP1 = 600;
    if (EXP1 < 0)
        EXP1 = 0;
    if (HP2 > 666)
        HP2 = 666;
    if (HP2 < 0)
        HP2 = 0;
    if (EXP2 > 600)
        EXP2 = 600;
    if (EXP2 < 0)
        EXP2 = 0;
}
void findSE(const char *email, char *se) // Find the se from the given email
{
    int i = 0;
    while (email[i] != '@')
    {
        se[i] = email[i];
        i += 1;
    }
    se[i] = '\0';
}
bool checkSE(const char *s, char *se, int &SEindex) // Check whether the password s contains se or not and if yes change the SEindex parameter
{
    int sizeS = strlen(s);
    int sizeSE = strlen(se);
    for (int i = 0; i < sizeS; ++i)
    {
        if (s[i] != se[0])
            continue;
        else
        {
            int j;
            for (j = 0; j < sizeSE; ++j)
            {
                if (s[i + j] != se[j])
                    break;
            }
            if (j == sizeSE)
            {
                SEindex = i;
                return 1;
            }
        }
    }
    return 0;
}
bool checkValidSpecialChar(const char *s) // Check whether the password s contains at least 1 special charatcter or not
{
    int specChar = 0;
    int size = strlen(s);
    for (int i = 0; i < size; ++i)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            specChar += 1;
    }
    if (specChar == 0)
        return 0;
    return 1;
}
int max(const int *tempArr, const char *arr_pwds[], int num_pwds) // Find the index of the password that appears most times and contains most character
{
    int indexes[30];
    int maxIndex = 0;
    for (int i = 0; i < num_pwds; ++i)
    {
        if (tempArr[i] > tempArr[maxIndex])
        {
            maxIndex = i;
        }
    }
    indexes[0] = maxIndex;
    int temp = 1;
    for (int i = maxIndex + 1; i < num_pwds; ++i)
    {
        if (tempArr[i] == tempArr[maxIndex])
        {
            indexes[temp] = i;
            temp += 1;
        }
    }
    int maxChar = 0;
    int indexwithmaxChar = 0;
    for (int i = 0; i < temp; ++i)
    {
        int charSize = strlen(arr_pwds[indexes[i]]);
        if (charSize > maxChar)
        {
            maxChar = charSize;
            indexwithmaxChar = indexes[i];
        }
    }
    return indexwithmaxChar;
}
bool areSamePasswords(const char *password1, const char *password2) // Check whether 2 passwords are completely the same or not
{
    int size1 = strlen(password1);
    int size2 = strlen(password2);
    if (size1 != size2)
        return 0;
    for (int i = 0; i < size1; ++i)
    {
        if (password1[i] != password2[i])
            return 0;
    }
    return 1;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
        return -99;
    checkValidMission1(exp1, exp2);
    if (e1 >= 0 && e1 <= 3) // Case 1
    {
        if (e1 == 0)
            exp2 += 29;
        else if (e1 == 1)
            exp2 += 45;
        else if (e1 == 2)
            exp2 += 75;
        else if (e1 == 3)
            exp2 = exp2 + 29 + 45 + 75;
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            exp1 = ceil(exp1 + D / 200.0);
        else
            exp1 = ceil(exp1 - D / 100.0);
        checkValidMission1(exp1, exp2);
        return exp1 + exp2;
    }
    if (e1 >= 4 && e1 <= 99) // Case 2
    {
        if (e1 <= 19)
            exp2 = ceil(exp2 + e1 / 4.0 + 19);
        else if (e1 <= 49)
        {
            exp2 = ceil(exp2 + e1 / 9.0 + 21);
        }
        else if (e1 <= 65)
            exp2 = ceil(exp2 + e1 / 16.0 + 17);
        else if (e1 <= 79)
        {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);
            checkValidMission1(exp1, exp2);
            if (exp2 > 200)
            {
                exp2 = ceil(exp2 + e1 / 9.0 + 21);
            }
        }
        else
        {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);
            checkValidMission1(exp1, exp2);
            exp2 = ceil(exp2 + e1 / 9.0 + 21);
            checkValidMission1(exp1, exp2);
            if (exp2 > 400)
            {
                exp2 = ceil(exp2 + e1 / 16.0 + 17);
                exp2 = ceil(exp2 * 1.15);
            }
        }
        exp1 -= e1;
        checkValidMission1(exp1, exp2);
        return exp1 + exp2;
    }
    return -99;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
        return -99;
    checkValidMission2(HP1, EXP1, M1);
    // Road 1
    double P1 = findProb(EXP1);
    // Road 2
    int initialMoney = M1;
    int paidMoney = 0;
    if (M1 != 0)
    {
        if (E2 % 2 == 1)
        {
            while (true)
            {
                // Case a
                if (HP1 < 200)
                {
                    HP1 = int(HP1 * 1.3 + 0.999);
                    M1 -= 150;
                    paidMoney += 150;
                }
                else
                {
                    HP1 = int(HP1 * 1.1 + 0.999);
                    M1 -= 70;
                    paidMoney += 70;
                }
                checkValidMission2(HP1, EXP1, M1);
                if (paidMoney > 0.5 * initialMoney)
                    break;
                // Case b
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    paidMoney += 200;
                }
                else
                {
                    M1 -= 120;
                    paidMoney += 120;
                }
                EXP1 = int(EXP1 * 1.13 + 0.999);
                checkValidMission2(HP1, EXP1, M1);
                if (paidMoney > 0.5 * initialMoney)
                    break;
                // Case c
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    paidMoney += 100;
                }
                else
                {
                    M1 -= 120;
                    paidMoney += 120;
                }
                EXP1 = int(EXP1 * 0.9 + 0.999);
                checkValidMission2(HP1, EXP1, M1);
                if (paidMoney > 0.5 * initialMoney)
                    break;
            }
        }
        else if (E2 % 2 == 0)
        {
            // Case a
            if (HP1 < 200)
            {
                HP1 = int(HP1 * 1.3 + 0.999);
                M1 -= 150;
            }
            else
            {
                HP1 = int(HP1 * 1.1 + 0.999);
                M1 -= 70;
            }
            checkValidMission2(HP1, EXP1, M1);
            if (M1 > 0)
            {
                // Case b
                if (EXP1 < 400)
                {
                    M1 -= 200;
                }
                else
                {
                    M1 -= 120;
                }
                EXP1 = int(EXP1 * 1.13 + 0.999);
                checkValidMission2(HP1, EXP1, M1);
                if (M1 > 0)
                {
                    // Case c
                    if (EXP1 < 300)
                    {
                        M1 -= 100;
                    }
                    else
                    {
                        M1 -= 120;
                    }
                    EXP1 = int(EXP1 * 0.9 + 0.999);
                    checkValidMission2(HP1, EXP1, M1);
                }
            }
        }
    }
    HP1 = int(HP1 * 0.83 + 0.999);
    EXP1 = int(EXP1 * 1.17 + 0.999);
    checkValidMission2(HP1, EXP1, M1);
    double P2 = findProb(EXP1);
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = findI(E2);
    double P3 = P[i] / 100.0;
    double averageP = (P1 + P2 + P3) / 3;
    if (averageP == 1)
        EXP1 = int(EXP1 * 0.75 + 0.999);
    else if (averageP < 0.5)
    {
        HP1 = int(HP1 * 0.85 + 0.999);
        EXP1 = int(EXP1 * 1.15 + 0.999);
        checkValidMission2(HP1, EXP1, M1);
    }
    else
    {
        HP1 = int(HP1 * 0.9 + 0.999);
        EXP1 = int(EXP1 * 1.2 + 0.999);
        checkValidMission2(HP1, EXP1, M1);
    }
    checkValidMission2(HP1, EXP1, M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;
    checkValidMission3(HP1, EXP1, HP2, EXP2);
    // Matrix[row][col]
    int matrix[10][10] = {};
    // Find meet point (i,j)
    int i = 0;
    int j = 0;
    for (int row = 0; row < 10; ++row)
    {
        for (int col = 0; col < 10; ++col)
        {
            matrix[row][col] = (E3 * col + (row * 2)) * (row - col);
            if (matrix[row][col] > (E3 * 2))
                i += 1;
            else if (matrix[row][col] < (-E3))
                j += 1;
        }
    }
    while (i / 10 != 0)
        i = i / 10 + i % 10;
    while (j / 10 != 0)
        j = j / 10 + j % 10;
    int max = maxOfDiag(matrix, i, j);
    if (abs(matrix[i][j]) > max)
    {
        HP1 = int(HP1 * 0.9 + 0.999);
        EXP1 = int(EXP1 * 0.88 + 0.999);
        HP2 = int(HP2 * 0.9 + 0.999);
        EXP2 = int(EXP2 * 0.88 + 0.999);
    }
    else
    {
        HP1 = int(HP1 * 1.1 + 0.999);
        EXP1 = int(EXP1 * 1.12 + 0.999);
        HP2 = int(HP2 * 1.1 + 0.999);
        EXP2 = int(EXP2 * 1.12 + 0.999);
    }
    checkValidMission3(HP1, EXP1, HP2, EXP2);
    return (abs(matrix[i][j]) > max ? matrix[i][j] : max);
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    int size = strlen(s);
    // Requirement 1
    if (size < 8)
        return -1;
    // Requirement 2
    if (size > 20)
        return -2;
    // Requirement 3
    char se[100];
    findSE(email, se);
    if (se[0] == 0)
        return -300;
    int SEindex;
    if (checkSE(s, se, SEindex))
    {
        return -(300 + SEindex);
    }
    // Requirement 4
    for (int i = 0; i < size - 2; ++i)
    {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
            return -(400 + i);
    }
    // Requirement 5
    if (!checkValidSpecialChar(s))
        return -5;
    // Requirement 6
    for (int i = 0; i < size; ++i)
    {
        if (s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!' && (s[i] < '0' || s[i] > '9') && (s[i] < 'A' || s[i] > 'Z') && (s[i] < 'a' || s[i] > 'z'))
            return i;
    }
    // Requirement 0
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int tempArr[40];
    // tempArr[i] stores the number of appearances (số lần xuất hiện) of the password arr_pwds[i] counted from i to last (num_pwds)
    for (int i = 0; i < num_pwds; ++i)
    {
        int temp = 1;
        for (int j = i + 1; j < num_pwds; ++j)
        {
            if (areSamePasswords(arr_pwds[i], arr_pwds[j]))
            {
                temp += 1;
            }
        }
        tempArr[i] = temp;
    }
    int index = max(tempArr, arr_pwds, num_pwds);
    // cout << "Password " << arr_pwds[index] << " appears most frequently with " << tempArr[index] << " time(s)" << endl;
    return index;
} ////////////////////////////////////////////////
  /// END OF STUDENT'S ANSWER
  ////////////////////////////////////////////////