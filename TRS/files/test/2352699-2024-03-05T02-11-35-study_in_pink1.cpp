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
bool setE1(int& E1) {
    if (E1 < 0 || E1 > 99) {
        return true;
    }
    else {
        return false;
    }
}
bool setE2(int& E2) {
    if (E2 < 0 || E2>99) {
        return true;
    }
    else {
        return false;
    }
}
bool setE3(int& E3) {
    if (E3 < 0 || E3>99) {
        return true;
    }
    else {
        return false;
    }
}
void setEXP1(int& EXP1) {
    if (EXP1 < 0) {
        EXP1 = 0;
    }
    if (EXP1 > 600) {
        EXP1 = 600;
    }
}
void setEXP2(int& EXP2) {
    if (EXP2 < 0) {
        EXP2 = 0;
    }
    if (EXP2 > 600) {
        EXP2 = 600;
    }
}
int roundint(double a) {
    if (a >= 0) {
        return (int)(a + 0.9999999999);
    }
    else {
        return (int)a;
    }
}
int firstMeet(int & exp1, int & exp2, int e1) {
    if (setE1(e1)) {
        return -99;
    }
    else {
        if (0 <= e1 && e1 <= 3) {
            if (e1 == 0) {
                exp2 = exp2 + 29;
            }
            else if (e1 == 1) {
                exp2 = exp2 + 45;
            }
            else if (e1 == 2) {
                exp2 = exp2 + 75;
            }
            else {
                exp2 = exp2 + 29 + 45 + 75;
            }
            setEXP2(exp2);
            int D;
            D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0) {
                exp1 = roundint(exp1 + D / 200.0);
            }
            else {
                exp1 = roundint(exp1 - D / 100.0);
            }
            setEXP1(exp1);
        }
        else if (e1 >= 4 && e1 <= 99) {
            if (e1 <= 19) {
                exp2 = roundint(exp2 + e1 / 4.0 + 19);
            }
            else if (e1 >= 20 && e1 <= 49) {
                exp2 = roundint(exp2 + e1 / 9.0 + 21);
            }
            else if (e1 >= 50 && e1 <= 65) {
                exp2 = roundint(exp2 + e1 / 16.0 + 17);
            }
            else if (e1 >= 66 && e1 <= 79) {
                exp2 = roundint(exp2 + e1 / 4.0 + 19);
                setEXP2(exp2);
                if (exp2 > 200) {
                    exp2 = roundint(exp2 + e1 / 9.0 + 21);
                    setEXP2(exp2);
                }
            }
            else if (e1 >= 80 && e1 <= 99) {
                exp2 = roundint(exp2 + e1 / 4.0 + 19);
                setEXP2(exp2);
                exp2 = roundint(exp2 + e1 / 9.0 + 21);
                setEXP2(exp2);
                if (exp2 > 400) {
                    exp2 = roundint(exp2 + e1 / 16.0 + 17);
                    setEXP2(exp2);
                    exp2 = roundint(exp2 * 1.15);
                    setEXP2(exp2);
                }
            }
            setEXP2(exp2);
            exp1 = exp1 - e1;
        }
            setEXP1(exp1);
            setEXP2(exp2);
        return exp1 + exp2;
    }
}

// Task 2
void setHP1(int& HP1) {
    if (HP1 < 0) {
        HP1 = 0;
    }
    if (HP1 > 666) {
        HP1 = 666;
    }
}
void setHP2(int& HP2) {
    if (HP2 < 0) {
        HP2 = 0;
    }
    if (HP2 > 666) {
        HP2 = 666;
    }
}
void setM(int &M1) {
    if (M1 < 0) {
        M1 = 0;
    }
    if (M1 > 3000) {
        M1 = 3000;
    }
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    int S;
    float P1;
    if (setE2(E2)) {
        return -99;
    }
    else {
        for (int i = 0; i <= sqrt(EXP1); i++) {
            if ((float)i == sqrt(EXP1)) {
                S = i * i;
                P1 = 100.0;
            }
            else if ((i + 1) > sqrt(EXP1)) {
                if ((EXP1 - (i * i)) < ((i + 1) * (i + 1) - EXP1)) {
                    P1 = 100.0;
                    S = i * i;
                }
                else {
                    S = (i + 1) * (i + 1);
                    P1 = ((EXP1 / (float)S) + 80) / 123.0 * 100;
                }

            }
        }
        int sum = 0;
        double m = 0.5 * M1;
        if (E2 % 2 != 0) {
            while (E2 % 2 != 0) {
                if (HP1 < 200) {
                    HP1 = roundint(HP1 * 1.30);
                    sum = sum + 150;
                    M1 = M1 - 150;
                }
                else if (HP1 >= 200) {
                    HP1 = roundint(HP1 * 1.10);
                    sum = sum + 70;
                    M1 = M1 - 70;
                }
                setHP1(HP1);
                setM(M1);
                if (sum > m) {
                    break;
                }
                else {
                    if (EXP1 < 400) {
                        EXP1 = roundint(EXP1 * 1.13);
                        sum = sum + 200;
                        M1 = M1 - 200;
                    }
                    else if (EXP1 >= 400) {
                        EXP1 = roundint(EXP1 * 1.13);
                        sum = sum + 120;
                        M1 = M1 - 120;
                    }
                    setEXP1(EXP1);
                    setM(M1);
                    if (sum > m) {
                        break;
                    }
                    else {
                        if (EXP1 < 300) {
                            EXP1 = roundint(EXP1 * 0.9);
                            sum = sum + 100;
                            M1 = M1 - 100;
                        }
                        else if (EXP1 >= 300) {
                            EXP1 = roundint(EXP1 * 0.9);
                            sum = sum + 120;
                            M1 = M1 - 120;
                        }
                        setEXP1(EXP1);
                        setM(M1);
                        if (sum > m) {
                            break;
                        }
                    }
                }
            }
            HP1 = roundint(HP1 * 0.83);
            EXP1 = roundint(EXP1 * 1.17);
            setHP1(HP1);
            setEXP1(EXP1);
        }
        else if (E2 % 2 == 0) {
            if (HP1 < 200) {
                HP1 = roundint(HP1 * 1.30);
                sum = sum + 150;
            }
            else if (HP1 >= 200) {
                HP1 = roundint(HP1 * 1.10);
                sum = sum + 70;
            }
            setHP1(HP1);
            setM(M1);
            if (sum >= M1) {
                M1 = 0;
                HP1 = roundint(HP1 * 0.83);
                EXP1 = roundint(EXP1 * 1.17);
                setHP1(HP1);
                setEXP1(EXP1);
            }
            else {
                if (EXP1 < 400) {
                    EXP1 = roundint(EXP1 * 1.13);
                    sum = sum + 200;
                }
                else if (EXP1 >= 400) {
                    EXP1 = roundint(EXP1 * 1.13);
                    sum = sum + 120;
                }
                setEXP1(EXP1);
                setM(M1);
                if (sum >= M1) {
                    M1 = 0;
                    HP1 = roundint(HP1 * 0.83);
                    EXP1 = roundint(EXP1 * 1.17);
                    setHP1(HP1);
                    setEXP1(EXP1);
                }
                else {
                    if (EXP1 < 300) {
                        EXP1 = roundint(EXP1 * 0.9);
                        sum = sum + 100;
                    }
                    else if (EXP1 >= 300) {
                        EXP1 = roundint(EXP1 * 0.9);
                        sum = sum + 120;
                    }
                    setEXP1(EXP1);
                    M1 = M1 - sum;
                    setM(M1);
                    HP1 = roundint(HP1 * 0.83);
                    EXP1 = roundint(EXP1 * 1.17);
                    setHP1(HP1);
                    setEXP1(EXP1);
                    setM(M1);
                }
            }
        }
        int S2;
        float P2;
        for (int i = 0; i <= sqrt(EXP1); i++) {
            if ((float)i == sqrt(EXP1)) {
                S2 = i * i;
                P2 = 100.0;
            }
            else if ((i + 1) > sqrt(EXP1)) {
                if ((EXP1 - (i * i)) < ((i + 1) * (i + 1) - EXP1)) {
                    P2 = 100.0;
                    S2 = i * i;
                }
                else {
                    S2 = (i + 1) * (i + 1);
                    P2 = ((EXP1 / (float)S2) + 80) / 123.0 * 100;
                }
            }
        }
        int a, P3;
        float SP;
        int P[10] = { 32,47,28,79,100,50,22,83,64,11 };
        if (E2 < 10) {
            a = E2;
            P3 = P[a];
        }
        else if (E2 >= 10) {
            a = E2 / 10 + (E2 % 10);
            a = a % 10;
            P3 = P[a];
        }
        if (P1 == 100 && P2 == 100 && P3 == 100) {
            EXP1 = roundint(EXP1 * 0.75);
        }
        else {
            SP = (P1 + P2 + P3) / 3.0;
            if (SP < 50) {
                HP1 = roundint(HP1 * 0.85);
                EXP1 = roundint(EXP1 * 1.15);
            }
            else if (SP >= 50) {
                HP1 = roundint(HP1 * 0.9);
                EXP1 = roundint(EXP1 * 1.2);
            }
        }
        setHP1(HP1);
        setEXP1(EXP1);
        setM(M1);
        return HP1 + EXP1 + M1;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (setE3(E3)) {
        return -99;
    }
    else {
        setE3(E3);
        setEXP1(EXP1);
        setEXP2(EXP2);
        setHP1(HP1);
        setHP2(HP2);
        int a = 0;
        int b = 0;
        int taxi, q, w, final;
        int max = 0;
        int map[10][10]{};
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                if (map[i][j] > (E3 * 2)) {
                    a = a + 1;
                }
                else if (map[i][j] < (-E3)) {
                    b = b + 1;
                }
            }
        }
        if (a < 10 && b < 10) {
            taxi = map[a][b];
            int q = a, e = a, z = a, c = a;
            int w = b, r = b, x = b, v = b;
            while (q <= 9 && w <= 9) {
                if (map[q][w] > max) {
                    max = map[q][w];
                }
                q++;
                w++;
            }
            while (e >= 0 && r >= 0) {
                if (map[e][r] > max) {
                    max = map[e][r];
                }
                e--;
                r--;
            }
            while (z >= 0 && x <= 9) {
                if (map[z][x] > max) {
                    max = map[z][x];
                }
                z--;
                x++;
            }
            while (c <= 9 && v >= 0) {
                if (map[c][v] > max) {
                    max = map[c][v];
                }
                c++;
                v--;
            }
            if (abs(taxi) > max) {
                EXP1 = roundint(EXP1 * 0.88);
                EXP2 = roundint(EXP2 * 0.88);
                HP1 = roundint(HP1 * 0.9);
                HP2 = roundint(HP2 * 0.9);
                final = taxi;
            }
            else {
                EXP1 = roundint(EXP1 * 1.12);
                EXP2 = roundint(EXP2 * 1.12);
                HP1 = roundint(HP1 * 1.1);
                HP2 = roundint(HP2 * 1.1);
                final = max;
            }
            setEXP1(EXP1);
            setEXP2(EXP2);
            setHP1(HP1);
            setHP2(HP2);
        }
        else {
            a = a / 10 + (a % 10);
            b = b / 10 + (b % 10);
            if (a < 10 && b < 10) {
                taxi = map[a][b];
                int q = a, e = a, z = a, c = a;
                int w = b, r = b, x = b, v = b;
                while (q <= 9 && w <= 9) {
                    if (map[q][w] > max) {
                        max = map[q][w];
                    }
                    q++;
                    w++;
                }
                while (e >= 0 && r >= 0) {
                    if (map[e][r] > max) {
                        max = map[e][r];
                    }
                    e--;
                    r--;
                }
                while (z >= 0 && x <= 9) {
                    if (map[z][x] > max) {
                        max = map[z][x];
                    }
                    z--;
                    x++;
                }
                while (c <= 9 && v >= 0) {
                    if (map[c][v] > max) {
                        max = map[c][v];
                    }
                    c++;
                    v--;
                }
                if (abs(taxi) > max) {
                    EXP1 = roundint(EXP1 * 0.88);
                    EXP2 = roundint(EXP2 * 0.88);
                    HP1 = roundint(HP1 * 0.9);
                    HP2 = roundint(HP2 * 0.9);
                    final = taxi;
                }
                else {
                    EXP1 = roundint(EXP1 * 1.12);
                    EXP2 = roundint(EXP2 * 1.12);
                    HP1 = roundint(HP1 * 1.1);
                    HP2 = roundint(HP2 * 1.1);
                    final = max;
                }
                setEXP1(EXP1);
                setEXP2(EXP2);
                setHP1(HP1);
                setHP2(HP2);
            }
            else {
                a = a / 10 + (a % 10);

                b = b / 10 + (b % 10);
                taxi = map[a][b];
                int q = a, e = a, z = a, c = a;
                int w = b, r = b, x = b, v = b;
                while (q <= 9 && w <= 9) {
                    if (map[q][w] > max) {
                        max = map[q][w];
                    }
                    q++;
                    w++;
                }
                while (e >= 0 && r >= 0) {
                    if (map[e][r] > max) {
                        max = map[e][r];
                    }
                    e--;
                    r--;
                }
                while (z >= 0 && x <= 9) {
                    if (map[z][x] > max) {
                        max = map[z][x];
                    }
                    z--;
                    x++;
                }
                while (c <= 9 && v >= 0) {
                    if (map[c][v] > max) {
                        max = map[c][v];
                    }
                    c++;
                    v--;
                }
                if (abs(taxi) > max) {
                    EXP1 = roundint(EXP1 * 0.88);
                    EXP2 = roundint(EXP2 * 0.88);
                    HP1 = roundint(HP1 * 0.9);
                    HP2 = roundint(HP2 * 0.9);
                    final = taxi;
                }
                else {
                    EXP1 = roundint(EXP1 * 1.12);
                    EXP2 = roundint(EXP2 * 1.12);
                    HP1 = roundint(HP1 * 1.1);
                    HP2 = roundint(HP2 * 1.1);
                    final = max;
                }
                setEXP1(EXP1);
                setEXP2(EXP2);
                setHP1(HP1);
                setHP2(HP2);
            }
        }
        return final;
    }
}

// Task 4
int checkPassword(const char* s, const char* email) {
    int y = 0;
    int b = 0;
    const char* domain = strrchr(email, '@');
    const int selength = strlen(email) - strlen(domain);
    char se[selength];
    strncpy(se, email, selength);
    se[selength] = '\0';
    if (strlen(s) >= 8 && strlen(s) <= 20) {
        const char* z = strstr(s, se);
        if (z) {
            int c = z - s;
            return -(300 + c);
        }
        else {
            for (int a = 0; a < strlen(s); a++) {
                if (s[a] == s[a + 1] && s[a + 1] == s[a + 2]) {
                    y = a;
                    return -(400 + y);
                }
            }
            for (int i = 0; i < strlen(s); i++) {
                if (s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%') {
                    b = b + 1;
                }
            }
            if (b == 0) {
                return -5;
            }
            else {
                for (int j = 0; j < strlen(s); j++) {
                    if (!isalnum(s[j]) && s[j] != '!' && s[j] != '@' && s[j] != '#' && s[j] != '$' && s[j] != '%') {
                        return j;
                    }
                }
                return -10;
            }
        }
    }
    else if (strlen(s) < 8) {
        return -1;
    }
    else {
        return -2;
    }
}

// Task 5
int mycount(const char* a[], int b, const char* c) {
    int count = 0;
    for (int i = 0; i < b; i++) {
        if (strcmp(a[i], c) == 0) {
            count++;
        }
    }
    return count;
}
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int max = 0;
    int a;
    size_t length;
    for (int i = 0; i < num_pwds; i++) {
        int passwordcount = mycount(arr_pwds, num_pwds, arr_pwds[i]);
        if (passwordcount > max) {
            max = passwordcount;
            a = i;
            length = strlen(arr_pwds[i]);
        }
        else if (passwordcount == max && strlen(arr_pwds[i]) > length) {
            max = passwordcount;
            a = i;
            length = strlen(arr_pwds[i]);
        }
    }
    return a;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////