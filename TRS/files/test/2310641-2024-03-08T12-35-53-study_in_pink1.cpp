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
void limitValue(int &value, int min, int max) {
    if (value < min) value = min;
    else if (value > max) value = max;
}

float myceil(float input) {
    float result = ceil(input);
    float diff = result - input;
    if (diff > 0.999) return input;
    else return result;
    }


int sumofdigits(int x) {
    return floor(x / 10) + x - 10 * floor(x / 10);
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ((e1 < 0) || (e1 > 99)) return -99;
    /////// case 1
    if ((e1 >= 0) && (e1 <= 3)){

        if (e1 == 0)    exp2 += 29;
        if (e1 == 1)    exp2 += 45;
        if (e1 == 2)    exp2 += 75;
        if (e1 == 3)    exp2 += 29 + 45 + 75;

        int D = e1 * 3 + exp1 * 7;

        if (D % 2 == 0) {
            exp1 = myceil(exp1 + (1.0) * D / 200);
            limitValue(exp1, 0, 600);
        }
        else {
            exp1 = myceil(exp1 - (1.0) * D / 100);
            limitValue(exp1, 0, 600);
        }
    }
    
    /////// case 2
    if ((e1 >= 4) && (e1 <= 99)){
        int oldexp2 = exp2;

        if ((e1 >= 4) && (e1 <= 19)) {
            exp2 = myceil(exp2 + (1.0) * e1 / 4 + 19);
            limitValue(exp2, 0, 600);
        }
        if ((e1 >= 20) && (e1 <= 49)) {
            exp2 = myceil(exp2 + (1.0) * e1 / 9 + 21);
            limitValue(exp2, 0, 600);
        }
        if ((e1 >= 50) && (e1 <= 65)) {
            exp2 = myceil(exp2 + (1.0) * e1 / 16 + 17);
            limitValue(exp2, 0, 600);
        }

        if ((e1 >= 66) && (e1 <= 79)){
            exp2 = myceil(exp2 + (1.0) * e1 / 4 + 19);
            limitValue(exp2, 0, 600);
            if (exp2 > 200) {
                exp2 = myceil(exp2 + (1.0) * e1 / 9 + 21);
                limitValue(exp2, 0, 600);
            }
        }

        if ((e1 >= 80) && (e1 <= 99)){
            exp2 = myceil(exp2 + (1.0) * e1 / 4 + 19);
            limitValue(exp2, 0, 600);
            exp2 = myceil(exp2 + (1.0) * e1 / 9 + 21);
            limitValue(exp2, 0, 600);
            if (exp2 > 400) {
                exp2 = myceil(exp2 + (1.0) * e1 / 16 + 17);
                limitValue(exp2, 0, 600);
            }
        }

        if (exp2 - oldexp2 > e1 / 4 + 19 + e1 / 9 + 21 + 3) {
            exp2 = myceil(exp2 * 1.15);
            limitValue(exp2, 0, 600);
        }

        exp1 -= e1;
    }

    /////// limiting stuff
    limitValue(exp1, 0, 600);
    limitValue(exp2, 0, 600);

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if ((E2 < 0) || (E2 > 99)) return -99;
    /////// road 1
    int S;
    float P1, P2, P3;

    // calc P1
    int flsq = pow(floor(sqrt(EXP1)), 2);
    int clsq = pow(myceil(sqrt(EXP1)), 2);
    if (clsq - EXP1 < EXP1 - flsq) S = clsq; else S = flsq;

    if (EXP1 >= S) P1 = 1; else P1 = ((1.0) * EXP1 / S + 80) / 123;
    
    /////// road 2
    int initialM = M1;

    do {
        /// hp recovering
        if (HP1 < 200) {
            HP1 = myceil(HP1 * (float)1.3);
            limitValue(HP1, 0, 666);
            M1 -= 150;
        }
        else {
            HP1 = myceil(HP1 * (float)1.1);
            limitValue(HP1, 0, 666);
            M1 -= 70;
        }
        if ((M1 < 0) || (((initialM - M1) > initialM * 0.5) && (E2 % 2 == 1))) break; // money check

        /// taxi or carriage
        if (EXP1 < 400) M1 -= 200; else M1 -= 120;
        EXP1 = myceil(EXP1 * (float)1.13);
        limitValue(EXP1, 0, 600);
        if ((M1 < 0) || (((initialM - M1) > initialM * 0.5) && (E2 % 2 == 1))) break; // money check

        /// helping homeless
        if (EXP1 < 300) M1 -= 100; else M1 -= 120;
        EXP1 = myceil(EXP1 * (float)0.9);
        if ((M1 < 0) || (((initialM - M1) > initialM * 0.5) && (E2 % 2 == 1))) break; // money check

        // loop continue?
        if ((E2 % 2 == 0) || ((initialM - M1) > initialM * 0.5)) break;
    } while (1);

    // mana decrease
    HP1 = myceil(HP1 * (float)0.83);
    EXP1 = myceil(EXP1 * (float)1.17);

    // limiting stuff
    limitValue(HP1, 0, 666);
    limitValue(EXP1, 0, 600);
    limitValue(M1, 0, 3000);

    // calc P2
    flsq = pow(floor(sqrt(EXP1)), 2);
    clsq = pow(myceil(sqrt(EXP1)), 2);
    if (clsq - EXP1 < EXP1 - flsq) S = clsq; else S = flsq;

    if (EXP1 >= S) P2 = 1; else P2 = ((1.0) * EXP1 / S + 80) / 123;

    // road 3
    int P3a[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

    if (E2 <= 10) P3 = P3a[E2] / 100;

    else {
    int digitSE2 = sumofdigits(E2);
    int digitLE2 = digitSE2 - 10 * floor(digitSE2 / 10);
    P3 = (1.0) * P3a[digitLE2] / 100;
    }

    // finally
    if ((P1 == 1) && (P2 == 1) && (P3 == 1)) EXP1 = myceil(EXP1 * (float)0.75);
    else {
        float finalP = (P1 + P2 + P3) / 3;
        if (finalP < 0.5) {
            HP1 = myceil(HP1 * (float)0.85);
            EXP1 = myceil(EXP1 * (float)1.15);
            limitValue(EXP1, 0, 600);
        }
        else {
            HP1 = myceil(HP1 * (float)0.9);
            EXP1 = myceil(EXP1 * (float)1.2);
            limitValue(EXP1, 0, 600);
        }
    }

    // limitting stuff again
    limitValue(HP1, 0, 666);
    limitValue(EXP1, 0, 600);
    limitValue(M1, 0, 3000);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ((E3 < 0) || (E3 > 99)) return -99;
    // creating matrix
    int map[10][10];
    int i, j, counter1 = 0, counter2 = 0;
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (map[i][j] > E3 * 2) counter1++;
            if (map[i][j] < - E3) counter2++;
        }
    }

    // calculate meeting point
    int i0 = sumofdigits(sumofdigits(counter1));
    int j0 = sumofdigits(sumofdigits(counter2));

    i = i0;
    j = j0;
    int score, k, maxleft = map[i][j], maxright = map[i][j];

    // max of left diag
    for (k = 1; k <= 9; k++) {
        i++; j++;
        if (i > 9) {
            i = 10 - j;
            j = 0;
        }
        if (j > 9) {
            j = 10 - i;
            i = 0;
        }
        if (map[i][j] > maxleft) maxleft = map[i][j];
    }
    i = i0;
    j = j0;

    // max of right diag
    for (k = 1; k <= 9; k++) {
        i++; j--;
        if (j < 0) {
            j = i - 1;
            i = 0;
        }
        if (i > 9) {
            i = j + 1;
            j = 9;
        }
        if (map[i][j] > maxright) maxright = map[i][j];
    }

    score = (maxleft + maxright + abs(maxleft - maxright)) / 2;
    int output3;

    // can they catch?
    if (abs(score) < abs(map[i0][j0])) {
        EXP1 = myceil(EXP1 * (float)0.88);
        EXP2 = myceil(EXP2 * (float)0.88);
        HP1 = myceil(HP1 * (float)0.9);
        HP2 = myceil(HP2 * (float)0.9);
        output3 = map[i0][j0];
    }
    else {
        EXP1 = myceil(EXP1 * (float)1.12);
        limitValue(EXP1, 0, 600);
        EXP2 = myceil(EXP2 * (float)1.12);
        limitValue(EXP2, 0, 600);
        HP1 = myceil(HP1 * (float)1.1);
        limitValue(HP1, 0, 666);
        HP2 = myceil(HP2 * (float)1.1);
        limitValue(HP2, 0, 666);
        output3 = score;
    }

    // 400 * 1.1 = 440 but myceil(400 * 1.1) = 441 ?

    // limitting stuff again
    limitValue(HP1, 0, 666);
    limitValue(HP2, 0, 666);
    limitValue(EXP1, 0, 600);
    limitValue(EXP2, 0, 600);
    
    return output3;
}

// Task 4

size_t isRepeat(const string& str) {
    int count = 1;
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i - 1]) {
            count++;
            if (count > 2) return i-1;
        }
        else count = 1;
    }
    return 0;
}

bool isSpechar(char ch) {
    return ch == '@' || ch == '#' || ch == '%' || ch == '$' || ch == '!';
}

size_t find_first_invalid(const string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (!isalnum(ch) && !isSpechar(ch)) return i;
    }
    return -1;
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se, strs = s, stremail = email;
    int atisat, seiisat, sciisat, spechar, invalidchar;

    atisat = stremail.find_first_of("@");
    se.assign(email, 0, atisat);
    seiisat = strs.find(se);
    sciisat = isRepeat(s) - 1;
    spechar = strs.find_first_of("@#%$!");
    invalidchar = find_first_invalid(s);

    if (strs.size() < 8) return -1;
    if (strs.size() > 20) return -2;
    if (seiisat != string::npos) return -(300 + (int)seiisat);
    if (isRepeat(s)) return -(400 + sciisat);
    if (spechar == string::npos) return -5;
    if (invalidchar != string::npos) return invalidchar;

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    int maxCount = 0;
    size_t maxLength = 0;
    int firstPosition = -1; // -1 means not found first pos

    for (int i = 0; i < num_pwds; i++) {
        string currentPwd = arr_pwds[i];
        int currentCount = 1;
        size_t currentLength = currentPwd.length();

        // counting how many repetition
        for (int j = i + 1; j < num_pwds; j++) {
            if (currentPwd == arr_pwds[j]) currentCount++;
        }

        // check if current password is new max
        if ((currentCount > maxCount) || (currentCount == maxCount && currentLength > maxLength)) {
            maxCount = currentCount;
            maxLength = currentLength;
            firstPosition = i;
        }
    }

    return firstPosition;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////