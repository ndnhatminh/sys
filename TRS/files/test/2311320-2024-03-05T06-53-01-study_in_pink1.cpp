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
    if (e1 < 4)
    {
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
            exp2 += (29 + 45 + 75);
            break;

        }
        int D;
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = ceil(exp1 + (D / float(200)));
        }
        else { 
            exp1 = ceil(exp1 - (D / float(100)));
        }

    }
    if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 = ceil(exp2 + (e1 / float(4) + 19));
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 = ceil(exp2 + (e1 / float(9) + 21));
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 = ceil(exp2 +(e1 / float(16) + 17));
        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = ceil(exp2 + (e1 / float(4) + 19));
            if (exp2 > 200) {
            exp2 = ceil(exp2 + (e1 / float(9) + 21));
            }
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 = ceil(exp2 + (e1 / float(4) + 19));
            exp2 = ceil(exp2 + (e1 / float(9) + 21));
            if (exp2 > 400) {
            exp2 = ceil(exp2 + (e1 / float(16) + 17));
            exp2 = ceil(exp2 * 1.15);
            }

        }
        exp1 -= e1;
    }
    if (exp1 > 600) {
        exp1 = 600;
    }
    if (exp2 > 600) {
        exp2 = 600;
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    //road 1:
    int S;
    S = round(sqrt(EXP1)) * round(sqrt(EXP1));
    double P1;
    if (EXP1 >= S) {
        P1 = 1;
    }
    else
        P1 = (static_cast<double>(EXP1) / S + 80) / 123;
    //road 2:
    if (E2 % 2 != 0) {
        int HalfM1 = M1 / 2;
        while (M1 >= HalfM1) {

            if (HP1 < 200) {
                HP1 = ceil(HP1 * 1.3);
                M1 -= 150;
            }
            else {
                HP1 = ceil(HP1 * 1.1);
                M1 -= 70;
            }

            if (M1 < HalfM1) {
                break;
            }

            if (EXP1 < 400) {
                M1 -= 200;
                EXP1 = ceil(EXP1 * 1.13);
            }
            else {
                M1 -= 120;
                EXP1 = ceil(EXP1 * 1.13);
            }

            if (M1 < HalfM1) {
                break;
            }
            if (EXP1 < 300) {
                M1 -= 100;
                EXP1 = ceil(EXP1 * 0.9);
            }
            else {
                M1 -= 120;
                EXP1 = ceil(EXP1 * 0.9);
            }

        }
        HP1 = ceil(HP1 * 0.83);
        EXP1 = ceil(EXP1 * 1.17);
    }
    else
    {
        if (HP1 < 200) {
            HP1 = ceil(HP1 * 1.3);
            M1 -= 150;
        }
        else {
            HP1 = ceil(HP1 * 1.1);
            M1 -= 70;
        }
        if (M1 <= 0) {
            M1 = 0;
            goto stop;
        }
        if (EXP1 < 400) {
            M1 -= 200;
            EXP1 = ceil(EXP1 * 1.13);
        }
        else {
            M1 -= 120;
            EXP1 = ceil(EXP1 * 1.13);
        }
        if (M1 <= 0) {
            M1 = 0;
            goto stop;
        }
        if (EXP1 < 300) {
            M1 -= 100;
        }
        else {
            M1 -= 120;
        }
        EXP1 = ceil(EXP1 * 0.9);
    stop:;
        HP1 = ceil(HP1 * 0.83);
        EXP1 = ceil(EXP1 * 1.17);

    }
    double P2;
    if (EXP1 >= S) {
        P2 = 1;
    }
    else {
        P2 = (static_cast<double>(EXP1) / S + 80) / 123;
    }
    //road 3:
    double P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i;
    if (E2 < 10) {
        i = E2;
    }
    else {
        i = (E2 / 10 + E2 % 10) % 10;
    }


    double P3 = static_cast<double>(P[i]) / 100.0;
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = ceil(EXP1 * 0.75);
    }


    if (((P1 + P2 + P3) / 3.0) < 0.5) {
        HP1 = ceil(HP1 * 0.85);
        EXP1 = ceil(EXP1 * 1.15);
    }
    else {
        HP1 = ceil(HP1 * 0.9);
        EXP1 = ceil(EXP1 * 1.2);
    }
    if (HP1 < 0) {
        HP1 = 0;
    }
    if (HP1 > 666) {
        HP1 = 666;
    }
    if (EXP1 < 0) {
        EXP1 = 0;
    }
    if (EXP1 > 600) {
        EXP1 = 600;
    }
    if (M1 < 0) {
        M1 = 0;
    }
    if (M1 > 3000) {
        M1 = 3000;
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    int taxi[10][10] = { 0 };
    int SherlockandWatson[10][10] = { 0 };
    int a = 0, b = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taxi[i][j] > E3 * 2) { a++; }
            if (taxi[i][j] < -E3) { b++; }
        }
    }
    while (a > 9) { a = a % 10 + a / 10; }
    while (b > 9) { b = b % 10 + b / 10; }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int m = i, n = j, max = 0, e = taxi[i][j], f = taxi[i][j], g = taxi[i][j], h = taxi[i][j];
            while (m > 0 && n > 0) {
                m--;
                n--;
                if (taxi[m][n] > e) {
                    e = taxi[m][n];
                }
            }
            m = i, n = j;
            while (m < 9 && n < 9) {
                m++;
                n++;
                if (taxi[m][n] > f) {
                    f = taxi[m][n];
                }
            }
            m = i, n = j;
            while (n < 9) {
                m--;
                n++;
                if (taxi[m][n] > g) {
                    g = taxi[m][n];
                }
            }
            m = i, n = j;
            while (m < 9) {
                m++;
                n--;
                if (taxi[m][n] > h) {
                    h = taxi[m][n];
                }
            }
            max = e;
            if (max < f) { max = f; }
            if (max < g) { max = g; }
            if (max < h) { max = h; }
            SherlockandWatson[i][j] = abs(max);
        }
    }
    int Bigger;
    if (abs(taxi[a][b]) > SherlockandWatson[a][b]) {
        EXP1 = ceil(EXP1 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        EXP2 = ceil(EXP2 * 0.88);
        HP2 = ceil(HP2 * 0.9);
        Bigger = taxi[a][b];
    }
    else {
        EXP1 = ceil(EXP1 * 1.12);
        HP1 = ceil(HP1 * 1.1);
        EXP2 = ceil(EXP2 * 1.12);
        HP2 = ceil(HP2 * 1.1);
        Bigger = SherlockandWatson[a][b];
    }
    return Bigger;
    return -1;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    const char* atSignPosition = strchr(email, '@');

    char se[101];
    strncpy(se, email, atSignPosition - email);
    se[atSignPosition - email] = '\0';

    int length = strlen(s);
    if (length < 8) return -1;
    if (length > 20) return -2;

    const char* sePosition = strstr(s, se);
    if (sePosition) return -(300 + (sePosition - s));



    bool hasSpecialCharacter = false;
    const char* specialCharacters = "@#%$!";
    for (int i = 0; i < length; ++i) {
        if (strchr(specialCharacters, s[i])) {
            hasSpecialCharacter = true;
            break;
        }
    }


    for (int i = 0; i < length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) return -(400 + i);
    }
    if (!hasSpecialCharacter) return -5;

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