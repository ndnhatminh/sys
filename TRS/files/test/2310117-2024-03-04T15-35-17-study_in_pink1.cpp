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

// Tam vuc
int scopeHP(int hp) {
    if (hp < 0) hp = 0;
    else if (hp > 666) hp = 666;
    return hp;
}
int scopeEXP(int exp) {
    if (exp < 0) exp = 0;
    else if (exp > 600) exp = 600;
    return exp;
}
int scopeM(int m) {
    if (m < 0) m = 0;
    else if (m > 3000) m = 3000;
    return m;
}
// So chinh phuong gan nhat
int scpgn(int EXP) {
    int b = ceil(sqrt(EXP)); int a;
    a = b - 1;
    if (abs(EXP - a * a) < abs(EXP - b * b)) return a * a;
    else return (b * b);
}

int roundup(double num) {
    num = int(num + 0.999999);
    return num;
}

int findMax(int matran[10][10], int a, int b) {
    int arr[100];
    int n = 0;
    int a1 = a, a2 = a, a3 = a, a4 = a;
    int b1 = b, b2 = b, b3 = b, b4 = b;
    while (a1 >= 0 && b1 >= 0) {
        arr[n] = matran[a1][b1];
        a1 -= 1; b1 -= 1; n += 1;
    }
    while (a2 >= 0 && b2 <= 9) {
        arr[n] = matran[a2][b2];
        a2 -= 1; b2 += 1; n += 1;
    }
    while (a3 <= 9 && b3 >= 0) {
        arr[n] = matran[a3][b3];
        a3 += 1; b3 -= 1; n += 1;
    }
    while (a4 <= 9 && b4 <= 9) {
        arr[n] = matran[a4][b4];
        a4 += 1; b4 += 1; n += 1;
    }
    int z = arr[0];
    for (int t = 1; t < n; t++) {
        if (z < arr[t]) z = arr[t];
    }
    return z;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    exp1 = scopeEXP(exp1);
    exp2 = scopeEXP(exp2);
    if (e1 >= 0 && e1 <= 99) {
        if (e1 >= 0 && e1 <= 3) {
            if (e1 == 0) exp2 += 29;
            else if (e1 == 1) exp2 += 45;
            else if (e1 == 2) exp2 += 75;
            else exp2 += (29 + 45 + 75);
            exp2 = scopeEXP(exp2);
            int D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0) exp1 = roundup(exp1 + ((double)D / 200));
            else exp1 = roundup(exp1 - ((double)D / 100));
            exp1 = scopeEXP(exp1);
        }
        else if (e1 >= 4 && e1 <= 99) {
            if (e1 >= 4 && e1 <= 19) exp2 = scopeEXP(roundup(exp2 + ((double)e1 / 4 + 19)));
            else if (e1 >= 20 && e1 <= 49) exp2 = scopeEXP(roundup(exp2 + ((double)e1 / 9 + 21)));
            else if (e1 >= 50 && e1 <= 65) exp2 = scopeEXP(roundup(exp2 + ((double)e1 / 16 + 17)));
            else if (e1 >= 66 && e1 <= 79) {
                exp2 = scopeEXP(roundup(exp2 + ((double)e1 / 4 + 19)));
                if (exp2 > 200) exp2 = scopeEXP(roundup(exp2 + ((double)e1 / 9 + 21)));
            }
            else if (e1 >= 80 && e1 <= 99) {
                exp2 = scopeEXP(roundup(exp2 + ((double)e1 / 4 + 19)));
                exp2 = scopeEXP(roundup(exp2 + ((double)e1 / 9 + 21)));
                if (exp2 > 400) {
                    exp2 = scopeEXP(roundup(exp2 + ((double)e1 / 16 + 17)));
                    exp2 = scopeEXP(roundup(exp2 * 1.15));
                }
                
            }
            exp1 = scopeEXP(exp1 - e1);
        }
        return exp1 + exp2;
    }
    else return -99;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    HP1 = scopeHP(HP1);
    EXP1 = scopeEXP(EXP1);
    M1 = scopeM(M1);
    if (E2 >= 0 && E2 <= 99) {
        double P1, P2, P3, P;
        //duong 1
        int S = scpgn(EXP1);
        if (EXP1 >= S) P1 = 1;
        else P1 = (((double)EXP1 / S + 80) / 123);
        //duong 2
        double half = M1 / 2;
        while (E2 % 2 == 1)  {
            if (HP1 < 200) {
                HP1 = scopeHP(roundup(HP1 * 1.3));
                M1 = scopeM(M1 - 150);
                if (M1 < half) {                    
                    break;
                }
            }
            else {
                HP1 = scopeHP(roundup(HP1 * 1.1));
                M1 = scopeM(M1 - 70);
                if (M1 < half) {
                    break;
                }
            }
            if (EXP1 < 400) {
                M1 = scopeM(M1 - 200);
                EXP1 = scopeHP(roundup(EXP1 * 1.13));
                if (M1 < half) {
                    break;
                }
            }
            else {
                M1 = scopeM(M1 - 120);
                EXP1 = scopeHP(roundup(EXP1 * 1.13));
                if (M1 < half) {
                    break;
                }
            }
            if (EXP1 < 300) {
                M1 = scopeM(M1 - 100);
                EXP1 = scopeHP(roundup(EXP1 * 0.9));
                if (M1 < half) {
                    break;
                }
            }
            else {
                M1 = scopeM(M1 - 120);
                EXP1 = scopeHP(roundup(EXP1 * 0.9));
                if (M1 < half) {
                    break;
                }
            }
        }
        if (E2 % 2 == 0) {
            if (HP1 < 200) {
                HP1 = scopeHP(roundup(HP1 * 1.3));
                M1 = scopeM(M1 - 150);
                if (M1 == 0) goto label;
            }
            else {
                HP1 = scopeHP(roundup(HP1 * 1.1));
                M1 = scopeM(M1 - 70);
                if (M1 == 0) goto label;
            }
            if (EXP1 < 400) {
                M1 = scopeM(M1 - 200);
                EXP1 = scopeHP(roundup(EXP1 * 1.13));
                if (M1 == 0) goto label;
            }
            else {
                M1 = scopeM(M1 - 120);
                EXP1 = scopeHP(roundup(EXP1 * 1.13));
                if (M1 == 0) goto label;
            }
            if (EXP1 < 300) {
                M1 = scopeM(M1 - 100);
                EXP1 = scopeHP(roundup(EXP1 * 0.9));
                if (M1 == 0) goto label;
            }
            else {
                M1 = scopeM(M1 - 120);
                EXP1 = scopeHP(roundup(EXP1 * 0.9));
                if (M1 == 0) goto label;
            }
        }
        label:
        HP1 = scopeHP(roundup(HP1 * 0.83));
        EXP1 = scopeHP(roundup(EXP1 * 1.17));
        S = scpgn(EXP1);
        if (EXP1 >= S) P2 = 1;
        else P2 = (((double)EXP1 / S + 80) / 123);
        //duong 3
        int p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int hchuc = E2 / 10; int hdv = E2 % 10;
        int i = (hchuc + hdv) % 10;
        P3 = (double)p[i]/100;
        //buoccuoi
        if (P1 == 1 && P2 == 1 && P3 == 1) EXP1 = scopeEXP(roundup(EXP1 * 0.75));
        else { 
            P = (P1 + P2 + P3) / 3;
            if (P < 0.5) { 
                HP1 = scopeHP(roundup(HP1 * 0.85));
                EXP1 = scopeEXP(roundup(EXP1 * 1.15));
            }
            else {
                HP1 = scopeHP(roundup(HP1 * 0.9));
                EXP1 = scopeEXP(roundup(EXP1 * 1.2));
            }
        }
        return HP1 + EXP1 + M1;
    }
    else return -99;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    HP1 = scopeHP(HP1);
    EXP1 = scopeEXP(EXP1);
    HP2 = scopeHP(HP2);
    EXP2 = scopeEXP(EXP2);
    if (E3 >= 0 && E3 <= 99) {
        int matran[10][10];
        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                matran[x][y] = ((E3 * y) + (x * 2)) * (x - y);
            }
        }
        int i = 0, j = 0, diemtaxi, diemholmes, trave;
        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                if (matran[x][y] > (E3 * 2)) i += 1;
                else if (matran[x][y] < (-E3)) j += 1;
            }
        }
        while (i > 9) i = (i / 10) + (i % 10);
        while (j > 9) j = (j / 10) + (j % 10);
        diemtaxi = matran[i][j] ;
        diemholmes = abs(findMax(matran, i, j));
        if (abs(diemtaxi) > diemholmes) {
            EXP1 = scopeEXP(roundup(EXP1 * 0.88));
            EXP2 = scopeEXP(roundup(EXP2 * 0.88));
            HP1 = scopeHP(roundup(HP1 * 0.9));
            HP2 = scopeHP(roundup(HP2 * 0.9));
            trave = diemtaxi;
        }
        else {
            EXP1 = scopeEXP(roundup(EXP1 * 1.12));
            EXP2 = scopeEXP(roundup(EXP2 * 1.12));
            HP1 = scopeHP(roundup(HP1 * 1.1));
            HP2 = scopeHP(roundup(HP2 * 1.1));
            trave = diemholmes;
        }
        return trave;
    }
    else return -99;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int trave = -10;
    int emlen = strlen(email);
    int slen = strlen(s);
    string p = s;
    string em = email;
    int i = 0;
    for (i = 0; i < emlen; i++) {
        if (em.substr(i, 1) == "@") break;
    }
    string se(email, 0, i);
    int e = p.find(se);
    int j = 0;
    int sc1 = p.find("@");
    int sc2 = p.find("#");
    int sc3 = p.find("%");
    int sc4 = p.find("$");
    int sc5 = p.find("!");

    if (slen < 8) {
        trave = -1; goto label;
    }
    if (slen > 20) {
        trave = -2; goto label;
    }

    if (e >= 0 && e < slen) { trave = -(300 + e); goto label; }

    while (j < strlen(s)-2) {
        if (s[j] == s[j + 1] && s[j] == s[j + 2]) break;
        else j += 1;
    }
    if (j < slen - 2) {
        trave = -(400 + j);
        goto label;
    }

    if (sc1 < 0 && sc2 < 0 && sc3 < 0 && sc4 < 0 && sc5 < 0) trave = -5;
    
    for (int k = 0; k < strlen(s); k++) {
        if (p.substr(k, 1) == "`" || p.substr(k, 1) == "~" || p.substr(k, 1) == "$" || p.substr(k, 1) == "^" ||
            p.substr(k, 1) == "*" || p.substr(k, 1) == "(" || p.substr(k, 1) == ")" || p.substr(k, 1) == "-" ||
            p.substr(k, 1) == "_" || p.substr(k, 1) == "=" || p.substr(k, 1) == "+" || p.substr(k, 1) == "[" ||
            p.substr(k, 1) == "]" || p.substr(k, 1) == "{" || p.substr(k, 1) == "}" || p.substr(k, 1) == "\\" ||
            p.substr(k, 1) == "|" || p.substr(k, 1) == ";" || p.substr(k, 1) == ":" || p.substr(k, 1) == "'" ||
            p.substr(k, 1) == "," || p.substr(k, 1) == "." || p.substr(k, 1) == "/" || p.substr(k, 1) == "<" ||
            p.substr(k, 1) == "<" || p.substr(k, 1) == ">" || p.substr(k, 1) == "?" || p.substr(k, 1) == "\"" || p.substr(k, 1) == " ") {
            trave = k;
            goto label;
        }
    }
    label:
    return trave;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int trave = 0;
    int demmax = 0;
    string mode[num_pwds];
    for (int i = 0; i < (num_pwds-1); i++) {
        int cnt = 1;
        for (int j = i + 1; j < num_pwds; j++) {
            if (arr_pwds[i] == arr_pwds[j]) cnt += 1;
        }
        if (demmax < cnt) {
            demmax = cnt;
        }
    }
    for (int i = 0; i < (num_pwds-1); i++) {
        int cnt = 1;
        for (int j = i + 1; j < num_pwds; j++) {
            if (arr_pwds[i] == arr_pwds[j]) cnt += 1;
        }
        if (demmax == cnt) {
            mode[i] = arr_pwds[i];
        }
    }
    int b = mode[0].length();
    for (int a = 0; a < num_pwds; a++) {
        if (b < mode[a].length()) trave = a;
    }
    return trave;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////