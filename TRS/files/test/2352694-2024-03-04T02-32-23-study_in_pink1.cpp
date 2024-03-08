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

#define maxHP 666
#define minHP 0
#define maxEXP 600
#define minEXP 0
#define maxM 3000
#define minM 0

//Check valid mission
bool checkE(int E) {
    return (E >= 0 && E <= 99);
}

//Check if INT
int checkINT(float num) {
    if(num - static_cast<int>(num) > 0) return static_cast<int>(num) + 1; else return static_cast<int>(num);
}

//Case 1
void CASE1_1(int & exp1, int & exp2, int e1) {

    if(e1 == 0) exp2 = (exp2 + 29 > maxEXP) ? maxEXP : exp2 + 29; 
        else if(e1 == 1) exp2 = (exp2 + 45 > maxEXP) ? maxEXP : exp2 + 45;
            else if(e1 == 2) exp2 = (exp2 + 75 > maxEXP) ? maxEXP : exp2 + 75;
                else exp2 = (exp2 + 29 + 45 + 75 > maxEXP) ? maxEXP : exp2 + 29 + 45 + 75;

    int D = e1 * 3 + exp1 * 7;

    if(D % 2) exp1 = (exp1 - checkINT(D*1.0/100) < minEXP) ? minEXP : checkINT(exp1*1.0 - D*1.0/100);
        else exp1 = (exp1 + checkINT(D*1.0/200) > maxEXP) ? maxEXP : exp1 + checkINT(D*1.0/200);
}

//Case 2
void CASE1_2(int & exp1, int & exp2, int e1) {

    int eq1 = checkINT(e1*1.0/4 + 19);
    int eq2 = checkINT(e1*1.0/9 + 21);
    int eq3 = checkINT(e1*1.0/16 + 17);
    
    if(e1 >= 4 && e1 <= 19) exp2 = (exp2 + eq1 > maxEXP) ? maxEXP : exp2 + eq1 ; else
    if(e1 >= 20 && e1 <= 49) exp2 = (exp2 + eq2 > maxEXP) ? maxEXP : exp2 + eq2 ; else
    if(e1 >= 50 && e1 <= 65) exp2 = (exp2 + eq3 > maxEXP) ? maxEXP : exp2 + eq3; else
    if(e1 >= 66 && e1 <= 79) {
        exp2 = (exp2 + eq1 > maxEXP) ? maxEXP : exp2 + eq1;
        if(exp2 > 200) exp2 = (exp2 + eq2 > maxEXP) ? maxEXP : exp2 + eq2;
    } else
    if(e1 >= 80 && e1 <= 99) {
        exp2 = (exp2 + eq1 > maxEXP) ? maxEXP : exp2 + eq1;
        exp2 = (exp2 + eq2 > maxEXP) ? maxEXP : exp2 + eq2;
        if(exp2 > 400) {
            exp2 = (exp2 + eq3 > maxEXP) ? maxEXP : exp2 + eq3;
            exp2 = (exp2 * 1.15 > maxEXP) ? maxEXP : checkINT(exp2 * 1.15);
        }
    }

    exp1 = (exp1 -e1 < minEXP) ? minEXP : exp1 - e1;
}
  
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

    if(!checkE(e1)) return -99;

    if(exp1 < minEXP) exp1 = minEXP;
    if(exp1 > maxEXP) exp1 = maxEXP;
    if(exp2 < minEXP) exp2 = minEXP;
    if(exp2 > maxEXP) exp2 = maxEXP;

    if(e1 <= 3) CASE1_1(exp1, exp2, e1);
        else CASE1_2(exp1, exp2, e1);
    return exp1 + exp2;
}


/*TASK 2*/

// Determine the closest square number
int closestSquare(int num) {
    int l = sqrt(num);
    int u = l + 1;

    //get lower and upper square
    int lS = l * l;
    int uS = u * u;

    if (abs(num - lS) < abs(num - uS)) {
        return lS;
    } else {
        return uS;
    }
}

float getProbability(int exp) {
    if (exp >= closestSquare(exp)) {
        return 1;
    } else {
        return ((exp * 1.0 / closestSquare(exp) * 1.0) + 80) / 123;
    }
}

void Road01(int & HP1, int & EXP1, int & M1, int E2, float & P1){
    P1 = getProbability(EXP1);
    //cout << closestSquare(EXP1) << endl;
}

void Road02(int & HP1, int & EXP1, int & M1, int E2, float & P2){

    int INIT = M1;

    StartOver:
        //Event 01

        if(M1 == 0 || (E2%2) && (INIT*0.5 < INIT-M1*1.0)) goto OddFinalChange;

        if(HP1 < 200) {
            HP1 = (checkINT(HP1 * 1.3) > maxHP) ? maxHP : checkINT(HP1 * 1.3);
            M1 = (M1 - 150 < minM) ? minM : M1 - 150;
        } else {
            HP1 = (checkINT(HP1 * 1.1) > maxHP) ? maxHP : checkINT(HP1 * 1.1);
            M1 = (M1 - 70 < minM) ? minM : M1 - 70;
        }

        if(M1 == 0 || (E2%2) && (INIT*0.5 < INIT-M1*1.0)) goto OddFinalChange;

        //Event 02 
        if(EXP1 < 400) M1 = (M1 - 200 < minM) ? minM : M1 - 200; else
            M1 = (M1 - 120 < minM) ? minM : M1 - 120;
        EXP1 = (checkINT(EXP1 * 1.13) > maxEXP) ? maxEXP : checkINT(EXP1 * 1.13);

        if(M1 == 0 || (E2%2) && (INIT*0.5 < INIT-M1*1.0)) goto OddFinalChange;

        //Event 03
        if(EXP1 < 300) M1 = (M1 - 100 < minM) ? minM : M1 - 100; else
            M1 = (M1 - 120 < minM) ? minM : M1 - 120;
        EXP1 = (checkINT(EXP1 * 0.9) < minEXP) ? minEXP : checkINT(EXP1 * 0.9);

        if(M1 == 0 || (E2%2) && (INIT*0.5 < INIT-M1*1.0)) goto OddFinalChange;

        if(E2 % 2 && (INIT*0.5 >= INIT-M1*1.0) && M1 > 0) goto StartOver; else goto OddFinalChange;

    OddFinalChange:
        HP1 = (checkINT(HP1 * 0.83) < minHP) ? minHP : checkINT(HP1 * 0.83);
        EXP1 = (checkINT(EXP1 * 1.17) > maxEXP) ? maxEXP : checkINT(EXP1 * 1.17);
        goto FinalAction;
    
    FinalAction:
        P2 = getProbability(EXP1);
}

void Road03(int & HP1, int & EXP1, int & M1, int E2, float & P3) {
    int INDEX[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    string s = to_string(E2);
    int tmp = 0;
    for(auto i : s) tmp += int(i) - 48;
    if(tmp > 9) tmp = (tmp % 10);
    P3 = INDEX[tmp]*1.0/100; 
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    if(checkE(E2) == false) return -99;

    if(HP1 < minHP) HP1 = minHP;
    if(HP1 > maxHP) HP1 = maxHP;
    if(EXP1 < minEXP) EXP1 = minEXP;
    if(EXP1 > maxEXP) EXP1 = maxEXP;
    if(M1 < minM) M1 = minM;
    if(M1 > maxM) M1 = maxM;

    float P1, P2, P3, P;

    Road01(HP1, EXP1, M1, E2, P1);
    Road02(HP1, EXP1, M1, E2, P2);
    Road03(HP1, EXP1, M1, E2, P3);

    if(P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = (checkINT(EXP1 * 0.75) < minEXP) ? minEXP : checkINT(EXP1 * 0.75);
    } else {
        P = (P1 + P2 + P3) / 3*1.0;
        if(P < 0.5){
            HP1 = (checkINT(HP1 * 0.85) < minHP) ? minHP : checkINT(HP1 * 0.85);
            EXP1 = (checkINT(EXP1 * 1.15) > maxEXP) ? maxEXP : checkINT(EXP1 * 1.15);
        } else {
            HP1 = (checkINT(HP1 * 0.9) < minHP) ? minHP : checkINT(HP1 * 0.9);
            EXP1 = (checkINT(EXP1 * 1.2) > maxEXP) ? maxEXP : checkINT(EXP1 * 1.2);
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3

//calculate max value of left diagonal
int maxDiagonal(int a[11][11], int i, int j) {
    int maxValue = a[i][j];

    int row = i;
    int col = j;

    while (row >= 0 && col >= 10) {
        maxValue = max(maxValue, a[row][col]);
        row--;
        col--;
    }

    row = i;
    col = j;

    while(row < 10 && col < 10) {
        maxValue = max(maxValue, a[row][col]);
        row++;
        col++;
    }
    
    row = i;
    col = j;
    
    while(row >= 0 && col < 10){
        maxValue = max(maxValue, a[row][col]);
        row--;
        col++;
    }
    
    row = i;
    col = j;
    
    while(row <10 && col >= 0){
        maxValue = max(maxValue, a[row][col]);
        row++;
        col--;
    }

    return maxValue;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

    if(checkE(E3) == false) return -99;

    if(HP1 < minHP) HP1 = minHP;
    if(HP1 > maxHP) HP1 = maxHP;
    if(HP2 < minHP) HP2 = minHP;
    if(HP2 > maxHP) HP2 = maxHP;
    if(EXP1 < minEXP) EXP1 = minEXP;
    if(EXP1 > maxEXP) EXP1 = maxEXP;
    if(EXP2 < minEXP) EXP2 = minEXP;
    if(EXP2 > maxEXP) EXP2 = maxEXP;

    int a[11][11];
    int b[11][11];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int col = 0, row = 0;

    //init the matrix
    for(int i = 0; i < 10;++i)
        for(int j = 0; j < 10; ++j){
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if(a[i][j] < -E3) col++;
            if(a[i][j] > E3*2) row++;
        } 
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            b[i][j] = max(b[i][j], maxDiagonal(a, i, j));
        }
    }

    while(row >= 10) row = (row / 10) + (row % 10);
    while(col >= 10) col = (col / 10) + (col % 10);

    if(abs(a[row][col]) <= b[row][col]){
        EXP1 = (EXP1 * 1.12 > maxEXP) ? maxEXP : checkINT(EXP1 * 1.12);
        EXP2 = (EXP2 * 1.12 > maxEXP) ? maxEXP : checkINT(EXP2 * 1.12);
        HP1 = (HP1 * 1.1 > maxHP) ? maxHP : checkINT(HP1 * 1.1);
        HP2 = (HP2 * 1.1 > maxHP) ? maxHP : checkINT(HP2 * 1.1);
    } else {
        EXP1 = (EXP1 * 0.88 < minEXP) ? minEXP : checkINT(EXP1 * 0.88);
        EXP2 = (EXP2 * 0.88 < minEXP) ? minEXP : checkINT(EXP2 * 0.88);
        HP1 = (HP1 * 0.9 < minHP) ? minHP : checkINT(HP1 * 0.9);
        HP2 = (HP2 * 0.9 < minHP) ? minHP : checkINT(HP2 * 0.9);
    }

    if(abs(a[row][col])>abs(b[row][col])) return a[row][col]; else return b[row][col];

    return -1;
}

string getSubString(string const & s){
    string::size_type pos = s.find('@');
    if(pos != string::npos) return s.substr(0, pos);
    else return "";
}

bool findEmail(string se, string s, int &sei){
    int l = se.length();
    int ls = s.length();

    for(int i = 0; i <= ls - l; ++i){
        if(s.substr(i, l) == se) {
            sei = i;
            return true;
        }
    } 
    return false;
}

bool checkDuplicate(string s, int & sci){
    int l = s.length();
    for(int i = 0; i < l - 2; ++i){
        if(s[i] == s[i+1] && s[i] == s[i + 2]){
            sci = i;
            return true;
        }
    } 
    return false;
}

bool checkSpecialChar(string s){
    for(auto i : s){
        if(i == '!' || i == '@' || i == '#' || i == '$' || i == '%') return true;
    }
    return false;
}

bool checkValid(string s, int & invalidChar){
    for(int i = 0; i < s.length(); ++i){
        char h = s[i];
        if((h >='0' && h <= '9') || (h >= 'a' && h <= 'z') || (h >= 'A' && h <= 'Z') || h == '!' || h == '@' || h == '#' || h == '$' || h == '%') continue;
            else {
                invalidChar = i;
                return false;
            }
    }
    return true;
}
    

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    string sub = getSubString(email);
    int len = strlen(s);
    int sei = 0;
    int sci = 0;
    int invalidChar;

    if(len < 8) return -1;
    if(len > 20)return -2;
    if(findEmail(sub, s, sei)) return -(300 + sei);
    if(checkDuplicate(s, sci)) return -(400 + sci);
    if(!checkSpecialChar(s)) return -5;
    if(!checkValid(s, invalidChar)) return invalidChar;

    return -10;

    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    int maxcnt = 0;
    int correctPos = 0;

    for(int i = 0; i < num_pwds; ++i){
        
        int cnt = 0;

        for(int j = i; j < num_pwds; ++j){
            if(strcmp(arr_pwds[i], arr_pwds[j]) == 0){
                ++cnt;
            }
        }

        if(maxcnt < cnt || ((maxcnt == cnt) && strlen(arr_pwds[i]) > strlen(arr_pwds[correctPos]))){
            maxcnt = cnt;
            correctPos = i;
        }

    }

    return correctPos;

    return -1;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////