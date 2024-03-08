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
//Check component
void checkHP(int &HP){
    if (HP>666) HP=666;
    else if (HP<0) HP=0;
}
void checkEXP(int &EXP){
    if(EXP>600) EXP=600;
    else if (EXP<0) EXP=0;
}
void checkM(int &M){
    if(M>3000) M=3000;
    else if(M<0) M=0;
}
double task2P(int EXP1){
    int S=0, a=sqrt(EXP1);
    if((EXP1-a*a)<((a+1)*(a+1)-EXP1)) return 1;
    else {
        S=(a+1)*(a+1);
        return (double(EXP1)/S+80)/123.;
}
}
void duong2sk1(int & HP1,int & M1, int E2, bool &state, int hm ){
    if (state){
        if(HP1<200){
            M1-=150;
            checkM(M1);
            if((M1==0 && E2%2==0)||(M1<hm && E2%2==1)) {
                HP1=HP1*130/100 + ((HP1*130)%100==0? 0:1);
                state=0;
            }
            else HP1=HP1*130/100 + ((HP1*130)%100==0? 0:1);
        }
        else{
            M1-=70;
            checkM(M1);
            if((M1==0 && E2%2==0)||(M1<hm && E2%2==1)) {
                HP1=HP1*110/100 + ((HP1*110)%100==0? 0:1);
                state=0;
            }
            else HP1=HP1*110/100 + ((HP1*110)%100==0? 0:1);
        }
        checkHP(HP1);
    }

}
void duong2sk2(int & EXP1, int & M1, int E2, bool &state, int hm ){
    if (state){
        if(EXP1<400){
            M1-=200;
            checkM(M1);
            if((M1==0 && E2%2==0)||(M1<hm && E2%2==1)) {
                EXP1=EXP1*113/100 + ((EXP1*113)%100==0? 0:1);
                state=0;
            }
            else EXP1=EXP1*113/100 + ((EXP1*113)%100==0? 0:1);
        }
        else{
            M1-=120;
            checkM(M1);
            if((M1==0 && E2%2==0)||(M1<hm && E2%2==1)) {
                EXP1=EXP1*113/100 + ((EXP1*113)%100==0? 0:1);
                state=0;
            }
            else EXP1=EXP1*113/100 + ((EXP1*113)%100==0? 0:1);
        }
        checkEXP(EXP1);
    }
}
void duong2sk3(int & EXP1, int & M1, int E2, bool &state, int hm ){
    if(state){
        if(EXP1<300){
            M1-=100;
            checkM(M1);
            if((M1==0 && E2%2==0)||(M1<hm && E2%2==1)) {
                EXP1=EXP1*90/100 + ((EXP1*90)%100==0? 0:1);
                state=0;
            }
            else EXP1=EXP1*90/100 + ((EXP1*90)%100==0? 0:1);
        }
        else{
            M1-=120;
            checkM(M1);
            if((M1==0 && E2%2==0)||(M1<hm && E2%2==1)) {
                EXP1=EXP1*90/100 + ((EXP1*90)%100==0? 0:1);
                state=0;
            }
            else EXP1=EXP1*90/100 + ((EXP1*90)%100==0? 0:1);
        }
        checkEXP(EXP1);
    }
}



// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    checkEXP(exp1);
    checkEXP(exp2);
    if (e1<0||e1>99) return -99;
    int D=0;
    if(e1<=3){
    switch (e1){
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
       exp2=exp2+29+45+75;
       break;
    }
    checkEXP(exp2);
    D=e1*3+exp1*7;
    if (D%2==0) exp1=exp1+int(D/200)+(D%200==0? 0:1);
    else exp1=exp1-int(D/100);
    checkEXP(exp1);
   }
   else {
    if(e1<=19) exp2=exp2+int(e1/4+19)+(e1%4==0? 0:1);
    else if(e1<=49) exp2=exp2+int(e1/9+21)+(e1%9==0? 0:1);
    else if(e1<=65) exp2=exp2+int(e1/16+17)+(e1%16==0? 0:1);
    else if(e1<=79) {
        exp2=exp2+int(e1/4+19)+(e1%4==0? 0:1);
        if (exp2>200) exp2=exp2+int(e1/9+21)+(e1%9==0? 0:1);
   }
   else {
        exp2=exp2+int(e1/4+19)+(e1%4==0? 0:1);
        exp2=exp2+int(e1/9+21)+(e1%9==0? 0:1);
        if (exp2>400) {
            exp2=exp2+int(e1/16+17)+(e1%16==0? 0:1);
            exp2=exp2*115/100 + ((exp2*115)%100==0? 0:1);
   }
   }
    exp1-=e1;
    checkEXP(exp2);
    checkEXP(exp1);
   }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    checkHP(HP1);
    checkEXP(EXP1);
    checkM(M1);
    if (E2<0||E2>99) return -99;
    //Duong 1
    double P1=task2P(EXP1);
    //Duong 2
    bool state=1;
    int hm=0.5*M1+(M1%2==0? 0:1);
    if(E2%2==0){
        duong2sk1(HP1,M1,E2,state,hm);
        duong2sk2(EXP1,M1,E2,state,hm);
        duong2sk3(EXP1,M1,E2,state,hm);
        HP1=HP1*83/100+((HP1*83)%100==0? 0:1);
        EXP1=EXP1*117/100+((EXP1*117)%100==0? 0:1);
    }
    if(E2%2==1){
        while(state){
            duong2sk1(HP1,M1,E2,state,hm);
            duong2sk2(EXP1,M1,E2,state,hm);
            duong2sk3(EXP1,M1,E2,state,hm);
        }
        HP1=HP1*83/100+((HP1*83)%100==0? 0:1);
        EXP1=EXP1*117/100+((EXP1*117)%100==0? 0:1);
    }
    checkHP(HP1);
    checkEXP(EXP1);
    double P2=task2P(EXP1);
    //Duong 3
    double P3=0;
    int a[10]={32,47,28,79,100,50,22,83,64,11};
    if(E2<=9) P3=a[E2]/100.;
    else P3=a[(E2/10+E2%10)%10]/100.;
    //Tong ket
    if((P1+P2+P3)/3==1) EXP1=EXP1*75/100+((EXP1*75)%100==0? 0:1);
    else if((P1+P2+P3)/3<0.5){
        HP1=HP1*85/100+((HP1*85)%100==0? 0:1);
        EXP1=EXP1*115/100+((EXP1*115)%100==0? 0:1);
        }
    else{
        HP1=HP1*90/100+((HP1*90)%100==0? 0:1);
        EXP1=EXP1*120/100+((EXP1*120)%100==0? 0:1);
    }
    checkHP(HP1);
    checkEXP(EXP1);
    return HP1 + EXP1 + M1;
    }

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    checkHP(HP1);
    checkHP(HP2);
    checkEXP(EXP1);
    checkEXP(EXP2);
    if (E3<0||E3>99) return -99;
    int Taxi[10][10];
    for(int i=0;i<10;i++ )
        for(int j=0;j<10;j++) Taxi[i][j]=0;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++) Taxi[i][j]=((E3*j)+(i*2))*(i-j);
    int im=0,jm=0;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++){
            if(Taxi[i][j]>E3*2) im++;
            if(Taxi[i][j]<(-E3)) jm++;
        }
    while(im>=10) im=im/10+im%10;
    while(jm>=10) jm=jm/10+jm%10;
    int max=0;
    int a=im,b=jm;
    while(a>=0 && b>=0 ){
        if (Taxi[a][b]>max) max=Taxi[a][b];
        a--;
        b--;
    }
    a=im,b=jm;
    while(a<=9 && b<=9 ){
        if (Taxi[a][b]>max) max=Taxi[a][b];
        a++;
        b++;
    }
    a=im,b=jm;
    while(a<=9 && b>=0 ){
        if (Taxi[a][b]>max) max=Taxi[a][b];
        a++;
        b--;
    }
    a=im,b=jm;
    while(a>=0 && b<=9 ){
        if (Taxi[a][b]>max) max=Taxi[a][b];
        a--;
        b++;
    }
    
    
    if(abs(Taxi[im][jm])>abs(max)){
        HP1=HP1*90/100+((HP1*90)%100==0? 0:1);
        EXP1=EXP1*88/100+((EXP1*88)%100==0? 0:1);
        HP2=HP2*90/100+((HP2*90)%100==0? 0:1);
        EXP2=EXP2*88/100+((EXP2*88)%100==0? 0:1);
        checkHP(HP1);
        checkHP(HP2);
        checkEXP(EXP1);
        checkEXP(EXP2);
        return Taxi[im][jm];
    }
    else{
        HP1=HP1*110/100+((HP1*110)%100==0? 0:1);
        EXP1=EXP1*112/100+((EXP1*112)%100==0? 0:1);
        HP2=HP2*110/100+((HP2*110)%100==0? 0:1);
        EXP2=EXP2*112/100+((EXP2*112)%100==0? 0:1);
        checkHP(HP1);
        checkHP(HP2);
        checkEXP(EXP1);
        checkEXP(EXP2);
        return max;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    //Kiem tra do dai
    if (strlen(s)<8) return -1;
    if (strlen(s)>20) return -2;
    char se[100]={0};
    for(int i=0;i<100;i++){
        if(email[i]==64) break;
        se[i]=email[i];
    }
    //Kiem tra s co chua se
    for(int i=0;i<strlen(s);i++){
        for(int j=0;j<strlen(se);j++){
            if (s[i+j]!=se[j]) break;
            if (j==strlen(se)-1) return -(300+i);
        }
    }
    //Kiem tra ky tu lien tiep
    for (int i=0;i<strlen(s)-2;i++){
        if (s[i]==s[i]+1 && s[i]==s[i+2]) return -(400+i);
    }

    //Kiem tra ky tu dac biet
    for(int i=0;i<strlen(s);i++){
        if(s[i]<=47||(s[i]>=58 && s[i]<=64)||(s[i]>=91 && s[i]<=96)||(s[i]>=123 && s[i]<=127)) break;
        if(i==strlen(s)-1) return -5;
    }



    


    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int count[300]={0};
    for (int i=0;i<num_pwds;i++){
        for (int j=i;j<num_pwds;j++)
            if(strcmp(arr_pwds[i],arr_pwds[j])==0) count[i]++;
    }
    int mk=0,vtr=0,maxlength=0;
    for(int i=0;i<num_pwds;i++){
        if(count[i]>mk||(count[i]==mk && strlen(arr_pwds[i]) > maxlength)){
            mk=count[i];
            vtr=i;
            maxlength=strlen(arr_pwds[i]);
        }
    }
    return vtr;
    }


    


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////