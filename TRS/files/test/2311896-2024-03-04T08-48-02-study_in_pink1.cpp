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
int check_value(int n, int start, int end)
{
    if (n < start)
        n = start;
    else if (n > end)
        n = end;
    return n;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) 
{
    if (e1 < 0 || e1 > 99)
        return -99;

    float t_exp1 = exp1, t_exp2 = exp2;
    int d, start = 0, end = 600;
    const float inf_1 = e1 * 1.0 / 4 + 19, inf_2 = e1 * 1.0 / 9 + 21, inf_3 = e1 * 1.0 / 16 + 17;

    t_exp1 = check_value(t_exp1, start, end);
    t_exp2 = check_value(t_exp2, start, end);

    if (e1 <= 3)
    {
        if (e1 == 0)
            t_exp2 += 29;
        else if (e1 == 1)
            t_exp2 += 45;
        else if (e1 == 2)
            t_exp2 += 75;
        else if (e1 == 3)
            t_exp2 += 149;
        d = e1 * 3 + t_exp1 * 7;
        if (d % 2 == 0)
            t_exp1 += d * 1.0 / 200;

        else
            t_exp1 -= d * 1.0 / 100;
        t_exp1 = ceil(t_exp1);
    }
    else
    {
        if (e1 >= 4 && e1 <= 19)
        {
            t_exp2 += inf_1;
            t_exp2 = ceil(t_exp2);
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            t_exp2 += inf_2;
            t_exp2 = ceil(t_exp2);
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            t_exp2 += inf_3;
            t_exp2 = ceil(t_exp2);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            t_exp2 += inf_1;
            t_exp2 = ceil(t_exp2);
            if (t_exp2 > 200)
            {
                t_exp2 += inf_2;
                t_exp2 = ceil(t_exp2);
            }
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            t_exp2 += inf_1;
            t_exp2 = ceil(t_exp2);
            t_exp2 += inf_2;
            t_exp2 = ceil(t_exp2);
            if (t_exp2 > 400)
            {
                t_exp2 += inf_3;
                t_exp2 = ceil(t_exp2);
                t_exp2 += t_exp2 * 15 / 100;
                t_exp2 = ceil(t_exp2);
            }
        }
        t_exp1 -= e1;
    }

    exp1 = check_value(ceil(t_exp1), start, end);
    exp2 = check_value(t_exp2, start, end);
    return exp1 + exp2;
}

// Task 2
float square_num(float exp1)
{
    float s1, s2, num, pp;
    s1 = round(sqrt(exp1) - 0.5) * round(sqrt(exp1) - 0.5);
    s2 = ceil(sqrt(exp1)) * ceil(sqrt(exp1));
    if (abs(exp1 - s1) < abs(exp1 - s2))
        num = s1;
    else
        num = s2;
    if (exp1 >= num)
        pp = 1.0;
    else
        pp = (exp1 / num + 80) / 123;
    return pp;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) 
{

    if (E2 < 0 || E2 > 99)
        return -99;

    int t_exp1 = EXP1, t_hp1 = HP1;
    float p1, p2, p3, s, p;
    int t_m1 = M1;
    int e_start = 0, e_end = 600, h_start = 0, h_end = 666, m_start = 0, m_end = 3000;
    int half_m1 = M1 * 0.5;
    int tien_da_chi = 0;

    t_exp1 = check_value(t_exp1, e_start, e_end);
    t_hp1 = check_value(t_hp1, h_start, h_end);
    t_m1 = check_value(t_m1, m_start, m_end);

    // con duong 1

    p1 = (square_num(t_exp1));
    //con duong 2
    if (E2 % 2 == 1)
    {
        if (t_m1 != 0)
        {
            while (true)
            {
                if (t_hp1 < 200)
                {
                    t_hp1 = ceil(t_hp1 * 1.3);
                    t_m1 -= 150;
                    tien_da_chi += 150;
                }
                else
                {
                    t_hp1 = ceil(t_hp1 * 1.1);
                    t_m1 -= 70;
                    tien_da_chi += 70;
                }
                t_hp1 = check_value(t_hp1, h_start, h_end);
                t_m1 = check_value(t_m1, m_start, m_end);
                if (tien_da_chi > half_m1)
                    break;

                if (t_exp1 < 400)
                {
                    t_exp1 = ceil(t_exp1 * 1.13);
                    t_m1 -= 200;
                    tien_da_chi += 200;
                }
                else
                {
                    t_exp1 = ceil(t_exp1 * 1.13);
                    t_m1 -= 120;
                    tien_da_chi += 120;
                }
                t_exp1 = check_value(t_exp1, e_start, e_end);
                t_m1 = check_value(t_m1, m_start, m_end);
                if (tien_da_chi > half_m1)
                    break;

                if (t_exp1 < 300)
                {
                    t_exp1 = ceil(t_exp1 * 0.9);
                    t_m1 -= 100;
                    tien_da_chi += 100;
                }
                else
                {
                    t_exp1 = ceil(t_exp1 * 0.9);
                    t_m1 -= 120;
                    tien_da_chi += 120;

                }
                t_exp1 = check_value(t_exp1, e_start, e_end);
                t_m1 = check_value(t_m1, m_start, m_end);
                if (tien_da_chi > half_m1)
                    break;
            }
        }
        t_hp1 = ceil(t_hp1 * 0.83);

        t_exp1 = ceil(t_exp1 * 1.17);
        t_exp1 = check_value(t_exp1, e_start, e_end);
        t_hp1 = check_value(t_hp1, h_start, h_end);
    }

    else
    {
        if (t_m1 != 0)
        {
            for (int i = 1; i < 2; i++)
            {
                if (t_hp1 < 200)
                {
                    t_hp1 = ceil(t_hp1 * 1.3);
                    t_m1 -= 150;
                    tien_da_chi += 150;
                }
                else
                {
                    t_hp1 = ceil(t_hp1 * 1.1);
                    t_m1 -= 70;
                    tien_da_chi += 70;
                }

                t_hp1 = check_value(t_hp1, h_start, h_end);
                t_m1 = check_value(t_m1, m_start, m_end);
                if (t_m1 == 0)
                    break;

                if (t_exp1 < 400)
                {
                    t_exp1 = ceil(t_exp1 * 1.13);
                    t_m1 -= 200;
                    tien_da_chi += 200;
                }
                else
                {
                    t_exp1 = ceil(t_exp1 * 1.13);
                    t_m1 -= 120;
                    tien_da_chi += 120;
                }
                t_exp1 = check_value(t_exp1, e_start, e_end);
                t_m1 = check_value(t_m1, m_start, m_end);
                if (t_m1 == 0)
                    break;

                if (t_exp1 < 300)
                {
                    t_exp1 = ceil(t_exp1 * 0.9);
                    t_m1 -= 100;
                    tien_da_chi += 100;
                }
                else
                {
                    t_exp1 = ceil(t_exp1 * 0.9);
                    t_m1 -= 120;
                    tien_da_chi += 120;
                }
                t_exp1 = check_value(t_exp1, e_start, e_end);
                t_m1 = check_value(t_m1, m_start, m_end);
                if (t_m1 == 0)
                    break;
            }
        }
        t_hp1 = ceil(t_hp1 * 0.83);
        t_exp1 = ceil(t_exp1 * 1.17);
        t_exp1 = check_value(t_exp1, e_start, e_end);
        t_hp1 = check_value(t_hp1, h_start, h_end);
    }
    p2 = (square_num(t_exp1));

    // con duong 3
    float arr[10] = { 0.32,0.47,0.28,0.79,1.0,0.5,0.22,0.83,0.64,0.11 };
    int i;
    if (E2 < 10)
        p3 = arr[E2];
    else
    {
        i = (E2 / 10 + E2 % 10) % 10;
        p3 = arr[i];

    }

    p = (p1 + p2 + p3) / 3;
    if (p == 1.0)
    {
        t_exp1 = ceil(t_exp1 * 0.75);
    }
    else
    {
        if (p < 0.5)
        {
            t_hp1 = ceil(t_hp1 * 0.85);
            t_exp1 = ceil(t_exp1 * 1.15);
        }
        else
        {
            t_hp1 = ceil(t_hp1 * 0.9);
            t_exp1 = ceil(t_exp1 * 1.2);
        }

    }

    t_exp1 = check_value(t_exp1, e_start, e_end);
    t_hp1 = check_value(t_hp1, h_start, h_end);
    t_m1 = check_value(t_m1, m_start, m_end);

    HP1 = t_hp1;
    EXP1 = t_exp1;
    M1 = t_m1;

    return HP1 + EXP1 + M1;
}

// Task 3

int largest(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int diagonal_num(int x, int y, int e3)
{
    int num_max;
    int d_ptu = -1;
    int taxi_arr[10][10] = {};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            taxi_arr[i][j] = ((e3 * j) + (i * 2)) * (i - j);
        }
    }
    int max_arr[19] = { -9999 };
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (x > y)
            {
                if (i - j == x - y || i + j == x + y)
                {
                    d_ptu += 1;
                    max_arr[d_ptu] = taxi_arr[i][j];
                }
            }
            else if (x < y)
            {
                if (j - i == y - x || i + j == x + y)
                {
                    d_ptu += 1;
                    max_arr[d_ptu] = taxi_arr[i][j];
                }
            }
            else
            {
                if (i - j == 0 || i + j == x + y)
                {
                    d_ptu += 1;
                    max_arr[d_ptu] = taxi_arr[i][j];
                }
            }
        }
    }
    num_max = largest(max_arr, 19);
    return num_max;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {

    if (E3 < 0 || E3 > 99)
        return -99;

    float t_exp1 = EXP1, t_exp2 = EXP2, t_hp1 = HP1, t_hp2 = HP2;
    int e_start = 0, e_end = 600, h_start = 0, h_end = 666;
    int chase_x, chase_y, count_x = 0, count_y = 0;

    t_exp1 = check_value(t_exp1, e_start, e_end);
    t_exp2 = check_value(t_exp2, e_start, e_end);
    t_hp1 = check_value(t_hp1, h_start, h_end);
    t_hp2 = check_value(t_hp2, h_start, h_end);

    int taxi_arr[10][10] = {};

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            taxi_arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (taxi_arr[i][j] > E3 * 2)
                count_x += 1;
            if (taxi_arr[i][j] < -E3)
                count_y += 1;
        }
    }

    if (count_x < 10)
        chase_x = count_x;
    else
        chase_x = ((count_x / 10 + count_x % 10) / 10) + ((count_x / 10 + count_x % 10) % 10);

    if (count_y < 10)
        chase_y = count_y;
    else
        chase_y = ((count_y / 10 + count_y % 10) / 10) + ((count_y / 10 + count_y % 10) % 10);

    if (abs(taxi_arr[chase_x][chase_y]) < abs(diagonal_num(chase_x, chase_y, E3)))
    {
        t_exp1 = ceilf(t_exp1 * 1.12);
        t_hp1 = ceilf(t_hp1 * 1.1);
        t_exp2 = ceilf(t_exp2 * 1.12);
        t_hp2 = ceilf(t_hp2 * 1.1);

        EXP1 = check_value(t_exp1, e_start, e_end);
        EXP2 = check_value(t_exp2, e_start, e_end);
        HP1 = check_value(t_hp1, h_start, h_end);
        HP2 = check_value(t_hp2, h_start, h_end);

        return abs(diagonal_num(chase_x, chase_y, E3));
    }
    else
    {
        t_exp1 = ceilf(t_exp1 * 0.88);
        t_hp1 = ceilf(t_hp1 * 0.9);
        t_exp2 = ceilf(t_exp2 * 0.88);
        t_hp2 = ceilf(t_hp2 * 0.9);
        EXP1 = check_value(t_exp1, e_start, e_end);
        EXP2 = check_value(t_exp2, e_start, e_end);
        HP1 = check_value(t_hp1, h_start, h_end);
        HP2 = check_value(t_hp2, h_start, h_end);

        return taxi_arr[chase_x][chase_y];
    }

}

// Task 4
int checkPassword(const char * s, const char * email) {
    char se[100] = {};
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%";

    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i]=='@')
            break;
        se[i] = email[i];
    }

    if (strlen(s) < 8)
        return -1;

    if (strlen(s) > 20)
        return -2;

    if (strstr(s, se) != NULL)
    {
        int result = 300 + (strlen(s) - strlen(strstr(s, se)));
        return -result;
    }

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == s[i + 1])
            return -(400 + i);
    }

    if (!(strstr(s, "@") != NULL || strstr(s, "#") != NULL || strstr(s, "%") != NULL || strstr(s, "$") != NULL || strstr(s, "!") != NULL))
        return -5;

    int count_alp = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        for (int j = 0; j < strlen(alphabet); j++)
        {
            if (alphabet[j] == s[i])
            {
                count_alp += 1;
            }
        }
        if (count_alp != i +1)
            return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds)
{
    int count = 1, num, vi_tri_dau = 0; // vount: dem so lan xuat hien, num la so phan tu cua day, vi_tri_dau la vi tri xuat hien dau tien cua phan tu
    int phan_tu_dai_nhat, result;           // dung de so sanh phan tu dai nhat trong day
    float max = 1.5;                // so lan xuat hien nhieu nhat
    num = num_pwds;

    const char* arr_max[31] = {};   // mang de chua phan tu xuat hien nhieu hon 1 lan, vi tri ptu trong mang nay la vi tri xuat hien dau tien cua ptu trong mang arr_pwds
    int arr_count[31] = {};         // mang de chua so lan xuat hien tuong ung voi phan tu o mang tren
    const char* arr_finish[31] = {};// mang de chua phan tu xuat nhien nhieu lan nhat

    // gan tat ca phau tu trong mang bang " "
    for (int i = 0; i < num; i++)
    {
        arr_max[i] = " ";
        arr_finish[i] = " ";
    }

    // tim phan tu xuat hien nhieu hon 1 va so lan xuat hien cua no
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (arr_pwds[i] == arr_pwds[j])
                count += 1;
        }
        if (count >= max)
        {
            vi_tri_dau = i;
            max = count;
            arr_max[vi_tri_dau] = arr_pwds[i];
            arr_count[vi_tri_dau] = count;
        }
        count = 1;
    }

    // tim phan tu xuat hien nhieu nhat ( loai bo cac phan tu xuat hien it hon)
    for (int i = 0; i < num; i++)
    {
        if (arr_count[i] == max)
            arr_finish[i] = arr_max[i];
    }

    // so sanh do dai cua phan tu trong mang va tra ve ket qua
    if (max == 1.5)
    {
        phan_tu_dai_nhat = strlen(arr_pwds[0]);
        for (int i = 1; i < num; i++)
        {
            if (strlen(arr_pwds[i]) > phan_tu_dai_nhat)
                phan_tu_dai_nhat = strlen(arr_pwds[i]);
        }
        for (int i = 0; i < num; i++)
        {
            if (strlen(arr_pwds[i]) == phan_tu_dai_nhat)
            {
                result = i;
                break;
            }
        }
    }

    else
    {
        phan_tu_dai_nhat = strlen(arr_finish[0]);
        for (int i = 1; i < num; i++)
        {
            if (strlen(arr_finish[i]) > phan_tu_dai_nhat)
                phan_tu_dai_nhat = strlen(arr_finish[i]);
        }
        for (int i = 0; i < num; i++)
        {
            if (strlen(arr_finish[i]) == phan_tu_dai_nhat)
            {
                result = i;
                break;
            }
        }
    }
    return result;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////