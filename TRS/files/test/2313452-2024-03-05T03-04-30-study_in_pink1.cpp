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
//CAP NHAT LAN CUOI 13:51 27/02/2024
void adjHP(int& HP1, int& HP2)
{
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (HP2 < 0) HP2 = 0;
    if (HP2 > 666) HP2 = 666;
}


void adjEXP(int& EXP1, int& EXP2)
{
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 600) EXP2 = 600;
}


void adjM(int& M1, int& M2)
{
    if (M1 < 0) M1 = 0;
    if (M1 > 3000) M1 = 3000;
    if (M2 < 0) M2 = 0;
    if (M2 > 3000) M2 = 3000;
}
int theNearestSquaredNumber(int n)
{
    int NUMSQRT = sqrt(n * 1.0);
    int A = NUMSQRT;
    int B = NUMSQRT + 1;
    int NUM_A = abs(n - A * A);
    int NUM_B = abs(n - B * B);
    if (NUM_A > NUM_B) return B * B;
    else return A * A;
}


int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;
    if (e1 <= 3)
    {
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
            exp2 += 149;
            break;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = int(exp1 + D / 200.0 + 0.9999);
        else exp1 = int(exp1 - D / 100.0 + 0.9999);

    }
    else if (e1 > 3) {
        if (e1 <= 19)
        {
            exp2 = int(exp2 + (e1 / 4.0 + 19) + 0.9999);
        }
        else if (e1 <= 49)
        {
            exp2 = int(exp2 + (e1 / 9.0 + 21) + 0.9999);
        }
        else if (e1 <= 65)
        {
            exp2 = int(exp2 + (e1 / 16.0 + 17) + 0.9999);
        }
        else if (e1 <= 79)
        {
            exp2 = int(exp2 + (e1 / 4.0 + 19) + 0.9999);
            if (exp2 > 200)
            {
                exp2 = int(exp2 + (e1 / 9.0 + 21) + 0.9999);
            }

        }
        else {
            exp2 = int(exp2 + (e1 / 4.0 + 19) + 0.9999);
            exp2 = int(exp2 + (e1 / 9.0 + 21) + 0.9999);
            if (exp2 > 400)
            {
                exp2 = int(exp2 + (e1 / 16.0 + 17) + 0.9999);
                exp2 = int(exp2 * 1.15 + 0.9999);
            }

        }
        exp1 = exp1 - e1;

    }
    adjEXP(exp1, exp2);
    return exp1 + exp2;
}
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
    int X = 0;
    //CHECK HP, EXP, M, E
    if (E2 < 0 || E2 > 99) return -99;
    adjHP(HP1, X);
    adjEXP(EXP1, X);
    adjM(M1, X);

    //ROAD 1
    float P1;
    if (theNearestSquaredNumber(EXP1) <= EXP1) P1 = 1;
    else P1 = ((1.0 * EXP1 / theNearestSquaredNumber(EXP1)) + 80) / 123;


    //ROAD 2 
    int K;
    int limitPayment = ceil(0.5 * M1);
    int payment = 0;
    if (E2 % 2 == 0) K = 0; else K = 1;
    do {
        if ((K == 1 && payment > limitPayment) || (K == 0 && M1 == 0)) break; //CHECK DIEU KIEN
        //EVENT 1
        if (HP1 < 200)
        {
            HP1 += ceil(HP1 * 30.0 / 100);
            M1 -= 150;
            payment += 150;
            adjHP(HP1, X);
            adjM(M1, X);
        }
        else
        {
            HP1 += ceil(HP1 * 10.0 / 100);
            M1 -= 70;
            payment += 70;
            adjHP(HP1, X);
            adjM(M1, X);
        }
        if ((K == 1 && payment > limitPayment) || (K == 0 && M1 == 0)) break; //CHECK DIEU KIEN
        //EVENT 2
        if (EXP1 < 400)
        {
            M1 -= 200;
            payment += 200;
            adjM(M1, X);
        }
        else
        {
            M1 -= 120;
            payment += 120;
            adjM(M1, X);
        }
        EXP1 += ceil(EXP1 * 13.0 / 100);
        adjEXP(EXP1, X);
        if ((K == 1 && payment > limitPayment) || (K == 0 && M1 == 0)) break; //CHECK DIEU KIEN
        ////EVENT 3
        if (EXP1 < 300)
        {
            M1 -= 100;
            payment += 100;
            EXP1 -= floor(EXP1 * 10.0 / 100);
            adjM(M1, X);
            adjEXP(EXP1, X);
        }
        else
        {
            M1 -= 120;
            payment += 120;
            EXP1 -= floor(EXP1 * 10.0 / 100);
            adjM(M1, X);
            adjEXP(EXP1, X);
        }
        if ((K == 1 && payment > limitPayment) || (K == 0 && M1 == 0)) break; //CHECK DIEU KIEN
    } while (K); //NEU E2 LA SO CHAN THI DUNG LAI

    //CAP NHAT HP EXP SAU KHI HET ROAD 2
    EXP1 += ceil(EXP1 * 17.0 / 100);
    adjEXP(EXP1, X);
    HP1 -= floor(HP1 * 17.0 / 100);
    adjHP(HP1, X);

    //TINH XAC SUAT P2
    float P2;
    if (theNearestSquaredNumber(EXP1) <= EXP1) P2 = 1.0;
    else P2 = ((1.0 * EXP1 / theNearestSquaredNumber(EXP1)) + 80) / 123;


    //ROAD 3
    int i;
    float P_ARRAY[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2 / 10 == 0) i = E2;
    else i = E2 / 10 + E2 % 10;
    if (i / 10 != 0) i = i % 10;
    float P3;
    P3 = 0.01 * P_ARRAY[i];
    //THE LAST CAL

    float P = (P1 + P2 + P3) / 3.0;
    if (P == 1)
    {
        EXP1 -= floor(EXP1 * 25.0 / 100);
        adjEXP(EXP1, X);
    }
    else if (P < 0.5)
    {
        HP1 -= floor(HP1 * 15.0 / 100);
        EXP1 += ceil(EXP1 * 15.0 / 100);
        adjHP(HP1, X);
        adjEXP(EXP1, X);
    }
    else
    {
        HP1 -= floor(HP1 * 10.0 / 100);
        EXP1 += ceil(EXP1 * 20.0 / 100);
        adjHP(HP1, X);
        adjEXP(EXP1, X);
    }
    return HP1 + EXP1 + M1;
}


// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    adjEXP(EXP1, EXP2);
    adjHP(HP1, HP2);

    int taxiPoint, detectivesPoint;

    /*Bảng điểm cho taxi*/
    int arr[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    /*Tìm tọa độ gặp nhau*/
    int greaterThan = 0, lessThan = 0, x, y;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] > E3 * 2) greaterThan++;
            if (arr[i][j] < -E3) lessThan++;
        }
    }
    if (greaterThan < 10) x = greaterThan;
    else {
        // num1 và num2 lần luọt là chứ số hàng chục và chữ số hàng đơn vị
        int num1 = greaterThan / 10, num2 = greaterThan % 10;
        while (num1 + num2 >= 10) {
            int temp = num1;
            num1 = (num1 + num2) / 10;
            num2 = (temp + num2) % 10;
        }
        x = num1 + num2;
    }
    if (lessThan < 10) y = lessThan;
    else {
        // num1 và num2 lần luọt là chứ số hàng chục và chữ số hàng đơn vị
        int num1 = lessThan / 10, num2 = lessThan % 10;
        while (num1 + num2 >= 10) {
            int temp = num1;
            num1 = (num1 + num2) / 10;
            num2 = (temp + num2) % 10;
        }
        y = num1 + num2;
    }
    // Ta đã có tọa độ gặp nhau là (x,y)
    taxiPoint = arr[x][y];
    int x_ = x, y_ = y;
    /*x LÀ CHỈ SÓ HÀNG, y LÀ CHỈ SỐ CỘT*/
    // Debug
    // Duyệt đường chéo trái
    if (x >= y) {
        while (y != 0) {
            y--;
            x--;
        }
        detectivesPoint = arr[x][y];
        while (x < 10 && y < 10) {
            if (arr[x + 1][y + 1] > detectivesPoint) detectivesPoint = arr[x + 1][y + 1];
            x++;
            y++;
        }
    }

    if (x <= y) {
        while (x != 0) {
            y--;
            x--;
        }
        detectivesPoint = arr[x][y];
        while (x < 10 && y < 10) {
            if (arr[x][y] > detectivesPoint) detectivesPoint = arr[x][y];
            x++;
            y++;
        }
    }
    // Duyệt đường chéo phải
     /*Duyệt từ hàng cuối*/
    if (x_ + y_ > 9) {
        // Nằm phía trên đường chéo phụ
        while (x_ != 9 && y_ >= 0) {
            x_++;
            y_--;
        }
        while (x_ >= 0 && y_ < 10) {
            if (arr[x_][y_] > detectivesPoint) detectivesPoint = arr[x_][y_];
            x_--;
            y_++;
        }
    }

    /*Duyệt từ cột đầu*/
    if (x_ + y_ < 9) {
        // Nằm phía dưới đường chéo phụ
        while (y_ != 0 && x_ < 10) {
            y_--;
            x_++;
        }
        while (x_ >= 0 && y_ < 10) {
            if (arr[x_][y_] > detectivesPoint) detectivesPoint = arr[x_][y_];
            x_--;
            y_++;
        }
    }

    /*Nếu gặp nhau tại 1 ô thuộc đường chéo phụ*/
    if (x_ + y_ == 9) {
        x_ = 9; y_ = 0;
        while (x >= 0 && y_ < 10) {
            if (arr[x_][y_] > detectivesPoint) detectivesPoint = arr[x_][y_];
            x_--;
            y_++;
        }

    }

    /*In case detectives cannot catch up the taxi*/
    if (abs(taxiPoint) > detectivesPoint) {
        EXP1 = ceil(EXP1 * 88.0 / 100);
        EXP2 = ceil(EXP2 * 88.0 / 100);
        HP1 = ceil(HP1 * 90.0 / 100);
        HP2 = ceil(HP2 * 90.0 / 100);
        adjEXP(EXP1, EXP2);
        adjHP(HP1, HP2);
        return taxiPoint;
    }

    /*In case detectives could catch up the taxi*/
    else {
        EXP1 = ceil(EXP1 * 112.0 / 100);
        EXP2 = ceil(EXP2 * 112.0 / 100);
        HP1 = ceil(HP1 * 110.0 / 100);
        HP2 = ceil(HP2 * 110.0 / 100);
        adjEXP(EXP1, EXP2);
        adjHP(HP1, HP2);
        return detectivesPoint;
    }

    return -1;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    const int maxLenEmail = 100;
    int len = 0;
    string se = "", pswd = ""; // pswd là toàn bộ chuỗi mà s đang thao tác
    /*Kiểm tra độ dài mật khẩu*/
    while (*s != '\0') {
        pswd += *s;
        len++;
        s++;
    }
    if (len < 8) return -1;
    if (len > 20) return -2;
    /*Kiểm tra tính hợp lệ của email*/
    while (*email != '@' && *email != '\0') {
        se += *email;
        email++;
    }
    // Nếu mật khẩu có chứa chuỗi se
    if (pswd.find(se) != -1) return -(300 + pswd.find(se));
    // s chứa nhiêù hơn 2 kí tự liên tiếp giống nhau
    for (int i = 0; i < pswd.length(); i++) {
        if (pswd[i] == pswd[i + 1] && pswd[i] == pswd[i + 2]) {
            return -(400 + i);
            break;
        }
    }

    // s không chứa kí tự đăc biệt
    int countSpecialChar = 0;
    for (int i = 0; i < pswd.length(); i++)
    {
        if (pswd[i] == '@' || pswd[i] == '#' || pswd[i] == '%' || pswd[i] == '$' || pswd[i] == '!')
            countSpecialChar++;
    }
    if (countSpecialChar == 0) return -5;

    /*Kiểm tra kí tự không hợp lệ*/
    for (int i = 0; i < pswd.length(); i++)
    {
        if (pswd[i] == 64 || pswd[i] == 35 || pswd[i] == 37 || pswd[i] == 36 || pswd[i] == 33 || (pswd[i] >= 48 && pswd[i] <= 57) || (pswd[i] >= 65 && pswd[i] <= 90) || (pswd[i] >= 97 && pswd[i] <= 122));
        else {
            return i;
        }
    }
    /*Sau cùng nếu s là mật khẩu hợp lệ*/
    return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxFrequency = 1;
    int maxLen = 0;
    string correctPswd;
    for (int i = 0; i < num_pwds; i++) {
        int fre1lement = 1;
        for (int j = i + 1; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
                fre1lement++;
        }

        if ((fre1lement > maxFrequency) || (fre1lement == maxFrequency && strlen(arr_pwds[i]) > maxLen))
        {
            maxFrequency = fre1lement;
            maxLen = strlen(arr_pwds[i]);
            correctPswd = arr_pwds[i];
        }
    }

    for (int i = 0; i < num_pwds; i++) {
        if (arr_pwds[i] == correctPswd) return i;
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////