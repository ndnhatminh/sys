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

// Task 1
int round_upper(float num){
    int result;
    result = num + 0.9999;
    return result;
}
void rescale_EXP(int &EXP)
{
    if (EXP > 600)
        EXP = 600;
    if (EXP < 0)
        EXP = 0;
}
void rescale_HP(int &HP)
{
    if (HP > 666)
        HP = 666;
    if (HP < 0)
        HP = 0;
}
void rescale_Money(int &M)
{
    if (M > 3000)
        M = 3000;
    if (M < 0)
        M = 0;
}
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    rescale_EXP(exp1);
    rescale_EXP(exp2);
    if (0 <= e1 && e1 <= 3)
    {
        if (e1 == 0)
            exp2 += 29;
        else if (e1 == 1)
            exp2 += 45;
        else if (e1 == 2)
            exp2 += 75;
        else if (e1 == 3)
            exp2 += (29 + 45 + 75);
        rescale_EXP(exp2);
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 = round_upper(exp1 + D / 200.0f);
        }
        else
        {
            exp1 = round_upper(exp1 - D / 100.0f);
        }
        rescale_EXP(exp1);
    }

    // trường hợp 2
    else if (4 <= e1 && e1 <= 99)
    {
        if (4 <= e1 && e1 <= 19)
        {
            exp2 = round_upper(e1 / 4.0f + 19 + exp2); // thông tin 1
        }
        else if (e1 >= 20 && e1 <= 49)
            exp2 = round_upper(e1 / 9.0f + 21 + exp2); // thông tin 2
        else if (e1 >= 50 && e1 <= 65)
            exp2 = round_upper(e1 / 16.0f + 17 + exp2); // thông tin 3
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 = round_upper(e1 / 4.0f + 19 + exp2);
            rescale_EXP(exp2);
            if (exp2 > 200)
                exp2 = round_upper(e1 / 9.0f + 21 + exp2);
            rescale_EXP(exp2);
        }
        else
        {
            exp2 = round_upper((e1 / 9.0f + 21) + exp2);
            exp2 = round_upper((e1 / 4.0f + 19) + exp2);
            rescale_EXP(exp2);
            if (exp2 > 400)
            {
                exp2 = round_upper((e1 / 16.0f) + 17 + exp2);
                exp2 = round_upper(exp2 * 1.15f);
            }
        }
        exp1 -= e1;
        rescale_EXP(exp1);
    }
    else
        return -99;
    // căn chỉnh lại giá trị exp1 và exp2
    rescale_EXP(exp1);
    rescale_EXP(exp2);
    return exp1 + exp2;
}

// Task 2
int nearest_square(int num)
{
    return round(sqrt(num)) * round(sqrt(num));
}
int calculate_i(int num)
{
    int iVal = 0; // giá trị của i trong con đường 3
    while (num > 0)
    {
        iVal += num % 10;
        num /= 10;
    }
    return iVal % 10;
}
double con_duong_3(int E2)
{
    double P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = calculate_i(E2);
    double P3 = P[i];
    return P3 / 100.0f;
}
void buy_stuff(int &HP, int &M1)
{
    if (HP < 200)
    {
        HP = round_upper(HP * 1.3f);
        M1 -= 150;
    }
    else
    {
        HP = round_upper(HP * 1.1f);
        M1 -= 70;
    }
    rescale_HP(HP);
    rescale_Money(M1);
}
void use_transportation(int &EXP, int &M1)
{
    if (EXP < 400) // đi taxi
    {
        M1 -= 200;
        EXP = round_upper(EXP * 1.13f);
    }
    else // đi ngựa
    {
        M1 -= 120;
        EXP = round_upper(EXP * 1.13f);
    }
    rescale_EXP(EXP);
    rescale_Money(M1);
}
void meet_homeless(int &EXP, int &M)
{
    if (EXP < 300)
    {
        M -= 100;
        EXP = round_upper(EXP * 0.9f);
    }
    else
    {
        M -= 120;
        EXP = round_upper(EXP * 0.9f);
    }
    rescale_EXP(EXP);
    rescale_Money(M);
}
double calculate_P2(int &EXP1, int &HP1)
{
    HP1 = round_upper(HP1 * 0.83f);
    EXP1 = round_upper(EXP1 * 1.17f);
    rescale_EXP(EXP1);
    rescale_HP(HP1);
    if (EXP1 >= nearest_square(EXP1))
        return 1;
    return (EXP1 / nearest_square(EXP1) + 80) / 123.0;
}
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    rescale_EXP(EXP1);
    rescale_HP(HP1);
    rescale_Money(M1);
    if(E2 < 0 || E2 > 99)
        return -99;
    double P[3] = {0, 0, 0};
    // con đường 1
    int S = nearest_square(EXP1);
    if (EXP1 >= S)
        P[0] = 1;
    else
        P[0] = (EXP1 / S + 80) / 123.0;
    // con đường 2
    int initM1 = M1; // số tiền trước khi đi vào con đường 2
    if (M1 == 0)
    {
        P[1] = calculate_P2(EXP1, HP1);
        P[2] = con_duong_3(E2);
    }
    else
    {
        if (E2 % 2 != 0)
        {
            while (true)
            {
                buy_stuff(HP1, M1);
                if (M1 < (initM1 / 2.0f))
                {
                    P[1] = calculate_P2(EXP1, HP1);
                    P[2] = con_duong_3(E2);
                    break;
                }
                use_transportation(EXP1, M1);
                if (M1 < (initM1 / 2.0f))
                {
                    P[1] = calculate_P2(EXP1, HP1);
                    P[2] = con_duong_3(E2);
                    break;
                }
                meet_homeless(EXP1, M1);
                if (M1 < (initM1 / 2.0f))
                {
                    P[1] = calculate_P2(EXP1, HP1);
                    P[2] = con_duong_3(E2);
                    break;
                }
            }
        }
        else if (E2 % 2 == 0)
        {
            if (M1 > 0)
            {
                buy_stuff(HP1, M1);
            }
            if (M1 > 0)
            {
                use_transportation(EXP1, M1);
            }
            if (M1 > 0)
            {
                meet_homeless(EXP1, M1);
            }
            P[1] = calculate_P2(EXP1, HP1);
            P[2] = con_duong_3(E2);
        }
    }

    double average = (P[0] + P[1] + P[2]) / 3.0;
    if ((P[0] == 1.0) && (P[1] == 1.0) && (P[2] == 1.0))
    {
        EXP1 = round_upper(EXP1 * 0.75f);
    }
    else
    {
        if (average < 0.5)
        {
            HP1 = round_upper(HP1 * 0.85f);
            EXP1 = round_upper(EXP1 * 1.15f);
        }
        else
        {
            HP1 = round_upper(HP1 * 0.9f);
            EXP1 = round_upper(EXP1 * 1.2f);
        }
    }
    rescale_HP(HP1);
    rescale_EXP(EXP1);
    rescale_Money(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int sum_of_digit(int num)
{
    int sum = 0;
    while (num != 0)
    {
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}
int find_max(int arr[10])
{
    int maxVal = arr[0]; // Giả sử phần tử đầu tiên là lớn nhất
    for (int idx = 1; idx < 10; idx++)
    {
        if (arr[idx] > maxVal)
        {
            maxVal = arr[idx]; // Cập nhật giá trị lớn nhất
        }
    }
    return maxVal;
}
int find_max_in_all_diagnal(int Taxi[10][10], int i, int j)
{

    int start_row = i, start_col = j;
    int L_arr_end_row = i, L_arr_end_col = j, L_arr_start_row = i, L_arr_start_col = j;
    while ((i > 0) && (j > 0))
    {
        L_arr_start_row = i - 1;
        L_arr_start_col = j - 1;
        i--;
        j--;
    }
    i = start_row, j = start_col;
    while ((i < 10) && (j < 10))
    {
        L_arr_end_col = j;
        L_arr_end_row = i;
        i++;
        j++;
    }
    // tìm đường chéo phải
    int R_arr_end_row = i, R_arr_end_col = j, R_arr_start_row = i, R_arr_start_col = j;
    i = start_row, j = start_col;
    while ((i >= 0) && (j < 10))
    {
        R_arr_start_row = i;
        R_arr_start_col = j;
        j++;
        i--;
    }
    i = start_row, j = start_col;
    while ((i < 10) && (j > 0))
    {
        R_arr_end_row = i + 1;
        R_arr_end_col = j - 1;
        i++;
        j--;
    }
    int L[10];
    int R[10];
    for (int i = 0; i < 10; i++)
    {
        L[i] = -999999;
        R[i] = -999999;
    }
    int maxL = L[0];
    int maxR = R[0];
    // phần tử đường chéo trái
    int idx = 0;
    int start_i = L_arr_start_row;
    int start_j = L_arr_start_col;
    while ((start_i <= L_arr_end_col) && (start_j <= L_arr_end_col))
    {
        L[idx] = Taxi[start_i][start_j];
        start_i++;
        start_j++;
        idx++;
    }
    idx = 0;
    start_i = R_arr_start_row;
    start_j = R_arr_start_col;
    while ((start_i <= R_arr_end_row) && (start_j >= R_arr_end_col))
    {
        R[idx] = Taxi[start_i][start_j];
        start_i++;
        start_j--;
        idx++;
    }
    maxL = find_max(L);
    maxR = find_max(R);
    if (maxR >= maxL)
    {
        return maxR;
    }
    return maxL;
};
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    rescale_EXP(EXP1); rescale_EXP(EXP2);
    rescale_HP(HP1); rescale_HP(HP2);
    if (E3 < 0 || E3 > 99)
        return -99;
    int Taxi[10][10];
    int watson[10][10];
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            Taxi[row][col] = ((E3 * col) + (row * 2)) * (row - col);
        }
    }
    // điểm của watson
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            watson[row][col] = find_max_in_all_diagnal(Taxi, row, col);
        }
    }
    int i = 0;
    int j = 0;
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            if (Taxi[row][col] > (2 * E3))
                i++;
            if (Taxi[row][col] < (-E3))
                j++;
        }
    }

    while ((i > 9) || (j > 9))
    {
        i = sum_of_digit(i);
        j = sum_of_digit(j);
    }

    if (abs(find_max_in_all_diagnal(Taxi, i, j)) >= abs(Taxi[i][j]))
    {
        EXP1 = round_upper(EXP1 * 1.12f);
        HP1 = round_upper(HP1 * 1.1f);
        EXP2 = round_upper(EXP2 * 1.12f);
        HP2 = round_upper(HP2 * 1.1f);
        rescale_EXP(EXP1);
        rescale_EXP(EXP2);
        rescale_HP(HP1);
        rescale_HP(HP2);
        return abs(find_max_in_all_diagnal(Taxi, i, j));
    }
    else
    {
        EXP1 = round_upper(EXP1 * 0.88f);
        HP1 = round_upper(HP1 * 0.9f);
        EXP2 = round_upper(EXP2 * 0.88f);
        HP2 = round_upper(HP2 * 0.9f);
        rescale_EXP(EXP1);
        rescale_EXP(EXP2);
        rescale_HP(HP1);
        rescale_HP(HP2);
        return Taxi[i][j];
    }
    return -1;
}

// Task 4
int find_ch(const char *s, char ch)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ch)
            return i;
    }
    return -1;
}
bool is_alpha(char ch)
{
    bool isCaptital = ((65 <= ch) && (ch <= 90)); // trên bảng mã ascii thì chữ hoa ứng với số thứ tự 75 -> 90
    bool isSmall = ((97 <= ch) && (ch <= 122));   // trên bảng mã ascii thì chữ hoa ứng với số thứ tự 97 -> 122
    if (isCaptital || isSmall)
        return true;
    return false;
}
bool is_digit(char ch)
{
    if (48 <= ch && ch <= 57)
        return true;
    return false;
}
bool isValid_special_char(char ch)
{ // kiểm tra kí tự đặc biệt có được cho phép hay không
    char special_ch_permmited[5] = {'@', '#', '$', '%', '!'};
    for (int i = 0; i < 5; i++)
    {
        if (ch == special_ch_permmited[i])
            return true;
    }
    return false;
}
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    std::string se = {};
    std::string copied_s = s;
    int digit_count = 0;
    int valid_special_ch = 0;
    for (int i = 0; i < find_ch(email, '@'); i++)
        se += email[i];
    // kiểm tra độ dài mật khẩu
    if (strlen(s) > 20) // 20 là độ dài tối đa của mật khẩu
        return -2;
    else if (strlen(s) < 8) // 8 là độ dài tối thiểu của mật khẩu
        return -1;
    // kiểm tra mật khẩu có kí tự đặc biệt hay không
    for (int idx = 0; idx < strlen(s); idx++)
    {
        if (isValid_special_char(s[idx]))
            valid_special_ch++;
    }
    for (int i = 0; i < strlen(s); ++i)
    {
        if (copied_s.find(se) != -1)
        {
            return 0 - (300 + copied_s.find(se));
        }
        else if ((s[i] == s[i + 1]) && (s[i] == s[i + 2]))
            return -(400 + i);
    }
    if (valid_special_ch == 0)
        return -5;
    for (int i = 0; i < strlen(s); i++)
    {
        if (!(is_digit(s[i]) || is_alpha(s[i])))
        {
            if (isValid_special_char(s[i]) == false)
                return i;
        }
    }

    return -10;
    return -99;
}

// Task 5
int find_str(const char *arr[], const char *ele, int number_element)
{
    for (int i = 0; i < number_element; i++)
    {
        if (strcmp(arr[i], ele) == 0)
        {
            return i;
        }
    }
    return -1;
}
int count_str(const char *arr[], const char *ele, int n = 3000)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (strcmp(arr[i], ele) == 0)
        {
            count++;
        }
    }
    return count;
}
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int max_fre = count_str(arr_pwds, arr_pwds[0], num_pwds);
    for (int i = 0; i < num_pwds; i++)
    {
        if (count_str(arr_pwds, arr_pwds[i], num_pwds) > max_fre)
        {
            max_fre = count_str(arr_pwds, arr_pwds[i], num_pwds);
        }
    }
    const char *max_fre_pass[300];
    int length = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        if (count_str(arr_pwds, arr_pwds[i], num_pwds) == max_fre)
        {
            max_fre_pass[length] = arr_pwds[i];
            length++;
        }
    }
    int maxlength = strlen(max_fre_pass[0]);
    for (int idx = 0; idx < length; idx++)
    {
        if (strlen(max_fre_pass[idx]) > maxlength)
        {
            maxlength = strlen(max_fre_pass[idx]);
        }
    }
    for (int i = 0; i < length; i++)
    {
        if (strlen(max_fre_pass[i]) == maxlength)
        {
            return find_str(arr_pwds, max_fre_pass[i], num_pwds);
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////