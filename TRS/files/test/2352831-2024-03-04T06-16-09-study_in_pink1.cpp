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
int cceil(double num) {
    int temp = num;
    if ((num - temp) <= 10e-5) return temp;
    else return temp + 1;
}

void capHp(int& hp) {
    if (hp < 0) hp = 0;
    if (hp > 666) hp = 666;
    return;
}

void capExp(int& exp) {
    if (exp < 0) exp = 0;
    if (exp > 600) exp = 600;
    return;
}

void capM(int& m) {
    if (m < 0) m = 0;
    if (m > 3000) m = 3000;
    return;
}

bool checkE(int e) {
    if (e < 0 || e>99) return false;
    else return true;
}

int nearestSquare(int n) {
    int l = floor(sqrt(n)), r = ceil(sqrt(n));
    return (n - l * l) < (r * r - n) ? l * l : r * r;
}
// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    if (checkE(e1) == false) return -99;
    capExp(exp1);
    capExp(exp2);
    //Case 1
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) exp2 += 29;
        else if (e1 == 1) exp2 += 45;
        else if (e1 == 2) exp2 += 75;
        else if (e1 == 3) exp2 += (29 + 45 + 75);

        int D = 3 * e1 + 7 * exp1;
        if (D % 2 == 0) exp1 = cceil(exp1 + D / 200.0);
        else exp1 = cceil(exp1 - D / 100.0);

        capExp(exp1);
        capExp(exp2);
    }
    //Case 2
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) exp2 += cceil(e1 / 4.0 + 19);
        else if (e1 >= 20 && e1 <= 49) exp2 += cceil(e1 / 9.0 + 21);
        else if (e1 >= 50 && e1 <= 65) exp2 += cceil(e1 / 16.0 + 17);
        else if (e1 >= 66 && e1 <= 79) {
            exp2 += ceil(e1 / 4.0 + 19);
            if (exp2 > 200) exp2 += cceil(e1 / 9.0 + 21);
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 += cceil(e1 / 4.0 + 19) + cceil(e1 / 9.0 + 21);
            if (exp2 > 400) exp2 = cceil(1.15 * (exp2 + cceil(e1 / 16.0 + 17)));
        }
        exp1 -= e1;
        capExp(exp1);
        capExp(exp2);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (checkE(E2) == false) return -99;
    capHp(HP1);
    capExp(EXP1);
    capM(M1);
    double P1, P2, P3;
    //Road 1
    int S = nearestSquare(EXP1);
    if (EXP1 >= S) P1 = 100;
    else P1 = 100 * (float(EXP1 / S) + 80) / 123.0;
    //Road 2
    ///Spend >50% of initial money -> spend until M1<=50% 
    int savings = cceil(M1 / 2.0);
    do {
        if ((E2 % 2 == 1 && M1 < savings) || (M1 == 0)) break;
        //Grocery
        if (HP1 < 200) {
            HP1 = cceil(1.3 * HP1);
            M1 -= 150;
        }
        else {
            HP1 = cceil(1.1 * HP1);
            M1 -= 70;
        }
        capHp(HP1);
        capM(M1);
        if ((E2 % 2 == 1 && M1 < savings) || (M1 == 0)) break;
        //Travel
        if (EXP1 < 400) M1 -= 200;
        else M1 -= 120;
        EXP1 = cceil(1.13 * EXP1);
        capExp(EXP1);
        capM(M1);
        if ((E2 % 2 == 1 && M1 < savings) || (M1 == 0)) break;
        //Meet homeless person
        if (EXP1 < 300) M1 -= 100;
        else M1 -= 120;
        EXP1 = cceil(0.9 * EXP1);
        capExp(EXP1);
        capM(M1);
        if ((E2 % 2 == 1 && M1 < savings) || (M1 == 0)) break;
    } while (E2 % 2 == 1);
    HP1 = cceil(0.83 * HP1);
    EXP1 = cceil(1.17 * EXP1);
    capHp(HP1);
    capExp(EXP1);
    ///Calculate P2
    S = nearestSquare(EXP1);
    if (EXP1 >= S) P2 = 100;
    else P2 = 100 * (float(EXP1 / S) + 80) / 123.0;
    //Road 3
    double P[10] = { 32,47,28,79,100,50,22,83,64,11 };
    if (E2 < 10) P3 = P[E2];
    else P3 = P[(E2 % 10 + (E2 - E2 % 10) / 10) % 10];
    //After 3 routes
    double sum = P1 + P2 + P3;
    if (sum == 300) EXP1 = cceil(0.75 * EXP1);
    else if (sum >= 150) {
        HP1 = cceil(0.9 * HP1);
        EXP1 = cceil(1.2 * EXP1);
    }
    else {
        HP1 = cceil(0.85 * HP1);
        EXP1 = cceil(1.15 * EXP1);
    }
    capExp(EXP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (checkE(E3) == false) return -99;
    capHp(HP1);
    capHp(HP2);
    capExp(EXP1);
    capExp(EXP2);
    int matrix[10][10];
    int i = 0, j = 0, a, b;
    //Entry in matrix value
    for (a = 0; a < 10; a++) {
        for (b = 0; b < 10; b++) {
            matrix[a][b] = (E3 * b + a * 2) * (a - b);
        }
    }
    for (a = 0; a < 10; a++) {
        for (b = 0; b < 10; b++) {
            if (matrix[a][b] > 2 * E3) i++;
            if (matrix[a][b] < -E3) j++;
        }
    }
    while (i >= 10 || j >= 10) {
        i = i % 10 + (i - i % 10) / 10;
        j = j % 10 + (j - j % 10) / 10;
    }
    int taxi = matrix[i][j], SW = matrix[i][j];
    //Left diagonal
    if (i < j) {
        a = 0; b = j - i;
    }
    else {
        a = i - j; b = 0;
    }
    while (a < 10 && b < 10) {
        if (matrix[a][b] > SW) SW = matrix[a][b];
        a++; b++;
    }
    //Right diagonal
    if (i + j <= 9) {
        a = 0; b = i + j;
    }
    else {
        b = 9; a = i + j - 9;
    }
    while (b >= 0 && a <= 9) {
        if (matrix[a][b] > SW) SW = matrix[a][b];
        a++; b--;
    }
    SW = abs(SW);
    if (abs(taxi) > SW) {
        HP1 = cceil(0.9 * HP1);
        HP2 = cceil(0.9 * HP2);
        EXP1 = cceil(0.88 * EXP1);
        EXP2 = cceil(0.88 * EXP2);
    }
    else {
        HP1 = cceil(1.1 * HP1);
        HP2 = cceil(1.1 * HP2);
        EXP1 = cceil(1.12 * EXP1);
        EXP2 = cceil(1.12 * EXP2);
    }
    capHp(HP1);
    capHp(HP2);
    capExp(EXP1);
    capExp(EXP2);

    return abs(taxi) > SW ? taxi : SW;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    char se[100];
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            strncpy(se, email, i);
            se[i] = '\0';
            break;
        }
    }
    if (strlen(s) < 8) return -1;
    if (strlen(s) > 20) return -2;

    char scheck[100];
    for (int i = 0; i < strlen(s); i++) {
        strncpy(scheck, s + (i), strlen(se)); scheck[strlen(se)] = '\0';
        if (strcmp(se, scheck) == 0) return -(300 + i);
    }

    for (int i = 0; i < strlen(s) - 2; i++) {
        if (s[i] != s[i + 1]) continue;
        else if (s[i + 1] == s[i + 2]) return -(400 + i);
    }
    int count = 0;
    for (int i = 0; i < strlen(s); i++) {
        if ((s[i] == '!') || (s[i] == '@') || (s[i] == '#') || (s[i] == '$') || (s[i] == '%')) {
            count++;
            break;
        }
    }
    if (count == 0) return -5;

    for (int i = 0; i < strlen(s); i++) {
        if (!(s[i] >= '0' && s[i] <= '9')) {
            if (!(s[i] >= 'A' && s[i] <= 'Z')) {
                if (!(s[i] >= 'a' && s[i] <= 'z')) {
                    if (!((s[i] == '!') || (s[i] == '@') || (s[i] == '#') || (s[i] == '$') || (s[i] == '%'))) {
                        return i;
                    }
                }
            }
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {

    int idx[num_pwds]; //Count the number of apperance
    memset(idx, 0, num_pwds * sizeof(int));

    for (int i = 0; i < num_pwds; i++) {
        for (int j = i + 1; j < num_pwds; j++) {
            if ((strcmp(arr_pwds[i], arr_pwds[j]) == 0) && (idx[i] >= 0)) {
                idx[i]++;
                idx[j] = -1;
            }
        }
    }
    int max = idx[0]; //Appear most in a array
    int pos = 0; //Mark the position
    for (int i = 1; i < num_pwds; i++) { //Find max
        if (idx[i] > max) {
            max = idx[i];
            pos = i;
        }
    }
    for (int i = pos + 1; i < num_pwds; i++) {
        if (idx[i] == max) {
            if (strlen(arr_pwds[i]) > strlen(arr_pwds[pos])) pos = i;
        }
    }
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////