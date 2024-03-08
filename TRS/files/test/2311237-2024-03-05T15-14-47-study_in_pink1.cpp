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



// Define the min and max possible value for hp, exp and money value
const int HP_FLOOR = 0, HP_CEIL = 666;
const int EXP_FLOOR = 0, EXP_CEIL = 600;
const int MONEY_FLOOR = 0, MONEY_CEIL = 3000;
const int E_FLOOR = 0, E_CEIL = 99;

#pragma region "Task 1: First Meet"
int firstMeet(int & exp1, int & exp2, int e1) {
    const int E1_CASE_1_CEIL = 3;

    // Check for a valid E1 value
    if (!isInRange(e1, E_FLOOR, E_CEIL)) {
        return -99;
    }

    // Check if E1 value is in range of Case 1 or Case 2, for readability, E1 value will be compared to 0 once again in this function
    if (isInRange(e1, E_FLOOR, E1_CASE_1_CEIL)) {
        firstMeetCase1(exp1, exp2, e1);
    } else {
        firstMeetCase2(exp1, exp2, e1);
    }
    
    return exp1 + exp2;
}

void firstMeetCase1(int & exp1, int & exp2, int e1) {
    const int EXP_E_0 = 29;
    const int EXP_E_1 = 45;
    const int EXP_E_2 = 75;
    const int EXP_E_3 = EXP_E_0 + EXP_E_1 + EXP_E_2;
    const int D_VALUE = e1 * 3 + exp1 * 7;
    float exp1F = exp1;

    // Watson exp calculation in case 1
    switch (e1) {
    case 0:
        exp2 += EXP_E_0;
        break;
    case 1:
        exp2 += EXP_E_1;
        break;
    case 2:
        exp2 += EXP_E_2;
        break;
    case 3:
        exp2 += EXP_E_3;
        break;
    }
    
    // Sherlock exp calculation in case 1
    if (D_VALUE % 2 == 0) {
        exp1F += (float)D_VALUE/200;
    } else {
        exp1F -= (float)D_VALUE/100;   
    }
    
    exp1 = ceil(exp1F);

    clamp(exp1, EXP_FLOOR, EXP_CEIL);
    clamp(exp2, EXP_FLOOR, EXP_CEIL);
}

void firstMeetCase2(int & exp1, int & exp2, int e1) {
    const int E_INFO_1_FLOOR = 4, E_INFO_1_CEIL = 19;
    const int EXP_E_INFO_1 = ceil((float)e1/4 + 19);
    
    const int E_INFO_2_FLOOR = 20, E_INFO_2_CEIL = 49;
    const int EXP_E_INFO_2 = ceil((float)e1/9 + 21);
    
    const int E_INFO_3_FLOOR = 50, E_INFO_3_CEIL = 65;
    const int EXP_E_INFO_3 = ceil((float)e1/16 + 17);
    
    const int E_INFO_4_FLOOR = 66, E_INFO_4_CEIL = 79;
    
    const int E_INFO_5_FLOOR = 80, E_INFO_5_CEIL = 99;
    
    // Watson exp calculation in case 2
    if (isInRange(e1, E_INFO_1_FLOOR, E_INFO_1_CEIL)) {
        exp2 += EXP_E_INFO_1;
    } else if (isInRange(e1, E_INFO_2_FLOOR, E_INFO_2_CEIL)) {
        exp2 += EXP_E_INFO_2;
    } else if (isInRange(e1, E_INFO_3_FLOOR, E_INFO_3_CEIL)) {
        exp2 += EXP_E_INFO_3;
    } else if (isInRange(e1, E_INFO_4_FLOOR, E_INFO_4_CEIL)) {
        exp2 += EXP_E_INFO_1;
        if (exp2 > 200) {
            exp2 += EXP_E_INFO_2;
        }
    } else if (isInRange(e1, E_INFO_5_FLOOR, E_INFO_5_CEIL)) {
        exp2 += EXP_E_INFO_1 + EXP_E_INFO_2;
        if (exp2 > 400) {
            exp2 += EXP_E_INFO_3;
            exp2 += ceil((float) exp2 * 0.15);
        }
    }

    // Sherlock exp calculation in case 2
    exp1 -= e1;
    
    clamp(exp1, EXP_FLOOR, EXP_CEIL);
    clamp(exp2, EXP_FLOOR, EXP_CEIL);
}
#pragma endregion

#pragma region "Task 2: Trace Luggage"
int traceLuggage(int &hp1, int &exp1, int &m1, int e2) {
    // TODO: Complete this function
    int answer;
    if (!isInRange(e2, E_FLOOR, E_CEIL)) {
        return -99;
    }

    // Calculate probabilitiy from each of the 3 paths
    float probabilityPath1 = traceLuggagePath1(exp1);
    float probabilityPath2 = traceLuggagePath2(hp1, exp1, m1, e2);
    float probabilityPath3 = traceLuggagePath3(e2);

    // Calculte hp1 and exp1 according to the average probability
    float averageProbability = (probabilityPath1 + probabilityPath2 + probabilityPath3) / 3;
    if (probabilityPath1 == 100 && probabilityPath2 == 100 & probabilityPath3 == 100) {
        exp1 = ceil((float)exp1 * (1.0 - 0.25));
    } else if (averageProbability < 50) {
        hp1 = ceil((float)hp1 * (1.0 - 0.15));
        exp1 += ceil((float)exp1 * 0.15);
    } else {
        hp1 = ceil((float)hp1 * (1.0 - 0.1));
        exp1 += ceil((float)exp1 * 0.2);
    }

    clamp(exp1, EXP_FLOOR, EXP_CEIL);
    clamp(hp1, HP_FLOOR, HP_CEIL);

    return hp1 + exp1 + m1;
}

float traceLuggagePath1(int &exp1) {
    int sValue = pow(round(sqrt((float)exp1)), 2);

    if (exp1 >= sValue) {
        return 100.0;
    } else {
        return (((float)exp1/sValue + 80)/123) * 100;
    }
}

float traceLuggagePath2(int &hp1, int &exp1, int &m1, int e2) {
    int halfMoney = round((float)m1 / 2);
    int moneySpent = 0;
    float probabilityPath2; // in percent

    if (e2 % 2 == 1) {
        while (true) {
            traceLuggagePath2_Event1(hp1, m1, moneySpent);
            if (moneySpent > halfMoney) {
                break;
            }

            traceLuggagePath2_Event2(exp1, m1, moneySpent);
            if (moneySpent > halfMoney) {
                break;
            }

            traceLuggagePath2_Event3(exp1, m1, moneySpent);
            if (moneySpent > halfMoney) {
                break;
            }
        }
    } else {
        if (m1 > 0) {
            traceLuggagePath2_Event1(hp1, m1, moneySpent);
        }
        if (m1 > 0) {
            traceLuggagePath2_Event2(exp1, m1, moneySpent);
        }
        if (m1 > 0) {
            traceLuggagePath2_Event3(exp1, m1, moneySpent);
        }
    }

    clamp(m1, MONEY_FLOOR, MONEY_CEIL);
    hp1 = ceil((float)hp1 * (1.0 - 0.17));
    exp1 = ceil((float)exp1 * (1.0 + 0.17));
    clamp(exp1, EXP_FLOOR, EXP_CEIL);
    clamp(hp1, HP_FLOOR, HP_CEIL);
    return traceLuggagePath1(exp1);;
}

// Event 1: Sherlock buys food
void traceLuggagePath2_Event1(int &hp1, int &m1, int &moneySpent) {  
    if (hp1 < 200) {
        hp1 += ceil((float)hp1 * 0.3);
        m1 -= 150;
        moneySpent += 150;
    } else {
        hp1 += ceil((float)hp1 * 0.1);
        m1 -= 70;
        moneySpent += 70;
    }
    clamp(hp1, HP_FLOOR, HP_CEIL);
}

// Event 2: Sherlock picks a mean of transport
void traceLuggagePath2_Event2(int &exp1, int &m1, int &moneySpent) {
    if (exp1 < 400) {
        m1 -= 200;
        moneySpent += 200;
    } else {
        m1 -= 120;
        moneySpent += 120;
    }
    exp1 += ceil((float)exp1 * 0.13);
    clamp(exp1, EXP_FLOOR, EXP_CEIL);
}

// Event 3: Sherlock asks a begger for direction to the luggage
void traceLuggagePath2_Event3(int &exp1, int &m1, int &moneySpent) {
    if (exp1 < 300) {
        m1 -= 100;
        moneySpent += 100;
    } else {
        m1 -= 120;
        moneySpent += 120;
    }
    exp1 = ceil((float)exp1 * (1.0 - 0.1));
    clamp(exp1, EXP_FLOOR, EXP_CEIL);
}

float traceLuggagePath3(int e2) {
    float probabilities[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int probabilityPath3 = 0;

    if (e2 < 10) {
        probabilityPath3 = e2;
    } else {
        int sum = (e2 / 10) + (e2 % 10);
        probabilityPath3 = sum % 10;
    }

    return probabilities[probabilityPath3];
}
#pragma endregion

#pragma region "Task 3: Chase Taxi"
int chaseTaxi(int &hp1, int &exp1, int &hp2, int &exp2, int e3) {
    // TODO: Complete this function
    if (!isInRange(e3, E_FLOOR, E_CEIL)) {
        return -99;
    }

    int row = 10, col = 10;
    int grid[row][col];
    int sortedGrid[row][col];
    int playerScore;
    int encounterX, encounterY;
    int returnValue;
    
    // Initialize the grid array
    for (int x = 0; x < row; x++) {
        for (int y = 0; y < col; y++) {
            grid[x][y] = 0;
        }
    }
    
    // Populate the grid array with the points of the car
    gridScoreCar(*grid, row, col, e3);
    
    // Find encounter position
    getEncounterPos(*grid, row, col, encounterX, encounterY, e3);

    // Find player score at (encounterX, encounterY)
    playerScore = playerScoreAt(*grid, encounterX, encounterY, row, col);
    
    if (playerScore < 0) {
        playerScore = abs(playerScore);
    }
    
    if (abs(grid[encounterX][encounterY]) > playerScore) {
        exp1 = ceil((float)exp1 * (1.0 - 0.12));
        hp1 = ceil((float)hp1 * (1.0 - 0.1));
        exp2 = ceil((float)exp2 * (1.0 - 0.12));
        hp2 = ceil((float)hp2 * (1.0 - 0.1));
        returnValue = grid[encounterX][encounterY];
    } else {
        exp1 += ceil((float)exp1 * 0.12);
        hp1 += ceil((float)hp1 * 0.1);
        exp2 += ceil((float)exp2 * 0.12);
        hp2 += ceil((float)hp2 * 0.1);
        returnValue = playerScore;
    }

    clamp(exp1, EXP_FLOOR, EXP_CEIL);
    clamp(hp1, HP_FLOOR, HP_CEIL);
    clamp(exp2, EXP_FLOOR, EXP_CEIL);
    clamp(hp2, HP_FLOOR, HP_CEIL);

    return returnValue;
}

void gridScoreCar(int* grid, int row, int col, int e3) {
    int count = 1;
    for (int x = 0; x < row; x++) {
        for (int y = 0; y < col; y++) {
            grid[(x * col) + y] = ((e3 * y) + (x * 2)) * (x - y);
            
        }
    }

    // Print all the value in 'grid[row][col]'
    // for (int x = 0; x < row; x++) {
    //     for (int y = 0; y < col; y++) {
    //         cout << grid[(x * col) + y] << " "; 
    //     }
    //     cout << endl;
    // }
}

void getEncounterPos(int* grid, int row, int col, int &x, int &y, int e3) {
    int xCounter = 0;
    int yCounter = 0;
    for (int x = 0; x < row; x++) {
        for (int y = 0; y < col; y++) {
            if (grid[(x * col) + y] > e3*2) {
                xCounter++;
            }

            if (grid[(x * col) + y] < -e3) {
                yCounter++;
            }
        }
    }

    while (xCounter >= 10) {
        xCounter = (xCounter / 10) + (xCounter % 10);
    }

    while (yCounter >= 10) {
        yCounter = (yCounter / 10) + (yCounter % 10);
    }
    
    x = xCounter;
    y = yCounter;
}

// 0 --------> y
// |
// |
// |
// v
// x
int playerScoreAt(int* grid, int x, int y, int row, int col) {
    int score = grid[(x * col) + y];
    int currentX = x;
    int currentY = y;

    // LEFT DIAGONAL
    // Down Left (x+, y-)
    while (currentX < row - 1 && currentY > 0) {
        if (score < grid[((currentX + 1) * col) + (currentY - 1)]) {
            score = grid[((currentX + 1) * col) + (currentY - 1)];
        }
        currentX++;
        currentY--;
    }

    // Up Right (x-, y+)
    currentX = x;
    currentY = y;
    while (currentX > 0 && currentY < col - 1) {
        if (score < grid[((currentX - 1) * col) + (currentY + 1)]) {
            score = grid[((currentX - 1) * col) + (currentY + 1)];
        }
        currentX--;
        currentY++;
    }

    // RIGHT DIAGONAL
    // Down Right (x+, y+)
    currentX = x;
    currentY = y;
    while (currentX < row - 1 && currentY < col - 1) {
        if (score < grid[((currentX + 1) * col) + (currentY + 1)]) {
            score = grid[((currentX + 1) * col) + (currentY + 1)];      
        }
        currentX++;
        currentY++;
    }

    // Up Left (x-, y-)
    currentX = x;
    currentY = y;
    while (currentX > 0 && currentY > 0) {
        if (score < grid[((currentX - 1) * col) + (currentY - 1)]) {
            score = grid[((currentX - 1) * col) + (currentY - 1)];
        }
        currentX--;
        currentY--;
    }
    return score;
}

#pragma endregion

#pragma region "Task 4: Check Password"
// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    string emailString = email;
    string password = s;
    string se = getUsername(emailString);
    const char specialChar[5] = {'@', '#', '%', '$', '!'};
    const int numberFloor = '0', numberCeil = '9';
    const int capLetterFloor = 'A', capLetterCeil = 'Z';
    const int letterFloor = 'a', letterCeil = 'z';
    const int minimumLength = 8, maximimLength = 20;

    // If password length is below minimum
    if (password.length() < minimumLength) {
        return -1;
    }

    // If password length is above maximum
    if (password.length() > maximimLength) {
        return -2;
    }
    
    // If password contains username
    if (password.find(se) != -1) {
        return -(300 + password.find(se));
    }

    bool hasSpecialChar = false;
    for (int i = 0; i < password.length(); i++) {
        if (i > 1) {
            // If a letter is repeated more than twice
            if (password[i] == password[i-1] && password[i] == password[i-2]) {
                return -(400 + i - 2);
            }
        }

        for (int s = 0; s < 5; s++) {
            if (password[i] == specialChar[s]) {
                hasSpecialChar = true;
            }
        }
    }
    
    // If password has 0 special character
    if (!hasSpecialChar) {
        return -5;
    }

    // If password contains invalid character
    for (int i = 0; i < password.length(); i++) {
        bool isSpecialChar = false;
        for (int s = 0; s < 5; s++) {
            if (password[i] == specialChar[s]) {
                isSpecialChar = true;
            }
        }

        if (!isInRange(password[i], numberFloor, numberCeil) && !isInRange(password[i], capLetterFloor, capLetterCeil) && !isInRange(password[i], letterFloor, letterCeil) && !isSpecialChar) {
            return i;
        }
    }

    // Password passed every checks => Valid
    return -10;
}

string getUsername(string email) {
    string se;
    for (int i = 0; i < email.length() - 1; i++) {
        if (email[i] == '@') {
            return se;
        }
        se = se + email[i];
    }
    
    return se;
}
#pragma endregion

#pragma region "Task 5: Find Correct Password"
// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    // cout << "NEW CALL" << endl;
    string passwordArray[num_pwds];

    // Convert char*[] to string[]
    for (int i = 0; i < num_pwds; i++) {
        passwordArray[i] = arr_pwds[i];
    }

    return countOccurrences(passwordArray, num_pwds);
}

int countOccurrences(string arr[], int size) {
    string uniqueElements[size]; // Array to store unique elements
    int counts[size] = {0};      // Array to store counts for each element
    int uniqueCount = 0;         // Number of unique elements

    for (int i = 0; i < size; ++i) {
        bool isUnique = true;
        // Check if the current element is already found
        for (int j = 0; j < uniqueCount; ++j) {
            if (arr[i] == uniqueElements[j]) {
                counts[j]++;
                isUnique = false;
                break;
            }
        }
        // If not found, add it to the list of unique elements
        if (isUnique) {
            uniqueElements[uniqueCount] = arr[i];
            counts[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    // Displaying the occurrences
    //cout << endl;
    //for (int i = 0; i < uniqueCount; ++i) {
    //    cout << "Element '" << uniqueElements[i] << "' occurs " << counts[i] << " times." << endl;
    //}
    
    int maxFrequency = counts[0];
    int maxFrequencyIndex = 0;
    for (int i = 1; i < uniqueCount; i++) {
        // Find the element with the highest occurrences
        if (maxFrequency < counts[i]) {
            maxFrequency = counts[i];
            maxFrequencyIndex = i;
        }
        // Find the longest string in case there are multiple highest occurrences
        if (maxFrequency == counts[i]) {
            if (uniqueElements[maxFrequencyIndex].length() < uniqueElements[i].length()) {
                maxFrequency = counts[i];
                maxFrequencyIndex = i;
            }
        }
    }
    
    // Find the index of the 'true password'
    for (int i = 0; i < size; i++) {
        if (uniqueElements[maxFrequencyIndex] == arr[i]) {
            // cout << "Max " << maxFrequency << " MaxIndex " << maxFrequencyIndex << " ";
            // cout << "Result: " << uniqueElements[i] << " with " << counts[i] <<  " at " << i << endl;
            return i;
        }
    }

    // Error code: Cannot find the 'true password' (This outcome is unlikely to happen)
    return -777;
}

#pragma endregion

#pragma region "Custom function"
// Check if value was in range of [floor, ceil]
bool isInRange(int value, int floor, int ceil) {
    if (value < floor || value > ceil) {
        return false;
    }

    return true;
}

// Clamp the value in range of [floor, ceil]
void clamp(int &value, int floor, int ceil) {
    if (value < floor) {
        value = floor;
    }

    if (value > ceil) {
        value = ceil;
    }

    return;
}
#pragma endregion
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////