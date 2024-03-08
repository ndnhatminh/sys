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

// Version 1.3
// Fix rounding up numbers. Use roundUpMul instead of ceil.
// Add cases that se does not have anything. (unnesscesary but for safer)
// Check HP function
int checkVarHP(int HP) {
    if (HP > 666)   HP = 666;
    else if (HP < 0) HP = 0;
    return HP;
}
// Check EXP function
int checkVarExp(int EXP) {
    if (EXP > 600)     EXP = 600;
    else if (EXP < 0)  EXP = 0;
    return EXP;
}
// Check M function
int checkVarM(int M) {
    if (M > 3000)     M = 3000;
    else if (M < 0)  M = 0;
    return M;
}
// Check E function
bool checkVarE(int E) {
    // If E is out of range then, this function return 0, means stop that mission and return -99
    if (E > 99 || E < 0) {
        return 0;
    }
    else return 1;
}
// Round Up Multiplexer
int roundUpMul (double num, double rate) {
    int result =  num * rate + 0.999;
    return result;
}
int temp;
// Sum digits in number function
int sumNumber(int num) {
    if (num == 0) {
        int result = temp;
        temp = 0;
        return result;
    }                       
    temp += num % 10;
    return sumNumber(num / 10);
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    // Check e1
    if (checkVarE(e1)) {
        // Check EXP Point
        exp1 = checkVarExp(exp1);
        exp2 = checkVarExp(exp2);
        // Case 1: e1 from 0 to 3
        if (e1 <= 3) {
            switch (e1) {
                // Information 1
                case 0:
                exp2 += 29;
                break;
                // Information 2
                case 1:
                exp2 += 45;
                break;
                // Information 3
                case 2:
                exp2 += 75;
                break;
                // Information 4
                case 3:
                exp2 += (29 + 45 + 75);
                break;
            }
            int D;
            D = 3*e1 + 7*exp1;
            //Odd
            if (D % 2 == 1) {
                exp1 = roundUpMul(exp1 - D/100.0, 1); 
            }
            //Even
            else {
                exp1 += roundUpMul(D, 0.005);
            }
        }

        // Case 2: e1 from 4 to 99
        else if (e1 <= 99) {
            // Information 1
            if (e1 <= 19) {
                exp2 += roundUpMul(e1/4.0 + 19, 1);
            }
            // Information 2
            else if (e1 <= 49) {
                exp2 += roundUpMul(e1/9.0 + 21, 1);
            }
            // Information 3
            else if (e1 <= 65) {
                exp2 += roundUpMul(e1/16.0 + 17, 1);
            }
            // Information 4
            else if (e1 <= 79) {
                // Update Information 1
                exp2 += roundUpMul(e1/4.0 + 19, 1);
                if (exp2 > 200) {
                    // Update Information 2
                    exp2 += roundUpMul(e1/9.0 + 21, 1);
                }
            }
            // Information 5
            else {
                // Update Information 1
                exp2 += roundUpMul(e1/4.0 + 19, 1);
                // Update Information 2
                exp2 += roundUpMul(e1/9.0 + 21, 1);
                if (exp2 > 400) {
                    // Update Information 3
                    exp2 += roundUpMul(e1/16.0 + 17, 1);
                    // Bonus exp2
                    exp2 = roundUpMul(exp2, 1.15);
                }
            }
            // Misunderstanding
            exp1 -= e1;
        }
    }
    // Invalid Value
    else {
        return -99;
    }
    // Check Exp Point
    /* In this mission, the EXP1 always increase OR decrease and the EXP2 always increase, therefore, no need to check every calculation step. 
    Only the final answear should be checked. */ 
    exp1 = checkVarExp(exp1);
    exp2 = checkVarExp(exp2);
    return exp1 + exp2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // Check E2
    if (checkVarE(E2)) {
        // Check input values
        HP1 = checkVarHP(HP1);
        EXP1 = checkVarExp(EXP1);
        M1 = checkVarM(M1);

        int S;
        double P1, P2, P3;
        // Path 1
        // P1 Calculation
        P1 = pCalc(EXP1, S, P1);

        // Path 2
        // Check Money
        float M0 = (float) M1 / 2.0;
        int total = 0;
        // Odd
        if (E2 % 2 == 1) {
            while (total <= M0 && M1 != 0) {
                // First stop
                fStop(HP1, EXP1, M1, total); // Checked values
                if (total > M0) break;
                // Second stop
                sStop(EXP1, M1, total); // Checked values
                if (total > M0) break;
                // Third stop
                tStop(EXP1, M1, total); // Checked values
                if (total > M0) break;
            }
        }
        // Even
        else if (M1 > 0){
            fStop(HP1, EXP1, M1, total); // Checked values
            if (M1 > 0) {
                sStop(EXP1, M1, total); // Checked values
                if (M1 > 0) {
                    tStop(EXP1, M1, total); // Checked values
                }
            }
        }

        //End of Road, Update HP1 and EXP1
        HP1 = roundUpMul(HP1, 0.83);
        EXP1 = roundUpMul(EXP1, 1.17);

        // Check updated values
        HP1 = checkVarHP(HP1);
        EXP1 = checkVarExp(EXP1);

        //P2 Calculation
        P2 = pCalc(EXP1, S, P2);

        // Path 3
        int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int i;
        if (E2 < 10) {
            i = E2;
        }
        else {
            i = sumNumber(E2);
            if (i >= 10) {
                i %= 10;
            }
        }
        P3 = P[i] / 100.0;
        
        //Check Ps
        if (P1 == 1 && P2 == 1 && P3 == 1) {
            EXP1 = roundUpMul(EXP1, 0.75);
        }
        else {
            double avg;
            avg = (P1 + P2 + P3) / 3.0;
            if (avg < 0.5) {
                HP1 = roundUpMul(HP1, 0.85);
                EXP1 = roundUpMul(EXP1, 1.15);
            }
            else {
                HP1 = roundUpMul(HP1, 0.9);
                EXP1 = roundUpMul(EXP1, 1.2);
            }
            // Check updated values
            HP1 = checkVarHP(HP1);
            EXP1 = checkVarExp(EXP1);
        }
    }
    else {
        return -99;
    }

    return HP1 + EXP1 + M1;
}
// Money Record
void moneyRec(int & M, int & total, int bill) {
    M -= bill;
    total += bill;
    // Check M
    M = checkVarM(M);
}
// First Stop
void fStop(int & HP1, int & EXP1, int & M1, int & total) {
    if (HP1 < 200) {
        HP1 = roundUpMul(HP1, 1.3);
        moneyRec(M1, total, 150);
    }
    else {
        HP1 = roundUpMul(HP1, 1.1);
        moneyRec(M1, total, 70);
    }
    // Check HP
    HP1 = checkVarHP(HP1);
}
// Second Stop
void sStop(int & EXP1, int & M1, int & total) {
    if (EXP1 < 400) {
        moneyRec(M1, total, 200);
    }
    else {
        moneyRec(M1, total, 120);
    }
    EXP1 =  roundUpMul(EXP1, 1.13);
    // Check EXP
    checkVarExp(EXP1);
    
}
// Third Stop
void tStop(int & EXP1, int & M1, int & total) {
    if (EXP1 < 300) {
        moneyRec(M1, total, 100);
    }
    else {
        moneyRec(M1, total, 120);
    }
    EXP1 = roundUpMul(EXP1, 0.9);
    // Check EXP
    checkVarExp(EXP1);
}
// P Calculation Function
double pCalc(int & EXP1, int & S, double & P) {
    // Nearest perfect square
    S = round(sqrt(EXP1)) * round(sqrt(EXP1));
    // Compare EXP1 with S
    if (EXP1 >= S) {
        P = 1;
    }
    else {
        P = ((double)EXP1 / (double)S + 80) / 123.0;
    }
    return P;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int result;
    if (checkVarE(E3)) {  
        EXP1 = checkVarExp(EXP1);
        HP1 = checkVarHP(HP1);
        EXP2 = checkVarExp(EXP2);
        HP2 = checkVarHP(HP2);
        
        int matrix[10][10];
        int countp = 0;
        int countn = 0;
        int i, j;
        for (i = 0; i < 10; i++) {          // row
            for (j = 0; j < 10; j++) {      // column
                matrix[i][j] = ((E3*j) + (i*2)) * (i-j);
                if (matrix[i][j] > E3*2)   countp++;
                if (matrix[i][j] < -E3)   countn++;
            }
        }
        i = sumNumber(countp);
        if (i >= 10) {
            i = sumNumber(i);
        }
        j = sumNumber(countn);
        if (j >= 10) {
            j = sumNumber(j);
        }

        int m, n;
        int max = 0;
        for (m = 0; m < 10; m++) {          // column
            for (n = 0; n < 10; n++) {      // row
                if (m + n == i + j) {       // down left to up right 
                    if (max <= matrix[n][m]) {
                        max = matrix[n][m];
                    }
                }
                else if (m - n == i - j) {  // up left to down right
                    if (max <= matrix[n][m]) {
                        max = matrix[n][m];
                    }
                }
            }
        }
        if (abs(matrix[i][j]) > max) {
            EXP1 = roundUpMul(EXP1, 0.88);
            HP1 = roundUpMul(HP1, 0.9);
            EXP2 = roundUpMul(EXP2, 0.88);
            HP2 = roundUpMul(HP2, 0.9);
            result = matrix[i][j];
        }
        else {
            EXP1 = roundUpMul(EXP1, 1.12);
            HP1 = roundUpMul(HP1, 1.1);
            EXP2 = roundUpMul(EXP2, 1.12);
            HP2 = roundUpMul(HP2, 1.1);
            result = max;
        }
    }
    
    else    return -99;

    EXP1 = checkVarExp(EXP1);
    HP1 = checkVarHP(HP1);
    EXP2 = checkVarExp(EXP2);
    HP2 = checkVarHP(HP2);
    return result;
}





// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se;
    int countl = 0; // count length
    int errSe = 0;   // includes se
    int errSame = 0;   // More than 2 same char
    int errNo = 1;   // No special char
    int errOther = 0;   // Other cases

    int errSePos, errSamePos, errOtherPos;
    for(int i = 0; i < 100; i++) {
        if (email[i] == '@') {  // Stop when meets @ symbol
            break;
        }
        else {
            se += email[i];     // Adding one by one character of email
        }
    }
    while (s[countl] != '\0') { // Counting length of s
        countl++;
    }
    // Length Range
    if (countl < 8) {
        return -1;
    }
    else if (countl > 20) {
        return -2;
    }
    if(se[0] == '\0') return -300;
    for (int i = 0; i < 20; i++) {
        if (s[i] != '\0') {
            // check se
            if (s[i] == se[0]) {    // check first character of both then check the followings
                if (se.length() > 1) {
                    int n = 1;
                    int m = i;          // current position of s
                    for (int k = 0; k < se.length(); k++) { // repeat se.length() times to see if k can reach till the last character of se
                        if (s[m + 1] != se[n]) {            // if the next character one of s same as the next character one of se (se[1]) then it will continue, otherwise, break. 
                            break;
                        }
                        if (k == se.length() - 1 || se[n + 1] == '\0') { // if the k reaches the limit or next char of se is a null char(n already added), means s have se.
                            errSe++;
                            if (errSe == 1) {
                                errSePos = i;
                            }
                            //cout << errSePos;
                            break;
                        }
                        n++;
                        m++;
                    }
                }
                else {
                    errSe++;
                    if (errSe == 1) {
                        errSePos = i;
                    }
                }
            }

            // No more than 2 continuous character
            if (s[i] == s[i+1] && s[i] == s[i+2]) {
                errSame++;
                if (errSame == 1) {
                    errSamePos = i;
                }
            }

            // At least 1 special character
            if (!isalnum(s[i]) ) {
                // Limited characters. Cannot differ from alphanumeric with some exceptions.
                if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
                    errNo = 0;
                }
                else {
                    errOther++;
                    if (errOther == 1) {
                        errOtherPos = i;
                    }
                }
            }
        }
        else    break;
    }
    if (errSe > 0) return -(300 + errSePos);
    else if (errSame > 0) return -(400 + errSamePos);
    else if (errNo == 1) return -5;
    else if (errOther > 0) return errOtherPos;
    else return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int count = 0;
    int max = 0;
    int result = 0;
    for (int i = 0; i < num_pwds; i++) {            // take out current element
        for (int j = 1; i + j < num_pwds; j++) {        // then, compare with following elements
            if (strcmp(arr_pwds[i], arr_pwds[i + j]) == 0) {
                count++;                            // if the same, count the time it appears
            }
        }
        if (count > max) {                          // remember the maximum time a password appears 
            max = count;                            // change to the password with more appearances
            result = i;                             // set the result to position of that password // Note, there will be no chance for same password to have same time of appearance
        }                                           // so, when it goes to count == max, means the current password and the previous max one are different.
        else if (count == max) {                                        // therefore if count == max, we just need to classify which one is longer to get the result.
            if (strlen(arr_pwds[i]) > strlen(arr_pwds[result])) {       // if the current pass longer than previous max pass, result will be the position of the current one.
                result = i;
            }
        }
        count = 0;                                  // reset the count to 1 to repeat the process for the following password.
    }
    return result;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////