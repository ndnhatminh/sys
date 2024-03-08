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

int firstMeet(int & exp1, int & exp2, int e1) {
// TODO: Complete this function
// CASE 1
   if (e1<0||e1>99){
    return-99;
      exit(-99);
  
   }

if (e1>=0&&e1<4){ 
    int D;
    if(e1 == 0){
       exp2+=29;
    }
    else if (e1 == 1){
       exp2+=45;
    }
    else if (e1 == 2){
       exp2+=75;
    }
    else if (e1 == 3){ 
       exp2+=149;
       }
 D = e1*3 + exp1*7;
 if( D%2 == 0){
       
       exp1 = ceil(exp1 +(D*1.00)/200);
       
    }
    else if ( D%2 != 0) {
       
       exp1 =  ceil(exp1 - (D*1.00)/100);
      
    }
 }


// calculate exp1
    
// CASE 2
    if (e1>=4&&e1<=19){
        exp2 = ceil(exp2+(e1*1.00)/4+19);
        exp1=exp1 - e1;
    }
    else if (e1>=20&&e1<=49){
        exp2 = ceil(exp2+(e1*1.00)/9+21);
        exp1=exp1 - e1;
    }
    else if (e1>=50&&e1<=65){
        exp2 = ceil(exp2+(e1*1.00)/16+17);
        exp1=exp1 - e1;
    }
    else if (e1>=66&&e1<=79){
        exp2 += (e1/4)+19;
        if(exp2 > 200){exp2= ceil(exp2+(e1*1.00)/9+21);}
        exp1=exp1 - e1;
        
    }
    else if (e1>=80&&e1<=99){
        exp2 = ceil(exp2+(e1*1.00)/4)+19+ceil((e1*1.00)/9)+21;
        if(exp2 > 400){exp2= ceil(exp2+(e1*1.00)/16+17);exp2 =ceil(exp2*1.15);}
        exp1=exp1 - e1;
    }


//condition for exp1 and exp2   
    if(exp1>600){
        exp1 = 600;
    }
    else if (exp1<0){
        exp1 = 0;
    }
    if(exp2>600){
        exp2 = 600;
    }
     else if (exp2<0){
        exp2 = 0;
    }

  
    

return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
//ROAD 1
     // Road 1
    int E2=E3;
    if (E2<0||E2>99){return-99;exit(-99);}

    int S1;
    float P1, P2, P3;
    int  costThreshold = M1/2;
   
    int s1,s2;

    int sq1 = sqrt(EXP1);
    int squareBelow1 = sq1 * sq1;
    int squareAbove1 = (sq1 + 1) * (sq1 + 1);

    if (EXP1 - squareBelow1 <= squareAbove1 - EXP1) {
        s1=squareBelow1;
    }
    else if(EXP1 - squareBelow1 > squareAbove1 - EXP1) {
        s1= squareAbove1;
    }
    
    if (s1>EXP1){
        P1 = 100;}
    else if (s1<EXP1 || s1 == EXP1){
        double propotion1 = (EXP1/s1);
        P1 = (propotion1+80)/123;}
   

 //Road 2
 
int cost = 0;
if(E2%2==0||E2%2!=0){
    if (HP1 < 200 && M1 > 0&&cost<=costThreshold) {
        HP1 = ceil(1.3 * HP1);
        M1 -= 150;
        cost+=150;
        
    }
    else if (HP1>=200&&M1 > 0&&cost<=costThreshold) {
        HP1 = ceil(1.1 * HP1);
        M1 -= 70;
        cost+=70;
        
    }

    if (EXP1 < 400 && M1 > 0&&cost<=costThreshold) {
        M1 -= 200;
        cost+=200;
        EXP1 = ceil(1.13 * EXP1);
    }
    else if (EXP1 >= 400 &&M1 > 0&&cost<=costThreshold) {
        M1 -= 120;
        cost+=120;
        EXP1 = ceil(1.13 * EXP1);
    }
    
    if (EXP1 < 300 && M1 > 0&&cost<=costThreshold) {
        M1 -= 100;
        cost+=100;
       
    }
    else if (EXP1 >= 300 &&M1 > 0&&cost<=costThreshold) {
        M1 -= 120;
        cost+=120;
        
    }
    EXP1 = ceil(0.9 * EXP1);
}
    if (E2 % 2 !=0) {
        if (HP1 < 200 && M1 > 0&&cost<=costThreshold) {
        HP1 = ceil(1.3 * HP1);
        M1 -= 150;
        cost+=150;
      
    }
    else if (HP1>=200&&M1 > 0&&cost<=costThreshold) {
        HP1 = ceil(1.1 * HP1);
        M1 -= 70;
        cost+=70;
        
    }

    if (EXP1 < 400 && M1 > 0&&cost<=costThreshold) {
        M1 -= 200;
        cost+=200;
        
    }
    else if (EXP1 >= 400 &&M1 > 0&&cost<=costThreshold) {
        M1 -= 120;
        cost+=120;
       
    }
    EXP1 = ceil(1.13 * EXP1);
    if (EXP1 < 300 && M1 > 0&&cost<=costThreshold) {
        M1 -= 100;
        cost+=100;
        
    }
    else if (EXP1 >= 300 &&M1 > 0&&cost<=costThreshold) {
        M1 -= 120;
        cost+=120;
        
    }
    EXP1 = ceil(0.9 * EXP1);  
    }
      if (cost>costThreshold||M1<=0&&cost>costThreshold){ 
        HP1 = ceil(0.83 * HP1);
        EXP1 = ceil(1.17 * EXP1);
    }
    

    int sq2 = sqrt(EXP1);
    int squareBelow2 = sq2 * sq2;
    int squareAbove2 = (sq2 + 1) * (sq2 + 1);

    if (EXP1 - squareBelow2 <= squareAbove2 - EXP1) {
        s2=squareBelow2;
    }
    else if(EXP1 - squareBelow2 > squareAbove2 - EXP1) {
        s2= squareAbove2;
    }
    
    if (s2>EXP1){
        P2 = 1;}
    else if (s2<=EXP1 ){
        double propotion2 = (EXP1/s2);
        P2 = (propotion2+80)/123;}
       

 //Road 3
        int P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        const int SIZE = 10;
        int i, sum;
        if (E2 >= 10 && E2 <= 99) {
            sum = (E2 / 10) + (E2 % 10);
            i = sum % 10;
        }
        else {
            i = E2;
        }
        P3 = P[i] / 100.0;
        if (P1 == 1 && P2 == 1 && P3 == 1) {
            EXP1 = 0.75 * EXP1;
        }
        else {
            float avg;
            avg = (P1 + P2 + P3) / 3;
            if (avg < 0.5) {
                HP1 = ceil(0.85 * HP1);
                EXP1 = ceil(1.15 * EXP1);
            }
            else {
                HP1 = ceil(0.9 * HP1);
                EXP1 = ceil(1.2 * EXP1);
            }

        }
       HP1 = max(0, min(666, HP1));
       EXP1 = max(0, min(600, EXP1));
       M1 = max(0, min(3000, M1)); 
        
        
        return HP1+EXP1+M1;
}

// Task 3

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
   if (E3<0||E3>99){
    return-99;
      exit(-99);
       
   }

    const int size = 10;
    int i, j;
    int matrix[size][size];
    

    for (int a = 0; a < size; a++) {
        for (int b = 0; b < size; ++b) {
            matrix[a][b] = ((E3 * b) + (a * 2)) * (a - b);
         
        }

    }
    int countpositive = 0;
    int countnegative = 0;
    for (int a = 0; a < size; a++) {
        for (int b = 0; b < size; ++b) {
            if (matrix[a][b] > (E3 * 2)) {
                countpositive += 1;
            }
        }
    }
    for (int a = 0; a < size; a++) {
        for (int b = 0; b < size; ++b) {
            if (matrix[a][b] < (-E3)) {
                countnegative += 1;
            }
        }
    }
   
    while (countpositive >= 10 && countpositive <= 99) {
       countpositive = (countpositive / 10) + (countpositive % 10);  
    }
    i = countpositive;
    while (countnegative >= 10 && countnegative <= 99) {
        countnegative = (countnegative / 10) + (countnegative % 10);
    }
    j = countnegative;


        int taxi;
        int max = matrix[i][j];
        //right:
        int a = i;
        int b = j;
        while ( a > 0 && b < size) {
            if (matrix[a][b] > max) {
                max = matrix[a][b];
            }
            a -= 1;
            b += 1;
        }

        a = i;
        b = j;
        while (a < size && b > 0) {
            if (matrix[a][b] > max) {
                max = matrix[a][b];
            }
            a += 1;
            b -= 1;
        }
       //left:

        a = i;
        b = j;
        while (a <size && b < size) {
            if (matrix[a][b] > max) {
                max = matrix[a][b];
            }
            a += 1;
            b += 1;
        }

        a = i;
        b = j;
        while (a >0 && b > 0) {
            if (matrix[a][b] > max) {
                max = matrix[a][b];
            }
            a -= 1;
            b -= 1;
        }
        taxi = abs(matrix[i][j]);
        int result;
        if (taxi < max) {
            EXP1 = ceil(EXP1 * 1.12);
            HP1 = ceil(HP1 * 1.1);
            EXP2 = ceil(EXP2 * 1.12);
            HP2 = ceil(HP2 * 1.1);
            result = max;
        }
        else (taxi >= max) {
            EXP1 = ceil(EXP1 *0.88 );
            HP1 = ceil(HP1 * 0.9);
            EXP2 = ceil(EXP2 * 0.88);
            HP2 = ceil(HP2 * 0.9);
            result = matrix[i][j];
        }
    

   return result;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int n = strlen(s); //strlen() is used to return the length of a string
    int email_se_pos = strcspn(email, "@");//strcspn is used to return the string from the first position to the position before @
    string se(email, 0, email_se_pos); //se is a substring starts at position 0 and end a position email_se_pos

    // Check length
    if (n < 8) {return -1;}
    if (n > 20) {return -2;}

    // Check for se
    if (strstr(s, se.c_str()) != nullptr) {return -(300 + strstr(s, se.c_str()) - s);}
    // strstr is used to return the substring in string s from a position to another position
    /*c_str() returns a pointer to a null-terminated character array, which is a C-style string. 
    This function is useful when you need to pass a C++ string to a function that expects a C-style string.*/


    // Check for special characters
    bool has_special_char = true;
    for (int i = 0; i < n; i++) {
        if (!isalnum(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') { // isalnum is used to check whether s[i] is a number
            has_special_char = false;
            break;
        }
    }
    if (has_special_char) {return -5;}

    // Check for more than 2 consecutive characters
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) return -(400 + i);
    }

    // Check for invalid characters
    for (int i = 0; i < n; i++) {
        if (!isalnum(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') {
            return i;
        }
    }

    return -10;
    
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxCount = 0;
    int maxLength = 0;
    int correctPasswordIndex = -1;

    for (int i = 0; i < num_pwds; i++) {
        int count = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) { //strcmp is used to compare the common that 2 arrays share
                count++;
            }
        }

        if (count > maxCount || (count == maxCount && strlen(arr_pwds[i]) > maxLength)) {
            maxCount = count;
            maxLength = strlen(arr_pwds[i]);
            correctPasswordIndex = i;
        }
    }

    return correctPasswordIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////