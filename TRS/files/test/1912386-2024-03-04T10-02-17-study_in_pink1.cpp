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

// Task 1
int firstMeet(int &exp1, int &exp2, int e1) {
    // Adjustments for E1 within [0, 3]
    if (e1 >= 0 && e1 <= 3) {
    if (e1 == 0) exp2 += 29;
    else if (e1 == 1) exp2 += 45;
    else if (e1 == 2) exp2 += 75;
    else if (e1 == 3) exp2 += 29 + 45 + 75; // Adding all observations together

    // Calculate decision value D
    int D = e1 * 3 + exp1 * 7;
    // Adjust EXP1 based on D
    if (D % 2 == 0) exp1 = ceil (exp1+(D / 200.0));
    else exp1 = ceil(exp1-(D / 100.0));
    // Ensure EXP2 does not exceed 600
    exp2 = min(exp2, 600);
    exp1 = max(0, min(exp1, 600));
    return exp1 + exp2;
    }
    // Handling E1 in the range [4, 99]
    double additionalEXP = 0;
    if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            additionalEXP = ceil(e1 / 4.0 + 19);
        } else if (e1 >= 20 && e1 <= 49) {
            additionalEXP = ceil(e1 / 9.0 + 21);
        } else if (e1 >= 50 && e1 <= 65) {
            additionalEXP = ceil(e1 / 16.0 + 17);
        }

        // Update EXP2 based on Sherlock's initial observations
        exp2 += additionalEXP;
   
            if (e1 >= 66 && e1 <= 79) {
                // Repeating the logic for [20, 49] if EXP2 > 200
                additionalEXP = ceil(e1 / 4.0 + 19);
                exp2 += additionalEXP;
                if (exp2 > 200) {
                    additionalEXP = ceil(e1 / 9.0 + 21);
                    exp2 += additionalEXP;
                }
            }
            if (e1 >= 80) {
                // Adding logic for [50, 65] if EXP2 > 400
                additionalEXP = ceil(e1 / 4.0 + 19) + ceil(e1 / 9.0 + 21);; 
                exp2 += additionalEXP;
                if (exp2 > 400) {
                    additionalEXP = ceil(e1 / 16.0 + 17);
                    exp2 += additionalEXP;
                }
            }
            // Increase EXP2 by 15% if all information is explained and corrects Sherlock
            if (e1 >= 80 && exp2 > 400) exp2 = ceil(exp2*1.15);


        // Ensure EXP2 does not exceed 600 after adjustments
        exp2 = min(exp2, 600);

        // Reduce Sherlock's EXP by E1 if corrected by Watson
        exp1 -= e1;
    exp1 = max(0, min(exp1, 600));
    return exp1 + exp2;
    }
    
else return -99;
    // Ensure EXP1 is within the valid range [0, 600]
    
}

//task 2
int nearestPerfectSquare(int EXP1) {
    int root = sqrt(EXP1);
    int lowerSquare = root * root;
    int upperSquare = (root + 1) * (root + 1);
    return (EXP1 - lowerSquare <= upperSquare - EXP1) ? lowerSquare : upperSquare;
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
    // Road 01 Probability
    int S = nearestPerfectSquare(EXP1);
    double P1 = EXP1 >= S ? 1.0 : (double)(EXP1/S + 80) / 123.0;
    // Road 02 Adjustments and Calculations
    double initialM1 = M1;
    double totalSpent = 0;

do {
    double budgetBeforeEvent = M1;

    // Adjustments for HP1 and M1 based on HP
    if (HP1 < 200) {
        HP1 = ceil(HP1 * 1.3);
        M1 -= 150;
    } else {
        HP1 = ceil(HP1 * 1.1);
        M1 -= 70;
    }
    // Break if spent over 50% of initialM1
    if (M1 <= initialM1 - (initialM1 * 0.5)) break;

    // Taxi or carriage cost adjustment based on EXP1
    M1 -= (EXP1 < 400) ? 200 : 120;
    EXP1 = ceil(EXP1 * 1.13);

    // Break if spent over 50% of initialM1
    if (M1 <= initialM1 - (initialM1 * 0.5)) break;

    // Helping the homeless person based on EXP1
    M1 -= (EXP1 < 300) ? 100 : 120;
    EXP1 = ceil(EXP1 * 0.9);
    // Break if spent over 50% of initialM1
    if (M1 <= initialM1 - (initialM1 * 0.5)) break;

} while (E2 % 2 != 0); // Continue only if E2 is odd

// Adjustments after the loop
if (M1 <= initialM1 * 0.5 || E2 % 2 == 0) {
    HP1 = ceil(HP1 * 0.83);
    EXP1 = ceil(EXP1 * 1.17);
}


    // Recalculate S for P2 after Road 02 events
    S = nearestPerfectSquare(EXP1);
    double P2 = EXP1 >= S ? 1.0 : (double)(EXP1/S + 80) / 123.0;
    // Road 03 Probability Calculation
    double probabilities[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int index = E2 < 10 ? E2 : (E2 / 10 + E2 % 10) % 10;
    double P3 = (probabilities[index]) / 100.0;
    // Final Adjustments Based on Probabilities
    double averageP = (P1 + P2 + P3) / 3.0;
    if (averageP == 1.0) {
        EXP1 = ceil(EXP1*0.75);
    } else if (averageP < 0.5) {
        HP1 = ceil(HP1*0.85);
        EXP1 = ceil(EXP1 *1.15);
    } else {
        HP1 = ceil(HP1*0.9);
        EXP1 = ceil(EXP1*1.2); // Cap EXP1 at 600
    }

    // Ensure HP1, EXP1, and M1 are within valid ranges
    HP1 = max(HP1, 0);
    EXP1 = min(EXP1, 600);
    M1 = max(M1, 0); // Adjusted to ensure M1 is not negative

    return HP1 + EXP1 + M1; // Return the sum of HP1, EXP1, and M1
}
// Task 3
#include <iostream>
#include <cmath>
#include <cstring>
#include <climits>

// Helper function to simplify to one-digit
int simplifyToOneDigit(int number) {
    while (number >= 10) {
        number = number / 10 + number % 10;
    }
    return number;
}

// Function to initialize and calculate the taxi's grade matrix
void initializeAndCalculateTaxiGrade(int taxiGrade[10][10], int E3) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxiGrade[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
}

// Function to calculate grades for Sherlock and Watson based on taxi's grade matrix
void calculateGradesSW(int SWGrade[10][10], int taxiGrade[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            SWGrade[i][j] = 0; // Initialize SWGrade to 0
            int maxGrade = INT_MIN; // To find the max grade in the taxi's path for comparison
            
            // Calculate based on column movement for Sherlock and Watson
            for (int k = 0; k < 10; k++) { // Traverse through all rows for a given column
                // Check left diagonal
                if (j - k >= 0 && i - k >= 0) {
                    maxGrade = max(maxGrade, taxiGrade[i-k][j-k]);
                }
                // Check right diagonal
                if (j + k < 10 && i - k >= 0) {
                    maxGrade = max(maxGrade, taxiGrade[i-k][j+k]);
                }
            }
            
            SWGrade[i][j] = maxGrade; // Assign the maximum grade found to SWGrade
        }
    }
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    int taxiGrade[10][10] = {0};
    int SWGrade[10][10] = {0};

    initializeAndCalculateTaxiGrade(taxiGrade, E3);
    calculateGradesSW(SWGrade, taxiGrade);

    int positiveCount = 0, negativeCount = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (taxiGrade[i][j] > (E3 * 2)) ++positiveCount;
            if (taxiGrade[i][j] < -E3) ++negativeCount;
        }
    }

    int meetingI = simplifyToOneDigit(positiveCount);
    int meetingJ = simplifyToOneDigit(negativeCount);
    // Compare taxi's grade at meeting point to Sherlock & Watson's grade
    bool caughtTaxi = abs(taxiGrade[meetingI][meetingJ]) <= SWGrade[meetingI][meetingJ];
    if (E3 >= 0 && E3 <= 99) {
    if (caughtTaxi) {
        HP1 = ceil(HP1*1.10); EXP1 = ceil(EXP1*1.12);
        HP2 = ceil(HP2*1.10); EXP2 = ceil(EXP2*1.12);

    } else {
        HP1 = ceil(HP1*0.90); EXP1 = ceil (EXP1*0.88);
        HP2 = ceil(HP2*0.90); EXP2 = ceil (EXP2*0.88);
    }

    // Ensure HP and EXP are within valid ranges after modification
    HP1 = max(0, HP1); EXP1 = min(600, EXP1);
    HP2 = max(0, HP2); EXP2 = min(600, EXP2);
    // Return the greater grade between taxi and Sherlock & Watson
    return caughtTaxi ? SWGrade[meetingI][meetingJ] : -abs(taxiGrade[meetingI][meetingJ]);}
    return -99;
}


// Task 4
int checkPassword(const char* s, const char* email) {
    // Extract username from email
    const char* atSymbol = strchr(email, '@');
    int usernameLength = atSymbol - email;
    char se[101]; // Assuming email length <= 100
    strncpy(se, email, usernameLength);
    se[usernameLength] = '\0';
    
    // Validate password length
    int length = strlen(s);
    if (length < 8) return -1;
    if (length > 20) return -2;
    
    // Initialize validation flags
    bool containsSpecial = false;
    bool containsSe = strstr(s, se) != nullptr;
    int consecutive = 1;
    int position = -1; // For tracking position of consecutive chars

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        // Check for special characters
        if (strchr("@#%$!", c)) containsSpecial = true;
        else {
    
        // Validate character is alphanumeric or special
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || strchr("@#%$!", c))) {
            if (!containsSpecial) return -5;
            return i ; // Position of first invalid character
        }


        // Check for consecutive identical characters
        if (i > 0 && s[i] == s[i - 1]) {
            consecutive++;
            if (consecutive > 2 && position == -1) position = i - 1;
        } else {
            consecutive = 1;
        }
        }
    }
    
    // Evaluate and return based on validation flags
    if (containsSe) return -(300 + (strstr(s, se) - s));
    if (position != -1) return -(400 + position);
    if (!containsSpecial) return -5;
        
    return -10; // All conditions met for a valid password
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int maxFrequency = 0;
    string maxPwd;
    int maxPwdIndex = -1;
    
    for (int i = 0; i < num_pwds; ++i) {
        string currentPwd(arr_pwds[i]);
        int currentFrequency = 1;
        
        // Check the frequency of the current password in the rest of the array
        for (int j = i + 1; j < num_pwds; ++j) {
            if (currentPwd == arr_pwds[j]) {
                currentFrequency++;
            }
        }
        
        // Update the max frequency and max password if conditions are met
        if ((currentFrequency > maxFrequency) ||
            (currentFrequency == maxFrequency && currentPwd.length() > maxPwd.length())) {
            maxFrequency = currentFrequency;
            maxPwd = currentPwd;
            maxPwdIndex = i;
        }
    }
    
    return maxPwdIndex;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////