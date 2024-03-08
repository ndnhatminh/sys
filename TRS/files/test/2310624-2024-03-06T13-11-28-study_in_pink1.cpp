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
if(exp1<=0){exp1=0;}
if(exp1>=600){exp1=600;}
if(exp2<=0){exp2=0;}
if(exp2>=600){exp2=600;}
if(e1<0 || e1>99){return -99;}

//case 1
if(e1>=0 && e1<=3){
switch(e1){
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
exp2+=29 + 45 + 75;
break;};
double a=e1*3+exp1*7;
int d=a;
if(d%2==0){exp1+=ceil(a/200);}
else{exp1=ceil(double(exp1)-a/100);};
};

//case 2
if(e1>=4 && e1<=99){
double a=e1;
if(e1>=4 && e1<=19){exp2+=ceil(a/4)+19;}
if(e1>=20 && e1<=49){exp2+=ceil(a/9)+21;}
if(e1>=50 && e1<=65){exp2+=ceil(a/16)+17;}
if(e1>=66 && e1<=79){exp2+=ceil(a/4)+19;if(exp2>200){exp2+=ceil(a/9)+21;};};
if(e1>=80 && e1<=99){
exp2+=ceil(a/4)+19+ceil(a/9)+21;
if(exp2>400){exp2+=ceil(a/16)+17;double b=exp2;b*=1.15;ceil(b);exp2=b;};
};
exp1-=e1;
};

if(exp1<=0){exp1=0;}
if(exp1>=600){exp1=600;}
if(exp2<=0){exp2=0;}
if(exp2>=600){exp2=600;}

    return exp1 + exp2;
}












// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
if(EXP1<=0){EXP1=0;}
if(EXP1>=600){EXP1=600;}
if(HP1<=0){HP1=0;}
if(HP1>=666){HP1=666;}
if(M1<=0){M1=0;}
if(M1>=3000){M1=3000;}
if(E2<0 || E2>99){return -99;}



//path 1
double p1;
int s=round(sqrt(EXP1))*round(sqrt(EXP1));
if(EXP1>=s){p1=1;}
else{p1=(double(EXP1)/s+80)/123;};

//path 2
double half=double(M1)/2;

if(E2%2!=0){
while(true){
if(HP1<200){HP1+=ceil(0.3*HP1);M1-=150;}
else{HP1+=ceil(0.1*HP1);M1-=70;};
//reset
if(HP1<=0){HP1=0;}
if(HP1>=666){HP1=666;}
if(M1<=0){M1=0;}
if(M1>=3000){M1=3000;}
if(M1<half){break;}

if(EXP1<400){M1-=200;}
else{M1-=120;};
EXP1+=ceil(0.13*EXP1);
//reset
if(EXP1<=0){EXP1=0;}
if(EXP1>=600){EXP1=600;}
if(M1<=0){M1=0;}
if(M1>=3000){M1=3000;}
if(M1<half){break;}

if(EXP1<300){M1-=100;}
else{M1-=120;};
EXP1=ceil(EXP1*0.9);
//reset
if(EXP1<=0){EXP1=0;}
if(EXP1>=600){EXP1=600;}
if(M1<=0){M1=0;}
if(M1>=3000){M1=3000;}
if(M1<half){break;}

};}
else{
if(HP1<200){HP1+=ceil(0.3*HP1);M1-=150;}
else{HP1+=ceil(0.1*HP1);M1-=70;};
//reset
if(HP1<=0){HP1=0;}
if(HP1>=666){HP1=666;}
if(M1<=0){M1=0;}
if(M1>=3000){M1=3000;}
if(M1<=0){goto end;}

if(EXP1<400){M1-=200;}
else{M1-=120;};
EXP1+=ceil(0.13*EXP1);
//reset
if(EXP1<=0){EXP1=0;}
if(EXP1>=600){EXP1=600;}
if(M1<=0){M1=0;}
if(M1>=3000){M1=3000;}
if(M1<=0){goto end;}

if(EXP1<300){M1-=100;}
else{M1-=120;};
EXP1=ceil(EXP1*0.9);
//reset
if(EXP1<=0){EXP1=0;}
if(EXP1>=600){EXP1=600;}
if(M1<=0){M1=0;}
if(M1>=3000){M1=3000;}
if(M1<=0){goto end;}
};


end: HP1=ceil(HP1*0.83);
EXP1+=ceil(EXP1*0.17);
//reset
if(EXP1<=0){EXP1=0;}
if(EXP1>=600){EXP1=600;}
if(HP1<=0){HP1=0;}
if(HP1>=666){HP1=666;}

double p2;
s=round(sqrt(EXP1))*round(sqrt(EXP1));
if(EXP1>=s){p2=1;}
else{p2=(double(EXP1)/s+80)/123;};

//path 3
double P[]={0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11};
int i;
if(E2<10){i=E2;}
else{i=(int(E2/10)+E2-int(E2/10)*10)-int((int(E2/10)+E2-int(E2/10)*10)/10)*10;};

double PP=(p1 + p2 + P[i])/3;
if(p1==1 && p2==1 && P[i]==1){EXP1=ceil(EXP1*0.75);}
else{
if(PP<0.5){HP1=ceil(HP1*0.85);EXP1+=ceil(EXP1*0.15);}
else{HP1=ceil(HP1*0.9);EXP1+=ceil(EXP1*0.2);}
};

if(EXP1<=0){EXP1=0;}
if(EXP1>=600){EXP1=600;}
if(HP1<=0){HP1=0;}
if(HP1>=666){HP1=666;}
if(M1<=0){M1=0;}
if(M1>=3000){M1=3000;}

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
if(EXP1<=0){EXP1=0;}
if(EXP1>=600){EXP1=600;}
if(EXP2<=0){EXP2=0;}
if(EXP2>=600){EXP2=600;}
if(HP1<=0){HP1=0;}
if(HP1>=666){HP1=666;}
if(HP2<=0){HP2=0;}
if(HP2>=666){HP2=666;}
if(E3<0 || E3>99){return -99;}

int a[10][10];
int p=0,p1;
int n=0,n1;
int max;
int taxi;
//matrix and i;j
for(int i=0;i<10;i++){
for(int j=0;j<10;j++){
a[i][j]=((E3*j)+(i*2))*(i-j);
if(a[i][j]>(E3*2)){p++;}
if(a[i][j]<(-E3)){n++;}
};};

p=int(p/10)+p-int(p/10)*10;
p=int(p/10)+p-int(p/10)*10;
n=int(n/10)+n-int(n/10)*10;
n=int(n/10)+n-int(n/10)*10;
taxi=a[p][n];
p1=p;
n1=n;

while(true){if(p==0 || n==0){break;};p--;n--;};
while(true){
	
if(p==0 || n==0){max=a[p][n];p++;n++;continue;};
if(p>9 || n>9){break;}
if(max<a[p][n]){max=a[p][n];};
p++;n++;if(p==9 || n==9){if(max<a[p][n]){max=a[p][n];};break;};
};

while(true){if(p1==0 || n1==9){break;};p1--;n1++;};
while(true){

if(p1==0 || n1==9){max=a[p1][n1];p1++;n1--;continue;};
if(p1>9 || n1<0){break;}
if(max<a[p1][n1]){max=a[p1][n1];};
p1++;n1--;if(p1==9 || n1==0){if(max<a[p1][n1]){max=a[p1][n1];};break;};
};

if(abs(taxi)<=max){
EXP1+=ceil(EXP1*0.12);EXP2+=ceil(EXP2*0.12);HP1+=ceil(HP1*0.1);HP2+=ceil(HP2*0.1);}
else{EXP1=ceil(EXP1*0.88);EXP2=ceil(EXP2*0.88);HP1=ceil(HP1*0.9);HP2=ceil(HP2*0.9);};
if(EXP1<=0){EXP1=0;}
if(EXP1>=600){EXP1=600;}
if(EXP2<=0){EXP2=0;}
if(EXP2>=600){EXP2=600;}
if(HP1<=0){HP1=0;}
if(HP1>=666){HP1=666;}
if(HP2<=0){HP2=0;}
if(HP2>=666){HP2=666;}
if(E3<0 || E3>99){return -99;}



if(abs(taxi)>max){return taxi;} else{return max;};


}

// Task 4
int checkPassword(const char * s, const char * email) {
int c=0;
string b=s;
string a=email;
a.erase (a.find('@'),a.length ());

if (b.length ()<8){c=-1;goto end;}
if (b.length ()>20){c=-2;goto end;}
if (b.find(a)!=-1){c=(-1)*(300+b.find(a));goto end;}
for(int i=0; ;i++){if(b[i]==b[i+1] && b[i]==b[i+2] && b[i+1]==b[i+2]){c=(-1)*(400+i);goto end;};if(i==(b.length()-3)){break;}};
if (b.find('@')==-1 && b.find('#')==-1 && b.find('%')==-1 && b.find('$')==-1 && b.find('!')==-1){c=-5;goto end;}
for(int i=0; ;i++){
if(b[i]!='0' && 
b[i]!='1' && 
b[i]!='2' &&
b[i]!='3' &&
b[i]!='4' &&
b[i]!='5' &&
b[i]!='6' &&
b[i]!='7' &&
b[i]!='8' &&
b[i]!='9' &&
b[i]!='a' &&
b[i]!='b' &&
b[i]!='c' &&
b[i]!='d' &&
b[i]!='e' &&
b[i]!='f' &&
b[i]!='g' &&
b[i]!='h' &&
b[i]!='i' &&
b[i]!='j' &&
b[i]!='k' &&
b[i]!='l' &&
b[i]!='m' &&
b[i]!='n' &&
b[i]!='o' &&
b[i]!='p' &&
b[i]!='q' &&
b[i]!='r' &&
b[i]!='s' &&
b[i]!='t' &&
b[i]!='u' &&
b[i]!='v' &&
b[i]!='w' &&
b[i]!='x' &&
b[i]!='y' &&
b[i]!='z' &&
b[i]!='A' &&
b[i]!='B' &&
b[i]!='C' &&
b[i]!='D' &&
b[i]!='E' &&
b[i]!='F' &&
b[i]!='G' &&
b[i]!='H' &&
b[i]!='I' &&
b[i]!='J' &&
b[i]!='K' &&
b[i]!='L' &&
b[i]!='M' &&
b[i]!='N' &&
b[i]!='O' &&
b[i]!='P' &&
b[i]!='Q' &&
b[i]!='R' &&
b[i]!='S' &&
b[i]!='T' &&
b[i]!='U' &&
b[i]!='V' &&
b[i]!='W' &&
b[i]!='X' &&
b[i]!='Y' &&
b[i]!='Z' &&
b[i]!='@' &&
b[i]!='#' &&
b[i]!='%' &&
b[i]!='$' &&
b[i]!='!'){c=i;goto end;}if(i==(b.length()-1)){break;}};




c=-10;
end: return c;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
string a;
int b[num_pwds];
int max,re;
for(int i=0; ;i++){a.insert (0,arr_pwds[i]);if(i==num_pwds-1){break;}};
for(int i=0; ;i++){b[i]=0;string c=arr_pwds[i];while(a.find(c)!=-1){a.erase(a.find(c),c.length());b[i]++;};if(i==num_pwds-1){break;}};

//b[i]+=c.length();
for(int i=0; ;i++){if(i==0){max=b[0];re=0;continue;}
if(max<b[i]){max=b[i];re=i;continue;}
string c=arr_pwds[i];
string d=arr_pwds[re];
if(max==b[i]){if(c.length()>d.length()){re=i;}};
if(i==num_pwds-1){break;}
};

//for(int i=0; ;i++){if(i==0){max=b[0];continue;};if(max<b[i]){max=b[i];}if(i==num_pwds-1){break;}};
//for(int i=0; ;i++){if(max==b[i]){re=i;}if(i==num_pwds-1){break;}};
return re;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////