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
int raoup(double value) {return (value + 0.99999);}

int firstMeet(int & exp1, int & exp2, int e1) {
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
            exp2 += 29 + 45 + 75;
            break;
        case 4 ... 19:
            exp2 += raoup(double(e1) / 4.0) + 19;
            break;
        case 20 ... 49:
            exp2 += raoup(double(e1) / 9.0) + 21;
            break;
        case 50 ... 65:
            exp2 += raoup(double(e1) / 16.0) + 17;
            break;
        case 66 ... 79:
            exp2 += raoup(double(e1) / 4.0) + 19;
            if (exp2 > 200) {
                exp2 += raoup(double(e1) / 9.0) + 21;
            }
            break;
        case 80 ... 99:
            exp2 += raoup(double(e1) / 4.0) + 19;
            exp2 += raoup(double(e1) / 9.0) + 21;
            if (exp2 > 400) {
                exp2 += raoup(double(e1) / 16.0) + 17;
                }
            break;
        default:
            return -99;
    }
    if (e1 >= 0 && e1 <= 3){
    int D =  e1 * 3 + exp1 * 7;
    exp1 += (D % 2 == 0) ? raoup(double(D) / 200.0) : -floor(double(D) / 100.0);
    }
    
    exp1 = max(0, min(exp1, 600));
    exp2 = max(0, min(exp2, 600));

    if (e1 >= 4 && e1 <= 99) {
        exp1 -= e1;
        exp1 = max(0, exp1);
    }

    if (e1 >= 80 && e1 <= 99 && exp2 > 400) {
        exp2 = min(600, static_cast<int>(raoup(double(exp2) * 1.15)));
    }

    return exp1 + exp2;
}

// Task 2
int HP(int HP) {return min(max(HP, 0), 666);}
int EXP(int EXP) {return min(max(EXP, 0), 600);}
int M(int M) {return min(max(M, 0), 3000);}
bool eventValid(int event) {return (event >= 0 && event <= 99);}

// Function to calculate the nearest perfect square
int nearestPerfectSquare(int EXP1) {
    // Find the square root of EXP1
    int sqrt_EXP1 = sqrt(EXP1);
   
    // Calculate the lower and upper perfect squares
    int lower = sqrt_EXP1 * sqrt_EXP1;
    int upper = (sqrt_EXP1 + 1) * (sqrt_EXP1 + 1);
   
    // Determine the nearest perfect square
    if (abs(EXP1 - lower) < abs(upper - EXP1)) {return lower;} else {return upper;}
}

// Function to calculate the probability for Road 01
double calculateProbabilityRoad01(int EXP1) {
    int S = nearestPerfectSquare(EXP1);
    if (EXP1 >= S) {return 1.0; // Probability is 100%
    } 
    else {
        return (static_cast<double>(EXP1) / S + 80) / 123;
    }
}


// Function to calculate the probability for Road 03
double calculateProbabilityRoad03(int E2) {
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 < 10) {
        i = E2;
    } else {
        i = (E2 / 10 + E2 % 10) % 10;
    }
    return P[i] / 100.0;
}


// Function to trace luggage
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    //if (isValidEvent=0) {return -99}
    if (!eventValid(E2)) { return -99;}
    HP1 = HP(HP1);
    EXP1 = EXP(EXP1);
    M1 = M(M1);
    // Road 01
    double P1 = calculateProbabilityRoad01(EXP1);


    // Road 02
    double P2;
    if (E2 % 2 == 0) {
        // Even event code
        // Implement one round of events
        // place 1
        if (HP1 < 200) {
                M1 -= 150;
                M1 = M(M1);
                HP1 = raoup(double (HP1)*1.3);
                HP1 = HP(HP1);
            } else {
                M1 -= 70;
                M1 = M(M1);
                HP1 = raoup(double (HP1)*1.1);
                HP1 = HP(HP1);
            }
           
        //place 2
            const int place2_M1= M1;
            if (EXP1 < 400 && M1 !=0) {
                M1 -= 200;
                M1 = M(M1);
                EXP1 = raoup(double (EXP1)*1.13);
                EXP1 = EXP(EXP1);
               } else if (EXP1 >= 400 && place2_M1 !=0) {
                M1 -= 120;
                M1 = M(M1);
                EXP1 = raoup(double (EXP1)*1.13);
                EXP1 = EXP(EXP1);
               }
        //place 3
            const int place3_M1= M1;
            if (EXP1 < 300&& M1 !=0) {
                M1 -= 100;
                M1 = M(M1);
                EXP1 = raoup(double (EXP1)* 0.9); // 10% decrease
               } else if(EXP1 >= 300 && place3_M1 !=0) {
                M1 -= 120;
                M1 = M(M1);
                EXP1 = raoup(double (EXP1)* 0.9); // 10% decrease
               }

    } else {
        // Odd event code
        // Implement repeated events until paid money exceeds 50% of initial M1
        int paidMoney = 0;
        const double aM1 =  M1 / 2.0;
        while (paidMoney <= aM1) {
            // Implement events and update HP1, EXP1, M1 accordingly
            //place 1
            if (HP1 < 200) {
                M1 -= 150;
                M1 = M(M1);
                paidMoney += 150;
                HP1 = raoup(double (HP1)*1.3);
                HP1 = HP(HP1);
            } else {
                M1 -= 70;
                M1 = M(M1);
                paidMoney += 70;
                HP1 = raoup(double (HP1)*1.1);
                HP1 = HP(HP1);
            }
            // Check if paidMoney exceeds half of M1
            if (paidMoney > aM1) {
                break; // Exit the loop
            }
           
            //place 2
            if (EXP1 < 400) {
               
                M1 -= 200;
                M1 = M(M1);
                paidMoney += 200;
               } else {
                M1 -= 120;
                M1 = M(M1);
                paidMoney += 120;
               }
           
            EXP1 = raoup(double (EXP1)*1.13);
            EXP1 = EXP(EXP1);
           
            if (paidMoney > aM1) {
                break; // Exit the loop
            }
           
            //place 3
            if (EXP1 < 300) {
                M1 -= 100;
                M1 = M(M1);
                paidMoney += 100;
               } else {
                M1 -= 120;
                M1 = M(M1);
                paidMoney += 120;
               }
            EXP1 = raoup(double (EXP1)* 0.9); // 10% decrease
        }
           }
            HP1 = raoup(double (HP1) * 0.83); // 17% decrease
            EXP1 = raoup(double(EXP1) * 1.17); // 17% increase
            // Adjust HP1 and EXP1 for walking to the end of the road
            HP1 = HP(HP1);
            EXP1 = EXP(EXP1);
            // Calculate P2 using Road 01 formula
            P2 = calculateProbabilityRoad01(EXP1);
    // Road 03
    double P3 = calculateProbabilityRoad03(E2);


    // Check if all probabilities are 100%
    if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0) {
        // Recalculate if all are 100%
        EXP1 = raoup(0.75 * double (EXP1));
        EXP1 = EXP(EXP1);
    } else {
        // Calculate average probability
        double P = (P1 + P2 + P3) / 3;
        if (P < 0.5) {
            // Hard time finding the suitcase
            HP1 = raoup(double(HP1) * 0.85); // 15% decrease
            EXP1 = raoup(double(EXP1) * 1.15); // 15% increase
            HP1 = HP(HP1);
            EXP1 = EXP(EXP1);
        } else {
            // Quickly find the suitcase
            HP1 = raoup(double(HP1) * 0.9); // 10% decrease
            EXP1 = raoup(double(EXP1) * 1.2); // 20% increase
            HP1 = HP(HP1);
            EXP1 = EXP(EXP1);
     
   }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    //TODO: implement task
    //if (isValidEvent=0) {return -99}
    if (!eventValid(E3)) { return -99;}

    const int SIZE = 10;
    int taxiMatrix[SIZE][SIZE] = {0};

    // Assign taxi matrix before any other caculation
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            taxiMatrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    // Calculate meeting location
    int positiveCount = 0, negativeCount = 0;
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (taxiMatrix[row][col] > E3 * 2) {
                positiveCount++;
            } else if (taxiMatrix[row][col] < -E3) {
                negativeCount++;
            }
        }
    }

    while (positiveCount > 9) {
        int sum = 0;
        while (positiveCount > 0) {
            sum += positiveCount % 10;
            positiveCount /= 10;
        }
        positiveCount = sum;
    }

    while (negativeCount > 9) {
        int sum = 0;
        while (negativeCount > 0) {
            sum += negativeCount % 10;
            negativeCount /= 10;
        }
        negativeCount = sum;
    }
    
    int const CountI = positiveCount ;
    int const CountJ = negativeCount ;
 
    // Meeting points, assign value for taxiGrade and sherlockWatsonGrade
    int taxiGrade = taxiMatrix[CountI][CountJ];
    
    int sherlockWatsonGrade = taxiMatrix[CountI][CountJ];

    for (int i = CountI, j = CountJ; i < SIZE && j < SIZE; ++i, ++j){sherlockWatsonGrade= max(sherlockWatsonGrade, taxiMatrix[i][j]);}
  
    for (int i = CountI, j = CountJ; i >=0 && j < SIZE; --i, ++j){sherlockWatsonGrade= max(sherlockWatsonGrade, taxiMatrix[i][j]);}
    
    for (int i = CountI, j = CountJ; i < SIZE && j >=0; ++i, --j){sherlockWatsonGrade= max(sherlockWatsonGrade, taxiMatrix[i][j]);}

    for (int i = CountI, j = CountJ; i >=0 && j >=0; --i, --j){sherlockWatsonGrade= max(sherlockWatsonGrade, taxiMatrix[i][j]);}

    // Update EXP and HP
    if (abs(taxiGrade) <= abs(sherlockWatsonGrade)) {
        EXP1 = raoup(EXP1 * 1.12);
        HP1 = raoup(HP1 * 1.1);
        EXP2 = raoup(EXP2 * 1.12);
        HP2 = raoup(HP2 * 1.1);
        HP1 = HP (HP1);
        HP2 = HP (HP2);
        EXP1 = EXP(EXP1);
        EXP2 = EXP(EXP2);
    } else {
        EXP1 = raoup(float(EXP1) * 0.88);
        HP1 = raoup(float(HP1) * 0.9);
        EXP2 = raoup(float(EXP2) * 0.88);
        HP2 = raoup(float(HP2) * 0.9);
        HP1 = HP (HP1);
        HP2 = HP (HP2);
        EXP1 = EXP(EXP1);
        EXP2 = EXP(EXP2);
    }
    if (abs(taxiGrade) > abs(sherlockWatsonGrade)) return taxiGrade;
    else return sherlockWatsonGrade;

}

// Task 4
int checkPassword(const char * s, const char * email)
{
    string password(s);
    string emailAddress(email);
    string se = emailAddress.substr(0, emailAddress.find('@'));

    // Check if the length of the password is within limits
    if (password.length() < 8)
        return -1;
    if (password.length() > 20)
        return -2;

    // Check if the password contains the email substring
    size_t found = password.find(se);
    if (found != string::npos)
        return -(300 + found);

    // Check if the password contains more than 2 consecutive identical characters
    for (int i = 0; i < password.length() - 2; ++i) {
        if (password[i] == password[i + 1] && password[i] == password[i + 2])
            return -(400 + i);
    }

    // Check if the password contains at least one special character
    bool hasSpecialChar = false;
    for (char c : password) {
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!')
            hasSpecialChar = true;
    }
    if (!hasSpecialChar)
        return -5;

    // Check each character for validity
    for (int i = 0; i < password.length(); ++i) {
        char c = password[i];
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '@' || c == '#' || c == '%' || c == '$' || c == '!'))
            return i;
    }

    return -10; // Password is valid
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    //TODO: implement task
     int maxFrequency = 0;
    const char* maxFrequencyPasswords[30]; // Maximum possible distinct passwords
    int maxLength = 0;
    const char* correctPassword = nullptr;

    // Count frequency of each password
    int passwordFrequency[30] = {0}; // Initialize to zero

    for (int i = 0; i < num_pwds; ++i) {
        const char* password = arr_pwds[i];
        int frequency = 0;

        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[j], password) == 0) {
                frequency++;
            }
        }

        passwordFrequency[i] = frequency;
        maxFrequency = max(maxFrequency, frequency);
    }

    // Collect passwords with maximum frequency
    int count = 0;
    for (int i = 0; i < num_pwds; ++i) {
        if (passwordFrequency[i] == maxFrequency) {
            maxFrequencyPasswords[count++] = arr_pwds[i];
        }
    }

    // Find the longest password with maximum frequency
    for (int i = 0; i < count; ++i) {
        const char* password = maxFrequencyPasswords[i];
        if (strlen(password) > maxLength) {
            maxLength = strlen(password);
            correctPassword = password;
        }
    }

    // Find the first position of the correct password
    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(arr_pwds[i], correctPassword) == 0) {
            return i ; 
        }
    }

    return -1; // Error: Correct password not found

}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////