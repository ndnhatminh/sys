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
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    int D = E1 * 3 + EXP1 * 7;
    if (E1 >= 0 && E1 <= 3) {
        if (E1 == 0) {
            EXP2 += 29;
        }
        else if (E1 == 1) {
            EXP2 += 45;
        }
        else if (E1 == 2) {
            EXP2 += 75;
        }
        else if (E1 == 3) {
            EXP2 += 29 + 45 + 75;
        }
        if (D % 2 == 0) {
        EXP1 += ceil(D / 200.0);
        } else {
        EXP1 -= ceil(D / 100);
    }
    }  
    if (E1 >= 4 && E1 <= 99) {
        if (E1 >= 4 && E1 <= 19) {
            EXP2 += ceil((E1 / 4.0) + 19);
        }
        else if (E1 >= 20 && E1 <= 49) {
            EXP2 += ceil((E1 / 9.0) + 21);
        }
        else if (E1 >= 50 && E1 <= 65) {
            EXP2 += ceil((E1 / 16.0) + 17);
        }
        else if (E1 >= 66 && E1 <= 79) {
            EXP2 += ceil((E1 / 4.0) + 19);
            if (EXP2 > 200) EXP2 += ceil((E1 / 9.0) + 21);
        }
        else if (E1 >= 80 && E1 <= 99) {
            EXP2 += ceil((E1 / 4.0) + 19) + ceil((E1 / 9.0) + 21);
            if (EXP2 > 400) {
                EXP2 += ceil((E1 / 16.0) + 17);
                EXP2 += ceil(EXP2 * 0.15);
            }
        }
        EXP1 -= E1;
    }

    EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600 : EXP1;
    EXP2 = (EXP2 < 0) ? 0 : (EXP2 > 600) ? 600 : EXP2;

    if (E1 < 0 || E1 > 99) return -99;

    return EXP2 + EXP1;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    if (E2 > 99 || E2 < 0) return -99;

    double S, S2, P1, P2;
    double mspent = 0;
    double mstart = M1;
    S = pow(round(sqrt(EXP1)),2);
    
    if (EXP1 >= S) P1 = 1.0;
    else P1 = ((EXP1/S) + 80) / 123.0;

    while (E2 % 2 == 1) {
    if (HP1 < 200) {
        HP1 += ceil(float(HP1 * 30.0/100));
        mspent += 150.0;
        M1 -= 150.0;
    }
    else {
        HP1 += ceil(float(HP1 * 10.0/100));
        mspent += 70.0;
        M1 -= 70.0;
    }

    HP1 = (HP1 < 0) ? 0 : (HP1 > 666) ? 666 : HP1;

    if (mspent > 0.5 * mstart) break;

    if (EXP1 < 400) {
        EXP1 += ceil(EXP1 * 13.0/100);
        mspent += 200.0;
        M1 -= 200.0;
    }
    else {
        EXP1 += ceil(EXP1 * 13.0/100);
        mspent += 120.0;
        M1 -= 120.0;
    }

    EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600 : EXP1;

    if (mspent > 0.5 * mstart) break;

    if (EXP1 < 300) {
        mspent += 100.0;
        EXP1 = ceil(EXP1 * 90.0/100);
        M1 -= 100.0;
    }
    else {
        mspent += 120.0;
        EXP1 = ceil(EXP1 * 90.0/100);
        M1 -= 120.0;
    }

    EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600 : EXP1;

    if (mspent > 0.5 * mstart) break;

}

while (E2 % 2 == 0) {
    if (HP1 < 200) {
        HP1 += ceil(float(HP1 * 30.0/100));
        mspent += 150.0;
        M1 -= 150.0;
    }
    else {
        HP1 += ceil(float(HP1 * 10.0/100));
        mspent += 70.0;
        M1 -= 70.0;
    }

    HP1 = (HP1 < 0) ? 0 : (HP1 > 666) ? 666 : HP1;

    if (M1 <= 0) break;

    if (EXP1 < 400) {
        EXP1 += ceil(EXP1 * 13.0/100);
        mspent += 200.0;
        M1 -= 200.0;
    }
    else {
        mspent += 120.0;
        EXP1 += ceil(EXP1 * 13.0/100);
        M1 -= 120.0;
    }

    EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600 : EXP1;

    if (M1 <= 0) break;

    if (EXP1 < 300) {
        mspent += 100.0;
        EXP1 = ceil(EXP1 * 90.0/100);
        M1 -= 100.0;
    }
    else {
        mspent += 120.0;
        EXP1 = ceil(EXP1 * 90.0/100);
        M1 -= 120.0;
    }

    EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600 : EXP1;
    
    break;
}

    HP1 = ceil(float(HP1 * 83.0/100));
    EXP1 += ceil(EXP1 * 17.0/100);

    HP1 = (HP1 < 0) ? 0 : (HP1 > 666) ? 666 : HP1;
    EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600 : EXP1;

    S2 = pow(round(sqrt(EXP1)),2);
    if (EXP1 >= S2) P2 = 1.0;
    else P2 = (EXP1/S2 + 80) / 123.0;

    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P3 = 0.0;
    int sum = ((E2 / 10) % 10) + (E2 % 10);
    int i;
    if (E2 < 10) {
        i = E2;
    } else {
        i = sum % 10;
    }
    P3 = P[i] / 100.0;

    if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0) {
        EXP1 -= ceil(EXP1 * 25.0/100);
    } else {
        double P0 = (P1 + P2 + P3) / 3.0;
        if (P0 < 0.5) {
            HP1 = ceil(HP1 * 85.0/100);
            EXP1 += ceil(EXP1 * 15.0/100);
        } else {
            HP1 = ceil(HP1 * 90.0/100);
            EXP1 += ceil(EXP1 * 20.0/100);
        }
    }

    EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600 : EXP1;
    HP1 = (HP1 < 0) ? 0 : (HP1 > 666) ? 666 : HP1;
    M1 = (M1 < 0) ? 0 : (M1 > 3000) ? 3000 : M1;

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    if (E3 > 99 || E3 < 0) return -99;

    int map[10][10] = {0};
    int gps[10][10] = {0};
    int taxipoint, teampoint;
    int i, j;

    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            int leftline = INT_MIN, rightline = INT_MIN;

            for (int k = 0; k < 10; ++k) {
                if (i - k >= 0 && j - k >= 0) {
                    leftline = max(leftline, map[i - k][j - k]);
                }
                if (i + k < 10 && j + k < 10) {
                    leftline = max(leftline, map[i + k][j + k]);
                }
            }

            for (int k = 0; k < 10; ++k) {
                if (i - k >= 0 && j + k < 10) {
                    rightline = max(rightline, map[i - k][j + k]);
                }
                if (i + k < 10 && j - k >= 0) {
                    rightline = max(rightline, map[i + k][j - k]);
                }
            }

            gps[i][j] = max(abs(leftline), abs(rightline));
        }
    }

    int num1 = 0, num2 = 0;
    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            if (map[i][j] > E3 * 2) ++num1;
            if (map[i][j] < -E3) ++num2;
        }
    }

    i = num1;
    while (i >= 10) i = i / 10 + i % 10;
    j = num2;
    while (j >= 10) j = j / 10 + j % 10;

    taxipoint = abs(map[i][j]);
    teampoint = gps[i][j];

    if (taxipoint > teampoint) {
        HP1 = ceil(HP1 * 90.0/100);
        EXP1 = ceil(EXP1 * 88.0/100);
        HP2 = ceil(HP2 * 90.0/100);
        EXP2 = ceil(EXP2 * 88.0/100);
    } else {
        HP1 += ceil(HP1 * 10.0/100);
        EXP1 += ceil(EXP1 * 12.0/100);
        HP2 += ceil(HP2 * 10.0/100);
        EXP2 += ceil(EXP2 * 12.0/100);
    }

    EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600 : EXP1;
    HP1 = (HP1 < 0) ? 0 : (HP1 > 666) ? 666 : HP1;
    EXP2 = (EXP2 < 0) ? 0 : (EXP2 > 600) ? 600 : EXP2;
    HP2 = (HP2 < 0) ? 0 : (HP2 > 666) ? 666 : HP2;

    return max(taxipoint, teampoint) * (taxipoint > teampoint ? -1 : 1);

}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    string se = email;
    se = se.substr(0, se.find('@'));

    string pass(s);

    if (pass.length() < 8) return -1;
    if (pass.length() > 20) return -2;

    size_t check = pass.find(se);
    if (check != string::npos) return -(300 + check);

    for (size_t i = 0; i < pass.length() - 2; ++i) {
        if (pass[i] == pass[i + 1] && pass[i] == pass[i + 2]) return -(400 + i);
    }

    bool specchar = false;
    for (char c: pass) {
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
            specchar = true;
            break;
        }
    }
    if (!specchar) return -5;

    for (size_t i = 0; i < pass.length(); ++i) {
        char c = pass[i];
        if (!(isdigit(c) || islower(c) || isupper(c) || c == '@' || c == '#' || c == '%' || c == '$' || c == '!')) {
            return i;
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    int maxcount = 0;
    int maxleng = 0;
    int correctpass = -1;

    for (int i = 0; i < num_pwds; ++i) {
        const char *curpwd = arr_pwds[i];
        int curleng = strlen(curpwd);
        int curcount = 1;

        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(curpwd, arr_pwds[j]) == 0) {
                curcount++;
            }
        }

        if (curcount > maxcount || (curcount == maxcount && curleng > maxleng)) {
            maxcount = curcount;
            maxleng = curleng;
            correctpass = i;
        }
    }

    if (num_pwds <= 0) {
        return -1;
    }

    return correctpass;

}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////