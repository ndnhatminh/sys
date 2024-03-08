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

int roundUp(double num) {
    int k = num + 0.999;
    return k;
}

void explimit(int& n) {
    if (n > 600) n = 600;
    if (n < 0) n = 0;
}

void hplimit(int& n) {
    if (n > 666) n = 666;
    if (n < 0) n = 0;
}

void mlimit(int& n) {
    if (n > 3000) n = 3000;
    if (n < 0) n = 0;
}

int nearestSquare(int n) {
    int sqrt_n = sqrt(n);
    if (sqrt_n * sqrt_n == n) {
        return n;
    }
    else {
        int lower_square = sqrt_n * sqrt_n;
        int higher_square = (sqrt_n + 1) * (sqrt_n + 1);

        if (n - lower_square < higher_square - n) {
            return lower_square;
        }
        else {
            return higher_square;
        }
    }
}

int sum(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void Count(int& n) {
    while (n >= 10) {
        n = sum(n);
    }
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {

    if (e1 > 99 || e1 < 0) return -99;
    explimit(exp1);
    explimit(exp2);
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) exp2 += 29;
        else if (e1 == 1) exp2 += 45;
        else if (e1 == 2) exp2 += 75;
        else if (e1 == 3) exp2 += 149;
        explimit(exp2);

        int D = 0;
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = roundUp(exp1 + D / 200.0);
        else exp1 = roundUp(exp1 - D / 100.0);
        explimit(exp1);

        return exp1 + exp2;
    }

    exp1 -= e1;
    explimit(exp1);

    if (e1 >= 4 && e1 <= 19) {
        exp2 = roundUp(exp2 + e1 / 4.0 + 19);
        explimit(exp2);
        return exp1 + exp2;
    }
    else if (e1 >= 20 && e1 <= 49) {
        exp2 = roundUp(exp2 + e1 / 9.0 + 21);
        explimit(exp2);
        return exp1 + exp2;
    }
    else if (e1 >= 50 && e1 <= 65) {
        exp2 = roundUp(exp2 + e1 / 16.0 + 17);
        explimit(exp2);
        return exp1 + exp2;
    }
    else if (e1 >= 66 && e1 <= 79) {
        exp2 = roundUp(exp2 + e1 / 4.0 + 19);
        if (exp2 > 200) exp2 = roundUp(exp2 + e1 / 9.0 + 21);
        explimit(exp2);
        return exp1 + exp2;
    }
    else if (e1 >= 80 && e1 <= 99) {
        exp2 = roundUp(exp2 + e1 / 4.0 + 19);
        exp2 = roundUp(exp2 + e1 / 9.0 + 21);
        explimit(exp2);
        if (exp2 > 400) {
            exp2 = roundUp(exp2 + e1 / 16.0 + 17);
            exp2 = roundUp(1.15 * exp2);
            explimit(exp2);
        }
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 > 99 || E2 < 0) return -99;
    hplimit(HP1);
    explimit(EXP1);
    mlimit(M1);

    int s1 = nearestSquare(EXP1);
    double P1 = 0;
    if (EXP1 >= s1) P1 = 100;
    else P1 = (EXP1 * 1.0 / s1 + 80) * 100 / 123;

    int m = M1;
    if (E2 % 2 == 1) {
        if (M1 != 0) {
            while (true) {
                if (HP1 < 200) {
                    HP1 = roundUp(HP1 * 1.3);
                    M1 -= 150;
                }
                else {
                    HP1 = roundUp(HP1 * 1.1);
                    M1 -= 70;
                }
                hplimit(HP1);
                if (M1 < m * 0.5) {
                    mlimit(M1);
                    break;
                }

                if (EXP1 < 400) {
                    M1 -= 200;
                    EXP1 = roundUp(EXP1 * 1.13);
                }
                else {
                    M1 -= 120;
                    EXP1 = roundUp(EXP1 * 1.13);
                }
                explimit(EXP1);
                mlimit(M1);
                if (M1 < m * 0.5) {
                    mlimit(M1);
                    break;
                }

                if (EXP1 < 300) {
                    M1 -= 100;
                    EXP1 = roundUp(EXP1 * 0.9);
                }
                else {
                    M1 -= 120;
                    EXP1 = roundUp(EXP1 * 0.9);
                }
                if (M1 < m * 0.5) {
                    mlimit(M1);
                    break;
                }
            }
        }
        HP1 = roundUp(HP1 * 0.83);
        EXP1 = roundUp(EXP1 * 1.17);
    }
    else {
        int i = 0;
        while (i == 0) {
            if (M1 <= 0) {
                M1 = 0;
                break;
            }
            if (HP1 < 200) {
                HP1 = roundUp(1.3 * HP1);
                M1 -= 150;
            }
            else if (HP1 >= 200) {
                HP1 = roundUp(1.1 * HP1);
                M1 -= 70;
            }
            hplimit(HP1);
            if (M1 <= 0) {
                M1 = 0;
                break;
            }


            if (EXP1 < 400) {
                M1 -= 200;
            }
            else if (EXP1 >= 400) {
                M1 -= 120;
            }
            EXP1 = roundUp(1.13 * EXP1);
            explimit(EXP1);
            if (M1 <= 0) {
                M1 = 0;
                break;
            }

            if (EXP1 < 300) {
                M1 -= 100;
            }
            else if (EXP1 >= 300) {
                M1 -= 120;
            }
            EXP1 = roundUp(0.9 * EXP1);
            explimit(EXP1);
            if (M1 <= 0) {
                M1 = 0;
                break;
            }
            i++;
        }
        EXP1 = roundUp(EXP1 * 1.17);
        HP1 = roundUp(HP1 * 0.83);
    }
    explimit(EXP1);
    hplimit(HP1);

    int s2 = nearestSquare(EXP1);
    double P2 = 0;
    if (EXP1 >= s2) P2 = 100;
    else P2 = (EXP1 * 1.0 / s2 + 80) * 100.0 / 123;

    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int P3 = 0;
    if (E2 < 10) {
        P3 = P[E2];
    }
    else {
        P3 = P[sum(E2) % 10];
    }

    if (P1 == 100 && P2 == 100 && P3 == 100) {
        EXP1 = roundUp(EXP1 * 0.75);
    }
    else {
        if ((P1 + P2 + P3) / 3 < 50) {
            HP1 = roundUp(HP1 * 0.85);
            EXP1 = roundUp(EXP1 * 1.15);
            explimit(EXP1);
            hplimit(HP1);
        }
        else {
            HP1 = roundUp(HP1 * 0.9);
            EXP1 = roundUp(EXP1 * 1.2);
            explimit(EXP1);
            hplimit(HP1);
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (E3 < 0 || E3>99) return -99;
    explimit(EXP1);
    explimit(EXP2);
    hplimit(HP1);
    hplimit(HP2);

    int matrix[10][10] = {};
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);

    int a = 0, b = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (matrix[i][j] > E3 * 2)
                a++;
            if (matrix[i][j] < -E3)
                b++;
        }
    }

    if (a >= 10)
        Count(a);
    if (b >= 10)
        Count(b);

    int max = matrix[a][b];
    int x = a, y = b;
    while (x > 0 && y > 0) {
        x--;
        y--;
        if (max < matrix[x][y])
            max = matrix[x][y];
    }
    x = a;
    y = b;
    while (x < 9 && y < 9) {
        x++;
        y++;
        if (max < matrix[x][y])
            max = matrix[x][y];
    }
    x = a;
    y = b;
    while (x < 0 && y < 9) {
        x--;
        y++;
        if (max < matrix[x][y])
            max = matrix[x][y];
    }
    x = a;
    y = b;
    while (x < 9 && y>0) {
        x++;
        y--;
        if (max < matrix[x][y])
            max = matrix[x][y];
    }

    if (abs(matrix[a][b]) <= max) {
        EXP1 = roundUp(EXP1 * 1.12);
        HP1 = roundUp(HP1 * 1.1);
        EXP2 = roundUp(EXP2 * 1.12);
        HP2 = roundUp(HP2 * 1.1);
        explimit(EXP1);
        explimit(EXP2);
        hplimit(HP1);
        hplimit(HP2);
        return max;
    }
    else {
        EXP1 = roundUp(EXP1 * 0.88);
        HP1 = roundUp(HP1 * 0.9);
        EXP2 = roundUp(EXP2 * 0.88);
        HP2 = roundUp(HP2 * 0.9);
        explimit(EXP1);
        explimit(EXP2);
        hplimit(HP1);
        hplimit(HP2);
        return matrix[a][b];
    }
    return -1;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    int length = strlen(s);
    if (length < 8) return -1;
    if (length > 20) return -2;

    const char* at_position = strchr(email, '@');
    int substring_length = at_position - email;
    char se[100];
    strncpy(se, email, substring_length);
    se[substring_length] = '\0';
    if (strstr(s, se) != NULL) {
        return -((strstr(s, se) - s) + 300);
    }

    for (int i = 2; i < length; ++i) {
        if (s[i] == s[i - 1] && s[i - 1] == s[i - 2]) return -(400 + i - 2);
    }

    bool check = false;
    for (int i = 0; i < length; i++) {
        if (s[i] == '@' || s[i] == '!' || s[i] == '#' || s[i] == '$' || s[i] == '%') {
            check = true;
            break;
        }
    }
    if (!check) return -5;

    for (int i = 0; i < length; i++) {
        char c = s[i];
        if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || 
            (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '@' || s[i] == '!' || s[i] == '#' ||
            s[i] == '$' || s[i] == '%')) {
            return i; 
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int index = 0;
    int countmax = 0;
    int lengthmax = 0;

    for (int i = 0; i < num_pwds; i++) {
        int count = 1;
        int length = strlen(arr_pwds[i]);

        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }

        if (count > countmax || (count == countmax && length > lengthmax)) {
            index = i;
            countmax = count;
            lengthmax = length;
        }
    }

    return index;
}
