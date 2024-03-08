#include "study_in_pink1.h"
using namespace std;

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
// TASK 1
int return1(int &exp1) // điều kiện exp1
{
    if (exp1 > 600)
    {
        exp1 = 600;
    }
    if (exp1 < 0)
    {
        exp1 = 0;
    }
    return exp1;
}

int return2(int &exp2) // điều kiện exp2
{
    if (exp2 > 600)
    {
        exp2 = 600;
    }
    if (exp2 < 0)
    {
        exp2 = 0;
    }
    return exp2;
}

int firstMeet(int &exp1, int &exp2, int e1)
{
    // Nhập chỉ số kinh nghiệm của Watson và Sherlock (exp2 và exp1); chỉ số sự kiện e1
    // Trường hợp 1: e1 trong đoạn [0,3]
    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0) // thông tin 1
        {
            exp2 += 29;
            return2(exp2);
        }
        else if (e1 == 1) // thông tin 2
        {
            exp2 += 45;
            return2(exp2);
        }
        else if (e1 == 2) // thông tin 3
        {
            exp2 += 75;
            return2(exp2);
        }
        else if (e1 == 3) // thông tin 4
        {
            exp2 += 29 + 45 + 75;
            return2(exp2);
        }

        int D = e1 * 3 + exp1 * 7;

        if (D % 2 == 0) // trường hợp D là số chẵn -> Afghanistan
        {
            exp1 = ceil(exp1 + ((double)D / 200.0));
            return1(exp1);
        }
        else if (D % 2 == 1) // trường hợp D là số lẻ -> Iraq
        {
            exp1 = ceil(exp1 - ((double)D / 100.0));
            return1(exp1);
        }
        return exp1 + exp2;
    }
    // Trường hợp 2: e1 trong đoạn [4, 99]
    else if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19) // thông tin 1
        {
            exp2 = ceil(exp2 + ((double)e1 / 4.0 + 19));
            return2(exp2);
        }
        else if (e1 >= 20 && e1 <= 49) // thông tin 2
        {
            exp2 = ceil(exp2 + ((double)e1 / 9.0 + 21));
            return2(exp2);
        }
        else if (e1 >= 50 && e1 <= 65) // thông tin 3
        {
            exp2 = ceil(exp2 + ((double)e1 / 16.0 + 17));
            return2(exp2);
        }
        else if (e1 >= 66 && e1 <= 79) // thông tin 4
        {
            exp2 = ceil(exp2 + ((double)e1 / 4.0 + 19));
            return2(exp2);
            if (exp2 > 200)
            {
                exp2 = ceil(exp2 + ((double)e1 / 9.0 + 21));
                return2(exp2);
            }
        }
        else if (e1 >= 80 && e1 <= 99) // thông tin 5
        {
            exp2 = ceil(exp2 + ((double)e1 / 4.0 + 19));
            return2(exp2);
            exp2 = ceil(exp2 + ((double)e1 / 9.0 + 21));
            return2(exp2);
            if (exp2 > 400)
            {
                exp2 = ceil(exp2 + ((double)e1 / 16.0 + 17));
                return2(exp2);
                exp2 = ceil(exp2 * 1.15);
                return2(exp2);
            }
        }
        // Sherlock đoán sai, Sherlock bị Watson cắm sừng
        exp1 = ceil((double)exp1 - e1);
        return1(exp1);
        return exp1 + exp2;
    }
    else
    {
        return -99;
    }
}

// TASK 2
int return3(int &HP1) // điều kiện HP1
{
    if (HP1 > 666)
    {
        HP1 = 666;
    }
    if (HP1 < 0)
    {
        HP1 = 0;
    }
    return HP1;
}

int return4(int &M1) // điều kiện M1
{
    if (M1 > 3000)
    {
        M1 = 3000;
    }
    if (M1 < 0)
    {
        M1 = 0;
    }
    return M1;
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // Con đường 1
    // Tính P1
    int x1 = sqrt(EXP1);
    float S1;
    if (x1 * x1 == EXP1)
    {
        S1 = EXP1;
    }
    else
    {
        int higher1 = ((x1 + 1) * (x1 + 1));
        int lower1 = x1 * x1;
        if (higher1 - EXP1 < EXP1 - lower1)
        {
            S1 = higher1;
        }
        else
        {
            S1 = lower1;
        }
    }
    // tính P1
    double P1;
    if (EXP1 >= S1)
    {
        P1 = 100;
    }
    else
    {
        P1 = (((double)EXP1 / S1 + 80.0) / 123.0) * 100;
    }

    // Con đường 2
    int initialM1 = 0.5 * M1;
    int usedmoney = 0;
    if (E2 % 2 != 0)
    {
        while (usedmoney < initialM1)
        {
            // sự kiện 1
            if (HP1 < 200)
            {
                HP1 = ceil((double)HP1 * 130 / 100);
                return3(HP1);
                M1 -= 150;
                return4(M1);
                usedmoney += 150;
                if (usedmoney > initialM1)
                {
                    break;
                }
            }
            else
            {
                HP1 = ceil((double)HP1 * 110 / 100);
                return3(HP1);
                M1 -= 70;
                return4(M1);
                usedmoney += 70;
                if (usedmoney > initialM1)
                {
                    break;
                }
            }
            // sự kiện 2
            if (EXP1 < 400)
            {
                EXP1 = ceil((double)EXP1 * 113 / 100);
                return1(EXP1);
                M1 -= 200;
                return4(M1);
                usedmoney += 200;
                if (usedmoney > initialM1)
                {
                    break;
                }
            }
            else
            {
                EXP1 = ceil((double)EXP1 * 113 / 100);
                return1(EXP1);
                M1 -= 120;
                return4(M1);
                usedmoney += 120;
                if (usedmoney > initialM1)
                {
                    break;
                }
            }
            // sự kiện 3
            if (EXP1 < 300)
            {
                EXP1 = ceil((double)EXP1 * 90 / 100);
                return1(EXP1);
                M1 -= 100;
                return4(M1);
                usedmoney += 100;
                if (usedmoney > initialM1)
                {
                    break;
                }
            }
            else
            {
                EXP1 = ceil((double)EXP1 * 90 / 100);
                return1(EXP1);
                M1 -= 120;
                return4(M1);
                usedmoney += 120;
                if (usedmoney > initialM1)
                {
                    break;
                }
            }
        }
    }
    else if (E2 % 2 == 0)
    {
        while (M1 > 0)
        {
            // sự kiện 1
            if (HP1 < 200)
            {
                HP1 = ceil((double)HP1 * 130 / 100);
                return3(HP1);
                M1 -= 150;
                return4(M1);
                if (M1 == 0)
                {
                    break;
                }
            }
            else
            {
                HP1 = ceil((double)HP1 * 110 / 100);
                return3(HP1);
                M1 -= 70;
                return4(M1);
                if (M1 == 0)
                {
                    break;
                }
            }
            // sự kiện 2
            if (EXP1 < 400)
            {
                EXP1 = ceil((double)EXP1 * 113 / 100);
                return1(EXP1);
                M1 -= 200;
                return4(M1);
                if (M1 == 0)
                {
                    break;
                }
            }
            else
            {
                EXP1 = ceil((double)EXP1 * 113 / 100);
                return1(EXP1);
                M1 -= 120;
                return4(M1);
                if (M1 == 0)
                {
                    break;
                }
            }
            // sự kiện 3
            if (EXP1 < 300)
            {
                EXP1 = ceil((double)EXP1 * 90 / 100);
                return1(EXP1);
                M1 -= 100;
                return4(M1);
                if (M1 == 0)
                {
                    break;
                }
            }
            else
            {
                EXP1 = ceil((double)EXP1 * 90 / 100);
                return1(EXP1);
                M1 -= 120;
                return4(M1);
                if (M1 == 0)
                {
                    break;
                }
            }
            break;
        }
    }
    HP1 = ceil((double)HP1 * 83 / 100);
    return3(HP1);
    EXP1 = ceil((double)EXP1 * 117 / 100);
    return1(EXP1);

    // Tính P2
    int x2 = sqrt(EXP1);
    int S2;
    if (x2 * x2 == EXP1)
    {
        S2 = EXP1;
    }
    else
    {
        int higher2 = ((x2 + 1) * (x2 + 1));
        int lower2 = x2 * x2;
        if (higher2 - EXP1 < EXP1 - lower2)
        {
            S2 = higher2;
        }
        else
        {
            S2 = lower2;
        }
    }

    double P2;

    if (EXP1 >= S2)
    {
        P2 = 100;
    }
    else
    {
        P2 = (((double)EXP1 / S2 + 80.0) / 123.0) * 100;
    }

    // Con đường 3
    double P3;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 / 10 < 1)
    {
        P3 = P[E2];
    }
    else
    {
        int i;
        if ((E2 % 10 + E2 / 10 % 10) >= 10)
        {
            i = (E2 % 10 + E2 / 10 % 10) % 10;
        }
        else
        {
            i = E2 % 10 + E2 / 10 % 10;
        }
        P3 = P[i];
    }
    // Kết thúc con đường
    int average = (P1 + P2 + P3) / 3;
    if (average == 100)
    {
        EXP1 = ceil((double)EXP1 * 75 / 100);
        return1(EXP1);
    }
    else if (average < 50)
    {
        EXP1 = ceil((double)EXP1 * 115 / 100);
        return1(EXP1);
        HP1 = ceil((double)HP1 * 85 / 100);
        return3(HP1);
    }
    else if (average < 100)
    {
        EXP1 = ceil((double)EXP1 * 120. / 100);
        return1(EXP1);
        HP1 = ceil((double)HP1 * 90 / 100);
        return3(HP1);
    }

    if (E2 > 99 || E2 < 0)
    {
        return -99;
    }
    return HP1 + EXP1 + M1;
}

// TASK 3

int return5(int &HP2) // điều kiện HP2
{
    if (HP2 > 666)
    {
        HP2 = 666;
    }
    if (HP2 < 0)
    {
        HP2 = 0;
    }
    return HP2;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    int T[10][10];
    int taxi[10][10];
    int sherwat[10][10];
    int S;
    int a = 0, b = 0;

    // Tính điểm taxi
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            T[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            taxi[i][j] = T[i][j];
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (T[i][j] > E3 * 2)
            {
                a++;
            }
            else if (T[i][j] < -E3)
            {
                b++;
            }
        }
    }
    while (a / 10 >= 1)
    {
        a = a % 10 + (a / 10 % 10);
    }
    while (b / 10 >= 1)
    {
        b = b % 10 + (b / 10 % 10);
    }
    int maxScore = taxi[a][b];

    // Tính điểm của Sherlock và Watson
    int A = a;
    int B = b;
    // Đường chéo trái 
    while (A >= 0 && B <= 9)  //các phần tử nằm trên điểm taxi
    {
        maxScore = max(maxScore, T[A][B]);
        A--;
        B++;
    }
    A = a;
    B = b;
    while (A <= 9 && B >= 0)  //các phần tử nằm dưới điểm taxi
    {
        maxScore = max(maxScore, T[A][B]);
        A++;
        B--;
    }
    A = a;
    B = b;

//Đường chéo phải
    while (A <= 9 && B <= 9) //các phần tử nằm dưới điểm taxi
    {
        maxScore = max(maxScore, T[A][B]);
        A++;
        B++;
    }
    A = a;
    B = b;
    while (A >= 0 && B >= 0) //các phần tử nằm trên điểm taxi
    {
        maxScore = max(maxScore, T[A][B]);
        A--;
        B--;
    }

    sherwat[A][B] = maxScore;

    // Cập nhật EXP và HP
    if (abs(taxi[a][b]) > sherwat[A][B])
    {
        maxScore = taxi[a][b];
        EXP1 = ceil((double)EXP1 * 88 / 100);
        return1(EXP1);
        EXP2 = ceil((double)EXP2 * 88 / 100);
        return2(EXP2);
        HP1 = ceil((double)HP1 * 90 / 100);
        return3(HP1);
        HP2 = ceil((double)HP2 * 90 / 100);
        return5(HP2);
    }
    else
    {
        maxScore = sherwat[A][B];
        EXP1 = ceil((double)EXP1 * 112 / 100);
        return1(EXP1);
        EXP2 = ceil((double)EXP2 * 112 / 100);
        return2(EXP2);
        HP1 = ceil((double)HP1 * 110 / 100);
        return3(HP1);
        HP2 = ceil((double)HP2 * 110 / 100);
        return5(HP2);
    }
    if (E3 > 99 || E3 < 0)
    {
        return -99;
    }
    return maxScore;
}

// TASK 4
int checkPassword(const char *s, const char *email)
{
    // CÁC HÀM SỬ DỤNG TRONG TASK 4:
    //  s.length(): đếm số ký tự có trong chuỗi s
    //  s.find("a"/d): tìm ký tự a/ chuỗi d trong chuỗi s

    string Password = (string)s;
    string Email = (string)email;
    string se;
    for (int i = 0; i < Email.find("@"); i++)
    {
        se = se + Email[i];
    };

    // Xét các trường hợp theo thứ tự:
    // s có độ dài ngắn hơn độ dài tối thiểu
    if (Password.length() < 8)
    {
        return -1;
    }

    // s có độ dài dài hơn độ dài tối thiểu
    if (Password.length() > 20)
    {
        return -2;
    }

    // s chứa chuỗi se
    if (Password.find(se) != -1) // nếu hàm find ko tìm ra chuỗi mình cần tìm thì sẽ trả -1
    {
        return -(300 + Password.find(se));
    }

    // s chứa nhiều hơn 2 ký tự liên tiếp và giống nhau
    for (int i = 0; i < Password.length() - 2; i++)
    {
        if (Password[i] == Password[i + 1] && Password[i + 1] == Password[i + 2])
        {
            return -(400 + i);
        }
    }

    // s ko chứa ký tự đặc biệt
    if (Password.find('@') == -1 && Password.find('#') == -1 && Password.find('$') == -1 && Password.find('%') == -1 && Password.find('!') == -1)
    {
        return -5;
    }

    // trường hợp còn lại (chứa các ký tự cực đặc biệt khác chữ, số và ký tự đặc biệt đã nêu trong đề, lúc này dò các ký tự đó trên bảng mã ASCII tương ứng với số nào để xét điều kiện)
    for (int i = 0; i < Password.length(); i++)
    {
        if ((int)Password[i] == 34 || (int)Password[i] >= 38 && (int)Password[i] <= 47 || (int)Password[i] >= 58 && (int)Password[i] <= 63 || (int)Password[i] >= 91 && (int)Password[i] <= 96 || (int)Password[i] >= 123 && (int)Password[i] <= 126)
        {
            return i;
        }
    }
    // Nếu mật khẩu hợp lệ
    return -10;
}

// TASK 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // CÁC HÀM SỬ DỤNG TRONG TASK 5:
    //  strcmp(chuỗi 1, chuỗi 2): So sánh 2 chuỗi (=0: giống nhau; >0: chuỗi 1 > chuỗi 2; <0: chuỗi 1 < chuỗi 2)

    int first_location_of_the_pass_with_highest_count = -1;
    int highest_count = 0;
    string longest_password;

    for (int i = 0; i < num_pwds; i++)
    {
        //Đếm password
        int count = 0;
        for (int j = i + 1; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                count++;
            }
        }
        string Password = (string)arr_pwds[i];
        if (count > highest_count)
        {
            highest_count = count;
            first_location_of_the_pass_with_highest_count = i;
        }
        else if ((count == highest_count) && (Password.length() > longest_password.length()))
        {
            longest_password = Password;
            first_location_of_the_pass_with_highest_count = i;
        }
    }
    return first_location_of_the_pass_with_highest_count;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////