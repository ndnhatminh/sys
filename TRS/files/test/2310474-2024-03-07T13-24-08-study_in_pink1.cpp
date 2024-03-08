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
    // TODO: Complete this function
      if (e1<0 or e1>99)
      return -99;
        if (exp1 > 600)
     exp1 =600;
    if (exp2 > 600)
     exp2 =600;
    if (exp1 <0 )
    exp1 =0;
if (exp2 <0 )
    exp2 =0;
  
int d=e1*3 + exp1*7;
    if (e1==0) {
        exp2 += 29;
   if (d%2==0) {
            exp1 = ceil(exp1 + d*1.0/200);
        } else {
            exp1 = ceil(exp1 - d*1.0/100);
        }
    }else if (e1==1){
        exp2 += 45;
    if (d%2==0) {
            exp1 = ceil(exp1 + d*1.0/200);
        } else {
            exp1 = ceil(exp1 - d*1.0/100);
        }
    }else if (e1==2){
        exp2 += 75;
   if (d%2==0) {
            exp1 = ceil(exp1 + d*1.0/200);
        } else {
            exp1 = ceil(exp1 - d*1.0/100);
        }
    }else if (e1==3){
       exp2 += 29 + 45 +75;
       if (d%2==0) {
            exp1 = ceil(exp1 + d*1.0/200);
        } else {
            exp1 = ceil(exp1 - d*1.0/100);
        }
    }
    else if (e1 <= 19 and e1 >= 4){
        exp2 = ceil(exp2 + e1*1.0/4 + 19);
        
        exp1 -= e1;
    }else if (e1 >= 20 and e1 <= 49){
        exp2 = ceil(exp2 + e1*1.0/9 + 21);
        exp1 -= e1;
    }else if (e1 >=50 and e1 <= 65){
        exp2 = ceil(exp2 + e1*1.0/16 + 17);
        exp1 -= e1;
    }else if (e1>=66 and e1<=79){
         exp2 = ceil(exp2+ e1*1.0/4 + 19);
         if (exp2 >200){
           exp2 = ceil(exp2 + e1*1.0/9 + 21);
         }
         exp1 -= e1;
    }else if (e1 >=80 and e1<=99) {
        exp2 = ceil(exp2 + e1*1.0/4 + 19);
        exp2 += ceil(e1*1.0/9 + 21);
        if (exp2 >400){
           exp2 = ceil(exp2 + e1*1.0/16 + 17);
           exp2 =ceil(exp2*1.15);
         }
         exp1 -= e1;
    }
    if (exp1 > 600)
     exp1 =600;
    if (exp2 > 600)
     exp2 =600;
    if (exp1 <0 )
    exp1 =0;
if (exp2 <0 )
    exp2 =0;
    return exp1+exp2;
}


// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{

// TODO: Complete this function
if (E2<0 or E2>99)
      return -99;
if (EXP1 > 600)
     EXP1 =600;
    if (EXP1 <0 )
    EXP1 =0;
        if (HP1 > 666)
     HP1 =666;
     if (HP1 <0 )
    HP1 =0;
        if (M1 > 3000)
     M1 =3000;
    if (M1 <0 )
    M1 =0;
        
//road 1-------------------------------
      int money = M1;   
      int s1 =0;
      float p1=0;
s1=round(sqrt(EXP1))*round(sqrt(EXP1));
        if (EXP1 >= s1){
   p1=1;
 }else p1 = (EXP1*1.0/s1 +80)*1.0/123;  

//--------------------------------------
//road 2--------------------------------
if (E2 % 2 !=0){
    if (M1==0){
 HP1=ceil(HP1*83.0/100);
 EXP1=ceil(EXP1*117.0/100);
 goto end;
}
 while (1>0){
//1
if (HP1  <200 ){
    HP1=ceil(HP1*130.0/100);
    M1 -= 150;
}else {
    HP1=ceil(HP1*110.0/100);
    M1-=70;
}
if (EXP1 > 600)
     EXP1 =600;
    if (EXP1 <0 )
    EXP1 =0;
        if (HP1 > 666)
     HP1 =666;
     if (HP1 <0 )
    HP1 =0;
        if (M1 > 3000)
     M1 =3000;
    if (M1 <0 )
    M1 =0;

if (M1 < money/2){
 HP1=ceil(HP1*83.0/100);
 EXP1=ceil(EXP1*117.0/100);
 goto end;
 }
 if (EXP1 > 600)
     EXP1 =600;
    if (EXP1 <0 )
    EXP1 =0;
        if (HP1 > 666)
     HP1 =666;
     if (HP1 <0 )
    HP1 =0;
        if (M1 > 3000)
     M1 =3000;
    if (M1 <0 )
    M1 =0;
//2
if (EXP1 <400){
    M1 -= 200;
    EXP1 = ceil(EXP1*113.0/100);
}else {
    M1-=120;
    EXP1 = ceil(EXP1*113.0/100);
}
if (EXP1 > 600)
     EXP1 =600;
    if (EXP1 <0 )
    EXP1 =0;
        if (HP1 > 666)
     HP1 =666;
     if (HP1 <0 )
    HP1 =0;
        if (M1 > 3000)
     M1 =3000;
    if (M1 <0 )
    M1 =0;
if (M1 < money/2){
 HP1=ceil(HP1*83.0/100);
 EXP1=ceil(EXP1*117.0/100);
goto end;
 }
 if (EXP1 > 600)
     EXP1 =600;
    if (EXP1 <0 )
    EXP1 =0;
        if (HP1 > 666)
     HP1 =666;
     if (HP1 <0 )
    HP1 =0;
        if (M1 > 3000)
     M1 =3000;
    if (M1 <0 )
    M1 =0;
//3
if (EXP1 <300 ){
    M1-=100;
    EXP1=ceil(EXP1*90.0/100);
}else {
    M1-=120;
    EXP1=ceil(EXP1*90.0/100);
}
if (EXP1 > 600)
     EXP1 =600;
    if (EXP1 <0 )
    EXP1 =0;
        if (HP1 > 666)
     HP1 =666;
     if (HP1 <0 )
    HP1 =0;
        if (M1 > 3000)
     M1 =3000;
    if (M1 <0 )
    M1 =0;
if (M1 < money/2){
 HP1=ceil(HP1*83.0/100);
 EXP1=ceil(EXP1*117.0/100);
goto end;
 }
 if (EXP1 > 600)
     EXP1 =600;
    if (EXP1 <0 )
    EXP1 =0;
        if (HP1 > 666)
     HP1 =666;
     if (HP1 <0 )
    HP1 =0;
        if (M1 > 3000)
     M1 =3000;
    if (M1 <0 )
    M1 =0;
 }
}else {
    if (M1==0){
 HP1=ceil(HP1*83.0/100);
 EXP1=ceil(EXP1*117.0/100);
 goto end;
}
//1
if (HP1  <200 ){
    HP1=ceil(HP1*130.0/100);
    M1 -= 150;
}else {
    HP1=ceil(HP1*110.0/100);
    M1-=70;
}
if (EXP1 > 600)
     EXP1 =600;
    if (EXP1 <0 )
    EXP1 =0;
        if (HP1 > 666)
     HP1 =666;
     if (HP1 <0 )
    HP1 =0;
        if (M1 > 3000)
     M1 =3000;
    if (M1 <0 )
    M1 =0;
if (M1==0){
 HP1=ceil(HP1*83.0/100);
 EXP1=ceil(EXP1*117.0/100);
goto end;
}

//2
if (EXP1 <400){
    M1 -= 200;
    EXP1 = ceil(EXP1*113.0/100);
}else {
    M1-=120;
    EXP1 = ceil(EXP1*113.0/100);
}
if (EXP1 > 600)
EXP1 =600;
    if (EXP1 <0 )
    EXP1 =0;
        if (HP1 > 666)
     HP1 =666;
     if (HP1 <0 )
    HP1 =0;
        if (M1 > 3000)
     M1 =3000;
    if (M1 <0 )
    M1 =0;
if (M1==0){
 HP1=ceil(HP1*83.0/100);
 EXP1=ceil(EXP1*117.0/100);
 goto end;
}
//3
if (EXP1 <300 ){
    M1-=100;
    EXP1=ceil(EXP1*90.0/100);
}else {
    M1-=120;
    EXP1=ceil(EXP1*90.0/100);
}
if (EXP1 > 600)
     EXP1 =600;
    if (EXP1 <0 )
    EXP1 =0;
        if (HP1 > 666)
     HP1 =666;
     if (HP1 <0 )
    HP1 =0;
        if (M1 > 3000)
     M1 =3000;
    if (M1 <0 )
    M1 =0;
    
  HP1=ceil(HP1*83.0/100);
 EXP1=ceil(EXP1*117.0/100);

if (EXP1 > 600)
     EXP1 =600;
    if (EXP1 <0 )
    EXP1 =0;
        if (HP1 > 666)
     HP1 =666;
     if (HP1 <0 )
    HP1 =0;
        if (M1 > 3000)
     M1 =3000;
    if (M1 <0 )
    M1 =0;
}
end:

if (EXP1 > 600)
     EXP1 =600;
    if (EXP1 <0 )
    EXP1 =0;
        if (HP1 > 666)
     HP1 =666;
     if (HP1 <0 )
    HP1 =0;
        if (M1 > 3000)
     M1 =3000;
    if (M1 <0 )
    M1 =0;

      float s2 =0;
      float p2=0;
s2=round(sqrt(EXP1))*round(sqrt(EXP1));


    if (EXP1 >= s2){
   p2=1;
 }else {
 p2 = (EXP1*1.0/s2 +80)/123; 
 }



//----------------------------------------
//road 3----------------------------------
float p3=0;
int count=0;
int arr[10] = {32,47,28,79,100,50,22,83,64,11};
if (E2<10){
    p3=arr[E2]*1.0/100;
}else {
    count = E2%10 + E2/10;
    p3=arr[count%10]*1.0/100;
}
//----------------------------------------
//conclude--------------------------------
float chance =0;
if (p1==1 and p2==1 and p3==1){
    EXP1=ceil(EXP1*75.0/100);
}else {
    chance = (p1+p2+p3)/3;
    if (chance < 0.5){
    HP1 =ceil(HP1*85.0/100);
    EXP1=ceil(EXP1*115.0/100);
}else 
{
    HP1 =ceil(HP1*90.0/100);
EXP1=ceil(EXP1*120.0/100);
}
}



//----------------------------------------
    if (EXP1 > 600)
     EXP1 =600;
    if (EXP1 <0 )
    EXP1 =0;
        if (HP1 > 666)
     HP1 =666;
    if (HP1 <0 )
    HP1 =0;
        if (M1 > 3000)
     M1 =3000;
    if (M1 <0 )
    M1 =0;
    

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
        if (EXP1 > 600)
     EXP1 =600;
    if (EXP1 <0 )
    EXP1 =0;
            if (EXP2 > 600)
     EXP2 =600;
    if (EXP2 <0 )
    EXP2 =0;
        if (HP1 > 666)
     HP1 =666;
    if (HP1 <0 )
    HP1 =0;
         if (HP2 > 666)
     HP2 =666;
    if (HP2 <0 )
    HP2 =0;
        if (E3<0 or E3>99)
      return -99;
    int taxi[10][10];
    int max=0;
    int a=0;
    int b=0;
    int maxSW = 0; 
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            taxi[i][j]=((E3*j)+(i*2))*(i-j);
            if (taxi[i][j]>(E3*2)){
               a+=1;
            }
            if (taxi[i][j]<(-E3)){
               b+=1;
            }
            }
        }
while (a>=10){
  a=a%10+a/10;
}
while (b>=10){
  b=b%10+b/10;
}
max = taxi[a][b];
maxSW = taxi[a-1][b-1];
for (int i=a,j=b;i>=0 and j>=0 and i<10 and j<10;i++,j++){
    if (taxi[i][j]>maxSW){
            maxSW=taxi[i][j];
            
        }
}
for (int i=a,j=b;i>=0 and j>=0 and i<10 and j<10;i++,j--){
    if (taxi[i][j]>maxSW){
            maxSW=taxi[i][j];
        }
        
}
for (int i=a,j=b;i>=0 and j>=0 and i<10 and j<10;i--,j++){
    if (taxi[i][j]>maxSW){
            maxSW=taxi[i][j];
        }
}
for (int i=a,j=b;i>=0 and j>=0 and i<10 and j<10;i--,j--){
    if (taxi[i][j]>maxSW){
            maxSW=taxi[i][j];
        }
}
 if (abs(maxSW)>=abs(max)){
    HP1=ceil(HP1*110./100);
    HP2=ceil(HP2*110.0/100);
    EXP1=ceil(EXP1*112.0/100);
    EXP2=ceil(EXP2*112.0/100);
           if (EXP1 > 600)
     EXP1 =600;
    if (EXP1 <0 )
    EXP1 =0;
            if (EXP2 > 600)
     EXP2 =600;
    if (EXP2 <0 )
    EXP2 =0;
        if (HP1 > 666)
     HP1 =666;
    if (HP1 <0 )
    HP1 =0;
         if (HP2 > 666)
     HP2 =666;
    if (HP2 <0 )
    HP2 =0;
    return maxSW;
 }else{
    HP1=ceil(HP1*90.0/100);
    HP2=ceil(HP2*90.0/100);
    EXP1=ceil(EXP1*88.0/100);
    EXP2=ceil(EXP2*88.0/100);
           if (EXP1 > 600)
     EXP1 =600;
    if (EXP1 <0 )
    EXP1 =0;
            if (EXP2 > 600)
     EXP2 =600;
    if (EXP2 <0 )
    EXP2 =0;
        if (HP1 > 666)
     HP1 =666;
    if (HP1 <0 )
    HP1 =0;
         if (HP2 > 666)
     HP2 =666;
    if (HP2 <0 )
    HP2 =0;

    return max;
 }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
 string se,emails,ss;
 int counts,countemail;
 bool checkSpecial = false;
 bool checkChar = false;
     
    counts = strlen(s);  


countemail = strlen(email);

ss.assign(s,counts);
emails.assign(email,countemail);
se = emails.substr(0,emails.find('@'));

if (ss.length()<8) return -1;
if (ss.length()>20) return -2;
size_t checkPass = ss.find(se);
if (checkPass != string::npos){
    return -(300 + checkPass);
}
for (int i=0;i<counts;i++){
    if (ss[i]==ss[i+1] and ss[i+1]==ss[i+2]){
      return -(400+i);

    }
}

for (int i=0;i<counts;i++){
    if (ss[i]=='@'||ss[i]=='#'||ss[i]=='%'||ss[i]=='$'||ss[i]=='!')
      checkSpecial = true;
      
}
if (checkSpecial==false){
    return -5;
}
for (int i=0;i<counts;i++){
    if ((ss[i]<='9'&&ss[i]>='0')||(ss[i]>='A'&&ss[i]<='Z')||(ss[i]>='a'&&ss[i]<='z'||ss[i]=='@'||ss[i]=='#'||ss[i]=='%'||ss[i]=='$'||ss[i]=='!')){
        checkChar= true;

    }else {
        return i;
    }
}

    return -10;
}



// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    int n=0;

    int maxappear =0;
    int maxlen=0;
    int place=0;
for (int i=0;i<num_pwds;i++){
    const string& arr=arr_pwds[i];
    n=0;
    for (int j=0;j<num_pwds;++j){
        if (arr_pwds[j]==arr){
            n++;
        }
    }
      if (n>maxappear or (n==maxappear and arr.length()>maxlen)){
        maxappear=n;
        maxlen=arr.length();
        place=i;
    }
}
    return place ;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////