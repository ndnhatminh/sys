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

//hàm làm tròn số
int roundUp(double num) {
    if (num - static_cast<int>(num) != 0) { // Kiểm tra nếu số không phải là số nguyên
        num = static_cast<int>(num) + 1; // Làm tròn số lên
    }
    return static_cast<int>(num); // Chuyển đổi về kiểu int và trả về
}

//hàm giới hạn giá trị
int limit(int value, int minValue, int maxValue) {
    // Nếu giá trị nhỏ hơn giá trị nhỏ nhất cho phép, gán bằng giá trị nhỏ nhất
    if (value < minValue) {
        return minValue;
    }
    // Nếu giá trị lớn hơn giá trị lớn nhất cho phép, gán bằng giá trị lớn nhất
    else if (value > maxValue) {
        return maxValue;
    }
    // Nếu giá trị nằm trong khoảng cho phép, trả về giá trị đó
    else {
        return value;
    }
}

//hàm tìm số chính phương S gần EXP1 nhất
int find_S(int EXP1) {
    // Tìm số chính phương lớn hơn EXP1
    int largerSquare = EXP1 + 1;
    while (largerSquare * largerSquare <= EXP1) {
        largerSquare++;
    }
    
    // Tìm số chính phương nhỏ hơn EXP1
    int smallerSquare = EXP1 - 1;
    while (smallerSquare * smallerSquare >= EXP1) {
        smallerSquare--;
    }

    // Chọn số chính phương gần EXP1 hơn và trả về
    if (EXP1 - smallerSquare <= largerSquare - EXP1) {
        return smallerSquare * smallerSquare;
    } else {
        return largerSquare * largerSquare;
    }
}

//hàm trị tuyệt đối
int Abs(int num){
    if(num<0){
        num=-num;
    }
    return num;
}

//hàm tìm số lớn hơn
int myMax(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 >= 0 && e1 <= 3) {
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
                exp2 += 29 + 45 + 75;
                break;
            default:
                return -99; // Sự kiện không hợp lệ
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            // Nếu D là số chẵn, Sherlock đoán Afghanistan (đoán đúng)
            double exp01;
            exp01=exp1;
            exp01 += D / 200.0;
            exp1=roundUp(exp01);
        } else {
           double exp01;
           exp01=exp1;
           exp01 -=D/100.0;
           exp1=roundUp(exp01);
        }
    } else if (e1 >= 4 && e1 <= 99) {
        int temp_exp = exp2;
        if (e1 >= 4 && e1 <= 19) {
            exp2 += roundUp(e1 / 4.0) + 19;
        } else if (e1 >= 20 && e1 <= 49) {
            exp2 += roundUp(e1 / 9.0) + 21;
        } else if (e1 >= 50 && e1 <= 65) {
            exp2 += roundUp(e1 / 16.0) + 17;
        } else if (e1 >= 66 && e1 <= 79) {
            exp2 += roundUp(e1 / 4.0) + 19;
            if (exp2 > 200) {
                exp2 += roundUp(e1 / 9.0) + 21;
            }
        } else if (e1 >= 80 && e1 <= 99) {
            exp2 += roundUp(e1 / 4.0) + 19;
            exp2 += roundUp(e1 / 9.0) + 21;
            if (exp2 > 400) {
                exp2 += roundUp(e1 / 16.0) + 17;
                exp2 = limit(exp2, 0, 600);
                exp2 = roundUp(exp2 * 1.15);
            }
        } else {
            return -99; // Sự kiện không hợp lệ
        }
        exp1 -= e1;
    } else {
        return -99; // Sự kiện không hợp lệ
    }
    // Đảm bảo rằng exp1 và exp2 nằm trong phạm vi cho phép
    exp1 = limit(exp1, 0, 600);
    exp2 = limit(exp2, 0, 600); 
    
    return exp1 + exp2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
     if(E2<0 || E2>99){
        return -99;
    }
   
    //con đường 1
    int S = 0;
    double P1=0.0;
    S = find_S(EXP1);
    if (EXP1 >= S) {
        P1 = 1.0;
    } else {
        P1 = (static_cast<double>(EXP1) / static_cast<double>(S) + 80.0) / 123.0;
    }
     //con đường 2
    double P2 = 0.0; // Xác suất tìm thấy vali
    int half_M = roundUp(static_cast<double>(M1) / 2.0);
    if (E2 % 2 == 1) { //trường hợp số lẻ và sẽ lặp tới khi tiêu hết hơn 1/2 số tiền ban đầu có
        while (M1 >= half_M) {
            if (HP1 < 200) {
                //mua đồ ăn và thức uống
                HP1 = roundUp(static_cast<double>(HP1) * 0.3 + static_cast<double>(HP1));
                HP1 = limit(HP1, 0, 666);
                M1 -= 150;
                M1 = limit(M1, 0, 3000);
            } else {
                HP1 = roundUp(static_cast<double>(HP1) * 0.1 + static_cast<double>(HP1));
                HP1 = limit(HP1, 0, 666);
                M1 -= 70;
                M1 = limit(M1, 0, 3000);
            }
               if (M1 < half_M) {
                break; // Thoát khỏi vòng lặp ngay lập tức khi điều kiện được thỏa mãn
            }

            //tiền di chuyển bằng taxi hoặc xe ngựa
            if (EXP1 < 400) {
                M1 -= 200;
                M1 = limit(M1, 0, 3000);
                EXP1 = roundUp(static_cast<double>(EXP1) * 0.13 + static_cast<double>(EXP1));
                EXP1 = limit(EXP1, 0, 600);
            } else {
                M1 -= 120;
                M1 = limit(M1, 0, 3000);
                EXP1 = roundUp(static_cast<double>(EXP1) * 0.13 + static_cast<double>(EXP1));
                EXP1 = limit(EXP1, 0, 600);
            }
                if (M1 <= half_M) {
                break; // Thoát khỏi vòng lặp ngay lập tức khi điều kiện được thỏa mãn
            }
            //tiền cho ông ăn xin
            if (EXP1 < 300) {
                M1 -= 100; 
                M1 = limit(M1, 0, 3000);
                EXP1 = roundUp(static_cast<double>(EXP1) - static_cast<double>(EXP1) * 0.1);
                EXP1 = limit(EXP1, 0, 600);
            } else {
                M1 -= 120; 
                M1 = limit(M1, 0, 3000);
                EXP1 = roundUp(static_cast<double>(EXP1) - static_cast<double>(EXP1) * 0.1);
                EXP1 = limit(EXP1, 0, 600);
            }
            if (M1 <= half_M) {
                break; // Thoát khỏi vòng lặp ngay lập tức khi điều kiện được thỏa mãn
            }
        }
    } else if (E2 % 2 == 0) { // Sự kiện chẵn
        // Thực hiện một lần các sự kiện
        //mua đồ ăn và thức uống
        if (HP1 < 200) {
            HP1 = roundUp(static_cast<double>(HP1) * 0.3 + static_cast<double>(HP1));
            HP1 = limit(HP1, 0, 666);
            M1 -= 150;
            M1 = limit(M1, 0, 3000);
        } else {
            HP1 = roundUp(static_cast<double>(HP1) * 0.1 + static_cast<double>(HP1));
            HP1 = limit(HP1, 0, 666);
            M1 -= 70;
            M1 = limit(M1, 0, 3000);
        }

        //tiền đi xe ngựa/taxi
        if (EXP1 < 400) {
            M1 -= 200;
            M1 = limit(M1, 0, 3000);
            EXP1 = roundUp(static_cast<double>(EXP1) * 0.13 + static_cast<double>(EXP1));
            EXP1 = limit(EXP1, 0, 600);
        } else {
            M1 -= 120;
            M1 = limit(M1, 0, 3000);
            EXP1 = roundUp(static_cast<double>(EXP1) * 0.13 + static_cast<double>(EXP1));
            EXP1 = limit(EXP1, 0, 600);
        }

        //tiền cho ông ăn xin
        if (EXP1 < 300) {
            M1 -= 100; 
            M1 = limit(M1, 0, 3000);
            EXP1 = roundUp(static_cast<double>(EXP1) - static_cast<double>(EXP1) * 0.1);
            EXP1 = limit(EXP1, 0, 600);
        } else {
            M1 -= 120;
            M1 = limit(M1, 0, 3000);
            EXP1 = roundUp(static_cast<double>(EXP1) - static_cast<double>(EXP1) * 0.1);
            EXP1 = limit(EXP1, 0, 600);
        }
    }

    // Cập nhật remaining_money, remaining_HP, remaining_EXP tương ứng
    //Lúc này HP1 sẽ giảm 17%, đồng thời EXP1 tăng 17%
    HP1 = roundUp(static_cast<double>(HP1) - 0.17 * static_cast<double>(HP1));
    HP1 = limit(HP1, 0, 666);
    EXP1 = roundUp(static_cast<double>(EXP1) + 0.17 * static_cast<double>(EXP1));
    EXP1 = limit(EXP1, 0, 600);
    double D = find_S(EXP1);
    if (EXP1 > D) {
        P2 = 1.0;
    } else {
        P2 = (static_cast<double>(EXP1) / static_cast<double>(D) + 80.0) / 123.0;
    }
    
    //con đường 3
    int i;
    if (E2 < 10) {
        i = E2;
    } else {
        i = (E2 / 10 + E2 % 10) % 10;
    }
    double probabilities[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}; // Mảng chứa các xác suất
    double P3 = probabilities[i]; // Truy xuất giá trị xác suất tương ứng với chỉ số i

    if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0) {
        EXP1 = roundUp(static_cast<double>(EXP1) * 0.75);
        EXP1 = limit(EXP1, 0, 600);
    } else {
        double P = (P1 + P2 + P3) / 3.0;
        if (P >= 0.5) { // HP1 sẽ giảm 10% và EXP1 tăng 20%
            EXP1 = roundUp(static_cast<double>(EXP1) * 1.2);
            EXP1 = limit(EXP1, 0, 600);
            HP1 = roundUp(static_cast<double>(HP1) * 0.9);
            HP1 = limit(HP1, 0, 666);
        } else if (P < 0.5) { // HP1 sẽ giảm 15% và EXP1 tăng 15%
            EXP1 = roundUp(static_cast<double>(EXP1) * 1.15);
            EXP1 = limit(EXP1, 0, 600);
            HP1 = roundUp(static_cast<double>(HP1) * 0.85);
            HP1 = limit(HP1, 0, 666);
        }
    }
    
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
        // Kiểm tra giá trị của E3
    if (E3 < 0 || E3 > 99) {
        return -99;
    }
    // Khởi tạo ma trận 10x10 với giá trị 0
    int taxi_matrix[10][10] = {0};
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            // Tính điểm số cho mỗi ô trong ma trận taxi_matrix
            taxi_matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // Tính số giá trị dương lớn hơn E3*2
    int count_pos = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (taxi_matrix[i][j] > E3*2) {
                count_pos++;
            }
        }
    }
    while(count_pos>9){
    int chuc  = count_pos/10;
    int   dv  = count_pos - chuc*10;
    count_pos = chuc + dv;
    }
    int i=count_pos;

    // Tính số giá trị âm nhỏ hơn -E3
    int count_neg = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (taxi_matrix[i][j] < -E3) {
                count_neg++;
            }
        }
    }
    while(count_neg>9){
    int chuc  = count_neg/10;
    int   dv  = count_neg - chuc*10;
    count_neg = chuc + dv;
    }
    int j=count_neg;
    //sau bước này ta đã có tọa độ [i][j] mà sherlock đuổi kịp taxi
    
    int sherlock_watson_matrix[10][10]={0};
    //bd
    // Tính điểm cho từng ô của ma trận Sherlock và Watson
    for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
        // Tính giá trị lớn nhất trong đường chéo trái và đường chéo phải của chiếc taxi
        int max_diagonal_score = (taxi_matrix[i][j]);

        // Duyệt qua đường chéo trái (lên trên và sang trái)
        int row = i - 1;
        int col = j - 1;
        while (row >= 0 && col >= 0) {
            max_diagonal_score = myMax(max_diagonal_score, (taxi_matrix[row][col]));
            row--;
            col--;
        }

        // Duyệt qua đường chéo phải (lên trên và sang phải)
        row = i - 1;
        col = j + 1;
        while (row >= 0 && col < 10) {
            max_diagonal_score = myMax(max_diagonal_score, (taxi_matrix[row][col]));
            row--;
            col++;
        }

        // Duyệt qua đường chéo dưới (xuống dưới và sang phải)
        row = i + 1;
        col = j + 1;
        while (row < 10 && col < 10) {
            max_diagonal_score = myMax(max_diagonal_score, (taxi_matrix[row][col]));
            row++;
            col++;
        }

        // Duyệt qua đường chéo dưới (xuống dưới và sang trái)
        row = i + 1;
        col = j - 1;
        while (row < 10 && col >= 0) {
            max_diagonal_score = myMax(max_diagonal_score, (taxi_matrix[row][col]));
            row++;
            col--;
        }

        // Lưu giá trị điểm của Sherlock và Watson tại ô (i, j)
        sherlock_watson_matrix[i][j] = max_diagonal_score;
    }
}
    //kt
    // Tính điểm của taxi và Sherlock-Watson tại vị trí gặp nhau
    int taxi_score = taxi_matrix[i][j];
    // Tính điểm cho từng ô trong ma trận của Sherlock và Watso
    int sherlock_watson_score = sherlock_watson_matrix[i][j];
     // Kiểm tra liệu Sherlock và Watson có đuổi kịp taxi hay không
    if (Abs(taxi_score) > sherlock_watson_score) {
        // Nếu không đuổi kịp
        // Cập nhật EXP và HP cho Sherlock và Watson
        EXP1 = roundUp(static_cast<double>(EXP1)*0.88);
        EXP1 = limit(EXP1,0,600);
        HP1  = roundUp(static_cast<double>(HP1)*0.9);
        HP1  = limit(HP1,0,666);
        EXP2 = roundUp(static_cast<double>(EXP2)*0.88);
        EXP2 = limit(EXP2,0,600);
        HP2  = roundUp(static_cast<double>(HP2)*0.9);
        HP2  = limit(HP2,0,666);
         return taxi_score;
    } else {
        // Nếu đuổi kịp
        // Cập nhật EXP và HP cho Sherlock và Watson
        EXP1 = roundUp(static_cast<double>(EXP1)*1.12);
        EXP1 = limit(EXP1,0,600);
        HP1  = roundUp(static_cast<double>(HP1)*1.1);
        HP1  = limit(HP1,0,666);
        EXP2 = roundUp(static_cast<double>(EXP2)*1.12);
        EXP2 = limit(EXP2,0,600);
        HP2  = roundUp(static_cast<double>(HP2)*1.1);
        HP2  = limit(HP2,0,666);
        return sherlock_watson_score;
    }
    // Trả về điểm số lớn hơn tại vị trí gặp nhau
}


// Task 4
// Hàm kiểm tra ký tự có phải là chữ cái (in hoa hoặc in thường) không
bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Hàm kiểm tra ký tự có phải là chữ số không
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Hàm kiểm tra ký tự có phải là ký tự đặc biệt không
bool isSpecialChar(char c) {
    return c == '@' || c == '#' || c == '%' || c == '$' || c == '!';
}
int checkPassword(const char * s, const char * email) {
 // Tìm vị trí của ký tự '@' trong email
    size_t pos = 0;
    while (email[pos] != '@' && email[pos] != '\0') {
        pos++;
    }

    // Lấy phần trước '@' trong email
    char se[pos + 1];
    for (size_t i = 0; i < pos; ++i) {
        se[i] = email[i];
    }
    se[pos] = '\0';

    // Kiểm tra độ dài của mật khẩu
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    if (length < 8) return -1;
    if (length > 20) return -2;
    
     // Kiểm tra mật khẩu có chứa chuỗi se không
    int sei = 0;
    while (s[sei] != '\0') {
        int match = 0;
        while (se[match] != '\0' && s[sei + match] == se[match]) {
            match++;
        }
        if (se[match] == '\0') return -(300 + sei);
        sei++;
    }

        // Kiểm tra mật khẩu có chứa nhiều hơn 2 ký tự liên tiếp và giống nhau không
    for (int i = 0; i < length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }
    
    // Kiểm tra mật khẩu có chứa ký tự đặc biệt không
    bool hasSpecialChar = false;
    for (int i = 0; i < length; ++i) {
        if (isSpecialChar(s[i])) {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) return -5;


    // Kiểm tra mật khẩu có chứa ký tự không hợp lệ
    for (int i = 0; i < length; ++i) {
        if (!(isLetter(s[i]) || isDigit(s[i]) || isSpecialChar(s[i]))) {
            return i; // Trả về vị trí của ký tự đầu tiên không hợp lệ
        }
    }

    // Mật khẩu hợp lệ
    return -10;    
}

// Task 5
// Hàm so sánh hai chuỗi
int strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
 // Tạo một bản đếm cho số lần xuất hiện của mỗi mật khẩu
    pair<const char*, int> passwordCount[30];

    // Lặp qua mảng mật khẩu và tăng số lần xuất hiện của mỗi mật khẩu
    int uniqueCount = 0;
    for (int i = 0; i < num_pwds; ++i) {
        bool found = false;
        for (int j = 0; j < uniqueCount; ++j) {
            if (strcmp(passwordCount[j].first, arr_pwds[i]) == 0) {
                passwordCount[j].second++;
                found = true;
                break;
            }
        }
        if (!found) {
            passwordCount[uniqueCount++] = make_pair(arr_pwds[i], 1);
        }
    }

    // Tìm mật khẩu xuất hiện nhiều nhất và có độ dài lớn nhất
    const char* mostFrequentPassword = nullptr;
    int maxCount = 0;
    int maxLength = 0;
    for (int i = 0; i < uniqueCount; ++i) {
        const char* pwd = passwordCount[i].first;
        int count = passwordCount[i].second;
        int length = 0;
        while (pwd[length] != '\0') {
            length++;
        }

        if (count > maxCount || (count == maxCount && length > maxLength)) {
            mostFrequentPassword = pwd;
            maxCount = count;
            maxLength = length;
        }
    }

    // Tìm vị trí đầu tiên của mật khẩu đúng trong mảng arr_pwds
    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(arr_pwds[i], mostFrequentPassword) == 0) {
            return i;
        }
    }

    // Trả về -1 nếu không tìm thấy mật khẩu đúng
    return -1;   
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////