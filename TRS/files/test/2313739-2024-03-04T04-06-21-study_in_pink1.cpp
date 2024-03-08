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

//! Task 1
void checkEXP(int &EXP1, int &EXP2){
    if(EXP1 < 0) EXP1 = 0;
    else if (EXP1 > 600) EXP1 = 600;
    if(EXP2 < 0) EXP2 = 0;
    else if (EXP2 > 600) EXP2 = 600;
}

void checkHP(int &HP1, int &HP2){
    if(HP1 < 0) HP1 = 0;
    else if (HP1 > 666) HP1 = 666;
    if(HP2 < 0) HP2 = 0;
    else if (HP2 > 666) HP2 = 666;
}

void checkM(int &M1, int &M2){
    if(M1 < 0) M1 = 0;
    else if (M1 > 3000) M1 = 3000;
    if(M2 < 0) M2 = 0;
    else if (M2 > 3000) M2 = 3000;
}

int firstMeet(int &EXP1, int &EXP2, int E1) {
checkEXP(EXP1, EXP2);
    if (E1 < 0 || E1 > 99) return -99;
    else if (E1 >= 0 && E1 <= 3){
        switch(E1){
            case 0: EXP2 += 29;
            break;
            case 1: EXP2 += 45;
            break;
            case 2: EXP2 += 75;
            break;
            case 3: EXP2 += 149;
            break;
        }
        int D;
        D = E1*3 + EXP1*7;
        if(D % 2 == 0){
             EXP1 = ceil(EXP1 + D/200.0);
        }
        else{
            EXP1 = ceil(EXP1 - D/100.0);
        }
        checkEXP(EXP1, EXP2);
        return EXP1 + EXP2;
    }
    else {
        if ( E1 >=4 && E1 <=19)
        EXP2 += ceil(E1/4.0) + 19;
        else if (E1 >=20 && E1 <= 49)
        EXP2 += ceil(E1/9.0) +21;
        else if (E1 >=50 && E1 <= 65)
        EXP2 += ceil(E1/16.0) + 17;
        else if (E1 >= 66 && E1 <=79){
        EXP2 += ceil(E1/4.0) + 19;
        checkEXP(EXP1, EXP2);
        if(EXP2 > 200)
        EXP2 += ceil(E1/9.0)+21;}
        else{
            EXP2 += ceil(E1/4.0) + 19;
            checkEXP(EXP1, EXP2);
            EXP2 += ceil(E1/9.0) + 21;
            checkEXP(EXP1, EXP2);
            if(EXP2 > 400){
                EXP2 += ceil(E1/16.0) + 17;
                checkEXP(EXP1, EXP2);
                EXP2 = ceil(EXP2*1.15*1.0);
                checkEXP(EXP1, EXP2);
            }
        }
        EXP1 -= E1;
    checkEXP(EXP1, EXP2);
    }
    return EXP1 + EXP2;
}

// Task 2
void checkEXP(int &EXP1){
    if(EXP1 < 0) EXP1 = 0;
    else if (EXP1 > 600) EXP1 = 600;
}

void checkHP(int &HP1){
    if(HP1 < 0) HP1 = 0;
    else if (HP1 > 666) HP1 = 666;
}

void checkM(int &M1){
    if(M1 < 0) M1 = 0;
    else if (M1 > 3000) M1 = 3000;
}
double ceil(double x){
    if (x - (int)x > 1e-9) 
    return (int)x + 1;
    else return (int)x;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if ( E2 < 0 || E2 >99 ) return -99;
    else{
    checkEXP(EXP1);
    checkHP(HP1);
    checkM(M1);
    // Con duong 1
    int a,b,c,S;
    a = floor(sqrt(EXP1));
    b = EXP1 - a*a;
    c = (a+1)*(a+1) - EXP1;
    if (b < c){
        S =  a*a;
    }
    else S = (a+1)*(a+1);
    double P1;
    if( EXP1 >= S) P1 = 100;
    else P1 = (((double)EXP1/S + 80)/123)*100;

    // Con duong 2
    int m = 0,n = M1;
    double P2;
    if ( E2 % 2 == 1){
        while(1){
            if(HP1 < 200){
                HP1 = ceil(1.3*HP1);
                M1 -= 150;
                m += 150;
                checkHP(HP1);
                checkM(M1);
                if(m > 0.5*n) break;
            }
            else{
                HP1 = ceil(1.1*HP1);
                M1 -= 70;
                m += 70;
                checkHP(HP1);
                checkM(M1);
                if(m > 0.5*n) break;
            }
            if( EXP1 < 400){
                M1 -= 200;
                m +=200;
                EXP1 = ceil(1.13*EXP1);
                checkEXP(EXP1);
                checkM(M1);
                if(m > 0.5*n) break; 
            }
            else{
                M1 -= 120;
                m += 120;
                checkM(M1);
                EXP1 = ceil(1.13*EXP1);
                checkEXP(EXP1);
                if(m > 0.5*n) break;
            }
            if(EXP1 < 300){
                M1 -= 100;
                m += 100;
                EXP1 = ceil(0.9*EXP1);
                checkEXP(EXP1);
                checkHP(HP1);
                checkM(M1);
                if(m > 0.5*n) break;
            }
            else{
                M1 -= 120;
                m += 120;
                EXP1 = ceil(0.9*EXP1);
                checkEXP(EXP1);
                checkHP(HP1);
                checkM(M1);
                if(m > 0.5*n) break;
            }
        }
        HP1 = ceil(HP1*0.83);
        EXP1 = ceil(EXP1*1.17);
        checkEXP(EXP1);
        checkHP(HP1);
        checkM(M1);
        // THEM SO CHINH PHUONG
         int a1,b1,c1,S1;
    a1 = floor(sqrt(EXP1));
    b1 = EXP1 - a1*a1;
    c1 = (a1+1)*(a1+1) - EXP1;
    if (b1 < c1){
        S1 = a1*a1;
    }
    else S1 = (a1+1)*(a1+1);
        if(EXP1 >= S1) P2 = 100;
        else P2 = (((double)EXP1/S + 80) / 123)*100;
    }
    else{
        if(HP1 < 200){
                HP1 = ceil(1.3*HP1);
                M1 -= 150;
                checkHP(HP1);
                checkM(M1);
            }
            else{
                HP1 = ceil(1.1*HP1);
                M1 -= 70;
    checkHP(HP1);
                checkM(M1);   
            }
            if(M1 > 0){
if( EXP1 < 400){
                M1 -= 200;
                checkM(M1);
            }
            else{
                M1 -= 120;
                checkM(M1);
            }
            EXP1 = ceil(1.13*EXP1);
                checkEXP(EXP1);
            }
            
            if(M1 > 0){
            if(EXP1 < 300){
                M1 -= 100;
                EXP1 = ceil(0.9*EXP1);
                checkEXP(EXP1);
                checkHP(HP1);
                checkM(M1);
            }
            else{
                M1 -= 120;
                EXP1 = ceil(0.9*EXP1);
                checkEXP(EXP1);
                checkHP(HP1);
                checkM(M1);
            }}
        HP1 = ceil(HP1*0.83);
        EXP1 = ceil(EXP1*1.17);
        checkEXP(EXP1);
        checkHP(HP1);
        checkM(M1);
        int a1,b1,c1,S1;
    a1 = floor(sqrt(EXP1));
    b1 = EXP1 - a1*a1;
    c1 = (a1+1)*(a1+1) - EXP1;
    if (b1 < c1){
        S1 = a1*a1;
    }
    else S1 = (a1+1)*(a1+1);
        if(EXP1 >= S1) P2 = 100;
        else P2 = (((double)EXP1/S + 80) / 123)*100;
    }

    //Con duong 3
    double P3;
    int p3[10] = {32,47,28,79,100,50,22,83,64,11};
    if(E2 < 10){
        P3 = p3[E2];}
    else if( E2 > 10 && E2 < 99){
        int e2,e3;
        e2 = E2 % 10 + E2 /10;
        e3 = e2 % 10;
        P3 = p3[e3];
    }
    double P4;
    if( P1 == 100 && P2 == 100 && P3  == 100){
        EXP1 = ceil(0.75*EXP1);
        checkEXP(EXP1);
    }
    else{
        P4 = ( P1+ P2 + P3)/3.0;
        if(P4 < 50){
            HP1 =ceil(HP1* 0.85);
            EXP1 = ceil(EXP1* 1.15);
            checkEXP(EXP1);
        }
        else{
            HP1 = ceil(HP1* 0.9);
            EXP1 = ceil(EXP1 * 1.20);
            checkEXP(EXP1);
            checkHP(HP1);
        }
    }
    return HP1 + EXP1 + M1;
}}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(E3 < 0 || E3 > 99) return -99;
    else{
    int diem_taxi[10][10];
    for(int i=0; i<10; i++){
        for(int j = 0; j<10; j++){
            diem_taxi[i][j]=(E3*j + 2*i)*(i-j);
        }
    }

    int duong = 0, am = 0;
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            if(diem_taxi[i][j]>0 && diem_taxi[i][j] > 2*E3) ++duong;
            else if(diem_taxi[i][j]<0 && diem_taxi[i][j] < -E3) ++am;
        }
    }

    int i,j;
    while (duong >= 10){
        int sum1 = 0;
        while(duong != 0){
            sum1 = sum1 + duong%10;
            duong /= 10;
        }
        duong = sum1;
    }
    i = duong;

    while (am >= 10){
        int sum2 = 0;
        while(am != 0){
            sum2 = sum2 + am%10;
            am /= 10;
        }
        am = sum2;
    }
    j = am;

    int a = i, b = j, max = diem_taxi[i][j];
    while( (a>=0 && a<=9) && (b>=0 && b<=9)){
        if(max < diem_taxi[a+1][b+1]){
            max = diem_taxi[a+1][b+1];
            
        }
        a++;
        b++;
    }
    a = i; b = j;
    while( (a>=0 && a<=9) && (b>=0 && b<=9)){
        if(max < diem_taxi[a-1][b-1]){
            max = diem_taxi[a-1][b-1];
            
        }
        a--;
        b--;
    }
    a = i; b = j;
    while( (a>=0 && a<=9) && (b>=0 && b<=9)){
        if(max < diem_taxi[a+1][b-1]){
            max = diem_taxi[a+1][b-1];
            
        }
        a++;
        b--;
    }
    a = i; b = j;
    while( (a>=0 && a<=9) && (b>=0 && b<=9)){
        if(max < diem_taxi[a-1][b+1]){
            max = diem_taxi[a-1][b+1];
            
        }
        a--;
        b++;
    }

    if(abs(diem_taxi[i][j])>max){
        EXP1 = ceil(EXP1 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        EXP2 = ceil(EXP2 * 0.88);
        HP2 = ceil(HP2 * 0.9);
        checkEXP(EXP1,EXP2);
        checkHP(HP1,HP2);
        return diem_taxi[i][j];
    }
    else{
        EXP1 = ceil(EXP1 * 1.12);
        HP1 = ceil(HP1 * 1.1);
        EXP2 = ceil(EXP2 * 1.12);
        HP2 = ceil(HP2 * 1.1);
        checkEXP(EXP1,EXP2);
        checkHP(HP1,HP2);
        return max;
    }
}}

// Task 4
int checkPassword(const char *s, const char *email) {

    char se[101];
    int length = 0;
    while(email[length] != '@'){
        se[length] = email[length];
        length ++;
    }
    se[length] = '\0';
    
    const char *thutu = strstr(s,se);
    int sei = thutu - s;
    
    int dodai = strlen(s),sci,h=0;
    for(int i = 0; i <= dodai -3; i++){
        if((s[i]==s[i+1])&&(s[i+1]==s[i+2])){
            sci = i;
            h++;
            break;
        }
    }
    
    bool check = true;
    for(int i = 0; i< dodai; i++){
        if(s[i]=='@'|| s[i]=='#'||s[i]=='$'||s[i]=='!' ||s[i]=='%')
            check = false;
    }
    // kiem tra s co chua cac ki tu khac yeu de bai hay khong 
    int a = -1;
    for(int i = 0; i< dodai; i++){
        if(!isalpha(s[i]) && !isdigit(s[i]) && s[i] !='!' && s[i] !='@' && s[i] !='#' && s[i] !='$' && s[i] !='%'){
            a=i;
            break;
        }
    }
    
    if(strlen(s) < 8) return -1;
    else if (strlen(s)>20) return -2;
    else if (thutu != NULL) return -(300+sei);
    else if (h>0) return -(400+sci);
    else if (check) return -5;
    else if ( a>=0) return a;
    else return -10;
    
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int max_dem = 0, max_dai = 0;
    const char* mk_dung = nullptr;
    for (int i = 0; i < num_pwds; ++i) {
        int dem = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                ++dem;
            }
        }
        int dai = strlen(arr_pwds[i]);
        if (dem > max_dem || (dem == max_dem && dai > max_dai)) {
            max_dem = dem;
            max_dai = dai;
            mk_dung = arr_pwds[i];
        }
    }
    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(arr_pwds[i], mk_dung) == 0) {
            return i;
        }
    } return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////