#include "study_in_pink1.h"
using namespace std;
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

int checkEXP(int &a) {
    if (a<0) return 0;
    if (a>600) return 600;
    return a;
}

int checkHP(int &a) {
    if (a<0) return 0;
    if (a>666) return 666;
    return a;
}

int checkMoney(int &a) {
    if (a<0) return 0;
    if (a>3000) return 3000;
    return a;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    //4.1.2
    if (e1<0 || e1>99) return -99;
    int D=0;
    if (e1>=0 && e1<=3) {
        if (e1==0) {
            exp2+=29;
            exp2=checkEXP(exp2);
        }
        else if (e1==1) {
            exp2+=45;
            exp2=checkEXP(exp2);
        }
        else if (e1==2) {
            exp2+=75;
            exp2=checkEXP(exp2);
        }
        else {
            exp2+=149;
            exp2=checkEXP(exp2);
        }
        D=e1*3+exp1*7;
        if (D%2==0) {
            exp1=exp1+(1.0*D/200)+0.999;
            exp1=checkEXP(exp1);
        }
        else {
            exp1=(exp1-(1.0*D/100))+0.999;
            exp1=checkEXP(exp1);
        }
    }
    //4.1.2
    if (e1>=4 && e1<=99) {
        if (e1>=4 && e1<=19) {
            exp2+=(1.0*e1/4+19)+0.999;
            exp2=checkEXP(exp2);
        }
        else if (e1>=20 && e1<=49) {
            exp2+=(1.0*e1/9+21)+0.999;
            exp2=checkEXP(exp2);
        }
        else if (e1>=50 && e1<=65) {
            exp2+=(1.0*e1/16+17)+0.999;
            exp2=checkEXP(exp2);
        }
        else if (e1>=66 && e1<=79) {
            exp2+=(1.0*e1/4+19)+0.999;
            if (exp2>200) exp2+=(1.0*e1/9+21)+0.999;
            exp2=checkEXP(exp2);
        }
        else {
            exp2+=(1.0*e1/4+19)+0.999;
            exp2+=(1.0*e1/9+21)+0.999;
            exp2=checkEXP(exp2);
            if (exp2>400) {
                exp2+=(1.0*e1/16+17)+0.999;
                exp2=exp2*1.15+0.999;
                exp2=checkEXP(exp2);
            }
        }
        exp1-=e1;
        exp1=checkEXP(exp1);
    }
    return exp1 + exp2;
}

//begin Task2
bool isPrime(int a) {
    int temp=sqrt(a);
    return (temp*temp==a);
}

int PrimeNumber(int a) {
    int S=0;
    if (isPrime(a)) return a;
    int b=sqrt(a);
    int c=b*b;
    int d=(b+1)*(b+1);
    int d1=abs(c-a);
    int d2=abs(d-a);
    int find=min(d1,d2);
    if (find==d1) S=c;
    else S=d;
    return S;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2<0 || E2>99) return -99;
    // 4.2.1
    double P1,P2=0,P3=0;
    int S1,S2,S3=0;
    S1=PrimeNumber(EXP1);
    if (EXP1>=S1) {
        P1=1;
    }
    else {
    P1=(1.0*EXP1/S1+80)/123;
    }

    // 4.2.2
    int half=(M1*0.5)+0.999;
    if (E2%2==0) {
            if (HP1<200 && M1>0) {
                HP1=HP1*1.3+0.999;
                M1-=150;
                HP1=checkHP(HP1);
                M1=checkMoney(M1);
                
            }
            else {
                if (M1>0) {
                HP1=(HP1*1.1)+0.999;
                M1-=70;
                HP1=checkHP(HP1);
                M1=checkMoney(M1);
                }
            }
            if (EXP1<400 && M1>0) {
                M1-=200;
                M1=checkMoney(M1);
                EXP1=(EXP1*1.13)+0.999;
                EXP1=checkEXP(EXP1);
            }
            else {
                if (M1>0) {
                M1-=120;
                M1=checkMoney(M1);
                EXP1=(EXP1*1.13)+0.999;
                EXP1=checkEXP(EXP1);
                }
            }
            if (EXP1<300 && M1>0) {
                M1-=100;
                M1=checkMoney(M1);
                EXP1=(EXP1*0.9)+0.999;
                EXP1=checkEXP(EXP1);
            }
            else {
                if (M1>0) {
                M1-=120;
                M1=checkMoney(M1);
                EXP1=(EXP1*0.9+0.999);
                EXP1=checkEXP(EXP1);
                }
            }
                HP1=(HP1*0.83)+0.999;
                HP1=checkHP(HP1);
                EXP1=(EXP1*1.17)+0.999;
                EXP1=checkEXP(EXP1);
    }
    else {
        int money=0;
        while (money<half) {
            if (HP1<200) {
                HP1=(HP1*1.3)+0.999;
                M1-=150;
                HP1=checkHP(HP1);
                M1=checkMoney(M1);
                money+=150;
            }
            else {
                HP1=(HP1*1.1)+0.999;
                M1-=70;
                HP1=checkHP(HP1);
                M1=checkMoney(M1);
                money+=70;
            }
            if (money>half) break;
            if (EXP1<400) {
                M1-=200;
                M1=checkMoney(M1);
                money+=200;
            }
            else {
                M1-=120;
                M1=checkMoney(M1);
                money+=120;
            }
            EXP1=(EXP1*1.13)+0.999;
            EXP1=checkEXP(EXP1);
            if (money>half) break;
            if (EXP1<300) {
                M1-=100;
                M1=checkMoney(M1);
                money+=100;
            }
            else {
                M1-=120;
                M1=checkMoney(M1);
                money+=120;
            }
            EXP1=(EXP1*0.9)+0.999;
            EXP1=checkEXP(EXP1);
            if (money>half) break;  
        }
        HP1=(HP1*0.83)+0.999;
        HP1=checkHP(HP1);
        EXP1=(EXP1*1.17)+0.999;
        EXP1=checkEXP(EXP1);
      
    }
    S2=PrimeNumber(EXP1);
    if (EXP1>=S2) P2=1;
    else P2=((1.0*EXP1/S2)+80)/123;
    //4.2.3
    int tong=0;
    double P[10]={0.32,0.47,0.28,0.59,1,0.5,0.22,0.83,0.64,0.11};
    if (E2<10) P3=P[E2];
    else  {
        tong=E2%10+E2/10;
        P3=P[tong%10];
    }
    if (P1==1 && P2==1 && P3==1) {
        EXP1=(EXP1*0.75)+0.999;
        EXP1=checkEXP(EXP1);
    }
    else {
        double aveP=(P1+P2+P3)/3;
        if (aveP<0.5) {
            HP1=(HP1*0.85)+0.999;
            HP1=checkHP(HP1);
            EXP1=(EXP1*1.15)+0.999;
            EXP1=checkEXP(EXP1);
        }
        else  {
            HP1=(HP1*0.9)+0.999;
            EXP1=(EXP1*1.2)+0.999;
            HP1=checkHP(HP1);
            EXP1=checkEXP(EXP1);
        }
    }
    return HP1+EXP1+M1;
}

// begin Task 3
int mapTaxi[10][10] = {0};
int mapSW1[10][10] = {0};
int mapSW2[10][10] = {0};

void TaxiValue(int mapTaxi[10][10], int E3) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            mapTaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
}

int Point_i(int mapTaxi[10][10],int E3) {
    int count=0;
    int point=0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if(mapTaxi[i][j]>0 && mapTaxi[i][j]>(E3*2)) count++;
        }
    }
    if (count>9) point=count/10+count%10;
    else point=count;
    if (point>9) point=point/10+point%10;
    return point;
}

int Point_j(int mapTaxi[10][10],int E3) {
    int count=0;
    int point=0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if(mapTaxi[i][j]<0 && mapTaxi[i][j]<(-E3)) count++;
        }
    }
    if (count>9) point=count/10+count%10;
    else point=count;
    if (point>9) point=point/10+point%10;
    return point;
}

void TravelLeftDiagonal(int mapTaxi[10][10],int mapSW1[10][10]) {
    int Max1=0,Max2=0;
    for (int i=0; i<10; i++) {
        int row=0;
        int col=i;
        int Maxtren=-1e9,Maxduoi=-1e9;
        while (row<10 && col<10) {
            Max1=max(mapTaxi[row][col],Maxtren);
            Max2=max(mapTaxi[col][row],Maxduoi);
            mapSW1[row][col]=Max1;
            mapSW1[col][row]=Max2;
            Maxtren=mapSW1[row][col];
            Maxduoi=mapSW1[col][row];
            int temp1=row;
            int temp2=col;
            while(temp1>0 && temp2>0) {
                if (mapSW1[temp1-1][temp2-1]<Max1) mapSW1[temp1-1][temp2-1]=Max1;
                if (mapSW1[temp2-1][temp1-1]<Max2) mapSW1[temp2-1][temp1-1]=Max2;
                temp1--;
                temp2--;
            }
            row++;
            col++;
        }
    }
}


void TravelRightDiagonal(int mapTaxi[10][10],int mapSW2[10][10]) {
    int Max1 = -1e9, Max2 = -1e9, Max3 = -1e9, Max4 = -1e9, Max5 = -1e9, Max6 = -1e9, Max7 = -1e9, Max8 = -1e9, Max9 = -1e9, Max10 = -1e9, Max11 = -1e9, Max12 = -1e9, Max13 = -1e9, Max14 = -1e9, Max15 = -1e9, Max16 = -1e9;
    int Max17=-1e9;
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (i+j==9) Max1=max(mapTaxi[i][j],Max1);
            if (i+j==8) Max2=max(mapTaxi[i][j],Max2);
            if (i+j==7) Max3=max(mapTaxi[i][j],Max3);
            if (i+j==6) Max4=max(mapTaxi[i][j],Max4);
            if (i+j==5) Max5=max(mapTaxi[i][j],Max5);
            if (i+j==4) Max6=max(mapTaxi[i][j],Max6);
            if (i+j==3) Max7=max(mapTaxi[i][j],Max7);
            if (i+j==2) Max8=max(mapTaxi[i][j],Max8);
            if (i+j==1) Max9=max(mapTaxi[i][j],Max9);
            if (i+j==10) Max10=max(mapTaxi[i][j],Max10);
            if (i+j==11) Max11=max(mapTaxi[i][j],Max11);
            if (i+j==12) Max12=max(mapTaxi[i][j],Max12);
            if (i+j==13) Max13=max(mapTaxi[i][j],Max13);
            if (i+j==14) Max14=max(mapTaxi[i][j],Max14);
            if (i+j==15) Max15=max(mapTaxi[i][j],Max15);
            if (i+j==16) Max16=max(mapTaxi[i][j],Max16);
            if (i+j==17) Max17=max(mapTaxi[i][j],Max17);
        }
    }
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (i+j==9) mapSW2[i][j]=Max1;
            if (i+j==8) mapSW2[i][j]=Max2;
            if (i+j==7) mapSW2[i][j]=Max3;
            if (i+j==6) mapSW2[i][j]=Max4;
            if (i+j==5) mapSW2[i][j]=Max5;
            if (i+j==4) mapSW2[i][j]=Max6;
            if (i+j==3) mapSW2[i][j]=Max7;
            if (i+j==2) mapSW2[i][j]=Max8;
            if (i+j==1) mapSW2[i][j]=Max9;
            if (i+j==10) mapSW2[i][j]=Max10;
            if (i+j==11) mapSW2[i][j]=Max11;
            if (i+j==12) mapSW2[i][j]=Max12;
            if (i+j==13) mapSW2[i][j]=Max13;
            if (i+j==14) mapSW2[i][j]=Max14;
            if (i+j==15) mapSW2[i][j]=Max15;
            if (i+j==16) mapSW2[i][j]=Max16;
            if (i+j==17) mapSW2[i][j]=Max17;
        }
    }
}

//Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3<0 || E3>99) return -99;
    TaxiValue(mapTaxi,E3);
    TravelLeftDiagonal(mapTaxi,mapSW1);
    TravelRightDiagonal(mapTaxi,mapSW2);
    int i=Point_i(mapTaxi,E3);
    int j=Point_j(mapTaxi,E3);
    int SW_score=max(mapSW1[i-1][j-1],mapSW2[i-1][j+1]);
    // Calculate mapSW
    if (abs(mapTaxi[i][j])>SW_score) {
        EXP1=(EXP1*0.88)+0.999;
        EXP1=checkEXP(EXP1);
        HP1 =(HP1*0.9)+0.999;
        HP1=checkHP(HP1);
        EXP2 = (EXP2*0.88)+0.999;
        EXP2 = checkEXP(EXP2);
        HP2 =(HP2*0.9)+0.999;
        HP2=checkHP(HP2);
    }
    else {
        EXP1=(EXP1*1.12)+0.999;
        EXP1=checkEXP(EXP1);
        HP1=(HP1*1.1)+0.999;
        HP1=checkHP(HP1);
        EXP2=(EXP2*1.12)+0.999;
        EXP2 = checkEXP(EXP2);
        HP2=(HP2*1.1)+0.999;
        HP2=checkHP(HP2);
    }
    if (E3==0) return 0;
    if (abs(mapTaxi[i][j])>SW_score) return mapTaxi[i][j];
    else return SW_score;
    
}

//begin TASK 4
bool checkCharacter (const char* s) {
    int count=0;
    for (int i=0; i<strlen(s)-1; i++) {
        if (s[i]==s[i+1] && s[i]==s[i+2]) count++;
        if (count>0) break;
    }
    return count>0;
}

bool checkSpecialCharacter(const char* s) {
    int count=0;
    for (int i=0; i<strlen(s); i++) {
        if (s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!') count++;
    }
    return count>0;
}

int checkFormPass(const char* s) {
    for (int i=0; i<strlen(s); i++) {
        if (!isalpha(s[i]) && !isdigit(s[i]) && s[i]!='%' && s[i]!='$' && s[i]!='@' && s[i]!='!' && s[i]!='#') return i;
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    char se[100];
    int length=strlen(s);
    if (length<8) return -1;
    if (length>20) return -2;
    //TH3
    // FIND SE
    const char* findse = strchr(email, '@');
    int pos=findse-email;
    strncpy(se,email,pos);
    se[pos]='\0';
    //find position of se in s
    const char* find_pos=strstr(s,se);
    int pos_se=find_pos-s;
    //TH3
    if (strstr(s,se)) return -300-pos_se;
    //TH4
    if (checkCharacter(s)) {
        for (int i=0; i<strlen(s)-2; i++) {
            if (s[i]==s[i+1] && s[i]==s[i+2]) return -400-i;
        }  
    }
    //TH5
    if (!checkSpecialCharacter(s)) return -5;
    //TH6
    if (checkFormPass(s)!=-1) {
        return checkFormPass(s);
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string arr[num_pwds];
    for (int i=0; i<num_pwds; i++) {
        arr[i]=arr_pwds[i];
    }
    int index=0,max_length=0,max_frequency=0;
    for (int i=0; i<num_pwds; i++) {
        int frequency=1,length=arr[i].length();
        for (int j=i+1; j<num_pwds; j++) {
            if (arr[i]==arr[j]) frequency++;
        }
        if (frequency>max_frequency ) {
            max_frequency=frequency;
            max_length=length;
            index=i;
        }
        if (max_frequency==frequency && length>max_length) {
            max_frequency=frequency;
            max_length=length;
            index=i;
        }
    }
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////