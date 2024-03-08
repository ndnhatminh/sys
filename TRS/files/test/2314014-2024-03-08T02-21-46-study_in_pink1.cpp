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
int resetexp1(int & exp1){
        if (exp1>600) {exp1 = 600;}
        if (exp1<=0){exp1=0;}
        return exp1;
    }
    int resetexp2(int & exp2){
        if (exp2>600){exp2=600;}
        if (exp2<=0){exp2=0;}
        return exp2;
    }
    int resetM1(int & M1){
        if (M1>3000) {M1 = 3000;}
        if (M1<=0){M1=0;}
        return M1;
    }
    int resetHP(int &HP1){
         if (HP1>666) {HP1 = 666;}
        if (HP1<=0){HP1=0;}
        return HP1;
    }
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int D;
    resetexp1(exp1);
    resetexp2(exp2);
    
    

    D = e1*3 + exp1*7;
    if (e1==0) { 
        exp2 = exp2+29;
        
    resetexp2(exp2);
         }
    if (e1==1) {
        exp2 = exp2 + 45;
    
    resetexp2(exp2);
    }
    if (e1==2){
        exp2 = exp2 + 75;
       
    resetexp2(exp2);
    }
    if (e1==3){
        exp2 = exp2 + 29 + 45 + 75;
     
    resetexp2(exp2);
    }
    
 if ((e1>=0)&&(e1<=3)){   
    if (D%2==0){
        exp1 = ceil(exp1 + 1.0*D/200);
        resetexp1(exp1);
    resetexp2(exp2);
    }
    else {
        exp1 = ceil(exp1 - 1.0*D/100);
       
        

    }
    resetexp1(exp1);
 }
if ((e1>=4)&&(e1<=99)){
    if ((e1>=4)&&(e1<=19)){
        exp2 = ceil(exp2 + 1.0*e1/4 + 19);
         resetexp2(exp2);
    }
    if ((e1>=20)&&(e1<=49)){
    exp2 = ceil(exp2 + 1.0*e1/9 + 21);
    resetexp2(exp2);
}
    if ((e1>=50)&&(e1<=65)){
        exp2 = ceil(exp2 + 1.0*e1/16 + 17);
        resetexp2(exp2);
}
    if ((e1>=66)&&(e1<=79)){
        exp2 = ceil(exp2 + 1.0*e1/4 + 19);
       resetexp2(exp2);
        if (exp2 > 200) {
            exp2 = ceil(exp2 + 1.0*e1/9 + 21);
            resetexp2(exp2);
        } 
    }
    if ((e1>=80)&&(e1<=99)){
        exp2 = ceil(exp2 + 1.0*e1/4 + 19);
        resetexp2(exp2);
        exp2 = ceil(exp2 + 1.0*e1/9 + 21);
        resetexp2(exp2);
    if (exp2>400){ 
        exp2 = ceil(exp2 + 1.0*e1/16 + 17); 
        resetexp2(exp2);
        }
        exp2 = ceil(exp2 + 0.15*exp2);
        resetexp2(exp2);
    }
    exp1 = exp1 - e1;
    resetexp1(exp1);
}
    
    
    // tạo hàm phụ kiểm tra tất cả
    return exp1 + exp2;
}
int SCP(int & a){
    int S = sqrt(a);
    if ((abs((S+1)*(S+1)-a))>(abs((S)*(S)-a))){
        S = S*S;
    }
    else {
        S = (S+1)*(S+1);
    }
    return S;

}



// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    
// tạo hàm phụ kiểm tra M1,HP1
resetM1(M1);
    resetexp1(EXP1);
    resetHP(HP1);
int M2 = M1;
int S1= SCP(EXP1);
float p1;
if (EXP1>S1){
    p1 = 1;
}
else {
    p1 = ((float)(EXP1/S1) + 80)/123;
}

if (E2%2==1){
next:
resetM1(M1);
resetexp1(EXP1);
resetHP(HP1);
if (HP1<200){
    HP1 = ceil((float)(HP1+0.3*HP1));
    M1 = M1 -150;
}
else {
    HP1 = ceil((float)(HP1+0.1*HP1));
    M1 = M1 - 70;
}
resetM1(M1);
resetexp1(EXP1);
resetHP(HP1);
if (M1<M2/2){
goto tryAgain;
    }
resetM1(M1);
resetHP(HP1);
resetexp1(EXP1);
if (EXP1<400){
    M1 = M1 -200;
   
   }
else {
    M1 = M1 - 120;
    }
    
    EXP1 = ceil((float)(1.13*EXP1));
    resetM1(M1);
    resetexp1(EXP1);
    resetHP(HP1);
    
    
    if (M1<M2/2){

        goto tryAgain;
    }

if (EXP1<300){
    M1 = M1 - 100;

}
else {
    M1 = M1 -120;
}
EXP1 = ceil((float)(EXP1 - 0.1*EXP1));
   resetM1(M1);
    resetexp1(EXP1);
    
if (M1>M2/2){
    goto next;
    }
}
HP1 = ceil((float)(HP1 - HP1*0.17));
EXP1 = ceil((float)(EXP1 + EXP1*0.17));
    resetexp1(EXP1);
    resetHP(HP1);
if (E2%2==0){

if (HP1<200){
    HP1 = ceil((float)(HP1+0.3*HP1));
    M1 = M1 -150;
    if (M1<0){
        M1 = 0;
        goto tryAgain;
    }
}
else {
    HP1 = ceil ((float)(HP1+0.1*HP1));
    M1 = M1 - 70;

    
    
}
resetM1(M1);
    resetexp1(EXP1);
    resetHP(HP1);
if (M1<0){
        M1 = 0;
        goto tryAgain;
    }
if (EXP1<400){
    M1 = M1-200;
    EXP1 = ceil((float)(EXP1+0.13*EXP1));
    
    
}
else {
    M1 = M1 -120;
    EXP1 = ceil((float)(EXP1+0.13*EXP1));
 
    
    }
    resetM1(M1);
    resetexp1(EXP1);
    resetHP(HP1);
if (M1<0){
    M1==0;
    goto tryAgain;
}


if (EXP1<300){
    M1 = M1 - 100;
    EXP1 = ceil((float)(EXP1 - 0.1*EXP1));
}
else {
    M1 = M1 -120;
    EXP1 = ceil((float)(EXP1 - 0.1*EXP1));
    }
   resetM1(M1);
    resetexp1(EXP1);
    resetHP(HP1);
    
    
}
tryAgain:


HP1 = ceil((float)(HP1 - HP1*0.17));
EXP1 = ceil((float)(EXP1 + EXP1*0.17));

   resetM1(M1);
    resetexp1(EXP1);
    resetHP(HP1);

float p2;
int S2;
S2 = SCP(EXP1);
if (EXP1>S2){
    p2 = 1;
}
else {
    p2 = (EXP1/S2 + 80)/123;
}
int a[]={32,47,28,79,100,50,22,83,64,11};
int i,p3;
float p;
if (E2/10==0){
    i = E2;
    p3 = a[i]/100;
}
if (E2/10>=1){
    i = E2/10 + (E2%10);
    i = i%10;
    p3 = a[i]/100;
}
if ((p1==1)&&(p2==1)&&(p3==1)){
    EXP1 = ceil(EXP1 - 0.25*EXP1);
   
    resetexp1(EXP1);
}
else {
    p = (p1 + p2 + p3)/3;
}
resetexp1(EXP1);
resetHP(HP1);
if (p < 0.5){
    HP1 = ceil((float)(HP1 - 0.15*HP1));
    EXP1 = ceil((float)(EXP1 + 0.15*EXP1));
    resetexp1(EXP1);
    resetHP(HP1);
}
else {
    HP1 = ceil((float)(HP1 - 0.1*HP1));
    EXP1 = ceil((float)(EXP1 + 0.2*EXP1));
    }
resetHP(HP1);
resetexp1(EXP1);
return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    resetexp1(EXP1);
    resetexp2(EXP2);
    resetHP(HP2);
    resetHP(HP1);
    int A[10][10];
     for (int i=0;i<10;i++)
{     for (int j=0;j<10;j++)
      {  A[i][j]=(E3*j +(i*2))*(i-j);
          }
    }
  
     int dem=0,count=0;
      for (int i=0;i<10;i++)
{     for (int j=0;j<10;j++)
      {  if ((A[i][j]>(E3*2)))
          dem++;
          }
    }

     for (int i=0;i<10;i++)
{     for (int j=0;j<10;j++)
      {  if ((A[i][j]<(-E3)))
         count++;
          }
    }
  int i=0,j=0; //set điểm gặp nhau
   int c,d;
   int e,f,g;
    
    if ( dem<10) i=dem;
   
    c=dem/10;
    d=dem%10;
    
    if ( (d+c) <10) i=d+c;
    else 
    { g=d+c;
     f=g/10;
     e=g%10;
      i=f+e;
        }
    
    if (count<10) j=count;
    c=count/10;
    d=count%10;
    
     if ( (d+c) <10) j=d+c;
    else 
    { g=d+c;
     f=g/10;
     e=g%10;
      j=f+e;
        } 
    int a=i,b=j;
 
 int max=A[i][j]; 
  while ( a>0 && b>0) // trái lùi
{   a--;
    b--;
    if (max < A[a][b] )
    max=A[a][b];
    }

int a1,b1;
  a1=i;b1=j;
  while ( a1 <9 && b1>0) // phải lùi
{   a1++;
    b1--;
    if (max < A[a1][b1] )
    max=A[a1][b1];
    }

 int a2,b2;
  a2=i;b2=j;
  while ( a2 <9 && b2<9) // trái tới
{   a2++;
    b2--;
    if (max < A[a2][b2] )
    max=A[a2][b2];
    }

int a3,b3;
  a3=i;b3=j;
  while ( a3 >0 && b3<9) // phải tới
{   a3--;
    b3++;
    if (max < A[a3][b3] )
    max=A[a3][b3];
    
    }
  
  
  if ( abs(max*1.0)  >= abs(  A[i][j]*1.0 ) ) 
  
 {   EXP1=ceil(1.12*EXP1) ; 
     HP1= ceil(1.1*HP1); 
     EXP2= ceil(1.12*EXP2); 
     HP2= ceil(1.1*HP2) ; 
    resetexp1(EXP1);
    resetexp2(EXP2);
    resetHP(HP2);
    resetHP(HP1);
    return max;
     }
    else 
    {
     EXP1=ceil(0.88*EXP1); 
     HP1= ceil(0.9*HP1); 
     EXP2=ceil(0.88*EXP2) ; 
     HP2= ceil(0.9*HP2); 
         
      return A[i][j];
    return -1;

}
}

 int checkchuoichuase( string S, string se){
    int result=0;
   for (int i=0;i<S.length()-se.length();i++){
        
    if (se == S.substr(i,se.length())) {
        result = result + 1;
        break;
            }
            
        
    }
    return result;
   
 }   
 int checkkytulientiep(string S){
    for (int i=0;i<S.length();i++){
        if ((S[i]==S[i+1])&&(S[i+1]==S[i+2])){
            return 1 ;
        }
        
    }
    return 0;
 }
int returnvitrikytulientiep(string S){
    
    int i,vt=0;
    for(i = 0; i < S.length(); i++){
        if((S[i] == S[i+1])&&(S[i+1] == S[i+2])) {
             vt = -400+i;
            }
        }
    
   return vt; 
}
 
 int checkkytudacbiet(string S){
    int p=0;
    for(int j = 0; j < S.length(); j++){
        if(S[j]=='@' || S[j]=='!'||S[j]=='%'||S[j]=='$'||S[j]=='#'){ 
            p=p+1;
            }
    
    }
   return p;
 }
int vitrixause(string S, string se){
    int result=-1 ;
    for (int i=0;i<S.length()-se.length();i++){
        
    if (se == S.substr(i,se.length())) {
    result = -300 - i;
    break;
        
    }
    }
          return result;

}

    

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string S = s;
    string Email = email;
    string se;
    int j;
    for (int i=0;i<Email.length();i++){
        if (Email[i]=='@'){ //abcd@
            se = Email.substr(0,i-1);
        }
    }
     
    ;
   
if (S.length()<8){return -1;}
else if (S.length()>20){return -2;}
else if (checkchuoichuase(S,se)){
  
    return vitrixause(S,se);}
else if (checkkytudacbiet(S)==0){return -5;}
else if (checkkytulientiep(S)==1) {return returnvitrikytulientiep(S); }
else if ((checkchuoichuase(S,se)==1)&&(checkkytulientiep(S)==1)){
    if (returnvitrikytulientiep(S)+400 < vitrixause(S,se)) {
        return returnvitrikytulientiep(S);
    }
    else { 
       
    return vitrixause(S,se);}
}
else {
    for(int i = 0; i < S.length(); i++){
            if(((int)(S[i])>=48 && (int)(S[i])<=57) || ((int)(S[i])>=65 && (int)(S[i])<=90) || ((int)S[i]>=97 && (int)S[i]<= 122)) {return -10;}
        }
}
return -99;
}
    

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
// dùng mảng phụ b lưu số lần xuất hiện của a[i]
// khoi tao b[m]=0
// tim phan tu max trong mảng b và biet a[i]
int b[num_pwds];
for (int i=0;i<num_pwds;i++){
    b[i]=0;
    for (int j=i;j<=num_pwds-i+1;j++){
        if (arr_pwds[j]==arr_pwds[i]){
            b[i]=b[i]+1;
        }
    }
}
// 1,1,3,1,5
int max=1;
for (int i=0;i<num_pwds;i++){
    if (b[i]>max){
        max = b[i];
    }
}
string S[num_pwds];
for (int i=0;i<num_pwds;i++){
    S[i] = "0";
}
for (int i=0;i<num_pwds;i++){
    if (b[i]==max){
        S[i]=arr_pwds[i];
        // mảng gồm những phần tử có số lần trùng nhau lớn nhất bằng nhau
    }

}

int MAX=1;
int result;
for (int i=0;i<num_pwds;i++){
    

    
    if (S[i].length()>MAX){
        MAX=S[i].length();
    
    }
}
for (int i=0;i<num_pwds;i++){
    if (S[i].length()==MAX){
        result = i;
        break;
        
    }

}
    return result;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////