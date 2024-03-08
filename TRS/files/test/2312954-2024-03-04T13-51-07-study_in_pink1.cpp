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
    if (exp1 > 600) { exp1 = 600; }
    if (exp1 < 0) { exp1 = 0; }
    if (exp2 > 600) { exp2 = 600; }
    if (exp2 < 0) { exp2 = 0; }
    if (e1 < 0 || e1>99) {
        e1 = -99;
    }
    else {
        if (e1 <= 3) {
            if (e1 == 0) {
                exp2 += 29;
            }
            else if (e1 == 1) {
                exp2 += 45;
            }
            else if (e1 == 2) {
                exp2 += 75;
            }
            else if (e1 == 3) {
                exp2 += 149;
            }
            if (exp2 > 600) { exp2 = 600; }
            if (exp2 < 0) { exp2 = 0; }
            int D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0) {
                exp1 = ceil(exp1 + (double)D / 200);

            }
            else { exp1 = ceil(exp1 - (double)D / 100); }
            if (exp1 > 600) { exp1 = 600; }
            if (exp1 < 0) { exp1 = 0; }
        }

        else {
            if (e1 <= 19) {
                exp2 = ceil(exp2 + (double)e1 / 4 + 19);
            }
            else if (e1 <= 49) {
                exp2 = ceil(exp2 + (double)e1 / 9 + 21);
            }
            else if (e1 <= 65) {
                exp2 = ceil(exp2 + (double)e1 / 16 + 17);
            }
            else if (e1 <= 79) {
                exp2 = ceil(exp2 + (double)e1 / 4 + 19);
                if (exp2 > 200) { exp2 = ceil(exp2 + (double)e1 / 9 + 21); }
            }
            else {
                if (e1 <= 99) {
                    exp2 = ceil(exp2 + (double)e1 / 4 + 19);
                    exp2 = ceil(exp2 + (double)e1 / 9 + 21);
                    if (exp2 > 400) {
                        exp2 = ceil(exp2 + (double)e1 / 16 + 17);
                        exp2 = ceil((double)exp2 * 1.25);
                    }
                }

            }
            if (exp2 > 600) { exp2 = 600; }
            if (exp2 < 0) { exp2 = 0; }
            exp1 -= e1;
        }
        if (exp1 > 600) { exp1 = 600; }
        if (exp1 < 0) { exp1 = 0; }
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 < 0 || E2>99) {
        E2 = -99;
    }
    else {
        if (EXP1 > 600) { EXP1 = 600; }
        if (EXP1 < 0) { EXP1 = 0; }
        if (HP1 > 666) { HP1 = 666; }
        if (HP1 < 0) { HP1 = 0; }
        if (M1 > 3000) { M1 = 3000; }
        if (M1 < 0) { M1 = 0; }
        double P1;
        int S = sqrt(EXP1);
        if (EXP1 >= S * S) P1 = 1.0;
        else P1 = (double)(EXP1 * 100 / S + 80) / 123.0;

        if (E2 % 2 == 0)
        {
            if (HP1 < 200)
            {
                HP1 = ceil((double)HP1 * 1.3);
                if (HP1 > 666) { HP1 = 666; }
                M1 -= 150;

            }
            else
            {
                HP1 = ceil((double)HP1 * 1.1);
                if (HP1 > 666) { HP1 = 666; }
                M1 -= 70;

            }
            if (M1 <= 0)
            {
                M1 = 0;
                goto start;
            }

            if (EXP1 < 400)
            {
                M1 -= 200;
                EXP1 = ceil((double)EXP1 * 1.13);
                if (EXP1 > 600) { EXP1 = 600; }
            }
            else
            {
                M1 -= 120;
                EXP1 = ceil((double)EXP1 * 1.13);
                if (EXP1 > 600) { EXP1 = 600; }
            }
            if (M1 <= 0)
            {
                M1 = 0;
                goto start;
            }


            if (EXP1 > 600) { EXP1 = 600; }
            if (EXP1 < 300)
            {
                M1 -= 100;
                if (M1 < 0) { M1 = 0; }
                EXP1 = ceil((double)EXP1 * 0.9);
            }
            else
            {
                M1 -= 120;
                EXP1 = ceil((double)EXP1 * 0.9);
            }
            if (M1 <= 0)
            {
                M1 = 0;
                goto start;
            }
        }
        else
        {
            int q = M1 / 2;
            bool t = true;
            int totalspent = 0;
            while (t)
            {
                if (HP1 < 200)
                {
                    HP1 = ceil((double)HP1 * 1.3);
                    if (HP1 > 666) { HP1 = 666; }
                    M1 -= 150;
                    if (M1 < 0) { M1 = 0; }
                    totalspent += 150;
                }
                else
                {
                    HP1 = ceil((double)HP1 * 1.1);
                    if (HP1 > 666) { HP1 = 666; }
                    M1 -= 70;
                    if (M1 < 0) { M1 = 0; }
                    totalspent += 70;
                }
                if (totalspent > q)
                {
                    break;
                }
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    if (M1 < 0) { M1 = 0; }
                    totalspent += 200;
                    EXP1 = ceil((double)EXP1 * 1.13);
                    if (EXP1 > 600) { EXP1 = 600; }
                }
                else
                {
                    M1 -= 120;
                    totalspent += 120;
                    EXP1 = ceil((double)EXP1 * 1.13);
                    if (EXP1 > 600) { EXP1 = 600; }
                }
                if (totalspent > q)
                {
                    break;
                }
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    if (M1 < 0) { M1 = 0; }
                    totalspent += 100;
                    EXP1 = ceil((double)EXP1 * 0.9);
                }
                else
                {
                    M1 -= 120;
                    if (M1 < 0) { M1 = 0; }
                    totalspent += 120;
                    EXP1 = ceil((double)EXP1 * 0.9);
                }
                if (totalspent > q)
                {
                    break;
                }
            }
        }
    start:
        HP1 = ceil((double)HP1 * 0.83);
        EXP1 = ceil((double)EXP1 * 1.17);
        if (EXP1 > 600) { EXP1 = 600; }

        double P2 = 0.0;
        int S1 = sqrt(EXP1);
        if (EXP1 >= S1 * S1) P2 = 1.0;
        else P2 = (double)(EXP1 / S1 + 80) / 123.0;

        int P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        int i;
        if (E2 < 10)
        {
            i = E2;
        }
        else
        {
            int a = E2 / 10 + E2 % 10;
            i = a % 10;
        }
        double P3 = P[i] / 100.0;
        if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0)
        {
            EXP1 = ceil((double)EXP1 * 0.75);
        }
        else
        {
            double avg_P = (P1 + P2 + P3) / 3.0;
            if (avg_P < 0.5)
            {
                HP1 = ceil((double)HP1 * 0.85);
                EXP1 = ceil((double)EXP1 * 1.15);
                if (EXP1 > 600) { EXP1 = 600; }
            }
            else
            {
                HP1 = ceil((double)HP1 * 0.9);
                EXP1 = ceil((double)EXP1 * 1.2);
                if (EXP1 > 600) { EXP1 = 600; }
            }
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    int h = 0;
    if (E3 < 0 || E3>99) {
        E3 = -99;
    }
    else {
        if (EXP1 > 600) { EXP1 = 600; };
        if (EXP1 < 0) { EXP1 = 0; };
        if (HP1 > 666) { HP1 = 666; };
        if (HP1 < 0) { HP1 = 0; };
        if (EXP2 > 600) { EXP2 = 600; };
        if (EXP2 < 0) { EXP2 = 0; };
        if (HP2 > 666) { HP2 = 666; };
        if (HP2 < 0) { HP2 = 0; };
        int  b = 0, c = 0;
        int a[10][10] = { 0 };
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                if (a[i][j] > (E3 * 2))  b++;
                if (a[i][j] < (-E3))  c++;
            }
        }

        while (b > 9) {
            b = (b % 10) + (b - (b % 10)) / 10;
        }
        while (c > 9) {
            c = (c % 10) + (c - (c % 10)) / 10;
        }
        int d = abs(a[b][c]);
        int g = a[b][c];
        int e = a[b][c];
        int t1 = b, t2 = b, t3 = b, t4 = b;
        int y1 = c, y2 = c, y3 = c, y4 = c;
        while (t1 < 9 && y1 < 9) {
            t1++; y1++;
            if (a[t1][y1] > e) {
                e = a[t1][y1];
            }
        }
        while (t2 > 0 && y2 > 0) {
            t2--; y2--;
            if (a[t2][y2] > e) {
                e = a[t2][y2];
            }
        }
        while (t3 > 0 && y3 < 9) {
            t3--; y3++;
            if (a[t3][y3] > e) {
                e = a[t3][y3];
            }
        }
        while (t4 < 9 && y4 > 0) {
            t4++; y4--;
            if (a[t4][y4] > e) {
                e = a[t4][y4];
            }
        }
        int f;
        f = abs(e);
        if (d > f) {
            EXP1 = ceil((double)EXP1 * 0.88);
            EXP2 = ceil((double)EXP2 * 0.88);
            HP1 = ceil((double)HP1 * 0.9);
            HP2 = ceil((double)HP2 * 0.9);
            h = g;
        }
        else {
            EXP1 = ceil((double)EXP1 * 1.12);
            EXP2 = ceil((double)EXP2 * 1.12);
            HP1 = ceil((double)HP1 * 1.1);
            HP2 = ceil((double)HP2 * 1.1);
            h = e;
        }
        if (EXP1 > 600) { EXP1 = 600; };
        if (EXP1 < 0) { EXP1 = 0; };
        if (HP1 > 666) { HP1 = 666; };
        if (HP1 < 0) { HP1 = 0; };
        if (EXP2 > 600) { EXP2 = 600; };
        if (EXP2 < 0) { EXP2 = 0; };
        if (HP2 > 666) { HP2 = 666; };
        if (HP2 < 0) { HP2 = 0; };
    }

    return h;
}


// Task 4
int checkPassword(const char* s, const char* email)
{
    string pass = s;
    string mail = email;
    int i = 0;
    string se = "";
    while (mail[i] != '@') {
        se.push_back(mail[i]);
        i++;
    }
    if (pass.length() < 8) return -1;
    if (pass.length() > 20) return -2;
    for (int i = 0; i <= pass.length() - ((se.length() > 3) ? 3 : se.length()); i++) {
        if (se == pass.substr(i, se.length())) return -(300 + i);
        if (pass[i] == pass[i + 1] && pass[i] == pass[i + 2]) return -(400 + i);
    }
    for (int a = 0; a < pass.length(); a++) {
        if (pass[a] == '@' || pass[a] == '#' || pass[a] == '!' || pass[a] == '$' || pass[a] == '%') {
            goto start;
        }
    }
    return -5;
start:
    return -10;
}
    // Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int a[30], d;
    for (int i = 0; i < num_pwds; i++) {
        a[i] = 0;
    }
    for (int i = 0; i < num_pwds; i++) {
        for (int j = 0; j < num_pwds; j++) {
            if (arr_pwds[i] == arr_pwds[j]) {
                a[i]++;
            }
        }
    }
    int b = a[0];
    for (int i = 1; i < num_pwds; i++) {
        if (a[i] > b) {
            b = a[i];
        }
    }
    int c = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (a[i] == b) {
            if (strlen(arr_pwds[i]) > c) {
                d = i;
                c = strlen(arr_pwds[i]);
            }
        }
    }
    return d;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////