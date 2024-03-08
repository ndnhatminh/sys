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
int hp(int a) {
    if (a < 0) { return a = 0; }
    else if (a > 666) { return a = 666; }
    else { return a; }
}

int expa(int a) {
    if (a < 0) { return a = 0; }
    else if (a > 600) { return a = 600; }
    else { return a; }
}

int m(int a) {
    if (a < 0) { return a = 0; }
    else if (a > 3000) { return a = 3000; }
    else { return a; }
}

int firstMeet(int& exp1, int& exp2, int e1) {
    if (e1 > 99 || e1 < 0) return -99;



    if (e1 == 0) {
        exp2 += 29; exp2 = expa(exp2);
    }
    else if (e1 == 1) {
        exp2 += 45; exp2 = expa(exp2);
    }
    else if (e1 == 2) {
        exp2 += 75; exp2 = expa(exp2);
    }
    else if (e1 == 3) {
        exp2 += 149; exp2 = expa(exp2);
    }
    else if (4 <= e1 && e1 <= 19) {
        exp2 += ceil(float(e1 / 4.0)) + 19; exp2 = expa(exp2);
    }
    else if (20 <= e1 && e1 <= 49) {
        exp2 += ceil(float(e1 / 9.0)) + 21; exp2 = expa(exp2);
    }
    else if (50 <= e1 && e1 <= 65) {
        exp2 += ceil(float(e1 / 16.0)) + 17; exp2 = expa(exp2);
    }
    else if (66 <= e1 && e1 <= 79) {
        exp2 += ceil(float(e1 / 4.0)) + 19; exp2 = expa(exp2);
        if (exp2 > 200) {
            exp2 += ceil(float(e1 / 9.0)) + 21; exp2 = expa(exp2);
        }
    }
    else if (80 <= e1 && e1 <= 99) {
        exp2 = exp2 + ceil(float(e1 / 4.0)) + 19 + ceil(float(e1 / 9.0)) + 21; exp2 = expa(exp2);
        if (exp2 > 400) {
            exp2 += ceil(float(e1 / 16.0)) + 17; exp2 = expa(exp2);
            exp2 = ceil(float(exp2 * 1.15)); exp2 = expa(exp2);
        }
    }

    int D = e1 * 3 + exp1 * 7;

    if (e1 >= 0 && e1 <= 3) {
        if (D % 2 == 0) {
            exp1 = ceil(exp1 + D / 200.0); exp1 = expa(exp1);
        }
        else {
            exp1 = ceil(exp1 - D / 100.0); exp1 = expa(exp1);
        }
    }
    else {
        exp1 = exp1 - e1; exp1 = expa(exp1);
    }


    return exp1 + exp2;
}



// Task 2
bool S(int num) {
    int can = sqrt(num);
    return can * can == num;
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 > 99 || E2 < 0) return -99;

    HP1 = hp(HP1);
    EXP1 = expa(EXP1);
    M1 = m(M1);

    int so_lon = 0, so_nho = 0, tong{ 0 }, M{ 0 };
    float p1 = 0, p2 = 0, p3 = 0;
    // con đường 1
    for (int i = EXP1 - 1; i >= 1; --i) {
        if (S(i)) {
            so_nho = i;
            break;
        }
    }
    for (int i = EXP1 + 1; ; ++i) {
        if (S(i)) {
            so_lon = i;
            break;
        }
    }
    if (abs(EXP1 - so_nho) < abs(EXP1 - so_lon)) {
        so_nho;
        p1 = 100.0;
    }
    else {
        so_lon;
        p1 = ((EXP1 / so_lon + 80) / 123.0) * 100.0;
    }

    // con đường 2
    int tien1, tien2;
    tien1 = M1 * 0.5;
    tien2 = M1;
    if (M1 == 0) {
        EXP1 = ceil(float(EXP1 * 1.17)); EXP1 = expa(EXP1);
        HP1 = ceil(float(HP1 * 0.83)); HP1 = hp(HP1);
    }
    else {
        if (E2 % 2 == 0) {
            if (HP1 < 200) {
                HP1 = ceil(float(HP1 * 1.30)); HP1 = hp(HP1);
                M1 -= 150;
                M1 = m(M1);
            }
            else {
                HP1 = ceil(float(HP1 * 1.10)); HP1 = hp(HP1);
                M1 -= 70; M1 = m(M1);
            }
            if (M1 != 0) {
                if (EXP1 < 400) {
                    M1 -= 200; M1 = m(M1);
                    EXP1 = ceil(float(EXP1 * 1.13)); EXP1 = expa(EXP1);
                    if (M1 != 0) {
                        if (EXP1 < 300) {
                            M1 -= 100; M1 = m(M1);
                            EXP1 = ceil(float(EXP1 * 0.9)); EXP1 = expa(EXP1);

                        }
                        else {
                            M1 -= 120;
                            M1 = m(M1);
                            EXP1 = ceil(float(EXP1 * 0.9)); EXP1 = expa(EXP1);

                        }
                    }
                }
                else {
                    M1 -= 120; M1 = m(M1);
                    EXP1 = ceil(float(EXP1 * 1.13)); EXP1 = expa(EXP1);
                    if (M1 != 0) {
                        if (EXP1 < 300) {
                            M1 -= 100; M1 = m(M1);
                            EXP1 = ceil(float(EXP1 * 0.9)); EXP1 = expa(EXP1);

                        }
                        else {
                            M1 -= 120;
                            M1 = m(M1);
                            EXP1 = ceil(float(EXP1 * 0.9)); EXP1 = expa(EXP1);

                        }
                    }
                }

            }
            EXP1 = ceil(float(EXP1 * 1.17)); EXP1 = expa(EXP1);
            HP1 = ceil(float(HP1 * 0.83)); HP1 = hp(HP1);


            for (int i = EXP1 - 1; i >= 1; --i) {
                if (S(i)) {
                    so_nho = i;
                    break;
                }
            }
            for (int i = EXP1 + 1; ; ++i) {
                if (S(i)) {
                    so_lon = i;
                    break;
                }
            }
            if (abs(EXP1 - so_nho) < abs(EXP1 - so_lon)) {
                p2 = 100.0;
            }
            else {

                p2 = ((EXP1 / so_lon + 80.0) / 123.0) * 100.0;
            }
        }
        else {
            for (int i = 0; i < 100; i++) {
                if (HP1 < 200) {
                    HP1 = ceil(float(HP1 * 1.30)); HP1 = hp(HP1);
                    M1 -= 150; M1 = m(M1);
                }
                else {
                    HP1 = ceil(float(HP1 * 1.10)); HP1 = hp(HP1);//571, 629, 666
                    M1 -= 70; M1 = m(M1);
                }
                tong = tien2 - M1;
                if (tong > tien1)  break;

                if (EXP1 < 400) {
                    M1 -= 200; M1 = m(M1);
                    EXP1 = ceil(float(EXP1 * 1.13)); EXP1 = expa(EXP1);//220, 224, 229, 233
                }
                else {
                    M1 -= 120; M1 = m(M1);
                    EXP1 = ceil(float(EXP1 * 1.13)); EXP1 = expa(EXP1);
                }
                tong = tien2 - M1;
                if (tong > tien1)  break;

                if (EXP1 < 300) {
                    M1 -= 100; M1 = m(M1);
                    EXP1 = ceil(float(EXP1 * 0.9)); EXP1 = expa(EXP1);//198, 202, 206, 210
                }
                else {
                    M1 -= 120; M1 = m(M1);
                    EXP1 = ceil(float(EXP1 * 0.9)); EXP1 = expa(EXP1);
                }
                tong = tien2 - M1;
                if (tong > tien1) break;

            }
            EXP1 = ceil(float(EXP1 * 1.17)); EXP1 = expa(EXP1);
            HP1 = ceil(float(HP1 * 0.83)); HP1 = hp(HP1);
            for (int i = EXP1 - 1; i >= 1; --i) {
                if (S(i)) {
                    so_nho = i;
                    break;
                }
            }
            for (int i = EXP1 + 1; ; ++i) {
                if (S(i)) {
                    so_lon = i;
                    break;
                }
            }
            if (abs(EXP1 - so_nho) < abs(EXP1 - so_lon)) {
                p2 = 100.0;

            }
            else {
                p2 = ((EXP1 / so_lon + 80) / 123.0) * 100.0;

            }

        }
    }
    HP1 = hp(HP1);
    EXP1 = expa(EXP1);
    M1 = m(M1);
    // con đường 3
    int i = 0;
    float p_trung_binh;
    int mang[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2 >= 0 && E2 <= 9) {
        i = E2;
        p3 = mang[i];
    }
    else if (E2 >= 10 && E2 <= 99) {
        int sum = (E2 / 10) + (E2 % 10);
        i = sum % 10;
        p3 = mang[i];
    }
    if (i >= 0 && i < 10) {
        p3 = mang[i];
    }
    p_trung_binh = (p1 + p2 + p3) / 3.0;
    if ((p1 == 100.0) && (p2 == 100.0) && (p3 == 100.0)) {
        EXP1 = ceil(float(EXP1 * 0.75)); EXP1 = expa(EXP1);
    }
    else if (p_trung_binh >= 50.0000000) {
        EXP1 = ceil(float(EXP1 * 1.20)); EXP1 = expa(EXP1);
        HP1 = ceil(float(HP1 * 0.9)); HP1 = hp(HP1);
    }
    else {
        EXP1 = ceil(float(EXP1 * 1.15)); EXP1 = expa(EXP1);
        HP1 = ceil(float(HP1 * 0.85)); HP1 = hp(HP1);
    }

    HP1 = hp(HP1);
    EXP1 = expa(EXP1);
    M1 = m(M1);

    return HP1 + EXP1 + M1;
}


// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    int so_dem_lon = 0, so_dem_nho = 0, i = 0, j = 0;
    int matran[10][10] = { 0 }, matran2[2];
    HP1 = hp(HP1);
    EXP1 = expa(EXP1);
    HP2 = hp(HP2);
    EXP2 = expa(EXP2);
    if (E3 > 99 || E3 < 0)  return -99;  

    // tính giá trị của ma trận và đếm số lượng các giá trị lớn hơn E3 * 2 và nhỏ hơn -E3
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matran[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (matran[i][j] > (E3 * 2)) {
                so_dem_lon++;
            }
            if (matran[i][j] < (-E3)) {
                so_dem_nho++;
            }
        }
    }

    // xác định giá trị của i và j dựa trên số lượng phần tử
    if (so_dem_lon >= 0 && so_dem_lon < 10) {
        i = so_dem_lon;
    }
    else if (so_dem_lon >= 10 && so_dem_lon < 100) {
        i = (so_dem_lon / 10) + (so_dem_lon % 10);
        while (i >= 10) {
            i = (i / 10) + (i % 10);
        }
    }
    if (so_dem_nho >= 0 && so_dem_nho < 10) {
        j = so_dem_nho;
    }
    else if (so_dem_nho >= 10 && so_dem_nho < 100) {
        j = (so_dem_nho / 10) + (so_dem_nho % 10);
        while (j >= 10) {
            j = (j / 10) + (j % 10);
        }
    }

    // gán vị trí của taxi vào ma trận 2 chiều
    matran2[0] = i;
    matran2[1] = j;

    int toa_do_taxi = matran[matran2[0]][matran2[1]];

    // tính đường chéo trái và đường chéo phải từ vị trí taxi trở lên và từ vị trí taxi trở xuống
    int max = toa_do_taxi;

    // tính đường chéo trái từ vị trí taxi trở lên và từ vị trí taxi trở xuống
    int k = matran2[0];
    int l = matran2[1];

    // tính đường chéo trái từ vị trí taxi trở lên
    while (k >= 0 && l >= 0) {
        if (matran[k][l] > max) {
            max = matran[k][l];
        }
        k--;
        l--;
    }

    // tính đường chéo trái từ vị trí taxi trở xuống
    k = matran2[0] + 1;
    l = matran2[1] + 1;
    while (k < 10 && l < 10) {
        if (matran[k][l] > max) {
            max = matran[k][l];
        }
        k++;
        l++;
    }

    // tính đường chéo phải từ vị trí taxi trở lên và từ vị trí taxi trở xuống
    k = matran2[0];
    l = matran2[1];

    // tính đường chéo phải từ vị trí taxi trở lên
    while (k >= 0 && l < 10) {
        if (matran[k][l] > max) {
            max = matran[k][l];
        }
        k--;
        l++;
    }

    // tính đường chéo phải từ vị trí taxi trở xuống 
    k = matran2[0] + 1;
    l = matran2[1] - 1;
    while (k < 10 && l >= 0) {
        if (matran[k][l] > max) {
            max = matran[k][l];
        }
        k++;
        l--;
    }

    if (abs(toa_do_taxi) > max) {
        EXP1 = ceil(float(EXP1 * 0.88));
        HP1 = ceil(float(HP1 * 0.9));
        EXP2 = ceil(float(EXP2 * 0.88));
        HP2 = ceil(float(HP2 * 0.9));

        HP1 = hp(HP1); 
        EXP1 = expa(EXP1); 
        HP2 = hp(HP2); 
        EXP2 = expa(EXP2); 


        return toa_do_taxi;
    }
    else {
        EXP1 = ceil(float(EXP1 * 1.12));
        HP1 = ceil(float(HP1 * 1.1));
        EXP2 = ceil(float(EXP2 * 1.12));
        HP2 = ceil(float(HP2 * 1.1));

        HP1 = hp(HP1); 
        EXP1 = expa(EXP1); 
        HP2 = hp(HP2); 
        EXP2 = expa(EXP2); 


        return max;
    }

    return -1;
}
// Task 4
int checkPassword(const char* s, const char* email) {// ký tự '\0': ở cuối chuỗi ký tự
    // độ dài mk
    int mk = strlen(s);
    if (mk < 8) return -1; 
    if (mk > 20) return -2; 

    // tìm se = chuỗi trước @ trong email
    string chuoi = strchr(email, '@');
    string chuoi_e = email;
    string chuoi_s = s;

    int chuoi2 = chuoi_e.find('@');
    string se = chuoi_e.substr(0, chuoi2); 
    int sei = chuoi_s.find(se);// trả về số

    // chứa se
    if (sei != string::npos) {
        return -(300 + sei);
    }

    // liên tiếp
    for (int i = 0; s[i] != '\0'; i++) {
        if ((s[i] == s[i + 1]) && (s[i] == s[i + 2])) {
            return -(400 + i);
        }
    }

    // ktra ktdb
    bool ktdb = false;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            ktdb = true;
            break;
        }
    }
    if (!ktdb) return -5;

    // mk hợp lệ
    for (int i = 0; s[i] != '\0'; i++) {
        if (!((s[i] >= '0' && s[i] <= '9') ||
            (s[i] >= 'A' && s[i] <= 'Z') || 
            (s[i] >= 'a' && s[i] <= 'z') || 
            (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))) { 
            return i;
        }
    }
    return -10;
}



// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int dai_nhat = 0;
    int nhieu_nhat = 0;
    int max_index = -1;

    // duyệt qua mảng để tìm mật khẩu đúng
    for (int i = 0; i < num_pwds; i++) { 
        const char* hientai_pwd = arr_pwds[i];  
        int dodai_pwd = strlen(hientai_pwd);  

        // đếm số lần xuất hiện của mật khẩu hiện tại
        int dem_hientai_pwd = 1; 
        for (int j = i + 1; j < num_pwds; j++) { 
            if (strcmp(hientai_pwd, arr_pwds[j]) == 0) {//strcmp: so sánh chuỗi 
                dem_hientai_pwd++; 
            }
        }

        // kiểm tra nếu mật khẩu hiện tại là mật khẩu đúng
        if (dem_hientai_pwd > nhieu_nhat || (dem_hientai_pwd == nhieu_nhat && dodai_pwd > dai_nhat)) { 
            nhieu_nhat = dem_hientai_pwd; 
            dai_nhat = dodai_pwd; 
            max_index = i;  
        }
    }

    return max_index;// số mk đúng
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////