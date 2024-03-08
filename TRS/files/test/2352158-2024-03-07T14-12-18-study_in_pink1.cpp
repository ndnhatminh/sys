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

// Helper function to round up if the value is a fraction
double roundUpIfFraction(double value) {
    double intPart;
    double fracPart = modf(value, &intPart);

    if (fabs(fracPart) > 0.00001) { // Check if the fractional part is not .000
        return ceil(value);
    } else {
        return value;
    }
}

// Ensure values are within limits
void ensureHP(int & HP) {
    HP = (HP < 0) ? 0 : (HP > 666) ? 666 : HP;
}
void ensureEXP(int & EXP) {
    EXP = (EXP < 0) ? 0 : (EXP > 600) ? 600 : EXP;
}
void ensureM(int & M) {
    M = (M < 0) ? 0 : (M > 3000) ? 3000 : M;
}
void ensuretempHP(double & tempHP) {
    tempHP = (tempHP < 0) ? 0 : (tempHP > 666) ? 666 : tempHP;
}
void ensuretempEXP(double & tempEXP) {
    tempEXP = (tempEXP < 0) ? 0 : (tempEXP > 600) ? 600 : tempEXP;
}


// TASK 1
void handleCase1(int &exp1, int &exp2, int e1) {
    if (e1 == 0) exp2 += 29;
    else if (e1 == 1) exp2 += 45;
    else if (e1 == 2) exp2 += 75;
    else if (e1 == 3) exp2 += (29 + 45 + 75);

    int D = e1 * 3 + exp1 * 7;
    double tempExp1 = exp1;
    if (D % 2 == 0) {
        tempExp1 = roundUpIfFraction(tempExp1 + (D / 200.0)); // right choice
    } else {
        tempExp1 = roundUpIfFraction(tempExp1 - (D / 100.0)); // wrong choice
    }
    exp1 = static_cast<int>(tempExp1);
 
    ensureEXP(exp1);
    ensureEXP(exp2);
}

void handleCase2(int &exp1, int &exp2, int e1) {
    double tempExp2 = exp2; 
    double tempE1 = e1;

    if (e1 >= 4  && e1 <= 19) {
        tempExp2 = roundUpIfFraction(tempExp2 + tempE1/4.0 + 19);
    }
    else if (e1 >= 20 && e1 <= 49) {
        tempExp2 = roundUpIfFraction(tempExp2 + tempE1/9.0 + 21);
    }
    else if (e1 >= 50 && e1 <= 65) {
        tempExp2 = roundUpIfFraction(tempExp2 + tempE1/16.0 + 17);
    }
    else if (e1 >= 66 && e1 <= 79) {
        tempExp2 = roundUpIfFraction(tempExp2 + tempE1/4.0 + 19);
        if (tempExp2 > 200.0) {
            tempExp2 = roundUpIfFraction(tempExp2 + tempE1/9.0 + 21);
        }
    }
    else if (e1 >= 80 && e1 <= 99) {
        tempExp2 = roundUpIfFraction(tempExp2 + tempE1/4.0 + 19);
        tempExp2 = roundUpIfFraction(tempExp2 + tempE1/9.0 + 21);
        if (tempExp2 > 400.0) {
            tempExp2 = roundUpIfFraction(tempExp2 + tempE1/16.0 + 17);
            tempExp2 = roundUpIfFraction(tempExp2 * 1.15); // Sherlock explains all the 3 information to Watson
        }
    }
    exp1 -= e1;
    exp2 = (tempExp2);

    ensureEXP(exp1);
    ensureEXP(exp2);
}

/////- MAIN FUNCTION -///////
int firstMeet(int &exp1, int &exp2, int e1) {
    if (e1 < 0 || e1 > 99) {
        return -99;
    }
    ensureEXP(exp1);

    ensureEXP(exp2);
    
    if (e1>=0 && e1<=3) {
        handleCase1(exp1, exp2, e1);
    } else {
        handleCase2(exp1, exp2, e1);
    }
    return exp1 + exp2;
}


// TASK 2

// Road 1
double calcP(double EXP) {
    int sqrtEXP = static_cast<int>(sqrt(EXP));
    int S = (EXP - (sqrtEXP * sqrtEXP) <= (sqrtEXP + 1)* (sqrtEXP + 1) - EXP) ? sqrtEXP * sqrtEXP : (sqrtEXP + 1) * (sqrtEXP + 1);
    return (EXP >= S) ? 1.0 : (EXP / S + 80) / 123;
}

// Road 2

void updateValue(double &value, double multiplier, int &M1, int cost) {
    if (M1 >= cost) {
        M1 -= cost;
    } else {
        cost -= M1;
        M1 = 0;
        
    }
    value = roundUpIfFraction(value * multiplier);
}

double road2(int &HP1, int &EXP1, int &M1, int E2) { 
    int initialM1 = M1;
    double tempEXP1 = EXP1;
    double tempHP1 = HP1;
    int maxIterations = 1000;
    int iteration = 0;
    while (iteration < maxIterations) {
        // Buying Supplies
        if (tempHP1 < 200) {
            updateValue(tempHP1, 1.3, M1, 150);
        } else {
            updateValue(tempHP1, 1.1, M1, 70);
        }
        ensuretempHP(tempHP1);
        if (M1 < initialM1 / 2 && E2 % 2 != 0 || M1 == 0) break;

        // Transportation
        if (tempEXP1 < 400) {
            updateValue(tempEXP1, 1.13, M1, 200);
        } else {
            updateValue(tempEXP1, 1.13, M1, 120);
        }
        ensuretempEXP(tempEXP1);
        if (M1 < initialM1 / 2 && E2 % 2 != 0 || M1 == 0) break;


        // Encounter with Homeless Person
        if (tempEXP1 < 300) {
            updateValue(tempEXP1, 0.9, M1, 100);
        } else {
            updateValue(tempEXP1, 0.9, M1, 120);
        }
        ensuretempEXP(tempEXP1);
        if (M1 < initialM1 / 2 && E2 % 2 != 0 || M1 == 0) break;

        // If E2 is even, break the loop
        if (E2 % 2 == 0) break;

        iteration++;
    }

    // Decrease HP1 by 17% and increase EXP1 by 17%
    tempHP1 = roundUpIfFraction(tempHP1 * 0.83);
    tempEXP1 = roundUpIfFraction(tempEXP1 * 1.17);
    ensuretempHP(tempHP1);
    ensuretempEXP(tempEXP1);

    cout << "HP1: " << tempHP1 << ", EXP1: " << tempEXP1 << ", M1: " << M1 << endl;
    // Calculate P2 as on Road 01
    double P2 = calcP(tempEXP1);

    // Update HP1 and EXP1
    EXP1 = tempEXP1;
    HP1 = tempHP1;

    ensureHP(HP1);
    ensureEXP(EXP1);
    ensureM(M1);

    return P2;
}


// Road 3
double road3(int E2) {
    static const int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int sum = 0;
    int tempE2 = E2;
    while (tempE2 > 0) {
        sum += tempE2 % 10;
        tempE2 /= 10;
    }
    int i = (E2 < 10) ? E2 : sum % 10;
    return P[i] / 100.0;
}

/////- MAIN FUNCTION -///////
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    if (E2 < 0 || E2 > 99) {
        return -99;
    }

    ensureHP(HP1);
    ensureEXP(EXP1);
    ensureM(M1);

    double P1 = calcP(EXP1);
    double P2 = road2(HP1, EXP1, M1, E2);
    double P3 = road3(E2);

    cout << "P1: " << P1 << ", P2: " << P2 << ", P3: " << P3 << endl;

    
    double tempHP1 = HP1;
    double tempEXP1 = EXP1;

    if (P1 == 1 && P2 == 1 && P3 == 1) 
        tempEXP1 = ceil(tempEXP1 * 0.75); // EXP reduced by 25%
    else {
        double averageP = (P1 + P2 + P3) / 3.0;
        tempHP1 = ceil(tempHP1 * (averageP < 0.50 ? 0.85 : 0.90)); // HP reduced by 15% or 10%
        tempEXP1 = ceil(tempEXP1 * (averageP < 0.50 ? 1.15 : 1.20)); // EXP increased by 15% or 20%
    }
    ensuretempHP(tempHP1);
    ensuretempEXP(tempEXP1);
    // Update HP1 and EXP1
    EXP1 = tempEXP1;
    HP1 = tempHP1;


    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

    if (E3 < 0 || E3 > 99) {
        return -99;
    }

    int taxiScores[10][10];
    int SherWatScores[10][10];

    //  Calculate taxiScores
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxiScores[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    //  Calculate Sherlock and Watson scores
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int maxScoreLeftDiagonal = taxiScores[i][j];
            int maxScoreRightDiagonal = taxiScores[j][i];
            for (int k = 0; k < 10; k++) {
                if (i + k < 10 && j + k < 10) {
                    maxScoreLeftDiagonal = max(maxScoreLeftDiagonal, taxiScores[i + k][j + k]);
                }
                if (i + k < 10 && j - k >= 0) {
                    maxScoreRightDiagonal = max(maxScoreRightDiagonal, taxiScores[i + k][j - k]);
                }
            }
            SherWatScores[i][j] = max(maxScoreLeftDiagonal, maxScoreRightDiagonal);
            if (SherWatScores[i][j] < 0) SherWatScores[i][j] = 0;
        }
    }

    // Calculate meeting point
    int i = 0, j = 0;
    for (int k = 0; k < 10; k++) {
        for (int l = 0; l < 10; l++) {
            if (taxiScores[k][l] > E3 * 2) i++;
            if (taxiScores[k][l] < -E3) j++;
        }
    }

    while (i > 9) {
        i = i / 10 + i % 10;
    }
    while (j > 9) {
        j = j / 10 + j % 10;
    }

    i %= 10;
    j %= 10;

    // Calculate final scores
    int taxiScore = taxiScores[i][j];
    int SherWatScore = SherWatScores[i][j];
    int finalScore = (abs(taxiScore) > abs(SherWatScore)) ? taxiScore : SherWatScore;

    // Update HP and EXP
    double tempHP1 = HP1;
    double tempEXP1 = EXP1;
    double tempHP2 = HP2;
    double tempEXP2 = EXP2;

    // If they catch up, each person's EXP and HP are increased by 12% and 10% respectively. Otherwise, they will be deducted by 12% and 10% respectively.
    double epsilon = 0.00001;

    if (abs(taxiScore) <= abs(SherWatScore)) {
        tempEXP1 = roundUpIfFraction(tempEXP1 * 1.12);
        tempHP1 = roundUpIfFraction(tempHP1 * 1.10);
        tempEXP2 = roundUpIfFraction(tempEXP2 * 1.12);
        tempHP2 = roundUpIfFraction(tempHP2 * 1.10);
    } else {
        tempEXP1 = roundUpIfFraction(tempEXP1 * 0.88);
        tempHP1 = roundUpIfFraction(tempHP1 * 0.90);
        tempEXP2 = roundUpIfFraction(tempEXP2 * 0.88);
        tempHP2 = roundUpIfFraction(tempHP2 * 0.90);
    }

    EXP1 = tempEXP1;
    HP1 = tempHP1;
    EXP2 = tempEXP2;
    HP2 = tempHP2;

    // Ensure EXP1 are within [0, 600]; HP1 are within [0, 666]; M1 are within [0, 3000]
    ensureEXP(EXP1);
    ensureHP(HP1);
    ensureEXP(EXP2);
    ensureHP(HP2);

    return finalScore;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string password(s);
    string se = string(email).substr(0, string(email).find('@'));
    string specialChars = "@#%$!";
    int consecutiveCharCount = 1;
    char lastChar = '\0';
    bool hasSpecialChar = false;

    // Check if password has length between 8 and 20
    if (password.length() < 8) return -1;
    if (password.length() > 20) return -2;

    // Check if password contains email
    if (password.find(se) != string::npos) return -(300 + password.find(se));

    for (int i = 0; i < password.length(); i++) {
        char c = password[i];
        
        // Check if password has consecutive characters
        if (c == lastChar) {
            consecutiveCharCount++;
            if (consecutiveCharCount > 2) return -(400 + i - 2);
        } else consecutiveCharCount = 1;

        lastChar = c;

        // Check if password contains special characters
        if (specialChars.find(c) != string::npos) hasSpecialChar = true;
    }

    // Check if password does not contain special characters
    if (!hasSpecialChar) return -5;

    for (int i = 0; i < password.length(); i++) {
        char c = password[i];

        // Check if password contain non-listed characters
        if (!isdigit(c) && !isalpha(c) && specialChars.find(c) == string::npos) {
            return i;
        }
    }

    // If password is valid
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxCount = 0;
    int maxLength = 0;
    int correctPasswordIndex = -1;

    for (int i = 0; i < num_pwds; i++) {
        int count = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }
        int length = strlen(arr_pwds[i]);
        if (count > maxCount || (count == maxCount && length > maxLength)) {
            maxCount = count;
            maxLength = length;
            correctPasswordIndex = i;
        }
    }

    return correctPasswordIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
