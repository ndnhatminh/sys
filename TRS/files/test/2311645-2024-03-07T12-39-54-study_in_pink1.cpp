#include "study_in_pink1.h"

typedef pair<int, int> Range;

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &exp1,
    int &exp2,
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
        ifs >> HP1 >> HP2 >> exp1 >> exp2 >> M1 >> M2 >> E1 >> E2 >> E3;
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

int check(int n, int firstpoint, int lastpoint)
{
    n = (n < firstpoint) ? firstpoint : (n > lastpoint) ? lastpoint
                                                        : n;
    return n;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    int firstpoint = 0, lastpoint = 600;
    if (e1 < 0 || e1 > 99)
        return -99;
    exp1 = check(exp1, firstpoint, lastpoint);
    exp2 = check(exp2, firstpoint, lastpoint);

    int in4;
    bool case1;
    if (e1 <= 3)
    {
        in4 = (e1 + 1);
        case1 = 1;
    }
    else
    {

        in4 = (e1 <= 25) ? (e1 / 20 + 1) : (e1 <= 65) ? (e1 / 25 + 1)
                                                      : (e1 / 20 + 1);
        case1 = 0;
    }

    const int inform1_1 = 29, inform1_2 = 45, inform1_3 = 75;
    float inform2_1, inform2_2, inform2_3;

    inform2_1 = e1 * 1.0000 / 4 + 19;
    inform2_2 = e1 * 1.0000 / 9 + 21;
    inform2_3 = e1 * 1.0000 / 16 + 17;
    float exp1_test = exp1; // use float var to caculate
    float exp2_test = exp2;

    if (case1)
    {
        // caculate exp2 (dont need to round up)
        switch (in4)
        {
        case 1:
        {
            exp2 += inform1_1;
            break;
        }
        case 2:
        {
            exp2 += inform1_2;
            break;
        }
        case 3:
        {
            exp2 += inform1_3;
            break;
        }

        case 4:
        {
            exp2 = exp2 + inform1_1 + inform1_2 + inform1_3;
            break;
        }
        }
        // caculate exp1  (need to round up)
        int D = e1 * 3 + exp1_test * 7;
        if (D % 2 == 0)
            exp1_test = ceil(exp1_test + D * 1.0000 / 200);
        else
            exp1_test = ceil(exp1_test - D * 1.0000 / 100);

        exp1 = exp1_test;
        exp1 = check(exp1, 0, 600);
    }
    else
    {
        // caculate exp2 (need round up)
        switch (in4)
        {
        case 1:
        {
            exp2_test += inform2_1;
            break;
        }
        case 2:
        {
            exp2_test += inform2_2;
            break;
        }
        case 3:
        {
            exp2_test += inform2_3;
            break;
        }
        case 4:
        {
            exp2 = ceil(exp2_test + inform2_1); // add inform2_1 and roundup value and check value
            // exp2 = exp2_test;                         // convert to int to check value
            exp2 = check(exp2, firstpoint, lastpoint);
            exp2_test = exp2; // return exp2 to exp2_test to continue caculate
            if (exp2_test > 200)
                exp2_test += inform2_2;
            break;
        }
        case 5:
        {
            exp2 = ceil(exp2_test + inform2_1);
            exp2 = check(exp2, firstpoint, lastpoint);
            exp2 = ceil(exp2 + inform2_2);
            exp2 = check(exp2, firstpoint, lastpoint);
            exp2_test = exp2;
            if (exp2_test > 400)
            {
                exp2_test = ceil(exp2_test + inform2_3);
                exp2 = exp2_test; // convert to int to check value
                exp2 = check(exp2, firstpoint, lastpoint);
                exp2_test = exp2; // return exp2 to exp2_test to continue caculate
                exp2_test = exp2_test * 1.1500;
            }
            break;
        }
        }
        // round up exp2
        exp2_test = ceil(exp2_test);
        exp2 = exp2_test;
        // caculate exp1 (need round up)
        exp1_test = ceil(exp1_test - e1);
        exp1 = exp1_test;
        exp1 = check(exp1, firstpoint, lastpoint);
        exp2 = check(exp2, firstpoint, lastpoint);
    }
    exp1 = check(exp1, firstpoint, lastpoint);
    exp2 = check(exp2, firstpoint, lastpoint);
    return exp1 + exp2;
}

//----------------------------------------------------------------

int nearestPerfectSquare(int num)
{
    // Tìm số chính phương gần nhất
    int closestPerfectSquare = round(sqrt(num));
    int lowerSquare = closestPerfectSquare - 1;
    int higherSquare = closestPerfectSquare + 1;

    // So sánh khoảng cách giữa số đã cho và hai số chính phương gần nhất
    int dist1 = abs(num - lowerSquare * lowerSquare);
    int dist2 = abs(num - closestPerfectSquare * closestPerfectSquare);
    int dist3 = abs(num - higherSquare * higherSquare);

    // Tìm số chính phương gần nhất
    int nearestPerfectSquare;
    if (dist1 <= dist2 && dist1 <= dist3)
    {
        nearestPerfectSquare = lowerSquare;
    }
    else if (dist2 <= dist1 && dist2 <= dist3)
    {
        nearestPerfectSquare = closestPerfectSquare;
    }
    else
    {
        nearestPerfectSquare = higherSquare;
    }

    return nearestPerfectSquare * nearestPerfectSquare;
}

void updateEXP1(int &M1, int &HP1, int &exp1, int e2)
{
    double halfM1 = M1 * 0.5;
    halfM1 = check(halfM1, 0, 3000);
    int M1_loss_1;
    int M0 = M1;

    if (e2 % 2 == 1)
    {
        if (halfM1 > 0)
        {
            while (e2 % 2 == 1)
            {
                if (HP1 < 200)
                {
                    HP1 = ceil(HP1 + 0.3 * HP1);
                    M1_loss_1 = -150;
                }
                else
                {
                    HP1 = ceil(HP1 + 0.1 * HP1);
                    M1_loss_1 = -70;
                }
                HP1 = check(HP1, 0, 666);
                M1 += M1_loss_1;
                M1 = check(M1, 0, 3000);
                if (abs(M0 - M1) > halfM1)
                {
                    break;
                }
                int M1_loss_2 = (exp1 < 400) ? -200 : -120;
                M1 += M1_loss_2;
                exp1 = ceil(exp1 * 1.13);
                exp1 = check(exp1, 0, 600);
                M1 = check(M1, 0, 3000);
                if (abs(M0 - M1) > halfM1)
                {
                    break;
                }
                int M1_loss_3 = (exp1 < 300) ? -100 : -120;
                M1 += M1_loss_3;
                exp1 = ceil(exp1 * 0.9);
                exp1 = check(exp1, 0, 600);
                M1 = check(M1, 0, 3000);
                if (abs(M0 - M1) > halfM1)
                {
                    break;
                }
            }
        }
        if (halfM1 == 0)
        {
            if (M1 != 0)
            {
                if (HP1 < 200)
                {
                    HP1 = ceil(HP1 + 0.3 * HP1);
                    M1_loss_1 = -150;
                }
                else
                {
                    HP1 = ceil(HP1 + 0.1 * HP1);
                    M1_loss_1 = -70;
                }
                HP1 = check(HP1, 0, 666);
                M1 += M1_loss_1;
                M1 = check(M1, 0, 3000);
            }
        }
        HP1 = ceil(HP1 * 0.83);
        exp1 = ceil(exp1 * 1.17);
        HP1 = check(HP1, 0, 666);
        exp1 = check(exp1, 0, 600);
    }

    if (e2 % 2 == 0)
    {
        if (M1 != 0)
        {
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 + 0.3 * HP1);
                M1_loss_1 = -150;
            }
            else
            {
                HP1 = ceil(HP1 + 0.1 * HP1);
                M1_loss_1 = -70;
            }
            M1 += M1_loss_1;
            M1 = check(M1, 0, 3000);
            HP1 = check(HP1, 0, 666);

            if (M1 != 0)
            {
                int M1_loss_2 = (exp1 < 400) ? -200 : -120;
                M1 += M1_loss_2;
                exp1 = ceil(exp1 * 1.13);
                exp1 = check(exp1, 0, 600);
                M1 = check(M1, 0, 3000);
                if (M1 != 0)
                {
                    int M1_loss_3 = (exp1 < 300) ? -100 : -120;
                    M1 += M1_loss_3;
                    exp1 = ceil(exp1 * 0.9);
                    exp1 = check(exp1, 0, 600);
                    M1 = check(M1, 0, 3000);
                }
            }
        }
        HP1 = ceil(HP1 * 0.83);
        exp1 = ceil(exp1 * 1.17);
        exp1 = check(exp1, 0, 600);
        HP1 = check(HP1, 0, 666);
    }
    exp1 = check(exp1, 0, 600);
    HP1 = check(HP1, 0, 666);
}

int traceLuggage(int &HP1, int &exp1, int &M1, int e2)
{
    // Kiểm tra giá trị đầu vào
    if (e2 < 0 || e2 > 99)
        return -99;
    HP1 = check(HP1, 0, 666);
    exp1 = check(exp1, 0, 600);
    int exp1_2 = check(exp1_2, 0, 600);
    M1 = check(M1, 0, 3000);

    float S = nearestPerfectSquare(exp1);
    float P1 = (exp1 >= S) ? 100.0 : roundf((exp1 * 1.00f / S + 80) / 123 * 100);

    updateEXP1(M1, HP1, exp1, e2);
    float S2 = nearestPerfectSquare(exp1);
    int HP_1 = HP1;
    int exp_1 = exp1;
    float P2 = (exp1 >= S2) ? 100.0 : roundf((exp1 * 1.00f / S + 80) / 123 * 100);

    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = (e2 < 10) ? e2 : ((e2 / 10 + e2 % 10) % 10);
    float P3 = P[i];

    float P_averange = (P1 + P2 + P3) / 3;
    if (P_averange >= 100)
    {
        exp1 = ceil(exp1 * 0.75);
    }
    else
    {
        if (P_averange < 50)
        {
            exp1 = ceil(exp_1 * 1.15);
            HP1 = ceil(HP_1 * 0.85);
            exp1 = check(exp1, 0, 600);
            HP1 = check(HP1, 0, 666);
        }
        else
        {
            exp1 = ceil(exp1 * 1.2);
            HP1 = ceil(HP1 * 0.9);
            exp1 = check(exp1, 0, 600);
            HP1 = check(HP1, 0, 666);
        }
    }
    // std::cout << P_averange << std::endl;
    return HP1 + exp1 + M1;
}

int maxOnLeftDiagonal(int matrix[10][10], int size, int row, int col)
{
    int maxVal = matrix[row][col];

    while (row >= 0 && col >= 0 && row < size && col < size)
    {
        if (matrix[row][col] > maxVal)
        {
            maxVal = matrix[row][col];
        }
        row++;
        col++;
    }
    return maxVal;
}

int maxOnRightDiagonal(int matrix[10][10], int size, int row, int col)
{
    int maxVal = matrix[row][col];

    while (row >= 0 && col < size && row < size && col >= 0)
    {
        if (matrix[row][col] > maxVal)
        {
            maxVal = matrix[row][col];
        }
        row++;
        col--;
    }
    return maxVal;
}

void TaxiMap(int e3, int &pos, int &neg, int &point, int &max, int HP1, int exp1, int HP2, int exp2, int map[10][10])
{
    pos = 0;
    neg = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            map[i][j] = ((e3 * j) + (i * 2)) * (i - j);
            if (map[i][j] > e3 * 2)
                pos += 1;
            if (map[i][j] < -e3)
                neg += 1;
        }
    }

    while (pos > 9)
    {
        pos = pos / 10 + pos % 10;
    }
    while (neg > 9)
    {
        neg = neg / 10 + neg % 10;
    }

    int row = pos;
    int col = neg;

    point = map[row][col];
    int maxleft = maxOnLeftDiagonal(map, 10, row, col);
    int maxright = maxOnRightDiagonal(map, 10, row, col);
    max = (maxright < maxleft) ? (maxleft) : (maxright);
}

int chaseTaxi(int &HP1, int &exp1, int &HP2, int &exp2, int e3)
{
    if (e3 < 0 || e3 > 99)
        return -99;

    exp1 = check(exp1, 0, 600);
    exp2 = check(exp2, 0, 600);
    HP1 = check(HP1, 0, 666);
    HP2 = check(HP2, 0, 666);

    int pos, neg, point, max;
    int map[10][10];

    TaxiMap(e3, pos, neg, point, max, HP1, exp1, HP2, exp2, map);

    if (abs(point) > max)
    {
        exp1 = ceil(exp1 * 0.999999 * 0.88);
        HP1 = ceil(HP1 * 0.999999 * 0.9);
        exp2 = ceil(exp2 * 0.999999 * 0.88);
        HP2 = ceil(HP2 * 0.999999 * 0.9);
    }
    else
    {
        exp1 = ceil(exp1 * 0.999999 * 1.12);
        HP1 = ceil(HP1 * 0.999999 * 1.1);
        exp2 = ceil(exp2 * 0.999999 * 1.12);
        HP2 = ceil(HP2 * 0.999999 * 1.1);
    }
    exp1 = check(exp1, 0, 600);
    HP1 = check(HP1, 0, 666);
    exp2 = check(exp2, 0, 600);
    HP2 = check(HP2, 0, 666);
    int x_return = (abs(point) <= max) ? (max) : (point);

    return x_return;
}
// Task 4
int checkPassword(const char *s, const char *email)
{
    // Tìm vị trí của ký tự '@' trong email
    const char *at_index = strchr(email, '@');
    if (at_index == nullptr)
    {
        return -10; // Email không hợp lệ
    }
    size_t se_length = at_index - email;
    char *se = new char[se_length + 1]; // Chuỗi se
    strncpy(se, email, se_length);
    se[se_length] = '\0';

    // Kiểm tra độ dài mật khẩu
    size_t s_length = strlen(s);
    if (s_length < 8)
    {
        delete[] se;
        return -1;
    }
    else if (s_length > 20)
    {
        delete[] se;
        return -2;
    }

    // Kiểm tra chuỗi se
    const char *pos = strstr(s, se);
    if (pos != nullptr)
    {
        int index = pos - s;
        delete[] se;
        return -(300 + index); // Trả về -(300+<sei>)
    }

    // Kiểm tra nhiều hơn 2 ký tự liên tiếp
    for (size_t i = 0; i < s_length - 2; ++i)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            delete[] se;
            return -(400 + i); // Trả về -(400+<sci>)
        }
    }

    // Kiểm tra ký tự đặc biệt
    const char special_characters[] = {'@', '#', '%', '$', '!'};
    bool has_special_character = false;
    for (size_t i = 0; i < s_length; ++i)
    {
        for (size_t j = 0; j < sizeof(special_characters) / sizeof(special_characters[0]); ++j)
        {
            if (s[i] == special_characters[j])
            {
                has_special_character = true;
                break;
            }
        }
        if (has_special_character)
            break;
    }
    if (!has_special_character)
    {
        delete[] se;
        return -5;
    }

    // Kiểm tra từng ký tự trong mật khẩu
    for (size_t i = 0; i < s_length; ++i)
    {
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')))
        {
            bool is_special = false;
            for (size_t j = 0; j < sizeof(special_characters) / sizeof(special_characters[0]); ++j)
            {
                if (s[i] == special_characters[j])
                {
                    is_special = true;
                    break;
                }
            }
            if (!is_special)
            {
                delete[] se;
                return static_cast<int>(i);
            }
        }
    }

    delete[] se;
    return -10; // Mật khẩu hợp lệ
}
// Task 5
struct PasswordInfo
{
    int count;
    int length;
};

int findCorrectPassword(const char **arr_pwds, int num_pwds)
{
    // Tạo một mảng động để lưu thông tin về mật khẩu
    PasswordInfo *password_infos = new PasswordInfo[num_pwds];

    // Khởi tạo các giá trị ban đầu
    for (int i = 0; i < num_pwds; ++i)
    {
        password_infos[i].count = 0;
        password_infos[i].length = std::strlen(arr_pwds[i]);
    }

    // Tính số lần xuất hiện của mỗi mật khẩu
    for (int i = 0; i < num_pwds; ++i)
    {
        int j = 0;
        while (j < num_pwds && std::strcmp(arr_pwds[i], arr_pwds[j]) != 0)
        {
            ++j;
        }
        if (j < num_pwds)
        {
            ++password_infos[j].count;
        }
    }

    // Tìm mật khẩu có số lần xuất hiện lớn nhất và độ dài lớn nhất
    int max_count = 0;
    int max_length = 0;
    for (int i = 0; i < num_pwds; ++i)
    {
        if (password_infos[i].count > max_count || (password_infos[i].count == max_count && password_infos[i].length > max_length))
        {
            max_count = password_infos[i].count;
            max_length = password_infos[i].length;
        }
    }

    // Tìm vị trí đầu tiên của mật khẩu đúng trong mảng arr_pwds
    for (int i = 0; i < num_pwds; ++i)
    {
        if (password_infos[i].count == max_count && password_infos[i].length == max_length)
        {
            delete[] password_infos; // Giải phóng bộ nhớ động đã cấp phát
            return i;
        }
    }

    delete[] password_infos; // Giải phóng bộ nhớ động đã cấp phát
    return -1;               // Trả về -1 nếu không tìm thấy mật khẩu đúng
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////