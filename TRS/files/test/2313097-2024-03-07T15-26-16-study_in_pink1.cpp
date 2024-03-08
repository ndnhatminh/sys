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


// check điều kiện
/*
1. check input
2. trường hợp đặc biệt, nếu mà hp, exp hay m ko ở dạng số nguyên thì phải làm tròn lên
3. trường hợp cá biệt e ko thuộc 0 -> 99 thì return -99
*/

// Khai báo hàm void tên reset_hp với 2 tham số hp1 và hp2 


//set input

float checkHP(float HP, int min = 0, int max = 666) {
    HP =   (HP > max)? max: (HP < min)? min: HP;
    return HP;
}

float checkEXP(float EXP, int min = 0, int max = 600) {
    EXP =   (EXP > max)? max: (EXP < min)? min: EXP;
    return EXP;
}

float checkM(float M, int min = 0, int max = 3000) {
    M =   (M > max)? max: (M < min)? min: M;
    return M;
}


// ???
bool checkSquared(int n){
    float a = round(sqrt(n)) - sqrt(n);
	if (a == 0)
		return 1;
	else 
		return 0;
}


void reset_hp(int& hp1, int& hp2) {
  // Nếu hp1 > 666 hoặc hp1 < 0 thì gán giá trị cho hp1 là 666 hoặc 0
  if (hp1 > 666) {
    hp1 = 666;
  }
  else if (hp1 < 0) {
    hp1 = 0;
  }
  // Làm tương tự với hp2
  if (hp2 > 666) {
    hp2 = 666;
  }
  else if (hp2 < 0) {
    hp2 = 0;
  }
}



// Khai báo hàm void tên reset_exp với 2 tham số exp1 và exp2
void reset_exp(int& exp1, int& exp2 ) {
  // Nếu exp1 > 600 hoặc exp1 < 0 thì gán giá trị cho exp1 là 600 hoặc 0
  if (exp1 > 600) {
    exp1 = 600;
  }
  else if (exp1 < 0) {
    exp1 = 0;
  }
  // Làm tương tự với exp2
  if (exp2 > 600) {
    exp2 = 600;
  }
  else if (exp2 < 0) {
    exp2 = 0;
  }
}

// Khai báo hàm void tên reset_money với 2 tham số m1 và m2
void reset_money(int& m1, int& m2) {
  // Nếu m1 > 3000 hoặc m1 < 0 thì gán giá trị cho m1 là 3000 hoặc 0
  if (m1 > 3000) {
    m1 = 3000;
  }
  else if (m1 < 0) {
    m1 = 0;
  }
  // Làm tương tự với m2
  if (m2 > 3000) {
    m2 = 3000;
  }
  else if (m2 < 0) {
    m2 = 0;
  }
}

int lam_tron_len ( double n)
{
  int k = ceil (n);
  return k;
}



// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ( e1 > 99 || e1 < 0) // bắt buộc trong mỗi task
    return -99;

    if ( e1 <= 3 && e1 >= 0)
    { switch (e1)
    {
    case 0:
    exp2 = exp2 + 29;
    break;

    case 1:
    exp2 = exp2 + 45;
    break;

    case 2:
    exp2 = exp2 + 75;
    break;

    case 3:
    exp2 = exp2 + 149;
    break;
    
    default:
        break;
    }

    int d = e1 * 3 + exp1 * 7;
    if ( d & 1)
    {
        double exp1_le = exp1 - (double) d / 100 ;
        exp1 = lam_tron_len (exp1_le);
    }
    else 
    {
        double exp1_chan = exp1 + (double) d/ 200;
        exp1 = lam_tron_len (exp1_chan);
    }

    reset_exp (exp1,exp2); 

    }

    if ( e1 >= 4 && e1 <= 99 ) // làm tròn lên rồi mới check 
    {
      int sk1, sk2, sk3;
        
        if ( e1 % 4 != 0 )
            sk1 = e1 / 4 + 19 + 1 ;
        else 
            sk1 = e1 / 4 + 19;
        
        if ( e1 % 9 != 0 )
            sk2 = e1 / 9 + 21 + 1 ;
        else 
            sk2 = e1 / 9 + 21;
        
        if ( e1 % 16 != 0 )
            sk3 = e1 / 16 + 17 +1 ;
        else
            sk3 = e1 / 16 + 17;
        
        
        
        if ( e1 >= 4 && e1 <= 19 )
        {
            exp2 += sk1;
            reset_exp (exp1,exp2);

        }
        if ( e1 >= 20 && e1 <= 49 )
        {
            exp2 = exp2 + sk2;
            reset_exp (exp1,exp2);
            
        }
        if ( e1 >= 50 && e1 <= 65)
        {
            exp2 += sk3;
            reset_exp (exp1,exp2);

        }
        if ( e1 >= 66 && e1 <= 79 )
        {
            exp2 += sk1;
            reset_exp (exp1,exp2);

            if ( exp2 > 200 )
            exp2 += sk2;

            reset_exp (exp1,exp2);
        }
        if ( e1 >= 80 && e1 <= 99 )
        {
            exp2 += sk1 ;
            reset_exp (exp1,exp2);
            exp2 += sk2;
            reset_exp (exp1,exp2);
            if ( exp2 > 400 )
            { 
                exp2 += sk3;
                reset_exp (exp1,exp2);
                exp2 = lam_tron_len ( 1.15 * exp2 );
                reset_exp (exp1,exp2);
            }
        }
        exp1 -= e1;
        reset_exp (exp1,exp2);
    }
    return exp1 + exp2;
}

// Task 2

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int squaredLess, squaredGtr, S;
    float P1, P2, P3, P;
    float EXP1_test, HP1_test, halfM1, sumFee;
    EXP1_test = EXP1; EXP1_test = checkEXP(EXP1_test);
    HP1_test = HP1; HP1_test = checkHP(HP1_test);
    M1 = checkM(M1);
    halfM1 = 0.5* M1;
    sumFee = 0; 
    
    if (E2 < 0 || E2 > 99){
        return -99;
    }else {
        // Road 1
    

    if (EXP1 >= 576 ){
        S = 576;
    }else{
        for (int i = EXP1; i >= 0; i--){
            bool test = checkSquared(i);
            if (test == 1){
                squaredLess = i;
                break;
            }
        }
        
        for (int i = EXP1; i <= 600; i++){
            bool test = checkSquared(i);
            if (test == 1){
                squaredGtr = i;
                break;
            }
        }

        S = ((EXP1 - squaredLess) < (squaredGtr - EXP1))? squaredLess: squaredGtr;       
    }
    P1 = (EXP1 >= S) ? 1 : (((float)EXP1/S +80)/123);

    // Road 2
    if ((E2 % 2) != 0){
        if (M1 == 0){
            HP1_test *= 0.83; HP1_test = ceil(HP1_test);
            HP1_test = checkHP(HP1_test);
            EXP1_test *= 1.17; EXP1_test = ceil(EXP1_test);
            EXP1_test = checkEXP(EXP1_test); 
        }
        while (sumFee <= halfM1) {
            //su kien 1
            M1 = (HP1_test < 200) ? (M1 -150) : (M1 - 70);
            M1 = checkM(M1);
            sumFee = (HP1_test < 200) ? (sumFee + 150) : (sumFee + 70);
            HP1_test = (HP1_test < 200) ? (HP1_test * 1.3) : (HP1_test * 1.1);
            HP1_test = ceil(HP1_test); HP1_test = checkHP(HP1_test);
            
            if (sumFee > halfM1){
                HP1_test *= 0.83; HP1_test = ceil(HP1_test);
                HP1_test = checkHP(HP1_test);
                EXP1_test *= 1.17; EXP1_test = ceil(EXP1_test);
                EXP1_test = checkEXP(EXP1_test);
                break;
            }

            //su kien 2
            M1 = (EXP1_test < 400) ? (M1 - 200) : (M1 -120);
            M1 = checkM(M1);
            sumFee = (EXP1_test < 400) ? (sumFee + 200) : (sumFee + 120);
            EXP1_test *= 1.13; EXP1_test = ceil(EXP1_test);
            EXP1_test = checkEXP(EXP1_test);
            if (sumFee > halfM1){
                HP1_test *= 0.83; HP1_test = ceil(HP1_test);
                HP1_test = checkHP(HP1_test);
                EXP1_test *= 1.17; EXP1_test = ceil(EXP1_test);
                EXP1_test = checkEXP(EXP1_test);
                break;
            }

            //su kien 3
            M1 = (EXP1_test < 300) ? (M1 - 100) : (M1 - 120);
            M1 = checkM(M1);
            sumFee = (EXP1_test < 300) ? (sumFee + 100) : (sumFee + 120);
            EXP1_test *= 0.9; EXP1_test = ceil(EXP1_test);
            EXP1_test = checkEXP(EXP1_test);
            if (sumFee > halfM1){
                HP1_test *= 0.83; HP1_test = ceil(HP1_test);
                HP1_test = checkHP(HP1_test);
                EXP1_test *= 1.17; EXP1_test = ceil(EXP1_test);
                EXP1_test = checkEXP(EXP1_test);
                break;
            }
        }
    }else {
        //su kien 1
        if (M1 != 0){
            M1 = (HP1_test < 200) ? (M1 -150) : (M1 - 70);
            M1 = checkM(M1);
            HP1_test = (HP1_test < 200) ? (HP1_test * 1.3) : (HP1_test * 1.1);
            HP1_test = ceil(HP1_test); HP1_test = checkHP(HP1_test);
            
            // su kien 2
            if (M1 != 0){ 
                M1 = (EXP1_test < 400) ? (M1 - 200) : (M1 -120);
                M1 = checkM(M1);
    
                EXP1_test *= 1.13; EXP1_test = ceil(EXP1_test);
                EXP1_test = checkEXP(EXP1_test);
                // su kien 3
                if (M1 != 0){
                    M1 = (EXP1_test < 300) ? (M1 - 100) : (M1 - 120);
                    M1 = checkM(M1);            
                    EXP1_test *= 0.9; EXP1_test = ceil(EXP1_test);
                    EXP1_test = checkEXP(EXP1_test);
                    
                    HP1_test *= 0.83; HP1_test = ceil(HP1_test);
                    HP1_test = checkHP(HP1_test);
                    EXP1_test *= 1.17; EXP1_test = ceil(EXP1_test);
                    EXP1_test = checkEXP(EXP1_test);

                }else {
                    HP1_test *= 0.83; HP1_test = ceil(HP1_test);
                    HP1_test = checkHP(HP1_test);
                    EXP1_test *= 1.17; EXP1_test = ceil(EXP1_test);
                    EXP1_test = checkEXP(EXP1_test);
                }
            }else{
            HP1_test *= 0.83; HP1_test = ceil(HP1_test);
            HP1_test = checkHP(HP1_test);
            EXP1_test *= 1.17; EXP1_test = ceil(EXP1_test);
            EXP1_test = checkEXP(EXP1_test); 
            }
        }else {
            HP1_test *= 0.83; HP1_test = ceil(HP1_test);
            HP1_test = checkHP(HP1_test);
            EXP1_test *= 1.17; EXP1_test = ceil(EXP1_test);
            EXP1_test = checkEXP(EXP1_test);
        }
        
       
    }
    EXP1 = EXP1_test;
    if (EXP1 <= 4){
        S = 4;
    }else if (EXP1 >= 576 ){
        S = 576;
    }else{
        for (int i = EXP1; i >= 0; i--){
            bool test = checkSquared(i);
            if (test == 1){
                squaredLess = i;
                break;
            }
        }
        
        for (int i = EXP1; i <= 600; i++){
            bool test = checkSquared(i);
            if (test == 1){
                squaredGtr = i;
                break;
            }
        }

        S = ((EXP1 - squaredLess) < (squaredGtr - EXP1))? squaredLess: squaredGtr;       
    }
    P2 = (EXP1 >= S) ? 1 : (((float)EXP1/S +80)/123);

    // Road 3
    int Pi[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10){
        P3 = 0.01*Pi[E2];
    }else{
        int sum = E2/10 + E2%10;
        int i = sum % 10;
        P3 = 0.01*Pi[i];
    }
    if ((P1 == 1) && (P2 == 1) && (P3 == 1)){
        EXP1_test *= 0.75; EXP1_test = ceil(EXP1_test);
        EXP1_test = checkEXP(EXP1_test);
    }else{
        P = (P1 + P2 + P3) / 3;
        EXP1_test = (P < 0.5) ? (EXP1_test * 1.15) : (EXP1_test * 1.2);
        EXP1_test = ceil(EXP1_test);
        EXP1_test = checkEXP(EXP1_test);

        HP1_test = (P < 0.5) ? (HP1_test * 0.85) : (HP1_test * 0.9);
        HP1_test = ceil(HP1_test);
        HP1_test = checkHP(HP1_test);
    }
    EXP1 = ceil(EXP1_test);
    HP1 = ceil(HP1_test);

    }
    
    
    return HP1 + EXP1 + M1;
}

/* int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    return HP1 + EXP1 + M1;
}

*/

// Task 3

// Hàm tính tổng các chữ số của một số
int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Hàm xử lý số
int processNumber(int n) {
    if (n < 10) {
        return n; // Trả về chính nó nếu n < 10
    } else {
        while (n >= 10) {
            n = sumOfDigits(n); // Cộng các chữ số của n lại
        }
        return n; // Trả về kết quả
    }
}


const int SIZE = 10;

// Hàm tìm giá trị lớn nhất trong đường chéo trái và phải
int findMaxInDiagonals(int matrix[SIZE][SIZE], int row, int col) {
    int maxLeftDiagonal = matrix[row][col];
    int maxRightDiagonal = matrix[row][col];

// tìm tọa độ gốc cho đường chéo trái
int row_left_0, col_left_0;
row_left_0 = row;
col_left_0 = col;

while ( row_left_0 != 0 && col_left_0 != 0 )
{
    row_left_0 = row_left_0 - 1;
    col_left_0 = col_left_0 - 1;
}
    // Tìm giá trị lớn nhất trong đường chéo trái
maxLeftDiagonal = matrix[row_left_0][col_left_0];
    // bugs ở đây
    for (int i = 1; i < SIZE; ++i) {
        if (row_left_0 + i < SIZE && col_left_0 + i < SIZE) {
            maxLeftDiagonal = max(maxLeftDiagonal, matrix[row_left_0 + i][col_left_0 + i]);
        }
    }

// tìm gốc cho đường chéo phải
int row_right_0, col_right_0;
row_right_0 = row;
col_right_0 = col;

while ( row_right_0 != 0 && col_right_0 != SIZE - 1 )
{
    row_right_0 = row_right_0 - 1;
    col_right_0 = col_right_0 + 1;
}
maxRightDiagonal = matrix [row_right_0][col_right_0];
    // Tìm giá trị lớn nhất trong đường chéo phải
    for (int i = 1; i < SIZE; ++i) {
        if (row_right_0 + i < SIZE && col_right_0 - i >= 0) {
            maxRightDiagonal = max(maxRightDiagonal, matrix[row_right_0 + i][col_right_0 - i]);
        }
    }

    // Trả về giá trị lớn nhất trong cả hai đường chéo
    return max(maxLeftDiagonal, maxRightDiagonal);
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

if ( E3 > 99 || E3 < 0 )
{
    return -99;
}
const int rows = 10;
const int cols = 10 ;
// bước 1: tạo ma trận 10x10 -> cho tên cướp
int matrix [10][10];
// bước 2: gán giá trị cho mảng theo công thức
 // Dùng hai vòng lặp để duyệt qua các phần tử của ma trận
  for (int i = 0; i < rows; i++) {
     for (int j = 0; j < cols; j++) {
      // Tính giá trị của phần tử tại vị trí (i, j) theo công thức cho trước
      matrix[i][j] = ( E3 * j + ( 2 * i ) ) * (i - j);
    }
  }
 // bước 4: xác định tọa độ gặp nhau
 int x,y;
 x=0; // = số phần tử > e3 * 2
 y=0; // = số phần tử < - e3
 
  // Dùng hai vòng lặp để duyệt qua các phần tử của ma trận
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      // Kiểm tra nếu phần tử tại vị trí (i, j) lớn hơn e3 * 2 thì tăng x lên 1
      if (matrix[i][j] > E3 * 2) {
        x++;
      }
      // Kiểm tra nếu phần tử tại vị trí (i, j) nhỏ hơn -e3 thì tăng y lên 1
      if (matrix[i][j] < - E3) {
        y++;
      }
    }
  }
  // chỉnh cho x,y
  x = processNumber (x);
  y = processNumber (y);
 // b5: xác định xem holme có bắt được cướp không -> tìm giá trị của holes tại tọa độ xy
 int holmes_can_be_negative = findMaxInDiagonals ( matrix, x, y );

 // holmes_can_be_negative = abs (holmes_can_be_negative);
 // tạo biến giả để làm tròn
 double gan_exp1 = EXP1;
 double gan_exp2 = EXP2;
 double gan_hp1 = HP1;
 double gan_hp2 = HP2;
 
 if ( abs(holmes_can_be_negative) < abs(matrix[x][y]) )
 {
    gan_exp1 = 0.88 * gan_exp1;
    gan_exp2 = 0.88 * gan_exp2;
    gan_hp1 = 0.9 * gan_hp1;
    gan_hp2 = 0.9 * gan_hp2;
 }
 else
 {
     gan_exp1 = 1.12 * gan_exp1;
     gan_exp2 = 1.12 * gan_exp2;
     gan_hp1 = 1.1 * gan_hp1;
     gan_hp2 = 1.1 * gan_hp2;
 }
EXP1 = ceil ( (float) gan_exp1);
EXP2 = ceil (  (float)  gan_exp2);
HP1 = ceil ( (float) gan_hp1);
HP2 = ceil ( (float) gan_hp2);

EXP1= checkEXP (EXP1);
EXP2 = checkEXP (EXP2);
HP1 = checkHP(HP1);
HP2 = checkHP (HP2);

int gan = matrix[x][y];
int abs_matrix_x_y = abs ( gan );
 
if ( abs(abs_matrix_x_y) >= holmes_can_be_negative )
    return gan;
else
    return holmes_can_be_negative;
}

/* int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    return -1;
} */

// Task 4


string extractSeFromEmail(const char* email) {
    const char* atPosition = strchr(email, '@');
    if (atPosition != nullptr) {
        return string(email, atPosition - email);
    }
    return ""; // Trả về chuỗi rỗng nếu không tìm thấy ký tự @ trong email
}

int checkPassword(const char* s, const char* email) {
    // Kiểm tra độ dài của mật khẩu
    int sLength = strlen(s);
    if (sLength < 8) {
        return -1; // Độ dài ngắn hơn độ dài tối thiểu
    }
    if (sLength > 20) {
        return -2; // Độ dài dài hơn độ dài tối đa
    }
    string se = extractSeFromEmail(email);
    // Kiểm tra không chứa chuỗi "se"
    if (strstr(s, se.c_str()) != nullptr) {
        return -(300 + strstr(s, se.c_str()) - s); // Chứa chuỗi "se"
    }

    // Kiểm tra không chứa nhiều hơn 2 ký tự liên tiếp và giống nhau
    for (int i = 0; i < sLength - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i); // Chứa nhiều hơn 2 ký tự liên tiếp và giống nhau
        }
    }
   
    // Kiểm tra ký tự đặc biệt
     bool hasSpecialChar = false;
    for (int i = 0; i < sLength; ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) {
        return -5; // Không chứa ký tự đặc biệt
    }
    
    
    // Kiểm tra vị trí của ký tự đầu tiên vi phạm yêu cầu
    for (int i = 0; i < sLength; ++i) {
        if (!isalnum(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') {
            return i; // Ký tự đầu tiên vi phạm yêu cầu
        }
    }
    // Mật khẩu hợp lệ
    return -10;
}

 /* int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    return -99;
} */

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int maxCount = 0; // Số lần xuất hiện nhiều nhất
    int maxLength = 0; // Độ dài lớn nhất
    int correctIndex = -1; // Vị trí của mật khẩu đúng

    for (int i = 0; i < num_pwds; ++i) {
        const char* pwd = arr_pwds[i];
        int len = strlen(pwd);

        // Đếm số lần xuất hiện của mật khẩu
        int count = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(pwd, arr_pwds[j]) == 0) {
                ++count;
            }
        }

        // Kiểm tra điều kiện độ dài và số lần xuất hiện
        if (count > maxCount || (count == maxCount && len > maxLength)) {
            maxCount = count;
            maxLength = len;
            correctIndex = i;
        }
    }

    return correctIndex;
}


/* int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    return -1;
} */

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////