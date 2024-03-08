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

int checkValue(int n, int startPoint, int endPoint) {
    if (n < startPoint) n = startPoint;
    if (n > endPoint) n = endPoint;
    return n;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    exp1 = checkValue(exp1, 0, 600);
    exp2 = checkValue(exp2, 0, 600);
    if (e1 < 0 || e1 > 99) return -99;
    //case1
    if (e1 == 0) exp2 += 29;
    if (e1 == 1) exp2 += 45;
    if (e1 == 2) exp2 += 75;
    if (e1 == 3) exp2 += 149;
    exp2 = checkValue(exp2, 0, 600);
    if (e1 >= 0 && e1 <= 3) {
        int numD = e1 * 3 + exp1 * 7;
        if (numD % 2 == 0) exp1 = ceil((float)(exp1) + (float)(numD * 1.0 / 200.0));
        else exp1 = ceil((float)(exp1) - (float)(numD * 1.0 / 100.0));
        exp1 = checkValue(exp1, 0, 600);
    }
    //case2
    if (e1 >= 4 && e1 <= 19) exp2 += (ceil((float)(e1 / 4.0 * 1.0)) + 19);
    if (e1 >= 20 && e1 <= 49) exp2 += (ceil((float)(e1 / 9.0 * 1.0)) + 21);
    if (e1 >= 50 && e1 <= 65) exp2 += (ceil((float)(e1 / 16.0 * 1.0)) + 17);
    if (e1 >= 66 && e1 <= 79) {
        exp2 += (ceil((float)(e1 / 4.0 * 1.0)) + 19);
        exp2 = checkValue(exp2, 0, 600);
        if (exp2 > 200) exp2 += (ceil((float)(e1 / 9.0 * 1.0)) + 21);
    }
    if (e1 >= 80 && e1 <= 99) {
        exp2 += (ceil((float)(e1 / 4.0 * 1.0)) + 19);
        exp2 = checkValue(exp2, 0, 600);
        exp2 += (ceil((float)(e1 / 9.0 * 1.0)) + 21);
        exp2 = checkValue(exp2, 0, 600);
        if (exp2 > 400) {
            exp2 += (ceil((float)(e1 / 16.0 * 1.0)) + 17);
            exp2 = checkValue(exp2, 0, 600);
            exp2 += (ceil((float)(exp2 * 15.0 / 100.0)));
        }
    }
    exp2 = checkValue(exp2, 0, 600);
    if (e1 >= 4 && e1 <= 99) {
        exp1 -= e1;
        exp1 = checkValue(exp1, 0, 600);
    }
    return exp1 + exp2;
}

//Task2
int nearestPerfectSquare(int value) {
    int sqrtValue = sqrt(value);
    int num1 = value - sqrtValue * sqrtValue;
    int num2 = (sqrtValue + 1) * (sqrtValue + 1) - value;
    if (num1 < num2) return sqrtValue * sqrtValue;
    else return (sqrtValue + 1) * (sqrtValue + 1);
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    HP1 = checkValue(HP1, 0, 666);
    EXP1 = checkValue(EXP1, 0, 600);
    M1 = checkValue(M1, 0, 3000);
    if (E2 < 0 || E2 > 99) return -99;
    //find p1
    int numS_p1 = nearestPerfectSquare(EXP1);
    float p1, p2, p3;
    if (EXP1 >= numS_p1) p1 = 1.0;
    else p1 = ((float)(EXP1 / numS_p1 * 1.0) + 80.0) / 123.0;
    //find p2
    float M1_limit = (float)(M1 / 2.0);
    int M1_paid = 0;
    if (E2 % 2 != 0) {
        while ((float)(M1_paid) <= M1_limit){ 
            //event1
            if (HP1 < 200) {
                HP1 += ceil(HP1 * 30.0 / 100.0);
                HP1 = checkValue(HP1, 0, 666);
                M1 -= 150;
                M1 = checkValue(M1, 0, 3000);
                M1_paid += 150;
            }
            else {
                HP1 += ceil(HP1 * 10.0 / 100.0);
                HP1 = checkValue(HP1, 0, 666);
                M1 -= 70;
                M1 = checkValue(M1, 0, 3000);
                M1_paid += 70;
            }
            if ((float)(M1_paid) > M1_limit) break;
            //event2
            if (EXP1 < 400) {
                M1 -= 200;
                M1 = checkValue(M1, 0, 3000);
                M1_paid += 200;
                EXP1 += ceil(EXP1 * 13.0 / 100.0);
                EXP1 = checkValue(EXP1, 0, 600);
            }
            else {
                M1 -= 120;
                M1 = checkValue(M1, 0, 3000);
                M1_paid += 120;
                EXP1 += ceil(EXP1 * 13.0 / 100.0);
                EXP1 = checkValue(EXP1, 0, 600);
            }
            if ((float)(M1_paid) > M1_limit) break;
            //event3
            if (EXP1 < 300) {
                M1 -= 100;
                M1 = checkValue(M1, 0, 3000);
                M1_paid += 100;
                EXP1 = ceil(EXP1 * 90.0 / 100);
                EXP1 = checkValue(EXP1, 0, 600);
            }
            else {
                M1 -= 120;
                M1 = checkValue(M1, 0, 3000);
                M1_paid += 120;
                EXP1 = ceil(EXP1 * 90.0 / 100);
                EXP1 = checkValue(EXP1, 0, 600);
            }
            if ((float)(M1_paid) > M1_limit) break;
        }
    }
    else {
        for (int i = 0; i < 1; i++) {
            //event1
            if (HP1 < 200) {
                HP1 += ceil(HP1 * 30.0 / 100.0);
                HP1 = checkValue(HP1, 0, 666);
                M1 -= 150;
                M1 = checkValue(M1, 0, 3000);
            }
            else {
                HP1 += ceil(HP1 * 10.0 / 100.0);
                HP1 = checkValue(HP1, 0, 666);
                M1 -= 70;
                M1 = checkValue(M1, 0, 3000);
            }
            if (M1 == 0) break;
            //event2
            if (EXP1 < 400) {
                M1 -= 200;
                M1 = checkValue(M1, 0, 3000);
                EXP1 += ceil(EXP1 * 13.0 / 100.0);
                EXP1 = checkValue(EXP1, 0, 600);
            }
            else {
                M1 -= 120;
                M1 = checkValue(M1, 0, 3000);
                EXP1 += ceil(EXP1 * 13.0 / 100.0);
                EXP1 = checkValue(EXP1, 0, 600);
            }
            if (M1 == 0) break;
            //event3
            if (EXP1 < 300) {
                M1 -= 100;
                M1 = checkValue(M1, 0, 3000);
                EXP1 = ceil(EXP1 * 90.0 / 100);
                EXP1 = checkValue(EXP1, 0, 600);
            }
            else {
                M1 -= 120;
                M1 = checkValue(M1, 0, 3000);
                EXP1 = ceil(EXP1 * 90.0 / 100);
                EXP1 = checkValue(EXP1, 0, 600);
            }
            if (M1 == 0) break;
        }
    }
    HP1 = ceil(HP1 * 83.0 / 100.0);
    HP1 = checkValue(HP1, 0, 666);
    EXP1 = ceil(EXP1 * 117.0 / 100.0);
    EXP1 = checkValue(EXP1, 0, 600);
    int numS_p2 = nearestPerfectSquare(EXP1);
    if (EXP1 >= numS_p2) p2 = 1.0;
    else p2 = ((float)(EXP1 / numS_p2 * 1.0) + 80.0) / 123.0;
    //find p3
    float P[10] = { 32,47,28,79,100,50,22,83,64,11 };
    int i;
    if (E2 >= 0 && E2 <= 9) {
        i = E2;
        p3 = (float)(P[i] / 100.0);
    }
    if (E2 >= 10 && E2 <= 99) {
        int sum = (E2 / 10) + (E2 % 10);
        i = sum % 10;
        p3 = (float)(P[i] / 100.0);
    }
    //result
    if (p1 == 1.0 && p2 == 1.0 && p3 == 1.0) {
        EXP1 = ceil(EXP1 * 75.0 / 100.0);
        EXP1 = checkValue(EXP1, 0, 600);
        return traceLuggage(HP1, EXP1, M1, E2);
    }
    float p_average = (p1 + p2 + p3) / 3.0;
    if (p_average < 0.5) {
        HP1 = ceil(HP1 * 85.0 / 100.0);
        HP1 = checkValue(HP1, 0, 666);
        EXP1 = ceil(EXP1 * 115.0 / 100.0);
        EXP1 = checkValue(EXP1, 0, 600);
    }
    else {
        HP1 = ceil(HP1 * 90.0 / 100.0);
        HP1 = checkValue(HP1, 0, 666);
        EXP1 = ceil(EXP1 * 120.0 / 100.0);
        EXP1 = checkValue(EXP1, 0, 600);
    }
    return HP1 + EXP1 + M1;
}

//Task3
int SeparateNum(int num) {
    int result = 0;
    while (num > 0) {
        result += num % 10;
        num /= 10;
    }
    return result;
}

int point(int row, int col, int arr[10][10]) {
    int max = arr[row][col];
    for (int i = 0; i < 10; i++) {
        int leftRow = i;
        int leftCol = col + i - row;
        if (leftRow < 10 && leftCol < 10) {
            if (arr[leftRow][leftCol] > max) {
                max = arr[leftRow][leftCol];
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        int rightRow = row - i + col;
        int rightCol = i;
        if (rightRow < 10 && rightCol < 10) {
            if (arr[rightRow][rightCol] > max) {
                max = arr[rightRow][rightCol];
            }
        }
    }
    return max;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    HP1 = checkValue(HP1, 0, 666);
    EXP1 = checkValue(EXP1, 0, 600);
    HP2 = checkValue(HP2, 0, 666);
    EXP2 = checkValue(EXP2, 0, 600);
    if (E3 < 0 || E3 > 99) return -99;
    int arr[10][10];
    int higher = 0, lower = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == j) arr[i][j] = 0;
            else arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] > (E3 * 2) && arr[i][j] > 0) higher++;
            else if (arr[i][j] < -E3 && arr[i][j] < 0) lower++;
        }
    }
    int row = SeparateNum(SeparateNum(higher));
    int col = SeparateNum(SeparateNum(lower));
    int curPos = arr[row][col];
    int curPoint = point(row, col, arr);
    if (abs(curPos) > curPoint)
    {
        EXP1 = ceil(EXP1 * 88.0 / 100.0);
        HP1 = ceil(HP1 * 90.0 / 100.0);
        EXP2 = ceil(EXP2 * 88.0 / 100.0);
        HP2 = ceil(HP2 * 90.0 / 100.0);
        EXP1 = checkValue(EXP1, 0, 600);
        HP1 = checkValue(HP1, 0, 666);
        EXP2 = checkValue(EXP2, 0, 600);
        HP2 = checkValue(HP2, 0, 666);
        return curPos;
    }
    else
    {
        EXP1 = ceil(EXP1 * 112.0 / 100.0);
        HP1 = ceil(HP1 * 110.0 / 100.0);
        EXP2 = ceil(EXP2 * 112.0 / 100.0);
        HP2 = ceil(HP2 * 110.0 / 100.0);
        EXP1 = checkValue(EXP1, 0, 600);
        HP1 = checkValue(HP1, 0, 666);
        EXP2 = checkValue(EXP2, 0, 600);
        HP2 = checkValue(HP2, 0, 666);
        return curPoint;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    if (strlen(s) < 8) {
        return -1;
    }
    if (strlen(s) > 20) {
        return -2;
    }
    char se[101];
    const char* at_position = strchr(email, '@');
    strncpy(se, email, at_position - email);
    se[at_position - email] = '\0';
    const char* result = strstr(s, se);
    if (result != nullptr) {
        return -(300 + (result - s));
    }
    for (int i = 0; i < strlen(s) - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }
    bool has_special = false;
    for (int i = 0; i < strlen(s); i++) {
        if (strchr("!@#$%", s[i]) != nullptr) {
            has_special = true;
            break;
        }
    }
    if (!has_special) {
        return -5;
    }
    for (int i = 0; i < strlen(s); ++i) {
        if ((s[i] >= '0' && s[i] <= '9') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'A' && s[i] <= 'Z') ||
            strchr("!@#$%", s[i]) != nullptr);
        else return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    char pwd[30][20];
    int count_pwd[30];
    int unique_Count = 0;
    for (int i = 0; i < num_pwds; i++) {
        bool found = false;
        for (int j = 0; j < unique_Count; j++) {
            if (strcmp(arr_pwds[i], pwd[j]) == 0) {
                count_pwd[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            strcpy(pwd[unique_Count], arr_pwds[i]);
            count_pwd[unique_Count]++;
            unique_Count++;
        }
    }
    int mostFre = 0;
    for (int i = 0; i <= unique_Count; i++) {
        if (count_pwd[i] > mostFre) mostFre = count_pwd[i];
    }
    //cout << "mostFre = " << mostFre << endl;
    int max_length = 0;
    char result_pwd[20];
    for (int i = 0; i <= unique_Count; i++) {
        if (count_pwd[i] == mostFre) {
            if (strlen(pwd[i]) > max_length) {
                max_length = strlen(pwd[i]);
                strcpy(result_pwd, pwd[i]);
            }
        }
    }
    //cout << "max_length = " << max_length << endl;
    //cout << "result_pwd = " << result_pwd << endl;
    for (int a = 0; a < num_pwds; a++){
        if (strcmp(result_pwd, arr_pwds[a]) == 0) return a;
    }
    //return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////