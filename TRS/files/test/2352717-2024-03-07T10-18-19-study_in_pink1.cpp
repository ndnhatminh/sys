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
void checkEXP(int &EXP1, int &EXP2)
{
    EXP1 = min(600, max(0, EXP1));
    EXP2 = min(600, max(0, EXP2));
}
void checkHP(int &HP1, int &HP2)
{
    HP1 = min(666, max(0, HP1));
    HP2 = min(666, max(0, HP2));
}

void checkM(int &M1, int &M2)
{
    M1 = min(3000, max(0, M1));
    M2 = min(3000, max(0, M2));
}
//task 1
int firstMeet(int & exp1, int & exp2, int E1) {
    if ( E1>=0 && E1<=3){
        //int D = E1 * 3 + exp1 * 7;
        if (E1 == 0) exp2 += 29;
        else if (E1 == 1) exp2 += 45;
        else if (E1 == 2) exp2 += 75;
        else if (E1 == 3) exp2 += 149;
        int D = E1 * 3 + exp1 * 7;
        if (D%2) {
           exp1 =  ceil (exp1- D / 100.0);
        } else {
               exp1 = ceil(exp1+ D / 200.0);
        }
        checkEXP(exp1,exp2);
    }
    else if (E1>=4 && E1 <=99)
    {
        exp1 -= E1;
        if (E1<=19) exp2 = ceil(exp2 + E1/4.0)+ 19;
        
         else if (E1<=49) exp2 = ceil(exp2+ E1/9.0) + 21;
        
         else if (E1<=65) exp2 = ceil(exp2+ E1/16.0) + 17;
        
         else if(E1<=79)
            
        {  exp2+= ceil(E1/4.0) + 19;
            
            checkEXP(exp1, exp2);
      
            if (exp2>200) exp2 = ceil(exp2 + E1/9.0) + 21;}
        
          else if(E1<=99)  { exp2 = ceil(exp2 + E1/4.0) + 19;
            
            checkEXP(exp1,exp2);
        
                exp2= ceil(exp2+ E1/9.0) + 21;
            
                checkEXP(exp1,exp2);
            
            if(exp2>400) { exp2 = ceil(exp2+ E1/16.0) + 17;
                    
                              checkEXP(exp1,exp2);
                    
                              exp2=ceil(exp2*23.0/20); }
          }
        
          checkEXP(exp1,exp2);
        }
        else return -99;
        return exp1 + exp2;
    }
//task 2
void ktrEXP(int & EXP1)
{  if (EXP1<0){
    EXP1=0;
}
   else if (EXP1>600){
    EXP1=600; }
}
void ktrHP(int & HP1)
{  if (HP1<0){
    HP1=0;
}
   else if (HP1>666){
    HP1=666;
}

}
void ktrM(int & M1)
{  if (M1<0){
    M1=0; }
else if (M1>3000){
    M1=3000; }
}

double Str1(int EXP1)
{int S=sqrt(EXP1);
    int S1=EXP1-S*S;
    int S2=(S+1)*(S+1)-EXP1;
 double P1;
     if (S1<S2) P1=1;
     else P1=(EXP1/(EXP1+S2)+80)/123.0;
    return P1;
}
void Str2_Event1(int &HP1,int &M1)
{if (HP1<200) {HP1=ceil(HP1*13.0/10);M1-=150;}
 else {HP1=ceil(HP1*11.0/10);M1-=70;}
    ktrHP(HP1);
}
void Str2_Event2(int &EXP1,int &M1)
{if (EXP1<400) M1-=200;
 else M1-=120;
 EXP1=ceil(EXP1*113.0/100);
 ktrEXP(EXP1);
}
void Str2_Event3(int &EXP1,int &M1)
{if (EXP1<300) M1 -= 100;
 else M1 -= 120;
 EXP1=ceil(EXP1*9.0/10);
  ktrEXP(EXP1);
}
void Str2(int &HP1, int &EXP1, int &M1, int E2)
{int M=M1;
 if (E2%2)
    {if (M1!=0){
     while(1)
        { Str2_Event1(HP1,M1);
        if (2*M1<M) break;
          Str2_Event2(EXP1,M1);
        if (2*M1<M) break;
        Str2_Event3(EXP1,M1);
        if (2*M1<M) break;
        }
               }
    }
 else {if (M1!=0) { Str2_Event1(HP1,M1);
        if (M1!=0) { Str2_Event2(EXP1,M1);
          if (M1!=0) {Str2_Event3(EXP1,M1);}
            }
        }
      }
 HP1=ceil(HP1*83.0/100);EXP1=ceil(EXP1*117.0/100);
 ktrEXP(EXP1);
}
double Str3(int E2)
{double P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11},P3;
if (E2>=10) {
    E2=E2%10+(E2-E2%10)/10;
    E2=E2%10;}
P3=P[E2];
return P3;
}
void PBang100(int &EXP1)
{EXP1=ceil(EXP1*75.0/100);
}

void PNhohon50(int &EXP1,int &HP1)
{EXP1=ceil(EXP1*115.0/100);
    ktrEXP(EXP1);
 HP1=ceil(HP1*85.0/100);
}

void PLonhonhoacbang50(int &EXP1,int &HP1)
{ EXP1=ceil(EXP1*12.0/10);
    ktrEXP(EXP1);
 HP1=ceil(HP1*90.0/100);
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
   if (E2 < 0 || E2 > 99) return -99;
double P1,P2,P3,P;
P1= Str1(EXP1);
 Str2(HP1, EXP1, M1, E2);
P2=Str1(EXP1);
P3=Str3(E2)/100;
P=(P1+P2+P3)/3;
if (P==1) PBang100(EXP1);
else if (P<0.5) PNhohon50(EXP1,HP1);
else if (P>=0.5) PLonhonhoacbang50(EXP1,HP1);
    return HP1 + EXP1 + M1;
}

//task 3

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int a[10][10];
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            a[i][j] = ((E3*j)+(i*2))*(i-j);
        }
    }
    int c1=0, c2=0;
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            if (a[i][j]>E3*2) c1++;
            if (a[i][j]<-E3) c2++;
        }
    }
    while (c1>=10){
        c1=c1/10+c1%10;
    }
    while (c2>=10){
        c2=c2/10+c2%10;
    }
    int max;
    for (int i=0;i<10;i++){
        if ((c1+i)<=9 && (c2+i)<=9){
            if (a[c1+i][c2+i]>max) max=a[c1+i][c2+i];
        }
        if ((c1-i)>=0 && (c2-i)>=0){
            if (a[c1-i][c2-i]>max) max=a[c1-i][c2-i];
        }
        if ((c1+i)<=9 && (c2-i)>=0){
            if (a[c1+i][c2-i]>max) max=a[c1+i][c2-i];
        }
        if ((c1-i)>=0 && (c2+i)<=9){
            if (a[c1-i][c2+i]>max) max=a[c1-i][c2+i];
        }
    }
    if (max<0) max=abs(max);
    if (abs(a[c1][c2]) > max){
        EXP1=ceil(0.88*EXP1);
        EXP2=ceil(0.88*EXP2);
        HP1=ceil(0.9*HP1);
        HP2=ceil(0.9*HP2);
        ktrEXP(EXP1);
        ktrEXP(EXP2);
        ktrHP(HP1);
        ktrHP(HP2);
        return a[c1][c2];
    }
    else{
        EXP1=ceil(1.12*EXP1);
        EXP2=ceil(1.12*EXP2);
        HP1=ceil(1.1*HP1);
        HP2=ceil(1.1*HP2);
        ktrEXP(EXP1);
        ktrEXP(EXP2);
        ktrHP(HP1);
        ktrHP(HP2);
        return max;
    }
}


int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    string emailString(email);
    string s1 = emailString.substr(0, emailString.find('@'));

    int s_length = strlen(s);
    if (s_length < 8)
        return -1;

    if (s_length > 20)
        return -2;

    const char *s1vitri = strstr(s, s1.c_str());
    if (s1vitri != nullptr)
        return -(300 + (s1vitri - s));

    for (int i = 0; i < s_length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
            return -(400 + i);
    }

    bool t = false;
    for (int i = 0; i < s_length; ++i) {
        if (s[i] == '!' || s[i] == '%' || s[i] == '$' || s[i] == '#' || s[i] == '@')
            t = true;
    }
    if (t==false)
        return -5;

    for (int i = 0; i < s_length; ++i) {
        char c = s[i];
        if (!(('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') ||
              c == '!' || c == '%' || c == '$' || c == '#' || c == '@')) {
            return i;
        }
    }

    return -10;

    return -99;
}


int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{

    int n=0;

    string a[30];

    a[n]=arr_pwds[n];

    for (int i=1;i<=num_pwds-1;i++)

    {for (int j=0;j<i;j++)

    {if (strcmp(arr_pwds[i],arr_pwds[j])==0) break;

    if (strcmp(arr_pwds[i],arr_pwds[j]) != 0 && j==i-1) { a[n+1]=arr_pwds[i]; n++; }

    }

    }

    int t=0;

    while(a[t] !="")

    { t++;

    }

    int a2[t];

    for (int i=0;i<t; i++) {a2[i]=0;}

    for (int i=0;i<t;i++)

    {for (int j=0;j<num_pwds;j++)

    {if (a[i]==arr_pwds[j]) a2[i] += 1;

    }

    }

    int max = a2[0];

    int v=0;

    for (int i = 1; i < t; i++) {

        if (max < a2[i] ) {

        max = a2[i];
            v=i;

    }

    else if (a2[i] == max && a[i].size() >a[v].size())

    {max=a2[i];
        v=i; }

    }

    for (int i=0;i<num_pwds;i++) {
        if (a[v]==arr_pwds[i]) {
            v=i; break;
            }
        
    }

    return v;

    return -1;
                                                 
    }

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
