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

int healthpoint(int& HP) {
    if (HP > 666) {
        HP = 666;
    }
    else if (HP < 0) {
        HP = 0;
    }
    return HP;
}

int experiencepoint(int& EXP) {
    if (EXP > 600) {
        EXP = 600;
    }
    else if (EXP < 0) {
        EXP = 0;
    }
    return EXP;
}

int money(int& M) {
    if (M > 3000) {
        M = 3000;
    }
    else if (M < 0) {
        M = 0;
    }
    return M;
}

int eventcode(int E) {
    if ((E < 0) || (E > 99))
        return -99;
    else
        return E;
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    e1 = eventcode(e1);
    if (e1 == -99)
        return -99;
    experiencepoint(exp1);
    experiencepoint(exp2);
    // Case 1
    if ((e1 >= 0) && (e1 <= 3)) {
        if (e1 == 0) {
            exp2 = exp2 + 29;
            experiencepoint(exp2);
        }
        else if (e1 == 1) {
            exp2 = exp2 + 45;
            experiencepoint(exp2);
        }
        else if (e1 == 2) {
            exp2 = exp2 + 75;
            experiencepoint(exp2);
        }
        else if (e1 == 3) {
            exp2 = exp2 + 29 + 45 + 75;
            experiencepoint(exp2);
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = ceil(double(exp1) + double(D) / 200.00);
            experiencepoint(exp1);
        }
        else {
            exp1 = ceil(double(exp1) - double(D) / 100.00);
            experiencepoint(exp1);
        }
    }
    // Case 2
    else if ((e1 >= 4) && (e1 <= 99)) {
        if (e1 <= 19) {
            exp2 = exp2 + ceil((double(e1 / 4.00) + 19));
            experiencepoint(exp2);
        }
        else if ((20 <= e1) && (e1 <= 49)) {
            exp2 = exp2 + ceil((double(e1 / 9.00) + 21));
            experiencepoint(exp2);
        }
        else if ((e1 >= 50) && (e1 <= 65)) {
            exp2 = exp2 + ceil((double(e1 / 16.00) + 17));
            experiencepoint(exp2);
        }
        else if ((66 <= e1) && (e1 <= 79)) {
            exp2 = exp2 + ceil((double(e1 / 4.00) + 19));
            experiencepoint(exp2);
            if (exp2 > 200) {
                exp2 = exp2 + ceil((double(e1 / 9.00) + 21));
                experiencepoint(exp2);
            }
        }
        else {
            exp2 = exp2 + ceil(double(e1 / 4.00) + 19);
            experiencepoint(exp2);
            exp2 = exp2 + ceil(double(e1 / 9.00) + 21);
            experiencepoint(exp2);
            if (exp2 > 400) {
                exp2 = exp2 + ceil((double(e1 / 16.00) + 17));
                experiencepoint(exp2);
                exp2 = ceil(double(exp2) * 1.15);
                experiencepoint(exp2);
            }
        }
        exp1 -= e1;
        experiencepoint(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int perfectsquare(int EXP1) {
    int x = sqrt(EXP1);
    if (x * x == EXP1) {
        return EXP1;
    }
    else if ((EXP1 - x * x) > ((x + 1) * (x + 1) - EXP1)) {
        return (x + 1) * (x + 1);
    }
    else
        return x * x;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    E2 = eventcode(E2);
    if (E2 == -99) {
        return -99;
    }
    experiencepoint(EXP1);
    money(M1);
    healthpoint(HP1);
    // Road 1
    int S1 = perfectsquare(EXP1);
    double P1;
    if (EXP1 >= S1) {
        P1 = 1;
    }
    else {
        P1 = (double(EXP1) / S1 + 80) / 123;
    }
    // Road 2
    int initial_M1 = M1;
    int used_M1 = 0;
    if (E2 % 2 != 0) {
        while (true) {
            if (M1 <= 0) {
                break;
            }
            if (HP1 < 200) {
                HP1 = ceil(HP1 + double(HP1) * 0.3);
                healthpoint(HP1);
                M1 = M1 - 150;
                money(M1);
                used_M1 += 150;
            }
            else {
                HP1 = ceil(HP1 + double(HP1) * 0.1);
                healthpoint(HP1);
                M1 = M1 - 70;
                money(M1);
                used_M1 += 70;
            }
            if (used_M1 > (initial_M1 * 0.5)) {
                break;
            }
            if (EXP1 < 400) {
                M1 = M1 - 200;
                money(M1);
                used_M1 = used_M1 + 200;
            }
            else {
                M1 = M1 - 120;
                money(M1);
                used_M1 = used_M1 + 120;
            }
            EXP1 = ceil(EXP1 + double(EXP1) * 0.13);
            experiencepoint(EXP1);
            if (used_M1 > (initial_M1 * 0.5)) {
                break;
            }
            if (EXP1 < 300) {
                M1 = M1 - 100;
                money(M1);
                used_M1 = used_M1 + 100;
            }
            else {
                M1 = M1 - 120;
                money(M1);
                used_M1 = used_M1 + 120;
            }
            EXP1 = ceil(EXP1 - double(EXP1) * 0.1);
            experiencepoint(EXP1);
            if (used_M1 > (initial_M1 * 0.5)) {
                break;
            }
        }
    }
    else if (E2 % 2 == 0) {
        while (true) {
            if (M1 <= 0) {
                break;
            }
            if (HP1 < 200) {
                HP1 = ceil(HP1 + double(HP1) * 0.3);
                healthpoint(HP1);
                M1 = M1 - 150;
                money(M1);
            }
            else {
                HP1 = ceil(HP1 + double(HP1) * 0.1);
                healthpoint(HP1);
                M1 = M1 - 70;
                money(M1);
            }
            if (M1 <= 0) {
                break;
            }

            if (EXP1 < 400) {
                M1 = M1 - 200;
                money(M1);
            }
            else {
                M1 = M1 - 120;
                money(M1);
            }
            EXP1 = ceil(EXP1 + double(EXP1) * 0.13);
            experiencepoint(EXP1);
            if (M1 <= 0) {
                break;
            }
            if (EXP1 < 300) {
                M1 = M1 - 100;
                money(M1);
            }
            else {
                M1 = M1 - 120;
                money(M1);
            }
            EXP1 = ceil(EXP1 - double(EXP1) * 0.1);
            experiencepoint(EXP1);
            break;
        }
    }
    HP1 = ceil(HP1 - double(HP1) * 0.17);
    healthpoint(HP1);
    EXP1 = ceil(EXP1 + double(EXP1) * 0.17);
    experiencepoint(EXP1);

    double P2;
    int S2 = perfectsquare(EXP1);
    if (EXP1 >= S2) {
        P2 = 1;
    }
    else {
        P2 = (double(EXP1) / S2 + 80) / 123;
    }
    // Road 3
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i;
    if (E2 < 10) {
        i = E2;
    }
    else {
        int a = E2 / 10;
        int b = E2 % 10;
        int c = a + b;
        i = c % 10;
    }
    double P3 = P[i] * 0.01;

    if ((P1 == 1) && (P2 == 1) && (P3 == 1)) {
        EXP1 = ceil(double(EXP1) * 0.75);
        experiencepoint(EXP1);
    }
    else {
        double aveP = (P1 + P2 + P3) / 3.0;
        if (aveP < 0.5) {
            HP1 = ceil(HP1 - double(HP1) * 0.15);
            healthpoint(HP1);
            EXP1 = ceil(EXP1 + double(EXP1) * 0.15);
            experiencepoint(EXP1);
        }
        else {
            HP1 = ceil(HP1 - double(HP1) * 0.1);
            healthpoint(HP1);
            EXP1 = ceil(EXP1 + double(EXP1) * 0.2);
            experiencepoint(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    E3 = eventcode(E3);
    if (E3 == -99) {
        return -99;
    }
    healthpoint(HP1);
    experiencepoint(EXP1);
    healthpoint(HP2);
    experiencepoint(EXP2);
    int Taxi[10][10];
    int SherWat[10][10];
    int i, j;
    for (i = 0; i <= 9; i++) {
        for (j = 0; j <= 9; j++) {
            Taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    for (i = 0; i <= 9; i++) {
        for (j = 0; j <= 9; j++) {
            int max_value = 0;
            for (int coor_i = i, coor_j = j; (coor_i >= 0) && (coor_j >= 0); coor_i--, coor_j--) {
                max_value = max(max_value, Taxi[coor_i][coor_j]);
            }
            for (int coor_i = i, coor_j = j; (coor_i <= 9) && (coor_j <= 9); coor_i++, coor_j++) {
                max_value = max(max_value, Taxi[coor_i][coor_j]);
            }
            for (int coor_i = i, coor_j = j; (coor_i >= 0) && (coor_j <= 9); coor_i--, coor_j++) {
                max_value = max(max_value, Taxi[coor_i][coor_j]);
            }
            for (int coor_i = i, coor_j = j; (coor_i <= 9 && coor_j >= 0); coor_i++, coor_j--) {
                max_value = max(max_value, Taxi[coor_i][coor_j]);
            }
            SherWat[i][j] = max_value;
        }
    }
    int meet_i = 0;
    int meet_j = 0;
    for (i = 0; i <= 9; i++) {
        for (j = 0; j <= 9; j++) {
            if (Taxi[i][j] > (E3 * 2)) {
                meet_i++;
            }
            if (Taxi[i][j] < (-E3)) {
                meet_j++;
            }
        }
    }
    while (meet_i >= 10) {
        int x1 = meet_i % 10;
        int x2 = meet_i / 10;
        meet_i = x1 + x2;
    }
    while (meet_j >= 10) {
        int y1 = meet_j % 10;
        int y2 = meet_j / 10;
        meet_j = y1 + y2;
    }
    int Taxi_value = Taxi[meet_i][meet_j];
    int SherWat_value = SherWat[meet_i][meet_j];
    if ((abs(Taxi_value) > SherWat_value)) {
        EXP1 = ceil(EXP1 - double(EXP1) * 0.12);
        experiencepoint(EXP1);
        EXP2 = ceil(EXP2 - double(EXP2) * 0.12);
        experiencepoint(EXP2);
        HP1 = ceil(HP1 - double(HP1) * 0.1);
        healthpoint(HP1);
        HP2 = ceil(HP2 - double(HP2) * 0.1);
        healthpoint(HP2);
    }
    else {
        EXP1 = ceil(EXP1 + double(EXP1) * 0.12);
        experiencepoint(EXP1);
        EXP2 = ceil(EXP2 + double(EXP2) * 0.12);
        experiencepoint(EXP2);
        HP1 = ceil(HP1 + double(HP1) * 0.1);
        healthpoint(HP1);
        HP2 = ceil(HP2 + double(HP2) * 0.1);
        healthpoint(HP2);
    }
    return (abs(Taxi_value) > SherWat_value) ? Taxi_value : SherWat_value;
    return -1;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    string password = s;
    string Email = email;
    if (strlen(s) < 8) {
        return -1;
    }
    if (strlen(s) > 20) {
        return -2;
    }
    int findsubstr = Email.find('@');
    string se = Email.substr(0, findsubstr);
    int sei = password.find(se);
    if (sei != string::npos) {
        return -(300 + sei);
    }
    for (int sci = 0; sci < (strlen(s) - 2); sci++) {
        if ((password[sci] == password[sci + 1]) && (password[sci + 1] == password[sci + 2])) {
            return -(400 + sci);
        }
    }
    bool specialchar=false;
    for (int i = 0; i < strlen(s); i++) {
        if ((s[i] == '@') || (s[i] == '#') || (s[i] == '%') || (s[i] == '$') || (s[i] == '!')) {
            specialchar = true;
        }
    }
    if (specialchar == false) {
        return -5;
    }
    for (int i = 0; i < strlen(s); i++) {
        if ((s[i] != '@' && s[i] != '%' && s[i] != '#' && s[i] != '!' && s[i] != '$' && (s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z') && (s[i] < '0' || s[i] > '9')))
            return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int most_repeat = 0;
    int longest = 0;
    int position = 0;
    for (int i = 0; i < num_pwds; i++) {
        int repeat = 1;
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                repeat = repeat + 1;
            }
        }
        if (repeat > most_repeat) {
            most_repeat = repeat;
            longest = strlen(arr_pwds[i]);
            position = i;
        }
        else if ((repeat == most_repeat) && (strlen(arr_pwds[i]) > longest)) {
            longest = strlen(arr_pwds[i]);
            position = i;
        }
    }
    return position;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////