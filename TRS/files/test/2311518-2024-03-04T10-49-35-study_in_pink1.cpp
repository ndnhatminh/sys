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

// Các hàm để check và reset kết quả
void checkHP1(int& HP1) {
    if (HP1 > 666) HP1 = 666;
    else if (HP1 < 0) HP1 = 0;
    else return;
}
void checkHP2(int& HP2) {
    if (HP2 > 666) HP2 = 666;
    else if (HP2 < 0) HP2 = 0;
    else return;
}
void checkEXP1(int& EXP1) {
    if (EXP1 > 600) EXP1 = 600;
    else if (EXP1 < 0) EXP1 = 0;
    else return;
}
void checkEXP2(int& EXP2) {
    if (EXP2 > 600) EXP2 = 600;
    else if (EXP2 < 0) EXP2 = 0;
    else return;
}
void checkM1(int& M1) {
    if (M1 > 3000) M1 = 3000;
    else if (M1 < 0) M1 = 0;
    else return;
}
void checkM2(int& M2) {
    if (M2 > 3000) M2 = 3000;
    else if (M2 < 0) M2 = 0;
    else return;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 >= 0 && e1 <= 3) {   
        if (e1 == 0) exp2 += 29; 
        if (e1 == 1) exp2 += 45;
        if (e1 == 2) exp2 += 75;
        if (e1 == 3) exp2 += 29 + 45 + 75;
        checkEXP2(exp2);
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = (int)ceil(exp1 + D / 200.0);
        else exp1 = (int)ceil(exp1 - D / 100.0);
        checkEXP1(exp1);
    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) exp2 = (int)ceil(exp2 + (e1 / 4.0 + 19));
        if (e1 >= 20 && e1 <= 49) exp2 = (int)ceil(exp2 + (e1 / 9.0 + 21));
        if (e1 >= 50 && e1 <= 65) exp2 = (int)ceil(exp2 + (e1 / 16.0 + 17));
        if (e1 >= 66 && e1 <= 79) {
            exp2 = (int)ceil(exp2 + (e1 / 4.0 + 19)); checkEXP2(exp2);
            if (exp2 > 200) exp2 = (int)ceil(exp2 + (e1 / 9.0 + 21));
        }
        checkEXP2(exp2);
        if (e1 >= 80 && e1 <= 99) {
            exp2 = (int)ceil(exp2 + (e1 / 4.0 + 19)); checkEXP2(exp2);
            exp2 = (int)ceil(exp2 + (e1 / 9.0 + 21)); checkEXP2(exp2);
            if (exp2 > 400) {
                exp2 = (int)ceil(exp2 + (e1 / 16.0 + 17)); checkEXP2(exp2);
                exp2 = (int)ceil(exp2 + 0.15 * exp2);
            }
        }
        checkEXP2(exp2);
        exp1 -= e1; checkEXP1(exp1);
    }
    else return -99;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 > 99 || E2 < 0) return -99;
    // Con đường 1
    double P1, P2, P3 ;
    // Tính xác suất P1
    int sqr = (int)round(sqrt(EXP1));
    int S = sqr * sqr;
    if (EXP1 >= S) P1 = 1.00;
    else P1 = (EXP1 / (double)S + 80.00) / 123.00;
    // Con đường 2
    int M_01 = M1; // Lưu giá  trị ban đầu của M1
    int sumM1 = 0; // Tổng số tiền đã chi
    if (E2 % 2 != 0) { // E2 là số lẻ
        while (sumM1 <= 0.5 * M_01) {
            // Sự kiện 1
            if (HP1 < 200) {
                HP1 = (int)ceil(HP1 + 0.3 * HP1); 
                M1 -= 150;
                sumM1 += 150;
            }
            else {
                HP1 = (int)ceil(HP1 + 0.1 * HP1); 
                M1 -= 70;
                sumM1 += 70;
            }
            checkHP1(HP1);
            checkM1(M1);
            if (sumM1 > 0.5 * M_01) break;
            // Sự kiện 2
            if (EXP1 < 400) {
                M1 -= 200;
                sumM1 += 200;
            }
            else {
                M1 -= 120;
                sumM1 += 120;
            }
            checkM1(M1);
            EXP1 = (int)ceil(EXP1 + 0.13 * EXP1); checkEXP1(EXP1);
            if (sumM1 > 0.5 * M_01) break;
            // Sự kiện 3
            if (EXP1 < 300) {
                M1 -= 100;
                sumM1 += 100;
            }
            else {
                M1 -= 120;
                sumM1 += 120;
            }
            checkM1(M1); 
            EXP1 = (int)ceil(EXP1 - 0.1 * EXP1); checkEXP1(EXP1);
            if (sumM1 > 0.5 * M_01) break;
        }
        HP1 = (int)ceil(HP1 - 0.17 * HP1); checkHP1(HP1);
        EXP1 = (int)ceil(EXP1 + 0.17 * EXP1); checkEXP1(EXP1);
    }
    else { // E2 là số chẵn
        for (int i = 0; i < 1; i++) {
            // Sự kiện 1
            if (M1 == 0) break;
            if (HP1 < 200) {
                HP1 = (int)ceil(HP1 + 0.3 * HP1);
                M1 -= 150;
            }
            else {
                HP1 = (int)ceil(HP1 + 0.1 * HP1);
                M1 -= 70;
            }
            checkHP1(HP1);
            checkM1(M1);
            if (M1 == 0) break;
            // Sự kiện 2
            if (EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            checkM1(M1);
            EXP1 = (int)ceil(EXP1 + 0.13 * EXP1); checkEXP1(EXP1);
            if (M1 == 0) break;
            // Sự kiện 3
            if (EXP1 < 300) M1 -= 100;
            else M1 -= 120;
            checkM1(M1);
            EXP1 = (int)ceil(EXP1 - 0.1 * EXP1); checkEXP1(EXP1);
        }
        HP1 = (int)ceil(HP1 - 0.17 * HP1); checkHP1(HP1);
        EXP1 = (int)ceil(EXP1 + 0.17 * EXP1); checkEXP1(EXP1);
    }
    sqr = (int)round(sqrt(EXP1));
    S = sqr * sqr;
    if (EXP1 >= S) P2 = 1.00;
    else P2 = (EXP1 / (double)S + 80.00) / 123.00;
    // Con đường 3
    double arrP[10] = { 0.32,0.47,0.28,0.79,1.00,0.50,0.22,0.83,0.64,0.11 };
    int i;
    if (E2 >= 0 && E2 <= 9) P3 = arrP[E2];
    else if (E2 >= 10 && E2 <= 99) {
        int a = E2 / 10;
        int b = E2 % 10;
        i = (a + b) % 10;
        P3 = arrP[i];
    }
    // Sau khi đi hết cả 3 tuyến đường
    double P;
    if (P1 == 1.00 && P2 == 1.00 && P3 == 1.00) EXP1 = (int)ceil(EXP1 * 0.75);
    else {
        P = (P1 + P2 + P3) / 3.00;
        if (P < 0.50) {
            HP1 = (int)ceil(HP1 - 0.15 * HP1);
            EXP1 = (int)ceil(EXP1 + 0.15 * EXP1);
        }
        else {
            HP1 = (int)ceil(HP1 - 0.1 * HP1);
            EXP1 = (int)ceil(EXP1 + 0.2 * EXP1); 
        }
        checkHP1(HP1);
        checkEXP1(EXP1);
    }
    checkEXP1(EXP1);
    return HP1 + EXP1 + M1;
}  

// Task 3
// Hàm tìm giá trị lớn nhất ở cả đường chéo trái và đường chéo phải của 1 điểm (i,j)
int max_diagonal(int matrix[][10], int i, int j) {
    int max = matrix[i][j];
    for (int k = -9; k < 10; k++) {
        if (i + k >= 0 && i + k < 10 && j + k >= 0 && j + k < 10) {
            if (matrix[i + k][j + k] > max) max = matrix[i + k][j + k];
        }
        if (i + k >= 0 && i + k < 10 && j - k >= 0 && j - k < 10) {
            if (matrix[i + k][j - k] > max) max = matrix[i + k][j - k];
        }
    }
    return max;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 > 99 || E3 < 0) return -99;
    // Tạo lập ma trận 10x10 và khởi tạo các giá trị 0
    int matrixTaxi[10][10]{};
    // Điền điểm tại các ô mà Taxi đi qua
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrixTaxi[i][j] = (E3 * j + i * 2) *(i - j);
        }
    }
    // Tạo lập ma trận để lưu điểm của Sherlock và Watson
    int matrixSW[10][10]{};
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10; i++) {
            matrixSW[i][j] = abs(max_diagonal(matrixTaxi, i, j));
        }
    }
    // Xe taxi gặp Sherlock và Watson
    int i = 0, j = 0;
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            if (matrixTaxi[a][b] > E3 * 2) i++;
            if (matrixTaxi[a][b] < -E3) j++;
        }
    }
    while (i >= 10 && i <= 99) {
        int a = i / 10, b = i % 10;
        i = a + b;
    }
    while (j >= 10 && j <= 99) {
        int a = j / 10, b = j % 10;
        j = a + b;
    }
    //So sánh điểm của Taxi và của Shelock-Watson và tính lại điểm của họ 
    if (abs(matrixTaxi[i][j]) > matrixSW[i][j]) {
        EXP1 = (int)ceil(EXP1 - 0.12 * EXP1); checkEXP1(EXP1);
        HP1 = (int)ceil(HP1 - 0.1 * HP1); checkHP1(HP1);
        EXP2 = (int)ceil(EXP2 - 0.12 * EXP2); checkEXP2(EXP2);
        HP2 = (int)ceil(HP2 - 0.1 * HP2); checkHP2(HP2);
        return matrixTaxi[i][j];
    }
    else {
        EXP1 = (int)ceil(EXP1 + 0.12 * EXP1); checkEXP1(EXP1);
        HP1 = (int)ceil(HP1 + 0.1 * HP1); checkHP1(HP1);
        EXP2 = (int)ceil(EXP2 + 0.12 * EXP2); checkEXP2(EXP2);
        HP2 = (int)ceil(HP2 + 0.1 * HP2); checkHP2(HP2);
        return matrixSW[i][j];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string email1 = email; // Tạo biến email1 kiểu string để lưu trữ chuỗi email
    string s1 = s; // Tạo biến s1 kiểu string để lưu trữ mật khẩu s

    // Cắt chuỗi kí tự nằm trước kí tự '@' và lưu vào biến "se"
    size_t pos = email1.find('@'); // Dùng hàm find để tìm vị trí của kí tự '@'
    string se = email1.substr(0, pos); // Dùng hàm substr để cắt chuỗi từ vị trí đầu đến vị trí của kí tự '@'
    
    // Kiểm tra độ dài của mật khẩu s
    const int minLength = 8;
    const int maxLength = 20;
    if (s1.length() < minLength) return -1;
    else if (s1.length() > maxLength) return -2;

    // Kiểm tra mật khẩu s có chứa chuỗi se không
    size_t pos_se = s1.find(se);
    if (pos_se != string::npos) return - (300 + (int)pos_se);

    int count = 1; // Biến đếm số lượng từ liên tiếp nhau
    char prev = s1[0]; // Biến lưu trữ kí tự đầu tiên của mật khẩu s
    bool special_char = false; // Cờ đánh dấu kí tự đặc biệt

    // Kiểm tra nếu s có chứa nhiều hơn 2 ký tự liên tiếp và giống nhau
    for (size_t i = 1; i < s1.length(); i++) {
        char c = s1[i];
        if (c == prev) {
            count++;
            if (count > 2) return -(400 + (int)(i - 2));
        }
        else {
            count = 1;
            prev = c;
        }
    }
    // Kiểm tra mật khẩu s có kí tự đặc biệt không
    for (size_t i = 0; i < s1.length(); i++) {
        char c = s1[i];
        string special_Char = "@#%$!"; // Tạo một biến chứa các kí tự đặc biệt
        if (special_Char.find(c) != string::npos) { // Nếu là kí tự đặc biệt thì đánh dấu là true
            special_char = true;
            break;
        }        
    }
    if (!special_char) return -5;

    // Kiểm tra các trường hợp còn lại
    for (size_t i = 0; i < s1.length(); i++) {
        char c = s1[i];
        string special_Char = "@#%$!"; // Tạo một biến chứa các kí tự đặc biệt
        if (!isdigit(c) && !islower(c) && !isupper(c) && special_Char.find(c) == string::npos) return i;
    }
    return -10; // Nếu mật khẩu không vi phạm quy tắc nào
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_count = 0; // Biến lưu số lần xuất hiện nhiều nhất của một mật khẩu
    int max_length = 0; // Biến lưu độ dài lớn nhất của một mật khẩu
    int correct_index = -1; // Biến lưu vị trí của mật khẩu đúng, mặc định là -1

    // Duyệt qua các mật khẩu trong mảng
    for (int i = 0; i < num_pwds; i++) { // Với mỗi mật khẩu
        int count = 0; // Biến đếm số lần xuất hiện của mật khẩu hiện tại
        int length = strlen(arr_pwds[i]); // Biến lưu độ dài của mật khẩu hiện tại

        // Duyệt qua các mật khẩu khác trong mảng
        for (int j = 0; j < num_pwds; j++) { // Với mỗi mật khẩu khác
            if (i == j) continue; // Loại trường hợp kiểm tra mật khẩu là chính nó 
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) { // Nếu mật khẩu hiện tại trùng với mật khẩu khác
                count++; // Tăng biến đếm lên 1
            }
        }

        // Kiểm tra xem mật khẩu hiện tại có phải là mật khẩu đúng hay không
        if (count > max_count) { // Nếu số lần xuất hiện của mật khẩu hiện tại lớn hơn số lần xuất hiện nhiều nhất
            max_count = count; // Gán số lần xuất hiện nhiều nhất bằng số lần xuất hiện của mật khẩu hiện tại
            max_length = length; // Gán độ dài lớn nhất bằng độ dài của mật khẩu hiện tại
            correct_index = i; // Gán vị trí của mật khẩu đúng bằng vị trí của mật khẩu hiện tại
        }
        else if (count == max_count) { // Nếu số lần xuất hiện của mật khẩu hiện tại bằng số lần xuất hiện nhiều nhất
            if (length > max_length) { // Nếu độ dài của mật khẩu hiện tại lớn hơn độ dài lớn nhất
                max_length = length; // Gán độ dài lớn nhất bằng độ dài của mật khẩu hiện tại
                correct_index = i; // Gán vị trí của mật khẩu đúng bằng vị trí của mật khẩu hiện tại
            }
        }
    }

    // Trả về vị trí của mật khẩu đúng
    return correct_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////