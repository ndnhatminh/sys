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

// Check HP
int checkValidHP(int & HP){
    if(HP > 666){
        HP = 666;
    }
    else if(HP < 0){
        HP = 0;
    }

    return HP;
}

// Check EXP
int checkValidEXP(int & EXP){
    if(EXP > 600){
        EXP = 600;
    }
    else if(EXP < 0){
        EXP = 0;
    }

    return EXP;
}

// Check Money
int checkValidM(int & M){
    if(M > 3000){
        M = 3000;
    }
    else if(M < 0){
        M = 0;
    }

    return M;
}

// Calculate probabilities P1 and P2
double calcP(int EXP){
    int S;
    double P;

    int S1 = floor(sqrt(EXP));
    S1 = pow(S1, 2);
    int S2 = floor(sqrt(EXP)) + 1;
    S2 = pow(S2, 2);

    if(abs(EXP - S1) < abs(S2 - EXP)){
        S = S1;
    }
    else{
        S = S2;
    }

    if(EXP >= S){
        P = 1;
    }
    else if(EXP < S){
        P = ((double)EXP/S + 80.0)/123.0;
    }

    return P;
}

// Count digits
int countDigit(int number){
    int count = 0;

    if(number == 0){
        return 1;
    }
    
    while(number > 0){
        number = number / 10;
        ++count;
    }

    return count;
}

// Functions for task 4
int invalidPassword(std::string s){
    for(int i = 0; i < s.length(); i++){
        if((s[i] >= 0 && s[i] <= 32) || (s[i] == 34) || (s[i] >= 38 && s[i] <= 47) || (s[i] >= 58 && s[i] <= 63) || (s[i] >= 91 && s[i] <= 96) || (s[i] >= 123 && s[i] <= 127)){
            return i;
        }
    }

    return -1;
}

int countSpecial(std::string s){
    int count = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'){
            count++;
        }
    }

    return count;
}

int checkConsecutive(std::string s){
    for(int i = 0; i < s.length() - 2; i++){
        if(s[i] == s[i+1] && s[i+1] == s[i+2] && s[i] == s[i+2]){
            return i;
        }
    }

    return -1;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

    if(e1 < 0 || e1 > 99){
        return -99;
    }

    checkValidEXP(exp1);
    checkValidEXP(exp2);

    if(e1 >= 0 && e1 <= 3){
        if(e1 == 0){
            exp2 = exp2 + 29;
        }
        if(e1 == 1){
            exp2 = exp2 + 45;
        }
        if(e1 == 2){
            exp2 = exp2 + 75;
        }
        if(e1 == 3){
            exp2 = exp2 + 29 + 45 + 75;
        }
        checkValidEXP(exp2);

        int D = e1 * 3 + exp1 * 7;

        if(D % 2 == 0){
            exp1 = ceil(- 1e-9 + (double)exp1 + D/200.0);
        }
        else{
            exp1 = ceil(- 1e-9 + (double)exp1 - D/100.0);
        }
        checkValidEXP(exp1);

        return exp1 + exp2;
    }

    else if(e1 >= 4 && e1 <= 99){
        if(e1 >= 4 && e1 <= 19){
            exp2 = ceil(- 1e-9 + (double)exp2 + (e1/4.0 + 19.0));
        }
        if(e1 >= 20 && e1 <= 49){
            exp2 = ceil(- 1e-9 + (double)exp2 + (e1/9.0 + 21.0));
        }
        if(e1 >= 50 && e1 <= 65){
            exp2 = ceil(- 1e-9 + (double)exp2 + (e1/16.0 + 17.0));
        }
        if(e1 >= 66 && e1 <= 79){
            exp2 = ceil(- 1e-9 + (double)exp2 + (e1/4.0 + 19.0));
            if(exp2 > 200){
                exp2 = ceil(- 1e-9 + (double)exp2 + (e1/9.0 + 21.0));
            }
        }
        if(e1 >= 80 && e1 <= 99){
            exp2 = ceil(- 1e-9 + (double)exp2 + (e1/4.0 + 19.0));
            exp2 = ceil(- 1e-9 + (double)exp2 + (e1/9.0 + 21.0));

            if(exp2 > 400){
                exp2 = ceil(- 1e-9 + (double)exp2 + (e1/16.0 + 17.0));
                exp2 = ceil(- 1e-9 + (double)exp2 + 0.15 * (double)exp2);
            }
        }

        exp1 = exp1 - e1;

        checkValidEXP(exp1);
        checkValidEXP(exp2);

        return exp1 + exp2;
    }

    return -99;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    if(E2 > 99 || E2 < 0){
        return -99;
    }

    checkValidHP(HP1);
    checkValidEXP(EXP1);
    checkValidM(M1);

    // Street #1:
    double P1 = calcP(EXP1);

    // Street #2:
    double money = (double)M1 * 0.5;

    if(E2 % 2 != 0){
        while(true){
            if(M1 <= 0){
                break;
            }

            if(HP1 < 200){
                HP1 = ceil(- 1e-9 + 1.3 * (double)HP1);
                checkValidHP(HP1);
                M1 = M1 - 150;
                if((double)M1 < money){
                    break;
                }
            }
            else{
                HP1 = ceil(- 1e-9 + 1.1 * (double)HP1);
                checkValidHP(HP1);
                M1 = M1 - 70;
                if((double)M1 < money){
                    break;
                }
            }

            if(EXP1 < 400){
                EXP1 = ceil(- 1e-9 + 1.13 * (double)EXP1);
                checkValidEXP(EXP1);
                M1 = M1 - 200;
                if((double)M1 < money){
                    break;
                }
            }
            else{
                EXP1 = ceil(- 1e-9 + 1.13 * (double)EXP1);
                checkValidEXP(EXP1);
                M1 = M1 - 120;
                if((double)M1 < money){
                    break;
                }
            }

            if(EXP1 < 300){
                EXP1 = ceil(- 1e-9 + 0.9 * (double)EXP1);
                checkValidEXP(EXP1);
                M1 = M1 - 100;
                if((double)M1 < money){
                    break;
                }
            }
            else{
                EXP1 = ceil(- 1e-9 + 0.9 * (double)EXP1);
                checkValidEXP(EXP1);
                M1 = M1 - 120;
                if((double)M1 < money){
                    break;
                }
            }
        }

        HP1 = ceil(- 1e-9 + 0.83 * (double)HP1);
        EXP1 = ceil(- 1e-9 + 1.17 * (double)EXP1);

        checkValidHP(HP1);
        checkValidEXP(EXP1);
        checkValidM(M1);
    }
    else if(E2 % 2 == 0){
        while(true){
            if(M1 == 0){
                break;
            }

            if(HP1 < 200){
                HP1 = ceil(- 1e-9 + 1.3 * (double)HP1);
                checkValidHP(HP1);
                M1 = M1 - 150;
                checkValidM(M1);
            }
            else{
                HP1 = ceil(- 1e-9 + 1.1 * (double)HP1);
                checkValidHP(HP1);
                M1 = M1 - 70;
                checkValidM(M1);
            }

            if(M1 == 0){
                break;
            }

            if(EXP1 < 400){
                M1 = M1 - 200;
                checkValidM(M1);
                EXP1 = ceil(- 1e-9 + 1.13 * (double)EXP1);
                checkValidEXP(EXP1);
            }
            else{
                M1 = M1 - 120;
                checkValidM(M1);
                EXP1 = ceil(- 1e-9 + 1.13 * (double)EXP1);
                checkValidEXP(EXP1);
            }

            if(M1 == 0){
                break;
            }

            if(EXP1 < 300){
                M1 = M1 - 100;
                checkValidM(M1);
                EXP1 = ceil(- 1e-9 + 0.9 * (double)EXP1);
                checkValidEXP(EXP1);
            }
            else{
                M1 = M1 - 120;
                checkValidM(M1);
                EXP1 = ceil(- 1e-9 + 0.9 * (double)EXP1);
                checkValidEXP(EXP1);
            }

            break;
        }

        HP1 = ceil(- 1e-9 + 0.83 * (double)HP1);
        EXP1 = ceil(- 1e-9 + 1.17 * (double)EXP1);

        checkValidHP(HP1);
        checkValidEXP(EXP1);
        checkValidM(M1);
    }

    double P2 = calcP(EXP1);

    // Street #3:
    double P[10] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    int i;

    if(countDigit(E2) == 2){
        i = (int)(floor(E2/10) + (E2 % 10)) % 10;
    }
    else if(countDigit(E2) == 1){
        i = E2;
    }

    double P3 = P[i];

    // Final part:
    double avgP = (P1 + P2 + P3)/3;

    if(avgP == 1){
        EXP1 = ceil(- 1e-9 + 0.75 * (double)EXP1);
    }
    else if(avgP < 0.5){
        HP1 = ceil(- 1e-9 + 0.85 * (double)HP1);
        EXP1 = ceil(- 1e-9 + 1.15 * (double)EXP1);
    }
    else if(avgP >= 0.5){
        HP1 = ceil(- 1e-9 + 0.9 * (double)HP1);
        EXP1 = ceil(- 1e-9 + 1.2 * (double)EXP1);
    }

    checkValidHP(HP1);
    checkValidEXP(EXP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

    if(E3 > 99 || E3 < 0){
        return -99;
    }

    checkValidEXP(EXP1);
    checkValidEXP(EXP2);
    checkValidHP(HP1);
    checkValidHP(HP2);

    int map[10][10];
    int counti = 0, countj = 0, TaxiPoint, SWPoint;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if(map[i][j] > (E3 * 2)){
                counti++;
            }
            if(map[i][j] < (-E3)){
                countj++;
            }
        }
    }

    while(countDigit(counti) == 2){
        counti = floor(counti/10) + (counti%10);
    }
    while(countDigit(countj) == 2){
        countj = floor(countj/10) + (countj%10);
    }

    TaxiPoint = map[counti][countj];
    SWPoint = TaxiPoint;

    int u1 = counti, v1 = countj;
    while(u1 < 10 && u1 > 0 && v1 < 10 && v1 > 0){
        if(SWPoint < map[u1][v1]){
            SWPoint = map[u1][v1];
        }
        u1++;
        v1++;
    }

    int u2 = counti, v2 = countj;
    while(u2 < 10 && u2 > 0 && v2 < 10 && v2 > 0){
        if(SWPoint < map[u2][v2]){
            SWPoint = map[u2][v2];
        }
        u2--;
        v2--;
    }

    int u3 = counti, v3 = countj;
    while(u3 < 10 && u3 > 0 && v3 < 10 && v3 > 0){
        if(SWPoint < map[u3][v3]){
            SWPoint = map[u3][v3];
        }
        u3++;
        v3--;
    }

    int u4 = counti, v4 = countj;
    while(u4 < 10 && u4 > 0 && v4 < 10 && v4 > 0){
        if(SWPoint < map[u4][v4]){
            SWPoint = map[u4][v4];
        }
        u4--;
        v4++;
    }

    if(abs(TaxiPoint) > SWPoint){
        EXP1 = ceil(- 1e-9 + 0.88 * (double)EXP1);
        EXP2 = ceil(- 1e-9 + 0.88 * (double)EXP2);
        HP1 = ceil(- 1e-9 + 0.9 * (double)HP1);
        HP2 = ceil(- 1e-9 + 0.9 * (double)HP2);

        checkValidEXP(EXP1);
        checkValidEXP(EXP2);
        checkValidHP(HP1);
        checkValidHP(HP2);

        return TaxiPoint;
    }
    else{
        EXP1 = ceil(- 1e-9 + 1.12 * (double)EXP1);
        EXP2 = ceil(- 1e-9 + 1.12 * (double)EXP2);
        HP1 = ceil(- 1e-9 + 1.1 * (double)HP1);
        HP2 = ceil(- 1e-9 + 1.1 * (double)HP2);

        checkValidEXP(EXP1);
        checkValidEXP(EXP2);
        checkValidHP(HP1);
        checkValidHP(HP2);

        return SWPoint;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    std::string Ss = s;
    std::string Semail = email;
    std::string se = Semail.substr(0, Semail.find('@'));

    if(Ss.length() < 8){
        return -1;
    }
    else if(Ss.length() > 20){
        return -2;
    }
    else if(Ss.find(se) != std::string::npos){
        return -(300 + Ss.find(se));
    }
    else if(checkConsecutive(Ss) >= 0){
        return -(400 + checkConsecutive(Ss));
    }
    else if(countSpecial(Ss) == 0){
        return -5;
    }
    else if(invalidPassword(Ss) >= 0){
        return invalidPassword(Ss);
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    
    int countM = 0;
    int index = 0;

    for(int i = 0; i < num_pwds; i++){
        int count = 1;

        for(int j = i + 1; j < num_pwds; j++){
            if(strcmp(arr_pwds[i], arr_pwds[j]) == 0){
                count++;
            }
        }
        if(count > countM){
            countM = count;
            index = i;
        }
        else if(count == countM){
            if(strlen(arr_pwds[i]) > strlen(arr_pwds[index])){
                index = i;
            }
        }
    }

    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////