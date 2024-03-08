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

int check_hp(double hp) {
    if (hp > 666) hp = 666;
    if (hp < 0) hp = 0;
    if (round(hp + 0.4999999) > int(hp)) hp = int(hp) + 1;
    return hp;
}
int check_exp(double exp) {
    if (exp > 600) exp = 600;
    if (exp < 0) exp = 0;
    if (round(exp + 0.4999999) > int(exp)) exp = int(exp) + 1;
    return exp;
}
int check_m(double m) {
    if (m > 3000) m = 3000;
    if (m < 0) m = 0;
    if (round(m + 0.4999999) > int(m)) m = int(m) + 1;
    return m;
}
bool arrange_password(const char* s,const char* arr_pwds[], int n,int a[30][3]) {
    if (n == 0) return true;
    for (int i = 0;i < n;i++) {
        int m = 0;
        while (1) {
            if (s[m] != arr_pwds[a[i][1]][m]) break;
            if (s[m] == '\0') {
                a[i][2]++;
                return false;
            }
            m++;
        }
    }
    return true;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1>99) return -99;
    else {
        if (e1 >= 0 && e1 <= 3) {
            switch (e1)
            {
            case 0: exp2 += 29;break;
            case 1: exp2 += 45;break;
            case 2: exp2 += 75;break;
            default:exp2 += 149;
                break;
            }
            exp2 = check_exp(exp2);
            int d = e1 * 3 + exp1*7;
            if (d % 2 == 0) exp1 = check_exp(1.0 * exp1 + d / 200.0);
            else exp1 = check_exp(1.0 * exp1 - d / 100.0);
        }
        else {
            if (e1 <= 19) exp2 = check_exp(1.0 * exp2 + 19.0 + e1 / 4.0);
            else if(e1<=49) exp2 = check_exp(1.0 * exp2 + 21.0 + e1 / 9.0);
            else if (e1 <= 65) exp2 = check_exp(1.0 * exp2 + 17.0 + e1 / 16.0);
            else if (e1 <= 79) {
                exp2 = check_exp(1.0 * exp2 + 19.0 + e1 / 4.0);
                if(exp2>200) exp2 = check_exp(1.0 * exp2 + 21.0 + e1 / 9.0);
            }
            else{
                exp2 = check_exp(1.0 * exp2 + 19.0 + e1 / 4.0);
                exp2 = check_exp(1.0 * exp2 + 21.0 + e1 / 9.0);
                if (exp2 > 400) {
                    exp2 = check_exp(1.0 * exp2 + 17.0 + e1 / 16.0);
                    exp2 = check_exp(exp2 * 1.15);
                }
            }
            exp1 = check_exp(exp1 - e1);
        }

        return exp1 + exp2;
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2>99) return -99;
    else {
        double p1, p2, p3;
        int s = sqrt(EXP1);
        if (2 * EXP1 < 2 * s * s + 2 * s + 1) p1 = 1;
        else {
            s = (s + 1) * (s + 1);
            p1 = (double(EXP1) / double(s) + 80.0) / 123.0;
        }
        if (E2 % 2 == 0) {
            if (M1) {
                if (HP1 < 200) {
                    HP1 = check_hp(HP1 * 1.3);
                    M1 = check_m(M1 - 150);
                }
                else {
                    HP1 = check_hp(HP1 * 1.1);
                    M1 = check_m(M1 - 70);
                }
            }
            if (M1) {
                if(EXP1<400) M1 = check_m(M1 - 200);
                else M1 = check_m(M1 - 120);
                EXP1 = check_exp(EXP1 * 1.13);
            }
            if (M1) {
                if(EXP1<300) M1 = check_m(M1 - 100);
                else M1 = check_m(M1 - 120);
                EXP1 = check_exp(EXP1 * 0.9);
            }
            HP1 = check_hp(HP1 *0.83);
            EXP1 = check_exp(EXP1 * 1.17);
        }
        else {
            int m = 0,m1=M1;
            while (1) {
                if (M1 == 0) break;
                if (HP1 < 200) {
                    HP1 = check_hp(HP1 * 1.3);
                    M1 = check_m(M1 - 150);
                    m += 150;
                }
                else {
                    HP1 = check_hp(HP1 * 1.1);
                    M1 = check_m(M1 - 70);
                    m += 70;
                }
                if (2 * m > m1) break;
                if (EXP1 < 400) {
                    M1 = check_m(M1 - 200);m += 200;
                }
                else { M1 = check_m(M1 - 120);m += 120; }
                EXP1 = check_exp(EXP1 * 1.13);
                if (2 * m > m1) break;
                if (EXP1 < 300) { M1 = check_m(M1 - 100);m += 100; }
                else {
                    M1 = check_m(M1 - 120);m += 120;
                }
                EXP1 = check_exp(EXP1 * 0.9);
                if (2 * m > m1) break;
            }
            HP1 = check_hp(HP1 * 0.83);
            EXP1 = check_exp(EXP1 * 1.17);
        }
        s = sqrt(EXP1);
        if (2 * EXP1 < 2 * s * s + 2 * s + 1) p2 = 1;
        else {
            s = (s + 1) * (s + 1);
            p2 = (double(EXP1) / double(s) + 80.0) / 123.0;
        }
        double p[] = { 32,47,28,79,100,50,22,83,64,11 };
        p3 = p[(E2 / 10 + E2 % 10) % 10]/100;
        if(p1+p2+p3==3)  EXP1 = check_exp(EXP1 * 0.75);
        else {
            if (p1 + p2 + p3 < 1.5) {
                HP1 = check_hp(HP1 * 0.85);
                EXP1 = check_exp(EXP1 * 1.15);
            }
            else {
                HP1 = check_hp(HP1 * 0.9);
                EXP1 = check_exp(EXP1 * 1.2);
            }
        }
        return HP1 + EXP1 + M1;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3>99) return -99;
    int site[10][10],m=0,n=0;
    for (int i = 0;i < 10;i++) {
        for (int j = 0;j < 10;j++) {
            site[i][j] = (E3 * j + i * 2) * (i - j);
            if (site[i][j] > E3 * 2) m++;
            if (site[i][j] < -E3) n++;
        }
    }
    while (m > 9) {
        m = m / 10 + m % 10;
    }
    while (n > 9) {
        n = n / 10 + n % 10;
    }
    int max_point = site[m][n];
    int min = (m > n) ? n : m;
    for (int i = -min;m + i < 10 && n + i < 10;i++) {
        if (max_point < site[m + i][n + i]) max_point = site[m + i][n + i];
    }
    min = (m > 9 - n) ? 9 - n : m;
    for (int i = -min;m + i < 10 && 9-n + i < 10;i++) {
        if (max_point < site[m + i][n - i]) max_point = site[m + i][n - i];
    }
    if (abs(max_point) < abs(site[m][n])) {
        HP1 = check_hp(HP1 * 0.9);
        EXP1 = check_exp(EXP1 * 0.88);
        HP2 = check_hp(HP2 * 0.9);
        EXP2 = check_exp(EXP2 * 0.88);
        return site[m][n];
    }
    else {
        HP1 = check_hp(HP1 * 1.1);
        EXP1 = check_exp(EXP1 * 1.12);
        HP2 = check_hp(HP2 * 1.1);
        EXP2 = check_exp(EXP2 * 1.12);
        return abs(max_point);
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int size_s = 0;
    string se, password;
    while (1) {
        if (*s == '\0') break;
        else {
            password.push_back(*s);
            size_s++;
            s++;
        }
    }
    s -= size_s;
    if (size_s < 8) return -1;
    if (size_s > 20) return -2;
    while (1) {
        if (*email == '@') break;
        else se.push_back(*email);
        email++;
    }
    if (password.find(se) != string::npos) return -300 - password.find(se);
    for (int i = 0;i < size_s - 2;i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) return -400 - i;
    }
    int check = 1;
    for (int i = 0;i < size_s;i++) {
        if (int(s[i]) == 33 || int(s[i]) == 64 || int(s[i]) > 34 && int(s[i]) < 38) {
            check = 0; break;
        }
    }
    if (check) return -5;
    for (int i = 0;i < size_s;i++) {
        if (int(s[i]) != 33 && int(s[i]) != 64 && !(int(s[i]) > 34 && int(s[i]) < 38)&&!(int(s[i])>47&& int(s[i])<58)&&!(int(s[i])>96&& int(s[i])<123)&&!(int(s[i])>64&& int(s[i])<91)) {
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int a[30][3],n=0;
    for (int i = 0;i < num_pwds;i++) {
        if (arrange_password(arr_pwds[i], arr_pwds, n, a)) {
            a[n][1] = i;
            a[n][2] = 1;
            a[n][0] = 0;
            while (1) {
                if (*arr_pwds[i] == '\0') {
                    arr_pwds[i] -= a[n][0];
                    break;
                }
                a[n][0]++;
                arr_pwds[i]++;
            }
            n++;
        }
    }
    int max = 0;
    for (int i = 1;i < n;i++) {
        if (a[i][2] > a[max][2]) max = i;
        if (a[i][2] == a[max][2]) {
            if (a[i][0] > a[max][0]) max = i;
        }
    }
    return a[max][1];
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////