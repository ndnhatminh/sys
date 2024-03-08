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
    if(exp1<0){
        exp1=0;
    }
    if(exp2<0){
        exp2=0;
    }
    if(exp1>600){
        exp1=600;
    }
    if(exp2>600){
        exp2=600;
    }
    if(e1<0||e1>99){
        return -99;
    }
    if(e1<=3){
        if(e1==0){
            exp2+=29;
        }
        else if(e1==1){
            exp2+=45;
        }
        else if(e1==2){
            exp2+=75;
        }
        else{
            exp2=exp2+29+45+75;
        }
        int d=e1*3+exp1*7;
        if((d%2)==0){
            exp1=exp1+(d/200);
        }
        else{
            exp1=exp1-(d/100);
        }
    }
    else{
        if(e1<=19){
            exp2=exp2+(ceil((e1/4.0))+19);
        }
        else if(e1<=49){
            exp2=exp2+(ceil((e1/9.0))+21);
        }
        else if(e1<=65){
            exp2=exp2+(ceil((e1/16.0))+17);
        }
        else if(e1<=79){
            exp2=exp2+(ceil((e1/4.0))+19);
            if(exp2>200){
                exp2=exp2+(ceil((e1/9.0))+21);
            }
        }
        else{
            exp2=exp2+(ceil((e1/4.0))+19);
            exp2=exp2+(ceil((e1/9.0))+21);
            if(exp2>400){
                exp2=(exp2+(ceil((e1/16.0))+17));
                exp2=ceil(exp2)*1.15;
            }
            
        }
        exp1=exp1-e1;

    }
    if(exp1<0){
        exp1=0;
    }
    if(exp2<0){
        exp2=0;
    }
    if(exp1>600){
        exp1=600;
    }
    if(exp2>600){
        exp2=600;
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(EXP1<0){
        EXP1=0;
    }
    if(HP1<0){
        HP1=0;
    }
    if(EXP1>600){
        EXP1=600;
    }
    if(HP1>666){
        HP1=666;
    }
    if(M1<0){
        M1=0;
    }
    if(M1>3000){
        M1=3000;
    }
    if(E2<0||E2>99){
        return -99;
    }
    double p,p1,p2,p3,s1,s2;
    int i2;
    s1=round(sqrt(EXP1))*round(sqrt(EXP1));
    if(s1<EXP1){
        p1=1;
    }
    else{
        p1=((EXP1/s1)+80)/123;
    }
    if(E2%2!=0){
        double HM=ceil(M1*0.5);
        while(M1>HM){
        while(M1>HM){
        if(HP1<200){
            HP1=ceil(HP1*1.3);
            M1=M1-150;
        }
        else{
            HP1=ceil(HP1*1.1);
            M1=M1-70;
        }
        break;
    }
    while (M1>HM){
        if(EXP1<400){
            M1=M1-200;
            EXP1=ceil(EXP1*1.13);
        }
        else
        {
            M1=M1-120;
            EXP1=ceil(EXP1*1.13);
        }
        break;
    }
    while(M1>HM){
     if(EXP1<300){
        M1=M1-100;
        EXP1=ceil(EXP1*0.9);
     }
     else
     {
        M1=M1-120;
        EXP1=ceil(EXP1*0.9);
     }
        break;
    }
    }
    if(M1<0){
        M1=0;
    }
    HP1=ceil(HP1*0.83);
    EXP1=ceil(EXP1*1.17);
    }
    else{
        while(M1>0){
        if(HP1<200){
            HP1=ceil(HP1*1.3);
            M1=M1-150;
        }
        else{
            HP1=ceil(HP1*1.1);
            M1=M1-70;
        }
        break;
    }
    while (M1>0){
        if(EXP1<400){
            M1=M1-200;
            EXP1=ceil(EXP1*1.13);
        }
        else
        {
            M1=M1-120;
            EXP1=ceil(EXP1*1.13);
        }
        break;
    }
    while(M1>0){
     if(EXP1<300){
        M1=M1-100;
        EXP1=ceil(EXP1*0.9);
     }
     else
     {
        M1=M1-120;
        EXP1=ceil(EXP1*0.9);
     }
        break;
    }
    if(M1<0){
        M1=0;
    }
    HP1=ceil(HP1*0.83);
    EXP1=ceil(EXP1*1.17);
    }
    s2=round(sqrt(EXP1))*round(sqrt(EXP1));
    if(s2<EXP1){
        p2=1;
    }
    else{
        p2=((EXP1/s2)+80)/123;
    }
    double P[10] = {0.32,0.47,0.28,0.79,0.100,0.50,0.22,0.83,0.64,0.11};
    if(E2<10){
        i2=E2;
        p3 = P[i2];
    }
    else{
        int tong=E2/10+E2%10;
        if(tong<10){
            i2=tong;
        }
        else{
            i2=tong-10;
        }
        p3=P[i2];
    }
    if(p1==1&&p2==1&&p3==1){
        EXP1=ceil(EXP1*0.75);
    }
    else{
        p=(p1+p2+p3)/3;
        if(p<0.5){
            HP1=ceil(HP1*0.85);
            EXP1=ceil(EXP1*1.15);
        }
        else{
            HP1=ceil(HP1*0.9);
            EXP1=ceil(EXP1*1.2);
        }
    }
    if(EXP1<0){
        EXP1=0;
    }
    if(HP1<0){
        HP1=0;
    }
    if(EXP1>600){
        EXP1=600;
    }
    if(HP1>666){
        HP1=666;
    }
    if(M1<0){
        M1=0;
    }
    if(M1>3000){
        M1=3000;
    }
    
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(EXP1<0){
        EXP1=0;
    }
    if(HP1<0){
        HP1=0;
    }
    if(EXP1>600){
        EXP1=600;
    }
    if(HP1>666){
        HP1=666;
    }
    if(EXP2<0){
        EXP2=0;
    }
    if(HP2<0){
        HP2=0;
    }
    if(EXP2>600){
        EXP2=600;
    }
    if(HP2>666){
        HP2=666;
    }
    if(E3<0||E3>99){
        return -99;
    }
    
    int Taxi[10][10];
    int i,j,am,duong,x,max,giatri;
    am=0;
    duong=0;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            Taxi[i][j]=((E3*j)+(i*2))*(i-j);
            if(Taxi[i][j]<(-E3)){
                am+=1;
            }
            if(Taxi[i][j]>(E3*2)){
                duong+=1;
            }
        }
    }
    while(am>=10){
        am=am/10+am%10;
    }
    j=am;
    while(duong>=10){
        duong=duong/10+duong%10;
    }
    i=duong;
    x=Taxi[i][j];
    max=Taxi[i][j];
    int I,J;
    I=i;
    J=j;
    while(I>0&&J>0){
        I-=1;
        J-=1;
        if(max<Taxi[I][J]){
            max=Taxi[I][J];
        }
    }
    while(I<9&&J<9){
        I+=1;
        J+=1;
        if(max<Taxi[I][J]){
            max=Taxi[I][J];
        }
    }
    while(I>0&&J<9){
        I-=1;
        J+=1;
        if(max<Taxi[I][J]){
            max=Taxi[I][J];
        }
    }
    while(I<9&&J>0){
        I+=1;
        J-=1;
        if(max<Taxi[I][J]){
            max=Taxi[I][J];
        }
    }
    if(abs(x)>max){
        EXP1=ceil(EXP1*0.88);
        EXP2=ceil(EXP2*0.88);
        HP1=ceil(HP1*0.9);
        HP2=ceil(HP2*0.9);
    }
    else
    {
        EXP1=ceil(EXP1*1.12);
        EXP2=ceil(EXP2*1.12);
        HP1=ceil(HP1*1.1);
        HP2=ceil(HP2*1.1);
    }
    
    if(EXP1<0){
        EXP1=0;
    }
    if(HP1<0){
        HP1=0;
    }
    if(EXP1>600){
        EXP1=600;
    }
    if(HP1>666){
        HP1=666;
    }
    if(EXP2<0){
        EXP2=0;
    }
    if(HP2<0){
        HP2=0;
    }
    if(EXP2>600){
        EXP2=600;
    }
    if(HP2>666){
        HP2=666;
    }
    if(abs(x)>max){
        giatri=x;
    }
    else
    {
        giatri=max;
    }
    return giatri;
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    if(strlen(s)<8){
        return -1;
    }
    if(strlen(s)>20){
        return -2;

    }
    int sei,sci;
    string se,sp;
    for(int i=0;i<strlen(email);i++){
        if(email[i]=='@'){
            break;
        }
        se.push_back(email[i]);
    }
    for(int i=0;i<strlen(s);i++){
        sp.push_back(s[i]);
    }

        sei=sp.find(se);
        if(sei<20){
        sei=-(300+sei);
        return sei;
        }
    for(int i=0;i<strlen(s);i++){
        int j=i+1;
        if(sp[i]==sp[j]){
            sci=i;
            sci=-(400+sci);
            return sci;
            break;
        }
    }
    for(int i=0;i<strlen(s);i++){
        if (s[i]=='@'||s[i]=='!'||s[i]=='%'||s[i]=='$'||s[i]=='#'){
            return -5;
            break;
        }
    }
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
     string only[num_pwds];
     int count[num_pwds];
     int max=0;
     int n=0;
     int m=0;
     string correct;
      for(int i=0;i<num_pwds;i++){
            only[i]=arr_pwds[i];
            count[i]=0;
        }
      for(int i=0;i<num_pwds;i++){
        for(int j=0;j<num_pwds;j++){
            if(only[i]==only[j]){
                count[i]+=1;
            }
        }
      }
      for(int i=0;i<num_pwds;i++){
        if(max<count[i]){
            max=count[i];
        }
      }
      for(int i=0;i<num_pwds;i++){
            if(max==count[i]){
                n = i;
                correct=only[n];
                break;
            }
        }
        for(int i=0;i<num_pwds;i++){
            if(max==count[i]&&only[n]!=only[i]){
                m=i;
                if(strlen(arr_pwds[n])>strlen(arr_pwds[m])){
                    continue;
                }
                else{
                    n=m;
                    correct=only[n];
                }
            }
        }
         for(int i=0;i<num_pwds;i++){
            if(correct==arr_pwds[i]){
                return i;
            }
         }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////