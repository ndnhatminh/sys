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


/* ------------             Global const         ---------- */
const int MAX_HP = 666;
const int MAX_EXP = 600;
const int MAX_M = 3000;
const int MAX_E = 99;
const int MIN = 0;

const char specialCharacters[] = {'@', '#', '%', '$', '!'};
const int minPasswordLength = 8;
const int maxPasswordLength = 20;

const int MatrixSize = 10;

/* ------------             Global functions         ---------- */


void checkExp(int &exp){
    if (exp < MIN){
        exp = 0;
    }
    else if (exp > MAX_EXP)
    {
        exp = MAX_EXP;
    }
}

void checkHP(int &HP){
    if (HP < MIN){
        HP = 0;
    }
    else if (HP > MAX_HP)
    {
        HP = MAX_HP;
    }
}

void checkM(int &M){
    if (M < MIN){
        M = 0;
    }
    else if (M > MAX_M)
    {
        M = MAX_M;
    }
}

void modifyExp(int &exp, double additional){
    // cout << additional << "\n" << exp + additional;
    exp = ceil(exp + additional);
    // cout << "\n" << exp << "\n";
    checkExp(exp);
}

void modifyHP(int &HP, double additional){
    // cout << "HP:" << additional << "\n" << HP + additional;
    HP = ceil(HP + additional);
    // cout << "\n" <<"HP:" << HP << "\n";
    checkHP(HP);
}

void modifyM(int &M, double additional){
    // cout << additional << "\n" << M + additional;
    M = ceil(M + additional);
    // cout << "\n" << M << "\n";
    checkM(M);
}

/* -------------        Start of task 1            -----------------*/
/* -------------   Supplement functions of task 1 -------------*/
double case0(){
    //0 Watson’s hairstyle and manner of speech are like those of the military Add 29 EXP
    return 29;
}

double case1(){
    //1 His face is tanned but not tanned under the wrist, proving that Watson has returned from abroad Add 45 EXP
    return 45;
}

double case2(){
    // 2 Watson limped, but when they met, he chose to stand without asking for a chair, so he had psychological problems after being injured. This could be an injury caused by action on the battlefield Add 75 EXP
    return 75;
}

double case3(){
    //3 case above, no bonus
    return case0() + case1() + case2();
}

double case4(int &e1){
    //4 19
    /*Watson has an expensive phone but he is looking for a roommate to share the rent, 
    the phone must have been given to Watson by someone else Add (E1/4+19) EXP */
    return ceil(static_cast<double>(e1)/ 4 + 19);
}

double case5(int &e1){
    //20 49 
    /*Watson has an expensive phone but he is looking for a roommate to share the rent, 
    the phone must have been given to Watson by someone else Add Add (E1/9+21) EXP. */
    return ceil(static_cast<double>(e1)/9 + 21);
}

double case6(int &e1){
    // 50 65 
    /*Watson has an expensive phone but he is looking for a roommate to share the rent, 
    the phone must have been given to Watson by someone else Add (E1/9+21) EXP. */
    return ceil(static_cast<double>(e1)/16 + 17);
    /*
    / operator of 2 int ALWAYS return an INT
    in order to return double/float, we must cast one/both operand
    */
}

double case7(int &e1, int &exp2){
    //66 79 
    /*Watson has an expensive phone but he is looking for a roommate to share the rent, 
    the phone must have been given to Watson by someone else Add Add (E1/9+21) EXP. */
    if (exp2 > 200){
        int c5 = case5(e1);
        return c5;
    }
    else {
        return 0;
    }
}

double case8(int &e1, int &exp2, bool& flag){
    //80 99
    // flag = false;
    if (exp2 > 400){
        flag = true;
        return case6(e1);
    }
    else {
        return 0;
    }
}

void decisionMaking(int &E1, int &exp1){
     //decision making D = 3*exp1 + 7*exp2
    //if D even, exp1 += D/200
    //if D odd, exp1 -= D/100
    int D = 0;
    D += 3 * E1 + 7 * exp1;
    if (D % 2 == 0){
        // exp1 += static_cast<double>(D)/200;
        modifyExp(exp1, D/200);
    }
    else {
        // exp1 -= static_cast<double>(D)/100;
        modifyExp(exp1, -D/100);
    }
    // cout << D << "\n";
    // return D;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99){
        return -99;
    }

    if (e1 >= 0 && e1 <= 3){
        if (e1 == 0){
            modifyExp(exp2, case0());
            checkExp(exp2);
        }
        else if (e1 == 1)
        {
            modifyExp(exp2, case1());
            checkExp(exp2);
        }
        else if (e1 == 2)
        {
            modifyExp(exp2, case2());
            checkExp(exp2);
        }
        else if (e1 == 3)
        {
            modifyExp(exp2, case3());
            checkExp(exp2);
        }
        // cout << exp1 <<" " << exp2 << "\n";
        decisionMaking(e1, exp1); 
        // cout << exp1 <<" " << exp2 << "\n";
        checkExp(exp1);
        checkExp(exp2);
        // cout << exp1 <<" " << exp2 << "\n";
    }
    else if (e1 >= 4 && e1 <= 99){
        if (e1 >= 4 && e1 <= 19){
            modifyExp(exp2, case4(e1));
        }
        else if (e1 >= 20 && e1 <= 49){
            modifyExp(exp2, case5(e1));
        }
        else if (e1 >= 50 && e1 <= 65){
            modifyExp(exp2, case6(e1));
        }
        else if (e1 >= 66 && e1 <= 79){
            modifyExp(exp2, case4(e1));
            modifyExp(exp2, case7(e1, exp2));
        }
        else if (e1 >= 80 && e1 <= 99){
            bool flag = false;
            modifyExp(exp2, case4(e1));
            modifyExp(exp2, case5(e1));
            modifyExp(exp2, case8(e1, exp2, flag));
            if (flag){
                modifyExp(exp2, static_cast<double>(exp2)*0.15);
            }
        }
        modifyExp(exp1, -e1); //subtract sherlock end of 2nd case
    }
    // return exp1 + exp2; //if greater than 600, reduce to 600, lower than 0, 0
    // int E3 = exp1 + exp2; //to avoid initial value of reference to non-const must be an lvalue
    // return checkExp(E3);
    return exp1 + exp2;
    }

/* -------------        End of task 1            -----------------*/

/* -------------        Start of task 2            -----------------*/
/* -------------   Supplement functions of task 2 -------------*/
int findClosestSquareRoot(int &exp){
    int sr = int(std::sqrt(exp));
    int lowerSQ = sr * sr;
    int higherSQ  = (sr +1) * (sr +1);
    if (std::abs(lowerSQ - exp) > (higherSQ - exp)){
        return higherSQ;
    }
    else return lowerSQ;
}
void takeRoad1(int & HP1, int & EXP1, int & M1, int E2, double P[]){
    int SR = findClosestSquareRoot(EXP1);
    if (EXP1 >= SR){
        P[0] = 1.0;
    }
    else {
        P[0] = static_cast<double>((static_cast<double>(EXP1) / SR + 80)) / 123;
    }
}

void road2P1(int& HP1, int& EXP1, int& M1){
    //Road 2.1
    if (HP1 < 200){
        // HP1 = HP1 * 1.3; 
        modifyHP(HP1, static_cast<double>(HP1) * 0.3);
        modifyM(M1, -150);
        // M1 = M1 - 150;
        // checkHP(HP1);
        // checkM(M1);
    }
    else{
        // modifyHP(HP1, HP1 * 0.1);
        modifyHP(HP1, static_cast<double>(HP1) * 0.1);
        modifyM(M1, -70);
        // HP1 = HP1 * 1.1;
        // M1 = M1 - 70;
        // checkHP(HP1);
        // checkM(M1);
    }
}

void road2P2(int& HP1, int& EXP1, int& M1){
    //ROAD 2.2
    if (EXP1 < 400){ 
        //taxi, 200M, increase 13%
        // M1 -= 200;
        modifyM(M1, -200);
    }
    else {
        //
        // M1 -= 120;
        modifyM(M1, -120);
    }
    modifyExp(EXP1, static_cast<double>(EXP1) * 0.13);
}

void road2P3(int& HP1, int& EXP1, int& M1){
    //Road 2.3
    if (EXP1 < 300){ 
        //give money, 200M, increase 13%
        // M1 -= 100;
        modifyM(M1, -100);
    }
    else {
        //give more
        // M1 -= 120;
        modifyM(M1, -120);
    }
    modifyExp(EXP1, static_cast<double>(EXP1) * -0.1);
}

void checkFlag(int& M1, bool& flag){
    if (M1 <= 0){
        flag = false;
    }
    flag = true;
}
void takeRoad2(int & HP1, int & EXP1, int & M1, int E2, double P[]){
    bool breakFlag = false;
    // cout << "M1: " << M1 << "\n";
    if (E2 % 2 == 1) {
        //odd case, 123 repeat until 50% money, decrease 17%HP, increase 17%exp
        int initialM = M1;
        // while (M1 < int(static_cast<double>(initialM) * 0.5) && !breakFlag){
        do {
            road2P1(HP1, EXP1, M1);
            checkFlag(M1, breakFlag);
            road2P2(HP1, EXP1, M1);
            checkFlag(M1, breakFlag);
            road2P3(HP1, EXP1, M1);
            checkFlag(M1, breakFlag);
            if (!breakFlag) break;
        }  
        while (breakFlag && (M1 > int(static_cast<double>(initialM) * 0.5)));
    }
    else {
        //even, 123, if M <= 0, break, update -17%hp, +17% exp
        //P2 is same as P1 after one round
        road2P1(HP1, EXP1, M1);
        checkFlag(M1, breakFlag);
        road2P2(HP1, EXP1, M1);
        checkFlag(M1, breakFlag);
        road2P3(HP1, EXP1, M1);
        checkFlag(M1, breakFlag);
        if (!breakFlag){
            return;
        }
    }
    modifyHP(HP1, static_cast<double>(HP1) * -0.17);
    modifyExp(EXP1, static_cast<double>(EXP1) * 0.17);

    double SR = findClosestSquareRoot(EXP1);
    P[1] = static_cast<double>(((static_cast<double>(EXP1) / SR) + 80)) / 123;
}

void takeRoad3(int & HP1, int & EXP1, int & M1, int E2, double P[]){
    int Px[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int divident = E2 % 100;
    int index = -1;
    if (divident < 10){ //because E already less than 100, if mod 100 less than 10 -> 1 digit, else 2 digit
        index = divident;
    }
    else {
        //2 digit, take the unit digit -> mod 10 
        int unitP = divident % 10;
        int tenP = int(divident / 10);
        int sum = unitP + tenP; // 0 to 18
        index = sum % 10; //take unit regardless of 1x or x
    }
    P[2] = Px[index] / 100;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;
    double P[3] = {0,0,0};
    //road 1 
    takeRoad1(HP1, EXP1, M1, E2, P);
    //road 2
    takeRoad2(HP1, EXP1, M1, E2, P);
    //road 3
    takeRoad3(HP1, EXP1, M1, E2, P);

    // cout << P[0] << " " << P[1] << " " << P[2];
    if (P[0] == P[1] && P[1] == P[2] && P[2] == 1.0){
        //mistake, exp1 - 25%
        modifyExp(EXP1, EXP1 * -0.25);
    }
    else { //not all is 100%
        //take average P
        if (((P[0] + P[1] + P[2]) / 3) < 0.5){
            modifyExp(EXP1, EXP1 * 0.15);
            modifyHP(HP1, HP1 * -0.15);
        }
        else { 
            //greater than 50%,quickly find suitcase
            modifyHP(HP1, HP1 * -0.1);
            modifyExp(EXP1, EXP1 * 0.2);
        }
    }
    return HP1 + EXP1 + M1;
}

int singleDigitSum(int number) {
    while (number > 9) {
       int sum = 0;
       while (number > 0) {
           sum += number % 10;
           number /= 10;
       }
       number = sum;
   }
   return number;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    int positiveCount = 0, negativeCount = 0;
    int taxiMap[MatrixSize][MatrixSize] = {}; // Taxi's skill scores matrix
    int sherlockWatsonMap[MatrixSize][MatrixSize] = {}; // Sherlock and Watson's scores matrix

    // memset(map, 0, sizeof(map)); //dont need to set

   // Initialize and populate the taxi's score matrix, also count point
   for (int i = 0; i < 10; i++) {
       for (int j = 0; j < 10; j++) {
           taxiMap[i][j] = ((E3 * j) + (i * 2)) * (i - j);
           if (taxiMap[i][j] > E3 * 2) ++positiveCount;
           if (taxiMap[i][j] < -E3) ++negativeCount;
       }
   }
   /*
   for (int i = 0; i < 10; i++) {
       for (int j = 0; j < 10; j++) {
           if (taxiMap[i][j] > E3 * 2) ++positiveCount;
           if (taxiMap[i][j] < -E3) ++negativeCount;
       }
   }
*/
   // Calculate Sherlock and Watson's scores
   for (int i = 0; i < 10; i++) {
       for (int j = 0; j < 10; j++) {
           int leftDiagonal = 0, rightDiagonal = 0;
           // Calculate left diagonal
           for (int k = i, l = j; k >= 0 && l >= 0; k--, l--) {
               leftDiagonal = max(leftDiagonal, taxiMap[k][l]);
           }
           for (int k = i, l = j; k < 10 && l < 10; k++, l++) {
               leftDiagonal = max(leftDiagonal, taxiMap[k][l]);
           }
           // Calculate right diagonal
           for (int k = i, l = j; k >= 0 && l < 10; k--, l++) {
               rightDiagonal = max(rightDiagonal, taxiMap[k][l]);
           }
           for (int k = i, l = j; k < 10 && l >= 0; k++, l--) {
               rightDiagonal = max(rightDiagonal, taxiMap[k][l]);
           }
           sherlockWatsonMap[i][j] = max(abs(leftDiagonal), abs(rightDiagonal));
       }
   }
    //intersect
   int p = singleDigitSum(positiveCount);
   int n = singleDigitSum(negativeCount);

   // Compare scores at meeting point and update HP/EXP
   int taxiScore = abs(taxiMap[p][n]);
   int swScore = sherlockWatsonMap[p][n];
   if (taxiScore > swScore) {
       // Taxi escapes
        modifyHP(HP1, static_cast<double>(HP1) * -0.1);
        modifyExp(EXP1, static_cast<double>(EXP1) * -0.12);
        // HP1 *= 0.9;
        // EXP1 *= 0.88;

        modifyHP(HP2, static_cast<double>(HP2) * -0.1);
        modifyExp(EXP2, static_cast<double>(EXP2) * -0.12);
        // HP2 *= 0.9;
        // EXP2 *= 0.88;
       return -taxiScore; // Return negative taxi's score
   } else {
        // Sherlock and Watson catch the taxi
        modifyHP(HP1, static_cast<double>(HP1) * 0.1);
        // HP1 *= 1.1;
        modifyExp(EXP1, static_cast<double>(EXP1) * 0.12);
        // EXP1 *= 1.12;
        modifyHP(HP2, static_cast<double>(HP2) * 0.1);
        modifyExp(EXP2, static_cast<double>(EXP2) * 0.12);
        // HP2 *= 1.1;
        // EXP2 *= 1.12;
       return swScore; // Return Sherlock and Watson's score
   }

}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    // Extract "se" from email
    const char *at_sign = strchr(email, '@');
    if (!at_sign) {
        return -10; // Invalid email format (no @)
    }  
    //const char* dont allow changing pointer, so cant find the first occurences and return pointer, so make a copy into string
    std::string se(email, strchr(email, '@') - email); //strchr return after @, so strchr - email = - x, string se tu email den -x => start -> before @

    // Check password length
    int passwordLength = strlen(s);
    if (passwordLength < minPasswordLength) {
        return -1;
    }
    else if (passwordLength > maxPasswordLength) {
        return -2;
    }

    // Check if password contains 'se'
    if (std::string(s).find(se) != std::string::npos) {
        return -(300 + std::string(s).find(se));
    }

    // Check for consecutive identical characters
    for (int i = 0; i < passwordLength - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }

    // Check for at least one special character
    bool hasSpecialCharacter = false;
    for (int i = 0; s[i] != '\0'; ++i) {
        for (const char special : specialCharacters) {
            if (s[i] == special) {
                hasSpecialCharacter = true;
                break;
            }
        }
        if (hasSpecialCharacter) break;
    }

    if (!hasSpecialCharacter) {
        return -5;
    }

    // Check for valid characters
    for (int i = 0; i < passwordLength; ++i) {
        if (!isalnum(s[i]) && strchr(specialCharacters, s[i]) == nullptr) {
            // Found an invalid character
            return i + 1; // Adjusting as per requirement might need to return the position (1-based)
        }
    }

    // If all conditions are satisfied, password is valid
    return -10;

}

// Task 5

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int counts[50] = {0}; // Upto 30 distinct, set 50 to be sure 
    int firstPositions[50] = {0};
    int distinctCount = 0;
    char const* distinctPwds[50] = {nullptr};

    // Count occurrences and track first positions
    for (int i = 0; i < num_pwds; ++i) {
        bool found = false;
        for (int j = 0; j < distinctCount; ++j) {
            if (strcmp(arr_pwds[i], distinctPwds[j]) == 0) { //compare 2 string, if identical, it return 0, else nullptr
                counts[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            distinctPwds[distinctCount] = arr_pwds[i];
            counts[distinctCount] = 1;
            firstPositions[distinctCount] = i;
            distinctCount++;
        }
    }

    // Find the correct password
    int maxCount = 0;
    size_t maxLength = 0;
    int positionOfCorrectPwd = num_pwds; // Initialize with max possible value
    for (int i = 0; i < distinctCount; ++i) {
        if ((counts[i] > maxCount) || (counts[i] == maxCount && strlen(distinctPwds[i]) > maxLength)) {
            maxCount = counts[i];
            maxLength = strlen(distinctPwds[i]);
            positionOfCorrectPwd = firstPositions[i];
        }
    }

    return positionOfCorrectPwd;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////