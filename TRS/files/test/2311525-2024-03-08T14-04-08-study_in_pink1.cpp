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
void dieukienEXP(int & exp){
    if (exp<0) exp = 0;
    else if (exp>600) exp = 600;
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1<0 || e1>99) return -99;
    else if (e1==0){
        exp2 += 29;
        int D = e1*3 + exp1*7;
        if (D%2==0) exp1 += ceil(D/200.0);
        else exp1 -= floor(D/100.0);
    }
    else if (e1==1){
        exp2 += 45;
        int D = e1*3 + exp1*7;
        if (D%2==0) exp1 += ceil(D/200.0);
        else exp1 -= floor(D/100.0);
    }
    else if (e1==2){
        exp2 += 75;
        int D = e1*3 + exp1*7;
        if (D%2==0) exp1 += ceil(D/200.0);
        else exp1 -= floor(D/100.0);
    }
    else if (e1==3){
        exp2 += 149;
        int D = e1*3 + exp1*7;
        if (D%2==0) exp1 += ceil(D/200.0);
        else exp1 -= floor(D/100.0);
    }
    else{
        if (e1>=4 && e1<=19) exp2 += 19+ceil(e1/4.0);
        if (e1>=20 && e1<=49) exp2 += 21+ceil(e1/9.0);
        if (e1>=50 && e1<=65) exp2 += 17+ceil(e1/16.0);
        if (e1>=66 && e1<=79){
            exp2 += 19+ceil(e1/4.0);
            dieukienEXP(exp2);
            if (exp2>200) exp2 += 21+ceil(e1/9.0);
        }
        if (e1>=80 && e1<=99){
            exp2 += 19+ceil(e1/4.0);
            dieukienEXP(exp2);
            exp2 += 21+ceil(e1/9.0);
            dieukienEXP(exp2);
            if (exp2>400){
                exp2 += 17+ceil(e1/16.0);
                dieukienEXP(exp2);
                exp2 = ceil(exp2*1.15);
            }
        }
        exp1 -= e1;
    }
    dieukienEXP(exp1);
    dieukienEXP(exp2);
    return exp1+exp2;
}

// Task 2
void dieukienHP(int & hp){
    if (hp<0) hp = 0;
    else if (hp>666) hp = 666;
}
void dieukienM(int & m){
    if (m<0) m = 0;
    else if (m>3000) m = 3000;
}
void Str21(int & HP1, int & M1){
    if (HP1<200){
        HP1=(HP1*1.3+0.999);
        M1-=150;
        dieukienHP(HP1);
        dieukienM(M1);
    }
    else{
        HP1=(HP1*1.1+0.999);
        M1-=70;
        dieukienHP(HP1);
        dieukienM(M1);
    }
}
void Str22(int & EXP1, int & M1){
    if (EXP1<400) M1-=200;
    else M1-=120;
    EXP1=(EXP1*1.13+0.999);
    dieukienM(M1);
    dieukienEXP(EXP1);
}
void Str23(int & EXP1, int & M1){
    if (EXP1<300) M1-=100;
    else M1-=120;
    EXP1=(EXP1*0.9+0.999);
    dieukienM(M1);
    dieukienEXP(EXP1);
}
double Str1(int & EXP1){
    double P1;
    int S;
    if ((int)(sqrt(EXP1))*(int)(sqrt(EXP1))==EXP1)
        S=EXP1;
    else if ((EXP1-(int)(sqrt(EXP1))*(int)(sqrt(EXP1)))<(((int)(sqrt(EXP1))+1)*((int)(sqrt(EXP1))+1)-EXP1))
        S=(int)(sqrt(EXP1))*(int)(sqrt(EXP1));
    else if ((EXP1-(int)(sqrt(EXP1))*(int)(sqrt(EXP1)))>(((int)(sqrt(EXP1))+1)*((int)(sqrt(EXP1))+1)-EXP1))
        S=((int)(sqrt(EXP1))+1)*((int)(sqrt(EXP1))+1);
    if (EXP1>=S) P1=1.00;
    else P1=((double)(EXP1/S)+80.00)/123.00;
    return P1;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2<0 || E2>99) return -99;
    double P1, P2, P3;
    P1=Str1(EXP1);
    int K=M1;
    if (E2%2!=0){
        if (M1!=0){
        while(0==0){
            Str21(HP1,M1);
            if (2*(K-M1)>K) break;
            Str22(EXP1,M1);
            if (2*(K-M1)>K) break;
            Str23(EXP1,M1);
            if (2*(K-M1)>K) break;
        }}
    }
    else{
        if (M1==0) goto cuoi;
        Str21(HP1,M1);
        if (M1==0) goto cuoi;
        Str22(EXP1,M1);
        if (M1==0) goto cuoi;
        Str23(EXP1,M1);
        if (M1==0) goto cuoi;
    }
    cuoi:{
        HP1=(HP1*0.83+0.999);
        EXP1=(EXP1*1.17+0.999);
    }
    dieukienEXP(EXP1);
    dieukienHP(HP1);
    dieukienM(M1);
    P2=Str1(EXP1);
    int P[10]={32,47,28,79,100,50,22,83,64,11};
    if (E2<10) P3=P[E2]/100.00;
    else P3=P[(E2%10+E2/10)%10]/100.00;
    double average=(P1+P2+P3)/3.00;
    if (average==1){
        EXP1=(EXP1*0.75+0.999);
        dieukienEXP(EXP1);
        dieukienHP(HP1);
        dieukienM(M1);
    }
    else{
        if (average<0.5){
            HP1=(HP1*0.85+0.999);
            EXP1=(EXP1*1.15+0.999);
            dieukienEXP(EXP1);
            dieukienHP(HP1);
            dieukienM(M1);
        }
        else{
            HP1=(HP1*0.9+0.999);
            EXP1=(EXP1*1.2+0.999);
            dieukienEXP(EXP1);
            dieukienHP(HP1);
            dieukienM(M1);
        }
    }
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int taxipoints[10][10];
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            taxipoints[i][j] = ((E3*j)+(i*2))*(i-j);
        }
    }
    int counti=0, countj=0;
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            if (taxipoints[i][j]>E3*2) counti++;
            if (taxipoints[i][j]<-E3) countj++;
        }
    }
    while (counti>=10){
        counti=counti/10+counti%10;
    }
    while (countj>=10){
        countj=countj/10+countj%10;
    }
    int max;
    for (int i=0;i<10;i++){
        if ((counti+i)<=9 && (countj+i)<=9){
            if (taxipoints[counti+i][countj+i]>max) max=taxipoints[counti+i][countj+i];
        }
        if ((counti-i)>=0 && (countj-i)>=0){
            if (taxipoints[counti-i][countj-i]>max) max=taxipoints[counti-i][countj-i];
        }
        if ((counti+i)<=9 && (countj-i)>=0){
            if (taxipoints[counti+i][countj-i]>max) max=taxipoints[counti+i][countj-i];
        }
        if ((counti-i)>=0 && (countj+i)<=9){
            if (taxipoints[counti-i][countj+i]>max) max=taxipoints[counti-i][countj+i];
        }
    }
    if (max<0) max=abs(max);
    if (abs(taxipoints[counti][countj])>max){
        EXP1=(0.999+0.88*EXP1);
        EXP2=(0.999+0.88*EXP2);
        HP1=(0.999+0.9*HP1);
        HP2=(0.999+0.9*HP2);
        dieukienEXP(EXP1);
        dieukienEXP(EXP2);
        dieukienHP(HP1);
        dieukienHP(HP2);
        return taxipoints[counti][countj];
    }
    else{
        EXP1=(0.999+1.12*EXP1);
        EXP2=(0.999+1.12*EXP2);
        HP1=(0.999+1.1*HP1);
        HP2=(0.999+1.1*HP2);
        dieukienEXP(EXP1);
        dieukienEXP(EXP2);
        dieukienHP(HP1);
        dieukienHP(HP2);
        return max;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    const char * semail = strchr(email,'@');
    size_t kytu = semail - email;
    char * se = new char[kytu+1];
    strncpy(se,email,kytu);
    se[kytu]='\0';
    if (strlen(s)<8) return -1;
    if (strlen(s)>20) return -2;
    for (int i = 0; i <= strlen(s)-1; i++) {
        bool kytutrungnhau = true;
        for (int j = 0; j < strlen(se); j++){
            if (s[i+j] != se[j]){
                kytutrungnhau = false;
                break;
            }
        }
        if (kytutrungnhau) return -(300+i);
    }
    for (int i = 0; i < strlen(s)-3; i++) {
        if (s[i]==s[i+1] && s[i+1]==s[i+2]) {
            return -(400+i);
            break;
        }
    }
    bool kytudacbiet = true;
    for (int i=0;i<=strlen(s)-1;i++){
        if (s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!') kytudacbiet=false;
    }
    if (kytudacbiet) return -5;
    for (int i=0;i<=strlen(s)-1;i++){
        if (!isalnum(s[i]) && (s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!'))
            return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int solanxuathiennhieunhat = 0;
    int pos = 0;
    for (int i = 0; i < num_pwds; i++) {
        int count = 0;
        bool matkhaulap = false;
        for (int j = 0; j < i; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                matkhaulap = true;
                break;
            }
        }
        if (!matkhaulap) {
            for (int k = i; k < num_pwds; k++) {
                if (strcmp(arr_pwds[i], arr_pwds[k]) == 0) {
                    count++;
                }
            }
            if (count > solanxuathiennhieunhat || (count == solanxuathiennhieunhat && strlen(arr_pwds[i]) > strlen(arr_pwds[pos]))) {
                solanxuathiennhieunhat = count;
                pos = i;
            }
        }
    }
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////