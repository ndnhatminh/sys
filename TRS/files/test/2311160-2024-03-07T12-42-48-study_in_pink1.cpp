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
int check(int n, int first, int last)
{
    if (n < first)
    {
        return first;
    }
    else if (n > last)
    {
        return last;
    }
    else
        return n;
}
int lastDigit(int n)
{
    return ((n / 10 + n % 10) % 10);
}

void buyFoodAndDrink(int &HP1, int &M1)
{
    if (HP1 < 200)
    {
        HP1 = HP1 + 0.3 * HP1 + 0.9999;
        M1 -= 150;
    }
    else
    {
        HP1 = HP1 + 0.1 * HP1 + 0.9999;
        M1 -= 70;
    }
}

void rentVehicle(int &EXP1, int &M1)
{
    if (EXP1 < 400)
    {
        M1 -= 200;
        EXP1 = EXP1 + 0.13 * EXP1 + 0.9999;
    }
    else
    {
        M1 -= 120;
        EXP1 = EXP1 + 0.13 * EXP1 + 0.9999;
    }
}

void helpHomeless(int &EXP1, int &M1)
{
    if (EXP1 < 300)
    {
        M1 -= 100;
        EXP1 = EXP1 - 0.1 * EXP1 + 0.9999;
    }
    else
    {
        M1 -= 120;
        EXP1 = EXP1 - 0.1 * EXP1 + 0.9999;
    }
}
int sumdigit(int n)
{
    int sum = 0;
    do
    {
        sum += n % 10;
        n /= 10;
    } while (n > 0);
    return (sum / 10 + sum % 10);
}

void findMax(int matrix[10][10], int row, int col, int &maxLeftDiagonal, int &maxRightDiagonal)
{
    maxLeftDiagonal = matrix[row][col];
    maxRightDiagonal = matrix[row][col];
    int tempRow = row, tempCol = col;

    while (tempRow > 0 && tempCol > 0)
    {
        tempRow--;
        tempCol--;
    }

    while (tempRow < 10 && tempCol < 10)
    {
        maxLeftDiagonal = max(maxLeftDiagonal, matrix[tempRow][tempCol]);
        tempRow++;
        tempCol++;
    }

    tempRow = row;
    tempCol = col;

    while (tempRow > 0 && tempCol < 9)
    {
        tempRow--;
        tempCol++;
    }

    while (tempRow < 10 && tempCol >= 0)
    {
        maxRightDiagonal = max(maxRightDiagonal, matrix[tempRow][tempCol]);
        tempRow++;
        tempCol--;
    }
}

int firstMeet(int &EXP1, int &EXP2, int e1)
{
    // TODO: Complete this function
    int d = 0;
    float x1t, x2t, add1, add2, add3, exp1i, exp2i;
    if (e1 < 0 || e1 > 99)
    {
        return -99;
        return EXP1;
        return EXP2;
    }
    else
    {
        EXP1 = check(EXP1, 0, 600);
        EXP2 = check(EXP2, 0, 600);
        x1t = EXP1;
        x2t = EXP2;
        if (e1 % 4 == 0)
            add1 = e1 / 4 + 19;
        else
            add1 = e1 / 4 + 20;
        if (e1 % 9 == 0)
            add2 = e1 / 9 + 21;
        else
            add2 = e1 / 9 + 22;
        if (e1 % 16 == 0)
            add3 = e1 * 1.000 / 16 + 17;
        else
            add3 = e1 / 16 + 18;

        if (e1 <= 3)
        {
            if (e1 == 0)
                EXP2 += 29;
            if (e1 == 1)
                EXP2 += 45;
            if (e1 == 2)
                EXP2 += 75;
            if (e1 == 3)
                EXP2 += 149;

            d = 3 * e1 + 7 * EXP1;

            if (d % 2 == 0)
            {
                EXP1 += d * 1.0000 / 200 + 0.9999;
            }
            else
            {
                EXP1 = EXP1 - d * 1.0000 / 100 + 0.9999;
            }

            // EXP1 = x1t;

            EXP1 = check(EXP1, 0, 600);
            EXP2 = check(EXP2, 0, 600);
        }

        else
        {
            if ((e1 >= 4) && (e1 <= 19))
                x2t = x2t + add1;
            if ((e1 >= 20) && (e1 <= 49))
                x2t = x2t + add2;
            if ((e1 >= 50) && (e1 <= 65))
                x2t = x2t + add3;
            if ((e1 >= 66) && (e1 <= 79))
            {
                x2t = x2t + add1;
                if (x2t > 200)
                    x2t = x2t + add2;
            }
            if ((e1 >= 80) && (e1 <= 99))
            {
                x2t = x2t + add1 + add2;
                if (x2t > 400)
                    x2t = 1.15 * (x2t + add3) + 0.9999;
            }

            EXP2 = x2t;
            EXP1 -= e1;

            EXP1 = check(EXP1, 0, 600);
            EXP2 = check(EXP2, 0, 600);
        }
        return EXP1 + EXP2;
    }
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    float Money = M1;
    float p = 0.0000, P1 = 0.0000, P2 = 0.0000, P3 = 0.0000;
    int index;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if ((round(sqrt(EXP1)) * round(sqrt(EXP1))) <= EXP1)
    {
        P1 = 100;
    }
    else
        P1 = ((EXP1 * 1.000) / (round(sqrt(EXP1)) * round(sqrt(EXP1))) + 80) * 100.0000 / 123;

    while (M1 >= Money * 1.000 / 2)
    {
        if (E2 % 2 == 1)
        {

            buyFoodAndDrink(HP1, M1);
            // std::cout << HP1 << " " << EXP1 << " " << M1 << std::endl;
            if (M1 < 0 || M1 < Money * 1.000 / 2)
                break;

            rentVehicle(EXP1, M1);
            // std::cout << HP1 << " " << EXP1 << " " << M1 << std::endl;
            if (M1 < 0 || M1 < Money * 1.000 / 2)
                break;

            helpHomeless(EXP1, M1);
            // std::cout << HP1 << " " << EXP1 << " " << M1 << std::endl;
            if (M1 < 0 || M1 < Money * 1.000 / 2)
                break;
        }
    }

    index = lastDigit(E2);
    P3 = P[index];
    HP1 = ceil(0.83 * HP1);
    EXP1 = ceil(1.17 * EXP1);

    // HP1 = check(HP1, 0, 666);
    // check(EXP1);

    if ((round(sqrt(EXP1)) * round(sqrt(EXP1))) <= EXP1)
    {
        P2 = 100;
    }
    else
        P2 = (EXP1 * 1.000 / (round(sqrt(EXP1)) * round(sqrt(EXP1))) + 80) * 100.0000 / 123;

    p = (P1 + P2 + P3) * 1.0000 / 3;

    if (p == 100)
    {
        EXP1 = ceil(0.75 * EXP1);
    }
    if (p < 50)
    {
        HP1 = ceil(0.85 * HP1);
        EXP1 = ceil(1.15 * EXP1);
    }
    else
    {
        HP1 = ceil(0.9 * HP1);
        EXP1 = ceil(1.2 * EXP1);
    }

    HP1 = check(HP1, 0, 666);
    EXP1 = check(EXP1, 0, 600);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    int matrix[10][10];
    int i, j, maxLeft, maxRight, MAX = 0, cnt_i = 0, cnt_j = 0;
    // cin >> e3 >> hp1 >> EXP1 >> hp2 >> EXP2;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (matrix[i][j] > (2 * E3))
                cnt_i += 1;
            else if (matrix[i][j] < (-E3))
                cnt_j += 1;
        }
    }

    i = sumdigit(cnt_i);
    j = sumdigit(cnt_j);
    findMax(matrix, i, j, maxLeft, maxRight);
    MAX = max(maxLeft, maxRight);
    if (abs(matrix[i][j]) > MAX)
    {
        EXP1 = ceil(EXP1 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        EXP2 = ceil(EXP2 * 0.88);
        HP2 = ceil(HP2 * 0.9);
    }
    else
    {
        EXP1 = ceil(EXP1 * 1.12);
        HP1 = ceil(HP1 * 1.1);
        EXP2 = ceil(EXP2 * 1.12);
        HP2 = ceil(HP2 * 1.1);
    }

    EXP1 = check(EXP1, 0, 600);
    EXP2 = check(EXP2, 0, 600);
    HP1 = check(HP1, 0, 666);
    HP2 = check(HP2, 0, 666);

    if (abs(matrix[i][j]) > MAX)
    {
        return matrix[i][j];
    }
    else
        return MAX;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    int len = strlen(s);
    int email_len = strlen(email);

    // Lấy chuỗi trước ký tự '@' trong email
    char se[101];
    int i = 0;
    while (email[i] != '@')
    {
        se[i] = email[i];
        i++;
    }
    se[i] = '\0';

    // Kiểm tra độ dài mật khẩu
    if (len < 8)
        return -1;
    if (len > 20)
        return -2;

    // Kiểm tra ký tự đặc biệt
    bool has_special_char = false;
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            has_special_char = true;
            break;
        }
    }
    if (!has_special_char)
        return -5;

    // Kiểm tra chuỗi "se"
    int se_pos = strstr(s, se) - s;
    if (se_pos >= 0)
        return -(300 + se_pos);

    // Kiểm tra nhiều hơn 2 ký tự liên tiếp
    for (int i = 0; i < len - 2; ++i)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            return -(400 + i);
        }
    }

    // Kiểm tra email
    for (int i = 0; i < email_len; ++i)
    {
        if (email[i] == '@')
        {
            return -10;
        }
    }

    // Trả về vị trí ký tự đầu tiên vi phạm
    for (int i = 0; i < len; ++i)
    {
        if (!isalnum(s[i]))
        {
            return i;
        }
    }
    return -99;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int max_count = 0;
    int max_length = 0;
    int correct_index = -1;

    for (int i = 0; i < num_pwds; ++i)
    {
        int count = 0;
        int length = strlen(arr_pwds[i]);

        for (int j = 0; j < num_pwds; ++j)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                count++;
            }
        }

        if (count > max_count || (count == max_count && length > max_length))
        {
            max_count = count;
            max_length = length;
            correct_index = i;
        }
    }

    if (correct_index != -1)
        return correct_index;
    else
        return -1;
}
