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
int firstMeet(int & exp1, int & exp2, int e1)
{
    int d;
        double E1=e1,EXP1=exp1,EXP2=exp2,D;
        if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(EXP2>600)EXP2=600;
    if(EXP2<0)EXP2=0;
        if(e1>99||e1<0)return -99; else{
   if((e1>=0)&&(e1<=3)){
    if(e1==0)EXP2+=29;
    if(e1==1)EXP2+=45;
    if(e1==2)EXP2+=75;
    if(e1==3)EXP2+=149;
    d=e1*3+EXP1 *7;
    D=d;
    if(d%2==0){EXP1=ceil(EXP1+D/200);}else{EXP1=ceil(EXP1-D/100);}
   } else{
   
    if (3<e1&&e1<20)EXP2=ceil(EXP2+E1/4+19);
    if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(EXP2>600)EXP2=600;
    if(EXP2<0)EXP2=0;
    if (19<e1&&e1<50)EXP2=ceil(EXP2+E1/9+21);
    if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(EXP2>600)EXP2=600;
    if(EXP2<0)EXP2=0;
    if (49<e1&&e1<66)EXP2=ceil(EXP2+E1/16+17);
    if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(EXP2>600)EXP2=600;
    if(EXP2<0)EXP2=0;
    if (65<e1&&e1<80){EXP2=ceil(EXP2+E1/4+19);
    if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(EXP2>600)EXP2=600;
    if(EXP2<0)EXP2=0;
    if(EXP2>200)EXP2=ceil(EXP2+E1/9+21);}
    if (79<e1&&e1<100){EXP2=ceil(EXP2+E1/4+19);if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(EXP2>600)EXP2=600;
    if(EXP2<0)EXP2=0;
    EXP2=ceil(EXP2+E1/9+21);if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(EXP2>600)EXP2=600;
    if(EXP2<0)EXP2=0;
if(EXP2>400){EXP2=ceil(EXP2+E1/16+17);
EXP2=ceil(EXP2+0.15*EXP2);
   }}
   EXP1-=e1;}}
   if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(EXP2>600)EXP2=600;
    if(EXP2<0)EXP2=0;
   exp1=EXP1;
   exp2=EXP2;
   return EXP1+EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
	if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(HP1>666)HP1=666;
    if(HP1<0)HP1=0;
	if(M1>3000)M1=3000;
	if(M1<0)M1=0;
     int a,b,s;
int c=M1;
    float P1,P2,P3,Pi[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    //Bat dau duong 1
    if(E2<0||E2>99){return -99;}else{
for(int i = 0; i < 27; i++)
{if(EXP1-i*i<=0){a=i;
    /* code */break;
}}
s=a*a;
b=a-1;
if(abs(EXP1-a*a)>abs(EXP1-b*b))s=b*b;
if (EXP1>=s)P1=100;
else P1=(EXP1/s+80)*100/123;
//Het duong 1
//Bat dau duong 2
if (E2%2!=0){while (M1>=0.5*c)
{  if(HP1<200){
    HP1=ceil(float(HP1*1.3));
     M1-=150;
     if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(HP1>666)HP1=666;
    if(HP1<0)HP1=0;
	if(M1>3000)M1=3000;
	if(M1<0)M1=0;
}else{HP1=ceil(float(HP1*1.1));
M1-=70;
if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(HP1>666)HP1=666;
    if(HP1<0)HP1=0;
	if(M1>3000)M1=3000;
	if(M1<0)M1=0;
}
if(M1<0.5*c)break;
if (EXP1<400)M1-=200;else M1-=120;
EXP1=ceil((EXP1*1.13));
if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(HP1>666)HP1=666;
    if(HP1<0)HP1=0;
	if(M1>3000)M1=3000;
	if(M1<0)M1=0;
if(M1<0.5*c)break;
if(EXP1<300)M1-=100;else M1-=120;
EXP1=ceil((EXP1*0.9));
if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(HP1>666)HP1=666;
    if(HP1<0)HP1=0;
	if(M1>3000)M1=3000;
	if(M1<0)M1=0;}
}
else
{if(HP1<200){
    HP1=ceil(float(HP1*1.3));
     M1-=150;
     if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(HP1>666)HP1=666;
    if(HP1<0)HP1=0;
	if(M1>3000)M1=3000;
	if(M1<0)M1=0;
}else{HP1=ceil(float(HP1*1.1));
M1-=70;
if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(HP1>666)HP1=666;
    if(HP1<0)HP1=0;
	if(M1>3000)M1=3000;
	if(M1<0)M1=0;
}
if (EXP1<400)M1-=200;else M1-=120;
EXP1=ceil(float(EXP1*1.13));
if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(HP1>666)HP1=666;
    if(HP1<0)HP1=0;
	if(M1>3000)M1=3000;
	if(M1<0)M1=0;
if(EXP1<300)M1-=100;else M1-=120;
EXP1=ceil(float(EXP1*0.9));
if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(HP1>666)HP1=666;
    if(HP1<0)HP1=0;
	if(M1>3000)M1=3000;
	if(M1<0)M1=0; }
HP1=ceil(float(HP1*0.83));
EXP1=ceil(float(EXP1*1.17));
if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(HP1>666)HP1=666;
    if(HP1<0)HP1=0;
	if(M1>3000)M1=3000;
	if(M1<0)M1=0;
for(int i = 0; i < 27; i++)
{if(EXP1-i*i<0){a=i;
    break;
}}
s=a*a;
b=a-1;
if(abs(EXP1-a*a)>abs(EXP1-b*b))s=b*b;
if (EXP1>=s)P2=100;
else P2=(EXP1/s+80)*100/123;
//Het duong 2
//bat dau duong 3
int T=0;
if(E2/10==0)P3=Pi[E2];else{T+=(E2%10);
E2=E2/10;T+=E2;
P3=Pi[T%10];
}
//Het duong 3
if(P1==P2==P3==1){return -99;}
if(((P1+P2+P3)/3)>=50){HP1=ceil(float(HP1*0.9));
EXP1=ceil(float(EXP1*1.2));}else{HP1=ceil(float(HP1*0.85));
EXP1=ceil(float(EXP1*1.15));}
if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(HP1>666)HP1=666;
    if(HP1<0)HP1=0;
	if(M1>3000)M1=3000;
	if(M1<0)M1=0;
return EXP1+M1+HP1;}}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
  int mp[10][10];
        int p=0,n=0,a,b,x,y,z,t,t1=0,t2=0;
        float exp1=EXP1,exp2=EXP2,hp1=HP1,hp2=HP2;
    if(E3<0||E3>99)return -99;else{
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                mp[i][j]=(E3*j+i*2)*(i-j);
                if(mp[i][j]>(E3*2))p++;
                if(mp[i][j]<(-E3))n++;
            }
        }
        a=p;b=n;
        while(a>9){
        while(p!=0){
            t1+=(p%10);
            p/=10;
        }
        a=t1;
        p=a;
        t1=0;
        }
        while(b>9){
        while(n!=0){
            t2+=(n%10);
            n/=10;
        }
        b=t2;
        n=b;
        t2=0;
        }
        x=mp[a][b];
        y=mp[a][b];
        z=a;
        t=b;
        while((a!=0)and(b!=9)){
            a--;
            b++;
        }
        while((z!=0)and(t!=0)){
            z--;
            t--;
        }
        while((a!=10)and(b!=-1)){
            if(mp[a][b]>x)x=mp[a][b];
            a++;
            b--;
        }
        while((z!=10)and(t!=10)){
            if(mp[z][t]>x)x=mp[z][t];
            z++;
            t++;
        }
if(x>=abs(y)){
    exp1=ceil(float(exp1*1.12));
    exp2=ceil(float(exp2*1.12));
    hp1=ceil(float(hp1*1.1));
   hp2=ceil(float(hp2*1.1));
}
else{
    exp1=ceil(float(exp1*0.88));
    exp2=ceil(float(exp2*0.88));
    hp1=ceil(float(hp1*0.9));
   hp2=ceil(float(hp2*0.9));
}
EXP1=exp1;
EXP2=exp2;
HP1=hp1;
HP2=hp2;
if(EXP1>600)EXP1=600;
    if(EXP1<0)EXP1=0;
    if(EXP2>600)EXP2=600;
    if(EXP2<0)EXP2=0;
    if(HP1>666)HP1=666;
    if(HP2>666)HP2=666;
    if(HP1<0)HP1=0;
    if(HP2<0)HP2=0;
if(x>abs(y)) return x;else{return y;}}
}


// Task 4
int checkPassword(const char * s, const char * email) 
{
     int a,b;
    string se;
    bool q=true,p,u;
   for(int i=0;email[i]!='@';i++ ){
    se+=email[i];
   }
    for(int i=0;i<strnlen(s,25);i++){
        for(int j=0;j<se.size();j++){
            if(s[i+j]==se[j])q=true;else{q=false;}
            if(q==false)break;
        }
        a=i;
        if(q)break;
    }
    for(int i=0;i<strnlen(s,25);i++){
        if(s[i]==s[i+1]&&s[i]==s[i+2])p=true;else{p=false;}
        b=i;
        if(p)break;
    }
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='#'||s[i]=='@'||s[i]=='%'||s[i]=='$'||s[i]=='!')u=true;else{u=false;}
        if(u)break;
    }
if(strnlen(s,25)<8)return -1;
else{if(strnlen(s,25)>20)return -2;
else{if(q||se.size()==0)return -(300+a);
else{if(p)return -(400+b);
else{if(u==false)return -5;
else{return -10;}}}}}
}


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
	int t=1,b=0,r;
    for(int i=0;i<num_pwds;i++){
    	for(int j=0;j<num_pwds;j++){if(arr_pwds[i]==arr_pwds[j])t++;
    	
	}
	if(t>b){b=t;
	r=i;
	}
	if(t==b){if(strnlen(arr_pwds[i],21)>strnlen(arr_pwds[r],21))r=i;
	}
	t=1;
    }
    return r;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////