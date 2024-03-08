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
    int& E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
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
void check(int& a, int b, int c)
{
    if (a > b)a = b;
    if (a < c)a = c;
}
int firstMeet(int& exp1, int& exp2, int e1) {

    if (e1 > 99 || e1 < 0) return -99;
    check(exp2, 600, 0);
    check(exp1, 600, 0);
    switch (e1) {
    case 0:
        exp2 += 29;
        break;
    case 1:
        exp2 += 45;
        break;
    case 2:
        exp2 += 75;
        break;
    case 4 ... 19:
        exp2 += ceil(float(e1) / 4 + 19);
        break;
    case 20 ... 49:
        exp2 += ceil(float(e1) / 9 + 21);
        break;
    case 50 ... 65:
        exp2 += ceil(float(e1) / 16 + 17);
        break;
    case 66 ... 79:
        exp2 += ceil(float(e1) / 4 + 19);
        if (exp2 > 200) exp2 += ceil(float(e1) / 9) + 21;
        break;
    case 80 ... 99:
        exp2 += ceil(float(e1) / 4) + 19 + ceil(float(e1) / 9) + 21;
        if (exp2 > 400) {
            exp2 += ceil(float(e1) / 16) + 17;
            exp2 += ceil(float(exp2) * 0.15);
        }
        break;
    default:exp2 += 149;
    }
    check(exp2, 600, 0);
    if (e1 < 4)
    {
        int d = e1 * 3 + exp1 * 7;
        if (d % 2 == 0) exp1 += ceil(float(d) / 200);
        else exp1 -= floor(float(d) / 100);
        check(exp1, 600, 0);
        return exp1 + exp2;
    }
    exp1 -= e1;
    check(exp1, 600, 0);
    return exp1 + exp2;
}
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    float p1, p2, p3, s, a[10] = { 0.32, 0.47, 0.28, 0.79, 1, 0.50, 0.22, 0.83, 0.64, 0.11 };
    ////////////////////////////////   way1   //////////////////////////////
    if (E2 < 0 || E2>99) return -99;
    check(HP1, 666, 0);
    check(EXP1, 600, 0);
    check(M1, 3000, 0);
    s = round(sqrt(EXP1)) * round(sqrt(EXP1));
    if (EXP1 >= s) p1 = 1;
    else p1 = (EXP1 / s + 80) / 123;
    ////////////////////////////////   way2   //////////////////////////////
    if (E2 % 2 == 0)s = 1;
    else s = float(M1) / 2;
    if (M1 != 0)
        do {
            if (HP1 < 200) {
                HP1 += ceil(float(HP1) * 0.3 - 0.000001); check(HP1, 666, 0);
                M1 -= 150;
            }
            else {
                HP1 += ceil(float(HP1) * 0.1 - 0.000001);
                M1 -= 70;
                check(HP1, 666, 0);
            }
            if (M1 < s) break;

            if (EXP1 < 400) M1 -= 200;
            else  M1 -= 120;
            EXP1 += ceil(float(EXP1) * 0.13 - 0.000001);
            check(EXP1, 600, 0);
            if (M1 < s) break;

            if (EXP1 < 300)  M1 -= 100;
            else  M1 -= 120;
            EXP1 = ceil(float(EXP1) * 0.9 - 0.000001);

        } while (M1 >= s && s != 1);

        check(M1, 3000, 0);
        HP1 = ceil(float(HP1) * 0.83 - 0.000001);
        EXP1 += ceil(float(EXP1) * 0.17 - 0.000001);
        check(EXP1, 600, 0);
        s = round(sqrt(EXP1)) * round(sqrt(EXP1));
        if (EXP1 >= s) p2 = 1;
        else p2 = (EXP1 / s + 80) / 123;
        ////////////////////////////////   way3   //////////////////////////////
        int in = (E2 / 10 + E2 % 10) % 10;
        p3 = a[in];
        if (p1 == p2 && p2 == p3 && p3 == 1) { EXP1 = ceil(float(EXP1) * 0.75 - 0.000001); check(EXP1, 600, 0); }
        else {
            s = (p1 + p2 + p3) / 3;
            if (s < 0.5) {
                EXP1 += ceil(float(EXP1) * 0.15 - 0.000001);
                check(EXP1, 600, 0);
                HP1 = ceil(float(HP1) * 0.85 - 0.000001);
            }
            else {
                EXP1 += ceil(float(EXP1) * 0.2 - 0.000001);
                check(EXP1, 600, 0);
                HP1 = ceil(float(HP1) * 0.9 - 0.000001);
            }
        }
        return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (E3 < 0 || E3>99) return -99;
    check(EXP2, 600, 0);
    check(EXP1, 600, 0);
    check(HP1, 666, 0);
    check(HP2, 666, 0);
    int arr[10][10], rows = 0, cols = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            arr[i][j] = (E3 - 2) * i * j - E3 * j * j + 2 * i * i;
            if (arr[i][j] > E3 * 2) rows += 1;
            if (arr[i][j] < -E3)    cols += 1;
        }
    rows = (rows / 10 + rows % 10) / 10 + (rows / 10 + rows % 10) % 10;
    cols = (cols / 10 + cols % 10) / 10 + (cols / 10 + cols % 10) % 10;
    int max_diag_1, max_diag_2 = arr[rows][cols];
    if (cols > rows) max_diag_1 = arr[0][cols - rows];
    else max_diag_1 = arr[9][9 - rows + cols];
    for (int d = 0; rows + d < 10 && cols - d >= 0; ++d) {
        max_diag_2 = max(max_diag_2, arr[rows + d][cols - d]);
    }
    for (int d = 0; rows - d >= 0 && cols + d < 10; ++d) {
        max_diag_2 = max(max_diag_2, arr[rows - d][cols + d]);
    }
    int kq = max(max_diag_1, max_diag_2), cs1 = 110, cs2 = 112;
    if (kq < abs(arr[rows][cols])) {
        cs1 = 90;
        cs2 = 88;
        kq = arr[rows][cols];
    }
    HP1 = ceil(float(HP1) * float(cs1) / 100 - 0.000001);
    check(HP1, 666, 0);
    EXP1 = ceil(float(EXP1) * float(cs2) / 100 - 0.0000001);
    check(EXP1, 600, 0);
    HP2 = ceil(float(HP2) * float(cs1) / 100 - 0.000001);
    check(HP2, 666, 0);
    EXP2 = ceil(float(EXP2) * float(cs2) / 100 - 0.000001);
    check(EXP2, 600, 0);
    return kq;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    char arr[5] = { '#','$','!','%','@' }, kt[1];
    string s1;
    int l = strlen(email), dem = -1;
    for (int i = 0; i < l; i++) {
        if (email[i] == '@') break;
        s1.push_back(email[i]);
    }
    const char* se = s1.c_str();
    l = strlen(s);
    if (l < 8)   return -1;
    if (l > 20)  return -2;
    const char* found = strstr(s, se);
    if (found != nullptr) return -static_cast<int>(found - s) - 300;
    for (int i = 0; i < l - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])return -(400 + i);
    }
    for (int i = 0; i < l; i++) {
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '!' || s[i] == '%')) {
            dem = i;
            break;
        }
    }
    int p = 0;
    for (int i = 0; i < 5; i++) {

        found = strchr(s, arr[i]);
        if (found != nullptr && dem == -1)    return -10;
        else if (found == nullptr) p++;
    }
    if (p == 5) return -5;
    return dem;
}

// Task 5

int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int index[30], cnt[30] = {}, dem = 0, kt = 0, maxlen = 0, indexs = 0;
    const char* s[30];
    for (int i = 0; i < num_pwds; i++) {
        int c = 0;
        for (int j = 0; j < dem; j++)   if (strcmp(arr_pwds[i], s[j]) == 0) { c++; break; };
        if (c == 0) {
            for (int j = 0; j < num_pwds; j++) if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) c++;
            cnt[dem] = c;
            s[dem] = arr_pwds[i];
            index[dem] = i;
            dem++;
        }
    }
    for (int i = 0; i < dem; i++) {
        if (cnt[i] > kt) {
            kt = cnt[i];
            maxlen = strlen(s[i]);
            indexs = index[i];
        }
        else if (kt == cnt[i] && maxlen < strlen(s[i])) {
            kt = cnt[i];
            indexs = index[i];
            maxlen = strlen(s[i]);
        }
    }
    return indexs;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////