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
// Reset function
void reset(int & exp1, int & exp2){
    if (exp1 > 600){
        exp1 = 600;
    }
    else if (exp1 < 0){
        exp1 = 0;
    }
    if (exp2 > 600){
        exp2 = 600;
    }
    else if (exp2 < 0){
        exp2 = 0;
    }
}
void resetExp(int & exp){
    if (exp > 600){
        exp = 600;
    }
    else if (exp < 0){
        exp = 0;
    }
}
void resetHP(int & hp){
    if (hp > 666){
        hp = 666;
    }
    else if (hp < 0){
        hp = 0;
    }
}
void resetMoney(int & money){
    if (money > 3000){
        money = 3000;
    }
    else if (money < 0){
        money = 0;
    }
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99){
        return -99;
    }
    reset(exp1, exp2);
    if (e1 >= 0 && e1 <=3) {
        int add0 = 29, add1 = 45, add2 = 75;
        switch (e1) {
            case 0:
                exp2 += add0;
                break;
            case 1:
                exp2 += add1;
                break;
            case 2:
                exp2 += add2;
                break;
            case 3:
                exp2 += (add0 + add1 + add2);
                break;
        }
        reset(exp1, exp2);
        int d = e1 * 3 + exp1 * 7;
        float difD;
        if (d % 2 == 0) {
            difD = float(d)/200.0;
            difD = ceil(difD);
            exp1 += difD;
        }
        else{
            difD = float(d)/100.0;
            difD = floor(difD);
            exp1 -= difD;
        }
        reset(exp1, exp2);
    }
    else if (e1 >= 4 && e1 <= 99){
        float dif, expFloat2;
        if (e1 >= 4 && e1 <= 19){
            dif = float(e1) / 4.0 + 19;
            exp2 += ceil(dif);
        }
        else if (e1 >= 20 && e1 <= 49){
            dif = float(e1) / 9.0 + 21;
            exp2 += ceil(dif);
        }
        else if (e1 >= 50 && e1 <= 65){
            dif = float(e1) / 16.0 + 17;
            exp2 += ceil(dif);
        }
        else if (e1 >= 66 && e1 <= 79){
            dif = float(e1) / 4.0 + 19;
            exp2 += ceil(dif);
            reset(exp1, exp2);
            if (exp2 > 200){
                dif = float(e1) / 9.0 + 21;
                exp2 += ceil(dif);
            }
        }
        else {
            dif = float(e1) / 4.0 + 19;
            exp2 += ceil(dif);
            dif = float(e1) / 9.0 + 21;
            exp2 += ceil(dif);
            reset(exp1, exp2);
            if (exp2 > 400){
                dif = float(e1) / 16.0 + 17;
                exp2 += ceil(dif);
                expFloat2 = float(exp2) * 1.15;
                exp2 = ceil(expFloat2);
            }
        }
        reset(exp1, exp2);
        exp1 -= e1;
    }
    reset(exp1, exp2);
    return exp1 + exp2;
}

// Task 2
int findNearest(int num){
    int squaredNum[25] = {0,1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400,441,484,529,576};
    int min = num;
    int temp, indexMin = 0;
    for (int i = 0; i < 25; i++)
    {
        temp = abs(num - squaredNum[i]);
        if (temp < min){
            min = temp;
            indexMin = i;
        }
    }
    return squaredNum[indexMin];
}
const float epsilon = 10e-6;
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99){
        return -99;
    }
    resetHP(HP1); resetExp(EXP1); resetMoney(M1);
    int s;
    float p, p1, p2, p3;
    bool isValid;
    // Road 1
    s = findNearest(EXP1);
    if (EXP1 >= s) {
        p1 = 1;
    }
    else {
        p1 = (float(EXP1)/float(s) + 80.0) / 123.0;
    }

    // Road 2
    if (M1 > 0){  
        int moneyPaid = 0;
        float halfBudget = M1 * 0.5;
        if (E2 % 2 == 1){
            while (moneyPaid <= halfBudget){
                if (HP1 < 200) {
                    HP1 += ceil(0.3 * (HP1) - epsilon);
                    moneyPaid += 150;
                    M1 -= 150;
                }
                else {
                    HP1 += ceil(0.1 * (HP1) - epsilon);
                    moneyPaid += 70;
                    M1 -= 70;
                }
                resetHP(HP1); resetExp(EXP1); resetMoney(M1);
                if (moneyPaid <= halfBudget){
                    if (EXP1 < 400) {
                        moneyPaid += 200;
                        M1 -= 200;
                    }
                    else {
                        moneyPaid += 120;
                        M1 -= 120;
                    }
                    EXP1 += ceil(0.13 * (EXP1) - epsilon);
                    resetHP(HP1); resetExp(EXP1); resetMoney(M1);
                    if (moneyPaid <= halfBudget){
                        if (EXP1 < 300){
                            moneyPaid += 100;
                            M1 -= 100;
                        }
                        else {
                            moneyPaid += 120;
                            M1 -= 120;
                        }
                        EXP1 -= floor(0.1 * (EXP1));
                        resetHP(HP1); resetExp(EXP1); resetMoney(M1);
                    }
                    else {
                        break;
                    }
                }
                else {
                    break;
                }
            }
            HP1 -= floor(0.17 * (HP1));
            EXP1 += ceil(0.17 * (EXP1) - epsilon);
            resetHP(HP1); resetExp(EXP1); resetMoney(M1);
        }
        else{
            if (HP1 < 200) {
                HP1 += ceil(0.3 * (HP1) - epsilon);
                M1 -= 150;
            }
            else {
                HP1 += ceil(0.1 * (HP1) - epsilon);
                M1 -= 70;
            }
            resetHP(HP1); resetExp(EXP1); resetMoney(M1);
            if (M1 > 0){
                if (EXP1 < 400) {
                    M1 -= 200;
                }
                else {
                    M1 -= 120;
                }
                EXP1 += ceil(0.13 * (EXP1) - epsilon);
                resetHP(HP1); resetExp(EXP1); resetMoney(M1);
                if (M1 > 0){
                    if (EXP1 < 300){
                        M1 -= 100;
                    }
                    else {
                        M1 -= 120;
                    }
                    EXP1 -= floor(0.1 * (EXP1));
                    resetHP(HP1); resetExp(EXP1); resetMoney(M1);
                    HP1 -= floor(0.17 * (HP1));
                    EXP1 += ceil(0.17 * (EXP1) - epsilon);
                    resetHP(HP1); resetExp(EXP1); resetMoney(M1);
                }
                else {
                    HP1 -= floor(0.17 * (HP1));
                    EXP1 += ceil(0.17 * (EXP1) - epsilon);
                    resetHP(HP1); resetExp(EXP1); resetMoney(M1);
                }
            }
            else {
                HP1 -= floor(0.17 * (HP1));
                EXP1 += ceil(0.17 * (EXP1) - epsilon);
                resetHP(HP1); resetExp(EXP1); resetMoney(M1);
            }
        }
    }
    else {
        HP1 -= floor(0.17 * (HP1));
        EXP1 += ceil(0.17 * (EXP1) - epsilon);
        resetHP(HP1); resetExp(EXP1); resetMoney(M1);
    }
    s = findNearest(EXP1);
    if (EXP1 >= s) {
        p2 = 1;
    }
    else {
        p2 = (float(EXP1)/float(s) + 80.0) / 123.0;
    }
    //Road 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int idx;
    if (E2 < 10){
        idx = E2;
        p3 = float(P[idx]) / 100.0;
    }
    else{
        int sum = 0;
        sum += (E2%10 + (E2/10)%10);
        idx = sum%10;
        p3 = float(P[idx]) / 100.0;
    }
    if (abs(p1 - p2) < epsilon && abs(p2 - p3) < epsilon && (p3 - 1.0) < epsilon){ //attention
        isValid = false;
        EXP1 -= floor(0.25 * float(EXP1));
    }
    else{
        isValid = true;
        p = (p1 + p2 + p3)/3.0;
        if (p < 0.5){
            HP1 -= floor(0.15 * float(HP1));
            EXP1 += ceil(0.15 * float(EXP1) - epsilon);
        }
        else{
            HP1 -= floor(0.1 * float(HP1));
            EXP1 += ceil(0.2 * float(EXP1) -epsilon);
        }
    }
    resetHP(HP1); resetExp(EXP1); resetMoney(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int shortenDigit(int num){
    int sum = 0;
    while (num > 0){
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}
// findMax function
int findMax(int arr[10][10], int ridx, int cidx){
    int max = arr[ridx][cidx];
    int rTemp = ridx;
    int cTemp = cidx;
    while(rTemp != 0 && cTemp != 0)
    {
        rTemp--;
        cTemp--;
        if (arr[rTemp][cTemp] > max){
            max = arr[rTemp][cTemp];
        }
    }
    rTemp = ridx;
    cTemp = cidx;
    while(rTemp != 9 && cTemp != 9)
    {
        rTemp++;
        cTemp++;
        if (arr[rTemp][cTemp] > max){
            max = arr[rTemp][cTemp];
        }
    }
    rTemp = ridx;
    cTemp = cidx;
    while(rTemp != 9 && cTemp != 0)
    {
        rTemp++;
        cTemp--;
        if (arr[rTemp][cTemp] > max){
            max = arr[rTemp][cTemp];
        }
    }
    rTemp = ridx;
    cTemp = cidx;
    while(rTemp != 0 && cTemp != 9)
    {
        rTemp--;
        cTemp++;
        if (arr[rTemp][cTemp] > max){
            max = arr[rTemp][cTemp];
        }
    }
    return max;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99){
        return -99;
    }
    resetHP(HP1); resetExp(EXP1); resetHP(HP2); resetExp(EXP2); 
    int findRow = 0, findCol = 0;
    int high = E3 * 2;
    int small = (-1) * E3;
    int road[10][10] = {0};
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            road[i][j] = ((E3 * j) + (i * 2)) * (i-j);
            if ((road[i][j]) > high) {
                findRow++;
            }
            else if ((road[i][j]) < small) {
                findCol++;
            }
        }
    }
    do
    {
        findRow = shortenDigit(findRow);
    } while (findRow > 9);
    do
    {
        findCol = shortenDigit(findCol);
    } while (findCol > 9);
    // place to meet: road[findRow][findCol]
    // find max along two diagonals
    int taxi = road[findRow][findCol], result;
    int chase = findMax(road, findRow, findCol);
    if (abs(taxi) > abs(chase)){
        HP1 -= floor(0.1 * float(HP1));
        EXP1 -= floor(0.12 * float(EXP1));
        HP2 -= floor(0.1 * float(HP2));
        EXP2 -= floor(0.12 * float(EXP2));
        result = taxi;
    }
    else {
        HP1 += ceil(0.1 * float(HP1) - epsilon);
        EXP1 += ceil(0.12 * float(EXP1) - epsilon);
        HP2 += ceil(0.1 * float(HP2) - epsilon);
        EXP2 += ceil(0.12 * float(EXP2) - epsilon);
        result = chase;
    }
    resetHP(HP1); resetExp(EXP1); resetHP(HP2); resetExp(EXP2); 
    return result;
}

// Task 4

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int n = strlen(s);
    string temp(email);
    int pos = temp.find('@');
    string seString = temp.substr(0, pos);
    const char * se = seString.c_str();
    const char * sePos = strstr(s, se);
    bool isConsecutive = false, isContainedSpecific = false;
    int currentCount = 1, curPos = 0;
    char tempChar = s[0];
    for (int i = 1; i < n; i++){
        if (s[i] == tempChar){
            currentCount++;
        }
        else {
            currentCount = 1;
            curPos = i;
            tempChar = s[i];
        }
        if (currentCount > 2){
            isConsecutive = true;
            break;
        }
    }
    for (int j = 0; j < n; j++){
        if (s[j] == '@' || s[j] == '#' || s[j] == '%' || s[j] == '$' || s[j] == '!'){
            isContainedSpecific = true;
            break;
        }
    }
    // check if all character is valid in manner
    int invalidIdx, charValue;
    bool isContainInvalidChar = false;
    for (int k = 0; k < n; k++){
        charValue = int(s[k]);
        if (charValue < 33 || charValue == 34 || (charValue >= 38 && charValue <= 47) || (charValue >= 58 && charValue <= 63) || (charValue >= 91 && charValue <= 96) || (charValue >= 123 && charValue <= 127))
        {
            invalidIdx = k;
            isContainInvalidChar = true;
            break;
        }
    }
    if (n < 8){
        return -1;
    }
    else if (n > 20){
        return -2;
    }
    else if (sePos != nullptr) {
        return -(300 + (sePos - s));
    }
    else if (isConsecutive){
        return -(400 + curPos);
    }
    else if (!isContainedSpecific){
        return -5;
    }
    else if (isContainInvalidChar){
        return invalidIdx;
    }
    else {
        return -10;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int count, maxCount = 0, len = 0, result;
    const char * validPd;
    for (int i = 0; i < num_pwds; i++){
        count = 1;
        for (int j = i+1; j < num_pwds; j++){
            if ((strcmp(arr_pwds[i], arr_pwds[j]) == 0)){
                count++;
            }
        }
        if (count > maxCount){
            maxCount = count;
            len = strlen(arr_pwds[i]);
            validPd = arr_pwds[i];
            result = i;
        }
        else if (count == maxCount){
            if (strlen(arr_pwds[i]) > len){
                len = strlen(arr_pwds[i]);
                validPd = arr_pwds[i];
                result = i;
            }
        }
    }
    return result;
}