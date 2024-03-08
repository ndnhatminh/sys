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
int rounding(double numToRound) {
    if ((numToRound - static_cast<int>(numToRound) > 0.001))
        return static_cast<int>(ceil(numToRound));
    else
        return static_cast<int>(floor(numToRound));
}
/**
 * Calculates the total experience points (EXP) for two players based on a given condition.
 * 
 * @param EXP1 The current EXP of player 1 (input/output parameter)
 * @param EXP2 The current EXP of player 2 (input/output parameter)
 * @param E1 The condition value used to calculate the EXP
 * @return The sum of EXP1 and EXP2 after the calculation
 */
int firstMeet(int& EXP1, int& EXP2, int E1) { 
    //check if E1 is out of range [0,99]
    if (E1 < 0 || E1 > 99){
        return -99; //return -99 and do nothing
    }

    // Apply bounds
    EXP1 = min(EXP1, 600);
    EXP2 = min(EXP2, 600);
    EXP1 = max(EXP1, 0);
    EXP2 = max(EXP2, 0);

    if (E1 >= 0 && E1 <= 3) {
        // Update EXP2 based on E1
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
                EXP2 += 29 + 45 + 75;
                break;
        }
    // Apply bounds
    EXP1 = min(EXP1, 600);
    EXP2 = min(EXP2, 600);
    EXP1 = max(EXP1, 0);
    EXP2 = max(EXP2, 0);

        // Calculate D
        int D = 3 * E1 + EXP1 * 7;

        // Adjust temp based on D
        double temp = EXP1;
        if (D % 2 == 0) {
            temp += D / 200.0;
        } else {
            temp -= D / 100.0;
        }

        // Update EXP1
        EXP1 = rounding((temp));

        // Apply bounds
        EXP1 = min(EXP1, 600);
        EXP2 = min(EXP2, 600);
        EXP1 = max(EXP1, 0);
        EXP2 = max(EXP2, 0);


    } else {
        // Apply bounds
        EXP1 = min(EXP1, 600);
        EXP2 = min(EXP2, 600);
        EXP1 = max(EXP1, 0);
        EXP2 = max(EXP2, 0);
        // Handle other cases for E1
        double temp = static_cast<double>(EXP2);
        if (E1 >= 4 && E1 <= 19) {
            temp += static_cast<double>(E1) / 4.0 + 19.0;
        } else if (E1 >= 20 && E1 <= 49) {
            temp += static_cast<double>(E1) / 9.0 + 21.0;
        } else if (E1 >= 50 && E1 <= 65) {
            temp += static_cast<double>(E1) / 16.0 + 17.0;
        } else if (E1 >= 66 && E1 <= 79) {
            temp += static_cast<double>(E1) / 4.0 + 19.0;
            temp = ceil(temp);
            if (temp > 200) {
                temp += E1 / 9.0 + 21.0;
                temp = ceil(temp);
            }
        } else if (E1 >= 80 && E1 <= 99) {
            temp = temp + (static_cast<double>(E1)/4.0 + 19.0);
            temp = ceil(temp);
            temp += (static_cast<double>(E1)/9.0 + 21.0);
            temp = ceil(temp);
            if (temp > 400) {
                temp += (static_cast<double>(E1) / 16.0 + 17.0);
                temp = ceil(temp);
                temp *= 1.15;
                temp = ceil(temp);
            }

        }
        // Update EXP1 and EXP2
        EXP1 -= E1;
        EXP2 = rounding((temp));
            

        // Apply bounds
        EXP1 = min(EXP1, 600);
        EXP2 = min(EXP2, 600);
        EXP1 = max(EXP1, 0);
        EXP2 = max(EXP2, 0);
    }

    // Apply bounds
    EXP1 = min(EXP1, 600);
    EXP2 = min(EXP2, 600);
    EXP1 = max(EXP1, 0);
    EXP2 = max(EXP2, 0);

    return EXP1 + EXP2;
}

// Task 2
bool isPerfect(int N) {
    // Check if N is a perfect square
    double root = sqrt(N);
    return (root == floor(root));
}

int findNearestPerfectSquare(int EXP1) {

    // Apply bounds
    EXP1 = min(EXP1, 600);
    EXP1 = max(EXP1, 0);
    
    if (isPerfect(EXP1)) {
        // If EXP1 is already a perfect square, return it
        return EXP1;
    }

    // Apply bounds
    EXP1 = min(EXP1, 600);
    EXP1 = max(EXP1, 0);

    // Find the closest perfect squares above and below EXP1
    int aboveN = ceil(sqrt(EXP1)) * ceil(sqrt(EXP1));
    int belowN = floor(sqrt(EXP1)) * floor(sqrt(EXP1));

    // Choose the one with minimum difference
    if (abs(aboveN - EXP1) <= abs(belowN - EXP1)) {
        return aboveN;
    } else {
        return belowN;
    }
}

void eventsRoute2_odd(int& HP1, int& M1, int& EXP1) {
    static int spent = 0;
    // Apply bounds
    HP1 = min(HP1, 666);
    EXP1 = min(EXP1, 600);
    M1 = min(M1, 3000);
    HP1 = max(HP1, 0);
    EXP1 = max(EXP1, 0);
    M1 = max(M1, 0);

    // Buy food or water
    if (HP1 < 200) {
        // Sherlock needs food and beverage
        HP1 = rounding((1.3 * HP1));
        spent += 150;
    } else {
        // Sherlock needs water 
        HP1 = rounding((1.1 * HP1));
        spent += 70;
    }
    if (spent > M1 / 2) {
        M1 = M1 - spent;
        spent = 0; // reset spent to 0 after each input group
        return; // Exit the function if spent > M1/2
    }

    // Apply bounds
    HP1 = min(HP1, 666);
    EXP1 = min(EXP1, 600);
    M1 = min(M1, 3000);
    HP1 = max(HP1, 0);
    EXP1 = max(EXP1, 0);
    M1 = max(M1, 0);
    
    // Decide on transportation
    if (EXP1 < 400) {
        // Take a taxi
        EXP1 = rounding((1.13 * EXP1));
        spent += 200;
    } else {
        // Take a horse-drawn carriage
        EXP1 = rounding((1.13 * EXP1));
        spent += 120;
    }
    if (spent > M1 / 2) {
        M1 = M1 - spent;
        spent = 0; // reset spent to 0 after each input group
        return; // Exit the function if spent > M1/2
    }

    // Apply bounds
    HP1 = min(HP1, 666);
    EXP1 = min(EXP1, 600);
    M1 = min(M1, 3000);
    HP1 = max(HP1, 0);
    EXP1 = max(EXP1, 0);
    M1 = max(M1, 0);

    // Help the homeless person
    if (EXP1 < 300) {
        // cost 100
        EXP1 = rounding((0.9 * EXP1));
        spent += 100;
    } else {
        // cost 120
        EXP1 = rounding((0.9 * EXP1));
        spent += 120;
    }
    if (spent > M1 / 2) {
        M1 = M1 - spent;
        spent = 0; // reset spent to 0 after each input group
        return; // Exit the function if spent > M1/2
    }

    // Apply bounds
    HP1 = min(HP1, 666);
    EXP1 = min(EXP1, 600);
    M1 = min(M1, 3000);
    HP1 = max(HP1, 0);
    EXP1 = max(EXP1, 0);
    M1 = max(M1, 0);

}

void eventsRoute2_even(int& HP1, int& M1, int& EXP1) {
    static int spent = 0;
    int limit = M1;
    // Apply bounds
    HP1 = min(HP1, 666);
    EXP1 = min(EXP1, 600);
    M1 = min(M1, 3000);
    HP1 = max(HP1, 0);
    EXP1 = max(EXP1, 0);
    M1 = max(M1, 0);

    // Buy food or water
    if (HP1 < 200) {
        // Sherlock needs food and beverage
        HP1 = rounding((1.3 * HP1));
        spent += 150;
        M1 -= 150;
    } else {
        // Sherlock needs water 
        HP1 = rounding((1.1 * HP1));
        spent += 70;
        M1 -= 70;
    }
    if (spent > limit) {
        M1 = 0;
        spent = 0;
        return; // Exit the function if spent > M1
    }

    // Apply bounds
    HP1 = min(HP1, 666);
    EXP1 = min(EXP1, 600);
    M1 = min(M1, 3000);
    HP1 = max(HP1, 0);
    EXP1 = max(EXP1, 0);
    M1 = max(M1, 0);

    // Decide on transportation
    if (EXP1 < 400) {
        // Take a taxi
        EXP1 = rounding((1.13 * EXP1));
        spent += 200;
        M1 -= 200;
    } else {
        // Take a horse-drawn carriage
        EXP1 = rounding((1.13 * EXP1));
        spent += 120;
        M1 -= 120;
    }
    if (spent > limit) {
        M1 = 0;
        spent = 0;
        return; // Exit the function if spent > M1
    }

    // Apply bounds
    HP1 = min(HP1, 666);
    EXP1 = min(EXP1, 600);
    M1 = min(M1, 3000);
    HP1 = max(HP1, 0);
    EXP1 = max(EXP1, 0);
    M1 = max(M1, 0);

    // Help the homeless person
    if (EXP1 < 300) {
        // cost 100
        EXP1 = rounding((0.9 * EXP1));
        spent += 100;
        M1 -= 100;
    } else {
        // cost 120
        EXP1 = rounding((0.9 * EXP1));
        spent += 120;
        M1 -= 120;
    }
    if (spent > limit) {
        M1 = 0;
        spent = 0;
        return; // Exit the function if spent > M1
    }

    // Apply bounds
    HP1 = min(HP1, 666);
    EXP1 = min(EXP1, 600);
    M1 = min(M1, 3000);
    HP1 = max(HP1, 0);
    EXP1 = max(EXP1, 0);
    M1 = max(M1, 0);

    // if Sherlock has enough money for 3 events, reset spent after each input group
    spent = 0;

}

/**
 * Calculates the trace of luggage based on the given parameters.
 * 
 * @param HP1 The current value of HP1 (health points).
 * @param EXP1 The current value of EXP1 (experience points).
 * @param M1 The current value of M1 (money).
 * @param E2 The value of E2 (a parameter).
 * @return The sum of HP1, EXP1, and M1 after performing the trace of luggage.
 *         If E2 is out of range [0, 99], returns -99.
 */
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    //check if E2 is out of range [0,99]
    if (E2 < 0 || E2 > 99){
        return -99; //return -99 and do nothing
    }
    // Apply bounds
    HP1 = min(HP1, 666);
    EXP1 = min(EXP1, 600);
    M1 = min(M1, 3000);
    HP1 = max(HP1, 0);
    EXP1 = max(EXP1, 0);
    M1 = max(M1, 0);
    // TODO: Complete this function

    // variables
    double p[3] = {0.0, 0.0, 0.0};


    // 1st route
    // Possibility road 1
    int s = findNearestPerfectSquare(EXP1);
    if (EXP1 >= s){
        p[0] = 1.0;
    } else {
        p[0] = static_cast<double>((static_cast<double>( EXP1) / static_cast<double>(s)) + 80.0) / 123.0;
    }
    // 2nd route
    if (M1 == 0){
        // do nothing
    } else {
        if (E2 % 2 !=0){ // check if E2 is an odd number
            int temp = M1;
            while(M1 == temp){
                eventsRoute2_odd(HP1, M1, EXP1);\
            }
        } else {
            eventsRoute2_even(HP1, M1, EXP1);
        }
    }

    // Apply bounds
    HP1 = min(HP1, 666);
    EXP1 = min(EXP1, 600);
    M1 = min(M1, 3000);
    HP1 = max(HP1, 0);
    EXP1 = max(EXP1, 0);
    M1 = max(M1, 0);
    
    // Walking till the end
    HP1 = rounding((0.83 * HP1));
    EXP1 = rounding((1.17 * EXP1));

    // Apply bounds
    HP1 = min(HP1, 666);
    EXP1 = min(EXP1, 600);
    M1 = min(M1, 3000);
    HP1 = max(HP1, 0);
    EXP1 = max(EXP1, 0);
    M1 = max(M1, 0);

    // Possibility road 2
    int t = findNearestPerfectSquare(EXP1);
    if (EXP1 >= t){
        p[1] = 1.0;
    } else {
        p[1] = static_cast<double>((static_cast<double>( EXP1) / static_cast<double>(s)) + 80.0) / 123.0;
    }

    // 3rd route
    int q[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2 < 10){
        p[2] = static_cast<double>(q[E2]) / 100.0;
    } else {
        p[2] = static_cast<double>(q[(E2/10 + E2%10)%10]) / 100.0;
    }

    // Average probability
    double ave = (p[0] + p[1] + p[2]) / 3.0;
    if (p[0] == 1 && p[1] == 1 && p[2] == 1){
        EXP1 = rounding((0.75 * EXP1));
    } else {
        if (ave < 0.5){
            HP1 = rounding((0.85 * HP1));
            EXP1 = rounding((1.15 * EXP1));
        } else {
            HP1 = rounding((0.9 * HP1));
            EXP1 = rounding((1.2 * EXP1));
        }
    }

    // Apply bounds
    HP1 = min(HP1, 666);
    EXP1 = min(EXP1, 600);
    M1 = min(M1, 3000);
    HP1 = max(HP1, 0);
    EXP1 = max(EXP1, 0);
    M1 = max(M1, 0);
    
    return HP1 + EXP1 + M1;
}
// Task 3
/**
 * Calculates the score and updates the attributes of Sherlock and Watson based on their interaction with a taxi.
 * 
 * @param HP1 The health points of Sherlock.
 * @param EXP1 The experience points of Sherlock.
 * @param HP2 The health points of Watson.
 * @param EXP2 The experience points of Watson.
 * @param E3 The value used to calculate the map for the taxi.
 * @return The score of either the taxi or Sherlock and Watson, depending on the outcome.
 */
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    //check if E3 is out of range [0,99]
    if (E3 < 0 || E3 > 99){
        return -99; //return -99 and do nothing
    }

    // Apply bounds
    HP1 = min(HP1, 666);
    HP2 = min(HP2, 666);
    EXP1 = min(EXP1, 600);
    EXP2 = min(EXP2, 600);
    HP1 = max(HP1, 0);
    HP2 = max(HP2, 0);
    EXP1 = max(EXP1, 0);
    EXP2 = max(EXP2, 0);
    // TODO: Complete this function
    
    // initialize map for taxi
    int map_taxi[10][10];
    // assign values to each position
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            map_taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j); // i-row; j-column
        }
    }
    // find meeting point
    // 1. find i-row number
    int meeting_row = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if(map_taxi[i][j] > E3*2) {
                meeting_row += 1;
            }
        }
    }
    if(meeting_row < 10){
        // do nothing
    } else {
        int temp = (meeting_row/10 + meeting_row%10);
        meeting_row = temp/10 + temp%10;
    }
    // 2. find j-column number
    int meeting_col = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if(map_taxi[i][j] < -E3) {
                meeting_col += 1;
            }
        }
    }
    if(meeting_col < 10){
        // do nothing
    } else {
        int temp = (meeting_col/10 + meeting_col%10);
        meeting_col = temp/10 + temp%10;
    }
    // we get the meeting point is (meeting_row, meeting_col)
    // At this point, taxi's score is 
    int taxi_score = map_taxi[meeting_row][meeting_col];

    // Next we need to find Sherlock and Watson's score
    // Their score equals to max(max(left_diagonal), max(right_diagonal))
    // take absolute of the value if negative
    // max(left_diagonal)
    int left_max = -10000;
    if (meeting_col >= meeting_row){
        for (int i=0 , j = abs(meeting_col-meeting_row); i < 10 && j < 10; i++, j++){
            if(left_max < map_taxi[i][j]){
                left_max = map_taxi[i][j];
            }
        }
    } else {
        for (int i= abs(meeting_col-meeting_row) , j = 0; i < 10 && j < 10; i++, j++){
            if(left_max < map_taxi[i][j]){
                left_max = map_taxi[i][j];
            }
        }
    }
    // max(right_diagonal)
    int right_max = -10000;
    if (meeting_row + meeting_col >= 10){
        for (int i = (meeting_col + meeting_row) - 9, j = 9; i < 10 && j >= 0; i++, j --){
            if(right_max < map_taxi[i][j]){
                right_max = map_taxi[i][j];
            }                                                                       
        }
    } else {
        for (int i = 0, j = meeting_col + meeting_row; i < 10 && j >= 0; i++, j--){ //j = meeting_col + meeting_row
            if(right_max < map_taxi[i][j]){
                right_max = map_taxi[i][j];
            }            
        }
    }
    // Sherlock and Watson's score
    int theirscore = max(right_max, left_max);
    if (theirscore < 0){
        theirscore = abs(theirscore);
    }
    // check if they can catch the taxi
    if (abs(taxi_score) > theirscore){
        // cannot catch the taxi
        EXP1 = rounding((0.88 * EXP1));
        HP1 = rounding((0.9 * HP1));
        EXP2 = rounding((0.88 * EXP2));
        HP2 = rounding((0.9 * HP2));

        // Apply bounds
        HP1 = min(HP1, 666);
        HP2 = min(HP2, 666);
        EXP1 = min(EXP1, 600);
        EXP2 = min(EXP2, 600);
        HP1 = max(HP1, 0);
        HP2 = max(HP2, 0);
        EXP1 = max(EXP1, 0);
        EXP2 = max(EXP2, 0);

        return taxi_score;
    } else {
        // can catch the taxi, also abs(taxi_score)==theirscore return theirscore
        EXP1 = rounding((1.12 * EXP1));
        HP1 = rounding((1.1 * HP1));
        EXP2 = rounding((1.12 * EXP2));
        HP2 = rounding((1.1 * HP2));       

        // Apply bounds
        HP1 = min(HP1, 666);
        HP2 = min(HP2, 666);
        EXP1 = min(EXP1, 600);
        EXP2 = min(EXP2, 600);
        HP1 = max(HP1, 0);
        HP2 = max(HP2, 0);
        EXP1 = max(EXP1, 0);
        EXP2 = max(EXP2, 0);

        return theirscore;
    }

}

// Task 4

bool isValidCharacter(char ch) {
    // Define a string of valid characters (numbers, letters, and special characters)
    const string validChars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@#%$!";
    
    // Check if the character is in the validChars string
    for (int i = 0; i < static_cast<int>(validChars.size()); i++){
        if (ch == validChars[i]) {
            return true;
        }
    }
    return false;
}

/**
 * Checks the validity of a password based on various criteria.
 *
 * @param s The password string to be checked.
 * @param email The email string used to extract a substring for comparison.
 * @return Returns a negative integer code indicating the reason for password invalidity.
 *         -1: Password length is less than 8 characters.
 *         -2: Password length is greater than 20 characters.
 *         -(300 + sei): The substring extracted from the email is found in the password.
 *                        'sei' is the index of the first occurrence of the substring in the password.
 *         -(400 + sci): More than 2 consecutive identical characters are found in the password.
 *                        'sci' is the index of the first occurrence of the consecutive characters.
 *         -5: No special characters (@, #, %, $, !) are found in the password.
 *         'i': The index of the first invalid character found in the password.
 *         -10: The password is valid.
 */
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
    // Check password length
    int passwordLength = static_cast<int>(strlen(s));
    if (passwordLength >= 8 && passwordLength <= 20) {
        // do nothing
    } else if (passwordLength < 8) {
        return -1;
    } else {
        return -2;
    }
    
    // Check for substring se
    // find the se string
    char se[200];
    int atpos = 0;
    for (int i = 0; i < static_cast<int>(strlen(email)); ++i){
        char ch = email[i];
        if (ch == '@'){
            atpos = i;
            break;
        }
    }
    // get se from email
    strncpy(se, email, atpos);
    se[atpos] = '\0'; // Null-terminate the substring
    // check if se in s
    if (strstr(s, se) == nullptr) {
        // do nothing
    } else {
        const char* result = strstr(s, se);
        // const char* not char* because strstr() gives us a const char* not char*
        int sei = result - s; // Calculate the index of the first occurrence of se in s
        return -(300 + sei);
    }
    
    // Check for consecutive identical characters
    for (int i = 2; i < passwordLength; ++i) {
        if (s[i] == s[i - 1] && s[i] == s[i - 2]) {
            // if s[i] and s[i-1] and s[i-2] simultaneously like one another
            // Conclusion: there are more than 2 characters consecutive like one another
            // and return -(400 + sci)
            // sci is the first index of the first string containing more than 2 consecutive identical characters
            return -(400 + (i-2));
        }
    }

    // Check for special characters
    bool hasSpecialChar = false; // assume no special characters
    for (int i = 0; i < passwordLength; ++i) {
        char ch = s[i];
        if (ch == '@' || ch == '#' || ch == '%' || ch == '$' || ch == '!') {
            hasSpecialChar = true;
            break;
        }
    }
    if (hasSpecialChar){
        // do nothing
    } else {
        return -5; // if there is no special characters, return -5
    }
    
    // Check for valid characters
    for (int i = 0; i < passwordLength; ++i) {
        char ch = s[i];
        if (isValidCharacter(ch) == false) {
            return i; // return the index of the first invalid character
        }
    }

    // If all conditions are met, the password is valid and return -10
    return -10; 
}

// Task 5
/**
 * Finds the correct password from an array of passwords.
 * The correct password is determined based on its frequency and length.
 *
 * @param arr_pwds An array of passwords.
 * @param num_pwds The number of passwords in the array.
 * @return The index of the correct password in the array.
 */
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    // Initialize variables to track the most frequent and longest password
    int maxFrequency = 0;
    int maxLength = 0;
    int correctPasswordIndex = -1;

    // Traverse the array and update password information
    for (int i = 0; i < num_pwds; ++i) {
        const char* pwd = arr_pwds[i];
        int length = strlen(pwd);

        // Check if this password is more frequent or longer
        int frequency = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(pwd, arr_pwds[j]) == 0) {
                frequency++;
            }
        }
        // frequency, length of that element in arr_pwds are found

        if (frequency > maxFrequency || (frequency == maxFrequency && length > maxLength)) {
            maxFrequency = frequency;
            maxLength = length;
            correctPasswordIndex = i;
            }
        }

    return correctPasswordIndex;
    
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
