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
int checkExp(int &exp)
{
    if (exp > 600)
    {
        exp = 600;
        return exp;
    }

    if (exp < 0)
    {
        exp = 0;
    }
    return exp;
}

int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
        return -99;
    checkExp(exp1);
    checkExp(exp2);

    int inf1 = ceil(e1 / 4.0 + 19), inf2 = ceil(e1 / 9.0 + 21), inf3 = ceil(e1 / 16.0 + 17);
    if (e1 >= 80)
    {
        exp2 += (inf1 + inf2);
        if (exp2 > 400)
            exp2 = ceil((exp2 + inf3) * 1.15);
        exp1 -= e1;
    }
    else if (e1 >= 66)
    {
        exp2 += inf1;
        if (exp2 > 200)
            exp2 += inf2;
        exp1 -= e1;
    }
    else if (e1 >= 50)
    {
        exp2 += inf3;
        exp1 -= e1;
    }
    else if (e1 >= 20)
    {
        exp2 += inf2;
        exp1 -= e1;
    }
    else if (e1 >= 4)
    {
        exp2 += inf1;
        exp1 -= e1;
    }
    else
    {
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
            exp2 += (29 + 45 + 75);
            break;
        default:
            break;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            exp1 = ceil(exp1 + (D / 200.0));
        else
            exp1 = ceil(exp1 - (D / 100.0));
    }
    checkExp(exp1);
    checkExp(exp2);
    return exp1 + exp2;
}

// Task 2
int checkHP(int &HP)
{
    if (HP > 666)
    {
        HP = 666;
        return HP;
    }

    if (HP < 0)
    {
        HP = 0;
    }
    return HP;
}
float searchS(int exp1)
{
    if (exp1 == 0 || exp1 == 1)
    {
        return 1;
    }

    int i = 0;
    while (true)
    {
        if (i * i <= exp1 && (i + 1) * (i + 1) > exp1)
        {
            if (((i + 1) * (i + 1) - exp1) > (exp1 - i * i))
                return 1;
            else
                return ((float)exp1 / ((i + 1) * (i + 1)) + 80) / 123.0;
        }
        i++;
    }
}

int checkM(int &M1)
{
    if (M1 > 3000)
    {
        M1 = 3000;
        return M1;
    }

    if (M1 < 0)
    {
        M1 = 0;
    }
    return M1;
}
float calculateP2(int &HP1, int &EXP1, int &M1, int E3)
{
    int m1 = M1;
    checkHP(HP1);
    if (E3 % 2 == 0)
    {
        // Food and drink
        if (M1 == 0)
        {
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            checkExp(EXP1);
            return searchS(EXP1);
        }
        if (HP1 < 200)
        {
            HP1 = ceil(HP1 * 1.3);
            M1 -= 150;
            checkM(M1);
            checkHP(HP1);
        }
        else
        {
            HP1 = ceil((float)(HP1 * 1.1));
            M1 -= 70;
            checkM(M1);
            checkHP(HP1);
        }
        if (M1 == 0)
        {
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            checkExp(EXP1);
            return searchS(EXP1);
        }
        // car and hourse
        if (EXP1 < 400)
        {
            EXP1 = ceil(EXP1 * 1.13);
            M1 -= 200;
            checkM(M1);
        }
        else
        {
            EXP1 = ceil(EXP1 * 1.13);
            checkExp(EXP1);
            M1 -= 120;
            checkM(M1);
        }
        if (M1 == 0)
        {
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            checkExp(EXP1);
            return searchS(EXP1);
        }
        // homeless person
        if (EXP1 < 300)
        {
            EXP1 = ceil(EXP1 * 0.9);
            M1 -= 100;
            checkM(M1);
        }
        else
        {
            EXP1 = ceil(EXP1 * 0.9);
            M1 -= 120;
            checkM(M1);
        }
        if (M1 == 0)
        {
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            checkExp(EXP1);
            return searchS(EXP1);
        }
        HP1 = ceil(HP1 * 0.83);
        EXP1 = ceil(EXP1 * 1.17);
        checkExp(EXP1);
    }
    else
    {
        if (M1 != 0)
            while (M1 >= m1 / 2.0)
            {
                // Food and drink
                if (HP1 < 200)
                {
                    HP1 = ceil(HP1 * 1.3);
                    M1 -= 150;
                    checkM(M1);
                    checkHP(HP1);
                }
                else
                {
                    HP1 = ceil((float)(HP1 * 1.1));
                    M1 -= 70;
                    checkM(M1);
                    checkHP(HP1);
                }
                if (M1 < m1 / 2.0)
                    break;
                // car and hourse
                if (EXP1 < 400)
                {
                    EXP1 = ceil(EXP1 * 1.13);
                    M1 -= 200;
                    checkM(M1);
                }
                else
                {
                    EXP1 = ceil(EXP1 * 1.13);
                    checkExp(EXP1);
                    M1 -= 120;
                    checkM(M1);
                }
                if (M1 < m1 / 2.0)
                    break;
                // homeless person
                if (EXP1 < 300)
                {
                    EXP1 = ceil(EXP1 * 0.9);
                    M1 -= 100;
                    checkM(M1);
                }
                else
                {
                    EXP1 = ceil(EXP1 * 0.9);
                    M1 -= 120;
                    checkM(M1);
                }
            }
        HP1 = ceil(HP1 * 0.83);
        EXP1 = ceil(EXP1 * 1.17);
        checkExp(EXP1);
    }
    return searchS(EXP1);
}
int traceLuggage(int &HP1, int &EXP1, int &M1, int E3)
{
    if (E3 > 99 || E3 < 0)
        return -99;
    // TODO: Complete this function
    checkExp(EXP1);
    checkHP(HP1);
    checkM(M1);
    float p1, p2, p3;

    // Probability 1
    p1 = searchS(EXP1);

    // Probability 2
    p2 = calculateP2(HP1, EXP1, M1, E3);

    // Probability 3
    int p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E3 < 10)
    {
        p3 = p[E3] * 0.01;
    }
    else
    {
        p3 = (p[(E3 / 10 + E3 % 10) % 10]) * 0.01;
    }
    // Conclude
    if (p1 == 1 && p2 == 1 && p3 == 1)
    {
        EXP1 = ceil(EXP1 * 0.75);
    }
    else if ((p1 + p2 + p3) / 3 < 0.5)
    {
        HP1 = ceil(HP1 * 0.85);
        EXP1 = ceil(EXP1 * 1.15);
        checkExp(EXP1);
    }
    else
    {
        HP1 = ceil(HP1 * 0.9);
        EXP1 = ceil(EXP1 * 1.2);
        checkExp(EXP1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int findSumij(int &cell)
{
    if (cell < 10)
        return cell;
    else
    {
        cell = cell % 10 + cell / 10;
        return findSumij(cell);
    }
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function

    if (E3 < 0 || E3 > 99)
        return -99;
    checkExp(EXP1);
    checkExp(EXP2);
    checkHP(HP1);
    checkHP(HP2);
    int matrixCar[10][10] = {0};
    int matrixSherlock[10][10] = {0};
    // Calculate TaxiScores
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            matrixCar[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // Calculate SherlockScores

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            matrixSherlock[i][j] = INT_MIN;
            for (int k = 0; k < 10; ++k)
            {
                if (i + j >= 9 && i + j - k < 10)
                {
                    matrixSherlock[i][j] = max(matrixSherlock[i][j], matrixCar[k][i + j - k]);
                }
                if (i + j - 9 + k < 10)
                {
                    matrixSherlock[i][j] = max(matrixSherlock[i][j], matrixCar[9 - k][i + j - 9 + k]);
                }
            }
        }
    }

    // Find a place
    int sumi = 0, sumj = 0;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (matrixCar[i][j] > 2 * E3)
                sumi += 1;
            if (matrixCar[i][j] < -E3)
                sumj += 1;
        }
    }

    findSumij(sumi);
    findSumij(sumj);

    if (abs(matrixCar[sumi][sumj]) > abs(matrixSherlock[sumi][sumj]))
    {
        EXP1 = ceil(float(EXP1 * 0.88));
        HP1 = ceil((float)(HP1 * 0.9));
        EXP2 = ceil((float)(EXP2 * 0.88));
        HP2 = ceil((float)(HP2 * 0.9));
        return matrixCar[sumi][sumj];
    }
    else
    {
        EXP1 = ceil((float)(EXP1 * 1.12));
        HP1 = ceil((float)(HP1 * 1.1));
        EXP2 = ceil((float)(EXP2 * 1.12));
        HP2 = ceil((float)(HP2 * 1.1));
        checkExp(EXP1);
        checkExp(EXP2);
        checkHP(HP1);
        checkHP(HP2);

        return matrixSherlock[sumi][sumj];
    }

    return -1;
}

// Task 4
bool checkSize(const char *s)
{
    return strlen(s) > 7 && strlen(s) < 21;
}

bool findSe(const char *email, const char *s, int &sei)
{
    string account(email);
    size_t atPos = account.find('@');
    if (atPos != string::npos)
    {
        account = account.substr(0, atPos);
        string str(s);
        size_t foundPos = str.find(account);
        if (foundPos != string::npos)
        {
            sei = foundPos;
            return true;
        }
    }
    return false;
}

bool findduplicate(const char *s, int &sci)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            sci = i;
            return true;
        }
        i++;
    }
    return false;
}

bool findspecialCharacters(const char *s)
{
    const char *characters = "@#%$!";
    for (int i = 0; s[i] != '\0'; i++)
    {
        for (int j = 0; characters[j] != '\0'; j++)
        {
            if (s[i] == characters[j])
                return true;
        }
    }
    return false;
}
bool isValid(const char *s, int &isV)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!((s[i] >= '0' && s[i] <= '9') || // Numbers
              (s[i] >= 'A' && s[i] <= 'Z') || // Uppercase letters
              (s[i] >= 'a' && s[i] <= 'z') || // Lowercase letters
              (s[i] == '!') ||
              (s[i] == '@') ||
              (s[i] == '#') ||
              (s[i] == '$') ||
              (s[i] == '%')))
        {
            isV = i;
            return false;
        }
    }
    return true;
}

int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    int sei = 0, sci = 0, isV = 0;
    if (!checkSize(s))
    {
        return strlen(s) < 8 ? -1 : -2;
    }

    if (findSe(email, s, sei))
    {
        return -(300 + sei);
    }

    if (findduplicate(s, sci))
    {
        return -(400 + sci);
    }

    if (!findspecialCharacters(s))
    {
        return -5;
    }
    if (!isValid(s, isV))
        return isV;

    return -10;
}

// Task 5
bool findMaxPassword(const char *arr_pwd1, const char *arr_pwd2)
{
    return strlen(arr_pwd1) > strlen(arr_pwd2);
}

int findDuplicatePassword(const char *arr_pwd[], int size)
{
    int maxCount = 0, maxIndex = -1;

    for (int i = 0; i < size; i++)
    {
        int count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(arr_pwd[i], arr_pwd[j]) == 0)
            {
                count++;
            }
        }

        if ((count > maxCount) || (count == maxCount && findMaxPassword(arr_pwd[i], arr_pwd[maxIndex])))
        {
            maxCount = count;
            maxIndex = i;
        }
    }

    return maxIndex;
}
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    if (num_pwds <= 0 || arr_pwds == nullptr)
    {
        return -1; // Invalid input
    }

    return findDuplicatePassword(arr_pwds, num_pwds);
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////