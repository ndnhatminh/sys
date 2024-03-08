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
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    exp1 = verifyEXP(exp1);
    exp2 = verifyEXP(exp2);
    if (verifyEvent(e1) == false)
        return -99;
    if (e1 < 4)
        whereWatsonReturn(exp1, exp2, e1);
    else
        brotherOrSister(exp1, exp2, e1);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    HP1 = verifyHP(HP1);
    EXP1 = verifyEXP(EXP1);
    M1 = verifyMoney(M1);
    if (verifyEvent(E2) == false)
        return -99;
    if (M1 <= 0)
    {
        HP1 = verifyHP(0.83 * HP1);
        EXP1 = verifyEXP(1.17 * EXP1);
        return HP1 + EXP1 + M1;
    }
    float firstRouteResult = firstRoute(EXP1);
    // cout << "First Route: "
    //      << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: "
    //      << EXP1 << ", M1: " << M1 << " Possibility: " << firstRouteResult << endl;
    float secondRouteResult = secondRoute(EXP1, HP1, M1, E2);
    // cout << "Second Route: "
    //      << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: "
    //      << EXP1 << ", M1: " << M1 << " Possibility: " << secondRouteResult <<endl;
    float thirdRouteResult = thirdRoute(EXP1, HP1, E2);
    // cout << "Third Route: "
    //      << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: "
    //      << EXP1 << ", M1: " << M1 << " Possibility: " << thirdRouteResult << endl;
    float traceLuggageProb = (firstRouteResult + secondRouteResult + thirdRouteResult) / 3;
    if (traceLuggageProb >= 100)
        EXP1 = verifyEXP(0.75 * EXP1);
    else if (traceLuggageProb >= 50 && traceLuggageProb < 100)
    {
        HP1 = verifyHP(0.9 * HP1);
        EXP1 = verifyEXP(1.2 * EXP1);
    }
    else
    {
        HP1 = verifyHP(0.85 * HP1);
        EXP1 = verifyEXP(1.15 * EXP1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    const int MATRIX_SIZE = 10;

    int taxiMatrix[MATRIX_SIZE][MATRIX_SIZE] = {0};
    initializeMatrix((int *)taxiMatrix, MATRIX_SIZE, MATRIX_SIZE, E3);

    int countLarger = 0;
    int countSmaller = 0;
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if (taxiMatrix[i][j] > E3 * 2)
                countLarger++;
            if (taxiMatrix[i][j] < -E3)
                countSmaller++;
        }
    }
    int rowMeet = convertToOneDigit(countLarger);
    int colMeet = convertToOneDigit(countSmaller);

    int chasePoint = maxDiagonal((int *)taxiMatrix, MATRIX_SIZE, MATRIX_SIZE, rowMeet, colMeet);

    if (abs(taxiMatrix[rowMeet][colMeet]) > abs(chasePoint))
    {
        HP1 = verifyHP(0.9 * HP1);
        EXP1 = verifyEXP(0.88 * EXP1);
        HP2 = verifyHP(0.9 * HP2);
        EXP2 = verifyEXP(0.88 * EXP2);
    }
    else
    {
        HP1 = verifyHP(1.1 * HP1);
        EXP1 = verifyEXP(1.12 * EXP1);
        HP2 = verifyHP(1.1 * HP2);
        EXP2 = verifyEXP(1.12 * EXP2);
    }

    return taxiMatrix[rowMeet][colMeet];
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    std::string victimEmail = email;
    std::string password = s;

    if (password.length() < 8)
        return -1;
    if (password.length() > 20)
        return -2;

    int atPos = victimEmail.find('@');
    std::string subEmail = victimEmail.substr(0, atPos);

    if (password.find(subEmail) != std::string::npos)
        return -(300 + password.find(subEmail));

    for (int i = 0; i < password.length() - 2; i++)
    {
        if (password[i] == password[i + 1] && password[i] == password[i + 2])
            return -(400 + password.find(password[i]));
    }

    int falseChar = isAlphanumeric(password);
    if (falseChar == NO_SPEC_CHAR)
        return -5;
    else if (falseChar != OK)
        return falseChar;
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function

    int numOfElements = 0;
    Password *distinctPassword = distinctList(arr_pwds, num_pwds, numOfElements);

    int mostAppearances = 0;
    int moreLength = 0;
    int mostIndex = 0;
    string foundPassword = "";
    for (int i = 0; i < numOfElements; i++)
    {
        if (distinctPassword[i].count > mostAppearances)
        {
            mostAppearances = distinctPassword[i].count;
            foundPassword = distinctPassword[i].value;
        }
        if (distinctPassword[i].count == mostAppearances)
        {
            if (distinctPassword[i].value.length() > foundPassword.length())
            {
                foundPassword = distinctPassword[i].value;
            }
        }
    }

    // cout << "distinctive elements: " << "Num of distinct element: " << numOfElements << endl;;
    // for (int i = 0; i < numOfElements; i++)
    // {
    //     std::cout << distinctPassword[i].value << " " << distinctPassword[i].count << endl;
    // }

    for (int i = 0; i < num_pwds; i++)
    {
        if (arr_pwds[i] == foundPassword)
        {
            mostIndex = i;
            break;
        }
    }
    delete[] distinctPassword;
    return mostIndex;
}

// Supporting Function
int verifyEXP(float exp)
{
    if (exp > 600)
        exp = 600;
    else if (exp < 0)
        exp = 0;
    return ceil(exp);
}

int verifyHP(float hp)
{
    if (hp > 666)
        hp = 666;
    else if (hp < 0)
        hp = 0;
    return ceil(hp);
}

int verifyMoney(float money)
{
    if (money > 3000)
        money = 3000;
    else if (money < 0)
        money = 0;
    return ceil(money);
}

bool verifyEvent(int event)
{
    if (event < 0 || event > 99)
        return false;
    return true;
}

void whereWatsonReturn(int &exp1, int &exp2, int e)
{
    switch (e)
    {
    case 0 /* constant-expression */:
        /* code */
        exp2 = verifyEXP(exp2 + 29);
        break;
    case 1:
        exp2 = verifyEXP(exp2 + 45);
        break;
    case 2:
        exp2 = verifyEXP(exp2 + 75);
        break;
    case 3:
        exp2 = verifyEXP(exp2 + 29 + 45 + 75);
        break;
    default:
        break;
    }
    int oddOrEven = 3 * e + 7 * exp1;
    if (IS_EVEN(oddOrEven))
        exp1 = verifyEXP(exp1 + oddOrEven * 1.0 / 200);
    else
        exp1 = verifyEXP(exp1 - oddOrEven * 1.0 / 100);
}

void brotherOrSister(int &exp1, int &exp2, int e)
{
    int FIRST_PIECE = ceil(e * 1.0 / 4) + 19;
    int SECOND_PIECE = ceil(e * 1.0 / 9) + 21;
    // cout << SECOND_PIECE << endl;
    int THIRD_PIECE = ceil(e * 1.0 / 16) + 17;
    if (e >= 4 && e < 20)
        exp2 = verifyEXP(exp2 + FIRST_PIECE);
    else if (e >= 20 && e < 50)
        exp2 = verifyEXP(exp2 + SECOND_PIECE);
    else if (e >= 50 && e < 66)
        exp2 = verifyEXP(exp2 + THIRD_PIECE);
    else if (e >= 65 && e < 80)
    {
        exp2 = verifyEXP(exp2 + FIRST_PIECE);
        if (exp2 > 200)
            exp2 = verifyEXP(exp2 + SECOND_PIECE);
    }
    else
    {
        exp2 = verifyEXP(verifyEXP(exp2 + FIRST_PIECE) + SECOND_PIECE);
        if (exp2 > 400)
            exp2 = verifyEXP(1.15 * verifyEXP(exp2 + THIRD_PIECE));
    }
    exp1 = verifyEXP(exp1 - e);
}

float firstRoute(int &exp)
{
    float firstRouteProb = 0;
    if (exp >= closestSquareNumber(exp))
        firstRouteProb = 1;
    else
        firstRouteProb = (float)((exp * 1.0 / closestSquareNumber(exp)) + 80) / 123;
    return 100 * firstRouteProb;
}

float secondRoute(int &exp, int &hp, int &money, int e)
{
    float secondRouteProb = 0;
    int halfOrgMoney = (0.5 * money);
    int totalSpending = 0;
    if (!IS_EVEN(e))
    {
        while (1)
        {
            totalSpending += foodAndBeverage(hp, money);
            if (totalSpending > halfOrgMoney)
                break;
            totalSpending += taxiOrHorse(exp, money);
            if (totalSpending > halfOrgMoney)
                break;
            totalSpending += poorManHelp(exp, money);
            if (totalSpending > halfOrgMoney)
                break;
        }
    }
    else
    {
        totalSpending += foodAndBeverage(hp, money);
        if (money > 0)
            totalSpending += taxiOrHorse(exp, money);
        if (money > 0)
            totalSpending += poorManHelp(exp, money);
    }
    hp = verifyHP(0.83 * hp);
    exp = verifyEXP(1.17 * exp);
    secondRouteProb = firstRoute(exp);
    return secondRouteProb;
}

float thirdRoute(int &exp, int &hp, int e)
{
    float thirdRouteProb = 0;
    int probArray[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int div = e / 10;
    if (div == 0)
        thirdRouteProb = probArray[e];
    else
    {
        int digit = e % 10;
        int index = (div + digit) % 10;
        thirdRouteProb = probArray[index];
    }
    return thirdRouteProb;
}

int closestSquareNumber(int num)
{
    int result = 0;
    int lower = floor(sqrt(num));
    int upper = lower + 1;
    if ((upper * upper - num) >= (num - lower * lower))
        result = lower * lower;
    else
        result = upper * upper;
    // cout << result << endl;
    return result;
}

int foodAndBeverage(int &hp, int &money)
{
    int startMoney = money;
    int spending = 0;
    if (hp < 200)
    {
        hp = verifyHP(1.3 * hp);
        money = verifyMoney(money - 150);
        // spending = 150;
        spending = (startMoney - money);
    }
    else
    {
        hp = verifyHP(1.1 * hp);
        money = verifyMoney(money - 70);
        // spending = 70;
        spending = (startMoney - money);
    }
    return spending;
}

int taxiOrHorse(int &exp, int &money)
{
    int startMoney = money;
    int spending = 0;
    if (exp < 400)
    {
        money = verifyMoney(money - 200);
        // spending = 200;
        spending = (startMoney - money);
    }
    else
    {
        money = verifyMoney(money - 120);
        // spending = 120;
        spending = (startMoney - money);
    }
    exp = verifyEXP(1.13 * exp);
    return spending;
}

int poorManHelp(int &exp, int &money)
{
    int startMoney = money;
    int spending = 0;
    if (exp < 300)
    {
        money = verifyMoney(money - 100);
        // spending = 100;
        spending = (startMoney - money);
    }
    else
    {
        money = verifyMoney(money - 120);
        // spending = 120;
        spending = (startMoney - money);
    }
    exp = verifyEXP(0.9 * exp);
    return spending;
}

void initializeMatrix(int *array, int rows, int cols, int e)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            *((array + i * cols) + j) = ((e * j) + (i * 2)) * (i - j);
    }
}

int convertToOneDigit(int num)
{
    while (num / 10 != 0)
    {
        int div = num / 10;
        int mod = num % 10;
        num = div + mod;
    }
    return num;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int maxDiagonal(int *array, int rows, int cols, int xPos, int yPos)
{
    // Calculate Left Diagonal start and end point
    int topLeftRow = xPos - min(xPos, yPos);
    int topLeftCol = yPos - min(xPos, yPos);

    int botRightRow = xPos + min(rows - 1 - xPos, cols - 1 - yPos);
    int botRightCol = yPos + min(rows - 1 - xPos, cols - 1 - yPos);

    // Calculate Right Diagonal start and end point
    int topRightRow = xPos - min(xPos, cols - 1 - yPos);
    int topRightCol = yPos + min(xPos, cols - 1 - yPos);

    int botLeftRow = xPos + min(rows - 1 - xPos, yPos);
    int botLeftCol = yPos - min(rows - 1 - xPos, yPos);

    int maxLeftValue = *((array + xPos * cols) + yPos);
    int maxRightValue = *((array + xPos * cols) + yPos);

    for (int i = topLeftRow, j = topLeftCol; i <= botRightRow, j <= botRightCol; i++, j++)
        maxLeftValue = max(maxLeftValue, *(array + i * cols + j));
    for (int i = botLeftRow, j = botLeftCol; i >= topRightRow, j <= topRightCol; i--, j++)
        maxRightValue = max(maxRightValue, *(array + i * cols + j));

    return max(maxLeftValue, maxRightValue);
}

int isAlphanumeric(std::string s)
{
    bool alnumValid = false;
    int falseChar = -1;
    for (char c : s)
    {
        if (c >= 48 && c <= 57 || c >= 65 && c <= 90 || c >= 97 && c <= 122)
            alnumValid = true;
        else if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!')
            alnumValid = true;
        else
        {
            alnumValid = false;
            if (s.find(c) != std::string::npos)
                falseChar = s.find(c);
            else
                falseChar = -2;
            break;
        }
    }
    if (alnumValid)
        return -10;
    else
        return falseChar;
}

Password *distinctList(const char *array[], int size, int &distinctCount)
{
    Password *distinctArray = new Password[size];
    distinctCount = 0;
    for (int i = 0; i < size; i++)
    {
        bool duplicate = false;
        for (int j = 0; j < distinctCount; j++)
        {
            if (array[i] == distinctArray[j].value)
            {
                duplicate = true;
                distinctArray[j].count++;
                break;
            }
        }
        if (!duplicate)
        {
            distinctArray[distinctCount].value = array[i];
            distinctArray[distinctCount].count++;
            distinctCount++;
        }
    }
    return distinctArray;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////