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

// Functions of Task 1
void rebound(int & a, int lower, int upper) {
    if (a > upper) {
        a = upper;
    } else if (a < lower) {
        a = lower;
    }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {    
    if (e1 < 0 || e1 > 99) return -99; // e1 out of range
    rebound(exp1, 0, 600); rebound(exp2, 0, 600);
    if (e1 < 4) {    // Case 1
        int exp_container[4] = {29, 45, 75, 29 + 45 + 75};
        exp2 += exp_container[e1];
        int d = e1 * 3 + exp1 * 7;
        if (d % 2) {
            exp1 = ceil(-0.001 + exp1 - d / 100.0);
        } else {
            exp1 = ceil(-0.001 + exp1 + d / 200.0);
        }
    } else if (e1 < 100) {  // Case 2
        double  a = e1 / 4.0 + 19,
                b = e1 / 9.0 + 21,
                c = e1 / 16.0 + 17;
        if (e1 < 20) {
            exp2 = ceil(-0.001 + exp2 + a);
        } else if (e1 < 50) {
            exp2 = ceil(-0.001 + exp2 + b);
        } else if (e1 < 66) {
            exp2 = ceil(-0.001 + exp2 + c);
        } else if (e1 < 80) {
            exp2 = ceil(-0.001 + exp2 + a); rebound(exp2, 0, 600);
            if (exp2 > 200)
                exp2 = ceil(-0.001 + exp2 + b);
        } else {
            exp2 = ceil(-0.001 + exp2 + a); rebound(exp2, 0, 600);
            exp2 = ceil(-0.001 + exp2 + b); rebound(exp2, 0, 600);
            if (exp2 > 400) {
                exp2 = ceil(-0.001 + exp2 + c); rebound(exp2, 0, 600);
                // add 15% exp
                exp2 = ceil(-0.001 + exp2 + exp2 * 0.15);
            }
        }
        exp1 -= e1;
    }
    rebound(exp1, 0, 600); rebound(exp2, 0, 600);
    return exp1 + exp2;
}

// Functions of Task 2
double nearest_square(double exp1) {
    double x = sqrt(exp1);
    if (x - static_cast<int>(x) >= 0.5) ++ x;
    return static_cast<int>(x) * static_cast<int>(x);
}

double calculate_prob_2(int EXP1) {
    double S = nearest_square(EXP1);
    if (EXP1 < S) return (EXP1 * 1.0 / S + 80.0) / 123.0;
    else return 1.0;
    return 0;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
    if (E2 < 0 || E2 > 99) return -99; // E2 out of range
    rebound(HP1, 0, 666); rebound(EXP1, 0, 600); rebound(M1, 0, 3000);
    // Road 1
    double P1 = calculate_prob_2(EXP1);
    // Road 2
    int ini = M1, paid = 0;
    bool ind = E2 % 2;
    while (M1 > 0) {
        // Grocery
        if (((paid > 0.5 * ini) && ind) || ((M1 <= 0) && !ind)) break;
        if (HP1 < 200) {
            HP1 = ceil(-0.001 + HP1 + HP1 * 0.3);
            M1 -= 150;
            paid += 150;
        } else {
            HP1 = ceil(-0.001 + HP1 + HP1 * 0.1);
            M1 -= 70;
            paid += 70;
        }
        rebound(HP1, 0, 666); rebound(EXP1, 0, 600); rebound(M1, 0, 3000);
        // Taxi
        if (((paid > 0.5 * ini) && ind) || ((M1 <= 0) && !ind)) break;
        if (EXP1 < 400) {
            M1 -= 200;
            paid += 200;
        } else {
            M1 -= 120;
            paid += 120;
        }
        EXP1 = ceil(-0.001 + EXP1 + EXP1 * 0.13);
        rebound(HP1, 0, 666); rebound(EXP1, 0, 600); rebound(M1, 0, 3000);
        // Homeless
        if (((paid > 0.5 * ini) && ind) || ((M1 <= 0) && !ind)) break;
        if (EXP1 < 300) {
            M1 -= 100;
            paid += 100;
        }
        else {
            M1 -= 120;
            paid += 120;
        }
        EXP1 = ceil(-0.001 + EXP1 - EXP1 * 0.1);
        rebound(HP1, 0, 666); rebound(EXP1, 0, 600); rebound(M1, 0, 3000);
        if (!ind) break;
    }
    HP1 = ceil(-0.001 + HP1 - HP1 * 0.17); rebound(HP1, 0, 666);
    EXP1 = ceil(-0.001 + EXP1 + EXP1 * 0.17); rebound(EXP1, 0, 600);
    double P2 = calculate_prob_2(EXP1);
    // Road 3
    int Ps[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P3 = Ps[(E2 / 10 + E2 % 10) % 10] / 100.0;
    // Final
    double P = (P1 + P2 + P3) / 3;
    if (P == 1) {
        EXP1 = ceil(-0.001 + EXP1 - EXP1 * 0.25);
    }
    else if (P < 0.5) {
        HP1 = ceil(-0.001 + HP1 - HP1 * 0.15);
        EXP1 = ceil(-0.001 + EXP1 + EXP1 * 0.15);
    } else {
        HP1 = ceil(-0.001 + HP1 - HP1 * 0.1);
        EXP1 = ceil(-0.001 + EXP1 + EXP1 * 0.2);
    }
    rebound(HP1, 0, 666); rebound(EXP1, 0, 600); rebound(M1, 0, 3000);
    return HP1 + EXP1 + M1;
}

// Functions of Task 3
int add_until(int a) {
    while (a > 9) {
        a = a / 10 + a % 10;
    }
    return a;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) return -99;  // e3 out of range
    rebound(HP1, 0, 666); rebound(EXP1, 0, 600); rebound(HP2, 0, 666); rebound(EXP2, 0, 600);
    //ini matrix
    int matrix[10][10], taxi_i = 0, taxi_j = 0;
    for (int i = 0; i < 10; ++ i) {
        for (int j = 0; j < 10; ++ j) {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (matrix[i][j] > E3 * 2) ++ taxi_i;
            else if (matrix[i][j] < E3 * -1) ++ taxi_j;
        }
    }
    taxi_i = add_until(taxi_i), taxi_j = add_until(taxi_j);
    int sherlock = matrix[taxi_i][taxi_j];
    // right
    for (int n = -9; n < 10; ++ n) {
        if ((taxi_i - n < 0) || (taxi_i - n > 9) || (taxi_j - n < 0) || (taxi_j - n > 9)) {
            continue;
        }
        if (sherlock < matrix[taxi_i - n][taxi_j - n]) {
            sherlock = matrix[taxi_i - n][taxi_j - n];
        }
    }
    // left
    for (int n = -9; n < 10; ++ n) {
        if ((taxi_i - n < 0) || (taxi_i - n > 9) || (taxi_j + n < 0) || (taxi_j + n > 9)) {
            continue;
        }
        if (sherlock < matrix[taxi_i - n][taxi_j + n]) {
            sherlock = matrix[taxi_i - n][taxi_j + n];
        }
    }

    if (sherlock < abs(matrix[taxi_i][taxi_j])) {
        EXP1 = ceil(-0.001 + EXP1 - EXP1 * 0.12); rebound(EXP1, 0, 600);
        HP1 = ceil(-0.001 + HP1 - HP1 * 0.1); rebound(HP1, 0, 666);
        EXP2 = ceil(-0.001 + EXP2 - EXP2 * 0.12); rebound(EXP2, 0, 600);
        HP2 = ceil(-0.001 + HP2 - HP2 * 0.1); rebound(HP2, 0, 666);
        return matrix[taxi_i][taxi_j];
    } else {
        EXP1 = ceil(-0.001 + EXP1 + EXP1 * 0.12); rebound(EXP1, 0, 600);
        HP1 = ceil(-0.001 + HP1 + HP1 * 0.1); rebound(HP1, 0, 666);
        EXP2 = ceil(-0.001 + EXP2 + EXP2 * 0.12); rebound(EXP2, 0, 600);
        HP2 = ceil(-0.001 + HP2 + HP2 * 0.1); rebound(HP2, 0, 666);
        return sherlock;
    }
    return -1;
}

// Functions of Task 4
string get_se(const char * email) {
    string se = "", reparsed_e = email;
    for (int i = 0; i < reparsed_e.size(); ++ i) {
        if (email[i] == '@')
            break;
        se += email[i];
    }
    return se;
}

bool check_valid_char(char a) {
    if ((a >= '0' && a <= '9') || (a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z') || a == '@' || a == '#' || a =='%' || a == '$' || a == '!') 
        return true;
    return false;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string se = get_se(email), password = s;
    if (password.size() < 8) // min length
        return -1;
    if (password.size() > 20) // max length
        return -2;
    // se in password
    if (password.find(se) != string::npos) {
        return -1 * (300 + password.find(se));
    }
    // consecutive chars
    for (int i = 0; i < password.size() - 2; ++ i) {
        if ((password[i] == password[i + 1]) && (password[i] == password[i + 2]))
            return -1 * (400 + i);
    }
    // at least 1 special char
    bool special = false;
    for (int i = 0; i < password.size(); ++ i) {
        char a = password[i];
        if (a == '@' || a == '#' || a =='%' || a == '$' || a == '!') {
            special = true;
            break;
        }
    }
    if (special == false) {
        return -5;
    }
    // valid char a-z A-Z 0-9
    for (int i = 0; i < password.size(); ++ i) {
        if (!check_valid_char(password[i]))
            return i;
    }
    // good password
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // const char * to string array
    string pwds[num_pwds];
    for (int i = 0; i < num_pwds; ++ i) {
        pwds[i] = arr_pwds[i];
    }
    // assume the first pwd to be our answer
    int index = 0, times = 0;
    for (int i = 0; i < num_pwds; ++ i) {
        int total = 0;
        // count its reiteration after it in the array        
        for (int j = i + 1; j < num_pwds; ++ j) {
            if (pwds[i] == pwds[j]) {
                ++ total;
            }
        }
        if (total > times) { // if more, definite replacement
            times = total;
            index = i;
        } else if (total == times) { // if equal, only replace if its length is longer
            if (pwds[i].size() > pwds[index].size()) {
                index = i;
            }
        }
    }
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////