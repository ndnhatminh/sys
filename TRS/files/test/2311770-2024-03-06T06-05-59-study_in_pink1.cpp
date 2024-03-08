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

int roundUp(double b) { // Ham lam tron so len 1
    return int(b) + (b > int(b));
}

void checkExp(int& a) { // Ham kiem tra mien của EXP
    if (a < 0) 
    {
        a = 0;
    }
    if (a > 600) 
    {
        a = 600;
    }
}

bool reviewMoney(int& a) { // Ham kiem tra tien am hay duong
    if (a <= 0) 
    {
        return 1;
    }
    return 0;
}

void checkMoney(int& a) {
    if (a > 3000) 
    {
        a = 3000;
    }
    if (a < 0) 
    {
        a = 0;
    }
}

void checkHP(int& a) {
    if (a > 666) 
    {
        a = 666;
    }
    if (a < 0) 
    {
        a = 0;
    }
}


double probability(int a) {
    double P;
    int S = 0;
    while (S * S <= a) {  // Ham tim so chinh phuong gan nhat
        S++;
    }
    int lower = (S - 1) * (S - 1);
    int bigger = S * S;
    if ((a - lower) < (bigger - a)) 
    {
        P = 1;
    }
    else 
    {
        P = ((a * 1.0 / bigger) + 80) / 123.0;
    }
    return P;
}

void Tong2ChuSo(int& x) { // Ham tinh tong 2 chu so
    x = (x / 10) + (x % 10);
}

int maxnumber(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int AbsoluteValue(int a) {
    int b = a - 2 * (a < 0) * a;
    return b;
}

void charCopy(const char* a, string b[], int j) {
    b[j] = a;
}

bool comparePass(const char* a, string b[], int j) {
    if (b[j] != a) return 0;
    return 1;
}

bool checkE(int a) {
    if (a < 0 || a > 99) return 1;
    return 0;
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    checkExp(exp1);
    checkExp(exp2);

    if (e1 >= 0 && e1 <= 3) // Truong hop 1
    {
        if (e1 == 0) // Thong tin 1
        {
            exp2 += 29;
        }
        else if (e1 == 1) // Thong tin 2
        {
            exp2 += 45;
        }
        else if (e1 == 2) // Thong tin 3
        {
            exp2 += 75;
        }
        else
        {
            exp2 += 29 + 45 + 75; // Thong tin 4
        }
        int D;
        D = e1 * 3 + exp1 * 7;

        if (D % 2 == 0) exp1 += roundUp(D / 200.0);
        else exp1 = roundUp(exp1 - (D / 100.0));

    }
    else if (e1 >= 4 && e1 <= 99) // Truong hop 2
    {
        if (e1 <= 19) // Thong tin 1
        {
            exp2 += roundUp(e1 / 4.0 + 19);
        }
        else if (e1 >= 20 && e1 <= 49) // Thong tin 2
        {
            exp2 += roundUp(e1 / 9.0 + 21);
        }
        else if (e1 >= 50 && e1 <= 65) // Thong tin 3 
        {
            exp2 += roundUp(e1 / 16.0 + 17);
        }
        else if (e1 >= 66 && e1 <= 79) // Thong tin 4
        {
            exp2 += roundUp(e1 / 4.0 + 19);
            checkExp(exp2);
            if (exp2 > 200) 
            {
                exp2 += roundUp(e1 / 9.0 + 21);
            }
        }
        else // Thong tin 5
        {
            exp2 += roundUp(e1 / 4.0 + 19);
            exp2 += roundUp(e1 / 9.0 + 21);
            checkExp(exp2);
            if (exp2 > 400)
            {
                exp2 += roundUp(e1 / 16.0 + 17);
                checkExp(exp2);
                exp2 = roundUp(exp2 * 1.15);
            }
        }
        exp1 -= e1;
    }
    else return -99;
    checkExp(exp1);
    checkExp(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function

    checkExp(EXP1);
    checkHP(HP1);
    checkMoney(M1);
    if (checkE(E2)) return -99;

    //Tim P1
    double P1 = probability(EXP1);

    //Tim P3
    double P3;
    int i;
    if (E2 / 10 == 0) i = E2;
    else i = ((E2 / 10) + (E2 % 10)) % 10;
    if (i == 0) P3 = 32 / 100.0;
    else if (i == 1) P3 = 47 / 100.0;
    else if (i == 2) P3 = 28 / 100.0;
    else if (i == 3) P3 = 79 / 100.0;
    else if (i == 4) P3 = 100 / 100.0;
    else if (i == 5) P3 = 50 / 100.0;
    else if (i == 6) P3 = 22 / 100.0;
    else if (i == 7) P3 = 83 / 100.0;
    else if (i == 8) P3 = 64 / 100.0;
    else if (i == 9) P3 = 11 / 100.0;

    //Tim P2
    if (E2 % 2 == 0) // TH1: khong lap lai
    {
        if (reviewMoney(M1)) goto endoftheRoad;

        if (HP1 < 200) // Su kien 1
        {
            HP1 = roundUp((HP1 / 10.0) * 13);
            M1 -= 150;
        }
        else
        {
            HP1 = roundUp((HP1 / 10.0) * 11);
            M1 -= 70;
        }

        checkHP(HP1);
        checkMoney(M1);

        if (reviewMoney(M1)) {
            goto endoftheRoad;
        }

        if (EXP1 < 400) // Su kien 2
        {
            M1 -= 200;
        }
        else 
        {
            M1 -= 120;
        }
        EXP1 = roundUp((EXP1 / 100.0) * 113);

        checkExp(EXP1);
        checkMoney(M1);

        if (reviewMoney(M1)) 
        {
            goto endoftheRoad;
        }

        if (EXP1 < 300) 
        {
            M1 -= 100;
        }
        else 
        {
            M1 -= 120;
        }
        EXP1 = roundUp((EXP1 / 100.0) * 90);

        checkExp(EXP1);
        checkMoney(M1);

    endoftheRoad:
        HP1 = roundUp((HP1 / 100.0) * 83);
        EXP1 = roundUp((EXP1 / 100.0) * 117);
        checkExp(EXP1);
    }

    else // TH2: lap lai
    {
        int initialMoney = M1;
        if (reviewMoney(M1)) 
        {
            goto endoftheRoad1;
        }

    EventLoop:
        if (HP1 < 200) // Su kien 1
        {
            HP1 = roundUp((HP1 / 10.0) * 13);
            M1 -= 150;
        }
        else
        {
            HP1 = roundUp((HP1 / 10.0) * 11);
            M1 -= 70;
        }

        checkHP(HP1);
        checkMoney(M1);

        if (M1 < (initialMoney * 0.5)) 
        {
            goto endoftheRoad1;
        }

        if (EXP1 < 400) // Su kien 2 
        {
            M1 -= 200;
        }
        else 
        {
            M1 -= 120;
        }
        EXP1 = roundUp((EXP1 / 100.0) * 113);
        checkExp(EXP1);
        checkMoney(M1);

        if (M1 < (initialMoney * 0.5)) 
        {
            goto endoftheRoad1;
        }

        if (EXP1 < 300) 
        {
            M1 -= 100;
        }
        else 
        {
            M1 -= 120;
        }
        EXP1 = roundUp((EXP1 / 100.0) * 90);
        checkExp(EXP1);
        checkMoney(M1);

        if (M1 >= (initialMoney * 0.5)) 
        {
            goto EventLoop;
        }
        else 
        {
            goto endoftheRoad1;
        }

    endoftheRoad1:
        checkMoney(M1);
        HP1 = roundUp((HP1 / 100.0) * 83);
        EXP1 = roundUp((EXP1 / 100.0) * 117);
        checkExp(EXP1);
        checkHP(HP1);
    }

    double P2 = probability(EXP1);

    double averProb;
    if (P1 == 1 && P2 == 1 && P3 == 1) 
    {
        EXP1 = roundUp(EXP1 * 0.75);
    }
    else 
    {
        averProb = (P1 + P2 + P3) / 3.0;
        if (averProb < 0.5)
        {
            HP1 = roundUp((HP1 / 100.0) * 85);
            EXP1 = roundUp((EXP1 / 100.0) * 115);
        }
        else
        {
            HP1 = roundUp((HP1 / 100.0) * 90);
            EXP1 = roundUp((EXP1 / 100.0) * 120);
        }
    }

    checkExp(EXP1);
    checkHP(HP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (checkE(E3)) return -99;
    checkExp(EXP1);
    checkExp(EXP2);
    checkHP(HP1);
    checkHP(HP2);

    int matrix[10][10];
    int TrucX = 0;
    int TrucY = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (matrix[i][j] > E3 * 2) TrucX++;
            if (matrix[i][j] < -E3) TrucY++;
        }
    }
    while (TrucX >= 10)
    {
        Tong2ChuSo(TrucX);
    }
    while (TrucY >= 10)
    {
        Tong2ChuSo(TrucY);
    }

    int maxNumber = matrix[TrucX][TrucY];

    int a = TrucX - TrucY;
    int b = 0;
    if (a >= 0) {
        while (a < 10) {
            if (matrix[a][b] >= maxNumber) maxNumber = matrix[a][b];
            a++;
            b++;
        }
    }
    else {
        while (-a < 10) {
            if (matrix[b][-a] >= maxNumber) maxNumber = matrix[b][-a];
            a--;
            b++;
        }
    }

    int c = TrucX + TrucY;
    int d = 0;
    if (c < 10)
    {
        while (c >= 0) {
            if (matrix[c][d] >= maxNumber) maxNumber = matrix[c][d];
            d++;
            c--;
        }
    }
    else
    {
        int f = 9;
        while (c - 9 <= 9) {
            if (matrix[f][c - 9] >= maxNumber) maxNumber = matrix[9][c - 9];
            c++;
            f--;
        }
    }
    if (AbsoluteValue(maxNumber) < AbsoluteValue(matrix[TrucX][TrucY])) {
        EXP1 = roundUp((EXP1 / 100.0) * 88);
        EXP2 = roundUp((EXP2 / 100.0) * 88);
        HP1 = roundUp((HP1 / 100.0) * 90);
        HP2 = roundUp((HP2 / 100.0) * 90);
        checkExp(EXP1);
        checkExp(EXP2);
        checkHP(HP1);
        checkHP(HP2);
        return matrix[TrucX][TrucY];
    }
    else {
        EXP1 = roundUp((EXP1 / 100.0) * 112);
        EXP2 = roundUp((EXP2 / 100.0) * 112);
        HP1 = roundUp((HP1 / 100.0) * 110);
        HP2 = roundUp((HP2 / 100.0) * 110);
        checkExp(EXP1);
        checkExp(EXP2);
        checkHP(HP1);
        checkHP(HP2);
        return maxNumber;
    }
    checkExp(EXP1);
    checkExp(EXP2);
    checkHP(HP1);
    checkHP(HP2);
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int seSize = 0;
    while (email[seSize] != '@')
    {
        seSize++;
    }

    char se[seSize];
    for (int i = 0; i < seSize; i++)
    {
        se[i] = email[i];
    }


    int size = 0;
    while (s[size] != '\0') {
        size++;
    }

    if (size < 8) return -1;
    if (size > 20) return -2;

    if (seSize == 0) return -300;

    int specialChar = 0;
    for (int i = 0; i < size - (seSize - 1); i++)
    {
        if (s[i] == se[0])
        {
            int j = i;
            int k = 0;
            while (s[j] == se[k] && k < seSize) {
                j++;
                k++;
            }
            if (k == seSize) return -(300 + i);
        }
    }

    for (int i = 0; i < size - 2; i++)
    {
        if (s[i + 1] == s[i]) {
            if (s[i + 2] == s[i]) return -(400 + i);
        }
    }


    for (int i = 0; i < size; i++)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') specialChar++;
    }
    if (specialChar == 0) return -5;

    for (int i = 0; i < size; i++)
    {
        if ((int(s[i]) == 32) || (int(s[i]) == 34) || ((int(s[i]) < 48) && (int(s[i]) > 37)) || ((int(s[i]) < 64) && (int(s[i]) > 57)) || ((int(s[i]) < 97) && (int(s[i]) > 90)) || ((int(s[i]) < 127) && (int(s[i]) > 122))) return i;
    }


    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int typeCount = 0;
    int arrayType[30];
    arrayType[0] = 1;
    string testPass[30];
    charCopy(arr_pwds[0], testPass, 0);

    for (int i = 1; i < num_pwds; i++)
    {
        for (int j = 0; j <= typeCount; j++)
        {
            if (comparePass(arr_pwds[i], testPass, j)) {
                arrayType[j]++;
                goto endofLoop;
            }
        }
        typeCount++;
        arrayType[typeCount] = 0;
        arrayType[typeCount]++;
        charCopy(arr_pwds[i], testPass, typeCount);
    endofLoop:
        ;
    }
    int max = 0;
    for (int i = 0; i < typeCount; i++)
    {
        if (arrayType[i + 1] > arrayType[max])  max = i + 1;
        if (arrayType[i + 1] == arrayType[max]) {
            if (testPass[i + 1].length() > testPass[max].length()) max = i + 1;
        }
    }
    int count = 0;
    while (testPass[max] != arr_pwds[count])
    {
        count++;
    }

    return count;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////