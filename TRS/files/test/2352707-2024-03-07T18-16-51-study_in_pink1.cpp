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
int checkexp(int exp) {
    if (exp > 600)
        exp = 600;
    else if (exp < 0)
        exp = 0;
    return exp;
}

int checkhp(int hp) {
    if (hp > 666)
        hp = 666;
    else if (hp < 0)
        hp = 0;
    return hp;
}

int checkm(int m) {
    if (m > 3000)
        m = 3000;
    else if (m < 0)
        m = 0;
    return m;
}

double road1(int exp) {
    double p;
    int a = sqrt(exp) + 0.5;
    double s = a * a;

    if (exp >= s)
        p = 1;
    else
        p = (exp / s + 80.00) / 123.00;
    return p;
}

int dn(int num) {
    int a = num / 10;
    int b = num % 10;
    return a + b;
}

int issc(char c) {
    if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!')
        return 1;
    else
        return 0;
}

int count(string r, int size, string arr[]) {
    int app = 0;
    for (int i = 0; i < size; i++) {
        if (r == arr[i])
            app++;
    }
    return app;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    exp1 = checkexp(exp1);

    if (e1 < 0 || e1 > 99)
        return -99;

    else if (e1 > -1 && e1 < 4) {
        switch (e1)
        {
        case 0:
            exp2 += 29;
            break;
        case 1:
            exp2 += 45;
            break;

        case 2:
            exp2 += 75;
            break;

        case 3:
            exp2 += 149;
            break;

        default:
            return -99;
        }
        int D = 3 * e1 + 7 * exp1;
        if (D % 2 == 0) {
            exp1 = ceil(exp1 + D / 200.00);
        }
        else {
            exp1 = ceil(exp1 - D / 100.00);
        }
    }

    else if (e1 > 3 && e1 < 20) {
        exp2 = ceil(exp2 + e1 / 4.00 + 19.00);
        exp1 -= e1;
    }

    else if (e1 > 19 && e1 < 50) {
        exp2 = ceil(exp2 + e1 / 9.00 + 21.00);
        exp1 -= e1;
    }

    else if (e1 > 49 && e1 < 66) {
        exp2 = ceil(exp2 + e1 / 16.00 + 17.00);
        exp1 -= e1;
    }

    else if (e1 > 65 && e1 < 80) {
        exp2 = ceil(exp2 + e1 / 4.00 + 19.00);
        if (exp2 > 200) {
            exp2 = ceil(exp2 + e1 / 9.00 + 21.00);
        }
        exp1 -= e1;
    }

    else {
        exp2 = ceil(exp2 + e1 / 4.00 + 19.00);
        exp2 = ceil(exp2 + e1 / 9.00 + 21.00);
        if (exp2 > 400) {
            exp2 = ceil(exp2 + e1 / 16.00 + 17.00);
            exp2 = ceil(exp2 * 1.15);
        }
        exp1 -= e1;
    }
    exp1 = checkexp(exp1);
    exp2 = checkexp(exp2);
    return  exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    HP1 = checkhp(HP1);
    EXP1 = checkexp(EXP1);
    M1 = checkm(M1);

    if (E2 < 0 || E2 > 99)
        return -99;

    double p1 = road1(EXP1);

    int tm = ceil(M1 / 2);
    if (E2 % 2 == 1) {
        while (1) {
            if (tm == 0) {
                HP1 = checkhp(ceil(HP1 * 0.83));
                EXP1 = checkexp(ceil(EXP1 * 1.17));
                break;
            }

            if (HP1 < 200) {
                HP1 = ceil(HP1 * 1.3);
                M1 -= 150;
                tm -= 150;
            }
            else {
                HP1 = ceil(HP1 * 1.1F);
                M1 -= 70;
                tm -= 70;
            }
            HP1 = checkhp(HP1);
            M1 = checkm(M1);
            if (tm < 0) {
                HP1 = checkhp(ceil(HP1 * 0.83));
                EXP1 = checkexp(ceil(EXP1 * 1.17));
                break;
            }


            if (EXP1 < 400) {
                M1 -= 200;
                tm -= 200;
            }
            else {
                M1 -= 120;
                tm -= 120;
            }
            EXP1 = checkexp(ceil(EXP1 * 1.13));
            M1 = checkm(M1);
            if (tm < 0) {
                HP1 = checkhp(ceil(HP1 * 0.83));
                EXP1 = checkexp(ceil(EXP1 * 1.17));
                break;
            }


            if (EXP1 < 300) {
                M1 -= 100;
                tm -= 100;
            }
            else {
                M1 -= 120;
                tm -= 120;
            }
            EXP1 = checkexp(ceil(EXP1 * 0.9));
            M1 = checkm(M1);
            if (tm < 0) {
                HP1 = checkhp(ceil(HP1 * 0.83));
                EXP1 = checkexp(ceil(EXP1 * 1.17));
                break;
            }
        }
    }



    else {
        for (int i = 0; i < 1; i++) {
            if (M1 == 0) {
                HP1 = checkhp(ceil(HP1 * 0.83));
                EXP1 = checkexp(ceil(EXP1 * 1.17));
                break;
            }

            if (HP1 < 200) {
                HP1 = ceil(HP1 * 1.3);
                M1 -= 150;
            }
            else {
                HP1 = ceil(HP1 * 1.1F);
                M1 -= 70;
            }
            HP1 = checkhp(HP1);
            M1 = checkm(M1);
            if (M1 == 0) {
                HP1 = checkhp(ceil(HP1 * 0.83));
                EXP1 = checkexp(ceil(EXP1 * 1.17));
                break;
            }


            if (EXP1 < 400)
                M1 -= 200;
            else M1 -= 120;
            EXP1 = checkexp(ceil(EXP1 * 1.13));
            M1 = checkm(M1);
            if (M1 == 0) {
                HP1 = checkhp(ceil(HP1 * 0.83));
                EXP1 = checkexp(ceil(EXP1 * 1.17));
                break;
            }


            if (EXP1 < 300)
                M1 -= 100;
            else M1 -= 120;
            EXP1 = checkexp(ceil(EXP1 * 0.9));
            M1 = checkm(M1);
            HP1 = checkhp(ceil(HP1 * 0.83));
            EXP1 = checkexp(ceil(EXP1 * 1.17));
        }

    }
    double p2 = road1(EXP1);



    double arrayp[10] = { 0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11 };
    int i;
    if (E2 < 10)
        i = E2;
    else {
        int a = E2 / 10;
        int b = E2 % 10;
        i = (a + b) % 10;
    }
    double p3 = arrayp[i];

    double pa = (p1 + p2 + p3) / 3.00;
    if (pa == 1) {
        EXP1 = ceil(EXP1 * 0.75);
    }
    else if (pa < 0.5) {
        HP1 = ceil(HP1 * 0.85);
        EXP1 = ceil(EXP1 * 1.15);
    }
    else {
        HP1 = ceil(HP1 * 0.9);
        EXP1 = ceil(EXP1 * 1.2);
    }
    HP1 = checkhp(HP1);
    EXP1 = checkexp(EXP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    HP1 = checkhp(HP1);
    EXP1 = checkexp(EXP1);
    HP2 = checkhp(HP2);
    EXP2 = checkexp(EXP2);

    if (E3 < 0 || E3 > 99)
        return -99;

    int ta[10][10];
    int sw[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            ta[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int max = 0;
            {
                int a = i, b = j;
                if (a >= b) {
                    a -= b;
                    b = 0;
                }

                if (a < b) {
                    b -= a;
                    a = 0;
                }

                while (a < 10 && b < 10) {
                    if (ta[a][b] > max)
                        max = ta[a][b];
                    a++;
                    b++;
                }
            }

            {
                int a = i, b = j;
                if (a + b <= 9) {
                    b += a;
                    a = 0;
                }

                if (a + b > 9) {
                    a -= 9 - b;
                    b = 9;
                }

                while (a < 10 && b > 0) {
                    if (ta[a][b] > max)
                        max = ta[a][b];
                    a++;
                    b--;
                }
            }
            sw[i][j] = max;
        }
    }


    int ip = 0, jp = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (ta[i][j] > E3 * 2)
                ip++;
            if (ta[i][j] < -E3)
                jp++;
        }
    }

    while (1) {
        if (ip > 9)
            ip = dn(ip);

        if (jp > 9)
            jp = dn(jp);

        if (ip < 10 && jp < 10)
            break;
    }


    int tap = ta[ip][jp], swp = sw[ip][jp];
    if (abs(tap) > swp) {
        EXP1 = checkexp(ceil(EXP1 * 0.88F));
        EXP2 = checkexp(ceil(EXP2 * 0.88F));
        HP1 = checkhp(ceil(HP1 * 0.9F));
        HP2 = checkhp(ceil(HP2 * 0.9F));
        return tap;
    }
    else {
        EXP1 = checkexp(ceil(EXP1 * 1.12F));
        EXP2 = checkexp(ceil(EXP2 * 1.12F));
        HP1 = checkhp(ceil(HP1 * 1.1F));
        HP2 = checkhp(ceil(HP2 * 1.1F));
        return swp;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string S(s);
    string Email(email);

    int i = Email.find('@');
    string se(Email, 0, i);

    if (S.length() < 8)
        return -1;

    if (S.length() > 20)
        return -2;

    int j = S.find(se);
    if (j >= 0)
        return -(300 + j);

    for (int k = 0; k < S.length() - 2; k++) {
        if (S[k + 2] == S[k]) {
            if (S[k + 1] == S[k])
                return -(400 + k);
        }
    }

    int n = 0;
    while (n < S.length()) {
        if (S[n] == '@' || S[n] == '#' || S[n] == '%' || S[n] == '$' || S[n] == '!')
            break;
        else n++;
    }
    if (n == S.length())
        return -5;

    int m = 0;
    while (m < S.length()) {
        if (isdigit(S[m]) || islower(S[m]) || isupper(S[m]) || issc(S[m]))
            m++;
        else
            return m;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string Arr_pwds[100];
    for (int i = 0; i < num_pwds; i++) {
        Arr_pwds[i] = arr_pwds[i];
    }

    string ar[100];
    ar[0] = Arr_pwds[0];
    int m = 1;
    for (int i = 1; i < num_pwds; i++) {
        int j = 0;
        while (j < m) {
            if (Arr_pwds[i] == ar[j])
                break;

            else
                j++;

            if (j == m) {
                ar[m] = Arr_pwds[i];
                m++;
                break;
            }
        }
    }

    int ap[100];
    for (int i = 0; i < m; i++) {
        ap[i] = count(ar[i], num_pwds, Arr_pwds);
    }

    int max = 0;
    for (int i = 0; i < m; i++) {
        if (ap[i] > max) {
            max = ap[i];
        }
    }

    int maxp[100];
    int n = 0;
    for (int i = 0; i < m; i++) {
        if (ap[i] == max) {
            maxp[n] = i;
            n++;
        }
    }

    int al[100];
    for (int i = 0; i < n; i++) {
        al[i] = ar[maxp[i]].length();
    }

    int fn = 0;
    for (int i = 0; i < n; i++) {
        if (al[i] > fn) {
            fn = al[i];
        }
    }

    string re;
    for (int i = 0; i < m; i++) {
        if (ap[i] == max) {
            if (ar[i].length() == fn) {
                re = ar[i];
            }
        }
    }

    int z = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (Arr_pwds[i] == re) {
            z = i;
            break;
        }
    }
    return z;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////