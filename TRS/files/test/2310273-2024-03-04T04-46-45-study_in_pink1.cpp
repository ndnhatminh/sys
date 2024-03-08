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

void checkHP1(int & HP1){
    if(HP1 > 666 ) HP1 = 666;
    if(HP1 < 0 ) HP1 = 0;
}

void checkHP2(int & HP2){
    if(HP2 > 666 ) HP2 = 666;
    if(HP2 < 0 ) HP2 = 0;
}

void checkEXP1(int & EXP1){
    if( EXP1 > 600 ) EXP1 = 600;
    if( EXP1 < 0 ) EXP1 = 0;
}

void checkEXP2(int & EXP2){
    if( EXP2 > 600 ) EXP2 = 600;
    if( EXP2 < 0 ) EXP2 = 0;
}

void checkM1(int & M1){
    if(M1 > 3000) M1 = 3000;
    if(M1 < 0 ) M1 = 0;
}

void checkM2(int & M2){
    if(M2 > 3000) M2 = 3000;
    if(M2 < 0 ) M2 = 0;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1 < 0 || e1 > 99) return -99;
    
    checkEXP1(exp1);
    checkEXP2(exp2);
    
    if(0 <= e1 && e1 <= 3){
        if(e1 == 0) exp2 += 29; 
        else if(e1 == 1) exp2 += 45; 
        else if(e1 == 2) exp2 += 75; 
        else exp2 += 29 + 45 + 75; 
        
        checkEXP2(exp2);
        
        int D;
        D = e1 * 3 + exp1 * 7;
        
        if(D % 2 == 0) exp1 = ceil(exp1 + D * 1.00 / 200); 
        else exp1 = ceil(exp1 - D * 1.00 / 100); 
        checkEXP1(exp1);
    }
    
    else if(4 <= e1 && e1 <= 19){
        exp2 = ceil( exp2 + e1 * 1.00 / 4 + 19);
        exp1 -= e1;
    }
    
    else if(20 <= e1 && e1 <= 49){
        exp2 = ceil(exp2 + e1 * 1.00/ 9 + 21);
        exp1 -= e1;
    }
    
    else if(50 <= e1 && e1 <= 65){
        exp2 = ceil( exp2 + e1 * 1.00 / 16 + 17);
        exp1 -= e1;
    }
    
    else if(66 <= e1 && e1 <= 79){
        exp2 = ceil( exp2 + e1 * 1.00/ 4 + 19);
        if(exp2 > 200) exp2 = ceil( exp2 + e1 * 1.00/ 9 + 21);
        exp1 -= e1;
    }
    
    
    else if(80 <= e1 && e1 <= 99){
        exp2 = ceil( exp2 + e1 * 1.00 / 4 + 19);
        exp2 = ceil( exp2 + e1 * 1.00 / 9 + 21);
        if(exp2 > 400){
            exp2 = ceil( exp2 + e1 * 1.00 / 16 + 17);
            exp2 = ceil( exp2 * 115.00 / 100);
        }
        exp1 -= e1;
    }
    
    checkEXP1(exp1);
    checkEXP2(exp2);

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 < 0 || E2 > 99) return -99;
    
    checkHP1(HP1);
    checkEXP1(EXP1);
    checkM1(M1);
    // Tren con duong 1
    
    double P1;
    
    int S1;
    S1 = round ( sqrt(EXP1) ) * round ( sqrt(EXP1) );
    if(EXP1 >= S1) P1 = 100;
    else P1 = (EXP1 * 1.00 / S1 + 80) / 123.00 * 100;
    
    // Tren con duong 2
    
    int m = M1 / 2.00; // 50% so tien ban dau
    int n = 0;
    
    while(E2 % 2 != 0){
        if(M1 <= 0) break;
        
        if(HP1 < 200){
            HP1 = ceil( HP1 * 130.00 / 100);
            M1 -= 150;
            n = n  + 150;
        }
        else {
            HP1 = ceil( HP1 * 110.00 / 100);
            n = n + 70;
            M1 -= 70;
        }
        
        checkHP1(HP1);
        checkM1(M1);
        
        if(n > m){ break;}
        if(M1 <=0){ break;}
    
        if(EXP1 < 400){
            M1 -= 200;
            n += 200;
        }
        else{
            M1 -= 120;
            n += 120;
        }
        EXP1 = ceil( EXP1 * 113.00 / 100);
        
        checkEXP1(EXP1);
        checkM1(M1);
        if(n > m){ break;}
        if(M1 <=0){ break;}
        
        if(EXP1 < 300){ 
            M1 -= 100;
            n += 100;
        }
        else{ 
            M1 -= 120;
            n += 120;
        }
        EXP1 = ceil(EXP1 * 9.00 / 10);
        
        checkEXP1(EXP1);
        checkM1(M1);
        if(n > m){ break;}
        if(M1 <=0){ break;}
        
    }
    
    //
    
    while(E2 % 2 == 0){
    if (M1 <= 0) break;
    
    if(HP1 < 200){
        HP1 = ceil( HP1 * 130.00 / 100);
        M1 = M1 - 150;
    }
    else {
        HP1 = ceil( HP1 * 110.00 / 100);
        M1 = M1 - 70; 
    }
    checkHP1(HP1);
    checkM1(M1);
    
    if(M1 <= 0){ break;}
    
    if(EXP1 < 400) M1 -= 200;
    else M1 -= 120;
    EXP1 = ceil( EXP1 *113.00/100);
    
    checkEXP1(EXP1);
    checkM1(M1);
    
    if(M1 <= 0) break;
    
    if(EXP1 < 300) M1 -= 100;
    else M1 -= 120;
    EXP1 = ceil(EXP1 * 90.00 / 100);
    checkEXP1(EXP1);
    checkM1(M1);
    
    break;
    }
    
    // Sau do
    HP1 = ceil( HP1 * 83.00 / 100); 
    EXP1 = ceil( EXP1 * 117.00 / 100);
    
    checkEXP1(EXP1);
    checkHP1(HP1);
    
    double P2;
    int S2 = round ( sqrt(EXP1) ) * round ( sqrt(EXP1) );
    if(EXP1 >= S2) P2 = 100;
    else P2 = (EXP1 * 1.00 / S2 + 80) / 123.00 * 100;
    
    // Tren con duong 3
    
    double P3;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i, a, b, c;
    if(E2 / 10 != 0){
        a = E2 % 10;
        b = E2 / 10;
        c = a + b;
        if(c / 10 != 0) i = c % 10;
        else i = c;
        P3 = P[i];
    }
    else {
        P3 = P[E2];
    }
    
    double p;
    if( P1 == 100 && P2 == 100 && P3 == 100){
        EXP1 = ceil( EXP1 * 75.00 / 100);
    }
    else{ p = (P1 + P2 + P3) / 3;
    
        if(p < 50 ){
            HP1 = ceil (HP1 * 85.00 / 100);
            EXP1 = ceil (EXP1 *115.00 / 100);
        }
        else {
            HP1 = ceil (HP1 * 90.00 / 100);
            EXP1 = ceil (EXP1 * 120.00 / 100);
        }
    }
    
    checkEXP1(EXP1);
    checkHP1(HP1);
    checkM1(M1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 < 0 || E3 > 99) return -99;
    
    checkHP1(HP1);
    checkHP2(HP2);
    checkEXP1(EXP1);
    checkEXP2(EXP2);
    
    int matran[10][10];
    int i, j, duong = 0, am = 0;
    
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            matran[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            if(matran[i][j] > 0 && matran[i][j] > E3 * 2) duong += 1;
            else if(matran[i][j] < 0 && matran[i][j] < E3 * -1) am += 1;
        }
    }
    
    int a = (duong % 10) + (duong / 10 ) % 10; 
    int b = (am % 10 ) + (am / 10 ) % 10;
    
    if(a > 9){
        a = (a % 10) + (a / 10) % 10;
    }
    if(b > 9){
        b = (b % 10) + (b / 10) % 10;
    }
    
    int diem = matran[a][b];
    int max = matran[a][b];
    
    
    // duong cheo trai
    int hieu = abs( a - b);
    
    // a giam b giam 
    int m = a, n = b;
    while(m >= 0 && n >= 0 && abs(m - n) == hieu){
        if(matran[m][n] > max) max = matran[m][n];
        m--;
        n--;
    }
    // a tang b tang 
    m = a; n = b;
    while(m < 10 && n < 10 && abs( m - n ) == hieu){
        if(matran[m][n] > max) max = matran[m][n];
        m++;
        n++;
    }
    
    // duong cheo phai 
    int tong = a + b;
    
    // a tang b giam
    m = a; n = b;
    while(m < 10 && n >= 0 && m + n == tong){
        if(matran[m][n] > max) max = matran[m][n];
        m++;
        n--;
    }
    // a giam b tang
    m = a; n = b;
    while(m >= 0 && n < 10 && m + n == tong){
        if(matran[m][n] > max) max = matran[m][n];
        m--;
        n++;
    }
    
    int kq;
    
    if( abs(diem) > max){
        kq = diem;
        HP1 = ceil(HP1 * 9.00 / 10);
        HP2 = ceil(HP2 * 9.00 / 10);
        EXP1 = ceil(EXP1 * 88.00 / 100);
        EXP2 = ceil(EXP2 * 88.00 / 100);
    }
    else {
        kq = max;
        HP1 = ceil(HP1 * 11.00 / 10);
        HP2 = ceil(HP2 * 11.00 / 10);
        EXP1 = ceil(EXP1 * 112.00 / 100);
        EXP2 = ceil(EXP2 * 112.00 / 100);
    }
    
    checkEXP1(EXP1);
    checkEXP2(EXP2);
    checkHP1(HP1);
    checkHP2(HP2);
    
    return kq;
}

// Task 4

bool check(const char *s1){
    int count=1;
    char preChar=s1[0];
    for(int i=1;i<strlen(s1);i++){
        if(s1[i]==preChar){
            count++;
        }
        else{
            count=1;
            preChar=s1[i];
        }
        if(count>2){
            return true;
        }
    }
    return false;
}
int position(const char *password){
    char previousChar = password[0];
    int Count = 1;
    int position = 0;
    for (int i = 1; i < strlen(password); i++) {
        if (password[i] == previousChar) {
            Count++;
            if (Count == 3) {
                position = i -2;
                break;
            }
        } else {
            previousChar = password[i];
            Count = 1;
        }
    }
    return position;
}
bool special(const char *password){
    for(int i=0;i<strlen(password);i++){
        if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%'){
            return false;
        }
    }
    return true;
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
        char se[100];
    int i=0;
    while(email[i]!='@'){
        se[i]=email[i];
        i++;
    }
    se[i]='\0';
    if(strlen(s)<8) return -1;
    if(strlen(s)>20) return -2;
    if(strstr(s,se)!=NULL){
        const char *p=strstr(s,se);
        return (-300+s-p);
    }
    if(check(s)){
        return -(400+position(s));
    }
    if(special(s)){
        return -5;
    }
    for(int i = 0; i < strlen(s); i++){
        if(!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))){
            return i;
        }
    }
    return -10;
}



// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxcount = 0,maxsize=0;
    int index = 0;
    for (int i = 0; i < num_pwds; i++) {
        const char *temp = arr_pwds[i];
        int count = 1;
        int length = 0;

        for (int j = 0; temp[j] != '\0'; j++) {
            length++;
        }

        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[j],temp) == 0) {
                count++;
            }
        }
        if (count > maxcount || (count == maxcount && length > maxsize)) {
            maxcount = count;
            maxsize = length;
            index = i;
        }
    }

    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////