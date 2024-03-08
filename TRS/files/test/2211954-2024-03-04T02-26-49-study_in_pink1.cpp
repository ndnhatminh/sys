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
void determinedRangeHP(int& HP) {
    if (HP < 0) {
        HP = 0;
    }
    if (HP > 666) {
        HP = 666;
    }
}

void determinedRangeEXP(int& exp) {
    if (exp < 0) {
        exp = 0;
    }
    if (exp > 600) {
        exp = 600;
    }
}

void determinedRangeM(int& m) {
    if (m < 0) {
        m = 0;
    }
    if (m > 3000) {
        m = 3000;
    }
}

int firstMeet(int& exp1, int& exp2, int e1) {
    determinedRangeEXP(exp1);
    determinedRangeEXP(exp2);
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
        else {
            exp2 += (29 + 45 + 75);
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = ceil((exp1 + ((float)D / 200)));
        }
        else {
            exp1 = ceil((exp1 - ((float)D / 100)));
        }
    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 = ceil((exp2 + ((float)e1 / 4 + 19)));
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 = ceil((exp2 + ((float)e1 / 9 + 21)));
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 = ceil((exp2 + ((float)e1 / 16 + 17)));
        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = ceil((exp2 + ((float)e1 / 4 + 19)));
            if (exp2 > 200) {
                exp2 = ceil((exp2 + ((float)e1 / 9 + 21)));
            }
        }
        else {
            exp2 = ceil((exp2 + ((float)e1 / 4 + 19)));
            exp2 = ceil((exp2 + ((float)e1 / 9 + 21)));
            if (exp2 > 400) {
                exp2 = ceil((exp2 + ((float)e1 / 16 + 17)));
                exp2 = ceil(((float)exp2 * 1.15));
            }
        }
        exp1 -= e1;
    }
    else {
        return -99;
    }
    determinedRangeEXP(exp1);
    determinedRangeEXP(exp2);

    return exp1 + exp2;
}

// Task 2
int squareNum(int exp1) {
    int a = sqrt(exp1);
    if (abs(exp1 - pow(a, 2)) > abs(exp1 - pow(a + 1, 2))) {
        return pow(a + 1, 2);
    }
    else {
        return pow(a, 2);
    }
}

void probability(int exp1, float& p) {
    int s = squareNum(exp1);
    if (exp1 >= s) {
        p = 100 / 100;
    }
    else {
        p = (float(exp1 / s) + 80) / 123;
    }
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 >= 0 && E2 <= 99) {
        float p1, p2, p3;

        probability(EXP1, p1);

        if (E2 % 2 != 0) {
            float m = M1 * 0.5;
            do
            {
                if (M1 <= 0) {
                    M1 = 0;
                    break;
                }
                if (HP1 < 200) {
                    HP1 = ceil(float((HP1 * 1.3)));
                    M1 -= 150;
                    determinedRangeHP(HP1);
                }
                else {
                    HP1 = ceil(float((HP1 * 1.1)));
                    M1 -= 70;
                    determinedRangeHP(HP1);
                }
                if (M1 < m) {
                    determinedRangeM(M1);
                    break;
                }

                if (EXP1 < 400) {
                    EXP1 = ceil(float((EXP1 * 1.13)));
                    M1 -= 200;
                    determinedRangeEXP(EXP1);
                }
                else {
                    EXP1 = ceil(float((EXP1 * 1.13)));
                    M1 -= 120;
                    determinedRangeEXP(EXP1);
                }
                if (M1 < m) {
                    break;
                }

                if (EXP1 < 300) {
                    M1 -= 100;
                    EXP1 = ceil(float((EXP1 * 0.9)));
                    determinedRangeEXP(EXP1);
                }
                else {
                    M1 -= 120;
                    EXP1 = ceil(float((EXP1 * 0.9)));
                    determinedRangeEXP(EXP1);
                }
                if (M1 < m) {
                    break;
                }
            } while (true);
            HP1 = ceil(float((HP1 * 0.83)));
            determinedRangeHP(HP1);
            EXP1 = ceil(float((EXP1 * 1.17)));
            determinedRangeEXP(EXP1);
            probability(EXP1, p2);
        }
        else {
            int j = 1;
            do
            {
                if (M1 <= 0) {
                    M1 = 0;
                    break;
                }
                if (HP1 < 200) {
                    HP1 = ceil(float((HP1 * 1.3)));
                    M1 -= 150;
                    determinedRangeHP(HP1);
                }
                else {
                    HP1 = ceil(float((HP1 * 1.1)));
                    M1 -= 70;
                    determinedRangeHP(HP1);
                }
                if (M1 <= 0) {
                    M1 = 0;
                    break;
                }

                if (EXP1 < 400) {
                    EXP1 = ceil(float((EXP1 * 1.13)));
                    M1 -= 200;
                    determinedRangeEXP(EXP1);
                }
                else {
                    EXP1 = ceil(float((EXP1 * 1.13)));
                    M1 -= 120;
                    determinedRangeEXP(EXP1);
                }
                if (M1 <= 0) {
                    M1 = 0;
                    break;
                }

                if (EXP1 < 300) {
                    M1 -= 100;
                    EXP1 = ceil(float((EXP1 * 0.9)));
                    determinedRangeEXP(EXP1);
                }
                else {
                    M1 -= 120;
                    EXP1 = ceil(float((EXP1 * 0.9)));
                    determinedRangeEXP(EXP1);
                }
                if (M1 <= 0) {
                    M1 = 0;
                    break;
                }
            } while (j != 1);
            HP1 = ceil(float((HP1 * 0.83)));
            determinedRangeHP(HP1);
            EXP1 = ceil(float((EXP1 * 1.17)));
            determinedRangeEXP(EXP1);
            probability(EXP1, p2);
        }

        int arrP[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        if (E2 >= 0 && E2 <= 9) {
            p3 = float(arrP[E2]) / 100;
        }
        else {
            int sumOfDigits = 0;
            for (int i = E2; i > 0; i /= 10) {
                sumOfDigits += i % 10;
            }
            E2 = sumOfDigits % 10;
            p3 = float(arrP[E2]) / 100;
        }

        if (p1 == 1 && p2 == 1 && p3 == 1) {
            EXP1 = ceil(float((EXP1 * 0.75)));
        }
        else {
            double averageP = (p1 + p2 + p3) / 3;
            if (averageP < 0.5) {
                HP1 = ceil(float((HP1 * 0.85)));
                EXP1 = ceil(float((EXP1 * 1.15)));
                determinedRangeEXP(EXP1);
                determinedRangeHP(HP1);
                determinedRangeM(M1);
            }
            else {
                HP1 = ceil(float((HP1 * 0.9)));
                EXP1 = ceil(float((EXP1 * 1.2)));
                determinedRangeEXP(EXP1);
                determinedRangeHP(HP1);
                determinedRangeM(M1);
            }
        }
    }
    else return -99;

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 >= 0 && E3 <= 99) {
        int matrix[10][10] = { 0 };
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }

        int pointi = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (matrix[i][j] > (E3 * 2)) {
                    pointi += 1;
                }
            }
        }
        while (pointi > 9)
        {
            int a = pointi;
            pointi = 0;
            for (int i = a; i > 0; i /= 10) {
                pointi += i % 10;
            }
        }

        int pointj = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (matrix[i][j] < (-E3)) {
                    pointj += 1;
                }
            }
        }
        while (pointj > 9)
        {
            int a = pointj;
            pointj = 0;
            for (int i = a; i > 0; i /= 10) {
                pointj += i % 10;
            }
        }

        int x1 = pointi, x2 = pointj, c = 0;
        int d[1000] = {0};
        d[c++] = matrix[pointi][pointj];
        while (x1 < 9 && x2 > 0)
        {
            x1 += 1;
            x2 -= 1;
            d[c++] = matrix[x1][x2];
        }
        int y1 = pointi, y2 = pointj;
        while (y1 > 0 && y2 < 9)
        {
            y1 -= 1;
            y2 += 1;
            d[c++] = matrix[y1][y2];
        }

        int z1 = pointi, z2 = pointj;
        while (z1 > 9  && z2 > 9)
        {
            z1 += 1;
            z2 += 1;
            d[c++] = matrix[z1][z2];
        }
        int t1 = pointi, t2 = pointj;
        while (t1 > 0 && t2 > 0)
        {
            t1 -= 1;
            t2 -= 1;
            d[c++] = matrix[t1][t2];
        }

        int positionSW = 0;
        for (int i = 0; i <= c; i++)
        {
            if (d[i] > positionSW) {
                positionSW = d[i];
            }
        }
        if (positionSW < 0) positionSW = abs(positionSW);

        if (abs(matrix[pointi][pointj]) > positionSW) {
            EXP1 = ceil(float(EXP1 * 0.88));
            HP1 = ceil(float(HP1 * 0.9));
            EXP2 = ceil(float(EXP2 * 0.88));
            HP2 = ceil(float(HP2 * 0.9));
            determinedRangeEXP(EXP1);
            determinedRangeEXP(EXP2);
            determinedRangeHP(HP1);
            determinedRangeHP(HP2);
            return matrix[pointi][pointj];
        }
        else {
            EXP1 = ceil(float(EXP1 * 1.12));
            HP1 = ceil(float(HP1 * 1.1));
            EXP2 = ceil(float(EXP2 * 1.12));
            HP2 = ceil(float(HP2 * 1.1));
            determinedRangeEXP(EXP1);
            determinedRangeEXP(EXP2);
            determinedRangeHP(HP1);
            determinedRangeHP(HP2);
            return positionSW;
        }
    }
    else return -99;

    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string se;
    string e(email);
    string passWord(s);
    string specialChars = "@#%$!";
    for (int i = 0; i < e.size(); i++) {
        if (e[i] == '@') {
            break;
        }
        else {
            se += e[i];
        }
    }

    if (passWord.size() < 8) {
        return -1;
    }
    if (passWord.size() > 20) {
        return -2;
    }

    size_t sei = passWord.find(se);
    if (sei != string::npos) {
        int position = sei;
        return -(300 + position);
    }

    for (int i = 0; i < passWord.size() - 2; i++) {
        if (passWord[i] == passWord[i + 1] && passWord[i + 1] == passWord[i + 2]) {
            return -(400 + i);
        }
    }

    int count = 0;
    for (int i = 0; i < specialChars.size(); i++) {
        for (int j = 0; j < passWord.size(); j++) {
            if (specialChars[i] == passWord[j]) {
                count += 1;
            }
        }
    }
    if (count == 0) {
        return -5;
    }

    for (int i = 0; i < passWord.size(); i++)
    {
        if (passWord[i] == '@' || passWord[i] == '#' || passWord[i] == '%' || passWord[i] == '$' || passWord[i] == '!') {
            continue;
        }
        else if (passWord[i] >= 'A' && passWord[i] <= 'Z' || passWord[i] >= 'a' && passWord[i] <= 'z' || passWord[i] >= '0' && passWord[i] <= '9') {
            continue;
        }
        else {
            return i;
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int index[1000] = {0};
    for (int i = 0; i < num_pwds; i++)
    {
        for (int j = 0; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                index[i] += 1;
            }
        }
    }

    int maxIndex = 0;
    for (int i = 1; i < num_pwds; i++)
    {
        if (index[i] > index[maxIndex]) {
            maxIndex = i;
        }
    }

    int positionMax[1000];
    int count = 0;
    for (int i = 0; i < num_pwds; i++) 
    {
        if (index[i] == index[maxIndex]) {
            positionMax[count++] = i;
        }
    }

    int max_length = 0;
    const char* correctPass = nullptr;
    for (int i = 0; i < count; i++) {
        int length = strlen(arr_pwds[positionMax[i]]);
        if (length > max_length) {
            max_length = length;
            correctPass = arr_pwds[positionMax[i]];
        }
    }

    for (int i = 0; i < num_pwds; i++) {
        if (strcmp(arr_pwds[i], correctPass) == 0) {
            return i;
        }
    }

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////