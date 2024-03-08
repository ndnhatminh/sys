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

int HP(double hp){
    int HP=ceilf(hp); 
    if (HP<0){
        return 0;
    }else if (HP>666){
        return 666;
    }else{
        return HP;
    }
}
int EXP(double EXP){
    int exp=ceilf(EXP);
    if (exp<0){
        return 0;
    }else if (exp>600){
        return 600;
    }else {
        return exp;
    }
}
int m(int m){
    if (m<0){
        return 0;
    }else if (m>3000){
        return 3000;
    }else {
        return m;
    }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1<0 || e1>99){
        return -99;
    }
    exp1 = EXP(exp1);
    exp2 = EXP(exp2);
    if ((e1>=0)&&(e1<=3)){
        if (e1==0)
            exp2 =EXP(exp2+29);
        else if (e1==1)
            exp2 =EXP(exp2+45);
        else if (e1==2)
            exp2 =EXP(exp2+75);
        else exp2 =EXP(exp2+29+45+75);
        int d = e1*3 + exp1*7;
        if (d%2==0){
            exp1 = EXP(exp1 + d/200.0);
        } else {
            exp1 = EXP(exp1-d/100.0);
        }
        exp1 = EXP(exp1);
        exp2 = EXP(exp2);
    }
    
    if ((e1>=4)&&(e1<=99)){
        if ((e1>=4)&&(e1<=19))
            exp2 = EXP(exp2+(e1/4.0 +19));
        else if ((e1>=20)&&(e1<=49))
            exp2 = EXP(exp2+e1/9.0 +21);
        else if ((e1>=50)&&(e1<=65))
            exp2 = EXP(exp2+e1/16.0 +17);
        else if ((e1>=66)&&(e1<=79)){
            exp2 = EXP(exp2+(e1/4.0 +19));
            if (exp2>200)
                exp2 = EXP(exp2+e1/9.0 +21);
        }
        else if ((e1>=80)&&(e1<=99)){
            exp2 = EXP(exp2+(e1/4.0 +19));
            exp2 = EXP(exp2 + (e1/9.0 +21));
            if (exp2>400){
                exp2 = EXP(exp2+(e1/16.0 + 17));
                exp2 =EXP(exp2*1.15);
            }
        }
        exp1 -= e1;
        exp1 = EXP(exp1);
        exp2 = EXP(exp2);
    }
    return exp1 + exp2;
}

// Task 2
double xacsuat(int EXP1){
    double s,p;
    for (int i=1;i<EXP1;i++){
        s=i*i;
        if(s>EXP1){
            int d0 = s - EXP1;
            int d1 = EXP1 - (i-1)*(i-1);
            if (d1<d0){
                p =100;
            }
            else p = ((EXP1/s + 80)/123)*100;
            break;
        }
    }
    return p;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2<0 || E2>99){
        return -99;
    }
    EXP1 = EXP(EXP1);
    HP1 = HP(HP1);
    double p1 = xacsuat(EXP1);
    //CON DUONG 2
    M1 = m(M1);
    int M = M1;
    if (E2%2 !=0){
        while (M1 > (M/2)){
            if (HP1<200){
                HP1 = HP(1.3*HP1);
                M1 -= 150;
            } else {
                HP1 = HP(1.1*HP1);
                M1 -= 70;
            }
            if (M1 < (M/2)){
                break;
            }
            if (EXP1 <400){
                M1 -= 200;
            }else  {
                M1 -= 120;
            }
            EXP1=EXP(EXP1*1.13);
            M1=m(M1);
            if (M1 < (M/2)){
                break;
            }
            if (EXP1<300){
                M1 -= 100;
            }else{ 
                M1 -= 120;
            }
            EXP1 = EXP(EXP1*0.9);
            if (M1 < (M/2)){
                break;
            }
        }
    } else{
        if (M1>0){
            if (HP1<200){
                HP1 = HP(1.3*HP1);
                M1 -= 150;
            } else {
                HP1 = HP(1.1*HP1);
                M1 -= 70;
            }
        }
        if (M1>0){
            if (EXP1 <400){
                M1 -= 200;
            }else  {
                M1 -= 120;
            }
            EXP1 = EXP(EXP1 * 1.13);
        }
        if (M1>0){
            if (EXP1<300){
                M1 -= 100;
            }else{ 
                M1 -= 120;
            }
            EXP1 = EXP(EXP1* 0.9);
        }
    }
    HP1 = HP(0.83*HP1);
    EXP1 = EXP(1.17*EXP1);
    double p2 = xacsuat(EXP1);
    //CON DUONG 3
    int P[] = {32,47,28,79,100,50,22,83,64,11};
    int i;
    if (E2<10){
        i = E2;
    }else{
        i = ((E2/10)+(E2%10))%10;
    }
    double p3 = P[i];

    if ((p1==100)&&(p2==100)&&(p3==100)){
        EXP1 = EXP(EXP1 * 0.75);
    }else{
        double p = (p1+p2+p3)/3;
        if (p<50){
            HP1 = HP((1-0.15) * HP1);
            EXP1 = EXP(1.15* EXP1);
        }else{
            HP1 = HP(0.9 * HP1);
            EXP1 = EXP(1.2 * EXP1);
        }
    }
    M1 = m(M1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3<0 || E3>99){
        return -99;
    }
    EXP1 = EXP(EXP1);
    EXP2 = EXP(EXP2);
    HP2 = EXP(HP2);
    HP1 = HP(HP1);
    int diem[10][10];
    int counti=0;
    int countj=0;
    for(int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            diem[i][j]=((E3*j)+(i*2))*(i-j);
            if (diem[i][j]>(E3*2)){
                counti +=1;
            }
            if (diem[i][j]<(-E3)){
                countj +=1;
            }
        }
    }
    while (counti>9){
        counti = (counti/10)+(counti%10); 
    }
    while (countj>9){
        countj = (countj/10)+(countj%10); 
    }
    int max = diem[counti][countj];
    for (int i=0;i<10;i++){
        if (i==counti){
            continue;
        }
        int z = 2*abs(counti - i);
        for (int j=0;j<10;j++){
            int a = i + j;
            int b = counti + countj;
            if (counti>i){
                if (a==b || a==b-z){
                    if (diem[i][j]>max){
                    max = diem[i][j];
                    }
                }
            }else{
                if (a==b || a== b+z){
                    if (diem[i][j]>max){
                    max = diem[i][j];
                    }
                } 
            }
        }
    }

    if (abs(diem[counti][countj])>max){
        HP1 = HP(HP1*0.9);
        HP2 = HP(HP2*0.9);
        EXP1 = EXP(EXP1*0.88);
        EXP2 = EXP(EXP2*0.88);
        return diem[counti][countj];
    }else{
        HP1 = HP(HP1*1.1);
        HP2 = HP(HP2*1.1);
        EXP1 = EXP(EXP1*1.12);
        EXP2 = EXP(EXP2*1.12);
        return max;
    }

    return -1;
}
// Task 4
const char* findse(const char *email){
    char s_e[100];
    int count;
    for (int i=0; i<strlen(email); i++){
        if (email[i] == '@'){
            break;
        }else{
            s_e[i] = email[i];
            count+=1;
        }
    }
    const char*se=s_e;
    return se;
}
int inclse(const char* s, const char* se){
    for (int i=0; i < strlen(s) ;i++){
        int k=0;
        int count=0;
        for(int j=i; j<(i+strlen(se));j++){
            if(se[k]==s[j]){
                count++;
                k++;
            }else{break;}
            if(count==strlen(se)){
                return i;
            }
        }
    }
    return -1;
}
int sc(const char*s){
    for (int i=0;i<strlen(s);i++){
        if(s[i] == s[i+1]){
            return i;
        }
    }
    return -1;
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    const char* se = findse(email);
    if(strlen(s)<8){
        return -1;
    }
    if (strlen(s)>20){
        return -2;
    }
    int sei = inclse(s,se);
    int sci = sc(s);
    if (sei != -1){
        return -(300+sei);
    }else if (sci !=-1){
        return -(400+sci);
    }
    int count;
    for (int i=0;i<strlen(s);i++){
        if (s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!'){
            count++;
        }
    }
    if (count<1){
        return -5;
    }
    for (int i=0;i<strlen(s);i++){
        if ((s[i]<101 || s[i]>132) || (s[i] < 141 || s[i]>172)){
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int count[30];
    for (int i=0; i<num_pwds;i++){
        count[i]=0;
        for (int j=0; j<num_pwds;j++){
            if (arr_pwds[i] == arr_pwds[j]){
                count[i]++;
            }
        }
    }
    int max=count[0];
    int lenmax = strlen(arr_pwds[0]);
    int result=0;
    for (int i=0; i<num_pwds;i++){
        if (count[i]>max){
            max=count[i];
            lenmax=strlen(arr_pwds[i]);
            result=i;
        }else if (count[i]==max){
            if(strlen(arr_pwds[i])>lenmax){
                lenmax=strlen(arr_pwds[i]);
                result=i;
            }
        }
    }
    return result;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
