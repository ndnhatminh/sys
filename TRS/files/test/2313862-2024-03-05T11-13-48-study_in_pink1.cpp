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
void checkLimitOfEXP (int & exp) {
    if(exp > 600) exp = 600;
    if(exp < 0) exp = 0;
}
void checkLimitOfHP (int & hp) {
    if(hp > 666) hp = 666;
    if(hp < 0) hp = 0;
}
void checkLimitOfM (int & m) {
    if(m > 3000) m = 3000;
    if(m < 0) m = 0;
}
// Function calculating the elements of a number's sum
int sumElement (int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    // Check the value of e1
    if ((e1 > 99) || (e1 < 0)) return -99;
    else {
        int D = 0; //declare Sherlock's decision
        // Case 1
        if (e1 <= 3) {
            // Check e1's value
            if (e1 == 0) {
                exp2 += 29;
                checkLimitOfEXP(exp2);
            }

            if (e1 == 1) {
                exp2 += 45;
                checkLimitOfEXP(exp2);
            }

            if (e1 == 2) {
                exp2 += 75;
                checkLimitOfEXP(exp2);
            }

            if (e1 == 3) {
                exp2 += 29 + 45 + 75;
                checkLimitOfEXP(exp2);
            }

            //Sherlock's decision
            D = e1 * 3 + exp1 * 7;

            // Check that D is even or odd;
            if (D % 2 == 0) {
                exp1 = ceil(float(exp1 + D / 200.0));
                checkLimitOfEXP(exp1);
            }
            else {
                exp1 = ceil(float(exp1 - D / 100.0));
                checkLimitOfEXP(exp1);
            }
        }

        // Case 2
        else {
            // Check e1's range
            if ((e1 >= 4) && (e1 <= 19)) {
                exp2 = ceil(float(exp2 + (e1 / 4.0 + 19)));
                checkLimitOfEXP(exp2);
            }

            if ((e1 >= 20) && (e1 <= 49)) {
                exp2 = ceil(float(exp2 + (e1 / 9.0 + 21)));
                checkLimitOfEXP(exp2);
            }

            if ((e1 >= 50) && (e1 <= 65)) {
                exp2 = ceil(float(exp2 + (e1 / 16.0 + 17)));
                checkLimitOfEXP(exp2);
            }

            if ((e1 >= 66) && (e1 <= 79)) {
                exp2 = ceil(float(exp2 + (e1 / 4.0 + 19)));
                if (exp2 > 200) {
                    exp2 = ceil(float(exp2 + (e1 / 9.0 + 21)));
                }
                checkLimitOfEXP(exp2);
            }

            if (e1 >= 80) {
                exp2 = ceil(float(exp2 + (e1 / 4.0 + 19)));
                exp2 = ceil(float(exp2 + (e1 / 9.0 + 21)));
                if (exp2 > 400) {
                    exp2 = ceil(float(exp2 + (e1 / 16.0 + 17)));
                    exp2 = ceil(float(exp2 * 1.15));
                }
            checkLimitOfEXP(exp2);
            }

            // Reducing exp1
            exp1 -= e1;
            checkLimitOfEXP(exp1);
        }
        return exp1 + exp2;
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if ((E2 > 99) || (E2 < 0)) return -99;
    // ROAD 01
    float p1 = 0, p2 = 0, p3 = 0, finalProbability = 0;
    int s = pow(round(sqrt(EXP1)), 2);
    if (s <= EXP1) p1 = 1; // s is the nearest perfect square to the value EXP1
    else p1 = (float(EXP1) / s + 80) / 123.0;

    // ROAD 02
    // Declare an initial money at road 02
    int initialM = M1;
    // Declare a variable to calculate the paid money
    int paidM = 0;
    // Declare a bool variable to execute the below loop
    bool trigger = true;
    while(trigger){        
        if (E2 % 2 == 0) trigger = false; //if E2 is even, the loop will be executed once

        // Event 1
        if (HP1 < 200) {
            HP1 = ceil(float(HP1 * 1.3));
            checkLimitOfHP(HP1);
            M1 -= 150;
            checkLimitOfM(M1);                
            paidM += 150;
        }
        else {
            HP1 = ceil(float(HP1 * 1.1));
            checkLimitOfHP(HP1);
            M1 -= 70;
            checkLimitOfM(M1);
            paidM += 70;
        }
        // Check that M1 is enough or not when E2 is even
        if(E2 % 2 == 0 && M1 == 0 ) break;
        // Check paid money when E2 is odd
        if(E2 % 2 != 0 && paidM > initialM * 0.5) break;

        // Event 2
        if (EXP1 < 400) {
            M1 -= 200;
            paidM += 200;
        }
        else {
            M1 -= 120;                
            paidM += 120;
        }  
        checkLimitOfM(M1);
        EXP1 = ceil(float(EXP1 * 1.13));
        checkLimitOfEXP(EXP1);
        // Check that M1 is enough or not when E2 is even
        if(E2 % 2 == 0 && M1 == 0 ) break;
        // Check paid money when E2 is odd
        if(E2 % 2 != 0 && paidM > initialM * 0.5) break;

        // Event 3
        if (EXP1 < 300) {
            paidM += 100;
            M1 -= 100;
            checkLimitOfM(M1);
        }
        else {
            paidM += 120;
            M1 -= 120;
            checkLimitOfM(M1);
        }
        EXP1 = ceil(float(EXP1 * 0.9));
        // Check that M1 is enough or not when E2 is even
        if(E2 % 2 == 0 && M1 == 0 ) break;
        // Check paid money when E2 is odd
        if(E2 % 2 != 0 && paidM > initialM * 0.5) break;
    }
    // Decrease HP1 and increase EXP1
    HP1 = ceil(float(HP1 * 0.83));
    EXP1 = ceil(float(EXP1 * 1.17)); 
    checkLimitOfEXP(EXP1);  
    // Calculate p2 
    if(p1 != 1) p2 = (float(EXP1) / s + 80) / 123.0;
    else p2 = 1;

    // Road 03
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = 0; // i is the index value of the probability P[i]

    if(E2 < 10) i = E2;
    else {
        i = sumElement(E2) % 10;
    }
    // Calculate p3 
    p3 = P[i] / 100.0;

    // After going through 3 routes, check condition of p1, p2, p3 to calculate the final probability
    if(p1 == 1 && p2 == 1 && p3 == 1) EXP1 = ceil(EXP1 * 0.75);
    else {
        finalProbability = (p1 + p2 + p3) / 3.0;
        if(finalProbability < 0.5) {
            HP1 = ceil(float(HP1 * 0.85));
            EXP1 = ceil(float(EXP1 * 1.15));
        }
        else {
            HP1 = ceil(float(HP1 * 0.9));
            EXP1 = ceil(float(EXP1 * 1.2));
        }
        checkLimitOfEXP(EXP1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    // Initialize matrix 10x10
    int matrix[10][10] = {0};

    // Two variables below will be used to count the number of positive and negative values in the matrix 
    int positiveVal = 0;
    int negativeVal = 0;
    for(int x = 0; x < 10; x++) {
        for(int y = 0; y < 10; y++) {
            matrix[x][y] = ((E3 * y) + (x * 2)) * (x - y);
            if(matrix[x][y] > E3 * 2) positiveVal++;
            if(matrix[x][y] < -E3) negativeVal++;
        }
    }
    // Calculate the value of i, j for finding point (i, j)
    int i = sumElement(positiveVal);
    int j = sumElement(negativeVal);
    while(i >= 10) {
        i = sumElement(i);
    }
    while(j >= 10) {
        j = sumElement(j);
    }
    // The score of Sherlock and Watson
    long long scoreOfSW = -1e9; 

    // Check the maximum value in the left diagonal
    for(int x = i, y = j; x < 10 && y < 10; x++, y++) {
        if(matrix[x][y] > scoreOfSW) scoreOfSW = matrix[x][y];
    }
    for(int x = i, y = j; x >= 0 && y >= 0; x--, y--) {
        if(matrix[x][y] > scoreOfSW) scoreOfSW = matrix[x][y];
    }

    // Check the maximum value in the right diagonal
    for(int x = i, y = j; x >= 0 && y < 10; x--, y++) {
        if(matrix[x][y] > scoreOfSW) scoreOfSW = matrix[x][y];
    }
    for(int x = i, y = j; x < 10 && y >= 0; x++, y--) {
        if(matrix[x][y] > scoreOfSW) scoreOfSW = matrix[x][y];
    }
    // Compare grade of Sherlock-Watson and taxi
    if(abs(matrix[i][j]) > scoreOfSW) {
        EXP1 = ceil(float(EXP1 * 0.88));
        HP1 = ceil(float(HP1 * 0.9));
        EXP2 = ceil(float(EXP2 * 0.88));
        HP2 = ceil(float(HP2 * 0.9));
        return matrix[i][j];
    }
    else {
        EXP1 = ceil(float(EXP1 * 1.12));
        HP1 = ceil(float(HP1 * 1.1)); 
        EXP2 = ceil(float(EXP2 * 1.12));
        HP2 = ceil(float(HP2 * 1.1));
        checkLimitOfEXP(EXP1);
        checkLimitOfEXP(EXP2);
        checkLimitOfHP(HP1);
        checkLimitOfHP(HP2);
        return scoreOfSW;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se = "";
    for(int i = 0; i < strlen(email) - strlen(strchr(email, '@')); i++) {
        se += email[i];
    } 
    // Check conditions to return values 
    if(strlen(s) < 8) return -1;
    if(strlen(s) > 20) return -2;

    // If s contains se
    const char * sePointer = se.c_str(); // Convert string se to const char * sePoint
    if(strstr(s, sePointer) != NULL) {
        int sei = strlen(s) - strlen(strstr(s, sePointer));
        return -(300 + sei);
    }

    // If s contains more than 2 consecutive and identical characters
    for(int i = 0; i < strlen(s) - 2; i++) {
        if(s[i] == s[i + 1] && s[i] == s[i + 2]) return -(400 + i);
    }

    int cnt = 0;// cnt is used to check that if s does not contain special characters
    bool havingAnotherSpecicalChar = false;// this variable is used to check that if s contains different special character without ’@’, ’#’, ’%’, ’$’, ’!’.
    int notAlnumPos = 0;// notAlnumPos is used to restore the position that contains different special character
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            cnt++;
        }
        if (!isalnum(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') {
            notAlnumPos = i;
            havingAnotherSpecicalChar = true;
        }
    }
    if(cnt == 0) return -5;
    if(havingAnotherSpecicalChar) return notAlnumPos; 
    return -10; // when s is valid password
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int cntMax = 0; // cntMax is used to restore the maximun frequence of a string appearing in arr_pwds[]
    int index = 0; // index is used to restore the position when cntMax is updated
    for(int i = 0; i < num_pwds; i++) {
        int cnt = 0; // cnt is used to count the frequence of a string appearing in arr_pwds[]
        for(int j = 0; j < num_pwds; j++) {
            if(strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                cnt++;
            }
        }
        if(i == 0) cntMax = cnt; // assume that arr_pwds[0] has the maximum frequence
        if(cnt >= cntMax && strcmp(arr_pwds[i], arr_pwds[index]) != 0) {
            if(cnt > cntMax) {
                cntMax = cnt; // cntMax is updated
                index = i;
            }
            // If cnt = cntMax, we will check that whose length is longer
            else {
               if(strlen(arr_pwds[index]) < strlen(arr_pwds[i])) {
                cntMax = cnt;
                index = i;
            } 
            }
        }
    }
    return index;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////