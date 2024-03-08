#include "study_in_pink1.h"

bool readFile(
    const string& filename,
    int& HP1,
    int& HP2,
    int& EXP1,
    int& EXP2,
    int& M1,
    int& M2,
    int& E1,
    int& E2,
    int& E3
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
void xu_ly_thong_so_HP1(int& HP1) {
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
}
void xu_ly_thong_so_HP2(int& HP2) {
    if (HP2 < 0) HP2 = 0;
    if (HP2 > 666) HP2 = 666;
}
void xu_ly_thong_so_EXP1(int& EXP1) {
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
}
void xu_ly_thong_so_EXP2(int& EXP2) {
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 600) EXP2 = 600;
}

void xu_ly_thong_so_M1(int& M1) {
    if (M1 < 0) M1 = 0;
    if (M1 > 3000) M1 = 3000;
}
void xu_ly_thong_so_M2(int& M2) {
    if (M2 < 0) M2 = 0;
    if (M2 > 3000) M2 = 3000;
}

// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {
    xu_ly_thong_so_EXP1(EXP1);
    xu_ly_thong_so_EXP2(EXP2);

    // TODO: Complete this function
    if (E1 < 0 || E1>99) return -99;

    int temp = 0;
    if (E1 >= 0 && E1 <= 3) {
        switch (E1)
        {
        case 0: {
            EXP2 += 29.0;
            xu_ly_thong_so_EXP2(EXP2);
            break;
        }
        case 1: {
            EXP2 += 45;
            xu_ly_thong_so_EXP2(EXP2);
            break;
        }
        case 2: {
            EXP2 += 75;
            xu_ly_thong_so_EXP2(EXP2);
            break;
        }
        case 3: {
            EXP2 += (29 + 45 + 75);
            xu_ly_thong_so_EXP2(EXP2);
            break;
        }
        }
        int D;
        D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0) {
            EXP1 = ceil(EXP1 + (float)D / 200.0);

            xu_ly_thong_so_EXP1(EXP1);
        }
        else {
            EXP1 = ceil(EXP1 - D / 100.0);

            xu_ly_thong_so_EXP1(EXP1);
        }
    }


    else {
        if (E1 >= 4 && E1 <= 19) {
            EXP2 = ceil(EXP2 + (E1 / 4.0 + 19.0));

            xu_ly_thong_so_EXP2(EXP2);
        }
        if (E1 >= 20 && E1 <= 49) {
            EXP2 = ceil(EXP2 + (E1 / 9.0 + 21.0));

            xu_ly_thong_so_EXP2(EXP2);
        }
        if (E1 >= 50 && E1 <= 65) {
            EXP2 = ceil(EXP2 + (E1 / 16.0 + 17.0));
            xu_ly_thong_so_EXP2(EXP2);
        }
        if (E1 >= 66 && E1 <= 79)
        {
            EXP2 = ceil(EXP2 + (E1 / 4.0 + 19.0));

            xu_ly_thong_so_EXP2(EXP2);
            if (EXP2 > 200) {
                EXP2 = ceil(EXP2 + (E1 / 9.0 + 21.0));

                xu_ly_thong_so_EXP2(EXP2);
            }
        }
        if (E1 >= 80 && E1 <= 99)
        {
            EXP2 = ceil(EXP2 + (E1 / 4.0 + 19.0));

            EXP2 = ceil(EXP2 + (E1 / 9.0 + 21.0));

            if (EXP2 > 400)
            {
                EXP2 = ceil(EXP2 + (E1 / 16.0 + 17.0));

                temp += 1;
            }
        }
        if (temp == 1) {
            EXP2 = ceil(1.15 * EXP2);

            xu_ly_thong_so_EXP2(EXP2);
        }
        EXP1 = EXP1 - E1;
        xu_ly_thong_so_EXP1(EXP1);

    }


    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2>99) return -99;
    xu_ly_thong_so_HP1(HP1);
    xu_ly_thong_so_EXP1(EXP1);
    xu_ly_thong_so_M1(M1);

    double xac_xuat_1 = 0.0, xac_xuat_2 = 0.0, xac_xuat_3, xac_xuat_tb = 0.0; // quy về số thập phân
    //duong1
    float p = round(sqrt(EXP1));
    float S = pow(p, 2);
    if (EXP1 >= S) {
        xac_xuat_1 = 100.0;
    }
    else xac_xuat_1 = (EXP1 / S + 80.0) / 123.0;

    xac_xuat_1 = xac_xuat_1 * 100.0;

    //chỗ này để thử xác suất 1
    //conduong2
    int so_tien_ban_dau = M1;
    int so_tien_can_tra = 0;
    if (M1 == 0) {
        goto HERE;
    }
    //nếu e2 = 0 thì không làm gì hết
    if (E2 % 2 != 0) {

        do {//roundup chỗ này lên
            //mua đồ ăn
            if (HP1 < 200) {
                HP1 = ceil(1.3 * HP1);
                M1 = M1 - 150;
                so_tien_can_tra = so_tien_can_tra + 150;
            }
            else {
                HP1 = ceil(1.1 * HP1);
                M1 = M1 - 70;
                so_tien_can_tra = so_tien_can_tra + 70;
            }
            xu_ly_thong_so_HP1(HP1);
            xu_ly_thong_so_M1(M1);
            if (so_tien_can_tra >= (0.5 * so_tien_ban_dau)) break;
            //đi xe
            if (EXP1 < 400) {
                M1 = M1 - 200;
                so_tien_can_tra = so_tien_can_tra + 200;
            }
            else {
                M1 = M1 - 120;
                so_tien_can_tra = so_tien_can_tra + 120;
            }
            xu_ly_thong_so_M1;
            EXP1 = ceil(1.13 * EXP1);
            xu_ly_thong_so_EXP1(EXP1);
            if (so_tien_can_tra >= (0.5 * so_tien_ban_dau)) break;
            //gặp người vô gia cư
            if (EXP1 < 300) {
                M1 = M1 - 100;
                so_tien_can_tra = so_tien_can_tra + 100;
            }
            else {
                M1 -= 120;
                so_tien_can_tra = so_tien_can_tra + 120;
            }
            xu_ly_thong_so_M1(M1);
            EXP1 = ceil(0.9 * EXP1);
            xu_ly_thong_so_EXP1(EXP1);
            if (so_tien_can_tra >= (0.5 * so_tien_ban_dau)) break;
        } while (so_tien_can_tra < (0.5 * so_tien_ban_dau));


    }
    else { //nếu e2 chẵn

        //mua đồ ăn
        if (HP1 < 200) {
            HP1 = ceil(1.3 * HP1);
            M1 = M1 - 150;
        }
        else {
            HP1 = ceil(1.1 * HP1);
            M1 = M1 - 70;
        }
        xu_ly_thong_so_HP1(HP1);
        xu_ly_thong_so_M1(M1);
        if (M1 == 0) goto else1;
        //đi xe
        if (EXP1 < 400) {
            M1 = M1 - 200;
        }
        else {
            M1 = M1 - 120;
        }
        xu_ly_thong_so_M1(M1);
        EXP1 = ceil(1.13 * EXP1);
        xu_ly_thong_so_EXP1(EXP1);

        if (M1 == 0) goto else1;
        //gặp người vô gia cư
        if (EXP1 < 300) {
            M1 = M1 - 100;
        }
        else {
            M1 -= 120;
        }
        xu_ly_thong_so_M1(M1);
        EXP1 = ceil(0.9 * EXP1);
        xu_ly_thong_so_EXP1(EXP1);

    }
else1:
    HP1 = ceil(0.83 * HP1);
    EXP1 = ceil(1.17 * EXP1);
    xu_ly_thong_so_EXP1(EXP1);
    xu_ly_thong_so_HP1(HP1);


HERE:
    float z = round(sqrt(EXP1));
    float R = pow(z, 2);
    if (EXP1 >= R) {
        xac_xuat_2 = 100;
    }
    else xac_xuat_2 = 100 * ((EXP1 / R + 80.0) / 123.0);


    //con đường 3
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i;//chi_so_gia_tri_xac_suat
    if (E2 >= 0 && E2 <= 9) xac_xuat_3 = P[E2];
    else {
        i = ((E2 % 10) + (E2 / 10)) % 10;
        xac_xuat_3 = P[i];
    }

    //chỗ này sai
     //tính toán xác suất trung bình
    if (xac_xuat_1 == 100.0 && xac_xuat_2 == 100.0 && xac_xuat_3 == 100) EXP1 = 0.75 * EXP1;
    else  xac_xuat_tb = (xac_xuat_1 + xac_xuat_2 + xac_xuat_3) / 3;

    if (xac_xuat_tb < 50) {
        HP1 = ceil(HP1 * 0.85);  xu_ly_thong_so_HP1(HP1);
        EXP1 = ceil(EXP1 * 1.15);  xu_ly_thong_so_EXP1(EXP1);
    }
    else {
        HP1 = ceil(HP1 * 0.9);
        xu_ly_thong_so_HP1(HP1);
        EXP1 = ceil(EXP1 * 1.2);
        xu_ly_thong_so_EXP1(EXP1);
    }
    //coi lại biến và kiểm tra lại các th
    return HP1 + EXP1 + M1;
}

// Task 3


int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3>99) return -99;
    int a[10][10] = { 0 };
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int cnt_i = 0;
    for (int t = 0; t <= 9; t++) {
        for (int e = 0; e < 9; e++) {
            if (a[t][e] > (E3 * 2)) {
                cnt_i += 1;
            }
        }
    }
    int cnt_j = 0;
    for (int m = 0; m <= 9; m++) {
        for (int n = 0; n < 9; n++) {
            if (a[m][n] < -E3) {
                cnt_j += 1;
            }
        }
    }
    int toa_do_i = ((((cnt_i % 10) + (cnt_i / 10)) % 10) + (((cnt_i % 10) + (cnt_i / 10)) / 10));



    int toa_do_j = ((((cnt_j % 10) + (cnt_j / 10)) % 10) + (((cnt_j % 10) + (cnt_j / 10)) / 10));


    //nhanh thu nhat
    int h = toa_do_i;
    int k = toa_do_j;
    int MAX = a[toa_do_i][toa_do_j];
    while (toa_do_i > 0 && toa_do_j > 0) {
        toa_do_i = toa_do_i - 1;
        toa_do_j = toa_do_j - 1;
        if (a[toa_do_i][toa_do_j] > MAX) MAX = a[toa_do_i][toa_do_j];
    }
    toa_do_i = h;
    toa_do_j = k;
    while (toa_do_i > 0 && toa_do_j < 9) {
        toa_do_i = toa_do_i - 1;
        toa_do_j = toa_do_j + 1;
        if (a[toa_do_i][toa_do_j] > MAX) MAX = a[toa_do_i][toa_do_j];
    }
    toa_do_i = h;
    toa_do_j = k;
    while (toa_do_i < 9 && toa_do_j < 9) {
        toa_do_i = toa_do_i + 1;
        toa_do_j = toa_do_j + 1;
        if (a[toa_do_i][toa_do_j] > MAX) MAX = a[toa_do_i][toa_do_j];
    }
    toa_do_i = h;
    toa_do_j = k;
    while (toa_do_i < 9 && toa_do_j > 0) {
        toa_do_i = toa_do_i + 1;
        toa_do_j = toa_do_j - 1;
        if (a[toa_do_i][toa_do_j] > MAX) MAX = a[toa_do_i][toa_do_j];
    }

    xu_ly_thong_so_HP1(HP1);
    xu_ly_thong_so_HP2(HP2);
    xu_ly_thong_so_EXP1(EXP1);
    xu_ly_thong_so_EXP2(EXP2);

    if (abs(a[h][k]) > abs(MAX)) {//check thử round hay 
        EXP1 = 0.88 * EXP1; ceil(EXP1);
        HP1 = 0.9 * HP1; ceil(HP1);
        EXP2 = 0.88 * EXP2; ceil(EXP2);
        HP2 = 0.9 * HP2; ceil(HP2);

    }

    else {
        EXP1 = 1.12 * EXP1; ceil(EXP1);
        HP1 = 1.1 * HP1; ceil(HP1);
        EXP2 = 1.12 * EXP2; ceil(EXP2);
        HP2 = 1.1 * HP2; ceil(HP2);

    }
    xu_ly_thong_so_HP1(HP1);
    xu_ly_thong_so_HP2(HP2);
    xu_ly_thong_so_EXP1(EXP1);
    xu_ly_thong_so_EXP2(EXP2);

    int trave;
    if (abs(a[h][k]) > abs(MAX)) {
        trave = a[h][k];
    }
    else {
        trave = MAX;
    }
    return trave;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function

    string copy = email;
    string ki_tu_dac_biet_1 = "@";
    string ki_tu_dac_biet_2 = "#";
    string ki_tu_dac_biet_3 = "$";
    string ki_tu_dac_biet_4 = "%";
    string ki_tu_dac_biet_5 = "!";
    string se = copy.erase(copy.find("@"));
    string str = s;
    if (strlen(s) < 8) return -1;
    if (strlen(s) > 20) return -2;
    int found = str.find(se);//neu thay loi thi thay int bang size_t
    if (found < str.length() && found >= 0) return -(300 + found);

    size_t vitri_ki_tu_dac_biet_1 = str.find(ki_tu_dac_biet_1);
    size_t vitri_ki_tu_dac_biet_2 = str.find(ki_tu_dac_biet_2);
    size_t vitri_ki_tu_dac_biet_3 = str.find(ki_tu_dac_biet_3);
    size_t vitri_ki_tu_dac_biet_4 = str.find(ki_tu_dac_biet_4);
    size_t vitri_ki_tu_dac_biet_5 = str.find(ki_tu_dac_biet_5);

    if ((vitri_ki_tu_dac_biet_1 >= 0 && vitri_ki_tu_dac_biet_1 <= strlen(s)) || (vitri_ki_tu_dac_biet_2 >= 0 && vitri_ki_tu_dac_biet_2 <= strlen(s)) || (vitri_ki_tu_dac_biet_3 >= 0 && vitri_ki_tu_dac_biet_3 <= strlen(s)) || (vitri_ki_tu_dac_biet_4 >= 0 && vitri_ki_tu_dac_biet_4 <= strlen(s)) || (vitri_ki_tu_dac_biet_5 >= 0 && vitri_ki_tu_dac_biet_5 <= strlen(s)));
    else if ((vitri_ki_tu_dac_biet_1 == std::string::npos) && (vitri_ki_tu_dac_biet_2 == std::string::npos) && (vitri_ki_tu_dac_biet_3 == std::string::npos) && (vitri_ki_tu_dac_biet_4 == std::string::npos) && (vitri_ki_tu_dac_biet_1 == std::string::npos)) return -5;


    for (int i = 0; i < strlen(s); i++) {
        if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z')))
            return i;
    }
    for (int j = 0; j <= strlen(s); j++) {
        if (s[j] == s[j + 1] && s[j] == s[j + 2]) return -(400 + (j));
    }

    return -10;
}

// Task 5

    int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
        

        string mang_mat_khau[100];
        //tach mang
        for (int z = 0; z < num_pwds; z++) {
            mang_mat_khau[z] = arr_pwds[z];
        }
        //dem so lan xuat hien 
        int dem[100] = { 0 };
        for (int i = 0; i < num_pwds; i++)
        {
            for (int j = 0; j < num_pwds; j++) {
                if (mang_mat_khau[i] == mang_mat_khau[j])
                    dem[i] += 1;
            }
        }
        //tim gia tri max
        int Max = dem[0];
        for (int t = 0; t < num_pwds; t++) {
            if (dem[t] > Max) Max = dem[t];
        }

        //mat khau da loc
        string censored_mk[100] = {};
        for (int m = 0; m < num_pwds; m++) {
            if (dem[m] == Max) {
                censored_mk[m] = mang_mat_khau[m];
            }
        }

        int dem_sokitu[100] = {};
        for (int n = 0; n < num_pwds; n++) {
            dem_sokitu[n] = censored_mk[n].length();
        }
        int Max_sokitu = dem_sokitu[0];
        int vitricantrave = 0;
        for (int p = 0; p < num_pwds; p++) {
            if (dem_sokitu[p] > Max_sokitu) {
                Max_sokitu = dem_sokitu[p];
                vitricantrave = p;
                break;
            }
        }

        return vitricantrave;
    }



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////