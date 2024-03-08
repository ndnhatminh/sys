#include "study_in_pink1.h"
using namespace std;
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
void limitEXP(int &EXP1, int &EXP2) {
    EXP1 = (EXP1 > 600) ? 600 : ((EXP1 < 0) ? 0 : EXP1);
    EXP2 = (EXP2 > 600) ? 600 : ((EXP2 < 0) ? 0 : EXP2);
}

void limitHP(int &HP1, int &HP2) {
    HP1 = (HP1 > 666) ? 666 : ((HP1 < 0) ? 0 : HP1);
    HP2 = (HP2 > 666) ? 666 : ((HP2 < 0) ? 0 : HP2);
}

void limitM(int &M1, int &M2) {
    M1 = (M1 > 3000) ? 3000 : ((M1 < 0) ? 0 : M1);
    M2 = (M2 > 3000) ? 3000 : ((M2 < 0) ? 0 : M2);
}

// Task 1

int firstMeet(int &exp1, int &exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0){
        return -1;
    }
    if (e1 <= 3) {
        if (e1 == 0)
            exp2 += 29;
        else if (e1 == 1)
            exp2 += 45;
        else if (e1 == 2)
            exp2 += 75;
        else
            exp2 += 149; // 29 + 45 + 75
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = static_cast<int>(ceil(exp1 + (D / 200.0) - 0.001)); // lam tron
        } else {
            exp1 = static_cast<int>(ceil(exp1 - (D / 100.0) - 0.001)); // lam tron
        }
        limitEXP(exp1, exp2);
    } 
    else if (e1 <= 99) {
        if (e1 <= 19)
            exp2 = static_cast<int>(ceil(exp2 + (e1 / 4.0 + 19) - 0.001));
        else if (e1 >= 20 && e1 <= 49)
            exp2 = static_cast<int>(ceil(exp2 + (e1 / 9.0 + 21) - 0.001));
        else if (e1 >= 50 && e1 <= 65)
            exp2 = static_cast<int>(ceil(exp2 + (e1 / 16.0 + 17) - 0.001));
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = static_cast<int>(ceil(exp2 + (e1 / 4.0 + 19) - 0.001));
            if (exp2 > 200)
                exp2 = static_cast<int>(ceil(exp2 + (e1 / 9.0 + 21) - 0.001));
        } else {
            exp2 = static_cast<int>(ceil(exp2 + (e1 / 4.0 + 19) - 0.001));
            exp2 = static_cast<int>(ceil(exp2 + (e1 / 9.0 + 21) - 0.001));
            if (exp2 > 400) {
                exp2 = static_cast<int>(ceil(exp2 + (e1 / 16.0 + 17) - 0.001));
                exp2 = static_cast<int>(ceil(exp2 * 1.15 - 0.001));
            }
        }
        exp1 -= e1;
        limitEXP(exp1, exp2); // Kiểm tra giá trị EXP
    }
    return exp1 + exp2;
}

// Task 2

int CP(int X) {
    int sqrtX = static_cast<int>(sqrt(X));
    return abs(X - sqrtX * sqrtX) < abs((sqrtX + 1) * (sqrtX + 1) - X) ? sqrtX * sqrtX : (sqrtX + 1) * (sqrtX + 1);
}
// firststreet
double street1(int exp1) {
    int S = CP(exp1);
    return exp1 >= S ? 100.0 : ((exp1 / S + 80) / 123.0) * 100;
}
// secondstreet
double street2(int &HP1, int &EXP1, int &M1, int e2) {
    double initialM = M1 * 0.5;
    while (true) {

        // event 1
        if (HP1 < 200) {
            HP1 = static_cast<int>(ceil(HP1 * 1.3));
            M1 -= 150;
        } else {
            HP1 = static_cast<int>(ceil(HP1 * 1.1));
            M1 -= 70;
        }
        limitHP(HP1, HP1);
        limitM(M1, M1);
        if ((e2 % 2 == 1 && M1 < initialM) || (e2 % 2 == 0 && M1 == 0)) {
            EXP1 = static_cast<int>(ceil(EXP1 * 1.17));
            HP1 = static_cast<int>(ceil(HP1 - HP1 * 0.17));
            limitEXP(EXP1, EXP1);
            limitHP(HP1, HP1);
            break;
        }

        // event 2
        if (EXP1 < 400) M1 -= 200;
        else M1 -= 120;
        EXP1 = static_cast<int>(ceil(EXP1 * 1.13));
        limitEXP(EXP1, EXP1);
        limitM(M1, M1);
        if ((e2 % 2 == 1 && M1 < initialM) || (e2 % 2 == 0 && M1 == 0)) {
            EXP1 = static_cast<int>(ceil(EXP1 * 1.17));
            HP1 = static_cast<int>(ceil(HP1 - HP1 * 0.17));
            limitEXP(EXP1, EXP1);
            limitHP(HP1, HP1);
            break;
        }
        
        // event 3
        if (EXP1 < 300) M1 -= 100;
        else M1 -= 120;
        EXP1 = static_cast<int>(ceil(EXP1 * 0.9));
        limitEXP(EXP1, EXP1);
        limitM(M1, M1);
        if ((e2 % 2 == 1 && M1 <= initialM) || e2 % 2 == 0) {
            EXP1 = static_cast<int>(ceil(EXP1 * 1.17));
            HP1 = static_cast<int>(ceil(HP1 - HP1 * 0.17));
            limitEXP(EXP1, EXP1);
            limitHP(HP1, HP1);
            break;
        }
    }
    return street1(EXP1);
}

double street3(int e2) {
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    return P[e2 < 10 ? e2 : (e2 / 10 + e2 % 10) % 10];
}
int traceLuggage(int &HP1, int &EXP1, int &M1, int e2) {
    if (e2 < 0 || e2 > 99) return -99;
    double S1 = street1(EXP1);
    double S2 = street2(HP1, EXP1, M1, e2);
    double S3 = street3(e2);
    if (S1 == 100 && S2 == 100 && S3 == 100) EXP1 = static_cast<int>(ceil(EXP1 * 0.75));
    else {
        double V = (S1 + S2 + S3) / 3;
        HP1 = static_cast<int>(ceil(HP1 * (V < 50 ? 0.85 : 0.9)));
        EXP1 = static_cast<int>(ceil(EXP1 * (V < 50 ? 1.15 : 1.2)));
    }
    limitEXP(EXP1, EXP1);
    limitHP(HP1, HP1);
    return HP1 + EXP1 + M1;
}

// Task 3

int calculateTaxiScore(int E3, int i, int j) {
    return ((E3 * j) + (i * 2)) * (i - j);
}

int calculateSherlockScore(const int TaxiMatrix[][10], int i, int j) {
    int leftDiagonalMax = TaxiMatrix[i][j];
    for (int k = 0; k < min(i, j); k++) {
        leftDiagonalMax = max(leftDiagonalMax, TaxiMatrix[i - k][j - k]);
    }

    int rightDiagonalMax = TaxiMatrix[i][j];
    for (int k = 0; k < min(10 - i, j); k++) {
        rightDiagonalMax = max(rightDiagonalMax, TaxiMatrix[i + k][j - k]);
    }

    return abs(max(leftDiagonalMax, rightDiagonalMax));
}

void EXPandHP(int &EXP1, int &HP1, int &EXP2, int &HP2, double EXP_factor, double HP_factor) {
    EXP1 = static_cast<int>(ceil(EXP1 * EXP_factor - 0.001));
    HP1 = static_cast<int>(ceil(HP1 * HP_factor - 0.001));
    EXP2 = static_cast<int>(ceil(EXP2 * EXP_factor - 0.001));
    HP2 = static_cast<int>(ceil(HP2 * HP_factor - 0.001));
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    if (E3 < 0 || E3 > 99)
        return -99;

    int TaxiMatrix[10][10] = {0};
    int SherlockMatrix[10][10] = {0};

    // Calculate scores for taxi
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            TaxiMatrix[i][j] = calculateTaxiScore(E3, i, j);
        }
    }

    // Calculate scores for Sherlock
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            SherlockMatrix[i][j] = calculateSherlockScore(TaxiMatrix, i, j);
        }
    }

    // Find meeting position
    int I = 0, J = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (TaxiMatrix[i][j] > E3 * 2)
                I++;
            if (TaxiMatrix[i][j] < -E3)
                J++;
        }
    }
    
    while (I >= 10 || J >= 10) {
        if (I >= 10) {
            I = I / 10 + I % 10;
        }
        if (J >= 10) {
            J = J / 10 + J % 10;
        }
    }

    // Calculate final score
    int MaxScore;
    if (abs(TaxiMatrix[I][J]) > SherlockMatrix[I][J]) {
        // Taxi escapes
        EXPandHP(EXP1, HP1, EXP2, HP2, 0.88, 0.9);
        MaxScore = TaxiMatrix[I][J];
    } else {
        // Sherlock and Watson catch the taxi
        EXPandHP(EXP1, HP1, EXP2, HP2, 1.12, 1.1);
        MaxScore = SherlockMatrix[I][J];
    }

    limitEXP(EXP1, EXP2); // Check EXP values
    limitHP(HP1, HP2);    // Check HP values
    return MaxScore;
}

// Task 4

int checkPassword(const char *s, const char *email) {
    string password(s);
    string userEmail(email);
    string userPrefix = userEmail.substr(0, userEmail.find('@'));

    // Check the length
    int passLength = password.length();
    if (passLength < 8) return -1;
    if (passLength > 20) return -2;

    // Check for string 'user Prefix'
    size_t prefixPos = password.find(userPrefix);
    if (prefixPos != string::npos) return -(300 + static_cast<int>(prefixPos));

    // Checks for 2 consecutive characters
    for (int i = 0; i < passLength - 2; ++i) {
        if (password[i] == password[i + 1] && password[i + 1] == password[i + 2]) return -(400 + i);
    }

    // Check for special characters
    string specialChars = "@#%$!";
    bool containsSpecialChar = false;
    for (char c : password) {
        if (specialChars.find(c) != string::npos) {
            containsSpecialChar = true;
            break;
        }
    }
    if (!containsSpecialChar) return -5;

    // Valid or not
    for (char c : password) {
        if (!isdigit(c) && !isalpha(c) && specialChars.find(c) == string::npos) return password.find(c);
    }
    // If password is valid, return -10
    return -10;
}

// Task 5

int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    int maxFre = 0, maxLength = 0, mPop = 0;

    for (int i = 0; i < num_pwds; ++i) {
        int count = 0, length = strlen(arr_pwds[i]);

        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }

        if (count > maxFre || (count == maxFre && length > maxLength)) {
            maxFre = count;
            maxLength = length;
            mPop = i;
        }
    }

    return mPop;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////