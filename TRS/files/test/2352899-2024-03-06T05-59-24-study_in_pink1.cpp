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

/// PHAM HONG PHAT, MSSV: 2352899

int reset(int data, char type) { // Check and reset if HP, EXP & M values are outside the range
    switch (type) {
    case 'H':
        if (data > 666) data = 666;
        else if (data < 0) data = 0;
        break;
    case 'E':
        if (data > 600) data = 600;
        else if (data < 0) data = 0;
        break;
    case 'M':
        if (data > 3000) data = 3000;
        else if (data < 0) data = 0;
        break;
    }
    return data;
}
int multiply(int a, char b, double c) { // Do the calculation and round up 
    if (b == '*') return ceil((double)((float)(a * c)));
    else return ceil((double)((float)(a / c)));
}

// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {
    if (E1 < 0 || E1 > 99) return -99; // Check if E1 is outside the range
    else if (E1 < 4) {
        switch (E1) { // Case 1: [0;3]
        case 0:
            EXP2 += 29;
            break;
        case 1:
            EXP2 += 45;
            break;
        case 2:
            EXP2 += 75;
            break;
        case 3:
            EXP2 += (29 + 45 + 75);
            break;
        }
        int D = E1 * 3 + EXP1 * 7; // Calculate Sherlock's decision and the EXPs
        EXP1 = (D % 2 == 0) ? (EXP1 + multiply(D, '/', 200)) : ceil((double)(EXP1 - D / 100));
        EXP1 = reset(EXP1, 'E');
        EXP2 = reset(EXP2, 'E');
        return EXP1 + EXP2;
    }
    else { // Case 2: [4;99] Calculate EXP1 & EXP2 according to the value of E1
        if (E1 < 20) EXP2 += (multiply(E1, '/', 4) + 19);
        else if (E1 < 50) EXP2 += (multiply(E1, '/', 9) + 21);
        else if (E1 < 66) EXP2 += (multiply(E1, '/', 16) + 17);
        else {
            EXP2 += (multiply(E1, '/', 4) + 19);
            EXP2 = reset(EXP2, 'E');
            if (E1 < 80) EXP2 += (EXP2 > 200) ? (multiply(E1, '/', 9) + 21) : 0;
            else {
                EXP2 += (multiply(E1, '/', 9) + 21);
                if (EXP2 > 400) {
                    EXP2 += (multiply(E1, '/', 16) + 17);
                    EXP2 = reset(EXP2, 'E');
                    EXP2 = multiply(EXP2, '*', 1.15);
                }
            }
        }
        EXP2 = reset(EXP2, 'E');
        EXP1 = reset(EXP1 - E1, 'E');
        return EXP1 + EXP2;
    }
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 < 0 || E2 > 99) return -99; // Check if E2 is outside the range
    int M_intial = M1;
    double P1, P2, P3, P_average, S;
    S = round(sqrt(double(EXP1))); // Find the nearest perfecr square to EXP1
    S *= S;
    P1 = (EXP1 >= S) ? 1 : (EXP1 / S + 80) / 123;
    while (true) { //Calculate Sherlock's various event, break if: 
        // (1) E2 is odd and M1 is less than or equal to half of M_intial;
        // (2) M1 is reduced to 0;
        // (3) E2 is even and Sherlock has done one round of action;

        if (HP1 < 200) {
            HP1 = multiply(HP1, '*', 1.3);
            M1 -= 150;
        }
        else {
            HP1 = multiply(HP1, '*', 1.1);
            M1 -= 70;
        }

        HP1 = reset(HP1, 'H');
        M1 = reset(M1, 'M');

        if (((M_intial > 2 * M1) && (E2 % 2 == 1)) || (M1 == 0)) { 
            HP1 = multiply(HP1, '*', 0.83);
            EXP1 = multiply(EXP1, '*', 1.17);
            break;
        }

        M1 -= (EXP1 < 400) ? 200 : 120;
        EXP1 = multiply(EXP1, '*', 1.13);
        EXP1 = reset(EXP1, 'E');
        M1 = reset(M1, 'M');

        if (((M_intial > 2 * M1) && (E2 % 2 == 1)) || (M1 == 0)) {
            HP1 = multiply(HP1, '*', 0.83);
            EXP1 = multiply(EXP1, '*', 1.17);
            break;
        }

        M1 -= (EXP1 < 300) ? 100 : 120;
        EXP1 = multiply(EXP1, '*', 0.9);
        EXP1 = reset(EXP1, 'E');
        M1 = reset(M1, 'M');

        if (((M_intial > 2 * M1) && (E2 % 2 == 1)) || (E2 % 2 == 0) || (M1 == 0)) {
            HP1 = multiply(HP1, '*', 0.83);
            EXP1 = multiply(EXP1, '*', 1.17);
            break;
        }
    }
    HP1 = reset(HP1, 'H');
    EXP1 = reset(EXP1, 'E');

    S = round(sqrt(double(EXP1))); // Find the nearest perfecr square to EXP1
    S *= S;
    P2 = (EXP1 >= S) ? 1 : (EXP1 / S + 80) / 123;
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 }; // Calculate P3 and P_average
    if (E2 < 10) P3 = P[E2] / 100.0;
    else P3 = P[(E2 % 10 + E2 / 10) % 10] / 100.0;
    P_average = (P1 + P2 + P3) / 3;

    if (P_average == 1) EXP1 = multiply(EXP1, '*', 0.75); // Calculate the return values of HP and EXP
    else if (P_average < 0.5) {
        HP1 = multiply(HP1, '*', 0.85);
        EXP1 = multiply(EXP1, '*', 1.15);
    }
    else {
        HP1 = multiply(HP1, '*', 0.9);
        EXP1 = multiply(EXP1, '*', 1.2);
    }
    HP1 = reset(HP1, 'H');
    EXP1 = reset(EXP1, 'E');
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (E3 < 0 || E3 > 99) return -99; // Check if E2 is outside the range
    int num_i = 0, num_j = 0, max = 0;
    int score[10][10]; // Create the matrix, assign values to its elements, and count num_i, num_j
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            score[i][j] = (E3 * j + i * 2) * (i - j);
            if (score[i][j] > 2 * E3) num_i++;
            else if (score[i][j] < -E3) num_j++;
        }
    }

    while (num_i > 9) { // Repeatedly sum the digits of num_i and num_j until they become one-digit numbers  
        num_i = num_i % 10 + num_i / 10;
    }
    while (num_j > 9) {
        num_j = num_j % 10 + num_j / 10;
    }

    int taxi = score[num_i][num_j]; // Calculate Sherlock and Watson's score: maximum value on the left and right diagonals
    for (int i = num_i, j = num_j; i < 10 && j < 10; i++, j++) {
        if (score[i][j] > max) max = score[i][j];
    }
    for (int i = num_i - 1, j = num_j - 1; i >= 0 && j >= 0; i--, j--) {
        if (score[i][j] > max) max = score[i][j];
    }
    for (int i = num_i + 1, j = num_j - 1; i < 10 && j >= 0; i++, j--) {
        if (score[i][j] > max) max = score[i][j];
    }
    for (int i = num_i - 1, j = num_j + 1; i >= 0 && j < 10; i--, j++) {
        if (score[i][j] > max) max = score[i][j];
    }

    if (max >= abs(taxi)) { // Calculate the return values
        EXP1 = multiply(EXP1, '*', 1.12);
        EXP2 = multiply(EXP2, '*', 1.12);
        HP1 = multiply(HP1, '*', 1.1);
        HP2 = multiply(HP2, '*', 1.1);
        EXP1 = reset(EXP1, 'E');
        EXP2 = reset(EXP2, 'E');
        HP1 = reset(HP1, 'H');
        HP2 = reset(HP2, 'H');
        return max;
    }
    else {
        EXP1 = multiply(EXP1, '*', 0.88);
        EXP2 = multiply(EXP2, '*', 0.88);
        HP1 = multiply(HP1, '*', 0.9);
        HP2 = multiply(HP2, '*', 0.9);
        return taxi;
    }
}

// Task 4
int checkPassword(const char* s, const char* email) {
    bool special = false, invalid = false;
    string s_copy = s, e_copy = email; // Copy the const char pointer s and email to a string, find the string se
    int at_sign = e_copy.find("@");
    string se = e_copy.substr(0, at_sign);
    int s_length = s_copy.length();

    if (s_length < 8) return -1; // Check if the password is invalid and return the corresponding value
    else if (s_length > 20) return -2;
    if (s_copy.find(se) != string::npos) return  -(300 + (int)(s_copy.find(se)));
    for (int n = 0; n < s_length; n++) {
        if ((s_copy[n] == s_copy[n + 1]) && (s_copy[n + 1] == s_copy[n + 2])) return -(400 + n);
    }
    if (s_copy.find("!") == string::npos && s_copy.find("@") == string::npos && s_copy.find("#") == string::npos && s_copy.find("$") == string::npos && s_copy.find("%") == string::npos)
        return -5;
    for (int n = 0; n < s_length; n++) {
        if (isalnum(s_copy[n]) == false && (s_copy[n] != '@' && s_copy[n] != '#' && s_copy[n] != '$' && s_copy[n] != '%' && s_copy[n] != '!'))
            return n;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    string pwds_copy[100]; // Copy arr_pwds to an array of string, initiate the necessary variables 
    int appear, first_appear = -1, max_appear = 0, max_length = 0; 
    for (int n = 0; n < num_pwds; n++) { 
        pwds_copy[n] = arr_pwds[n];
    }

    for (int i = 0; i < num_pwds; i++) { // Run two loops to find the password with: 
        // (1) most appearance; 
        // (2) equally most appearance and max length;
        // (3) equally most appearance, equal length and smallest first_appear;
        appear = 1;
        for (int j = i + 1; j < num_pwds; j++) {
            if (pwds_copy[i] == pwds_copy[j]) {
                appear++;
            }
        }
        if (appear > max_appear || (appear == max_appear && pwds_copy[i].length() >= max_length)) {
            if (first_appear < i) first_appear = i;
            max_appear = appear;
            max_length = pwds_copy[i].length();
        }
    }
    return first_appear;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////