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

void setExp(int & exp){
    if (exp > 600){
        exp = 600;
    }
    else if (exp < 0){
        exp = 0;
    }
}

void setHp(int & hp){
    if (hp > 666){
        hp = 666;
    }
    else if (hp < 0){
        hp = 0;
    }
}

void setMoney(int & m){
    if (m > 3000){
        m = 3000;
    }
    else if (m < 0){
        m = 0;
    }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
if (0 <= e1 && 99 >= e1){
    if (0 <= e1 && 3 >= e1){
        if (e1 == 0){
            exp2 += 29;
        }
        else if (e1 == 1){
            exp2 += 45;
        }
        else if (e1 == 2){
            exp2 += 75;
        }
        else if (e1 == 3){
            exp2 += 149;
        }
        int d;
        d = e1 * 3 + exp1 * 7;
        if (d % 2 == 0){
            exp1 = ceil(exp1 + d/200.0);
        }
        else {
            exp1 = ceil(exp1 - d/100.0);
        }
    }
    else if (4 <= e1 && 99 >= e1){
        if (4 <= e1 && 19 >= e1){
            exp2 += ceil((e1 / 4.0) + 19);
        }
        else if (20 <= e1 && 49 >= e1){
            exp2 +=  ceil((e1 / 9.0) + 21);
        }
        else if (50 <= e1 && 65 >= e1){
            exp2 += ceil((e1 / 16.0) + 17);
        }
        else if (66 <= e1 && 79 >= e1){
            exp2 += ceil((e1 / 4.0) + 19);
            if (exp2 > 200){
                exp2 += ceil((e1 / 9.0) + 21);
            }
        }
        else if (80 <= e1 && 99 >= e1){
            exp2 += ceil((e1 / 4.0) + 19);
            exp2 += ceil((e1 / 9.0) + 21);
            if (exp2 > 400){
                exp2 += ceil((e1 / 16.0) +  17);
                exp2 = ceil(exp2 * 1.15);
            }
        }
        exp1 = exp1 - e1;
    }
        setExp (exp1);
        setExp (exp2);
    return exp1 + exp2;
}
else{
    return -99;
}
}

int nearestSquare(int & num){
    double squareNum = sqrt(num);
    int nearestInt = static_cast<int>(round(squareNum));
    int nearestSquare = nearestInt * nearestInt;

    return nearestSquare;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
if (E2 < 0 || E2 > 99){
    return -99;
}
    double P1, P2, P3, Pmean;
    int S1 = nearestSquare (EXP1);
    if (EXP1 >= S1){
        P1 = 1;
    }
    else{
        P1 = (EXP1 / S1 + 80) / 123.0;
    }
    int initialMoney = M1;
    while (true){
    if (M1 <= 0){
        break;
    }
    if (HP1 < 200){
        HP1 = ceil(HP1 * 130.0 / 100);
        if (M1 > 0){ 
            M1 -= 150;
        }
    } 
    else{
        HP1 = ceil(HP1 * 110.0 / 100);
        if (M1 > 0){
             M1 -= 70;
        }
    }
    setHp (HP1);
    setMoney (M1);
    if (E2 % 2 != 0){
        if (M1 <= 0 || (initialMoney - M1) > (initialMoney / 2)){
            break;
        }
    } 
    else{
        if (M1 <= 0){
            break;
        }
    }
    if (EXP1 < 400 && M1 > 0){
        M1 -= 200;
        EXP1 = ceil(EXP1 * 113.0 / 100);
    } 
    else if (EXP1 >= 400 && M1 > 0){
        M1 -= 120;
        EXP1 = ceil(EXP1 * 113.0 / 100);
    }
    setExp (EXP1);
    setMoney (M1);
    if (E2 % 2 != 0){
        if (M1 <= 0 || (initialMoney - M1) > (initialMoney / 2)){
            break;
        }
    } 
    else{
        if (M1 <= 0){
            break;
        }
    }
    if (EXP1 < 300 && M1 > 0){
        M1 -= 100;
        EXP1 = ceil(EXP1 * 90.0 / 100);
    } 
    else if (EXP1 >= 300 && M1 > 0){
        M1 -= 120;
        EXP1 = ceil(EXP1 * 90.0 / 100);
    }
    setExp (EXP1);
    setMoney (M1);
    if (E2 % 2 != 0){
        if (M1 <= 0 || (initialMoney - M1) > (initialMoney / 2)){
            break;
        }
    } 
    else{
        break;
    }
    }
    HP1 = ceil(HP1 * 83.0 / 100);
    EXP1 = ceil(EXP1 * 117.0 / 100);
    setExp (EXP1);
    setHp (HP1);
    int S2 = nearestSquare (EXP1);
    if (EXP1 >= S2){
        P2 = 1;
    }
    else{
        P2 = (EXP1 / S2 + 80) / 123.0;
    }
    int i;
    int P[10] = {32,47,28,79,100,50,22,83,64,11};
    if (E2 < 10){
        i = E2;
    }
    else if (E2 >= 10){
        int sum = (E2 / 10) + (E2 % 10);
        i = sum % 10;
    }
    P3 = P[i] / 100.0;
    if (P1 == 1 && P1 == P2 && P1 == P3){
        EXP1 = ceil(EXP1 * 75.0 / 100);
    }
    else{
        Pmean = (P1 + P2 + P3) / 3;
        if (Pmean < 0.5){
            HP1 = ceil(HP1 * 85.0 / 100);
            EXP1 = ceil(EXP1 * 115.0 / 100);
        }
        else{
            HP1 = ceil(HP1 * 90.0 / 100);
            EXP1 = ceil(EXP1 * 120.0 / 100);
        }
    }
    setExp (EXP1);
    setHp (HP1);
    setMoney (M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99){
        return -99;
    }

    int taxiPoint[10][10] = {0};
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            taxiPoint[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int bigger = 0, smaller = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (taxiPoint[i][j] > 2 * E3){
                bigger++;
            }
            else if (taxiPoint[i][j] < -E3){
                smaller++;
            }
        }
    }
    int posI, posJ;
    int meetingPoint[10][10];
    if (bigger >= 10){
        posI = bigger / 10 + bigger % 10;
        if (posI >= 10){
            posI = posI / 10 + posI % 10;
        }
    }
    if (smaller >= 10){
        posJ = smaller / 10 + smaller % 10;
        if (posJ >= 10){
            posJ = posJ / 10 + posJ % 10;
        }
    }
    int sherlockPoint = 0;
    for (int i = posI, j = posJ; i >= 0 && j >= 0; i--, j--){
        if (i >= 0 && j >= 0 && taxiPoint[i][j] > sherlockPoint){
            sherlockPoint = taxiPoint[i][j];
        }
    }
    for (int i = posI, j = posJ; i < 10 && j >= 0; i++, j--){
        if (i < 10 && j >= 0 && taxiPoint[i][j] > sherlockPoint){
            sherlockPoint = taxiPoint[i][j];
        }
    }
    for (int i = posI, j = posJ; i < 10 && j < 10; i++, j++){
        if (i < 10 && j < 10 && taxiPoint[i][j] > sherlockPoint){
            sherlockPoint = taxiPoint[i][j];
        }
    }
    for (int i = posI, j = posJ; i >= 0 && j < 10; i--, j++){
        if (i >= 0 && j < 10 && taxiPoint[i][j] > sherlockPoint){
            sherlockPoint = taxiPoint[i][j];
        }
    }
    if (abs(taxiPoint[posI][posJ]) > sherlockPoint){
        EXP1 = ceil(EXP1 * 88.0 / 100);
        EXP2 = ceil(EXP2 * 88.0 / 100);
        HP1 = ceil(HP1 * 90.0 / 100);
        HP2 = ceil(HP2 * 90.0 / 100);
        setExp(EXP1);
        setExp(EXP2);
        setHp(HP1);
        setHp(HP2);
        return taxiPoint[posI][posJ];
    }
    else{
        EXP1 = ceil(EXP1 * 112.0 / 100);
        EXP2 = ceil(EXP2 * 112.0 / 100);
        HP1 = ceil(HP1 * 110.0 / 100);
        HP2 = ceil(HP2 * 110.0 / 100);
        setExp(EXP1);
        setExp(EXP2);
        setHp(HP1);
        setHp(HP2);
        return sherlockPoint;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    char se[100];
    int i;
    for (i = 0; email[i] != '@'; i++){
        se[i] = email[i];
    }
    se[i] = '\0';
    int length = strlen(s);
    if (length < 8){
        return -1;
    }
    if (length > 20){
        return -2;
    }
    if (strstr(s, se) != nullptr){
        return -(300 + (strstr(s, se) - s));
    }
    for (int j = 0; j < length - 2; j++){
        if (s[j] == s[j + 1] && s[j] == s[j + 2]){
            return -(400 + j);
        }
    }
    bool hasSpecialCharacter = false;
    const char specialCharacters[] = {'@', '#', '%', '$', '!'};
    for (int j = 0; j < length; j++){
        for (char specialChar : specialCharacters){
            if (s[j] == specialChar){
                hasSpecialCharacter = true;
                break;
            }   
        }
        if (hasSpecialCharacter){
            break;
        }
    }
    if (!hasSpecialCharacter){
    return -5;
    }
    for (int j = 0; j < length; j++){
        char c = s[j];
        if (!isalnum(c)){
            bool isSpecial = false;
            for (char specialChar : specialCharacters){
                if (c == specialChar){
                    isSpecial = true;
                    break;
                }
            }
            if (!isSpecial){
                return j;
            }
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int counts[num_pwds] = {0};
    for (int i = 0; i < num_pwds; i++){
        int count = 0;
        for (int j = 0; j < num_pwds; j++){
            if (i != j && string(arr_pwds[i]) == arr_pwds[j]){
                count++;
            }
        }
        counts[i] = count;
    }
    int maxCount = 0;
    int maxLength = 0;
    int maxCountIndex;
    for (int i = 0; i < num_pwds; i++){
        if (counts[i] > maxCount || (counts[i] == maxCount && strlen(arr_pwds[i]) > maxLength)) {
            maxCount = counts[i];
            maxLength = strlen(arr_pwds[i]);
            maxCountIndex = i;
        }
    }
    return maxCountIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////