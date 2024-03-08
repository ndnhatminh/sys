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

int checkEXP(int &exp){
    if(exp<0) exp=0;
    else if(exp>600) exp=600;
    return exp;
} 

int checkHP(int &hp){
    if(hp<0) hp=0;
    else if(hp>666) hp=666;
    return hp;
}

int checkM(int &m){
    if(m<0) m=0;
    else if(m>3000) m=3000;
    return m;
}

int checkNumber(int &n){
    while(n>9){
        int x=n%10;
        int y=(n-x)*0.1;
        n=x+y;
    }
    return n;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    checkEXP(exp1);
    checkEXP(exp2);
    if((e1>=0)&&(e1<=99)){
        if(e1<=3){
            int D=e1*3+exp1*7;
            float sD=D;
            float a;
            if(D%2==0) a=exp1+sD/200;
            else if(D%2==1) a=exp1-sD/100;
            exp1=ceil(a);
            if(e1==0) exp2 +=29;
            else if(e1==1) exp2+=45;
            else if(e1==2) exp2+=75;
            else if(e1==3) exp2+=(29+45+75);
        }
        else if((e1>=4)&&(e1<=99)){
            float b;
            float sE1=e1;
            float sEXP2=exp2;
            if(e1<=19) b=sEXP2+sE1/4+19;
            else if((e1>=20)&&(e1<=49)) b=sEXP2+sE1/9+21;
            else if((e1>=50)&&(e1<=65)) b=sEXP2+sE1/16+17;
            else if((e1>=66)&&(e1<=79)){
                b=sEXP2+sE1/4+19;
                exp2=ceil(b);
                sEXP2=exp2;
                if(exp2>200){
                    b=sEXP2+sE1/9+21; 
                    exp2=ceil(b);
                    sEXP2=exp2;
                }
            }
            else if((e1>=80)&&(e1<=99)){
                b=sEXP2+sE1/4+19;
                exp2=ceil(b);
                sEXP2=exp2;
                b=sEXP2+sE1/9+21;
                exp2=ceil(b);
                sEXP2=exp2;
                if(exp2>400){
                    b=sEXP2+sE1/16+17;
                    exp2=ceil(b);
                    sEXP2=exp2;
                    b=sEXP2*115/100;
                    exp2=ceil(b);
                    sEXP2=exp2;
                }
            }
            exp1=exp1-e1;
            exp2=ceil(b);
        }
    checkEXP(exp1);
    checkEXP(exp2);
    return exp1 + exp2;
    }
    else return-99;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    checkHP(HP1);
    checkEXP(EXP1);
    checkM(M1);
    float P1;
    float P2;
    float P3;
    float fP;
    float sHP1;
    float sEXP1;
    float sqrtEXP1=sqrt(EXP1);
    float a=floor(sqrtEXP1);
    float b=ceil(sqrtEXP1);
    if((sqrtEXP1-a)<=(b-sqrtEXP1)) P1=100;
    else {
        P1=100.0*(EXP1*(1.0/(b*b))+80.0)/123.0;
        P1=round(P1);
        }
    if((E2>=0)&&(E2<=99)){
        if(E2%2==1){
            const float fM=M1*0.5;
            while(M1>=fM){
                if(HP1<200){
                    sHP1=HP1*1.3;
                    M1=M1-150;
                 }
                else {
                    sHP1=HP1*1.1;
                    M1=M1-70;
                }
                HP1=ceil(sHP1);
                checkHP(HP1);
                if(M1<fM) break;
                if(EXP1<400) M1=M1-200;
                else M1=M1-120; 
                sEXP1=EXP1*1.13;
                EXP1=ceil(sEXP1);
                checkEXP(EXP1);
                if(M1<fM) break;
                if(EXP1<300) M1=M1-100;
                else M1=M1-120;
                sEXP1=EXP1*0.9;
                EXP1=ceil(sEXP1);
                if(M1<fM) break;
            }
        }
        else{
            for(int i=0;i<1;++i){
                if(HP1<200){
                    sHP1=HP1*1.3;
                    M1=M1-150;
                 }
                else {
                    sHP1=HP1*1.1;
                    M1=M1-70;
                }
                HP1=ceil(sHP1);
                checkHP(HP1);
                if(M1<=0) break;
                if(EXP1<400) M1=M1-200;
                else M1=M1-120; 
                sEXP1=EXP1*1.13;
                EXP1=ceil(sEXP1);
                checkEXP(EXP1);
                if(M1<=0) break;
                if(EXP1<300) M1=M1-100;
                else M1=M1-120;
                sEXP1=EXP1*0.9;
                EXP1=ceil(sEXP1);
                if(M1<=0) break;
            }
        }
        sHP1=HP1*0.83;
        HP1=ceil(sHP1);
        sEXP1=EXP1*1.17;
        EXP1=ceil(sEXP1);
        checkHP(HP1);
        checkEXP(EXP1);
        checkM(M1);
        sqrtEXP1=sqrt(EXP1);
        a=floor(sqrtEXP1);
        b=ceil(sqrtEXP1);
        if((b-sqrtEXP1)>=(sqrtEXP1-a)) P2=100;
        else {
            P2=100.0*(EXP1*(1.0/(b*b))+80.0)/123.0;
            P2=round(P2);
        }
        float P[10]= {32,47,28,79,100,50,22,83,64,11};
        static int k;
        int n;
        if(E2>=10){
            n=E2%10;
            k=n+(E2-n)/10;
            if(k>=10) k=k%10;
        }
        else k=E2;
        P3=P[k];
        if((P1+P2+P3)==300) {
            sEXP1=EXP1*0.75;
            EXP1=ceil(sEXP1);
        }
        else{
            fP=(P1+P2+P3)/3.0;
            if(fP<50){
                sHP1=HP1*0.85;
                sEXP1=EXP1*1.15;
            }   
            else{
                sHP1=HP1*0.9;
                sEXP1=EXP1*1.2;
            }
            HP1=ceil(sHP1);
            EXP1=ceil(sEXP1);
        }
        checkHP(HP1);
        checkEXP(EXP1);
        checkM(M1);
        return HP1+EXP1+M1;
    }
    else return -99;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    checkHP(HP1);
    checkHP(HP2);
    checkEXP(EXP1);
    checkEXP(EXP2);
    float sEXP1=EXP1;
    float sEXP2=EXP2;
    float sHP1=HP1;
    float sHP2=HP2;
    if((E3>=0)&&(E3<=99)){
        int taxiMap[10][10];
        for(int i=0;i<10;++i){
            for(int j=0;j<10;++j){
            taxiMap[i][j]=((E3*j)+(i*2))*(i-j);
            }   
        }
        int a=0;
        for(int i=0;i<10;++i){
            for(int j=0;j<10;++j) {
                if((taxiMap[i][j])>(E3*2)) ++a;
            }
        }
        int b=0;
        for(int i=0;i<10;++i){
            for(int j=0;j<10;++j) {
                if((taxiMap[i][j])<(0-E3)) ++b;
            }
        }
        a=checkNumber(a);
        b=checkNumber(b);
        int taxiScore=taxiMap[a][b];
        int c=taxiScore;
        int d=taxiScore;
        int e=taxiScore;
        int f=taxiScore;
        for(int i=a,j=b;(i>0)&&(j>0);--i,--j) {
            if(c<(taxiMap[i-1][j-1])) c=(taxiMap[i-1][j-1]);
        }
        for(int i=a,j=b;(i<9)&&(j<9);++i,++j) {
            if(d<(taxiMap[i+1][j+1])) d=(taxiMap[i+1][j+1]);
        }
        for(int i=a,j=b;(i<9)&&(j>0);++i,--j) {
            if(e<(taxiMap[i+1][j-1])) e=(taxiMap[i+1][j-1]);
        }
        for(int i=a,j=b;(i>0)&&(j<9);--i,++j) {
            if(f<(taxiMap[i-1][j+1])) f=(taxiMap[i-1][j+1]);
        }
        int maxScore=max(max(c,d),max(e,f));
        if((abs(maxScore))>=(abs(taxiScore))){
            sEXP1=sEXP1*1.12;
            sEXP2=sEXP2*1.12;
            sHP1=sHP1*1.10;
            sHP2=sHP2*1.10;
            EXP1=ceil(sEXP1);
            EXP2=ceil(sEXP2);
            HP1=ceil(sHP1);
            HP2=ceil(sHP2);
            checkHP(HP1);
            checkHP(HP2);
            checkEXP(EXP1);
            checkEXP(EXP2);
            return maxScore;
        }
        else{
            sEXP1=sEXP1*0.88;
            sEXP2=sEXP2*0.88;
            sHP1=sHP1*0.9;
            sHP2=sHP2*0.9;
            EXP1=ceil(sEXP1);
            EXP2=ceil(sEXP2);
            HP1=ceil(sHP1);
            HP2=ceil(sHP2);
            checkHP(HP1);
            checkHP(HP2);
            checkEXP(EXP1);
            checkEXP(EXP2);
            return taxiScore;
        }
    }
    else return -99;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string sEmail(email);
    string nS(s);
    int pA=sEmail.find('@');
    string se=sEmail.substr(0,pA);
    int sei=nS.find(se);
    int sci=-1;
    for(int i=0;i<(nS.length()-2);++i){
        if((nS[i]==nS[i+1])&&(nS[i+1]==nS[i+2])){
            sci=i;
            break;
        }
    }
    int sc1=nS.find('@');
    int sc2=nS.find('#');
    int sc3=nS.find('%');
    int sc4=nS.find('$');
    int sc5=nS.find('!');
    int pInvalidCharacter=-1;
    char x;
    for(int i=0;i<nS.length();i++){
        x=nS[i];
        if(!((x==33)||(x==35)||(x==36)||(x==38)||(x==64)||((48<=x)&&(x<=57))||((65<=x)&&(x<=90))||((97<=x)&&(x<=122)))){
            pInvalidCharacter=i;
            break;
        }
    }
    if(nS.length()<8) return -1;
    if(nS.length()>20) return -2;
    if(sei>=0) return -(300+sei);
    if(sci>=0) return -(400+sci);
    if((sc1+sc2+sc3+sc4+sc5)==-5) return -5;
    if(pInvalidCharacter>=0) return pInvalidCharacter;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    const char *rightPW=nullptr;
    int a=0;
    int b=0;
    for (int i=0;i<num_pwds;++i){
        const char *PW=arr_pwds[i];
        int l=strlen(PW);
        int c=0;
        for (int j=0;j<num_pwds;++j){
            if (strcmp(PW, arr_pwds[j])==0) ++c;
        }
        if (((c==a)&&(l>b))||(c>a)){
            a=c;
            b=l;
            rightPW=PW;
        }
    }
    for (int i=0; i<num_pwds; ++i) {
        if (strcmp(arr_pwds[i],rightPW)==0){
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////