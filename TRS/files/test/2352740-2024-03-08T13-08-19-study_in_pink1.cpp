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
int check(int n,int firstpoint,int lastpoint){
if(n< firstpoint){
    return n= firstpoint;
}
else if(n>lastpoint){
    return n=lastpoint;
}
else{
    return n;
}
return 0;
}
int check1(int n,int firstpoint1,int lastpoint1){
    if((n>0)&(n<99)){
        return n;
    }
    else{
    return -99;
    }
}
int firstMeet(int & exp1, int & exp2, int  e1) {
    int firstpoint,lastpoint;
    exp1=check(exp1,0,600);
    exp2=check(exp2,0,600);
    e1=check1(e1,0,99);

    if((e1>=0)&&(e1<=3)){
        if(e1==0){
            exp2=exp2+29;
             exp2=check(exp2,0,600);
            int D=ceil(e1*3+exp1*7);
            if(D%2==0){
                exp1=ceil(exp1+(D/200));
                 exp1=check(exp1,0,600);
            }
            else{
                exp1=ceil(exp1-(D/100));
                 exp1=check(exp1,0,600);
            }
          return exp1+exp2;

        }
        else if(e1==1){
            exp2=exp2+45;
             exp2=check(exp2,0,600);
            int D=ceil(e1*3+exp1*7);
             if(D%2==0){
                exp1=ceil(exp1+(D/200));
                 exp1=check(exp1,0,600);
            }
            else{
                exp1=ceil(exp1-(D/100));
                 exp1=check(exp1,0,600);
            }
           return exp1+exp2;

        }
        else if(e1==2){
            exp2=exp2+75;
             exp2=check(exp2,0,600);
            int D=ceil(e1*3+exp1*7);
             if(D%2==0){
                exp1=ceil(exp1+(D/200));
                 exp1=check(exp1,0,600);
            }
            else{
                exp1=ceil(exp1-(D/100));
                 exp1=check(exp1,0,600);
            }
           return exp1+exp2;


        }
        else{
            exp2=exp2+29+45+75;
             exp2=check(exp2,0,600);
            int D=ceil(e1*3+exp1*7);
             if(D%2==0){
                exp1=ceil(exp1+(D/200));
                 exp1=check(exp1,0,600);
            }
            else{
                exp1=ceil(exp1-(D/100));
                 exp1=check(exp1,0,600);
            }
            return exp1+exp2;
        }
    }
else if((e1>=4)&&(e1<=99)){
    if((e1>=4)&&(e1<=19)){
        exp2=ceil(exp2+ceil(e1/4+19));
        exp1=exp1-e1;
         exp1=check(exp1,0,600);
          exp2=check(exp2,0,600);
       return exp1+exp2;

    }
   else if((e1>=20)&&(e1<=49)){
        exp2=ceil(exp2+(e1/9.0+21));
        exp1=exp1-e1;
         exp1=check(exp1,0,600);
          exp2=check(exp2,0,600);
       return exp1+exp2;
    }
    else if((e1>=50)&&(e1<=65)){
        exp2=ceil(exp2+(e1/16.0+17));
        exp1=exp1-e1;
         exp1=check(exp1,0,600);
          exp2=check(exp2,0,600);
       return exp1+exp2;
    }
    else if((e1>=66)&&(e1<=79)){
       exp2=ceil(exp2+(e1/4.0+19));
        exp1=exp1-e1;
         exp1=check(exp1,0,600);
          exp2=check(exp2,0,600);
       if(exp2>200){
         exp2=ceil(exp2+(e1/9.0+21));
          exp2=check(exp2,0,600);
         return exp1+exp2; 
       }
       else{
       return exp1+exp2; 
       }

    }
    else if(e1>=80&&e1<=99){
     exp2=(exp2+((e1/4.0)+19));
     exp2=ceil(exp2);
     exp2=ceil(exp2+((e1/9.0)+21));
      exp1=exp1-e1;
       exp1=check(exp1,0,600);
        exp2=check(exp2,0,600);
     if(exp2>400){
        exp2=ceil(exp2+(e1/16.0)+17);
        exp2=ceil(exp2*1.15);
         exp2=check(exp2,0,600);
         return exp1+exp2;
         
       
     }else{
     return exp1+exp2;
    }}
}
     else {
     return -99;
 }
 return 0;
}


// Task 2
int nearestSquareNumber(int k) {
   int i=0;
   while(1){
      if(trunc(sqrt(k+i))==sqrt(k+i))return k+i;
    if(trunc(sqrt(k-i))==sqrt(k-i))return k-i;
    i++;
   }
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    E2=check1(E2,0,99);
    HP1=check(HP1,0,666);
    EXP1=check(EXP1,0,600);
    M1=check(M1,0,3000);
    int S=nearestSquareNumber(EXP1);
    float P1,P2,P3;
    //ditrenconduong1
    if(EXP1>=S){
        P1=100;
    }
    else{
        P1=((EXP1/S)+80)/123;
    }
    
    //di tren con duong 2
int moneyspent =0;
int halfmoney=ceil(M1*0.5);
   if(E2%2!=0){
    while(moneyspent<halfmoney){
   if(HP1<200){
        HP1=ceil(HP1*1.30);
        M1=ceil(M1-150);
        HP1=check(HP1,0,666);
        M1=check(M1,0,3000);
      moneyspent=moneyspent+150;
}
else{
HP1=ceil(HP1*1.1);
M1=ceil(M1-70);
 HP1=check(HP1,0,666);
     M1=check(M1,0,3000);
     moneyspent=moneyspent+70;
    }
    if(moneyspent>=halfmoney){
        break;
    }
    if(EXP1<400){
        M1=ceil(M1-200);
        M1=check(M1,0,3000);
        moneyspent=moneyspent+200;
    }
    else{
        M1=ceil(M1-120);
        EXP1=ceil(EXP1*1.13);
        M1=check(M1,0,3000);
        EXP1=check(EXP1,0,600);
        moneyspent=moneyspent+120;
    }
    if(moneyspent>=halfmoney){
        break;
    }
    if(EXP1<300){
        M1=ceil(M1-100);
        EXP1=ceil(EXP1*0.9);
        M1=check(M1,0,3000);
        EXP1=check(EXP1,0,600);
        moneyspent=moneyspent+100;
    }
    else{
        M1=ceil(M1-120);
        EXP1=ceil(EXP1*0.9);
        M1=check(M1,0,3000);
        EXP1=check(EXP1,0,600);
        moneyspent=moneyspent+120;
    }
   }
  
HP1=ceil(HP1*0.83);
EXP1=ceil(EXP1*1.17);
EXP1=check(EXP1,0,600);
HP1=check(HP1,0,600);
S=nearestSquareNumber(EXP1);
if(S<=EXP1){
    P2=100;
}
else{
    P2=((EXP1/S)+80)/123;
}
    }
    else{
        if(HP1<200){
        HP1=ceil(HP1*1.30);
        M1=ceil(M1-150);
        HP1=check(HP1,0,666);
        M1=check(M1,0,3000);
      moneyspent=moneyspent+150;
}
else{
HP1=ceil(HP1*1.1);
M1=ceil(M1-70);
 HP1=check(HP1,0,666);
     M1=check(M1,0,3000);
     moneyspent=moneyspent+70;
    }
    if(M1<0){
    M1=0;
    HP1=ceil(HP1*0.83);
EXP1=ceil(EXP1*1.17);
EXP1=check(EXP1,0,600);
HP1=check(HP1,0,600);
S=nearestSquareNumber(EXP1);
if(S<=EXP1){
    P2=100;
}
else{
    P2=((EXP1/S)+80)/123;
}
    }
    if(EXP1<400){
        M1=ceil(M1-200);
        M1=check(M1,0,3000);
        moneyspent=moneyspent+200;
    }
    else{
        M1=ceil(M1-120);
        EXP1=ceil(EXP1*1.13);
        M1=check(M1,0,3000);
        EXP1=check(EXP1,0,600);
        moneyspent=moneyspent+120;
    }
    if(M1<0){
    M1=0;
    HP1=ceil(HP1*0.83);
EXP1=ceil(EXP1*1.17);
EXP1=check(EXP1,0,600);
HP1=check(HP1,0,600);
S=nearestSquareNumber(EXP1);
if(S<=EXP1){
    P2=100;
}
else{
    P2=((EXP1/S)+80)/123;
}
    }
if(EXP1<300){
        M1=ceil(M1-100);
        EXP1=ceil(EXP1*0.9);
        M1=check(M1,0,3000);
        EXP1=check(EXP1,0,600);
        moneyspent=moneyspent+100;
    }
    else{
        M1=ceil(M1-120);
        EXP1=ceil(EXP1*0.9);
        M1=check(M1,0,3000);
        EXP1=check(EXP1,0,600);
        moneyspent=moneyspent+120;
    }
     HP1=ceil(HP1*0.83);
EXP1=ceil(EXP1*1.17);
EXP1=check(EXP1,0,600);
HP1=check(HP1,0,600);
S=nearestSquareNumber(EXP1);
if(S<=EXP1){
    P2=100;
}
else{
    P2=((EXP1/S)+80)/123;
}

    }
    //con duong thu 3
    int P[10]={32,47,28,79,100,50,22,83,64,11};
    int o;
    if(E2>9){
int r=E2%10;
int t=E2/10;
if(r+t>9){
o=P[(r+t)%10];
    }
    else{
    o=P[r+t];
    }
    }
    else{
 o=P[E2];
    }

    P3=o;
    double p=(P1+P2+P3)/3;
    if(p>=50){
        EXP1=ceil(EXP1*1.2);
HP1=ceil(HP1*0.9);
EXP1=check(EXP1,0,600);
HP1=check(HP1,0,666);
    }
    else{
        EXP1=ceil(EXP1*1.15);
HP1=ceil(HP1*0.85);
EXP1=check(EXP1,0,600);
HP1=check(HP1,0,666);
    }
    
return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
      int a[10][10];
        int count=0;
        int count1=0;
        int x;
        int y;
        int q;
        int w;
        int i;
        int j;
        E3=check1(E3,0,99);
    HP1=check(HP1,0,666);
    EXP1=check(EXP1,0,600);
    EXP2=check(EXP2,0,3000);
    HP2=check(HP2,0,666);
      for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
          a[i][j]=((E3*j)+(i*2))*(i-j);
          if((a[i][j]>0)&&(a[i][j]>(E3*2))){
            count++;
          }
          else if((a[i][j]<0)&&(a[i][j]<(-E3))){
          count1++;
      }
      
      }
      }
    
      
      x=count%10;
      y=count/10;
      q=count1%10;
      w=count1/10;
      i=x+y;
      j=q+w;
      while(i>9){
        x=i%10;
        y=i/10;
        i=x+y;
      }
      while(j>9){
        q=j%10;
        w=j/10;
        j=q+w;
      }
      int s=a[i][j];
int min=i;
if(j<min){
min=j;
}
else{
  min=i;
}
int g=i-min;
int h=j-min;
int max=a[g][h];
int dem=1;
int r;
int o;
int l;
  while(((g+dem)<10)&&((h+dem)<10)){
    r=a[g+dem][h+dem];
    if(r>max){
      max=r;
    }
    dem++;
  }
  
  dem=1;
while(((i-dem)>=0)&&((j+dem)<10)){
o=a[i-dem][j+dem];
if(o>max){
  max=o;
}
dem++;
}

dem=1;
while(((i+dem)<10)&&((j-dem)>=0)){
l=a[i+dem][j-dem];
if(l>max){
  max=l;
}
dem++;
}

if(max<abs(s)){
  HP1=ceil(HP1*0.9);
  HP2=ceil(HP2*0.9);
  EXP1=ceil(EXP1*0.88);
EXP2=ceil(EXP2*0.88);
 HP1=check(HP1,0,666);
  EXP1=check(EXP1,0,600);
   EXP2=check(EXP2,0,600);
    HP2=check(HP2,0,600);
    return s;
}
else if(max>abs(s)){
  HP1=ceil(HP1*1.1);
  HP2=ceil(HP2*1.1);
  EXP1=ceil(EXP1*1.12);
EXP2=ceil(EXP2*1.12);
 HP1=check(HP1,0,666);
  EXP1=check(EXP1,0,600);
   EXP2=check(EXP2,0,600);
    HP2=check(HP2,0,600);
    return max;
}
cout<<HP1<< " "<<HP2<<" "<<EXP1<<" "<<EXP2;
return -1;
} 

// Task 4


string beforecharacter(string email,char target ){
    string se="";
for(int i=0;i<email.length();++i){
    if(email[i]==target){
        break; 
    }
    else {
        se+=email[i];
    }
    return se;
}
return "";
}
bool checkifscontainse(string s,string se){
    size_t found=s.find(se);
    //return (found != string ::npos);
    if (found==string::npos) return 1; else return 0;

}
int checkpassswordletter( string& password) {
    bool hasDigit = false;
    bool hasLowercase = false;
    bool hasUppercase = false;
    bool hasSpecialChar = false; //abc@[]abc1A   c=[
    bool ok=1;
    for (char c : password) {
        if (isdigit(c)) {
            hasDigit = true;
        } else if (islower(c)) {
            hasLowercase = true;
        } else if (isupper(c)) {
            hasUppercase = true;
        } else if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
            hasSpecialChar = true;
        } else {
            for (int i=0;i<password.length();i++) {
                if (password[i]==c) return i;
            }
        }
    }
    bool word=hasLowercase + hasUppercase;
    if (hasDigit && word && hasSpecialChar && ok) return -1;
    return 0;
}
bool checkifcontinuous(const string &s){
    int consecutiveCount = 1; 
    char prevChar = '\0'; 

    for (char c : s) {
        if (c == prevChar) {
            consecutiveCount++;
            if (consecutiveCount >= 2) {
                return false; 
            }
        } else {
            consecutiveCount = 1;
            prevChar = c;
        }
    }

    return true; 
}
int passwordlikable(string s){
    for(int i=0;i<s.length()-1;++i){
        if(s[i]==s[i]+1){
            return i;
        }
    }
    return 0;
}
bool checkspecial(string s) {
    string ex="@#%$!";
    for (char x:s) {
        if (ex.find(x)!=-1) return 1;
    }
    return 0;
}

int validpassword(string s,string se,int sci){



        if((s.length()>=8)&&(s.length()<=20)){
            if(checkifscontainse(s,se)){
             if(checkspecial(s)){
                if(checkifcontinuous(s)){
return -10;
                }
                sci=passwordlikable(s);
           return -(400+sci);
             }
             return -5;
            }   
            return -(300+sci);
        }
        else {
            if(s.length()<8) return -1;
            if(checkpassswordletter(s)!=-1) return checkpassswordletter(s);
            return -2;
        }
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string st(s);
    string ft(email);
string se=beforecharacter(ft,'@');
int sei;
if (checkifscontainse(st,se)==0) sei=st.find(se);

return validpassword( st, se, sei);
return -99;
}



// Task 5
// ham de nhap cac mat khau rieng biet
//void Tao 1 mang chua cac mat khau rieng biet |
 int findCorrectPassword(const char * arr_pwds[], int num_pwds){
     int max=strlen(arr_pwds[0]);
   int vt=0;
   int max1=1;
    
    for(int i=0;i<num_pwds;++i){
int appearance=1;
for(int j=i+1;j<num_pwds;++j){
    if(arr_pwds[j]==arr_pwds[i]){
    appearance++;
    }
}
if(max1<appearance){
    vt=i;
    max1=appearance;
    max=strlen(arr_pwds[i]);
    }
    else if((max<strlen(arr_pwds[i]))&&(max1==appearance)){

        vt=i;
        max1=appearance;
        max=strlen(arr_pwds[i]);
    }
    
    }
    return vt;
    } 

   

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////