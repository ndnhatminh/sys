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

// Func to RoundUp and Set Limit
int limtSet(double num, const char* mod) {
    // Add RoundUp
    int num1 = ceil(num);
    // This is for setlimit
    if ((mod == "exp") && (num1 > 600)) {
        num1 = 600;
    }
    if ((mod == "m") && (num1 > 3000)) {
        num1 = 3000;
    }
    if ((mod == "hp") && (num1 > 666)) {
        num1 = 666;
    }
    if (num1 < 0) {
        num1 = 0;
    }
    // Return
    return num1;
}

// Func to hash strings
unsigned int hashFunction(const char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = hash * 101 + *str++;
    }
    // Return
    return hash;
}

// Func to find near square number
int square_number(int EXP1) {
    int s = sqrt(EXP1);
    if (abs(s*s - EXP1) < abs((s+1)*(s+1) - EXP1)) {
        return (s*s);
    }
    else {
        return ((s + 1)*(s + 1));
    }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    exp1 = limtSet(exp1,"exp");
    exp2 = limtSet(exp2,"exp");
    if ((e1 < 0) || (e1 > 99)) {
        return -99;
    }
    if ((e1 >= 0) && (e1 <= 3)) {
        if (e1 == 0) {
            exp2 += 29;
        }
        else if (e1 == 1) {
            exp2 += 45;
        }
        else if (e1 == 2) {
            exp2 += 75;
        }
        else if (e1 == 3) {
            exp2 += 29 + 45 + 75;
        }
        exp2 = limtSet(exp2,"exp");
        int D = (e1*3) + (exp1*7);
        if (D%2==0) {
            exp1 = limtSet((exp1 + D/200.0),"exp");
        }
        else {
            exp1 = limtSet((exp1 - D/100.0),"exp");
        }       
    }
    // Situation_II
    if ((e1>=4) && (e1<=99)) {
        // Watson
        if ((e1>=4) && (e1<=19)) {
            exp2 = limtSet((exp2 + e1/4.0 + 19),"exp");
        }
        else if ((e1>=20) && (e1<=49)) {
            exp2 = limtSet((exp2 + e1/9.0 + 21),"exp");
        }
        else if ((e1>=50) && (e1<=65)) {
            exp2 = limtSet((exp2 + e1/16.0 + 17),"exp");
        }
        else if ((e1>=66) && (e1<=79)) {
            exp2 = limtSet((exp2 + e1/4.0 + 19),"exp");
            if (exp2 > 200){
                exp2 = limtSet((exp2 + e1/9.0 + 21),"exp");
            }
        }
        else if ((e1>=80) && (e1<=99)) {
            exp2 = limtSet((exp2 + e1/4.0 + 19),"exp");
            exp2 = limtSet((exp2 + e1/9.0 + 21),"exp");
            if (exp2 > 400) {
                exp2 = limtSet((exp2 + e1/16.0 + 17),"exp");
                exp2 = limtSet((exp2 * 1.15),"exp");
            }
        }
        // Sherlock
        exp1 = limtSet((exp1 - e1),"exp");
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    HP1 = limtSet(HP1,"hp");
    EXP1 = limtSet(EXP1,"exp");
    M1 = limtSet(M1,"m");
    if ((E2 < 0) || (E2 > 99)) {
        return -99;
    }
    // Road_1
    int P1 = 0, P2 = 0, P3 = 0;
    if (EXP1 >= square_number(EXP1)) {
        P1 = 1;
    }
    else {
        P1 = (EXP1/(square_number(EXP1)) + 80) / 123.0;
    }
    // Road_2
    if (E2%2 != 0) {
        int MPay = 0;
        int Mfirst = M1/2;
        while (MPay <= Mfirst) {
            // Event 1
            if (HP1 < 200) {
                HP1 = limtSet((HP1 * 1.3),"hp");
                M1 = limtSet((M1 - 150),"m");
                MPay += 150;
            }
            else {
                HP1 = limtSet((HP1 * 1.1),"hp");
                M1 = limtSet((M1 - 70),"m");
                MPay += 70;
            }
            if (MPay > Mfirst) {
                break;
            }
            // Event 2
            if (EXP1 < 400) {
                M1 = limtSet((M1 - 200),"m");
                MPay += 200;
            } 
            else {
                M1 = limtSet((M1 - 120),"m");
                MPay += 120;
            }
            EXP1 = limtSet((EXP1 * 1.13),"exp");
            if (MPay > Mfirst) {
                break;
            }
            // Event 3
            if (EXP1 < 300) {
                M1 = limtSet((M1 - 100),"m");
                MPay += 100;
            }
            else {
                M1 = limtSet((M1 - 120),"m");
                MPay += 120;
            }
            EXP1 = limtSet((EXP1 * 0.9),"exp");
        }
        HP1 = limtSet((HP1 * 0.83),"hp");
        EXP1 = limtSet((EXP1 * 1.17),"exp");
    }
    if (E2%2 == 0) {
        int MPay = 0;
        // Event 1
        if (HP1 < 200) {
            HP1 = limtSet((HP1 * 1.3),"hp");
            M1 = limtSet((M1 - 150),"m");
            MPay += 150;
        }
        else {
            HP1 = limtSet((HP1 * 1.1),"hp");
            M1 = limtSet((M1 - 70),"m");
            MPay += 70;
        }
        if (MPay <= M1) {
            // Event 2
            if (EXP1 < 400) {
                M1 = limtSet((M1 - 200),"m");
                MPay += 200;
            } 
            else {
                M1 = limtSet((M1 - 120),"m");
                MPay += 120;
            }
            EXP1 = limtSet((EXP1 * 1.13),"exp");
            if (MPay <= M1) {
                // Event 3
                if (EXP1 < 300) {
                    M1 = limtSet((M1 - 100),"m");
                } 
                else {
                    M1 = limtSet((M1 - 120),"m");
                }
                EXP1 = limtSet((EXP1 * 0.9),"exp");
            }
        }
        HP1 = limtSet((HP1 * 0.83),"hp");
        EXP1 = limtSet((EXP1 * 1.17),"exp");
    }
    if (EXP1 >= square_number(EXP1)) {
        P2 = 1;
    }
    else {
        P2 = (EXP1/(square_number(EXP1)) + 80) / 123.0;
    }
    // Michi_3
    int P[]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = 0;
    if (E2 < 10) {
        i = E2;
        P3 = P[i];
    }
    if (E2 >= 10) {
        int x = E2/10;
        int y = E2%10;
        i = (x + y);
        if (i < 10) {
            P3 = P[i];
        }
        else {
            int i = i%10;
            P3 = P[i];
        }
    }
    // P = P1+P2+P3
    int P_sum = 0;
    if ((P1 == 1) && (P2 == 1) && (P3 == 1)) {
        EXP1 = limtSet((EXP1 * 0.75),"exp");
    }
    else {
        P_sum = P1 + P2 + P3/100.0;
    }
    if (P_sum < 0.5) {
        HP1 = limtSet((HP1 * 0.85),"hp");
        EXP1 = limtSet((EXP1 * 1.15),"exp");
    }
    else if (P_sum >= 0.5) {
        HP1 = limtSet((HP1 * 0.9),"hp");
        EXP1 = limtSet((EXP1 * 1.2),"exp");
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    HP1 = limtSet(HP1,"hp");
    EXP1 = limtSet(EXP1,"exp");
    HP2 = limtSet(HP2,"hp");
    EXP2 = limtSet(EXP2,"exp");
    if ((E3 < 0) || (E3 > 99)) {
        return -99;
    }
    int array[10][10];
    int num1 = 0, num2 = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            array[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (array[i][j] > E3*2) {
                num1++;
            }
            if (array[i][j] < -E3) {
                num2++;
            }
        }
    }
    while (num1 >= 10) {
        int x = num1/10;
        int y = num1%10;
        num1 = x+y;
    }
    while (num2 >= 10) {
        int x = num2/10;
        int y = num2%10;
        num2 = x+y;
    }
    int taxiPoint = array[num1][num2];
    int maxLeft = 0, maxRight = 0;
    for (int i = num1 - fmin(num1, num2), j = num2 - fmin(num1, num2); ((i < 10) && (j < 10)); i++, j++) {
        int Left = array[i][j];
        maxLeft = fmax(maxLeft, Left);
    }
    for (int i = num1 - fmin(num1, 10 - num2), j = num2 + fmin(num1, 10 - num2); ((i < 10) && (j >= 0) && (j < 10)); i++, j--) {
        int Right = array[i][j];
        maxRight = fmax(maxRight, Right);
    }
    int maxPoint = fmax(maxLeft, maxRight);
    if (abs(taxiPoint) <= maxPoint) {
        HP1 = limtSet((HP1 * 1.1),"hp");
        EXP1 = limtSet((EXP1 * 1.12),"exp");
        HP2 = limtSet((HP2 * 1.1),"hp");
        EXP2 = limtSet((EXP2 * 1.12),"exp");
        return maxPoint;
    }
    else {
        HP1 = limtSet((HP1 * 0.9),"hp");
        EXP1 = limtSet((EXP1 * 0.88),"exp");
        HP2 = limtSet((HP2 * 0.9),"hp");
        EXP2 = limtSet((EXP2 * 0.88),"exp");
        return taxiPoint;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int len = strlen(s);
    if (len < 8) {
        return -1;
    }
    else if (len > 20) {
        return -2;
    }
    const char *atPos = strchr(email, '@');
    if (atPos != nullptr) {
        int length = atPos - email;
        char se[length+1];
        strncpy(se,email,length);
        se[length] = '\0';
        const char* pos = strstr(s, se);
        if (pos != nullptr) {
            return -(300 + int(pos - s));
        }
    }
    for (int i = 0; i < len - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
            return -(400 + i);
    }
    bool hasSpecialChar = false;
    const char *specialChars = "@#%$!";
    for (int i = 0; i < len; ++i) {
        if (strchr(specialChars, s[i]) != nullptr) {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar)
        return -5;
    for (int i = 0; i < len; ++i) {
        char c = s[i];
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || strchr(specialChars, c) != nullptr))
            return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    const int MAX_BUCKETS = 1000;
    int counts[MAX_BUCKETS] = {0};
    int *hash_values = new int[num_pwds];
    for (int i = 0; i < num_pwds; ++i) {
        int hash = hashFunction(arr_pwds[i]) % MAX_BUCKETS;
        hash_values[i] = hash;
        counts[hash]++;
    }
    int max_count = 0;
    int max_length = strlen(arr_pwds[0]);
    int max_index = 0;
    for (int i = 0; i < num_pwds; ++i) {
        int hash = hash_values[i];
        if (counts[hash] > max_count) {
            max_count = counts[hash];
            max_length = strlen(arr_pwds[i]);
            max_index = i;
        }
        if (counts[hash] == max_count) {
            int len = strlen(arr_pwds[i]);
            if (len > max_length) {
                max_length = len;
                max_index = i;
            }
        }
    }
    delete[] hash_values;
    return max_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////