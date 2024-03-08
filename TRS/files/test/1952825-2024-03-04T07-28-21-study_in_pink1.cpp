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

void checkValidHp(int &HP)
{
    if (HP > 666)
    {
        HP = 666;
    }
    else if (HP < 0)
    {
        HP = 0;
    }
}

void checkValidExp(int &EXP)
{
    if (EXP < 0)
    {
        EXP = 0;
    }
    else if (EXP > 600)
    {
        EXP = 600;
    }
}
void checkValidMoney(int &M)
{
    if (M < 0)
    {
        M = 0;
    }
    else if (M > 3000)
    {
        M = 3000;
    }
}
bool checkValidEvent(int &E)
{
    if (E < 0 || E > 99)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int roundUp(double number)
{
    int integerPart = static_cast<int>(number);
    if (number > integerPart)
    {
        return integerPart + 1;
    }
    else
    {
        return integerPart;
    }
}

bool isEvenNumber(int number)
{
    return (number % 2 == 0);
}

int nearestPerfectSquare(int number)
{
    double root = sqrt(static_cast<double>(number));

    int roundedRoot = static_cast<int>(root + 0.5);

    int nearestSquare = roundedRoot * roundedRoot;

    return nearestSquare;
}
int firstMeet(int &exp1, int &exp2, int e1)
{
    if (e1 < 0 || e1 > 99)
        return -99;
    // TODO: Complete this function
    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0)
        {
            exp2 = exp2 + 29;
        }
        else if (e1 == 1)
        {
            exp2 = exp2 + 45;
        }
        else if (e1 == 2)
        {
            exp2 = exp2 + 75;
        }
        else if (e1 == 3)
        {
            exp2 = exp2 + 29 + 45 + 75;
        }
        int D = (e1 * 3) + (exp1 * 7);
        if (isEvenNumber(D))
        {
            exp1 = ceil(exp1 + float(D / 200.0));
        }
        else
        {
            exp1 = ceil(exp1 - float(D / 100.0));
        }
    }
    else if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 = exp2 + ceil(e1 / 4.0) + 19;
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 = exp2 + ceil(e1 / 9.0) + 21;
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 = exp2 + ceil(e1 / 16.0) + 17;
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 = exp2 + ceil(e1 / 4.0) + 19;
            if (exp2 > 200)
            {
                exp2 = exp2 + ceil(e1 / 9.0) + 21;
            }
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 = exp2 + ceil(e1 / 4.0) + 19;
            exp2 = exp2 + ceil(e1 / 9.0) + 21;

            if (exp2 > 400)

            {
                exp2 = exp2 + ceil(e1 / 16.0) + 17;
                exp2 = (exp2 + ceil((exp2 * 15) / 100.0));
            }
        }

        exp1 = exp1 - e1;
    }
    checkValidExp(exp1);
    checkValidExp(exp2);
    return exp1 + exp2;
}

bool getFoodAndDrink(int &HP1, int &M1, int &moneySpend)
{
    if (HP1 < 200)
    {
        HP1 = ceil(HP1 * 1.3);
        M1 = M1 - 150;
        moneySpend = moneySpend + 150;
    }
    else
    {
        HP1 = ceil(HP1 * 11.0 / 10);
        M1 = M1 - 70;
        moneySpend = moneySpend + 70;
    }
    checkValidHp(HP1);
    checkValidMoney(M1);
    return M1 == 0 ? false : true;
}

bool getTaxiOrHorseRide(int &EXP1, int &M1, int &moneySpend)
{
    int taxiCost = 200;
    int horseCost = 120;
    if (EXP1 < 400)
    {
        M1 = M1 - taxiCost;
        moneySpend = moneySpend + taxiCost;
    }
    else
    {
        M1 = M1 - horseCost;
        moneySpend = moneySpend + horseCost;
    }
    EXP1 = ceil(EXP1 * 1.13);
    checkValidExp(EXP1);
    checkValidMoney(M1);
    return M1 == 0 ? false : true;
}

bool homeLessPerson(int &EXP1, int &M1, int &moneySpend)
{
    if (EXP1 < 300)
    {
        M1 = M1 - 100;
        moneySpend = moneySpend + 100;
    }
    else
    {
        M1 = M1 - 120;
        moneySpend = moneySpend + 120;
    }
    EXP1 = ceil(EXP1 * 0.9);
    checkValidExp(EXP1);
    checkValidMoney(M1);

    return M1 == 0 ? false : true;
}
bool isGreaterThanHalf(int moneySpend, int initialMoneyRound2)
{
    int half = initialMoneyRound2 / 2;
    return moneySpend > half;
}
int findPositionI(int E2)
{
    if (E2 >= 0 && E2 < 10)
    {
        return E2;
    }
    else
    {
        int firstDigit = E2 / 10;
        int secondDigit = E2 % 10;
        return (firstDigit + secondDigit) % 10;
    }
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (E2 < 0 || E2 > 99)
        return -99;
    // TODO: Complete this function
    int moneySpend = 0;
    /*ROAD 1*/
    double P1 = 0.0;
    double P2 = 0.0;
    double P3 = 0.0;
    int S = nearestPerfectSquare(EXP1);
    if (EXP1 >= S)
    {
        P1 = 1;
    }
    else
    {
        double result = (((double)EXP1 / (double)S) + 80) / 123;
        P1 = result;
    }
    int initialMoneyRound2 = M1;
    if (!isEvenNumber(E2))
    {
        while (true)
        {
            if (M1 == 0)
            {
                break;
            }
            bool event1 = getFoodAndDrink(HP1, M1, moneySpend);

            if (isGreaterThanHalf(moneySpend, initialMoneyRound2))
            {
                break;
            }
            if (M1 == 0)
            {
                break;
            }
            bool event2 = getTaxiOrHorseRide(EXP1, M1, moneySpend);

            if (isGreaterThanHalf(moneySpend, initialMoneyRound2))
            {
                break;
            }
            if (M1 == 0)
            {
                break;
            }

            bool event3 = homeLessPerson(EXP1, M1, moneySpend);

            if (isGreaterThanHalf(moneySpend, initialMoneyRound2))
            {
                break;
            }
            if (M1 == 0)
            {
                break;
            }
        }
    }
    else
    {
        while (true)
        {
            if (M1 == 0)
            {
                break;
            }
            bool event1 = getFoodAndDrink(HP1, M1, moneySpend);
            if (event1 == false)
            {
                break;
            }
            bool event2 = getTaxiOrHorseRide(EXP1, M1, moneySpend);

            if (event2 == false)
            {
                break;
            }
            bool event3 = homeLessPerson(EXP1, M1, moneySpend);

            if (event3 == false)
            {
                break;
            }
            break;
        }
    }

    HP1 = ceil(HP1 * 0.83);
    EXP1 = ceil(EXP1 * 1.17);

    checkValidHp(HP1);
    checkValidExp(EXP1);

    int S2 = nearestPerfectSquare(EXP1);
    if (EXP1 >= S2)
    {
        P2 = 1;
    }
    else
    {
        double result = (((double)EXP1 / (double)S2) + 80) / 123;
        P2 = result;
    }

    int PArray[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = findPositionI(E2);
    P3 = PArray[i] * 0.01;

    if (P1 == 1 & P2 == 1 & P3 == 1)
    {
        EXP1 = ceil(EXP1 * 0.75);
        checkValidExp(EXP1);
    }
    else
    {
        double averageP = (P1 + P2 + P3) / 3.0;
        if (averageP < 0.5)
        {
            EXP1 = ceil(EXP1 * 1.15);
            HP1 = ceil(HP1 * 0.85);
            checkValidHp(HP1);
            checkValidExp(EXP1);
        }
        else
        {
            EXP1 = ceil(EXP1 * 1.2);
            HP1 = ceil(HP1 * (9.0 / 10));
            checkValidHp(HP1);
            checkValidExp(EXP1);
        }
    }

    return HP1 + EXP1 + M1;
}

int findIAndJ(int num)
{
    while (num >= 10)
    {
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}
void addValueSherlockWatsonMatrix(int value, int i, int j, int arr[][10])
{
    arr[j][i] = value;
}
int taxiScore(int i, int j, int E3)
{
    return ((E3 * j) + (i * 2)) * (i - j);
}
int findMax(int (*matrix)[10], int i, int j)
{
    int max = matrix[i][j];
    int x, y;

    x = i < j ? 0 : i - j;
    y = i < j ? j - i : 0;
    while (x < 10 && y < 10)
    {
        if (matrix[x][y] > max)
        {
            max = matrix[x][y];
        }
        x++;
        y++;
    }

    y = i + j < 10 ? 0 : i + j - 10 + 1;
    x = i + j < 10 ? i + j : 10 - 1;
    while (x >= 0 && y < 10)
    {
        if (matrix[x][y] > max)
        {
            max = matrix[x][y];
        }
        x--;
        y++;
    }

    return max;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 < 0 || E3 > 99)
        return -99;

    int result = 0;
    // TODO: Complete this function
    bool chase = false;
    const int SIZE = 10;
    int sherlockWatsonMap[SIZE][SIZE] = {0};
    int taxiMap[SIZE][SIZE] = {0};

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            taxiMap[i][j] = taxiScore(i, j, E3);
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int maxTemp = findMax(taxiMap, i, j);

            addValueSherlockWatsonMatrix(maxTemp, j, i, sherlockWatsonMap);
        }
    }

    int countGreater = 0, countSmaller = 0;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (taxiMap[i][j] > E3 * 2)
                countGreater++;
            if (taxiMap[i][j] < -E3)
                countSmaller++;
        }
    }
    int posI = findIAndJ(countGreater);
    int posJ = findIAndJ(countSmaller);

    int taxiGrade = taxiMap[posI][posJ];
    int sherlockWatsonGrade = sherlockWatsonMap[posI][posJ];

    if (abs(taxiGrade) > sherlockWatsonGrade)
    {

        EXP1 = ceil(EXP1 * 88.0 / 100);
        EXP2 = std::ceil(EXP2 * 88.0 / 100);
        HP1 = std::ceil(HP1 * (9.0 / 10));
        HP2 = std::ceil(HP2 * (9.0 / 10));

        result = taxiGrade;
    }
    else
    {
        chase = true;
        EXP1 = std::ceil(EXP1 * 112.0 / 100);
        EXP2 = std::ceil(EXP2 * 112.0 / 100);
        HP1 = std::ceil(HP1 * 11.0 / 10);
        HP2 = std::ceil(HP2 * 11.0 / 10);

        result = sherlockWatsonGrade;
    }
    checkValidExp(EXP1);
    checkValidExp(EXP2);
    checkValidHp(HP1);
    checkValidHp(HP2);
    return result;
}

bool checkValidString(string S)
{
    int size = S.length();
    if (size < 8 || size > 20)
    {
        return false;
    }
    else
        return true;
}
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    int min_length = 8;
    int max_length = 20;
    const char *special_chars = "@#%$!";
    const char *se = strstr(email, "@");
    if (se == nullptr)
        return -99;

    char se_string[101];
    strncpy(se_string, email, se - email);
    se_string[se - email] = '\0';

    int se_index = static_cast<int>(se - email);

    int length = strlen(s);
    if (length < min_length)
        return -1;
    else if (length > max_length)
        return -2;

    if (strstr(s, se_string) != nullptr)
    {
        const char *position = strstr(s, se_string);
        return -(300 + (position - s));
    }

    for (int i = 0; i < length - 2; ++i)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
            return -(400 + i);
    }

    bool has_special_char = false;
    for (int i = 0; i < length; ++i)
    {
        if (strchr(special_chars, s[i]) != nullptr)
        {
            has_special_char = true;
            break;
        }
    }
    if (!has_special_char)
        return -5;

    for (int i = 0; i < length; ++i)
    {
        char c = s[i];
        if (!((c >= '0' && c <= '9') ||
              (c >= 'a' && c <= 'z') ||
              (c >= 'A' && c <= 'Z') ||
              strchr(special_chars, c) != nullptr))
        {
            return i;
        }
    }

    return -10;
}

int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    const int MAX_PASSWORD_LENGTH = 100;
    const int MAX_PASSWORDS = 30;
    std::pair<std::string, int> passwordCounts[MAX_PASSWORDS];

    for (int i = 0; i < MAX_PASSWORDS; ++i)
    {
        passwordCounts[i].second = 0;
    }

    int numDistinctPasswords = 0;
    for (int i = 0; i < num_pwds; ++i)
    {
        std::string password = arr_pwds[i];
        bool found = false;
        for (int j = 0; j < numDistinctPasswords; ++j)
        {
            if (passwordCounts[j].first == password)
            {
                passwordCounts[j].second++;
                found = true;
                break;
            }
        }
        if (!found)
        {
            passwordCounts[numDistinctPasswords].first = password;
            passwordCounts[numDistinctPasswords].second = 1;
            numDistinctPasswords++;
        }
    }

    std::string mostFrequentPassword;
    int maxCount = 0;
    int maxLength = 0;
    for (int i = 0; i < numDistinctPasswords; ++i)
    {
        const std::string &password = passwordCounts[i].first;
        int count = passwordCounts[i].second;
        int length = password.length();

        if (count > maxCount || (count == maxCount && length > maxLength))
        {
            mostFrequentPassword = password;
            maxCount = count;
            maxLength = length;
        }
    }

    for (int i = 0; i < num_pwds; ++i)
    {
        if (strcmp(arr_pwds[i], mostFrequentPassword.c_str()) == 0)
        {
            return i;
        }
    }

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////