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
void lim_exp(int &EXP) {
    if (EXP > 600) EXP = 600;
    if (EXP < 0) EXP = 0;
}
void lim_hp(int &HP) {
    if (HP > 666) HP = 666;
    if (HP < 0) HP = 0;
}
void lim_money(int &M) {
    if (M > 3000) M = 3000;
    if (M < 0) M = 0;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) { return -99; }
    //TH1
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) exp2 += 29;
        if (e1 == 1) exp2 += 45;
        if (e1 == 2) exp2 += 75;
        if (e1 == 3) exp2 += 149;      
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = ceil(double(exp1 + (D / 200.0)));
        else exp1 = ceil(double(exp1 - (D / 100.0)));
        lim_exp(exp1);
        lim_exp(exp2);
    }
    //TH2
    if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) exp2 = ceil(double(exp2 + (e1 / 4.0 + 19)));
        if (e1 >= 20 && e1 <= 49) exp2 = ceil(double(exp2 + (e1 / 9.0 + 21)));
        if (e1 >= 50 && e1 <= 65) exp2 = ceil(double(exp2 + (e1 / 16.0 + 17)));
        if (e1 >= 66 && e1 <= 79) {
            exp2 = ceil(double(exp2 + (e1 / 4.0 + 19)));
            if (exp2 > 200) exp2 = ceil(double(exp2 + (e1 / 9.0 + 21)));
        }
        if (e1 >= 80 && e1 <= 99) {
            exp2 = ceil(double(exp2 + (e1 / 4.0 + 19)));
            exp2 = ceil(double(exp2 + (e1 / 9.0 + 21)));
            if (exp2 > 400) {
                exp2 = ceil(double(exp2 + (e1 / 16.0 + 17)));
                exp2 = ceil(double(exp2 * 1.15));
            }
        }
        exp1 -= e1;
        lim_exp(exp1);
        lim_exp(exp2);
    }
    return exp1 + exp2;
}

// Task 2
//CD1
double XS_P1(int EXP1) {
    int S = (int(sqrt(EXP1) + 0.5)) * (int(sqrt(EXP1) + 0.5)); //so chinh phuong gan exp1 nhat
    double P1;
    if (EXP1 >= S) P1 = 1;
    else P1 = (EXP1 / S + 80) / 123.0;
    return P1;
}
//CD2
void CD2_SK1(int& HP1, int& M1) {
    if (HP1 < 200) {
        HP1 = ceil(double(HP1 * 1.13));
        M1 -= 150;
    }
    else {
        HP1 = ceil(double(HP1 * 1.1)); 
        M1 -= 70; 
    }
    lim_hp(HP1); lim_money(M1);
}
void CD2_SK2(int& EXP1, int& M1) {
    if (EXP1 < 400) M1 -= 200;
    else M1 -= 120;
    EXP1 = ceil(double(EXP1 * 1.13));
    lim_exp(EXP1); lim_money(M1);
}
void CD2_SK3(int& EXP1, int& M1) {
    if (EXP1 < 300) M1 -= 100;
    else M1 -= 120;
    EXP1 = ceil(double(EXP1 * 0.9));
    lim_exp(EXP1); lim_money(M1);
}
//sau 3 su kien tren CD2
void CD2(int& HP1, int& EXP1, int& M1, int E2) {
    int M = M1;
    if (E2 % 2) //E2 la so le
    {
        if (M1 != 0) {
            while (1)
            {
                CD2_SK1(HP1, M1);
                if (2 * M1 < M) break;
                CD2_SK2(EXP1, M1);
                if (2 * M1 < M) break;
                CD2_SK3(EXP1, M1);
                if (2 * M1 < M) break;
            }
        }
    }
    else {
        if (M1 != 0) {
            CD2_SK1(HP1, M1);
            if (M1 != 0) {
                CD2_SK2(EXP1, M1);
                if (M1 != 0) { 
                    CD2_SK3(EXP1, M1);
                }
            }
        }
    }
    HP1 = ceil(double(HP1 * 0.83));
    EXP1 = ceil(double(EXP1 * 1.17));
    lim_exp(EXP1);
}
//CD3
double XS_P3(int E2) {
    double P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 }, P3;
    if (E2 >= 10) { 
        E2 = (E2 - E2 % 10) / 10 + E2 % 10; //tong 2 chu so
        E2 = E2 % 10; //chu so hang don vi cua tong
    }
    P3 = P[E2];
    return P3;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;
    double P, P1, P2, P3;
    P1 = XS_P1(EXP1);
    CD2(HP1, EXP1, M1, E2);
    P2 = XS_P1(EXP1);
    P3 = XS_P3(E2) / 100; //so trong mang tren chua bao gom '%'
    P = (P1 + P2 + P3) / 3;
    if (P == 1)  EXP1 = ceil(double(EXP1 * 0.75));
    else if (P < 0.5) {
        EXP1 = ceil(double(EXP1 * 1.15));
        lim_exp(EXP1);
        HP1 = ceil(double(HP1 * 0.85));
    }
    else if (P >= 0.5) {
        EXP1 = ceil(double(EXP1 * 1.2));
        lim_exp(EXP1);
        HP1 = ceil(double(HP1 * 0.9));
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) { return -99; }
    int mang[10][10] = {};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            mang[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int a = 0, b = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (mang[i][j] > E3 * 2) a++;
            if (mang[i][j] < -E3) b++;
        }
    }
    while (a >= 10) {
        a = a / 10 + a % 10;
    }
    while (b >= 10) {
        b = b / 10 + b % 10;
    }
    int max;
    for (int i = 0; i < 10; i++) {
        if ((a + i) < 10 && (b + i) < 10) {
            if (mang[a + i][b + i] > max) max = mang[a + i][b + i];
        }
        if ((a - i) >= 0 && (b - i) >= 0) {
            if (mang[a - i][b - i] > max) max = mang[a - i][b - i];
        }
        if ((a + i) <= 9 && (b - i) >= 0) {
            if (mang[a + i][b - i] > max) max = mang[a + i][b - i];
        }
        if ((a - i) >= 0 && (b + i) <= 9) {
            if (mang[a - i][b + i] > max) max = mang[a - i][b + i];
        }
    }
    if (max < 0) max = abs(max);
    if (abs(mang[a][b]) > max) {
        EXP1 = ceil(double(EXP1 * 0.88));
        EXP2 = ceil(double(EXP2 * 0.88));
        HP1 = ceil(double(HP1 * 0.9));
        HP2 = ceil(double(HP2 * 0.9));
    return mang[a][b];
    }
    else {
        EXP1 = ceil(EXP1 * 1.12);
        EXP2 = ceil(EXP2 * 1.12);
        HP1 = ceil(HP1 * 1.1);
        HP2 = ceil(HP2 * 1.1);
        return max;
    }
    lim_exp(EXP1);
    lim_exp(EXP2);
    lim_hp(HP1);
    lim_hp(HP2);
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    const char* vitri = strchr(email, '@'); //vi tri cua @ trong email    
    int seLength = vitri - email; //so ki tu tu dau chuoi email cho den @
    char se[100]; 
    memset(se, '\0', sizeof(se));

    strncpy(se, email, seLength);
     
    if (strlen(s) < 8) {
        return -1; 
    }
    if (strlen(s) > 20) {
        return -2; 
    }
    const char* sePos = strstr(s, se);
    if (sePos) {
        return -(300 + (sePos - s)); //chua chuoi se
    }
    for (int i = 1; i < strlen(s); i++) {
        if (s[i] == s[i - 1]) {
            return -(400 + i); //nhieu hon 2 ki tu lien tiep giong nhau
        }
    }
    for (int j = 0; j < strlen(s); j++) {
        char c = s[j];
       
            if (c != '@' && c != '#' && c != '%' && c != '$' && c != '!')
                return -5; //khong chua ki tu dac biet
        
    }
    return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int password_count[30] = { 0 };//so luong mat khau khong qua 30
    //duyet qua pwds trong mang va dem so lan xuat hien cua pwds
    for (int i = 0; i < num_pwds; ++i) {
        string password = arr_pwds[i];
        password_count[i] = 1; //danh dau mat khau xuat hien 1 lan

        //kiem tra lai cac mat khau truoc
        for (int j = 0; j < i; ++j) {
            if (password == arr_pwds[j]) {
                    password_count[i]++; //tang so lan xuat hien mat khau
            }
        }
    }
    //mat khau xuat hien nhieu nhat
    string most_app_pwds;
    int max_count = 0;
    for (int i = 0; i < num_pwds; ++i) {
        if (password_count[i] > max_count) {
            max_count = password_count[i];
            most_app_pwds = arr_pwds[i];
        }
    }
    //mat khau dai nhat
    int first_occurrence; //vi tri xuat hien dau tien
    int max_length = 0;
    for (int i = 0; i < num_pwds; ++i) {
        if (arr_pwds[i] == most_app_pwds) {
            if ((int)(most_app_pwds.length()) > max_length) {
                max_length = (int)most_app_pwds.length();
                first_occurrence = i;
            }
        }
    }     
    return first_occurrence;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////