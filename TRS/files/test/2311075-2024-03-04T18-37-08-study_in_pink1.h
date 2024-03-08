/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2023
* Author: Vu Van Tien
* Date: 02.02.2023
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef _H_STUDY_IN_PINK_1_H_
#define _H_STUDY_IN_PINK_1_H_

#include "main.h"

bool readFile( const string & filename, int & HP1, int & HP2, int & EXP1, int & EXP2, int & M1, int & M2, int & E1, int & E2, int & E3);

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
#define CLAMP_HP(HP) \
    do { \
        if (HP > 600) HP = 600; \
        if (HP < 0) HP = 0; \
    } while(0)

#define CLAMP_EXP(EXP) \
    do { \
        if (EXP > 600) EXP = 600; \
        if (EXP < 0) EXP = 0; \
    } while(0)

#define CLAMP_M(M) \
    do { \
        if (M > 1000) M = 1000; \
        if (M < 0) M = 0; \
    } while(0)

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    if (E1 >= 0 && E1 <= 3) {
        EXP2 += (E1 == 0) ? 29 : (E1 == 1) ? 45 : (E1 == 2) ? 75 : 149;

        double D = E1 * 3.0 + EXP1 * 7.0;
        if (int(D) % 2 == 0) {
            EXP1 = EXP1 + ceil(D / 200.0);
            CLAMP_EXP(EXP1);
        }
        else {
            EXP1 = EXP1 - ceil(D / 100.0);
            CLAMP_EXP(EXP1);
        }
    }

    if (E1 >= 4 && E1 <= 99) {
        if (E1 >= 4 && E1 <= 19) {
            EXP2 += ceil(E1 / 4.0) + 19;
            CLAMP_EXP(EXP2);
        }
        else if (E1 >= 20 && E1 <= 49) {
            EXP2 += ceil(E1 / 9.0) + 21;
            CLAMP_EXP(EXP2);
        }
        else if (E1 >= 50 && E1 <= 65) {
            EXP2 += ceil(E1 / 16.0) + 17;
            CLAMP_EXP(EXP2);
        }
        else if (E1 >= 66 && E1 <= 79) {
            EXP2 += ceil(E1 / 9.0) + 19;
            CLAMP_EXP(EXP2);
            if (EXP2 > 200) {
                EXP2 += ceil(E1 / 9.0) + 21;
                CLAMP_EXP(EXP2);
            }
        }
        else if (E1 >= 80 && E1 <= 99) {
            EXP2 += ceil(E1 / 4.0) + 19;
            CLAMP_EXP(EXP2);
            EXP2 += ceil(E1 / 9.0) + 21;
            CLAMP_EXP(EXP2);
            if (EXP2 > 400) {
                EXP2 += ceil(E1 / 16.0) + 17;
                CLAMP_EXP(EXP2);
                EXP2 = ceil(1.15 * EXP2);
                CLAMP_EXP(EXP2);
            }
        }
        EXP1 -= E1;
        CLAMP_EXP(EXP1);
    }

    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    double P1, P2, P3;
    int S;
    S = int(sqrt(EXP1));
    S = int(abs(EXP1 - pow(S, 2)) < abs(EXP1 - pow(S + 1, 2)) ? pow(S, 2) : pow(S + 1, 2));

    P1 = (EXP1 > S) ? 1 : (EXP1 * 1.0 / S * 1.0 + 80) / 1.23;

    int flag = 1;
    int m1 = 0;

    while (flag && m1 < M1 / 2) {

        if (HP1 < 200) {
            HP1 = ceil(HP1 * 1.3);    CLAMP_HP(HP1);
            m1 += 150; if (m1 > M1 / 2) break;
        }
        else {
            HP1 = ceil(HP1 * 1.1);    CLAMP_HP(HP1);
            m1 += 70; if (m1 > M1 / 2) break;
        }
        m1 += (EXP1 < 400) ? 200 : 120;
        EXP1 = ceil(1.13 * EXP1); CLAMP_EXP(EXP1);

        if (m1 > M1 / 2) break;
        m1 += (EXP1 < 300) ? 100 : 120;
        EXP1 = ceil(EXP1 * 0.9); CLAMP_EXP(EXP1);
        if (m1 > M1 / 2) break;
        flag = (E2 % 2 == 1) ? 1 : 0;
    }
    HP1 = ceil(HP1 * 0.83);    CLAMP_HP(HP1);
    EXP1 = ceil(EXP1 * 1.17); CLAMP_EXP(EXP1);
    M1 -= m1;

    S = sqrt(EXP1);
    S = int(abs(EXP1 - pow(S, 2)) < abs(EXP1 - pow(S + 1, 2)) ? pow(S, 2) : pow(S + 1, 2));

    P2 = (EXP1 > S) ? 1 : (EXP1 * 1.0 / S * 1.0 + 80) / 123;


    int p[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int m;
    if (E2 >= 10) {
        m = E2 % 10 + E2 / 10;

        if (m >= 10) m = m % 10;
    }
    else m = E2;
    P3 = p[m] / 100.0;
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = ceil(EXP1 * 0.75); CLAMP_EXP(EXP1);
        ////////////
    }
    else {
        double P = (P1 + P2 + P3) / 3;

        if (P < 0.5) {
            HP1 = ceil(HP1 * 0.85);    CLAMP_HP(HP1);
            EXP1 = ceil(EXP1 * 1.15); CLAMP_EXP(EXP1);
        }
        else {
            HP1 = ceil(HP1 * 0.9);    CLAMP_HP(HP1);
            EXP1 = ceil(EXP1 * 1.2); CLAMP_EXP(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}
int maxMatrix(int a[10][10], int b, int c) {

    //cheo trai
    int i = b, j = c, max = a[b][c];
    while (c < 9) {
        if (max < a[i][j])max = a[i][j];
        i++; j++;
        if (i > 10 || j > 10)break;
    }
    i = b; j = c;
    while (b > 0) {
        if (max < a[i][j]) max = a[i][j];
        i--; j--;
        if (i < 0 || j < 0)break;
    }
    //cheo phai
    i = b, j = c;
    while (b > 0) {
        if (max < a[i][j])max = a[i][j];
        i--; j++;
        if (i < 0 || j>10)break;
    }
    i = b; j = c;
    while (c < 9) {
        if (max < a[i][j]) max = a[i][j];
        i++; j--;
        if (i > 10 || j < 0)break;
    }
    return max;
}

int checkMax(int a[10][10], int e) {
    int dem = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (a[i][j] > e * 2)dem++;
        }
    }
    return dem;
}
int checkMin(int a[10][10], int e) {
    int dem = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (a[i][j] < -e)dem++;
        }
    }
    return dem;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int a[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int x = checkMax(a, E3);

    int y = checkMin(a, E3);

    if (x >= 10) {
        x = x % 10 + x / 10;
        if (x >= 10) x = x % 10 + x / 10;
    }

    if (y >= 10) {
        y = y % 10 + y / 10;
        if (y >= 10) y = y % 10 + x / 10;
    }

    int Total = maxMatrix(a, x, y);

    if (Total > abs(a[x][y])) {
        EXP1 = ceil(1.12 * EXP1);
        CLAMP_EXP(EXP1);
        HP1 = ceil(1.10 * HP1);
        EXP2 = ceil(1.12 * EXP2);
        CLAMP_EXP(EXP2);
        HP2 = ceil(1.10 * HP2);
    }
    else {
        EXP1 = ceil(0.88 * EXP1);
        CLAMP_EXP(EXP1);
        HP1 = ceil(0.9 * HP1);

        EXP2 = ceil(0.88 * EXP2);
        CLAMP_EXP(EXP2);
        HP2 = ceil(0.9 * HP2);
    }

    if (Total > abs(a[x][y]))
        return Total;
    else
        return a[x][y];

    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    return -99;
}

// Task 5


int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    char set[30][100];
    int index = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (checkset(set, arr_pwds[i], index) == 0) {
            int j = 0;
            while (arr_pwds[i][j] != '\0') {
                set[index][j] = arr_pwds[i][j];
                j++;
            }
            set[index][j] = '\0';
            index++;
        }
    }

    char FFF[100];
    int mmm = 0;
    int nnn = 0;
    for (int i = 0; i < index; i++) {
        char hh[100];
        int j = 0;
        while (set[i][j] != '\0') {
            hh[j] = set[i][j];
            j++;
        }
        hh[j] = '\0';
        int dem = 0;
        for (int j = 0; j < num_pwds; j++) {
            int k = 0;
            while (arr_pwds[j][k] != '\0' && hh[k] != '\0') {
                if (arr_pwds[j][k] != hh[k])
                    break;
                k++;
            }
            if (arr_pwds[j][k] == '\0' && hh[k] == '\0')
                dem++;
        }
        if (dem > mmm || (dem == mmm && nnn < j)) {
            int k = 0;
            while (k <= j) {
                FFF[k] = hh[k];
                k++;
            }
            mmm = dem;
            nnn = j;
        }
    }
    for (int i = 0; i < num_pwds; i++) {
        int j = 0;
        while (arr_pwds[i][j] != '\0' && FFF[j] != '\0') {
            if (arr_pwds[i][j] != FFF[j])
                break;
            j++;
        }
        if (arr_pwds[i][j] == '\0' && FFF[j] == '\0')
            return i;
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
