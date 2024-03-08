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

// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {
    // TODO: Complete this function
    if (E1 < 0 || E1 > 99) return -99;
    if (E1 <= 3)
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
        int D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0) EXP1 += ceil(float(D / 200.0));
        else EXP1 -= floor(float(D / 100.0));
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        if (EXP2 > 600) EXP2 = 600;
    }
    else
    {
        if (E1 <= 19) EXP2 += ceil(float(E1 / 4.0)) + 19;
        else if (E1 > 19 && E1 <= 49) EXP2 += ceil(float(E1 / 9.0)) + 21;
        else if (E1 > 49 && E1 <= 65) EXP2 += ceil(float(E1 / 16.0)) + 17;
        else if (E1 > 65 && E1 <= 79)
        {
            EXP2 += ceil(float(E1 / 4.0)) + 19;
            if (EXP2 > 200) EXP2 += ceil(float(E1 / 9.0)) + 21;
        }
        else if (E1 > 79)
        {
            EXP2 += ceil(float(E1 / 9.0)) + 21 + ceil(float(E1 / 16.0)) + 17;
            if (EXP2 > 400)
            {
                EXP2 += ceil(float(E1 / 16.0)) + 17;
                EXP2 = ceil(float(EXP2 * 1.15));
            }
        }
        EXP1 -= E1;
        if (EXP1 < 0) EXP1 = 0;
        if (EXP2 > 600) EXP2 = 600;
    }
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;
    

    float P1, P2, P3;
    //Road 01
    int n = round(sqrt(EXP1));
    float s = n * n;
    if (EXP1 >= s) P1 = 100;
    else P1 = float((EXP1 / s + 80) / 1.23);
    //Road 02
    if (E2 % 2)
    {
        int tieu = 0, event = 2, fund = ceil(float(M1 * 0.5));
        while (tieu <= fund)
        {
            switch (event=++event % 3)
            {
            case 0: //Event 1
                if (HP1 < 200)
                {
                    HP1 = ceil(float(HP1 * 1.3));
                    M1 -= 150;
                    tieu += 150;
                }
                else
                {
                    HP1 = ceil(float(HP1 * 1.1));
                    M1 -= 70;
                    tieu += 70;
                }
                if (HP1 > 666) HP1 = 666;
                if (M1 < 0) M1 = 0;
                break;
            case 1: //Event 2
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    tieu += 200;
                }
                else
                {
                    M1 -= 120;
                    tieu += 120;
                }
                EXP1 = ceil(float(EXP1 * 1.13));
                if (EXP1 > 600) EXP1 = 600;
                if (M1 < 0) M1 = 0;
                break;
            case 2: //Event 3
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    tieu += 100;
                }
                else
                {
                    M1 -= 120;
                    tieu += 120;
                }
                EXP1 = ceil(float(EXP1 * 0.9));
                if (M1 < 0) M1 = 0;
                break;
            }
        }
    }
    else
    {
        int event = 0;
        while (M1 != 0 && event != 3)
        {
            switch (event++)
            {
            case 0: //Event 1
                if (HP1 < 200)
                {
                    HP1 = ceil(float(HP1 * 1.3));
                    M1 -= 150;
                }
                else
                {
                    HP1 = ceil(float(HP1 * 1.1));
                    M1 -= 70;
                }
                if (HP1 > 666) HP1 = 666;
                if (M1 < 0) M1 = 0;
                break;
            case 1: //Event 2
                if (EXP1 < 400) M1 -= 200;
                else M1 -= 120;
                EXP1 = ceil(float(EXP1 * 1.13));
                if (EXP1 > 600) EXP1 = 600;
                if (M1 < 0) M1 = 0;
                break;
            case 2: //Event 3
                if (EXP1 < 300) M1 -= 100;
                else M1 -= 120;
                EXP1 = ceil(float(EXP1 * 0.9));
                if (M1 < 0) M1 = 0;
                break;
            }
        }
    }
    HP1 = ceil(float(HP1 * 0.83));
    EXP1 = ceil(float(EXP1 * 1.17));
    if (EXP1 > 600) EXP1 = 600;
    n = round(sqrt(EXP1));
    s = n * n;
    if (EXP1 >= s) P2 = 100;
    else P2 = float((EXP1 / s + 80) / 1.23);
    //Road 03
    int i = (E2 / 10 + E2 % 10) % 10;
    int xacsuat[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    P3 = xacsuat[i];
    if (P1 == 100 && P2 == 100 && P3 == 100) EXP1 = ceil(float(EXP1 * 0.75));
    float P = float((P1 + P2 + P3) / 3);
    if (P < 50)
    {
        HP1 = ceil(float(HP1 * 0.85));
        EXP1 = ceil(float(EXP1 * 1.15));
    }
    else
    {
        HP1 = ceil(float(HP1 * 0.9));
        EXP1 = ceil(float(EXP1 * 1.2));
    }
    if (EXP1 > 600) EXP1 = 600;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    int Taxi[10][10], Sherlock[10][10], Left[19], Right[19];
    int x = 0, y = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            Taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            Left[i - j + 9] = max(Left[i - j + 9], Taxi[i][j]);
            Right[i + j] = max(Right[i + j], Taxi[i][j]);
            if (Taxi[i][j] > E3 * 2) ++x;
            if (Taxi[i][j] < -E3) ++y;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            Sherlock[i][j] = abs(max(Left[i - j + 9], Right[i + j]));
        }
    }
    while (x > 9)
    {
        x = x / 10 + x % 10;
    }
    while (y > 9)
    {
        y = y / 10 + y % 10;
    }
    if (abs(Taxi[x][y]) > Sherlock[x][y])
    {
        EXP1 = ceil(float(EXP1 * 0.88));
        HP1 = ceil(float(HP1 * 0.90));
        EXP2 = ceil(float(EXP2 * 0.88));
        HP2 = ceil(float(HP2 * 0.90));
        return Taxi[x][y];
    }
    else
    {
        EXP1 = ceil(float(EXP1 * 1.12));
        HP1 = ceil(float(HP1 * 1.10));
        EXP2 = ceil(float(EXP2 * 1.12));
        HP2 = ceil(float(HP2 * 1.10));
        if (EXP1 > 600) EXP1 = 600;
        if (HP1 > 666) HP1 = 666;
        if (EXP2 > 600) EXP2 = 600;
        if (HP2 > 666) HP2 = 666;
        return Sherlock[x][y];
    }
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    int dodais = strlen(s);
    char se[101];
    int dodaise = 0;
    while (email[dodaise] != '@')
    {
        se[dodaise] = email[dodaise];
        dodaise++;
    }
    se[dodaise] = '\0';
    if (dodais < 8) return -1;
    if (dodais > 20) return -2;
    bool Kitudacbiet = false;
    for (int i = 0; i < dodais; i++)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            Kitudacbiet = true;
        }
        if (i < dodais - dodaise + 1 && strncmp(s + i, se, dodaise) == 0)
        {
            return -(300 + i);
        }
        if (i < dodais - 2 && s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            return -(400 + i);
        }
    }
    if (!Kitudacbiet) return -5;
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int highestcount = 0, longestlen = 0, firstindex = -99;
    for (int i = 0; i < num_pwds; i++)
    {
        int currentcount = 0;
        for (int j = 0; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) currentcount++;
        }
        int currentlen = strlen(arr_pwds[i]);
        if (currentcount > highestcount || (currentcount == highestcount && currentlen > longestlen))
        {
            highestcount = currentcount;
            longestlen = currentlen;
            firstindex = i;  
        }
    }
    return firstindex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////