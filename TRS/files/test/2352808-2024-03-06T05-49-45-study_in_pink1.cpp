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

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    e1 = (e1 > 99) ? 99 : (e1 < 0) ? 0 : e1;
    if (e1 >= 0 && e1 <= 3)
    {
        //Truong hop 1 
        double expChange = 0;
        switch (e1) {
        case 0:
            expChange = 29;
            break;
        case 1:
            expChange = 45;
            break;
        case 2:
            expChange = 75;
            break;
        case 3:
            expChange = 29 + 45 + 75;
            break;
        }
        exp2 += expChange;


        //EXP cua Sherlock 

        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            exp1 += D / 200;
        else
            exp1 -= D / 100;
        exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
        exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
        e1 = (e1 > 99) ? 99 : (e1 < 0) ? 0 : e1;
    }

    //Truong hop 2

    else if (e1 >= 4 && e1 <= 99) {

        double expChange = 0.000;
        if (e1 >= 4 && e1 <= 19)
            expChange = std::ceil((double)e1 / 4 + 19);
        else if (e1 >= 20 && e1 <= 49)
            expChange = std::ceil((double)e1 / 9 + 21);
        else if (e1 >= 50 && e1 <= 65)
            expChange = std::ceil((double)e1 / 16 + 17);
        else if (e1 >= 66 && e1 <= 79) {
            expChange = std::ceil((double)e1 / 4 + 19);
            if (exp2 > 200)
                expChange = std::ceil((double)e1 / 9 + 21);
        }
        else if (e1 >= 80 && e1 <= 99) {
            expChange += ceil((double)e1 / 4 + 19);
            expChange += ceil((double)e1 / 9 + 21);
            if (exp2 > 400)
                expChange += std::ceil((double)e1 / 16 + 17);
        }
        exp2 += expChange;
        if (e1 >= 80 && e1 <= 99) {
            exp2 += std::ceil((double)exp2 * 0.15);
        }
        exp1 -= e1;
        e1 = (e1 > 99) ? 99 : (e1 < 0) ? 0 : e1;
        exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
        exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
    }

    return exp1 + exp2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // Street 1:
    int squareRoot = (sqrt(EXP1));
    int S;
    float XS_P1;
    int square = squareRoot * squareRoot;
    int nextSquare = (squareRoot + 1) * (squareRoot + 1);

    if (abs(EXP1 - square) < abs(EXP1 - nextSquare)) {
        S = square;
    }
    else {
        S = nextSquare;
    }
    if (EXP1 >= S)
        XS_P1 = 1.0;
    else
        XS_P1 = (((float)EXP1 / S + 80) / 123);



    int nua = ceil((double)M1 * 0.5);
    // street 2:
    while (E2 % 2 == 1 && M1 > nua)
    {
        //event 1
        if (HP1 < 200) {
            HP1 += ceil((double)HP1 * 0.3);
            M1 -= 150;
            HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
        }
        else {
            HP1 += ceil((double)HP1 * 0.1);
            M1 -= 70;
            HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
        }
        E2 = (E2 > 99) ? 99 : (E2 < 0) ? 0 : E2;
        if (M1 < nua)
            break;
        //event 2
        if (EXP1 < 400) {
            M1 -= 200;
            EXP1 += ceil((double)EXP1 * 0.13);

            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
        }

        else {
            M1 -= 120;
            EXP1 += ceil((double)EXP1 * 0.13);
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
        }

        if (M1 < nua)
            break;
        //event 3
        if (EXP1 < 300) {
            M1 -= 100;
            EXP1 -= floor((double)EXP1 * 0.1);
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
        }
        else {
            M1 -= 120;
            EXP1 -= floor((double)EXP1 * 0.1);
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
        }
        if (M1 < nua) {
            break;
        }

        HP1 -= floor((double)HP1 * 0.17);
        EXP1 += ceil((double)EXP1 * 0.17);
        EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
        HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
    }



    // when E2 is even 
    if (E2 % 2 == 0) {

        if (HP1 < 200) {
            HP1 += ceil((double)HP1 * 0.3);
            M1 -= 150;
            HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
        }
        else {
            HP1 += ceil((double)HP1 * 0.1);
            M1 -= 70;
            HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
        }

        //event 2
        if (EXP1 < 400) {
            M1 -= 200;
            EXP1 += ceil((double)EXP1 * 0.13);
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
        }
        else {
            M1 -= 120;
            EXP1 += ceil((double)EXP1 * 0.13);
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
        }

        //event 3
        if (EXP1 < 300) {
            M1 -= 100;
            EXP1 -= floor((double)EXP1 * 0.1);
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
        }
        else {
            M1 -= 120;
            EXP1 -= floor((double)EXP1 * 0.1);
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
        }
        HP1 -= floor((double)HP1 * 0.17);
        EXP1 += ceil((double)EXP1 * 0.17);
        EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
        HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
    }

    float XS_P2 = (((float)EXP1 / S + 80) / 123);

    // street 3:
    int P3[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i;
    int sum;
    if (E2 < 10)
        i = E2;
    else if (E2 >= 10 && E2 <= 99) {
        sum = (E2 / 10 + E2 % 10);
        i = sum % 10;
        E2 = (E2 > 99) ? 99 : (E2 < 0) ? 0 : E2;
    }

    double XS_P3 = (double)P3[i] / 100;

    float total_P = (XS_P1 + XS_P2 + XS_P3) / 3;

    if (XS_P1 == 1 && XS_P2 == 1 && XS_P3 == 1) {
        EXP1 -= floor((double)EXP1 * 0.25);

        EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
    }
    else if (total_P < 0.5) {
        EXP1 += ceil((double)EXP1 * 0.15);
        HP1 -= floor((double)HP1 * 0.15);

        EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
        HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
    }
    else if (total_P >= 0.5) {
        HP1 = ceil((double)HP1 * 0.9);
        EXP1 += ceil((double)EXP1 * 0.2);

        EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
        HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
    }

    return HP1 + EXP1 + M1;
}

// Task 3

int toSingleDigit(int num) {
    while (num > 9) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    HP1 = std::max(0, std::min(666, HP1));
    HP2 = std::max(0, std::min(666, HP2));

    EXP1 = std::max(0, std::min(600, EXP1));
    EXP2 = std::max(0, std::min(600, EXP2)); 

    E3 = std::max(0, std::min(99, E3));

    const int size = 10;
    int taxiMap[size][size], swScores[size][size] = { 0 };


    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            taxiMap[i][j] = (((E3 * j) + (i * 2)) * (i - j));
        }
    }


    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int maxScore = INT_MIN;


            for (int k = -size; k < size; ++k) {
                int diagI = i + k, diagJ = j + k;
                if (diagI >= 0 && diagI < size && diagJ >= 0 && diagJ < size) {
                    maxScore = max(maxScore, abs(taxiMap[diagI][diagJ]));
                }

                diagI = i + k, diagJ = j - k;
                if (diagI >= 0 && diagI < size && diagJ >= 0 && diagJ < size) {
                    maxScore = max(maxScore, abs(taxiMap[diagI][diagJ]));
                }
            }

            swScores[i][j] = maxScore;
        }
    }


    int countGreater = 0, countSmaller = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (taxiMap[i][j] > E3 * 2) countGreater++;
            if (taxiMap[i][j] < -E3) countSmaller++;
        }
    }

    int meetI = toSingleDigit(countGreater);
    int meetJ = toSingleDigit(countSmaller);


    bool catchTaxi = abs(taxiMap[meetI][meetJ]) <= swScores[meetI][meetJ];


    double hpUpdateFactor = catchTaxi ? 1.1 : 0.9;
    double expUpdateFactor = catchTaxi ? 1.12 : 0.88;

    HP1 = static_cast<int>(HP1 + hpUpdateFactor);
    EXP1 = static_cast<int>(EXP1 + expUpdateFactor);
    HP2 = static_cast<int>(HP2 + hpUpdateFactor);
    EXP2 = static_cast<int>(EXP2 + expUpdateFactor);


    int taxiGrade = abs(taxiMap[meetI][meetJ]);
    int swGrade = max(HP1 + EXP1, HP2 + EXP2);

    return (taxiGrade > swGrade) ? -taxiGrade : swGrade;
}


// Task 4

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    char se[256]; 
    strncpy(se, email, sizeof(se) - 1);
    se[sizeof(se) - 1] = '\0'; 
    char* atSign = strchr(se, '@');
    if (atSign) *atSign = '\0'; 

    int sLength = strlen(s);
   
    if (sLength < 8) {
        return -1;
    }
    if (sLength > 20) {
        return -2;
    }

    if (strstr(s, se) != NULL) {
        return -(300 + (strstr(s, se) - s));
    }
  
    for (int i = 0; i < sLength - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }

    bool hasSpecialChar = false;
    for (int i = 0; i < sLength; ++i) {
        char c = s[i];
        if (!(isDigit(c) || isAlpha(c) || c == '@' || c == '#' || c == '%' || c == '$' || c == '!')) {
            return static_cast<int>(static_cast<unsigned char>(c)); 
        }
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
            hasSpecialChar = true;
        }
    }

    if (!hasSpecialChar) {
        return -5;
    }

    return -99;
}


// Task 5
const int MAX_PASSWORDS = 30;
const int MAX_LENGTH = 100;
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int freq[MAX_PASSWORDS] = { 0 };
    int firstPos[MAX_PASSWORDS];
    for (int i = 0; i < num_pwds; ++i) {
        firstPos[i] = -1; 
    }

    for (int i = 0; i < num_pwds; ++i) {
        bool found = false;
        for (int j = 0; j < i; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                freq[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            freq[i] = 1;
            firstPos[i] = i; 
        }
    }

    int maxFreq = 0;
    size_t maxLength = 0;
    int correctPos = -1;
    for (int i = 0; i < num_pwds; ++i) {
        if (freq[i] > maxFreq || (freq[i] == maxFreq && strlen(arr_pwds[i]) > maxLength)) {
            maxFreq = freq[i];
            maxLength = strlen(arr_pwds[i]);
            correctPos = firstPos[i]; 
        }
    }

    return correctPos; 
}
    


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////