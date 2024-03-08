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

int checkexp (int & exp) {
    if (exp > 600) exp = 600;
    if (exp < 0) exp = 0;
    return exp;
}

int checkhp (int & hp) {
    if (hp > 666) hp = 666;
    if (hp < 0) hp = 0;
    return hp;
}

int checkm (int & m) {
    if (m > 3000) m = 3000;
    if (m < 0) m = 0;
    return m;
}


// Task 1

int firstMeet(int & exp1, int & exp2, int e1) {
    checkexp(exp1);
    checkexp(exp2);
    if (e1 < 0 || e1 > 99) return -99;
    else if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) {
            exp2 += 29;
            checkexp(exp2);
        }
        else if (e1 == 1) {
            exp2 += 45;
            checkexp(exp2);
        }
        else if (e1 == 2) {
            exp2 += 75;
            checkexp(exp2);
        }
        else if (e1 == 3) {
            exp2 += 29 + 45 + 75;
            checkexp(exp2);
        }
        int d = e1*3 + exp1*7;
        if (d%2 == 0) exp1 += ceilf(d*0.005);
        else exp1 = ceilf(exp1 - (d*0.01));
        checkexp(exp1);
    }   
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 += ceilf(e1/4.0) + 19;
            checkexp(exp2);
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 += ceilf(e1/9.0) + 21;
            checkexp(exp2);
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 += ceilf(e1/16.0) + 17;
            checkexp(exp2);
        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2 += ceilf(e1/4.0 + 19);
            checkexp(exp2);
            if (exp2 > 200) exp2 += ceilf(e1/9.0 + 21);
            checkexp(exp2);
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 += ceilf(e1/4.00 + 19) + ceilf(e1/9.0 + 21);
            checkexp(exp2);
            if (exp2 > 400) {
                exp2 += ceilf(e1/16.00 + 17);
                checkexp(exp2);
                exp2 += ceilf(exp2*0.15);
                checkexp(exp2);
            }
        }
        exp1 -= e1;
    }
    checkexp(exp1);
    checkexp(exp2);
    return exp1 + exp2;
}

// Task 2
int road21 (int & HP1, int & M1) {
    if (HP1 < 200) {
        HP1 += ceilf(HP1*0.3);
        M1 -= 150;
    }
    else {
        HP1 += ceilf(HP1*0.1);
        M1 -= 70;
    }
    checkhp(HP1);
    checkm(M1);
    return HP1;
    return M1;
}
int road22 (int & EXP1, int & M1) {
    if (EXP1 < 400) M1 -= 200;
    else M1 -= 120;
    EXP1 += ceilf(EXP1*0.13);
    checkexp(EXP1);
    checkm(M1);
    return EXP1;
    return M1;
}
int road23 (int & EXP1, int & M1) {
    if (EXP1 < 300) M1 -= 100;
    else M1 -= 120;
    EXP1 = ceilf(EXP1*0.90);
    checkexp(EXP1);
    checkm(M1);
    return EXP1;
    return M1;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99) return -99;
    checkhp(HP1);
    checkm(M1);
    double p1 = 0, p2 = 0, p3 = 0;
    // Road 1
    int sq1 = round(sqrt(EXP1));
    int s1 = sq1*sq1;
    if ((EXP1 - s1) >= 0) p1 = 1.00;
    else p1 = ((EXP1*1.0/s1) + 80)/123;
    // Road 2
    if (E2%2 == 0) {
        if (M1 > 0) {
            road21(HP1, M1);
            if (M1 > 0) road22(EXP1, M1);
            if (M1 > 0) road23(EXP1, M1);
            }
        HP1 = ceilf(HP1*0.83);
        EXP1 += ceilf(EXP1*0.17);
    } 
    else {
        float m = M1/2;
        int a = M1;
        int b = 0;
        while(0 == 0) {
            if (b <= m) {
                road21(HP1, M1);
                b += a - M1;
                a = M1;
            }
            if (b <= m) {
                road22(EXP1, M1);
                b += a - M1;
                a = M1;
            }
            if (b <= m) {
                road23(EXP1, M1);
                b += a - M1;
                a = M1;
            }
            if (b > m) {
                HP1 = ceilf(HP1*0.83);
                EXP1 += ceilf(EXP1*0.17);
                break;
            }
        }
        
    }
    checkexp(EXP1);
    checkhp(HP1);
    int sq2 = round(sqrt(EXP1));
    int s2 = sq2*sq2;
    if ((EXP1 - s2) >= 0) p2 = 1.00;
    else p2 = (EXP1*1.0/s2 + 80)/123;
    // Road 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 >= 0 && E2 <= 9) {
        p3 = P[E2]/100.0;
    } 
    else {
        int c = E2/10;
        int d = E2 - c*10;
        int sum = c + d;
        c = sum/10;
        d = sum - c*10;
        p3 = P[d]/100.0;
    }
    if (p1 == 1 && p2 == 1 && p3 == 1) EXP1 = ceilf(EXP1*0.75);
    else {
        if (((p1 + p2 + p3)/3.0) < 0.5) {
            HP1 = ceilf(HP1*0.85);
            EXP1 += ceilf(EXP1*0.15);
        } 
        else {
            HP1 = ceilf(HP1*0.9);
            EXP1 += ceilf(EXP1*0.2);
        }
    }
    checkexp(EXP1);
    checkhp(HP1);
    return HP1 + EXP1 + M1;
}

// Task 3

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) return -99;
    checkhp(HP1);
    checkhp(HP2);
    checkexp(EXP1);
    checkexp(EXP2);
    int matrix[10][10];
    int countmore = 0, countless = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            matrix[i][j] = ((E3*j) + (i*2))*(i-j);
            if (matrix[i][j] > E3*2) countmore++;
            if (matrix[i][j] < -E3) countless++;
        }
    }
    while (countmore >= 10) {
        int a = countmore/10;
        countmore -= a*10;
        countmore += a;
    }
    while (countless >= 10) {
        int a = countless/10;
        countless -= a*10;
        countless += a;
    }
    
    int valuetaxi = matrix[countmore][countless];
    int valuepeople = 0;
    for (int i = 0; i < 10; i++) {
        int value = matrix[countmore - i][countless - i];
        if (valuepeople < value) valuepeople = value;
        if ((countmore - i == 0) || (countless - i) == 0) break;
    }
    for (int i = 0; i < 10; i++) {
        int value = matrix[countmore + i][countless + i];
        if (valuepeople < value) valuepeople = value;
        if ((countmore + i == 9) || (countless + i) == 9) break;
    }
    for (int i = 0; i < 10; i++) {
        int value = matrix[countmore - i][countless + i];
        if (valuepeople < value) valuepeople = value;
        if ((countmore - i == 0) || (countless + i) == 9) break;
    }
    for (int i = 0; i < 10; i++) {
        int value = matrix[countmore + i][countless - i];
        if (valuepeople < value) valuepeople = value;
        if ((countmore + i == 9) || (countless - i) == 0) break;
    }
    if (abs(valuetaxi) > abs(valuepeople)) {
        HP1 = ceilf(HP1*0.9);
        HP2 = ceilf(HP2*0.9);
        EXP1 = ceilf(EXP1*0.88);
        EXP2 = ceilf(EXP2*0.88);
        checkexp(EXP1);
        checkexp(EXP2);
        checkhp(HP1);
        checkhp(HP2);
        return valuetaxi;
    }
    else {
        HP1 += ceilf(HP1*0.1);
        HP2 += ceilf(HP2*0.1);
        EXP1 += ceilf(EXP1*0.12);
        EXP2 += ceilf(EXP2*0.12);
        checkexp(EXP1);
        checkexp(EXP2);
        checkhp(HP1);
        checkhp(HP2);
        return valuepeople;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string full(email);
    string pass(s);
    string se = "";
    for (int i = 0; i < full.length(); i++) {
        if (full[i] == '@') break;
        else se += full[i];
    }
    if (pass.length() < 8) return -1;
    if (pass.length() > 20) return -2;
    if (se.length() <= pass.length()) {
        for (int i = 0; i <= pass.length() - se.length(); ++i) {
            int j;
            for (j = 0; j < se.length(); ++j) {
                if (pass[i + j] != se[j]) break;
            }
            if (j == se.length()) return -(300+i);
        }
    }
    for (int i = 0; i < (pass.length() - 2); i++) {
        if ((pass[i] == pass[i+1]) && (pass[i] == pass[i+2])) return -(400+i);
    }
    for (int i = 0; i < pass.length(); i++) {
        if (!((pass[i] >= 'A' && pass[i] <= 'Z')||(pass[i] >= 'a' && pass[i] <= 'z')||(pass[i] >= '0' && pass[i] <= '9'))) {
            if (!(pass[i] == '@'||pass[i] == '#'||pass[i] == '%'||pass[i] == '$'||pass[i] == '!')) return i;
        }
    }
    int count = 0;
    for (int i = 0; i < pass.length(); i++) {
        if ((pass[i] == '@'||pass[i] == '#'||pass[i] == '%'||pass[i] == '$'||pass[i] == '!')) count++;
    }
    if (count == 0) return -5;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int appearmost = 0;
    int longest = 0;
    int location = 0;

    for (int i = 0; i < num_pwds; ++i) {
        int appear = 0;
        int l = strlen(arr_pwds[i]);

        for (int j = 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                appear++;
            }
        }
        if (appear > appearmost || (appear == appearmost && l > longest)) {
            location = i;
            appearmost = appear;
            longest = l;
        }
    }
    return location;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////