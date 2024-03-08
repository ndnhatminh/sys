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


// EXP=(0,600)  HP=(0,666)  M=(0,3000)
inline void boundLimit(int& var, int lowerLimit, int upperLimit) {
    if (var > upperLimit) {
        var = upperLimit;
    }
    if (var < lowerLimit) {
        var = lowerLimit;
    }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    
    if ((e1 < 0) || (e1 > 99)) {
        return -99;
    }
    
    boundLimit(exp1, 0, 600);
    boundLimit(exp2, 0, 600);

    if ((e1 >= 0) && (e1 <= 3)) {
        switch (e1) {
        case 0:
            exp2 += 29;
            break;
        case 1:
            exp2 += 45;
            break;
        case 2:
            exp2 += 75;
            break;
        case 3:
            exp2 += 149;
            break;
        }
        boundLimit(exp2, 0, 600);
        int D = e1 * 3 + exp1 * 7;
        if (D % 2) {
            exp1 -= D / 100;
            boundLimit(exp1, 0, 600);
        }
        else {
            exp1 = ceil(exp1 + (double)D / 200 + -1e-9);
            boundLimit(exp1, 0, 600);
        }
    }
    else if ((e1 >= 4) && (e1 <= 99)) {
        if (e1 <= 19) {
            exp2 += ceil((double)e1 / 4 + 19 + -1e-9);
        }
        else if (e1 > 19 && e1 <= 49) {
            exp2 += ceil((double)e1 / 9 + 21 + -1e-9);
        }
        else if (e1 > 49 && e1 <= 65) {
            exp2 += ceil((double)e1 / 16 + 17 + -1e-9);
        }
        else if (e1 > 65 && e1 <= 79) {
            exp2 += ceil((double)e1 / 4 + 19 + -1e-9);
            if (exp2 > 200) {
                exp2 += ceil((double)e1 / 9 + 21 + -1e-9);
            }
        }
        else {
            exp2 += ceil((double)e1 / 4 + 19 + -1e-9);
            exp2 += ceil((double)e1 / 9 + 21 + -1e-9);
            if (exp2 > 400) {
                exp2 += ceil((double)e1 / 16 + 17 + -1e-9);
                exp2 = ceil(exp2 * 1.15 + -1e-9);
            }
        }
        boundLimit(exp2, 0, 600);
        exp1 -= e1;
        boundLimit(exp1, 0, 600);
    }
    else { return -99; }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {

    if ((E2 < 0) || (E2 > 99)) {
        return -99;
    }

    boundLimit(HP1, 0, 666);
    boundLimit(EXP1, 0, 600);
    boundLimit(M1, 0, 3000);
    
    // Road 1
    int smallSquare = pow(floor(sqrt((double)EXP1)), 2);
    int largeSquare = pow(ceil(sqrt((double)EXP1)), 2);
    int S;
    if (abs(smallSquare - EXP1) < abs(largeSquare - EXP1)) {
        S = smallSquare;
    }
    else {
        S = largeSquare;
    }
    double P1 = 0;
    if (EXP1 >= S) {
        P1 = 1;
    }
    else {
        P1 = ((double)EXP1 / S + 80) / 123;
    }

    // Road 2
    int halfOfM1 = M1 * 0.5;
    int paidMoney = 0;
    bool firstTimeEvenE2 = false;

    while ((M1 != 0) && (firstTimeEvenE2 == false)) {
        //e1
        if (HP1 < 200) {
            HP1 = ceil(HP1 * 1.3 + -1e-9);
            M1 -= 150;
            paidMoney += 150;
        }
        else {
            HP1 = ceil(HP1 * 1.1 + -1e-9);
            M1 -= 70;
            paidMoney += 70;
        }
        boundLimit(M1, 0, 3000);
        boundLimit(HP1, 0, 666);
        if ((E2 % 2) ? (paidMoney > halfOfM1) : (M1 == 0)) {
            break;
        }

        //e2
        if (EXP1 < 400) {
            M1 -= 200;
            paidMoney += 200;
        }
        else {
            M1 -= 120;
            paidMoney += 120;
        }
        boundLimit(M1, 0, 3000);
        EXP1 = ceil(EXP1 * 1.13 + -1e-9);
        boundLimit(EXP1, 0, 600);
        if ((E2 % 2) ? (paidMoney > halfOfM1) : (M1 == 0)) {
            break;
        }

        //e3
        if (EXP1 < 300) {
            M1 -= 100;
            paidMoney += 100;
        }
        else {
            M1 -= 120;
            paidMoney += 120;
        }
        boundLimit(M1, 0, 3000);
        EXP1 = ceil(EXP1 * 0.9 + -1e-9);
        boundLimit(EXP1, 0, 600);
        if ((E2 % 2) ? (paidMoney > halfOfM1) : (M1 == 0)) {
            break;
        }
        //
        if ((E2 % 2) == 0) {
            firstTimeEvenE2 = true;
        }
    }

    HP1 = ceil(HP1 * 0.83 + -1e-9);
    boundLimit(HP1, 0, 666);
    EXP1 = ceil(EXP1 * 1.17 + -1e-9);
    boundLimit(EXP1, 0, 600);

    smallSquare = pow(floor(sqrt((double)EXP1)), 2);
    largeSquare = pow(ceil(sqrt((double)EXP1)), 2);
    if (abs(smallSquare - EXP1) < abs(largeSquare - EXP1)) {
        S = smallSquare;
    }
    else {
        S = largeSquare;
    }
    double P2 = 0;
    if (EXP1 >= S) {
        P2 = 1;
    }
    else {
        P2 = ((double)EXP1 / S + 80) / 123;
    }

    //Road 3
    int possibleP3[] = { 32,47,28,79,100,50,22,83,64,11 };
    int i = 0;
    if (E2 > 9) {
        i = (E2 / 10 + E2 % 10) % 10;
    }
    else {
        i = E2;
    }
    double P3 = (i == 4 ? P3 = 1 : P3 = possibleP3[i] * 0.01);

    //Conclusion
    if ((P1 == 1) && (P2 == 1) && (P3 == 1)) {
        EXP1 = ceil(EXP1 * 0.75 + -1e-9);
        boundLimit(EXP1, 0, 600);
    }
    else {
        double avrP = (P1 + P2 + P3) / 3;
        if (avrP < 0.5) {
            HP1 = ceil(HP1 * 0.85 + -1e-9);
            boundLimit(HP1, 0, 666);
            EXP1 = ceil(EXP1 * 1.15 + -1e-9);
            boundLimit(EXP1, 0, 600);
        }
        else {
            HP1 = ceil(HP1 * 0.9 + -1e-9);
            boundLimit(HP1, 0, 666);
            EXP1 = ceil(EXP1 * 1.2 + -1e-9);
            boundLimit(EXP1, 0, 600);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int maxDiagonal(int i, int j, int matrix[10][10]) {
    int x = ((i - j) < 0 ? 0 : (i - j));
    int y = ((j - i) < 0 ? 0 : (j - i));
    int maxNumber = matrix[x][y];
    for (int z = 0; z < (10 - abs(i - j)); z++) {
        if (matrix[x + z][y + z] > maxNumber) {
            maxNumber = matrix[x + z][y + z];
        }
    }

    x = ((i + j - 10 + 1) < 0 ? 0 : (i + j - 10 + 1));
    y = ((i + j) > (10 - 1) ? (10 - 1) : (i + j));
    for (int z = 0; z <= ((10 - 1 - x) < y ? (10 - 1 - x) : y); z++) {
        if (matrix[x + z][y - z] > maxNumber) {
            maxNumber = matrix[x + z][y - z];
        }
    }
    return maxNumber;
}

int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {

    if ((E3 < 0) || (E3 > 99)) {
        return -99;
    }

    boundLimit(HP1, 0, 666);
    boundLimit(HP2, 0, 666);
    boundLimit(EXP1, 0, 600);
    boundLimit(EXP2, 0, 600);

    int taxi[10][10] = { 0 }, SherAndWats[10][10] = { 0 };
    int xMeet = 0, yMeet = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taxi[i][j] > (E3 * 2)) {
                xMeet++;
            }
            if (taxi[i][j] < -E3) {
                yMeet++;
            }
        }
    }

    while (xMeet > 9) {
        xMeet = (xMeet / 10 + xMeet % 10);
    }
    while (yMeet > 9) {
        yMeet = (yMeet / 10 + yMeet % 10);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            SherAndWats[i][j] = maxDiagonal(i, j, taxi);
        }
    }

    if (abs(taxi[xMeet][yMeet]) > SherAndWats[xMeet][yMeet]) {
        EXP1 = ceil(EXP1 * 0.88 + -1e-9);
        HP1 = ceil(HP1 * 0.9 + -1e-9);
        EXP2 = ceil(EXP2 * 0.88 + -1e-9);
        HP2 = ceil(HP2 * 0.9 + -1e-9);
        boundLimit(EXP1, 0, 600);
        boundLimit(EXP2, 0, 600);
        boundLimit(HP1, 0, 666);
        boundLimit(HP2, 0, 666);

        return taxi[xMeet][yMeet];
    }
    else {
        EXP1 = ceil(EXP1 * 1.12 + -1e-9);
        HP1 = ceil(HP1 * 1.1 + -1e-9);
        EXP2 = ceil(EXP2 * 1.12 + -1e-9);
        HP2 = ceil(HP2 * 1.1 + -1e-9);
        boundLimit(EXP1, 0, 600);
        boundLimit(EXP2, 0, 600);
        boundLimit(HP1, 0, 666);
        boundLimit(HP2, 0, 666);

        return SherAndWats[xMeet][yMeet];
    }

    return -99;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    string pass(s), dmail(email);
    string se = dmail.substr(0, dmail.find("@"));
    int passSize = pass.length();

    if (passSize < 8) {
        return -1;
    }
    if (passSize > 20) {
        return -2;
    }
    if (size_t cord = pass.find(se) != string::npos) {
        return -1 * (300 + pass.find(se));
    }

    bool containSpecail = false;
    int remainingCase = -1;
    for (int i = 0; i < passSize; i++) {
        if ((i > 1) && (pass[i] == pass[i - 1]) && (pass[i] == pass[i - 2])) {     //consecutive
            return -1 * (400 + i - 2);
        }
        if (
            (pass[i] >= 48) && (pass[i] <= 57) ||       //number
            (pass[i] >= 65) && (pass[i] <= 90) ||       //uppercase
            (pass[i] >= 97) && (pass[i] <= 122) ||      //lowercase
            (pass[i] == 64) || (pass[i] <= 35) ||       //@ # % $ !
            (pass[i] == 37) || (pass[i] <= 36) ||
            (pass[i] == 33)
            ) {
            if ((pass[i] == 64) || (pass[i] <= 35) ||       //@ # % $ !
                (pass[i] == 37) || (pass[i] <= 36) ||
                (pass[i] == 33)) {
                containSpecail = true;
            };
        }
        else if (remainingCase == -1) { remainingCase = i; }

    }
    if (!containSpecail) {
        return -5;
    }
    else if (remainingCase >= 0) {
        return remainingCase;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int maxFreq = 0;
    int position = 0;
    string correctWord(arr_pwds[0]);

    for (int i = 0; i < num_pwds; i++) {
        int freq = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                freq++;
            }
        }
        
        if (freq > maxFreq) {
            maxFreq = freq;
            correctWord = arr_pwds[i];
            position = i;
        }
        else if ((freq == maxFreq) && (strlen(arr_pwds[i]) > correctWord.length())) {
            correctWord = arr_pwds[i];
            position = i;
        }
    }
    return position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////