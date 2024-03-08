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
   // DO NOT MODIFY THIS FUNCTION
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
// Hàm phụ
void checkTask1(int &exp1, int &exp2) {
    if (exp1 > 600) {
        exp1 = 600;
    }
    else if (exp1 < 0) {
        exp1 = 0;
    }
    if (exp2 > 600) {
        exp2 = 600;
    }
    else if (exp2 < 0) {
        exp2 = 0;
    }
}
// Hàm chính
int firstMeet(int &exp1, int &exp2, int e1)
{
    if (e1 < 0 || e1 > 99) return -99;
    checkTask1(exp1, exp2);
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) {
            exp2 += 29;
        }
        else if (e1 == 1) {
            exp2 += 45;
        }
        else if (e1 == 2) {
            exp2 += 75;
        }
        else {
            exp2 = exp2 + 29 + 45 + 75;
        }
        checkTask1(exp1, exp2);
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 += ceil(float(D / 200.0));
        }
        else {
            exp1 -= floor(float(D / 100.0));
        }
    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 <= 19) {
            exp2 += ceil(float(e1 / 4.0)) + 19; // thông tin 1
        }
        else if (e1 <= 49) {
            exp2 += ceil(float(e1 / 9.0)) + 21; // thông tin 2
        }
        else if (e1 <= 65) {
            exp2 += ceil(float(e1 / 16.0)) + 17; // thông tin 3
        }
        else if (e1 <= 79) { // thông tin 4
            exp2 += ceil(float(e1 / 4.0)) + 19;
            checkTask1(exp1, exp2);
            if (exp2 > 200) {
                exp2 += ceil(float(e1 / 9.0)) + 21;
            }
        }
        else { // thông tin 5
            exp2 += ceil(float(e1 / 4.0)) + 19;
            checkTask1(exp1, exp2);
            exp2 += ceil(float(e1 / 9.0)) + 21;
            checkTask1(exp1, exp2);
            if (exp2 > 400) {
                exp2 += ceil(float(e1 / 16.0)) + 17;
                checkTask1(exp1, exp2);
                exp2 += ceil(float(exp2 * 0.15));
            }
        }
        checkTask1(exp1, exp2);
        exp1 -= e1;
        checkTask1(exp1, exp2);
    }
    checkTask1(exp1, exp2);
    return exp1 + exp2;
}

// Task 2
// Hàm phụ:
int soChinhPhuongGanNhat(int &EXP1) {
    // Hàm tìm số chính phương gần nhất
    if (EXP1 == 0 || EXP1 == 1) {
        return EXP1;
    }
    int small = sqrt(EXP1);
    int big = small + 1;
    if (small * small == EXP1) {
        return small * small;
    }
    else if (big * big == EXP1) {
        return big * big;
    }
    else {
        int dist_small = EXP1 - small * small;
        int dist_big = big * big - EXP1;
        if (dist_small >= dist_big) {
            return big * big;
        }
        else {
            return small * small;
        }
    }
}
void checkTask2(int &HP1, int &EXP1, int &M1)
{
    // Hàm check các thông số của Task 2
    if (HP1 > 666) {
        HP1 = 666;
    }
    else if (HP1 < 0) {
        HP1 = 0;
    }
    if (EXP1 > 600) {
        EXP1 = 600;
    }
    else if (EXP1 < 0) {
        EXP1 = 0;
    }
    if (M1 > 3000) {
        M1 = 3000;
    }
    else if (M1 < 0) {
        M1 = 0;
    }
}
// Hàm chính
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
    if (E2 < 0 || E2 > 99) return -99;
    float P;
    checkTask2(HP1, EXP1, M1);
    // Con đường 1
    int S = soChinhPhuongGanNhat(EXP1);
    float P1 = 0;
    if (EXP1 >= S) {
        P1 = 1;
    }
    else {
        P1 = float(EXP1 / S + 80) / 123.0;
    }
    // Biến phụ:
    int banDau = M1;
    int chiTra = 0;

    // Nếu E2 lẻ
    if (E2 % 2 != 0) {
        while (((chiTra) <= float(banDau) * 0.5) && (M1 > 0)) {
            
            // Con đường 2

            checkTask2(HP1, EXP1, M1);
            // SỰ KIỆN 1
            if (((chiTra) <= float(banDau) * 0.5) && (M1 > 0)) {
                if (HP1 < 200) {
                    HP1 = ceil(float(HP1 * 1.3));
                    M1 -= 150;
                    chiTra += 150;
                }
                else if (HP1 >= 200) {
                    HP1 = ceil(float(HP1 * 1.1));
                    M1 -= 70;
                    chiTra += 70;
                }
            }
            else break;

            checkTask2(HP1, EXP1, M1);
            // SỰ KIỆN 2
            if (chiTra <= float(banDau) * 0.5) {
                if (EXP1 < 400) {
                    M1 -= 200;
                    chiTra += 200;
                }
                else {
                    M1 -= 120;
                    chiTra += 120;
                }
                checkTask2(HP1, EXP1, M1);
                EXP1 = ceil(float(EXP1 * 1.13));
            }
            else break;

            checkTask2(HP1, EXP1, M1);
            // SỰ KIỆN 3
            if (((chiTra) <= float(banDau) * 0.5) && (M1 > 0)) {
                if (EXP1 < 300) {
                    M1 -= 100;
                    chiTra += 100;
                }
                else {
                    M1 -= 120;
                    chiTra += 120;
                }
                checkTask2(HP1, EXP1, M1);
                EXP1 = ceil(float(EXP1 * 0.9));
            }
            else break;
            checkTask2(HP1, EXP1, M1);
        }
        HP1 = ceil(float(HP1 * 0.83));
        EXP1 = ceil(float(EXP1 * 1.17));
        checkTask2(HP1, EXP1, M1);

        // E2 chẵn
    }
    else{
        
        // SỰ KIỆN 1
        checkTask2(HP1, EXP1, M1);
        if (M1 > 0) {
            if (HP1 < 200) {
                HP1 = ceil(float(HP1 * 1.3));
                M1 -= 150;
            }
            else {
                HP1 = ceil(float(HP1 * 1.1));
                M1 -= 70;
            }
        }

        // SỰ KIỆN 2
        checkTask2(HP1, EXP1, M1);
        if (M1 > 0) {
            if (EXP1 < 400) {
                M1 -= 200;
            }
            else {
                M1 -= 120;
            }
            EXP1 = ceil(float(EXP1 * 1.13));
        }

        // SỰ KIỆN 3
        checkTask2(HP1, EXP1, M1);
        if (M1 > 0) {
            if (EXP1 < 300) {
                M1 -= 100;
            }
            else {
                M1 -= 120;
            }
            EXP1 = ceil(float(EXP1 * 0.9));
        }
        checkTask2(HP1, EXP1, M1);
        HP1 = ceil(float(HP1 * 0.83));
        EXP1 = ceil(float(EXP1 * 1.17));
        checkTask2(HP1, EXP1, M1);
    }
    S = soChinhPhuongGanNhat(EXP1);
    float P2;
    if (EXP1 >= S) {
        P2 = 1;
    }
    else {
        P2 = (float(EXP1) / S + 80) / 123.0;
    }

    // con đường 3
    int P_arrays[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float P3;
    if (E2 >= 0 && E2 <= 9) {
        P3 = P_arrays[E2] / 100.0;
    }
    else {
        int donvi = E2 % 10;
        int chuc = E2 / 10;
        P3 = (P_arrays[(donvi + chuc) % 10]) / 100.0;
    }
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = ceil(float(EXP1 * 0.75));
        checkTask2(HP1, EXP1, M1);
    } else {
        P = (P1 + P2 + P3) / 3;
        if (P < 0.5) {
            HP1 = ceil(float(HP1 * 0.85));
            EXP1 = ceil(float(EXP1 * 1.15));
        }
        else {
            HP1 = ceil(float(HP1 * 0.9));
            EXP1 = ceil(float(EXP1 * 1.2));
        }
    }
    checkTask2(HP1, EXP1, M1);
    return HP1 + EXP1 + M1;
}

// Task 3
// Hàm phụ
void checkTask3(int &EXP1, int &HP1, int &EXP2, int &HP2) {
    if (EXP1 > 600) {
        EXP1 = 600;
    }
    else if (EXP1 < 0) {
        EXP1 = 0;
    }
    if (EXP2 > 600) {
        EXP2 = 600;
    }
    else if (EXP2 < 0) {
        EXP2 = 0;
    }
    if (HP1 > 666) {
        HP1 = 666;
    }
    else if (HP1 < 0) {
        HP1 = 0;
    }
    if (HP2 > 666) {
        HP2 = 666;
    }
    else if (HP2 < 0) {
        HP2 = 0;
    }
}
int tinhMaxDuongCheoTrai(int T[][10], int i, int j) {
    int score = T[i][j];

    // Duyệt lên trên
    int x = i - 1, y = j - 1;
    while (x >= 0 && y >= 0) {
        score = max(score, T[i][j]);
        --x;
        --y;
    }

    // Duyệt xuống dưới
    x = i + 1;
    y = j + 1;
    while (x < 10 && y < 10) {
        score = max(score, T[i][j]);
        ++x;
        ++y;
    }
    return score;
}

int tinhMaxDuongCheoPhai(int T[][10], int i, int j)
{
    int score = T[i][j];

    // Duyệt lên trên
    int x = i - 1, y = j + 1;
    while (x >= 0 && y >= 0) {
        score = max(score, T[i][j]);
        --x;
        ++y;
    }

    // Duyệt xuống dưới
    x = i + 1;
    y = j - 1;
    while (x < 10 && y >= 0) {
        score = max(score, T[x][y]); // Lấy giá trị tuyệt đối
        ++x;
        --y;
    }
    return score;
}

// Hàm chính
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    if (E3 < 0 || E3 > 99) return -99;
    // Thiết lập ma trận
    const int SIZE = 10;
    int T[SIZE][SIZE] = {0};
    int H[SIZE][SIZE];
    int x = 0, y = 0;
    int max_left;
    int max_right;

    // Tính giá trị từng ô của Taxi_map
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            T[i][j] = (((E3 * j) + (i * 2)) * (i - j));
            if (T[i][j] > (2 * E3)) {
                x++;
            }
            else if (T[i][j] < (-E3)) {
                y++;
            }
        }
    }

    // Tính tọa độ của điểm giao nhau
    while (x > 9 || y > 9) {
        if (x > 9) {
            x = (x / 10) + (x) % 10;
        }
        if (y > 9) {
            y = (y / 10) + (y) % 10;
        }
    }

    // Thiết lập ma trận Holmes
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) { 
            int maxDuongCheoTrai = tinhMaxDuongCheoTrai(T, i, j);
            int maxDuongCheoPhai = tinhMaxDuongCheoPhai(T, i, j);
            H[i][j] = abs(max(maxDuongCheoTrai, maxDuongCheoPhai));
        }
    }
    checkTask3(EXP1, HP1, EXP2, HP2);

    // Kiểm tra gặp nhau
    if (abs(T[x][y]) > H[x][y]) {
        EXP1 = ceil(float(EXP1 * 0.88));
        HP1 = ceil(float(HP1 * 0.9));

        EXP2 = ceil(float(EXP2 * 0.88));
        HP2 = ceil(float(HP2 * 0.9));

        checkTask3(EXP1, HP1, EXP2, HP2);
        return T[x][y];
    }
    else {
        EXP1 = ceil(float(EXP1 * 1.12));
        HP1 = ceil(float(HP1 * 1.1));

        EXP2 = ceil(float(EXP2 * 1.12));
        HP2 = ceil(float(HP2 * 1.1));

        checkTask3(EXP1, HP1, EXP2, HP2);
        return H[x][y];
    }
    return -1;
}

// Task 4
int checkPassword(const char *s, const char *email) {

    // Biến tạm
    int length_se = 0;
    int length_s = strlen(s);
    char se[length_s];

    // Chuyển đổi kiểu dữ liệu của chuỗi s
    char *chuoi_s = new char[length_s + 1];
    strcpy(chuoi_s, s);

    // Đọc - ghi chuỗi se từ email
    while (email[length_se] != '@') {
        se[length_se] = email[length_se];
        length_se++;
    }
    se[length_se] = '\0';

    // kiểm tra độ dài
    if (length_s < 8) {
        return -1;
    }
    else if (length_s > 20) {
        return -2;
    }

    // kiểm tra chuỗi se
    char *checkse = strstr(chuoi_s, se); // con trỏ chuỗi
    if (checkse != 0) {
        return -(300 + (checkse - chuoi_s));
    }

    // kiểm tra 2 kí tự liên tiếp giống nhau
    for (int i = 0; i < length_s; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }
    // kiểm tra có tồn tại kí tự đặc biệt
    int temp = 0;
    while (temp < length_s) {
        if (s[temp] != '@' && s[temp] != '#' && s[temp] != '%' && s[temp] != '$' && s[temp] != '!') {
            temp++;
        }
        else break;
    }
    if (temp == length_s) {
        return -5;
    }
    // Kiểm tra kí tự không được quy định
    for (int i = 0; i < length_s; i++) {
        if (((s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122)) || (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'));
        else {
            return i;
        }
    }
    return -10;
}
// Task 5
// Hàm chính:
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int max_freq = 1;
    int max_len = 0;
    string correct_pwds;
    for (int i = 0; i < num_pwds; i++) {
        int count = 1;
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }
        if (count > max_freq || (count == max_freq && strlen(arr_pwds[i]) > max_len)) {
            max_freq = count;
            max_len = strlen(arr_pwds[i]);
            correct_pwds = arr_pwds[i];
        }
    }
    for (int i = 0; i < num_pwds; i++) {
        if (arr_pwds[i] == correct_pwds) {
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
///////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////