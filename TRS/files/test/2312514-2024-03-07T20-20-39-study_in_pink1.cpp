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
int checkHP(int n) {
if(n<0) n=0;
if(n>666) n=666;
return n;
}
int checkEXP(int & n) {
if(n<0) n=0;
if(n>600) n=600;
return int(n);
}
int checkEXP1(int & n) {
if(n<0) n=0;
if(n>600) n=600;
return int(n);
}
int checkM(int n) {
if(n<0) n=0;
if(n>3000) n=3000;
return n;
}
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
if(E1 < 0 && E1 >=100 ) return -99;
    else {
     if(E1<=3){
        int D=E1*3+EXP1*7;
        if(E1==0) {EXP2+=29; checkEXP1(EXP2);}
        if(E1==1) {EXP2+=45; checkEXP1(EXP2);}
        if(E1==2) {EXP2+=75; checkEXP1(EXP2);}
        if(E1==3) {EXP2+=149; checkEXP1(EXP2);}
        if(D%2==0) {EXP1=ceil(EXP1+(D*1.0/200));checkEXP1(EXP1);}
        if(D%2!=0) {EXP1=ceil(EXP1-(D*1.0/100));checkEXP1(EXP1);}
     }if(E1>3){
        if(E1>=4 && E1<=19) {
                EXP2=ceil(EXP2+(E1*1.0/4+19)); checkEXP1(EXP2);}
        if(E1>=20 && E1<=49) {
            EXP2=ceil(EXP2+(E1*1.0/9+21)); checkEXP1(EXP2);}
        if(E1>=50 && E1<=65) {
            EXP2=ceil(EXP2+(E1*1.0/16+17)); checkEXP1(EXP2);}
        if(E1>=66 && E1<=79) {
            EXP2=ceil(EXP2+(E1*1.0/4)+19);checkEXP1(EXP2);
            if(EXP2>200){EXP2=ceil(EXP2+(E1*1.0/9+21));}}
        if(E1>=80 && E1<=99) {
            EXP2=ceil(EXP2+(E1*1.0/4+19)); checkEXP1(EXP2); EXP2=ceil(EXP2+(E1*1.0/9)+21); checkEXP1(EXP2);
            if(EXP2>400){EXP2=ceil(EXP2+(E1*1.0/16)+17);checkEXP1(EXP2); EXP2=ceil(EXP2+(EXP2*1.0*15)/100);checkEXP1(EXP2);}
        }
        EXP1-=E1;
        checkEXP1(EXP1);
    }
    }
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    // con đường 1
    float a=sqrt(EXP1);// tìm số chính phương gần EXP1 nhất
    a=int(a);
    int A=a*a;
    int B=(a+1)*(a+1);
    int S;
    double P1;
    if (abs(A-EXP1) < abs(B-EXP1)) S=A;
    else S=B;
    if (EXP1>=S) P1=100;
    else P1=((float(EXP1)/S+80)/123)*100;
    //con đường 2
    int q=M1,n=0;
    if (E2%2!=0) {
    while (n<(q*0.5))
    {
    if(HP1<200 && M1>0 && n<(q*0.5)) {HP1=ceil(HP1*1.0*1.3);checkHP(HP1); M1=M1-150;checkM(M1);n=q-M1;}
    if(HP1>=200 && M1>0 && n<(q*0.5)) {HP1=ceil(HP1*1.0*1.1);checkHP(HP1); M1=M1-70;checkM(M1);n=q-M1;}
    if(EXP1<400 && M1>0 && n<(q*0.5)){
        M1-=200; checkM(M1);
        EXP1=ceil(EXP1*1.13);
        n=q-M1;
        checkEXP(EXP1);
        if(n<(q*0.5)){
        if(EXP1<300){
            M1-=100; checkM(M1);
        }
        if(EXP1>=300){
            M1-=120; checkM(M1);
        }
        EXP1=ceil(EXP1*0.9);
        checkEXP(EXP1);}
    }
    if(EXP1>=400 && M1>0 && n<(q*0.5)){
        M1-=120; checkM(M1);
        EXP1=ceil(EXP1*1.13);
        checkEXP(EXP1);
        n=q-M1;
        if(n<(q*0.5)){
        if(EXP1<300){
            M1-=100; checkM(M1);
        }
        if(EXP1>=300){
            M1-=120; checkM(M1);
        }
        EXP1=ceil(EXP1*0.9);
        checkEXP(EXP1);}
    }
    n=q-M1;
    }
    HP1=ceil(HP1-HP1*1.0*0.17);checkHP(HP1);
    EXP1=ceil(EXP1+0.17*EXP1);checkEXP(EXP1);
    }
    else
    {
    if(HP1<200 && M1>0 && n<(q*0.5)) {HP1=ceil(HP1*1.0*1.3);checkHP(HP1); M1=M1-150;checkM(M1);n=q-M1;}
    if(HP1>=200 && M1>0 && n<(q*0.5)) {HP1=ceil(HP1*1.0*1.1);checkHP(HP1); M1=M1-70;checkM(M1);n=q-M1;}
    if(EXP1<400 && M1>0 && n<(q*0.5)){
        M1-=200; checkM(M1);
        EXP1=ceil(EXP1*1.13);
        n=q-M1;
        checkEXP(EXP1);
        if(n<(q*0.5)){
        if(EXP1<300){
            M1-=100; checkM(M1);
        }
        if(EXP1>=300){
            M1-=120; checkM(M1);
        }
        EXP1=ceil(EXP1*0.9);
        checkEXP(EXP1);}
    }
    if(EXP1>=400 && M1>0 && n<(q*0.5)){
        M1-=120; checkM(M1);
        EXP1=ceil(EXP1*1.13);
        checkEXP(EXP1);
        n=q-M1;
        if(n<(q*0.5)){
        if(EXP1<300){
            M1-=100; checkM(M1);
        }
        if(EXP1>=300){
            M1-=120; checkM(M1);
        }
        EXP1=ceil(EXP1*0.9);
        checkEXP(EXP1);}
    }
    }
    a=sqrt(EXP1);// tìm số chính phương gần EXP1 nhất
    a=int(a);
    A=a*a;
    B=(a+1)*(a+1);
    double P2;
    if (abs(A-EXP1) < abs(B-EXP1)) S=A;
    else S=B;
    if (EXP1>=S) P2=100;
    else P2=((float(EXP1)/S+80)/123)*100;
    //con đường 3
    int P[]={32,47,28,79,100,50,22,83,64,11};
    int i;
    if (E2<10) i=E2;
    else {
        int sumDigits=(E2%10) + (E2/10);
        i=sumDigits%10;
    }
    float P3=P[i];
    //tổng kết
    if (P1==100&&P2==100&&P3==100) {EXP1=ceil(EXP1-0.25*EXP1);}
    else
    {
        float ave=(P1+P2+P3)/3;
        if (ave<50) {HP1=ceil(HP1-HP1*1.0*0.15);EXP1=ceil(EXP1+0.15*EXP1);}
        else {HP1=ceil(HP1-HP1*1.0*0.1);EXP1=ceil(EXP1+0.2*EXP1);}

    }
checkEXP(EXP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int sum(int n){
    if(n < 10)  return n;
    int s=0;
    while(n>0){
        s+=n%10;
        n/=10;
        if(s==10) {n=s;s=0;}
    }
    return s;
}
int scoreofSW(int mtran[10][10], int row, int col){
    int score=mtran[row][col];
    for(int i=row+1, j=col+1; i<10 && j<=0; ++i, ++j)
        score=max(score, mtran[i][j]);
    for(int i=row-1, j=col-1; i>=0 && j>=0; --i, --j)
        score=max(score, mtran[i][j]);
    for(int i=row+1, j=col-1; i<10 && j>=0; ++i, --j)
        score=max(score, mtran[i][j]);
    for(int i=row-1, j=col+1; i>=0 && j<10; --i, ++j)
        score=max(score, mtran[i][j]);
    return score;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
const int A=10,B=10;
int mtran[A][B],a=0,b=0;
if(E3<0 || E3>99) return -99;
for(int i=0; i<10; i++){
        for(int j=0; j<10; j++) {
            mtran[i][j] = ((E3*j)+(i*2))*(i-j);
            if(mtran[i][j]>=E3*2) a+=1;
            else if(mtran[i][j]<(-E3)) b+=1;
        }
}

a=sum(a);
b=sum(b);
int taxi=mtran[a][b], sumofscore=scoreofSW(mtran,a,b);
if(abs(sumofscore)>=abs(taxi)) {
    EXP1*=1.12;checkEXP1(EXP1);EXP2*=1.12;checkEXP1(EXP2);
    HP1*=1.1;checkHP(HP1);HP2*=1.1;checkHP(HP2);
}
else {EXP1*=0.88;checkEXP1(EXP1);EXP2*=0.88;checkEXP1(EXP2);
    HP1*=0.9;checkHP(HP1);HP2*=0.9;checkHP(HP2);}
    return taxi;
}

// Task 4
int checkPassword(const char * s, const char * email){
    // TODO: Complete this function

string nameemail,ne;
nameemail=string(email);
for (char i:nameemail)
   {

    if (i=='@') break;
ne+=i;}
//string se(email);
//se=se.substr(0,se.find('@'));


string str(s);
int n=str.length();
const int MIN_LENGTH = 8;
const int MAX_LENGTH = 20;
if (n< MIN_LENGTH) return -1;
if (n> MAX_LENGTH) return -2;

for (int i=0;i<n-2;++i)
    if (str[i]==str[i+1]&&str[i+1]==str[i+2]) return -(400+i);
    
int position=str.find(ne);
if (position != string::npos) return -(300 + position);



string specialChar="@#%$!";
bool specialCharacter=false;
for (char c:specialChar)
    if (specialChar.find(c)!=string::npos) { return true; break;}

    if (!specialCharacter) return -5;

    for (int i=0;i<n;++i)
    { char c=str[i];
        if ((0<=c && c<=9)|| ('a'<=c && c<='z')|| ('A'<=c && c<='Z' )
                        || ((specialChar.find(c)) != string::npos ))
            continue;
        return i;
    }

    return -10;
}



// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int f=0,v=0,D=0;
    for(int i=0;i<num_pwds;i++){
        string pass=arr_pwds[i];
        int fre=0;
        int d=pass.length();
        for(int j=0;j<num_pwds;j++){
            if(strcmp(arr_pwds[i],arr_pwds[j])==0) fre++;
            if(fre>f || (fre==f && d>D)){
                f=fre;
                D=d;
                v=i;
            }
        }
    }
    return v;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////