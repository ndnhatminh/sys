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
void conhp(int& hp) {
    if (hp < 0) hp = 0;
    if (hp > 666) hp = 666;
}

void conexp(int& exp) {
    if (exp < 0) exp = 0;
    if (exp > 600) exp = 600;
}

void conm(int& m) {
    if (m < 0) m = 0;
    if (m > 3000) m = 3000;
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) 
{
    if (E1 > 99 || E1 < 0) { return -99; }
    int D;
    D = E1 * 3.0 + EXP1 * 7.0;
    switch (E1) {
    case 0:
        EXP2 += 29;
        break;
    case 1:
        EXP2 += 45;
        break;
    case 2:
        EXP2 += 75;
        break;
    case 3:
        EXP2 += 149;
        break;
    }
    if (E1 >= 0 && E1 <= 3) {
        if (D % 2 == 0) {
            EXP1 = ceil(EXP1 + (D / 200.0));
        }
        else {

            EXP1 = ceil(EXP1 - (D / 100.0));
        }
    }
    else  if (E1 >= 4 && E1 <= 19)
    {
        EXP2 = ceil(EXP2 + (E1 / 4.0 + 19.0));
        EXP1 -= E1;
    }
    else if (E1 >= 20 && E1 <= 49) {
        EXP2 = ceil(EXP2 + (E1 / 9.0 + 21.0));
        EXP1 -= E1;
    }
    else if (E1 >= 50 && E1 <= 65) {
        EXP2 = ceil(EXP2 + (E1 / 16.0 + 17.0));
        EXP1 -= E1;
    }
    else if (E1 >= 66 && E1 <= 79) {
        EXP2 = ceil(EXP2 + (E1 / 4.0 + 19.0));
        if (EXP2 > 200) {
            EXP2 = ceil(EXP2 + (E1 / 9.0 + 21.0));
        }
        EXP1 -= E1;
    }
    if (E1 >= 80 && E1 <= 99)
    {
        EXP2 = ceil(EXP2 + (E1 / 4.0 + 19.0));//40
        EXP2 = ceil(EXP2 + (E1 / 9.0 + 21.0)); //31 327
        EXP1 -= E1;
        if (EXP2 > 400) {
            EXP2 = ceil(EXP2 + (E1 / 16.0 + 17.0));
            EXP2 = ceil(EXP2 + (EXP2 * 15.0 / 100.0));
        }
    }

    if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    if (EXP2 > 600)
    {
        EXP2 = 600;
    }
    if (EXP1 < 0)
    {
        EXP1 = 0;
    }
    if (EXP2 < 0)
    {
        EXP2 = 0;
    }

    return EXP1 + EXP2;
}
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 < 0 || E2 > 99) return -99;
    conm(M1); conhp(HP1); conexp(EXP1);
    int s, spend = 0;
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 }, i;
    double hm = 0.5 * M1;
    double p1, p2, p3, _p;
    // Way 1
    s = pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= s) p1 = 1;
    else p1 = ((double(EXP1) / s) + 80) / 123;

    // Way 2
    if (E2 % 2 != 0) {
        while (spend <= hm) {
            // Event 1
            if (HP1 < 200) {
                HP1 = ceil(double(HP1 * 130) / 100);
                conhp(HP1);
                spend += 150;
            }
            else {
                HP1 = ceil(double(HP1 * 110) / 100);
                conhp(HP1);
                spend += 70;
            }
            if (spend > hm) break;
            // Event 2
            if (EXP1 < 400) {
                spend += 200;
            }
            else {
                spend += 120;
            }
            EXP1 = ceil(double(EXP1 * 113) / 100);
            conexp(EXP1);
            if (spend > hm) break;
            // Event 3
            if (EXP1 < 300) {
                spend += 100;
            }
            else {
                spend += 120;
            }
            EXP1 = ceil(double(EXP1 * 90) / 100);
            conexp(EXP1);
        }
        EXP1 = ceil(double(EXP1 * 117) / 100);
        conexp(EXP1);
        HP1 = ceil(double(HP1 * 83) / 100);
        conhp(HP1);
        M1 -= spend;
        conm(M1);
    }
    else {
        // Event 1
        if (HP1 < 200) {
            HP1 = ceil(double(HP1 * 130) / 100);
            conhp(HP1);
            M1 -= 150;
            conm(M1);
        }
        else {
            HP1 = ceil(double(HP1 * 110) / 100);
            conhp(HP1);
            M1 -= 70;
            conm(M1);
        }
        if (M1 == 0) goto walk;
        // Event 2
        if (EXP1 < 400) {
            M1 -= 200;
            conm(M1);
        }
        else {
            M1 -= 120;
            conm(M1);
        }
        EXP1 = ceil(double(EXP1 * 113) / 100);
        conexp(EXP1);
        if (M1 == 0) goto walk;
        // Event 3
        if (EXP1 < 300) {
            M1 -= 100;
            conm(M1);
        }
        else {
            M1 -= 120;
            conm(M1);
        }
        EXP1 = ceil(double(EXP1 * 90) / 100);
        conexp(EXP1);
    walk:
        EXP1 = ceil(double(EXP1 * 117) / 100);
        conexp(EXP1);
        HP1 = ceil(double(HP1 * 83) / 100);
        conhp(HP1);
    }
    s = pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= s) p2 = 1;
    else p2 = ((double(EXP1) / s) + 80) / 123;
    // Way 3
    if (E2 >= 0 && E2 < 10) i = E2;
    if (E2 >= 10 && E2 < 100) {
        i = (E2 / 10 + E2 % 10) % 10;
    }
    p3 = P[i];
    // Caclculate
    p1 *= 100; p2 *= 100;
    if (p1 == 100 && p2 == 100 && p3 == 100) EXP1 = ceil(double(EXP1 * 75) / 100);
    else {
        _p = (p1 + p2 + p3) / 3;
        if (_p < 50) {
            HP1 = ceil(double(HP1 * 85) / 100);
            EXP1 = ceil(double(EXP1 * 115) / 100);
            conhp(HP1);
            conexp(EXP1);
        }
        else {
            HP1 = ceil(double(HP1 * 90) / 100);
            EXP1 = ceil(double(EXP1 * 120) / 100);
            conhp(HP1);
            conexp(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}
        
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    // Khoi tao ma tran 10x10 voi gia tri 0
    return -1;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    int len = strlen(s);
    int emailLen = strlen(email);
    char se[101];
    int sei = 0;

    int i;
    for (i = 0; i < emailLen && email[i] != '@'; i++) {
        se[i] = email[i];
    }
    se[i] = '\0';

    if (len < 8) {
        return -1;
    }
    if (len > 20) {
        return -2;
    }

    if (strstr(s, se) != NULL) {
        sei = strstr(s, se) - s;
        return -(300 + sei);
    }

    for (int i = 0; i < len - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }

    if (strpbrk(s, "@#%$!") == NULL) {
        return -5;
    }

    for (int i = 0; i < len; i++) {
        if (!((s[i] >= '0' && s[i] <= '9') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))) {
            return i;
        }
    }
    return -10;
}

// Task 5 
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int maxCount = 0;
    int maxLength = 0;
    string correctPassword = "";

    // Bản đồ để lưu đếm của mỗi mật khẩu


    // Kiểm tra từng mật khẩu trong mảng
    for (int i = 0; i < num_pwds; i++) {
        const char* password = arr_pwds[i];
        int count = 0;
        int length = strlen(password);

        // Đếm số lần xuất hiện của mỗi mật khẩu
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[j], password) == 0) {
                count++;
            }
        }

        // Cập nhật đếm trong bản đồ

        // Kiểm tra xem mật khẩu hiện tại có nhiều lần xuất hiện hơn hoặc dài hơn không
        if (count > maxCount || (count == maxCount && length > maxLength)) {
            maxCount = count;
            maxLength = length;
            correctPassword = password;
        }
    }

    // Tìm vị trí của mật khẩu đúng trong mảng
    for (int i = 0; i < num_pwds; i++) {
        if (strcmp(arr_pwds[i], correctPassword.c_str()) == 0) {
            return i;
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy mật khẩu đúng
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////



