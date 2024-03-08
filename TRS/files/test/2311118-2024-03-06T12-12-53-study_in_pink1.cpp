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


int roundNum(double n) {
    int intPart=(int)n;
    double decPart=n-intPart;
    if (decPart!=0.0) return intPart+1;
    else return intPart;
}
int limHP(int hp) {
    if (hp < 0) return 0;
    else if (hp > 666) return 666;
    return hp;
}
int limEXP(int exp) {
    if (exp < 0) return 0;
    else if (exp > 600) return 600;
    return exp;
}
int limM(int money) {
    if (money < 0) return 0;
    else if (money > 3000) return 3000;
    return money;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1<0||e1>99) return -99;
    else{
        if (e1>=0&&e1<4){
            switch(e1){
            case 0:
                exp2=limEXP(exp2+=29);
                break;
            case 1:
                exp2=limEXP(exp2+=45);
                break;
            case 2:
                exp2=limEXP(exp2+=75);
                break;
            case 3:
                exp2=limEXP(exp2+=149);
                break;
            }
            int D=e1*3+exp1*7;
            if (D%2==0) exp1=limEXP(roundNum(exp1+D/200.0));
            else exp1=limEXP(roundNum(exp1-D/100.0));
    }
        else {
            if (e1>=4&&e1<=19) exp2=limEXP(roundNum(exp2+e1/4.0+19));
            else if (e1>=20&&e1<=49) exp2=limEXP(roundNum(exp2+e1/9.0+21));
            else if (e1>=50&&e1<=65) exp2=limEXP(roundNum(exp2+e1/16.0+17));
            else if (e1>=66&&e1<=79){
                exp2=limEXP(roundNum(exp2+e1/4.0+19));
                if (exp2>200) exp2=limEXP(roundNum(exp2+e1/9.0+21));
            }
            else if (e1>=80&&e1<=99){
                exp2=limEXP(roundNum(exp2+e1/4.0+19));
                exp2=limEXP(roundNum(exp2+e1/9.0+21));
                if (exp2>400) {
                    exp2=limEXP(roundNum(exp2+e1/16.0+17));
                    exp2=limEXP(roundNum(exp2+exp2*0.15));
                }
            }
            exp1=limEXP(exp1-e1);
        }
        return exp1 + exp2;
        }
}

bool isPS(int n) {
    for (int i=1;i<=n;++i) {
        if (i*i==n) return true;
    }
    return false;
}
int nearestPS(int n) {
    if(isPS(n)) return n;
    else{
       int sonho=n-1;
    while (sonho>0) {
        if (isPS(sonho)) break;
        sonho--;
    }
    int solon=n+1;
    while (true) {
        if (isPS(solon)) break;
        solon++;
    }
    if (n-sonho<=solon-n) return sonho;
    else return solon;
    }
}
double road1(int n){
    double S=nearestPS(n);
    double P1;
    if (n>=S) P1=1;
    else P1=((n/S)+80)/123.0;
    return P1;
}
void sk1(int &HP1, int &M1){
    if (HP1<200) {
        HP1=limHP(roundNum(HP1+HP1*30.0/100));
        M1=limM(roundNum(M1-150));
    } else {
        HP1=limHP(roundNum(HP1+HP1*10.0/100));
        M1=limM(roundNum(M1-70));
    }
}
void sk2(int &M1, int &EXP1){
    if (EXP1<400) {
        M1=limM(M1-200);
        EXP1=limEXP(roundNum(EXP1+EXP1*13.0/100));
    } else {
        M1=limM(M1-120);
        EXP1=limEXP(roundNum(EXP1+EXP1*13.0/100));
    }
}
void sk3(int &M1, int &EXP1){
    if (EXP1<300) {
        M1=limM(M1-100);
        EXP1=limEXP(roundNum(EXP1-EXP1*10.0/100));
    } else {
        M1=limM(M1-120);
        EXP1=limEXP(roundNum(EXP1-EXP1*10.0/100));
    }
}
double road2(int &HP1, int &EXP1, int &M1, int E2){
    if (E2%2!=0){
        int preM1=M1;
        float halfM1=50.0/100*M1;
        while(M1>0){
            sk1(HP1,M1);
            if ((preM1-M1)>=halfM1) break;
            sk2 (M1,EXP1);
            if ((preM1-M1)>=halfM1) break;
            sk3 (M1, EXP1);
            if ((preM1-M1)>=halfM1) break;
            }
        }
    else {
        while(M1>0){
            sk1(HP1,M1);
            if (M1==0) break;
            sk2(M1,EXP1);
            if (M1==0) break;
            sk3(M1,EXP1);
            if (M1==0) break;
            break;
        }

    }
    HP1=limHP(roundNum(HP1-HP1*17.0/100));
    EXP1=limEXP(roundNum(EXP1+EXP1*17.0/100));
    double S=nearestPS(EXP1);
    double P2;
    if (EXP1>=S) P2=1;
    else P2=((EXP1/S)+80)/123.0;
    return P2;
}
double road3(int E2){
    double P3,P[] = {0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11};
    int i;
    if (E2<10) i=E2;
    else i=((E2/10)+(E2%10))%10;
    P3=P[i];
    return P3;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2<0||E2>99) return -99;
    else {
        double P1=road1(EXP1), P2=road2(HP1,EXP1,M1,E2), P3=road3(E2);
        if (P1+P2+P3==3) EXP1=limEXP(roundNum(EXP1-25.0/100*EXP1));
        else if ((P1+P2+P3)/3<0.5) {
            HP1=limHP(roundNum(HP1-15.0/100*HP1));
            EXP1=limEXP(roundNum(EXP1+15.0/100*EXP1));
        }
        else {
            HP1=limHP(roundNum(HP1-10.0/100*HP1));
            EXP1=limEXP(roundNum(EXP1+20.0/100*EXP1));
        }
        return HP1 + EXP1 + M1;
    }
}

int abs(int num) {
    return num >= 0 ? num : -num;
}
int sum2Digits(int num) {
    int sum=0;
    while (num>=10) {
        sum=0;
        while (num>0) {
            sum+=num%10;
            num/=10;
        }
        num=sum;
    }
    return sum;
}
struct pos {
    int x;
    int y;
};
int cheoLeft(int matrix[10][10], int row, int col) {
    int maxVal=0;
    while ((row>=0&&row<10)&&(col>=0&&col<10)) {
        maxVal = std::max(maxVal, matrix[row][col]);
        ++row;
        ++col;
    }
    while ((row>=0&&row<10)&&(col>=0&&col<10)){
        maxVal=std::max(maxVal, matrix[row][col]);
        --row;
        --col;
    }
    return maxVal;
}
int cheoRight(int matrix[10][10], int row, int col) {
    int maxVal=0;
    while ((row>=0&&row<10)&&(col>=0&&col<10)) {
        maxVal=std::max(maxVal, matrix[row][col]);
        ++row;
        --col;
    }
    while ((row>=0&&row<10)&&(col>=0&&col<10)) {
        maxVal=std::max(maxVal, matrix[row][col]);
        --row;
        ++col;
    }
    return maxVal;
}
void calcTaxiScores(int taxiMap[10][10], int E3) {
    for (int i=0;i<10;++i) {
        for (int j=0;j<10;++j) taxiMap[i][j]=((E3*j)+(i*2))*(i-j);
    }
}
void calcSWscores(int taxiMap[10][10],int SWmap[10][10]) {
    for (int j=0;j<10;++j) {
        for (int i=0;i<10;++i) SWmap[i][j]=abs(std::max(cheoLeft(taxiMap,i,j),cheoRight(taxiMap,i,j)));
    }
}
pos MeetingPoint(int taxiMap[10][10], int E3) {
    pos vitri;
    vitri.x=0;
    vitri.y=0;
    for (int j=0;j<10;++j) {
        for (int i=0;i<10;++i) {
            if (taxiMap[i][j]>E3*2) ++vitri.x;
            else if(taxiMap[i][j]<-E3) ++vitri.y;
        }
    }
    vitri.x=sum2Digits(vitri.x);
    vitri.y=sum2Digits(vitri.y);
    return vitri;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3<0||E3>99) return -99;
    else{
        int taxiMap[10][10] = {0};
        int SWmap[10][10] = {0};
        calcTaxiScores(taxiMap, E3);
        calcSWscores(taxiMap,SWmap);
        pos vitri=MeetingPoint(taxiMap,E3);
        if (abs(taxiMap[vitri.x][vitri.y])>SWmap[vitri.x][vitri.y]){
            HP1=limHP(roundNum(HP1-HP1*0.10));
            EXP1=limEXP(roundNum(EXP1-EXP1*0.12));
            HP2=limHP(roundNum(HP2-HP2*0.10));
            EXP2=limEXP(roundNum(EXP2-EXP2*0.12));
            return taxiMap[vitri.x][vitri.y];
        }
        else {
            HP1=limHP(roundNum(HP1+HP1*0.10));
            EXP1=limEXP(roundNum(EXP1+EXP1*0.12));
            HP2=limHP(roundNum(HP2+HP2*0.10));
            EXP2=limEXP(roundNum(EXP2+EXP2*0.12));
            return SWmap[vitri.x][vitri.y];
        }
    }
}


void cut(const char* email, char* se) {
    int i;
    for (i=0;email[i]!='\0';++i) {
        if (email[i]=='@') break;
        se[i]=email[i];
    }
    se[i]='\0';
}
int checkLength(const char* s){
    const int minLength=8, maxLength=20;
    int sLen=0;
    while (s[sLen]!='\0') sLen++;
    if (sLen<minLength) return -1;
    else if (sLen>maxLength) return -2;
    else return -99;
}
int checkContainsSE(const char* s, const char* email){
    int sLen=0,seLen=0;
    while (s[sLen]!='\0') sLen++;
    while (email[seLen]!='\0'&&email[seLen]!='@') seLen++;
    if (seLen<=sLen){
        char se[seLen];
        cut(email,se);
        for (int i=0;i<=sLen-seLen;++i){
            int j;
            for (j=0;j<seLen;++j) if (s[i+j]!=se[j]) break;
            if (j==seLen) return -(300+i);
        }
        return -99;
    }
    return -99;
}
int checkConsecutiveChar(const char* s){
    int sLen=0;
    while (s[sLen]!='\0') sLen++;
    for (int i=0;i<sLen-2;++i) if (s[i]==s[i+1]&&s[i]==s[i+2]) return -(400+i);
    return -99;
}
int checkContainsSpecChar(const char* s){
    for (int i=0;s[i]!='\0';++i) if (s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!') return -99;
    return -5;
}
int checkInvalidChar(const char* s){
    for (int i=0;s[i]!='\0';++i) {
        if (!((s[i]>='0'&&s[i]<='9')||
              (s[i]>='a'&&s[i]<='z')||
              (s[i]>='A'&&s[i]<='Z')||
              (s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!')))
            return i;
    }
    return -99;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    if (checkLength(s)==-99){
        if (checkContainsSE(s,email)==-99){
            if (checkConsecutiveChar(s)==-99){
                if (checkContainsSpecChar(s)==-99){
                    if (checkInvalidChar(s)==-99) return -10;
                    else return checkInvalidChar(s);
                }
                else return checkContainsSpecChar(s);
            }
            else return checkConsecutiveChar(s);
        }
        else return checkContainsSE(s,email);
    }
    else return checkLength(s);
}

int strLen(const char* str){
    int length = 0;
    while (str[length]!='\0') length++;
    return length;
}
int compareStr(const char* s1, const char* s2){
    int i=0,j=0;
    while ( s1[i]!='\0'&& s2[j]!='\0') {
        if (s1[i]!=s2[j]) return 0;
        ++i;
        ++j;
    }
    return (s1[i]=='\0'&&s2[j]=='\0');
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxLen = 0;
    int maxCount = 0;
    int maxIdx = -1;
    for (int i=0;i<num_pwds;++i) {
        int length = strLen(arr_pwds[i]);
        int counT=1;
        for (int j=i+1;j<num_pwds;++j) if (compareStr(arr_pwds[i], arr_pwds[j])) ++counT;
        if (counT>maxCount||(counT==maxCount&&length>maxLen)) {
            maxCount=counT;
            maxLen=length;
            maxIdx=i;
        }
    }
    return maxIdx;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
