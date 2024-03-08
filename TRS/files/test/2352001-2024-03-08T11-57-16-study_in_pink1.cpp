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
//Function to Make sure HP, EXP, M always in defined range 
void checkValidValueWaston(int &HP2, int &EXP2, int &M2)
{
    if (EXP2 > 600)
        EXP2 = 600;
    else if (EXP2 < 0)
        EXP2 = 0;
    if (M2 > 3000)
        M2 = 3000;
    else if (M2 < 0)
        M2 = 0;
    if (HP2 > 666)
        HP2 = 666;
    else if (HP2 < 0)
        HP2 = 0;
}
void checkValidValueSherlock(int &HP1, int &EXP1, int &M1)
{
    if (EXP1 > 600)
        EXP1 = 600;
    else if (EXP1 < 0)
        EXP1 = 0;
    if (M1 > 3000)
        M1 = 3000;
    else if (M1 < 0)
        M1 = 0;
    if (HP1 > 666)
        HP1 = 666;
    else if (HP1 < 0)
        HP1 = 0;
}
int firstMeet(int &exp1, int &exp2, int e1)
{
    // Respond to invalid event code
    if (e1 > 99 || e1 < 0)
        return -99;
    // Check EXP1 and EXP2 is valid or not
    if (exp1 > 600)
        exp1 = 600;
    else if (exp1 < 0)
        exp1 = 0;
    if (exp2 > 600)
        exp2 = 600;
    else if (exp2 < 0)
        exp2 = 0;
    // Case 1
    if (e1 == 0)
    {
        exp2 += 29;
    }
    else if (e1 == 1)
    {
        exp2 += 45;
    }
    else if (e1 == 2)
    {
        exp2 += 75;
    }
    else if (e1 == 3)
    {
        exp2 = exp2 + 29 + 45 + 75;
    }
    // Case 2
    else if (e1 >= 4 && e1 <= 19)
    {
        exp2 = exp2 + (e1 * 1.0 / 4) + 0.999 + 19;
    }
    else if (e1 >= 20 && e1 <= 49)
    {
        exp2 = exp2 + (e1 * 1.0 / 9) + 0.999 + 21;
    }
    else if (e1 >= 50 && e1 <= 65)
    {
        exp2 = exp2 + (e1 * 1.0 / 16) + 0.999 + 17;
    }
    else if (e1 >= 66 && e1 <= 79)
    {
        exp2 = exp2 + ((e1 * 1.0 / 4) + 0.999) + 19;
        if (exp2 > 600)
            exp2 = 600;
        else if (exp2 < 0)
            exp2 = 0;
        if (exp2 > 200)
        {
            exp2 = exp2 + ((e1 * 1.0 / 9) + 0.999) + 21;
        }
    }
    else
    {
        exp2 = exp2 + ((e1 * 1.0 / 4) + 0.999) + 19;
        if (exp2 > 600)
            exp2 = 600;
        else if (exp2 < 0)
            exp2 = 0;
        exp2 = exp2 + ((e1 * 1.0 / 9) + 0.999) + 21;
        if (exp2 > 600)
            exp2 = 600;
        else if (exp1 < 0)
            exp2 = 0;
        if (exp2 > 400)
        {
            exp2 = exp2 + ((e1 * 1.0 / 16) + 0.999) + 17;
            if (exp2 > 600)
                exp2 = 600;
            else if (exp2 < 0)
                exp2 = 0;
            exp2 = (exp2 * 1.15) + 0.999;
        }
    }
    // Calculate Decision and calculate exp1 for case 1:
    if (e1 <= 3)
    {
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 = exp1 + ((D * 1.0 / 200) + 0.999);
        }
        else
        {
            exp1 = (exp1 * 1.0 - (D * 1.0 / 100)) + 0.999;
        }
        if (exp1 > 600)
            exp1 = 600;
        else if (exp1 < 0)
            exp1 = 0;
    }
    // Calculate exp1 for case 2:
    else
        exp1 -= e1;

    if (exp1 > 600)
        exp1 = 600;
    else if (exp1 < 0)
        exp1 = 0;
    if (exp2 > 600)
        exp2 = 600;
    else if (exp1 < 0)
        exp2 = 0;
    return exp1 + exp2;
}

// Task 2
// Function to calculate the perfect square that nearest with the EXP
int perfectSquare(int exp)
{
    int nearestSquare = 0;
    int lowerSquare = 0;
    int higherSquare = 0;

    for (int i = 0; i * i <= exp; i++)
    {
        lowerSquare = i * i;
        higherSquare = (i + 1) * (i + 1);
    }

    if ((exp - lowerSquare) < (higherSquare - exp))
    {
        nearestSquare = lowerSquare;
    }
    else
    {
        nearestSquare = higherSquare;
    }

    return nearestSquare;
}

// Mission 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    //check whether E2 is in range or not
    if (E2 > 99 || E2 < 0)
        return -99;
    bool isEventEven = (E2 % 2 == 0);
    int paidMoney = 0;
    checkValidValueSherlock(HP1, EXP1, M1);
    double halfMoney = M1 * 0.5;

    // Road 1
    double P1 = 0;
    int S = perfectSquare(EXP1);
    // Handle value for P1
    P1 = (EXP1 >= S) ? 1 : ((EXP1 * 1.0 / S + 80) / 123);

    // Road 2
    // Case For E2 is odd Number
    while (!isEventEven)
    {
        if (M1 == 0)
            break;
        // Buying Food
        if (HP1 < 200)
        {
            HP1 = (1.3 * HP1) + 0.999;
            M1 -= 150;
            checkValidValueSherlock(HP1, EXP1, M1);
            paidMoney += 150;
            if (paidMoney > halfMoney)
            {
                checkValidValueSherlock(HP1, EXP1, M1);
                break;
            }
        }
        else
        {
            HP1 = (1.1 * HP1) + 0.999;
            M1 -= 70;
            checkValidValueSherlock(HP1, EXP1, M1);
            paidMoney += 70;
            if (paidMoney > halfMoney)
            {
                checkValidValueSherlock(HP1, EXP1, M1);
                break;
            }
        }
        checkValidValueSherlock(HP1, EXP1, M1);
        // Travel
        if (EXP1 < 400)
        {
            M1 -= 200;
            EXP1 = (EXP1 * 1.13) + 0.999;
            checkValidValueSherlock(HP1, EXP1, M1);
            paidMoney += 200;
            if (paidMoney > halfMoney)
            {
                checkValidValueSherlock(HP1, EXP1, M1);
                break;
            }
        }
        else
        {
            M1 -= 120;
            EXP1 = (EXP1 * 1.13) + 0.999;
            checkValidValueSherlock(HP1, EXP1, M1);
            paidMoney += 120;
            if (paidMoney > halfMoney)
            {
                checkValidValueSherlock(HP1, EXP1, M1);
                break;
            }
        }
        checkValidValueSherlock(HP1, EXP1, M1);
        // Meet homeless people
        if (EXP1 < 300)
        {
            M1 -= 100;
            EXP1 = (0.9 * EXP1) + 0.999;
            checkValidValueSherlock(HP1, EXP1, M1);
            paidMoney += 100;
            if (paidMoney > halfMoney)
            {
                checkValidValueSherlock(HP1, EXP1, M1);
                break;
            }
        }
        else
        {
            M1 -= 120;
            EXP1 = (0.9 * EXP1) + 0.999;
            checkValidValueSherlock(HP1, EXP1, M1);
            paidMoney += 120;
            if (paidMoney > halfMoney)
            {
                checkValidValueSherlock(HP1, EXP1, M1);
                break;
            }
        }
        checkValidValueSherlock(HP1, EXP1, M1);
    }
    // Case for E2 is even
    while (isEventEven)
    {
        if (M1 == 0)
            break;
        // Buying Food
        if (HP1 < 200)
        {
            HP1 = (1.3 * HP1) + 0.999;
            M1 -= 150;
            checkValidValueSherlock(HP1, EXP1, M1);
        }
        else
        {
            HP1 = (1.1 * HP1) + 0.999;
            M1 -= 70;
            checkValidValueSherlock(HP1, EXP1, M1);
        }
        checkValidValueSherlock(HP1, EXP1, M1);
        if (M1 == 0)
        {
            checkValidValueSherlock(HP1, EXP1, M1);
            break;
        }
        // Travel
        if (EXP1 < 400)
        {
            M1 -= 200;
            checkValidValueSherlock(HP1, EXP1, M1);
        }
        else
        {
            M1 -= 120;
            checkValidValueSherlock(HP1, EXP1, M1);
        }
        EXP1 = (EXP1 * 1.13) + 0.999;
        checkValidValueSherlock(HP1, EXP1, M1);
        if (M1 == 0)
        {
            checkValidValueSherlock(HP1, EXP1, M1);
            break;
        }
        // Meet homeless people
        if (EXP1 < 300)
        {
            M1 -= 100;
            checkValidValueSherlock(HP1, EXP1, M1);
        }
        else
            M1 -= 120;
        checkValidValueSherlock(HP1, EXP1, M1);
        EXP1 = (0.9 * EXP1) + 0.999;
        checkValidValueSherlock(HP1, EXP1, M1);
        break;
    }
    // Update HP1, EXP1
    HP1 = (HP1 * 0.83) + 0.999;
    EXP1 = (EXP1 * 1.17) + 0.999;
    checkValidValueSherlock(HP1, EXP1, M1);
    // Calculate probability P2
    double P2 = 0;
    int K = perfectSquare(EXP1);
    // Handle value for P2
    P2 = (EXP1 >= K) ? 1 : ((EXP1 * 1.0 / K + 80) / 123);

    // Road 3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P3 = 0;
    if (E2 < 10)
        P3 = P[E2] * 1.0 / 100;
    else
        P3 = P[(E2 / 10 + E2 % 10) % 10] * 1.0 / 100;

    // After going through all 3 routes
    if (P1 == 1 && P2 == 1 && P3 == 1)
    {
        EXP1 = (EXP1 * 0.75) + 0.999;
    }
    else
    {
        checkValidValueSherlock(HP1, EXP1, M1);
        double Probability = (P1 + P2 + P3) * 1.0 / 3;
        if (Probability < 0.5)
        {
            HP1 = (HP1 * 0.85) + 0.999;
            EXP1 = (EXP1 * 1.15) + 0.999;
        }
        else
        {
            HP1 = (HP1 * 0.9) + 0.999;
            EXP1 = (EXP1 * 1.20) + 0.999;
        }
    }
    // Make sure final values are in range
    checkValidValueSherlock(HP1, EXP1, M1);

    return HP1 + EXP1 + M1;
}

// Mission 3
//  Finding the largest value of left diagonal pass through a defined point X(i, j)
int maxLeftDiagonal(int map[10][10], int row, int col)
{
    int max = map[row][col];

    for (int i = 1; i + row < 10 && i + col < 10; i++)
    {
        if (max < map[row + i][col + i])
            max = map[row + i][col + i];
    }
    for (int i = 1; row - i >= 0 && col - i >= 0; i++)
    {
        if (max < map[row - i][col - i])
            max = map[row - i][col - i];
    }
    return max;
}
// Finding the largest value of right diagonal pass through a defined point X(i, j)
int maxRightDiagonal(int map[10][10], int row, int col)
{
    int max = map[row][col];
    for (int i = 1; row - i >= 0 && col + i < 10; i++)
    {
        if (max < map[row - i][col + i])
            max = map[row - i][col + i];
    }
    for (int i = 1; row + i < 10 && col - i >= 0; i++)
    {
        if (max < map[row + i][col - i])
            max = map[row + i][col - i];
    }

    return max;
}
//Find the max value of the left and right diagonal of the matrix
int maxValueForMatrix(int map[10][10], int row, int col)
{
    int result = max(maxRightDiagonal(map, row, col), maxLeftDiagonal(map, row, col));
    return result;
}
// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 < 0 || E3 > 99)
        return -99;
    int M1 = 0;
    checkValidValueSherlock(HP1, EXP1, M1);
    checkValidValueWaston(HP2, EXP2, M1);
    // Define Taxi Maps Score
    int taxiMap[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            taxiMap[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    // Define Sherlock and Waston matrix
    int WS[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            WS[i][j] = maxValueForMatrix(taxiMap, i, j);
        }
    }
    // Define meeting point
    int meet_i = 0;
    int meet_j = 0;

    // Counting loop
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (taxiMap[i][j] > E3 * 2)
                meet_i += 1;
            if (taxiMap[i][j] < -E3)
                meet_j += 1;
        }
    }
    // Sum the digits until they are less than or equal to 9
    while (meet_i > 9)
    {
        meet_i = meet_i / 10 + meet_i % 10;
    }
    while (meet_j > 9)
    {
        meet_j = meet_j / 10 + meet_j % 10;
    }

    if (abs(taxiMap[meet_i][meet_j]) > WS[meet_i][meet_j])
    {
        EXP1 = (EXP1 * 0.88) + 0.999;
        HP1 = (HP1 * 0.9) + 0.999;
        EXP2 = (EXP2 * 0.88) + 0.999;
        HP2 = (HP2 * 0.9) + 0.999;
        checkValidValueSherlock(HP1, EXP1, M1);
        checkValidValueWaston(HP2, EXP2, M1);
        return taxiMap[meet_i][meet_j];
    }
    else
    {
        EXP1 = (EXP1 * 1.12) + 0.999;
        HP1 = (HP1 * 1.1) + 0.999;
        EXP2 = (EXP2 * 1.12) + 0.999;
        HP2 = (HP2 * 1.1) + 0.999;
        checkValidValueSherlock(HP1, EXP1, M1);
        checkValidValueWaston(HP2, EXP2, M1);

        return WS[meet_i][meet_j];
    }
    checkValidValueSherlock(HP1, EXP1, M1);
    checkValidValueWaston(HP2, EXP2, M1);
    return -1;
}

// Task 4
int checkPassword(const char *s, const char *email) {
    // Extract string se from string email
    int index_at = 0;
    string se;
    const char *p = email;
    while (*p != '@') {
        se.push_back(*p);
        p++;
        index_at++;
    }

    // Find the size of s
    int s_size = strlen(s);

    // Check size of s if it is valid
    if (s_size < 8) {
        return -1;
    } else if (s_size > 20) {
        return -2;
    }
    // Check whether string se is in s
    string password = s;
    int firstOcurrence = password.find(se);
    if (firstOcurrence != string::npos) return -(300+firstOcurrence);



    // Check consecutive and identical characters
    for (int i = 0; i < s_size - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }

    // Check for special character
    const char specialChars[] = {'@', '#', '%', '$', '!'};
    int specialChar = 0;
    for (int i = 0; i < s_size; i++) {
        for (int k = 0; k < 5; k++) {
            if (s[i] == specialChars[k]) {
                specialChar++;
                break; // Break out of inner loop if a special character is found
            }
        }
    }
    if (specialChar == 0) {
        return -5;
    }

    // Check remaining cases
    for (int i = 0; i < s_size; i++) {
        if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ||
              s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')) {
            return i;
        }
    }

    //If Password is valid
    return -10;
}

// Task 5
// Define a data type password_Nums which has 4 properties
struct password_Nums
{
    const char *password;
    int quantity;
    int appear_index;
    int password_len;
};

int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{   
    // Because there is maximum with 30 distinct password
    const int maxPasswords = 30;
    password_Nums correctPass[maxPasswords] = {};

    for (int i = 0; i < num_pwds; ++i)
    {
        const char *currentPassword = arr_pwds[i];
        for (int j = 0; j < maxPasswords; ++j)
        {
            if (correctPass[j].password == nullptr)
            {
                // Found an empty slot, add the password
                correctPass[j].password = currentPassword;
                correctPass[j].quantity = 1;
                correctPass[j].appear_index = i;
                correctPass[j].password_len = strlen(currentPassword);
                break;
            }
            else if (strcmp(correctPass[j].password, currentPassword) == 0)
            {
                // Password already exists, increment the quantity
                correctPass[j].quantity++;
                break;
            }
        }
    }
    int maxFrequency = correctPass[0].quantity; // maxFrequency = How many times the password appears
    int lengthOfMax = correctPass[0].password_len;
    int returnIndex = correctPass[0].appear_index;
    for (int i = 0; i < maxPasswords; ++i)
    {
        if (correctPass[i].password != nullptr)
        {
            if (correctPass[i].quantity > maxFrequency)
            {
                maxFrequency = correctPass[i].quantity;
                lengthOfMax = correctPass[i].password_len;
                returnIndex = correctPass[i].appear_index;
            }
            else if (correctPass[i].quantity == maxFrequency)
            {
                if (correctPass[i].password_len > lengthOfMax)
                {
                    maxFrequency = correctPass[i].quantity;
                    lengthOfMax = correctPass[i].password_len;
                    returnIndex = correctPass[i].appear_index;
                }
                else if (correctPass[i].password_len == lengthOfMax)
                {
                    if (correctPass[i].appear_index < returnIndex)
                    {
                        maxFrequency = correctPass[i].quantity;
                        lengthOfMax = correctPass[i].password_len;
                        returnIndex = correctPass[i].appear_index;
                    }
                }
            }
        }
    }
    if (returnIndex < num_pwds)
        return returnIndex;

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////