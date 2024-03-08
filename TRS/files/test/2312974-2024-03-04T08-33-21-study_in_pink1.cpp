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
int roundNumber(double num) {
    if ((num - (int)num) <= 1e-9) {
        return (int)num;
    }
    else {
        return ceil(num);
    }
}
// Task 1
int firstMeet(int& exp1, int& exp2, int e1)
{
    // TODO: Complete this function
    if (exp1 < 0) exp1 = 0;
    if (exp1 > 600) exp1 = 600;
    if (exp2 < 0) exp2 = 0;
    if (exp2 > 600) exp2 = 600;
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
        //Check thiet lap so
        if (exp2 > 600) exp2 = 600;
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = roundNumber(exp1 + ((double)D / 200));
        else exp1 = roundNumber(exp1 - ((double)D / 100));
        //Check thiet lap so
        if (exp1 < 0) exp1 = 0;
        if (exp1 > 600) exp1 = 600;
    }
    else if ((e1 >= 4) && (e1 <= 99)) {
        if ((e1 >= 4) && (e1 <= 19)) exp2 = roundNumber(exp2 + (((double)e1 / 4) + 19));
        if ((e1 >= 20) && (e1 <= 49)) exp2 = roundNumber(exp2 + (((double)e1 / 9) + 21));
        if ((e1 >= 50) && (e1 <= 65)) exp2 = roundNumber(exp2 + (((double)e1 / 16) + 17));
        if ((e1 >= 66) && (e1 <= 79)) {
            exp2 = roundNumber(exp2 + (((double)e1 / 4) + 19));
            if (exp2 > 200) exp2 = roundNumber(exp2 + (((double)e1 / 9) + 21));
        }
        if ((e1 >= 80) && (e1 <= 99)) {
            exp2 = roundNumber(exp2 + (((double)e1 / 4) + 19));
            exp2 = roundNumber(exp2 + (((double)e1 / 9) + 21));
            if (exp2 > 400) {
                exp2 = roundNumber(exp2 + (((double)e1 / 16) + 17));
                exp2 = roundNumber(exp2 + (0.15 * exp2));
            }
        }
        exp1 -= e1;
    }
    else {
        return -99;
    }
    if (exp1 < 0) exp1 = 0;
    if (exp1 > 600) exp1 = 600;
    if (exp2 < 0) exp2 = 0;
    if (exp2 > 600) exp2 = 600;
    return exp1 + exp2;
}


// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
    if (!((E2 >= 0) && (E2 <= 99))) {
        return -99;
    }
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (M1 < 0) M1 = 0;
    if (M1 > 3000) M1 = 3000;
    int S, S1, S2, i;
    double P1, P2;
    //Con duong 1
    i = sqrt(EXP1);
    S1 = i * i;
    S2 = (i + 1) * (i + 1);
    if (S1 == EXP1) S = S1;
    else {
        if (abs(S1 - EXP1) > abs(S2 - EXP1)) S = S2;
        else if (abs(S1 - EXP1) < abs(S2 - EXP1)) S = S1;
    }
    if (EXP1 >= S) P1 = 100;
    else P1 = ((double)EXP1 / S + 80) * 100 / 123;
    //Con duong 2
    int M1Spent = 0;
    double moneyLimit = M1 / 2;
    if (E2 % 2 != 0) {
        while (true) {
            if (HP1 < 200) {
                HP1 = roundNumber(HP1 + 0.3 * HP1);
                M1Spent += 150;
            }
            else {
                HP1 = roundNumber(HP1 + 0.1 * HP1);
                M1Spent += 70;
            }
            //Check thiet lap
            if (HP1 > 666) HP1 = 666;
            //Check dieu kien dung
            if (M1Spent > moneyLimit) break;
            if (EXP1 < 400) {
                EXP1 = roundNumber(1.13 * EXP1);
                M1Spent += 200;
            }
            else {
                EXP1 = roundNumber(1.13 * EXP1);
                M1Spent += 120;
            }
            //Check thiet lap
            if (EXP1 > 600) EXP1 = 600;
            if (M1Spent > moneyLimit) break;
            if (EXP1 < 300) M1Spent += 100;
            else M1Spent += 120;
            EXP1 = roundNumber(EXP1 * 0.9);
            if (M1Spent > moneyLimit) break;
        }
        M1 -= M1Spent;
    }
    else {
        if (M1 != 0) {
            if (HP1 < 200) {
                HP1 = roundNumber(HP1 + 0.3 * HP1);
                M1 -= 150;
            }
            else {
                HP1 = roundNumber(HP1 + 0.1 * HP1);
                M1 -= 70;
            }
            //Check thiet lap
            if (HP1 > 666) HP1 = 666;
            if (M1 > 0) {
                if (EXP1 < 400) M1 -= 200;
                else M1 -= 120;
                EXP1 = roundNumber(EXP1 + 0.13 * EXP1);
                //
                if (EXP1 > 600) EXP1 = 600;
                if (M1 > 0) {
                    if (EXP1 < 300) M1 -= 100;
                    else M1 -= 120;
                    EXP1 = roundNumber(EXP1 - 0.1 * EXP1);
                    if (M1 < 0) M1 = 0;
                }
                else {
                    M1 = 0;
                }
            }
            else {
                M1 = 0;
            }
        }
    }
    HP1 = roundNumber(HP1 - 0.17 * HP1);
    EXP1 = roundNumber(EXP1 + 0.17 * EXP1);
    if (EXP1 > 600) EXP1 = 600;
    //Sac xuat tim duoc vali cua con duong 2:
    i = sqrt(EXP1);
    S1 = i * i;
    S2 = (i + 1) * (i + 1);
    if (S1 == EXP1) S = S1;
    else {
        if (abs(S1 - EXP1) > abs(S2 - EXP1)) S = S2;
        else if (abs(S1 - EXP1) < abs(S2 - EXP1)) S = S1;
    }
    if (EXP1 >= S) P2 = 100;
    else P2 = ((double)EXP1 / S + 80) * 100 / 123;
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    double P3;
    if ((E2 >= 0) && (E2 <= 9)) P3 = P[E2];
    else if ((E2 >= 10) && (E2 <= 99)) {
        int firstNum = E2 / 10;
        int secNum = E2 % 10;
        int twoSum = firstNum + secNum;
        if (twoSum <= 9) P3 = P[twoSum];
        else {
            P3 = P[twoSum % 10];
        }
    }
    double P4;
    if ((P1 == 100) && (P2 == 100) && (P3 == 100)) {
        EXP1 = roundNumber(EXP1 - 0.25 * EXP1);
    }
    else {
        P4 = (P1 + P2 + P3) / 3;
        if (P4 >= 50) {
            HP1 = roundNumber(HP1 - 0.1 * HP1);
            EXP1 = roundNumber(EXP1 + 0.2 * EXP1);
        }
        else {
            HP1 = roundNumber(HP1 - 0.15 * HP1);
            EXP1 = roundNumber(EXP1 + 0.15 * EXP1);
        }
    }
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (M1 < 0) M1 = 0;
    if (M1 > 3000) M1 = 3000;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3)
{
    if (!((E3 >= 0) && (E3 <= 99))) {
        return -99;
    }
    int arr[15][15] = { 0 };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int meetCounti = 0;
    int meetCountj = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] > E3 * 2) meetCounti++;
            if (arr[i][j] < E3 * (-1)) meetCountj++;
        }
    }
    int meetPointi, meetPointj;
    if (meetCounti >= 10) {
        int S1 = meetCounti / 10;
        int S2 = meetCounti % 10;
        int S = S1 + S2;
        meetPointi = S;
        if (S >= 10) {
            int S1 = S / 10;
            int S2 = S % 10;
            int S3 = S1 + S2;
            meetPointi = S3;
        }
    }
    if (meetCountj >= 10) {
        int S1 = meetCountj / 10;
        int S2 = meetCountj % 10;
        int S = S1 + S2;
        meetPointj = S;
        if (S >= 10) {
            int S1 = S / 10;
            int S2 = S % 10;
            int S3 = S1 + S2;
            meetPointj = S3;
        }
    }
    int taxiPoint = arr[meetPointi][meetPointj];
    int max;
    int max1 = arr[meetPointi][meetPointj];
    int max2 = arr[meetPointi][meetPointj];
    int max3 = arr[meetPointi][meetPointj];
    int max4 = arr[meetPointi][meetPointj];
    for (int i = meetPointi - 1, j = meetPointj - 1; i >= 0 && j >= 0; i--, j--) {
        if (max1 < arr[i][j]) max1 = arr[i][j];
    }
    for (int i = meetPointi + 1, j = meetPointj + 1; i < 10 && j < 10; i++, j++) {
        if (max2 < arr[i][j]) max2 = arr[i][j];
    }
    for (int i = meetPointi + 1, j = meetPointj - 1; i < 10 && j >= 0; i++, j--) {
        if (max3 < arr[i][j]) max3 = arr[i][j];
    }
    for (int i = meetPointi - 1, j = meetPointj + 1; i >= 0 && j < 10; i--, j++) {
        if (max4 < arr[i][j]) max4 = arr[i][j];
    }
    max = (max1 > max2) ? max1 : max2;
    max = (max > max3) ? max : max3;
    max = (max > max4) ? max : max4;
    if (max < 0) {
        max = abs(max);
    }
    if (abs(taxiPoint) > max) {
        EXP1 = roundNumber(0.88 * EXP1);
        HP1 = roundNumber(0.9 * HP1);
        EXP2 = roundNumber(0.88 * EXP2);
        HP2 = roundNumber(0.9 * HP2);
        return taxiPoint;
    }
    else {
        EXP1 = roundNumber(1.12 * EXP1);
        HP1 = roundNumber(1.1 * HP1);
        EXP2 = roundNumber(1.12 * EXP2);
        HP2 = roundNumber(1.1 * HP2);
        if (HP1 > 666) HP1 = 666;
        if (HP2 > 666) HP2 = 666;
        if (EXP1 > 600) EXP1 = 600;
        if (EXP2 > 600) EXP2 = 600;
        return max;
    }
    return -1;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    int i = 0;
    char se[100];
    while ((email[i] != '\0') && (email[i] != 64)) {
        se[i] = email[i];
        i++;
    }
    int passCharcount = 0;
    while (s[passCharcount] != '\0') {
        passCharcount++;
    }
    if (passCharcount < 8) {
        return -1;
    }
    else if (passCharcount > 20) {
        return -2;
    }
    //i la tong so ky tu cua se
    if (passCharcount >= i) {
        for (int m = 0; m < passCharcount; m++) {
            if (s[m] == se[0]) {
                int count = 0;
                for (int n = m; n < m + i; n++) {
                    if (s[n] == se[n - m]) count++;
                }
                if (count == i) {
                    return -(300 + m);
                }
            }
        }
    }
    for (int i = 0; i < passCharcount - 2; i++) {
        if ((s[i] == s[i + 1]) && (s[i + 1] == s[i + 2])) {
            return -(400 + i);
        }
    }
    {
        bool contains = true;
        for (int m = 0; m < passCharcount; m++) {
            if ((s[m] == '@') || (s[m] == '#') || (s[m] == '%') || (s[m] == '$') || (s[m] == '!')) {
                contains = false;
                break;
            }
        }
        if (contains) {
            return -5;
        }
    }
    for (int m = 0; m < passCharcount; m++) {
        if (!((s[m] == '!') || (s[m] >= 35 && s[m] <= 37) || (s[m] >= 48 && s[m] <= 57) || (s[m] >= 64 && s[m] <= 90) || (s[m] >= 97 && s[m] <= 122))) {
            return m;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int count[100] = { 0 };
    for (int i = 0; i < num_pwds; i++) {
        for (int j = 0; j < num_pwds; j++) {
            if (arr_pwds[i] == arr_pwds[j]) {
                count[i]++;
            }
        }
    }
    int maxCount = 0;
    int idx = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (count[i] >= maxCount) {
            maxCount = count[i];
            idx = i;
        }
    }
    for (int i = 0; i < num_pwds; i++) {
        if (count[i] == maxCount) {
            if (arr_pwds[i] == arr_pwds[idx]) {
                if (idx > i) {
                    idx = i;
                }
                continue;
            }
            else {
                if (strlen(arr_pwds[i]) > strlen(arr_pwds[idx])) {
                    idx = i;
                }
                else if (strlen(arr_pwds[i]) == strlen(arr_pwds[idx])) {
                    if (idx > i) {
                        idx = i;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < num_pwds; i++) {
        if (arr_pwds[i] == arr_pwds[idx]) {
            idx = i;
            break;
        }
    }
    return idx;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////