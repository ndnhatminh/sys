

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

//check formulla
int check(int & object, int first, int last) {
    if (object < first) object = first;
    if (object > last) object = last;
    return object;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    
    //check initial conditions
    check(exp1, 0, 600);
    check(exp2, 0, 600);
    
    if ( e1 < 0 || e1 > 99){
        return -99;
    }else{
        if (e1 >= 0 && e1 <= 3) {
            switch (e1) {
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
            int D = e1 * 3 + exp1 * 7;
            if (D & 1) {
                exp1 = ceil(exp1 - D * 1.0000 / 100);
            }
            else exp1 = ceil(exp1 + D * 1.0000 / 200);
            check(exp1, 0, 600);
            check(exp2, 0, 600);
        }
        if (e1 >= 4 && e1 <= 99) {
            float observe1 = e1 * 1.000 / 4 + 19;
            float observe2 = e1 * 1.000 / 9 + 21;
            float observe3 = e1 * 1.000 / 16 + 17;
            if (e1 <= 19) {
                exp2 = ceil(exp2 + observe1);
                check(exp2, 0, 600);
            }
            else if (e1 <= 49) {
                exp2 = ceil(exp2 + observe2);
                check(exp2, 0, 600);
            }
            else if (e1 <= 65) {
                exp2 = ceil(exp2 + observe3);
                check(exp2, 0, 600);
            }
            else if (e1 <= 79) {
                exp2 = ceil(exp2 + observe1);
                check(exp2, 0, 600);
                if (exp2 > 200) exp2 = ceil(exp2 + observe2);
                check(exp2, 0, 600);
            }
            else if (e1 <= 99) {
                exp2 = ceil(exp2 + observe1);
                check(exp2, 0, 600);
                exp2 = ceil(exp2 + observe2);
                check(exp2, 0, 600);
                if (exp2 > 400) {
                    exp2 = ceil(exp2 + observe3);
                    check(exp2, 0, 600);
                    exp2 = ceil(exp2 * 1.15);
                    check(exp2, 0, 600);
                }
            }
            exp1 -= e1;
            check(exp1, 0, 600);
        }
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    
    //check initial conditions
    check(M1, 0, 3000);
    check(HP1, 0, 666);
    check(EXP1, 0, 600);
    if (E3 < 0 || E3 > 99){
        return -99;
    }
    else {

        //road 1
        float S = pow(round(sqrt(EXP1)), 2);
        float p1;
        if (EXP1 >= S) {
            p1 = 1;
        }
        else p1 = (EXP1 * 1.000 / S + 80) / 123;
        
        //road 2
        float m1i = M1 * 1.0000 / 2;
        int expense = 0;
        if (E3 & 1) {
            while (expense <= m1i) {
                if (HP1 < 200) {
                    HP1 = ceil(HP1 * 130.0000 / 100);
                    M1 -= 150;
                    expense += 150;
                    check(M1, 0, 3000);
                    check(HP1, 0, 666);
                }
                else {
                    HP1 = ceil(HP1 * 110.0000 / 100);
                    M1 -= 70;
                    expense += 70;
                    check(M1, 0, 3000);
                    check(HP1, 0, 666);
                }
                if (expense > m1i) break;
                if (EXP1 < 400) {
                    M1 -= 200;
                    expense += 200;
                }
                else { 
                    M1 -= 120;
                    expense += 120;
                }
                EXP1 = ceil(EXP1 * 113.0000 / 100);
                check(M1, 0, 3000);
                check(EXP1, 0, 600);
                if (expense > m1i) break;
                if (EXP1 < 300) {
                    M1 -= 100;
                    expense += 100;
                }
                else {
                    M1 -= 120;
                    expense += 120;
                }
                EXP1 = ceil(EXP1 * 90.0000 / 100);
                check(M1, 0, 3000);
                check(EXP1, 0, 600);
                if (expense > m1i) break;
            }
            HP1 = ceil(HP1 * 83.0000 / 100);
            EXP1 = ceil(EXP1 * 117.0000 / 100);
            check(EXP1, 0, 600);
            check(HP1, 0, 666);
        }
        else {
            if (HP1 < 200) {
                HP1 = ceil(HP1 * 130.0000 / 100);
                M1 -= 150;
                check(M1, 0, 3000);
                check(HP1, 0, 666);
            }
            else {
                HP1 = ceil(HP1 * 110.0000 / 100);
                M1 -= 70;
                check(M1, 0, 3000);
                check(HP1, 0, 666);
            }
            if (M1 > 0){
                if (EXP1 < 400) {
                M1 -= 200;
                }
                else M1 -= 120;
                EXP1 = ceil(EXP1 * 113.0000 / 100);
                check(M1, 0, 3000);
                check(EXP1, 0, 600);
                if (M1 > 0) {
                    if (EXP1 < 300) {
                    M1 -= 100;
                    }
                    else M1 -= 120;
                    EXP1 = ceil(EXP1 * 90.0000 / 100);
                    check(M1, 0, 3000);
                    check(EXP1, 0, 600);
                }
            }
            HP1 = ceil(HP1 * 83.0000 / 100);
            EXP1 = ceil(EXP1 * 117.0000 / 100);
            check(EXP1, 0, 600);
            check(HP1, 0, 666);
        }
        S = pow(round(sqrt(EXP1)), 2);
        float p2;
        if (EXP1 >= S) {
            p2 = 1;
        }
        else p2 = (EXP1 * 1.000 / S + 80) / 123;
        
        //road 3
        int p[10] = { 32,47,28,79,100,50,22,83,64,11 };
        int p3;
        if (E3 % 10 == E3) {
            int i = E3;
            p3 = p[i];
        }
        else {
            int a = E3 % 10;
            int b = (E3 - a) / 10;
            int i = (a + b) % 10;
            p3 = p[i];
        }
        
        //at the end of the road
        p1 *= 100;
        p2 *= 100;
        if (p1 == p2 && p2 == p3 && p3 == 100) {
            EXP1 = ceil(EXP1 * 75.0000 / 100);
            check(EXP1, 0, 600);
        }
        else {
            float P = (p1 + p2 + p3) * 1.0000 / 3;
            if (P < 50) {
                HP1 = ceil(HP1 * 85.0000 / 100);
                EXP1 = ceil(EXP1 * 115.0000 / 100);
                check(EXP1, 0, 600);
                check(HP1, 0, 666);
            }
            else {
                HP1 = ceil(HP1 * 90.0000 / 100);
                EXP1 = ceil(EXP1 * 120.0000 / 100);
                check(EXP1, 0, 600);
                check(HP1, 0, 666);
            }
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    
    //check initial conditions
    check(EXP1, 0, 600);
    check(HP1, 0, 666);
    check(EXP2, 0, 600);
    check(HP2, 0, 666);

    if  (E3 < 0 || E3 > 99){
        return -99;
    }else{
        int taxiMatrix[10][10];
        int i, j;
        
        //find taxi points and position
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                taxiMatrix[i][j] = (E3 * j + (i * 2)) * (i - j);
            }
        }
        int countGreater = 0, countLesser = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (taxiMatrix[i][j] > E3 * 2) countGreater++;
                if (taxiMatrix[i][j] < -E3) countLesser++;
            }
        }
        i = countGreater;
        j = countLesser;
        while (i % 10 != i) {
            int a = i % 10;
            int b = (i - a) / 10;
            i = a + b;
        }
        while (j % 10 != j) {
            int a = j % 10;
            int b = (j - a) / 10;
            j = a + b;
        }

        //find Sherlock and Watson points
        int temp = taxiMatrix[i][j];
        int jtest1 = j;
        int jtest2 = j;
        int jtest3 = j;
        int jtest4 = j;
        
        for (int a = i; a >= 0; a--) {
            if (temp < taxiMatrix[a][jtest1]) temp = taxiMatrix[a][jtest1];
            jtest1--;
            if (jtest1 < 0) break;
        }
        for (int a = i; a <= 9; a++) {
            if (temp < taxiMatrix[a][jtest2]) temp = taxiMatrix[a][jtest2];
            jtest2--;
            if (jtest2 < 0) break;
        }
        for (int a = i; a <= 9; a++) {
            if (temp < taxiMatrix[a][jtest3]) temp = taxiMatrix[a][jtest3];
            jtest3++;
            if (jtest3 > 9) break;
        }
        for (int a = i; a >= 0; a--) {
            if (temp < taxiMatrix[a][jtest4]) temp = taxiMatrix[a][jtest4];
            jtest4++;
            if (jtest4 > 9) break;
        }
        
        //compare the points and update the HPs and EXPs value
        if (abs(taxiMatrix[i][j]) > temp) {
            EXP1 = ceil(EXP1 * 88.0000 / 100);
            HP1 = ceil(HP1 * 90.0000 / 100);
            EXP2 = ceil(EXP2 * 88.0000 / 100);
            HP2 = ceil(HP2 * 90.0000 / 100);
            check(EXP1, 0, 600);
            check(HP1, 0, 666);
            check(EXP2, 0, 600);
            check(HP2, 0, 666);
            return taxiMatrix[i][j];
        }
        else {
            EXP1 = ceil(EXP1 * 112.0000 / 100);
            HP1 = ceil(HP1 * 110.0000 / 100);
            EXP2 = ceil(EXP2 * 112.0000 / 100);
            HP2 = ceil(HP2 * 110.0000 / 100);
            check(EXP1, 0, 600);
            check(HP1, 0, 666);
            check(EXP2, 0, 600);
            check(HP2, 0, 666);
            return temp;
        }
        return -1;
    }    
}

// Task 4
int checkPassword(const char * s, const char * email) {
    
    //create se
    size_t chrPos = strchr(email, '@') - email;
    char se[101];
    strncpy(se, email, chrPos);
    se[chrPos] = '\0';

    //check the password length
    size_t slength = strlen(s);
    if (slength < 8) return -1;
    if (slength > 20) return -2;

    //check if password contain se
    const char* sePos = strstr(s, se);
    if (sePos != nullptr) return -(300 + (sePos - s));

    //check if there are consecutive and identical chars
    for (size_t i = 0; i < slength - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) return -(400 + i);
    }
    
    // check if there are special chars in password
    const char* specialchr = "@#%$!";
    if (strpbrk(s, specialchr) == nullptr) return -5;

    //check for valid password
    for (size_t i = 0; i < slength; i++) {
        if (!isalnum(s[i]) && strchr(specialchr, s[i]) == nullptr) return i;
    }
    return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int count_max = 0;
    int length_max = 0;
    int rightpwds = -1;
    for (int i = 0; i < num_pwds; i++) {
        int pwdslength = strlen(arr_pwds[i]);
        int count_pwds = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count_pwds++;
            }
        }
        if (count_pwds > count_max || (count_pwds == count_max && pwdslength > length_max)) {
            count_max = count_pwds;
            length_max = pwdslength;
            rightpwds = i;
        }
    }
    return rightpwds;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////