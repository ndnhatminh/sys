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

//! Task 1
int firstMeet(int &EXP1, int &EXP2, int E1)
{

    if (E1 < 0 || E1 > 99)
    {
        return -99;
    }

    else if (E1 >= 0 && E1 <= 3)
    {
        if (E1 == 0)
            EXP2 += 29;
        else if (E1 == 1)
            EXP2 += 45;
        else if (E1 == 2)
            EXP2 += 75;
        else if (E1 == 3)
            EXP2 = EXP2 + 45 + 75 + 29;
        int D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0)
        {
            EXP1 += ceil(D / 200.0);
        }
        else
        {
            EXP1 -= floor(D / 100.0);
        }
    }

    else if (E1 >= 4 && E1 <= 99)
    {
        if (E1 >= 4 && E1 <= 19)
        {
            EXP2 += ceil((E1 / 4.0) + 19);
        }
        else if (E1 >= 20 && E1 <= 49)
        {
            EXP2 += ceil((E1 / 9.0) + 21);
        }
        else if (E1 >= 50 && E1 <= 65)
        {
            EXP2 += ceil((E1 / 16.0) + 17);
        }
        else if (E1 >= 66 && E1 <= 79)
        {
            EXP2 += ceil((E1 / 4.0) + 19);
            if (EXP2 > 200)
            {
                EXP2 += ceil((E1 / 9.0) + 21);
            }
        }
        else if (E1 >= 80 && E1 <= 99)
        {
            EXP2 += ceil((E1 / 4.0) + 19);
            EXP2 += ceil((E1 / 9.0) + 21);
            if (EXP2 > 400)
            {
                EXP2 += ceil((E1 / 16.0) + 17);
                EXP2 += ceil(EXP2 * 0.15);
            }
        }
        EXP1 -= E1;
    }
    if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    if (EXP2 > 600)
    {
        EXP2 = 600;
    }
    if (EXP1 < 0)
    {
        EXP1 = 0;
    }
    if (EXP2 < 0)
    {
        EXP2 = 0;
    }

    return EXP1 + EXP2;
}

//! Task2
int nearestPerfectSquare(int EXP1)
{
    int squareRoot = ceil(std::floor(std::sqrt(EXP1)));
    int lowerSquare = squareRoot * squareRoot;
    int upperSquare = (squareRoot + 1) * (squareRoot + 1);

    return (EXP1 - lowerSquare <= upperSquare - EXP1) ? lowerSquare : upperSquare;
}

double calculateProbability(int EXP1, int S)
{
    double P1;

    if (EXP1 >= S)
    {
        P1 = 1.0;
    }
    else
    {
        P1 = ((EXP1) / S + 80.0) / 123.0;
    }

    return P1;
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }
    else
    {
        int nearestSquare = nearestPerfectSquare(EXP1);
        double probability = calculateProbability(EXP1, nearestSquare);
        int m0 = M1 / 2;
        bool skillsExecuted = false;
        // sk1
        do
        {
            if (HP1 < 200)
            {
                HP1 += ceil(0.3 * HP1);
                M1 -= 150;
                if (HP1 > 666)
                {
                    HP1 = 666;
                }
                if (HP1 < 0)
                {
                    HP1 = 0;
                }
                if (M1 < m0 && E2 % 2 == 1)
                {
                    break;
                }
                if (M1 < 0 && E2 % 2 == 0)
                {
                    break;
                }
            }
            else
            {
                HP1 = ceil(HP1 * 11.0 / 10);
                // HP1 += ceil(0.1 * HP1);
                if (M1 < m0)
                {
                    break;
                }
                M1 -= 70;
                if (HP1 > 666)
                {
                    HP1 = 666;
                }
                if (HP1 < 0)
                {
                    HP1 = 0;
                }
                if (M1 < m0 && E2 % 2 == 1)
                {
                    break;
                }
                if (M1 < 0 && E2 % 2 == 0)
                {
                    break;
                }
            }

            // sk2
            if (EXP1 < 400)
            {
                M1 -= 200;
                EXP1 += ceil(0.13 * EXP1);
                if (EXP1 > 600)
                {
                    EXP1 = 600;
                }
                if (EXP1 < 0)
                {
                    EXP1 = 0;
                }
                if (M1 < m0 && E2 % 2 == 1)
                {
                    break;
                }
                if (M1 < 0 && E2 % 2 == 0)
                {
                    break;
                }
            }
            else
            {
                M1 -= 120;
                EXP1 += ceil(0.13 * EXP1);
                if (EXP1 > 600)
                {
                    EXP1 = 600;
                }
                if (EXP1 < 0)
                {
                    EXP1 = 0;
                }
                if (M1 < m0 && E2 % 2 == 1)
                {
                    break;
                }
                if (M1 < 0 && E2 % 2 == 0)
                {
                    break;
                }
            }

            // sk3
            int m;
            if (EXP1 < 300)
            {
                M1 -= 100;
                EXP1 -= floor(0.1 * EXP1);
                if (EXP1 > 600)
                {
                    EXP1 = 600;
                }
                if (EXP1 < 0)
                {
                    EXP1 = 0;
                }
                if (M1 < m0 && E2 % 2 == 1)
                {
                    skillsExecuted = true;
                    break;
                }
                if (M1 < 0 && E2 % 2 == 0)
                {
                    skillsExecuted = true;
                    break;
                }
            }
            else
            {
                M1 -= 120;
                EXP1 -= floor(0.1 * EXP1);
                if (EXP1 > 600)
                {
                    EXP1 = 600;
                }
                if (EXP1 < 0)
                {
                    EXP1 = 0;
                }
                if (M1 < m0 && E2 % 2 == 1)
                {
                    skillsExecuted = true;
                    break;
                }
                if (M1 < 0 && E2 % 2 == 0)
                {
                    skillsExecuted = true;
                    break;
                }
            }
            skillsExecuted = true;
        } while (E2 % 2 == 1);

        if (E2 % 2 == 1)
        {
            HP1 -= floor(0.17 * HP1);
            if (HP1 > 666)
            {
                HP1 = 666;
            }
            if (HP1 < 0)
            {
                HP1 = 0;
            }
            EXP1 = ceil(EXP1 * 11.7 / 10);
            if (EXP1 > 600)
            {
                EXP1 = 600;
            }
            if (EXP1 < 0)
            {
                EXP1 = 0;
            }
        }
        else if (E2 % 2 == 0 && !skillsExecuted)
        {
            M1 = 0;
            HP1 -= floor(0.17 * HP1);
            if (HP1 > 666)
            {
                HP1 = 666;
            }
            if (HP1 < 0)
            {
                HP1 = 0;
            }
            EXP1 += ceil(0.17 * EXP1);
            if (EXP1 > 600)
            {
                EXP1 = 600;
            }
            if (EXP1 < 0)
            {
                EXP1 = 0;
            }
        }
        else if (E2 % 2 == 0 && skillsExecuted)
        {
            HP1 -= floor(0.17 * HP1);
            if (HP1 > 666)
            {
                HP1 = 666;
            }
            if (HP1 < 0)
            {
                HP1 = 0;
            }
            EXP1 += ceil(0.17 * EXP1);
            if (EXP1 > 600)
            {
                EXP1 = 600;
            }
            if (EXP1 < 0)
            {
                EXP1 = 0;
            }
        }

        int nearestSquare2 = nearestPerfectSquare(EXP1);
        double probability2 = calculateProbability(EXP1, nearestSquare2);

        int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int i;
        if (E2 < 10)
        {
            i = E2;
        }
        else
        {
            i = (E2 / 10 + E2 % 10) % 10;
        }

        double probability3 = P[i] / 100.0;

        if (probability == 1.0 && probability2 == 1.0 && probability3 == 1.0)
        {
            EXP1 -= floor(0.25 * EXP1);
            if (EXP1 > 600)
            {
                EXP1 = 600;
            }
            if (EXP1 < 0)
            {
                EXP1 = 0;
            }
        }
        else
        {
            double averageProbability = (probability + probability2 + probability3) / 3.0;

            if (averageProbability < 0.5)
            {
                HP1 -= floor(0.15 * HP1);
                if (HP1 > 666)
                {
                    HP1 = 666;
                }
                if (HP1 < 0)
                {
                    HP1 = 0;
                }
                EXP1 += ceil(0.15 * EXP1);
                if (EXP1 > 600)
                {
                    EXP1 = 600;
                }
                if (EXP1 < 0)
                {
                    EXP1 = 0;
                }
            }
            else
            {
                HP1 -= floor(0.1 * HP1);
                if (HP1 > 666)
                {
                    HP1 = 666;
                }
                if (HP1 < 0)
                {
                    HP1 = 0;
                }
                EXP1 = ceil(EXP1 * 12.0 / 10);

                if (EXP1 > 600)
                {
                    EXP1 = 600;
                }
                if (EXP1 < 0)
                {
                    EXP1 = 0;
                }
            }
        }
        if (EXP1 > 600)
        {
            EXP1 = 600;
        }
        if (EXP1 < 0)
        {
            EXP1 = 0;
        }
        if (HP1 > 666)
        {
            HP1 = 666;
        }
        if (HP1 < 0)
        {
            HP1 = 0;
        }
        if (M1 > 3000)
        {
            M1 = 3000;
        }
        if (M1 < 0)
        {
            M1 = 0;
        }
        return HP1 + EXP1 + M1;
    }
}

//! Task 3
void printMatrix(int array[10][10])
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int findPosition(int countBigger, int countSmaller, int &posI, int &posJ)
{
    int sumBigger = 0;
    int sumSmaller = 0;

    while (countBigger > 0 || sumBigger >= 10)
    {
        sumBigger += countBigger % 10;
        countBigger /= 10;

        if (countBigger == 0 && sumBigger >= 10)
        {
            countBigger = sumBigger;
            sumBigger = 0;
        }
    }

    while (countSmaller > 0 || sumSmaller >= 10)
    {
        sumSmaller += countSmaller % 10;
        countSmaller /= 10;

        if (countSmaller == 0 && sumSmaller >= 10)
        {
            countSmaller = sumSmaller;
            sumSmaller = 0;
        }
    }

    posI = sumBigger;
    posJ = sumSmaller;

    return ((posJ * 2) + (posI * 2)) * (posI - posJ);
}

int findMaxOnDiagonals(int array[10][10], int posI, int posJ)
{
    int maxDiagonalValue = array[posI][posJ];

    for (int i = 0; i < 10; ++i)
    {
        int j = posJ + (i - posI);
        if (j >= 0 && j < 10)
        {
            if (array[i][j] > maxDiagonalValue)
            {
                maxDiagonalValue = array[i][j];
            }
        }
    }

    for (int i = 0; i < 10; ++i)
    {
        int j = posJ - (i - posI);
        if (j >= 0 && j < 10)
        {
            if (array[i][j] > maxDiagonalValue)
            {
                maxDiagonalValue = array[i][j];
            }
        }
    }

    return maxDiagonalValue;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }
    else
    {
        int array[10][10];
        int countBigger = 0;
        int countSmaller = 0;

        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                array[i][j] = ((E3 * j) + (i * 2)) * (i - j);

                int currentElement = array[i][j];
                if (currentElement > 2 * E3)
                {
                    ++countBigger;
                }
                else if (currentElement < -E3)
                {
                    ++countSmaller;
                }
            }
        }
        int posI = 0, posJ = 0;
        int aValues = findPosition(countBigger, countSmaller, posI, posJ);
        int aValue = array[posI][posJ];
        int bValue = findMaxOnDiagonals(array, posI, posJ);

        if (std::abs(aValue) <= bValue)
        {
            EXP1 = ceil(EXP1 * 11.2 / 10);
            if (EXP1 > 600)
            {
                EXP1 = 600;
            }
            if (EXP1 < 0)
            {
                EXP1 = 0;
            }
            HP1 = ceil(HP1 * 11.0 / 10);
            if (HP1 > 666)
            {
                HP1 = 666;
            }
            if (HP1 < 0)
            {
                HP1 = 0;
            }
            EXP2 = ceil(EXP2 * 11.2 / 10);
            if (EXP2 > 600)
            {
                EXP2 = 600;
            }
            if (EXP2 < 0)
            {
                EXP2 = 0;
            }
            HP2 = ceil(HP2 * 11.0 / 10);
            if (HP2 > 666)
            {
                HP2 = 666;
            }
            if (HP2 < 0)
            {
                HP2 = 0;
            }
        }
        else
        {
            EXP1 = ceil(EXP1 * 88.0 / 100);
            if (EXP1 > 600)
            {
                EXP1 = 600;
            }
            if (EXP1 < 0)
            {
                EXP1 = 0;
            }
            HP1 = ceil(HP1 * 9.0 / 10);
            if (HP1 > 666)
            {
                HP1 = 666;
            }
            if (HP1 < 0)
            {
                HP1 = 0;
            }

            EXP2 = ceil(EXP2 * 88.0 / 100);
            if (EXP2 > 600)
            {
                EXP2 = 600;
            }
            if (EXP2 < 0)
            {
                EXP2 = 0;
            }
            HP2 = ceil(HP2 * 9.0 / 10);
            if (HP2 > 666)
            {
                HP2 = 666;
            }
            if (HP2 < 0)
            {
                HP2 = 0;
            }
        }
        if (std::abs(aValue) <= bValue)
        {
            return abs(bValue);
        }
        else
        {
            return aValue;
        }
    }
}

//! Task 4
int checkPassword(const char *s, const char *email)
{

    char se[101];

    const char *atPosition = strchr(email, '@');

    if (atPosition == NULL)
    {

        return -99;
    }

    int length = atPosition - email;
    strncpy(se, email, length);
    se[length] = '\0';

    int sLength = strlen(s);

    if (sLength < 8)
    {
        return -1;
    }

    if (sLength > 20)
    {
        return -2;
    }

    const char *sePosition = strstr(s, se);

    if (sePosition != NULL)
    {

        return -(300 + (sePosition - s));
    }

    for (int i = 0; i < sLength - 2; ++i)
    {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
        {
            return -(400 + i);
        }
    }

    for (int i = 0; i < sLength; ++i)
    {
        if ((s[i] == '[' || s[i] == ']'))
        {
            int specialCharCount1 = 0;

            for (int i = 0; i < sLength; ++i)
            {
                if (s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%' || s[i] == '&' || s[i] == '!')
                {
                    specialCharCount1++;
                }
            }

            if (specialCharCount1 == 0)
            {
                return -5;
            }
            return i;
        }
    }
    int specialCharCount = 0;

    for (int i = 0; i < sLength; ++i)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%' || s[i] == '&' || s[i] == '!')
        {
            specialCharCount++;
        }
    }

    if (specialCharCount == 0)
    {
        return -5;
    }
    return -10;
}

//! Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    if (num_pwds <= 0)
    {
        return -1;
    }

    int max_freq = 0;
    int max_length = 0;
    int position = -1;

    for (int i = 0; i < num_pwds; i++)
    {
        int current_freq = 0;
        int current_length = strlen(arr_pwds[i]);

        for (int j = 0; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                current_freq++;
            }
        }

        if (current_freq > max_freq || (current_freq == max_freq && current_length > max_length))
        {
            max_freq = current_freq;
            max_length = current_length;
            position = i;
        }
    }

    return position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////