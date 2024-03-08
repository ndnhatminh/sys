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
    if (e1 < 0 || e1 > 99)
        return -99;
    if (exp1 < 0)
        exp1 = 0;
    if (exp2 < 0)
        exp2 = 0;
    if (exp1 > 600)
        exp1 = 600;
    if (exp2 > 600)
        exp2 = 600;
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
        if (e1 >= 4 && e1 <= 99)
        {
            if (e1 >= 4 && e1 <= 19)
            {
                exp2 += ceil((float)e1 / 4 + 19);
            }
            else if (e1 >= 20 && e1 <= 49)
            {
                exp2 += ceil((float)e1 / 9 + 21);
            }
            else if (e1 >= 50 && e1 <= 65)
            {
                exp2 += ceil((float)e1 / 16 + 17);
            }
            else if (e1 >= 66 && e1 <= 79)
            {
                exp2 += ceil((float)e1 / 4 + 19);
                if (exp2 > 200)
                    exp2 += ceil((float)e1 / 9 + 21);
            }
            else
            {
                exp2 += ceil((float)e1 / 4 + 19);
                exp2 += ceil((float)e1 / 9 + 21);

                if (exp2 > 400)
                {
                    exp2 += ceil((float)e1 / 16 + 17);
                    exp2 += ceil((float)exp2 * 1.5);
                }
            }
            if (exp2 > 600)
                exp2 = 600;
            if (exp1 > 600)
                exp1 = 600;
            if (exp1 < 0)
                exp1 = 0;
            if (exp2 < 0)
                exp2 = 0;
            exp1 -= e1;
            if (exp1 < 0)
                exp1 = 0;
        }
        break;
    }
    if (exp2 > 600)
        exp2 = 600;
    if (exp1 > 600)
        exp1 = 600;
    if (exp1 < 0)
        exp1 = 0;
    if (exp2 < 0)
        exp2 = 0;
    if (e1 < 4)
    {
        int d = e1 * 3 + exp1 * 7;
        if (d % 2 == 0)
            exp1 = ceil((float)exp1 + (float)d / 200);
        else
            exp1 = ceil((float)exp1 - (float)d / 100);
    }
    if (exp2 > 600)
        exp2 = 600;
    if (exp1 > 600)
        exp1 = 600;
    if (exp1 < 0)
        exp1 = 0;
    if (exp2 < 0)
        exp2 = 0;
    if (exp1 < 0)
        exp1 = 0;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (HP1 < 0)
        HP1 = 0;
    if (EXP1 < 0)
        EXP1 = 0;
    if (M1 < 0)
        M1 = 0;
    if (HP1 > 666)
        HP1 = 666;
    if (EXP1 > 600)
        EXP1 = 600;
    if (M1 > 3000)
        M1 = 3000;
#pragma region street_1
    int s1 = sqrt(EXP1);
    int s2 = s1 + 1;
    int res;
    float p1{2.0f};
    if (abs(EXP1 - s1 * s1) > abs(EXP1 - s2 * s2))
    {
        res = s2 * s2;
    }
    else
        res = s1 * s1;
    if (EXP1 >= res)
        p1 = 1;
    else
        p1 = ((float)(EXP1) / res + 80) / 123;
#pragma endregion

#pragma region street_2
    float p2;
    float init_coin = (float)M1 / 2;
    int coin_consume = 0;
    do
    {
        if (HP1 < 200)
        {
            HP1 = ceil(round(float(HP1) * 1.3 * 100) / 100);
            M1 -= 150;
            coin_consume += 150;
        }
        else
        {
            HP1 = ceil(round(float(HP1) * 1.1 * 100) / 100);
            M1 -= 70;
            coin_consume += 70;
        }

        if ((M1 <= 0 && E2 % 2 == 0) || (coin_consume >= init_coin && E2 % 2 == 1))
            break;
        if (EXP1 < 400)
        {
            M1 -= 200;
            coin_consume += 200;
            EXP1 = ceil(round((float)EXP1 * 1.13 * 100) / 100);
        }
        else
        {
            M1 -= 120;
            coin_consume += 120;
            EXP1 = ceil(round((float)EXP1 * 1.13 * 100) / 100);
        }
        if ((M1 <= 0 && E2 % 2 == 0) || (coin_consume >= init_coin && E2 % 2 == 1))
            break;
        if (EXP1 < 300)
        {
            M1 -= 100;
            coin_consume += 100;
            EXP1 = ceil(round((float)EXP1 * 0.9 * 100) / 100);
        }
        else
        {
            M1 -= 120;
            coin_consume += 120;
            EXP1 = ceil(round((float)EXP1 * 0.9 * 100) / 100);
        }
        if ((M1 <= 0 && E2 % 2 == 0) || (coin_consume >= init_coin && E2 % 2 == 1))
            break;

    } while (E2 % 2 == 1 && coin_consume <= init_coin);
    if (HP1 < 0)
        HP1 = 0;
    if (EXP1 < 0)
        EXP1 = 0;
    if (M1 < 0)
        M1 = 0;
    if (HP1 > 666)
        HP1 = 666;
    if (EXP1 > 600)
        EXP1 = 600;
    if (M1 > 3000)
        M1 = 3000;
    HP1 = ceil(round((float)HP1 * 0.83 * 100) / 100);
    EXP1 = ceil(round((float)EXP1 * 1.17 * 100) / 100);
    s1 = sqrt(EXP1);
    s2 = s1 + 1;
    if (abs(EXP1 - s1 * s1) > abs(EXP1 - s2 * s2))
    {
        res = s2 * s2;
    }
    else
        res = s1 * s1;
    if (EXP1 >= res)
        p2 = 1;
    else
        p2 = ((float)(EXP1) / res + 80) / 123;
#pragma endregion

#pragma region street_3
    float p3;
    int arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int tmp = E2;
    float ket_qua;
    res = 0;
    if (tmp < 10)
        res = tmp;
    else
    {
        while (tmp)
        {
            res += tmp % 10;
            tmp /= 10;
        }
        res = res % 10;
    }
    p3 = (float)arr[res] / 100;

#pragma endregion
    if (p3 == 1 && p2 == 1 && p1 == 1)
    {
        EXP1 = (float)EXP1 * 0.75;
    }
    else
    {
        ket_qua = (p1 + p2 + p3) / 3;
        if (ket_qua < 0.5)
        {
            HP1 = ceil(round((float)HP1 * 0.85 * 100) / 100);
            EXP1 = ceil(round((float)EXP1 * 1.15 * 100) / 100);
        }
        else
        {
            HP1 = ceil(round((float)HP1 * 0.9 * 100) / 100);
            EXP1 = ceil(round((float)EXP1 * 1.2 * 100) / 100);
        }
    }
    if (HP1 < 0)
        HP1 = 0;
    if (EXP1 < 0)
        EXP1 = 0;
    if (M1 < 0)
        M1 = 0;
    if (HP1 > 666)
        HP1 = 666;
    if (EXP1 > 600)
        EXP1 = 600;
    if (M1 > 3000)
        M1 = 3000;
    return HP1 + EXP1 + M1;
}
int convert_to_1digit(int n)
{
    if (n < 10)
        return n;
    int res = 0;
    while (n)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}
int find_highest_num(int arr[][10], int num, int x, int y)
{
    int res = -1e9;
    int x1 = x, x2 = x, y1 = y, y2 = y;

    while (x1 && y1 && x1 < 9 && y1 < 9)
    {
        x1--;
        y1--;
    }
    while (x2 && y2 && x2 < 9 && y2 < 9)
    {
        x2++;
        y2--;
    }
    for (int i = x1, j = y1; i < 10 && j < 10 && i >= 0 && j >= 0; i++, j++)
    {
        if (arr[i][j] > res)
            res = arr[i][j];
    }
    for (int i = x2, j = y2; i < 10 && i >= 0 && j < 10 && j >= 0; i--, j++)
    {
        if (arr[i][j] > res)
            res = arr[i][j];
    }
    return res;
}
// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (HP1 < 0)
        HP1 = 0;
    if (EXP1 < 0)
        EXP1 = 0;
    if (HP2 < 0)
        HP2 = 0;
    if (EXP2 < 0)
        EXP2 = 0;
    if (HP1 > 666)
        HP1 = 666;
    if (EXP1 > 600)
        EXP1 = 600;
    if (EXP2 > 600)
        EXP2 = 600;
    if (HP2 > 666)
        HP2 = 666;
    int arr[10][10]{0};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int x_axis = 0, y_axis = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] > (2 * E3))
                x_axis++;
            if (arr[i][j] < (-E3))
                y_axis++;
        }
    }

    while (x_axis >= 10)
    {
        x_axis = convert_to_1digit(x_axis);
    }
    while (y_axis >= 10)
    {
        y_axis = convert_to_1digit(y_axis);
    }
    int res = find_highest_num(arr, arr[x_axis][y_axis], x_axis, y_axis);
    if (abs(arr[x_axis][y_axis]) > res)
    {
        EXP1 = ceil(round((float)EXP1 * 0.88 * 100) / 100);
        HP1 = ceil(round((float)HP1 * 0.9 * 100) / 100);
        EXP2 = ceil(round((float)EXP2 * 0.88 * 100) / 100);
        HP2 = ceil(round((float)HP2 * 0.9 * 100) / 100);
        res = arr[x_axis][y_axis];
    }
    else
    {
        EXP1 = ceil(round((float)EXP1 * 1.12 * 100) / 100);
        HP1 = ceil(round((float)HP1 * 1.1 * 100) / 100);
        EXP2 = ceil(round((float)EXP2 * 1.12 * 100) / 100);
        HP2 = ceil(round((float)HP2 * 1.1 * 100) / 100);
    }
    if (HP1 < 0)
        HP1 = 0;
    if (EXP1 < 0)
        EXP1 = 0;
    if (HP2 < 0)
        HP2 = 0;
    if (EXP2 < 0)
        EXP2 = 0;
    if (HP1 > 666)
        HP1 = 666;
    if (EXP1 > 600)
        EXP1 = 600;
    if (EXP2 > 600)
        EXP2 = 600;
    if (HP2 > 666)
        HP2 = 666;

    return res;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    string se;
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
            break;
        se += email[i];
    }
    if (strlen(s) < 8)
        return -1;
    if (strlen(s) > 20)
        return -2;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == se[0])
        {
            int count = 1;
            for (int j = 1, k = i + 1; j < se.size() && k < strlen(s); j++, k++)
            {
                if (se[j] != s[k])
                    break;
                count++;
            }
            if (count == se.size())
            {
                return -(300 + i);
            }
        }
    }
    char check_double = s[0];
    int count_double = 0;
    for (int i = 1; i < strlen(s); i++)
    {

        if (check_double == s[i])
        {
            count_double++;
        }
        else
        {
            count_double = 0;
        }

        if (count_double == 2)
            return -(400 + i - 2);
        check_double = s[i];
    }
    bool check_special_sign = false;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            check_special_sign = true;
    }
    if (!check_special_sign)
        return -5;
    for (int i = 0; i < strlen(s); i++)
    {
        if (!(islower(s[i]) || isupper(s[i]) || isdigit(s[i]) || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))
        {
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int max_count = 0, max_length = 0, res = -1;
    for (int i = 0; i < num_pwds; i++)
    {
        int count = 1;
        for (int j = 0; j < num_pwds; j++)
        {
            if (i != j && strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                count++;
            }
        }
        if (count > max_count || (count == max_count && strlen(arr_pwds[i]) > max_length))
        {
            max_count = count;
            max_length = strlen(arr_pwds[i]);
            res = i;
        }
    }
    return res;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////