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

// Conditions
void conhp(int& hp) {
    if (hp < 0) hp = 0;
    if (hp > 666) hp = 666;
}

void conexp(int& exp) {
    if (exp < 0) exp = 0;
    if (exp > 600) exp = 600;
}

void conm(int& m) {
    if (m < 0) m = 0;
    if (m > 3000) m = 3000;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    conexp(exp1); conexp(exp2);
    if (e1 < 0 || e1 > 99) return -99;
    else {
        if (e1 >= 0 && e1 <= 3) {
            switch (e1) {
                case 0: exp2 += 29; break;
                case 1: exp2 += 45; break;
                case 2: exp2 += 75; break;
                case 3: exp2 += 29 + 45 + 75; break;
            }
            conexp(exp2);
            int D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0) {
                exp1 += ceil(double(D) / 200);
                conexp(exp1);
            }
            else {
                exp1 = ceil(exp1 - double(D) / 100);
                conexp(exp1);
            }
        }
        if (e1 >= 4 && e1 <= 99) {
            if (e1 >= 4 && e1 <= 19) {
                exp2 += ceil(double(e1) / 4) + 19;
                conexp(exp2);
            }
            if (e1 >= 20 && e1 <= 49) {
                exp2 += ceil(double(e1) / 9) + 21;
                conexp(exp2);
            } 
            if (e1 >= 50 && e1 <= 65) {
                exp2 += ceil(double(e1) / 16) + 17;
                conexp(exp2);
            } 
            if (e1 >= 66 && e1 <= 79) {
                exp2 += ceil(double(e1) / 4) + 19;
                conexp(exp2);
                if (exp2 > 200) {
                    exp2 += ceil(double(e1) / 9) + 21;
                    conexp(exp2);
                } 
            }
            if (e1 >= 80 && e1 <= 99) {
                exp2 += ceil(double(e1) / 4) + 19;
                conexp(exp2);
                exp2 += ceil(double(e1) / 9) + 21;
                conexp(exp2);
                if (exp2 > 400) {
                    exp2 += ceil(double(e1) / 16) + 17;
                    conexp(exp2);
                    exp2 = ceil(double(115 * exp2) / 100);
                }
                conexp(exp2);
            }
            exp1 -= e1;
            conexp(exp1);
        }
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;
    conm(M1); conhp(HP1); conexp(EXP1);
    int s, spend = 0;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}, i;
    double hm = 0.5 * M1;
    double p1, p2, p3, _p;
    // Way 1
    s = pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= s) p1 = 1;
    else p1 = ((double(EXP1) / s) + 80) / 123;

    // Way 2
    if (E2 % 2 != 0) {
        while (spend <= hm) {
            // Event 1
            if (HP1 < 200) {
                HP1 = ceil(double(HP1 * 130) / 100);
                conhp(HP1);
                spend += 150;
            } else {
                HP1 = ceil(double(HP1 * 110) / 100);
                conhp(HP1);
                spend += 70;
            }
            if (spend > hm) break;
            // Event 2
            if (EXP1 < 400) {
                spend += 200;
            } else {
                spend += 120;
            }
            EXP1 = ceil(double(EXP1 * 113) / 100);
            conexp(EXP1);
            if (spend > hm) break;
            // Event 3
            if (EXP1 < 300) {
                spend += 100;
            } else {
                spend += 120;
            }
            EXP1 = ceil(double(EXP1 * 90) / 100);
            conexp(EXP1);
        }
        EXP1 = ceil(double(EXP1 * 117) / 100);
        conexp(EXP1);
        HP1 = ceil(double(HP1 * 83) / 100);
        conhp(HP1);
        M1 -= spend;
        conm(M1);
    } else {
        // Event 1
        if (HP1 < 200) {
            HP1 = ceil(double(HP1 * 130) / 100);
            conhp(HP1);
            M1 -= 150;
            conm(M1);
        } else {
            HP1 = ceil(double(HP1 * 110) / 100);
            conhp(HP1);
            M1 -= 70;
            conm(M1);
        }
        if (M1 == 0) goto walk;
        // Event 2
        if (EXP1 < 400) {
            M1 -= 200;
            conm(M1);
        } else {
            M1 -= 120;
            conm(M1);
        }
        EXP1 = ceil(double(EXP1 * 113) / 100);
        conexp(EXP1);
        if (M1 == 0) goto walk;
        // Event 3
        if (EXP1 < 300) {
            M1 -= 100;
            conm(M1);
        } else {
            M1 -= 120;
            conm(M1);
        }
        EXP1 = ceil(double(EXP1 * 90) / 100);
        conexp(EXP1);
        walk:
        EXP1 = ceil(double(EXP1 * 117) / 100);
        conexp(EXP1);
        HP1 = ceil(double(HP1 * 83) / 100);
        conhp(HP1);
    }
    s = pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= s) p2 = 1;
    else p2 = ((double(EXP1) / s) + 80) / 123;
    // Way 3
    if (E2 >= 0 && E2 < 10) i = E2;
    if (E2 >= 10 && E2 < 100) {
        i = (E2 / 10 + E2 % 10) % 10;
    }
    p3 = P[i];
    // Caclculate
    p1 *= 100; p2 *= 100;
    if (p1 == 100 && p2 == 100 && p3 ==100) EXP1 = ceil(double(EXP1 * 75) / 100);
    else {
        _p = (p1 + p2 + p3) / 3;
        if (_p < 50) {
            HP1 = ceil(double(HP1 * 85) / 100);
            EXP1 = ceil(double(EXP1 * 115) / 100);
            conhp(HP1);
            conexp(EXP1);
        } else {
            HP1 = ceil(double(HP1 * 90) / 100);
            EXP1 = ceil(double(EXP1 * 120) / 100);
            conhp(HP1);
            conexp(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    int taxipoint[10][10], ci = 0, cj = 0, x, y;
    // Generate taxi points
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxipoint[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taxipoint[i][j] > 2 * E3) ci++;
            if (taxipoint[i][j] < - E3) cj++;
        }
    }
    // Calculate cordinate
    x = (ci / 10 + ci % 10);
    if (x >= 10) x = (x / 10 + x % 10);
    y = (cj / 10 + cj % 10);
    if (y >= 10) y = (y / 10 + y % 10);
    int points = taxipoint[x][y];
    int i = x - 1, j = y - 1;
    while (i > 0 && j > 0) {
        if (taxipoint[i][j] > points) points = taxipoint[i][j];
        i--;
        j--;
    }
    i = x + 1; j = y + 1;
    while (i < 10 && j < 10) {
        if (taxipoint[i][j] > points) points = taxipoint[i][j];
        i++;
        j++;
    }
    i = x - 1; j = y + 1;
    while (i > 0 && j < 10) {
        if (taxipoint[i][j] > points) points = taxipoint[i][j];
        i--;
        j++;
    }
    i = x + 1; j = y - 1;
    while (i < 10 && j > 0) {
        if (taxipoint[i][j] > points) points = taxipoint[i][j];
        i++;
        j--;
    }
    if (abs(taxipoint[x][y]) > points) {
        EXP1 = ceil(double(EXP1 * 88) / 100);
        EXP2 = ceil(double(EXP2 * 88) / 100);
        conexp(EXP1); conexp(EXP2);
        HP1 = ceil(double(HP1 * 90) / 100);
        HP2 = ceil(double(HP2 * 90) / 100);
        conhp(HP1); conhp(HP2);
        return taxipoint[x][y];
    } else {
        EXP1 = ceil(double(EXP1 * 112) / 100);
        EXP2 = ceil(double(EXP2 * 112) / 100);
        conexp(EXP1); conexp(EXP2);
        HP1 = ceil(double(HP1 * 110) / 100);
        HP2 = ceil(double(HP2 * 110) / 100);
        conhp(HP1); conhp(HP2);
        return points;
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    char at = '@', excl = '!', shrp = '#', prct = '%', dlr = '$';
    string se, _email(email), _s(s);
    size_t found = _email.find(at);
    se = _email.substr(0, found); 
    int lp = _s.length();
    // Check Password
    found = _s.find(se);
    if (lp < 8) return -1;
    if (lp > 20) return -2;
    if (found != -1) return - (300 + found);
    for (int i = 0; i < lp - 2; i++) {
        if (_s[i] == _s[i + 1] && _s[i + 1] == _s[i + 2]) return - (400 + i);
    }
    if (_s.find(at) != -1 || _s.find(shrp) != -1 || _s.find(prct) != -1 || _s.find(excl) != -1 || _s.find(dlr) != -1) {
    } else return -5;
    for (int i = 0; i < lp; i++) {
        if ((_s[i] >= 35 && _s[i] <= 37) || (_s[i] >= 48 && _s[i] <= 57) || (_s[i] >= 64 && _s[i] <= 90) || (_s[i] >= 97 && _s[i] <= 122) || (_s[i] == 33)) {
        } else return i;
    }
    return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int temp[num_pwds], freq[num_pwds], length_pwds[num_pwds], trueorder[num_pwds];
    string order_pwds[num_pwds];
    int countfreq = 0, maxfreq = -1, maxlength = -1, countmaxfreq = 0, truecount = 0;
    for (int i = 0; i < num_pwds; i++) temp[i] = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (temp[i] == 0) {
            int count = 0;
            for (int j = i; j < num_pwds; j++) {
                if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                    count++;
                    temp[j] = 1;
                }
            }
            length_pwds[countfreq] = strlen(arr_pwds[i]);
            order_pwds[countfreq] = arr_pwds[i];
            freq[countfreq++] = count;
        }
    }
    // Most appear
    for (int i = 0; i < countfreq; i++) {
        maxfreq = max(maxfreq, freq[i]);
    }
    // Sort the same max appear
    for (int i = 0; i < countfreq; i++) {
        if (maxfreq == freq[i]) {
            trueorder[truecount++] = i;
        }
    }
    // Find max length
    for (int i = 0; i < countfreq; i++) {
        if (maxfreq == freq[i]) {
            countmaxfreq += 1;
            if (countmaxfreq > 1) {
                for (int i = 0; i < truecount; i++) {
                    maxlength = max(length_pwds[trueorder[i]], maxlength);
                }
            } 
        }
    }
    if (countmaxfreq == 1) {
        for (int i = 0; i < countfreq; i++) {
            if (freq[i] == maxfreq) {
                for (int j = 0; j < num_pwds; j++) {
                    if (order_pwds[i] == arr_pwds[j]) {
                        return j;
                    }
                }
            }
        }
    } else {
        for (int i = 0; i < countfreq; i++) {
            if (freq[i] == maxfreq) {
                if (length_pwds[i] == maxlength) {
                    for (int j = 0; j < num_pwds; j++) {
                        if (order_pwds[i] == arr_pwds[j]) {
                            return j;
                        }
                    }
                }
            }
        }
    }
    return -1;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////