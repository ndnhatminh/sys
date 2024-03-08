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
    // TODO: Complete this function
    int task1;
    if ((e1 >= 0) && (e1 <= 99)) {
        int d;
        float fexp1, fexp2, fd, fe1;
        fexp1 = exp1;
        fexp2 = exp2;
        resetExp(fexp1);
        resetExp(fexp2);
        if ((e1 >= 0) && (e1 <= 3))
        {
            switch (e1)
            {
            case 0: fexp2 += 29; resetExp(fexp2); break;
            case 1: fexp2 += 45; resetExp(fexp2); break;
            case 2: fexp2 += 75; resetExp(fexp2); break;
            default:
                fexp2 += (29 + 45 + 75);
                resetExp(fexp2);
                break;
            }
            d = e1 * 3 + exp1 * 7;
            fd = d;
            if (d % 2 == 0) {
                fexp1 += fd / 200;
                resetExp(fexp1);
            }
            else {
                fexp1 -= fd / 100;
                resetExp(fexp1);
            }
            exp1 = ceil(fexp1);
            exp2 = ceil(fexp2);
        }
        else if ((e1 >= 4) && (e1 <= 99))
        {
            fe1 = e1;
            if ((e1 >= 4) && (e1 <= 19)) {
                fexp2 += (fe1 / 4 + 19);
                resetExp(fexp2);
            }
            else if ((e1 >= 20) && (e1 <= 49)) {
                fexp2 += (fe1 / 9 + 21);
                resetExp(fexp2);
            }
            else if ((e1 >= 50) && (e1 <= 65)) {
                fexp2 += (fe1 / 16 + 17);
                resetExp(fexp2);
            }
            else if ((e1 >= 66) && (e1 <= 79))
            {
                fexp2 += (fe1 / 4 + 19);
                resetExp(fexp2);
                if (fexp2 > 200) {
                    fexp2 += (fe1 / 9 + 21);
                    resetExp(fexp2);
                }
            }
            else
            {
                fexp2 += (fe1 / 4 + 19);
                resetExp(fexp2);
                fexp2 += (fe1 / 9 + 21);
                resetExp(fexp2);
                if (fexp2 > 400) {
                    fexp2 += (fe1 / 16 + 17);
                    resetExp(fexp2);
                    fexp2 *= 1.15;
                    resetExp(fexp2);
                }
            }
            fexp1 -= fe1;
            resetExp(fexp1);
            exp1 = ceil(fexp1);
            exp2 = ceil(fexp2);
        }
        task1 = exp1 + exp2;
    }
    else task1 = -99;
    return task1;
}

void resetExp(float& fexp) {
    if (fexp > 600) fexp = 600;
    if (fexp < 0) fexp = 0;
    int exp;
    exp = ceil(fexp);
    fexp = exp;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    int task2;
    if ((E2 >= 0) && (E2 <= 99)) {
        // Road1
        int sNum1, sNum2;
        float P1, P2, fEXP1, M, fHP1, fM1;
        fEXP1 = EXP1;
        resetExp(fEXP1);
        fHP1 = HP1;
        resetHP(fHP1);
        P1 = prob(fEXP1);
        // Road 2
        fM1 = M1;
        resetMoney(fM1);
        if (fM1 != 0) {
            if (E2 % 2 != 0) {
                M = fM1 / 2;
                do
                {
                    if (fHP1 < 200) {
                        fHP1 *= 1.3;
                        resetHP(fHP1);
                        fM1 -= 150;
                        resetMoney(fM1);
                        if (fM1 < M) break;
                    }
                    else {
                        fHP1 *= 1.1;
                        resetHP(fHP1);
                        fM1 -= 70;
                        resetMoney(fM1);
                        if (fM1 < M) break;
                    }
                    if (fEXP1 < 400) {
                        fEXP1 *= 1.13;
                        resetExp(fEXP1);
                        fM1 -= 200;
                        resetMoney(fM1);
                        if (fM1 < M) break;
                    }
                    else {
                        fEXP1 *= 1.13;
                        resetExp(fEXP1);
                        fM1 -= 120;
                        resetMoney(fM1);
                        if (fM1 < M) break;
                    }
                    if (fEXP1 < 300) {
                        fEXP1 *= 0.9;
                        resetExp(fEXP1);
                        fM1 -= 100;
                        resetMoney(fM1);
                        if (fM1 < M) break;
                    }
                    else {
                        fEXP1 *= 0.9;
                        resetExp(fEXP1);
                        fM1 -= 120;
                        resetMoney(fM1);
                        if (fM1 < M) break;
                    }
                } while (fM1 >= M);
            }
            else {
                if (fHP1 < 200) {
                    fHP1 *= 1.3;
                    resetHP(fHP1);
                    fM1 -= 150;
                    resetMoney(fM1);
                }
                else {
                    fHP1 *= 1.1;
                    resetHP(fHP1);
                    fM1 -= 70;
                    resetMoney(fM1);
                }
                if (fM1 != 0) {
                    if (fEXP1 < 400) {
                        fEXP1 *= 1.13;
                        resetExp(fEXP1);
                        fM1 -= 200;
                        resetMoney(fM1);
                    }
                    else {
                        fEXP1 *= 1.13;
                        resetExp(fEXP1);
                        fM1 -= 120;
                        resetMoney(fM1);
                    }
                    if (fM1 != 0) {
                        if (fEXP1 < 300) {
                            fEXP1 *= 0.9;
                            resetExp(fEXP1);
                            fM1 -= 100;
                            resetMoney(fM1);
                        }
                        else {
                            fEXP1 *= 0.9;
                            resetExp(fEXP1);
                            fM1 -= 120;
                            resetMoney(fM1);
                        }
                    }
                }
            }
        }
        fHP1 *= 0.83;
        resetHP(fHP1);
        fEXP1 *= 1.17;
        resetExp(fEXP1);
        P2 = prob(fEXP1);
        // Road 3
        float P3[10]{ 0.32, 0.47, 0.28, 0.79, 1, 0.50, 0.22, 0.83, 0.64, 0.11 }, P;
        int i;
        if (E2 / 10 == 0) i = E2;
        else {
            i = E2 % 10;
            E2 /= 10;
            E2 += i;
            i = E2 % 10;
        }
        if ((P1 == 1) && (P2 == 1) && (P3[i] == 1)) {
            fEXP1 *= 0.75;
            resetExp(fEXP1);
        }
        else {
            P = (P1 + P2 + P3[i]) / 3;
            if (P < 0.5) {
                fHP1 *= 0.85;
                resetHP(fHP1);
                fEXP1 *= 1.15;
                resetExp(fEXP1);
            }
            else {
                fHP1 *= 0.9;
                resetHP(fHP1);
                fEXP1 *= 1.2;
                resetExp(fEXP1);
            }
        }
        EXP1 = ceil(fEXP1);
        HP1 = ceil(fHP1);
        M1 = ceil(fM1);
        task2 = HP1 + EXP1 + M1;
    }
    else task2 = -99;
    return task2;
}

void resetMoney(float& M) {
    if (M > 3000) M = 3000;
    if (M < 0) M = 0;
}

void resetHP(float& fHP) {
    if (fHP > 666) fHP = 666;
    if (fHP < 0) fHP = 0;
    int HP;
    HP = ceil(fHP);
    fHP = HP;
}

float prob(float n) {
    int sNUM1, sNUM2;
    float P;
    sNUM1 = sqrt(n);
    sNUM2 = pow(sNUM1 + 1, 2);
    sNUM1 = pow(sNUM1, 2);
    if (abs(sNUM1 - n) > abs(sNUM2 - n)) P = (n / sNUM2 + 80) / 123;
    else P = 1;
    return P;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    int grMat[10][10], gT = 0, lT = 0, tSc, SWsc, mGr, task3;
    if ((E3 >= 0) && (E3 <= 99)) {
        float fEXP1 = EXP1, fHP1 = HP1, fEXP2 = EXP2, fHP2 = HP2;
        resetExp(fEXP1);
        resetExp(fEXP2);
        resetHP(fHP1);
        resetHP(fHP2);
        for (int j = 0; j < 10; j++) {
            for (int i = 0; i < 10; i++) {
                grMat[j][i] = ((E3 * j) + (2 * i)) * (i - j);
                if (grMat[j][i] > (E3 * 2)) gT++;
                if (grMat[j][i] < -E3) lT++;
            }
        }
        int i, j;
        while (gT / 10 != 0) {
            i = gT % 10;
            gT /= 10;
            gT += i;
        }
        i = gT;
        while (lT / 10 != 0) {
            j = lT % 10;
            lT /= 10;
            lT += j;
        }
        j = lT;
        tSc = grMat[j][i];
        for (int a = 1; ((i - a) >= 0) && ((j - a) >= 0); a++) {
            mGr = grMat[j - a][i - a];
            if (mGr > tSc) SWsc = mGr;
            else SWsc = tSc;
        }
        for (int a = 1; ((i + a) <= 9) && ((j + a) <= 9); a++) {
            mGr = grMat[j + a][i + a];
            if (mGr > SWsc) SWsc = mGr;
        }
        for (int a = 1; ((i - a) >= 0) && ((j + a) <= 9); a++) {
            mGr = grMat[j + a][i - a];
            if (mGr > SWsc) SWsc = mGr;
        }
        for (int a = 1; ((i + a) <= 9) && ((j - a) >= 0); a++) {
            mGr = grMat[j - a][i + a];
            if (mGr > SWsc) SWsc = mGr;
        }
        SWsc = abs(SWsc);
        if (abs(tSc) > SWsc) {
            SWsc = tSc;
            fEXP1 *= 0.88;
            resetExp(fEXP1);
            fEXP2 *= 0.88;
            resetExp(fEXP2);
            fHP1 *= 0.9;
            resetHP(fHP1);
            fHP2 *= 0.9;
            resetHP(fHP2);
        }
        else {
            fEXP1 *= 1.12;
            resetExp(fEXP1);
            fEXP2 *= 1.12;
            resetExp(fEXP2);
            fHP1 *= 1.1;
            resetHP(fHP1);
            fHP2 *= 1.1;
            resetHP(fHP2);
        }
        EXP1 = ceil(fEXP1);
        EXP2 = ceil(fEXP2);
        HP1 = ceil(fHP1);
        HP2 = ceil(fHP2);
        task3 = SWsc;
    }
    else task3 = -99;
    return task3;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    int result = 0, fa = 0, sei = 0, sci = strlen(s), spChar[5]{ 33, 35, 36, 37, 64 };;
    // Get se
    stringstream ss;
    ss << email;
    string se = ss.str();
    for (int i = 0; i < se.length(); i++) {
        if (se[i] == '@')
        {
            fa = i;
            break;
        }
    }
    se.erase(fa, se.length() - fa);
    // Contain se check
    for (int i = 0; i < strlen(s); i++) {
        int test = 0;
        if (s[i] == se[0])
            for (int j = 0; j < se.length(); j++) {
                if (s[i + j] == se[j]) test++;
                else break;
            }
        if (test == se.length()) {
            sei = i;
            break;
        }
        sei = i + 1;
    }
    // Contain more than 2 chars check
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == s[i + 1]) {
            if (s[i + 1] == s[i + 2]) {
                sci = i;
                break;
            }
        }
    }
    if (strlen(s) >= 8) {
        if (strlen(s) <= 20) {
            if (sei == strlen(s)) {
                // Contain special chars check
                if (sci == strlen(s)) {
                    for (int i = 0; i < 5; i++) {
                        if (memchr(s, spChar[i], strlen(s))) {
                            result = 5;
                            break;
                        }
                        else result = -5;
                    }
                    // Remaining cases check
                    if (result == 5) {
                        for (int i = 0; i < strlen(s); i++) {
                            if ((s[i] == 33) || ((s[i] >= 35) && (s[i] <= 37)) || ((s[i] >= 48) && (s[i] <= 57)) || ((s[i] >= 64) && (s[i] <= 90)) || ((s[i] >= 97) && (s[i] <= 122))) result = -10;
                            else {
                                result = i;
                                break;
                            }
                        }
                    }
                }
                else result = -(400 + sci);
            }
            else result = -(300 + sei);
        }
        else result = -2;
    }
    else result = -1;
    return result;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int re = 1, max = 0, pos = 0, result;
    for (int i = 0; i < num_pwds; i++) {
        result = 0;
        for (int j = 0; j < i; j++) {
            if (arr_pwds[i] == arr_pwds[j]) {
                re = 0;
                break;
            }
            else re = 1;
        }
        if (re) {
            for (int k = i; k < num_pwds; k++) {
                if (arr_pwds[i] == arr_pwds[k]) {
                    result++;
                }
            }
            if (max < result) {
                max = result;
                pos = i;
            }
            if ((max == result) && (pos != i)) {
                if (strlen(arr_pwds[pos]) < strlen(arr_pwds[i])) {
                    pos = i;
                }
            }
        }
        else continue;
    }
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////