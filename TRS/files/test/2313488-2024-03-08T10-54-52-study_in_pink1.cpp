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
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 < 0 || e1 > 99) return -99;
    //TH1
    if (e1 >= 0 && e1 <= 3) {
        switch (e1) {
        case 0:
            exp2 = exp2 + 29;
            break;
        case 1:
            exp2 = exp2 + 45;
            break;
        case 2:
            exp2 = exp2 + 75;
            break;
        case 3:
            exp2 = exp2 + 149;
            break;
        }
        if (exp2 > 600) exp2 = 600;
        else if (exp2 < 0) exp2 = 0;
        else exp2 = exp2;
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = ceil(exp1 + D / 200.0);
        else if (D % 2 != 0) exp1 = ceil(exp1 - D / 100.0);
        if (exp1 > 600) exp1 = 600;
        else if (exp1 < 0) exp1 = 0;
        else exp1 = exp1;
    }
    //TH2
    else if (e1 >= 4 && e1 <= 99) {
        int TH;
        if (e1 >= 4 && e1 <= 19) TH = 1;
        else if (e1 >= 20 && e1 <= 49) TH = 2;
        else if (e1 >= 50 && e1 <= 65) TH = 3;
        else if (e1 >= 66 && e1 <= 79) TH = 4;
        else if (e1 >= 80 && e1 <= 99) TH = 5;
        switch (TH) {
        case 1:
            exp2 = ceil(exp2 + (e1 / 4.0 + 19));
            if (exp2 > 600) exp2 = 600;
            else if (exp2 < 0) exp2 = 0;
            else exp2 = exp2;
            break;
        case 2:
            exp2 = ceil(exp2 + (e1 / 9.0 + 21));
            if (exp2 > 600) exp2 = 600;
            else if (exp2 < 0) exp2 = 0;
            else exp2 = exp2;
            break;
        case 3:
            exp2 = ceil(exp2 + (e1 / 16.0 + 17));
            if (exp2 > 600) exp2 = 600;
            else if (exp2 < 0) exp2 = 0;
            else exp2 = exp2;
            break;
        case 4:
            exp2 = ceil(exp2 + (e1 / 4.0 + 19));
            if (exp2 > 600) exp2 = 600;
            else if (exp2 < 0) exp2 = 0;
            else exp2 = exp2;
            if (exp2 > 200) exp2 = ceil(exp2 + (e1 / 9.0 + 21));
            if (exp2 > 600) exp2 = 600;
            else if (exp2 < 0) exp2 = 0;
            else exp2 = exp2;
            break;
        case 5:
            int cong = 0;
            exp2 = ceil(exp2 + (e1 / 4.0 + 19));
            exp2 = ceil(exp2 + (e1 / 9.0 + 21));
            if (exp2 > 600) exp2 = 600;
            else if (exp2 < 0) exp2 = 0;
            else exp2 = exp2;
            if (exp2 > 400) {
                exp2 = ceil(exp2 + (e1 / 16.0 + 17));
                cong = 1;
            }
            if (cong == 1) exp2 = 1.15 * exp2;
            if (exp2 > 600) exp2 = 600;
            else if (exp2 < 0) exp2 = 0;
            else exp2 = exp2;
            break;
        }
        exp1 = exp1 - e1;
        if (exp1 > 600) exp1 = 600;
        else if (exp1 < 0) exp1 = 0;
        else exp1 = exp1;
    }
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99) return -99;
    //CD1
    int can = static_cast<int>(sqrt(EXP1));
    int canCong = can + 1;
    int CPcan = can * can;
    int CPcanCong = canCong * canCong;
    float S;
    if ((EXP1 - CPcan) > (CPcanCong - EXP1)) S = CPcanCong;
    else if ((EXP1 - CPcan) < (CPcanCong - EXP1)) S = CPcan;
    double P1;
    if (EXP1 >= S) P1 = 1;
    else P1 = static_cast<double>((EXP1 / S + 80) / 123.0);
    //CD2
    int truongHop;
    if (E2 % 2 != 0) truongHop = 0;
    else if (E2 % 2 == 0) truongHop = 1;
    if (truongHop == 1) {
        if (M1 > 0) {
            if (HP1 < 200) {
                HP1 = ceil(HP1 * 1.3);
                if (HP1 > 666) HP1 = 666;
                M1 = M1 - 150;
                if (M1 < 0) M1 = 0;
            }
            else {
                HP1 = ceil(HP1 * 1.1);
                if (HP1 > 666) HP1 = 666;
                M1 = M1 - 70;
                if (M1 < 0) M1 = 0;
            }
        }
        if (M1 > 0) {
            if (EXP1 < 400) M1 = M1 - 200;
            else M1 = M1 - 120;
            if (M1 < 0) M1 = 0;
            EXP1 = ceil(EXP1 * 1.13);
            if (EXP1 > 600) EXP1 = 600;
        }
        if (M1 > 0) {
            if (EXP1 < 300) M1 = M1 - 100;
            else M1 = M1 - 120;
            if (M1 < 0) M1 = 0;
            EXP1 = ceil(EXP1 * 0.9);
        }
        HP1 = ceil(HP1 * 0.83);
        EXP1 = ceil(EXP1 * 1.17);
        if (EXP1 > 600) EXP1 = 600;
    }
    else if (truongHop == 0) {
        double  motNua = ceil(M1*0.5);
        int tongChi= 0;
        int kiemTra = 0;
        do {
            if (M1 > 0 && kiemTra == 0 && motNua != 0) {
                if (HP1 < 200) {
                    HP1 = ceil(HP1 * 1.3);
                    if (HP1 > 666) HP1 = 666;
                    M1 = M1 - 150;
                    if (M1 < 0) M1 = 0;
                    tongChi = tongChi + 150;
                }
                else {
                    HP1 = ceil(HP1 * 1.1);
                    if (HP1 > 666) HP1 = 666;
                    M1 = M1 - 70;
                    if (M1 < 0) M1 = 0;
                    tongChi = tongChi + 70;
                }
                if (tongChi > motNua) kiemTra = 1;
            }
            if (M1 > 0 && kiemTra == 0 && motNua != 0) {
                if (EXP1 < 400) {
                    M1 = M1 - 200;
                    tongChi = tongChi + 200;
                }
                else {
                    M1 = M1 - 120;
                    tongChi = tongChi + 120;
                }
                if (M1 < 0) M1 = 0;
                EXP1 = ceil(EXP1 * 1.13);
                if (EXP1 > 600) EXP1 = 600;
                if (tongChi > motNua) kiemTra = 1;
            }
            if (M1 > 0 && kiemTra == 0 && motNua != 0) {
                if (EXP1 < 300) {
                    M1 = M1 - 100;
                    tongChi = tongChi + 100;
                }
                else {
                    M1 = M1 - 120;
                    tongChi = tongChi + 120;
                }
                if (M1 < 0) M1 = 0;
                EXP1 = ceil(EXP1 * 0.9);
                if (tongChi > motNua) kiemTra = 1;
            }
        } while (M1 > 0 && kiemTra == 0 && motNua != 0);
        HP1 = ceil(HP1 * 0.83);
        EXP1 = ceil(EXP1 * 1.17);
        if (EXP1 > 600) EXP1 = 600;
    }
    int can2 = sqrt(EXP1);
    int canCong2 = can2 + 1;
    int CPcan2 = can2 * can2;
    int CPcanCong2 = canCong2 * canCong2;
    double S2;
    if ((EXP1 - CPcan2) > (CPcanCong2 - EXP1)) S2 = CPcanCong2;
    else if ((EXP1 - CPcan2) < (CPcanCong2 - EXP1)) S2 = CPcan2;
    double P2;
    if (EXP1 >= S2) P2 = 1;
    else P2 = (EXP1 / S2 + 80) / 123.0;
    //CD3
    double mang[10] = { 0.32,0.47,0.28,0.79,1,0.50,0.22,0.83,0.64,0.11 };
    double P3;
    if (E2 >= 0 && E2 <= 9) P3 = mang[E2];
    else {
        int hangChuc = E2 / 10;
        int hangDonvi = E2 % 10;
        int Tong = hangChuc + hangDonvi;
        int so = Tong % 10;
        P3 = mang[so];
    }
    double trungBinhcong;
    if (P1 == 1 && P2 == 1 && P3 == 1) EXP1 = ceil(EXP1 * 0.75);
    else {
        trungBinhcong = (P1 + P2 + P3) / 3.0;
        if (trungBinhcong < 0.5) {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
            if (EXP1 > 600) EXP1 = 600;
        }
        else {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
            if (EXP1 > 600) EXP1 = 600;
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) return -99;
    int taxi[10][10] = { 0 };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int hang = 0;
    int cot = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (taxi[i][j] > (E3 * 2)) hang++;
            if (taxi[i][j] < (-E3)) cot++;
        }
    }
    int hangdung = 0;
    int cotdung = 0;
    int diemTaxi = 0;
    for (int i = 0; i < 1; i++) {
        if (hang > 9) hang = (hang % 10) + (hang / 10);
        if (cot > 9) cot = (cot % 10) + (cot / 10);
        if (hang > 9 || cot > 9) i--;
    }
    diemTaxi = (taxi[hang][cot]);
    
    int giaTriLonNhat = (taxi[hang][cot]);
    if (giaTriLonNhat < taxi[hang+1][cot + 1] && cot !=9 && hang !=9) giaTriLonNhat = (taxi[hang + 1][cot + 1]);
    if (giaTriLonNhat < taxi[hang+1][cot - 1] && cot !=0 && hang !=9) giaTriLonNhat = (taxi[hang + 1][cot - 1]);
    if (giaTriLonNhat < taxi[hang-1][cot - 1] && cot !=0 && hang !=0) giaTriLonNhat = (taxi[hang - 1][cot - 1]);
    if (giaTriLonNhat < taxi[hang-1][cot + 1] && cot !=9 && hang !=0) giaTriLonNhat = (taxi[hang - 1][cot + 1]);
   
    if (abs(diemTaxi) > giaTriLonNhat) {
        EXP1 = ceil(EXP1 * 0.88);
        EXP2 = ceil(EXP2 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        HP2 = ceil(HP2 * 0.9);
        return diemTaxi;
    }
    else {
        EXP1 = ceil(EXP1 * 1.12);
        EXP2 = ceil(EXP2 * 1.12);
        HP1 = ceil(HP1 * 1.1);
        HP2 = ceil(HP2 * 1.1);
        if (EXP1 > 600) EXP1 = 600;
        if (EXP1 > 600) EXP1 = 600;
        if (HP1 > 666) HP1 = 666;
        if (HP2 > 666) HP2 = 666;
        return giaTriLonNhat;
    }
}


// Task 4
int checkPassword(const char* s, const char* email) {
    //Lay chuoi se
    const char* viTri = strchr(email, '@');
    size_t doDaise = static_cast<size_t>(viTri - email);
    char* se = new char[doDaise + 1];
    strncpy(se, email, doDaise);
    se[doDaise] = '\0';
    //Kiem tra mat khau
    int doDai = strlen(s);
    const char* xuatHien = strstr(s, se);
    const int toiThieu = 2;
    int BatDau = -1;
    int doDaiChuoiLienTiep = 0;
    if (doDai < 8) return -1;
    if (doDai > 20) return -2;
    if (xuatHien != nullptr) {
        ptrdiff_t sei = xuatHien - s;
        return - (300 + sei);
    }
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == s[i + 1]) {
            if (BatDau == -1) {
                BatDau = i;
            }
            doDaiChuoiLienTiep++;
        }
        else {
            if (doDaiChuoiLienTiep > toiThieu - 1) {
                return -(400 + BatDau);
            }
            BatDau = -1;
            doDaiChuoiLienTiep = 0;
        }
    }
    bool kiTuDacBiet = true;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            kiTuDacBiet = false;
        }
    }
    if (kiTuDacBiet) return -5;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (!((s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= '0' && s[i] <= '9') ||
            (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))) {
            return i;
        }
    }
    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int soKhac = 0;
    const char* mangKhac[30];
    for (int i = 0; i < num_pwds && soKhac < 30; ++i) {
        const char* current = arr_pwds[i];
        bool docNhat = true;
        for (int j = 0; j < soKhac; ++j) {
            if (current != nullptr && mangKhac[j] != nullptr && strcmp(current, mangKhac[j]) == 0) {
                docNhat = false;
                break;
            }
        }
        if (docNhat) {
            mangKhac[soKhac++] = current;
        }
    }
    int soLanXuatHien[30] = {};
    int max = 0;
    for (int j = 0; j < soKhac; ++j) {
        for (int z = 0; z < num_pwds; z++) {
            if (mangKhac[j] != nullptr && arr_pwds[z] != nullptr && strcmp(mangKhac[j], arr_pwds[z]) == 0) {
                soLanXuatHien[j]++;
            }
        }
    }
    for (int j = 0; j < soKhac; ++j) {
        if (soLanXuatHien[j] > max) {
            max = soLanXuatHien[j];
        }
    }
    const char* mangXHN[30];
    int matKhauCoCungSLXH = 0;
    for (int j = 0; j < soKhac; ++j) {
        if (soLanXuatHien[j] == max) {
            mangXHN[matKhauCoCungSLXH++] = mangKhac[j];
        }
    }
    int daiNhat = 0;
    const char* MK = nullptr;
    for (int i = 0; i < matKhauCoCungSLXH; i++) {
        const char* password = mangXHN[i];
        if (password != nullptr) {
            int length = strlen(password);
            if (length > daiNhat) {
                daiNhat = length;
                MK = password;
            }
        }
    }
    int Vitri = 0;
    for (int z = 0; z < num_pwds; z++) {
        if (MK != nullptr && arr_pwds[z] != nullptr && strcmp(MK, arr_pwds[z]) == 0) {
            Vitri = z;
            break;
        }
    }
    return Vitri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////