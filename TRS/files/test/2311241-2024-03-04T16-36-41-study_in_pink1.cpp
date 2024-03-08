#include "study_in_pink1.h"

bool readFile(
    const string& filename,
    int& HP1,
    int& HP2,
    int& EXP1,
    int& EXP2,
    int& M1,
    int& M2,
    int& E1,
    int& E2,
    int& E3
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
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    //Case 1: e1 = [0, 3]
    if (e1 >= 0 && e1 <= 3) {
        TESTEXP(exp2); TESTEXP(exp1);
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
        default:
            exp2 += (29 + 45 + 75);
            break;

        }
        TESTEXP(exp2)
            int D = e1 * 3 + exp1 * 7;
        (!(D & 1)) ? (exp1 = Ceil(exp1 + D / 200.0)) : (exp1 = Ceil(exp1 - D / 100.0)); TESTEXP(exp1);
    }
    //Case 2: e1 = [4, 99]
    else if (e1 >= 4 && e1 <= 19) {
        TESTEXP(exp1); TESTEXP(exp2);
        exp2 = Ceil(exp2 + (e1 / 4.0 + 19.0)); TESTEXP(exp2);
        exp1 = exp1 - e1; TESTEXP(exp1);
    }//information 1
    else if (e1 >= 20 && e1 <= 49) {
        TESTEXP(exp1); TESTEXP(exp2);
        exp2 = Ceil(exp2 + (e1 / 9.0 + 21.0)); TESTEXP(exp2);
        exp1 = exp1 - e1; TESTEXP(exp1);
    }//information 2
    else if (e1 >= 50 && e1 <= 65) {
        TESTEXP(exp1); TESTEXP(exp2);
        exp2 = Ceil(exp2 + (e1 / 16.0 + 17.0)); TESTEXP(exp2);
        exp1 = exp1 - e1; TESTEXP(exp1);
    }//information 3
    else if (e1 >= 66 && e1 <= 79) {    //information 4
        TESTEXP(exp1); TESTEXP(exp2);
        exp2 = Ceil(exp2 + (e1 / 4.0 + 19.0)); TESTEXP(exp2);
        if (exp2 > 200) exp2 = Ceil(exp2 + (e1 / 9.0 + 21.0)); TESTEXP(exp2);
        exp1 = exp1 - e1; TESTEXP(exp1);
    }
    else if (e1 >= 80 && e1 <= 99) { //information 5
        TESTEXP(exp1); TESTEXP(exp2);
        exp2 = Ceil(exp2 + (e1 / 4.0 + 19.0)); TESTEXP(exp2);
        exp2 = Ceil(exp2 + (e1 / 9.0 + 21.0)); TESTEXP(exp2);
        if (exp2 > 400) {
            exp2 = Ceil(exp2 + (e1 / 16.0 + 17.0)); TESTEXP(exp2);
            exp2 = Ceil(exp2 * 1.15); TESTEXP(exp2);    //exp2 increased 15% after 3 infomation
        }
        exp1 = exp1 - e1; TESTEXP(exp1);
    }
    else return -99;
    TESTEXP(exp1);
    TESTEXP(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    int result = 0;
    if (E2 < 0 || E2 > 99) result = -99;
    else {
        TESTEXP(EXP1); TESTHP(HP1); TESTM(M1);
        // road 01
        float P1 = 1;
        calPoss(EXP1, P1);
        // road 02
        if (E2 & 1) { // odd
            float temp = M1 / 2.0;
            while (M1 > 0 && M1 >= temp) {
                // Recover HP1
                if (HP1 < 200) {
                    HP1 = Ceil(HP1 * 1.3);
                    M1 -= 150;
                }
                else {
                    HP1 = Ceil(HP1 * 1.1);
                    M1 -= 70;
                }
                TESTHP(HP1);
                TESTM(M1);
                checkM1half(M1, temp);
                // TAXI OR HORSE
                if (EXP1 < 400) M1 -= 200;
                else M1 -= 120;
                EXP1 = Ceil(EXP1 * 1.13); TESTEXP(EXP1);
                TESTM(M1);
                checkM1half(M1, temp);
                // Homeless man
                if (EXP1 < 300) M1 -= 100;
                else M1 -= 120;
                EXP1 = Ceil(EXP1 * 0.9); TESTEXP(EXP1);
                TESTM(M1);
                checkM1half(M1, temp);
            }
        }
        else {
            do {
                TESTM(M1);
                checkM1(M1);
                // Recover HP1
                if (HP1 < 200) {
                    HP1 = Ceil(HP1 * 1.3);
                    M1 -= 150;
                }
                else {
                    HP1 = Ceil(HP1 * 1.1);
                    M1 -= 70;
                }
                TESTHP(HP1);
                TESTM(M1);
                checkM1(M1);
                // TAXI OR HORSE
                if (EXP1 < 400) M1 -= 200;
                else M1 -= 120;
                EXP1 = Ceil(EXP1 * 1.13); TESTEXP(EXP1);
                TESTM(M1);
                checkM1(M1);
                // Homeless man
                if (EXP1 < 300) M1 -= 100;
                else M1 -= 120;
                EXP1 = Ceil(EXP1 * 0.9); TESTEXP(EXP1);
                TESTM(M1);
                checkM1(M1);
            } while (0);
        }

        HP1 = Ceil(HP1 * 0.83); TESTHP(HP1);
        EXP1 = Ceil(EXP1 * 1.17); TESTEXP(EXP1);

        float P2 = 1;
        calPoss(EXP1, P2);

        // road 03
        int P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        int i = 0;
        index(E2, i);
        float P3 = P[i] / 100.0f;

        // check Possibilities
        if (P1 * P2 * P3 == 1) EXP1 = Ceil(EXP1 * 0.75);
        else {
            float Pa = (P1 + P2 + P3) / 3;
            if (Pa < 0.5) {
                HP1 = Ceil(HP1 * 0.85);
                EXP1 = Ceil(EXP1 * 1.15);
            }
            else {
                HP1 = Ceil(HP1 * 0.9);
                EXP1 = Ceil(EXP1 * 1.2);
            }
            TESTHP(HP1);
            TESTEXP(EXP1);
        }
        result = HP1 + EXP1 + M1;
    }
    return result;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    int result = 0;
    if (E3 < 0 || E3 > 99) result = -99;
    else {
        TESTEXP(EXP1); TESTEXP(EXP2);
        TESTHP(HP1); TESTHP(HP2);
        int matrix[10][10] = { {0} };
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                matrix[i][j] = (E3 * j + i * 2) * (i - j);
            }
        }

        int countMax, countMin;
        countMax = countMin = 0;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (matrix[i][j] > E3 * 2) countMax++;
                if (matrix[i][j] < -E3) countMin++;
            }
        }

        int Row = calIndex(countMax); int Col = calIndex(countMin);
        int point = matrix[Row][Col];

        for (int i = -1; i <= 1; i += 2) {
            for (int j = -1; j <= 1; j += 2) {
                int newRow = Row + i;
                int newCol = Col + j;

                while (newRow >= 0 && newRow < 10 && newCol >= 0 && newCol < 10) {
                    if (matrix[newRow][newCol] > point) {
                        point = matrix[newRow][newCol];
                    }
                    newRow += i;
                    newCol += j;
                }
            }
        }
        point = abs(point);
        if (abs(matrix[Row][Col]) > point) {
            EXP1 = Ceil(EXP1 * 0.88); TESTEXP(EXP1);
            EXP2 = Ceil(EXP2 * 0.88); TESTEXP(EXP2);
            HP1 = Ceil(HP1 * 0.9); TESTHP(HP1);
            HP2 = Ceil(HP2 * 0.9); TESTHP(HP2);
            result = matrix[Row][Col];
        }
        else {
            EXP1 = Ceil(EXP1 * 1.12); TESTEXP(EXP1);
            EXP2 = Ceil(EXP2 * 1.12); TESTEXP(EXP2);
            HP1 = Ceil(HP1 * 1.1); TESTHP(HP1);
            HP2 = Ceil(HP2 * 1.1); TESTHP(HP2);
            result = point;
        }
    }
    return result;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function

    std::string tempS = s;
    std::string tempEmail = email;
    std::string se = tempEmail.substr(0, tempEmail.find('@'));

    // Check the length of the password
    if (tempS.length() < 8) {
        return -1;
    }
    else if (tempS.length() > 20) {
        return -2;
    }

    // Check for substring 'se' in the password
    if (tempS.find(se) != std::string::npos) {
        return -(300 + tempS.find(se));
    }

    // Check for consecutive repeating characters
    for (int i = 0; i < tempS.size() - 2; i++) {
        if (tempS[i] == tempS[i + 1] && tempS[i] == tempS[i + 2]) {
            return -(400 + i);
        }
    }
    // Check for special characters
    if (tempS.find_first_of("@#%$!") == std::string::npos) return -5;
    // Check for invalid characters
    for (int i = 0; i < tempS.size(); i++) {
        char x = tempS[i];
        if (!isAlnum(x) && x != '@' && x != '#' && x != '%' && x != '$' && x != '!') {
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    int* count = new int[num_pwds];
    for (int i = 0; i < num_pwds; i++) count[i] = 1;
    for (int i = 0; i < num_pwds; i++) {
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count[i]++;
            }
        }
    }
    int maxCount = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (count[i] > maxCount) maxCount = count[i];
    }
    int maxLen = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (count[i] == maxCount && strlen(arr_pwds[i]) > maxLen) maxLen = strlen(arr_pwds[i]);
    }
    int index = 0;
    int cnt = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (count[i] == maxCount) cnt++;
    }
    if (cnt == 1) {
        for (int i = 0; i < num_pwds; i++) {
            if (count[i] == maxCount) {
                index = i;
                break;
            }
        }
    }
    else {
        for (int i = 0; i < num_pwds; i++) {
            if (count[i] == maxCount && strlen(arr_pwds[i]) == maxLen) {
                index = i;
                break;
            }
        }
    }
    delete[] count;
    return index;
}
int calIndex(int x) {
    if (x / 10 == 0) return x;
    else {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return calIndex(sum);
    }
}
int isAlnum(int c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

int Ceil(float x) {
    return (int)(x + 0.999);
}

#define index(n, i) {\
    if (n < 10) i = n;\
    else {\
        int s = n % 10 + n / 10;\
        i = s % 10;\
    }\
 }
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////