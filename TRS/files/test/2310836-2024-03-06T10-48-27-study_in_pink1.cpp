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

// Tim do dai chuoi
int cd(string s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}
// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{

    if (e1 < 0 || e1 > 99)
        return -99;
    if (exp1 > 600)
        exp1 = 600;
    if (exp2 > 600)
        exp2 = 600;
    if (exp1 < 0)
        exp1 = 0;
    if (exp2 < 0)
        exp2 = 0;
    // TODO: Complete this function
    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0)
            exp2 += 29;
        else if (e1 == 1)
            exp2 += 45;
        else if (e1 == 2)
            exp2 += 75;
        else
            exp2 += 149;
        if (exp2 > 600)
            exp2 = 600;
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            exp1 = ceil((double)exp1 + (double)D / 200);

        else
            exp1 = ceil((double)exp1 - (double)D / 100);
        if (exp1 > 600)
            exp1 = 600;
        if (exp1 < 0)
            exp1 = 0;
    }
    if (e1 >= 4 && e1 <= 99)
    {

        if (e1 >= 4 && e1 <= 19)
            exp2 = ceil((double)(exp2) + (double)e1 / 4 + 19);
        else if (e1 <= 49)
            exp2 = ceil((double)(exp2) + (double)e1 / 9 + 21);
        else if (e1 <= 65)
            exp2 = ceil((double)(exp2) + (double)e1 / 16 + 17);
        else if (e1 <= 79)
        {
            exp2 = ceil((double)(exp2) + (double)e1 / 4 + 19);

            if (exp2 > 200)
                exp2 = ceil((double)(exp2) + (double)e1 / 9 + 21);
        }
        else
        {
            exp2 = ceil((double)(exp2) + (double)e1 / 4 + 19);
            exp2 = ceil((double)(exp2) + (double)e1 / 9 + 21);
            if (exp2 > 400)
            {
                exp2 = ceil((double)(exp2) + (double)e1 / 16 + 17);
                exp2 = ceil((double)exp2 * 115 / 100);
            }
        }

        if (exp2 > 600)
            exp2 = 600;
        exp1 -= e1;
        if (exp1 < 0)
            exp1 = 0;
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (E2 < 0 || E2 > 99)
        return -99;
    if (HP1 > 666)
        HP1 = 666;
    if (EXP1 > 600)
        EXP1 = 600;
    if (M1 < 0)
        M1 = 0;
    if (M1 > 3000)
        M1 = 3000;
    if (EXP1 < 0)
        EXP1 = 0;
    if (HP1 < 0)
        HP1 = 0;
    // TODO: Complete this function
    // Con duong 01
    int S = sqrt(EXP1);
    float P1 = 0;
    if (EXP1 - S * S < (S + 1) * (S + 1) - EXP1)
        P1 = 1;
    else
        P1 = (float)EXP1 / ((S + 1) * (S + 1) * 123) + (float)80 / 123;
    // Con duong 02
    //.
    if (M1 > 3000)
        M1 = 3000;
    float Mbd = (float)M1 * 50 / 100;
    int Mct = 0;
    if (M1 > 0)
    {
        if (E2 % 2 == 1)
        {
            while (Mct <= Mbd && Mbd != 0)
            {
                if (HP1 < 200)
                {
                    HP1 = ceil((float)HP1 * 130 / 100);
                    M1 -= 150;
                    Mct += 150;
                }
                else
                {
                    HP1 = ceil((float)HP1 * 110 / 100);
                    M1 -= 70;
                    Mct += 70;
                }
                if (HP1 > 666)
                    HP1 = 666;
                if (M1 < 0)
                    M1 = 0;
                if (Mct > Mbd)
                    break;
                //.

                if (EXP1 < 400)
                {
                    M1 -= 200;
                    Mct += 200;
                }
                else
                {
                    M1 -= 120;
                    Mct += 120;
                }
                if (M1 < 0)
                    M1 = 0;
                EXP1 = ceil((float)EXP1 * 113 / 100);

                if (EXP1 > 600)
                    EXP1 = 600;
                if (Mct > Mbd)
                    break;
                //.
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    Mct += 100;
                }
                else
                {
                    M1 -= 120;
                    Mct += 120;
                }
                if (M1 < 0)
                    M1 = 0;
                EXP1 = ceil((float)EXP1 * 90 / 100);
                if (EXP1 < 0)
                    EXP1 = 0;
            }
        }
        else
        {
            if (HP1 < 200)
            {
                HP1 = ceil((float)HP1 * 130 / 100);
                M1 -= 150;
            }

            else
            {
                HP1 = ceil((float)HP1 * 110 / 100);
                M1 -= 70;
            }
            if (HP1 > 666)
                HP1 = 666;
            if (M1 < 0)
                M1 = 0;

            //.

            if (EXP1 < 400 && M1 > 0)
            {
                M1 -= 200;
                EXP1 = ceil((float)EXP1 * 113 / 100);
            }
            else if (M1 > 0)
            {
                M1 -= 120;
                EXP1 = ceil((float)EXP1 * 113 / 100);
            }
            if (M1 < 0)
                M1 = 0;

            if (EXP1 > 600)
                EXP1 = 600;
            //.
            if (EXP1 < 300 && M1 > 0)
            {
                M1 -= 100;
                EXP1 = ceil((float)EXP1 * 90 / 100);
            }
            else if (M1 > 0)
            {
                M1 -= 120;
                EXP1 = ceil((float)EXP1 * 90 / 100);
            }
            if (M1 < 0)
                M1 = 0;

            if (EXP1 < 0)
                EXP1 = 0;
        }
    }
    HP1 = ceil((float)HP1 * 83 / 100);
    EXP1 = ceil((float)EXP1 * 117 / 100);
    if (HP1 > 666)
        HP1 = 666;
    if (EXP1 > 600)
        EXP1 = 600;
    S = sqrt(EXP1);
    float P2 = 0;
    if (EXP1 - S * S < (S + 1) * (S + 1) - EXP1)
        P2 = 1;
    else
        P2 = (float)EXP1 / ((S + 1) * (S + 1) * 123) + (float)80 / 123;
    // Con duong 3
    int i = 0;
    float P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 >= 10)
        i = (E2 / 10 + E2 % 10) % 10;
    else
        i = E2;
    float P3 = (float)P[i] / 100;
    float Ptb = 0;
    if (P1 == 1 && P2 == 1 && P3 == 1)
        EXP1 = ceil((float)EXP1 * 75 / 100);
    else
    {
        Ptb = (float)(P1 + P2 + P3) / 3;
        if (Ptb < 0.5)
        {
            HP1 = ceil((float)HP1 * 85 / 100);
            EXP1 = ceil((float)EXP1 * 115 / 100);
        }
        else
        {
            HP1 = ceil((float)HP1 * 90 / 100);
            EXP1 = ceil((float)EXP1 * 120 / 100);
        }
    }
    if (HP1 > 666)
        HP1 = 666;
    if (EXP1 > 600)
        EXP1 = 600;
    if (HP1 < 0)
        HP1 = 0;
    if (EXP1 < 0)
        EXP1 = 0;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 < 0 || E3 > 99)
        return -99;
    if (HP1 > 666)
        HP1 = 666;
    if (HP2 > 666)
        HP2 = 666;
    if (HP1 < 0)
        HP1 = 0;
    if (HP2 < 0)
        HP2 = 0;
    if (EXP1 > 600)
        EXP1 = 600;
    if (EXP2 > 600)
        EXP2 = 600;
    if (EXP1 < 0)
        EXP1 = 0;
    if (EXP2 < 0)
        EXP2 = 0;

    // TODO: Complete this function
    int a[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    //
    int b[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int demi = 0, demj = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (a[i][j] > E3 * 2)
                demi++;
            if (a[i][j] < -E3)
                demj++;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int hang = i;
            int cot = j;
            int mx = a[i][j];
            while ((hang > 0 && cot > 0) && (hang < 9 && cot < 9))
            {
                hang++;
                cot--;
            }
            if (hang > cot)
            {
                while (hang >= 0 && cot <= 9)
                {
                    if (mx < a[hang][cot])
                        mx = a[hang][cot];
                    hang--;
                    cot++;
                }
            }
            else
            {
                while (cot >= 0 && hang <= 9)
                {
                    if (mx < a[hang][cot])
                        mx = a[hang][cot];
                    cot--;
                    hang++;
                }
            }
            hang = i;
            cot = j;
            while (hang > 0 && cot > 0)
            {
                hang--;
                cot--;
            }
            while (hang <= 9 && cot <= 9)
            {
                if (mx < a[hang][cot])
                    mx = a[hang][cot];
                cot++;
                hang++;
            }
            b[i][j] = mx;
        }
    }
    while (demi >= 10)
        demi = demi / 10 + demi % 10;
    while (demj >= 10)
        demj = demj / 10 + demj % 10;
    if (b[demi][demj] >= abs(a[demi][demj]))
    {
        EXP1 = ceil((float)EXP1 * 112 / 100);
        EXP2 = ceil((float)EXP2 * 112 / 100);
        HP1 = ceil((float)HP1 * 110 / 100);
        HP2 = ceil((float)HP2 * 110 / 100);
        if (EXP1 > 600)
            EXP1 = 600;
        if (EXP2 > 600)
            EXP2 = 600;
        if (HP1 > 666)
            HP1 = 666;
        if (HP2 > 666)
            HP2 = 666;
        return b[demi][demj];
    }
    else
    {
        EXP1 = ceil((float)EXP1 * 88 / 100);
        EXP2 = ceil((float)EXP2 * 88 / 100);
        HP1 = ceil((float)HP1 * 90 / 100);
        HP2 = ceil((float)HP2 * 90 / 100);
        if (EXP1 < 0)
            EXP1 = 0;
        if (EXP2 < 0)
            EXP2 = 0;
        if (HP1 < 0)
            HP1 = 0;
        if (HP2 < 0)
            HP2 = 0;
        return a[demi][demj];
    }
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    int szs = 0;
    while (s[szs] != '\0')
        szs++;
    int sze = 0;
    while (email[sze] != '\0')
        sze++;
    string se = "";
    for (int i = 0; i < sze; i++)
    {
        if (email[i] != '@')
            se += email[i];
        else
            break;
    }
    if (szs < 8)
        return -1;
    if (szs > 20)
        return -2;
    int sz = cd(se);
    for (int i = 0; i < szs - sz + 1; i++)
    {
        int idx = i;
        for (int j = 0; j < sz; j++)
        {
            if (s[idx] != se[j])
                break;
            idx++;
        }

        if (idx - i == sz)
            return -(300 + i);
    }

    for (int i = 0; i < szs; i++)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
            return -(400 + i);
    }
    int dem = 0;
    for (int i = 0; i < szs; i++)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            dem++;
            break;
        }
    }
    if (dem == 0)
        return -5;
    for (int i = 0; i < szs; i++)
    {
        if ((s[i] < '0' || (s[i] > '9' && s[i] < 'A') || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z') && !(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))
            return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int dem[num_pwds]; // mang dem so lan xuat hien trong mang ban dau
    for (int i = 0; i < num_pwds; i++)
        dem[i] = 0;
    int num = 0;             // bien dem so phan tu co gia tri trung
    int idxlandau[num_pwds]; // mang luu tru vi tri xuat hien lan dau cua cac phan tu
    string s[num_pwds];      // mang luu tru cac phan tu khac nhau
    // Tao ra mang chua so lan xuat hien cua cac phan tu(mang dem)
    for (int i = 0; i < num_pwds; i++)
    {
        int kt = 0;
        int chiso;
        for (int j = 0; j < num; j++)
        {
            if (arr_pwds[i] == s[j])
            {
                kt++;
                chiso = j;
                break;
            }
        }
        if (kt == 0)
        {
            s[num] = arr_pwds[i];
            chiso = num;
            idxlandau[num] = i;
            num++;
        }
        dem[chiso]++;
    }
    int mx = dem[0];
    int mxdodai = cd(arr_pwds[idxlandau[0]]);
    int trave = 0;
    for (int i = 0; i < num; i++)
        if (mx <= dem[i])
        {
            if (mx == dem[i])
            {
                if (cd(arr_pwds[idxlandau[i]]) > mxdodai)
                {
                    mxdodai = cd(arr_pwds[idxlandau[i]]);
                    trave = idxlandau[i];
                }
            }
            if (mx < dem[i])
            {
                mx = dem[i];
                mxdodai = cd(arr_pwds[idxlandau[i]]);
                trave = idxlandau[i];
            }
        }
    return trave;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////