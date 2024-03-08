#include "study_in_pink1.h"

#define MAX_EXP 600
#define MAX_HP 666
#define MAX_M 3000

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
void update(int &n, float newN, int maxN)
{
    if (newN > maxN)
        n = maxN;
    else if (newN < 0)
        n = 0;
    else
        n = ceil(newN);
}

int firstMeet(int &exp1, int &exp2, int e1)
{
    if (e1 >= 0 && e1 <= 3)
    { // Tru?ng h?p 1
        int E1[4] = {29, 45, 75, 149};
        exp2 += E1[e1];
        exp2 = exp2 > 600 ? 600 : exp2;
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            update(exp1, exp1 + D / 200.0f, MAX_EXP);
        else
            update(exp1, exp1 - D / 100.0f, MAX_EXP);
    }
    else if (e1 > 3 && e1 < 100)
    { // Tru?ng h?p 2
        if (e1 < 20)
            update(exp2, exp2 + e1 / 4.0f + 19, MAX_EXP);
        else if (e1 < 50)
            update(exp2, exp2 + e1 / 9.0f + 21, MAX_EXP);
        else if (e1 < 66)
            update(exp2, exp2 + e1 / 16.0f + 17, MAX_EXP);
        else if (e1 < 80)
        {

            update(exp2, exp2 + e1 / 4.0f + 19, MAX_EXP);
            if (exp2 > 200)
                update(exp2, exp2 + e1 / 9.0f + 21, MAX_EXP);
        }
        else
        {
            update(exp2, exp2 + e1 / 4.0f + 19, MAX_EXP);
            update(exp2, exp2 + e1 / 9.0f + 21, MAX_EXP);
            if (exp2 > 400)
            {
                update(exp2, exp2 + e1 / 16.0f + 17, MAX_EXP);
                update(exp2, exp2 * 1.15f, MAX_EXP);
            }
        }
        exp1 -= e1;
        exp1 = exp1 < 0 ? 0 : exp1;
    }
    else
        return -99; // Tru?ng h?p không trong kho?ng
    return exp1 + exp2;
}

// Task 2

float tinh_xac_suat(int EXP1)
{
    int S, S1, S2;
    for (int i = 0; i * i <= EXP1; i++)
    {
        S1 = i * i;
        S2 = (i + 1) * (i + 1);
    }
    (EXP1 - S1) < (S2 - EXP1) ? S = S1 : S = S2;
    float P;
    EXP1 >= S ? P = 1.0 : P = ((float)EXP1 / S + 80) / 123;
    return P;
}

// H?i s?c kh?e
void hoi_suc_khoe(int &HP1, int &M1)
{
    if (HP1 < 200)
    {
        update(HP1, HP1 * 1.3f, MAX_HP);
        M1 -= 150;
    }
    else
    {
        update(HP1, HP1 * 1.1f, MAX_HP);
        M1 -= 70;
    }
}

// Thuê xe
void thue_xe(int &M1, int &EXP1)
{
    EXP1 < 400 ? M1 -= 200 : M1 -= 120;
    update(EXP1, EXP1 * 1.13f, MAX_EXP);
}

// H?i thông tin t? ngu?i vô gia cu
void hoi_duong(int &M1, int &EXP1)
{
    EXP1 < 300 ? M1 -= 100 : M1 -= 120;
    update(EXP1, EXP1 * 0.9f, MAX_EXP);
}

void het_tien(int &HP1, int &EXP1, int &M1)
{
    update(HP1, HP1 * 0.83f, MAX_HP);
    update(EXP1, EXP1 * 1.17f, MAX_EXP);
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (E2 < 0 || 99 < E2)
        return -99;

    // Con du?ng 1
    float P1 = tinh_xac_suat(EXP1);

    // Con du?ng 2
    int M_bd = M1;
    if (E2 % 2 != 0)
    {
        do
        {
            if (M1 < 0.5 * M_bd)
                break;
            hoi_suc_khoe(HP1, M1);
            if (M1 < 0.5 * M_bd)
                break;
            thue_xe(M1, EXP1);
            if (M1 < 0.5 * M_bd)
                break;
            hoi_duong(M1, EXP1);
        } while (true);
    }
    else // E2%2==0
    {
        hoi_suc_khoe(HP1, M1);
        if (M1 > 0)
        {
            thue_xe(M1, EXP1);
            if (M1 > 0)
                hoi_duong(M1, EXP1);
        }
    }
    het_tien(HP1, EXP1, M1);

    float P2 = tinh_xac_suat(EXP1);

    // Con du?ng 3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float P3;
    if (E2 < 10)
        P3 = P[E2] * 0.01f;
    else if (E2 < 100)
    {
        // d?i v? 1 s? r?i l?y don v?
        int a = (E2 % 10 + E2 / 10) % 10;
        P3 = P[a] * 0.01f;
    }
    else
        return -99;

    // Sau khi di h?t 3 con du?ng
    float tb;
    tb = (P1 + P2 + P3) / 3;
    if (tb == 1)
    {
        update(EXP1, EXP1 * 0.75f, MAX_EXP);
    }
    else if (tb >= 0.5)
    {
        update(HP1, HP1 * 0.9f, MAX_HP);
        update(EXP1, EXP1 + EXP1 * 0.2f, MAX_EXP);
    }
    else
    {
        update(HP1, HP1 * 0.85f, MAX_HP);
        update(EXP1, EXP1 * 1.15f, MAX_EXP);
    }
    M1 = M1 < 0 ? 0 : M1;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 >= 0 && E3 < 100)
    {
        int M[10][10];
        int temp;
        // nh?p giá tr? vào trong ma tr?n
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                M[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                temp = M[i][j];
            }
        }
        int count_up = 0;   // khai báo bi?n d?m s? l?n hon E3*2
        int count_down = 0; // Khai báo bi?n d?m s? nh? hon -E3

        // d?m s? li?u
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (M[i][j] > E3 * 2)
                    count_up++;
                if (M[i][j] < -E3)
                    count_down++;
            }
        }

        // tìm t?a dô di?m dích
        int x, y;
        x = count_up / 10 + count_up % 10;
        x = x / 10 + x % 10;
        y = count_down / 10 + count_down % 10;
        y = y / 10 + y % 10;
        int goal = M[x][y];

        // tìm di?m c?a 2 ngu?i dó
        int max = 0;

        // Tìm trên du?ng chéo trái
        if (y >= x)
        {
            for (int n = 0; n < 10; n++)
            {
                if (y - x + n < 10)
                    max = M[n][y - x + n] ? M[n][y - x + n] : max;
            }
        }
        else
        {
            for (int n = 0; n < 10; n++)
            {
                if (x - y + n < 10)
                    max = M[x - y + n][n] ? M[x - y + n][n] : max;
            }
        }
        // Tìm trên du?ng chéo ph?i
        if (x + y >= 9)
        {
            for (int n = 0; n < 10; n++)
            {
                if (x + y - 9 + n < 10)
                    max = M[x + y - 9 + n][9 - n] ? M[x + y - 9 + n][9 - n] : max;
            }
        }
        else
        {
            for (int n = 0; n < 10; n++)
            {
                if (x + y - n >= 0)
                    max = M[n][x + y - n] ? M[n][x + y - n] : max;
            }
        }

        // du?i k?p
        if (abs(M[x][y]) <= abs(max))
        {
            update(HP1, HP1 * 1.1f, MAX_HP);
            update(HP2, HP2 * 1.1f, MAX_HP);
            update(EXP1, EXP1 * 1.12f, MAX_EXP);
            update(EXP2, EXP2 * 1.12f, MAX_EXP);
            return max;
        }

        // không du?i k?p
        else
        {
            update(HP1, HP1 * 0.9f, MAX_HP);
            update(HP2, HP2 * 0.9f, MAX_HP);
            update(EXP1, EXP1 * 0.88f, MAX_EXP);
            update(EXP2, EXP2 * 0.88f, MAX_EXP);
            return M[x][y];
        }
    }
    else
        return -99;
}

// Task 4
bool check_lien_tiep(char password[])
{
    for (int i = 0; i < strlen(password) - 2; i++)
    {
        if (password[i] == password[i + 1])
        {
            if (password[i] == password[i + 2])
                return true;
        }
    }
    return false;
}
bool check_ki_tu(char password[], char b[], int x)
{
    for (int i = 0; i < x; i++)
        if (strchr(password, b[i]) != NULL)
            return true;
    return false;
}
int checkPassword(const char *s, const char *email)
{
    const int MAX = 256;
    // các kí hi?u d?c bi?t cho phép
    char password[MAX];
    strcpy(password, s);
    // d?m b?o k?t thúc b?ng null
    password[strlen(s)] = '\0';
    char dacbiet[6] = "@#%$!";
    int ip_a;
    for (int i = 0; i < strlen(email); i++)
    {
        // ki?m v? trí c?a d?u @ trong email
        if (email[i] == '@')
        {
            ip_a = i;
            break;
        }
    }
    char se[MAX]; // chu?i ký t? tru?c d?u @

    // chép ph?n tru?c d?u @ c?a email vào <se>
    strncpy(se, email, ip_a);
    se[ip_a] = '\0'; // Ð?m b?o chu?i k?t thúc b?ng null

    // t?o chu?i ch?a các kí t? khác
    char khac[MAX];
    int x = 0;
    for (int i = 0; i < 256; i++)
    {
        if ((i != 33) && (i < 35 || i > 37) && (i < 48 || i > 57) && (i < 64 || i > 90) && (i < 97 || i > 122))
        {
            khac[x] = char(i);
            x++;
        }
    }
    khac[x] = '\0'; // d?m b?o k?t th?c = null

    // B?t d?u ki?m tra password
    if (strlen(password) < 8) // N?u nh? hon min
        return -1;
    else if (strlen(password) > 20) // N?u l?n hon max
        return -2;

    // N?u có ch?a <se>
    else if (strstr(password, se) != NULL)
    {
        int temp1;
        for (int i = 0; i < strlen(password); i++)
        {
            // tìm v? trí ký c?a <se> trong password
            // So sánh t?ng ip_a ký t? c?a password v?i chu?i se
            if (strncmp(password + i, se, ip_a) == 0)
            {
                temp1 = i; // Luu v? trí c?a se trong password
                break;
            }
        }
        return -(300 + temp1);
    }

    // N?u có > 2 ký t? liên ti?p
    else if (check_lien_tiep(password))
    {
        char temp_char;
        int cnt1 = 0;
        for (int i = 0; i < strlen(password) - 1; i++)
        {
            if (password[i] == password[i + 1])
            {
                if (password[i] == password[i + 2])
                    return -(400 + i);
            }
        }
    }

    // N?u không ch?a kí t? d?c bi?t
    else if (!check_ki_tu(password, dacbiet, 5))
        return -5;
    else if (check_ki_tu(password, khac, x))
    {
        char temp2;
        for (int i = 0; i < x; i++)
            if (strchr(password, khac[i]) != NULL)
                temp2 = khac[i];
        for (int i = 0; i < strlen(password); i++)
            if (password[i] == temp2)
                return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    const int MAX = 100;
    int nums[MAX] = {0};
    // d?m s? l?n xu?t hi?n c?a 1 m?t kh?u
    if (num_pwds == 1)
        return 0;
    for (int i = 0; i < num_pwds - 1; i++)
    {
        int count = 1;
        for (int j = i + 1; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
                count++;
        }
        nums[i] = count;
    }
    nums[num_pwds - 1] = 1; // mat khau cu?i luôn ch? xu?t hi?n 1 l?n
    int max = 0;
    int temp3 = 0;

    // tìm pass có s? l?n nhi?u nh?t
    for (int i = 0; i < num_pwds; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
            temp3 = i;
        }
    }
    // xem th? có nhi?u pass xu?t hi?n nh?t ko
    for (int i = temp3 + 1; i < num_pwds; i++)
    {
        if (nums[i] == max && strlen(arr_pwds[i]) > strlen(arr_pwds[temp3]))
            temp3 = i;
    }
    return temp3;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
