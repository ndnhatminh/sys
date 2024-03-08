#include "study_in_pink1.h"

bool readFile(
        const string &filename,
        int &HP1,
        int &HP2,
        int &EXP1,
        int &EXP2,
        int &M1,
        int &M2,
        int &E1,
        int &E2,
        int &E3
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
    } else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////


int checkValidHP(int HP) {
    if (HP < 0) {
        HP = 0;
    } else if (HP > 666) {
        HP = 666;
    }
    return HP;
}

int checkValidEXP(int EXP) {
    if (EXP < 0) {
        EXP = 0;
    } else if (EXP > 600) {
        EXP = 600;
    }
    return EXP;
}

int checkValidM(int M) {
    if (M < 0) {
        M = 0;
    } else if (M > 3000) {
        M = 3000;
    }
    return M;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) {
        return -99;
    }
    int D;
    exp1 = checkValidEXP(exp1);
    exp2 = checkValidEXP(exp2);

    if (e1 <= 3) {
        if (e1 == 0) {
            exp2 += 29;
        } else if (e1 == 1) {
            exp2 += 45;
        } else if (e1 == 2) {
            exp2 += 75;
        } else {
            exp2 += 149;
        }
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = ceil(exp1 + (D / 200.0));
        } else {
            exp1 = ceil(exp1 - (D / 100.0));
        }
    } else if (e1 >= 4) {
        if (e1 <= 19) {
            exp2 += ceil(float(e1 / 4.0 + 19));
        } else if (e1 >= 20 && e1 <= 49) {
            exp2 += ceil(float(e1 / 9.0 + 21));
        } else if (e1 >= 50 && e1 <= 65) {
            exp2 += ceil(float(e1 / 16.0 + 17));
        } else if (e1 >= 66 && e1 <= 79) {
            exp2 += ceil(float(e1 / 4.0 + 19));
            if (exp2 > 200) {
                exp2 += ceil(float(e1 / 9.0 + 21));
            }
        } else if (e1 >= 80) {
            exp2 += ceil(float(e1 / 4.0 + 19));
            exp2 += ceil(float(e1 / 9.0 + 21));
            if (exp2 > 400) {
                exp2 += ceil(float(e1 / 16.0 + 17));
                exp2 += ceil(float(0.15 * exp2));
            }
        }

        exp1 -= e1;
    }

    exp1 = checkValidEXP(exp1);
    exp2 = checkValidEXP(exp2);
    return exp1 + exp2;
}


// Task 2
int nearestSquare(int N) {
    double root = sqrt(N);

    if (root == floor(root)) {
        return N;
    }

    int low_int = floor(root);
    int up_int = low_int + 1;

    int low_square = low_int * low_int;
    int up_square = up_int * up_int;

    return abs(N - low_square) < abs(N - up_square) ? low_square : up_square;
}


int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) {
        return -99;
    }
    double S, P1, P2, P3, P_final, M;
    int M_pay = 0;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    HP1 = checkValidHP(HP1);
    EXP1 = checkValidEXP(EXP1);
    M1 = checkValidM(M1);
    M = M1;


    S = nearestSquare(EXP1);
    if (EXP1 >= S) {
        P1 = 1;
    } else {
        P1 = float(((EXP1 / S) + 80) / 123);
    }


    if (E2 % 2 != 0) {
        while (true) {
            if (M == 0) {
                break;
            }
            if (HP1 < 200) {
                HP1 = ceil(float(1.3 * HP1));
                M_pay += 150;
                M -= 150;
                HP1 = checkValidHP(HP1);
                M = checkValidM(M);
                if (M_pay > 0.5 * M1) {
                    break;
                }
            } else {
                HP1 = ceil(float(1.1 * HP1));
                M_pay += 70;
                M -= 70;
                HP1 = checkValidHP(HP1);
                M = checkValidM(M);

                if (M_pay > 0.5 * M1) {
                    break;
                }
            }

            if (EXP1 < 400) {
                EXP1 = ceil(float(1.13 * EXP1));
                M_pay += 200;
                M -= 200;
                EXP1 = checkValidEXP(EXP1);
                M = checkValidM(M);

                if (M_pay > 0.5 * M1) {
                    break;
                }
            } else {
                EXP1 = ceil(float(1.13 * EXP1));
                M_pay += 120;
                M -= 120;
                EXP1 = checkValidEXP(EXP1);
                M = checkValidM(M);

                if (M_pay > 0.5 * M1) {
                    break;
                }
            }

            if (EXP1 < 300) {
                EXP1 = ceil(float(0.9 * EXP1));
                M_pay += 100;
                M -= 100;
                EXP1 = checkValidEXP(EXP1);
                M = checkValidM(M);

                if (M_pay > 0.5 * M1) {
                    break;
                }
            } else {
                EXP1 = ceil(float(0.9 * EXP1));
                M_pay += 120;
                M -= 120;
                EXP1 = checkValidEXP(EXP1);
                M = checkValidM(M);

                if (M_pay > 0.5 * M1) {
                    break;
                }
            }
        }
        HP1 = ceil(float(0.83 * HP1));
        EXP1 = ceil(float(1.17 * EXP1));
        HP1 = checkValidHP(HP1);
        EXP1 = checkValidEXP(EXP1);
    } else {
        if (M > 0) {
            if (HP1 < 200) {
                HP1 = ceil(float(1.3 * HP1));
                M_pay += 150;
                M -= 150;
                HP1 = checkValidHP(HP1);
                M = checkValidM(M);

            } else {
                HP1 = ceil(float(1.1 * HP1));
                M_pay += 70;
                M -= 70;
                HP1 = checkValidHP(HP1);
                M = checkValidM(M);

            }
        }

        if (M > 0) {
            if (EXP1 < 400) {
                EXP1 = ceil(float(1.13 * EXP1));
                M_pay += 200;
                M -= 200;
                EXP1 = checkValidEXP(EXP1);
                M = checkValidM(M);

            } else {
                EXP1 = ceil(float(1.13 * EXP1));
                M_pay += 120;
                M -= 120;
                EXP1 = checkValidEXP(EXP1);
                M = checkValidM(M);

            }
        }

        if (M > 0) {
            if (EXP1 < 300) {
                EXP1 = ceil(float(0.9 * EXP1));
                M_pay += 100;
                M -= 100;
                EXP1 = checkValidEXP(EXP1);
                M = checkValidM(M);

            } else {
                EXP1 = ceil(float(0.9 * EXP1));
                M_pay += 120;
                M -= 120;
                EXP1 = checkValidEXP(EXP1);
                M = checkValidM(M);

            }
        }

        HP1 = ceil(float(0.83 * HP1));
        EXP1 = ceil(float(1.17 * EXP1));
        HP1 = checkValidHP(HP1);
        EXP1 = checkValidEXP(EXP1);
    }

    S = nearestSquare(EXP1);
    if (EXP1 >= S) {
        P2 = 1;
    } else {
        P2 = float(((EXP1 / S) + 80) / 123);
    }

    if (E2 < 10) {
        int i = E2;
        P3 = float(P[i]) / 100.00;
    } else {
        int i = (E2 / 10 + E2 % 10) % 10;
        P3 = float(P[i]) / 100.00;
    }

    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = ceil(float(0.75 * EXP1));
        EXP1 = checkValidEXP(EXP1);

    } else {
        P_final = (P1 + P2 + P3) / 3;
        if (P_final < 0.5) {
            HP1 = ceil(float(0.85 * HP1));
            EXP1 = ceil(float(1.15 * EXP1));
            HP1 = checkValidHP(HP1);
            EXP1 = checkValidEXP(EXP1);
        } else {
            HP1 = ceil(float(0.9 * HP1));
            EXP1 = ceil(float(1.2 * EXP1));
            HP1 = checkValidHP(HP1);
            EXP1 = checkValidEXP(EXP1);

        }
    }

    M1 = int(M);
    M1 = checkValidM(M1);


    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) {
        return -99;
    }
    int point_taxi[10][10] = {0};
    int point_sherlock, meet_point;
    int count_positive = 0;
    int count_negative = 0;
    int i, j, max;

    HP1 = checkValidHP(HP1);
    EXP1 = checkValidEXP(EXP1);
    HP2 = checkValidHP(HP2);
    EXP2 = checkValidEXP(EXP2);

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            point_taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
//            cout << point_taxi[i][j] << " ";
            if (point_taxi[i][j] > E3 * 2) {
                count_positive++;
            } else if (point_taxi[i][j] < -E3) {
                count_negative++;
            }
        }
//        std::cout << std::endl;
    }

    if (count_positive < 10) {
        i = count_positive;
    } else {
        i = count_positive / 10 + count_positive % 10;
        if (i > 9) {
            i = i / 10 + i % 10;
        }
    }

    if (count_negative < 10) {
        j = count_negative;
    } else {
        j = count_negative / 10 + count_negative % 10;
        if (j > 9) {
            j = j / 10 + j % 10;
        }
    }

    max = point_taxi[i][j];
    meet_point = max;
    int absolute_point_taxi = abs(point_taxi[i][j]);

    while (i > 0 && j < 9) {
        --i;
        ++j;
        if (point_taxi[i][j] > max) {
            max = point_taxi[i][j];
        }
    }

    while (i < 9 && j > 0) {
        ++i;
        --j;
        if (point_taxi[i][j] > max) {
            max = point_taxi[i][j];
        }
    }

    while (i > 0 && j > 0) {
        --i;
        --j;
        if (point_taxi[i][j] > max) {
            max = point_taxi[i][j];
        }
    }

    while (i < 9 && j < 9) {
        ++i;
        ++j;
        if (point_taxi[i][j] > max) {
            max = point_taxi[i][j];
        }
    }

    point_sherlock = max;
    if (absolute_point_taxi > point_sherlock) {
        EXP1 = ceil(float(0.88 * EXP1));
        EXP2 = ceil(float(0.88 * EXP2));
        HP1 = ceil(float(0.9 * HP1));
        HP2 = ceil(float(0.9 * HP2));
        return meet_point;
    } else {
        EXP1 = ceil(float(1.12 * EXP1));
        EXP1 = checkValidEXP(EXP1);
        EXP2 = ceil(float(1.12 * EXP2));
        EXP2 = checkValidEXP(EXP2);
        HP1 = ceil(float(1.1 * HP1));
        HP1 = checkValidHP(HP1);
        HP2 = ceil(float(1.1 * HP2));
        HP2 = checkValidHP(HP2);
        return point_sherlock;
    }

}

// Task 4
int checkPassword(const char *s, const char *email) {
    // TODO: Complete this function
    string emailString = email;
    string sString = s;
    string se;

    if (emailString.length() > 100) {
        return 100;
    }

    bool hasAt = false;
    for (int i = 0; i < emailString.length(); ++i) {
        if (emailString[i] == '@') {
            hasAt = true;
            for (int j = i + 1; j < emailString.length(); ++j) {
                if (emailString[j] == '@') {
                    return j;
                }
            }
            break;
        } else {
            se += emailString[i];
        }
    }

    if (!hasAt) {
        return -1;
    }

    if (sString.length() < 8) {
        return -1;
    } else if (sString.length() > 20) {
        return -2;
    }

    bool hasSpecialChar = false;
    if (se.length() > sString.length()) {
        for (int i = 0; i < sString.length(); ++i) {
            if (sString[i] == '@' || sString[i] == '#' || sString[i] == '%' || sString[i] == '$' || sString[i] == '!') {
                hasSpecialChar = true;
            }


            if (sString[i] == sString[i + 1] && sString[i] == sString[i + 2]) {
                return -(400 + i);
            }
        }

        if (!hasSpecialChar) {
            return -5;
        }

        for (int i = 0; i < sString.length(); ++i) {
            if (!isalnum(sString[i]) && sString[i] != '@' && sString[i] != '#' && sString[i] != '%' &&
                sString[i] != '$' &&
                sString[i] != '!') {
                return i;
            }
        }
    } else {
        for (int i = 0; i <= sString.length() - se.length(); ++i) {
            int j;
            for (j = 0; j < se.length(); ++j) {
                if (sString[i + j] != se[j]) {
                    break;
                }
            }
            if (j == se.length()) {
                return -(300 + i);
            }
        }

        for (int i = 0; i < sString.length(); ++i) {
            if (sString[i] == '@' || sString[i] == '#' || sString[i] == '%' || sString[i] == '$' || sString[i] == '!') {
                hasSpecialChar = true;
            }


            if (sString[i] == sString[i + 1] && sString[i] == sString[i + 2]) {
                return -(400 + i);
            }
        }

        if (!hasSpecialChar) {
            return -5;
        }

        for (int i = 0; i < sString.length(); ++i) {
            if (!isalnum(sString[i]) && sString[i] != '@' && sString[i] != '#' && sString[i] != '%' &&
                sString[i] != '$' &&
                sString[i] != '!') {
                return i;
            }
        }

    }


    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxFrequency = 0;
    int maxLength = 0;
    int index;
    string correctPassword;

    for (int i = 0; i < num_pwds; ++i) {
        int frequency = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                ++frequency;
            }
        }

        if (frequency > maxFrequency ||
            (frequency == maxFrequency && strlen(arr_pwds[i]) > maxLength)) {
            maxFrequency = frequency;
            maxLength = (int) strlen(arr_pwds[i]);
            correctPassword = arr_pwds[i];
        }
    }

    for (index = 0; index < num_pwds; ++index) {
        if (arr_pwds[index] == correctPassword) {
            return index;
        }
    }
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////