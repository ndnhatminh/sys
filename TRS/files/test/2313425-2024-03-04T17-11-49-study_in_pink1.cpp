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
int LamTron(float num) {
    int a = num;
    if (round(num) != a) {
        return a++;
    }
    else return a;
}
int check_HP(int HP1) {
    if ((HP1 >= 0) && (HP1 <= 666)) {
        return HP1;
    }
    else if (HP1 < 0) return 0;
    else return 666;
}

int check_EXP(int EXP1) {
    if ((EXP1 >= 0) && (EXP1 <= 600)) {
        return EXP1;
    }
    else if (EXP1 > 600) return 600;
    else return 0;
}

int check_M(int M1) {
    if ((M1 >= 0) && (M1 <= 3000)) {
        return M1;
    }
    else if (M1 > 3000) return 3000;
    else return 0;
}
bool check_E(int e1) {
    if (e1 >= 0 && e1 <= 99) {
        return true;
    }
    else return false;
}
int firstMeet(int& exp1, int& exp2, int e1) {
    //Trường hợp 1
    if (check_E(e1)) {
        exp1 = check_EXP(exp1);
        exp2 = check_EXP(exp2);
        if ((e1 >= 0) && (e1 <= 3)) {
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
                exp2 = exp2 + 29 + 45 + 75;
                break;
            }
            int D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0) exp1 += ((double)D / 200) + 0.99999;
            else exp1 = (double)exp1 - ((double)D / 100) + 0.9999;
        }
        //Trường hợp 2
        if (e1 >= 4 && e1 <= 99) {
            if (e1 >= 4 && e1 <= 19) exp2 += (double)e1 / 4 + 19 + 0.9999;
            else if (e1 >= 20 && e1 <= 49) exp2 = (double)exp2 + double(e1) / 9 + 21 + 0.9999;
            else if (e1 >= 50 && e1 <= 65) exp2 = (double)exp2 + double(e1) / 16 + 17 + 0.9999;
            else if (e1 >= 66 && e1 <= 79) {
                exp2 = (double)exp2 + double(e1) / 4 + 19 + 0.9999;
                if (exp2 > 200) exp2 = (double)exp2 + double(e1) / 9 + 21 + 0.99999;

            }
            else {
                exp2 += (double)e1 / 4 + 19 + 0.9999;
                exp2 = (double)exp2 + double(e1) / 9 + 21 + 0.9999;
                if (exp2 > 400) {
                    exp2 = (double)exp2 + (double)e1 / 16 + 17 + 0.999999;
                    exp2 = (double)exp2 * 1.15 + 0.9999999;
                    if (exp2 > 600) exp2 = 600;
                }
            }
            exp1 -= e1;
        }
        exp1 = check_EXP(exp1);
        exp2 = check_EXP(exp2);
        return exp1 + exp2;
    }
    else return -99;
}

// Task 2
//Ham kiem tra so chinh phuong
bool SoChinhPhuong(int num) {
    int can = sqrt(num);
    if (can * can == num) {
        return true;
    }
    else return false;
}
//Ham tim so chinh phuong gan nhat
int SoChinhPhuongGanNhat(int num) {
    int lower = num - 1;
    int higher = num + 1;

    while (true) {
        if (SoChinhPhuong(lower)) {
            return lower;
        }
        if (SoChinhPhuong(higher)) {
            return higher;
        }
        lower--;
        higher++;
    }
}
double XacSuat01(int& HP1, int& EXP1, int& M1, int E2) {
    double P1;
    HP1 = check_HP(HP1);
    M1 = check_M(M1);
    EXP1 = check_EXP(EXP1);
    double S = SoChinhPhuongGanNhat(EXP1);
    if (EXP1 >= S) {
        P1 = 1;
    }
    else P1 = ((double)EXP1 / S + 80) / 123;
    return P1;
}

double XacSuat02(int& HP1, int& EXP1, int& M1, int E2) {
    double paid = 0;
    HP1 = check_HP(HP1);
    M1 = check_M(M1);
    EXP1 = check_EXP(EXP1);
    double M = (double)M1 / 2;
    //E2 le
    if (E2 % 2 != 0) {
        while (paid <= M) {
            //Su kien 1
            if (HP1 < 200) {
                HP1 = (double)HP1 * 1.3 + 0.99999;
                M1 -= 150;
                paid += 150;
                HP1 = check_HP(HP1);
            }
            else {
                HP1 = (double)HP1 * 1.1 + 0.99999;
                M1 -= 70;
                paid += 70;
                HP1 = check_HP(HP1);
            }
            if (paid > M) break;
            //Su kien 2
            if (EXP1 < 400) {
                M1 -= 200;
                paid += 200;
                EXP1 = (double)EXP1 * 1.13 + 0.99999;
                EXP1 = check_EXP(EXP1);
            }
            else {
                M1 -= 120;
                paid += 120;
                EXP1 = (double)EXP1 * 1.13 + 0.999999;
                EXP1 = check_EXP(EXP1);
            }
            if (paid > M) break;
            //Su kien 3
            if (EXP1 < 300) {
                M1 -= 100;
                paid += 100;

            }
            else {
                M1 -= 120;
                paid += 120;

            }
            EXP1 = (double)EXP1 * 0.9 + 0.99999;
            EXP1 = check_EXP(EXP1);
            if (paid > M) break;

        }
        HP1 = (double)HP1 * 0.83 + 0.99999;
        EXP1 = (double)EXP1 * 1.17 + 0.99999;
        HP1 = check_HP(HP1);
        EXP1 = check_EXP(EXP1);
    }
    //E2 chan
    else {
        //Su kien 1
        for (int i = 0; i < 1; i++) {
            if (HP1 < 200) {
                HP1 = double(HP1) * 1.3 + 0.99999;
                M1 -= 150;
                paid = 150;
            }
            else {
                HP1 = HP1 * 1.1 + 0.999999;
                HP1 = check_HP(HP1);
                M1 -= 70;
                paid = 70;
            }
            M1 = check_M(M1);
            if (M1 == 0) break;

            //Su kien 2

            if (EXP1 < 400) {
                M1 -= 200;
                paid += 200;

            }
            else {
                M1 -= 120;
                paid += 120;

            }
            EXP1 = (double)EXP1 * 1.13 + 0.99999;
            M1 = check_M(M1);
            if (M1 == 0) break;

            //Su kien 3

            if (EXP1 < 300) {
                M1 -= 100;
                paid += 100;

            }
            else {
                M1 -= 120;
                paid += 120;

            }
            EXP1 = (double)EXP1 * 0.9 + 0.99999;
            M1 = check_M(M1);

            if (M1 == 0) break;
        }
        HP1 = HP1 * 0.83 + 0.99999;
        EXP1 = double(EXP1) * 1.17 + 0.999999;

    }
    double P2 = XacSuat01(HP1, EXP1, M1, E2);
    return P2;
}
double XacSuat03(int& HP1, int& EXP1, int& M1, int E2) {
    HP1 = check_HP(HP1);
    M1 = check_M(M1);
    EXP1 = check_EXP(EXP1);
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i;
    if (E2 <= 9) i = E2;
    if (E2 >= 10) {
        int i1 = E2 / 10;
        int i2 = E2 % 10;
        i = i1 + i2;
        if (i >= 10) i = i / 10 + i % 10;
    }
    double P3 = P[i];
    return P3 / 100;
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (check_E(E2)) {
        HP1 = check_HP(HP1);
        EXP1 = check_EXP(EXP1);
        M1 = check_M(M1);
        double P1 = XacSuat01(HP1, EXP1, M1, E2);
        double P2 = XacSuat02(HP1, EXP1, M1, E2);
        double P3 = XacSuat03(HP1, EXP1, M1, E2);
        double Pa;


        //Conclusion
        Pa = (P1 + P2 + P3) / 3;
        if (Pa * 100 == 100) {
            EXP1 = (double)EXP1 * 0.75 + 0.9999;

        }
        else if (Pa * 100 < 50) {
            HP1 = (double)HP1 * 0.85 + 0.99999;

            EXP1 = (double)EXP1 * 1.15 + 0.9999;

        }
        else if (Pa * 100 >= 50) {
            HP1 = (double)HP1 * 0.9 + 0.9999;
            EXP1 = (double)EXP1 * 1.2 + 0.99999;
        }
        HP1 = check_HP(HP1);
        EXP1 = check_EXP(EXP1);
        M1 = check_M(M1);
        return HP1 + EXP1 + M1;
    }
    else return -99;
}

// Task 3
//Ham tim max duong cheo trai
int maxDCheoTrai(int i, int j, int map[10][10]) {
    int MaxVal = INT_MIN;
        while (i < 10 && j >= 0 && i >= 0 && j <= 10) {
            MaxVal = max(MaxVal, map[i][j]);
            i++;
            j--;
    }
        while (i < 10 && j >= 0 && i >= 0 && j <= 10) {
            MaxVal = max(MaxVal, map[i][j]);
            i--;
            j++;
        }
        return MaxVal;
}
//Ham tim max duong cheo phai
int maxDCheoPhai(int i, int j, int map[10][10]) {
    int MaxVal = INT_MIN;
    while (i < 10 && j >= 0 && i >= 0 && j <= 10) {
        MaxVal = max(MaxVal, map[i][j]);
        i++;
        j++;
    }
    while (i < 10 && j >= 0 && i >= 0 && j <= 10) {
        MaxVal = max(MaxVal, map[i][j]);
        i--;
        j--;
    }
    return MaxVal;
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    //Ban do taxi
    int map[10][10] = { 0 };
    int count1 = 0, count2 = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (map[i][j] > (E3 * 2)) count1++;
            if (map[i][j] < (-E3)) count2++;
        }
    }

    int m, n;
    if (count1 <= 9) m = count1;
    else {
        m = ((int)count1 / 10) + ((int)count1 % 10);
        if (m >= 10) m = (m / 10) + (m % 10);
    }
    if (count2 <= 9) n = count2;
    else {
        n = ((int)count2 / 10) + ((int)count2 % 10);
        if (n >= 10) n = (n / 10) + (n % 10);
    }
    int pointTaxi = map[m][n], pointSherlock = max(maxDCheoPhai(m, n, map), maxDCheoTrai(m, n, map));
    int result;
    if (abs(pointTaxi) > pointSherlock) {
        EXP1 = EXP1 * 0.88 + 0.999999;
        HP1 = HP1 * 0.9 + 0.99999;
        EXP2 = EXP2 * 0.88 + 0.99999;
        HP2 = HP2 * 0.9 + 0.999999;
        EXP1 = check_EXP(EXP1);
        EXP2 = check_EXP(EXP2);
        HP1 = check_HP(HP1);
        HP2 = check_HP(HP2);
        return pointTaxi;
    }
    else {
        EXP1 = EXP1 * 1.12 + 0.999999;
        HP1 = HP1 * 1.1 + 0.99999;
        EXP2 = EXP2 * 1.12 + 0.99999;
        HP2 = HP2 * 1.1 + 0.999999;
        EXP1 = check_EXP(EXP1);
        EXP2 = check_EXP(EXP2);
        HP1 = check_HP(HP1);
        HP2 = check_HP(HP2);
        return pointSherlock;
    }
    return result;
}

// Task 4
int checkPassword(const char * s, const char* email) {
    const char* pos;
    pos = strchr(email, '@');
    // Lấy chuỗi 'se' từ đầu đến trước ký tự '@'
    char se[100]; // Email có độ dài tối đa là 100
    strncpy(se, email, pos - email);
    se[pos - email] = '\0';

    if (strlen(s) < 8)
        return -1;
    else if (strlen(s) > 20)
        return -2;
    else if (strstr(s, se) != NULL)
        return -(300 + (strstr(s, se) - s));
    else {
        for (int i = 0; i < strlen(s) - 2; i++) {
            if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
                return -(400 + i);
            }
        }
    }
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != '@' || s[i] != '#' || s[i] != '%' || s[i] != '$' || s[i] != '!') {
            return -5;
            continue;
        }
        else if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            return -10;
        continue;
    }

    return -99;
}

// Task 5
int XuatHien(string a[], int num_pwds, string password) {
    int count = 0;
    for (int i = 0; i < num_pwds; ++i) {
        if (a[i] == password) {
            count++;
        }
    }
    return count;
}
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string a[100];
    for (int i = 0; i < num_pwds; ++i) {
        a[i] = arr_pwds[i];
    }
    int maxLength = 0;
    int maxCount = 0;
    string Current_Pwds;
    string Correct_Pwds;

    for (size_t i = 0; i < num_pwds; ++i) {
        Current_Pwds = a[i];
        int SoLanXuatHien = XuatHien(a, num_pwds, Current_Pwds);
        if (SoLanXuatHien > maxCount || (SoLanXuatHien == maxCount && Current_Pwds.length() > maxLength)) {
            maxCount = SoLanXuatHien;
            maxLength = Current_Pwds.length();
            Correct_Pwds = Current_Pwds;
        }
    }

    for (int i = 0; i < num_pwds; ++i) {
        if (a[i] == Correct_Pwds) {
            return i;
        }
    }
    return -1;
}



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////