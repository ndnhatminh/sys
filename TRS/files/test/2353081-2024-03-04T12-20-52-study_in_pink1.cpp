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

//check
void checkexp(int & exp)
{
    if (exp <0)    exp=0;
    if (exp >600)  exp=600;
}

void checkhp(int & HP)
{
    if (HP < 0)    HP=0;
    if (HP >666)   HP=666;
}

void checkmoney(int & M)
{
    if (M <0)  M=0;
    if (M > 3000)  M=3000;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 <0 || e1>99)
        return -99;
    checkexp(exp1); checkexp(exp2); 

    if (e1<=3)  {
        switch (e1)
        {
        case 0:
            exp2+=29;
            break;
        case 1:
            exp2+=45;
            break;
        case 2:
            exp2+=75;
            break;
        case 3:
            exp2+=149;
            break;
        }
        int d=(e1*3)+(exp1*7);
        if (d%2==0) {
            exp1=exp1+double(d)/200+0.999;
        }
        else {
            exp1=exp1-double(d)/100+0.999;
        }

    }
    if (e1>=4 && e1<=19)
    {
        exp2=exp2+double(e1)/4+19+0.999;
    }
    if (e1>=20 && e1<=49)
    {
        exp2=exp2+double(e1)/9+21+0.999;
    }
    if (e1>=50 && e1<=65)
    {
        exp2=exp2+double(e1)/16+17+0.999;
    }
    if (e1>=66 && e1<=79)
    {
        exp2=exp2+double(e1)/4+19+0.999;
        if (exp2>200)   exp2=exp2+double(e1)/9+21+0.999;
    }
    if (e1>=80 && e1<=99)
    {
        exp2=exp2+double(e1)/4+19+0.999;
        exp2=exp2+double(e1)/9+21+0.999;
        if (exp2>400)   { exp2=exp2+double(e1)/16+17+0.999;
            exp2=exp2+double(exp2)*0.15+0.999;
    }}
    if (e1>=4 && e1<=99)    exp1-=e1;
    checkexp(exp1); checkexp(exp2);
    return exp1 + exp2;
}

// Task 2 


int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 <0 || E2>99)
        return -99;
    checkexp(EXP1); checkhp(HP1); checkmoney(M1);
    //quang duong 1
    int t=sqrt(EXP1);
    double s,p1,p2,p3;
    if (abs(t*t-EXP1)<=abs((t+1)*(t+1)-EXP1))   s=t*t;
    else s=(t+1)*(t+1);   
    if (EXP1>=s)    p1=1;
    else p1=(double(EXP1)/s+80)/123;

    //quang duong 2
    if (E2%2==1) { 
    double mtam=M1/2;
    int mtong=0;
    while (mtong<=mtam){
        //mua nuoc
    if (HP1 < 200)  {
        HP1=HP1+double(HP1)*0.3+0.999;
        M1-=150;mtong+=150;
    }
    else {
        HP1=HP1+double(HP1)*0.1+0.999;
        M1-=70;mtong+=70;
    }
    checkhp(HP1); checkmoney(M1);
    if (mtong>mtam) break;
        //di chuyen
    if (EXP1<400)   {M1-=200; mtong+=200;}
    else    {M1-=120; mtong+=120;}
    EXP1=EXP1+double(EXP1)*0.13+0.999;
    checkexp(EXP1);checkmoney(M1);
    if (mtong>mtam) break;
        //vo gia cu
    if (EXP1<300)   {M1-=100; mtong+=100;}    
        else    {M1-=120; mtong+=120;}
    EXP1=EXP1-double(EXP1)*0.1+0.999;
    checkexp(EXP1);checkmoney(M1);
    } 
    HP1=HP1-double(HP1)*0.17+0.999;
    EXP1=EXP1+EXP1*0.17+0.999;
    checkexp(EXP1);checkhp(HP1);
    }
    //e2 chan
    else {
        //mua nuoc
    if (M1>0){
    if (HP1 < 200)  {
        HP1=HP1+double(HP1)*0.3+0.999;
        M1-=150;
    }
    else {
        HP1=HP1+double(HP1)*0.1+0.999;
        M1-=70;
    }
    checkhp(HP1); checkmoney(M1);}
        //di chuyen
    if (M1>0){
    if (EXP1<400)   M1-=200;
    else    M1-=120;
    EXP1=EXP1+double(EXP1)*0.13+0.999;
    checkexp(EXP1);checkmoney(M1);}
        //vo gia cu
    if (M1>0){
    if (EXP1<300)   M1-=100;    
        else    M1-=120;
    EXP1=EXP1-double(EXP1)*0.1+0.999;
    checkexp(EXP1);checkmoney(M1);}

    HP1=HP1-double(HP1)*0.17+0.999;
    EXP1=EXP1+EXP1*0.17+0.999;
    checkexp(EXP1);checkhp(HP1);
    }
//tinh p2
    t=sqrt(EXP1);
    if (abs(t*t-EXP1)<=abs((t+1)*(t+1)-EXP1))   s=t*t;
    else s=(t+1)*(t+1);   
    if (EXP1>=s)    p2=1;
    else p2=(double(EXP1)/s+80)/123;
    

//quang duong 3
    double ptam[]={0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11};
    int i;
    if (E2>=0 && E2<10) i=E2;
        else {
            int d=E2/10+E2%10;
            i=d%10;
        }
    p3=ptam[i];

//final
    if (p1==1 && p2==1 && p3==1)    EXP1=EXP1*0.75+0.999;
        else{
            double p=(p1+p2+p3)/3;
            if (p<0.5)  {
                HP1=HP1-HP1*0.15+0.999;
                EXP1=EXP1+EXP1*0.15+0.999;
            }
            else{
                HP1=HP1-HP1*0.1+0.999;
                EXP1=EXP1+EXP1*0.2+0.999;
            }
        }
    checkexp(EXP1);checkhp(HP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
        if (E3 <0 || E3>99)
        return -99;
    checkexp(EXP1); checkhp(HP1); checkexp(EXP2); checkhp(HP2);
    int a=0,b=0;
    int taxi[10][10]={0};
    int sw[10][10]={0};
    for (int i=0;i<10;i++)
        for (int j=0;j<10;j++){
            taxi[i][j]=((E3*j)+(i*2))*(i-j);
            if (taxi[i][j]>2*E3)   a++;
            if (taxi[i][j]<-E3)    b++;}

    for (int i=0;i<10;i++)
        for (int j=0;j<10;j++){
            int x=i,y=j;
            int tmp=taxi[i][j];
            while (x>=0 && y>=0){
                if (taxi[x][y]>tmp) {
                    tmp=taxi[x][y];
                }
                x--;y--;
            }
            x=i;y=j;
            while (x<10 && y<10){
                if (taxi[x][y]>tmp) {
                    tmp=taxi[x][y];
                }
                x++;y++;
            }
            x=i;y=j;
            while (x>=0 && y<10){
                if (taxi[x][y]>tmp) {
                    tmp=taxi[x][y];
                }
                x--;y++;
            }
            x=i;y=j;
            while (x<10 && y>=0){
                if (taxi[x][y]>tmp) {
                    tmp=taxi[x][y];
                }
                x++;y--;
            }
            sw[i][j]=abs(tmp);
        }
        while (a>9){
            a=a/10+a%10;
        }
        while (b>9){
            b=b/10+b%10;
        }
        if (abs(taxi[a][b])>sw[a][b])  {
            EXP1=double(EXP1)*0.88+0.999;
            HP1=double(HP1)*0.9+0.999;
            EXP2=double(EXP2)*0.88+0.999;
            HP2=double(HP2)*0.9+0.999;
        }
        else{
            EXP1=double(EXP1)*1.12+0.999;
            HP1=double(HP1)*1.1+0.999;
            EXP2=double(EXP2)*1.12+0.999;
            HP2=double(HP2)*1.1+0.999;}
        checkexp(EXP1);checkhp(HP1);
        checkexp(EXP2);checkhp(HP2);
        if(abs(taxi[a][b])>sw[a][b])    return taxi[a][b];
        else return sw[a][b];  
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string se="";
    for (int i=0;i<strlen(email);i++)
        {
            if (email[i]=='@')  break;
            else se.push_back(email[i]);
        }
    if (strlen(s)<8)    return -1;
    if (strlen(s)>20)   return -2;
    
    if (se=="")  return -300;
    for (int i=0;i<strlen(s);i++)
        if (s[i]==se[0]){
            bool check=true;
            for (int j=1;j<se.length();j++)
                if (s[i+j]!=se[j])  {check=false; break;}
                   if (check)  return -(300+i);}

    for (int i=0;i<strlen(s)-2;i++)
        if (s[i]==s[i+1] && s[i]==s[i+2])   return -(400+i);
    bool checkktdb=false;
    for (int i=0;i<strlen(s);i++)
        if (s[i]=='@' || s[i]=='#' || s[i]=='$' || s[i]=='%' || s[i]=='!')
         {checkktdb=true; break;}
    if (!checkktdb)  return -5;

    for (int i=0;i<strlen(s);i++)
        if (s[i]=='@' || s[i]=='#' || s[i]=='$' || s[i]=='%' || s[i]=='!'
        || s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]>='0' && s[i]<='9')
        {}
        else return i;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string mk[30]={};
    int solan[30]={0};
    for (int i=0; i<num_pwds; i++)
    {
        for(int j=0; j<30; j++){
            if (arr_pwds[i]==mk[j])    {solan[j]++; break;}
            if (mk[j]=="")  {mk[j]=arr_pwds[i]; solan[j]++; break;}
        }
    }
    int max=0;
    for (int i=0; i<30; i++)
        if (solan[i]>max)   max=solan[i];
    string kq="";
    for (int i=0; i<30; i++)
        if (solan[i]==max && mk[i].length()>kq.length())  kq=mk[i];
    for (int i=0; i<num_pwds; i++)
        if (arr_pwds[i]==kq)   return i;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////