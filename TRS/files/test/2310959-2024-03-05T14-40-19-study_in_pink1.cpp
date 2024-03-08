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
//Kiểm tra chỉ số sức khỏe (HP)
void Res_HP(int& HP) {
    if (HP < 0) HP = 0;
    else if (HP > 666) HP = 666;
}

void Res_EXP(int& EXP) {
    if (EXP < 0) EXP = 0;
    else if (EXP >= 600) EXP = 600;
}

void Res_M(int& M) {
    if (M < 0) M = 0;
    else if (M > 3000) M = 3000;
}

void Res_E(int& E) {
    if (E < 0 || E > 99) E = -99;
}

int SoNguyen_D(int& E1, int& EXP1) {
    float temp_EXP1;
    int D = E1 * 3 + EXP1 * 7;
    if (D % 2 == 0) {
        temp_EXP1 = static_cast<float>(EXP1) + static_cast<float>(D) / 200.0f;
        EXP1 = static_cast<int>(ceil(temp_EXP1));
        Res_EXP(EXP1);
        return EXP1;
    }
    else temp_EXP1 = static_cast<float>(EXP1) - static_cast<float>(D) / 100.0f;
    EXP1 = static_cast<int>(ceil(temp_EXP1));
    Res_EXP(EXP1);
    return EXP1;
}

int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    Res_E(e1);
    if (e1 == -99) return e1;
    else {
        Res_EXP(exp1);
        Res_EXP(exp2);
        if (e1 == 0) {
            exp2 += 29;
            Res_EXP(exp2);
            SoNguyen_D(e1, exp1);
        }
        else if (e1 == 1) {
            exp2 += 45;
            Res_EXP(exp2);
            SoNguyen_D(e1, exp1);
        }
        else if (e1 == 2) {
            exp2 += 75;
            Res_EXP(exp2);
            SoNguyen_D(e1, exp1);
        }
        else if (e1 == 3) {
            exp2 += 149;
            Res_EXP(exp2);
            SoNguyen_D(e1, exp1);
        }
        else {
            if (e1 >= 4 && e1 <= 19)       exp2 += ceil(e1 / 4.0 + 19);
            else if (e1 >= 20 && e1 <= 49) exp2 += ceil(e1 / 9.0 + 21);
            else if (e1 >= 50 && e1 <= 65) exp2 += ceil(e1 / 16.0 + 17);
            else if (e1 >= 66 && e1 <= 79) {
                exp2 += ceil(e1 / 4.0 + 19);
                if (exp2 > 200) exp2 += ceil(e1 / 9.0 + 21);
            }
            else if (e1 >= 80 && e1 <= 99)
            {
                exp2 += (ceil(e1 / 4.0 + 19) + ceil(e1 / 9.0 + 21));
                if (exp2 > 400) {
                    exp2 += ceil(e1 / 16.0 + 17);
                    exp2 += ceil(exp2 * 0.15);
                }
            }
            exp1 -= e1;
            Res_EXP(exp2);
            Res_EXP(exp1);
        }
        return exp1 + exp2;
    }
}
// Task 2
//Sự kiện 1 (NV2)
void SK1(int& HP, int& M, float& M_chitieu) {
    if (HP < 200) {
        HP += ceil(float(HP * 30.0 / 100));
        Res_HP(HP);
        M = M - 150;
        M_chitieu += 150;
        Res_M(M);
    }
    else {
        HP += ceil(float(HP * 10.0 / 100));
        Res_HP(HP);
        M = M - 70;
        M_chitieu += 70;
        Res_M(M);
    }
}
//Sự kiện 2 (NV2)
void SK2(int& EXP, int& M, float& M_chitieu) {
    if (EXP < 400) {
        M = M - 200;
        M_chitieu += 200;
        Res_M(M);
        EXP += ceil(float(EXP * 13.0 / 100));
        Res_EXP(EXP);
    }
    else {
        M = M - 120;
        M_chitieu += 120;
        Res_M(M);
        EXP += ceil(float(EXP * 13.0 / 100));
        Res_EXP(EXP);
    }
}
//Sự kiện 3 (NV2)
void SK3(int& EXP, int& M, float& M_chitieu) {
    if (EXP < 300) {
        M = M - 100;
        M_chitieu += 100;
        Res_M(M);
        EXP = ceil(float(EXP * 90.0 / 100));
        Res_EXP(EXP);
    }
    else {
        M = M - 120;
        M_chitieu += 120;
        Res_M(M);
        EXP = ceil(float(EXP * 90.0 / 100));
        Res_EXP(EXP);
    }
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    Res_E(E2);
    if (E2 == -99) return -99;
    else {
        Res_EXP(EXP1);
        Res_HP(HP1);
        Res_M(M1);
        float temp_1 = pow(round(sqrt(EXP1)), 2);
        float P1;
        if (temp_1 <= EXP1) {
            P1 = 100;
        }
        else {
            P1 = (EXP1 / temp_1 + 80) / 123.0;
        }
        //Con đường 2
        float M_bandau = M1;
        float M_chitieu = 0;
        while (E2 % 2 == 1) {
            SK1(HP1, M1, M_chitieu);
            if (M_bandau / 2 < M_chitieu) break;
            SK2(EXP1, M1, M_chitieu);
            if (M_bandau / 2 < M_chitieu) break;
            SK3(EXP1, M1, M_chitieu);
            if (M_bandau / 2 < M_chitieu) break;
        }
        while (E2 % 2 == 0) {
            SK1(HP1, M1, M_chitieu);
            if (M1 <= 0) break;
            SK2(EXP1, M1, M_chitieu);
            if (M1 <= 0) break;
            SK3(EXP1, M1, M_chitieu);
            break;
        }
        HP1 = ceil(float(HP1 * 83.0 / 100));
        EXP1 += ceil(float(EXP1 * 17.0 / 100));
        Res_HP(HP1);
        Res_EXP(EXP1);
        float temp_2 = pow(round(sqrt(EXP1)), 2);
        float P2;
        if (temp_2 <= EXP1) {
            P2 = 100;
        }
        else {
            P2 = (EXP1 / temp_2 + 80) / 123.0;
        }
        //Con đường 3
        int Pi;
        int arr_P[10] = { 32,47,28,79,100,50,22,83,64,11 };
        if (0 <= E2 && E2 <= 9) Pi = arr_P[E2];
        else {
            int temp = E2 % 10 + (E2 / 10) % 10;
            Pi = arr_P[temp];
        }
        //Summary
        float P_S;
        if (P1 == 100 && P2 == 100 && Pi == 100) {
            EXP1 = ceil(float(EXP1 * 75.0 / 100));
            Res_EXP(EXP1);
        }
        else {
            P_S = (P1 + P2 + Pi) / 3.0;
            if (P_S < 0.5) {
                HP1 = ceil(float(HP1 * 85.0 / 100));
                Res_HP(HP1);
                EXP1 += ceil(float(EXP1 * 15.0 / 100));
                Res_EXP(EXP1);
            }
            else {
                HP1 = ceil(float(HP1 * 90.0 / 100));
                Res_HP(HP1);
                EXP1 += ceil(float(EXP1 * 20.0 / 100));
                Res_EXP(EXP1);
            }
        }
        return HP1 + EXP1 + M1;
    }
}
// Task 3
int Row_NumFind(int& E3) {
    int arr1[10][10];
    int count = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr1[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr1[i][j] > E3 * 2) count++;
            else;
        }
    }
    while (count > 9) {
        count = count % 10 + count / 10;
    }
    return count;
}
int Col_NumFind(int& E3) {
    int arr2[10][10];
    int count = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr2[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr2[i][j] < (-1) * E3) count++;
            else;
        }
    }
    while (count > 9) {
        count = count % 10 + count / 10;
    }
    return count;
}
int Max_CheoTrai(int& E3, int& row, int& col) {
    int i1 = row;
    int j1 = col;
    int i2 = row;
    int j2 = col;
    int arr3[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr3[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int Max = arr3[i1][j1];
    while (i1 >= 0 && j1 >= 0) {
        if (Max <= arr3[i1][j1]) {
            Max = arr3[i1][j1];
            i1--;
            j1--;
        }
        else {
            i1--;
            j1--;
        }
    }
    while (i2 <= 9 && j2 <= 9) {
        if (Max <= arr3[i2][j2]) {
            Max = arr3[i2][j2];
            i2++;
            j2++;
        }
        else {
            i2++;
            j2++;
        }
    }
    return Max;
}
int Max_CheoPhai(int& E3, int& row, int& col) {
    int i1 = row;
    int j1 = col;
    int i2 = row;
    int j2 = col;
    int arr3[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr3[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int Max = arr3[i1][j1];
    while (i1 >= 0 && j1 <= 9) {
        if (Max <= arr3[i1][j1]) {
            Max = arr3[i1][j1];
            i1--;
            j1++;
        }
        else {
            i1--;
            j1++;
        }
    }
    while (i2 <= 9 && j2 >= 0) {
        if (Max <= arr3[i2][j2]) {
            Max = arr3[i2][j2];
            i2++;
            j2--;
        }
        else {
            i2++;
            j2--;
        }
    }
    return Max;
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    int arr[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    Res_E(E3);
    if (E3 == -99) return -99;
    else {
        float temp_EXP1, temp_EXP2, temp_HP1, temp_HP2;
        int D_Taxi = 0, D_ThamTu = 0, D_BEST = 0;
        int temp_i = Row_NumFind(E3);
        int temp_j = Col_NumFind(E3);
        D_Taxi = arr[temp_i][temp_j];
        int Temp_cheotrai = Max_CheoTrai(E3, temp_i, temp_j);
        int Temp_cheophai = Max_CheoPhai(E3, temp_i, temp_j);
        if (Temp_cheophai >= Temp_cheotrai) D_ThamTu = Temp_cheophai;
        else D_ThamTu = Temp_cheotrai;
        int c = abs(D_Taxi);
        if (c > D_ThamTu) {
            temp_EXP1 = static_cast<float>(EXP1) * 0.88;
            EXP1 = static_cast<int>(ceil(temp_EXP1));
            Res_EXP(EXP1);
            temp_EXP2 = static_cast<float>(EXP2) * 0.88;
            EXP2 = static_cast<int>(ceil(temp_EXP2));
            Res_EXP(EXP2);
            temp_HP1 = static_cast<float>(HP1) * 0.9;
            HP1 = static_cast<int>(ceil(temp_HP1));
            Res_HP(HP1);
            temp_HP2 = static_cast<float>(HP2) * 0.9;
            HP2 = static_cast<int>(ceil(temp_HP2));
            Res_HP(HP2);
            D_BEST = D_Taxi;
        }
        else {
            temp_EXP1 = static_cast<float>(EXP1) * 1.12;
            EXP1 = static_cast<int>(ceil(temp_EXP1));
            Res_EXP(EXP1);
            temp_EXP2 = static_cast<float>(EXP2) * 1.12;
            EXP2 = static_cast<int>(ceil(temp_EXP2));
            Res_EXP(EXP2);
            temp_HP1 = static_cast<float>(HP1) * 1.1;
            HP1 = static_cast<int>(ceil(temp_HP1));
            Res_HP(HP1);
            temp_HP2 = static_cast<float>(HP2) * 1.1;
            HP2 = static_cast<int>(ceil(temp_HP2));
            Res_HP(HP2);
            D_BEST = D_ThamTu;
        }
        return D_BEST;
    }
}

// Task 4

int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    //Tìm 'se'
    string Ki_tu1 = "^&*()_-=+{}[];:',>.? ";
    string Ki_tu2 = "!@#$%";
    int vitri = 0;
    string se = email;
    string password(s);
    string email_str(email);
    se = se.substr(0, email_str.find('@'));
    if (password.length() < 8) return -1;
    if (password.length() > 20) return -2;
    size_t se_check = password.find(se);
    if (se_check != string::npos)  return -(300 + se_check);

    for (int i = 0; i < password.length() - 2; i++) {
        if (password[i] == password[i + 1] && password[i] == password[i + 2]) return -(400 + i);
    }
    if (!(password.find('@') != string::npos || password.find('#') != string::npos || password.find('$') != string::npos || password.find('%') != string::npos || password.find('!') != string::npos)) {
        return -5;
    }
    for (int i = 0; i < Ki_tu1.length(); i++) {
        if (password.find(Ki_tu1[i]) != string::npos) {
            return password.find(Ki_tu1[i]);
        }
    }
    return -10;
}
// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int index = 0;
    struct password {
        int count = 1;
        string password_name;
    };
    password arr[1000];
    for (int i = 0; i < num_pwds; i++) {
        arr[i].password_name = arr_pwds[i];
        for (int j = i + 1; j < num_pwds; j++) {
            if (arr[i].password_name == arr_pwds[j]) {
                arr[i].count++;
            }
        }
    }
    password Lonnhat = arr[0];
    for (int i = 1; i < num_pwds; i++) {
        if (Lonnhat.count < arr[i].count) {
            Lonnhat = arr[i];
            index = i;
        }
        else if (Lonnhat.count == arr[i].count) {
            if (Lonnhat.password_name.length() < arr[i].password_name.length()) {
                Lonnhat = arr[i];
                index = i;
            }
        }
    }
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////