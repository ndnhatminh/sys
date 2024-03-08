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
void checkHP (int& hp){
// Xử lý thông tin cho hp
    if (hp > 666) {
        hp = 666;
    } else if (hp < 0) {
        hp = 0;
    }
}
void checkEXP (int& exp){
// Xử lý thông tin cho exp
    if (exp > 600) {
        exp = 600;
    } else if (exp < 0) {
        exp = 0;
    }
}

void checkM(int& m){
  // Xử lý thông tin cho m
    if (m > 3000) {
        m = 3000;
    } else if (m < 0) {
        m = 0;
    }
}



// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 <0 && e1 > 99) return -99;
    checkEXP(exp1);
    checkEXP(exp2);
    // Trường hợp e1 thuộc [0,3]
    if (e1 >= 0 && e1 <= 3) {
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
            case 3:
                exp2 += (29 + 45 + 75); // Tổng của 3 trường hợp trước đó
                break;
        }
         // Tính D
    const int D = e1 * 3 + exp1 * 7;

    // Nếu D chia hết cho 2 (D chẵn), cộng thêm D/200 vào exp1
    if (D % 2 == 0) {
        exp1 += D / 200;
    } else {
        // Nếu D không chia hết cho 2 (D lẻ), trừ đi D/100 từ exp1
        exp1 -= D / 100;
    }
    }
    // Trường hợp e1 thuộc [4,99]
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19)
            exp2 += ceil(e1 / 4.0 + 19);
        else if (e1 >= 20 && e1 <= 49)
            exp2 += ceil(e1 / 9.0 + 21);
        else if (e1 >= 50 && e1 <= 65)
            exp2 += ceil(e1 / 16.0 + 17);
        else if (e1 >= 66 && e1 <= 79) {
            exp2 += ceil(e1 / 4.0 + 19);
            if (exp2 > 200)
                exp2 += ceil(e1 / 9.0 + 21);
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 += ceil(e1 / 4.0 + 19);
            if (exp2 > 200)
                exp2 += ceil(e1 / 9.0 + 21);
            if (exp2 > 400)
                exp2 += ceil(e1 / 16.0 + 17);
            exp2 += ceil(exp2 * 0.15); // Thêm 15% của exp2 cũ
        }
        exp1 -= e1;
    }
    checkEXP(exp1);
    checkEXP(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 <0 && E2 > 99) return -99;
    checkEXP(EXP1);
    checkHP(HP1);
    checkM(M1);
   float P1, P2, P3;

       //Con đường 1
    float A=sqrt(EXP1);
    float S=round(A)*round(A);
    if(EXP1>=S) {
        P1=100;
    }
    else {
        P1=(EXP1/S+80)/1.23;
    };
    //Con đường 2
    int Mt=M1;
    Gate:
    if (HP1<200) {
        HP1=ceil(HP1*1.3);
        M1-=150;
    }
    else {
        HP1=ceil(HP1*1.1);
        M1-=70;
    };
      if (M1<=0.5*(Mt) and E2%2!=0) {
          goto End;
      }
      else if (M1<0 and E2%2==0) {
          M1=0;
          goto End;
      };
    if (EXP1<400) {
        M1-=200;
    }
    else {
        M1-=120;
    };
    EXP1=ceil(EXP1*1.13);
      if (M1<=0.5*(Mt) and E2%2!=0) {
          goto End;
      }
      else if (M1<0 and E2%2==0) {
          M1=0;
          goto End;
      };
    if (EXP1<300) {
        M1-=100;
    }
    else {
        M1-=120;
    }
    EXP1=ceil(EXP1*0.9);
      if (M1<=0.5*(Mt) and E2%2!=0) {
          goto End;
      }
      else if (M1<0 and E2%2==0) {
          M1=0;
          goto End;
      };
    if (E2%2!=0) {
        goto Gate;
    }
    End:
    HP1 =ceil(HP1*0.83);
    EXP1 =ceil(EXP1*1.17);
    A=sqrt(EXP1);
    S=round(A)*round(A);
    if(EXP1>=S) {
        P2=100;
    }
    else {
        P2=(EXP1/S+80)/1.23;
    };
    //Con đường 3
    int i;
    int P[]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2<10) {
        i=E2;
    }
    else {
        i=((E2/10)+(E2%10))%10;
    }
    P3=P[i];
    float PT;
    if (P1==P2==P3==100) {
        EXP1=ceil(EXP1*0.75);
    }
    else {
         PT=(P1+P2+P3)/3;
        if (PT<50) {
            HP1=ceil(HP1*0.85);
            EXP1=ceil(1.15*EXP1);
        }
        else {
            HP1=ceil(HP1*0.9);
            EXP1=ceil(1.2*EXP1);
        }
    };

    checkEXP(EXP1);
    checkHP(HP1);
    checkM(M1);
    
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    checkEXP(EXP1);
    checkHP(HP1);
    checkEXP(EXP2);
    checkHP(HP2);
    if (E3 <0 && E3 > 99) return -99;
   
// tạo ma trận
const int N = 10;
    int matrix[N][N];
    int cross[40]; // Số lượng phần tử tối đa trong mảng cross là 20 + 20 = 40

    // Tạo ma trận và tính toán giá trị i và j
    int i = 0, j = 0;
    for (int i_ = 0; i_ < N; i_++) {
        for (int j_ = 0; j_ < N; j_++) {
            // Tính toán scoreT (điểm của taxi) tại điểm (i, j)
            int scoreT1 = ((E3 * j_) + (i_ * 2)) * (i_ - j_);
            // Lưu giá trị scoreT vào ma trận
            matrix[i_][j_] = scoreT1;

            if (scoreT1 > 2 * E3) i++;
            else if (scoreT1 < -E3) j++;
        }
    }

    // Chia nhỏ giá trị i và j nếu cần
    while (i >= 10) i = i / 10 + i % 10;
    while (j >= 10) j = j / 10 + j % 10;

    // Tính điểm của Sher và Was
    int a = i, b = j, c = i, d = j, n = 0;
    for (int k = -9; k < 10; k++) {
        a = i + k; b = j + k; c = i + k; d = j - k;
        if (a >= 0 && a <= 9 && b >= 0 && b <= 9) {
            cross[n++] = matrix[a][b];
        }
        if (c >= 0 && c <= 9 && d >= 0 && d <= 9) {
            cross[n++] = matrix[c][d];
        }
    }

    int scoreS = cross[0];
    for (int i = 1; i < n; i++) {
        if (scoreS < cross[i]) {
            scoreS = cross[i];
        }
    }
    scoreS = abs(scoreS);

    int Re;
    // So sánh scoreS và scoreT
    if (scoreS > abs(matrix[i][j])) {
        Re = scoreS;
        EXP1 += ceil(0.12 * EXP1);
        HP1 += ceil(0.10 * HP1);
        EXP2 += ceil(0.12 * EXP2);
        HP2 += ceil(0.10 * HP2);
    } else if (scoreS < abs(matrix[i][j])) {
        Re = matrix[i][j];
        EXP1 -= ceil(0.12 * EXP1);
        HP1 -= ceil(0.10 * HP1);
        EXP2 -= ceil(0.12 * EXP2);
        HP2 -= ceil(0.10 * HP2);
    }
    checkEXP(EXP1);
    checkHP(HP1);
    checkEXP(EXP2);
    checkHP(HP2);
 return Re ;
}



// Task 4
int checkPassword(const char * s, const char * email) {
 // Tìm vị trí của ký tự '@' trong email
    const char *atPos = strchr(email, '@');
    if (atPos == nullptr)
        return -3; // Không tìm thấy ký tự '@'

    int emailLength = atPos - email;
    if (emailLength < 1 || emailLength > 100)
        return -1; // Email không hợp lệ

    // Tạo chuỗi se từ email
    char se[101];
    strncpy(se, email, emailLength);
    se[emailLength] = '\0';

    // Kiểm tra độ dài của mật khẩu
    int sLength = strlen(s);
    if (sLength < 8)
        return -1; // Mật khẩu quá ngắn
    if (sLength > 20)
        return -2; // Mật khẩu quá dài

    // Kiểm tra xem mật khẩu có chứa chuỗi se không
    const char *sePosition = strstr(s, se);
    if (sePosition != nullptr)
        return -(300 + (sePosition - s)); // Mật khẩu chứa chuỗi se

    // Kiểm tra các yêu cầu khác của mật khẩu
    bool hasSpecialChar = false;
    bool hasConsecutiveRepeatedChars = false;
    for (int i = 0; i < sLength; ++i) {
        // Kiểm tra ký tự đặc biệt
        if (!(isdigit(s[i]) || isalpha(s[i]) || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))
            return i; // Mật khẩu không hợp lệ vì chứa ký tự không hợp lệ
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            hasSpecialChar = true;

        // Kiểm tra các ký tự liên tiếp và giống nhau
        if (i > 1 && s[i] == s[i - 1] && s[i] == s[i - 2])
            hasConsecutiveRepeatedChars = true;
    }

    if (!hasSpecialChar)
        return -5; // Mật khẩu không chứa ký tự đặc biệt
    if (hasConsecutiveRepeatedChars)
        return -(400 + (sLength - 2)); // Mật khẩu có chứa nhiều hơn 2 ký tự liên tiếp và giống nhau

    return -10; // Mật khẩu hợp lệ
}


// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    // Tạo một mảng để lưu trữ số lần xuất hiện của mỗi mật khẩu
    int *passwordCounts = new int[num_pwds];
    memset(passwordCounts, 0, num_pwds * sizeof(int));
    
    // Lặp qua mảng arr_pwds để đếm số lần xuất hiện của mỗi mật khẩu
    for (int i = 0; i < num_pwds; ++i) {
        for (int j = i + 1; j < num_pwds; ++j) {
            if (std::strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                passwordCounts[i]++;
            }
        }
    }
    
    // Tìm mật khẩu có số lần xuất hiện nhiều nhất và độ dài dài nhất
    int maxCount = 0;
    size_t maxLength = 0;
    int mostCommonPasswordIndex = -1;
    for (int i = 0; i < num_pwds; ++i) {
        if (passwordCounts[i] > maxCount || (passwordCounts[i] == maxCount && std::strlen(arr_pwds[i]) > maxLength)) {
            maxCount = passwordCounts[i];
            maxLength = std::strlen(arr_pwds[i]);
            mostCommonPasswordIndex = i;
        }
    }
    
    delete[] passwordCounts;
    
    return mostCommonPasswordIndex;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////