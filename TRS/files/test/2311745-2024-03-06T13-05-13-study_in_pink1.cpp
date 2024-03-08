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
        int & E3 ) {
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


int checkexp(int x) {
    if (x > 600) x = 600;
    else if (x < 0) x = 0;
    return x;
}

int checkhp(int x) {
    if (x > 666) x = 666;
    else if (x < 0) x = 0;
    return x;
}

int checkmoney(int x) {
    if (x > 3000) x = 3000;
    else if (x < 0) x = 0;
    return x;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

    if (e1 < 0 || e1 > 99) return -99;

    else {
        int D = 0;
        if (e1 >= 0 && e1 <= 3) {
            if (e1 == 0) exp2 = exp2 + 29;
            else if (e1 == 1) exp2 = exp2 + 45;
            else if (e1 == 2) exp2 = exp2 + 75;
            else if (e1 == 3) exp2 = exp2 + 29 + 45 + 75;

            D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0) exp1 = ceil(exp1 + D / 200.0);
            else if (D % 2 == 1) exp1 = ceil(exp1 - D / 100.0);

            exp1 = checkexp(exp1);
            exp2 = checkexp(exp2);
        }
        else {
            if (e1 >= 4 && e1 <= 19) {
                exp2 = ceil(exp2 + e1 / 4.0 + 19);
            }
            else if (e1 >= 20 && e1 <= 49) {
                exp2 = ceil(exp2 + e1 / 9.0 + 21);
            }
            else if (e1 >= 50 && e1 <= 65) {
                exp2 = ceil(exp2 + e1 / 16.0 + 17);
            }
            else if (e1 >= 66 && e1 <= 79) {
                exp2 = ceil(exp2 + e1 / 4.0 + 19);
                exp2 = checkexp(exp2);

                if (exp2 > 200) {
                    exp2 = ceil(exp2 + e1 / 9.0 + 21);
                    exp2 = checkexp(exp2);
                }
            }
            else if (e1 >= 80 && e1 <= 99) {
                exp2 = ceil(exp2 + e1 / 4.0 + 19 + e1 / 9.0 + 21);
                exp2 = checkexp(exp2);

                if (exp2 > 400) {
                    exp2 = ceil(exp2 + e1 / 16.0 + 17);
                    exp2 = checkexp(exp2);

                    exp2 = ceil(exp2 * 1.15);
                    exp2 = checkexp(exp2);
                }
            }
            exp1 = checkexp(exp1);
            exp1 = exp1 - e1;
            exp2 = checkexp(exp2);
        }
        return exp1 + exp2;
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    if (E2 < 0 || E2 > 99) return -99;

    else {
        double P1 = 0, P2 = 0, P3 = 0;

        // P1
        double S1 = 0;
        S1 = round(sqrt(EXP1)) * round(sqrt(EXP1));

        if (S1 <= EXP1) P1 = 1;
        else P1 = (EXP1 / S1 + 80) / 123;

        // P2
        double S2 = 0;
        if (M1 == 0) {
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);

            HP1 = checkhp(HP1);
            EXP1 = checkexp(EXP1);
          
        }
        if (M1 != 0) {
            if (E2 % 2 == 1) {
                double money = (double)(M1) / 2;
                while (true) {
                    if (HP1 < 200) {
                        HP1 = ceil(HP1 * 1.3);
                        M1 = M1 - 150;

                        HP1 = checkhp(HP1);
                        M1 = checkmoney(M1);
                    }
                    else {
                        HP1 = ceil(HP1 * 1.1);
                        M1 = M1 - 70;

                        HP1 = checkhp(HP1);
                        M1 = checkmoney(M1);
                    }

                    if (M1 < money) break;

                    if (EXP1 < 400) {
                        M1 = M1 - 200;
                        EXP1 = ceil(EXP1 * 1.13);

                        EXP1 = checkexp(EXP1);
                        M1 = checkmoney(M1);
                    }
                    else {
                        M1 = M1 - 120;
                        EXP1 = ceil(EXP1 * 1.13);

                        EXP1 = checkexp(EXP1);
                        M1 = checkmoney(M1);
                    }
                    if (M1 < money) break;

                    if (EXP1 < 300) {
                        M1 = M1 - 100;
                        EXP1 = ceil(EXP1 * 0.9);

                        EXP1 = checkexp(EXP1);
                        M1 = checkmoney(M1);
                    }
                    else {
                        M1 = M1 - 120;
                        EXP1 = ceil(EXP1 * 0.9);

                        EXP1 = checkexp(EXP1);
                        M1 = checkmoney(M1);
                    }
                    if (M1 < money) break;
                }
                HP1 = ceil(HP1 * 0.83);
                EXP1 = ceil(EXP1 * 1.17);

                HP1 = checkhp(HP1);
                EXP1 = checkexp(EXP1);
            }
            if (E2 % 2 == 0) {
                while (true) {
                    if (HP1 < 200) {
                        HP1 = ceil(HP1 * 1.3);
                        M1 = M1 - 150;

                        HP1 = checkhp(HP1);
                        M1 = checkmoney(M1);
                    }
                    else {
                        HP1 = ceil(HP1 * 1.1);
                        M1 = M1 - 70;

                        HP1 = checkhp(HP1);
                        M1 = checkmoney(M1);
                    }
                    if (M1 == 0) break;

                    if (EXP1 < 400) {
                        M1 = M1 - 200;
                        EXP1 = ceil(EXP1 * 1.13);

                        EXP1 = checkexp(EXP1);
                        M1 = checkmoney(M1);
                    }
                    else {
                        M1 = M1 - 120;
                        EXP1 = ceil(EXP1 * 1.13);

                        EXP1 = checkexp(EXP1);
                        M1 = checkmoney(M1);
                    }
                    if (M1 == 0) break;

                    if (EXP1 < 300) {
                        M1 = M1 - 100;
                        EXP1 = ceil(EXP1 * 0.9);

                        EXP1 = checkexp(EXP1);
                        M1 = checkmoney(M1);
                    }
                    else {
                        M1 = M1 - 120;
                        EXP1 = ceil(EXP1 * 0.9);

                        EXP1 = checkexp(EXP1);
                        M1 = checkmoney(M1);
                    }
                    break;
                }
                HP1 = ceil(HP1 * 0.83);
                EXP1 = ceil(EXP1 * 1.17);

                HP1 = checkhp(HP1);
                EXP1 = checkexp(EXP1);
            }
        }
        S2 = round(sqrt(EXP1)) * round(sqrt(EXP1));

        if (S2 <= EXP1) P2 = 1;
        else P2 = (EXP1 / S2 + 80) / 123;

        // P3
        int arrP3[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int i = 0, j = 0;

        if (E2 >= 0 && E2 <= 9) P3 = (double)(arrP3[E2]) / 100;
        else {
            if (E2 >= 10 && E2 <= 99) {
                i = E2 / 10 + E2 % 10;
            }
            if (i >= 10 && i <= 99) {
                j = i / 10 + i % 10;
            }
            P3 = (double)(arrP3[j]) / 100;
        }

        if (P1 + P2 + P3 == 1) EXP1 = ceil(EXP1 * 0.75);
        else {
            if ((P1 + P2 + P3) / 3 < 0.5) {
                HP1 = ceil(HP1 * 0.85);
                EXP1 = ceil(EXP1 * 1.15);

                HP1 = checkhp(HP1);
                EXP1 = checkexp(EXP1);
            }
            if ((P1 + P2 + P3) / 3 >= 0.5) {
                HP1 = ceil(HP1 * 0.9);
                EXP1 = ceil(EXP1 * 1.2);

                HP1 = checkhp(HP1);
                EXP1 = checkexp(EXP1);
            }
        }
        return HP1 + EXP1 + M1;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

    if (E3 < 0 || E3 > 99) return -99;
    else {
        int taximap[10][10];
        int cp = 0, cm = 0;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                taximap[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                if (taximap[i][j] > (E3 * 2)) cp++;
                if (taximap[i][j] < (-E3)) cm++;
            }
        }

        if (cp >= 10) cp = cp / 10 + cp % 10;
        if (cm >= 10) cm = cm / 10 + cm % 10;

        if (cp >= 10) cp = cp / 10 + cp % 10;
        if (cm >= 10) cm = cm / 10 + cm % 10;

        int SW = taximap[cp][cm];

        if (cp < cm) {
            for (int i = 1; i < 10; i++) {
                for (int j = 0; j < i; j++) {
                    if (i + j == cp + cm) {
                        if (taximap[i][j] > SW) SW = taximap[i][j];
                    }
                }
            }
        }

        if (cp > cm) {
            for (int i = 1; i < 10; i++) {
                for (int j = 0; j < i; j++) {
                    if (i == j + abs(cp - cm)) {
                        if (taximap[i][j] > SW) SW = taximap[i][j];
                    }
                    if (i + j == cp + cm) {
                        if (taximap[i][j] > SW) SW = taximap[i][j];
                    }
                }
            }
        }

        if (abs(taximap[cp][cm]) > SW) {
            EXP1 = ceil(EXP1 * 0.88);
            HP1 = ceil(HP1 * 0.9);
            EXP2 = ceil(EXP2 * 0.88);
            HP2 = ceil(HP2 * 0.9);

            EXP1 = checkexp(EXP1);
            EXP2 = checkexp(EXP2);
            HP1 = checkhp(HP1);
            HP2 = checkhp(HP2);
            return taximap[cp][cm];
        }
        else {
            EXP1 = ceil(EXP1 * 1.12);
            HP1 = ceil(HP1 * 1.1);
            EXP2 = ceil(EXP2 * 1.12);
            HP2 = ceil(HP2 * 1.1);

            EXP1 = checkexp(EXP1);
            EXP2 = checkexp(EXP2);
            HP1 = checkhp(HP1);
            HP2 = checkhp(HP2);
            return SW;
        }
    }
}


int charloop(string x) {
    for (int i = 0; i < x.size() - 2; i++) {
        if (x[i] == x[i + 1] && x[i] == x[i + 2]) {
            return i;
        }
    }
    return -1;
}

bool specialchar(string x) {
    for (char i : x) {
        if (i == '@' || i == '#' || i == '$' || i == '%' || i == '!') {
            return true;
        }
    }
    return false;
}

int other(string x) {
    for (char i : x) {
        if (!(isdigit(i) && islower(i) && isupper(i) && i == '!' && i == '@' && i == '#' && i == '$' && i == '%')) {
            return x.find(i);
        }
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string strS(s);
    string strE(email);

    string se = strE.substr(0, strE.find('@'));

    if (strS.size() < 8) return -1;

    else if (strS.size() > 20) return -2;

    else if (strS.find(se) < strS.size()) return -(300 + strS.find(se));

    else if (charloop(strS) != -1) return -(400 + charloop(strS));

    else if (specialchar(strS) == false) return -5;

    else if (other(strS) != -1) return other(strS);
    
    else return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int index = 0; 
    int max_count = 0;

    for (int i = 0; i < num_pwds; i++) {
        int count = 1; 
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }

        if (count > max_count || (count == max_count && strlen(arr_pwds[i]) > strlen(arr_pwds[index]))) {
            max_count = count;
            index = i;
        }
    }
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////