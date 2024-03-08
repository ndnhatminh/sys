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
int prehp(int& hp) {
    if (hp < 0) { hp = 0; };
    if (hp > 666) { hp = 666; };
    return hp;
}
int preexp(int& exp) {
    if (exp < 0) { exp = 0; };
    if (exp > 600) { exp = 600; };
    return exp;
}
int prem(int& m) {
    if (m < 0) { m = 0; };
    if (m > 3000) { m = 3000; };
    return m;
}
bool isSquare(int n) {
    int sqrtn = sqrt(n);
    return (sqrtn * sqrtn == n);
}
int sumDigits(int n) {
    int sum = 0;
    while (n > 0 || sum > 9) {
        if (n == 0) {
            n = sum;
            sum = 0;
        }
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int findMaxDiagonal(int matrix[10][10], int i, int j) {
    int maxVal = 0;
    // Đường chéo trái
    int x = i, y = j;
    while (x >= 0 && y >= 0) {
        maxVal = std::max(maxVal, matrix[x][y]);
        x--;
        y--;
    }
    x = i, y = j;
    while (x < 10 && y < 10) {
        maxVal = std::max(maxVal, matrix[x][y]);
        x++;
        y++;
    }
    // Đường chéo phải
    x = i, y = j;
    while (x >= 0 && y < 10) {
        maxVal = std::max(maxVal, matrix[x][y]);
        x--;
        y++;
    }
    x = i, y = j;
    while (x < 10 && y >= 0) {
        maxVal = std::max(maxVal, matrix[x][y]);
        x++;
        y--;
    }
    return maxVal;
}
// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    int d;
    d = e1 * 3 + exp1 * 7;
    //th1
    if (0 <= e1 && e1 <= 3) {
        if (e1 == 0) {
            exp2 =exp2 + 29;
        }
        if (e1 == 1) {
            exp2 =exp2 + 45;
        }
        if (e1 == 2) {
            exp2 =exp2 + 75;
        }
        if (e1 == 3) {
            exp2 = exp2 + 29 + 45 + 75;
        };
        preexp(exp2);
    if (d % 2 == 0) { exp1 = ceil(exp1 + d / 200.0); };
    if (d % 2 != 0) { exp1 = ceil(exp1 - d / 100.0); };
    };
    preexp(exp1);
    //th2
    if (4 <= e1 && e1 <= 99) {
        if (4 <= e1 && e1 <= 19) {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);
        };
        if (20 <= e1 && e1 <= 49) {
            exp2 = ceil(exp2+ e1 / 9.0 + 21);
        };
        if (50 <= e1 && e1 <= 65) {
            exp2 = ceil(exp2 + e1 / 16.0 + 17);
        };
        if (66 <= e1 && e1 <= 79) {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);
            if (exp2 > 200) {
                exp2 = ceil(exp2 + e1 / 9.0 + 21);
            }
        };
        if (80 <= e1 && e1 <= 99) {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);
            exp2 = ceil(exp2 + e1 / 9.0 + 21);
            if (exp2 > 400) {
                exp2 = ceil(exp2 + e1 / 16.0 + 17);
                exp2 = ceil(exp2 * 1.15);
            }
        };
        preexp(exp2);
        exp1 = exp1 - e1;
        preexp(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    double P1;
   // con duong 1
    int low = EXP1;
    int up = EXP1;
    while (!isSquare(up)) {
        up++;
    }
    while (!isSquare(low)) {
        low--;
    }
    int d_up = abs(up - EXP1);
    int d_low = abs(low - EXP1);
    if (d_up <= d_low ) {
        P1 = ((EXP1 / (up * up) + 80) / 123.0)*100;
    }
    else {
        P1 = 100;
    }
    // con duong 2
    double P2;
    int money = ceil(M1 * 0.5);
    if (HP1 < 200) {
        HP1 = ceil(HP1 * 1.3);
        M1 -= 150;
    }
    else {
        HP1 = ceil(HP1 * 1.1);
        M1 -= 70;
    };
    if (EXP1 < 400) {
        M1 -= 200;
    }
    else {
        M1 -= 120;
    }
    EXP1 = ceil(EXP1 * 1.13);
    preexp(EXP1);
    if (EXP1 < 300) {
        M1 -= 100;
    }
    else {
        M1 -= 120;
    }
    EXP1 = ceil(EXP1 * 0.9);
    if (E2 % 2 != 0) {
            while(M1>money){
                if (HP1 < 200) {
                    HP1 = ceil(HP1 * 1.3);
                    M1 -= 150;
                    if(M1<money){
                        break;
                    }
                }
            else {
                HP1 = ceil(HP1 * 1.1);
                M1 -= 70;
                if(M1<money){
                        break;
                    }
                };
            if (EXP1 < 400) {
                M1 -= 200;
                if(M1<money){
                        break;
                    }
                }
            else {
                M1 -= 120;
                if(M1<money){
                        break;
                    }
                };
            EXP1 = ceil(EXP1 * 1.13);
            preexp(EXP1);
            if (EXP1 < 300) {
        M1 -= 100;
        EXP1 = ceil(EXP1 * 0.9);
        if(M1<money){
                        break;
                    }
    }
    else {
        M1 -= 120;
        EXP1 = ceil(EXP1 * 0.9);
        if(M1<money){
                        break;
                    }
    }
            }
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
        } else {
            if (M1 <= 0) {
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            }
        }
    low = EXP1;
    up = EXP1;
    while (!isSquare(up)) {
        up++;
    }
    while (!isSquare(low)) {
        low--;
    }
     d_up = abs(up - EXP1);
     d_low = abs(low - EXP1);
    if (d_up <= d_low) {
        P2 = ((EXP1 / (up * up) + 80) / 123.0)*100;
    }
    else {
        P2 = 100;
    }
    // con duong 3
    int i;
    int P3;
    int P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2 < 10) {
        i = E2;
    }
    else {
        int sumofdigits = (E2 / 10) + (E2 % 10);
        i = sumofdigits % 10;
    }
    P3 = P[i];
    if (P1 == P2 && P1 == P3 && P1 == 100) { EXP1 = ceil(EXP1 *0.75); }
    if( (P1+P2+P3)/3 < 50 ){
        HP1 = ceil(HP1 * 0.85);
        EXP1 = ceil(EXP1 * 1.15);
    }
    else {
        HP1 = ceil(HP1 * 0.9);
        EXP1 = ceil(EXP1 * 1.2);
    }
    preexp(EXP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    const int n = 10;
    int a[n][n] = { 0 };
    int b[n][n] = { 0 };
    int i, j;
    // Khởi tạo điểm số cho ma trận taxi
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // Tính điểm số cho Sherlock và Watson
    for (j = 0; j < n; ++j) {
        for (i = 0; i < n; ++i) {
            b[i][j] = std::abs(findMaxDiagonal(a, i, j));
        }
    }

    // Tìm điểm gặp nhau
    int meetI = 0, meetJ = 0;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (a[i][j] > E3 * 2) meetI++;
            if (a[i][j] < -E3) meetJ++;
        }
    }
    meetI = sumDigits(meetI);
    meetJ = sumDigits(meetJ);

    // Kiểm tra xem Sherlock và Watson có đuổi kịp taxi không
    int taxiScore = std::abs(a[meetI][meetJ]);
    int sherlockScore = b[meetI][meetJ];
    if (taxiScore > sherlockScore) {
        HP1 = ceil(HP1 * 0.9);
        EXP1 = ceil(EXP1 * 0.88);
        HP2 = ceil(HP2 * 0.90);
        EXP2 = ceil(EXP2 * 0.88);
    }
    else {
        HP1 = ceil(HP1 * 1.1);
        EXP1 = ceil(EXP1 * 1.12);
        HP2 = ceil(HP2 * 1.1);
        EXP2 = ceil(EXP2 * 1.12);
    }
    return taxiScore > sherlockScore ? a[meetI][meetJ] : sherlockScore;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    const char* at_sign = strchr(email, '@');
    int se_length = at_sign - email;
    char se[101];
    strncpy(se, email, se_length);
    se[se_length] = '\0';
    int s_length = strlen(s);
    if (s_length < 8) return -1;
    if (s_length > 20) return -2;
    if (strstr(s, se) != NULL) {
        const char* se_pos = strstr(s, se);
        return -(300 + (se_pos - s));
    }
    for (int i = 0; i < s_length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            return -(400 + i);
        }
    }
    bool has_special_char = false;
    for (int i = 0; i < s_length; ++i) {
        if (strchr("@#%$!", s[i]) != NULL) {
            has_special_char = true;
        }
        else if (!isalnum(s[i])) {
            return i;
        }
    }
    if (!has_special_char)
       return -5;

    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int max_count = 0;
    size_t max_length = 0;
    int correct_index = -1;

    for (int i = 0; i < num_pwds; ++i) {
        int count = 0;
        // Đếm số lần xuất hiện của mật khẩu hiện tại
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                ++count;
            }
        }

        // Cập nhật mật khẩu đúng nếu tìm thấy số lần xuất hiện nhiều hơn hoặc độ dài lớn hơn
        if ((count > max_count) || (count == max_count && strlen(arr_pwds[i]) > max_length)) {
            max_count = count;
            max_length = strlen(arr_pwds[i]);
            correct_index = i;
        }
    }

    return correct_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
