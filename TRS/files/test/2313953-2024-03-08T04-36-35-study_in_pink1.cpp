#include "study_in_pink1.h"
// version 1.1
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
    // DO NOT MODIFY THIS FUNCTION
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

// begin task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    if (e1 >= 0 && e1 <= 3) // TH1 (0.5đ)
    {
        if (e1 == 0)
        {
            exp2 += 29;
        }
        else if (e1 == 1)
        {
            exp2 += 45;
        }
        else if (e1 == 2)
        {
            exp2 += 75;
        }
        else if (e1 == 3)
        {
            exp2 += 149; // sum point of 3 information
        }
        int d = e1 * 3 + exp1 * 7;
        double temp;
        if (d % 2 == 0)
        {
            exp1 = exp1 + (double)d / 200 + 0.9999; // select true: add exp1
        }
        else
        {
            exp1 = exp1 - (double)d / 100 + 0.9999; // select false
        }

        if (exp1 < 0)
            exp1 = 0; // return 0 if exp < 0
        if (exp2 < 0)
            exp2 = 0;
        if (exp1 > 600)
            exp1 = 600; // return 600 if exp > 600
        if (exp2 > 600)
            exp2 = 600;
        return exp1 + exp2;
    }
    else if (e1 >= 4 && e1 <= 99) // TH2 (1đ)
    {
        double temp;
        bool testNumInfo = false;
        if (e1 >= 4 && e1 <= 19) // information 1
        {
            exp2 = exp2 + (e1 / 4.0 + 19) + 0.9999;
        }
        else if (e1 >= 20 && e1 <= 49) // information 2
        {
            exp2 = exp2 + (e1 / 9.0 + 21) + 0.9999;
        }
        else if (e1 >= 50 && e1 <= 65) // information 3
        {
            exp2 = exp2 + (e1 / 16.0 + 17) + 0.9999;
        }
        else if (e1 >= 66 && e1 <= 79) // information 4
        {
            exp2 = exp2 + (e1 / 4.0 + 19) + 0.9999; // explain info 1 and continue
            if (exp2 > 200)                         // allow explain info 2
            {
                exp2 = exp2 + (e1 / 9.0 + 21) + 0.9999; // explain info 2
            }
        }
        else if (e1 >= 80 && e1 <= 99) // information 5
        {
            exp2 = exp2 + (e1 / 4.0 + 19) + 0.9999;
            // explain info 1 and continue
            exp2 = exp2 + (e1 / 9.0 + 21) + 0.9999;
            // explain info 2 and continue
            if (exp2 > 400) // allow explain info 3
            {
                testNumInfo = true;
                exp2 = exp2 + (e1 / 16.0 + 17) + 0.9999;
            }
        }
        if (testNumInfo) // if explain 3 information 1, 2, 3; point' exp2 add 15%
        {
            exp2 = 1.15 * exp2 + 0.9999;
        }
        exp1 -= e1;

        if (exp1 < 0)
            exp1 = 0; // return 0 if exp < 0
        if (exp2 < 0)
            exp2 = 0;
        if (exp1 > 600)
            exp1 = 600; // return 600 if exp > 600
        if (exp2 > 600)
            exp2 = 600;
        return exp1 + exp2;
    }
    else
        return -99;
}
// end task 1

// begin task 2
//  fuction test isPerfectSquare
bool isPerfectSquare(int n)
{
    int sqrt_n = sqrt(n);
    return sqrt_n * sqrt_n == n;
}

int nearestPerfectSquare(int n)
{
    if (isPerfectSquare(n))
        return n;

    int smaller = sqrt(n);
    int larger = smaller + 1;

    int smaller_square = smaller * smaller;
    int larger_square = larger * larger;

    if (n - smaller_square <= larger_square - n)
        return smaller_square;
    else
        return larger_square;
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (E2 < 0 || E2 > 99)
        return -99;
    else
    {
        int SM = M1; // value SM (start money)
        // road 1
        int s1 = nearestPerfectSquare(EXP1); // value s1 save nearest PerfectSquare
        double p1;
        if (EXP1 >= s1)
            p1 = 1; // p1 = 100%
        else
        {
            p1 = (1.0 * EXP1 / s1 + 80) / 123;
        }

        // road 2
        if (E2 % 2 != 0)
        {
            while (true)
            {
                // buy food
                if (HP1 < 200)
                {
                    HP1 = 1.3 * HP1 + 0.9999;
                    M1 -= 150;
                }
                else
                {
                    HP1 = 1.1 * HP1 + 0.9999;
                    M1 -= 70;
                }
                if (HP1 > 666)
                    HP1 = 666;
                else if (HP1 < 0)
                    HP1 = 0;
                if (EXP1 > 600)
                    EXP1 = 600;
                else if (EXP1 < 0)
                    EXP1 = 0;
                if (M1 > 3000)
                    M1 = 3000;
                else if (M1 < 0)
                    M1 = 0;

                if ((SM - M1) > 0.5 * SM) // số tiền đã chi trả (SM-M1) > 50% tiền ban đầu thì đi bộ
                    break;

                // rent car
                if (EXP1 < 400)
                    M1 -= 200;
                else
                    M1 -= 120;
                EXP1 = 1.13 * EXP1 + 0.9999; // exp1 of Sherlock add 13%
                if (HP1 > 666)
                    HP1 = 666;
                else if (HP1 < 0)
                    HP1 = 0;
                if (EXP1 > 600)
                    EXP1 = 600;
                else if (EXP1 < 0)
                    EXP1 = 0;
                if (M1 > 3000)
                    M1 = 3000;
                else if (M1 < 0)
                    M1 = 0;

                if ((SM - M1) > 0.5 * SM) // số tiền đã chi trả (SM-M1) > 50% tiền ban đầu thì đi bộ
                    break;

                // meet homeless people
                if (EXP1 < 300)
                    M1 -= 100;
                else if (EXP1 >= 300)
                    M1 -= 120;
                EXP1 = 0.9 * EXP1 + 0.9999; // homeless people was mistaken and exp1 minus 10%
                if (HP1 > 666)
                    HP1 = 666;
                else if (HP1 < 0)
                    HP1 = 0;
                if (EXP1 > 600)
                    EXP1 = 600;
                else if (EXP1 < 0)
                    EXP1 = 0;
                if (M1 > 3000)
                    M1 = 3000;
                else if (M1 < 0)
                    M1 = 0;

                if ((SM - M1) > 0.5 * SM) // số tiền đã chi trả (SM-M1) > 50% tiền ban đầu thì đi bộ
                    break;
            }
            HP1 = 0.83 * HP1 + 0.9999;
            EXP1 = 1.17 * EXP1 + 0.9999;

            if (HP1 > 666)
                HP1 = 666;
            else if (HP1 < 0)
                HP1 = 0;
            if (EXP1 > 600)
                EXP1 = 600;
            else if (EXP1 < 0)
                EXP1 = 0;
            if (M1 > 3000)
                M1 = 3000;
            else if (M1 < 0)
                M1 = 0;
        }
        else if (E2 % 2 == 0)
        {
            // buy food
            if (HP1 < 200 && M1 >= 0)
            {
                HP1 = 1.3 * HP1 + 0.9999;
                M1 -= 150;
            }
            else if (HP1 >= 200 && M1 >= 0)
            {
                HP1 = 1.1 * HP1 + 0.9999;
                M1 -= 70;
            }
            if (HP1 > 666)
                HP1 = 666;
            else if (HP1 < 0)
                HP1 = 0;
            if (EXP1 > 600)
                EXP1 = 600;
            else if (EXP1 < 0)
                EXP1 = 0;
            if (M1 > 3000)
                M1 = 3000;

            // rent car
            if (EXP1 < 400 && M1 >= 0)
            {
                M1 -= 200;
                EXP1 = 1.13 * EXP1 + 0.9999; // exp1 of Sherlock add 13%
            }
            else if (EXP1 >= 400 && M1 >= 0)
            {
                M1 -= 120;
                EXP1 = 1.13 * EXP1 + 0.9999; // exp1 of Sherlock add 13%
            }
            if (HP1 > 666)
                HP1 = 666;
            else if (HP1 < 0)
                HP1 = 0;
            if (EXP1 > 600)
                EXP1 = 600;
            else if (EXP1 < 0)
                EXP1 = 0;
            if (M1 > 3000)
                M1 = 3000;

            // meet homeless people
            if (EXP1 < 300 && M1 >= 0)
            {
                M1 -= 100;
                EXP1 = 0.9 * EXP1 + 0.9999; // homeless people was mistaken and exp1 minus 10%
            }
            else if (EXP1 >= 300 && M1 >= 0)
            {
                M1 -= 120;
                EXP1 = 0.9 * EXP1 + 0.9999; // homeless people was mistaken and exp1 minus 10%
            }

            if (HP1 > 666)
                HP1 = 666;
            else if (HP1 < 0)
                HP1 = 0;
            if (EXP1 > 600)
                EXP1 = 600;
            else if (EXP1 < 0)
                EXP1 = 0;
            if (M1 > 3000)
                M1 = 3000;
            // check money
            if (M1 < 0)
                M1 = 0;
            HP1 = 0.83 * HP1 + 0.9999;
            EXP1 = 1.17 * EXP1 + 0.9999;

            if (HP1 > 666)
                HP1 = 666;
            else if (HP1 < 0)
                HP1 = 0;
            if (EXP1 > 600)
                EXP1 = 600;
            else if (EXP1 < 0)
                EXP1 = 0;
            if (M1 > 3000)
                M1 = 3000;
        }

        int s2 = nearestPerfectSquare(EXP1); // value s save nearest PerfectSquare
        double p2;
        if (EXP1 >= s2)
            p2 = 1; // p1 = 100%
        else
        {
            p2 = (1.0 * EXP1 / s2 + 80) / 123;
        }

        // road3
        int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        double p3;
        if (E2 >= 0 && E2 <= 9)
        {
            p3 = 1.0 * P[E2] / 100;
        }
        else if (E2 >= 10 && E2 <= 99)
        {
            int ten = E2 / 10;        // Lấy chữ số hàng chục
            int unit = E2 % 10;       // Lấy chữ số hàng đơn vị
            int sum = ten + unit;     // Tính tổng hai chữ số
            int unitOfSum = sum % 10; // Lấy chữ số hàng đơn vị của tổng
            p3 = 1.0 * P[unitOfSum] / 100;
        }

        // check xác suất
        if (p1 == 1 && p2 == 1 && p3 == 1)
        {
            EXP1 = 0.75 * EXP1 + 0.9999; // exp1 of Sherlock minus 25%
            if (EXP1 < 0)
                EXP1 = 0;
            else if (EXP1 > 600)
                EXP1 = 600;
            if (HP1 < 0)
                HP1 = 0;
            else if (HP1 > 666)
                HP1 = 666;
            if (M1 < 0)
                M1 = 0;
            else if (M1 > 3000)
                M1 = 3000;
            return EXP1 + HP1 + M1;
        }
        else
        {
            double p = (p1 + p2 + p3) / 3;
            if (p < 0.5)
            {
                HP1 = 0.85 * HP1 + 0.9999;
                EXP1 = 1.15 * EXP1 + 0.9999;
            }
            else if (p >= 0.5)
            {
                HP1 = 0.9 * HP1 + 0.9999;
                EXP1 = 1.2 * EXP1 + 0.9999;
            }
            if (EXP1 < 0)
                EXP1 = 0;
            else if (EXP1 > 600)
                EXP1 = 600;
            if (HP1 < 0)
                HP1 = 0;
            else if (HP1 > 666)
                HP1 = 666;
            if (M1 < 0)
                M1 = 0;
            else if (M1 > 3000)
                M1 = 3000;
            return EXP1 + HP1 + M1;
        }
    }
}
// Task 3
int sumDigits(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
// hàm tính tổng các chữ số có 2 chữ số
int reduceToOneDigit(int num)
{
    while (num > 9)
    {
        num = sumDigits(num);
    }
    return num;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }
    else
    {
        double temp;
        // delcare array 2D used to save points of Taxi
        int taxi[10][10] = {0};
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                taxi[i][j] = (E3 * j + i * 2) * (i - j);
            }
        }

        // delcare array 2D used to save points of Sherlock Holms
        int SH[10][10] = {0};
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                int diagonal1 = taxi[i][j], diagonal2 = taxi[i][j];
                for (int k = -max(i, j); k < 10; ++k)
                {
                    // Tính giá trị trên đường chéo trái
                    if (i + k < 10 && i + k >= 0 && j + k < 10 && j + k >= 0)
                        diagonal1 = max(diagonal1, taxi[i + k][j + k]);

                    // Tính giá trị trên đường chéo phải
                    if (i + k < 10 && i + k >= 0 && j - k >= 0 && j - k < 10)
                        diagonal2 = max(diagonal2, taxi[i + k][j - k]);
                }
                // Lưu giá trị lớn nhất của 2 đường chéo vào ma trận B
                SH[i][j] = max(diagonal1, diagonal2);
            }
        }

        // function find point where Sherlock detect Taxi
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                if (taxi[i][j] > 2 * E3)
                    count1++;
                if (taxi[i][j] < -E3)
                    count2++;
            }
        }
        if (count1 > 9)
            count1 = reduceToOneDigit(count1);
        if (count2 > 9)
            count2 = reduceToOneDigit(count2);

        if (abs(taxi[count1][count2]) > abs(SH[count1][count2])) // not detected
        {
            EXP1 = 0.88 * EXP1 + 0.9999; // minus exp and hp
            HP1 = 0.9 * HP1 + 0.9999;

            EXP2 = 0.88 * EXP2 + 0.9999;
            HP2 = 0.9 * HP2 + 0.9999;

            if (EXP1 < 0)
                EXP1 = 0;
            else if (EXP1 > 600)
                EXP1 = 600;
            if (HP1 < 0)
                HP1 = 0;
            else if (HP1 > 666)
                HP1 = 666;

            if (EXP2 < 0)
                EXP2 = 0;
            else if (EXP2 > 600)
                EXP2 = 600;
            if (HP2 < 0)
                HP2 = 0;
            else if (HP2 > 666)
                HP2 = 666;

            return taxi[count1][count2];
        }
        else // detected
        {
            EXP1 = 1.12 * EXP1 + 0.9999; // add exp and hp
            HP1 = 1.1 * HP1 + 0.9999;

            EXP2 = 1.12 * EXP2 + 0.9999;
            HP2 = 1.1 * HP2 + 0.9999;

            if (EXP1 < 0)
                EXP1 = 0;
            else if (EXP1 > 600)
                EXP1 = 600;
            if (HP1 < 0)
                HP1 = 0;
            else if (HP1 > 666)
                HP1 = 666;

            if (EXP2 < 0)
                EXP2 = 0;
            else if (EXP2 > 600)
                EXP2 = 600;
            if (HP2 < 0)
                HP2 = 0;
            else if (HP2 > 666)
                HP2 = 666;

            return SH[count1][count2];
        }
    }
}

// task 4
//  function get se
string se(const char *email)
{
    string str;
    for (int i = 0; i < strlen(email); ++i)
    {
        if (email[i] != '@')
        {
            str.push_back(email[i]);
        }
        else
            break;
    }
    return str;
}

int checkPassword(const char *s, const char *email)
{
    // độ dài
    if (strlen(s) < 8)
    {
        return -1; // độ dài mk < 8
    }
    else if (strlen(s) > 20)
    {
        return -2; // độ dài mk > 20
    }

    // chuỗi con
    string temp = se(email);
    size_t found = string(s).find(temp); // Tạo đối tượng string từ chuỗi const char *
    if (found != string::npos)
    {
        return -(300 + found); // mk chứa tên của gmail
    }

    // chuỗi trùng liên tiếp
    int sci = -1;
    for (int i = 0; i < strlen(s) - 2; ++i)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            sci = i;
            break;
        }
    }
    if (sci != -1)
    {
        return -(400 + sci); // chuỗi mk có nhiều hơn 2 kí tự trùng nhau liên tiếp
    }

    // kí tự đặc biệt
    bool checkchar = false;
    for (int i = 0; i < strlen(s); ++i)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            checkchar = true;
            break;
        }
    }
    if (!checkchar)
    {
        return -5; // không có kí tự đặc biệt
    }

    // ngoài kí tự thông thường
    for (int i = 0; i < strlen(s); ++i)
    {
        if (!((s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))
        {
            return i; // chuỗi mk có kí tự nằm ngoài những kí tự đã quy định
        }
    }
    return -10; // mật khẩu đúng
}
// end task 4

// Task 5
bool compareConstChar(const char *str1, const char *str2)
{
    // Using strcmp() for full comparison
    int cmp = strcmp(str1, str2);
    return cmp == 0;
}

int findCorrectPassword(const char *arr_pwds[], int num_pwds) // hàm tìm số lượng mật khẩu giống nhau trong mảng
{
    int a[100];
    int max = 0;
    int index = 0;
    int count;
    for (int i = 0; i < num_pwds; i++) // tìm lần xuất hiện của các mật khẩu
    {
        count = 0;
        for (int j = i + 1; j < num_pwds; j++)
        {
            if (compareConstChar(arr_pwds[i], arr_pwds[j]))
            {
                a[j] = 0;
                count++;
            }
        }
        a[i] = count;
    }
    for (int i = 0; i < num_pwds; ++i) // tìm mật khẩu có số lần xuất hiện lớn nhất
    {
        if (a[i] > max)
        {
            max = a[i];
            index = i;
        }
    }
    const char *save = arr_pwds[index];
    for (int i = index + 1; i < num_pwds; ++i)
    {
        if (strlen(save) < strlen(arr_pwds[i]) && max == a[i])
        {
            index = i;
            save = arr_pwds[i];
        }
    }
    return index;
}
