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
void checkEXP(int& EXP1, int& EXP2) {
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 600) EXP2 = 600;
}
void checkHP(int& HP1, int& HP2) {
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (HP2 < 0) HP2 = 0;
    if (HP2 > 666) HP2 = 666;
}
void checkM(int& M1, int& M2) {
    if (M1 < 0) M1 = 0;
    if (M1 > 3000) M1 = 3000;
    if (M2 < 0) M2 = 0;
    if (M2 > 3000) M2 = 3000;
}
int firstMeet(int& EXP1, int& EXP2, int E1) {
    // TODO: Complete this function
    if (E1 < 0 || E1 > 99) {
        return -99;
    }
    checkEXP(EXP1, EXP2);
    if (0 <= E1 && E1 <= 3) { // E1 thuoc [0;3]
        if (E1 == 0) {
            EXP2 += 29;
            checkEXP(EXP1, EXP2);
        }
        else if (E1 == 1) {
            EXP2 += 45;
            checkEXP(EXP1, EXP2);
        }
        else if (E1 == 2) {
            EXP2 += 75;
            checkEXP(EXP1, EXP2);
        }
        else if (E1 == 3) {
            EXP2 += 29 + 45 + 75;
            checkEXP(EXP1, EXP2);
        }
        int D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0) {
            EXP1 = ceil((float)EXP1 + (float)D / 200);
            checkEXP(EXP1, EXP2);
        }
        else {
            EXP1 = ceil((float)EXP1 - (float)D / 100);
            checkEXP(EXP1, EXP2);
        }
    }
    else { // E1 thuoc [4;99]
        if (4 <= E1 && E1 <= 19) {
            EXP2 += ceil((float)E1 / 4 + 19);
            checkEXP(EXP1, EXP2);
        }
        else if (20 <= E1 && E1 <= 49) {
            EXP2 += ceil((float)E1 / 9) + 21;
            checkEXP(EXP1, EXP2);
        }
        else if (50 <= E1 && E1 <= 65) {
            EXP2 += ceil((float)E1 / 16 + 17);
            checkEXP(EXP1, EXP2);
        }
        else if (66 <= E1 && E1 <= 79) {
            EXP2 += ceil((float)E1 / 4 + 19);
            checkEXP(EXP1, EXP2);
            if (EXP2 > 200) {
                EXP2 += ceil((float)E1 / 9 + 21);
                checkEXP(EXP1, EXP2);
            }
        }
        else if (80 <= E1 && E1 <= 99) {
            EXP2 += ceil((float)E1 / 4 + 19);
            checkEXP(EXP1, EXP2);
            EXP2 += ceil((float)E1 / 9 + 21);
            checkEXP(EXP1, EXP2);
            if (EXP2 > 400) {
                EXP2 += ceil((float)E1 / 16 + 17);
                checkEXP(EXP1, EXP2);
                EXP2 = ceil((float)EXP2 + (float)EXP2 * 0.15);
            }
        }
        EXP1 -= E1;
        checkEXP(EXP1, EXP2);
    }
    return EXP1 + EXP2;
}
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2>99) {
        return -99;
    }
    checkEXP(EXP1, EXP1);
    checkHP(HP1, HP1);
    checkM(M1, M1);
    // CON DUONG 01
    int S1;
    int k = sqrt(EXP1);
    if (abs(k * k - EXP1) > abs((k + 1) * (k + 1) - EXP1)) {
        S1 = (k + 1) * (k + 1);
    }
    else {
        S1 = k * k;
    }
    double P1 = (EXP1 >= S1) ? 1.0 : (EXP1 / (double)S1 + 80) / 123;

    // CON DUONG 02
    float M0 = (float)M1 / 2; //So tien bat dau con duong
    if (M1 > 0) {
        if (E2 % 2 == 1) {//So le
            while ((float)M1 >= (float)M0) {
                if (HP1 < 200) {
                    HP1 = ceil((float)HP1 + 0.3 * (float)HP1);
                    M1 -= 150;
                    checkHP(HP1, HP1);
                    checkM(M1, M1);
                }
                else {
                    HP1 = ceil((float)HP1 + 0.1 * (float)HP1);
                    M1 -= 70;
                    checkHP(HP1, HP1);
                    checkM(M1, M1);
                }
                if ((float)M1 < M0) break;
                if (EXP1 < 400) {
                    M1 -= 200;
                    checkM(M1, M1);
                }
                else {
                    M1 -= 120;
                    checkM(M1, M1);
                }
                EXP1 = ceil((float)EXP1 + (float)EXP1 * 0.13);
                checkEXP(EXP1, EXP1);
                if ((float)M1 < M0) break;
                M1 -= ((EXP1 < 300) ? 100 : 120);
                checkM(M1, M1);
                EXP1 = ceil((float)EXP1 - (float)EXP1 * 0.1);
                checkEXP(EXP1, EXP1);
                if ((float)M1 < M0) break;
            }
        }
        while (E2 % 2 == 0) {// so chan
            if (HP1 < 200) {
                HP1 = ceil((float)HP1 + 0.3 * (float)HP1);
                M1 -= 150;
                checkHP(HP1, HP1);
                checkM(M1, M1);
            }
            else {
                HP1 = ceil((float)HP1 + 0.1 * (float)HP1);
                M1 -= 70;
                checkHP(HP1, HP1);
                checkM(M1, M1);
            }
            if (M1 <= 0) {
                M1 = 0;
                break;
            }
            if (EXP1 < 400) {
                M1 -= 200;
                checkM(M1, M1);
            }
            else {
                M1 -= 120;
                checkM(M1, M1);
            }
            EXP1 = ceil((float)EXP1 + (float)EXP1 * 0.13);
            checkEXP(EXP1, EXP1);
            if (M1 <= 0) {
                M1 = 0;
                break;
            }
            M1 -= ((EXP1 < 300) ? 100 : 120);
            checkM(M1, M1);
            EXP1 = ceil((float)EXP1 - (float)EXP1 * 0.1);
            checkEXP(EXP1, EXP1);
            if (M1 <= 0) {
                M1 = 0;
                break;
            }
            break;
        }
    }
    HP1 = ceil((float)HP1 - 0.17 * (float)HP1);
    checkHP(HP1, HP1);
    EXP1 = ceil((float)EXP1 + 0.17 * (float)EXP1);
    checkEXP(EXP1, EXP1);

    int S2;
    int j = sqrt(EXP1);
    if (abs(j * j - EXP1) > abs((j + 1) * (j + 1) - EXP1)) {
        S2 = (j + 1) * (j + 1);
    }
    else {
        S2 = j * j;
    }
    double P2 = (EXP1 >= S2) ? 1.0 : (EXP1 / (double)S2 + 80) / 123;

    // CON DUONG 03
    double P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i = ((E2 < 10) ? E2 : ((E2 / 10 + E2 % 10) % 10));
    double P3 = P[i];
    P3 = P3 / 100;

    if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0) {
        EXP1 = ceil((float)EXP1 - 0.25 * (float)EXP1);
        checkEXP(EXP1, EXP1);
    }
    else {
        double FinalProb = (P1 + P2 + P3) / 3;
        if (FinalProb < 0.5) {
            HP1 = ceil((float)0.85 * HP1);
            EXP1 = ceil((float)EXP1 + 0.15 * (float)EXP1);
            checkHP(HP1, HP1);
            checkEXP(EXP1, EXP1);
        }
        else {
            HP1 = ceil((float)0.9 * HP1);
            EXP1 = ceil((float)EXP1 + 0.2 * (float)EXP1);
            checkHP(HP1, HP1);
            checkEXP(EXP1, EXP1);
        }
    }

    checkHP(HP1, HP1);
    checkEXP(EXP1, EXP1);
    checkM(M1, M1);

    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3>99) {
        return -99;
    }
    checkEXP(EXP1, EXP2);
    checkHP(HP1, HP2);
    int matrix[10][10]; // tao ma tran
    int i = 0;
    int j = 0;
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) {
            matrix[x][y] = ((E3 * y) + (x * 2)) * (x - y);
            if (matrix[x][y] > (E3 * 2)) i += 1; //tim i và j
            if (matrix[x][y] < (-E3)) j += 1;
        }
    }
    while (i >= 10) { //ep i j thanh so 1 chu so
        i = (i / 10) + (i % 10);
    }
    while (j >= 10) {
        j = (j / 10) + (j % 10);
    }
    int x = i; //SWScore
    int y = j;
    int highest = matrix[i][j];
    while (x > 0 && y < 10) {//cheo phai
        if (matrix[x][y] > highest) {
            highest = matrix[x][y];
        }
        x -= 1;
        y += 1;
    }
    x = i;
    y = j;
    while (x < 10 && y > 0) {
        if (matrix[x][y] > highest) {
            highest = matrix[x][y];
        }
        x += 1;
        y -= 1;
    }
    x = i; //cheo trai
    y = j;
    while (x < 10 && y < 10) {
        if (matrix[x][y] > highest) {
            highest = matrix[x][y];
        }
        x += 1;
        y += 1;
    }
    x = i;
    y = j;
    while (x > 0 && y > 0) {
        if (matrix[x][y] > highest) {
            highest = matrix[x][y];
        }
        x -= 1;
        y -= 1;
    }
    int taxiScore = matrix[i][j];//diem taxi
    int final;
    if (abs(taxiScore) <= highest) {//so sanh 2 diem
        HP1 = ceil((float)HP1 + 0.1 * (float)HP1);
        EXP1 = ceil((float)EXP1 + 0.12 * (float)EXP1);
        HP2 = ceil((float)HP2 + 0.1 * (float)HP2);
        EXP2 = ceil((float)EXP2 + 0.12 * (float)EXP2);
        checkEXP(EXP1, EXP2);
        checkHP(HP1, HP2);
        final = highest;
    }
    else {
        HP1 = ceil((float)HP1 - (float)HP1 * 0.1);
        EXP1 = ceil((float)EXP1 - (float)EXP1 * 0.12);
        HP2 = ceil((float)HP2 - (float)HP2 * 0.1);
        EXP2 = ceil((float)EXP2 - (float)EXP2 * 0.12);
        checkEXP(EXP1, EXP2);
        checkHP(HP1, HP2);
        final = taxiScore;
    }
    checkEXP(EXP1, EXP2);
    checkHP(HP1, HP2);
    return final;
}
// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    char se[101]{}; //trich se
    int i = 0;
    while (email[i] != '@') {
        se[i] = email[i];
        i++;
    }
    se[i] = '\0';
    int length = strlen(s); //do dai
    if (length < 8) return -1;
    if (length > 20) return -2;
    const char* sestring = strstr(s, se); //s chua se
    if (sestring != NULL) {
        int i = sestring - s;
        return -(300 + i);
    }
    for (int i = 0; i < length - 2; i++) { // >2 ki tu lien tiep giong nhau
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            int sci = i;
            return -(400 + sci);
        }
    }
    int specialcharcount = 0; // ko co ki tu dac biet
    for (int i = 0; i < length; i++) {
        if (s[i] == '#' || s[i] == '@' || s[i] == '%' || s[i] == '!' || s[i] == '$') {
            specialcharcount += 1;
        }
    }
    if (specialcharcount == 0) {
        return -5;
    }

    for (int i = 0; i < length; i++) {//s chua ki tu ko phai so, ko phai chu, ko thuoc list ki tu dac biet
        if (!isalnum(s[i]) && s[i] != '#' && s[i] != '@' && s[i] != '%' && s[i] != '!' && s[i] != '$') {
            return i;
        }
    }
    return -10;
}
// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxcount = 0;
    int maxlength = 0;
    const char* correctpass;
    for (int i = 0; i < num_pwds; ++i) {// xet do lap + do dai pass
        const char* password = arr_pwds[i];
        int countpass = 0; // cap nhat do lap
        int length = strlen(password); // cap nhat do dai
        for (int j = 0; j < num_pwds; ++j) {// dem so lan xuat hien cua pass đang xet
            if (strcmp(arr_pwds[j], password) == 0) {
                countpass++;
            }
        }
        if (countpass > maxcount || (countpass == maxcount && length > maxlength)) { //update pass đung 
            maxcount = countpass;
            maxlength = length;
            correctpass = password;
        }
    }
    for (int i = 0; i < num_pwds; ++i) {// tim vi tri dau tien cua pass dung
        if (strcmp(arr_pwds[i], correctpass) == 0) {
            return i;
        }
    }
    return -1;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////