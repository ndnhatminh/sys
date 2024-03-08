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
/*I added this checkVar function to check EXP condition*/
int checkVarEXP(int n){
    if (n > 600){
        n = 600;
    }else if (n < 0){
        n = 0;
    }
    return n;
}
/*I added this checkVar function to check HP condition*/
int checkVarHP(int n){
    if (n > 666){
        n = 666;
    }else if (n < 0){
        n = 0;
    }
    return n;
}
/*I added this checkVar function to check M condition*/
int checkVarM(int n){
    if (n > 3000){
        n = 3000;
    }else if (n < 0){
        n = 0;
    }
    return n;
}
/*I added the below case1W&S and case2W&S function*/
int case1W (int & exp2, int e1){
    if (e1 == 0){
        exp2 += 29;
    }else if (e1 == 1){
        exp2 += 45;
    }else if (e1 == 2){
        exp2 += 75;
    }else if (e1 == 3){
        exp2 += (29 + 45 + 75);
    }
    return exp2;
}
int case1S (int & exp1, int e1){
    int D = e1*3 + exp1*7;
    if (D % 2 == 0){
        exp1 = ceil(exp1 + D/200.0);
    }else (exp1 = ceil(exp1 - D/100.0));
    return exp1;
}

int case2W (int & exp2, int e1){
    double w1, w2, w3;
    w1 = ceil(e1/4.0 + 19);
    w2 = ceil(e1/9.0 + 21);
    w3 = ceil(e1/16.0 + 17);
    if (4 <= e1 && e1 <= 19){
        exp2 += w1;
    }else if (20 <= e1 && e1 <= 49){
        exp2 += w2;
    }else if (50 <= e1 && e1 <= 65){
        exp2 += w3;
    }else if (66 <= e1 && e1 <= 79){
        exp2 += w1;
        if (exp2 > 200){
            exp2 += w2;
        }else ;
    }else if (80 <= e1 && e1 <= 99){
        exp2 += (w1 + w2);
        if (exp2 > 400){
            exp2 += w3;
            exp2 = ceil(exp2 * 1.15);
        }else ;
    }
    return exp2;
}

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || 99 < e1){
    return -99;
    }else {
        exp1 = checkVarEXP(exp1);
        exp2 = checkVarEXP(exp2);
        if (0 <= e1 && e1 <= 3){
        //Watson case 1
        exp2 = checkVarEXP(case1W(exp2, e1));
        //Sherlock case 1
        exp1 = checkVarEXP(case1S(exp1, e1));
        }
        if (4 <= e1 && e1 <= 99){
        //Watson case 2
        exp2 = checkVarEXP(case2W(exp2, e1));
        //Sherlock case 2
        exp1 = checkVarEXP(exp1 - e1);
        }
        return exp1 + exp2;
    }

}


// Task 2
int nearSquare(int exp1){
    int s1, s2, s;
    s1 = floor(sqrt(exp1));
    s2 = ceil(sqrt(exp1));
    if (abs(exp1 - s1*s1) >= abs(exp1 - s2*s2)){
        s = s2;
    }else{
        s = s1;
    }
    return s*s;
}

void Road02Energy(int & HP1, int & M1, int & Paid){
    if (HP1 < 200){
        HP1 = checkVarHP(ceil(HP1 + HP1 * 0.3));
        M1 = checkVarM(M1 - 150);
        Paid += 150;
    }else {
        HP1 = checkVarHP(ceil(HP1 + HP1 * 0.1));
        M1 = checkVarM(M1 - 70);
        Paid += 70;
    }
}

void Road02Drive(int & EXP1, int & M1, int & Paid){
    if (EXP1 < 400){
        EXP1 = checkVarEXP(ceil(EXP1 + EXP1 * 0.13));
        M1 = checkVarM(M1 - 200);
        Paid += 200;
    }else {
        EXP1 = checkVarEXP(ceil(EXP1 + EXP1 * 0.13));
        M1 = checkVarM(M1 - 120);
        Paid += 120;
    }   
}

void Road02Home(int & EXP1, int & M1, int & Paid){
    if (EXP1 < 300){
        M1 = checkVarM(M1 - 100);
        Paid += 100;
        EXP1 = checkVarEXP(ceil(EXP1 * 0.9));
    }else {
        M1 = checkVarM(M1 - 120);
        Paid += 120;
        EXP1 = checkVarEXP(ceil(EXP1 * 0.9));
    }    
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || 99 < E2){
    return -99;
    }else {
        HP1 = checkVarHP(HP1);
        EXP1 = checkVarEXP(EXP1);
        M1 = checkVarM(M1);
        int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        double avgP;

        //ROAD 01
        double P1, Square1;
        Square1 = nearSquare(EXP1);
        //cout << "Nearest perfect square: " << Square1 << endl;
        if (EXP1 >= Square1){
            P1 = 100;
        }else {
            P1 = ((EXP1/Square1 + 80)/123)*100;
        }
        //cout << "P1: " << P1 << endl;
        
        //ROAD 02
        int halfM1 = M1*0.5;
        int Paid = 0;
        //For E2 is even
        if (E2 % 2 == 0){
            if (M1 == 0){
                HP1 = checkVarHP(ceil(HP1 * 0.83));
                EXP1 = checkVarEXP(ceil(EXP1 + EXP1 * 0.17));
            }else{
                Road02Energy(HP1, M1, Paid);
                if(M1 != 0){
                    Road02Drive(EXP1, M1, Paid);
                    if(M1 != 0){
                        Road02Home(EXP1, M1, Paid);
                    }else M1 = 0;
                }else M1 = 0;
                HP1 = checkVarHP(ceil(HP1 * 0.83));
                EXP1 = checkVarEXP(ceil(EXP1 + EXP1 * 0.17));
            }
        }

        //For E2 is odd
        if (E2 % 2 != 0){
            if (M1 == 0){
                HP1 = checkVarHP(ceil(HP1 * 0.83));
                EXP1 = checkVarEXP(ceil(EXP1 + EXP1 * 0.17));
            }else{
                while (Paid <= halfM1){
                    Road02Energy(HP1, M1, Paid);
                    if (Paid <= halfM1){
                        Road02Drive(EXP1, M1, Paid); 
                        if (Paid <= halfM1){
                            Road02Home(EXP1, M1, Paid);
                        }else break;
                    }else break;
                }
            HP1 = checkVarHP(ceil(HP1 * 0.83));
            EXP1 = checkVarEXP(ceil(EXP1 + EXP1 * 0.17));
            }

        }
        double P2, Square2;
        Square2 = nearSquare(EXP1);
        //cout << "Nearest perfect square: " << Square1 << endl;
        if (EXP1 >= Square2){
            P2 = 100;
        }else {
            P2 = ((EXP1/Square2 + 80)/123)*100;
        }

        //cout << "P2 = " << P2 << endl;

        //ROAD 03
        int i, a, b;
        double P3;
        if (0 <= E2 && E2 <= 9){
            i = E2;
            P3 = P[i];
        }else{
            a = E2 / 10;
            b = E2 % 10;
            i = (a + b) % 10;
            P3 = P[i];
        }
        //cout << "P3 = " << P3 << endl;

        if (P1 == 100 && P2 == 100 && P3 == 100){
            EXP1 = checkVarEXP(ceil(EXP1 * 0.75));
        }else{
            avgP = (P1 + P2 + P3)/3.0;
            if (avgP < 50){
                HP1 = checkVarHP(ceil(HP1 * 0.85));
                EXP1 = checkVarEXP(ceil(EXP1 + EXP1 * 0.15));
            }else{
                HP1 = checkVarHP(ceil(HP1 * 0.90));
                EXP1 = checkVarEXP(ceil(EXP1 + EXP1 * 0.2));
            }
        }
        return HP1 + EXP1 + M1;

    }

}

// Task 3
// TO Check change the 2 digit to 1 digit
int twotoONE(int a){
    int ten, unit;
    if (0 <= a && a <= 9){
        return a;
    }
    while (a > 9){
        ten = a / 10;
        unit = a % 10;
        a = ten + unit;
    }   
    return a;
}

int findMAXtwo(int num1, int num2){
    int max;
    if (num1 > num2){
        max = num1;
    }else max = num2;
    return max;
}

int findMAX(int a, int b, int c, int d){
    int max;
    int e = findMAXtwo(a, b);
    int f = findMAXtwo (c, d);
    max = findMAXtwo(e, f);
    return max;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || 99 < E3){
        return -99;
    }else{
        HP1 = checkVarHP(HP1);
        EXP1 = checkVarEXP(EXP1);
        HP2 = checkVarHP(HP2);
        EXP2 = checkVarEXP(EXP2);
    const int rowSize = 10, columnSize = 10;
    int Run[rowSize][columnSize];

    // Create matrix as demanded
    for (int row = 0; row < rowSize; row++){
        for (int column = 0; column < columnSize; column++){
            int taxi = ((E3 * column)+(row * 2)) * (row - column);
            Run[row][column] = taxi;
        }
    }

    // Find greater and smaller values
    int greater = 0, smaller = 0;
    for (int row = 0; row < rowSize; row++){
        for (int column = 0; column < columnSize; column ++){
            if (Run[row][column] > (E3 * 2)){
                greater += 1;
            }else if (Run[row][column] < (-E3)){
                smaller += 1;
            }   
        }
    }
    greater = twotoONE(greater);
    smaller = twotoONE(smaller);
    int maxleftup = 0, maxleftdown = 0, maxrightup = 0, maxrightdown = 0;

    int taxiabs = abs(Run[greater][smaller]);
    int taxi = Run[greater][smaller];
    // cout << "Greater: " << greater << endl;
    // cout << "Smaller: " << smaller << endl;
    // cout << "Taxi PTS: " << taxiabs << endl;

    //Find MAX-LEFT-UP
    for (int u = 0; greater - u >= 0 && smaller - u >= 0; u++  ){
        
        if (Run[greater - u][smaller - u] > maxleftup){
            maxleftup = Run[greater - u][smaller - u];
        }
        
    }
    // cout << "Max Left Up: " << maxleftup << endl;
    
    //Find MAX-LEFT-DOWN
    for (int u = 0; greater + u <= 9  && smaller - u >= 0; u++  ){
        
        if (Run[greater + u][smaller - u] > maxleftdown){
            maxleftdown = Run[greater + u][smaller - u];
        }
        
    }
    // cout << "Max Left Down: " << maxleftdown << endl;

    //Find MAX-RIGHT-UP
    for (int u = 0; greater - u >= 0  && smaller + u <= 9; u++  ){
        
        if (Run[greater - u][smaller + u] > maxrightup){
            maxrightup = Run[greater - u][smaller + u];
        }
        
    }
    // cout << "Max Right Up: " << maxrightup << endl; 
    
    //Find MAX-RIGHT-DOWN
    for (int u = 0; greater + u <= 9  && smaller + u <= 9; u++  ){
        
        if (Run[greater + u][smaller + u] > maxrightdown){
            maxrightdown = Run[greater + u][smaller + u];
        }
        
    }
    // cout << "Max Right Up: " << maxrightdown << endl;   

    int Sherlock = abs(findMAX(maxleftup, maxleftdown, maxrightup, maxrightdown));
    // cout << "Sherlock's PTS (Max among 4 number): " << Sherlock << endl;

    if (taxiabs > Sherlock){
        // cout << "CAN'T catch the taxi" << endl;
        EXP1 = checkVarEXP(ceil(EXP1 * 0.88));
        HP1 = checkVarHP(ceil(HP1 * 0.9));
        EXP2 = checkVarEXP(ceil(EXP2 * 0.88));
        HP2 = checkVarHP(ceil(HP2 * 0.9));
    }else {
        // cout << "CATCH the taxi" << endl;
        EXP1 = checkVarEXP(ceil(EXP1 + EXP1 * 0.12));
        HP1 = checkVarHP(ceil(HP1 + HP1 * 0.1));
        EXP2 = checkVarEXP(ceil(EXP2 + EXP2 * 0.12));
        HP2 = checkVarHP(ceil(HP2 + HP2 * 0.1));
        taxi = Sherlock; // Because return bigger value btw abs(taxi) & Sherlock
    }
    
    return taxi;
    }
    
}

// Task 4
//TO find out the odd character || no special
int isValid(const string& str) {
    bool withSC = false;

    for (int i = 0; i < str.length(); i++) {
        if (isalnum(str[i])) {
            // Character is alphanumeric
            continue;
        } else if (str[i] == '!' || str[i] == '#' || str[i] == '$' || str[i] == '%' || str[i] == '@') {
            // Found a special character
            withSC = true;
        } else {
            // Found an invalid character
            //cout << "Invalid character at position " << i << ": " << str[i] << endl;
            return i;
        }
    }

    if (!withSC) {
        //cout << "No special character in this password." << endl;
        return -5;
    }
    return -1;
}

//TO find 3 consecutive same value
int checkTriple(const char* s){
    int value =  -1;
    for (int i = 0; i < strlen(s) - 2; i++){
        if (s[i] == s[i+1] && s[i+1] == s[i+2]) {
            // Three consecutive characters found
            //cout << "Loop starts at: " << i << endl;
            value = i;
            break;
        }
    }
    return value;
}


int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int value;
    int MAX = 100;
    char se[MAX];
    int at;
    for (int i = 0; i < strlen(email); i++){
        if (email[i] == '@'){
            at = i;
            break;
        }
    }
    strncpy(se, email, at);
    se[at] = '\0'; // Null-terminate the substring
    const char *loopSE = strstr(s, se);

    if (strlen(s) < 8){
        value = -1;
        //cout << "Pass < 8" << endl;
    }else if (strlen(s) > 20){
        value = -2;
        //cout << "Pass > 20" << endl;
    }else if(loopSE != nullptr){ //nullptr: null pointer: has the memory address of a 0
        value =  -(300 + (loopSE - s));
        //cout << "Pass with SE" << endl;
    }else if(checkTriple(s) != -1){
        value =  -(400 + checkTriple(s));
        //cout << "Pass with TRIPLE" << endl;
    }else if (isValid(s) == -5){
        value = -5;
        // cout << "Pass with no SPECIAL" << endl;
    }else if((isValid(s) != -5) && (isValid(s) != -1)){
        value = isValid(s);
        // cout << "Pass with UNDEFINED character" << endl;
    }else{
        value = -10;
    }

    return value;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int countRepeat[30] = {0};
    int passLength[30] = {0};
    int maxAppear = 0, longestPass = 0;
    int value = -1;

    for (int i = 0; i < num_pwds; i++){
        //Find the length of pass
        // const char * pass = arr_pwds[i];
        passLength[i] = strlen(arr_pwds[i]);

        countRepeat[i] = 1; //Pass appears at least one time

        for (int j = 1 + i; j < num_pwds; j++){
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0){
                countRepeat[i]++; 
            }
        }
    }
    
    for (int i = 0; i < num_pwds; i++){
        if (maxAppear < countRepeat[i]){
            maxAppear = countRepeat[i];
        }
    }

    for (int i = 0; i < num_pwds; i++){
        if(countRepeat[i] == maxAppear){
            // cout << "Pass: " << arr_pwds[i] << " - Length: " << passLength[i] << endl;
            if(passLength[i] > longestPass){
                longestPass = passLength[i];
                // cout << "Longest pass with most iteration is: " << arr_pwds[i] << endl;
                value = i;
            }
        }
    }
    return value;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////