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



//task1:
int firstMeet( int &exp1,int &exp2,int e1) {
    float EXP;
    int D;
float EXP1=exp1;
float EXP2=exp2;
int E1=e1;
if (E1<0||E1>99){EXP=-99;if (EXP1<0){EXP1=0;}
if (EXP2<0){EXP2=0;}
if (EXP1>600){EXP1=600;}
if (EXP2>600){EXP2=600;}}
else if (E1>=0 && E1 <=3)
{
if (EXP1<0){EXP1=0;}
if (EXP2<0){EXP2=0;}
if (EXP1>600){EXP1=600;}
if (EXP2>600){EXP2=600;}
if (E1==0){EXP2=EXP2+29;
}
else if (E1==1){EXP2=EXP2+45;
}
else if (E1==2){EXP2=EXP2+75;
}
else {EXP2=EXP2+29+45+75;
}
if (EXP1<0){EXP1=0;}
if (EXP2<0){EXP2=0;}
if (EXP1>600){EXP1=600;}
if (EXP2>600){EXP2=600;}
D=E1*3+EXP1*7;
float d=D;
if (D%2==0){
   EXP1=ceil(EXP1+d/200*1.00);
  }
else {EXP1=ceil(EXP1-d/100*1.00);
}
}
else {
if (EXP1<0){EXP1=0;}
if (EXP2<0){EXP2=0;}
if (EXP1>600){EXP1=600;}
if (EXP2>600){EXP2=600;}
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
exp1=EXP1;
exp2=EXP2;
EXP=EXP1+EXP2;
return (EXP);
}

//task2
int traceLuggage(int  &HP1, int &EXP1, int  &M1, int E2)
{
float hp1=HP1,exp1=EXP1,m1=M1;
/*conduongso1*/
int a,Sum;
float S,P1,P2,P3,R;
int P=100;
R=M1;
if (E2<0||E2>99)
{
Sum=-99;
if (hp1<0){hp1=0;}
if (hp1>666){hp1=666;}
if (exp1<0){exp1=0;}
if (exp1>600){exp1=600;}
if (m1<0){m1=0;}
if (m1>3000){m1=3000;}
}
else {
if (hp1<0){hp1=0;}
if (hp1>666){hp1=666;}
if (exp1<0){exp1=0;}
if (exp1>600){exp1=600;}
if (m1<0){m1=0;}
if (m1>3000){m1=3000;}

a=floor(sqrt(exp1));
if ((exp1-a*a)<=((a+1)*(a+1)-exp1)){S=a*a;P1=100;}
else {S=(a+1)*(a+1);P1=1.00*(exp1/S+80)/123*100;}
P1=ceil(P1);
/*conduongso2*/

if(E2%2!=0)
{
    do{if (hp1<200){hp1=ceil(hp1+0.30*hp1);m1=m1-150; if (hp1<0){hp1=0;}
if (hp1>666){hp1=666;}
if (exp1<0){exp1=0;}
if (exp1>600){exp1=600;}
if (m1<0){m1=0;}
if (m1>3000){m1=3000;}}
else {hp1=ceil(hp1+0.1*hp1); m1=m1-70;if (hp1<0){hp1=0;}
if (hp1>666){hp1=666;}
if (exp1<0){exp1=0;}
if (exp1>600){exp1=600;}
if (m1<0){m1=0;}
if (m1>3000){m1=3000;}}
if( (R-m1)>=0.5*R ){
if (hp1<0){hp1=0;}
if (hp1>666){hp1=666;}
if (exp1<0){exp1=0;}
if (exp1>600){exp1=600;}
if (m1<0){m1=0;}
if (m1>3000){m1=3000;}
        break;
        }
if (exp1>400){m1=m1-120;if (hp1<0){hp1=0;}
if (hp1>666){hp1=666;}
if (m1<0){m1=0;}
if (m1>3000){m1=3000;}}
else {m1=m1-200;if (hp1<0){hp1=0;}
if (hp1>666){hp1=666;}

if (m1<0){m1=0;}
if (m1>3000){m1=3000;}}
exp1=ceil(exp1*1.13);

if (hp1<0){hp1=0;}
if (hp1>666){hp1=666;}
if (exp1<0){exp1=0;}
if (exp1>600){exp1=600;}
if (m1<0){m1=0;}
if (m1>3000){m1=3000;}
if( (R-m1)>=0.5*R ){
        break;
        }
if (exp1<300){m1=m1-100;if (hp1<0){hp1=0;}
if (hp1>666){hp1=666;}
if (exp1<0){exp1=0;}
if (exp1>600){exp1=600;}
if (m1<0){m1=0;}
if (m1>3000){m1=3000;}}
else {m1=m1-120;if (hp1<0){hp1=0;}
if (hp1>666){hp1=666;}
if (exp1<0){exp1=0;}
if (exp1>600){exp1=600;}
if (m1<0){m1=0;}
if (m1>3000){m1=3000;}}
exp1=ceil(exp1*0.90);
if (hp1<0){hp1=0;}
if (hp1>666){hp1=666;}
if (exp1<0){exp1=0;}
if (exp1>600){exp1=600;}
if (m1<0){m1=0;}
if (m1>3000){m1=3000;}
if( (R-m1)>=0.5*R ){
        break;
        }
    }
    while ((R-m1)<=0.5*R);
}
else {

for (int i=1; i<2; i++) {
if (m1<=0){m1=0;break;}
if (hp1<200){hp1=ceil(hp1+0.30*HP1);m1=m1-150;
if (hp1<0){hp1=0;}
if (hp1>666){hp1=666;}
if (m1<=0){m1=0;break;}
if (m1>3000){m1=3000;}
}
else {hp1=ceil(hp1+0.1*hp1); m1=m1-70;if (hp1<0){hp1=0;}
if (hp1>666){hp1=666;}
if (m1<=0){m1=0;break;}
if (m1>3000){m1=3000;}}

if (exp1>400){m1=m1-120;
exp1=ceil(exp1*1.13);
if (exp1<0){exp1=0;}
if (exp1>600){exp1=600;}
if (m1<=0){m1=0;break;}
if (m1>3000){m1=3000;}}
else {m1=m1-200;
exp1=ceil(exp1*1.13);
if (exp1<0){exp1=0;}
if (exp1>600){exp1=600;}
if (m1<=0){m1=0;break;}
if (m1>3000){m1=3000;}}

if (exp1<300){m1=m1-100;
exp1=ceil(exp1*0.90);

if (exp1<0){exp1=0;}
if (exp1>600){exp1=600;}

if (m1<=0){m1=0;break;}
if (m1>3000){m1=3000;}}
else {m1=m1-120;
exp1=ceil(exp1*0.90);

if (exp1<0){exp1=0;}
if (exp1>600){exp1=600;}

if (m1<=0){m1=0;break;}
if (m1>3000){m1=3000;}}

}
}
/*dunglai*/
hp1=ceil((1-0.17)*hp1);
if (hp1<0){hp1=0;}
if (hp1>666){hp1=666;}
exp1=ceil((1+0.17)*exp1);
if (exp1<0){exp1=0;}
if (exp1>600){exp1=600;}
a=sqrt(exp1);
if ((exp1-a*a)<=((a+1)*(a+1)-exp1)){S=a*a;P2=100;}
else {S=(a+1)*(a+1);P2=ceil(1.00*(exp1/S+80)/123*100);}

/*conduongso3*/
int ratio[10]={32,47,28,79, 100, 50, 22, 83, 64, 11};
if (E2>=0 && E2<=9){P3=ratio[E2];}
else {
    int d=E2/10+E2%10;
    P3=ratio[d%10];
}
/*trungbinh*/
P=(P1+P2+P3)/3;

if(P==100){exp1=0.75*exp1;}
else if (P<50){hp1=ceil(0.85*hp1);
    exp1=ceil(1.15*exp1);

}
else {hp1=ceil(0.9*hp1);
    exp1=ceil(1.2*exp1);

}

if (hp1<0){hp1=0;}
if (hp1>666){hp1=666;}
if (exp1<0){exp1=0;}
if (exp1>600){exp1=600;}
if (m1<0){m1=0;}
if (m1>3000){m1=3000;}
Sum=hp1+exp1+m1;
HP1=hp1;
EXP1=exp1;
M1=m1;
}
return (Sum);
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3){
	int m,n;
float exp1=EXP1;
float exp2=EXP2;
float hp1=HP1,hp2=HP2;
int maxtTaxi[10][10];
if (E3<0||E3>99){
    return -99;
}
else{
    m=0;n=0;
    for (int i=0; i<10;i++)
    {
for (int j=0; j<10; j++)
        {
            maxtTaxi[i][j]=((E3*j)+(i*2))*(i-j);
            if (maxtTaxi[i][j]>0&&maxtTaxi[i][j]>2*E3) {m=m+1;}
            else if (maxtTaxi[i][j]<0&&maxtTaxi[i][j]<(-E3)) {n=n+1;}

        }

    }
int maxtSW[10][10];
for (int i=0; i<10;i++)
    {
        for (int j=0; j<10; j++)
        {
            maxtSW[i][j]=maxtTaxi[i][j];
        }

    }
 for (int i=0; i<10;i++)
    {
        for (int j=0; j<10; j++)
        {
           int x=0,y=0;
           while (i-x>=0&&j-x>=0){
               while(i+y<=9&&j+y<=9){
                   if (maxtSW[i][j]<=maxtSW[i+y][j+y]){maxtSW[i][j]=maxtSW[i+y][j+y];}
                   if (maxtSW[i][j]<=maxtSW[i-x][j-x]){maxtSW[i][j]=maxtSW[i-x][j-x];}
                    y++;
                   }
                  x++;
               }

        }

        }
for (int i=0;i<10;i++){
    for (int j=0;j<10;j++){
        if (i+j<=9){
            for (int k=0;k<=(i+j);k++)
            {
                if (maxtSW[i][j]<=maxtTaxi[k][i+j-k])
                {maxtSW[i][j]=maxtTaxi[k][i+j-k];}
             }
}

                else {
                    for (int k=9;k>=i+j-9;k--)
                    {if (maxtSW[i][j]<=maxtTaxi[k][i+j-9])
                    {maxtSW[i][j]=maxtTaxi[k][i+j-9];}
                    }
}
}
}
while (m>=10||n>=10){
m=m/10+m%10;
n=n/10+n%10;}

if (abs(maxtTaxi[m][n])>abs(maxtSW[m][n]))
{
    exp1=exp1*0.88;
    hp1=hp1*0.9;
    exp2=exp2*0.88;
    hp2=hp2*0.9;
if (exp1<0){exp1=0;}
if (exp1>600){exp1=600;}
if (hp1>666){hp1=666;}
if (hp1<0){hp1=0;}
if (exp2<0){exp2=0;}
if (exp2>600){exp2=600;}
if (hp2>666){hp2=666;}
if (hp2<0){hp2=0;}
EXP1=ceil(exp1);
HP1=ceil(hp1);
EXP2=ceil(exp2);
HP2=ceil(hp2);
    return maxtTaxi[m][n];
}
else {
    exp1=exp1*1.12;
    hp1=hp1*1.1;
    exp2=exp2*1.12;
    hp2=hp2*1.1;
if (exp1<0){exp1=0;}
if (exp1>600){exp1=600;}
if (hp1>666){hp1=666;}
if (hp1<0){hp1=0;}
if (exp2<0){exp2=0;}
if (exp2>600){exp2=600;}
if (hp2>666){hp2=666;}
if (hp2<0){hp2=0;}
EXP1=ceil(exp1);
HP1=ceil(hp1);
EXP2=ceil(exp2);
HP2=ceil(hp2);
    return maxtSW[m][n];
}
}
}



//task 4
int checkPassword(const char* s, const char* email)
{
    int a;
    float sci,sei;
std::string s1=std::string(s);
std::string email1=std::string(email);
     std::string se;
    if (s1.length()>20){a=-2;}
    else if (s1.length()<8){a=-1;}
    else{

       for (int i=0; i<email1.length();i++)
       {
          if (email1[i]=='@')
     {sei=i;se=email1.substr(0,i);}
       }
       for (int j=0; j<s1.length();j++)
       {
           if (s1.substr(j,sei)==se){sei=j;a= -300-sei; break;}

                else {
               if (s[j]==s[j+1]&&s[j]==s[j+2]){sci=j; a= -400-sci; break;}
               else if (!(s[j]>='A'&& s[j]<='Z')&&!(s[j]>='a'&& s[j]<='z')&&!(s[j]>='0'&& s[j]<='9')&&(s[j]!='@')&& (s[j]!='#')&&( s[j]!='!')&&( s[j]!='%')&&( s[j]!='$')){
                   a=j;break;
               }
               else{
                   if (s[j]=='@'|| s[j]=='#'|| s[j]=='!'|| s[j]=='%'|| s[j]=='$'){
                       a= -10;break;
                   }
                   else {a= -5;}
                    }
               }
               }

}
return a;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int *dem=new int [num_pwds];
    int max, re;
    for (int i = 0; i < num_pwds; i++) dem[i] = 1;
    for (int i = 0; i < num_pwds; i++) {
        for (int j = i + 1; j < num_pwds; j++) {
            if (!strcmp(arr_pwds[i],arr_pwds[j])) dem[i]++;
        }
    }
    max = 0; re=0;
    for (int i = 0; i < num_pwds; i++) {
        if (max < dem[i]) {
            max = dem[i];
            re = i;
        }
        else if (max == dem[i]) {
            if (strlen(arr_pwds[re]) < strlen(arr_pwds[i])) {
                re = i;
                max = dem[i];
            }
        }
    }
    delete[]dem;
    return re;
}



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
