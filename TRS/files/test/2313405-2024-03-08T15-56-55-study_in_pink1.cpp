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
    //4.1.1
    exp1 = (exp1 > 600) ? 600 : exp1;
    exp1 = (exp1 < 0) ? 0 : exp1;
    exp2 = (exp2 > 600) ? 600 : exp2;
    exp2 = (exp2 < 0) ? 0 : exp2;
    if (e1 < 0 || e1>99)
        return -99;
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
        else if (e1 == 3) {
            exp2 += 29 + 45 + 75;
        }
        int d;
        d = (e1 * 3 + exp1 * 7);
        if (d / 2 == 0) {
            exp1 = ceil(exp1 + (e1 * 3 + exp1 * 7) / 200.0);
        }
        else {
            exp1 = ceil(exp1 - (e1 * 3 + exp1 * 7) / 100.0);
        }
    }
    //4.1.2
    else if (e1 >= 4 && e1 <= 19) {
        exp2 = ceil(exp2 + (e1 / 4.0 + 19.0));
        exp1 = ceil(exp1 - e1);
    }
    else if (e1 >= 20 && e1 <= 49) {
        exp2 = ceil(exp2 + (e1 / 9.0 + 21.0));
        exp1 = ceil(exp1 - e1);
    }
    else if (e1 >= 50 && e1 <= 65) {
        exp2 = ceil(exp2 + (e1 / 16.0 + 17.0));
        exp1 = ceil(exp1 - e1);
    }
    else if (e1 >= 66 && e1 <= 79) {
        exp2 = ceil(exp2 + (e1 / 4.0 + 19.0));
        if (exp2 > 200) {
            exp2 =ceil(exp2 + (e1 / 9.0 + 21.0));
        }
        exp1 = ceil(exp1 - e1);
    }
    else if (e1 >= 80 && e1 <= 99) {
        exp2 = ceil(exp2 + (e1 / 4.0 + 19.0));
        exp2 = ceil(exp2+ (e1 / 9.0 + 21.0));
        if (exp2 > 400) {
            exp2 = ceil(exp2 + (e1 / 16.0 + 17.0));
        }
        exp2 = ceil(exp2 + (exp2 * 0.15));
        exp1 = ceil(exp1 - e1);
    }
    exp1 = (exp1 > 600) ? 600 : exp1;
    exp1 = (exp1 < 0) ? 0 : exp1;
    exp2 = (exp2 > 600) ? 600 : exp2;
    exp2 = (exp2 < 0) ? 0 : exp2;
    if (e1 < 0 || e1>99)
        return -99;
    return exp1 + exp2;
}

// Task 2
// Hàm để tìm số chính phương gần nhất của một số nguyên dương
int nearestPerfectSquare(int num) {
    int nearestRoot = round(sqrt(num)); // Lấy căn bậc hai gần nhất
    int lowerRoot = nearestRoot - 1;
    int higherRoot = nearestRoot + 1;

    // Tính khoảng cách của số đã cho đến ba số chính phương gần nhất
    int distToLower = abs(num - lowerRoot * lowerRoot);
    int distToNearest = abs(num - nearestRoot * nearestRoot);
    int distToHigher = abs(num - higherRoot * higherRoot);

    // Chọn số chính phương gần nhất
    int nearestPerfectSquare;
    if (distToLower <= distToNearest && distToLower <= distToHigher) {
        nearestPerfectSquare = lowerRoot;
    } else if (distToNearest <= distToLower && distToNearest <= distToHigher) {
        nearestPerfectSquare = nearestRoot;
    } else {
        nearestPerfectSquare = higherRoot;
    }

    return nearestPerfectSquare;
}

// Hàm để cập nhật kinh nghiệm và máu của người chơi sau khi gặp phải sự kiện
void updateEXPAndHP(int &M1, int &HP1, int &exp1, int e2) {
    // Một nửa lượng máu
    int halfM1 = M1 * 0.5;
    int M0 = M1;

    if (e2 % 2 == 1) { // Nếu sự kiện có chỉ số là số lẻ
        while (e2 % 2 == 1) {
            // Cập nhật lượng máu và kinh nghiệm tùy theo điều kiện
            if (HP1 < 200) {
                HP1 = ceil(HP1 + 0.3 * HP1);
                M1 -= 150;
            } else {
                HP1 = ceil(HP1 + 0.1 * HP1);
                M1 -= 70;
            }
            M1 = std::max(0, std::min(3000, M1)); // Đảm bảo lượng máu nằm trong giới hạn

            if (M0 - M1 > halfM1) {
                break;
            }

            int M1_loss_2 = (exp1 < 400) ? -200 : -120;
            M1 += M1_loss_2;
            exp1 = ceil(exp1 * 1.13);

            if (M0 - M1 > halfM1) {
                break;
            }

            int M1_loss_3 = (exp1 < 300) ? -100 : -120;
            M1 += M1_loss_3;
            exp1 = ceil(exp1 * 0.9);

            if (M0 - M1 > halfM1) {
                break;
            }
        }
        // Cập nhật lại lượng máu và kinh nghiệm cuối cùng
        HP1 = ceil(HP1 * 0.83);
        exp1 = ceil(exp1 * 1.17);
    } else { // Nếu sự kiện có chỉ số là số chẵn
        if (HP1 < 200) {
            HP1 = ceil(HP1 + 0.3 * HP1);
            M1 -= 150;
        } else {
            HP1 = ceil(HP1 + 0.1 * HP1);
            M1 -= 70;
        }


        if (M1 != 0) {
            int M1_loss_2 = (exp1 < 400) ? -200 : -120;
            M1 += M1_loss_2;
            exp1 = ceil(exp1 * 1.13);

            if (M1 != 0) {
                int M1_loss_3 = (exp1 < 300) ? -100 : -120;
                M1 += M1_loss_3;
                exp1 = ceil(exp1 * 0.9);
            }
        }

        // Cập nhật lại lượng máu và kinh nghiệm cuối cùng
        HP1 = ceil(HP1 * 0.83);
        exp1 = ceil(exp1 * 1.17);
    }
}

// Hàm để xử lý sự kiện khi người chơi gặp phải vấn đề vận chuyển hành lý
int traceLuggage(int &HP1, int &exp1, int &M1, int e2) {
    if (e2 < 0 || e2 > 99) // Kiểm tra giá trị hợp lệ của chỉ số sự kiện
        return -99;
    exp1 = (exp1 > 600) ? 600 : exp1;
    exp1 = (exp1 < 0) ? 0 : exp1;
    HP1 = (HP1 < 0) ? 0 : HP1;
    HP1 = (HP1 > 666) ? 666 : HP1;
    M1 = (M1 < 0) ? 0 : M1;
    M1 = (M1 > 3000) ? 3000 : M1;
    // Kiểm tra và đảm bảo giá trị các biến nằm trong giới hạn


    float S = nearestPerfectSquare(exp1); // Tìm số chính phương gần nhất
    float P1 = (exp1 >= S) ? 100.0 : roundf((exp1 * 1.00f / S + 80) / 123 * 100); // Tính tỷ lệ thành công P1

    // Cập nhật lượng máu và kinh nghiệm theo sự kiện
    updateEXPAndHP(M1, HP1, exp1, e2);

    float S2 = nearestPerfectSquare(exp1); // Tìm số chính phương gần nhất sau khi cập nhật
    int HP_1 = HP1;
    int exp_1 = exp1;
    float P2 = (exp1 >= S2) ? 100.0 : roundf((exp1 * 1.00f / S + 80) / 123 * 100); // Tính tỷ lệ thành công P2

    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}; // Mảng P
    int i = (e2 < 10) ? e2 : ((e2 / 10 + e2 % 10) % 10); // Tính chỉ số của mảng P dựa trên e2
    float P3 = P[i]; // Lấy giá trị P3 từ mảng P

    // Tính tỷ lệ thành công trung bình P_averange
    float P_averange = (P1 + P2 + P3) / 3;

    // Xử lý việc cập nhật lượng máu và kinh nghiệm cuối cùng của người chơi dựa trên tỷ lệ thành công trung bình
    if (P_averange >= 100) {
        exp1 = ceil(exp1 * 0.75);
    } else {
        if (P_averange < 50) {
            exp1 = ceil(exp_1 * 1.15);
            HP1 = ceil(HP_1 * 0.85);
       
        } else {
            exp1 = ceil(exp1 * 1.2);
            HP1 = ceil(HP1 * 0.9);
         
        }
    }
    if (e2 < 0 || e2 > 99) // Kiểm tra giá trị hợp lệ của chỉ số sự kiện
        return -99;
    exp1 = (exp1 > 600) ? 600 : exp1;
    exp1 = (exp1 < 0) ? 0 : exp1;
    HP1 = (HP1 < 0) ? 0 : HP1;
    HP1 = (HP1 > 666) ? 666 : HP1;
    M1 = (M1 < 0) ? 0 : M1;
    M1 = (M1 > 3000) ? 3000 : M1;
    return HP1 + exp1 + M1; // Trả về tổng lượng máu, kinh nghiệm và tiền của người chơi
}




// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    EXP1 = (EXP1 > 600) ? 600 : EXP1;
    EXP1 = (EXP1 < 0) ? 0 : EXP1;
    EXP2 = (EXP2 > 600) ? 600 : EXP2;
    EXP2 = (EXP2 < 0) ? 0 : EXP2;
    HP1 = (HP1 < 0) ? 0 : HP1;
    HP1 = (HP1 > 666) ? 666 : HP1;
    HP2 = (HP2 < 0) ? 0 : HP2;
    HP2 = (HP2 > 666) ? 666 : HP2;
    if (E3 > 99 || E3 < 0)
        return -99;

        // Khởi tạo ma trận 10x10 với giá trị 0
        int taxi_matrix[10][10] = { 0 };
        int M_i = 0, M_j = 0;
        // Tính điểm số của chiếc taxi tại mỗi vị trí
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                taxi_matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                // Tìm điểm gặp nhau của Sherlock và Watson với taxi
                if (taxi_matrix[i][j] > (E3 * 2)) {
                    M_i++;
                }
                if (taxi_matrix[i][j] < (-E3)) {
                    M_j++;
                }
                if (M_i >= 10 && M_i < 100) {
                    M_i = M_i / 10 + M_i % 10;
                }
                if (M_j >= 10 && M_j < 100) {
                    M_j = M_j / 10 + M_j % 10;
                }

            }
        }

        // Tính điểm số tối đa của Sherlock và Watson tại mỗi vị trí
        int max_points[10][10] = { 0 };
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                int left_diagonal_points[10], right_diagonal_points[10];
                for (int k = 0; i + k < 10 && j - k >= 0; ++k) {
                    left_diagonal_points[k] = taxi_matrix[i + k][j - k];
                }
                for (int k = 0; i + k < 10 && j + k < 10; ++k) {
                    right_diagonal_points[k] = taxi_matrix[i + k][j + k];
                }
                int left_max = 0, right_max = 0;
                for (int k = 0; i + k < 10 && j - k >= 0; ++k) {
                    if (left_diagonal_points[k] > left_max) {
                        left_max = left_diagonal_points[k];
                    }
                }
                for (int k = 0; i + k < 10 && j + k < 10; ++k) {
                    if (right_diagonal_points[k] > right_max) {
                        right_max = right_diagonal_points[k];
                    }
                }
                max_points[i][j] = max(left_max, right_max);
            }
        }

        // Kiểm tra và cập nhật EXP và HP cho Sherlock và Watson
        int taxi_points = taxi_matrix[M_i][M_j];
        int sherlock_watson_max = max_points[M_i][M_j];

        if (abs(taxi_points) > 2 * sherlock_watson_max) {
            // Họ không đuổi kịp taxi
            EXP1 = ceil(EXP1 * 0.88);
            HP1 = ceil(HP1 * 0.90);
            EXP2 = ceil(EXP2 * 0.88);
            HP2 = ceil(HP2 * 0.90);
            return taxi_points;
        }
        else {
            // Họ đuổi kịp taxi
            EXP1 = ceil(EXP1 * 1.12);
            HP1 = ceil(HP1 * 1.10);
            EXP2 = ceil(EXP2 * 1.12);
            HP2 = ceil(HP2 * 1.10);
            return sherlock_watson_max;
        }
        EXP1 = (EXP1 > 600) ? 600 : EXP1;
        EXP1 = (EXP1 < 0) ? 0 : EXP1;
        EXP2 = (EXP2 > 600) ? 600 : EXP2;
        EXP2 = (EXP2 < 0) ? 0 : EXP2;
        HP1 = (HP1 < 0) ? 0 : HP1;
        HP1 = (HP1 > 666) ? 666 : HP1;
        HP2 = (HP2 < 0) ? 0 : HP2;
        HP2 = (HP2 > 666) ? 666 : HP2;
        if (E3 > 99 || E3 < 0)
            return -99;

        return -1;
}

// Task 4
string exse(const char* email) {
    const char* po = strchr(email, '@');
    if (po != nullptr)
    {
        return string(email, po - email);
    }
    else {
        return "";
    }
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // Kiểm tra độ dài mật khẩu
    int s_length = strlen(s);
    if (s_length < 8) return -1;                      // Độ dài ngắn hơn tối thiểu
    if (s_length > 20) return -2;                     // Độ dài dài hơn tối đa
    // Kiểm tra chuỗi 'se'
    string se = exse(email);
    if (strstr(s, se.c_str()) != nullptr) {
        return -(300 + strstr(s, se.c_str()) - s);
    }
             // Chứa chuỗi 'se'

    // Kiểm tra ký tự đặc biệt
    bool hasSpecialChar = false;
    for (int i = 0; i < s_length; ++i) {
        if (!(isalnum(s[i]) || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')) {
            return -5;                              // Không có ký tự đặc biệt
        }
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            hasSpecialChar = true;
        }
    }
    if (!hasSpecialChar) return -5;                 // Không có ký tự đặc biệt

    // Kiểm tra các ký tự liên tiếp và giống nhau
    for (int i = 0; i < s_length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);                      // Nhiều hơn 2 ký tự liên tiếp và giống nhau
        }
    }
    // Kiểm tra vị trí ký tự đầu tiên vi phạm 
    for (int i = 0; i < s_length; ++i) {
        if (!isalnum(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') {
            return i;
        }
    }

    // Mật khẩu hợp lệ
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    // Struct để lưu thông tin về mật khẩu
    struct PasswordInfo {
        const char* password;
        int occurrences;
        int length;
    };

    PasswordInfo max_password = { nullptr, 0, 0 };

    // Tìm số lần xuất hiện và độ dài của mỗi mật khẩu
    for (int i = 0; i < num_pwds; ++i) {
        // Đếm số lần xuất hiện
        int occurrences = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                ++occurrences;
            }
        }

        // Kiểm tra xem mật khẩu hiện tại có xuất hiện nhiều hơn mật khẩu có số lần xuất hiện lớn nhất không
        if (occurrences > max_password.occurrences ||
            (occurrences == max_password.occurrences && strlen(arr_pwds[i]) > max_password.length)) {
            max_password.password = arr_pwds[i];
            max_password.occurrences = occurrences;
            max_password.length = strlen(arr_pwds[i]);
        }
    }

    // Tìm vị trí đầu tiên của mật khẩu đúng trong mảng arr_pwds
    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(arr_pwds[i], max_password.password) == 0) {
            return i;
        }
    }

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////