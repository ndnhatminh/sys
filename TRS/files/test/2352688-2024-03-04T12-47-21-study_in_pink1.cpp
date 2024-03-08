#include "study_in_pink1.h"

bool readFile(
    const string& filename,
    int& HP1,
    int& HP2,
    int& EXP1,
    int& EXP2,
    int& M1,
    int& M2,
    int& E1,
    int& E2,
    int& E3
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

// the function checkEXP aims to determine whether EXP is valid
int checkEXP(float EXP) {
    if (EXP > 600) {
        EXP = 600;
    }
    if (EXP < 0) {
        EXP = 0;
    }
    return ceil(EXP);
}

// the function checkHP aims to determine whether HP is valid
int checkHP(float HP) {
    if (HP > 666) {
        HP = 666;
    }
    if (HP < 0) {
        HP = 0;
    }
    return ceil(HP);
}

// the function checkM aims to determine whether M is valid
int checkM(float M) {
    if (M > 3000) {
        M = 3000;
    }
    if (M < 0) {
        M = 0;
    }
    return ceil(M);
}

// the function calculateProbability aims to compute Probability in Route1 and Route2  of Task2
float calculateProbability(int EXP) {
    float S = pow(round(sqrt(EXP)), 2);
    if (EXP >= S) {
        return 1;
    }
    else {
        return (EXP / S + 80) / 123.0;
    }

}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    if (e1 < 0 || e1 > 99) {
        return -99;
    }
    else {
        exp1 = checkEXP(exp1);
        exp2 = checkEXP(exp2);
    }
    //Situation 1
    if (e1 <= 3) {
        switch (e1) {
        case 0:
            exp2 = checkEXP(exp2 + 29);
            break;
        case 1:
            exp2 = checkEXP(exp2 + 45);
            break;
        case 2:
            exp2 = checkEXP(exp2 + 75);
            break;
        case 3:
            exp2 = checkEXP(exp2 + 29 + 45 + 75);
            break;
        }
        int D = 3 * e1 + 7 * exp1;
        if (D % 2) {
            exp1 = checkEXP(exp1 - (D / 100.0));
        }
        else {
            exp1 = checkEXP(exp1 + (D / 200.0));
        }
        //Situation 2
    }
    else {
        if (e1 >= 80) {
            exp2 = checkEXP(exp2 + e1 / 4.0 + 19);
            exp2 = checkEXP(exp2 + e1 / 9.0 + 21);
            if (exp2 > 400) {
                exp2 = checkEXP(exp2 + e1 / 16.0 + 17);
                exp2 = checkEXP(exp2 * 1.15);
            }
        }
        else if (e1 >= 66) {
            exp2 = checkEXP(exp2 + e1 / 4.0 + 19);
            if (exp2 > 200) {
                exp2 = checkEXP(exp2 + e1 / 9.0 + 21);
            }
        }
        else if (e1 >= 50) {
            exp2 = checkEXP(exp2 + e1 / 16.0 + 17);
        }
        else if (e1 >= 20) {
            exp2 = checkEXP(exp2 + e1 / 9.0 + 21);
        }
        else if (e1 >= 4) {
            exp2 = checkEXP(exp2 + e1 / 4.0 + 19);
        }
        exp1 = checkEXP(exp1 - e1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 < 0 || E2 > 99) {
        return -99;
    }
    else {
        HP1 = checkHP(HP1);
        EXP1 = checkEXP(EXP1);
        M1 = checkM(M1);
    }
    float P1, P2, P3, averageProbability, P[10] = { 0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11 };
    //Route 1
    P1 = calculateProbability(EXP1);
    //Route 2
    int paidMoney = 0;
    float halfinitialMoney = M1 * 0.5;
    if (E2 % 2) {
        while (1) {
            //Event 1
            if (HP1 < 200) {
                HP1 = checkHP(HP1 * 1.3);
                paidMoney += 150;
            }
            else {
                HP1 = checkHP(HP1 * 1.1);
                paidMoney += 70;
            }
            if (paidMoney > halfinitialMoney) {
                break;
            }
            //Event 2
            if (EXP1 < 400) {
                paidMoney += 200;
                EXP1 = checkEXP(EXP1 * 1.13);
            }
            else {
                paidMoney += 120;
                EXP1 = checkEXP(EXP1 * 1.13);
            }
            if (paidMoney > halfinitialMoney) {
                break;
            }
            //event3
            if (EXP1 < 300) {
                paidMoney += 100;
                EXP1 = checkEXP(EXP1 * 0.9);
            }
            else {
                paidMoney += 120;
                EXP1 = checkEXP(EXP1 * 0.9);
            }
            if (paidMoney > halfinitialMoney) {
                break;
            }
        }
        HP1 = checkHP(HP1 * 0.83);
        EXP1 = checkEXP(EXP1 * 1.17);
        M1 = checkM(M1 - paidMoney);
    }
    else {
        if (HP1 < 200) {
            HP1 = checkHP(HP1 * 1.3);
            M1 = checkM(M1 - 150);
        }
        else {
            HP1 = checkHP(HP1 * 1.1);
            M1 = checkM(M1 - 70);
        }
        if (M1 != 0) {
            if (EXP1 < 400) {
                M1 = checkM(M1 - 200);
                EXP1 = checkEXP(EXP1 * 1.13);
            }
            else {
                M1 = checkM(M1 - 120);
                EXP1 = checkEXP(EXP1 * 1.13);
            }
        }
        if (M1 != 0) {
            if (EXP1 < 300) {
                M1 = checkM(M1 - 100);
                EXP1 = checkEXP(EXP1 * 0.9);
            }
            else {
                M1 = checkM(M1 - 120);
                EXP1 = checkEXP(EXP1 * 0.9);
            }
        }
        HP1 = checkHP(HP1 * 0.83);
        EXP1 = checkEXP(EXP1 * 1.17);
    }
    P2 = calculateProbability(EXP1);
    //Route 3
    if (E2 < 10) {
        P3 = P[E2];
    }
    else {
        int i = ((E2 % 10) + (E2 - (E2 % 10)) / 10) % 10;
        P3 = P[i];
    }
    //After 3 routes
    if ((P1 == P2) && (P2 == P3) && (P1 == 1)) {
        EXP1 = checkEXP(EXP1 * 0.75);
    }
    else {
        averageProbability = (P1 + P2 + P3) / 3;
        if (averageProbability < 0.5) {
            HP1 = checkHP(HP1 * 0.85);
            EXP1 = checkEXP(EXP1 * 1.15);
        }
        else {
            HP1 = checkHP(HP1 * 0.9);
            EXP1 = checkEXP(EXP1 * 1.20);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (E3 < 0 || E3 > 99) {
        return -99;
    }
    else {
        HP1 = checkHP(HP1);
        EXP1 = checkEXP(EXP1);
        HP2 = checkHP(HP2);
        EXP2 = checkEXP(EXP2);
    }
    //iMeet and jMeet are the coordinates of the position where taxi would meet Sherlock and Waston
    //taxiPoint is a 10x10 matrix containing all skil scores of taxi, chasePoint is point of Sherlock and Waston at the meeting position
    int taxiPoint[10][10], chasePoint, iMeet = 0, jMeet = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            taxiPoint[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taxiPoint[i][j] > E3 * 2) {
                iMeet++;
            }
            if (taxiPoint[i][j] < -E3) {
                jMeet++;
            }
        }
    }
    while ((iMeet >= 10) || (jMeet >= 10)) {
        if (iMeet >= 10) {
            iMeet = (iMeet % 10) + (iMeet - (iMeet % 10)) / 10;
        }
        if (jMeet >= 10) {
            jMeet = (jMeet % 10) + (jMeet - (jMeet % 10)) / 10;
        }
    }
    int count = 1;
    chasePoint = taxiPoint[iMeet][jMeet];
    //For while loops below aim to determine the left diagonal and right diagonal with respect to meeting position
    while ((iMeet - count >= 0) && (jMeet - count >= 0)) {
        chasePoint = max(chasePoint, taxiPoint[iMeet - count][jMeet - count]);
        count++;
    }
    count = 1;
    while ((iMeet + count < 10) && (jMeet + count < 10)) {
        chasePoint = max(chasePoint, taxiPoint[iMeet + count][jMeet + count]);
        count++;
    }
    count = 1;
    while ((iMeet - count >= 0) && (jMeet + count < 10)) {
        chasePoint = max(chasePoint, taxiPoint[iMeet - count][jMeet + count]);
        count++;
    }
    count = 1;
    while ((iMeet + count < 10) && (jMeet - count >= 0)) {
        chasePoint = max(chasePoint, taxiPoint[iMeet + count][jMeet - count]);
        count++;
    }
    if (abs(taxiPoint[iMeet][jMeet]) > chasePoint) {
        EXP1 = checkEXP(EXP1 * 0.88);
        HP1 = checkHP(HP1 * 0.9);
        EXP2 = checkEXP(EXP2 * 0.88);
        HP2 = checkHP(HP2 * 0.9);
        return taxiPoint[iMeet][jMeet];
    }
    else {
        EXP1 = checkEXP(EXP1 * 1.12);
        HP1 = checkHP(HP1 * 1.10);
        EXP2 = checkEXP(EXP2 * 1.12);
        HP2 = checkHP(HP2 * 1.10);
        return chasePoint;
    }
}

// Task 4
int checkPassword(const char* s, const char* email) {
    string se = "", specialCharacter = "@#%$!";
    while (*email != '@') {
        se += *email;
        email++;
    }
    int length = 0, sei = 0, sci = 1, lsb = 0;
    bool seiCheck = false, sciCheck = false, spcCheck = false, lsbCheck = false;;
    char sciPreviousCharacter;
    while (*s != '\0') {
        length++;
        //Sei
        if ((sei < se.length()) && (seiCheck == false)) {
            int i = 0;
            while (se[i] != '\0') {
                if (*(s + i) != se[i]) {
                    break;
                }
                if (se[i + 1] == '\0') {
                    sei = length - sei - 1;
                    seiCheck = true;
                }
                i++;
            }
        }
        else {
            if (se[0] == '\0') {
                sei = 0;
            }
            seiCheck = true;
        }
        //Sci
        if (length == 1) {
            sciPreviousCharacter = *s;
        }
        else if ((sci <= 2) && (sciCheck == false)) {
            if (sciPreviousCharacter != *s) {
                sci = 1;
                sciPreviousCharacter = *s;
            }
            else {
                sci++;
            }
        }
        else {
            if (sciCheck == false) {
                sci = length - sci - 1;
            }
            sciCheck = true;
        }
        //SpecialCharacter
        if (spcCheck == false) {
            for (int d = 0; d <= 4; d++) {
                if (*s == specialCharacter[d]) {
                    spcCheck = true;
                    break;
                }
            }
        }
        if (((*s == 33) || (*s == 35) || (*s == 36) || (*s == 37) || (*s == 64) || ((*s >= 48) && (*s <= 57)) || ((*s >= 65) && (*s <= 90)) || ((*s >= 97) && (*s <= 122))) && (!lsbCheck)) {
            lsb = length;
        }
        else {
            lsbCheck = true;
        }
        s++;
    }
    //sciCheck below is for special case where consecutive letters are at the end of password
    if ((sciCheck == false) && (sci > 2)) {
        sci = length - sci;
        sciCheck = true;
    }
    //result
    if (length < 8) {
        return -1;
    }
    else if (length > 20) {
        return -2;
    }
    else  if (seiCheck == true) {
        return -(300 + sei);
    }
    else if (sciCheck == true) {
        return -(400 + sci);
    }
    else if (spcCheck == false) {
        return -5;
    }
    else if (lsbCheck == true) {
        return lsb;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    //pwdsScan is an integer matrix to store the numbers of appearance and first-appeared position of all distinguished passwords
    int pwdsScan[30][2] = { {0,-1} };
    //pwds is a string matrix to store distinguished passwords for easier checking
    string pwds[30] = { "" };
    //index plays the role of counting, setCardinality is the number of valid distinguished passwords, mostAppearance is the largest of appeared times of passwords
    int index = 0, setCardinality = 0, mostAppearance = 0, result = 0;
    if (num_pwds == 1) {
        result = 0;
    }
    else {
        for (int i = 0; i < num_pwds; i++) {
            //determine whether the arr_pwds[i] is already recorded in pwdsScan
            while (index < setCardinality) {
                if (arr_pwds[i] == pwds[index]) {
                    pwdsScan[index][0]++;
                    break;
                }
                else {
                    index++;
                }
            }
            //if arr_pwds[i] is  not recorded in pwdsScan, add it as a new one
            if (index == setCardinality) {
                pwds[index] = arr_pwds[i];
                pwdsScan[index][1] = i;
                setCardinality++;
            }
            index = 0;
        }
        //determine which password is desired
        for (int i = 0; i < setCardinality; i++) {
            if (pwdsScan[i][0] > mostAppearance) {
                mostAppearance = pwdsScan[i][0];
                index = i;
                result = pwdsScan[i][1];
            }
            else if ((pwdsScan[i][0] == mostAppearance) && (pwds[i].length() > pwds[index].length())) {
                index = i;
                result = pwdsScan[i][1];
            }
        }
    }
    return result;
}