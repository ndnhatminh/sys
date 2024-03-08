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

int checkEXP(int x)
{
    if (x < 0)
    {
        x = 0;
    }
    else if (x > 600)
    {
        x = 600;
    }
    return x;
}

int checkHP(int x)
{
    if (x < 0)
    {
        x = 0;
    }
    else if (x > 666)
    {
        x = 666;
    }
    return x;
}

int checkM(int x)
{
    if (x < 0)
    {
        x = 0;
    }
    else if (x > 3000)
    {
        x = 3000;
    }
    return x;
}
// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    int D;

    if (e1 < 0 || e1 > 99)
        return -99;

    if (e1 >= 0 && e1 <= 3)
    {
        switch (e1)
        {
        case 0:
            exp2 = exp2 + 29;
            break;

        case 1:
            exp2 = exp2 + 45;
            break;

        case 2:
            exp2 = exp2 + 75;
            break;

        case 3:
            exp2 = exp2 + 29 + 45 + 75;
            break;
        }
        exp2 = checkEXP(exp2);
        D = e1 * 3 + exp1 * 7;

        if (D % 2 == 0)
        {
            exp1 = exp1 + ceil((double)D / 200);
        }
        else
        {
            exp1 = ceil(exp1 - D / 100);
        }
        exp1 = checkEXP(exp1);
    }

    else if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 = ceil(exp2 + (float)e1 / 4 + 19 - 1e-8);
        }
        else if (e1 > 19 && e1 <= 49)
        {
            exp2 = ceil(exp2 + (float)e1 / 9 + 21 - 1e-8);
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 = ceil(exp2 + (float)e1 / 16 + 17 - 1e-8);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 = ceil(exp2 + (float)e1 / 4 + 19 - 1e-8);
            if (exp2 > 200)
                exp2 = ceil(exp2 + (float)e1 / 9 + 21 - 1e-8);
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 = ceil(exp2 + (float)e1 / 4 + 19 - 1e-8);
            exp2 = checkEXP(exp2);
            exp2 = ceil(exp2 + (float)e1 / 9 + 21 - 1e-8);
            exp2 = checkEXP(exp2);

            if (exp2 > 400)
            {
                exp2 = ceil(exp2 + (float)e1 / 16 + 17 - 1e-8);
                exp2 = ceil(exp2 * 1.15 - 1e-8);
            }
        }
        exp1 = exp1 - e1;
        exp1 = checkEXP(exp1);
        exp2 = checkEXP(exp2);
    }

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    int S;
    double P1, P2, P3;

    if (E2 < 0 || E2 > 99)
        return -99;

    if (EXP1 != int(sqrt(EXP1)) * int(sqrt(EXP1)))
    {
        S = int(sqrt(EXP1) + 0.5) * int(sqrt(EXP1) + 0.5);
    }
    else
    {
        S = EXP1;
    }
    // cout << "S la "<<S<<endl;
    // cout << "exp1 la "<<EXP1<<endl;
    if (EXP1 >= S)
    {
        P1 = 100;
    }
    else
    {
        P1 = ceil(((float)EXP1 / S + 80) * 100 / 123);
    }

    // cout << "P1 la "<< ceil(P1) << endl;

    // con duong 2
    int M, T;
    T = 0;
    M = M1 * 0.5;
    if (E2 % 2 == 0)
    {
        if (HP1 < 200)
        {
            HP1 = ceil(HP1 * 1.3 - 1e-8);
            M1 -= 150;
        }
        else if (HP1 >= 200)
        {
            HP1 = ceil(HP1 * 1.1 - 1e-8);
            M1 -= 70;
        }
        HP1 = checkHP(HP1);
        M1 = checkM(M1);
        if (M1 > 0)
        {
            if (EXP1 < 400)
            {
                M1 -= 200;
            }
            else if (EXP1 >= 400)
            {
                M1 -= 120;
            }
            EXP1 = ceil(EXP1 * 1.13 - 1e-8);
        }
        EXP1 = checkEXP(EXP1);
        M1 = checkM(M1);
        if (M1 > 0)
        {
            if (EXP1 < 300)
            {
                M1 -= 100;
            }
            else if (EXP1 >= 300)
            {
                M1 -= 120;
            }
            EXP1 = ceil(EXP1 * 0.9 - 1e-8);
            EXP1 = checkEXP(EXP1);
            M1 = checkM(M1);
        }
    }
    if (E2 % 2 != 0)
    {
        for (; T <= M;)
        {
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 * 1.3 - 1e-8);
                M1 -= 150;
                T += 150;
            }
            else if (HP1 >= 200)
            {
                HP1 = ceil(HP1 * 1.1 - 1e-8);
                M1 -= 70;
                T += 70;
            }
            HP1 = checkHP(HP1);
            M1 = checkM(M1);
            if (T <= M)
            {
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    T += 200;
                }

                else if (EXP1 >= 400)
                {
                    M1 -= 120;
                    T += 120;
                }
                EXP1 = ceil(EXP1 * 1.13 - 1e-8);
            }

            EXP1 = checkEXP(EXP1);
            M1 = checkM(M1);
            if (T <= M)
            {
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    T += 100;
                }
                else if (EXP1 >= 300)
                {
                    M1 -= 120;
                    T += 120;
                }
                EXP1 = ceil(EXP1 * 0.9 - 1e-8);
            }
            EXP1 = checkEXP(EXP1);
            M1 = checkM(M1);
        }
    }

    HP1 = ceil(HP1 * 0.83 - 1e-8);
    EXP1 = ceil(EXP1 * 1.17 - 1e-8);
    // cout << EXP1 << endl;

    EXP1 = checkEXP(EXP1);
    HP1 = checkHP(HP1);

    if (EXP1 != int(sqrt(EXP1)) * int(sqrt(EXP1)))
    {
        S = int(sqrt(EXP1) + 0.5) * int(sqrt(EXP1) + 0.5);
    }
    else
    {
        S = EXP1;
    }

    if (EXP1 >= S)
    {
        P2 = 100;
    }
    else
    {
        P2 = ceil(((float)EXP1 / S + 80) * 100 / 123);
    }

    // con duong 3
    int X[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int sum, i, P;
    sum = 0;
    while (E2 != 0)
    {
        sum += E2 % 10;
        E2 = E2 / 10;
    }
    i = sum % 10;
    P3 = X[i];
    // cout << "P3 = "<<P3<<endl;

    P = (P1 + P2 + P3) / 3;
    // cout << "Xac suat P = "<< P<< endl;
    if (P1 == 100 && P2 == 100 && P3 == 100)
    {

        EXP1 = ceil(0.75 * EXP1 - 1e-8);
    }
    else if (P < 50)
    {
        HP1 = ceil(HP1 * 0.85 - 1e-8);
        EXP1 = ceil(EXP1 * 1.15 - 1e-8);
    }
    else if (P >= 50)
    {
        HP1 = ceil(HP1 * 0.9 - 1e-8);
        EXP1 = ceil(EXP1 * 1.2 - 1e-8);
    }
    HP1 = checkHP(HP1);
    EXP1 = checkEXP(EXP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    int a[10][10];
    int count1, count2, sum1(0), sum2(0), w(0), b(0), tong, diemTaxi, diemS, diemS1, diemS2;
    int diem;

    if (E3 < 0 || E3 > 99)
        return -99;
    // HP1 = checkHP(HP1);
    // EXP1 = checkEXP(EXP1);
    // HP2 = checkHP(HP2);
    // EXP2 = checkEXP(EXP2);

    // diem = 0;
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);

            if (a[i][j] > (E3 * 2))
            {
                count1++;
            }

            if (a[i][j] < (-E3))
            {
                count2++;
            }
        }
    }

    if (count1 >= 10)
    {
        sum1 += count1 / 10;
        count1 = count1 % 10;
        sum1 += count1;
        while (sum1 > 9)
        {
            w += sum1 / 10;
            sum1 = sum1 % 10;
        }
        w += sum1;
    }
    else
    {
        w = count1;
    }

    if (count2 >= 10)
    {
        sum2 += count2 / 10;
        count2 = count2 % 10;
        sum2 += count2;
        while (sum2 > 9)
        {
            b += sum2 / 10;
            sum2 = sum2 % 10;
        }
        b += sum2;
    }
    else
    {
        b = count2;
    }
    diemS1 = a[0][0];
    diemTaxi = a[w][b];
    tong = w + b;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            if (i + j == tong)
            {
                if (a[i][j] > diemS1)
                    swap(diemS1, a[i][j]);
            }
    }

    diemS2 = a[0][0];
    int hieu = 0;
    hieu = w - b;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            if (i - j == hieu)
            {
                if (a[i][j] > diemS2)
                    swap(diemS2, a[i][j]);
            }
    }

    if (diemS1 > diemS2)
    {
        diemS = diemS1;
    }
    else if (diemS1 <= diemS2)
    {
        diemS = diemS2;
    }

    if (diemS < 0)
    {
        diemS = abs(diemS);
    }
    if (abs(diemTaxi) > diemS)
    {
        diem = diemTaxi;
        EXP1 = ceil((float)EXP1 * 0.88 - 1e-8);
        HP1 = ceil((float)HP1 * 0.9 - 1e-8);
        EXP2 = ceil((float)EXP2 * 0.88 - 1e-8);
        HP2 = ceil((float)HP2 * 0.9 - 1e-8);
    }
    else if (abs(diemTaxi) <= diemS)
    {
        diem = diemS;
        EXP1 = ceil((float)EXP1 * 1.12 - 1e-8);
        HP1 = ceil((float)HP1 * 1.1 - 1e-8);
        EXP2 = ceil((float)EXP2 * 1.12 - 1e-8);
        HP2 = ceil((float)HP2 * 1.1 - 1e-8);
    }
    HP1 = checkHP(HP1);
    EXP1 = checkEXP(EXP1);
    HP2 = checkHP(HP2);
    EXP2 = checkEXP(EXP2);
    return diem;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    string se(email);
    int count = 0;
    int huhu = 0;
    int sLength;
    int a;

    while (se[count] != '@')
    {
        count++;
    }
    se.resize(count);
    sLength = strlen(s);

    bool specialChar = false;
    for (int i = 0; i < sLength; i++)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            specialChar = true;
            break;
        }
    }
    bool check = true;
    for (int i = 0; i < sLength; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            huhu++;
        }
        else
        {
            check = false;
            break;
        }
    }

    if (sLength < 8)
    {
        return -1;
    }
    else if (sLength > 20)
    {
        return -2;
    }

    if (strstr(s, se.c_str()) != NULL)
    {
        return -(300 + string(s).find(se));
    }

    for (int i = 0; i < sLength; i++)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            return -(400 + i);
        }
    }

    if (!specialChar)
    {
        return -5;
    }
    else if (!check)
    {
        return huhu;
    }
    else
    {
        return -10;
    }
}

// Task 5
int countPw(const char *arr_pwds[], int num_pwds, const char *pw)
{
    int count = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        if (strcmp(pw, arr_pwds[i]) == 0)
            count++;
    }
    return count;
}

int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int max = 0;
    int maxLength = 0;
    int viTri, length, xh;

    for (int i = 0; i < num_pwds; i++)
    {
        const char *pw = arr_pwds[i];
        length = strlen(pw);
        xh = countPw(arr_pwds, num_pwds, pw);
        if (xh > max || (xh == max && length > maxLength))
        {
            maxLength = length;
            max = xh;
            viTri = i;
        }
    }
    return viTri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
///////////////////////////////////////////////