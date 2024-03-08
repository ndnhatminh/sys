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
int check(int n, int firstPoint, int lastPoint) {
n = (n < firstPoint) ? firstPoint : (n > lastPoint) ? lastPoint : n;
return n;
}
int checkEvenOdd(int num) {
    return(num % 2 == 0) ? 1 : 0;
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1 >= 0 && e1 <= 99){
        exp2 = check(exp2, 0, 600);
        exp1 = check(exp1, 0, 600);
        int d = e1*3 + exp1*7;
        if(e1 == 0){
            exp2 += 29;
            if(checkEvenOdd(d) == 1){
                if(d % 200 != 0){
                exp1 = exp1 + d/200 + 1;
                }else exp1 = exp1 + d/200;
            }
            else{
                exp1 = exp1 - d/100;
            }
        }
        else if(e1 == 1){
            exp2 += 45;
            if(checkEvenOdd(d) == 1){
                if(d % 200 != 0){
                exp1 = exp1 + d/200 + 1;
                }else exp1 = exp1 + d/200;
            }
            else{
                exp1 = exp1 - d/100;
            }
        }
        else if(e1 == 2){
            exp2 += 75;
            if(checkEvenOdd(d) == 1){
                if(d % 200 != 0){
                exp1 = exp1 + d/200 + 1;
                }else exp1 = exp1 + d/200;
            }
            else{
                exp1 = exp1 - d/100;
            }
        }
        else if(e1 == 3){
            exp2 += 149;
            if(checkEvenOdd(d) == 1){
                if(d % 200 != 0){
                exp1 = exp1 + d/200 + 1;
                }else exp1 = exp1 + d/200;
            }
            else{
                exp1 = exp1 - d/100;
            }
        }
        else if(e1 >= 4 && e1 <= 19){
            if(e1 % 4 != 0){
                exp2 = exp2 + e1/4 + 19 + 1;
            }
            else exp2 = exp2 + e1/4 + 19;
            exp1 -= e1;
        }
        else if(e1 >= 20 && e1 <= 49){
            if(e1 % 9 != 0){
                exp2 = exp2 + e1/9 + 21 + 1;
            }
            else exp2 = exp2 + e1/9 + 21;
            exp1 -= e1;
        }
        else if(e1 >= 50 && e1 <= 65){
            if(e1 % 16 != 0){
                exp2 = exp2 + e1/16 + 17 + 1;
            }
            else exp2 = exp2 + e1/16 + 17;
            exp1 -= e1;
        }
        else if(e1 >= 66 && e1 <= 79){
            if(e1 % 4 != 0){
                exp2 = exp2 + e1/4 + 19 + 1;
            }
            else exp2 = exp2 + e1/4 + 19;
            if(exp2 > 200){
                if(e1 % 9 != 0){
                exp2 = exp2 + e1/9 + 21 + 1;
            }
            else exp2 = exp2 + e1/9 + 21;
            }
            exp1 -= e1;
        }
        else if(e1 >= 80 && e1 <= 99){
            if(e1 % 4 != 0){
                exp2 = exp2 + e1/4 + 19 + 1;
            }
            else exp2 = exp2 + e1/4 + 19;
            if(e1 % 9 != 0){
                exp2 = exp2 + e1/9 + 21 + 1;
            }
            else exp2 = exp2 + e1/9 + 21;
            if(exp2 > 400){
                if(e1 % 16 != 0){
                exp2 = exp2 + e1/16 + 17 + 1;
            }
            else exp2 = exp2 + e1/16 + 17;
            if(exp2*115 % 100 != 0){
                 exp2 = (115*exp2)/100 + 1;
            }else exp2 = (115*exp2)/100;
            }
            exp1 -= e1;
        }
        exp2 = check(exp2, 0, 600);
        exp1 = check(exp1, 0, 600);
        return exp1 + exp2; 
    }
    else return -99;
}

// Task 2
// Function to check if a number is perfect square
bool isPerfect(int n) {
    int x = sqrt(n);
    return (x * x == n);
}

// Function to get the closest perfect square
float getClosestPerfectSquare(int S, int EXP1) {
    float P1 = -1;
    if(isPerfect(S)){
        P1 = 1;
    }
    else{
        int aboveS = -1;
        int belowS = -1;
        int temp;
        // Finding first perfect square number greater than N
        temp = S + 1;
        while(true){
            if(isPerfect(temp)){
                aboveS = temp;
                break;
            }
            else temp++;
        }
        // Finding first perfect square number less than N
        temp = S - 1;
        while(true){
            if(isPerfect(temp)){
                belowS = temp;
                break;
            }
            else temp--;
        }
        // Variables to store the differences
        int diff1 = aboveS - S;
        int diff2 = S - belowS;
        if(diff1 > diff2)
            S = belowS;
        else 
            S = aboveS;
    }
    if(EXP1 >= S)
        P1 = 1;
    else 
        P1 = ((float)EXP1/S + 80.0)/123.0;

    return P1;
}
// Function calculate i in road 3
int calculateIndex(int E2) {
    string E2_str = to_string(E2);
    if (E2_str.length() == 1) {
        return E2;
    }
    else if (E2_str.length() == 2) {
        int sum = (E2_str[0] - '0') + (E2_str[1] - '0'); // Subtract '0' to convert char to int
        return sum % 10; // Return the units digit of the sum
    }
    else {
        return -1;
    }
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    //Road 1
    if(E2 >= 0 && E2 <= 99){
    
        int S = EXP1;
        float P1 = getClosestPerfectSquare(S, EXP1);
    //Road 2
    int M = M1;
    if(E2 % 2 != 0){ // e2 is odd num
        while(M1 > ceilf(M/2.0)){
            HP1 = check(HP1, 0, 666);
            EXP1 = check(EXP1, 0, 600);
            M1 = check(M1, 0, 3000);
            if(HP1 < 200){ // eat and drink
                HP1 = ceilf(HP1*130/100.0);
                M1 -= 150;
            }   
            else{ // drink
                HP1 = ceilf(HP1*110/100.0);
                M1 -= 70;
            }
            HP1 = check(HP1, 0, 666);
            EXP1 = check(EXP1, 0, 600);
            M1 = check(M1, 0, 3000);
            if(M1 < ceilf(M/2)) break;
            if(EXP1 < 400){
                    M1 -= 200; // taxi  
                    EXP1 = ceilf(113*EXP1/100.0);
            }
                else{
                    M1 -= 120; // horse
                    EXP1 = ceilf(113*EXP1/100.0);
                }
            HP1 = check(HP1, 0, 666);
            EXP1 = check(EXP1, 0, 600);
            M1 = check(M1, 0, 3000);
            if(M1 < ceilf(M/2)) break;
            if(EXP1 < 300){
                    M1 -= 100; // homeless give instructions
                    EXP1 = ceilf(90*EXP1/100.0);
            }
                else{
                    M1 -= 120; // homeless lead the way
                    EXP1 = ceilf(90*EXP1/100.0);
                }
            HP1 = check(HP1, 0, 666);
            EXP1 = check(EXP1, 0, 600);
            M1 = check(M1, 0, 3000);
            if(M1 < ceilf(M/2)) break;
        }
    }
    else{ // e2 is even num 
    if(M1 >= 0){
        HP1 = check(HP1, 0, 666);
        EXP1 = check(EXP1, 0, 600);
        M1 = check(M1, 0, 3000);
        if(HP1 < 200){ // eat and drink
                HP1 = ceilf(HP1*130/100.0);
                M1 -= 150;
            }   
            else{ // drink
                HP1 = ceilf(HP1*110/100.0);
                M1 -= 70;
            }
        }
    if(M1 >= 0){
        HP1 = check(HP1, 0, 666);
        EXP1 = check(EXP1, 0, 600);
        M1 = check(M1, 0, 3000);
            if(EXP1 < 400){
                    M1 -= 200; // taxi  
                    EXP1 = ceilf(113*EXP1/100.0);
            }
                else{
                    M1 -= 120; // horse
                    EXP1 = ceilf(113*EXP1/100.0);
            }
       }
    if(M1 >= 0){
        HP1 = check(HP1, 0, 666);
        EXP1 = check(EXP1, 0, 600);
        M1 = check(M1, 0, 3000);
            if(EXP1 < 300){
                    M1 -= 100; // homeless give instructions
                    EXP1 = ceilf(90*EXP1/100.0);
            }
                else{
                    M1 -= 120; // homeless lead the way
                    EXP1 = ceilf(90*EXP1/100.0);
                }
        }   
    }
    // check
    HP1 = check(HP1, 0, 666);
    EXP1 = check(EXP1, 0, 600);
    M1 = check(M1, 0, 3000);
        // update when e2 is even or odd num
        HP1 = ceilf(83*HP1/100.0);
        EXP1 = ceilf(117*EXP1/100.0);
    HP1 = check(HP1, 0, 666);
    EXP1 = check(EXP1, 0, 600);
    M1 = check(M1, 0, 3000);
      
    S = EXP1;
    float P2 = getClosestPerfectSquare(S, EXP1);
    // road 3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float P3 = P[calculateIndex(E2)]/100.0;
    if(P1 == 1 && P2 == 1 && P3 == 1) 
                                    EXP1 = ceilf(75*EXP1/100.0);
        else{
            float P = (P1 + P2 + P3) / 3.0;
                if(P < 0.5){
                    HP1 = ceilf(85*HP1/100.0);
                    EXP1 = ceilf(115*EXP1/100.0);
                }
                else{
                    HP1 = ceilf(90*HP1/100.0);
                    EXP1 = ceilf(120*EXP1/100.0);
                }
        }

    HP1 = check(HP1, 0, 666);
    EXP1 = check(EXP1, 0, 600);
    M1 = check(M1, 0, 3000);  
    return HP1 + EXP1 + M1;
    }
    else
        return -99;
}

// Task 3
int taxiMatrix[10][10] = {0};

void taxiScore(int E3) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            taxiMatrix[i][j] = ((E3*j) + (i*2))*(i-j);
        }
    }
}

int getScoreSherlockWatson(int i, int j) {
    int maxPoint = INT_MIN;

    // left diagonal
    int x = i, y = j;
    while (x >= 0 && y >= 0) {
        maxPoint = max(maxPoint, taxiMatrix[x][y]);
        --x;
        --y;
    }
    x = i, y = j;
    while(x <= 9 && y <= 9){
        maxPoint = max(maxPoint, taxiMatrix[x][y]);
        ++x;
        ++y;
    }

    // right diagonal
    x = i, y = j;
    while (x <= 9 && y >= 0) {
        maxPoint = max(maxPoint, taxiMatrix[x][y]);
        ++x;
        --y;
    }
    x = i, y = j;
    while(x >= 0 && y <=9){
        maxPoint = max(maxPoint, taxiMatrix[x][y]);
        --x;
        ++y;
    }
    // Return max value in the array possiblePoints
    return maxPoint;
}

// Function to calculate the sum of digits of a number
int sumOfDigits(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int calculatePoint_i(int E3) {
    int i = 0;
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {
            if (taxiMatrix[row][col] > E3 * 2) {
                ++i;
            }
        }
    }
    while (i >= 10) {
        i = sumOfDigits(i);
    }

    return i;
}

int calculatePoint_j(int E3) {
    int j = 0;
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {
            if (taxiMatrix[row][col] < -E3) {
                ++j;
            }
        }
    }

    while (j >= 10) {
        j = sumOfDigits(j);
    }

    return j;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 >= 0 && E3 <= 99){
    // check
    HP1 = check(HP1, 0, 666);
    EXP1 = check(EXP1, 0, 600);
    HP2 = check(HP2, 0, 666);
    EXP2 = check(EXP2, 0, 600);
        taxiScore(E3);
        int i = calculatePoint_i(E3);
        int j = calculatePoint_j(E3);
        int taxiPoint = taxiMatrix[i][j];
        int sherlockWatsonPoint = abs(getScoreSherlockWatson(i,j));
        if(abs(taxiPoint) > sherlockWatsonPoint){
            // Update EXP and HP : Sherlock
            EXP1 = ceilf(88*EXP1/100.0);
            HP1 = ceilf(90*HP1/100.0);
            // Update EXP and HP : Watson
            EXP2 = ceilf(88*EXP2/100.0);
            HP2 = ceilf(90*HP2/100.0);
            // check
        HP1 = check(HP1, 0, 666);
        EXP1 = check(EXP1, 0, 600);
        HP2 = check(HP2, 0, 666);
        EXP2 = check(EXP2, 0, 600);
            // Return the greater grade between taxi and Sherlock & Watson
            return taxiPoint;
        }
        else{
            // Update EXP and HP : Sherlock
            EXP1 = ceilf(112*EXP1/100.0);
            HP1 = ceilf(110*HP1/100.0);
            // Update EXP and HP : Watson
            EXP2 = ceilf(112*EXP2/100.0);
            HP2 = ceilf(110*HP2/100.0);
            // check
        HP1 = check(HP1, 0, 666);
        EXP1 = check(EXP1, 0, 600);
        HP2 = check(HP2, 0, 666);
        EXP2 = check(EXP2, 0, 600);
            // Return the greater grade between taxi and Sherlock & Watson
            return sherlockWatsonPoint;
        }
    }
    else    
        return -99;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    char se[256];
    const char * at_sign_position = strchr(email, '@');
    if (at_sign_position != NULL) {
        size_t length = at_sign_position - email;
        strncpy(se, email, length);
        se[length] = '\0';  // Null-terminate the copied substring
    }
    const char * special_chars = "@#%$!";
    int n = strlen(s);

    if (n < 8) return -1;
    if (n > 20) return -2;
    if (strstr(s, se) != NULL) return -(300 + (strstr(s, se) - s));
    
    for (int i = 0; i < n - 2; ++i) {
        if (s[i] == s[i+1] && s[i+1] == s[i+2]) return -(400 + i);
    }
    
    if (strpbrk(s, special_chars) == NULL) return -5;
    
    for (int i = 0; i < n; ++i) {
        if (!isdigit(s[i]) && !isalpha(s[i]) && strchr(special_chars, s[i]) == NULL) {
            return i;
        }
    }
    
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_passwords[], int num_passwords) {
    int max_freq = 0, max_len = 0, pos = -1;
    for (int i = 0; i < num_passwords; ++i) {
        int count = 0;
        for (int j = 0; j < num_passwords; ++j) {
            if (strcmp(arr_passwords[i], arr_passwords[j]) == 0) {
                ++count;
            }
        }
        int len = strlen(arr_passwords[i]);
        if (count > max_freq || (count == max_freq && len > max_len)) {
            max_freq = count;
            max_len = len;
            pos = i;
        }
    }
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////