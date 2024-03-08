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

//######### HELPER FUNCTIONS #########//
int closestSquare(int n) {
    double root = sqrt(n);
    int closestInt = round(root);
    int closestSquare = closestInt * closestInt;
    return closestSquare;
}

double customCeil(double value, double precision = 1e-10) {
    double intValue = floor(value);
    if (value - intValue > precision) {
        return intValue + 1.0;
    } else {
        return intValue;
    }
}

void path_2_events_loop(int & HP1, int & EXP1, int & M1, int halfM1, int & moneySpent) {
    if (M1 <= 0) { // no money
        M1 = 0;
        return;
    }
    while (moneySpent <= halfM1) {
        //////////////! Event 1
        if (HP1 < 200) {
            HP1 = customCeil(HP1 * 1.3);
            M1 -= 150;
            moneySpent += 150;
        }
        else {
            HP1 = customCeil(HP1 * 1.1);
            M1 -= 70;
            moneySpent += 70;
        }
        HP1 = (HP1 < HP_MIN) ? HP_MIN : (HP1 > HP_MAX) ? HP_MAX : HP1; // reset HP
        if (moneySpent > halfM1) return;

        //////////////! Event 2
        if (EXP1 < 400) {
            M1 -= 200; // taxi
            moneySpent += 200;
        } else {
            M1 -= 120; // horse ride
            moneySpent += 120;
        }
        EXP1 = customCeil(EXP1 * 1.13);
        EXP1 = (EXP1 < EXP_MIN) ? EXP_MIN : (EXP1 > EXP_MAX) ? EXP_MAX : EXP1; // reset EXP
        if (moneySpent > halfM1) return;
        
        //////////////! Event 3
        if (EXP1 < 300) {
            M1 -= 100;
            moneySpent += 100;
        } else {
            M1 -= 120;
            moneySpent += 120;
        }
        EXP1 = customCeil(EXP1 * 0.9);
        EXP1 = (EXP1 < EXP_MIN) ? EXP_MIN : (EXP1 > EXP_MAX) ? EXP_MAX : EXP1; // reset EXP
        if (moneySpent > halfM1) return;
    }
}

void path_2_events(int & HP1, int & EXP1, int & M1) {
    if (M1 <= 0) { // no money
        M1 = 0;
        return;
    }

    //////////////! Event 1
    if (HP1 < 200) {
        HP1 = customCeil(HP1 * 1.3);
        M1 -= 150;
    }
    else {
        HP1 = customCeil(HP1 * 1.1);
        M1 -= 70;
    }
    HP1 = (HP1 < HP_MIN) ? HP_MIN : (HP1 > HP_MAX) ? HP_MAX : HP1; // reset HP
    if (M1 <= 0) {
        M1 = 0;
        return;
    }

    //////////////! Event 2
    if (EXP1 < 400) {
        M1 -= 200; // taxi
    } else {
        M1 -= 120; // horse ride
    }
    EXP1 = customCeil(EXP1 * 1.13);
    EXP1 = (EXP1 < EXP_MIN) ? EXP_MIN : (EXP1 > EXP_MAX) ? EXP_MAX : EXP1; // reset EXP
    if (M1 <= 0) {
        M1 = 0;
        return;
    }
    
    //////////////! Event 3
    if (EXP1 < 300) {
        M1 -= 100;
    } else {
        M1 -= 120;
    }
    EXP1 = customCeil(EXP1 * 0.9);
    EXP1 = (EXP1 < EXP_MIN) ? EXP_MIN : (EXP1 > EXP_MAX) ? EXP_MAX : EXP1; // reset EXP
    if (M1 <= 0) {
        M1 = 0;
        return;
    }
}

int calculate_i(int E2, int P3_array[]) {
    if (E2 < 10) {
        return E2; // Return E2 if it is a one-digit number
    } else {
        int sum = (E2 / 10) + (E2 % 10); // Calculate the sum of the two digits
        int unitPlace = sum % 10; // Get the number in the unit place of the sum
        
        return unitPlace; // Return the number in the unit place of the sum
    }
}

// void printChaseMap(int chaseMap[ROWS][COLS]) {
//     for (int i = 0; i < ROWS; ++i) {
//         for (int j = 0; j < COLS; ++j) {
//             cout << chaseMap[i][j] << "\t";
//         }
//         cout << endl;
//     }
// }

int maxDiagonalValue(int chaseMap[ROWS][COLS], int i, int j) {
    // Initialize variables to store maximum values from left and right diagonals
    int maxLeftDiagonal = chaseMap[i][j];
    int maxRightDiagonal = chaseMap[i][j];

    // Traverse left diagonal
    for (int k = 1; i - k >= 0 && j - k >= 0; ++k) {
        maxLeftDiagonal = max(maxLeftDiagonal, chaseMap[i - k][j - k]);
    }
    for (int k = 1; i + k <= 9 && j - k >= 0; ++k) {
        maxLeftDiagonal = max(maxLeftDiagonal, chaseMap[i + k][j - k]);
    }

    // Traverse right diagonal
    for (int k = 1; i + k <= 9 && j + k <= 9; ++k) {
        maxRightDiagonal = max(maxRightDiagonal, chaseMap[i + k][j + k]);
    }
    for (int k = 1; i - k >= 0 && j + k <= 9; ++k) {
        maxRightDiagonal = max(maxRightDiagonal, chaseMap[i - k][j + k]);
    }

    // Return maximum value from both
    return max(maxLeftDiagonal, maxRightDiagonal);
}

int findValue_i(int chaseMap[ROWS][COLS], int E3) {
    // Count the number of points greater than E3 * 2
    int i = 0;
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) 
        {
            if (chaseMap[row][col] > E3 * 2) {
                ++i;
            }
        }
    }

    // If i or j is a two-digit number, keep repeating the stage sum of two digits until the sum is the one-digit number
    while (i >= 10) {
        int sum = 0;
        while (i > 0) {
            sum += i % 10;
            i /= 10;
        }
        i = sum;
    }

    return i;
}

int findValue_j(int chaseMap[ROWS][COLS], int E3) {
    // Count the number of points smaller than -E3
    int j = 0;
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (chaseMap[row][col] < -E3) {
                ++j;
            }
        }
    }

    while (j >= 10) {
        int sum = 0;
        while (j > 0) {
            sum += j % 10;
            j /= 10;
        }
        j = sum;
    }

    return j;
}

string get_se(const char* email) {
    size_t atIndex = strchr(email, '@') - email;
    if (atIndex != string::npos) {
        return string(email, atIndex);
    }
    return "";
}

int find_sei(const char* s, const char* se) {
    const char* position = std::strstr(s, se);
    if (position != nullptr) {
        return position - s;
    }
    return -1;  // Substring not found
}

int find_sci(const char* s) {
    size_t length = strlen(s);
    for (size_t i = 0; i < length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return static_cast<int>(i);
        }
    }
    return -1;  // Substring with > 2 consecutive identical characters not found
}

int check_chars(const char* s) {
    const char* specialChars = "@#%$!";
    for (int i = 0; i < strlen(s); ++i) {
        if (!isdigit(s[i]) && !isalpha(s[i]) && !strchr(specialChars, s[i])) {
            return i;
        }
    }
    return -1; // All characters are valid
}

bool has_special_chars(const char* s) {
    const char* specialChars = "@#%$!";
    for (int i = 0; i < strlen(s); ++i) {
        if (strchr(specialChars, s[i])) {
            return true;
        }
    }
    return false; // No special characters
}

//####################################//

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // Check and reset limits
    if (E1 < 0 || E1 > 99) return -99;
    EXP1 = (EXP1 < EXP_MIN) ? EXP_MIN : (EXP1 > EXP_MAX) ? EXP_MAX : EXP1;
    EXP2 = (EXP2 < EXP_MIN) ? EXP_MIN : (EXP2 > EXP_MAX) ? EXP_MAX : EXP2;

    //////////////! Situation 1
    if (E1 >= 0 && E1 <= 3) {
        if (E1 == 0) EXP2 += 29;
        if (E1 == 1) EXP2 += 45;
        if (E1 == 2) EXP2 += 75;
        if (E1 == 3) EXP2 += 29 + 45 + 75;

        // Sherlock's decisions
        int D = E1 * 3 + EXP1 * 7;
        double D_alt = D;
        if (D % 2 == 0) EXP1 = customCeil(EXP1 + D_alt/200);
        else EXP1 = customCeil(EXP1 - D_alt/100);
    }
    
    //////////////! Situation 2
    double e1_alt = E1;
    if (E1 >= 4 && E1 <= 99) {
        if (E1 <= 19) EXP2 += customCeil(e1_alt/4 + 19);
        else if (E1 <= 49) EXP2 = EXP2 + customCeil((e1_alt/9 + 21));
        else if (E1 <= 65) EXP2 += customCeil(e1_alt/16 + 17);
        else if (E1 <= 79) {
            EXP2 += customCeil(e1_alt/4 + 19);
            if (EXP2 > 200) EXP2 += customCeil(e1_alt/9 + 21);
        } 
        else if (E1 <= 99) {
            EXP2 += customCeil(e1_alt/4 + 19);
            EXP2 += customCeil(e1_alt/9 + 21);
            if (EXP2 > 400) {
                EXP2 += customCeil(e1_alt/16 + 17);
                EXP2 = customCeil(EXP2 * 1.15);
            }
        }
        EXP1 -= E1;
    }

    // Check and reset limits
    EXP1 = (EXP1 < EXP_MIN) ? EXP_MIN : (EXP1 > EXP_MAX) ? EXP_MAX : EXP1;
    EXP2 = (EXP2 < EXP_MIN) ? EXP_MIN : (EXP2 > EXP_MAX) ? EXP_MAX : EXP2;

    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // Check and reset limits
    if (E2 < 0 || E2 > 99) return -99;
    HP1 = (HP1 < HP_MIN) ? HP_MIN : (HP1 > HP_MAX) ? HP_MAX : HP1;
    EXP1 = (EXP1 < EXP_MIN) ? EXP_MIN : (EXP1 > EXP_MAX) ? EXP_MAX : EXP1;
    M1 = (M1 < M_MIN) ? M_MIN : (M1 > M_MAX) ? M_MAX : M1;

    //////////////! PATH 1
    int S = closestSquare(EXP1);
    double P1 = 100;
    if (EXP1 < S) P1 = 100 * ((EXP1/S) + 80)/123;

    //////////////! PATH 2 
    double halfM1 = M1 * 0.5;
    int moneySpent = 0;
    if (E2 % 2 == 0) {
        path_2_events(HP1, EXP1, M1);
    } else {
        path_2_events_loop(HP1, EXP1, M1, halfM1, moneySpent);
    }
    HP1 = customCeil(HP1 * 0.83);
    EXP1 = customCeil(EXP1 * 1.17);
    
    // Check and reset limits
    HP1 = (HP1 < HP_MIN) ? HP_MIN : (HP1 > HP_MAX) ? HP_MAX : HP1;
    EXP1 = (EXP1 < EXP_MIN) ? EXP_MIN : (EXP1 > EXP_MAX) ? EXP_MAX : EXP1;
    M1 = (M1 < M_MIN) ? M_MIN : (M1 > M_MAX) ? M_MAX : M1;

    S = closestSquare(EXP1);
    double P2 = 100;
    if (EXP1 < S) P2 = 100 * ((EXP1/S) + 80)/123;

    //////////////! PATH 3
    int P3_array[10] = {32,47,28,79,100,50,22,83,64,11};
    int i = calculate_i(E2, P3_array);
    double P3 = P3_array[i];

    int P;
    if (P1 == P2 && P2 == P3 && P1 == 100) {
        EXP1 = customCeil(EXP1 * 0.75);
    } else {
        P = customCeil((P1 + P2 + P3) / 3);

        if (P < 50) {
        HP1 = customCeil(HP1 * 0.85);
        EXP1 = customCeil(EXP1 * 1.15);
        } else {
            HP1 = customCeil(HP1 * 0.9);
            EXP1 = customCeil(EXP1 * 1.2);
        }
    }


    // Check and reset limits
    HP1 = (HP1 < HP_MIN) ? HP_MIN : (HP1 > HP_MAX) ? HP_MAX : HP1;
    EXP1 = (EXP1 < EXP_MIN) ? EXP_MIN : (EXP1 > EXP_MAX) ? EXP_MAX : EXP1;
    M1 = (M1 < M_MIN) ? M_MIN : (M1 > M_MAX) ? M_MAX : M1;

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // Limits
    if (E3 < 0 || E3 > 99) return -99;
    HP1 = (HP1 < HP_MIN) ? HP_MIN : (HP1 > HP_MAX) ? HP_MAX : HP1;
    EXP1 = (EXP1 < EXP_MIN) ? EXP_MIN : (EXP1 > EXP_MAX) ? EXP_MAX : EXP1;
    HP2 = (HP2 < HP_MIN) ? HP_MIN : (HP2 > HP_MAX) ? HP_MAX : HP2;
    EXP2 = (EXP2 < EXP_MIN) ? EXP_MIN : (EXP2 > EXP_MAX) ? EXP_MAX : EXP2;

    // Calculate the score for each location in the chase map
    int chaseMap[ROWS][COLS];
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            // Calculate score using the given formula
            int score = ((E3 * j) + (i * 2)) * (i - j);
            // Store the score in the corresponding location of the chase map
            chaseMap[i][j] = score;
        }
    }

    // Taxi's score
    int taxiScore = chaseMap[findValue_i(chaseMap, E3)][findValue_j(chaseMap, E3)];
    // Sherlock & Watson's score
    int SherWatScore = maxDiagonalValue(chaseMap, findValue_i(chaseMap, E3), findValue_j(chaseMap, E3));
    SherWatScore = abs(SherWatScore);
    
    if (abs(taxiScore) > abs(SherWatScore)) { // Can't catch the taxi
        EXP1 = customCeil(EXP1 * 0.88);
        EXP2 = customCeil(EXP2 * 0.88);
        HP1 = customCeil(HP1 * 0.9);
        HP2 = customCeil(HP2 * 0.9);

        HP1 = (HP1 < HP_MIN) ? HP_MIN : (HP1 > HP_MAX) ? HP_MAX : HP1;
        EXP1 = (EXP1 < EXP_MIN) ? EXP_MIN : (EXP1 > EXP_MAX) ? EXP_MAX : EXP1;
        HP2 = (HP2 < HP_MIN) ? HP_MIN : (HP2 > HP_MAX) ? HP_MAX : HP2;
        EXP2 = (EXP2 < EXP_MIN) ? EXP_MIN : (EXP2 > EXP_MAX) ? EXP_MAX : EXP2;
        return taxiScore;
    } else { // Gyatt the taxi
        EXP1 = customCeil(EXP1 * 1.12);
        EXP2 = customCeil(EXP2 * 1.12);
        HP1 = customCeil(HP1 * 1.1);
        HP2 = customCeil(HP2 * 1.1);

        HP1 = (HP1 < HP_MIN) ? HP_MIN : (HP1 > HP_MAX) ? HP_MAX : HP1;
        EXP1 = (EXP1 < EXP_MIN) ? EXP_MIN : (EXP1 > EXP_MAX) ? EXP_MAX : EXP1;
        HP2 = (HP2 < HP_MIN) ? HP_MIN : (HP2 > HP_MAX) ? HP_MAX : HP2;
        EXP2 = (EXP2 < EXP_MIN) ? EXP_MIN : (EXP2 > EXP_MAX) ? EXP_MAX : EXP2;
        return SherWatScore;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {

    // cout << "s: " << s << endl;
    
    string se_str = get_se(email);
    const char* se = se_str.c_str();
    // cout << "se: " << se << endl;
    
    int sei = find_sei(s, se);
    // cout << "sei: " << sei << endl;
    
    int sci = find_sci(s);
    // cout << "sci: " << sci << endl;

    int sLength = strlen(s);
    if (sLength < 8)
        return -1; // Password too short
    if (sLength > 20)
        return -2; // Password too long

    if (sei > -1)
        return -(300 + sei); // Password contains se

    if (sci > -1)
        return -(400 + sci); // Password contains identical consecutive chars
    
    if (!has_special_chars(s))
        return -5; // Password does not contain special characters

    if (check_chars(s) != -1) 
        return check_chars(s); // Password contains invalid characters

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxCount = 0;
    int maxLength = 0;
    int correctIndex = -1;

    for (int i = 0; i < num_pwds; i++) {
        int count = 0;
        int length = strlen(arr_pwds[i]);

        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }

        if (count > maxCount || (count == maxCount && length > maxLength)) {
            maxCount = count;
            maxLength = length;
            correctIndex = i;
        }
    }

    return correctIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////