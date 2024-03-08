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
int firstMeet(int& exp1, int& exp2, int e1) {
    if (e1 >= 0 && e1 <= 99) {
        // case 1
        if (e1 >= 0 && e1 <= 3) {       // exp2 outcome according to e1 value [0, 3]
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
                exp2 += 29 + 45 + 75;
                break;
            }
            int D;      // calculate decision value
            D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0) exp1 += ceil(D / 200);
            else exp1 -= ceil(D / 100);
        }

        // case 2
        // exp2 outcome according to e1 value [4, 99]
        if (e1 >= 4 && e1 <= 99) {
            if (e1 >= 4 && e1 <= 19) exp2 += ceil(e1 / 4.0 + 19);
            else if (e1 >= 20 && e1 <= 49) exp2 += ceil(e1 / 9.0 + 21);
            else if (e1 >= 50 && e1 <= 65) exp2 += ceil(e1 / 16.0 + 17);
            else if (e1 >= 66 && e1 <= 79) {
                exp2 += ceil(e1 / 4.0 + 19);
                if (exp2 > 200) exp2 += ceil(e1 / 9.0 + 21);
            }
            else if (e1 >= 80 && e1 <= 99) {
                exp2 += ceil(e1 / 4.0 + 19);
                exp2 += ceil(e1 / 9.0 + 21);
                if (exp2 > 400) {
                    exp2 += ceil(e1 / 16.0 + 17);
                    exp2 += ceil(0.15 * exp2);
                }
            }
            exp1 -= e1;     // exp1 decreased
        }
        exp1 = exp1 < 0 ? 0 : exp1; exp1 = exp1 > 600 ? 600 : exp1;     // exp1 [0, 600]
        exp2 = exp2 < 0 ? 0 : exp2; exp2 = exp2 > 600 ? 600 : exp2;     // exp2 [0, 600]

        return exp1 + exp2;
    }
    return -99;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 >= 0 && E2 <= 99) {
        int S;
        double P1, P2, P3;
        // Road 01
        S = pow(round(sqrt(EXP1)), 2);      // nearest perfect square S
        if (EXP1 >= S) P1 = 100;
        else P1 = ceil(((EXP1 / S * 1.0 + 80) / 123) * 100);

        // Road 02
        int halfM1 = M1 * 0.5;
        if (E2 % 2 != 0) {
            for (;;) {
                // Event 01
                if (M1 > halfM1) {
                    if (HP1 < 200) {
                        HP1 += ceil(HP1 * 0.3);
                        M1 -= 150;
                    }
                    else {
                        HP1 += ceil(HP1 * 0.1);
                        M1 -= 70;
                    }

                    HP1 = HP1 < 0 ? 0 : HP1; HP1 = HP1 > 666 ? 666 : HP1;     // HP1 [0, 666]
                    EXP1 = EXP1 < 0 ? 0 : EXP1; EXP1 = EXP1 > 600 ? 600 : EXP1;     // EXP1 [0, 600]
                    M1 = M1 < 0 ? 0 : M1; M1 = M1 > 3000 ? 3000 : M1;     // M1 [0, 3000]
                }
                else break;

                // Event 02
                if (M1 > halfM1) {
                    if (EXP1 < 400) M1 -= 200;
                    else M1 -= 120;
                    EXP1 += ceil(EXP1 * 0.13);

                    HP1 = HP1 < 0 ? 0 : HP1; HP1 = HP1 > 666 ? 666 : HP1;     // HP1 [0, 666]
                    EXP1 = EXP1 < 0 ? 0 : EXP1; EXP1 = EXP1 > 600 ? 600 : EXP1;     // EXP1 [0, 600]
                    M1 = M1 < 0 ? 0 : M1; M1 = M1 > 3000 ? 3000 : M1;     // M1 [0, 3000]
                }
                else break;

                // Event 03
                int m;
                if (M1 > halfM1) {
                    if (EXP1 < 300) m = 100;
                    else m = 120;
                    M1 -= m;
                    EXP1 = ceil(EXP1 * 0.9);

                    HP1 = HP1 < 0 ? 0 : HP1; HP1 = HP1 > 666 ? 666 : HP1;     // HP1 [0, 666]
                    EXP1 = EXP1 < 0 ? 0 : EXP1; EXP1 = EXP1 > 600 ? 600 : EXP1;     // EXP1 [0, 600]
                    M1 = M1 < 0 ? 0 : M1; M1 = M1 > 3000 ? 3000 : M1;     // M1 [0, 3000]
                }
                else break;
            }
        }
        else {
            // Event 01
            for (int i = 0; i < 1; i++) {
                if (M1 > 0) {
                    if (HP1 < 200) {
                        HP1 += ceil(HP1 * 0.3);
                        M1 -= 150;
                    }
                    else {
                        HP1 += ceil(HP1 * 0.1);
                        M1 -= 70;
                    }

                    HP1 = HP1 < 0 ? 0 : HP1; HP1 = HP1 > 666 ? 666 : HP1;     // HP1 [0, 666]
                    EXP1 = EXP1 < 0 ? 0 : EXP1; EXP1 = EXP1 > 600 ? 600 : EXP1;     // EXP1 [0, 600]
                    M1 = M1 < 0 ? 0 : M1; M1 = M1 > 3000 ? 3000 : M1;     // M1 [0, 3000]
                }
                else break;

                // Event 02
                if (M1 > 0) {
                    if (EXP1 < 400) M1 -= 200;
                    else M1 -= 120;
                    EXP1 += ceil(EXP1 * 0.13);

                    HP1 = HP1 < 0 ? 0 : HP1; HP1 = HP1 > 666 ? 666 : HP1;     // HP1 [0, 666]
                    EXP1 = EXP1 < 0 ? 0 : EXP1; EXP1 = EXP1 > 600 ? 600 : EXP1;     // EXP1 [0, 600]
                    M1 = M1 < 0 ? 0 : M1; M1 = M1 > 3000 ? 3000 : M1;     // M1 [0, 3000]
                }
                else break;

                // Event 03
                int m;
                if (M1 > 0) {
                    if (EXP1 < 300) m = 100;
                    else m = 120;
                    M1 -= m;
                    EXP1 = ceil(EXP1 * 0.9);

                    HP1 = HP1 < 0 ? 0 : HP1; HP1 = HP1 > 666 ? 666 : HP1;     // HP1 [0, 666]
                    EXP1 = EXP1 < 0 ? 0 : EXP1; EXP1 = EXP1 > 600 ? 600 : EXP1;     // EXP1 [0, 600]
                    M1 = M1 < 0 ? 0 : M1; M1 = M1 > 3000 ? 3000 : M1;     // M1 [0, 3000]
                }
                else break;
            }
        }

        HP1 = ceil(HP1 * 0.83);
        EXP1 += ceil(EXP1 * 0.17);

        HP1 = HP1 < 0 ? 0 : HP1; HP1 = HP1 > 666 ? 666 : HP1;     // HP1 [0, 666]
        EXP1 = EXP1 < 0 ? 0 : EXP1; EXP1 = EXP1 > 600 ? 600 : EXP1;     // EXP1 [0, 600]
        M1 = M1 < 0 ? 0 : M1; M1 = M1 > 3000 ? 3000 : M1;     // M1 [0, 3000]

        S = pow(round(sqrt(EXP1)), 2);      // nearest perfect square S
        if (EXP1 >= S) P2 = 100;
        else P2 = ceil(((EXP1 / S * 1.0 + 80) / 123) * 100);

        // Road 03
        int sumE2;
        int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        if (E2 < 10) P3 = P[E2];
        else {
            sumE2 = (E2 - (E2 % 10)) / 10 + E2 % 10;
            P3 = P[sumE2 % 10];     // number of the unit place of the total value
        }

        // Probability
        double avgP;
        if (P1 == P2 == P3 == 100) EXP1 -= ceil(EXP1 * 0.25);
        else {
            avgP = ceil((P1 + P2 + P3) / 3.0);
            if (avgP < 50) {
                HP1 = ceil(HP1 * 0.85);
                EXP1 += ceil(EXP1 * 0.15);
            }
            else {
                HP1 = ceil(HP1 * 0.9);
                EXP1 += ceil(EXP1 * 0.20);
            }

            HP1 = HP1 < 0 ? 0 : HP1; HP1 = HP1 > 666 ? 666 : HP1;     // HP1 [0, 666]
            EXP1 = EXP1 < 0 ? 0 : EXP1; EXP1 = EXP1 > 600 ? 600 : EXP1;     // EXP1 [0, 600]
            M1 = M1 < 0 ? 0 : M1; M1 = M1 > 3000 ? 3000 : M1;     // M1 [0, 3000]
        }

        return HP1 + EXP1 + M1;
    }
    return -99;
}
// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (E3 >= 0 && E3 <= 99) {
        int r = 0, c = 0;
        int max = 0;
        int taxi[10][10] = { 0 };

        // Taxi skill score
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);

                if (taxi[i][j] > E3 * 2) r++;
                if (taxi[i][j] < -E3) c++;
            }
        }

        // Point where taxi meet Sherlock and Watson
        for (;;) {
            if (r >= 10) r = (r - (r % 10)) / 10 + r % 10;
            else break;
        }
        for (;;) {
            if (c >= 10) c = (c - (c % 10)) / 10 + c % 10;
            else break;
        }

        // Sherlock and Watson skill score
        for (int i = r, j = c; i > 0 && j > 0; i--, j--) {
            if (taxi[i][j] >= max) max = taxi[i][j];
        }
        for (int i = r, j = c; i < 10 && j < 10; i++, j++) {
            if (taxi[i][j] >= max) max = taxi[i][j];
        }
        for (int i = r, j = c; i < 10 && j > 0; i++, j--) {
            if (taxi[i][j] >= max) max = taxi[i][j];
        }
        for (int i = r, j = c; i > 0 && j < 10; i--, j++) {
            if (taxi[i][j] >= max) max = taxi[i][j];
        }

        //  Compare the absolute value of the taxi’s point with Sherlock and Watson’s
        if (abs(taxi[r][c]) > abs(max)) {
            EXP1 = ceil(EXP1 * 0.88);
            HP1 = ceil(HP1 * 0.9);

            EXP2 = ceil(EXP2 * 0.88);
            HP2 = ceil(HP2 * 0.9);

            HP1 = HP1 < 0 ? 0 : HP1; HP1 = HP1 > 666 ? 666 : HP1;     // HP1 [0, 666]
            EXP1 = EXP1 < 0 ? 0 : EXP1; EXP1 = EXP1 > 600 ? 600 : EXP1;     // EXP1 [0, 600]
            HP2 = HP2 < 0 ? 0 : HP2; HP2 = HP2 > 666 ? 666 : HP2;     // HP2 [0, 666]
            EXP2 = EXP2 < 0 ? 0 : EXP2; EXP2 = EXP2 > 600 ? 600 : EXP2;     // EXP2 [0, 600]

            return taxi[r][c];
        }
        else {
            EXP1 += ceil(EXP1 * 0.12);
            HP1 += ceil(HP1 * 0.1);

            EXP2 += ceil(EXP2 * 0.12);
            HP2 += ceil(HP2 * 0.1);

            HP1 = HP1 < 0 ? 0 : HP1; HP1 = HP1 > 666 ? 666 : HP1;     // HP1 [0, 666]
            EXP1 = EXP1 < 0 ? 0 : EXP1; EXP1 = EXP1 > 600 ? 600 : EXP1;     // EXP1 [0, 600]
            HP2 = HP2 < 0 ? 0 : HP2; HP2 = HP2 > 666 ? 666 : HP2;     // HP2 [0, 666]
            EXP2 = EXP2 < 0 ? 0 : EXP2; EXP2 = EXP2 > 600 ? 600 : EXP2;     // EXP2 [0, 600]

            return max;
        }
        return -1;
    }
    return -99;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    string S = s; string Email = email;
    string se;
    int countSe = 0;
    int sizeEmail, sizeS;
    int sizeSe = 0;
    sizeEmail = Email.length();
    sizeS = S.length();

    // Find se
    for (int i = 0; i < sizeEmail; i++) {
        if (email[i] == 64) break;
        else sizeSe++;
    }
    se = Email.substr(0, sizeSe);

    // Limit of s
    int minS = 8; int maxS = 20;
    if (sizeS < minS) return -1;
    if (sizeS > maxS) return -2;

    // If s contains se
    size_t sei = S.find(se);
    if (sei != string::npos) return -(300 + sei);

    // If s contains more than 2 consecutive and identical characters
    int sci = 0;
    for (int i = 1; i < sizeS; i++) {
        if (s[i] == s[i - 1]) {
            sci++;
            if (sci >= 2) {
                sci = i - 2;
                return -(400 + sci);
            }
        }
    }

    // If s does not contain special characters
    for (int i = 0; i < sizeS; i++) {
        if (!(s[i] == 33 || (s[i] >= 35 && s[i] <= 37) || s[i] == 64)) return -5;
    }

    //  Remaining cases
    for (int i = 0; i < sizeS; i++) {
        if (!((s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))) return i;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxFreq = 0; int maxLen = 0; int pos = -1;

    for (int i = 0; i < num_pwds; i++) {
        // Counting frequency
        int freq = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (arr_pwds[i] == arr_pwds[j]) freq++;
        }

        // Password with the longest length among the most frequently occurring passwords
        int len = strlen(arr_pwds[i]);
        if (freq > maxFreq || (freq == maxFreq && len > maxLen)) {
            maxFreq = freq;
            maxLen = len;
            pos = i;
        }
    }
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////