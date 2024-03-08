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
void setExp(int &toset)
{
    if (toset > 600)
        toset = 600;
    if (toset < 0)
        toset = 0;
}

int D_(int e1, int exp1)
{
    int D = 3 * e1 + exp1 * 7;

    if (D % 2 == 0)
    {
        return (double)exp1 + (double)D / 200 + 0.999;
    }
    else
    {
        return (double)exp1 - (double)D / 100 + 0.999;
    }
}
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function

    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }

    setExp(exp1);
    setExp(exp2);

    if (e1 >= 0 && e1 <= 3) // Situation 1
    {
        if (e1 == 0)
        {
            // Watson's hairstyle and manner of speech are like those of the military
            exp2 += 29;
        }
        else if (e1 == 1)
        {
            // Watson's face is tanned but not tanned under the wrist
            exp2 += 45;
        }
        else if (e1 == 2)
        {
            // Watson limped but chose to stand without asking for a chair
            exp2 += 75;
        }
        else if (e1 == 3)
        {
            // Sherlock explains all the information
            // Add EXP equal to the total of Information 1, 2, and 3
            exp2 += 29 + 45 + 75;
        }

        setExp(exp2);
        exp1 = D_(e1, exp1);
        setExp(exp1);
    }

    else if (e1 >= 4 && e1 <= 99)
    {

        if (e1 >= 4 && e1 <= 19)
        {
            exp2 += (double)e1 / 4 + 19 + 0.999;
        }

        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 += (double)e1 / 9 + 21 + 0.999;
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 += (double)e1 / 16 + 17 + 0.999;
        }

        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 += (double)e1 / 4 + 19 + 0.999;
            setExp(exp2);

            if (exp2 > 200)
            {
                exp2 += (double)e1 / 9 + 21 + 0.999;
            }
        }

        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 += (double)e1 / 4 + 19 + 0.999;
            setExp(exp2);
            exp2 += (double)e1 / 9 + 21 + 0.999;
            setExp(exp2);

            if (exp2 > 400)
            {
                exp2 += (double)e1 / 16 + 17 + 0.999;
                setExp(exp2);
                exp2 += (double)exp2 * 15 / 100 + 0.999;
            }
        }
        setExp(exp2);
        exp1 -= e1;
        setExp(exp1);
    }

    return exp1 + exp2;
}

// Task 2
double closestSquare(int exp1)
{
    int S = round(sqrt(exp1));
    S *= S;

    if (exp1 >= S)
    {
        return 1;
    }

    else
    {
        return ((double)exp1 / S + 80) / 123;
    }
}

void setHP(int &HP)
{
    if (HP > 666)
        HP = 666;
    if (HP < 0)
        HP = 0;
}

void setMoney(int &money)
{
    if (money > 3000)
        money = 3000;
    if (money < 0)
        money = 0;
}

void goShopping(int &HP, int &money)
{
    if (money <= 0)
        return;

    if (HP < 200)
    {
        HP += (double)HP * 30 / 100 + 0.999;
        money -= 150;
    }

    else if (HP >= 200)
    {
        HP += (double)HP * 10 / 100 + 0.999;
        money -= 70;
    }
}

void RentCar(int &exp1, int &money)
{
    if (money <= 0)
        return;

    if (exp1 < 400)
    {
        money -= 200;
    }

    else if (exp1 >= 400)
    {
        money -= 120;
    }
    exp1 += (double)exp1 * 13 / 100 + 0.999;
}

void helpHomeless(int &exp1, int &money)
{
    if (money <= 0)
        return;

    if (exp1 < 300)
    {
        money -= 100;
    }

    else if (exp1 >= 300)
    {
        money -= 120;
    }

    exp1 = ceil((double)exp1 - (double)exp1 * 10 / 100);
}

// Con đường 2
double simulate_02(int E2, int &exp1, int &hp, int &money)
{
    if (money == 0)
    {
        hp = ceil((double)hp - (double)hp * 17 / 100);
        setHP(hp);
        exp1 += (double)exp1 * 17 / 100 + 0.999;
        setExp(exp1);

        return closestSquare(exp1);
    }

    int half = (double)money * 0.5 + 0.999;

    if (E2 % 2 == 1)
    {
        while (money >= half)
        {
            goShopping(hp, money);
            setHP(hp);
            setMoney(money);
            if (money < half)
                break;
            RentCar(exp1, money);
            setExp(exp1);
            setMoney(money);
            if (money < half)
                break;
            helpHomeless(exp1, money);
            setExp(exp1);
            setMoney(money);
            if (money < half)
                break;
        }
    }

    else
    {
        goShopping(hp, money);
        setMoney(money);
        RentCar(exp1, money);
        setMoney(money);
        helpHomeless(exp1, money);
        setMoney(money);
    }

    hp = ceil((double)hp - (double)hp * 17 / 100);
    setHP(hp);
    exp1 += (double)exp1 * 17 / 100 + 0.999;
    setExp(exp1);

    return closestSquare(exp1);
}

// Con đường 3
double P3_(int e2)
{

    if (e2 < 0 || e2 > 99)
        return -99;

    double P[10] = {0.32, 0.47, 0.28, 0.79, 1.00, 0.50, 0.22, 0.83, 0.64, 0.11};
    int i;

    if (e2 >= 0 && e2 <= 9) // Nếu e2 là số có một chữ số
    {
        i = e2;
    }
    else if (e2 >= 10 && e2 <= 99) // Nếu e2 là số có hai chữ số
    {
        i = (e2 / 10) + (e2 % 10); // Tính tổng của 2 chữ số
        i = i % 10;                // Lấy số hàng đơn vị của giá trị tổng
    }

    return P[i];
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)

{
    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }

    setHP(HP1);
    setExp(EXP1);
    setMoney(M1);

    double P1 = closestSquare(EXP1);
    double P2 = simulate_02(E2, EXP1, HP1, M1);
    double P3 = P3_(E2);

    if (P1 == 1 && P2 == 1 && P3 == 1)
    {
        EXP1 = ceil((double)EXP1 - (double)EXP1 * 25 / 100);
    }

    double avrg = (P1 + P2 + P3) / 3;

    if (avrg < 0.5)
    {
        HP1 = ceil((double)HP1 - (double)HP1 * 15 / 100);
        EXP1 += (double)EXP1 * 15 / 100 + 0.99;
    }

    else if (avrg >= 0.5)
    {
        HP1 = ceil((double)HP1 - (double)HP1 * 10 / 100);
        EXP1 += double(EXP1) * 20 / 100 + 0.99;
    }

    setHP(HP1);
    setExp(EXP1);

    return HP1 + EXP1 + M1;
}

int find_matrix(int matrix[10][10], int i, int j)
{
    int max_value = matrix[i][j];

    // Đường chéo trái
    int x = i - 1;
    int y = j - 1;
    while (x >= 0 && y >= 0)
    {
        if (matrix[x][y] > max_value)
        {
            max_value = matrix[x][y];
        }
        --x;
        --y;
    }

    x = i + 1;
    y = j + 1;
    while (x < 10 && y < 10)
    {
        if (matrix[x][y] > max_value)
        {
            max_value = matrix[x][y];
        }
        ++x;
        ++y;
    }

    // Đường chéo phải
    x = i - 1;
    y = j + 1;
    while (x >= 0 && y < 10)
    {
        if (matrix[x][y] > max_value)
        {
            max_value = matrix[x][y];
        }
        --x;
        ++y;
    }

    x = i + 1;
    y = j - 1;
    while (x < 10 && y >= 0)
    {
        if (matrix[x][y] > max_value)
        {
            max_value = matrix[x][y];
        }
        ++x;
        --y;
    }

    return max_value;
}

int process(int a)
{
    if (a >= 0 && a < 10)
    {
        return a;
    }

    else if (a >= 10 && a < 100)
    {
        while (a >= 10)
        {
            int sum = 0;
            while (a != 0)
            {
                sum += a % 10;
                a /= 10;
            }

            a = sum;
        }
    }
    return a;
}

int f_count_A(int matrix[10][10], int E3)
{
    int count_A = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            if (matrix[i][j] < -E3)
                count_A++;
        }
    }
    return count_A;
}

int f_count_D(int matrix[10][10], int E3)
{
    int count_D = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            if (matrix[i][j] > 2 * E3)
                count_D++;
        }
    }
    return count_D;
}
// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }

    setHP(HP1);
    setHP(HP2);
    setExp(EXP1);
    setExp(EXP2);

    int arr[10][10] = {0};

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    int count_D = f_count_D(arr, E3);
    int count_A = f_count_A(arr, E3);
    int i = process(count_D);
    int j = process(count_A);

    int taxiScore = arr[i][j];
    int scoreSW = find_matrix(arr, i, j);

    if (abs(taxiScore) > scoreSW)
    {
        HP1 = ceil((double)HP1 - (double)HP1 * 10 / 100);
        setHP(HP1);
        EXP1 = ceil((double)EXP1 - (double)EXP1 * 12 / 100);
        setExp(EXP1);
        HP2 = ceil((double)HP2 - (double)HP2 * 10 / 100);
        setHP(HP1);
        EXP2 = ceil((double)EXP2 - (double)EXP2 * 12 / 100);
        setExp(EXP1);

        return taxiScore;
    }

    else
    {
        HP1 = ceil((double)HP1 + (double)HP1 * 10 / 100);
        setHP(HP1);
        EXP1 = ceil((double)EXP1 + (double)EXP1 * 12 / 100);
        setExp(EXP1);
        HP2 = ceil((double)HP2 + (double)HP2 * 10 / 100);
        setHP(HP1);
        EXP2 = ceil((double)EXP2 + (double)EXP2 * 12 / 100);
        setExp(EXP1);

        return scoreSW;
    }
}

// Task 4

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

bool isAlpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int checkPassword(const char *s, const char *email)
{
    const int MIN_LENGTH = 8;
    const int MAX_LENGTH = 20;
    const char *specialChars = "@#%$!";
    char emailCopy[101];
    strncpy(emailCopy, email, 100);
    emailCopy[100] = '\0'; // Đảm bảo chuỗi kết thúc bằng ký tự null
    const char *SS = strtok(emailCopy, "@");
    // strtok = string token, return a pointer to the "token" that is separated by a specified character.
    int len = strlen(s);
    if (len < MIN_LENGTH)
        return -1;
    if (len > MAX_LENGTH)
        return -2;
    if (strstr(s, SS) != NULL)
        return -(300 + (strstr(s, SS) - s)); // s la vi tri dau tien cua chuoi s, co s = 0;
    // strstr: tra ve 1 con tro la vi tri dau tien cua chuoi con SS trong chuoi s
    for (int i = 0; i < len - 2; ++i)
    {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
            return -(400 + i);
    }
    bool hasSpecialChar = false;
    for (int i = 0; i < len; ++i)
    {
        if (!isDigit(s[i]) && !isAlpha(s[i]) && strchr(specialChars, s[i]) == NULL)
            // strchr: finding the occurrence of a character in a string
            return i;
        if (strchr(specialChars, s[i]) != NULL)
            hasSpecialChar = true;
    }
    if (!hasSpecialChar)
        return -5; // no special character
    return -10;    // valid password
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int maxCount = 0, maxLength = 0, resPos = -1;
    for (int i = 0; i < num_pwds; ++i)
    {
        int count = 0;
        for (int j = 0; j < num_pwds; ++j)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                count++;
            }
        }
        int len = strlen(arr_pwds[i]);
        if (count > maxCount || (count == maxCount && len > maxLength))
        {
            maxCount = count;
            maxLength = len;
            resPos = i;
        }
    }
    return resPos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////