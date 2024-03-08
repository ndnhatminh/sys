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
// Hàm làm tròn số nguyên gần nhất
int checkInputOutputTask1(int &exp1, int &exp2)
{
    if (exp1 < 0)
    {
        exp1 = 0;
    }
    else if (exp1 > 600)
    {
        exp1 = 600;
    }
    if (exp2 < 0)
    {
        exp2 = 0;
    }
    else if (exp2 > 600)
    {
        exp2 = 600;
    }
    return 1;
}
int checkInputOutputTask2(int &hp1, int &exp1, int &m1)
{
    if (exp1 < 0)
    {
        exp1 = 0;
    }
    else if (exp1 > 600)
    {
        exp1 = 600;
    }
    if (hp1 < 0)
    {
        hp1 = 0;
    }
    else if (hp1 > 666)
    {
        hp1 = 666;
    }
    if (m1 < 0)
    {
        m1 = 0;
    }
    else if (m1 > 3000)
    {
        m1 = 3000;
    }
    return 1;
}
int checkInputOutputTask3(int &hp1, int &exp1, int &hp2, int &exp2)
{
    if (exp1 < 0)
    {
        exp1 = 0;
    }
    else if (exp1 > 600)
    {
        exp1 = 600;
    }
    if (hp1 < 0)
    {
        hp1 = 0;
    }
    else if (hp1 > 666)
    {
        hp1 = 666;
    }
    if (hp2 < 0)
    {
        hp2 = 0;
    }
    else if (hp2 > 666)
    {
        hp2 = 666;
    }
    if (exp2 < 0)
    {
        exp2 = 0;
    }
    else if (exp2 > 600)
    {
        exp2 = 600;
    }
    return 1;
}
int roundInt(float e)
{
    if (e == int(e))
        return e;
    else
        return int(e) + 1;
}
bool isSquare(int n)
{
    if (n >= 0)
    {
        int k = sqrt(n);
        return k * k == n;
    }
    return false;
}

// Hàm tìm số chính phương gần nhất
int nearestSquare(int exp1)
{
    int less = exp1 - 1;
    int greater = exp1 + 1;

    while (true)
    {
        if (isSquare(less))
            return less;
        else if (isSquare(greater))
            return greater;

        less--;
        greater++;
    }

    return nearestSquare(exp1);
}

int findMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Hàm để xử lý nhiệm vụ
int task(int E)
{
    if (E < 0 || E > 99)
        return -99;

    // Xử lý nhiệm vụ ở đây

    return 0; // Trả về 0 nếu xử lý thành công
}
bool isSpecial(char n)
{
    if (n == '@' || n == '#' || n == '%' || n == '$' || n == '!')
        return true;
    return false; // Added return statement
}

// Task 1

int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    int check = checkInputOutputTask1(exp1, exp2);
    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }
    int D = e1 * 3 + exp1 * 7;
    // case 1
    if (e1 >= 0 && e1 <= 3)
    {
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
            exp2 += 29 + 45 + 75;
        }
        if (D % 2 == 0)
        {
            exp1 = roundInt(float(exp1) + float(D) / float(200));
            exp1 = roundInt(exp1);
        }
        else
        {
            exp1 = roundInt(float(exp1) - float(D) / float(100));
            exp1 = roundInt(exp1);
        }
    }
    // case 2
    else if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 += roundInt(float(float(e1) / 4 + 19));
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 += roundInt(float(float(e1) / 9 + 21));
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 += roundInt(float(float(e1) / 16 + 17));
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 += roundInt(float(float(e1) / 16 + 17));
            if (exp2 > 200)
            {
                exp2 += roundInt(float(float(e1) / 9 + 21));
            }
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 += roundInt(float(float(e1) / 4 + 19));
            exp2 += roundInt(float(float(e1) / 9 + 21));
            if (exp2 > 400)
            {
                exp2 += roundInt(float(float(e1) / 16 + 17));
                exp2 = roundInt(float(float(exp2) + float(exp2) * 0.15));
            }
        }
        exp1 -= e1;
        exp1 = roundInt(float(exp1));
    }
    int checkresult = checkInputOutputTask1(exp1, exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (E2 < 0 || E2 > 99)
        return -99;
    // Route 1
    int check = checkInputOutputTask2(HP1, EXP1, M1);
    int S = nearestSquare(EXP1);
    int firstMoney = M1;
    float P1, P2;
    if (EXP1 >= S)
    {
        P1 = float(1.0);
    }
    else
    {
        P1 = float((float((float(EXP1) / float(S))) + float(80)) / 123.0);
    }
    // Route 2
    if (E2 % 2 != 0)
    {
        int firstMoney = roundInt(float(M1) / 2.0);
        int checkResult;
        int paidMoney = 0;
        while (firstMoney > paidMoney)
        {
            // food
            if (HP1 < 200)
            {
                HP1 = roundInt(float(HP1) * 1.3);
                M1 -= 150;
                paidMoney += 150;
                checkResult = checkInputOutputTask2(HP1, EXP1, M1);
                if (paidMoney > firstMoney)
                    break;
            }
            else
            {
                HP1 = roundInt(float(HP1) * 1.1);
                M1 -= 70;
                paidMoney += 70;
                checkResult = checkInputOutputTask2(HP1, EXP1, M1);
                if (paidMoney > firstMoney)
                    break;
            }
            // vehicle
            if (EXP1 < 400)
            {
                M1 -= 200;
                paidMoney += 200;
                EXP1 = roundInt(float(EXP1) * 1.13);
                checkResult = checkInputOutputTask2(HP1, EXP1, M1);
                if (paidMoney > firstMoney)
                    break;
            }
            else
            {
                M1 -= 120;
                paidMoney += 120;
                EXP1 = roundInt(float(EXP1) * 1.13);
                checkResult = checkInputOutputTask2(HP1, EXP1, M1);
                if (paidMoney > firstMoney)
                    break;
            }
            // homeless
            if (EXP1 < 300)
            {
                M1 -= 100;
                paidMoney += 100;
                EXP1 = roundInt(float(EXP1) * 0.9);
                checkResult = checkInputOutputTask2(HP1, EXP1, M1);
                if (paidMoney > firstMoney)
                    break;
            }
            else
            {
                M1 -= 120;
                paidMoney += 120;
                EXP1 = roundInt(float(EXP1) * 0.9);
                checkResult = checkInputOutputTask2(HP1, EXP1, M1);
                if (paidMoney > firstMoney)
                    break;
            }
        }
        EXP1 = roundInt(float(EXP1) * 1.17);
        HP1 = roundInt(float(HP1) * 0.83);
        checkResult = checkInputOutputTask2(HP1, EXP1, M1);

        int S1 = nearestSquare(EXP1);
        if (EXP1 >= S1)
        {
            P2 = float(1.0);
        }
        else
        {
            P2 = float((float((float(EXP1) / float(S1))) + float(80)) / 123.0);
        }
    }
    else
    {
        int firstMoney = roundInt(float(M1) / 2.0);
        int checkResult;
        // food
        if (HP1 < 200 && M1 > 0)
        {
            HP1 = roundInt(float(HP1) * 1.3);
            M1 -= 150;
            checkResult = checkInputOutputTask2(HP1, EXP1, M1);
        }
        else if (HP1 >= 200 && M1 > 0)
        {
            HP1 = roundInt(float(HP1) * 1.1);
            M1 -= 70;
            checkResult = checkInputOutputTask2(HP1, EXP1, M1);
        }
        // vehicle
        if (EXP1 < 400 && M1 > 0)
        {
            M1 -= 200;
            EXP1 = roundInt(float(EXP1) * 1.13);
            checkResult = checkInputOutputTask2(HP1, EXP1, M1);
        }
        else if (EXP1 >= 400 && M1 > 0)
        {
            M1 -= 120;
            EXP1 = roundInt(float(EXP1) * 1.13);
            checkResult = checkInputOutputTask2(HP1, EXP1, M1);
        }
        // homeless
        if (EXP1 < 300 && M1 > 0)
        {
            M1 -= 100;
            EXP1 = roundInt(float(EXP1) * 0.9);
            checkResult = checkInputOutputTask2(HP1, EXP1, M1);
        }
        else if (EXP1 >= 300 && M1 > 0)
        {
            M1 -= 120;
            EXP1 = roundInt(float(EXP1) * 0.9);
            checkResult = checkInputOutputTask2(HP1, EXP1, M1);
        }
        EXP1 = roundInt(float(EXP1) * 1.17);
        HP1 = roundInt(float(HP1) * 0.83);
        checkResult = checkInputOutputTask2(HP1, EXP1, M1);
        int S1 = nearestSquare(EXP1);
        if (EXP1 >= S1)
        {
            P2 = float(1.0);
        }
        else
        {
            P2 = float((float((float(EXP1) / float(S1))) + float(80)) / 123.0);
        }
    }
    // Route 3
    int arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = 0;
    if (E2 < 10)
    {
        i = E2;
    }
    else
    {
        i = (E2 % 10) + (int(E2 / 10) % 10);
        if (i >= 10)
        {
            i = i % 10;
        }
    }
    float P3 = float(arr[i]);
    P2 = float(P2) * 100.0;
    P1 = float(P1) * 100.0;
    float average;
    if (P1 == P2 == P3 == 100.0)
    {
        EXP1 = roundInt(float(EXP1) * 0.75);
        check = checkInputOutputTask2(HP1, EXP1, M1);
    }
    else
    {
        average = (P1 + P2 + float(P3)) / 3.0;
        if (average < 50)
        {
            HP1 = roundInt(float(HP1) * 0.85);
            EXP1 = roundInt(float(EXP1) * 1.15);
            check = checkInputOutputTask2(HP1, EXP1, M1);
        }
        else
        {
            HP1 = roundInt(float(HP1) * 0.9);
            EXP1 = roundInt(float(EXP1) * 1.2);
            check = checkInputOutputTask2(HP1, EXP1, M1);
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }
    int matrix[10][10] = {0};
    int rows = 10;
    int cols = 10;
    int sumA = 0;
    int sumB = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    // for (int i = 0; i < rows; ++i)
    // {
    //     for (int j = 0; j < cols; ++j)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] > (E3 * 2))
            {
                sumA += 1;
            }
            if (matrix[i][j] < (E3 * -1))
            {
                sumB += 1;
            }
        }
    }
    while (sumA >= 10)
    {
        sumA = (sumA % 10) + (int(sumA / 10) % 10);
    }
    while (sumB >= 10)
    {
        sumB = (sumB % 10) + (int(sumB / 10) % 10);
    }
    int arr[20] = {0};
    int index = 0;
    int i = sumA;
    int j = sumB;
    int x = i, y = j;
    int x1 = i, y1 = j;
    while (x > 0 && y > 0)
    {
        x--;
        y--;
    }
    while (x1 > 0 && y1 < 9)
    {
        x1--;
        y1++;
    }
    while (x < rows && y < cols)
    {
        arr[index++] = matrix[x][y];
        x++;
        y++;
    }
    while (x1 < rows && y1 < cols && x1 >= 0 && y1 >= 0)
    {
        arr[index++] = matrix[x1][y1];
        x1++;
        y1--;
    }
    int SW = findMax(arr, 20);
    int point = matrix[i][j];
    int result;
    if (abs(point) > SW)
    {
        HP1 = roundInt(float(HP1) * 0.9);
        EXP1 = roundInt(float(EXP1) * 0.88);
        HP2 = roundInt(float(HP2) * 0.9);
        EXP2 = roundInt(float(EXP2) * 0.88);
        int checkResult = checkInputOutputTask3(HP1, EXP1, HP2, EXP2);
        result = point;
    }
    else
    {
        HP1 = roundInt(float(HP1) * 1.1);
        EXP1 = roundInt(float(EXP1) * 1.12);
        HP2 = roundInt(float(HP2) * 1.1);
        EXP2 = roundInt(float(EXP2) * 1.12);
        int checkResult = checkInputOutputTask3(HP1, EXP1, HP2, EXP2);
        result = SW;
    }
    return result;
}
// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    string emailStr = email;
    string sStr = s;
    string se = emailStr.substr(0, emailStr.find('@'));
    size_t sei = sStr.find(se);
    char element;

    if (sStr.length() < 8)
        return -1;
    if (sStr.length() > 20)
        return -2;

    for (int i = 0; i < sStr.length(); i++)
    {
        element = sStr[i];
        if (i == sei)
        {
            return -(300 + i);
        }
    }

    for (int i = 0; i < sStr.length() - 2; i++)
    {
        if (sStr[i] == sStr[i + 1] && sStr[i + 1] == sStr[i + 2])
        {
            return -(400 + i);
        }
    }

    for (int i = 0; i < sStr.length(); i++)
    {
        if (!isalnum(sStr[i]) && !isSpecial(sStr[i]))
            return -5;
    }

    return -10;

    return -99;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{

    int count[num_pwds];
    string arr_pwdsn[num_pwds];

    for (int i = 0; i < num_pwds; ++i)
    {
        arr_pwdsn[i] = arr_pwds[i];
    }

    for (int i = 0; i < num_pwds; ++i)
    {
        count[i] = 0;
        for (int j = 0; j < num_pwds; ++j)
        {
            if (arr_pwdsn[i] == arr_pwdsn[j])
            {
                count[i]++;
            }
        }
    }

    int maxCount = 0;
    for (int i = 0; i < num_pwds; ++i)
    {
        if (count[i] > maxCount)
        {
            maxCount = count[i];
        }
    }

    int maxIndex[num_pwds];
    int num = 0;
    for (int i = 0; i < num_pwds; ++i)
    {
        if (count[i] == maxCount)
        {
            maxIndex[num++] = i;
        }
    }

    int length = 0;
    int correct = -1;
    for (int i = 0; i < num; ++i)
    {
        int index = maxIndex[i];
        int len = arr_pwdsn[index].length();
        if (len > length)
        {
            length = len;
            correct = index;
        }
    }

    return correct;

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////