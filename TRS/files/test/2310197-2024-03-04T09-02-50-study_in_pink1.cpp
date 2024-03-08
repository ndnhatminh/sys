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

//set input
float checkHP(float HP, int min = 0, int max = 666) {
    HP =   (HP > max)? max: (HP < min)? min: HP;
    return HP;
}

float checkEXP(float EXP, int min = 0, int max = 600) {
    EXP =   (EXP > max)? max: (EXP < min)? min: EXP;
    return EXP;
}

float checkM(float M, int min = 0, int max = 3000) {
    M =   (M > max)? max: (M < min)? min: M;
    return M;
}

//function sp task 2
bool checkSquared(int n){
    float a = round(sqrt(n)) - sqrt(n);
	if (a == 0)
		return 1;
	else 
		return 0;
}

// function sp task 4
string extractSeFromEmail(const char* email) {
    const char* atPosition = strchr(email, '@');
    if (atPosition != nullptr) {
        return string(email, atPosition - email);
    }
    return ""; 
}

// function sp task 5
int setMeetPoint (int n){
    if (n < 10){
        return n;
    }
    while (n >= 10){
        n = (n / 10) + (n % 10);
    }
   return n;
    
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    float EXP1_test, EXP2_test; int D;
    EXP1_test = exp1; EXP2_test = exp2;
    EXP1_test = checkEXP(EXP1_test); EXP2_test = checkEXP(EXP2_test);
    if (e1 < 0 || e1 >99){
        return -99;
    }else if(e1 <= 3){
        switch (e1)
        {
        case 0:
            EXP2_test += 29;
            EXP2_test = checkEXP(EXP2_test);
            break;
        case 1:
            EXP2_test += 45;
            EXP2_test = checkEXP(EXP2_test);
            break;
        case 2:
            EXP2_test += 75;
            EXP2_test = checkEXP(EXP2_test);
            break;
        case 3:
            EXP2_test += 29 + 45 + 75;
            EXP2_test = checkEXP(EXP2_test);
            break;
        }
        D = e1*3 + EXP1_test*7;
        if (D % 2 == 0){
            EXP1_test += ((float)D/200); EXP1_test= ceil(EXP1_test);
            EXP1_test = checkEXP(EXP1_test);
        }else {
            EXP1_test -= ((float)D/100); EXP1_test= ceil(EXP1_test);
            EXP1_test = checkEXP(EXP1_test);
        }
        exp1 = ceil(EXP1_test);
        exp2 = ceil(EXP2_test);
    }else {
        if (e1 <= 19){
            EXP2_test += ((float)e1/4 + 19); EXP2_test= ceil(EXP2_test);
            EXP2_test = checkEXP(EXP2_test);
        }else if (e1 <= 49){
            EXP2_test += ((float)e1/9 + 21); EXP2_test= ceil(EXP2_test);
            EXP2_test = checkEXP(EXP2_test);
        }else if (e1 <= 65){
            EXP2_test += ((float)e1/16 + 17);EXP2_test= ceil(EXP2_test);
            EXP2_test = checkEXP(EXP2_test);
        }else if (e1 <= 79){
            EXP2_test += ((float)e1/4 + 19); EXP2_test = ceil(EXP2_test);
            EXP2_test = checkEXP(EXP2_test);
            EXP2_test = (EXP2_test > 200)? (EXP2_test + ((float)e1/9 + 21)): EXP2_test; EXP2_test = ceil(EXP2_test);
            EXP2_test = checkEXP(EXP2_test);
        }else if (e1 <= 99){
            EXP2_test += ((float)e1/4 + 19); EXP2_test = ceil(EXP2_test);
            EXP2_test = checkEXP(EXP2_test);
            EXP2_test += ((float)e1/9 + 21); EXP2_test = ceil(EXP2_test);
            EXP2_test = checkEXP(EXP2_test);
            if (EXP2_test > 400){
                EXP2_test += ((float)e1/16 + 17); EXP2_test = ceil(EXP2_test);
                EXP2_test = checkEXP(EXP2_test);
                EXP2_test = (EXP2_test * 1.15); EXP2_test = ceil(EXP2_test);
                EXP2_test = checkEXP(EXP2_test);
            }
            
        }
        EXP1_test -= e1;
        EXP1_test = checkEXP(EXP1_test);
        exp1 = ceil(EXP1_test);
        exp2 = ceil(EXP2_test);
    }    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int squaredLess, squaredGtr, S;
    float P1, P2, P3, P;
    float EXP1_test, HP1_test, halfM1, sumFee;
    EXP1_test = EXP1; EXP1_test = checkEXP(EXP1_test);
    HP1_test = HP1; HP1_test = checkHP(HP1_test);
    M1 = checkM(M1);
    halfM1 = 0.5* M1;
    sumFee = 0; 
    
    if (E2 < 0 || E2 > 99){
        return -99;
    }else {
        // Road 1
    

    if (EXP1 >= 576 ){
        S = 576;
    }else{
        for (int i = EXP1; i >= 0; i--){
            bool test = checkSquared(i);
            if (test == 1){
                squaredLess = i;
                break;
            }
        }
        
        for (int i = EXP1; i <= 600; i++){
            bool test = checkSquared(i);
            if (test == 1){
                squaredGtr = i;
                break;
            }
        }

        S = ((EXP1 - squaredLess) < (squaredGtr - EXP1))? squaredLess: squaredGtr;       
    }
    P1 = (EXP1 >= S) ? 1 : (((float)EXP1/S +80)/123);

    // Road 2
    if ((E2 % 2) != 0){
        if (M1 == 0){
            HP1_test *= 0.83; HP1_test = ceil(HP1_test);
            HP1_test = checkHP(HP1_test);
            EXP1_test *= 1.17; EXP1_test = ceil(EXP1_test);
            EXP1_test = checkEXP(EXP1_test); 
        }
        while (sumFee <= halfM1) {
            //su kien 1
            M1 = (HP1_test < 200) ? (M1 -150) : (M1 - 70);
            M1 = checkM(M1);
            sumFee = (HP1_test < 200) ? (sumFee + 150) : (sumFee + 70);
            HP1_test = (HP1_test < 200) ? (HP1_test * 1.3) : (HP1_test * 1.1);
            HP1_test = ceil(HP1_test); HP1_test = checkHP(HP1_test);
            
            if (sumFee > halfM1){
                HP1_test *= 0.83; HP1_test = ceil(HP1_test);
                HP1_test = checkHP(HP1_test);
                EXP1_test *= 1.17; EXP1_test = ceil(EXP1_test);
                EXP1_test = checkEXP(EXP1_test);
                break;
            }

            //su kien 2
            M1 = (EXP1_test < 400) ? (M1 - 200) : (M1 -120);
            M1 = checkM(M1);
            sumFee = (EXP1_test < 400) ? (sumFee + 200) : (sumFee + 120);
            EXP1_test *= 1.13; EXP1_test = ceil(EXP1_test);
            EXP1_test = checkEXP(EXP1_test);
            if (sumFee > halfM1){
                HP1_test *= 0.83; HP1_test = ceil(HP1_test);
                HP1_test = checkHP(HP1_test);
                EXP1_test *= 1.17; EXP1_test = ceil(EXP1_test);
                EXP1_test = checkEXP(EXP1_test);
                break;
            }

            //su kien 3
            M1 = (EXP1_test < 300) ? (M1 - 100) : (M1 - 120);
            M1 = checkM(M1);
            sumFee = (EXP1_test < 300) ? (sumFee + 100) : (sumFee + 120);
            EXP1_test *= 0.9; EXP1_test = ceil(EXP1_test);
            EXP1_test = checkEXP(EXP1_test);
            if (sumFee > halfM1){
                HP1_test *= 0.83; HP1_test = ceil(HP1_test);
                HP1_test = checkHP(HP1_test);
                EXP1_test *= 1.17; EXP1_test = ceil(EXP1_test);
                EXP1_test = checkEXP(EXP1_test);
                break;
            }
        }
    }else {
        //su kien 1
        if (M1 != 0){
            M1 = (HP1_test < 200) ? (M1 -150) : (M1 - 70);
            M1 = checkM(M1);
            HP1_test = (HP1_test < 200) ? (HP1_test * 1.3) : (HP1_test * 1.1);
            HP1_test = ceil(HP1_test); HP1_test = checkHP(HP1_test);
            
            // su kien 2
            if (M1 != 0){ 
                M1 = (EXP1_test < 400) ? (M1 - 200) : (M1 -120);
                M1 = checkM(M1);
    
                EXP1_test *= 1.13; EXP1_test = ceil(EXP1_test);
                EXP1_test = checkEXP(EXP1_test);
                // su kien 3
                if (M1 != 0){
                    M1 = (EXP1_test < 300) ? (M1 - 100) : (M1 - 120);
                    M1 = checkM(M1);            
                    EXP1_test *= 0.9; EXP1_test = ceil(EXP1_test);
                    EXP1_test = checkEXP(EXP1_test);
                    
                    HP1_test *= 0.83; HP1_test = ceil(HP1_test);
                    HP1_test = checkHP(HP1_test);
                    EXP1_test *= 1.17; EXP1_test = ceil(EXP1_test);
                    EXP1_test = checkEXP(EXP1_test);

                }else {
                    HP1_test *= 0.83; HP1_test = ceil(HP1_test);
                    HP1_test = checkHP(HP1_test);
                    EXP1_test *= 1.17; EXP1_test = ceil(EXP1_test);
                    EXP1_test = checkEXP(EXP1_test);
                }
            }else{
            HP1_test *= 0.83; HP1_test = ceil(HP1_test);
            HP1_test = checkHP(HP1_test);
            EXP1_test *= 1.17; EXP1_test = ceil(EXP1_test);
            EXP1_test = checkEXP(EXP1_test); 
            }
        }else {
            HP1_test *= 0.83; HP1_test = ceil(HP1_test);
            HP1_test = checkHP(HP1_test);
            EXP1_test *= 1.17; EXP1_test = ceil(EXP1_test);
            EXP1_test = checkEXP(EXP1_test);
        }
        
       
    }
    EXP1 = EXP1_test;
    if (EXP1 <= 4){
        S = 4;
    }else if (EXP1 >= 576 ){
        S = 576;
    }else{
        for (int i = EXP1; i >= 0; i--){
            bool test = checkSquared(i);
            if (test == 1){
                squaredLess = i;
                break;
            }
        }
        
        for (int i = EXP1; i <= 600; i++){
            bool test = checkSquared(i);
            if (test == 1){
                squaredGtr = i;
                break;
            }
        }

        S = ((EXP1 - squaredLess) < (squaredGtr - EXP1))? squaredLess: squaredGtr;       
    }
    P2 = (EXP1 >= S) ? 1 : (((float)EXP1/S +80)/123);

    // Road 3
    int Pi[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10){
        P3 = 0.01*Pi[E2];
    }else{
        int sum = E2/10 + E2%10;
        int i = sum % 10;
        P3 = 0.01*Pi[i];
    }
    if ((P1 == 1) && (P2 == 1) && (P3 == 1)){
        EXP1_test *= 0.75; EXP1_test = ceil(EXP1_test);
        EXP1_test = checkEXP(EXP1_test);
    }else{
        P = (P1 + P2 + P3) / 3;
        EXP1_test = (P < 0.5) ? (EXP1_test * 1.15) : (EXP1_test * 1.2);
        EXP1_test = ceil(EXP1_test);
        EXP1_test = checkEXP(EXP1_test);

        HP1_test = (P < 0.5) ? (HP1_test * 0.85) : (HP1_test * 0.9);
        HP1_test = ceil(HP1_test);
        HP1_test = checkHP(HP1_test);
    }
    EXP1 = ceil(EXP1_test);
    HP1 = ceil(HP1_test);

    }
    
    
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 <  0 || E3 > 99){
        return -99;
    }
    const int SIZE = 10;
    int countPointGtr = 0, countPointLess = 0;
    int iMeet, jMeet;
    int maxPoint, taxiPoint, holmesPoint, maxLeft, maxRight;
    int iStartLeft, jStartLeft, iStartRight, jStartRight;
    float HP1_test, EXP1_test, HP2_test, EXP2_test;
    HP1_test = checkHP(HP1); EXP1_test = checkEXP(EXP1);
    HP2_test = checkHP(HP2); EXP2_test = checkEXP(EXP2);

    int mapTaxi[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
            mapTaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
            countPointGtr = (mapTaxi[i][j] > (E3 *2)) ? (countPointGtr + 1) : countPointGtr;
            countPointLess = (mapTaxi[i][j] < -E3) ? (countPointLess + 1) : countPointLess;
        }
    }

    iMeet = setMeetPoint(countPointGtr);
    jMeet = setMeetPoint(countPointLess);
    maxLeft = mapTaxi[iMeet][jMeet];
    maxRight = mapTaxi[iMeet][jMeet];
    iStartLeft = iMeet; jStartLeft = jMeet;
    iStartRight = iMeet; jStartRight = jMeet;

    // tim Max cho dg cheo trai
    while ((iStartLeft != 0) && (jStartLeft != 0)){
        iStartLeft = iStartLeft - 1;
        jStartLeft = jStartLeft - 1;
    }
    for (int n = 1; n < SIZE; ++n){
        if (((iStartLeft + n) < SIZE) && ((jStartLeft + n) < SIZE)){
            maxLeft = (maxLeft < mapTaxi[iStartLeft + n][jStartLeft + n]) ? mapTaxi[iStartLeft + n][jStartLeft + n] : maxLeft;
        }
    }

    // Tim Max cho dg cheo phai
    while (iStartRight != 0 && jStartRight != (SIZE -1)){
        iStartRight = iStartRight - 1;
        jStartRight = jStartRight + 1;
    }
    for (int n = 1; n < SIZE; ++n){
        if (((iStartRight + n) < SIZE) && ((jStartRight - n) >= 0)){
            maxRight = (maxRight < mapTaxi[iStartRight + n][jStartRight - n]) ? mapTaxi[iStartRight + n][jStartRight - n] : maxRight;
        }
    }

    maxPoint = (maxLeft > maxRight) ? maxLeft : maxRight;
    holmesPoint = abs(maxPoint);
    taxiPoint = abs(mapTaxi[iMeet][jMeet]);

    EXP1_test = (holmesPoint < taxiPoint) ? (EXP1_test * 0.88) : (EXP1_test * 1.12);
        EXP1_test = ceil(EXP1_test); EXP1_test = checkEXP(EXP1_test);
    EXP2_test = (holmesPoint < taxiPoint) ? (EXP2_test * 0.88) : (EXP2_test * 1.12);
        EXP2_test = ceil(EXP2_test); EXP2_test = checkEXP(EXP2_test);
    HP1_test = (holmesPoint < taxiPoint) ? (HP1_test * 0.9) : (HP1_test * 1.1);
        HP1_test = ceil(HP1_test); HP1_test = checkHP(HP1_test);
    HP2_test = (holmesPoint < taxiPoint) ? (HP2_test * 0.9) : (HP2_test * 1.1);
        HP2_test = ceil(HP2_test); HP2_test = checkHP(HP2_test);

    EXP1 = EXP1_test; HP1 = HP1_test;
    EXP2 = EXP2_test; HP2 = HP2_test;

    if (taxiPoint > holmesPoint){
        return mapTaxi[iMeet][jMeet];
    }else
        return maxPoint;
    
    
}

// Task 4
int checkPassword(const char * s, const char * email) {
    int sLength = strlen(s);
    if (sLength < 8) {
        return -1; 
    }
    if (sLength > 20) {
        return -2; 
    }
    string se = extractSeFromEmail(email);
  
    if (strstr(s, se.c_str()) != nullptr) {
        return -(300 + strstr(s, se.c_str()) - s); 
    }

   
    for (int i = 0; i < sLength - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i); 
        }
    }
    
    
    
    bool specialChar = false;
    for (int i = 0; i < sLength; ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            specialChar = true;
            break;
        }
    }
    if (!specialChar) {
        return -5; 
    }
    
    for (int i = 0; i < sLength; ++i) {
        if (!isalnum(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') {
            return i; 
        }
    }
    
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxCount = 0; 
    int maxLength = 0; 
    int idCorrectPwd = -1; 

    for (int i = 0; i < num_pwds; ++i) {
        const char* pwd = arr_pwds[i];
        int lenPwd = strlen(pwd);

       
        int count = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(pwd, arr_pwds[j]) == 0) {
                ++count;
            }
        }

        
        if (count > maxCount || (count == maxCount && lenPwd > maxLength)) {
            maxCount = count;
            maxLength = lenPwd;
            idCorrectPwd = i;
        }
    }

    return idCorrectPwd;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////