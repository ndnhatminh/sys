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
int sume(int n)
{
    int a, b;
    while (n >= 10)
    {
        a = n / 10;
        b = n % 10;
        n = a + b;
    }
    return n;
}
int cpnearest(int exp)
{
    int s, a = sqrt(exp);
    if (exp - pow(a, 2) < pow(a + 1, 2) - exp) s = pow(a, 2);
    else s = pow(a + 1, 2);
    return s;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 > 99 || e1 < 0) return -99;
    //TH1:
    if (e1 <= 3)
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
            exp2 += (29 + 45 +75);
            break;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = lamtron(exp1 + (float)D/200);
        else exp1 = lamtron(exp1 - (float)D/100);
        ktexp(exp1);
        ktexp(exp2);
    }
    //TH2:
    else if (e1 >= 4 && e1 <= 19) exp2 = lamtron(exp2 + (float)e1/4 + 19);
    else if (e1 >= 20 && e1 <= 49) exp2 = lamtron(exp2 + (float)e1/9 + 21);
    else if (e1 >= 50 && e1 <= 65) exp2 = lamtron(exp2 + (float)e1/16 + 17);
    else if (e1 >= 66 && e1 <= 79)
    {
        exp2 = lamtron(exp2 + (float)e1/4 + 19);
        if (exp2 > 200) exp2 = lamtron(exp2 + (float)e1/9 + 21);
    }
    else 
    {
        exp2 = lamtron(exp2 + (float)e1/4 + 19);
        exp2 = lamtron(exp2 + (float)e1/9 + 21);
        if (exp2 > 400)
        {
            exp2 = lamtron(exp2 + (float)e1/16 + 17);
            exp2 = lamtron(exp2 * 1.15);
        }
    }
    if (e1 > 3) exp1 -= e1;
    ktexp(exp1);
    ktexp(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 > 99 || E2 < 0) return -99;
    //Con duong 01
    float p1, p2, p3;
    int S = cpnearest(EXP1);
    if (EXP1 >= S) p1 = 100;
    else p1 = ((float)EXP1 / S + 80) / 123 * 100;
    //Con duong 02
    bool out = false;
    if (M1 == 0) out = true;
    if (E2 % 2 != 0)
    {
       
        /*while (!out)
        {
            int gia, them;
            if (HP1 < 200)
            {
                HP1 = lamtron(HP1 * 1.3);
                M1 -= 150;
                chi += 150;
            }
            else
            {
                HP1 = lamtron(HP1 * 1.1);
                M1 -= 70;
                chi += 70;
            }
            if (chi > M1/2 || M1 <= 0) out = true;
            if (EXP1 < 400)
            {
                M1 -= 200;
                chi += 200;
            }
            else 
            {
                M1 -= 120;
                chi += 120;
            }
            EXP1 = lamtron(EXP1 * 1.13);
            ktexp(EXP1);
            if (EXP1 < 300)
            {
                M1 -= 100;
                chi += 100;
            }
            else
            {
                M1 -= 120;
                chi += 120;
            }
            EXP1 = lamtron(EXP1 * 0.9);
        }*/
        int chi = 0;
        float half = float(M1)/2;
        while (!out)
        {
            int gia;
            float doi;
            if (HP1 < 200) 
            {
                gia = 150;
                doi = 1.3;
            }
            else
            {
                gia = 70;
                doi = 1.1;
            }
            HP1 = lamtron(HP1 * doi);
            kthp(HP1);
            M1 -= gia;
            chi += gia;
            if (chi > half || M1 <= 0) out = true;
            if (!out)
            {
                if (EXP1 < 400) gia = 200;
                else gia = 120;
                M1 -= gia;
                chi += gia;
                EXP1 = lamtron(EXP1 * 1.13);
                ktexp(EXP1);
                if (chi > half || M1 <= 0) out = true;
                if (!out)
                {
                    if (EXP1 < 300) gia = 100;
                    else gia = 120;
                    chi += gia;
                    M1 -= gia;
                    EXP1 = lamtron(EXP1 * 0.9);
                    if (chi > half || M1 <= 0) out = true;
                }
            }
        }
    }
    else
    {
        if (!out)
        {
            int gia;
            float doi;
            if (HP1 < 200) 
            {
                gia = 150;
                doi = 1.3;
            }
            else
            {
                gia = 70;
                doi = 1.1;
            }
            HP1 = lamtron(HP1 * doi);
            kthp(HP1);
            M1 -= gia;
            if (M1 <= 0) out = true;
            if (!out)
            {
                if (EXP1 < 400) gia = 200;
                else gia = 120;
                M1 -= gia;
                EXP1 = lamtron(EXP1 * 1.13);
                ktexp(EXP1);
                if (M1 <= 0) out = true;
                if (!out)
                {
                    if (EXP1 < 300) gia = 100;
                    else gia = 120;
                    M1 -= gia;
                    EXP1 = lamtron(EXP1 * 0.9);
                    if (M1 <= 0) out = true;
                }
            }
        }
    }
    kttien(M1);
    HP1 = lamtron(HP1 * 0.83);
    EXP1 = lamtron(EXP1 * 1.17);
    ktexp(EXP1);
    S = cpnearest(EXP1);
    if (EXP1 >= S) p2 = 100;
    else p2 = ((float)EXP1 / S + 80) / 123 * 100;
    //Con duong 03
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10) p3 = P[E2];
    else 
    {
        int a = E2 / 10, b = E2 % 10;
        p3 = P[(a + b) % 10];
    }
    if (p1 == 100 && p2 == 100 && p3 == 100)
    EXP1 = lamtron(EXP1 * 0.75);
    else
    {
        float tb = (p1 + p2 + p3) / 3;
        if (tb < 50) 
        {
            HP1 = lamtron(HP1 * 0.85);
            EXP1 = lamtron(EXP1 * 1.15);
            ktexp(EXP1);
        }
        else 
        {
            HP1 = lamtron(HP1 * 0.9);
            EXP1 = lamtron(EXP1 * 1.2);
            ktexp(EXP1);   
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 > 99 || E3 < 0) return -99;
    int map[10][10], h = 0, c = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            map[i][j] = (E3 * j + i * 2) * (i - j);
            if (map[i][j] > E3 * 2) h += 1;
            else if (map[i][j] < -E3) c += 1;
        }
    h = sume(h);
    c = sume(c);
    int i = 0, j = 0;
    //cheo trai
    if (h < c) j = c - h;
    else i = h - c;
    int max = map[i][j];
    while (i < 9 && j < 9)
    {
        if (max < map[i + 1][j + 1]) max = map[i + 1][j + 1];
        i++;
        j++;
    }
    //cheo phai
    i = 9;
    j = 0;
    if (9 - h > c) i = h + c;
    else j = c - (9 - h);
    while (i >= 0 && j < 10)
    {
        if (max < map[i][j]) max = map[i][j];
        i--;
        j++;
    }
    int kq = map[h][c];
    float doihp, doiexp;
    if (abs(max) >= abs(map[h][c]))
    {
        kq = abs(max);
        doihp = 1.1;
        doiexp = 1.12;
    }
    else 
    {
        doihp = 0.9;
        doiexp = 0.88;
    }
    HP1 = lamtron(HP1 * doihp);
    HP2 = lamtron(HP2 * doihp);
    EXP1 = lamtron(EXP1 * doiexp);
    EXP2 = lamtron(EXP2 * doiexp);
    kthp(HP1);
    kthp(HP2);
    ktexp(EXP1);
    ktexp(EXP2);
    return kq;
    //return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int cd = strlen(s);
    if (cd < 8) return -1;
    if (cd > 20) return -2;
    char se[cd] = "";
    int i = 0;
    while (email[i] != 64)
    {
        se[i] = email[i];
        i++;
    }
    bool cse = false;
    int sei = 0;
    while (sei < (cd - i + 1) && !cse)
    {
        int j = 0;
        while (0 <= j && j < i)
        {
            if (s[j + sei] != se[j]) j = -1;
            else j++;
        }
        if (j == i) cse = true;
        else sei++;
    }
    if (cse) return -(300 + sei);
    int sci = 0, count = 1;
    i = 0;
    while (i < cd - 1 && count < 3)
    {
        if (s[i] == s[i + 1]) count += 1;
        else 
        {
            sci = i + 1;
            count = 1;
        }
        i++;
    }
    if (count == 3) return -(400 + sci);
    i = 0;
    while (0 <= i && i < cd)
    {
        if (s[i] == 64 || s[i] == 33 || (35 <= s[i] && s[i] <= 37)) i = -1;
        else i++;
    }
    if (i == cd) return -5;
    i = 0;
    bool vp = false;
    while (!vp && i < cd)
    {
        if ((64 <= s[i] && s[i] <= 90) || (97 <= s[i] && s[i] <= 122) || (48 <= s[i] && s[i] <= 57) || s[i] == 33 || (35 <= s[i] && s[i] <= 37)) i++;
        else vp = true;
    }
    if (vp) return i;
    return -10;
    //return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int i = 0, ktm = 0;
    int xhmax = 1, xh;
    string pw[30];
    int vt[30];
    while (i < num_pwds)
    {
        xh = 1;
        for (int j = i + 1; j < num_pwds; j++)
        if (arr_pwds[i] == arr_pwds[j]) xh += 1;
        if (xh == xhmax)
        {
            pw[ktm] = arr_pwds[i];
            vt[ktm] = i;
            ktm++;
        }
        else if (xh > xhmax)
        {
            xhmax = xh;
            ktm = 0;
            vt[ktm] = i;
            pw[ktm] = arr_pwds[i];
            ktm += 1;
        }
        i++;
    }
    int vtpw = 0, max = pw[vtpw].length();
    for (int j = 1; j < ktm; j++)
        {
            if (pw[j].length() > max)
            {
                max = pw[j].length();
                vtpw = j;
            }
        }
    return vt[vtpw];
}

int lamtron( float a) {
    return int(a + 0.999);
}
/*int lamtron( float a) {
    int hp;
    if (a - int(a) > 0) hp = a + 1;
    else hp = a;
    return hp;
}*/
void kthp(int & hp) {
    if (hp < 0) hp = 0;
    else if (hp > 666) hp = 666;
}
void ktexp(int & exp) {
    if (exp < 0) exp = 0;
    else if (exp > 600) exp = 600;
}
void kttien(int & tien) {
    if (tien < 0) tien = 0;
    else if (tien > 3000) tien = 3000;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////