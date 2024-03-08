#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

void checkexp(int& exp) {
    if (exp < 0)exp = 0;
    if (exp > 600)exp = 600;
}
void checkhp(int& hp) {
    if (hp < 0)hp = 0;
    if (hp > 666)hp = 666;
}
void checkm(int& m) {
    if (m < 0)m = 0;
    if (m > 3000)m = 3000;
}
void checke(int& e) {
    if (e < 0 or e > 99)e = -100;
}
// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    double a=e1,z=exp2;
    checke(e1);
    checkexp(exp1);
    checkexp(exp2);
    if (e1 == -100)return -99; 
    //th1
    else if (e1 >= 0 and e1 <= 3) {
        if (e1 == 0)exp2 += 29;
        else if (e1 == 1)exp2 += 45;
        else if (e1 == 2)exp2 += 75;
        else if (e1 == 3)exp2 += (75 + 45 + 29);
        double d = e1 * 3 + exp1 * 7,j=exp1;
        int e=d;
        if (e % 2 == 0)j = ceil(j + d/ 200);
        else if (e % 2 == 1)j = ceil(j - d / 100);
        if(j!=exp1)exp1=j;
        checkexp(exp1);
    }
    //th2
    else if (e1 >= 4 and e1 <= 99) {
        if (e1 >=4 and e1 <= 19)z += ceil(a / 4 + 19);
        else if (e1 >= 20 and e1 < 50)z += ceil(a / 9) + 21;
        else if (e1 >= 50 and e1 <= 65)z += ceil(a / 16 + 17);
        else if (e1 >= 66 and e1 < 80) {
            z += ceil(a / 4 + 19);
            if (z > 200)z += ceil(a / 9) + 21;
        }
        else if (e1 >= 80 and e1 < 100) {
            z += ceil(a / 4 + 19) + ceil(a / 9 + 21);
            if (z > 400){
            z += ceil(a / 16 + 17);
            z += ceil(z * 15 / 100);
            }
            if (z > 600)z = 600;
        }
        if(exp2!=z)exp2=z;
        checkexp(exp1);checkexp(exp2);
        exp1 -= e1;
    } 
    checkexp(exp1);checkexp(exp2);
    return exp1 + exp2;
}

// Task 2

void tongso(int &a) {
    a = a % 10 + (a - (a % 10)) / 10;
}
bool stn(int a) {
    int i = 0;
    while (i * i <= a) {
        if (i * i == a) {
            return true;
        }
        i++;
    }
    return false;
}
void dg2a(int& HP1, int& EXP1, int& M1) {
    //dg 2
    if (HP1 < 200) {
        HP1 = ceil(HP1 * 130.0/100);
        M1 -= 150;
        checkhp(HP1);checkm(M1);
    }
    else {
        HP1 = ceil( HP1 * 110.0/100);
        M1 -= 70;
        checkhp(HP1);checkm(M1);
    }
}
void dg2b(int& HP1, int& EXP1, int& M1) {
    //dg 2  
    if (EXP1 < 400)M1 -= 200;
    else M1 -= 120;
    EXP1 = ceil(EXP1 * 113.0/100);
    checkexp(EXP1);checkm(M1);
}
void dg2c(int& HP1, int& EXP1, int& M1) {
    //dg 2
    if (EXP1 < 300)M1 -= 100;
    else M1 -= 120;
    EXP1 = ceil(EXP1 * 90.0/100);
    checkexp(EXP1);checkm(M1);
}
void TP(double& P, int E, int EXP1){
    int s = round(sqrt(EXP1))*round(sqrt(EXP1));
    if(EXP1>=s)P=1;
    else P=(EXP1 / s + 80.0) / 123;
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    //Dg 1
    double P1,P2,P3,Pt;
    checkhp(HP1);
    checkexp(EXP1);
    checkm(M1);
    checke(E2);
    if(E2 == -100) return-99;
    TP(P1,E2,EXP1);
    //dg 2
    if (E2 % 2 == 1) {
        double a=M1;
        while (a - float(M1) < a / 2) {
            dg2a(HP1, EXP1, M1); if (a - float(M1) > a / 2)break;
            dg2b(HP1, EXP1, M1); if (a - float(M1) > a / 2)break;
            dg2c(HP1, EXP1, M1); if (a - float(M1) > a / 2)break;
        }
    }
    else {
        dg2a(HP1, EXP1, M1); checkm(M1); checkhp(HP1); checkexp(EXP1);
        if (M1 == 0)goto nhaydong;
        dg2b(HP1, EXP1, M1); checkm(M1); checkhp(HP1); checkexp(EXP1);
        if (M1 == 0)goto nhaydong;
        dg2c(HP1, EXP1, M1); checkm(M1); checkhp(HP1); checkexp(EXP1);      
    }
    nhaydong:
    HP1 = ceil(HP1 * 83.0/100); checkhp(HP1);
    EXP1 = ceil(EXP1 * 117.0/100);checkexp(EXP1);
    checkm(M1);
    TP(P2,E2,EXP1);
    //dg3
    double A[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};int i;
    if(E2<10)i=E2;
    else i = (E2/10 + E2%10)%10;
    P3=A[i]*1.0/100;
    //sau dg
    if(P1==1 and P2==1 and P3==1){
        EXP1=ceil(EXP1*75.0/100);
    }else{
        Pt=(P1+P2+P3)/3;
        if(Pt<50.0/100){
            HP1=ceil(HP1*85.0/100);
            EXP1=ceil(EXP1*115.0/100);
        }else{
            HP1=ceil(HP1*90.0/100);  
            EXP1=ceil(EXP1*120.0/100);
        }
    }
    checkhp(HP1);checkexp(EXP1);
    return HP1+EXP1+M1;
}

// Task 3

int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    checkexp(EXP1); checkexp(EXP2);
    checkhp(HP1); checkhp(HP2);
    checke(E3); if (E3 == -100)return -99;
    int matrix[10][10];
    int dg=0, am=0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (matrix[i][j] > E3 * 2)dg ++;
            if (matrix[i][j] < -E3)am ++;
        }
    }
    while(dg>=10)tongso(dg);
    while(am>=10)tongso(am);
    int max=0,l=dg,d=am;
    while ( l < 10 and d >= 0) {
        if (matrix[l][d]> max){max = matrix[l] [d];}
        l++;
        d--;
    }
    l=dg,d=am;
    while (l < 10 and d<10) {
        if (matrix[l] [d]> max){max = matrix[l] [d];}
        l ++;
        d ++;
    }
    l=dg,d=am;
    while (l >= 0 and d< 10) {
        if (matrix[l][d]> max){max = matrix[l] [d];}
        l--;
        d++;
    }
    l=dg,d=am;
    while (l >= 0 and d >= 0) {
        if (matrix[l] [d] > max){max = matrix[l] [d];}
        l --;
        d --;
    }
    
    if(abs(matrix[dg] [am]) <= max) {
        EXP1 = ceil(EXP1 * 112.0/100);
        EXP2 = ceil(EXP2 * 112.0/100);
        HP1 = ceil(HP1 * 110.0/100);
        HP2 = ceil(HP2 * 110.0/100);
        checkexp(EXP1); checkexp(EXP2);
        checkhp(HP1); checkhp(HP2);
        return max;
    }
    if(abs(matrix[dg] [am]) > max){
        EXP1 = ceil(EXP1 * 88.0/100);
        EXP2 = ceil(EXP2 * 88.0/100);
        HP1 = ceil(HP1 * 90.0/100);
        HP2 = ceil(HP2 * 90.0/100);
        checkexp(EXP1); checkexp(EXP2);
        checkhp(HP1); checkhp(HP2);
        return matrix[dg][am];
    }
    checkexp(EXP1); checkexp(EXP2);
    checkhp(HP1); checkhp(HP2);
    return max;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    string emai= string(email);
    int len = strlen(s),n=emai.find('@');
    const char* special_chars = "@#%$!";
    string se=emai.substr(0,n);
    string ss=string(s);


    if (len < 8) {
        return -1;
    }
    if (len > 20) {
        return -2;
    }
    int sev = ss.find(se);
    if (sev>=0) {
        return -(300 + sev); 
    }

    
    for (int i = 0; i < len - 2; ++i) {
        if (s[i] == s[i + 1] and s[i] == s[i + 2]) {
            return -(400 + i); 
        }
    }
    //ki tu dac biet
    bool has_special_char = false;
    for (int i = 0; i < len; ++i) {
        if (strchr(special_chars, s[i])) {
            has_special_char = true;
            break;
        }
    }
    if (!has_special_char) {
        return -5; 
    }
    //ki tu k dc
    for (int i=0;i<len;i++){
        if(s[i]!='@' and s[i]!='#' and s[i]!='%' and s[i]!='$' and s[i]!='!' and !(s[i]>='A' and s[i]<='Z') and !(s[i]>='a' and s[i]<='z') and !(s[i]>='0' and s[i]<='9')){
            return i;break;
        }
    }
    // Mật khẩu hợp lệ
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int dem = 0,maxl = 0,vt = 0;

    for (int i = 0; i < num_pwds; ++i) {
        const char* pwd = arr_pwds[i];
        int length = strlen(pwd);

        int count = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(pwd, arr_pwds[j]) == 0) {
                count++;
            }
        }

        if (count > dem or (count == dem and length > maxl)) {
            dem= count;
            maxl = length;
            vt = i;
        }
    }

    return vt;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////