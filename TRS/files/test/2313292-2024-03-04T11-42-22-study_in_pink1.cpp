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

// These functions are used to update data and assure they are appropriate

///////////////////////////////////////////////////////////////
void adjustHP(int & HP, double shift){                       //
    HP = static_cast<int>(HP + shift + 0.99999);             //
    (HP < 0) ? (HP = 0) : ((HP > 666) ? (HP = 666) : 0);     // 
}                                                            //
                                                             //
void adjustEXP(int & EXP, double shift){                     //
    EXP = static_cast<int>(EXP + shift + 0.99999);           //
    (EXP < 0) ? (EXP = 0) : ((EXP > 600) ? (EXP = 600) : 0); //
}                                                            //
                                                             //
void adjustM(int & M, double shift){                         //
    M = static_cast<int>(M + shift + 0.99999);               //
    (M < 0) ? (M = 0) : ((M > 3000) ? (M = 3000) : 0);       //
}                                                            //
///////////////////////////////////////////////////////////////

// Task 1: divide into 2 cases

void firstMeet_case1(int E1, int & EXP1, int & EXP2){
    switch (E1){
        case 0: 
            adjustEXP(EXP2, 29);
            break;
        case 1:
            adjustEXP(EXP2, 45);
            break;
        case 2:
            adjustEXP(EXP2, 75);
            break;
        case 3:
            adjustEXP(EXP2, 29 + 45 + 75);
            break; 
    }
    int D = (E1 * 3) + (EXP1 * 7);
    (D % 2 == 0) ? adjustEXP(EXP1, D/200.0) : adjustEXP(EXP1, - D/100.0);
}

void firstMeet_case2(int E1, int & EXP1, int & EXP2){
    //info 1
    if (E1 >= 4 && E1 <= 19){
        adjustEXP(EXP2, (E1 / 4.0) + 19);
    }
    else{
        //info 2
        if (E1 <= 49){
            adjustEXP(EXP2, (E1 / 9.0) + 21);
        }
        else{
            //info 3
            if (E1 <= 65){
                adjustEXP(EXP2, (E1 / 16.0) + 17);
            }
            else{
                //info 4
                if (E1 <= 79){
                    adjustEXP(EXP2, (E1 / 4.0) + 19);
                    if (EXP2 > 200) adjustEXP(EXP2, (E1 / 9.0) + 21);
                }
                else{
                    //info 5
                    if (E1 <=99){
                        adjustEXP(EXP2, (E1 / 4.0) + 19);
                        adjustEXP(EXP2, (E1 / 9.0) + 21);
                        if (EXP2 > 400){
                            adjustEXP(EXP2, (E1 / 16.0) + 17);
                            adjustEXP(EXP2, 0.15*EXP2);
                        }
                    }
                }
            }
        }
    }
    adjustEXP(EXP1, - E1);
}

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
        return -99;
    adjustEXP(exp1, 0);
    adjustEXP(exp2, 0);
    if (e1 >= 0 && e1 <= 3){
        firstMeet_case1(e1, exp1, exp2);
    }
    else{
        firstMeet_case2(e1, exp1, exp2);
    }
    
    return exp1 + exp2;
}

//Task 2: Divide into 3 streets

double traceLuggage_street1(int EXP1){
    // This means S = s * s
    int s = static_cast<int>(sqrt(EXP1));

    //Compare EXP1 with average of both upbound and lowbound, that is (s^2 + (s+1)^2)/2 and always has decimal place
    if (EXP1 < (s * s) + s + 0.5){
        //EXP1 >= S
        return 1.0;
    }
    else{
        ++s;
        return (EXP1 / (s * s * 1.0) + 80)/123.0;
    }
    return 0;
}

// Second street has 3 smaller functions 

int event1(int & HP1, int & M1){
    if (HP1 < 200){
        adjustHP(HP1, 0.3 * HP1);
        adjustM(M1, - 150);
        return 150;
    }
    else{
        adjustHP(HP1, 0.1 * HP1);
        adjustM(M1, - 70);
        return 70;
    }
    return 0;
}

int event2(int & EXP1, int & M1){
    if (EXP1 < 400){
        adjustM(M1, - 200);
        adjustEXP(EXP1, 0.13 * EXP1);
        return 200;
    }
    else{
        adjustM(M1, - 120);
        adjustEXP(EXP1, 0.13 * EXP1);
        return 120;
    }
    return 0;
}

int event3(int & EXP1, int & M1){
    if (EXP1 < 300){
        adjustM(M1, - 100);
        adjustEXP(EXP1, - 0.1 * EXP1);
        return 100;
    }
    else{
        adjustM(M1, - 120);
        adjustEXP(EXP1, - 0.1 * EXP1);
        return 120;
    }
    return 0;
}

// Decrease HP and increase EXP

void walk(int & HP1, int & EXP1){
    adjustHP(HP1, - 0.17 * HP1);
    adjustEXP(EXP1, 0.17 * EXP1);
}

// Note: Computing the probability for the second street is identical to which for the first street

double traceLuggage_street2(int & HP1, int & EXP1, int & M1, int E2){
    int expense = 0;
    int initialM = M1;

    // This is a situation in which M1 equals 0 initially
    if (M1 == 0){
        walk(HP1, EXP1);
        return traceLuggage_street1(EXP1);
    }
    // E2 is odd
    if (E2 % 2){
        while (expense <= 0.5 * initialM){
            expense += event1(HP1, M1); 
            if (expense > 0.5 * initialM) break;
            expense += event2(EXP1, M1); 
            if (expense > 0.5 * initialM) break;            
            expense += event3(EXP1, M1); 
        }
        walk(HP1, EXP1);
    }
    // E2 is even
    else{
        event1(HP1, M1); 
        if (M1 != 0) event2(EXP1,M1); 
        if (M1 != 0) event3(EXP1, M1);
        walk(HP1, EXP1);
    }
    return traceLuggage_street1(EXP1);
}

double traceLuggage_street3(int E2){
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = (E2 <= 9) ? (E2) : ((E2 % 10 + E2 / 10) % 10); 
    return (P[i] / 100.0);
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
        return -99;
    adjustEXP(EXP1, 0);
    adjustHP(HP1, 0);
    adjustM(M1, 0);

    double sum = traceLuggage_street1(EXP1) + traceLuggage_street2(HP1, EXP1, M1, E2) + traceLuggage_street3(E2);
    // All streets give 100% then sum = 3
    if (sum >= 3){  // Just in case precision error
        adjustEXP(EXP1, - 0.25 * EXP1);
    }
    else{
        if (sum / 3.0 < 0.5){
            adjustHP(HP1, - 0.15 * HP1);
            adjustEXP(EXP1, 0.15 * EXP1);
        }
        else{
            adjustHP(HP1, - 0.1 * HP1);
            adjustEXP(EXP1, 0.2 * EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;
    adjustEXP(EXP1, 0);
    adjustEXP(EXP2, 0);
    adjustHP(HP1, 0);
    adjustHP(HP2, 0);
    // This array 10x10 contains all scores of criminal
    int map[10][10] = {0};
    // Location where encounter occurs
    int row = 0, column = 0;

    for (int i = 0; i <= 9; ++i){
        for (int j = 0; j <= 9; ++j){
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            // Raw data of location
            (map[i][j] > E3 * 2) ? (++row) : ((map[i][j] < - E3) ? (++column) : 0);
        }
    }
    // We first determine the specific location detective catch criminal up, then compute the score of detective
    // Modify data of location
    while (row > 9){
        row = (row / 10) + (row % 10);
    }
    while (column > 9){
        column = (column / 10) + (column % 10);
    }

    // Find the score of detective at the encounter//
    // The score of Sherlock
    int scoreDet = map[row][column];
    // Left line up
    for (int i = row - 1, j = column - 1; (i >= 0) && (j >= 0); --i, --j){
        if (map[i][j] > scoreDet) scoreDet = map[i][j];
    }
    // Left line down
    for (int i = row + 1, j = column + 1; (i <= 9) && (j <= 9); ++i, ++j){
        if (map[i][j] > scoreDet) scoreDet = map[i][j];
    }
    // Right line up
    for (int i = row - 1, j = column + 1; (i >= 0) && (j <= 9); --i, ++j){
        if (map[i][j] > scoreDet) scoreDet = map[i][j];
    }
    // Right line down
    for (int i = row + 1, j = column - 1; (i <= 9) && (j >= 0); ++i, --j){
        if (map[i][j] > scoreDet) scoreDet = map[i][j];
    }
    scoreDet = abs(scoreDet);
    if (abs(map[row][column]) > scoreDet){
        adjustEXP(EXP1, - 0.12 * EXP1); adjustEXP(EXP2, - 0.12 * EXP2);
        adjustHP(HP1, - 0.1 * HP1); adjustHP(HP2, - 0.1 * HP2);
        return map[row][column];
    }
    else{
        adjustEXP(EXP1, 0.12 * EXP1); adjustEXP(EXP2, 0.12 * EXP2);
        adjustHP(HP1, 0.1 * HP1); adjustHP(HP2, 0.1 * HP2);
        return scoreDet;
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // Data preprocessing
    string se = string(email).substr(0, string(email).find('@')); // begins at 0 and contains a number of character before '@'

    if (string(s).size() < 8){
        return -1;
    }
    if (string(s).size() > 20){
        return -2;
    }
    // We declare posInvalid to use for both conditions
    string::size_type posInvalid = string::npos; // To put simply, npos is no position 
    //the subscript of the starting location of se
    posInvalid = string(s).find(se);
    if ( posInvalid != string::npos){
        return - (300 + posInvalid);
    }

    // We check three conditions in an iteration: if there are three consecutive identical numbers, if there is a special character, and
    // if there is an invalid character

    // These identifers below used for three consecutive identical numbers
    char lastChar = '\0';
    short count = 0;
    // Check if special character exists
    bool specialChar = false;
    string specialChars = "@#%$!";
    string::size_type isValidchar = string::npos;

    for (char c : string(s)){
        if (c == lastChar){
            count++;
            if (posInvalid == string::npos){
                if (count == 3){
                    // Triple c 
                    posInvalid = string(s).find(string(3,c));
                }
            }
        }
        else{
            count = 1;
        }
        lastChar = c;

        if (specialChar == false){
            if (specialChars.find(c) != string::npos){
                specialChar = true;
            }
        }
        
        if (isValidchar == string::npos){
            if (!((c >= '0' && c <= '9') || // digits
                  (c >= 'a' && c <= 'z') || // lowercase letters
                  (c >= 'A' && c <= 'Z') || // uppercase letters
                  (specialChars.find(c) != string::npos))){ // special characters
                  isValidchar = string(s).find(c);
            }
        }
    }

    // We must obey the order in discription, that why we need to check conditions outside the loop 
    if (posInvalid != string::npos){
        return - (400 + posInvalid);
    }
    if (!specialChar){
        return -5;
    }
    if (isValidchar != string::npos){
        return isValidchar;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    // Add all elements in array into a string
/*
    string totalString = "";
    string passwords[30] = "";
    int idx = 0;

    for (int i = 0; i < num_pwds; i++){
        if (totalString.find(string(arr_pwds[i])) == string::npos){
            passwords[idx++] = string(arr_pwds[i]);
        }
        totalString.append(arr_pwds[i]);
    }
*/
    int maxCount = 0;
    // This is a subcript of a element has longest length
    int maxIndex = 0;

    for (int i = 0; i < num_pwds; i++){
        int count = 0;
        for (int j = i + 1; j < num_pwds; j++){
            if (string(arr_pwds[i]) == string(arr_pwds[j])){
                count++;
            }
        }
        if (count > maxCount || count == maxCount && string(arr_pwds[i]).size() > string(arr_pwds[maxIndex]).size()){
            maxCount = count;
            maxIndex = i;
        }
    }
    return maxIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////