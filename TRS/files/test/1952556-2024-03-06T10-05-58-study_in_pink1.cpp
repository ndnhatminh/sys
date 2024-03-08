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
int sochinhphuong(int n)
{
    int lowerBound = sqrt(n);
    int upperBound = lowerBound + 1;

    int lowerSquare = lowerBound * lowerBound;
    int upperSquare = upperBound * upperBound;

    int closestSquare;
    if (abs(n - lowerSquare) < abs(n - upperSquare))
    {
        closestSquare = lowerSquare;
    }
    else
    {
        closestSquare = upperSquare;
    }
    return closestSquare;
}
void checkHP(int &hp)
{
    if (hp > 666)
    {
        hp = 666;
    }
    else if (hp < 0)
    {
        hp = 0;
    }
}
void checkExp(int &exp)
{
    if (exp > 600)
    {
        exp = 600;
    }
    else if (exp < 0)
    {
        exp = 0;
    }
}
void checkM(int &m)
{
    if (m > 3000)
    {
        m = 3000;
    }
    else if (m < 0)
    {
        m = 0;
    }
}
int checkE(int &e)
{
    if (e < 0 || e > 99)
    {
        return -99;
    }
    return 0;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    checkExp(exp1);
    checkExp(exp2);
    checkE(e1);
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
        else
        {
            exp2 = exp2 + 29 + 45 + 75;
        }
        checkExp(exp2);
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 = exp1 + round(D / 200);
        }
        else
        {
            exp1 = exp1 - round(D / 100);
        }
        checkExp(exp1);
    }
    else if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 = exp2 + ceil((double)e1 / 4) + 19;
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 = exp2 + ceil((double)e1 / 9) + 21;
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 = exp2 + ceil((double)e1 / 16) + 17;
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 = exp2 + ceil((e1 / 4 + 19));
            if (exp2 > 200)
            {
                exp2 = exp2 + ceil((double)e1 / 9) + 21;
            }
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 = exp2 + ceil((double)e1 / 4) + 19;
            exp2 = exp2 + ceil((double)e1 / 9) + 21;
            if (exp2 > 400)
            {
                exp2 = exp2 + ceil((double)e1 / 16) + 17;
                exp2 = exp2 + ceil((double)exp2 * 0.15);
            }
        }

        checkExp(exp2);
        exp1 = exp1 - e1;
        checkExp(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    checkHP(HP1);
    checkExp(EXP1);
    checkM(M1);
    checkE(E2);

    // CON DUONG 1
    int S1 = sochinhphuong(EXP1);
    double P1 = 0;
    if (EXP1 >= S1)
    {
        P1 = 1;
    }
    else
    {
        P1 = (double)(EXP1 / S1 + 80) / 123;
    }

    // CON DUONG 2
    int fm1 = M1;
    int chitra = 0;
    if (E2 % 2 == 1)
    {
    ev1:
        if (HP1 < 200)
        {
            M1 -= 150;
            chitra += 150;
            HP1 = ceil((double)HP1 * 1.3);
            checkHP(HP1);
            checkM(M1);
        }
        else
        {
            M1 -= 70;
            chitra += 70;
            HP1 = ceil((double)HP1 * 1.1);
            checkHP(HP1);
            checkM(M1);
        }
        if (chitra > fm1 / 2)
        {
            goto cuoiduong2;
        }

    ev2:
        if (EXP1 < 400)
        {
            M1 -= 200;
            checkM(M1);
            chitra += 200;
        }
        else
        {
            M1 -= 120;
            checkM(M1);
            chitra += 120;
        }
        EXP1 = ceil((double)EXP1 * 1.13);
        checkExp(EXP1);
        if (chitra > fm1 / 2)
        {
            goto cuoiduong2;
        }

    ev3:
        if (EXP1 < 300)
        {
            M1 -= 100;
            chitra += 100;
        }
        else
        {
            M1 -= 120;
            chitra += 120;
        }
        checkM(M1);
        EXP1 = ceil((double)EXP1 * 0.9);
        checkExp(EXP1);

        if (chitra > fm1 / 2)
        {
            goto cuoiduong2;
        }
        else
        {
            goto ev1;
        }
    }
    else
    {

        if (HP1 < 200)
        {
            M1 -= 150;
            HP1 = ceil((double)HP1 * 1.3);
            checkHP(HP1);
            checkM(M1);
        }
        else
        {
            M1 -= 70;
            HP1 = ceil((double)HP1 * 1.1);
            checkHP(HP1);
            checkM(M1);
        }
        if (M1 == 0)
        {
            goto cuoiduong2;
        }

        if (EXP1 < 400)
        {
            M1 -= 200;
            checkM(M1);
        }
        else
        {
            M1 -= 120;
            checkM(M1);
        }
        EXP1 = ceil((double)EXP1 * 1.13);
        checkExp(EXP1);
        if (M1 == 0)
        {
            goto cuoiduong2;
        }

        if (EXP1 < 300)
        {
            M1 -= 100;
        }
        else
        {
            M1 -= 120;
        }
        checkM(M1);
        EXP1 = ceil((double)EXP1 * 0.9);
        checkExp(EXP1);
        if (M1 == 0)
        {
            goto cuoiduong2;
        }
    }
cuoiduong2:
    HP1 = ceil((double)HP1 * 0.83);
    EXP1 = ceil((double)EXP1 * 1.17);
    checkHP(HP1);
    checkExp(EXP1);
    int S2 = sochinhphuong(EXP1);
    double P2 = 0;
    if (EXP1 >= S2)
    {
        P2 = 1;
    }
    else
    {
        P2 = (double)(EXP1 / S2 + 80) / 123;
    }

    // CON DUONG 3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P3;
    if (E2 >= 0 && E2 < 10)
    {
        P3 = P[E2] / 100;
    }
    else
    {
        int k = E2;
        int hangchuc = E2 / 10;
        int hangdv = E2 % 10;
        int tong = hangchuc + hangdv;
        int i = tong % 10;
        P3 = (double)P[i] / 100;
    }

    if (P1 == 1 && P2 == 1 && P3 == 1)
    {
        EXP1 = ceil((double)EXP1 * 0.75);
        checkExp(EXP1);
    }
    else
    {
        double Pfinal = (double)(P1 + P2 + P3) / 3;
        if (Pfinal < 0.5)
        {
            HP1 = ceil((double)HP1 * 0.85);
            EXP1 = ceil((double)EXP1 * 1.15);
        }
        else
        {
            HP1 = ceil((double)HP1 * 0.9);
            EXP1 = ceil((double)EXP1 * 1.2);
        }
        checkExp(EXP1);
        checkHP(HP1);
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    int taxiMap[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            taxiMap[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // tim diem gap nhau
    int i = 0, j = 0;
    int demlon = 0, demnho = 0;
    for (int h = 0; h < 10; h++)
    {
        for (int c = 0; c < 10; c++)
        {
            if (taxiMap[h][c] > E3 * 2)
            {
                demlon++;
            }
            else if (taxiMap[h][c] < -E3)
            {
                demnho++;
            }
        }
    }
    while (demlon >= 10)
    {
        int hangChuc = demlon / 10;
        int donVi = demlon % 10;
        int sum = hangChuc + donVi;
        demlon = sum;
    }
    while (demnho >= 10)
    {
        int hangChuc = demnho / 10;
        int donVi = demnho % 10;
        int sum = hangChuc + donVi;
        demnho = sum;
    }
    i = demlon;
    j = demnho;

    int cach = abs(i - j);
    int taxiScore = taxiMap[i][j];
    int max_left_diagonal = taxiMap[i][j];
    for (int m = i - 1, n = 9; m < 10 && n >= 0; m++, n--)
    {
        if (taxiMap[m][n] > max_left_diagonal)
        {
            max_left_diagonal = taxiMap[m][n];
        }
    }
    int max_right_diagonal = taxiMap[i][j];
    for (int i = 0, j = cach; i < 10 && j < 10; i++, j++)
    {
        if (taxiMap[i][j] > max_right_diagonal)
        {
            max_right_diagonal = taxiMap[i][j];
        }
    }
    int maxsw = 0;
    if (max_left_diagonal > max_right_diagonal)
    {
        maxsw = max_left_diagonal;
    }
    else
    {
        maxsw = max_right_diagonal;
    }

    if (abs(taxiScore) > maxsw)
    {
        HP1 -= 0.1 * HP1;
        EXP1 -= 0.12 * EXP1;
        HP2 -= 0.1 * HP2;
        EXP2 -= 0.12 * EXP2;
        checkHP(HP1);
        checkHP(HP2);
        checkExp(EXP1);
        checkExp(EXP2);
        return taxiScore;
    }
    else
    {
        HP1 += 0.1 * HP1;
        EXP1 += 0.12 * EXP1;
        HP2 += 0.1 * HP2;
        EXP2 += 0.12 * EXP2;
        checkHP(HP1);
        checkHP(HP2);
        checkExp(EXP1);
        checkExp(EXP2);
        return maxsw;
    }
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    string se(email);
    se.erase(se.find('@'));

    int len = strlen(s);
    if (len < 8)
    {
        return -1;
    }
    if (len > 20)
    {
        return -2;
    }

    bool has_special_char = false;
    for (int i = 0; i < len; i++)
    {
        if (isalnum(s[i]) || strchr("@#%$!", s[i]))
        {
            has_special_char = true;
            break;
        }
    }
    if (!has_special_char)
    {
        return -5;
    }

    if (strstr(s, se.c_str()))
    {
        return -(300 + strstr(s, se.c_str()) - s);
    }

    for (int i = 0; i < len - 2; i++)
    {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
        {
            return -(400 + i);
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int max_count = 0, max_index = -1;
    int len[num_pwds], count[num_pwds];

    for (int i = 0; i < num_pwds; i++)
    {
        len[i] = strlen(arr_pwds[i]);
        count[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                count[j]++;
                break;
            }
        }
    }

    for (int i = 0; i < num_pwds; i++)
    {
        if (count[i] >= max_count)
        {
            if (count[i] > max_count || (count[i] == max_count && len[i] > len[max_index]))
            {
                max_count = count[i];
                max_index = i;
            }
        }
    }

    return max_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////