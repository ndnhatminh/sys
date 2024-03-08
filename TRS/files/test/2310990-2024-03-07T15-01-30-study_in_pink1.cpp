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

// xu li du lieu
float HP(float a)
{
    if (a != int(a)) a = ceil(a);
    if (a > 666) a = 666;
    else if (a < 0) a = 0;
    return a;
}
float EXP(float a)
{
    if (int(a) != a) a = ceil(a);
    if (a > 600) a = 600;
    else if (a < 0) a = 0;
    return a;
}
float M(float a)
{
    if (int(a) != a)
        a = ceil(a);
    if (a > 3000) a = 3000;
    else if (a < 0) a = 0;
    return a;
}
// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    
    exp1 = EXP(exp1);
    exp2 = EXP(exp2);
    float EXP2 = exp2;
    float EXP1 =exp1;
    if ((e1 < 0) || (e1 > 99))return -99;
    else
    {
        if ((e1 >= 0) && (e1 <= 3))
        {
            if (e1 == 0) EXP2  += 29;
            else if (e1 == 1)
                EXP2+= 45;
            else if (e1 == 2)
                EXP2+= 75;
            else if (e1 == 3)
                EXP2 += 29 + 45 + 75;
            int  D = e1 * 3 + EXP1 * 7;
            if (D % 2 == 0)
                EXP1  += (float)D / 200;
            else
                EXP1 -= (float)D / 100;
            exp1 = EXP(EXP1);
            exp2 = EXP(EXP2);
        }
        
        if ((e1 >= 4) && (e1 <= 99))
        {
            if (e1 < 20)
            {
                EXP2 += (float)e1 / 4 + 19;
                EXP2 = EXP(EXP2);
            }
            else if (e1 < 50)
            {
                EXP2 += (float)e1 / 9 + 21;
                EXP2 = EXP(EXP2);
            }
            else if (e1 < 66)
            {
                EXP2 += (float)e1 / 16 + 17;
                EXP2 = EXP(EXP2);
            }
            else if (e1 < 80)
            {
                EXP2 += (float)e1 / 4 + 19;
                EXP2 = EXP(EXP2);
                if (EXP2 > 200)
                    EXP2 += (float)e1 / 9 + 21;
            }
            else
            {
                EXP2 += (float)e1 / 4 + 19;
                EXP2 = EXP(EXP2);
                EXP2 += (float)e1 / 9 + 21;
                EXP2 = EXP(EXP2);
                if (EXP(EXP2) > 400)
                {
                    EXP2 += (float)e1 / 16 + 17;
                    EXP2 = EXP(EXP2);
                    EXP2 = EXP2 * 1.15;
                    EXP2 = EXP(EXP2);
                }
            }
            EXP1 -= e1;
            exp1 = EXP(EXP1);
            exp2 = EXP(EXP2);
        }
        return exp1 + exp2;
    }
}
// tao ham tim so chinh phuong gan nhat
int chinhphuong(int a)
{
    int b;
    int d;
    for (int i = a; i <= 600; i++)
    {

        int e = sqrt(i);
        if (e * e == i)
        {
            b = i;
            break;
        }

    }
    for (int i = a; i >= 0; i--)
    {
        int f = sqrt(i);

        if (f * f == i)
        {
            d = i;
            break;
        }


    }
    if (a - d > b - a) a = b;
    else a = d;
    return a;
}
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    float hp1 = HP(HP1);
    float exp1 = EXP(EXP1);
    float m1 = M(M1); double P1, P2, P3;
    if ((E2 < 0) || (E2 > 99))
        return -99;
    else
    {
        //TINH P1
        int S1 = chinhphuong(EXP1);
        if (S1 <= exp1)
            P1 = 100;
        else P1 = 100 * (double)((double)exp1 / S1 + 80) / 123;
        int m = 0; float N = (float)0.5 * M1;
        //TINH P2 TRUONG HOP E2 LE
        if (E2 % 2 == 1)
        {
            while (m <= N)
            {
                if (hp1 < 200)
                {
                    m = m + 150;
                    if (m1 != 0)
                    {
                        m1 -= 150;
                        hp1 += 0.3 * hp1;
                        hp1 = HP(hp1);
                        exp1 = EXP(exp1);
                        m1 = M(m1);
                        if (m > N)
                        {
                            hp1 -= 0.17 * hp1;
                            exp1 += 0.17 * exp1;
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    m = m + 70;
                    if (m1 != 0)
                    {
                        m1 -= 70;
                        hp1 += 0.1 * hp1;
                        hp1 = HP(hp1);
                        exp1 = EXP(exp1);
                        m1 = M(m1);
                        if (m > N)
                        {
                            hp1 -= 0.17 * hp1;
                            exp1 += 0.17 * exp1;
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                if (exp1 < 400)
                {
                    m = m + 200;
                    if (m1 != 0)
                    {
                        m1 -= 200;
                        exp1 = 1.13 * exp1;
                        hp1 = HP(hp1);
                        exp1 = EXP(exp1);
                        m1 = M(m1);
                        if (m > N)
                        {
                            hp1 -= 0.17 * hp1;
                            exp1 += 0.17 * exp1;
                            break;
                        }
                    }
                    else
                    {

                        break;
                    }
                }
                else
                {
                    m = m + 120;
                    if (m1 != 0)
                    {
                        m1 -= 120;
                        exp1 = 1.13 * exp1;
                        hp1 = HP(hp1);
                        exp1 = EXP(exp1);
                        m1 = M(m1);
                        if (m > N)
                        {
                            hp1 -= 0.17 * hp1;
                            exp1 += 0.17 * exp1;
                            break;
                        }
                    }
                    else
                    {

                        break;
                    }
                }
                if (exp1 < 300)
                {
                    m += 100;
                    if (m1 != 0)
                    {
                        m1 -= 100;
                        exp1 = 0.9 * exp1;
                        hp1 = HP(hp1);
                        exp1 = EXP(exp1);
                        m1 = M(m1);
                        if (m > N)
                        {
                            hp1 -= 0.17 * hp1;
                            exp1 += 0.17 * exp1;
                            break;
                        }
                    }
                    else
                    {

                        break;
                    }
                }
                else
                {
                    m += 120;
                    if (m1 != 0)
                    {
                        m1 -= 120;
                        exp1 = 0.9 * exp1;

                        hp1 = HP(hp1);
                        exp1 = EXP(exp1);
                        m1 = M(m1);
                        if (m > N)
                        {
                            hp1 -= 0.17 * hp1;
                            exp1 += 0.17 * exp1;
                            break;
                        }
                    }
                    else
                    {

                        break;
                    }

                }
            }
        }
        // TINH P2 TH E2 CHAN
        else
        {
            if (m1 > 0)
            {

                if (hp1 < 200)
                {
                    m1 -= 150;
                    hp1 += 0.3 * hp1;
                    hp1 = HP(hp1);
                    exp1 = EXP(exp1);
                    m1 = M(m1);

                }
                else
                {
                    m1 -= 70;
                    hp1 += 0.1 * hp1;
                    hp1 = HP(hp1);
                    exp1 = EXP(exp1);
                    m1 = M(m1);
                }
            }
            
            if (m1 > 0)
            {
                if (exp1 < 400)
                {
                    m1 -= 200;
                    exp1 = 1.13 * exp1;
                    hp1 = HP(hp1);
                    exp1 = EXP(exp1);
                    m1 = M(m1);
                }
                else
                {
                    m1 -= 120;
                    exp1 = 1.13 * exp1;
                    hp1 = HP(hp1);
                    exp1 = EXP(exp1);
                    m1 = M(m1);
                }
            }
            

            if (m1 > 0)
            {
                if (exp1 < 300)
                {
                    m1 -= 100;
                    exp1 = 0.9 * exp1;
                    hp1 = HP(hp1);
                    exp1 = EXP(exp1);
                    m1 = M(m1);
                }
                else
                {
                    m1 -= 120;
                    exp1 = 0.9 * exp1;
                    hp1 = HP(hp1);
                    exp1 = EXP(exp1);
                    m1 = M(m1);
                }
                
            }
            hp1 -= 0.17 * hp1;
            exp1 += 0.17 * exp1;
        }
        hp1 = HP(hp1);
        exp1 = EXP(exp1);
        m1 = M(m1);
        int S2 = chinhphuong(exp1);
        if (S2 <= exp1)
            P2 = 100;
        else P2 = 100 * (float)(((float)exp1 / S2 + 80) / 123);
        // TINH P3
        int P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        if (E2 < 10)
        {
            P3 = P[E2];
        }
        else
        {
            int a = E2 % 10;
            int b = E2 / 10;
            int c = (a + b) % 10;
            P3 = P[c];
        }
        if (P1 + P2 + P3 == 300)
        {
            exp1 = 0.75 * exp1;
        }
        else
        {
            float xacsuat = (P1 + P2 + P3) / 3;
            if (xacsuat < 50)
            {
                hp1 -= 0.15 * hp1;
                exp1 += 0.15 * exp1;
            }
            else
            {
                hp1 = 0.9 * hp1;
                exp1 = 1.2 * exp1;
            }
        }
        EXP1 = EXP(exp1);
        HP1 = HP(hp1);
        M1 = M(m1);
        return HP1 + EXP1 + M1;
    }
}
int rutgon(int a)
{
    while (a > 9)
        a = (int)a % 10 + (int)a / 10;
    return a;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    int a[10][10];
    if ((E3 < 0) || (E3 > 99)) return -99;
    else
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        int s1 = 0, s2 = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (a[i][j] > E3 * 2)
                {
                    s1 += 1;
                }
                if (a[i][j] < -E3)
                {
                    s2 += 1;
                }
            }
        }
        s1 = rutgon(s1); s2 = rutgon(s2);
        int taxi = a[s1][s2];

        // duong cheo phai
        int max2;
        if (s1 < 9 - s2)
        {
            max2 = a[0][s2 + s1];
            for (int i = 0; i <= s2 + s1; i++)
            {
                if (max2 < a[i][s2 + s1 - i]) max2 = a[i][s1 + s2 - i];
            }
        }
        else
        {
            max2 = a[s1 - 9 + s2][9];
            for (int i = 0; i <= 9 - s1 + 9 - s2; i++)
            {
                if (max2 < a[s1 + s2 - 9 + i][9 - i]) max2 = a[s1 + s2 - 9 + i][9 - i];
            }
        }
        // duong cheo trai 
        int max1;
        if (9 - s1 > 9 - s2)
        {
            max1 = a[s1 + 9 - s2][9];
            for (int i = 0; i <= s1 - s2 + 9; i++)
            {
                if (max1 < a[s1 - s2 + 9 - i][9 - i]) max1 = a[s1 - s2 + 9 - i][9 - i];
            }
        }
        else
        {
            max1 = a[9][s2 + 9 - s1];
            for (int i = 0; i <= s2 + 9 - s1; i++)
            {
                if (max1 < a[9 - i][s2 + 9 - s1 - i]) max1 = a[9 - i][s2 + 9 - s1 - i];
            }
        }
        int max;
        if (max1 > max2) max = max1;
        else max = max2;
        if (abs(taxi) > abs(max))
        {
            EXP1 = EXP((float)EXP1 * 0.88);
            EXP2 = EXP((float)EXP2 * 0.88);
            HP1 = HP((float)HP1 * 0.9);
            HP2 = HP((float)HP2 * 0.9);
            return taxi;
        }
        else
        {
            EXP1 = EXP((float)EXP1 * 1.12);
            EXP2 = EXP((float)EXP2 * 1.12);
            HP1 = HP((float)HP1 * 1.1);
            HP2 = HP((float)HP2 * 1.1);
            return abs(max);
        }
    }
}
int count(const char* s)
{
    int b = -1;
    for (int i = 0; i < strlen(s) - 2; i++)
    {
        if ((s[i] == s[i + 1]) && (s[i] == s[i + 2]))
        {
            b = i;
            break;
        }
    }
    return b;
}
int dacbiet(const char* s) {
    int a = 0;
    char b[] = {'@','#','%','$','!'};
    for (int i = 0; i < strlen(s); i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (b[j] == s[i])
            {
                a = 1;
                break;
            }
        }
    }
    if (a == 0) return -5;
    else return 5;
}
int se(const char* s, const char* email)
{
    int a = 0;
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] != '@')
        {
            a += 1;
        }
        else break;
    }
    char b[100];
    strncpy(b, email + 0, a);
    b[a] = '\0';
    const char* k = strstr(s, b);
    int x = -2;
    if (k == NULL) return -2;
    else
    {
        x = k - s;
        return -(300 + x);
    }
}
// kiem tra xem chuoi mat khau co dung yeu cau ve mat nhung ki tu duoc cho phep hay khong
int check(const char* s) {
    int a;
    for (int i = 0; i < strlen(s); i++)
    {
        if ((s[i] >= 'a') && (s[i] <= 'z')) a = -1;
        else if ((s[i] >= 'A') && (s[i] <= 'Z')) a = -2;
        else if ((s[i] >= '0') && (s[i] <= '9')) a = -3;
        else if ((s[i] == '@') || (s[i] == '#')
            || (s[i] == '%') || (s[i] == '$') || (s[i] == '!')) a = -4;
        else
        {
            a = i;
            break;
        }
    }
    return a;
}
// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    if (strlen(s) < 8) return -1;
    else if (strlen(s) > 20) return -2;
    else if (se(s, email) != -2) return se(s, email);
    else if (count(s) != -1) return -(400 + count(s));
    else if (dacbiet(s) == -5) return -5;
    else if (check(s) >= 0) return check(s);
    else return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int k = 0;
    int a[200]; a[num_pwds] = '\0';
    // tao mang so lan xuat hien tuong ung vi tri 
    for (int i = 0; i < num_pwds; i++)
    {
        for (int j = 0; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i] , arr_pwds[j])==0)
                k += 1;
        }
        a[i] = k;
        k = 0;
    }
    int c = 0; int d[200]; 
    int  max = a[0];
    // tim max 
    for (int i = 0; i < num_pwds; i++)
    {
        if (max < a[i]) max = a[i];
    }
    // dem so lan xuat hien max, tao mang danh dau vi tri xuat hien max
    for (int i = 0; i < num_pwds; i++)
    {
        if (max == a[i]) {
            c += 1;
            d[c - 1] = i;
        }
    }
    int e; d[c] = '\0';
    int mimi = strlen(arr_pwds[d[0]]);
    // tim do dai chuoi lon nhat trong tap hop max
    for (int i = 0; i < c; i++)
    {
        if (strlen(arr_pwds[d[i]]) > mimi)
        {
            mimi = strlen(arr_pwds[d[i]]);
        }
    }
    for (int i = 0; i < c; i++)
    {
        if (strlen(arr_pwds[d[i]]) == mimi)
        {
            e = d[i];
            break;
        }
    }
    return e;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
// CAU MONG MUOI PHUONG CHU PHAT ANH HAO QUANG CHIEU ROI PHU HO EM DAT DIEM CAO A.
// CAU MONG 10 DIEM, TIEN DO GAM VOC, TUONG LAI RANG RO.
////////////////////////////////////////////////