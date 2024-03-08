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

//Function CheckHP, CheckEXP, CheckMoney
void CheckHP(int& HP) {
    if (HP > 666) { HP = 666; }
    if (HP < 0) { HP = 0; }
}

void CheckEXP(int& EXP) {
    if (EXP > 600) { EXP = 600; }
    if (EXP < 0) { EXP = 0; }
}

void CheckMoney(int& M) {
    if (M > 3000) { M = 3000; }
    if (M < 0) { M = 0; }
}

void ThayDoi(int& m, double n) {

    m = ceil((double)(m + (n - 1) * m));
}
//Hàm phụ Task1
void Task1_D1(int& exp2, int e1) {
    float temp = exp2 + e1 / 4.0 + 19;
    exp2 = ceil(temp);
    CheckEXP(exp2);
}

void Task1_D2(int& exp2, int e1) {
    float temp = exp2 + e1 / 9.0 + 21;
    exp2 = ceil(temp);
    CheckEXP(exp2);
}

void Task1_D3(int& exp2, int e1) {
    float temp = exp2 + e1 / 16.0 + 17;
    exp2 = ceil(temp);
    CheckEXP(exp2);
}


// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    if (e1 > 99 || e1 < 0) { return -99; }
    CheckEXP(exp1);
    CheckEXP(exp2);
    //Trường hợp e1 thuộc đoạn [0,3], Sherlock (exp1) mô tả làm thay đổi EXP của Watson (exp2)
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) {
            exp2 += 29;
            CheckEXP(exp2);
        }
        if (e1 == 1) {
            exp2 += 45;
            CheckEXP(exp2);
        }
        if (e1 == 2) {
            exp2 += 75;
            CheckEXP(exp2);
        }
        if (e1 == 3) {
            exp2 += 149; //29+47+75=149
            CheckEXP(exp2);
        }
        int D = 3 * e1 + 7 * exp1;
        if (D % 2 == 0) {
            float temp1 = exp1 + D / 200.0;
            exp1 = ceil(temp1);
            CheckEXP(exp1);
        }
        else {
            float temp2 = exp1 - D / 100.0;
            exp1 = ceil(temp2);
            CheckEXP(exp1);
        }
    }
    //Trường hợp e2 thuộc đoạn [4,99], Sherlock (exp1) mô tả làm thay đổi EXP của Watson (exp2)
    if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) { Task1_D1(exp2, e1); }
        else if (e1 <= 49) { Task1_D2(exp2, e1); }
        else if (e1 <= 65) { Task1_D3(exp2, e1); }
        else if (e1 <= 79) {
            Task1_D1(exp2, e1);
            if (exp2 > 200) { Task1_D2(exp2, e1); }
        }
        else {
            Task1_D1(exp2, e1);
            Task1_D2(exp2, e1);
            if (exp2 > 400) {
                Task1_D3(exp2, e1);
                ThayDoi(exp2, 1.15f);
                CheckEXP(exp2);
            }
        }
        exp1 -= e1; //Do shock nên exp1 bị giảm e1
        CheckEXP(exp1);
    }
    return exp1 + exp2;
}

//Hàm phụ Task2:
//Hàm phụ Task2:
bool ifNearBy(int n) {
    int s = sqrt(n);
    int abs1 = n - s * s;
    int abs2 = (s + 1) * (s + 1) - n;
    if (abs2 > abs1) { return true; }
    else { return false; }
}

void Task2_R2(int& M1, int& HP1, int& EXP1, float condition) {
    if (M1 >= condition) {
        //Đoạn 1: Mua nước và đồ ăn
        if (HP1 < 200) {
            ThayDoi(HP1, 1.3f);
            CheckHP(HP1);
            M1 -= 150;
            CheckMoney(M1);
        }
        else {
            ThayDoi(HP1, 1.1f);
            CheckHP(HP1);
            M1 -= 70;
            CheckMoney(M1);
        }
    }
    if (M1 >= condition) {
        //Đoạn 2: Đi xe ngựa hay xe taxi
        if (EXP1 < 400) { M1 -= 200; }
        else { M1 -= 120; }
        CheckMoney(M1);
        ThayDoi(EXP1, 1.13f);
        CheckEXP(EXP1);
    }
    if (M1 >= condition) {
        //Đoạn 3: Hỏi người vô gia cư
        if (EXP1 < 300) { M1 -= 100; }
        else { M1 -= 120; }
        CheckMoney(M1);
        ThayDoi(EXP1, 0.9f);
        CheckEXP(EXP1);
    }
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 > 99 || E2 < 0) { return -99; }
    else {
        CheckMoney(M1);
        CheckHP(HP1);
        CheckEXP(EXP1);
        //Con đường 1:
        float P1;
        if (ifNearBy(EXP1)) { P1 = 1; }
        else { P1 = (EXP1 / (pow((int)(sqrt(EXP1) + 1), 2)) + 80.0) / 123.0; } //chia cho số chính phương lớn hơn EXP1
        //Con đường 2:
        int FirstM = M1;
        //Nếu E3 chẵn thì thực hiện đúng 1 lần, Nếu E3 lẻ thì thực hiện đến khi nào số tiền còn lại nhỏ hơn 50% số tiền ban đầu
        if (E2 % 2 == 0 || FirstM == 0) {
            Task2_R2(M1, HP1, EXP1, 1);
            ThayDoi(EXP1, 1.17f);
            CheckEXP(EXP1);
            ThayDoi(HP1, 0.83f);
            CheckHP(HP1);
        }
        else {
            while (M1 >= FirstM / 2) { Task2_R2(M1, HP1, EXP1, FirstM / 2.0); }
            ThayDoi(EXP1, 1.17f);
            CheckEXP(EXP1);
            ThayDoi(HP1, 0.83f);
            CheckHP(HP1);
        }
        float P2;
        if (ifNearBy(EXP1)) { P2 = 1; }
        else { P2 = (EXP1 / (pow((int)(sqrt(EXP1) + 1), 2)) + 80) / 123; }
        //Con đường 3:
        int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        float P3;
        if (E2 < 10) {
            P3 = P[E2] / 100.0;
        }
        else {
            P3 = P[(E2 / 10 + E2 % 10) % 10] / 100.0;
        }
        //Sau khi đi 3 tuyến đường:
        if (P1 == 1 && P2 == 1 && P3 == 1) {
            ThayDoi(EXP1, 0.75f);
        }
        else {
            float Ptrung = (P1 + P2 + P3) / 3;
            if (Ptrung < 0.5) {
                ThayDoi(HP1, 0.85f);
                ThayDoi(EXP1, 1.15f);
                CheckEXP(EXP1);
                CheckHP(HP1);
            }
            else {
                ThayDoi(HP1, 0.9f);
                ThayDoi(EXP1, 1.2f);
                CheckEXP(EXP1);
                CheckHP(HP1);
            }
        }
        return HP1 + EXP1 + M1;
    }
}


//Hàm phụ Task3
int MaxCheoTrai(int Matrix[10][10], int i, int j) {
    int MaxCheoTrai = Matrix[i][j];
    int Curri = i;
    int Currj = j;
    while (Curri < 10 && Currj < 10) {
        MaxCheoTrai = max(MaxCheoTrai, Matrix[Curri][Currj]);
        Curri++;
        Currj++;
    }
    Curri = i;
    Currj = j;
    while (Curri >= 0 && Currj >= 0) {
        MaxCheoTrai = max(MaxCheoTrai, Matrix[Curri][Currj]);
        Curri--;
        Currj--;
    }
    return MaxCheoTrai;
}
int MaxCheoPhai(int Matrix[10][10], int i, int j) {
    int MaxCheoPhai = Matrix[i][j];
    int Curri = i;
    int Currj = j;
    while (Curri < 10 && Currj < 10 && Curri >= 0 && Currj >= 0) {
        MaxCheoPhai = max(MaxCheoPhai, Matrix[Curri][Currj]);
        Curri++;
        Currj--;
    }
    Curri = i;
    Currj = j;
    while (Curri < 10 && Currj < 10 && Curri >= 0 && Currj >= 0) {
        MaxCheoPhai = max(MaxCheoPhai, Matrix[Curri][Currj]);
        Curri--;
        Currj++;
    }
    return MaxCheoPhai;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (E3 > 99 || E3 < 0) { return -99; }
    CheckHP(HP1);
    CheckHP(HP2);
    CheckEXP(EXP1);
    CheckEXP(EXP2);
    //Khởi tạo ma trận và gán giá trị:
    int Matrix[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            Matrix[i][j] = (E3 * j + 2 * i) * (i - j);;
        }
    }
    int cnti = 0;
    int cntj = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (Matrix[i][j] > 2 * E3) { cnti++; }
            if (Matrix[i][j] < 0 - E3) { cntj++; }
        }
    }
    while (cnti >= 10) { cnti = cnti / 10 + cnti % 10; }
    while (cntj >= 10) { cntj = cntj / 10 + cntj % 10; }
    int result;
    //Vị trí gặp nhau tại (i,j)
    int SherlockP = max(MaxCheoTrai(Matrix, cnti, cntj), MaxCheoPhai(Matrix, cnti, cntj));
    if (abs(Matrix[cnti][cntj]) > abs(SherlockP)) {
        result = Matrix[cnti][cntj];
        ThayDoi(EXP1, 0.88f);
        ThayDoi(EXP2, 0.88f);
        CheckEXP(EXP1);
        CheckEXP(EXP2);
        ThayDoi(HP1, 0.9f);
        ThayDoi(HP2, 0.9f);
        CheckHP(HP1);
        CheckHP(HP2);
    }
    else {
        result = SherlockP;
        ThayDoi(EXP1, 1.12f);
        ThayDoi(EXP2, 1.12f);
        CheckEXP(EXP1);
        CheckEXP(EXP2);
        ThayDoi(HP1, 1.10f);
        ThayDoi(HP2, 1.10f);
        CheckHP(HP1);
        CheckHP(HP2);
    }
    return result;
}
//Hàm phụ Task4:
bool KyTuDacBiet(const char* s) {
    bool contain = false;
    const char* KTDB = "@#%$!";
    while (*KTDB) {
        if (strchr(s, *KTDB)) {
            contain = true;
            break;
        }
        KTDB++;
    }
    return contain;
}
//Task 4
int checkPassword(const char* s, const char* email) {
    int passwordLength = strlen(s);
    const char* seCheck = strchr(email, '@');
    int seCheckLength = seCheck - email;
    char se[101];
    strncpy(se, email, seCheckLength);
    se[seCheckLength] = '\0';
    const char* pos = strstr(s, se);
    if (passwordLength < 8) {
        return -1;
    }
    else if (passwordLength > 20) {
        return -2;
    }
    else if (pos != nullptr) {
        return -(300 + (pos - s)); // Chứa chuỗi se
    }
    for (int i = 0; i < passwordLength - 2; i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            return -(400 + i); // Chứa nhiều hơn 2 ký tự liên tiếp
        }
    }
    if (!KyTuDacBiet(s)) {
        return -5; // Không chứa ký tự đặc biệt
    }
    else for (int i = 0; i < passwordLength; i++) {
        if ((s[i] < '0' || (s[i] > '9' && s[i] < 'A') || (s[i] > 'Z' && s[i] < 'a') || (s[i] > 'z')) && (s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!')) { return i; }
    }
    return -10;
}
// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    pair<const char*, int> passwordCounts[num_pwds];
    for (int i = 0; i < num_pwds; i++) {
        passwordCounts[i].first = arr_pwds[i];
        passwordCounts[i].second = 0;
    }
    for (int i = 0; i < num_pwds; i++) {
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(passwordCounts[i].first, arr_pwds[j]) == 0) {
                passwordCounts[i].second++;
            }
        }
    }
    const char* mostFrequentPassword = nullptr;
    int maxCount = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (passwordCounts[i].second > maxCount || (passwordCounts[i].second == maxCount && strlen(passwordCounts[i].first) > strlen(mostFrequentPassword))) {
            mostFrequentPassword = passwordCounts[i].first;
            maxCount = passwordCounts[i].second;
        }
    }
    for (int i = 0; i < num_pwds; i++) {
        if (strcmp(arr_pwds[i], mostFrequentPassword) == 0) {
            return i;
        }
    }
    return -1;
}


