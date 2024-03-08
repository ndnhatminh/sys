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
float checkexp(float exp){
exp=ceill(exp);
if (exp>600) exp=600;
if (exp<0) exp=0;
return exp;
}
float checkhp(float hp){
hp=ceill(hp);
if (hp>666) hp=666;
if (hp<0) hp=0;
return hp;
}
float checkm(float m){
m=ceill(m);
if (m>3000) m=3000;
if (m<0) m=0;
return m;
}


//////////////////////
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
if (e1<0 or e1>99) return -99;
else {
float Exp1=exp1,Exp2=exp2;
Exp1=checkexp(Exp1); Exp2=checkexp(Exp2);
if (0 <= e1 and e1 <=3){
    if (e1==0) Exp2=Exp2+29;
    if (e1==1) Exp2=Exp2+45;
    if (e1==2) Exp2=Exp2+75;
    if (e1==3) Exp2=Exp2+29+45+75;  
    Exp2=checkexp(Exp2);
    int d;
    d=e1*3+Exp1*7;   
    if (d%2==0) Exp1=Exp1+d/200;
    else Exp1=Exp1-d/100;
    Exp1=checkexp(Exp1);
}
else {
    if (4 <= e1 and e1 <=19) Exp2=Exp2+e1/4.0 +19;
    if (20 <= e1 and e1 <= 49) Exp2=Exp2+e1/9.0 +21;
    if (50 <=e1 and e1 <= 65) Exp2= Exp2+e1/16.0+17;
    if (66 <= e1 and e1 <= 79) {
        Exp2= Exp2+e1/4.0 +19;Exp2=checkexp(Exp2);
        if (Exp2 > 200) Exp2= Exp2+e1/9.0+21;}
    if (80 <= e1 and e1 <= 99) {
        Exp2=Exp2+e1/4.0 +19;Exp2=checkexp(Exp2);
        Exp2=Exp2+e1/9.0 +21;Exp2=checkexp(Exp2);
        if(Exp2 > 400) {
            Exp2=Exp2 + e1/16.0 +17;Exp2=checkexp(Exp2);
            Exp2=Exp2*1.15;}}
    Exp2=checkexp(Exp2);
    Exp1=Exp1-e1;
    Exp1=checkexp(Exp1);
}   
    exp1=Exp1; exp2=Exp2;
    return exp1 + exp2;
}}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    ///////////////////////////////road1
float hp1=HP1,exp1=EXP1,m1=M1;
if (E2<0 or E2>99) return -99;
else{
hp1=checkhp(hp1); exp1=checkexp(exp1); m1=checkm(m1);
int i,n;
float p1,p2,p3; 
for (i=0;i*i <= exp1; i++){}
if (i*i-exp1>= exp1-(i-1)*(i-1)) n=(i-1)*(i-1);
else n=i*i;
if (n<=exp1) p1=100;
else p1=(exp1*1.0/n +80)/123*100;
    /////////////////////////////////road2
int m;
m=m1;
if (E2%2==1){
    while(1){  
    if (m1==0) break;  
    if (hp1<200) {hp1=hp1*1.3;m1=m1-150;}
    else {hp1=hp1*1.1;m1=m1-70;}
    hp1=checkhp(hp1); m1=checkm(m1);
    if (m1<m/2) break;
    if (exp1<400) m1=m1-200;
    else m1=m1-120;
    exp1=exp1*1.3;
    exp1=checkexp(exp1); m1=checkm(m1);
    if (m1<m/2) break;
    if (exp1<300) m1=m1-100;
    else m1=m1-120;
    exp1=exp1*0.9;
    exp1=checkexp(exp1); m1=checkm(m1);
    if (m1<m/2) break;}
    exp1=exp1*1.17;
    hp1=hp1*0.83;
    hp1=checkhp(hp1); exp1=checkexp(exp1);}
else{for(int y=0;y<1;y++)
    {if (m1==0) break;
    if (hp1<200) {hp1=hp1*1.3;m1=m1-150;}
    else {hp1=hp1*1.1;m1=m1-70;}
    hp1=checkhp(hp1); m1=checkm(m1);
    if (m1==0) break;
     if (exp1<400) m1=m1-200;
    else m1=m1-120;
    exp1=exp1*1.3;
    exp1=checkexp(exp1); m1=checkm(m1);
    if (m1==0) break;
    if (exp1<300) m1=m1-100;
    else m1=m1-120;
    exp1=exp1*0.9;
    exp1=checkexp(exp1); m1=checkm(m1);
    if (m1==0) break;}
    exp1=exp1*1.17;
    hp1=hp1*0.83;
    hp1=checkhp(hp1); exp1=checkexp(exp1);
}
int a,b;
for (a=0;a*a <= exp1; a++){}
if (-exp1+a*a>= exp1-(a-1)*(a-1)) b=(a-1)*(a-1);
else b=i*i;
if (b<=exp1) p2=100;
else p2=(exp1*1.0/b +80)/123*100;
///////////////////////////////road3
int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
if (E2<10) p3=P[E2];
else {
    int e=E2%10+(E2-E2%10)/10;
    int f=e%10;
    p3=P[f];
}
///////////////////////////////Afterall
if (p1==p2 and p1==p3 and p1==100) exp1=exp1*0.75;
else {
    if ((p1+p2+p3)/3 >=50) {hp1=hp1*0.9;exp1=exp1*1.2;}
    else {hp1=hp1*0.85;exp1=exp1*1.15;}
}
hp1=checkhp(hp1); exp1=checkexp(exp1); m1=checkm(m1);
HP1=hp1; EXP1=exp1;M1=m1;
    return HP1 + EXP1 + M1;
}}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
float hp1=HP1,exp1=EXP1,hp2=HP2,exp2=EXP2;
if (E3<0 or E3>99) return -99;
else{
hp1=checkhp(hp1); exp1=checkexp(exp1); hp2=checkhp(hp2); exp2=checkexp(exp2);
int p[10][10];
int i=0,j=0;
for (int a=0;a<10;a++){
    for (int b=0;b<10;b++){
        p[a][b]=(E3*b+a*2)*(a-b);
        if (p[a][b]>E3*2){i++;}
        if (p[a][b]<-E3){j++;}
    }
}

while (i>9){i=i%10+(i-i%10)/10;}
while (j>9){j=j%10+(j-j%10)/10;}

int max=0;
for(int a=i,b=j;a<10 and b<10;){
    if (max<p[a][b]) max=p[a][b];
    a++;
    b++;
}
for(int a=i,b=j;a>=0 and b>=0;){
    if (max<p[a][b]) max=p[a][b];
    a--;
    b--;
}
for(int a=i,b=j;a>=0 and b<10;){
    if (max<p[a][b]) max=p[a][b];
    a--;
    b++;
}
for(int a=i,b=j;a<10 and b>=0;){
    if (max<p[a][b]) max=p[a][b];
    a++;
    b--;
}
if (max<abs(p[i][j])){hp1=hp1*0.9;hp2=hp2*0.9;exp1=exp1*0.88;exp2=exp2*0.88;}
else {hp1=hp1*1.1;hp2=hp2*1.1;exp1=exp1*1.12;exp2=exp2*1.12;}    
hp1=checkhp(hp1); exp1=checkexp(exp1); hp2=checkhp(hp2); exp2=checkexp(exp2);
HP1=hp1;HP2=hp2;EXP1=exp1;EXP2=exp2;
if (max<abs(p[i][j])) return p[i][j];
else return max;
}}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
bool correct=1;
int case1=1,case2=1,case3=1,case4=2,case5=1,case6=1;
int final=-10;
string str1,str2;
str1=s;
int str1length=str1.length();
str2=email;
int a=str2.find("@");
int special=0;
string se(str2,0,a);
for(int i=0; i<1;i++){
    if (str1length<8) {final= -1; break;}
    if (str1length>20) {final =-2; break;}
    for (int j=0;j<=abs(str1length-a);j++){
        string se2(str1,j,a);
        if (se2==se) {case3=-300-j;correct=0;break;}
    }
    if (correct==0) {final= case3; break;}
    for (int j=0,k=1,h=2;j<str1length-2;){
        if (str1[j]==str1[k] and str1[j]==str1[h]) {case4=-400-j;correct=0; break;}
        j++;k++;h++;
    }
    if (correct==0) {final= case4;break;}
    if (str1.find("@")!=-1) special++;
    if (str1.find("#")!=-1) special++;
    if (str1.find("%")!=-1) special++;
    if (str1.find("$")!=-1) special++;
    if (str1.find("!")!=-1) special++;
    if (special==0) {final= -5;break;}
    for (int j=0;j<str1length;j++){
        int b=0;
        if (97<=int(str1[j]) and int(str1[j])<=122) {b++;}
        if (65<=int(str1[j]) and int(str1[j])<=90) {b++;}
        if (str1[j]=='$' or str1[j]=='!' or str1[j]=='@' or str1[j]=='#' or str1[j]=='%') {b++;}
        if (b==0) {case6=j;correct=0;break;}
    }
    if (correct==0) {final= case6;break;}
}
 return final;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
int maxcount=0,maxlength=0,firstcorrectpwds;
for(int i=0;i<num_pwds;i++){
    const char *pwds=arr_pwds[i];
    int length=strlen(pwds);
    int count=0;
    for(int j=0;j<num_pwds;j++){
        if (pwds==arr_pwds[j]) count++;
    }
    if (count > maxcount or (count==maxcount and length > maxlength)){
        maxcount=count; maxlength=length;firstcorrectpwds=i;
    }
}
    return firstcorrectpwds;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////