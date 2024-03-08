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

int RoundUP(double x) {                         // HAM LAM TRON LEN
    double A = x + 0.999;
    return A;
}

int checkHP(int HP) {                           // HAM KIEM TRA HP
    if (HP < 0) HP = 0;
    else if (HP > 666) HP = 666;
    else ;
    return HP;
}

int checkEXP(int exp) {                         // HAM KIEM TRA EXP 
    if (exp < 0) exp = 0;
    else if (exp > 600) exp = 600;
    else ;
    return exp;
}

int checkM(int M) {                             // HAM KIEM TRA SO TIEN
    if (M < 0) M = 0;
    else if (M > 3000) M = 3000;
    else ;
    return M;
}

// Task 1
void MeetCase1(int &exp1, int &exp2, int e1) {                  // TRUONG HOP 1
    switch (e1) {
        case 0: {                               // GIAI THICH THONG TIN 1
            exp2 = exp2 + 29;
            break;
        }
        case 1: {                               // GIAI THICH THONG TIN 2
            exp2 = exp2 + 45;
            break;
        }
        case 2: {                               // GIAI THICH THONG TIN 3
            exp2 = exp2 + 75;
            break;
        }
        case 3: {                               // GIAI THICH CA 3 THONG TIN
            exp2 = exp2 + 29 + 45 + 75;
            break;
        }
    }
    int D = (e1*3)+(exp1*7);                    // Tinh so nguyen D
    float exp1_cal = exp1;                      // Chuyen EXP1 sang so thuc de tinh toan
    if (D%2==0) exp1_cal += (float)D/200;       // Neu D la so chan
    else exp1_cal -= (float)D/100;              // Neu D la so le
    exp1 = RoundUP(exp1_cal);                   // Lam tron EXP1 sau khi da tinh toan
    return;
}

void MeetCase2(int &exp1, int &exp2, int e1) {                  // TRUONG HOP 2
    int info;
    float info1, info2, info3, exp2_cal;
    exp2_cal = exp2;
    info1 = e1*1.0000/4 + 19;
    info2 = e1*1.0000/9 + 21;
    info3 = e1*1.0000/16 + 17;
    
    // XET TRUONG HOP TRONG CAC KHOANG E1
    if ((4<=e1)&&(e1<=19)) info = 1;
    else if ((20<=e1)&&(e1<=49)) info = 2;
    else if ((50<=e1)&&(e1<=65)) info = 3;
    else if ((66<=e1)&&(e1<=79)) info = 4;
    else if ((80<=e1)&&(e1<=99)) info = 5;
    
    switch(info) {
        case 1: {                               // GIAI THICH THONG TIN 1
            exp2_cal += info1;
            break;
        }
        case 2: {                               // GIAI THICH THONG TIN 2
            exp2_cal += info2;
            break;
        }
        case 3: {                               // GIAI THICH THONG TIN 3
            exp2_cal += info3;
            break;
        }
        case 4: {                               // GIAI THICH THONG TIN 1, KIEM TRA EXP2 DE GIAI THICH TIEP THONG TIN 2
            exp2_cal += info1;                  
            exp2 = RoundUP(exp2_cal);
            if (checkEXP(exp2) > 200) {                 // Kiem tra xem EXP2 co thoa dieu kien de cap nhat them thong tin 2
                exp2_cal = exp2;
                exp2_cal += info2;
            }
            break;
        }
        case 5: {                               // GIAI THICH THONG TIN 1 VA THONG TIN 2, KIEM TRA EXP2 DE GIAI THICH THONG TIN 3
            exp2_cal += info1;
            exp2 = RoundUP(exp2_cal);
            exp2_cal = exp2;
            exp2_cal += info2;
            exp2 = RoundUP(exp2_cal);
            if (checkEXP(exp2) > 400) {                 // Kiem tra xem EXP2 co thoa dieu kien de cap nhat them thong tin 3
                exp2_cal = exp2;
                exp2_cal += info3;
                exp2 = RoundUP(exp2_cal);
                exp2_cal = checkEXP(exp2);
                exp2_cal *= 1.15;
            }
            break;
        }    
    }
    exp2 = RoundUP(exp2_cal);                  // Lam tron EXP2 sau khi tinh toan
    exp1 -= e1;                                // Cap nhat EXP1
}

int firstMeet(int &exp1, int &exp2, int e1) {
    // TODO: Complete this function

    // KIEM TRA EXP1 VA EXP2 CO NAM TRONG KHOANG CHO PHEP
    exp1 = checkEXP(exp1);
    exp2 = checkEXP(exp2);

    if ((0<=e1)&&(e1<=3)) MeetCase1(exp1, exp2, e1);                    // KIEM TRA E1 TRONG TRUONG HOP 1
    else if ((4<=e1)&&(e1<=99)) MeetCase2(exp1, exp2, e1);              // KIEM TRA E1 TRONG TRUONG HOP 2
    else return -99;                            // Neu E1 nam ngoai khoang cho phep thi tra ve -99
    
    // KIEM TRA LAI EXP1 VA EXP2 CO NAM TRONG KHOANG CHO PHEP
    exp1 = checkEXP(exp1);
    exp2 = checkEXP(exp2);
    return exp1 + exp2;
}

// Task 2
double Street1(int & EXP1) {                                        // XAC SUAT TIM THAY VALI TREN CON DUONG 1
    double P;
    int S, x, y;
    x = sqrt(EXP1);                                         // Tinh can bac 2 cua EXP1 de tim phan nguyen 
    y = x + 1;                                              //  Tang phan nguyen them 1

    //  SO SANH XEM DAU LA SO CHINH PHUONG GAN EXP1 NHAT
    if (abs(EXP1 - x*x) > abs(EXP1 - y*y)) S = y*y;         // So chinh phuong lon hon EXP1
    else S = x*x;                                           // So chinh phuong nho hon hoac bang EXP1
    
    if (EXP1 >= S)                                          // So sanh giua EXP1 va so chinh phuong S
        P = 100;
    else P = (((float)EXP1 / (float)S) + 80)/123*100;
    return P;
}

double Street2(int &HP1, int &EXP1, int &M1, int E2) {              // XAC SUAT TIM THAY VALI TREN CON DUONG 2
    int M_spend = 0;                                        // So tien da chi tra cho cac su kien
    float half = M1 * 0.5;                                  // Phan nua so tien ban dau
    
    if (M1 == 0) {                                          // Neu so tien M1 ban dau bang 0 thi cap nhat HP va EXP ngay lap tuc
        HP1 = checkHP(RoundUP((float)HP1 * 0.83));
        EXP1 = checkEXP(RoundUP((float)EXP1 * 1.17));
    } else if (E2 % 2 == 0) {                               // Xet truong hop neu E2 la so chan
                // SU KIEN 1
                if (HP1 < 200) {
                    M1 -= 150;      M1 = checkM(M1);
                    HP1 = RoundUP((float)HP1 * 1.3);
                    HP1 = checkHP(HP1);
                } else {
                    M1 -= 70;       M1 = checkM(M1);
                    HP1 = RoundUP((float)HP1 * 1.1);
                    HP1 = checkHP(HP1);
                } 
                if (M1 != 0) {                              // Kiem tra so tien con lai
                    // SU KIEN 2
                    if (EXP1 < 400) {
                        M1 -= 200;      M1 = checkM(M1);
                        EXP1 = RoundUP((float)EXP1 * 1.13);
                        EXP1 = checkEXP(EXP1);
                    } else {
                        M1 -= 120;      M1 = checkM(M1);
                        EXP1 = RoundUP((float)EXP1 * 1.13);
                        EXP1 = checkEXP(EXP1);
                    }
                } else goto even;               // Di bo den cuoi duong
                if (M1 != 0) {                              // Kiem tra so tien con lai
                    // SU KIEN 3
                    if (EXP1 < 300) {
                        M1 -= 100;      M1 = checkM(M1);
                        EXP1 = RoundUP((float)EXP1 * 0.9);
                        EXP1 = checkEXP(EXP1);
                    } else {
                        M1 -= 120;      M1 = checkM(M1);
                        EXP1 = RoundUP((float)EXP1 * 0.9);
                        EXP1 = checkEXP(EXP1);
                    }
                } else goto even;               // Di bo den cuoi duong
            
            // CAP NHAT HP VA EXP SAU KHI DA TRAI QUA 3 SU KIEN HOAC KHI KHONG DU TIEN DE THUC HIEN HANH DONG TIEP THEO
            even: {
                HP1 = checkHP(RoundUP((float)HP1 * 0.83));
                EXP1 = checkEXP(RoundUP((float)EXP1 * 1.17));
            }
    } else {                                                // Truong hop E2 la so le
        while (M_spend <= half) {                                       // Kiem tra so tien da chi tra co lon hon hay khong
            // SU KIEN 1
            if (HP1 < 200) {
                M1 -= 150;      M1 = checkM(M1);        M_spend += 150;
                HP1 = RoundUP((float)HP1 * 1.3);
                HP1 = checkHP(HP1);
            } else {
                M1 -= 70;       M1 = checkM(M1);        M_spend += 70;
                HP1 = RoundUP((float)HP1 * 1.1);
                HP1 = checkHP(HP1);
            }
            if (M_spend <= half) {                                      // Kiem tra so tien da chi tra co lon hon hay khong
                // SU KIEN 2
                if (EXP1 < 400) {
                    M1 -= 200;      M1 = checkM(M1);        M_spend += 200;
                    EXP1 = RoundUP((float)EXP1 * 1.13);
                    EXP1 = checkEXP(EXP1);
                } else {
                    M1 -= 120;      M1 = checkM(M1);        M_spend += 120;
                    EXP1 = RoundUP((float)EXP1 * 1.13);
                    EXP1 = checkEXP(EXP1);
                } 
            } else goto odd;               // Di bo den cuoi duong
            if (M_spend <= half) {                                      // Kiem tra so tien da chi tra co lon hon hay khong
                // SU KIEN 3
                if (EXP1 < 300) {
                    M1 -= 100;      M1 = checkM(M1);        M_spend += 100;
                    EXP1 = RoundUP((float)EXP1 * 0.9);
                    EXP1 = checkEXP(EXP1);
                } else {
                    M1 -= 120;      M1 = checkM(M1);        M_spend += 120;
                    EXP1 = RoundUP((float)EXP1 * 0.9);
                    EXP1 = checkEXP(EXP1);
                }
            } else goto odd;               // Di bo den cuoi duong
        }
        
        // CAP NHAT HP VA EXP SAU KHI SO TIEN CHI TRA LON HON 50% SO TIEN BAN DAU
        odd: {
            HP1 = checkHP(RoundUP((float)HP1 * 0.83));
            EXP1 = checkEXP(RoundUP((float)EXP1 * 1.17));
        }
    }
    double P = Street1(EXP1);
    return P;
}

double Street3(int E2) {                                            // XAC SUAT TIM THAY VALI TREN CON DUONG 3
    float P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i, a, b, T;
    if (E2 < 10) i = E2;                            // Neu E2 co 1 chu so thi tra ve P tuong ung
    else {                                          // Neu E2 co 2 chu so
        a = E2/10;  b = E2%10;
        T = a + b;                                  // Tong 2 chu so
        i = T % 10;                                 // Lay chu so hang don vi 
    }
    return P[i];
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if ((E2 < 0)||(E2 > 99)) return -99;                        // Neu E2 nam ngoai khoang cho phep thi tra ve -99
    
    // KIEM TRA HP1, EXP1 VA M1 CO NAM TRONG KHOANG CHO PHEP
    HP1 = checkHP(HP1);
    EXP1 = checkEXP(EXP1);
    M1 = checkM(M1);
    
    double P1, P2, P3, P;
    P1 = Street1(EXP1);                                     // Xac suat tren con duong 1
    P2 = Street2(HP1, EXP1, M1, E2);                        // Xac suat tren con duong 2
    P3 = Street3(E2);                                       // Xac suat tren con duong 3
    P = (P1 + P2 + P3)/3;                       // Tinh xac suat cuoi cung
    
    if ((P1==100)&&(P2==100)&&(P3==100)) {                  // Khi xac suat tren ca 3 con duong deu la 100%
        EXP1 = checkEXP(RoundUP((float)EXP1 * 0.75));       // Cap nhat va kiem tra EXP1
    } else if (P < 50) {                                    // Neu xac suat cuoi cung be hon 50%
        // Cap nhat va kiem tra HP1 va EXP1
        HP1 = checkHP(RoundUP((float)HP1 * 0.85));         
        EXP1 = checkEXP(RoundUP((float)EXP1 * 1.15));
    } else {                                                // Neu xac suat cuoi cung lon hon hoac bang 50%
        // Cap nhat va kiem tra HP1 va EXP1
        HP1 = checkHP(RoundUP((float)HP1 * 0.9));
        EXP1 = checkEXP(RoundUP((float)EXP1 * 1.2));
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int point(int n) {                                      // TIM VI TRI GAP NHAU
    int a, b;
    while (n >= 10) {
        a = n / 10;
        b = n % 10;
        n = a + b;
    }
    return n;
}

int max_value(int a, int b) {                           // TIM MAX GIUA 2 SO 
    int MAX = a;
    if (b > MAX) MAX = b;
    return MAX;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ((E3 < 0)||(E3 > 99)) return -99;                        // Neu E3 nam ngoai khoang cho phep thi tra ve -99
    
    int i, j, a, b, m, n, max_l, max_r;
    int taxi[10][10];
    int SW[10][10];
    
    // KHOI TAO MANG TINH DIEM SO CUA TAXI
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            taxi[i][j] = ((E3*j) + (i*2))*(i-j);
        }
    }
    
    // KHOI TAO MANG TINH DIEM SO CHO SHERLOCK - WATSON
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            max_l = taxi[i][j];                                 // Khoi tao phan tu co gia tri lon nhat tren duong cheo trai
            max_r = taxi[i][j];                                 // Khoi tao phan tu co gia tri lon nhat tren duong cheo phai
            for (m = 0; m < 10; m++) {
                for (n = 0; n < 10; n++) {
                    if ((m - n)==(i - j)) {                     // XET CAC PHAN TU TREN DUONG CHEO TRAI
                        if (taxi[m][n] > max_l)
                            max_l = taxi[m][n];                 // Cap nhat gia tri lon nhat tren duong cheo trai
                    }
                    if ((m + n)==(i + j)) {                     // XET CAC PHAN TU TREN DUONG CHEO PHAI
                        if (taxi[m][n] > max_r)
                            max_r = taxi[m][n];                 // Cap nhat gia tri lon nhat tren duong cheo phai
                    }
                }
            }
            // SO SANH 2 GIA TRI LON NHAT TREN DUONG CHEO ROI GAN GIA TRI SHERLOCK - WATSON
            SW[i][j] = abs(max_value(max_l, max_r));            
        }
    }
    
    // TIM VI TRI GAP NHAU GIUA TAXI VA SHERLOCK - WATSON
    a = 0; b = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (taxi[i][j] > (E3*2)) a += 1;                    // Tim tat ca cac gia tri lon hon E3*2 de tim chi so i
            if (taxi[i][j] < -E3) b += 1;                       // Tim tat ca cac gia tri nho hon -E3 de tim chi so j
        }
    }
    // VI TRI GAP NHAU
    i = point(a);
    j = point(b);
    
    if (abs(taxi[i][j]) > SW[i][j]) {                           // TRUONG HOP SHERLOCK VA WATSON KHONG DUOI KIP TAXI
        // Cap nhat va kiem tra cac gia tri EXP1, EXP2, HP1, HP2 tuong ung 
        EXP1 = checkEXP(RoundUP((float)EXP1 * 0.88));
        EXP2 = checkEXP(RoundUP((float)EXP2 * 0.88));
        HP1 = checkHP(RoundUP((float)HP1 * 0.9));
        HP2 = checkHP(RoundUP((float)HP2 * 0.9));
        return taxi[i][j];              // Tra ve diem so cua taxi
    } else {                                                    // TRUONG HOP SHERLOCK VA WATSON DUOI KIP TAXI
        // Cap nhat va kiem tra cac gia tri EXP1, EXP2, HP1, HP2 tuong ung
        EXP1 = checkEXP(RoundUP((float)EXP1 * 1.12));
        EXP2 = checkEXP(RoundUP((float)EXP2 * 1.12));
        HP1 = checkHP(RoundUP((float)HP1 * 1.1));
        HP2 = checkHP(RoundUP((float)HP2 * 1.1));
        return SW[i][j];                // Tra ve diem so cua Sherlock - Watson
    }
    return -1;
}

// Task 4

// KIEM TRA MAT KHAU CO CHUA NHIEU HON 2 KY TU LIEN TIEP GIONG NHAU
bool checkDuplicate(int i, const char * s) {                               
    if ((s[i] == s[i+1]) && (s[i] == s[i+2]))
        return 1;
    else return 0;
}

// KIEM TRA MAT KHAU CO CHUA KY TU DAC BIET
bool hasSpecialChar(int i, const char * s) {
    if (s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!') 
        return 1;
    else return 0;
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string pwd = s;
    string account = email;

    int len = strlen(s);
    int d = 0;

    // TACH CHUOI se NAM TRUOC KY TU '@' TRONG EMAIL
    while (email[d] != '@') {
        ++d;
    }
    string se = account.substr(0, d);       
    
    // KIEM TRA TINH HOP LE CUA MAT KHAU
    if (len < 8)                                    // MAT KHAU CO DO DAI NGAN HON DO DAI TOI THIEU
        return -1;                                          // Tra ve -1
    else if (len > 20)                              // MAT KHAU CO DO DAI DAI HON DO DAI TOI DA
        return -2;                                          // Tra ve -2
    else {
        bool Contain = 0;                       // Kiem tra mat khau co chua chuoi se hay khong?
        bool Duplicate = 0;                     // Kiem tra mat khau co chua nhieu hon 2 ky tu giong nhau lien tiep hay khong?
        bool Special = 0;                       // Kiem tra mat khau co chua it nhat 1 ky tu dac biet hay khong?
        bool Invalid = 0;                       // Kiem tra mat khau co chua ky tu khong hop le hay khong?

        int C_pos ;                             // Vi tri dau tien chua chuoi se
        int D_pos ;                             // Vi tri dau tien cua dau tien gom nhieu hon 2 ky tu giong nhau lien tiep
        int I_pos ;                             // Vi tri dau tien cua ky tu khong hop le

        // KIEM TRA MAT KHAU CO CHUA CHUOI se 
        int pos = pwd.find(se);
        if (pos != -1) {
            Contain = 1;                            // Mat khau co chua chuoi se
            C_pos = -(300 + pos);                   // Cap nhat vi tri 
        } else {
            for (int i = 0; i < len; i++) { 
                if (checkDuplicate(i, s)) {
                        Duplicate = 1;              // Mat khau co chua nhieu hon 2 ky tu giong nhau lien tiep
                        D_pos = -(400 + i);         // Cap nhat vi tri 
                }
                // KIEM TRA MAT KHAU CO CHUA KY TU KHONG HOP LE
                else if (!(((48<=s[i])&&(s[i]<=57)) || ((65<=s[i])&&(s[i]<=90)) || ((97<=s[i])&&(s[i]<=122)) 
                        || (hasSpecialChar(i, s)))) 
                    {
                        Invalid = 1;                // Mat khau co chua ky tu khong hop le
                        I_pos = i;                  // Cap nhat vi tri
                }
                else if (hasSpecialChar(i, s)) {
                        Special = 1;                // Mat khau co chua it nhat 1 ky tu dac biet
                }
            }
        }

        if (Contain) 
            return C_pos;                       // Tra ve -(300 + <sei>)
        else if (Duplicate)
            return D_pos;                       // Tra ve -(400 + <sci>)
        else if (!Special) 
            return -5;                          // Tra ve -5 (Mat khau khong chua ky tu dac biet)
        else if (Invalid)
            return I_pos;                       // Tra ve vi tri dau tien cua ky tu khong hop le
        else return -10;                // Mat khau hop le
    }
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_length = 0;                                     // Do dai lon nhat cua mat khau
    int max_count = 0;                                      // So lan xuat hien nhieu nhat cua mat khau 
    int pos = -1;                                           // Vi tri dau tien cua mat khau dung
    
    // KIEM TRA TUNG MAT KHAU TRONG MANG
    for (int i = 0; i < num_pwds; i++) {                                
        int length = strlen(arr_pwds[i]);                       // Do dai cua mat khau dang xet
        int count = 0;                                          // Khoi tao bien dem so lan xuat hien cua mat khau dang xet
        
        // DUYET QUA CAC MAT KHAU TRONG MANG DE DEM SO LAN XUAT HIEN CUA MAT KHAU DANG XET
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[j], arr_pwds[i]) == 0) {        // Kiem tra hai mat khau co bang nhau hay khong?
                count += 1;                                     // Cap nhat so lan xuat hien cua mat khau dang xet
            }
        }
        
        // SO SANH SO LAN XUAT HIEN CUA MAT KHAU DANG XET VOI SO LAN XUAT HIEN NHIEU NHAT
        if (count > max_count) {                    
            max_count = count;          // Cap nhat so lan xuat hien nhieu nhat cua mat khau trong mang
            if (length > max_length) {              // SO SANH DO DAI CUA MAT KHAU 
                pos = i;                            // Cap nhat vi tri cua mat khau dung (Truong hop mat khau co do dai lon nhat)
                max_length = length;                // Cap nhat do dai lon nhat cua mat khau trong mang
            }
            pos = i;                    // Cap nhat vi tri cua mat khau dung (Truong hop mat khau co so lan xuat hien nhieu nhat)
        
        // TRUONG HOP 2 MAT KHAU CO CUNG SO LAN XUAT HIEN NHIEU NHAT
        } else if (count == max_count) {
                    if (length > max_length) {          // SO SANH DO DAI CUA MAT KHAU 
                        pos = i;                             // Cap nhat vi tri cua mat khau dung 
                        max_length = length;                 // Cap nhat do dai lon nhat cua mat khau trong mang
                    }
        }        
    }
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////