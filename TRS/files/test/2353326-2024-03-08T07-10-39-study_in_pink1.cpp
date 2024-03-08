#include "study_in_pink1.h"
#include <vector>
#include <iostream>
#include <map>
#include <string>
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
int HPlimit(int HP){
    if(HP < 0) HP = 0;
    if(HP > 666) HP = 666;
    return HP;
}

int EXPlimit(int EXP){
    if(EXP < 0) EXP = 0;
    if(EXP > 600) EXP = 600;
    return EXP;
}

int theM(int M){
    if(M < 0) M = 0;
    if(M > 3000) M = 3000;
    return M;
}
int theE(int e){
	if(e < 0 || e> 99) return -99;
	else return e;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1) {
    e1 = theE(e1);
    if (e1 >= 0 && e1 <= 3) {
        static const int ExpValues[4] = {29, 45, 75, 149}; // 149 is the sum of 29, 45, and 75
        exp2 += ExpValues[e1];

        int Delta = e1 * 3 + exp1 * 7;
        exp1 += (Delta % 2 == 0) ? ((Delta % 200 == 0) ? Delta / 200 : Delta / 200 + 1) : -Delta / 100;
    }

    if (e1 >= 4 && e1 <= 99) {
        bool Maxed = false;
        if (e1 <= 19) {
            exp2 += (e1 % 4 == 0) ? e1 / 4 + 19 : e1 / 4 + 20;
        } else if (e1 <= 49) {
            exp2 += (e1 % 9 == 0) ? e1 / 9 + 21 : e1 / 9 + 22;
        } else if (e1 <= 65) {
            exp2 += (e1 % 16 == 0) ? e1 / 16 + 17 : e1 / 16 + 18;
        } else if (e1 <= 79) {
            exp2 += (e1 % 4 == 0) ? e1 / 4 + 19 : e1 / 4 + 20;
            if (exp2 > 200) {
                exp2 += (e1 % 9 == 0) ? e1 / 9 + 21 : e1 / 9 + 22;
            }
        } else if (e1 <= 99) {
            exp2 += (e1 % 4 == 0) ? e1 / 4 + 19 : e1 / 4 + 20;
            exp2 += (e1 % 9 == 0) ? e1 / 9 + 21 : e1 / 9 + 22;
            if (exp2 > 400) {
                exp2 += (e1 % 16 == 0) ? e1 / 16 + 17 : e1 / 16 + 18;
                Maxed = true;
            }
        }

        if (Maxed) {
            exp2 = exp2 * 2 - static_cast<int>(exp2 * 0.85);
        }
        exp1 -= e1;
    }

    exp1 = EXPlimit(exp1);
    exp2 = EXPlimit(exp2);
    return exp1 + exp2;
}
//----------------------------------------------------------------//

double xs(int EXP1) {
    double result;
    int nearestSquare = static_cast<int>(sqrt(EXP1));
    bool isCloserToLowerSquare = (EXP1 - pow(nearestSquare, 2)) < (pow(nearestSquare + 1, 2) - EXP1);

    result = isCloserToLowerSquare ? 1.0 : (static_cast<double>(EXP1) / pow(nearestSquare + 1, 2) + 80) / 123;

    return result;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    E2 = theE(E2);
    // road 1
    double p1 = xs(EXP1);
    cout << p1 << endl << endl;

    // road 2
    double p2;
    int charge = 0;
    int limit = (E2 % 2 == 1) ? (M1 + 1) / 2 : INT_MAX;

    for(int i = 0; HP1 < 200 && charge <= limit; i = (i + 1) % 2) {
        int deltaHP = (HP1 < 200) ? 150 : 70;
        int deltaM = (EXP1 < 400) ? 200 : 120;
        int deltaEXP = (EXP1 < 300) ? 100 : 120;

        HP1 = HPlimit(HP1 * 2 - HP1 * ((i == 0) ? 0.7 : 0.9));
        M1 = theM(M1 - deltaHP);
        charge += deltaHP;
        if(charge > limit) break;

        M1 = theM(M1 - deltaM);
        charge += deltaM;
        EXP1 = EXPlimit(EXP1 * 2 - EXP1 * ((i == 0) ? 0.87 : 0.1));
        cout << HP1 << " " << M1 << " " << EXP1 << endl;
    }

    // Adjustments after the loop
    HP1 = HPlimit(HP1 - HP1 * 0.17);
    EXP1 = EXPlimit(EXP1 * 2 - EXP1 * 0.83);
    cout << HP1 << " " << M1 << " " << EXP1 << endl;

    // road 3
    double p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int idx = (E2 / 10 + E2 % 10) % 10;
    double p3 = p[idx] / 100;
    cout << idx << " " << p3 << endl;

    // Final decision
    double average = (p1 + p2 + p3) / 3;
    if(p1 == 1 && p2 == 1 && p3 == 1) {
        EXP1 -= EXP1 * 0.25;
    } else if(average < 0.5) {
        HP1 -= HP1 * 0.15;
        EXP1 = EXPlimit(EXP1 * 2 - EXP1 * 0.85);
    } else {
        HP1 -= HP1 * 0.1;
        EXP1 = EXPlimit(EXP1 * 2 - EXP1 * 0.8);
    }
    return HP1 + EXP1 + M1;
}
//----------------------------------------------------------------//

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    E3 = theE(E3);
    int grid[10][10];
    int deltaI = 0, deltaJ = 0;

    // Populate the grid and calculate deltas
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            grid[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (grid[i][j] > E3 * 2) ++deltaI;
            if (grid[i][j] < E3 * (-1)) ++deltaJ;
        }
    }

    // Normalize deltas
    while (deltaI > 9) deltaI = (deltaI % 10) + (deltaI / 10);
    while (deltaJ > 9) deltaJ = (deltaJ % 10) + (deltaJ / 10);

    int taxiValue = grid[deltaI][deltaJ], sherlockValue = grid[deltaI][deltaJ];

    // Find Sherlock's highest value on diagonals
    for (int i = 0; i < 10; ++i) {
        int leftDiagonal = i + (deltaJ - deltaI);
        int rightDiagonal = deltaJ + (deltaI - i);

        if (leftDiagonal >= 0 && leftDiagonal < 10) {
            sherlockValue = std::max(sherlockValue, grid[i][leftDiagonal]);
        }
        if (rightDiagonal >= 0 && rightDiagonal < 10) {
            sherlockValue = std::max(sherlockValue, grid[i][rightDiagonal]);
        }
    }

    // Apply effects based on the higher absolute value
    if (std::abs(taxiValue) > std::abs(sherlockValue)) {
        HP1 = HPlimit(HP1 - static_cast<int>(HP1 * 0.1));
        HP2 = HPlimit(HP2 - static_cast<int>(HP2 * 0.1));
        EXP1 = EXPlimit(EXP1 - static_cast<int>(EXP1 * 0.12));
        EXP2 = EXPlimit(EXP2 - static_cast<int>(EXP2 * 0.12));
        return taxiValue;
    } else {
        HP1 = HPlimit(HP1 * 2 - static_cast<int>(HP1 * 0.9));
        HP2 = HPlimit(HP2 * 2 - static_cast<int>(HP2 * 0.9));
        EXP1 = EXPlimit(EXP1 * 2 - static_cast<int>(EXP1 * 0.88));
        EXP2 = EXPlimit(EXP2 * 2 - static_cast<int>(EXP2 * 0.88));
        return sherlockValue;
    }
}
//----------------------------------------------------------------//

bool checkCharacter(char c) {
    // Check if character is alphanumeric
    if (isalnum(c)) return true;

    // Check if character is one of the special symbols
    switch (c) {
        case '@':
        case '#':
        case '%':
        case '$':
        case '!':
            return true;
        default:
            return false;
    }
}
// Task 4
int checkPassword(const char * s, const char * email) {
    int length = strlen(s);
    if (length < 8) return -1; // Password too short
    if (length > 20) return -2; // Password too long

    bool hasSpecialChar = false;
    std::string emailPrefix;
    std::string password(s); // Directly initialize with the C-string

    // Check for special characters in the password and extract email prefix
    for (char ch : password) {
        if (strchr("@#%$!", ch)) hasSpecialChar = true;
    }
    for (const char* ptr = email; *ptr && *ptr != '@'; ++ptr) {
        emailPrefix += *ptr;
    }

    // Check if password contains email prefix
    if (password.find(emailPrefix) != std::string::npos) {
        return -300 - static_cast<int>(password.find(emailPrefix));
    }

    // Check for three consecutive identical characters
    for (int i = 0; i < length - 2; ++i) {
        if (password[i] == password[i + 1] && password[i + 1] == password[i + 2]) {
            return -401; // Three consecutive characters
        }
    }

    // Ensure all characters are valid
    if (!hasSpecialChar) return -5; // No special character
    for (int i = 0; i < length; ++i) {
        if (!checkCharacter(password[i])) return i; // Invalid character found
    }

    return -10; // Password is valid
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    std::map<std::string, std::pair<int, int>> pwd_counts;
    for(int i = 0; i < num_pwds; ++i) {
        std::string pwd(arr_pwds[i]);
        pwd_counts[pwd].first++;
        pwd_counts[pwd].second = pwd.length();
    }

    int max_count = 0, max_length = 0, idx = -1;
    for(int i = 0; i < num_pwds; ++i) {
        std::string pwd(arr_pwds[i]);
        if(pwd_counts[pwd].first > max_count || (pwd_counts[pwd].first == max_count && pwd_counts[pwd].second > max_length)) {
            max_count = pwd_counts[pwd].first;
            max_length = pwd_counts[pwd].second;
            idx = i;
        }
    }

    return idx;
}




////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////