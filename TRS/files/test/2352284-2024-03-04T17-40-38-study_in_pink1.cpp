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


void checkexp(int& exp) {
    if (exp < 0) exp = 0;
    if (exp > 600) exp = 600;
}

void checkhp(int& hp) {
    if (hp < 0) hp = 0;
    if (hp > 666) hp = 666;
}

void checkm(int& m) {
    if (m < 0) m = 0;
    if (m > 3000) m = 3000;
}

bool checke(int& e) {
    return ((e >= 0) && (e <= 99));
}
bool road2(int& e, int m1, double m2) {
    return ((e % 2 == 0 && m1 == 0) || (e % 2 != 0 && (m1 == 0 || m1 < m2 )));
}
// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    if (!checke(e1)) return -99;
    checkexp(exp1);
    checkexp(exp2);
    if (e1 >= 0 && e1 <= 3) {
        switch (e1) {
        case 0:
            exp2 += 29;
            checkexp(exp2);
            break;
        case 1:
            exp2 += 45;
            checkexp(exp2);
            break;
        case 2:
            exp2 += 75;
            checkexp(exp2);
            break;
        case 3:
            exp2 += 149;
            checkexp(exp2);
            break;
        default:
            break;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = ceil(exp1 + D / 200.0);
        else exp1 = ceil(exp1 - D / 100.0);
        checkexp(exp1);
    }
    else if ((e1 >= 4) && (e1 <= 99)) {
        if ((e1 >= 4) && (e1 <= 19)) {
            exp2 += ceil(e1 / 4.0 + 19);
            checkexp(exp2);
        }
        else if ((e1 >= 20) && (e1 <= 49)) {
            exp2 += ceil(e1 / 9.0 + 21);
            checkexp(exp2);
        }
        else if ((e1 >= 50) && (e1 <= 65)) {
            exp2 += ceil(e1 / 16.0 + 17);
            checkexp(exp2);
        }
        else if ((e1 >= 66) && (e1 <= 79)) {
            exp2 += ceil(e1 / 4.0 + 19);
            checkexp(exp2);
            if (exp2 > 200) exp2 += ceil(e1 / 9.0 + 21);
            checkexp(exp2);
        }
        else if ((e1 >= 80) && (e1 <= 99)) {
            exp2 += ceil(e1 / 4.0 + 19);
            checkexp(exp2);
            exp2 += ceil(e1 / 9.0 + 21);
            checkexp(exp2);
            if (exp2 > 400) {
                exp2 += ceil( e1 / 16.0 + 17);
                checkexp(exp2);
                exp2 = ceil(exp2 * 1.15);
                checkexp(exp2);
            }
        }
     exp1 -= e1;
     checkexp(exp1);
    }
    return exp1 + exp2;
}

//Task 2

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (!checke(E2)) return -99;
    checkexp(EXP1);
    checkhp(HP1);
    checkm(M1);

    //Road 1:
    int S = pow(round(sqrt(EXP1)), 2);
    double P1, P2, P3, Pavg;
    if (EXP1 >= S) P1 = 1; else P1 = (EXP1 / S + 80.0) / 123.0;

    //Road 2:
    double budget = M1 / 2.0;
    do {
        if (road2(E2, M1, budget)) break;
        // Buy food and drinks
        if (HP1 < 200) {
            HP1 = ceil(0.3 * HP1 + HP1);
            checkhp(HP1);
            M1 -= 150;
            checkm(M1);
        }
        else {
            HP1 = ceil(HP1 + HP1 * 0.1);
            checkhp(HP1);
            M1 -= 70;
            checkm(M1);
        }   // Done event 1
        if (road2(E2, M1, budget)) break;
        // Rent a taxi or horse
        if (EXP1 < 400) {
            M1 -= 200;
            checkm(M1);
        }
        else {
            M1 -= 120;
            checkm(M1);
        }
        EXP1 = ceil(EXP1 + EXP1 * 0.13);
        checkexp(EXP1);
        //Done event 2
        if (road2(E2, M1, budget)) break;
        // Homeless
        if (EXP1 < 300) {
            M1 -= 100;
            checkm(M1);
        }
        else {
            M1 -= 120;
            checkm(M1);
        }
        EXP1 = ceil(EXP1 * 0.9);
        checkexp(EXP1);
        // Done event 3
        if (road2(E2, M1, budget)) break;
    } while (E2 % 2 != 0);
    HP1 = ceil(HP1 * 0.83);
    checkhp(HP1);
    EXP1 = ceil(EXP1 + EXP1 * 0.17);
    checkexp(EXP1);
    //Calculate P2
    S = pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= S) P2 = 1; else P2 = (EXP1 / S + 80.0) / 123.0;

    //Road 3:
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2 < 10) P3 = P[E2] / 100.0;
    else {
        if (E2 / 10 + E2 % 10 >= 10)
            P3 = P[(E2 / 10 + E2 % 10) % 10] / 100.0;
        else P3 = P[(E2 / 10 + E2 % 10)] / 100.0;
    }
    Pavg = (P1 + P2 + P3) / 3;
    if (P1 == P2 && P2 == P3 && P3 == 1) EXP1 = ceil(EXP1 * 0.75);
    else if (Pavg < 0.5) {
        HP1 = ceil(HP1 * 0.85);
        checkhp(HP1);
        EXP1 = ceil(EXP1 + EXP1 * 0.15);
        checkexp(EXP1);
    }
    else {
        HP1 = ceil(HP1 * 0.9);
        checkhp(HP1);
        EXP1 = ceil(EXP1 + EXP1 * 0.2);
        checkexp(EXP1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (!checke(E3)) return -99;
    checkhp(HP1);
    checkhp(HP2);
    checkexp(EXP1);
    checkexp(EXP2);
    int taximap[10][10] = { 0 }, a = 0, b = 0;

    //Input taxi score:
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            taximap[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taximap[i][j] > E3 * 2) a++;
            else if (taximap[i][j] < E3 * -1) b++;
        }
    }
    // find meeting point:
    while (a >= 10) {
        a = a / 10 + a % 10;
    }
    while (b >= 10) {
        b = b / 10 + b % 10;
    }
    //Find Sherlock and Watson's score:
    int snw = taximap[a][b];
    int seta = a, setb = b;
    while (a >= 0 && b >= 0) {
        if (taximap[a][b] > snw) snw = taximap[a][b];
        --a;
        --b;
    }
    a = seta;
    b = setb;
    while (a <= 9 && b <= 9) {
        if (taximap[a][b] > snw) snw = taximap[a][b];
        ++a;
        ++b;
    }
    a = seta;
    b = setb;
    while (a <= 9 && b >= 0) {
        if (taximap[a][b] > snw) snw = taximap[a][b];
        ++a;
        --b;
    }
    a = seta;
    b = setb;
    while (a >= 0 && b <= 9) {
        if (taximap[a][b] > snw) snw = taximap[a][b];
        --a;
        ++b;
    }
    a = seta;
    b = setb;
    if (snw < 0) snw = -snw;
    // Catching taxi:
    if (abs(taximap[a][b]) > snw) {
        EXP1 = ceil(EXP1 - EXP1 * 0.12);
        checkexp(EXP1);
        EXP2 = ceil(EXP2 - EXP2 * 0.12);
        checkexp(EXP2);
        HP1 = ceil(HP1 - HP1 * 0.1);
        checkhp(HP1);
        HP2 = ceil(HP2 - HP2 * 0.1);
        checkhp(HP2);
        return taximap[a][b];
    }
    else {
        EXP1 = ceil(EXP1 + EXP1 * 0.12);
        checkexp(EXP1);
        EXP2 = ceil(EXP2 + EXP2 * 0.12);
        checkexp(EXP2);
        HP1 = ceil(HP1 + HP1 * 0.1);
        checkhp(HP1);
        HP2 = ceil(HP2 + HP2 * 0.1);
        checkhp(HP2);
        return snw;
    }
}

// Task 4
int checkPassword(const char* s, const char* email) {
    string stremail = email, strs = s;
    string se = stremail.substr(0, stremail.find('@'));
    //check length of s:
    size_t l = strs.length();
    if (l < 8) return -1;
    if (l > 20) return -2;
    //check s contain se:
    size_t cse = strs.find(se);
    if (cse != string::npos) return -(300 + int(cse));
    //check for 2 consecutive identical char:
    for (int i = 1; i < l; ++i) {
        if (strs[i - 1] == strs[i] && strs[i] == strs[i + 1]) return -(400 + (i - 1));
    }
    //check for special character
    string special = { "!@#$%" };
    size_t sp = strs.find_first_of(special);
    if (sp == string::npos) return-5;
    //check for any invalid character:
    string validchar = { "!@#$%0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" };
    size_t vc = strs.find_first_not_of(validchar);
    if (vc != string::npos) return int(vc);
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int maxcounter = 0, index = 0;
    size_t maxl = 0;
    for (int i = 0; i < num_pwds; ++i) {
        int counter = 1;
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) counter++;
        }
        size_t l = strlen(arr_pwds[i]);
        if (counter > maxcounter || (counter == maxcounter && l > maxl)) {
            maxcounter = counter;
            maxl = l;
            index = i;
        }
    }
   return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////