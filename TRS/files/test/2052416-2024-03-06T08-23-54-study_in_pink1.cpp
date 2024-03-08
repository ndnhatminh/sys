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

// Supporting functions
int adjustHP(int hp) {
    if (hp > 666) {
        return 666;
    } else if (hp < 0) {
        return 0;
    } else {
        return hp;
    }
}

int adjustEXP(int exp) {
    if (exp > 600) {
        return 600;
    } else if (exp < 0) {
        return 0;
    } else {
        return exp;
    }
}

int adjustMoney(int money) {
    if (money > 3000) {
        return 3000;
    } else if (money < 0) {
        return 0;
    } else {
        return money;
    }
}

bool validE(int e) {
    return (e >= 0 && e <= 99);
}

// Task 1 case 1
int task1_case1(int & exp1, int & exp2, int e1) {
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
            // Giải thích cả 3 thông tin, cộng thêm EXP tương ứng
            exp2 += 29 + 45 + 75;
            break;
        default:
            // Trường hợp không hợp lệ
            return -1000; // Trả về -1000 để chỉ ra lỗi
    }
    exp2 = adjustEXP(exp2); //adjust after modifying
    int D = e1 * 3 + exp1 * 7;

    // Kiểm tra xem D là số chẵn hay lẻ
    if (D % 2 == 0) {
        exp1 = adjustEXP(exp1 + ceil(D / 200.0));
    } else {
        exp1 = adjustEXP(exp1 - floor(D / 100.0));
    }

    return exp1 + exp2;
}

int task1_case2(int & exp1, int & exp2, int e1){
    int additionalExp_info1 = ceil(e1 / 4.0) + 19;
    int additionalExp_info2 = ceil(e1 / 9.0) + 21;
    int additionalExp_info3 = ceil(e1 / 16.0) + 17;

    if (e1 >= 4 && e1 <= 19) {
        exp2 += additionalExp_info1;
    } else if (e1 >= 20 && e1 <= 49) {
        exp2 += additionalExp_info2;
    } else if (e1 >= 50 && e1 <= 65) {
        exp2 += additionalExp_info3;
    } else if (e1 >= 66 && e1 <=79) {
        exp2 += additionalExp_info1;
        exp2 = adjustEXP(ceil(exp2));
        if (exp2 > 200) {
            exp2 += additionalExp_info2;
            exp2 = adjustEXP(ceil(exp2));
        }
    } else if (e1 >= 80 && e1 <= 99) {
        exp2 += additionalExp_info1;
        exp2 = adjustEXP(ceil(exp2));
        exp2 += additionalExp_info2;
        exp2 = adjustEXP(ceil(exp2));
        if (exp2 > 400) {
            exp2 += additionalExp_info3;
            exp2 = adjustEXP(ceil(exp2));
            exp2 = adjustEXP(ceil(exp2 * 1.15));
        }
    }
    exp2 = adjustEXP(ceil(exp2));
    exp1 = adjustEXP(exp1 - e1);
    return exp1 + exp2;
}

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (!validE(e1))
        return -99;
    exp1 = adjustEXP(exp1);
    exp2 = adjustEXP(exp2);
    if (e1 <= 3) return task1_case1(exp1, exp2, e1);
    else return task1_case2(exp1, exp2, e1);
}

// Task 2

int nearestSquare(int num) {
    // Tìm căn bậc hai của num
    int sqrtNum = sqrt(num);

    // Kiểm tra xem num có phải là số chính phương không
    if (sqrtNum * sqrtNum == num) {
        return num; // Nếu num là số chính phương, trả về ngay
    } else {
        // Nếu num không là số chính phương, tìm số chính phương gần nhất
        int lowerSquare = sqrtNum * sqrtNum;
        int upperSquare = (sqrtNum + 1) * (sqrtNum + 1);

        // Trả về số chính phương gần nhất
        if (num - lowerSquare <= upperSquare - num) {
            return lowerSquare;
        } else {
            return upperSquare;
        }
    }
}

void event1_road2(int & HP1, int & EXP1, int & M1){
    if (HP1 < 200) {
        HP1 = ceil(HP1 * 1.3);
        M1 = M1 - 150;
    } else {
        HP1 = ceil(HP1 * 1.1);
        M1 = M1 - 70;
    }
    HP1 = adjustHP(HP1);
    M1 = adjustMoney(M1);
}

void event2_road2(int & HP1, int & EXP1, int & M1) {
    if (EXP1 < 400) {
        M1 = M1 - 200;
    } else {
        M1 = M1 - 120;
    }
    M1 = adjustMoney(M1);
    EXP1 = adjustEXP(ceil(EXP1 * 1.13));
}

void event3_road2(int & EXP1, int & M1) {
    if (EXP1 < 300) {
        M1 = M1 - 100;
    } else {
        M1 = M1 - 120;
    }
    M1 = adjustMoney(M1);
    EXP1 = adjustEXP(ceil(EXP1 * 0.9));
}

double probability_road1(int &exp1) {
    // Tính số chính phương gần nhất với EXP1
    int s = nearestSquare(exp1);

    // Tính xác suất P1
    double probability;
    if (exp1 >= s) {
        probability = 100.0; // Nếu EXP1 >= S, xác suất là 100%
    } else {
        probability = (exp1 * 1.0 / s + 80) / 123;
    }

    return probability;
}

double probability_road2(int & HP1, int & EXP1, int & M1, int E2){
    float halfBudget = M1 / 2.0;    
    if (E2 % 2 == 1) {
        while (M1 >= halfBudget) {
            event1_road2(HP1, EXP1, M1);
            if (M1 < halfBudget) break;
            event2_road2(HP1, EXP1, M1);
            if (M1 < halfBudget) break;
            event3_road2(EXP1, M1);
        }

    } else {
        if (M1 > 0) {
            event1_road2(HP1, EXP1, M1);
        }
        if (M1 > 0) {
            event2_road2(HP1, EXP1, M1);
        }
        if (M1 > 0) {
            event3_road2(EXP1, M1);
        }
    }
    HP1 = adjustHP(ceil(HP1 * 0.83));
    EXP1 = adjustEXP(ceil(EXP1 * 1.17));

    int s = nearestSquare(EXP1);

    // Tính xác suất P1
    double probability;
    if (EXP1 >= s) {
        probability = 100.0; // Nếu EXP1 >= S, xác suất là 100%
    } else {
        probability = (EXP1 * 1.0 / s + 80) / 123;
    }

    return probability;

}

double probability_road3(int & HP1, int & EXP1, int & M1, int E2) {
    int p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = (E2 / 10 + E2 % 10) % 10;
    return p[i];
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (!validE(E2))
        return -99;
        
    HP1 = adjustHP(HP1);
    EXP1 = adjustEXP(EXP1);
    M1 = adjustMoney(M1);

    double p1 = probability_road1(EXP1);
    double p2 = probability_road2(HP1, EXP1, M1, E2);
    double p3 = probability_road3(HP1, EXP1, M1, E2);


    if (p1 + p2 + p3 >= 300) {
        EXP1 = adjustEXP(ceil(EXP1 * 0.75));
    } else {
        double p = (p1 + p2 + p3) / 3;
        if (p < 0.5) {
            HP1 = adjustHP(ceil(HP1 * 0.85));
            EXP1 = adjustEXP(ceil(EXP1 * 1.15));
        } else {
            HP1 = adjustHP(ceil(HP1 * 0.9));
            EXP1 = adjustEXP(ceil(EXP1 * 1.2));
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3

int sum_to_one_digit(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    if (sum >= 10) {
        return sum_to_one_digit(sum);
    }
    return sum;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (!validE(E3))
        return -99;
    int matrix_taxi[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrix_taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    HP1 = adjustHP(HP1);
    EXP1 = adjustEXP(EXP1);
    HP2 = adjustHP(HP2);
    EXP2 = adjustEXP(EXP2);

    int num_of_gt_e3x2 = 0; // #greater than e3*2
    int num_of_lt_me3 = 0; // # less than -e3
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (matrix_taxi[i][j] > E3*2) {
                num_of_gt_e3x2++;
            }
            else if (matrix_taxi[i][j] < (E3 * (-1))) {
                num_of_lt_me3++;
            }
        }
    }
    int meet_i = sum_to_one_digit(num_of_gt_e3x2);
    int meet_j = sum_to_one_digit(num_of_lt_me3);
    int taxi_score = matrix_taxi[meet_i][meet_j];
    int detective_score = -1e9;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i - j == meet_i - meet_j || i + j == meet_i + meet_j) {
                if (matrix_taxi[i][j] > detective_score) {
                    detective_score = matrix_taxi[i][j];
                }
            }
        }
    }

    detective_score = abs(detective_score);

    if (abs(taxi_score) > detective_score) {
        EXP1 = adjustEXP(ceil(EXP1 * 0.88));
        HP1 = adjustHP(ceil(HP1 * 0.9));
        EXP2 = adjustEXP(ceil(EXP2 * 0.88));
        HP2 = adjustHP(ceil(HP2 * 0.9));
        return taxi_score;
    } else {
        EXP1 = adjustEXP(ceil(EXP1 * 1.12));
        HP1 = adjustHP(ceil(HP1 * 1.1));
        EXP2 = adjustEXP(ceil(EXP2 * 1.12));
        HP2 = adjustHP(ceil(HP2 * 1.1));
        return detective_score;
    }

    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int len = strlen(s);
    if (len < 8)
        return -1;
    if (len > 20)
        return -2;
    // Xác định độ dài của chuỗi "se" bằng cách tính vị trí của ký tự '@' trong chuỗi "email"
    int seLength = strcspn(email, "@");

    // Tạo và cấp phát bộ nhớ cho chuỗi "se" với độ dài đã xác định
    char *se = new char[seLength + 1]; // +1 để lưu ký tự kết thúc chuỗi '\0'

    // Sao chép các ký tự từ chuỗi "email" vào chuỗi "se" cho đến khi gặp ký tự '@'
    strncpy(se, email, seLength);
    se[seLength] = '\0'; // Thêm ký tự kết thúc chuỗi
    if (strstr(s, se) != nullptr) {
        return (-(300 + (strstr(s, se) - s)));
    }

    // Kiểm tra nhiều hơn 2 ký tự liên tiếp giống nhau
    for (int i = 0; i < len - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
            return -(400 + i);
    }

    // Kiểm tra ký tự đặc biệt
    bool hasSpecialChar = false;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            hasSpecialChar = true;
    }
    if (!hasSpecialChar)
        return -5;

    // Kiểm tra các điều kiện khác
    for (int i = 0; i < len; ++i) {
        // Kiểm tra ký tự không hợp lệ
        if (!((s[i] >= '0' && s[i] <= '9') || 
              (s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= 'A' && s[i] <= 'Z') ||
              (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')))
            return i;
    }
    return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    // Đếm số lần xuất hiện của từng mật khẩu
    int maxCount = 0;
    int maxLength = 0;
    const char * correctPassword = nullptr;

    for (int i = 0; i < num_pwds; ++i) {
        const char * currentPassword = arr_pwds[i];
        int currentCount = 0;
        int currentLength = strlen(currentPassword);

        // Đếm số lần xuất hiện của mật khẩu hiện tại
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(currentPassword, arr_pwds[j]) == 0) {
                currentCount++;
            }
        }

        // Kiểm tra nếu mật khẩu hiện tại xuất hiện nhiều hơn mật khẩu đúng hiện tại
        if (currentCount > maxCount || (currentCount == maxCount && currentLength > maxLength)) {
            correctPassword = currentPassword;
            maxCount = currentCount;
            maxLength = currentLength;
        }
    }

    // Tìm vị trí đầu tiên của mật khẩu đúng trong mảng arr_pwds
    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(arr_pwds[i], correctPassword) == 0) {
            return i;
        }
    }

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////