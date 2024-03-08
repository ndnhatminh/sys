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

void fixInRange_exp(int & exp) {
    if (exp > 600)
        exp = 600;
    else if (exp < 0)
        exp = 0;
}
void fixInRange_hp(int & hp) {
    if (hp > 666)
        hp = 666;
    else if (hp < 0)
        hp = 0;
}
void fixInRange_m(int & m) {
    if (m > 3000)
        m = 3000;
    else if (m < 0)
        m = 0;
}
    



// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0  || e1 > 99)
        return -99;
    fixInRange_exp(exp1);
    fixInRange_exp(exp2);
    if (e1 >= 0 && e1 <= 3){
        switch (e1)
        {
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
            exp2 += 29 + 45 + 75;
        default:
            break;
        }
        int D;
        D = e1*3 + exp1*7;
        exp1 = D%2 == 0? ceil(exp1 + D/200.0): ceil(exp1 - D/100.0);
        fixInRange_exp(exp1);
    }
    else {
        switch (e1){
            case 4 ... 19:
                exp2 += ceil(e1/4.0 + 19);
                break;
            case 20 ... 49:
                exp2 += ceil(e1/9.0 + 21);
                break;
            case 50 ... 65:
                exp2 += ceil(e1/16.0 + 17);
                break;
            case 66 ... 79:
                exp2 += ceil(e1/4.0 + 19);
                if (exp2 > 200){
                    exp2 += ceil(e1/9.0 + 21);
                }
                break;
            case 80 ... 99:
                exp2 += ceil(e1/4.0 + 19) + ceil(e1/9.0 + 21);
                if (exp2 > 400){
                    exp2 += ceil(e1/16.0 + 17);
                    fixInRange_exp(exp2);
                    exp2 += ceil(exp2*15.0/100);
                    
                }
                break;
            default:
                break;
        }
        exp1 -= e1;
    }
    fixInRange_exp(exp1);
    fixInRange_exp(exp2);
    return exp1 + exp2;
}

int closestSquare(int n) {
    int sq = trunc(sqrt(n));
    int p1 = sq*sq;
    int p2 = (sq + 1)*(sq + 1);
    if ((n - p1) < (p2 - n)) {
        return p1;
    }
    else return p2;
    
}
double road1(int & exp1) {
    int S = closestSquare(exp1);
    if (exp1 >= S) {
        return 100;
    }
    else {
        return (exp1*1.0/S + 80)*100/123;
    }
}

void road2_action1(int & hp1, int & m1){
    if (hp1 < 200) {
        hp1 = ceil(hp1*1.3);
        m1 -= 150;
    }
    else {
        hp1 = ceil(float(hp1)*110/100);
        m1 -= 70;
    }
    fixInRange_hp(hp1);
    fixInRange_m(m1);
}
void road2_action2(int & exp1, int & m1){
    if (exp1 < 400) {
        m1 -= 200;
    }
    else {
        m1 -= 120;
    }
    fixInRange_m(m1);
    exp1 = ceil(exp1*1.13);
    fixInRange_exp(exp1);
}
void road2_action3(int & exp1, int & m1){
    if (exp1 < 300) {
        m1 -= 100;
    }
    else {
        m1 -= 120;
    }
    fixInRange_m(m1);
    exp1 = ceil(exp1*0.9);
}

bool isMoneyEnough(int mStart, int mLeft) {
    if (mLeft >= (float)mStart/2) {
        return true;
    }
    else return false;
}
bool isMoneyLeft(int m) {
    if (m > 0)
        return true;
    else return false;
}
double road2(int & hp1, int & exp1, int & m1, int e2) {
    int mStart = m1;
    if (m1  == 0)
        goto jmp;
    if (e2%2 == 0){            
        road2_action1(hp1, m1);
        if (!isMoneyLeft(m1)) {
            
            goto jmp;
        }
        road2_action2(exp1, m1);
        if (!isMoneyLeft(m1)) {
            
            goto jmp;
        }
        road2_action3(exp1, m1);
        if (!isMoneyLeft(m1)) {
            
            goto jmp;
        }
    }
    else {
        while (true) {
            road2_action1(hp1, m1);
            
            if (!isMoneyEnough(mStart, m1)) {
                break;
            }
            road2_action2(exp1, m1);
            if (!isMoneyEnough(mStart, m1)) {
                break;
            }
            road2_action3(exp1, m1);
            if (!isMoneyEnough(mStart, m1)) {
                break;
            }
        }
    }
    jmp:
    
    hp1 = ceil(hp1*0.83);
    exp1 = ceil(exp1*1.17);
    fixInRange_exp(exp1);
    return road1(exp1);
}
int road3(int e2) {
    int P[10] = {32,47,28,79,100,50,22,83,64,11};
        return P[(e2/10 + e2%10)%10];
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
        return -99;
    fixInRange_hp(HP1);
    fixInRange_exp(EXP1);
    fixInRange_m(M1);
    double P;
    double P1 = road1(EXP1);
    double P2 = road2(HP1, EXP1, M1, E2);
    double P3 = road3(E2);
    if (P1 == 100 && P2 == 100 && P3 == 100) {
        EXP1 = ceil(EXP1*0.75);
    }
    else {
        P = (P1 + P2 + P3)/3;
        if (P < 50) {
            
            HP1 = ceil(HP1*0.85);
            EXP1 = ceil(EXP1*1.15);
        }
        else {
            
            HP1 = ceil(HP1*0.9);
            EXP1 = ceil(EXP1*1.2);
        }
    }
    fixInRange_exp(EXP1);
    return HP1 + EXP1 + M1;
}

int getMax(int n1, int n2) {
    if (n1 > n2)
        return n1;
    else return n2;
}

void drawMap(int arr[10][10]) {
    for (int i=0; i < 10; i++) {
        for (int j=0; j < 10; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;
    fixInRange_hp(HP1);
    fixInRange_exp(EXP1);
    fixInRange_hp(HP2);
    fixInRange_exp(EXP2);
    int map[10][10];
    int meetr = 0, meetc = 0;
    int i, j;
    for (i=0; i < 10; i++) {
        for (j=0; j < 10; j++) {
            map[i][j] = ((E3*j) + (i*2))*(i-j);
        }
    }

    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++) {
            if (map[i][j] > E3*2){
                meetr++;
            }
            else if (map[i][j] < -E3) {
                meetc++;
            }
        }
    }

    while(meetr/10 != 0) {
        meetr = meetr/10 + meetr%10;
    }
    while(meetc/10 != 0) {
        meetc = meetc/10 + meetc%10;
    }

    int taxiPoint = map[meetr][meetc];
    int SherPoint = map[meetr][meetc];

    for(i = 1; (meetr + i < 10) && (meetc + i < 10); i++) {
        SherPoint = getMax(SherPoint, map[meetr + i][meetc + i]);
    }
    for(i = 1; (meetr - i >= 0) && (meetc - i >= 0); i++) {
        SherPoint = getMax(SherPoint, map[meetr - i][meetc - i]);
    }
    for(i = 1; (meetr + i < 10) && (meetc - i >= 0); i++) {
        SherPoint = getMax(SherPoint, map[meetr + i][meetc - i]);
    }
    for(i = 1; (meetr - i >= 0) && (meetc + i < 10); i++) {
        SherPoint = getMax(SherPoint, map[meetr - i][meetc + i]);
    }
    if (abs(taxiPoint) > SherPoint) {
        EXP1 = ceil(EXP1*0.88);
        EXP2 = ceil(EXP2*0.88);
        HP1 = ceil(HP1*0.9);
        HP2 = ceil(HP2*0.9);
        return taxiPoint;
    }
    else {
        EXP1 = ceil((float)EXP1*112/100);
        fixInRange_exp(EXP1);
        EXP2 = ceil((float)EXP2*112/100);
        fixInRange_exp(EXP2);
        HP1 = ceil((float)HP1*110/100);
        fixInRange_hp(HP1);
        HP2 = ceil((float)HP2*110/100);
        fixInRange_hp(HP2);
        
        return SherPoint;
    }
    
    //cout << "Taxi: " << taxiPoint << ", Sher: " << SherPoint << endl;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int i = 0, j = 0;
    char symbols[] = "@#%$!";
    
    int passLength = strlen(s);                                             // meets length required?
    if (passLength < 8)
        return -1;
    else if (passLength > 20)
        return -2;

    string se = string(email).substr(0,string(email).find("@"));            // has se?
    int sei = string(s).find(se);
    if (sei != -1) {
        
        return -(300 + sei);
    }

    int sci;                                                                // has more than 2 continuous same char?
    for (i = 0;i < passLength-2; i++) {
        if (s[i] == s[i+1] && s[i] == s[i+2]){
            sci = i;
            
            return -(400 + sci);
        }
    }
    
    bool has_syms = false;                                                  // has atleast 1 symbol?
    for (i = 0; i < passLength ; i++) {
        for (j = 0; j < strlen(symbols); j++) {
            if (s[i] == symbols[j]) {
                has_syms = true;
                break;
            }
        }
    }
    bool has_unknowChar = false;                                            // has unknow character?
    for (i = 0; i < passLength ; i++) {                                     
        if (!isalpha(s[i]) && !isdigit(s[i])) {
            for (j = 0; j < strlen(symbols); j++) {
            if (s[i] == symbols[j])
                break;
            
            else if (j == strlen(symbols) - 1)
                return i;
            }
        }
    }
    if ( has_syms == false) {
        return -5;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int i = 0, j = 0;
    int pwds_count = 1,  pwds_idx = 0, pwds_maxCount = 1; int pwds_current = strlen(arr_pwds[0]);
    for (i = 0;i < num_pwds; i++) {
        pwds_count = 1;
        for (j = i + 1; j < num_pwds; j++) {
            
            if (arr_pwds[i] == arr_pwds[j]) {
                pwds_count++;
            }
        }
        if (pwds_count > pwds_maxCount) {
            pwds_maxCount = pwds_count;
            pwds_current = strlen(arr_pwds[i]);
            pwds_idx = i;
        }
        else if (pwds_count == pwds_maxCount) {
            if (strlen(arr_pwds[i]) > pwds_current) {
                pwds_current = strlen(arr_pwds[i]);
                pwds_idx = i;
            }
        }
    }
    return pwds_idx;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////