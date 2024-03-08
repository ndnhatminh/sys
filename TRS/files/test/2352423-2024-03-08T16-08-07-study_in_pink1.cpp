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
// Task 1
void checkEXP(int& EXP) {
    EXP = (EXP > 600) ? 600 : (EXP < 0) ? 0 : EXP;
}

void checkHP(int& HP) {
    HP = (HP < 0) ? 0 : (HP > 666) ? 666 : HP;
}

void checkM(int& M) {
    M = (M < 0) ? 0 : (M > 3000) ? 3000 : M;
}


int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 && e1  > 99) {
        return -99;
    }
    else {


        checkEXP(exp1);
        checkEXP(exp2);
        float change;

        if ((e1 >= 0) && (e1 <= 3))
        {
            if (e1 == 0) {
                exp2 += 29;
                checkEXP(exp2);

            }
            else if (e1 == 1) {
                exp2 += 45;
                checkEXP(exp2);

            }
            else if (e1 == 2) {
                exp2 += 75;
                checkEXP(exp2);

            }
            else {
                exp2 = exp2 + 29 + 45 + 75;
                checkEXP(exp2);

            }

            int D = e1 * 3 + exp1 * 7;
            if ((D % 2) == 1) {
                exp1 = ceil((float)(exp1 - (D / 100.0)));
                checkEXP(exp1);

            }
            else {
                exp1 = ceil((float)(exp1 + (D / 200.0)));
                checkEXP(exp1);

            }
        }
        else {
            if ((e1 >= 4) && (e1 <= 19)) {
                change = ceil((float)(exp2 + ((e1 / 4.0) + 19.0)));
                exp2 = change;

                checkEXP(exp2);

            }
            else if ((e1 >= 20) && (e1 <= 49)) {
                change = ceil((float)(exp2 + ((e1 / 9.0) + 21.0)));
                exp2 = change;
                checkEXP(exp2);

            }
            else if ((e1 >= 50) && (e1 <= 65)) {
                change = ceil((float)(exp2 + ((e1 / 16.0) + 17.0)));
                exp2 = change;
                checkEXP(exp2);

            }
            else if ((e1 >= 66) && (e1 <= 79))  {
                change = ceil((float)(exp2 + ((e1 / 4.0) + 19)));
                exp2 = change;
                checkEXP(exp2);
                if (exp2 > 200) {
                    change = ceil((float)(exp2 + ((e1 / 9.0) + 21)));
                    exp2 = change;
                    checkEXP(exp2);
                }
                else {
                    checkEXP(exp2);

                }
            }
            else{
                change = ceil((float)(exp2 + ((e1 / 4.0) + 19.0)));
                exp2 = change;
                checkEXP(exp2);

                change = ceil((float)(exp2 + ((e1 / 9.0) + 21.0)));
                exp2 = change;
                checkEXP(exp2);

                if (exp2 > 400) {
                    change = ceil((float)(exp2 + ((e1 / 16.0) + 17.0)));
                    exp2 = change;
                    checkEXP(exp2);

                    change = ceil((float)(exp2 * 1.15));
                    exp2 = change;
                    checkEXP(exp2);

                }
                else {
                    checkEXP(exp1);
                }

            }
            exp1 -= e1;
            checkEXP(exp1);

        }
        return exp1 + exp2;



    }
}


// Task 2

int S(int EXP1) {
    int S = round(sqrt(EXP1));
    return S * S;
}

void even1(int& HP1, int& M1, int& pay) {

    if (HP1 < 200) {
        HP1 = ceil(HP1 * 1.3);
        checkHP(HP1);
        M1 = M1 - 150;
        checkM(M1);
        pay += 150;
    }
    else {
        HP1 = ceil(HP1 * 1.10);
        checkHP(HP1);
        M1 = M1 - 70;
        checkM(M1);
        pay += 70;
    }
}

void even2(int& EXP1, int& M1, int& pay) {
    if (EXP1 < 400) {
        EXP1 = ceil(EXP1 * 1.13);
        checkEXP(EXP1);
        M1 = M1 - 200;
        checkM(M1);
        pay += 200;

    }
    else {
        EXP1 = ceil(EXP1 * 1.13);
        checkEXP(EXP1);
        M1 = M1 - 120;
        checkM(M1);
        pay += 120;
    }
}

void even3(int& EXP1, int& M1, int& pay) {
    if (EXP1 < 300) {
        EXP1 = ceil(EXP1 * 0.90);
        checkEXP(EXP1);
        M1 = M1 - 100;
        checkM(M1);
        pay = pay + 100;
    }
    else {
        EXP1 = ceil(EXP1 * 0.90);
        checkEXP(EXP1);
        M1 = M1 - 120;
        checkM(M1);
        pay = pay + 120;
    }
}

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    checkEXP(EXP1);
    checkHP(HP1);
    checkM(M1);

    if (E2 < 0 && E2  > 99) {
        return -99;
    }
    else {
        float P1;
        int S1 = S(EXP1);
        float P2;
        int pay = 0;
        int half = M1 * 0.5;

        if (EXP1 >= S1) {
            P1 = 1;
        }
        else {
            P1 = (((float)EXP1 / S1) + 80) / 123;
        }

        if (E2 % 2 == 1) {
            while (pay < half) {
                even1(HP1, M1, pay);
                if (pay > half)
                    break;
                even2(EXP1, M1, pay);
                if (pay > half)
                    break;
                even3(EXP1, M1, pay);
                if (pay > half)
                    break;
            }
            HP1 = ceil(HP1 * 0.83);
            checkHP(HP1);
            EXP1 = ceil(EXP1 * 1.17);
            checkEXP(EXP1);
        }
        else {
            even1(HP1, M1, pay);
            if (M1 > 0)
            {
                even2(EXP1, M1, pay);
                if (M1 > 0)
                {
                    even3(EXP1, M1, pay);
                }
            }
            HP1 = ceil(HP1 * 0.83);
            checkHP(HP1);
            EXP1 = ceil(EXP1 * 1.17);
            checkEXP(EXP1);
        }
        int S2 = S(EXP1);
        if (EXP1 >= S2) {
            P2 = 1;
        }
        else {
            P2 = (((float)EXP1 / (float)S2 + 80)) / 123;
        }
        float P;
        int i;
        int P_i[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        float P3;
        if (E2 < 10) {
            i = E2;
            P3 = (float)P_i[i] / 100;
        }
        else {
            i = (E2 / 10 + E2 % 10) % 10;
            P3 = (float)P_i[i];
        }

        if (P1 == 1 && P2 == 1 && P3 == 1) {
            EXP1 = ceil(EXP1 * 0.75);
            checkEXP(EXP1);
        }
        else {
            P = (P1 + P2 + P3) / 3;
            if (P < 0.5) {
                HP1 = ceil(HP1 * 0.85);
                checkHP(HP1);
                EXP1 = ceil(EXP1 * 1.15);
                checkEXP(EXP1);


            }
            else {

                HP1 = ceil(HP1 * 0.9);
                checkHP(HP1);
                EXP1 = ceil(EXP1 * 1.2);
                checkEXP(EXP1);

            }
        }
        return HP1 + EXP1 + M1;
    }
}



//// Task 3
int sumint(int a) {
    int sum = 0;
    while (a != 0) {
        sum = sum + a % 10;
        a /= 10;
    }
    return sum;
}



int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    checkHP(HP1);
    checkHP(HP2);
    checkEXP(EXP1);
    checkEXP(EXP2);

    
    
    
    int lon_hon = 0;
    int nho_hon = 0;
    int ma_tran[10][10];
    int duong_tat;
    int tri_duong_tat;
    int taxi;
    double a;
    if (E3 > 99 || E3 < 0) {
        return -99;
   }
    else
    {
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                ma_tran[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                if ((E3 * 2) < ma_tran[i][j])
                {
                    lon_hon++;
                }
                if ((-E3) > ma_tran[i][j])
                {
                    nho_hon++;
                }
            }
        }
        while ((lon_hon / 10) > 0)
        {
            lon_hon = sumint(lon_hon);
        }
        while ((nho_hon / 10) > 0)
        {
            nho_hon = sumint(nho_hon);
        }
        int gia_tri_i = lon_hon, gia_tri_j = nho_hon;
        duong_tat = ma_tran[lon_hon][nho_hon];
        //tinh cheos trai ma di len
        while ((gia_tri_i != 0) && (gia_tri_j != 0))
        {
            gia_tri_i--;
            gia_tri_j--;
            if (duong_tat < ma_tran[gia_tri_i][gia_tri_j])
            {
                duong_tat = ma_tran[gia_tri_i][gia_tri_j];
            }
        }
        gia_tri_i = lon_hon; gia_tri_j = nho_hon;
        //tinh cheo trai ma di xuong
        while ((gia_tri_i != 9) && (gia_tri_j != 9))
        {
            gia_tri_i++;
            gia_tri_j++;
            if (duong_tat < ma_tran[gia_tri_i][gia_tri_j])
            {
                duong_tat = ma_tran[gia_tri_i][gia_tri_j];
            }
        }
        gia_tri_i = lon_hon; gia_tri_j = nho_hon;
        //tinh cheo phai ma di len
        while ((gia_tri_i != 9) && (gia_tri_j != 0))
        {
            gia_tri_i++;
            gia_tri_j--;
            if (duong_tat < ma_tran[gia_tri_i][gia_tri_j])
            {
                duong_tat = ma_tran[gia_tri_i][gia_tri_j];
            }
        }
        gia_tri_i = lon_hon; gia_tri_j = nho_hon;
        //tinh cheo phai ma di xuong
        while ((gia_tri_i != 0) && (gia_tri_j != 9))
        {
            gia_tri_i--;
            gia_tri_j++;
            if (duong_tat < ma_tran[gia_tri_i][gia_tri_j])
            {
                duong_tat = ma_tran[gia_tri_i][gia_tri_j];
            }
        }
        tri_duong_tat = abs(duong_tat);
        taxi = abs(ma_tran[lon_hon][nho_hon]);

        if (taxi > duong_tat)
        {
            a = (double)(EXP1 * 1) - (EXP1 * 0.12);
            EXP1 = ceil(a);
            a = (double)(EXP2 * 1) - (EXP2 * 0.12);
            EXP2 = ceil(a);
            a = (double)(HP1 * 1) - (HP1 * 0.1);
            HP1 = ceil(a);
            a = (double)(HP2 * 1) - (HP2 * 0.1);
            HP2 = ceil(a);
        }
        else {
            a = (double)(EXP1 * 1) + (EXP1 * 0.12);
            EXP1 = ceil(a);
            a = (double)(EXP2 * 1) + (EXP2 * 0.12);
            EXP2 = ceil(a);
            a = (double)(HP1 * 1) + (HP1 * 0.1);
            HP1 = ceil(a);
            a = (double)(HP2 * 1) + (HP2 * 0.1);
            HP2 = ceil(a);
        }
        int tra_ve;
        if (taxi > tri_duong_tat) {
            tra_ve = ma_tran[lon_hon][nho_hon];
        }
        else {
            tra_ve = duong_tat;
        }
        return tra_ve;
        //task 3 completed.
    }
}


// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    // Tách chuỗi email để lấy phần trước ký tự '@'
    string se = string(email).substr(0, string(email).find('@'));
    // Chuyển đổi mật khẩu từ const char* sang string để dễ dàng xử lý
    string password = string(s);
    // Lấy độ dài của mật khẩu
    int len = password.length();
    // Kiểm tra xem mật khẩu có ngắn hơn 8 ký tự hay không
    if (len < 8) return -1;
    // Kiểm tra xem mật khẩu có dài hơn 20 ký tự hay không
    if (len > 20) return -2;
    // Kiểm tra xem mật khẩu có chứa chuỗi se hay không
    if (password.find(se) != string::npos) return -(300 + password.find(se));
    // Kiểm tra xem mật khẩu có chứa nhiều hơn 2 ký tự liên tiếp và giống nhau hay không
    for (int i = 0; i < len - 2; i++) {
        if (password[i] == password[i + 1] && password[i + 1] == password[i + 2]) return -(400 + i);
    }
    // Định nghĩa các ký tự đặc biệt
    string special_chars = "@#%$!";
    // Kiểm tra xem mật khẩu có chứa ít nhất một ký tự đặc biệt hay không
    bool has_special_char = false;
    for (char c : password) {
        if (special_chars.find(c) != string::npos) {
            has_special_char = true;
            break;
        }
    }
    // Nếu mật khẩu không chứa ký tự đặc biệt, trả về -5
    if (!has_special_char) return -5;
    // Kiểm tra xem mật khẩu có chứa ký tự không hợp lệ hay không
    for (char c : password) {
        if (!(('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || special_chars.find(c) != string::npos)) {
            return password.find(c);
        }
    }
    // Nếu mật khẩu thỏa mãn tất cả các điều kiện, trả về -10
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
 
        // Khởi tạo các biến để lưu trữ độ dài mật khẩu dài nhất, số lần xuất hiện nhiều nhất và chỉ số của mật khẩu đúng
        int max_length = 0;
        int max_count = 0;
        int index = -1;

        // Duyệt qua mảng arr_pwds
        for (int i = 0; i < num_pwds; ++i) {
            // Khởi tạo biến đếm số lần xuất hiện của mật khẩu hiện tại
            int count = 0;
            // Duyệt qua mảng arr_pwds một lần nữa để đếm số lần xuất hiện của mật khẩu hiện tại
            for (int j = 0; j < num_pwds; ++j) {
                // Nếu mật khẩu hiện tại giống với mật khẩu tại vị trí j thì tăng biến đếm lên 1
                if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                    ++count;
                }
            }

            // Lấy độ dài của mật khẩu hiện tại
            int length = strlen(arr_pwds[i]);
            // Nếu mật khẩu hiện tại xuất hiện nhiều hơn mật khẩu trước đó hoặc nếu nó xuất hiện cùng số lần nhưng dài hơn, thì nó sẽ được chọn làm mật khẩu đúng
            if (count > max_count || (count == max_count && length > max_length)) {
                max_count = count;
                max_length = length;
                index = i;
            }
        }

        // Trả về chỉ số của mật khẩu đúng đầu tiên trong mảng
        return index;
}




////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////