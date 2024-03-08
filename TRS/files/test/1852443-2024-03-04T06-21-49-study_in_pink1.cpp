#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
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

// Check HP1 & HP2  [0,666]
void checkHP(int &hp1, int &hp2)
{
    // hp1
    if (hp1 < 0)
    {
        hp1 = 0;
    }
    else if (hp1 > 666)
    {
        hp1 = 666;
    }
    // hp2
    if (hp2 < 0)
    {
        hp2 = 0;
    }
    else if (hp2 > 666)
    {
        hp2 = 666;
    }
}
// Check EXP1 & EXP2  [0,600]
void checkEXP(int &exp1, int &exp2)
{
    // exp1
    if (exp1 < 0)
    {
        exp1 = 0;
    }
    else if (exp1 > 600)
    {
        exp1 = 600;
    }
    // exp2
    if (exp2 < 0)
    {
        exp2 = 0;
    }
    else if (exp2 > 600)
    {
        exp2 = 600;
    }
}
// check M1 & M2 [0,3000]
void checkM(int &m1, int &m2)
{
    // m1
    if (m1 < 0)
    {
        m1 = 0;
    }
    else if (m1 > 3000)
    {
        m1 = 3000;
    }
    // m2
    if (m2 < 0)
    {
        m2 = 0;
    }
    else if (m2 > 3000)
    {
        m2 = 3000;
    }
}
// check E [0,99] -->do task Else return -99

// check M1 Task2
void check_HP1_EXP1_M1(int &HP1, int &EXP1, int &M1)
{

    // HP1
    if (HP1 < 0)
    {
        HP1 = 0;
    }
    else if (HP1 > 666)
    {
        HP1 = 666;
    }
    // EXP1
    if (EXP1 < 0)
    {
        EXP1 = 0;
    }
    else if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    // M1
    if (M1 < 0)
    {
        M1 = 0;
    }
    else if (M1 > 3000)
    {
        M1 = 3000;
    }
}
bool checkContinueEvent(int total_spend, double M1_t)
{
    if (total_spend > M1_t)
        return false;
    return true;
}
int nearestSquare(int num)
{
    // Tìm căn bậc hai của số nguyên cho trước
    int root = sqrt(num);

    // Kiểm tra xem số nguyên này có phải là số chính phương không
    if (root * root == num)
    {
        return num; // Trả về chính số nguyên này nếu nó là số chính phương
    }
    else
    {
        // Nếu không phải, tìm số chính phương gần nhất
        int lowerSquare = root * root;
        int upperSquare = (root + 1) * (root + 1);

        // So sánh khoảng cách giữa số nguyên và các số chính phương gần nhất
        if (num - lowerSquare <= upperSquare - num)
        {
            return lowerSquare;
        }
        else
        {
            return upperSquare;
        }
    }
}
// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // Check exp1, exp2 [0,600]
    checkEXP(exp1, exp2);
    // Check e1 [0,99]
    if (e1 >= 0 && e1 <= 99)
    {
        // TH1: E1[0,3]
        if (e1 >= 0 && e1 <= 3)
        {
            // exp1 // Sherlock
            int d = e1 * 3 + exp1 * 7;
            if (d % 2 == 0)
            {
                exp1 = ceil(exp1 + (d * 1.0) / (200 * 1.0)); // Afghanistan
            }
            else
            {
                exp1 = ceil(exp1 - (d * 1.0) / (100 * 1.0)); // Iraq
            }
            // exp2  //Watson
            if (e1 == 0)
            {
                exp2 = exp2 + 29;
            }
            else if (e1 == 1)
            {
                exp2 = exp2 + 45;
            }
            else if (e1 == 2)
            {
                exp2 = exp2 + 75;
            }
            else
            {
                exp2 = exp2 + 29 + 45 + 75;
            }
        }
        else // TH2: E1[4,99]
        {
            // exp2
            if (e1 >= 4 && e1 <= 19) // e1[4,19]
            {
                exp2 = ceil(exp2 + (e1 * 1.0) / 4.0 + 19);
            }
            else if (e1 >= 20 && e1 <= 49) // e2[20,49]
            {
                exp2 = ceil(exp2 + (e1 * 1.0) / 9.0 + 21);
            }
            else if (e1 >= 50 && e1 <= 65) // e3[50,65]
            {
                exp2 = ceil(exp2 + (e1 * 1.0) / 16.0 + 17);
            }
            else if (e1 >= 66 && e1 <= 79) // e4[66,79]
            {
                exp2 = ceil(exp2 + (e1 * 1.0) / 4.0 + 19); // e1
                if (exp2 > 200)
                {
                    exp2 = ceil(exp2 + (e1 * 1.0) / 9.0 + 21); // e2
                }
            }
            else if (e1 >= 80 && e1 <= 99) // e5[80,99]
            {
                exp2 = ceil(exp2 + (e1 * 1.0) / 4.0 + 19); // e1

                exp2 = ceil(exp2 + (e1 * 1.0) / 9.0 + 21); // e2

                if (exp2 > 400)
                {
                    exp2 = ceil(exp2 + (e1 * 1.0) / 16.0 + 17); // e3

                    exp2 = ceil(1.15 * exp2); // 15%
                }
            }
            // exp1
            exp1 = exp1 - e1;
        }
        // check EXP
        checkEXP(exp1, exp2);
        return exp1 + exp2;
    }
    else
    {
        return -99;
    }
}
// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // Check HP1, EXP1, M1
    check_HP1_EXP1_M1(HP1, EXP1, M1);
    // Check E2 [0,99]
    if (E2 >= 0 && E2 <= 99)
    {
        // Route 1
        int S1 = nearestSquare(EXP1);
        double P1 = 0.0;
        if (EXP1 >= S1)
        {
            P1 = 100.0; // Nếu EXP1 lớn hơn hoặc bằng S, xác suất là 100%
        }
        else
        {
            P1 = ((EXP1 * 1.0) / (S1 * 1.0) + 80.0) / 1.23; // Nếu không, tính theo công thức
        }
        // Route 2
        if (E2 % 2 == 0) // E2 chẵn
        {
            bool flag_continue = true;
            if (M1 == 0)
                flag_continue = false;

            // Event 1
            if (flag_continue == true)
            {
                if (HP1 < 200)
                {
                    HP1 = ceil(HP1 + HP1 * 0.3); // Cộng thêm 30% HP hiện có
                    M1 -= 150;                   // Trừ tiền mua thức ăn và nước uống
                }
                else
                {
                    HP1 = ceil(HP1 + HP1 * 0.1); // Cộng thêm 10% HP hiện có
                    M1 -= 70;                    // Trừ tiền mua nước uống
                }

                // Check HP1, EXP1, M1
                check_HP1_EXP1_M1(HP1, EXP1, M1);
                // Check M1 after Event 1
                if (M1 == 0)
                    flag_continue = false;
            }

            // Envent 2
            if (flag_continue == true)
            {
                if (EXP1 < 400)
                {
                    M1 -= 200; // Trừ tiền thuê taxi
                }
                else
                {
                    M1 -= 120; // Trừ tiền thuê xe ngựa
                }
                EXP1 = ceil(EXP1 + EXP1 * 0.13); // Tăng EXP1 lên 13%

                // Check HP1, EXP1, M1
                check_HP1_EXP1_M1(HP1, EXP1, M1);
                // Check M1 after Event 2
                if (M1 == 0)
                    flag_continue = false;
            }

            // Event 3
            if (flag_continue == true)
            {
                if (EXP1 < 300)
                {
                    M1 -= 100; // Trừ tiền giup do
                }
                else
                {
                    M1 -= 120; // Trừ tiền giup do
                }
                EXP1 = ceil(EXP1 - EXP1 * 0.1); // Giam EXP1 lên 10%
                // Check HP1, EXP1, M1
                check_HP1_EXP1_M1(HP1, EXP1, M1);
            }
            // End
            HP1 = ceil(HP1 - HP1 * 0.17);    // Giảm HP1 đi 17%
            EXP1 = ceil(EXP1 + EXP1 * 0.17); // Tăng EXP1 lên 17%
            // Check HP1, EXP1, M1
            check_HP1_EXP1_M1(HP1, EXP1, M1);
        }
        else // E2 lẻ
        {
            bool continue_event = true;
            double M1_min = 0.5 * M1;
            double total_spend = 0.0; // envent 1
            if (M1 == 0)
                continue_event = false;
            while (continue_event)
            {
                // Envent 1
                if (continue_event)
                {

                    if (HP1 < 200)
                    {
                        HP1 = ceil(HP1 + HP1 * 0.3); // Cộng thêm 30% HP hiện có
                        M1 -= 150;                   // Trừ tiền mua thức ăn và nước uống
                        total_spend += 150;
                    }
                    else
                    {
                        HP1 = ceil(HP1 + HP1 * 0.1); // Cộng thêm 10% HP hiện có
                        M1 -= 70;                    // Trừ tiền mua nước uống
                        total_spend += 70;
                    }

                    // Check Continue
                    continue_event = checkContinueEvent(total_spend, M1_min);

                    // Check HP1, EXP1, M1
                    check_HP1_EXP1_M1(HP1, EXP1, M1);
                }

                // Envent 2

                if (continue_event)
                {
                    if (EXP1 < 400)
                    {
                        M1 -= 200; // Trừ tiền thuê taxi
                        total_spend += 200;
                    }
                    else
                    {
                        M1 -= 120; // Trừ tiền thuê xe ngựa
                        total_spend += 120;
                    }
                    EXP1 = ceil(EXP1 + EXP1 * 0.13); // Tăng EXP1 lên 13%

                    // Check Continue
                    continue_event = checkContinueEvent(total_spend, M1_min);

                    // Check HP1, EXP1, M1
                    check_HP1_EXP1_M1(HP1, EXP1, M1);
                }

                // Envent 3

                if (continue_event)
                {
                    if (EXP1 < 300)
                    {
                        M1 -= 100;          // Trừ tiền giup do
                        total_spend += 100; // Trừ tiền giup do
                    }
                    else
                    {
                        M1 -= 120;          // Trừ tiền giup do
                        total_spend += 120; // Trừ tiền giup do
                    }
                    EXP1 = ceil(EXP1 - EXP1 * 0.1); // Giam EXP1 lên 10%

                    // Check continue
                    continue_event = checkContinueEvent(total_spend, M1_min);

                    // Check HP1, EXP1, M1
                    check_HP1_EXP1_M1(HP1, EXP1, M1);
                }
            }
            // End
            HP1 = ceil(HP1 - HP1 * 0.17);    // Giảm HP1 đi 17%
            EXP1 = ceil(EXP1 + EXP1 * 0.17); // Tăng EXP1 lên 17%

            // Check HP1, EXP1, M1
            check_HP1_EXP1_M1(HP1, EXP1, M1);
        }

        // Caculate P2
        int S2 = nearestSquare(EXP1);
        double P2 = 0.0;
        if (EXP1 >= S2)
        {
            P2 = 100.0; // Nếu EXP1 lớn hơn hoặc bằng S, xác suất là 100%
        }
        else
        {
            P2 = ((EXP1 * 1.0) / (S2 * 1.0) + 80.0) / 1.23; // Nếu không, tính theo công thức
        }

        ////////////////////// Route 3////////////////////////////
        int arr_p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}; // Mang gia tri xac suat
        int index_p = 0;
        if (E2 < 10)
        {
            index_p = E2;
        }
        else
        {
            int s_index = E2 / 10 + E2 % 10; // Tong 2 chu so
            index_p = s_index % 10;          // Don vi tong 2 chu so
        }

        // Caculate P3
        double P3 = arr_p[index_p];

        ///////////////////// P1, P2,P3///////////////////////
        double P = (P1 + P2 + P3) / 3.0;

        if (P1 == 100 && P2 == 100 && P3 == 100)
        {
            EXP1 = ceil(EXP1 - EXP1 * 0.25); // Giam 25%
        }
        else
        {

            if (P < 50.0)
            {
                HP1 = ceil(HP1 - HP1 * 0.15);    // Giam 15%
                EXP1 = ceil(EXP1 + EXP1 * 0.15); // Tang 15%
            }
            else
            {
                HP1 = ceil(HP1 - HP1 * 0.1);    // Giam 10%
                EXP1 = ceil(EXP1 + EXP1 * 0.2); // Tang 20%
            }
        }

        //////////////////////////////Done///////////////////////////
        // Check HP1, EXP1, M1
        check_HP1_EXP1_M1(HP1, EXP1, M1);

        return HP1 + EXP1 + M1;
    }
    else
        return -99;
}

// Task 3

// Hàm để tìm giá trị lớn nhất trên đường chéo trái của ma trận
int findMaxOnMainDiagonal(int matrix[][10], int i, int j)
{
    int max = matrix[i][j]; // Giả sử giá trị lớn nhất là phần tử tại vị trí (i, j)
    int x = i, y = j;       // Lưu lại vị trí bắt đầu của đường chéo
    while (x < 10 && y < 10)
    {
        if (matrix[x][y] > max)
        {
            max = matrix[x][y];
        }
        x++;
        y++;
    }
    return max;
}

// Hàm để tìm giá trị lớn nhất trên đường chéo phải của ma trận
int findMaxOnAntiDiagonal(int matrix[][10], int i, int j)
{
    int max = matrix[i][j]; // Giả sử giá trị lớn nhất là phần tử tại vị trí (i, j)
    int x = i, y = j;       // Lưu lại vị trí bắt đầu của đường chéo
    while (x < 10 && y >= 0)
    {
        if (matrix[x][y] > max)
        {
            max = matrix[x][y];
        }
        x++;
        y--;
    }
    return max;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // Check HP, EXP
    checkHP(HP1, HP2);
    checkEXP(EXP1, EXP2);
    // Check E3 [0,99]
    if (E3 >= 0 && E3 <= 99)
    {
        // Khởi tạo ma trận điểm số của taxi và tính toán điểm số
        int taxiMap[10][10];
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                taxiMap[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }

        // Tính số giá trị dương lớn hơn E3*2
        // Tính Số giá trị âm nhỏ hơn -E3
        int count_positive = 0;
        int count_negative = 0;
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                if (taxiMap[i][j] > 0 && taxiMap[i][j] > (E3 * 2))
                {
                    count_positive++;
                }
                else if (taxiMap[i][j] < 0 && taxiMap[i][j] < (E3 * (0 - 1)))
                {
                    count_negative++;
                }
            }
        }
        // Tính toán vị trí gặp nhau của taxi và Sherlock-Watson
        while (count_positive > 9)
        {
            count_positive = count_positive / 10 + count_positive % 10;
        }
        while (count_negative > 9)
        {
            count_negative = count_negative / 10 + count_negative % 10;
        }

        // Tính điểm số tương ứng với việc Sherlock và Watson đi theo các đường chéo

        int maxOnMainDiagonal = findMaxOnMainDiagonal(taxiMap, count_positive, count_negative);
        int maxOnAntiDiagonal = findMaxOnAntiDiagonal(taxiMap, count_positive, count_negative);

        int maxPoints = max(maxOnMainDiagonal, maxOnAntiDiagonal);
        int taxiPoints = taxiMap[count_positive][count_negative];
        // So sánh điểm số của taxi với điểm số của Sherlo  ck và Watson

        if (abs(taxiPoints) > maxPoints)
        {
            // Không đuổi kịp Taxi
            EXP1 = ceil(EXP1 - EXP1 * 0.12);
            HP1 = ceil(HP1 - HP1 * 0.10);
            EXP2 = ceil(EXP2 - EXP2 * 0.12);
            HP2 = ceil(HP2 - HP2 * 0.10);

            // Check HP, EXP
            checkHP(HP1, HP2);
            checkEXP(EXP1, EXP2);
            return taxiPoints;
        }
        else
        {
            // Đuổi kịp Taxi
            EXP1 = ceil(EXP1 + EXP1 * 0.12);
            HP1 = ceil(HP1 + HP1 * 0.10);
            EXP2 = ceil(EXP2 + EXP2 * 0.12);
            HP2 = ceil(HP2 + HP2 * 0.10);

            // Check HP, EXP
            checkHP(HP1, HP2);
            checkEXP(EXP1, EXP2);
            return maxPoints;
        }
    }
    else
        return -99;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // Kiểm tra email hợp lệ
    const char *atPos = strchr(email, '@');
    if (atPos == nullptr)
    {
        return -99; // Email không hợp lệ, không có ký tự '@'
    }
    // Tạo chuỗi se từ email
    char se[101];
    strncpy(se, email, atPos - email);
    se[atPos - email] = '\0';

    // Kiểm tra độ dài của mật khẩu
    int len = strlen(s);

    if (len < 8)
    {
        return -1; // Mật khẩu ngắn hơn độ dài tối thiểu
    }
    else if (len > 20)
    {
        return -2; // Mật khẩu dài hơn độ dài tối đa
    }

    // Kiểm tra xem mật khẩu có chứa chuỗi 'se' hay không
    const char *sePos = strstr(s, se);
    if (sePos != nullptr)
    {
        return -(300 + (sePos - s)); // Mật khẩu chứa chuỗi 'se'
    }

    // Kiểm tra ký tự đặc biệt
    const char *specialChars = "@#%$!";
    bool hasSpecialChar = false;
    for (int i = 0; i < len; ++i)
    {
        if (strchr(specialChars, s[i]) != nullptr)
        {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar)
    {
        return -5; // Không có ký tự đặc biệt trong mật khẩu
    }

    // Kiểm tra ký tự liên tiếp và giống nhau
    for (int i = 0; i < len - 1; ++i)
    {
        if (s[i] == s[i + 1])
        {
            if (i > 0 && s[i] == s[i - 1])
            {
                return -(400 + i - 1); // Mật khẩu có nhiều hơn 2 ký tự liên tiếp và giống nhau
            }
        }
    }

    // Kiểm tra các điều kiện khác
    for (int i = 0; i < len; ++i)
    {
        char c = s[i];
        if (!isalnum(c) && strchr(specialChars, c) == nullptr)
        {
            return i; // Ký tự không hợp lệ
        }
    }

    // Mật khẩu hợp lệ
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // Tìm mật khẩu có số lần xuất hiện nhiều nhất và độ dài lớn nhất
    const char *corPassword = nullptr;
    int maxCount = 0;
    int maxLength = 0;
    for (int i = 0; i < num_pwds; ++i)
    {
        // Đếm số lần xuất hiện của mỗi mật khẩu và kiểm tra độ dài của nó
        const char *curPassword = arr_pwds[i];
        int curCount = 1;
        int curLength = strlen(curPassword);
        for (int j = i + 1; j < num_pwds; ++j)
        {
            if (strcmp(arr_pwds[j], curPassword) == 0)
            {
                curCount++;
            }
        }
        // So sánh với mật khẩu
        if (curCount > maxCount || (curCount == maxCount && curLength > maxLength))
        {
            corPassword = curPassword;
            maxCount = curCount;
            maxLength = curLength;
        }
    }

    // Tìm vị trí đầu tiên
    for (int i = 0; i < num_pwds; ++i)
    {
        if (strcmp(arr_pwds[i], corPassword) == 0)
        {
            return i; // Trả về vị trí đầu tiên của mật khẩu đúng
        }
    }

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////