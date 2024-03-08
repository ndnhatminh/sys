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
//check funtion 
//Check variable function
int checkHP(double HP) {
    int roundedHP = ceil(HP);
    if (roundedHP > 666) {
        return 666;
    } else if (roundedHP < 0) {
        return 0;
    } else {
        return roundedHP;
    }
}

int checkEXP(double EXP) {
    int roundedEXP = ceil(EXP);
    if (roundedEXP > 600) {
        return 600;
    } else if (roundedEXP < 0) {
        return 0;
    } else {
        return roundedEXP;
    }
}

int checkMoney(double M) {
    int roundedM = ceil(M);
    if (roundedM > 3000) {
        return 3000;
    } else if (roundedM < 0) {
        return 0;
    } else {
        return roundedM;
    }
}

int checkEvent(int E) {
    if (E < 0 || E > 99) {
        return -99;
    } else {
        return E;
    }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    e1 = checkEvent(e1);
    if (e1 == -99){
        return -99;
    }
    else {
        // TODO: Complete this function
        exp1 = checkEXP(exp1);
        exp2 = checkEXP(exp2);
        if(e1>=0 && e1<=3){
            if(e1==0){ 
                exp2 = checkEXP(exp2 + 29);
            }
            else if(e1==1){
                exp2 = checkEXP(exp2 + 45);
            }
            else if(e1==2){
                exp2 = checkEXP(exp2 + 75);
            }
            else if(e1==3){
                exp2 = checkEXP(exp2 + 149);
            }
            int D = e1*3 + exp1*7;
            if(D%2==0){
                exp1 = checkEXP(exp1 + D/double(200));
            }
            else{
                exp1 = checkEXP(exp1 - D/double(100));
            }
        }
        else if(e1>=4 && e1<=99){
            if (e1>=4 && e1<=19){
                exp2 = checkEXP(exp2 + e1/double(4) + 19);
            }
            else if(e1>=20 && e1<=49){
                exp2 = checkEXP(exp2 + e1/double(9) + 21);
            }
            else if(e1>=50 && e1<=65){
                exp2 = checkEXP(exp2 + e1/double(16) + 17);
            }
            else if(e1>=66 && e1<=79){
                exp2 = checkEXP(exp2 + e1/double(4) + 19);
                if (exp2 > 200){
                    exp2 = checkEXP(exp2 + e1/double(9) + 21);
                }
            }
            else if(e1>=80 && e1<=99){
                exp2 = checkEXP(exp2 + e1/double(4) + 19);
                exp2 = checkEXP(exp2 + e1/double(9) + 21);
                if(exp2 > 400){
                    exp2 = checkEXP(exp2 + e1/double(16) + 17);
                    exp2 = checkEXP(exp2 + (double(15)/100)*exp2);
                }
            }
            exp1 = checkEXP(exp1 - e1);
        }
        return exp1 + exp2;
    }
}

// Task 2
// With way 01
//Check perfect square
bool isPerfectSquare(int n) {
    int sqrt_n = sqrt(n);
    return sqrt_n * sqrt_n == n;
}

// Find the nearest perfect square to EXP1
int findNearestPerfectSquare(int exp1) {
    int lower = exp1 - 1;
    int upper = exp1 + 1;
    if (exp1 == 0) {
        return 0;
    }
    while (true) {
        if (isPerfectSquare(lower))
            return lower;
        else if (isPerfectSquare(upper))
            return upper;
        lower--;
        upper++;
    }
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    E2 = checkEvent(E2);
    if (E2 == -99){
        return -99;
    }
    else {
        HP1 = checkHP(HP1);
        EXP1 = checkEXP(EXP1);
        M1 = checkMoney(M1);
        // cout << "initial HP1: " << HP1 << endl;
        // cout << "initial EXP1: " << EXP1 << endl;
        // cout << "initial M1: " << M1 << endl;
        // TODO: Complete this function
        double P1, P2, P3 = 0;
        // Identify the probability P1
        int S1 = findNearestPerfectSquare(EXP1);
        // printf("S1: %d\n", S1);
        if(EXP1 >= S1){
            P1 = double(100)/100;
        }
        else {
            P1 = ((double(EXP1) / S1) + 80) / 123;
        }
        // printf("P1: %f\n", P1);
        // Identify the probability P2
        int initM = M1;
        int payM = 0;
        if(M1 >= 0) {
            if (E2 % 2 == 0){
                if (M1 == 0 ){
                    HP1 = checkHP(HP1 - (double(17)/100)*HP1);
                    EXP1 = checkEXP(EXP1 + (double(17)/100)*EXP1);
                    // cout << "M1 = 0 không trải qua sự kiện nào \n";
                }
                else{
                    //event 1
                    if(HP1 < 200){
                        HP1 = checkHP(HP1 + (double(30)/100)*HP1);
                        payM = payM + 150;
                        M1 = checkMoney(M1 - 150);
                        // cout <<"HP1 when HP1 < 200: " << HP1 << endl;
                    }
                    else {
                        HP1 = checkHP(HP1 + (double(10)/100)*HP1);
                        payM = payM + 70;
                        M1 = checkMoney(M1 - 70);        
                    }
                    if(M1 > 0){
                        //event 2
                        if(EXP1 < 400){
                            payM = payM + 200;
                            M1 = checkMoney(M1 - 200);
                            EXP1 = checkEXP(EXP1 + (double(13)/100)*EXP1);
                            // cout << "EXP1 when EXP1 < 400: " << EXP1 << endl;
                            // cout << "M1 when EXP1 < 400: " << M1 << endl;
                        }
                        else {
                            payM = payM + 120;
                            M1 = checkMoney(M1 - 120);
                            EXP1 = checkEXP(EXP1 + (double(13)/100)*EXP1);
                        }
                        if(M1 > 0){
                            //event 3
                            if(EXP1 < 300){
                                payM = payM + 100;
                                M1 = checkMoney(M1 - 100);
                                EXP1 = checkEXP(EXP1 - (double(10)/100)*EXP1);
                                // cout << "EXP1 when EXP1 < 300: " << EXP1 << endl;
                                // cout << "M1 when EXP1 < 300: " << M1 << endl;
                            }
                            else {
                                payM = payM + 120;
                                M1 = checkMoney(M1 - 120);
                                EXP1 = checkEXP(EXP1 - (double(10)/100)*EXP1);
                                // cout << "EXP1 when EXP1 >= 300: " << EXP1 << endl;
                                // cout << "M1 when EXP1 >= 300: " << M1 << endl;
                            }
                            if(M1 >= 0){
                                HP1 = checkHP(HP1 - (double(17)/100)*HP1);
                                EXP1 = checkEXP(EXP1 + (double(17)/100)*EXP1);
                                // cout << "EXP1 after event 3: " << EXP1 << endl;
                            }
                        }
                        else{
                            HP1 = checkHP(HP1 - (double(17)/100)*HP1);
                            EXP1 = checkEXP(EXP1 + (double(17)/100)*EXP1);
                            // cout << "EXP1 after event 2: " << EXP1 << endl;
                        }
                    }
                    else {
                        HP1 = checkHP(HP1 - (double(17)/100)*HP1);
                        EXP1 = checkEXP(EXP1 + (double(17)/100)*EXP1); 
                        // cout << "EXP1 after event 1: " << EXP1 << endl; 
                        // cout << "HP1 after event 1: " << HP1 << endl;                  
                    } 
                }
            }
            else { // E2 % 2 != 0
                while (E2 % 2 != 0){
                    // event 1
                    if (M1 == 0){
                        HP1 = checkHP(HP1 - (double(17)/100)*HP1);
                        EXP1 = checkEXP(EXP1 + (double(17)/100)*EXP1);
                        // cout << "M1 = 0 không trải qua sự kiện nào \n";
                        break;
                    }
                    if(HP1 < 200){
                        HP1 = checkHP(HP1 + (double(30)/100)*HP1);
                        payM = payM + 150;
                        M1 = checkMoney(M1 - 150);
                        // cout <<"HP1 when HP1 < 200 in event 1: " << HP1 << endl;
                    }
                    else {
                        HP1 = checkHP(HP1 + (double(10)/100)*HP1);
                        payM = payM + 70;
                        M1 = checkMoney(M1 - 70);   
                        // cout <<"HP1 when HP1 >= 200: " << HP1 << endl;
                        // cout <<"M1 when HP1 >= 200: " << M1 << endl;
                        // cout << "---\n";
                    }  
                    if(double(payM) > (double(50)/100)*initM){
                        HP1 = checkHP(HP1 - (double(17)/100)*HP1);
                        EXP1 = checkEXP(EXP1 + (double(17)/100)*EXP1);
                        // cout << "end event 1\n ";
                        // cout << "HP1 when payM > 50%: " << HP1 << endl;
                        // cout << "EXP1 when payM > 50%: " << EXP1 << endl;
                        break;
                    }                   
                    // event 2
                    if(EXP1 < 400){
                        payM = payM + 200;
                        M1 = checkMoney(M1 - 200);
                        EXP1 = checkEXP(EXP1 + (double(13)/100)*EXP1);
                        // cout << "EXP1 when EXP1 < 400: " << EXP1 << endl;
                        // cout << "M1 when EXP1 < 400: " << M1 << endl;
                        // cout << "---\n";
                    }
                    else {
                        payM = payM + 120;
                        M1 = checkMoney(M1 - 120);
                        EXP1 = checkEXP(EXP1 + (double(13)/100)*EXP1);
                        // cout << "M1 when EXP1 >= 400: " << M1 << endl;
                    }
                    if(double(payM) > (double(50)/100)*initM){
                        HP1 = checkHP(HP1 - (double(17)/100)*HP1);
                        EXP1 = checkEXP(EXP1 + (double(17)/100)*EXP1);
                        // cout << "HP1 when payM > 50%: " << HP1 << endl;
                        break;
                    } 
                    //event 3
                    if(EXP1 < 300){
                        payM = payM + 100;
                        M1 = checkMoney(M1 - 100);
                        EXP1 = checkEXP(EXP1 - (double(10)/100)*EXP1);
                        // cout << "EXP1 when EXP1 < 300: " << EXP1 << endl;
                        // cout << "M1 when EXP1 < 300: " << M1 << endl;
                        // cout << "payM: " << payM << endl;
                        // cout << "---\n";
                    }
                    else {
                        payM = payM + 120;
                        M1 = checkMoney(M1 - 120);
                        EXP1 = checkEXP(EXP1 - (double(10)/100)*EXP1);
                        // cout << "M1 when EXP1 >= 300: " << M1 << endl;
                    }
                    if(double(payM) > (double(50)/100)*initM){
                        HP1 = checkHP(HP1 - (double(17)/100)*HP1);
                        EXP1 = checkEXP(EXP1 + (double(17)/100)*EXP1);
                        // cout << "HP1: "<< HP1 << endl;
                        break;
                    } 
                }      
            }
        }
        int S2 = findNearestPerfectSquare(EXP1);
        if(EXP1 >= S2){
            P2 = double(100)/100;
        }
        else {
            P2 = ((double(EXP1) / S2) + 80) / 123;
        }
        // printf("P2: %f\n", P2);
        // Identify the probability P3
        int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int i = 0;
        if(checkEvent(E2) < 10){
            i = E2;
        }
        else {
            i = (E2 / 10 + E2 % 10) % 10;
        }
        // cout << "i: " << i << endl;
        P3 = P[i] / double(100);
        if(i == 4 && P1 == P2 && P2 == P3){
            EXP1 = checkEXP(EXP1 - (double(25)/100)*EXP1);
        }
        else {
            // cout << "(P1 + P2 + P3)/3: " << (P1 + P2 + P3)/3 << endl;
            if((P1 + P2 + P3)/3 < double(50)/100){
                HP1 = checkHP(HP1 - (double(15)/100)*HP1);
                EXP1 = checkEXP(EXP1 + (double(15)/100)*EXP1);
            }
            else if ((P1 + P2 + P3)/3 >= double(50)/100){
                HP1 = checkHP(HP1 - (double(10)/100)*HP1);
                EXP1 = checkEXP(EXP1 + (double(20)/100)*EXP1);
                // cout <<"HP1 when P1 + P2 + P3 >= 50: " << HP1 << endl;
                // cout <<"EXP1 when P1 + P2 + P3 >= 50: " << EXP1 << endl;
            }
        }
        // printf("P3: %f\n", P3);
        return HP1 + EXP1 + M1;
    }
}

// Task 3
int findMax(int matrix[10][10], int row, int col) {
    int max = matrix[row][col]; // Giả sử điểm cần xét cũng là phần tử lớn nhất
    int r, c;

    // Xét đường chéo chính (từ trên cùng bên trái đến dưới cùng bên phải)
    for (r = row, c = col; r < 10 && c < 10; ++r, ++c) {
        if (matrix[r][c] > max) {
            max = matrix[r][c];
        }
    }

    // Xét đường chéo phụ (từ trên cùng bên phải đến dưới cùng bên trái)
    for (r = row, c = col; r < 10 && c >= 0; ++r, --c) {
        if (matrix[r][c] > max) {
            max = matrix[r][c];
        }
    }

    return abs(max);
}
void printSherlockWatsonMatrix(int matrix[10][10]){
    // Khởi tạo ma trận mới để lưu các giá trị tìm được
    int newMatrix[10][10];

    // Duyệt qua từng cột và tìm số lớn nhất trong 2 đường chéo tại mỗi điểm trên cột đó
    for (int col = 0; col < 10; ++col) {
        for (int row = 0; row < 10; ++row) {
            newMatrix[row][col] = findMax(matrix, row, col);
        }
    }

    // In ma trận các giá trị lớn nhất ra màn hình
    // cout << "Ma tran cua Sherlock va Watson:\n";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            // cout << newMatrix[i][j] << " ";
            // cout << setw(5) << newMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
// Hàm để đếm số lượng giá trị trong ma trận lớn hơn số E3*2
int countValuesGreaterThan(int matrix[10][10], int E3) {
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (matrix[i][j] > E3 * 2) {
                count++;
            }
        }
    }
    return count;
}

// Hàm để đếm số lượng giá trị trong ma trận nhỏ hơn số -E3
int countValuesLessThan(int matrix[10][10], int E3) {
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (matrix[i][j] < - E3) {
                count++;
            }
        }
    }
    return count;
}
int sumDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    E3 = checkEvent(E3);
    if (E3 == -99){
        return -99;
    }
    else {
        HP1 = checkHP(HP1);
        EXP1 = checkEXP(EXP1);
        HP2 = checkHP(HP2);
        EXP2 = checkEXP(EXP2);
        // TODO: Complete this function
        int arr[10][10];
        // Initialize the array
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                arr[i][j] = 0;
            }
        }    
        // Fill the array TAXI
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                // cout << setw(5) << arr[i][j] << " ";
            }
        }
        int x0 = countValuesGreaterThan(arr, E3);
        // cout << "x0: " << x0 << endl;
        int y0 = countValuesLessThan(arr, E3);
        // cout << "y0: " << y0 << endl;
        while (x0 >= 10 || y0 >= 10) {
            x0 = sumDigits(x0);
            y0 = sumDigits(y0);
        }
        if(abs(arr[x0][y0]) > findMax(arr, x0, y0)){// KHÔNG đuổi kịp
            HP1 = checkHP(HP1 - (double(10)/100)*HP1);
            EXP1 = checkEXP(EXP1 - (double(12)/100)*EXP1);
            HP2 = checkHP(HP2 - (double(10)/100)*HP2);
            EXP2 = checkEXP(EXP2 - (double(12)/100)*EXP2);
            return arr[x0][y0];
        }
        else if(abs(arr[x0][y0]) <= findMax(arr, x0, y0)){ // bắt kịp khi abs(arr[x0][y0]) <= findMax(arr, x0, y0)
            HP1 = checkHP(HP1 + (double(10)/100)*HP1);
            EXP1 = checkEXP(EXP1 + (double(12)/100)*EXP1);
            HP2 = checkHP(HP2 + (double(10)/100)*HP2);
            EXP2 = checkEXP(EXP2 + (double(12)/100)*EXP2);
            return findMax(arr, x0, y0);
        }
    } 
    return -1;  
}

// Task 4
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isLowercase(char c) {
    return c >= 'a' && c <= 'z';
}

bool isUppercase(char c) {
    return c >= 'A' && c <= 'Z';
}

bool isValidSpecialChar(char c) {
    return c == '@' || c == '#' || c == '%' || c == '$' || c == '!';
}
// Hàm tìm vị trí của ký tự '@' trong chuỗi email
int findAtSymbol(const char* email) {
    int position = 0;
    while (email[position] != '\0') {
        if (email[position] == '@') {
            return position;
        }
        position++;
    }
    return -1; // Không tìm thấy ký tự '@'
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int length = strlen(s);
    // Kiểm tra độ dài của mật khẩu
    if (length < 8)
        return -1;
    if (length > 20)
        return -2;
    int atSymbolPosition = findAtSymbol(email);
    if (atSymbolPosition == -1) {
        return -1; // Không tìm thấy ký tự '@' trong email
    }

    // Tạo chuỗi se từ email
    char se[100]; // Giả sử email không quá 100 ký tự
    for (int i = 0; i < atSymbolPosition; i++) {
        se[i] = email[i];
    }
    se[atSymbolPosition] = '\0';

    // Kiểm tra xem chuỗi s có chứa chuỗi se không
    int sLength = 0;
    while (s[sLength] != '\0') {
        sLength++;
    }
    for (int i = 0; i <= sLength - atSymbolPosition; i++) {
        bool match = true;
        for (int j = 0; j < atSymbolPosition; j++) {
            if (s[i + j] != se[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return -(300 + i); // Tìm thấy chuỗi se trong s
        }
    }
    // Kiểm tra sự xuất hiện của nhiều hơn 2 ký tự liên tiếp giống nhau
    for (int i = 0; i < length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
            return -(400 + i);
    }

    // Kiểm tra sự xuất hiện của ít nhất một ký tự đặc biệt
    bool hasSpecial = false;
    for (int i = 0; i < length; ++i) {
        if (isValidSpecialChar(s[i])) {
            hasSpecial = true;
            break;
        }
    }
    if (!hasSpecial)
        return -5;

    // Kiểm tra các ký tự trong mật khẩu
    for (int i = 0; i < length; ++i) {
        char c = s[i];
        if (!(isDigit(c) || isLowercase(c) || isUppercase(c) || isValidSpecialChar(c))) {
            return i;
        }
    }
    // Trả về -10 nếu mật khẩu hợp lệ
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    // Tạo một mảng để lưu số lần xuất hiện của mỗi mật khẩu và độ dài của nó
    int counts[30] = {0};
    int lengths[30] = {0};
    const char* passwords[30] = {nullptr};

    // Tính số lần xuất hiện và độ dài của từng mật khẩu
    for (int i = 0; i < num_pwds; ++i) {
        const char* pwd = arr_pwds[i];
        int j = 0;
        while (passwords[j] != nullptr && strcmp(passwords[j], pwd) != 0) {
            ++j;
        }
        if (passwords[j] == nullptr) {
            passwords[j] = pwd;
        }
        ++counts[j];
        lengths[j] = strlen(pwd);
    }

    // Tìm mật khẩu có số lần xuất hiện nhiều nhất và độ dài dài nhất
    int max_count = 0;
    int max_length = 0;
    const char* correct_password = nullptr;
    for (int i = 0; i < 30; ++i) {
        if (passwords[i] != nullptr && (counts[i] > max_count || (counts[i] == max_count && lengths[i] > max_length))) {
            max_count = counts[i];
            max_length = lengths[i];
            correct_password = passwords[i];
        }
    }

    // Tìm vị trí của mật khẩu đúng trong mảng arr_pwds
    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(arr_pwds[i], correct_password) == 0) {
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////