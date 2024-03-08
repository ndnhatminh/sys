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
    // DO NOT MODIFY THIS FUNcTION
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
// Check EXP
void getEXP(int &EXP1) {
    if (EXP1 < 0) {
        EXP1 = 0;
    } else if (EXP1 > 600) {
        EXP1 = 600;
    }
}

// Check HP
void getHP(int &HP1) {
    if (HP1 < 0) {
        HP1 = 0;
    } else if (HP1 > 666) {
        HP1 = 666;
    }
}

// Check M
void getM(int &M1) {
    if (M1 < 0) {
        M1 = 0;
    } else if (M1 > 3000) {
        M1 = 3000;
    }
}

// Case 1
void firstMeetCase1(int &EXP1, int &EXP2, int E1) {
    int arr[4] = {29, 45, 75, 149};
    int D = E1 * 3 + EXP1 * 7;
    EXP2 += arr[E1];
    if (D % 2)
        EXP1 -= floor(D / 100.0);
    else
        EXP1 += ceil(D / 200.0);
    getEXP(EXP1);
    getEXP(EXP2);
}

// Case 2
void firstMeetCase2(int &EXP1, int &EXP2, int E1) {
    EXP1 -= E1;
    if (E1 <= 19)
        EXP2 += 19 + ceil(E1 / 4.0);
    else if (E1 <= 49)
        EXP2 += 21 + ceil(E1 / 9.0);
    else if (E1 <= 65)
        EXP2 += 17 + ceil(E1 / 16.0);
    else if (E1 <= 79) {
        EXP2 += 19 + ceil(E1 / 4.0);
        getEXP(EXP1);
        getEXP(EXP2);
        if (EXP2 > 200)
            EXP2 += 21 + ceil(E1 / 9.0);
    } else if (E1 <= 99) {
        EXP2 += 19 + ceil(E1 / 4.0);
        getEXP(EXP1);
        getEXP(EXP2);
        EXP2 += 21 + ceil(E1 / 9.0);
        getEXP(EXP1);
        getEXP(EXP2);
        if (EXP2 > 400) {
            EXP2 += 17 + ceil(E1 / 16.0);
            getEXP(EXP1);
            getEXP(EXP2);
            EXP2 = ceil(EXP2 * 23.0 / 20);
        }
    }
    getEXP(EXP1);
    getEXP(EXP2);
}

// Execute task 1
int firstMeet(int &exp1, int &exp2, int e1) {
    if (e1 < 0 || e1 > 99) {
        return -99;
    } else if (e1 <= 3) {
        firstMeetCase1(exp1, exp2, e1);
    } else if (e1 <= 99) {
        firstMeetCase2(exp1, exp2, e1);
    }
    return exp1 + exp2;
}

// Task 2
// Road 1
// Value of P1
double traceLuggageRoad1(int EXP1) {
    int N = sqrt(EXP1), N1 = EXP1 - N * N, N2 = (N + 1) * (N + 1) - EXP1;
    double P1;
    if (N1 < N2)
        P1 = 1;
    else
        P1 = (EXP1 / (EXP1 + N2) + 80) / 123.0;
    return P1;
}

// Road 2
// Event 1
void traceLuggageRoad2_Event1(int &HP1, int &M1) {
    if (HP1 < 200) {
        HP1 = ceil(HP1 * 13.0 / 10);
        M1 -= 150;
    } else {
        HP1 = ceil(HP1 * 11.0 / 10);
        M1 -= 70;
    }
    getHP(HP1);
    getM(M1);
}

// Event 2
void traceLuggageRoad2_Event2(int &EXP1, int &M1) {
    if (EXP1 < 400)
        M1 -= 200;
    else
        M1 -= 120;
    EXP1 = ceil(EXP1 * 113.0 / 100);
    getEXP(EXP1);
    getM(M1);
}

// Event 3
void traceLuggageRoad2_Event3(int &EXP1, int &M1) {
    if (EXP1 < 300)
        M1 -= 100;
    else
        M1 -= 120;
    EXP1 = ceil(EXP1 * 9.0 / 10);
    getEXP(EXP1);
    getM(M1);
}

// Calculation changes of HP1, EXP1, M1 after 3 events
void traceLuggageRoad2(int &HP1, int &EXP1, int &M1, int E2) {
    int M = M1;
    if (E2 % 2) {
        if (M1 != 0) {
            while (1) {
                traceLuggageRoad2_Event1(HP1, M1);
                if (2 * M1 < M) break;
                traceLuggageRoad2_Event2(EXP1, M1);
                if (2 * M1 < M) break;
                traceLuggageRoad2_Event3(EXP1, M1);
                if (2 * M1 < M) break;
            }
        }
    } else {
        if (M1 != 0) {
            traceLuggageRoad2_Event1(HP1, M1);
            if (M1 != 0) {
                traceLuggageRoad2_Event2(EXP1, M1);
                if (M1 != 0) {
                    traceLuggageRoad2_Event3(EXP1, M1);
                }
            }
        }
    }
    HP1 = ceil(HP1 * 83.0 / 100);
    EXP1 = ceil(EXP1 * 117.0 / 100);
    getEXP(EXP1);
}

// P2=P1
// So only need to calculate value of P1
// Road 3
// Calculation of P3
double traceLuggageRoad3(int E2) {
    double P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}, P3;
    if (E2 >= 10) {
        E2 = E2 % 10 + (E2 - E2 % 10) / 10;
        E2 = E2 % 10;
    }
    P3 = P[E2];
    return P3;
}

// Changes of value when P is known
// P=100%
void incident_1(int &EXP1) {
    EXP1 = ceil(EXP1 * 75.0 / 100);
}

// P<50%
void incident_2(int &EXP1, int &HP1) {
    EXP1 = ceil(EXP1 * 115.0 / 100);
    getEXP(EXP1);
    HP1 = ceil(HP1 * 85.0 / 100);
}

// P>=50%
void incident_3(int &EXP1, int &HP1) {
    EXP1 = ceil(EXP1 * 12.0 / 10);
    getEXP(EXP1);
    HP1 = ceil(HP1 * 90.0 / 100);
}

// Execute task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
    if (E2 < 0 || E2 > 99)
        return -99;
    double P1, P2, P3, P;
    P1 = traceLuggageRoad1(EXP1);
    traceLuggageRoad2(HP1, EXP1, M1, E2);
    P2 = traceLuggageRoad1(EXP1);
    P3 = traceLuggageRoad3(E2) / 100;
    P = (P1 + P2 + P3) / 3;
    if (P == 1)
        incident_1(EXP1);
    else if (P < 0.5)
        incident_2(EXP1, HP1);
    else if (P >= 0.5)
        incident_3(EXP1, HP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    // Create taxi map
    int taxiMap[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxiMap[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    
    // Count occurrences based on conditions
    int counti = 0, countj = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (taxiMap[i][j] > E3 * 2)
                counti++;
            if (taxiMap[i][j] < -E3)
                countj++;
        }
    }
    
    // Normalize counti and countj
    while (counti >= 10) {
        counti = counti / 10 + counti % 10;
    }
    while (countj >= 10) {
        countj = countj / 10 + countj % 10;
    }
    
    // Find maximum value around the specified coordinates
    int max = 0;
    for (int i = 0; i < 10; i++) {
        if ((counti + i) <= 9 && (countj + i) <= 9) {
            if (taxiMap[counti + i][countj + i] > max)
                max = taxiMap[counti + i][countj + i];
        }
        if ((counti - i) >= 0 && (countj - i) >= 0) {
            if (taxiMap[counti - i][countj - i] > max)
                max = taxiMap[counti - i][countj - i];
        }
        if ((counti + i) <= 9 && (countj - i) >= 0) {
            if (taxiMap[counti + i][countj - i] > max)
                max = taxiMap[counti + i][countj - i];
        }
        if ((counti - i) >= 0 && (countj + i) <= 9) {
            if (taxiMap[counti - i][countj + i] > max)
                max = taxiMap[counti - i][countj + i];
        }
    }
    
    // Handle negative values
    if (max < 0)
        max = abs(max);
    
    // Update values based on conditions and return the maximum or -1
    if (abs(taxiMap[counti][countj]) > max) {
        EXP1 = 0.88 * EXP1 + 0.999;
        EXP2 = 0.88 * EXP2 + 0.999;
        HP1 = 0.9 * HP1 + 0.999;
        HP2 = 0.9 * HP2 + 0.999;
        return taxiMap[counti][countj];
    } else {
        EXP1 = 1.12 * EXP1 + 0.999;
        EXP2 = 1.12 * EXP2 + 0.999;
        HP1 = 1.1 * HP1 + 0.999;
        HP2 = 1.1 * HP2 + 0.999;
        return max;
    }
}


// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    // Determine se
    std::string emailString(email);
    std::string se = emailString.substr(0, emailString.find('@'));

    // Check if s is shorter than the minimum length
    int s_length = strlen(s);
    if (s_length < 8)
        return -1;

    // Check if s is longer than the maximum length
    if (s_length > 20)
        return -2;

    // Check if s contains se
    const char *se_position = strstr(s, se.c_str());
    if (se_position != nullptr)
        return -(300 + (se_position - s));

    // Check for consecutive identical characters
    for (int i = 0; i < s_length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
            return -(400 + i);
    }

    // Check if s contains special characters
    bool hasSpecialChar = false;
    for (int i = 0; i < s_length; ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            hasSpecialChar = true;
    }
    if (!hasSpecialChar)
        return -5;

    // Check for validity of each character
    for (int i = 0; i < s_length; ++i) {
        char c = s[i];
        if (!(('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') ||
              c == '@' || c == '#' || c == '%' || c == '$' || c == '!')) {
            return i;
        }
    }

    // If no conditions are violated, return -10
    return -10;


    return -99;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    

    // Create an array to store unique passwords
    int k = 0;
    string arr_pwds2[39];
    arr_pwds2[k] = arr_pwds[k];
    for (int i = 1; i < num_pwds; i++) {
        for (int j = 0; j < i; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
                break;
            if (strcmp(arr_pwds[i], arr_pwds[j]) != 0 && j == i - 1) {
                arr_pwds2[k + 1] = arr_pwds[i];
                k++;
            }
        }
    }

    // Count the number of unique passwords
    int count = 0;
    while (!arr_pwds2[count].empty()) {
        count++;
    }

    // Create an array to store the occurrence count of each unique password
    int arr_pwds3[count];
    for (int i = 0; i < count; i++) {
        arr_pwds3[i] = 0;
    }

    // Populate the array with the occurrence count of each unique password
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < num_pwds; j++) {
            if (arr_pwds2[i] == arr_pwds[j]) {
                arr_pwds3[i]++;
            }
        }
    }

    // Find the first most frequent password, giving priority to longer ones
    int max = arr_pwds3[0];
    int position = 0;
    for (int i = 1; i < count; i++) {
        if (arr_pwds3[i] > max || (arr_pwds3[i] == max && arr_pwds2[i].size() > arr_pwds2[position].size())) {
            max = arr_pwds3[i];
            position = i;
        }
    }

    // Find the index of the most frequent password in the original array
    for (int i = 0; i < num_pwds; i++) {
        if (arr_pwds2[position] == arr_pwds[i]) {
            position = i;
            break;
        }
    }

    return position;
    return -1;

}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////