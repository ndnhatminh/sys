#include "study_in_pink1.h"

bool readFile(
    const string& filename,
    int& HP1,
    int& HP2,
    int& EXP1,
    int& EXP2,
    int& M1,
    int& M2,
    int& E1,
    int& E2,
    int& E3
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

void check2(int& value1, int& value2, int floor, int ceiling) {
    value1 = max(min(value1, ceiling), floor);
    value2 = max(min(value2, ceiling), floor);
}
void checkSher(int& HP, int& EXP, int& M) {
    HP = max(min(HP, 666), 0);
    EXP = max(min(EXP, 600), 0);
    M = max(min(M, 3000), 0);
}
int gennearestsqnum(int XP) {
    if (XP - pow((int)sqrt(XP), 2) <= sqrt(XP))
        return (int)pow((int)sqrt(XP), 2);
    else return (int)pow((int)sqrt(XP) + 1, 2);
}
void calcP(int xp, double& P, int& count) {
    if (xp >= gennearestsqnum(xp)) {
        P = 1;
        count += 1;
    }
    else P = ((double)xp / (double)gennearestsqnum(xp) + 80) / 123;
}
int sum2(int& num) {
    while (num >= 10)
        num = num / 10 + num % 10;
    return num;
}
int findse(const char* a, const char* b, int num) {
    string se = string(b).substr(0, num);
    return string(a).find(se);
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    if (e1 < 0 || 99 < e1)
        return -99;
    else check2(exp1, exp2, 0, 600);
    if (0 <= e1 && e1 <= 3) {
        if (e1 == 0)
            exp2 += 29;
        else if (e1 == 1)
            exp2 += 45;
        else if (e1 == 2)
            exp2 += 75;
        else exp2 += 29 + 45 + 75;
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            exp1 += (int)ceil(D / 200.0 - 1.192092896e-07F);
        else exp1 -= (int)floor(D / 100.0 + 1.192092896e-07F);
    }
    if (4 <= e1) {
        if (e1 <= 19)
            exp2 += (int)ceil(e1 / 4.0 - 1.192092896e-07F) + 19;
        else if (e1 <= 49)
            exp2 += (int)ceil(e1 / 9.0 - 1.192092896e-07F) + 21;
        else if (e1 <= 65)
            exp2 += (int)ceil(e1 / 16.0 - 1.192092896e-07F) + 17;
        else if (e1 <= 79) {
            exp2 += (int)ceil(e1 / 4.0 - 1.192092896e-07F) + 19;
            check2(exp1, exp2, 0, 600);
            if (exp2 > 200)
                exp2 += (int)ceil(e1 / 9.0 - 1.192092896e-07F) + 21;
        }
        else {
            exp2 += (int)ceil(e1 / 4.0 - 1.192092896e-07F) + 19;
            check2(exp1, exp2, 0, 600);
            exp2 += (int)ceil(e1 / 9.0 - 1.192092896e-07F) + 21;
            check2(exp1, exp2, 0, 600);
            if (exp2 > 400) {
                exp2 += (int)ceil(e1 / 16.0 - 1.192092896e-07F) + 17;
                check2(exp1, exp2, 0, 600);
                exp2 += (int)ceil(exp2 * 0.15 - 1.192092896e-07F);
            }
        }
        exp1 -= e1;
    }
    check2(exp1, exp2, 0, 600);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 < 0 || 99 < E2)
        return -99;
    checkSher(HP1, EXP1, M1);
    int count = 0;
    double P1, P2, P3, Pfinal;
    calcP(EXP1, P1, count);
    if (M1 != 0) {
        if (E2 % 2 == 0) {
            if (M1 != 0) {
                if (HP1 < 200) {
                    HP1 += (int)ceil(HP1 * 0.3 - 1.192092896e-07F);
                    M1 -= 150;
                }
                else {
                    HP1 += (int)ceil(HP1 * 0.1 - 1.192092896e-07F);
                    M1 -= 70;
                }
                checkSher(HP1, EXP1, M1);
            }
            if (M1 != 0) {
                if (EXP1 < 400)
                    M1 -= 200;
                else
                    M1 -= 120;
                EXP1 += (int)ceil(EXP1 * 0.13 - 1.192092896e-07F);
                checkSher(HP1, EXP1, M1);
            }
            if (M1 != 0) {
                if (EXP1 < 300)
                    M1 -= 100;
                else
                    M1 -= 120;
                EXP1 -= (int)floor(EXP1 * 0.1 + 1.192092896e-07F);
                checkSher(HP1, EXP1, M1);
            }
        }
        else if (E2 % 2 == 1) {
            int spent = 0;
            int maxpay = ceil(M1 / 2.0 - 1.192092896e-07F);
            if (M1 % 2 == 0)
                maxpay += 1;
            while (spent < maxpay) {
                if (M1 != 0 && spent < maxpay) {
                    if (HP1 < 200) {
                        HP1 += (int)ceil(HP1 * 0.3 - 1.192092896e-07F);
                        M1 -= 150; spent += 150;
                    }
                    else {
                        HP1 += (int)ceil(HP1 * 0.1 - 1.192092896e-07F);
                        M1 -= 70; spent += 70;
                    }
                    checkSher(HP1, EXP1, M1);
                }
                if (M1 != 0 && spent < maxpay) {
                    if (EXP1 < 400) {
                        M1 -= 200; spent += 200;
                    }
                    else {
                        M1 -= 120; spent += 120;
                    }
                    EXP1 += (int)ceil(EXP1 * 0.13 - 1.192092896e-07F);
                    checkSher(HP1, EXP1, M1);
                }
                if (M1 != 0 && spent < maxpay) {
                    if (EXP1 < 300) {
                        M1 -= 100; spent += 100;
                    }
                    else {
                        M1 -= 120; spent += 120;
                    }
                    EXP1 -= (int)floor(EXP1 * 0.1 + 1.192092896e-07F);
                    checkSher(HP1, EXP1, M1);
                }
            }
        }
    }
    HP1 -= (int)floor(HP1 * 0.17 + 1.192092896e-07F);
    EXP1 += (int)ceil(EXP1 * 0.17 - 1.192092896e-07F);
    checkSher(HP1, EXP1, M1);
    calcP(EXP1, P2, count);
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i;
    if (E2 < 10)
        i = E2;
    else
        i = (E2 / 10 + E2 % 10) % 10;
    P3 = P[i];
    if (P3 == 100 && count == 2)
        EXP1 -= (int)floor(EXP1 * 0.25 + 1.192092896e-07F);
    else {
        Pfinal = (P1 + P2 + P3 / 100) / 3;
        if (Pfinal < 0.5) {
            HP1 -= (int)floor(HP1 * 0.15 + 1.192092896e-07F);
            EXP1 += (int)ceil(EXP1 * 0.15 - 1.192092896e-07F);
        }
        else {
            HP1 -= (int)floor(HP1 * 0.10 + 1.192092896e-07F);
            EXP1 += (int)ceil(EXP1 * 0.20 - 1.192092896e-07F);
        }
    }
    checkSher(HP1, EXP1, M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (E3 < 0 || 99 < E3)
        return -99;
    check2(HP1, HP2, 0, 666); check2(EXP1, EXP2, 0, 600);
    int car[10][10], countneg = 0, countpos = 0, HWpts = 0, taxipts, re;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            car[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (car[i][j] > E3 * 2)
                countpos += 1;
            if (car[i][j] < E3 * -1)
                countneg += 1;
        }
    }
    sum2(countpos); sum2(countneg);
    taxipts = car[countpos][countneg]; HWpts = car[countpos][countneg];
    int i = countpos, j = countneg;
    while (i < 9 && j > 0) {
        i += 1; j -= 1;
        HWpts = max(car[i][j], HWpts);
    }
    i = countpos, j = countneg;
    while (i > 0 && j > 0) {
        i -= 1; j -= 1;
        HWpts = max(car[i][j], HWpts);
    }
    i = countpos, j = countneg;
    while (i < 9 && j < 9) {
        i += 1; j += 1;
        HWpts = max(car[i][j], HWpts);
    }
    i = countpos, j = countneg;
    while (i < 9 && j < 9) {
        i += 1; j += 1;
        HWpts = max(car[i][j], HWpts);
    }
    if (abs(taxipts) > HWpts) {
        HP1 -= (int)floor(HP1 * 0.1 + 1.192092896e-07F);
        EXP1 -= (int)floor(EXP1 * 0.12 + 1.192092896e-07F);
        HP2 -= (int)floor(HP2 * 0.1 + 1.192092896e-07F);
        EXP2 -= (int)floor(EXP2 * 0.12 + 1.192092896e-07F);
        re = taxipts;
    }
    else {
        HP1 += (int)ceil(HP1 * 0.1 - 1.192092896e-07F);
        EXP1 += (int)ceil(EXP1 * 0.12 - 1.192092896e-07F);
        HP2 += (int)ceil(HP2 * 0.1 - 1.192092896e-07F);
        EXP2 += (int)ceil(EXP2 * 0.12 - 1.192092896e-07F);
        re = HWpts;
    }
    check2(HP1, HP2, 0, 666); check2(EXP1, EXP2, 0, 600);
    return re;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    if (strlen(s) < 8)
        return -1;
    if (strlen(s) > 20)
        return -2;
    if (findse(s, email, string(email).find("@")) >= 0)
        return -(300 + findse(s, email, string(email).find("@")));
    for (int i = 2; i < strlen(s); i++) {
        if (s[i - 2] == s[i - 1] && s[i - 1] == s[i])
            return -(400 + i - 2);
    }
    bool kokitudacbiet = false;
    for (int i = 0; i < strlen(s); i++) {
        if (!(s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%'))
            kokitudacbiet = true;
    }   
    if (kokitudacbiet)
        return -5;
    for (int i = 0; i < strlen(s); i++) {
        if ((s[i] < 'A' || ('Z' < s[i] && s[i] < 'a') || 'z' < s[i]) && (s[i] < '0' || '9' < s[i]) && !(s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%'))
            return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    string a[30];
    int maxshowup = 0, maxlen = 0, b[30] = { 0 };
    for (int i = 0; i < num_pwds; i++) {
        a[i] = arr_pwds[i];
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                b[j] += 1;
                maxshowup = max(maxshowup, b[j]);
            }
        }
    }
    for (int i = 0; i < num_pwds; i++) {
        if (b[i] == maxshowup) {
            maxlen = max((int)strlen(arr_pwds[i]), maxlen);
        }
    }
    for (int i = 0; i < num_pwds; i++) {
        if (b[i] == maxshowup && (int)strlen(arr_pwds[i]) == maxlen) {
            return i;
        }
    }
    return -1;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////