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
void limitHp(int& HP) {
    if (HP > 666) {
        HP = 666;
    }
    else if (HP < 0) {
        HP = 0;
    }
}

void limitExp(int& EXP) {
    if (EXP > 600) {
        EXP = 600;
    }
    else if (EXP < 0) {
        EXP = 0;
    }
}
void limitM(int& M) {
    if (M > 3000) {
        M = 3000;
    }
    else if (M < 0) {
        M = 0;
    }
}


// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    if (e1 >= 0 && e1 <= 99) {
        if (e1 >= 0 && e1 <= 3) {
            switch (e1) {
            case 0:
                exp2 += 29;
                break;
            case 1:
                exp2 += 45;
                break;
            case 2:
                exp2 += 75;
                break;
            case 3:
                exp2 += (29 + 45 + 75);
                break;
            }
            int D = (e1 * 3) + (exp1 * 7);
            if (D % 2 == 0) {
                exp1 += (D / 200);
            }
            else {
                exp1 -= (D / 100);
            }
        }
        if (e1 >= 4 && e1 <= 99) {
            if (e1 >= 4 && e1 <= 19) {
                exp2 += ceil((double)e1 / 4) + 19;
            }
            else if (e1 >= 20 && e1 <= 49) {
                exp2 += ceil((double)e1 / 9) + 21;
            }
            else if (e1 >= 50 && e1 <= 65) {
                exp2 += ceil((double)e1 / 16) + 17;
            }
            else if (e1 >= 66 && e1 <= 79) {
                exp2 += ceil((double)e1 / 4) + 19;
                if (exp2 > 200) {
                    exp2 += ceil((double)e1 / 9) + 21;
                }
            }
            else {
                exp2 += ceil((double)e1 / 4) + 19;
                exp2 += ceil((double)e1 / 9) + 21;
                if (exp2 > 400) {
                    exp2 += ceil((double)e1 / 16) + 17;
                }
                exp2 = exp2 * 1.15;
            }
            exp1 -= e1;
        }
        limitExp(exp1);
        limitExp(exp2);
        
        return exp1 + exp2;
    }
    else {
        return -99;
    }
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if (E2 >= 0 && E2 <= 99) {
        //com duong so 1 
        int S;
        double p1;
        S = (round((sqrt(EXP1)))) * (round((sqrt(EXP1))));
        if (EXP1 >= S) {
            p1 = 1;
        }
        else {
            p1 = ((EXP1 / (double)S) + 80) / 123;
        }

        // con duong so 2
        int remain_m = M1;
        double p2;
        if (E2 % 2 == 1) {
            while (M1 > (remain_m * 0.5)) {
                if (HP1 < 200) {
                    HP1 = ceil(HP1 * 1.3);
                    M1 -= 150;
                }
                else {
                    HP1 = ceil(HP1 * 1.1);
                    M1 -= 70;
                }
                if (M1 < (remain_m * 0.5)) {
                    break;
                }
                if (EXP1 < 400) {
                    M1 -= 200;
                }
                else {
                    M1 -= 120;
                }
                EXP1 = ceil(EXP1 * 1.13);
                if (M1 < (remain_m * 0.5)) {
                    break;
                }
                if (EXP1 < 300) {
                    M1 -= 100;
                }
                else {
                    M1 -= 120;
                }
                EXP1 = ceil(EXP1 * 0.9);
                if (M1 < (remain_m * 0.5)) {
                    break;
                }
            }
            EXP1 = ceil(EXP1 * 1.17);
            HP1 = ceil(HP1 * 0.83);
        }
        else {
            if (M1 > 0) {
                if (HP1 < 200) {
                    HP1 = ceil(HP1 * 1.3);
                    M1 -= 150;
                }
                else {
                    HP1 = ceil(HP1 * 1.1);//110;
                    M1 -= 70;//1130;
                }
            }
            if (M1 > 0) {
                if (EXP1 < 400) {
                    M1 -= 200;
                }
                else {
                    M1 -= 120;//1010
                }
                EXP1 = ceil(EXP1 * 1.13);
                
            }
            if (M1 > 0) {
                if (EXP1 < 300) {
                    M1 -= 100;
                }
                else {
                    M1 -= 120;//890
                }
                EXP1 = ceil(EXP1 * 0.9);
            } 
            EXP1 = ceil(EXP1 * 1.17);
            HP1 = ceil(HP1 * 0.83);
        }
        limitM(M1);
        limitExp(EXP1);
 
        S = (round(sqrt(EXP1))) * (round(sqrt(EXP1)));
        if (EXP1 >= S) {
            p2 = 1;
        }
        else {
            p2 = ((EXP1 / (double)S) + 80) / 123;
        }
        // con duong so 3
        int p[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        double p3;
        int i;
        if (E2 < 10) {
            i = E2;
        }
        else {
            i = ((int)(E2 / 10) + (E2 % 10)) % 10;
        }
        p3 = p[i] / 100;
        // xac suat p
        double P;
        if (p1 == 1 && p2 == 1 && p3 == 1) {
            EXP1 = ceil(EXP1 * 0.75);
        }
        else {
            P = (p1 + p2 + p3) / 3;
            if (P < 0.5) {
                HP1 = ceil(HP1 * 0.85);
                EXP1 = ceil(EXP1 * 1.15);
            }
            else {
                HP1 = ceil(HP1 * 0.9);
                EXP1 = ceil(EXP1 * 1.2);
            }
        }
        limitHp(HP1);
        limitExp(EXP1);
        limitM(M1);
        return HP1 + EXP1 + M1;
    } 
    else {
     return -99;
    }
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 >= 0 && E3 <= 99) {
        
        // khoi tao ma tran diem so cho taxi
        int taxi_map[10][10] = { 0 };
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                taxi_map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        //khoi tao ma tran diem so cho Sherlock va Watson
        int SW_map[10][10] = { 0 };
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                int max1 = 0;
                int max2 = 0;
                for (int k = i, l = j; k < 10 && l < 10; k++, l++) {
                    if (max1 < taxi_map[k][l]) {
                        max1 = taxi_map[k][l];
                    }
                }
                for (int k = i, l = j; k >= 0 && l >= 0 ; k--, l--) {
                    if (max1 < taxi_map[k][l]) {
                        max1 = taxi_map[k][l];
                    }
                }
        
                for (int d = i, f = j; d >= 0 && f < 10; d--, f++) {
                    if (max2 < taxi_map[d][f]) {
                        max2 = taxi_map[d][f];
                    }
                }
                for (int d = i, f = j; d < 10 && f >= 0; d++, f--) {
                    if (max2 < taxi_map[d][f]) {
                        max2 = taxi_map[d][f];
                    }
                }
                SW_map[i][j] = max(max1, max2);
            }
        }
        // tim diem gap nhau
        int i = 0, j = 0;
        int so_duong = 0;
        int so_am = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (taxi_map[i][j] > (E3 * 2)) {
                    so_duong += 1;
                }
                if (taxi_map[i][j] < (-E3)) {
                    so_am += 1;
                }
            }
        }
        if (so_duong < 10) {
            i = so_duong;
        }
        else {
            i = ((int)((int)(so_duong / 10) + (so_duong % 10)) / 10) + (((int)(so_duong / 10) + (so_duong % 10)) % 10);
        }
        if (so_am < 10) {
           j = so_am;
        }
        else {
            j = ((int)((int)(so_am / 10) + (so_am % 10)) / 10) + (((int)(so_am / 10) + (so_am % 10)) % 10);
        }
        int diem_gap;
        if (abs(taxi_map[i][j]) <= SW_map[i][j]) {
            EXP1 = ceil((int)(EXP1 * 1.12));
            EXP2 = ceil((int)(EXP2 * 1.12));
            HP1 = ceil((int)(HP1 * 1.1));
            HP2 = ceil((int)(HP2 * 1.1));
            diem_gap = SW_map[i][j];
        }
        else {
            EXP1 = ceil((int)(EXP1 * 0.88));
            EXP2 = ceil((int)(EXP2 * 0.88));
            HP1 = ceil((int)(HP1 * 0.9));
            HP2 = ceil((int)(HP2 * 0.9));
            diem_gap = taxi_map[i][j];
        }
        limitHp(HP1);
        limitExp(EXP1);
        limitHp(HP2);
        limitExp(EXP2);
        return diem_gap;
    }
    else {
        return -99;
    }
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    string emailStr(email);
    string se = emailStr.substr(0, emailStr.find('@'));

    if (strlen(s) < 8) {
        return -1;
    }
    if (strlen(s) > 20) {
        return -2;
    }
    const char* special = { "@#$%!" };
    const char* sei = strstr(s, se.c_str());
    if (sei != nullptr) {
        return -(300 + (sei - s));
    }
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }
    if (strpbrk(s, special) == nullptr) {
        return -5;
    }
    for (int i = 0; i < strlen(s); ++i) {
        if (!isalnum(s[i]) && !strchr(special, s[i]) && !isalpha(s[i])) {
            return i;
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_count = 0;
    int max_length = 0;
    int result = -1;
    for (int i = 0; i < num_pwds; i++) {
        string pass_w = arr_pwds[i];
        int count_pw = 0;
        int length_pw = pass_w.length();
        for (int j = 0; j < num_pwds; j++) {
            if (pass_w == arr_pwds[j]) {
                count_pw += 1;
            }
        }
        if (max_count < count_pw || (max_count == count_pw && max_length < pass_w.length())) {
            max_count = count_pw;
            max_length = pass_w.length();
            result = i;
        }
    }
    
    return result;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
