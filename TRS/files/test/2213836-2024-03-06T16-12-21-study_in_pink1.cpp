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

//* kiểm tra exp
int checkExp(int exp) {
    if(exp < 0) return exp = 0;
    else if(exp > 600) return exp = 600;
    else return exp;
}

//* kiểm tra hp
int checkHp(int hp) {
    if(hp < 0) return hp = 0;
    else if(hp > 666) return hp = 666;
    else return hp;
}

//* kiểm tra money
int checkMoney(int money) {
    if(money < 0) return money = 0;
    else if(money > 3000) return money = 3000;
    else return money;
}

//* kiểm tra số chính phương
bool isSquare(int num) {
    int squareRoot = sqrt(num);
    return squareRoot * squareRoot == num;
}

//* tìm số chính phương gần nhất
int nearestSquare(int num) {
    int smaller = num - 1;
    int larger = num + 1;

    if(isSquare(num)) return num;

    while(true) {
        if (isSquare(smaller))
            return smaller;
        else if (isSquare(larger))
            return larger;
        else {
            smaller--;
            larger++;
        }
    }
}

//* nghỉ ngơi và mua đồ
void rest(int & HP1, int & M1) {
    if (HP1 < 200) {
        HP1 = (HP1 * 1.3) + 0.999; // Cộng thêm 30% HP
        M1 -= 150;
    } else {
        HP1 = (HP1 * 1.1) + 0.999; // Cộng thêm 10% HP
        M1 -= 70;
    }
    HP1 = checkHp(HP1);
    M1 = checkMoney(M1);
}

//* thuê taxi hoặc xe ngựa
void vehicle(int & EXP1, int & M1) {
    if (EXP1 < 400) {
        M1 -= 200; // Thuê taxi
    } else {
        M1 -= 120; // Thuê xe ngựa
    }
    EXP1 = (EXP1 * 1.13) + 0.999; // Tăng 13% EXP
    EXP1 = checkExp(EXP1);
    M1 = checkMoney(M1);
}

//* giúp người vô gia cư
void homeless(int & EXP1, int & M1) {
    if (EXP1 < 300) {
        M1 -= 100;
    } else {
        M1 -= 120;
    }
    EXP1 = (EXP1 * 0.9) + 0.999; // Giảm 10% EXP
    EXP1 = checkExp(EXP1);
    M1 = checkMoney(M1);
}

//* kiểm tra kí tự đặc biệt
bool isValidChar(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '@' || c == '#' || c == '%' || c == '$' || c == '!';
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1 < 0 || e1 > 99) return -99;
    exp1 = checkExp(exp1);
    exp2 = checkExp(exp2);

    //* TH1:
    if(e1 >= 0 && e1 <= 3) {
        if(e1 == 0) exp2 += 29;
        else if(e1 == 1) exp2 += 45;
        else if(e1 == 2) exp2 += 75;
        else if(e1 == 3) exp2 += 149;

        int D = e1*3 + exp1*7;
        if(D%2 == 0) exp1 = (exp1 + static_cast<double>(D)/200) + 0.999; // số chẵn
        else exp1 = (exp1 - static_cast<double>(D)/100) + 0.999;

        exp1 = checkExp(exp1); // cập nhật lại chỉ số nếu vượt quá giới hạn
        exp2 = checkExp(exp2);
    }
    
    //* TH2
    else if(e1 >= 4 && e1 <= 99) {
        if(e1 >= 4 && e1 <= 19) exp2 = (exp2 + (static_cast<double>(e1)/4 + 19)) + 0.999;
        else if(e1 >= 20 && e1 <= 49) exp2 = (exp2 + (static_cast<double>(e1)/9 + 21)) + 0.999;
        else if(e1 >= 50 && e1 <= 65) exp2 = (exp2 + (static_cast<double>(e1)/16 + 17)) + 0.999;

        else if(e1 >= 66 && e1 <= 79) {
            exp2 = (exp2 + (static_cast<double>(e1)/4 + 19)) + 0.999;
            if(exp2 > 200) exp2 = (exp2 + (static_cast<double>(e1)/9 + 21)) + 0.999;
        }

        else if(e1 >= 80 && e1 <= 99) {
            exp2 = (exp2 + (static_cast<double>(e1)/4 + 19)) + 0.999;
            exp2 = (exp2 + (static_cast<double>(e1)/9 + 21)) + 0.999;
            if(exp2 > 400) {
                exp2 = (exp2 + (static_cast<double>(e1)/16 + 17)) + 0.999;
                exp2 = (exp2 * 1.15) + 0.999;
            }
        }
        
        exp1 -= e1;

        exp1 = checkExp(exp1); // cập nhật lại chỉ số nếu vượt quá giới hạn
        exp2 = checkExp(exp2);
    }
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 < 0 || E2 > 99) return -99;
    HP1 = checkHp(HP1);
    EXP1 = checkExp(EXP1);
    M1 = checkMoney(M1);
    
    //* TH1
    double P1;
    int S = nearestSquare(EXP1);
    if(EXP1 >= S) P1 = 100; // tính xác suất đường 1
    else P1 = ((static_cast<double>(EXP1)/S + 80)/123) * 100;

    //* TH2
    double P2;
    int initialMoney = M1/2;
    if(M1 != 0) {
        if(E2%2 != 0) {
            while(M1 >= initialMoney) {
                rest(HP1, M1);
                if(M1 < initialMoney) break;
                vehicle(EXP1, M1);
                if(M1 < initialMoney) break;
                homeless(EXP1, M1);
            }
        }
        else {
            rest(HP1, M1);
            if(M1 > 0) vehicle(EXP1, M1);
            if(M1 > 0) homeless(EXP1, M1);
        }
    }
    HP1 = (HP1 * 0.83) + 0.999;
    EXP1 = (EXP1 * 1.17) + 0.999;
    HP1 = checkHp(HP1);
    EXP1 = checkExp(EXP1);

    S = nearestSquare(EXP1);
    if(EXP1 >= S) P2 = 100; // tính xác suất đường 2
    else P2 = ((static_cast<double>(EXP1)/S + 80)/123) * 100;

    //* TH3
    double P3;
    int i;
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2 < 10) i = E2;
    else {
        int total = (E2 / 10) + (E2 % 10);
        i = total % 10;
    }
    P3 = P[i];

    //* sau khi đi xong 3 đường
    if(P1 == 100 && P2 == 100 && P3 == 100) {
        EXP1 = (EXP1 * 0.75) + 0.999;
        EXP1 = checkExp(EXP1);
    }
    else {
        double P_vali = (P1 + P2 + P3) / 3.0;
        
        if(P_vali < 50.0) {
            HP1 = (HP1 * 0.85) + 0.999;
            EXP1 = (EXP1 * 1.15) + 0.999;
            HP1 = checkHp(HP1);
            EXP1 = checkExp(EXP1);
        }

        else {
            HP1 = (HP1 * 0.9) + 0.999;
            EXP1 = (EXP1 * 1.2) + 0.999;
            HP1 = checkHp(HP1);
            EXP1 = checkExp(EXP1);
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 < 0 || E3 > 99) return -99;
    HP1 = checkHp(HP1);
    HP2 = checkHp(HP2);
    EXP1 = checkExp(EXP1);
    EXP2 = checkExp(EXP2);
    
    //* tạo matrix cho taxi
    int taxiMatrix[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxiMatrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    //* tìm điểm i
    int count_i = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (taxiMatrix[i][j] > E3*2) {
                count_i++;
            }
        }
    }
    while(count_i > 9) {
        count_i = count_i/10 + count_i%10;
    }

    //* tìm điểm j;
    int count_j = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (taxiMatrix[i][j] < -E3) {
                count_j++;
            }
        }
    }
    while(count_j > 9) {
        count_j = count_j/10 + count_j%10;
    }

    //* tìm điểm của 2 thám tử
    int a = count_i;
    int b = count_j;
    int maxLeft = taxiMatrix[a][b];
    int maxRight = taxiMatrix[a][b];
    
    // left (up or down)
    while (a > 0 && b > 0) {
        a--;
        b--;
        maxLeft = max(maxLeft, taxiMatrix[a][b]);
    }
    a = count_i;
    b = count_j;
    while (a < 9 && b < 9) {
        a++;
        b++;
        maxLeft = max(maxLeft, taxiMatrix[a][b]);
    }

    // right (up or down)
    a = count_i;
    b = count_j;
    while (a > 0 && b < 9) {
        a--;
        b++;
        maxRight = max(maxRight, taxiMatrix[a][b]);
    }
    a = count_i;
    b = count_j;
    while (a < 9 && b > 0) {
        a++;
        b--;
        maxRight = max(maxRight, taxiMatrix[a][b]);
    }
    
    int maxValue = max(maxLeft, maxRight);

    //* so sánh điểm 2 bên
    int taxiPoint = taxiMatrix[count_i][count_j];
    int dectPoint = maxValue;

    if(abs(taxiPoint) > abs(dectPoint)) {
        EXP1 = (EXP1 * 0.88) + 0.999;
        EXP2 = (EXP2 * 0.88) + 0.999;
        HP1 = (HP1 * 0.9) + 0.999;
        HP2 = (HP2 * 0.9) + 0.999;
        
        EXP1 = checkExp(EXP1);
        EXP2 = checkExp(EXP2);
        HP1 = checkHp(HP1);
        HP2 = checkHp(HP2);

        return taxiPoint;
    }
    else {
        EXP1 = (EXP1 * 1.12) + 0.999;
        EXP2 = (EXP2 * 1.12) + 0.999;
        HP1 = (HP1 * 1.1) + 0.999;
        HP2 = (HP2 * 1.1) + 0.999;
        
        EXP1 = checkExp(EXP1);
        EXP2 = checkExp(EXP2);
        HP1 = checkHp(HP1);
        HP2 = checkHp(HP2);

        return dectPoint;
    }
    
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    //* Kiểm tra độ dài của mật khẩu
    int len = strlen(s);
    if(len < 8) return -1;
    if(len > 20) return -2;
    
    //* Kiểm tra mật khẩu không chứa chuỗi se
    char se[100]; // Đảm bảo có đủ không gian cho chuỗi se
    int length = strlen(email);
    int j = 0; // Biến đếm cho chuỗi se
    for(int i = 0; i < length; i++) {
        if(email[i] != '@') {
            se[j] = email[i];
            j++;
        } 
        else break;
    }
    se[j] = '\0'; // Đảm bảo kết thúc chuỗi se bằng NULL
    const char* firstAppear = strstr(s, se);
    if(firstAppear != nullptr) {
        int sei = firstAppear - s;
        return -(300 + sei);
    }
    
    //* Kiểm tra mật khẩu không chứa nhiều hơn 2 ký tự liên tiếp
    for (int i = 0; i < len - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
            return -(400 + i);
    }
    
    //* Kiểm tra mật khẩu có chứa ký tự đặc biệt không
    bool specialChar = false;
    for(int i = 0; i < len; i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            specialChar = true;
    }
    if(specialChar == false) return -5;
    
    //* Các trường hợp còn lại
    for(int i = 0; i < len; i++) {
        if(!isValidChar(s[i])) return i;
    }
    
    return -10;

    // return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_freq = 0;
    int max_length = 0;
    const char *max_freq_pwd = nullptr;

    //* Duyệt qua từng mật khẩu trong mảng
    for(int i = 0; i < num_pwds; i++) {
        const char *current_pwd = arr_pwds[i];
        int current_freq = 0;
        int current_length = strlen(current_pwd);

        //* Đếm số lần xuất hiện của mật khẩu hiện tại
        for(int j = 0; j < num_pwds; j++) {
            if(strcmp(arr_pwds[j], current_pwd) == 0) {
                current_freq++;
            }
        }

        //* Kiểm tra nếu mật khẩu hiện tại có số lần xuất hiện nhiều nhất và độ dài dài nhất
        if(current_freq > max_freq || (current_freq == max_freq && current_length > max_length)) {
            max_freq_pwd = current_pwd;
            max_freq = current_freq;
            max_length = current_length;
        }
    }

    //* Tìm vị trí đầu tiên của mật khẩu đúng trong mảng arr_pwds
    for(int i = 0; i < num_pwds; i++) {
        if(strcmp(arr_pwds[i], max_freq_pwd) == 0) {
            return i;
        }
    }

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////