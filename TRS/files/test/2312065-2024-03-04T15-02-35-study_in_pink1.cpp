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
void expmaxmin(int &a) {
    if (a < 0) a = 0;
    if (a > 600) a = 600;
}

void hpmaxmin(int &a) {
    if (a < 0) a = 0;
    if (a > 666) a = 666;
}

void tienmaxmin(int &a) {
    if (a < 0) a = 0;
    if (a > 3000) a = 3000;
}

int manhmoi1(int a, int b) {
    return int((a + (1.0 * b / 4) + 19) + 0.999);
}
int manhmoi2(int a, int b) {
    return int((a + (1.0 * b / 9) + 21) + 0.999);
}
int manhmoi3(int a, int b) {
    return int((a + (1.0 * b / 16) + 17) + 0.999);
}
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 < 0 || e1>99) return -99;
    if (e1 >= 0 && e1 <= 3) {
        switch (e1) {
        case 0:
            exp2 += 29; break;
        case 1:
            exp2 += 45; break;
        case 2:
            exp2 += 75; break;
        case 3:
            exp2 += (29 + 45 + 75); break;
        }
        expmaxmin(exp2);
        int d = (3 * e1 + 7 * exp1);
        (d & 1) ? (exp1 -= floor(int(1.0 * d / 100.0))) : (exp1 += ceil(1.0 * d / 200.0));
        expmaxmin(exp1);

    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) exp2 = manhmoi1(exp2, e1);
        if (e1 >= 20 && e1 <= 49) exp2 = manhmoi2(exp2, e1);
        if (e1 >= 50 && e1 <= 65) exp2 = manhmoi3(exp2, e1);
        if (e1 >= 66 && e1 <= 79) {
            exp2 = manhmoi1(exp2, e1);
            if (exp2 > 200) exp2 = manhmoi2(exp2, e1);
        }
        if (e1 >= 80 && e1 <= 99) {
            exp2 = manhmoi2(manhmoi1(exp2, e1), e1);
            if (exp2 > 400) {
                exp2 = manhmoi3(exp2, e1);
                exp2 += int((1.0 * exp2 * 0.15) + 0.999);
            }
        }
        exp1 -= e1;

    }
    expmaxmin(exp1);
    expmaxmin(exp2);
    return (exp1 + exp2);
}
bool checkchinhphuong(int n) {
    int a = 0;
    while (a * a <= n) {
        if (a * a == n) {
            return true;
        }
        a++;
    }
    return false;
}

int sos(int n) {
    if (n==0) return n;
    int a = n - 1;
    int b = n + 1;
    while (1) {
        if (checkchinhphuong(a)) {
            return a;
        }
        else if (checkchinhphuong(b)) {
            return b;
        }
        a--;
        b++;
    }
}
void hanhdong1(int& HP1, int& M1) {
    if (HP1 < 200) {
        HP1 = int(HP1 * 1.3 + 0.999);
        M1 -= 150;
        hpmaxmin(HP1); tienmaxmin(M1);
    }
    else {
        HP1 = int(HP1 * 1.1 + 0.999);
        M1 -= 70;
        hpmaxmin(HP1); tienmaxmin(M1);
    }
}
void hanhdong2(int& EXP1, int& M1) {
    (EXP1 > 400) ? (M1 -= 120) : (M1 -= 200);
    EXP1 = int(EXP1 * 1.13 + 0.999);
    expmaxmin(EXP1); tienmaxmin(M1);
}

void hanhdong3(int& EXP1, int& M1) {
    (EXP1 < 300) ? (M1 -= 100) : (M1 -= 120);
    EXP1 = int(EXP1 * 0.9 + 0.999);
    expmaxmin(EXP1); tienmaxmin(M1);
}
void hanhdong(int& HP1, int& M1, int& EXP1) {
    int dem = 0;
    int moc = M1;
     while ((moc - M1) <= int(moc / 2.0 + 0.999)) {
        switch (dem % 3 + 1) {
        case 1: {
            hanhdong1(HP1, M1);
            dem++;
            break;
        }
        case 2: {
            hanhdong2(EXP1, M1);
            dem++;
            break;
        }

        case 3: {
            hanhdong3(EXP1, M1);
            dem++;
            break;
        }
        }
    } 
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2>99) return -99;
    float p1 = 0, p2 = 0, p3 = 0;
    //con duong 1
    int s = sos(EXP1);
    if (s <= EXP1) p1 = 1;
    else {
        p1 = (1.0 * EXP1 / s + 80) / 123;
    }
    //con duong 2
    if (E2 & 1) {
        hanhdong(HP1, M1, EXP1);

    }
    else {
        hanhdong1(HP1, M1);
        if (M1 > 0)
            hanhdong2(EXP1, M1);
        if (M1 > 0)
            hanhdong3(EXP1, M1);
    }

    HP1 = int(HP1 * 0.83 + 0.999);
    EXP1 = int(EXP1 * 1.17 + 0.999);
    hpmaxmin(HP1); expmaxmin(EXP1); tienmaxmin(M1);
    int s2 = sos(EXP1);
    if (EXP1 >= s2) p2 = 1;
    else p2 = (1.0 * EXP1 / s2 + 80) / 123;
    //con duong 3
    float mp3[10] = { 0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11 };
    int r = E2;
    if (E2 > 9) r = ((E2 / 10) + (E2 % 10)) % 10;
    p3 = mp3[r];
    expmaxmin(EXP1); hpmaxmin(HP1); tienmaxmin(M1);
    if (p1 == 1.0 && p2 == 1.0 && p3 == 1.0) EXP1 = int(EXP1 * 0.75 + 0.999);
    else {
        float vali = (p1 + p2 + p3) / 3;
        if (vali < 0.5) {
            HP1 = int(HP1 * 0.85 + 0.999);
            EXP1 = int(EXP1 * 1.15 + 0.999);
        }
        else {
            HP1 = int(HP1 * 0.9 + 0.999);
            EXP1 = int(EXP1 * 1.2 + 0.999);
        }
    }
    expmaxmin(EXP1); hpmaxmin(HP1); tienmaxmin(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int max(int a, int b) {
    if (a > b) return a;
    return b;
}
int tinhso(int a) {
    while (a > 9) {
        a = (a % 10) + (a / 10);
    }
    return a;
}
int bunbo(int a, int b) {
    int m = 0;
    if ((a + b) > 10) m = (a + b - 9);
    return m;
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (E3 < 0 || E3>99) return -99;
    int cao = 0, thap = 0, a = 0, b = 0;
    int matran[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matran[i][j] = (((E3 * j) + (i * 2)) * (i - j));
            if (matran[i][j] > (E3 * 2)) cao++;
            if (matran[i][j] < (-E3)) thap++;
        }
    a = tinhso(cao); b = tinhso(thap);
    }

    int diem = -10000;
    int taxi = matran[a][b];
    //duong cheo chinh
    if ((a - b) <= 0) {
        for (int i = 0; i <= 9 - (b - a); i++) {
            diem = max(diem, matran[i][i + a - b]);
        }
    }
    else {
        for (int i = 0; i <= 9 - (a - b); i++) {
            diem = max(diem, matran[i + (a - b)][i]);
        }
    }
    if ((a + b) <= 9) {
        for (int i = 0; i <= (a + b); i++) {
            diem = max(diem, matran[i][a + b - i]);
        }
    }
    else {
        for (int i = (a + b) - 9; i <= 9; i++) {
            diem = max(diem, matran[i][a + b - i]);
        }
    }
    if (abs(taxi) > diem) {
        EXP1 = int(EXP1 * 0.88 + 0.999);
        EXP2 = int(EXP2 * 0.88 + 0.999);
        HP1 = int(HP1 * 0.9 + 0.999);
        HP2 = int(HP2 * 0.9 + 0.999);
        expmaxmin(EXP1); expmaxmin(EXP2); hpmaxmin(HP1); hpmaxmin(HP2);
        return int(taxi);
    }
    else {
        EXP1 = int(EXP1 * 1.12 + 0.999);
        EXP2 = int(EXP2 * 1.12 + 0.999);
        HP1 = int(HP1 * 1.1 + 0.999);
        HP2 = int(HP2 * 1.1 + 0.999);
        expmaxmin(EXP1); expmaxmin(EXP2); hpmaxmin(HP1); hpmaxmin(HP2);
        return int(diem);
    }
    return -1;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    char se[100];
    int km;
    for (km = 0; email[km] != '@' ; ++km) {
        se[km] = email[km];
    }
    se[km] = '\0';
    int dem = 0;
    while (s[dem] != '\0') { dem++; }
    // It hon 8 ki tu
    if (dem < 8) return -1;
    //Nhieu hon 20 ki tu
    if (dem > 20) return -2;
    //trong s co e
    for (int i = 0; s[i] != '\0'; i++) {
        for (int j = 0; se[j] != '\0'; j++) {
            if (s[i + j] != se[j]) break;
            if (s[i + j] == se[j] && se[j + 1] != '\0') continue;
            return -(300 + i);
        }
    }

    //2 ki tu lien ke
    for (int i = 0; s[i + 2] != '\0'; i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) return -(400 + i);
    }
    //Ki tu dac biet
    bool bruh = 0;
    char kitudacbiet[5] = { '@', '#', '%', '$','!'};
    for (int i = 0; s[i] != '\0'; i++) {
        for (int j = 0; j < 5; j++) {
            if (s[i] == kitudacbiet[j]) {
                goto tieptuc;
            }
        }
    }
return -5;
tieptuc:
// Ki tu ben ngoai
for (int i = 0; s[i] != '\0'; i++) {
    if ((s[i] < 'A' || s[i]>'Z') && (s[i] < 'a' || s[i]>'z') && (s[i] < 35 || s[i]>38) && (s[i] != 33)&&(s[i]!=64) && (s[i]<'0' || s[i]>'9')) {
        return i;
    }
}
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int dodai[100] = { 0 }; int soluong[100] = { 0 }; int vitri[100] = { 0 };
    for (int i = 0; i < num_pwds; i++) {
        dodai[i] = strlen(arr_pwds[i]);
        vitri[i] = i;
    }
    for (int i = 0; i < num_pwds; i++) {
        soluong[i] = 1;
        for (int j = 0; j < num_pwds; j++) {
            if (i == j) continue;
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
                soluong[i]++;
        }
    }
    int km = 0;
    for (int i = 0; i < num_pwds; i++) {
        for (int j = 0; j < num_pwds; j++) {
            if (soluong[j] > soluong[km]) {
                km = j; break;
            }
            if ((soluong[j] == soluong[km]) && strlen(arr_pwds[j]) > strlen(arr_pwds[km])) {
                km = j;
            }
        }
    }

    return km;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////