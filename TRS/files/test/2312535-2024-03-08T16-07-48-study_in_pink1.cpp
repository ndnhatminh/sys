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

// Các hàm điều kiện
int checkexp(int &exp) {
    if (exp > 600) { exp = 600;}
    if (exp < 0) { exp = 0;}
    return exp;
}

int checkHP(int &HP) {
    if (HP > 666) { HP = 666;}
    if (HP < 0) { HP = 0;}
    return HP;
}

int checkM(int &M) {
    if (M > 3000) { M = 3000;}
    if (M < 0) { M = 0;}
    return M;
} 

// Task1
    int firstMeet(int & exp1, int & exp2, int e1) {
    checkexp(exp1);
    checkexp(exp2);
    if (e1 < 0 || e1 > 99) return -99;

    if (e1 >= 0 && e1 <= 3) {
        int D;
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
            case 3:
                exp2 += (29 + 45 + 75);
                break;
        }
        checkexp(exp2);        
        
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = ceil(exp1 + D / 200.0);            
        } else {
            exp1 = ceil(exp1 - D / 100.0);
        }
        checkexp(exp1);
        return exp1 + exp2;               
    }

    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 += ceil((e1 / 4.0) + 19.0);
            checkexp(exp2);
        } 
        else if (e1 >= 20 && e1 <= 49) {
            exp2 += ceil((e1 / 9.0) + 21.0);
            checkexp(exp2);
        } 
        else if (e1 >= 50 && e1 <= 65) {
            exp2 += ceil((e1 / 16.0) + 17.0);
            checkexp(exp2);
        } 
        else if (e1 >= 66 && e1 <= 79) {
            exp2 += ceil((e1 / 4.0) + 19.0);
            checkexp(exp2);
            if (exp2 > 200) {
                exp2 += ceil((e1 / 9.0) + 21.0);
                checkexp(exp2);
            }
        } 
        else if (e1 >= 80 && e1 <= 99) {
            exp2 += ceil((e1 / 4.0) + 19.0) + ceil((e1 / 9.0) + 21.0);
            checkexp(exp2);
            if (exp2 > 400) {
                exp2 = ceil(exp2 + (e1 / 16.0) + 17.0);
                checkexp(exp2);
                // Sherlock giải thích cả 3 thông tin nên Watson được cộng thêm 15%
                exp2 = ceil(1.15 * exp2);
            } 
        }
        checkexp(exp2);
        exp1 = ceil(exp1 - e1);
        checkexp(exp1);
    }    
    return exp1 + exp2;
}

// Task 2
double calculateP1(int &HP1, int &EXP1) {
    checkHP(HP1);
    checkexp(EXP1);

    int S = 0;
    if (sqrt(EXP1) == int(sqrt(EXP1))) {
        S = EXP1;
    } else {
        int nextSquare = (int(sqrt(EXP1)) + 1) * (int(sqrt(EXP1)) + 1);
        int prevSquare = (int(sqrt(EXP1)) - 1) * (int(sqrt(EXP1)) - 1);
        if (nextSquare - EXP1 < EXP1 - prevSquare) S = nextSquare;
        else  S = prevSquare;
    }
    return S;
    
    double P1 = 0.0;
    if (EXP1 >= S) {
        P1 = 1.0;
    } else {
        P1 = (EXP1 / S + 80.0) / 123.0;
    }
    return P1;
}
   
double calculateP2(int &HP1, int &EXP1, int &M1, int E2) {
    checkHP(HP1);
    checkexp(EXP1);
    checkM(M1);
    if (E2 < 0 || E2 > 99) return -99;

    double P2 = 0.0;
    double MoB = M1 * 0.5;
    int Mpay = 0; 

    if (E2 % 2 == 0)
    {
        while (M1 > 0) {
        if (HP1 < 200) {
            HP1 = ceil(HP1 * 1.3);
            M1 -= 150;
        } else {
            HP1 = ceil(HP1 * 1.1);
            M1 -= 70;
        }
        checkHP(HP1);
        checkM(M1);
        if (M1 == 0) break;

        if (EXP1 < 400) {            
            M1 -= 200;
        } else {
            M1 -= 120;
        }
        EXP1 = ceil(EXP1 * 1.13);
        checkexp(EXP1);
        checkM(M1);
        if (M1 == 0) break;

        if (EXP1 < 300) {
            M1 -= 100;
        } else {
            M1 -= 120;
        }
        EXP1 = ceil(EXP1 * 0.9);
        checkexp(EXP1);
        checkM(M1);
        if (M1 == 0) break;
        break;
    }
    HP1 = ceil(HP1 - HP1 * 0.17);
    EXP1 = ceil(EXP1 + EXP1 * 0.17);
    checkHP(HP1);
    checkexp(EXP1);
    } else {
        while (M1 > 0) {
        if (HP1 < 200) {
            HP1 = ceil(HP1 * 1.3);
            M1 -= 150;
            Mpay += 150;
        } else {
            HP1 = ceil(HP1 * 1.1);
            M1 -= 70;
            Mpay += 70;
        }
        checkHP(HP1);
        checkM(M1);
        if (Mpay > MoB) {
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            checkHP(HP1);
            checkexp(EXP1);
            break;
        }
        checkM(M1);

        if (EXP1 < 400) {            
            M1 -= 200;
            Mpay += 200;
        } else {
            M1 -= 120;
            Mpay += 120;
        }
        EXP1 = ceil(EXP1 * 1.13);
        checkexp(EXP1);
        checkM(M1);
        if (Mpay > MoB) {
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            checkHP(HP1);
            checkexp(EXP1);
            break;
        }
        checkM(M1);

        if (EXP1 < 300) {
            M1 -= 100;
            Mpay += 100;
        } else {
            M1 -= 120;
            Mpay += 120;            
        }
        EXP1 = ceil(EXP1 * 0.9);
        checkexp(EXP1);
        checkM(M1);
        if (Mpay > MoB) {
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            checkHP(HP1);
            checkexp(EXP1);
            break;
        }
        checkM(M1);
    }
    }
    checkHP(HP1);
    checkexp(EXP1);

    P2 = calculateP1(HP1, EXP1);
    return P2;
}

double calculateP3(int &EXP1, int E2) {
    if (E2 < 0 || E2 > 99) return -99;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 < 10) {
        i = E2;
    } else {
        int sum = E2 / 10 + E2 % 10;
        i = sum % 10;
    }
    return P[i] / 100.0;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99) return -99;
    double P[3];
    P[0] = calculateP1(HP1, EXP1);
    P[1] = calculateP2(HP1, EXP1, M1, E2);
    P[2] = calculateP3(EXP1, E2);

    if (P[0] + P[1] + P[2] == 3.0) {
        EXP1 = ceil(EXP1 * 0.75);
        checkexp(EXP1);
    } else {
        double avgP = (P[0] + P[1] + P[2]) / 3.0;
        if (avgP < 0.5) {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        } else {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
        }
    }
    checkHP(HP1);
    checkexp(EXP1);

    return EXP1 + HP1 + M1;
}

// Task 3
const int matrixSize = 10;
void initializeTaxiMatrix(int taxiMatrix[matrixSize][matrixSize], int E3) {  
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            taxiMatrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
}

int leftDiagonalMax(int taxiMatrix[matrixSize][matrixSize], int i, int j) {
    int maxVal = taxiMatrix[i][j];
    while (i < matrixSize && j < matrixSize) {
        maxVal = max(maxVal, taxiMatrix[i][j]);
        ++i;
        ++j;
    }
    return maxVal;
}

int rightDiagonalMax(int taxiMatrix[matrixSize][matrixSize], int i, int j) {
    int maxVal = taxiMatrix[i][j];
    while (i < matrixSize && j >= 0) {
        maxVal = max(maxVal, taxiMatrix[i][j]);
        ++i;
        --j;
    }
    return maxVal;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {

    if (E3 < 0 || E3 > 99) return -99;
    int result = 0;
    int i = 0, j = 0;
    int taxiMatrix[matrixSize][matrixSize];
    initializeTaxiMatrix(taxiMatrix, E3);

    for (int k = 0; k < 10; k++) {
      for (int l = 0; l < 10; l++) {
        if (taxiMatrix[k][l] > E3 * 2) {
          i++;
        }
      }
    }

    for (int k = 0; k < 10; k++) {
        for (int l = 0; l < 10; l++) {
            if (taxiMatrix[k][l] < -E3) {
                j++;
            }
        }
    }
    while (i >= 10) {
        int sum = 0;
        while (i > 0) {
            sum += i % 10;
            i /= 10;
        }
    i = sum;
    }

    while (j >= 10) {
        int sum = 0;
        while (j > 0) {
            sum += j % 10;
            j /= 10;
        }
    j = sum;
    }
    
    int left = leftDiagonalMax(taxiMatrix, i, j);
    int right = rightDiagonalMax(taxiMatrix, i, j);
    int meetScore = abs(max(left,right)); 

    // Cập nhật EXP và HP tương ứng
    if (abs(taxiMatrix[i][j]) > meetScore) {
        EXP1 = ceil(EXP1 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        EXP2 = ceil(EXP2 * 0.88);
        HP2 = ceil(HP2 * 0.9);
        result = taxiMatrix[i][j];
    } else {
        EXP1 = ceil(EXP1 * 1.12);
        HP1 = ceil(HP1 + HP1 * 0.1);
        EXP2 = ceil(EXP2 * 1.12);
        HP2 = ceil(HP2 + HP2 * 0.1);
        result = meetScore;
    }
    checkexp(EXP1);
    checkexp(EXP2);
    checkHP(HP1);
    checkHP(HP2);
    return result;
}
 
// Task 4
int checkPassword(const char *s, const char *email) {

    int len = strlen(s);
    if (len < 8) return -1; 
    if (len > 20) return -2; 

    int emailLen = strlen(email);
    int seLength = 0;
    while (seLength < emailLen && email[seLength] != '@') {
        seLength++;
    }
    char se[101];
    strncpy(se, email, seLength);
    se[seLength] = '\0';

    const char *pos = strstr(s, se);
    if (pos != nullptr) {
        return -(300 + (pos - s)); 
    }

    for (int i = 0; i < len - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i); 
        }
    }

    bool hasSpecialChar = false;
    for (int i = 0; i < len; ++i) {
        char c = s[i];
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) return -5; 

    for (int i = 0; i < len; ++i) {
        char c = s[i];

        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
              (c == '@' || c == '#' || c == '%' || c == '$' || c == '!'))) {
            return i; 
        }
    }

    return -10; 
}

// Task 5

int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    int maxCount = 0; 
    int maxLength = 0; 
    int index = -1; 

    int count[30] = {0};

    for (int i = 0; i < num_pwds; ++i) {
        int len = strlen(arr_pwds[i]);
        int currentCount = 1; 
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                currentCount++; 
            }
        }
        if (currentCount > maxCount || (currentCount == maxCount && len > maxLength)) {
            maxCount = currentCount;
            maxLength = len;
            index = i;
        }
    }
    return index;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////