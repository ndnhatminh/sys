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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 >=0 && e1 <=99){
    if (e1>=0 && e1 <=3){
        int D = e1 * 3 + exp1 * 7;
        if (e1 == 0){
            exp2=exp2 + 29;
        }
        if (e1 == 1){
            exp2=exp2 + 45;
        }
        if(e1 == 2){
            exp2=exp2 + 75;
        }
        if (e1 == 3){
            exp2 = exp2 + 29 + 45 + 75;
        }
        if ( D % 2 == 0){
                float exp11=exp1 + (D/200.0);
                exp1 = ceil(exp11);
        }
        else{
                float exp12=exp1 - (D/100.0);
                exp1 = ceil(exp12);
        }
        
    }
    if (exp2>600 ){
        exp2 = 600;
    }
    if (exp2<0 ){
        exp2 = 0;
    }
    if (exp1>600 ){
        exp1 = 600;
    }
    if (exp1<0 ){
        exp1 = 0;
    }
    if (e1>=4 && e1 <=99){
    if (e1>=4 && e1<=19){
        float exp21 = exp2 + (e1/4.0+19);
        exp2 = ceil(exp21);
    }
    if (e1>=20 && e1<=49){
        float exp21=exp2 + (e1/9.0+21);
        exp2 = ceil(exp21);
    }
    if (e1>=50 && e1<=65){
        float exp21=exp2 + (e1/16.0+17);
        exp2 = ceil(exp21);
    }
    if (e1>=66 && e1<=79){
        int exp21=ceil(exp2 + (e1/4.0+19));
        if (exp21>200){
            exp2=ceil(exp21 + (e1/9.0+21));
        }
        else{
            exp2=exp21+0;
        }
    }
    if (e1>=80 && e1<=99){
        int exp21=ceil(exp2 + (e1/4.0+19));
        int exp22=ceil(exp21 + (e1/9.0+21));
        if (exp22>400){
            int exp23=ceil(exp22 + (e1/16.0+17));
            exp2=ceil(exp23+exp23*0.15);
        }
        else{
            exp2=exp22+0;
        }
    }
    exp1 = exp1 - e1;
    if (exp2>600 ){
        exp2 = 600;
    }
    if (exp2<0 ){
        exp2 = 0;
    }
    if (exp1>600 ){
        exp1 = 600;
    }
    if (exp1<0 ){
        exp1 = 0;
    }
 
    }
    return exp1 + exp2;
    }
    else {
        return -99;
    }
}

// Task 2
int findS(int n) {
    int squareRoot = static_cast<int>(sqrt(n));
    int lowerS = squareRoot * squareRoot;
    int upperS = (squareRoot + 1) * (squareRoot + 1);

    if (abs(n - lowerS) < abs(n - upperS)) {
        return lowerS;
    } else {
        return upperS;
    }
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
if (E2 >=0 && E2 <=99){
if (EXP1>600 ){
    EXP1 = 600;
}
if (EXP1<0 ){
    EXP1 = 0;
}
if (HP1>666 ){
     HP1 = 666;
}
if (HP1<0 ){
    HP1 = 0;
}
if (M1>3000 ){
    M1 = 3000;
}
if (M1<0 ){
    M1 = 0;
}
int S = findS(EXP1);
float P1;
if (EXP1>=S){
    P1 = 1.0;
}
else {
    float P11=(EXP1/(S*1.0) + 80);
    P1=P11/123;
    
}
if (E2 % 2 == 1) {
float stop = M1/2;
while (M1>stop && M1>0){
if (HP1 < 200) {
    float HP11 = HP1 + 0.3 * HP1;
    HP1 = ceil(HP11);
    M1 -= 150;
} 
else {
    float HP11 = HP1 + 0.1 * HP1;
    HP1 = ceil(HP11);
    M1 -= 70;
}
if (HP1>666 ){
     HP1 = 666;
}
if (HP1<0 ){
    HP1 = 0;
}
if (M1>3000 ){
    M1 = 3000;
}
if (M1<0 ){
    M1 = 0;
}
if (M1 <= stop || M1 <= 0) {
    break;
}
if (EXP1 < 400) {
    M1 -= 200;
    float EXP11 = EXP1 + 0.13 * EXP1;
    EXP1 = ceil(EXP11);
} 
else {
    M1 -= 120;
    float EXP11 = EXP1 + 0.13 * EXP1;
    EXP1 = ceil(EXP11);
}
if (EXP1>600 ){
    EXP1 = 600;
}
if (EXP1<0 ){
    EXP1 = 0;
}
if (M1>3000 ){
    M1 = 3000;
}
if (M1<0 ){
    M1 = 0;
}
if (M1 <= stop || M1 <= 0) {
    break;
}
if (EXP1 < 300) {
    M1 -= 100;
    float EXP11 = EXP1 *0.9;
    EXP1 = ceil(EXP11);
} 
else {
    M1 -= 120;
    float EXP11 = EXP1 *0.9;
    EXP1 = ceil(EXP11);
}
if (EXP1>600 ){
    EXP1 = 600;
}
if (EXP1<0 ){
    EXP1 = 0;
}
if (M1>3000 ){
    M1 = 3000;
}
if (M1<0 ){
    M1 = 0;
}
if (M1 <= stop || M1 <= 0) {
    break;
}
}
float HP11 = HP1 - 0.17 * HP1;
HP1 = ceil(HP11);
if (HP1>666 ){
     HP1 = 666;
}
if (HP1<0 ){
    HP1 = 0;
}
float EXP11 = EXP1 + 0.17 * EXP1;
EXP1 = ceil(EXP11);
if (EXP1>600 ){
    EXP1 = 600;
}
if (EXP1<0 ){
    EXP1 = 0;
}
}
if (E2 % 2 == 0){
while ( M1 > 0 ){
    if (HP1 < 200) {
    float HP11 = HP1 + 0.3 * HP1;
    HP1 = ceil(HP11);
    M1 -= 150;
} 
else {
    float HP11 = HP1 + 0.1 * HP1;
    HP1 = ceil(HP11);
    M1 -= 70;
}
if (HP1>666 ){
     HP1 = 666;
}
if (HP1<0 ){
    HP1 = 0;
}
if (M1>3000 ){
    M1 = 3000;
}
if (M1<0 ){
    M1 = 0;
}
if (M1 <= 0){
    break;
}
if (EXP1 < 400) {
    M1 -= 200;
    float EXP11 = EXP1 + 0.13 * EXP1;
    EXP1 = ceil(EXP11);
} 
else {
    M1 -= 120;
    float EXP11 = EXP1 + 0.13 * EXP1;
    EXP1 = ceil(EXP11);
}
if (EXP1>600 ){
    EXP1 = 600;
}
if (EXP1<0 ){
    EXP1 = 0;
}
if (M1>3000 ){
    M1 = 3000;
}
if (M1<0 ){
    M1 = 0;
}
if (M1 <= 0){
    break;
}
if (EXP1 < 300) {
    M1 -= 100;
    float EXP11 = EXP1 *0.9;
    EXP1 = ceil(EXP11);
} 
else {
    M1 -= 120;
    float EXP11 = EXP1 *0.9;
    EXP1 = ceil(EXP11);
}
if (EXP1>600 ){
    EXP1 = 600;
}
if (EXP1<0 ){
    EXP1 = 0;
}
if (M1>3000 ){
    M1 = 3000;
}
if (M1<0 ){
    M1 = 0;
}
if (M1 <= 0){
    break;
}
break;
}
float HP11 = HP1 - 0.17 * HP1;
HP1 = ceil(HP11);
if (HP1>666 ){
     HP1 = 666;
}
if (HP1<0 ){
    HP1 = 0;
}
float EXP11 = EXP1 + 0.17 * EXP1;
EXP1 = ceil(EXP11);
if (EXP1>600 ){
    EXP1 = 600;
}
if (EXP1<0 ){
    EXP1 = 0;
}
}
S = findS(EXP1);
float P2;
if (EXP1>=S){
    P2 = 1.0;
}
else {
float P21=(EXP1/(S*1.0) +80);
P2=P21/123; 
}
float P[10] = {0.32, 0.47, 0.28, 0.79, 1.0, 0.5, 0.22, 0.83, 0.64, 0.11};
int i=0;
if (E2 < 10) {
    i = E2;
} 
else {
    i = (E2 % 10) + (E2 / 10);
    i %= 10;
}
float P3 = P[i];
float sum = P1 + P2 + P3;
float Pf = sum / 3;
if (Pf == 1){
    EXP1=ceil(EXP1*0.75);
}
if (Pf < 0.5) {
    HP1 =ceil(HP1*0.85);
    EXP1=ceil(EXP1*1.15);
}
if (Pf >=0.5 && Pf < 1){
    HP1 = ceil(HP1*0.9);
    EXP1 = ceil(EXP1*1.2);
}
if (EXP1>600 ){
    EXP1 = 600;
}
if (EXP1<0 ){
    EXP1 = 0;
}
if (HP1>666 ){
     HP1 = 666;
}
if (HP1<0 ){
    HP1 = 0;
}
if (M1>3000 ){
    M1 = 3000;
}
if (M1<0 ){
    M1 = 0;
}
    return HP1 + EXP1 + M1;
}
else {
    return -99;
}
}
// Task 3
//createMap
void Map(int m[10][10], int E3){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            m[i][j]=((E3 * j) + (i * 2)) * (i - j);
        }
    }
}
//meeting_point
int cordinate (int c){
    while (c >= 10){
        c = c % 10 + c / 10;
    }
    return c;
}
void meeting_point(int m [10][10], int E3, int &rmp, int &cmp){
    rmp = 0;
    cmp = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (m[i][j] > E3 * 2){
                rmp ++;
            }
            if  (m[i][j] < -E3){
                cmp++;
            }
        }
    }

}
//findMax
int findMax(int m[10][10], int r, int c){
    int max = m[r][c];

    // Check diagonally right-down
    for (int i = r + 1, j = c + 1; i < 10 && j < 10; i++, j++) {
        if (m[i][j] > max) {
            max = m[i][j];
        }
    }

    // Check diagonally left-up
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
        if (m[i][j] > max) {
            max = m[i][j];
        }
    }

    // Check diagonally right-up
    for (int i = r + 1, j = c - 1; i < 10 && j >= 0; i++, j--) {
        if (m[i][j] > max) {
            max = m[i][j];
        }
    }

    // Check diagonally left-down
    for (int i = r - 1, j = c + 1; i >= 0 && j < 10; i--, j++) {
        if (m[i][j] > max) {
            max = m[i][j];
        }
    }

    return max;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3>=0 && E3<=99){
    int m[10][10];
    Map (m, E3);
    int rmp, cmp;
    meeting_point (m,E3,rmp,cmp);
    rmp = cordinate(rmp);
    cmp = cordinate(cmp);
    int current_point = findMax(m, rmp, cmp);
    int taxi_point = abs( m[rmp][cmp]);
    int realTaxi = m[rmp][cmp];
    int return_point = current_point;
    if (current_point >= taxi_point){
        EXP1 = ceil((double)EXP1 * 1.12);
        HP1 = ceil((double)HP1 * 1.1);
        EXP2 = ceil((double)EXP2 * 1.12);
        HP2 = ceil((double)HP2 * 1.1);
    }
    else{
        EXP1 = ceil((double)EXP1 * 0.88);
        HP1 = ceil((double)HP1 * 0.9);
        EXP2 = ceil((double)EXP2 * 0.88);
        HP2 = ceil((double)HP2 * 0.9);
        return_point = realTaxi;
    }

    return return_point;
}
    else {
        return -99;
}
}
// Task 4
bool isSpChar(char c) {
    return (c == '@' || c == '#' || c == '%' || c == '$' || c == '!');
}

int checkPassword(const char* s, const char* email) {
    size_t PassSize = strlen(s);
    bool TooShort = (PassSize < 8);
    if (TooShort) {
        return -1;
    }
    bool TooLong = (PassSize > 20);
    if (TooLong) {
        return -2;
    }
    bool haveSpChar = false;
    for (const char *c = s; *c != '\0'; ++c) {
        if (*c == '@' || *c == '#' || *c == '%' || *c == '$' || *c == '!') {
            haveSpChar = true;
            break;
        }
    }
    if (!haveSpChar) {
        return -5;
    }
    size_t pos = 0;
    char se[101];
    while (email[pos] != '@' && email[pos] != '\0' && pos < 100) {
        se[pos] = email[pos];
        ++pos;
    }
    se[pos] = '\0';
    bool containsSe = (strstr(s, se) != nullptr);
    if (containsSe) {
        return -(300 + static_cast<int>(strstr(s, se) - s));
    }
    for (size_t i = 0; i < PassSize - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + static_cast<int>(i));
        }
    }
    bool hasSpChar = false;
    for (size_t i = 0; i < PassSize; ++i) {
        if (isSpChar(s[i])) {
            hasSpChar = true;
            break;
        }
    }
    if (!hasSpChar) {
        return -5;
    }

    for (size_t i = 0; i < PassSize; ++i) {
        if (!isalnum(s[i]) && !isSpChar(s[i])) {
            return static_cast<int>(i);
        }
    }

    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxFrequency = 0;
    int maxLength = 0;
    int result;

    for (int i = 0; i < num_pwds; ++i) {
        const char* currentPass = arr_pwds[i];
        int currentLength = strlen(currentPass);
        int currentFrequency = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(currentPass, arr_pwds[j]) == 0) {
                ++currentFrequency;
            }
        }

        // Check if the current password is correct based on frequency and length
        if (currentFrequency > maxFrequency || 
           (currentFrequency == maxFrequency && currentLength > maxLength)) {
            maxFrequency = currentFrequency;
            maxLength = currentLength;
            result = i;
        }
    }

    return result;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////