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

int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1<0 || e1 >99) e1 = -99; 
    if (e1 == -99) return -99;    
    if (exp1<0) exp1 = 0;
    if (exp1>600) exp1 = 600;
    if (exp2<0) exp2 = 0;
    if (exp2>600) exp2 = 600;
 
    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0) exp2 += 29;
        else if (e1 == 1) exp2 += 45;
        else if (e1 == 2) exp2 += 75;
        else if (e1 == 3) exp2 += 149;
    int D = e1*3 + exp1*7;
    if (D%2 == 0) exp1 += ceil(float(float(D)/200.00)) ;
    else exp1 -= ceil(float(float(D)/100.00)) ;
    if (exp1<0) exp1 = 0;
    if (exp1>600) exp1 = 600;
    }
    else if (e1>= 4 && e1 <= 99)
    {
        exp1 -= e1;
        if (e1 >=4 && e1 <= 19) exp2 += ceil(float(float(e1)/4.0f + 19));
        else if (e1 >=20 && e1 <= 49) exp2 += ceil(float(float(e1)/9.0 + 21));
        else if (e1 >= 50 && e1 <= 65) exp2 += ceil(float(float(e1)/16.0+ 17));
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 +=ceil(float(float(e1)/4.0 + 19));
            if (exp2 >200) exp2 += ceil(float(float(e1)/9.0 + 21));
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 += ceil(float(float(e1)/4.0 + 19));
            exp2 += ceil(float(float(e1)/9.0+ 21));
            if (exp2 >400) 
            {
                exp2 +=ceil(float(float(e1)/16.0+ 17));
                exp2 = ceil(float(exp2*1.0 + exp2*0.15));
            }
        }
    
    }
    if (exp1<0) exp1 = 0;
    if (exp1>600) exp1 = 600;
    if (exp2<0) exp2 = 0;
    if (exp2>600) exp2 = 600;
    if (exp2 > 600) exp2 = 600; 
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (EXP1<0) EXP1 = 0;
    if (EXP1>600) EXP1 = 600;
    if (E2<0 || E2 >99) E2 = -99; 
    if (E2 == -99) return -99; 
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (M1 > 3000) M1 = 3000;
    if (M1 <0) M1 = 0;
 //CON DUONG 1
    float P1, P2, P3;
    float S1 = ceil(sqrt(EXP1));
    if (EXP1 >= S1) P1 = 100;
    else P1 = (EXP1/S1 + 80) / 123;
//CON DUONG 2
    if (E2 % 2 == 0) //chan
    {
        for (int i=1; i<2; i++)
        {
            if (HP1 < 200)
            {
                HP1 = ceil(float(HP1*1 + HP1*0.3));
                if (HP1 > 666) HP1 = 666;
                M1 -= 150;
                if (M1<0) 
                {
                    M1 = 0;
                    break;
                } 
            }
            else if (HP1 >= 200)
            {
                HP1 = ceil(float(HP1*1 + HP1*0.1));
                if (HP1 > 666) HP1 = 666;
                M1 -= 70;
                if (M1<0) 
                {
                    M1 = 0;
                    break;
                } 
            }
            if (EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            EXP1 = ceil(float(EXP1*1 + EXP1*0.13));
            if (EXP1>600) EXP1 = 600;
            if (M1<0) 
                {
                    M1 = 0;
                    break;
                } 
            if (EXP1 < 300) M1 -= 100;
            else M1 -= 120;
            EXP1 = ceil(float(EXP1*1 - EXP1*0.1));
            if (EXP1>600) EXP1 = 600;
            if (M1<0) M1 = 0;
        }   
    }
    else //le
    {
        int check = M1/2;
        while (M1 >= check)
        {
            if (HP1 < 200)
            {
                HP1 = ceil(float(HP1*1 + HP1*0.3));
                if (HP1 > 666) HP1 = 666;
                M1 -= 150;
                if (M1< check) break;

            }
            else if (HP1 >= 200)
            {
                HP1 = ceil(float(HP1*1 + HP1*0.1));
                if (HP1 > 666) HP1 = 666;
                M1 -= 70;
                if (M1< check) break;
            }
            if (M1<0) M1 = 0;
            if (EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            EXP1 = ceil(float(EXP1*1 + EXP1*0.13));
            if (EXP1>600) EXP1 = 600;
            if (M1< check) break;
            if (EXP1 < 300) M1 -= 100;
            
            else M1 -= 120;
            EXP1 = ceil(EXP1*1.0 - EXP1*0.1);
            if (EXP1>600) EXP1 = 600;
            if (M1< check) break;
        }
        if (M1<0) M1 =0;
        if (M1 < check)
        {
            HP1 = ceil(float(HP1*1 - HP1*0.17));
            EXP1 = ceil(float(EXP1*1+ EXP1*0.17));
        }   
    }
    if (EXP1<0) EXP1 = 0;
    if (EXP1>600) EXP1 = 600;
    if (E2<0 || E2 >99) E2 = -99; 
    if (E2 == -99) return -99; 
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (M1 > 3000) M1 = 3000;
    float S2 = round(sqrt(EXP1));
    if (EXP1 >= S2) P2 = 100;
    else P2 = (EXP1/S2 + 80) / 123;
//CON DUONG 3
    int p[10];
    p[0] = 32;
    p[1] = 47;
    p[2] = 28;
    p[3] = 79;
    p[4] = 100;
    p[5] = 50;
    p[6] = 22;
    p[7] = 83;
    p[8] = 64;
    p[9] = 11;
    if (E2 < 10) P3 = p[E2];
    else 
    {
        int chuc = E2/10;
        int dv = E2%10;
        P3 = p[chuc + dv];
    }
//tinh p
    if (P1 == 100 && P2 == 100 && P3 == 100) EXP1 = ceil(float(EXP1*0.75));
    else 
    {
        float avgP = (P1+P2+P3)/3;
        if (avgP <50)
        {
            HP1 = ceil(float(HP1*1.0 - HP1*0.15));
            EXP1 = ceil(float(EXP1*1+EXP1*0.15));
        }
        else if (avgP >=50) {
            HP1 = ceil(float(HP1*1.0 - HP1*0.10));
            EXP1 = ceil(float(EXP1*1 + EXP1*0.20));       
        } 
    }
    if (EXP1<0) EXP1 = 0;
    if (EXP1>600) EXP1 = 600;
    if (E2<0 || E2 >99) E2 = -99; 
    if (E2 == -99) return -99; 
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (M1 > 3000) M1 = 3000;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    int t[10][10];
    int s[10][10];
    int h=0; //subtitue value for sherlock
    int a, b;

    int x,y; //sherlock catch taxi
    int diff;
    int rvalue;
    for (int j=0; j<=9; j++)
    {
        for (int i=0; i<=9; i++)
        {
                t[i][j] = ((E3*j) + (i*2))*(i-j);
        }
    }
    for (int i=0; i<=9; i++)
    {
        for (int j=0; j<=9; j++)
        {
        int k = 0;
        while (j+k<=9 && i+k<=9)
        {
            if (t[i+k][j+k] >= h) h=t[i+k][j+k];
            k++;
        }
        k=0;
        while (i-k>=0 && j-k>=0 )
        {
            if (t[i-k][j-k] >= h) h=t[i-k][j-k];
            k++;
        }
        k=0;
        while (i+k<=9 && j-k>=0)
            {
            if (t[i+k][j-k]>= h) h=t[i+k][j-k];
            k++;
        }
        k=0;
        while (j+k<=9 && i-k>=0)
            {
            if (t[i-k][j+k]>= h) h=t[i-k][j+k];
            k++;
        }
        s[i][j] = h;
        }
    }
    for (int i=0; i<=9; i++)
    {
        for (int j=0; j<=9; j++)
        {
            if (t[i][j] > E3*2) a++;
        }
    }
    for (int i=0; i<=9; i++)
    {
        for (int j=0; j<=9; j++)
        {
            if (t[i][j] < E3*-1) b++;
        }
    }
if (a>=10)
{
    x = a/10 + a%10;
    if (x>=10) x = x/10 + x%10;
}
else if (a==100) x = 1;
else x = a;
if (b>=10)
{
    y = b/10 + b%10;
    if (y>=10) y = y/10 + y%10;
}
else if (b==100) y = 1;
else y = b;
diff = abs(t[x][y]) - s[x][y];
if (diff <=0)
{
    EXP1 = float(EXP1*1 + EXP1*0.12);
    EXP2 = float(EXP2*1 + EXP2*0.12);
    HP1 = float(HP1*1 + HP1*0.1);
    HP2 = float(HP2*1 + HP2*0.1);
}
else
{
    EXP1 = float(EXP1*1 - EXP1*0.12);
    EXP2 = float(EXP2*1 - EXP2*0.12);
    HP1 = float(HP1*1 - HP1*0.1);
    HP2 = float(HP2*1 - HP2*0.1);
}
if (diff > 0) rvalue = t[x][y];
else rvalue = s[x][y];
    return rvalue;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string pass = s;
    string mail = email;
    int positionREP;
    int charCount;
    int specialChar = 0;
    int n = mail.length();
    int z;
    
    for (int i=0; i<=n; i++)
    {
        if (mail.compare(i, 1, "@") == 0)
        {
            z = i-1;
            break;
        }
    }
    string se = mail.substr(0,z);
    int positionSE = pass.find(se);
    for (int i=0; i<pass.length(); i++)
    {
        if (pass[i] == pass[i+1] && pass[i+1] == pass[i+2]) positionREP = i;
    }
    for (int i=0; i<=pass.length(); i++)
    {
        if (pass[i] == pass[i+1] && pass[i+1] == pass[i+2]) 
        {positionREP = i;
        break;
        }
    }
    for (int i=0; i<pass.length(); i++)
    {
        if (mail.compare(i, 1, "@") == 0 || mail.compare(i, 1, "#") == 0 || mail.compare(i, 1, "%") == 0 || mail.compare(i, 1, "#") ==0 ||mail.compare(i, 1, "!") ==0) specialChar  = i;
    }    
        //condition
    if (pass.length() <=8 ) return -1;
    else if (pass.length() >= 20) return -2;
    else if (positionSE) return -1*(300+positionSE);
    else if (positionREP != -1) return -1*(400+positionREP);
    else if (specialChar == 0) return -5;
    else return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int num[num_pwds];
    for (int i =0; i< num_pwds; i++) {
        int count = 1;
        for (int j=0; j< num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }
        num[i] = count;
    } 
    int max = 0;
    int x;
    for (int i=0; i<num_pwds;i++) {
        if (num[i]>max) {
            max = num[i];
            x = i;
        }
    }
    for (int j = x + 1; j < num_pwds; j++) {
        if ((num[j] == max) && (strlen(arr_pwds[j]) > strlen(arr_pwds[x])))
        x = j;
        }
    return x;   
}
