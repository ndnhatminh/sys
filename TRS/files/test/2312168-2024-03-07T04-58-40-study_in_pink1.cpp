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
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
        return -99;
    if (exp1 < 0)
        exp1 = 0;
    else if (exp1 > 600)
        exp1 = 600;
    if (exp2 < 0)
        exp2 = 0;
    else if (exp2 > 600)
        exp2 = 600;
    if (e1 >= 0 && e1 < 4)
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
            exp2 += 149;
            break;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 = ceil(exp1 + 1.0 * D / 200);
        }
        else if (D % 2 != 0)
        {
            exp1 = ceil(exp1 - 1.0 * D / 100);
        }
    }
    if (e1 >= 4 && e1 < 100)
    {
        if (e1 <= 19)
            exp2 += ceil(1.0 * e1 / 4 + 19);
        else if (e1 <= 49)
            exp2 += ceil(1.0 * e1 / 9 + 21);
        else if (e1 <= 65)
            exp2 += ceil(1.0 * e1 / 16 + 17);
        else if (e1 <= 79)
        {
            exp2 += ceil(1.0 * e1 / 4 + 19);
            if (exp2 > 200)
                exp2 += ceil(1.0 * e1 / 9 + 21);
        }
        else if (e1 <= 99)
        {
            exp2 += ceil(1.0 * e1 / 9 + 21) + ceil(1.0 * e1 / 4 + 19);
            if (exp2 > 400)
            {
                exp2 += ceil(1.0 * e1 / 16 + 17);
                exp2 += ceil(exp2 * 0.15);
            }
        }
        exp1 -= e1;
    }
    if (exp1 < 0)
        exp1 = 0;
    else if (exp1 > 600)
        exp1 = 600;
    if (exp2 < 0)
        exp2 = 0;
    else if (exp2 > 600)
        exp2 = 600;
    return exp1 + exp2;
}
// Task 2
double xacxuat(int EXP)
{
    double P = 1;
    int can = sqrt(EXP);
    if (EXP > can * can + can)
    {
        can++;
        P = (1.0 * EXP / (can * can) + 80) / 123;
    }
    return P;
}
void kiemtra(int &HP1, int &EXP1, int &M1)
{
    if (EXP1 < 0)
        EXP1 = 0;
    if (EXP1 > 600)
        EXP1 = 600;
    if (HP1 < 0)
        HP1 = 0;
    if (HP1 > 666)
        HP1 = 666;
    if (M1 < 0)
        M1 = 0;
    if (M1 > 3000)
        M1 = 3000;
}
int traceLuggage(int &HP1, int &EXP1, int &M1, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;
    kiemtra(HP1, EXP1, M1);
    double P1 = xacxuat(EXP1);
    int money = 0;
    double tienchi = 0.5 * M1;
    if (E3 % 2 != 0)
    {
        while (1)
        {   
            if (M1 <= 0 || money > tienchi)
            {
                HP1 = ceil(HP1 - 17.0 / 100 * HP1);
                EXP1 += ceil(17.0 * EXP1 / 100);
                kiemtra(HP1, EXP1, M1);
                break;
            }
            if (HP1 < 200)
            {
                HP1 += ceil(HP1 * 3.0 / 10);
                M1 -= 150;
                money += 150;
            }
            else
            {
                HP1 = ceil(HP1 * 11.0 / 10);
                M1 -= 70;
                money += 70;
            }
            kiemtra(HP1, EXP1, M1);
            if (M1 == 0 || money > tienchi)
            {
                HP1 = ceil(HP1 - 17.0 / 100 * HP1);
                EXP1 += ceil(17.0 * EXP1 / 100);
                kiemtra(HP1, EXP1, M1);
                break;
            }
            if (EXP1 < 400)
            {
                M1 -= 200;
                money += 200;
                EXP1 += ceil(EXP1 * 13.0 / 100);
            }
            else
            {
                M1 -= 120;
                money += 120;
                EXP1 += ceil(EXP1 * 13.0 / 100);
            }
            kiemtra(HP1, EXP1, M1);
            if (M1 == 0 || money > tienchi)
            {
                HP1 = ceil(HP1 * 83.0 / 100);
                EXP1 += ceil(17.0 * EXP1 / 100);
                kiemtra(HP1, EXP1, M1);
                break;
            }
            if (EXP1 < 300)
            {
                M1 -= 100;
                money += 100;
                EXP1 = ceil(EXP1 * 9.0 / 10);
            }
            else
            {
                M1 -= 120;
                money += 120;
                EXP1 = ceil(EXP1 * 9.0 / 10);
            }
            kiemtra(HP1, EXP1, M1);
            if (M1 == 0 || money > tienchi)
            {
                HP1 = ceil(HP1 * 83.0 / 100);
                EXP1 += ceil(17.0 * EXP1 / 100);
                kiemtra(HP1, EXP1, M1);
                break;
            }
        }
    }
    else
    {
        while (1)
        {   
            if (M1 <= 0)
            {
                HP1 = ceil(HP1 - 17.0 / 100 * HP1);
                EXP1 += ceil(17.0 * EXP1 / 100);
                kiemtra(HP1, EXP1, M1);
                break;
            }
            if (HP1 < 200)
            {
                HP1 += ceil(HP1 * 3.0 / 10);
                M1 -= 150;
                money += 150;
            }
            else
            {
                HP1 = ceil(HP1 * 11.0 / 10);
                M1 -= 70;
                money += 70;
            }
            kiemtra(HP1, EXP1, M1);
            if (M1 <= 0)
            {
                HP1 = ceil(HP1 - 17.0 / 100 * HP1);
                EXP1 += ceil(17.0 * EXP1 / 100);
                kiemtra(HP1, EXP1, M1);
                break;
            }
            if (EXP1 < 400)
            {
                M1 -= 200;
                money += 200;
                EXP1 += ceil(EXP1 * 13.0 / 100);
            }
            else
            {
                M1 -= 120;
                money += 120;
                EXP1 += ceil(EXP1 * 13.0 / 100);
            }
            kiemtra(HP1, EXP1, M1);
            if (M1 <= 0)
            {
                HP1 = ceil(HP1 * 83.0 / 100);
                EXP1 += ceil(17.0 * EXP1 / 100);
                kiemtra(HP1, EXP1, M1);
                break;
            }
            if (EXP1 < 300)
            {
                M1 -= 100;
                money += 100;
                EXP1 = ceil(EXP1 * 9.0 / 10);
            }
            else
            {
                M1 -= 120;
                money += 120;
                EXP1 = ceil(EXP1 * 9.0 / 10);
            }
            kiemtra(HP1, EXP1, M1);
            if (M1 <= 0)
            {
                HP1 = ceil(HP1 * 83.0 / 100);
                EXP1 += ceil(17.0 * EXP1 / 100);
                kiemtra(HP1, EXP1, M1);
                break;
            }
            if (E3 % 2 == 0)
            {
                HP1 = ceil(HP1 * 83.0 / 100);
                EXP1 += ceil(17.0 * EXP1 / 100);
                kiemtra(HP1, EXP1, M1);
                break;
            }
        }
    }
    double P2 = xacxuat(EXP1);
    int i = E3;
    if (E3 >= 10)
    {
        i = (E3 % 10 + E3 / 10) % 10;
    }
    int P3[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P = (P1 + P2 + P3[i] / 100.0) / 3.0;
    if (P == 1)
    {
        EXP1 = ceil(EXP1 * 75.0 / 100);
    }
    else if (P < 0.5)
    {
        HP1 = ceil(HP1 * 85.0 / 100);
        EXP1 += ceil(15.0 * EXP1 / 100);
    }
    else if (P >= 0.5)
    {
        HP1 = ceil(HP1 * 9.0 / 10);
        EXP1 = ceil(12.0 * EXP1 / 10);
    }
    kiemtra(HP1, EXP1, M1);
    return HP1 + EXP1 + M1;
}
// Task 3
void kiemtrainput(int &HP1, int &EXP1, int &HP2, int &EXP2)
{
    if (EXP1 < 0)
        EXP1 = 0;
    else if (EXP1 > 600)
        EXP1 = 600;
    if (EXP2 < 0)
        EXP2 = 0;
    else if (EXP2 > 600)
        EXP2 = 600;
    if (HP1 < 0)
        HP1 = 0;
    else if (HP1 > 666)
        HP1 = 666;
    if (HP2 < 0)
        HP2 = 0;
    else if (HP2 > 666)
        HP2 = 666;
}
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    kiemtrainput(HP1, EXP1, HP2, EXP2);
    if (E3 < 0 || E3 > 99)
        return -99;
    int mangduongdi[10][10], a = 0, b = 0;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            mangduongdi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (mangduongdi[i][j] > E3 * 2)
                a++;
            if (mangduongdi[i][j] < -E3)
                b++;
        }
    }
    for (int i = 0; i < 2; ++i)
    {
        a = a / 10 + a % 10;
        b = b / 10 + b % 10;
    }
    int maxPoint = mangduongdi[a][b], result = mangduongdi[a][b];
    for (int i = 0; i < 10; ++i)
    {
        if (a + i > 9 || b - i < 0)
            break;
        if (mangduongdi[a + i][b - i] > maxPoint)
        {
            maxPoint = mangduongdi[a + i][b - i];
        }
    }
    for (int i = 0; i < 10; ++i)
    {
        if (a - i < 0 || b + i > 9)
            break;
        if (mangduongdi[a - i][b + i] > maxPoint)
        {
            maxPoint = mangduongdi[a - i][b + i];
        }
    }
    for (int j = 0; j < 10; ++j)
    {
        if (a + j > 9 || b + j > 9)
            break;
        if (mangduongdi[a + j][b + j] > maxPoint)
        {
            maxPoint = mangduongdi[a + j][b + j];
        }
    }
    for (int j = 0; j < 10; ++j)
    {
        if (a - j < 0 || b - j < 0)
            break;
        if (mangduongdi[a - j][b - j] > maxPoint)
        {
            maxPoint = mangduongdi[a - j][b - j];
        }
    }
    if (mangduongdi[a][b] < 0)
    {
        mangduongdi[a][b] = -mangduongdi[a][b];
    }
    if (maxPoint < 0)
    {
        maxPoint = -maxPoint;
    }
    if (mangduongdi[a][b] > maxPoint)
    {
        HP1 = ceil(9.0 * HP1 / 10);
        EXP1 = ceil(88.0 * EXP1 / 100);
        HP2 = ceil(9.0 * HP2 / 10);
        EXP2 = ceil(88.0 * EXP2 / 100);
        kiemtrainput(HP1, EXP1, HP2, EXP2);
        return result;
    }
    else
    {
        HP1 = ceil(11.0 * HP1 / 10);
        EXP1 = ceil(112.0 * EXP1 / 100);
        HP2 = ceil(11.0 * HP2 / 10);
        EXP2 = ceil(112.0 * EXP2 / 100);
        kiemtrainput(HP1, EXP1, HP2, EXP2);
        return maxPoint;    
    }
    return -1;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    char SE[100], dodaiSE = 0;
    for (int i = 0; i < 100; ++i)
    {
        if (email[i] != '@')
        {
            SE[i] = email[i];
            dodaiSE++;
        }
        else
        {
            SE[i] = '\0';
            break;
        }
    }
    int dodai = 0;
    for (int i = 0; i < 21; ++i)
    {
        if (s[i] == '\0')
            break;
        else
            dodai++;
    }
    if (dodai > 20)
    {

        return -2;
    }
    else if (dodai < 8)
    {
        return -1;
    }
    if(*SE=='\0') return -300;
    int SEI;
    for (int i = 0; i < dodai; ++i)
    {
        if (s[i] == SE[0])
        {
            int sosanh = 0;
            SEI = i;
            int nam=i;
            for (int j = 0; j < dodaiSE; j++)
            {
                if (s[nam] == SE[j])
                {
                    sosanh++;
                    nam++;
                    if (sosanh == dodaiSE)
                    {
                        return -(300 + SEI);
                    }
                }
                else
                {
                    --nam;
                    break;
                }
            }
        }
    }

    char kytudacbiet = 0;
    for (int i = 0; i < dodai; i++)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            return -(400 + i);
        }
    }
    for (int i = 0; i < dodai; i++)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            kytudacbiet++;
        }
    }
    if (kytudacbiet == 0)
    {
        return -5;
    }

    for (int i = 0; i < dodai; i++)
    {
        if (
            !(s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))
            return i;
    }

    return -10;
}
int dodai(const char arr[])
{
    int dai = 0;
    while (arr[dai] != '\0')
    {
        dai++;
    }
    return dai;
}
bool giongnhau(const char a[], const char b[])
{
    int dai = 0;
    while (1)
    {
        if (a[dai] != b[dai])
            return false;
        if (a[dai] == '\0' && b[dai] == '\0')
            return true;
        dai++;
    }
    return true;
}
// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int solanMax = 0;
    int viTri = -1;
    int dodaiMax = -1;
    for (int i = 0; i < num_pwds; i++)
    {
        int solan = 1;
        for (int j = i + 1; j < num_pwds; j++)
        {
            if (giongnhau(arr_pwds[i], arr_pwds[j]))
            {
                solan++;
            }
        }
        if (solan > solanMax)
        {
            viTri = i;
            dodaiMax = dodai(arr_pwds[i]);
            solanMax = solan;
        }
        else if (solan == solanMax)
        {
            if (dodai(arr_pwds[i]) > dodaiMax)
            {
                viTri = i;
                dodaiMax = dodai(arr_pwds[i]);
                solanMax = solan;
            }
        }
    }
    return viTri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////