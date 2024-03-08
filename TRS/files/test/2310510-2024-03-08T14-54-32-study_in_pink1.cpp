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

// HAM LAM TRON LEN VA KHONG VUOT KHOANG CHO PHEP
int roundup(float x, int beyond){
if (x>beyond) x=beyond;
else if (x<0) x=0;
     else if (x-round(x)>0) x=round(x)+1;
          else if (x-round(x)<0) x=round(x);
return round(x);
}
int roundEXP(float x){ return roundup(x, 600); };
int roundHP(float x){ return roundup(x, 666); };
int roundM(float x){ return roundup(x, 3000); };


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    int D;
    if(e1>=0 && e1<=99){        exp1=roundEXP(exp1); exp2=roundEXP(exp2); 
        //TH1
        if (e1<=3){
            switch(e1){
            case(0): exp2+=29; break;
            case(1): exp2+=45; break;
            case(2): exp2+=75; break;
            case(3): exp2+=29+45+75;
            }
            exp2=roundEXP(exp2);
            //Du doan
            D=e1*3+exp1*7;
            if (D%2==0) exp1=roundEXP(exp1+D/200.0);
            else exp1=roundEXP(exp1-D/100.0);
        }
        //TH2
        else{
            //4-19 Thong tin 1
            if (e1<=19){
            exp2=roundEXP(exp2+(e1/4.0+19));
            }
            //20-49 Thong tin 2
            else if (e1<=49){
            exp2=roundEXP(exp2+(e1/9.0+21));
            }
            //50-65 Thong tin 3
            else if (e1<=65){
            exp2=roundEXP(exp2+(e1/16.0+17));
            }
            //66-79 Thong tin 1+2
            else if (e1<=79){
            exp2=roundEXP(exp2+(e1/4.0+19));
            if (exp2>200) exp2=roundEXP(exp2+(e1/9.0+21));
            }
            //80-99 Thong tin 1+2+3
            else {
            exp2=roundEXP(exp2+(e1/4.0+19));
            exp2=roundEXP(exp2+(e1/9.0+21));
            if (exp2>400) {exp2=roundEXP(exp2+(e1/16.0+17)); exp2=roundEXP(exp2*1.15);}
            }
        exp1=roundEXP(exp1-e1);
        }
        return exp1 + exp2;
    }
    else return -99;
}




///////////////////////////////////////////////////////////////////////////
void calP(float & P, int EXP){
        int S=round(sqrt(EXP));
        if (S>sqrt(EXP)) S--;
        if (EXP*2<pow(S,2)+pow(S+1,2)) P=1; else P=(EXP*1.0/(S*S)+80)/123;
}
///////////////////////////////////////////////////////////////////////////



// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
if (E2>=0 && E2<=99){    EXP1=roundEXP(EXP1); HP1=roundHP(HP1); M1=roundM(M1);
    // Bien xac suat
    float P1, P2, P3;
    // Con duong 1
    calP(P1, EXP1);
////////////////////////////////////////////////////////////////////////////////////////////////
    // Con duong 2
    //// Phuong an 1
    if (E2%2!=0){
        bool exit=1; int spend=0, beginroad=M1;
    while (exit){
        if (M1==0) {exit=0; break;}
        //1st step
        if (HP1<200) {HP1=roundHP(HP1*1.3); M1=roundM(M1-150); spend+=150;}
        else {HP1=roundHP(HP1*1.1); M1=roundM(M1-70); spend+=70;}
            if (spend>0.5*beginroad) {exit=0; break;}
        //2nd step
        if (EXP1<400) {M1=roundM(M1-200); spend+=200;}
        else {M1=roundM(M1-120); spend+=120;}
        EXP1=roundEXP(EXP1*1.13);
            if (spend>0.5*beginroad) {exit=0; break;}
        //3rd step
        if (EXP1<300) {M1=roundM(M1-100); spend+=100;}
        else {M1=roundM(M1-120); spend+=120;}
        EXP1=roundEXP(EXP1*0.9);
            if (spend>0.5*beginroad) {exit=0; break;}
    }
    }
    //// Phuong an 2
    else{
        bool exit=1;
        while (exit){
        if (M1==0) {exit=0; break;}
         //1st step
        if (HP1<200) {HP1=roundHP(HP1*1.3); M1=roundM(M1-150);}
        else {HP1=roundHP(HP1*1.1); M1=roundM(M1-70);}
        if (M1==0) {exit=0; break;}

        //2nd step
        if (EXP1<400) {M1=roundM(M1-200);}
        else {M1=roundM(M1-120);}
        EXP1=roundEXP(EXP1*1.13);
        if (M1==0) {exit=0; break;}
        //3rd step
        if (EXP1<300) {M1=roundM(M1-100);}
        else {M1=roundM(M1-120);}
        EXP1=roundEXP(EXP1*0.9);
        if (M1==0) {exit=0; break;}
        //Thoat
        exit=0;
        }
    }
    HP1=roundHP(HP1*0.83); EXP1=roundEXP(EXP1*1.17);
    calP(P2, EXP1);

////////////////////////////////////////////////////////////////////////////////////////////////
    // Con duong 3
    int P[10]={32,47,28,79,100,50,22,83,64,11};
    if (E2>9) {E2=E2/10+E2%10; E2=E2%10;}
    P3=P[E2]/100.0;
    // Tong ket 3 con dong
    if (P1+P2+P3==3) EXP1=roundEXP(EXP1*0.75);
    else {
        P3=(P1+P2+P3)/3;
        if (P3<0.5) {HP1=roundHP(HP1*0.85); EXP1=roundEXP(EXP1*1.15);}
        else {HP1=roundHP(HP1*0.9); EXP1=roundEXP(EXP1*1.2);}
    }

    return HP1 + EXP1 + M1;
}
else return -99;
}




// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
if (E3>=0 && E3<=99){        EXP1=roundEXP(EXP1); HP1=roundHP(HP1); EXP2=roundEXP(EXP2); HP2=roundHP(HP2); 
    // Khoi tao map
    int Taxi[10][10], GT=0, LT=0;
    for (int i=0; i<10; i++) for (int j=0; j<10; j++) {
        Taxi[i][j]=(E3*j+i*2)*(i-j);
        if (Taxi[i][j]>E3*2) GT++;
        else if (Taxi[i][j]<-E3) LT++;
    }
    while (GT>9) {GT=GT/10+GT%10;}
    while (LT>9) {LT=LT/10+LT%10;}
    // Tinh diem Sherlock va Watson
    int scoreSW=-1e+5, lx, ly, rx, ry;
    if (GT>LT) {lx=GT-LT; ly=0;} else {lx=0; ly=LT-GT;}
    for ( ; lx<=9 && ly<=9; lx++, ly++) {if (scoreSW<Taxi[lx][ly]) scoreSW=Taxi[lx][ly];}
    if (GT+LT<9) {rx=0; ry=LT+GT;} else {rx=GT+LT-9; ry=9;}
    for ( ; rx<=9 && ry>=0; rx++, ry--) {if (scoreSW<Taxi[rx][ry]) scoreSW=Taxi[rx][ry];}
    scoreSW=abs(scoreSW);
    // Ket luan
    if (abs(Taxi[GT][LT])>scoreSW) {
        EXP1=roundEXP(EXP1*0.88); HP1=roundHP(HP1*0.9);
        EXP2=roundEXP(EXP2*0.88); HP2=roundHP(HP2*0.9);
        return Taxi[GT][LT];
    }
    else {
        EXP1=roundEXP(EXP1*1.12); HP1=roundHP(HP1*1.1);
        EXP2=roundEXP(EXP2*1.12); HP2=roundHP(HP2*1.1);
        return scoreSW;
    }
}
else return -99;
}


// Task 4
int checkPassword(const char * s, const char * email) {
    int Lse, Lose;
    char se[100]; for (Lse=0; email[Lse]!='@'; Lse++) {se[Lse]=email[Lse];} se[Lse]='\0';
    int Ls=strlen(s), checkse=0, spec=-1;
    // Check do dai
    if (Ls>20) return -2;
    else if (Ls<8) return -1;
    else {
            // Check chuoi se
            for (int i=0; i<=Ls-Lse; i++) {
                if (s[i]==se[0]&&checkse==0) {
                    int j;
                    for (j=1; j<Lse; j++) if (s[i+j]!=se[j]) break;
                    if (j==Lse) {checkse=1; Lose=i; break;}
                }
            }
            if (checkse) return -(300+Lose);
            else{
                // Check ky tu lien tiep
                for (int i=0; i<Ls-2; i++) if(s[i]==s[i+1] && s[i+1]==s[i+2]) return -(400+i);
                // Ky tu dac biet
                for (int i=0; i<Ls; i++) if (s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!') {spec++; break;}
                if (spec) return -5;
                else{
                    // Thanh phan ky tu
                    for (int i=0; i<Ls; i++) {
                            if ((s[i]>=48 && s[i]<=57)||(s[i]>=65 && s[i]<=90)||(s[i]>=97 && s[i]<=122)||s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!') continue;
                            return i;
                    }
                    return -10;
                }
            }
    }
}



// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    const int N=num_pwds;
    int codepwds[N];  for (int i=0; i<N; i++) codepwds[i]=1;
    for (int i=N-1; i>=0; i--) {
        for (int j=i+1; j<=N-1; j++)
            if (!strcmp(arr_pwds[i], arr_pwds[j])) {
                codepwds[i]=codepwds[j]+1;
                break;
            }
        }
    int maxindex=0;
    for (int i=1; i<N; i++)
        if (codepwds[i]>codepwds[maxindex]||(codepwds[i]==codepwds[maxindex]&&strlen(arr_pwds[i])>strlen(arr_pwds[maxindex]))) maxindex=i;
    return maxindex;
}



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
