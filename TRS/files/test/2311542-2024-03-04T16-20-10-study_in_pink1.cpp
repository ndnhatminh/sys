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
int fixE(int n) {
    int m = n;
    if (m > 99)  return -1;
    if (m < 0) return -1;
    return 0;
}
int fixHP(int n) {
    int m = n;
    if (m > 666) {
        m = 666;
        return m;
    }
    else if (m < 0) {
        m = 0;
        return m;
    }
    return m;
}
int fixEXP(int n) {
    int m = n;
    if (m > 600) {
        m = 600;
        return m;
    }
    else if (m < 0) {
        m = 0;
        return m;
    }
    return m;
}
int fixM(int n) {
    int m = n;
    if (m > 3000) {
        m = 3000;
        return m;
    }
    else if (m < 0) {
        m = 0;
        return m;
    }
    return m;
}
// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {
    // TODO: Complete this function
    if (fixE(E1) == -1) return -99;
    EXP1 = fixEXP(EXP1);
    EXP2 = fixEXP(EXP2);

    if (E1 >= 0 && E1 <= 3) {
        if (E1 == 0) EXP2 = fixEXP(EXP2 + 29);
        if (E1 == 1) EXP2 = fixEXP(EXP2 + 45);
        if (E1 == 2) EXP2 = fixEXP(EXP2 + 75);
        if (E1 == 3) EXP2 = fixEXP(EXP2 + 149);
        int D = (E1 * 3) + (EXP1 * 7);
        if ((D % 2) == 0) EXP1 = fixEXP(ceil(float(EXP1) + ceil(float(D) / 200.0))); else EXP1 = fixEXP(ceil(float(EXP1) - (float(D) / 100.0)));
    }
    if (E1 >= 4 && E1 <= 99) {
        if (E1 >= 4 && E1 <= 19) EXP2 = fixEXP(ceil(float(EXP2) + ceil(float(E1) / 4.0 + 19.0)));
        if (E1 >= 20 && E1 <= 49) EXP2 = fixEXP(ceil(float(EXP2) + ceil(float(E1) / 9.0 + 21.0)));
        if (E1 >= 50 && E1 <= 65) EXP2 = fixEXP(ceil(float(EXP2) + ceil(float(E1) / 16.0 + 17.0)));
        if (E1 >= 66 && E1 <= 79) {
            EXP2 = fixEXP(ceil(float(EXP2) + (float(E1) / 4.0 + 19.0)));
            if (EXP2 > 200) EXP2 = fixEXP(ceil(float(EXP2) + ceil(float(E1) / 9.0 + 21.0)));
        }
        if (E1 >= 80 && E1 <= 99) {
            EXP2 = fixEXP(ceil(float(EXP2) + ceil(float(E1) / 4.0 + 19.0) + ceil(float(E1) / 9.0 + 21.0)));
            if (EXP2 > 400) {
                EXP2 = fixEXP(ceil(float(EXP2) + ceil(float(E1) / 16.0 + 17.0)));
                EXP2 = fixEXP(ceil(float(EXP2) + ceil(float(EXP2) * 15.0 / 100.0)));
            }
        }
        EXP1 = fixEXP(EXP1 - E1);
    }
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if (fixE(E2) == -1) return -99;
    EXP1 = fixEXP(EXP1);
    HP1 = fixHP(HP1);
    M1 = fixM(M1);

    // ROAD1
    double P1 = 0;
    double a = sqrt(EXP1);
    int b = round(a);
    int S = b * b;
    if (EXP1 > S || EXP1 == S) P1 = 1; else P1 = (((EXP1 * 1.0) / (S * 1.0) + 80.0) / 123.0);
    // ROAD2
    if ((E2 % 2) == 1) {
        int M0 = round(M1 / 2), S = 0;
        while (S <= M0) {
            if (M1 == 0)
            {
                break;
            }
            if (HP1 < 200) {
                HP1 = fixHP(ceil(float(HP1) + ceil(float(HP1) * 3.0 / 10.0)));
                M1 = fixM(M1 - 150);
                S = S + 150;
            }
            else {
                HP1 = fixHP(ceil(float(HP1) + ceil(float(HP1) * 1.0 / 10.0)));
                M1 = fixM(M1 - 70);
                S = S + 70;
            }
            if (S > M0)
                break;
            if (EXP1 < 400) {
                EXP1 = fixEXP(ceil(float(EXP1) + ceil(float(EXP1) * 13.0 / 100.0)));
                M1 = fixM(M1 - 200);
                S = S + 200;
            }
            else {
                EXP1 = fixEXP(ceil(float(EXP1) + ceil(float(EXP1) * 13.0 / 100.0)));
                M1 = fixM(M1 - 120);
                S = S + 120;
            }
            if (S > M0)
                break;
            if (EXP1 < 300) {
                EXP1 = fixEXP(ceil(float(EXP1) - (float(EXP1) * 1.0 / 10.0)));
                M1 = fixM(M1 - 100);
                S = S + 100;
            }
            else {
                EXP1 = fixEXP(ceil(float(EXP1) - (float(EXP1) * 1.0 / 10.0)));
                M1 = fixM(M1 - 120);
                S = S + 120;
            }
            if (S > M0)
                break;
        }
        HP1 = fixHP(ceil(float(HP1) - (float(HP1) * 17.0 / 100.0)));
        EXP1 = fixEXP(ceil(float(EXP1) + ceil(float(EXP1) * 17.0 / 100.0)));
    }
    else {
        int f = 0;
        while (f < 1) {
            if (M1 == 0)
            {
                break;
            }
            if (HP1 < 200) {
                HP1 = fixHP(ceil(float(HP1) + ceil(float(HP1) * 3.0 / 10.0)));
                M1 = fixM(M1 - 150);
                S = S + 150;
            }
            else {
                HP1 = fixHP(ceil(float(HP1) + ceil(float(HP1) * 1.0 / 10.0)));
                M1 = fixM(M1 - 70);
                S = S + 70;
            }
            if (M1 == 0)
            {
                break;
            }
            if (EXP1 < 400) {
                EXP1 = fixEXP(ceil(float(EXP1) + ceil(float(EXP1) * 13.0 / 100.0)));
                M1 = fixM(M1 - 200);
                S = S + 200;
            }
            else {
                EXP1 = fixEXP(ceil(float(EXP1) + ceil(float(EXP1) * 13.0 / 100.0)));
                M1 = fixM(M1 - 120);
                S = S + 120;
            }
            if (M1 == 0)
            {
                break;
            }
            if (EXP1 < 300) {
                EXP1 = fixEXP(ceil(float(EXP1) - (float(EXP1) * 1.0 / 10.0)));
                M1 = fixM(M1 - 100);
                S = S + 100;
            }
            else {
                EXP1 = fixEXP(ceil(float(EXP1) - (float(EXP1) * 1.0 / 10.0)));
                M1 = fixM(M1 - 120);
                S = S + 120;
            }
            if (M1 == 0)
            {
                break;
            }
            f = f + 1;
        }
        HP1 = fixHP(ceil(float(HP1) - (float(HP1) * 17.0 / 100.0)));
        EXP1 = fixEXP(ceil(float(EXP1) + ceil(float(EXP1) * 17.0 / 100.0)));

    }
    double P2 = 0;
    a = sqrt(EXP1);
    b = round(a);
    S = b * b;
    if (EXP1 > S || EXP1 == S) P2 = 1; else P2 = (((EXP1 * 1.0) / (S * 1.0) + 80.0) / 123.0);
    // ROAD3
    int P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i = 0, j = E2, sum = 0, k;
    if (j < 10) i = E2; else {
        while (j > 0) {
            k = j % 10;
            sum = sum + k;
            j = j / 10;
        }
        i = sum % 10;
    }
    double P3 = (P[i] * 1.0) / 100.0;
    // END
    if (P1 == 1 && P2 == 1 && P3 == 1) EXP1 = fixEXP(round(EXP1 - (EXP1 / 4 + 0.5)));
    else {
        double P0 = (P1 + P2 + P3) / 3.0;
        if (P0 < 0.5) {
            HP1 = fixHP(ceil(float(HP1) - (float(HP1) * 15.0 / 100.0)));
            EXP1 = fixEXP(ceil(float(EXP1) + ceil(float(EXP1) * 15.0 / 100.0)));
        }
        else {
            HP1 = fixHP(ceil(float(HP1) - (float(HP1) * 1.0 / 10.0)));
            EXP1 = fixEXP(ceil(float(EXP1) + ceil(float(EXP1) * 1.0 / 5.0)));
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int sum(int n) {
    int sum = 0;
    while (n > 0 || sum > 9) {
        if (n == 0) {
            n = sum;
            sum = 0;
        }
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (fixE(E3) == -1) return -99;
    HP1 = fixHP(HP1);
    EXP1 = fixEXP(EXP1);
    HP2 = fixHP(HP2);
    EXP2 = fixEXP(EXP2);
    // TODO: Complete this function

    int a[10][10];
    int b = E3 * 2, c = E3 * (-1), e = 0, f = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (a[i][j] > b) e = e + 1; else if (a[i][j] < c) f = f + 1;
        }
    }
    if (e > 9) {
        e = sum(e);
    }
    if (f > 9) {
        f = sum(f);
    }
    int max = a[e][f];
    if (e <= f) {
        int p = 0, q = 0;
        p = e;
        q = f;
        while (p <= 9 && q >= 0) {
            if (a[p][q] > max) max = a[p][q];
            p++;
            q--;
        }
    }
    else {
        int p = 0, q = 0;
        p = e;
        q = f;
        while (p <= 9) {
            if (a[p][q] > max) max = a[p][q];
            p++;
            q++;
        }
        p = e;
        q = f;
        while (p <= 9 && q >= 0) {
            if (a[p][q] > max) max = a[p][q];
            p++;
            q--;
        }
        p = e;
        q = f;
        while (p >= 0 && q <= 9) {
            if (a[p][q] > max) max = a[p][q];
            p--;
            q++;
        }
    }
    if (abs(a[e][f]) > max) {
        EXP1 = fixEXP(ceil(float(EXP1) - 12.0 * float(EXP1) / 100.0));
        HP1 = fixHP(ceil(float(HP1) - float(HP1) / 10.0));
        EXP2 = fixEXP(ceil(float(EXP2) - 12.0 * float(EXP2) / 100.0));
        HP2 = fixHP(ceil(float(HP2) - float(HP2) / 10.0));
    }
    else {
        EXP1 = fixEXP(ceil(float(EXP1) + ceil(12.0 * float(EXP1) / 100.0)));
        HP1 = fixHP(ceil(float(HP1) + ceil(float(HP1) / 10.0)));
        EXP2 = fixEXP(ceil(float(EXP2) + ceil(12.0 * float(EXP2) / 100.0)));
        HP2 = fixHP(ceil(float(HP2) + ceil(float(HP2) / 10.0)));
    }
    int k = 0;
    if (abs(a[e][f]) > max) k = a[e][f]; else k = max;
    return k;
}

// Task 4
int checkLength(string s) {
    int count = 0;
    for (int i = 0; s[i]; i++) {
        count++;
    }
    return count;
}
string getSe(string str) {
    size_t pos = str.find_first_of('@');
    string se = str.substr(0, pos);
    return se;
}
int check1(string s, string se) {
    for (int i = 0; i < checkLength(s); i++) {
        int j;
        for (j = 0; j < checkLength(se); j++)
            if (s[i + j] != se[j]) break;
        if (j == checkLength(se)) return i;
    }
    return -1;
}
int check2(string s) {
    int count = 0;
    for (int i = 0; i < checkLength(s) - 1; i++) {
        if (s[i] == s[i + 1]) {
            if (s[i + 1] == s[i + 2]) {
                return count;
            }
        }
        count++;
    }
    return -1;
}
int check3(string s) {
    for (int i = 0; i < checkLength(s); i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') return 1;
    }
    return -1;
}
int check4(string s) {
    int a = s.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#%$!");
    if (a >= 0) return a; else return -1;
}
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function

    int length = 0, sei = 0, sci = 0, sc = 0, f = 0;
    string se;
    length = checkLength(s);
    se = getSe(email);
    sei = check1(s, se);
    sci = check2(s);
    sc = check3(s);
    f = check4(s);
    if (length < 8) return -1;
    else if (length > 20) return -2;
    else if (sei != -1) return -(300 + sei);
    else if (sci != -1) return -(400 + sci);
    else if (sc == -1) return -5;
    else if (f != -1) return f;
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string arr[30];
    for (int i = 0; i < num_pwds; i++) {
        arr[i] = arr_pwds[i];
    }
    int a = 0, pos = 0;
    string str;
    for (int i = 0; i < num_pwds; i++) {
        int count = 0;
        for (int j = i + 1; j < num_pwds; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > a) {
            str = arr[i];
            a = count;
            pos = i;
        }
        else if (count == a) {
            if (checkLength(arr[i]) > checkLength(str)) {
                str = arr[i];
                a = count;
                pos = i;
            }
        }
    }
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////