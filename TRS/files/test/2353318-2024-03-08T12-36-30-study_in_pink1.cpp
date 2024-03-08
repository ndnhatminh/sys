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
//round up function
void checkHP(int &HP){
     if (HP < 0) HP = 0;
     if (HP > 666) HP = 666;
}
void checkEXP(int &EXP){
    if (EXP < 0) EXP = 0;
    if (EXP > 600) EXP = 600;
}
void checkM (int &M){
    if (M > 3000) M = 3000;
    if (M < 0) M = 0;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    // case 1
    if (e1 < 0 || e1 > 99) return -99;
    checkEXP(exp1);
    checkEXP(exp2);


    if (0 <= e1 && e1 <= 3) {
        if (e1 == 0) exp2 += 29;
        else if (e1 == 1) exp2 += 45;
        else if (e1 == 2)exp2 += 75;
        else exp2 += 149;
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = ceil(-0.0001 +exp1 * 1.0 + D * 1.0 / 200);
        else exp1 = ceil(-0.0001 +-0.0001 +exp1 * 1.0 - D * 1.0 / 100 );
    }


    // case 2
    else if (4 <= e1 && e1 <= 99) {
        if (4 <= e1 && e1 <= 19) exp2 = ceil(-0.0001 +exp2 * 1.0 + e1 * 1.0 / 4 + 19);
        else if (20 <= e1 && e1 <= 49) exp2 = ceil(-0.0001 +exp2 * 1.0 + e1 * 1.0 / 9 + 21);
        else if (50 <= e1 && e1 <= 65) exp2 = ceil(-0.0001 +exp2 * 1.0 + e1 * 1.0 / 16 + 17);
        else if (66 <= e1 && e1 <= 79) {
            exp2 = ceil(-0.0001 +exp2 * 1.0 + e1 * 1.0 / 4 + 19);
            if (exp2 > 200) exp2 = ceil(-0.0001 +exp2 * 1.0 + e1 * 1.0 / 9 + 21);
        }
        else if (80 <= e1 && e1 <= 99) {
            exp2 = ceil(-0.0001 +exp2 * 1.0 + e1 * 1.0 / 4 + 19);  checkEXP(exp2);
            exp2 = ceil(-0.0001 +exp2 * 1.0 + e1 * 1.0 / 9 + 21);
            if (exp2 > 400) {
                exp2 = ceil(-0.0001 +exp2 * 1.0 + e1 * 1.0 / 16 + 17); checkEXP(exp2);
                exp2 = ceil(-0.0001 +exp2 * 1.15);
            }
        }
        exp1 -= e1;
        
    }
   
    checkEXP(exp1);
    checkEXP(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    checkEXP(EXP1);
    checkHP(HP1);
    checkM(M1);
    int S;
    double P1, P2, P3;
    // road 1
   
    for (int i = 0; i <= 25; i++) {
        
        if (EXP1 == 0) {
            S = 0;
            break;
        }
        if (abs(EXP1 - i * i) > abs(EXP1 - (i + 1) * (i + 1))) {
            S = (i + 1) * (i + 1);
        }
    }
    if (EXP1 >= S) P1 = 1;
    else P1 = (EXP1 * 1.0 / S + 80) / 123;
    // road 2
    float half = 0.5 * M1;
    if (E3 % 2 != 0) {
        while (true) {
            if (M1 == 0) break;
            if (HP1 < 200) {
                HP1 = ceil(-0.0001 +(float)HP1 * 1.3);
                M1 -= 150;
            }
            else {
                HP1 = ceil(-0.0001 +(float)HP1 * 1.1);
                M1 -= 70;
            }
            checkHP(HP1);
            checkM(M1);
            if (M1 == 0) break;
            if (M1 < half)  break;
            
            if (EXP1 < 400) {
                M1 -= 200;
                EXP1 = ceil(-0.0001 +float(EXP1) * 1.13);
            }
            else {
                M1 -= 120;
                EXP1 = ceil(-0.0001 +(float)EXP1 * 1.13);
            }
            checkEXP(EXP1);
            checkM(M1);
            if (M1 == 0) break;
            if (M1 < half) break;
            if (EXP1 < 300) {
                M1 -= 100;
                EXP1 = ceil(-0.0001 +(float)EXP1 * 0.9);
            }
            else {
                M1 -= 120;
                EXP1 = ceil(-0.0001 +(float)EXP1 * 0.9);
            }
            checkEXP(EXP1);
            checkM(M1);
            if (M1 == 0) break;
            if (M1 < half)  break;
        }
       
    }
    if (E3 % 2 == 0) {
            if (M1 == 0) goto endofif;
            if (HP1 < 200) {
                HP1 = ceil(-0.0001 +(float)HP1 * 1.3);
                M1 -= 150;
            }
            else {
                HP1 = ceil(-0.0001 +(float)HP1 * 1.1);
                M1 -= 70;
            }
            checkHP(HP1);
            checkM(M1);
            if (M1 == 0)  goto endofif;

            if (EXP1 < 400) {
                M1 -= 200;
                EXP1 = ceil(-0.0001 +(float)EXP1 * 1.13);
            }
            else {
                M1 -= 120;
                EXP1 = ceil(-0.0001 +(float)EXP1 * 1.13);
            }
            checkEXP(EXP1);
            checkM(M1);
            if (M1 == 0)  goto endofif;
            
            if (EXP1 < 300) {
                M1 -= 100;
                EXP1 = ceil(-0.0001 +(float)EXP1 * 0.9);
            }
            else {
                M1 -= 120;
                EXP1 = ceil(-0.0001 +(float)EXP1 * 0.9);
            }
            checkEXP(EXP1);
            checkM(M1);
    }
    endofif:
    HP1 = ceil(-0.0001 +(float) HP1 * 0.83);
    EXP1 = ceil(-0.0001 +(float)EXP1 * 1.17);
    checkEXP(EXP1);
    checkHP(HP1);
    checkM(M1);
    for (int i = 0; i <= 25; i++) {
        if (EXP1 == 0) {
            S = 0;
            break;
        }
        if (abs(EXP1 - i * i) > abs(EXP1 - (i + 1) * (i + 1))) {
            S = (i + 1) * (i + 1);
        }
    }
    if (EXP1 >= S) P2 = 1;
    else P2 = (EXP1 * 1.0 / S + 80) / 123;
    // road 3
    float p[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E3 < 10)  P3 = p[E3] / 100;
        else {
        int i = E3 / 10 + E3 % 10;
            if (i < 10) P3 = p[i] / 100;
            else P3 = p[i - 10] / 100;
        }
    // after 3 roads
    if ((P1 + P2 + P3) / 3 == 1) EXP1 = ceil(-0.0001 +(float)EXP1 * 0.75);
        else {
            if ((P1 + P2 + P3) / 3 < 0.5) {
                HP1 = ceil(-0.0001 +(float)HP1 * 0.85);
                EXP1 = ceil(-0.0001 +(float)EXP1 * 1.15);
            }
            else {
                HP1 = ceil(-0.0001 +(float)HP1 * 0.9);
                EXP1 = ceil(-0.0001 +(float)EXP1 * 1.2);
            }
        }
    checkEXP(EXP1);
    checkHP(HP1);
    checkM(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
   
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
     if (0 > E3 || E3 > 99) return -99;
    checkEXP(EXP1);
    checkHP(HP1);
    checkEXP(EXP2);
    checkHP(HP2);
    // TODO: Complete this function
    // matrix setup
    int map[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = (E3 * j + i * 2) * (i - j);
        }
    }
    // coordinate of meeting location
    int x = 0, y = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map[i][j] > 2 * E3) x += 1;
            if (map[i][j] < -E3) y += 1;
        }
    }
    if ( x < 10 ) x=x;
    else {
        int i= x / 10 + x % 10;
        if (i<10)x=i;
        else x = i/10+i%10;
    }
    if ( y < 10 ) y=y;
    else {
        int i= y / 10 + y % 10;
        if (i<10)y=i;
        else y = i/10+i%10;
    }
    // Taxi's grade
    int taxi = map[x][y];
    // Sherlock & Watson's grade
    int SWgrade = map[x][y];
    int l=x, r=y;
    while (0<=l && l<10 && 0<=r && r<10){
        if (map[l][r]>SWgrade) SWgrade=map[l][r];
        l++;r++;
    }
     while (0<=l && l<10 && 0<=r && r<10){
        if (map[l][r]>SWgrade) SWgrade=map[l][r];
        l--;r--;
    }
    l=x, r=y;
    while (0<=l && l<10 && 0<=r && r<10){
        if (map[l][r]>SWgrade) SWgrade=map[l][r];
        l++;r--;
    }
    while (0<=l && l<10 && 0<=r && r<10){
        if (map[l][r]>SWgrade) SWgrade=map[l][r];
        l--;r++;
    }
    if (abs(SWgrade) < abs(taxi)) {
        EXP1 = ceil(-0.0001 + EXP1 * 0.88);
        EXP2 = ceil(-0.0001 + EXP2 * 0.88);
        HP1 = ceil(-0.0001 + HP1 * 0.9);
        HP2 = ceil(-0.0001 + HP2 * 0.9);
        checkHP(HP1);
        checkHP(HP2);
        checkEXP(EXP1);
        checkEXP(EXP2);
        return taxi;
    }
    else {
        EXP1 = ceil(-0.0001 + EXP1 * 1.12);
        EXP2 = ceil(-0.0001 + EXP2 * 1.12);
        HP1 = ceil(-0.0001 + HP1 * 1.1);
        HP2 = ceil(-0.0001 + HP2 * 1.1);
        checkHP(HP1);
        checkHP(HP2);
        checkEXP(EXP1);
        checkEXP(EXP2);
        return SWgrade;
    }
}


// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    // find char before @
    string Email = static_cast<string>(email);
    string se;
    for (int i = 0; i < Email.length(); i++) {
        if (Email[i] != '@') se += Email[i];
        else break;
    }
    // Check if se is in s
    // xet sei.lengh() =1
    string S = static_cast<string>(s);
    if (S.length() < 8) return -1;
    if (S.length() > 20) return -2;
    if (S.find(se)<20) return -300-S.find(se);
    //check for more than 2 consecutive and indentical characters;
    for (int sci = 0; sci < S.length()-2; sci++) {
        if (S[sci] == S[sci + 1] && S[sci]==S[sci+2]) return -(400 + sci);
    }
    //check for speacial character
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '@' || S[i] == '#' || S[i] == '%' || S[i] == '$' || S[i] == '!') break;
        else  if (i == S.length() - 1) return -5;
    }
    //check for character error
    for (int i = 0; i < S.length(); i++) {
        if (S[i] >= 'A' && S[i] <= 'Z' || S[i] >='a' &&  S[i]<='z' || S[i] >= '0' && '9' >= S[i] || S[i] == '@' || S[i] == '#' || S[i] == '%' || S[i] == '$' || S[i] == '!') continue;
        else return i;
    }
    return -10;
}

//task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    const int num = num_pwds;
    string *pwds= new string[num_pwds];
    int *frequency= new int[num_pwds];
    for (int i = 0; i < num_pwds; i++) {
        pwds[i] = arr_pwds[i];
        frequency[i] = 0;
    }
   
    for (int i = 0; i < num_pwds; i++) {
        for (int j = 0; j < num_pwds; j++){
            if (pwds[i] == pwds[j]) frequency[i] += 1;
        }
    }
    int most=frequency[0],max=pwds[0].length();
    for (int i = 0; i < num_pwds; i++) {
        if (frequency[i] > most) most = frequency[i];
        if ( pwds[i].length() > max) max = pwds[i].length();
    }
     
    
    for (int j = 0; j < max; j++) {
        for (int i = num_pwds - 1; i >= 0; i--) {
            if (frequency[i] == most) {
                if (pwds[i].length() == max - j) {
                    max -= j;
                    goto endofloop;
                }
            }
        }
    }
    endofloop:
    int pw;
    for (int i = num_pwds - 1; i >= 0; i--) {
        if (frequency[i] == most && pwds[i].length() == max) pw = i;
    }
    delete[] pwds;
    delete[] frequency;
    return pw;
    
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////