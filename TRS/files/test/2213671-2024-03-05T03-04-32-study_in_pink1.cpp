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

void adjustHP(int &HP) {
    const int minHP = 0;
    const int maxHP = 666;

    if (HP < minHP) {
        HP = minHP;
    } else if (HP > maxHP) {
        HP = maxHP;
    }
}

void adjustEXP(int &EXP) {
    const int minEXP = 0;
    const int maxEXP = 600;

    if (EXP < minEXP) {
        EXP = minEXP;
    } else if (EXP > maxEXP) {
        EXP = maxEXP;
    }
}

void adjustMoney(int &M) {
    const int minMoney = 0;
    const int maxMoney = 3000;

    if (M < minMoney) {
        M = minMoney;
    } else if (M > maxMoney) {
        M = maxMoney;
    }
}

bool isEven(int number) {
    return (number % 2 == 0);
}

int PerfectSquare(int n) {
    int i = 1;
    int S2 = 0;
    while(n >= S2){
        S2 = i * i;
        i++;
    }
    int S1;
    S1 = ( i -2 ) * ( i - 2 );
    if( (S2-n) < (n-S1) ) return S2;
    else return S1;
}

const int SIZE = 10;

void createMatrix(int E3, int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
}

int countValuesGreaterThanE3Times2(int matrix[SIZE][SIZE], int E3) {
    int count = 0;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (matrix[i][j] > E3 * 2) {
                count++;
            }
        }
    }

    return count;
}

int countValuesLessThanNegativeE3(int matrix[SIZE][SIZE], int E3) {
    int count = 0;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (matrix[i][j] < -E3) {
                count++;
            }
        }
    }

    return count;
}

int findTap(int matrix[SIZE][SIZE], int row, int col) {
    int x = matrix[row][col];
    for (int i = row, j = col; i < SIZE && j >= 0; ++i, --j) {
        if(matrix[i][j] >= x) x = matrix[i][j];
    }
    for (int i = row, j = col; i >= 0 && j < SIZE ; --i, ++j) {
        if(matrix[i][j] >= x) x = matrix[i][j];
    }

    for (int i = row, j = col; i < SIZE && j < SIZE; ++i, ++j) {
        if(matrix[i][j] >= x) x = matrix[i][j];
    }
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if(matrix[i][j] >= x) x = matrix[i][j];
    }
    return x;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1) {
    if(e1 <= 3) {
        if(e1 == 0) exp2 += 29;
        if(e1 == 1) exp2 += 45;
        if(e1 == 2) exp2 += 75;
        if(e1 == 3) exp2 += 149;
        int D;
        D = e1 * 3 + exp1 * 7;
        if (isEven(D)) exp1 += D / 200;
        else exp1 -= D / 100;
    } else {
        float x;
        if(e1 <= 19) {
            x = ceil(e1 / 4 + 0.49);
            exp2 = exp2 + x + 19;
        }
        if(e1 >= 20 && e1 <= 49) {
            x = ceil(e1 / 9 + 0.49);
            exp2 = exp2 + x + 21;
        }
        if(e1 >= 50 && e1 <= 65) {
            x = ceil(e1 / 16 + 0.49);
            exp2 = exp2 + x + 17;
        }
        if(e1 >= 66 && e1 <= 79) {
            x = ceil(e1 / 4 + 0.49);
            exp2 = exp2 + x + 19;
            if(exp2 > 200 ) {
                x = ceil(e1 / 9 + 0.49);
                exp2 = exp2 + x + 21;
            }
        }
        if(e1 >= 80 ) {
            x = ceil(e1 / 4 + 0.49);
            exp2 = exp2 + x + 19;
            x = ceil(e1 / 9 + 0.49);
            exp2 = exp2 + x + 21;
            if(exp2 > 400 ) {
                x = ceil(e1 / 16 + 0.49);
                exp2 = exp2 + x + 17;
                x = ceil(exp2 * 115 / 100 + 0.49);
                exp2 = x;
            }
        }
        exp1 -= e1;
    }
    adjustEXP(exp1);
    adjustEXP(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
    float x;
    double a, b;
    int nearestPerfectSquare = PerfectSquare(EXP1);
    int P1;
    if (EXP1 >= nearestPerfectSquare) {
        P1 = 100;
    } else {
        a = EXP1;
        b = nearestPerfectSquare;
        x = ((a / b + 80) / 123 + 0.0049) * 100;
        P1 = x;
    }

    if(!isEven(E2)) {
        int N = 0;
        while(N <= M1 / 2) {
        	if(N > M1 / 2) break;
            if(HP1 < 200) {
                x = ceil(HP1 * 130 / 100 );
                HP1 = x;
                N += 150;
            } else {
                x = ceil(HP1 * 110 / 100 );
                HP1 = x;
                N += 70;
            }

            if(N > M1 / 2) break;
            if(EXP1 < 400) {
                N += 200;
            } else {
                N += 120;
            }
            x = ceil(EXP1 * 113 / 100 );
            EXP1 = x;

            if(N > M1 / 2) break;
            if(EXP1 < 300) {
                N += 100;
            } else {
                N += 120;
            }
            x = ceil(EXP1 * 90 / 100 );
            EXP1 = x;
        }
        M1 = M1 - N;
    } else {
        if(M1 > 0 ) {
			if(HP1 < 200) {
            x = ceil(HP1 * 130 / 100 );
            HP1 = x;
            M1 -= 150;
        	} else {
            x = ceil(HP1 * 110 / 100 );
            HP1 = x;
            M1 -= 70;
        	}
    	}

        if(M1 > 0) {
            if(EXP1 < 400) {
                M1 -= 200;
            } else {
                M1 -= 120;
            }
            x = ceil(EXP1 * 113 / 100 );
            EXP1 = x;
        }

        if(M1 > 0) {
            if(EXP1 < 300) {
                M1 -= 100;
            } else {
                M1 -= 120;
            }
            x = ceil(EXP1 * 90 / 100 );
            EXP1 = x;
        }
    }
    x = ceil(HP1 * 83 / 100 );
    HP1 = x;
    x = ceil(EXP1 * 117 / 100 );
    EXP1 = x;

    nearestPerfectSquare = PerfectSquare(EXP1);
    int P2;
    if (EXP1 >= nearestPerfectSquare) {
        P2 = 100;
    } else {
        a = EXP1;
        b = nearestPerfectSquare;
        x = ((a / b + 80) / 123 + 0.0049) * 100;
        P2 = x;
    }

    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int arraySize = sizeof(P) / sizeof(P[0]);

    int index;

    if (E2 < 10) {
        index = E2;
    } else {
        int sum = (E2 / 10) + (E2 % 10);
        index = sum % arraySize;
    }
    int P3 = P[index];

    int O;
    O = ceil((P1 + P2 + P3) / 3 );
    if(O == 100) {
        x = ceil(EXP1 * 75 / 100 );
        EXP1 = x;
    } else if(O < 50) {
        x = ceil(HP1 * 85 / 100 );
        HP1 = x;
        x = ceil(EXP1 * 115 / 100 );
        EXP1 = x;
    } else {
        x = ceil(HP1 * 90 / 100 );
        HP1 = x;
        x = ceil(EXP1 * 120 / 100 );
        EXP1 = x;
    }

    adjustHP(HP1);
    adjustEXP(EXP1);
    adjustMoney(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    float x;
    int taxiMap[SIZE][SIZE];
    createMatrix(E3, taxiMap);
    int a = countValuesGreaterThanE3Times2(taxiMap, E3);
    int b = countValuesLessThanNegativeE3(taxiMap, E3);
    while(a >= 10) {
        a = (a / 10) + (a % 10);
    }

    while(b >= 10) {
        b = (b / 10) + (b % 10);
    }
    int Taxi = taxiMap[a][b];
    int Tap = findTap(taxiMap, a, b);

    if ( abs(Taxi) > Tap) {
        x = ceil(EXP1 * 0.88);
        EXP1 = x;
        x = ceil(HP1 * 0.9);
        HP1 = x;
        x = ceil(EXP2 * 0.88);
        EXP2 = x;
        x = ceil(HP2 * 0.9);
        HP2 = x;
        adjustHP(HP1);
        adjustEXP(EXP2);
        adjustHP(HP1);
        adjustEXP(EXP2);
        return Taxi;
    } else {
        x = ceil(EXP1 * 1.12);
        EXP1 = x;
        x = ceil(HP1 * 1.1);
        HP1 = x;
        x = ceil(EXP2 * 1.12);
        EXP2 = x;
        x = ceil(HP2 * 1.1);
        HP2 = x;
        adjustHP(HP1);
        adjustEXP(EXP2);
        adjustHP(HP1);
        adjustEXP(EXP2);
        return Tap;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    size_t atPos = 0;
    while (email[atPos] != '@' && email[atPos] != '\0') {
        atPos++;
    }

    char *se = new char[atPos + 1];
    strncpy(se, email, atPos);
    se[atPos] = '\0';

    if (strlen(s) < 8) {
        delete[] se;
        return -1;
    }
    if (strlen(s) > 20) {
        delete[] se;
        return -2;
    }

    const char *specialChars = "@#%$!";
    if (strpbrk(s, specialChars) == nullptr) {
        delete[] se;
        return -5;
    }

    const char *sePos = strstr(s, se);
    if (sePos != nullptr) {
        delete[] se;
        return -(300 + static_cast<int>(sePos - s));
    }

    for (size_t i = 0; i < strlen(s) - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            delete[] se;
            return -(400 + static_cast<int>(i));
        }
    }

    delete[] se;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int counts[num_pwds];
    int lengths[num_pwds];

    for (int i = 0; i < num_pwds; ++i) {
        counts[i] = 0;
        lengths[i] = strlen(arr_pwds[i]);
    }

    for (int i = 0; i < num_pwds; ++i) {
        for (int j = 0; j < num_pwds; ++j) {
            if (j != i && strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                counts[i]++;
            }
        }
    }

    int max_count = 0;
    int max_length = 0;
    int max_count_index = -1;

    for (int i = 0; i < num_pwds; ++i) {
        if (counts[i] > max_count || (counts[i] == max_count && lengths[i] > max_length)) {
            max_count = counts[i];
            max_length = lengths[i];
            max_count_index = i;
        }
    }

    return max_count_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////