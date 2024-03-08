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
bool checkE(int E){
    if (E < 0 || E > 99) return false;
    return true;
}
void checkHP(int & HP){
    if (HP > 666) HP = 666;
    else if (HP < 0) HP = 0;
    else return;
}

void checkEXP(int & EXP){
    if (EXP > 600) EXP = 600;
    else if (EXP < 0) EXP = 0;
    else return;
}
void checkM(int & M){
    if (M > 3000) M = 3000;
    else if (M < 0) M = 0;
    else return;
}
int ceilVer2(double n){
    if (abs(n - int(n)) > 1e-9)
        return ceil(n);
    else 
        return int(n);
}
bool squareNum(int n, int & S)
{
    if (n == 0){
        S = 0;
        return true;
    }

    int a = sqrt(n);
    S = (a + 1)*(a + 1) - n > n - a*a ? a*a : (a + 1)*(a + 1);
    if (S > n) return false;
    return true;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (!checkE(e1)) return -99;

    checkEXP(exp1);
    checkEXP(exp2);

    if (e1 < 4) 
    {
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
            case 3:
                exp2 += 149;
                break;
        }

        int D = e1*3 + exp1*7;
        if (D % 2 == 0)
            exp1 = ceilVer2(exp1 + D/200.0);
        else
            exp1 = ceilVer2(exp1 - D/100.0);

    }
    else {
        if (e1 < 20) {
            exp2 = ceilVer2(exp2 + e1/4.0 + 19);
        }
        else if (e1 < 50){
            exp2 = ceilVer2(exp2 + e1/9.0 + 21);     
        }  
        else if (e1 < 66){
            exp2 = ceilVer2(exp2 + e1/16.0 + 17);
        }
        else if (e1 < 80) {
            exp2 = ceilVer2(exp2 + e1/4.0 + 19);
            if (exp2 > 200)
                exp2 = ceilVer2(exp2 + e1/9.0 + 21);
        }
        else {
            exp2 = ceilVer2(exp2 + e1/4.0 + 19);
            exp2 = ceilVer2(exp2 + e1/9.0 + 21);
            if (exp2 > 400)
            {
                exp2 = ceilVer2(exp2 + e1/16.0 + 17);
                exp2 = ceilVer2(exp2 + 0.15*exp2);
            }
        }
        exp1 -= e1;
    }
    
    checkEXP(exp1);
    checkEXP(exp2);
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (!checkE(E2)) return -99;

    checkHP(HP1);
    checkEXP(EXP1);
    checkM(M1);

    // con duong 1
    float P, P1, P2, P3;
    int S;
    if (squareNum(EXP1, S)) 
        P1 = 1;
    else 
        P1 = ((EXP1*1.0)/S + 80)/123;

    // con duong 2
    float half = M1*0.5;
    int sumCost = 0;
    while (true){
        if (M1 == 0) break;

        // su kien 1
        if (HP1 < 200){
            HP1 = ceilVer2(HP1*1.3);
            M1 -= 150; sumCost += 150;
        }
        else {
            HP1 = ceilVer2(HP1*1.1);
            M1 -= 70; sumCost += 70;
        }

        checkHP(HP1);
        checkM(M1);

        if ((E2 % 2 == 1 && sumCost > half) || (E2 % 2 == 0 && M1 == 0))
            break;

        // su kien 2
        if (EXP1 < 400){
            M1 -= 200;
            sumCost += 200;
        }  
        else{
            M1 -= 120;
            sumCost += 120;
        }
        EXP1 = ceilVer2(EXP1*1.13);

        checkEXP(EXP1);
        checkM(M1);

        if ((E2 % 2 == 1 && sumCost > half) || (E2 % 2 == 0 && M1 == 0))
            break;

        // su kien 3
        if (EXP1 < 300){
            M1 -= 100;
            sumCost += 100;
        } 
        else {
            M1 -= 120;
            sumCost += 120;
        }
        EXP1 = ceilVer2(EXP1*0.9);

        checkM(M1);

        if ((E2 % 2 == 1 && sumCost > half) || E2 % 2 == 0)
            break;
    }
    
    EXP1 = ceilVer2(EXP1*1.17);
    HP1 = ceilVer2(HP1*0.83);

    checkEXP(EXP1);

    if (squareNum(EXP1, S)) 
        P2 = 1;
    else 
        P2 = ((EXP1*1.0)/S + 80)/123;

    // con duong 3
    float p[] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    int i = (E2%10 + E2/10) % 10;
    P3 = p[i];
    
    if (P1 == P2 && P2 == P3 && P3 == 1)
        EXP1 = ceilVer2(EXP1*0.75);
    else {
        P = (P1 + P2 + P3) / 3;
        if (P < 0.5){
            HP1 = ceilVer2(HP1*0.85);
            EXP1 = ceilVer2(EXP1*1.15);
        }
        else {
            HP1 = ceilVer2(HP1*0.9);
            EXP1 = ceilVer2(EXP1*1.2);
        }
        checkEXP(EXP1);
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (!checkE(E3)) return -99;
    
    checkHP(HP1);
    checkEXP(EXP1);
    checkHP(HP2);
    checkEXP(EXP2);

    int matrix[10][10] = {0};
    int num1(0), num2(0);
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] += (E3*j + i*2)*(i - j);
            if (matrix[i][j] > E3*2) num1++;
            if (matrix[i][j] < E3*(-1)) num2++;
        }
    }

    while (num1/10 != 0){
        num1 = num1/10 + num1%10;
    }
    while (num2/10 != 0){
        num2 = num2/10 + num2%10;
    }

    int MAX = matrix[num1][num2];
    int a, b;

    a = num1 - 1; b = num2 - 1;
    while (a >= 0 && b >= 0)
    {
        if (matrix[a][b] > MAX)
        MAX = matrix[a][b];
        a--; b--;
    }

    a = num1 + 1; b = num2 + 1;
    while (a <= 9 && b <= 9)
    {
        if (matrix[a][b] > MAX)
        MAX = matrix[a][b];
        a++; b++;
    }

    a = num1 - 1; b = num2 + 1;
    while (a >= 0 && b <= 9)
    {
        if (matrix[a][b] > MAX)
        MAX = matrix[a][b];
        a--; b++;
    }

    a = num1 + 1; b = num2 - 1;
    while (a <= 9 && b >= 0)
    {
        if (matrix[a][b] > MAX)
        MAX = matrix[a][b];
        a++; b--;
    }

    if (MAX < 0) MAX *= (-1);

    int taxi = matrix[num1][num2];
    if (taxi < 0) taxi *= (-1);

    if (taxi - MAX > 0){
        EXP1 = ceilVer2(EXP1*0.88);
        EXP2 = ceilVer2(EXP2*0.88);
        HP1 = ceilVer2(HP1*0.9);
        HP2 = ceilVer2(HP2*0.9);
        return matrix[num1][num2];
    }
    else {
        EXP1 = ceilVer2(EXP1*1.12);
        EXP2 = ceilVer2(EXP2*1.12);
        HP1 = ceilVer2(HP1*1.1);
        HP2 = ceilVer2(HP2*1.1);
        checkEXP(EXP1); checkEXP(EXP2);
        checkHP(HP1); checkHP(HP2); 
        return MAX;
    }
}

// Task 4
int checkSE(const char * s, char * se){
    if (strstr(s, se) != NULL)
        return strstr(s, se) - s;
    else
        return -1;
}
int checkDuplicate(const char * str, int num){
    if (num <= 2) return -1;
  
    for (int i = 1; i < num - 1; i++){
        if (str[i] == str[i - 1] && str[i] == str[i + 1])
            return i - 1;
    }
    return -1;
}
int checkChar(const char * str, int num){
        bool flag1 = true, flag2 = true;
        int temp = -1;
        for (int i = 0; i < num; i++) {
            if (str[i] == '@' || str[i] == '#' || str[i] == '%' || str[i] == '$' || str[i] == '!'){
                flag1 = false;
            }
            else if (flag2 && (str[i] < 48 || (str[i] > 57 && str[i] < 65) || (str[i] > 90 && str[i] < 97) || str[i] > 122)){
                flag2 = false;
                temp = i;
            }  
        }
        if (flag1) return -5;
        return temp;
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function 
    int num1 = strlen(s), num2 = strlen(email);
    char se[100];

    for (int i = 0; i < num2; i++) {
        if (email[i] == '@')
        {
            strncpy(se, email, i);
            se[i] = '\0';
            break;
        }           
    }

    if (num1 < 8) return -1;
    if (num1 > 20) return -2;

    int temp = checkSE(s, se);
    if (temp != -1) return -(temp + 300);

    temp = checkDuplicate(s, num1);
    if (temp != -1) return -(temp + 400);

    temp = checkChar(s, num1);
    if (temp != -1) return temp;

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function 
    char pwds[30][30] = {'\0'};
    int table[3][30] = {0};
    int num = 0;

    for (int i = 0; i < num_pwds; i++){
        bool flag = true;
        for (int j = 0; j < num; j++){
            if (strcmp(arr_pwds[i], pwds[j]) == 0){
                table[0][j]++;
                flag = false;
                break;
            }
        }
        if (flag){
            strcpy(pwds[num], arr_pwds[i]);
            table[0][num]++;
            table[1][num] = strlen(arr_pwds[i]);
            table[2][num] = i;
            num++;
        }
    }

    int MAX(0), res, len;

    for (int i = 0; i < num; i++){
        if (table[0][i] > MAX){
            MAX = table[0][i];
            res = table[2][i];
            len = table[1][i];
        }
        else if (table[0][i] == MAX){
            if (table[1][i] > len){
                res= table[2][i];
                len = table[1][i];
            }
        }
    }

    return res;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////