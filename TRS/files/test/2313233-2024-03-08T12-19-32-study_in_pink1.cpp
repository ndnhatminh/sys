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


int firstMeet(int& exp1, int& exp2, int e1) {
    if (e1 > 99 || e1 < 0) return -99;
    if (exp1 > 600) exp1 = 600;
    if (exp1 < 0) exp1 = 0;
    if (exp2 > 600) exp2 = 600;
    if (exp2 < 0) exp2 = 0;
    if (e1 >= 0 && e1 <= 3) {
        switch (e1)
        {
        case 0: exp2 += 29; break;
        case 1: exp2 += 45; break;
        case 2: exp2 += 75; break;
        case 3: exp2 += 29 + 45 + 75; break;
        }
        if (exp2 > 600) exp2 = 600;
        float D = e1 * 3 + exp1 * 7;
        if (int(D) % 2 == 0) exp1 += ceil(D / 200);
        else exp1 = ceil(float(exp1 - D / 100));
        if (exp1 > 600) exp1 = 600;
        
    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) exp2 += ceil(float(e1) / 4 + 19);
        if (e1 >= 20 && e1 <= 49) exp2 += ceil(float(e1) / 9 + 21);
        if (e1 >= 50 && e1 <= 65) exp2 += ceil(float(e1) / 16 + 17);
        if (e1 >= 66 && e1 <= 79) {
            exp2 += ceil(float(e1) / 4 + 19);
            if (exp2 > 200)  exp2 += ceil(float(e1) / 9 + 21);
        }
        if (e1 >= 80 && e1 <= 99) {
            exp2 += ceil(float(e1) / 4 + 19) + ceil(float(e1) / 9 + 21);
            if (exp2 > 400) {
                exp2 += ceil(float(e1) / 16 + 17);
                exp2 += ceil((float(exp2) / 100) * 15);
            }
        }
        if (exp2 > 600) exp2 = 600;
        exp1 -= e1;
        if (exp1 < 0) exp1 = 0;
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 > 99 || E2 < 0) return -99;
    if (HP1 > 666) HP1 = 666;
    if (EXP1 > 600) EXP1 = 600;
    if (M1 > 3000) M1 = 3000;
    if (M1 < 0) M1 = 0;
    if (HP1 < 0) HP1 = 0;
    if (EXP1 < 0) EXP1 = 0;
    int S;
    float k;
    float s = sqrt(EXP1);
    if (int(s) == s) S = EXP1;
    else if (abs(int(s) * int(s) - EXP1) >= abs((int(s) + 1) * (int(s) + 1) - EXP1)) S = (int(s) + 1) * (int(s) + 1);
    else S = int(s) * int(s);
    float P1;
    if (EXP1 >= S) P1 = 1;
    else P1 = (float(EXP1) / S + 80) / 123;
    if (E2 % 2 == 1) {
        k = float(M1) / 2;
        while (M1>0) {
            if (HP1 < 200) {
                HP1 = ceil(float(HP1 * 1.3));
                M1 -= 150;
            }
            else {
                HP1 = ceil(float(HP1 * 1.1));
                M1 -= 70;
            }
            if (HP1 > 666) HP1 = 666;
            if (M1 < k) break;

            if (EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            EXP1 = ceil(float(EXP1 * 1.13));
            if (EXP1 > 600) EXP1 = 600;
            if (M1 < k) break;

            if (EXP1 < 300) M1 -= 100;
            else M1 -= 120;
            EXP1 = ceil(float(EXP1 * 0.9));
            if (M1 < k) break;
        }

    }
    else {
        while (M1>0) {
            if (HP1 < 200) {
                HP1 = ceil(float(HP1 * 1.3));
                M1 -= 150;
            }
            else {
                HP1 = ceil(float(HP1 * 1.1));
                M1 -= 70;
            }
            if (HP1 > 666) HP1 = 666;
            if (M1 <= 0) break;

            if (EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            EXP1 = ceil(float(EXP1 * 1.13));
            if (EXP1 > 600) EXP1 = 600;
            if (M1 <= 0) break;

            if (EXP1 < 300) M1 -= 100;
            else M1 -= 120;
            EXP1 = ceil(float(EXP1 * 0.9));
            if (M1 <= 0) break;
            break;
        }
    }
    HP1 = ceil(float(HP1 * 0.83));
    EXP1 = ceil(float(EXP1 * 1.17));
    if (EXP1 > 600) EXP1 = 600;
    s = sqrt(EXP1);
    if (int(s) == s) S = EXP1;
    else if (abs(int(s) * int(s) - EXP1) >= abs((int(s) + 1) * (int(s) + 1) - EXP1)) S = (int(s) + 1) * (int(s) + 1);
    else S = int(s) * int(s);
    float P2, P3;
    if (EXP1 >= S) P2 = 1;
    else  P2 = (float(EXP1) / S + 80) / 123;
    if (M1 < 0) M1 = 0;

    float P[10] = { 31,47,28,79,100,50,22,83,64,11 };
    if (E2 / 10 == 0) P3 = P[E2] / 100;
    else P3 = P[(E2 / 10 + E2 % 10) % 10] / 100;

    if (P1 + P2 + P3 == 3){ 
        EXP1 = ceil(float(EXP1 * 0.75));
    }
    else if (P1 + P2 + P3 < 1.5) {
        EXP1 = ceil(float(EXP1 * 1.15));
        HP1 = ceil(float(HP1 * 0.85));
    }
    else {
        HP1 = ceil(float(HP1 * 0.9));
        EXP1 = ceil(float(EXP1 * 1.2));
    }
    if (EXP1 > 600) EXP1 = 600;

    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (E3 > 99 || E3 < 0) return -99;
    if (HP1 > 666) HP1 = 666;
    if (EXP1 > 600) EXP1 = 600;
    if (HP2 > 666) HP2 = 666;
    if (EXP2 > 600) EXP2 = 600;
    if (HP2 < 0) HP2 = 0;
    if (EXP2 < 0) EXP2 = 0;
    if (HP1 < 0) HP1 = 0;
    if (EXP1 < 0) EXP1 = 0;
    int taxi[10][10]{}, x = 0, y = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taxi[i][j] > 2 * E3) x += 1;
            if (taxi[i][j] < -E3) y += 1;
        }
    }
    while ((x / 10 > 0)||(y / 10 > 0)){
        x = x / 10 + x % 10;
        y = y / 10 + y % 10;
    }

    int max = taxi[x][y];
    if(x>=y){
        for(int i=-y;i+x<=9;i++){
            if (max < taxi[i + x][i + y]) max = taxi[x + i][y + i];
        }
    }
    else{
        for(int i=-x;i+y<=9;i++){
            if (max < taxi[i + x][i + y]) max = taxi[x + i][y + i];
        }
    }
    if(x+y>=9){
        for(int i=x-9;y+i<=9;i++){
            if (max < taxi[x - i][i + y]) max = taxi[x - i][i + y];
        }
    }
    else{
        for(int i=-y;x-i<=9;i++){
            if (max < taxi[x - i][i + y]) max = taxi[x - i][i + y];
        }
    }
    if (abs(taxi[x][y]) > abs(max)) {
        EXP1 = ceil(float(EXP1 * 0.88));
        HP1 = ceil(float(HP1 * 0.9));
        EXP2 = ceil(float(EXP2 * 0.88));
        HP2 = ceil(float(HP2 * 0.9));
        return taxi[x][y];
    }
    else {
        EXP1 = ceil(float(EXP1 * 1.12));
        HP1 = ceil(float(HP1 * 1.1));
        EXP2 = ceil(float(EXP2 * 1.12));
        HP2 = ceil(float(HP2 * 1.1));
        if (EXP1 > 600) EXP1 = 600;
        if (EXP2 > 600) EXP2 = 600;
        if (HP2 > 666) HP2 = 666;
        if (HP1 > 666) HP1 = 666;
        return max;
    }
}

// Task 4
int checkPassword(const char* s, const char* email) {
    int sizes = strlen(s);
    int sizese = 0;
    while (email[sizese] != '@') sizese++;
    char se[110];
    for (int i = 0; i < sizese; i++) {
        se[i] = email[i];
    }
    if (sizes < 8) return -1;
    else if (sizes > 20) return -2;
    int p = 0;
    for (int i = 0; i <= (sizes - sizese); i++) {
        for (int j = i; j < sizese + i; j++) {
            if (s[j] == se[j - i]) p++;
        }
        if (p == sizese) return -(300 + i);
        p = 0;
    }
    const char x[] = "!@#$%";
    for (int i = 0; i <= (sizes - 2); i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) return -(400 + i);
    }
    for (int i = 0; i < sizes; i++) {
        for (int j = 0; j < 5; j++) {
            if (s[i] == x[j]) p = -1;
        }
    }
    if (p != -1) return -5;
    for (int i = 0; i < sizes; i++) {
        if ((int(s[i] >= 48 && int(s[i]) <= 57)) || (int(s[i]) >= 64 && int(s[i]) <= 90) || (int(s[i]) >= 97 && int(s[i]) <= 122) || (int(s[i]) == 33) || (int(s[i]) >= 35 && int(s[i]) <= 37)) continue;
        else return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    const char* k[100]{};
    k[0] = arr_pwds[0];
    int l[100]{};
    l[0] = -1;
    int h = 0, m = 0;
    for (int i = 0; i < num_pwds; i++) {
        for (int j = 0; j <= h; j++) {
            if (!strcmp(arr_pwds[i],k[j])) {
                l[j]++;
                m++;
            }
        }
        if (m == 0) {
            h++;
            k[h] = arr_pwds[i];
        }
        m = 0;
    }
    int maxx = 0;
    for (int i = 0; i <= h; i++) {
        if ((l[maxx] < l[i]) || ((l[maxx] == l[i]) && (strlen(k[maxx]) < strlen(k[i])))) maxx = i;
    }
    for (int i = 0; i < num_pwds; i++) {
        if (!strcmp(arr_pwds[i], k[maxx])){ 
            return i;
        }
    }
    return 0;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////