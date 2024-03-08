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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    // Trường hợp 1
    if (e1 >= 0 && e1 <= 3) {
        int expToAdd = 0;
        switch (e1) {
            case 0: expToAdd = 29; break;
            case 1: expToAdd = 45; break;
            case 2: expToAdd = 75; break;
            case 3: expToAdd = 29 + 45 + 75; break;
        }
        exp2 += expToAdd;
        int D = e1 * 3 + exp1 * 7;
        double expAdd1 = 0;
        if (D % 2 == 0) {
            expAdd1 = ceil(D / 200);
            exp1 += expAdd1;
        } else {
            expAdd1 = ceil(D / 100);
            exp1 -= expAdd1;
        }
    } else if (e1 >= 4 && e1 <= 99) {// Trường hợp 2
        if (e1 >= 4 && e1 <= 19) {
            exp2 += ceil((double)e1 / 4 + 19);
        } else if (e1 >= 20 && e1 <= 49) {
            exp2 += ceil((double)e1 / 9 + 21);
        } else if (e1 >= 50 && e1 <= 65) {
            exp2 += ceil((double)e1 / 16 + 17);
        } else if (e1 >= 66 && e1 <= 79) {
            exp2 += ceil((double)e1 / 4 + 19);
            if (exp2 > 200) {
                exp2 += ceil((double)e1 / 9 + 21);
            }
        } else if (e1 >= 80 && e1 <= 99) {
            exp2 += ceil(((double)e1 / 4 + 19) + ((double)e1 / 9 + 21));
            if (exp2 > 400) {
                exp2 += ceil((double)e1 / 16 + 17);
                exp2 += ceil((double)exp2 * 0.15);
            }
        }
        // Cập nhật EXP1 của Sherlock
        exp1 -= e1;
    } else {
        return -99;
    }
    exp1 = exp1 < 0 ? 0 : (exp1 > 600 ? 600 : exp1);
    exp2 = exp2 < 0 ? 0 : (exp2 > 600 ? 600 : exp2);
    // Trả về tổng EXP của Sherlock và Watson
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // Con đường 01
    int S = nearestPerfectSquare(EXP1);
    double P1 = (EXP1 >= S) ? 1 : (((double)EXP1 / S + 80) / 123);

    // Con đường 02
    double P2 = 0;
    double HP_temp = HP1;
    double EXP_temp = EXP1;
    double M_temp = M1;
    double M_haft = M1 * 0.5;

    if (E2 % 2 == 0) {
        // su kien 1
        if (HP_temp < 200) {
            HP_temp += ceil(HP_temp * 0.3);
            M_temp -= 150;
        } else {
            HP_temp += ceil(HP_temp * 0.1);
            M_temp -= 70;
        }
        HP_temp = (HP_temp > 666) ? 666 : ((HP_temp <= 0) ? 0 : HP_temp);
        if (M_temp <= 0) {
            HP_temp -= floor(HP_temp * 0.17);
            EXP_temp += ceil(EXP_temp * 0.17);
            HP_temp = (HP_temp > 666) ? 666 : ((HP_temp <= 0) ? 0 : HP_temp);
            EXP_temp = (EXP_temp < 0) ? 0 : ((EXP_temp > 600) ? 600 : EXP_temp);
            goto skip_check;
        }

        // su kien 2
        M_temp -= (EXP_temp < 400) ? 200 : 120;
        EXP_temp += ceil(EXP_temp * 0.13);
        EXP_temp = (EXP_temp < 0) ? 0 : ((EXP_temp > 600) ? 600 : EXP_temp);
        if (M_temp <= 0) {
            HP_temp -= floor(HP_temp * 0.17);
            EXP_temp += ceil(EXP_temp * 0.17);
            HP_temp = (HP_temp > 666) ? 666 : ((HP_temp <= 0) ? 0 : HP_temp);
            EXP_temp = (EXP_temp < 0) ? 0 : ((EXP_temp > 600) ? 600 : EXP_temp);
            goto skip_check;
        }

        // su kien 3
        M_temp -= (EXP_temp < 300) ? 100 : 120;
        EXP_temp -= floor(EXP_temp * 0.1);
        EXP_temp = (EXP_temp < 0) ? 0 : ((EXP_temp > 600) ? 600 : EXP_temp);
        if (M_temp <= 0) {
            HP_temp -= floor(HP_temp * 0.17);
            EXP_temp += ceil(EXP_temp * 0.17);
            HP_temp = (HP_temp > 666) ? 666 : ((HP_temp <= 0) ? 0 : HP_temp);
            EXP_temp = (EXP_temp < 0) ? 0 : ((EXP_temp > 600) ? 600 : EXP_temp);
        }
    } else {
        while(true) {
            // su kien 1
            if (HP_temp < 200) {
                HP_temp += ceil(HP_temp * 0.3);
                M_temp -= 150;
            } else {
                HP_temp += ceil(HP_temp * 0.1);
                M_temp -= 70;
            }
            HP_temp = (HP_temp > 666) ? 666 : ((HP_temp <= 0) ? 0 : HP_temp);
            if (M_temp <= M_haft) {
                HP_temp -= floor(HP_temp * 0.17);
                EXP_temp += ceil(EXP_temp * 0.17);
                HP_temp = (HP_temp > 666) ? 666 : ((HP_temp <= 0) ? 0 : HP_temp);
                EXP_temp = (EXP_temp < 0) ? 0 : ((EXP_temp > 600) ? 600 : EXP_temp);
                break;
            }

            // su kien 2
            M_temp -= (EXP_temp < 400) ? 200 : 120;
            EXP_temp += ceil(EXP_temp * 0.13);
            EXP_temp = (EXP_temp < 0) ? 0 : ((EXP_temp > 600) ? 600 : EXP_temp);
            if (M_temp <= M_haft) {
                HP_temp -= floor(HP_temp * 0.17);
                EXP_temp += ceil(EXP_temp * 0.17);
                HP_temp = (HP_temp > 666) ? 666 : ((HP_temp <= 0) ? 0 : HP_temp);
                EXP_temp = (EXP_temp < 0) ? 0 : ((EXP_temp > 600) ? 600 : EXP_temp);
                break;
            }

            // su kien 3
            M_temp -= (EXP_temp < 300) ? 100 : 120;
            EXP_temp -= floor(EXP_temp * 0.1);
            EXP_temp = (EXP_temp < 0) ? 0 : ((EXP_temp > 600) ? 600 : EXP_temp);
            if (M_temp <= M_haft) {
                HP_temp -= floor(HP_temp * 0.17);
                EXP_temp += ceil(EXP_temp * 0.17);
                HP_temp = (HP_temp > 666) ? 666 : ((HP_temp <= 0) ? 0 : HP_temp);
                EXP_temp = (EXP_temp < 0) ? 0 : ((EXP_temp > 600) ? 600 : EXP_temp);
                break;
            }
        }
    }
    skip_check:
    HP1 = HP_temp;
    EXP1 = EXP_temp;
    M1 = M_temp;
    int S2 = nearestPerfectSquare(EXP1);
    P2 = (EXP1 >= S2) ? 1 : (((double)EXP1 / S2 + 80) / 123);

    // Tính xác suất trên con đường 03
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = 0;

    if (E2 < 10) {
        i = E2;
    } else if (E2 < 100 && E2 >= 10) {
        int sum = (E2 / 10) + (E2 % 10);
        i = sum % 10;
    }
    double P3 = (double)P[i] / 100;

    if (P1 == 1 && P2 == 1 && P3 == 1) {
        // Cả 3 con đường có xác suất 100%
        EXP1 -= floor((float)EXP1 * 0.25);
    } else {
        double P_avg = (P1 + P2 + P3) / 3;

        if (P_avg >= 0.5) {
            HP1 -= floor((float)HP1 * 0.1);
            EXP1 += ceil((float)EXP1 * 0.2);
        } else {
            HP1 -= floor((float)HP1 * 0.15);
            EXP1 += ceil((float)EXP1 * 0.15);
        }
    }
    HP1 = (HP1 > 666) ? 666 : ((HP1 <= 0) ? 0 : HP1);
    EXP1 = (EXP1 < 0) ? 0 : ((EXP1 > 600) ? 600 : EXP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int matrix[10][10] = {0}; // Khởi tạo ma trận 10x10 với các giá trị ban đầu là 0
    int i = 0, j = 0;
    // Tính điểm số cho từng ô của ma trận taxi
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {
            matrix[row][col] = ((E3 * col) + (row * 2)) * (row - col);
        }
    }
    // Tính toán vị trí gặp nhau của taxi và Sherlock/Watson
    while (true) {
        if (i >= E3 * 2) {
            i = (i / 10) + (i % 10); // Tổng số trở về 1 chữ số
        }
        if (j >= -E3) {
            j = (j / 10) + (j % 10); // Tổng số trở về 1 chữ số
        }
        if (abs(matrix[i][j]) > max(HP1, HP2)) {
            // Nếu điểm số tuyệt đối của taxi lớn hơn cả Sherlock và Watson, họ sẽ không đuổi kịp
            HP1 -= floor((double)HP1 * 0.12);
            EXP1 -= floor((double)EXP1 * 0.1);
            HP2 -= floor((double)HP2 * 0.12);
            EXP2 -= floor((double)EXP2 * 0.1);
            HP1 = (HP1 > 666) ? 666 : ((HP1 <= 0) ? 0 : HP1);
            EXP1 = (EXP1 < 0) ? 0 : ((EXP1 > 600) ? 600 : EXP1);
            HP2 = (HP2 > 666) ? 666 : ((HP2 <= 0) ? 0 : HP2);
            EXP2 = (EXP2 < 0) ? 0 : ((EXP2 > 600) ? 600 : EXP2);
            return matrix[i][j]; // Trả về điểm số của taxi
        } else {
            // Nếu điểm số của taxi nhỏ hơn hoặc bằng cả Sherlock và Watson, họ sẽ đuổi kịp
            HP1 += ceil((double)HP1 * 0.12);
            EXP1 += ceil((double)EXP1 * 0.1);
            HP2 += ceil((double)HP2 * 0.12);
            EXP2 += ceil((double)EXP2 * 0.1);
            HP1 = (HP1 > 666) ? 666 : ((HP1 <= 0) ? 0 : HP1);
            EXP1 = (EXP1 < 0) ? 0 : ((EXP1 > 600) ? 600 : EXP1);
            HP2 = (HP2 > 666) ? 666 : ((HP2 <= 0) ? 0 : HP2);
            EXP2 = (EXP2 < 0) ? 0 : ((EXP2 > 600) ? 600 : EXP2);
            if (i >= 9 && j >= 9) break; // Đã gặp nhau tại biên của ma trận
            i++;
            j++;
        }
    }
    return matrix[i][j]; // Trả về điểm số của taxi
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // Đảm bảo email có ít nhất 1 ký tự '@' và chiều dài tối đa 100 ký tự
    if (strlen(email) > 100) {
        return -99; // Email không hợp lệ
    }
    const char *at_sign = strchr(email, '@');
    if (at_sign == nullptr || strchr(at_sign + 1, '@') != nullptr) {
        return -99; // Email không hợp lệ
    }

    // Tách chuỗi se từ email
    int se_start = at_sign - email;
    char se[101];
    strncpy(se, email, se_start);
    se[se_start] = '\0';

    // Kiểm tra độ dài mật khẩu
    int len = strlen(s);
    if (len < 8) {
        return -1; // Độ dài quá ngắn
    }
    if (len > 20) {
        return -2; // Độ dài quá dài
    }

    // Kiểm tra mật khẩu có chứa ký tự đặc biệt không
    const char *special_chars = "@#%$!";
    bool has_special_char = false;
    for (int i = 0; i < len; ++i) {
        if (strchr(special_chars, s[i]) != nullptr) {
            has_special_char = true;
            break;
        }
    }
    if (!has_special_char) {
        return -5; // Không chứa ký tự đặc biệt
    }

    // Kiểm tra xem mật khẩu có chứa chuỗi se không
    if (strstr(s, se) != nullptr) {
        return -(300 + (strstr(s, se) - s)); // Mật khẩu chứa chuỗi se
    }

    // Kiểm tra xem mật khẩu có chứa nhiều hơn 2 ký tự liên tiếp không
    for (int i = 0; i < len - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i); // Mật khẩu chứa nhiều hơn 2 ký tự liên tiếp
        }
    }

    return -10; // Mật khẩu hợp lệ
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_freq = 0;
    int max_length = 0;
    int max_freq_index = 0;

    for (int i = 0; i < num_pwds; ++i) {
        const char *pwd = arr_pwds[i];
        int freq = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(pwd, arr_pwds[j]) == 0) {
                freq++;
            }
        }
        int length = strlen(pwd);
        if (freq > max_freq || (freq == max_freq && length > max_length)) {
            max_freq = freq;
            max_length = length;
            max_freq_index = i;
        }
    }

    return max_freq_index;
}

// tìm số chính phương gần nhất
int nearestPerfectSquare(int n) {
    int smaller = sqrt(n);
    int larger = smaller + 1;
    int smaller_square = smaller * smaller;
    int larger_square = larger * larger;

    if (abs(n - smaller_square) < abs(n - larger_square)) {
        return smaller_square;
    } else {
        return larger_square;
    }
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////