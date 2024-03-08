#include "study_in_pink1.h"

bool readFile( const string & filename, int & HP1, int & HP2, int & EXP1, int & EXP2, int & M1, int & M2, int & E1, int & E2, int & E3) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else {
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
int firstMeet(int & EXP1, int & EXP2, int E1) {
    EXP2 = min(EXP2, 600);
    EXP2 = max(EXP2, 0);
    EXP1 = min(EXP1, 600);
    EXP1 = max(EXP1, 0);
    if (E1 >= 0 && E1 <= 3)
    {
        switch (E1)
        {
        case 0: EXP2 += 29;
            break;
        case 1: EXP2 += 45;
            break;
        case 2: EXP2 += 75;
            break;
        case 3: EXP2 += 149;
            break;
        }
        EXP2 = min(EXP2, 600);
        EXP2 = max(EXP2, 0);
        int D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0)
            EXP1 = ceil(EXP1 + D / 200.0);
        else
            EXP1 = ceil(EXP1 - D / 100.0);
        EXP1 = min(EXP1, 600);
        EXP1 = max(EXP1, 0);
        return EXP1 + EXP2;
    }
    else if (E1 >= 4 && E1 <= 99)
    {
        if (E1 >= 4 && E1 <= 19) EXP2 = ceil(EXP2 + E1 / 4.0 + 19.0);
        else if (E1 >= 20 && E1 <= 49) EXP2 = ceil(EXP2 + E1 / 9.0 + 21.0);
        else if (E1 >= 50 && E1 <= 65) EXP2 = ceil(EXP2 + E1 / 16.0 + 17.0);
        else if (E1 >= 66 && E1 <= 79)
        {
            EXP2 = ceil(EXP2 + E1 / 4.0 + 19.0);
            EXP2 = min(EXP2, 600);
            EXP2 = max(EXP2, 0);
            if (EXP2 > 200) EXP2 = ceil(EXP2 + E1 / 9.0 + 21.0);
            EXP2 = min(EXP2, 600);
            EXP2 = max(EXP2, 0);
        }
        else if (E1 >= 80 && E1 <= 99)
        {
            EXP2 = ceil(EXP2 + E1 / 4.0 + 19.0);
            EXP2 = min(EXP2, 600);
            EXP2 = max(EXP2, 0);
            EXP2 = ceil(EXP2 + E1 / 9.0 + 21.0);
            EXP2 = min(EXP2, 600);
            EXP2 = max(EXP2, 0);
            if (EXP2 > 400)
            {
                EXP2 = ceil(EXP2 + E1 / 16.0 + 17.0);
                EXP2 = min(EXP2, 600);
                EXP2 = max(EXP2, 0);
                EXP2 = ceil(EXP2 * 1.15);
                EXP2 = min(EXP2, 600);
                EXP2 = max(EXP2, 0);
            }
        }
        EXP1 -= E1;
        EXP2 = min(EXP2, 600);
        EXP2 = max(EXP2, 0);
        EXP1 = min(EXP1, 600);
        EXP1 = max(EXP1, 0);
        return EXP1 + EXP2;
    }
    return -99;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 < 0 || E2>99) return -99;
    double p1, p2, p3;
    double base = sqrt(EXP1);
    double s1 = pow(base, 2);
    double s2 = pow(base + 1, 2);
    if ((EXP1 - s1) < (s2 - EXP1)) p1 = 1.00; else p1 = (((EXP1 / s2) + 80) / 123.0);

    double HM = M1 / 2;
    if ((E2 % 2) == 1) {
        while (M1 >= HM) {
            if (M1 == 0) break;
            if (HP1 < 200) {
                HP1 = ceil( HP1 + 0.3 * HP1 - 1e-5);
                M1 = M1 - 150;

            }
            else {
                HP1 =ceil( HP1 + 0.1 * HP1 - 1e-5);
                M1 -= 70;
            }
            HP1 = min(HP1, 666);
            HP1 = max(HP1, 0);

            M1 = min(M1, 3000);
            M1 = max(M1, 0);

            if (M1 < HM) break;

            if (EXP1 < 400) M1 -= 200; else M1 -= 120;
            M1 = min(M1, 3000);
            M1 = max(M1, 0);

            EXP1 = ceil(EXP1 * 1.13- 1e-5);

            EXP1 = min(EXP1, 600);
            EXP1 = max(EXP1, 0);

            if (M1 < HM) break;

            if (EXP1 < 300) M1 -= 100; else M1 -= 120;
            M1 = min(M1, 3000);
            M1 = max(M1, 0);

            EXP1 = ceil( EXP1 * 0.9);
            EXP1 = min(EXP1, 600);
            EXP1 = max(EXP1, 0);
        }
        HP1 = ceil( HP1 * 0.83);
        HP1 = min(HP1, 666);
        HP1 = max(HP1, 0);
        EXP1 =ceil( EXP1 * 1.17);
        EXP1 = min(EXP1, 600);
        EXP1 = max(EXP1, 0);
    }
    else
    {
        if (M1 == 0) goto skipAction;

        if (HP1 < 200)
        {
            HP1 = ceil( HP1 + 0.3 * HP1 -1e-5);
            M1 = M1 - 150;
        }
        else
        {
            HP1 =ceil( HP1 + 0.1 * HP1 -1e-5);
            M1 -= 70;
        }
        HP1 = min(HP1, 666);
        HP1 = max(HP1, 0);

        M1 = min(M1, 3000);
        M1 = max(M1, 0);
        if (M1 == 0) goto skipAction;

        if (EXP1 < 400) M1 -= 200; else M1 -= 120;
        M1 = min(M1, 3000);
        M1 = max(M1, 0);

        EXP1 = ceil(EXP1 * 1.13 - 1e-5);

        EXP1 = min(EXP1, 600);
        EXP1 = max(EXP1, 0);
        if (M1 == 0) goto skipAction;

        if (EXP1 < 300) M1 -= 100; else M1 -= 120;
        M1 = min(M1, 3000);
        M1 = max(M1, 0);

        EXP1 = ceil( EXP1 * 0.9 - 1e-5);

        EXP1 = min(EXP1, 600);
        EXP1 = max(EXP1, 0);

    skipAction:
        
            HP1 = ceil( HP1 * 0.83 - 1e-5);
            HP1 = min(HP1, 666);
            HP1 = max(HP1, 0);
            EXP1 = ceil(EXP1 * 1.17 - 1e-5);
            EXP1 = min(EXP1, 600);
            EXP1 = max(EXP1, 0);
        
    }

    base = sqrt(EXP1);
    s1 = pow(base, 2);
    s2 = pow(base + 1, 2);
    if ((EXP1 - s1) < (s2 - EXP1)) p2 = 1.00; else p2 = (((EXP1 / s2) + 80) / 123.0);

    int arr[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2 < 10) p3 = arr[E2]; else 
    {
        int digit = floor(E2 / 10) + (E2 % 10);
        if (digit < 10) p3 = arr[digit]; else p3 = arr[digit % 10];
    }
    p3 = p3 / 100.0;

    double p = (p1 + p2 + p3) / 3.0;

    if (p1 == 1 && p2==1 && p3==1) EXP1 = ceil(EXP1 * 0.75 - 1e-5);
    else if (p < 1 && p >= 0.5) {
        HP1 = ceil(HP1 * 0.9 - 1e-5);
        EXP1 = ceil(EXP1 * 1.2 - 1e-5);
    }
    else if (p<0.5) {
        HP1 = ceil(HP1 * 0.85 - 1e-5);
        EXP1 = ceil(EXP1 * 1.15 - 1e-5);
    }

    return HP1 + EXP1 + M1;
}

int roundUp(double x, double y)
{
    return (x + y - 1) / y;
}
// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    int arr1[10][10], arr2[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            arr1[i][j] = ((E3 * j) + (i * 2)) * (i - j);
    int posX = 0, posY = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr1[i][j] > E3 * 2) ++posX;
            if (arr1[i][j] < -E3) ++posY;
            int x = i, y = j;
            arr2[i][j] = arr1[i][j];
            while ((x + 1 < 10) && (y + 1 < 10))
            {
                arr2[i][j] = max(arr2[i][j], arr1[x + 1][y + 1]);
                ++x;
                ++y;
            }
            x = i, y = j;
            while ((x - 1 >= 0) && (y + 1 < 10))
            {
                arr2[i][j] = max(arr2[i][j], arr1[x - 1][y + 1]);
                --x;
                ++y;
            }
            x = i, y = j;
            while ((x - 1 >= 0) && (y - 1 >= 0))
            {
                arr2[i][j] = max(arr2[i][j], arr1[x - 1][y - 1]);
                --x;
                --y;
            }
            x = i, y = j;
            while ((x + 1 < 10) && (y - 1 >= 0))
            {
                arr2[i][j] = max(arr2[i][j], arr1[x + 1][y - 1]);
                ++x;
                --y;
            }
            if (arr2[i][j] < 0) arr2[i][j] = -arr2[i][j];
        }
    }
    while (posX >= 10)
    {
        posX = (posX / 10) + (posX % 10);
    }
    while (posY >= 10)
    {
        posY = (posY / 10) + (posY % 10);
    }
    if (abs(arr1[posX][posY]) > arr2[posX][posY])
    {
        EXP1 = roundUp(EXP1 * 88, 100);
        HP1 = roundUp(HP1 * 90, 100);
        EXP2 = roundUp(EXP2 * 88, 100);
        HP2 = roundUp(HP2 * 90, 100);

        EXP1 = min(EXP1, 600);
        EXP1 = max(EXP1, 0);
        HP1 = min(HP1, 666);
        HP1 = max(HP1, 0);

        EXP2 = min(EXP2, 600);
        EXP2 = max(EXP2, 0);
        HP2 = min(HP2, 666);
        HP2 = max(HP2, 0);

        return arr1[posX][posY];
    }
    EXP1 = roundUp(EXP1 * 112, 100);
    HP1 = roundUp(HP1 * 110, 100);
    EXP2 = roundUp(EXP2 * 112, 100);
    HP2 = roundUp(HP2 * 110, 100);

    EXP1 = min(EXP1, 600);
    EXP1 = max(EXP1, 0);
    HP1 = min(HP1, 666);
    HP1 = max(HP1, 0);

    EXP2 = min(EXP2, 600);
    EXP2 = max(EXP2, 0);
    HP2 = min(HP2, 666);
    HP2 = max(HP2, 0);
    return arr2[posX][posY];
}


// Task 4
int checkPassword(const char * s, const char * email) {
        int len = strlen(s);
        if (len < 8) return -1;
        if (len > 20) return -2;
        char se[101];
        int top = 0;
        while (email[top] != '@')
        {
            se[top] = email[top];
            ++top;
        }
        for (int i = 0; i + top - 1 < len; i++)
        {
            bool haveSe = 1;
            for (int j = i; j <= i + top - 1; j++)
            {
                if (se[j - i] != s[j])
                {
                    haveSe = 0;
                    break;
                }
            }
            if (haveSe == 1)
                return -(300 + i);
        }
        for (int i = 0; i + 2 < len; i++)
        {
            if ((s[i] == s[i + 1]) && (s[i + 1] == s[i + 2]))
                return -(400 + i);
        }
        bool haveSpec = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            {
                haveSpec = 1;
                continue;
            }
            if (('0' <= s[i]) && (s[i] <= '9')) continue;
            if (('a' <= s[i]) && (s[i] <= 'z')) continue;
            if (('A' <= s[i]) && (s[i] <= 'Z')) continue;
            return i;
        }
        if (haveSpec == 0) return -5;

        return -10;
    }

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxCount = 0;
    int pwdsPosition = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        int count = 0;
        int curLen = strlen(arr_pwds[i]);
        for (int j = i + 1; j < num_pwds; j++)
        {
            int len = strlen(arr_pwds[j]);
            bool isEqual = (len == curLen);
            for (int t = 0; (t < len) && (isEqual); t++)
                isEqual &= (arr_pwds[i][t] == arr_pwds[j][t]);
            if (isEqual)
                ++count;
        }
        if (count > maxCount)
        {
            maxCount = count;
            pwdsPosition = i;
        }
        else if (count == maxCount)
        {
            if (strlen(arr_pwds[i]) > strlen(arr_pwds[pwdsPosition]))
                pwdsPosition = i;
        }
    }
    return pwdsPosition;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
