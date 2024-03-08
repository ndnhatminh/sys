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
    // Hàm này được sử dụng để đọc file input,
    // KHÔNG CHỈNH SỬA HÀM NÀY
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else {
        cerr << "Không tìm thấy file" << endl;
        return false;
    }
}

void checkM(int &i){
    if(i<=0){
        i = 0;
    }
    if(i>3000){
        i = 3000; 
    }
  
}

void checkEXP(int &i){
    if(i<0){
        i=0;
    }
    if(i>600){
        i=600;
    }
   
}

void checkHP(int &i){
    if (i<0){
        i=0;
    }
    if(i>666){
        i=666;
    }

}




int firstMeet(int &exp1, int &exp2, int e1) {
   if((e1<0)||(e1>99)){
        return -99;
    }
    else{
    checkEXP(exp1);
    checkEXP(exp2);

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
                exp2 += 29 + 45 + 75;
                break;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            float a =exp1 + D / 200.0;
            exp1 = ceil(a);
        } else {
            float a=exp1 - D / 100.0;
            exp1 = ceil(a);
        }
    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 <= 19 && e1 >= 4) {
            float a=exp2+(e1 / 4.0) + 19;
            exp2 = ceil(a);
        }
        if (e1 <= 49 && e1 >= 20) {
             float a = exp2+ (e1 / 9.0) + 21;
            exp2 = ceil(a);
           
        }
        if (e1 <= 65 && e1 >= 50) {
            float a= exp2+(e1 / 16.0) + 17;
            exp2 = ceil(a);
        }
        if (e1 <= 79 && e1 >= 66) {
            float a= exp2+(e1 / 4.0) + 19;
            exp2 = ceil(a);
            if (exp2 > 200) {
                float a = exp2+(e1 / 9.0) + 21;
                exp2 = ceil(a);
            }
        }
        if (e1 <= 99 && e1 >= 80) {
            float a= exp2+(e1 / 4.0) + 19;
            exp2 = ceil(a);
            float b= exp2+(e1 / 9.0) + 21;
            exp2 = ceil(b);
            if (exp2 > 400) {
                float a=exp2+(e1 / 16.0) + 17;
                exp2 = ceil(a);
                float b=exp2+0.15 * exp2;
                exp2 = ceil(b);
            }
        }
        exp1 =exp1- e1;
    }
    checkEXP(exp1);
    checkEXP(exp2);
    return exp1 + exp2;}
}

double xacsuatP(int &EXP1){
    double a = sqrt(EXP1);
    int S,c;
    float P;
    float b =floor(a) + 0.50;
    if (a >= b) {
        c = ceil(a);
        
    }
    else {
        c = floor(a);
    }
    S= c*c;

    if (EXP1 >= S) {
        P = 1;
    }
    else {
        P = ((EXP1 / (S * 1.0)) + 80) / 123.0;
    }
    return P;
}

void SK1(int &HP1, int &M1){
    if (HP1 < 200) {
        float a= 0.3 * HP1+ HP1;
        HP1= ceil(a);
        M1 -= 150;
    }
    else {
        float a=0.1 * HP1 + HP1;
        HP1 = ceil(a);
        M1 -= 70;
    }
    checkHP(HP1);
    checkM(M1);
}

void SK2(int &EXP1, int &M1){
    if (EXP1 < 400) {
        M1 -= 200;
    }
    else {
        M1 -= 120;
    }
    float a= 0.13 * EXP1 + EXP1;
    EXP1 = ceil(a);
     checkM(M1);
    checkEXP(EXP1);
}
void SK3(int &EXP1, int &M1){
    if (EXP1 < 300) {
        M1 -= 100;
    }
    else {
        M1 -= 120;
    }
    float a= EXP1- 0.1 * EXP1;
    EXP1 = ceil(a);
   
    checkM(M1);
    checkEXP(EXP1);
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
    if((E2<0)||(E2>99)){
        return -99;
    }
    else{
    int N = M1;
    double P1 = xacsuatP(EXP1);
    
    
    if (E2 % 2 != 0) {
        while (true) {
            SK1(HP1,M1);
            if (0.5 * N > M1) {
                break;
            }
            SK2(EXP1,M1);
            if (0.5 * N > M1) {
                break;}
            SK3(EXP1,M1);
            if (0.5 * N > M1) {
                break;}
           
        }
        float a=HP1-0.17 * HP1;
        HP1 = ceil(a);
        float b=EXP1 + 0.17 * EXP1;
        EXP1 = ceil(b);
        checkHP(HP1);
        checkEXP(EXP1);
    }
    if (E2 % 2 == 0) {
       for(int i =0; i<1;i++) {
        SK1(HP1,M1);
            if (M1<=0) {
                 break;
            }
            SK2(EXP1,M1);
            if (M1<=0) {
                break;}
            SK3(EXP1,M1);
            if (M1<=0) {
                break;}
        
    }
    float a = HP1 - 0.17 * HP1;
    HP1 = ceil(a);
    float b =EXP1 + 0.17 * EXP1;
        EXP1 = ceil(b);
        checkHP(HP1);
        checkEXP(EXP1);
    }
    float P2= xacsuatP(EXP1);
   int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
int i;
if (E2 < 10) {
    i = E2;
} else {
    int sum = (E2 / 10) + (E2 % 10);
    i = sum % 10;
}
int P3 = P[i];
double Plast;
if (P1 == 1.0 && P2 == 1.0 && P3 == 100) {
    float a= EXP1 - 0.25 * EXP1;
    EXP1 = ceil(a);
} else {
    Plast = (P1 + P2 + P3 / 100.0) / 3.0; 
    if (Plast < 0.5) {
        float a= HP1-0.15 * HP1;
            HP1 = ceil(a);
        float b =EXP1+0.15 * EXP1;
            EXP1 = ceil(b);
        }
        else {
            float a= HP1- 0.1 * HP1;
            HP1 = ceil(a);
            float b=EXP1+0.2 * EXP1;
            EXP1 = ceil(b);
        }
    }
    checkEXP(EXP1);
    checkHP(HP1);
    return HP1 + EXP1 + M1;}
}





// Task 3


int MaxOnDiagonal(int (&matrix)[MATRIX_SIZE][MATRIX_SIZE], int row, int col) {
    // Tính giá trị lớn nhất trên đường chéo chính
    int maxOnMainDiagonal = matrix[row][col];
    int maxOnSecondaryDiagonal = matrix[row][col];

    // Duyệt từ vị trí trở về phía trên và bên trái trên đường chéo chính
    for (int i = 1; row - i >= 0 && col - i >= 0; ++i) {
        if (matrix[row - i][col - i] > maxOnMainDiagonal) {
            maxOnMainDiagonal = matrix[row - i][col - i];
        }
    }

    // Duyệt từ vị trí trở về phía dưới và bên phải trên đường chéo chính
    for (int i = 1; row + i < MATRIX_SIZE && col + i < MATRIX_SIZE; ++i) {
        if (matrix[row + i][col + i] > maxOnMainDiagonal) {
            maxOnMainDiagonal = matrix[row + i][col + i];
        }
    }

    // Tính giá trị lớn nhất trên đường chéo phụ
    // Duyệt từ vị trí trở về phía trên và bên phải trên đường chéo phụ
    for (int i = 1; row - i >= 0 && col + i < MATRIX_SIZE; ++i) {
        if (matrix[row - i][col + i] > maxOnSecondaryDiagonal) {
            maxOnSecondaryDiagonal = matrix[row - i][col + i];
        }
    }

    // Duyệt từ vị trí trở về phía dưới và bên trái trên đường chéo phụ
    for (int i = 1; row + i < MATRIX_SIZE && col - i >= 0; ++i) {
        if (matrix[row + i][col - i] > maxOnSecondaryDiagonal) {
            maxOnSecondaryDiagonal = matrix[row + i][col - i];
        }
    }

    // Trả về giá trị lớn nhất của hai đường chéo
    return max(maxOnMainDiagonal, maxOnSecondaryDiagonal);
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    if((E3<0)||(E3>99)){
        return -99;
    }
    else{
    int taxi_map[MATRIX_SIZE][MATRIX_SIZE] = {0};
    int sw_map[MATRIX_SIZE][MATRIX_SIZE] = {0};
    
    // Tính điểm số của chiếc taxi tại mỗi vị trí trên bản đồ
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            taxi_map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // Tính điểm số của Sherlock và Watson tại mỗi vị trí trên bản đồ
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            // Tính điểm số của Sherlock và Watson dựa trên hàm MaxOnDiagonal
            sw_map[i][j] = abs(MaxOnDiagonal(taxi_map, i, j));
        }
    }

    int meeting_point_i = 0, meeting_point_j = 0;
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            if(taxi_map[i][j] > E3 * 2) {
                meeting_point_i = meeting_point_i + 1;
            }
        }
    }

    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            if(taxi_map[i][j] < -E3) {
                meeting_point_j = meeting_point_j + 1;
            }
        }
    }
    
    while (meeting_point_i >= 10) {
        int sum_i = 0, sum_j = 0;
        while (meeting_point_i > 0) {
            sum_i += meeting_point_i % 10;
            meeting_point_i /= 10;
        }
        while (meeting_point_j > 0) {
            sum_j += meeting_point_j % 10;
            meeting_point_j /= 10;
        }
        meeting_point_i = sum_i;
        meeting_point_j = sum_j;
    }
    
    int max;
    float a= EXP1*0.88;
    float b=HP1*0.9;
    float c=EXP2*0.88;
    float d=HP2*0.9;
    float A=1.12*EXP1;
    float B=1.1*HP1;
    float C=1.12*EXP2;
    float D=1.1*HP2;
    if (abs(taxi_map[meeting_point_i][meeting_point_j]) > sw_map[meeting_point_i][meeting_point_j]) {
        EXP1 = ceil(a);
        HP1 = ceil(b);
        EXP2 = ceil(c);
        HP2 = ceil(d);
        max = taxi_map[meeting_point_i][meeting_point_j];
    } else {
        EXP1 = ceil(A);
        HP1 = ceil(B);
        EXP2 = ceil(C);
        HP2 = ceil(D);
        max = sw_map[meeting_point_i][meeting_point_j];
    }

 

        // Kiểm tra và cập nhật EXP và HP
        checkEXP(EXP1);
        checkEXP(EXP2);
        checkHP(HP1);
        checkHP(HP2);
        // Trả về điểm số của Sherlock và Watson
        return max;}
}



// Task 4
int checkPassword(const char *s, const char *email) {
    // Tính toán vị trí của chuỗi 'se'
    size_t posSe = strchr(email, '@') - email;
    char se[posSe + 1];
    strncpy(se, email, posSe);
    se[posSe] = '\0';

    // Kiểm tra độ dài của chuỗi
    size_t len = strlen(s);
    if (len < 8) return -1; // Độ dài ngắn hơn tối thiểu
    if (len > 20) return -2; // Độ dài dài hơn tối đa

    // Kiểm tra s có chứa chuỗi 'se' hay không
    const char *foundSe = strstr(s, se);
    if (foundSe != nullptr) return -(300 + (foundSe - s));

    // Kiểm tra s có chứa nhiều hơn 2 ký tự liên tiếp và giống nhau hay không
    for (size_t i = 0; i < len - 2; ++i) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) return -(400 + i);
    }

    // Kiểm tra s có chứa ít nhất một ký tự đặc biệt
    bool hasSpecialChar = false;
    for (const char *c = s; *c != '\0'; ++c) {
        if (*c == '@' || *c == '#' || *c == '%' || *c == '$' || *c == '!') {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) return -5; // Không chứa ký tự đặc biệt

    // Kiểm tra từng ký tự của s
    for (size_t i = 0; i < len; ++i) {
        char c = s[i];
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
              (c == '@' || c == '#' || c == '%' || c == '$' || c == '!'))) {
            return i; // Trả về vị trí của ký tự vi phạm yêu cầu hợp lệ
        }
    }

    return -10; // Mật khẩu hợp lệ
}
   


// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    // Tạo một mảng để lưu số lần xuất hiện của từng mật khẩu
    int* passwordCounts = new int[num_pwds];
    memset(passwordCounts, 0, sizeof(int) * num_pwds);

    // Đếm số lần xuất hiện của mỗi mật khẩu trong mảng
    for (int i = 0; i < num_pwds; ++i) {
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                passwordCounts[i]++;
            }
        }
    }

    // Tìm mật khẩu có số lần xuất hiện nhiều nhất và có độ dài dài nhất
    int maxCount = 0;
    int maxLength = 0;
    int correctIndex = -1;
    for (int i = 0; i < num_pwds; ++i) {
        if (passwordCounts[i] > maxCount || (passwordCounts[i] == maxCount && strlen(arr_pwds[i]) > maxLength)) {
            maxCount = passwordCounts[i];
            maxLength = strlen(arr_pwds[i]);
            correctIndex = i;
        }
    }

    delete[] passwordCounts;

    return correctIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////