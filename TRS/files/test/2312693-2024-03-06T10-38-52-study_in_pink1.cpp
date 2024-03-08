#include "study_in_pink1.h"
#define tl 0.999

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
void checkHP(int & HP){
	if (HP > 666) HP = 666;
	else if (HP < 0) HP = 0;};
void checkEXP(int & EXP)
	{if (EXP > 600) EXP = 600;
	else if (EXP < 0) EXP = 0;};
void checkM(int & M)
{if (M > 3000) M = 3000;
	else if (M < 0) M = 0;};

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
checkEXP(exp1);
checkEXP(exp2);
 if (e1 >99 or e1 <0) return -99;
if (e1<=3 and e1>=0)
{switch(e1){case 0:
    exp2 = exp2 +29;break;
    case 1:
    exp2 = exp2 +45;break;
    case 2:
    exp2 = exp2 +75;break;
    case 3:
    exp2 = exp2 +149;break;
};
checkEXP(exp2);
int D = e1*3 + exp1*7;
if (D%2==0) exp1=exp1 + D/200.0 + tl;
else exp1= exp1 - D/100.0 + tl;}
else if (e1>=4 and e1<=19) exp2 = exp2 + e1/4.0 + 19 + tl;
else if (e1>=20 and e1<=49) exp2 = exp2 + e1/9.0 + 21 + tl;
else if (e1>=50 and e1<=65) exp2 = exp2 + e1/16.0 + 17 +tl;
else if (e1>=66 and e1<=79)
{exp2= exp2 + e1/4.0 + 19 + tl;
if  (exp2>200) exp2 = exp2 + e1/9.0 +21 + tl;}
else if (e1>=80 and e1<=99) {exp2 = exp2 + e1/4.0 +19 +tl;
exp2 = exp2 + e1/9.0 +21 +tl;
        if  (exp2>400){exp2 = exp2 + e1/16.0 + 17 + tl;
    exp2 = exp2*1.15 + tl;};};
if(e1>3 and e1<100)    exp1=exp1-e1;
    checkEXP(exp2);checkEXP(exp1);
    return exp1 + exp2;
}
// Task 2
int findnear(int & S,float & P, int & EXP)
{int n=1000; for(int a =0; a<30; ++a){
    if (abs(a*a-EXP)<n) {S = a*a;n=abs(a*a-EXP);};};
if (EXP>=S) P=1;
else P = (((EXP/S)+80.0)/123.0);
return P;}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
checkHP(HP1);
checkEXP(EXP1);
checkM(M1);
if (E2<0 or E2>99) return -99;
float P1,P2,P3[] = {32,47,28,79,100,50,22,83,64,11}, pba, half=M1/2.0;
int S1=0,S2=0,i=0;

findnear(S1,P1,EXP1);

if (E2%2==1) {while (M<=M1){
if (HP1<200){M1=M1-150; HP1=HP1*1.30 +tl;}
else{HP1=HP1*1.10 +tl; M1=M1-70;};
if (half>M1) break;
if(EXP1<400) M1=M1-200;
else M1=M1-120;
EXP1=EXP1*1.13 +tl;checkEXP(EXP1);
if(half>M1) break;
if (EXP1<300) M1=M1-100;
else  M1=M1-120;
EXP1=EXP1*0.90 +tl;
if (half>M1) break;}}
else{
if (HP1<200){M1=M1-150; HP1=HP1*1.30 +tl;}
else{HP1=HP1*1.10 +tl;
M1=M1-70;};
if(EXP1<400) M1=M1-200;
else M1=M1-120;
EXP1=EXP1*1.13 +tl;checkEXP(EXP1);
if (EXP1<300) M1=M1-100;
else  M1=M1-120;
EXP1=EXP1*0.90 +tl;};
checkHP(HP1);
checkEXP(EXP1);
HP1=HP1*0.83 +tl;EXP1 =EXP1*1.17 +tl;
checkM(M1);
checkEXP(EXP1);
checkHP(HP1);
findnear(S2,P2,EXP1);

if (E2>9) {i = E2/10 + E2%10;pba =P3[i%10]/100.0;}
else pba = P3[E2]/100.0;

if (P1==1 and P2==1 and pba==1)
EXP1= EXP1*0.75 +tl;
else if (((P1+P2+pba)/3.0)<(0.50))
{HP1=HP1*0.85 +tl;
EXP1=EXP1*1.15 +tl;}
else{HP1=HP1*0.90 +tl;
EXP1=EXP1*1.20 +tl;};

checkM(M1);
checkEXP(EXP1);
checkHP(HP1);
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
   checkHP(HP1);checkHP(HP2);
   checkEXP(EXP1);checkEXP(EXP2);
if (E3<0 or E3>99) return -99;
int Mang[11][11]={0},store[11][11]={0}, gta=0,gtd =0;
for(int i=0;i<=9;++i){
for(int j=0;j<=9;++j){
    Mang[i][j]=(E3*j+i*2)*(i-j);
   if (Mang[i][j]>E3*2) gtd=gtd +1;
   else if (Mang [i][j] <-E3) gta=gta +1;
};
};
while (gta>9) {gta=gta/10 +gta%10;};
while (gtd>9) {gtd=gtd/10 +gtd%10;};

for (int a=0; a<=9; ++a){
for (int b=0; b<=9-a; ++b){
store[b][a+b+1]=Mang[0][a+1];
store[a+b+1][b]=Mang[9][8-a];
};
};

for (int c=9; c>=0; --c){
for (int d=0; d<=9; ++d){
for (int k=1; k<=9; ++k){int I= c-k;
int J=d+k;
if (Mang[I][J]>store[c][d] and I>=0 and I<=9 and J>=0 and J<=9) store[c][d]=Mang[I][J];
};
for (int k=9; k>=1; --k){int I=c+k; int J=d-k;
if (Mang[I][J]>store[c][d] and I<=9 and I>=0 and J<=9 and J>=0) store[c][d]=Mang[c+k][d-k];
};
};
};

if(abs(Mang[gtd][gta])>store[gtd][gta]){
    EXP1=EXP1*0.88+tl; EXP2=EXP2*0.88+tl;
    HP1=HP1*0.90 + tl; HP2 = HP2*0.90+tl;
    checkHP(HP1);checkHP(HP2);checkEXP(EXP1);checkEXP(EXP2);
    return Mang[gtd][gta];}
else{EXP1=EXP1*1.12+tl; EXP2=EXP2*1.12+tl;
    HP1=HP1*1.10 + tl; HP2 = HP2*1.10 + tl;
    checkHP(HP1);checkHP(HP2);checkEXP(EXP1);checkEXP(EXP2);
    return store[gtd][gta] ;};
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
int l1 =strlen(s), l2=strlen(email);
int sei=100, sci=-1;
if (l2>=1 and l2<=100){
    string se ="";
    int skt =0;
    while ((email[skt]!='@') and (skt<l2))
        {se=se+email[skt];
    skt=skt +1;};
for (int b=0; b<l1;++b){string pb =""; for(int d=0;d<skt;++d) pb=pb+s[b+d]; if (pb==se and sei>=b) sei =b;};

for (int c=0;c<(l1-1);++c){if (s[c]==s[c+1]) {sci=c; break;}
else sci=-1;};

int i =0;
string db ={'@','#','%','$','!'};
for(int g = 0; g<l1; ++g){for(int f=0;f<5;++f){if (s[g]==db[f]) i=1;};};
if (l1<8) {return -1;}
else if (l1>20) return -2;
else if  (sei<100) return (-300 - sei);
else if (sci>=0) return (-400 -sci);
else if (i=1) return -5;
else return -10;};
return -99;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int sss=0, sbd =0,stb=0;
string  pt ="";
if (num_pwds!=1) for(int i =0; i<num_pwds;++i){
        for(int j=0; j<num_pwds;++j)
    {if (arr_pwds[i]==arr_pwds[j]) sbd=sbd +1;};
    if  (sss<sbd) {sss=sbd; pt =arr_pwds[i]; stb=i;sbd=0;}
   else if (sss==sbd and pt.size()<strlen(arr_pwds[i])){pt=arr_pwds[i]; stb=i;sbd=0;}
   else sbd=0;

   };return stb;}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////

