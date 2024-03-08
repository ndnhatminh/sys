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
void check(int& EXP1,int& EXP2) {
    if (EXP1 > 600) EXP1 = 600;
    if (EXP2 > 600) EXP2 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP2 < 0) EXP2 = 0;
}
void check3(int& HP1, int& HP2) {
    if (HP1 > 666) HP1 = 666;
    if (HP2 > 666) HP2 = 666;
    if (HP1 < 0) HP1 = 0;
    if (HP2 < 0) HP2 = 0;
}
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    if (E1 < 0 || E1> 99) return -99;  
    check(EXP1, EXP2);
    // TODO: Complete this function
    int D = E1 * 3 + EXP1 * 7;
    if (E1 == 0) EXP2 += 29;
    if (E1 == 1) EXP2 += 45;
    if (E1 == 2) EXP2 += 75;
    if (E1 == 3) EXP2 += 149;
    if (D % 2 != 0 && E1<4) EXP1 -= D / 100;
    if (D % 2 == 0 && E1<4) EXP1 += D / 200.0 + 0.99;
    if (E1 >= 4 && E1 <= 19) EXP2 += (E1 / 4.0 + 0.99) + 19;
    if (E1 >= 20 && E1 <= 49) EXP2 += (E1 / 9.0 + 0.99) + 21;
    if (E1 >= 50 && E1 <= 65) EXP2 += (E1 / 16.0 + 0.99) + 17;
    
    if (E1 >= 66 && E1 <= 79) {
        EXP2 += (E1 / 4.0 + 0.99) + 19;
        if (EXP2 > 200) EXP2 += (E1 / 9.0 + 0.99) + 21;
    }
    if (E1 >= 80 && E1 <= 99) {
        EXP2 += (E1 / 4.0 + 0.99) + 19;
        EXP2 += (E1 / 9.0 + 0.99) + 21;
        if (EXP2 > 400) {
            EXP2 += (E1 / 16.0 + 0.99) + 17;
            EXP2 = EXP2 * 1.15 + 0.99;
        }
    }
    if (E1 > 3) EXP1 = EXP1 - E1;
    check(EXP1, EXP2);
    return EXP1 + EXP2;
}
int Near(int a) {
    double a1, a2;
    int b;
    for (int i = a; i > 0; i--) {
        a1 = i;
        b = sqrt(i);
        if ((sqrt(a1) - b) == 0) {
            break;
        }
    }
    for (int i = a; i <= 625; i++) {
        a2 = i;
        b = sqrt(i);
        if ((sqrt(a2) - b) == 0) {
            break;
        }
    }
    if ((a - a1) > (a2 - a)) {
        return a2;
    }
    else return a1;
}
void check2(int& EXP1, int& HP1, int& M1) {
    if (EXP1 < 0) EXP1 = 0;
    if (HP1 < 0) HP1 = 0;
    if (M1 < 0) M1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (EXP1 > 600) EXP1 = 600;
    if (M1 > 3000) M1 = 3000;
}
double Odd(int& EXP1, int& HP1, int& M1) {
    double SM = M1 * 0.5;
    bool nover = true;
    double S;
    while (nover) {
        if (nover) {
            if (HP1 < 200) {
                HP1 = HP1 * 1.3 + 0.99;
                M1 -= 150;
            }
            else {
                HP1 = HP1 * 1.1 + 0.99;
                M1 -= 70;
            }
        }
        check2(EXP1, HP1, M1);
        if (M1 < SM) nover = false;
        if (nover) {
            if (EXP1 < 400) {
                M1 -= 200;
            }
            else {
                M1 -= 120;
            }
            EXP1 = EXP1 * 1.13 + 0.99;
        }
        check2(EXP1, HP1, M1);
        if (M1 < SM) nover = false;
        if (nover) {
            if (EXP1 < 300) {
                M1 -= 100;
            }
            else {
                M1 -= 120;
            }
        }
        check2(EXP1, HP1, M1);
        if (M1 < SM) nover = false;
    }
    HP1 = HP1 * 0.83 + 0.99;
    EXP1 = EXP1 * 1.17 + 0.99;
    S = Near(EXP1);
    if (EXP1 >= S) return 100;
    else return ((EXP1 / S) + 80) / (1.23);
}
double Even(int& EXP1, int& HP1, int& M1) {
    double S;
    if (M1 > 0) {
        if (HP1 < 200) {
            HP1 = HP1 * 1.3 + 0.99;
            M1 -= 150;
        }
        else {
            HP1 = HP1 * 1.1 + 0.99;
            M1 -= 70;
        }
    }
    check2(EXP1, HP1, M1);
    if (M1 > 0) {
        if (EXP1 < 400) {
            M1 -= 200;
        }
        else {
            M1 -= 120;
        }
        EXP1 = EXP1 * 1.13 + 0.99;
    }
    check2(EXP1, HP1, M1);
    if (M1 > 0) {
        if (EXP1 < 300) {
            M1 -= 100;
        }
        else {
            M1 -= 120;
        }
    }
    check2(EXP1, HP1, M1);
    HP1 = HP1 * 0.83 + 0.99;
    EXP1 = EXP1 * 1.17 + 0.99;
    S = Near(EXP1);
    if (EXP1 >= S) return 100;
    else return ((EXP1 / S) + 80) / (1.23);
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 < 0 || E2>99) return -99;
    // TODO: Complete this function
    check2(EXP1, HP1, M1);
    double P1, P2, P3;
    double S;
    S = Near(EXP1);
    if (EXP1 >= S) P1 = 100;
    else P1 = ((EXP1 / S) + 80) / (1.23);
    if (E2 % 2 != 0) {
        P2 = Odd(EXP1, HP1, M1);
    }
    else P2 = Even(EXP1, HP1, M1);
    int arr[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2 < 10) P3 = arr[E2];
    else {
        int i;
        i = E2 / 10 + E2 - (E2 / 10) * 10;
        i = i - (i / 10) * 10;
        P3 = arr[i];
    }
    double P;
    if (P3 == P1 && P1 == P2 && P1 == 100) EXP1 = EXP1 * 0.75 + 0.99;
    else {
        P = (P1 + P2 + P3) / 3.0;
        if (P >= 50) {
            HP1 = HP1 * 0.9 + 0.99;
            EXP1 = EXP1 * 1.2 + 0.99;
        }
        else {
            HP1 = HP1 * 0.85 + 0.99;
            EXP1 = EXP1 * 1.15 + 0.99;
        }
    }
    check2(EXP1, HP1, M1);
    return HP1 + EXP1 + M1;
}
int EE3;
int point(int i, int j) {
    return ((EE3 * j) + (i * 2)) * (i - j);
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3>99) return -99;
    EE3 = E3;
    int map[10][10];
    int x, y;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = point(i, j);
        }
    }
    int more = 0;
    int less = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map[i][j] > (E3 * 2)) more += 1;
            if (map[i][j] < (E3 * (-1))) less += 1;

        }
    }
    if (more / 10 != 0) {
        x = (more / 10) + (more - (more / 10) * 10);
        if (x >= 10) x = (x / 10) + (x - (x / 10) * 10);
    }
    else x = more;
    if (less / 10 != 10) {
        y = (less / 10) + (less - (less / 10) * 10);
        if (y >= 10) y = (y / 10) + (y - (y / 10) * 10);
    }
    else y = less;
    int taxi = map[x][y];
    int true_point = -9999;
    int i = x;
    int j = y;
    while (i > 0 && j > 0) {
        i = i - 1;
        j = j - 1;
        if (map[i][j] >= true_point) true_point = map[i][j];
    }
    i = x;
    j = y;
    while (j < 9 && i > 0) {
        i = i - 1;
        j = j + 1;
        if (map[i][j] >= true_point) true_point = map[i][j];
    }
    i = x;
    j = y;
    while (i < 9 && j > 0) {
        i = i + 1;
        j = j - 1;
        if (map[i][j] >= true_point) true_point = map[i][j];
    }
    i = x;
    j = y;
    while (i < 9 && j < 9) {
        i = i + 1;
        j = j + 1;
        if (map[i][j] >= true_point) true_point = map[i][j];
    }
    if (abs(taxi) > abs(true_point)) {
        EXP1 = 0.88 * EXP1 + 0.99;
        EXP2 = 0.88 * EXP2 + 0.99;
        HP1 = 0.9 * HP1 + 0.99;
        HP2 = 0.9 * HP2 + 0.99;
        check(EXP1, EXP2);
        check3(HP1, HP2);
        return taxi;
    }
    else {
        EXP1 = 1.12 * EXP1 + 0.99;
        EXP2 = 1.12 * EXP2 + 0.99;
        HP1 = 1.1 * HP1 + 0.99;
        HP2 = 1.1 * HP2 + 0.99;
        check(EXP1, EXP2);
        check3(HP1, HP2);
        return true_point;
    }
    
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string s1 = s;
    string email1 = email;
    int co = 0;
    int cou = 0;
    char ara[100];
    char arara[100];
    for (char a : email1) {
        if (a == '@') break;
        ara[co] = a;
        co = co + 1;
    }
    string se;
    for (int i = 0; i < co; i++) {
        se += ara[i];
    }
    for (char a : s1) {
        arara[cou] = a;
        cou = cou + 1;
    }
    if (cou < 8) return -1;
    if (cou > 20) return -2;
    for (int i = 0; i < cou; i++) {
        if (arara[i] == ara[0]) {
            int ase = 0;
            for (int j = i; j < cou; j++) {
                if (arara[j] != ara[ase]) continue;
                ase += 1;
                if (ase == co) return -(300 + i);
            }
        }
    }
    for (int i = 0; i < (cou - 2); i++) {
        if (arara[i] == arara[i + 1] && arara[i] == arara[i + 2]) return -(400 + i);
    }
    bool special = false;
    for (int i = 0; i < cou; i++) {
        if (arara[i] == '@' || arara[i] == '!' || arara[i] == '$' || arara[i] == '%' || arara[i] == '#') {
            special = true;
            break;
        }
    }
    if (special != true) return -5;
    for (int i = 0; i < cou; i++) {
        if (arara[i] == '^' || arara[i] == '&' || arara[i] == '*' || arara[i] == '(' || arara[i] == ')') {
            return i;
            break;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int fact;
    string pass[num_pwds];
    //Chuyen tu const char thanh string.
    for (int i = 0; i < num_pwds; i++) {
        pass[i] = arr_pwds[i];
    }
    int a = 0;
    string Opass[num_pwds];
    int Times[num_pwds];
    for (int i = 0; i < num_pwds; i++) {
        Times[i] = 0;
    }
    //Kiem tra xem pass co trung ko
    for (int i = 0; i < num_pwds; i++) {
        for (int j = 0; j < num_pwds; j++) {
            if (pass[i] != Opass[j]) {
                if (j == (num_pwds-1)){
                    Opass[a] = pass[i];
                    Times[a] += 1;
                    a = a + 1;
                }
            }
            else {
                Times[j] = Times[j] + 1;
                break;
            }
        }
    }
    int m = 0;
    int t = 0;
    int l = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (Times[i] > m) {
            m = Times[i];
            a = i;
            t = 0;
            for (char u : Opass[i]) {
                t = t + 1;
            }
            l = t;
        }
        if (Times[i] == m) {
            t = 0;
            for (char u : Opass[i]) {
                t = t + 1;
            }
            if (t > l) {
                a = i;
                l = t;
            }
        }
    }
    for (int i = 0; i < num_pwds; i++) {
        if (pass[i] == Opass[a]) {
            fact = i;
            break;
        }
    }
    return fact;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////