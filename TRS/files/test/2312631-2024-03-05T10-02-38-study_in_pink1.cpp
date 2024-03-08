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

void limitHP(int& HP) {
    if (HP > 666) HP = 666;
    else if (HP < 0) HP = 0;
    return;
}

void limitEXP(int& EXP) {
    if (EXP > 600) EXP = 600;
    else if (EXP < 0) EXP = 0;
    return;
}

void limitM(int& M) {
    if (M > 3000) M = 3000;
    else if (M < 0) M = 0;
    return;
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    if (e1 >= 100 || e1 < 0) return -99;
    if (e1 >= 0 && e1 < 4) {
        limitEXP(exp1); limitEXP(exp2);
        if (e1 == 0) exp2 += 29;
        else if (e1 == 1) exp2 += 45;
        else if (e1 == 2) exp2 += 75;
        else if (e1 == 3) exp2 += 149;
        limitEXP(exp2);
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = (exp1 + D / 200.0) + 0.999;
        else exp1 = (exp1 - D / 100.0) + 0.999;
        limitEXP(exp1);
    }
    else if (e1 >= 4 && e1 < 100) {
        limitEXP(exp1); limitEXP(exp2);
        if (e1 >= 4 && e1 < 20) {
            exp2 += (e1 / 4.0 + 19) + 0.999;
        }
        else if (e1 >= 20 && e1 < 50) {
            exp2 += (e1 / 9.0 + 21) + 0.999;
        }
        else if (e1 >= 50 && e1 < 66) {
            exp2 += (e1 / 16.0 + 17) + 0.999;
        }
        else if (e1 >= 66 && e1 < 80) {
            exp2 += (e1 / 4.0 + 19) + 0.999;
            limitEXP(exp2);
            if (exp2 > 200) exp2 += (e1 / 9.0 + 21) + 0.999;
        }
        else if (e1 >= 80 && e1 < 100) {
            exp2 += (e1 / 4.0 + 19) + 0.999;
            exp2 += (e1 / 9.0 + 21) + 0.999;
            limitEXP(exp2);
            if (exp2 > 400) {
                exp2 += (e1 / 16.0 + 17) + 0.999;
                exp2 = exp2 * 1.15 + 0.999;
            }
        }
        limitEXP(exp2);
        exp1 -= e1;
        limitEXP(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int squareroot(float value) {
    float sr = sqrt(value);
    sr = round(sr);
    sr *= sr;
    return sr;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    float P1, P2, P;
    if (E2 >= 100 || E2 < 0) return -99;
    limitHP(HP1); limitEXP(EXP1); limitM(M1);
    int half = M1 / 2;
    //first street 
    int S1 = squareroot(EXP1);
    if (EXP1 >= S1) P1 = 1;
    else P1 = ((EXP1 / S1) + 80.0) / 123.0;
    //second street
    if (M1 != 0) {
        if (E2 % 2 != 0) {
            int spent1 = 0;
            while (spent1 <= half && M1 > 0) {
                if (HP1 < 200) {
                    if (spent1 <= half) {
                        spent1 += 150; 
                        HP1 = (HP1 * 1.3) + 0.999;
                        limitHP(HP1); 
                    }
                }
                else {
                    if (spent1 <= half) {
                        spent1 += 70;
                        HP1 = (HP1 * 1.1) + 0.999;
                        limitHP(HP1); 
                    }
                } 
                if (EXP1 < 400) {
                    if (spent1 <= half) {
                        spent1 += 200;
                        EXP1 = (EXP1 * 1.13) + 0.999;
                        limitEXP(EXP1); 
                    }
                }
                else {
                    if (spent1 <= half) {
                        spent1 += 120;
                        EXP1 = (EXP1 * 1.13) + 0.999;
                        limitEXP(EXP1); 
                    }
                } 
                if (EXP1 < 300) {
                    if (spent1 <= half) {
                        spent1 += 100;
                        EXP1 = (EXP1 * 0.9) + 0.999;
                        limitEXP(EXP1);
                    }
                }
                else {
                    if (spent1 <= half) {
                        spent1 += 120;
                        EXP1 = (EXP1 * 0.9) + 0.999;
                        limitEXP(EXP1);
                    }
                }
            }
            M1 -= spent1; 
            limitM(M1);
        }
        else if (E2 % 2 == 0) {
            int spent2 = 0;
            if (HP1 < 200) {
                if (spent2 < M1) {
                    spent2 += 150;
                    HP1 = (HP1 * 1.3) + 0.999;
                    limitHP(HP1); 
                }
            }
            else {
                if (spent2 < M1) {
                    spent2 += 70;
                    HP1 = (HP1 * 1.1) + 0.999;
                    limitHP(HP1); 
                }
            }
            if (EXP1 < 400) {
                if (spent2 < M1) {
                    spent2 += 200;
                    EXP1 = (EXP1 * 1.13) + 0.999;
                    limitEXP(EXP1); 
                }
            }
            else {
                if (spent2 < M1) {
                    spent2 += 120;
                    EXP1 = (EXP1 * 1.13) + 0.999;
                    limitEXP(EXP1); 
                }
            }
            if (EXP1 < 300) {
                if (spent2 < M1) {
                    spent2 += 100;
                    EXP1 = (EXP1 * 0.9) + 0.999;
                    limitEXP(EXP1); 
                }
            }
            else {
                if (spent2 < M1) {
                    spent2 += 120;
                    EXP1 = (EXP1 * 0.9) + 0.999;
                    limitEXP(EXP1);  
                }
            }
            M1 -= spent2;
            limitM(M1);
        }
    }
    HP1 = (HP1 * 0.83) + 0.999; 
    EXP1 = (EXP1 * 1.17) + 0.999; 
    limitEXP(EXP1); limitHP(HP1);
    int S2 = squareroot(EXP1);
    if (EXP1 >= S2) P2 = 1;
    else P2 = ((EXP1 / S2) + 80.0) / 123.0;
    //third street
    int P3[10] = { 32,47,28,79,100,50,22,83,64,11 };
    if (E2 >= 100 || E2 < 0) return -99;
    if (E2 >= 10 && E2 <= 99) {
        E2 = (E2 / 10) + (E2 % 10); 
        if (E2 >= 10) E2 = E2 % 10;
    }
    //after 3 way
    P = (P1 * 100 + P2 * 100 + P3[E2]) / 3; 
    if (P == 100) {
        EXP1 = (EXP1 * 0.75) + 0.999;
        limitEXP(EXP1);
    }
    else if (P < 50) {
        HP1 = (HP1 * 0.85) + 0.999;
        EXP1 = (EXP1 * 1.15) + 0.999;
        limitEXP(EXP1); limitHP(HP1);
    }
    else if (P > 50) {
        HP1 = (HP1 * 0.9) + 0.999;
        EXP1 = (EXP1 * 1.2) + 0.999;
        limitEXP(EXP1); limitHP(HP1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    int max = 0, i = 0, j = 0; 
    int mt[10][10] = { 0 }, posmt[10][10] = { 0 };
    if (E3 >= 100 || E3 < 0) return -99;
    limitHP(HP1); limitHP(HP2); limitEXP(EXP1); limitEXP(EXP2);
    int upcheck = E3 * 2, downcheck = -1 * E3; 
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            mt[r][c] = ((E3 * c) + (r * 2)) * (r - c);
            if (mt[r][c] >= 0) posmt[r][c] = mt[r][c];
            else posmt[r][c] = abs(mt[r][c]);
            if (mt[r][c] > upcheck) i++;
            if (mt[r][c] < downcheck) j++;
        }
    }
    if (i >= 10 && i <= 99) {
        while (i >= 10) i = (i / 10) + (i % 10); 
    }
    if (j >= 10 && j <= 99) {
        while (j >= 10) j = (j / 10) + (j % 10);
    }
    int i1 = i, i2 = i, i3 = i, i4 = i, j1 = j, j2 = j, j3 = j, j4 = j;
    while (i1 < 10 && j1 < 10) {
        if (mt[i1][j1] > max) max = mt[i1][j1];
        i1++;
        j1++;
    }
    while (i2 >= 0 && j2 >= 0) {
        if (mt[i2][j2] > max) max = mt[i2][j2];
        i2--;
        j2--;
    }
    while (i3 < 10 && j3 >= 0) {
        if (mt[i3][j3] > max) max = mt[i3][j3];
        i3++;
        j3--;
    }
    while (i4 >= 0 && j4 < 10) {
        if (mt[i4][j4] > max) max = mt[i4][j4];
        i4--;
        j4++;
    }
    max = abs(max);

    if (max >= posmt[i][j]) {
        EXP1 = (EXP1 * 1.12) + 0.999;
        limitEXP(EXP1);
        HP1 = HP1 * 1.1 + 0.999;
        limitHP(HP1);
        EXP2 = EXP2 * 1.12 + 0.999;
        limitEXP(EXP2);
        HP2 = HP2 * 1.1 + 0.999;
        limitHP(HP2);
        return max; 
    }
    else {
        EXP1 = EXP1 * 0.88 + 0.999;
        limitEXP(EXP1);
        HP1 = HP1 * 0.9 + 0.999;
        limitHP(HP1);
        EXP2 = EXP2 * 0.88 + 0.999;
        limitEXP(EXP2);
        HP2 = HP2 * 0.9 + 0.999;
        limitHP(HP2);
        return mt[i][j];
    }

    return -1;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    int len1 = strlen(email), len2 = strlen(s);
    if (len1 <= 100) {
        string se = ""; int ord = 0;
        while (email[ord] != '@') {
            se += email[ord];
            ord++;
        }
        if (len2 < 8) return -1;
        else if (len2 > 20) return -2;
        for (int sei = 0; sei < len2; sei++) {
            string secheck = "";
            for (int i = sei; i < ord + sei; i++) {
                if (ord + sei > len2) break;
                else {
                    secheck += s[i];
                }
            }
            if (secheck == se) return -(300 + sei);
        }
        for (int sci = 0; sci < len2; sci++) { 
            if (sci < len2 && (sci + 1) < len2 && (sci + 2) < len2) {
                if (s[sci] == s[sci + 1] && s[sci] == s[sci + 2]) return -(400 + sci); 
            } 
        }
        int ct1 = 0, ct2 = 0, I; 
        for (int i = 0; i < len2; i++) { 
            if (!isalnum(s[i])) { 
                if (s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%') { 
                    ct1++; 
                }
            }
        }
        for (int i = 0; i < len2; i++) { 
            if (!isalnum(s[i])) { 
                if (s[i] != '!' && s[i] != '@' && s[i] != '#' && s[i] != '$' && s[i] != '%') { 
                    ct2++;  
                    I = i; 
                    break;
                }
            }
        } 
        if (ct1 == 0) return -5;  
        else if (ct2 != 0) return I;  
    }
    return -10;
}

// Task 5
struct password {
    int len, fre;
    string pwd;
};

int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    struct password pass[num_pwds]; 
    for (int i = 0; i < num_pwds; i++) {
        pass[i].fre = 0;
        pass[i].len = strlen(arr_pwds[i]); 
        pass[i].pwd = arr_pwds[i];
    }
    for (int i = 0; i < num_pwds; i++) {
        for (int j = 0; j < num_pwds; j++) {
            if (i != j && pass[i].pwd == arr_pwds[j]) pass[i].fre++;
        }
    }
    password passValid = pass[0]; 
    for (int i = 1; i < num_pwds; i++) { 
        if (passValid.fre < pass[i].fre || (passValid.fre == pass[i].fre && passValid.len < pass[i].len)) { 
            passValid = pass[i]; 
        } 
    } 
    for (int i = 0; i < num_pwds; i++) {
        if (passValid.pwd == arr_pwds[i]) return i;
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////