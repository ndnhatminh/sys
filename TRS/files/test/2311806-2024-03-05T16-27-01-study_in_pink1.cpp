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
int YEA(double & a)
{
    
    return static_cast<int>((double)a) - static_cast<int>((double)a > 10e-7) ? ceil((double)a) : (double)(a);
    
}
// Task 1
void checkHP(int & HP) {
    if (HP < 0) HP = 0;
    if (HP > 666) HP = 666;
}
int checkEXP(int & EXP) {
    if (EXP < 0) EXP = 0;
    if (EXP > 600) EXP = 600;
    return EXP;
}
int checkMoney(int & m) {
    if (m < 0)   m = 0;
    if (m > 3000)  m = 3000;
    return m;
}
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 >= 0 && e1 <= 3)
    {
        switch (e1) {
        case 0: exp2 = exp2 + 29;
            break;
        case 1: exp2 = exp2 + 45;
            break;
        case 2: exp2 = exp2 + 75;
            break;
        case 3: exp2 = exp2 + 29 + 45 + 75;
            break;
        }
      
        int D = e1 * 3 + exp1 * 7;
        //int c = static_cast<int>(((double)D / 200.0)) - static_cast<int>((double)D / 200.0 > 10e-7) ? ceil((double)D / 200.0) : (double)D / 200.0;
        //int d = static_cast<int>(((double)D / 100.0)) - static_cast<int>((double)D / 100.0 > 10e-7) ? ceil((double)D / 100.0) : (double)D / 100.0;
        if (D % 2 == 0)
            exp1 =  static_cast<int>(ceil(exp1 + (D) / 200.0));
        else
            exp1 =  static_cast<int>(ceil(exp1 - (D) / 100.0));
       
  

        return exp1 + exp2;
    }
   

    // Tính c và d
   

    // TODO: Complete this function
    
        if (e1 >= 4 && e1 <= 19)    exp2 = exp2 + ceil(e1 / 4.0 - 1e-9) + 19;
        if (e1 >= 20 && e1 <= 49)	exp2 = exp2 + ceil(e1 / 9.0 - 1e-9) + 21;
        if (e1 >= 50 && e1 <= 65)	exp2 = exp2 + ceil(e1 / 16.0 - 1e-9) + 17;
        if (e1 >= 66 && e1 <= 79)
        {
            exp2 = exp2 + ceil(e1 / 4.0) + 19;
            if (exp2 > 200)	exp2 = exp2 + ceil(e1 / 9.0 - 1e-9) + 21;
        }
        if (e1 >= 80 && e1 <= 99)
        {
            exp2 = exp2 + ceil(e1 / 4.0 - 1e-9) + 19;
            exp2 = exp2 + ceil(e1 / 9.0 - 1e-9) + 21;
            if (exp2 > 400) {
                exp2 = exp2 + ceil(e1 / 16.0) + 17;
                exp2 = ceil(exp2 * 1.15 - 1e-9);
            }
        }
        exp1 = exp1 - e1;
        if (exp2 > 600) exp2 = 600;
        checkEXP(exp2);
        checkEXP(exp1);
    return exp1 + exp2;
}
// Task 2
int way1(int & exp) {
    int n = sqrt(exp);
    if ((exp - n * n) > ((n + 1) * (n + 1) - exp)) return (n + 1) * (n + 1);
    else return n * n;
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function 
    float P1, P2, P3;
    checkEXP(EXP1);
    //way1
    if (way1(EXP1) <= EXP1) P1 = 1.0;
    else P1 = round((EXP1 / way1(EXP1) + 80.0) / 123.0 * 100.0) / 100.0;
    //way2
    int Money = ceil(M1 * 0.5 - 1e-9);
    
    do {
        if (M1 == 0) break;
        if (HP1 < 200) {
            HP1 = ceil((double)HP1 * 1.3 - 1e-9);
            checkHP(HP1);
            M1 = M1 - 150;
        }
        else {
            HP1 =ceil((double)HP1 * 1.1 - 1e-9);
            checkHP(HP1);
            M1 = M1 - 70;
        }
        if ((M1 - Money < 0 && E2 % 2 == 1) || M1 <= 0) break;

        if (EXP1 < 400)        M1 = M1 - 200;
        else                   M1 = M1 - 120;
        EXP1 = ceil((double)EXP1 * 1.13 - 1e-9);
        
   
        if ((M1 - Money < 0 && E2 % 2 == 1) || M1 <= 0) break;
        
        if (EXP1 > 300)  M1 = M1 - 120;
        else  M1 = M1 - 100; 
        EXP1 = ceil((double)EXP1 * 0.9 - 1e-9);
        checkEXP(EXP1);
        if ((M1 - Money < 0 && E2 % 2 == 1) || M1 <= 0) break;
        if (E2 % 2 == 0) break;
    } while (M1 - Money > 0);
    
    HP1 = ceil(0.83 * HP1 - 1e-9);
    EXP1 = ceil(1.17 * EXP1 - 1e-9);
    
        if (way1(EXP1) <= EXP1) P2 = 1.0;
    else P2 = round((EXP1 / way1(EXP1) + 80.0) / 123.0 * 100.0) / 100.0;
    //way3
    int p[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2 - 10 <= 0) P3 = p[E2] * 0.01;
    else {
        int a = E2 / 10;
        int b = E2 % 10;
        if (a+b>=10) P3 = p[a + b - 10] * 0.01;
        if (a + b < 10) P3 = p[a + b] * 0.01;
    }
    if (P1 == P2 == P3 == 1.0) EXP1 = ceil(0.75 * EXP1 - 1e-9);
    float P = round((P1 + P2 + P3) / 3 * 100) / 100;
    if (P < 0.5) 
    {
        HP1 = ceil(0.85 * HP1 - 1e-9);
        EXP1 = ceil(1.15 * EXP1 - 1e-9);
    }
    else {
        HP1 = ceil(0.9 * HP1 - 1e-9);
        EXP1 = ceil(1.2 * EXP1 - 1e-9);
    }
    checkEXP(EXP1);
    return HP1 + EXP1 + M1;
}
int tinh(int& a) {
    while (a >= 10) {
        int sum = (a / 10) + (a % 10);
        a = sum;
    }
    return a;
 }
// Task 3
int MAX(int matrix[10][10], int row, int col) {
    int maxVal = matrix[row][col]; // Khởi tạo giá trị lớn nhất bằng giá trị tại điểm (a, b)

    // Duyệt qua các phần tử trên đường chéo trái chứa điểm (a, b)
    for (int k = 0; k < 10; ++k) {
        int a = k;
        int b = col - row + k; // Tính toán cột tương ứng trên đường chéo trái
        if (b >= 0 && b < 10) {
            maxVal = max(maxVal, matrix[a][b]);
        }
    }

    // Duyệt qua các phần tử trên đường chéo phải chứa điểm (a, b)
    for (int k = 0; k < 10; ++k) {
        int a = k;
        int b = row + col - k; // Tính toán cột tương ứng trên đường chéo phải
        if (b >= 0 && b < 10) {
            maxVal = max(maxVal, matrix[a][b]);
        }
    }

    return maxVal;
}


    int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
        int I =0, J = 0;
        int max;
        int taxi[10][10];
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if (taxi[i][j] > E3 * 2) I = I + 1;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if (taxi[i][j] < -E3 ) J = J + 1;
        int i = tinh(I);
        int j = tinh(J);
        if ( MAX(taxi, i, j) > abs(taxi[i][j])) 
        {
            EXP1 = ceil(EXP1 * 1.12 - 1e-9);
            EXP2 = ceil(EXP2 * 1.12 - 1e-9);
            HP1 = ceil(HP1 * 1.1 - 1e-9);
            HP2 = ceil(HP2 * 1.1 - 1e-9);
            return MAX(taxi, i, j);
        }
        else
        {
            EXP1 = ceil(EXP1 * 0.88 - 1e-9);
            EXP2 = ceil(EXP2 * 0.88 - 1e-9);
            HP1 = ceil(HP1 * 0.9 - 1e-9);
            HP2 = ceil(HP2 * 0.9 - 1e-9);
            return taxi[i][j];
        }
}

// Task 4
   
    int checkPassword(const char* s, const char* email) {
        // Tìm chuỗi 'se' trong email
        size_t at_position = strchr(email, '@') - email;
        string se = string(email).substr(0, at_position);

        // Độ dài tối thiểu và tối đa của mật khẩu
        int minLength = 8;
        int maxLength = 20;

        // Kiểm tra độ dài của mật khẩu
        int s_length = strlen(s);
        if (s_length < minLength) {
            return -1; // Mật khẩu ngắn hơn độ dài tối thiểu
        }
        if (s_length > maxLength) {
            return -2; // Mật khẩu dài hơn độ dài tối đa
        }

        // Kiểm tra có chứa chuỗi 'se' không
        const char* found_se = strstr(s, se.c_str());
        if (found_se != nullptr) {
            return -(300 + (found_se - s)); // Trả về vị trí của 'se'
        }

        // Kiểm tra có chứa ký tự đặc biệt không
        bool hasSpecialChar = false;
        for (int i = 0; i < s_length; ++i) {
            if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
                hasSpecialChar = true;
                break;
            }
        }
        if (!hasSpecialChar) {
            return -5; // Mật khẩu không chứa ký tự đặc biệt
        }

        // Kiểm tra nhiều hơn 2 ký tự liên tiếp
        for (int i = 0; i < s_length - 2; ++i) {
            if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
                return -(400 + i); // Trả về vị trí của chuỗi ký tự liên tiếp
            }
        }

        // Mật khẩu hợp lệ
        return -10;
    }


   
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this functionint findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    int max_count = 0;
    int max_length = 0;
    int correct_index = -1;

    // Lặp qua mảng mật khẩu
    for (int i = 0; i < num_pwds; i++) {
        const char* pwd = arr_pwds[i];
        int length = strlen(pwd);
        int count = 1; // Đếm số lần xuất hiện của mật khẩu

        // Lặp lại từng phần tử sau mật khẩu hiện tại
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(pwd, arr_pwds[j]) == 0) {
                count++; // Tăng số lần xuất hiện nếu tìm thấy mật khẩu giống nhau
            }
        }

        // Kiểm tra xem mật khẩu hiện tại có phải là mật khẩu đúng không
        if (count > max_count || (count == max_count && length >= max_length)) {
            max_count = count;
            max_length = length;
            correct_index = i;
        }
    }

    return correct_index;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////