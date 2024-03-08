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
int firstMeet(int &exp1, int &exp2, int e1) {
    // Kiểm tra giới hạn của exp1 và exp2
    exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
    exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;

    if (e1 < 0 || e1 > 99) {
        return -99; // Trả về -99 nếu e1 nằm ngoài khoảng [0, 99]
    } else if (e1 >= 0 && e1 <= 3) {
        // Xử lý trường hợp 1
        if (e1 == 0) {
            exp2 += 29;
        } else if (e1 == 1) {
            exp2 += 45;
        } else if (e1 == 2) {
            exp2 += 75;
        } else if (e1 == 3) {
            exp2 += 29 + 45 + 75;
        }

        int D = e1 * 3 + exp1 * 7;
        // Kiểm tra tính chẵn lẻ của D
        if (D % 2 == 0) {
            exp1 = (int)ceil((double)exp1 + ((double)D / 200));
        } else {
            exp1 = (int)ceil((double)exp1 - ((double)D / 100));
        }
        // Kiểm tra giới hạn của exp1 và exp2 sau khi cập nhật
        exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
        exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
    } else if (e1 >= 4 && e1 <= 19) {
        // Xử lý trường hợp 2
        exp2 += ceil((double)e1 / 4 + 19);
        exp1 -= e1;
    } else if (e1 >= 20 && e1 <= 49) {
        exp2 += ceil((double)e1 / 9 + 21);
        exp1 -= e1;
    } else if (e1 >= 50 && e1 <= 65) {
        exp2 += ceil((double)e1 / 16 + 17);
        exp1 -= e1;
    } else if (e1 >= 66 && e1 <= 79) {
        exp2 += ceil((double)e1 / 4 + 19);
        if (exp2 > 200) {
            exp2 += ceil((double)e1 / 9 + 21);
        }
        exp1 -= e1;
    } else if (e1 >= 80 && e1 <= 99) {
        exp2 += ceil((double)e1 / 4 + 19);
        exp2 += ceil((double)e1 / 9 + 21);
        if (exp2 > 400) {
            exp2 += ceil((double)e1 / 16 + 17);
            exp2 = ceil((double)exp2 * 1.15);
        }
        exp1 -= e1;
    }
    // Kiểm tra giới hạn của exp1 và exp2 trước khi trả về
    exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
    exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
    return exp1 + exp2;
}

// Task 2


int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    //conduong1
    //ham tim so chinh phuong gan nhat 
    if (E2 < 0 || E2 > 99) {
        return -99; // Trả về -99 nếu E2 nằm ngoài khoảng [0, 99]
    }
    EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
    HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
    M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
    double P1, P2, P3, P_end;
    int tong = 0;
    int S;
    int can_bac_hai_duoi = sqrt(EXP1);
    int can_bac_hai_tren = can_bac_hai_duoi + 1;
    int SCPDuoi = can_bac_hai_duoi * can_bac_hai_duoi;
    int SCPTren = can_bac_hai_tren * can_bac_hai_tren;

    if (abs(EXP1 - SCPDuoi) < abs(EXP1 - SCPTren)) {
        S = SCPDuoi;
    }
    else {
        S = SCPTren;
    }

    if (EXP1 >= S)
    {
        P1 = 1.0;
    }
    else {
        P1 = (double)(((double)EXP1 / (double)S + 80) / 123);
    }
    //conduong2
    double nua = M1 / 2;
    if (E2 % 2 == 1)
    {
        while (tong < nua)
        {
            //mua thuc an do uong
            if (HP1 < 200)
            {
                HP1 = ceil((double)HP1 * 1.3);
                HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
                M1 = M1 - 150;
                M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
                tong += 150;
            }
            else
            {
                HP1 = ceil((double)HP1 * 1.1);
                HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
                M1 = M1 - 70;
                M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
                tong += 70;
            }
            if (tong > nua)
                break;
            //taxi xe ngua
            if (EXP1 < 400)
            {
                M1 = M1 - 200;
                M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
                tong += 200;
            }
            else
            {
                M1 = M1 - 120;
                M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
                EXP1 = ceil((double)EXP1 * 1.13);
                EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
                tong += 120;
            }
            if (tong > nua)
                break;
            //ng vo gia cu
            if (EXP1 < 300)
            {
                M1 = M1 - 100;
                M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
                EXP1 = ceil((double)EXP1 * 0.9);
                EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
                tong += 100;
            }
            else
            {
                M1 = M1 - 120;
                M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
                EXP1 = ceil((double)EXP1 * 0.9);
                EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
                tong += 120;
            }
            if (tong > nua)
                break;
        }
        HP1 = ceil((double)HP1 * 0.83);
        HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
        EXP1 = ceil((double)EXP1 * 1.17);
        EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
    }
    else
    {
        while (M1 > 0)
        {
            //mua thuc an do uong
            if (HP1 < 200)
            {
                HP1 = ceil((double)HP1 * 1.3);
                HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
                M1 = M1 - 150;
                M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
            }
            else
            {
                HP1 = ceil((double)HP1 * 1.1);
                HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
                M1 = M1 - 70;
                M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
            }
            if (M1 <= 0)
            {
                M1 = 0;
                break;

            }

            //taxi xe ngua
            if (EXP1 < 400)
            {
                M1 = M1 - 200;
                M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
            }
            else
            {
                M1 = M1 - 120;
                M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
                EXP1 = ceil((double)EXP1 * 1.13);
                EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
            }
            if (M1 <= 0)
            {
                M1 = 0;
                break;
            }
            //ng vo gia cu
            if (EXP1 < 300)
            {
                M1 = M1 - 100;
                M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
                EXP1 = ceil((double)EXP1 * 0.9);
                EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
            }
            else
            {
                M1 = M1 - 120;
                M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
                EXP1 = ceil((double)EXP1 * 0.9);
                EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
            }
            break;
        }
        HP1 = ceil((double)HP1 * 0.83);
        HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
        EXP1 = ceil((double)EXP1 * 1.17);
        EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
    }
     int S2;
    int can_bac_hai_duoi2 = sqrt(EXP1);
    int can_bac_hai_tren2 = can_bac_hai_duoi2 + 1;
    int SCPDuoi2 = can_bac_hai_duoi2 * can_bac_hai_duoi2;
    int SCPTren2 = can_bac_hai_tren2 * can_bac_hai_tren2;

    if (abs(EXP1 - SCPDuoi2) < abs(EXP1 - SCPTren2)) {
        S2 = SCPDuoi2;
    }
    else {
        S2 = SCPTren2;
    }

    if (EXP1 >= S2)
    {
        P2 = 1.0;
    }
    else {
        P2 = (double)(((double)EXP1 / (double)S + 80) / 123);
    }
    //conduong3

    int P[10] = { 32,47,28,79,100,50,22,83,64,11 };
    int i, tonghaiso;
    if (E2 < 10)
    {
        i = E2;
    }
    else {
        tonghaiso = (E2 / 10) + (E2 % 10);
        i = tonghaiso % 10;
    }
    P3 = (double)P[i] / 100.0;
    if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0)
    {
        EXP1 = ceil((double)EXP1 * 0.75);
        EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
    }
    else
    {
        P_end = (P1 + P2 + P3) / 3;
        if (P_end < 0.5)
        {
            HP1 = ceil((double)HP1 * 0.85);
            HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
            EXP1 = ceil((double)EXP1 * 1.15);
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
        }
        else {
            HP1 = ceil((double)HP1 * 0.9);
            HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
            EXP1 = ceil((double)EXP1 * 1.2);
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3 //xem lai truong hop max=diem gap
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) {
        return -99; // Trả về -99 nếu E3 nằm ngoài khoảng [0, 99]
    }
    EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
    HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
    EXP2 = (EXP2 > 600) ? 600 : (EXP2 < 0) ? 0 : EXP2;
    HP2 = (HP2 > 666) ? 666 : (HP2 < 0) ? 0 : HP2;
    int tongsoduong = 0, tongsoam = 0, i_meet, j_meet;

    int a[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (a[i][j] > (E3 * 2)) {
                tongsoduong += 1;
            }
            if (a[i][j] < (-E3)) {
                tongsoam += 1;
            }
        }
    }

    i_meet = tongsoduong;
    while (i_meet > 9) {
        i_meet = i_meet / 10 + i_meet % 10;
    }

    j_meet = tongsoam;
    while (j_meet > 9) {
        j_meet = j_meet / 10 + j_meet % 10;
    }


    int maxVal = a[i_meet + 1][j_meet + 1];
    int i_meet_start = i_meet;
    int j_meet_start = j_meet;
    while (i_meet_start + 1 < 10 && j_meet_start + 1 < 10)
    {
        maxVal = max(maxVal, a[i_meet_start + 1][j_meet_start + 1]);
        i_meet_start++;
        j_meet_start++;
    }
    i_meet_start = i_meet;
    j_meet_start = j_meet;

    while (i_meet_start + 1 < 10 && j_meet_start - 1 >= 0)
    {
        maxVal = max(maxVal, a[i_meet_start + 1][j_meet_start - 1]);
        i_meet_start++;
        j_meet_start--;
    }
    i_meet_start = i_meet;
    j_meet_start = j_meet;
    while (i_meet_start - 1 >= 0 && j_meet_start + 1 < 10)
    {
        maxVal = max(maxVal, a[i_meet_start - 1][j_meet_start + 1]);
        i_meet_start--;
        j_meet_start++;
    }
    i_meet_start = i_meet;
    j_meet_start = j_meet;
    while (i_meet_start - 1 >= 0 && j_meet_start - 1 >= 0)
    {
        maxVal = max(maxVal, a[i_meet_start - 1][j_meet_start - 1]);
        i_meet_start--;
        j_meet_start--;
    }
   
        if (abs(a[i_meet][j_meet]) > abs(maxVal)) //neu khong duoi kip
        {
            HP1 -= (int)floor((1.0/10 * (double)HP1));
        EXP1 -= (int)floor((12.0/100 * (double)EXP1));
        HP2 -= (int)floor((1.0/10 *(double) HP2));
        EXP2 -= (int)floor((12.0/100 * (double)EXP2));
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
            HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
            EXP2 = (EXP2 > 600) ? 600 : (EXP2 < 0) ? 0 : EXP2;
            HP2 = (HP2 > 666) ? 666 : (HP2 < 0) ? 0 : HP2;
            return a[i_meet][j_meet];
        }
        else // neu duoi kip
        {
            HP1 += (int)ceil((1.0/10 * (double)HP1));
        EXP1 += (int)ceil((12.0/100 * (double)EXP1));
        HP2 += (int)ceil((1.0/10 * (double)HP2));
        EXP2 += (int)ceil((12.0/100 *(double)EXP2));
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
            HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
            EXP2 = (EXP2 > 600) ? 600 : (EXP2 < 0) ? 0 : EXP2;
            HP2 = (HP2 > 666) ? 666 : (HP2 < 0) ? 0 : HP2;
            return maxVal;
        }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
// Tìm độ dài của chuỗi s
    int s_length = strlen(s);

    // Tìm vị trí của ký tự '@' trong chuỗi email
    const char* at_position = strchr(email, '@');

    // Nếu không tìm thấy ký tự '@' trong email
    if (at_position == NULL) {
        return -1; // Email không hợp lệ
    }

    // Tạo một chuỗi để lưu phần trước ký tự '@' trong email
    char se[50]; // Giả sử độ dài tối đa của phần trước '@' là 50
    int se_length = at_position - email;
    strncpy(se, email, se_length);
    se[se_length] = '\0'; // Kết thúc chuỗi

    // Kiểm tra độ dài của mật khẩu
    if (s_length < 8) {
        return -1; // Độ dài không hợp lệ
    }
    else if (s_length > 20) {
        return -2; // Độ dài không hợp lệ
    }

    // Kiểm tra xem mật khẩu có chứa chuỗi se không
    const char* se_position = strstr(s, se);
    if (se_position != NULL) {
        int sei = se_position - s;
        return -(300 + sei); // Mật khẩu chứa chuỗi se
    }

    // Kiểm tra mật khẩu có chứa nhiều hơn 2 ký tự liên tiếp và giống nhau
    for (int i = 0; i < s_length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i); // Mật khẩu chứa nhiều hơn 2 ký tự giống nhau
        }
    }

    // Kiểm tra mật khẩu có chứa ký tự đặc biệt không
    bool containsSpecialChar = false;
    for (const char* ptr = s; *ptr != '\0'; ++ptr) {
        if (*ptr == '@' || *ptr == '#' || *ptr == '%' || *ptr == '$' || *ptr == '!') {
            containsSpecialChar = true;
            break;
        }
    }
    if (!containsSpecialChar) {
        return -5; // Mật khẩu không chứa ký tự đặc biệt
    }

    // Kiểm tra từng ký tự trong chuỗi
    for (int i = 0; i < s_length; ++i) {
        if (!((s[i] >= '0' && s[i] <= '9') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'A' && s[i] <= 'Z') ||
            s[i] == '@' || s[i] == '#' ||
            s[i] == '%' || s[i] == '$' ||
            s[i] == '!')) {
            return i; // Trả về vị trí sai
        }
    }

    return -10; // Mật khẩu hợp lệ
}
  

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // Đếm số lần xuất hiện của từng mật khẩu
    int maxCount = 0; // Số lần xuất hiện nhiều nhất
    int maxIndex = 0; // Chỉ số của mật khẩu xuất hiện nhiều nhất trong mảng

    for (int i = 0; i < num_pwds; ++i) {
        int passwordCount = 1; // Bắt đầu từ 1 vì đã gặp mật khẩu đầu tiên
        for (int j = i + 1; j < num_pwds; ++j) { // Bắt đầu từ i + 1 để tránh duyệt lại các mật khẩu trước đó
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                passwordCount++;
            }
        }

        // Nếu số lần xuất hiện của mật khẩu hiện tại lớn hơn số lần xuất hiện nhiều nhất
        // hoặc bằng nhau nhưng độ dài của mật khẩu hiện tại lớn hơn mật khẩu xuất hiện nhiều nhất
        if (passwordCount > maxCount || (passwordCount == maxCount && strlen(arr_pwds[i]) > strlen(arr_pwds[maxIndex]))) {
            maxIndex = i; // Cập nhật chỉ số của mật khẩu xuất hiện nhiều nhất
            maxCount = passwordCount; // Cập nhật số lần xuất hiện nhiều nhất
        }
    }

    return maxIndex; // Trả về chỉ số của mật khẩu xuất hiện nhiều nhất trong mảng
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////