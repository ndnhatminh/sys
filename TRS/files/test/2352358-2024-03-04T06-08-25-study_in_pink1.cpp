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

// Check whether exp is enough
int EXPEnough(int& exp) {
    if (exp > 600)
        exp = 600;
    else if (exp < 0)
        exp = 0;
    return exp;
}

//Check whether cash is enough
int CashEnough(int& M) {
    if (M > 3000)
        M = 3000;
    else if (M < 0)
        M = 0;
    return M;
}

//Check whether hp is enough
int HPEnough(int& HP) {
    if (HP > 666)
        HP = 666;
    else if (HP < 0)
        HP = 0;
    return HP;
}

//
int NearestSquareInteger(int& N) {
    int s = sqrt(N);
    if (s * s == N) {
        return s;
    }
    else {
        int above = pow(s + 1, 2), below = pow(s, 2);
        int distance_above = abs(above - N), distance_below = abs(N - below);
        if (distance_above < distance_below) {
            return above;
        }
        else {
            return below;
        }
    }
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    if ((e1 < 0) || (e1 > 99)) {
        return -99;
    }
    //truong hop 1
    EXPEnough(exp1);
    EXPEnough(exp2);
    if ((e1 >= 0) && (e1 <= 3))
    {
        if (e1 == 0) {
            exp2 += 29;
            EXPEnough(exp2);
        }
        if (e1 == 1) {
            exp2 += 45;
            EXPEnough(exp2);
        }
        if (e1 == 2) {
            exp2 += 75;
            EXPEnough(exp2);
        }
        if (e1 == 3) {
            exp2 += 149;
            EXPEnough(exp2);
        }
        int d = e1 * 3 + exp1 * 7;
        if (d % 2 == 0) {
            exp1 += ceil((d * 1.0) / 200 - 1e-9);
            EXPEnough(exp1);
        }
        else {
            exp1 -= floor((d * 1.0) / 100 + 1e-9);
            EXPEnough(exp1);
        }
    }
    //truong hop 2
    else {
        if ((e1 >= 4) && (e1 <= 99)) {
            if ((e1 > 3) && (e1 < 20)) {
                exp2 += ceil((e1 * 1.0) / 4 + 19 - 1e-9);
                EXPEnough(exp2);
            }
            if ((e1 > 19) && (e1 < 50)) {
                exp2 += ceil((e1 * 1.0) / 9 + 21 - 1e-9);
                EXPEnough(exp2);
            }
            if ((e1 > 49) && (e1 < 66)) {
                exp2 += ceil((e1 * 1.0) / 16 + 17 - 1e-9);
                EXPEnough(exp2);
            }
            if ((e1 > 65) && (e1 < 80)) {
                exp2 += ceil((e1 * 1.0) / 4 + 19 - 1e-9);
                EXPEnough(exp2);
                if (exp2 > 200) {
                    exp2 += ceil((e1 * 1.0) / 9 + 21 - 1e-9);
                    EXPEnough(exp2);
                }
            }
            if ((e1 > 79) && (e1 < 100)) {
                exp2 += ceil((e1 * 1.0) / 4 + 19 - 1e-9);
                EXPEnough(exp2);
                exp2 += ceil((e1 * 1.0) / 9 + 21 - 1e-9);
                EXPEnough(exp2);
                if (exp2 > 400) {
                    exp2 += ceil((e1 * 1.0) / 16 + 17 - 1e-9);
                    EXPEnough(exp2);
                    exp2 += ceil(0.15 * exp2);
                    EXPEnough(exp2);
                }
            }
            exp1 -= e1;
            EXPEnough(exp1);
        }
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if ((E2 < 0) || (E2 > 99)) {
        return -99;
    }
    else {
        EXPEnough(EXP1);
        HPEnough(HP1);
        CashEnough(M1);
    }
    //con duong 1
    double P1, S = (NearestSquareInteger(EXP1)) * 1.0;
    if (S <= EXP1) {
        P1 = 100 * 1.0;
    }
    else {
        P1 = (1.0 * ((1.0 * EXP1) / S + 80)) / 123 * 100;
    }
    //con duong 2
    double tien_ban_dau = 0.5 * (1.0 * M1);
    if ((E2 % 2 != 0) && (M1 != 0)) {
        while (M1 >= tien_ban_dau) {
            if (HP1 < 200) {
                HP1 += ceil(0.3 * HP1 - 1e-9);
                HPEnough(HP1);
                M1 -= 150;
                CashEnough(M1);
            }
            else {
                HP1 += ceil(0.1 * HP1 - 1e-9);
                HPEnough(HP1);
                M1 -= 70;
                CashEnough(M1);
            }
            if ((M1 < (tien_ban_dau)) || (M1 <= 0)) {
                break;
            }
            if (EXP1 < 400) {
                M1 -= 200;
                CashEnough(M1);
                EXP1 += ceil(0.13 * EXP1 - 1e-9);
                EXPEnough(EXP1);
            }
            else {
                M1 -= 120;
                CashEnough(M1);
                EXP1 += ceil(0.13 * EXP1 - 1e-9);
                EXPEnough(EXP1);
            }
            if ((M1 < tien_ban_dau) || (M1 <= 0)) {
                break;
            }
            if (EXP1 < 300) {
                M1 -= 100;
                CashEnough(M1);
                EXP1 -= floor(0.1 * EXP1 + 1e-9);
                EXPEnough(EXP1);
            }
            else {
                M1 -= 120;
                CashEnough(M1);
                EXP1 -= floor(0.1 * EXP1 + 1e-9);
                EXPEnough(EXP1);
            }
            if ((M1 < tien_ban_dau) || (M1 <= 0)) {
                break;
            }
        }
        HP1 -= floor(0.17 * HP1 + 1e-9);
        HPEnough(HP1);
        EXP1 += ceil(0.17 * EXP1 - 1e-9);
        EXPEnough(EXP1);
    }
    else {
            if (M1>0) {
                if (HP1 < 200) {
                    HP1 += ceil(0.3 * HP1 - 1e-9);
                    HPEnough(HP1);
                    M1 -= 150;
                    CashEnough(M1);
                }
                else {
                    HP1 += ceil(0.1 * HP1 - 1e-9);
                    HPEnough(HP1);
                    M1 -= 70;
                    CashEnough(M1);
                }
            }
            if (M1 > 0) {
                if (EXP1 < 400) {
                    M1 -= 200;
                    CashEnough(M1);
                    EXP1 += ceil(0.13 * EXP1 - 1e-9);
                    EXPEnough(EXP1);
                }
                else {
                    M1 -= 120;
                    CashEnough(M1);
                    EXP1 += ceil(0.13 * EXP1 - 1e-9);
                    EXPEnough(EXP1);
                }
            }
            if (M1 > 0) {
                if (EXP1 < 300) {
                    M1 -= 100;
                    CashEnough(M1);
                    EXP1 -= floor(0.1 * EXP1 + 1e-9);
                    EXPEnough(EXP1);
                }
                else {
                    M1 -= 120;
                    CashEnough(M1);
                    EXP1 -= floor(0.1 * EXP1 + 1e-9);
                    EXPEnough(EXP1);
                }
            }
        HP1 -= floor(0.17 * HP1 + 1e-9);
        HPEnough(HP1);
        EXP1 += ceil(0.17 * EXP1 - 1e-9);
        EXPEnough(EXP1);
    }
    double P2, S2 = (NearestSquareInteger(EXP1)) * 1.0;
    if (S2 <= EXP1) {
        P2 = 100 * 1.0;
    }
    else {
        P2 = (((EXP1 * 1.0) / S2 + 80) * 1.0) / 123 * 100;
    }

    //con duong 3
    int P_array[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int k;
    if ((E2 >= 0) && (E2 <= 9)) {
        k = E2;
    }
    else {
        if ((E2 >= 10) && (E2 <= 99)) {
            int a1 = E2 / 10;
            int b1 = E2 % 10;
            k = (a1 + b1) % 10;
        }
    }
    double P3 = (P_array[k]) * 1.0;

    //tinh tong
    double P_average = (P1 + P2 + P3) / 3;
    if ((P1 == 100) && (P2 == 100) && (P3 == 100)) {
        EXP1 -= floor(0.25 * EXP1 + 1e-9);
        EXPEnough(EXP1);
    }
    else {
        if (P_average < 50) {
            HP1 -= floor(0.15 * HP1 + 1e-9);
            HPEnough(HP1);
            EXP1 += ceil(0.15 * EXP1 - 1e-9);
            EXPEnough(EXP1);
        }
        else {
            HP1 -= floor(0.1 * HP1 + 1e-9);
            HPEnough(HP1);
            EXP1 += ceil(0.2 * EXP1 - 1e-9);
            EXPEnough(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if ((E3 < 0) || (E3 > 99)) {
        return -99;
    }
    else {
        HPEnough(HP1);
        HPEnough(HP2);
        EXPEnough(EXP1);
        EXPEnough(EXP2);
        int initial_array[10][10];
        int gap_nhau_x = 0, gap_nhau_y = 0;
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                initial_array[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                if (initial_array[i][j] > (2 * E3)) {
                    gap_nhau_x++;
                }
                if (initial_array[i][j] < -E3) {
                    gap_nhau_y++;
                }
            }
        }
        while ((gap_nhau_x >= 10) && (gap_nhau_x <= 99)) {
            int a2 = gap_nhau_x / 10;
            int b2 = gap_nhau_x - 10 * a2;
            gap_nhau_x = a2 + b2;
        }
        while ((gap_nhau_y >= 10) && (gap_nhau_y <= 99)) {
            int a3 = gap_nhau_y / 10;
            int b3 = gap_nhau_y - 10 * a3;
            gap_nhau_y = a3 + b3;
        }
        int d1 = gap_nhau_x + gap_nhau_y;
        int d2 = gap_nhau_x - gap_nhau_y;
        int diem_so_hai_nguoi_kabs = (initial_array[0][d1]);
        int diem_so_hai_nguoi = abs(initial_array[0][d1]);
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                if ((i + j == d1) || (i - j == d2)) {
                    if (((initial_array[i][j]) > diem_so_hai_nguoi_kabs)) {
                        diem_so_hai_nguoi_kabs = (initial_array[i][j]);
                        diem_so_hai_nguoi = abs(initial_array[i][j]);
                    }
                }
            }
        }
        int diem_so_taxi = abs(initial_array[gap_nhau_x][gap_nhau_y]);
        int diem_so_taxi_kabs = initial_array[gap_nhau_x][gap_nhau_y];
        if (diem_so_taxi > diem_so_hai_nguoi) {
            EXP1 -= floor(0.12 * EXP1+1e-9);
            HP1 -= floor(0.1 * HP1+1e-9);
            EXP2 -= floor(0.12 * EXP2+1e-9);
            HP2 -= floor(0.1 * HP2+1e-9);
            HPEnough(HP1);
            HPEnough(HP2);
            EXPEnough(EXP1);
            EXPEnough(EXP2);
        }
        else {
            EXP1 += ceil(0.12 * EXP1-1e-9);
            HP1 += ceil(0.1 * HP1-1e-9);
            EXP2 += ceil(0.12 * EXP2-1e-9);
            HP2 += ceil(0.1 * HP2-1e-9);
            HPEnough(HP1);
            HPEnough(HP2);
            EXPEnough(EXP1);
            EXPEnough(EXP2);
        }
        if (diem_so_taxi > diem_so_hai_nguoi) {
            return diem_so_taxi_kabs;
        }
        else {
            return diem_so_hai_nguoi_kabs;
        }
    }
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    long int a;
    string str1 = email;
    string se;
    string pass = s;
    pass = pass+"\0";
    int c=-3;
    //tim se
    size_t pos_email = str1.find('@');
    if (pos_email != std::string::npos) {
        se = str1.substr(0, pos_email);
    }
    //chua ki tu ngoai ki tu duoc dung
    bool check = false;
    for (int i =0; i < (int)pass.length(); i++){
    if ((pass[i] >= 0 && pass[i] <= 32) || pass[i] == 34 || (pass[i] >= 38 && pass[i] <= 47) || (pass[i] >= 58 && pass[i] <= 63) || (pass[i] >= 91 && pass[i] <= 96) || (pass[i] >= 123)) {check = true; a = i; break;}
    }
    

    //nhan dien coi s co chua ki tu dac biet khong
    string ki_tu_dac_biet = "@#%$!";
    int not_found_ktdb = 0;
    for (int i = 0; i < (int)ki_tu_dac_biet.length(); i++) {
        if (pass.find(ki_tu_dac_biet[i]) == std::string::npos) {
            not_found_ktdb++;
        }
    }
    if (not_found_ktdb == 5) {
        a = -5;
    }
    //nhan dien coi s co chua nhieu hon 2 ki tu lien tiep va giong nhau khong
    int lap = 1, sci = 0;
    for (int i = 0; i < (int)pass.length(); i++) {
        if (lap == 3) { sci = i - 2; break; }
        if (pass[i] == pass[i + 1]) { lap++; }
        else { lap = 1; }
    }
    if (lap == 3) {
        a = -(400 + sci);
    }
    //nhan dien coi s co chua se khong
    if (pass.find(se) != std::string::npos) {
        size_t sei = pass.find(se);
        c = -(300 + int(sei));
        a = c;
    }
    //nhan dien coi s co vuot qua 20 ki tu hay nho hon 8 ki tu hay khong
    if (pass.length() > 20) {
        a = -2;
    }
    if (pass.length() < 8) {
        a = -1;
    }
    if ((a != -1) && (a != -2) && (a != c) && (lap <= 2) && (not_found_ktdb < 5) && (check == false)) {
        a = -10;
    }
    return a;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    //chuyen char thanh str
    string str_pwds[num_pwds];
    int vi_tri;
    for (int i = 0; i < num_pwds; i++) {
        str_pwds[i] = arr_pwds[i];
    }
    //tao mang thu gon
    string new_arr_pwds[num_pwds];
    new_arr_pwds[0] = str_pwds[0];
    bool found;
    int a = 1;
    for (int i = 1; i < num_pwds; i++) {
        for (int j = 0; j <= a; j++) {
            if (str_pwds[i] == new_arr_pwds[j]) {
                found = true; break;
            }
            else {
                found = false;
            }
        }
        if (found == false) {
            new_arr_pwds[a] = str_pwds[i];
            a++;
        }
    }
    //dem mang va tim mang xuat hien nhieu nhat
    int mang_dem[a];
    for (int i = 0; i < a; i++) {
        mang_dem[i] = 0;
    }
    for (int j = 0; j < a; j++) {
        for (int i = 0; i < num_pwds; i++) {
            if (str_pwds[i] == new_arr_pwds[j]) {
                mang_dem[j] += 1;
            }
        }
    }
    int max = mang_dem[0], count_max = 0, pos_in_sub = 0;
    for (int i = 0; i < a; i++) {
        if (mang_dem[i] > max) {
            max = mang_dem[i];
            count_max = 0;
            pos_in_sub = i;
        }
        else if (mang_dem[i] == max) {
            count_max++;
        }
    }
    //neu count=0, xuat i, neu lon hon thi dem tiep
    if (count_max == 0) {
        for (int i = 0; i < num_pwds; i++) {
            if (str_pwds[i] == new_arr_pwds[pos_in_sub]) {
                vi_tri = i;
                break;
            }
        }
    }
    else {
        string pass_same_frequency[count_max + 1];
        int b = 0;
        bool psl;
        for (int i = 0; i < a; i++) {
            if (mang_dem[i] == max) {
                psl = true;
            }
            else {
                psl = false;
            }
            if (psl == true) {
                pass_same_frequency[b] = new_arr_pwds[i];
                b++;
            }
        }
        int longest_length;
        longest_length = (int)pass_same_frequency[0].length();
        string longest_string = pass_same_frequency[0];
        for (int i = 1; i < b; i++) {
            if ((int)pass_same_frequency[i].length() > longest_length) {
                longest_length = (int)pass_same_frequency[i].length();
                longest_string = pass_same_frequency[i];
            }
        }
        for (int i = 0; i < num_pwds; i++) {
            if (str_pwds[i] == longest_string) {
                vi_tri = i;
                break;
            }
        }
    }
    return vi_tri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////