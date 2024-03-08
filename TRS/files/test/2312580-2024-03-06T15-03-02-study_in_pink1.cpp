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


void event_1(int & HP1, int & M1, int & spentM1);
void event_2(int & HP1, int & M1, int & spentM1);
void event_3(int & HP1, int & M1, int & spentM1);
bool isOverSpent(int & spentM1, int startM1, int & M1, int E2);
void checkEXP(int & EXP);
void checkHP(int & HP);
void checkM(int & M);
bool checkE(int E);
void roundUp(int & input, double result);
int getSherlockScore(int i, int j, int (&map)[10][10]);


//check input data

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    //check input data 
    if(checkE(e1)) return -99; 
    checkEXP(exp1);
    checkEXP(exp2);

    if(e1 >= 0 && e1 <= 3) {
        int D;
        
        if (e1 == 0) {
            exp2 += 29;
        } else if (e1 == 1) {
            exp2 += 45;
        } else if (e1 == 2) {
            exp2 += 75;
        } else if (e1 == 3) {
            exp2 += (75 + 45 + 29);
        }

        D = e1*3 + exp1*7;
        if(D % 2 == 0) exp1 += ceil(D/200.0);
        else exp1 -= floor(D/100.0);
        
    } else if(e1 >= 4 && e1 <= 99) {
        if(e1 <= 19) {
            exp2 += ceil(e1/4.0 + 19);
        } else if(e1 <= 49) {
            exp2 += ceil(e1/9.0 + 21);
        } else if(e1 <= 65) {
            exp2 += ceil(e1/16.0 + 17);
        } else if(e1 <= 79) {
            exp2 += ceil(e1/4.0 + 19);
            if(exp2 > 200) exp2 += ceil(e1/9.0 + 21);
        } else {
            exp2 += ceil(e1/4.0 + 19);
            exp2 += ceil(e1/9.0 + 21);
            if(exp2 > 400){
                exp2 += ceil(e1/16.0 + 17);
                exp2 = ceil(exp2 * 1.15); 
            }
        }
        exp1 -= e1;
    } 

    checkEXP(exp1);
    checkEXP(exp2);

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    //check input data
    if(checkE(E2)) return -99;
    checkHP(HP1);
    checkEXP(EXP1);
    checkM(M1);


    double p1, p2, avrgP;
    int p3;
    int startM1 = M1, spentM1 = 0;
    bool isMistaken = true;

    //declare local function
    // void event_1(int & HP1, int & M1);
    // void event_2(int & HP1, int & M1);
    // void event_3(int & HP1, int & M1);
    // bool isOverSpent(int & spentM1, int startM1, int M1, int E2);

    while(isMistaken) {
        //Road 1
        int s = pow(round(sqrt(EXP1)),2);
        if(EXP1 >= s) p1 = 1;
        else p1 = (static_cast<double>(EXP1)/s + 80)/123;

        //Road 2

        if(E2%2 != 0) {
            while(true) {
                
                event_1(HP1, M1, spentM1);
                if(isOverSpent(spentM1, startM1, M1, E2)) break;

                event_2(EXP1, M1, spentM1);
                if(isOverSpent(spentM1, startM1, M1, E2)) break;

                event_3(EXP1, M1, spentM1);
                if(isOverSpent(spentM1, startM1, M1, E2)) break;
            }

        } else {
            event_1(HP1, M1, spentM1);
            if(!isOverSpent(spentM1, startM1, M1, E2)) {
                event_2(EXP1, M1, spentM1);
                if(!isOverSpent(spentM1, startM1, M1, E2)) {
                    event_3(EXP1, M1, spentM1);
                }
            }
        }
        roundUp(HP1, HP1*0.83);//HP1 = ceil(HP1*0.83);
        roundUp(EXP1, EXP1*1.17); //EXP1 = ceil(EXP1*1.17);
        checkHP(HP1);
        checkEXP(EXP1);
        s = pow(round(sqrt(EXP1)),2);
        p2 = (static_cast<double>(EXP1)/s + 80)/123;
        if(EXP1 >= s) p2 = 1;
        else p2 = (static_cast<double>(EXP1)/s + 80)/123;

        //Road 3
        int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int i;

        if(E2 < 10) i = E2;
        else {
            i = (E2/10) + (E2 - (E2/10)*10);
            i = i - (i/10)*10;
        }
        p3 = P[i];

        //End Road
        if(p1 == 1 && p2 == 1 && p3 == 100) {
            roundUp(EXP1, EXP1*0.75); //EXP1 = ceil(EXP1*0.75);
            checkEXP(EXP1);
            continue;
        }
        else isMistaken = false;

        avrgP = (p1+p2+p3/100.0) / 3;
        if(avrgP < 0.50) {
            roundUp(HP1,HP1*0.85); //HP1 = ceil(HP1*0.85);
            roundUp(EXP1,EXP1*1.15); //EXP1 = ceil(EXP1*1.15);
        } else {
            roundUp(HP1, HP1*0.9); //HP1 = ceil(HP1*0.9);
            roundUp(EXP1, EXP1*1.2); //EXP1 = ceil(EXP1*1.2);
        }
        checkHP(HP1);
        checkEXP(EXP1);

    }
    
    //delcare local functions

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    //check input data
    // if(HP1 > 666) HP1 = 666;
    // if(HP1 < 0) HP1 = 0;
    // if(HP2 > 666) HP2 = 666;
    // if(HP2 < 0) HP2 = 0;
    // if(EXP1 < 0) EXP1 = 0;
    // if(EXP2 < 0) EXP2 = 0;
    // if(EXP1 > 600) EXP1 = 600;
    // if(EXP2 > 600) EXP2 = 600;
    // if(E3 < 0 || E3 > 99) return -99;
    if(checkE(E3)) return -99;
    checkHP(HP1);
    checkHP(HP2);
    checkEXP(EXP1);
    checkEXP(EXP2);


    int map[10][10] = {};
    int iCor = 0, jCor = 0;
    int sherlockMap[10][10] = {};
    int sherlockScore = 0;
    int taxiScore;


    //Taxi score
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            map[i][j] = ((E3*j)+(i*2))*(i-j);
        }
    }


    //Meeting point
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(map[i][j] > (E3*2)) iCor++;
            if(map[i][j] < -E3) jCor++;
        }
    }
        //when i or j > 10
    while(iCor >= 10){ 
        iCor = iCor/10 + (iCor - (iCor/10)*10);
    }
    while(jCor >= 10){
        jCor = jCor/10 + (jCor - (jCor/10)*10);
    }

    taxiScore = map[iCor][jCor];


    //Get Sherlock's Score at meeting point
    //RightDiag
    // int iTemp = iCor, jTemp = jCor;
    // while(iTemp <= 9 && jTemp >=  0) {
    //     if(map[iTemp][jTemp] > sherlockScore) sherlockScore = map[iTemp][jTemp];
    //     iTemp++; //go left and downward from (iTemp,jTemp)
    //     jTemp--;
    // }
    // iTemp = iCor; jTemp = jCor;
    // while(iTemp >= 0 && jTemp <= 9) {
    //     if(map[iTemp][jTemp] > sherlockScore) sherlockScore = map[iTemp][jTemp];
    //     iTemp--; //go right and upward from (iTemp,jTemp)
    //     jTemp++;
    // }

    // //LeftDiag
    // iTemp = iCor; jTemp = jCor;
    // while(iTemp >= 0 && jTemp >= 0) {
    //     if(map[iTemp][jTemp] > sherlockScore) sherlockScore = map[iTemp][jTemp];
    //     iTemp--; //go left and upward from (iTemp,jTemp)
    //     jTemp--;
    // }
    // iTemp = iCor; jTemp = jCor;
    // while(iTemp <= 9 && jTemp <= 9) {
    //     if(map[iTemp][jTemp] > sherlockScore) sherlockScore = map[iTemp][jTemp];
    //     iTemp++; //go right and downward from (i,jTemp)
    //     jTemp++;
    // } 

    for(int j = 0; j < 10; j++){
        for(int i = 0; i < 10; i++){
            sherlockMap[i][j] = getSherlockScore(i, j, map);
        }
    }

    sherlockScore = sherlockMap[iCor][jCor];

    
    //When Sherlock and Taxi meets
    if(abs(taxiScore) <= sherlockScore) {
        roundUp(EXP1, EXP1*1.12); // EXP1 = ceil(EXP1*1.12);
        roundUp(HP1, HP1*1.1); // HP1 = ceil(HP1*1.1);
        roundUp(EXP2, EXP2*1.12); // EXP2 = ceil(EXP2*1.12);
        roundUp(HP2, HP2*1.1); // HP2 = ceil(HP2*1.1);
        checkEXP(EXP1);
        checkEXP(EXP2);
        checkHP(HP1);
        checkHP(HP2);
        return sherlockScore;
    } else {
        roundUp(EXP1, EXP1*0.88);
        roundUp(HP1, HP1*0.9);
        roundUp(EXP2, EXP2*0.88);
        roundUp(HP2, HP2*0.9);
        // EXP1 = ceil(EXP1*0.88);
        // HP1 = ceil(HP1*0.9);
        // EXP2 = ceil(EXP2*0.88);
        // HP2 = ceil(HP2*0.9);
        checkEXP(EXP1);
        checkEXP(EXP2);
        checkHP(HP1);
        checkHP(HP2);
        return taxiScore;
    }   
          

    // if(sherlockScore > abs(taxiScore)) return sherlockScore;
    // else return taxiScore;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se;

    for (int i = 0; i < 100; i++){
        if(email[i] != '@'){
            se += email[i];
        } else break;
    }

    //password length
    if(strlen(s) < 8) return -1;
    else if(strlen(s) > 20) return -2;

    //se in password
    int index = 0;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == se[index]) index++;
        else index = 0;
        
        if(index == se.length()) return -(300 + (i - (se.length() - 1)));
    }

    //consecutive letter
    for(int i = 1; i < strlen(s) - 1; i++){
        if(s[i] == s[i-1]){
            if(s[i] == s[i+1]) return -(400 + (i - 1));
        }
    }

    //special character
    bool containSpecialChar = false;
    for(int i = 0; i < strlen(s); i++){
        if((s[i] >= 33 && s[i] <= 38 && s[i]!= 34) || s[i] == 64){
            containSpecialChar = true;
            break;
        }
    }
    if(containSpecialChar == false) return -5;

    //not uppercase or lowercase or numbers
    for(int i = 0; i < strlen(s); i++){
        if(!((s[i] >= 65 && s[i] <= 90) ||
        (s[i] >= 97 && s[i] <= 122) ||
        (s[i] >= 48 && s[i] <= 57) ||
        (s[i] >= 33 && s[i] <= 38 && s[i]!= 34) || s[i] == 64)) 
        return i;
    }



    return -10;
}

// Task 5
// struct password{
//     const char * content;
//     int length = strlen(content);
//     int occurrence = 0;
// };




int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    //password pwds_list[] = {};
    const char * passwords[30] = {};
    int numOfPwds = 0;
    int maxLength = 0;
    int maxOccurrence = 0;
    int firstPos = 10000;
    int occurrence[30] = {};
    int pos[30] = {};
    int length[30] = {};
    bool hasOccurred = false;

    for(int i = 0; i < num_pwds; i++){
        for(int j = 0; j < 30; j++){
            if(arr_pwds[i] == passwords[j]){
                occurrence[j] += 1;
                hasOccurred = true;
            }
        }
        if(!hasOccurred){
            passwords[numOfPwds] = arr_pwds[i];
            occurrence[numOfPwds] = 1;
            length[numOfPwds] = strlen(arr_pwds[i]);
            pos[numOfPwds] = i;
            numOfPwds++;
        }
    }


    for(int i = 0; i < numOfPwds; i++){
        if(occurrence[i] > maxOccurrence) maxOccurrence = occurrence[i];
    }


    for(int i = 0; i < numOfPwds; i++){
        if(occurrence[i] == maxOccurrence){
            if(length[i] > maxLength) maxLength = length[i];
        }
    }
    
    for(int i = 0; i < numOfPwds; i++){
        if(occurrence[i] == maxOccurrence && length[i] == maxLength){
            if(pos[i] < firstPos) firstPos = pos[i];
        }
    }


    return firstPos;
}



void event_1(int & HP1, int & M1, int & spentM1){
    if(M1 == 0) return ;
    if(HP1 < 200) {
        roundUp(HP1, HP1*1.3); //HP1 = ceil(HP1*1.3);
        M1 -= 150;
        spentM1 += 150;
    } else {
        roundUp(HP1,HP1*1.1); //HP1 = ceil(HP1*1.1);
        M1 -= 70;
        spentM1 += 70;
    }
    checkHP(HP1);
    checkM(M1);
}

void event_2(int & EXP1, int & M1, int & spentM1){
    if(M1 == 0) return;
    if(EXP1 < 400){
        M1 -= 200;
        spentM1 += 200;
    }
    else {
        M1 -= 120;
        spentM1 += 120;
    }
    roundUp(EXP1, EXP1*1.13); //EXP1 = ceil(EXP1*1.13);
    checkEXP(EXP1);
    checkM(M1);
}

void event_3(int & EXP1, int & M1, int & spentM1){
    if(M1 == 0) return;
    if(EXP1 < 300) {
        M1 -= 100;
        spentM1 += 100;
    }
    else {
        M1 -= 120;
        spentM1 += 120;
    }
    roundUp(EXP1, EXP1 * 0.9);//EXP1 = ceil(EXP1*0.9);
    checkEXP(EXP1);
    checkM(M1);
}

bool isOverSpent(int & spentM1, int startM1, int & M1, int E2){
    if(E2%2 != 0) {
        if(spentM1 > 0.5*startM1 || M1 == 0){
            // M1 += spentM1; //return spentm1 to m1
            return true;
        }
        else return false;
    } else {
        if (M1 <= 0) {
            M1 = 0;
            return true;
        } else return  false;
    }
}

int getSherlockScore(int i, int j, int (&map)[10][10]){
    long int max = -100000;
    int tempi = i, tempj = j;
    //RightDiag
    while(tempi <= 9 && tempj >=  0) {
        if(map[tempi][tempj] > max) max = map[tempi][tempj];
        tempi++; //go left and downward from (i,tempj)
        tempj--;
    }
    tempi = i; tempj = j;
    while(tempi >= 0 && tempj <= 9) {
        if(map[tempi][tempj] > max) max = map[tempi][tempj];
        tempi--; //go right and upward from (i,tempj)
        tempj++;
    }

    //LeftDiag
    tempi = i; tempj = j;
    while(tempi >= 0 && tempj >= 0) {
        if(map[tempi][tempj] > max) max = map[tempi][tempj];
        tempi--; //go left and upward from (i,tempj)
        tempj--;
    }
    tempi = i; tempj = j;
    while(tempi <= 9 && tempj <= 9) {
        if(map[tempi][tempj] > max) max = map[tempi][tempj];
        tempi++; //go right and downward from (i,tempj)
        tempj++;
    }

    return abs(max);
}

void checkEXP(int & EXP){
    if(EXP > 600) EXP = 600;
    if(EXP < 0) EXP = 0;
}

void checkHP(int & HP){
    if(HP > 666) HP = 666;
    if(HP < 0) HP = 0;
}

void checkM(int & M){
    if(M > 3000) M = 3000;
    if(M < 0) M = 0;
}

bool checkE(int E){
    //return true if out of range, false if in range
    if(E > 99 || E < 0) return true;
    else return false;
}

void roundUp(int & input, double result){
    if(result - static_cast<int>(result) < 1e-7 && result - static_cast<int>(result) >= 0)
    input = static_cast<int>(result);
    else input = result + 1;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////