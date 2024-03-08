#include "study_in_pink1.h"
using namespace std;
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


int roundUp(double x);
int roundUp(double x) {
    int intPart = static_cast<int>(x);
    if (x > intPart) return intPart + 1;
    else return intPart;
}

int nearpfsq(int EXP1) {
    double S = sqrt(EXP1);
    int S1 = round(S); int S2 = roundUp(S);
    if ((abs(S - S1)) < (abs(S - S2))) return S1 * S1; else return S2 * S2;

}
void adjustValue(int& value, int lowerLimit, int upperLimit) {
    if (value < lowerLimit) {
        value = lowerLimit;
    }
    else if (value > upperLimit) {
        value = upperLimit;
    }
}

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    
    // Thực hiện các tính toán tương ứng với thông tin từng khoảng của E1
    if (E1 >= 0 && E1 <= 3) {
        if (E1 == 3) {
            EXP2 += (29 + 45 + 75); // Tổng của các trường hợp trên
        }
        else {
            switch (E1) {
            case 0:
                EXP2 += 29;
                break;
            case 1:
                EXP2 += 45;
                break;
            case 2:
                EXP2 += 75;
                break;
            default:
                break;
            }
        }

        // Tính toán quyết định D dựa trên E1 và EXP1 của Sherlock
        int D = E1 * 3 + EXP1 * 7;

        // Kiểm tra D là số chẵn hay lẻ và cập nhật EXP1 của Sherlock tương ứng
        if (D % 2 == 0) {
            // Nếu D là số chẵn, Sherlock nghiêng về Afghanistan
            EXP1 = roundUp((EXP1 + 0.00) + (D + 0.00) / 200);
        }
        else {
            // Nếu D là số lẻ, Sherlock nghiêng về Iraq
            EXP1 = roundUp((EXP1 + 0.00) - (D + 0.00) / 100);
        }
    }
    else if (E1 >= 4 && E1 <= 99) {
        if (E1 >= 4 && E1 <= 19) {
            EXP2 = roundUp((EXP2 + 0.00) + (E1+0.00)/4 + 19);
        }
        else if (E1 >= 20 && E1 <= 49) {
            EXP2 = roundUp((EXP2 + 0.00) + (E1 + 0.00)/9 + 21);
        }
        else if (E1 >= 50 && E1 <= 56) {
            EXP2 = roundUp((EXP2 + 0.00) + (E1+0.00)/16 + 17);
        }
        else if (E1 >= 66 && E1 <= 79) {
            EXP2 = roundUp((EXP2 + 0.00) + (E1 + 0.00) / 4 + 19); // Thông tin 1
            if (EXP2 > 200) {
                EXP2 = roundUp((EXP2 + 0.00) + (E1 + 0.00) / 9 + 21); // Thông tin 2
            }
        }
        else if (E1 >= 80 && E1 <= 99) {
            EXP2 = roundUp((EXP2 + 0.00) + (E1 + 0.00)/4 + 19); // Thông tin 1
            EXP2 = roundUp( (EXP2 + 0.00) + (E1 + 0.00)/9 + 21); // Thông tin 2
                if (EXP2 > 400) {
                    EXP2 = roundUp((EXP2 + 0.00) + (E1 + 0.00)/16 + 17); // Thông tin 3
                }
            
        }

        // Nếu Watson được giải thích cả 3 thông tin 1, 2, 3, EXP2 sẽ được cộng thêm 15%
        if (E1 >= 80 && E1 <= 99 && EXP2 > 400) {
            EXP2 = roundUp((EXP2 + 0.00) * 1.15); // Cộng thêm 15%

        }

        // Giảm EXP1 của Sherlock nếu Watson không có anh trai
        
        EXP1 -= E1;
        
         if(E1 < 0 || E1 > 99)
         return -99;// trả về giá trị -99 nếu E1 ko nằm trong khaongr [0; 99]

    }
    adjustValue(EXP1, 0, 600);
    adjustValue(EXP2, 0, 600);
// Trả về tổng EXP của Sherlock và Watson
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    adjustValue(HP1, 0, 666);
    adjustValue(EXP1, 0, 600);
    adjustValue(M1, 0, 3000);
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;
    bool oddE2 = false;
    if ((E2 % 2) == 1) oddE2 = true;

    //Con đường 1
    float P1;
    int S;
    
    S = nearpfsq(EXP1);
    if (EXP1 >= S)
        P1 = 1;
    else
        P1 = (static_cast<float> (EXP1) / S + 80) / 123;
    int Pay = 0;
   

    for ( ; ; ) {
        if (oddE2) if (Pay > 0.5 * M1) {
            break;
        }

        //Con đường 2
        
        if (HP1 < 200)// lại cửa hàng mua đồ 
        {
            HP1 = roundUp(static_cast<float>(HP1) * 1.3);
            Pay += 150;
            if (!(oddE2)) if (Pay > M1) break;
        }
        else {
            HP1 = roundUp(static_cast<float>(HP1) * 1.1);
            Pay += 70;
            if (!(oddE2)) if (Pay > M1) break;
        }
        if (oddE2) if (Pay > 0.5 * M1) {
            break;
        }

        //thuê taxi hoặc xe ngựa
        if (EXP1 < 400) {
            Pay += 200;//taxi
            if (!(oddE2)) if (Pay > M1) break;
        }
        else {
            Pay += 120;//xe ngựa
            if (!(oddE2)) if (Pay > M1) break;
        }
        if (oddE2) if (Pay > 0.5 * M1) {
            break;
        }
        EXP1 = roundUp(static_cast<float>(EXP1) * 1.13);
        //gặp thằng l vô gia cư
        if (EXP1 < 300) {
            Pay += 100;
            if (!(oddE2)) if (Pay > M1) break;
        }
        else {
            Pay += 120;
            if (!(oddE2)) if (Pay > M1) break;
        }
        EXP1 = roundUp(static_cast<float>(EXP1) * 0.9);
        if (oddE2) if (Pay > 0.5 * M1) {
            break;
        }
    }

    //cập nhật
    M1 -= Pay;
    

    HP1 = roundUp(static_cast<float>(HP1) * 0.83);
    EXP1 = roundUp(static_cast<float>(EXP1) * 1.17);
    adjustValue(HP1, 0, 666);
    adjustValue(EXP1, 0, 600);
    adjustValue(M1, 0, 3000);
    float P2 = 0.0;
    S = nearpfsq(EXP1);

    if (EXP1 >= S)
        P2 = 1;
    else
        P2 = (static_cast<float>(EXP1) / S + 80) / 123;
    //Con đường 3
    int P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i = 0;
    float p = 0;

    if (E2 < 10)
        i = E2;
    else {
        int sum = (E2 / 10) + (E2 % 10);
        i = sum % 10;
    }
    //Cả 3 tuyến đường xác suất là 100%
    if (P1 == 1 && P2 == 1 && P[i] == 100) {//P[i] là của con đường 3
        EXP1 = roundUp(static_cast<float>(EXP1) * 0.75);
    }
    //Ko phải là 100%
    else {
        p = (P1 + P2 + P[i]) / 3;

    }
    if (p < 0.5) {
        HP1 = roundUp(static_cast<float>(HP1) * 0.85);
        EXP1 = roundUp(static_cast<float>(EXP1) * 1.15);
    }
    else {
        HP1 = roundUp(static_cast<float>(HP1) * 0.90);
        EXP1 = roundUp(static_cast<float>(EXP1) * 1.20);

    }
    adjustValue(HP1, 0, 666);
    adjustValue(EXP1, 0, 600);
    adjustValue(M1, 0, 3000);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    
    if (E3 < 0 || E3 >99) return -99;

    //khởi tạo ma trận
    int taxiMap[10][10];

    //Tạo bản đồ cho chiếc taxi
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            taxiMap[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int c1 = 0;
    int c2 = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (taxiMap[i][j] > E3 * 2) //Tìm số phần tử lớn hơn E3x2
                c1++;

            else if (taxiMap[i][j] < -E3) //Tìm số phần tử nhỏ hơn -E3
                c2++;
        }
    }



    while (c1 > 9) c1 = c1 / 10 + (c1 % 10);

    while (c2 > 9) c2 = c2 / 10 + (c2 % 10);
    //Tìm vị trí gặp nhau của taxi và Sherlock-Watson
    int taxiScore = 0;
    int SherlockandWatsonScore = 0;
    int maxval;
    taxiScore = taxiMap[c1][c2];
    int i=c1, j=c2;

    maxval = taxiMap[c1][c2];
    while ((i >= 0 && i <= 9) && (j >= 0 && j <= 9)) {
        if (maxval < taxiMap[i][j]) {
            maxval = taxiMap[i][j];
            
        }
        i++; j++;
    }
    i = c1; j = c2;
    while ((i >= 0 && i <= 9) && (j >= 0 && j <= 9)) {
        if (maxval < taxiMap[i][j]) {
            maxval = taxiMap[i][j];
            
        }
        i--; j--;
    }
    i = c1; j = c2;
    while ((i >= 0 && i <= 9) && (j >= 0 && j <= 9)) {
        if (maxval < taxiMap[i][j]) {
            maxval = taxiMap[i][j];
            
        }
        i++; j--;
    }
    i = c1; j = c2;
    while ((i >= 0 && i <= 9) && (j >= 0 && j <= 9)) {
        if (maxval < taxiMap[i][j]) {
            maxval = taxiMap[i][j];
            
        }
        i--; j++;
    }


    SherlockandWatsonScore = abs(maxval);
    adjustValue(HP1, 0, 666);
    adjustValue(HP2, 0, 666);
    adjustValue(EXP1, 0, 600);
    adjustValue(EXP2, 0, 600);

    if (abs(taxiScore) > SherlockandWatsonScore) {
        //Không đuổi kịp
        EXP1 = roundUp(static_cast<float>(EXP1) * 0.88);
        EXP2 = roundUp(static_cast<float>(EXP2) * 0.88);
        HP1 = roundUp(static_cast<float>(HP1) * 0.9);
        HP2 = roundUp(static_cast<float>(HP2) * 0.9);
        return taxiScore;
    }
    //Đuổi kịp
    else {
        EXP1 = roundUp(static_cast<float>(EXP1) * 1.12);
        EXP2 = roundUp(static_cast<float>(EXP2) * 1.12);
        HP1 = roundUp(static_cast<float>(HP1) * 1.1);
        HP2 = roundUp(static_cast<float>(HP2) * 1.1);
        adjustValue(HP1, 0, 666);
        adjustValue(HP2, 0, 666);
        adjustValue(EXP1, 0, 600);
        adjustValue(EXP2, 0, 600);
        return SherlockandWatsonScore;
    }

}

    

// Task 4
bool isAlphaNumeric(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // Lấy chuỗi se từ email
        string se = "";
        for (int i = 0; email[i] != '@'; ++i) {
            se += email[i];
        }

        // Kiểm tra độ dài của mật khẩu
        int length = 0;
        while (s[length] != '\0') {
            length++;
        }
        if (length < 8) return -1; // Độ dài ngắn hơn độ dài tối thiểu
        if (length > 20) return -2; // Độ dài dài hơn độ dài tối đa

        // Kiểm tra mật khẩu không chứa chuỗi se
        int found = -1;
        for (int i = 0; s[i] != '\0'; ++i) {
            if (s[i] == se[0]) {
                bool match = true;
                for (int j = 1; se[j] != '\0'; ++j) {
                    if (s[i + j] != se[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    found = i;
                    break;
                }
            }
        }
        if (found != -1) return -(300 + found); // Mật khẩu chứa chuỗi se

        // Kiểm tra mật khẩu có chứa ký tự đặc biệt
        bool hasSpecialChar = false;
        for (int i = 0; s[i] != '\0'; ++i) {
            if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
                hasSpecialChar = true;
                break;
            }
        }
        if (!hasSpecialChar) return -5; // Mật khẩu không chứa ký tự đặc biệt

        // Kiểm tra mật khẩu không chứa nhiều hơn 2 ký tự liên tiếp và giống nhau
        for (int i = 0; i < length - 2; ++i) {
            if (s[i] == s[i + 1] && s[i] == s[i + 2]) return -(400 + i);
        }

        // Kiểm tra các ký tự trong mật khẩu
        for (int i = 0; s[i] != '\0'; ++i) {
            if (!isAlphaNumeric(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') {
                // Nếu không phải là chữ số, chữ cái, hoặc ký tự đặc biệt
                return s[i]; // Trả về vị trí của ký tự đầu tiên không hợp lệ
            }
        }

        // Mật khẩu hợp lệ
        return -10;
   
    }

// Task 5

    int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
        // TODO: Complete this function
        int* passwordCount = new int[num_pwds](); // Khởi tạo mảng đếm số lần xuất hiện của mật khẩu

        // Đếm số lần xuất hiện của mỗi mật khẩu trong mảng
        for (int i = 0; i < num_pwds; ++i) {
            if (passwordCount[i] == -1) continue; // Bỏ qua nếu đã kiểm tra mật khẩu này

            for (int j = i + 1; j < num_pwds; ++j) {
                if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                    passwordCount[i]++; // Tăng số lần xuất hiện của mật khẩu
                    passwordCount[j] = -1; // Đánh dấu là đã kiểm tra mật khẩu này
                }
            }
        }

        // Tìm mật khẩu xuất hiện nhiều nhất
        int maxCount = -1;
        int maxLength = -1;
        int index = -1;
        for (int i = 0; i < num_pwds; ++i) {
            if (passwordCount[i] > maxCount) {
                maxCount = passwordCount[i];
                maxLength = strlen(arr_pwds[i]); // Cập nhật độ dài mật khẩu đúng
                index = i;
            }
            else if (passwordCount[i] == maxCount) {
                int currentLength = strlen(arr_pwds[i]);
                if (currentLength > maxLength) {
                    maxLength = currentLength; // Cập nhật độ dài mật khẩu đúng
                    index = i;
                }
            }
        }

        delete[] passwordCount;

        return index;
    }

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////