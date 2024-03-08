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

int luiSoEXP(int EXP) {
    if (EXP > 600) {
        return 600;
    }
    else if (EXP < 0) {
        return 0;
    }
    else
        return EXP;
}

int luiSoHP(int HP) {
    if (HP > 666) {
        return 666;
    }
    else if (HP < 0) {
        return 0;
    }
    else
        return HP;
}

int luiSoM(int M) {
    if (M > 3000) {
        return 3000;
    }
    else if (M < 0) {
        return 0;
    }
    else
        return M;
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0)
            exp2 = luiSoEXP(ceil(exp2 + 29));
        else if (e1 == 1)
            exp2 = luiSoEXP(ceil(exp2 + 45));
        else if (e1 == 2)
            exp2 = luiSoEXP(ceil(exp2 + 75));
        else if (e1 == 3)
            exp2 = luiSoEXP(ceil(exp2 + 29 + 45 + 75));

        int d = e1 * 3 + exp1 * 7;

        if (d % 2 == 0) {
            exp1 = luiSoEXP(ceil(exp1 + (d / 200)));
        }
        else {
            exp1 = luiSoEXP(ceil(exp1 - (d / 100)));
        }
    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 = luiSoEXP(ceil(exp2 + (e1 / 4 + 0.999) + 19));
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 = luiSoEXP(ceil(exp2 + (e1 / 9 + 0.999) + 21));
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 = luiSoEXP(ceil(exp2 + (e1 / 16 + 0.999) + 17));
        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = luiSoEXP(ceil(exp2 + (e1 / 4 + 0.999) + 19));
            if (exp2 > 200) {
                exp2 = luiSoEXP(ceil(exp2 + (e1 / 9 + 0.999) + 21));
            }
        }
        else {
            exp2 = luiSoEXP(ceil(exp2 + (e1 / 4 + 0.999) + 19));
            exp2 = luiSoEXP(ceil(exp2 + (e1 / 9 + 0.999) + 21));
            if (exp2 > 400) {
                exp2 = luiSoEXP(ceil(exp2 + (e1 / 16 + 0.999) + 17));
            }
            exp2 = luiSoEXP(ceil(exp2 * 1.15));
        }

        exp1 = luiSoEXP(exp1 - e1);
    }
    else
        return -99;

    return exp1 + exp2;
}

// Task 2
int soChinhPhuong(int n) {
    int canBacHai = sqrt(n);
    return (canBacHai * canBacHai == n);
}

int soChinhPhuongGanEXP1Nhat(int EXP1) {
    if (soChinhPhuong(EXP1)) {
        return EXP1;
    }
    else {
        int S1 = 0, S2 = 0;

        for (int i = EXP1; i >= 0; --i) {
            if (soChinhPhuong(i)) {
                S1 = i;
                break;
            }
        }

        for (int i = EXP1; ; ++i) {
            if (soChinhPhuong(i)) {
                S2 = i;
                break;
            }
        }

        if (EXP1 - S1 < S2 - EXP1) {
            return S1;
        }
        else {
            return S2;
        }
    }
}

float xacSuat(float EXP1, float S) {
    if (EXP1 >= S) {
        return 1.0;
    }
    else
        return (EXP1 / S + 80.0) / 123.0;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
        return -99;

    float P1 = 1.0, P2 = 1.0, P3 = 1.0;

    int oldM1 = M1;

    while (P1 == 1.0 && P2 == 1.0 && P3 == 1.0) {
        //Con duong 1
        int S = soChinhPhuongGanEXP1Nhat(EXP1);

        P1 = xacSuat(EXP1, S);

        //Con duong 2
        if (HP1 < 200) {
            HP1 = luiSoHP(ceil(HP1 + (0.3 * HP1)));
            M1 = luiSoM(ceil(M1 - 150));
        }
        else {
            HP1 = luiSoHP(ceil(HP1 + (0.1 * HP1)));
            M1 = luiSoM(ceil(M1 - 70));
        }

        if (EXP1 < 400) {
            M1 = luiSoM(ceil(M1 - 200));
            EXP1 = luiSoEXP(ceil(EXP1 * 1.13));
        }
        else {
            M1 = luiSoM(ceil(M1 - 120));
            EXP1 = luiSoEXP(ceil(EXP1 * 1.13));
        }

        if (EXP1 < 300) {
            M1 = luiSoM(ceil(M1 - 100));
            EXP1 = luiSoEXP(ceil(EXP1 * 0.9));
        }
        else {
            M1 = luiSoM(ceil(M1 - 120));
            EXP1 = luiSoEXP(ceil(EXP1 * 0.9));
        }

        int sumM1 = oldM1 - M1;

        if (E2 % 2 != 0) {
            if (sumM1 < 0.5 * oldM1) {
                if (HP1 < 200) {
                    HP1 = luiSoHP(ceil(HP1 + (0.3 * HP1)));
                    M1 = luiSoM(ceil(M1 - 150));
                }
                else {
                    HP1 = luiSoHP(ceil(HP1 + (0.1 * HP1)));
                    M1 = luiSoM(ceil(M1 - 70));
                }

                sumM1 = oldM1 - M1;

                if (sumM1 < 0.5 * oldM1) {
                    if (EXP1 < 400) {
                        M1 = luiSoM(ceil(M1 - 200));
                        EXP1 = luiSoEXP(ceil(EXP1 * 1.13));
                    }
                    else {
                        M1 = luiSoM(ceil(M1 - 120));
                        EXP1 = luiSoEXP(ceil(EXP1 * 1.13));
                    }

                    sumM1 = oldM1 - M1;

                    if (sumM1 < 0.5 * oldM1) {
                        if (EXP1 < 300) {
                            M1 = luiSoM(ceil(M1 - 100));
                            EXP1 = luiSoEXP(ceil(EXP1 * 0.9));
                        }
                        else {
                            M1 = luiSoM(ceil(M1 - 120));
                            EXP1 = luiSoEXP(ceil(EXP1 * 0.9));
                        }
                    }
                }
            }
        }

        HP1 = luiSoHP(ceil(HP1 * 0.83));

        EXP1 = luiSoEXP(ceil(EXP1 * 1.17));

        P2 = xacSuat(EXP1, S);

        //Con duong 3
        int i = 0;

        int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };

        if (E2 >= 0 && E2 <= 9) {
            i = E2;
        }
        else {
            int sum = (E2 / 10) + (E2 % 10);

            i = sum % 10;
        }

        P3 = P[i] / 100;
    }

    float P = (P1 + P2 + P3) / 3;

    if (P < 0.5) {
        HP1 = luiSoHP(ceil(0.85 * HP1));
        EXP1 = luiSoEXP(ceil(1.15 * EXP1));
    }
    else {
        HP1 = luiSoHP(ceil(0.9 * HP1));
        EXP1 = luiSoEXP(ceil(1.2 * EXP1));
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;
    int a = 0, b = 0;
    int taxiMaTran[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; j++) {
            taxiMaTran[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taxiMaTran[i][j] > E3 * 2)
                a++;
            if (taxiMaTran[i][j] < -E3)
                b++;
        }
    }

    while (a / 10 >= 1)
        a = a / 10 + a % 10;
    while (b / 10 >= 1)
        b = b / 10 + b % 10;

    int traiTren = INT_MIN;
    int traiDuoi = INT_MIN;
    int phaiTren = INT_MIN;
    int phaiDuoi = INT_MIN;

    //duong cheo trai tren
    for (int i = a, j = b; i >= 0 && j >= 0; --i, --j) {
        if (taxiMaTran[i][j] > traiTren) {
            traiTren = taxiMaTran[i][j];
        }
    }

    //duong cheo trai duoi
    for (int i = a, j = b; i < 10 && j < 10; ++i, ++j) {
        if (taxiMaTran[i][j] > traiDuoi) {
            traiDuoi = taxiMaTran[i][j];
        }
    }

    //duong cheo phai tren
    for (int i = a, j = b; i >= 0 && j < 10; --i, ++j) {
        if (taxiMaTran[i][j] > phaiTren) {
            phaiTren = taxiMaTran[i][j];
        }
    }

    //duong cheo phai duoi
    for (int i = a, j = b; i < 10 && j >= 0; ++i, --j) {
        if (taxiMaTran[i][j] > phaiDuoi) {
            phaiDuoi = taxiMaTran[i][j];
        }
    }

    int giaTriLonNhat;

    if ((traiTren > traiDuoi) && (traiTren > phaiTren) && (traiTren > phaiDuoi))
        giaTriLonNhat = abs(traiTren);
    else if ((traiDuoi > phaiTren) && (traiDuoi > phaiDuoi))
        giaTriLonNhat = abs(traiDuoi);
    else if (phaiTren > phaiDuoi)
        giaTriLonNhat = abs(phaiTren);
    else
        giaTriLonNhat = abs(phaiDuoi);

    if (abs(taxiMaTran[a][b]) > giaTriLonNhat) {
        EXP1 = luiSoEXP(ceil(0.88 * EXP1));
        HP1 = luiSoHP(ceil(0.9 * HP1));
        EXP2 = luiSoEXP(ceil(0.88 * EXP2));
        HP2 = luiSoHP(ceil(0.9 * HP2));
        return taxiMaTran[a][b];
    }
    else {
        EXP1 = luiSoEXP(ceil(1.12 * EXP1));
        HP1 = luiSoHP(ceil(1.1 * HP1));
        EXP2 = luiSoEXP(ceil(1.12 * EXP2));
        HP2 = luiSoHP(ceil(1.1 * HP2));
        return giaTriLonNhat;
    }
}

// Task 4
bool kyTuDacBiet(char s) {
    return s == '!' || s == '@' || s == '#' || s == '$' || s == '%';
}

int checkPassword(const char* s, const char* email) {
    const char* mienEmail = strchr(email, '@');
    int se = mienEmail - email;

    int s_length = strlen(s);
    if (s_length < 8) {
        return -1;
    }
    else if (s_length > 20) {
        return -2;
    }

    for (int i = 0; i <= s_length - se; i++) {
        bool s_chua_se = true;
        for (int j = 0; j < se; ++j) {
            if (s[i + j] != email[j]) {
                s_chua_se = false;
                break;
            }
        }
        if (s_chua_se)
            return -(300 + i);
    }

    for (int i = 0; i < s_length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
            return -(400 + i);
    }

    bool chua_ky_tu_dac_biet = false;
    for (int i = 0; i < s_length; ++i) {
        if (kyTuDacBiet(s[i])) {
            chua_ky_tu_dac_biet = true;
        }
    }
    if (chua_ky_tu_dac_biet)
        return -5;

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int matKhauDaiNhat = 0;
    int xuatHienNhieuNhat = 0;
    int viTriDungCuaMatKhau = -1;

    for (int i = 0; i < num_pwds; ++i) {
        const char* matKhauHienTai = arr_pwds[i];
        int doDaiMatKhauHienTai = strlen(matKhauHienTai);

        int count = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[j], matKhauHienTai) == 0)
                count++;
        }

        if ((count > xuatHienNhieuNhat) || (count == xuatHienNhieuNhat && doDaiMatKhauHienTai > matKhauDaiNhat)) {
            matKhauDaiNhat = doDaiMatKhauHienTai;
            xuatHienNhieuNhat = count;
            viTriDungCuaMatKhau = i;
        }
    }

    return viTriDungCuaMatKhau;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////