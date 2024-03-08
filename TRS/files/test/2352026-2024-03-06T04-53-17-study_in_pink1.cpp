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

// Reset functions
void resetHP(int & HP) {
    if (HP < 0)
        HP = 0;
    else if (HP > 666)
        HP = 666;
}

void resetEXP(int & EXP) {
    if (EXP < 0)
        EXP = 0;
    else if (EXP > 600)
        EXP = 600;
}

void resetM(int & M) {
    if (M < 0)
        M = 0;
    else if (M > 3000)
        M = 3000;
}

double Ceil(double a)
{
    // int temp_a = a;
    // if(temp_a - a > )
    // {
    //     return Ceil(a);
    // }
    // return temp_a;
    double temp = a - floor(a);
    if (temp > 0.0000001)
        return floor(a) + 1;
    return floor(a);
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    resetEXP(exp1);
    resetEXP(exp2);

    if (e1 < 0 || e1 > 99) return -99;
    
    if (e1 < 4) {
        if (e1 == 0)
            exp2 += 29;
        else if (e1 == 1)
            exp2 += 45;
        else if (e1 == 2)
            exp2 += 75;
        else
            exp2 += 29 + 45 + 75;

        int d = e1 * 3 + exp1 * 7; // Sherlock's decision
        if (d % 2 == 0)
            exp1 += Ceil(d/200.0);
        else
            exp1 -= d/100;
    } else {
        if (e1 < 20)
            exp2 += Ceil(e1/4.0 + 19);
        else if (e1 < 50)
            exp2 += Ceil(e1/9.0 + 21);
        else if (e1 < 66)
            exp2 += Ceil(e1/16.0 + 17);
        else if (e1 < 80) {
            exp2 += Ceil(e1/4.0 + 19);
            if (exp2 > 200)
                exp2 += Ceil(e1/9.0 + 21);
        } else {
            exp2 += Ceil(e1/4.0 + 19) + Ceil(e1/9.0 + 21);
            if (exp2 > 400) {
                exp2 += Ceil(e1/16.0 + 17);

                // Explained all 3 information
                exp2 += Ceil(exp2 * 0.15);
            }
        }
        exp1 -= e1;
    }
    
    resetEXP(exp1);
    resetEXP(exp2);
    
    return exp1 + exp2;
}

// Task 2
bool isPerfectSquareNum(int num) {
    int x = sqrt(num);
    return (x * x == num);
}

int traceLuggage_Road1(int EXP1) {
    // Find closest perfect square num (S)
    int S;
    for (int i = 0; ; i++) {
        if (isPerfectSquareNum(EXP1 + i)) {
            S = EXP1 + i;
            break;
        }
        if (isPerfectSquareNum(EXP1 - i)) {
            S = EXP1 - i;
            break;
        }
    }

    if (EXP1 < S)
        return round((EXP1 * 1.0 / S + 80) / 123 * 100);
    return 100; // 100%
}

int traceLuggage_Road2(int & HP1, int & EXP1, int & M1, int E2) {

    if (E2 % 2 == 1) {
        int firstHalfM1 = M1 / 2,
        totalExpense = 0;
    
        while (true) {
            // Grocery store
            if (HP1 < 200) {
                HP1 += Ceil(HP1 * 0.3);
                M1 -= 150;
                totalExpense += 150;
                resetHP(HP1);
            }
            else {
                HP1 += Ceil (HP1 * 0.1);
                M1 -= 70;
                totalExpense += 70;
                resetHP(HP1);
            }
            if (totalExpense > firstHalfM1)
                break;

            // Taxi or carriage
            if (EXP1 < 400){
                M1 -= 200;
                totalExpense += 200;
            }
            else {
                M1 -= 120;
                totalExpense += 120;
            }
            EXP1 += Ceil(EXP1 * 0.13);
            if (totalExpense > firstHalfM1)
                break;
            
            // Homeless
            if (EXP1 < 300) {
                M1 -= 100;
                totalExpense += 100;
            } else {
                M1 -= 120;
                totalExpense += 120;
            }
            EXP1 -= floor(EXP1 * 0.1);
            if (totalExpense > firstHalfM1)
                break;
        }

    } else { // E2 % 2 == 0
        // Grocery store
        if(M1 > 0) {
            if (HP1 < 200) {
                HP1 += Ceil(HP1 * 0.3);
                M1 -= 150;
                resetHP(HP1);
            }
            else {
                HP1 += Ceil (HP1 * 0.1);
                M1 -= 70;
                resetHP(HP1);
            }
        }

        if (M1 > 0) {
            // Taxi or carriage
            if (EXP1 < 400)
                M1 -= 200;
            else
                M1 -= 120;
                
            EXP1 += Ceil(EXP1 * 0.13);
        }

        if (M1 > 0) {
            // Homeless
            if (EXP1 < 300)
                M1 -= 100;
            else
                M1 -= 120;
            EXP1 -= floor(EXP1 * 0.1);
        } 

    }

    HP1 -= floor(HP1 * 0.17);
    EXP1 += Ceil(EXP1 * 0.17);

    resetEXP(EXP1);
    resetHP(HP1);
    resetM(M1);

    return traceLuggage_Road1(EXP1);
}

int traceLuggage_Road3(int E2) {
    const int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10) 
        return P[E2];
    return P[(E2 / 10 + E2 % 10) % 10];
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    if (E2 < 0 || E2 > 99) return -99;
    
    resetEXP(EXP1);
    resetHP(HP1);
    resetM(M1);

    int P1 = traceLuggage_Road1(EXP1),
        P2 = traceLuggage_Road2(HP1, EXP1, M1, E2),
        P3 = traceLuggage_Road3(E2);
    
    int P = P1 + P2 + P3;
    if (P == 300) { // P1 == 100%, P2 == 100%, P3 == 100%
        EXP1 -= floor(EXP1 * 0.25);

    }else{

        if (P < 150) { // Average < 50%
            HP1 -= floor(HP1 * 0.15);
            EXP1 += Ceil(EXP1 * 0.15);
        } else {
            HP1 -= floor(HP1 * 0.1);
            EXP1 += Ceil(EXP1 * 0.2);
        }
    }
    resetEXP(EXP1);
    resetHP(HP1);
    resetM(M1);

    return HP1 + EXP1 + M1;
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;

    int map[10][10],
        x = 0, y = 0; // Location they met taxi
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = (E3 * j + i * 2) * (i - j);
            if (map[i][j] > 2 * E3)
                x++;
            else if (map[i][j] < -E3)
                y++;
        }
    }
    
    while (x > 9)
        x = x / 10 + x % 10;
    while (y > 9)
        y = y / 10 + y % 10;        
    
    int detectivePoint = map[x][y];
    for (int i = x-1, j = y-1; (i > -1 && j > -1); i--, j--)
        detectivePoint = max(detectivePoint, map[i][j]);
    for (int i = x+1, j = y+1; (i < 10 && j < 10); i++, j++)
        detectivePoint = max(detectivePoint, map[i][j]);
    for (int i = x+1, j = y-1; (i < 10 && j > -1); i++, j--)
        detectivePoint = max(detectivePoint, map[i][j]);
    for (int i = x-1, j = y+1; (i > -1 && j < 10); i--, j++)
        detectivePoint = max(detectivePoint, map[i][j]);

    if (abs(map[x][y]) > detectivePoint) {
        EXP1 -= floor(EXP1 * 0.12);
        HP1 -= floor(HP1 * 0.1);
        EXP2 -= floor(EXP2 * 0.12);
        HP2 -= floor(HP2 * 0.1);
        resetEXP(EXP1);
        resetEXP(EXP2);
        resetHP(HP1);
        resetHP(HP2);
        return map[x][y];
    } else {
        EXP1 += Ceil(EXP1 * 0.12);
        HP1 += Ceil(HP1 * 0.1);
        EXP2 += Ceil(EXP2 * 0.12);
        HP2 += Ceil(HP2 * 0.1);
        resetEXP(EXP1);
        resetEXP(EXP2);
        resetHP(HP1);
        resetHP(HP2);
        return detectivePoint;
    }

    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
    // Const char * to char *.
    char * s_temp = (char *) s;

    // Check password length
    int passLen = strlen(s_temp);
    if (passLen < 8)
        return -1;
    if (passLen > 20)
        return -2;

    // Get se from email
    char se[100];
    int emailLen = strlen(email);
    int idx = 0;
    for (;(idx < emailLen && email[idx] != '@'); idx++)
        se[idx] = email[idx];
    se[idx] = '\0';

    
    // Check if password contain se
    char * pch = strstr(s_temp, se);
    if (pch != nullptr)
        return -(300 + pch - s_temp);
    
    // Check if contain > 2 consecutive characters
    bool flag = false;
    for (int i = 1; s[i] != '\0'; i++)
        if (s[i] == s[i-1]) {
            if (flag)
                return -(400 + i-2);
            flag = true;
        } else
            flag = false;
    
    // Check if contain special characters
    pch = strchr(s_temp,'@');
    if (pch == nullptr) {
        pch = strchr(s_temp, '#');
        if (pch == nullptr) {
            pch = strchr(s_temp, '%');
            if (pch == nullptr) {
                pch = strchr(s_temp, '$');
                if (pch == nullptr) {
                    pch = strchr(s_temp, '!');
                    if (pch == nullptr)
                        return -5;
                }
            }
        }
    }

    // Check if contain invalid characters
    for (int i = 0; s_temp[i] != '\0'; i++) {
        char current = tolower(s_temp[i]);
        if ( (current < 'a' || current > 'z') &&
             (current < '0' || current > '9') &&
             current != '@' && current != '#' &&
             current != '%' && current != '$' &&
             current != '!'
           )
            return i;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int unique_idx[30], num_unique = 0,
        appeared[30], maxAppeared = 0;
    for (int i = 0; i < num_pwds; i++) {
        bool exist = false;
        for (int j = 0; j < num_unique; j++) {
            if (arr_pwds[i] == arr_pwds[unique_idx[j]]) {
                exist = true;
                appeared[j]++;
                maxAppeared = max(maxAppeared, appeared[j]);
                break;
            }
        }
        if (!exist) {
            unique_idx[num_unique] = i;
            appeared[num_unique] = 1;
            num_unique++;
            maxAppeared = max(maxAppeared, 1);
        }
    }

    int maxLenIdx = -1;
    for (int i = 0; i < num_unique; i++) {
        if (appeared[i] == maxAppeared) {
            if (maxLenIdx == -1)
                maxLenIdx = unique_idx[i];
            else if (strlen(arr_pwds[unique_idx[i]])
                     > strlen(arr_pwds[maxLenIdx]))
                    maxLenIdx = unique_idx[i];
        }
    }

    return maxLenIdx;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////