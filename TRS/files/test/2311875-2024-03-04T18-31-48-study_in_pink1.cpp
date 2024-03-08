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

void increaseHp(int & hp, bool tf, int value) {
    if (tf) hp += value;
    else hp -=value;
    if (hp < 0) hp = 0;
    if (hp > 666) hp = 666;
}

void increaseExp(int & exp, bool tf, int value) {
    if (tf) exp += value;
    else exp -= value;
    if (exp < 0) exp = 0;
    if (exp > 600) exp = 600;
}

void increaseM(int & m, bool tf, int value) {
    if (tf) m += value;
    else m -= value;
    if (m < 0) m = 0;
    if (m > 3000) m = 3000;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    if (e1 < 0 || e1 > 99) return -99;
    increaseExp(exp1, 1, 0);
    increaseExp(exp2, 1, 0);

    if (e1 <= 3) {
        if (e1 == 0) increaseExp(exp2, 1 ,29);
        else if (e1 == 1) increaseExp(exp2, 1 ,45);
        else if (e1 == 2) increaseExp(exp2, 1 ,75);
        else increaseExp(exp2, 1, 149);

        int D = e1*3 + exp1*7;
        if (D % 2 == 0) increaseExp(exp1, 1, D / 200 + (D % 200 != 0));
        else increaseExp(exp1, 0, floor(D / 100));
    } else {
        if (e1 <= 19) increaseExp(exp2, 1, (e1 / 4 + 19) + (e1 % 4 != 0));
        else if (e1 <= 49) increaseExp(exp2, 1, (e1 / 9 + 21) + (e1 % 9 != 0));
        else if (e1 <= 65) increaseExp(exp2, 1, (e1 / 16 + 17) + (e1 % 16 != 0));
        else if (e1 <= 79) {
            increaseExp(exp2, 1, (e1 / 4 + 19) + (e1 % 4 != 0));
            if (exp2 > 200) increaseExp(exp2, 1, (e1 / 9 + 21) + (e1 % 9 != 0));
        }
        else {
            increaseExp(exp2, 1, (e1 / 4 + 19) + (e1 % 4 != 0));
            increaseExp(exp2, 1, (e1 / 9 + 21) + (e1 % 9 != 0));
            if (exp2 > 400) {
                increaseExp(exp2, 1, e1 / 16 + 17 + (e1 % 16 != 0));
                increaseExp(exp2, 1, exp2 * 15 / 100 + (exp2 * 15 % 100 != 0));
            }
        }
        increaseExp(exp1, 0, e1);
    }
    return exp1 + exp2;
}
//----------------------------------------------------------------------

int nearestnum(int n){
    int result = round(float(sqrt(n)));
    result *= result;
    return result;
}
//----------------------------------------------------------------------
int sukien1 (int & HP1, int & M1) {
    if (HP1 < 200) {
        increaseHp(HP1, 1, HP1 * 30 / 100 + (HP1 % 10 != 0));
        increaseM(M1, 0, 150);
    } else {
        increaseHp(HP1, 1, HP1 * 10 / 100 + (HP1 % 10 != 0));
        increaseM(M1, 0, 70);
    }
    return 0;
}
//----------------------------------------------------------------------
int sukien2 (int & EXP1, int & M1){
    if (EXP1 < 400) increaseM(M1, 0, 200);
    else increaseM(M1, 0, 120);
    increaseExp(EXP1, 1, EXP1 * 13 / 100 + (EXP1 * 13 % 100 != 0));
    return 0;
}
//----------------------------------------------------------------------
int sukien3 (int & EXP1, int & M1){
    if (EXP1 < 300) increaseM(M1, 0, 100);
    else increaseM(M1, 0, 120);
    increaseExp(EXP1, 0, floor(EXP1 * 10 / 100));
    return 0;
}
//-----------------------------------------------------------------------
// Task 2      
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 > 99 || E2 < 0) return -99;
    increaseHp(HP1, 1, 0); 
    increaseExp(EXP1, 1, 0); 
    increaseM(M1, 1, 0);

    double p1 = 0, p2 = 0, p3 = 0;
    //Way1:
    int S = nearestnum(EXP1);
    if (EXP1 >= S) p1 = 1;
    else p1 = (double(EXP1) / S + 80.0) / 123.0;
    
    //Way2
    for (int i = 0; i < 1; ++i) {
        if (M1 == 0) break;
        int halfMoney = M1 / 2 + (M1 % 2 != 0);
        if (E2 % 2 != 0) {
            while (M1 >= halfMoney) {
                sukien1(HP1, M1);
                if (M1 < halfMoney) break;
                sukien2(EXP1, M1);
                if (M1 < halfMoney) break;
                sukien3(EXP1, M1);
            }
        } else {
            sukien1(HP1, M1);
            if (M1 == 0) break;
            sukien2(EXP1, M1);
            if (M1 == 0) break;
            sukien3(EXP1, M1);
        }
    }
    increaseHp(HP1, 0, floor(HP1 * 17 / 100));
    increaseExp(EXP1, 1, EXP1 * 17 / 100 + (EXP1 * 17 % 100 != 0));
    
    int S2 = nearestnum(EXP1);
    if (EXP1 >= S2) p2 = 1;
    else p2 = (double(EXP1) / S2 + 80.0) / 123.0;

    //Way3:
    int Prob[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    p3 = Prob[(E2 % 10 + E2 / 10) % 10] / 100.0;

    //Di het cả 3 con duong
    if (p1 == 1 && p2 == 1 && p3 == 1)  increaseExp(EXP1, 0, floor(EXP1 / 4));
    else {
        float pend = (p1 + p2 + p3)/3;
        if (pend < 0.5) {
            increaseHp(HP1, 0, floor(HP1 * 15 / 100));
            increaseExp(EXP1, 1, EXP1 * 15 / 100 + (EXP1 * 15 % 100 != 0));
        }
        else {
            increaseHp(HP1, 0, floor(HP1 * 10 / 100));
            increaseExp(EXP1, 1, EXP1 * 20 / 100 + (EXP1 * 20 % 100 != 0));
        }
    } 
       return HP1 + EXP1 + M1;
}
//-----------------------------------------------------------------------------
// Task 3
int score (int i, int j, int E3) {
    return ((E3 * j) + (i * 2)) * (i - j);
} 

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    increaseHp(HP1, 1, 0); 
    increaseExp(EXP1, 1, 0); 
    increaseHp(HP2, 1, 0); 
    increaseExp(EXP2, 1, 0); 

    int matrix[10][10] = {}; //ma trận ban đầu
    for (int i = 0; i <= 9; ++i)
        for (int j = 0; j <= 9; ++j)
            matrix[i][j] = score(i, j, E3);  //ma trận điểm số của taxi
    
    int x = 0, y = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            if (matrix[i][j] > (E3 * 2)) x++;  //tìm điểm (x, y) gặp nhau
            if (matrix[i][j] < (-E3)) y++;
        }
    }
    while (x >= 10) x = x / 10 + x % 10;
    while (y >= 10) y = y / 10 + y % 10;

    int max = score(0, 0, E3);
    int n = x, m = y;
    while (n < 10 && m < 10) {
        n++;
        m++;
        if (score(n, m, E3) > max) max = score(n, m, E3);
    }
    n = x, m = y;
    while (n > 0 && m > 10) {
        n--;
        m--;
        if (score(n, m, E3) > max) max = score(n, m, E3);
    } 
    n = x, m = y;
    while (n > 0 && m < 10) {
        n--;
        m++;
        if (score(n, m, E3) > max) max = score(n, m, E3);
    }
    n = x, m = y;
    while (n < 10 && m > 0) {
        n++;
        m--;
        if (score(n, m, E3) > max) max = score(n, m, E3);
    }    

    if (abs(matrix[x][y]) > max) {
        increaseExp(EXP1, 0, floor(EXP1 * 12 / 100));
        increaseHp(HP1, 0, floor(HP1 / 10));
        increaseExp(EXP2, 0, floor(EXP2 * 12 / 100));
        increaseHp(HP2, 0, floor(HP2 / 10));
        return matrix[x][y];
    } else {
        increaseExp(EXP1, 1, (EXP1 * 12 / 100) + (EXP1 * 12 % 100 != 0));
        increaseHp(HP1, 1, (HP1 / 10) + (HP1 % 10 != 0));
        increaseExp(EXP2, 1, (EXP2 * 12 / 100) + (EXP2 * 12 % 100 != 0));
        increaseHp(HP2, 1, (HP2 / 10) + (HP2 % 10 != 0));
        return max;
    }
}
//------------------------------------------------------------------------------
// Task 4
bool validWord(char temp) {
     return (isupper(temp) || islower(temp) || isdigit(temp)
     || (temp == '@') || (temp == '!') || (temp == '#') || (temp == '$') || (temp == '%') );
}

int checkPassword(const char* s, const char* email) {
    if (strlen(s) < 8) return -1;
    if (strlen(s) > 20) return -2;
    char name[100];
    strcpy(name, email);
    char* se = strtok(name, "@");

    if (strstr(s, se) != NULL) {
        for (int i = 0; i < strlen(s) - strlen(se) + 1; ++i){
            if (s[i] == se[0])
            {
                if (strlen(se) == 1) return -(300 + i);
                int j = 1;
                while (j < strlen(se))
                {
                    if (s[i + j] == se[j]) j++;
                    else break;
                }
                if (j == strlen(se)) return -(300 + i);
            }
        }
    } 
    if (strlen(s) > 2) for (int i = 0; i < strlen(s) - 2; ++i)
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) return -(400 + i);

    if (strchr(s, '@') == NULL
        && strchr(s, '!') == NULL
        && strchr(s, '#') == NULL
        && strchr(s, '$') == NULL
        && strchr(s, '%') == NULL) return -5;

    for (int i = 0; i < strlen(s); i++){ 
       if (validWord(s[i]) == 0) return i;
       }
    return -10;
    
}

//------------------------------------------------------------------------------
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxCount = 0;
    int maxLength = 0;
    int correctPwd = 0;
    for (int i = 0; i < num_pwds; i++) {
        const char* pwd = arr_pwds[i];
        int pwdCount = 0;
        int pwdLength = strlen(pwd);
        for (int j = 0; j < num_pwds; j++) {
            if (j != i && strcmp(pwd, arr_pwds[j]) == 0) pwdCount++;
            if (pwdCount > maxCount || (pwdCount == maxCount && pwdLength > maxLength)) {
                maxCount = pwdCount;
                maxLength = pwdLength;
                correctPwd = i;
            }
        } 
    }
    return correctPwd;
}
  
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////