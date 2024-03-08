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
void resetHP(int  & HP){
 if(HP<0){
    HP=0;
 }
 else if(HP>666){
    HP=666;
 }
}
void resetEXP(int & EXP){
 if(EXP<0){
    EXP=0;
 }
 else if(EXP>600){
    EXP=600;
 }
}
void resetM(int & M){
 if(M<0){
    M=0;
 }
 else if(M>3000){
    M=3000;
 }
} 
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
     if(e1<0||e1>99){
        return -99;
     }
    float E1 = (float)e1;
    if(E1>=0 && E1<=3){
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
            exp2+=149;
            break;
        }
        resetEXP(exp2);
        int D;
         D=E1*3 + exp1*7;
        float d = (float)D;
        if((D+1)%2){
            exp1=ceil(exp1+d/200);
        }
        else {
            exp1=ceil(exp1-d/100);
        }
        resetEXP(exp1);
    }
    else if(E1>=4 && E1<=99){
        if(E1<20){
            exp2=ceil(exp2+(E1/4 + 19));
            resetEXP(exp2);
        }
        else if(E1<50){
            exp2=ceil(exp2+(E1/9+21));
            resetEXP(exp2);
        }
        else if(E1<66){
            exp2=ceil(exp2+(E1/16+17));
            resetEXP(exp2);
        }
        else if(E1<80){
            exp2=ceil(exp2+(E1/4 + 19));
            resetEXP(exp2);
            if(exp2>200){
                exp2=ceil(exp2+(E1/9+21));
                resetEXP(exp2);
            }
        }
        else {
            exp2=ceil(exp2+(E1/4+19));
            resetEXP(exp2);
            exp2=ceil(exp2+(E1/9+21));
            resetEXP(exp2);
            if(exp2>400){
                 exp2=ceil(exp2+(E1/16+17));
                 resetEXP(exp2);
                 exp2=ceil(exp2*1.15);
                 resetEXP(exp2);
            }
        }
        exp1-=E1;
    }
    return exp1 + exp2;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
     if(E2<0||E2>99){
        return -99;
    }
    double p,p1,p2,p3;
 p1=(EXP1>=round(sqrt(EXP1))*round(sqrt(EXP1)))?1:((EXP1/(round(sqrt(EXP1))*round(sqrt(EXP1))))+80)/123;
 int preHP1;
 if((E2%2)+1){
    int maxM1=M1;
    while(maxM1-M1<=(maxM1/2)){
        if(maxM1-M1>=(maxM1/2)+1){
            break;
        }
        else{
        preHP1=HP1;
       HP1=(preHP1<200)?ceil(HP1*1.3):ceil(HP1*1.1);
       M1=(preHP1<200)?M1-150:M1-70;
         resetHP(HP1);
        resetM(M1);
        if(maxM1-M1<=(maxM1/2)){
        M1=(EXP1<400)?M1-200:M1-120;
        resetM(M1);
        EXP1=ceil(EXP1*1.13);
        resetEXP(EXP1);
        if(maxM1-M1<=(maxM1/2)){
        M1=(EXP1<300)?M1-100:M1-120;
        resetM(M1);
        EXP1=ceil(0.9*EXP1);
        resetEXP(EXP1);}}}
    }
 }
 else {if(M1>0){
       preHP1=HP1;
       HP1=(preHP1<200)?ceil(HP1*1.3):ceil(HP1*1.1);
       M1=(preHP1<200)?M1-150:M1-70;
         resetHP(HP1);
        resetM(M1);
        if(M1>0){
        M1=(EXP1<400)?M1-200:M1-120;
        resetM(M1);
        EXP1=ceil(EXP1*1.13);
        resetEXP(EXP1);
        if(M1>0){
        M1=(EXP1<300)?M1-100:M1-120;
        resetM(M1);
        EXP1=ceil(0.9*EXP1);
        resetEXP(EXP1);}}}
 }
 HP1=ceil(HP1*0.83);
 resetHP(HP1);
 EXP1=ceil(EXP1*1.17);
 resetEXP(EXP1);
 p2=(EXP1>=round(sqrt(EXP1))*round(sqrt(EXP1)))?1:((EXP1/(round(sqrt(EXP1))*round(sqrt(EXP1))))+80)/123;
 double P[10]={0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11};
 p3=(E2%10==0)?P[E2]:((E2/10+E2%10)%10);
 if(p1==1 && p2==1 && p3==1){
    EXP1=ceil(EXP1*0.75);
    resetEXP(EXP1);
 } 
 else {
 p=(p1+p2+p3)/3;
 HP1=(p<0.5)?ceil(HP1*0.85):ceil(HP1*0.9);
 EXP1=(p<0.5)?ceil(EXP1*1.15):ceil(EXP1*1.2);
 resetEXP(EXP1);
 resetHP(HP1);
 }

    return HP1 + EXP1 + M1;
 }

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0||E3>99){
        return -99;
    }
    else{
        int taxi[10][10];
        int I=0;
        int J=0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                taxi[i][j]=((E3*j)+(i*2))*(i-j);
                if(taxi[i][j]>(E3*2)){
                    I++;
                }
                if(taxi[i][j]<(-E3)){
                    J++;
                }
            }
         }
          while(I/10!=0){
                I=(I/10)+(I%10);
            }
            while(J/10!=0){
                J=(J/10)+(J%10);
            }
            int SH;
            if((I==0 && J==0)||(I==9 && J==9)){
                SH==0;
            }
            else if((I==9 && J==0)||(I==0 && J==9)){
                SH=taxi[9][0];
                for(int k=1;k<10;k++){
                    if(SH<taxi[9-k][k]){
                        SH=taxi[9-k][k];
                    }
                }
            }
            else{
                int SHl;
                int SHr;
                if(I+J<=9){
                 SHr=taxi[I+J][0];
                 for(int k=1;k<I+J+1;k++){
                    if(SHr<taxi[I+J-k][k]){
                        SHr=taxi[I+J-k][k];
                     }
                  }
            }
                 else{
                 SHr=taxi[9][I+J-9];
                 for(int k=1;k<19-I-J;k++){
                    if(SHr<taxi[9-k][I+J-9+k]){
                        SHr=taxi[9-k][I+J-9+k];
                    }
                 }
                  }
                  if(I==J){
                    SHl=0;
                  }
                  else if(I>J){
                    SHl=taxi[I-J][0];
                    for(int k=1;k<10-I+J;k++){
                        if(SHl<taxi[I-J+k][k]){
                            SHl=taxi[I-J+k][k];
                        }
                    }
                  }
                  else{
                    SHl=taxi[0][J-I];
                    for(int k=1;k<10-J+I;k++){
                        if(SHl<taxi[k][J-I+k]){
                            SHl=taxi[k][J-I+k];
                        }
                    }
                  }
                  SH=fmax(SHl,SHr);
                  SH=abs(SH);
             }
            if(abs(taxi[I][J])>SH){
                HP1=ceil(0.9*HP1);
                EXP1=ceil(0.88*EXP1);
                HP2=ceil(0.9*HP2);
                EXP2=ceil(0.88*EXP2);
                resetHP(HP1);
                resetHP(HP2);
                resetEXP(EXP1);
                resetEXP(EXP2);
                return taxi[I][J];
             }
             else {
                HP1=ceil(1.1*HP1);
                EXP1=ceil(1.12*EXP1);
                HP2=ceil(1.1*HP2);
                EXP2=ceil(1.12*EXP2);
                resetHP(HP1);
                resetHP(HP2);
                resetEXP(EXP1);
                resetEXP(EXP2);
                return SH;
             }
         }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    char se[100];
     const char* n=strchr(email,'@');
    strncpy(se,email,(n-email));
    se[n-email]='\0';
    int l=strlen(s);
    if(l<8){
        return -1;
    }
    if(l>20){
        return -2;
    }
    const char* result =strstr(s,se);
    if(result!=nullptr){
        return -(300+(result-s));
    }
    for(int i=0; i<l-2;i++){
        if(s[i]==s[i+1]&&s[i+2]==s[i+1]){
            return -(400+i);
            break;
        }
    }
    bool specialchar=false;
    for(int j=0;j<l;j++){
        if(s[j]=='@'||s[j]=='%'||s[j]=='$'||s[j]=='!'||s[j]=='#'){
            specialchar=true;
            break;
        }
    }
    if(!specialchar){
        return -5;
    }
    for(int k=0;k<l;k++){
        if((s[k]>='A' && s[k]<='Z')||(s[k]>='a'&& s[k]<='z')||(s[k]>='0'&& s[k]<='9')||(s[k]=='@'||s[k]=='%'||s[k]=='$'||s[k]=='!'||s[k]=='#')){
            continue;
        }
        else {
            return k;
            break;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int count[1000];
    int length[1000];
    for(int i=0;i<num_pwds;i++){
        count[i]=0;
        length[i]=strlen(arr_pwds[i]);
        for(int  j=0;j<num_pwds;j++){
            if(arr_pwds[j]==arr_pwds[i]){
                count[i]++;
            }
        }
    }
     int MAX=count[0];
     int a=0;
    for(int k=0;k<num_pwds;k++){
        if(MAX<count[k]){
            MAX=count[k];
            a=k;
        }}
    for(int t=0;t<num_pwds;t++){
        if(count[t]==MAX && length[t]>length[a]){
            a=t;
        }
    }
    return a;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////