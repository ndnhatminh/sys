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
int limitcheck(int a, int b) {
    if (a > b) a = b;
    else if (a < 0) a = 0;
    return a;
}
int checkvalueintegerornot(float n) {
    bool a; 
    if (n != ceil(n)) a = 0;
    else a = 1;
    return a;
}
float percentageintask2(int w1) {
    float p1;
    int d = w1;
    int check1;
    int check2;
    for (int i = 0; i <= 900;i++) {
        float b = (float)sqrt(i);
        int a = checkvalueintegerornot(b);
        if (a == 1) {
            check1 = i;
        }
        if (abs(w1 - check1) < d) {
            d = abs(w1 - check1);
            check2 = check1;
        }
    }
    if (w1 >= check2) p1 = 1;
    else p1 = ((430 / check2) + 80) / 123.0;
    p1 = ceil(p1 * 100);
    return p1;
}
int checkinglimitintask3(int a, int b) {
    int c = 1;
    if (a == 0 || b == 0 || a == 9 || b == 9) c = 1;
    else c = 0;
    return c;
}
int sumof2numberletters(int a) {
    int b = a / 10 + a % 10;
    int c = b / 10 + b % 10;
    return c;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    exp1 = limitcheck(exp1, 600);
    exp2 = limitcheck(exp2, 600);
    if (e1 < 0 || e1 > 99) return -99;
    else {
        if (e1 >= 0 && e1 <= 3) {
            if (e1 == 0)	exp2 = exp2 + 29;
            else if (e1 == 1)	exp2 = exp2 + 45;
            else if (e1 == 2)	exp2 = exp2 + 75;
            else exp2 = exp2 + 29 + 45 + 75;
            exp1 = limitcheck(exp1, 600);
            exp2 = limitcheck(exp2, 600);
            int D;
            D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0) exp1 = ceil(exp1 + D / 200.0);
            else exp1 = ceil(exp1 - D / 100);
        }
        else if (e1 >= 4 && e1 <= 19) exp2 = ceil(exp2 + (e1 / 4.0) + 19);
        else if (e1 >= 20 && e1 <= 49) exp2 = ceil(exp2 + (e1 / 9.0) + 21);
        else if (e1 >= 50 && e1 <= 65) exp2 = ceil(exp2 + e1 / 16.0 + 17);
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);
            exp2 = limitcheck(exp2, 600);
            if (exp2 > 200) exp2 = ceil(exp2 + e1 / 9.0 + 21);
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);
            exp2 = limitcheck(exp2, 600);
            exp2 = ceil(exp2 + e1 / 9.0 + 21);
            exp2 = limitcheck(exp2, 600);
            if (exp2 > 400) {
                exp2 = ceil(exp2 + e1 / 16.0 + 17);
                exp2 = limitcheck(exp2, 600);
                exp2 = ceil(exp2 + 0.15 * exp2);
            }
        }
        if (e1 >= 4 && e1 <= 99) exp1 = exp1 - e1;
        exp1 = limitcheck(exp1, 600);
        exp2 = limitcheck(exp2, 600);
        return exp1 + exp2;
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // the first way
    if (E2 < 0 || E2 > 99) return -99;
    else {
        EXP1 = limitcheck(EXP1, 600);
        HP1 = limitcheck(HP1, 666);
        M1 = limitcheck(M1, 3000);
        float way1 = percentageintask2(EXP1);
        way1 = way1 / 100;

        // The second way
        EXP1 = limitcheck(EXP1, 600);
        HP1 = limitcheck(HP1, 666);
        int a = 1;
        int money = M1 / 2;
        int money2 = 0;
        if (E2 % 2 == 1) {
            for (int i = 1; i <= 100; i++) {
                switch (a) {
                case 1:
                    if (money2 > money) break;
                    else {
                        if (HP1 < 200) {
                            HP1 = ceil(HP1 * 1.3);
                            money2 = money2 + 150;
                        }
                        else {
                            HP1 = ceil(HP1 * 1.1);
                            money2 = money2 + 70;
                        }
                        a = 2;
                    }
                    EXP1 = limitcheck(EXP1, 600);
                    HP1 = limitcheck(HP1, 666);
                case 2:
                    if (money2 > money) break;
                    else {
                        if (EXP1 < 400) {
                            money2 = money2 + 200;
                        }
                        else money2 = money2 + 120;
                        EXP1 = ceil(EXP1 * 1.13);
                        a = 3;
                    }
                    EXP1 = limitcheck(EXP1, 600);
                    HP1 = limitcheck(HP1, 666);
                case 3:
                    if (money2 > money) break;
                    else {
                        if (EXP1 < 300) money2 = money2 + 100;
                        else money2 = money2 + 120;
                        EXP1 = ceil(EXP1 * 0.9);
                        a = 1;
                    }
                    EXP1 = limitcheck(EXP1, 600);
                    HP1 = limitcheck(HP1, 666);
                }
            }

            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            EXP1 = limitcheck(EXP1, 600);
            HP1 = limitcheck(HP1, 666);
        }
        else {
            if (money2 > M1);
            else {
                if (HP1 < 200) {
                    HP1 = ceil(HP1 * 1.3);
                    money2 = money2 + 150;
                }
                else {
                    HP1 = ceil(HP1 * 1.1);
                    money2 = money2 + 70;
                }
            }
            EXP1 = limitcheck(EXP1, 600);
            HP1 = limitcheck(HP1, 666);
            if (money2 > M1);
            else {
                if (EXP1 < 400) {
                    money2 = money2 + 200;
                }
                else money2 = money2 + 120;
                EXP1 = ceil(EXP1 * 1.13);
            }
            EXP1 = limitcheck(EXP1, 600);
            HP1 = limitcheck(HP1, 666);
            if (money2 > M1);
            else {
                if (EXP1 < 300) money2 = money2 + 100;
                else money2 = money2 + 120;
                EXP1 = ceil(EXP1 * 0.9);
            }
            EXP1 = limitcheck(EXP1, 600);
            HP1 = limitcheck(HP1, 666);
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            EXP1 = limitcheck(EXP1, 600);
            HP1 = limitcheck(HP1, 666);
        }
        float way2 = percentageintask2(EXP1);
        way2 = way2 / 100;
        M1 = M1 - money2;
        M1 = limitcheck(M1, 3000);
        // the third way
        EXP1 = limitcheck(EXP1, 600);
        HP1 = limitcheck(HP1, 666);
        float P3;
        int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        if (E2 / 10 == 0) {
            P3 = P[E2];
        }
        else {
            int valueI = E2 / 10 + E2 % 10;
            P3 = P[valueI % 10] / 100.0;
        }
        // General
        float way = (way1 + way2 + P3) / 3;
        if (way1 == 1 && way2 == 1 && P3 == 1) {
            EXP1 = ceil(EXP1 * 0.75);
        }
        else if (way < 0.5) {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        }
        else {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
        }
        EXP1 = limitcheck(EXP1, 600);
        HP1 = limitcheck(HP1, 666);
        return HP1 + EXP1 + M1;
    }
}
// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    else {
        EXP1 = limitcheck(EXP1, 600);
        HP1 = limitcheck(HP1, 666);
        EXP2 = limitcheck(EXP2, 600);
        HP2 = limitcheck(HP2, 666);
        int map[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        int taxi;
        int a = 0;
        int b = 0;
        // a is greater than E2*2
        // b is smaller than -E2
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (map[i][j] > (E3 * 2)) a = a + 1;
                else if (map[i][j] < (-E3)) b = b + 1;
            }
        }

        taxi = map[sumof2numberletters(a)][sumof2numberletters(b)];
        int HolmesLocation = taxi;



        for (int i = sumof2numberletters(a), j = sumof2numberletters(b); i <= 9 && j <= 9; i++, j++) {
            if (map[i][j] > HolmesLocation) HolmesLocation = map[i][j];
            if (checkinglimitintask3(i, j) == 1) break;
        }
        for (int i = sumof2numberletters(a), j = sumof2numberletters(b); i >= 0 && j >= 0; i--, j--) {
            if (map[i][j] > HolmesLocation) HolmesLocation = map[i][j];
            if (checkinglimitintask3(i, j) == 1) break;
        }
        for (int i = sumof2numberletters(a), j = sumof2numberletters(b); i <= 9 && j >= 0; i++, j--) {
            if (map[i][j] > HolmesLocation) HolmesLocation = map[i][j];
            if (checkinglimitintask3(i, j) == 1) break;
        }
        for (int i = sumof2numberletters(a), j = sumof2numberletters(b); i >= 0 && j <= 9; i--, j++) {
            if (map[i][j] > HolmesLocation) HolmesLocation = map[i][j];
            if (checkinglimitintask3(i, j) == 1) break;
        }
        int k;
        if (abs(HolmesLocation) > abs(taxi)) {
            HP1 = ceil(HP1 * 1.1);
            EXP1 = ceil(EXP1 * 1.12);
            HP2 = ceil(HP2 * 1.1);
            EXP2 = ceil(EXP2 * 1.12);
            k = HolmesLocation;
        }
        else {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 0.88);
            HP2 = ceil(HP2 * 0.9);
            EXP2 = ceil(EXP2 * 0.88);
            k = taxi;
        }
        EXP1 = limitcheck(EXP1, 600);
        HP1 = limitcheck(HP1, 666);
        EXP2 = limitcheck(EXP2, 600);
        HP2 = limitcheck(HP2, 666);
        return k;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    //Finding the length
    long count2 ;
    //address of @
    int address;
    count2 = strlen(email);
    for (int i = 0; i < count2; i++) {
        if (email[i] == '@') {
            address = i;
            break;
        }   
    }
    long count1;
    count1 = strlen(s);
    int j = 0;
    int a = 0;
    bool b=0;
    int checktask4=0;
    for (int i = 0; i < count1;i++) {
        if (s[i] == s[i + 1]) {
            a = i;
            b = 1;
            break;
        }
    }
    bool c = 0;
    for (int i = 0; i < count1;i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '!' || s[i] == '$' || s[i] == '%') {
            c = 1;
            break;
        }
    }
    bool address1 = 0;
    int address2 = 0;
    int ad = 0;
    for (int i = 0; i < count1; i++) {
        if (ad == address) {
            address1 = 1;
            address2 = i - ad;
            break;
        }
        if (s[i] == email[ad]) ad = ad + 1;
    }
    if (count1 < 7) checktask4 = -1;
    else if (count1 > 20) checktask4 = -2;
    else if (address1 == 1) {
        
                checktask4 = -(300 + address2);
    
    }
    else if (b == 1) {
        for (int i = 0; i < count1;i++) {
            if (s[i] == s[i + 1]) {
                checktask4 = -(400 + i);
                break;
            }
        }
    }
    else if (c = 0) checktask4 = -5;
    else checktask4 =  -10;
    return checktask4;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int a[100];
    for (int i = 0; i < 100;i++) {
        a[i] = 0;
    }
    // counting how many of each password;
    for (int i = 0; i < num_pwds;i++) {
        for (int j = 0; j < num_pwds;j++) {
            if (arr_pwds[i] == arr_pwds[j]) a[i] = a[i] +1;
        }
    }
    //find out what appeare the most
    int b = a[0];
    int c;
    for (int i = 0; i < 100;i++) {
        if (a[i] > b) {
            b = a[i];
            c = i;
        }
    }
    // find out if same quantity
    for (int i = 0; i < 100;i++) {
        if (a[i] == b) {
            if (strlen(arr_pwds[i]) > strlen(arr_pwds[c])) {
                c = i;
                break;
           }
        }
    }
    return c;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
