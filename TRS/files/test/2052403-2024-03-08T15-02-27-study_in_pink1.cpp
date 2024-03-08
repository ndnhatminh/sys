#include "study_in_pink1.h"
#include <cmath>
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

int hpCheck(int hp)
{
    if (hp > 666)
        return 666;
    else if (hp < 0)
        return 0;
    else
        return hp;
}

int expCheck(int exp)
{
    if (exp > 600)
        return 600;
    else if (exp < 0)
        return 0;
    else
        return exp;
}

int moneyCheck(int m)
{
    if (m > 3000)
        return 3000;
    else if (m < 0)
        return 0;
    else
        return m;
}
float ceil_two_decimal(float n)
{
    return ceil(n * 100) / 100;
}

int findNearestPerfectSquare(int n)
{
    int sqrt_n = static_cast<int>(sqrt(n)); // Calculate integer square root

    int lower = sqrt_n * sqrt_n;              // Lower bound square
    int higher = (sqrt_n + 1) * (sqrt_n + 1); // Upper bound square

    int diffLower = abs(lower - n);   // Absolute difference from lower square
    int diffHigher = abs(higher - n); // Absolute difference from higher square

    if (diffLower <= diffHigher)
    {
        return lower;
    }
    else
    {
        return higher;
    }
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    float expIncrease = 0;
    int decision = 0;

    if (e1 >= 0 && e1 <= 3)
    {
        switch (e1)
        {
        case 0:
            expIncrease = 29;
            break;
        case 1:
            expIncrease = 45;
            break;
        case 2:
            expIncrease = 75;
            break;
        case 3:
            expIncrease = 149;
            break;
        default:
            return -99;
        }

        decision = e1 * 3 + exp1 * 7;
        exp1 += (decision % 2 == 0) ? ceil(decision / 200) : -ceil(decision / 100);
        exp2 += expIncrease;

        return expCheck(exp1) + expCheck(exp2);
    }
    else if (e1 >= 4 && e1 <= 99)
    {
        if (e1 <= 19)
            expIncrease = float(e1) / 4 + 19;
        else if (e1 >= 20 && e1 <= 49)
            expIncrease = float(e1) / 9 + 21;
        else if (e1 >= 50 && e1 <= 65)
            expIncrease = float(e1) / 16 + 17;
        else if (e1 >= 66 && e1 <= 79)
        {
            expIncrease = float(e1) / 4 + 19;
            if (exp2 + ceil(expIncrease) > 200)
                expIncrease = ceil(expIncrease) + (e1 / 9 + 21);
        }
        else if (e1 >= 80)
        {
            expIncrease = ceil(expIncrease + (float(e1) / 4 + 19));
            expIncrease = ceil(expIncrease + (float(e1) / 9 + 21));

            if (exp2 + expIncrease > 400)
            {
                expIncrease = ceil(expIncrease + (float(e1) / 16 + 17));
            }
        }
        else
            return -99;

        exp2 = expCheck(ceil(exp2 + expIncrease));
        if (e1 >= 80 && expIncrease >= 93)
        {
            exp2 = expCheck(ceil(exp2 * 1.15));
        }
        exp1 -= e1;
        return expCheck(exp1) + expCheck(exp2);
    }
    return -99;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    // Route 1
    int sqrt_exp1, paid_money, total_paid = 0;
    int start_m = M1;
    float P1, P2, P3;
    int s = findNearestPerfectSquare(EXP1);

    if (s <= EXP1)
    {
        P1 = 1;
    }
    else
    {
        P1 = ceil_two_decimal(ceil_two_decimal(EXP1 / s + 80) / 123);
    }
    // Route 2
    do
    {
        // Event 1
        if (HP1 < 200)
        {
            HP1 = ceil(HP1 * 1.3);
            paid_money = 150;
        }
        else
        {
            HP1 = ceil(HP1 * 1.1);
            paid_money = 70;
        }
        HP1 = hpCheck(HP1);
        M1 = moneyCheck(M1 - paid_money);
        total_paid += paid_money;
        if (total_paid > 0.5 * start_m)
        {
            HP1 = hpCheck(ceil(HP1 * 0.83));
            EXP1 = expCheck(ceil(EXP1 * 1.17));
            break;
        }
        // Event 2
        if (M1 > 0)
        {
            if (EXP1 < 400)
            {
                paid_money = 200;
            }
            else
            {
                paid_money = 120;
            }
            EXP1 = expCheck(ceil(EXP1 * 1.13));
        }
        M1 = moneyCheck(M1 - paid_money);
        total_paid += paid_money;
        if (total_paid > 0.5 * start_m)
        {
            HP1 = hpCheck(ceil(HP1 * 0.83));
            EXP1 = expCheck(ceil(EXP1 * 1.17));
            break;
        }
        // Event 3
        if (M1 > 0)
        {
            if (EXP1 < 300)
            {
                paid_money = 100;
            }
            else
            {
                paid_money = 120;
            }

            EXP1 = expCheck(ceil(EXP1 * 0.9));
        }
        M1 = moneyCheck(M1 - paid_money);
        total_paid += paid_money;
        if (total_paid > 0.5 * start_m)
        {
            HP1 = hpCheck(ceil(HP1 * 0.83));
            EXP1 = expCheck(ceil(EXP1 * 1.17));
            break;
        }
    } while (E2 % 2 == 1);

    s = findNearestPerfectSquare(EXP1);
    if (s <= EXP1)
    {
        P2 = 1;
    }
    else
    {
        P2 = (EXP1 / s + 80) / 123;
    }

    // Route 3
    int i, a;
    if (E2 < 10)
    {
        i = E2;
    }
    else if (E2 < 99 && E2 >= 10)
    {
        a = E2 / 10 + E2 % 10;
        i = a % 10;
    }

    switch (i)
    {
    case 1:
        P3 = 0.32;
    case 2:
        P3 = 0.47;
    case 3:
        P3 = 0.28;
    case 4:
        P3 = 0.79;
    case 5:
        P3 = 1;
    case 6:
        P3 = 0.50;
    case 7:
        P3 = 0.22;
    case 8:
        P3 = 0.83;
    case 9:
        P3 = 0.64;
    case 10:
        P3 = 0.11;
    }

    float P;
    if (P1 == 100 && P2 == 100 && P3 == 100)
    {
        EXP1 = expCheck(ceil(EXP1 * 0.75));
    }
    else
    {
        P = (P1 + P2 + P3) / 3;
        if (P < 0.5)
        {
            HP1 = hpCheck(ceil(HP1 * 0.85));
            EXP1 = expCheck(ceil(EXP1 * 1.15));
        }
        else
        {
            HP1 = hpCheck(ceil(HP1 * 0.9));
            EXP1 = expCheck(ceil(EXP1 * 1.2));
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    int points, count_pos, count_neg;
    int matrix[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = (E3 * j + i * 2) * (i - j);
            if (matrix[i][j] > E3 * 2)
            {
                count_pos += 1;
            }
            if (matrix[i][j] < -E3)
            {
                count_neg += 1;
            }
        }
    }

    do
    {
        count_pos = count_pos % 10 + count_pos / 10;
        count_neg = count_neg % 10 + count_neg / 10;
    } while (count_pos >= 10 || count_neg >= 10);

    points = matrix[count_pos][count_neg];
    int max = points;

    for (int i = 0; i < 10; i++)
    {
        int j = count_neg + (i - count_pos);
        if (j >= 0 && j < 10)
        {
            if (max < matrix[i][j])
            {
                max = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        int j = count_neg - (i - count_pos);
        if (j > 0 && j < 10)
        {
            if (max < matrix[i][j])
            {
                max = matrix[i][j];
            }
        }
    }

    if (abs(points) > max)
    {
        HP1 = hpCheck(ceil(0.9 * HP1));
        EXP1 = expCheck(ceil(0.88 * EXP1));
        HP2 = hpCheck(ceil(0.9 * HP2));
        EXP2 = expCheck(ceil(0.88 * EXP2));
        return points;
    }
    else
    {
        HP1 = hpCheck(ceil(1.1 * HP1));
        EXP1 = expCheck(ceil(1.12 * EXP1));
        HP2 = hpCheck(ceil(1.1 * HP2));
        EXP2 = expCheck(ceil(1.12 * EXP2));

        return max;
    }
}

int checkPassword(const char *s, const char *email)
{
    int len = strlen(s);
    const char *special_chars = "@#%$!";
    int email_length = strlen(email);
    int atIndex = -1;
    for (int i = 0; i < email_length; i++)
    {
        if (email[i] == '@')
        {
            atIndex = i;
            break;
        }
    }
    if (atIndex == -1)
        return -6;

    char se[101];
    strncpy(se, email, atIndex);
    se[atIndex] = '\0';

    if (len < 8)
        return -1;
    if (len > 20)
        return -2;

    bool hasSpecialChar = false;
    for (int i = 0; i < len; i++)
    {

        if (strstr(s, se) != NULL)
            return -(300 + int(strstr(s, se) - s));
        if (i > 1 && s[i] == s[i - 1] && s[i] == s[i - 2])
            return -(400 + i);
        if (strchr(special_chars, s[i]))
            hasSpecialChar = true;
        if (!((s[i] >= '0' && s[i] <= '9') ||
              (s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= 'A' && s[i] <= 'Z') ||
              strchr(special_chars, s[i])))
        {
            return i;
        }
    }

    if (!hasSpecialChar)
        return -5;

    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int max_count = 0;
    int max_length = 0;
    int max_index = -1;

    for (int i = 0; i < num_pwds; i++)
    {
        int current_count = 0;
        for (int j = 0; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                current_count++;
            }
        }

        if (current_count > max_count || (current_count == max_count && strlen(arr_pwds[i]) > max_length))
        {
            max_count = current_count;
            max_length = strlen(arr_pwds[i]);
            max_index = i;
        }
    }

    return max_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////