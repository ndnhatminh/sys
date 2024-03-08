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
            exp1 += (e1 * 3 + exp1 * 7) / 200;
        }
        else {
            exp1 -= (e1 * 3 + exp1 * 7) / 200;
        }
    }
    //4.1.2
    else if (e1 >= 4 && e1 <= 19) {
        exp2 = ceil(exp2 + (e1 / 4 + 19));
    }
    else if (e1 >= 20 && e1 <= 49) {
        exp2 = ceil(exp2+(e1 / 9 + 21));
    }
    else if (e1 >= 50 && e1 <= 65) {
        exp2 = ceil(exp2 + (e1 / 16 + 17));
    }
    else if (e1 >= 66 && e1 <= 79) {
        exp2 = ceil(exp2 + (e1 / 4 + 19));
        if (exp2 > 200) {
            exp2 =ceil(exp2 + (e1 / 9 + 21));
        }
    }
    else if (e1 >= 80 && e1 <= 99) {
        exp2 =ceil(exp2 + (e1 / 4 + 19));
        exp2 =ceil(exp2 + (e1 / 9 + 21));
        if (exp2 > 400) {
            exp2 = ceil(exp2+(e1 / 16 + 17));
        }
        exp2 = exp2 + exp2 * 0.15;
    }
    exp1 -= e1;

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

        M1 = std::max(0, std::min(3000, M1)); // Đảm bảo lượng máu nằm trong giới hạn

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

    return HP1 + exp1 + M1; // Trả về tổng lượng máu, kinh nghiệm và tiền của người chơi
}




// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int MT[10][10];
    for (int i=0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            MT[i][j] = 0;
        }

    }

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
    int u;
    for (int i = 0; i < num_pwds; i++) {
        for (int n = 0; n < num_pwds; n++) {
            if (arr_pwds[i] == arr_pwds[n]) {
                u += 1;
            }
            if (n = num_pwds - 1) {
                cout<<"M?t kh?u"<<arr_pwds[i]<<"xu?t hi?n"<<u<<"l?n."<<"\n";
            }



        }

        
    }



    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////