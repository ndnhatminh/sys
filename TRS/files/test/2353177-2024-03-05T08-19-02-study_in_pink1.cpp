#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & E1,
        int & E2,
        int & E3
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

// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1)
{
    // TODO: Complete this function
    if (E1 < 0 || E1>99)return -99;
    if (EXP1 > 600) EXP1 = 600; if (EXP2 > 600) EXP2 = 600;
    if (EXP1 < 0) EXP1 = 0; if (EXP2 < 0) EXP2 = 0;
    if (E1 >= 0 && E1 <= 3)
    {
        int D = 3 * E1 + EXP1 * 7;
        if (D % 2 == 0) { EXP1 = ceil(EXP1 + (float)D / 200); if (EXP1 > 600) EXP1 = 600; }
        else { EXP1 = ceil(EXP1 - (float)D / 100); if (EXP1 < 0) EXP1 = 0; }
        if (E1 == 0) { EXP2 += 29; if (EXP2 > 600) EXP2 = 600; }
        if (E1 == 1) { EXP2 += 45; if (EXP2 > 600) EXP2 = 600; }
        if (E1 == 2) { EXP2 += 75; if (EXP2 > 600) EXP2 = 600; }
        if (E1 == 3) { EXP2 += 149; if (EXP2 > 600) EXP2 = 600; }
    }
    else if (E1 >= 4 && E1 <= 99)
    {
        EXP1 -= E1; if (EXP1 < 0) EXP1 = 0;
        if (E1 <= 19) { EXP2 = ceil(EXP2 + (float)E1 / 4 + 19); if (EXP2 > 600) EXP2 = 600; }
        if (E1 >= 20 && E1 <= 49) { EXP2 = ceil(EXP2 + (float)E1 / 9 + 21); if (EXP2 > 600) EXP2 = 600; }
        if (E1 >= 50 && E1 <= 65) { EXP2 = ceil(EXP2 + (float)E1 / 16 + 17); if (EXP2 > 600) EXP2 = 600; }
        if (E1 >= 66 && E1 <= 79)
        {
            EXP2 = ceil(EXP2 + (float)E1 / 4 + 19); if (EXP2 > 600) EXP2 = 600;
            if (EXP2 > 200) { EXP2 = ceil(EXP2 + (float)E1 / 9 + 21); if (EXP2 > 600) EXP2 = 600; }
        }
        if (E1 >= 80 && E1 <= 99)
        {
            EXP2 = ceil(EXP2 + (float)E1 / 4 + 19); if (EXP2 > 600) EXP2 = 600;
            EXP2 = ceil(EXP2 + (float)E1 / 9 + 21); if (EXP2 > 600) EXP2 = 600;
            if (EXP2 > 400)
            {
                EXP2 = ceil(EXP2 + (float)E1 / 16 + 17);
                EXP2 = ceil((float)1.15f * EXP2); if (EXP2 > 600) EXP2 = 600;
            }
        }
    }
    if (EXP1 > 600) EXP1 = 600; if (EXP2 > 600) EXP2 = 600;
    if (EXP1 < 0) EXP1 = 0; if (EXP2 < 0) EXP2 = 0;
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
    // TODO: Complete this function
    if (E2 > 99 || E2 < 0) return -99;
    if (HP1 > 666) HP1 = 666; if (HP1 < 0) HP1 = 0;
    if (EXP1 > 600) EXP1 = 600; if (EXP1 < 0) EXP1 = 0;
    if (M1 > 3000) M1 = 3000; if (M1 < 0) M1 = 0;


    int s, PREVM1, TOTAL = 0;
    float Pave, P1, P2, P3, P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };

    s = round(sqrt(EXP1));
    s *= s;


    if (EXP1 >= s) P1 = 1;
    else
    {
        P1 = (float)EXP1 / s + 80;
        P1 = (float)P1 / 123;
    }

    PREVM1 = ceil((float)0.5f * M1 - 0.001);


    if (E2 % 2 == 1)
        while (true)
        {
            //SUKIEN1
            if (M1 == 0) break;
            if (TOTAL > PREVM1) break;
            else
            {
                if (HP1 < 200)
                {
                    HP1 = ceil((float)1.3f * HP1 - 0.001); if (HP1 > 666) HP1 = 666;
                    M1 -= 150; if (M1 < 0) M1 = 0; TOTAL += 150;
                }
                else
                {
                    HP1 = ceil((float)1.1f * HP1 - 0.001); if (HP1 > 666) HP1 = 666;
                    M1 -= 70; if (M1 < 0) M1 = 0; TOTAL += 70;
                }
            }

            if (M1 == 0) break;
            if (TOTAL > PREVM1) break;
            else
            {
                //SUKIEN2
                if (EXP1 < 400)
                {
                    M1 -= 200; if (M1 < 0) M1 = 0; TOTAL += 200;
                }
                else
                {
                    M1 -= 120; if (M1 < 0) M1 = 0; TOTAL += 120;
                }
                EXP1 = ceil((float)1.13f * EXP1 - 0.001); if (EXP1 > 600) EXP1 = 600;
                //HETSUKIEN2
            }



            if (M1 == 0) break;
            if (TOTAL > PREVM1) break;
            else
            {
                //SUKIEN3
                if (EXP1 < 300)
                {
                    M1 -= 100; if (M1 < 0) M1 = 0; TOTAL += 100;
                }
                else
                {
                    M1 -= 120; if (M1 < 0) M1 = 0; TOTAL += 120;
                }
                EXP1 = ceil((float)0.9f * EXP1 - 0.001);
                //HETSUKIEN3
            }
        }

    else if (E2 % 2 == 0)
    {
        if (M1 != 0)
        {
            if (HP1 < 200)
            {
                HP1 = ceil((float)1.3f * HP1 - 0.001); if (HP1 > 666) HP1 = 666;
                M1 -= 150; if (M1 < 0) M1 = 0;
            }
            else if (HP1 >= 200)
            {
                HP1 = ceil((float)1.1f * HP1 - 0.001); if (HP1 > 666) HP1 = 666;
                M1 -= 70; if (M1 < 0) M1 = 0;
            }
        }
        //HETSUKIEN1

        //SUKIEN2
        if (M1 != 0)
        {
            if (EXP1 < 400)
            {
                M1 -= 200; if (M1 < 0) M1 = 0;
            }
            else if (EXP1 >= 400)
            {
                M1 -= 120; if (M1 < 0) M1 = 0;
            }
            EXP1 = ceil((float)1.13f * EXP1 - 0.001); if (EXP1 > 600) EXP1 = 600;
            //HETSUKIEN2
        }


        //SUKIEN3
        if (M1 != 0)
        {
            if (EXP1 < 300)
            {
                M1 -= 100; if (M1 < 0) M1 = 0;
            }
            else if (EXP1 >= 300)
            {
                M1 -= 120; if (M1 < 0) M1 = 0;
            }
            EXP1 = ceil((float)0.9f * EXP1 - 0.001);
            //HETSUKIEN3
        }
    }
    HP1 = ceil((float)0.83f * HP1 - 0.001);
    EXP1 = ceil((float)1.17f * EXP1 - 0.001); if (EXP1 > 600) EXP1 = 600;

    s = round(sqrt(EXP1));
    s *= s;


    if (EXP1 >= s) P2 = 1;
    else
    {
        P2 = (float)EXP1 / s + 80;
        P2 = (float)P2 / 123;
    }


    if (E2 > 0 && E2 < 10) P3 = P[E2] / 100;
    else if (E2 >= 10 && E2 <= 99) P3 = P[(E2 / 10 + E2 % 10) % 10] / 100.0;


    if (P1 == 1 && P2 == 1 && P3 == 1) EXP1 = ceil((float)0.75f * EXP1 - 0.001);
    else
    {
        Pave = (P1 + P2 + P3) / 3;
        if (Pave < 0.5f)
        {
            HP1 = ceil((float)0.85f * HP1 - 0.001);
            EXP1 = ceil((float)1.15f * EXP1 - 0.001); if (EXP1 > 600) EXP1 = 600;
        }
        else
        {
            HP1 = ceil((float)0.9f * HP1 - 0.001);
            EXP1 = ceil((float)1.2f * EXP1 - 0.001); if (EXP1 > 600) EXP1 = 600;
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3>99) return -99;

    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP2 > 600) EXP2 = 600;
    if (EXP2 < 0) EXP2 = 0;
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    if (HP2 > 666) HP2 = 666;
    if (HP2 < 0) HP2 = 0;

    int Matrix[11][11], ci = 0, cj = 0, Maxx = -32000;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            Matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (Matrix[i][j] > E3 * 2) ci++;
            if (Matrix[i][j] < -E3) cj++;
        }
    }
    if (ci > 9)
    {
        while (true)
        {
            ci = ci / 10 + ci % 10;
            if (ci > 0 && ci < 10) break;
        }
    }
    if (cj > 9)
    {
        while (true)
        {
            cj = cj / 10 + cj % 10;
            if (cj > 0 && cj < 10) break;
        }
    }

    int x = ci, y = cj;
    while (x >= 0 && x < 10 && y >= 0 && y < 10)
    {
        if (Matrix[x][y] > Maxx) Maxx = Matrix[x][y];
        x++; y++;
    }

    x = ci, y = cj;
    while (x >= 0 && x < 10 && y >= 0 && y < 10)
    {
        if (Matrix[x][y] > Maxx) Maxx = Matrix[x][y];
        x--; y--;
    }

    x = ci, y = cj;
    while (x >= 0 && x < 10 && y >= 0 && y < 10)
    {
        if (Matrix[x][y] > Maxx) Maxx = Matrix[x][y];
        x--; y++;
    }

    x = ci, y = cj;
    while (x >= 0 && x < 10 && y >= 0 && y < 10)
    {
        if (Matrix[x][y] > Maxx) Maxx = Matrix[x][y];
        x++; y--;
    }

    if (abs(Matrix[ci][cj]) > Maxx)
    {
        EXP1 = ceil((float)0.88f * EXP1);
        EXP2 = ceil((float)0.88f * EXP2);
        HP1 = ceil((float)0.9f * HP1);
        HP2 = ceil((float)0.9f * HP2);
        return Matrix[ci][cj];
    }
    else if (abs(Matrix[ci][cj]) <= Maxx)
    {
        EXP1 = ceil((float)1.12f * EXP1); if (EXP1 > 600) EXP1 = 600;
        EXP2 = ceil((float)1.12f * EXP2); if (EXP2 > 600) EXP2 = 600;
        HP1 = ceil((float)1.1f * HP1); if (HP1 > 666) HP1 = 666;
        HP2 = ceil((float)1.1f * HP2); if (HP2 > 666) HP2 = 666;
        return Maxx;
    }
    return -1;
}

// Task 4
int checkPassword(const char* s, const char* email)
{
    // TODO: Complete this function
    string Email = email;
    string Pass = s, se;
    bool check = false;


    if (Pass.length() < 8) return -1;
    if (Pass.length() > 20) return -2;
    se = Email.substr(0, Email.find('@'));
    if (Pass.find(se) <= 20) return -(300 + Pass.find(se));
    for (int i = 0; i < Pass.length(); i++)
    {
        if (Pass[i] == Pass[i + 1] && Pass[i + 1] == Pass[i + 2])
        {
            return -(400 + i);
        }
    }
    if (Pass.find('@') > 20 && Pass.find('#') > 20 && Pass.find('%') > 20 && Pass.find('$') > 20 && Pass.find('!') > 20) return -5;
    for (int i = 0; i < Pass.length(); i++)
    {
        if ((int)Pass[i] < 48 && (int)Pass[i] != 33 && (int)Pass[i] != 35 && (int)Pass[i] != 36 && (int)Pass[i] != 37) return i;
        else if ((int)Pass[i] < 64 && (int)Pass[i] > 57) return i;
        else if ((int)Pass[i] < 97 && (int)Pass[i] > 90) return i;
        else if ((int)Pass[i] > 122) return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int count[1000], lenght[1000], MaxTime = 1, MaxLength = 0;

    for (int i = 0; i < num_pwds; i++) { count[i] = 1; lenght[i] = 0; }

    for (int i = 0; i < num_pwds - 1; i++)
    {
        for (int j = i + 1; j < num_pwds; j++)
        {

            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                count[i]++;
            }
        }
    }



    for (int i = 0; i < num_pwds; i++) if (count[i] > MaxTime) MaxTime = count[i];

    for (int i = 0; i < num_pwds; i++)
    {
        if (count[i] == MaxTime)
        {
            lenght[i] = strlen(arr_pwds[i]);
            if (lenght[i] > MaxLength) MaxLength = lenght[i];
        }
    }

    for (int i = 0; i < num_pwds; i++) if (lenght[i] == MaxLength) return i;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////