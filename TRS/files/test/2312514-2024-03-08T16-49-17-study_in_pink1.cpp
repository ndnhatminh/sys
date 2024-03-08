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
int checkHP(int & n) {
if(n<0) n=0;
if(n>666) n=666;
return n;
}
int checkEXP(int & n) {
if(n<0) n=0;
if(n>600) n=600;
return n;
}
int checkEXP1(int & n) {
if(n<0) n=0;
if(n>600) n=600;
return int(n);
}
int checkM(int & n) {
if(n<0) n=0;
if(n>3000) n=3000;
return n;
}
int findsquarenumber(int n){
    float a=sqrt(n);// tìm số chính phương gần EXP1 nhất
    a=int(a);
    int A=a*a;
    int B=(a+1)*(a+1);
    int S;
    if (abs(A-n) < abs(B-n)) S=A;
    else S=B;
    return S;
}
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
if(E1 < 0 || E1 >=100 ) return -99;
    else {
     if(E1<=3){
        int D=E1*3+EXP1*7;
        if(E1==0) {EXP2+=29; checkEXP(EXP2);}
        if(E1==1) {EXP2+=45; checkEXP(EXP2);}
        if(E1==2) {EXP2+=75; checkEXP(EXP2);}
        if(E1==3) {EXP2+=149; checkEXP(EXP2);}
        if(D%2==0) {EXP1=ceil(EXP1+(D*1.0/200));checkEXP(EXP1);}
        if(D%2!=0) {EXP1=ceil(EXP1-(D*1.0/100));checkEXP(EXP1);}
     }if(E1>3){
        if(E1>=4 && E1<=19) {
                EXP2=ceil(EXP2+(E1*1.0/4+19)); checkEXP(EXP2);}
        if(E1>=20 && E1<=49) {
            EXP2=ceil(EXP2+(E1*1.0/9+21)); checkEXP(EXP2);}
        if(E1>=50 && E1<=65) {
            EXP2=ceil(EXP2+(E1*1.0/16+17)); checkEXP(EXP2);}
        if(E1>=66 && E1<=79) {
            EXP2=ceil(EXP2+(E1*1.0/4)+19);checkEXP(EXP2);
            if(EXP2>200){EXP2=ceil(EXP2+(E1*1.0/9+21));checkEXP(EXP2);}}
        if(E1>=80 && E1<=99) {
            EXP2=ceil(EXP2+(E1*1.0/4+19)); checkEXP(EXP2); EXP2=ceil(EXP2+(E1*1.0/9)+21); checkEXP(EXP2);
            if(EXP2>400){EXP2=ceil(EXP2+(E1*1.0/16)+17);checkEXP(EXP2); EXP2=ceil(EXP2+(EXP2*1.0*15)/100);checkEXP(EXP2);}
        }
        EXP1-=E1;
        checkEXP(EXP1);
    }
    }
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    // con đường 1
    checkEXP(EXP1);
    checkHP(HP1);
    checkM(M1);
    int S=findsquarenumber(EXP1);
    double P1;
    if (EXP1>=S) P1=100;
    else P1=((float(EXP1)/S+80)/123)*100;
    //con đường 2
    int h=M1,n=0;
    if (E2%2==1) {
    while (n<(h*1.0/2) && M1>0)
    {
    if(HP1<200 && M1>0 && n<(h*1.0/2)) {HP1+=ceil(HP1*30.0/100);checkHP(HP1); M1=M1-150;checkM(M1);n=h-M1;}
    if(HP1>=200 && M1>0 && n<(h*1.0/2)) {HP1+=ceil(HP1*10.0/100);checkHP(HP1); M1=M1-70;checkM(M1);n=h-M1;}
    if(EXP1<400 && M1>0 && n<(h*1.0/2)){
        M1-=200; checkM(M1);
        EXP1+=ceil(EXP1*13.0/100);
        n=h-M1;
        checkEXP(EXP1);
        if(n<(h*1.0/2) && M1>0){
        if(EXP1<300){
            M1-=100; checkM(M1);
        }
        if(EXP1>=300){
            M1-=120; checkM(M1);
        }
        EXP1=EXP1-floor(EXP1*1.0/10);
        checkEXP(EXP1);}
    }
    if(EXP1>=400 && M1>0 && n<(h*1.0/2)){
        M1-=120; checkM(M1);
        EXP1+=ceil(EXP1*13.0/100);
        checkEXP(EXP1);
        n=h-M1;
        if(n<(h*1.0/2) && M1>0){
        if(EXP1<300){
            M1-=100; checkM(M1);
        }
        if(EXP1>=300){
            M1-=120; checkM(M1);
        }
        EXP1=EXP1-floor(EXP1*1.0/10);
        checkEXP(EXP1);}
    }
    n=h-M1;
    }
    HP1=HP1-floor(HP1*17.0/100);checkHP(HP1);
    EXP1+=ceil(EXP1*17.0/100);checkEXP(EXP1);
    }
    if(E2%2==0)
    {
    if(HP1<200 && M1>0 && n<(h*1.0/2)) {HP1=ceil(HP1*30.0/100);checkHP(HP1); M1=M1-150;checkM(M1);n=h-M1;}
    if(HP1>=200 && M1>0 && n<(h*1.0/2)) {HP1=ceil(HP1*10.0/100);checkHP(HP1); M1=M1-70;checkM(M1);n=h-M1;}
    if(EXP1<400 && M1>0 && n<(h*1.0/2)){
        M1-=200; checkM(M1);
   EXP1+=ceil(EXP1*13.0/100);
        n=h-M1;
        checkEXP(EXP1);
        if(n<(h*0.5) && M1>0){
        if(EXP1<300){
            M1-=100; checkM(M1);
        }
        if(EXP1>=300){
            M1-=120; checkM(M1);
        }
        EXP1=EXP1-floor(EXP1*10.0/10);
        checkEXP(EXP1);}
    }
    if(EXP1>=400 && M1>0 && n<(h*1.0/2)){
        M1-=120; checkM(M1);
       EXP1+=ceil(EXP1*13.0/100);
        checkEXP(EXP1);
        n=h-M1;
        if(n<(h*1.0/2 && M1>0)){
        if(EXP1<300){
            M1-=100; checkM(M1);
        }
        if(EXP1>=300){
            M1-=120; checkM(M1);
        }
        EXP1=EXP1-floor(EXP1*1.0/10);
        checkEXP(EXP1);}
    }
    HP1=HP1-floor(HP1*17.0/100);checkHP(HP1);
    EXP1=EXP1+ceil(EXP1*17.0/100);checkEXP(EXP1);
    }
    int S1=findsquarenumber(EXP1);
    double P2;
    if (EXP1>=S1) P2=100;
    else P2=((EXP1*1.0/S1)+80)/123*100;
    //con đường 3
    int P[]={32,47,28,79,100,50,22,83,64,11};
    int i;
    double P3;
    if (E2<10 && E2>=0) P3=P[E2]*1.0;
    else {
        int sumDigits=0;
        sumDigits+=E2%10; 
        E2/=10;
        sumDigits+=E2%10;
        E2/=10;
        i=sumDigits%10;
         double P3=P[i]*1.0;
    }

    //tổng kết
    if (P1==100&&P2==100&&P3==100) {EXP1=EXP1-floor(EXP1*25.0/100);checkEXP(EXP1);}
    else
    {
        float ave=ceil((P1+P2+P3)/3);
        if (ave<50) {HP1=HP1-floor(HP1*15.0/100);checkHP(HP1);EXP1=ceil(EXP1+EXP1*15.0/100);checkEXP(EXP1);}
        else if(ave>=50 && ave<100) {HP1=HP1-floor(HP1*10.0/100);checkHP(HP1);EXP1=ceil(EXP1+EXP1*1.0/5);checkEXP(EXP1);}
    }
checkEXP(EXP1);
checkHP(HP1);
checkM(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int sum(int n){
    if(n < 10)  return n;
    int s=0;
    while(n>0){
        s+=n%10;
        n/=10;
    }
    return s;
}
int scoreofSW(int matran[10][10], int row, int col){
    int score=matran[row][col];
    for(int i=row+1, j=col+1; i<10 && j<=0; ++i, ++j)
        score=max(score, matran[i][j]);
    for(int i=row-1, j=col-1; i>=0 && j>=0; --i, --j)
        score=max(score, matran[i][j]);
    for(int i=row+1, j=col-1; i<10 && j>=0; ++i, --j)
        score=max(score, matran[i][j]);
    for(int i=row-1, j=col+1; i>=0 && j<10; --i, ++j)
        score=max(score, matran[i][j]);
    return score;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
const int A1=10,B1=10;
int matran[A1][B1],a=0,b=0,A=0,B=0;
if(E3<0 || E3>99) return -99;
for(int i=0; i<10; i++){
        for(int j=0; j<10; j++) {
            matran[i][j] = ((E3*j)+(i*2))*(i-j);
            if(matran[i][j]>=E3*2 && matran[i][j]>0) a+=1;
            else if(matran[i][j]<(-E3) && matran[i][j]<0) b+=1;
        }
}

A=sum(sum(a));
B=sum(sum(b));
int taxi=matran[A][B], sumofscore=abs(scoreofSW(matran,A,B)),X=0;
if(abs(sumofscore)>=abs(taxi)) {
    EXP1+=ceil(EXP1*12.0/100);checkEXP1(EXP1);
    EXP2+=ceil(EXP2*12.0/100);checkEXP1(EXP2);
    HP1+=ceil(HP1*10.0/100);checkHP(HP1);
    HP2+=ceil(HP2*10.0/100);checkHP(HP2);
    X=sumofscore;
}
else {EXP1=EXP1-floor(EXP1*12.0/100);checkEXP1(EXP1);
EXP2=EXP2-floor(EXP2*12.0/100);checkEXP1(EXP2);
    HP1=HP1-floor(HP1*10.0/100);checkHP(HP1);
    HP2=HP2-floor(HP2*10.0/100);checkHP(HP2);
    X=taxi;
    }
    return X;
}

// Task 4
int checkPassword(const char *s, const char *email) {
    string str(s);
    string nameemail(email);
    string specialChar = "@#%$!";

    int n = str.length();
    const int MIN_LENGTH = 8;
    const int MAX_LENGTH = 20;

    if (n < MIN_LENGTH) return -1;
    if (n > MAX_LENGTH) return -2;

    string name;
    for (char c : nameemail) {
        if (c == '@') {
            break;
        }
        name += c;
    }

    int position = str.find(name);
    if (position != string::npos) return -(300 + position);

    for (int i=0;i<n-2;++i)
    if (str[i]==str[i+1]&&str[i+1]==str[i+2]) return -(400+i);
    
    bool specialCharacter = false;
    for (char c : specialChar) {
        if (str.find(c) != string::npos) {
            specialCharacter = true;
            break;
        }
    }
    if (!specialCharacter) return -5;

    for (int i = 0; i < n; ++i) {
        char c = str[i];
        if (('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || (specialChar.find(c) != std::string::npos)) {
            continue;
        }
        return i;
    }

    return -10;
}



// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int fre=0,navi=0,Dai=0;
    for(int i=0;i<num_pwds;i++){
        string passw=arr_pwds[i];
        int frequen=0;
        int d=passw.length();
        for(int j=0;j<num_pwds;j++){
            if(strcmp(arr_pwds[i],arr_pwds[j])==0) frequen++;
            if(frequen>fre || (frequen==fre && d>Dai)){
                fre=frequen;
                Dai=d;
                navi=i;
            }
        }
    }
    return navi;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////