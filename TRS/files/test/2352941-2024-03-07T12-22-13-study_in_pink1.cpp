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
void check_EXP(int & exp1, int & exp2){
    if(exp1 < 0) exp1 = 0;
    else if(exp1 > 600) exp1 = 600;
    if(exp2 < 0) exp2 = 0;
    else if(exp2 > 600) exp2 = 600;
}
int firstMeet(int & exp1, int & exp2, int e1) 
{
    // TODO: Complete this function
    if(e1 < 0 || e1 > 99){
        return -99;
    } else {
        check_EXP(exp1, exp2);
        if(e1 >=0 && e1 <=3)
    {
        if(e1 == 0)
        {
            exp2 = exp2 + 29;
            check_EXP(exp1, exp2);
        }
        if(e1 == 1)
        {
            exp2 = exp2 + 45;
            check_EXP(exp1, exp2);
        }
        if(e1 == 2)
        {
            exp2 = exp2 + 75;
            check_EXP(exp1, exp2);
        }
        if(e1 == 3)
        {
            exp2 = exp2 + 29 + 45 + 75;
            check_EXP(exp1, exp2);
        }
        int D = e1*3 + exp1*7;
        if(D%2==0)
        {
            exp1 = ceil(exp1 + 1.00*D/200);
            check_EXP(exp1, exp2);
        }else{
            exp1 = ceil(exp1 - 1.00*D/100);
            check_EXP(exp1, exp2);
        }
    } else { 
        if(e1 >= 4 && e1 <= 99)
        {
            if(e1 >= 4 && e1 <= 19){
                exp2 = ceil(exp2 + 1.00*e1/4 + 19);
                check_EXP(exp1, exp2);
            }
            if(e1 >= 20 && e1 <= 49){
               exp2 = ceil(exp2 + 1.00*e1/9 + 21);
               check_EXP(exp1, exp2);
            }
            if(e1 >= 50 && e1 <= 65){
                exp2 = ceil(exp2 + 1.00*e1/16 + 17);
                check_EXP(exp1, exp2);
            }
            if(e1 >= 66 && e1 <= 79){
                exp2 = ceil(exp2 + 1.00*e1/4 + 19);
                check_EXP(exp1, exp2);
                if(exp2 > 200){
                    exp2 = ceil(exp2 + 1.00*e1/9 + 21);
                    check_EXP(exp1, exp2);
                }
            }
            if(e1 >= 80 && e1 <= 99){
                exp2 = ceil(exp2 + 1.00*e1/4 + 19);
                check_EXP(exp1, exp2);
                exp2 = ceil(exp2 + 1.00*e1/9 + 21);
                check_EXP(exp1, exp2);
                if(exp2 > 400){
                    exp2 = ceil(exp2 + 1.00*e1/16 + 17);
                    check_EXP(exp1, exp2);
                    exp2 = ceil(1.00*exp2*1.15);
                    check_EXP(exp1, exp2);
                }
            }
            exp1 = exp1 - e1;
        }
    }
    }
    check_EXP(exp1, exp2);
    return exp1 + exp2;
}

// Task 2
int perfectsquare(int &EXP1)
{
    int sqrt_exp = sqrt(EXP1);
    if(sqrt_exp*sqrt_exp == EXP1){
        return EXP1;
    }else{
        if(sqrt_exp*sqrt_exp > EXP1){
            int n = sqrt_exp - 1;
            if(sqrt_exp*sqrt_exp - EXP1 > EXP1 - n*n){
                return n*n;
            }else{
                return sqrt_exp*sqrt_exp;
            }
        }else{
            int t = sqrt_exp + 1;
            if(EXP1 - sqrt_exp*sqrt_exp > t*t - EXP1){
                return t*t;
            }else{
            return sqrt_exp*sqrt_exp;
            }
        }
    }
}

void checkexp(int & EXP1, int & HP1){
    if(EXP1 < 0) EXP1 = 0;
    else if(EXP1 > 600) EXP1 = 600;
    if(HP1 < 0) HP1 = 0;
    else if(HP1 > 666) HP1 = 666;
}

void checkMoney(int & M1){
    if(M1 < 0) M1 = 0;
    else if(M1 > 3000) M1 = 3000;
}

int calculate_I(int E2) {
    if (E2 < 10) {
        return E2;
    } else {
        return (E2 / 10 + E2 % 10) % 10;
    }
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 < 0 || E2 > 99){
        return -99;
    }
    checkexp(EXP1, HP1);
    checkMoney(M1);
    double P1, P2;
    // 1
    int S = perfectsquare(EXP1);
    float a = M1*0.5;
    float b = 0;
    if(EXP1 >= S){
        P1 = 1.0;
    }else{
        P1 = (1.00*EXP1/S +80)/123;
    }
    // 2
    if(M1 != 0){
    //e2 le
    while(E2 % 2 != 0){
    if(HP1 < 200){
        checkexp(EXP1, HP1);
        HP1 = ceil(1.00*HP1 + 0.3*HP1);
        M1 = M1 - 150;
        b += 150;
        checkexp(EXP1, HP1);
        checkMoney(M1);
         if(b > a)
    {
        HP1 = ceil(1.00*HP1 - 0.17*HP1);
        EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
        checkexp(EXP1, HP1);
        break;
    }
    }else{
        checkexp(EXP1, HP1);
        HP1 = ceil(1.00*HP1 + 0.1*HP1);
        M1 = M1 - 70;
        b += 70;
        checkexp(EXP1, HP1);
        checkMoney(M1);
        if(b > a)
    {
        HP1 = ceil(1.00*HP1 - 0.17*HP1);
        EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
        checkexp(EXP1, HP1);
        break;
    }
    }
    if(EXP1 < 400){
        checkexp(EXP1, HP1);
        M1 = M1 - 200;
        b += 200;
        EXP1 = ceil(1.00*EXP1 + EXP1 * 0.13);
        checkexp(EXP1, HP1);
        checkMoney(M1);
        if(b > a)
    {
        HP1 = ceil(1.00*HP1 - 0.17*HP1);
        EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
        checkexp(EXP1, HP1);
        break;
    }
    }else{
        checkexp(EXP1, HP1);
        M1 = M1 - 120;
        b += 120;
        EXP1 = ceil(1.00*EXP1 + EXP1 * 0.13);
        checkexp(EXP1, HP1);
        checkMoney(M1);
        if(b > a)
    {
        HP1 = ceil(1.00*HP1 - 0.17*HP1);
        EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
        checkexp(EXP1, HP1);
        break;
    }
    }
    if(EXP1 < 300){
        checkexp(EXP1, HP1);
        M1 = M1 - 100;
        b += 100;
        EXP1 = ceil(1.00*EXP1 - 0.1*EXP1);
        checkexp(EXP1, HP1);
        checkMoney(M1);
        if(b > a)
    {
        HP1 = ceil(1.00*HP1 - 0.17*HP1);
        EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
        checkexp(EXP1, HP1);
        break;
    }
    }else{
        checkexp(EXP1, HP1);
        M1 = M1 -120;
        b+= 120;
        EXP1 = ceil(1.00*EXP1 - 0.1*EXP1);
        checkexp(EXP1, HP1);
        checkMoney(M1);
        if(b > a)
    {
        HP1 = ceil(1.00*HP1 - 0.17*HP1);
        EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
        checkexp(EXP1, HP1);
        break;
    }
    }
    }
    // e2 chan
    if(E2 % 2 == 0)
    {
        for (int c = 0; c < 1; c++){
    if(HP1 < 200){
        checkexp(EXP1, HP1);
        HP1 = ceil(1.00*HP1 + 0.3*HP1);
        M1 = M1 - 150;
        checkexp(EXP1, HP1);
        checkMoney(M1);
        if(M1 <= 0)
    {
        HP1 = ceil(1.00*HP1 - 0.17*HP1);
        EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
        checkexp(EXP1, HP1);
        checkMoney(M1);
        break;
    }
    }else{
        checkexp(EXP1,HP1);
        HP1 = ceil(1.00*HP1 + 0.1*HP1);
        M1 = M1 - 70;
        checkexp(EXP1, HP1);
        checkMoney(M1);
        if(M1 <= 0)
    {
        HP1 = ceil(1.00*HP1 - 0.17*HP1);
        EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
        checkexp(EXP1, HP1);
        checkMoney(M1);
        break;
    }
    }
    if(EXP1 < 400){
        checkexp(EXP1, HP1);
        M1 = M1 - 200;
        EXP1 = ceil(1.00*EXP1 + EXP1 * 0.13);
        checkexp(EXP1, HP1);
        checkMoney(M1);
       if(M1 <= 0)
    {
        HP1 = ceil(1.00*HP1 - 0.17*HP1);
        EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
        checkexp(EXP1, HP1);
        checkMoney(M1);
        break;
    }
    }else{
        checkexp(EXP1,HP1);
        M1 = M1 - 120;
        EXP1 = ceil(1.00*EXP1 + EXP1 * 0.13);
        checkexp(EXP1, HP1);
        checkMoney(M1);
       if(M1 <= 0)
    {
        HP1 = ceil(1.00*HP1 - 0.17*HP1);
        EXP1 = ceil(1.00*EXP1 + EXP1 * 0.17);
        checkexp(EXP1, HP1);
        checkMoney(M1);
        break;
    }
    }
    if(EXP1 < 300){
        checkexp(EXP1,HP1);
        M1 = M1 - 100;
        EXP1 = ceil(1.00*EXP1 - 0.1*EXP1);
        checkexp(EXP1, HP1);
        checkMoney(M1);
    }else{
        checkexp(EXP1,HP1);
        M1 = M1 - 120;
        EXP1 = ceil(1.00*EXP1 - 0.1*EXP1);
        checkexp(EXP1, HP1);
        checkMoney(M1);
    }
        HP1 = ceil(1.0*HP1 - HP1*0.17);
        EXP1 = ceil(1.0*EXP1 + EXP1*0.17);
        checkexp(EXP1, HP1);
    }
    }
    }else{
        HP1 = ceil(1.0*HP1 - HP1*0.17);
        EXP1 = ceil(1.0*EXP1 + EXP1*0.17);
        checkexp(EXP1, HP1);
    }
    int N = perfectsquare(EXP1);
    if(EXP1 >= N){
        P2 = 1.0;
    }else{
        P2 = (1.00*EXP1/S +80)/123;
    }
    // 3
    double Pi[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = calculate_I(E2);
    double P3 = Pi[i]/100.0;
    // luggage found
    if(P1 == 1.0 && P2 == 1.0 && P3 == 1.0){
        EXP1 = ceil(1.00*EXP1 - 0.25*EXP1);
        checkexp(EXP1, HP1);
    }else{
        double p = (P1 + P2 + P3)/3;
        if(p < 0.5){
            HP1 = ceil(1.00*HP1 - 0.15*HP1);
            EXP1 = ceil(1.00*EXP1 + 0.15*EXP1);
            checkexp(EXP1, HP1);
        }else{
            HP1 = ceil(1.00*HP1 - 0.1*HP1);
            EXP1 = ceil(1.00*EXP1 + 0.2*EXP1);
            checkexp(EXP1, HP1);
        }
    }
    return HP1 + EXP1 + M1;
}


// Task 3
int findmax(int matrix[10][10], int r, int c){
    int a = r + c;
    int b = r - c;
    int MAX = matrix[r][c];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(i + j == a){
                if(MAX < matrix[i][j]){
                    MAX = matrix[i][j];
                }
            }
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(i - j == b){
                 if(MAX < matrix[i][j]){
                    MAX = matrix[i][j];
                }
            }
        }
    }
    return MAX;
}
int calculate(int n) {
    if (n < 10) {
        return n;
    } else {
        return calculate((n / 10 + n % 10));
    }
}
void checkexp2(int & EXP2, int & HP2){
    if(EXP2 < 0) EXP2 = 0;
    else if(EXP2 > 600) EXP2 = 600;
    if(HP2 < 0) HP2 = 0;
    else if(HP2 > 666) HP2 = 666;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3){
    // TODO: Complete this function
    if(E3 < 0 || E3 > 99){
        return -99;
    }
    checkexp(EXP1, HP1);
    checkexp2(EXP2, HP2);
    int a, b;
    int ROW = 0;
    int COL = 0;
    int matrix[10][10];
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if(matrix[i][j] > 1.0*E3*2) ROW++;
            if(matrix[i][j] < -1.0*E3) COL++;
    }
    }
    a = calculate(ROW);
    b = calculate(COL);
    int max = findmax(matrix, a, b);
    if(max >= abs(matrix[a][b])){
        EXP1 = ceil(1.00*EXP1 + EXP1*0.12);
        HP1 = ceil(1.00*HP1 + HP1*0.1);
        EXP2 = ceil(1.00*EXP2 + EXP2*0.12);
        HP2 = ceil(1.00*HP2 + HP2*0.1);
        checkexp(EXP1, HP1);
        checkexp2(EXP2, HP2);
        return max;
    }else{
        EXP1 = ceil(1.00*EXP1 - EXP1*0.12);
        HP1 = ceil(1.00*HP1 - HP1*0.1);
        EXP2 = ceil(1.00*EXP2 - EXP2*0.12);
        HP2 = ceil(1.00*HP2 - HP2*0.1);
        checkexp(EXP1, HP1);
        checkexp2(EXP2, HP2);
        return matrix[a][b];
    }
    return -1;
}

// Task 4
bool specialchar(string s){
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'){
        return true;
        }
    }
    return false;
}
bool check_valid_specialchar(char x) {
    string special_char="@#%$!";
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (x == special_char[i]) {
            return 1;
        }
    }
    return 0;
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string input = email;
    string pass = s;

    int sub = input.find('@');
    string se = input.substr(0,sub);

    if(pass.length() < 8){
        return -1;
    }else if(pass.length() > 20){
        return -2;
    }
    int a = pass.find(se);
    if (a != string::npos) { 
       return -1 * (300 + a);
    }
       for(int i = 0; i < pass.length(); i++){
        if(pass[i] == pass[i+1] && pass[i+1] == pass[i+2]){
            return -1 * (400 + i);
        }
    }
    if(!(specialchar(pass))){
        return -5;
    }
    for(int i = 0; i < pass.length(); i++){
        if((int)pass[i]>=48 && (int)pass[i]<=57) 
            continue;
        else if((int)pass[i]>=65 && (int)pass[i]<=90) 
            continue;
        else if((int)pass[i]>=97 && (int)pass[i]<=122) 
            continue;
        else if(check_valid_specialchar(pass[i])==1) 
            continue;
        else 
            return i;
    }
        return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int count_max = 1;
    int position = 0;
    for(int i = 0; i < num_pwds; i++){
        int count = 1;
        for(int j = i+1; j < num_pwds; j++){
            if(strcmp(arr_pwds[i],arr_pwds[j]) == 0) count++;
        }
    if (count > count_max){
        count_max = count;
        position = i;
    }
    else if (count == count_max && strlen(arr_pwds[i]) > strlen(arr_pwds[position])){
        position = i;
    }
}
    return position;
}
    

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////