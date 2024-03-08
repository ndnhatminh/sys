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

void checkExp(int &exp)
{
    if (exp < 0)
    {
        exp = 0;
    }
    if (exp > 600)
    {
        exp = 600;
    }
}
void checkM(int &m)
{
    if (m < 0)
    {
        m = 0;
    }
    if (m > 3000)
    {
        m = 3000;
    }
}
void checkHP(int &hp)
{
    if (hp < 0)
    {
        hp = 0;
    }
    if (hp > 666)
    {
        hp = 666;
    }
}

double myCeil(double num)
{
    double wholePart = static_cast<int>(num);
    return wholePart < num ? wholePart + 1 : wholePart;
}

double getDoublePercentValue(int &value, double percent)
{
    return myCeil(static_cast<double>(value) * percent);
}

// Task 1

int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    double e1_double = static_cast<double>(e1);
    double answer1 = e1_double / 4 + 19;
    double answer2 = e1_double / 9 + 21;
    double answer3 = e1_double / 16 + 17;

    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }

    if (exp1 < 0)
    {
        exp1 = 0;
    }
    if (exp1 > 600)
    {
        exp1 = 600;
    }
    if (exp2 < 0)
    {
        exp2 = 0;
    }
    if (exp2 > 600)
    {
        exp2 = 600;
    }

    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0)
            exp2 += 29;
        else if (e1 == 1)
            exp2 += 45;
        else if (e1 == 2)
            exp2 += 75;
        else if (e1 == 3)
            exp2 += 29 + 45 + 75;

        int D = e1 * 3.0 + exp1 * 7.0;

        if (D % 2 == 0)
        {
            double ans = D / 200.0;
            double exp1_double;
            exp1_double = myCeil(exp1_double + ans);
            exp1 += exp1_double;
        }
        else
        {
            double ans = D / 100.0;
            double exp1_double;
            exp1_double = myCeil(exp1_double - ans);
            exp1 += exp1_double;
        }
    }
    else if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        {
            double exp2_double;
            exp2_double = myCeil(exp2_double + answer1);
            exp2 += exp2_double;
            if (exp2 > 600)
            {
                exp2 = 600;
            }
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            double exp2_double;
            exp2_double = myCeil(exp2_double + answer2);
            exp2 += exp2_double;
            if (exp2 > 600)
            {
                exp2 = 600;
            }
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            double exp2_double;
            exp2_double = myCeil(exp2_double + answer3);
            exp2 += exp2_double;
            if (exp2 > 600)
            {
                exp2 = 600;
            }
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            double exp2_double;
            exp2_double = myCeil(exp2_double + answer1);
            exp2 += exp2_double;
            exp2_double = 0;
            if (exp2 > 600)
            {
                exp2 = 600;
            }
            if (exp2 > 200)
            {
                exp2_double = myCeil(exp2_double + answer2);
                exp2 += exp2_double;
                if (exp2 > 600)
                {
                    exp2 = 600;
                }
            }
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            double exp2_double;
            exp2_double = myCeil(exp2_double + answer1);
            exp2 += exp2_double;
            exp2_double = 0;
            if (exp2 > 600)
            {
                exp2 = 600;
            }
            exp2_double = myCeil(exp2_double + answer2);
            exp2 += exp2_double;
            exp2_double = 0;
            if (exp2 > 600)
            {
                exp2 = 600;
            }
            if (exp2 > 400)
            {
                exp2_double = myCeil(exp2_double + answer3);
                exp2 += exp2_double;
                if (exp2 > 600)
                {
                    exp2 = 600;
                }
                double exp = static_cast<double>(exp2);
                exp = myCeil(exp * 1.15);
                exp2 += exp;
                if (exp2 > 600)
                {
                    exp2 = 600;
                }
            }
        }

        exp1 -= e1;
        if (exp1 < 0)
        {
            exp1 = 0;
        }
    }

    // Ensure exp1 and exp2 are within the range [0, 600]
    if (exp1 < 0)
    {
        exp1 = 0;
    }
    if (exp1 > 600)
    {
        exp1 = 600;
    }
    if (exp2 < 0)
    {
        exp2 = 0;
    }
    if (exp2 > 600)
    {
        exp2 = 600;
    }

    return exp1 + exp2;
}

// Task 2
int nearestPerfectSquare(int num)
{
    int lowerSquare = 0, upperSquare = 0;
    int lowerDiff = 0, upperDiff = 0;
    int i = 0;

    while (true)
    {
        if (i * i <= num)
        {
            lowerSquare = i * i;
            lowerDiff = num - lowerSquare;
        }
        else
        {
            upperSquare = i * i;
            upperDiff = upperSquare - num;
            break;
        }
        i++;
    }

    return (lowerDiff <= upperDiff) ? lowerSquare : upperSquare;
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (HP1 < 0)
    {
        HP1 = 0;
    }
    if (HP1 > 666)
    {
        HP1 = 666;
    }
    if (EXP1 < 0)
    {
        EXP1 = 0;
    }
    if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    if (M1 < 0)
    {
        M1 = 0;
    }
    if (M1 > 3000)
    {
        M1 = 3000;
    }

    double P1 = 0;
    // Calculate the nearest perfect square to EXP1
    int S = nearestPerfectSquare(EXP1);
    double S_double = static_cast<double>(S);
    double EXP1_double = static_cast<double>(EXP1);
    // Calculate the probability P1
    if (EXP1 > S)
    {
        P1 = 1;
    }
    else
    {
        P1 = ((EXP1_double / S_double) + 80) / 123;
    }

    double P2 = 0;
    int M = M1;

    if (M1 != 0)
    {
        while (true)
        {
            if (HP1 < 200)
            {
                HP1 = getDoublePercentValue(HP1, 1.3); // Increase HP1 by 30%
                M -= 150;                              // Deduct 150 from E2
                if (M <= 0.5 * M1)
                {
                    break;
                }
                if (M <= 0)
                {
                    M = 0;
                    break;
                }
            }
            else
            {
                HP1 = getDoublePercentValue(HP1, 1.1); // Increase HP1 by 10%
                if (HP1 > 666)
                {
                    HP1 = 666;
                }

                M -= 70; // Deduct 70 from E2
                if (M <= 0.5 * M1)
                {
                    break;
                }
                if (M <= 0)
                {
                    M = 0;
                    break;
                }
            }
            if (EXP1 < 400)
            {
                M -= 200; // Deduct 200 for taxi fare
                EXP1 = getDoublePercentValue(EXP1, 1.13);
                if (M <= 0.5 * M1)
                {
                    break;
                }
                if (M <= 0)
                {
                    M = 0;
                    break;
                }
            }
            else
            {
                M -= 120;                                 // Deduct 120 for horse fare
                EXP1 = getDoublePercentValue(EXP1, 1.13); // Increase EXP1 by 13%

                if (M <= 0.5 * M1)
                {
                    break;
                }
                if (M <= 0)
                {
                    M = 0;
                    break;
                }
            }
            if (EXP1 < 300)
            {
                M -= 100;
                EXP1 = getDoublePercentValue(EXP1, 0.9);
                if (M <= 0.5 * M1)
                {
                    break;
                }
                if (M <= 0)
                {
                    M = 0;
                    break;
                }
            }
            else
            {
                M -= 120;

                EXP1 = getDoublePercentValue(EXP1, 0.9);
                if (M <= 0.5 * M1)
                {
                    break;
                }
                if (M <= 0)
                {
                    M = 0;
                    break;
                }
            }
            if (M <= 0.5 * M1 || E2 % 2 == 0)
            {
                break;
            }
        }
        M1 = M;
    }

    HP1 = getDoublePercentValue(HP1, 0.83);
    if (HP1 < 0)
    {
        HP1 = 0;
    }

    EXP1 = getDoublePercentValue(EXP1, 1.17);
    if (EXP1 > 600)
    {
        EXP1 = 600;
    }

    int S2 = nearestPerfectSquare(EXP1);
    if (EXP1 > S2)
    {
        P2 = 1;
    }
    else
    {
        double S2_double = static_cast<double>(S2);
        double EXP1_double = static_cast<double>(EXP1);
        P2 = ((EXP1_double / S2_double) + 80) / 123;
    }

    // Phase 3
    double P[10] = {0.32, 0.47, 0.28, 0.79, 0.100, 0.50, 0.22, 0.83, 0.64, 0.11};

    int i = E2 < 10 ? E2 : (E2 / 10 + E2 % 10) % 10;
    double P3 = P[i];

    if (P3 == 1 && P2 == 1 && P1 == 1)
    {
        EXP1 = getDoublePercentValue(EXP1, 0.75);
        checkExp(EXP1);
    }
    else
    {
        double averageProbability = (P1 + P2 + P3) / 3;
        if (averageProbability < 0.5)
        {
            HP1 = getDoublePercentValue(HP1, 0.85);
            checkHP(HP1);
            EXP1 = getDoublePercentValue(EXP1, 1.15);
            checkExp(EXP1);
        }
        else
        {
            HP1 = getDoublePercentValue(HP1, 0.9);
            checkHP(HP1);
            EXP1 = getDoublePercentValue(EXP1, 1.2);
            checkExp(EXP1);
        }
    }

    HP1 = myCeil(HP1);
    EXP1 = myCeil(EXP1);

    return HP1 + EXP1 + M1;
}

// Task 3
const int N = 10;

// Custom max function
int maxVal(int a, int b)
{
    return (a > b) ? a : b;
}

int maxLeft(int matrix[10][10], int i, int j)
{
    int max_value = matrix[i][j];
    int x = i - 1, y = j - 1;
    while (x >= 0 && y >= 0)
    {
        max_value = maxVal(max_value, matrix[x][y]);
        x--;
        y--;
    }
    x = i + 1, y = j + 1;
    while (x < N && y < N)
    {
        max_value = maxVal(max_value, matrix[x][y]);
        x++;
        y++;
    }
    return max_value;
}
int maxRight(int matrix[10][10], int i, int j)
{
    int max_value = matrix[i][j];
    int x = i + 1, y = j - 1;
    while (x < N && y >= 0)
    {
        max_value = maxVal(max_value, matrix[x][y]);
        x++;
        y--;
    }
    x = i - 1, y = j + 1;
    while (x >= 0 && y < N)
    {
        max_value = maxVal(max_value, matrix[x][y]);
        x--;
        y++;
    }
    return max_value;
}

int sumDigits(int num)
{
    int sum = 0;
    while (num > 0 || sum > 9)
    {
        if (num == 0)
        {
            num = sum;
            sum = 0;
        }
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    int N = 10;
    int taxiMatrix[10][10];
    int detectiveMatrix[N][N];
    int iSum = 0, jSum = 0;

    // Tính điểm số kỹ năng cho taxi tại mỗi vị trí
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            taxiMatrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taxiMatrix[i][j] > (E3 * 2))
            {
                iSum++;
            }
            if (taxiMatrix[i][j] < (-E3))
            {
                jSum++;
            }
        }
    }

    while (iSum > 9)
    {
        iSum = sumDigits(iSum);
    }
    while (jSum > 9)
    {
        jSum = sumDigits(jSum);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int maxDiagonal = maxVal(maxLeft(taxiMatrix, i, j), maxRight(taxiMatrix, i, j));
            if (maxDiagonal < 0)
            {
                maxDiagonal = abs(maxDiagonal);
            }
            detectiveMatrix[i][j] = maxDiagonal;
        }
    }

    if (abs(taxiMatrix[iSum][jSum]) > detectiveMatrix[iSum][jSum])
    {
        HP1 = getDoublePercentValue(HP1, 0.9);
        HP2 = getDoublePercentValue(HP2, 0.9);
        EXP1 = getDoublePercentValue(EXP1, 0.88);
        EXP2 = getDoublePercentValue(EXP2, 0.88);
        return taxiMatrix[iSum][jSum];
    }
    else
    {
        HP1 = getDoublePercentValue(HP1, 1.1);
        HP2 = getDoublePercentValue(HP2, 1.1);
        EXP1 = getDoublePercentValue(EXP1, 1.12);
        EXP2 = getDoublePercentValue(EXP2, 1.12);
        return detectiveMatrix[iSum][jSum];
    }

    return 0;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    const char *se = strchr(email, '@');
    if (se)
    {
        int se_length = se - email;
        char *se_substring = new char[se_length + 1];
        strncpy(se_substring, email, se_length);
        se_substring[se_length] = '\0';
        const char *found = strstr(s, se_substring);
        if (found != NULL)
        {
            int position = found - s;
            delete[] se_substring;
            return -(300 + position);
        }
        delete[] se_substring;
    }

    int length = strlen(s);
    if (length < 8)
        return -1;
    if (length > 20)
        return -2;

    for (int i = 0; i < length - 2; i++)
    {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
            return -(400 + i);
    }

    const char *special_chars = "@#%$!";
    for (int i = 0; i < length; i++)
    {
        if (strchr(special_chars, s[i]) != NULL)
            return -5;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    const char *unique_pwds[30];
    int freq[30] = {0};
    int num_unique_pwds = 0;

    for (int i = 0; i < num_pwds; i++)
    {
        int j;
        for (j = 0; j < num_unique_pwds; j++)
        {
            if (strcmp(arr_pwds[i], unique_pwds[j]) == 0)
            {
                freq[j]++;
                break;
            }
        }
        if (j == num_unique_pwds)
        {
            unique_pwds[num_unique_pwds] = arr_pwds[i];
            freq[num_unique_pwds] = 1;
            num_unique_pwds++;
        }
    }

    int max_freq = 0;
    int longest_length = 0;
    const char *correct_password = NULL;
    for (int i = 0; i < num_unique_pwds; i++)
    {
        int length = strlen(unique_pwds[i]);
        if (freq[i] > max_freq || (freq[i] == max_freq && length > longest_length))
        {
            max_freq = freq[i];
            longest_length = length;
            correct_password = unique_pwds[i];
        }
    }

    for (int i = 0; i < num_pwds; i++)
    {
        if (arr_pwds[i] == correct_password)
        {
            return i;
        }
    }

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////