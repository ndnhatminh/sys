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

// Functions that I declare
double limitCheckHP(double hp) {
    if (hp > 666) return 666;
    else if (hp < 0) return 0;
    else return hp;
}

double limitCheckEXP(double exp) {
    if (exp > 600) return 600;
    else if (exp < 0) return 0;
    else return exp;
}

double limitCheckM(double m) {
    if (m > 3000) return 3000;
    else if (m < 0) return 0;
    else return m;
}

double initialLimitCheckHP(int hp) {
    if (hp > 666) return 666;
    else if (hp < 0) return 0;
    else return hp;
}

double initialLimitCheckEXP(int exp) {
    if (exp > 600) return 600;
    else if (exp < 0) return 0;
    else return exp;
}

double initialLimitCheckM(int m) {
    if (m > 3000) return 3000;
    else if (m < 0) return 0;
    else return m;
}

bool limitCheckE(int e) {
    if (e < 0 || e > 99) return true;
    else return false;
}

int squareNumber(int exp1) {
    double remainder = sqrt(exp1) - floor(sqrt(exp1));
    if (remainder <= 0.5) return (floor(sqrt(exp1)) * floor(sqrt(exp1)));
    else return (ceil(sqrt(exp1)) * ceil(sqrt(exp1)));
}

bool moneySpentCheck(double moneySpent, double initialMoney) {
    if (moneySpent > 0.5*initialMoney) return true;
    else return false;
}

int maxEntry(int array[10][10], int i, int j) {
    int max = array[i][j], temporaryi = i, temporaryj = j;
    while (temporaryi > 0 && temporaryj > 0) {
        temporaryi -= 1;
        temporaryj -= 1;
        if (array[temporaryi][temporaryj] >= max) max = array[temporaryi][temporaryj];
    }
    temporaryi = i;
    temporaryj = j;
    while (temporaryi <9 && temporaryj < 9) {
        temporaryi += 1;
        temporaryj += 1;
        if (array[temporaryi][temporaryj] >= max) max = array[temporaryi][temporaryj];
    }
    temporaryi = i;
    temporaryj = j;
    while (temporaryi > 0 && temporaryj < 9) {
        temporaryi -= 1;
        temporaryj += 1;
        if (array[temporaryi][temporaryj] >= max) max = array[temporaryi][temporaryj];
    }
    temporaryi = i;
    temporaryj = j;
    while (temporaryi < 9 && temporaryj > 0) {
        temporaryi += 1;
        temporaryj -= 1;
        if (array[temporaryi][temporaryj] >= max) max = array[temporaryi][temporaryj];
    }
    temporaryi = i;
    temporaryj = j;
    return abs(max);
}  
// The end of my functions section

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    double temporaryEXP1 = initialLimitCheckEXP(exp1), temporaryEXP2 = initialLimitCheckEXP(exp2), temporaryE1 = e1;
    if (limitCheckE(e1)) return -99;
    if (temporaryE1 >= 0 && temporaryE1 <= 3) {
        if (temporaryE1 == 0) {
            temporaryEXP2 += 29;
            temporaryEXP2 = limitCheckEXP(temporaryEXP2);
        }
        else if (temporaryE1 == 1) {
            temporaryEXP2 += 45;
            temporaryEXP2 = limitCheckEXP(temporaryEXP2);
        }
        else if (temporaryE1 == 2) {
            temporaryEXP2 += 75;
            temporaryEXP2 = limitCheckEXP(temporaryEXP2);
        }
        else if (temporaryE1 == 3) {
            temporaryEXP2 += 29 + 45 + 75;
            temporaryEXP2 = limitCheckEXP(temporaryEXP2);
        }
        int d = temporaryE1 * 3 + temporaryEXP1 * 7;
        if ((d % 2) == 0) {
            temporaryEXP1 += d/200.0;
            temporaryEXP1 = ceil(temporaryEXP1);
            temporaryEXP1 = limitCheckEXP(temporaryEXP1);
        }

        else if ((d % 2) == 1) {
            temporaryEXP1 -= d/100.0;
            temporaryEXP1 = ceil(temporaryEXP1);
            temporaryEXP1 = limitCheckEXP(temporaryEXP1);
        }

    }

    if (temporaryE1 >= 4 && temporaryE1 <= 99) {
        if (temporaryE1 >= 4 && temporaryE1 <= 19) {
            temporaryEXP2 += temporaryE1/4 + 19;
            temporaryEXP2 = ceil(temporaryEXP2);
            temporaryEXP2 = limitCheckEXP(temporaryEXP2);
        }
        else if (temporaryE1 >= 20 && temporaryE1 <= 49) {
            temporaryEXP2 += temporaryE1/9 + 21;
            temporaryEXP2 = ceil(temporaryEXP2);
            temporaryEXP2 = limitCheckEXP(temporaryEXP2);
        }
        else if (temporaryE1 >= 50 && temporaryE1 <= 65) {
            temporaryEXP2 += temporaryE1/16 + 17;
            temporaryEXP2 = ceil(temporaryEXP2);
            temporaryEXP2 = limitCheckEXP(temporaryEXP2);
        }
        else if (temporaryE1 >= 66 && temporaryE1 <= 79) {
            temporaryEXP2 += temporaryE1/4 + 19;
            temporaryEXP2 = ceil(temporaryEXP2);
            temporaryEXP2 = limitCheckEXP(temporaryEXP2);

            if (temporaryEXP2 > 200) {
                temporaryEXP2 += temporaryE1/9 + 21;
                temporaryEXP2 = ceil(temporaryEXP2);
                temporaryEXP2 = limitCheckEXP(temporaryEXP2);
            }
        }
        else if (temporaryE1 >= 80 && temporaryE1 <= 99) {
            temporaryEXP2 += temporaryE1/4 + 19;
            temporaryEXP2 = ceil(temporaryEXP2);
            temporaryEXP2 = limitCheckEXP(temporaryEXP2);
            temporaryEXP2 += temporaryE1/9 + 21;
            temporaryEXP2 = ceil(temporaryEXP2);
            temporaryEXP2 = limitCheckEXP(temporaryEXP2);
            if (temporaryEXP2 > 400) {
                temporaryEXP2 += temporaryE1/16 + 17;
                temporaryEXP2 = ceil(temporaryEXP2);
                temporaryEXP2 = limitCheckEXP(temporaryEXP2);
                temporaryEXP2 += 0.15 * temporaryEXP2;
                temporaryEXP2 = ceil(temporaryEXP2);    
                temporaryEXP2 = limitCheckEXP(temporaryEXP2);
            }
        }
        temporaryEXP1 -= temporaryE1;
        temporaryEXP1 = limitCheckEXP(temporaryEXP1);
        
    }
    exp1 = temporaryEXP1;
    exp2 = temporaryEXP2;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // Declaring double variables to avoid automatic round down of integers
    double temporaryHP1 = limitCheckHP(HP1), temporaryEXP1 = limitCheckEXP(EXP1), temporaryM1 = limitCheckM(M1), temporaryE2 = E2;
    if (limitCheckE(E2)) return -99;

    // Road 01
    double P1;
    if (temporaryEXP1 >= squareNumber(temporaryEXP1)) P1 = 1;
    else P1 = (temporaryEXP1/squareNumber(temporaryEXP1)+80)/123;
    
    // Road 02
    double P2, moneySpent = 0, initialMoney = temporaryM1;
    if (E2 % 2 == 1) {
        while (E2 % 2 == 1) {
            if (temporaryHP1 < 200 && temporaryM1 > 0) {
                temporaryHP1 += 0.3 * temporaryHP1;
                temporaryHP1 = ceil(temporaryHP1);
                temporaryHP1 = limitCheckHP(temporaryHP1);
                temporaryM1 -= 150;
                temporaryM1 = limitCheckM(temporaryM1);
                moneySpent += 150;
                if (moneySpentCheck(moneySpent, initialMoney)) break;
            }
            else if (temporaryHP1 >= 200 && temporaryM1 > 0) {
                temporaryHP1 += 0.1 * temporaryHP1;
                temporaryHP1 = ceil(temporaryHP1);
                temporaryHP1 = limitCheckHP(temporaryHP1);
                temporaryM1 -= 70;
                temporaryM1 = limitCheckM(temporaryM1);
                moneySpent += 70;
                if (moneySpentCheck(moneySpent, initialMoney)) break;
            }
            if (temporaryEXP1 < 400 && temporaryM1 > 0) {
                temporaryM1 -= 200;
                temporaryM1 = limitCheckM(temporaryM1);
                moneySpent += 200;
                temporaryEXP1 += 0.13 * temporaryEXP1;
                temporaryEXP1 = ceil(temporaryEXP1);
                temporaryEXP1 = limitCheckEXP(temporaryEXP1);
                if (moneySpentCheck(moneySpent, initialMoney)) break;
            }
            else if (temporaryEXP1 >= 400 && temporaryM1 > 0) {
                temporaryM1 -= 120;
                temporaryM1 = limitCheckM(temporaryM1);
                moneySpent += 120;
                temporaryEXP1 += 0.13 * temporaryEXP1;
                temporaryEXP1 = ceil(temporaryEXP1);
                temporaryEXP1 = limitCheckEXP(temporaryEXP1);
                if (moneySpentCheck(moneySpent, initialMoney)) break;
            }
            if (temporaryEXP1 < 300 && temporaryM1 > 0) {
                temporaryM1 -= 100;
                temporaryM1 = limitCheckM(temporaryM1);
                moneySpent += 100;
                temporaryEXP1 -= 0.1 * temporaryEXP1;
                temporaryEXP1 = ceil(temporaryEXP1);
                temporaryEXP1 = limitCheckEXP(temporaryEXP1);
                if (moneySpentCheck(moneySpent, initialMoney)) break;
            }
            else if (temporaryEXP1 >= 300 && temporaryM1 > 0) {
                temporaryM1 -= 120;
                temporaryM1 = limitCheckM(temporaryM1);
                moneySpent += 120;
                temporaryEXP1 -= 0.1 * temporaryEXP1;
                temporaryEXP1 = ceil(temporaryEXP1);
                temporaryEXP1 = limitCheckEXP(temporaryEXP1);
                if (moneySpentCheck(moneySpent, initialMoney)) break;
            }
        }
        temporaryHP1 -= 0.17 * temporaryHP1;
        temporaryHP1 = ceil(temporaryHP1);
        temporaryHP1 = limitCheckHP(temporaryHP1);
        temporaryEXP1 += 0.17 * temporaryEXP1;
        temporaryEXP1 = ceil(temporaryEXP1);
        temporaryEXP1 = limitCheckEXP(temporaryEXP1);
    }

    if (E2 % 2 == 0) {
        if (temporaryHP1 < 200 && temporaryM1 > 0) {
            temporaryHP1 += 0.3 * temporaryHP1;
            temporaryHP1 = ceil(temporaryHP1);
            temporaryHP1 = limitCheckHP(temporaryHP1);
            temporaryM1 -= 150;
            temporaryM1 = limitCheckM(temporaryM1);
        }
        else if (temporaryHP1 >= 200 && temporaryM1 > 0) {
            temporaryHP1 += 0.1 * temporaryHP1;
            temporaryHP1 = ceil(temporaryHP1);
            temporaryHP1 = limitCheckHP(temporaryHP1);
            temporaryM1 -= 70;
            temporaryM1 = limitCheckM(temporaryM1);
        }
        if (temporaryEXP1 < 400 && temporaryM1 > 0) {
            temporaryM1 -= 200;
            temporaryM1 = limitCheckM(temporaryM1);
            temporaryEXP1 += 0.13 * temporaryEXP1;
            temporaryEXP1 = ceil(temporaryEXP1);
            temporaryEXP1 = limitCheckEXP(temporaryEXP1);
        }
        else if (temporaryEXP1 >= 400 && temporaryM1 > 0) {
            temporaryM1 -= 120;
            temporaryM1 = limitCheckM(temporaryM1);
            temporaryEXP1 += 0.13 * temporaryEXP1;
            temporaryEXP1 = ceil(temporaryEXP1);
            temporaryEXP1 = limitCheckEXP(temporaryEXP1);
        }
        if (temporaryEXP1 < 300 && temporaryM1 > 0) {
            temporaryM1 -= 100;
            temporaryM1 = limitCheckM(temporaryM1);
            temporaryEXP1 -= 0.1 * temporaryEXP1;
            temporaryEXP1 = ceil(temporaryEXP1);
            temporaryEXP1 = limitCheckEXP(temporaryEXP1);
        }
        else if (temporaryEXP1 >= 300 && temporaryM1 > 0) {
            temporaryM1 -= 120;
            temporaryM1 = limitCheckM(temporaryM1);
            temporaryEXP1 -= 0.1 * temporaryEXP1;
            temporaryEXP1 = ceil(temporaryEXP1);
            temporaryEXP1 = limitCheckEXP(temporaryEXP1);
        }
        temporaryHP1 -= 0.17 * temporaryHP1;
        temporaryHP1 = ceil(temporaryHP1);
        temporaryHP1 = limitCheckHP(temporaryHP1);
        temporaryEXP1 += 0.17 * temporaryEXP1;
        temporaryEXP1 = ceil(temporaryEXP1);
        temporaryEXP1 = limitCheckEXP(temporaryEXP1);
    }
    if (temporaryEXP1 >= squareNumber(temporaryEXP1)) P2 = 1;
    else P2 = (temporaryEXP1/squareNumber(temporaryEXP1)+80)/123;

    // Road 03
    double P3;
    int firstNum = 0, secondNum = 0, sum = 0;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}, i;
    if (temporaryE2 < 10) {
        i = temporaryE2;
        P3 = P[i]/100.0;
    }
    else if (temporaryE2 >= 10) {
        firstNum = E2 / 10;
        secondNum = E2 % 10;
        sum = firstNum + secondNum;
        if (sum < 10) {
            i = sum;
            P3 = P[i]/100.0;
        }
        else if (sum >= 10) {
            i = sum % 10;
            P3 = P[i]/100.0;
        }
    }
    // After 3 roads
    double averageOfProbability = (P1 + P2 + P3) / 3;
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        temporaryEXP1 -= 0.25 * temporaryEXP1;
        temporaryEXP1 = ceil(temporaryEXP1);
        temporaryEXP1 = limitCheckEXP(temporaryEXP1);
    }
    else {
        if (averageOfProbability < 0.5) {
            temporaryHP1 -= 0.15 * temporaryHP1;
            temporaryHP1 = ceil(temporaryHP1);
            temporaryHP1 = limitCheckHP(temporaryHP1);
            temporaryEXP1 += 0.15 * temporaryEXP1;
            temporaryEXP1 = ceil(temporaryEXP1);
            temporaryEXP1 = limitCheckEXP(temporaryEXP1);
        }
        else if (averageOfProbability >= 0.5) {
            temporaryHP1 -= 0.1 * temporaryHP1;
            temporaryHP1 = ceil(temporaryHP1);
            temporaryHP1 = limitCheckHP(temporaryHP1);
            temporaryEXP1 += 0.2 * temporaryEXP1;
            temporaryEXP1 = ceil(temporaryEXP1);
            temporaryEXP1 = limitCheckEXP(temporaryEXP1);
        }
    }
    HP1 = temporaryHP1;
    EXP1 = temporaryEXP1;
    M1 = temporaryM1;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    double temporaryHP1 = initialLimitCheckHP(HP1), temporaryEXP1 = initialLimitCheckEXP(EXP1), temporaryHP2 = initialLimitCheckHP(HP2), temporaryEXP2 = initialLimitCheckEXP(EXP2);
    if (limitCheckE(E3)) return -99;
    int taxiRoute[10][10], sherlockAndWatsonRoute[10][10];;
    // Initializing a matrix for the taxi route
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxiRoute[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // Initializing a matrix for Sherlock and Watson
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            sherlockAndWatsonRoute[x][y] = maxEntry(taxiRoute, x, y);
        }
    }

    // Counting the number of entries in the matrix
    int meeti = 0, meetj = 0;
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            if (taxiRoute[a][b] > (E3*2)) meeti += 1;
            if (taxiRoute[a][b] < -E3) meetj += 1;
        }
    }

    int firstNum, secondNum;
    while (meeti >= 10) {
        firstNum = meeti / 10.0;
        secondNum = meeti % 10;
        meeti = firstNum + secondNum;
    }
    while (meetj >= 10) {
        firstNum = meetj / 10;
        secondNum = meetj % 10;
        meetj = firstNum + secondNum;
    }

    if (abs(taxiRoute[meeti][meetj]) > sherlockAndWatsonRoute[meeti][meetj]) {
        temporaryEXP1 -= 0.12 * temporaryEXP1;
        temporaryEXP1 = ceil(temporaryEXP1);
        temporaryEXP1 = limitCheckEXP(temporaryEXP1);
        EXP1 = temporaryEXP1;
        temporaryHP1 -= 0.1 * temporaryHP1;
        temporaryHP1 = ceil(temporaryHP1);
        temporaryHP1 = limitCheckHP(temporaryHP1);
        HP1 = temporaryHP1;
        temporaryEXP2 -= 0.12 * temporaryEXP2;
        temporaryEXP2 = ceil(temporaryEXP2);
        temporaryEXP2 = limitCheckEXP(temporaryEXP2);
        EXP2 = temporaryEXP2;
        temporaryHP2 -= 0.1 * temporaryHP2;
        temporaryHP2 = ceil(temporaryHP2);
        temporaryHP2 = limitCheckHP(temporaryHP2);
        HP2 = temporaryHP2;
        return taxiRoute[meeti][meetj];
    }

    else {
        temporaryEXP1 += 0.12 * temporaryEXP1;
        temporaryEXP1 = ceil(temporaryEXP1);
        temporaryEXP1 = limitCheckEXP(temporaryEXP1);
        EXP1 = temporaryEXP1;
        temporaryHP1 += 0.1 * temporaryHP1;
        temporaryHP1 = ceil(temporaryHP1);
        temporaryHP1 = limitCheckHP(temporaryHP1);
        HP1 = temporaryHP1;
        temporaryEXP2 += 0.12 * temporaryEXP2;
        temporaryEXP2 = ceil(temporaryEXP2);
        temporaryEXP2 = limitCheckEXP(temporaryEXP2);
        EXP2 = temporaryEXP2;
        temporaryHP2 += 0.1 * temporaryHP2;
        temporaryHP2 = ceil(temporaryHP2);
        temporaryHP2 = limitCheckHP(temporaryHP2);
        HP2 = temporaryHP2;
        return sherlockAndWatsonRoute[meeti][meetj];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int i = 0;
    char se[100];
    while (email[i] != '@') {
        i++;
    }
    if (email[i] == '@') {
        for (int j = 0; j < i; j++) {
            se[j] = email[j];
        }
        se[i] = '\0';
    }
    if (strlen(s) < 8) return -1;
    if (strlen(s) > 20) return -2;

    int y = 0;
    // Detecting se
    for (int x = 0; x < strlen(s); x++) {
        if (s[x] == se[0]) {
            while (y < strlen(se) && s[x+y] == se[y]) {
                y++;
            }
            if (y == strlen(se))  {
                return -(300 + x);
            }
        }
    }
    for (int z = 0; z < strlen(s) - 1; z++) {
        if (s[z] == s[z+1] && s[z+1] == s[z+2]) {
            return -(400 + z);
        }
    }
    
    int a = 0;
    while (a < strlen(s) && (s[a] != '@' || s[a] != '!' || s[a] != '#' || s[a] != '$' || s[a] != '%')) {
        if (s[a] == '@' || s[a] == '!' || s[a] == '#' || s[a] == '$' || s[a] == '%') break;
        a++;
    }
    if (a == strlen(s)) return -5;
    int b;
    for (b = 0; b < strlen(s); b++) {
        if ((s[b] < 48 || s[b] > 57) && (s[b] < 65 || s[b] > 90) && (s[b] < 97 || s[b] > 122)) 
            if (s[b] != 33 && s[b] != 35 && s[b] != 36 && s[b] != 37 && s[b] != 64 ) break;
    }
    if (b < strlen(s)) return b; 
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int count, mostFrequent = 0, positionOfMostFrequent, longestPwd = 0;
    for (int i = 0; i < num_pwds; i++) {
        count = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (arr_pwds[i] == arr_pwds[j]) count += 1;
        }
        if (count > mostFrequent) {
            longestPwd = strlen(arr_pwds[i]);
            mostFrequent = count;
            positionOfMostFrequent = i;
        }
        if (count == mostFrequent && strlen(arr_pwds[i]) > longestPwd) {
            longestPwd = strlen(arr_pwds[i]);
            positionOfMostFrequent = i;
        }
    }
    return positionOfMostFrequent;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////