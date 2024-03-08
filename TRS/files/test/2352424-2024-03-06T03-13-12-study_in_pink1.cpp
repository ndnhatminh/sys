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
void healthpoints(int& hp) {
     if (hp<0) hp=0;
     else
         if (hp>666) hp=666;
     
 }
 void experiences(int& exp) {
         if (exp<0) exp=0;
     else
             if (exp>600) exp=600;
 }
 void money(int& m) {
     if (m<0) m=0;
     else
         if (m>3000) m=3000;
 }
int nearestPerfectSquare(int& n)
{
    int r = sqrt(n);
    if (r * r == n)
    {
        return n;
    }
    else if (abs((r + 1) * (r + 1) - n) < abs(n - r * r))
    {
        return (r + 1) * (r + 1);
    }
    else
    {
        return r * r;
    }
}
 // Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    experiences(exp1);
    experiences(exp2);
    float a;
    if (e1<0 || e1>99) return -99;
    else {
        //circumstance1
        if (e1>=0 && e1<=3) {
            if (e1==0) {
                exp2+=29;
                experiences(exp2);
            }
            else if (e1==1) {
                exp2+=45;
                experiences(exp2);
            }
            else if (e1==2) {
                exp2+=75;
                experiences(exp2);
            }
            else {
                exp2+=29+45+75;
                experiences(exp2);
            }
            int D=e1*3+exp1*7;
            if  (D%2==0) {
                a=exp1+D/200.0;
                exp1=ceil(a);
                experiences(exp1);
            }
            else {
                a=exp1-D/100.0;
                exp1=ceil(a);
                experiences(exp1);
            }
        }
        //circumstance2
        else if (e1>=4 && e1<=99) {
            if(e1>=4 && e1<=19)
            {
                a=exp2+e1/4.0+19;
                exp2=ceil(a);
                experiences(exp2);
            }
            if (e1>=20 && e1<=49) {
                a=exp2+e1/9.0+21;
                exp2=ceil(a);
                experiences(exp2);
            }
            if (e1>=50 && e1<=65) {
                a=exp2+e1/16.0+17;
                exp2=ceil(a);
                experiences(exp2);
            }
            if(e1>=66 && e1<=79)
            {
                a=exp2+e1/4.0+19;
                exp2=ceil(a);
                experiences(exp2);
                if (exp2>200) {
                    a=exp2+e1/9.0+21;
                    exp2=ceil(a);
                    experiences(exp2);
                }
            }
            if (e1>=80 && e1<=99)
            {
                a=exp2+e1/4.0+19;
                exp2=ceil(a);
                experiences(exp2);
                a=exp2+e1/9.0+21;
                exp2=ceil(a);
                experiences(exp2);
                if (exp2>400) {
                    a=exp2+e1/16.0+17;
                    exp2=ceil(a);
                    experiences(exp2);
                    a=exp2*1.15;
                    exp2=ceil(a);
                    experiences(exp2);
                }
            }
            exp1-=e1;
            experiences(exp1);
        }
        
        return exp1+exp2;
    }
}
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    healthpoints(HP1);
    experiences(EXP1);
    money(M1);
    if (E2<0 || E2>99) return -99;
    // Road 01
    float S1=nearestPerfectSquare(EXP1);
    float P1;
    if (EXP1 >= S1)
    {
        P1 = 100;
    }
    else
    {
        P1 = ((EXP1 / S1 + 80) / 123.0) * 100;
    }
    // Road 02
    float halfM1 = M1 * 0.5;
   
    if (E2 % 2 == 1)
    {
        for (int i = 0; i < 100; i++)
        {
            if (M1 >=halfM1)
            {
              
                if (HP1 < 200)
                {
                    float a = HP1 * 1.3;
                    HP1 = ceil(a);
                    healthpoints(HP1);
                    M1 -= 150;
                    money(M1);
                }
                else
                {
                    float a = HP1 * 1.1;
                    HP1 = ceil(a);
                    healthpoints(HP1);
                    M1 -= 70;
                    money(M1);
                }
            }
            else
                break;
            if (M1 >=halfM1)
            {
              
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    float a = EXP1 * 1.13;
                    EXP1 = ceil(a);
                    experiences(EXP1);
                    money(M1);
                }
                else
                {
                    M1 -= 120;
                    float a = EXP1 * 1.13;
                    EXP1 = ceil(a);
                    experiences(EXP1);
                    money(M1);
                }
            }
            else
                break;

            if (M1 >=halfM1)
            {
                
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    float a = EXP1 * 0.9;
                    EXP1 = ceil(a);
                    money(M1);
                }
                else
                {
                    M1 -= 120;
                    float a = EXP1 * 0.9;
                    EXP1 = ceil(a);
                    money(M1);
                }
            }
            else
                break;
        }
        float a = HP1 * 0.83;
        HP1 = ceil(a);
        healthpoints(HP1);
        float b = EXP1 * 1.17;
        EXP1 = ceil(b);
        experiences(EXP1);
    }
    
    else
    {
        for (int i = 0; i < 1; i++)
        {
            if (M1 > 0)
            {
                if (HP1 < 200)
                {
                    float a = HP1 * 1.3;
                    HP1 = ceil(a);
                    healthpoints(HP1);
                    M1 -= 150;
                    money(M1);
                }
                else
                {
                    float a = HP1 * 1.1;
                    HP1 = ceil(a);
                    healthpoints(HP1);
                    M1 -= 70;
                    money(M1);
                }
            }
            else
            
                break;
            if (M1 > 0)
            {
               
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    money(M1);
                    float a = EXP1 * 1.13;
                    EXP1 = ceil(a);
                    experiences(EXP1);
                    money(M1);
                }
                else
                {
                    M1 -= 120;
                    money(M1);
                    float a = EXP1 * 1.13;
                    EXP1 = ceil(a);
                    experiences(EXP1);
                    money(M1);
                }
            }
            else
                break;
            if (M1 > 0)
            {
                
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    money(M1);
                    float a = EXP1 * 0.9;
                    EXP1 = ceil(a);
                    experiences(EXP1);
                    money(M1);
                }
                else
                {
                    M1 -= 120;
                    money(M1);
                    float a = EXP1 * 0.9;
                    EXP1 = ceil(a);
                    experiences(EXP1);
                    money(M1);
                }
            }
            else
                break;
        }
        float a = HP1 * 0.83;
        HP1 = ceil(a);
        healthpoints(HP1);
        float b = EXP1 * 1.17;
        EXP1 = ceil(b);
        experiences(EXP1);
    }
    float P2;
    float S2=nearestPerfectSquare(EXP1);
    if (EXP1 >= S2)
    {
        P2 = 100;
    }
    else
    {
        P2 = ((EXP1 / S2 + 80) / 123.0) * 100;
    }

    //road3
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i=0;
    float P3 = 0;
    int s=0;
    while (E2>0) {
                s+=E2%10;

                E2/=10;
            }
       i=s%10;
        P3 = P[i];
    

    if (P1 == 100 && P2 == 100 && P3 == 100)
    {
        float a = EXP1 * 0.75;
        EXP1 = ceil(a);
        experiences(EXP1);
    }

    else
    {
        float Pavg = (P1 + P2 + P3) / 3.0;
        if (Pavg < 50)
        {
            float a;
            float b;
            a = HP1 * 0.85;
            HP1 = ceil(a);
            healthpoints(HP1);
            b = EXP1 * 1.15;
            EXP1 = ceil(b);
            experiences(EXP1);
        }
        else if (Pavg > 50)
        {
            float a;
            float b;
            a = HP1 * 0.9;
            HP1 = ceil(a);
            healthpoints(HP1);
            b = EXP1 * 1.2;
            EXP1 = ceil(b);
            experiences(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    healthpoints(HP1);
    experiences(EXP1);
    healthpoints(HP2);
    experiences(EXP2);
    if (E3<0 || E3>99) return -99;
    else {
        int TaxiScore=0;
        int DetectiveScore=0;
        float a;
        int row=0;
        int column=0;
        int posi=0;
        int posj=0;
        int Matrix[10][10];
        for (int i=0; i<10; i++) {
            for (int j=0; j<10; j++) {
                Matrix[i][j] = (E3*j+i*2)*(i-j);
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (Matrix[i][j] > E3 * 2) {
                    row++;
                }
                if (Matrix[i][j] < (-E3)) {
                    column++;
                }
            }
        }
        while (row >= 10) {
            row=row%10+(row-row%10)/10.0;
            }
        while (column >= 10) {
            column=column%10+(column-column%10)/10.0;
        }
        posi=row; posj=column;
        TaxiScore=Matrix[posi][posj];
        int Max=Matrix[posi][posj];
        int diff=abs(posi-posj);
        int sum=abs(posi+posj);
        int m=posi, n=posj;
        while (m>=0 && n>=0 && abs(m-n)==diff) {
            if(Matrix[m][n]>Max)
                Max=Matrix[m][n];
            m--;
            n--;
        }
        m=posi; n=posj;
        while (m<=9 && n<=9 && abs(m-n)==diff) {
            if(Matrix[m][n]>Max)
                Max=Matrix[m][n];
            m++;
            n++;
        }
        m=posi; n=posj;
        while (m<=9 && n>=0 && m+n==sum) {
            if(Matrix[m][n]>Max)
                Max=Matrix[m][n];
            m++;
            n--;
        }
        m=posi; n=posj;
        while (m>=9 && n<=0 && m+n==sum) {
            if(Matrix[m][n]>Max)
                Max=Matrix[m][n];
            m--;
            n++;
        }
        DetectiveScore=Max;
        if (abs(TaxiScore)>DetectiveScore) {
            Max=TaxiScore;
            a=EXP1*0.88;
            EXP1=ceil(a);
            a=EXP2*0.88;
            EXP2=ceil(a);
            a=HP1*0.9;
            HP1=ceil(a);
            a=HP2*0.9;
            HP2=ceil(a);
        }
        else {
            Max=DetectiveScore;
            a=EXP1*1.12;
            EXP1=ceil(a);
            a=EXP2*1.12;
            EXP2=ceil(a);
            a=HP1*1.1;
            HP1=ceil(a);
            a=HP2*1.1;
            HP2=ceil(a);
        }
        experiences(EXP1);
        experiences(EXP2);
        healthpoints(HP1);
        healthpoints(HP2);

        
        
        return Max;
        
        }
}

// Task 4
int checkPassword(const char *s, const char *email)
{
       int  a = strlen(s),
        b = strlen(email),
        c=0;
    string se = "";
    for (int i = 0; i < b; i++)
    {
        if (email[i] == '@')
        {
            break;
        }
        else
            se += email[i];
    }
    // Check if the length of the password is within the valid range

    if (a < 8)
    {
        return -1; // shorter than minimum length
    }
    if (a > 20)
    {
        return -2; // longer than maximum length
    }

    for (int i = 0; i < a; i++)
    {
        if (se == "")
        {
            return -300;
            break;
        }
        else if (s[i] == se[0])
        {
            c = 1;
            for (int j = 0; j < se.length(); j++)
            {
                if (i + j + 1 > a)
                {
                    c = 0;
                    break;
                }
                if (s[i + j] != se[j])
                {
                    c = 0;
                    break;
                }
            }
        }
        if (c != 0)
        {
            return -(300 + i);
            break;
        }
    }
    // Check if each character is valid and if there are consecutive identical characters

    for (int i = 0; i < a; i++)
    {
        if (i + 2 <= a - 1)
        {
            if (s[i] == s[i + 1] && s[i] == s[i + 2])
            {
                return -(400 + i);
            }
        }
    }
    int x = 0;
    for (int i = 0; i < a; i++)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            x = 1; // Invalid character
        }
    }
    if (x == 0)
    {
        return -5;
    }
    string isoalphanumeric = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#$%!";
    for (int i = 0; i < a; i++)
    {
        int h = -1;
        for (int j = 0; j < isoalphanumeric.length(); j++)
        {
            if (s[i] == isoalphanumeric[j])
            {
                h = i;
                break;
            }
        }
        if (h == -1)
        {
            return i;
        }
    }
    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxcount=0;
        int maxlength=0;
        int position=-1;
        for (int i=0; i<num_pwds; i++) {
             const string& password=arr_pwds[i];
            int count=0;
            size_t length=password.length();
            for (int j=0; j<num_pwds; j++) {
                if (arr_pwds[j]==password) {
                    count++;
                }
            }
            if (count>maxcount || (count==maxcount && length>maxlength)) {
                maxcount=count;
                maxlength=length;
                position=i;
            }
        }
        return position;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////




