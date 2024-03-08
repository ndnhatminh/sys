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

int check(int n, int sodau, int socuoi) {
    if (n < sodau) return sodau;
    else if (n > socuoi) return socuoi;
    else return n;
}

int tienM1(int m1) {
    if (m1 < 0) return 0;
    return m1;

}

int tong2sothanh1(int n) {
    if (n / 10 == 0) { return n; }
    else {
        int m = n;
        n = n % 10;
        m = (m - n) / 10;
        int kq = n + m;
        return tong2sothanh1(kq);
    }

}


int PHANNGUYEN(double x) {
    return static_cast<int>(floor(x));
}


int sochinhphuong(double x) {
    if (x == 0) return 1;
    else {
        double a = sqrt(x);
        if (a == PHANNGUYEN(a)) { return a * a; }
        else {
            int kq1 = PHANNGUYEN(a) * PHANNGUYEN(a);
            int kq2 = (PHANNGUYEN(a) + 1) * (PHANNGUYEN(a) + 1);
            if ((x - kq1) > (kq2 - x)) {

                return kq2;
            }
            else {

                return kq1;
            }
        }
    }
}
int lamtronlen(double a) {
    if (a - (int)a) return (int)a + 1;
    else return (int)a;
}
// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) { exp2 += 29; }
        else if (e1 == 1) { exp2 += 45; }
        else if (e1 == 2) { exp2 += 75; }
        else { exp2 += 29 + 45 + 75; }
        int d = e1 * 3 + exp1 * 7;
        if (d % 2 == 0) { exp1 += lamtronlen(d / 200.0); }
        else { exp1 = lamtronlen(exp1 - d * 0.01); }
    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) { exp2 = exp2 + lamtronlen(e1 / 4.0) + 19; }
        else if (e1 >= 20 && e1 <= 49) { exp2 = exp2 + lamtronlen(e1 / 9.0) + 21; }
        else if (e1 >= 50 && e1 <= 65) { exp2 = exp2 + lamtronlen(e1 / 16.0) + 17; }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 = exp2 + lamtronlen(e1 / 4.0) + 19;
            if (exp2 > 200) { exp2 = exp2 + lamtronlen(e1 / 9.0) + 21; }
        }
        else {
            exp2 = exp2 + lamtronlen(e1 / 4.0) + 19;
            exp2 = exp2 + lamtronlen(e1 / 9.0) + 21;
            if (exp2 > 400) {
                exp2 = (exp2 + lamtronlen(e1 / 16.0) + 17);
                exp2 = lamtronlen(exp2 * 1.15);
            }
        }
        exp1 = exp1 - e1;
    }
    if (exp1 > 600) { exp1 = 600; }
    if (exp2 > 600) { exp2 = 600; }
    if (exp1 < 0) { exp1 = 0; }
    if (exp2 < 0) { exp2 = 0; }

    return exp1 + exp2;
}
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {

    HP1 = check(HP1, 0, 999);
    EXP1 = check(EXP1, 0, 900);
    M1 = check(M1, 0, 2000);
    // TODO: Complete this function
    //duong 1
    int s = sochinhphuong(EXP1);
    double p1, p2, p3;
    if (EXP1 >= s) { p1 = 1; }
    else { p1 = ((EXP1 * 1.0 / s * 1.0) + 80) / 123.0; }

    //duong 2
    float  tienbandau = M1;
    float  tienmotnua = M1 / 2;


    if (E2 % 2 == 0) {
        if (M1 == 0) goto Nhayquaday;
        if (HP1 < 200) {
            HP1 += lamtronlen(HP1 * (30.0 / 100.0));
            M1 -= 150;
        }

        else {
            HP1 += lamtronlen(HP1 * (10.0 / 100.0));
            M1 -= 70;
        }

        M1 = tienM1(M1);
        if (M1 == 0) goto Nhayquaday;

        if (EXP1 < 400) {
            M1 = M1 - 200;
        }
        else { M1 = M1 - 120; }
        EXP1 = EXP1 + lamtronlen(EXP1 * (13.0 / 100));

        M1 = tienM1(M1);
        if (M1 == 0) goto Nhayquaday;

        if (EXP1 < 300) {
            M1 -= 100;
        }
        else {
            M1 -= 120;

        }
        EXP1 = lamtronlen(EXP1 - EXP1 * 10.0 / 100);

        tienM1(M1);


    Nhayquaday:
        HP1 = lamtronlen(HP1 - HP1 * 17.0 / 100);
        EXP1 = EXP1 + lamtronlen(EXP1 * 17.0 / 100);
        if (EXP1 > sochinhphuong(EXP1)) { p2 = 1; }
        else { p2 = ((EXP1 / sochinhphuong(EXP1)) + 80) / 123.0; }

    }
    else {

        while (1) {
            if (HP1 < 200) {
                HP1 = HP1 + lamtronlen(HP1 * (30.00 / 100));
                M1 -= 150;
            }
            else {
                HP1 = HP1 + lamtronlen(HP1 * (10.00 / 100));
                M1 -= 70;
            }
            if ((tienbandau - M1) > tienmotnua) { break; }
            if (EXP1 < 400) {
                M1 -= 200;
            }
            else { M1 -= 120; }
            EXP1 = EXP1 + lamtronlen(EXP1 * (13.0 / 100));
            if ((tienbandau - M1) > tienmotnua) { break; }
            if (EXP1 < 300) {
                M1 -= 100;
            }
            else {
                M1 -= 120;

            }
            EXP1 = lamtronlen(EXP1 - EXP1 * 0.1);
            if ((tienbandau - M1) > tienmotnua) { break; }
        }
        HP1 = lamtronlen(HP1 - HP1 * 17.0 / 100);
        EXP1 = EXP1 + lamtronlen(EXP1 * 17.0 / 100);
        if (EXP1 > sochinhphuong(EXP1)) { p2 = 1.0; }
        else { p2 = ((EXP1 / sochinhphuong(EXP1)) + 80) / 123.0; }
    }



    //duong 3
    double a[10] = { 0.32, 0.47, 0.28, 0.79, 1, 0.50, 0.22, 0.83, 0.64, 0.11 };
    if (E2 / 10 == 0) { p3 = a[E2]; }
    else {
        int f = E2 % 10;
        int g = E2 / 10;
        int h = f + g;
        if (h / 10 == 0) {
            p3 = a[h];
        }
        else {
            int j = h % 10;
            p3 = a[j];
        }
    }
    if (p1 == 1.0 && p2 == 1.0 && p3 == 1.0) { EXP1 = EXP1 - lamtronlen(EXP1 * 25.0 / 100); }
    else {
        float p = (p1 + p2 + p3) / 3;
        if (p < 0.5) {
            HP1 = lamtronlen(HP1 - HP1 * 15.0 / 100);
            EXP1 += lamtronlen(EXP1 * 15.0 / 100);
        }
        else {
            HP1 = lamtronlen(HP1 - HP1 * 10.0 / 100);
            EXP1 = EXP1 + lamtronlen(EXP1 * 20.0 / 100);
        }

    }
    HP1 = check(HP1, 0, 666);
    EXP1 = check(EXP1, 0, 600);
    M1 = check(M1, 0, 3000);

    return HP1 + EXP1 + M1;

}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int map[10][10];
    int dem1 = 0, dem2=0;
    int diemcuataxi, diemcuasherlock;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = { ((E3 * j) + (i * 2)) * (i - j) };
            if (map[i][j] > E3 * 2) { dem1 += 1; }
            if (map[i][j] <-E3 ) { dem2 += 1; }
        }
    }
    int i = tong2sothanh1(dem1);
    int j = tong2sothanh1(dem2);
    int max1 = map[i][j], max2 = map[i][j];
    //duong cheo / 
   
    if (i + j <= 9) {
        for (int m = 0; m <= i + j; m++) {
            int n = (i + j) - m;
            if (max1 < map[m][n]) max1 = map[m][n];
        }
    }
    else {
        for (int m = 9; m >= i + j - 9; m--) {
            int n = i + j - m;
            if (max1 < map[m][n]) max1 = map[m][n];
        }
        

    }




    //duong cheo \
    
    if (i < j) {
        for (int m = 0; m <= 9 - (j - i); m++) {
            int n = j-i;
            map[m][n];
            n = n + 1;
            if (max2 < map[m][n]) max2 = map[m][n];
        }
    }
    else if (i == j) {
        for (int m = 0; m <= 9; m++) {
            if (max2 < map[m][m]) { max2 = map[m][m]; }
        }
    }
    else {
        for (int m = 9; m >= i - j; m--) {
            int n = m-i+j;
            if (max2 < map[m][m]) { max2 = map[m][m]; }
        }
    }
    if (max1 > max2) { diemcuasherlock = max1; }
    else diemcuasherlock = max2;
      diemcuataxi = map[i][j];
    if (abs(diemcuasherlock) >= abs(diemcuataxi)) {
        EXP1 += EXP1 * 12 / 100;
        EXP2 += EXP2 * 12 / 100;
        HP1 += HP1 * 10 / 100;
        HP2 += HP2 * 10 / 100;
    }
    else {
        EXP1 -= EXP1 * 12 / 100;
        EXP2 -= EXP2 * 12 / 100;
        HP1 -= HP1 * 10 / 100;
        HP2 -= HP2 * 10 / 100;

    }

    if (abs(diemcuasherlock) >= abs(diemcuataxi)) return diemcuasherlock;
    else return diemcuataxi;
    
    
   
}



// Task 4
bool checklen(const char* s, bool& l) {
    l = false;
    if (strlen(s) < 8 || strlen(s) > 20) {
        if (strlen(s) < 8) l = false;
        else l = true;


        return false;
    }
    else return true;
}

bool checkchar(const char* s, int& n) {
    for (int i = 0; i < strlen(s); i++) {
        if (!((s[i] >= 97 && s[i] <= 122) || (s[i] >= 64 && s[i] <= 90) || (s[i] >= 48 && s[i] <= 57) || s[i] == 33 || (s[i] >= 35 && s[i] <= 37))) {
            n = i;
            return false;
        }
    }
    return true;

}

bool checkse(const char* s, const char* email, int& n) {  //check l?i
    int a;
    char* se;
    const char* afterse;



    afterse = strchr(email, '@');

    a = strlen(email) - strlen(afterse);

    se = new char[a + 1];
    strncpy(se, email, a);


    for (int i = 0; i < strlen(s) - a; i++)
    {
        int b = 0;
        for (int j = 0; j < a; j++) {
            if (se[j] == s[i + j]) b++;
        }
        if (b == a) {
            n = i;
            return false;
        }
    }
    return true;

}

bool checkmorethan2char(const char* s, int& n) {
    for (int i = 0; i < strlen(s) - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            n = i;
            return false;
        }
    }
    return true;
}

bool checkspecialchar(const char* s) {
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 64 || s[i] == 33 || (s[i] >= 35 && s[i] <= 37)) return true;
    }
    return false;
}

int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    bool l;
    int sei, sci, n;


    if (checklen(s, l) == false) {
        if (l) return -2;
        else return -1;
    }

    if (checkse(s, email, sei) == false) return -(300 + sei);

    if (checkmorethan2char(s, sci) == false) return -(400 + sci);

    if (checkspecialchar(s) == false) return -5;

    if (checkchar(s, n) == false) return n;

    return -10;


}

// Task 5
bool alldifferent(const char* pwds, char* pass[30]) {
    for (int i = 0; i < 30; i++) {

        if (strcmp(pwds, pass[i]) == 0) {

            return false;
        }
    }
    return true;
}

int firstposition(const char* arr_pwds[], int num_pwds, char* pass[], int correctpass) {
    for (int i = 0; i < num_pwds; i++)
    {

        if (strcmp(pass[correctpass], arr_pwds[i]) == 0) return i;
    }
    return 0;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    char* pass[30];
    int numpass[30] = {};
    int maxtimes[30] = {};
    int correctpass;
    char nowhere[] = ".";
    char* nothing = nowhere;

    for (int i = 0; i < 30; i++) {
        pass[i] = nowhere;
    }



    pass[0] = new char[strlen(arr_pwds[0]) + 1];
    strcpy(pass[0], arr_pwds[0]);

    numpass[0] = 1;


    for (int i = 1; i < num_pwds; i++)
    {
        int k = 0;
        while (*pass[k] != *nothing) k++;

        if (alldifferent(arr_pwds[i], pass)) {

            pass[k] = new char[strlen(arr_pwds[i]) + 1];
            strcpy(pass[k], arr_pwds[i]);
            numpass[k] = 1;
        }
        else {
            for (int j = 0; j < 30; j++) {
                if (strcmp(pass[j], arr_pwds[i]) == 0) numpass[j]++;
            }

        }


    }




    int maxi = numpass[0];          //findmax times
    maxtimes[0] = numpass[0];

    for (int i = 1; i < 30; i++)
    {

        if (maxi < numpass[i])
        {
            maxi = numpass[i];

            for (int j = 0; j < 30; j++) maxtimes[j] = 0;
            maxtimes[i] = numpass[i];
        }
        if (maxi == numpass[i]) {
            maxtimes[i] = numpass[i];
        }

    }



    for (int i = 0; i < 30; i++)
    {
        if (maxtimes[i]) {
            correctpass = i;
            break;
        }
    }

    for (int i = 0; i < 30; i++)
    {
        if (maxtimes[i]) {
            if (strlen(pass[i]) > strlen(pass[correctpass]))	correctpass = i;
        }

    }


    return firstposition(arr_pwds, num_pwds, pass, correctpass);

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////