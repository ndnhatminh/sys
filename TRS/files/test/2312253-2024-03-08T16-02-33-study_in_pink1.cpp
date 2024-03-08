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
int checkHP (int HP) {
    if (HP > 666) {
        return 666;
    }
    else if (HP < 0) {
        return 0;
    }
    else {
        return HP;
    }
}
int checkEXP (int EXP) {
    if (EXP > 600) {
        return 600;
    }
    else if (EXP < 0) {
        return 0;
    }
    else {
        return EXP;
    }
}
int checkM (int M) {
    if (M > 3000) {
        return 3000;
    }
    else if (M < 0) {
        return 0;
    }
    else {
        return M;
    }
}
int roundVal (double Val) {
    int roundVal = int(Val);
	if (Val - roundVal > 0) {
		return roundVal + 1;
	} else {
		return roundVal;
	}
}
bool checkE (int E) {
    if (E < 0 || E > 99) {
        return true;
    }
    else {
        return false;
    }
}
bool EFromTo (int E, int From, int To) {
    if (E >= From && E <= To) {
        return true;
    }
    else {
        return false;
    }
}
int roundPlus (int Val, int x) {
    Val += Val*x/100 + (Val*x%100 != 0);
    return Val;
}
int roundMinus (int Val, int x) {
    Val -= floor (Val*x/100);
    return Val;
}


// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    EXP1 = checkEXP (EXP1);
    EXP2 = checkEXP (EXP2);
    if (checkE (E1)) {
        return -99;
    }
    else {
        if (EFromTo (E1, 0, 3)) {
            if (E1 == 0) {
                EXP2 += 29;
            }
            else if (E1 == 1) {
                EXP2 += 45;
            }
            else if (E1 == 2) {
                EXP2 += 75;
            }
            else {
                EXP2 += 149;
            }
            EXP2 = checkEXP (EXP2);
            int D = E1*3 + EXP1*7;
            if (D % 2 == 0) {
                EXP1 = roundVal (EXP1 + double(D)/200);
            }
            else {
                EXP1 = roundVal (EXP1 - double(D)/100);
            }
            EXP1 = checkEXP (EXP1);
        }
        else if (EFromTo (E1, 4, 99)) {
            if (EFromTo (E1, 4, 19)) {
                EXP2 = roundVal (EXP2 + double(E1)/4 + 19);
                EXP2 = checkEXP (EXP2);
            }
            else if (EFromTo (E1, 20, 49)) {
                EXP2 = roundVal (EXP2 + double(E1)/9 + 21);
                EXP2 = checkEXP (EXP2);
            }
            else if (EFromTo (E1, 50, 65)) {
                EXP2 = roundVal (EXP2 + double(E1)/16 + 17);
                EXP2 = checkEXP (EXP2);
            }
            else if (EFromTo (E1, 66, 79)) {
                EXP2 = roundVal (EXP2 + double(E1)/4 + 19);
                EXP2 = checkEXP (EXP2);
                if (EXP2 > 200) {
                    EXP2 = roundVal (EXP2 + double(E1)/9 + 21);
                    EXP2 = checkEXP (EXP2);
                }
            }
            else if (EFromTo (E1, 80, 99)) {
                EXP2 = roundVal (EXP2 + double(E1)/4 + 19);
                EXP2 = roundVal (EXP2 + double(E1)/9 + 21);
                EXP2 = checkEXP (EXP2);
                if (EXP2 > 400) {
                    EXP2 = roundVal (EXP2 + double(E1)/16 + 17);
                    EXP2 = checkEXP (EXP2);
                    EXP2 = roundPlus (EXP2, 15);
                    EXP2 = checkEXP (EXP2);
                }
            }
            EXP1 -= E1;
            EXP1 = checkEXP (EXP1);
        }
    }
    return EXP1 + EXP2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (checkE (E2)){
        return -99;
    }

    // PATH 1
    else {
    EXP1 = checkEXP (EXP1);
    double P1;
    int S;
    double s = sqrt(double(EXP1));
    int s1 = floor(s);
    int s2 = int(s+0.999);
    int S1 = s1*s1;
    int S2 = s2*s2;
    if (EXP1 - S1 < S2 - EXP1) {
    S = S1;
    }
    else {
    S = S2;
    }
    if (EXP1 - S >= 0) {
    P1 = double(1);
    }
    else {
    P1 = (((double(EXP1)/S) + 80)/123);
    }
    
    // PATH 2
    M1 = checkM (M1);
    const int M1_begin = M1;
    HP1 = checkHP (HP1);    
    if (E2%2 == 1) {
    //    if (M1_begin != 0) {
        while (double(M1) / M1_begin >= (double(1)/2)) {
    if (HP1 < 200) {
        HP1 = roundPlus (HP1, 30);
        HP1 = checkHP (HP1);
        M1 -= 150;
        M1 = checkM (M1);
    }
    else {
        HP1 = roundPlus (HP1, 10);       
        M1 -= 70;
        HP1 = checkHP (HP1);
        M1 = checkM (M1);
    }
    if (double(M1) / M1_begin >= (double(1)/2)) {
    if (EXP1 < 400) {
        M1 -= 200;
        EXP1 = roundPlus (EXP1, 13);
        M1 = checkM (M1);
        EXP1 = checkEXP (EXP1);
    }
    else {
        M1 -= 120;
        EXP1 = roundPlus (EXP1, 13);
        M1 = checkM (M1);
        EXP1 = checkEXP (EXP1);
    }
    }
    else {
        break;
    }
    if (double(M1) / M1_begin >= (double(1)/2)) {
    if (EXP1 < 300) {
        M1 -= 100;
        EXP1 = roundMinus (EXP1, 10);
        M1 = checkM (M1);
        EXP1 = checkEXP (EXP1);
    }
    else {
        M1 -= 120;
        EXP1 = roundMinus (EXP1, 10);
        M1 = checkM (M1);
        EXP1 = checkEXP (EXP1);
    }
    }
    else {
        break;
    }
        }
        HP1 = roundMinus (HP1, 17);
        HP1 = checkHP (HP1);
        EXP1 = roundPlus (EXP1, 17);
        EXP1 = checkEXP (EXP1);
    }
    else {
        if (M1 != 0) {
    if (HP1 < 200) {
        HP1 = roundPlus (HP1, 30);
        HP1 = checkHP (HP1);
        M1 -= 150;
        M1 = checkM (M1);
    }
    else {
        HP1 = roundPlus (HP1, 10);       
        M1 -= 70;
        HP1 = checkHP (HP1);
        M1 = checkM (M1);
    }
        if (M1 != 0) {
    if (EXP1 < 400) {
        M1 -= 200;
        EXP1 = roundPlus (EXP1, 13);
        M1 = checkM (M1);
        EXP1 = checkEXP (EXP1);
    }
    else {
        M1 -= 120;
        EXP1 = roundPlus (EXP1, 13);
        M1 = checkM (M1);
        EXP1 = checkEXP (EXP1);
    }
    if (M1 != 0) {
    if (EXP1 < 300) {
        M1 -= 100;
        EXP1 = roundMinus (EXP1, 10);
        M1 = checkM (M1);
        EXP1 = checkEXP (EXP1);
    }
    else {
        M1 -= 120;
        EXP1 = roundMinus (EXP1, 10);
        M1 = checkM (M1);
        EXP1 = checkEXP (EXP1);
    }   
    }
    }
    }
    HP1 = roundMinus (HP1, 17);
    HP1 = checkHP (HP1);
    EXP1 = roundPlus (EXP1, 17);
    EXP1 = checkEXP (EXP1); 
    }
    double P2;
    int R;
    double r = sqrt(double(EXP1));
    int r1 = floor(r);
    int r2 = int(r+0.999);
    int R1 = r1*r1;
    int R2 = r2*r2;
    if (EXP1 - R1 < R2 - EXP1) {
    R = R1;
    }
    else {
    R = R2;
    }
    if (EXP1 - R >= 0) {
    P2 = double(1);
    }
    else {
    P2 = (((double(EXP1)/R) + 80)/123);
    }
    // PATH 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (EFromTo (E2, 0, 9)) {
        i = E2;
    }
    else if (EFromTo (E2, 10, 99)) {
        E2 = E2/10 + E2%10;
        i = E2%10;
    }
    double P3 = double(P[i])/100;

    // Tinh P
    double P_ave = (P1 + P2 + P3)/3;
    if (P_ave == double(1)) {
        EXP1 = roundMinus (EXP1, 25);
        EXP1 = checkEXP (EXP1);
    }
    else {
        if (P_ave < double(1)/2) {
            HP1 = roundMinus (HP1, 15);
            EXP1 = roundPlus (EXP1, 15);
            HP1 = checkHP (HP1);
            EXP1 = checkEXP (EXP1);
        }
        else {
            HP1 = roundMinus (HP1, 10);
            EXP1 = roundPlus (EXP1, 20);
            HP1 = checkHP (HP1);
            EXP1 = checkEXP (EXP1);
        }
    }
    return HP1 + EXP1 + M1;
    }
}



// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    HP1 = checkHP (HP1);
    HP2 = checkHP (HP2);
    EXP1 = checkEXP (EXP1);
    EXP2 = checkEXP (EXP2);
    if (checkE (E3)) {
        return -99;
    }
    else {
       // MA TRAN CHUA DIEM TAXI
       int taxi[10][10];
       for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // TINH DIA DIEM GAP NHAU
    int row = 0, column = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (taxi[i][j] > (E3 * 2)) {
                ++row;
            }
            else if (taxi[i][j] < (0 - E3)) {
                ++column;
            }
        }
    }
    while (row >= 10) {
        row = row/10 + row%10;
    }
    while (column >= 10) {
        column = column/10 + column%10;
    }

    // TINH MAX CAC DUONG CHEO TAI DIEM GAP
    const int a = row; 
    const int b = column;
    
    int max[4] = {0, 0, 0, 0};
    while (row <= 9 && column <= 9) {
        if (taxi[row][column] > max[0]) {
            max[0] = taxi[row][column];
        }
        ++row;
        ++column;
    }
    row = a;
    column = b;
    while (row <= 9 && column >= 0) {
        if (taxi[row][column] > max[1]) {
            max[1] = taxi[row][column];
        }
        ++row;
        --column;
    }
    row = a;
    column = b;
    while (row >= 0 && column <= 9) {
        if (taxi[row][column] > max[2]){
            max[2] = taxi[row][column];
        }
        --row;
        ++column;
    }
    row = a;
    column = b;
    
    while (row >= 0 && column >= 0){
        if (taxi[row][column] > max[3]){
            max[3] = taxi[row][column];
        }
        --row;
        --column;
    }

    // TINH DIEM SHERLOCK
    int s;
    s = max[0];
    for (int i = 1; i < 4 ; i++) {
        if (max[i] > s) {
            s = max[i];
        }
    }
    
    // SO SANH DIEM SO CUA SHERLOCK VA TAXI
    if (abs (taxi[row][column]) > s) {
        EXP1 = roundMinus (EXP1, 12);
        EXP2 = roundMinus (EXP2, 12);
        HP1 = roundMinus (HP1, 10);
        HP2 = roundMinus (HP2, 10);
        EXP1 = checkEXP (EXP1);
        EXP2 = checkEXP (EXP2);
        HP1 = checkHP (HP1);
        HP2 = checkHP (HP2);
        return taxi[row][column];
    }
    else {
        EXP1 = roundPlus (EXP1, 12);
        EXP2 = roundPlus (EXP2, 12);
        HP1 = roundPlus (HP1, 10);
        HP2 = roundPlus (HP2, 10);
        EXP1 = checkEXP (EXP1);
        EXP2 = checkEXP (EXP2);
        HP1 = checkHP (HP1);
        HP2 = checkHP (HP2);
        return s;
    }
    }
}



// KIEM TRA SPECIAL CHAR?
bool special_char (char a) {
    if (a == '@') return true;
    if (a == '#') return true;
    if (a == '%') return true;
    if (a == '$') return true;
    if (a == '!') return true;
    return false;
}
// KIEM TRA VALID CHAR?
bool valid_char (char a) {
    if (special_char (a)) return true;
    if (int(a) >= 48 && int(a) <= 57) return true;
    if (int(a) >= 65 && int(a) <= 90) return true;
    if (int(a) >= 97 && int(a) <= 122) return true;
    return false;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string e (email);
    string S (s);
    string se;
    for (int i = 0; e[i] != '@'; i++) {
        se = se + e[i];
    }
    // CASE 2: < min
    if (S.length() < 8) return -1;
    // CASE 3: > max
    if (S.length() > 20) return -2; 
    int S_len = S.length();
    int se_len = se.length();
    // CASE 4: chua se
    for (int i = 0; i < S_len - se_len + 1; i++) {
        if (S[i] == se[0]){
            bool check = true;
            for (int j = 0; j < se_len; j++){
                if (S[i + j] != se[j]) {
                    check = false;
                    break;
                }
            }
            if (check == true) {
                
                return -(300 + i);
            }
        }
    }
    //CASE 5: > 2 char giong nhau lien tiep
    for (int i = 2; i < S.length(); i++) {
        if (S[i - 2] == S[i - 1] && S[i - 1] == S[i]) return -(400 + i - 2);
    }
    // CASE 6: ton tai special char?
    bool exist = false;
    for (int i = 0; i < S.length(); i++) {
        if (special_char (S[i])) {
            exist = true;
            break;
        }
    }
    if (exist == false) return -5;
    // CASE 7: others
    for (int i = 0; i < S.length(); i++) {
        if (valid_char (S[i]) == false) return i;
    }
    // CASE 1: VALID
    return -10;
}



// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    const char* correct_pw = nullptr;
    int max_cnt = 0, max_len = 0;

    // GAN MAT KHAU
    for (int i = 0; i < num_pwds; i++) {
        const char* pw = arr_pwds[i];
        int cnt = 0;
        int len = 0;

        // CALCULATE CNT & LEN
        for (int j = 0; pw[j] != '\0'; j++) {
            ++len;
        }

        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(pw, arr_pwds[j]) == 0) {
                ++cnt;
            }
        }

        // RETURN CORRECT PW
        if (cnt > max_cnt || (cnt == max_cnt && len > max_len)) {
            max_cnt = cnt;
            max_len = len;
            correct_pw = pw;
        }
    }

    // RETURN 1ST PLACE
    for (int i = 0; i < num_pwds; i++) {
        if (arr_pwds[i] == correct_pw) {
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////