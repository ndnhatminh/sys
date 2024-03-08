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

// Check valid (check the HP, EXP, M if they are in the requested range)
// HP = [0; 666], EXP = [0; 600], M = [0; 3000]
//             type 1: HP, 2: EXP, M: 3
int checkValid(int type, int value) {

    // Check HP
    if (type == 1) {
        int temp_hp = value;
        if (value > 666) return  666;
        else if (value < 0) return 0;
        else return temp_hp;
    }

    // Check EXP
    if (type == 2) {
        int temp_exp = value;
        if (value > 600) return  600;
        else if (value < 0) return 0;
        else return temp_exp;
    }

    // Check M
    if (type == 3) {
        int temp_m = value;
        if (value > 3000) return  3000;
        else if (value < 0) return 0;
        else return temp_m;
    }
    return value;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 >= 0 && e1 <= 99) {
        exp1 = checkValid(2, exp1);
        exp2 = checkValid(2, exp2);
        // Case 1 ==============================
        if (e1 >= 0 && e1 <= 3) {
            // Watson +++++++++++++++++++++++
            switch (e1) {
            case (0):
                exp2 += 29;
                exp2 = checkValid(2, exp2);
                break;

            case (1):
                exp2 += 45;
                exp2 = checkValid(2, exp2);
                break;

            case (2):
                exp2 += 75;
                exp2 = checkValid(2, exp2);
                break;

            case (3):
                exp2 += (29 + 45 + 75);
                exp2 = checkValid(2, exp2);
                break;

            }
            // End Watson ++++++++++++++++++++

            // Sherlock ++++++++++++++++++++++
            int D = (e1 * 3) + (exp1 * 7);
            if (D % 2 == 0) {
                exp1 = ceil(exp1 + static_cast<float>(D) / 200);
                exp1 = checkValid(2, exp1);
            }
            else {
                exp1 = ceil(exp1 - static_cast<float>(D) / 100);
                exp1 = checkValid(2, exp1);
            }
            // End Sherlock ++++++++++++++++++
        }
        // End Case 1 ==========================

        // Case 2 ==============================
        else if (e1 >= 4 && e1 <= 99) {
            // Watson ++++++++++++++++++++++++
            // Sherlock explains Info 1
            if (e1 >= 4 && e1 <= 19) {
                exp2 = ceil(exp2 + (static_cast<float>(e1) / 4) + 19);
                exp2 = checkValid(2, exp2);
            }
            // Sherlock explains Info 2
            else if (e1 >= 20 && e1 <= 49) {
                exp2 = ceil(exp2 + (static_cast<float>(e1) / 9) + 21);
                exp2 = checkValid(2, exp2);
            }
            // Sherlock explains Info 3
            else if (e1 >= 50 && e1 <= 65) {
                exp2 = ceil(exp2 + (static_cast<float>(e1) / 16) + 17);
                exp2 = checkValid(2, exp2);
            }

            else if (e1 >= 66 && e1 <= 79) {
                // Sherlock explains Info 1
                exp2 = ceil(exp2 + (static_cast<float>(e1) / 4) + 19);
                exp2 = checkValid(2, exp2);
                if (exp2 > 200) {
                    // Sherlock explains Info 2
                    exp2 = ceil(exp2 + (static_cast<float>(e1) / 9) + 21);
                    exp2 = checkValid(2, exp2);
                }
            }
            else if (e1 >= 80 && e1 <= 99) {
                // Sherlock explains Info 1
                exp2 = ceil(exp2 + (static_cast<float>(e1) / 4) + 19);
                exp2 = checkValid(2, exp2);
                // Sherlock explains Info 2
                exp2 = ceil(exp2 + (static_cast<float>(e1) / 9) + 21);
                exp2 = checkValid(2, exp2);
                if (exp2 > 400) {
                    // Sherlock explains Info 3
                    exp2 = ceil(exp2 + (static_cast<float>(e1) / 16) + 17);
                    exp2 = checkValid(2, exp2);
                    // Watson's EXP2 plus 15% more
                    exp2 = ceil(exp2 + (static_cast<float>(exp2) * 0.15));
                    exp2 = checkValid(2, exp2);
                }
            }
            // Sherlock's EXP2 minus E1
            exp1 -= e1;
            exp1 = checkValid(2, exp1);
        }
        // End Case 2===========================

        exp1 = checkValid(2, exp1);
        exp2 = checkValid(2, exp2);
        
        return exp1 + exp2;
    }
    else return -99;
}

// Task 2
double calcP(int exp1) {
    int S;  // Let S be the nearest perfect square number

    // Find S =================================================================================
    int previous_perfect_square = 1;
    int current_perfect_square;
    bool run = false;

    if (exp1 == 0) S = 1;
    else {
        // i <= 625 because 625 is the nearest perfect square that is 
        // close to 600-the cap of exp
        for (int i = 0; i <= 625; i++) {
            for (int j = 1; j <= i; j++) {
                if (j * j == i) {
                    current_perfect_square = i;
                    // Find 2  nearest perfect square numbers to the exp1
                    if ((exp1 >= previous_perfect_square) && (exp1 <= current_perfect_square)) {
                        // Check which perfect square number is the closest to the exp2
                        if ((exp1 - previous_perfect_square) < (current_perfect_square - exp1)) {
                            S = previous_perfect_square;
                        }
                        else S = current_perfect_square;
                        // ============================================================
                        run = true;
                    }
                    else previous_perfect_square = current_perfect_square;
                }
            }
            if (run == true) break; // Breakout the outermost for-loop when found the nearest perfect square
        }
    }
    // End Find S =============================================================================

    // Calculate P and reurn the value ==========
    double P;
    if (exp1 >= S) P = 1;
    else P = ((static_cast<double>(exp1) / S) + 80) / 123;

    return P * 100; // Unit is %
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 >= 0 && E2 <= 99) {
        HP1 = checkValid(1, HP1);
        EXP1 = checkValid(2, EXP1);
        M1 = checkValid(3, M1);
        // Road 1 ==========================
        double P1 = calcP(EXP1);
        // End Road 1 ======================

        // Road 2 ==========================
        int M1_spent = 0;
        double half_M1 = static_cast<double>(M1) / 2;

        if (E2 % 2 != 0) {
            while (M1 > 0) { // Need to be checked if M1 > 0
                // Event 1
                if (HP1 < 200) {
                    HP1 = ceil(HP1 + (static_cast<float>(HP1) * 0.3));
                    HP1 = checkValid(1, HP1);
                    M1 -= 150;
                    M1 = checkValid(3, M1);
                    M1_spent += 150;
                }
                else {
                    HP1 = ceil(HP1 + (static_cast<float>(HP1) * 0.1));
                    HP1 = checkValid(1, HP1);
                    M1 -= 70;
                    M1 = checkValid(3, M1);
                    M1_spent += 70;
                }
                if (M1_spent > half_M1) break;

                //Event 2
                if (EXP1 < 400) {
                    // Sherlock uses taxi
                    M1 -= 200;
                    M1 = checkValid(3, M1);
                    M1_spent += 200;
                }
                else {
                    // Sherlock uses carriage
                    M1 -= 120;
                    M1 = checkValid(3, M1);
                    M1_spent += 120;
                }
                EXP1 = ceil(EXP1 + (static_cast<float>(EXP1) * 0.13));
                EXP1 = checkValid(2, EXP1);
                if (M1_spent > half_M1) break;

                // Event 3
                if (EXP1 < 300) {
                    M1 -= 100;
                    M1 = checkValid(3, M1);
                    M1_spent += 100;
                }
                else {
                    M1 -= 120;
                    M1 = checkValid(3, M1);
                    M1_spent += 120;
                }
                EXP1 = ceil(EXP1 - (static_cast<float>(EXP1) * 0.1));
                EXP1 = checkValid(2, EXP1);
                if (M1_spent > half_M1) break;
            }
            // Change HP1 and EXP1 
            HP1 = ceil(HP1 - (static_cast<float>(HP1) * 0.17));
            HP1 = checkValid(1, HP1);
            EXP1 = ceil(EXP1 + (static_cast<float>(EXP1) * 0.17));
            EXP1 = checkValid(2, EXP1);
        }

        else {
            while (M1 > 0) {
                // Event 1
                if (HP1 < 200) {
                    HP1 = ceil(HP1 + (static_cast<float>(HP1) * 0.3));
                    HP1 = checkValid(1, HP1);
                    M1 -= 150;
                    M1 = checkValid(3, M1);
                    M1_spent += 150;
                }
                else {
                    HP1 = ceil(HP1 + (static_cast<float>(HP1) * 0.1));
                    HP1 = checkValid(1, HP1);
                    M1 -= 70;
                    M1 = checkValid(3, M1);
                    M1_spent += 70;
                }
                if (M1 <= 0) break;

                //Event 2
                if (EXP1 < 400) {
                    // Sherlock uses taxi
                    M1 -= 200;
                    M1 = checkValid(3, M1);
                    M1_spent += 200;
                }
                else {
                    // Sherlock uses carriage
                    M1 -= 120;
                    M1 = checkValid(3, M1);
                    M1_spent += 120;
                }
                EXP1 = ceil(EXP1 + (static_cast<float>(EXP1) * 0.13));
                EXP1 = checkValid(2, EXP1);
                if (M1 <= 0) break;

                // Event 3
                if (EXP1 < 300) {
                    M1 -= 100;
                    M1 = checkValid(3, M1);
                    M1_spent += 100;
                }
                else {
                    M1 -= 120;
                    M1 = checkValid(3, M1);
                    M1_spent += 120;
                }
                EXP1 = ceil(EXP1 - (static_cast<float>(EXP1) * 0.1));
                EXP1 = checkValid(2, EXP1);
                if (M1 <= 0) break;

                break; // To run 3 Events once
            }

            // Change HP1 and EXP1 
            HP1 = ceil(HP1 - (static_cast<float>(HP1) * 0.17));
            HP1 = checkValid(1, HP1);
            EXP1 = ceil(EXP1 + (static_cast<float>(EXP1) * 0.17));
            EXP1 = checkValid(2, EXP1);
        }
        double P2 = calcP(EXP1);
        // End Road 2 ======================

        // Road 3 ==========================
        double P3;
        int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        if (E2 < 10) P3 = P[E2];
        else {
            int b = E2 % 10;
            int a = (E2 - b) / 10;
            P3 = P[(a + b) % 10];
        }
        // End Road 3 ======================

        if (P1 == 100 && P2 == 100 && P3 == 100) {
            EXP1 = ceil(EXP1 - (static_cast<float>(EXP1) * 0.25));
            EXP1 = checkValid(2, EXP1);
        }
        else {
            if (((P1 + P2 + P3) / 3) < 50) {
                EXP1 = ceil(EXP1 + (static_cast<float>(EXP1) * 0.15));
                EXP1 = checkValid(2, EXP1);
                HP1 = ceil(HP1 - (static_cast<float>(HP1) * 0.15));
                HP1 = checkValid(1, HP1);
            }
            else {
                EXP1 = ceil(EXP1 + (static_cast<float>(EXP1) * 0.2));
                EXP1 = checkValid(2, EXP1);
                HP1 = ceil(HP1 - (static_cast<float>(HP1) * 0.1));
                HP1 = checkValid(1, HP1);
            }
        }

        HP1 = checkValid(1, HP1);
        EXP1 = checkValid(2, EXP1);
        M1 = checkValid(3, M1);

        return HP1 + EXP1 + M1;
    }
    else return -99;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 >= 0 && E3 <= 99) {
        EXP1 = checkValid(2, EXP1);
        EXP2 = checkValid(2, EXP2);
        HP1 = checkValid(1, HP1);
        HP2 = checkValid(1, HP2);
        // Create Taxi matrix
        int Taxi[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                Taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }

        // Find the meeting point
        // The taxi will meet Sherlock and Watson at (I;J) with 
        // I is the number of Taxi's score > E3*2
        // J is the number of Taxi's score < -E3
        int I;
        int J;
        int temp_I = 0;
        int temp_J = 0;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (Taxi[i][j] > E3 * 2) temp_I++;
                if (Taxi[i][j] < -E3) temp_J++;
            }
        }

        // To have I < 10
        if (temp_I < 10) I = temp_I;
        else {
            while (temp_I >= 10) {
                int b = temp_I % 10;
                int a = (temp_I - b) / 10;
                temp_I = a + b;
            }
            I = temp_I;
        }

        // To have J < 10
        if (temp_J < 10) I = temp_J;
        else {
            while (temp_J >= 10) {
                int b = temp_J % 10;
                int a = (temp_J - b) / 10;
                temp_J = a + b;
            }
            J = temp_J;
        }

        int Taxi_score = Taxi[I][J];

        // L_diag ==========================================
        int L_diag[10];

        int num_of_L_elements;

        // Up
        if (I < J) {
            num_of_L_elements = 10 - (J - I);
            for (int i = 0; i < num_of_L_elements; i++) {
                L_diag[i] = Taxi[0 + i][J - I + i];
            }
        }
        // Down
        else if (I > J) {
            num_of_L_elements = 10 - (I - J);
            for (int i = 0; i < num_of_L_elements; i++) {
                L_diag[i] = Taxi[I - J + i][0 + i];
            }
        }
        // Between
        else {
            num_of_L_elements = 10;
            for (int i = 0; i < 10; i++) {
                L_diag[i] = Taxi[i][i];
            }
        }

        // R_diag ==========================================
        int R_diag[10];
        int k = 0;
        int num_of_R_elements = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i + j == I + J) {
                    R_diag[k] = Taxi[i][j];
                    k++;
                    num_of_R_elements++;
                }
            }
        }

        // Find largest number in L_diag
        int max = L_diag[0];
        for (int i = 0; i < num_of_L_elements; i++) {
            if (max < L_diag[i]) {
                max = L_diag[i];
            }
        }
        // Find largest number in both arrays L and R
        for (int i = 0; i < num_of_R_elements; i++) {
            if (max < R_diag[i]) {
                max = R_diag[i];
            }
        }

        int S_n_W_score = abs(max);

        if (abs(Taxi_score) > S_n_W_score) {
            // Sherlock and Watson lost the taxi
            EXP1 = ceil(EXP1 - static_cast<float>(EXP1) * 0.12);
            EXP1 = checkValid(2, EXP1);

            EXP2 = ceil(EXP2 - static_cast<float>(EXP2) * 0.12);
            EXP2 = checkValid(2, EXP2);

            HP1 = ceil(HP1 - static_cast<float>(HP1) * 0.1);
            HP1 = checkValid(1, HP1);

            HP2 = ceil(HP2 - static_cast<float>(HP2) * 0.1);
            HP2 = checkValid(1, HP2);

            return Taxi_score;
        }
        else {
            // Sherlock and Watson catch the taxi
            EXP1 = ceil(EXP1 + static_cast<float>(EXP1) * 0.12);
            EXP1 = checkValid(2, EXP1);

            EXP2 = ceil(EXP2 + static_cast<float>(EXP2) * 0.12);
            EXP2 = checkValid(2, EXP2);

            HP1 = ceil(HP1 + static_cast<float>(HP1) * 0.1);
            HP1 = checkValid(1, HP1);

            HP2 = ceil(HP2 + static_cast<float>(HP2) * 0.1);
            HP2 = checkValid(1, HP2);

            return S_n_W_score;
        }
        EXP1 = checkValid(2, EXP1);
        EXP2 = checkValid(2, EXP2);
        HP1 = checkValid(1, HP1);
        HP2 = checkValid(1, HP2);
    }

    else return -99;
}

// Task 4
// Calculate the length of a string
int stringLen(const char * str_len) {
    int len_of_str = 0;
    while (*str_len != '\0') {
        len_of_str++;
        str_len++; // Move the pointer s to the next character
    }
    return len_of_str;
}
// Check for string se in string s
int first_occure; // To make this a global variable and calculate the index of the first character occurrence
                    // first_occure = <sei>
bool have_str_similar(string S, string SE) {
    int count = 0;

    bool run = true;
    int k = 0; // check for b's index

    while (run) {
        for (int j = 0; j < S.size(); j++) {
            if (SE[k] == S[j]) {
                first_occure = j - k;
                run = false;
                break;
            }
        }
        k++;
    }

    run = true;
    for (int i = 0; i < SE.size() && run; i++) {
        for (int j = 0; j < S.size(); j++) {
            if (SE[i] == S[j]) {
                if (j - i <= first_occure) {
                    count++;
                    break;
                }
                else run = false;
            }
        }
    }

    if (count == SE.size()) return true;
    else return false;
}

// Check for 2 consecutive and indentical character in password
int first_con_inden_char; // To make this a global variable and 
                            //calculate the index of the first consecutive and identical character
                            // first_con_inden_char = <sei>
bool has_consecutive_indentical_char(const char * str) {
    for (int i = 0; i < stringLen(str); i++) {
        if (str[i] == str[i + 1]) {
            first_con_inden_char = i;
            return true;
        }
    }
    return false;
}

// Check if password does not have a special character
bool does_not_have_special_char(const char * STR) {
    int check = 0;
    for (int i = 0; i < stringLen(STR); i++) {
        if (STR[i] == '@' || STR[i] == '#' || STR[i] == '%' || STR[i] == '$' || STR[i] == '!') {
            check++;
        }
    }
    if (check > 0) return false;
    else return true;
}

// Check for an invalid character
int invalid_char_index;
bool have_invalid_char(const char* strg) {
    bool check_char = false;
    for (int i = 0; i < stringLen(strg); i++) {
        if (((int)strg[i] == 34) || ((int)strg[i] >= 38 && (int)strg[i] <= 47) ||
            ((int)strg[i] >= 58 && (int)strg[i] <= 63) ||
            ((int)strg[i] >= 91 && (int)strg[i] <= 96) ||
            ((int)strg[i] >= 123 && (int)strg[i] <= 126)) {
            check_char = true;
            invalid_char_index = i;
            break;
        }
        else continue;
    }

    return check_char;
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // Put the character before '@' in email into se
    char* se = new char[stringLen(email) + 1];

    for (int i = 0; i < stringLen(email); i++) {
        if (email[i] != '@') se[i] = email[i];
        else {
            se[i] = '\0';
            break;
        }
    }

    // Check for password
    if (stringLen(s) < 8) return -1; // Password's length < 8
    else if (stringLen(s) > 20) return -2; // Password's length > 20
    else if (have_str_similar(s, se)) return (-(300 + first_occure));
    else if (has_consecutive_indentical_char(s)) return (-(400 + first_con_inden_char));
    else if (does_not_have_special_char(s)) return -5;
    else if (have_invalid_char(s)) return invalid_char_index;
    else return -10;
    /*return -99;*/
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string max_element = arr_pwds[0];
    int max_count = 1;

    for (int i = 0; i < num_pwds; i++) {
        int count = 1;
        for (int j = 0; j < num_pwds; j++) {
            if (arr_pwds[i] == arr_pwds[j]) {
                count++;
            }
        }
        if ((count > max_count) || (count == max_count && stringLen(arr_pwds[i]) > max_element.length())) {
            max_count = count;
            max_element = arr_pwds[i];
        }
    }

    int max_element_pos;
    for (int i = 0; i < num_pwds; i++) {
        if (max_element == arr_pwds[i]) {
            max_element_pos = i;
            break;
        }
    }

    return max_element_pos;
    //return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////