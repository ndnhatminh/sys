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

// Task 1
int checkEXP(int EXP) {
    if (EXP > 600) return 600;
    else if (EXP < 0) return 0;
    else return EXP;
}
int checkM(int M) {
    if (M > 3000) return 3000;
    else if (M < 0) return 0;
    else return M;
}
int checkHP(int HP) {
    if (HP > 666) return 666;
    else if (HP < 0) return 0;
    else return HP;
}

int firstMeet(int& EXP1, int& EXP2, int E1) {
    EXP1 = checkEXP(EXP1); EXP2 = checkEXP(EXP2);
    // TH1
    if (E1 < 0 || E1>99) return -99;
    if (E1 >= 0 && E1 <= 3) {
        if (E1 == 0) EXP2 = checkEXP(EXP2 + 29);
        else if (E1 == 1) EXP2 = checkEXP(EXP2 + 45);
        else if (E1 == 2) EXP2 = checkEXP(EXP2 + 75);
        else EXP2 = checkEXP(EXP2 + 29 + 45 + 75);
        int D = E1 * 3 + EXP1 * 7;
        double d = 1.0 * D / 200;
        if (D % 2 == 0) {
            EXP1 = EXP1 + (int)ceil(d);
            EXP1=checkEXP(EXP1);
        }
        else {
            double e = 1.0 * EXP1 - 1.0 * D / 100;
            EXP1 = (int)ceil(e);
            EXP1=checkEXP(EXP1);
        }
    }
    // TH2
    double r1 = 1.0 * E1 / 4 + 19, r2 = 1.0 * E1 / 9 + 21, r3 = 1.0 * E1 / 16 + 17;
    if (E1 >= 4 && E1 <= 99) {
        if (E1 >= 4 && E1 <= 19) {
            double a = 1.0 * EXP2 + r1;
            EXP2 = (int)ceil(a);
            EXP2 = checkEXP(EXP2);
        }
        else if (E1 >= 20 && E1 <= 49) {
            double a = 1.0 * EXP2 + r2;
            EXP2 = (int)ceil(a);
            EXP2 = checkEXP(EXP2);
        }
        else if (E1 >= 50 && E1 <= 65) {
            double a = 1.0 * EXP2 + r3;
            EXP2 = (int)ceil(a);
            EXP2 = checkEXP(EXP2);
        }
        else if (E1 >= 66 && E1 <= 79) {
            EXP2 = checkEXP((int)ceil(1.0 * EXP2 + 1.0 * E1 / 4 + 19));
            if (EXP2 > 200) {
                EXP2 = checkEXP((int)ceil(1.0 * EXP2 + 1.0 * E1 / 9 + 21));
            }
        }
        else if (E1 >= 80 && E1 <= 99) {
            EXP2 = checkEXP((int)ceil(1.0 * EXP2 + 1.0 * E1 / 4 + 19));
            EXP2 = checkEXP((int)ceil(1.0 * EXP2 + 1.0 * E1 / 9 + 21));
            if (EXP2 > 400) {
                EXP2 = checkEXP((int)ceil(1.0 * EXP2 + 1.0 * E1 / 16 + 17));
                EXP2 = checkEXP((int)ceil(1.0 * EXP2 * 1.15));
            }
        }
        EXP1 = checkEXP(EXP1 - E1);
    }
    return EXP1 + EXP2;
}




// Task 2
double traceP(int EXP1) {
    int min = INT_MAX, S;
    for (int i = 2; i <= 26; i++) {
        int a = abs(EXP1 - i * i);
        if (a < min) {
            min = a;
            S = i * i;
        }
    }
    if (EXP1 >= S) return 1.0;
    else {
        double temp = ((1.0 * EXP1 / S + 80) / 123);
        return (round(temp * 100)) / 100;;
    }
}
int tong(int dem) {
    int sum = 0;
    while (dem) {
        int a = dem % 10;
        sum += a;
        dem /= 10;
    }
    if (sum <= 9) return sum;
    else return sum % 10;;

}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 < 0 || E2>99) return -99;
    // con duong 1
    double P1 = traceP(EXP1);
    // con duong 2
    int c = M1, chitra = 0, i = 1;
    bool ok1 = false, ok2 = false;
    if (E2 % 2 != 0) {
        while (chitra < M1 / 2) {
            if (HP1 < 200 && chitra < M1 / 2) {
                c -= 150;
                chitra += 150;
                HP1 = (int)ceil(HP1 * 130.0 / 100);
                HP1 = checkHP(HP1);
                c = checkM(c);
                if (c == 0) break;

            }
            else if (HP1 >= 200 && chitra < M1 / 2) {
                c -= 70;
                chitra += 70;
                HP1 = (int)ceil(HP1 * 110.0 / 100);
                HP1 = checkHP(HP1);
                c = checkM(c);
                if (c == 0) break;
            }
            if (EXP1 < 400 && chitra < M1 / 2) {
                c -= 200;
                chitra += 200;
                EXP1 = (int)ceil(EXP1 * 113.0 / 100);
                checkEXP(EXP1);
                c = checkM(c);
                if (c == 0) break;
            }
            else if (EXP1 >= 400 && chitra < M1 / 2) {
                c -= 120;
                chitra += 120;
                EXP1 = (int)ceil(EXP1 * 113.0 / 100);
                checkEXP(EXP1);
                c = checkM(c);
                if (c == 0) break;
            }
            if (EXP1 < 300 && chitra < M1 / 2) {
                c -= 100;
                chitra += 100;
                EXP1 = (int)ceil(EXP1 * 90.0 / 100);;
                c = checkM(c);
                if (c == 0) break;
            }
            else if (EXP1 >= 300 && chitra < M1 / 2) {

                c -= 120;
                chitra += 120;
                EXP1 = (int)ceil(EXP1 * 90.0 / 100);
                c = checkM(c);
                if (c == 0) break;
            }

        }
    }
    else if (E2 % 2 == 0) {
        for (int i = 0; i < 1; i++) {
            if (HP1 < 200) {
                c -= 150;
                chitra += 150;
                HP1 = (int)ceil(HP1 * 130.0 / 100);
                HP1 = checkHP(HP1);
                c = checkM(c);
                if (c == 0) break;

            }
            else if (HP1 >= 200) {
                c -= 70;
                chitra += 70;
                HP1 = (int)ceil(HP1 * 110.0 / 100);
                HP1 = checkHP(HP1);
                c = checkM(c);
                if (c == 0) break;
            }
            if (EXP1 < 400) {
                c -= 200;
                chitra += 200;
                EXP1 = (int)ceil(EXP1 * 113.0 / 100);
                checkEXP(EXP1);
                c = checkM(c);
                if (c == 0) break;
            }
            else if (EXP1 >= 400) {
                c -= 120;
                chitra += 120;
                EXP1 = (int)ceil(EXP1 * 113.0 / 100);
                checkEXP(EXP1);
                c = checkM(c);
                if (c == 0) break;
            }
            if (EXP1 < 300) {
                c -= 100;
                chitra += 100;
                EXP1 = (int)ceil(EXP1 * 90.0 / 100);;
                c = checkM(c);
                if (c == 0) break;
            }
            else if (EXP1 >= 300) {

                c -= 120;
                chitra += 120;
                EXP1 = (int)ceil(EXP1 * 90.0 / 100);
                c = checkM(c);
                if (c == 0) break;
            }

        }
    }
    c = checkM(c);
    M1 = M1 - chitra;
    M1 = checkM(M1);
    HP1 = (int)ceil(HP1 * 83.0 / 100);
    EXP1 = (int)ceil(EXP1 * 117.0 / 100);
    EXP1 = checkEXP(EXP1);
    double P2 = traceP(EXP1);
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    double P3 = 1.0 * P[tong(E2)] / 100;
    double tb = (P1 + P2 + P3) / 3;
    tb = (round(tb * 100)) / 100;
    if (tb == 1.0) {
        EXP1 = (int)ceil(EXP1 * 75.0 / 100);
    }
    else if (tb < 0.50) {
        HP1 = (int)ceil(HP1 * 85.0 / 100);
        EXP1 = (int)ceil(EXP1 * 115.0 / 100);
        EXP1 = checkEXP(EXP1);
    }
    else {
        HP1 = (int)ceil(HP1 * 90.0 / 100);
        EXP1 = (int)ceil(EXP1 * 120.0 / 100);
        EXP1 = checkEXP(EXP1);
    }
    return HP1 + M1 + EXP1;
}






// Task 3
int tong1(int dem) {
    int sum = 0;
    while (dem) {
        int a = dem % 10;
        sum += a;
        dem /= 10;
    }
    if (sum <= 9) return sum;
    else return tong1(sum);

}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (E3 < 0 || E3>99) return -99;
    int a[10][10], b[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    // tim duong cheo trai
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int hang = i;
            int cot = j;
            int max = INT_MIN;
            // tim max tren duong cheo trai
            while (hang < 10 && cot < 10) {
                if (a[hang][cot] > max) {
                    max = a[hang][cot];
                }
                hang++;
                cot++;
            }
            // tim max tren duong cheo phai
            int hang1 = i;
            int cot1 = j;
            while (hang1 < 10 && cot1 >= 0) {
                if (a[hang1][cot1] > max) {
                    max = a[hang1][cot1];
                }

                hang1++;
                cot1--;
            }
            b[i][j] = max;
        }
    }
    int dem1 = 0, dem2 = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (a[i][j] > E3 * 2) ++dem1;
            if (a[i][j] < -E3) ++dem2;
        }
    }
    if (dem1 >= 10) {
        dem1 = tong1(dem1);
    }
    if (dem2 >= 10) {
        dem2 = tong1(dem2);
    }

    if (abs(a[dem1][dem2]) <= abs(b[dem1][dem2])) {
        // ko duoi kip
        HP1 = checkHP((int)ceil(HP1 * 110.0 / 100));
        HP2 = checkHP((int)ceil(HP2 * 110.0 / 100));
        EXP1 = checkEXP((int)ceil(EXP1 * 112.0 / 100));
        EXP2 = checkEXP((int)ceil(EXP2 * 112.0 / 100));
    }
    else {
        HP1 = checkHP((int)ceil(HP1 * 90.0 / 100));
        HP2 = checkHP((int)ceil(HP2 * 90.0 / 100));
        EXP1 = checkEXP((int)ceil(EXP1 * 88.0 / 100));
        EXP2 = checkEXP((int)ceil(EXP2 * 88.0 / 100));
    }
    if (abs(a[dem1][dem2]) <= abs(b[dem1][dem2])) return b[dem1][dem2];
    else return a[dem1][dem2];;
}

// Task 4
bool kitu(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            return true;
        }
    }
    return false;
}
bool kitu1(char s) {
    if (s == '@' || s == '#' || s == '%' || s == '$' || s == '!') {
        return true;
    }
    else return false;
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}
bool isLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
int checkPassword(const char* s, const char* email) {
    string se;
    string s1 = s;
    string email1 = email;
    stringstream ss(email1);
    while (getline(ss, se, '@')) {
        break;
    }
    if (s1.size() < 8) return -1;
    if (s1.size() > 20) return -2;
    if (s1.find(se) != string::npos) {
        int a = s1.find(se);
        return -(int)a - 300;
    }

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == '@' || s1[i] == '#' || s1[i] == '%' || s1[i] == '$' || s1[i] == '!') {
            if (s1[i] == s1[i + 1] && s1[i + 1] == s1[i + 2] && s1[i] == s1[i + 2]) return -i - 400;
        }
    }

    if (kitu(s1) == false) return -5;
    for (int i = 0; i < s1.size(); i++) {
        if (isDigit(s1[i]) == false && isLetter(s1[i]) == false && kitu1(s1[i]) == false) {
            return i;
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int b[40] = { 0 };
    int max = INT_MIN;
    int a = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (strlen(arr_pwds[i]) != 0) {
            for (int j = i + 1; j < num_pwds; j++) {
                if (strlen(arr_pwds[j]) != 0) {
                    if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                        b[i]++;
                        arr_pwds[j] = ""; 
                    }
                }
            }
        }
    }
    for (int j = 0; j < 40; j++) {
        if (b[j] != 0) {
            if (b[j] > max) {
                max = b[j];
                a = j;
            }
            else if (b[j] == max) {
                if (strlen(arr_pwds[j]) > strlen(arr_pwds[a])) {
                    a = j;
                }
            }
        }
    }
    return a;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////