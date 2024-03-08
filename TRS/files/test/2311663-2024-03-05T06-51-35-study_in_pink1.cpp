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

//! Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    int D;
    if (E1 < 0 || E1 > 99) 
    return -99;
    if (EXP1 < 0 || EXP1 > 600)
    {
        if (EXP1 < 0)
        EXP1 *= 0;
        if (EXP1 > 600)
        EXP1 = EXP1*0 + 600;
    }
if (EXP2 < 0 || EXP2 > 600)
    {
        if (EXP2 < 0)
        EXP2 *= 0;
        if (EXP2 > 600)
        EXP2 = EXP2*0 + 600;
    }
    if (E1 >= 0 && E1 <= 3)
    {
        if (E1 == 0)
        {
            EXP2 += 29;
            if (EXP2 < 0 || EXP2 > 600)
    {
        if (EXP2 < 0)
        EXP2 *= 0;
        if (EXP2 > 600)
        EXP2 = EXP2*0 + 600;
    }
        }
        else if (E1 == 1)
        {
            EXP2 += 45;
            if (EXP2 < 0 || EXP2 > 600)
    {
        if (EXP2 < 0)
        EXP2 *= 0;
        if (EXP2 > 600)
        EXP2 = EXP2*0 + 600;
    }
        }
        else if (E1 == 2)
        {
            EXP2 += 75;
            if (EXP2 < 0 || EXP2 > 600)
    {
        if (EXP2 < 0)
        EXP2 *= 0;
        if (EXP2 > 600)
        EXP2 = EXP2*0 + 600;
    }
        }
        else if (E1 == 3)
        {
            EXP2 += 149;
            if (EXP2 < 0 || EXP2 > 600)
    {
        if (EXP2 < 0)
        EXP2 *= 0;
        if (EXP2 > 600)
        EXP2 = EXP2*0 + 600;
    }
        }
        D = E1*3 + EXP1*7;
        if (D %2 == 0)
        {
            EXP1 = ceil(-1e-9+EXP1 + (D/200.0));
            if (EXP1 < 0 || EXP1 > 600)
    {
        if (EXP1 < 0)
        EXP1 *= 0;
        if (EXP1 > 600)
        EXP1 = EXP1*0 + 600;
    }
        }
        else
        {
            EXP1 = ceil(-1e-9+EXP1 - (D/100.0));
            if (EXP1 < 0 || EXP1 > 600)
    {
        if (EXP1 < 0)
        EXP1 *= 0;
        if (EXP1 > 600)
        EXP1 = EXP1*0 + 600;
    }       
    }
    }
    else
    {
        if (E1 >= 4 && E1 <= 19)
        {
            EXP2 = EXP2 + ceil(-1e-9+E1/4.0 + 19);
            if (EXP2 < 0 || EXP2 > 600)
    {
        if (EXP2 < 0)
        EXP2 *= 0;
        if (EXP2 > 600)
        EXP2 = EXP2*0 + 600;
    }
    EXP1 -= E1;
    if (EXP1 < 0 || EXP1 > 600)
    {
        if (EXP1 < 0)
        EXP1 *= 0;
        if (EXP1 > 600)
        EXP1 = EXP1*0 + 600;
    }
        }
        else if (E1 >= 20 && E1 <= 49)
        {
            EXP2 = EXP2 + ceil(-1e-9+E1/9.0 + 21);
            if (EXP2 < 0 || EXP2 > 600)
    {
        if (EXP2 < 0)
        EXP2 *= 0;
        if (EXP2 > 600)
        EXP2 = EXP2*0 + 600;
    }
    EXP1 -= E1;
    if (EXP1 < 0 || EXP1 > 600)
    {
        if (EXP1 < 0)
        EXP1 *= 0;
        if (EXP1 > 600)
        EXP1 = EXP1*0 + 600;
    }
        }
        else if (E1 >= 50 && E1 <= 65)
        {
            EXP2 = EXP2 + ceil(-1e-9+E1/16.0 +17);
            if (EXP2 < 0 || EXP2 > 600)
    {
        if (EXP2 < 0)
        EXP2 *= 0;
        if (EXP2 > 600)
        EXP2 = EXP2*0 + 600;
    }
     EXP1 -= E1;
    if (EXP1 < 0 || EXP1 > 600)
    {
        if (EXP1 < 0)
        EXP1 *= 0;
        if (EXP1 > 600)
        EXP1 = EXP1*0 + 600;
    }
        }
        else if (E1 >= 66 && E1 <= 79)
        {
            EXP2 = EXP2 + ceil(-1e-9+E1/4.0 + 19);
            if (EXP2 < 0 || EXP2 > 600)
    {
        if (EXP2 < 0)
        EXP2 *= 0;
        if (EXP2 > 600)
        EXP2 = EXP2*0 + 600;
    }
            if (EXP2 > 200)
            {
                EXP2 = EXP2 + ceil(-1e-9+E1/9.0 + 21);
                if (EXP2 < 0 || EXP2 > 600)
    {
        if (EXP2 < 0)
        EXP2 *= 0;
        if (EXP2 > 600)
        EXP2 = EXP2*0 + 600;
    }
            }
    EXP1 -= E1;
    if (EXP1 < 0 || EXP1 > 600)
    {
        if (EXP1 < 0)
        EXP1 *= 0;
        if (EXP1 > 600)
        EXP1 = EXP1*0 + 600;
    }
        }
        else if (E1 >= 80 && E1 <= 99)
        {
            EXP2 = EXP2 + ceil(-1e-9+E1/4.0 + 19);
            if (EXP2 < 0 || EXP2 > 600)
    {
        if (EXP2 < 0)
        EXP2 *= 0;
        if (EXP2 > 600)
        EXP2 = EXP2*0 + 600;
    }
            EXP2 = EXP2 + ceil(-1e-9+E1/9.0 + 21);
            if (EXP2 < 0 || EXP2 > 600)
    {
        if (EXP2 < 0)
        EXP2 *= 0;
        if (EXP2 > 600)
        EXP2 = EXP2*0 + 600;
    }
            if (EXP2 > 400)
            {
                EXP2 = EXP2 + ceil(-1e-9+E1/16.0 +17);
                if (EXP2 < 0 || EXP2 > 600)
    {
        if (EXP2 < 0)
        EXP2 *= 0;
        if (EXP2 > 600)
        EXP2 = EXP2*0 + 600;
    }
    EXP2 = EXP2 + ceil(-1e-9+(EXP2*15)/100.0);
    if (EXP2 < 0 || EXP2 > 600)
    {
        if (EXP2 < 0)
        EXP2 *= 0;
        if (EXP2 > 600)
        EXP2 = EXP2*0 + 600;
    }
            }
    EXP1 -= E1;
    if (EXP1 < 0 || EXP1 > 600)
    {
        if (EXP1 < 0)
        EXP1 *= 0;
        if (EXP1 > 600)
        EXP1 = EXP1*0 + 600;
    }
        }
    }
    return EXP1 + EXP2;
    }
    
int checkEXP (double x){
if (x < 0) return 0;
else if (x > 600) return 600;
else return x;
}
int checkHP (double y){
if (y < 0) return 0;
else if (y > 666) return 666;
else return y;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    int M2;
    if (M1 < 0)
    M1 = 0;
    else if (M1 > 3000)
    M1 = 3000;
    if (M2 < 0)
    M2 = 0;
    else if (M2 > 3000)
    M2 = 3000;
    if (E2 < 0 || E2 > 99) 
    return -99;
    EXP1 = checkEXP(EXP1);
    HP1 = checkHP(HP1);
    double P1,P2,P3;
    double M6;
    M6 = M1/2.0;
    int S = round(sqrt(EXP1));
    S = S * S;
    if (EXP1 >= S)
    {
        P1 = 100;
    } 
    else
    {
        P1 = ((double(EXP1)/S + 80)/123.0)*100;
    }
    //con duong so 2
    if (E2 % 2 == 0)
    {
        while (M1 > 0)
        {
            if (HP1 < 200)
            {
                M1 -= 150;
                HP1 = ceil(HP1*130.0/100);
                HP1 = checkHP(HP1);
                if (M1 <= 0)
                {
                    M1 = 0;
                    break;
                }
            }
            else if (HP1 >= 200)
            {
                M1 -= 70;
                HP1 = ceil(HP1*110.0/100);
                HP1 = checkHP(HP1);
                if (M1 <= 0)
                {
                    M1 = 0;
                    break;
                }
            }
            if (EXP1 < 400)
            {
                M1 -= 200;
                EXP1 = ceil(EXP1*113.0/100);
                EXP1 = checkEXP(EXP1);
                if (M1 <= 0)
                {
                    M1 = 0;
                    break;
                }
            }
            else if (EXP1 >= 400)
            {
                M1 -= 120;
                EXP1 = ceil(EXP1*113.0/100);
                EXP1 = checkEXP(EXP1);
                if (M1 <= 0)
                {
                    M1 = 0;
                    break;
                }
            }
            if (EXP1 < 300)
            {
                M1 -= 100;
                EXP1 = ceil(EXP1*90.0/100);
                EXP1 = checkEXP(EXP1);
                if (M1 <= 0)
                {
                    M1 = 0;
                    break;
                }
            }
            else if(EXP1 >= 300)
            {
                M1 -= 120;
                EXP1 = ceil(EXP1*90.0/100);
                EXP1 = checkEXP(EXP1);
                if (M1 <= 0)
                {
                    M1 = 0;
                    break;
                }
            }
            break;
        }
    }
    else
    {
        while(M1 > 0)
        {
         if (HP1 < 200)
            {
                M1 -= 150;
                HP1 = ceil(HP1*130.0/100);
                HP1 = checkHP(HP1);
                if (M1 <= 0 || M1 < M6)
                {
                    if (M1 <= 0)
                    {
                    M1 = 0;
                    }
                    break;
                }
            }
            else if (HP1 >= 200)
            {
                M1 -= 70;
                HP1 = ceil(HP1*110.0/100);
                HP1 = checkHP(HP1);
                if (M1 <= 0 || M1 < M6)
                {
                    if (M1 <= 0)
                    {
                        M1 = 0;
                    }
                    break;
                }
            }
            if (EXP1 < 400)
            {
                M1 -= 200;
                EXP1 = ceil(EXP1*113.0/100);
                EXP1 = checkEXP(EXP1);
                if (M1 <= 0 || M1 < M6)
                {
                    if (M1 <= 0)
                    {
                    M1 = 0;
                    }
                    break;
                }
            }
            else if (EXP1 >= 400)
            {
                M1 -= 120;
                EXP1 = ceil(EXP1*113.0/100);
                EXP1 = checkEXP(EXP1);
                if (M1 <= 0 || M1 < M6)
                {
                    if (M1 <= 0)
                    {
                    M1 = 0;
                    }
                    break;
                }
            }
            if (EXP1 < 300)
            {
                M1 -= 100;
                EXP1 = ceil(EXP1*90.0/100);
                EXP1 = checkEXP(EXP1);
                if (M1 <= 0 || M1 < M6)
                {
                    if (M1 <= 0)
                    {
                    M1 = 0;
                    }
                    break;
                }
            }
            else if(EXP1 >= 300)
            {
                M1 -= 120;
                EXP1 = ceil(EXP1*90.0/100);
                EXP1 = checkEXP(EXP1);
                if (M1 <= 0 || M1 < M6)
                {
                    if (M1 <= 0)
                    {
                    M1 = 0;
                    }
                    break;
                }
            }
        }
    }
       HP1 = ceil(HP1*83.0/100);
       HP1 = checkHP(HP1);
       EXP1 = ceil(EXP1*117.0/100);
       EXP1 = checkEXP(EXP1);
       S = round(sqrt(EXP1));
       S = S * S;
    if (EXP1 >= S)
    {
        P2 = 100;
    } 
    else
    {
        P2 = ((double(EXP1)/S + 80)/123.0)*100;
    }
    //con duong so 3
    int n[10];
    n[0] = 32;
    n[1] = 47;
    n[2] = 28;
    n[3] = 79;
    n[4] = 100;
    n[5] = 50;
    n[6] = 22;
    n[7] = 83;
    n[8] = 64;
    n[9] = 11;
    if (E2 < 10)
    {
        P3 = n[E2];
    }
    else if (E2 >= 10 && E2 <= 99)
    {
        int c;
        c = (E2 % 10) + floor(E2/10);
        int kol;
        kol = c % 10;
        P3 = n[kol];
    }
    //Sau khi di het ca 3 tuyen duong
    double k;
    k = (P1 + P2 + P3)/3.0;
    if (k == 100)
    {
        EXP1 = ceil(EXP1*75.0/100);
        EXP1 = checkEXP(EXP1);
    }
    else if (k < 100 && k >= 50)
    {
        HP1 = ceil(HP1*90.0/100);
        HP1 = checkHP(HP1);
        EXP1 = ceil(EXP1*120.0/100);
        EXP1 = checkEXP(EXP1);
    }
    else if (k < 50)
    {
        HP1 = ceil(HP1*85.0/100);
        HP1 = checkHP(HP1);
        EXP1 = ceil(EXP1*115.0/100);
        EXP1 = checkEXP(EXP1);
}
return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) 
    return -99;
    HP2 = checkHP(HP2);
    int matrix[10][10] = {0};
    int ARS = 0, TOT = 0;
    for (int MCI = 0; MCI < 10; MCI++)
    {
        for (int MUN = 0; MUN < 10; MUN++)
        {
            matrix[MCI][MUN] = ((E3*MUN)+(MCI*2))*(MCI-MUN);
            if (matrix[MCI][MUN] > E3*2)
            {
                ARS++;
            }
            else if (matrix[MCI][MUN] < -E3)
            {
                TOT++;
            }
        }
    }
    if (ARS >= 10 && ARS <= 99)
    {
        ARS = (ARS % 10) + floor(ARS/10);
        if (ARS >= 10 && ARS <= 99)
        {
            ARS = (ARS % 10) + floor(ARS/10);
        }
    }
    if (TOT >= 10 && TOT <= 99)
    {
        TOT = (TOT % 10) + floor(TOT/10);
        if (TOT >= 10 && TOT <= 99)
        {
            TOT = (TOT % 10) + floor(TOT/10);
        }
    }
    int diemSherlockvaWatson = matrix[ARS][TOT];
    int diemtaxi = matrix[ARS][TOT];
    for (int MCI = 0; MCI < 10; MCI++)
    {
        for (int MUN = 0; MUN < 10; MUN++)
        {
            if ((MCI + MUN) == (ARS + TOT))
            {
                if (matrix[MCI][MUN] > diemSherlockvaWatson)
                {
                    diemSherlockvaWatson = matrix[MCI][MUN];
                }
            }
            if ((MCI - MUN) == (ARS - TOT))
            {
                if (matrix[MCI][MUN] > diemSherlockvaWatson)
                {
                    diemSherlockvaWatson = matrix[MCI][MUN];
                }
            }
        }
    }
    diemSherlockvaWatson = abs(diemSherlockvaWatson);
    if (abs(diemtaxi) > diemSherlockvaWatson)
    {
        EXP1 = ceil(EXP1*88.0/100);
        HP1 = ceil(HP1*90.0/100);
        EXP2 = ceil(EXP2*88.0/100);
        HP2 = ceil(HP2*90.0/100);
        EXP1 = checkEXP(EXP1);
        EXP2 = checkEXP(EXP2);
        HP1 = checkHP(HP1);
        HP2 = checkHP(HP2);
    return diemtaxi;
    }
    else 
    {
        EXP1 = ceil(EXP1*112.0/100);
        HP1 = ceil(HP1*110.0/100);
        EXP2 = ceil(EXP2*112.0/100);
        HP2 = ceil(HP2*110.0/100);
        EXP1 = checkEXP(EXP1);
        EXP2 = checkEXP(EXP2);
        HP1 = checkHP(HP1);
        HP2 = checkHP(HP2);
    return diemSherlockvaWatson;
    }
    
}

// Task 4
int checkPassword(const char* s, const char* email) {

    int length = 0;
    while (s[length] != '\0')
    {
        length++;
    }
    if (length < 8)
    {
       return -1;
    }
    else if (length > 20)
    {
        return -2;
    }
    const char* ptr;
    ptr = strchr(email, '@');
    char se[101];
    strncpy(se, email, ptr-email);
    se[ptr-email] = '\0';
    const char* bar;
    bar = strstr(s, se);
    if (bar != NULL)
    {
        int sei = bar-s;
        return -(300 + sei);
    }
    for (int i = 0; i < length - 2; i++)
    {
        if (s[i] == s[i+1] && s[i+1] == s[i+2])
        {
            int sci = i;
            return -(400 + sci);
        }
    }
    const char* specialCharss = "@#$%!";
    bool foundSpecialChar = false;
    for (int i = 0; i < length; i++)
    {
        if(strchr(specialCharss, s[i]))
        {
            foundSpecialChar = true;
            break;
        }
    }
    if (!foundSpecialChar)
        return -5;
    const char* validchars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#%$!";
    for (int i = 0; i < length; i++)
    {
        if (!strchr(validchars, s[i]))
        {
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char** arr_pwds, int num_pwds) {
    int* freq = new int[num_pwds];
    int max_freq = 0;
    int max_len = 0;
    int correct_pwd_index = 0;

    for (int i = 0; i < num_pwds; ++i) {
        for (int n = i + 1; n < num_pwds; ++n) {
            if (strcmp(arr_pwds[i], arr_pwds[n]) == 0) {
                freq[i]++;
            }
        }
        if (freq[i] > max_freq || (freq[i] == max_freq && strlen(arr_pwds[i]) > max_len)) {
            max_freq = freq[i];
            max_len = strlen(arr_pwds[i]);
            correct_pwd_index = i;
        }
    }

    return correct_pwd_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////