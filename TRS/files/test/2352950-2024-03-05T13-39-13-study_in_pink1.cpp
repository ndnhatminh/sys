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

int update(int input, int lowerbound, int upperbound){
    if (input < lowerbound) return lowerbound;
    else if (input > upperbound) return upperbound;
    else return input;
}

int roundUp(double val) {
    return int(val+0.999);
}

// Task 1
int firstMeetCase1Exp1(int exp1, int e1) {
    int d = e1 * 3 + exp1 * 7;
    if (d % 2 == 0) return roundUp(exp1 + 1.0*d/200);
    else return roundUp(exp1 - 1.0*d/100);
}

int firstMeetCase1Exp2(int exp2, int e1){
    switch (e1) {
        case 0: {
            exp2 += 29;
            break;
        }
        case 1: {
            exp2 += 45;
            break;
        }
        case 2: {
            exp2 += 75;
            break;
        }
        default: {
            exp2 += 149;
            break; 
        }
    }
    return exp2;
}

int firstMeetCase2Exp1(int exp1, int e1){
    return exp1 - e1;
}

int firstMeetCase2Exp2(int exp2, int e1){
    if (e1 <= 19) 
        return roundUp(exp2 + 1.0*e1/4 + 19);
    else if (e1 <= 49) 
        return roundUp(exp2 + 1.0*e1/9 + 21);
    else if (e1 <= 65) 
        return roundUp(exp2 + 1.0*e1/16 + 17);
    else if (e1 <= 79) {
        exp2 = roundUp(exp2 + 1.0*e1/4 + 19);
        if (exp2 > 200) exp2 = roundUp(exp2 + 1.0*e1/9 + 21);
        return exp2;
    }
    else {
        exp2 = roundUp(exp2 + 1.0*e1/4 + 19);
        exp2 = roundUp(exp2 + 1.0*e1/9 + 21);
        if (exp2 > 400) {
            exp2 = roundUp(exp2 + 1.0*e1/16 + 17);
            exp2 = roundUp(exp2 * 1.15);
        }
        return exp2;
    }
}

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    if(e1 < 0 || e1 > 99) return -99;

    exp1 = update(exp1, 0, 600);
    exp2 = update(exp2, 0, 600);

    if (e1 <= 3) {
        exp1 = firstMeetCase1Exp1(exp1, e1);
        exp2 = firstMeetCase1Exp2(exp2, e1);
    }
    else {
        exp1 = firstMeetCase2Exp1(exp1, e1);
        exp2 = firstMeetCase2Exp2(exp2, e1);
    }
    exp1 = update(exp1, 0, 600);
    exp2 = update(exp2, 0, 600);
    return exp1 + exp2;
}

// Task 2

int perfectSquare(int n){
    return (int(sqrt(n) + 0.5))*(int(sqrt(n) + 0.5));
}

float road1(int EXP1){
    int s = perfectSquare(EXP1);
    if (EXP1 >= s) return 1;
    else return (1.0*EXP1/s + 80)/123;
}

void function1(int & HP1, int & M1, int & pay) {
    if (HP1 < 200){
        HP1 = roundUp(HP1 * 1.3);
        M1 -= 150;
        pay += 150;
    }
    else {
        HP1 = roundUp(HP1 * 1.1);
        M1 -= 70;
        pay += 70;
    }
    HP1 = update(HP1, 0, 666);
    M1 = update(M1, 0, 3000);
}

void function2(int & EXP1, int & M1, int & pay) {
    if (EXP1 < 400) {
        M1 -= 200;
        pay += 200;
    }
    else {
        M1 -= 120;
        pay += 120;
    }
    M1 = update(M1, 0, 3000);
    EXP1 = update(roundUp(EXP1 * 1.13), 0, 600);
}

void function3(int & EXP1, int & M1, int & pay){
    if (EXP1 < 300) {
        M1 -= 100;
        pay += 100;
    }
    else {
        M1 -= 120;
        pay += 120;
    }
    M1 = update(M1, 0, 3000);
    EXP1 = roundUp(EXP1 * 0.9);
}

bool checkMoney(int money, int pay){
    return pay > money;
}

void oddE2(int & HP1, int & EXP1, int & M1, int money, int & pay){
    while(M1){
        function1(HP1, M1, pay);
        if(checkMoney(money, pay)) break;
        function2(EXP1, M1, pay);
        if(checkMoney(money, pay)) break;
        function3(EXP1, M1, pay);
        if(checkMoney(money, pay)) break;
    }
}

void evenE2(int & HP1, int & EXP1, int & M1, int & pay){
    if (M1 > 0) function1(HP1, M1, pay);
    else return;
    if (M1 > 0) function2(EXP1, M1, pay);
    else return;
    if (M1 > 0) function3(EXP1, M1, pay);
    else return;
}

float road2(int & HP1, int & EXP1, int & M1, int E2){
    float money = 0.5 * M1;
    int pay = 0;
    if (M1 != 0) {
        if (E2 % 2 != 0) oddE2(HP1, EXP1, M1, money, pay);
        else evenE2(HP1, EXP1, M1, pay);
    }
    HP1 = roundUp(HP1 * 0.83);
    EXP1 = update(roundUp(EXP1 * 1.17), 0, 600);
    return road1(EXP1);
}

int sumDigitNumber(int n){
    int sum = 0;
    while(n != 0) {
        sum += (n % 10);
        n /=10;
    }
    return sum;
}

int road3(int E2){
    int p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 <= 9) return p[E2];
    else return p[sumDigitNumber(E2)%10];
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 < 0 || E2 > 99) return -99;

    HP1 = update(HP1, 0, 666);
    EXP1 = update(EXP1, 0, 600);
    M1 = update(M1, 0, 3000);
    
    float average = (road1(EXP1) + road2(HP1, EXP1, M1, E2) + 1.0*road3(E2)/100)/3;
    if (average == 1) EXP1 = roundUp(EXP1 * 0.75);
    else if (average < 0.5) {
        HP1 = roundUp(HP1 * 0.85);
        EXP1 = update(roundUp(EXP1 * 1.15), 0, 600);
    }
    else {
        HP1 = roundUp(HP1 * 0.9);
        EXP1 = update(roundUp(EXP1 * 1.2), 0, 600);
    }
    return HP1 + EXP1 + M1;
}

// Task 3

void arrayTaxi(int arr[][10], int E3){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            arr[i][j] = ((E3*j) + (i*2))*(i-j);
        }
    }
}

int numberOfDigit(int n){
    int sum = 0;
    while(n!=0){
        sum += n%10;
        n/=10;
    }
    if (sum <= 9) return sum;
    return numberOfDigit(sum);
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 < 0 || E3 > 99) return -99;

    HP1 = update(HP1, 0, 666);
    HP2 = update(HP2, 0, 666);
    EXP1 = update(EXP1, 0, 600);
    EXP2 = update(EXP2, 0, 600);
    

    int arr[10][10] = {0};
    arrayTaxi(arr, E3);

    int greater = 0, smaller = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if (arr[i][j] > E3 * 2) greater++;
            if (arr[i][j] < -E3) smaller++;
        }
    }

    int a = numberOfDigit(greater), b = numberOfDigit(smaller);
    int max = INT_MIN;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(i + j == a + b || i - j == a - b) 
                if (max < arr[i][j]) max = arr[i][j];
        }
    }
    if (abs(arr[a][b]) > max) {
        HP1 = update(roundUp(HP1 * 0.9), 0, 666);
        HP2 = update(roundUp(HP2 * 0.9), 0, 666);
        EXP1 = update(roundUp(EXP1 * 0.88), 0, 600);
        EXP2 = update(roundUp(EXP2 * 0.88), 0, 600);
        return arr[a][b];
    }
    else {
        HP1 = update(roundUp(HP1 * 1.1), 0, 666);
        HP2 = update(roundUp(HP2 * 1.1), 0, 666);
        EXP1 = update(roundUp(EXP1 * 1.12), 0, 600);
        EXP2 = update(roundUp(EXP2 * 1.12), 0, 600);
        return max;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    if (strlen(s) < 8) return -1;

    if (strlen(s) > 20) return -2;

    string se;
    for(int i = 0; email[i] != '@'; i++) se += email[i];
    if (strstr(s, se.c_str()) != NULL){
        return -300 - (int)(strstr(s, se.c_str()) -s);
    }

    for(int i = 2; i < strlen(s); i++){
        if (s[i] == s[i - 1] && s[i] == s[i-2]) {
            return -400 - (i-2);
        }
    }

    int count = 0;
    for(int i = 0; i < strlen(s); i++){
        if (!(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))
            count++;
    }
    if (count == strlen(s)) return -5;
    
    for(int i = 0; i < strlen(s); i++){
        if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ||
        s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))
            return i;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_count = 0, max_length = 0, correct_index = -1;

    for(int i = 0; i < num_pwds; i++){
        int count = 0, length = strlen(arr_pwds[i]);
        for(int j = 0; j < num_pwds; j++){
            if (!strcmp(arr_pwds[j], arr_pwds[i])) count++;
        }
        if(count > max_count || (length > max_length && count == max_count)){
            max_count = count;
            max_length = length;
            correct_index = i;
        }
    }
    return correct_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////