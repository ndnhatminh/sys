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

// CheckHP
void adjust_HP(int &HP1, int &HP2) {
    if (HP1 > 666) {
        HP1 = 666;
    }
    else if (HP1 < 0) {
        HP1 = 0;

    }
    if (HP2 > 666) {
        HP2 = 666;
    }
    else if (HP2 < 0) {
        HP2 = 0;
    }
}
// CheckEXP
void adjust_EXP(int &EXP1, int &EXP2) {
    if (EXP1 > 600) {
        EXP1 = 600;
    }
    else if (EXP1 < 0) {
        EXP1 = 0;

    }
    if (EXP2 > 600) {
        EXP2 = 600;
    }
    else if (EXP2 < 0) {
        EXP2 = 0;
    }
}
//CheckMoney
void adjust_M(int &M1, int &M2) {
    if (M1 > 3000) {
        M1 = 3000;
    }
    else if (M1 < 0) {
        M1 = 0;

    }
    if (M2 > 3000) {
        M2 = 3000;
    }
    else if (M2 < 0) {
        M2 = 0;
    }
}
//CheckDuplication
bool CheckDuplication(const char* pass1, const char* pass2) {
    int index = 0;
    while ((pass1[index] != '\0') || (pass2[index] != '\0')) {
        if (pass1[index] != pass2[index]) {
            return false;
        }
        index++;
    }
    return true;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 < 0 || e1 > 99) {
        return -99;
    }
    else;
    adjust_EXP(exp1, exp2);
    if (0 <= e1 && e1 <= 3) {
        switch (e1) {
        case 0: exp2 += 29; break; 
        case 1: exp2 += 45; break;
        case 2: exp2 += 75; break;
        case 3: exp2 += (29 + 45 + 75); break;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = ceilf(exp1 + D * 1.00 / 200);
        }
        else {
            exp1 = ceilf(exp1 - D * 1.00 / 100);
        }
        adjust_EXP(exp1, exp2);
    }
    else {
        if (4 <= e1 && e1 <= 19) {
            exp2 = ceilf(exp2 + e1 * 1.00 / 4 + 19);
        }
        else if (20 <= e1 && e1 <= 49) {
            exp2 = ceilf(exp2 + e1 * 1.00 / 9 + 21);
        }
        else if (50 <= e1 && e1 <= 65) {
            exp2 = ceilf(exp2 + e1 * 1.00 / 16 + 17);
        }
        else if (66 <= e1 && e1 <= 79) {
            exp2 = ceilf(exp2 + e1 * 1.00 / 4 + 19);
            if (exp2 > 200) {
                exp2 = ceilf(exp2 + e1 * 1.00 / 9 + 21);
            }
        }
        else if (80 <= e1 && e1 <= 99) {
            exp2 = ceilf(exp2 + e1 * 1.00 / 4 + 19);
            exp2 = ceilf(exp2 + e1 * 1.00 / 9 + 21);
            if (exp2 > 400) {
                exp2 = ceilf(exp2 + e1 * 1.00 / 16 + 17);
                exp2 = ceilf(exp2 + 0.15 * exp2);
            }
        }
        else;
        exp1 -= e1;
        adjust_EXP(exp1, exp2);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99) {
        return -99;
    }
    adjust_EXP(EXP1, EXP1);
    adjust_HP(HP1, HP1);
    adjust_M(M1, M1);
    int S1  = sqrt(EXP1);
    if (abs(S1 * S1 - EXP1) < abs((S1+ 1) * (S1 + 1) - EXP1)) {
        S1 = S1 * S1;
    }
    else {
        S1 = (S1 + 1) * (S1 + 1);
    }
    double P1, P2, P3;
    int paid = 0;
    double half_budget = 0.5 * M1;
    if (EXP1 >= S1) {
        P1 = 100;
    }
    else {
        P1 = (EXP1 * 1.00 / S1 + 80) * 100 / 123;
    }
    if (M1 == 0);
    else {
        do {
            if (HP1 < 200) {
                HP1 = ceilf(1.3 * HP1);
                M1 -= 150;
                paid += 150;
            }
            else {
                HP1 = ceilf(1.1 * HP1);
                M1 -= 70;
                paid += 70;
            }
            adjust_HP(HP1, HP1);
            adjust_M(M1, M1);
            if (M1 == 0) {
                break;
            }
            else if (paid > half_budget && E2 % 2 != 0) {
                break;
            }
            if (EXP1 < 400) {
                M1 -= 200;
                paid += 200;
            }
            else {
                M1 -= 120;
                paid += 120;
            }
            EXP1 = ceilf(1.13 * EXP1);
            adjust_EXP(EXP1, EXP1);
            adjust_M(M1, M1);
            if (M1 == 0) {
                break;
            }
            else if (paid > half_budget && E2 % 2 != 0) {
                break;
            }
            if (EXP1 < 300) {
                M1 -= 100;
                paid += 100;
            }
            else {
                M1 -= 120;
                paid += 120;
            }
            EXP1 = ceilf(0.9 * EXP1);
            adjust_EXP(EXP1, EXP1);
            adjust_M(M1, M1);
            if (M1 == 0) {
                break;
            }
            else if (paid > half_budget && E2 % 2 != 0) {
                break;
            }
        } while (paid <= half_budget && E2 % 2 != 0);
    }
    HP1 = ceilf(0.83 * HP1);
    EXP1 = ceilf(1.17 * EXP1);
    adjust_HP(HP1, HP1);
    adjust_EXP(EXP1, EXP1);
    int S2 = sqrt(EXP1);
    if (abs(S2 * S2 - EXP1) < abs((S2 + 1) * (S2 + 1) - EXP1)) {
        S2 = S2 * S2;
    }
    else {
        S2 = (S2 + 1) * (S2 + 1);
    }
    if (EXP1 >= S2) {
        P2 = 100;
    }
    else {
        P2 = (EXP1 * 1.00 / S2 + 80) * 100 / 123;
    }
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    P3 = P[(E2 % 10 + (E2 / 10) % 10) % 10];
    if (P1 + P2 + P3 == 300) {
        EXP1 = ceilf(0.75 * EXP1);
    }
    else if (P1 + P2 + P3 < 150) {
        HP1 = ceilf(0.85 * HP1);
        EXP1 = ceilf(1.15 * EXP1);
    }
    else {
        HP1 = ceilf(0.9 * HP1);
        EXP1 = ceilf(1.2 * EXP1);
    }
    adjust_HP(HP1, HP1);
    adjust_EXP(EXP1, EXP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) {
        return -99;
    }
    adjust_HP(HP1, HP2);
    adjust_EXP(EXP1, EXP2);
    int taxi_matrix[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxi_matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int pos_nums = 0, neg_nums = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (taxi_matrix[i][j] > (E3 * 2)) {
                pos_nums += 1;
            }
            if (taxi_matrix[i][j] < (-1 * E3)) {
                neg_nums += 1;
            }
        }
    }
    int i, j;
    i = (pos_nums % 10 + (pos_nums / 10) % 10);
    i = i % 10 + (i / 10) % 10;
    j = (neg_nums % 10 + (neg_nums / 10) % 10);
    j = j % 10 + (j / 10) % 10;
    int max_num = 0;
    int incri = i, decrj = j;
    while ((0 <= incri && incri < 10) && (0 <= decrj && decrj < 10)) {
        if (taxi_matrix[incri][decrj] >= max_num) {
            max_num = taxi_matrix[incri][decrj];
        }
        if (incri <= i && decrj >= j) {
            incri--;
            decrj++;
        }
        else {
            incri++;
            decrj--;
        }
        if (incri == -1 || decrj == 10) {
            incri = i + 1;
            decrj = j - 1;
        }
    }
    int incr_i = i, incr_j = j;
    while ((0 <= incr_i && incr_i < 10) && (0 <= incr_j && incr_j < 10)) {
        if (taxi_matrix[incr_i][incr_j] >= max_num) {
            max_num = taxi_matrix[incr_i][incr_j];
        }
        if (incr_i >= i && incr_j >= j) {
            incr_i++;
            incr_j++;
        }
        else {
            incr_i--;
            incr_j--;
        }
        if (incr_i == 10 || incr_j == 10) {
            incr_i = i - 1;
            incr_j = j - 1;
        }
    }
    if (abs(taxi_matrix[i][j]) <= abs(max_num)) {
        EXP1 = ceilf(1.12 * EXP1);
        EXP2 = ceilf(1.12 * EXP2);
        HP1 = ceilf(1.1 * HP1);
        HP2 = ceilf(1.1 * HP2);
        adjust_HP(HP1, HP2);
        adjust_EXP(EXP1, EXP2);
        return max_num;
    }
    else {
        EXP1 = ceilf(0.88 * EXP1);
        EXP2 = ceilf(0.88 * EXP2);
        HP1 = ceilf(0.9 * HP1);
        HP2 = ceilf(0.9 * HP2);
        adjust_HP(HP1, HP2);
        adjust_EXP(EXP1, EXP2);
        return taxi_matrix[i][j];
    }
}

// Task 4
int checkPassword(const char* s, const char* email) {
    char se[150];
    int k = 0;
    while (email[k] != 64) {
        se[k] = email[k];
        k++;
    }
    se[k] = '\0';
    if (strlen(s) < 8) {
        return -1;
    }
    else if (strlen(s) > 20) {
        return -2;
    }
    const char *address;
    address = strstr(s, se);
    if (address != 0) {
        return -(300 + address - s);
    }
    int index = 0, count_same = 0, count_spec = 0, count_strange = 0;
    int st_same = 0, st_strange = 0;
    for (; index < strlen(s); index++) {
        if (s[index] == s[index + 1] && s[index] == s[index + 2]) {
            if (count_same == 0) {
                st_same = index;
                count_same++;
            }
        }
        else if ((s[index] == 33) || (s[index] == 35) || (s[index] == 36) || (s[index] == 37) || (s[index] == 64)) {
                count_spec++;
        }
        else if ((s[index] < 48) || ((s[index] > 57) && (s[index] < 65)) || ((s[index] > 90) && (s[index] < 97)) || (s[index] > 122)) {
            if (count_strange == 0) {
                st_strange = index;
                count_strange++;
            }
        }
    }
    if (count_same != 0) {
        return -(400 + st_same);
    }
    else if (count_spec == 0) {
        return -5;
    }
    else if (count_strange != 0) {
        return st_strange;
    }
    else {
        return -10;
    }    
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int quantity[100], freq = 0, max_freq = 0, index_max_freq_st = 0;
    for (int m = 0; m < num_pwds; m++) {
        freq = 0;
        for (int n = 0; n < num_pwds; n++) {
            if(CheckDuplication(arr_pwds[m], arr_pwds[n])){
                freq++;
            }
        }
        quantity[m] = freq;
        if (freq > max_freq) {
            max_freq = freq;
            index_max_freq_st = m;
        }
    }
    for (int z = 0; z < num_pwds; z++) {
        if (((quantity[z] == max_freq) && (strlen(arr_pwds[z]) > strlen(arr_pwds[index_max_freq_st])))) {
            index_max_freq_st = z;
        }
        else;
    }
    return index_max_freq_st;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////