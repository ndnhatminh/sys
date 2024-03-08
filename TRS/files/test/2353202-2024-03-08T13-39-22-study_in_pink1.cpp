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

//limit value for EXP, HP, & M.
int liEXP(int x){
    if(x < 0){
        return 0;
    }else if(x > 600){
        return 600;
    }
    return x;
}

int liHP(int x){
    if(x < 0){
        return 0;
    }else if(x > 666){
        return 666;
    }
    return x;
}

int liM(int x){
    if(x < 0){
        return 0;
    }else if(x > 3000){
        return 3000;
    }
    return x;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if(e1 < 0 || e1 > 99){
        return - 99;
    }
    exp1 = liEXP(exp1);
    exp2 = liEXP(exp2);

    if(e1 >= 0 && e1 <=3){
        switch(e1){
            case 0:
                exp2 = liEXP(exp2 + 29);
                break;
            case 1:
                exp2 = liEXP(exp2 + 45);
                break;
            case 2:
                exp2 = liEXP(exp2 +75);
                break;
            case 3:
                exp2 = liEXP(exp2 + 29 + 45 + 75);
                break;
        }

        int D = e1*3 + exp1*7;
        if(D % 2 == 0){
            exp1 = liEXP(ceil(exp1 + D/200.00));
        }else{
            exp1 = liEXP(ceil(exp1 - D/100.00));
        }

    }else if(e1 >=4 && e1 <= 99){
        if(e1 >= 4 && e1 <= 19){
            exp2 = liEXP(ceil(exp2 + e1/4.00 + 19));
        }else if(e1 >= 20 && e1 <= 49){
            exp2 = liEXP(ceil(exp2 + e1/9.00 + 21));
        }else if(e1 >= 50 && e1 <= 65){
            exp2 = liEXP(ceil(exp2 + e1/16.00 + 17));
        }else if(e1 >= 66 && e1 <= 79){
            exp2 = liEXP(ceil(exp2 + e1/4.00 + 19));
            if(exp2 > 200){
                exp2 = liEXP(ceil(exp2 + e1/9.00 + 21));
            }
        }else if(e1 >= 80 && e1 <= 99){
            exp2 = liEXP(ceil(exp2 + e1/4.00 + 19));
            exp2 = liEXP(ceil(exp2 + e1/9.00 + 21));
            if(exp2 > 400){
                exp2 = liEXP(ceil(exp2 + e1/16.00 + 17));
                exp2 = liEXP(exp2 + ceil(15.00*exp2/100));
            }
        }
        exp1 = liEXP(exp1 - e1);
    }
    return exp1 + exp2;
}

// Task 2
//finding the nearest perfect square.
int nps(int &x){
    int lowerSqrt = sqrt(x);
    int higherSqrt = lowerSqrt + 1;

    int lowerSquare = higherSqrt*higherSqrt;
    int higherSquare = lowerSqrt*lowerSqrt;

    if(abs(x - lowerSquare) < abs(x - higherSquare)){
        return lowerSquare;
    }else{
        return higherSquare;
    }
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(E2 < 0 || E2 > 99){
        return - 99;
    }
    HP1 = liHP(HP1);
    EXP1 = liEXP(EXP1);
    M1 = liM(M1);

    //road 1.
    int S = nps(EXP1);
    double P1;

    if(EXP1 >= S){
        P1 = 1;
    }else{
        P1 = (EXP1*1.00/S + 80)/123;
    }

    //road 2.
    int const originalMoney = M1;
    int half = originalMoney*0.5; //a half of the original money.
    int moneySpent = 0;

    if(E2 % 2 != 0){
        while(moneySpent <= half && M1 > 0){
            if(HP1 < 200){
                HP1 = liHP(HP1 + ceil(30.00*HP1/100));
                M1 = liM(M1 - 150);
                moneySpent += 150;
            }else{
                HP1 = liHP(HP1 + ceil(10.00*HP1/100));
                M1 = liM(M1 - 70);  
                moneySpent += 70;
            }

            if(moneySpent > half || M1 <= 0){
                break;
            }

            if(EXP1 < 400){
                EXP1 = liEXP(EXP1 + ceil(13.00*EXP1/100));
                M1 = liM(M1 - 200);
                moneySpent += 200;
            }else{
                EXP1 = liEXP(EXP1 + ceil(13.00*EXP1/100));
                M1 = liM(M1 - 120);
                moneySpent += 120;
            }
            
            if(moneySpent > half || M1 <= 0){
                break;
            }

            if(EXP1 < 300){
                EXP1 = liEXP(EXP1 - floor(10.00*EXP1/100));
                M1 = liM(M1 - 100);
                moneySpent += 100;
            }else{
                EXP1 = liEXP(EXP1 - floor(10.00*EXP1/100));
                M1 = liM(M1 - 120);
                moneySpent += 120;
            }

            if(moneySpent > half || M1 <= 0){
                break;
            }
        }

        HP1 = liHP(HP1 - floor(17.00*HP1/100));
        EXP1 = liEXP(EXP1 + ceil(17.00*EXP1/100));
        
    }else{
        if(M1 > 0){
            if(HP1 < 200){
                HP1 = liHP(HP1 + ceil(30.00*HP1/100));
                M1 = liM(M1 - 150);
            }else{
                HP1 = liHP(HP1 + ceil(10.00*HP1/100));
                M1 = liM(M1 - 70);  
            }
        }

        if(M1 > 0){
            if(EXP1 < 400){
                EXP1 = liEXP(EXP1 + ceil(13.00*EXP1/100));
                M1 = liM(M1 - 200);
            }else{
                EXP1 = liEXP(EXP1 + ceil(13.00*EXP1/100));
                M1 = liM(M1 - 120);
            }
        }

        if(M1 > 0){
            if(EXP1 < 300){
                EXP1 = liEXP(EXP1 - floor(10.00*EXP1/100));
                M1 = liM(M1 - 100);
            }else{
                EXP1 = liEXP(EXP1 - floor(10.00*EXP1/100));
                M1 = liM(M1 - 120);
            }
        }
            
        HP1 = liHP(HP1 - floor(17.00*HP1/100));
        EXP1 = liEXP(EXP1 + ceil(17.00*EXP1/100));
    }

    S = nps(EXP1);
    double P2;

    if(EXP1 >= S){
        P2 = 1;
    }else{
        P2 = (EXP1*1.00/S + 80)/123;
    }

    //road 3.
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if(E2 >= 0 && E2 < 10){
        i = E2;
    }else if(E2 >= 10){
        int sum = E2/10.00 + E2%10;
        i = sum % 10;
    }

    double P3 = P[i];
    P3 = P3/100.00;

    //final.
    double pAvg = (P1 + P2 + P3)/3.00;
    if(P1 == 1 && P2 == 1 && P3 == 1){
        EXP1 = liEXP(EXP1 - floor(25.00*EXP1/100));
    }else if(pAvg < 0.5){
        HP1 = liHP(HP1 - floor(15.00*HP1/100));
        EXP1 = liEXP(EXP1 + ceil(15.00*EXP1/100));
    }else if(pAvg >= 0.5){
        HP1 = liHP(HP1 - floor(10.00*HP1/100));
        EXP1 = liEXP(EXP1 + ceil(20.00*EXP1/100));
    }
    return HP1 + EXP1 + M1;
}

// Task 3
//sum of digits
int sumOD(int x){ 
    int sum = 0;
    if(x < 10){
        return x;
    }else{
        sum = x/10 + x%10;
        while(sum > 9){
            sum = sumOD(sum);
        }
        return sum;
    }
}   

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3){
    if(E3 < 0 || E3 > 99){
        return - 99;
    }
    HP1 = liHP(HP1);
    EXP1 = liEXP(EXP1);
    HP2 = liHP(HP2);
    EXP2 = liEXP(EXP2);

    int pos = 0, neg = 0;
    int i, j, meetRow, meetCol, sum;
    int dR1 = -9999, dR2 = -9999, dL1 = -9999, dL2 = -9999, dL, dR, maxD; //max diagonal from right & left
    
    //taxi score
    int taxiScore[10][10] = {0};
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j ++){
            taxiScore[i][j] = ((E3*j) + (i*2))*(i - j);

            if(taxiScore[i][j] > 0){
                if(taxiScore[i][j] > E3*2){
                    pos += 1;
                }
            }else if(taxiScore[i][j] < 0){
                if(taxiScore[i][j] < -E3){
                    neg += 1;
                }
            }
        }
    }
    
    //the coordinate where they meet.
    meetRow = sumOD(pos);
    meetCol = sumOD(neg);

    //Sherlock & Watson scores
    //dL1: cheo trai di len.
    i = meetRow - 0;
    j = meetCol - 0;
    while(i >= 0 && j >= 0){
        if(i < 0 || j < 0){
            break;
        }else{
            dL1 = max(dL1, taxiScore[i][j]);
            i--;
            j--;
        }
    }

    //dL2: cheo trai di xuong.
    i = meetRow + 1;
    j = meetCol + 1;
    while(i > meetRow && i < 10 && j > meetCol && j < 10){
        if(i > 10 || j > 10){
            break;
        }else{
            dL2 = max(dL2, taxiScore[i][j]);
            i++;
            j++;
        }
    }
    
    //max tren duong cheo trai.
    if(dL1 > dL2){
        dL = dL1;
    }else{
        dL = dL2;
    }

    //dR1: cheo phai di len.
    i = meetRow - 0;
    j = meetCol - 0;
    while(i >= 0 && j < 10){
        if(i < 0 || j >= 10){
            break;
        }else{
            dR1 = max(dR1, taxiScore[i][j]);
            i--;
            j++;
        }
    }

    //dR2: cheo phai di xuong.
    i = meetRow + 1;
    j = meetCol - 1;
    while(i > meetRow && i < 10 && j >= 0 && j < meetCol){
        if(i >= 10 || j < 0){
            break;
        }else{
            dR2 = max(dR2, taxiScore[i][j]);
            i++;
            j--;
        }
    }

    //max tren duong cheo phai.
    if(dR1 > dR2){
        dR = dR1;
    }else{
        dR = dR2;
    }

    //max cua ca hai duong cheo.
    if(dL > dR){
        maxD = dL;
    }else{
        maxD = dR;
    }

    if(maxD >= abs(taxiScore[meetRow][meetCol])){
        HP1 = liHP(HP1 + ceil(10.00*HP1/100));
        EXP1 = liEXP(EXP1 + ceil(12.00*EXP1/100));
        HP2 = liHP(HP2 + ceil(10.00*HP2/100));
        EXP2 = liEXP(EXP2 + ceil(12.00*EXP2/100));
        return maxD;
    }else if(maxD < abs(taxiScore[meetRow][meetCol])){
        HP1 = liHP(HP1 - floor(10.00*HP1/100));
        EXP1 = liEXP(EXP1 - floor(12.00*EXP1/100));
        HP2 = liHP(HP2 - floor(10.00*HP2/100));
        EXP2 = liEXP(EXP2 - floor(12.00*EXP2/100));
        return taxiScore[meetRow][meetCol];
    }

    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string s1 = s, e1 = email;
    string se = e1.substr(0, e1.find('@'));
    size_t i;
    
    //check do dai mat khau.
    if(s1.length() < 8){
        return -1;
    }else if(s1.length() > 20){
        return -2;
    }

    //check xem pass co chua se hay khong.
    size_t seFound = s1.find(se);
    if(seFound != string::npos){
        return -(300 + seFound);
    }

    //check xem pass co 2 ki tu lien tiep nhau hay khong.
    for(i = 0; i < s1.length() - 2; i++){
        if(s1[i] == s1[i + 1] && s1[i] == s1[i + 2]){
            return -(400 + i);
        }
    }
    
    //check xem s co ki tu dac biet hay khong.
    bool specialChar = false;
    for(char c : s1){
        if(c == '@' || c == '#' || c == '%' || c == '$' || c == '!'){
            specialChar = true;
            break;
        }
    }
    if(!specialChar) return -5;

    //cac truong hop con lai.
    for(i = 0; i < s1.length(); i++){
        char c = s1[i];
        if(!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || 
        (c == '@' || c == '#' || c == '%' || c == '$' || c == '!'))){
            return i;
        }
    }

    //neu mat khau hop le.
    return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    struct passTest{
    string pass;
    int fre; //short of frequency.
    };

    passTest truePass, passNow;
    truePass.fre = 0;

    //check the frequency of each pass + max frequency + max length.
    for(int i = 0; i < num_pwds; ++i){
        passNow.pass = arr_pwds[i];
        passNow.fre = 1;

        //check how many pass after current pass is the same as it.
        for(int j = i + 1; j < num_pwds; ++j){
            if(arr_pwds[j] == passNow.pass){
                ++passNow.fre;
            }
        }

        //update maximum frequency
        if((passNow.fre > truePass.fre) || (passNow.fre == truePass.fre && passNow.pass.length() > truePass.pass.length())){
            truePass.pass = passNow.pass;
            truePass.fre = passNow.fre;
        }
    }

    for(int i = 0; i < num_pwds; i++){
        if(arr_pwds[i] == truePass.pass){
            return i;
        }
    }

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////