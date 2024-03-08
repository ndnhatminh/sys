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
// các dụng cụ:
       //hàm làm tròn số
int lamtronso(double& number) {
    double so_thap_phan_thu2 =abs( round(number) - number);
    if ((round(number) < number)&&(so_thap_phan_thu2 >= 0.1)) {
            number += 0.5;
            number = round(number);
        }
    else number = round(number);
    return number;
}
        //các hàm check giới hạn
int CHECK_overflow_HP(int& HP) {
    if (HP <= 0) HP = 0;
    if (HP >= 666) HP = 666;
    return HP;
}
int CHECK_overflow_EXP(int& EXP) {
    if (EXP <= 0) EXP = 0;
    if (EXP >= 600) EXP = 600;
    return EXP;
}
int CHECK_overflow_MONEY(int& MONEY) {
    if (MONEY <= 0) MONEY = 0;
    if (MONEY >= 3000) MONEY = 3000;
    return MONEY;
}
//các hàm check Max value
    //hàm check max trên đường chéo trái
int Find_max_left(int Matran[10][10], int& i, int& j) {
    int max = Matran[i][j];
        //lưu vị trí ban đầu để dò hướng ngược lại
    int i_checkpoint = i;
    int j_checkpoint = j;
    while (((i < 10)&&(i>0)) || ((j < 10)&&(j>0))) {
        i++;
        j++;
        if (Matran[i][j] > max) max = Matran[i][j];
        else max = Matran[i - 1][j - 1];
    }
    i = i_checkpoint;
    j = j_checkpoint;
    while (((i < 10) && (i > 0)) || ((j < 10) && (j > 0))) {
        i--;
        j--;
        if (Matran[i][j] > max) max = Matran[i][j];
        else max = Matran[i +1][j +1];
    }
    return max;
}
    //hàm check max trên đường chéo phải
int Find_max_right(int Matran[10][10], int& i, int& j) {
    int max = Matran[i][j];
        //lưu vị trí ban đầu để dò hướng ngược lại
    int i_checkpoint = i;
    int j_checkpoint = j;
    while (((i < 10) && (i > 0)) || ((j < 10) && (j > 0))) {
        i--;
        j++;
        if (Matran[i][j] > max) max = Matran[i][j];
        else max = Matran[i + 1][j - 1];
    }
    i = i_checkpoint;
    j = j_checkpoint;
    while (((i < 10) && (i > 0)) || ((j < 10) && (j > 0))) {
        i++;
        j--;
        if (Matran[i][j] > max) max = Matran[i][j];
        else max = Matran[i - 1][j + 1];
    }
    return max;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 >= 0 && e1 <= 99) {
        double exp1_clone, exp2_clone;
        //TRƯỜNG HỢP 1:
        if (e1 >= 0 && e1 <= 3) {
            if (e1 == 0) exp2 += 29;
            else if (e1 == 1) exp2 += 45;
            else if (e1 == 2) exp2 += 75;
            else exp2 += (29 + 45 + 75);
            int D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0) {
                exp1_clone = D / 200.0;
                exp1_clone = lamtronso(exp1_clone);
                exp1 += exp1_clone;
                exp1 = CHECK_overflow_EXP(exp1);
            }
            else {
                exp1_clone = D / 100.0;
                exp1_clone = lamtronso(exp1_clone);
                exp1 -= exp1_clone;
                exp1 = CHECK_overflow_EXP(exp1);
            }   
        }
        //TRƯỜNG HỢP 2:
        if (e1 >= 4 && e1 <= 99) {
            if (e1 >= 4 && e1 <= 19) {// thông tin 1
                exp2_clone = e1 / 4.0 + 19;
                exp2_clone = lamtronso(exp2_clone);
                exp2 += exp2_clone;
                exp2 = CHECK_overflow_EXP(exp2);
            }
            else if (e1 >= 20 && e1 <= 49) {// thông tin 2
                exp2_clone = e1 / 9.0 + 21;
                exp2_clone = lamtronso(exp2_clone);
                exp2 += exp2_clone;
                exp2 = CHECK_overflow_EXP(exp2);
            }
            else if (e1 >= 50 && e1 <= 65) {// thông tin 3
                exp2_clone = e1 / 16.0 + 17;
                exp2_clone = lamtronso(exp2_clone);
                exp2 += exp2_clone;
                exp2 = CHECK_overflow_EXP(exp2);
            }
            else if (e1 >= 66 && e1 <= 99) {
                exp2_clone = e1 / 4.0 + 19;
                exp2_clone = lamtronso(exp2_clone);
                exp2 += exp2_clone;
                exp2 = CHECK_overflow_EXP(exp2);
                if (e1 <= 79 && exp2 > 200) {//thông tin 1,2
                    exp2_clone = e1 / 9.0 + 21;
                    exp2_clone = lamtronso(exp2_clone);
                    exp2 += exp2_clone;
                    exp2 = CHECK_overflow_EXP(exp2);
                }
                if (e1 >= 80 && exp2 > 400) {//thông tin 1,2,3
                    exp2_clone = e1 / 9.0 + 21;
                    exp2_clone = lamtronso(exp2_clone);
                    exp2 += exp2_clone;
                    exp2 = CHECK_overflow_EXP(exp2);
                    exp2_clone = e1 / 16.0 + 17;
                    exp2_clone = lamtronso(exp2_clone);
                    exp2 += exp2_clone;
                    exp2 = CHECK_overflow_EXP(exp2);
                    exp2_clone = exp2 * 1.15;
                    exp2 =lamtronso( exp2_clone);
                    exp2 = CHECK_overflow_EXP(exp2);
                }
            }
            exp1 -= e1;
        }
        return exp1 + exp2;
    }
    else return -99;
 }
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if (E2 >= 0 && E2 <= 99) {
        double HP1_clone, EXP1_clone;
        int S = 0;
        int daysotunhien[9] = {1,2,3,4,5,6,7,8,9};
            for (int i = 0; S >= EXP1; i++) {
                for (int j = 0; S >= EXP1; j++) {
                    S = pow(daysotunhien[i], 2) * pow(daysotunhien[j], 2);
                }
            }
        //con đường 1:
        double P1;
        if (EXP1 >= S) P1 = 1.00;
        else P1 = ((EXP1 / (S*1.0) + 80) / 123.0);
        //con đường 2:
        if (E2 % 2 != 0) { 
        double Money_need_to_paid;
        int Money_paid = 0;
        Money_need_to_paid = M1 * 0.5;
        Money_need_to_paid = lamtronso(Money_need_to_paid);
            while (Money_paid <= Money_need_to_paid ) {
                M1 = CHECK_overflow_MONEY(M1);
                // Hành động 1 mua đồ ăn
                if (Money_paid <= Money_need_to_paid) {
                    if (HP1 < 200) {//có mua đồ ăn
                        HP1_clone = HP1 * 1.3;
                        HP1 = lamtronso(HP1_clone);
                        HP1 = CHECK_overflow_HP(HP1);
                        Money_paid += 150;
                        M1 -= 150;
                        M1 = CHECK_overflow_MONEY(M1);
                    }
                    else {//chỉ mua đồ uống
                        Money_paid += 70;
                        M1 -= 70;
                        M1 = CHECK_overflow_MONEY(M1);
                        HP1_clone= HP1 * 1.1;
                         HP1 = lamtronso(HP1_clone);
                       HP1=CHECK_overflow_HP(HP1);
                    }
                }
                else break;
                //Hành động 2 chọn loại phương tiện 
                if (Money_paid <= Money_need_to_paid) {
                    if (EXP1 >= 400) {// đi bằng ngựa.
                        Money_paid += 120;
                        M1 -= 120;
                        M1 = CHECK_overflow_MONEY(M1);
                        EXP1_clone= EXP1 * 1.13;
                        EXP1 = lamtronso(EXP1_clone);
                        EXP1 = CHECK_overflow_EXP(EXP1);
                    }
                    else { // đi bằng taxi.
                        Money_paid += 200; 
                        M1 -= 200;
                            M1 = CHECK_overflow_MONEY(M1);
                    }
                }
                else break;
                if (Money_paid <= Money_need_to_paid) {// Hành động 3 trả tiền cho vô gia cư
                    if (EXP1 < 300) {//TH trả 100
                        Money_paid += 100;
                        M1 -= 100;
                        M1 = CHECK_overflow_MONEY(M1);
                        EXP1_clone= EXP1 * 0.9;
                        EXP1 = lamtronso(EXP1_clone);
                        EXP1 = CHECK_overflow_MONEY(EXP1);
                    }
                    else {//TH hợp trả 120
                        Money_paid += 120;
                        M1 -= 120;
                        M1 = CHECK_overflow_MONEY(M1);
                        EXP1_clone= EXP1 * 0.9;
                        EXP1 = lamtronso(EXP1_clone);
                        EXP1 = CHECK_overflow_EXP(EXP1);
                    }
                }
                else break;
            }
            HP1_clone= HP1 *0.83;
            HP1 = lamtronso(HP1_clone);
            HP1 = CHECK_overflow_HP(HP1);
            EXP1_clone= EXP1* 1.17; 
            EXP1 = lamtronso(EXP1_clone);
            EXP1 = CHECK_overflow_EXP(EXP1);
        }
        else {
            //Hành động 1 mua đồ ăn
            if (M1!= 0) {
                if (HP1 < 200) {//có mua đồ ăn
                    HP1_clone = HP1 * 1.3;
                    HP1 = lamtronso(HP1_clone);
                    HP1 = CHECK_overflow_HP(HP1);
                    M1 -= 150;
                    M1 = CHECK_overflow_MONEY(M1);
                }
                else {//chỉ mua đồ uống
                    M1 -= 70;
                    M1 = CHECK_overflow_MONEY(M1);
                    HP1_clone = HP1 * 1.1;
                    HP1 = lamtronso(HP1_clone);
                    HP1 = CHECK_overflow_HP(HP1);
                }
            }
            //Hành động 2 chọn loại phương tiện 
            if (M1!= 0) {
                    // đi bằng ngựa.
                if (EXP1 > 400) {
                    M1 -= 120;
                    M1 = CHECK_overflow_MONEY(M1);
                    EXP1_clone = EXP1 * 1.13;
                    EXP1 = lamtronso(EXP1_clone);
                    EXP1 = CHECK_overflow_EXP(EXP1);
                }
                else { // đi bằng taxi.
                    M1 -= 200;
                    M1 = CHECK_overflow_MONEY(M1);
                }
            }
            //Hành động 3 trả tiền cho vô gia cư
            if (M1 != 0) {
                if (EXP1 < 300) {//TH trả 100
                    M1 -= 100;
                    M1 = CHECK_overflow_MONEY(M1);
                    EXP1_clone = EXP1 * 0.9;
                    EXP1 = lamtronso(EXP1_clone);
                    EXP1 = CHECK_overflow_MONEY(EXP1);
                }
                else {//TH hợp trả 120
                    M1 -= 200;
                    M1 = CHECK_overflow_MONEY(M1);
                    EXP1_clone = EXP1 * 0.9;
                    EXP1 = lamtronso(EXP1_clone);
                    EXP1 = CHECK_overflow_EXP(EXP1);
                }
            }
            HP1_clone = HP1 * 0.83;
            HP1 = lamtronso(HP1_clone);
            HP1 = CHECK_overflow_HP(HP1);
            EXP1_clone = EXP1 * 1.17;
            EXP1 = lamtronso(EXP1_clone);
            EXP1 = CHECK_overflow_EXP(EXP1);
        }
        for (int i = 0; S >= EXP1; i++) {
            for (int j = 0; S >= EXP1; j++) {
                S = pow(daysotunhien[i], 2) * pow(daysotunhien[j], 2);
            }
        }
        double P2;
        if (EXP1 >= S) P2 = 1.00;
        else P2 = ((EXP1 /(S*1.00) + 80) / 123.0);
        // con dường 3:
        int P[10] = {32,47,28,79,100,50,22,83,64,11};
        int i;// chỉ số i
        if (E2 < 10) i = E2;
        else{ 
            int s;
            s = (E2 / 10) + (E2 % 10);// tổng hàng chục và hàng đơn vị
            i = s % 10;
        }
        int P3 = P[i];
        double P_TB = (P1*100 + P2*100 + P3) / 3;
        if (P1 == P2 && P1 == P3 && P1 == 100) {
            EXP1_clone = EXP1 * 0.75;
            EXP1 = lamtronso(EXP1_clone);
            EXP1 = CHECK_overflow_EXP(EXP1);
        }
        else if (P_TB >= 50&& P_TB<100) {
            HP1_clone = HP1 * 0.9;
            HP1 = lamtronso(HP1_clone);
            HP1 = CHECK_overflow_HP(HP1);
            EXP1_clone = EXP1 * 1.2;
            EXP1 = lamtronso(EXP1_clone);
            EXP1 = CHECK_overflow_EXP(EXP1);
        }
        else {
            HP1_clone = HP1 * 0.85;
            HP1 = lamtronso(HP1_clone);
            HP1 = CHECK_overflow_HP(HP1);
            EXP1_clone = EXP1 * 1.15;
            EXP1 = lamtronso(EXP1_clone);
            EXP1 = CHECK_overflow_EXP(EXP1);
        }
    return HP1 + EXP1 + M1;
    }
    else return -99;
}
// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    double HP1_clone, EXP1_clone, HP2_clone, EXP2_clone;
    int i, j;// Tọa độ điểm
    int positive_numbers = 0, negative_numbers = 0;//số lượng số âm số lượng số dương
    if (E3 >= 0 && E3 <= 99) {
        int Matran[10][10]{};
        //tạo map
        for (int hang= 0; hang < 10; hang++) {
            for (int cot = 0; cot < 10; cot++) {
                Matran[hang][cot] = (E3 * cot + hang * 2) * (hang - cot);
            }
        }
        for (int hang = 0; hang < 10; hang++) {
            for (int cot = 0; cot < 10; cot++) {
                // quét map 
                if (Matran[hang][cot] > (E3 * 2)) positive_numbers++;
                if (Matran[hang][cot] < -E3) negative_numbers++;
            }
        }
        //tách số
        if (positive_numbers >= 10)
        {
            i = (positive_numbers / 10) + (positive_numbers % 10);
        }
        else i = positive_numbers;
        if (i >= 10) i = (i / 10);
        if (negative_numbers >= 10) {
            j = (negative_numbers / 10) + (negative_numbers % 10);
        }
        else j = negative_numbers;
        if (j > 10) j = (j / 10);
        //chia làm 2 bài toán tìm max trên 2 đường chéo trái phải rồi so sánh chúng
        int taxi_point = Matran[i][j];
        int max_left = Find_max_left(Matran, i, j);
        int max_right = Find_max_right(Matran, i, j);
        int team_sherlock_point;
        if (max_left > max_right) team_sherlock_point = max_left;
        else team_sherlock_point = max_right;
        //so sánh 2 max trên 2 đường chéo để tìm team_sherlock_point
        if (abs(taxi_point) < team_sherlock_point) {
            EXP1_clone = EXP1 * 1.12;
            EXP1 = lamtronso(EXP1_clone);
            EXP1 = CHECK_overflow_EXP(EXP1);
            EXP2_clone = EXP2 * 1.12;
            EXP2 = lamtronso(EXP2_clone);
            EXP2 = CHECK_overflow_EXP(EXP2);
            HP1_clone = HP1 * 1.1;
            HP1 = lamtronso(HP1_clone);
            HP1 = CHECK_overflow_EXP(HP1);
            HP2_clone = HP2 * 1.1;
            HP2 = lamtronso(HP2_clone);
            HP2 = CHECK_overflow_EXP(HP2);
        }
        else {
            EXP1_clone = EXP1 * 0.88;
            EXP1 = lamtronso(EXP1_clone);
            EXP1 = CHECK_overflow_EXP(EXP1);
            EXP2_clone = EXP2 * 0.88;
            EXP2 = lamtronso(EXP2_clone);
            EXP2 = CHECK_overflow_EXP(EXP2);
            HP1_clone = HP1 * 0.9;
            HP1 = lamtronso(HP1_clone);
            HP1 = CHECK_overflow_EXP(HP1);
            HP2_clone = HP2 * 0.9;
            HP2 = lamtronso(HP2_clone);
            HP2 = CHECK_overflow_EXP(HP2);
        }
        return taxi_point;
    }
    else return -99;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    char se[91]{};
    for (int i = 0; i < 100; i++) {
        if (email[i] == '@') break;
        se[i] = email[i];
    }
    int so_ky_tu = 0;
    while (s[so_ky_tu] != '\0') so_ky_tu++;
    if (so_ky_tu >= 8 && so_ky_tu <= 20) {
        char tu;
        bool case1, case8, case14, case20, case26, case32, case38, case44, case50, case_so3, case_so9,
            case2, case9, case15, case21, case27, case33, case39, case45, case51, case_so4, case_ky_tu1,
            case3, case10, case16, case22, case28, case34, case40, case46, case52, case_so5, case_ky_tu2,
            case4, case11, case17, case23, case29, case35, case41, case47, case_so0, case_so6, case_ky_tu3,
            case5, case12, case18, case24, case30, case36, case42, case48, case_so1, case_so7, case_ky_tu4,
            case6, case13, case19, case25, case31, case37, case43, case49, case_so2, case_so8, case_ky_tu5,
            case7;
        for (int i = 0; i < so_ky_tu; i++) {
            tu = s[i];
            switch (tu) {
            case 'q': case1 = true;
                break;
            case 'w': case2 = true;
                break;
            case 'e':case3 = true;
                break;
            case 'r':case4 = true;
                break;
            case 't':case5 = true;
                break;
            case 'y':case6 = true;
                break;
            case 'u':case7 = true;
                break;
            case 'i':case8 = true;
                break;
            case 'o':case9 = true;
                break;
            case 'p':case10 = true;
                break;
            case 'a':case11 = true;
                break;
            case 's':case12 = true;
                break;
            case 'd':case13 = true;
                break;
            case 'f':case14 = true;
                break;
            case 'g':case15 = true;
                break;
            case 'h':case16 = true;
                break;
            case 'j':case17 = true;
                break;
            case 'k':case18 = true;
                break;
            case 'l':case19 = true;
                break;
            case 'z':case20 = true;
                break;
            case 'x':case21 = true;
                break;
            case 'c':case22 = true;
                break;
            case 'v':case23 = true;
                break;
            case 'b':case24 = true;
                break;
            case 'n':case25 = true;
                break;
            case 'm':case26 = true;
                break;
            case 'Q':case27 = true;
                break;
            case 'W':case28 = true;
                break;
            case 'E':case29= true;
                break;
            case 'R':case30 = true;
                break;
            case 'T':case31 = true;
                break;
            case 'Y':case32 = true;
                break;
            case 'U':case33 = true;
                break;
            case 'I':case34 = true;
                break;
            case 'O':case35 = true;
                break;
            case 'P':case36 = true;
                break;
            case 'A':case37 = true;
                break;
            case 'S':case38 = true;
                break;
            case 'D':case39 = true;
                break;
            case 'F':case40 = true;
                break;
            case 'G':case41 = true;
                break;
            case 'H':case42 = true;
                break;
            case 'J':case43 = true;
                break;
            case 'K':case44 = true;
                break;
            case 'L':case45 = true;
                break;
            case 'Z':case46 = true;
                break;
            case 'X':case47 = true;
                break;
            case 'C':case48= true;
                break;
            case 'V':case49 = true;
                break;
            case 'B':case50 = true;
                break;
            case 'N':case51 = true;
                break;
            case 'M':case52 = true;
                break;
            case '1':case_so1 = true;
                break;
            case '2':case_so2 = true;
                break;
            case '3':case_so3 = true;
                break;
            case '4':case_so4 = true;
                break;
            case '5':case_so5 = true;
                break;
            case '6':case_so6 = true;
                break;
            case '7':case_so7 = true;
                break;
            case '8':case_so8 = true;
                break;
            case '9':case_so9 = true;
                break;
            case '0':case_so0 = true;
                break;
            case '!':case_ky_tu1 = true;
                break;
            case '@':case_ky_tu2 = true;
                break;
            case '#':case_ky_tu3 = true;
                break;
            case '$':case_ky_tu4 = true;
                break;
            case '%': case_ky_tu5 = true;
                break;
            }
        }
        if ((case1 || case8 || case14 || case20 || case26 || case32 || case38 || case44 || case50 || case_so3 || case_so9 ||
            case2 || case9 || case15 || case21 || case27 || case33 || case39 || case45 || case51 || case_so4 ||
            case3 || case10 || case16 || case22 || case28 || case34 || case40 || case46 || case52 || case_so5 ||
            case4 || case11 || case17 || case23 || case29 || case35 || case41 || case47 || case_so0 || case_so6 ||
            case5 || case12 || case18 || case24 || case30 || case36 || case42 || case48 || case_so1 || case_so7 ||
            case6 || case13 || case19 || case25 || case31 || case37 || case43 || case49 || case_so2 || case_so8 ||
            case7) && (case_ky_tu1 || case_ky_tu2 || case_ky_tu3 || case_ky_tu4 || case_ky_tu5)) {
            const char* se_clone = strstr(s, se);
            if (se_clone == NULL) {
                int vi_tri_1 = 0;
                int vi_tri_2 = 1;
                int so_lan_trung = 0;
                int vi_tri_trung[3] = {};
                while (so_lan_trung <= 2) {
                    if (s[vi_tri_1] == s[vi_tri_2]) {
                        vi_tri_trung[vi_tri_1] = vi_tri_1;
                        so_lan_trung++;
                    }
                    vi_tri_1++;
                    vi_tri_2++;
                }
                int giatri_vi_tri_dau = vi_tri_trung[0];
                if (so_lan_trung > 2) return -400 -giatri_vi_tri_dau;
                else return -10;

            }
            else {
                for (int i = 0; i < 100; i++) {
                    if (se[0] == s[i]) {
                      return  -300-i;
                    }
                }
            }
        }
        else return -5;
    }
    else {
        if (so_ky_tu < 8) return -1;
        else return -2;
    }
    return -99;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int memory[num_pwds] = {};
    for (int i = 0; i < num_pwds; i++) {
        int so_lan_trung = 0;
        for (int j = 1; j < num_pwds; j++) {
            if (arr_pwds[i] == arr_pwds[j]) {
                so_lan_trung++;
            }
        }
        memory[i]= so_lan_trung;
    }
    int MAX = memory[0];
    for (int i = 1; i < num_pwds; i++) {
        if (MAX < memory[i]) MAX = memory[i];
    }
    for (int i = 0; i < num_pwds; i++) {
        if (MAX == memory[i]) return i;
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////