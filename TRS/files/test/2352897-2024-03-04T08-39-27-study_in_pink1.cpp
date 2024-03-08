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
int checkinvalid(string s,int &b){
    int value=0;
string valid="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#%$!";
for(int i=0; i< s.length() ; i++ ){
    if(valid.find(s[i])==string::npos) {
        b=i;
        value=1;
        break;
    }
}
return value;
}
int checkrepeat(string s , int &a){
    int value=0;
    for(int i=0; i<s.length()-1;i++){
        if(s[i]==s[i+1]) {
            if(s[i+1]==s[i+2]){
                value=1;
                a=i;
                break;
            }
            }
    }
    return value;
}
int findspecial(string s){
    int spec1= s.find("@");
    int spec2= s.find("#");
    int spec3= s.find("%");
    int spec4= s.find("$");
    int spec5= s.find("!");
    return (spec1 != string::npos) + (spec2 != string::npos) + (spec3 != string::npos) + (spec4 != string::npos) + (spec5 != string::npos);

}
void checkexp(int & exp){
    if(exp<0) exp=0;
    if(exp>600) exp=600;
    
}
void checkhp(int & HP){
    if(HP<0) HP=0;
    if(HP>666) HP=666;
    
}
void checkm(int & M){
    if(M<0) M=0;
    if(M>3000) M=3000;
    
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    double offset = -1e-9;
    if(e1<0||e1>99) {return -99;}
    checkexp(exp1);
    checkexp(exp2);
    if(e1>=0 && e1<=3){
        if(e1==0) exp2 += 29;
        if(e1==1) exp2 += 45;
        if(e1==2) exp2 += 75;
        if(e1==3) exp2 += 149;
        int D = e1*3 + exp1*7;
        if(D % 2 == 0){
            exp1 =ceil((double)exp1+ (double)D/200 + offset);
            checkexp(exp1);
            checkexp(exp2);
        }
        else{
            exp1 =ceil((double)exp1 - (double)D/100 + offset);
            checkexp(exp1);
            checkexp(exp2);
        }
        }
    else if(e1>=4&&e1<=99){
        if(e1>=4 && e1<=19) {exp2 = ceil((double)e1/4 + 19 + offset + exp2 ) ; checkexp(exp2);}
        else if(e1>=20 && e1<=49){exp2 = ceil((double)e1/9 + 21 + offset +exp2 ) ;checkexp(exp2);}
        else if(e1>=50 && e1<=65){exp2 = ceil((double)e1/16 + 17 + offset + exp2 );checkexp(exp2);}
        else if(e1>=66 && e1<=79){
            exp2 = ceil((double)e1/4 + 19 + exp2 + offset);
            checkexp(exp2);
            if(exp2 > 200){ exp2 = ceil((double)e1/9 + 21 + offset + exp2);checkexp(exp2);}
        }
        else if(e1>=80 && e1<=99){
            exp2 = ceil((double)e1/4 + 19 + exp2 + offset);checkexp(exp2);
            exp2 = ceil((double)e1/9 + 21 + exp2 + offset);checkexp(exp2);
            if(exp2>400){
                exp2 = ceil((double)e1/16 + 17 + exp2 + offset);checkexp(exp2);
                exp2 = ceil((double)exp2*1.15 + offset);checkexp(exp2);
            } 
        }
        exp1 = exp1 - e1;
        checkexp(exp1);
        checkexp(exp2);
    }

    return exp1+exp2;
    }


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int returnvalue;
    double offset = -1e-9;
    if(E2<0||E2>99){ return -99;}
     checkhp(HP1);
    checkexp(EXP1);

    checkm(M1);
    double maxm=M1*0.5;
    double count=0;
    int s;
    double P1,P2,P3;

    s=round(sqrt((double)EXP1));
    s= s*s;
    
    if(EXP1>=s) P1=100/100;
    else P1=((double)EXP1/s +80)/123;
if(E2%2==1){
    while(true){
    if(count<=maxm && M1>0){ 
    if(HP1<200){
        HP1=ceil((double)HP1*(1.3) + offset);
        checkhp(HP1);
        M1-=150;
        checkm(M1);
        count+=150;  
    }
    else{
        HP1=ceil((double)HP1*(1.1) + offset);
        checkhp(HP1);
        M1-=70;
        checkm(M1);
        count+=70;
    }}
    else break;
    if(count<=maxm && M1>0){
    if(EXP1<400){
        M1-=200;
        checkm(M1);
        count+=200;
        EXP1=ceil((double)EXP1*(1.13) + offset);
        checkexp(EXP1);
    }
    else{
        M1-=120;
        checkm(M1);
        count+=120;
        EXP1=ceil((double)EXP1*(1.13) + offset);
        checkexp(EXP1);
    }}else break;
    if(count<=maxm && M1>0){
    if(EXP1<300){
        M1-=100;
        checkm(M1);
        count+=100;
        EXP1=ceil((double)EXP1*(0.9) + offset);
        checkexp(EXP1);
    }
    else{
        M1-=120;
        checkm(M1);
        count+=120;
        EXP1=ceil((double)EXP1*(0.9) + offset);
        checkexp(EXP1);
    }}else break;
    }
    HP1=ceil((double)HP1*(0.83) + offset);
    EXP1=ceil((double)EXP1*(1.17) + offset);
    checkhp(HP1);
    checkexp(EXP1);
    }
else if(E2%2==0){
    while(true){
        if(M1>0){ 
    if(HP1<200){
        HP1=ceil((double)HP1*(1.3) + offset);
        checkhp(HP1);
        M1-=150;
        checkm(M1);
        count+=150;  
    }
    else{
        HP1=ceil((double)HP1*(1.1) + offset);
        checkhp(HP1);
        M1-=70;
        checkm(M1);
        count+=70;
    }}
    else break;
    if(M1>0){
    if(EXP1<400){
        M1-=200;
        checkm(M1);
        count+=200;
        EXP1=ceil((double)EXP1*(1.13) + offset);
        checkexp(EXP1);
    }
    else{
        M1-=120;
        checkm(M1);
        count+=120;
        EXP1=ceil((double)EXP1*(1.13) + offset);
        checkexp(EXP1);
    }}else break;
    if(M1>0){
    if(EXP1<300){
        M1-=100;
        checkm(M1);
        count+=100;
        EXP1=ceil((double)EXP1*(0.9) + offset);
        checkexp(EXP1);
    }
    else{
        M1-=120;
        checkm(M1);
        count+=120;
        EXP1=ceil((double)EXP1*(0.9) + offset);
        checkexp(EXP1);
    }}else break;
    break;

    }
    HP1=ceil((double)HP1*(0.83) + offset);
    EXP1=ceil((double)EXP1*(1.17) + offset);
    checkhp(HP1);
    checkexp(EXP1);
    }
    s=round(sqrt((double)EXP1));
    s= s*s;
    if(EXP1>=s) P2=100/100;
    else P2=((double)EXP1/s +80)/123;
    int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if(E2>=0&&E2<=9) i=E2;
    else if(E2>=10 && E2<=99){
        i= E2%10 + E2/10;
        i= i%10;
    }
    P3= P[i]*0.01;
    double avgp;
    avgp=(P1 + P2 + P3)/3;
    if(P1==1&&P2==1&&P3==1){
        EXP1=ceil((double)EXP1*0.75 + offset);
        checkexp(EXP1);
    }
    else if(avgp<0.5){
        EXP1=ceil((double)EXP1*1.15 + offset);
        checkexp(EXP1);
        HP1=ceil((double)HP1*0.85 + offset);
        checkhp(HP1);
    }
    else if(avgp>=0.5&&avgp<1){
        EXP1=ceil((double)EXP1*1.20 + offset);
        checkexp(EXP1);
        HP1=ceil((double)HP1*0.9 + offset);
        checkhp(HP1);
    }

    
    return HP1 + EXP1 + M1;;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0||E3>99) {return -99;}
    checkhp(HP1);
    checkexp(EXP1);
    checkhp(HP2);
    checkexp(EXP2);
    int value=0;
    
    double offset = -1e-9;
    int car[10][10];
    int i = 0; int j = 0;
    int a = 0; int b = 0;
    int max =0 ;
    for(i=0 ; i<=9 ; i++){
        for(j=0 ; j<= 9; j++){
            car[i][j]=((E3*j)+(i*2))*(i-j);
        }
    }
    for(i=0 ; i<=9 ; i++){
        for(j=0 ; j<= 9; j++){
            if(car[i][j]>(E3*2)) a++;
            if(car[i][j]<-E3) b++;
        }
    }
    while(true){
        if(a>=10){
            a= a%10 + a/10;
        }
        else break;
    }
    while(true){
        if(b>=10){
            b= b%10 + b/10;
        }
        else break;
    }
    i=a;
    j=b;
    while(i>=0&&i<=9&&j>=0&&j<=9){
        if(max<car[i][j]) max = car[i][j];
        i--;
        j--;
    }
    i=a;
    j=b;
    while(i>=0&&i<=9&&j>=0&&j<=9){
        if(max<car[i][j]) max = car[i][j];
        i++;
        j--;
    }
    i=a;
    j=b;
    while(i>=0&&i<=9&&j>=0&&j<=9){
        if(max<car[i][j]) max = car[i][j];
        i--;
        j++;
    }
    i=a;
    j=b;
    while(i>=0&&i<=9&&j>=0&&j<=9){
        if(max<car[i][j]) max = car[i][j];
        i++;
        j++;
    }
    if(abs(car[a][b])>max){
       HP1=ceil((double)HP1*0.9 + offset) ;
       checkhp(HP1);
       EXP1 = ceil( (double) EXP1 * 0.88 + offset) ;
       checkexp(EXP1);
       HP2=ceil((double)HP2*0.9 + offset) ;
       checkhp(HP2);
       EXP2 = ceil( (double) EXP2 * 0.88 + offset) ;
       checkexp(EXP2);
       value = car[a][b];
    }
    else if(abs(car[a][b])<=max){
        HP1 = ceil ( (double) HP1 * 1.1 + offset) ;
       checkhp(HP1);
       EXP1 = ceil ( (double) EXP1 * 1.12 + offset) ;
       checkexp(EXP1);
       HP2 = ceil ( (double) HP2 * 1.1 + offset) ;
       checkhp(HP2);
       EXP2 = ceil ( (double) EXP2 * 1.12 + offset) ;
       checkexp(EXP2);
       value=max;
    }
    
   
    return value;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string pass(s);
    string mail(email);
    int b=0;
    int sci=0;
    int returnvalue;
    int pos = mail.find("@");
    string se = mail.substr(0, pos);
    if(pass.length()<8) returnvalue = -1 ;
    else if(pass.length()>20) returnvalue = -2;
    else if(pass.find(se)!= string::npos) returnvalue = -(300 + pass.find(se));
    else if(checkrepeat(s,sci)) returnvalue= -(400+sci);
    else if(findspecial(s)==0) returnvalue= -5;
    else if(checkinvalid(s,b)) returnvalue=b;
    else returnvalue=-10;
    return returnvalue;
    }

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int mostrepeat=0;
    int count[num_pwds];
for(int i=0 ; i < num_pwds ; i++){
    count[i]=0;
    for(int j=0 ;(i + j)< num_pwds; j++){
        if(string(arr_pwds[i])==string(arr_pwds[i+j])){
            count[i]+=1;
        }
    }
}
int a=0;
for( a=0 ; a < num_pwds ; a++){
    if(count[mostrepeat] <= count[a]){
        if(count[mostrepeat] < count[a]){ mostrepeat=a;}
        else if(count[mostrepeat] == count[a]){
            if(strlen(arr_pwds[mostrepeat])< strlen(arr_pwds[a])){
                mostrepeat=a;
            }
        }
    }

}
    return mostrepeat;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////