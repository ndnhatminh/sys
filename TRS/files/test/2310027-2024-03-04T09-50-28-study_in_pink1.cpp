#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNCTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    } else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Min
int min(int a, int b){
    return a > b ? b : a;
}
// Max
int max(int a, int b){
    return a > b ? a : b;
}
// Scope limit 
void limit(int &number, int range){
    number = max(0, min(number, range));
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 < 0 || e1 > 99) return -99;
    limit(exp1, 600); limit(exp2, 600);
    if (e1 <= 3) {
        switch (e1) {
            case 0: exp2 += 29; break;
            case 1: exp2 += 45; break;
            case 2: exp2 += 75; break;
            case 3: exp2 += 149; break;
        }
        
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = ceil(exp1 + 1.0 * D / 200);
        else exp1 = ceil(exp1 - 1.0 * D / 100);
    } else {
        if (e1 <= 19) exp2 += ceil(1.0 * e1 / 4 + 19);
        else if (e1 <= 49) exp2 += ceil(1.0 * e1 / 9 + 21);
        else if (e1 <= 65) exp2 += ceil(1.0 * e1 / 16 + 17);
        else if (e1 <= 79) {
            exp2 += ceil(1.0 * e1 / 4 + 19);
            if (exp2 > 200) exp2 += ceil(1.0 * e1 / 9 + 21);
        } else {
            exp2 += ceil(1.0 * e1 / 4 + 19);
            exp2 += ceil(1.0 * e1 / 9 + 21);
            if (exp2 > 400) {
                exp2 += ceil(1.0 * e1 / 16 + 17);
                exp2 = ceil(exp2 + exp2 * 0.15);
            } 
        }
        exp1 -= e1;
    }
    limit(exp1, 600); limit(exp2, 600);
    return exp1 + exp2;
} 

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99) return -99;
    limit(HP1, 666); limit(EXP1, 600); limit(M1, 3000);
    
    //ROAD 1
    float P1, P2, P3;
    int S = (int)(sqrt(EXP1) + 0.5); S *= S;
    if (S <= EXP1) P1 = 1;
    else P1 = (1.0 * EXP1 / S + 80) / 123;
    
    //ROAD 2
    int MS = 0, M1_tmp = M1, ok = 1;
    if (E2 % 2 == 0) ok = 0;
    do {    
        // Act 1
        if (M1 <= 0) break;
        if (HP1 < 200) {
            HP1 = ceil(HP1 + 0.3 * HP1);
            M1 -= 150; MS += 150;
        } else {
            HP1 = ceil(HP1 + 0.1 * HP1);
            M1 -= 70; MS += 70;
        }
        limit(HP1, 666);
        
        // Act 2
        if (M1 <= 0 || (MS > 0.5 * M1_tmp && ok)) break;
        if (EXP1 < 400) {
            M1 -= 200; MS += 200;
        } else {
            M1 -= 120; MS += 120;
        }
        EXP1 = ceil(EXP1 + 0.13 * EXP1);
        
        // Act 3
        if (M1 <= 0 || (MS > 0.5 * M1_tmp && ok)) break;
        if (EXP1 < 300) {
            M1 -= 100; MS += 100;
        } else {
            M1 -= 120; MS += 120;
        }
        EXP1 = ceil(EXP1 - 0.1 * EXP1);
        if (M1 <= 0 || (MS > 0.5 * M1_tmp && ok)) break;
    } while (MS <= M1_tmp * 0.5 && E2 % 2 == 1);
    
    // Update HP, EXP
    HP1 = ceil(HP1 - 0.17 * HP1); EXP1 = ceil(EXP1 + 0.17 * EXP1);
    limit(EXP1, 600); limit(M1, 3000);
    int SS = (int)(sqrt(EXP1) + 0.5); SS *= SS;
    if (SS <= EXP1) P2 = 1;
    else P2 = (1.0 * EXP1 / SS + 80) / 123;

    //ROAD 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 / 10 == 0) P3 = P[E2];
    else P3 = P[(E2 / 10 + E2 % 10) % 10];
    P3 /= 100; 
    if (P1 == 1 && P2 == 1 && P3 == 1) EXP1 = ceil(EXP1 - 0.25 * EXP1);
    else {
        if ((P1 + P2 + P3) / 3 <  0.5) {
            HP1 = ceil(HP1 - 0.15 * HP1);
            EXP1 = ceil(EXP1 + 0.15 * EXP1);
        } else {
            HP1 = ceil(HP1 - 0.1 * HP1);
            EXP1 = ceil(EXP1 + 0.2 * EXP1);
        }
        limit(EXP1, 600);
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) return -99;
    limit(EXP1, 600); limit(EXP2, 600);
    limit(HP1, 666); limit(HP2, 666);
    int arr[10][10], cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (arr[i][j] > E3 * 2) cnt1++;
            if (arr[i][j] < -E3) cnt2++;
        }
    }
    while (cnt1 / 10 != 0) cnt1 = cnt1 / 10 + cnt1 % 10;
    while (cnt2 / 10 != 0) cnt2 = cnt2 / 10 + cnt2 % 10;    
    int max_value = arr[cnt1][cnt2], i = cnt1, j = cnt2;
    while (i >= 0 && j >= 0 && i < 10 && j < 10) {    
        max_value = max(max_value, arr[i][j]);
        i--; j--;
    }
    i = cnt1; j = cnt2;
    while (i >= 0 && j >= 0 && i < 10 && j < 10) {
        max_value = max(max_value, arr[i][j]);
        i++; j--;
    }
    i = cnt1; j = cnt2;
    while (i >= 0 && j >= 0 && i < 10 && j < 10) {
        max_value = max(max_value, arr[i][j]);
        i--; j++;
    }
    i = cnt1; j = cnt2;
    while (i >= 0 && j >= 0 && i < 10 && j < 10) {
        max_value = max(max_value, arr[i][j]);
        i++; j++;
    }
    max_value = abs(max_value);
    if (abs(arr[cnt1][cnt2]) > max_value) {
        EXP1 = ceil(EXP1 - 0.12 * EXP1); EXP2 = ceil(EXP2 - 0.12 * EXP2);
        HP1 = ceil(HP1 - 0.1 * HP1); HP2 = ceil(HP2 - 0.1 * HP2);
        return arr[cnt1][cnt2];
    } else {
        EXP1 = ceil(EXP1 + 0.12 * EXP1); EXP2 = ceil(EXP2 + 0.12 * EXP2);
        HP1 = ceil(HP1 + 0.1 * HP1); HP2 = ceil(HP2 + 0.1 * HP2);
        limit(EXP1, 600); limit(EXP2, 600);
        limit(HP1, 666); limit(HP2, 666);
        return max_value;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string se = "", s_str = s, email_str = email;
    for (int i = 0; i < email_str.length(); i++) {
        if (email_str[i] == '@') break;
        se += email_str[i];
    }
    if (s_str.length() < 8) return -1;
    
    if (s_str.length() > 20) return -2;
    
    if (s_str.find(se) != -1) return -(300 + s_str.find(se));
    
    int special = 0;
    for (int j = 0; j < s_str.length(); j++) {
        if (s_str[j] == s_str[j + 1] && s_str[j] == s_str[j + 2]) return -(400 + j);
        if (s_str[j] == '@' || s_str[j] == '#' || s_str[j] == '%' || s_str[j] == '$' || s_str[j] == '!') special++;
    }
    if (special == 0) return -5;
    
    for (int j = 0; j < s_str.length(); j++) {
        if (s_str[j] == '@' || s_str[j] == '#' || s_str[j] == '%' || s_str[j] == '$' || s_str[j] == '!');
        else if (!isdigit(s_str[j]) && !isalpha(s_str[j])) return j;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string arr[num_pwds], CorrectPassword = "";
    int cnt[30], index = 0, times = 1;
    for (int i = 0; i < 30; i++) cnt[i] = 0;
    arr[0] = arr_pwds[0]; cnt[0] = 1;
    for (int i = 1; i < num_pwds; i++) {
        int ok = 1;
        for (int j = 0; j <= index; j++) {
            if (arr[j] == arr_pwds[i]) {
                cnt[j]++;
                times = max(times, cnt[j]);
                ok = 0;
            } 
        }
        if (ok) {
            index++;
            cnt[index] = 1;
            arr[index] = arr_pwds[i];
        }
    }
    for (int i = 0; i <= index; i++) {
        if (times == cnt[i]) {
            if (CorrectPassword.length() < arr[i].length()) CorrectPassword = arr[i];
        }
    }
    for (int i = 0; i < num_pwds; i++) {
        if (CorrectPassword == arr_pwds[i]) return i;
    }
    return -1;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////

