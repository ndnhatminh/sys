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

int Checker (int value, int uplimit, int downlimit){
    value = min(value, uplimit);
    value = max(value, downlimit);
        return value;
}
double Vali_chance (double EXP1){
    double S = round(sqrt(EXP1));
        if (EXP1 >= S*S)
            return 1;
        else
            return (double(EXP1)/(S*S) + 80)/123;}
int ceilling(double value) {
    return (value + 0.99999);
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 < 0 || e1 > 99)
        return -99;
    exp1 = Checker(exp1, 600, 0);
    exp2 = Checker(exp2, 600, 0);
    
    // Complete this function
    switch (e1) {
        case 0: exp2 += 29; break;
        case 1: exp2 += 45; break;
        case 2: exp2 += 75; break;
        case 3: exp2 += 149; break;
    }
    if (4 <= e1 && e1 <= 19)
        exp2 += ceilling(double(e1) / 4) + 19;
    else if (20 <= e1 && e1 <= 49)
        exp2 += ceilling(double(e1) / 9) + 21;
    else if (50 <= e1 && e1 <= 65)
        exp2 += ceilling(double(e1) / 16) + 17;
    else if (66 <= e1 && e1 <= 79) {
        exp2 += ceilling(double(e1) / 4) + 19;
        if (exp2 > 200)
            exp2 += ceilling(double(e1) / 9) + 21;
    }
    else if (80 <= e1 && e1 <= 99) {
        exp2 += ceilling(double(e1) / 4) + 19;
        exp2 += ceilling(double(e1) / 9) + 21;
        if (exp2 > 400) {
            exp2 += ceilling(double(e1) / 16) + 17;
            exp2 = ceilling(1.15 * exp2);
        }
    }
    if (e1 - 3 <= 0) {
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 1)
            exp1 -= (D / 100);
        else
            exp1 += ceilling(double(D) / 200);
    }
    else
        exp1 -= e1;
    exp1 = Checker(exp1, 600, 0);
    exp2 = Checker(exp2, 600, 0);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99)
        return -99;
    EXP1 = Checker(EXP1, 600, 0);
    HP1 = Checker(HP1, 666, 0);
    M1 = Checker(M1, 3000, 0);
    
    // First road
    double P1 = Vali_chance(EXP1);

    // Second road
    double PM = M1 / 2,PreM1 = M1;
    while (true) {
        if (M1 <= 0) {
            break;
        }
    
        // Drinking
        if (HP1 < 200) {
            HP1 = ceilling(double(HP1)*1.3);
            M1 -= 150;
        }
        else {
            HP1 = ceilling(double(1.1 * HP1));
            M1 -= 70;
        }
        HP1 = Checker(HP1, 666, 0);
        if ((E2%2 == 1 && PM < (PreM1 - M1)) || (E2%2 == 0 && M1 <= 0)) {
            break;
        }

        // Transportation
        if (EXP1 < 400)
            M1 -= 200;
        else
            M1 -= 120;
        EXP1 = ceilling(double(EXP1)*1.13);
        EXP1 = Checker(EXP1, 600, 0);
        if ((E2%2 == 1 && PM < (PreM1 - M1)) || (E2%2 == 0 && M1 <= 0)) {
            break;
        }

        // Homeless
        if (EXP1 < 300) M1 -= 100;
        else M1 -= 120;
        EXP1 = ceilling(double(EXP1) * 0.9);
        EXP1 = Checker(EXP1, 600, 0);
        if ((E2%2 == 1 && PM < (PreM1 - M1)) || (E2%2 == 0 && M1 <= 0)) {
            break;
        }
        if (E2 % 2 == 0)
            break;
    }   
    HP1 = ceilling(double(HP1)*0.83);
    EXP1 = ceilling(double(EXP1)*1.17);
    M1 = Checker(M1, 3000, 0);
    HP1 = Checker(HP1, 666, 0);
    EXP1 = Checker(EXP1, 600, 0);
    double P2 = Vali_chance(EXP1);
//Third road
double P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
int i = (E2/10 + E2%10)%10;
double P3 = P[i]/100;

//Vali
if (P1 >= 1 && P2 >= 1 && P3 >= 1) EXP1 = ceilling(double(EXP1)*0.75);
else if ((P1 + P2 + P3)/3 < 0.5){
    HP1 = ceilling(double(HP1)*0.85);
    EXP1 = ceilling(double(EXP1)*1.15);}
else{
    HP1 = ceilling(double(HP1)*.9);
    EXP1 = ceilling(double(EXP1)*1.2);
}
    EXP1 = Checker (EXP1,600,0);
    HP1 = Checker (HP1,666,0);
    return HP1 + EXP1 + M1;
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;
    HP1 = Checker (HP1,666,0);
    EXP1 = Checker (EXP1,600,0);
    HP2 = Checker (HP2,666,0);
    EXP2 = Checker (EXP2,600,0);
    int map[10][10];
    for (int j = 0; j < 10; j++){
        for (int i = 0; i < 10; i ++){
            map[i][j] = ((E3*j) + (i*2))*(i-j);
        }
    }
    int shortcut = -81*E3,ivalue = 0,jvalue = 0, return_value; //Smallest num when i = 0, j = 9
    for (int j = 0; j < 10; j++){
        for (int i = 0; i < 10; i ++){
        if (map[i][j] > E3*2) ivalue += 1;
        if (map[i][j] < -E3) jvalue += 1;
        }
    }

    int i = ivalue/10 + ivalue%10;
    if (i >= 10) i = i/10 + i%10;
    int j = jvalue/10 + jvalue%10;
    if (j >= 10) j = j/10 + j%10;

    int range = max(max(9-i,abs(0-i)),max(9-j,abs(0-j)));
            for (int e = 0; e  < range; e++){
                    if (j+e < 10 && i+e < 10){
                        int TR = int(map[i+e][j+e]);
                        shortcut = max(shortcut,TR);                    }
                    if (j+e < 10 && i-e > -1){
                        int BL = map[i-e][j+e];
                        shortcut = max(shortcut,BL);
                    }
                    if (j-e > -1 && i+e < 10){
                        int BR = map[i+e][j-e];
                        shortcut = max(shortcut,BR);
                    }   
                    if (i-e > -1 && j-e > -1){
                        int TL = map[i-e][j-e];
                        shortcut = max(shortcut,TL);
                    }
            }
    int tmap = map[i][j];
    shortcut= max(tmap,shortcut);
    if (shortcut >= abs(map[i][j])) {
    EXP1 = ceilling(double(EXP1 * 1.12));
    EXP2 = ceilling(double(EXP2 * 1.12));
    HP1 = ceilling(double(HP1 * 1.1));
    HP2 = ceilling(double(HP2 * 1.1));
    return_value = shortcut;
} else {
    EXP1 = ceilling(double(EXP1) * .88);
    EXP2 = ceilling(double(EXP2) * .88);
    HP1 = ceilling(double(HP1 * .9));
    HP2 = ceilling(double(HP2 * .9));
    return_value = map[i][j];
}
    HP1 = Checker (HP1,666,0);
    EXP1 = Checker (EXP1,600,0);
    HP2 = Checker (HP2,666,0);
    EXP2 = Checker (EXP2,600,0);
    return return_value;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    int se_error = 20, dup_error = 20, char_error = 20;
    string S = s, Email = email, se = Email.substr(0, Email.find('@'));
    
    if (S.length() < 8) return -1;
    if (S.length() > 20) return -2;

    for (int i = 0; i < S.length(); i++) {
        if (!(int(S[i]) == 33 || ( 35 <= int(S[i]) && int(S[i]) <= 37 ) || (64 <= int(S[i]) && int(S[i]) <= 90)|| (97 <= int(S[i]) && int(S[i]) <= 122) || (48 <= int(S[i]) && int(S[i] <= 57))) ){
            char_error = i;
            break;
        }
        if (i > 1 && S[i] == S[i - 1] && S[i] == S[i - 2]) {
            dup_error = i;
            break;
        }
    }

    if (S.find(se) != string::npos)
        se_error = S.find(se);

    if (se_error != 20 && se_error == min(char_error, se_error))
        return -(300 + se_error);
    else if (dup_error != 20 && dup_error == min(min(char_error, se_error), dup_error))
        return -(398 + dup_error);
    else if (S.find('@') == string::npos && S.find('#') == string::npos && S.find('%') == string::npos && S.find('$') == string::npos && S.find('!') == string::npos)
        return -5;
    else if (char_error != 20 && char_error == min(char_error, se_error))
        return char_error;

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxi = 0, position = 0;
    string last_pass;

    for (int i = 0; i < num_pwds; i++) {
        int amount = 0;
        for (int e = 0; e < num_pwds; e++) {
            if (strcmp(arr_pwds[i], arr_pwds[e]) == 0) {
                amount++;
            }
        }

        if (amount > maxi) {
            maxi = amount;
            position = i;
            last_pass = arr_pwds[i];
        } else if (amount == maxi) {
            if (strlen(arr_pwds[i]) > last_pass.length()) {
                last_pass = arr_pwds[i];
                position = i;
            }
        }
    }

    return position;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////