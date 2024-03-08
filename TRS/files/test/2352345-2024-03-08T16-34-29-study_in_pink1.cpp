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
int check(int n, int minPoint, int maxPoint) {
n = (n < minPoint) ? minPoint : (n > maxPoint) ? maxPoint : n;
return n;
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
const int minEXP=0;
const int maxEXP=600;
    if (e1 < 0 || e1 > 99) return -99;
exp1 = check(exp1, minEXP, maxEXP);
exp2 = check(exp2, minEXP, maxEXP);
    //Case 1 : D belongs to [0;3]
    int  D=e1*3+exp1*7;
    switch(e1){
        case 0: exp2+=29;
        exp2=check(exp2,minEXP,maxEXP);
        break;
        case 1: exp2+=45;
         exp2=check(exp2,minEXP,maxEXP);
         break;
        case 2: exp2+=75;
         exp2=check(exp2,minEXP,maxEXP);
         break;
        case 3: exp2+=29+45+75;
        exp2=check(exp2,minEXP,maxEXP);
        break;
    }
    if (e1==0||e1==1||e1==2||e1==3){
        if (D%2==0) {
            exp1=ceil(exp1+D/200.0);
            exp1=check(exp1,minEXP,maxEXP);
        }
        if (D%2!=0) {
        exp1=ceil(exp1-D/100.0);
        exp1=check(exp1,minEXP,maxEXP);
        }
    }
    //Case 2: D belongs to [4;99]
    //[4;19]
    if (e1>=4&&e1<=19) {
        exp1-=e1;
        exp2=exp2+ceil(e1/4.0)+19;
         exp1=check(exp1,minEXP,maxEXP);
        exp2=check(exp2,minEXP,maxEXP);
    }
    //[20;49]
    if (e1>=20&&e1<=49){
        exp1-=e1;
        exp2=exp2+ceil(e1/9.0)+21;
         exp1=check(exp1,minEXP,maxEXP);
        exp2=check(exp2,minEXP,maxEXP);
    }
    //[50;65]
    if (e1>=50&&e1<=65){
        exp1-=e1;
        exp2=exp2+ceil(e1/16.0)+17;
        exp1=check(exp1,minEXP,maxEXP);
        exp2=check(exp2,minEXP,maxEXP);
    }
    //[66;79]
    if (e1>=66&&e1<=79){
        exp1-=e1;
        exp2=exp2+ceil(e1/4.0)+19;
         exp1=check(exp1,minEXP,maxEXP);
        exp2=check(exp2,minEXP,maxEXP);
        if(exp2>200) {
            exp2=exp2+ceil(e1/9.0)+21;
        exp2=check(exp2,minEXP,maxEXP);
        }
    }
    //[80;99]
    if (e1>=80&&e1<=99){
        exp1-=e1;
        exp2=exp2+ceil(e1/4.0)+19;
         exp2=check(exp2,minEXP,maxEXP);
          exp1=check(exp1,minEXP,maxEXP);
        exp2=exp2+ceil(e1/9.0)+21;
        exp2=check(exp2,minEXP,maxEXP);

        if(exp2>400) {
            exp2=exp2+ceil(e1/16.0)+17;
            exp2=check(exp2,minEXP,maxEXP);
            exp2=ceil(float(exp2*1.150));
            exp2=check(exp2,minEXP,maxEXP);
        }
    }
    exp1 = check(exp1, minEXP, maxEXP);
    exp2 = check(exp2, minEXP, maxEXP);
    return exp1 + exp2;
}
// Task 2
int findNearestNumber(int a) {
    int lowerNUmber = pow(floor(sqrt(a)), 2);
    int upperNumber = pow(ceil(sqrt(a)), 2);
    return (a - lowerNUmber < upperNumber - a) ? lowerNUmber : upperNumber;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
   if (E2<0||E2>99) return -99;
    const int minHP=0, maxHP=666;
    const int minEXP=0, maxEXP=600;
    const int minM=0, maxM=3000;
    EXP1=check(EXP1, minEXP, maxEXP);
    HP1=check(HP1,minHP,maxHP);
    M1=check(M1,minM,maxM);
    //Start Road 1
    int S1,S2,S3;
    float P1=0.0,P2=0.0,P3=0.0,P_Ave=0.0;
    S1=findNearestNumber(EXP1);
    if (EXP1>=S1) P1=1.0;
    else P1=((EXP1/S1)+80.0)/123.0;
    //End of Road 1   

    //Start Road 2
    int M_Used=0;
    const int M_Started=ceil(float(M1/2.0));
    //E2 is an odd number.
    if (E2%2!=0&&M1>0){
        while (M_Used<M_Started){
            if (HP1<200&&M_Used<M_Started) {
                HP1 =ceil(float(HP1*1.3));
                check(HP1,minHP,maxHP);
                M_Used+=150;
            }
             if (HP1>=200&&M_Used<M_Started){
                HP1=ceil(HP1*float(110.0/100.0));
                check(HP1,minHP,maxHP);
                M_Used+=70;
            }
            if (EXP1<400&&M_Used<M_Started) {
               EXP1=ceil(float(EXP1*1.13));
                M_Used+=200;
            }
            if (EXP1>=400&&M_Used<M_Started) {
               EXP1=ceil(float(EXP1*1.13));
               M_Used+=120;
            }
            if (EXP1<300&&M_Used<M_Started){
                M_Used+=100;
                EXP1=ceil(float(EXP1*0.9));
            }
            if (EXP1>=300&&M_Used<M_Started) {
                M_Used+=120;
                 EXP1=ceil(float(EXP1*0.9));
            }
        }
        M1-=M_Used;
        HP1=ceil(float(HP1*0.83));
        EXP1=ceil(float(EXP1*1.17));
    }
    //E2 is an even number
    if (E2%2==0){
        if (HP1<200&&M1>0) {
            HP1 = ceil(float(HP1*1.3));
            M_Used+=150;
            M1-=150;
            check(M1,minM,maxM);
        }
        if (HP1>=200&&M1>0) {
            HP1=ceil(float(HP1*1.1));
            M_Used+=70;
            M1-=70;
            check(M1,minM,maxM);
        }
        if (EXP1<400&&M1>0) {
            EXP1=ceil(float(EXP1*1.13));
            M_Used+=200;
            M1-=200;
            check(M1,minM,maxM);
        }
        if (EXP1>=400&&M1>0) {
           EXP1=ceil(float(EXP1*1.13));
           M_Used+=120;
           M1-=120;
           check(M1,minM,maxM);
        }
        if (EXP1<300&&M1>0){
            M_Used+=100;
            EXP1=ceil(float(EXP1*0.9));
            M1-=100;
            check(M1,minM,maxM);
        }
        if (EXP1>=300&&M1>0) {
            M_Used+=120;
             EXP1=ceil(float(EXP1*0.9));
             M1-=120;
             check(M1,minM,maxM);
        }
    }
    S2=findNearestNumber(EXP1);
    if (EXP1>=S2) P2=1.0; 
    else P2=((EXP1/S2)+80.0)/123.0;
    //End of Road 2
    
    // Start Road 3
    int K[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = (E2 < 10) ? E2 : (E2 / 10 + E2 % 10) % 10;
    P3 = K[i]/100.0;
    //End of Road 3
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 =ceil(float(EXP1*0.75));
    } else {
         P_Ave = (P1 + P2 + P3) / 3.0;
        if (P_Ave < 0.5) {
            HP1 =ceil(float(HP1*0.85));
            EXP1 =ceil(float(EXP1*1.15));
        } else {
            HP1= ceil(float(HP1*0.9));
            EXP1 =ceil(float(EXP1*1.2));
        }
    }
M1=check(M1,minM,maxM);
EXP1=check(EXP1,minEXP,maxEXP);
HP1=check(HP1,minHP,maxHP);
    return HP1 + EXP1 + M1;
}

// Task 3

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
     const int minHP=0, maxHP=666;
    const int minEXP=0, maxEXP=600;
   HP1= check(HP1,minHP,maxHP);
   HP2=check(HP2,minHP,maxHP);
   EXP1=check(EXP1,minEXP,maxEXP);
    EXP2=check(EXP2,minEXP,maxEXP);
    if (E3<0||E3>99) return -99;
    int countBig=0, countSmall=0;
   int mapPoint[10][10];
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            mapPoint[i][j]=((E3*j)+(i*2))*(i-j);
        }
    }
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            if (mapPoint[i][j]>(2*E3)) countBig++;
            if (mapPoint[i][j]<-E3) countSmall++;
        }
    }
int I=(countBig<10) ? countBig : (countBig%10+countBig/10);
I =(I<10) ? I : (I%10+I/10);
int P=(countSmall<10) ? countSmall : (countSmall%10+countSmall/10);
P =(P<10) ? P : (P%10+P/10);
int taxiPoint=mapPoint[I][P];
const int max=taxiPoint;
//
    for (int i=0;i<10;i++){
      if (mapPoint[I-i][P-i]>max) max=mapPoint[I-i][P-i];
      if ((I-i)==0||(P-i)==0) break;
    }
//
    for (int i=0;i<10;i++){
      if (mapPoint[I+i][P+i]>max) max=mapPoint[I+i][P+i];
      if ((I+i)==9||(P+i)==9) break;
    }
//
    for (int i=0;i<10;i++){
      if (mapPoint[I-1][P+i]>max) max=mapPoint[I+i][P+i];
      if ((I-i)==0||(P+i)==9) break;
    }
// 
     for (int i=0;i<10;i++){
      if (mapPoint[I+i][P-i]>max) max=mapPoint[I+i][P-i];
      if ((I+i)==9||(P-i)==0) break;
    }
int twoManPoint=max;   
   if (abs(twoManPoint)>=abs(taxiPoint)) {
       EXP1=ceil(EXP1*120.0/100);
       EXP2=ceil(EXP2*120.0/100);
       HP1=ceil(HP1*110.0/100);
       HP2=ceil(HP2*110.0/100);
   }
   else {
       EXP1=ceil(EXP1*88.0/100);
       EXP2=ceil(EXP2*88.0/100);
       HP1=ceil(HP1*90.0/100);
       HP2=ceil(HP2*90.0/100);
   }
    HP1= check(HP1,minHP,maxHP);
   HP2=check(HP2,minHP,maxHP);
   EXP1=check(EXP1,minEXP,maxEXP);
    EXP2=check(EXP2,minEXP,maxEXP);
   int k= (abs(twoManPoint)>=abs(taxiPoint)) ? twoManPoint : taxiPoint;
return k;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    char se[101];
    int length_se = strchr(email, '@') - email;
    strncpy(se, email, length_se);
   se[length_se] = '\0';
   const char* check = strstr(s, se);
    if (check != nullptr)
        return -(300 + (check - s)); 
    //Kiểm tra độ dài hợp lệ của s
    int length_s = strlen(s);
    if (length_s < 8)
        return -1; 
    if (length_s > 20)
        return -2; 
        int k;
    for (int i=0;i<length_s-2;i++){
        if (s[i]==s[i+1]&&s[i+1]==s[i+2]) 
        return -(400+i);
        break;
    }
    bool specialChar = false;
    for (int i = 0; i < length_s; ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            specialChar = true;
    }
    if (!specialChar)
        return -5; 
    return -10;
}
// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    int maxFrequency = 0; 
    int maxLength = 0;   
    int firstPosition = 0; 
     int currentFrequency = 0;      
    for (int i = 0; i < num_pwds; ++i) {
        const char *Pwds = arr_pwds[i];
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(Pwds, arr_pwds[j]) == 0) {
                currentFrequency++;
            }
        }
        if (currentFrequency > maxFrequency || (currentFrequency == maxFrequency && strlen(Pwds) > maxLength)) {
            maxFrequency = currentFrequency;
            maxLength = strlen(Pwds);
            firstPosition = i; 
        }
    }
    return firstPosition;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////