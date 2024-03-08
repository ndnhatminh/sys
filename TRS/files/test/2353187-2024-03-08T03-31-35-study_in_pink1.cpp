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


// Clamping function
int clamp(int x, int min, int max) {
    if (x > max) x = max;
    else if (x < min) x = min;
    else x = x;
    return x;
}


////////////////////////////////////////////
// For future references
//  HP1 = clamp(HP1, 0, 666);
//  HP2 = clamp(HP2, 0, 666);
//  EXP1 = clamp(EXP1, 0, 600);
//  EXP2 = clamp(EXP2, 0, 600);
//  M1 = clamp(M1, 0, 3000);
//  M2 = clamp(M2, 0, 3000);
////////////////////////////////////////////


// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {

    if ((E1 > 99) or (E1 < 0)) return -99;
    double dEXP1 = EXP1;
    double dEXP2 = EXP2;
    double dE1 = E1;

    if (dE1 >= 0 && dE1 <= 3) {
        int D = dE1 * 3 + dEXP1 * 7;
        if (D % 2 == 0) dEXP1 += D / 200;
        else dEXP1 -= (D / 100.00);
    }
    else if (dE1 >= 4 && dE1 <= 99) {
        dEXP1 = dEXP1 - dE1;
    }

    if (dE1 == 0) {
        dEXP2 += 29;
    }
    else if (dE1 == 1) {
        dEXP2 += 45;
    }
    else if (dE1 == 2) {
        dEXP2 += 75;
    }
    else if (dE1 == 3) {
        dEXP2 += 149;
    }
    else if (dE1 >= 4 && dE1 <= 19) {
        dEXP2 += (dE1 / 4 + 19);
    }
    else if (dE1 >= 20 && dE1 <= 49) {
        dEXP2 += (dE1 / 9 + 21);
    }
    else if (dE1 >= 50 && dE1 <= 65) {
        dEXP2 += (dE1 / 16 + 17);
    }
    else if (dE1 >= 66 && dE1 <= 79) {
        dEXP2 += (dE1 / 4 + 19);
        if (dEXP2 > 200) {
            dEXP2 += (dE1 / 9 + 21);
        }
    }
    else if (dE1 >= 80 && dE1 <= 99) {
        dEXP2 += (dE1 / 4 + 19);
        dEXP2 += (dE1 / 9 + 21);
        if (dEXP2 > 400) {
            dEXP2 += (dE1 / 16 + 17);
            dEXP2 *= 1.15;
        }
    }

    //Rounding
    dEXP1 = ceil(dEXP1);
    dEXP2 = ceil(dEXP2);

    //Clamping
    EXP1 = clamp(dEXP1, 0, 600);
    EXP2 = clamp(dEXP2, 0, 600);

    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {

    // Declaring
    int lo, hi, count;
    int MSpent = 0;
    int P[11] = { 32,47,28,79,100,50,22,83,64,11 };
    double P1, P2, P3;
    double HP = HP1;
    double EXP = EXP1;
    double M = M1;

    // Road 01 ////////////////////////////
    for (int i = 1; i < 100; i++) {
        if (pow(i, 2) <= EXP) {
            lo = pow(i, 2);
        }
        else if ((pow(i, 2)) > EXP) {
            hi = pow(i, 2);
            break;
        }
    }
    if ((EXP - lo) <= (hi - EXP)) {
        P1 = 100;
    }
    else {
        P1 = ((EXP / hi) + 80) / 1.23;
    }
    ///////////////////////////////////////

    // Road 02 ////////////////////////////

    while (true) {
        //First event
        if (HP < 200) {
            HP *= 1.3;
            MSpent += 150;
        }
        else {
            HP *= 1.1;
            MSpent += 70;
        }
        HP = ceil(HP);
        if (MSpent > M) break;
        if ((MSpent >= (M / 2)) && (E2 % 2 != 0)) break;
        //Second event
        if (EXP < 400) {
            MSpent += 200;
        }
        else {
            MSpent += 120;
        }
        EXP = ceil(EXP * 1.13);
        if (MSpent > M) break;
        if ((MSpent >= (M / 2)) && (E2 % 2 != 0)) break;
        //Third event
        if (EXP < 300) {
            MSpent += 100;
            EXP = ceil(EXP * 0.9);
        }
        else {
            MSpent += 120;
            EXP = ceil(EXP * 0.9);
        }
        if (MSpent > M) break;
        if ((MSpent >= (M / 2)) && (E2 % 2 != 0)) break;
        if (E2 % 2 == 0) break;
    }
    M -= MSpent;

    ///////////////////////////////////////

    HP = ceil(HP * 0.83);
    EXP = ceil(EXP * 1.17);
    for (int i = 1; i < 100; i++) {
        if (pow(i, 2) <= EXP) {
            lo = pow(i, 2);
        }
        else if (pow(i, 2) > EXP) {
            hi = pow(i, 2);
            break;
        }
    }
    if ((EXP - lo) <= (hi - EXP)) {
        P2 = 100;
    }
    else {
        P2 = ((EXP / hi) + 80) / 1.23;
    }

    // Road 03 ////////////////////////////
    if (E2 / 10 < 0) {
        P3 = P[E2];
    }
    else {
        P3 = P[(E2 / 10 + (E2 - 10 * (E2 / 10))) % 10];
    }
    ///////////////////////////////////////

    // Conclusion? /////////////
    if ((P1 == 100) && (P2 == 100) && (P3 == 100)) {
        EXP = ceil(EXP * 0.75);
    }
    else if (((P1 + P2 + P3) / 3) < 50) {
        HP = ceil(HP * 0.85);
        EXP = ceil(EXP * 1.15);
    }
    else {
        HP = ceil(HP * 0.9);
        EXP = ceil(EXP * 1.2);
    }
    ////////////////////////////

    HP1 = clamp(HP, 0, 666);
    EXP1 = clamp(EXP, 0, 600);
    M1 = clamp(M, 0, 3000);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    int temp, Taxi, Duo = 0;
    int row = 0;
    int col = 0;
    double dEXP1 = EXP1;
    double dEXP2 = EXP2;
    double dHP1 = HP1;
    double dHP2 = HP2;

    //Finding meet coords
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            temp = ((E3 * j) + (i * 2)) * (i - j);
            if (temp > (E3 * 2)) row++;
            if (temp < (-E3)) col++;
        }
    }
    while (row > 9) {
        row = (row % 10) + (row / 10);
    }
    while (col > 9) {
        col = (col % 10) + (col / 10);
    }
    
    //The Taxi's score
    Taxi = ((E3 * col) + (row * 2)) * (row - col);
    Duo = Taxi;

    //Finding the duo's score
    ///// Check lower left diagonal
    for (int i = row + 1, j = col - 1; i < 10 && j >= 0; ++i, --j) {
        if ((((E3 * j) + (i * 2)) * (i - j)) > Duo) {
            Duo = (((E3 * j) + (i * 2)) * (i - j));
        }
    }

    ///// Check lower right diagonal
    for (int i = row + 1, j = col + 1; i < 10 && j < 10; ++i, ++j) {
        if ((((E3 * j) + (i * 2)) * (i - j)) > Duo) {
            Duo = (((E3 * j) + (i * 2)) * (i - j));
        }
    }

    //Returns
    if (abs(Taxi) > abs(Duo)) {
        EXP1 = ceil(dEXP1 * 0.88);
        EXP2 = ceil(dEXP2 * 0.88);
        HP1 = ceil(dHP1 * 0.9);
        HP2 = ceil(dHP2 * 0.9);
        return Taxi;
    }
    else {
        EXP1 = ceil(dEXP1 * 1.12);
        EXP2 = ceil(dEXP2 * 1.12);
        HP1 = ceil(dHP1 * 1.1);
        HP2 = ceil(dHP2 * 1.1);
        return Duo;
    }
}

// Task 4
int checkPassword(const char* s, const char* email) {
    const char* ValidChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890@#$%!";
    const char* SpecialChars = "@#%$!";
    char se[101];

    //Check length validity
    if (strlen(s) < 8) {
        return -1;
    }
    else if (strlen(s) > 20) {
        return -2;
    }
    ///////////////////////


    //Look for se in s, pointer to se if found, null otherwise
    const char* whereat = strchr(email, '@');
    size_t length = whereat - email;
    strncpy(se, email, length); //Copy substring before @ from email to se
    se[length] = '\0'; //Give se a null terminator
    const char* sei = strstr(s, se);
    if (sei != NULL) {
        return -(300 + (sei - s)); //sei - s gives returns length of substring before first se occurence
    }
    //////////////////////////////////////////////////////////

    //Check for 3+ consecutive chars
    int sci = 0;
    for (sci = 0; sci < strlen(s) - 2; sci++) {
        if (s[sci] == s[sci + 1] && s[sci] == s[sci + 2]) {
            break;
        }
    }

    if (sci < strlen(s) - 2) return -(400 + sci);
    ////////////////////////////////

    //Check for special chars
    bool flag = 0;
    size_t index = 0; //Initialize index to point to the start of the string
    while (s[index] != '\0') { // Loop until the null terminator is encountered
        if (strchr(SpecialChars, s[index]) != nullptr) {
            flag = 1; //Flag the occurence
            break; //At least one special character found
        }
        index++; //Move to the next character
    }
    if (flag != 1) return -5;
    /////////////////////////

    //Check for any invalid characters
    index = 0; //Re-initialize index to point to the start of the string
    while (s[index] != '\0') { //Loop until the null terminator is encountered
        if (strchr(ValidChars, s[index]) == nullptr) {
            return 0; //Invalid character found, return 0 which is the start of any string
        }
        index++; //Move to the next character
    }
    //////////////////////////////////

    //It wont trigger any checks if the string is valid so it will arrive at this point and returns -10
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    //Defining the array types
    struct Data {
        string pwd;
        int count;
    };

    //Initializing the array
    Data storage[num_pwds + 1];
    for (int i = 0; i <= num_pwds; i++) {
        storage[i].pwd = ""; //Initialize string to empty
        storage[i].count = 0; //Initialize counter to zero
    }

    //Storing unique elements, and counts of occurences
    int index = 0; //Index of where the storing process is at
    for (int i = 0; i < num_pwds; i++) {
        bool isUnique = true; //Initialise a bool for flagging
        //Check if the current element matches anything already in storage
        for (int j = 0; j < index; j++) {
            if (storage[j].pwd == arr_pwds[i]) {
                isUnique = false; //Flagged as a repeated element, increment the count then break
                storage[j].count++;
                break;
            }
        }
        //If the password is unique, store it with the count 1
        if (isUnique) {
            storage[index].pwd = arr_pwds[i];
            storage[index].count = 1;
            index++;
        }
    }

    //Find ones with most occurences and is the longest string
    int maxCount = 0; //Initialize an index for highest counts of reoccurence
    int maxLen = 0; //Initialize an index for highest character length
    string StrLong = ""; //Initialize an empty string to store the longest one for later use
    for (int i = 0; i < index; i++) {
        if (storage[i].count > maxCount) maxCount = storage[i].count; //Get highest count
    }
    for (int i = 0; i < index; i++) {
        if ((storage[i].pwd.length() > maxLen) && (storage[i].count == maxCount)) {
            //Get longest string
            maxLen = storage[i].count;
            StrLong = storage[i].pwd;
        }
    }

    //Find index of the first occurence of StrLong in arr_pwds
    for (int i = 0; i < num_pwds; i++) {
        if (arr_pwds[i] == StrLong) {
            index = i;
            break;
        }
    }
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////