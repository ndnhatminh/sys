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

//Ham gioi han
int lim(int so, int gh)
{
    if (so <= 0) so = 0;
    else if (so > gh) so = gh;
    return so;
}
// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1)
{
    int D;
    int gh = 600;
    if (E1 >= 0 && E1 <= 99)
    {
        //ktra ghan Exp
        
        EXP1 = lim(EXP1, gh);
        EXP2 = lim(EXP2, gh);
        if ((E1 >= 0) && (E1 <= 3))
        {
            if (E1 == 0) EXP2 += 29;
            else if (E1 == 1) EXP2 += 45;
            else if (E1 == 2) EXP2 += 75;
            else if (E1 == 3) EXP2 += 149;
            D = E1 * 3 + EXP1 * 7;
            if (D % 2 == 0) EXP1 = ceil(EXP1 + D / 200.0f);
            else EXP1 = ceil(EXP1 - D / 100.0f);
            EXP1 = lim(EXP1, gh);
            EXP2 = lim(EXP2, gh);
        }
        else if (E1 <= 99)
        {
            if (E1 <= 19) EXP2 = ceil(EXP2 + E1 / 4.0f + 19);
            else if (E1 <= 49) EXP2 = ceil(EXP2 + E1 / 9.0f + 21);
            else if (E1 <= 65) EXP2 = ceil(EXP2 + E1 / 16.0f + 17);
            else if (E1 <= 79)
            {
                EXP2 = ceil(EXP2 + E1 / 4.0f + 19);
                if (EXP2 > 200) EXP2 = ceil(EXP2 + E1 / 9.0f + 21);
            }
            else
            {
                EXP2 = ceil(EXP2 + E1 / 4.0f + 19);
                EXP2 = ceil(EXP2 + E1 / 9.0f + 21);
                if (EXP2 > 400)
                {
                    EXP2 = ceil(EXP2 + E1 / 16.0f + 17);
                    EXP2 = ceil(EXP2 * 1.15f);
                }
            }
            EXP1 -= E1;
            EXP1 = lim(EXP1, gh);
            EXP2 = lim(EXP2, gh);
        }
        return EXP1 + EXP2;
    }
    else
    {
        E1 = -99;
        return E1;
    }
}

//Ham xac xuat
float cpgn(int EXP)
{
    int x, y, z, S;
    float P1;
    x = sqrt(EXP);
    y = pow(x, 2);
    z = pow((x + 1), 2);
    if ((EXP - y) > (z - EXP)) S = z;
    else S = y;
    if (S <= EXP) P1 = 1;
    else P1 = (((float)EXP / (float)S) + 80) / 123;
    return P1;
}

//Ham su kien road 2
void event1(int& HP1, int& EXP1, int& M1)
{
    int ghhp = 666, ghexp = 600, ghm = 3000;
    HP1 = lim(HP1, ghhp);
    EXP1 = lim(EXP1, ghexp);
    M1 = lim(M1, ghm);
    if (HP1 < 200)
    {
        HP1 = ceil(HP1 * 1.3f);
        M1 -= 150;
    }
    else
    {
        HP1 = ceil(HP1 * 1.1f);
        M1 -= 70;
    }
    HP1 = lim(HP1, ghhp);
    EXP1 = lim(EXP1, ghexp);
    M1 = lim(M1, ghm);
}

void event2(int& HP1, int& EXP1, int& M1)
{
    int ghhp = 666, ghexp = 600, ghm = 3000;
    HP1 = lim(HP1, ghhp);
    M1 = lim(M1, ghm);
    EXP1 = lim(EXP1, ghexp);
    if (EXP1 < 400) 
        M1 -= 200;
    else 
        M1 -= 120;
    EXP1 = ceil(EXP1 * 1.13f);
    M1 = lim(M1, ghm);
    EXP1 = lim(EXP1, ghexp);
    HP1 = lim(HP1, ghhp);
}

void event3(int& HP1, int& EXP1, int& M1)
{
    int ghhp = 666, ghexp = 600, ghm = 3000;
    HP1 = lim(HP1, ghhp);
    EXP1 = lim(EXP1, ghexp);
    M1 = lim(M1, ghm);
    if (EXP1 < 300) 
        M1 -= 100;
    else 
        M1 -= 120;
    EXP1 = ceil(EXP1 * 0.9f);
    HP1 = lim(HP1, ghhp);
    EXP1 = lim(EXP1, ghexp);
    M1 = lim(M1, ghm);
}
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
    if (E2 < 0 || E2 > 99) return -99;
    float P1, P2;
    int T;
    int ghhp = 666, ghexp = 600, ghm = 3000, i;
    HP1 = lim(HP1, ghhp);
    EXP1 = lim(EXP1, ghexp);
    M1 = lim(M1, ghm);
    if (E2 >= 0 && E2 <= 99)
    { 
        HP1 = lim(HP1, ghhp);
        EXP1 = lim(EXP1, ghexp);
        M1 = lim(M1, ghm);

        //road 1
        P1 = cpgn(EXP1);  //p1=1

        //road 2
        const int im = ceil(M1 / 2.0f);
        while (E2 % 2 != 0)
        {
            event1(HP1, EXP1, M1);
            if ((im * 2 - M1) > im) goto stop; 
            event2(HP1, EXP1, M1);
            if ((im * 2 - M1) > im) goto stop;
            event3(HP1, EXP1, M1);
            if ((im * 2 - M1) > im) goto stop;
        }
        if (E2 % 2 == 0)
        {
            if (M1 == 0) goto stop;
            event1(HP1, EXP1, M1);
            if (M1 == 0) goto stop;
            event2(HP1, EXP1, M1);
            if (M1 == 0) goto stop;
            event3(HP1, EXP1, M1);
            goto stop;
        }
        stop: HP1 = ceil(HP1 * 0.83f); EXP1 = ceil(EXP1 * 1.17f);
        EXP1 = ceil(EXP1);
        HP1 = ceil(HP1);
        HP1 = lim(HP1, ghhp);
        EXP1 = lim(EXP1, ghexp);
        M1 = lim(M1, ghm);

        P2 = cpgn(EXP1);

        //road 3
        float P3[10] = { 0.32, 0.47, 0.28, 0.79, 1.00, 0.50, 0.22, 0.83, 0.64, 0.11};
        if (E2 <= 9) i = E2;
        else i = ((E2 / 10) + (E2 % 10)) % 10;

        //conclusion
        float P = (P1 + P2 + P3[i]) / 3.0f;
        if (P == 1) EXP1 = ceil(EXP1 * 0.7499999f);
        else if (P < 0.5f)
        {
            HP1 = ceil(HP1 * 0.8499999f);
            EXP1 = ceil(EXP1 * 1.1499999f);
        }
        else if (P >= 0.5)
        {
            HP1 = ceil(HP1 * 0.8999999f);
            EXP1 = ceil(EXP1 * 1.1999999f);
        }
        HP1 = lim(HP1, ghhp);
        EXP1 = lim(EXP1, ghexp);
        M1 = lim(M1, ghm);
        T = HP1 + EXP1 + M1;
        return T;
    }
    return T;
}
//Ham ma tran
void matrix(int A[10][10], int E)
{
    int i, j;
    for (i = 0; i <= 9; i += 1)
    {
        for(j = 0; j <= 9; j += 1)
        {
            A[i][j] = ((E * j) + (i * 2)) * (i - j);
        }   
    }  
}

//Ham tim kiem i
int searchi(int A[10][10], int E)
{
    int i, j, B = 0;
    for (i = 0; i <= 9; i += 1)
    {
        for(j = 0; j <= 9; j += 1)
        {
            if(A[i][j] > E * 2) ++B;
        }   
    }
    while (B >= 10) 
    {
        B = (B / 10) + (B % 10);  
    }
    return B;   // I
}

//Ham tim kiem j
int searchj(int A[10][10], int E)
{
    int i, j, B = 0;
    for (i = 0; i <= 9; i += 1)
    {
        for(j = 0; j <= 9; j += 1)
        {
            if(A[i][j] < (-E)) ++B;
        }   
    }
    while (B >= 10) 
    {
        B = (B / 10) + (B % 10); 
    }
    return B;   // J
}

//Ham tim kiem gtri lon nhat trong duong cheo
int searchdc(int A[10][10], int m, int n, int big)
{
    int x = m, y = n;
    big = 0;
    for (;m <= 9;m++)                                        // duoi phai
    {
            if (A[m][n] > big) big = A[m][n];
            if (n == 9) break;
            n++;
    }
    m = x; n = y;
    for (;m <= 9;m++)                                        // duoi trai
    {
            if (A[m][n] > big) big = A[m][n];
            if (n == 0) break;
            n--;
            
    }
    m = x; n = y;
    for (;m >= 0;m--)                                        // tren phai
    {

            if (A[m][n] > big) big = A[m][n];
            if (n == 9) break;
            n++;
    }
    m = x; n = y;
    for (;m >= 0;m--)                                       // tren trai
    {
        
            if (A[m][n] > big) big = A[m][n];
            if (n == 0) break;
            n--;
    }
    return big;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) 
{
    // TODO: Complete this function
    int ghhp = 666, ghexp = 600;
    int m, n, x, y, A[10][10], B, ret;
    if (E3 >= 0 && E3 <= 99)
    {
        matrix(A, E3);
        m = searchi(A, E3);
        n = searchj(A, E3);
        x = m;
        y = n; 
        B = searchdc(A, x, y, B);
        if (abs(A[x][y]) > B)
        {
            EXP1 = ceil(EXP1 * 0.88f);
            HP1 = ceil(HP1 * 0.90f);
            EXP2 = ceil(EXP2 * 0.88f);
            HP2 = ceil(HP2 * 0.90f);
            ret = A[m][n];
        }
        else
        {
            EXP1 = ceil(EXP1 * 1.12f);
            HP1 = ceil(HP1 * 1.10f);
            EXP2 = ceil(EXP2 * 1.12f);
            HP2 = ceil(HP2 * 1.10f);
            
            HP1 = lim(HP1, ghhp);
            EXP1 = lim(EXP1, ghexp);
            HP2 = lim(HP2, ghhp);
            EXP2 = lim(EXP2, ghexp);
            ret = B; 
        }
        if (E3 == 0) 
        {
            ret = 0;
        }
        return ret;
        
    }
    else return -99;
}

//dkien s[]
int passcheck(string s)
{   
    int i, j, c;
    string correct = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@#%$!";
    for (i = 0; i < s.length(); i++)
    {
        c = 0;
        for (j = 0; j < correct.length(); j++)
        {
            if (s[i] == correct[j]) break;
            else c += 1;
        }
        if (c == correct.length()) return i; //tra ve vtri sai
    }
    return -10;
}

// Task 4
int checkPassword(const char* s, const char* email) 
{
    // TODO: Complete this function
    int P, PL, EL, r, T = 0;
    int j = 0, i = 0, x, y;
    string se, email1 = email, s1 = s;
    PL = s1.length(); //length mkhau
    EL = email1.length(); //length mail    
    while (i < EL)
        {
            if (email1[i] == '@') break;
            ++i;
                    //se: email truoc @; s: mkhau
        }
    se = email1.substr(0,i);
    int G = i;
    if (PL < 8) return -1;                                              //line2
    
    else if (PL > 20) return -2;                                        //line3
    
    if (G == 0) return -300;
    
    int A = s1.find(se);            //A: tim chuoi 'se' trong 's'
    if (A >= 0) return -(300 + A);                                      //line4
    
    for (int m = 0; m < PL; ++m)
    {
        if (s1[m] == s1[m+1] && s1[m+1] == s1[m+2]) return -(400 + m);  //line5
    }

    int n;
    for (int i = 0; i < PL; ++i)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        { 
            n = 1; 
            break; 
        }
        else n = 2;
    }
    if (n == 2) return -5;                                              //line6

    int Q = passcheck(s1);                                               //line7
    return Q;    
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) 
{
    // TODO: Complete this function
    string arr_pwds1[num_pwds];
    
    for (int i = 0; i < num_pwds; i++)
    {
        arr_pwds1[i] = arr_pwds[i];
    }


    int d, c, z[num_pwds];
    for (int i = 0; i < num_pwds; i++)
    {
        c = 1;
        for(int j = i + 1; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i],arr_pwds[j]) == 0)
            {
                c += 1;
            }
        }
    z[i] = c;                    
    }
    
    d = 0;
    int max = 1, length = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        if (z[i] >= max) 
        {
            max = z[i];             //tim tan so nhieu nhat
        }
    }
    string equal[num_pwds];
    int g = 0;
    for (int i = 0; i < num_pwds; i++)
    {        
        if (z[i] == max) 
        {
            equal[g] = arr_pwds1[i];    //tim cac mkhau co tan so lon nhat
        }
        else equal[g] = '0';
        g++;
        for (int j = 0; j < num_pwds; j++)
        {
            if (equal[i].length() > length)
            {
                length = equal[i].length();
                d = i;
            }
        }
    }

    
    return d;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////