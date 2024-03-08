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
int Check(double m){
    if (abs(m - (int)(m)) > 1e-9) return ceil(m);
    return (int)(m);
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;
    if (exp1 > 600) exp1 = 600;
    else if (exp1 < 0) exp1 = 0;
    if (exp2 > 600) exp2 = 600;
    else if (exp2 < 0) exp2 = 0;
    if (e1 >= 0 && e1 <= 3){   
        if (e1 == 0) exp2 = exp2 + 29;
        else if (e1 == 1) exp2 = exp2 + 45;
        else if (e1 == 2) exp2 = exp2 + 75;
        else exp2 = exp2 + 149;
        int D(e1*3 + exp1*7);
        if (D%2 == 0) exp1 = Check(exp1 + D/200.0);
        else exp1 = Check(exp1 - D/100.0);
    }
    else if (e1 <= 19){
        exp2 = Check(exp2 + e1/4.0 + 19);
        exp1 = exp1 - e1;
    } 
    else if (e1 <= 49){
        exp2 = Check(exp2 + e1/9.0 + 21); 
        exp1 = exp1 - e1;
    }     
    else if (e1 <= 65){
        exp2 = Check(exp2 + e1/16.0 + 17);
        exp1 = exp1 - e1;
    } 
    else if (e1 <= 79){
        exp2 = Check(exp2 + e1/4.0 + 19);
        if (exp2 > 200) exp2 = Check(exp2 + e1/9.0 + 21);
        exp1 = exp1 - e1;
    }
    else {
        exp2 = Check(exp2 + e1/4.0 + 19);
        exp2 = Check(exp2 + e1/9.0 + 21);
        if (exp2 > 400){
            exp2 = Check(exp2 + e1/16.0 + 17);
            exp2 = Check(exp2 + 0.15*exp2);
        }
        exp1 = exp1 - e1;
    }
    if (exp1 > 600) exp1 = 600;
    else if (exp1 < 0) exp1 = 0;
    if (exp2 > 600) exp2 = 600;
    else if (exp2 < 0) exp2 = 0;
    return exp1 + exp2;
}
// Task 2
int findS(int m){
    if (m == 0) return 0;
    int a = sqrt(m);
    int d1 = m - a*a, d2 = (a + 1)*(a + 1) - m;
    if (d1 < d2) return a*a;
    else return (a + 1)*(a + 1);
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;
    if (HP1 > 666) HP1 = 666;
    else if (HP1 < 0) HP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    else if (EXP1 < 0) EXP1 = 0;
    if (M1 > 3000) M1 = 3000;
    else if (M1 < 0) M1 = 0;
    float P1(1); 
    int S1 = findS(EXP1);
    if (S1 > EXP1) P1 = ((EXP1*1.0)/S1 + 80)/123;
    float a(M1*0.5); int s(0);
    bool sign(true);
    while (sign){
        if (M1 == 0) break;
        if (HP1 < 200){
            HP1 = Check(HP1*1.3);
            M1 = M1 - 150; 
            s = s + 150;
            if (HP1 > 666) HP1 = 666;
            else if (HP1 < 0) HP1 = 0;
            if (M1 > 3000) M1 = 3000;
            else if (M1 < 0) M1 = 0;
        }
        else{
            HP1 = Check(HP1*1.1);
            M1 = M1 - 70; 
            s = s + 70;
            if (HP1 > 666) HP1 = 666;
            else if (HP1 < 0) HP1 = 0;
            if (M1 > 3000) M1 = 3000;
            else if (M1 < 0) M1 = 0;
        }
        if (E2%2 == 1 && a < s) break;
        if (E2%2 == 0 && M1 == 0) break;
        if (EXP1 < 400){
            M1 = M1 - 200;
            s = s + 200;
            if (M1 > 3000) M1 = 3000;
            else if (M1 < 0) M1 = 0;
        }  
        else{
            M1 = M1 - 120;
            s = s + 120;
            if (M1 > 3000) M1 = 3000;
            else if (M1 < 0) M1 = 0;
        }
        EXP1 = Check(EXP1*1.13);
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
        if (E2%2 == 1 && a < s) break;
        if (E2%2 == 0 && M1 == 0) break;
        if (EXP1 < 300){
            M1 = M1 - 100;
            s = s + 100;
            if (M1 > 3000) M1 = 3000;
            else if (M1 < 0) M1 = 0;
        } 
        else {
            M1 = M1 - 120;
            s = s + 120;
            if (M1 > 3000) M1 = 3000;
            else if (M1 < 0) M1 = 0;
        }
        EXP1 = Check(EXP1*0.9);
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
        if (E2%2 == 1 && a < s) sign = false;
        if (E2%2 == 0) sign = false;    
    }
    EXP1 = Check(EXP1*1.17);
    HP1 = Check(HP1*0.83);
    if (HP1 > 666) HP1 = 666;
    else if (HP1 < 0) HP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    else if (EXP1 < 0) EXP1 = 0;
    float P2(1); 
    int S2 = findS(EXP1);
    if (S2 > EXP1) P2 = (EXP1*1.0/S2 + 80)/123;
    float arr[10] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    float P3;
    if (E2/10 == 0) P3 = arr[E2];
    else P3 = arr[(E2/10 + E2%10)%10];
    if (P1 == 1 && P2 == P1 && P3 == P1) EXP1 = Check(EXP1*0.75);
    else {
        if ((P1 + P2 + P3)/3 < 0.5){
            HP1 = Check(HP1*0.85);
            EXP1 = Check(EXP1*1.15);
        }
        else {
            HP1 = Check(HP1*0.9);
            EXP1 = Check(EXP1*1.2);
        }
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
    }
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    if (HP1 > 666) HP1 = 666;
    else if (HP1 < 0) HP1 = 0;
    if (HP2 > 666) HP2 = 666;
    else if (HP2 < 0) HP2 = 0;
    if (EXP1 > 600) EXP1 = 600;
    else if (EXP1 < 0) EXP1 = 0;
    if (EXP2 > 600) EXP2 = 600;
    else if (EXP2 < 0) EXP2 = 0;
    int arr[10][10]; int a(0), b(0);
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            arr[i][j] = (E3*j + i*2)*(i - j);
            if (arr[i][j] > E3*2) a = a + 1;
            if (arr[i][j] < -E3) b = b + 1;
        }
    }
    while (a > 9) {
        a = a/10 + a%10;
    }
    while (b > 9) {
        b = b/10 + b%10;
    }
    int m(arr[a][b]), i(a - 1), j(b - 1); 
    while ((i > -1) && (j > -1)){
        if (m < arr[i][j]) m = arr[i][j];
        i = i - 1;
        j = j - 1;
    }
    i = a + 1; 
    j = b + 1;
    while (i < 10 && j < 10) {
        if (m < arr[i][j]) m = arr[i][j];
        i = i + 1;
        j = j + 1;
    }
    i = a - 1; 
    j = b + 1;
    while (i > -1 && j < 10){
        if (m < arr[i][j]) m = arr[i][j];
        i = i - 1;
        j = j + 1;
    }
    i = a + 1;
    j = b - 1;
    while (i < 10 && j > -1) {
        if (m < arr[i][j]) m = arr[i][j];
        i = i + 1;
        j = j - 1;
    }
    int result;
    if ((abs(arr[a][b]) - abs(m)) > 0){
        HP1 = Check(HP1*0.9); EXP1 = Check(EXP1*0.88);
        HP2 = Check(HP2*0.9); EXP2 = Check(EXP2*0.88);
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        if (HP2 > 666) HP2 = 666;
        else if (HP2 < 0) HP2 = 0;
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
        if (EXP2 > 600) EXP2 = 600;
        else if (EXP2 < 0) EXP2 = 0;
        result = arr[a][b];
    }
    else {
        HP1 = Check(HP1*1.1); EXP1 = Check(EXP1*1.12);
        HP2 = Check(HP2*1.1); EXP2 = Check(EXP2*1.12);
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        if (HP2 > 666) HP2 = 666;
        else if (HP2 < 0) HP2 = 0;
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
        if (EXP2 > 600) EXP2 = 600;
        else if (EXP2 < 0) EXP2 = 0;
        result = abs(m);
    }
    return result;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function 
    char se[100];
    int i(0);
    bool sign(true);
    while (sign && (i < strlen(email))){
        if (email[i] == '@')
        {
            strncpy(se, email, i);
            se[i] = '\0';
            sign = false;
        }
        i = i + 1;
    }
    if (strlen(s) < 8) return -1;
    if (strlen(s) > 20) return -2;
    if (strstr(s, se) != NULL) return -(strstr(s, se) - s + 300);
    for (int i = 0; i < strlen(s) - 2; i++)
    {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) return -(i + 400);
    }
    sign = true;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '@' || s[i] == '%' || s[i] == '#' || s[i] == '!' || s[i] == '$')
        {
            sign = false;
            break;
        }
        
    }
    if (sign) return -5;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '@' || s[i] == '%' || s[i] == '#' || s[i] == '!' || s[i] == '$') continue;
        if (s[i] < 48 || (s[i] > 57 && s[i] < 65) || (s[i] > 90 && s[i] < 97) || s[i] > 122) return i;    
    }
    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function 
    int pos, len, freq(0);
    for (int i = 0; i < num_pwds; i++) {
        int countFreq(0);
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0){
                countFreq = countFreq + 1;
            }
        }
        if (countFreq > freq){
            freq = countFreq;
            len = strlen(arr_pwds[i]);
            pos = i;
        }
        else if (countFreq == freq){
            if (strlen(arr_pwds[i]) > len){
                len = strlen(arr_pwds[i]);
                pos = i;
            }
        }
    }
    return pos;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////