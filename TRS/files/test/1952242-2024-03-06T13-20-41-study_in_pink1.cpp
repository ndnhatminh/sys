#include "study_in_pink1.h"
const int MAX_E = 99;
const int WATER_COST = 70;
const int FOOD_COST = 150;
const int TAXI_COST = 200;
const int CARRIAGE_COST = 120;
const int HOMELESS_TAXI_COST = 100;
const int HOMELESS_CARRIAGE_COST = 120;
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
void checkHP(int &HP1, int &HP2)
{

    if (HP1 < 0)
    {
        HP1 = 0;
    }
    if (HP1 > 666)
    {
        HP1 = 666;
    }
    if (HP2 < 0)
    {
        HP2 = 0;
    }
    if (HP2 > 666)
    {
        HP2 = 666;
    }
}
void checkEXP(int &EXP1, int &EXP2)
{
    if (EXP1 < 0)
    {
        EXP1 = 0;
    }
    if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    if (EXP2 < 0)
    {
        EXP2 = 0;
    }
    if (EXP2 > 600)
    {
        EXP2 = 600;
    }
}
void checkM(int &M1, int &M2)
{
    if (M1 < 0)
    {
        M1 = 0;
    }
    if (M1 > 3000)
    {
        M1 = 3000;
    }
    if (M2 < 0)
    {
        M2 = 0;
    }
    if (M2 > 3000)
    {
        M2 = 3000;
    }
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    checkEXP(exp1, exp2);
    if (e1 >= 0 && e1 <= 3)
    {
        // Sherlock
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 += D / 200.0 + 0.9999999;
        }
        else
        {
            exp1 -= D / 100.0 - 0.9999999;
        }
        // Watson
        switch (e1)
        {
        case 0:
            /* code */
            exp2 += 29;
            break;
        case 1:
            /* code */
            exp2 += 45;
            break;
        case 2:
            /* code */
            exp2 += 75;
            break;
        case 3:
            /* code */
            exp2 += 29 + 45 + 75;
            break;

        default:
            break;
        }
    }
    else if (e1 >= 4 && e1 <= 99)
    {
        // Sherlock
        exp1 -= e1;
        // Watson
        // [4, 19]
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 += ceil(e1 / 4.0 + 19);
        }
        // [20,49]
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 += ceil(e1 / 9.0 + 21);
        }
        // [50,65]
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 += ceil(e1 / 16.0 + 17);
        }
        // [66,79]
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 += ceil(e1 / 4.0 + 19);
            if (exp2 > 200)
            {
                exp2 += ceil(e1 / 9.0 + 21);
            }
        }
        // [80,99]
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 += ceil(e1 / 4.0 + 19) + ceil(e1 / 9.0 + 21);
            if (exp2 > 400)
            {
                exp2 += ceil(e1 / 16.0 + 17);
                exp2 += exp2 * 0.15 + 0.9999999;
            }
        }
    }
    else
    {
        return -99;
    }
    checkEXP(exp1, exp2);
    return exp1 + exp2;
}

void buyFoodAndWater(int &HP, int &M, double &spent)
{
    HP += HP * 0.3 + 0.999;
    checkHP(HP, HP);
    M -= FOOD_COST;
    checkM(M, M);
    spent += FOOD_COST;
}

void buyWater(int &HP, int &M, double &spent)
{
    HP += HP * 0.1 + 0.999;
    checkHP(HP, HP);
    M -= WATER_COST;
    checkM(M, M);
    spent += WATER_COST;
}

void rentVehicle(int &EXP, int &M, double &spent, bool isTaxi)
{
    M -= (isTaxi ? TAXI_COST : CARRIAGE_COST);
    checkM(M, M);
    spent += (isTaxi ? TAXI_COST : CARRIAGE_COST);
    EXP += EXP * 0.13 + 0.999;
    checkEXP(EXP, EXP);
}

void meetHomeless(int &EXP, int &M, double &spent, bool lowEXP)
{
    M -= (lowEXP ? HOMELESS_TAXI_COST : HOMELESS_CARRIAGE_COST);
    checkM(M, M);
    spent += (lowEXP ? HOMELESS_TAXI_COST : HOMELESS_CARRIAGE_COST);
    EXP -= EXP * 0.1 - 0.999;
    checkEXP(EXP, EXP);
}

int traceLuggage(int &HP, int &EXP, int &M, int E2)
{
    if (E2 < 0 || E2 > MAX_E)
    {
        return -99;
    }

    checkHP(HP, HP);
    checkEXP(EXP, EXP);
    checkM(M, M);

    // Road 1
    double S = pow(round(sqrt(EXP)), 2);
    double P1 = (EXP >= S) ? 100 : ((EXP / S + 80) / 123) * 100;

    // Road 2
    double spent = 0;
    double half = M * 0.5;

    do
    {
        if (M)
        {
            if (HP < 200)
            {
                buyFoodAndWater(HP, M, spent);
            }
            else
            {
                buyWater(HP, M, spent);
            }
        }
        else
        {
            break;
        }

        if (E2 % 2 != 0 && spent > half)
        {
            break;
        }

        if (M)
        {
            rentVehicle(EXP, M, spent, (EXP < 400));
        }
        else
        {
            break;
        }

        if (E2 % 2 != 0 && spent > half)
        {
            break;
        }

        if (M)
        {
            meetHomeless(EXP, M, spent, (EXP < 300));
        }
        else
        {
            break;
        }

        if (E2 % 2 != 0 && spent > half)
        {
            break;
        }
    } while (E2 % 2 != 0);

    EXP += EXP * 0.17 + 0.999;
    checkEXP(EXP, EXP);
    HP -= HP * 0.17 - 0.999;

    S = pow(round(sqrt(EXP)), 2);
    int P2 = (EXP >= S) ? 100 : ((EXP / S + 80) / 123) * 100;

    // Road 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int P3 = (E2 < 10) ? P[E2] : P[(E2 % 10 + E2 / 10) % 10];

    // Check after all
    if (P1 == 100 && P2 == 100 && P3 == 100)
    {
        EXP -= EXP * 0.25 - 0.9999999;
        checkEXP(EXP, EXP);
    }
    else
    {
        double avg = (P1 + P2 + P3) / 3.0;
        if (avg < 50)
        {
            EXP += EXP * 0.15 + 0.9999999;
            HP -= HP * 0.15 - 0.9999999;
        }
        else
        {
            EXP += EXP * 0.2 + 0.9999999;
            HP -= HP * 0.1 - 0.9999999;
        }
        checkEXP(EXP, EXP);
        checkHP(HP, HP);
    }

    return HP + EXP + M;
}
int findMaxInDiagonals(int matrix[10][10], int i, int j)
{
    int maxVal = matrix[i][j];

    // Check the main diagonal
    for (int k = 1; i + k < 10 && j + k < 10; ++k)
    {
        if (matrix[i + k][j + k] > maxVal)
        {
            maxVal = matrix[i + k][j + k];
        }
    }
    for (int k = 1; i - k >= 0 && j - k >= 0; ++k)
    {
        if (matrix[i - k][j - k] > maxVal)
        {
            maxVal = matrix[i - k][j - k];
        }
    }

    // Check the secondary diagonal
    for (int k = 1; i + k < 10 && j - k >= 0; ++k)
    {
        if (matrix[i + k][j - k] > maxVal)
        {
            maxVal = matrix[i + k][j - k];
        }
    }
    for (int k = 1; i - k >= 0 && j + k < 10; ++k)
    {
        if (matrix[i - k][j + k] > maxVal)
        {
            maxVal = matrix[i - k][j + k];
        }
    }

    return maxVal;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 < 0 || E3 > MAX_E)
    {
        return -99;
    }
    checkHP(HP1, HP2);
    checkEXP(EXP1, EXP2);
    // TODO: Complete this function
    int matrix[10][10] = {0};
    // The taxi go row by row, in every position, the value = ((E3∗j)+(i∗2))∗(i−j) (i, j are the row and column index of the matrix)
    int pos_i = 0, pos_j = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (matrix[i][j] > 2 * E3)
            {
                pos_i++;
            }
            if (matrix[i][j] < -E3)
            {
                pos_j++;
            }
        }
    }
    // pos_i pos_j processing
    while (pos_i > 9)
    {
        pos_i = pos_i % 10 + pos_i / 10;
    }
    while (pos_j > 9)
    {
        pos_j = pos_j % 10 + pos_j / 10;
    }
    // find max value in diagonals
    int maxVal = findMaxInDiagonals(matrix, pos_i, pos_j);
    if (abs(maxVal) >= abs(matrix[pos_i][pos_j]))
    {
        EXP1 += EXP1 * 0.12 + 0.9999999;
        HP1 += HP1 * 0.1 + 0.9999999;
        EXP2 += EXP2 * 0.12 + 0.9999999;
        HP2 += HP2 * 0.1 + 0.9999999;
        checkEXP(EXP1, EXP2);
        checkHP(HP1, HP2);
        return abs(maxVal);
    }
    EXP1 -= EXP1 * 0.12 - 0.9999999;
    HP1 -= HP1 * 0.1 - 0.9999999;
    EXP2 -= EXP2 * 0.12 - 0.9999999;
    HP2 -= HP2 * 0.1 - 0.9999999;
    checkEXP(EXP1, EXP2);
    checkHP(HP1, HP2);
    return matrix[pos_i][pos_j];
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // Extracting the substring before '@' directly without a loop
    char se[100];
    int i = 0;
    while (email[i] != '@')
    {
        se[i] = email[i];
        i++;
    }
    se[i] = '\0';

    // Counting '@' occurrences while traversing email
    int count = 0;
    for (i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
        {
            count++;
        }
    }
    // No need to check if there's more than one '@' in an email
    if (count != 1)
    {
        return -3; // Indicating invalid email format
    }

    // Password constraints
    int len = strlen(s);
    if (len < 8)
    {
        return -1;
    }
    if (len > 20)
    {
        return -2;
    }

    // Tracking consecutive character count
    int consecutiveCharCount = 0;
    char lastChar = '\0'; // Initialize to a character not allowed in password
    for (i = 0; i < len; i++)
    {
        if (s[i] == lastChar)
        {
            consecutiveCharCount++;
            if (consecutiveCharCount > 2)
            {
                return -(400 + i); // Position of the first 3 consecutive characters
            }
        }
        else
        {
            consecutiveCharCount = 1;
            lastChar = s[i];
        }
    }

    // Tracking special character count
    int specialCharCount = 0;
    const char *specialChars = "@#$%&!"; // Consolidated special characters
    for (i = 0; s[i] != '\0'; i++)
    {
        if (strchr(specialChars, s[i]) != nullptr)
        {
            specialCharCount++;
        }
    }
    if (specialCharCount == 0)
    {
        return -5;
    }

    // Checking if password contains substring 'se'
    if (strstr(s, se) != nullptr)
    {
        return -(300 + (strstr(s, se) - s)); // Position of 'se'
    }

    // Validating email characters
    for (i = 0; email[i] != '\0'; i++)
    {
        if (!((email[i] >= 'A' && email[i] <= 'Z') || (email[i] >= 'a' && email[i] <= 'z') || (email[i] >= '0' && email[i] <= '9') || email[i] == '@' || email[i] == '.'))
        {
            return i; // Position of the first invalid character
        }
    }

    return -10; // Success
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    if (num_pwds <= 0 || arr_pwds == NULL)
    {
        // Invalid input
        return -1;
    }

    int maxOccurrences = 0;
    int maxLength = 0;
    const char *correctPassword = NULL;
    int correctPosition = -1;

    for (int i = 0; i < num_pwds; ++i)
    {
        const char *currentPassword = arr_pwds[i];
        int occurrences = 1;

        if (currentPassword == NULL)
        {
            // Skip NULL passwords
            continue;
        }

        // Count occurrences and find the length
        for (int j = i + 1; j < num_pwds; ++j)
        {
            if (arr_pwds[j] != NULL && strcmp(currentPassword, arr_pwds[j]) == 0)
            {
                occurrences++;
            }
        }

        int currentLength = strlen(currentPassword);

        // Check if it's the correct password
        if (occurrences > maxOccurrences || (occurrences == maxOccurrences && currentLength > maxLength))
        {
            maxOccurrences = occurrences;
            maxLength = currentLength;
            correctPassword = currentPassword;
            correctPosition = i;
        }
    }

    return correctPosition;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////