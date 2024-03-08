#include "study_in_pink1.h"

bool readFile(const string& filename, int& HP1, int& HP2, int& EXP1, int& EXP2, int& M1, int& M2, int& E1, int& E2, int& E3) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNCTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    } else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

// STUDENT'S ANSWER BEGINS HERE
// Complete the following functions
// DO NOT modify any parameters in the functions.

double _ceil(double num) {
    // cout << "Ta dao: " << abs(num - (int)round(num)) << endl;
    if (abs(num - (int)round(num)) < 0.0000001) {
        // cout << "Ta dao: " << abs(num - (int)round(num)) << endl;
        return round(num);
    }
    return ceil(num);
}

// Task 1
void ensureExp(int& exp) {
    if (600 < exp) {
        exp = 600;
    } else if (exp < 0) {
        exp = 0;
    }
}

int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    // Su kien ngoai doan [0, 99]
    if (e1 < 0 || 99 < e1) {
        return -99;
    }

    // Truong hop 1
    if (0 <= e1 && e1 <= 3) {
        // Thay doi exp2
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
        }
        ensureExp(exp2);

        // Thay doi exp1
        int d = e1 * 3 + exp1 * 7;
        double exp1_temp;
        if (d % 2 == 0) {
            exp1_temp = exp1 + d / 200.0;
        } else {
            exp1_temp = exp1 - d / 100.0;
        }
        exp1 = _ceil(exp1_temp);
        ensureExp(exp1);
    }

    // Truong hop 2
    else {
        double exp2_temp;
        switch (e1) {
            case 4 ... 19:
                exp2_temp = exp2 + (e1 / 4.0 + 19);
                break;
            case 20 ... 49:
                exp2_temp = exp2 + (e1 / 9.0 + 21);
                break;
            case 50 ... 65:
                exp2_temp = exp2 + (e1 / 16.0 + 17);
                break;
            case 66 ... 79:
                exp2_temp = exp2 + (e1 / 4.0 + 19);  // Giai thich thong tin 1
                exp2 = _ceil(exp2_temp);
                ensureExp(exp2);

                if (200 < exp2) {
                    exp2_temp = exp2 + (e1 / 9.0 + 21);  // Giai thich thong tin 2
                }
                break;
            case 80 ... 99:
                exp2_temp = exp2 + (e1 / 4.0 + 19);  // Giai thich thong tin 1
                exp2 = _ceil(exp2_temp);
                ensureExp(exp2);

                exp2_temp = exp2 + (e1 / 9.0 + 21);  // Giai thich thong tin 2
                exp2 = _ceil(exp2_temp);
                ensureExp(exp2);

                if (400 < exp2) {
                    exp2_temp = exp2 + (e1 / 16.0 + 17);  // Giai thich thong tin 3
                    exp2 = _ceil(exp2_temp);
                    ensureExp(exp2);
                    exp2_temp = exp2 * 1.15;
                }
        }
        exp2 = _ceil(exp2_temp);
        ensureExp(exp2);
        exp1 = exp1 - e1;
        ensureExp(exp1);
    }

    return exp1 + exp2;
}

// Task 2
int squareNumber(int exp) {
    int nearest;
    double squareRoot;
    for (int i = 0;; i++) {
        nearest = exp + i;
        squareRoot = sqrt(nearest);
        if (squareRoot - (int)squareRoot == 0) {  ///////////////////////
            return nearest;
        }

        nearest = exp - i;
        squareRoot = sqrt(nearest);
        if (squareRoot - (int)squareRoot == 0) {  ///////////////////////////////
            return nearest;
        }
    }
}

void ensureHP(int& hp) {
    if (666 < hp) {
        hp = 666;
    } else if (hp < 0) {
        hp = 0;
    }
}

void ensureMoney(int& m) {
    if (3000 < m) {
        m = 3000;
    } else if (m < 0) {
        m = 0;
    }
}

bool overHalfMoney(int halfMoney, int sumMoney) {
    return halfMoney < sumMoney;
}

bool overMoney(int M1) {
    return M1 <= 0;
}

bool canWalk(int halfMoney, int sumMoney, int M1, int E2) {
    return (E2 % 2 != 0 && overHalfMoney(halfMoney, sumMoney)) || (E2 % 2 == 0 && overMoney(M1));
}

void startWalk(int& HP1, int& EXP1) {
    double hp1_temp;
    double exp1_temp;
    hp1_temp = HP1 * 0.83;
    HP1 = _ceil(hp1_temp);
    ensureHP(HP1);
    exp1_temp = EXP1 * 1.17;
    EXP1 = _ceil(exp1_temp);
    ensureExp(EXP1);
}

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    double p1, p2, p3;
    // Con duong 1
    int s = squareNumber(EXP1);
    if (s <= EXP1) {
        p1 = 1;
    } else {
        p1 = ((EXP1 / s) + 80) / 123.0;
    }

    // Con duong 2
    double exp1_temp;
    double hp1_temp;
    int halfMoney = M1 / 2;  // Lam tron xuong ///////////////////////////
    int sumMoney = 0;

    do {
        // Su kien 1
        if (HP1 < 200) {
            hp1_temp = HP1 * 1.3;
            M1 -= 150;
            sumMoney += 150;
        } else {
            hp1_temp = HP1 * 1.1;
            M1 -= 70;
            sumMoney += 70;
        }

        // cout << "hp1_temp: " << fixed << setprecision(20) << hp1_temp << endl;

        // double num = 139.999999;
        // cout << "num: " << fixed << setprecision(40) << num << endl;

        // int nhap = __ceil(num);
        // cout << "nhap: " << nhap << endl;

        HP1 = _ceil(hp1_temp);  ///////////////////////////////////////// SAI ROI NE
        ensureHP(HP1);
        ensureMoney(M1);

        // cout << "HP1: " << HP1 << endl;

        if (canWalk(halfMoney, sumMoney, M1, E2)) {
            startWalk(HP1, EXP1);
            break;
        }

        // Su kien 2
        if (EXP1 < 400) {
            M1 -= 200;
            sumMoney += 200;
        } else {
            M1 -= 120;
            sumMoney += 120;
        }
        ensureMoney(M1);
        exp1_temp = EXP1 * 1.13;
        EXP1 = _ceil(exp1_temp);
        ensureExp(EXP1);

        if (canWalk(halfMoney, sumMoney, M1, E2)) {
            startWalk(HP1, EXP1);
            break;
        }

        // Su kien 3
        if (EXP1 < 300) {
            M1 -= 100;
            sumMoney += 100;
        } else {
            M1 -= 120;
            sumMoney += 120;
        }
        ensureMoney(M1);
        exp1_temp = EXP1 * 0.9;
        EXP1 = _ceil(exp1_temp);
        ensureExp(EXP1);

        if (canWalk(halfMoney, sumMoney, M1, E2) || E2 % 2 == 0) {
            startWalk(HP1, EXP1);
            break;
        }

    } while (E2 % 2 != 0);  // Da doc toi day

    s = squareNumber(EXP1);  // Tinh p2 sau khi hoan thanh 3 su kien cua con duong 2
    if (s <= EXP1) {
        p2 = 1;
    } else {
        p2 = ((EXP1 / s) + 80) / 123.0;
    }

    // Con duong 3
    int p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10) {
        p3 = p[E2] / 100.0;
    } else {
        double sum = (E2 / 10) + (E2 / 10.0 - E2 / 10) * 10;
        if (9 < sum) {
            sum = (sum / 10 - int(sum / 10)) * 10.0;  //////////////////////////
        }
        p3 = p[(int)round(sum)] / 100.0;
    }

    // Tinh xac suat sau khi hoan thanh 3 con duong
    if (p1 == 1 && p2 == 1 && p3 == 1) {
        exp1_temp = EXP1 * 0.75;
        EXP1 = _ceil(exp1_temp);
        ensureExp(EXP1);
    } else {
        double pTB = (p1 + p2 + p3) / 3.0;
        if (pTB < 0.5) {
            hp1_temp = HP1 * 0.85;
            HP1 = _ceil(hp1_temp);
            ensureHP(HP1);

            exp1_temp = EXP1 * 1.15;
            EXP1 = _ceil(exp1_temp);
            ensureExp(EXP1);
        } else {
            // cout << "HP1_before: " << HP1 << endl;
            hp1_temp = HP1 * 0.9;
            // cout << "hp1_temp: " << hp1_temp << endl;
            HP1 = _ceil(hp1_temp);
            ensureHP(HP1);

            // cout << "HP1: " << HP1 << endl;

            exp1_temp = EXP1 * 1.2;
            EXP1 = _ceil(exp1_temp);
            ensureExp(EXP1);
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    // Khoi tao ma tran 10 x 10
    int matrix[10][10];
    int countBigNumber = 0;
    int countSmallNumber = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (E3 * 2 < matrix[i][j]) {
                countBigNumber++;
            }
            if (matrix[i][j] < -E3) {
                countSmallNumber++;
            }
        }
    }

    // Tim vi tri taxi va diem cua taxi
    int ipos = countBigNumber;
    int jpos = countSmallNumber;
    while (9 < ipos) {
        ipos = round((ipos / 10) + (ipos / 10.0 - ipos / 10) * 10);
    }
    while (9 < jpos) {
        jpos = round(jpos / 10 + (jpos / 10.0 - jpos / 10) * 10);
    }
    int taxiScore = matrix[ipos][jpos];

    // Tim diem cua Sherlock va Waston
    int max = matrix[ipos][jpos];
    // Tim max ben tren duong cheo trai
    for (int i = 1; ipos - i >= 0 && jpos - i >= 0; i++) {
        int score = matrix[ipos - i][jpos - i];
        if (max < score) {
            max = score;
        }
    }

    // Tim max ben duoi duong cheo trai
    for (int i = 1; ipos + i <= 9 && jpos + i <= 9; i++) {
        int score = matrix[ipos + i][jpos + i];
        if (max < score) {
            max = score;
        }
    }

    // Tim max ben tren duong cheo phai
    for (int i = 1; ipos - i >= 0 && jpos + i <= 9; i++) {
        int score = matrix[ipos - i][jpos + i];
        if (max < score) {
            max = score;
        }
    }

    // Tim max ben duoi duong cheo phai
    for (int i = 1; ipos + i <= 9 && jpos - i >= 0; i++) {
        int score = matrix[ipos + i][jpos - i];
        if (max < score) {
            max = score;
        }
    }
    int sherlockScore = abs(max);

    // Tinh EXP va HP cua Sherlock va Waston
    double exp1_temp, exp2_temp;
    double hp1_temp, hp2_temp;
    if (abs(taxiScore) > sherlockScore) {  // Khong duoi kip taxi
        exp1_temp = EXP1 * 0.88;
        exp2_temp = EXP2 * 0.88;
        hp1_temp = HP1 * 0.9;
        hp2_temp = HP2 * 0.9;
    } else {  // Duoi kip taxi
        exp1_temp = EXP1 * 1.12;
        exp2_temp = EXP2 * 1.12;
        hp1_temp = HP1 * 1.1;
        hp2_temp = HP2 * 1.1;
    }
    EXP1 = _ceil(exp1_temp);
    EXP2 = _ceil(exp2_temp);
    HP1 = _ceil(hp1_temp);
    HP2 = _ceil(hp2_temp);

    ensureExp(EXP1);
    ensureExp(EXP2);
    ensureHP(HP1);
    ensureHP(HP2);

    return abs(taxiScore) > sherlockScore ? taxiScore : sherlockScore;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    // Lay duoc chuoi se
    int seLen = 0;
    for (int i = 0; email[i] != '@'; i++) {
        seLen++;
    }
    char* se = new char[seLen + 1];
    for (int i = 0; i < seLen; i++) {
        se[i] = email[i];
    }
    se[seLen] = '\0';

    // Kiem tra do dai
    int sLen = strlen(s);
    if (sLen < 8) {
        delete[] se;
        return -1;
    } else if (sLen > 20) {
        delete[] se;
        return -2;
    }

    // Kiem tra s co chua se hay khong
    bool isContainSe = false;
    int j = 0;
    int sePos;
    for (int i = 0; i < sLen; i++) {
        if (s[i] == se[j]) {
            if (j == seLen - 1) {
                isContainSe = true;
                sePos = i - seLen + 1;
                break;
            }
            j++;
        } else {
            j = 0;
        }
    }
    if (isContainSe) {
        delete[] se;
        return -(300 + sePos);
    }

    // Kiem tra co chua nhieu hon 2 ki tu lien tiep
    int count = 1;
    bool isSameChar = false;
    int charPos;
    for (int i = 0; i < sLen - 1; i++) {
        if (s[i] == s[i + 1]) {
            count++;
            if (count == 3) {
                isSameChar = true;
                charPos = i - 1;
                break;
            }
        } else {
            count = 1;
        }
    }
    if (isSameChar) {
        delete[] se;
        return -(400 + charPos);
    }

    // Kiem tra ki tu dac biet
    bool isSpecialChar = false;
    for (int i = 0; i < sLen; i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '!' || s[i] == '$') {
            isSpecialChar = true;
            break;
        }
    }
    if (!isSpecialChar) {
        delete[] se;
        return -5;
    }

    // Kiem tra truong hop con lai
    for (int i = 0; i < sLen; i++) {
        if (('0' <= s[i] && s[i] <= '9') || ('@' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] & s[i] <= 'z') || ('#' <= s[i] && s[i] <= '%') || s[i] == '!') {
            continue;
        }
        delete[] se;
        return i;
    }

    delete[] se;
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    // Mang luu so lan xuat hien cua tung chuoi
    int* countAppear = new int[num_pwds];

    for (int i = 0; i < num_pwds; i++) {
        int count = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }
        countAppear[i] = count;
    }

    // Tim so lan xuat hien cao nhat
    int maxAppear = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (countAppear[i] > maxAppear) {
            maxAppear = countAppear[i];
        }
    }

    // Tao mang luu chieu dai cua chuoi xuat hien nhieu nhat
    int* lenMaxAppear = new int[num_pwds];
    for (int i = 0; i < num_pwds; i++) {
        if (countAppear[i] == maxAppear) {
            lenMaxAppear[i] = strlen(arr_pwds[i]);
        } else {
            lenMaxAppear[i] = 0;
        }
    }

    // Tim do dai lon nhat trong cac chuoi xuat hien nhieu nhat
    int maxLen = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (lenMaxAppear[i] > maxLen) {
            maxLen = lenMaxAppear[i];
        }
    }

    // Tim vi tri dau tien cua mat khau
    int posPassword;
    for (int i = 0; i < num_pwds; i++) {
        if (lenMaxAppear[i] == maxLen) {
            posPassword = i;
            break;
        }
    }

    delete[] countAppear;
    delete[] lenMaxAppear;
    return posPassword;
}

// END OF STUDENT'S ANSWER
