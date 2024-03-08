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

// Task 1

void checkEXP(int& exp1, int& exp2)
{
    exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
    exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
}


void checkHP(int& hp1, int& hp2)
{
    hp1 = (hp1 < 0) ? 0 : (hp2 > 666) ? 666 : hp1;
    hp2 = (hp2 < 0) ? 0 : (hp2 > 666) ? 666 : hp2;
}

void checkM(int& M1, int& M2)
{
    M1 = (M1 < 0) ? 0 : (M1 > 3000) ? 3000 : M1;
    M2 = (M2 < 0) ? 0 : (M2 > 3000) ? 3000 : M2;
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

    double in1 = exp2 + (e1 / 4.0 + 19.0),
        in2 = exp2 + (e1 / 9.0 + 21.0),
        in3 = exp2 + (e1 / 16.0 + 17.0);

    if (e1 < 0 && e1 > 99)
        return -99;

    checkEXP(exp1, exp2);
    int p;

    if (e1 >= 0 && e1 <= 3) {
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
            exp2 = exp2 + 29 + 45 + 75;
        }

        int D = 3 * e1 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = ceil(exp1 + (D / 200 + 1));
        }
        else {
            exp1 = exp1 - ceil(D / 100);
        }
    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 = ceil(in1);
            exp1 -= e1;
            checkEXP(exp1, exp2);
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 = ceil(in2);
            exp1 -= e1;
            checkEXP(exp1, exp2);
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 = ceil(in3);
            exp1 -= e1;
            checkEXP(exp1, exp2);
        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = ceil(in1);
            int a = exp2;
            exp1 -= e1;
            checkEXP(exp1, exp2);
            if (exp2 > 200) {
                exp2 = a + ceil(e1 / 9.0 + 21.0);
                checkEXP(exp1, exp2);
                checkEXP(exp1, exp2);

            }
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 = ceil(in1);
            p = exp2;
            exp2 = p + ceil((e1 / 9.0 + 21.0)); ;
            checkEXP(exp1, exp2);
            if (exp2 > 400) {
                exp2 += ceil(in3);
                checkEXP(exp1, exp2);
                exp2 = ceil(exp2 * 1.15);
                checkEXP(exp1, exp2);

            }
            exp1 -= e1;
        }
    }
    checkEXP(exp1, exp2);

    return exp1 + exp2;
}

void checkEXP(int& EXP1) {
    EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
}

void checkHP(int& HP1) {
    HP1 = (HP1 < 0) ? 0 : (HP1 > 666) ? 666 : HP1;
}

void checkM(int& M1) {
    M1 = (M1 < 0) ? 0 : (M1 > 3000) ? 3000 : M1;
}
int S(int EXP1) {
    int S = round(sqrt(EXP1));
    return S * S;
}

void even1(int& HP1, int& M1, int& pay) {

    if (HP1 < 200) {
        HP1 = ceil(HP1 * 1.3);
        checkHP(HP1);
        M1 = M1 - 150;
        checkM(M1);
        pay += 150;
    }
    else {
        HP1 = ceil(HP1 * 1.10);
        checkHP(HP1);
        M1 = M1 - 70;
        checkM(M1);
        pay += 70;
    }
}

void even2(int& EXP1, int& M1, int& pay) {
    if (EXP1 < 400) {
        EXP1 = ceil(EXP1 * 1.13);
        checkEXP(EXP1);
        M1 = M1 - 200;
        checkM(M1);
        pay += 200;

    }
    else {
        EXP1 = ceil(EXP1 * 1.13);
        checkEXP(EXP1);
        M1 = M1 - 120;
        checkM(M1);
        pay += 120;
    }
}

void even3(int& EXP1, int& M1, int& pay) {
    if (EXP1 < 300) {
        EXP1 = ceil(EXP1 * 0.90);
        checkEXP(EXP1);
        M1 = M1 - 100;
        checkM(M1);
        pay = pay + 100;
    }
    else {
        EXP1 = ceil(EXP1 * 0.90);
        checkEXP(EXP1);
        M1 = M1 - 120;
        checkM(M1);
        pay = pay + 120;
    }
}


int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    float P1;
    int S1 = S(EXP1);
    float P2;
    int pay = 0;
    int half = M1 * 0.5;

    if (EXP1 >= S1) {
        P1 = 1;
    }
    else {
        P1 = (EXP1 / S1 + 80) / 123;
    }

    if (E2 % 2 == 1) {
        while (pay < half) {
            even1(HP1, M1, pay);
            if (pay > half)
                break;
            even2(EXP1, M1, pay);
            if (pay > half)
                break;
            even3(EXP1, M1, pay);
            if (pay > half)
                break;
        }
        HP1 = ceil(HP1 * 0.83);
        checkHP(HP1);
        EXP1 = ceil(EXP1 * 1.17);
        checkEXP(EXP1);
    }
    else {
        even1(HP1, M1, pay);
        if (M1 > 0)
        {
            even2(EXP1, M1, pay);
            if (M1 > 0)
            {
                even3(EXP1, M1, pay);
            }
        }
        HP1 = ceil(HP1 * 0.83);
        checkHP(HP1);
        EXP1 = ceil(EXP1 * 1.17);
        checkEXP(EXP1);
    }
    int S2 = S(EXP1);
    if (EXP1 >= S2) {
        P2 = 1;
    }
    else {
        P2 = (EXP1 / S2 + 80) / 123;
    }
    float P;
    int i;
    int P_i[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    float P3;
    if (E2 < 10) {
        i = E2;
        P3 = P_i[i] / 100;
    }
    else {
        i = (E2 / 10 + E2 % 10) % 10;
        P3 = P_i[i];
    }

    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = ceil(EXP1 * 0.75);
        checkEXP(EXP1);
    }
    else {
        P = (P1 + P2 + P3) / 3;
        if (P < 0.5) {
            HP1 = ceil(HP1 * 0.85);
            checkHP(HP1);
            EXP1 = ceil(EXP1 * 1.15);
            checkEXP(EXP1);

        }
        else {
            HP1 = ceil(HP1 * 0.9);
            checkHP(HP1);
            EXP1 = ceil(EXP1 * 1.20);
            checkEXP(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}



int score(int E3, int i, int j) {
    return ((E3 * j) + (i * 2)) * (i - j);
}

int maxscore(int a, int b) {
    return (a > b) ? a : b;
}

void update(int& HP, int& EXP, double HP_1, double EXP_1) {
    HP = ceil(HP * HP_1);
    EXP = ceil(EXP * EXP_1);
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

    int matrix[10][10] = { 0 };
    int posi = 0, posj = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = score(E3, i, j);
            posi += (matrix[i][j] > 2 * E3);
            posj += (matrix[i][j] < -E3);
        }
    }



    while (posi >= 10) {
        posi = (posi % 10) + (posi / 10);
    }
    while (posj >= 10) {
        posj = (posj % 10) + (posj / 10);
    }

    int taxiScore = matrix[posi][posj];
    int sherlockScore = matrix[posi][posj];

    for (int i = 0; i < 10; i++) {
        int col = (posj - posi) + i;
        if (col >= 0 && col < 10) {
            sherlockScore = maxscore(sherlockScore, matrix[i][col]);
        }
    }

    for (int i = 0; i < 10; i++) {
        int col = (posi + posj) - i;
        if (col >= 0 && col < 10) {
            sherlockScore = maxscore(sherlockScore, matrix[i][col]);
        }
    }

    if (abs(taxiScore) > abs(sherlockScore)) {
        update(HP1, EXP1, 0.9, 0.88);
        update(HP2, EXP2, 0.9, 0.88);
        return taxiScore;
    }
    else {
        update(HP1, EXP1, 1.1, 1.12);
        update(HP2, EXP2, 1.1, 1.12);
        return sherlockScore;
    }
}
 

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
        char tempEmail[100]; 
    strcpy(tempEmail, email);

    const char* se = strtok(tempEmail, "@");
    int n = strlen(s);
    int hasspe = 0;
    int se_1 = 0; 
    int cr = 0;

    for (int i = 0; i < n; i++) {
        char spe = s[i];

        if (spe == '@' || spe == '#' || spe == '%' || spe == '$' || spe == '!') {
            hasspe = 1;
        }

        for (int j = 0; se[j] != '\0'; j++) {
            if (s[i + j] != se[j]) {
                break;
            }
            if (se[j + 1] == '\0') {
                se_1 = 1;
            }
        }

        if (i >= 2 && spe == s[i - 1] && spe == s[i - 2]) {
            cr = 1;
        }
    }

    if (hasspe && !se_1 && !cr && n >= 8 && n <= 20) {
        return -10; 
    }
    else if (n < 8) {
        return -1;  
    }
    else if (n > 20) {
        return -2;  
    }
    else if (se_1) {
        return -(300 + (strstr(s, se) - s));  
    }
    else if (cr) {
        for (int i = 2; i < n; i++) {
            if (s[i] == s[i - 1] && s[i] == s[i - 2]) {
                return -(400 + i - 2);  
            }
        }
    }
    else if (!hasspe) {
        return -5;  
    }
    else {
        for (int i = 0; i < n; i++) {
            if (!islower(s[i]) && !isupper(s[i]) && !isdigit(s[i]) && strchr("@#%$!", s[i])) {
                return i;  
            }
        }
    }

    return -99;
}

   

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    
int cnt = 0, len = 0, id = -1;

    for (int i = 0; i < num_pwds; ++i) {
        const char* curpwd = arr_pwds[i];
        int curlen = strlen(curpwd), cur = 1;

        for (int j = i + 1; j < num_pwds; ++j) {  // Thay ð?i 'num' thành 'num_pwds'
            if (strcmp(curpwd, arr_pwds[j]) == 0) {
                cur++;
            }
        }

        if ((cur > cnt) || (cur == cnt && curlen > len)) {
            cnt = cur;
            len = curlen;
            id = i;
        }
    }

    return id;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
