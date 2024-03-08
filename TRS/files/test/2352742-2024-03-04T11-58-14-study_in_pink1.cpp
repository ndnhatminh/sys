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

//Helper function
void calibrateEXP(int & exp){
    if(exp < 0) exp = 0;
    else if(exp > 600) exp = 600;
}

void calibrateHP(int & HP){
    if(HP < 0) HP = 0;
    else if(HP > 666) HP = 666;
}

void calibrateM(int & M){
    if(M < 0) M = 0;
    else if(M > 3000) M = 3000;
}

bool road2(int & HP1, int & EXP1, int & M, double refM){
    if(M < refM) return false;
    if(HP1 < 200){
        HP1 = ceil((float)(1.3*HP1));
        M = M - 150;
    }
    else{
        HP1 = ceil((float)(1.1*HP1));
        M = M - 70;
    }
    calibrateHP(HP1);
    if(M < refM) return false;
    if(EXP1 < 400){
        M = M - 200;
    }
    else{
        M = M - 120;
    }
    EXP1 = ceil((float)(1.13*EXP1));
    calibrateEXP(EXP1);
    if(M < refM) return false;
    if(EXP1 < 300){
        M = M - 100;
    }
    else{
        M = M - 120;
    }
    EXP1 = ceil((float)(0.9*EXP1));
    calibrateEXP(EXP1);
    if(M < refM) return false;
    return true;
}

int shortenNumber(int num){
    if(num / 10 > 0){
        num = shortenNumber(num%10 + num/10);
    }
    return num;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1 < 0 || e1 > 99){
        return -99;
    }
    calibrateEXP(exp1);
    calibrateEXP(exp2);
    if(e1 < 4){
        switch (e1)
        {
            case 3:
                exp2 = exp2 + 74;
            case 2:
                exp2 = exp2 + 30;
            case 1:
                exp2 = exp2 + 16;
            case 0:
                exp2 = exp2 + 29;
                break;
            default:
                break;
        }
        int D = e1*3 + exp1*7;
        if(D % 2 == 0){
            exp1 = exp1 + ceil(D/200.0);
        }
        else{
            exp1 = exp1 + ceil(-D/100.0);
        }
        calibrateEXP(exp1);
        calibrateEXP(exp2);
        return exp1 + exp2;
    }
    if(e1 < 20){
        exp2 = exp2 + ceil(e1/4.0) + 19;
    }
    else if(e1 < 50){
        exp2 = exp2 + ceil(e1/9.0) + 21;
    }
    else if(e1 < 66){
        exp2 = exp2 + ceil(e1/16.0) + 17;
    }
    else if(e1 < 80){
        exp2 = exp2 + ceil(e1/4.0) + 19;
        if(exp2 > 200){
            exp2 = exp2 + ceil(e1/9.0) + 21;
        }
    }
    else{
        exp2 = exp2 + ceil(e1/4.0) + 19;
        exp2 = exp2 + ceil(e1/9.0) + 21;
        if(exp2 > 400){
            exp2 = exp2 + ceil(e1/16.0) + 17;
            //If Watson is explained by Sherlock with all 3 information, Watson will be added 15% of the current EXP
            exp2 = ceil((float)(1.15*exp2));
        }
    }
    exp1 = exp1 - e1;
    calibrateEXP(exp1);
    calibrateEXP(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) { // i think change to E2 would be more suitable
    // TODO: Complete this function
    if(E2 < 0 || E2 > 99){
        return -99;
    }
    calibrateEXP(EXP1);
    calibrateHP(HP1);
    calibrateM(M1);
    // Road 1
    int S = pow(round(sqrt(EXP1)),2);
    double P1 = 1;
    if(EXP1 < S){
        P1 = (EXP1/(double)S + 80)/123;
    }

    // Road 2
    if(E2 % 2 == 0){
        road2(HP1, EXP1, M1, 0.00001);
    }
    else{
        double targetSpent = 0.5*M1;
        if(targetSpent == 0){
            targetSpent = 0.00001;
        }
        bool working = true;
        while(working){
            working = road2(HP1, EXP1, M1, targetSpent);
        }
    }
    HP1 = ceil((float)(0.83*HP1));
    EXP1 = ceil((float)(1.17*EXP1));
    calibrateEXP(EXP1);
    calibrateHP(HP1);
    calibrateM(M1);
    S = pow(round(sqrt(EXP1)),2);
    double P2 = 1;
    if(EXP1 < S){
        P2 = (EXP1/(double)S + 80)/123;
    }
    // Road 3
    short Ps[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P3 = Ps[(E2%10 + E2/10)%10]/100.0;

    //Sumup
    double P = (P1 + P2 + P3)/3.0;
    if(P == 1){
        EXP1 = ceil((float)(0.75*EXP1));
    }
    else if(P < 0.5){
        HP1 = ceil((float)(0.85*HP1));
        EXP1 = ceil((float)(1.15*EXP1));
    }
    else{
        HP1 = ceil((float)(0.9*HP1));
        EXP1 = ceil((float)(1.2*EXP1));
    }
    calibrateEXP(EXP1);
    calibrateHP(HP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 < 0 || E3 > 99){
        return -99;
    }
    calibrateEXP(EXP1);
    calibrateEXP(EXP2);
    calibrateHP(HP1);
    calibrateHP(HP2);
    int taxiPoints[10][10];
    int meetingI = 0;
    int meetingJ = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            int point =  ((E3 * j) + (i * 2)) * (i - j);
            taxiPoints[i][j] = point;
            if(point > 2*E3){
                meetingI = meetingI + 1;
            }
            else if(point < -E3){
                meetingJ = meetingJ + 1;
            }
        }
    }
    meetingI = shortenNumber(meetingI);
    meetingJ = shortenNumber(meetingJ);
    int taxiPoint = taxiPoints[meetingI][meetingJ];
    int homesPoint = -99999;
    int x=meetingI, y=meetingJ;
    do{
        x = x + 1;
        y = y + 1;
        if(x > 9){
            x = 10 - y;
            y = 0;
        }
        else if(y > 9){
            y = 10 - x;
            x = 0;
        }
        if(taxiPoints[x][y] > homesPoint){
            homesPoint = taxiPoints[x][y];
        }
    }
    while(x - meetingI != 0);
    do{
        x = x - 1;
        y = y + 1;
        if(x < 0){
            x = y - 1;
            y = 0;
        }
        else if(y > 9){
            y = x + 1;
            x = 9;
        }
        if(taxiPoints[x][y] > homesPoint){
            homesPoint = taxiPoints[x][y];
        }
    }
    while(x - meetingI != 0);
    homesPoint = abs(homesPoint);
    if(abs(taxiPoint) > homesPoint){
        EXP1 = ceil((float)(0.88*EXP1));
        EXP2 = ceil((float)(0.88*EXP2));
        HP1 = ceil((float)(0.9*HP1));
        HP2 = ceil((float)(0.9*HP2));
        calibrateEXP(EXP1);
        calibrateEXP(EXP2);
        calibrateHP(HP1);
        calibrateHP(HP2);
        return taxiPoint;
    }
    else{
        EXP1 = ceil((float)(1.12*EXP1));
        EXP2 = ceil((float)(1.12*EXP2));
        HP1 = ceil((float)(1.1*HP1));
        HP2 = ceil((float)(1.1*HP2));
        calibrateEXP(EXP1);
        calibrateEXP(EXP2);
        calibrateHP(HP1);
        calibrateHP(HP2);
        return homesPoint;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    const int slen = strlen(s);
    if(slen < 8)
        return -1;
    if(slen > 20)
        return -2;
    string newEmail = string(email);
    string newS = string(s);
    string se = string(email,0,newEmail.find('@'));
    size_t ePos = newS.find(se);
    if(ePos != string::npos){
        return -300 - ePos;
    }
    int subtraction[slen - 1];
    for(int i = 1; i < slen; i++){
        subtraction[i - 1] = s[i] - s[i-1];
    }
    for(int i = 0; i < slen - 2; i++){
        if(!(subtraction[i] || subtraction[i+1])){
            return -400 - i;
        }
    }
    bool hasSpecialChar = false;
    for(int i = 0; i < slen; i++){
        bool tempSpecialChar = s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!';
        hasSpecialChar = hasSpecialChar || tempSpecialChar;
    }
    if(!hasSpecialChar){
        return -5;
    }
    for(int i = 0; i < slen; i++){
        bool tempSpecialChar = s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!';
        if(tempSpecialChar || (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) ;
        else{
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int freq[num_pwds];
    int pwdLen[num_pwds];
    for(int i = 0; i < num_pwds; i++){
        const char * pwd = arr_pwds[i];
        freq[i] = 1;
        pwdLen[i] = strlen(pwd);
        for(int j = i+1; j < num_pwds; j++){
            if(strcmp(pwd, arr_pwds[j]) == 0){
                freq[i] = freq[i] + 1;
            }
        }
    }
    int maxFreq = -1;
    int maxIndex = -1;
    int maxLen = -1;
    for(int i = 0; i < num_pwds; i++){
        int tempFreq = freq[i];
        int tempLen = pwdLen[i];
        if(tempFreq > maxFreq || (tempFreq == maxFreq && tempLen > maxLen)){
            maxFreq = tempFreq;
            maxLen = tempLen;
            maxIndex = i;
        }
    }
    return maxIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////