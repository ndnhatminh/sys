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
//CAC HAM CHECK
int check_hp(int& hp) {
    if (hp > 666) hp = 666;
    else if (hp < 0) hp = 0;
    return hp;
}
int check_exp(int& exp) {
    if (exp > 600) exp = 600;
    else if (exp < 0) exp = 0;
    return exp;
}
int check_m(int& m) {
    if (m > 3000) m = 3000;
    else if (m < 0) m = 0;
    return m;
}
int check_e(int &e) {
    if ((e < 0) || (e > 99)) e = -99;
    return e;
}
// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    int D;
    e1 = check_e(e1);
    if (e1 <= 3) {
        switch (e1) {
        case 0: exp2 += 29; break;
        case 1: exp2 += 45; break;
        case 2: exp2 += 75; break;
        case 3: exp2 = exp2 + 29 + 45 + 75; break;
        }
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = ceil(exp1 + (float(D) / 200));
        else exp1 = ceil(exp1 - D / 100.0);
        exp1 = check_exp(exp1);
    }
    if ((e1 >= 4) && (e1 <= 19)) { exp2 = ceil(exp2 + ((e1 / 4.0) + 19)); exp1 = exp1 - e1; }
    else if ((e1 >= 20) && (e1 <= 49)) { exp2 = ceil(exp2 + ((e1 / 9.0) + 21)); exp1 = exp1 - e1; }
    else if ((e1 >= 50) && (e1 <= 65)) { exp2 = ceil(exp2 + ((e1 / 16.0) + 17)); exp1 = exp1 - e1; }
     else if ((e1 >= 66) && (e1 <= 79)) {
        exp2 = ceil(exp2 + ((e1 / 4.0) + 19));
        exp2=check_e(exp2);
        if (exp2 > 200) exp2 = exp2 + ceil(e1 / 9.0 + 21);
        exp2 = check_exp(exp2);
        exp1 = exp1 - e1;
    }
    else if ((e1 >= 80) && (e1 <= 99)) {
        exp2 = exp2 + ceil(e1 / 4.0 + 19);
        exp2 = exp2 + ceil(e1 / 9.0 + 21);
        check_exp(exp2);
        if (exp2 > 400) {
            exp2 = exp2 + ceil(e1 / 16.0 + 17);
            exp2 = exp2 + ceil(exp2 * 0.15);
            exp2 = check_exp(exp2);
        }
        exp1 = exp1 - e1;
    }
    
    return exp1 + exp2;


}



// Task 2
bool SCP(int n) {
    int sqrt_n = sqrt(n);
    return sqrt_n * sqrt_n == n;
}
int nearSCP(int n) {
    int itself = n;
    int smaller = n - 1;
    int larger = n + 1;

    while (true) {
        if (SCP(itself)) {
            return itself;
        }
        else if (SCP(smaller)) {
            return smaller;
        }

        else if (SCP(larger)) {
            return larger;
        }
        smaller--;
        larger++;
    }
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    int S = nearSCP(EXP1);
    float P1, P2, P3;
    if (EXP1 >= S) P1 = 1.0;
    else P1 = (float(EXP1) / S + 80) / 123.0;
    float O = M1 * 0.5;
    
    while (M1>0) {
        if (HP1 < 200) {
            HP1 = ceil(HP1 * 1.3); M1-= 150; check_hp(HP1);
            check_m(M1);
            
        }
        else {
            HP1 = ceil(HP1 * 1.1);  M1 -= 70; 
            check_hp(HP1);
            check_m(M1);
            
        }
        if (M1 < O) break;
        if (EXP1 < 400) {
            M1-= 200;
            
            EXP1 = ceil(EXP1 * 1.13);
            check_m(M1);
            
        }
        else {
            M1-= 120;
            
            EXP1 = ceil(EXP1 * 1.13);
            check_m(M1);
           
        }
        if (M1 < O) break;
        
        if (EXP1 < 300) {
            M1-= 100;
            check_m(M1);
           
            
        }
        else
        {
            M1-= 120;
            EXP1 = ceil(EXP1 * 0.9);
            check_exp(EXP1);
            check_m(M1);
            
           
        }
        if (E2 % 2 == 0) {
            break;
        }
        }
    HP1 = ceil(HP1 * 0.83);
    EXP1 = ceil(EXP1 * 1.17);
    check_exp(EXP1);
    check_hp(HP1);
    check_m(M1);

   
  
    
    P2 = (float(EXP1) / S + 80) / 123;
    int B[]{ 32,47,28,79,100,50,22,83,64,11 };
    if (E2 < 10) P3 = B[E2] / 100.0;
    else {
        int C = E2 / 10 + E2 % 10;
        if (C >= 10) C = C % 10;
        P3 = B[C] / 100.0;
    }
    if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0) {
        EXP1 = ceil(EXP1 * 0.75);
        check_exp(EXP1);
    }
    else {
        float F = (P1 + P2 + P3) / 3;
        if (F < 0.5) {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
            check_exp(EXP1);
            check_hp(HP1);
        }

        else {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
            check_exp(EXP1);
            check_hp(HP1);
        }
    }


        return HP1 + EXP1 + M1;
    }

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    int A[10][10]{};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            A[i][j] = ((E3 * j) + (i * 2)) * (i - j);
    }
    int dem1 = 0, dem2 = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (A[i][j] > (E3 * 2)) dem1 = dem1 + 1;
            if (A[i][j] < (-E3)) dem2 = dem2 + 1;
        }
    }
    int x = dem1 / 10 + dem1 % 10;
    int y = dem2 / 10 + dem2 % 10;
    if (x >= 10) x = x / 10 + x % 10;
    if (y >= 10) y = y / 10 + y % 10;
    int maxvalue = 0;
    for (int i = 0; i < 10; i++) {
        int j = y - x + i;
        if (j >= 0 && j < 10) {
            if (A[i][j] > maxvalue) maxvalue = A[i][j];
        }
    }
    for (int i = 0; i < 10; i++) {
        int j = y + x - i;
        if (j >= 0 && j < 10) {
            if (A[i][j] > maxvalue) maxvalue = A[i][j];
        }
    }
    int gttask3;
    if (abs(A[x][y]) > maxvalue) {
        EXP1 = ceil(0.88 * EXP1);
        EXP2 = ceil(0.88 * EXP2);
        HP1 = ceil(HP1 * 0.9);
        HP2 = ceil(HP2 * 0.9);
        check_exp(EXP1);
        check_exp(EXP2);
        check_hp(HP1);
        check_hp(HP2);
        gttask3 = A[x][y];
    }
    if (abs(A[x][y]) < maxvalue) {
        EXP1 = ceil(1.12 * EXP1);
        EXP2 = ceil(1.12 * EXP2);
        HP1 = ceil(HP1 * 1.1);
        HP2 = ceil(HP2 * 1.1);
        check_exp(EXP1);
        check_exp(EXP2);
        check_hp(HP1);
        check_hp(HP2);
        gttask3 = maxvalue;
    }


    return gttask3;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    if (string(s).length() < 8) return -1;
    if (string(s).length() > 20) return -2;
    size_t ktdb = string(email).find('@');
    string se = string(email).substr(0, ktdb);
    size_t found_se = string(s).find(se);
    if (found_se != string::npos) return -(300 + found_se);
    for (size_t i = 0; i < string(s).length() - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }
    bool ktktdb = false;
    for (char c : string(s)) {
        if (!isalnum(c) && c != '@' && c != '#' && c != '%' && c != '$' && c != '!') {
            ktktdb = true;
            break;
        }
    }
    if (ktktdb = true) return -5;
    return 10;

}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int max_length = 0;
    int max_count = 0;
    std::string correct_pwd;
    for (int i = 0; i < num_pwds; ++i) {
        std::string pwd = arr_pwds[i];
        int length = pwd.length();
        int count = 1;

        for (int j = i + 1; j < num_pwds; ++j) {
            if (arr_pwds[j] == pwd)
                ++count;
        }

        if (count > max_count || (count == max_count && length > max_length)) {
            max_count = count;
            max_length = length;
            correct_pwd = pwd;
        }
    }

    for (int i = 0; i < num_pwds; ++i) {
        if (arr_pwds[i] == correct_pwd)
            return i;
    }

    return -1;  //Neu k tim thay mk dung
}




////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
///////////////////////////////////////////////