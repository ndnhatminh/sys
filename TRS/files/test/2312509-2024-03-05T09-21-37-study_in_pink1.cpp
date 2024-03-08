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
int firstMeet(int & EXP1, int & EXP2, int E1) {
    if (E1 < 0 || E1 > 99) {
        return -99;
    }

    // Case 1
    if (E1 <= 3) {
        switch (E1) {
            case 0:
                EXP2 += 29;
                break;
            case 1:
                EXP2 += 45;
                break;
            case 2:
                EXP2 += 75;
                break;
            case 3:
                EXP2 += 149;
                break;
        }

        int D = E1*3 + EXP1*7;
        if (D % 2 == 0) {
            EXP1 += ceil(float(D/200.00));
        }
        else EXP1 -= floor(float(D/100.00));
        
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        if (EXP2 > 600) EXP2 = 600;
    }

    // Case 2
    else {
        if (E1 <= 19) EXP2 += ceil(float(E1/4.00)) + 19;
        else if (E1 <= 49) EXP2 += ceil(float(E1/9.00)) + 21;
        else if (E1 <= 65) EXP2 += ceil(float(E1/16.00)) + 17;
        else if (E1 <= 79) {
            EXP2 += ceil(float(E1/4.00)) + 19;
            if (EXP2 > 200) EXP2 += ceil(float(E1/9.00)) + 21;
        }
        else {
            EXP2 += ceil(float(E1/4.00)) + ceil(float(E1/9.00)) + 40;
            if (EXP2 > 400) {
                EXP2 += ceil(float(E1/16.00)) + 17;
                EXP2 = ceil(float(EXP2*1.15));
            } 
        }
        EXP1 -= E1;
        if (EXP1 < 0) EXP1 = 0;
        if (EXP2 > 600) EXP2 = 600;
    }

    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99) {
        return -99;
    }

    double P1, P2, P3;
    
    // Road 01
    int N = sqrt(EXP1);
    if (EXP1 - N*N < pow(N + 1, 2) - EXP1) P1 = 100;
    else P1 = double((EXP1/pow(N + 1, 2) + 80)/1.23);

    // Road 02
    if (E2%2 == 1) {
        int paid = 0, event = 2;
        int halfM1 = 0.5*M1;
        while (paid <= halfM1) {
            switch (event = ++event % 3) {
                case 0: // event 1
                    if (HP1 < 200) {
                        HP1 = ceil(float(HP1*1.30));
                        M1 -= 150;
                        paid += 150;
                    }
                    else {
                        HP1 = ceil(float(HP1*1.10));
                        M1 -= 70;
                        paid += 70;
                    }
                    if (HP1 > 666) HP1 = 666;
                    if (M1 < 0) M1 = 0;
                    break;

                case 1: // event 2
                    if (EXP1 < 400) {
                        M1 -= 200;
                        paid += 200;
                    }
                    else {
                        M1 -= 120;
                        paid += 120;
                    }
                    EXP1 = ceil(float(EXP1*1.13));
                    if (M1 < 0) M1 = 0;
                    if (EXP1 > 600) EXP1 = 600;
                    break;

                case 2: // event 3
                    if (EXP1 < 300) {
                        M1 -= 100;
                        paid += 100;
                    }
                    else {
                        M1 -= 120;
                        paid += 120;
                    }
                    EXP1 = ceil(float(EXP1*0.90));
                    if (M1 < 0) M1 = 0;
                    break;
            }
        }
    }

    else {
        int event = 0;
        do {
            switch (event++) {
                case 0: // event 1
                    if (HP1 < 200) {
                        HP1 = ceil(float(HP1*1.30));
                        M1 -= 150;
                    }
                    else {
                        HP1 = ceil(float(HP1*1.10));
                        M1 -= 70;
                    }
                    if (HP1 > 666) HP1 = 666;
                    if (M1 < 0) M1 = 0;
                    break;

                case 1: // event 2
                    if (EXP1 < 400) M1 -= 200;
                    else M1 -= 120;
                    EXP1 = ceil(float(EXP1*1.13));
                    if (M1 < 0) M1 = 0;
                    if (EXP1 > 600) EXP1 = 600;
                    break;

                case 2: // event 3
                    if (EXP1 < 300) M1 -= 100;
                    else M1 -= 120;
                    EXP1 = ceil(float(EXP1*0.90));
                    if (M1 < 0) M1 = 0;
                    break;
            }
        }
        while (event != 3 && M1 != 0);
    }

    HP1 = ceil(float(HP1*0.83));
    EXP1 = ceil(float(EXP1*1.17));
    if (EXP1 > 600) EXP1 = 600;

    N = sqrt(EXP1);
    if (EXP1 - N*N < pow(N + 1, 2) - EXP1) P2 = 100;
    else P2 = double((EXP1/pow(N + 1, 2) + 80)/1.23);

    // Road 03
    int i = (E2/10 + E2%10)%10;
    double PC[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    P3 = PC[i];

    // Conclusion
    if (P1 == 100 && P2 == 100 && P3 == 100) EXP1 = ceil(float(EXP1*0.75));
    else {
        double P = (P1 + P2 + P3)/3;
        if (P < 50) {
            HP1 = ceil(float(HP1*0.85));
            EXP1 = ceil(float(EXP1*1.15));
        }
        else {
            HP1 = ceil(float(HP1*0.90));
            EXP1 = ceil(float(EXP1*1.20));
        }
    }
    if (EXP1 > 600) EXP1 = 600;

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) {
        return -99;
    }

    int taxi[10][10] = {}, SW[10][10] = {};

    int leftDiag[19], rightDiag[19];
    for (int i = 0; i < 19; i++) {
        leftDiag[i] = rightDiag[i] = -8020;
    }
    
    int x = 0, y = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxi[i][j] = (E3*j + i*2) * (i - j);
            leftDiag[i - j + 9] = max(leftDiag[i - j + 9], taxi[i][j]);
            rightDiag[i + j] = max(rightDiag[i + j], taxi[i][j]);
            if (taxi[i][j] > E3*2) ++x;
            if (taxi[i][j] < -E3) ++y;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            SW[i][j] = abs(max(leftDiag[i - j + 9], rightDiag[i + j]));
        }
    }

    while (x >= 10) x = x/10 + x%10;
    while (y >= 10) y = y/10 + y%10;

    if (abs(taxi[x][y]) > SW[x][y]) {
        EXP1 = ceil(float(EXP1*0.88));
        EXP2 = ceil(float(EXP2*0.88));
        HP1 = ceil(float(HP1*0.90));
        HP2 = ceil(float(HP2*0.90));

        return taxi[x][y];
    }

    else {
        EXP1 = ceil(float(EXP1*1.12));
        EXP2 = ceil(float(EXP2*1.12));
        HP1 = ceil(float(HP1*1.10));
        HP2 = ceil(float(HP2*1.10));

        if (EXP1 > 600) EXP1 = 600;
        if (EXP2 > 600) EXP2 = 600;
        if (HP1 > 666) HP1 = 666;
        if (HP2 > 666) HP2 = 666;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                SW[i][j] = max(leftDiag[i - j + 9], rightDiag[i + j]);
            }
        }

        return SW[x][y];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string se = "";
    const char *ptr = email;
    while (*ptr != '@') {
        se += *ptr;
        ptr++;
    }

    int len = strlen(s);
    if (len < 8) return -1; 
    if (len > 20) return -2; 

    const char * found = strstr(s, se.c_str());
    if (found) return -(300 + (found - s)); 

    for (int i = 0; i < len - 2; i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            return -(400 + i); 
        }
    }

    bool hasSpeChar = false;
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
            hasSpeChar = true;
            break;
        }
    }
    if (!hasSpeChar) return -5; 

    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (!(isdigit(c) || islower(c) || isupper(c) || c == '@' || c == '#' || c == '%' || c == '$' || c == '!')) {
            return i; 
        }
    }

    return -10; 
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxcount = 0;
    const char * maxpass = nullptr;
    int maxpasspos;

    for (int i = 0; i < num_pwds; i++) {
        const char * curpass = arr_pwds[i];
        int curcount = 0;
        
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(curpass, arr_pwds[j]) == 0) {
                curcount++;
            }
        }

        if (curcount > maxcount || (curcount == maxcount && strlen(curpass) > strlen(maxpass))) {
            maxcount = curcount;
            maxpass = curpass;
            maxpasspos = i;
        }
    }

    return maxpasspos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////