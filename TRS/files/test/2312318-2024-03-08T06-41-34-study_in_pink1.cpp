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




int kiemtra(int n, int firstnum, int lastnum) {
    if (n < firstnum) n = firstnum;
    if (n > lastnum) n = lastnum;
    return n;
// Task 1

}

int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function


    int  d;
    float exp1_t, exp2_t;
    if (e1 < 0 || e1 > 99)
        return -99;
    exp1 = kiemtra(exp1, 0, 600);
    exp2 = kiemtra(exp2, 0, 600);
    exp1_t = exp1;
    exp2_t = exp2;
    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0)
            exp2_t += 29;
        if (e1 == 1)
            exp2_t += 45;
        if (e1 == 2)
            exp2_t += 75;
        if (e1 == 3)
            exp2_t += 29 + 45 + 75;
        d = e1 * 3 + exp1_t * 7;
        if (d % 2 == 0)
            exp1_t = ceil(exp1_t + d * 1.0000 / 200 - 0.00001);
        else exp1_t = ceil(exp1_t - d * 1.0000 / 100 - 0.00001);
        exp1_t = kiemtra(exp1_t, 0, 600);
        exp2_t = kiemtra(exp2_t, 0, 600);
        exp1 = exp1_t;
        exp2 = exp2_t;
    }
    if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
            exp2_t = ceil(exp2_t + e1 * 1.0000 / 4 + 19 - 0.00001);
        else if (e1 >= 20 && e1 <= 49)
            exp2_t = ceil(exp2_t + e1 * 1.0000 / 9 + 21 - 0.00001);
        else if (e1 > 49 && e1 <= 65)
            exp2_t = ceil(exp2_t + e1 * 1.0000 / 16 + 17 - 0.00001);
        else if (e1 > 65 && e1 <= 79)
        {
            exp2_t = ceil(exp2_t + e1 * 1.0000 / 4 + 19 - 0.00001);
            if (exp2_t > 200)
                exp2_t = ceil(exp2_t + e1 * 1.0000 / 9 + 21 - 0.00001);
        }
        if (e1 > 79 && e1 <= 99)
        {
            exp2_t = ceil((exp2_t + e1 * 1.0000 / 4 + 19) - 0.00001);
            exp2_t = ceil(exp2_t + e1 * 1.0000 / 9 + 21 - 0.00001);
            if (exp2_t > 400)
            {
                exp2_t = ceil(exp2_t + e1 * 1.0000 / 16 + 17 - 0.00001);
                exp2_t = ceil(exp2_t + exp2_t * 0.15 - 0.00001);
            }

        }

        exp1 -= e1;

        exp2 = exp2_t;
    }

    exp1 = kiemtra(exp1, 0, 600);
    exp2 = kiemtra(exp2, 0, 600);


    return exp1 + exp2;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    int k, t, a;
    double p1, p2, p3, p, s;
    if (E2 < 0 || E2 > 99)
        return -99;
    EXP1 = kiemtra(EXP1, 0, 600);
    HP1 = kiemtra(HP1, 0, 666);
    M1 = kiemtra(M1, 0, 3000);

    double HP1_t, EXP1_t;
    HP1_t = HP1;
    EXP1_t = EXP1;

    //con duong 1
    k = round(sqrt(EXP1));
    s = (k * k);

    if (EXP1 >= s)
        p1 = 100;
    else {

        p1 = ((EXP1_t / s + 80 * 1.0000) / 123) * 100;
    }

    //con duong 2

    t = M1;
    a = 0;
    if (E2 % 2 == 1) {
        while (a <= 0.5 * t)
        {
            if (HP1_t < 200) {
                HP1_t = ceil(HP1_t + HP1_t * 0.3 - 0.00001);
                M1 -= 150;
            }
            else {
                HP1_t = ceil(HP1_t + HP1_t * 0.1 - 0.00001);
                M1 -= 70;
            }
            HP1_t = kiemtra(HP1_t, 0, 666);
            M1 = kiemtra(M1, 0, 3000);
            a = t - M1;
            if (a > 0.5 * t) break;
            if (EXP1_t < 400)
                M1 -= 200;
            else M1 -= 120;
            EXP1_t = ceil(EXP1_t + EXP1_t * 0.13 - 0.00001);
            EXP1_t = kiemtra(EXP1_t, 0, 600);
            M1 = kiemtra(M1, 0, 3000);
            a = t - M1;
            if (a > 0.5 * t) break;

            if (EXP1_t < 300)
                M1 -= 100;
            else M1 -= 120;
            EXP1_t = ceil(EXP1_t - EXP1_t * 0.1 - 0.00001);
            EXP1_t = kiemtra(EXP1_t, 0, 600);
            M1 = kiemtra(M1, 0, 3000);
            a = t - M1;
            if (a > 0.5 * t) break;
        }



    }
    else {
        int q = 0;
        do {
            if (HP1_t < 200) {
                HP1_t = ceil(HP1_t + HP1_t * 0.3 - 0.00001);
                M1 -= 150;
            }
            else {
                HP1_t = ceil(HP1_t + HP1_t * 0.1 - 0.00001);
                M1 -= 70;
            }
            HP1_t = kiemtra(HP1_t, 0, 666);
            M1 = kiemtra(M1, 0, 3000);
            if (M1 == 0) break;

            if (EXP1_t < 400)
                M1 -= 200;
            else M1 -= 120;
            EXP1_t = ceil(EXP1_t + EXP1_t * 0.13 - 0.00001);
            EXP1_t = kiemtra(EXP1_t, 0, 600);
            M1 = kiemtra(M1, 0, 3000);

            if (M1 == 0) break;

            if (EXP1_t < 300)
                M1 -= 100;
            else M1 -= 120;
            EXP1_t = ceil(EXP1_t - EXP1_t * 0.1 - 0.00001);
            EXP1_t = kiemtra(EXP1_t, 0, 600);

            M1 = kiemtra(M1, 0, 3000);

            if (M1 == 0) break;

        } while (q > 1);
    }

    HP1_t = ceil(HP1_t - HP1_t * 0.17 - 0.00001);
    EXP1_t = ceil(EXP1_t + EXP1_t * 0.17 - 0.00001);
    HP1_t = kiemtra(HP1_t, 0, 666);
    EXP1_t = kiemtra(EXP1_t, 0, 600);
    int k2;
    double s2;
    EXP1 = EXP1_t;

    k2 = round(sqrt(EXP1));
    s2 = k2 * k2;
    if (EXP1 >= s2)
        p2 = 100;
    else {
        p2 = ((EXP1 / s2 + 80) / 123) * 100;
    }
    EXP1_t = EXP1;

    //con duong 3
    int P[10] = { 32,47,28,79,100,50,22,83,64,11 };
    int i;
    if (E2 < 10) {
        i = E2;
        p3 = P[i];
    }
    else if (E2 <= 99) {
        i = ((E2 - (E2 % 10)) / 10 + (E2 % 10)) % 10;
        p3 = P[i];
    }
    if ((p1 + p2 + p3) == 300) {
        EXP1_t = ceil(EXP1_t - 0.25 * EXP1_t - 0.00001);

    }
    else {
        p = (p1 + p2 + p3) / 3;
        if (p < 50) {
            HP1_t = ceil(HP1_t - 0.15 * HP1_t - 0.00001);
            EXP1_t = ceil(EXP1_t + 0.15 * EXP1_t - 0.00001);
        }
        else {
            HP1_t = ceil(HP1_t - 0.1 * HP1_t - 0.00001);
            EXP1_t = ceil(EXP1_t + 0.2 * EXP1_t - 0.00001);
        }

    }
    EXP1_t = kiemtra(EXP1_t, 0, 600);
    HP1_t = kiemtra(HP1_t, 0, 666);
    HP1 = HP1_t;
    EXP1 = EXP1_t;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;

    HP1 = kiemtra(HP1, 0, 666);
    HP2 = kiemtra(HP2, 0, 666);
    EXP1 = kiemtra(EXP1, 0, 600);
    EXP2 = kiemtra(EXP2, 0, 600);

    float HP1_T, HP2_T, EXP1_T, EXP2_T;
    HP1_T = HP1;
    HP2_T = HP2;
    EXP1_T = EXP1;
    EXP2_T = EXP2;
    int mt1[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            mt1[i][j] = 0;
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            mt1[i][j] = ((E3 * j) + (i * 2)) * (i - j);

        }
    }

    int dem1 = 0;
    int dem2 = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (mt1[i][j] > E3 * 2) {
                dem1++;
            }
            if (mt1[i][j] < -E3) {
                dem2++;
            }
        }
    }
    while (dem1 >= 10) {
        dem1 = (dem1 / 10) + (dem1 % 10);
    }
    while (dem2 >= 10) {
        dem2 = (dem2 / 10) + (dem2 % 10);
    }


    int max, a, b;
    a = dem1; b = dem2;
    max = mt1[a][b];

    while (a >= 0 && a < 9 && b >= 0 && b < 9) {
        a++; b++;
        if (mt1[a][b] > max) {
            max = mt1[a][b];
        }
    }
    a = dem1; b = dem2;
    while (a >= 0 && a < 9 && b > 0 && b < 10) {
        a++; b--;
        if (mt1[a][b] > max) {
            max = mt1[a][b];
        }
    }
    a = dem1; b = dem2;
    while (a > 0 && a < 10 && b > 0 && b < 10) {
        a--; b--;
        if (mt1[a][b] > max) {
            max = mt1[a][b];
        }
    }
    a = dem1; b = dem2;
    while (a > 0 && a < 10 && b >= 0 && b < 9) {
        a--; b++;
        if (mt1[a][b] > max) {
            max = mt1[a][b];
        }
    }int max1 = max;
    if (max < 0) max1 = abs(max);



    int dem = abs(mt1[dem1][dem2]);

    if ( dem > max1) {
        EXP1_T = ceil(EXP1_T - 0.12 * EXP1_T - 0.00001);
        EXP2_T = ceil(EXP2_T - 0.12 * EXP2_T - 0.00001);
        HP1_T = ceil(HP1_T - 0.1 * HP1_T - 0.00001);
        HP2_T = ceil(HP2_T - 0.1 * HP2_T - 0.00001);
        EXP1_T = kiemtra(EXP1_T, 0, 600);
        EXP2_T = kiemtra(EXP2_T, 0, 600);
        HP1_T = kiemtra(HP1_T, 0, 666);
        HP2_T = kiemtra(HP2_T, 0, 666);
        EXP1 = EXP1_T;
        EXP2 = EXP2_T;
        HP1 = HP1_T;
        HP2 = HP2_T;
        return mt1[dem1][dem2];
    }

    else {
        EXP1_T = ceil(EXP1_T + 0.12 * EXP1_T - 0.00001);
        EXP2_T = ceil(EXP2_T + 0.12 * EXP2_T - 0.00001);
        HP1_T = ceil(HP1_T + 0.1 * HP1_T - 0.00001);
        HP2_T = ceil(HP2_T + 0.1 * HP2_T - 0.00001);
        EXP1_T = kiemtra(EXP1_T, 0, 600);
        EXP2_T = kiemtra(EXP2_T, 0, 600);
        HP1_T = kiemtra(HP1_T, 0, 666);
        HP2_T = kiemtra(HP2_T, 0, 666);
        EXP1 = EXP1_T;
        EXP2 = EXP2_T;
        HP1 = HP1_T;
        HP2 = HP2_T;
        return max;

    }
    

}



// Task 4
int checkPassword(const char* s, const char* email)
{
    // TODO: Complete this function

    string se;
    int m = 0;
    for (int i = 0; i < 100; i++) {

        if (email[i] != '@') {
            se += email[i];
        }

        else {
            m = i;
            break;
        }
    }
    int n = strlen(s);



    bool test = true;


    //ngan hon
    if (n < 8){
        test = false;
        return -1;
        }

        // dai hon
        if (n > 20)
        {
            test = false;
            return -2;
        }
    //chua chuoi se
    if (se.empty()) {
        return -300;
    }

    int t = 0, z = 0;
    int dem = 0, sei = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (se[i] == s[j]) {
                t = i;
                z = j;
                while (se[t] == s[z] && t < m && z < n) {
                    dem++;
                    t++;
                    z++;
                }

                if (dem == m) {
                    sei = z - m;
                    return -(300 + sei);
                }
                dem = 0;
            }
        }
    }
    //chua hon 2 ky tu ltiep giong nhau
    int sci = 0;
    int k = 0;
    for (int i = 0; i < n - 2; i++) {
        if ((s[i] == s[i + 1]) && (s[i] == s[i + 2]))
        {
            test = false;

            return -(400 + i);
            break;
        }
    }




    // khong chua ky tu dac biet
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            l++;
        }
    }
    if (l == 0) {
        test = false;
        return -5;
    }
    // chua cac ky tu khac
    int dem2;
    for (int i = 0; i < n; i++) {
        if ((s[i] >= '0') && (s[i] <= '9')) test = true;
        else if ((s[i] >= 'a') && (s[i] <= 'z')) test = true;
        else if ((s[i] >= 'A') && (s[i] <= 'Z')) test = true;
        else if (s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') {
            test = false;
            dem2 = i;
            break;

        }
    } if (test == false) return dem2;

    //hop le
    if (test == true) return -10;

    return -99;
}
// Task 5

int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int c[num_pwds] = {};
    for (int i = 0; i < num_pwds; i++) {
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                c[i]++;

            }
        }
    }
    int l;
    int max = c[0];
    int dem = 0;
    for (int i = 1; i < num_pwds; i++) {
        if (c[i] > max) {
            max = c[i];
            dem = i;

        }
        if (c[i] == max) {
            l = strlen(arr_pwds[dem]);
            if (l < strlen(arr_pwds[i])) {
                dem = i;

            }

        }
    }
    return dem;
}




////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////

