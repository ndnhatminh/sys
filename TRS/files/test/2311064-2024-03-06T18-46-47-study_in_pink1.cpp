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
int limitValue(int valuee, int minVal, int maxVal) {
    if (valuee < minVal) {
        return minVal;
    }
    else if (valuee > maxVal) {
        return maxVal;
    }
    else {
        return valuee;
    }
}
// Hàm tính toán chỉ số sức khoẻ HP
int calculateHP(int HP) {
    return limitValue(HP, 0, 666);
}

// Hàm tính toán chỉ số kinh nghiệm EXP
int calculateEXP(int EXP) {
    return limitValue(EXP, 0, 600);
}

// Hàm tính toán số tiền M
int calculateMoney(int money) {
    return limitValue(money, 0, 3000);
}

// Hàm tính toán mã sự kiện E
int calculateEvent(int event) {
    return limitValue(event, 0, 99);
}
int case1(int& EXP1, int& EXP2, int E1) {
    float EXP1_1, EXP2_2;
    switch (E1)
    {
    case 0:
        EXP2 += 29;
        EXP2 = calculateEXP(EXP2);
        break;
    case 1:
        EXP2 += 45;
        EXP2 = calculateEXP(EXP2);
        break;
    case 2:
        EXP2 += 75;
        EXP2 = calculateEXP(EXP2);
        break;
    case 3:
        EXP2 = EXP2 + 29 + 45 + 75;
        EXP2 = calculateEXP(EXP2);
        break;
    }
    int D = E1 * 3 + EXP1 * 7;
    if (D % 2 == 0) {
        EXP1_1 = EXP1 + 1.0 * D / 200;
        EXP1 = calculateEXP(ceil(EXP1_1));
    }
    else {
        EXP1_1 = EXP1 - 1.0 * D / 100;
        EXP1 = calculateEXP(ceil(EXP1_1));
    }
    return EXP1 + EXP2;
}//nontested

int case2(int& EXP1, int& EXP2, int E1) {
    float EXP1_1, EXP2_2;
    if (E1 >= 4 && E1 <= 19) {
        EXP2_2 = EXP2 + 1.0 * E1 / 4 + 19; // Th2 case 1
        EXP1 = EXP1 - E1;
        EXP2 = calculateEXP(ceil(EXP2_2));
        EXP1 = calculateEXP(EXP1);
    }
    else if (E1 >= 20 && E1 <= 49) {
        EXP2_2 = EXP2 + 1.0 * E1 / 9 + 21;
        EXP1 = EXP1 - E1;
        EXP2 = calculateEXP(ceil(EXP2_2));
        EXP1 = calculateEXP(EXP1);
    }
    else if (E1 >= 50 && E1 <= 65) {
        EXP2_2 = EXP2 + 1.0 * E1 / 16 + 17; // TH2 case 3
        EXP2 = calculateEXP(ceil(EXP2_2));
        EXP1 -= E1;
        EXP1 = calculateEXP(EXP1);
    }
    else if (E1 >= 66 && E1 <= 79) {
        EXP2_2 = EXP2 + 1.0 * E1 / 4 + 19;
        EXP2 = calculateEXP(ceil(EXP2_2));
        EXP1 -= E1;
        EXP1 = calculateEXP(EXP1);
        if (EXP2 > 200) {
            EXP2_2 = EXP2 + 1.0 * E1 / 9 + 21;
            EXP2 = calculateEXP(ceil(EXP2_2));
        }
    }
    if (E1 >= 80 && E1 <= 99) {
        EXP2_2 = EXP2 + 1.0 * E1 / 4 + 19;
        EXP2_2 = EXP2_2 + 1.0 * E1 / 9 + 21;
        EXP2 = calculateEXP(ceil(EXP2_2));
        EXP1 -= E1;
        EXP1 = calculateEXP(ceil(EXP1));
        if (EXP2 > 400)
        {
            EXP2_2 = EXP2 + 1.0 * E1 / 16 + 17;
            EXP2_2 = EXP2_2 * 1.15;
            EXP2 = calculateEXP(ceil(EXP2_2));
        }
    }
    return EXP1 + EXP2;
}//nontested
int firstMeet(int& EXP1, int& EXP2, int E1) {
    if (E1 >= 0 && E1 <= 3)
        return case1(EXP1, EXP2, E1);
    else
        return case2(EXP1, EXP2, E1);

}
int S(int n, int& EXP1) {
    n = pow(ceil((float)sqrt(EXP1)), 2);
    return n;
}
int n;
double road1(int& EXP1) {
    double P1;
    if (EXP1 >= S(n, EXP1)) {
        P1 = 100;
    }
    else {
        P1 = (1.0 * EXP1 / S(n, EXP1) + 80) / 1.23;
    }
    //cout << "P1 = " << P1 << endl;
    return P1;
}

double road2(int& HP1, int& EXP1, int& M1, int E2) {
    int moneySpent = 0; // 890
    if (HP1 < 200) {
        HP1 = calculateHP(ceil((float)HP1 * 1.3));
        moneySpent += 150;
    }
    else {
        HP1 = calculateHP(ceil((float)HP1 * 1.1));
        moneySpent += 70;// 820
    }

    if (EXP1 < 400) {
        moneySpent += 200;
        EXP1 = calculateEXP(ceil((float)EXP1 * 1.13));
    }
    else {
        moneySpent += 120; // 700
        EXP1 = calculateEXP(ceil((float)EXP1 * 1.13));
    }

    if (EXP1 < 300) {
        moneySpent += 100;
    }
    else {
        moneySpent += 120;//580
        EXP1 = calculateEXP(ceil((float)EXP1 * 0.9));
    }

    if (E2 % 2 == 0) {
        M1 = calculateMoney(M1 - moneySpent);
        if (M1 == 0) {
            HP1 = calculateHP(ceil((float)HP1 * 0.83));
            EXP1 = calculateEXP(ceil((float)EXP1 * 1.17));
        }
        else {
            HP1 = calculateHP(ceil((float)HP1 * 0.83));
            EXP1 = calculateEXP(ceil((float)EXP1 * 1.17));
        }
    }
    else if (E2 % 2 != 0 && M1 > 0) {
        while (E2 % 2 != 0 && M1 > 0) {

            if (HP1 < 200) {
                HP1 = calculateHP(ceil((float)HP1 * 1.3));
                moneySpent += 150;
            }
            else {
                HP1 = calculateHP(ceil((float)HP1 * 1.1));
                moneySpent += 70;//510
            }

            // Sự kiện 2
            if (EXP1 < 400) {
                moneySpent += 200;
                EXP1 = calculateEXP(ceil((float)EXP1 * 1.13));
            }
            else {
                moneySpent += 120;//390
                EXP1 = calculateEXP(ceil((float)EXP1 * 1.13));
            }

            if (moneySpent > 0.5 * M1) {
                HP1 = calculateHP(ceil((float)HP1 * 0.83));
                EXP1 = calculateEXP(ceil((float)EXP1 * 1.17));
                break;
            }
        }
    }
    double P2;
    if (EXP1 >= S(n, EXP1)) {
        P2 = 100;
    }
    else {
        P2 = (1.0 * EXP1 / S(n, EXP1) + 80) / 1.23;
    }
    M1 = calculateMoney(M1 - moneySpent);

    return P2;
}
double road3(int E2) {
    double P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    // Tính chỉ số i
    int i;
    if (E2 < 10) {
        i = E2;
    }
    else {
        int sum = (E2 / 10) + (E2 % 10);
        i = sum % 10;
    }
    double P3 = P[i];
    //cout << "P3 = " << P3 << endl;
    return P3;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    double P = (road1(EXP1) + road2(HP1, EXP1, M1, E2) + road3(E2)) / 3;
    // cout << "P = " << P << endl;
    if (P == 100) {
        while (P == 100) {
            EXP1 = calculateEXP(ceil((float)EXP1 * 0.75));
            P = (road1(EXP1) + road2(HP1, EXP1, M1, E2) + road3(E2)) / 3;
            if (P != 100) {
                break;
            }
        }
    }
    if (P < 50) {
        HP1 = calculateHP(ceil((float)HP1 * 0.85)); // Làm tròn giá trị của HP1
        EXP1 = calculateEXP(ceil((float)EXP1 * 1.15));
    }
    else {
        HP1 = calculateHP(ceil((float)HP1 * 0.9)); // Làm tròn giá trị của HP1
        EXP1 = calculateEXP(ceil((float)EXP1 * 1.2));
    }

    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    int mapPoints[10][10] = {};

    for (int k = 0; k < 10; k++) {
        for (int j = 0; j < 10; j++) {
            mapPoints[k][j] = (k - j) * ((E3 * j) + (k * 2));
        }
    }

    int yang = 0;
    int yin = 0;

    for (int k = 0; k < 10; k++) {
        for (int j = 0; j < 10; j++) {
            if (mapPoints[k][j] > (E3 * 2)) {
                yang++;
            }
            else if (mapPoints[k][j] < (-E3)) {
                yin++;
            }
        }
    }

    while (yang >= 10) {
        yang = yang % 10 + yang / 10;
    }

    while (yin >= 10) {
        yin = yin % 10 + yin / 10;
    }

    int taxiPoints = mapPoints[yang][yin];
    int sherlock = mapPoints[yang][yin];

    for (int k = yang, j = yin; k < 10 && j < 10; k++, j++) {
        if (mapPoints[k][j] > sherlock) {
            sherlock = mapPoints[k][j];
        }
    }

    for (int k = yang, j = yin; k < 10 && j >= 0; k++, j--) {
        if (mapPoints[k][j] > sherlock) {
            sherlock = mapPoints[k][j];
        }
    }

    for (int k = yang, j = yin; k >= 0 && j < 10; k--, j++) {
        if (mapPoints[k][j] > sherlock) {
            sherlock = mapPoints[k][j];
        }
    }

    for (int k = yang, j = yin; k >= 0 && j >= 0; k--, j--) {
        if (mapPoints[k][j] > sherlock) {
            sherlock = mapPoints[k][j];
        }
    }
    if (abs(sherlock) > abs(taxiPoints)) {
        return sherlock;
    }
    else {
        return taxiPoints;
    }
}
// Task 4
int checkPassword(const char* s, const char* email) {
    string se = string(email).substr(0, string(email).find('@'));  // Lấy chuỗi se từ email

    if (strlen(s) < 8)
        return -1;  // Độ dài ngắn hơn độ dài tối thiểu

    if (strlen(s) > 20)
        return -2;  // Độ dài dài hơn độ dài tối đa

    if (string(s).find(se) != string::npos)
        return -static_cast<int>(300 + string(s).find(se));  // Chứa chuỗi se

    char prev = '\0';
    int consecutive = 0;
    bool SpecialChar = false;

    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];

        if (!isalnum(c) && c != '@' && c != '#' && c != '%' && c != '$' && c != '!')
            return i;  // Ký tự không hợp lệ

        if (!SpecialChar && (c == '@' || c == '#' || c == '%' || c == '$' || c == '!'))
            SpecialChar = true;

        if (c == prev) {
            consecutive++;
            if (consecutive > 2)
                return -(400 + i);  // Nhiều hơn 2 ký tự liên tiếp và giống nhau
        }
        else {
            prev = c;
            consecutive = 1;
        }
    }

    if (!SpecialChar)
        return -5;  // Không chứa ký tự đặc biệt

    return -10;  // Mật khẩu hợp lệ
}

// Task 5

#define LM 30

int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    string maxcountpassword;
    int maxcount = 0;

    for (int t = 0; t < num_pwds; t++) {
        int count = 0;
        for (int v = 0; v < num_pwds; v++)
            if (arr_pwds[t] == arr_pwds[v])
                count++;
        if (count > maxcount || (count == maxcount && strlen(arr_pwds[t]) > maxcountpassword.length())) {
            maxcount = count;
            maxcountpassword = arr_pwds[t];
        }
    }

    for (int t = 0; t < num_pwds; t++)
        if (arr_pwds[t] == maxcountpassword)
            return t;

    return -1;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////