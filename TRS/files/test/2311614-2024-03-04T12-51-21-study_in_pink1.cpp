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
int processing(int min, int max, int value) {
    if (value < min) value = min;
    if (value > max) value = max;
    return value;
}
bool range(int val, int min, int max) {
    return (val >= min && val <= max);
}
int firstMeet(int & exp1, int & exp2, int e1){
    exp1 = processing(0, 600, exp1);
    exp2 = processing(0, 600, exp2);
    if (e1 < 0 || e1>99) return -99;
    else {
        if (e1 >= 0 && e1 <= 3)
        {
            switch (e1) {
            case 0: exp2 += 29; break;
            case 1: exp2 += 45; break;
            case 2: exp2 += 75; break;
            case 3: exp2 += 149; break;
            }
            exp1 = processing(0, 600, exp1);
            exp2 = processing(0, 600, exp2);
            int D = e1 * 3 + exp1 * 7;
            if (D % 2 == 1) {
                exp1 = ceil(exp1 - D / 100.0-0.00001);
                exp1 = processing(0, 600, exp1);
            }
            else {
                exp1=exp1 + ceil(D/200.0-0.000001);
                exp1 = processing(0, 600, exp1);
            }
            exp1 = processing(0, 600, exp1);
            exp2 = processing(0, 600, exp2);
        }
        if (e1 >= 4 && e1 <= 99) {
            if (range(e1, 4, 19)) exp2 = ceil(exp2 + e1 / 4.0 + 19-0.000001);
            if (range(e1, 20, 49)) exp2 = ceil(exp2 + e1 / 9.0 + 21-0.00001);
            if (range(e1, 50, 65)) exp2 = ceil(exp2 + e1 / 16.0 + 17-0.000001);
            if (range(e1, 66, 79)) {
                exp2 = ceil(exp2 + e1 / 4.0 + 19-0.0000001);
                if (exp2 > 200) exp2 = ceil(exp2 + e1 / 9.0 + 21-0.000001);
            }
            if (range(e1, 80, 99)) {
                exp2 = ceil(exp2 + e1 / 4.0 + 19-0.000001);
                exp2 = ceil(exp2 + e1 / 9.0 + 21-0.000001);
                if (exp2 > 400) {
                    exp2 = ceil(exp2 + e1 / 16.0 + 17-0.000001);
                    exp2 = ceil(exp2 * 1.15-0.000001);
                }
            }
            exp1 -= e1;
            exp1 = processing(0, 600, exp1);
            exp2 = processing(0, 600, exp2);
            
        }
        exp1 = processing(0, 600, exp1);
        exp2 = processing(0, 600, exp2);
            
        return exp1 + exp2;
    }
}

// Task 2
double road1(int& EXP1) {
    EXP1 = processing(0, 600, EXP1);
    double S = 0; double P1 = 0;
    S = pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= S) P1 = 100;
    else P1 = (EXP1 / S + 80)*100 / 123;
    return P1;
}
double road2(int& HP1, int& EXP1, int& M1, int E2) {
    //road2
    HP1 = processing(0, 666, HP1);
    EXP1 = processing(0, 600, EXP1);
    M1 = processing(0, 3000, M1);
    double S = 0;
    double P2 = 0;
    int moneySpent = 0;
    double halfM1 = M1 / 2.0;
    while (E2 % 2 == 1) {
        //event1
        HP1 = processing(0, 666, HP1);
        EXP1 = processing(0, 600, EXP1);
        M1 = processing(0, 3000, M1);
        if (M1==0) break;
        if (HP1 < 200) {
            HP1 = processing(0, 666, HP1);
            EXP1 = processing(0, 600, EXP1);
            M1 = processing(0, 3000, M1);
            HP1 = ceil(HP1 * 1.3-0.0001);
            M1 -= 150;
            moneySpent += 150;
            HP1 = processing(0, 666, HP1);
            M1 = processing(0, 3000, M1);
        }
        else {
            HP1 = processing(0, 666, HP1);
            EXP1 = processing(0, 600, EXP1);
            M1 = processing(0, 3000, M1);
            HP1 = ceil(HP1 * 1.1-0.0001);
            M1 -= 70;
            moneySpent += 70;
            HP1 = processing(0, 666, HP1);
            M1 = processing(0, 3000, M1);
        }
        if (moneySpent > halfM1) break;
        //event2
        if (EXP1 < 400) {
            HP1 = processing(0, 666, HP1);
            EXP1 = processing(0, 600, EXP1);
            M1 = processing(0, 3000, M1);
            M1 -= 200;
            moneySpent += 200;
            M1 = processing(0, 3000, M1);
            EXP1 = ceil(EXP1 * 1.13-0.0001);
            EXP1 = processing(0, 600, EXP1);
        }
        else {
            HP1 = processing(0, 666, HP1);
            EXP1 = processing(0, 600, EXP1);
            M1 = processing(0, 3000, M1);
            M1 -= 120;
            moneySpent += 120;
            M1 = processing(0, 3000, M1);
            EXP1 = ceil(EXP1 * 1.13-0.0001);
            EXP1 = processing(0, 600, EXP1);
        }
        if (moneySpent > halfM1) break;
        //event3
        if (EXP1 < 300) {
            HP1 = processing(0, 666, HP1);
            EXP1 = processing(0, 600, EXP1);
            M1 = processing(0, 3000, M1);
            M1 -= 100;
            moneySpent += 100;
            M1 = processing(0, 3000, M1);
            EXP1 = ceil(EXP1 * 0.9-0.0001);
        }
        else {
            HP1 = processing(0, 666, HP1);
            EXP1 = processing(0, 600, EXP1);
            M1 = processing(0, 3000, M1);
            M1 -= 120;
            moneySpent += 120;
            M1 = processing(0, 3000, M1);
            EXP1 = ceil(EXP1 * 0.9-0.0001);
        }
        if (moneySpent > halfM1) break;
    }

    while (E2 % 2 == 0) {
        //event1
        HP1 = processing(0, 666, HP1);
        EXP1 = processing(0, 600, EXP1);
        M1 = processing(0, 3000, M1);
        if (M1==0) break;
        if (HP1 < 200) {
            HP1 = processing(0, 666, HP1);
            EXP1 = processing(0, 600, EXP1);
            M1 = processing(0, 3000, M1);
            HP1 = ceil(HP1 * 1.3-0.00001);
            M1 -= 150;
            HP1 = processing(0, 666, HP1);
            M1 = processing(0, 3000, M1);
            if (M1 == 0) break;
        }
        else {
            HP1 = processing(0, 666, HP1);
            EXP1 = processing(0, 600, EXP1);
            M1 = processing(0, 3000, M1);
            HP1 = ceil(HP1 * 1.1-0.00001);
            M1 -= 70;
            moneySpent += 70;
            HP1 = processing(0, 666, HP1);
            M1 = processing(0, 3000, M1);
            if (M1 == 0) break;
        }
        //event2
        if (EXP1 < 400) {
            HP1 = processing(0, 666, HP1);
            EXP1 = processing(0, 600, EXP1);
            M1 = processing(0, 3000, M1);
            M1 -= 200;
            moneySpent += 200;
            M1 = processing(0, 3000, M1);
            EXP1 = ceil(EXP1 * 1.13-0.00001);
            EXP1 = processing(0, 600, EXP1);
            if (M1 == 0) break;
        }
        else {
            HP1 = processing(0, 666, HP1);
            EXP1 = processing(0, 600, EXP1);
            M1 = processing(0, 3000, M1);
            M1 -= 120;
            moneySpent += 120;
            M1 = processing(0, 3000, M1);
            EXP1 = ceil(EXP1 * 1.13-0.00001);
            EXP1 = processing(0, 600, EXP1);
            if (M1 == 0) break;
        }
        //event3
        if (EXP1 < 300) {
            HP1 = processing(0, 666, HP1);
            EXP1 = processing(0, 600, EXP1);
            M1 = processing(0, 3000, M1);
            M1 -= 100;
            moneySpent += 100;
            M1 = processing(0, 3000, M1);
            EXP1 = ceil(EXP1 * 0.9-0.00001);
            if (M1 == 0) break;
        }
        else {
            HP1 = processing(0, 666, HP1);
            EXP1 = processing(0, 600, EXP1);
            M1 = processing(0, 3000, M1);
            M1 -= 120;
            moneySpent += 120;
            M1 = processing(0, 3000, M1);
            EXP1 = ceil(EXP1 * 0.9-0.00001);
            if (M1 == 0) break;
        }
        break;
    }
    HP1 = ceil(HP1 * 0.83-0.0001);
    EXP1 = ceil(EXP1 * 1.17-0.00001);
    HP1 = processing(0, 666, HP1);
    EXP1 = processing(0, 600, EXP1);
    M1 = processing(0, 3000, M1);

    S = pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= S) P2 = 100;
    else P2 = (EXP1 / S + 80) *100/ 123;
    return P2;
}
double road3(int& HP1, int& EXP1, int& M1, int E2) {
    int i = 0;
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2<10) i=E2;
    else {
    int unit=E2%10;
    int tens=E2/10;
    i=(tens+unit)%10;
    }
    return P[i];
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 < 0 || E2>99) return -99;
    else {
        double P1 = 0; double P2 = 0; double P3 = 0;
        P1 = road1(EXP1);
        P2 = road2(HP1, EXP1, M1, E2);
        P3 = road3(HP1, EXP1, M1, E2);
        double P = (P1 + P2 + P3) / 3;
        if (P == 100) {
            EXP1 = ceil(EXP1 * 0.75-0.00001);
            HP1 = processing(0, 666, HP1);
            EXP1 = processing(0, 600, EXP1);
            M1 = processing(0, 3000, M1);
        }
        else if (P < 50) {
            HP1 = ceil(HP1 * 0.85-0.0001);
            EXP1 = ceil(EXP1 * 1.15-0.00001);
        }
        else {
            HP1 = ceil(HP1 * 0.9-0.0001);
            EXP1 = ceil(EXP1 * 1.2-0.00001);
        }
        HP1 = processing(0, 666, HP1);
        EXP1 = processing(0, 600, EXP1);
        M1 = processing(0, 3000, M1);
        return HP1 + EXP1 + M1;
    }
}


// Task 3
int sumOfDigits(int number) {
    int sum = 0;

    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    if (sum >= 10) {
        sum = sumOfDigits(sum);
    }
    return sum;
}
int findmax(int a[10][10], int i, int j) {
    int max = a[i][j];

    for (int k = 1; i + k < 10 && j + k < 10; k++) {
        if (a[i + k][j + k] > max) max = a[i + k][j + k];
    }

    for (int k = 1; i - k >= 0 && j - k >= 0; k++) {
        if (a[i - k][j - k] > max) max = a[i - k][j - k];
    }

    for (int k = 1; i - k >= 0 && j + k < 10; k++) {
        if (a[i - k][j + k] > max) max = a[i - k][j + k];
    }

    for (int k = 1; i + k < 10 && j - k >= 0; k++) {
        if (a[i + k][j - k] > max) max = a[i + k][j - k];
    }

    return max;
}

int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (E3 < 0 || E3>99) return -99;
    else {
        HP1 = processing(0, 666, HP1);
        HP2 = processing(0, 666, HP2);
        EXP1 = processing(0, 600, EXP1);
        EXP2 = processing(0, 600, EXP2);
        int counti = 0; int countj = 0;
        int M[10][10] = {};
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                M[i][j] = j * E3 + 2 * i;
                int k = i - j;
                M[i][j] *= k;
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (M[i][j] > (E3 * 2)) counti++;
                if (M[i][j] < (-E3)) countj++;
            }
        }
        int i = 0;
        int j = 0;
        i = sumOfDigits(counti);
        j = sumOfDigits(countj);
        int taxiPoint = M[i][j];
        int Sherlock = abs(findmax(M, i, j));
        if (abs(taxiPoint) > Sherlock) {
            EXP1 = ceil(EXP1 * 0.88-0.00001);
            HP1 = ceil(HP1 * 0.9-0.00001);
            EXP2 = ceil(EXP2 * 0.88-0.00001);
            HP2 = ceil(HP2 * 0.9-0.00001);
            return taxiPoint;
        }
        else {
            EXP1 = ceil(EXP1 * 1.12-0.00001);
            HP1 = ceil(HP1 * 1.1-0.00001);
            HP1 = processing(0, 666, HP1);
            EXP1 = processing(0, 600, EXP1);
            EXP2 = ceil(EXP2 * 1.12-0.00001);
            HP2 = ceil(HP2 * 1.1-0.00001);
            HP2 = processing(0, 666, HP2);
            EXP2 = processing(0, 600, EXP2);
            return Sherlock;
        }
    }
     return -1;
}
    


// Task 4
bool condition1(string s) {
    return (s.length() >= 8 && s.length() <= 20);
}

bool condition2(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ||
            s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')) {
            return false;
        }
    }
    return true;
}


bool condition3(const string se, const string s) {
    if (se.length() > s.length()) {
        return false;
    }

    for (size_t i = 0; i <= s.length() - se.length(); i++) {
        bool found = true;
        for (size_t j = 0; j < se.length(); j++) {
            if (se[j] != s[i + j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return true;
        }
    }

    return false;
}

bool condition4(string s) {
    for (int i = 0; i <= s.length() - 3; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) return false;
    }
    return true;
}

bool condition5(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            return true;
        }
    }
    return false;
}

int checkPassword(const char* s, const char* email) {
    string se;
    for (int i = 0; email[i] != '@'; i++) {
        se += email[i];
    }

    string password(s);


    if (condition1(password) && condition2(password) && !(condition3(se, password)) &&
        condition4(password) && condition5(password)) {
        return -10;
    }
    else if (password.length() < 8) {
        return -1;
    }
    else if (password.length() > 20) {
        return -2;
    }
    else if (condition3(se, password)) {
        size_t index = password.find(se);
        int output = 300 + index;
        return -output;
    }
    else if (!condition4(password)) {
        for (int i = 0; i <= password.length() - 3; i++) {
            if (password[i] == password[i + 1] && password[i] == password[i + 2]) {
                return -(400 + i);
            }
        }
    }
    else if (!condition5(password)) {
        return -5;
    }
    else {
        for (int i = 0; i < password.length(); i++) {
            if (!((password[i] >= '0' && password[i] <= '9') || (password[i] >= 'a' && password[i] <= 'z') ||
                (password[i] >= 'A' && password[i] <= 'Z') || password[i] == '@' || password[i] == '#' ||
                password[i] == '%' || password[i] == '$' || password[i] == '!')) {
                return i;
            }
        }
    }
    return 0;
}


// Task 5
    int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
        int b[100] = {}; 
        for (int i = 0; i < num_pwds; i++) {
            for (int j = i + 1; j < num_pwds; j++) {
                if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) b[i]++;
            }
        }

        int maxCount = b[0];
        int index = 0;
        for (int i = 0; i < num_pwds; i++) {
            if (b[i] > maxCount) {
                maxCount = b[i];
                index = i;
            }
            else if (b[i] == maxCount) {
                if (strlen(arr_pwds[i]) > strlen(arr_pwds[index])) index = i;
            }
        }

        return index;
    }


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////