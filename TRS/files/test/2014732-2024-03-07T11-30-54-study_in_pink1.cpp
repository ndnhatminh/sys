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

int checkHP(int hp) {
    if (hp < 0) return 0;
    else if (hp > 666) return 666;
    return hp;
}

int checkEXP(int EXP) {
    if (EXP < 0) return 0;
    else if (EXP > 600) return 600;
    return EXP;
}

int checkM(int M) {
    if (M < 0) return 0;
    else if (M > 3000) return 3000;
    return M;
}

bool checkCP (int n){
    int s = sqrt(n);
    return s * s == n;
}

int nearestCP (int n){
    int a = round (sqrt(n));
    return a * a;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int D = 0;
    if (e1 < 0 || e1 > 99) return -99;
    else if (e1 >= 0 && e1 < 4){
        switch (e1){
            case 0: exp2 = checkEXP(exp2 + 29);
            break;
            case 1: exp2 = checkEXP(exp2 + 45);
            break;
            case 2: exp2 = checkEXP(exp2 + 75);
            break;
            case 3: exp2 = checkEXP(exp2 + 29 + 45 + 75);
            break;
        }
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = checkEXP(ceil(exp1 + (double)D / 200));
        else exp1 = checkEXP(ceil(exp1 - (double)D/100));
    }
    else if (e1 >= 4 && e1 <= 19) exp2 = checkEXP(ceil(exp2 + ((double)e1 / 4 + 19)));
    else if (e1 >= 20 && e1 <= 49) exp2 = checkEXP(ceil(exp2 + ((double)e1 / 9 + 21)));
    else if (e1 >= 50 && e1 <= 65) exp2 = checkEXP(ceil(exp2 + ((double)e1 / 16 + 17)));
    else if (e1 >= 66 && e1 <= 79) {
        exp2 = checkEXP(ceil(exp2 + ((double)e1/4 + 19)));
        if (exp2 > 200) exp2 = checkEXP(ceil(exp2 + ((double)e1 / 9 + 21)));
    }
    else {
        exp2 = checkEXP(ceil(exp2 + ((double)e1/4 + 19)));
        exp2 = checkEXP(ceil(exp2 + ((double)e1/9 + 21)));
        if (exp2 > 400) {
            exp2 = checkEXP(ceil(exp2 + ((double)e1/16 + 17)));
            exp2 = checkEXP(ceil(exp2 + exp2 * 0.15));
        }
    }
    if (e1 > 3) exp1 = checkEXP(exp1 - e1);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;
    double P1, P2, P3;
    //Con Duong 1
    int a = nearestCP(EXP1);
    if (EXP1 >= a) P1 = 1;
    else {
        double temp = (double)EXP1 / a;
        P1 = (temp + 80) / 123.0;
        P1 = ceil(P1 * 100) / 100;
    }
    //Con Duong 2
    int totalM = 0, halfM = ceil(M1 * 0.5);
    if (E2 % 2 == 1) {
        do {
            //TH1
            if (HP1 < 200) {
                M1 = checkM(M1 - 150);
                HP1 = checkHP(ceil(HP1 + HP1 * 0.3));
                totalM += 150;
                if (M1 == 0 || totalM > halfM) break;
            }
            else {
                M1 = checkM(M1 - 70);
                HP1 = checkHP(ceil(HP1 + HP1 * 0.1));
                totalM += 70;
                if (M1 == 0 || totalM > halfM) break;
            }
            //TH2
            if (EXP1 < 400) {
                M1 = checkM(M1 - 200);
                totalM += 200;
                EXP1 = checkEXP ((ceil(EXP1 * 1.13)));
            }
            else {
                M1 = checkM(M1 - 120);
                totalM += 120;
                EXP1 = checkEXP ((ceil(EXP1 * 1.13)));
            }
            if (M1 == 0 || totalM > halfM) break;
            //TH3
            if (EXP1 < 300) {
                M1 = checkM(M1 - 100);
                totalM += 100;
                EXP1 = checkEXP ((ceil(EXP1 * 0.9)));
            }
            else {
                M1 = checkM(M1 - 120);
                totalM += 120;
                EXP1 = checkEXP ((ceil(EXP1 * 0.9)));
            }
            if (M1 == 0 || totalM > halfM) break;
        } while (totalM <= halfM);
        EXP1 = checkEXP ((ceil(EXP1 * 1.17)));
        HP1 = checkHP ((ceil(HP1 - HP1 * 0.17)));
    }
    else {
        //TH1
        if (HP1 < 200 && M1 != 0) {
            M1 = checkM(M1 - 150);
            HP1 = ceil(HP1 + HP1 * 0.3);
        }
        else {
            if (M1 != 0){
                M1 = checkM(M1 - 70);
                HP1 = checkHP(ceil(HP1 + HP1 * 0.1));
            }
        }
        //TH2
        if (EXP1 < 400 && M1 != 0) {
            M1 = checkM(M1 - 200);
            EXP1 = checkEXP ((ceil(EXP1 * 1.13)));
        }
        else {
            if (M1 != 0){
                M1 = checkM(M1 - 120);
                EXP1 = checkEXP ((ceil(EXP1 * 1.13)));
            }
        }
        //TH3
        if (EXP1 < 300 && M1 != 0) {
            M1 = checkM(M1 - 100);
            EXP1 = checkEXP ((ceil(EXP1 * 0.9)));
        }
        else {
            if (M1 != 0){
                M1 = checkM(M1 - 120);
                EXP1 = checkEXP ((ceil(EXP1 * 0.9)));
            }
        }
        EXP1 = checkEXP ((ceil(EXP1 * 1.17)));
        HP1 = checkHP ((ceil(HP1 - HP1 * 0.17)));
    }
    int b = nearestCP(EXP1);
    if (EXP1 >= b) P2 = 1;
    else {
        double temp = (double)EXP1 / b;
        P2 = (temp + 80) / 123.0;
        P2 = ceil(P2 * 100) / 100;
    }
    //Con duong 3
    int arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int cs;
    if (E2 < 10) cs = E2;
    else {
        cs = (floor(E2 / 10) + (E2 % 10));
        cs %= 10;
    }
    P3 = (double)arr[cs] / 100;
    if (P1 == 1 && P2 == 1 && P3 == 1) EXP1 = ceil(EXP1 * 0.75);
    else {
        double P = (P1 + P2 + P3) / 3;
        if (P < 0.5) {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = checkEXP(ceil(EXP1 * 1.15));
        }
        else {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = checkEXP(ceil(EXP1 * 1.2));
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    int m[10][10];
    int a = 0, b = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            m[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (m[i][j] > (E3 * 2)) a++;
            if (m[i][j] < -E3) b++;
        }
    }
    while (a >= 10) a = (floor(a / 10) + (a % 10));
    while (b >= 10) b = (floor(b / 10) + (b % 10));
    int maxLeft = m[a][b];
    for (int x = a - 1, y = b - 1; x >= 0 && y >= 0; x--, y--) {
        if (m[x][y] > maxLeft) {
        maxLeft = m[x][y];
        }
    }
    for (int x = a + 1, y = b + 1; x < 10 && y < 10; x++, y++) {
        if (m[x][y] > maxLeft) {
        maxLeft = m[x][y];
        }
    }
    int maxRight = m[a][b];
    for (int x = a - 1, y = b + 1; x >= 0 && y < 10; x--, y++) {
        if (m[x][y] > maxRight) {
        maxRight = m[x][y];
        }
    }
    for (int x = a + 1, y = b - 1; x < 10 && y >= 0; x++, y--) {
        if (m[x][y] > maxRight) {
        maxRight = m[x][y];
        }
    }
    int max = maxLeft > maxRight ? maxLeft : maxRight;
    if (abs(m[a][b]) > max) {
        EXP1 = checkEXP(ceil(EXP1 * 0.88));
        HP1 = checkHP(ceil(HP1 * 0.9));
        EXP2 = checkEXP(ceil(EXP2 * 0.88));
        HP2 = checkHP(ceil(HP2 * 0.9));
        return m[a][b];
    }
    EXP1 = checkEXP(ceil(EXP1 + EXP1 * 0.12));
    HP1 = checkHP(ceil(HP1 + HP1 * 0.1));
    EXP2 = checkEXP(ceil(EXP2 + EXP2 * 0.12));
    HP2 = checkHP(ceil(HP2 + HP2 * 0.1));
    return max;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int se_pos = -1;
    for (int i = 0; i < strlen(email); i++){
        if (email[i] == '@') {
            se_pos = i;
            break;
        }
    }
    char se[100];
    strncpy(se, email, se_pos);
    se[se_pos] = '\0';
    int len = strlen(s);
    if (len < 8) return -1; // Mật khẩu quá ngắn
    if (len > 20) return -2; // Mật khẩu quá dài
    for (int i = 0; i < len; i++) {
        if (strncmp(s + i, se, se_pos) == 0) {
            return -(300 + i); // Mật khẩu chứa chuỗi se
        }
    }
    for (int i = 0; i < len - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i); // Mật khẩu chứa nhiều hơn 2 ký tự liên tiếp giống nhau
        }
    }
    bool flag = false;
    for (int i = 0; i < len; i++) {
        if (strchr("@#%$!", s[i]) != NULL) {
            flag = true;
        }
    }
    if (!flag) {
        return -5; // Mật khẩu không chứa ký tự đặc biệt
    }
    for (int i = 0; i < len; i++) {
        if (s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!' && isalnum(s[i]) == 0) {
            return i;
        }
    }
    return -10;
}

int arrCount (const char * arr[], const char *word, int numArr) {
    int count = 0;
    for (int i = 0; i < numArr; i++) {
        if (arr[i] == word) count++;
    }
    return count;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxCount = 0, maxLen = strlen(arr_pwds[0]), index = 0;

    // Duyệt qua mảng mật khẩu
    for (int i = 0; i < num_pwds; i++) {
        int curCount = arrCount(arr_pwds, arr_pwds[i], num_pwds);

        // Cập nhật maxCount và index chỉ khi số lần xuất hiện hiện tại cao hơn hoặc bằng
        if (curCount >= maxCount) {
            if (curCount > maxCount) {
                maxCount = curCount;
                maxLen = strlen(arr_pwds[i]);
                index = i;
            }
            else {
                if (strlen(arr_pwds[i]) > maxLen) {
                    maxLen = strlen(arr_pwds[i]);
                    index = i;
                }
            }
        }
    }

    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////