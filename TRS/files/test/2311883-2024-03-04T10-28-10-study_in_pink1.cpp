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
int checkLimit(int var,int min,int max){
    int result=var;
    if (var < min)
        result = min;
    else if (var > max)
        result = max;
    return result;
}
bool checkMoney(int& use, int M,int E) {
    int mleft = M - use;
    if (E % 2 != 0) {
        if (use > (50 * M / 100))
            return 1;
    }
    else {
        M = checkLimit(mleft, 0, 3000);
        if (M == 0)
            return 1;
    }
    return 0;
}
//Task 1
int firstMeet(int& exp1, int& exp2, int e1) { 
    if (e1 < 0 || e1>99)
        return -99;
    exp1 = checkLimit(exp1, 0, 600);
    exp2 = checkLimit(exp2, 0, 600);
    float check;
    //case1
    if (e1 >= 0 && e1 <= 3){       
        switch (e1){
        case 0:
            exp2 += 29;
            break;
        case 1:
            exp2 += 45;
            break;
        case 2:
            exp2 += 75;
            break;
        default:
            exp2 += 29 + 45 + 75;
        }
        int D = e1 * 3 + exp1 * 7;
        check = exp1;
        if (D % 2 == 0)
            check += float(D) / float(200);
        else
            check -= float(D) / float(100);
        exp1 = ceil(check);
    }
    //case2
    else if (e1 >= 4 && e1 <= 99){      
        if (e1 <= 19){
            check = exp2+float(e1) / float(4) + 19;
            exp2 = ceil(check);       
        }
        else if (e1 >= 20 && e1 <= 49){
            check = exp2+float(e1) / float(9) + 21;
            exp2 = ceil(check);
        }
        else if (e1 >= 50 && e1 <= 65){
            check =exp2+ float(e1) / float(16) + 17;
            exp2 = ceil(check);
        }
        else if (e1 >= 66 && e1 <= 79){
            check =exp2+ float(e1) / float(4) + 19;
            exp2 = ceil(check);
            if (exp2 > 200){
                check =exp2+ float(e1) / float(9) + 21;
                exp2 = ceil(check);
            }
        }
        else if (e1 >= 80) {
            check = exp2 + float(e1) / float(4) + 19;
            exp2 = ceil(check);
            check = exp2 + float(e1) / float(9) + 21;
            exp2 = ceil(check);
            if (exp2 > 400) {
                check = exp2 + float(e1) / float(16) + 17;
                exp2 = ceil(check);
                check = exp2 * 1.15;
                exp2 = ceil(check);
            }
        }
        exp1 -= e1;
    }
    exp1 = checkLimit(exp1, 0, 600);
    exp2 = checkLimit(exp2, 0, 600);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    int use(0), S;
    float check, n, p1, p2, p3, pall;
    if (E2 < 0 || E2 > 99)
        return -99;
    EXP1 = checkLimit(EXP1, 0, 600);
    HP1 = checkLimit(HP1, 0, 666);
    M1 = checkLimit(M1, 0, 3000); 
    //way1 
    S = EXP1;
    for (int i = 1;; i++) {
        n = sqrt(S);
        if (n == int(n))
            break;
        else {
            if (i % 2 == 0)
                S -= i;
            else S += i;
            n = sqrt(S);
            if (n == int(n))
                break;
        }
    }
    if (EXP1 >= S)
        p1 = 1;
    else p1 = ((float(EXP1) / float(S)) + 80) / float(123);
    //way2             
    for (int i = 0;; i++) {
        if (M1 == 0)
            break;
        if (HP1 < 200) {
            check = HP1*1.3;
            use += 150;
            HP1 = ceil(check);
        }
        else {
            check = HP1*1.1;
            use += 70;
            HP1 = ceil(check);
        }
        HP1 = checkLimit(HP1, 0, 666);
        if (checkMoney(use, M1, E2) == 1)
            break;      
        if (EXP1 < 400)
            use += 200;
        else
            use += 120;
        check = EXP1 * 1.13;
        EXP1 = ceil(check);
        EXP1 = checkLimit(EXP1, 0, 600);
        if (checkMoney(use, M1, E2) == 1)
            break;
        if (EXP1 < 300)
            use += 100;
        else
            use += 120;
        check = EXP1 * 0.9;
        EXP1 = ceil(check);
        EXP1 = checkLimit(EXP1, 0, 600);
        if (checkMoney(use, M1, E2) == 1 || (E2 % 2 == 0))
            break;
    }
    M1 = M1 - use;
    M1 = checkLimit(M1, 0, 3000);
    check = HP1 * 0.83;
    HP1 = ceil(check);
    check = EXP1 * 1.17;
    EXP1 = ceil(check);
    HP1 = checkLimit(HP1, 0, 666);
    EXP1 = checkLimit(EXP1, 0, 600);
    S = EXP1;
    for (int i = 1;; i++) {
        n = sqrt(S);
        if (n == int(n))
            break;
        else {
            if (i % 2 == 0)
                S -= i;
            else S += i;
            n = sqrt(S);
            if (n == int(n))
                break;
        }
    }
    if (EXP1 >= S)
        p2 = 1;
    else p2 = ((float(EXP1) /float(S) + 80) / float(123));
    //WAY3
    int P[10] = { 32,47,28,79,100,50,22,83,64,11 };
    int chuc, dvi;
    if (E2 >= 10) {
        chuc = E2 / 10;
        dvi = E2 % 10;
        E2 = chuc + dvi;
        if(E2>=10)
            E2 = E2 % 10;
    }
    p3 = P[E2];
    pall = (p1 + p2 + p3 / 100) / 3;
    if (p1 == 1 && p2 == 1 && p3 == 100) {
        check = EXP1 * 0.75;
        EXP1 = ceil(check);
    }
    else {
        if (pall < 0.5) {
            check = HP1 * 0.85;
            HP1 = ceil(check);
            check = EXP1 * 1.15;
            EXP1 = ceil(check);
        }
        else if (pall >= 0.5) {
            check = HP1 * 0.9;
            HP1 = ceil(check);
            check = EXP1 * 1.2;
            EXP1 = ceil(check);
        }
    }
    EXP1 = checkLimit(EXP1, 0, 600);
    HP1 = checkLimit(HP1, 0, 666);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (E3 < 0 || E3 > 99)
        return -99;
    EXP1 = checkLimit(EXP1, 0, 600);
    HP1 = checkLimit(HP1, 0, 666);
    EXP2 = checkLimit(EXP2, 0, 600);
    HP2 = checkLimit(HP2, 0, 666);
    int taxi[10][10] = {};
    int countp(0), countn(0);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taxi[i][j] > 0 && taxi[i][j] > E3 * 2)
                countp += 1;
            else if (taxi[i][j] < 0 && taxi[i][j] < -E3)
                countn += 1;
        }
    }
    int cheotrai[10], cheophai[10];
    int chuc, dvi;
    while (countp >= 10) {
        chuc = countp / 10;
        dvi = countp % 10;
        countp = chuc + dvi;
    }
    while (countn >= 10) {
        chuc = countn / 10;
        dvi = countn % 10;
        countn = chuc + dvi;
    }
    int row = countp, col = countn, a(0), b;
        for (int i = 0;; i++) {
            if (row + i > 9 || col + i > 9)
                break;
            cheotrai[a] = taxi[row + i][col + i];
            a++;
        }
        for (int i = 1;; i++) {
            if (row - i < 0 || col - i < 0) {
                --a;
                break;
            }
            cheotrai[a] = taxi[row - i][col - i];
            a++;
        }
        b = 0;
        for (int i = 0;; i++) {
            if (row + i > 9 || col - i < 0)
                break;
            cheophai[b] = taxi[row + i][col - i];
            b++;
        }
        for (int i = 1;; i++) {
            if (row - i < 0 || col + i > 9) {
                --b;
                break;
            }             
            cheophai[b] = taxi[row - i][col + i];
            b++;
        }
    int lmax, rmax;
    if (a == 0)
        lmax = cheotrai[a];
    if(b==0)
        rmax = cheophai[b];
    if(a!=0 || b!=0) {
        for (int j = 0; j < a; j++) {
            if (cheotrai[j] >= cheotrai[j + 1]) {
                lmax = cheotrai[j];
                cheotrai[j] = cheotrai[j + 1];
                cheotrai[j + 1] = lmax;
            }
            else {
                lmax = cheotrai[j + 1];
                continue;
            }
        }
        for (int j = 0; j < b; j++) {
            if (cheophai[j] >= cheophai[j + 1]) {
                rmax = cheophai[j];
                cheophai[j] = cheophai[j + 1];
                cheophai[j + 1] = rmax;
            }
            else {
                rmax = cheophai[j + 1];
                continue;
            }
        }
    }
    int sw;
    float check;
    if (lmax > rmax)
        sw = lmax;
    else sw = rmax;
    if (abs(taxi[countp][countn]) > abs(sw)) {
        check = EXP1 * 0.88;
        EXP1 = ceil(check);
        check = EXP2 * 0.88;
        EXP2 = ceil(check);
        check = HP1 * 0.9;
        HP1 = ceil(check);
        check = HP2 * 0.9;
        HP2 = ceil(check);
        EXP1 = checkLimit(EXP1, 0, 600);
        HP1 = checkLimit(HP1, 0, 666);
        EXP2 = checkLimit(EXP2, 0, 600);
        HP2 = checkLimit(HP2, 0, 666);
        return taxi[countp][countn];
    }
    else {
        check = EXP1 * 1.12;
        EXP1 = ceil(check);
        check = EXP2 * 1.12;
        EXP2 = ceil(check);
        check = HP1 * 1.1;
        HP1 = ceil(check);
        check = HP2 * 1.1;
        HP2 = ceil(check);
        EXP1 = checkLimit(EXP1, 0, 600);
        HP1 = checkLimit(HP1, 0, 666);
        EXP2 = checkLimit(EXP2, 0, 600);
        HP2 = checkLimit(HP2, 0, 666);
        return sw;
    }
    
}

// Task 4
int checkPassword(const char* s, const char* email) {
    string cemail(email), cs(s);
    int a = cemail.find("@");
    cemail.erase(a);
    int sei = cs.find(cemail);
    if (cs.size() < 8)
        return -1;
    if (cs.size() > 20)
        return -2;
    if (sei != -1)
        return -(300 + sei);
    for (int i = 0; i <= cs.size() - 3; i++) {
        if (cs[i] == cs[i + 1] && cs[i] == cs[i + 2])
            return -(400 + i);
    }
    string symbol[5] = { "!","@","#","$","%" };
    int count(0);
    for (int i = 0; i < 5; i++) {
        if (cs.find(symbol[i]) == -1)
            count++;
    }
    if (count == 5)
        return -5;
    char rage[67];
    int m(0);
    for (int i = 0; i <= 122; i++) {
        if (i == 33 || (i <= 37 && i >= 35) || (i <= 57 && i >= 48) || (i <= 90 && i >= 64) || (i >= 97 && i <= 122)) {
            rage[m] = i;
            m++;
        }
    }
    for (int j = 0; j < cs.size(); j++) {
        count = 0;
        for (int i = 0; i < 67; i++) {
            if (cs[j] == rage[i])
                count++;
        }
        if (count == 0)
            return j;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    string *sarr_pwds=new string[num_pwds];
    string *pwds=new string[num_pwds];
    int exist[100];
    int times[100];
    int count, p(0);
    for (int i = 0; i < num_pwds; i++)
        sarr_pwds[i] = arr_pwds[i];
    for (int i = 0; i < num_pwds; i++)
        exist[i] = 0;
    for (int i = 0; i < num_pwds; i++) {
        count = 1;
        if (exist[i] == 0) {
            for (int j = 0; j < num_pwds; j++) {
                if (i == j)
                    continue;
                else if (sarr_pwds[i] == sarr_pwds[j]) {
                    count++;
                    exist[j] = 1;
                }
            }
            pwds[p] = sarr_pwds[i];
            times[p] = count;
            p++;
        }
        else continue;
    }
    string smax;
    int imax, lct;
    if (p == 1)
        smax = pwds[0];
    for (int i = 0; i < p - 1; i++) {
        if (times[i] >= times[i + 1]) {
            imax = times[i];
            if (imax == times[i + 1] && (pwds[i].size() < pwds[i + 1].size()))
                smax = pwds[i + 1];
            else smax = pwds[i];
            times[i] = times[i + 1];
            times[i + 1] = imax;
            pwds[i] = pwds[i + 1];
            pwds[i + 1] = smax;
        }
        else {
            smax = pwds[i + 1];
            imax = times[i + 1];
        }
    }
    for (int i = 0; i < num_pwds; i++) {
        if (sarr_pwds[i] == smax) {
            delete[] sarr_pwds;
            delete[] pwds;
            return i;
        }
    }
    return -1;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////