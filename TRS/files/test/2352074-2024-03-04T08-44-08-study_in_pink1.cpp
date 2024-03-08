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
    // DO NOT MODIFY THIS FUNCTION
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


int limitHp(int & hp){
    if (hp > 666){
        hp = 666;
    }
    if (hp < 0){
        hp = 0;
    }
    return hp;
}
int limitExp (int & exp){
    if (exp > 600){
        exp = 600;
    }
    if (exp < 0){
        exp = 0;
    }
    return exp;
}

int limitMoney(int & m){
    if (m > 3000){
        m = 3000;
    }
    if (m < 0){
        m = 0;
    }
    return m;
}

bool limitE(int e) {
    if (e >= 0 && e <= 99) {
        return true;
    } else
        return false;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // Case 1:
    if (!(limitE(e1))){
        return -99;
    }
    limitExp (exp1);
    limitExp (exp2);
    if (e1 <= 3) {
        switch (e1) {
            case 0:
                exp2 += 29;
                limitExp(exp2);
                break;
            case 1:
                exp2 += 45;
                limitExp(exp2);
                break;
            case 2:
                exp2 += 75;
                limitExp(exp2);
                break;
            case 3:
                exp2 += 149;
                limitExp(exp2);
                break;
            default:
                break;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            exp1 = ceil(exp1 + double(D) / 200.00);
        else
            exp1 = ceil(exp1 - double(D) / 100.00);
        limitExp(exp1);
        }
    // Case 2:
    else {
        if (e1 <= 19) {
            exp2 = exp2 + ceil(double(e1 / 4.00) + 19);
            limitExp(exp2);
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 = exp2 + ceil(double(e1 / 9.00) + 21);
            limitExp(exp2);
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 = exp2 + ceil(double(e1 / 16.00) + 17);
            limitExp(exp2);
        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = exp2 + ceil(double(e1 / 4.00) + 19);
            limitExp(exp2);
            if (exp2 > 200) {
                exp2 = exp2 + ceil(double(e1 / 9.00) + 21);
                limitExp(exp2);
            }
        } else {
            exp2 = exp2 + ceil(double(e1 / 4.00) + 19);
            limitExp(exp2);
            exp2 = exp2 + ceil(double(e1 / 9.00) + 21);
            limitExp(exp2);
            if (exp2 > 400) {
                exp2 = exp2 + ceil(double(e1 / 16.00) + 17);
                limitExp(exp2);
                exp2 = ceil(double(exp2 * 1.15));
                limitExp(exp2);
            }
        }
        exp1 = ceil(exp1 - e1);
        limitExp(exp1);
    }
    return exp1 + exp2;
}


int ClosestPerfectSquare(int s){
    int x = sqrt(s);
    if ((x*x) == s){
        return s;
    }
    int higherNum = (x+1)*(x+1);
    int lowerNum = x*x;
    int diff1 = higherNum - s;
    int diff2 = s - lowerNum;
    if (diff1 >= diff2)
        return lowerNum;
    else
        return higherNum;
}

void buyFoodAndDrink(int & hp, int & m){
    if (hp < 200){
        hp = ceil(hp + double(hp * 0.3));
        limitHp(hp);
        m = m - 150;
        limitMoney(m);
    }
    else {
        hp = ceil(hp + double(hp * 0.1));
        limitHp(hp);
        m = m - 70;
        limitMoney(m);
    }
}

void travelToLuggage(int & exp, int & m){
    if (exp < 400){
        m = m - 200;
        limitMoney(m);
    }
    else {
        m = m - 120;
        limitMoney(m);
    }
    exp = ceil(double(exp) * 1.13);
    limitExp(exp);
}

void homelessPeople (int & exp, int & m){
    if (exp < 300){
        m = m - 100;
        limitMoney(m);
    }
    else {
        m = m - 120;
        limitMoney(m);
    }
    exp = ceil(double(exp) * 0.9);
    limitExp(exp);
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (!(limitE(E2))) {
        return -99;
    }
    limitExp (EXP1);
    limitHp(HP1);
    limitMoney(M1);
    double P1, P2, P3, P;

    // Road 1
    int S1 = ClosestPerfectSquare(EXP1);
    if (EXP1 >= S1){
        P1 = 1;
    }
    else {
        P1 = (double(EXP1) / double(S1) + 80.00)/123.00;
    }

    // Road 2
    if (E2 % 2 != 0) {
        double halfMoney = M1 * 0.5;
        while (true) {
            if (M1 <= 0)
                break;
            buyFoodAndDrink(HP1, M1);
            if (M1 < halfMoney)
                break;
            travelToLuggage(EXP1, M1);
            if (M1 < halfMoney)
                break;
            homelessPeople(EXP1, M1);
            if (M1 < halfMoney)
                break;
        }
    } else {
        for (int i = 0; i < 1; i++) {
            if (M1 <= 0)
                break;
            buyFoodAndDrink(HP1, M1);
            if (M1 <= 0)
                break;
            travelToLuggage(EXP1, M1);
            if (M1 <= 0)
                break;
            homelessPeople(EXP1, M1);
        }
    }
    HP1 = ceil(HP1 * 0.83);
    limitHp(HP1);
    EXP1 = ceil(double(EXP1) * 1.17);
    limitExp(EXP1);

    int S2 = ClosestPerfectSquare(EXP1);
    if (EXP1 >= S2){
        P2 = 1;
    }
    else {
        P2 = (double(EXP1) / double(S2) + 80.00)/123.00;
    }

    // Road 3
    double arr[]= {32,47,28,79,100,50,22,83,64,11};
    if (E2 / 10 == 0){
        int a = E2 % 10;
        P3 = arr[a] * 0.01;
    }
    else {
        int sum = (E2 % 10) + (E2 / 10);
        int a = sum % 10;
        P3 = arr[a] * 0.01;
    }

    if ((P1 == 1) && (P2 == 1) && (P3 == 1)){
        EXP1 = ceil(EXP1 - double (EXP1 * 0.25));
        limitExp(EXP1);
    }
    else {
        P = (P1 + P2 + P3) / 3.00;
        if (P < 0.5) {
            HP1 = ceil(HP1 - double(HP1 * 0.15));
            limitHp(HP1);
            EXP1 = ceil(EXP1 + double(EXP1 * 0.15));
            limitExp(EXP1);
        } else {
            HP1 = ceil(HP1 - double(HP1 * 0.1));
            limitHp(HP1);
            EXP1 = ceil(EXP1 + double(EXP1 * 0.2));
            limitExp(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int highestNumDiagonalLeft(int matrix[20][20], int x, int y){
    int diff = x - y;
    int highestNum;
    if (diff == 0){
        return 0;
    }
    else if (diff > 0){
        x -= y;
        y = 0;
        highestNum = matrix[x][y];
        while (x < 9){
            x++;
            y++;
            if (matrix[x][y] > highestNum)
                highestNum = matrix[x][y];
        }
    }
    else {
        y -= x;
        x = 0;
        highestNum = matrix[x][y];
        while (y < 9){
            x++;
            y++;
            if (matrix[x][y] > highestNum)
                highestNum = matrix[x][y];
        }
    }
    return highestNum;
}

int highestNumDiagonalRight(int matrix[20][20], int x, int y){
    int highestNum;
    if (x + y <= 9){
        x = 0;
        y = x + y;
        highestNum = matrix[x][y];
        while (y > 0){
            x++;
            y--;
            if (matrix[x][y] > highestNum)
                highestNum = matrix[x][y];
        }
    }
    else {
        x = (x + y) - 9;
        y = 9;
        highestNum = matrix[x][y];
        while (x < 9){
            x++;
            y--;
            if (matrix[x][y] > highestNum)
                highestNum = matrix[x][y];
        }
    }
    return highestNum;
}

int rowMeet(int matrix[20][20], int e){
    int count = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
             if (matrix[i][j] > (e * 2))
                 count++;
        }
    }
    while (count / 10 != 0){
        int a = count / 10;
        int b = count % 10;
        count = a + b;
    }
    return count;
}

int columnMeet(int matrix[20][20], int e){
    int count = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (matrix[i][j] < (-e))
                count++;
        }
    }
    while (count / 10 != 0){
        int a = count / 10;
        int b = count % 10;
        count = a + b;
    }
    return count;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (!(limitE(E3))) {
        return -99;
    }
    limitExp (EXP1);
    limitExp (EXP2);
    limitHp(HP1);
    limitHp(HP2);
    int matrix1[20][20];
    int matrix2[20][20];
    int sherlock;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            matrix1[i][j] = 0;
            matrix2[i][j] = 0;
        }
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            matrix1[i][j] = ((E3 * j)+(i * 2))*(i - j);
        }
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++) {
            int left = highestNumDiagonalLeft(matrix1, i, j);
            int right = highestNumDiagonalRight(matrix1, i, j);
            if (left >= right)
                sherlock = left;
            else
                sherlock = right;
            matrix2[i][j] = sherlock;
        }
    }
    int r = rowMeet(matrix1, E3);
    int co = columnMeet(matrix1, E3);
    int x;
    if (abs(matrix1[r][co]) <= abs(matrix2[r][co])) {
        EXP1 = ceil(EXP1 + double(EXP1 * 0.12));
        HP1 = ceil(HP1 + double(HP1 * 0.1));
        EXP2 = ceil(EXP2 + double(EXP2 * 0.12));
        HP2= ceil(HP2 + double(HP2 * 0.1));
        x = matrix2[r][co];
    }
    else {
        EXP1 = ceil(EXP1 - double(EXP1 * 0.12));
        HP1 = ceil(HP1 - double(HP1 * 0.1));
        EXP2 = ceil(EXP2 - double(EXP2 * 0.12));
        HP2= ceil(HP2 - double(HP2 * 0.1));
        x = matrix1[r][co];
    }
    limitExp(EXP1);
    limitHp(HP1);
    limitExp(EXP2);
    limitHp(HP2);
    return x;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string se;
    string news;
    news = s;
    string newEmail;
    newEmail = email;
    int t = 0;
    for (int i = 0; i <= newEmail.length(); i++){
        if (newEmail[i] == '@'){
            t = i;
            break;
        }
    }
    se = newEmail.substr(0,t);

    if (news.length() < 8)
        return -1;
    else if (news.length() > 20)
        return -2;

    if (se == ""){
        return -300;
    }

    if (se.length() <= news.length()) {
        int j = 0;
        for (int i = 0; i < news.length(); i++) {
            if (news[i] == se[j]) {
                j++;
                if (j == se.length()) {
                    int sei = i - j + 1;
                    return -(300 + sei);
                }
            } else {
                if (j > 0) {
                    for (int k = j; k >= 0; k--) {
                        if (k == 0) {
                            j = 0;
                            break;
                        }
                        if (news[i] == se[k - 1]) {
                            break;
                        }
                    }
                }
            }
        }
    }

    int num0 = 0;
    int num1 = 1;
    int num2 = 2;
    for (int i = 0; i <= news.length() - 2 ; i++){
        if ((news[num0] == news[num1]) && (news[num1] == news[num2])){
            return -(400 + num0);
        }
        else {
            num0++;
            num1++;
            num2++;
        }
    }

    int trueValue = 0;
    for (int i = 0; i <= news.length(); i++){
        if (news[i] == '@' || news[i] == '#' || news[i] == '%' || news[i] == '$' || news[i] == '!'){
            break;
        }
        if (i == news.length())
            trueValue = 1;
    }
    if (trueValue == 1){
        return -5;
    }

    for (int i = 0; i < news.length(); i++){
        if((!(news[i] >= '0' && news[i] <= '9')) && (!(news[i] >= 'a' && news[i] <= 'z')) && (!(news[i] >= 'A' && news[i] <= 'Z')) && (news[i] != '@') && (news[i] != '#') && (news[i] != '%') && (news[i] != '$') && (news[i] != '!')){
            return i;
        }
    }
    return -10;
}

// Task 5

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string numofpwsarr_pwds[100];
    int countNumOfPws = num_pwds;
    int controlNum = 1;
    numofpwsarr_pwds[0] = arr_pwds[0];
    for (int i = 1; i < num_pwds; i++){
        int check = 1;
        for (int j = 0; j < controlNum; j++){
            if (arr_pwds[i] == arr_pwds[j]){
                check = 0;
                countNumOfPws -= 1;
                break;
            }
        }
        if (check == 1){
            numofpwsarr_pwds[controlNum] = arr_pwds[i];
            controlNum++;
        }
    }

    int mostFrequency = 0;
    string mostFrequent;
    for (int i = 0; i < countNumOfPws; i++){
        int count = 0;
        for (int j = 0; j < num_pwds; j++){
            if (numofpwsarr_pwds[i]== arr_pwds[j]) {
                count++;
            }
        }
        if (count > mostFrequency){
            mostFrequency = count;
            mostFrequent = numofpwsarr_pwds[i];
        }
        else if (count == mostFrequency){
            if (numofpwsarr_pwds[i].length() > mostFrequent.length()){
                mostFrequent = numofpwsarr_pwds[i];
            }
        }
    }
    int firstString = 0;
    for (int i = 0; i < num_pwds; i++){
        if (mostFrequent == arr_pwds[i]){
            firstString = i;
            break;
        }
    }
    return firstString;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////