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
        if (exp2 > 600) { exp2 = 600; }
        if (exp2 < 0) { exp2 = 0; }
        if (exp1 > 600) { exp1 = 600; }
        if (exp1 < 0) { exp1 = 0; }
        if (e1 >= 0 && e1 <= 3) {
            if (e1 == 0) { exp2 += 29; }
            else if (e1 == 1) { exp2 += 45; }
            else if (e1 == 2) { exp2 += 75; }
            else if (e1 == 3) { exp2 += 149; }
            int D;
            D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0) { exp1 = ceil(exp1 + (D / float(200))); }
            else if (D % 2 != 0) { exp1 = ceil(exp1 - (D / float(100))); }
        }
        else if (e1 >= 4 && e1 <= 99) {
            if (e1 >= 4 && e1 <= 19) { exp2 = ceil(exp2 + e1 / float(4) + 19); }
            else if (e1 >= 20 && e1 <= 49) { exp2 = ceil(exp2 + e1 / float(9) + 21); }
            else if (e1 >= 50 && e1 <= 65) { exp2 = ceil(exp2 + e1 / float(16) + 17); }
            else if (e1 >= 66 && e1 <= 79) {
                exp2 = ceil(exp2 + e1 / float(4) + 19);
                if (exp2 > 200) { exp2 = ceil(exp2 + e1 / float(9) + 21); }
            }
            else if (e1 >= 80 && e1 <= 99) {
                exp2 = ceil(exp2 + e1 / float(4) + 19);
                exp2 = ceil(exp2 + e1 / float(9) + 21);
                if (exp2 > 400) {
                    exp2 = ceil(exp2 + e1 / float(16) + 17);
                    exp2 = ceil(exp2 * 1.15);
                }
            }
            exp1 -= e1;
        }
        if (exp2 > 600) { exp2 = 600; }
        if (exp2 < 0) { exp2 = 0; }
        if (exp1 > 600) { exp1 = 600; }
        if (exp1 < 0) { exp1 = 0; }
        return exp1 + exp2;
    }
    else {
        e1 = -99;
        return e1;
    }
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 >= 0 && E2 <= 99) {
        if (HP1 > 666) { HP1 = 666; }
        if (HP1 < 0) { HP1 = 0; }
        if (EXP1 > 600) { EXP1 = 600; }
        if (EXP1 < 0) { EXP1 = 0; }
        if (M1 > 3000) { M1 = 3000; }
        if (M1 < 0) { M1 = 0; }
        int S, i;
        S = round(sqrt(EXP1)) * round(sqrt(EXP1));
        float P1;
        if (EXP1 >= S) { P1 = 100; }
        else { P1 = (EXP1 / float(S) + 80) / 123 * 100; }
        if (E2 % 2 != 0) {
            float halfthebugget = M1 / float(2);
            while (M1 >= halfthebugget) {
                if (M1 <= 0) {
                    M1 = 0;
                    break;
                }
                if (HP1 < 200) {
                    M1 -= 150;
                    HP1 = ceil(HP1 + HP1 * 0.3);
                }
                else {
                    M1 -= 70;
                    HP1 = ceil(HP1 + HP1 * 0.1);
                }
                if (HP1 > 666) { HP1 = 666; }
                if (HP1 < 0) { HP1 = 0; }
                if (M1 < halfthebugget) { break; }
                if (EXP1 < 400) { M1 -= 200; }
                else {
                    M1 -= 120;
                }
                EXP1 = ceil(EXP1 * 1.13);
                if (EXP1 > 600) { EXP1 = 600; }
                if (M1 < halfthebugget) { break; }
                if (EXP1 < 300) { M1 -= 100; }
                else {
                    M1 -= 120;
                }
                EXP1 = ceil(EXP1 * 0.9);
            }
            if (M1 < 0) { M1 = 0; }
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            if (EXP1 > 600) { EXP1 = 600; }
        }
        else {
            for (i = 1; i == 1; i++) {
                if (M1 <= 0) {
                    M1 = 0;
                    break;
                }
                if (HP1 < 200) {
                    M1 -= 150;
                    HP1 = ceil(HP1 + HP1 * 0.3);
                }
                else {
                    M1 -= 70;
                    HP1 = ceil(HP1 + HP1 * 0.1);
                }
                if (HP1 > 666) { HP1 = 666; }
                if (HP1 < 0) { HP1 = 0; }
                if (M1 <= 0) {
                    M1 = 0;
                    break;
                }
                if (EXP1 < 400) { M1 -= 200; }
                else {
                    M1 -= 120;
                }
                EXP1 = ceil(EXP1 * 1.13);
                if (EXP1 > 600) { EXP1 = 600; }
                if (M1 <= 0) {
                    M1 = 0;
                    break;
                }
                if (EXP1 < 300) { M1 -= 100; }
                else {
                    M1 -= 120;
                }
                EXP1 = ceil(EXP1 * 0.9);
            }
            if (M1 < 0) { M1 = 0; }
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            if (EXP1 > 600) { EXP1 = 600; }
        }
        S = round(sqrt(EXP1)) * round(sqrt(EXP1));
        float P2;
        if (EXP1 >= S) { P2 = 100; }
        else { P2 = (EXP1 / float(S) + 80) / 123 * 100; }
        int P3;
        int P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        if (E2 >= 0 && E2 < 10) { P3 = P[E2]; }
        else {
            int i;
            i = (E2 % 10 + E2 / 10) % 10;
            P3 = P[i];
        }
        if (P1 == P2 && P2 == P3 && P3 == 100) { EXP1 = ceil(EXP1 * 0.75); }
        else if ((P1 + P2 + P3) / 3 < 50) {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        }
        else if ((P1 + P2 + P3) / 3 >= 50) {
            EXP1 = ceil(EXP1 * 1.2);
            HP1 = ceil(HP1 * 0.9);
        }
        if (HP1 > 666) { HP1 = 666; }
        if (HP1 < 0) { HP1 = 0; }
        if (EXP1 > 600) { EXP1 = 600; }
        if (EXP1 < 0) { EXP1 = 0; }
        return HP1 + EXP1 + M1;
    }
    else {
        E2 = -99;
        return E2;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 >= 0 && E3 <= 99) {
        int Taxi[10][10], i, j, Detective[10][10], v = 0, g = 0;
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                Taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                if (Taxi[i][j] > E3 * 2) {
                    v++;
                }
                if (Taxi[i][j] < -E3) {
                    g++;
                }
                while (v > 9) { v = (v / 10 + v % 10)%10; }
                while (g > 9) { g = (g / 10 + g % 10)%10; }
            }
        }
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                int u = i, x = j, Maxupleft = Taxi[i][j], Maxdownright = Taxi[i][j], Maxupright = Taxi[i][j], Maxdownleft = Taxi[i][j], Max = 0;
                while (u > 0 && x > 0) {
                    u--; x--;
                    if (Taxi[u][x] > Maxupleft) {
                        Maxupleft = Taxi[u][x];
                    }
                }
                u = i, x = j;
                while (u < 9 && x < 9) {
                    u++; x++;
                    if (Taxi[u][x] > Maxdownright) {
                        Maxdownright = Taxi[u][x];
                    }
                }
                u = i, x = j;
                while (x < 9) {
                    u--; x++;
                    if (Taxi[u][x] > Maxupright) {
                        Maxupright = Taxi[u][x];
                    }
                }
                u = i, x = j;
                while (u < 9) {
                    u++; x--;
                    if (Taxi[u][x] > Maxdownleft) {
                        Maxdownleft = Taxi[u][x];
                    }
                }
                Max = Maxupleft;
                if (Maxdownright > Max) { Max = Maxdownright; }
                if (Maxupright > Max) { Max = Maxupright; }
                if (Maxdownleft > Max) { Max = Maxdownleft; }
                Detective[i][j] = abs(Max);
            }
        }
        int b;
        if (abs(Taxi[v][g]) > Detective[v][g]) {
            EXP1 = ceil(EXP1 * 0.88);
            HP1 = ceil(HP1 * 0.9);
            EXP2 = ceil(EXP2 * 0.88);
            HP2 = ceil(HP2 * 0.9);
            b = Taxi[v][g];
        }
        else {
            EXP1 = ceil(EXP1 * 1.12);
            HP1 = ceil(HP1 * 1.1);
            EXP2 = ceil(EXP2 * 1.12);
            HP2 = ceil(HP2 * 1.1);
            b = Detective[v][g];
        }
        if (HP1 > 666) { HP1 = 666; }
        if (EXP1 > 600) { EXP1 = 600; }
        if (HP2 > 666) { HP2 = 666; }
        if (EXP2 > 600) { EXP2 = 600; }
        return b;
    }
    else {
        E3 = -99;
        return E3;
    }
}

// Task 4
int checkPassword(const char* s, const char* email) {
    const char* atSignPosition = strchr(email, '@');
    char se[101];
    strncpy(se, email, atSignPosition - email);
    se[atSignPosition - email] = '\0';
    const char* sePosition = strstr(s, se);
    if (sePosition) return -(300 + (sePosition - s));

    int length = strlen(s);
    if (length < 8) return -1;
    if (length > 20) return -2;

    bool hasSpecialCharacter = false;
    const char* specialCharacters = "@#%$!";
    for (int i = 0; i < length; ++i) {
        if (strchr(specialCharacters, s[i])) {
            hasSpecialCharacter = true;
            break;
        }
    }
    if (!hasSpecialCharacter) return -5;

    for (int i = 0; i < length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) return -(400 + i);
    }

    for (int i = 0; i < length; ++i) {
        if (!(isdigit(s[i]) || islower(s[i]) || isupper(s[i]) || strchr(specialCharacters, s[i]))) {
            return i;
        }
    }

    return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int max_count = 0;
    int max_index = -1; 

    for (int i = 0; i < num_pwds; ++i) {
        int count = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[j], arr_pwds[i]) == 0) { 
                ++count;
            }
        }

        if (count > max_count || (count == max_count && strlen(arr_pwds[i]) > strlen(arr_pwds[max_index]))) {
            max_count = count;
            max_index = i;
        }
    }

    return max_index;
    return -1;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////