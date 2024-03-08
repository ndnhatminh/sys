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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1<0||e1>99) return -99;
     float EXP1, EXP2, E1;
 EXP1=(float)exp1;
 EXP2=(float)exp2;
 E1 = (float)e1;
 if(e1>=0&&e1<=3)
 {
    if(e1==0)
    {
        EXP2+=29;
    }
    else if(e1==1)
    {
        EXP2+=45;
    }
    else if(e1==2)
    {
        EXP2 +=75;
    }
    else if(e1 ==3)
    {
        EXP2 += (45+29+75);
    }
    int d = e1*3 + exp1*7;
    float D = (float)d;
    if(d%2==0)
    {
        EXP1+=D/200;
        
    }
    else
    {
        EXP1 -= D/100;
    }
    EXP1=ceil(EXP1);
 }
 else if (e1>=4&&e1<=99)
 {
    if(e1>=4&&e1<=19)
    { 
EXP2 += E1/4 +19;
EXP2=ceil(EXP2);
    }
    else if(e1>= 20 && e1 <= 49)
    {
        EXP2 += E1/9 + 21;
        EXP2=ceil(EXP2);
    }
    else if(e1>=50&&e1<=65)
    {
        EXP2+= E1/16 + 17;
        EXP2=ceil(EXP2);
    }
    else if(e1>=66&&e1<=79)
    {
        EXP2 += E1/4 +19;
       EXP2= ceil(EXP2);
        if(EXP2>200)
        {
            EXP2 += E1/9 + 21;
           EXP2= ceil(EXP2);
        }
    }
    else if(e1>=80&&e1<=99)
    {
        EXP2+=E1/4 +19;
        EXP2=ceil(EXP2);
        EXP2+=E1/9+ 21;
        EXP2=ceil(EXP2);
        if(EXP2>400)
        {
            EXP2+=E1/16+17;
           EXP2= ceil(EXP2);
            EXP2*=1.15;
           EXP2= ceil(EXP2);
        }
    }
    EXP1-=E1;
 }
 exp1 = (int)EXP1;
 exp2 = (int)EXP2;
 if(exp1>600)
 {
    exp1=600;
 }
 if(exp2 >600)
 {
    exp2 = 600;
 }
 if(exp1<0)
 {
    exp1=0;
 }
 if(exp2<0)
 {
    exp2 =0;
 }
    return exp1 + exp2;
}

// Task 2
int findsquare(int a)
{
    int b = sqrt(a);
    if(a-b*b<(b+1)*(b+1)-a)
    { return b*b;

    }
    else return (b+1)*(b+1);
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
    if(E3<0 || E3 >99) return -99;
float hp1 = (float)HP1;
float exp1 = (float)EXP1;
float e3 = (float)E3;
int M = M1, d=0;
int S = findsquare(EXP1), paid=0;
float P1;
if(EXP1>=S)
{
    P1 =1;
}
else 
{
    P1=(exp1/S +80)/123;
}
while(paid<=M/2)
{if(hp1<200)
{
    hp1*=1.3;
    M1-=150;
   hp1= ceil(hp1);
   paid+=150;
}
else
{
    hp1*=1.1;
    M1 -=70;
    hp1=ceil(hp1);
    paid+=70;

}
if(M1<0||(paid>M/2&&E3%2==1))
{
    break;
}
if(exp1<400)
{M1-=200;
paid+=200;}
else
{M1-=120;
paid+=120;}
exp1*=1.13;
exp1=ceil(exp1);
if(M1<0||(paid>M/2&&E3%2==1))
{
    break;
}
if(exp1<300)
{
    M1-=100;
    paid += 100;
}
else
{
    M1-=120;
    paid += 120;
}
exp1*=0.9;
exp1=ceil(exp1);
d++;
if(E3%2==0)
{break;}

}
if(hp1>666)
{
    hp1=666;
}
if(exp1>600)
{
    exp1=600;
}
if(M1>3000)
{
    M=3000;
}


    hp1*=0.83;
    exp1*=1.17;
    hp1=ceil(hp1);
    exp1=ceil(exp1);

if(M1<0)
{
    M1=0;
}
EXP1=(int)exp1;
int S2 =findsquare(EXP1);
float P2;
if(EXP1>=S2)
{
    P2=1;
}
else
{
    P2=(exp1/S2 + 80)/123;
}
float P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
float P3;
if(E3<=9)
{
    P3=P[E3]/100;
}
else if(E3>=10&&E3<=99)
{
    P3=P[(E3/10+E3%10)%10]/100;
}
float p = (P1+P2+P3)/3;
if(p==1)
{
    exp1*=0.75;
    exp1=ceil(exp1);
}
else if(p<0.5)
{
hp1*=0.85;
exp1*=1.15;
hp1=ceil(hp1);
exp1=ceil(exp1);
}
else if(p>=0.5)
{
    hp1*=0.9;
    exp1*=1.2;
    hp1=ceil(hp1);
    exp1=ceil(exp1);
}
HP1=(int)hp1;
EXP1=(int)exp1;
if(HP1>666)
{
    HP1=666;
}
if(EXP1>600)
{
    EXP1=600;
}
if(M1>3000)
{
    M=3000;
}
if(HP1<0)
{
    HP1=0;
}
if(EXP1<0)
{
    EXP1=0;
}
if(M1<0)
{
    M1=0;
}

    return HP1 + EXP1 + M1;
}

// Task 3
int  maxPoint(int m, int n ,int (&a)[10][10])
{ int maxL =a[m][n], maxR = a[m][n];
int Lm = m, Ln = n, Rm=m, Rn=n;
while(Ln*Lm>0)
{
Lm--; 
Ln--;
}
while((Lm-9)*(Ln-9)>0)
{
if(a[Lm][Ln]>=maxL)
{
    maxL=a[Lm][Ln];
    
}
Ln++;
    Lm++;
}
while(Rn*(Rm-9)<0)
{
Rm++;
Rn--;
}
while(Rm*(Rn-9)<0)
{
    if(a[Rm][Rn]>=maxR)
    {
        maxR=a[Rm][Rn];
    }
    Rm--;
    Rn++;
}
if(maxR>=maxL)
{
    return maxR;
}
else
{
    return maxL;
}}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
       float hp1= (float)HP1;
    float exp1=(float)EXP1;
    float hp2 = (float)HP2;
    float exp2 =(float)EXP2;
    int m[10][10];
    int x =0, y=0;
    for(int i =0; i<=9;i++)
    {
        for(int j =0; j<=9; j++)
        {
            m[i][j]= ((E3*j) + (i*2))*(i-j);
        }
    }
    
    
    int n[10][10];
    for(int j = 0; j<=9;j++)
    {
        for(int i =0; i<=9; i++)
        {
            n[i][j]=maxPoint(i,j,m);
        }
    }
    
for(int i =0; i<=9; i++)
{
    for(int j =0; j<=9;j++)
    {
        if(m[i][j]>E3*2)
        {
            x++;
        }
        if(m[i][j]<-E3)
        {
            y++;
        }
    }
}

while(x>=10)
{
x=x/10 + x%10;
}
while(y>=10)
{
    y=y/10 +y%10;
}
if(abs(m[x][y])>abs(n[x][y]))
{
exp1*=0.88;
hp1*=0.9;
exp2*=0.88;
hp2*=0.9;
hp1=ceil(hp1);
hp2=ceil(hp2);
exp1=ceil(exp1);
exp2=ceil(exp2);
EXP1=(int)exp1;
EXP2=(int)exp2;
HP1=(int)hp1;
HP2=(int)hp2;
if(HP1>666)
{
    HP1=666;
}
if(EXP1>600)
{
    EXP1=600;
}
if(HP1<0)
{
    HP1=0;
}
if(EXP1<0)
{
    EXP1=0;
}

if(HP2>666)
{
    HP2=666;
}
if(EXP2>600)
{
    EXP2=600;
}
if(HP2<0)
{
    HP2=0;
}
if(EXP2<0)
{
    EXP2=0;
}
return m[x][y];
}
else
{
    exp1*=1.12;
    hp1*=1.1;
    exp2*=1.12;
    hp2*=1.1;
    hp1=ceil(hp1);
hp2=ceil(hp2);
exp1=ceil(exp1);
exp2=ceil(exp2);
EXP1=(int)exp1;
EXP2=(int)exp2;
HP1=(int)hp1;
HP2=(int)hp2;
if(HP1>666)
{
    HP1=666;
}
if(EXP1>600)
{
    EXP1=600;
}
if(HP1<0)
{
    HP1=0;
}
if(EXP2<0)
{
    EXP2=0;
}
if(HP2>666)
{
    HP2=666;
}
if(EXP2>600)
{
    EXP2=600;
}
if(HP2<0)
{
    HP2=0;
}
if(EXP2<0)
{
    EXP2=0;
}
    return n[x][y];
}

    return -1;
}

// Task 4
int se_in_s(string se, const char* s)
{ 
    int j =0,m;
     for(int  i =0; i <= strlen(s)-2;i++)
{ if(s[i]!=se[j]) continue;
 else if(se[j]==s[i]&&s[i+1]==se[j+1])
{
     if(j==se.size()-2)
{ 
    return i+1-se.size()+1;
    break;
}
     j++;
    
}
else if(se[j]==s[i]&&se.size()==1)
{
    return i;
}

}
return -1;
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

   stringstream ss(email);
   string se;
   while(getline(ss,se,'@'))
   {
    break;
   }
   int s_size=strlen(s) ;
   if(s_size>=8&&s_size<=20)
   {
    if(se_in_s(se,s)+1)
   { int a = se_in_s(se,s);
    return -(300+a);
   }
   else {for(int i =0; i<=s_size-2;i++)
   {
    if(s[i]==s[i+1]&&s[i+1]==s[i+2])
    {
        return -(400+i);
        break;
    }}
    for(int i =0; i<=s_size-2;i++)
    {if(s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!')
    { return -10;
        break;
    }
    else if(i+1==s_size-1)
    {return -5;}
    }
     }
    
   }
   
   else if(s_size<8)
   {
    return -1;
   } 
   else if(s_size>20)
   {
    return -2;
   }
   return 0;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    
     string arr[num_pwds];
    for(int i=0; i<= num_pwds-1;i++)
    {
        arr[i]=arr_pwds[i];
    }
    int a[num_pwds];
    
    for(int i =0; i<= num_pwds-1; i++)
    { int d1 =1;
        for(int j =i+1; j<= num_pwds-1; j++)
        {
            if(arr[i]==arr[j])
            {
                d1++;
                arr[j]=j;
            }
        }
       a[i]=d1;
       
    } 
    int maxP=a[0],result;
    int b[100];
     
    for(int i =1; i<= num_pwds-1;i++)
   {
    if(a[i]>maxP)
    {
        maxP=a[i];
    }
   } int m = 0,n;
    for(int i =0; i<= num_pwds-1; i++)
   {
    if(a[i]==maxP)
    { 
     if(arr[i].size()>=m)
     {
       m=arr[i].size();
       n=i;
     }
         
    }
   
   }
   return n;
   
    
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////