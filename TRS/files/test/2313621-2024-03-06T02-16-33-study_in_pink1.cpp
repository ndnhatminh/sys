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

// ADDTION CODE
int checkHP(int& HP){
    if(HP > 666) return 666;
    else if(HP < 0) return 0;
    else return HP;
}
int checkEXP(int& EXP){
    if(EXP > 600) return 600;
    else if(EXP < 0 ) return 0;
    else return EXP;
}
int checkMoney(int& M){
    if(M > 3000) return 3000;
    else if(M < 0) return 0;
    else return M;
}
int checkSquare(int exp){
    if(exp == ((int)sqrt(exp)*(int)sqrt(exp))) return exp; 
    else if(ceil(float(sqrt(exp)))*ceil(float(sqrt(exp))) - exp > exp - floor(float(sqrt(exp)))*floor(float(sqrt(exp)))) return floor(float(sqrt(exp)))*floor(float(sqrt(exp)));
    else return ceil(float(sqrt(exp)))*ceil((float(sqrt(exp))));
}
int Sumofdigits(int a){
    if(a < 10) return a;
    else return Sumofdigits(a/10 + a%10);
}



// ADDTION CODE
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    exp1 = checkEXP(exp1);
    exp2 = checkEXP(exp2);
    int D;
    if(e1 > 99 || e1 < 0) return -99;
    else if(e1 < 4){
        switch(e1){
            case 0: exp2 += 29; break;
            case 1: exp2 += 45; break;
            case 2: exp2 += 75; break;
            case 3: exp2 += 149; break;
        }
        exp2 = checkEXP(exp2);
        D = e1*3 + exp1*7;
        if(D % 2 == 0) exp1 += ceil(float( D/200.0));
        else exp1 -= floor(float(D/100.0));
        exp1 = checkEXP(exp1);
    }
    else{
        if(e1 <= 19 ) exp2 += ceil(float( e1/4.0)) + 19;
        else if(e1 <= 49) exp2 += ceil(float( e1/9.0)) + 21;
        else if(e1 <= 65) exp2 += ceil(float(e1/16.0)) + 17;
        else if(e1 <= 79) {
            exp2 += ceil(float(e1/4.0)) + 19;
            if(exp2 > 200) exp2 += ceil(float(e1/9.0)) + 21;
        }       
       else {
            exp2 += ceil(float( e1/4.0)) + 19 + ceil(float( e1/9.0)) + 21;
            if(exp2 > 400) {
                exp2 += ceil(float( e1/16.0)) + 17;
                exp2 += ceil(float( exp2*0.15));
            }
        }
        exp2 = checkEXP(exp2);
        exp1 -= e1;
        exp1 = checkEXP(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
   if(E3 < 0 || E3 > 99) return -99;
    else{
    float P1, P2, P3, Average;

    HP1 = checkHP(HP1);
    EXP1 = checkEXP(EXP1);
    M1 = checkMoney(M1);

    const int LIMODD = floor(float(M1/2.0));
    int Check = 0;

    // The first road_______________________________________________________________
    if(EXP1 >= checkSquare(EXP1)) P1 = 1;
    else P1 = ((float) EXP1/checkSquare(EXP1)+80)/123;

    //The second road_______________________________________________________________
    if(E3 % 2 == 0 && M1 > 0){
        //sub 1
    if(HP1 < 200) {
        HP1 += ceil(float(HP1*0.3));
        M1 -= 150;
        
                 }
    else {
        HP1 += ceil(float(HP1*0.1));
        M1 -= 70;
        
              }
    HP1 = checkHP(HP1);
    M1 = checkMoney(M1);
    if(M1 == 0) goto GETOVER;
        // sub 2
        if(EXP1 < 400) {
        M1 -= 200;
        
    }
    else {
        M1 -= 120;
        
    }
    EXP1 += ceil(float(EXP1*0.13));
    EXP1 = checkEXP(EXP1);
    HP1 = checkHP(HP1);
    M1 = checkMoney(M1);
    if(M1 == 0) goto GETOVER;
        // sub 3
    if(EXP1 < 300){
    M1 -= 100;

   }
   else {
    M1 -= 120;
    
   }
    EXP1 -= floor(float(EXP1*0.1));
    EXP1 = checkEXP(EXP1);
    HP1 = checkHP(HP1);
    M1 = checkMoney(M1);
    }
    else while(M1 > 0){///////////////////////////////////////////////////////
        //sub 1
    if(HP1 < 200) {
        HP1 += ceil(float(HP1*0.3));
        M1 -= 150;
        Check += 150;
              }
    else {
         HP1 += ceil(float(HP1*0.1));
         M1 -= 70;
         Check += 70;
              }
        HP1 = checkHP(HP1);
        M1 = checkMoney(M1);
    if(Check > LIMODD) break;
    // sub 2
    if(EXP1 < 400) {
        M1 -= 200;
        Check += 200;
    }
    else {
        M1 -= 120;
        Check += 120;
    }
    EXP1 += ceil(float(EXP1*0.13));
    EXP1 = checkEXP(EXP1);
    HP1 = checkHP(HP1);
    M1 = checkMoney(M1);
    if(Check > LIMODD) break;
    // sub 3
   if(EXP1 < 300){
    M1 -= 100;
    Check += 100;
   }
   else {
    M1 -= 120;
    Check += 120;
   }
    EXP1 -= floor(float(EXP1*0.1));
    EXP1 = checkEXP(EXP1);
    HP1 = checkHP(HP1);
    M1 = checkMoney(M1);
    if(Check > LIMODD) break;
    }
    GETOVER:
        HP1 -= floor(float(HP1*0.17));
        EXP1 += ceil(float(EXP1*0.17));
        HP1 = checkHP(HP1);
        EXP1 = checkEXP(EXP1);

        if(EXP1 >= checkSquare(EXP1)) P2 = 1;
        else P2 = ((float)EXP1/checkSquare(EXP1)+80)/123;
    
    // The third road_____________________________________________________________________
        float P[10]={0.32, 0.47, 0.28, 0.79, 1.0, 0.5, 0.22, 0.83, 0.64, 0.11};
       if(E3 < 10) P3 = P[E3];
       else P3 = P[(E3/10+E3%10)%10];
       Average = (P1 + P2 + P3)/3;
       if(Average == float(1)) EXP1 -= floor(float(EXP1*0.25));
       else if(Average < 0.5) {
        HP1 -= floor(float(HP1*0.15));
        EXP1 += ceil(float(EXP1*0.15));
       }
       else {
        HP1 -= floor(float(HP1*0.1));
        EXP1 += ceil(float(EXP1*0.2));
 
       }
       HP1 = checkHP(HP1);
       EXP1 = checkEXP(EXP1);
     return HP1 + EXP1 + M1;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    EXP1 = checkEXP(EXP1);
    EXP2 = checkEXP(EXP2);
    HP1 = checkHP(HP1);
    HP2 = checkHP(HP2);
    if(E3 < 0 || E3 > 99) return -99;
    else{
    int a[10][10], countI = 0, countJ = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) {
            a[i][j] = (E3*j+i*2)*(i-j);
            if(a[i][j] > E3*2 ) countI += 1;
            if(a[i][j] < -E3) countJ += 1;
        }
    }
    countI = Sumofdigits(countI);
    countJ = Sumofdigits(countJ);
    int x = countI-1, y = countJ-1, max =a[countI][countJ];
    //check \ 
    
    while(x >= 0 && y >= 0){
        if(a[x][y] >  max)  max = a[x][y] ;
        x -= 1; y -= 1;
    }
    x = countI+1; y = countJ-1;
    while(x <= 9 && y >= 0){
        if(a[x][y] > max) max = a[x][y];
        x +=1; y-= 1;
    }
    if(abs(a[countI][countJ]) > abs(max) ) {
        EXP1 -= floor(float(EXP1*0.12));
        EXP2 -= floor(float(EXP2*0.12));
        HP1 -= floor(float(HP1*0.1));
        HP2 -= floor(float(HP2*0.1));
        EXP1 = checkEXP(EXP1);
        EXP2 = checkEXP(EXP2);
        HP1 = checkHP(HP1);
        HP2 = checkHP(HP2);
        return a[countI][countJ];
    }
    else{
        EXP1 += ceil(float(EXP1*0.12));
        EXP2 += ceil(float(EXP2*0.12));
        HP1 += ceil(float(HP1*0.1));
        HP2 += ceil(float(HP2*0.1));
        EXP1 = checkEXP(EXP1);
        EXP2 = checkEXP(EXP2);
        HP1 = checkHP(HP1);
        HP2 = checkHP(HP2);
        return max;
    }
    
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string strS = s, strEmail = email, se;
    se = strEmail.erase(strEmail.find('@'));
    if(strS.length() < 8) return -1;
    else if(strS.length() > 20) return -2;
    else {
            int arr[3]={999, 999, 999};
        if(strS.find(se) != string::npos) arr[0] = strS.find(se);
        for(int i = 0 ; i < strS.length()-2; i++){
            if(strS[i]==strS[i+1] && strS[i]==strS[i+2]) {
                    arr[1] = i;
                    break;
            }
        }
        for(int i = 0 ; i < strS.length(); i++){
            if (!(isalnum(strS[i]) || strS[i] == '$' || strS[i] == '%' ||strS[i] == '#' || strS[i] == '@' || strS[i] == '!')){
                    arr[2] = i;
                    break;
                }
            }
        bool checkSC = (strS.find('$')==string::npos)&&(strS.find('%')==string::npos)&&(strS.find('#')==string::npos)&&(strS.find('@')==string::npos)&&(strS.find('!')==string::npos);
        if(arr[0] != 999) return -(300+arr[0]);
        if(arr[1] != 999) return -(400+arr[1]);
        if(checkSC) return -5;
        if(arr[2] != 999) return arr[2];
        return -10;
        }
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string arr[num_pwds];
    for(int i = 0 ; i < num_pwds; i++){
        arr[i]=arr_pwds[i];
    }
    int arrS[30], arrP[30];
    string str[30];
    int num = 0;
    for (int i = 0; i < num_pwds; ++i) {
        if (!arr[i].empty()) {
            int count = 1;
            for (int j = i + 1; j < num_pwds; ++j) {
                if (arr[i] == arr[j]) {
                    ++count;
                    arr[j] = "";
                }
            }
            arrS[num] = count;
            str[num]= arr[i];
            arrP[num] = i;
            num+=1;
        }
    }
    int maxArr = arrS[0];
    string maxstr = str[0];
    int maxArrP = 0;
    for(int i = 1;i < num;i++){
        if(arrS[i] > maxArr) {
                maxArr = arrS[i];
                maxstr = str[i];
                maxArrP = arrP[i];
        }
        else if(arrS[i] == maxArr) {
            if(str[i].length() > maxstr.length()) {
                maxArr = arrS[i];
                maxstr = str[i];
                maxArrP = arrP[i];
        }
            else if(str[i].length() == maxstr.length()){
                if(arrP[i] < maxArrP) {
                maxArr = arrS[i];
                maxstr = str[i];
                maxArrP = arrP[i];
        }
            }

    }
}
 return maxArrP;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////