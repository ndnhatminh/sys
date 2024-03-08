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
#define ceil(double) ceil(float(double)) // Ép kiểu double trong ceil thành float
// Limit EXP (limit the exp in range between 0 and 600)
int lm_exp(int exp)
{
    if (exp > 600)
    {
        exp = 600;
    }
    else if (exp < 0)
    {
        exp = 0;
    }
    else
    {
        exp = exp;
    }
    return exp;
}

// Limit HP
int lm_hp(int hp)
{
    if (hp > 666)
    {
        hp = 666;
    }
    else if (hp < 0)
    {
        hp = 0;
    }
    else
    {
        hp = hp;
    }
    return hp;
}

// Limit M
int lm_m(int m)
{
    if (m > 3000)
    {
        m = 3000;
    }
    else if (m < 0)
    {
        m = 0;
    }
    else
    {
        m = m;
    }
    return m;
}

// Calculate percentage
double cal_percent(int EXP1)
{
    double can_EXP1, P, S;
    can_EXP1 = round(sqrt(EXP1));
    S = can_EXP1*can_EXP1;

    if (EXP1 >= S)
    {
        P = 1;
    }
    else
    {
        P = ((EXP1 / S) + 80) / 123.0;
    }

    // Round percentage
    P = round(P * 100) / 100;
    return P;
}

// Find max number in crossline
int max_cl_number(int h[10][10], int x, int y)
{
    int max_num = h[x][y];

    // Left and above crossline
    for (int i = x, k = y; i >= 0 && k >= 0; --i, --k)
    {

        if (h[i][k] >= max_num)
        {
            max_num = h[i][k];
        }
    }

    // Right and above crossline
    for (int i = x, k = y; i >= 0 && k <= 9; --i, ++k)
    {
        
        if (h[i][k] >= max_num)
        {
            max_num = h[i][k];
        }
    }

    // Right and under
    for (int i = x, k = y; i <= 9 && k >= 0; ++i, --k)
    {
        
        if (h[i][k] >= max_num)
        {
            max_num = h[i][k];
        }
    }

    // Left and under
    for (int i = x, k = y; i <= 9 && k <= 9; ++i, ++k)
    {
        
        if (h[i][k] >= max_num)
        {
            max_num = h[i][k];
        }
    }

    return max_num;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    int D;
    //Limit at the beggining
    exp1 = lm_exp(exp1);
    exp2 = lm_exp(exp2);

    // 1st case
    if (e1 == 0){
        exp2 += 29;
    }
    else if (e1 == 1){
        exp2 += 45;
    }
    else if (e1 == 2){
        exp2 += 75;
    }
    else if (e1 == 3){
        exp2 = exp2 + 29 + 45 + 75;
    }
    // 2nd case
    else if (e1 >= 4 && e1 <= 19){
        exp2 += ceil((e1 / 4.0)) + 19;
    }
    else if (e1 >= 20 && e1 <= 49){
        exp2 += ceil((e1 / 9.0)) + 21;
    }
    else if (e1 >= 50 && e1 <= 65){
        exp2 += ceil(e1 / 16.0) + 17;
    }
    else if (e1 >= 66 && e1 <= 79)
    {
        exp2 += ceil(e1 / 4.0) + 19;
        if (exp2 > 200){
            exp2 += ceil((e1 / 9.0)) + 21;
        }
    }
    else if (e1 >= 80 && e1 <= 99)
    {
        exp2 += ceil(e1 / 4.0) + 19 + ceil(e1 / 9.0) + 21;
        if (exp2 > 400)
        {
            exp2 += ceil(e1 / 16.0) + 17;
            exp2 += ceil((exp2 * 15) / 100.0);
        }
    }
    else
        return -99;

    exp2 = lm_exp(exp2);

    D = e1 * 3 + exp1 * 7;
    // 1st case
    if (e1 >= 0 && e1 <= 3)
    {
        if (D % 2 == 0)
        {
            exp1 = ceil(exp1 + (D / 200.0));
        }
        else
            exp1 = ceil(exp1 - (D / 100.0));
    }
    // 2nd case
    else
        exp1 -= e1;
    exp1 = lm_exp(exp1);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    // Limit at the beginning
    double P1, P2, P3, P_tb, h_M1 = M1 / 2;
    double P[10] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    int i;
    HP1 = lm_hp(HP1);
    EXP1 = lm_exp(EXP1);
    M1 = lm_m(M1);
    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }
    else
    {
        // Road 1
        P1 = cal_percent(EXP1);

        // Road 2
        // E2 is an odd
        if (E2 % 2 != 0)
        {
            int m = 0;

            while (m <= h_M1)
            {
                // Event 1
                if (HP1 < 200)
                {
                    HP1 = ceil(HP1 * 1.3);
                    HP1 = lm_hp(HP1);
                    m += 150;

                    if (m > M1 / 2)
                    {
                        break;
                    }

                }
                else
                {
                    HP1 = ceil(HP1 * 1.1);
                    m += 70;
                    HP1 = lm_hp(HP1);

                    if (m > M1 / 2)
                    {
                        break;
                    }
                }

                
                // Event 2
                if (EXP1 < 400)
                {
                    m += 200;
                    EXP1 = ceil(EXP1 * 1.13);
                    EXP1 = lm_exp(EXP1);

                    if (m > M1 / 2)
                    {
                        break;
                    }
                }
                else
                {
                    m += 120;
                    EXP1 = ceil(EXP1 * 1.13);
                    EXP1 = lm_exp(EXP1);

                    if (m > M1 / 2)
                    {
                        break;
                    }
                }   
                // Event 3
                if (EXP1 < 300)
                {
                    m += 100;
                    EXP1 = ceil(EXP1 * 0.9);
                    EXP1 = lm_hp(EXP1);
                    
                }
                else
                {
                    m += 120;
                    EXP1 = ceil(EXP1 * 0.9);
                    EXP1 = lm_hp(EXP1);

                    
                }
            }
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);

            HP1 = lm_hp(HP1);
            EXP1 = lm_exp(EXP1);

            M1 -= m;
            M1 = lm_m(M1);
        }
        // E2 is an even
        if (E2 % 2 == 0)
        {
            if (M1 == 0) {
                HP1 = ceil(HP1 * 0.83);
                EXP1 = ceil(EXP1 * 1.17);

                HP1 = lm_hp(HP1);
                EXP1 = lm_exp(EXP1);
            }
            // Event 1
            if (HP1 < 200 && M1 > 0)
            {
                HP1 = ceil(HP1 * 1.3);
                M1 -= 150;

                HP1 = lm_hp(HP1);
                M1 = lm_m(M1);

                if (M1 == 0)
                {
                    HP1 = ceil(HP1 * 0.83);
                    EXP1 = ceil(EXP1 * 1.17);

                    HP1 = lm_hp(HP1);
                    EXP1 = lm_exp(EXP1);
                }
            }
            else if (HP1 >= 200 && M1 > 0)
            {
                HP1 = ceil(HP1 * 1.1);
                M1 -= 70;

                HP1 = lm_hp(HP1);
                M1 = lm_m(M1);

                if (M1 == 0)
                {
                    HP1 = ceil(HP1 * 0.83);
                    EXP1 = ceil(EXP1 * 1.17);

                    HP1 = lm_hp(HP1);
                    EXP1 = lm_exp(EXP1);
                }
            }

            // Event 2
            if (EXP1 < 400 && M1 > 0)
            {
                M1 -= 200;
                EXP1 = ceil(EXP1 * 1.13);

                M1 = lm_m(M1);
                EXP1 = lm_exp(EXP1);

                if (M1 == 0)
                {
                    HP1 = ceil(HP1 * 0.83);
                    EXP1 = ceil(EXP1 * 1.17);

                    HP1 = lm_hp(HP1);
                    EXP1 = lm_exp(EXP1);
                }
            }
            else if (EXP1 >= 400 && M1 > 0)
            {
                M1 -= 120;
                EXP1 = ceil(EXP1 * 1.13);

                M1 = lm_m(M1);
                EXP1 = lm_exp(EXP1);

                if (M1 == 0)
                {
                    HP1 = ceil(HP1 * 0.83);
                    EXP1 = ceil(EXP1 * 1.17);

                    HP1 = lm_hp(HP1);
                    EXP1 = lm_exp(EXP1);
                }
            }

            // Event 3
            if (EXP1 < 300 && M1 > 0)
            {
                M1 -= 100;
                EXP1 = ceil(EXP1 * 0.9);
                
                HP1 = ceil(HP1 * 0.83);
                EXP1 = ceil(EXP1 * 1.17);

                M1 = lm_m(M1);
                HP1 = lm_hp(HP1);
                EXP1 = lm_exp(EXP1);
            }
            else if (EXP1 >= 300 && M1 > 0)
            {
                M1 -= 120;
                EXP1 = ceil(EXP1 * 0.9);

                HP1 = ceil(HP1 * 0.83);
                EXP1 = ceil(EXP1 * 1.17);

                M1 = lm_m(M1);
                HP1 = lm_hp(HP1);
                EXP1 = lm_exp(EXP1);
            }
            // At the end of Road 2
        }
        P2 = cal_percent(EXP1);

        // Road 3
        if (E2 < 10)
        {
            i = E2;
        }
        else
        {
            int chuc, dvi, sum_chuc_dvi;
            chuc = E2 / 10;
            dvi = E2 % 10;
            sum_chuc_dvi = chuc + dvi;
            i = sum_chuc_dvi % 10;
        }
        P3 = P[i];

        // Check percentage of finding luggage on three road
        if (P1 == 1 && P2 == 1 && P3 == 1)
        {
            EXP1 = ceil(EXP1 * 0.75);

            EXP1 = lm_exp(EXP1);
        }
        else
        {
            P_tb = round(((P1 + P2 + P3) / 3) * 100) / 100;

            if (P_tb < 0.5)
            {
                HP1 = ceil(HP1 * 0.85);
                EXP1 = ceil(EXP1 * 1.15);

                HP1 = lm_hp(HP1);
                EXP1 = lm_exp(EXP1);
            }
            else
            {
                HP1 = ceil(HP1 * 0.9);
                EXP1 = ceil(EXP1 * 1.2);

                HP1 = lm_hp(HP1);
                EXP1 = lm_exp(EXP1);
            }
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    int m[10][10], h[10][10];
    int x = 0, y = 0;

    // Create matrix for taxi
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            m[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    
    // Create matrix for H and W
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            h[j][i] = max_cl_number(m, j, i);

            if (h[j][i] < 0)
            {
                h[j][i] = h[j][i] * (-1);
            }
        }
    }

    // face-to-face
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {

            if (m[i][j] > E3 * 2)
                x += 1;
            else if (m[i][j] < -E3)
                y += 1;
        }
    }

    // Check if x or y are bigger than 10
    for (x; x >= 10; x = (x / 10) + (x % 10))
    {
        x = x;
    }

    for (y; y >= 10; y = (y / 10) + (y % 10))
    {
        y = y;
    }

    // Check if H and W could catch the taxi
    int p = m[x][y];
    int bigger_num;
    if (p < 0)
    {
        p = p * (-1);
    }
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }
    else if (p > h[x][y])
    {

        HP1 = ceil(HP1 * 0.9);
        EXP1 = ceil(EXP1 * 0.88);
        HP2 = ceil(HP2 * 0.9);
        EXP2 = ceil(EXP2 * 0.88);

        HP1 = lm_hp(HP1);
        EXP1 = lm_exp(EXP1);
        HP2 = lm_hp(HP2);
        EXP2 = lm_exp(EXP2);

        bigger_num = m[x][y];
    }
    else
    {

        HP1 = ceil(HP1 * 1.1);
        EXP1 = ceil(EXP1 * 1.12);
        HP2 = ceil(HP2 * 1.1);
        EXP2 = ceil(EXP2 * 1.12);

        HP1 = lm_hp(HP1);
        EXP1 = lm_exp(EXP1);
        HP2 = lm_hp(HP2);
        EXP2 = lm_exp(EXP2);

        bigger_num = h[x][y];
    }
    return bigger_num;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    // Check the length of s
    int length = 0;

    while (s[length] != '\0')
    {
        length += 1;
    }

    if (length < 8)
    {
        return -1; // Shorter than the shortest
    }

    if (length > 20)
    {
        return -2; // Longer than the longest
    }

    // Check if s contain se
    int email_length = 0;

    while (email[email_length] != '@')
    {
        email_length += 1;
    }

    for (int i = 0; i <= length - email_length; ++i)
    {
        int m = 0;
        for (int j = 0; j < email_length; ++j)
        {

            if (s[i + j] == email[j])
            { // Check xem nó giống nguyên một từ hay chỉ giống 1 chữ
                m += 1;
            }

            if (m == email_length)
            {
                break;
            }
        }

        if (m == email_length)
        {
            return -(300 + i);
        }
    }

    // Check if it has more than two doubled-char (EX: nn, mm, ww,...)
    for (int i = 0; i < length - 2; ++i)
    {

        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            return -(400 + i);
        }
    }

    // Check special char in s
    bool has_special_char = false;

    for (int i = 0; i < length; ++i)
    {

        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            has_special_char = true;
            break;
        }
    }

    if (!has_special_char)
    {
        return -5;
    }

    // Check if every char is valid
    for (int i = 0; i < length; ++i)
    {
        if (!((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90) ||
              (s[i] >= 48 && s[i] <= 57) || s[i] == 35 || s[i] == 36 ||
              s[i] == 37 || s[i] == 64 || s[i] == 33))
        {
            return i;
        }
    }

    return -10; // Return if password is valid
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int max_count = 0;
    int max_length = 0;
    int max_index = -1;

    for (int i = 0; i < num_pwds; ++i)
    {
        const char *pwd = arr_pwds[i];
        int count = 0;
        int length = strlen(pwd);

        for (int j = 0; j < num_pwds; ++j)
        {

            if (strcmp(arr_pwds[j], pwd) == 0)
            { // Compare pwd with every string in arr
                count++;
            }
        }
        if (count > max_count || (count == max_count && length > max_length))
        {
            max_count = count;
            max_length = length;
            max_index = i;
        }
    }

    return max_index;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////