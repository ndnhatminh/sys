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

void checkHP(int &HP)
{
    if (HP > 666)
        HP = 666;
    else if (HP < 0)
    {
        HP = 0;
    }
}

void checkEXP(int &EXP)
{
    if (EXP > 600)
        EXP = 600;
    else if (EXP < 0)
    {
        EXP = 0;
    }
}

void checkM(int &M)
{
    if (M > 3000)
        M = 3000;
    else if (M < 0)
    {
        M = 0;
    }
}

bool checkE(int &E)
{
    if (E < 0 || E > 99)
        return true;
    return false;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // Case 1: E1 = [0,3]
    if (checkE(e1))
        return -99;
    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0)
            exp2 += 29;
        else if (e1 == 1)
            exp2 += 45;
        else if (e1 == 2)
            exp2 += 75;
        else
            exp2 += 29 + 45 + 75;
        // Quyet dinh dua tren so nguyen D de du doan
        // D chan: exp1 tang them D/200, D le: exp1 giam di D/100
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            exp1 += ceil(D / 200.0 - 1e-9);
        else
            exp1 -= floor(D / 100.0);
    }

    // Case2: E1 = [4,99]
    else if (e1 >= 4 && e1 <= 99)
    {
        // Giai thich thong tin 1
        if (e1 <= 19)
            exp2 += ceil(e1 / 4.0 + 19 - 1e-9);
        // Giai thich thong tin 2
        else if (e1 <= 49)
            exp2 += ceil(e1 / 9.0 + 21 - 1e-9);
        // Giai thich thong tin 3
        else if (e1 <= 65)
            exp2 += ceil(e1 / 16.0 + 17 - 1e-9);
        // Giai thich thong tin 1, neu exp > 200 thi giai thich tiep thong tin 2
        else if (e1 <= 79)
        {
            exp2 += ceil(e1 / 4.0 + 19 - 1e-9);
            if (exp2 > 200)
                exp2 += ceil(e1 / 4.0 + 21 - 1e-9);
        }
        // Giai thich thong tin 1 va 2, neu exp > 400 thi giai thich tiep thong tin 3
        else
        {
            exp2 += ceil(e1 / 4.0 + 19 - 1e-9);
            exp2 += ceil(e1 / 4.0 + 21 - 1e-9);
            if (exp2 > 400)
            {
                exp2 += ceil(e1 / 16.0 + 17 - 1e-9);
                exp2 = ceil(exp2 * 1.15 - 1e-9);
            }
        }
        exp1 -= e1;
    }
    checkEXP(exp2);
    checkEXP(exp1);
    return exp1 + exp2;
}

// Task 2
int check_square_nearest(int &EXP1)
{
    int sqrt_canDuoi = floor(sqrt(EXP1));
    int sqrt_canTren = sqrt_canDuoi + 1;
    int canTren = sqrt_canTren * sqrt_canTren,
        canDuoi = sqrt_canDuoi * sqrt_canDuoi;
    int S; // S la so chinh phuong gan nhat
    if (canTren - EXP1 < EXP1 - canDuoi)
        S = canTren;
    else
        S = canDuoi;
    return S;
}

bool compare_M_And_originalM(int const &M1, int const &original_M1)
{
    if (M1 < 0.5 * original_M1) // So sanh so tien su dung co nhieu hon 50% so tien ban dau khong
        return true;
    return false;
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // Kiem tra E2 co phu hop khong
    if (checkE(E2))
        return -99;

    // Con duong thu nhat
    int S1, S2; // S1, S2 la so chinh phuong gan nhat voi EXP1 tren con duong 1, 2
    S1 = check_square_nearest(EXP1);
    // Tim gia tri xac suat P
    float P1, P2, P3; // P1, P2, P3 la xac suat tim thay vali tren con duong 1, 2, 3
    if (EXP1 >= S1)
        P1 = 1.0;
    else
        P1 = (EXP1 * 1.0 / S1 + 80) / 123;
    //-----------------------------------------------------------------------------
    // Con duong thu hai
    // Kiem tra chan le E2
    if (M1 != 0)
    {
        const int original_M1 = M1;
        // Truong hop E2 la so le
        if (E2 % 2 == 1)
        {
            while (!compare_M_And_originalM(M1, original_M1))
            {
                // Su kien 1: HP1
                if (HP1 < 200)
                {
                    HP1 = ceil(1.3 * HP1 - 1e-9);
                    M1 -= 150;
                }
                else
                {
                    HP1 = ceil(1.1 * HP1 - 1e-9);
                    M1 -= 70;
                }
                // Kiem tra dieu kien tiep tuc sau su kien 1
                checkHP(HP1);
                checkM(M1);
                if (compare_M_And_originalM(M1, original_M1))
                    break;

                // Su kien 2: EXP1
                if (EXP1 < 400)
                    M1 -= 200; // Di taxi
                else
                    M1 -= 120;                   // Di xe ngua
                EXP1 = ceil(1.13 * EXP1 - 1e-9); // Cap nhat EXP1 sau su kien 2
                // Kiem tra dieu kien tiep tuc sau su kien 2
                checkM(M1);
                checkEXP(EXP1);
                if (compare_M_And_originalM(M1, original_M1))
                    break;

                // Su kien 3: EXP1 lan 2
                if (EXP1 < 300)
                    M1 -= 100; // Giup do nguoi vo gia cu va "nghe" nguoi nay chi
                else
                    M1 -= 120;                         // Giup do nguoi o gia cu va "nho" nguoi nay dan
                EXP1 = ceil(EXP1 - 0.1 * EXP1 - 1e-9); // Cap nhat EXP1 sau su kien 3
                // Kiem tra dieu kien tiep tuc sau su kien 3 duoc cap nhat o dieu kien vong lap while
                checkM(M1);
                checkEXP(EXP1);
            }
        }
        // Truong hop E2 la so chan
        else
        {
            // Su kien 1: HP1
            if (HP1 < 200)
            {
                HP1 = ceil(1.3 * HP1 - 1e-9);
                M1 -= 150;
            }
            else
            {
                HP1 = ceil(1.1 * HP1 - 1e-9);
                M1 -= 70;
            }
            // Kiem tra dieu kien tiep tuc sau su kien 1
            checkHP(HP1);
            checkM(M1);
            if (M1 != 0)
            {
                // Su kien 2: EXP1
                if (EXP1 < 400)
                    M1 -= 200; // Di taxi
                else
                    M1 -= 120;                   // Di xe ngua
                EXP1 = ceil(1.13 * EXP1 - 1e-9); // Cap nhat EXP1 sau su kien 2
                // Kiem tra dieu kien tiep tuc sau su kien 2
                checkM(M1);
                checkEXP(EXP1);
                if (M1 != 0)
                {
                    // Su kien 3: EXP1 lan 2
                    if (EXP1 < 300)
                        M1 -= 100; // Giup do nguoi vo gia cu va "nghe" nguoi nay chi
                    else
                        M1 -= 120;                         // Giup do nguoi o gia cu va "nho" nguoi nay dan
                    EXP1 = ceil(EXP1 - 0.1 * EXP1 - 1e-9); // Cap nhat EXP1 sau su kien 3
                    // Kiem tra dieu kien tiep tuc sau su kien 3 duoc cap nhat o dieu kien vong lap while
                    checkM(M1);
                    checkEXP(EXP1);
                }
            }
        }
    }
    HP1 = ceil(HP1 - 0.17 * HP1 - 1e-9);
    EXP1 = ceil(EXP1 + 0.17 * EXP1 - 1e-9);
    checkHP(HP1);
    checkEXP(EXP1);
    S2 = check_square_nearest(EXP1);
    if (EXP1 >= S2)
        P2 = 1.0;
    else
        P2 = (EXP1 * 1.0 / S2 + 80) / 123;

    //-----------------------------------------------------------------------------
    // Con duong thu ba
    int arr_P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}; // Mang 10 phan tu la 10 gia tri xac suat
    int num_E2;                                                // Tong hai chu so cua E2
    int idx_P;                                                 // Chi so xac suat con duong 3
    num_E2 = E2 % 10 + E2 / 10;                                // % de lay hang don vi, / lay hang chuc
    idx_P = num_E2 % 10;                                       // Lay hang don vi cua tong hai chu so cua E2
    P3 = arr_P[idx_P] / 100.0;

    // Gia quyet van de cuoi nhiem vu 2
    float avg_P = (P1 + P2 + P3) / 3.0; // Trung binh xac suat tim thay sau khi di qua 3 con duong
    if (avg_P == 1.0)                   // Ca 3 tuyen duong deu co xac suat 100%
    {
        EXP1 = ceil(EXP1 - 0.25 * EXP1 - 1e-9);
    }
    else if (avg_P < 0.5)
    {
        HP1 = ceil(HP1 - 0.15 * HP1 - 1e-9);
        EXP1 = ceil(EXP1 + 0.15 * EXP1 - 1e-9);
    }
    else
    {
        HP1 = ceil(HP1 - 0.1 * HP1 - 1e-9);
        EXP1 = ceil(EXP1 + 0.2 * EXP1 - 1e-9);
    }
    checkHP(HP1);
    checkEXP(EXP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int cal_sum_digits(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // Kiem tra E3 co phu hop khong
    if (checkE(E3))
        return -99;

    int arr[10][10] = {0};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    // Dem gia tri am, duong thoa yeu cau gia tri duong > 2*E3 va gia tri am < -E3
    // Theo cong thuc tinh diem cua taxi, khi i = j thi diem bang 0 nen duong cheo chinh bang 0.
    // Cung theo do, i > j thi diem lon hon 0. Nguoc lai, diem nho hon 0.
    // Nen khi dem gia tri am, duong, ta chi can xet ma tran tren va ma tran duoi cho truong hop tuong ung
    int pos_num = 0, neg_num = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (arr[i][j] < -E3)
                neg_num++;
        }
        for (int j = 0; j < i; j++)
        {
            if (arr[i][j] > (2 * E3))
                pos_num++;
        }
    }
    // Tinh gia tri i, j gap nhau theo de bai su dung ham tinh tong chu so
    int i_meeting, j_meeting;
    i_meeting = cal_sum_digits(pos_num);
    i_meeting = cal_sum_digits(i_meeting);
    j_meeting = cal_sum_digits(neg_num);
    j_meeting = cal_sum_digits(j_meeting);

    // Gia tri diem cua taxi tai diem gap mat
    int val_taxi = arr[i_meeting][j_meeting];

    // Tinh diem cua Sherlock va Watson
    int val_SW = arr[i_meeting][j_meeting];

    // So sanh diem tren duong cheo trai
    for (int i = i_meeting, j = j_meeting;; i--, j--)
    {
        if (arr[i][j] > val_SW)
            val_SW = arr[i][j];
        if (i == 0 || j == 0)
            break;
    }
    for (int i = i_meeting, j = j_meeting;; i++, j++)
    {
        if (arr[i][j] > val_SW)
            val_SW = arr[i][j];
        if (i == 9 || j == 9)
            break;
    }

    // So sanh diem tren duong cheo phai
    for (int i = i_meeting, j = j_meeting;; i--, j++)
    {
        if (arr[i][j] > val_SW)
            val_SW = arr[i][j];
        if (i == 0 || j == 9)
            break;
    }
    for (int i = i_meeting, j = j_meeting;; i++, j--)
    {
        if (arr[i][j] > val_SW)
            val_SW = arr[i][j];
        if (i == 9 || j == 0)
            break;
    }

    // Cuoc gap go
    if (abs(val_taxi) > val_SW)
    {
        EXP1 = ceil(EXP1 - 0.12 * EXP1 - 1e-9);
        EXP2 = ceil(EXP2 - 0.12 * EXP2 - 1e-9);
        HP1 = ceil(HP1 - 0.1 * HP1 - 1e-9);
        HP2 = ceil(HP2 - 0.1 * HP2 - 1e-9);

        return val_taxi;
    }
    else
    {
        EXP1 = ceil(EXP1 + 0.12 * EXP1 - 1e-9);
        EXP2 = ceil(EXP2 + 0.12 * EXP2 - 1e-9);
        HP1 = ceil(HP1 + 0.1 * HP1 - 1e-9);
        HP2 = ceil(HP2 + 0.1 * HP2 - 1e-9);

        checkEXP(EXP1);
        checkEXP(EXP2);
        checkHP(HP1);
        checkHP(HP2);

        return val_SW;
    }
}

// Task 4

bool is_alnum_spec(const char c)
{
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'))
        return true;
    if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!')
        return true;
    return false;
}

int cal_sei(const char *s, const char *se)
{
    int sei = -1;
    int len_s = strlen(s);
    int len_se = strlen(se);

    for (int n = 0; n <= len_s - len_se; ++n)
    {
        int m = 0;
        while (m < len_se && s[n + m] == se[m])
        {
            ++m;
        }

        if (m == len_se)
        {
            sei = n;
            break;
        }
    }

    return sei;
}

int cal_sci(const char *s)
{
    int sci = -1;
    for (int i = 0; i < strlen(s) - 2; i++)
    {
        if (s[i] == s[i + 1])
        {
            if (s[i + 1] == s[i + 2])
            {
                sci = i;
                return sci;
            }
        }
    }
    return sci;
}

bool check_special(const char c)
{
    if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!')
        return true;
    return false;
}

int checkPassword(const char *s, const char *email)
{

    // Tim vi tri ky tu @ de biet so luong chuoi ki tu "se" cua email
    // lay chuoi truoc @ gan vao se
    int len_se = 0;
    while (email[len_se] != '@')
        len_se++;
    char *se = new char[len_se + 1];
    strncpy(se, email, len_se);
    se[len_se] = '\0';

    // Kiem tra xem chuoi s co so luong ky tu phu hop tu 8-20 hay khong
    int len_s = strlen(s);
    if (len_s < 8)
        return -1;
    else if (len_s > 20)
        return -2;

    // Kiem tra dieu kien ky tu phu hop
    bool pos_s = false;
    int index_impos_s = 0;
    for (int i = 0; i < len_s; i++)
    {
        if (!is_alnum_spec(s[i]))
        {
            pos_s = true;
            index_impos_s = i;
            break;
        }
    }
    if (pos_s == true)
        return index_impos_s;

    // Kiem tra chuoi chua se
    int sei = -1;
    sei = cal_sei(s, se);
    if (sei != -1)
        return -(300 + sei);

    // Kiem tra ky tu lien tiep giong nhau
    int sci = -1;
    sci = cal_sci(s);
    if (sci != -1)
        return -(400 + sci);

    // Khong chua ki tu dac biet
    bool noex_spec = false;
    for (int i = 0; i < len_s; i++)
    {
        if (check_special(s[i]))
        {
            noex_spec = true;
            break;
        }
    }
    if (!noex_spec)
        return -5;

    // Mat khau hop le
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    if (num_pwds <= 0 || arr_pwds == nullptr)
    {
        return -1;
    }
    int maxCount = 0;
    int maxLength = 0;
    int resultIndex = -1;
    int *passwordCount = new int[num_pwds]();
    // Duyet qua mang va dem so luan xuat hien cá»§a moi chuoi
    for (int i = 0; i < num_pwds; ++i)
    {
        const char *password = arr_pwds[i];
        if (password != nullptr)
        {
            passwordCount[i]++;
            // Neu chuoi da xuat hien truoc do, tang gia tri tuong ung trong mang dem
            for (int j = 0; j < i; ++j)
            {
                if (strcmp(password, arr_pwds[j]) == 0)
                {
                    passwordCount[j]++;
                    break;
                }
            }
        }
    }
    // Duyet qua mang dem de tim chuoi co so lan xuat hien nhieu nhat va tim length neu co cung so lan xuat hien
    for (int i = 0; i < num_pwds; i++)
    {
        const char *password = arr_pwds[i];
        if (password != nullptr)
        {
            int count = passwordCount[i];
            int length = strlen(password);
            if (count > maxCount || (count == maxCount && length > maxLength))
            {
                maxCount = count;
                maxLength = length;
                resultIndex = i;
            }
        }
    }
    delete[] passwordCount;
    return resultIndex;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////