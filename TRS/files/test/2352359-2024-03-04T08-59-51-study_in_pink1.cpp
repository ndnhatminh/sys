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
    
    // Return -99 if e1 is out of range
    if (!eventIsInRange(e1)) {
        return -99;
    }
    else {
        // Case 1
        if (0 <= e1 && e1 <= 3) {
            
            /* Changing Watson's EXP */
            
            const int INFO_ONE_EXP = 29, // Const exp gained information
                      INFO_TWO_EXP = 45,
                      INFO_THREE_EXP = 75;
            
            switch (e1) {
                
                // Information 1: Add 29 EXP 
                case 0:
                    exp2 += INFO_ONE_EXP; limitEXP(exp2);
                    break;
                    
                // Information 2: Add 45 EXP 
                case 1:
                    exp2 += INFO_TWO_EXP; limitEXP(exp2);
                    break;
                    
                // Information 3: Add 75 EXP
                case 2: 
                    exp2 += INFO_THREE_EXP; limitEXP(exp2);
                    break;
    
                // Information 4: Add EXP equal to a total of info 1, 2 and 3
                case 3:
                    exp2 += INFO_ONE_EXP + INFO_TWO_EXP + INFO_THREE_EXP; limitEXP(exp2);
                    break;
    
            }
    
            /* Changing Sherlock's EXP */
            
            int D = e1 * 3 + exp1 * 7; // Sherlock's decision
    
            if (D % 2 == 0) { // If D is an even number
                exp1 = ceil(exp1 + D / 200.0 - 1e-10); limitEXP(exp1);
            }
            else { // If D is an odd number 
                exp1 = ceil(exp1 - D / 100.0 - 1e-10); limitEXP(exp1);
            }
        }
        
        // Case 2
        else if (4 <= e1 && e1 <= 99) { // E1's range [4, 99]
    
            /* Changing Watson's EXP */
            
            // Information 1: Add (E1/4 + 19)
            if (4 <= e1 && e1 <= 19) { // E1's range [4, 19]
                exp2 += ceil(e1 / 4.0 + 19 - 1e-10); limitEXP(exp2);
            }
            
            // Information 2: Add (E1/9 + 21)
            else if (20 <= e1 && e1 <= 49) { // E1's range [20, 49]
                exp2 += ceil(e1 / 9.0 + 21 - 1e-10); limitEXP(exp2);    
            }
            
            // Information 3: Add (E1/16 + 17)
            else if (50 <= e1 && e1 <= 65) { // E1's range [50, 65]
                exp2 += ceil(e1 / 16.0 + 17 - 1e-10); limitEXP(exp2);
            }
            
            // Information 4: Update EXP like info 1 then if EXP > 200 then update EXP like info 2
            else if (66 <= e1 && e1 <= 79) { // E1's range [66, 79]
                exp2 += ceil(e1 / 4.0 + 19 - 1e-10); limitEXP(exp2); // Info 1
                
                if (exp2 > 200) {
                    exp2 += ceil(e1 / 9.0 + 21 - 1e-10); limitEXP(exp2); // Info 2
                }
            }
            
            // Information 5: Update like info 1 and 2 and if EXP > 400 then update EXP like info 3
            // Note: If info 1, 2, and 3 are all called, add 15% to EXP
            else {
                exp2 += ceil(e1 / 4.0 + 19 - 1e-10); limitEXP(exp2); // Info 1
                
                exp2 += ceil(e1 / 9.0 + 21 - 1e-10); limitEXP(exp2); // Info 2
                    
                if (exp2 > 400) {
                    exp2 += ceil(e1 / 16.0 + 17 - 1e-10); limitEXP(exp2); // Info 3
                    exp2 = ceil(exp2 * 115 / 100.0 - 1e-10); limitEXP(exp2); // Updated with all 3 info
                }
                
            }
            
            /* Changing Sherlock's EXP */
            
            // Sherlock EXP is reduced by E1 for his mistake
            exp1 -= e1; limitEXP(exp1);
            
        }
    }
    
    return exp1 + exp2; // Returning
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
    
    // Return -99 if E3 is out of range
    if (!eventIsInRange(E3)) {
        return -99;
    }
    
    // Declaring probabilities
    double P1, P2, P3;
    
    
    /* Road 1 */
    P1 = (EXP1 >= nearestPerfectSquare(EXP1))? 100 : ((EXP1 / nearestPerfectSquare(EXP1)) + 80) / 123.0 * 100;

    /* Road 2 */
    double halfBudget = M1 / 2; 
    int spentMoney = 0;
    
    const int TAXI_PRICE = 200,
              CARRIAGE_PRICE = 120;
    
    int eventIndex = 1;
    while(1 <= eventIndex && eventIndex <= 3) {
        
        switch(eventIndex) {
            
            // Event 1
            case 1:
                if (HP1 < 200) {
                    HP1 = ceil(HP1 * 1.3 - 1e-10); limitHP(HP1);
                    M1 -= 150; limitMoney(M1);
                    spentMoney += 150;
                }
                
                else {
                    HP1 = ceil(HP1 * 1.1 - 1e-10); limitHP(HP1);
                    M1 -= 70; limitMoney(M1);
                    spentMoney += 70;
                }
                break;
        
            // Event 2 
            case 2:
                if (EXP1 < 400) {
                    M1 -= TAXI_PRICE; limitMoney(M1);
                    spentMoney += TAXI_PRICE;
                } 
                
                else {
                    M1 -= CARRIAGE_PRICE; limitMoney(M1);
                    spentMoney += CARRIAGE_PRICE;
                }
                
                EXP1 = ceil(EXP1 * (1 + 0.13) - 1e-10); limitEXP(EXP1);
                break;
        
            // Event 3
            case 3:
                if (EXP1 < 300) {
                    M1 -= 100; limitMoney(M1);
                    spentMoney += 100; 
                }
                
                else {
                    M1 -= 120; limitMoney(M1);
                    spentMoney += 120;
                }
                
                EXP1 = ceil(EXP1 * 0.9 - 1e-10); limitEXP(EXP1);
                break;
        }
        
        if (E3 % 2 != 0) {
            if (spentMoney > halfBudget) {
                break;
            } 
            else if (eventIndex == 3) {
            eventIndex = 1;
            }
            else eventIndex++;
        }

        if (E3 % 2 == 0) {
            if (spentMoney > M1) {
                break;
            }
            else eventIndex++;
        }
    }
    
    HP1 = ceil(HP1 * 0.83 - 1e-10); limitHP(HP1);
    EXP1 = ceil(EXP1 * (1 + 0.17) - 1e-10); limitEXP(EXP1);
    
    P2 = (EXP1 >= nearestPerfectSquare(EXP1))? 100 : ((EXP1 / nearestPerfectSquare(EXP1)) + 80) / 123.0 * 100;


    /* Road 3 */
    const int probabilityValues[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i; // index value 
    
    if (0 <= E3 && E3 <= 9) { // E3 is a single-digit number
        i = E3;
    }
    else if (10 <= E3 && E3 <= 99) { // E3 is a double-digit number
        i = sumOfDigits(E3) % 10;
    }

    P3 = probabilityValues[i];

    
    /* After going through all 3 routes */
    if (P1 == 100 && P2 == 100 && P3 == 100) {
        EXP1 = ceil(EXP1 * 0.75 - 1e-10); limitEXP(EXP1);
        traceLuggage(HP1, EXP1, M1, E3);
    }
    
    else {
        double averageProbability = (P1 + P2 + P3) / 3.0;
        
        if (averageProbability < 50) {
            HP1 = ceil(HP1 * 0.85 - 1e-10); limitHP(HP1);
            EXP1 = ceil(EXP1 * (1 + 0.15) - 1e-10); limitEXP(EXP1);
        }
        else {
            HP1 = ceil(HP1 * 0.9 - 1e-10); limitHP(HP1);
            EXP1 = ceil(EXP1 * (1 + 0.2) - 1e-10); limitEXP(EXP1);
        }
    }
    
    return HP1 + EXP1 + M1; // Returning
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (!eventIsInRange(E3)) {
        return -99;
    }
    
    int meetingPointI = 0, meetingPointJ = 0;
    
    int taxiMap[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxiMap[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            
            if (taxiMap[i][j] > (E3 * 2)) meetingPointI++;
            if (taxiMap[i][j] < (E3 * -1)) meetingPointJ++;
        }
    }
    
    while ((10 <= meetingPointI && meetingPointI <= 99) || (10 <= meetingPointJ && meetingPointJ <= 99)) {
        meetingPointI = sumOfDigits(meetingPointI);
        meetingPointJ = sumOfDigits(meetingPointJ);
    } 
    
    auto findLargestValueOnDiagonalThroughPoint = [taxiMap](int i, int j,string dir) -> int {
        int max;
        
        if (dir == "left") {
            while (i != 0 && j != 0) {
                i--;
                j--;
            }
            
            max = taxiMap[i][j];
            
            while (i != 10 && j != 10) {
                if (taxiMap[i][j] > max) {
                    max = taxiMap[i][j];
                }
                
                i++; j++;
            }
        }
        
        else {
            while (i != 9 && j != 0) {
                i++;
                j--;
            }
            
            max = taxiMap[i][j];
            
            while (i != -1 && j != 10) {
                if (taxiMap[i][j] > max) {
                    max = taxiMap[i][j];
                }
                
                i--; j++;
            }
        }
        
        return max;
    };

    int sherlockMap[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (findLargestValueOnDiagonalThroughPoint(i, j, "right") > findLargestValueOnDiagonalThroughPoint(i, j, "left")) {
                sherlockMap[i][j] = findLargestValueOnDiagonalThroughPoint(i, j, "right");
            }
            else {
                sherlockMap[i][j] = findLargestValueOnDiagonalThroughPoint(i, j, "left");
            }
        }
    }
    
    if (abs(sherlockMap[meetingPointI][meetingPointJ]) >= abs(taxiMap[meetingPointI][meetingPointJ])) {
            EXP1 = ceil(EXP1 * (1 + 0.12) - 1e-10); limitEXP(EXP1);
            HP1 = ceil(HP1 * (1 + 0.1) - 1e-10); limitHP(HP1);
            
            EXP2 = ceil(EXP2 * (1 + 0.12) - 1e-10); limitEXP(EXP2);
            HP2 = ceil(HP2 * (1 + 0.1) - 1e-10); limitHP(HP2);
            
            return sherlockMap[meetingPointI][meetingPointJ];
        }
        else {
            EXP1 = ceil(EXP1 * 0.88 - 1e-10);
            HP1 = ceil(HP1 * 0.9 - 1e-10);
            
            EXP2 = ceil(EXP2 * 0.88 - 1e-10);
            HP2 = ceil(HP2 * 0.9 - 1e-10);
            
            return taxiMap[meetingPointI][meetingPointJ];
        }
    
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
        
    string passwordString = s,
           emailString = email;
    
    string se;
    size_t atPos = emailString.find('@');
    if (atPos != std::string::npos) {
        se = emailString.substr(0, atPos);
    }
    
    if (passwordString.length() < 8) {
        return -1;
    }
    
    if (passwordString.length() > 20) {
        return -2;
    }
    
    if (passwordString.find(se) != std::string::npos) {
        return (-300 - passwordString.find(se));
    }
    
    for (size_t i = 1; i < passwordString.length(); i++) {
        if (passwordString[i] == passwordString[i - 1] && passwordString[i] == passwordString[i + 1]) {
            return -(400 + i);
        }
    }
    
    bool hasSpecialChar = false;
    for (char c : passwordString) {
        if (!isalnum(c)) {
            hasSpecialChar = true;
        break;
        }
    }
    if (!hasSpecialChar) {
        return -5;
    }
    
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string pwdCorrect = "";
    int pwdCorrectNo = 0;
    
    for (int i = 0; i < num_pwds; i++) {
        string pwdChecking = arr_pwds[i];
        int pwdCheckingNo = 1;
        
        for (int j = i + 1; j < num_pwds; j++) {
            if (arr_pwds[j] == pwdChecking) {
                pwdCheckingNo++;
            }
        }
        
        if (pwdCheckingNo > pwdCorrectNo) {
            pwdCorrect = pwdChecking;
            pwdCorrectNo = pwdCheckingNo;
        }
        
        else if (pwdCheckingNo == pwdCorrectNo) {
            if (pwdChecking.length() > pwdCorrect.length()) {
                pwdCorrect = pwdChecking;
                pwdCorrectNo = pwdCheckingNo;
            }
            else if (pwdChecking.length() > pwdCorrect.length()) {
                for (int i = 0; i < num_pwds; i++) {
                    if (arr_pwds[i] == pwdChecking) {
                        pwdCorrect = pwdChecking;
                        pwdCorrectNo = pwdCheckingNo;
                        break;
                    }
                    else if (arr_pwds[i] == pwdCorrect) break;
                }
            }
        }
    }
    
    int position;
    for (int i = 0; i < num_pwds; i++) {
        if (arr_pwds[i] == pwdCorrect) {
            position = i;
            break;
        }
    }
    return position;
}

// Additional functions
int limitHP(int & hp) {
    if (hp < 0) hp = 0;
    
    if (hp > 666) hp = 666;
    
    return hp;
}

int limitEXP(int & exp) {
    if (exp < 0) exp = 0;
    
    if (exp > 600) exp = 600;
    
    return exp;
}

int limitMoney(int & money) {
    if (money < 0) money = 0;
    
    if (money > 3000) money = 3000;
    
    return money;
}

bool eventIsInRange(int e) {
    return (0 <= e && e <= 99);
}

int nearestPerfectSquare(int num) {
    if (num <= 0) {
        return 0;
    }
    else {
        int lowerSquare = floor(sqrt(num));
        int higherSquare = ceil(sqrt(num));
        
        int lowerSquareValue = pow(lowerSquare, 2);
        int higherSquareValue = pow(higherSquare, 2);
        
        if (abs(num - lowerSquareValue) < abs(num - higherSquareValue)) {
            return lowerSquareValue;
        } 
        else {
            return higherSquareValue;
        }
    }
}

int sumOfDigits(int number) {
    int tenthDigit = number / 10;

    int unitDigit = number % 10;

    return tenthDigit + unitDigit;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////