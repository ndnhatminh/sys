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
    // DO NOT MODIFY THIS FUNCTION
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

// Global helping functions
void validateHP(int& hp) {
    if (hp < 0) hp = 0;
    if (hp > 666) hp = 666;
}
void validateEXP(int& exp) {
    if (exp < 0) exp = 0;
    if (exp > 600) exp = 600;
}
void validateM(int& m) {
    if (m < 0) m = 0;
    if (m > 3000) m = 3000;
}
// End global helping functions

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1<0 || 99<e1) return -99;

    switch(e1) {
        // Mission 1 case 1 (4.1.1)
        case 0:
            exp2 += 29;
            validateEXP(exp2);
            mission1case1(exp1, e1);
            break;

        case 1:
            exp2 += 45;
            validateEXP(exp2);
            mission1case1(exp1, e1);
            break;

        case 2:
            exp2 += 75;
            validateEXP(exp2);
            mission1case1(exp1, e1);
            break;

        case 3:
            exp2 += 29 + 45 + 75;
            validateEXP(exp2);
            mission1case1(exp1, e1);
            break;
        // End mission 1 case 1 (4.1.1)

        // Mission 1 case 2 (4.1.2)
        default:
            if (e1 <= 19) {
                exp2 = ceil(exp2 + e1/4.0+19);
                validateEXP(exp2);
            }
            else if (e1 <= 49) {
                exp2 = ceil(exp2 + e1/9.0+21);
                validateEXP(exp2);
            }
            else if (e1 <= 65) {
                exp2 = ceil(exp2 + e1/16.0+17);
                validateEXP(exp2);
            }
            else if (e1 <= 79) {
                exp2 = ceil(exp2 + e1/4.0+19);
                validateEXP(exp2);
                if (exp2 > 200) {
                    exp2 = ceil(exp2 + e1/9.0+21);
                    validateEXP(exp2);
                }
            }
            else {
                exp2 = ceil(exp2 + e1/4.0+19);
                validateEXP(exp2);

                exp2 = ceil(exp2 + e1/9.0+21);
                validateEXP(exp2);

                if (exp2 > 400) {
                    exp2 = ceil(exp2 + e1/16.0+17);
                    validateEXP(exp2);

                    exp2 = ceil(exp2*1.15);
                    validateEXP(exp2);
                }
            }
            exp1 -= e1;
            validateEXP(exp1);
        // End mission 1 case 2 (4.1.2)
    }
    return exp1 + exp2;
}
// Helping functions
void mission1case1(int & exp1, int e1) {
    int d = e1*3 + exp1*7;

    if (d%2 == 0) {
        exp1 = ceil(exp1 + d/200.0);
        validateEXP(exp1);
    }
    else {
        exp1 -= d/100;
        validateEXP(exp1);
    }
}
// End Task 1

// Task 2
int paid_money = 0;

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2<0 || 99<E2) return -99;

    // Mission 2 road 1 (4.2.1)
    int s = nearestPerfectSquare(EXP1);
    float p1 = 0;

    if (EXP1 >= s) p1 = 1;
    else p1 = ((float)EXP1/s + 80) / 123;
    // End mission 2 road 1 (4.2.1)

    // Mission 2 road 2 (4.2.2)
    if (E2%2 != 0) {
        int started_money = M1;
        
        while (paid_money <= started_money/2) {
            foodAndBeverage(HP1, M1);
            if (paid_money > started_money/2) break;

            rentATaxiOrCarriage(EXP1, M1);
            if (paid_money > started_money/2) break;
            
            homeless(EXP1, M1);
        }
        HP1 = ceil(HP1*0.83);
        EXP1 = ceil(EXP1*1.17);
        validateEXP(EXP1);
    }
    else {
        if (M1 > 0) foodAndBeverage(HP1, M1);
        if (M1 > 0) rentATaxiOrCarriage(EXP1, M1);
        if (M1 > 0) homeless(EXP1, M1);
        
        HP1 = ceil(HP1*0.83);
        EXP1 = ceil(EXP1*1.17);
        validateEXP(EXP1);
    }

    s = nearestPerfectSquare(EXP1);
    float p2 = 0;

    if (EXP1 >= s) p2 = 1;
    else p2 = ((float)EXP1/s + 80) / 123;
    // End mission 2 road 2 (4.2.2)

    // Mission 2 road 3 (4.2.3)
    int p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float p3 = 0;

    if (E2 < 10) p3 = p[E2] / 100.0;
    else {
        int index = findIndex(E2);
        p3 = p[index] / 100.0;
    }
    // End mission 2 road 3 (4.2.3)

    if (p1==1 && p2==1 && p3==1) EXP1 = ceil(EXP1*0.75);
    else {
        float pAverage = (p1+p2+p3) / 3.0;

        if (pAverage < 0.5) {
            HP1 = ceil(HP1*0.85);
            EXP1 = ceil(EXP1*1.15);
            validateEXP(EXP1);
        }
        else {
            HP1 = ceil(HP1*0.9);
            EXP1 = ceil(EXP1*1.2);
            validateEXP(EXP1);
        }
    }
    
    return HP1 + EXP1 + M1;
}
// Helping functions
int nearestPerfectSquare(int exp1) {
    int s_smaller = floor(sqrt(exp1)) * floor(sqrt(exp1)),
    s_greater = ceil(sqrt(exp1)) * ceil(sqrt(exp1));

    if ((exp1-s_smaller) < (s_greater-exp1)) return s_smaller;
    else return s_greater;
}
void foodAndBeverage(int & HP1, int & M1) {
    if (HP1 < 200) {
        HP1 = ceil(HP1*1.3);
        
        M1 -= 150;
        validateM(M1);
        paid_money += 150;
    }
    else {
        HP1 = ceil(HP1*1.1);
        validateHP(HP1);
        
        M1 -= 70;
        validateM(M1);
        paid_money += 70;
    }
}
void rentATaxiOrCarriage(int & EXP1, int & M1) {
    if (EXP1 < 400) {
        M1 -= 200;
        validateM(M1);
        paid_money += 200;
    }
    else {
        M1 -= 120;
        validateM(M1);
        paid_money += 120;
    }
    EXP1 = ceil(EXP1*1.13);
    validateEXP(EXP1);
}
void homeless(int & EXP1, int & M1) {
    if (EXP1 < 300) {
        M1 -= 100;
        validateM(M1);
        paid_money += 100;
    }
    else {
        M1 -= 120;
        validateM(M1);
        paid_money += 120;
    }
    EXP1 = ceil(EXP1*0.9);
}
int findIndex(int E2) {
    int sumOf2Digits = (E2/10) + (E2%10);
    return sumOf2Digits%10;
}
// End Task 2

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3<0 || 99<E3) return -99;

    int map[10][10][2]; // map[][][0] -> taxi's score. map[][][1] -> Sherlock's score

    for (int i=0; i<10; i++) { // Calculate taxi's score
        for (int j=0; j<10; j++)
            map[i][j][0] = (E3*j + i*2) * (i-j);
    }
    for (int j=0; j<10; j++) { // Calculate Sherlock's score
        for (int i=0; i<10; i++) {
            int grade = leftDiagonal(map, i, j) > rightDiagonal(map, i, j) ? leftDiagonal(map, i, j) : rightDiagonal(map, i, j); // the maximum value from both the left diagonal and right diagonal of the taxi's scores
            grade = grade<0 ? -grade : grade; // if this score is negative, take its absolute value
            map[i][j][1] = grade;
        }
    }
    // taxi would meet Sherlock at the point (i, j)
    int i = findI(map, E3);
    int j = findJ(map, E3);

    if (abs(map[i][j][0]) > map[i][j][1]) { // if the absolute value of the taxi's score is greater than Sherlock's score, they wouldn't catch the taxi. EXP and HP of each will decrease by 12% and 10%
        EXP1 = ceil(EXP1*0.88);
        EXP2 = ceil(EXP2*0.88);
        
        HP1 = ceil(HP1*0.9);
        HP2 = ceil(HP2*0.9);
    }
    else { // otherwise, EXP and HP of each will increase by 12% and 10%
        EXP1 = ceil(EXP1*1.12);
        validateEXP(EXP1);
        
        EXP2 = ceil(EXP2*1.12);
        validateEXP(EXP2);

        HP1 = ceil(HP1*1.1);
        validateHP(HP1);

        HP2 = ceil(HP2*1.1);
        validateHP(HP2);
    }
    return abs(map[i][j][0]) > map[i][j][1] ? map[i][j][0] : map[i][j][1];
}
// Helping functions
int leftDiagonal(int map[10][10][2], int row, int col) {
    int topLeftRow = row, topLeftCol = col, bottomRightRow = row, bottomRightCol = col, max = INT_MIN;
    
    while (topLeftRow>0 && topLeftCol>0) { // find row and column of top left
        topLeftRow--;
        topLeftCol--;
    }
    while (bottomRightRow<9 && bottomRightCol<9) { // find row and column of bottom right
        bottomRightRow++;
        bottomRightCol++;
    }
    for (int i=topLeftRow, j=topLeftCol; i<=bottomRightRow; i++, j++) { // find max of left diagonal
        if (map[i][j][0] > max) max = map[i][j][0];
    }

    return max;
}
int rightDiagonal(int map[10][10][2], int row, int col) {
    int topRightRow = row, topRightCol = col, bottomLeftRow = row, bottomLeftCol = col, max = INT_MIN;
    while (topRightRow>0 && topRightCol<9) {
        topRightRow--;
        topRightCol++;
    }
    while (bottomLeftRow<9 && bottomLeftCol>0) {
        bottomLeftRow++;
        bottomLeftCol--;
    }
    for (int i=topRightRow, j=topRightCol; i<=bottomLeftRow; i++, j--) {
        if (map[i][j][0] > max) max = map[i][j][0];
    }
    return max;
}
int findI(int map[10][10][2], int E3) {
    int i=0;

    for (int r=0; r<10; r++) {
        for (int c=0; c<10; c++)
            if (map[r][c][0] > E3*2) i++;
    }
    int tensDigit = i/10, unitDigit = i%10;
    i = tensDigit + unitDigit;

    if (0<=i && i<=9) return i;
    else if (10<=i && i<=18) return i-9;
    else return 1;
}
int findJ(int map[10][10][2], int E3) {
    int j=0;
    
    for (int r=0; r<10; r++) {
        for (int c=0; c<10; c++)
            if (map[r][c][0] < -E3) j++;
    }
    int tensDigit = j/10, unitDigit = j%10;
    j = tensDigit + unitDigit;

    if (0<=j && j<=9) return j;
    else if (10<=j && j<=18) return j-9;
    else return 1;
}
// End Task 3

// Task 4
char se[100];
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    findSE(email, se);
    if (isValidPassword(s, se)) return -10; // if s is a valid password, return -10

    if (strlen(s) < 8) return -1;

    if (strlen(s) > 20) return -2;

    if (strstr(s, se) != nullptr) {
        int sei = strlen(s)-strlen(strstr(s, se));
        return -(300+sei);
    }

    for (int i=0; i < strlen(s)-2; i++) { // s contains more than 2 consecutive and identical characters
        if (s[i]==s[i+1] && s[i+1]==s[i+2]) return -(400+i);
    }

    bool specialChar = false;
    for (int i=0; i<strlen(s); i++) {
        if (s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!') {
            specialChar = true;
            break;
        }
    }
    if (!specialChar) return -5; // if s does not contain any special character
    
    for (int i=0; i < strlen(s); i++) {
        if ((s[i]<48 || 57<s[i]) && (s[i]<97 || 122<s[i]) && (s[i]<65 || 90<s[i]) && s[i]!='@' && s[i]!='#' && s[i]!='%' && s[i]!='$' && s[i]!='!') return i; // if s[i] is not a number, a letter or an allowed special character, return its index
    }

    return -99; // initial code
}
// Helping functions
void findSE(const char* email, char se[100]) {
    strcpy(se, email);
    
    for (int i=0; i<strlen(email); i++) {
        if (se[i] != '@') continue;
        else {
            se[i] = '\0';
            break;
        }
    }
}
bool isValidPassword(const char* s, char se[100]) {
    if (strlen(s)<8 || 20<strlen(s)) return false; // must contain from 8 to 20 characters
    bool specialChar = false;
    
    for (int i=0; i<strlen(s); i++) {
        if ( (s[i]<48 || 57<s[i]) && (s[i]<97 || 122<s[i]) && (s[i]<65 || 90<s[i]) && s[i]!='@' && s[i]!='#' && s[i]!='%' && s[i]!='$' && s[i]!='!' ) return false; // characters in the password can only be numbers, letters or these special characters '@', '#', '%', '$', '!'
        
        if (s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!') specialChar = true; // must contain at least 1 special character
    }
    if (!specialChar) return false;
    
    if (strstr(s, se) != nullptr) return false; // must not contain the string se
    
    for (int i=0; i < strlen(s)-2; i++) { // must not contain more than 2 consecutive and identical characters
        if (s[i]==s[i+1] && s[i+1]==s[i+2]) return false;
    }
    return true;
}
// End Task 4

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int index = 0; // index of the first correct password in arr_pwds[]

    const char* str[30]; // 30 distinct passwords
    for (int i=0; i<30; i++) str[i] = "\0";

    int times[30]; // save how many times str[i] appears
    for (int i=0; i<30; i++) times[i] = 0;

    int length[30]; // length of str[i]
    for (int i=0; i<30; i++) length[i] = 0;
    
    while (index<num_pwds) {
        bool skip = false;
        
        for (int i=0; i<index; i++) { // if the string at position index already appeared, skip it
            if (arr_pwds[i] == arr_pwds[index]) {
                skip = true;
                break;
            }
        }
        if (!skip) {
            str[index] = arr_pwds[index];
            times[index] = 1;
            length[index] = strlen(arr_pwds[index]);
            for (int i=index+1; i<num_pwds; i++) if (arr_pwds[i] == arr_pwds[index]) times[index]++;
        }
        index++;
    }
    
    int the_most_times = 0, the_longest = 0;
    
    for (int i=0; str[i]!="\0"; i++) {
        if (times[i]>the_most_times || length[i]>the_longest) {
            the_most_times = times[i];
            the_longest = length[i];
            index = i;
        }
    }
    return index;
    //return -1; // initial code
}
// End Task 5
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////