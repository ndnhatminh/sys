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
void checkHP (int &HP){
    if (HP < 0) {
        HP = 0;
    }
    else if (HP > 666) HP = 666;
}

void checkExp (int &EXP){
    if (EXP < 0) {
        EXP = 0;
    }
    else if (EXP > 600) EXP = 600;
}

void checkMoney(int &M){
    if (M < 0) M = 0;
    if ( M > 3000) M = 3000;
}

bool checkE (int E){
    if (E < 0) return false;
    else if (E <= 99) return true;
    else return false;
}
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    float EXP1_1, EXP2_1;
    if (E1 <= 3)
    {
        int D;
        D = E1 * 3 + EXP1 * 7;
        switch (E1)
        {
            case 0:
                EXP2 += 29;
                if(D % 2 == 0){
                    EXP1_1 = ceil(EXP1 + (float)D/200);
                }
                else EXP1_1 = ceil(EXP1 - (float)D/100);
                ceil(EXP1_1);
                EXP1 = EXP1_1;
                break;
            case 1:
                EXP2 += 45;
                if(D % 2 == 0){
                    EXP1_1 = ceil(EXP1 + (float)D/200);
                }
                else EXP1_1 = ceil(EXP1 - (float)D/100);
                ceil(EXP1_1);
                EXP1 = EXP1_1;

                break;
            case 2:
                EXP2 += 75;
                if(D % 2 == 0){
                    EXP1_1 = ceil(EXP1 + (float)D/200);
                }
                else EXP1_1 = ceil(EXP1 - (float)D/100);
                ceil(EXP1_1);
                EXP1 = EXP1_1;
                break;
            case 3:
                EXP2 += 29 + 45 + 75;
                if(D % 2 == 0){
                    EXP1_1 = ceil(EXP1 + (float)D/200);
                }
                else EXP1_1 = ceil(EXP1 - (float)D/100);
                ceil(EXP1_1);
                EXP1 = EXP1_1;
                break;
            default:
                break;
        }

    }

    else if (E1 <= 19){
        EXP2_1 = ceil(EXP2 + (float)E1/4 + 19);
        EXP2 = EXP2_1;
        EXP1 -= E1;
    }
    else if (E1 <= 49){
        EXP2_1 = ceil(EXP2 + (float)E1/9 + 21);
        EXP2 = EXP2_1;
        EXP1 -= E1;
    }
    else if (E1 <= 65){
        EXP2_1 = ceil(EXP2 + (float)E1/16 + 17);

        EXP2 = EXP2_1;
        EXP1 -= E1;
    }
    else if (E1 <= 79){
        EXP2_1 = ceil(EXP2 + (float)E1/4 + 19);

        if (EXP2_1 > 200) EXP2_1 = ceil(EXP2_1 + (float)E1/9 + 21);
        EXP2 = EXP2_1;
        EXP1 -= E1;
    }
    else if (E1 <= 99){
        EXP2_1 = ceil(EXP2 + (float)E1/4 + 19);

        EXP2_1 = ceil(EXP2_1 + (float)E1/9 + 21);
        if (EXP2_1 > 400) {
            EXP2_1 = ceil(EXP2_1 + (float)E1/16 + 17);
            EXP2_1 = ceil(EXP2_1 * 1.15);
        }
        EXP2 = EXP2_1;
        EXP1 -= E1;
    }

    checkExp(EXP1);
    checkExp(EXP2);
    return EXP1 + EXP2;
}

// Task 2
bool ktrSochinhphuong (int n){
    int i = 0;
    while (i*i <= n){
        if ( i*i == n ) return true;
        i++;
    }
    return false;
}

int timSochinhphuongGannhat(int EXP1){
    int larger, smaller;
    //tìm số chính phương nhỏ hơn
    for (int i = EXP1; i >= 0; i--){
        if (ktrSochinhphuong(i)){
            smaller = i;
            break;
        }
    }
    //tìm số chính phương lớn hơn
    for (int i = EXP1; ;i++){
        if (ktrSochinhphuong(i)){
            larger = i;
            break;
        }
    }

    if (abs(EXP1 - smaller) <= abs(EXP1 - larger)) {
        return smaller;
    }
    else return larger;
}
void sukien1 (int &HP1, int &M1){ // mua thức ăn, thức uống
    float HP3;
    if (HP1 < 200){
        HP3 = ceil(HP1 * 1.3);
        HP1 = HP3;
        M1 -= 150;
    }
    else {
        HP3 = ceil(HP1 * 1.1);
        HP1 = HP3;
        M1 -= 70;
    }
    checkMoney(M1);
    checkHP(HP1);
}

void sukien2 (int &EXP1, int &M1){ // thuê taxi, xe ngựa
    float HP3;
    if (EXP1 < 400) { // thuê taxi
        M1 -= 200;
    }
    else M1 -= 120; // thuê ngựa
    HP3 = ceil(EXP1 * 1.13);
    EXP1 = HP3;
    checkMoney(M1);
    checkExp(EXP1);
}

void sukien3 (int &EXP1, int &M1){ // gặp người vô gia cư
    float EXP3;
    if (EXP1 < 300) { // tin lời
        M1 -= 100;
    }
    else M1 -= 120;
    EXP3 = ceil(EXP1 * 0.9);
    EXP1 = EXP3;
    checkMoney(M1);
    checkExp(EXP1);
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    float P1, P2, P3;// xác suất 3 đường đi
    //Đường đi 1
    int Sochinhphuong = timSochinhphuongGannhat(EXP1);
    // tính xác suất P1
    if (EXP1 >= Sochinhphuong) {
        P1 = 1;
    } else P1 = (EXP1 / (float) Sochinhphuong + 80) / 123;
    int gioihantien = M1/2;
    //Đường đi 2
    if (E2 % 2 != 0) {
        //E2 lẻ
        //lặp lại sự kiện
        while (M1 >= gioihantien) {
            if (M1 > gioihantien) sukien1(HP1, M1);
            if (M1 > gioihantien) sukien2(EXP1, M1);
            if (M1 > gioihantien) sukien3(EXP1, M1);
        }
        float HP3, EXP3;
        HP3 = ceil(HP1 * 0.83);
        HP1 = HP3;
        checkHP(HP1);
        EXP3 = ceil(EXP1 * 1.17);
        EXP1 = EXP3;
        checkExp(EXP1);
        // tính xác suất P2

        if (EXP1 >= Sochinhphuong) {
            P2 = 1;
        } else P2 = (EXP1 / (float)Sochinhphuong + 80) / 123;

    } else { //E2 chẵn
        float HP3, EXP3;
        sukien1(HP1, M1);

        // LẦN LƯỢT THỰC HIỆN HÀNH ĐỘNG
        if (M1 <= 0) {
            P2 = 0; //XAC SUAT
            checkMoney(M1);
            HP3 = ceil(HP1 * 0.83);
            HP1 = HP3;
            checkHP(HP1);
            EXP3 = ceil(EXP1 * 1.17);
            EXP1 = EXP3;
            checkExp(EXP1);
        } else {
            sukien2(EXP1, M1);
            if (M1 <= 0) {
                P2 = 0; //XAC SUAT
                checkMoney(M1);
                HP3 = ceil(HP1 * 0.83);
                HP1 = HP3;
                checkHP(HP1);
                EXP3 = ceil(EXP1 * 1.17);
                EXP1 = EXP3;
                checkExp(EXP1);
            } else {
                sukien3(EXP1, M1);
                if (M1 < 0) {
                    P2 = 0; //XAC SUAT
                    checkMoney(M1);
                    HP3 = ceil(HP1 * 0.83);
                    HP1 = HP3;
                    checkHP(HP1);
                    EXP3 = ceil(EXP1 * 1.17);
                    EXP1 = EXP3;
                    checkExp(EXP1);
                } else {
                    HP3 = ceil(HP1 * 0.83);
                    HP1 = HP3;
                    checkHP(HP1);
                    EXP3 = ceil(EXP1 * 1.17);
                    EXP1 = EXP3;
                    checkExp(EXP1);

                    if (EXP1 >= Sochinhphuong) {
                        P2 = 1;
                    } else
                        P2 = (EXP1 / (float) Sochinhphuong + 80) / 123;

                }
            }
        }
    }

    // đường đi số 3
    double P[10] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    if (E2 >= 0 && E2 <= 9) {
        P3 = P[E2];
    } else {
        while (E2 >= 10) {
            E2 = E2 % 10 + E2 / 10;
        }
        P3 = P[E2];
    }
    double Pi;
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        float EXP3, HP3;
        EXP3 = ceil(EXP1 * 0.75);
        EXP1 = EXP3;
        checkExp(EXP1);
    } else {
        Pi = (P1 + P2 + P3) / 3;
        if (Pi < 0.5) {
            float EXP3, HP3;
            HP3 = ceil(HP1 * 0.85);
            HP1 = HP3;
            checkHP(HP1);
            EXP3 = ceil(EXP1 * 1.15);
            EXP1 = EXP3;
            checkExp(EXP1);

        } else {
            float EXP3, HP3;
            HP3 = ceil(HP1 * 0.9);
            HP1 = HP3;
            checkHP(HP1);
            EXP3 = ceil(EXP1 * 1.2);
            EXP1 = EXP3;
            checkExp(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int changetoOnedigit (int &n){
    n = n%10 + n/10;
    if (n <= 9 && n >= 0) return n;
    else return changetoOnedigit(n);
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int map[10][10];
    //tạo map
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    //tìm vị trí gặp nhau
    int demsoDuong = 0;
    int demsoAm = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(map[i][j] > E3 * 2) {
                demsoDuong++;
            }
            if(map[i][j] < -E3){
                demsoAm++;
            }
        }
    }
    demsoDuong = changetoOnedigit(demsoDuong);
    demsoAm = changetoOnedigit(demsoAm);
    int vitriGapnhau = map[demsoDuong][demsoAm];
    //tìm max đường chéo phải
    int maxPhai;
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            if (i + j == demsoDuong + demsoAm){
                if (map[i][j] > vitriGapnhau) {
                    maxPhai = map[i][j];
                }
                else maxPhai = vitriGapnhau;
            }
        }
    }

    //tìm max đường chéo phải
    int maxTrai;
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            if (i + j == demsoDuong + demsoAm){
                if (map[i][j] > vitriGapnhau) {
                    maxPhai = map[i][j];
                }
                else maxPhai = vitriGapnhau;
            }
        }
    }

    //tim diem cua S va W tai vi tri gap nhau
    int sherlock_watson_Point;
    if (maxPhai > maxTrai) {
        sherlock_watson_Point = maxPhai;
    }
    else sherlock_watson_Point = maxTrai;

    //Final action
    int taxi_point;
    taxi_point = map[demsoDuong][demsoAm];
    float HP1_1, HP2_1, EXP1_1, EXP2_1;
    if ( sherlock_watson_Point < abs(taxi_point)){
        //EXP1
        EXP1_1 = EXP1 * 0.88;
        EXP1 = ceil(EXP1_1);
        checkHP(EXP1);

        //EXP2
        EXP2_1 = EXP2 * 0.88;
        EXP2 = ceil(EXP2_1);
        checkHP(EXP2);

        //HP1
        HP1_1 = HP1 * 0.9;
        HP1 = ceil(HP1_1);
        checkHP(HP1);

        //HP2
        HP2_1 = HP2 * 0.9;
        HP2 = ceil(HP2_1);
        checkHP(HP2);
        return taxi_point;
    }
    else {
        //EXP1
        EXP1_1 = EXP1 * 1.12;
        EXP1 = ceil(EXP1_1);
        checkHP(EXP1);

        //EXP2
        EXP2_1 = EXP2 * 1.12;
        EXP2 = ceil(EXP2_1);
        checkHP(EXP2);

        //HP1
        HP1_1 = HP1 * 1.1;
        HP1 = ceil(HP1_1);
        checkHP(HP1);

        //HP2
        HP2_1 = HP2 * 1.1;
        HP2 = ceil(HP2_1);
        checkHP(HP2);


        return sherlock_watson_Point;
    }

}

// Task 4
int demSokitu (const char* str){
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }
    return count;
}
bool ktrKituDacbiet (const char* &str){
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '@' ||str[i] == '#' || str[i] == '%' || str[i] == '$' ||str[i] == '!')
            return true;
    }
    return false;
}
bool ktrKitu (char &str){
    if (str == '@' ||str == '#' || str == '%' || str == '$' ||str == '!'){
        return true;
    }
    return false;
}
bool kituKhac (char ki_tu){
    bool so;
    if (ki_tu >= '0' && ki_tu <= '9') {
        so = true;
    } else so = false;

    bool chu;
    if ((ki_tu >= 'A' && ki_tu <= 'Z') || (ki_tu >= 'a' && ki_tu <= 'z')) {
        chu = true;
    } else chu = false;

    if (so == true || chu == true || ktrKitu(ki_tu) == true) return false;
    return true;
}
int checkPassword(const char * s, const char * email) {
    int count_s = demSokitu(s);// đếm số kí tự của s
    if (count_s < 8) return -1; // s có độ dài ngắn hơn độ dài tối thiểu
    if (count_s > 20) return -2; // s có độ dài dài hơn độ dài tối đa

    // tạo se
    string email1 = (string)email;
    int count_se = 0;
    for (int i = 0; i < demSokitu(email); i++){
        if (email1[i] == '@') break;
        count_se++;
    }
    string se = email1.substr(0, count_se);
//kiểm tra se trong s
    string s1 = s;
    string sub_s;
    for (int i = 0; i < count_s; i++){
        if (s[i] == se[0]){
            sub_s = s1.substr(i, count_se);
            if (sub_s == se){
                return -(300+i);
            }
        }
    }



    //ktr s có chứa nhiều hơn 2 ký tự liên tiếp và giống nhau
    for (int i = 0; i < count_s; i++){
        if (s[i] == s[i+1] && s[i+1] == s[i+2]){
            return -(400 + i);
        }
    }

    if (ktrKituDacbiet(s) == 0) return -5; //  s không chứa ký tự đặc biệt
    //check kí tự khác
    for (int i = 0; i < count_s; i++){
        if (kituKhac(s[i]) == true) return i;
    }
    return -10;

}

//Task 5
int demSokitu (string &str){
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }
    return count;
}
int soLanxuathien(string str[], int n, string value){
    int count = 0;
    for(int i = 0; i < n ; i++){
        if (str[i] == value) count++;
    }
    return count;
}

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int n = num_pwds;
    string arr[n];
    for (int i = 0; i < n; i++){
        arr[i] = (string)arr_pwds[i];
    }
    int Max = 0;
    //// Tìm số lần xuất hiện nhiều nhất
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n + 1; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > Max) {
            Max = count;
        }
    }
    string dainhat;/// phần tử có số kí tự nhiều nhất
    ///Tìm kí tự dài nhất trong dãy
    for (int i = 0; i < num_pwds; i++){
        if (soLanxuathien(arr, num_pwds,arr[i]) == Max){
            dainhat = arr[i];
            break;
        }
    }
    for (int i = 0; i < num_pwds; i++){
        if(soLanxuathien(arr, num_pwds,arr[i]) == Max){
            if (demSokitu(arr[i]) > demSokitu(dainhat)){
                dainhat = arr[i];
            }
        }
    }
    ///Tìm vị trí
    int pos;
    for (int i = 0; i < num_pwds; i++){
        if (arr[i] == dainhat) {
            pos = i;
            break;
        }
    }
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////