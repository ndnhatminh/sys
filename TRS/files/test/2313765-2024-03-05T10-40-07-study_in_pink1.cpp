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

int checkHP(int &HP1){
    if (HP1>666){
        HP1=666;
    }
    else if  (HP1<0){
        HP1=0;}
    return  HP1;
}
float ceil2(float n){
    n+=0.5;
    return round(n);
}
int checkEXP(int &EXP1){
    if (EXP1>600){
        EXP1=600;
    }
    else if (EXP1<0){
        EXP1=0;}
    return  EXP1;
}

int checkM(int &M1){
    if(M1>3000){
        M1=3000;
    }
    else if(M1<0){
        M1=0;
    }
    return M1;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    checkEXP(exp1);
    checkEXP(exp2);
    if (e1 >= 0 && e1 <= 3) {
        switch (e1) {
            case 0:
                exp2 += 29;
                break;
            case 1:
                exp2 += 45;
                break;
            case 2:
                exp2 += 75;
                break;
            case 3:
                exp2 += 29 + 45 + 75;
                break;
        }
        checkEXP(exp2);
        int D;
        D = e1 * 3 + exp1 * 7;
        cout<<D<<endl;
        if (D % 2 == 0) exp1 = ceil(exp1+D / 200);
        else exp1 = ceil(exp1-D / 100);
        cout<<exp1<<endl;
        checkEXP(exp1);
        return exp1 + exp2;

    } else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 = ceil2(exp2+e1 / 4 + 19);
            checkEXP(exp2);
        }
        if (e1 >= 20 && e1 <= 49) {
            exp2 = ceil2(exp2+e1 / 9 + 21);
            checkEXP(exp2);
        }
        if (e1 >= 50 && e1 <= 65) {
            exp2 = ceil2(exp2+e1 / 16 + 17);
            checkEXP(exp2);
        }
        if (e1 >= 66 && e1 <= 79) {
            exp2 = ceil2(exp2+e1 / 4 + 19);
            if (exp2 > 200) exp2 = ceil2(exp2+e1 / 9 + 21);
            checkEXP(exp2);
        }
        if (e1 >= 80 && e1 <= 99) {
            exp2 = ceil2(exp2+e1 / 4 + 19 + e1 / 9 + 21);
            if (exp2 > 400) exp2 = ceil2(exp2+e1 / 16 + 17);
            exp2 = ceil2(exp2 * 1.15);
            checkEXP(exp2);
        }
        exp1 =exp1- e1;
        checkEXP(exp1);
        checkEXP(exp2);
        return  exp2;
    } else return -99;
}
// Task 2
int findSquareNumber(int n){
    int a=n;
    int b=n;
    int S;
    while (!(sqrt(a) == trunc(sqrt(a)))){a++;}
    while (!(sqrt(b) == trunc(sqrt(b)))){b--;}
    if (abs(a-S) >abs(b-S)) S = b ;
    else S=a;
    return S;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
    double P1;
    int S=findSquareNumber(EXP1);
    if (EXP1>=S) P1=100;
    else P1=((double(EXP1/S) +80)/123)*100;
    int B=M1;

    if (E3%2!=0){
        while (M1>B/2)
        {
            if (HP1<200){

                HP1=ceil2(HP1*1.3);
                M1-=150;
            }
            else {
                HP1=ceil2(HP1*1.1);
                M1-=70;}
            if(M1<B/2) break;
            if (EXP1<400) M1-=200;
            else M1-=120;
            if(M1<B/2) break;
            EXP1=ceil2(EXP1*1.13);
            if (EXP1<300) M1-=100;
            else M1-=120;
            if(M1<B/2) break;
        }
        HP1=ceil2(HP1*0.83);
        EXP1=ceil2(EXP1*1.17);
    }
    else {
        while (M1>0){
            if (HP1<200){
                HP1=ceil2(HP1*1.3);
                M1-=150;
            }
            else {
                HP1=ceil2(HP1*1.1);
                M1-=70;}
            if (M1<=0) break;
            if (EXP1<400) M1-=200;
            else M1-=120;
            EXP1=ceil2(EXP1*1.13);
            if (M1<=0) break;
            if (EXP1<300) M1-=100;
            else M1-=120;
            break;
        }
        HP1=ceil2(HP1*0.83);
        EXP1=ceil2(EXP1*1.17);
    }
    double P2;
    P2=findSquareNumber(EXP1);
    if (EXP1>=S) P2=100;
    else P2=double((EXP1/S +80)/123);
    int P[10]={32,47,28,79,100,50,22,83,64,11};
    int i;
    if (E3<10&&E3>=0) i=E3;
    else {
        i=(E3/10+E3%10)%10;
    }
    double P3=P[i];
    if (P1==100&&P2==100&&P3==100) EXP1=ceil2(EXP1-EXP1*0.25);
    else
    {
        double Pt;
        Pt=(P1+P2+P3)/3;
        if (Pt<=50){
            HP1-=ceil2(HP1*0.15);
            EXP1=ceil2(EXP1*0.15);
        }
        else {
            HP1=ceil2(HP1*0.9);
            EXP1=ceil2(EXP1*1.2);

        }
    }
    HP1=checkHP(HP1);
    EXP1=checkEXP(EXP1);
    return HP1+EXP1+M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    int Mt[10][10];
    int a = 0, b = 0, t1 = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            Mt[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (Mt[i][j] > E3 * 2) a++;
            if (Mt[i][j] < -E3) b++;
        }
    }
    while (a >= 10) {
        a = a / 10 + a % 10;
    }
    int c=a;
    int e=a;
    int g=a;
    int o=a;
    while (b >= 10) {
        b = b / 10 + b % 10;
    }
    int d=b;
    int f=b;
    int h=b;
    int k=b;
    for (int i = a, j=b; i < 10&&j<10 ; i++ ,j++) {
        if (Mt[i][j] > t1) t1 = Mt[i][j];
    }
    for (int i = e,j=f; i > 0&&j>0; i--,j--) {
        if (Mt[i][j] > t1) t1 = Mt[i][j];
    }
    for (int i = g, j=h; i >0&&j<10 ; i-- ,j++) {
        if (Mt[i][j] > t1) t1 = Mt[i][j];
    }
    for (int i = o,j=k; i < 10&&j>0; i++,j--) {
        if (Mt[i][j] > t1) t1 = Mt[i][j];
    }
        if (t1 > abs(Mt[c][d])) {
            EXP1 =ceil2(EXP1* 1.12);
            EXP2 =ceil2(EXP2 *1.12);
            HP1 =ceil2(HP1 *1.1);
            HP2 =ceil2(HP2 *1.1);
            return t1;
        } else {
             EXP1 =ceil2(EXP1* 0.88);
            EXP2 =ceil2(EXP2 *0.88);
            HP1 =ceil2(HP1 *0.9);
            HP2 =ceil2(HP2 *0.9);
            return Mt[c][d];
        }
    }
// Task 4
int checkPassword(const char *s, const char *email) {
    string email_str(email);
    size_t at_pos = email_str.find('@');
    if (at_pos == string::npos) {
        return -1;
    }
    string se = email_str.substr(0, at_pos);

    size_t len = strlen(s);
    if (len < 8) {
        return -1;
    }
    if (len > 20) {
        return -2;
    }
    if (strstr(s, se.c_str()) != nullptr) {
        return -(300 + (int)(strstr(s, se.c_str()) - s));
    }
    for (size_t i = 0; i < len - 2; ++i) {
        if (s[i] == s[i + 1]&&s[i]==s[i+2]) {
            return -(400 + i);
        }
    }
    bool has_special = false;
    for (size_t i = 0; i < len; ++i) {
        if (!isalnum(s[i]) && strchr("@#%$!", s[i]) != nullptr) {
            has_special = true;
            break;
        }
    }
    if (!has_special) {
        return -5;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int Mt[30]={0};
    int max=0;
    int maxl=0;
    int count=0;

    for (int i=0;i<num_pwds;i++) {
        for (int j=1;j<num_pwds;j++){
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) Mt[i]++;
        }
    }
    for (int x=0;x<30;x++) {
        if (Mt[x]>max) {
            max=Mt[x];
            maxl=x;
        }
        else if (Mt[x] == max && strlen(arr_pwds[x]) > strlen(arr_pwds[maxl])) {
            maxl = x;
        }
    }
    
    return maxl;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////