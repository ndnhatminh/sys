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

// Check
void checkEXP(int &EXP1, int &EXP2)
{
    // Thiết lập lại giá trị nếu vượt quá hoặc dưới giới hạn
    EXP1 = (EXP1 > 600) ? 600 : ((EXP1 < 0) ? 0 : EXP1);
    EXP2 = (EXP2 > 600) ? 600 : ((EXP2 < 0) ? 0 : EXP2);
}

void checkHP(int &HP1, int &HP2)
{
    // Thiết lập lại giá trị nếu vượt quá hoặc dưới giới hạn
    HP1 = (HP1 > 666) ? 666 : ((HP1 < 0) ? 0 : HP1);
    HP2 = (HP2 > 666) ? 666 : ((HP2 < 0) ? 0 : HP2);
}

void checkM(int &M1, int &M2)
{
    // Thiết lập lại giá trị nếu vượt quá hoặc dưới giới hạn
    M1 = (M1 > 3000) ? 3000 : ((M1 < 0) ? 0 : M1);
    M2 = (M2 > 3000) ? 3000 : ((M2 < 0) ? 0 : M2);
}

// Task 1
void firstMeet_Case1(int &exp1, int &exp2, int e1)
{
    if (e1 == 0)
        exp2 += 29;
    else if (e1 == 1)
        exp2 += 45;
    else if (e1 == 2)
        exp2 += 75;
    else
        exp2 += 149; // 29 + 45 + 75

    int D = e1 * 3 + exp1 * 7;
    if (D % 2 == 0)
        exp1 = static_cast<int>(std::ceil(exp1 + (D / 200.0) - 0.001)); // Làm tròn lên
    else
        exp1 = static_cast<int>(std::ceil(exp1 - (D / 100.0) - 0.001)); // Làm tròn lên

    checkEXP(exp1, exp2); // Kiểm tra giá trị EXP
}

void firstMeet_Case2(int &exp1, int &exp2, int e1)
{
    if (e1 >= 4 && e1 <= 19)
        exp2 = static_cast<int>(std::ceil(exp2 + (e1 / 4.0 + 19) - 0.001));
    else if (e1 >= 20 && e1 <= 49)
        exp2 = static_cast<int>(std::ceil(exp2 + (e1 / 9.0 + 21) - 0.001));
    else if (e1 >= 50 && e1 <= 65)
        exp2 = static_cast<int>(std::ceil(exp2 + (e1 / 16.0 + 17) - 0.001));
    else if (e1 >= 66 && e1 <= 79)
    {
        exp2 = static_cast<int>(std::ceil(exp2 + (e1 / 4.0 + 19) - 0.001));
        if (exp2 > 200)
            exp2 = static_cast<int>(std::ceil(exp2 + (e1 / 9.0 + 21) - 0.001));
    }
    else
    {
        exp2 = static_cast<int>(std::ceil(exp2 + (e1 / 4.0 + 19) - 0.001));
        exp2 = static_cast<int>(std::ceil(exp2 + (e1 / 9.0 + 21) - 0.001));
        if (exp2 > 400)
        {
            exp2 = static_cast<int>(std::ceil(exp2 + (e1 / 16.0 + 17) - 0.001));
            exp2 = static_cast<int>(std::ceil(exp2 * 1.15 - 0.001));
        }
    }

    exp1 -= e1;
    checkEXP(exp1, exp2); // Kiểm tra giá trị EXP
}

int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    if (e1 <= 3 && e1 >= 0)
        firstMeet_Case1(exp1, exp2, e1);
    else if (e1 >= 4 && e1 <= 99)
        firstMeet_Case2(exp1, exp2, e1);
    else
        return -99;

    return exp1 + exp2;
}

// Task 2
int closestPerfectSquare(int X) // Tìm số chính phương gần nhất
{
    int sqrtX = static_cast<int>(std::sqrt(X));
    int square1 = sqrtX * sqrtX;
    int square2 = (sqrtX + 1) * (sqrtX + 1);

    return (X - square1 < square2 - X) ? square1 : square2;
}

double traceLuggage_Street1(int exp1)
{
    int S;
    S = closestPerfectSquare(exp1);
    if (exp1 >= S)
        return 100;
    else
        return ((exp1 / S + 80) / 123.0) * 100;
}

double traceLuggage_Street2(int &HP1, int &EXP1, int &M1, int e2)
{
    double initialM = M1 * 0.5;
    while (true)
    {
        // Sự kiện 1
        if (HP1 < 200)
        {
            HP1 = static_cast<int>(std::ceil(HP1 * 1.3 - 0.001));
            M1 -= 150;
        }
        else if (HP1 >= 200)
        {
            HP1 = static_cast<int>(std::ceil(HP1 * 1.1 - 0.001));
            M1 -= 70;
        }
        checkHP(HP1, HP1); // Kiểm tra giá trị HP
        checkM(M1, M1);    // Kiểm tra giá trị M
        if (e2 % 2 == 1 && M1 < initialM)
        {
            EXP1 = static_cast<int>(std::ceil(EXP1 * 1.17 - 0.001));
            HP1 = static_cast<int>(std::ceil(HP1 - HP1 * 0.17 - 0.001));
            checkEXP(EXP1, EXP1); // Kiểm tra giá trị EXP
            checkHP(HP1, HP1);    // Kiểm tra giá trị HP
            break;
        }
        else if (e2 % 2 == 0 && M1 == 0)
        {
            EXP1 = static_cast<int>(std::ceil(EXP1 * 1.17 - 0.001));
            HP1 = static_cast<int>(std::ceil(HP1 - HP1 * 0.17 - 0.001));
            checkEXP(EXP1, EXP1); // Kiểm tra giá trị EXP
            checkHP(HP1, HP1);    // Kiểm tra giá trị HP
            break;
        }

        // Sự kiện 2
        if (EXP1 < 400)
            M1 -= 200;
        else if (EXP1 >= 400)
            M1 -= 120;
        EXP1 = static_cast<int>(std::ceil(EXP1 * 1.13 - 0.001));
        checkEXP(EXP1, EXP1); // Kiểm tra giá trị EXP
        checkM(M1, M1);       // Kiểm tra giá trị M
        if (e2 % 2 == 1 && M1 < initialM)
        {
            EXP1 = static_cast<int>(std::ceil(EXP1 * 1.17 - 0.001));
            HP1 = static_cast<int>(std::ceil(HP1 - HP1 * 0.17 - 0.001));
            checkEXP(EXP1, EXP1); // Kiểm tra giá trị EXP
            checkHP(HP1, HP1);    // Kiểm tra giá trị HP
            break;
        }
        else if (e2 % 2 == 0 && M1 == 0)
        {
            EXP1 = static_cast<int>(std::ceil(EXP1 * 1.17 - 0.001));
            HP1 = static_cast<int>(std::ceil(HP1 - HP1 * 0.17 - 0.001));
            checkEXP(EXP1, EXP1); // Kiểm tra giá trị EXP
            checkHP(HP1, HP1);    // Kiểm tra giá trị HP
            break;
        }

        // Sự kiện 3
        if (EXP1 < 300)
            M1 -= 100;
        else if (EXP1 >= 300)
            M1 -= 120;
        EXP1 = static_cast<int>(std::ceil(EXP1 * 0.9 - 0.001));
        checkEXP(EXP1, EXP1); // Kiểm tra giá trị EXP
        checkM(M1, M1);       // Kiểm tra giá trị M
        if (e2 % 2 == 1 && M1 <= initialM)
        {
            EXP1 = static_cast<int>(std::ceil(EXP1 * 1.17 - 0.001));
            HP1 = static_cast<int>(std::ceil(HP1 - HP1 * 0.17 - 0.001));
            checkEXP(EXP1, EXP1); // Kiểm tra giá trị EXP
            checkHP(HP1, HP1);    // Kiểm tra giá trị HP
            break;
        }
        else if (e2 % 2 == 0)
        {
            EXP1 = static_cast<int>(std::ceil(EXP1 * 1.17 - 0.001));
            checkEXP(EXP1, EXP1); // Kiểm tra giá trị EXP
            HP1 = static_cast<int>(std::ceil(HP1 - HP1 * 0.17 - 0.001));
            checkHP(HP1, HP1); // Kiểm tra giá trị HP
            break;
        }
    }

    return traceLuggage_Street1(EXP1);
}

double traceLuggage_Street3(int e2)
{
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (e2 < 10)
    {
        i = e2;
    }
    else
    {
        i = (e2 / 10 + e2 % 10) % 10;
    }
    return P[i];
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int e2)
{
    // Update here
    if (e2 < 0 || e2 > 99)
        return -99;
    double P1 = traceLuggage_Street1(EXP1);
    double P2 = traceLuggage_Street2(HP1, EXP1, M1, e2);
    double P3 = traceLuggage_Street3(e2);

    if (P1 == 100 && P2 == 100 && P3 == 100)
        EXP1 = static_cast<int>(std::ceil(EXP1 * 0.75 - 0.001));
    else
    {
        double P = (P1 + P2 + P3) / 3;
        if (P < 50)
        {
            HP1 = static_cast<int>(std::ceil(HP1 * 0.85 - 0.001));
            EXP1 = static_cast<int>(std::ceil(EXP1 * 1.15 - 0.001));
        }
        else
        {
            HP1 = static_cast<int>(std::ceil(HP1 * 0.9 - 0.001));
            EXP1 = static_cast<int>(std::ceil(EXP1 * 1.2 - 0.001));
        }
    }
    checkEXP(EXP1, EXP1); // Kiểm tra giá trị EXP
    checkHP(HP1, HP1);    // Kiểm tra giá trị HP

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // Update here
    if (E3 < 0 || E3 > 99)
        return -99;
    int taxi[10][10] = {0};
    int sherlock[10][10] = {0};

    // Tính điểm cho taxi
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // Tính điểm cho sherlock
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // Đường chéo trái
            int leftDiagonalMax = taxi[i][j];
            for (int k = 0; k < std::min(i, j); k++)
            {
                leftDiagonalMax = leftDiagonalMax > taxi[i - k][j - k] ? leftDiagonalMax : taxi[i - k][j - k];
            }

            // Đường chéo phải
            int rightDiagonalMax = taxi[i][j];
            for (int k = 0; k < std::min(10 - i, j); k++)
            {
                rightDiagonalMax = rightDiagonalMax > taxi[i + k][j - k] ? rightDiagonalMax : taxi[i + k][j - k];
            }

            sherlock[i][j] = leftDiagonalMax > rightDiagonalMax ? leftDiagonalMax : rightDiagonalMax;
            sherlock[i][j] = abs(sherlock[i][j]);
        }
    }

    // Tìm vị trí gặp nhau
    int I = 0, J = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (taxi[i][j] > E3 * 2)
                I++;
            if (taxi[i][j] < -E3)
                J++;
        }
    }

    // Nếu i hoặc j là số có 2 chữ số
    while (I >= 10 || J >= 10)
    {
        if (I >= 10)
        {
            I = I / 10 + I % 10;
        }
        if (J >= 10)
        {
            J = J / 10 + J % 10;
        }
    }
    // Tính điểm cuối cùng
    int MaxScore;
    if (std::abs(taxi[I][J]) > sherlock[I][J])
    {
        // Taxi thoát được
        EXP1 = static_cast<int>(std::ceil(EXP1 * 0.88 - 0.001));
        HP1 = static_cast<int>(std::ceil(HP1 * 0.9 - 0.001));
        EXP2 = static_cast<int>(std::ceil(EXP2 * 0.88 - 0.001));
        HP2 = static_cast<int>(std::ceil(HP2 * 0.9 - 0.001));
        MaxScore = taxi[I][J];
    }
    else
    {
        // Sherlock và Watson bắt được taxi
        EXP1 = static_cast<int>(std::ceil(EXP1 * 1.12 - 0.001));
        HP1 = static_cast<int>(std::ceil(HP1 * 1.1 - 0.001));
        EXP2 = static_cast<int>(std::ceil(EXP2 * 1.12 - 0.001));
        HP2 = static_cast<int>(std::ceil(HP2 * 1.1 - 0.001));
        MaxScore = sherlock[I][J];
    }
    checkEXP(EXP1, EXP2); // Kiểm tra giá trị EXP
    checkHP(HP1, HP2);    // Kiểm tra giá trị HP
    return MaxScore;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    std::string password(s);
    std::string userEmail(email);
    std::string se = userEmail.substr(0, userEmail.find('@'));

    // Kiểm tra độ dài của mật khẩu
    if (password.length() < 8)
        return -1;
    if (password.length() > 20)
        return -2;

    // Kiểm tra xem mật khẩu có chứa chuỗi 'se' không
    if (password.find(se) != std::string::npos)
        return -(300 + password.find(se));

    // Kiểm tra xem mật khẩu có chứa nhiều hơn 2 ký tự liên tiếp không
    for (int i = 0; i < password.length() - 2; i++)
    {
        if (password[i] == password[i + 1] && password[i + 1] == password[i + 2])
            return -(400 + i);
    }

    // Kiểm tra xem mật khẩu có chứa ít nhất 1 ký tự đặc biệt không
    std::string specialChars = "@#%$!";
    bool containsSpecialChar = false;
    for (char c : password)
    {
        if (specialChars.find(c) != std::string::npos)
        {
            containsSpecialChar = true;
            break;
        }
    }
    if (!containsSpecialChar)
        return -5;

    // Kiểm tra xem mật khẩu có chứa ký tự không hợp lệ không
    for (char c : password)
    {
        if (!std::isdigit(c) && !std::isalpha(c) && specialChars.find(c) == std::string::npos)
            return password.find(c);
        // return 999;
    }

    // Nếu mật khẩu hợp lệ, trả về -10
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int maxCount = 0, maxLength = 0, firstPos = 0;
    for (int i = 0; i < num_pwds; ++i)
    {
        int count = 0, length = strlen(arr_pwds[i]);
        for (int j = 0; j < num_pwds; ++j)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                count++;
            }
        }
        if (count > maxCount || (count == maxCount && length > maxLength))
        {
            maxCount = count;
            maxLength = length;
            firstPos = i;
        }
    }
    return firstPos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////