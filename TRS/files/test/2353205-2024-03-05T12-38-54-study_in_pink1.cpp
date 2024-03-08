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

// Task 1
void checkEXP(int& exp) {
    if (exp > 600)
        exp = 600;
    if (exp < 0)
        exp = 0;
}
void checkHP(int& hp) {
    if (hp > 666)
        hp = 666;
    if (hp < 0)
        hp = 0;
}
int lam_tron(double a) {
    if (fmod(a, 1.0) > 1e-9) {
        a = a + 1;
    }
    return a;
}
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    int D;
    double a;
    if (e1 < 0 || e1>99)
        return -99;
    if (e1 == 0)
    {
        exp2 = exp2 + 29;
        checkEXP(exp2);
    }
    else if (e1 == 1)
    {
        exp2 = exp2 + 45;
        checkEXP(exp2);
    }
    else if (e1 == 2)
    {
        exp2 = exp2 + 75;
        checkEXP(exp2);
    }
    else if (e1 == 3)
    {
        exp2 = exp2 + 29 + 45 + 75;
        checkEXP(exp2);
    }
    else if ((e1 >= 4) && (e1 <= 19))
    {
        a = (double)exp2 + ((double)e1 / 4 + 19);
        exp2 = lam_tron(a);
    }
    else if ((e1 >= 20) && (e1 <= 49))
    {
        a = (double)exp2 + ((double)e1 / 9 + 21);
        exp2 = lam_tron(a);
    }
    else if ((e1 >= 50) && (e1 <= 65))
    {
        a = (double)exp2 + ((double)e1 / 16 + 17);
        exp2 = lam_tron(a);
    }
    else if ((e1 >= 66) && (e1 <= 79))
    {
        a = (double)exp2 + ((double)e1 / 4 + 19);
        exp2 = lam_tron(a);
        checkEXP(exp2);
        if (exp2 > 200)
        {
            a = (double)exp2 + ((double)e1 / 9 + 21);
            exp2 = lam_tron(a);
        }
    }
    else if ((e1 >= 80) && (e1 <= 99)) {
        a = (double)exp2 + ((double)e1 / 4 + 19);
        exp2 = lam_tron(a);
        checkEXP(exp2);
        a = (double)exp2 + ((double)e1 / 9 + 21);
        exp2 = lam_tron(a);
        checkEXP(exp2);
        if (exp2 > 400)
        {
            a = (double)exp2 + ((double)e1 / 16 + 17);
            exp2 = lam_tron(a);
            checkEXP(exp2);
        }
        a = (double)exp2 * 1.15;
        exp2 = lam_tron(a);
    }

    if ((e1 >= 0) && (e1 <= 3))
    {
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            a = (double)exp1 + (double)D / 200;
            exp1 = lam_tron(a);
        }
        else
        {
            a = (double)exp1 - (double)D / 100;
            exp1 = lam_tron(a);
        }
    }
    else if (e1 >= 4 && e1 <= 99) {
        exp1 = exp1 - e1;
    }
    checkEXP(exp1);
    checkEXP(exp2);
    if (e1 < 0 || e1>99)
        return -99;
    else
        return exp1 + exp2;
}

// Task 2
void check_tien(int& m) {
    if (m > 3000)
        m = 3000;
    else if (m < 0)
        m = 0;
}
void sukien1_conduong2(int& HP1, int& EXP1, int& M1, int& E3, int& tieu) {
    double a;
    if (HP1 < 200)
    {
        a = (double)HP1 * 1.3;
        HP1 = lam_tron(a);
        M1 = M1 - 150;
        tieu = tieu + 150;
    }
    else
    {
        a = (double)HP1 * 1.1;
        HP1 = lam_tron(a);
        M1 = M1 - 70;
        tieu = tieu + 70;
    }
    checkHP(HP1);
    check_tien(M1);
}
void sukien2_conduong2(int& HP1, int& EXP1, int& M1, int& E3, int& tieu) {
    double a;
    if (EXP1 < 400)
    {
        M1 = M1 - 200;
        tieu = tieu + 200;
        a = (double)EXP1 * 1.13;
        EXP1 = lam_tron(a);
    }
    else {
        M1 = M1 - 120;
        tieu = tieu + 120;
        a = (double)EXP1 * 1.13;
        EXP1 = lam_tron(a);
    }
    checkEXP(EXP1);
    check_tien(M1);
}
void sukien3_conduong2(int& HP1, int& EXP1, int& M1, int& E3, int& tieu) {
    double a;
    if (EXP1 < 300)
    {
        M1 = M1 - 100;
        tieu = tieu + 100;
        a = (double)EXP1 * 0.90;
        EXP1 = lam_tron(a);
    }
    else {
        M1 = M1 - 120;
        tieu = tieu + 120;
        a = (double)EXP1 * 0.90;
        EXP1 = lam_tron(a);
    }
    checkEXP(EXP1);
    check_tien(M1);
}
int xac_dinh_i(int E3) {
    int n, so, tong, dem, i;
    dem = 0;
    tong = 0;
    so = 0;
    n = E3;
    if (n == 0)
        return 0;
    while (n != 0)
    {
        so = n % 10;//lay so hang don vi ra
        tong += so;//cong so hang don vi
        n /= 10;//chia cho 10 de chuyen so tu hang chuc sang hang don vi
        dem++;
    }
    if (dem == 1)
        return E3;
    else {
        if (tong >= 10)
            i = tong % 10;
        else
            i = tong;
        return i;
    }
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    int tieu;
    double P1, P2, P3, Ptb, a, S;
    double b;
    tieu = 0;
    double P[10] = { 32,47,28,79,100,50,22,83,64,11 };
    if (E2 < 0 || E2>99)
        return -99;
    S = round(sqrt(EXP1));
    S = pow(S, 2);
    if (EXP1 >= S)
        P1 = 1;
    else
        P1 = (((double)EXP1 / (double)S + 80) / 123);
    if (M1 != 0) {
        if ((E2 % 2) != 0) {
            b = M1 * 0.5;
            //lap cho toi khi tien da tieu lon hon 50% M1 truoc khi bat dau duong 2
            while (tieu < b) {
                sukien1_conduong2(HP1, EXP1, M1, E2, tieu);
                if (tieu > b)
                    break;
                sukien2_conduong2(HP1, EXP1, M1, E2, tieu);
                if (tieu > b)
                    break;
                sukien3_conduong2(HP1, EXP1, M1, E2, tieu);
                if (tieu > b)
                    break;
            }

            checkEXP(EXP1);
            checkHP(HP1);
        }
        else {
            sukien1_conduong2(HP1, EXP1, M1, E2, tieu);
            if (M1 > 0) {
                sukien2_conduong2(HP1, EXP1, M1, E2, tieu);
                if (M1 > 0) {
                    sukien3_conduong2(HP1, EXP1, M1, E2, tieu);
                }
            }
            check_tien(M1);
        }
        a = (double)HP1 * 0.83;
        HP1 = lam_tron(a);
        a = (double)EXP1 * 1.17;
        EXP1 = lam_tron(a);
        checkEXP(EXP1);
        checkHP(HP1);
    }
    S = round(sqrt(EXP1));
    S = pow(S, 2);
    if (EXP1 >= S)
        P2 = 1;
    else
        P2 = (((double)EXP1 / (double)S + 80) / 123);
    int i = xac_dinh_i(E2);
    P3 = P[i] / 100;
    if ((P1 + P2 + P3) == 3.0)
    {
        a = (double)EXP1 * 0.75;
        EXP1 = lam_tron(a);
    }
    else {
        Ptb = (P1 + P2 + P3) / 3;
        if (Ptb < 0.5) {
            a = (double)HP1 * 0.85;
            HP1 = lam_tron(a);
            //a = (double)EXP1 * 1.15;
            //EXP1 = lam_tron(a);
        }
        else {
            a = (double)HP1 * 0.90;
            HP1 = lam_tron(a);
            a = (double)EXP1 * 1.20;
            EXP1 = lam_tron(a);
        }
    }
    check_tien(M1);
    checkEXP(EXP1);
    checkHP(HP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int cong_hai_so(int a) {
    int tong = 0;
    while (a != 0) {
        tong = tong + a % 10;
        a /= 10;
    }
    return tong;
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    int lon_hon = 0;
    int nho_hon = 0;
    int ma_tran[10][10];
    int duong_tat;
    int tri_duong_tat;
    int taxi;
    double a;
    if (E3 < 0 || E3>99)
        return -99;
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
        lon_hon = cong_hai_so(lon_hon);
    }
    while ((nho_hon / 10) > 0)
    {
        nho_hon = cong_hai_so(nho_hon);
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

    if (taxi > tri_duong_tat)
    {
        a = ((double)EXP1 * 0.88);
        EXP1 = lam_tron(a);
        a = ((double)EXP2 * 0.88);
        EXP2 = lam_tron(a);
        a = ((double)HP1 * 0.9);
        HP1 = lam_tron(a);
        a = ((double)HP2 * 0.9);
        HP2 = lam_tron(a);
    }
    else {
        a = ((double)EXP1 * 1.12);
        EXP1 = lam_tron(a);
        a = ((double)EXP2 * 1.12);
        EXP2 = lam_tron(a);
        a = ((double)HP1 * 1.1);
        HP1 = lam_tron(a);
        a = ((double)HP2 * 1.1);
        HP2 = lam_tron(a);
    }
    checkEXP(EXP1);
    checkEXP(EXP2);
    checkHP(HP1);
    checkHP(HP2);
    int tra_ve;
    if (taxi > tri_duong_tat) {
        tra_ve = ma_tran[lon_hon][nho_hon];
    }
    else {
        tra_ve = tri_duong_tat;
    }
    return tra_ve;
}

// Task 4
int check_invalid_charr(char s) {
    if (s >= '0' && s <= '9') return false;
    if (s >= 'A' && s <= 'Z') return false;
    if (s >= 'a' && s <= 'z') return false;
    if ((s == '@') || (s == '#') || (s == '%') || (s == '$') || (s == '!'))
        return false;
    return true;
}
bool speicial(string s) {
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] == '@') || (s[i] == '#') || (s[i] == '%') || (s[i] == '$') || (s[i] == '!'))
            return false;
    }
    return true;
}
int similar(string s) {
    for (int i = 0; i < s.length(); i++)
    {
        if (i + 1 == s.length())
            break;
        if (s[i + 1] == s[i])
        {
            if (s[i + 2] == s[i])
                return i;
        }
    }
    return 200;
}
int Matching(string se, string s) {
    int sei = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == se[0]) {

            for (int j = 0; j < se.length(); j++) {
                if (s[j + i] == se[j])
                    sei += 1;
            }
            if (sei == se.length())
                return i;
        }
    }
    return 200;
}
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    string string_s = s;
    string string_email = email;

    int u = -10;
    int thu_tu_sai = -1;
    string se;
    int i = 0;
    while (string_email[i] != '@')
    {
        se = se + string_email[i];
        i++;
    }
    int sei = Matching(se, string_s);
    int sci = similar(string_s);
    for (int i = 0; i < string_s.length(); i++) {
        if (check_invalid_charr(s[i])) {
            thu_tu_sai = i;
            break;
        }
    }
    if (string_s.length() < 8)
        u = -1;
    else if (string_s.length() > 20)
        u = -2;
    else if (sei != 200 || sci != 200) {
        if (sei <= sci && sei != 200)
            u = -(300 + sei);
        if (sci < sei && sci != 200)
            u = -(400 + sci);
    }
    else if (speicial(string_s))
        u = -5;
    else if (thu_tu_sai != -1)
        u = thu_tu_sai;
    return u;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int count_max = 0;
    int tt_max = 0;

    for (int i = 0; i < num_pwds; i++)
    {
        int count_nhap = 0;
        for (int j = 0; j < num_pwds; j++)
        {
            if (arr_pwds[i] == arr_pwds[j])
            {
                count_nhap++;

            }
        }
        if (count_nhap > count_max || (count_nhap == count_max && strlen(arr_pwds[i]) > strlen(arr_pwds[tt_max])))
        {
            count_max = count_nhap;
            tt_max = i;
        }
    }
    return tt_max;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////