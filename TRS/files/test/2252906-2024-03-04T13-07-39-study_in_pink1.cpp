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
void checkLimitHP (int & HP) {
    if(HP > 666) HP = 666;
    if(HP < 0) HP = 0;
}
void checkLimitEXP (int & EXP) {
    if(EXP > 600) EXP = 600;
    if(EXP < 0) EXP = 0;
}
void checkLimitM (int & M) {
    if(M > 3000) M = 3000;
    if(M < 0) M = 0;
}
int firstMeet(int & exp1, int & exp2, int e1) {
    checkLimitEXP(exp2);
    checkLimitEXP(exp1);
    // TODO: Complete this function
    if(e1 < 0 || e1 > 99) return -99;
    if(e1 >= 0 && e1 <= 3) {
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
                exp2 = 29 + 45 + 75 + exp2;
                break;
        }
        checkLimitEXP(exp2);
        int D = e1 * 3 + exp1 * 7;
        if(D % 2 == 0) exp1 = D/200.0 + exp1 + 0.999; else exp1 = exp1 - D/100.0 + 0.999;
        checkLimitEXP(exp1);
    }
    else if(e1 >= 4 && e1 <= 99) {
        if(e1 >= 4 && e1 <= 19) { // 1
            exp2 = e1/4.0 + 19 + exp2 + 0.999;
        }
        else if(e1 >= 20 && e1 <= 49) { // 2
            exp2 = e1/9.0  + 21 + exp2 + 0.999;
        }
        else if(e1 >= 50 && e1 <= 65) { // 3
            exp2 = e1/16.0 + 17 + exp2 + 0.999;
        }
        else if(e1 >= 66 && e1 <= 79) {
            exp2 = e1/4.0 + 19 + exp2 + 0.999; // 1
            if(exp2 > 200) { // 2
                exp2 = e1/9.0 + 21 + exp2 + 0.999;
            }
        }
        else {
            // 1
            exp2 = e1/4.0 + 19 + exp2 + 0.999;
            // 2
            exp2 = e1/9.0 + 21 + exp2 + 0.999;
            // 3
            if(exp2 > 400) {
                exp2 = e1/16.0 + 17 + exp2 + 0.999;
                exp2 = exp2 * 1.15 + 0.999;
            }
        }
        checkLimitEXP(exp2);
        exp1 -= e1;
        checkLimitEXP(exp1);
    }
    return exp1 + exp2;
}

// Task 2
bool isPerfectSquare(int number) {
    if(sqrt(number) - floor(sqrt(number)) == 0) return true;
    return false;
}
int NearestPerfectSquare(int number) {
    if(isPerfectSquare(number)) return number;
    int upper = number + 1;
    int under = number - 1;
    while(!isPerfectSquare(upper)) upper++;
    while(!isPerfectSquare(under)) under--;
    return ((number - under) > (upper - number)) ? upper : under;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    checkLimitHP(HP1);
    checkLimitM(M1);
    checkLimitEXP(EXP1);
    // TODO: Complete this function
    if(E2 < 0 || E2 > 99) return -99;
    //road1
    double S = NearestPerfectSquare(EXP1);
    double P1 = (EXP1 >= S) ? 1 : ((EXP1/S+80)/123.0);
    //road2////////////////////////////////////////////////////
    if(E2 % 2 != 0) {
        double checkpoint = M1/2.0;
        double Mpaid = 0;
        while(true) {
        	if(M1 == 0) break;
            // drink & eat////////////////////////////////////////////////////
            if(HP1 < 200) {
                HP1 = HP1 * 1.3 + 0.999;
                M1 -= 150;
                Mpaid += 150;
            }
            else {
                HP1 = HP1 * 1.1 + 0.999;
                M1 -= 70;
                Mpaid += 70;
            }
            checkLimitHP(HP1);
            checkLimitM(M1);
            if(Mpaid > checkpoint || M1 == 0) break;
            // taxi////////////////////////////////////////////////////
            if(EXP1 < 400) {
                M1 -= 200;
                Mpaid += 200;
            }
            else {
                M1 -= 120;
                Mpaid += 120;
            }
            EXP1 = EXP1 * 1.13 + 0.999;
            checkLimitEXP(EXP1);
            checkLimitM(M1);
            if(Mpaid > checkpoint || M1 == 0) break;
            // homeless////////////////////////////////////////////////////
            if(EXP1 < 300) {
                M1 -= 100;
                Mpaid += 100;
            }
            else {
                M1 -= 120;
                Mpaid += 120;
            }
            EXP1 = EXP1 * 0.90 + 0.999;
            checkLimitEXP(EXP1);
            checkLimitM(M1);
            if(Mpaid > checkpoint || M1 == 0) break;
        }
        HP1 = HP1 * 0.83 + 0.999; EXP1 = EXP1 * 1.17 + 0.999;
        checkLimitEXP(EXP1);
        checkLimitHP(HP1);
    }
    else {
        bool skip = false;
        if(M1 == 0) skip = true;

        // drink & eat////////////////////////////////////////////////////
        if(HP1 < 200 && !skip) {
            HP1 = HP1 * 1.3 + 0.999;
            M1 -= 150;
        }
        else if(HP1 >= 200 && !skip){
            HP1 = HP1 * 1.1 + 0.999;
            M1 -= 70;
        }
        checkLimitHP(HP1);
        checkLimitM(M1);

        if(M1 == 0) skip = true;

        // taxi////////////////////////////////////////////////////
        if(EXP1 < 400 && !skip) {
            M1 -= 200;
        }
        else if(EXP1 >= 400 && !skip){
            M1 -= 120;
        }
        if(!skip) EXP1 = EXP1 * 1.13 + 0.999;
        checkLimitEXP(EXP1);
        checkLimitM(M1);
        if(M1 == 0) skip = true;
        // homeless////////////////////////////////////////////////////
        if(EXP1 < 300 && !skip) {
            M1 -= 100;
        }
        else if(EXP1 >= 300 && !skip){
            M1 -= 120;
        }
        if(!skip) EXP1 = EXP1 * 0.90 + 0.999;
        checkLimitEXP(EXP1);
        checkLimitM(M1);
        if(M1 == 0) skip = true;
      
        HP1 = HP1 * 0.83 + 0.999; EXP1 = EXP1 * 1.17 + 0.999;
        checkLimitEXP(EXP1);
        checkLimitHP(HP1);
    }
    S = NearestPerfectSquare(EXP1);
    double P2 = (EXP1 >= S) ? 1 : ((EXP1/S+80)/123.0);
    //road 3////////////////////////////////////////////////////
    int fixed_P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P3 = 0.0;
    if(E2 < 10) P3 = fixed_P[E2] / 100.0;
    else {
        int E2_temp = E2;
        int i = 0;
        i = i + E2_temp % 10;
        E2_temp /= 10;
        i = i + E2_temp % 10;
        P3 = fixed_P[i%10] / 100.0;
    }
    //compute answer///////////
    if(P1 == 1.0 && P2 == 1.0 && P3 == 1.0) {
        EXP1 = EXP1 * 0.75 + 0.999;
    }
    else {
        double middle = (P1 + P2 + P3)/3.0;
        if(middle < 0.5) {
            HP1 = HP1 * 0.85 + 0.999;
            EXP1 = EXP1 * 1.15 + 0.999;
        }
        else {
            HP1 = HP1 * 0.90 + 0.999;
            EXP1 = EXP1 * 1.20 + 0.999;
        }
    }
    checkLimitEXP(EXP1);
    checkLimitHP(HP1);
    checkLimitM(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int maxDiagonal(int taxi[][10], int i, int j) {
    int maxCurr = taxi[i][j];
    int x = i, y = j;
    // down right//////////////////////////////////////
    while(x < 10 && y < 10) {
        if(maxCurr < taxi[x][y]) maxCurr = taxi[x][y];
        x++; y++;
    }
    // up right//////////////////////////////////////
    x = i; y = j;
    while(x < 10 && y >= 0) {
        if(maxCurr < taxi[x][y]) maxCurr = taxi[x][y];
        x++; y--;
    }
    // down left//////////////////////////////////////
    x = i; y = j;
    while(x >= 0 && y < 10) {
        if(maxCurr < taxi[x][y]) maxCurr = taxi[x][y];
        x--; y++;
    }
    // up left//////////////////////////////////////
    x = i; y = j;
    while(x >= 0 && y >= 0) {
        if(maxCurr < taxi[x][y]) maxCurr = taxi[x][y];
        x--; y--;
    }
    return abs(maxCurr);
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    checkLimitHP(HP1); checkLimitHP(HP2); checkLimitEXP(EXP1); checkLimitEXP(EXP2);
    // TODO: Complete this function
    if(E3 > 99 || E3 < 0) return -99;
    int taxiTable[10][10];
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            taxiTable[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int detectiveTable[10][10];
    for(int j = 0; j < 10; j++) {
        for(int i = 0; i < 10; i++) {
            detectiveTable[i][j] = maxDiagonal(taxiTable, i, j);
        }
    }
    int largerE3X2 = 0, smaller_minusE3 = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(taxiTable[i][j] > 2*E3) largerE3X2++;
            else if(taxiTable[i][j] < -E3) smaller_minusE3++;
        }
    }
    while(largerE3X2 >= 10) {
        int temp = largerE3X2;
        largerE3X2 = temp % 10;
        temp /= 10;
        largerE3X2 = largerE3X2 + temp % 10;
    }
    while(smaller_minusE3 >= 10) {
        int temp = smaller_minusE3;
        smaller_minusE3 = temp % 10;
        temp /= 10;
        smaller_minusE3 = smaller_minusE3 + temp % 10;
    }
    bool TaxiLarger = false;
    if(abs(taxiTable[largerE3X2][smaller_minusE3]) > detectiveTable[largerE3X2][smaller_minusE3]) {
        EXP1 = EXP1 * 0.88 + 0.999;
        EXP2 = EXP2 * 0.88 + 0.999;

        HP1 = HP1 * 0.90 + 0.999;
        HP2 = HP2 * 0.90 + 0.999;
        TaxiLarger = true;
    }
    else {
        EXP1 = EXP1 * 1.12 + 0.999;
        EXP2 = EXP2 * 1.12 + 0.999;

        HP1 = HP1 * 1.10 + 0.999;
        HP2 = HP2 * 1.10 + 0.999;
    }
    checkLimitEXP(EXP1);
    checkLimitHP(HP1);
    checkLimitEXP(EXP2);
    checkLimitHP(HP2);
    //fix all ceil to * and + 0.999
    return (TaxiLarger) ? taxiTable[largerE3X2][smaller_minusE3] : detectiveTable[largerE3X2][smaller_minusE3];
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    if(!s && !email) return -99;
    string validS(s), Email(email);
    string se = "";
    int validS_len = validS.length(), Email_len = Email.length();
    for(int i = 0; Email[i] != '@' && i < Email_len; i++) {
        se += Email[i];
    }
    if (validS_len < 8) return -1;
    if (validS_len > 20) return -2;
    // find se
    size_t found_se = validS.find(se);
    if(found_se != string::npos) {
        int foundxd = found_se;
        return -(300 + foundxd);
    }
    // find more than 3 same consecutive
    for(int i = 2; i < validS_len; i++) {
        if(validS[i] == validS[i-1] && validS[i-1] == validS[i-2]) {
            return -(400 + i - 2);
        }
    }
    // find special char
    bool specialFound = false;
    for(int i = 0; i < validS_len; i++) {
        if(validS[i] == '@' || validS[i] == '#' || 
        validS[i] == '%' || validS[i] == '$' || validS[i] == '!') specialFound = true;
    }
    if(!specialFound) return -5;
    //rest 
    for(int i = 0; i < validS_len; i++) {
        if((validS[i] == '@' || validS[i] == '#' || validS[i] == '%' || validS[i] == '$' || validS[i] == '!') 
        || (validS[i] >= '0' && validS[i] <= '9')
        || (validS[i] >= 'A' && validS[i] <= 'Z')
        || (validS[i] >= 'a' && validS[i] <= 'z')) continue;
        else return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_AppearIndex = 0;
    int temp_count = 1;
    int max_Appear = 0;
    for(int i = 0; i < num_pwds; i++) {
        for(int j = 0; j < num_pwds; j++) {
            if(j != i && strcmp(arr_pwds[i], arr_pwds[j]) == 0) temp_count += 1;
        }
        string temp1(arr_pwds[i]), max_len(arr_pwds[max_AppearIndex]);

        if(temp_count > max_Appear || ((temp_count == max_Appear) && temp1.length() > max_len.length())) {
            max_Appear = temp_count;
            max_AppearIndex = i;
        }
        temp_count = 1;
    }
    return max_AppearIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
