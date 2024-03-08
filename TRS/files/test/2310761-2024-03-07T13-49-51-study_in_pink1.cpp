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
bool checkE(int E) {
    bool checke = 1;
    if (E < 0 and E>99) {
        checke = 0;
    }
    return checke;
}
void checkEXP(int& EXP) {
    if (EXP > 600) EXP = 600;
    else if (EXP < 0) EXP = 0;
}
void checkHP(int& HP) {
    if (HP > 666) HP = 666;
    else if (HP < 0) HP = 0;
}
void checkM(int& M) {
    if (M > 3000) M = 3000;
    else if (M < 0) M = 0;
}
// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {
    // TODO: Complete this function
    if (checkE(E1) == 0) return -99;
    if (E1 >= 0 and E1 <= 3) {
        if (E1 == 0) EXP2 += 29;
        else if (E1 == 1) EXP2 += 45;
        else if (E1 == 2) EXP2 += 75;
        else if (E1 == 3) EXP2 += 149;
        int d;
        d = E1 * 3 + EXP1 * 7;
        if (d % 2 == 0) EXP1 += d / 200;
        else EXP1 -= d / 100;
    }

    if (E1 >= 4 and E1 <= 99) {
        if (E1 <= 19) EXP2 = EXP2 + (float)E1 / 4 + 19 + 0.999;
        else if (E1 <= 49) EXP2 = EXP2 + (float)E1 / 9 + 21 + 0.999;
        else if (E1 <= 65) EXP2 = EXP2 + (float)E1 / 16 + 17 + 0.999;
        else if (E1 <= 79) {
            if (EXP2 = EXP2 + E1 / 4 + 19 < 200) EXP2 = EXP2 + (float)E1 / 4 + 19 + 0.999;
            else {
                EXP2 = EXP2 + (float)E1 / 4 + 19 + 0.999;
                EXP2 = EXP2 + (float)E1 / 9 + 21 + 0.999;
            }
        }
        else if (E1 <= 99) {
            if (EXP2 + E1 / 4 + 19 + E1 / 9 + 21 < 400) {
                EXP2 = EXP2 + (float)E1 / 4 + 19 + 0.999;
                EXP2 = EXP2 + (float)E1 / 9 + 21 + 0.999;
            }
            else {
                EXP2 = EXP2 + (float)E1 / 4 + 19 + 0.999;
                EXP2 = EXP2 + (float)E1 / 9 + 21 + 0.999;
                EXP2 = EXP2 + (float)E1 / 16 + 17 + 0.999;
                EXP2 = 1.15 * EXP2 + 0.999;
            }
        }
        EXP1 = EXP1 - E1 + 0.999;
        
    }
    checkEXP(EXP1); checkEXP(EXP2);
    return EXP1 + EXP2;

}

// Task 2
int chinhphuong(int n) {
    int x, y;
    x = sqrt(n);
    y = x + 1;
    if (n - x * x < y * y - n) return x * x;
    else return y * y;
}

void again() {
    int traceLuggage(int& HP1, int& EXP1, int& M1, int E2);
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    //con duong 1
    if (checkE(E2) == 0) return -99;
    float P1, P2, P3, TB;
    int S1 = chinhphuong(EXP1);
    if (EXP1 >= S1)	P1 = 1;
    else P1 = ((float)EXP1 / S1 + 80) / 123;
    //con duong 2
    int m = 0.5 * M1;
    while (M1 > m) {
        if (HP1 < 200) {           //hanh dong 1
            HP1 = 1.3 * HP1 + 0.999;
            M1 -= 150;
        }
        else {
            HP1 = 1.1 * HP1 + 0.999;
            M1 -= 70;
        }
        if (M1 < m)	break;
        if (EXP1 < 400) {
            M1 -= 200; //di taxi
            EXP1 = 1.13 * EXP1 + 0.999;
        }
        else {
            M1 -= 120;
            EXP1 = 1.13 * EXP1 + 0.999;    //di xe ngua
        }
        if (M1 < m)	break;
        if (EXP1 < 300) {
            M1 -= 100;           //vo gia cu
            EXP1 = 0.9 * EXP1 + 0.999;
        }
        else {
            M1 -= 120;
            EXP1 = 0.9 * EXP1 + 0.999;
        }

        if (E2 % 2 == 0) {
            HP1 = 0.83 * HP1 + 0.999;
            EXP1 = 1.17 * EXP1 + 0.999;
            break;
        }
    }
    if (E2 % 2 == 1) {
        HP1 = 0.83 * HP1 + 0.999;
        EXP1 = 1.17 * EXP1 + 0.999;
    }
    int S2 = chinhphuong(EXP1);
    if (EXP1 >= S2)	P2 = 1;
    else P2 = ((float)EXP1 / S2 + 80) / 123;
    //con duong 3
    int i;
    float P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2 < 10) i = E2;
    else {
        int j = E2 / 10 + E2 % 10;
        if (j < 10)	i = j;
        else i = j % 10;
    }
    P3 = P[i] / 100;
    //ket
    if (P1 == 1 and P2 == 1 and P3 == 1) {
        EXP1 = EXP1 * 0.75 + 0.999;
        again;
    }
    else TB = (P1 + P2 + P3) / 3;
    if (TB < 0.5) {
        HP1 = 0.85 * HP1 + 0.999;
        EXP1 = 1.15 * EXP1 + 0.999;
    }
    else {
        HP1 = 0.9 * HP1 + 0.999;
        EXP1 = 1.2 * EXP1 + 0.999;
    }
    checkEXP(EXP1); checkHP(HP1);   checkM(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (checkE(E3) == 0)   return -99;
    float gradeTaxi[10][10];
    float grade[10][10];
    int i = 0, j = 0;
    int tra;
    for (int m = 0; m < 10; m++) {
        for (int n = 0; n < 10; n++) {
            gradeTaxi[m][n] = ((E3 * n) + (m * 2)) * (m - n);
            if (gradeTaxi[m][n] > E3 * 2) i++;
            if (gradeTaxi[m][n] < -E3 * 2) j++;

        }
    }

    float maxleft, maxright;
    while (i > 9)	i = i / 10 + i % 10;
    while (j > 9)	j = j / 10 + j % 10;
    int k, t;
    k = i;  t = j;
    while (k > 0 && t > 0) {
        maxleft = max(maxleft, gradeTaxi[k][t]);
        k--; t--;
    }
    k = i; t = j;
    while (k < 10 && t < 10) {
        maxleft = max(maxleft, gradeTaxi[k][t]);
        k++; t++;
    }
    k = i; t = j;
    while (k > 0 && t < 10) {
        maxright = max(maxright, gradeTaxi[k][t]);
        k--; t++;
    }
    k = i; t = j;
    while (k < 10 && t > 0) {
        maxright = max(maxright, gradeTaxi[k][t]);
        k++; t--;
    }
    if (maxright > maxleft) grade[i][j] = maxright;
    else grade[i][j] = maxleft;


    if (abs(gradeTaxi[i][j]) > grade[i][j]) {
        EXP1 *= 0.88;
        HP1 *= 0.9;
        EXP2 *= 0.88;
        HP2 *= 0.9;
        tra = gradeTaxi[i][j];
    }
    else {
        EXP1 *= 1.12;
        HP1 *= 1.1;
        EXP2 *= 1.12;
        HP2 *= 1.1;
        tra = grade[i][j] - gradeTaxi[i][j];
    }
    
    return tra;
}

// Task 4
bool checkContain(const char* s, const char* se) {
    char* first;
    first = strstr(s, se);
    if (first != NULL)
        return true;
    else
        return false;
}

bool checkRepeat(const char* s, int& j) {
    bool result = false;
    for (int i = 0; i < strlen(s) - 2; i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            result = true;
            j = i;
            break;
        }
    }
    return result;
}

bool checkNoSpecialDigits(const char* s) {
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '@' || s[i] == '#' ||
            s[i] == '%' || s[i] == '$' || s[i] == '!'){
            return false;
        }
    }
    return true;
}

int checkPassword(const char* s, const char* email) {
    int checkpass;
    char se[100];
    int i = 0;
    while (*(email + i) != '@') {
        *(se + i) = *(email + i);
        i++;
    }
    se[i] = '\0'; // Null terminate the se string
    int j;
    if (strlen(s) >= 8 && strlen(s) <= 10 && !checkContain(s, se)
        && !checkRepeat(s, j)
        && checkNoSpecialDigits(s))
        checkpass = -10;
    else if (strlen(s) < 8)
        checkpass = -1;
    else if (strlen(s) > 20)
        checkpass = -2;
    else if (checkContain(s, se)) {
        const char* sei;
        sei = strstr(s, se);
        checkpass = -(300 + (sei - s));
    } else if (checkRepeat(s, j)) {
        checkpass = -(400 + j);
    } else if (!checkNoSpecialDigits(s))
        checkpass = -5;
    cout << checkpass << endl;
    return checkpass;
}
// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxCount = 0;
    string mostFrequent;
    for (int i = 0; i < num_pwds; i++) {
        string currentPass = arr_pwds[i];
        int currentCount = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (arr_pwds[j] == currentPass) currentCount++;
        }
        if (currentCount > maxCount or (currentCount = maxCount and currentPass.length() > mostFrequent.length())) {
            maxCount = currentCount;
            mostFrequent = currentPass;
        }
    }
   
    int result;
    for (int k = 0; k < num_pwds; k++) {
        if (arr_pwds[k] == mostFrequent) {
            result = k;
            break;
        }
    }
    return result;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
