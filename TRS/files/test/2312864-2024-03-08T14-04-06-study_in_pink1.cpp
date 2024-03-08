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
    if (exp1<0) exp1=0;
    if (exp1>600) exp1=600;
    if (exp2<0) exp2=0;
    if (exp2>600) exp2=600;
    if (e1<0||e1>99) return -99;
    else if (0<=e1&&e1<=3){
        if (e1==0) exp2+=29;
        if (e1==1) exp2+=45;
        if (e1==2) exp2+=75;
        if (e1==3) exp2+=29+45+75;
        int D=e1*3+exp1*7;
        if (D%2==0) exp1=ceil(exp1+D/200.0);
        else exp1=ceil(exp1-D/100.0);}
    else{
        if (4<=e1&&e1<=19) exp2=ceil(exp2+e1/4.0+19);
        if (20<=e1&&e1<=49) exp2=ceil(exp2+e1/9.0+21);
        if (50<=e1&&e1<=65) exp2=ceil(exp2+e1/16.0+17);
        if (66<=e1&&e1<=79){
            exp2=ceil(exp2+e1/4.0+19);
            if (exp2>200) exp2=ceil(exp2+e1/9.0+21);}
        if (80<=e1&&e1<=99){
            exp2=ceil(exp2+e1/4.0+19);
            exp2=ceil(exp2+e1/9.0+21);
            if (exp2>400) exp2=ceil(1.15*ceil(exp2+e1/16.0+17));}
        exp1-=e1;}
    if (exp1<0) exp1=0;
    if (exp1>600) exp1=600;
    if (exp2<0) exp2=0;
    if (exp2>600) exp2=600;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (HP1<0) HP1=0;
    if (HP1>666) HP1=666;
    if (EXP1<0) EXP1=0;
    if (EXP1>600) EXP1=600;
    if (M1<0) M1=0;
    if (M1>3000) M1=3000;
    if (E2<0||E2>99) return -99;
    float P1,P2,P3;
    int b=M1;
//con duong 1//
    if (EXP1-floor(sqrt(EXP1))*floor(sqrt(EXP1))<=ceil(sqrt(EXP1))*ceil(sqrt(EXP1))-EXP1) P1=100;
    else P1=(((float)EXP1/(ceil(sqrt(EXP1))*ceil(sqrt(EXP1)))+80)/123.0)*100;
//con duong 2//
   while (true){
//su kien 1.
        if (M1==0) break;
        if (HP1<200){
            HP1=ceil(HP1*1.3);
            M1-=150;}
        else {
            HP1=ceil(HP1*1.1);
            M1-=70;}
        //-------------------
        if (HP1>666) HP1=666;
        if (M1<0) M1=0;
        //-------------------
        if (E2%2!=0&&M1<0.5*b) break;
        if (E2%2==0&&M1<=0) break;
//su kien 2.
        if (EXP1<400) M1-=200;
        else {
            M1-=120;
            EXP1=ceil(EXP1*1.13);}
        //-------------------
        if (EXP1>600) EXP1=600;
        if (M1<0) M1=0;
        //-------------------
        if (E2%2!=0&&M1<0.5*b) break;
        if (E2%2==0&&M1<=0) break;
        ///su_kien_3
        if (EXP1<300) M1-=100;
        else {
            M1-=120;
            EXP1=ceil(EXP1*0.9);}
        //-------------------
        if (EXP1<0) EXP1=0;
        if (M1<0) M1=0;
        //-------------------
        if (E2%2!=0&&M1<0.5*b) break;
        if (E2%2==0) break;}
        HP1=ceil(HP1*0.83);
        EXP1=ceil(EXP1*1.17);
        //-------------------
        if (HP1>666) HP1=666;
        if (HP1<0) HP1=0;
        if (EXP1>600) EXP1=600;
        if (EXP1<0) EXP1=0;
        if (M1<0) M1=0;
        if (M1>3000) M1=3000;
        //-------------------
        if (EXP1-floor(sqrt(EXP1))*floor(sqrt(EXP1))<=ceil(sqrt(EXP1))*ceil(sqrt(EXP1))-EXP1) P2=100;
        else P2=(((float)EXP1/(ceil(sqrt(EXP1))*ceil(sqrt(EXP1)))+80)/123.0)*100;
//con_duong_3
    int P[10]={32,47,28,79,100,50,22,83,64,11};
    if (E2>9) E2=((E2-E2%10)/10 + E2%10)%10;
    P3=P[E2];
//ket thuc
    if (P1==100&&P2==100&&P3==100) EXP1=ceil(EXP1*0.75);
    if (((P1+P2+P3)/3)<50) {
        HP1=ceil(HP1*0.85);
        EXP1=ceil(EXP1*1.15);}
    else {
        HP1=ceil(HP1*0.9);
        EXP1=ceil(EXP1*1.2);}
    if (EXP1>600) EXP1=600;
    return HP1+EXP1+M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (HP1<0) {HP1=0;}
    if (HP1>666) {HP1=666;}
    if (EXP1<0) {EXP1=0;}
    if (EXP1>600) {EXP1=600;}
    if (HP2<0) HP2=0;
    if (HP2>666) HP2=666;
    if (EXP2<0) EXP2=0;
    if (EXP2>600) EXP2=600;
    if (E3<0||E3>99) return -99;
    //------------------------
    int i,j,a[10][10],b,c=0,d=0;
    for (j=0;j<10;j++) {
        for (i=0;i<10;i++) {
            a[i][j]=(E3*j+2*i)*(i-j);
            if (a[i][j]>2*E3) c+=1;
            if (a[i][j]<-E3) d+=1;
        }
    }
    //------------------------
    c=(c-(c%10))/10+c%10;
    c=(c-(c%10))/10+c%10;
    d=(d-(d%10))/10+d%10;
    d=(d-(d%10))/10+d%10;
    b=a[c][d];
    //------------------------
    for (i=0;i<10;i++) {
        if (i!=c) {
            j=d-abs(c-i);
            if (0<=j&&j<=9) {
                if (b<a[i][j]) b=a[i][j];}
            j=d+abs(c-i);
            if (0<=j&&j<=9) {
                if (b<a[i][j]) b=a[i][j];}
        }
    }
    if (abs(a[c][d])>abs(b)) {
        EXP1=ceil(EXP1*0.88);
        EXP2=ceil(EXP2*0.88);
        HP1=ceil(HP1*0.9);
        HP2=ceil(HP2*0.9);
        return a[c][d];}
    else {
        EXP1=ceil(EXP1*1.12);
        EXP2=ceil(EXP2*1.12);
        HP1=ceil(HP1*1.1);
        HP2=ceil(HP2*1.1);
        if (HP1>666) HP1=666;
        if (EXP1>600) EXP1=600;
        if (HP2>666) HP2=666;
        if (EXP2>600) EXP2=600;
        return abs(b);}
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string se;
    int i,j,l;
    for (i=0;i<strlen(s);i++) {
        if (!(s[i]==33 || (35<=s[i]&&s[i]<=37) || (48<=s[i]&&s[i]<=57) || (64<=s[i]&&s[i]<=90) || (97<=s[i]&&s[i]<=122))) return i;
    }
    for (i=0;email[i]!='@';i++) {
        se += email[i];}
    l=i;
    if (strlen(s)<8) return -1;
    if (strlen(s)>20) return -2;
    for (i=0;i<strlen(s);i++) {
        if (se[0]==s[i]) {
            for (j=i+1;j<i+l;j++) {
                if (s[j]!=se[j-i]) j=i+l+1;}
            if (j==i+l) return -(300+i);}
    }
    for (i=0;i<strlen(s)-2;i++) {
        if (s[i]==s[i+1]&&s[i]==s[i+2]) return -(400+i);}
    for (i=0;i<strlen(s);i++) {
        if (s[i]==33 || 35==s[i] || s[i]==36 || s[i]==37 || s[i]==64) i=strlen(s)+1;}
    if (i==strlen(s)) return -5;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int i,j,a[num_pwds],b[num_pwds],c[num_pwds],x=0,y=0;
    for (j=0;j<num_pwds;j++) {
        a[j]=0;b[j]=0;c[j]=0;
        for (i=num_pwds-1;i>=0;i--) {
            if (strcmp(arr_pwds[j],arr_pwds[i])==0) {a[j]+=1;b[j]=i;}
        }
        c[j]=strlen(arr_pwds[j]);
    }
    for (j=1;j<num_pwds;j++) {
      if (a[0] < a[j]) {a[0]=a[j];b[0]=b[j];c[0]=c[j];}
      if (a[0]==a[j] && b[0]==b[j]) {a[0]=a[j];b[0]=b[j];c[0]=c[j];}
      if (a[0]==a[j] && b[0]!=b[j]) {
        if (c[0] < c[j]) {a[0]=a[j];b[0]=b[j];c[0]=c[j];}
      }
    }
    return b[0];
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
