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
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
     if (E1 < 0 || E1 > 3) {
        return -99; // Trả về -99 nếu E1 không hợp lệ
    }

    // Cập nhật chỉ số EXP của Watson dựa trên thông tin được Sherlock giải thích
    switch (E1) {
        case 0:
            EXP2 += 29; // Watson trở về từ Afghanistan
            break;
        case 1:
            EXP2 += 45; // Watson từ nước ngoài về
            break;
        case 2:
            EXP2 += 75; // Watson bị thương tại chiến trường
            break;
        case 3:
            EXP2 += 149; // Tổng EXP cộng thêm từ 3 thông tin trước
            break;
    }

    // Tính toán quyết định D của Sherlock
    int D = E1 * 3 + EXP1 * 7;

    // Cập nhật EXP của Sherlock dựa trên quyết định D
    if (D % 2 == 0) {
        // Nếu D là số chẵn, Sherlock nghiêng về Afghanistan
        EXP1 += D / 200;
    } else {
        // Nếu D là số lẻ, Sherlock nghiêng về Iraq
        EXP1 -= std::round(D / 100.0); // Làm tròn gần nhất trước khi cộng hoặc trừ
    }

    return EXP1 + EXP2;
}
int main() {
    int EXP1, EXP2, E1;

    // Nhập dữ liệu
    std::cin >> EXP1 >> EXP2 >> E1;

    // Thực hiện cho ví dụ cụ thể
    
    std::cout << "Tổng EXP của Sherlock và Watson sau khi gặp nhau lần đầu: " << firstMeet(EXP1, EXP2, E1) << std::endl;

    return 0;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////