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
    //Tính exp dựa trên e1
    if (e1 >= 0 && e1 <=3){
        if (e1 == 0) exp2 += 29;
        else if (e1 == 1) exp2 += 45;       
        else if (e1 == 2) exp2 += 75;
        else exp2 = exp2 + 29 + 45 + 75;
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = ceil(float(exp1 + D/200));
        else exp1 = ceil(float(exp1 - D/100));    
    }    
    else if (e1 >= 4 && e1 <=99) {
        if ( e1 >= 4 && e1<= 19) exp2 = int(ceil(exp2 + e1/4.0 + 19));
        else if ( e1 >= 20 && e1 <= 49) exp2 = int(ceil(exp2 + e1/9.0 + 21));
        else if ( e1 >= 50 && e1 <= 65) exp2 = int(ceil(exp2 + e1/16.0 + 17));
        else if ( e1 >= 66 && e1 <= 79) {
          if (exp2 > 200) exp2 = int(ceil(exp2 + (e1/9.0 + 21)));  
          exp2 = int(ceil (exp2 + (e1/4.0 + 19)));
        }
        else if (  e1 >= 80 && e1<= 99) {
          exp2 += ceil(float(e1) / 4) + 19 + ceil(float(e1) / 9) + 21; 
          if (exp2 > 400) {
            exp2 += ceil(float(e1) / 16) + 17;
            exp2 += ceil(float(exp2) * 0.15);
        }           
        }  
        exp1 = exp1 - e1;                      
    }
    //Trả về 99
    else return e1 = -99; 
    //Giới hạn hp và exp [0;600]
    exp1 = max(0, min(exp1, 600));
    exp2 = max(0, min(exp2, 600));
    //Trả về tổng 2  exp
    return exp1 + exp2;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    float P1, P2, P3;
    int d1, d2;
    // Tính P2 và cập nhật tiền chi phí nếu cần
    d1 = pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= d1) P1 = 1;
    else P1 = (EXP1 / d1 + 80.0) / 123.0;

    float tienphannua = M1 * 0.5;
   
    if (M1 > tienphannua) {
        while (M1 > tienphannua) {
            if (HP1 < 200) {
                HP1 = ceil(float(HP1 * 1.3));
                M1 -= 150;
            } else {
                HP1 = ceil(float(HP1 * 1.1));
                M1 -= 70;            
            }

            if (M1 < tienphannua) break;

            if (EXP1 < 400) M1 -= 200;               
            else M1 -= 120;          
            EXP1 = ceil(float(EXP1 * 1.13));

            if (M1 < tienphannua) break;

            if (EXP1 < 300) {
                M1 -= 100; 
                EXP1 = ceil(float(EXP1 - EXP1 * 0.1));
            } else {
                M1 -= 120;
                EXP1 = ceil(float(EXP1 * 0.9));
            }

            if (M1 < tienphannua) break; 

            if (E2 % 2 == 0) break;       
        }
    } else {
        while (M1 < tienphannua) {
            if (HP1 < 200) {
                HP1 = ceil(float(HP1 * 1.3));
                M1 -= 150;
            } else {
                HP1 = ceil(float(HP1 * 1.1));
                M1 -= 70;            
            }

            if (M1 < 120) {
                M1 = 0;
                break;
            }
        
            if (EXP1 < 400) M1 -= 200;               
            else M1 -= 120;          
            EXP1 = ceil(float(EXP1 * 1.13));

            if (M1 < 70) {
                M1 = 0;
                break;
            }
            if (E2 % 2 == 0) break;
        }
    }
    // Cập nhật HP1 và EXP1
    HP1 = ceil(float(HP1 * 0.83));
    EXP1 = ceil(float(EXP1 * 1.17));
    // Tính P3 và xác định giá trị cuối cùng của p
    d2 = pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= d2) P2 = 1; 
    else P2 = (EXP1 / d2 + 80.0) / 123.0;

    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = E2 > 10 ? ((E2 / 10 + E2 % 10) % 10) : E2;
    P3 = P[i] / 100.0;

    float p = (P1 + P2 + P3) / 3.0;
    // Cập nhật HP1 và EXP1 cuối cùng dựa trên p
    if (p == 1.0) HP1 = ceil(float(HP1 * 0.75));
    else {
        if (p < 0.5) {
            HP1 = ceil(float(HP1 * 0.85));
            EXP1 = ceil(float(EXP1 * 1.15));
        } else {
            HP1 = ceil(float(HP1 * 0.9));
            EXP1 = ceil(float(EXP1 * 1.2));
        }
    }

    // Đảm bảo giới hạn các giá trị
    HP1 = min(HP1, 666);
    HP1 = max(HP1, 0);
    EXP1 = min(EXP1, 600);
    EXP1 = max(EXP1, 0);
    M1 = min(M1, 3000);
    M1 = max(M1, 0);
    if (E2 < 0 || E2 > 99) E2 = -99;

    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    // Khởi tạo ma trận 10x10 với giá trị ban đầu là 0
    constexpr int matran = 10;
    int map[matran][matran] = {0};

    // Tính điểm số của chiếc taxi tại mỗi vị trí
     for (int i = 0; i < matran; i++) {
        for (int j = 0; j < matran; j++) {
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
     }

    // Tính toán chỉ số i và j dựa trên số điểm dương và âm
    int count_duong = 0, count_am = 0;
     for (int i = 0; i < matran; ++i) {
        for (int j = 0; j < matran; ++j) {
            if (map[i][j] > E3 * 2) {
                ++count_duong;
            }
            if (map[i][j] < -E3) {
                ++count_am;
            }
        }
     }
    // Tính toán vị trí gặp nhau
    int i = count_duong, j = count_am;
    while (i > 9) {
        i = i % 10 + i / 10;
    }
    while (j > 9) {
        j = j % 10 + j / 10;
    }

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
        EXP1 = min(int(ceil(float(EXP1) * 0.88)), 600);
        HP1 = min(int(ceil(float(HP1) * 0.9)), 666);
        EXP2 = min(int(ceil(float(EXP2) * 0.88)), 600);
        HP2 = min(int(ceil(float(HP2) * 0.9)), 666);
        return taxi_score;
    } else {
        
        EXP1 = min(int(ceil(float(EXP1) * 1.12)), 600);
        HP1 = min(int(ceil(float(HP1) * 1.1)), 666);
        EXP2 = min(int(ceil(float(EXP2) * 1.12)), 600);
        HP2 = min(int(ceil(float(HP2) * 1.1)), 666);
        return sherlock_watson_score;
    }
    // Trả về điểm số lớn hơn tại vị trí gặp nhau
    return -1;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string password(s);
    string se(email);
    se = se.substr(0, se.find('@'));
    string special_chars = "@#%$!";
    
    // Kiểm tra độ dài mật khẩu
    if (password.length() < 8) {
        return -1;// Mật khẩu quá ngắn
    }
    if (password.length() > 20) {
        return -2;// Mật khẩu quá dài
    }

    // Kiểm tra trong mật khẩu có chứa email không
    size_t se_index = password.find(se);
    if (se_index != string::npos) {
        return -(300 + se_index);// Mật khẩu chứa phần đầu của email
    }

    // Kiểm tra có nhiều hơn 2 ký tự giống nhau liên tiếp
    for (size_t i = 0; i < password.length() - 2; ++i) {
        if (password[i] == password[i+1] && password[i+1] == password[i+2]) {
            return -(400 + i);// Mật khẩu có 3 ký tự giống nhau liên tiếp
        }
    }

    // Kiểm tra ký tự đặc biệt
    bool has_special_char = false;
    for (char c : password) {
        if (special_chars.find(c) != string::npos) {
            has_special_char = true;
            break;
        }
    }
    if (!has_special_char) {
        return -5;// Mật khẩu không chứa ký tự đặc biệt
    }

    //Kiểm tra các ký tự không hợp lệ
    for (size_t i = 0; i < password.length(); ++i) {
        char c = password[i];
        if (!isalnum(c) && special_chars.find(c) == string::npos) {
            return i;// Mật khẩu chứa ký tự không hợp lệ
        }
    }
    // Mật khẩu hợp lệ
    return -10;
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