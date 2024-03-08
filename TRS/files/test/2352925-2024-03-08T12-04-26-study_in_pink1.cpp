#include "study_in_pink1.h"
#include <cmath>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
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
/// CoMplete the following functions
/// DO NOT Modify any paraMeters in the functions.
////////////////////////////////////////////////////////////////////////
int check_EXP(int EXP) {
    if (EXP > 600) { EXP = 600; }
    else if (EXP < 0) { EXP = 0; }
    else { EXP = EXP; }
    return EXP;
}
int check_HP(int HP) {
    if (HP > 666) { HP = 666; }
    else if (HP < 0) { HP = 0; }
    else { HP = HP; }
    return HP;
}
int check_M(int M) {
    if (M > 3000) { M = 3000; }
    else if (M < 0) { M = 0; }
    else { M = M; }
    return M;
}
int check_e(int E) {
    if (E < 0 || E > 99) {
        return -99;
    }
    return E;
}


// Task 1


int firstMeet(int & EXP1, int & EXP2, int E1) {
    EXP1 = check_EXP(EXP1);
    EXP2 = check_EXP(EXP2);
    E1 = check_e(E1);
    if (E1 >= 0 && E1 <= 3) {
        int D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0) {
            EXP1 = ceil(EXP1 + D / 200.0);

        }
        else {
            EXP1 = ceil(EXP1 - D / 100.0);
        }

        switch (E1)
        {
        case 0:
            EXP2 += 29;
            break;
        case 1:
            EXP2 += 45;
            break;
        case 2:
            EXP2 += 75;
            break;
        case 3:
            EXP2 += 29 + 45 + 75;
            break;
        default:
            break;
        }
        return EXP1 + EXP2;
    }

      switch (E1)
      {
    case 4 ... 19:
        EXP2 = EXP2 + ceil((E1 / 4.0) + 19);
        EXP2 = check_EXP(EXP2);
        EXP1 -= E1;
        EXP1 = check_EXP(EXP1);
        break;

   
    case 20 ... 49:
        EXP2 = EXP2 + ceil((E1 / 9.0) + 21);
        EXP2 = check_EXP(EXP2);
        EXP1 -= E1;
        EXP1 = check_EXP(EXP1);
        break;
 
    case 50 ... 65:
        EXP2 = EXP2 + ceil((E1 / 16.0) + 17);
        EXP2 = check_EXP(EXP2);
        EXP1 -= E1;
        EXP1 = check_EXP(EXP1);
        break;
    
    case 66 ... 79:
        EXP2 = EXP2 + ceil((E1 / 4.0) + 19);
        EXP2 = check_EXP(EXP2);
        EXP1 -= E1;
        EXP1 = check_EXP(EXP1);
            if (EXP2 > 200) {
                EXP2 = EXP2 + ceil((E1 / 9.0) + 21);
                EXP2 = check_EXP(EXP2);
                EXP1 -= E1;
            }
            break;

   
    case 80 ... 99:
        EXP2 = EXP2 + ceil((E1 / 4.0) + 19) ;
        EXP2 = check_EXP(EXP2);
        EXP2 = EXP2 + ceil((E1 / 9.0) + 21);
        EXP2 = check_EXP(EXP2);
        EXP1 -= E1;
        EXP1 = check_EXP(EXP1);
        if (EXP2  > 400) {
            EXP2 = EXP2 + ceil((E1 / 16.0) + 17);
            EXP2 = check_EXP(EXP2);
            EXP2 += 0.15 * EXP2;
            EXP2 = check_EXP(EXP2);
        }
     break;
    default:
      break;
  }
   
    return EXP1 + EXP2;
}

// Task 2
int clamp(int value, int minVal, int maxVal) {
    return max(minVal, min(maxVal, value));
}


void limitValues(int& HP, int& EXP, int& M) {
    HP = max(0, min(HP, 666));
    EXP = max(0, min(EXP, 600));
    M = max(0, min(M, 3000));
}


int SochinhPhuong(int num) {
    int  sqrtN = static_cast<int>(sqrt(num));
    int lowerN = static_cast<int>(sqrtN * sqrtN);
    int upperN = static_cast<int>(sqrtN + 1) * (sqrtN + 1);
    return num - lowerN <= upperN - num ? lowerN : upperN;
}

// Main function to describe Sherlock's luggage searching process
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // Check if E2 is within the valid range
    if (E2 < 0 || E2 > 99) return -99;

    // Limit HP, EXP, and M values
    limitValues(HP1, EXP1, M1);

    // Calculate the probability P1
    int S = SochinhPhuong(EXP1);
    double P1 = EXP1 >= S ? 1.0 : (static_cast<double>(EXP1) / S + 80) / 123.0;

    // Calculate the probability P2 for Road 02
    double P2 = 0;
    bool isE2Odd = E2 % 2 != 0;
    int initialM = M1;
    while (M1 > 0) {
        // Events in Road 02
        M1 = clamp(HP1 < 200 ? M1 - 150 : M1 - 70, 0, 3000);
        HP1 = clamp(ceil(HP1 < 200 ? HP1 * 130 / 100.0 : HP1 * 110 / 100.0), 0, 666);
        if ((isE2Odd && (M1 < ceil(initialM / 2.0) || !M1)) || (!isE2Odd && !M1)) break;

        M1 = clamp(EXP1 < 400 ? M1 - 200 : M1 - 120, 0, 3000);
        EXP1 = clamp(ceil(EXP1 * 113 / 100.0), 0, 600);
        if ((isE2Odd && (M1 < ceil(initialM / 2.0) || !M1)) || (!isE2Odd && !M1)) break;

        M1 = clamp(EXP1 < 300 ? M1 - 100 : M1 - 120, 0, 3000);
        EXP1 = clamp(ceil(EXP1 * 90 / 100.0), 0, 600);
        if ((isE2Odd && (M1 < ceil(initialM / 2.0) || !M1)) || (!isE2Odd && !M1)) break;
    }

    HP1 = clamp(ceil(HP1 * 83 / 100.0), 0, 666);
    EXP1 = clamp(ceil(EXP1 * 117 / 100.0), 0, 600);

    // Calculate the probability P2 for Road 02
    int S2 = SochinhPhuong(EXP1);
    P2 = EXP1 >= S2 ? 1.0 : (static_cast<double>(EXP1) / S2 + 80) / 123.0;
    P2 = max(0.0, min(P2, 1.0));

    // Calculate the probability P3 for Road 03
    const int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i = (E2 > 9) ? (E2 / 10 + E2 % 10) % 10 : E2;
    double P3 = P[i] / 100.0;

    // Calculate the average probability
    double averageP = (P1 + P2 + P3) / 3;
    if (averageP == 1.0) {
        EXP1 = ceil(EXP1 * 0.75);
    }
    else {
        HP1 = ceil(averageP < 0.5 ? HP1 * 85 / 100.0 : HP1 * 90 / 100.0);
        EXP1 = ceil(averageP < 0.5 ? EXP1 * 115 / 100.0 : EXP1 * 120 / 100.0);
    }

    // Limit HP, EXP, and M values again
    limitValues(HP1, EXP1, M1);

    // Return the sum of HP, EXP, and M
    return HP1 + EXP1 + M1;
}

// Task 3

    int maxValue(int matrix[10][10], int row, int column) {
        int maxVal = 0;
        for (int i = row, j = column; i >= 0 && j >= 0 && i < 10 && j < 10; i--, j--) {
            maxVal = max(maxVal, matrix[i][j]);
        }
        for (int i = row, j = column; i >= 0 && j >= 0 && i < 10 && j < 10; i--, j++) {
            maxVal = max(maxVal, matrix[i][j]);
        }
        for (int i = row, j = column; i >= 0 && j >= 0 && i < 10 && j < 10; i++, j--) {
            maxVal = max(maxVal, matrix[i][j]);
        }
        for (int i = row, j = column; i >= 0 && j >= 0 && i < 10 && j < 10; i++, j++) {
            maxVal = max(maxVal, matrix[i][j]);
        }
        return maxVal;
    }

    void limit(int& HP, int& EXP) {
        HP = max(0, min(HP, 666));
        EXP = max(0, min(EXP, 600));
    }

    int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
        if (E3 < 0 || E3 > 99) return -99;

        limit(HP1, EXP1);
        limit(HP2, EXP2);
        E3 = max(0, min(E3, 99));

        int matrix[10][10];
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }

        int x = 0, y = 0;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (matrix[i][j] > E3 * 2) x++;
                if (matrix[i][j] < -E3) y++;
            }
        }

        while (x > 9) {
            x = x % 10 + x / 10;
        }
        while (y > 9) {
            y = y % 10 + y / 10;
        }

        int taxiScore = matrix[x][y];
        int sherlockScore = maxValue(matrix, x, y);

        bool isTaxiHigher = abs(taxiScore) > sherlockScore;
        double factor = isTaxiHigher ? 0.88 : 1.12;

        double newEXP1 = EXP1 * factor;
        double newEXP2 = EXP2 * factor;

        double newHP1 = HP1 * (isTaxiHigher ? 0.9 : 1.1);
        double newHP2 = HP2 * (isTaxiHigher ? 0.9 : 1.1);

        EXP1 = max(0, min(int(ceil(newEXP1)), 600));
        EXP2 = max(0, min(int(ceil(newEXP2)), 600));

        HP1 = max(0, min(int(ceil(newHP1)), 666));
        HP2 = max(0, min(int(ceil(newHP2)), 666));

        return abs(taxiScore) > abs(sherlockScore) ? taxiScore : sherlockScore;
    }


// Task 4
int checkPassword(const char* s, const char* email) {
    string se = email;
    size_t atIndex = se.find('@');
    if (atIndex == string::npos || atIndex >= 100) {
        return -99; // Mã lỗi khi email không hợp lệ
    }

    se = se.substr(0, atIndex); // Lấy phần trước ký tự '@'

    // Kiểm tra độ dài
    if (strlen(s) < 8) {
        return -1;
    }
    if (strlen(s) > 20) {
        return -2;
    }

    // Kiểm tra kí tự trong chuỗi se
    int checkse = strstr(s, se.c_str()) - s;
    if (checkse != -1) {
        return -(300 + checkse);
    }

    // Kiểm tra 2 ký tự liên tiếp
    for (int i = 0; i < strlen(s) - 2; ++i) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            return -(400 + i);
        }
    }

    // Kiểm tra ký tự đặc biệt
    bool hasSpecialChar = false;
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            hasSpecialChar = true;
            break;
        }
    }

    if (!hasSpecialChar) {
        return -5; // Mật khẩu không chứa ký tự đặc biệt
    }

    return -10; // Mật khẩu hợp lệ
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    std::unordered_map<std::string, int> dem_mat_khau;

    // Đếm số lần xuất hiện của mỗi mật khẩu khác nhau
    for (int i = 0; i < num_pwds; ++i) {
        std::string mat_khau = arr_pwds[i];
        dem_mat_khau[mat_khau]++;
    }

    // Tìm mật khẩu xuất hiện nhiều nhất
    int so_lan_xuat_hien_nhieu_nhat = 0;
    std::string mat_khau_xuat_hien_nhieu_nhat;
    for (const auto& cap : dem_mat_khau) {
        if (cap.second > so_lan_xuat_hien_nhieu_nhat) {
            so_lan_xuat_hien_nhieu_nhat = cap.second;
            mat_khau_xuat_hien_nhieu_nhat = cap.first;
        }
    }

    // Tìm chỉ số của mật khẩu xuất hiện nhiều nhất
    for (int i = 0; i < num_pwds; ++i) {
        if (std::string(arr_pwds[i]) == mat_khau_xuat_hien_nhieu_nhat) {
            return i;
        }
    }

    return -1; // Giá trị trả về mặc định nếu không tìm thấy mật khẩu
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////