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

// Those function is used to check the input of the testcase
void inputEXP1(int &EXP1)
{
    if (EXP1 < 0)
        EXP1 = 0;
    if (EXP1 > 600)
        EXP1 = 600;
}
void inputEXP2(int &EXP2)
{
    if (EXP2 < 0)
        EXP2 = 0;
    if (EXP2 > 600)
        EXP2 = 600;
}
void inputHP1(int &HP1)
{
    if (HP1 < 0)
        HP1 = 0;
    if (HP1 > 666)
        HP1 = 666;
}
void inputHP2(int &HP2)
{
    if (HP2 < 0)
        HP2 = 0;
    if (HP2 > 666)
        HP2 = 666;
}
void inputM1(int &M1)
{
    if (M1 < 0)
        M1 = 0;
    if (M1 > 3000)
        M1 = 3000;
}
void inputM2(int &M2)
{
    if (M2 < 0)
        M2 = 0;
    if (M2 > 3000)
        M2 = 3000;
}
bool inputE1(int &E1)
{
    if (E1 < 0)
        return true;
    if (E1 > 99)
        return true;

    return false;
}
bool inputE2(int &E2)
{
    if (E2 < 0)
        return true;
    if (E2 > 99)
        return true;

    return false;
}

// This function is used to check if the number is not an integer
bool isNotInteger(float x)
{
    return x - (int)x != 0;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    if (inputE1(e1))
        return -99;
    inputEXP1(exp1);
    inputEXP2(exp2);
    // TH1: switch case those simple cases in the task
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
    default:
        break;
    }
    // integer D:
    int d = e1 * 3 + exp1 * 7;
    // Cases for E1 that has these value: 0, 1, 2, 3:
    if (e1 == 0 || e1 == 1 || e1 == 2 || e1 == 3)
    {
        if (d % 2 == 0)
        {
            exp1 = exp1 + (float)d / 200 + 0.99;
        }
        else
        {
            exp1 = exp1 - (float)d / 100 + 0.99;
        }
    }

    // TH2
    //cases for E1 that has these value: 4, 5, ..., 99:
    if (e1 >= 4 && e1 <= 19)
    {
        if (isNotInteger((float)e1 / 4))
            exp2 = exp2 + (float)e1 / 4 + 19 + 0.9999;
        else
            exp2 = exp2 + (float)e1 / 4 + 19;
    }
    else if (e1 >= 20 && e1 <= 49)
    {
        if (isNotInteger((float)e1 / 9))
            exp2 = exp2 + (float)e1 / 9 + 21 + 0.9999;
        else
            exp2 = exp2 + (float)e1 / 9 + 21;
    }
    else if (e1 >= 50 && e1 <= 65)
    {
        if (isNotInteger((float)e1 / 16))
            exp2 = exp2 + (float)e1 / 16 + 17 + 0.9999;
        else
            exp2 = exp2 + (float)e1 / 16 + 17;
    }
    else if (e1 >= 66 && e1 <= 79)
    {
        if (isNotInteger((float)e1 / 4))
            exp2 = exp2 + (float)e1 / 4 + 19 + 0.9999;
        else
            exp2 = exp2 + (float)e1 / 4 + 19;
        if (exp2 > 200)
        {
            if (isNotInteger((float)e1 / 9))
                exp2 = exp2 + (float)e1 / 9 + 21 + 0.9999;
            else
                exp2 = exp2 + (float)e1 / 9 + 21;
        }
    }
    else if (e1 >= 80 && e1 <= 99)
    {
        if (isNotInteger((float)e1 / 4))
            exp2 = exp2 + (float)e1 / 4 + 19 + 0.9999;
        else
            exp2 = exp2 + (float)e1 / 4 + 19;
        if (isNotInteger((float)e1 / 9))
            exp2 = exp2 + (float)e1 / 9 + 21 + 0.9999;
        else
            exp2 = exp2 + (float)e1 / 9 + 21;
        if (exp2 > 400)
        {
            if (isNotInteger((float)e1 / 16))
                exp2 = exp2 + (float)e1 / 16 + 17 + 0.9999;
            else
                exp2 = exp2 + (float)e1 / 16 + 17;
            if (isNotInteger((float)exp2 * 1.15))
                exp2 = (float)exp2 * 1.15 + 0.9999;
            else
                exp2 = (float)exp2 * 1.15;
        }
    }
    else
    {
        inputEXP1(exp1);
        inputEXP2(exp2);
    }
    //This case is for E1 that is not in the range of 0 to 99
    if (e1 != 0 && e1 != 1 && e1 != 2 && e1 != 3 && e1 >= 4 && e1 <= 99)
    {
        exp1 = exp1 - e1 + 0.99;
    }

    inputEXP1(exp1);
    inputEXP2(exp2);
    return exp1 + exp2;
}

//Find the closest square number of integer n
int closestSquareNumber(int n)
{
    int a = sqrt(n);
    int b = a + 1;
    if (abs(n - a * a) < abs(n - b * b))
        return a * a;
    else
        return b * b;
}

//This function is used to calculate the percentage of the first road in task 2
double taskTwoStreet1(int exp1)
{
    int closest = closestSquareNumber(exp1);
    if (exp1 >= closest)
        return 100;
    else
        return ((double)exp1 / closest + 80) / 123 * 100;
}

//This function is used to calculate the percentage of the second road in task 2
double taskTwoStreet2(int &HP1, int &EXP1, int &M1, int E2)
{
    int halfM1 = M1 / 2;
    int m = 0;
    int sumM = 0;
    do
    {   
        //When E2 is an even number
        if (E2 % 2 == 0)
        {
            inputEXP1(EXP1);
            inputHP1(HP1);
            // Action 1:
            if (HP1 < 200)
            {
                m = 150;
                sumM += m;
                HP1 = (double)HP1 * 1.3 + 0.9999;
                M1 = M1 - m;
                if (M1 <= 0)
                    break;
            }
            else
            {
                m = 70;
                sumM += m;
                HP1 = (double)HP1 * 1.1 + 0.9999;
                M1 = M1 - m;
                if (M1 <= 0)
                    break;
            }
            inputEXP1(EXP1);
            inputHP1(HP1);
            // Action 2:
            if (EXP1 < 400)
            {
                m = 200;
                sumM += m;
                M1 = M1 - m;
                EXP1 = (double)EXP1 * 1.13 + 0.9999;
                if (M1 <= 0)
                    break;
            }
            else
            {
                m = 120;
                sumM += m;
                M1 = M1 - m;
                EXP1 = (double)EXP1 * 1.13 + 0.9999;
                if (M1 <= 0)
                    break;
            }
            inputEXP1(EXP1);
            inputHP1(HP1);

            // Action 3:
            if (EXP1 < 300)
            {
                m = 100;
                sumM += m;
                M1 = M1 - m;
                EXP1 = (double)EXP1 * 0.9 + 0.9999;
                if (M1 <= 0)
                    break;
            }
            else
            {
                m = 120;
                sumM += m;
                M1 = M1 - m;
                EXP1 = (double)EXP1 * 0.9 + 0.9999;
                if (M1 <= 0)
                    break;
            }
            inputEXP1(EXP1);
            inputHP1(HP1);
            inputM1(M1);
            break;
        }
        inputEXP1(EXP1);
        inputHP1(HP1);
        //When E2 is an odd number
        // Action 1:
        if (HP1 < 200)
        {
            m = 150;
            sumM += m;
            HP1 = (double)HP1 * 1.3 + 0.9999;
            M1 = M1 - m;
            if (sumM > halfM1 || M1 <= 0)
                break;
        }
        else
        {
            m = 70;
            sumM += m;
            HP1 = (double)HP1 * 1.1 + 0.9999;
            M1 = M1 - m;
            if (sumM > halfM1 || M1 <= 0)
                break;
        }
        inputEXP1(EXP1);
        inputHP1(HP1);
        // Action 2:
        if (EXP1 < 400)
        {
            m = 200;
            sumM += m;
            M1 = M1 - m;
            EXP1 = (double)EXP1 * 1.13 + 0.9999;
            if (sumM > halfM1 || M1 <= 0)
                break;
        }
        else
        {
            m = 120;
            sumM += m;
            M1 = M1 - m;
            EXP1 = (double)EXP1 * 1.13 + 0.9999;
            if (sumM > halfM1 || M1 <= 0)
                break;
        }
        inputEXP1(EXP1);
        inputHP1(HP1);

        // Action 3:
        if (EXP1 < 300)
        {
            m = 100;
            sumM += m;
            M1 = M1 - m;
            EXP1 = (double)EXP1 * 0.9 + 0.9999;
            if (sumM > halfM1 || M1 <= 0)
                break;
        }
        else
        {
            m = 120;
            sumM += m;
            M1 = M1 - m;
            EXP1 = (double)EXP1 * 0.9 + 0.9999;
            if (sumM > halfM1 || M1 <= 0)
                break;
        }
        inputEXP1(EXP1);
        inputHP1(HP1);
    } while (E2 % 2 != 0);
    inputEXP1(EXP1);
    inputHP1(HP1);
    inputM1(M1);
    HP1 = (double)HP1 * 0.83 + 0.9999;
    EXP1 = (double)EXP1 * 1.17 + 0.9999;
    inputEXP1(EXP1);
    inputHP1(HP1);
    inputM1(M1);
    //This return statement of road 2 has the same function of road 1, so i reuse the function taskTwoStreet1
    return taskTwoStreet1(EXP1);
}

//This function is used to calculate the integer of E2, which is used in road 3
//This function only take the digit < 10 of the number
int sumOfTwoDigitNumber(int n)
{
    if (n < 10)
        return n;
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n = n / 10;
    }
    return sum % 10;
}
//This function is used to return the P3 percentage of the road 3
double taskTwoStreet3(int E2)
{
    int arrayP[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int sum = sumOfTwoDigitNumber(E2);
    return arrayP[sum];
}

//main function of task 2
// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E3)
{
    //return -99 if the input is invalid
    if (inputE2(E3))
        return -99;
    double P1 = taskTwoStreet1(EXP1);
    double P2 = taskTwoStreet2(HP1, EXP1, M1, E3);
    double P3 = taskTwoStreet3(E3);
    double average = (P1 + P2 + P3) / 3;
    // TODO: Complete this function
    if (P1 == 100 && P2 == 100 && P3 == 100)
    {
        EXP1 = (double)EXP1 * 0.75 + 0.99;
    }
    else
    {
        if (average < 50)
        {
            HP1 = (double)HP1 * 0.85 + 0.99;
            EXP1 = (double)EXP1 * 1.15 + 0.99;
        }
        else if (average >= 50)
        {
            HP1 = (double)HP1 * 0.9 + 0.99;
            EXP1 = (double)EXP1 * 1.2 + 0.99;
        }
    }
    inputEXP1(EXP1);
    inputHP1(HP1);
    inputM1(M1);
    return HP1 + EXP1 + M1;
}

//This function is used to check max number of the 4 direction of the given position, which is used in task 3
int checkMaxInTask3(int arr[10][10], int rowsArr, int colsArr)
{
    int max = arr[rowsArr][colsArr];

    for (int i = rowsArr, j = colsArr; i < 10 && j < 10; i++, j++)
    {
        if (arr[i][j] > max)
        {
            max = arr[i][j];
        }
    }

    for (int i = rowsArr, j = colsArr; i >= 0 && j >= 0; i--, j--)
    {
        if (arr[i][j] > max)
        {
            max = arr[i][j];
        }
    }
    for (int i = rowsArr, j = colsArr; i < 10 && j >= 0; i++, j--)
    {
        if (arr[i][j] > max)
        {
            max = arr[i][j];
        }
    }
    for (int i = rowsArr, j = colsArr; i >= 0 && j < 10; i--, j++)
    {
        if (arr[i][j] > max)
        {
            max = arr[i][j];
        }
    }

    return max;
}

//This function return the position i, which is the number stand for row, used in task 3
int returnIinArr(int arr[10][10], int E3)
{
    int iIn = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] > (E3 * 2))
            {
                iIn++;
            }
        }
    }
    return iIn;
}

//This function return the position j, which is the number stand for column, used in task 3
int returnJinArr(int arr[10][10], int E3)
{
    int jIn = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] < (-E3))
            {
                jIn++;
            }
        }
    }
    return jIn;
}

//This function is used to calculate the sum of the digits of the number n
//This function is different to the sumOfTwoDigitNumber because it get still + even when the sum is greater than 9
int sumOfDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n = n / 10;
    }
    if (sum > 9)
    {
        return sumOfDigits(sum);
    }
    return sum;
}

//Main function of task 3
// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (inputE2(E3))
        return -99;
    // TODO: Complete this function
    int arr[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    int numI = sumOfDigits(returnIinArr(arr, E3));
    int numJ = sumOfDigits(returnJinArr(arr, E3));

    int taxiNum = arr[numI][numJ];
    int sherlockNum = checkMaxInTask3(arr, numI, numJ);

    if (abs(taxiNum) > abs(sherlockNum))
    {
        HP1 = (double)HP1 * 0.9 + 0.99;
        HP2 = (double)HP2 * 0.9 + 0.99;
        EXP1 = (double)EXP1 * 0.88 + 0.99;
        EXP2 = (double)EXP2 * 0.88 + 0.99;
        inputEXP1(EXP1);
        inputEXP2(EXP2);
        inputHP1(HP1);
        inputHP2(HP2);
        return taxiNum;
    }
    else
    {
        HP1 = (double)HP1 * 1.1 + 0.99;
        HP2 = (double)HP2 * 1.1 + 0.99;
        EXP1 = (double)EXP1 * 1.12 + 0.99;
        EXP2 = (double)EXP2 * 1.12 + 0.99;
        inputEXP1(EXP1);
        inputEXP2(EXP2);
        inputHP1(HP1);
        inputHP2(HP2);
        return sherlockNum;
    }

    return -1;
}

//return the substring of the email before the @
void returnSe(string &se, string email)
{
    for (int i = 0; i < email.length(); i++)
    {
        if (email[i] != '@')
        {
            se += email[i];
        }
        else
        {
            return;
        }
    }
}

//This function is used to compare the substring of the email with the given password
bool compareSubString(string newS, string se, int &index)
{
    for (int i = 0; i < newS.length(); i++)
    {
        if (i + se.length() > newS.length())
            break;
        if (newS.substr(i, se.length()) == se)
        {
            index = i;
            return true;
        }
    }
    return false;
}

//This function is used to check if the password has more than 2 same character
bool checkMoreThan2SameCharacter(string newS, int &index)
{
    for (int i = 0; i < newS.length(); i++)
    {
        if (newS[i] == newS[i + 1] && newS[i] == newS[i + 2])
        {
            index = i;
            return true;
        }
    }

    return false;
}

//This function is used to check if the password has special character
bool checkSpecialCharacter(string newS)
{
    int count = 0;
    for (int i = 0; i < newS.length(); i++)
    {
        if (newS[i] == '!' || newS[i] == '@' || newS[i] == '#' || newS[i] == '$' || newS[i] == '%' || newS[i] == '&')
        {
            count++;
        }
    }
    if (count > 0)
        return false;
    return true;
}

//This function is used to check if the password has unwanted character
bool checkUnwantedCharacter(string newS, int &index)
{
    for (int i = 0; i < newS.length(); i++)
    {
        char c = newS[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&')
        {
            continue;
        }
        else
        {
            index = i;
            return true;
        }
    }
    return false;
}

//This function is used to check if the email has more than 1 @
void returnDoubleACircle(string newEmail, int &index)
{
    int count = 0;
    int firstACircle = 0;
    for (int i = 0; i < newEmail.length(); i++)
    {
        if (newEmail[i] == '@')
        {
            count++;
            if (count == 1)
                firstACircle = i;
        }
    }

    if (count > 1)
    {
        index = firstACircle;
    }
}

//main function of task 4
// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    string newS = (string)s;
    string newEmail = (string)email;
    string se = "";
    returnSe(se, newEmail);

    int index = 0;

    //cases to return
    if (newS.length() < 8)
    {
        return -1;
    }
    else if (newS.length() > 20)
    {
        return -2;
    }
    else if (compareSubString(newS, se, index))
    {
        return -(300 + index);
    }
    else if (checkMoreThan2SameCharacter(newS, index))
    {
        return -(400 + index);
    }
    else if (checkSpecialCharacter(newS))
    {
        return -5;
    }
    else
    {
        returnDoubleACircle(newEmail, index);
        if (index != 0)
        {
            return index;
        }
        if (checkUnwantedCharacter(newS, index))
        {
            return index;
        }
    }

    return -10;
}

//This function is used to get the first index of the max number of the array, 
//and if there are more than 1 max number, it will return the first index of the longest password
int getFirstMaxIndex(const char *arr_pwds[], int index[], int num_pwds)
{
    int max = index[0];
    int firstIndex = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        if (index[i] > max)
        {
            max = index[i];
            firstIndex = i;
        }
    }
    string newS = (string)arr_pwds[firstIndex];
    int longestPwds = newS.length();
    for (int i = 0; i < num_pwds; i++)
    {
        string newS2 = (string)arr_pwds[i];
        if (index[i] == max)
        {
            if (newS2.length() > longestPwds)
            {
                longestPwds = newS2.length();
                firstIndex = i;
            }
        }
    }

    return firstIndex;
}

//main function of task 5
// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int index[num_pwds];

    //this loop is made to store the number of the same password in the index[num_pwds] array
    for (int i = 0; i < num_pwds; i++)
    {
        int count = 1;
        for (int j = 0; j < num_pwds; j++)
        {
            if (i == j)
                continue;
            string newS1 = (string)arr_pwds[i];
            string newS2 = (string)arr_pwds[j];
            if (newS1 == newS2)
            {
                count++;
            }
        }
        index[i] = count;
    }

    return getFirstMaxIndex(arr_pwds, index, num_pwds);
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////