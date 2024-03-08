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

void adjustInRangeEXP(int & exp) {
    if (exp > 600) {exp = 600;}
    else if (exp < 0) {exp = 0;}
}

void adjustInRangeHP(int & hp) {
    if (hp > 666) {hp = 666;}
    else if (hp < 0) {hp = 0;}
}

void adjustInRangeM(int & m) {
    if (m > 3000) {m = 3000;}
    else if (m < 0) {m = 0;}
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) {
        return -99; 
    }

    if (e1 >= 0 && e1 <= 3) {
        switch (e1) {
            case 0:
                exp2 += 29;
                break;
            case 1:
                exp2 += 45;
                break;
            case 2:
                exp2 += 75;
                break;
            default: 
                exp2 += (29 + 45 + 75);
                break;
        }

        int D = (e1 * 3) + (exp1 * 7); 
        if ((int)D % 2 == 0) {
            exp1 += ceilf(float(D/200));  
        }
        else {
            exp1 -= ceilf(float(D/100)); 
        }
    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 += ceilf(e1 / 4.0) + 19;
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 += ceilf(e1 / 9.0) + 21;
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 += ceilf(e1 / 16.0) + 17;
        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2 += ceilf(e1 / 4.0) + 19;
            if (exp2 > 200) {exp2 += ceilf(e1 / 9.0) + 21;}
        }
        else {
            exp2 += ceilf(e1 / 4.0) + 19;
            exp2 += ceilf(e1 / 9.0) + 21;
            if ((int)exp2 > 400) {
                exp2 += ceilf(e1 / 16.0) + 17;
                exp2 = ceilf(exp2 + exp2 * 0.15); 
            }
        }
        exp1 -= e1; 
    }

    adjustInRangeEXP(exp1);
    adjustInRangeEXP(exp2);

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) {
        return -99; 
    }

    // 1st route
    int S = 0;
    double P1; 
    nearestPerfectSqr(EXP1, S); 
    if (EXP1 >= S) {P1 = 1.00;}
    else {P1 = ((static_cast<double>(EXP1) / static_cast<double>(S)) + 80 ) / 123;}

    // 2nd route
    int onehalf = M1 / 2; 
    int sumM = 0; 
    int HPtmp = 0;
    int EXPtmp = 0; 

    while (true) {
        HPtmp = 0;
        EXPtmp = 0;

        // 1st event
        if (HP1 < 200) {
            HPtmp = ceilf(HP1 * 0.3); 
            sumM += 150;
        }
        else {
            HPtmp = ceilf(HP1 * 0.1); 
            sumM += 70; 
        }
        if (((E2 % 2) != 0 && sumM > onehalf) || ((E2 % 2) == 0 && sumM > M1)) {break;}
        HP1 += HPtmp; 
        adjustInRangeHP(HP1);

        // 2nd event
        if (EXP1 < 400) {sumM += 200;}
        else {sumM += 120;}
        EXPtmp = ceilf(EXP1 * 0.3); 
        if (((E2 % 2) != 0 && sumM > onehalf) || ((E2 % 2) == 0 && sumM > M1)) {break;}
        EXP1 += EXPtmp;
        adjustInRangeEXP(EXP1);

        // 3rd event
        if (EXP1 < 300) {sumM += 100;}
        else {sumM += 120;}
        EXPtmp = ceilf(EXP1 * 0.1); 
        if (((E2 % 2) != 0 && sumM > onehalf) || ((E2 % 2) == 0 && sumM > M1)) {break;} 
        EXP1 -= EXPtmp; 
        adjustInRangeEXP(EXP1);
        
        // Check for E2
        if ((E2 % 2) == 0) {
            break;
        }
    }

    if ((E2 % 2) == 0 && sumM > M1) {M1 = 0;}
    else {M1 -= sumM;}

    HP1 = ceilf(HP1 - (HP1 * 0.17));  
    EXP1 = ceilf(EXP1 + EXP1 * 0.17); 

    adjustInRangeEXP(EXP1);
    adjustInRangeHP(HP1);
    adjustInRangeM(M1);

    S = 0;
    double P2; 
    nearestPerfectSqr(EXP1, S); 
    if (EXP1 >= S) {P2 = 1;}
    else {P2 = ((static_cast<double>(EXP1) / static_cast<double>(S)) + 80 ) / 123;}

    // 3rd route
    double P[10] = {0.32, 0.47, 0.28, 0.79, 1.00, 0.50, 0.22, 0.83, 0.64, 0.11}; 
    double P3; 

    if (E2 <= 9) {P3 = P[E2];}
    else {
        int i = (((E2 / 10) % 10) + (E2 % 10)) % 10; 
        P3 = P[i]; 
    }

    // Average probabilities
    if (P1 == 1.00 && P2 == 1.00 && P3 == 1.00) {
        EXP1 = ceilf(EXP1 - EXP1 * 0.25);
    }
    adjustInRangeEXP(EXP1);

    double average;
    average = (P1 + P2 + P3) / 3;
    if (average < 0.50) {
        HP1 = ceilf(HP1 - HP1 * 0.15);
        EXP1 = ceilf(EXP1 + EXP1 * 0.15);
    }
    else {
        HP1 = ceilf(HP1 - HP1 * 0.10);
        EXP1 = ceilf(EXP1 + EXP1 * 0.20);
    }

    adjustInRangeEXP(EXP1);
    adjustInRangeHP(HP1);

    return HP1 + EXP1 + M1;
}

bool perfectSqr(int num) {
    if ((sqrt(num) - floor(sqrt(num))) != 0) {
        return false;
    }
    return true; 
}

void nearestPerfectSqr(int num, int & s) {
    if (perfectSqr(num)) {
        s = num;
        return; 
    }

    int aboveN = -1, belowN = -1;
    int runner; 

    runner = num + 1;
    while (true) {
        if (perfectSqr(runner)) {
            aboveN = runner;
            break;
        }
        else {
            ++runner; 
        }
    }

    runner = num - 1;
    while (true) {
        if (perfectSqr(runner)) {
            belowN = runner;
            break;
        }
        else {
            --runner; 
        }
    }

    if ((aboveN - num) < (num - belowN)) {s = aboveN;}
    else {s = belowN;}
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) {
        return -99; 
    }

    // Taxi matrix
    int matrixTaxi[10][10];
    memset(matrixTaxi, 0, sizeof(matrixTaxi)); 

    int posSum = 0, negSum = 0; 
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrixTaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j); 
            if (matrixTaxi[i][j] > (E3 * 2)) {++posSum;}
            else if (matrixTaxi[i][j] < (-E3)) {++negSum;}
        }
    }

    while (true) {
        if (posSum > 9) { posSum = (((posSum / 10) % 10) + (posSum % 10)); }
        if (negSum > 9) { negSum = (((negSum / 10) % 10) + (negSum % 10)); }

        if (negSum <= 9 && posSum <= 9) { break; }
    }

    // Serlock and Watson matrix
    int matrixSW[10][10]; 
    memset(matrixSW, 0, sizeof(matrixSW));

    // Each cell's value in matrixSW is the greatest value in both right and left diagonal of matrixTaxi 
    // which go through the coordinates of that cell
    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < 10; ++i) {
            greatestDiagonalElement(matrixTaxi, i, j, matrixSW[i][j]); 
        }
    }

    int returnVal = 0; 
    if (abs(matrixTaxi[posSum][negSum]) > matrixSW[posSum][negSum]) {
        EXP1 = ceilf(EXP1 - EXP1 * 0.12); 
        EXP2 = ceilf(EXP2 - EXP2 * 0.12); 
        HP1 = ceilf(HP1 - HP1 * 0.10);
        HP2 = ceilf(HP2 - HP2 * 0.10);        
        returnVal = matrixTaxi[posSum][negSum]; 
    }
    else {
        EXP1 = ceilf(EXP1 + EXP1 * 0.12); 
        EXP2 = ceilf(EXP2 + EXP2 * 0.12); 
        HP1 = ceilf(HP1 + HP1 * 0.10); 
        HP2 = ceilf(HP2 + HP2 * 0.10);
        returnVal = matrixSW[posSum][negSum];   
    }

    adjustInRangeEXP(EXP1);
    adjustInRangeHP(HP1);
    adjustInRangeEXP(EXP2);
    adjustInRangeHP(HP2);

    return returnVal;
}

void greatestDiagonalElement(int matrixTaxi[0][10], int x, int y, int & cell) {
    int max = 0;
    int i = x, j = y; 
    // left-to-right diagonal
    while (i >= 0 && j >= 0) {
        if (matrixTaxi[i][j] > max) {
            max = matrixTaxi[i][j];
        }
        --i;
        --j;
    }
    i = x + 1;
    j = y + 1;
    while (i < 10 && j < 10) {
        if (matrixTaxi[i][j] > max) {
            max = matrixTaxi[i][j];
        }
        ++i;
        ++j;
    }
    i = x;
    j = y;

    // right-to-left diagonal 
    while (i >= 0 && j < 10) {
        if (matrixTaxi[i][j] > max) {
            max = matrixTaxi[i][j];
        }
        --i;
        ++j;
    }
    i = x + 1;
    j = y - 1;
    while (i < 10 && j >= 0) {
        if (matrixTaxi[i][j] > max) {
            max = matrixTaxi[i][j];
        }
        ++i;
        --j;
    }
    cell = abs(max); 
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    if (strlen(s) < 8) {return -1;}
    if (strlen(s) > 20) {return -2;}
    
    // Get pass
    char passToCheck[strlen(s)]; 
    strcpy(passToCheck, s); 

    // Get se
    char tmpSe[strlen(email)]; 
    strcpy(tmpSe, email);

    char se[strlen(email)]; 
    int i = 0;
    while (true) {
        if (tmpSe[i] == '@') {
            break;
        }
        se[i] = tmpSe[i]; 
        ++i; 
    } 
    se[i] = '\0'; 
    int seLength = i; 

    // Check for valididity
    int seStartIdx, count = 0;
    bool found = false; 
    int j = 0, next; 
    for (int i = 0; i < (int)strlen(passToCheck); ++i) {
        // Contain se
        if (passToCheck[i] == se[j]) {
            if (found == false) {
                seStartIdx = i;
                found = true;
            }
            ++count;
            if (count == (int)seLength) {
                return (-(300 + seStartIdx)); 
            }
            ++j; 
        }
        else {
            found = false;
            count = seStartIdx = j = 0; 
        }

        // Contain Consecutive similar characters
        next = i + 1;  
        if (passToCheck[i] == passToCheck[next]) {
            return (-(400 + i));  
        }
    }

    bool specialChar = false, invalidChar = false; 
    int invalidCharIdx = 0; 
    for (int i = 0; i < (int)strlen(passToCheck); ++i) {
        if (passToCheck[i] == '@' || passToCheck[i] == '#' || passToCheck[i] == '%' || passToCheck[i] == '$' || passToCheck[i] == '!') {
            specialChar = true; 
            continue; 
        }

        if (!isdigit(passToCheck[i]) && !isalpha(passToCheck[i]) && invalidChar == false) {
            invalidCharIdx = i; 
            invalidChar = true;  
        }
    }

    if (specialChar == false) {return -5;}
    if (invalidChar == true) {return invalidCharIdx;}

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    char order_Pwds[num_pwds][1000];
    int len = 0; 
    int freq_Pwds[num_pwds]; 
    int first_Ocurrent[num_pwds]; 

    for (int i = 0; i < (int)num_pwds; i++) {
        bool same = false;
        char tmp[1000]; 
        strcpy(tmp, arr_pwds[i]);

        for (int j = 0; j < (int)len; j++) {
            if (strcmp(order_Pwds[j], tmp) == 0)
			{
				same = true;
				freq_Pwds[j]++;
				break;
			}
        }

        if (same == false) {
            strcpy(order_Pwds[i], arr_pwds[i]);
            freq_Pwds[i] = 1;
            first_Ocurrent[i] = i; 
            ++len; 
        }
    }

    int maxIndex = 0;
    for (int i = 1; i < (int)len; i++) {
        if (freq_Pwds[i] > freq_Pwds[maxIndex]) {
            maxIndex = i;
        }
        else if (freq_Pwds[i] == freq_Pwds[maxIndex]) {
            if (strlen(order_Pwds[i]) > strlen(order_Pwds[maxIndex])) {
                maxIndex = i; 
            }
        }
    }

    return first_Ocurrent[maxIndex];
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////