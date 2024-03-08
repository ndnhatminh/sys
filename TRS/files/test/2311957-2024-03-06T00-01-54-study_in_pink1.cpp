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
    // TODO: Complete this function
    int D;
    float ss;
    if (0 <= e1 && e1 <= 99) {
        if (exp1 > 600) exp1 = 600;
        if (exp2 > 600) exp2 = 600;
        if (exp1 < 0) exp1 = 0;
        if (exp2 < 0) exp2 = 0;
        if (0 <= e1 && e1 <= 3) {
            switch (e1)
            {
            case 0: exp2 += 29; break;
            case 1: exp2 += 45; break;
            case 2: exp2 += 75; break;
            case 3: exp2 = exp2 + 29 + 45 + 75; break;
            }
            if (exp2 > 600) exp2 = 600;
            D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0) {
                exp1 += D / 200; if (D % 200 != 0) exp1++;
            }
            else {
                exp1 -= D / 100;
            }
            if (exp1 > 600) exp1 = 600;
            if (exp1 < 0) exp1 = 0;
        }
        else {
            if (4 <= e1 && e1 <= 19) {
                exp2 += e1 / 4 + 19;
                if (e1 % 4 != 0) exp2++;
                if (exp2 > 600) exp2 = 600;
            }
            if (20 <= e1 && e1 <= 49) {
                exp2 += e1 / 9 + 21;
                if (e1 % 9 != 0) exp2++;
                if (exp2 > 600) exp2 = 600;
            }
            if (50 <= e1 && e1 <= 65) {
                exp2 += e1 / 16 + 17;
                if (e1 % 16 != 0) exp2++;
                if (exp2 > 600) exp2 = 600;
            }
            if (66 <= e1 && e1 <= 79) {
                exp2 += e1 / 4 + 19;
                if (e1 % 4 != 0) exp2++;
                if (exp2 > 200) {
                    exp2 += e1 / 9 + 21;
                    if (e1 % 9 != 0) exp2++;
                }
                if (exp2 > 600) exp2 = 600;
            }
            if (80 <= e1 && e1 <= 99) {
                exp2 += e1 / 4 + 19;
                if (e1 % 4 != 0) exp2++;
                exp2 += e1 / 9 + 21;
                if (e1 % 9 != 0) exp2++;
                if (exp2 > 400) {
                    exp2 += e1 / 16 + 17;
                    if (e1 % 16 != 0) exp2++;
                    ss = exp2 * 1.15;
                    exp2 *= 1.15;
                    if (ss > exp2) exp2++;
                }
                if (exp2 > 600) exp2 = 600;
            }
            exp1 -= e1;
            if (exp1 < 0) exp1 = 0;
        }
        return exp1 + exp2;
    }
    else return -99;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if (0 <= E2 && E2 <= 99) {
        if (HP1 > 666) HP1 = 666;
        if (HP1 < 0) HP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        if (EXP1 < 0) EXP1 = 600;
        if (M1 < 0)M1 = 0;
        if (M1 > 3000)M1 = 3000;
        bai2:
        //duong1
        float P1, P2, P3,ss;
        int S = sqrt(EXP1), chuc1, donvi1, chuc2, donvi2;
        float savemoney = 0, halfmoney = 0.5 * M1;
        if (S * S == EXP1) P1 = 1;
        else {
            int a = S + 1;
            if ((EXP1 - pow(S, 2)) > (pow(a, 2) - EXP1)) P1 = 1;
            else P1 = (((EXP1 * 1.0 / S) + 80) / 123);
        }
        //duong2
        if (E2 % 2 == 0) {
            //sukien1
            if (M1 != 0) {
                if (HP1 < 200) {
                    ss = HP1 * 1.3;
                    HP1 *= 1.3;
                    if (ss > HP1) HP1++;
                    if (HP1 > 666) HP1 = 666;
                    M1 -= 150;
                    if (M1 < 0) M1 = 0;
                }
                else {
                    ss = HP1 * 1.1;
                    HP1 *= 1.1;
                    if (ss > HP1)HP1++;
                    if (HP1 > 666)HP1 = 666;
                    M1 -= 70;
                    if (M1 < 0) M1 = 0;
                }
                //sukien2
                if (M1 != 0) {
                    if (EXP1 < 400) M1 -= 200;
                    else M1 -= 120;
                    if (M1 < 0) M1 = 0;
                    ss = EXP1 * 1.13;
                    EXP1 *= 1.13;
                    if (ss > EXP1) EXP1++;
                }
                //sk3
                if (M1 != 0) {
                    if (EXP1 < 300) M1 -= 100;
                    else M1 -= 120;
                    if (M1 < 0) M1 = 0;
                    ss = EXP1 * 0.9;
                    EXP1 *= 0.9;
                    if (ss > EXP1) EXP1++;
                }
            }
        }
        else {
            for (;;) {
                if (HP1 < 200) {
                    ss = HP1 * 1.3;
                    HP1 *= 1.3;
                    if (ss > HP1) HP1++;
                    if (HP1 > 666) HP1 = 666;
                    M1 -= 150;
                    savemoney += 150;
                    if (M1 < 0) M1 = 0;
                    if (savemoney > halfmoney) break;
                }
                else {
                    ss = HP1 * 1.1;
                    HP1 *= 1.1;
                    if (ss > HP1)HP1++;
                    if (HP1 > 666)HP1 = 666;
                    M1 -= 70;
                    if (M1 < 0) M1 = 0;
                    savemoney += 70;
                    if (savemoney > halfmoney) break;
                }
                //sukien2

                if (EXP1 < 400) {
                    M1 -= 200;
                    savemoney += 200;
                }
                else {
                    M1 -= 120;
                    savemoney += 120;
                }
                if (M1 < 0) M1 = 0;
                ss = EXP1 * 1.13;
                EXP1 *= 1.13;
                if (ss > EXP1) EXP1++;
                if (EXP1 > 600) EXP1 = 600;
                if (savemoney > halfmoney) break;

                //sk3

                if (EXP1 < 300) {
                    M1 -= 100;
                    savemoney += 100;
                }
                else {
                    M1 -= 120;
                    savemoney += 120;
                }
                if (M1 < 0) M1 = 0;
                ss = EXP1 * 0.9;
                EXP1 *= 0.9;
                if (ss > EXP1) EXP1++;
                if (savemoney > halfmoney) break;
            }
        }
        ss = HP1 * 0.83;
        HP1 *= 0.83;
        if (ss > HP1) HP1++;
        ss = EXP1 * 1.17;
        EXP1 *= 1.17;
        if (ss > EXP1) EXP1++;
        if (EXP1 > 600)EXP1 = 600;
        S = sqrt(EXP1);
        if (S * S == EXP1) P2 = 1;
        else {
            int a = S + 1;
            if (((EXP1 - pow(S, 2))) > ((pow(a, 2) - EXP1))) P2 = 1;
            else P2 = (((EXP1 * 1.0 / S) + 80) / 123);
        }
        //đường 3
        int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        if (E2 <= 9) P3 = P[E2];
        else {
            chuc1 = E2 / 10;
            donvi1 = E2 - chuc1 * 10;
            chuc2 = (chuc1 + donvi1) / 10;
            donvi2 = (chuc1 + donvi1) - chuc2 * 10;
            P3 = P[donvi2];
        }
        P3 = P3 / 100;
        if (P1 == 1 && P2 == 1 && P3 == 1) {
            ss = EXP1 * 0.75;
            EXP1 *= 0.75;
            if (ss > EXP1) EXP1++;
            goto bai2;
        }
        else {
            if (((P1 + P2 + P3) / 3) < 0.5) {
                ss = HP1 * 0.85;
                HP1 *= 0.85;
                if (ss > HP1) HP1++;
                ss = EXP1 * 1.15;
                EXP1 *= 1.15;
                if (ss > EXP1) EXP1++;
            }
            else {
                ss = HP1 * 0.9;
                HP1 *= 0.9;
                if (ss > HP1) HP1++;
                ss = EXP1 * 1.2;
                EXP1 *= 1.2;
                if (ss > EXP1) EXP1++;
            }
        }
        if (EXP1 > 600) EXP1 = 600;
        return HP1 + EXP1 + M1;
    }
    else return -99;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (0 < E3 && E3 < 99) {
        int countbigger = 0, countsmaller = 0, x, y, chuc1, donvi1, chuc2, donvi2, sum, subtrac, c;
        int taxi[10][10], sherlock[10][10];
        float ss;
        if (HP1 > 666) HP1 = 666;
        if (HP1 < 0) HP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        if (EXP1 < 0) EXP1 = 600;
        if (HP2 > 666) HP2 = 666;
        if (HP2 < 0) HP2 = 0;
        if (EXP2 > 600) EXP2 = 600;
        if (EXP2 < 0) EXP2 = 600;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                sherlock[i][j] = 0;
            }
        }
        for (int i=0; i < 10; i++) {
            for (int j=0; j < 10; j++) {
                taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                if (taxi[i][j] > (E3 * 2)) countbigger++;
                if (taxi[i][j] < (-E3)) countsmaller++;
            }
        }
        //x la vi tri gap nhau
        chuc1 = countbigger / 10;
        donvi1 = countbigger - chuc1 * 10;
        x = chuc1 + donvi1;
        chuc2 = x / 10;
        donvi2 = x - 10 * chuc2;
        x = chuc2 + donvi2;
        //y la vi tri gap nhau
        chuc1 = countsmaller / 10;
        donvi1 = countsmaller - chuc1 * 10;
        y = chuc1 + donvi1;
        chuc2 = x / 10;
        donvi2 = y - 10 * chuc2;
        y = chuc2 + donvi2;
        sherlock[x][y] = taxi[x][y];
        c = 0;
        sum = x + y;
        subtrac = y - x;
        for (int m = 0; m < 10; m++) {
            if (subtrac < 0 || subtrac>9) {
                c++;
                subtrac++;
                continue;
            }
            if (taxi[c][subtrac] > sherlock[x][y]) sherlock[x][y] = taxi[c++][subtrac++];
        }
        for (int m = 0; m < 10; m++) {
            if (sum < 0 || sum>9) {
                c++;
                sum--;
                continue;
            }
            if (taxi[c][sum] > sherlock[x][y]) sherlock[x][y] = taxi[c++][sum--];
        }
        if (sherlock[x][y] < 0) sherlock[x][y] = abs(sherlock[x][y]);
        if (sherlock[x][y] >= abs(taxi[x][y])) {
            ss = EXP1 * 1.12;
            EXP1 *= 1.12;
            if (ss > EXP1)EXP1++;
            if (EXP1 > 600) EXP1 = 600;
            ss = EXP2 * 1.12;
            EXP2 *= 1.12;
            if (EXP2 < ss) EXP2++;
            if (EXP2 > 600)EXP2 = 600;
            ss = HP1 * 1.1;
            HP1 *= 1.1;
            if (ss > HP1) HP1++;
            if (HP1 > 666) HP1 = 666;
            ss = HP2 * 1.1;
            HP2 *= 1.1;
            if (ss > HP2)HP2++;
            if (HP2 > 666) HP2 = 666;
            return sherlock[x][y];
        }
        else {
            ss = EXP1 * 0.88;
            EXP1 *= 0.88;
            if (ss > EXP1)EXP1++;
            ss = EXP2 * 0.88;
            EXP2 *= 0.88;
            if (EXP2 < ss) EXP2++;
            ss = HP1 * 0.9;
            HP1 *= 0.9;
            if (ss > HP1) HP1++;
            ss = HP2 * 0.9;
            HP2 *= 0.9;
            if (ss > HP2)HP2++;
            return taxi[x][y];
        }
    }
    else return -99;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    char se[101] = { 0 };
    char* ptse = se;
    int cnt = 0, len = strlen(s), sei = 0, sci = 0,vitri;
    const char* trung;
    for (int i = 0; email[i] != '@'; i++) {
        ptse[i] = email[i];
        cnt = i;
    }
    se[++cnt] = '\0';
    trung = strstr(s, se);
    if (8 > len) return -1;

    if (20 < len) return -2;

    if (trung != nullptr) {
        vitri = strlen(s)-strlen(trung);
        return -(300 + vitri);
       
    }
       
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) return -(400 + i);   
    }
   
    for (int i = 0; i < len; i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%' || s[i] == '!') break;
        else return -5;
    }
    char illegal[28] = { 32,34,38,39,40,41,42,43,44,45,46,47,58,59,60,61,62,63,91,92,93,94,95,96,123,124,125,126 };
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 28; j++) {
            if (s[i] == illegal[j]) return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int tanso=0,length=0,first=0;
    for (int i = 0; i < num_pwds; i++) {
        int count = 1;
        for (int j = i+1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) count++;
        }
        if (count > tanso) {
            tanso = count;
            first = i;
            length = strlen(arr_pwds[i]);
        }
        if (count == tanso) {
            if (strlen(arr_pwds[i]) > length) {
                length = strlen(arr_pwds[i]);
                first = i;
            }
        }
    }
    return first;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////