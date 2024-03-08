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
    int& E3
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
// Hàm để kiểm tra và đặt lại giá trị của biến HP (sức khoẻ)
void checkAndResetHP(int& HP) {
    if (HP > 666) 
    {
        HP = 666;
    }
    else if (HP < 0) {
        HP = 0;
    }
}

// Hàm để kiểm tra và đặt lại giá trị của biến EXP (kinh nghiệm)
void checkAndResetEXP(int& EXP) {
    if (EXP > 600) 
    {
        EXP = 600;
    }
    else if (EXP < 0) 
    {
        EXP = 0;
    }
}

// Hàm để kiểm tra và đặt lại giá trị của biến M (số tiền
void checkAndResetMoney(int& M) {
    if (M > 3000) 
    {
        M = 3000;
    }
    else if (M < 0) 
    {
        M = 0;
    }

}



// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function

// Kiểm tra xem số liệu nhập có hợp lý hay không
checkAndResetEXP(exp1);
checkAndResetEXP(exp2);

////////// Trường hợp 1
    if (e1 == 0)
    {

        exp2 += 29;
        checkAndResetEXP(exp2);
        checkAndResetEXP(exp1);
        int D = e1 * 3 + exp1 * 7;

        if (D % 2 == 0)
        {
            ///nếu D là số chẵn
            exp1 = ceil(exp1 + static_cast<float>(D) / 200);
            checkAndResetEXP(exp1);
        }

        else
        {
            //nếu D là số lẻ
            exp1 = ceil(exp1 - static_cast<float>(D) / 100);
            checkAndResetEXP(exp1);
        }
    }

    else if (e1 == 1)
    {
        
        exp2 += 45;
        checkAndResetEXP(exp2);
        int D = e1 * 3 + exp1 * 7;

        if (D % 2 == 0)
        {
            ///nếu D là số chẵn
            exp1 = ceil(exp1 + static_cast<float>(D) / 200);
            checkAndResetEXP(exp1);
        }

        else
        {
           //nếu D là số lẻ
            exp1 = ceil(exp1 - static_cast<float>(D) / 100);
            checkAndResetEXP(exp1);
        }
    }

    else if (e1 == 2)
    {

        exp2 += 75;
        checkAndResetEXP(exp2);
        int D = e1 * 3 + exp1 * 7;

        if (D % 2 == 0)
        {
            //nếu D là số chẵn
            exp1 = ceil(exp1 + static_cast<float>(D) / 200);
            checkAndResetEXP(exp1);
        }

        else
        {
            //nếu D là số lẻ
            exp1 = ceil(exp1 - static_cast<float>(D) / 100);
            checkAndResetEXP(exp1);
        }
    }

    else if (e1 == 3)
    {

        exp2 += 29 + 45 + 75;
        checkAndResetEXP(exp2);
        int D = e1 * 3 + exp1 * 7;

        if (D % 2 == 0)
        {
             //nếu D là số chẵn
            exp1 = ceil(exp1 + static_cast<float>(D) / 200);
            checkAndResetEXP(exp1);
        }

        else
        {
            //nếu D là số lẻ
            exp1 = ceil(exp1 - static_cast<float>(D) / 100);
            checkAndResetEXP(exp1);
        }
    }

/// trường hợp 2
    else if (e1 >= 4 && e1 <= 19)
    {

        exp2 += ceil((static_cast<float>(e1) / 4 + 19));
        checkAndResetEXP(exp2);
    }

    else if (e1 >= 20 && e1 <= 49)
    {

        exp2 += ceil((static_cast<float>(e1) / 9 + 21));
        checkAndResetEXP(exp2);
    }

    else if (e1 >= 50 && e1 <= 65)
    {

        exp2 += ceil((static_cast<float>(e1) / 16 + 17));
        checkAndResetEXP(exp2);
    }

    else if (e1 >= 66 && e1 <= 79)
    {

        exp2 += ceil((static_cast<float>(e1) / 4 + 19));
        checkAndResetEXP(exp2);

        // kiểm tra xem exp của Watson có lớn hơn 200 không
        if (exp2 > 200)
        {

            exp2 += ceil((static_cast<float>(e1) / 9 + 21));
            checkAndResetEXP(exp2);
        }
    }

    else if (e1 >= 80 && e1 <= 99)
    {

        exp2 += ceil((static_cast<float>(e1) / 4 + 19));
        exp2 += ceil((static_cast<float>(e1) / 9 + 21));
        checkAndResetEXP(exp2);

        /// kiểm tra xem exp của Watson có lớn hơn 400 không
        if (exp2 > 400)
        {

            exp2 += ceil((static_cast<float>(e1) / 16 + 17));
            checkAndResetEXP(exp2);
            // Watson được nhận thêm 15% exp đang có vì nghe cả 3 thông tin
            exp2 += ceil((static_cast<float>(exp2) * 0.15));
            checkAndResetEXP(exp2);
        }
    }
   // Cập nhật exp của Sherlock khi biết mình nhầm Watson có một người anh

    if (e1 >= 4 && e1 <= 99)
    {
        exp1 -= ceil(static_cast<float>(e1));
        checkAndResetEXP(exp1);
    }

    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }
    return exp1 + exp2;
}


// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
    float P1;
    //TODO: implement task
    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }
    checkAndResetEXP(EXP1);
    checkAndResetMoney(M1);

    //con đường 1
    double a = sqrt(EXP1);
    double S = round(a) * round(a);

    if (EXP1 >= S)
    {
        P1 = 100;
    }

    else
    {
        P1 = ((static_cast<float>(EXP1) / S + 80) / 123) * 100;
    }

    //Con đường 2
    // Khai báo tổng tiền đã trả và tiền ban đầu
    int TotalM = 0;
    int StartM = ceil(static_cast<float>(M1) * 0.5);
    if (E2 % 2 != 0)
    {

        while (TotalM <= StartM)
        {   
            /// Con đường 1
            if (HP1 < 200  && TotalM <= StartM)
            {
                HP1 = ceil((static_cast<float>(HP1) + (static_cast<float>(HP1) * 0.3)) * 0.99999);

                checkAndResetHP(HP1);
                M1 -= 150;
                checkAndResetMoney(M1);
                TotalM += 150;
            }

            else if (HP1 >= 200  && TotalM <= StartM)
            {
                HP1 = ceil((static_cast<float>(HP1) + (static_cast<float>(HP1) * 0.1)) * 0.99999);
                checkAndResetHP(HP1);
                M1 -= 70;
                checkAndResetMoney(M1);
                TotalM += 70;
            }
            checkAndResetMoney(M1);
            checkAndResetEXP(EXP1);

            /// Con đường 2
            if (EXP1 < 400  && TotalM <= StartM)
            {
                M1 -= 200;
                checkAndResetMoney(M1);
                TotalM += 200;
                EXP1 = ceil((static_cast<float>(EXP1) + (static_cast<float>(EXP1) * 0.13)) * 0.99999);
            }

            else if (EXP1 >= 400  && TotalM <= StartM)
            {
                M1 -= 120;
                checkAndResetMoney(M1);
                TotalM += 120;
                EXP1 = ceil((static_cast<float>(EXP1) + (static_cast<float>(EXP1) * 0.13)) * 0.99999);
                checkAndResetEXP(EXP1);
            }

            checkAndResetMoney(M1);
            checkAndResetEXP(EXP1);
            
            /// Con đường 3
            if (EXP1 < 300  && TotalM <= StartM)
            {
                M1 -= 100;
                checkAndResetMoney(M1);
                TotalM += 100;
                EXP1 = ceil((static_cast<float>(EXP1) - (static_cast<float>(EXP1) * 0.1)) * 0.99999);
                checkAndResetEXP(EXP1);
            }

            else if (EXP1 >= 300  && TotalM <= StartM)
            {
                M1 -= 120;
                checkAndResetMoney(M1);
                TotalM += 120;
                EXP1 = ceil((static_cast<float>(EXP1) - (static_cast<float>(EXP1) * 0.1)) * 0.99999);
                checkAndResetEXP(EXP1);
            }

        }
        HP1 = ceil((static_cast<float>(HP1) - (static_cast<float>(HP1) * 0.17)) * 0.99999);
        checkAndResetHP(HP1);
        EXP1 = ceil((static_cast<float>(EXP1) + (static_cast<float>(EXP1) * 0.17)) * 0.99999);
        checkAndResetEXP(EXP1);

    }

    else
    {
        /// Con đường 1
        if (HP1 < 200 && M1 > 0)
        {
            HP1 = ceil((static_cast<float>(HP1) + (static_cast<float>(HP1) * 0.3)) * 0.99999);
            checkAndResetHP(HP1);
            M1 -= 150;
            checkAndResetMoney(M1);
            TotalM += 150;
        }

        else if (HP1 >= 200 && M1 > 0)
        {
            HP1 = ceil((static_cast<float>(HP1) + (static_cast<float>(HP1) * 0.1)) * 0.99999);
            checkAndResetHP(HP1);
            M1 -= 70;
            checkAndResetMoney(M1);
            TotalM += 70;
        }
        checkAndResetMoney(M1);
        checkAndResetEXP(EXP1);

        /// Con đường 2
        if (EXP1 < 400 && M1 > 0)
        {
            M1 -= 200;
            checkAndResetMoney(M1);
            TotalM += 200;
            EXP1 = ceil((static_cast<float>(EXP1) + (static_cast<float>(EXP1) * 0.13)) * 0.99999);
        }

        else if (EXP1 >= 400 && M1 > 0)
        {
            M1 -= 120;
            checkAndResetMoney(M1);
            TotalM += 120;
            EXP1 = ceil((static_cast<float>(EXP1) + (static_cast<float>(EXP1) * 0.13)) * 0.99999);
            checkAndResetEXP(EXP1);
        }
        checkAndResetMoney(M1);
        checkAndResetEXP(EXP1);

        /// Con đường 3
        if (EXP1 < 300 && M1 > 0)
        {
            M1 -= 100;
            checkAndResetMoney(M1);
            TotalM += 100;
            EXP1 = ceil((static_cast<float>(EXP1) - (static_cast<float>(EXP1) * 0.1)) * 0.99999);
            checkAndResetEXP(EXP1);
        }

        else if (EXP1 >= 300 && M1 > 0)
        {
            M1 -= 120;
            checkAndResetMoney(M1);
            TotalM += 120;
            EXP1 = ceil((static_cast<float>(EXP1) - (static_cast<float>(EXP1) * 0.1)) * 0.99999);
            checkAndResetEXP(EXP1);
        }
        HP1 = ceil((static_cast<float>(HP1) - (static_cast<float>(HP1) * 0.17)) * 0.99999);
        checkAndResetHP(HP1);
        EXP1 = ceil((static_cast<float>(EXP1) + (static_cast<float>(EXP1) * 0.17)) * 0.99999);
        checkAndResetEXP(EXP1);
    }

    float P2;
    a = sqrt(EXP1);
    S = round(a) * round(a);

    if (EXP1 >= S)
    {
        P2 = 100;
    }

    else
    {
        P2 = ((static_cast<float>(EXP1) / S + 80) / 123) * 100;
    }

    // Con đường 3
    float P4[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i;

    if (E2 < 10)
    {
        i = E2;
    }

    if (E2 >= 10 && E2 <= 99)
    {
        int sumDigits = (E2 / 10) + (E2 % 10);
        i = sumDigits % 10;
    }

    float P3;
    P3 = P4[i]; 
    float GTTB = (P1 + P2 + P3) / 3;

    // Nếu cả 3 con đường có xác suất là 100%
    if (GTTB == 100.0)
    {
        EXP1 = ceil((static_cast<float>(EXP1) - (static_cast<float>(EXP1) * 0.25)) * 0.99999);
        checkAndResetEXP(EXP1);
    }

    else
    {
        // Nếu GTTB < 50%
        if (GTTB < 50.0)
        {
            HP1 = ceil((static_cast<float>(HP1) - (static_cast<float>(HP1) * 0.15)) * 0.99999);
            checkAndResetHP(HP1);
            checkAndResetHP(HP1);
            EXP1 = EXP1 = ceil((static_cast<float>(EXP1) + (static_cast<float>(EXP1) * 0.15)) * 0.99999);
            checkAndResetEXP(EXP1);
        }

        // Nếu GTTB >= 50%
        if (GTTB >= 50.0)
        {
            
            HP1 = ceil((static_cast<float>(HP1) - (static_cast<float>(HP1) * 0.1)) * 0.99999);
            checkAndResetHP(HP1);
            EXP1 = EXP1 = ceil((static_cast<float>(EXP1) + (static_cast<float>(EXP1) * 0.2)) * 0.99999);
            checkAndResetEXP(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
// Khởi tạo ma trận
const int MATRIX_SIZE = 10;

// Hàm tính vị trí gặp nhau (i, j) của xe taxi với Sherlock và Watson
void calculateMeetingPosition(int &i, int &j, int taxiMatrix[MATRIX_SIZE][MATRIX_SIZE], int E3) {
   

// Đếm số giá trị dương và âm trong ma trận
int positiveCount = 0;
int negativeCount = 0;

for (int i = 0; i < MATRIX_SIZE; ++i) 
    {
        for (int j = 0; j < MATRIX_SIZE; ++j) 
        {
            if (taxiMatrix[i][j] > E3 * 2) 
            {
                ++positiveCount;
            }

            if (taxiMatrix[i][j] < -E3) 
            {
                ++negativeCount;
            }
        }
    }

// Tính toán i và j từ số giá trị dương và âm
i = positiveCount;
j = negativeCount;

// Cộng 02 chữ số của i lại cho đến khi tổng chỉ còn 1 chữ số
while (i >= 10) 
    {
        int tempSum = 0;
        while (i > 0) 
        {
            tempSum += i % 10;
            i /= 10;
        }
        i = tempSum;
    }

    // Cộng 02 chữ số của j lại cho đến khi tổng chỉ còn 1 chữ số
while (j >= 10) 
    {
        int tempSum = 0;
        while (j > 0) 
        {
            tempSum += j % 10;
            j /= 10;
        }
        j = tempSum;
    }
}
//// Tính toán ma trận của Sherlock và Watson
int findMaxScoreAtIntersection(int taxiMatrix[MATRIX_SIZE][MATRIX_SIZE], int i, int j) {
    // Tính toán đường chéo trái
    int leftDiagonal = 0;
    for (int x = i, y = j; x >= 0 && y >= 0; --x, --y) 
    {
        leftDiagonal = std::max(leftDiagonal, taxiMatrix[x][y]);
    }

    // Tính toán đường chéo phải
    int rightDiagonal = 0;
    for (int x = i, y = j; x < MATRIX_SIZE && y >= 0; ++x, --y) 
    {
        rightDiagonal = std::max(rightDiagonal, taxiMatrix[x][y]);
    }

    // Lấy giá trị lớn nhất trên cả hai đường chéo và lấy giá trị tuyệt đối
    int score = std::max(std::abs(leftDiagonal), std::abs(rightDiagonal));

    return score;
}

int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3)
{
    //TODO: implement task
    if (E3 < 0 || E3 > 99)
        {
            return -99;
        }
    int taxiMatrix[MATRIX_SIZE][MATRIX_SIZE];
    int SherlockWatsonMatrix[MATRIX_SIZE][MATRIX_SIZE];
    int i_meet;
    int j_meet;
    int result;

    // Khởi tạo ma trận của taxi
    for (int i = 0; i < MATRIX_SIZE; ++i) 
        {
            for (int j = 0; j < MATRIX_SIZE; ++j) 
            {
                taxiMatrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        } 
    calculateMeetingPosition(i_meet, j_meet, taxiMatrix, E3);
    int maxscore = findMaxScoreAtIntersection(taxiMatrix,i_meet, j_meet);
    if (abs(taxiMatrix[i_meet][j_meet]) > maxscore)
        {
            EXP1 = ceil(EXP1 * 0.88 * 0.9999999);
            EXP2 = ceil(EXP2 * 0.88 * 0.9999999);
            HP1 = ceil(HP1 * 0.9 * 0.9999999);
            HP2 = ceil(HP2 * 0.9 * 0.9999999);
            result = taxiMatrix[i_meet][j_meet];
        }
    if (abs(taxiMatrix[i_meet][j_meet]) <= maxscore)
        {
            EXP1 = ceil(EXP1 * 1.12* 0.9999999);
            EXP2 = ceil(EXP2 * 1.12 * 0.9999999);
            HP1 = ceil(HP1 * 1.1 * 0.9999999);
            HP2 = ceil(HP2 * 1.1 * 0.9999999);
            result = maxscore;       
        }
    checkAndResetEXP(EXP1);
    checkAndResetEXP(EXP2);
    checkAndResetHP(HP1);
    checkAndResetHP(HP2);
    return result;
}

// Task 4
int checkPassword(const char* s, const char* email)
{
    //TODO: implement task
    // Kiểm tra độ dài của mật khẩu
    int pass_length = 0;
    while (s[pass_length] != '\0') 
    {
        pass_length++;
    }

    if (pass_length < 8) 
    {
        return -1;
    } 
    else if (pass_length > 20) 
    {
        return -2;
    }

    // Kiểm tra chuỗi se
    int se_detect = 0;
    while (email[se_detect] != '@') 
    {
        se_detect++;
    }

    char se[se_detect + 1];
    for (int i = 0; i < se_detect; i++) 
    {
        se[i] = email[i];
    }
    se[se_detect] = '\0';
    int se_position = -1;
    for (int i = 0; s[i] != '\0'; i++) 
    {
        if (strncmp(&s[i], se, se_detect) == 0) 
        {
            se_position = i;
            break;
        }
    }

    if (se_position != -1) 
    {
        return -(300 + se_position);
    }

    // Kiểm tra ký tự đặc biệt
    const char special_characters[] = "@#%$!";
    int special_found = 0;
    for (int i = 0; s[i] != '\0'; i++) 
    {
        if (strchr(special_characters, s[i]) != nullptr) 
        {
            special_found = 1;
            break;
        }
    }

    if (!special_found) 
    {
        return -5;
    }

    // Kiểm tra nhiều hơn 2 ký tự liên tiếp và giống nhau
    for (int i = 0; s[i + 2] != '\0'; i++) 
    {
        if (s[i] == s[i+1] && s[i] == s[i+2]) 
        {
            return -(400 + i);
        }
    }

    return -10;  // Trả về -10 nếu mật khẩu hợp lệ
}
    

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds)
{
      //TODO: implement task
    // Nếu không có mật khẩu, trả về -1
    if (num_pwds == 0) 
    {
        return -1;
    }

    // Sử dụng một mảng để lưu số lần xuất hiện của mỗi mật khẩu
    int* password_count = new int[num_pwds](); // Khởi tạo mảng giá trị 0

    // Sử dụng một mảng để lưu độ dài của mỗi mật khẩu
    int* password_length = new int[num_pwds];

    // Duyệt qua mảng mật khẩu để đếm số lần xuất hiện và lưu độ dài
    for (int i = 0; i < num_pwds; ++i) 
    {
        password_length[i] = std::strlen(arr_pwds[i]);

        // Duyệt qua mảng để kiểm tra số lần xuất hiện của mật khẩu i trong mảng
        for (int j = 0; j < num_pwds; ++j) 
        {
            if (i != j && std::strcmp(arr_pwds[i], arr_pwds[j]) == 0) 
            {
                ++password_count[i];
            }
        }
    }

    // Tìm mật khẩu có số lần xuất hiện nhiều nhất và có độ dài lớn nhất
    int max_appeareance = 0;
    int max_length = 0;
    int correct_password = 0;

    for (int i = 0; i < num_pwds; ++i) 
    {
        if (password_count[i] >  max_appeareance || (password_count[i] ==  max_appeareance && password_length[i] > max_length)) 
        {
             max_appeareance = password_count[i];
            max_length = password_length[i];
            correct_password = i;
        }
    }

    // Giải phóng bộ nhớ đã cấp phát
    delete[] password_count;
    delete[] password_length;

    return correct_password;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////

   