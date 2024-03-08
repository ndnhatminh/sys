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

//Checking Hit Points
void checkHP(int& HP1, int& HP2)
{
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (HP2 < 0) HP2 = 0;
    if (HP2 > 666) HP2 = 666;
}

//Checking Experience Points
void checkEXP(int& EXP1, int& EXP2)
{
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 600) EXP2 = 600;
}

//Checking Money
void checkM(int& M1, int& M2)
{
    if (M1 < 0) M1 = 0;
    if (M1 > 3000) M1 = 3000;
    if (M2 < 0) M2 = 0;
    if (M2 > 3000) M2 = 3000;
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    checkEXP(exp1, exp2);
    //Case 1
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) exp2 += 29;
        if (e1 == 1) exp2 += 45;
        if (e1 == 2) exp2 += 75;
        if (e1 == 3) exp2 = exp2 + 29 + 45 + 75;

        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 += D / 200;
        else exp1 -= D / 100;
    }

    //Case 2
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 <= 19) exp2 = ceil(exp2 + (1.0 * e1) / 4 + 19 ); //Changing e1 to double to use ceil round up function

        else if (e1 <= 49) exp2 = ceil(exp2 + (1.0 * e1) / 9 + 21 );

        else if (e1 <= 65) exp2 = ceil(exp2 + (1.0 * e1) / 16 + 17 );

        else if (e1 <= 79) {
            exp2 = ceil(exp2 + (1.0 * e1) / 4 + 19);

            if (exp2 > 200) exp2 = ceil(exp2 + (1.0 * e1) / 9 + 21);
        }

        else if (e1 <= 99) {
            exp2 = ceil(exp2 + (1.0 * e1) / 4 + 19);
            exp2 = ceil(exp2 + (1.0 * e1) / 9 + 21);

            if (exp2 > 400) {
                exp2 = ceil(exp2 + (1.0 * e1) / 16 + 17);
                exp2 = ceil(exp2 * 1.15);
            }
        }
        exp1 -= e1;
    }

    else return -99;
    checkEXP(exp1, exp2);

    return exp1 + exp2;
}

// Task 2
//For calculating P1 and P2
double traceLuggage_Road1(int EXP1) {
    double P;
    int S = pow(round(sqrt(EXP1)), 2);//Finding nearest perfect square value of EXP1

    if (EXP1 >= S) P = 1;
    else P = ((1.0 * EXP1) / S + 80) / 123.0;
    return P;
}

//For calculating P3
int traceLuggage_Road3(int E2) {
    if (E2 < 10) {
        return E2;
    }
    else {
        int sum = (E2 / 10) + (E2 % 10); //Sum of the two digits
        return sum % 10; //Unit place of the sum
    }
}

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    int a = 0;
    checkHP(HP1, a); //Only checking HP1, not HP2
    checkEXP(EXP1, a);
    checkM(M1, a);

    //Road 1
    double P1 = traceLuggage_Road1(EXP1);

    //Road 2
    if (E2 % 2 == 1) { //E2 is odd
        int fee = 0;
        int halfM = M1 / 2;
        while(M1 > 0) {
            //Road 2 First event
            if (HP1 < 200) {
                HP1 = ceil(HP1 * 1.3);
                M1 -= 150;
                fee += 150;
            }
            else {
                HP1 = ceil(HP1 * 1.1);
                M1 -= 70;
                fee += 70;
            }
            if (fee > halfM) break;

            //Road 2 Second event
            if (EXP1 < 400) {
                M1 -= 200;
                fee += 200;
            }
            else {
                M1 -= 120;
                fee += 120;
            }
            EXP1 = ceil(EXP1 * 1.13);
            if (fee > halfM) break;

            //Road 3 Third event
            if (EXP1 < 300) {
                M1 -= 100;
                fee += 100;
            }
            else {
                M1 -= 120;
                fee += 120;
            }
            EXP1 = ceil(EXP1 * 0.9);
            if (fee > halfM) break;
        }
        HP1 = ceil(HP1 * 0.83);
        EXP1 = ceil(EXP1 * 1.17);
    }

    else { //E2 is even
        //Road 2 First event
        if (M1 > 0) {
            if (HP1 < 200) {
                HP1 = ceil(HP1 * 1.3);
                M1 -= 150;
            }
            else {
                HP1 = ceil(HP1 * 1.1);
                M1 -= 70;
            }
        }

        //Road 2 Second event
        if (M1 > 0) {
            if (EXP1 < 400) {
                M1 -= 200;
            }
            else {
                M1 -= 120;
            }
            EXP1 = ceil(EXP1 * 1.13);
        }

        //Road 2 Third event
        if (M1 > 0) {
            if (EXP1 < 300) {
                M1 -= 100;
            }
            else {
                M1 -= 120;
            }
            EXP1 = ceil(EXP1 * 0.9);
        }
    }

    double P2 = traceLuggage_Road1(EXP1);

    //Road 3
    const int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i = traceLuggage_Road3(E2);
    double P3 = P[i] / 100.0;

    //Post-3 routes
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = ceil(EXP1 * 0.75);
    }
    else {
        double prob = (P1 + P2 + P3) / 3.0;
        if (prob < 0.5) {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        }
        else {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
        }
    }

    //Last checking
    checkHP(HP1, a);
    checkEXP(EXP1, a);
    checkM(M1, a);

    return HP1 + EXP1 + M1;
}

// Task 3
//Creating the grade matrix of the taxi
void taxiScore(int taxiMap[10][10], int E3) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxiMap[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
}

//Creating the grade matrix of Sherlock & Watson
void SherlockWatsonScore(int taxiMap[10][10], int sherlockWatsonMap[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int max = 0;
            for (int k = 0; i + k < 10 && j + k < 10; k++) {
                if (taxiMap[i + k][j + k] > max) max = taxiMap[i + k][j + k];
            }
            for (int k = 0; i + k < 10 && j - k >= 0; k++) {
                if (taxiMap[i + k][j - k] > max) max = taxiMap[i + k][j - k];
            }
            sherlockWatsonMap[i][j] = max;
        }
    }
}

int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    checkHP(HP1, HP2);
    checkEXP(EXP1, EXP2);

    int taxiMap[10][10] = { 0 };
    int sherlockWatsonMap[10][10] = { 0 };

    taxiScore(taxiMap, E3);
    SherlockWatsonScore(taxiMap, sherlockWatsonMap);

    //Counting points greater than E3 * 2 and points smaller than -E3
    int i = 0, j = 0;
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            if (taxiMap[row][col] > E3 * 2) i++;
            if (taxiMap[row][col] < -E3) j++;
        }
    }

    //Calculating sum of two digits until it's a one-digit number
    while (i >= 10) {
        i = (i / 10) + (i % 10);
    }
    while (j >= 10) {
        j = (j / 10) + (j % 10);
    }

    //Determine if Sherlock and Watson catch the taxi
    int taxiGrade = taxiMap[i][j];
    int sherlockWatsonGrade = sherlockWatsonMap[i][j];
    if (abs(taxiGrade) > abs(sherlockWatsonGrade)) {
        //Failed
        HP1 *= 0.9;
        EXP1 *= 0.88;
        HP2 *= 0.9;
        EXP2 *= 0.88;
        checkHP(HP1, HP2);
        checkEXP(EXP1, EXP2);
        return taxiGrade;
    }
    else {
        //Success
        HP1 *= 1.1;
        EXP1 *= 1.12;
        HP2 *= 1.1;
        EXP2 *= 1.12;
        checkHP(HP1, HP2);
        checkEXP(EXP1, EXP2);
        return sherlockWatsonGrade;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
    //Length of password
    int length = strlen(s);
    if (length < 8) return -1;
    if (length > 20) return -2;

    //Checking if s contains se
    int sei;
    string se, sp;

    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') break;
        se.push_back(email[i]);//String se will contain characters before @
    }

    for (int i = 0; i < length; i++) {
        sp.push_back(s[i]);//Converting s to string
    }

    sei = sp.find(se);
    if (sei != -1) return -(300 + sei);

    //Checking for more than 2 consecutive and identical characters
    for (int sci = 0; sci < length; sci++) {
        if (s[sci] == s[sci + 1] && s[sci] == s[sci + 2]) return -(400 + sci);
    }

    //Checking for special characters
    for (int i = 0; i < length; i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') return -10;
    }
    return -5;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxCount = 0;
    int maxLength = 0;
    const char* correctPass = ""; //Correct password will be an empty string

    for (int i = 0; i < num_pwds; i++) {
        const char* pass = arr_pwds[i];
        int count = 0;
        int length = strlen(pass);

        //Counting the number of occurrences of the current password
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(pass, arr_pwds[j]) == 0) count++;
        }

        //Updating the correct password
        if (count > maxCount || (count == maxCount && length > maxLength)) {
            maxCount = count;
            maxLength = length;
            correctPass = pass;
        }
    }

    //Finding the position of the first occurrence of the correct password
    for (int i = 0; i < num_pwds; i++) {
        if (arr_pwds[i] == correctPass) return i;
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////