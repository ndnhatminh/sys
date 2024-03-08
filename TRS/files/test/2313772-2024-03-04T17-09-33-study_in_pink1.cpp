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
int test(int n, int min, int max)
{
    if (n < min) { return min; }
    else if (n > max) { return max; }
    else return n;
}
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    int min = 0, max = 600;
    int d = 0, b = 0, c = 0, exp2_test = 0;
    double a = 0;
    exp1 = test(exp1, min, max);
    exp2 = test(exp2, min, max);
    if (e1 < 0 || e1>99) { return -99; }
    if (e1 >= 0 && e1 <= 3) {
        d = e1 * 3 + exp1 * 7;
        if (d % 2 == 1) { a = exp1 - d / 100.0000; }
        else { a = exp1 + d / 200.0000; }
        exp1 = a + 0.99;
        exp1 = test(exp1, min, max);
        switch (e1) {
        case 0:exp2 += 29;
            break;
        case 1:exp2 += 45;
            break;
        case 2:exp2 += 75;
            break;
        case 3:exp2 += 149;
            break;
        }
        exp2 = test(exp2, min, max);
    }
    else {
        exp1 = exp1 - e1;
        if (e1 >= 4 && e1 <= 19) { exp2 = exp2 + (e1 / 4.00) + 19.99; }
        else if (e1 >= 20 && e1 <= 49) { exp2 = exp2 + (e1 / 9.00) + 21.99; }
        else if (e1 >= 50 && e1 <= 65) { exp2 = exp2 + (e1 / 16.00) + 17.99; }
        else if (e1 >= 66 && e1 <= 79) {
            b = (e1 / 4.00) + 19.99;
            if (exp2 + b > 200) { exp2 = exp2 + b + (e1 / 9.00) + 21.99; }
            else exp2 = exp2 + b + 0.99;
        }
        else if (e1 >= 80 && e1 <= 99) {
            b = (e1 / 4.00) + 19.99;
            c = (e1 / 9.00) + 21.99;
            d = (e1 / 16.00) + 17.99;
            exp2_test = exp2 + b + c + d;
            if (exp2 + b + c > 400) {

                exp2 = (exp2_test * 1.15) + 0.99;
            }
            else exp2 = exp2 + b + c;
        }



    }
    exp1 = test(exp1, min, max);
    exp2 = test(exp2, min, max);
    return exp1 + exp2;

}

// Task 2
int find(int num) {
    int can = sqrt(num);
    int square1 = can * can;
    int square2 = (can + 1) * (can + 1);
    int dis1 = abs(num - square1);
    int dis2 = abs(num - square2);
    if (dis1 < dis2) { return square1; }
    else return square2;

}
double tinh(int EXP1) {
    int S = find(EXP1);
    if (EXP1 >= S) {
        return 1.0;
    }
    else {
        return (EXP1 * 1.000 / S + 80) / 123;
    }
}
double tinhp3(int E2) {
    int P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i;
    if (E2 < 10) {
        i = E2;
    }
    else {
        i = (E2 / 10 + E2 % 10) % 10;
    }
    return P[i] / 100.00;
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    int i = 0, tong = 0, b = 0;
    double p0 = 0, p1 = 0, p2 = 0, p3 = 0;
    int a = M1;
    EXP1 = test(EXP1, 0, 600);
    HP1 = test(HP1, 0, 666);
    M1 = test(M1, 0, 3000);
    if (E2 < 0 || E2>99) { return -99; }
    p1 = tinh(EXP1);
    bool event = true;
    if (E2 % 2 == 1) {
        while (event) {
            if (M1 * 1.0 > a * 0.5) {
                if (HP1 < 200) {
                    HP1 = HP1 * 1.3 + 0.99;
                    M1 = M1 - 150;
                }
                else {
                    HP1 = HP1 * 1.1 + 0.99;
                    M1 = M1 - 70;
                }
                EXP1 = test(EXP1, 0, 600);
                HP1 = test(HP1, 0, 666);
                M1 = test(M1, 0, 3000);
            }

            if (M1 * 1.0 > a * 0.5) {
                if (EXP1 < 400) {
                    M1 = M1 - 200;
                    EXP1 = EXP1 * 1.13 + 0.99;
                }
                else {
                    M1 = M1 - 120;
                    EXP1 = EXP1 * 1.13 + 0.99;
                }
                EXP1 = test(EXP1, 0, 600);
                HP1 = test(HP1, 0, 666);
                M1 = test(M1, 0, 3000);
            }
            if (M1 * 1.0 > a * 0.5) {
                if (EXP1 < 300) {
                    M1 = M1 - 100;
                    EXP1 = EXP1 * 0.9 + 0.99;
                }
                else {
                    M1 = M1 - 120;
                    EXP1 = EXP1 * 0.9 + 0.99;
                }
                EXP1 = test(EXP1, 0, 600);
                HP1 = test(HP1, 0, 666);
                M1 = test(M1, 0, 3000);
            }
            if (M1 * 1.0 <= a * 0.5) { event = false; }

        }
    }
    else {
        if (M1 > 0) {
            if (HP1 < 200) {
                HP1 = HP1 * 1.3 + 0.99;
                M1 = M1 - 150;
            }
            else {
                HP1 = HP1 * 1.1 + 0.99;
                M1 = M1 - 70;
            }
            EXP1 = test(EXP1, 0, 600);
            HP1 = test(HP1, 0, 666);
            M1 = test(M1, 0, 3000);
        }
        if (M1 > 0) {
            if (EXP1 < 400) {
                M1 = M1 - 200;
                EXP1 = EXP1 * 1.13 + 0.99;
            }
            else {
                M1 = M1 - 120;
                EXP1 = EXP1 * 1.13 + 0.99;
            }
            EXP1 = test(EXP1, 0, 600);
            HP1 = test(HP1, 0, 666);
            M1 = test(M1, 0, 3000);
        }
        if (M1 > 0) {
            if (EXP1 < 300) {
                M1 = M1 - 100;
                EXP1 = EXP1 * 0.9 + 0.99;
            }
            else {
                M1 = M1 - 120;
                EXP1 = EXP1 * 0.9 + 0.99;
            }
            EXP1 = test(EXP1, 0, 600);
            HP1 = test(HP1, 0, 666);
            M1 = test(M1, 0, 3000);
        }
    }
    HP1 = HP1 * 0.83 + 0.99;
    EXP1 = EXP1 * 1.17 + 0.99;
    EXP1 = test(EXP1, 0, 600);
    HP1 = test(HP1, 0, 666);
    M1 = test(M1, 0, 3000);
    p2 = tinh(EXP1);
    p3 = tinhp3(E2);
    p0 = p1 + p2 + p3;
    if (p0 == 1) { EXP1 = EXP1 * 0.75 + 0.99; }
    else if (p0 < 0.5) {
        HP1 = HP1 * 0.85 + 0.99;
        EXP1 = EXP1 * 1.15 + 0.99;
    }
    else {
        HP1 = HP1 * 0.9 + 0.99;
        EXP1 = EXP1 * 1.2 + 0.99;
    }
    EXP1 = test(EXP1, 0, 600);
    HP1 = test(HP1, 0, 666);
    M1 = test(M1, 0, 3000);
    return HP1 + EXP1 + M1;

}
// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    int count1, count2, sher, tax, back ;
    count1 = 0;
    count2 = 0;
    int p[10][10];
    if (E3 < 0 || E3>99) return -99;
    EXP1 = test(EXP1, 0, 600);
    HP1 = test(HP1, 0, 666);
    EXP2 = test(EXP2, 0, 600);
    HP2 = test(HP2, 0, 666);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            p[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (p[i][j] != 0 && p[i][j] > (E3 * 2)) {
                count1 = count1 + 1;
            }
            if (p[i][j] != 0 && p[i][j] < (-E3)) {
                count2 = count2 + 1;
            }
        }
    }

    while (count1 >= 10) {
        count1 = count1 / 10 + count1 % 10;
    }

    while (count2 >= 10) {
        count2 = count2 / 10 + count2 % 10;
    }

    tax = p[count1][count2];
     sher = 0;

    for (int i = 1; i <= 9; ++i) {

        if ((count1 + i) <= 9 && (count2 + i) <= 9) {
            if (p[count1 + i][count2 + i] > sher) sher = p[count1 + i][count2 + i];

        }

        if ((count1 - i) >= 0 && (count2 - i) >= 0) {
            if (p[count1 - i][count2 - i] > sher) sher = p[count1 - i][count2 - i];

        }

        if ((count1 - i) >= 0 && (count2 + i) <= 9) {
            if (p[count1 - i][count2 + i] > sher) sher = p[count1 - i][count2 + i];

        }

        if ((count1 + i) <= 9 && (count2 - i) >= 0) {
            if (p[count1 + i][count2 - i] > sher) sher = p[count1 + i][count2 - i];

        }

    }

    if (abs(tax) > abs(sher)) {
        EXP1 = EXP1 * 0.88 + 0.99;
        EXP2 = EXP2 * 0.88 + 0.99;
        HP1 = HP1 * 0.9 + 0.99;
        HP2 = HP2 * 0.9 + 0.99;
        back = tax;
    }
    else {
        EXP1 = EXP1 * 1.12 + 0.99;
        EXP2 = EXP2 * 1.12 + 0.99;
        HP1 = HP1 * 1.1 + 0.99;
        HP2 = HP2 * 1.1 + 0.99;
        back = sher;
    }
    EXP1 = test(EXP1, 0, 600);
    HP1 = test(HP1, 0, 666);
    EXP2 = test(EXP2, 0, 600);
    HP2 = test(HP2, 0, 666);

    return back;
}

// Task 4
bool numchar(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int checkPassword(const char* s, const char* email) {
    string se;

    const char* find = strchr(email, '@');
    if (find != nullptr) {

        se.assign(email, find - email);
    }

    int leng = strlen(s);
    if (leng < 8) {
        return -1;
    }

    if (leng > 20) {
        return -2;
    }

    const char* search = strstr(s, se.c_str());
    if (search != nullptr) {
        return -(300 + (search - s));
    }

    char pre = '\0';
    int csame = 1;
    bool spc = false;

    for (int i = 0; i < leng; ++i) {
        char c = s[i];
        if (!numchar(c) && c != '@' && c != '#' && c != '%' && c != '$' && c != '!') {
            return i;
        }

        if (numchar(c)) {
            if (c == pre) {

                csame++;
                if (csame > 2) {
                    return -(400 + i - 2);
                }
            }
            else {
                csame = 1;
            }
        }
        else {
            spc = true;
        }
        pre = c;
    }
    if (!spc) {
        return -5;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int maxcount = 0;
    int maxleng = 0;
    int correct = 0;

    for (int i = 0; i < num_pwds; ++i) {
        const char* pass = arr_pwds[i];
        int currentcount = 0;
        int currentleng = std::strlen(pass);

        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[j], pass) == 0) {
                currentcount++;
            }
        }
        if (currentcount > maxcount || (currentcount == maxcount && currentleng > maxleng)) {
            maxcount = currentcount;
            maxleng = currentleng;
            correct = i;
        }
    }

    return correct;

}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////