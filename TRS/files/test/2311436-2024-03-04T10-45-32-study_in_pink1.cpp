#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNCTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
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
int calculateExperience (int & exp) {
    if (exp > 600)
        return 600;
    else {
    if (exp < 0)
        return 0;
    else
        return exp;
    }
}   

int firstMeet(int & exp1, int & exp2, int e1) {
    //TH1
    if (e1 < 0 || e1 > 99)
        return -99;

    exp1 = calculateExperience(exp1);
    exp2 = calculateExperience(exp2);

    if ((e1 >= 0) && (e1 < 4)) {
        switch(e1) {
            case 0:
                exp2 += 29;
                break;
            case 1: 
                exp2 += 45;
                break;
            case 2:
                exp2 += 75;
                break;
            default:
                exp2 += (29 + 45 + 75);
                break;
        }

        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            exp1 += ceil(D / 200.0);
        else
            exp1 = ceil(exp1 - D / 100.0);
        }

        else //TH2
        {
        if (e1 >= 4 && e1 < 20) // Thong tin 1
            exp2 += ceil(e1 / 4.0) + 19;

        else if (e1 < 50) // Thong tin 2
            exp2 += ceil(e1 / 9.0) + 21;

        else if (e1 < 66) // Thong tin 3
            exp2 += ceil(e1 / 16.0) + 17;

        else if (e1 < 80) {
            exp2 += ceil(e1 / 4.0) + 19;
            if (exp2 > 200)
                exp2 += ceil(e1 / 9.0) + 21;
            }

        else if (e1 < 100) {
            exp2 += ceil(e1 / 4.0) + 19;
            exp2 += ceil(e1 / 9.0) + 21;
            if(exp2 > 400) {
                exp2 += (ceil(e1 / 16.0) + 17);
                exp2 = ceil((exp2 * 1.0) * 1.15);
                }
            }

            exp1 -= e1;
        }
    
    exp1 = calculateExperience(exp1);
    exp2 = calculateExperience(exp2);
    return exp1 + exp2;
}

// Task 2
//Check money
int calculateMoney (int& M) { 
    if (M > 3000)
        return 3000;
    else {
    if (M < 0)
        return 0;
    else
        return M;
    }
}

//Check HP:
int calculateHP (int& HP) { 
    if (HP > 666)
        return 666;
    else {
    if (HP < 0)
        return 0;
    else
        return HP;
    }
}

//Find nearest square number:
int nearestSquare(int& EXP1) {
    int squareRoot = static_cast<int>(sqrt(EXP1));
    int lower = squareRoot * squareRoot;
    int upper = (squareRoot + 1) * (squareRoot + 1);

    if (abs(EXP1 - lower) <= abs(upper - EXP1))
        return lower;
    else 
        return upper;
}   

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 < 0 || E2 > 99)
        return -99;

    EXP1 = calculateExperience(EXP1);
    M1 = calculateMoney(M1);
    HP1 = calculateHP(HP1);

    //Road 1:
    int S = nearestSquare(EXP1);
    double P1;
    if (EXP1 >= S)
        P1 = 1.0;
    else
        P1 = ((static_cast<int>(EXP1) / S) + 80.0) / 123.0;

    //Road 2:
    int initial_money = M1;
    int total_paid = 0;

    while (M1 > 0) {
        //Round 1:
        if (HP1 < 200) {
            HP1 = ceil((HP1 * 13.0 / 10)); 
            M1 -= 150; 
        }
        else {
            HP1 = ceil(HP1 * 11.0 / 10);
            M1 -= 70; 
        }
        HP1 = calculateHP(HP1);
        total_paid = initial_money - M1;

        //Round 2:
        if (E2 % 2 != 0 && total_paid > initial_money / 2.0) {
            break;
        }

        if (M1 <= 0) break;

        if (EXP1 < 400) 
            M1 -= 200; 
        else 
            M1 -= 120; 
        
        EXP1 = ceil(EXP1 * 11.3 / 10);
        total_paid = initial_money - M1;

        //Round 3:
        if (E2 % 2 != 0 && total_paid > initial_money / 2.0) {
            break;
        }

        if (M1 <= 0) break;

        if (EXP1 < 300) 
            M1 -= 100;
        else 
            M1 -= 120;

        EXP1 = ceil(EXP1 * 9.0 / 10);
        total_paid = initial_money - M1;

        if (E2 % 2 != 0 && total_paid > initial_money / 2.0) {
            break;
        }
        if(E2 % 2 == 0) {
            break;
        }
    }

    HP1 = ceil(static_cast<double>(HP1) * 0.83);
    EXP1 = ceil(EXP1 * 11.7 / 10);

    M1 = calculateMoney(M1);
    EXP1 = calculateExperience(EXP1);
    HP1 = calculateHP(HP1);

    S = nearestSquare(EXP1);
    double P2;
    if (EXP1 >= S)
        P2 = 1.0;
    else
        P2 = ((static_cast<int>(EXP1) / S) + 80.0) / 123.0;

    // Road 3:
    int Pi[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;

    if (E2 < 10) 
        i = E2;
    else {
        int sum = (E2 / 10) + (E2 % 10);
        i = sum % 10;
    }

    int k = Pi[i];
    double P3 = static_cast<double>(k) / 100;

    if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0)
        EXP1 = ceil(EXP1 * 7.5 / 10);
    else {
        double P = (P1 + P2 + P3) / 3;
        if (P < 0.50000){
            HP1 = ceil(HP1 * 8.5 / 10);
            EXP1 = ceil(EXP1 * 11.5 / 10);
        }
        else {
            HP1 = ceil(HP1 * 9.0 / 10);
            EXP1 = ceil(EXP1 * 12.0 / 10);
        }
    }

    EXP1 = calculateExperience(EXP1);
    HP1 = calculateHP(HP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int sumDigits(int &num) {
    if (num < 10)
        return num;
    else {
        int sum = (num / 10) + (num % 10);
        if (sum < 10) {
            return sum;
        }
        else {
            int anotherSum = (sum / 10) + (sum % 10);
            return anotherSum;
        }
    }
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    if(E3 < 0 || E3 > 99)
        return -99;
 
    int i, j;
    int taxiMatrix [10][10] = {0};
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++){
            taxiMatrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    int meeting_a = 0, meeting_b = 0;
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                if (taxiMatrix[i][j] > (E3 * 2)) {
                    meeting_a++;
            }
                if (taxiMatrix[i][j] < (-E3)) {
                    meeting_b++;
            }
        }
    }
    meeting_a = sumDigits(meeting_a);
    meeting_b = sumDigits(meeting_b);
    int taxiPoint = taxiMatrix[meeting_a][meeting_b];

    int maxLeft = INT_MIN;
    int maxRight = INT_MIN;

    // Iterate through the matrix
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // Check if the element belongs to the left diagonal passing through meeting point
            if (i - j == meeting_a - meeting_b) {
                if (taxiMatrix[i][j] > maxLeft) {
                    maxLeft = taxiMatrix[i][j];
                }
            }

            // Check if the element belongs to the right diagonal passing through meeting point
            if (i + j == meeting_a + meeting_b) {
                if (taxiMatrix[i][j] > maxRight) {
                    maxRight = taxiMatrix[i][j];
                }
            }
        }
    }

    int largestNumber = maxLeft > maxRight ? maxLeft : maxRight;

    int SherlockWatson_Point = abs(largestNumber);

    if (abs(taxiPoint) <= SherlockWatson_Point){
        EXP1 = ceil(EXP1 * 11.2 / 10);
        HP1 = ceil(HP1 * 11.0 / 10);
        EXP2 = ceil(EXP2 * 11.2 / 10);
        HP2 = ceil(HP2 * 11.0 / 10); 
    }

    else {
        EXP1 = ceil(EXP1 * 0.88);
        HP1 = ceil(HP1 * 9.0 / 10);
        EXP2 = ceil(EXP2 * 0.88);
        HP2 = ceil(HP2 * 9.0 / 10);
    }

    EXP1 = calculateExperience (EXP1);
    EXP2 = calculateExperience (EXP2);
    HP1 = calculateHP (HP1);
    HP2 = calculateHP (HP2);

    int greaterValue = abs(taxiPoint) > SherlockWatson_Point ? taxiPoint : SherlockWatson_Point;
    return greaterValue;

}

// Task 4
// A function to check if a character is a special character
bool checkSpecial(char c) {
    return (c == '@' || c == '#' || c == '%' || c == '$' || c == '!');
}

// A function to check the validity of a password
int checkPassword(const char * s, const char * email) {
    int i;
    // Get the length of the password
    int length = strlen(s);

    // Check the length requirement
    if (length < 8) 
        return -1;
    if (length > 20) 
        return -2;

    // Get the string before the '@' character in the email
    string se = "";
    for (i = 0; i < 100; i++) {
        if (email[i] == '@') 
            break;
            se += email[i];
    }

    // Check if the password contains the email string
    if (strstr(s, se.c_str()) != NULL) {
        return -(300 + (strstr(s, se.c_str()) - s));
    }

    // Check the character requirements
    bool hasLower = false;
    bool hasUpper = false;
    bool hasDigit = false; 
    bool hasSpecial = false; 
    int firstPosition = -1; 
    for (i = 0; i < length; i++) {
        char c = s[i];
        if (islower(c)) 
            hasLower = true;
        else if (isupper(c)) 
            hasUpper = true;
        else if (isdigit(c)) 
            hasDigit = true;
        else if (checkSpecial(c))
            hasSpecial = true;
        else {
        if (firstPosition == -1) 
                firstPosition = i; // Update the position of the first violation
        }
    }

    // Check the consecutive character requirement
    for (i = 0; i < length; i++){
        char c = s[i];
        if (s[i] == s[i+1] && s[i] == s[i+2])
            return -(400 + i);
    }
    
    // Check if the password has at least one special character
    if (!hasSpecial) 
        return -5;

    if (firstPosition != -1) 
        return firstPosition;

    // If all requirements are met, return -10
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    const char *frequentPassword = nullptr;
    int frequentCount = 0;
    int i, j;

    for (i = 0; i < num_pwds; i++) {
        const char *currentPassword = arr_pwds[i];
        int count = 1;

        if (currentPassword == nullptr)
            continue;

        for (j = i + 1; j < num_pwds; j++) {
            if (strcmp(currentPassword, arr_pwds[j]) == 0)
                count++;
        }

        if (count > frequentCount ||
            (count == frequentCount && strlen(currentPassword) 
                > strlen(frequentPassword))) {
            frequentCount = count;
            frequentPassword = currentPassword;
        }
    }

    for (i = 0; i < num_pwds; i++) {
        if (strcmp(arr_pwds[i], frequentPassword) == 0)
            return i;
    }

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
