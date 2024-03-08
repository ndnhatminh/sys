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

void testHP(int& HP1){
    if(HP1 > 666){
        HP1 = 666;
    }else if(HP1 < 0){
        HP1 = 0;
    }
}

void testEXP(int& EXP1){
    if(EXP1 > 600){
        EXP1 = 600;
    }else if(EXP1 < 0){
        EXP1 = 0;
    }   
}
// Task 1
void test(int & exp1, int & exp2){
    if(exp2 > 600){
        exp2 = 600;
    }
    else if(exp2 < 0){
        exp2 = 0;
    }
    if(exp1 > 600){
        exp1 = 600;
    }
    else if(exp1 < 0){
        exp1 = 0;
    }
}
int firstMeet(int& exp1, int& exp2, int e1) {
    if (e1 < 0 || e1 > 99) {
        return -99;
    }
    testEXP(exp1);
    testEXP(exp2);
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) {
            exp2 += 29;
        } else if (e1 == 1) {
            exp2 += 45;
        } else if (e1 == 2) {
            exp2 += 75;
        } else if (e1 == 3) {
            exp2 += 149;
        }
    testEXP(exp1);
    testEXP(exp2);
        if ((e1 * 3 + exp1 * 7) % 2 == 0) {
            exp1 = exp1 + (e1 * 3 + exp1 * 7) / 200.0 + 0.999;
        } else {
            exp1 = exp1 - (e1 * 3 + exp1 * 7) / 100.0 + 0.999;
        }

        test(exp1, exp2);
    } else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 += e1 / 4.0 + 19 + 0.999;
            test(exp1, exp2);
        } else if (e1 >= 20 && e1 <= 49) {
            exp2 = exp2 + e1 / 9.0 + 21 + 0.999;
            test(exp1, exp2);
        } else if (e1 >= 50 && e1 <= 65) {
            exp2 += e1 / 16.0 + 17 + 0.999;
            test(exp1, exp2);
        } else if (e1 >= 66 && e1 <= 79) {
            exp2 += e1 / 4.0 + 19 + 0.999;
            test(exp1, exp2);
            if (exp2 > 200) {
                exp2 += e1 / 9.0 + 21 + 0.999;
                test(exp1, exp2);
            }
        } else if (e1 >= 80 && e1 <= 99) {
            exp2 += e1 / 4.0 + 19 + 0.999;
            test(exp1, exp2);
            exp2 += e1 / 9.0 + 21 + 0.999;
            test(exp1, exp2);
            if (exp2 > 400) {
                exp2 += e1 / 16.0 + 17 + 0.999;
                test(exp1, exp2);
                exp2 = exp2 * 1.15 + 0.999;
                test(exp1, exp2);
            }
        }
        exp1 -= e1;
        test(exp1, exp2);
    }
    test(exp1, exp2);
    return exp1 + exp2;
}

// Task 2

bool testCP(int number){
    int sqrtNumber = std::sqrt(number);
    return (sqrtNumber * sqrtNumber == number);
}

int isPerfectSquare(int number) {
    if (number < 0) {
        return false; // Số âm không phải là số chính phương
    }
    int ChinhPhuong[] ={0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289, 324, 361, 400, 441, 484, 529, 576, 625, 676, 729, 784, 841, 900, 961};
    for(int i = 0; i < 32; i++){
        if(number == ChinhPhuong[i]){
            return number;
        }
    }
    
    int bigger = number + 1;
    int smaller = number - 1;
    while(true){
        if(smaller > 0){
            if(testCP(smaller)){
                return smaller;
            }
        }
        if(testCP(bigger)){
            return bigger;
        }
        smaller--;
        bigger++;
    }
}

// Hàm tính chỉ số sức khỏe và kinh nghiệm Sherlock sau khi đi qua con đường 01
double calculateStatsRoad1(int& HP1, int& EXP1, int& M1) {
    int S = isPerfectSquare(EXP1); // Số chính phương gần với EXP1 nhất
    double P;
    if (EXP1 >= S)
        P = 1.0; // Xác suất 100% tìm thấy vali
    else
        P = (EXP1 / (double)S + 80) / 123; // Tính xác suất theo công thức

    // Cập nhật chỉ số sức khỏe và kinh nghiệm
    return P;
}

// Hàm tính chỉ số sức khỏe và kinh nghiệm Sherlock sau khi đi qua con đường 02
double calculateStatsRoad2(int& HP1, int& EXP1, int& M1, int E2) {
    double P;
    int M0 = M1;
    if(E2 % 2 == 1){
        while (M1 > 0) {
            if (HP1 < 200) {
                HP1 = HP1 + HP1 * 0.3 + 0.999; // Tăng sức khỏe 30%
                M1 -= 150; // Chi phí mua đồ
            } else {
                HP1 = HP1 + HP1 * 0.1 + 0.999; // Tăng sức khỏe 10%
                M1 -= 70; // Chi phí mua nước uống
            }
            testHP(HP1);
            testEXP(EXP1);
            if (M1 < M0 * 0.5) {
                break;
            }
            if (EXP1 < 400) {
                M1 -= 200; // Chi phí thuê taxi
                EXP1 += EXP1 * 0.13 + 0.999; // Tăng kinh nghiệm 13%
            } else {
                M1 -= 120; // Chi phí thuê xe ngựa
                EXP1 += EXP1 * 0.13 + 0.999; // Tăng kinh nghiệm 13%
            }
            testHP(HP1);
            testEXP(EXP1);
            if (M1 < M0 * 0.5) {
                break;
            }
            int m = (EXP1 < 300) ? 100 : 120;
            EXP1 = EXP1 - EXP1 * 0.1 + 0.999; 
            M1 -= m;
            testHP(HP1);
            testEXP(EXP1);
            if (M1 < M0 * 0.5) {
                break;
            }
        }
    }else{
        if(M1 > 0){
            if (HP1 < 200 && M1 > 0) {
                HP1 += HP1 * 0.3 + 0.999; // Tăng sức khỏe 30%
                M1 -= 150; // Chi phí mua đồ
            } else if (HP1 >= 200 && M1 > 0){
                HP1 += HP1 * 0.1 + 0.999; // Tăng sức khỏe 10%
                M1 -= 70; // Chi phí mua nước uống
            }
            testHP(HP1);
            testEXP(EXP1);
            if (EXP1 < 400 && M1 > 0) {
                M1 -= 200; // Chi phí thuê taxi
                EXP1 += EXP1 * 0.13 + 0.999; // Tăng kinh nghiệm 13%
            } else if (EXP1 >= 400 && M1 > 0){
                M1 -= 120; // Chi phí thuê xe ngựa
                EXP1 += EXP1 * 0.13 + 0.999; // Tăng kinh nghiệm 13%
            }
            testHP(HP1);
            testEXP(EXP1);
            if(M1 > 0){
                int m = (EXP1 < 300) ? 100 : 120;
                if(M1 > 0){
                    EXP1 = EXP1 - EXP1 * 0.1 + 0.999; // Giảm kinh nghiệm 10%
                    M1 -= m;
                }
            }
            testHP(HP1);
            testEXP(EXP1); 
        }
    }
    testHP(HP1);
    testEXP(EXP1);
    HP1 = HP1 - HP1 * 0.17 + 0.999; // Giảm sức khỏe 17%
    EXP1 += EXP1 * 0.17 + 0.999; // Tăng kinh nghiệm 17%
    testHP(HP1);
    testEXP(EXP1);
    if(M1 < 0) M1 = 0;
    return calculateStatsRoad1(HP1, EXP1, M1);
}
// Hàm tính chỉ số sức khỏe và kinh nghiệm Sherlock sau khi đi qua con đường 03
double calculateStatsRoad3(int& HP1, int& EXP1, int& M1, int E2) {
    double P;
    int E2_sum = E2 % 10 + E2 / 10 % 10; // Tính tổng của 2 chữ số của E2 và lấy số hàng đơn vị
    int i = 0;
    if(E2 < 10){
        i = E2;
    }else{
        if(E2_sum < 10){
            i = E2_sum;
        }else{
            i = E2_sum - 10;
    }
    }
    double P_array[] = {0.32, 0.47, 0.28, 0.79, 1.0, 0.5, 0.22, 0.83, 0.64, 0.11}; // Mảng xác suất
    P = P_array[i]; // Xác suất tìm thấy vali

    // Cập nhật chỉ số sức khỏe và kinh nghiệm
    return P;
}
// Hàm tính tổng chỉ số sức khỏe, kinh nghiệm và tiền của Sherlock
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(E2 < 0 || E2 > 99){
        return -99;
    }
    // Tính chỉ số sau khi đi qua từng con đường
    testHP(HP1);
    testEXP(EXP1);
    if(M1 < 0) M1 = 0;
    if(M1 > 3000) M1 = 3000;
    double P1 = calculateStatsRoad1(HP1, EXP1, M1);
    double P2 = calculateStatsRoad2(HP1, EXP1, M1, E2);
    double P3 =  calculateStatsRoad3(HP1, EXP1, M1, E2);
    double P = (P1 + P2 + P3) / 3;
    if(P == 1){
        EXP1 = EXP1 - EXP1*0.25 + 0.999;
    }
    else{
        // Cập nhật chỉ số sức khỏe và kinh nghiệm cuối cùng
        if (P >= 0.5) {
            HP1 = HP1 - HP1 * 0.1 + 0.999; // Giảm sức khỏe 10%
            EXP1 += EXP1 * 0.2 + 0.999; // Tăng kinh nghiệm 20%
        } else {
            HP1 = HP1 - HP1 * 0.15 + 0.999; // Giảm sức khỏe 15%
            EXP1 += EXP1 * 0.15 + 0.999; // Tăng kinh nghiệm 15%
        }
    }
    testHP(HP1);
    testEXP(EXP1);
    return HP1 + EXP1 + M1;
}

// Tính điểm số trên đường chéo trái (từ trên xuống dưới)
int DuongCheo1(int i, int j, int** matrix,int Max){
    while (i >= 0 && i <= 9 && j >= 0 && j <= 9) {
        if(Max < matrix[i][j]){
            Max = matrix[i][j];
        }
        i++;
        j--;
    }
    return Max;
}

int DuongCheo2(int i, int j, int** matrix,int Max){
    while (i >= 0 && i <= 9 && j >= 0 && j <= 9) {
        if(Max < matrix[i][j]){
            Max = matrix[i][j];
        }
        i++;
        j++;
    }
    return Max;
}

int DuongCheo3(int i, int j, int** matrix,int Max){
    while (i >= 0 && i <= 9 && j >= 0 && j <= 9) {
        if(Max < matrix[i][j]){
            Max = matrix[i][j];
        }
        i--;
        j++;
    }
    return Max;
}

int DuongCheo4(int i, int j, int** matrix,int Max){
    while (i >= 0 && i <= 9 && j >= 0 && j <= 9) {
        if(Max < matrix[i][j]){
            Max = matrix[i][j];
        }
        i--;
        j--;
    }
    return Max;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 < 0 || E3 > 99){
        return -99;
    }
    testHP(HP1);
    testEXP(EXP1);
    testHP(HP2);
    testEXP(EXP2);
    int ** Mang = new int*[10];
    for(int i = 0 ;i<10;i++){
        Mang[i] = new int [10];
    }
    int bigger = 0;
    int smaller = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0 ; j < 10 ; j++){
            Mang[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if(Mang[i][j] > 0 && Mang[i][j] > E3*2){
                bigger++;
            }
            if(Mang[i][j] < 0 && Mang[i][j] < -E3){
                smaller++;
            }
        }
    }
    int i,j;
    i = bigger;
    while(i >= 10){
        int tensDigit = i / 10; // Lấy chữ số hàng chục
        int unitsDigit = i % 10; // Lấy chữ số hàng đơn vị

        int sum = tensDigit + unitsDigit; // Tính tổng của hai chữ số
        i = sum;
    }
    j = smaller;
    while(j >= 10){
        int tensDigit = j / 10; // Lấy chữ số hàng chục
        int unitsDigit = j % 10; // Lấy chữ số hàng đơn vị

        int sum = tensDigit + unitsDigit; // Tính tổng của hai chữ số
        j = sum;
    }
    int max = 0;
    int taxi = Mang[i][j];
    max = DuongCheo1(i,j,Mang,max);
    max = DuongCheo2(i,j,Mang,max);
    max = DuongCheo3(i,j,Mang,max);
    max = DuongCheo4(i,j,Mang,max);
    if(abs(taxi) <= max){
        EXP1 = EXP1 + EXP1 * 0.12 + 0.999;
        EXP2 = EXP2 + EXP2 * 0.12 + 0.999;
        HP1 = HP1 + HP1 * 0.1 + 0.999;
        HP2 = HP2 + HP2 * 0.1 + 0.999;
    }else{
        EXP1 = EXP1 - EXP1 * 0.12 + 0.999;
        EXP2 = EXP2 - EXP2 * 0.12 + 0.999;
        HP1 = HP1 - HP1 * 0.1 + 0.999;
        HP2 = HP2 - HP2 * 0.1 + 0.999;
    }
    testHP(HP1);
    testEXP(EXP1);
    testHP(HP2);
    testEXP(EXP2);
    int answer = max;
    for (int i = 0; i < 10; i++) {
        delete[] Mang[i];  // Xóa mảng con trỏ ở mỗi phần tử
    }
    delete[] Mang;  // Xóa mảng con trỏ chính

    Mang = nullptr;  // Gán giá trị nullptr để tránh truy cập vào địa chỉ đã giải phóng
    if(answer < abs(taxi)) answer = taxi;
    return answer;
}


// Task 4
int checkPassword(const char* s, const char* email) {
    size_t email_length = strlen(email);
    size_t at_index = 0;
    for (size_t i = 0; i < email_length; i++) {
        if (email[i] == '@') {
            at_index = i;
            break;
        }
    }

    char se[101];
    strncpy(se, email, at_index);
    se[at_index] = '\0';

    size_t s_length = strlen(s);
    if (s_length < 8) {
        return -1;
    }

    if (s_length > 20) {
        return -2;
    }

    if (strstr(s, se) != nullptr) {
        return -(300 + (strstr(s, se) - s));
    }

    for (size_t i = 0; i < s_length - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }

    bool has_special_char = false;
    for (size_t i = 0; i < s_length; i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            has_special_char = true;
            break;
        }
    }

    if (!has_special_char) {
        return -5;
    }

    for (size_t i = 0; i < s_length; i++) {
        char c = s[i];
        if (!isalnum(c) && c != '@' && c != '#' && c != '%' && c != '$' && c != '!') {
            return i;
        }
    }

    return -10;
}
// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // Tạo một bảng băm để đếm số lần xuất hiện của mỗi mật khẩu
    int count[100] = { 0 }; // Mảng count có kích thước tối đa 30, như yêu cầu testcase

    // Tìm số lần xuất hiện của mỗi mật khẩu và độ dài lớn nhất
    int maxCount = 0;
    int maxLength = 0;
    int maxIndex = -1;

    for (int i = 0; i < num_pwds; i++) {
        const char* password = arr_pwds[i];
        int length = strlen(password);

        // Kiểm tra xem mật khẩu đã được đếm trước đó chưa
        if (count[i] == 0) {
            // Đếm số lần xuất hiện của mật khẩu và cập nhật độ dài lớn nhất
            int passwordCount = 1;

            for (int j = i + 1; j < num_pwds; j++) {
                if (strcmp(password, arr_pwds[j]) == 0) {
                    passwordCount++;
                    count[j] = 1; // Đánh dấu đã đếm mật khẩu này
                }
            }

            // Cập nhật mật khẩu đúng đầu tiên
            if (passwordCount > maxCount || (passwordCount == maxCount && length > maxLength)) {
                maxCount = passwordCount;
                maxLength = length;
                maxIndex = i;
            }
        }
    }

    return maxIndex;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////