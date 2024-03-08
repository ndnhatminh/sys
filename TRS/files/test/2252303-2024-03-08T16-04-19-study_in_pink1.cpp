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

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;
    if (exp1 < 0) exp1 = 0;
    if (exp2 < 0) exp2 = 0;
    if (exp1 > 600) exp1 = 600;
    if (exp2 > 600) exp2 = 600;
    if (e1 >= 0 && e1 <= 3) {
        switch (e1) {
        case 0:
            exp2 += 29;
            if (exp2 > 600) exp2 = 600;
            break;
        case 1:
            exp2 += 45;
            if (exp2 > 600) exp2 = 600;
            break;
        case 2:
            exp2 += 75;
            if (exp2 > 600) exp2 = 600;
            break;
        case 3:
            exp2 += 29 + 45 + 75;
            if (exp2 > 600) exp2 = 600;
            break;
        }
        float D = e1 * 3 + exp1 * 7;
        if (int(D) % 2 == 0) {
            exp1 = ceil(round((exp1 + D / 200) * 100) / 100);
            if (exp1 > 600) exp1 = 600;
        }
        else {
            exp1 = ceil(round((exp1 - D / 100) * 100) / 100);
            if (exp1 < 0) exp1 = 0;
        }
    }
    else {
        if (e1 >= 4 && e1 <= 19) {  // thong tin 1
            exp2 += ceil(round((float(e1) / 4 + 19) * 100) / 100);
            if (exp2 > 600) exp2 = 600;
        }
        else if (e1 >= 20 && e1 <= 49) {    // thong tin 2
            exp2 += ceil(round((float(e1) / 9 + 21) * 100) / 100);
            if (exp2 > 600) exp2 = 600;
        }
        else if (e1 >= 50 && e1 <= 65) {    // thong tin 3
            exp2 += ceil(round((float(e1) / 16 + 17) * 100) / 100);
            if (exp2 > 600) exp2 = 600;
        }
        else if (e1 >= 66 && e1 <= 79) {    // thong tin 4
            exp2 += ceil(round((float(e1) / 4 + 19) * 100) / 100);
            if (exp2 > 600) exp2 = 600;
            if (exp2 > 200) {
                exp2 += ceil(round((float(e1) / 9 + 21) * 100) / 100);
                if (exp2 > 600) exp2 = 600;
            }
        }
        else {                            // thong tin 5
            exp2 += ceil(round((float(e1) / 4 + 19) * 100) / 100);
            exp2 += ceil(round((float(e1) / 9 + 21) * 100) / 100);
            if (exp2 > 400) {
                exp2 += ceil(round((float(e1) / 16 + 17) * 100) / 100);
                exp2 = ceil(round(exp2 * 1.15 * 100) / 100);
                if (exp2 > 600) exp2 = 600;
            }
        }
        exp1 -= e1;
        if (exp1 < 0) exp1 = 0;
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;
    if (EXP1 < 0) EXP1 = 0;
    if (HP1 < 0) HP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (HP1 > 666) HP1 = 666;
    if (M1 < 0) M1 = 0;
    if (M1 > 3000) M1 = 3000;
    float P1, P2, P3;
    // Duong 1
    float S = round(sqrt(EXP1));
    S = S * S;
    if (EXP1 >= S) {
        P1 = 100;
    }
    else {
        P1 = ((EXP1 / S + 80) / 123) * 100;
    }
    float iniM1 = M1 * 0.5;
    // Duong 2
    int consume = 0;
    /*if (HP1 < 200) {
        HP1 = ceil(round(HP1 * 1.3 * 100) / 100);
        if (HP1 > 666) HP1 = 666;
        if (HP1 < 0) HP1 = 0;
        M1 -= 150;
        consume += 150;
    }
    else {
        HP1 = ceil(round(HP1 * 1.1 * 100) / 100);
        if (HP1 > 666) HP1 = 666;
        if (HP1 < 0) HP1 = 0;
        M1 -= 70;
        consume += 70;
    }
    if (EXP1 < 400) {
        M1 -= 200;
        EXP1 = ceil(round(EXP1 * 1.13 * 100) / 100);
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        consume += 200;
    }
    else {
        M1 -= 120;
        EXP1 = ceil(round(EXP1 * 1.13 * 100) / 100);
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        consume += 120;
    }
    if (EXP1 < 300) {
        M1 -= 100;
        consume += 100;
    }
    else {
        M1 -= 120;
        consume += 120;
        EXP1 = ceil(round(EXP1 * 0.9 * 100) / 100);
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
    }*/
    if (E2 % 2 != 0) {
        bool flag = true;
        while (flag) {
            if (HP1 < 200) {
                if (consume > iniM1) {
                    flag = false;
                }
                else {
                    HP1 = ceil(round(HP1 * 1.3 * 100) / 100);
                    if (HP1 > 666) HP1 = 666;
                    if (HP1 < 0) HP1 = 0;
                    M1 -= 150;
                    if (M1 < 0) M1 = 0;
                    consume += 150;
                }
            }
            else {
                if (consume > iniM1) {
                    flag = false;
                }
                else {
                    M1 -= 70;
                    if (M1 < 0) M1 = 0;
                    consume += 70;
                    HP1 = ceil(round(HP1 * 1.1 * 100) / 100);
                    if (HP1 > 666) HP1 = 666;
                    if (HP1 < 0) HP1 = 0;
                    // cout << "HP1 loop: " << HP1 << endl;
                }
            }
            if (flag == false) {
                break;
            }
            if (EXP1 < 400) {
                if (consume > iniM1) {
                    flag = false;
                }
                else {
                    M1 -= 200;
                    if (M1 < 0) M1 = 0;
                    consume += 200;
                    EXP1 = ceil(round(EXP1 * 1.13*100) / 100);
                    if (EXP1 < 0) EXP1 = 0;
                    if (EXP1 > 600) EXP1 = 600;
                }
            }
            else {
                if (consume > iniM1) {
                    flag = false;
                }
                else {
                    M1 -= 120;
                    if (M1 < 0) M1 = 0;
                    consume += 120;
                    EXP1 = ceil(round(EXP1 * 1.13 * 100) / 100);
                    if (EXP1 < 0) EXP1 = 0;
                    if (EXP1 > 600) EXP1 = 600;
                }
            }
            if (flag == false) {
                break;
            }
            if (EXP1 < 300) {
                if (consume > iniM1) {
                    flag = false;
                }
                else {
                    M1 -= 100;
                    if (M1 < 0) M1 = 0;
                    consume += 100;
                    EXP1 = ceil(round(EXP1 * 0.9 * 100) / 100);
                    if (EXP1 < 0) EXP1 = 0;
                    if (EXP1 > 600) EXP1 = 600;
                }
            }
            else {
                if (consume > iniM1) {
                    flag = false;
                }
                else {
                    M1 -= 120;
                    if (M1 < 0) M1 = 0;
                    consume += 120;
                    EXP1 = ceil(round(EXP1 * 0.9 * 100) / 100);
                    if (EXP1 < 0) EXP1 = 0;
                    if (EXP1 > 600) EXP1 = 600;
                }
            }
            if (flag == false) {
                break;
            }
        }
        HP1 = ceil(round(HP1 * 0.83 * 100) / 100);
        if (HP1 > 666) HP1 = 666;
        if (HP1 < 0) HP1 = 0;
        EXP1 = ceil(round(EXP1 * 1.17 * 100) / 100);
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        S = round(sqrt(EXP1));
        S = S * S;
        if (EXP1 >= S) {
            P2 = 100;
        }
        else {
            P2 = ((EXP1 / S + 80) / 123) * 100;
        }
    }
    else {      // so chan
        if (M1 > 0) {
            if (HP1 < 200) {
                HP1 = ceil(round(HP1 * 1.3 * 100) / 100);
                if (HP1 > 666) HP1 = 666;
                if (HP1 < 0) HP1 = 0;
                M1 -= 150;
                if (M1 < 0) M1 = 0;
            }
            else {
                HP1 = ceil(round(HP1 * 1.1 * 100) / 100);
                if (HP1 > 666) HP1 = 666;
                if (HP1 < 0) HP1 = 0;
                M1 -= 70;
                if (M1 < 0) M1 = 0;
            }
        }
        if (M1 > 0) {
            if (EXP1 < 400) {
                M1 -= 200;
                if (M1 < 0) M1 = 0;
                EXP1 = ceil(round(EXP1 * 1.13 * 100) / 100);
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
            }
            else {
                M1 -= 120;
                if (M1 < 0) M1 = 0;
                EXP1 = ceil(round(EXP1 * 1.13 * 100) / 100);
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
            }
        }
        if (M1 > 0) {
            if (EXP1 < 300) {
                M1 -= 100;
                if (M1 < 0) M1 = 0;
                EXP1 = ceil(round(EXP1 * 0.9 * 100) / 100);
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
            }
            else {
                M1 -= 120;
                if (M1 < 0) M1 = 0;
                EXP1 = ceil(round(EXP1 * 0.9 * 100) / 100);
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
            }
        }
        if (M1 < 0) M1 = 0;
        HP1 = ceil(round(HP1 * 0.83 * 100) / 100);
        if (HP1 > 666) HP1 = 666;
        if (HP1 < 0) HP1 = 0;
        EXP1 = ceil(round(EXP1 * 1.17 * 100) / 100);
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        S = round(sqrt(EXP1));
        S = S * S;
        if (EXP1 >= S) {
            P2 = 100;
        }
        else {
            P2 = ((EXP1 / S + 80) / 123) * 100;
        }
    }
    // Duong 3
    int Pi[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i;
    if (E2 < 10) {
        i = E2;
    }
    else {
        i = ((E2 / 10) + (E2 % 10)) % 10;
    }
    P3 = Pi[i];
    float avgP;
    if (P1 == 100 && P2 == 100 && P3 == 100) {
        EXP1 = ceil(round(EXP1 * 0.75 * 100) / 100);
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
    }
    else {
        avgP = (P1 + P2 + P3) / 3;
        if (avgP < 50) {
            HP1 = ceil(round(HP1 * 0.85 * 100) / 100);
            if (HP1 > 666) HP1 = 666;
            if (HP1 < 0) HP1 = 0;
            EXP1 = ceil(round(EXP1 * 1.15 * 100) / 100);
            if (EXP1 < 0) EXP1 = 0;
            if (EXP1 > 600) EXP1 = 600;
        }
        else {
            HP1 = ceil(round(HP1 * 0.9 * 100) / 100);
            if (HP1 > 666) HP1 = 666;
            if (HP1 < 0) HP1 = 0;
            EXP1 = ceil(round(EXP1 * 1.2 * 100) / 100);
            if (EXP1 < 0) EXP1 = 0;
            if (EXP1 > 600) EXP1 = 600;
        }
    }
    // cout << "P1 " <<P1 << endl;
    // cout << "P2 " <<P2 << endl;
    // cout << "P3 " <<P3 << endl;
    // cout << "HP1 " << HP1 << endl;
    // cout << "EXP1 " << EXP1 << endl;
    // cout << "M1 " << M1 << endl;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP2 > 600) EXP2 = 600;
    if (EXP2 < 0) EXP2 = 0;
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (HP2 < 0) HP2 = 0;
    if (HP2 > 666) HP2 = 666;
    int arr[10][10] = {0};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int x = 0, y = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] > (E3 * 2)) {
                x++;
            }
            if (arr[i][j] < (-E3)) {
                y++;
            }
        }
    }
    while (x >= 10) {
        x = (x / 10) + (x % 10);
    }
    while (y >= 10) {
        y = (y / 10) + (y % 10);
    }
    int tempx = x;
    int tempy = y;
    int diemTaxi = arr[x][y];
    long long maxphai = arr[tempx][tempy];
    long long maxtrai = arr[tempx][tempy];
    //cheo phai tren
    while (tempx != 0) {
        if (tempy != 0) {
            tempx--;
            tempy--;
        }
        else {
            break;
        }
        if (maxphai < arr[tempx][tempy]) {
            maxphai = arr[tempx][tempy];
        }
    }
    //cheo phai duoi
    tempx = x;
    tempy = y;
    while (tempy != 9) {
        if (tempx != 9) {
            tempx++;
            tempy++;
        }
        else {
            break;
        }
        if (maxphai < arr[tempx][tempy]) {
            maxphai = arr[tempx][tempy];
        }
    }
    //cheo trai tren
    while (tempx != 0) {
        if (tempy != 9) {
            tempx--;
            tempy++;
        }
        else {
            break;
        }
        if (maxtrai < arr[tempx][tempy]) {
            maxtrai = arr[tempx][tempy];
        }
    }
    //cheo trai duoi
    tempx = x;
    tempy = y;
    while (tempy != 0) {
        if (tempx != 9) {
            tempx++;
            tempy--;
        }
        else {
            break;
        }
        if (maxtrai < arr[tempx][tempy]) {
            maxtrai = arr[tempx][tempy];
        }
    }
    int diemThamTu;
    diemThamTu = max(maxphai, maxtrai);
    if (abs(diemTaxi) > diemThamTu) {
        EXP1 = ceil(round(EXP1 * 0.88 * 100) / 100);
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        EXP2 = ceil(round(EXP2 * 0.88 * 100) / 100);
        if (EXP2 < 0) EXP2 = 0;
        if (EXP2 > 600) EXP2 = 600;
        HP1 = ceil(round(HP1 * 0.9 * 100) / 100);
        if (HP1 < 0) HP1 = 0;
        if (HP1 > 666) HP1 = 666;
        HP2 = ceil(round(HP2 * 0.9 * 100) / 100);
        if (HP2 < 0) HP2 = 0;
        if (HP2 > 666) HP2 = 666;
        return diemTaxi;
    }
    else {
        EXP1 = ceil(round(EXP1 * 1.12 * 100) / 100);
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        EXP2 = ceil(round(EXP2 * 1.12 * 100) / 100);
        if (EXP2 < 0) EXP2 = 0;
        if (EXP2 > 600) EXP2 = 600;
        HP1 = ceil(round(HP1 * 1.1 * 100) / 100);
        if (HP1 < 0) HP1 = 0;
        if (HP1 > 666) HP1 = 666;
        HP2 = ceil(round(HP2 * 1.1 * 100) / 100);
        if (HP2 < 0) HP2 = 0;
        if (HP2 > 666) HP2 = 666;
        return diemThamTu;
    }
}

// Task 4
int checkPassword(const char* s, const char* email) {
    string se;
    int index = 0;
    while (email[index] != '@') {
        se += email[index];
        index++;
    }
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    if (length < 8) return -1;
    if (length > 20) return -2;
    int sLength = length;
    index = 0;
    int tmpidx = 0;
    int pivot;
    int pivotse;
    bool check = true;
    bool hasSpecialChar = false;
    bool hasConsecutiveChars = false;
    bool containsSe = true;
    int invalidchar;
    bool invalid = false;
    while (s[index] != '\0') {
        int temp = index;
        // check special
        if (!isalnum(s[index]) && s[index] != '@' && s[index] != '#' && s[index] != '%' && s[index] != '$' && s[index] != '!') {
            if (invalid != true){
                invalidchar = index;
                invalid = true;
            }
        }

        if (s[index] == '@' || s[index] == '#' || s[index] == '%' || s[index] == '$' || s[index] == '!') {
            hasSpecialChar = true;
        }

        // check consecutive
        if (index > 0 && s[index] == s[index - 1] && s[index] == s[index + 1]) {
            if (hasConsecutiveChars != true) {
                pivot = index - 1;
                hasConsecutiveChars = true;
            }
        }
        tmpidx = 0;
        index = temp;
        index++;
    }
    // check contain se
    string stemp = s;
    size_t found = stemp.find(se);
    if (found != string::npos) {
        pivotse = static_cast<int>(found);
        containsSe = true;
    }
    else {
        containsSe = false;
    }


    if (containsSe) return -(300 + pivotse);
    if (hasConsecutiveChars) return -(400 + pivot);
    if (hasSpecialChar == false) return -5;
    if (invalid) return invalidchar;
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int max_length = 0;
    int max_count = 0;
    int correct_index = -1;

    for (int i = 0; i < num_pwds; ++i) {
        const char* current_pwd = arr_pwds[i];
        int current_length = strlen(current_pwd);
        int count = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(current_pwd, arr_pwds[j]) == 0) {
                ++count;
            }
        }
        if (count > max_count || (count == max_count && current_length > max_length)) {
            max_count = count;
            max_length = current_length;
            correct_index = i;
        }
    }

    return correct_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
