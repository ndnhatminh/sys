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

void max_value( int & HP1, int & HP2, int & exp1, int & exp2, int & M1, int & M2 ){
    if ( HP1 > 666 ) HP1 = 666;
    if ( HP1 < 0 ) HP1 = 0;
    if ( HP2 > 666 ) HP2 = 666;
    if ( HP2 < 0 ) HP2 = 0;
    if ( exp1 > 600) exp1 = 600;
    if ( exp1 < 0) exp1 = 0;
    if ( exp2 > 600) exp2 = 600;
    if ( exp2 < 0) exp2 = 0;
    if ( M1 > 3000) M1 = 3000;
    if ( M1 < 0) M1 = 0;
    if ( M2 > 3000) M2 = 3000;
    if ( M2 < 0) M2 = 0;
}
// 1: sherlock 2: watson
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ( e1 < 0 || e1 > 99) return -99;
    else {
        if ( exp1 > 600) exp1 = 600;
        if ( exp1 < 0) exp1 = 0;
        if ( exp2 > 600) exp2 = 600;
        if ( exp2 < 0) exp2 = 0;
        if ( e1 >= 0 && e1 <= 3){
            if ( e1 == 0) exp2 += 29;
            else if ( e1 == 1) exp2 += 45;
            else if ( e1 == 2) exp2 += 75;
            else if ( e1 == 3) exp2 = exp2 +29 +45 +75;
            if ( exp2 > 600) exp2 = 600;
            if ( exp2 < 0) exp2 = 0;
            int D = e1 * 3 + exp1 * 7;
            if ( D % 2 == 0) {
                exp1 = (exp1 + D*0.005 + 0.9999999);
            }
            else {
                exp1 = (exp1 - D * 0.01 + 0.9999999);
            }
            if ( exp1 > 600) exp1 = 600;
            if ( exp1 < 0) exp1 = 0;
        }
        else if ( e1 >= 4 && e1 <= 99){
              if ( e1 >= 4 && e1 <= 19) exp2 = (exp2 + (e1 * 0.25 + 19) + 0.9999999);
              else if ( e1 >= 20 && e1 <= 49) exp2 = (exp2 + (double(e1)/9 + 21) + 0.9999999);
              else if ( e1 >= 50 && e1 <= 65) exp2 = (exp2 + (e1 * 0.0625 + 17) + 0.9999999);
              else if ( e1 >= 66 && e1 <= 79) {
                exp2 = (exp2 + (e1 * 0.25 + 19) + 0.9999999);
                if ( exp2 > 600) exp2 = 600;
                if ( exp2 < 0) exp2 = 0;
                if ( exp2 > 200) exp2 = (exp2 + (double(e1)/9 + 21) + 0.9999999);
              }
              else if ( e1 >= 80 && e1 <= 99) {
                exp2 = (exp2 + (e1 * 0.25 + 19) + 0.9999999);
                if ( exp2 > 600) exp2 = 600;
                if ( exp2 < 0) exp2 = 0;
                exp2 = (exp2+ (double(e1)/9 + 21) + 0.9999999);
                if ( exp2 > 400) {
                    exp2 = (exp2 + (e1 * 0.0625 + 17) + 0.9999999);
                    exp2 = (exp2 * 1.15 + 0.9999999) ;
                }
              }    
              if ( exp2 > 600) exp2 = 600;
              if ( exp2 < 0) exp2 = 0;
              exp1 -= e1;  
        }
        if ( exp1 > 600) exp1 = 600;
        if ( exp1 < 0) exp1 = 0;
        if ( exp2 > 600) exp2 = 600;
        if ( exp2 < 0) exp2 = 0;
        return exp1 + exp2;
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if ( E2 < 0 || E2 > 99) return -99;
    else {
        if ( EXP1 > 600) EXP1 = 600;
        if ( EXP1 < 0) EXP1 = 0;
        if ( HP1 > 666 ) HP1 = 666;
        if ( HP1 < 0 ) HP1 = 0;
        if ( M1 > 3000) M1 = 3000;
        if ( M1 < 0) M1 = 0;
        int s[27];
        int P1, P2;
        // con duong 01
        for ( int i = 0 ; i <= 25 ; i++ ){
            s[i] = i * i;
        }
        // tim so chinh phuong gan exp1 nhat
        int min1 = 9999999, flag1 = 0;
        for ( int i = 0 ; i <= 25 ; i++){
            if ( abs(EXP1 - s[i]) <= min1 ) {
                min1 = abs(EXP1 - s[i]);
                flag1 = i;
            }
        }
        if ( EXP1 >= s[flag1] ) P1 = 100;
        else P1 = (double(double(EXP1) / s[flag1] + 80)) / 123 * 100; 
        // con duong 02
        
        if ( E2 % 2 == 1 && M1 != 0){
            int money = 0 , money0 = M1;
            while (money <= money0 * 0.5){
                if ( HP1 < 200) {
                    HP1 = HP1 * 1.3 + 0.9999999;
                    if ( HP1 > 666 ) HP1 = 666;
                    M1 -= 150;
                    money += 150;
                }
                else {
                    HP1 = HP1 * 1.1 + 0.9999999;
                    if ( HP1 > 666 ) HP1 = 666;
                    M1 -= 70;
                    money += 70;
                }
                if (  money > money0 * 0.5) {
                    break;
                }
                if ( EXP1 < 400 ) {M1 -= 200; money += 200;}
                else {M1 -= 120; money += 120;}
                EXP1 = EXP1 * 1.13 + 0.9999999;
                if ( EXP1 > 600) EXP1 = 600;
                if ( money > money0 * 0.5) {
                    break;
                }
                if ( EXP1 < 300) {M1 -= 100; money += 100;}
                else {M1 -= 120; money += 120;}
                EXP1 = EXP1 * 0.9 + 0.9999999;
                if ( EXP1 > 600) EXP1 = 600;
                if ( money > money0 * 0.5)  {
                    break;
                }
            }
        }
        else if ( E2 % 2 == 0 && M1 != 0 ){
            while ( M1 > 0){
                if ( HP1 < 200) {
                    HP1 = HP1 * 1.3 + 0.9999999;
                    if ( HP1 > 666 ) HP1 = 666;
                    M1 -= 150;
                }
                else {
                    HP1 = HP1 * 1.1 + 0.9999999;
                    if ( HP1 > 666 ) HP1 = 666;
                    M1 -= 70;
                }
                if ( M1 <= 0) {
                    M1 = 0;
                    break;
                }
                if ( EXP1 < 400 ) {M1 -= 200;}
                else {M1 -= 120;}
                EXP1 = EXP1 * 1.13 + 0.9999999;
                if ( EXP1 > 600) EXP1 = 600;
                if ( M1 <= 0) {
                    M1 = 0;
                    break;
                }
                if ( EXP1 < 300) {M1 -= 100; }
                else {M1 -= 120; }
                EXP1 = EXP1 * 0.9 + 0.9999999;
                if ( EXP1 > 600) EXP1 = 600;
                if ( M1 <= 0)  {
                    M1 = 0;
                    break;
                }
                break;
            }
        }
        HP1 = HP1 * 0.83 + 0.9999999;
        if ( HP1 > 666 ) HP1 = 666;
        EXP1 = EXP1 * 1.17 + 0.9999999;
        if ( EXP1 > 600) EXP1 = 600;
        int min2 = 9999999, flag2 = 0;
        for ( int i = 0 ; i <= 25 ; i++){
            if ( abs(EXP1 - s[i]) <= min2 ) {
                min2 = abs(EXP1 - s[i]);
                flag2 = i;
            }
        }
        if ( EXP1 >= s[flag2] ) P2 = 100;
        else P2 = (double(double(EXP1) / s[flag2] + 80)) / 123 * 100; 
        // con duong 3 
        int cd3[] = {32,47,28,79,100,50,22,83,64,11};
        int P3;
        if ( E2 >= 0 && E2 <= 9 ) P3 = cd3[E2];
        else if ( E2 >= 10 && E2 <= 99){
            P3 = cd3[(E2 % 10 + E2 / 10) % 10];
        }
        if ( P1 == 100 && P2 == 100 && P3 == 100) EXP1 = EXP1 * 0.75 + 0.9999999;
        else {
            double P4;
            P4 = (double( P1 + P2 + P3)) / 3;
            if ( P4 < 50) {
                HP1 = HP1 * 0.85 + 0.9999999;
                EXP1 = EXP1 * 1.15 + 0.9999999;
            }
            else {
                HP1 = HP1 * 0.9 + 0.9999999;
                EXP1 = EXP1 * 1.2 + 0.9999999;
            }
        }
        if ( EXP1 > 600) EXP1 = 600;
        if ( EXP1 < 0) EXP1 = 0;
        if ( HP1 > 666 ) HP1 = 666;
        if ( HP1 < 0 ) HP1 = 0;
        if ( M1 > 3000) M1 = 3000;
        if ( M1 < 0) M1 = 0;
        return HP1 + EXP1 + M1; 
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ( E3 < 0 || E3 > 99) return -99;
    else {
        if ( HP1 > 666 ) HP1 = 666;
        if ( HP1 < 0 ) HP1 = 0;
        if ( HP2 > 666 ) HP2 = 666;
        if ( HP2 < 0 ) HP2 = 0;
        if ( EXP1 > 600) EXP1 = 600;
        if ( EXP1 < 0) EXP1 = 0;
        if ( EXP2 > 600) EXP2 = 600;
        if ( EXP2 < 0) EXP2 = 0;
        int a[10][10];
        int soam = 0 , soduong = 0 ;
        for ( int i = 0 ; i <= 9 ; i++){
            for ( int j = 0 ; j <= 9 ; j++){
                 a[i][j] = 0;
            }
        }
        for ( int i = 0 ; i <= 9 ; i++){
            for ( int j = 0 ; j <= 9 ; j++){
                a[i][j] = (( E3 * j ) + ( i * 2)) * ( i - j);
                if ( a[i][j] > E3 * 2) soduong++;
                if ( a[i][j] < (0 - E3)) soam++;
            }
        }
        while ( soam >= 10 || soduong >= 10 ){
            soam = soam % 10 + soam / 10;
            soduong = soduong % 10 + soduong / 10;
        }
        int max = -9999999 , k = 0 ;
        while ( k <= 9){
                // duong cheo trai
                if ( soduong + k <= 9 && soam + k <= 9){
                    if ( max <= a[soduong+k][soam+k]) max = a[soduong+k][soam+k];
                }
                if ( soduong - k >= 0 && soam - k >= 0){
                    if ( max <= a[soduong-k][soam-k]) max = a[soduong-k][soam-k];
                }
                // duong cheo phai
                if ( soduong + k <= 9 && soam - k >= 0){
                    if ( max <= a[soduong+k][soam-k]) max = a[soduong+k][soam-k];
                }
                if ( soduong - k >= 0 && soam + k <= 9){
                    if ( max <= a[soduong-k][soam+k]) max = a[soduong-k][soam+k];
                }
                k++;
        }
        if ( abs(a[soduong][soam]) > abs(max)) {
            EXP1 = (EXP1 * 0.88 + 0.9999999);
            EXP2 = (EXP2 * 0.88 + 0.9999999);
            HP1 = (HP1 * 0.9 + 0.9999999);
            HP2 = (HP2 * 0.9 + 0.9999999);
        }
        else {
            EXP1 = (EXP1 * 1.12 + 0.9999999);
            EXP2 = (EXP2 * 1.12 + 0.9999999);
            HP1 = (HP1 * 1.1 + 0.9999999);
            HP2 = (HP2 * 1.1 + 0.9999999);
        }
        if ( HP1 > 666 ) HP1 = 666;
        if ( HP1 < 0 ) HP1 = 0;
        if ( HP2 > 666 ) HP2 = 666;
        if ( HP2 < 0 ) HP2 = 0;
        if ( EXP1 > 600) EXP1 = 600;
        if ( EXP1 < 0) EXP1 = 0;
        if ( EXP2 > 600) EXP2 = 600;
        if ( EXP2 < 0) EXP2 = 0;
        if ( abs(a[soduong][soam]) > abs(max)) {
            return a[soduong][soam] ;
            //return soduong + soam;
        }
        else return max;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // Lấy chuỗi se từ email
    int seLength = 0;
    while (email[seLength] != '@' ) {
        seLength++;
    }
    char se[seLength + 1];
    strncpy(se, email, seLength);
    se[seLength] = '\0';

    // Kiểm tra độ dài của mật khẩu
    int sLength = 0;
    while (s[sLength] != '\0') {
        sLength++;
    }
    if (sLength < 8) {
        return -1; // Mật khẩu ngắn hơn độ dài tối thiểu
    }
    if (sLength > 20) {
        return -2; // Mật khẩu dài hơn độ dài tối đa
    }
    // kiểm tra ký tự khác
    bool diffchar = false;
    for ( int i = 0 ; i < sLength ; i++){
        char ch = s[i];
        if ( ( ch >= '0' && ch <= '9' ) || ( ch >= 97 && ch <= 122 ) || ( ch >= 65 && ch <= 90 ) || ch == '@' || ch == '#' || ch == '%' || ch == '$' || ch == '!' ){
            diffchar = false;
        }
        else {
            diffchar = true;
            return i;
            break;
        }
    }
    // Kiểm tra chuỗi se
    for (int i = 0; i <= sLength - seLength; ++i) {
        if (strncmp(s + i, se, seLength) == 0) {
            return -(300 + i); // Mật khẩu chứa chuỗi se
        }
    }

    // Kiểm tra nhiều hơn 2 ký tự liên tiếp
    for (int i = 0; i < sLength - 2; ++i) {
        if (s[i] == s[i + 1] && s[i+1] == s[i+2] ) {
            return -(400 + i); // Mật khẩu chứa nhiều hơn 2 ký tự liên tiếp
        }
    }
    // Kiểm tra ký tự đặc biệt
    bool SpecialChar = false;
    for (int i = 0; i < sLength; ++i) {
        char ch = s[i];
        if (ch == '@' || ch == '#' || ch == '%' || ch == '$' || ch == '!') {
            SpecialChar = true;
        }
    }
    if (!SpecialChar) {
        return -5; 
    }
    
    return -10; 
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int arr_solan[num_pwds + 1];
    // dem so lan xuat hien
    for ( int i = 0 ; i < num_pwds  ; i++){
        arr_solan[i] = 1;
        int n = 1;
        for ( int j = i + 1 ; j < num_pwds ; j++){
            if ( strcmp(arr_pwds[i], arr_pwds[j]) == 0 ) n++;
        }
        arr_solan[i] = n;
    }
    // tìm số lần xuất hiện nhiều nhất
    int max = 0 ;
    for ( int i = 0 ; i < num_pwds ; i++){
        if ( max < arr_solan[i]) max = arr_solan[i]; 
    }
    // tao mang gom nhung chuoi co so lan xuat hien = max
    int max_kitu = 0, vitri = 0;
    for ( int i = 0 ; i < num_pwds ; i++){
        int j = 0;
        if ( arr_solan[i] == max) {
            while ( arr_pwds[i][j] != '\0'){
                j++;
            }
            if ( j > max_kitu ) {max_kitu = j; vitri = i; }
        }
    }
    return vitri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////