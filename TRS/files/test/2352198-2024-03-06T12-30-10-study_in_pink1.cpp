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
int HPlimit(int HP) {
    if (HP > 666) HP = 666;
    else if (HP < 0) HP = 0;
    return HP;
}
int EXPlimit(int EXP) {
    if (EXP > 600) EXP = 600;
    else if (EXP < 0) EXP = 0;
    return EXP;
}
int Mlimit(int M) {
    if (M > 3000) M = 3000;
    else if (M < 0) M = 0;
    return M;
}

int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    if (e1 > 99 || e1 < 0) {
        return -99;
    }
    else {
        exp1 = EXPlimit(exp1);
        exp2 = EXPlimit(exp2);
        double sub1, sub2;
        sub1 = exp1;
        sub2 = exp2;
        if (e1 >= 0 && e1 <= 3) {
            switch (e1) {
            case 0:
                sub2 = sub2 + 29;
                sub2 = EXPlimit(sub2);
                break;
            case 1:
                sub2 = sub2 + 45;
                sub2 = EXPlimit(sub2);
                break;
            case 2:
                sub2 = sub2 + 75;
                sub2 = EXPlimit(sub2);
                break;
            case 3:
                sub2 = sub2 + 149;
                sub2 = EXPlimit(sub2);
                break;
            }
            int even = e1 * 3 + sub1 * 7;
            if (even % 2 == 0) {
                sub1 += even * 1.0 / 200;
                sub1 = ceil(sub1);
                sub1 = EXPlimit(sub1);
            }
            else {
                sub1 -= even * 1.0 / 100;
                sub1 = ceil(sub1);
                sub1 = EXPlimit(sub1);
            }
        }
        if (e1 >= 4 && e1 <= 99) {
            if (e1 >= 4 && e1 <= 19) {
                sub2 = sub2 + e1 * 1.0 / 4 + 19;
                sub2 = ceil(sub2);
                sub2 = EXPlimit(sub2);
            }
            else if (e1 >= 20 && e1 <= 49) {
                sub2 = sub2 + e1 * 1.0 / 9 + 21;
                sub2 = ceil(sub2);
                sub2 = EXPlimit(sub2);
            }
            else if (e1 >= 50 && e1 <= 65) {
                sub2 = sub2 + e1 * 1.0 / 16 + 17;
                sub2 = ceil(sub2);
                sub2 = EXPlimit(sub2);
            }
            else if (e1 >= 66 && e1 <= 79) {
                sub2 = sub2 + e1 * 1.0 / 4 + 19;
                sub2 = ceil(sub2);
                sub2 = EXPlimit(sub2);
                if (sub2 > 200) {
                    sub2 = sub2 + e1 * 1.0 / 9 + 21;
                    sub2 = ceil(sub2);
                    sub2 = EXPlimit(sub2);
                }
            }
            else if (e1 >= 80 && e1 <= 99) {
                sub2 = sub2 + e1 * 1.0 / 4 + 19;
                sub2 = ceil(sub2);
                sub2 = EXPlimit(sub2);
                sub2 = sub2 + e1 * 1.0 / 9 + 21;
                sub2 = ceil(sub2);
                sub2 = EXPlimit(sub2);
                if (sub2 > 400) {
                    sub2 = sub2 + e1 * 1.0 / 16 + 17;
                    sub2 = ceil(sub2);
                    sub2 = EXPlimit(sub2);
                    sub2 = sub2 * 1.15;
                    sub2 = ceil(sub2);
                    sub2 = EXPlimit(sub2);
                }
            }
            sub1 = sub1 - e1;
            sub1 = EXPlimit(sub1);
        }
        exp1 = sub1;
        exp2 = sub2;
        return exp1 + exp2;
    }
}

// Task 2
bool socp(int n) {
    int a = sqrt(n);
    return a * a == n;
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if (E2 > 99 || E2 < 0) {
        return -99;
    }
    else {
        EXP1 = EXPlimit(EXP1);
        HP1 = HPlimit(HP1);
        M1 = Mlimit(M1);
        int S;
        if (socp(EXP1)) {
            S = EXP1;
        }
        else {
            int lower = sqrt(EXP1);
            int higher = lower + 1;
            if (abs(EXP1 - lower * lower) <= abs(EXP1 - higher * higher)) {
                S = lower * lower;
            }
            else {
                S = higher * higher;
            }
        }
        double P1;
        if (EXP1 >= S) {
            P1 = 100;
        }
        else {
            P1 = (EXP1 * 1.0 / S + 80) / 123 * 100;
        }
        float sub1 = EXP1;
        float sub2 = HP1;
        double limit = M1 * 1.0 / 2;
        int paid = 0;
        if (E2 % 2 == 1) {
            while (paid <= limit) {
                if (sub2 < 200) {
                    sub2 *= 1.3;
                    sub2 = ceil(sub2);
                    sub2 = HPlimit(sub2);
                    paid += 150;
                }
                else {
                    sub2 *= 1.1;
                    sub2 = ceil(sub2);
                    sub2 = HPlimit(sub2);
                    paid += 70;
                }
                if (paid > limit) break;
                if (sub1 < 400) {
                    paid += 200;
                    sub1 *= 1.13;
                    sub1 = ceil(sub1);
                    sub1 = EXPlimit(sub1);
                }
                else {
                    paid += 120;
                    sub1 *= 1.13;
                    sub1 = ceil(sub1);
                    sub1 = EXPlimit(sub1);
                }
                if (paid > limit) break;
                if (sub1 < 300) {
                    paid += 100;
                }
                else {
                    paid += 120;
                }
                sub1 *= 0.9;
                sub1 = ceil(sub1);
                sub1 = EXPlimit(sub1);
                if (paid > limit) break;
            }
        }
        else {
            for (int i = 0; i < 1; i++) {
                if (sub2 < 200) {
                    sub2 *= 1.3;
                    sub2 = ceil(sub2);
                    sub2 = HPlimit(sub2);
                    paid += 150;
                    if (paid >= M1) break;
                }
                else {
                    sub2 *= 1.1;
                    sub2 = ceil(sub2);
                    sub2 = HPlimit(sub2);
                    paid += 70;
                    if (paid >= M1) break;
                }
                if (sub1 < 400) {
                    paid += 200;
                    sub1 *= 1.13;
                    sub1 = ceil(sub1);
                    sub1 = EXPlimit(sub1);
                    if (paid >= M1) break;
                }
                else {
                    paid += 120;
                    sub1 *= 1.13;
                    sub1 = ceil(sub1);
                    sub1 = EXPlimit(sub1);
                    if (paid >= M1) break;
                }
                if (sub1 < 300) {
                    paid += 100;
                    sub1 *= 0.9;
                    sub1 = ceil(sub1);
                    sub1 = EXPlimit(sub1);
                    if (paid >= M1) break;

                }
                else {
                    paid += 120;
                    sub1 *= 0.9;
                    sub1 = ceil(sub1);
                    sub1 = EXPlimit(sub1);
                    if (paid > M1) break;
                }
            }
        }
        sub2 *= 0.83;
        sub2 = ceil(sub2);
        sub2 = HPlimit(sub2);
        sub1 *= 1.17;
        sub1 = ceil(sub1);
        sub1 = EXPlimit(sub1);
        M1 -= paid;
        M1 = Mlimit(M1);
        double P2;
        if (socp(sub1)) {
            S = sub1;
        }
        else {
            int lower = sqrt(sub1);
            int higher = lower + 1;
            if (abs(sub1 - lower * lower) <= abs(sub1 - higher * higher)) {
                S = lower * lower;
            }
            else {
                S = higher * higher;
            }
        }
        if (sub1 >= S) {
            P2 = 100;
        }
        else {
            P2 = (sub1 / S + 80) / 123 * 100;
        }
        double P3;
        int i;
        int sum = 0;
        int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        if (E2 < 10) {
            i = P[E2];
        }
        else {
            int sum = 0;
            sum = sum + E2 / 10 + E2 % 10;
            sum = sum % 10;
            i = P[sum];
        }
        P3 = i;
        double avg = (P1 + P2 + P3) / 3;
        if (avg == 100) {
            sub1 *= 0.75;
            sub1 = ceil(sub1);
            sub1 = EXPlimit(sub1);
        }
        else if (avg >= 0 && avg < 50) {
            sub2 *= 0.85;
            sub2 = ceil(sub2);
            sub2 = HPlimit(sub2);
            sub1 *= 1.15;
            sub1 = ceil(sub1);
            sub1 = EXPlimit(sub1);
        }
        else {
            sub2 *= 0.9;
            sub2 = ceil(sub2);
            sub2 = HPlimit(sub2);
            sub1 *= 1.2;
            sub1 = ceil(sub1);
            sub1 = EXPlimit(sub1);
        }
        EXP1 = sub1;
        HP1 = sub2;

        return HP1 + EXP1 + M1;
    }
}
// Task 3
const int row = 10;
const int col = 10;

void taxi(int E3, int taxiscore[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int score = ((E3 * j) + (i * 2)) * (i - j);
            taxiscore[i][j] = score;
        }
    }
}

void chase(int chasescore[row][col], int taxiscore[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int maxtopleft = INT_MIN;
            int maxtopright = INT_MIN;
            int maxbottomright = INT_MIN;
            int maxbottomleft = INT_MIN;
            int max;

            for (int k = 0; i + k < 10 && j + k < 10; k++) {
                if (taxiscore[i + k][j + k] > maxbottomright) maxbottomright = taxiscore[i + k][j + k];
            }

            for (int k = 0; i - k >= 0 && j - k >= 0; k++) {
                if (taxiscore[i - k][j - k] > maxtopleft) maxtopleft = taxiscore[i - k][j - k];
            }

            for (int k = 0; i + k < 10 && j - k >= 0; k++) {
                if (taxiscore[i + k][j - k] > maxbottomleft) maxbottomleft = taxiscore[i + k][j - k];
            }

            for (int k = 0; i - k >= 0 && j + k < 10; k++) {
                if (taxiscore[i - k][j + k] > maxtopright) maxtopright = taxiscore[i - k][j + k];
            }
            max = maxbottomright;
            if (maxtopleft > max) max = maxtopleft;
            if (maxbottomleft > max) max = maxbottomleft;
            if (maxtopright > max) max = maxtopright;
            chasescore[i][j] = max;
        }

    }
}

int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 > 99 || E3 < 0) {
        return -99;
    }
    else {
        EXP1 = EXPlimit(EXP1);
        EXP2 = EXPlimit(EXP2);
        HP1 = HPlimit(HP1);
        HP2 = HPlimit(HP2);
        int i, j;
        int taxiscore[row][col];
        int chasescore[row][col];

        taxi(E3, taxiscore);
        chase(chasescore, taxiscore);
        int pos = 0, neg = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (taxiscore[i][j] > E3 * 2) pos += 1;
                else if (taxiscore[i][j] < -E3) neg += 1;
            }
        }
        if (pos < 10) {
            i = pos;
        }
        else {
            while (pos >= 10) {
                i = pos / 10 + pos % 10;
                pos = i;
            }
        }
        if (neg < 10) {
            j = neg;
        }
        else {
            while (neg >= 10) {
                j = neg / 10 + neg % 10;
                neg = j;
            }
        }
        int result;
        float sub1, sub2, sub3, sub4;
        sub1 = HP1;
        sub2 = EXP1;
        sub3 = HP2;
        sub4 = EXP2;
        if (abs(taxiscore[i][j]) > abs(chasescore[i][j])) {
            sub1 *= 0.9;
            sub1 = ceil(sub1);
            sub1 = HPlimit(sub1);
            sub2 *= 0.88;
            sub2 = ceil(sub2);
            sub2 = EXPlimit(sub2);
            sub3 *= 0.9;
            sub3 = ceil(sub3);
            sub3 = HPlimit(sub3);
            sub4 *= 0.88;
            sub4 = ceil(sub4);
            sub4 = EXPlimit(sub4);
            result = taxiscore[i][j];
        }
        else {
            sub1 *= 1.1;
            sub1 = ceil(sub1);
            sub1 = HPlimit(sub1);
            sub2 *= 1.12;
            sub2 = ceil(sub2);
            sub2 = EXPlimit(sub2);
            sub3 *= 1.1;
            sub3 = ceil(sub3);
            sub3 = HPlimit(sub3);
            sub4 *= 1.12;
            sub4 = ceil(sub4);
            sub4 = EXPlimit(sub4);
            result = chasescore[i][j];
        }
        HP1 = sub1;
        EXP1 = sub2;
        HP2 = sub3;
        EXP2 = sub4;
        return result;
    }
}

// Task 4
bool special(const string& password) {
    bool special = false;

    for (char c : password) {
        if (c == '@' || c == '#' || c == '$' || c == '%' || c == '!') {
            special = true;
        }
    }
    return special;
}

int password(const string& s, const string& email) {
    string se = email.substr(0, email.find('@'));
    if (s.length() < 8) return -1;
    if (s.length() > 20) return -2;
    const char* se_cstr = se.c_str();
    const char* s_cstr = s.c_str();
    if (strstr(s_cstr, se_cstr) != nullptr) {
        size_t sei = strstr(s_cstr, se_cstr) - s_cstr;
        return -(300 + sei);
    }
    for (size_t i = 0; i < s.length() - 2; ++i) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            int sci = i;
            return -(400 + sci);
        }
    }
    bool Special = false;
    if (!special(s)) return -5;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '[') return i;
    }
    return -10;
}
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    int passwordResult = password(s, email);
    return passwordResult;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int finalcount = 0;
    int finallength = 0;
    string result;
    for (int i = 0; i < num_pwds; ++i) {
        string password = arr_pwds[i];
        int length = password.length();
        int count = 1;
        for (int j = i + 1; j < num_pwds; ++j) {
            if (arr_pwds[j] == password) {
                count++;
            }
        }
        if (count > finalcount || (count == finalcount && length > finallength)) {
            finalcount = count;
            finallength = length;
            result = password;
        }
    }

    for (int i = 0; i < num_pwds; ++i) {
        if (arr_pwds[i] == result) {
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////