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


//LIMIT & ROUND
int liroHP(int HP){
    if (HP > 666){
        HP = 666;
    }
    if (HP < 0){
        HP = 0;
    }
    return ceil(HP);
}
int liroEXP(int EXP){
    if (EXP > 600){
        EXP = 600;
    }
    if (EXP < 0){
        EXP = 0;
    }
    return ceil(EXP);
}
int liroM(int M){
    if (M > 3000){
        M = 3000;
    }
    if (M < 0){
        M = 0;
    }
    return ceil(M);
}
int limiE(int E){
    if (E > 99 || E < 0){
        return -99;
    }
    return E;
}

//FIND THE NEAREST SQUARE
int fnearsqr(int n){
    if (sqrt(n)!= round(sqrt(n))){
       return round(sqrt(n))*round(sqrt(n));
    }else{
        return n;
    }
}

//CHECK THE LETTER
bool isnumorlt(char c) {
    return ((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9') || (c=='!') || (c=='@') || (c=='#') || (c=='$') || (c=='%'));
}
int validChar(string str) {
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (isnumorlt(c) == 0){
            return 0;
        }
    }
    return 1;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    e1 = limiE(e1);
    if (e1 == -99){
        return -99;
    }
    exp1 = liroEXP(exp1);
    exp2 = liroEXP(exp2);
    //4.1.1 Case 1
    if (e1<4){
        switch (e1){
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
                exp2 += (29 + 45 + 75);
                break;
        }
        
        int D = e1 * 3.0 + exp1 * 7.0;
        D % 2 == 0  ?  (exp1 = ceil(exp1 + (D/200.0))) : (exp1 = ceil(exp1 - (D/100.0)));
        exp1 = liroEXP(exp1);
        exp2 = liroEXP(exp2);
    //4.1.2 Case 2
    }else{
        switch (e1){
            case 4 ... 19:
                exp2 = ceil(exp2 + (e1/ 4.0) + 19);
                break;
            case 20 ... 49:
                exp2 = ceil(exp2 + (e1/ 9.0) + 21);
                break;
            case 50 ... 65:
                exp2 = ceil(exp2 + (e1/16.0) + 17);
                break;
            case 66 ... 79:
                exp2 = ceil(exp2 + (e1/ 4.0) + 19);
                if (exp2 > 200){
                    exp2 = ceil(exp2 + (e1/9.0) + 21);
                }
                break;
            case 80 ... 99:
                exp2 = ceil(exp2 + (e1/4.0) + 19);
                exp2 = ceil(exp2 + (e1/9.0) + 21);
                if (exp2 > 400){
                    exp2 = ceil(exp2 + (e1/16.0) + 17);
                    exp2 = ceil(exp2 * 1.15);
                }
                break;
        }
        exp1 -= e1;
        exp1 = liroEXP(exp1);
        exp2 = liroEXP(exp2);
        
    }
    
    return exp1 + exp2;
}



// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    HP1  = liroHP(HP1);
    EXP1 = liroEXP(EXP1);
    M1 = liroM(M1);
    E2 = limiE(E2);
    if (E2 == -99){
        return -99;
    }
    double P1=0, P2=0, P3=0, Pm=0;
    
//4.2.1 Road 01
    int S1 = fnearsqr(EXP1);
    S1>EXP1  ?  (P1 = ( ( (EXP1/S1) + 80) /123.0)*100) : (P1 = 100);
    
//4.2.2 Road 02
    int hMi1 = ceil(M1 * 0.5);
    do{
        HP1<200  ?  (M1 -= 150) : (M1 -= 70);
        HP1<200  ?  (HP1 = ceil(HP1 * 1.30)) : (HP1 = ceil(HP1 * 1.10));
        if (M1 < 0){
            break;
        }
        if (M1 < hMi1 && E2%2 != 0){
            break;
        }
        EXP1<400  ?  (M1 -= 200) : (M1 -= 120);
        EXP1 = ceil(EXP1 * 1.13);
        if (M1 < 0){
            break;
        }
        if (M1 < hMi1 && E2%2 != 0){
            break;
        }
        EXP1<300  ?  (M1 -= 100) : (M1 -= 120);
        EXP1 = ceil(EXP1 * 0.90);
        if (M1 < 0){
            break;
        }
        if (M1 < hMi1 && E2%2 != 0){
            break;
        }
    }while (M1 > hMi1 && M1 > 0 && E2%2!=0);
    HP1  = ceil(HP1  * 0.83);
    EXP1 = ceil(EXP1 * 1.17);
    int S2 = fnearsqr(EXP1);
    S2>EXP1  ?  (P2 = ( ( (EXP1/S2) + 80) /123.0) *100) : (P2 = 100);

//4.2.3 Road 03
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
      
    int pl3 = (E2%10 + (E2 - E2%10)/10) %10;
    E2<10  ?  (P3 = P[E2]) : (P3 = P[pl3]);

    if (P1==P2 && P2==P3 && P3==100){
        EXP1 = ceil(EXP1 * 0.75);
    }else{
        Pm = ceil((P1+P2+P3) /3.0);

        Pm<50  ?  (HP1  = ceil(HP1  * 0.85)) : (HP1  = ceil(HP1  * 0.90));
        Pm<50  ?  (EXP1 = ceil(EXP1 * 1.15)) : (EXP1 = ceil(EXP1 * 1.20));
    }
    HP1  = liroHP(HP1);
    EXP1 = liroEXP(EXP1);
    M1   = liroM(M1);
    
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    E3 = limiE(E3);
    if (E3 == -99){
        return -99;
    }
    int map[10][10];
    int I = 0;
    int J = 0;
//Create Map
    for (int j=0; j<10; j++){
        for (int i=0; i<10; i++){
            map[i][j] = ((E3*j) + (i*2)) * (i-j);
            if (map[i][j] > (E3*2)){
                I++;
            }
            if (map[i][j] < (-E3)){
                J++;
            }
        }
    }
//Find Meeting Spot
    if (I > 9){
        do{
            I = I%10 + (I - I%10)/10;
        }while (I > 9);
    }
    if (J > 9) {
        do{
            J= J%10 + (J - J%10)/10;
        }while (J > 9);
    }
    
//Find Max of 2 diagonal AKA Sherlock & Watson's grade
    int SWgr = map[I][J];
    //LEFT DIAGONAL
    if (I>J){
        for(int i = -J; i < 10-I;i++){
            SWgr = max(SWgr, map[I+i][J+i]);
        }
    }else{
        for(int i = -I; i < I-10 ;i++){
            SWgr = max(SWgr, map[I+i][J-i]);
        }
    }
    //RIGHT DIAGONAL
    if ((I<4 && J<4) || (I<10-J && I==10-J)){
        for(int i = -I; i < I+1;i++){
            SWgr = max(SWgr, map[I-i][I+i]);
        }
    }
    if((I>5 && J>5) || (I>10-J && I==10-J)){
        for(int i = 9-I; i > J-10 ;i--){
            SWgr = max(SWgr, map[J-i][I+i]);
        }
    }

// Taxi's grade
    int taxigr = map[I][J];
    
    if (abs(taxigr) > SWgr){
        EXP1 = ceil(EXP1 - EXP1* 0.12);
        HP1  = ceil(HP1  - HP1 * 0.10);
        EXP2 = ceil(EXP2 - EXP2* 0.12);
        HP2  = ceil(HP2  - HP1 * 0.10);
        HP1  = liroHP(HP1);
        EXP1 = liroEXP(EXP1);
        HP2  = liroHP(HP2);
        EXP2 = liroEXP(EXP2);
        return taxigr;
    }else{
        EXP1 = ceil(EXP1 + EXP1* 0.12);
        HP1  = ceil(HP1  + HP1 * 0.10);
        EXP2 = ceil(EXP2 + EXP2* 0.12);
        HP2  = ceil(HP2  + HP1 * 0.10);
        HP1  = liroHP(HP1);
        EXP1 = liroEXP(EXP1);
        HP2  = liroHP(HP2);
        EXP2 = liroEXP(EXP2);
        return SWgr;
    }
    return -1;
}


// Task 4
int checkPassword(const char * s, const char * email) {
//Find the words before "@"
    string em = email;
    double position = em.find("@");
    string se;
    for (int i = 0; i < position; i++) {
        se += email[i];
    }
//CHECK PASSWORD
    string Pass = s;
//Check length
    if(Pass.length() < 8){
        return -1;
    }else if(Pass.length() > 20){
        return -2;
    }
//Check if contain <se>
    int sei = -1;
    for (int i = 0; i < Pass.length(); i++) {
        if (Pass[i] == se[0]) {
            bool match = true;
            for (int j = 1; j < se.length(); j++) {
                if (Pass[i + j] != se[j]) {
                    match = false;
                    break;
                }
            }
            if (match == true) {
                sei = i;
                return -(300+sei);
                break;
            }
        }
    }
//Check 2 consecutive and identical characters
    for(int i = 0; i < Pass.length()-2; i++){
        if(Pass[i]==Pass[i+1] && Pass[i+1]==Pass[i+2]){
            return -(400+i);
            break;
        }
    }
//Check character & Special character
    int count = 0;
    if (validChar(Pass) == 0){
        return -5;
    }else{
        for(int i = 0; i < Pass.length(); i++){
            if(Pass[i]=='!' || Pass[i]=='@' || Pass[i]=='#' || Pass[i]=='$' || Pass[i]=='%'){
                break;
            }else{
                count++;
            }
            if (count == Pass.length()){
                return -5;
            }
        }
    }
    
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    char AccuratePass[20];
    int bestCount = 0;
    int bestLength = 0;
    int AccuratePosition = -1;

//Process on each password
    for (int i = 0; i < num_pwds; ++i) {
        const char* currentPass = arr_pwds[i];
        int currentCount = 1;

        // Check repetition of current password
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(currentPass, arr_pwds[j]) == 0) {
                currentCount++;
            }
        }

        // Check the conditions on the current password
        if (currentCount > bestCount ||
            (currentCount == bestCount && strlen(currentPass) > bestLength)) {
            bestCount = currentCount;
            bestLength = strlen(currentPass);
            strcpy(AccuratePass, currentPass);
            AccuratePosition = i;
        }
    }

    return AccuratePosition;
}
    

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
