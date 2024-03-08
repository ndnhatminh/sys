#include "study_in_pink1.h"

bool readFile(
    const string& filename,
    int& HP1,
    int& HP2,
    int& EXP1,
    int& EXP2,
    int& M1,
    int& M2,
    int& E1,
    int& E2,
    int& E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
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
    //Check hp và exp [0;600] lần 1
    exp1 = max(0, min(exp1, 600));
    exp2 = max(0, min(exp2, 600));
    //Trả về -99 nếu vượt e1
    if (e1 > 99 || e1 < 0) return -99;
    //Tính exp dựa trên e1
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
    case 4 ... 19:
        exp2 += ceil(float(e1) / 4 + 19);
        break;
    case 20 ... 49:
        exp2 += ceil(float(e1) / 9 + 21);
        break;
    case 50 ... 65:
        exp2 += ceil(float(e1) / 16 + 17);
        break;
    case 66 ... 79:
        exp2 += ceil(float(e1) / 4 + 19);
        if (exp2 > 200) exp2 += ceil(float(e1) / 9) + 21;
        break;
    case 80 ... 99:
        exp2 += ceil(float(e1) / 4) + 19 + ceil(float(e1) / 9) + 21;
        if (exp2 > 400) {
            exp2 += ceil(float(e1) / 16) + 17;
            exp2 += ceil(float(exp2) * 0.15);
        }
        break;
    default:exp2 += 149;
    }
    exp2 = max(0, min(exp2, 600));
    if (e1 < 4)
    {
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 += ceil(float(D) / 200);
        else exp1 -= floor(float(D) / 100);
        exp1 = max(0, min(exp1, 600));
        return exp1 + exp2;
    }
    exp1 -= e1;
    //Giới hạn hp và exp [0;600] 
    exp1 = max(0, min(exp1, 600));
    //Trả về tổng 2  exp
    return exp1 + exp2;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    float P[10] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11 };
    float P1, P2, P3;
    float d1;
    HP1 = max(0, min(HP1, 666));
    EXP1 = max(0, min(EXP1, 600));
    M1 = max(0, min(M1, 3000));
    //-------------------------CON ĐƯỜNG 1--------------------------
    //Trả về -99 nếu vượt quá E2
    if (E2 < 0 || E2 > 99) return -99;
    // Tính P2 và cập nhật tiền chi phí nếu cần
    d1 = round(sqrt(EXP1)) * round(sqrt(EXP1));
    if (EXP1 >= d1) P1 = 1;
    else P1 = (EXP1 / d1 + 80) / 123;
    //-------------------------CON ĐƯỜNG 2--------------------------
    if (E2 % 2 == 0) d1 = 1;
    else d1 = float(M1) / 2;
    if (M1 != 0)
        do {
            if (HP1 < 200) {
                HP1 += ceil(float(HP1) * 0.3 - 0.000001); 
                HP1 = max(0, min(HP1, 666));
                M1 -= 150;
            } else {
                HP1 += ceil(float(HP1) * 0.1 - 0.000001);
                M1 -= 70;
                HP1 = max(0, min(HP1, 666));
            }
            if (M1 < d1) break;
            //
            if (EXP1 < 400) M1 -= 200;
            else  M1 -= 120;
            EXP1 += ceil(float(EXP1) * 0.13 - 0.000001);
            EXP1 = max(0, min(EXP1, 600));
            if (M1 < d1) break;
            //
            if (EXP1 < 300)  M1 -= 100;
            else  M1 -= 120;
            EXP1 = ceil(float(EXP1) * 0.9 - 0.000001);

        } while (M1 >= d1 && d1 != 1);

        M1 = max(0, min(M1, 3000));
        HP1 = ceil(float(HP1) * 0.83 -0.000001);
        EXP1 += ceil(float(EXP1) * 0.17 -0.000001);
        EXP1 = max(0, min(EXP1, 600));
        d1 = round(sqrt(EXP1)) * round(sqrt(EXP1));
        if (EXP1 >= d1) P2 = 1;
        else P2 = (EXP1 / d1 + 80) / 123;
        //--------------------------CON ĐƯỜNG 3------------------------
        int i = (E2 / 10 + E2 % 10) % 10;
        P3 = P[i];
        if (P1 == P2 && P2 == P3 && P3 == 1) { EXP1 = ceil(float(EXP1) * 0.75 - 0.000001 );
            EXP1 = max(0, min(EXP1, 600));}
        else {
            d1 = (P1 + P2 + P3) / 3;
            if (d1 < 0.5) {
                HP1 = ceil(float(HP1 * 0.85 - 0.000001));
                EXP1 += ceil(float(EXP1 * 0.15 - 0.000001));
                EXP1 = max(0, min(EXP1, 600));
            } 
            else {
                HP1 = ceil(float(HP1 * 0.9 - 0.000001 ));
                EXP1 = ceil(float(EXP1 * 1.2 - 0.000001));
                EXP1 = max(0, min(EXP1, 600));
            }
        }
        // Đảm bảo giới hạn các giá trị đã được lồng xếp vào nhiều chỗ
        return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3>99) return -99;
    // Khởi tạo ma trận 10x10 với giá trị ban đầu là 0
    constexpr int matran = 10;
    int map[matran][matran] = {0};
    // Tính điểm số của chiếc taxi tại mỗi vị trí
    int count_duong = 0, count_am = 0;
    for (int i = 0; i < matran; ++i) {
        for (int j = 0; j < matran; ++j) {
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (map[i][j] > E3 * 2) ++count_duong;
            if (map[i][j] < -E3) ++count_am;
        }
    }
    // Tính toán vị trí gặp nhau
    count_duong = (count_duong / 10 + count_duong % 10) / 10 + (count_duong / 10 + count_duong % 10) % 10;
    count_am = (count_am / 10 + count_am % 10) / 10 + (count_am / 10 + count_am % 10) % 10;
    int i=count_duong;
    int j=count_am;
    // Kiểm tra điểm số của Sherlock và Watson
    int taxi_score = map[i][j];  
    // Xác định điểm số của Sherlock và Watson
    int sherlock_watson_score = map[i][j];
    for (int k = 0; i - k >= 0 && j + k < 10; ++k) {
        sherlock_watson_score = max(sherlock_watson_score, map[i - k][j + k]);
    }
    for (int k = 0; i + k < 10 && j - k >= 0; ++k) {
        sherlock_watson_score = max(sherlock_watson_score, map[i + k][j - k]);
    }
    for (int k = 0; i + k < 10 && j + k < 10 ; ++k) {
        sherlock_watson_score = max(sherlock_watson_score, map[i + k][j + k]);
    }
    for (int k = 0; i + k < 10 && j + k < 10; ++k) {
        sherlock_watson_score = max(sherlock_watson_score, map[i - k][j - k]);
    }

    // Cập nhật EXP và HP của Sherlock và Watson
    if (abs(taxi_score) > sherlock_watson_score) {
        EXP1 = ceil(float(EXP1) * 0.88);EXP1 = max(0, min(EXP1, 600));

        HP1 = ceil(float(HP1) * 0.9);HP1 = max(0, min(HP1, 666));

        EXP2 = ceil(float(EXP2) * 0.88);EXP2 = max(0, min(EXP2, 600));

        HP2 = ceil(float(HP2) * 0.9);HP2 = max(0, min(HP2, 666));
        return taxi_score;
    } else {
        EXP1 = ceil(float(EXP1) * 1.12);EXP1 = max(0, min(EXP1, 600));

        HP1 = ceil(float(HP1) * 1.1);HP1 = max(0, min(HP1, 666));

        EXP2 = ceil(float(EXP2) * 1.12);EXP2 = max(0, min(EXP2, 600));

        HP2 = ceil(float(HP2) * 1.1);HP2 = max(0, min(HP2, 666));
        return sherlock_watson_score;
    }
    // Trả về điểm số lớn hơn tại vị trí gặp nhau
}
// Task 4
int checkPassword(const char* s, const char* email) {
    // Mảng chứa các ký tự đặc biệt được phép trong mật khẩu
    char special_chars[5] = { '#','$','!','%','@' }, kt[1];
    // Lưu phần trước dấu '@' vào chuỗi
    string s1;
    int emailLength = strlen(email);
    int invalidIndex = -1;

    // Duyệt qua email để lấy phần trước dấu '@'
    for (int i = 0; i < emailLength; i++) {
        if (email[i] == '@') break;
        s1.push_back(email[i]);
    }
    int passwordLength = strlen(s);
    // Kiểm tra độ dài mật khẩu, nếu nhỏ hơn 8 hoặc lớn hơn 20, trả về mã lỗi tương ứng
    if (passwordLength < 8) return -1;
    if (passwordLength > 20) return -2;
    // Kiểm tra mật khẩu có chứa phần của email hay không
    const char* foundEmail = strstr(s, s1.c_str());
    if (foundEmail != nullptr) return -static_cast<int>(foundEmail - s) - 300;
    // Kiểm tra mật khẩu có chứa 3 ký tự giống nhau liên tiếp hay không
    for (int i = 0; i < passwordLength - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) return -(400 + i);
    }
    // Kiểm tra các ký tự không hợp lệ trong mật khẩu
    for (int i = 0; i < passwordLength; ++i) {
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '!' || s[i] == '%')) {
            invalidIndex = i;
            break;
        }
    }
    // Kiểm tra các ký tự đặc biệt trong mật khẩu
    int specialCharCount = 0;
    for (int i = 0; i < 5 ; ++i) {
        foundEmail = strchr(s, special_chars[i]);
        if (foundEmail != nullptr && invalidIndex == -1)  return -10;
        else if (foundEmail == nullptr) specialCharCount++;
    }
    // Nếu mật khẩu không chứa bất kỳ ký tự đặc biệt nào, trả về mã lỗi tương ứng
    if (specialCharCount == 5) return -5;
    // Nếu mật khẩu không chứa ký tự không hợp lệ nào, trả về vị trí của ký tự không hợp lệ đầu tiên
    return invalidIndex;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_count = 0;// Số lần xuất hiện tối đa của một mật khẩu
    int max_length = 0;// Độ dài tối đa của một mật khẩu
    int max_index = -1;// Vị trí đầu tiên của mật khẩu đúng trong mảng
    
    for (int i = 0; i < num_pwds; ++i) {
        int current_count = 0;// Số lần xuất hiện của mật khẩu hiện tại
        int current_length = strlen(arr_pwds[i]);// Độ dài của mật khẩu hiện tại
        // Đếm số lần xuất hiện của mật khẩu hiện tại  
        
        for (int j = 0; j < num_pwds; ++j) {
            if (i != j && strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                current_count++;
            }
        }
        // Kiểm tra xem mật khẩu hiện tại có xuất hiện nhiều lần hơn và có độ dài lớn hơn
        // Mật khẩu tìm thấy trước đó hay không
        if (current_count > max_count || (current_count == max_count && current_length > max_length)) {
            max_count = current_count;
            max_length = current_length;
            max_index = i;
        }
    }

    return max_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////