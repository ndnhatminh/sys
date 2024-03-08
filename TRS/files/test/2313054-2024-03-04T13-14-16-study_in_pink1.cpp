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
void check_limit(int& val, int lb, int ub) {
    if (val > ub) {
        val = ub;
    }
    else if (val < lb) {
        val = lb;
    }
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int D,d;
    /*check_limit(exp1, 0, 600);
    check_limit(exp2, 0, 600);*/
    if ((e1 < 0) || (e1 > 99)) {
        return -99;
    }
    else if ((e1 >= 0) && (e1 <= 3)) { 
        check_limit(exp1, 0, 600);
        check_limit(exp2, 0, 600);
        switch (e1) {
        case 0: exp2 = exp2 + 29; break;
        case 1: exp2 = exp2 + 45; break;
        case 2: exp2 = exp2 + 75; break;
        case 3: exp2 = exp2 + 149; break;
            }
        D = (e1 * 3 + exp1 * 7);
        d = (e1 * 3 + exp1 * 7) % 2;
        switch (d) {
        case 0: exp1 = (int)ceil((float)exp1 + (float)D / 200); break;
        case 1: exp1 = (int)ceil((float)exp1 - (float)D / 100); break;
        }
    }
    else if ((e1 >= 4) && (e1 <= 99)) {
        check_limit(exp1, 0, 600);
        check_limit(exp2, 0, 600);
        if ((e1 >= 4) && (e1 <= 19)) {
            exp2 = (int)ceil((float)exp2 + (float)e1 / 4 + 19);
        }
        else if ((e1 >= 20) && (e1 <= 49)) {
            exp2 = (int)ceil((float)exp2 + (float)e1 / 9 + 21);
        }
        else if ((e1 >= 50) && (e1 <= 65)) {
            exp2 = (int)ceil((float)exp2 + (float)e1 / 16 + 17);
        }
        else if ((e1 >= 66) && (e1 <= 79)) {
            exp2 = (int)ceil((float)exp2 + (float)e1 / 4 + 19);
            if (exp2 > 200) {
                exp2 = (int)ceil((float)exp2 + (float)e1 / 9 + 21);
            }
        }
        else if ((e1 >= 80) && (e1 <= 99)) {
            exp2 = (int)ceil((float)exp2 + (float)e1 / 4 + 19);
            exp2 = (int)ceil((float)exp2 + (float)e1 / 9 + 21);
            if (exp2 > 400) {
                exp2 = (int)ceil((float)exp2 + (float)e1 / 16 + 17);
                exp2 = (int)ceil(float(exp2) + 0.15 * (float)exp2);
            }
        }
    exp1 = exp1 - e1;
    }
    check_limit(exp1, 0, 600);
    check_limit(exp2, 0, 600);
    return exp1 + exp2; 
}
//Ham tim so chinh phuong gan nhat voi so da cho
int So_chinh_phuong_gan(int exp1) {
    int num_1, num_2, s1, s2;
    //dem xuong toi 1
    for (int i = exp1; i >= 1; --i) {
        int sqr = sqrt(i);
        if (sqr == sqrt(i)) {
            num_1 = i;
            break;
        }
    }
    //dem len vo cung
    for (int i = exp1; ; i++) {
        int sqr = sqrt(i);
        if (sqr == sqrt(i)) {
            num_2 = i;
            break;
        }
    }
    s1 = exp1 - num_1;
    s2 = num_2 - exp1;
    if (s1 <= s2) {
        return num_1;
    }
    else {
        return num_2;
    }
}
//su kien 1
void su_kien_1(int& HP1, int& M1, int& money) {
    if (HP1 < 200) {
        HP1 = (int)ceil((float)HP1 * 1.3);
        M1 = M1 - 150;
        money = money + 150;
    }
    else {
        HP1 = (int)ceil((float)HP1 * 1.1);
        M1 = M1 - 70;
        money = money + 70;
    }
}
//su kien 2
void su_kien_2(int& EXP1, int& M1, int& money) {
    if (EXP1 < 400) {
        M1 = M1 - 200;
        money = money + 200;
    }
    else {
        M1 = M1 - 120;
        money = money + 120;
    }
    EXP1 = (int)ceil((float)EXP1 + 0.13 * EXP1);
}
//su kien 3
void su_kien_3(int& EXP1, int& M1, int& money) {
    if (EXP1 < 300) {
        M1 = M1 - 100;
        money = money + 100;
    }
    else {
        M1 = M1 - 120;
        money = money + 120;
    }
    EXP1 = (int)ceil((float)EXP1 - 0.1 * EXP1);
}
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
// TODO: Complete this function
int S1, S2, d, a, b, c;
int money = 0;
int M = M1 / 2;
float P_line1, P_line2, P_line3, P;
float P_3[10] = { 32,47,28,79,100,50,22,83,64,11 };
//check_limit(HP1, 0, 666);
//check_limit(EXP1, 0, 600);
//check_limit(M1, 0, 3000);
if ((E2 < 0) || (E2 > 99)) {
    return -99;
}
else {
    check_limit(HP1, 0, 666);
    check_limit(EXP1, 0, 600);
    check_limit(M1, 0, 3000);
    if (M1 == 0) {
        HP1
    }
    //con duong 1
    S1 = So_chinh_phuong_gan(EXP1);
    if (EXP1 >= S1) {
        P_line1 = 100;
    }
    else {
        P_line1 = ((float(EXP1) / S1 + 80) / 123) * 100;
    }
    //con duong 2
    if ((E2 % 2) == 0) {
        su_kien_1(HP1, M1, money);
        check_limit(M1, 0, 3000);
        if (M1 != 0) {
            su_kien_2(EXP1, M1, money);
            check_limit(M1, 0, 3000);
            if (M1 != 0) {
                su_kien_3(EXP1, M1, money);
                check_limit(M1, 0, 3000);
            }
        }
    }
    if ((E2 % 2) == 1) {
        while (money <= M) {
            su_kien_1(HP1, M1, money);
            if (money > M) { break; }
            su_kien_2(EXP1, M1, money);
            if (money > M) { break; }
            su_kien_3(EXP1, M1, money);
            if (money > M) { break; }
        }
    }
    HP1 = (int)ceil((float)HP1 * 0.83);
    EXP1 = (int)ceil((float)EXP1 + 0.17 * EXP1);
    S2 = So_chinh_phuong_gan(EXP1);
    if (EXP1 >= S2) {
        P_line2 = 100;
    }
    else {
        P_line2 = ((float(EXP1) / S2 + 80) / 123) * 100;
    }
    //con duong 3
    if ((E2 >= 0) && (E2 <= 9)) {
        P_line3 = P_3[E2];
    }
    else {
        a = E2 % 10;
        b = E2 / 10;
        c = a + b;
        d = c % 10;
        P_line3 = P_3[d];
    }
    P = (P_line1 + P_line2 + P_line3) / 3;
    //cout << P_line1 << ' ' << P_line2 << ' ' << P_line3 << ' ';
    //////////////////////////////////////////////////////////////////////////
    if (P == 100) {
        EXP1 = (int)ceil((float)EXP1 - 0.25 * EXP1);
    }
    else if (P != 100) {
        if (P < 50) {
            HP1 = (int)ceil((float)HP1 * 0.85);
            EXP1 = (int)ceil((float)EXP1 + 0.15 * EXP1);
        }
        else {
            HP1 = (int)ceil((float)HP1 * 0.9);
            //cout << HP1 << ' ';
            EXP1 = (int)ceil((float)EXP1 + 0.20 * EXP1);
        }
    }
}
check_limit(HP1, 0, 666);
check_limit(EXP1, 0, 600);
check_limit(M1, 0, 3000);
//cout << EXP1 << ' ' << M1 << ' ' << HP1 << '\n';
//cout << HP1 + EXP1 + M1;
return HP1 + EXP1 + M1;
}
//max_duong_cheo
int max_duong_cheo(int taxi[10][10], int x, int y, int E3) {
    int max1 = 0; int max2 = 0; int max3 = 0; int max4 = 0; int max5 = 0;
    //int taxi[10][10] = {};
    ////int Sherlock_Waston[10][10] = {};
    //for (int i = 0; i < 10; i++) {
    //    for (int j = 0; j < 10; j++) { taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j); }
    //}
    ////max_cheo_huyen
    max1 = taxi[x][y];
    for (int i = x, j = y; (i >= 0) && (j >= 0); --i, --j) {
        if (taxi[i][j] > max1) { max1 = taxi[i][j]; }
    }
    max2 = taxi[x + 1][y + 1];
    for (int i = x + 1, j = y + 1; (i < 10) && (j < 10); i++, j++) {
        if (taxi[i][j] > max2) { max2 = taxi[i][j]; }
    }
    ////max_cheo sac
    max3 = taxi[x - 1][y + 1];
    for (int i = x - 1, j = y + 1; (i >= 0) && (j < 10); --i, j++) {
        if (taxi[i][j] > max3) { max3 = taxi[i][j]; }
    }
    max4 = taxi[x + 1][y - 1];
    for (int i = x + 1, j = y - 1; (i < 10) && (j >= 0); i++, --j) {
        if (taxi[i][j] > max4) { max4 = taxi[i][j]; }
    }
    /////////////////////////////////////////////////////////////////////////
    max5 = max1;
    if (max2 >= max5) { max5 = max2; }
    if (max3 >= max5) { max5 = max3; }
    if (max4 >= max5) { max5 = max4; }
    //Sherlock_Waston[y][x] = abs(max5);
    return max5;
}
int toa_do_gap_nhau(int& count) {
    count = count % 10 + count / 10;
    if (count < 10) {
        return count;
    }
    else {
        return toa_do_gap_nhau(count);
    }
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int count1 = 0; int count2 = 0;
    int taxi[10][10] = {};
    int Sherlock_Waston[10][10] = {};
    if ((E3 < 0) || (E3 > 99)) {
        return -99;
    }
    else {
        check_limit(HP1, 0, 666);
        check_limit(EXP1, 0, 600);
        check_limit(HP2, 0, 666);
        check_limit(EXP2, 0, 600);
        //taxi
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (taxi[i][j] > (E3 * 2)) {
                    count1 = count1 + 1;
                }
                if (taxi[i][j] < (-E3)) {
                    count2 = count2 + 1;
                }
            }
        }
        if (abs(max_duong_cheo(taxi, toa_do_gap_nhau(count1), toa_do_gap_nhau(count2), E3)) < abs(taxi[toa_do_gap_nhau(count1)][toa_do_gap_nhau(count2)])) {
            EXP1 = (int)((float)EXP1 * 0.88 + 0.99999);
            EXP2 = (int)((float)EXP2 * 0.88 + 0.99999);
            HP1 = (int)((float)HP1 * 0.9 + 0.99999);
            HP2 = (int)((float)HP2 * 0.9 + 0.99999);
            return taxi[toa_do_gap_nhau(count1)][toa_do_gap_nhau(count2)];
        }
        else {
            EXP1 = (int)((float)EXP1 * 1.12 + 0.99999);
            EXP2 = (int)((float)EXP2 * 1.12 + 0.99999);
            HP1 = (int)((float)HP1 * 1.1 + 0.99999);
            HP2 = (int)((float)HP2 * 1.1 + 0.99999);
            return max_duong_cheo(taxi, toa_do_gap_nhau(count1), toa_do_gap_nhau(count2), E3);
        }
    }
    check_limit(HP1, 0, 666);
    check_limit(EXP1, 0, 600);
    check_limit(HP2, 0, 666);
    check_limit(EXP2, 0, 600);
    return -1;
}

//check ky tu and so
bool check_tung_ky_tu_and_so(char s) {
    if (((int(s) >= 97) && (int(s) <= 122)) ||
        ((int(s) >= 65) && (int(s) <= 90)) ||
        ((int(s) >= 48) && (int(s) <= 57)) ||
        ((int(s) >= 35) && (int(s) <= 38)) ||
        ((int(s)) == 33)) {
        return 1;
    }
    return 0;
}
//check chuoi
bool check_chuoi(string s, int& z) {
    for (int i = 0; i < s.size(); i++) {
        if ((check_tung_ky_tu_and_so(s[i])) == false) {
            z = i;
            return 0;
        }
    }
    return 1;
}
//check chuoi se
bool check_chuoi_se(string s, string se, int& x) {

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == se[0]) {
            x = i;
            int n = 0;
            for (int j = 0; j < se.size(); j++) {
                if (s[i + j] == se[j]) {
                    n = n + 1;
                }
            }
            if (n == se.size()) {
                return 0;
            }
        }
    }
    return 1;
}
//check ky tu lien tiep
bool check_ky_tu_lien_tiep(string s, int& y) {
    for (int i = 0; i < s.size() - 2; i++) {
        if ((s[i] == s[i + 1]) && (s[i] == s[i + 2])) {
            y = i;
            return 0;
        }
    }
    return 1;
}
//check special
bool check_special(char s) {
    if ((int(s) == 33) || (int(s) == 35) || (int(s) == 36) || (int(s) == 37) || (int(s) == 38)) {
        return 1;
    }
    else {
        return 0;
    }

}
//check ky tu dac biet
bool check_ky_tu_dac_biet(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (check_special(s[i]) == true) {
            return 1;
        }
    }
    return 0;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se;
    int x = 0; int y = 0; int z = 0;
    for (int i = 0; i < strlen(email); i++) {
        se = se + email[i];
        if (email[i + 1] == '@') {
            break;
        }
    }
    //cout << se << ' ';
    //pass hop le
    if ((strlen(s) >= 8) && (strlen(s) <= 20)) {
        if ((check_chuoi(s, z) == true)
            && (check_chuoi_se(s, se, x) == true)
            && (check_ky_tu_lien_tiep(s, y) == true)
            && (check_ky_tu_dac_biet(s) == true)) {
            return -10;
        }
    }
    if (strlen(s) < 8) {
        return -1;
    }
    if (strlen(s) > 20) {
        return -2;
    }
    if (check_chuoi_se(s, se, x) == false) {
        return -(300 + x);
    }
    if (check_ky_tu_lien_tiep(s, y) == false) {
        return -(400 + y);
    }
    if (check_ky_tu_dac_biet(s) == false) {
        return -5;
    }
    if (check_chuoi(s, z) == false) {
        return z;
    }
    //return 0;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_count = 0;
    int arr_id = 0;
    for (int i = 0; i < num_pwds; i++) {
        int count1 = 1;
        for (int j = i + 1; j < num_pwds; j++) {
            if (arr_pwds[i] == arr_pwds[j]) {
                count1 = count1 + 1;
            }
        }
        if (count1 > max_count) {
            max_count = count1;
            arr_id = i;//so sanh so lan xuat hien cua phan tu
        }
        else if (count1 == max_count && strlen(arr_pwds[i]) > strlen(arr_pwds[arr_id])) {
            arr_id = i;//tim vi tri cua phan tu dai hon trong so phan tu xuat hien nhieu nhat
        }
    }
        return arr_id;
    //return -1;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////