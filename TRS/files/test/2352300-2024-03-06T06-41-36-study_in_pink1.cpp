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

void check(int& para, int boundary) {
    if (para < 0) para = 0;
    else if (para > boundary) para = boundary;
}

bool checkMoney(int startm, int paid, int M1, int E2) {
    if ((E2 % 2 == 1) && (paid > (0.5 * startm))) return true;
    if ((E2 % 2 == 0) && (M1 <= 0)) return true;
    return false;
}

double square(int EXP1) {
    double x = sqrt(EXP1);
    if ((x - (int)x < 0.5) && (x - (int)x != 0)) return 1;
    else return (EXP1 / (double)(ceil(x) * ceil(x)) + 80) / 123;
}

int checkij(int ij) {
    while (ij > 9) ij = ij / 10 + ij % 10;
    return ij;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ((e1 < 0) || (e1 > 99)) return -99;
    if ((e1 >= 0) && (e1 <= 3)) {
        switch (e1) {
        case 0: exp2 += 29; break;
        case 1: exp2 += 45; break;
        case 2: exp2 += 75; break;
        case 3: exp2 += 149; break;
        }
        check(exp2, 600);
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 += ceil(D / 200.0);
        else exp1 -= floor(D / 100.0);
        check(exp1, 600);
    }
    else if ((e1 >= 4) && (e1 <= 99)) {
        if ((e1 >= 4) && (e1 <= 19)) exp2 += ceil((e1 / 4.0 + 19));
        else if ((e1 >= 20) && (e1 <= 49)) exp2 += ceil((e1 / 9.0 + 21));
        else if ((e1 >= 50) && (e1 <= 65)) exp2 += ceil((e1 / 16.0 + 17));
        else if ((e1 >= 66) && (e1 <= 79)) {
            exp2 += ceil((e1 / 4.0 + 19));
            if (exp2 > 200) exp2 += ceil((e1 / 9.0 + 21));
        }
        else if ((e1 >= 80) && (e1 <= 99)) {
            exp2 += ceil((e1 / 4.0 + 19));
            exp2 += ceil((e1 / 9.0 + 21));
            if (exp2 > 400) {
                exp2 += ceil((e1 / 16.0 + 17));
                exp2 += ceil(0.15 * exp2);
            }
        }
        exp1 -= e1;
        check(exp1, 600);
        check(exp2, 600);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if ((E2 < 0) || (E2 > 99)) return -99;
    double P1, P2, P3;
    P1 = square(EXP1);
    if (M1 != 0) {
        int startm = M1, paid = 0;
        do {
            if (HP1 < 200) {
                HP1 += ceil(0.3 * HP1);
                M1 -= 150;
                paid += 150;
            }
            else {
                HP1 += ceil(0.1 * HP1);
                M1 -= 70;
                paid += 70;
            }
            check(HP1, 666);
            check(M1, 3000);
            if (checkMoney(startm, paid, M1, E2)) break;
            if (EXP1 < 400) {
                M1 -= 200;
                paid += 200;
            }
            else {
                M1 -= 120;
                paid += 120;
            }
            EXP1 += ceil(0.13 * EXP1);
            check(M1, 3000);
            check(EXP1, 600);
            if (checkMoney(startm, paid, M1, E2)) break;
            if (EXP1 < 300) {
                M1 -= 100;
                paid += 100;
            }
            else {
                M1 -= 120;
                paid += 120;
            }
            EXP1 -= floor(0.1 * EXP1);
            check(M1, 3000);
            check(EXP1, 600);
            if (checkMoney(startm, paid, M1, E2)) break;
        } while (E2 % 2 == 1);
    }
    HP1 -= floor(0.17 * HP1);
    EXP1 += ceil(0.17 * EXP1);
    check(HP1, 666);
    check(EXP1, 600);
    P2 = square(EXP1);
    int P[10] = { 32,47,28,79,100,50,22,83,64,11 };
    if (E2 < 10) P3 = P[E2] / 100.0;
    else P3 = P[(E2 / 10 + E2 % 10) % 10] / 100.0;
    if ((P1 == 1) && (P2 == 1) && (P3 == 1)) EXP1 -= floor(0.25 * EXP1);
    else if ((P1 + P2 + P3) / 3 < 0.5) {
        HP1 -= floor(0.15 * HP1);
        EXP1 += ceil(0.15 * EXP1);
    }
    else {
        HP1 -= floor(0.1 * HP1);
        EXP1 += ceil(0.2 * EXP1);
    }
    check(EXP1, 600);
    check(HP1, 666);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ((E3 < 0) || (E3 > 99)) return -99;
    int taxi[10][10], icount = 0, jcount = 0, i, j, taximeet;
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++) {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taxi[i][j] > E3 * 2) icount++;
            else if (taxi[i][j] < -E3) jcount++;
        }
    i = checkij(icount);
    j = checkij(jcount);
    taximeet = taxi[i][j];
    int sherlock = taximeet;
    while ((i <= 9) && (j >= 0)) sherlock = max(taxi[i++][j--], sherlock);
    sherlock = abs(sherlock);
    if (abs(taximeet) <= sherlock) {
        EXP1 += ceil(0.12 * EXP1);
        EXP2 += ceil(0.12 * EXP2);
        HP1 += ceil(0.1 * HP1);
        HP2 += ceil(0.1 * HP2);
        check(EXP1, 600);
        check(EXP2, 600);
        check(HP1, 666);
        check(HP2, 666);
        return sherlock;
    }
    else {
        EXP1 -= floor(0.12 * EXP1);
        EXP2 -= floor(0.12 * EXP2);
        HP1 -= floor(0.1 * HP1);
        HP2 -= floor(0.1 * HP2);
        check(EXP1, 600);
        check(EXP2, 600);
        check(HP1, 666);
        check(HP2, 666);
        return taximeet;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se = "", si = s;
    int i = 0;
    while (email[i] != '@') se += email[i++];
    if (strlen(s) < 8) return -1;
    if (strlen(s) > 20) return -2;
    if (si.find(se) != -1) return -(300 + (signed)si.find(se));
    for (i = 0; i <= strlen(s) - 3; i++)
        if ((s[i] == s[i + 1]) && (s[i + 1] == s[i + 2])) return -(400 + i);
    if ((si.find('@') == -1) && (si.find('#') == -1) && (si.find('%') == -1) && (si.find('$') == -1) && (si.find('!') == -1)) return -5;
    for (i = 0; i < strlen(s); i++)
        if (((s[i] < 48) || (s[i] > 57)) && ((s[i] < 97) || (s[i] > 122)) && ((s[i] < 65) || (s[i] > 90)) && (s[i] != '@') && (s[i] != '#') && (s[i] != '%') && (s[i] != '$') && (s[i] != '!')) return i;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int freq, maxfreq = 0, k = 0;
    const char* s = arr_pwds[0];
    for (int i = 0; i < num_pwds; i++) {
        freq = 0;
        for (int j = i; j < num_pwds; j++)
            if (arr_pwds[i] == arr_pwds[j]) freq++;
        if ((maxfreq < freq) || ((maxfreq == freq) && (strlen(s) < strlen(arr_pwds[i])))) {
            maxfreq = freq;
            s = arr_pwds[i];
            k = i;
        }
    }
    return k;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////