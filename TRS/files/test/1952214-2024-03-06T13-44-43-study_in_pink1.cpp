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

// Helper function
void updateHP(int & hp) {
    if (hp < 0) {
        hp = 0;
    } else if (hp > 666) {
        hp = 666;
    }
}

void updateEXP(int & exp) {
    if (exp < 0) {
        exp = 0;
    } else if (exp > 600) {
        exp = 600;
    }
}

void updateM(int & m) {
    if (m < 0) {
        m = 0;
    } else if (m > 3000) {
        m = 3000;
    }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || 99 < e1) { // out of range
        return -99;
    }

    updateEXP(exp1);
    updateEXP(exp2);

    if (0 <= e1 && e1 <= 3) { // case 1
        if (e1 == 0) { // info 1
            exp2 += 29;
        } else if (e1 == 1) { // info 2
            exp2 += 45;
        } else if (e1 == 2) { // info 3
            exp2 += 75;
        } else if (e1 == 3) { // all 3 info
            exp2 += 29 + 45 + 75;
        }
        updateEXP(exp2);

        // Holmes's Decision
        int d = e1*3 + exp1*7;
        if (d % 2 == 0) { // even - true
            exp1 += d/200.0 + 0.999;
        } else { // odd - false
            exp1 -= d/100.0 - 0.999;
        }
        updateEXP(exp1);
    } else if (4 <= e1 && e1 <= 99) { // case 2
        if (4 <= e1 && e1 <= 19) { // info 1
            exp2 += e1/4.0 + 19.999;
        } else if (20 <= e1 && e1 <= 49) { // info 2
            exp2 += e1/9.0 + 21.999;
        } else if (50 <= e1 && e1 <= 65) { // info 3
            exp2 += e1/16.0 + 17.999;
        } else if (66 <= e1 && e1 <= 79) {
            // info 1
            exp2 += e1/4.0 + 19.999;
            if (exp2 > 200) { // info 2
                exp2 += e1/9.0 + 21.999;
            }
        } else if (80 <= e1 && e1 <= 99) {
            // info 1
            exp2 += e1/4.0 + 19.999;
            // info 2
            exp2 += e1/9.0 + 21.999;
            if (exp2 > 400) { // info 3
                exp2 += e1/16.0 + 17.999;
                // bonus 15% EXP
                exp2 += exp2*0.15 + 0.999;
            }
        }
        updateEXP(exp2);
        
        // Holmes's mistake
        exp1 -= e1;
        updateEXP(exp1);
    }

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || 99 < E2) { // E out of range
        return -99;
    }

    updateHP(HP1);
    updateEXP(EXP1);
    updateM(M1);

    // Road 1
    double S = pow(round(sqrt(EXP1)), 2);
    double P1;
    if (EXP1 >= S) {
        P1 = 100;
    } else {
        P1 = 100 * (EXP1 / S + 80) / 123;
    }

    // Road 2
    double P2;
    double spent = 0;
    double half = M1*0.5;
    do {
        if (M1) { // Grocery Store
            if (HP1 < 200) { // buy food and water
                HP1 += HP1*0.3 + 0.999;
                updateHP(HP1);
                M1 -= 150;
                updateM(M1);
                spent += 150;
            } else { // water only
                HP1 += HP1*0.1 + 0.999;
                updateHP(HP1);
                M1 -= 70;
                updateM(M1);
                spent += 70;
            }
        } else {
            break;
        }
        if (E2 % 2 != 0 && spent > half) {
            break;
        }
        
        if (M1) { // rent vehicle
            if (EXP1 < 400) { // taxi
                M1 -= 200;
                updateM(M1);
                spent += 200;
            } else { // carriage
                M1 -= 120;
                updateM(M1);
                spent += 120;
            }
            EXP1 += EXP1*0.13 + 0.999;
            updateEXP(EXP1);
        } else {
            break;
        }
        if (E2 % 2 != 0 && spent > half) {
            break;
        }
        
        if (M1) { // meet a homeless
            if (EXP1 < 300) {
                M1 -= 100;
                updateM(M1);
                spent += 100;
            } else {
                M1 -= 120;
                updateM(M1);
                spent += 120;
            }
            EXP1 -= EXP1*0.1 - 0.999;
            updateEXP(EXP1);
        } else {
            break;
        }
        if (E2 % 2 != 0 && spent > half) {
            break;
        }
    } while (E2 % 2 != 0);

    // At the end of road 2
    HP1 -= HP1*0.17 - 0.999;
    updateHP(HP1);
    EXP1 += EXP1*0.17 + 0.999;
    updateEXP(EXP1);
    S = pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= S) {
        P2 = 100;
    } else {
        P2 = 100 * (EXP1 / S + 80) / 123;
    }

    // Road 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P3;
    if (E2 < 10) {
        P3 = P[E2];
    } else {
        P3 = P[(E2/10 + E2%10) % 10];
    }

    // Result
    if (P1 == 100 && P2 == 100 && P3 == 100) {
        EXP1 -= EXP1*0.25 - 0.999;
        updateEXP(EXP1);
    } else {
        double P_average = (P1 + P2 + P3) / 3;
        if (P_average < 50) {
            HP1 -= HP1*0.15 - 0.999;
            updateHP(HP1);
            EXP1 += EXP1*0.15 + 0.999;
            updateEXP(EXP1);
        } else {
            HP1 -= HP1*0.1 - 0.999;
            updateHP(HP1);
            EXP1 += EXP1*0.2 + 0.999;
            updateEXP(EXP1);
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || 99 < E3) { // E out of range
        return -99;
    }

    updateHP(HP1);
    updateEXP(EXP1);
    updateHP(HP2);
    updateEXP(EXP2);

    int i0 = 0, j0 = 0;
    int matrix[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (matrix[i][j] > E3*2) {
                i0++;
            } else if (matrix[i][j] < -E3) {
                j0++;
            }
        }
    }

    while (i0 > 9) {
        i0 = i0/10 + i0%10;
    }
    while (j0 > 9) {
        j0 = j0/10 + j0%10;
    }

    int SnW = matrix[i0][j0];
    // main diagonal
    for (int i = 0; i < 10; i++) {
        if (i0 + i < 10 && j0 + i < 10) {
            if (matrix[i0 + i][j0 + i] > SnW) {
                SnW = matrix[i0 + i][j0 + i];
            }
        }
        if (i0 - i >= 0 && j0 - i >= 0) {
            if (matrix[i0 - i][j0 - i] > SnW) {
                SnW = matrix[i0 - i][j0 - i];
            }
        }
    }
    // secondary diagonal
    for (int i = 0; i < 10; i++) {
        if (i0 + i < 10 && j0 - i >= 0) {
            if (matrix[i0 + i][j0 - i] > SnW) {
                SnW = matrix[i0 + i][j0 - i];
            }
        }
        if (i0 - i >= 0 && j0 + i < 10) {
            if (matrix[i0 - i][j0 + i] > SnW) {
                SnW = matrix[i0 - i][j0 + i];
            }
        }
    }
    SnW = abs(SnW);

    if (abs(matrix[i0][j0]) > SnW) {
        EXP1 -= EXP1*0.12 - 0.999;
        updateEXP(EXP1);
        HP1 -= HP1*0.1 - 0.999;
        updateHP(HP1);

        EXP2 -= EXP2*0.12 - 0.999;
        updateEXP(EXP2);
        HP2 -= HP2*0.1 - 0.999;
        updateHP(HP2);

        return matrix[i0][j0];
    } else {
        EXP1 += EXP1*0.12 + 0.999;
        updateEXP(EXP1);
        HP1 += HP1*0.1 + 0.999;
        updateHP(HP1);

        EXP2 += EXP2*0.12 + 0.999;
        updateEXP(EXP2);
        HP2 += HP2*0.1 + 0.999;
        updateHP(HP2);

        return SnW;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    if (strlen(s) < 8) {
        return -1;
    }
    if (strlen(s) > 20) {
        return -2;
    }

    bool special_char = false;
    int illegal_char = -1;
    int se_index = -1;
    int sc_index = -1;
    int se_count = 0;
    int sc_count = 1;
    int se_length = 0;
    while (email[se_length] != '@') {
        se_length++;
    }
    char * se = new char[se_length+1];
    strncpy(se, email, se_length);
    se[se_length] = '\0';

    for (int i = 0; i < strlen(s); i++) { // S: [0-9a-zA-Z@#%$!];
        if (illegal_char == -1 && 
                !(('0' <= s[i] && s[i] <= '9') || ('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') 
                || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')) {
            illegal_char = i;
        } else {
            if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
                special_char = true;
            }
            if (sc_index == -1) {
                if (i != 0 && s[i] == s[i-1]) {
                    sc_count++;
                    if (sc_count == 3) {
                        sc_index = i - 2;
                    }
                } else if (sc_count != 1) {
                    sc_count = 1;
                }
            }
            if (se_index == -1) {
                if (s[i] == se[se_count]) {
                    se_count++;
                    if (se_count == strlen(se)) {
                        se_index = i - se_count + 1;
                    }
                } else if (se_count) {
                    se_count = 0;
                }
            }
        }
    }

    if (se_index != -1) { // s contains se
        return -(300 + se_index);
    }
    if (sc_index != -1) { // s contains more than 2 of the same characters
        return -(400 + sc_index);
    }
    if (!special_char) { // s does not contain any special characters
        return -5;
    }
    if (illegal_char != -1) { // s contains illegal characters
        return illegal_char;
    }
    return -10; // valid password
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_length = 0;
    int max_count = 0;
    int index = -1;
    for (int i = 0; max_count < num_pwds - i + 1; i++) {
        int count = 1;
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }
        if (count > max_count || (count == max_count && strlen(arr_pwds[i]) > max_length)) {
            max_count = count;
            max_length = strlen(arr_pwds[i]);
            index = i;
        }
    }

    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////