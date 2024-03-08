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
bool matkhaudaco(string matkhau[], string matkhauvao, int size) {
    for (int i = 0; i < size; i++) {
        if (matkhauvao == matkhau[i]) return false;
    }
    return true;
}


int findS (int n,int &S) {
  if ( abs((int(sqrt(n)) + 1) * (int(sqrt(n)) + 1) - n) < abs(int(sqrt(n)) * int(sqrt(n)) - n) )
  S= (int(sqrt(n))+1)*(int(sqrt(n))+1);
  else
  S= int(sqrt(n))*int(sqrt(n));
return S;
}

int secondWay(int Tien,int & HP1, int & EXP1, int & M1, int E2) {

if((Tien-M1)<=0.5*Tien) {
if (HP1<200) {
HP1=HP1+ceil(float(HP1)*30.0/100.0);
M1=(M1-150);}
else {
HP1=HP1+ceil(float(HP1)*10.0/100.0);
M1=M1-70;}
if (HP1>666) HP1=666;
if (M1<0) M1=0;
}

if((Tien-M1)<=0.5*Tien) {
if (EXP1<400) {
M1=(M1-200);
EXP1=(EXP1+ceil(float(EXP1)*13.0/100.0));}
else {
M1=(M1-120);
EXP1=(EXP1+ceil(float(EXP1)*13.0/100.0));}
if (M1<0){M1=0;}
if (EXP1>600) EXP1=600;
}

if((Tien-M1)<=0.5*Tien) {
if (EXP1<300) {
M1=(M1-100);
EXP1=ceil(float(EXP1*90.0/100.0));}
else {
M1=(M1-120);
EXP1=ceil(float(EXP1*90.0/100.0));}
if (M1<0) M1=0;
}
return HP1,EXP1,M1;
}
////////////////////////////////////////////////////////////////////////

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
if((e1<0) ||(e1>99)) return -99;
if ((e1>=0)&&(e1<=3))
{ switch(e1) {
case 0: {exp2 +=29;break;}
case 1: {exp2 += 45;break;}
case 2: {exp2 += 75;break;}
case 3: {exp2 = exp2 +149;break;}
}
int D=e1*3 + exp1 *7;
if (D%2==0) {exp1=ceil(exp1 +float(D)/200);}
else {exp1=ceil(exp1-float(D)/100);}
if (exp1>600) exp1 =600;
if (exp2>600) exp2 =600;
if (exp1<0) exp1=0;
}
else
{ if ((e1>=4)&&(e1<=19)) {exp2= ceil(exp2 + float(e1)/4+19);}
else if ((e1>=20) && (e1<=49)) {exp2=ceil(exp2 + float(e1)/9+21);}
else if ((e1>=50) && (e1<=65)) {exp2=ceil(exp2 + float(e1)/16+17);}
else if ((e1>=66) && (e1<=79)) { exp2=ceil(exp2 + float(e1)/4+19); 
     if (exp2>200) exp2=ceil(exp2 + float(e1)/9+21); }
else if((e1>=80) && (e1<=99))
{ exp2=ceil(exp2 + float(e1)/4+19);
exp2=ceil(exp2 + float(e1)/9+21);
if (exp2 >400)
{
exp2=ceil(exp2 + float(e1)/16+17);
exp2= ceil(float(exp2)*1.15);
}
} 
if (exp2>600) exp2=600;
exp1=exp1 -e1;
if (exp1>600) exp1 =600;
if (exp1<0) exp1=0;

}
return exp1 + exp2;
}




// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
if ((E2<0)||(E2>99)) return -99;
int S,Tien;
Tien=M1;
double P1,P2,P3;
S=findS(EXP1,S);
if (EXP1>=S)
P1=1.0;
else
P1= (((double(EXP1)/S)+80)/123);
if ((E2%2)==1) {
while ((Tien-M1)<=0.5*Tien){
secondWay(Tien,HP1,EXP1,M1,E2);}
HP1=ceil((float(HP1)*83.0/100.0));
EXP1=ceil((float(EXP1)*117.0/100.0));
if (EXP1>600) EXP1=600;
} else {

if (M1>0) {
if (HP1<200) {
HP1=HP1+ceil(float(HP1)*30.0/100.0);
M1=(M1-150);}
else {
HP1=HP1+ceil(float(HP1)*10.0/100.0);
M1=M1-70;}
if (HP1>666) HP1=666;
if (M1<0) M1=0;
}

if (M1>0) {
if (EXP1<400) {
M1=(M1-200);
EXP1=(EXP1+ceil(float(EXP1)*13.0/100.0));}
else {
M1=(M1-120);
EXP1=(EXP1+ceil(float(EXP1)*13.0/100.0));}
if (M1<0){M1=0;}
if (EXP1>600) EXP1=600;
}

if (M1>0) {
if (EXP1<300) {
M1=(M1-100);
EXP1=ceil(float(EXP1*90.0/100.0));}
else {
M1=(M1-120);
EXP1=ceil(float(EXP1*90.0/100.0));}
if (M1<0) M1=0;
}

HP1=ceil((float(HP1)*83.0/100.0));
EXP1=ceil((float(EXP1)*117.0/100.0));
if (EXP1>600) {EXP1=600;}
}

S=findS(EXP1,S);
if (EXP1>=S)
P2=1.0;
else
P2=  (((double(EXP1)/S)+80)/123);
int i;
int P[10]= {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
if (E2<10) {
P3= (float(P[E2]))/100;
}
else if ((E2>=10)&&(E2<=99))
{int sum = (E2 / 10) + (E2 % 10);
 sum = sum % 10;
 P3= (float(P[sum]))/100;}

if ((P1==P2)&&(P2==P3)&&(P1==1)) {
EXP1=(ceil((float(EXP1)*75.0/100.0)));
}
else if (((P1+P2+P3)/3)>0.5) {
HP1=ceil((float(HP1)*90.0/100.0));
EXP1=(ceil((float(EXP1)*120.0/100.0)));
if (EXP1>600) EXP1=600;
} else {
HP1=ceil((float(HP1)*85.0/100.0));
EXP1=ceil((float(EXP1)*115.0/100.0));
if (EXP1>600) EXP1=600;
}
return HP1+EXP1+M1;
}

//Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
if ((E3<0)||(E3>99)) {return -99;}
int taxi [10][10] ={{0}};
 for (int i=0;i<10;i++){
 for (int j=0;j<10;j++) {
    taxi [i][j]= ((E3 * j) + (i *2)) * (i -j);
    }}


int max = 0;
int min = 0;

for (int i = 0; i < 10; i++) {
for (int j = 0; j < 10; j++) {
if (taxi[i][j] > (2 * E3)) {
    max++;
} else if (taxi[i][j] < ( -E3)) {
    min++;
}}}

while( ((max)>=10)&&((max)<=99))
{ max=max/10 +max%10;}
while( ((min)>=10)&&((min)<=99))
{ min=min/10 +min%10;}
// xác định vị trí
int point = taxi[max][min];
int a,b;
a=max;
b=min;

if (max >min ) {
max=max-min;
min =0;
}

if (max <=min ) {
min=min-max;
max=0;
}
int maxLeft,maxRight;
maxLeft=taxi[max][min];
maxRight=taxi[max][min];
while ((max<=9)&&(min<=9)) {
if (maxLeft< taxi[max][min])
{maxLeft= taxi[max][min];}
max++;
min++;
}

while ( (a!=0) && (b!=9) )
{a--;
b++;}

while ( (a<10)&&(b>=0))
{ if (maxRight<=taxi[a][b]){ maxRight=taxi[a][b];}
 a++;
b--;}

int S;
if ((maxRight)>(maxLeft)){ S=maxRight;}
else {S=maxLeft;}
if (abs(point)>S)
{EXP1=ceil((EXP1)*88.0/100.0);
HP1 =ceil((HP1)*90.0/100.0);
EXP2=ceil((EXP2)*88.0/100.0);
HP2 =ceil((HP2)*90.0/100.0);
S=point;
} else {
EXP1=ceil((EXP1)*112.0/100.0);
HP1 =ceil((HP1)*110.0/100);
EXP2=ceil((EXP2)*112.0/100);
HP2 =ceil((HP2)*110.0/100); 
if (EXP1>600) EXP1=600;
if (EXP2>600) EXP2=600;
if (HP1>666) HP1=666;
if (HP2>666) HP2=666;
S=S;
}    

    return S;
}

// Task 4
int checkPassword(const char * s, const char * email) {
   // TODO: Complete this function
string se;
int k=0;
while ( email [k] != '@') {
se = se +email [k];
k++;
  }

int soluongtrung=1;
int strlens=0;
for (int i=0; s[i] != '\0';i++) { strlens++; }
if ( (strlens <8)) return -1;
if ( (strlens >20)) return -2;
if (k==0 ) return -(300);
for (int i = 0; i < strlens; i++) {
if (s[i] == se[0]) {
for (int c = 1; c < se.length(); c++)
 {
if (se[c] == s[i + c])soluongtrung++; 
 }
    
       
       if (soluongtrung == se.length()) return -(300 + i);
          else soluongtrung=1;

}}
 

for (int i=2; i<strlens;i++){
if ((s[i]==s[i-1])&&((s[i]==s[i-2]))){ return -(400+i-2);}
}

int sum=0;
for (int i=0; i<strlens;i++){
if ((s[i] == '@') || ((s[i]) == '#') || (s[i] == '%') || (s[i] == '$') || (s[i] == '!')) { sum=sum+1; } }
if (sum<1) {return -5;}

for( int i=0; i<strlens;i++) {
if (!isalnum(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') return i; }



return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
// TODO: Complete this function
    string matkhau[30];
    int soluong[30] = {0};
    int a = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (!matkhaudaco(matkhau, arr_pwds[i], a)) continue;
        matkhau[a] = arr_pwds[i];
        a++;
    }

    for (int i = 0; i < a; i++) {
    for (int j = 0; j < num_pwds; j++) {
    if (matkhau[i] == arr_pwds[j]) {
    soluong[i]++;}}}
// Tìm mật khẩu dài nhất và nhiều nhất
    int max = 0;
    int len = 0;
    int index = 0;
    for (int i = 0; i < a; i++) {
    if (soluong[i] > max || (soluong[i] == max && matkhau[i].length() > len)) {
    max = soluong[i];
    len = matkhau[i].length();
    index = i; }}
// tìm return
    for (int i = 0; i < num_pwds; i++) { 
  
    if (matkhau[index]==arr_pwds[i]) {index=i; break;}}
    return index;

}
    


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
