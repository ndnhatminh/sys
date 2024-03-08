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
    if (e1 < 0 || e1 > 99) return -99;

    if (exp1 < 0) exp1 = 0;
    else if (exp1 > 600) exp1 = 600;
    if (exp2 < 0) exp2 = 0;
    else if (exp2 > 600) exp2 = 600;

    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) exp2 += 29;
        else if (e1 == 1) exp2 += 45;
        else if (e1 == 2) exp2 += 75;
        else exp2 += 29 + 45 + 75;
        if (exp2 > 600) exp2 = 600;

        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = exp1 + D / 200. + 0.999;
            if (exp1 > 600) exp1 = 600;
        }
        else {
            exp1 = exp1 - D / 100. + 0.999;
            if (exp1 < 0) exp1 = 0;
        }
    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) exp2 = exp2 + e1 / 4. + 19 + 0.999;
        else if (e1 >= 20 && e1 <= 49) exp2 = exp2 + e1 / 9. + 21 + 0.999;
        else if (e1 >= 50 && e1 <= 65) exp2 = exp2 + e1 / 16. + 17 + 0.999;
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = exp2 + e1 / 4. + 19 + 0.999;
            if (exp2 > 200) exp2 = exp2 + e1 / 9. + 21 + 0.999;
        }
        else {
            exp2 = exp2 + e1 / 4. + 19 + 0.999;
            exp2 = exp2 + e1 / 9. + 21 + 0.999;
            if (exp2 > 400) {
                exp2 = exp2 + e1 / 16. + 17 + 0.999;
                exp2 = exp2 * 1.15 + 0.999;
            }
        }
        if (exp2 > 600) exp2 = 600;

        exp1 -= e1;
        if (exp1 < 0) exp1 = 0;
    }

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;

    double P1 = 0.;
    if (HP1 < 0) HP1 = 0;
    else if (HP1 > 666) HP1 = 666;
    if (EXP1 < 0) EXP1 = 0;
    else if (EXP1 > 600) EXP1 = 600;
    if (M1 < 0) M1 = 0;
    else if (M1 > 3000) M1 = 3000;

    int closestValue1 = 0;
    for (int i = 0; i < 25; i++) {
        if (abs(i * i - EXP1) <= abs(closestValue1 - EXP1)) closestValue1 = i * i;
        else break;
    }
    if (EXP1 >= closestValue1) P1 = 1.;
    else P1 = (double(EXP1) / closestValue1 + 80) / 123.;

    double P2 = 0.;
    double half_M1 = M1 / 2.;
    double cost = 0.;
    if (E2 % 2 != 0) {
        while (true) {
            if (M1 > 0) {
                if (HP1 < 200) {
                    HP1 = HP1 * 1.3 + 0.999;
                    M1 -= 150;
                    cost += 150;
                }
                else {
                    HP1 = HP1 * 1.1 + 0.999;
                    M1 -= 70;
                    cost += 70;
                }
                if (HP1 > 666) HP1 = 666;
                if (M1 < 0) M1 = 0;
                if (cost > half_M1) break;

                if (EXP1 < 400) {
                    M1 -= 200;
                    cost += 200;
                }
                else {
                    M1 -= 120;
                    cost += 120;
                }
                if (M1 < 0) M1 = 0;
                EXP1 = EXP1 * 1.13 + 0.999;
                if (EXP1 > 600) EXP1 = 600;
                if (cost > half_M1) break;

                if (EXP1 < 300) {
                    M1 -= 100;
                    cost += 100;
                }
                else {
                    M1 -= 120;
                    cost += 120;
                }
                if (M1 < 0) M1 = 0;
                EXP1 = EXP1 * 0.9 + 0.999;
                if (cost > half_M1) break;
            }
            else break;
        }
        HP1 = HP1 * 0.83 + 0.999;
        EXP1 = EXP1 * 1.17 + 0.999;
        if (EXP1 > 600) EXP1 = 600;
    }
    else {
        if (M1 > 0) {
            if (HP1 < 200) {
                HP1 = HP1 * 1.3 + 0.999;
                M1 -= 150;
            }
            else {
                HP1 = HP1 * 1.1 + 0.999;
                M1 -= 70;
            }
            if (HP1 > 666) HP1 = 666;
            if (M1 < 0) M1 = 0;
        }
        if (M1 > 0) {
            if (EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            if (M1 < 0) M1 = 0;
            EXP1 = EXP1 * 1.13 + 0.999;
            if (EXP1 > 600) EXP1 = 600;

        }
        if (M1 > 0) {
            if (EXP1 < 300) M1 -= 100;
            else M1 -= 120;
            if (M1 < 0) M1 = 0;
            EXP1 = EXP1 * 0.9 + 0.999;
        }
        HP1 = HP1 * 0.83 + 0.999;
        EXP1 = EXP1 * 1.17 + 0.999;
        if (EXP1 > 600) EXP1 = 600;
    }
    int closestValue2 = 0;
    for (int i = 0; i < 25; i++) {
        if (abs(i * i - EXP1) <= abs(closestValue2 - EXP1)) closestValue2 = i * i;
        else break;
    }
    if (EXP1 >= closestValue2) P2 = 1.;
    else P2 = (double(EXP1) / closestValue2 + 80) / 123.;

    double P3 = 0.;
    int arr[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2 >= 0 && E2 <= 9) P3 = arr[E2] / 100.;
    else if (E2 >= 10 && E2 <= 99) {
        int idx = ((E2 / 10) + (E2 % 10)) % 10;
        P3 = arr[idx] / 100.;
    }

    double P = 0.;
    if (P1 == 1. && P2 == 1. && P3 == 1.) EXP1 = EXP1 * 0.75 + 0.999;
    else {
        P = (P1 + P2 + P3) / 3.;
        if (P < 0.5) {
            HP1 = HP1 * 0.85 + 0.999;
            EXP1 = EXP1 * 1.15 + 0.999;
        }
        else {
            HP1 = HP1 * 0.9 + 0.999;
            EXP1 = EXP1 * 1.2 + 0.999;
        }
        if (EXP1 > 600) EXP1 = 600;
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;

    if (HP1 < 0) HP1 = 0;
    else if (HP1 > 666) HP1 = 666;
    if (HP2 < 0) HP2 = 0;
    else if (HP2 > 666) HP2 = 666;
    if (EXP1 < 0) EXP1 = 0;
    else if (EXP1 > 600) EXP1 = 600;
    if (EXP2 < 0) EXP2 = 0;
    else if (EXP2 > 600) EXP2 = 600;

    int arrTaxi[10][10] = {};
    int pos = 0;
    int neg = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arrTaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (arrTaxi[i][j] > 2 * E3) pos++;
            else if (arrTaxi[i][j] < -E3) neg++;
        }
    }
    while (pos / 10 != 0) {
        pos = pos / 10 + pos % 10;
    }
    while (neg / 10 != 0) {
        neg = neg / 10 + neg % 10;
    }
    int k = pos;
    int l = neg;
    int maxSW = -999999;
    while (k >= 0 && l >= 0) {
        if (maxSW < arrTaxi[k][l]) maxSW = arrTaxi[k][l];
        k--;
        l--;
    }
    k = pos;
    l = neg;
    while (k <= 9 && l <= 9) {
        if (maxSW < arrTaxi[k][l]) maxSW = arrTaxi[k][l];
        k++;
        l++;
    }
    k = pos;
    l = neg;
    while (k >= 0 && l <= 9) {
        if (maxSW < arrTaxi[k][l]) maxSW = arrTaxi[k][l];
        k--;
        l++;
    }
    k = pos;
    l = neg;
    while (k <= 9 && l >= 0) {
        if (maxSW < arrTaxi[k][l]) maxSW = arrTaxi[k][l];
        k++;
        l--;
    }
    int finalPoint = 0;
    if (abs(arrTaxi[pos][neg]) > abs(maxSW)) {
        EXP1 = EXP1 * 0.88 + 0.999;
        HP1 = HP1 * 0.9 + 0.999;
        EXP2 = EXP2 * 0.88 + 0.999;
        HP2 = HP2 * 0.9 + 0.999;
        finalPoint = arrTaxi[pos][neg];
    }
    else {
        EXP1 = EXP1 * 1.12 + 0.999;
        if (EXP1 > 600) EXP1 = 600;
        HP1 = HP1 * 1.1 + 0.999;
        if (HP1 > 666) HP1 = 666;
        EXP2 = EXP2 * 1.12 + 0.999;
        if (EXP2 > 600) EXP2 = 600;
        HP2 = HP2 * 1.1 + 0.999;
        if (HP2 > 666) HP2 = 666;
        finalPoint = maxSW;
    }

    return finalPoint;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int lenS = strlen(s);
    int lenE = strlen(email);
    if (lenS < 8) return -1;
    else if (lenS > 20) return -2;
    else {
        const char* posPointerA = strchr(email, '@');
        int lenSE = posPointerA - email;
        if (lenSE <= 20) {
            char se[25];
            strcpy(se, email);
            se[lenSE] = '\0';
            const char* posPointerS = strstr(s, se);
            if (posPointerS != nullptr) {
                int sei = posPointerS - s;
                return -(300 + sei);
            }
        }

        int sameLetter = 1;
        int sci = 0;
        for (int i = 0; i < lenS - 1; i++) {
            if (s[i] == s[i + 1]) {
                sameLetter++;
                if (sameLetter > 2) {
                    sci = i - 1;
                    return -(400 + sci);
                }
            }
            else sameLetter = 1;
        }

        bool specialLetter = false;
        for (int i = 0; i < lenS; i++) {
            if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
                specialLetter = true;
                break;
            }
        }
        if (!specialLetter) return -5;

        for (int i = 0; i < lenS; i++) {
            if (s[i] >= '0' && s[i] <= '9') continue;
            else if (s[i] >= 'a' && s[i] <= 'z') continue;
            else if (s[i] >= 'A' && s[i] <= 'Z') continue;
            else if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') continue;
            else return i;
        }
        return -10;
    }
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxFrePwd = 0;
    int maxLenPwd = 0;
    int idx = 0;
    for (int i = 0; i < num_pwds; i++) {
        int frePwd = 1;
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) frePwd++;
        }
        if (frePwd > maxFrePwd) {
            maxFrePwd = frePwd;
            idx = i;
            maxLenPwd = strlen(arr_pwds[i]);
        }
        else if (frePwd == maxFrePwd) {
            if (strlen(arr_pwds[i]) > maxLenPwd) {
                maxLenPwd = strlen(arr_pwds[i]);
                idx = i;
            }
        }
    }

    return idx;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////