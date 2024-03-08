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
// Custom functon
double setCeil(double value)
{
    double intPart;
    float fracPart = modf(value, &intPart);
    if (fracPart >= 0.5 || fracPart <= -0.5 || abs(fracPart) > 1e-10)
    {

        return ceil(value);
    }
    else
    {
        return value;
    }
}
// Main function
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }
    exp1 = (exp1 < 0) ? 0 : (exp1 > 600) ? 600
                                         : exp1;
    exp2 = (exp2 < 0) ? 0 : (exp2 > 600) ? 600
                                         : exp2;

    if (e1 >= 0 && e1 <= 3)
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
            exp2 += 29 + 45 + 75;
            break;

        default:
            break;
        }

        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 = setCeil(exp1 + (double)D / 200);
        }
        else
        {
            exp1 = setCeil(exp1 - (double)D / 100);
        }
    }
    else if (e1 <= 99)
    {
        if (e1 <= 19)
        {
            exp2 = setCeil(exp2 + ((double)e1 / 4 + 19));
        }
        else if (e1 <= 49)
        {
            exp2 = setCeil(exp2 + ((double)e1 / 9 + 21));
        }
        else if (e1 <= 65)
        {
            exp2 = setCeil(exp2 + ((double)e1 / 16 + 17));
        }
        else if (e1 <= 79)
        {
            exp2 = setCeil(exp2 + ((double)e1 / 4 + 19));
            if (exp2 > 200)
            {
                exp2 = setCeil(exp2 + ((double)e1 / 9 + 21));
            }
        }
        else if (e1 <= 99)
        {
            exp2 = setCeil(exp2 + ((double)e1 / 4 + 19));
            exp2 = setCeil(exp2 + ((double)e1 / 9 + 21));
            if (exp2 > 400)
            {
                exp2 = setCeil(exp2 + ((double)e1 / 16 + 17));
                exp2 = setCeil(exp2 * 1.15);
            }
        }
        exp1 -= e1;
    }

    exp1 = (exp1 < 0) ? 0 : (exp1 > 600) ? 600
                                         : exp1;
    exp2 = (exp2 < 0) ? 0 : (exp2 > 600) ? 600
                                         : exp2;
    return exp1 + exp2;
}

// Task 2

// Custom functions
int findNearestSquareNumber(int number)
{
    int S = round(sqrt(number));
    S = S * S;
    return S;
}
// Main function
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    double P1, P2, P3;
    HP1 = (HP1 < 0) ? 0 : (HP1 > 666) ? 666
                                      : HP1;
    EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600
                                         : EXP1;
    M1 = (M1 < 0) ? 0 : (M1 > 3000) ? 3000
                                    : M1;
    if (E2 < 0 || E2 > 99)
        return -99;

    // Road 01
    int S = findNearestSquareNumber(EXP1);
    if (EXP1 >= S)
        P1 = 1.0;
    else
        P1 = ((static_cast<double>(EXP1) / S) + 80) / 123;

    // Road 02
    const double HALF_MONEY = M1 * 0.5;
    if (E2 >= 0 && E2 <= 99 && E2 % 2 != 0)
    {
        while (HALF_MONEY <= M1)
        {
            // Event one
            if (HP1 < 200)
            {
                HP1 = setCeil(HP1 * 1.3);
                M1 -= 150;
            }
            else
            {
                HP1 = setCeil(HP1 * 1.1);
                M1 -= 70;
            }

            HP1 = (HP1 < 0) ? 0 : (HP1 > 666) ? 666
                                              : HP1;
            M1 = (M1 < 0) ? 0 : (M1 > 3000) ? 3000
                                            : M1;

            if (HALF_MONEY > M1)
                break;
            // Event two
            if (EXP1 < 400)
                M1 -= 200;
            else
                M1 -= 120;

            EXP1 = setCeil(EXP1 * 1.13);
            EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600
                                                 : EXP1;
            M1 = (M1 < 0) ? 0 : (M1 > 3000) ? 3000
                                            : M1;

            if (HALF_MONEY > M1)
                break;
            // Event three
            if (EXP1 < 300)
                M1 -= 100;
            else
                M1 -= 120;

            EXP1 = setCeil(EXP1 * 0.9);

            EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600
                                                 : EXP1;
            M1 = (M1 < 0) ? 0 : (M1 > 3000) ? 3000
                                            : M1;

            if (HALF_MONEY > M1)
                break;
        }
        // Final Calculation
        HP1 = setCeil(HP1 * 0.83);
        EXP1 = setCeil(EXP1 * 1.17);
    }
    else if (E2 >= 0 && E2 <= 99 && E2 % 2 == 0)
    {
        for (int i = 0; i < 1; i++)
        {
            // Event one
            if (HP1 < 200)
            {
                HP1 = setCeil(HP1 * 1.3);
                M1 -= 150;
            }
            else if (HP1 >= 200)
            {
                HP1 = setCeil(HP1 * 1.1);
                M1 -= 70;
            }
            HP1 = (HP1 < 0) ? 0 : (HP1 > 666) ? 666
                                              : HP1;
            M1 = (M1 < 0) ? 0 : (M1 > 3000) ? 3000
                                            : M1;

            if (M1 == 0)
                break;
            // Event two
            if (EXP1 < 400)
                M1 -= 200;
            else
                M1 -= 120;

            M1 = (M1 < 0) ? 0 : (M1 > 3000) ? 3000
                                            : M1;

            EXP1 = setCeil(EXP1 * 1.13);

            EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600
                                                 : EXP1;

            if (M1 == 0)
                break;
            // Event three
            if (EXP1 < 300)
                M1 -= 100;
            else
                M1 -= 120;

            M1 = (M1 < 0) ? 0 : (M1 > 3000) ? 3000
                                            : M1;

            EXP1 = setCeil(EXP1 * 0.9);
            EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600
                                                 : EXP1;

            if (M1 == 0)
                break;
        }
        // Final Calculation
        HP1 = setCeil(HP1 * 0.83);
        EXP1 = setCeil(EXP1 * 1.17);
    }
    EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600
                                         : EXP1;
    HP1 = (HP1 < 0) ? 0 : (HP1 > 666) ? 666
                                      : HP1;

    int S2 = findNearestSquareNumber(EXP1);
    if (EXP1 >= S2)
        P2 = 1.0;
    else
        P2 = ((static_cast<double>(EXP1) / S2) + 80) / 123;

    // Road 03
    int arrP3[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int n;
    if (E2 >= 0 && E2 <= 9)
    {
        P3 = (arrP3[E2] / 100.0);
    }
    else
    {
        n = (E2 / 10) + (E2 % 10);
        if (n >= 0 && n <= 9)
            P3 = (arrP3[n] / 100.0);
        else
            P3 = (arrP3[n % 10] / 100.0);
    }

    double AVERAGE_PERCENTAGE = (P1 + P2 + P3) / 3.0;
    if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0)
    {
        EXP1 = setCeil(EXP1 * 0.75);
        EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600
                                             : EXP1;
    }
    else
    {
        if (AVERAGE_PERCENTAGE < 0.5)
        {
            HP1 = setCeil(HP1 * 0.85);
            EXP1 = setCeil(EXP1 * 1.15);
        }
        else if (AVERAGE_PERCENTAGE >= 0.5)
        {
            HP1 = setCeil(HP1 * 0.9);
            EXP1 = setCeil(EXP1 * 1.2);
        }
        EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600
                                             : EXP1;
        HP1 = (HP1 < 0) ? 0 : (HP1 > 666) ? 666
                                          : HP1;
    }

    return HP1 + EXP1 + M1;
}

// Task 3
// Custom functions
void createMap(int arr[][10], int numberEvent)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = ((numberEvent * j) + (i * 2)) * (i - j);
        }
    }
}
void showMap(int arr[][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << setw(5 + 1) << right << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int isMax(int arr[], int index)
{
    int max = arr[0];
    for (int i = 0; i <= index; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    if (max < 0)
    {
        // cout << "less than 0" << endl;
        // cout << max << endl;
        // cout << abs(max) << endl;
        return abs(max);
    }
    return max;
}
int diagonalLeft(int i, int j, int arr[], int m[][10], int index)
{
    // i = (i > 9) ? 9 : i;
    // j = (j > 9) ? 9 : j;
    arr[index] = m[i][j];
    // cout << "i: " << i << " "
    //      << "j: " << j << endl;
    // cout << "array at " << index << " is " << arr[index] << endl;
    if (i != 9 && j != 9)
    {
        return diagonalLeft(i + 1, j + 1, arr, m, index + 1);
    }
    else
    {
        return isMax(arr, index);
    }
}
int diagonalRight(int i, int j, int arr[], int m[][10], int index)
{
    // i = (i > 9) ? 9 : i;
    // j = (j > 9) ? 9 : j;
    arr[index] = m[i][j];
    // cout << "i: " << i << " "
    //      << "j: " << j << endl;
    // cout << "array at " << index << " is " << arr[index] << endl;
    if (i != 9 && j != 0)
    {
        return diagonalRight(i + 1, j - 1, arr, m, index + 1);
    }
    else
    {
        return isMax(arr, index);
    }
}
int calculateDiagonalLeft(int i, int j, int arr[], int m[][10])
{
    // i = (i < 0) ? 0 : i;
    // j = (j < 0) ? 0 : j;

    // cout << "i: " << i << "j: " << j << endl;
    // cout << "array true: " << arr[0] << endl;
    if (i != 0 && j != 0)
    {
        return calculateDiagonalLeft(i - 1, j - 1, arr, m);
    }
    else
    {
        return diagonalLeft(i, j, arr, m, 0);
    }
}
int calculateDiagonalRight(int i, int j, int arr[], int m[][10])
{
    // i = (i < 0) ? 0 : i;
    // j = (j < 0) ? 0 : j;

    // cout << "i: " << i << "j: " << j << endl;
    // cout << "array true: " << arr[0] << endl;
    if (i != 0 && j != 9)
    {
        return calculateDiagonalRight(i - 1, j + 1, arr, m);
    }
    else
    {
        return diagonalRight(i, j, arr, m, 0);
    }
}
int findMax(int i, int j, int M[][10])
{
    int arrLeft[100];
    int arrRight[100];
    int maxLeft = calculateDiagonalLeft(i, j, arrLeft, M);
    // cout << "max left: " << maxLeft << endl;
    int maxRight = calculateDiagonalRight(i, j, arrRight, M);
    // cout << "max right: " << maxRight << endl;
    if (maxLeft > maxRight)
    {
        return maxLeft;
    }
    else
    {
        return maxRight;
    }
}
int calculateCords(int number, int sum)
{
    // cout << "before number: " << number << endl;
    while (number != 0)
    {
        sum += number % 10;
        number /= 10;
    }
    // cout << "number: " << sum << endl;
    if (sum >= 10)
    {
        number = sum;
        // cout << "after number:" << number << endl;
        return calculateCords(number, 0);
    }
    return sum;
}
int findCordsX(int number, int map[][10])
{
    int count = 0;
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j] > number * 2)
            {
                count++;
            }
        }
    }
    // cout << "X: " << count << endl;
    if (count >= 10)
    {
        sum = calculateCords(count, sum);
    }
    return sum;
}
int findCordsY(int number, int map[][10])
{
    int count = 0;
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j] < -number)
            {
                count++;
            }
        }
    }
    // cout << "Y: " << count << endl;
    if (count >= 10)
    {
        sum = calculateCords(count, sum);
    }
    return sum;
}

// Main function
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }
    int a = 1;
    int M[10][10];
    createMap(M, E3);
    // showMap(M);
    int i = findCordsX(E3, M);
    int j = findCordsY(E3, M);
    int max = findMax(i, j, M);
    // cout << "i: " << i << endl;
    // cout << "j: " << j << endl;
    // cout << "max of both diagonals: " << max << endl;
    if (abs(M[i][j]) > max)
    {
        EXP1 = setCeil(EXP1 * 0.88);
        EXP2 = setCeil(EXP2 * 0.88);
        HP1 = setCeil(HP1 * 0.9);
        HP2 = setCeil(HP2 * 0.9);
        HP1 = (HP1 < 0) ? 0 : (HP1 > 666) ? 666
                                          : HP1;
        EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600
                                             : EXP1;
        HP2 = (HP2 < 0) ? 0 : (HP2 > 666) ? 666
                                          : HP2;
        EXP2 = (EXP2 < 0) ? 0 : (EXP2 > 600) ? 600
                                             : EXP2;
        return M[i][j];
    }
    else
    {
        EXP1 = setCeil(EXP1 * 1.12);
        EXP2 = setCeil(EXP2 * 1.12);
        HP1 = setCeil(HP1 * 1.1);
        HP2 = setCeil(HP2 * 1.1);
        HP1 = (HP1 < 0) ? 0 : (HP1 > 666) ? 666
                                          : HP1;
        EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600
                                             : EXP1;
        HP2 = (HP2 < 0) ? 0 : (HP2 > 666) ? 666
                                          : HP2;
        EXP2 = (EXP2 < 0) ? 0 : (EXP2 > 600) ? 600
                                             : EXP2;
        return max;
    }
}

// Task 4
// Custom functions
void getString(const char *email, char *se)
{
    int i;
    for (i = 0; email[i] != '@' && email[i] != '\0'; i++)
    {
        se[i] = email[i];
    }
    se[i] = '\0';
    // cout << "string: " << se << endl;
}
int checkLength(const char *s)
{
    return strlen(s) < 8 ? -1 : strlen(s) > 20 ? -2
                                               : -10;
}
int findStringIndex(const char *mainstring, char *substring)
{
    string stringContainer;
    string substringContainer;
    size_t sizeString = strlen(mainstring);
    size_t sizeSubString = strlen(substring);

    for (int i = 0; i < sizeString; i++)
    {
        stringContainer += mainstring[i];
    }
    for (int i = 0; i < sizeSubString; i++)
    {
        substringContainer += substring[i];
    }
    // cout << "String: " << stringContainer << endl;
    // cout << "SubString: " << substringContainer << endl;

    int found = stringContainer.find(substringContainer);
    // cout << "index: " << found << endl;
    if (found != string::npos)
    {
        return -(300 + found);
    }
    else
        return -10;
}
int findConsecutive(const char *mainstring)
{
    int count = 0;
    int index;
    size_t sizeString = strlen(mainstring);
    for (int i = 0; i < sizeString; i++)
    {
        if (i + 2 > sizeString)
            break;
        if (mainstring[i] == mainstring[i + 1] && mainstring[i] == mainstring[i + 2])
        {
            // cout << "string1: " << mainstring[i] << endl;
            // cout << "string2: " << mainstring[i + 1] << endl;
            // cout << "string3: " << mainstring[i + 2] << endl;
            // cout << "size: " << sizeString << endl;
            index = i;
            // cout << "i: " << index << endl;
            // cout << "final: " << -(400 + index) << endl;
            return -(400 + index);
        }
    }
    return -10;
}
int checkSpecialCharacters(const char *mainstring)
{
    size_t sizeString = strlen(mainstring);
    int flag = 0;
    for (int i = 0; i < sizeString; i++)
    {
        if (mainstring[i] == '!' || mainstring[i] == '@' || mainstring[i] == '#' || mainstring[i] == '$' || mainstring[i] == '%')
        {
            flag = 1;
        }
        else
        {
            continue;
        }
    }
    if (flag == 0)
    {
        return -5;
    }
    return -10;
}
int checkGeneral(const char *mainstring)
{
    size_t sizeString = strlen(mainstring);
    int flag = 0;
    for (int i = 0; i < sizeString; i++)
    {
        if (mainstring[i] >= 48 && mainstring[i] <= 57 || mainstring[i] >= 65 && mainstring[i] <= 90 || mainstring[i] >= 97 && mainstring[i] <= 122)
        {
            continue;
        }
        else if (mainstring[i] == '!' || mainstring[i] == '@' || mainstring[i] == '#' || mainstring[i] == '$' || mainstring[i] == '%')
        {
            continue;
        }
        else
        {
            return i;
        }
    }
    return -10;
}

// Main function
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    int result[100];
    char emailString[100];
    getString(email, emailString);
    // size_t size = strlen(emailString);
    // for (int i = 0; i < size; i++)
    // {
    //     // subString += se[i];
    //     cout << "String 2: " << emailString[i] << endl;
    // }
    result[0] = checkLength(s);
    result[1] = findStringIndex(s, emailString);
    result[2] = findConsecutive(s);
    result[3] = checkSpecialCharacters(s);
    result[4] = checkGeneral(s);

    for (int i = 0; i < 5; i++)
    {
        // cout << "result at " << i << " " << result[i] << endl;
        if (result[i] != -10)
        {
            // cout << "result: " << result[i] << " index: " << i << endl;
            return result[i];
            break;
        }
    }
    return -10;
}

// Task 5
// Custom functions
int mostFrequent(string *arr, int n)
{
    int maxLength = 0;
    int freqMax = 0;
    string elementMax;
    int position = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > freqMax)
        {

            freqMax = count;
            elementMax = arr[i];
            position = i;
        }
        if (count == freqMax)
        {
            if (arr[i].length() > maxLength)
            {
                maxLength = arr[i].length();
                freqMax = count;
                elementMax = arr[i];
                position = i;
            }
        }
    }
    // cout << "Password appeared most: " << elementMax << endl;
    // cout << "Password length: " << maxLength << endl;
    return position;
}
// Main function
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    string passwordContainer[num_pwds];
    for (int i = 0; i < num_pwds; i++)
    {
        passwordContainer[i] = arr_pwds[i];
    }
    int position = mostFrequent(passwordContainer, num_pwds);

    return position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////