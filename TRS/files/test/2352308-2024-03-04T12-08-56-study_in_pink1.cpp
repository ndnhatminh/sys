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
int findMax(int a,int b){
    if (a > b){
        return a;
    } 
    return b;
}
int abstract(int a){
    if (a < 0){
        return -a;
    }
    return a;
}
int maxLeftDiagonal(int x[10][10], int a, int b){
    int max = x[a][b];
    int row = a;
    int column = b;

    while ( row < 10 && column <10){
        max = findMax(max, x[row][column]);
        row++;
        column++;
    }
    row = a;
    column = b;
    while ( row >= 0 && column >= 0){
        max = findMax(max, x[row][column]);
        row--;
        column--;
    }
  return max;
}
int maxRightDiagonal(int x[10][10], int a, int b){
    int max = x[a][b];
    int row = a;
    int column = b;

    while ( row >= 0  && column < 10){
        max = findMax(max, x[row][column]);
        row--;
        column++;
    }
    row = a;
    column = b;
    while ( row < 10 && column >= 0){
        max = findMax(max, x[row][column]);
        row++;
        column--;
    }
  return max;
}

int nearestPerfectSquare(int value){
    int lowerRoot = sqrt(value);
    int upperRoot = lowerRoot + 1;
    int lowerSquare = lowerRoot*lowerRoot;
    int upperSquare = upperRoot*upperRoot;
    return (abs(value - lowerSquare) < abs(value - upperSquare)) ? lowerSquare : upperSquare;
}
int checkMoney (int z){
     if (z >= 3000){
        return 3000;
    } else if (z <= 0){
        return 0;
    }
    return z;
}
int checkNumberExp(int y){
    if (y >= 600){
        return 600;
    } else if (y <= 0){
        return 0;
    }
    return y;
}
int checkNumberHp (int x){
    if (x > 666){
        return 666;
    } else if (x < 0){
        return 0;
    }
    return x;
}
int roundUp(float x) {
    if (x - (int)x == 0){
          return x;
    }
    return ++x; 
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 > 99 || e1 < 0){
        return -99;
    }
     int lol= checkNumberExp(exp1);
            exp1 = lol;
     int lol1 = checkNumberExp(exp2);
            exp2 = lol1;
    if ( e1 >= 0 && e1 <=3 ){
        if (e1==0){
            exp2 += 29;
        } else if (e1 == 1){
            exp2 += 45;
        } else if (e1 == 2){
            exp2 +=75;
        
        } else {
            exp2 = exp2 + 29 + 45 + 75;
        }
     int num14 = checkNumberExp(exp2);
     exp2 = num14;;
    int D = e1*3 + exp1*7;
    if ( D%2==0){
        int eq1 = roundUp(exp1*1.0 + (D*1.0/200));
        exp1 = eq1;
        int temp = checkNumberExp(exp1);
        exp1 = temp;
    } else {
        float eq1 = roundUp(exp1*1.0 - (D*1.0/100));
        exp1 = eq1;
         int temp = checkNumberExp(exp1);
        exp1 = temp;
    }
    }
    if (e1 >3 && e1 <= 99){
        if (e1 > 3 && e1 <= 19){
            int eq1 = roundUp(e1*1.0/4 + 19);
            exp2 += eq1;
             int num14 = checkNumberExp(exp2);
            exp2 = num14;;
        } else if (e1 > 19 && e1 <= 49){
            int eq1 = roundUp(e1*1.0/9 + 21);
            exp2 += eq1;
             int num14 = checkNumberExp(exp2);
            exp2 = num14;;
        } else if (e1 > 49 && e1 <= 65){
            int eq1 = roundUp(e1*1.0/16 + 17);
            exp2 += eq1;
             int num14 = checkNumberExp(exp2);
            exp2 = num14;
        } else if (e1 > 65 && e1 <= 79){
            int eq1 = roundUp(e1*1.0/4 + 19);
            exp2 += eq1;
             int num16 = checkNumberExp(exp2);
            exp2 = num16;;
            if (exp2 > 200){
                int eq1 = roundUp(e1*1.0/9 + 21);
                exp2 += eq1;
                int num21 = checkNumberExp(exp2);
                exp2 = num21;
            }
            int num14 = checkNumberExp(exp2);
            exp2 = num14;;
        }
    else {
        int eq1 = roundUp(e1*1.0/4 + 19);
        exp2 += eq1;
        int num15 = checkNumberExp(exp2);
        exp2 = num15;
        int eq2 = roundUp(e1*1.0/9 + 21);
        exp2 += eq2;
        int num14 = checkNumberExp(exp2);
        exp2 = num14;;
        if (exp2 > 400){
            int eq1 = roundUp(e1*1.0/16 + 17);
            exp2 += eq1;
            int num15 = checkNumberExp(exp2);
            exp2 = num15;
            int eq2 = roundUp(exp2*1.15);
            exp2 = eq2;
            int num14 = checkNumberExp(exp2);
            exp2 = num14;
        }
    }
    int num13 = checkNumberExp(exp1);
    exp1 = num13;
    exp1 -= e1;
    int num1 = checkNumberExp(exp1);
    exp1 = num1;
    int num2 = checkNumberExp(exp2);
    exp2 = num2;
    }
    return exp1 + exp2 ;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
  if (E2 > 99 || E2 < 0){
        return -99;
    }
    int num2 = checkNumberHp(HP1);
    HP1 = num2;
    int num3 = checkNumberExp(EXP1);
    EXP1 = num3;
    int num20 = checkMoney(M1);
    M1 = num20;
    float P1;
    float P2;
    float P3;
    float Pavg;
        // FIRST ROUTE
        int S1 = nearestPerfectSquare(EXP1);
        if (EXP1 >= S1){
            P1 = 1.0;
        } else {
            P1 = (EXP1*1.0/S1 + 80)/123;
        // P1 = ((int)(eq1 * 100 ) + roundUp(eq1*1000 - int(eq1*1000)))/100.0;
        }
        // SECOND ROUTE
        int InitialMoney = M1;
        while (true){
            if (M1 == 0 || ((E2 % 2 != 0) && ((InitialMoney - M1*1.0) > (InitialMoney*0.5)))){break;}
            if (HP1 < 200){
                int eq1 = roundUp(HP1*1.3);
                HP1= eq1;
                int temp1 = checkNumberHp(HP1);
                HP1 = temp1;
                M1 -= 150;
                int temp2 = checkMoney(M1);
                M1 = temp2;
            }
            else {
                int eq1 = roundUp(HP1*1.1);
                HP1 = eq1;
                int temp1 = checkNumberHp(HP1);
                HP1 = temp1;
                M1 -= 70;
                int temp2 = checkMoney(M1);
                M1 = temp2;
            }


            if (M1 == 0 || ((E2 % 2 != 0) && ((InitialMoney - M1*1.0) > (InitialMoney*0.5)))){break;}
            if(EXP1 < 400){
                int eq1 = roundUp(EXP1*1.13);
                EXP1 = eq1;
                int temp3 = checkNumberExp(EXP1);
                EXP1 = temp3;
                M1 -= 200;
                int temp2 = checkMoney(M1);
                M1 = temp2;
            }
            else {
                int eq1 = roundUp(EXP1*1.13);
                EXP1 = eq1;
                int temp3 = checkNumberExp(EXP1);
                EXP1 = temp3;
                 M1 -= 120;
                int temp2 = checkMoney(M1);
                M1 = temp2;
            }

            if(M1 == 0 || ((E2 % 2 != 0) && ((InitialMoney - M1*1.0) > (InitialMoney*0.5)))){break;}
            if (EXP1 < 300){
                M1 -= 100;
                int eq1 = roundUp(EXP1*0.9);
                EXP1 = eq1;
                int temp3 = checkNumberExp(EXP1);
                EXP1 = temp3;
                int temp2 = checkMoney(M1);
                M1 = temp2;
            } 
            else {
                M1 -= 120;
                int eq1 = roundUp(EXP1*0.9);
                EXP1 = eq1;
                int temp3 = checkNumberExp(EXP1);
                EXP1 = temp3;
                int temp2 = checkMoney(M1);
                M1 = temp2;
            }

            if (M1 == 0 || ((E2 % 2 != 0) && ((InitialMoney - M1*1.0) > (InitialMoney*0.5)))){break;}

            if(E2 % 2 == 0) break;
    }
    int temp1 = roundUp(HP1*0.83);
    HP1 = temp1;
    int temp2 = checkNumberHp(HP1);
    HP1 = temp2;
    int temp3 = roundUp(EXP1*1.17);
    EXP1 = temp3;
    int temp4 = checkNumberExp(EXP1);
    EXP1 = temp4;
    int S2 = nearestPerfectSquare(EXP1);
    if (EXP1 >= S2) {
        P2 = 1;
    }
    else P2 = (EXP1*1.0/S2 + 80)/123;

    //THIRD ROUTE
    float P[] = {0.32, 0.47, 0.28, 0.79,1,0.5, 0.22,0.83,0.64,0.11};
    for ( int i = 0; i < 10; i++){
        if (E2 < 10){
            P3 = P[E2];
        } else {
            int tmp =((E2%10) + (E2/10));
            P3 = P[tmp%10];
        }
    }

    if(P1 == 1 && P2 == 1 && P3 == 1) {
        int temp70 = roundUp(EXP1*0.75);
        EXP1 = temp70;
        int temp120 = checkNumberExp(EXP1);
        EXP1 = temp70;
    } else {
        float eq10 = (P1 + P2 + P3)/3;
        Pavg = eq10;
    // Pavg = ((int)(eq10 * 100 ) + roundUp(eq10*1000 - int(eq10*1000)))/100.0;
        if (Pavg < 0.5){
            int hehe1 = roundUp(HP1*0.85);
            HP1 = hehe1;
            int hehe3 = checkNumberHp(HP1);
            HP1 = hehe3;
            int hehe2 = roundUp(EXP1*1.15);
            EXP1 = hehe2;
            int hehe =checkNumberExp(EXP1);
            EXP1 = hehe;
        } else {
            int temp11 = roundUp(HP1*0.9);
            HP1 = temp11;
            int temp12 = checkNumberHp(HP1);
            HP1 = temp12;
            int temp13 = roundUp(EXP1*1.2);
            EXP1 = temp13;
            int temp14 = checkNumberExp(EXP1);
            EXP1 = temp14;
            
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
         if (E3 > 99 || E3 < 0){
        return -99;
    }
    int temp14 = checkNumberHp(HP1);
    HP1 = temp14;
    int temp15 = checkNumberHp(HP2);
    HP2 = temp15;
    int temp16 = checkNumberExp(EXP1);
    EXP1 = temp16;
    int temp17 = checkNumberExp(EXP2);
    EXP2 = temp17;
    int countpositive = 0;
    int countnegative = 0;
    int map[10][10];
    int imeet;
    int jmeet;
    int mapSherlock[10][10];
    for (int i= 0; i < 10; i++){
        for ( int j = 0; j < 10 ; j++){
            map[i][j] = ((E3*j)+(i*2))*(i-j);
        }
    }
     for (int i= 0; i < 10; i++){
        for ( int j = 0; j <10 ; j++){
        int maxLeft = maxLeftDiagonal(map,i,j);
        int maxRight = maxRightDiagonal(map,i,j);
        mapSherlock[i][j] = findMax(maxLeft, maxRight); 
        }
     }
   for (int i= 0; i < 10; i++){
        for ( int j = 0; j < 10 ; j++){
            if (map[i][j] >= 0 ){
                if (map[i][j] > (E3*2)){
                    countpositive++;
                }
            }
            else {
                if (map[i][j] < (-E3)){
                countnegative++;
                }
            }
        }
    }
   if (countpositive < 10){
        imeet = countpositive;
    } else {
        while ((int(countpositive/10) + countpositive%10) > 9 ){
            countpositive = int(countpositive/10) + countpositive%10; 
        } 
        imeet =  int(countpositive/10) + countpositive%10;
    }
     if (countnegative < 10){
        jmeet = countnegative;
    } else {
        while ((int(countnegative/10) + countnegative%10) > 9 ){
            countnegative = int(countnegative/10) + countnegative%10; 
        } 
        jmeet = int(countnegative/10) + countnegative%10;
    }
 if (abstract(map[imeet][jmeet]) > mapSherlock[imeet][jmeet]){
    int temp1 = roundUp(EXP1*0.88);
    EXP1 = temp1;
    int temp2 = checkNumberExp(EXP1);
    EXP1 = temp2;
     int temp3 = roundUp(EXP2*0.88);
    EXP2 = temp3;
    int temp4 = checkNumberExp(EXP2);
    EXP2 = temp4;
    int temp5 = roundUp(HP1*0.9);
    HP1 = temp5;
    int temp6 = checkNumberHp(HP1);
    HP1 = temp6;
    int temp7 = roundUp(HP2*0.9);
    HP2 = temp7;
    int temp8 = checkNumberHp(HP2);
    HP2 = temp8;
    return map[imeet][jmeet];
 } else {
      int temp1 = roundUp(EXP1*1.12);
    EXP1 = temp1;
    int temp2 = checkNumberExp(EXP1);
    EXP1 = temp2;
     int temp3 = roundUp(EXP2*1.12);
    EXP2 = temp3;
    int temp4 = checkNumberExp(EXP2);
    EXP2 = temp4;
    int temp5 = roundUp(HP1*1.1);
    HP1 = temp5;
    int temp6 = checkNumberHp(HP1);
    HP1 = temp6;
    int temp7 = roundUp(HP2*1.1);
    HP2 = temp7;
    int temp8 = checkNumberHp(HP2);
    HP2 = temp8;
    return mapSherlock[imeet][jmeet];
 }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
     //CALCULATE SE
    string se;
   for (int i= 0; i < strlen(email); i++){
     if ( email[i] != '@' ){
         se += email[i];
     }
   else break;
  }
      //CHECK VALID PASSWORD
      bool hasSE = false;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == se[0]) {
            int count = 0;
            for (int j = 0; j < se.length(); j++) {
                if(j + i > strlen(s)) break;
                if (s[j + i] == se[j]){
                    count += 1;
                }
            }  
            if (count ==  se.length()) {
                bool hasSE = true;
            }
        }
    }
     bool checkCharacter = true;
    for (int i = 0; i < strlen(s); ++i) {
        if (!( (s[i] >= '0' && s[i] <= '9') ||
               (s[i] >= 'a' && s[i] <= 'z') ||
               (s[i] >= 'A' && s[i] <= 'Z') ||
               (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') )) {
            checkCharacter = false;
            break;
    }
    }
    bool checksamechar = false;
     for (int i= 0; i < strlen(s)-2; ++i){
         if (s[i] == s[i+1] && s[i] == s[i+2]) {
           checksamechar = true;
           break;
    }
     }
    bool hasSpecialCharac = false;
    for (int i = 0; i < strlen(s); i++){
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'){
            hasSpecialCharac = true;
            break;
        }
    }
    if ( (strlen(s) >= 8 && strlen(s) <= 20) && (checkCharacter = true) && (hasSE = false) && (checksamechar = false) && (hasSpecialCharac = true)){
        return -10;
    } 
    else {
    //IF NOT VALID WE CONTINUE
    int length = strlen(s);
     if (length < 8){
      return -1;
     }
    if (length > 20){ 
    return -2; 
    }

  //CHECK IF SE IN S
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == se[0]) {
            int count = 0;
            for (int j = 0; j < se.length(); j++) {
                if(j + i >= strlen(s)) break;
                if (s[j + i] == se[j])
                    count += 1;
            }  
            if (count == se.length()) {
            return -(300 + i);
            }
        }
    }
  //CHECK iF MORE THAN 2 CHAR IN S
    for (int i= 0; i < (int)strlen(s)-2; ++i){
         if (s[i] == s[i+1] && s[i] == s[i+2]) {
            return -(400 + i);
    }
    }
     //CHECK IF HAS SPECIAL CHAR
    bool hasSpecialChar = false;
    for (int i = 0; i < (int)strlen(s); i++){
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'){
            hasSpecialChar = true;
            break;
        }
    }
    if (hasSpecialChar != true ){
        return -5;
    }
    //IF NONE OF THOSE ABOVE
    
      for (int i = 0; i < (int)strlen(s); ++i) {
        if (!( (s[i] >= '0' && s[i] <= '9') ||
               (s[i] >= 'a' && s[i] <= 'z') ||
               (s[i] >= 'A' && s[i] <= 'Z') ||
               (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') )) {
            return i;
    }
      }
     }
     return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {

    int lengthMax = 0;
    int repeatMAX = 0;
    int index;

    for (int i = 0; i < num_pwds; ++i) {

        int count = 0;

        for(int j = i; j < num_pwds; ++j){
            if(strcmp(arr_pwds[i], arr_pwds[j]) == 0) count++;
        }

        if(count > repeatMAX || ((count == repeatMAX) && (strlen(arr_pwds[i]) > lengthMax))){
            repeatMAX = count;
            lengthMax = strlen(arr_pwds[i]);
            index = i;
        }

    }
    
    return index;
    
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////