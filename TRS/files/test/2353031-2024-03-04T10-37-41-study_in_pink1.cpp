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
 
//Reset HP 
int resetHP(int& HP) {
    if (HP < 0)
        HP = 0;
    else if (HP > 666)
        HP = 666;
    else
        ;
    return HP;
}
//Reset EXP
int resetEXP(int& EXP) {
    if (EXP < 0)
        EXP = 0;
    else if (EXP > 600)
        EXP = 600;
    else
        ;
    return EXP;
}
//Reset Money
int resetMoney(int& M) {
    if (M < 0)
        M = 0;
    else if (M > 3000)
        M = 3000;
    else
        ;
    return  M;
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    if (e1 < 0 || e1 > 99)
        return -99;
    resetEXP(exp1);
    resetEXP(exp2);
    int D;
    switch (e1) {
    case 0 ... 3:
        if (e1 == 0) {
            exp2 += 29;
        }
        else if (e1 == 1) {
            exp2 += 45;
        }
        else if (e1 == 2) {
            exp2 += 75;
        }
        else {
            exp2 = exp2 + 29 + 45 + 75;
        }
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            exp1 = ceil(exp1 + D / 200.00);
        else
            exp1 = ceil(exp1 - D / 100.00);
        resetEXP(exp1);
        resetEXP(exp2);
        break;

    case 4 ... 99:
        if (e1 >= 4 && e1 <= 19)
            exp2 = ceil(exp2 + (e1 / 4.00 + 19));
        else if (e1 >= 20 && e1 <= 49)
            exp2 = ceil(exp2 + (e1 / 9.00 + 21));
        else if (e1 >= 50 && e1 <= 65)
            exp2 = ceil(exp2 + (e1 / 16.00 + 17));
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = ceil(exp2 + (e1 / 4.00 + 19));
            resetEXP(exp1);
            resetEXP(exp2);
            if (exp2 > 200)
            exp2 = ceil(exp2 + (e1 / 9.00 + 21));
            resetEXP(exp1);
            resetEXP(exp2);
        }
        else {
            exp2 = ceil(exp2 + (e1 / 4.00 + 19));
            exp2 = ceil(exp2 + (e1 / 9.00 + 21));
            resetEXP(exp1);
            resetEXP(exp2);
            if (exp2 > 400) {
                exp2 = ceil(exp2 + (e1 / 16.00 + 17));
                exp2 = ceil(exp2 * 115.00/100);
                resetEXP(exp1);
                resetEXP(exp2);
            }
        }
        exp1 -= e1;
        break;
    }
    resetEXP(exp1);
    resetEXP(exp2);
    return exp1 + exp2;
}
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 < 0 || E2 > 99)
        return -99;
    resetHP(HP1);
    resetEXP(EXP1);
    resetMoney(M1);

    //Road 1
    //find S
    int S;
    S = sqrt(EXP1);
    if (EXP1 - S * S < (S + 1) * (S + 1) - EXP1)
        S = S * S;
    else
        S = (S + 1) * (S + 1);
    //Probability 
    double P1;
    if (EXP1 >= S)
        P1 = 100;
    else
        P1 = (double(EXP1) / double(S) + 80) / 123.00 * 100;
    //Road 2
    int m = 0, m_1 = M1;
    if (E2 % 2 != 0) {
        while (m <= 0.5 * M1 && M1 > 0) {
            if (HP1 < 200) {
                HP1 = ceil(HP1 * 130.00/100);
                m += 150;
                m_1 -= 150;
            }
            else {
                HP1 = ceil(HP1 * 110.00/100);
                m += 70;
                m_1 -= 70;
            }
            resetHP(HP1);
            resetMoney(m_1);
            if (m > 0.5 * M1)
                break;

            if (EXP1 < 400) {
                m += 200;
                m_1 -= 200;
            }
            else {
                m += 120;
                m_1 -= 120;
            }
            EXP1 = ceil(EXP1 * 113.00/100);
            resetEXP(EXP1);
            resetMoney(m_1);
            if (m > 0.5 * M1)
                break;

            if (EXP1 < 300) {
                m += 100;
                m_1 -= 100;
            }
            else {
                m += 120;
                m_1 -= 120;
            }
            EXP1 = ceil(EXP1 * 90.00/100);
            resetEXP(EXP1);
            resetMoney(m_1);
            if (m > 0.5 * M1)
                break;
        }
    }
    else {
        if (m_1 > 0) {
            if (HP1 < 200) {
                HP1 = ceil(HP1 * 130.00/100);
                m += 150;
                m_1 -= 150;
            }
            else {
                HP1 = ceil(HP1 * 110.00/100);
                m += 70;
                m_1 -= 70;
            }
            resetHP(HP1);
            resetMoney(m_1);
        }

        if (m_1 > 0) {
            if (EXP1 < 400) {
                m += 200;
                m_1 -= 200;
            }
            else {
                m += 120;
                m_1 -= 120;
            }
            EXP1 = ceil(EXP1 * 113.00/100);
            resetEXP(EXP1);
            resetMoney(m_1);
        }

        if(m_1 > 0){
            if (EXP1 < 300) {
                m += 100;
                m_1 -= 100;
            }
            else {
                m += 120;
                m_1 -= 120;
            }
            EXP1 = ceil(EXP1 * 90.00/100);
            resetEXP(EXP1);
            resetMoney(m_1);
            
        }
    }
    HP1 = ceil(HP1 * 83.00 / 100);
    EXP1 = ceil(EXP1 * 117.00 / 100);
    resetHP(HP1);
    resetEXP(EXP1);
    M1 = m_1;
    //find S
    S = sqrt(EXP1);
    if (EXP1 - S * S < (S + 1) * (S + 1) - EXP1)
        S = S * S;
    else
        S = (S + 1) * (S + 1);
    //Probability 
    double P2;
    if (EXP1 >= S)
        P2 = 100;
    else
        P2 = (double(EXP1) / double(S) + 80) / 123.00 * 100;
    //Road 3
    double P3, P_ave;
    int P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2 < 10)
        P3 = P[E2];
    else
        P3 = P[((E2 / 10 + E2 - E2 / 10 * 10) - (E2 / 10 + E2 - E2 / 10 * 10) / 10 * 10)];
    P_ave =(P1 + P2 + P3) / 3.00;
    if (P1 == 100 && P2 == 100 && P3 == 100)
        EXP1 = ceil(EXP1 * 0.75);
    else if (P_ave < 50) {
        HP1 = ceil(HP1 * 85.00/100);
        EXP1 = ceil(EXP1 * 115.00/100);
    }
    else {
        HP1 = ceil(HP1 * 90.00/100);
        EXP1 = ceil(EXP1 * 120.00/100);
    }
    resetHP(HP1);
    resetEXP(EXP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99)
        return -99;
    resetHP(HP1);
    resetHP(HP2);
    resetEXP(EXP1);
    resetEXP(EXP2);

    int score[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            score[i][j] = (E3 * j + i * 2) * (i - j);
        }
    }

    //Meeting point
    int count_i = 0, count_j = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (score[i][j] > E3 * 2)
                count_i += 1;
            if (score[i][j] < -E3)
                count_j += 1;
        }
    }
    while (count_i > 9)
        count_i = count_i / 10 + (count_i - count_i / 10 * 10);
    while (count_j > 9)
        count_j = count_j / 10 + (count_j - count_j / 10 * 10);

    //Score of Sherlock and Waston
    int score_1 = score[count_i][count_j];
    int i = count_i, j = count_j;
    while (i >= 0 && j >= 0) {
        if (score_1 <= score[i][j])
            score_1 = score[i][j];
        i--;
        j--;
    }
    i = count_i;
    j = count_j;
    while (i >= 0 && j < 10) {
        if (score_1 <= score[i][j])
            score_1 = score[i][j];
        i--;
        j++;

    }
    i = count_i;
    j = count_j;
    while (i < 10 && j >= 0) {
        if (score_1 <= score[i][j])
            score_1 = score[i][j];
        i++;
        j--;
    }
    i = count_i;
    j = count_j;
    while (i < 10 && j < 10) {
        if (score_1 <= score[i][j])
            score_1 = score[i][j];
        i++;
        j++;
    }
    if (abs(score[count_i][count_j]) > score_1) {
        EXP1 = ceil(EXP1 * 88.00/100);
        EXP2 = ceil(EXP2 * 88.00/100);
        HP1 = ceil(HP1 * 90.00/100);
        HP2 = ceil(HP2 * 90.00/100);
        resetHP(HP1);
        resetHP(HP2);
        resetEXP(EXP1);
        resetEXP(EXP2);
        return score[count_i][count_j];
    }
    else {
        EXP1 = ceil(EXP1 * 112.00/100);
        EXP2 = ceil(EXP2 * 112.00 / 100);
        HP1 = ceil(HP1 * 110.00 / 100);
        HP2 = ceil(HP2 * 110.00 / 100);
        resetHP(HP1);
        resetHP(HP2);
        resetEXP(EXP1);
        resetEXP(EXP2);
        return score_1;
    }
    return -1;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    string s1 = s;
    string e1 = email;
    if (s1.size() < 8)
        return -1;

    if (s1.size() > 20)
        return -2;

    string se = e1.substr(0, e1.find("@"));
    size_t sei = s1.find(se);
    if (sei != string::npos)
        return -(300 + int(sei));

    int sci;
    for (int i = 0; i < s1.size() - 2; i++) {
        if (s1[i] == s1[i + 1] && s1[i] == s1[i + 2]) {
            sci = i;
            return -(400 + int(sci));
        }
    }

    string special = "@#%$!";
    size_t spi = s1.find_first_of(special);
    if (spi == string::npos)
        return -5;

    string valid = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#%$!";
    size_t invalid = s1.find_first_not_of(valid);
    if (invalid != string::npos)
        return int(invalid);
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    const char* pwds = arr_pwds[0];
    int occur[num_pwds];//initialize the array with 0
    int max_count = 0;
    int max_len = strlen(arr_pwds[0]);

    for (int i = 0; i < num_pwds; i++) {
        occur[i] = 0;
    }

    for (int i = 0; i < num_pwds; i++) {
        int  count = 0;
        if (occur[i] == 1)
            continue;
        for (int j = i; j < num_pwds; j++) {
            if (strcmp(arr_pwds[j], arr_pwds[i]) == 0) {
                count++;
                occur[j] = 1;
            }
        }
        if (max_count < count || (max_count == count && max_len < strlen(arr_pwds[i]))) {
            max_count = count;
            max_len = strlen(arr_pwds[i]);
            pwds = arr_pwds[i];
        }
    }

    for (int i = 0; i < num_pwds; i++) {
        if (strcmp(pwds, arr_pwds[i]) == 0)
            return i;
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////