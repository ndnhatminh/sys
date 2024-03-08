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

// Support Functions --------------------------------
void resetHP(int& n) {
    if (n > 666)
        n = 666;
    else if (n < 0)
        n = 0;
}

void resetEXP(int& n) {
    if (n > 600)
        n = 600;
    else if (n < 0)
        n = 0;
}

void resetM(int& n) {
    if (n > 3000)
        n = 3000;
    else if (n < 0)
        n = 0;
}

int isPerfectSquare (int EXP1) {
    int lowerNum = sqrt(EXP1);
    int upperNum = lowerNum + 1;
    int lowerDifference = EXP1 - (lowerNum * lowerNum);
    int upperDifference = (upperNum * upperNum) - EXP1;
    if (lowerDifference < upperDifference) return lowerNum * lowerNum;
    else return upperNum * upperNum;
}

bool isSpecialCharacter(char c) {
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

// ------------------------------------------------------------------------------------------------

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ((e1 < 0) || (e1 > 99)) return -99;

    if ((e1 >= 0) && (e1 <= 3)) {
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = ceil(exp1 + D/200.0);
        else exp1 = ceil(exp1 - D/100.0);
        resetEXP(exp1);

        if (e1 == 0) exp2 = exp2 + 29;
        else if (e1 == 1) exp2 = exp2 + 45;
        else if (e1 == 2) exp2 = exp2 + 75;
        else if (e1 == 3) exp2 = exp2 + 29 + 45 + 75;
        resetEXP(exp2);
    }

    if ((e1 >= 4) && (e1 <= 99)) {
        if (e1 <= 19) exp2 = ceil(exp2 + (e1/4.0 + 19));
        else if ((e1 >= 20) && (e1 <= 49)) exp2 = ceil(exp2 + (e1/9.0 + 21));
        else if ((e1 >= 50) && (e1 <= 65)) exp2 = ceil(exp2 + (e1/16.0 + 17));
        else if ((e1 >= 66) && (e1 <= 79)) {
            exp2 = ceil(exp2 + (e1/4.0 + 19));
            if (exp2 > 200) exp2 = ceil(exp2 + (e1/9.0 + 21));
        }
        else if (e1 >= 80) {
            exp2 = ceil(exp2 + (e1/4.0 + 19)); resetEXP(exp2);
            exp2 = ceil(exp2 + (e1/9.0 + 21)); resetEXP(exp2);
                if (exp2 > 400) {
                    exp2 = ceil(exp2 + (e1/16.0 +17)); resetEXP(exp2);
                    exp2 = ceil(1.15 * exp2); resetEXP(exp2);
            }
        }
        exp1 = ceil(exp1 - e1); resetEXP(exp1);
    }

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;

    // First path
    double P1, P2, P3;
    int MS1 = 0;
    const double halfMoney = 0.5 * M1;
    if (EXP1 >= isPerfectSquare(EXP1)) P1 = 1; else P1 = ((EXP1 * 1.00 / isPerfectSquare(EXP1)) + 80) / 123;
    
    // Second path
    if (E2 % 2 == 0) {
        // Event 1
        if (HP1 < 200) {
            HP1 = ceil(HP1 + 0.3 * HP1);
            MS1 = MS1 + 150;
            M1 = M1 - 150;
        } else {
            HP1 = ceil(HP1 + 0.1 * HP1);
            MS1 = MS1 + 70;
            M1 = M1 - 70;
        }
        resetHP(HP1);
        resetM(M1);

        // Event 2
        if (MS1 <= halfMoney) {
            if (EXP1 < 400) {
                MS1 = MS1 + 200;
                M1 = M1 - 200;
            } else {
                MS1 = MS1 + 120;
                M1 = M1 - 120;
            }
            EXP1 = (int) ceil(EXP1 + 0.13 * EXP1);
            resetEXP(EXP1);
            resetM(M1);
        }

        // Event 3
        if (MS1 <= halfMoney) {
            if (EXP1 < 300){
                MS1 = MS1 + 100;
                M1 = M1 - 100;
            } else {
                MS1 = MS1 + 120;
                M1 = M1 - 120;
            }
            EXP1 = ceil(EXP1 - 0.1 * EXP1);
            resetEXP(EXP1);
            resetM(M1);
        }
    }

    if (E2 % 2 != 0) {
        while (1) {
            // Event 1
            if (MS1 <= halfMoney) {
                if (HP1 < 200) {
                    HP1 = ceil(HP1 + 0.3 * HP1);
                    MS1 = MS1 + 150;
                    M1 = M1 - 150;
                } else {
                    HP1 = ceil(HP1 + 0.1 * HP1);
                    MS1 = MS1 + 70;
                    M1 = M1 - 70;
                }
                resetHP(HP1);
                resetM(M1);
            } else break;

            // Event 2
            if (MS1 <= halfMoney) {
                if (EXP1 < 400) {
                    MS1 = MS1 + 200;
                    M1 = M1 - 200;
                } else {
                    MS1 = MS1 + 120;
                    M1 = M1 - 120;
                }
                EXP1 = ceil(EXP1 + 0.13 * EXP1);
                resetEXP(EXP1);
                resetM(M1);
            } else break;

            // Event 3
            if (MS1 <= halfMoney) {
                if (EXP1 < 300) {
                    MS1 = MS1 + 100;
                    M1 = M1 - 100;
                } else {
                    MS1 = MS1 + 120;
                    M1 = M1 - 120;
                }
                EXP1 = ceil(EXP1 - 0.1 * EXP1);
                resetEXP(EXP1);
                resetM(M1);
            } else break;
        }
    }

    HP1 = ceil(HP1 - 0.17 * HP1); resetHP(HP1);
    EXP1 = ceil(EXP1 + 0.17 * EXP1); resetEXP(EXP1);
    if (EXP1 >= isPerfectSquare(EXP1)) P2 = 1; else P2 = ((EXP1 * 1.00 / isPerfectSquare(EXP1)) + 80) / 123;
    
    // Third path
    const int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 < 10) i = E2;
    else {
        int num1 = (int) E2/10;
        int num2 = (int) E2%10;
        i = (num1 + num2) % 10;
    }
    P3 = P[i] / 100.0;

    // After 3 paths
    if ((P1 == 1.00) && (P2 == 1.00) && (P3 == 1.00)){
        EXP1 = ceil(EXP1 - 0.25 * EXP1);
        resetEXP(EXP1);
    } else {
        double FP = (P1 + P2 + P3) / 3.00;
        if (FP < 0.5) {
            HP1 = ceil(HP1 - 0.15 * HP1);
            EXP1 = ceil(EXP1 + 0.15 * EXP1);
        } else {
            HP1 = ceil(HP1 - 0.1 * HP1);
            EXP1 = ceil(EXP1 + 0.2 * EXP1);
        }
        resetHP(HP1);
        resetEXP(EXP1);
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    // taxi matrix
    int taxi[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
    
    // find the meeting position
    int count = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (taxi[i][j] > (E3*2))
                count++;
    int i_idx = count;
    while (i_idx >= 10) {
        int num1 = i_idx / 10;
        int num2 = i_idx % 10;
        i_idx = num1 + num2;
    }
    

    count = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (taxi[i][j] < (-E3))
                count++;
    int j_idx = count;
    while (j_idx >= 10) {
        int num1 = j_idx / 10;
        int num2 = j_idx % 10;
        j_idx = num1 + num2;
    }

    // sherlock and watson matrix
    int sw[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int max1 = taxi[i][j];

            // đi xuống trái
            int a = i, b = j;
            while ((a != 9) && (b != 0)) {
                a++; b--;
                if (taxi[a][b] > max1) max1 = taxi[a][b];
            }
            
            // đi lên phải
            a = i, b = j;
            while ((a != 0) && (b != 9)) {
                a--; b++;
                if (taxi[a][b] > max1) max1 = taxi[a][b];
            }
            
            // đi xuống phải
            a = i, b = j;
            while ((a != 9) && (b != 9)) {
                a++; b++;
                if (taxi[a][b] > max1) max1 = taxi[a][b];
            }
            // đi lên trái
            a = i, b = j;
            while ((a != 0) && (b != 0)) {
                a--; b--;
                if (taxi[a][b] > max1) max1 = taxi[a][b];
            }
            sw[i][j] = max1;
        }
    }

    // return result
    if (abs(taxi[i_idx][j_idx]) > abs(sw[i_idx][j_idx])) {
        EXP1 = ceil(EXP1 - 0.12 * EXP1); resetEXP(EXP1);
        EXP2 = ceil(EXP2 - 0.12 * EXP2); resetEXP(EXP2);
        HP1 = ceil(HP1 - 0.1 * HP1); resetHP(HP1);
        HP2 = ceil(HP2 - 0.1 * HP2); resetHP(HP2);
        return taxi[i_idx][j_idx];
    } else {
        EXP1 = ceil(EXP1 + 0.12 * EXP1); resetEXP(EXP1);
        EXP2 = ceil(EXP2 + 0.12 * EXP2); resetEXP(EXP2);
        HP1 = ceil(HP1 + 0.1 * HP1); resetHP(HP1);
        HP2 = ceil(HP2 + 0.1 * HP2); resetHP(HP2);
        return sw[i_idx][j_idx];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    // find se
    string emailStr(email);
    size_t atPosition = emailStr.find('@');
    string se = "";
    if (atPosition != string::npos) se = emailStr.substr(0, atPosition);

    string sStr(s);

    // check invalid length
    if (sStr.length() < 8) return -1; else if (sStr.length() > 20) return -2;

    // check string with 2 more consecutive characters
    for (int i = 0; i < sStr.length() - 2; i++) 
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) return -(400 + i);

    // check if password s has string se or not
    int found = sStr.find(se);
    if (found != string::npos) return -(300 + found);

    // check invalid character and at least one special character
    bool hasSpecial = 0;
    for (size_t i = 0; i < sStr.length(); ++i) {
        char ch = sStr[i];
        // uppercase: [65..90], digit: [48..57], lowercase: [97..122]
        if (!((ch >= 65 && ch <= 90) || (ch >= 48 && ch <= 57) || (ch >= 97 && ch <= 122) || isSpecialCharacter(ch))) return i;
        if (isSpecialCharacter(ch)) hasSpecial = 1;
    }
    if (!hasSpecial) return -5;

    // password is correct
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxCount = 0;
    int maxCountFirstIdx = -1;
    int maxLength = 0;

    for (int i = 0; i < num_pwds; ++i) {
        int count = 1;
        for (int j = i + 1; j < num_pwds; ++j) {
            if (std::strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }
        if (count > maxCount || (count == maxCount && std::strlen(arr_pwds[i]) > maxLength)) {
            maxCount = count;
            maxLength = std::strlen(arr_pwds[i]);
            maxCountFirstIdx = i;
        }
    }

    return maxCountFirstIdx;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////