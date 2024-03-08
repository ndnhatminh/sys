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

int checkExp(int a) {
    if (a < 0) a = 0;
    if (a > 600) a = 600;
    return a;
}

int checkHP(int a) {
    if (a < 0) a = 0;
    if (a > 666) a = 666;
    return a;
}

int checkMoney(int a) {
    if (a < 0) a = 0;
    if (a > 3000) a = 3000;
    return a;
}

int sqrNum(int a) {
    int sqrNum;
    for (int i = 1; i < a; i++) {
        int b = i * i;
        int c = (i - 1) * (i - 1);
        if (abs(a - b) < abs(a - c)) sqrNum = b;
        else break;
        if (a == b) { sqrNum = b; break; }
    }
    return sqrNum;
}

int max(int a, int b) {
    return a >= b ? a : b;
}

const int matrixSize = 10;

void findMaxOnDiagonals(int matrix[matrixSize][matrixSize], int i, int j, int& maxVal) {
    int Val = -100000;
    if (i == j) {
        if (i == 0 || i == 9)  maxVal = 0;
        else { // find max value on right diagonal
            for (int k = 01; k < 10; ++k) {
                int valUpRight, valDownLeft;
                if (i - k >= 0 && j + k < matrixSize) {
                    valUpRight = matrix[i - k][j + k];
                    Val = max(Val, valUpRight);
                }

                if (i + k < matrixSize && j - k >= 0) {
                    valDownLeft = matrix[i + k][j - k];
                    Val = max(Val, valDownLeft);
                }
            }
            maxVal = Val;
        }
        return;
    }
    if (i == 9 && j == 8) {
        maxVal = matrix[9][8]; return;
    }
    for (int k = 0; k < 10; ++k) {
        // find max value on left diagonal
        int valLeft, valRight;

        if (i + k < matrixSize && j + k < matrixSize) {
            valLeft = matrix[i - k][j - k];
            Val = max(Val, valLeft);
        }

        if (i - k >= 0 && j - k >= 0) {
            valRight = matrix[i + k][j + k];
            Val = max(Val, valRight);
        }
        // find max value on right diagonal
        int valUpRight, valDownLeft;
        if (i - k >= 0 && j + k < matrixSize) {
            valUpRight = matrix[i - k][j + k];
            Val = max(Val, valUpRight);
        }

        if (i + k < matrixSize && j - k >= 0) {
            valDownLeft = matrix[i + k][j - k];
            Val = max(Val, valDownLeft);
        }
    }
    maxVal = Val;
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1>99) return -99;
    if (e1 >= 0 && e1 <= 3) {
        switch (e1){
        case 0: exp2 = checkExp(exp2 + 29);
            break;
        case 1: exp2 = checkExp(exp2 + 45);
            break;
        case 2: exp2 = checkExp(exp2 + 75);
            break;
        case 3: exp2 = checkExp(exp2 + 29 + 45 + 75);
            break;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) { float x = exp1 + D / 200.0; x = ceil(x); exp1 = checkExp(x); }//exp1 = checkExp(ceil(exp1 + D / 200.0));
        else { float x = exp1 - D / 100.0; x = ceil(x); exp1 = checkExp(x); }//exp1 = checkExp(ceil(exp1 - D / 100.0));
    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 < 20) { float x = exp2 + e1 / 4.0 + 19; x = ceil(x); exp2 = checkExp(x); }//exp2 = checkExp(ceil(exp2 + e1 / 4.0 + 19));
        else if (e1 < 50) { float x = exp2 + e1 / 9.0 + 21; x = ceil(x); exp2 = checkExp(x); }//exp2 = checkExp(ceil(exp2 + e1 / 9.0 + 21));
        else if (e1 < 66) { float x = exp2 + e1 / 16.0 + 17; x = ceil(x); exp2 = checkExp(x); }// = checkExp(ceil(exp2 + e1 / 16.0 + 17));
                else if (e1 < 80) {
                    {float x = exp2 + e1 / 4.0 + 19; x = ceil(x); exp2 = checkExp(x); }
                    //exp2 = checkExp(ceil(exp2 + e1 / 4.0 + 19));
                    if (exp2 > 200) { float x = exp2 + e1 / 9.0 + 21; x = ceil(x); exp2 = checkExp(x); }//exp2 = checkExp(ceil(exp2 + e1 / 9.0 + 21));
                }
                    else {
                        {float x = exp2 + e1 / 4.0 + 19; x = ceil(x); exp2 = checkExp(x); }//exp2 = checkExp(ceil(exp2 + e1 / 4.0 + 19));
                        {float y = exp2 + e1 / 9.0 + 21; y = ceil(y); exp2 = checkExp(y); }//exp2 = checkExp(ceil(exp2 + e1 / 9.0 + 21));
                        if (exp2 > 400) {
                            {float x = exp2 + e1 / 16.0 + 17; x = ceil(x); exp2 = checkExp(x); }//exp2 = checkExp(ceil(exp2 + e1 / 16.0 + 17));
                            {float y = exp2 * 1.15; y = ceil(y); exp2 = checkExp(y); }//exp2 = checkExp(ceil(exp2 * 1.15));
                        }
                    }
    }
    exp1 = checkExp(exp1 - e1);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2>99) return -99;
    //Road 01
    int S1 = sqrNum(EXP1);
    double P1,P2,P3,Pavg;
    //caculate probablity
    if (EXP1 >= S1) P1 = 100;
    else P1 = (EXP1 / (S1 * 1.0) + 80) * 100 / 123.0;
    //Road 02
    if (M1==0) {
        EXP1 = checkExp(ceil(EXP1 * 1.17));
        HP1 = checkHP(ceil(HP1 * (1.00 - 0.17)));
    }
    else {
        int M_half = M1 * 0.50;
        //E2 is even
        if (E2 % 2 == 0) {
            if (M1 > 0) {
                //event 1
                if (HP1 < 200) {
                    M1 = checkMoney(M1 - 150);
                    HP1 = checkHP(ceil((HP1 * 1.30)));
                }
                else {
                    M1 = checkMoney(M1 - 70);
                    HP1 = checkHP(ceil(HP1 * 1.10));

                }
                if (M1 > 0) {
                    //event 2
                    if (EXP1 < 400) M1 = checkMoney(M1 - 200);
                    else M1 = checkMoney(M1 - 120);
                    EXP1 = checkExp(ceil(EXP1 * 1.13));
                    if (M1 > 0) {
                        //event 3
                        if (EXP1 < 300) M1 = checkMoney(M1 - 100);
                        else M1 = checkMoney(M1 - 120);
                        EXP1 = checkExp(ceil(EXP1 * 0.90));
                    }
                    else M1 = 0;
                }
                else M1 = 0;
            }
            else M1 = 0;
        }
        // E2 is odd
        else {
            while (M1 >= M_half) {
                if (HP1 < 200) {
                    HP1 = checkHP(ceil(HP1 * 1.30));
                    M1 = checkMoney(M1 - 150);
                }
                else {
                    HP1 = checkHP(ceil(HP1 * 1.10));
                    M1 = checkMoney(M1 - 70);
                }
                if (M1 < M_half) break;
                if (EXP1 < 400) {
                    M1 = checkMoney(M1 - 200);
                }
                else M1 = checkMoney(M1 - 120);
                EXP1 = checkExp(ceil(EXP1 * 1.13));
                if (M1 < M_half) break;
                if (EXP1 < 300) M1 = checkMoney(M1 - 100);
                else M1 = checkMoney(M1 - 120);
                EXP1 = checkExp(ceil(EXP1 * 0.90));
            }
        }
        EXP1 = checkExp(ceil(EXP1 * 1.17));
        HP1 = checkHP(ceil(HP1 * (1.00 - 0.17)));
    }
    //caculate probablity
    int S2= sqrNum(EXP1);
    if (EXP1 >= S2) P2 = 100;
    else P2 = (EXP1 / (S2 * 1.0) + 80) * 100 / 123.0;
    //Road 03
    double P[10] = { 32,47,28,79,100,50,22,83,64,11 };
    if (E2 < 10) P3 = P[E2];
    else P3 = P[(E2 / 10 + E2 % 10) % 10];
    if (P1 == P2 == P3 == 100) EXP1 = checkExp(ceil(EXP1 * 0.75));
    else {
        Pavg = (P1 + P2 + P3) / 3.0;
        if (Pavg < 50) {
            HP1 = checkHP(ceil(HP1 * 0.85));
            EXP1 = checkExp(ceil(EXP1 * 1.15));
        }
        else {
            HP1 = checkHP(ceil(HP1 * 0.9));
            EXP1 = checkExp(ceil(EXP1 * 1.2));
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
  
    int iMet = 0;
    int jMet=0;

    int count1 = 0; //count value > 2*E3
    int count2 = 0; //count value < -E3

    int gradeTaxi[matrixSize][matrixSize]; //matrix 10x10
    for (int i = 0; i < matrixSize; i++) { //10 rows 
        for (int j = 0; j < matrixSize; j++) { //10 columns
            gradeTaxi[i][j] = (E3 * j + i * 2) * (i - j);
            if (gradeTaxi[i][j] > (2 * E3)) {
                count1++; 
            }
            if (gradeTaxi[i][j] < -E3) {
                count2++; 
            }
        }
    }

    int unitsCount1 = (count1 / 10 + count1 % 10);
    unitsCount1 = (unitsCount1 / 10 + unitsCount1 % 10) % 10;
    int unitsCount2 = (count2 / 10 + count2 % 10);
    unitsCount2 = (unitsCount2 / 10 + unitsCount2 % 10) % 10;

    // position Sherlock and Waston met the Taxi
    iMet = unitsCount1;
    jMet = unitsCount2;
    
    int maxVal;// max value on diagonals

    findMaxOnDiagonals(gradeTaxi, iMet, jMet, maxVal);

    if (maxVal < 0) {
        maxVal = abs(maxVal);
    }

    int gradeSW = maxVal;

    if (abs(gradeTaxi[iMet][jMet]) <= gradeSW) {
        //They can catch the taxi
        EXP1 = checkExp(ceil(EXP1 * 1.12));
        EXP2 = checkExp(ceil(EXP2 * 1.12));
        HP1 = checkHP(ceil(HP1 * 1.10));
        HP2 = checkHP(ceil(HP2 * 1.10));
        return gradeSW;
    }
    else { //they cannot catch it
        EXP1 = checkExp(ceil(EXP1 * 0.88));
        EXP2 = checkExp(ceil(EXP2 * 0.88));
        HP1 = checkHP(ceil(HP1 * 0.90));
        HP2 = checkHP(ceil(HP2 * 0.90));
        return gradeTaxi[iMet][jMet];
    }
    
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    
    // Find string before "@"
    string se;
    const char* found = strchr(email, '@');
    if (found != nullptr) {
        size_t length = found - email;
        se = std::string(email, length);
    }

    // Check if length of s is between 8 and 20
    int sLength = strlen(s);
    if (sLength < 8) return -1;
    if (sLength > 20) return -2;

    // Check if se is in s
    const char* position = std::strstr(s, se.c_str());
    if (position != nullptr) {
        size_t sci = position - s;
        return -(300 + sci);
    }

    // Check if s contains 3 same characters in a row
    for (const char* p = s; *p != '\0'; ++p) {
        if (*p == *(p + 1) && *(p + 1) == *(p + 2)) {
            size_t sci = p - s;
            return -(400 + sci);
        }
    }

    // Check if s contains special character
    for (; *s != '\0'; ++s) {
        if (*s == '@' || *s == '#' || *s == '%' || *s == '$' || *s == '!') return -10;
    }

    return -5;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxCount = 0; //count times a password appears
    int maxLength = 0; //count characters in a password
    int maxIndex = 0; //position of first time password appears

    for (int i = 0; i < num_pwds; i++) {
        int count = 1;
        int length = 0;
        //compare 2 password to count times its appearance
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }

        const char* currentPwd = arr_pwds[i];
        while (*currentPwd != '\0') { 
            length++;
            currentPwd++;
        }

        if (count > maxCount || (count == maxCount && length > maxLength)) {
            maxCount = count;
            maxLength = length;
            maxIndex = i;
        }
    }

    return maxIndex;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////