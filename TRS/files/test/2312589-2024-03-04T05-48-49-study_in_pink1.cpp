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
void check(int &HP, int &EXP, int &M) {
    if (HP > 666) {
        HP = 666;
    }
    if (HP < 0) {
        HP = 0;
    }
    if (EXP > 600) {
        EXP = 600;
    }
    if (EXP < 0) {
        EXP = 0;
    }
    if (M > 3000) {
        M = 3000;
    }
    if (M < 0) {
        M = 0;
    }
}
void walkAlone(int& EXP, double &P) {;
    int square = 0;
    for (int i = 1; (i - 1) * (i - 1) <= EXP; i++) {
        if (abs(EXP - i * i) <= abs(EXP - (i + 1) * (i + 1)) && abs(EXP - (i + 1) * (i + 1)) < abs(EXP - (i + 2) * (i + 2))) {
            square = i * i;
            break;
        }
    }
    P = (( EXP / square * 1.0) + 80) / 123;
    P *= 100;
}
void maxnumber(int& indexi, int& indexj, int &E3, int &biggest) {
    int matrix[10][10] = { 0 };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int ii = indexi;
    int ij = indexj;
    while (ii >= 0 && ij >= 0) {
        if (matrix[ii][ij]>biggest) {
            biggest = matrix[ii][ij];
        }
        ii--;
        ij--;
    }
    ii = indexi;
    ij = indexj;
    while (ii >= 0 && ij < 10) {
        if (matrix[ii][ij] > biggest) {
            biggest = matrix[ii][ij];
        }
        ii--;
        ij++;
    }
    ii = indexi;
    ij = indexj;
    while (ii < 10 && ij >= 0) {
        if (matrix[ii][ij] > biggest) {
            biggest = matrix[ii][ij];
        }
        ii++;
        ij--;
    }
    ii = indexi;
    ij = indexj;
    while (ii <10 && ij <10 ) {
        if (matrix[ii][ij] > biggest) {
            biggest = matrix[ii][ij];
        }
        ii++;
        ij++;
    }
}

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int hp1, hp2, m1, m2;
    if (e1 < 0 || e1 >99)
        return -99;
    else if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) {
            exp2 += 29;
        }
        if (e1 == 1) {
            exp2 += 45;
        }
        if (e1 == 2) {
            exp2 += 75;
        }
        if (e1 == 3) {
            exp2 += 149;
        }
        int d = 3 * e1 + 7 * exp1;
        if (d % 2 == 0) {
            exp1 += (int)ceil(d / 200.0);
            exp1 = (int)ceil(exp1);
        }
        if (d % 2 != 0) {
            exp1 -= (int)round(d / 100.0);
        }
    }
    else if (4 <= e1 && e1 <= 99) {
        if (4 <= e1 && e1 <= 19) {
            exp2 += (int)ceil(e1 / 4.0 + 19);
        }
        if (20 <= e1 && e1 <= 49) {
            exp2 += (int)ceil(e1 / 9.0 + 21);
        }
        if (50 <= e1 && e1 >= 65) {
            exp2 += (int)ceil(e1 / 16.0 + 17);
        }
        if (66 <= e1 && e1 <= 79) {
            exp2 += (int)ceil(e1 / 4.0 + 19);
            if (exp2 > 200) {
                exp2 += (int)ceil(e1 / 9.0 + 21);
            }
        }
        if (80 <= e1 && e1 <= 99) {
            exp2 += (int)ceil(e1 / 4.0 + 19);
            exp2 += (int)ceil(e1 / 9.0 + 21);
            if (exp2 > 400) {
                exp2 += (int)ceil(e1 / 16.0 + 17);
            }
            exp2 *= (int)ceil(exp2 * 1.15);
        }
        exp1 -= e1;
    }
    check(hp1, exp1, m1);
    check(hp2, exp2, m2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int square = 0;
    for (int i = 1; (i - 1) * (i - 1) <= square; i++) {
        if (abs(EXP1 - i * i) <= abs(EXP1 - (i + 1) * (i + 1)) && abs(EXP1 - (i + 1) * (i + 1)) < abs(EXP1 - (i + 2) * (i + 2))) {
            square = i * i;
            break;
        }
    }
    double P1 = 0; double P2 = 0; double P3 = 0;
    if (EXP1 >= square) {
        P1 = 100;
    }
    else {
        P1 = (EXP1 / square * 1.0 + 80) / 123;
    }
    int spend = 0;
    if (E2 % 2 == 1) {
        while (spend <= (double)M1 / 2.0) {
            if (M1 == 0) {
                break;
            }
            if (spend <= (double)M1 / 2.0) {
                if (HP1 < 200) {
                    spend += 150;
                    HP1 = (int)ceil(HP1 * 1.3);
                    check(HP1, EXP1, M1);
                }
                else if (HP1 >= 200) {
                    spend += 70;
                    HP1 = (int)ceil(HP1 * 1.1);
                    check(HP1, EXP1, M1);
                }
            }
            if (spend <= (double)M1 / 2.0) {
                if (EXP1 < 400) {
                    spend += 200;
                }
                else if (EXP1 >= 400) {
                    spend += 120;
                }
                EXP1 = (int)ceil(EXP1 * 1.13);
                check(HP1, EXP1, M1);
            }
            if (spend <= (double)M1 / 2.0) {
                if (EXP1 < 300) {
                    spend += 100;
                }
                else if (EXP1 >= 300) {
                    spend += 120;
                }
                EXP1 = (int)ceil(EXP1 * 0.9);
            }
        }
        walkAlone(EXP1, P2);
        M1 -= spend;
        HP1 = (int)ceil(HP1 * 0.83);
        EXP1 = (int)ceil(EXP1 * 1.17);
        check(HP1, EXP1, M1);
    }
    else if (E2 % 2 == 0){
        if (M1 == 0) {
            walkAlone(EXP1, P2);
            spend = M1 + 1;
        }
        int count = 0;
        if (spend <= M1) {
            if (HP1 < 200) {
                spend += 150;
                HP1 = (int)ceil(HP1 * 1.3);
            }
            else if (HP1 >= 200) {
                spend += 70;
                HP1 = (int)ceil(HP1 * 1.1);
            }
            count++;
        }
        else walkAlone(EXP1, P2);
        check(HP1, EXP1, M1);
        if (spend <= M1) {
            if (EXP1 < 400) {
                spend += 200;
            }
            else if (EXP1 >= 400) {
                spend += 120;
            }
            EXP1 = (int)ceil(EXP1 * 1.13);
            count++;
        }
        else walkAlone(EXP1, P2);
        if (spend <= M1) {
            if (EXP1 < 300) {
                spend += 100;
            }
            else if (EXP1 >= 300) {
                spend += 120;
            }
            count++;
            EXP1 = (int)ceil(EXP1 * 0.9);
        }
        else walkAlone(EXP1, P2);
        if (count == 3) {
            walkAlone(EXP1, P2);    
        }
        M1 -= spend;
        HP1 = (int)ceil(HP1 * 0.83);
        EXP1 = (int)ceil(EXP1 * 1.17);
        check(HP1, EXP1, M1);
    }
    int Percentage[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int index = 0;
    if (E2 < 10) {
        P3 = Percentage[E2];
    }
    else if (E2 >= 10) {
        index = E2;
        while (index >= 10) {
            index = index % 10 + index / 10;
        }
        P3 = Percentage[index];      
    }
    if (P1 == 100 && P2 == 100 && P3 == 100) {
        EXP1 = (int)ceil(EXP1 * 0.75);
    }
    else {
        double average = 0;
        average = (P1 + P2 + P3) / 3;
        if (average < 50) {
            HP1 = (int)ceil(HP1 * 0.85);
            EXP1 = (int)ceil(EXP1 * 1.15);
        }
        else if (average >= 50) {
            HP1 = (int)ceil(HP1 * 0.9);
            EXP1 = (int)ceil(EXP1 * 1.2);
        }
    }
    check(HP1, EXP1, M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int matrix[10][10] = { 0 };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int counti = 0;
    int countj = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (matrix[i][j] > E3 * 2) {
                counti++;
            }
            if (matrix[i][j] < 0 - E3) {
                countj++;
            }
        }
    }
    int indexi = counti;
    int indexj = countj;
    while (indexi >= 10) {
        indexi = indexi / 10 + indexi % 10;
    }
    while (indexj >= 10) {
        indexj = indexj / 10 + indexj % 10;
    }
    int biggest = 0;
    maxnumber(indexi, indexj, E3, biggest);
    if (biggest >= abs(matrix[indexi][indexj])) {
        EXP1 = (int)ceil(EXP1 * 1.12);
        EXP2 = (int)ceil(EXP2 * 1.12);
        HP1 = (int)ceil(HP1 * 1.1);
        HP2 = (int)ceil(HP2 * 1.1);
    }
    else {
        EXP1 = (int)ceil(EXP1 * 0.88);
        EXP2 = (int)ceil(EXP2 * 0.88);
        HP1 = (int)ceil(HP1 * 0.9);
        HP2 = (int)ceil(HP2 * 0.9);
    }
    if (biggest >= abs(matrix[indexi][indexj])) {
        return biggest;
    }
    else {
        return matrix[indexi][indexj];
    }
    return -1;
}

// Task 4
bool valid(const char* s, const char* se, int lengthse) {
    if (strlen(s) < 8) {
        return 0;
    }
    if (strlen(s) > 20) {
        return 0;
    }
    int dem = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            dem++;
        }
    }
    if (dem < 1) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == se[0]) {
            for (int j = 0; j < lengthse; j++) {
                if (s[j] == se[j]) {
                    count++;
                }
            }
            if (count == lengthse) {
                return 0;
            }
        }
    }
    for (int i = 0; i < strlen(s); i++) {
        if ((s[i] == 34) || (38 <= s[i] && s[i] <= 47) || (58 <= s[i] && s[i] <= 63) || (91 <= s[i] && s[i] <= 96) || (123 <= s[i] && s[i] <= 126)) {
            return 0;
        }
    }
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            return 0;
        }
    }

    return 1;
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int count = 0;
    int counta = 0;
    int index = 0;
    int lengthse = 0;
    char se[79] = { 0 };
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == 64) {
            index = i;
            counta++;
        }
    }
    lengthse = index;
    if (counta == 1) {
        for (int i = 0; i < index; i++) {
            se[i] = email[i];
        }
    }
    if (strlen(s) < 8) {
        return -1;
    }
    else if (strlen(s) > 20) {
        return -2;
    }
    for (int i = 0; i < strlen(s); i++) {
        int countb = 0;
        if (s[i] == se[0]) {
            for (int j = 0; j < lengthse; j++) {
                if (s[i+j] == se[j]) {
                    countb++;
                }
            }
            if (countb == lengthse) {
                return -(300+i);
            }
        }
    }
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            return -(400+i);
        }
    }
    int dem = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            dem++;
        }
    }
    if (dem < 1) {
        return -5;
    }
    if (valid(s, email, lengthse)) {
        return -10;
    }

    return -99;
}

// Task 5

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int count[30] = {1};
    int index = 0;
    int biggest = 0;
    int dem = 0;
    for (int i = 0; i < num_pwds; i++) {
        for (int j = 1; j < num_pwds; j++) {
                if (arr_pwds[i] == arr_pwds[j]) {
                    count[i]++;
            }
        }
        //
    }
    for (int i = 0; i < num_pwds; i++) {
        if (biggest <= count[i]) {
            biggest = count[i];
        }
    }
    int dema = 0;
    int demb = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (count[i] == biggest) {
            for (int j = i+1; j < num_pwds; j++) {
                if (arr_pwds[i] == arr_pwds[j]) {
                    dema++;
                }
                else if (arr_pwds[i] != arr_pwds[j] && count[j] == biggest) {
                    demb++;
                }
            }
        }
    }
    if (dema == biggest && demb == 0) {
        for (int i = 0; i < num_pwds; i++) {
            if (biggest == count[i]) {
                index = i;
                return index;
                break;
            }
        }
    }
    else if (dema == biggest && demb != 0) {
        for (int i = 0; i < num_pwds; i++) {
            if (biggest == count[i]) {
                for (int j=i+1; j < num_pwds; j++) {
                    if (strlen(arr_pwds[i]) < strlen(arr_pwds[j])&&count[i]==biggest&&count[j]==biggest) {
                        index = j;
                        break;
                    }
                }
            }    
        }
        return index;
    }
//    return value;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////