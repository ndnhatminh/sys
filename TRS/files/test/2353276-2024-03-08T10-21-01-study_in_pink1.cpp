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

int checkexpfunction(int a){
    if (a>600){
        return 600;
    }
    if (a<0){
        return 0;
    }
    return a;
}

int checkhpfunction(int a){
    if (a>666){
        return 666;
    }
    if (a<0){
        return 0;
    }
    return a;
}

int checkgoldfunction(int a){
    if (a>3000){
        return 3000;
    }
    if (a<0){
        return 0;
    }
    return a;
}

int nearestsquare(int a){
    int floorsqra = floor(sqrt(a));
    int ceilsqra = ceil(sqrt(a));
    if (abs(pow(floorsqra,2) - a) > abs(pow(ceilsqra,2) - a)) {
        return pow(ceilsqra,2);
    }
    return pow(floorsqra,2);
}

int sumofnum(int a) {
    if (a > 9) {
        return sumofnum((a / 10) + (a % 10));
    }
    return a;
}

int maxofdiagonal(int matrix[10][10], int row, int col){
    int max = matrix[row][col];
    int i = row;
    int j = col;
    while (i >= 0 && j >= 0 && i < 10 && j < 10) {
        if (max < matrix[i][j]) {
            max = matrix[i][j];
        }
        --i;
        ++j;
    }
    i = row;
    j = col;
    while (i >= 0 && j >= 0 && i < 10 && j < 10) {
        if (max < matrix[i][j]) {
            max = matrix[i][j];
        }
        ++i;
        --j;
    }
    i = row;
    j = col;
    while (i >= 0 && j >= 0 && i < 10 && j < 10) {
        if (max < matrix[i][j]) {
            max = matrix[i][j];
        }
        ++i;
        ++j;
    }
    i = row;
    j = col;
    while (i >= 0 && j >= 0 && i < 10 && j < 10) {
        if (max < matrix[i][j]) {
            max = matrix[i][j];
        }
        --i;
        --j;
    }
    return max;
}

bool detectspecialletter(string s){
    for (int i = 0; i<s.length(); i++){
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'){
            return true;
        }
    }
    return false;
}

int detectcontinuousity(string s){
    for (int i=0; i<s.length(); i++){
        if ((s[i]==s[i+1]) && (s[i] == s[i+2])){
            return i;
        }
    }
    return -1;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1)
{
    //TODO: implement task
    if ((e1<0) || (e1>99)){
        return -99;
    }
    exp1 = checkexpfunction(exp1);
    exp2 = checkexpfunction(exp2);
    if ((e1<=3) && (e1>=0)) {
        if (e1 == 0){
            exp2 += 29;
        }
        if (e1 == 1){
            exp2 += 45;
        }
        if (e1 == 2) {
            exp2 += 75;
        }
        if (e1 == 3) {
            exp2 = exp2 + 29 + 45 + 75;
        }
        
        int d = e1*3 + exp1*7;
        
        if (d%2 == 0){
            exp1 = ceil(exp1 + 1.0*d/200);
        }
        else {
            exp1 = ceil(exp1 - 1.0*d/100);
        }
    }
    else {
        if ((e1>=4) && (e1<=19)) {
            exp2 = ceil(exp2 + 1.0*e1/4 + 19);
        }
        else if ((e1>=20) && (e1<=49)) {
            exp2 = ceil(exp2 + 1.0*e1/9 + 21);
        }
        else if ((e1>=50) && (e1<=65)) {
            exp2 = ceil(exp2 + 1.0*e1/16 + 17);
        }
        else if ((e1>=66) && (e1<=79)) {
            exp2 = ceil(exp2 + 1.0*e1/4 + 19);
            if (exp2>200){
                exp2 = ceil(exp2 + 1.0*e1/9 + 21);
            }
        }
        else if ((e1>=80) && (e1<=99)) {
            exp2 = ceil(exp2 + 1.0*e1/4 + 19);
            exp2 = ceil(exp2 + 1.0*e1/9 + 21);
            if (exp2>400){
                exp2 = ceil(exp2 + 1.0*e1/16 + 17);
                exp2 = ceil(exp2 * 1.15);
            }
        }
        exp1 = exp1 - e1;
    }
    
    exp1 = checkexpfunction(exp1);
    exp2 = checkexpfunction(exp2);
    
    return exp1 + exp2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if ((E2<0) || (E2>99)){
        return -99;
    }
    EXP1 = checkexpfunction(EXP1);
    HP1 = checkhpfunction(HP1);
    M1 = checkgoldfunction(M1);
    int S = nearestsquare(EXP1);
    double P1,P2,P3;
    if (S<=EXP1){
        P1 = 100;
    }
    else {
        P1 = ceil(100*(EXP1/S + 80)/123);
    }
    
    int budget = M1/2;
    int total = 0;
    
    if (M1<=0){
        HP1 = ceil(1.00*HP1 - 0.17*HP1);
        EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
        EXP1 = checkexpfunction(EXP1);
    }
    else{
        while (E2 % 2 != 0) {
            if (HP1<200){
                HP1 = ceil(HP1 * 1.0 + HP1 * 0.3);
                M1 -= 150;
                total += 150;
                HP1 = checkhpfunction(HP1);
                M1 = checkgoldfunction(M1);
                if (total > budget){
                    HP1 = ceil(1.00*HP1 - 0.17*HP1);
                    EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
                    EXP1 = checkexpfunction(EXP1);
                    break;
                }
            }
            else {
                HP1 = ceil(HP1 * 1.0 + HP1 * 0.1);
                M1 -= 70;
                total += 70;
                HP1 = checkhpfunction(HP1);
                M1 = checkgoldfunction(M1);
                if (total > budget){
                    HP1 = ceil(1.00*HP1 - 0.17*HP1);
                    EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
                    EXP1 = checkexpfunction(EXP1);
                    break;
                }
            }
            
            if (EXP1<400){
                M1 -= 200;
                total += 200;
                EXP1 = ceil(EXP1 * 1.0 + EXP1 * 0.13);
                HP1 = checkhpfunction(HP1);
                M1 = checkgoldfunction(M1);
                if (total > budget){
                    HP1 = ceil(1.00*HP1 - 0.17*HP1);
                    EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
                    EXP1 = checkexpfunction(EXP1);
                    break;
                }
            }
            else {
                M1 -= 120;
                total += 120;
                EXP1 = ceil(EXP1 * 1.0 + EXP1 * 0.13);
                HP1 = checkhpfunction(HP1);
                M1 = checkgoldfunction(M1);
                if (total > budget){
                    HP1 = ceil(1.00*HP1 - 0.17*HP1);
                    EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
                    EXP1 = checkexpfunction(EXP1);
                    break;
                }
            }
            
            if (EXP1<300){
                M1 -= 100;
                total += 100;
                EXP1 = ceil(EXP1 * 1.0 - EXP1 * 0.1);
                HP1 = checkhpfunction(HP1);
                M1 = checkgoldfunction(M1);
                if (total > budget){
                    HP1 = ceil(1.00*HP1 - 0.17*HP1);
                    EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
                    EXP1 = checkexpfunction(EXP1);
                    break;
                }
            }
            else {
                M1 -= 120;
                total += 120;
                EXP1 = ceil(EXP1 * 1.0 - EXP1 * 0.1);
                HP1 = checkhpfunction(HP1);
                M1 = checkgoldfunction(M1);
                if (total > budget){
                    HP1 = ceil(1.00*HP1 - 0.17*HP1);
                    EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
                    EXP1 = checkexpfunction(EXP1);
                    break;
                }
            }
        }
        
        while (E2 % 2 == 0){
            if (HP1<200){
                HP1 = ceil(HP1 * 1.0 + HP1 * 0.3);
                M1 -= 150;
                total += 150;
                HP1 = checkhpfunction(HP1);
                M1 = checkgoldfunction(M1);
                if (M1 == 0){
                    HP1 = ceil(1.00*HP1 - 0.17*HP1);
                    EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
                    EXP1 = checkexpfunction(EXP1);
                    break;
                }
            }
            else {
                HP1 = ceil(HP1 * 1.0 + HP1 * 0.1);
                M1 -= 70;
                total += 70;
                HP1 = checkhpfunction(HP1);
                M1 = checkgoldfunction(M1);
                if (M1 == 0){
                    HP1 = ceil(1.00*HP1 - 0.17*HP1);
                    EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
                    EXP1 = checkexpfunction(EXP1);
                    break;
                }
            }
            
            
            if (EXP1<400){
                M1 -= 200;
                total += 200;
                EXP1 = ceil(EXP1 * 1.0 + EXP1 * 0.13);
                HP1 = checkhpfunction(HP1);
                M1 = checkgoldfunction(M1);
                if (M1 == 0){
                    HP1 = ceil(1.00*HP1 - 0.17*HP1);
                    EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
                    EXP1 = checkexpfunction(EXP1);
                    break;
                }
            }
            else {
                M1 -= 120;
                total += 120;
                EXP1 = ceil(EXP1 * 1.0 + EXP1 * 0.13);
                HP1 = checkhpfunction(HP1);
                M1 = checkgoldfunction(M1);
                if (M1 == 0){
                    HP1 = ceil(1.00*HP1 - 0.17*HP1);
                    EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
                    EXP1 = checkexpfunction(EXP1);
                    break;
                }
            }
            
            if (EXP1<300){
                M1 -= 100;
                total += 100;
                EXP1 = ceil(EXP1 * 1.0 - EXP1 * 0.1);
                HP1 = checkhpfunction(HP1);
                M1 = checkgoldfunction(M1);
                if (M1 == 0){
                    HP1 = ceil(1.00*HP1 - 0.17*HP1);
                    EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
                    EXP1 = checkexpfunction(EXP1);
                    break;
                }
            }
            else {
                M1 -= 120;
                total += 120;
                EXP1 = ceil(EXP1 * 1.0 - EXP1 * 0.1);
                HP1 = checkhpfunction(HP1);
                M1 = checkgoldfunction(M1);
                if (M1 == 0){
                    HP1 = ceil(1.00*HP1 - 0.17*HP1);
                    EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
                    EXP1 = checkexpfunction(EXP1);
                    break;
                }
            }
            HP1 = ceil(1.00*HP1 - 0.17*HP1);
            EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
            EXP1 = checkexpfunction(EXP1);
            break;
        }
    }

    S = nearestsquare(EXP1);
    if (S<=EXP1){
        P2 = 100;
    }
    else {
        P2 = ceil(100*(EXP1/S + 80)/123);
    }

    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    
    if (E2<=9){
        P3 = P[E2];
    }
    else {
        P3 = P[(E2%10+E2/10)%10];
    }
    
    if ((P1==100) && (P2 == 100) && (P3 == 100)){
        EXP1 = ceil(EXP1 * 0.75);
    }
    else {
        int Pfinal = (P1 + P2 + P3)/3;
        if (Pfinal>=50){
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
        }
        else {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        }
    }
    HP1 = checkhpfunction(HP1);
    EXP1 = checkexpfunction(EXP1);
    M1 = checkgoldfunction(M1);
    
    return EXP1 + HP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    //TODO: implement task
    if ((E3<0) || (E3>99)){
        return -99;
    }
    HP1 = checkhpfunction(HP1);
    HP2 = checkhpfunction(HP2);
    EXP1 = checkexpfunction(EXP1);
    EXP2 = checkexpfunction(EXP2);
    int mat[10][10];
    int counti = 0;
    int countj = 0;
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            mat[i][j] = ((E3*j) + (i*2)) * (i-j);
            if (mat[i][j]>E3*2){
                counti += 1;
            }
            if (mat[i][j]<-1*E3){
                countj += 1;
            }
        }
    }
    int ifinal = sumofnum(counti);
    int jfinal = sumofnum(countj);
    
    int point = maxofdiagonal(mat, ifinal, jfinal);
    
    if (point >= abs(mat[ifinal][jfinal])){
        EXP1 = ceil(EXP1 * 1.0 + EXP1 * 0.12);
        EXP2 = ceil(EXP2 * 1.0 + EXP2 * 0.12);
        HP1 = ceil(HP1 * 1.0 + HP1 * 0.1);
        HP2 = ceil(HP2 * 1.0 + HP2 * 0.1);
        HP1 = checkhpfunction(HP1);
        HP2 = checkhpfunction(HP2);
        EXP1 = checkexpfunction(EXP1);
        EXP2 = checkexpfunction(EXP2);
        return point;
    }
    else {
        EXP1 = ceil(EXP1 * 1.0 - EXP1 * 0.12);
        EXP2 = ceil(EXP2 * 1.0 - EXP2 * 0.12);
        HP1 = ceil(HP1 * 1.0 - HP1 * 0.1);
        HP2 = ceil(HP2 * 1.0 - HP2 * 0.1);
        HP1 = checkhpfunction(HP1);
        HP2 = checkhpfunction(HP2);
        EXP1 = checkexpfunction(EXP1);
        EXP2 = checkexpfunction(EXP2);
        return mat[ifinal][jfinal];
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email)
{
    //TODO: implement task
    string a = email;
    unsigned long pos = a.find("@");
    string se = a.substr(0,pos);
    
    string b = s;
    if (b.length()<8){
        return -1;
    }
    
    if (b.length()>20){
        return -2;
    }
    
    int found = b.find(se);
    if (found != string::npos){
        return -1*(300+found);
    }
    
    if (detectcontinuousity(b) != -1){
        return -1*(400+detectcontinuousity(b));
    }
    
    if (!detectspecialletter(b)){
        return -5;
    }
    
    for (int i=0; i<b.length(); i++){
        if (b[i] == 34 || (b[i] >= 38 && b[i] <= 47) || (b[i]>=58 && b[i]<=63) || (b[i]>=91 && b[i] <= 96) || (b[i]>=123 && b[i]<=126)) {
            return i;
        }
    }
    
    
    return -10;
}
   

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    if (num_pwds <= 0) {
            return -1;
    }
    
    int maxfreq = 0;
    unsigned long maxlen = strlen(arr_pwds[0]);
    const char* res;
    
    for (int i=0; i<num_pwds; i++) {
        int freq = 0;
        unsigned long length = strlen(arr_pwds[i]);
        
        for (int j=0; j<num_pwds; j++) {
            if (strcmp(arr_pwds[j], arr_pwds[i]) == 0) {
                freq++;
            }
        }
        
        if ((freq==maxfreq && length>maxlen) || (freq > maxfreq)){
            maxfreq = freq;
            maxlen = length;
            res = arr_pwds[i];
        }
    }
    
    for (int i=0; i<num_pwds; i++) {
        if (strcmp(arr_pwds[i], res) == 0) {
            return i;
        }
    }
    return -1;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
