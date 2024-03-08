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

void preprocessHp(int& hp) {
    if (hp > 666) hp = 666;
    if (hp < 0) hp = 0;
}

void preprocessExp(int& exp) {
    if (exp > 600) exp = 600;
    if (exp < 0) exp = 0;
}

void preprocessM(int& m) {
    if (m > 3000) m = 3000;
    if (m < 0) m = 0;
}

bool squareNum(int num) {
    if (num <= 0) return false;
    int sqr = sqrt(num);
    if (sqr * sqr == num) return true;
    return false;
}

int findSquare(int num) {
    if (squareNum(num)) return num;
    int i = num - 1;
    int j = num + 1;
    while ((i > 0) && (!squareNum(i))) i -= 1;
    while (!squareNum(j)) j += 1;
    if (abs(num - i) < abs(num - j)) {
        return i;
    }
    return j;
}

float proRoad1(int EXP1) {
    int s = findSquare(EXP1);
    // cout << "S = " << s << endl;
    if (EXP1 >= s) return 100; 
        else return (float(EXP1)/s + 80) / 1.23;
}

void doAction1(int& EXP1, int& HP1, int& M1) {
    if (M1 > 0) {
        if (HP1 < 200) {
            M1 -= 150;
            preprocessM(M1);
            HP1 = ceil(HP1 * 1.3);
            preprocessHp(HP1);
        } else {
            M1 -= 70;
            preprocessM(M1);
            HP1 = ceil(HP1 * 1.1);
            preprocessHp(HP1);
        }
        // cout << "action 1 " << endl;
        // cout << "EXP1:" << EXP1 << " HP1:" << HP1 << " M1:" << M1 << endl;
    }
    return;
}

void doAction2(int& EXP1, int& HP1, int& M1) {
    if (M1 > 0) {
        if (EXP1 < 400) {
            M1 -= 200;
            preprocessM(M1);
        } else {
            M1 -= 120;
            preprocessM(M1);
        }
        EXP1 = ceil(EXP1*1.13);
        preprocessExp(EXP1);
        // cout << "action 2 " << endl;
        // cout << "EXP1:" << EXP1 << " HP1:" << HP1 << " M1:" << M1 << endl;
    }
    return;
} 

void doAction3(int& EXP1, int& HP1, int& M1) {
    if (M1 > 0) {
        if (EXP1 < 300) {
            M1 -= 100;
            preprocessM(M1);
        } else {
            M1 -= 120;
            preprocessM(M1);
        }
        EXP1 = ceil(EXP1*0.9);
        preprocessExp(EXP1);
        // cout << "action 3 " << endl;
        // cout << "EXP1:" << EXP1 << " HP1:" << HP1 << " M1:" << M1 << endl;
    }   
    return; 
}

int sumDigits(int num) {
    int sum = num;
    while (sum >= 10) {
        sum = sum / 10 + sum % 10;
    }
    return sum;
}

int maxDiagonal(int taxi[10][10], int i, int j) {
    int result = taxi[i][j];
    // left diagonal
    int x, y;
    x = i;
    y = j;
    while ((x > 0) && (y > 0)) {
        x -= 1;
        y -= 1;
        // cout << taxi[x][y] << " ";
        if (taxi[x][y] > result) result = taxi[x][y];
    }
    // cout << endl;
    x = i;
    y = j;
    while ((x < 9) && (y < 9)) {
        x += 1;
        y += 1;
        // cout << taxi[x][y] << " ";
        if (taxi[x][y] > result) result = taxi[x][y];
    }
    // cout << endl;
    // right diagonal 
    x = i;
    y = j;
    while ((x < 9) && (y > 0)) {
        x += 1;
        y -= 1;
        // cout << taxi[x][y] << " ";
        if (taxi[x][y] > result) result = taxi[x][y];
    }
    // cout << endl;
    x = i;
    y = j;
    while ((x > 0) && (y < 9)) {
        x -= 1;
        y += 1;
        // cout << taxi[x][y] << " ";
        if (taxi[x][y] > result) result = taxi[x][y];
    }
    // cout << endl;
    return result;
}

bool isCharInString(const char* str, char c) {
    return strchr(str, c) != nullptr;
}

int findSubstring(const char* s, char* se) {
    for (int i = 0; i <= strlen(s) - strlen(se); i++) {
        int j;
        for (j = 0; j < strlen(se); j++) {
            if (s[i + j] != se[j]) {
                break;
            }
        }
        if (j == strlen(se)) return i;
    }
    return -1;
}

int findSpecialChars(const char* str) {
    for (int i = 0; i < strlen(str); i++) 
        if (!((str[i] >= '0' && str[i] <= '9') ||
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z') ||
            str[i] == '@' || str[i] == '#' ||
            str[i] == '$' || str[i] == '%' || str[i] == '!')) return i;
    return -1; 
}

bool specialChar(char c) {
    if (!((c >= '0' && c <= '9') ||
        (c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        c == '@' || c == '#' ||
        c == '$' || c == '%' || c == '!')) return true;
    return false;
}

char* extractUsername(const char* email) {
    int i = 0;
    char* se = new char[99];
    while (email[i] != '@' && i < 100) {
        se[i] = email[i];
        i++;
    }
    se[i] = '\0';
    return se;
}

int findRepeatingChars(const char* str) {
    for (int i = 0; i < strlen(str) - 2; i++) 
        if (str[i] == str[i + 1] && str[i] == str[i + 2]) return i;
    return -1;
}

bool isPasswordExist(char* result[], int size, const char* str) {
    for (int i = 0; i < size; i++) {
        if (strcmp(str, result[i]) == 0) {
            return true;
        }
    }
    return false;
}

char** getUniquePasswords(const char* arr_pwds[], int num_pwds, int& uniqueCount) {
    char** result = new char*[num_pwds];
    uniqueCount = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (!isPasswordExist(result, uniqueCount, arr_pwds[i])) {
            result[uniqueCount] = new char[strlen(arr_pwds[i]) + 1];
            strcpy(result[uniqueCount], arr_pwds[i]);
            uniqueCount++;
        }
    }
    return result;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    // check
    if ((e1 < 0) || (e1 > 99)) return -99;
    // preprocessing
    preprocessExp(exp1);
    preprocessExp(exp2);
    // case 1
    if ((e1 >= 0) && (e1 <= 3)) {
        if (e1 == 0) {
            exp2 += 29;
            preprocessExp(exp2);
        }
        if (e1 == 1) {
            exp2 += 45;
            preprocessExp(exp2);
        }
        if (e1 == 2) {
            exp2 += 75;
            preprocessExp(exp2);
        }
        if (e1 == 3) {
            exp2 += 29 + 45 + 75;
            //preprocessExp(exp2);
        }
        int d = e1 * 3 + exp1 * 7;
        // cout << d << endl;
        if (d % 2 == 0) {
            exp1 = ceil(exp1 + float(d) / 200);
            preprocessExp(exp1);
        } else {
            exp1 = ceil(exp1 - float(d) / 100);
            preprocessExp(exp1);
        }
    }
    
    //case 2
    if ((e1 >= 4) && (e1 <= 99)) {
        if ((e1 >= 4) && (e1 <= 19)) {
            exp2 = ceil(exp2 + float(e1) / 4 + 19);
            preprocessExp(exp2);
        }
        if ((e1 >= 20) && (e1 <= 49)) {
            exp2 = ceil(exp2 + float(e1) / 9 + 21);
            preprocessExp(exp2);
        }
        if ((e1 >= 50) && (e1 <= 65)) {
            exp2 = ceil(exp2 + float(e1) / 16 + 17);
            preprocessExp(exp2);
        }
        if ((e1 >= 66) && (e1 <= 79)) {
            exp2 = ceil(exp2 + float(e1) / 4 + 19);
            preprocessExp(exp2);
            if (exp2 > 200) {
                exp2 = ceil(exp2 + float(e1) / 9 + 21);
                preprocessExp(exp2);
            }
        }
        if ((e1 >= 80) && (e1 <= 99)) {
            exp2 = ceil(exp2 + float(e1) / 4 + 19);
            preprocessExp(exp2);
            exp2 = ceil(exp2 + float(e1) / 9 + 21);
            preprocessExp(exp2);
            if (exp2 > 400) {
                exp2 = ceil(exp2 + float(e1) / 16 + 17);
                preprocessExp(exp2);
                exp2 = ceil(exp2 * 1.15);
                preprocessExp(exp2);
            }
        }
        exp1 -= e1;
        preprocessExp(exp1);
    }
    
    // cout << exp1 << endl;
    // cout << exp2 << endl;

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if ((E2 < 0) || (E2 > 99)) return -99;
    preprocessExp(EXP1);
    preprocessHp(HP1);
    preprocessM(M1);

    // Road 1
    float p1;
    p1 = proRoad1(EXP1);
    
    // Road 2
    int money = M1;
    if (E2 % 2 == 1) {
        while ((M1 > 0) && (money - M1 <= 0.5 * money)) {
            doAction1(EXP1, HP1, M1);
            if (money - M1 < 0.5 * money) doAction2(EXP1, HP1, M1);
            if (money - M1 < 0.5 * money) doAction3(EXP1, HP1, M1);
        } 
    } else {
        doAction1(EXP1, HP1, M1);
        doAction2(EXP1, HP1, M1);
        doAction3(EXP1, HP1, M1);
    }
    HP1 = ceil(HP1 * 0.83);
    preprocessHp(HP1);
    EXP1 = ceil(EXP1 * 1.17);
    preprocessExp(EXP1);
    // cout << EXP1 << " " << HP1 << " " << M1 << endl;
    float p2;
    p2 = proRoad1(EXP1);
    
    // Road 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int e = E2;
    float p3;
    if (e <= 9) p3 = P[e]; 
    else {
        e = e / 10 + e % 10;
        if (e >= 10) e = e % 10;
        p3 = P[e];
    }
    if ((p1 != 100) || (p2 != 100) || (p3 != 100)) {
        float pmean = (p1 + p2 + p3) / 3;
        if (pmean < 50) {
            HP1 = ceil(HP1 * 0.85);
            preprocessHp(HP1);
            EXP1 = ceil(EXP1 * 1.15);
            preprocessExp(EXP1);
        } else {
            HP1 = ceil(HP1 * 0.9);
            preprocessHp(HP1);
            EXP1 = ceil(EXP1 * 1.2);
            preprocessExp(EXP1);
        }
    } else {
        EXP1 = ceil(EXP1 * 0.75);
        preprocessExp(EXP1);
    }
    // cout << p1 << " " << p2 << " " << p3 << endl;

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ((E3 < 0) || (E3 > 99)) return -99;
    preprocessExp(EXP1);
    preprocessExp(EXP2);
    preprocessHp(HP1);
    preprocessHp(HP2);

    int taxi[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) 
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
    }

    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 10; j++) cout << taxi[i][j] << " ";
    //     cout << endl;
    // }

    int x = 0, y = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (taxi[i][j] > 2 * E3)  x += 1;
            if (taxi[i][j] < -E3)  y += 1;
        }
    }
    // cout << "x = " << x << "  y = " << y << endl;
    x = sumDigits(x);
    y = sumDigits(y);
    // cout << "x = " << x << "  y = " << y << endl;

    int sher = abs(maxDiagonal(taxi, x, y));
    // cout << "Taxi: " << taxi[x][y] << "  SHER: " << sher << endl;
    bool flag = false;
    if (abs(taxi[x][y]) > sher) {
        EXP1 = ceil(EXP1 * 0.88);
        preprocessExp(EXP1);
        EXP2 = ceil(EXP2 * 0.88);
        preprocessExp(EXP2);
        HP1 = ceil(HP1 * 0.9);
        preprocessHp(HP1);
        HP2 = ceil(HP2 * 0.9);
        preprocessHp(HP2);
    } else {
        EXP1 = ceil(EXP1 * 1.12);
        preprocessExp(EXP1);
        EXP2 = ceil(EXP2 * 1.12);
        preprocessExp(EXP2);
        HP1 = ceil(HP1 * 1.1);
        preprocessHp(HP1);
        HP2 = ceil(HP2 * 1.1);
        preprocessHp(HP2);
        flag = true;
    }
    if (flag == true) return sher;
        else return taxi[x][y];
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    if (strlen(s) < 8) return -1;
    if (strlen(s) > 20) return -2;

    char* se = new char[99];
    se = extractUsername(email);
    
    if (findSubstring(s, se) != -1) return -(300 + findSubstring(s, se));
    
    if (findRepeatingChars(s) != -1) return -(400 + findRepeatingChars(s));
    
    if (!isCharInString(s, '@') && !isCharInString(s, '#') && !isCharInString(s, '%') && !isCharInString(s, '$') && !isCharInString(s, '!')) return -5;
    
    if (findSpecialChars(s) != -1) return findSpecialChars(s);
    return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int count = 0;
    char** unique_pwds = new char*[num_pwds];
    unique_pwds = getUniquePasswords(arr_pwds, num_pwds, count);
    int fre[count];
    // count frequency of existing of each password
    for (int i = 0; i < count; i++) {
        fre[i] = 0;
        for (int j = 0; j < num_pwds; j++) 
            if (strcmp(unique_pwds[i], arr_pwds[j]) == 0) fre[i]++;
    }
    // sort following the frequency of passwords
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (fre[i] < fre[j]) {
                int temp = fre[i];
                fre[i] = fre[j];
                fre[j] = temp;
                char* s = unique_pwds[i];
                unique_pwds[i] = unique_pwds[j];
                unique_pwds[j] = s;
            }
        }
    }

    // for (int i = 0; i < count; i++) {
    //     cout << unique_pwds[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < count; i++) cout << fre[i] << " ";
    // cout << endl;
    

    int run = 1;
    while ((fre[run] == fre[run - 1]) && (run < count)) {
        run++;
    }
    // sum of frequencies and length of strings
    for (int i = 0; i < run; i++) {
        fre[i] += strlen(unique_pwds[i]);
    } 

    // for (int i = 0; i < count; i++) cout << fre[i] << " ";
    // cout << endl;

    // find max values in array
    int max_value = fre[0];
    int save_index = 0;
    for (int i = 0; i < run; i++) 
        if (max_value < fre[i]) {
            max_value = fre[i];
            save_index = i;
        }
    char* correct_password = unique_pwds[save_index];
    for (int i = 0; i < num_pwds; i++) 
        if (strcmp(correct_password, arr_pwds[i]) == 0) return i;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
