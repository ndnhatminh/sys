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
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }
    else if (e1 >= 0 && e1 <= 3)
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
            exp2 += 29 + 45 + 75;
        }

        // Determine Sherlock's prediction and update exp1 accordingly
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 = ceil(exp1 + D / 200.0);
        }
        else
        {
            exp1 -= D / 100;
        }

        if (exp2 < 0)
        {
            exp2 = 0;
        }
        else if (exp2 > 600)
        {
            exp2 = 600;
        }

        if (exp1 < 0)
        {
            exp1 = 0;
        }
        else if (exp1 > 600)
        {
            exp1 = 600;
        }
    }

    // Case 2: e1 in range [4, 99]
    else if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 = ceil(exp2 + e1 / 9.0 + 21);
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 = ceil(exp2 + e1 / 16.0 + 17);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);
            if (exp2 > 200)
            {
                exp2 = ceil(exp2 + e1 / 9.0 + 21);
            }
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);
            exp2 = ceil(exp2 + e1 / 9.0 + 21);
            if (exp2 > 400)
            {
                exp2 = ceil(exp2 + e1 / 16.0 + 17);
                exp2 = ceil(exp2 + exp2 * 0.15);
            }
        }

        if (exp2 < 0)
        {
            exp2 = 0;
        }
        else if (exp2 > 600)
        {
            exp2 = 600;
        }

        exp1 -= e1;
        if (exp1 < 0)
        {
            exp1 = 0;
        }
        else if (exp1 > 600)
        {
            exp1 = 600;
        }
    }

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
        return -99;

    if (EXP1 < 0)
    {
        EXP1 = 0;
    }
    else if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    if (M1 < 0)
    {
        M1 = 0;
    }
    else if (M1 > 3000)
    {
        M1 = 3000;
    }
    if (HP1 < 0)
    {
        HP1 = 0;
    }
    else if (HP1 > 666)
    {
        HP1 = 666;
    }

    // Road 01

    double P1;
    int nearestPerfectSquare = floor(sqrt(EXP1));
    int S;

    int remainder1 = EXP1 - (nearestPerfectSquare * nearestPerfectSquare);
    int remainder2 = (nearestPerfectSquare + 1) * (nearestPerfectSquare + 1) - EXP1;

    if (remainder1 < remainder2)
    {
        S = nearestPerfectSquare * nearestPerfectSquare;
    }
    else
    {
        S = (nearestPerfectSquare + 1) * (nearestPerfectSquare + 1);
    }

    if (EXP1 >= S)
    {
        P1 = 100;
    }
    else
    {
        P1 = ((EXP1 / S + 80.0) / 123.0) * 100;
    }

    // Road 2
    // E la so chan

    if (E2 % 2 == 0)
    {
        while (true)
        {
            if (M1 > 0)
            {
                if (HP1 < 200)
                {
                    HP1 += ceil((double)HP1 * 30.0 / 100);
                    M1 -= 150;
                }
                else
                {
                    HP1 += ceil((double)HP1 * 10.0 / 100);
                    M1 -= 70;
                }
            }
            else
            {
                M1 = 0;
                break;
            }

            if (M1 > 0)
            {
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    EXP1 += ceil((double)EXP1 * 13.0 / 100);
                }
                else
                {
                    M1 -= 120;
                    EXP1 += ceil((double)EXP1 * 13.0 / 100);
                }
            }
            else
            {
                M1 = 0;
                break;
            }

            if (M1 > 0)
            {
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    EXP1 -= floor((double)EXP1 * 10.0 / 100);
                }
                else
                {
                    M1 -= 120;
                    EXP1 -= floor((double)EXP1 * 10.0 / 100);
                }
            }
            else
            {
                M1 = 0;
                break;
            }
            break;
        }

        /////////////////////////////////////////////
        if (HP1 < 0)
        {
            HP1 = 0;
        }
        else if (HP1 > 666)
        {
            HP1 = 666;
        }
        /////////////////////////////////////////////

        HP1 -= floor((double)HP1 * 17.0 / 100);
        EXP1 += ceil((double)EXP1 * 17.0 / 100);
    }

    /////////////////////////////////////////////

    // E la so le
    if (E2 % 2 == 1)
    {
        double moneySpent = 0.0;
        double initialMoney = M1 * 50.0 / 100;

        while (true)
        {
            if (M1 == 0)
                break;

            if (HP1 < 200)
            {
                if (moneySpent > initialMoney)
                    break;

                HP1 += ceil((double)HP1 * 30.0 / 100);
                moneySpent += 150;
                M1 -= 150;
            }
            else
            {
                HP1 += ceil((double)HP1 * 10.0 / 100);
                moneySpent += 70;
                M1 -= 70;
            }
            /////////////////////////////////////////////
            if (moneySpent > initialMoney)
                break;

            if (HP1 < 0)
            {
                HP1 = 0;
            }
            else if (HP1 > 666)
            {
                HP1 = 666;
            }
            /////////////////////////////////////////////
            if (EXP1 < 400)
            {

                moneySpent += 200;
                M1 -= 200;
                EXP1 += ceil((double)EXP1 * 13.0 / 100);
            }
            else
            {
                moneySpent += 120;
                M1 -= 120;
                EXP1 += ceil((double)EXP1 * 13.0 / 100);
            }
            /////////////////////////////////////////////
            if (HP1 < 0)
            {
                HP1 = 0;
            }
            else if (HP1 > 666)
            {
                HP1 = 666;
            }

            if (moneySpent > initialMoney)
                break;

            if (EXP1 < 300)
            {

                M1 -= 100;
                moneySpent += 100;
            }
            else
            {
                M1 -= 120;
                moneySpent += 120;
            }
            EXP1 -= floor((double)EXP1 * 10.0 / 100);
            if (moneySpent > initialMoney)
                break;
        }

        if (HP1 < 0)
        {
            HP1 = 0;
        }
        else if (HP1 > 666)
        {
            HP1 = 666;
        }

        HP1 -= floor((double)HP1 * 17.0 / 100);
        EXP1 += ceil((double)EXP1 * 17.0 / 100);
    }

    // Tinh lai P2 cho road2 sau khi xet E2 chan le

    if (EXP1 < 0)
    {
        EXP1 = 0;
    }
    else if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    if (M1 < 0)
    {
        M1 = 0;
    }
    else if (M1 > 3000)
    {
        M1 = 3000;
    }
    if (HP1 < 0)
    {
        HP1 = 0;
    }
    else if (HP1 > 666)
    {
        HP1 = 666;
    }

    double P2;
    int nearestPerfectSquare_2 = floor(sqrt(EXP1));
    int S2;

    int remainder1_2 = EXP1 - (nearestPerfectSquare_2 * nearestPerfectSquare_2);
    int remainder2_2 = (nearestPerfectSquare_2 + 1) * (nearestPerfectSquare_2 + 1) - EXP1;

    if (remainder1_2 < remainder2_2)
    {
        S2 = nearestPerfectSquare_2 * nearestPerfectSquare_2;
    }
    else
    {
        S2 = (nearestPerfectSquare_2 + 1) * (nearestPerfectSquare_2 + 1);
    }

    if (EXP1 >= S2)
    {
        P2 = 100;
    }
    else
    {
        P2 = ((((double)EXP1 / S2) + 80) / 123.0) * 100;
    }

    /////////////////////////////////////////////
    if (EXP1 < 0)
    {
        EXP1 = 0;
    }
    else if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    if (M1 < 0)
    {
        M1 = 0;
    }
    else if (M1 > 3000)
    {
        M1 = 3000;
    }
    if (HP1 < 0)
    {
        HP1 = 0;
    }
    else if (HP1 > 666)
    {
        HP1 = 666;
    }
    /////////////////////////////////////////////

    // Road 3

    double P3;
    int i;
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

    if (E2 < 10)
    {
        i = E2;
        P3 = P[i];
    }
    else
    {
        int sum = E2 % 10 + E2 / 10;
        i = sum % 10;
        P3 = P[i];
    }

    /////////////////////////////////////////////
    if (HP1 < 0)
        HP1 = 0;
    else if (HP1 > 666)
        HP1 = 666;

    if (EXP1 < 0)
        EXP1 = 0;
    else if (EXP1 > 600)
        EXP1 = 600;

    if (M1 < 0)
        M1 = 0;
    else if (M1 > 3000)
        M1 = 3000;
    /////////////////////////////////////////////

    // Final decision
    double avg_P = (P1 + P2 + P3) / 3.0;

    if (P1 == 100 && P2 == 100 && P3 == 100)
    {
        EXP1 -= floor((double)EXP1 * 25 / 100.0); // Decrease EXP by 25%
    }
    else
    {
        if (avg_P < 50.0)
        {
            HP1 -= floor((double)HP1 * 15 / 100);  // Decrease HP by 15%
            EXP1 += ceil((double)EXP1 * 15 / 100); // Increase EXP by 15%
        }
        else
        {
            HP1 -= floor((double)HP1 * 10 / 100);  // Decrease HP by 10%
            EXP1 += ceil((double)EXP1 * 20 / 100); // Increase EXP by 20%
        }
    }

    /////////////////////////////////////////////
    if (EXP1 < 0)
    {
        EXP1 = 0;
    }
    else if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    if (M1 < 0)
    {
        M1 = 0;
    }
    else if (M1 > 3000)
    {
        M1 = 3000;
    }
    if (HP1 < 0)
    {
        HP1 = 0;
    }
    else if (HP1 > 666)
    {
        HP1 = 666;
    }
    /////////////////////////////////////////////

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;

    if (HP1 < 0)
    {
        HP1 = 0;
    }
    else if (HP1 > 666)
    {
        HP1 = 666;
    }

    if (EXP1 < 0)
    {
        EXP1 = 0;
    }
    else if (EXP1 > 600)
    {
        EXP1 = 600;
    }

    if (HP2 < 0)
    {
        HP2 = 0;
    }
    else if (HP2 > 666)
    {
        HP2 = 666;
    }

    if (EXP2 < 0)
    {
        EXP2 = 0;
    }
    else if (EXP2 > 600)
    {
        EXP2 = 600;
    }

    // Khai báo và khởi tạo mảng 10x10
    int bigger = 0, smaller = 0;
    int arr[10][10] = {};

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);

            // Thực hiện so sánh giá trị của phần tử để tìm bigger và smaller
            if (arr[i][j] > 2 * E3)
            {
                bigger++;
            }
            if (arr[i][j] < -E3)
            {
                smaller++;
            }
        }
    }

    // Tính posI và posJ dựa trên cách tính tổng chữ số đơn vị và chục của bigger và smaller
    int posI = 0, posJ = 0;
    int temp = bigger;

    // Tính tổng chữ số đơn vị và chục của bigger
    while (temp >= 10)
    {
        temp = temp / 10 + temp % 10;
    }
    posI = temp; // Cộng thêm chữ số cuối cùng

    int temp2 = smaller;
    // Tính tổng chữ số đơn vị và chục của smaller
    while (temp2 >= 10)
    {
        temp2 = temp2 / 10 + temp2 % 10;
    }
    posJ = temp2; // Cộng thêm chữ số cuối cùng

    // Tính tổng chữ số đơn vị và chục của bigger cho đến khi tổng < 10
    int sherlockPoint = arr[posI][posJ];

    // Bước 2: Hướng xanh lá: i và j giảm
    for (int i = posI, j = posJ; i >= 0 && j >= 0; --i, --j)
    {
        if (i != posI || j != posJ)
        { // Kiểm tra không phải vị trí gặp nhau
            if (arr[i][j] > sherlockPoint)
            {
                sherlockPoint = arr[i][j];
            }
        }

        // Kiểm tra giới hạn và break nếu cần
        if (i < 0 || j < 0)
        {
            break;
        }
    }

    // Hướng xanh dương: i tăng, j giảm
    for (int i = posI, j = posJ; i < 10 && j >= 0; ++i, --j)
    {
        if (i != posI || j != posJ)
        {
            if (arr[i][j] > sherlockPoint)
            {
                sherlockPoint = arr[i][j];
            }
        }

        if (i >= 10 || j < 0)
        {
            break;
        }
    }

    // Hướng hồng: i và j tăng
    for (int i = posI, j = posJ; i < 10 && j < 10; ++i, ++j)
    {
        if (i != posI || j != posJ)
        {
            if (arr[i][j] > sherlockPoint)
            {
                sherlockPoint = arr[i][j];
            }
        }

        if (i >= 10 || j >= 10)
        {
            break;
        }
    }

    // Hướng vàng: i giảm, j tăng
    for (int i = posI, j = posJ; i >= 0 && j < 10; --i, ++j)
    {
        if (i != posI || j != posJ)
        {
            if (arr[i][j] > sherlockPoint)
            {
                sherlockPoint = arr[i][j];
            }
        }
        // Kiểm tra giới hạn và break nếu cần
        if (i < 0 || j >= 10)
        {
            break;
        }
    }

    int taxiPoint = ((E3 * posJ) + (posI * 2)) * (posI - posJ);
    // Thực hiện so sánh giữa TaxiPoint và SherlockPoint
    if (abs(taxiPoint) > sherlockPoint)
    {
        // Không đuổi kịp được taxi

        HP1 -= floor((double)HP1 * 10.0 / 100.0);
        EXP1 -= floor((double)EXP1 * 12.0 / 100.0);
        HP2 -= floor((double)HP2 * 10.0 / 100.0);
        EXP2 -= floor((double)EXP2 * 12.0 / 100.0);

        if (EXP1 < 0)
        {
            EXP1 = 0;
        }
        else if (EXP1 > 600)
        {
            EXP1 = 600;
        }

        if (HP1 < 0)
        {
            HP1 = 0;
        }
        else if (HP1 > 666)
        {
            HP1 = 666;
        }

        if (HP2 < 0)
        {
            HP2 = 0;
        }
        else if (HP2 > 666)
        {
            HP2 = 666;
        }

        if (EXP2 < 0)
        {
            EXP2 = 0;
        }
        else if (EXP2 > 600)
        {
            EXP2 = 600;
        }

        return taxiPoint;
    }
    else
    {
        // Đuổi kịp được taxi

        HP1 += ceil((double)HP1 * 10.0 / 100.0);
        EXP1 += ceil((double)EXP1 * 12.0 / 100.0);
        HP2 += ceil((double)HP2 * 10.0 / 100.0);
        EXP2 += ceil((double)EXP2 * 12.0 / 100.0);

        if (EXP1 < 0)
        {
            EXP1 = 0;
        }
        else if (EXP1 > 600)
        {
            EXP1 = 600;
        }

        if (HP1 < 0)
        {
            HP1 = 0;
        }
        else if (HP1 > 666)
        {
            HP1 = 666;
        }

        if (HP2 < 0)
        {
            HP2 = 0;
        }
        else if (HP2 > 666)
        {
            HP2 = 666;
        }

        if (EXP2 < 0)
        {
            EXP2 = 0;
        }
        else if (EXP2 > 600)
        {
            EXP2 = 600;
        }

        return sherlockPoint;
    }
    return -1;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    // Tìm chuỗi 'se' từ đầu đến ký tự '@' trong email
    char se[101];
    int i = 0;
    while (email[i] != '@')
    {
        se[i] = email[i];
        i++;
    }
    se[i] = '\0';

    int length = strlen(s);
    if (length < 8)
        return -1; // Trả về -1 nếu độ dài ngắn hơn độ dài tối thiểu
    if (length > 20)
        return -2; // Trả về -2 nếu độ dài dài hơn độ dài tối đa

    const char *found = strstr(s, se);
    if (found != nullptr)
    {
        int position = found - s;
        return -(300 + position);
    }

    for (int i = 0; i < length - 2; ++i)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
            return -(400 + i); // Trả về - (400 + i) nếu có nhiều hơn 2 ký tự liên tiếp giống nhau
    }

    bool hasSpecialChar = false;
    for (int i = 0; i < length; ++i)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            hasSpecialChar = true;
    }
    if (!hasSpecialChar)
        return -5; // Trả về -5 nếu mật khẩu không chứa ký tự đặc biệt

    for (int i = 0; i < length; ++i)
    {
        if (!isalnum(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!')
            return i;
    }

    return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int max_frequency = 0;
    int max_length = 0;
    int position = -1;

    for (int i = 0; i < num_pwds; ++i)
    {
        const char *password = arr_pwds[i];
        int frequency = 0;

        for (int j = 0; j < num_pwds; ++j)
        {
            if (strcmp(password, arr_pwds[j]) == 0)
            {
                frequency++;
            }
        }

        int length = strlen(password);

        // Kiểm tra điều kiện để xác định mật khẩu đúng
        if (frequency > max_frequency || (frequency == max_frequency && length > max_length))
        {
            max_frequency = frequency;
            max_length = length;
            position = i;
        }
    }

    return position;

    return -1; // Nếu không tìm thấy
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////