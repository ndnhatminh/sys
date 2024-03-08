/// /////////////////////////////////////////////////////////////////////////////////////// ///
///                                                                                         ///
///                          "A STUDY IN PINK" THE ASSIGNMENT                               ///
///                                                                                         ///
/// File name       : study_in_pink1.cpp           File Version: Final                      ///
/// Author          : NGUYEN HUNG THINH                                                     ///
/// Student's ID    : 2313287                      Course: CO1027 - Ky Thuat Lap Trinh      ///
/// Email           : thinh.nguyen1172005@hcmut.edu.vn                                      ///
/// Class           : MT23KTM1                                                              ///
/// Finish Raw Code : 28/02/2024                                                            ///
/// Finish Debug    : 01/03/2024 - 05:15 PM                                                 ///
/// Code written in : Visual Studio 2022 (x64) 17.9.1 - A Study in Pink solution            ///
/// Testcase (1)    : Author : Vo Tien (1000 testcases)                                     ///
///                   Date : 20/02/2023                                                     ///
///                   FB : https ://www.facebook.com/profile.php?id=100056605580171         ///
/// Testcase (2)    : Author : nhatkhangcs.github.io                                        ///
///                   Date : unknown                                                        ///
///                   Link : https://nhatkhangcs.github.io/Web-Programming-Fundamental-232  ///
///                                                                                         ///
/// /////////////////////////////////////////////////////////////////////////////////////// ///    

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

// FinalResult (Round and Limit Set depends on different objects)
int finres(float input, char obj) {
    int output;
    // Round up to an integer
    if (input >= 0) {
        if (int(input) == input) output = input; else output = int(input) + 1;
    }
    else {
        output = int(input);
    }

    // Limit Set and Reset for indicated objects
    switch (obj) {
    case 0: { // HP
        if (output >= 666) output = 666;
        if (output <= 0) output = 0;
    }
          break;
    case 1: { // EXP
        if (output >= 600) output = 600;
        if (output <= 0) output = 0;
    }
          break;
    case 2: { // M
        if (output >= 3000) output = 3000;
        if (output <= 0) output = 0;
    }
          break;
    case 3: // E
        if ((output > 99) || (output < 0)) output = -99;
        break;
    default: // Numeric Option used in mathematics problems
        break;
    }

    // Final Result
    return output;
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function

    e1 = finres(e1, 3);
    // Error Cir.
    if (e1 == -99) return -99;
    else {
        // Safety Check
        exp1 = finres(exp1, 1);
        exp2 = finres(exp2, 1);

        // Cir.2 Task 1
        if (e1 >= 80) { // Opt.5 Sherlock explains Watson all his clues (Opt.1.2.3)
            exp2 = finres(exp2 + e1 / 4.0 + 19, 1);
            exp2 = finres(exp2 + e1 / 9.0 + 21, 1);
            if (exp2 > 400) {
                exp2 = finres(exp2 + e1 / 16.0 + 17, 1);
                exp2 = finres(exp2 * 1.15, 1);
            }
            exp1 = finres(exp1 - e1, 1);
        }
        else if (e1 >= 66) { // Opt.4 Sherlock explains Watson Opt.1.2
            exp2 = finres(exp2 + e1 / 4.0 + 19, 1);
            if (exp2 > 200) {
                exp2 = finres(exp2 + e1 / 9.0 + 21, 1);
            }
            exp1 = finres(exp1 - e1, 1);
        }
        else if (e1 >= 50) { // Opt.3 Sherlock explains Watson
            exp2 = finres(exp2 + e1 / 16.0 + 17, 1);
            exp1 = finres(exp1 - e1, 1);
        }
        else if (e1 >= 20) { // Opt.2 Sherlock explains Watson
            exp2 = finres(exp2 + e1 / 9.0 + 21, 1);
            exp1 = finres(exp1 - e1, 1);
        }
        else if (e1 >= 4) { // Opt.1 Sherlock explains Watson
            exp2 = finres(exp2 + e1 / 4.0 + 19, 1);
            exp1 = finres(exp1 - e1, 1);
        }

        // Cir.1 Task 1
        if (e1 == 3) { // Opt.4 Sherlock explains Watson all his clues (Opt.1.2.3)
            exp2 = finres(exp2 + 29 + 45 + 75, 1);
            if ((e1 * 3 + exp1 * 7) % 2 == 0) {
                exp1 = finres(exp1 + (e1 * 3 + exp1 * 7) / 200.0, 1);
            }
            else {
                exp1 = finres(exp1 - (e1 * 3 + exp1 * 7) / 100.0, 1);
            }
        }
        else if (e1 == 2) { // Opt.3 Sherlock explains Watson
            exp2 = finres(exp2 + 75, 1);
            if ((e1 * 3 + exp1 * 7) % 2 == 0) {
                exp1 = finres(exp1 + (e1 * 3 + exp1 * 7) / 200.0, 1);
            }
            else {
                exp1 = finres(exp1 - (e1 * 3 + exp1 * 7) / 100.0, 1);
            }
        }
        else if (e1 == 1) { // Opt.2 Sherlock explains Watson
            exp2 = finres(exp2 + 45, 1);
            if ((e1 * 3 + exp1 * 7) % 2 == 0) {
                exp1 = finres(exp1 + (e1 * 3 + exp1 * 7) / 200.0, 1);
            }
            else {
                exp1 = finres(exp1 - (e1 * 3 + exp1 * 7) / 100.0, 1);
            }
        }
        else if (e1 == 0) { // Opt.1 Sherlock explains Watson
            exp2 = finres(exp2 + 29, 1);
            if ((e1 * 3 + exp1 * 7) % 2 == 0) {
                exp1 = finres(exp1 + (e1 * 3 + exp1 * 7) / 200.0, 1);
            }
            else {
                exp1 = finres(exp1 - (e1 * 3 + exp1 * 7) / 100.0, 1);
            }
        }

        // Final Task 1 Output
        return exp1 + exp2;
    }
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function

    E2 = finres(E2, 3);
    //Addictional Variables
    int EXPtoS[25], minEXPtoS1 = 0, minEXPtoS2 = 0, S1 = 0, S2 = 0;
    float P1 = 0, P2 = 0, P3 = 0;
    float budget = 0;

    // Error Cir.
    if (E2 == -99) return -99;
    else {
        // Safe Check
        HP1 = finres(HP1, 0);
        EXP1 = finres(EXP1, 1);
        M1 = finres(M1, 2);

        // First Road
        // Identify P1
        for (int i = 0; i <= 24; i++) {
            EXPtoS[i] = abs(EXP1 - i * i);
        }
        minEXPtoS1 = EXPtoS[0];
        for (int i = 1; i <= 24; i++) {
            if (minEXPtoS1 > EXPtoS[i]) {
                minEXPtoS1 = EXPtoS[i];
            }
        }
        for (int i = 0; i <= 24; i++) {
            if (minEXPtoS1 == EXPtoS[i]) {
                S1 = i * i;
            }
        }
        if (EXP1 >= S1) P1 = 1.0; else P1 = (EXP1 / S1 + 80) / 123.0;

        // Second Road
        budget = (M1 * 0.5);
        while (1 == 1) { // Loop until Money Out
            if ((M1 == 0) || (budget < 0)) {
                break; // Money Out
            }
            // Event 1
            if (HP1 < 200) {
                HP1 = finres(HP1 * 1.3, 0);
                M1 = finres(M1 - 150, 2);
                if (E2 % 2 != 0) {
                    budget = (budget - 150);

                }
            }
            else {
                HP1 = finres(HP1 * 1.1, 0);
                M1 = finres(M1 - 70, 2);
                if (E2 % 2 != 0) {
                    budget = budget - 70;

                }
            }
            if ((M1 == 0) || (budget < 0)) {
                break; // Money Out
            }
            // Event 2
            if (EXP1 < 400) {
                M1 = finres(M1 - 200, 2);
                if (E2 % 2 != 0) {
                    budget = budget - 200;

                }
            }
            else {
                M1 = finres(M1 - 120, 2);
                if (E2 % 2 != 0) {
                    budget = budget - 120;

                }
            }
            EXP1 = finres(EXP1 * 1.13, 1);
            if ((M1 == 0) || (budget < 0)) {
                break; // Money Out
            }
            // Event 3
            if (EXP1 < 300) {
                M1 = finres(M1 - 100, 2);
                if (E2 % 2 != 0) {
                    budget = budget - 100;

                }
            }
            else {
                M1 = finres(M1 - 120, 2);
                if (E2 % 2 != 0) {
                    budget = budget - 120;

                }
            }
            EXP1 = finres(EXP1 * 0.9, 1);
            if ((M1 == 0) || (budget < 0)) {
                break; // Money Out
            }
            if (E2 % 2 == 0) break;
        }
        // End loop
        HP1 = finres(HP1 * 0.83, 0);
        EXP1 = finres(EXP1 * 1.17, 1);
        // Identify P2
        for (int i = 0; i <= 24; i++) {
            EXPtoS[i] = abs(EXP1 - i * i);
        }
        minEXPtoS2 = EXPtoS[0];
        minEXPtoS2 = EXPtoS[0];
        for (int i = 1; i <= 24; i++) {
            if (minEXPtoS2 > EXPtoS[i]) {
                minEXPtoS2 = EXPtoS[i];
            }
        }
        for (int i = 0; i <= 24; i++) {
            if (minEXPtoS2 == EXPtoS[i]) {
                S2 = i * i;
            }
        }
        // Final P2
        if (EXP1 >= S2) P2 = 1.0; else P2 = (EXP1 / S2 + 80) / 123.0;

        // Third Road
        float arrP3[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        // Indentify P3
        P3 = arrP3[(int(E2 / 10) + (E2 % 10)) % 10] / 100.0;

        // Final Total P
        if ((P1 == 1.0) && (P2 == 1.0) && (P3 == 1.0)) {
            EXP1 = finres(EXP1 * 0.75, 1);
        }
        else {
            if (((P1 + P2 + P3) / 3) > 0.5) {
                HP1 = finres(HP1 * 0.9, 0);
                EXP1 = finres(EXP1 * 1.2, 1);
            }
            else {
                HP1 = finres(HP1 * 0.85, 0);
                EXP1 = finres(EXP1 * 1.15, 1);
            }
        }

        // Final Task 2 Output
        return HP1 + EXP1 + M1;
    }
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function

    E3 = finres(E3, 3);
    // Additional Variables
    int count_i = 0, count_j = 0, locat_i = 0, locat_j = 0, x = 0, y = 0;
    int maxLD = 0, maxLU = 0, maxRD = 0, maxRU = 0, maxL = 0, maxR = 0, max = 0;

    // Error Cir.
    if (E3 == -99) return -99;
    else {
        // Safe Check
        HP1 = finres(HP1, 0);
        HP2 = finres(HP2, 0);
        EXP1 = finres(EXP1, 1);
        EXP2 = finres(EXP2, 1);

        // The taxi ran away
        // Identify runmap matrix 10x10
        int runmap[10][10];
        // Initialize runmap with '0' data
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                runmap[i][j] = 0;
            }
        }
        // Filling runmap matrix with specialized formular
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                runmap[i][j] = finres(((E3 * j) + (i * 2)) * (i - j), 4);
                //Count_i
                if (runmap[i][j] > (E3 * 2)) count_i++;
                if (runmap[i][j] < (-E3)) count_j++;
            }
        }

        // Identify the address of [i][j] where (Sherlock and Watson) might catch up with the runaway taxi
        // Identify locat_i
        locat_i = int(count_i / 10) + (count_i % 10);
        while (int(locat_i / 10) != 0) {
            locat_i = int(locat_i / 10) + (locat_i % 10);
        }
        locat_j = int(count_j / 10) + (count_j % 10);
        while (int(locat_j / 10) != 0) {
            locat_j = int(locat_j / 10) + (locat_j % 10);
        }
        // Announce the address [i][j]

        // Chase started
        // Identify Maximum of Left Down (maxLD) line
        x = locat_i; y = locat_j; maxLD = runmap[x][y];
        while ((x <= 8) && (y <= 8)) {
            x++; y++;
            if (maxLD < runmap[x][y]) {
                maxLD = runmap[x][y];
            }
        }
        // Identify Maximum of Left Up (maxLU) line
        x = locat_i; y = locat_j; maxLU = runmap[x][y];
        while ((x >= 1) && (y >= 1)) {
            x--; y--;
            if (maxLU < runmap[x][y]) {
                maxLU = runmap[x][y];
            }
        }
        if (maxLU >= maxLD) maxL = maxLU; else if (maxLU <= maxLD) maxL = maxLD;
        x = locat_i; y = locat_j; maxRD = runmap[x][y];
        while ((x <= 8) && (y >= 1)) {
            x++; y--;
            if (maxRD < runmap[x][y]) {
                maxRD = runmap[x][y];
            }
        }
        // Identify Maximum of Right Up (maxRU) line
        x = locat_i; y = locat_j; maxRU = runmap[x][y];
        while ((x >= 1) && (y <= 8)) {
            x--; y++;
            if (maxRU < runmap[x][y]) {
                maxRU = runmap[x][y];
            }
        }
        if (maxRU >= maxRD) maxR = maxRU; else if (maxRU <= maxRD) maxR = maxRD;
        // Identify Maximum of both Left and Right lines
        if (maxR >= maxL) max = maxR; else if (maxR <= maxL) max = maxL;

        // Final Task 3 Output
        if (abs(runmap[locat_i][locat_j]) > max) {
            EXP1 = finres(EXP1 * 0.88, 1);
            EXP2 = finres(EXP2 * 0.88, 1);
            HP1 = finres(HP1 * 0.9, 0);
            HP2 = finres(HP2 * 0.9, 0);
            return runmap[locat_i][locat_j];
        }
        else if (abs(runmap[locat_i][locat_j]) <= max) {
            EXP1 = finres(EXP1 * 1.12, 1);
            EXP2 = finres(EXP2 * 1.12, 1);
            HP1 = finres(HP1 * 1.1, 0);
            HP2 = finres(HP2 * 1.1, 0);
            return max;
        }
    }
    return 0;
}

// Task 4
// 'Check if there is any special char' function
bool isSpecChar(string str, char findnum) {
    size_t findn = str.find(findnum);
    if (findn != string::npos) {
        return true;
    }
    else {
        return false;
    }
}

int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function

    // Addictional Variables
    int exist = 0;
    int errcode[6] = { -10, -10, -10, -10, -10, -10 };

    //Convert const char* to string (I don't like using C-style syntax and neither does the IDE)
    string emailS = email;
    string seS = "@"; // Password must not contain this string
    string sS = s;

    // Identify se - part name of the email
    size_t find64 = emailS.find(seS); // find64 means find the character listed 64 in DEC in ASCII, aka. @
    seS.assign(emailS, 0, find64);

    // Check if the Password valid
    // Check the length of the Password s
    if (sS.size() < 8) {
        errcode[0] = -1;
    }
    if (sS.size() > 20) {
        errcode[1] = -2;
    }
    // Check if the Password contains se string
    size_t sei = sS.find(seS);
    if (sei != string::npos) {
        errcode[2] = -(300 + int(sei));
    }
    // Check if the Password do not have a roll of 3 duplicated chars
    // Duplicated
    for (int sci = 0; sci <= sS.size() - 1; sci++) {
        if (sS[sci] == sS[sci + 1]) {
            if (sS[sci] == sS[sci + 2]) {
                errcode[3] = -(400 + sci);
                break;
            }
        }
    }
    // Check if the Password do contain at least 1 special char @ # % $ !
    exist = 0;
    if (isSpecChar(s, 33)) exist++;
    if (isSpecChar(s, 35)) exist++;
    if (isSpecChar(s, 36)) exist++;
    if (isSpecChar(s, 37)) exist++;
    if (isSpecChar(s, 64)) exist++;
    if (exist == 0) errcode[4] = -5;
    // Check if all char obeys the range rules
    // A-Z; a-z; 0-9; @ # % $ !
    for (int i = 0; i <= sS.size() - 1; i++) {
        if (!(((sS[i] >= 48) && (sS[i] <= 57)) || ((sS[i] >= 64) && (sS[i] <= 90)) || ((sS[i] >= 97) && (sS[i] <= 122)) || (sS[i] == 33) || ((sS[i] >= 35) && (sS[i] <= 37)))) {
            errcode[5] = i;
            break;
        }
    }

    // Final Task 4 Output
    if (errcode[0] != -10) return errcode[0];
    else if (errcode[1] != -10) return errcode[1];
    else if (errcode[2] != -10) return errcode[2];
    else if (errcode[3] != -10) return errcode[3];
    else if (errcode[4] != -10) return errcode[4];
    else return errcode[5];
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    // Addictional Variables
    int max_t = 0, max_i = 0, max_l = 0;
    int commonPass[300];
    int lengthPass[300];
    int exist = 0;

    // Initializing commonPass[] and lengthPass[] with '0' data
    for (int i = 0; i < 300; i++) {
        lengthPass[i] = 0;
        commonPass[i] = 0;
    }

    // Counting the existence of each data and its size in length
    for (int i = 0; i <= num_pwds - 1; i++) {
        exist = 0;
        for (int j = 0; j <= num_pwds - 1; j++) {
            if ((string(arr_pwds[i]) == string(arr_pwds[j])) && (j >= i)) {
                exist++;
            }
        }
        commonPass[i] = exist;
        lengthPass[i] = string(arr_pwds[i]).length();
    }

    // Try to find the longest password in the most common used passwords
    max_i = 0;
    max_l = string(arr_pwds[0]).length();
    max_t = commonPass[0];
    for (int i = 0; i <= num_pwds - 1; i++) {
        if ((max_t < commonPass[i]) || ((max_l < lengthPass[i]) && (max_t == commonPass[i]))) {
            max_t = commonPass[i];
            max_l = lengthPass[i];
            max_i = i;
        }
    }

    // Final Task 5 Output
    // First-seen correct password
    return max_i;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////