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
//Checking HP bound
int verifyHP(int HP)
{
    if (HP >= 0 && HP <= 666) return HP;
    else if (HP < 0) return 0;
    else return 666;
}

//Checking EXP bound
int varifyEXP(int exp)
{
    if (exp >= 0 && exp <= 600) return exp;
    else if (exp < 0)   return 0;
    else return 600;
}

//Checking Money Bound
int varifyM1(int M)
{
    if (M >= 0 && M <= 3000) return M;
    else if (M < 0)   return 0;
    else return 3000;
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1)
{
    int dung = 0;
    //check bound of ini-value
    exp1 = varifyEXP(exp1);
    exp2 = varifyEXP(exp2);
    if (e1 < 0 || e1 > 99) return -99;
    else
    {
        if (e1 >= 0 && e1 <= 3)
        {
            //Enter TH 1
            if (e1 == 0)
            {
                dung = exp2 + 29;
                exp2 = varifyEXP(dung);
            }
            else if (1 == e1)
            {
                dung = exp2 + 45;
                exp2 = varifyEXP(dung);
            }
            else if (2 == e1)
            {
                dung = exp2 + 75;
                exp2 = varifyEXP(dung);
            }
            else
            {
                dung = exp2 + 29 + 45 + 75;
                exp2 = varifyEXP(dung);
            }

            int D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0)
            {
                dung = ceil(exp1 + D * 1.0 / 200);
                exp1 = varifyEXP(dung);
            }
            else
            {
                dung = ceil(exp1 - D * 1.0 / 100);
                exp1 = varifyEXP(dung);
            }
            return exp1 + exp2;
            //Exit TH1
        }
        else
        {
            //Enter TH2
            if (e1 <= 19)
            {
                dung = ceil(e1 * 1.0 / 4 + 19 + exp2);
                exp2 = varifyEXP(dung);
            }
            else if (e1 <= 49)
            {
                dung = ceil(e1 * 1.0 / 9 + 21 + exp2);
                exp2 = varifyEXP(dung);
            }
            else if (e1 <= 65)
            {
                dung = ceil(e1 * 1.0 / 16 + 17 + exp2);
                exp2 = varifyEXP(dung);
            }
            else if (e1 <= 79)
            {
                dung = ceil(e1 * 1.0 / 4 + 19 + exp2);
                exp2 = varifyEXP(dung);
                if (exp2 > 200)
                {
                    dung = ceil(e1 * 1.0 / 9 + 21 + exp2);
                    exp2 = varifyEXP(dung);
                }
            }
            else
            {
                dung = ceil(e1 * 1.0 / 4 + 19 + exp2);
                exp2 = varifyEXP(dung);
                dung = ceil(e1 * 1.0 / 9 + 21 + exp2);
                exp2 = varifyEXP(dung);
                if (exp2 > 400)
                {
                    dung = ceil(e1 * 1.0 / 16 + 17 + exp2);
                    exp2 = varifyEXP(dung);
                    dung = ceil(exp2 * 115 / 100.0);
                    exp2 = varifyEXP(dung);
                }
            }
            dung = exp1 - e1;
            exp1 = varifyEXP(dung);
            return exp1 + exp2;
            //Exit TH2
        }
    }
}

// Task 2
int findS(int EXP1)
{
    int S = 0;

    if (EXP1 == 1) S = 1;
    else if (EXP1 == 0) S = 0;
    else
    {
        int soL = pow(ceil(sqrt(EXP1 * 1.0)), 2);
        int soB = pow((ceil(sqrt(EXP1 * 1.0)) - 1), 2);
        if ((EXP1 - soB) < (soL - EXP1)) S = soB;
        else S = soL;
    }
    return S;
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    //Check bound of initial value
    HP1 = verifyHP(HP1);
    EXP1 = varifyEXP(EXP1);
    M1 = varifyM1(M1);

    int dung = 0;

    if (E2 < 0 || E2>99) return -99;
    else
    {
        double P1 = 0, P2 = 0;
        int S = findS(EXP1);
        if (EXP1 >= S) P1 = 1;
        else
        {
            P1 = (EXP1 * 1.0 / S + 80) * 1.0 / 123;
        }
        double boundMoney = M1 / 2.0;
        int spend = 0;
        while (!(double(spend) > boundMoney) && M1 != 0)
        {
            if (HP1 < 200)
            {
                dung = ceil(HP1 * 3 / 10.0 + HP1);
                HP1 = verifyHP(dung);
                if (M1 > 150)
                {
                    spend += 150;
                    M1 -= 150;
                }
                else
                {
                    spend += M1;
                    M1 = 0;
                    if (!(E2 % 2)) break;
                }
                if (double(spend) > boundMoney && (E2 % 2)) break;
            }
            else
            {
                dung = ceil(HP1 / 10.0 + HP1);
                HP1 = verifyHP(dung);
                if (M1 > 70)
                {
                    spend += 70;
                    M1 -= 70;
                }
                else
                {
                    spend += M1;
                    M1 = 0;
                    if (!(E2 % 2)) break;
                }
                if (double(spend) > boundMoney && (E2 % 2)) break;
            }

            if (EXP1 < 400)
            {
                dung = ceil(EXP1 * 113 / 100.0);
                EXP1 = varifyEXP(dung);
                if (M1 > 200)
                {
                    spend += 200;
                    M1 = M1 - 200;
                }
                else
                {
                    spend += M1;
                    M1 = 0;
                    if (!(E2 % 2)) break;
                }
                if (double(spend) > boundMoney && (E2 % 2)) break;
            }
            else
            {
                dung = ceil(EXP1 * 113 / 100.0);
                EXP1 = varifyEXP(dung);
                if (M1 > 120)
                {
                    spend = spend + 120;
                    M1 = M1 - 120;
                }
                else
                {
                    spend += M1;
                    M1 = 0;
                    if (!(E2 % 2)) break;
                }
                if (double(spend) > boundMoney && (E2 % 2)) break;
            }
            if (EXP1 < 300)
            {
                dung = ceil(EXP1 * 9 / 10.0);
                EXP1 = varifyEXP(dung);
                if (M1 > 100)
                {
                    spend = spend + 100;
                    M1 = M1 - 100;
                }
                else
                {
                    spend += M1;
                    M1 = 0;
                    if (!(E2 % 2)) break;
                }
                if (double(spend) > boundMoney && (E2 % 2)) break;
            }
            else
            {
                dung = ceil(EXP1 * 9 / 10.0);
                EXP1 = varifyEXP(dung);
                if (M1 > 120)
                {
                    spend += 120;
                    M1 -= 120;
                }
                else
                {
                    spend += M1;
                    M1 = 0;
                    if (!(E2 % 2)) break;
                }
                if (double(spend) > boundMoney && (E2 % 2)) break;
            }

            if (!(E2 % 2))  break;
        }

        dung = ceil(HP1 - HP1 * 17 / 100.0);
        HP1 = verifyHP(dung);
        dung = ceil(EXP1 + EXP1 * 17 / 100.0);
        EXP1 = varifyEXP(dung);

        S = findS(EXP1);
        if (EXP1 >= S) P2 = 1;
        else
        {
            P2 = (EXP1 * 1.0 / S + 80) * 1.0 / 123;
        }

        double P3 = 0;
        double P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        if (E2 < 10) P3 = P[E2];
        else
        {
            int b3 = (E2 / 10 + E2 % 10) % 10;
            P3 = P[b3];
        }

        P3 = P3 / 100.0;

        if (1 == P1 && 1 == P2 && 1 == P3)
        {
            dung = ceil(EXP1 * 75 / 100.0);
            EXP1 = varifyEXP(dung);
        }
        else
        {
            double TB = (P1 + P2 + P3) / 3.0;
            if (TB < 0.50)
            {
                dung = ceil(HP1 * 85 / 100.0);
                HP1 = verifyHP(dung);
                dung = ceil(EXP1 * 115 / 100.0);
                EXP1 = varifyEXP(dung);
            }
            else
            {
                dung = ceil(HP1 * 9 / 10.0);
                HP1 = verifyHP(dung);
                dung = ceil(EXP1 * 12 / 10.0);
                EXP1 = varifyEXP(dung);
            }
        }
        return HP1 + EXP1 + M1;
    }
}

// Task 3
bool vuotMang(int x, int y)
{
    if (x < 0 || y < 0) return 1;
    if (x > 9 || y > 9) return 1;
    return 0;
}
int timDiem(int arr[10][10], int x, int y)
{
    int max = arr[x][y];
    for (int i = x, j = y; !vuotMang(i, j); i++, j++)
    {
        if (arr[i][j] > max) max = arr[i][j];
    }
    for (int i = x, j = y; !vuotMang(i, j); i--, j--)
    {
        if (arr[i][j] > max) max = arr[i][j];
    }
    for (int i = x, j = y; !vuotMang(i, j); i--, j++)
    {
        if (arr[i][j] > max) max = arr[i][j];
    }
    for (int i = x, j = y; !vuotMang(i, j); i++, j--)
    {
        if (arr[i][j] > max) max = arr[i][j];
    }
    return max;
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // Check ini-value

    HP1 = verifyHP(HP1);
    EXP1 = varifyEXP(EXP1);
    HP2 = verifyHP(HP2);
    EXP2 = varifyEXP(EXP2);

    int dung = 0;
    if (E3 < 0 || E3>99) return -99;
    else
    {
        int arr[10][10]{};
        int demL = 0, demB = 0;

        for (int x = 0; x < 10; x++)
        {
            for (int y = 0; y < 10; y++)
            {
                arr[x][y] = ((E3 * y) + (x * 2)) * (x - y);
                if (arr[x][y] > 2 * E3) demL++;
                if (arr[x][y] < -E3) demB++;
            }
        }

        int x = (demL / 10 + demL % 10) / 10 + (demL / 10 + demL % 10) % 10;
        int y = (demB / 10 + demB % 10) / 10 + (demB / 10 + demB % 10) % 10;
        int D = abs(timDiem(arr, x, y));

        if (!(abs(arr[x][y]) > D))
        {
            dung = ceil(EXP1 * 112 / 100.0);
            EXP1 = varifyEXP(dung);
            dung = ceil(EXP2 * 112 / 100.0);
            EXP2 = varifyEXP(dung);
            dung = ceil(HP1 * 11 / 10.0);
            HP1 = verifyHP(dung);
            dung = ceil(HP2 * 11 / 10.0);
            HP2 = verifyHP(dung);
            return D;
        }
        else
        {
            dung = ceil(EXP1 * 88 / 100.0);
            EXP1 = varifyEXP(dung);
            dung = ceil(EXP2 * 88 / 100.0);
            EXP2 = varifyEXP(dung);
            dung = ceil(HP1 * 9 / 10.0);
            HP1 = verifyHP(dung);
            dung = ceil(HP2 * 9 / 10.0);
            HP2 = verifyHP(dung);
            return arr[x][y];
        }
    }
}

int timChuoi(const char* s, const char* se)
{
    const char* found = strstr(s, se);
    if (found == NULL) return -100;
    return int(found - s);
}

int lienTiep(const char* s)
{
    for (int i = 0; i < strlen(s) - 2; i++)
    {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) return i;
    }
    return -100;
}

bool dacBiet(const char* s)
{
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') return 1;
    }
    return 0;
}
bool dacBiet(const char* s, int i)
{
    if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') return 1;
    return 0;
}
bool trongKhoang(const char* s, int i)
{
    if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A'
        && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))) return 0;
    return 1;
}
int chuoiLa(const char* s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!(dacBiet(s, i) || trongKhoang(s, i))) return i;
    }
    return -1;
}
int checkPassword(const char* s, const char* email) {
    std::string contain{};
    std::stringstream samp(email);
    std::getline(samp, contain, '@');
    const char* se = contain.c_str();
    int size = strlen(s);
    if (!(size >= 8 && size <= 20))
    {
        return size < 8 ? -1 : -2;
    }
    int vitri = timChuoi(s, se);
    if (vitri != -100) return -(300 + vitri);
    vitri = lienTiep(s);
    if (vitri >= 0) return -(400 + vitri);
    if (!dacBiet(s)) return -5;
    vitri = chuoiLa(s);
    if (vitri != -1) return vitri;
    return -10;
}

bool chuoiXuatHien(const char* arr[200], int count, const char* s)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(s, arr[i]) == 0) return 1;
    }
    return 0;
}
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int tansuat = 0, count = 0;
    const char* arr[200]{};
    int soLanXuatHien[200]{};

    for (int i = 0; i < num_pwds; i++)
    {
        if (chuoiXuatHien(arr, count, arr_pwds[i])) continue;
        for (int j = i + 1; j < num_pwds; j++)
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) tansuat++;

        arr[count] = arr_pwds[i];
        soLanXuatHien[count] = tansuat;
        count++;
        tansuat = 0;
    }

    int XH = soLanXuatHien[0];
    const char* daiNhat = arr[0];

    for (int i = 0; i < count; i++)
    {
        if (XH < soLanXuatHien[i])
        {
            XH = soLanXuatHien[i];
            daiNhat = arr[i];
        }
    }

    for (int i = 0; i < count; i++)
        if (soLanXuatHien[i] == XH) daiNhat = strlen(arr[i]) > strlen(daiNhat) ? arr[i] : daiNhat;

    for (int i = 0; i < num_pwds; i++)
        if (strcmp(daiNhat, arr_pwds[i]) == 0) return i;

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////