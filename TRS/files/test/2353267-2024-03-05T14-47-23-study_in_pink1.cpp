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
void checkExp1(int & exp) {
    if (exp < 0) exp = 0;
    if (exp > 600) exp = 600;
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 <0 || e1 > 99) return -99;
    checkExp1(exp1);
    checkExp1(exp2);
    int d = 0;
    if (e1 >= 0 && e1 <=3) {
        d = e1*3 + exp1*7;
        if (d%2 == 0) exp1 =ceil(exp1 +d/200.0);
        else exp1 = ceil(exp1 -d/100.0);
        checkExp1(exp1);

    }
    if (e1 >= 4 && e1 <= 99) exp1 -= e1;
    if (e1 == 0) exp2 += 29;
    else if (e1 == 1) {
        exp2 +=45;
        checkExp1(exp2);
    }
    else if (e1 == 2) {
        exp2 += 75;
        checkExp1(exp2);
    }
    else if (e1 == 3) {
        exp2 += 149;
        checkExp1(exp2);
    }
    else if (e1 >=4 && e1 <=19) {
        exp2 += e1/4.000 + 19 +0.99;
        checkExp1(exp2);
        }
     else if (e1 >=20 && e1 <=49) {
        exp2 += e1/9.000 + 21 +0.99; 
        checkExp1(exp2); 
        }
    else if (e1 >=50 && e1 <=65) {
        exp2 += e1/16.000 + 17 +0.99; 
        checkExp1(exp2);
        }
    else if (e1 >= 66 && e1 <= 79) {
        exp2 += e1/4.000 + 19+0.99;
        checkExp1(exp2);
        if (exp2 > 200) {
            exp2 += e1/9.000 + 21+0.99;
            checkExp1(exp2);
        }
    }
    else if (e1 >= 80 && e1 <=99) {
        exp2 += e1/4.000 + 19+0.99;
        checkExp1(exp2);
        exp2 += e1/9.000 + 21+0.99;
        checkExp1(exp2);
        if (exp2 > 400) {
            exp2 += e1/16.000 + 17+0.99;
            checkExp1(exp2);
            exp2 += exp2 * 0.15+0.99;
            checkExp1(exp2);
        }
    }
    checkExp1(exp2);
    checkExp1(exp1);
    return exp1 + exp2;
}

// Task 2
void checkExp(int & exp) {
    if (exp < 0) exp = 0;
    if (exp > 600) exp = 600;
}
void checkHp(int & hp) {
    if (hp < 0) hp = 0;
    if (hp > 666) hp = 666;
}
void checkM1(int & m1) {
    if (m1 < 0) m1 = 0;
    if (m1 > 3000) m1 = 3000;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 <0 || E2 > 99) return -99;
    checkExp(EXP1);
    checkHp(HP1);
    checkM1(M1);
    // Con đường 01
    double P1;
    int s = static_cast<int>(sqrt(EXP1)); // Số chính phương gần nhất với EXP1
    if (EXP1 >= s) {
        P1 = 1.0;
    } else {
        P1 = (EXP1 / static_cast<double>(s) + 80.0) / 123.0;
    }

    // Con đường 02
    double moneySpent = 0.0;
    double moneyStart = M1*0.5; // nữa số tiền ban đầu

while (true) {
        //sự kiện 1
        if (E2%2==0 && M1 == 0) break;
        if (HP1 < 200) {
            HP1 = ceil(HP1+HP1*0.3); // tăng 30%
            checkHp(HP1);
            M1 -= 150;
            moneySpent += 150;
        } else {
            HP1 = ceil(HP1+HP1*0.1); // tăng 10%
            checkHp(HP1);
            M1 -= 70;
            moneySpent += 70;
        }
        //kiểm tra kiện để thoát vòng lặp tại sự kiện 1
        if (E2%2!=0 && moneyStart < moneySpent || E2%2 ==0 && M1 == 0) {
            HP1 = ceil(HP1-HP1*0.17);     // giảm 17% 
            EXP1 = ceil(EXP1 +EXP1*0.17); // tăng 17%
            checkExp(EXP1);
            checkHp(HP1);
            break;
        }
        // sự kiện 2
        if (EXP1 < 400) {
            M1 -= 200;
            moneySpent += 200;
        } 
        else {
            M1 -= 120;
            moneySpent += 120;
        }
            EXP1 = ceil (EXP1 +EXP1*0.13); // tăng 13%

        //kiểm tra kiện để thoát vòng lặp tại sự kiện 2    
        if (E2%2!=0 && moneyStart < moneySpent || E2%2 ==0 && M1 == 0) {
            HP1 = ceil(HP1-HP1*0.17);     // giảm 17% 
            EXP1 = ceil(EXP1 +EXP1*0.17); // tăng 17%
            checkExp(EXP1);
            checkHp(HP1);
            break;
        }
        //sự kiện 3
        if (EXP1 < 300) {
            M1 -= 100;
            moneySpent +=100;
        }
        else {
            M1 -= 120;
            moneySpent +=120;
        }
        EXP1 = ceil(EXP1 -EXP1*0.1); // giảm 10%
        checkExp(EXP1);

        //kiểm tra kiện để thoát vòng lặp tại sự kiện 3
        if (E2%2!=0 && moneyStart < moneySpent || E2%2 ==0 && M1 == 0) {
            HP1 = ceil(HP1-HP1*0.17);     // giảm 17% 
            EXP1 = ceil(EXP1 +EXP1*0.17); // tăng 17%
            checkExp(EXP1);
            checkHp(HP1);
            break;
        }
        if (E2%2 == 0) break;
    }
    double P2=0.0;
    s = static_cast<int>(sqrt(EXP1)); // Số chính phương gần nhất với EXP1
    if (EXP1 >= s) {
        P2 = 1.0;
    } else {
        P2 = (EXP1 / static_cast<double>(s) + 80.0) / 123.0;
    }
    // Con đường 03
    double P3;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = 0;
    if (E2 < 10) {
        i = E2;
    } else {
        int sum = E2 / 10 + E2 % 10;
        i = sum % 10;
    }

    P3 = P[i]/100.0;

    // Tính kết quả cuối cùng
    if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0) {
        EXP1 =ceil(EXP1 - EXP1*0.25) ; // Giảm 25%
    } else {
        double average_P = (P1 + P2 + P3) / 3.0;
        if (average_P < 0.5) {
            HP1 =ceil(HP1-HP1* 0.15); // Giảm 15%
            EXP1 =ceil(EXP1+EXP1* 0.15); // Tăng 15%
            checkExp(EXP1);
            checkHp(HP1);
        } else {
            HP1 = ceil(HP1-HP1*0.1); // Giảm 10%
            EXP1 = ceil(EXP1+EXP1*0.2); // Tăng 20%
            checkExp(EXP1);
            checkHp(HP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    int taxiMap[10][10] = {0};
    int scoreMap[10][10] = {0};

    // Tính điểm số cho mỗi ô của ma trận taxi
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            taxiMap[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // Tính điểm số cho mỗi ô của ma trận lưu điểm
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            // Đường chéo trái
            int maxLeft = 0;
            for (int k = i, l = j; k < 10 && l < 10; ++k, ++l) {
                maxLeft = max(maxLeft, taxiMap[k][l]);
            }

            // Đường chéo phải
            int maxRight = 0;
            for (int k = i, l = j; k < 10 && l >= 0; ++k, --l) {
                maxRight = max(maxRight, taxiMap[k][l]);
            }

            // Điểm số của Sherlock và Watson là điểm số lớn nhất của hai đường chéo
            scoreMap[i][j] = max(abs(maxLeft), abs(maxRight));
        }
    }

    // Tính vị trí gặp nhau
    int taxiPositiveCount = 0;
    int taxiNegativeCount = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int score = taxiMap[i][j];
            if (score > E3 * 2) {
                taxiPositiveCount++;
            } else if (score < -E3) {
                taxiNegativeCount++;
            }
        }
    }

    // Tính tổng của 2 số nếu đếm ra số 2 chữ số
    while (taxiNegativeCount >= 10) {
        taxiNegativeCount = taxiNegativeCount % 10 + taxiNegativeCount / 10;
    }
    while (taxiPositiveCount >= 10) {
        taxiPositiveCount = taxiPositiveCount % 10 + taxiPositiveCount / 10;
    }

    int position1 = taxiPositiveCount;
    int position2 = taxiNegativeCount;

    // Kiểm tra xem bắt kịp hay không
    if (abs(taxiMap[position1][position2]) > scoreMap[position1][position2]) {
        // Taxi không bị đuổi kịp
        HP1 = HP1 * 0.90 + 0.999;
        EXP1 = EXP1 * 0.88 + 0.999;
        HP2 = HP2 * 0.90 + 0.999;
        EXP2 = EXP2 * 0.88 + 0.999;
        checkHp(HP1);
        checkHp(HP2);
        checkExp1(EXP1);
        checkExp1(EXP2);
        return taxiMap[position1][position2];
    } else {
        // Taxi bị đuổi kịp
        HP1 = HP1 * 1.10 +0.999;
        EXP1 = EXP1 * 1.12 +0.999;
        HP2 = HP2 * 1.10 +0.999;
        EXP2 = EXP2 * 1.12 + 0.999;
        checkHp(HP1);
        checkHp(HP2);
        checkExp1(EXP1);
        checkExp1(EXP2);        
        return scoreMap[position1][position2];
    }
}
// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    // Lấy chuỗi se từ địa chỉ email
    string email_temp(email);
    size_t point = email_temp.find('@');
    string se = email_temp.substr(0, point);

    // Kiểm tra độ dài của chuỗi s
    int len = strlen(s);
    if (len < 8) return -1; // Độ dài ngắn hơn độ dài tối thiểu
    if (len > 20) return -2; // Độ dài dài hơn độ dài tối đa

    // Kiểm tra chuỗi s có chứa chuỗi se hay không
    const char* found = strstr(s, se.c_str());
    if (found != nullptr) return -300 - (found -s); // Trả về vị trí đầu tiên của chuỗi se

    // Kiểm tra s có chứa nhiều hơn 2 ký tự liên tiếp và giống nhau hay không
    for (int i = 0; i < len ; ++i) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            return -400 - i; // Trả về vị trí đầu tiên của chuỗi đầu tiên gồm nhiều hơn 2 ký tự liên tiếp và giống nhau
        }
    }

    // Kiểm tra s có chứa ít nhất 1 ký tự đặc biệt hay không
    bool special = false;
    for (int i = 0; i < len ; ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            special = true;
            break;
        }
    }
    if (!special) return -5; // Không chứa ký tự đặc biệt

    // Kiểm tra từng ký tự trong chuỗi s
    for (int i = 0; i < len ; ++i) {
        // Kiểm tra xem ký tự có phải là chữ số, chữ cái hoặc ký tự đặc biệt không
        if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')) {
            return i; // Trả về vị trí của ký tự đầu tiên vi phạm
        }
    }

    // Mật khẩu hợp lệ
    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    // Tạo một mảng để lưu số lần xuất hiện của mỗi mật khẩu
    int pass_cout[num_pwds] = {0};

    // Đếm số lần xuất hiện của mỗi mật khẩu trong mảng arr_pwds
    for (int i = 0; i < num_pwds; ++i) {
        for (int j = i; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                pass_cout[i]++;
            }
        }
    }

    // Tìm mật khẩu có số lần xuất hiện nhiều nhất và có độ dài dài nhất
    int maxCount = 0;
    int maxPass = 0;
    for (int i = 0; i < num_pwds; ++i) {
        if (pass_cout[i] > maxCount || (pass_cout[i] == maxCount && strlen(arr_pwds[i]) > strlen(arr_pwds[maxPass]))) {
            maxCount = pass_cout[i];
            maxPass = i;
        }
    }

    return maxPass;

}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////