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
int firstMeet(int &EXP1,int &EXP2,int E1) {
    float EXP;
    int D;
if (E1<0||E1>99){EXP=-99;if (EXP1<0){EXP1=0;}
if (EXP2<0){EXP2=0;}
if (EXP1>600){EXP1=600;}
if (EXP2>600){EXP2=600;}}
else if (E1>=0 && E1 <=3)
{
if (E1==0){EXP2=EXP2+29;
}
else if (E1==1){EXP2=EXP2+45;
}
else if (E1==2){EXP2=EXP2+75;
}
else {EXP2=EXP2+29+45+75;
}
D=E1*3+EXP1*7;
if (D%2==0){
   EXP1=ceil(EXP1+D/200*1.00);
   if (EXP1<0){EXP1=0;}
if (EXP2<0){EXP2=0;}
if (EXP1>600){EXP1=600;}
if (EXP2>600){EXP2=600;}
  }
else {EXP1=ceil(EXP1-D/100*1.00); 
if (EXP1<0){EXP1=0;}
if (EXP2<0){EXP2=0;}
if (EXP1>600){EXP1=600;}
if (EXP2>600){EXP2=600;}
}
}
else {
if (E1>=4&&E1<=19){EXP2=ceil(EXP2+1.0*E1/4+19);}
else if (E1>=20&&E1<=49){EXP2=ceil(EXP2+1.0*E1/9+21);}
else if (E1>=50&&E1<=65){EXP2=ceil(EXP2+1.0*E1/16+17);}
else if (E1>=66&&E1<=79){EXP2=ceil(EXP2+1.0*E1/4+19);
      if (EXP2>200){EXP2=ceil(EXP2+1.0*E1/9+21);}
      }
else {EXP2=ceil(EXP2+1.0*E1/4+19);
   EXP2=ceil(EXP2+1.0*E1/9+21);
 if (EXP2>400){EXP2=ceil(EXP2+1.0*E1/16+17);
    EXP2=ceil(EXP2*1.15);
    }
 } 
EXP1=ceil(EXP1-E1);
if (EXP1<0){EXP1=0;}
if (EXP2<0){EXP2=0;}
if (EXP1>600){EXP1=600;}
if (EXP2>600){EXP2=600;}
}
EXP=EXP1+EXP2;
return (EXP);
}

// Task 2
int traceLuggage(int &HP1,int &EXP1,int &M1,int E2)
{
int S,a;
float P,P1,P2,P3,T0;
T0=M1;
float hp1,exp1;
hp1=HP1;
exp1=EXP1;
if (E2<0 || E2>99)
{
return -99;
}
else 
{
a=round(sqrt(exp1)); 
S=a*a;
if (exp1>=S) {P1==100;}
else {P1=ceil((exp1/S*1.00+80)/123*100);}
if (E2%2!=0)
{do {if (hp1<200) {hp1=ceil(hp1*1.3); M1=M1-150;}
else {hp1=ceil(hp1*1.1); M1=M1-70;}
if (M1<=0.5*T0) 
{break;}
if (exp1>400) {M1=M1-120;}
else {M1=M1-200;}
exp1=ceil(exp1*1.13);
if (M1<=0.5*T0) 
{break;}
if (exp1<300) {M1=M1-100;}
else {M1=M1-120;}
exp1=ceil(exp1*0.9);
if (M1<=0.5*T0) 
{break;}
}
while (M1>0.5*T0);
}
else{
for (int i=1; i<2; i++) {
if (M1<=0) {
    M1=0;break;
    }
if (hp1<200) 
{hp1=ceil(1.30*hp1); M1=M1-150;}
else {hp1=ceil(1.1*hp1); M1=M1-70;}
if (M1<=0) {M1=0; break;}
if (exp1>400) {M1=M1-120;}
else {M1=M1-200;}
exp1=ceil(exp1*1.13);
if (M1<=0) {M1=0; break;}
if (exp1<300) {M1=M1-100;}
else {M1=M1-120;}
exp1=ceil(exp1*0.9);
if (M1<0){M1=0; break;}
}
}
hp1=ceil(0.83*hp1);
exp1=ceil(1.17*exp1);
a=round(sqrt(exp1));
S=a*a;
if (exp1>=S) {P2=100;}
else {P2=ceil((exp1/S*1.00+80)/123*100);} 
int B[10]={32,47,28,79,100,50,22,83,64,11};
if (E2>=0 && E2<=9) {P3=B[E2];}
else 
{
int v=E2/10+E2%10;
    P3=B[v%10];
}      
P=(P1+P2+P3)/3;
if (P==100) 
{
exp1=ceil(0.75*exp1);
}
else if (P<50) {hp1=ceil(0.85*hp1);
                exp1=ceil(1.15*exp1);}
else 
{hp1=ceil(0.9*hp1);
exp1=ceil(1.2*exp1);
}
if (hp1<0) {hp1=0;}
if (hp1>666) {hp1=666;}
if (exp1<0) {exp1=0;}
if (exp1>600) {exp1=600;}
if (M1<0) {M1=0;}
if (M1>3000) {M1=3000;}
HP1=hp1;
EXP1=exp1;
return (HP1+EXP1+M1); 
}
}
//task 3

int chaseTaxi(int &HP1,int &EXP1,int &HP2,int &EXP2, int E3) 
{
// TODO: Complete this function
int MT[10][10]; 
int i,j,MAX,m,M, 
    x,y,a=0,b=0;
if (E3>=0 & E3<=99)
{
for(i = 0; i < 10; i++)
{
for(j = 0; j < 10; j++)
{
MT[i][j]=((E3*j)+(i*2))*(i-j);
}
} 
for(i = 0; i < 10; i++)
{
for(j = 0; j < 10; j++)
{
if(MT[i][j]>E3*2) 
a++;
if(MT[i][j]<-E3) 
b++;
}
}
while ((a>9)||(b>9))
{
a=a%10+a /10;
b=b%10+b/10;
}
i=a;
j=b;
if((i + j) < 9)
{
x= 0;
y= i + j;
MAX=MT[x][y];
while(y>=0){
if (MAX<MT[x][y]) MAX= MT[x][y];
x++;
y--;
}
}
else
{
x=i+j-9;
y= 9;
MAX=MT[x][y];
while (x<=9)
{
if (MAX<MT[x][y]) 
MAX=MT[x][y];
x++;
y--;
}
}
if ((i-j)>0)
{
x=9;
y=9-(i-j);
while (b>=0)
{
if (MAX<MT[a][b]) 
MAX=MT[a][b];
a--;
b--;
}
}
else
{
a=9+(i-j);
y=9;
while (a >= 0)
{
if (MAX<MT[a][b]) MAX=MT[a][b];
a--;
b--;
}
}
m=MT[i][j];
if (abs(m) > abs(MAX))
{
EXP1=ceil(EXP1*0.88);
HP1=ceil(HP1*0.9);
EXP2=ceil(EXP2*0.88);
HP2=ceil(HP2*0.9);
M=m;
}
else
{
EXP1=ceil(EXP1*1.12);
HP1=ceil(HP1*1.1);
EXP2=ceil(EXP2*1.12);
HP2=ceil(HP2*1.1);
M=MAX;
}
if (EXP1>600) EXP1=600;
if (EXP2>600) EXP2=600;
if (HP1>666) HP1=600;
if (HP2>666) HP1=666;
return M;
}
else 
{
return -99;
}
}

// Task 4
int checkPassword(const char* s, const char* email)
{
int a;
float sci,sei;
int vv;
for (int i=0; i<strlen(email);i++){
if (email[i]=='@'){
    vv=i; 
}
}
char* se = new char[vv + 1];
strncpy(se,email,vv);
se[vv] = '\0';
if (strlen(s)>20){a=-2;}
else if (strlen(s)<8){a=-1;}
else{
for (int j=0; j<strlen(s);j++){
char* m = new char[vv + 1];
strncpy(m, s + j, vv);
m[vv] = '\0';
if (strcmp(se,m)==0){sei=j; a= -300-sei; break;}
else {
if (s[j]==s[j+1]&&s[j]==s[j+2]){sci=j; a= -400-sci; break;}
else if (!(s[j]>='A'&& s[j]<='Z')&&!(s[j]>='a'&& s[j]<='z')&&!(s[j]>='0'&& s[j]<='9')&&(s[j]!='@')&& (s[j]!='#')&&( s[j]!='!')&&( s[j]!='%')&&( s[j]!='$'))
{a=j;break;}
else{ a=0;
if (s[j]=='@'|| s[j]=='#'|| s[j]=='!'|| s[j]=='%'|| s[j]=='$'){a= -10;break;}
else {a= -5;}
}
}
}
} 
return a;
}
// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) 
{
int *ct=new int [num_pwds];  
int x, y;
for (int i = 0; i < num_pwds; i++) {
ct[i] = 1;
}
for (int i = 0; i < num_pwds; i++) {
for (int j = i + 1; j < num_pwds; j++) {
if (!strcmp(arr_pwds[i],arr_pwds[j])) {
ct[i]=ct[i]+1;
} 
}
}
x = 0;
for (int i = 0; i < num_pwds; i++) {
if (x < ct[i]) {
x = ct[i];
y= i;
}
else if (x == ct[i]) {
if (strlen(arr_pwds[x]) < strlen(arr_pwds[i])) {
y = i;
x = ct[i];
}
}
}
return y;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////