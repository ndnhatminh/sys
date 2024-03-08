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
    if (e1 >= 0 && e1 < 4) {
        if (e1 == 0) {
            exp2 += 29;
        }
        else if (e1 == 1) {
            exp2 += 45;
        }
        else if (e1 == 2) {
            exp2 += 75;
        }
        else if (e1 == 3) {
            exp2 += 149;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = round(exp1 + D / 200 + 0.5);
        }
        else {
            exp1 = round(exp1 - D / 100);
        }
    }
    else if (e1 >= 4 && e1 < 100) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 = exp2 + round(e1 / 4 + 0.5) + 19;
        }
        if (e1 >= 20 && e1 <= 49) {
            exp2 = exp2 + round(e1 / 9 + 0.5) + 21;
        }
        if (e1 >= 50 && e1 <= 65) {
            exp2 = exp2 + round(e1 / 16 + 0.5) + 17;
        }
        if (e1 >= 66 && e1 <= 79) {
            exp2 = exp2 + round(e1 / 4 + 0.5) + 19;
            if (exp2 > 200) {
                exp2 = exp2 + round(e1 / 9 + 0.5) + 21;
            }
        }
        if (e1 >= 80 && e1 <= 99) {
            exp2 = exp2 + round(e1 / 4) + 19;
            exp2 = exp2 + round(e1 / 9) + 21;
            if (exp2 > 400) {
                exp2 = exp2 + round(e1 / 16) + 17;
                exp2 = round(exp2 * 1.15 + 0.5);
            }
        }
        exp1 -= e1;
    }
    else return -99;
    if (exp1 < 0) {
        exp1 = 0;
    }
    if (exp1 > 600) {
        exp1 = 600;
    }
    if (exp2 < 0) {
        exp2 = 0;
    }
    if (exp2 > 600) {
        exp2 = 600;
    }
            return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
        int S = pow(round(sqrt(EXP1)), 2);
    float P1, P2;
    float P;
    int h = round (M1 * 0.5);
    EXP1 = min(max(0, EXP1), 600);
    HP1 = min(max(0, HP1), 666);
    M1 = min(max(0, M1), 3000);
    if (E2 < 0 || E2 > 99) {
        return -99;
    }
    if (EXP1 > S) {
        P1 = 1.0;
    }
    else {
        P1 = (EXP1/S + 80)/123.0;
    }
    if (E2 % 2 != 0) {
        while (M1 >= h) {
            if (HP1 < 200) {
                HP1 = round(HP1 * 1.3 + 0.5);
                M1 -= 150;
                if (M1 < h) {
                    break;
                }
            }
            else {
                HP1 = round(HP1 * 1.1 + 0.5);
                M1 -= 70;
                if (M1 < h) {
                    break;
                }
            }
            if (EXP1 < 400) {
                M1 -= 200;
                EXP1 = round(EXP1 * 1.13 + 0.5);
                if (M1 < h) {
                    break;
                }
            }
            else {
                M1 -= 120;
                EXP1 = round(EXP1 * 1.13 + 0.5);
                if (M1 < h) {
                    break;
                }
            }
            if (EXP1 < 300) {
                M1 -= 100;
                EXP1 = round(EXP1 * 0.9 + 0.5);
                if (M1 < h) {
                    break;
                }
            }
            else {
                M1 -= 120;
                EXP1 = EXP1 * 0.9;
                if (M1 < h) {
                    break;
                }
            }
        }
        EXP1 = round(EXP1 * 1.17 + 0.5);
        HP1 = round(HP1 * 0.83 + 0.5);
    }
    else {
        if (HP1 < 200 && M1 > 0) {
            HP1 = round(HP1 * 1.3 + 0.5);
            M1 -= 150;
        }
        if (HP1 >= 200 && M1 > 0) {
            HP1 = round(HP1 * 1.1 + 0.5);
            M1 -= 70;
        }
        if (EXP1 < 400 && M1 > 0) {
            M1 -= 200;
            EXP1 = round(EXP1 * 1.13 + 0.5);
        }
        if (EXP1 >= 400 && M1 > 0) {
            M1 -= 120;
            EXP1 = round(EXP1 * 1.13 + 0.5);
        }
        if (EXP1 < 300 && M1 > 0) {
            M1 -= 100;
            EXP1 = EXP1 * 0.9;
        }
        if (EXP1 >= 300 && M1 > 0) {
            M1 -= 120;
            EXP1 = round(EXP1 * 0.9 + 0.5);
        }
        EXP1 = round(EXP1 * 1.17 + 0.5);
        HP1 = round(HP1 * 0.83 + 0.5);
    }
    S = pow(round(sqrt(EXP1)), 2);
    if (EXP1 > S) {
        P2 = 1.0;
    }
    else {
        P2 = (EXP1 / S + 80) / 123.0;
    }
    float P3[10] = { 0.32,0.47,0.28,0.79,1,0.50,0.22,0.83,0.64,0.11 };
    int i;
    if (E2 < 10) {
        i = E2;
    }
    else {
        int t = E2 / 10 + E2 % 10;
        i = t % 10;
    }
    if (P1 == 1.0 && P2 == 1.0 && P3[i] == 1.0) {
        EXP1 = round(EXP1 * 0.75 + 0.5);
    }
    else {
        P = (P1 + P2 + P3[i])/3;
        if (P < 0.5) {
            HP1 = round(HP1 * 0.85 + 0.5);
            EXP1 = round(EXP1 * 1.15 + 0.5);
        }
        else {
            HP1 = round(HP1 * 0.9 + 0.5);
            EXP1 = round(EXP1 * 1.2 + 0.5);
        }
    }
    EXP1 = min(max(0, EXP1), 600);
    HP1 = min(max(0, HP1), 666);
    M1 = min(max(0, M1), 3000);
    return EXP1 + HP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    int ls = strlen(s);
    if (ls < 8) {
        return -1;
    }
    if (ls > 20) {
        return -2;
    }
    string s1(s);
    string e1(email);
    int pos = e1.find('@');
    string se = e1.substr(0, pos);
    int pos1 = s1.find(se);
    if (pos != string::npos) {
        return -(300 + pos1);
    }
    for (int i = 0; i < ls - 1; ++i) {
        if (s[i] == s[i + 1]) {
            return -(400 + i); 
            break;
        }
    }
    bool spChar = false;
    for (int i = 0; i <= ls; ++i) {
        char c = s[i];
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
            spChar = true;
            break;
        }
    }
    if (!spChar) return -5;
    return -10; 
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int ap[30] = { 0 };
    for (int i = 0; i < num_pwds; i++) {
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                ap[i]++;
            }
        }
    }
    int max = 0;
    int mlen = 0;
    int t = 0;
    for (int i = 0; i < num_pwds; ++i) {
        if (ap[i] > max || (ap[i] == max && strlen(arr_pwds[i]) > mlen)) {
            max = ap[i];
            mlen = strlen(arr_pwds[i]);
            t = i;
        }
    }
    return t;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
