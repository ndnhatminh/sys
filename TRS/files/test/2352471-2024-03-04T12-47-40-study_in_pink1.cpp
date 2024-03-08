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

// Basic function
double ceil(double num) {
    return (int)num == num ? (int)num : (int)num + 1;
}

double floor(double num) {
    return (int)num;
}

int max(int a, int b) {
    return a > b ? a : b;
}

void setHP(int &HP, int value) {
    HP = value;
    if (HP > 666) {
        HP = 666;
    } else if (HP < 0) {
        HP = 0;
    }
}

void setEXP(int &EXP, int value) {
    EXP = value;
    if (EXP > 600) {
        EXP = 600;
    } else if (EXP < 0) {
        EXP = 0;
    }
}

void setMoney(int &Money, int value) {
    Money = value;
    if (Money > 3000) {
        Money = 3000;
    } else if (Money < 0) {
        Money = 0;
    }
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1) {
    if (0 <= e1 && e1 <= 3) {
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
            default:
                break;
        }

        int D = e1*3 + exp1*7;
        if (D % 2 == 0) {
            exp1 += ceil(D/200.0);
        } else {
            exp1 = ceil(exp1 - D/100.0);
        }
    }

    if (4 <= e1 && e1 <= 99) {
        if (4 <= e1 && e1 <= 19) {
            exp2 += ceil(e1/4.0 + 19);
        }
        if (20 <= e1 && e1 <= 49) {
            exp2 += ceil(e1/9.0 + 21);
        }
        if (50 <= e1 && e1 <= 65) {
            exp2 += ceil(e1/16.0 + 17);
        }
        if (66 <= e1 && e1 <= 79) {
            exp2 += ceil(e1/4.0 + 19);
            if (exp2 > 200) {
                exp2 += ceil(e1/9.0 + 21);
            }
        }
        if (80 <= e1 && e1 <= 99) {
            exp2 += ceil(e1/4.0 + 19);
            exp2 += ceil(e1/9.0 + 21);
            if (exp2 > 400) {
                exp2 += ceil(e1/16.0 + 17);
                exp2 += ceil(0.15 * exp2);
            }
        }
        exp1 -= e1;
    }

    exp1 = exp1 > 600 ? 600 : exp1 < 0 ? 0 : exp1;
    exp2 = exp2 > 600 ? 600 : exp2 < 0 ? 0 : exp2;

    return exp1 + exp2;
}

// Task 2
bool isPerfect(int N) {
    if ((sqrt(N) - floor(sqrt(N))) != 0) {
        return false;
    };
    return true;
}

int getClosestPerfectSquare(int N) {
    if (isPerfect(N)) {
        return N;
    }

    // Variables to store first perfect
    // square number
    // above and below N
    int aboveN = -1, belowN = -1;
    int n1;

    // Finding first perfect square
    // number greater than N
    n1 = N + 1;
    while (true) {
        if (isPerfect(n1)) {
            aboveN = n1;
            break;
        }
        else {
            n1++;
        }
    }
    //TODO: Optimize

    // Finding first perfect square
    // number less than N
    n1 = N - 1;
    while (true) {
        if (isPerfect(n1)) {
            belowN = n1;
            break;
        }
        else {
            n1--;
        }
    }

    // Variables to store the differences
    int diff1 = aboveN - N;
    int diff2 = N - belowN;

    if (diff1 > diff2) {
        return belowN;
    } else {
        return aboveN;
    }
}

float calculateProbability(int EXP1) {
    float S = getClosestPerfectSquare(EXP1);
    float P;

    if (EXP1 >= S) {
        P = 1;
    } else {
        P = (EXP1/S + 80)/123;
    }
    return P;
}

int digitCounter(int N) {
    int count = 0;
    while (N != 0) {
        N /= 10;
        count++;
    }
    return count;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    float P1;

    // Road 1
    P1 = calculateProbability(EXP1);

    // Road 2
    if (E2 % 2 == 1) {
        bool finishedAllEvents = false;
        int paidMoney = 0;
        int initialMoney = M1;
        do {
            if (HP1 < 200) {
                setHP(HP1, (HP1 + ceil(0.3*HP1)));
                setMoney(M1, (M1 - 150));
                paidMoney += 150;
            } else {
                setHP(HP1, (HP1 + ceil(0.1 * HP1)));
                setMoney(M1, (M1 - 70));
                paidMoney += 70;
            }

            if (paidMoney >= initialMoney * 0.5) break;

            if (EXP1 < 400) {
                setMoney(M1, (M1 - 200));
                paidMoney += 200;
            } else {
                setMoney(M1, (M1 - 120));
                paidMoney += 120;
            }
            setEXP(EXP1, (EXP1 + ceil(EXP1*0.13)));

            if (paidMoney >= initialMoney * 0.5) break;

            if (EXP1 < 300) {
                setMoney(M1, (M1 - 100));
                paidMoney += 100;
            } else {
                setMoney(M1, (M1 - 120));
                paidMoney += 120;
            }
            setEXP(EXP1, (ceil(EXP1 - EXP1*0.1)));

            if (paidMoney >= initialMoney * 0.5) break;
        }
        while (true);
    } else {
        bool finishedAllEvents = false;
        do {
            if (HP1 < 200) {
                setHP(HP1, (HP1 + ceil(0.3*HP1)));
                setMoney(M1, (M1 - 150));
            } else {
                setHP(HP1, (HP1 + ceil(0.1*HP1)));
                setMoney(M1, (M1 - 70));
            }

            if (M1 <= 0) break;

            if (EXP1 < 400) {
                setMoney(M1, (M1 - 200));
            } else {
                setMoney(M1, (M1 - 120));
            }
            setEXP(EXP1, (EXP1 + ceil(EXP1*0.13)));

            if (M1 <= 0) break;

            if (EXP1 < 300) {
                setMoney(M1, (M1 - 100));
            } else {
                setMoney(M1, (M1 - 120));
            }

            setEXP(EXP1, (ceil(EXP1 - EXP1*0.1)));
            finishedAllEvents = true;
        } while (M1 >= 0 && !finishedAllEvents);
    }

    setHP(HP1, ceil(HP1 - 0.17*HP1));
    setEXP(EXP1, (EXP1 + ceil(EXP1*0.17)));

    float P2 = calculateProbability(EXP1);

    // Road 3
    float P3;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (digitCounter(E2) == 1) {
        P3 = P[E2];
    } else if (digitCounter(E2) == 2) {
        int index = (E2/10 + E2%10) %10;
        P3 = P[index]/100.0;
    }

    if (P1*P2*P3 != 1) {
        float averageProberbility = (P1 + P2 + P3)/3;
        if (averageProberbility < 0.5) {
            setHP(HP1, ceil(HP1 - 0.15*HP1));
            setEXP(EXP1, (EXP1 + ceil(0.15*EXP1)));
        } else {
            setHP(HP1, ceil(HP1 - 0.1*HP1));
            setEXP(EXP1, (EXP1 + ceil(0.2*EXP1)));
        }
    } else {
        setEXP(EXP1, ceil(EXP1 - 0.25*EXP1));
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int findMaxDiagonalValue(int matrix[10][10], int i, int j) {
    // i, j is the current position
    int maxVal = 0;

    // Left Diagonal
    int x = i - 1, y = j - 1;
    while (x >= 0 && y >= 0) {
        maxVal = max(maxVal, matrix[x][y]);
        x--;
        y--;
    }
    x = i + 1, y = j + 1;
    while (x < 10 && y < 10) {
        maxVal = max(maxVal, matrix[x][y]);
        x++;
        y++;
    }

    // Right Diagonal
    x = i - 1, y = j + 1;
    while (x >= 0 && y < 10) {
        maxVal = max(maxVal, matrix[x][y]);
        x--;
        y++;
    }
    x = i + 1, y = j - 1;
    while (x < 10 && y >= 0) {
        maxVal = max(maxVal, matrix[x][y]);
        x++;
        y--;
    }

    return abs(maxVal);
}

int simplifyNumber(int num) {
    while (digitCounter(num) != 1) {
        num = (num / 10 + num % 10);
    }
    return num;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    int taxiArray[10][10] = {0};
    int sherlockWatsonArray[10][10] = {0};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxiArray[i][j] = ((E3*j) + (i*2))*(i-j);
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            sherlockWatsonArray[i][j] = findMaxDiagonalValue(taxiArray, i, j);
        }
    }

    int positiveNum = 0;
    int negativeNum = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (taxiArray[i][j] > E3*2) {
                positiveNum++;
            } else if (taxiArray[i][j] < -E3) {
                negativeNum++;
            }
        }
    }

    int meetingXLocation = simplifyNumber(positiveNum);
    int meetingYLocation = simplifyNumber(negativeNum);

    int sherlockWatsonScore = sherlockWatsonArray[meetingXLocation][meetingYLocation];
    int taxiScore = taxiArray[meetingXLocation][meetingYLocation];

    if (abs(taxiScore) > sherlockWatsonScore) {
        setEXP(EXP1, ceil(EXP1 - 0.12*EXP1));
        setEXP(EXP2, ceil(EXP2 - 0.12*EXP2));

        setHP(HP1, ceil(HP1 - 0.1*HP1));
        setHP(HP2, ceil(HP2 - 0.1*HP2));

        return taxiScore;
    } else {
        setEXP(EXP1, EXP1 + ceil(0.12*EXP1));
        setEXP(EXP2, EXP2 + ceil(0.12*EXP2));

        setHP(HP1, HP1 + ceil(0.1*HP1));
        setHP(HP2, HP2 + ceil(0.1*HP2));

        return sherlockWatsonScore;
    }
}

// Task 4
int strLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}

char* extractUsername(const char* email) {
    int length = 0;
    while (email[length] != '@' && email[length] != '\0') {
        ++length;
    }

    char* username = new char[length + 1];
    for (int i = 0; i < length; ++i) {
        username[i] = email[i];
    }
    username[length] = '\0';

    return username;
}

int checkPassword(const char* s, const char* email) {
    // Check password length
    int length = strLength(s);
    if (length < 8) return -1;
    if (length > 20) return -2;

    // Check if password contains username
    char* username = extractUsername(email);
    const char* usernameInPassword = strstr(s, username);
    if (usernameInPassword != nullptr) {
        int position = usernameInPassword - s;
        delete[] username;
        return -(300 + position);
    }
    delete[] username;

    // Check if password contains consecutive characters
    int consecutive = 1;
    for (int i = 0; i < length; ++i) {
        char c = s[i];

        if (i > 0 && c == s[i - 1]) {
            consecutive++;
            if (consecutive > 2) return -(400 + (i - 2));
        } else {
            consecutive = 1;
        }
    }

    // Check if password contains special characters
    bool hasSpecialChar = false;

    for (int i = 0; i < length; ++i) {
        char c = s[i];

        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
            hasSpecialChar = true;
        }
    }
    if (!hasSpecialChar) return -5;

    // Check if password contains digits
    for (int i = 0; i < length; ++i) {
        char c = s[i];

        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '@' || c == '#' || c == '%' || c == '$' || c == '!')) {
            return i;
        }
    }

    return -10;
}

int foo() {
    return -4;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxFreq = 0;
    int correctPwdIndex = -1;
    int maxLength = 0;

    for (int i = 0; i < num_pwds; ++i) {
        int freq = 1;
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                ++freq;
            }
        }

        int currentLength = strLength(arr_pwds[i]);
        if (freq > maxFreq || (freq == maxFreq && currentLength > maxLength)) {
            maxFreq = freq;
            correctPwdIndex = i;
            maxLength = currentLength;
        }
    }

    return correctPwdIndex;

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////