#include "study_in_pink1.h"

bool readFile(
    const string& filename,
    int& HP1,
    int& HP2,
    int& EXP1,
    int& EXP2,
    int& M1,
    int& M2,
    int& E1,
    int& E2,
    int& E3
) {
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
int roundUp(int max, float x) {
    int res = x * 1.0 + 0.999;

    if (res > max) return max;
    if (res < 0) return 0;
    return res;
}
bool isSquare(int a) //Xet xem a la so chinh phuong hay khong
{
    int can = sqrt(a);
    if (can * can == a) return 1;
    else return 0;
}
int Square(int a) //Tim so chinh phuong gan a nhat, khong thay doi a
{
    int S;
    if (isSquare(a) == 1)
    {
        S = a;
    }
    else
    {
        float can = sqrt(a);
        int upper = ceil(can) * ceil(can);
        int lower = floor(can) * floor(can);
        S = (upper - a) > (a - lower) ? lower : upper;
    }
    return S;
}
//ham nay ko lam thay doi cac tham so
double conduong1(int& HP1, int& EXP1, int& M1, int E2)
{
    int S = Square(EXP1);
    double P1;
    if (EXP1 >= S)
    {
        return P1 = 1;
    }
    else
    {
        return P1 = (double)(EXP1 / S + 80) / 123;
    }
}
void sk1(int& HP1, int& EXP1, int& M1, int E2)
{
    if (HP1 < 200)
    {
        M1 = roundUp(3000, M1 - 150);
        if (M1 == 0)
        {
            HP1 = roundUp(666, (float)HP1 * 1.3);
            return;
        }
        HP1 = roundUp(666, (float)HP1 * 1.3);
        return;
    }
    else
    {
        M1 = roundUp(3000, M1 - 70);
        if (M1 == 0)
        {
            HP1 = roundUp(666, (float)HP1 * 1.1);
            return;
        }
        HP1 = roundUp(666, (float)HP1 * 1.1);
        return;
    }
}
void sk2(int& HP1, int& EXP1, int& M1, int E2)
{
    if (EXP1 < 400)
    {
        M1 = roundUp(3000, M1 - 200);
        if (M1 == 0)
        {
            EXP1 = roundUp(600, (float)EXP1 * 1.13);
            return;
        }
        EXP1 = roundUp(600, (float)EXP1 * 1.13);
        return;
    }
    else
    {
        M1 = roundUp(3000, M1 - 120);
        if (M1 == 0)
        {
            EXP1 = roundUp(600, (float)EXP1 * 1.13);
            return;
        }
        EXP1 = roundUp(600, (float)EXP1 * 1.13);
        return;
    }
}
void sk3(int& HP1, int& EXP1, int& M1, int E2)
{
    if (EXP1 < 300)
    {
        M1 = roundUp(3000, M1 - 100);
        if (M1 == 0)
        {
            EXP1 = roundUp(600, (float)EXP1 * 0.9);
            return;
        }
        EXP1 = roundUp(600, (float)EXP1 * 0.9);
        return;
    }
    else
    {
        M1 = roundUp(3000, M1 - 120);
        if (M1 == 0)
        {
            EXP1 = roundUp(600, (float)EXP1 * 0.9);
            return;
        }
        EXP1 = roundUp(600, (float)EXP1 * 0.9);
        return;
    }
}
void conduong2(int& HP1, int& EXP1, int& M1, int E2)
{
    float M = (float)M1 / 2;
    int Mp = M1;
    if (M1 == 0)
    {
        HP1 = roundUp(666, (float)HP1 * 0.83);
        EXP1 = roundUp(600, (float)EXP1 * 1.17);
        return;
    }
    else
    {
        if (E2 % 2 == 0)
        {
            sk1(HP1, EXP1, M1, E2);
            if (M1 == 0)
            {
                EXP1 = roundUp(600, (float)EXP1 * 1.17);
                HP1 = roundUp(666, (float)HP1 * 0.83);
                return;
}
            sk2(HP1, EXP1, M1, E2);
            if (M1 == 0)
            {
                EXP1 = roundUp(600, (float)EXP1 * 1.17);
                HP1 = roundUp(666, (float)HP1 * 0.83);
                return;
            }
            sk3(HP1, EXP1, M1, E2);
            if (M1 == 0)
            {
                EXP1 = roundUp(600, (float)EXP1 * 1.17);
                HP1 = roundUp(666, (float)HP1 * 0.83);
                return;
            }
            EXP1 = roundUp(600, (float)EXP1 * 1.17);
            HP1 = roundUp(666, (float)HP1 * 0.83);
            return;
        }
        else
        {
            float Sum = 0;
            while (1)
            {
                sk1(HP1, EXP1, M1, E2);
                if ((Sum = Mp - M1) > M)
                {
                    EXP1 = roundUp(600, (float)EXP1 * 1.17);
                    HP1 = roundUp(666, (float)HP1 * 0.83);
                    return;
                }
                sk2(HP1, EXP1, M1, E2);
                if ((Sum = Mp - M1) > M)
                {
                    EXP1 = roundUp(600, (float)EXP1 * 1.17);
                    HP1 = roundUp(666, (float)HP1 * 0.83);
                    return;
                }
                sk3(HP1, EXP1, M1, E2);
                if ((Sum = Mp - M1) > M)
                {
                    EXP1 = roundUp(600, (float)EXP1 * 1.17);
                    HP1 = roundUp(666, (float)HP1 * 0.83);
                    return;
                }
            }
        }
    }
}
int firstMeet(int& exp1, int& exp2, int e1)
{
    // TODO: Complete this function
    if ((e1 < 0) || (e1 > 99))
    {
        return -99;
    }
    else if ((e1 >= 0) && (e1 <= 3))
    {
        switch (e1)
        {
        case 0:
            exp2 = exp2 + 29;
            if (exp2 > 600)
            {
                exp2 = 600;
            }
            break;
        case 1:
            exp2 = exp2 + 45;
            if (exp2 > 600)
            {
                exp2 = 600;
            }
            break;
        case 2:
            exp2 = exp2 + 75;
            if (exp2 > 600)
            {
                exp2 = 600;
            }
            break;
        case 3:
            exp2 = exp2 + 29 + 45 + 75;
            if (exp2 > 600)
            {
                exp2 = 600;
            }
            break;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 = roundUp(600, (float)exp1 + (float)D / 200);
        }
        else
        {
            exp1 = roundUp(600, (float)exp1 - (float)D / 100);
        }
    }
    else if ((e1 >= 4) && (e1 <= 99))
    {
        if ((e1 >= 4) && (e1 <= 19))
        {
            exp2 = roundUp(600, (float)exp2 + (float)e1 / 4 + 19);
        }
        else if ((e1 >= 20) && (e1 <= 49))
        {
            exp2 = roundUp(600, (float)exp2 + (float)e1 / 9 + 21);
}
        else if ((e1 >= 50) && (e1 <= 65))
        {
            exp2 = roundUp(600, (float)exp2 + (float)e1 / 16 + 17);
        }
else if ((e1 >= 66) && (e1 <= 79))
        {
            exp2 = roundUp(600, (float)exp2 + (float)e1 / 4 + 19);
            if (exp2 > 200)
            {
                exp2 = roundUp(600, (float)exp2 + (float)e1 / 9 + 21);
            }
        }
        else
        {
            exp2 = roundUp(600, (float)exp2 + (float)e1 / 4 + 19);
            exp2 = roundUp(600, (float)exp2 + (float)e1 / 9 + 21);
            if (exp2 > 400)
            {
                exp2 = roundUp(600, (float)exp2 + (float)e1 / 16 + 17);
                exp2 = roundUp(600, (float)exp2 * 1.15);
            }
        }
        exp1 = exp1 - e1;
    }
    if (exp1 < 0)
    {
        exp1 = 0;
    }
    return exp1 + exp2;
}



int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 < 0 || E2 > 99) return -99;
    //Conduong1
    double P1 = conduong1(HP1, EXP1, M1, E2);
    //Conduong2
    conduong2(HP1, EXP1, M1, E2);
    double P2 = conduong1(HP1, EXP1, M1, E2);
    //Conduong3
    double P3 = 0;
    int p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 >= 0 && E2 <= 9) 
    { 
        P3 = p[E2];
    }
    else
    {
        int L = E2 % 10 + E2 / 10;
        int i = L % 10;
        P3 = p[i];
    }
    
    if (P1 == 1 && P2 == 1 && P3 == 100)
    {
        EXP1 = roundUp(600, (float)EXP1 * 0.75);
    }
    else
    {
        double P = (P1 + P2 + (double)P3 / 100) / 3;
        if (P < 0.5)
        {
            HP1 = roundUp(666, (float)HP1 * 0.85);
            EXP1 = roundUp(600, (float)EXP1 * 1.15);
        }
        else
        {
            HP1 = roundUp(666, (float)HP1 * 0.9);
            EXP1 = roundUp(600, (float)EXP1 * 1.2);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    int a[10][10] = { 0 };
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int x1[9], x2[9], x[19];
    x[0] = 0;
    //tinh x1
    for (int i = 1; i <= 9; i++)
    {
        int idai = 0, idaj = i;
        x1[i - 1] = a[0][i];
        for (int t = 0; t < 10 - i; ++t) 
            x1[i - 1] = max(x1[i - 1], a[idai + t][idaj + t]);
    }
    //tinh x2
    for (int j = 1; j <= 9; j++)
    {
        int idai = j, idaj = 0;
        x2[j - 1] = a[j][0];
        for (int t = 0; t < 10 - j; t++) 
            x2[j - 1] = max(x1[j - 1], a[idai + t][idaj + t]);
    }
    for (int i = 1; i < 10; i++)
    {
        x[i] = x1[i - 1];
    }
    for (int i = 10; i < 19; i++)
    {
        x[i] = x2[i - 10];
    }
    //tinh y
    int y1[9], y2[9], y[19];
    y[0] = a[0][9];
    for (int i = 0; i < 10; i++)
    {
        y[0] = max(y[0], a[i][9 - i]);
    }
    //tinh y1
    for (int i = 8; i >= 0; i--)
    {
        int idai = 0, idaj = i;
        y1[8 - i] = a[0][i];
        for (int t = 1; t < i + 1; t++)
            y1[8 - i] = max(y1[8 - i], a[idai + t][idaj - t]);
    }
    //tinh y2
    for (int j = 1; j <= 9; j++)
    {
        int idai = j, idaj = 9;
        y2[j - 1] = a[j][9];
        for (int t = 1; t < 10 - j; t++)
            y2[j - 1] = max(y2[j - 1], a[idai + t][idaj - t]);
    }
    for (int i = 1; i < 10; i++)
    {
        y[i] = y1[i - 1];
    }
    for (int i = 10; i < 19; i++)
    {
        y[i] = y2[i - 10];
    }
    int cnti = 0, cntj = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (a[i][j] > E3 * 2)   cnti++;
            if (a[i][j] < -E3) cntj++;
        }
    }
    int b[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (a[i][j] < 0) {
                int p1 = x1[abs(i - j - 1)];
                int p2;
                if (i + j <= 8)
                {
                    p2 = y1[8 - j];
                }
                else if (i + j == 9)
                {
                    p2 = y[0];
                }
                else
                {
                    p2 = y2[i + j - 10];
                }
                b[i][j] = max(p1, p2);
            }
            else if (a[i][j] == 0)
            {
                int p1 = 0;
                int p2;
                if (i + j <= 8)
                {
                    p2 = y1[8 - j];
                }
                else if (i + j == 9)
                {
                    p2 = y[0];
                }
                else
                {
                    p2 = y2[i + j - 10];
                }
                b[i][j] = max(p1, p2);
            }
            else
            {
                int p1 = x2[abs(i - j - 1)];
                int p2;
                if (i + j <= 8)
                {
p2 = y1[8 - j];
                }
                else if (i + j == 9)
                {
                    p2 = y[0];
                }
                else
                {
                    p2 = y2[i + j - 10];
                }
                b[i][j] = max(p1, p2);
            }
        }
    }
    do
    {
        cnti = cnti / 10 + cnti % 10;
    } while (cnti >= 10);
    do
    {
        cntj = cntj / 10 + cntj % 10;
    } while (cntj >= 10);
    int score = 0;
    if (abs(a[cnti][cntj]) > b[cnti][cntj])
    {
        EXP1 = roundUp(600, EXP1 * 1.0 * 0.88);
        HP1 = roundUp(600, HP1 * 1.0 * 0.9);
        EXP2 = roundUp(600, EXP2 * 1.0 * 0.88);
        HP2 = roundUp(600, HP2 * 1.0 * 0.9);

        score = a[cnti][cntj];
    }
    else
    {
        EXP1 = roundUp(600, EXP1 * 1.0 * 1.12);
        HP1 = roundUp(600, HP1 * 1.0 * 1.1);
        EXP2 = roundUp(600, EXP2 * 1.0 * 1.12);
        HP2 = roundUp(600, HP2 * 1.0 * 1.1);
        score = b[cnti][cntj];
    }
    
    return score;
}

bool isSpeacialCharacter(char c) {
    return (c == '@' || c == '#' || c == '%' || c == '$' || c == '!');
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    string password(s);

    if (password.length() < 8) return -1;
    if (password.length() > 20) return -2;

    string se;
    for (int i = 0; email[i] && email[i] != '@'; i++) {
        se += email[i];
    }

    size_t sei = password.find(se);
    if (sei != string::npos) {
        return -(300 + static_cast<int>(sei));
    }

    for (int i = 0; s[i + 2]; i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) return -(400 + i);
    }

    bool hasSpecialCharacter = false;
    for (int i = 0; s[i]; i++) {
        if (isSpeacialCharacter(s[i])) {
            hasSpecialCharacter = true;
            break;
        }
    }
    if (!hasSpecialCharacter) return -5;

    for (int i = 0; s[i]; i++) {
        if ((s[i] < '0' || s[i] > '9') && (s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z') && !isSpeacialCharacter(s[i])) return i;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxCount = INT_MIN;
    int maxIndex = 0;
    for (int i = 0; i < num_pwds; i++) {
        int countAppear = 0;
        int firstIndex = -1;

        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                countAppear++;
                if (firstIndex == -1) firstIndex = j;
            }
        }

        if (countAppear > maxCount || (countAppear == maxCount && strlen(arr_pwds[firstIndex]) > strlen(arr_pwds[maxIndex]))) {
            maxCount = countAppear;
            maxIndex = firstIndex;
        }
    }

    return maxIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
