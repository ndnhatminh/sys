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
int checkHP(int HP){
    if (HP > 666){
        HP = 666;
    }
    if (HP < 0){
        HP = 0;
    }
    return HP;
}
int checkEXP(int EXP){
    if (EXP > 600){
        EXP = 600;
    }
    if (EXP < 0){
        EXP = 0;
    }
    return EXP;
}
int checkM(int M){
    if (M > 3000){
        M = 3000;
    }
    if (M < 0){
        M = 0;
    }
    return M;
}
int checkE(int E){
    if ( E > 99 || E < 0) {
        return -99;
    }else return E;
}
int square(int exp){
    int a = sqrt(exp);
    int s = 0;
    if ((abs(a*a-exp)) < (abs((a+1)*(a+1)-exp))){
        s = a*a;
    }else {
        s = (a+1)*(a+1);
    }
    return s;
}
double CEIL(double x){
    double y;
    if ( x - (int)x > 1e-10){
        y = ceil(x);
    }else {
        y = (int)x;
    }
    return y;
}
bool checkalphanumber(char x){
    if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9')) return true;
    else return false;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(checkE(e1) == -99) return -99;
    exp1 = checkEXP(exp1);
    exp2 = checkEXP(exp2);
    if (e1 >= 0 && e1 <= 3){
    switch (e1){
        case 0:
        exp2 = exp2 + 29;
        break;
        case 1:
        exp2 = exp2 + 45;
        break;
        case 2:
        exp2 = exp2 + 75;
        break;
        case 3:
        exp2 = exp2 + 29 + 45 + 75;
        break;
        }
        int d;
        d = e1*3 + exp1*7;
        if (d % 2 == 0){
            exp1 = CEIL(exp1 + d/200.0);
        }
        else {
            exp1 = CEIL(exp1 - d/100.0);
        }
    }
    if (e1 >= 4 && e1 <= 99){
    if (e1 >= 4 && e1 <= 19 ){
        exp2 = CEIL(exp2 + (e1/4.0 + 19));
    }
    if (e1 >= 20 && e1 <= 49){
        exp2 = CEIL( exp2 + (e1/9.0 + 21) );
    }
    if (e1 >= 50 && e1 <= 65){
       exp2 = CEIL(exp2 +(e1/16.0 + 17) );
    }
    if (e1 >= 66 && e1 <= 79){
        exp2 = CEIL(exp2 + (e1/4.0 + 19));
        exp2 = checkEXP(exp2);
        if (exp2 >200){
            exp2 = CEIL(exp2 +(e1/9.0 + 21));
        }
    }
    if (e1 >= 80 && e1 <= 99){
        exp2 = CEIL(exp2 + (e1/4.0 + 19));
        exp2 = checkEXP(exp2);
        exp2 = CEIL(exp2 +(e1/9.0 + 21));
        exp2 = checkEXP(exp2);
        if (exp2 > 400){
           exp2 = CEIL(exp2 +(e1/16.0 + 17)); 
           exp2 = checkEXP(exp2);
           exp2 = CEIL(exp2*1.15);
        }
    }
    exp1 = exp1 - e1;
    }
    exp1 = checkEXP(exp1);
    exp2 = checkEXP(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (checkE(E2) == -99 ) return -99;
    HP1 =  checkHP(HP1);
    EXP1 = checkEXP(EXP1);
    M1 = checkM(M1);
    double p1,p2,p3;
    // Road 01
    int S1 = square(EXP1);
    if (EXP1 >= S1){
        p1 = 100;
    }else {
        p1 = (((float)EXP1/S1+80)/123.0)*100;
    }
    // Road 02
    int temp = M1;
    int m = 0;
    if (E2 %2 !=0){
        while( m <= temp*0.5 && M1 != 0){
            if ( HP1 < 200){
                M1 = checkM(M1 - 150);
                HP1 = checkHP(CEIL(HP1*1.30));
                m = m + 150;
            }else {
                M1 = checkM(M1 - 70);
                HP1 = checkHP(CEIL(HP1*1.10));
                m = m + 70;
            }
            if ( (m <= temp*0.5) && M1 != 0 ){
                if ( EXP1 < 400){
                    M1 = checkM(M1 - 200);
                    m = m + 200;
                    EXP1 = checkEXP(CEIL(EXP1*1.13));
                }else if( EXP1 >= 400){
                    M1 = checkM(M1 - 120);
                    m = m + 120;
                    EXP1 = checkEXP(CEIL(EXP1*1.13));
                }
            }
            if ((m <= temp*0.5) && M1 !=0 ){
                if ( EXP1 < 300){
                    EXP1 = checkEXP(CEIL(EXP1*0.9));
                    M1 = checkM(M1 - 100);
                    m = m + 100;
                }else {
                    M1 = checkM(M1 - 120);
                    m = m + 120;
                    EXP1 = checkEXP(CEIL(EXP1*0.9));
                }
            }
        }
        EXP1 = checkEXP(CEIL(EXP1*1.17));
        HP1 = checkHP(CEIL(HP1*0.83));
    }else {
        if ( HP1 < 200 ){
        HP1 = CEIL(HP1*1.30);
        HP1 = checkHP(HP1);
        M1 = M1 - 150;
        M1 = checkM(M1);
    }else {
        HP1 = CEIL(HP1*1.10);
        HP1 = checkHP(HP1);
        M1 = M1 - 70;
        M1 = checkM(M1);
    }
    if ( M1 != 0){
        if ( EXP1 < 400 ){
            M1 = M1 - 200;
            M1 = checkM(M1);
            EXP1 = checkEXP(CEIL(EXP1*1.13));
        }else {
            M1 = M1 - 120;
            M1 = checkM(M1);
            EXP1 = checkEXP(CEIL(EXP1*1.13));
        }
    }
    if ( M1 != 0){
        if ( EXP1 < 300){
            M1 = M1 - 100;
            M1 = checkM(M1);
            EXP1 = checkEXP(CEIL(EXP1*0.9));
        }else if ( EXP1 >= 300) {
            M1 = M1 - 120;
            M1 = checkM(M1);
            EXP1 = checkEXP(CEIL(EXP1*0.9));
        }
    }
        EXP1 = checkEXP(CEIL(EXP1*1.17));
        HP1 = checkHP(CEIL(HP1*0.83));
    }
    int S2 = square(EXP1);
    if (EXP1 >= S2){
        p2 = 100;
    }else {
        p2 = (((float)EXP1/S2+80)/123.0)*100;
    }
    // Road 03
    int P[10] = {32,47,28,79,100,50,22,83,64,11};
    int i;
    if ( E2 >= 0 && E2 <= 9 ){
        i = E2;
        p3 = P[i];
    }
    if ( E2 >= 10 && E2 <= 99 ){
        i = (E2/10 + E2%10)%10;
        p3 = P[i];
    }
    //
    if ( p1 == 100 && p2 == 100 && p3 == 100){
        EXP1 = checkEXP(CEIL(EXP1*0.75));
    } 
    //}
    cout << p1 << endl << p2 << endl << p3 << endl;
    double P123;
    if ( p1 != 100 || p2 != 100 || p3 != 100){
         P123 = (p1+ p2 + p3)/3;
            if (P123 < 50){
                HP1 = checkHP(CEIL(HP1*0.85));
                EXP1 = checkEXP(CEIL(EXP1*1.15));
            }else {
            HP1 = checkHP(CEIL(HP1*0.9));
            EXP1 = checkEXP(CEIL(EXP1*1.2));
            }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ( checkE(E3) == -99) return -99;
    HP1 = checkHP(HP1);
    EXP1 = checkEXP(EXP1);
    HP2 = checkHP(HP2);
    EXP2 = checkEXP(EXP2);
    double matrix[10][10];
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            matrix[i][j]= (E3*j+i*2)*(i-j);
        }
    }
    //cout << "Matrix: "<< endl;
    //for (int i=0; i<10; i++){
    //    for (int j=0; j<10; j++){
    //        cout << setw(7) << matrix[i][j];
    //    }
    //    cout << endl;
    //}
    int k = 0;
    int l = 0;
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if (matrix[i][j] > E3*2){
                k = k + 1;
            }
            if (matrix[i][j] < -E3){
                l = l + 1;
            }
        }
    }
    while (k >=10 && k <= 99){
        k = k/10 + k%10;
    }
    while (l >=10 && l <= 99){
        l = l/10 + l%10;
    }
    double max = matrix[k][l];
    int i = k;
    int j = l;
    while ( i >=0 && j >=0){
        if ( matrix[i][j] > max){
            max = matrix[i][j];
        }
        i = i-1;
        j = j-1;
    }
    i = k;
    j = l;
    while ( i <=9 && j <= 9){
        if ( matrix[i][j] > max){
            max = matrix[i][j];
        }
        i = i + 1;
        j = j + 1;
    }
    i = k;
    j = l;
    while ( i>=0 && j <=9){
        if ( matrix[i][j] > max){
            max = matrix[i][j];
        }
        i = i - 1;
        j = j + 1;
    }
    i = k;
    j = l;
    while ( i <= 9 && j >= 0){
        if ( matrix[i][j] > max){
            max = matrix[i][j];
        }
        i = i + 1;
        j = j - 1;
    }
    if ( max < 0){
        max = abs(max);
    }
    if ( abs(matrix[k][l]) > max){
        EXP1 = checkEXP(CEIL(EXP1*0.88));
        HP1 = checkHP(CEIL(HP1*0.9));
        EXP2 = checkEXP(CEIL(EXP2*0.88));
        HP2 = checkHP(CEIL(HP2*0.9));
        return matrix[k][l];
    }else {
        EXP1 = checkEXP(CEIL(EXP1*1.12));
        HP1 = checkHP(CEIL(HP1*1.1));
        EXP2 = checkEXP(CEIL(EXP2*1.12));
        HP2 = checkHP(CEIL(HP2*1.1));
        return max;
    }
    //return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int i = 0;
    int selength = 0;
    while ( email[i] != '@'){
        selength = selength +1;
        i = i+1;
    }
    char se[100];
    for ( int i =0; i <= selength ; i++){
        se[i] = email[i];
    }
    se[selength] = '\0';
    if ( strlen(s) < 8) return -1;
    if ( strlen(s) > 20) return -2;
    if ( strstr(s,se) != nullptr){
    int sei = strlen(s)-strlen(strstr(s,se));
    return -(300+sei);
    }
    for ( int i =0; i < strlen(s); i++){
        if ( s[i] == s[i+1] && s[i]==s[i+2])
        return -(400+i);
    }
    if (strpbrk(s,"@#%$!") == nullptr) return -5;
    for ( int i=0; i < strlen(s); i++){
        if ( checkalphanumber(s[i]) == false && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!')
        return i;
    }
    return -10;
}
int countE(int k, const char* arr[], int n){
    int count = 0;
    string str = arr[k];
    for (int i=0;i < n; i++){
       if ( arr[i] == str ){
        count = count + 1 ;
       }
    }
    return count;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    if ( num_pwds <=0) return -1;
    int k=0;
    for ( int i =0; i < num_pwds; i++){
        if ( countE(i,arr_pwds,num_pwds) > countE(k,arr_pwds,num_pwds) ){
            k = i;
        }
    }
    for (int i=0; i < num_pwds; i++){
        if ( countE(i,arr_pwds,num_pwds) == countE(k,arr_pwds,num_pwds) && arr_pwds[i] != arr_pwds[k]){
            if ( strlen(arr_pwds[i]) > strlen(arr_pwds[k])){
                k = i;
            }
        }
    }    
    return k;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////