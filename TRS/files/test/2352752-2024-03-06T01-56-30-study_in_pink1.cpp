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

//round the values
int my_ceil(float a)
{
    int temp = (int) a;
    if (a == temp) {
        return a;
    }
    return temp + 1;
}
//limit values
int checkEXP(double EXP){
    EXP = my_ceil(EXP);
    if( EXP < 0){ EXP = 0;}
    if( EXP > 600){ EXP = 600;}
    return EXP;} 

int checkHP(double HP){
    HP = my_ceil(HP);
    if( HP < 0){ HP = 0;}
    if( HP > 666 ){ HP = 666;}
    return HP;}

int checkM(double M){
    M = my_ceil(M);
    if( M < 0){ M = 0;}
    if( M > 3000){ M = 3000;}
    return M;}

int nearSQ(double n){
    int N = round(sqrt(n));
        int lower_square = N * N;
        int upper_square = (N + 1) * (N + 1);
        int nearest_square;

        if (n - lower_square <= upper_square - n) {
            nearest_square = lower_square;
        }
        else {
            nearest_square = upper_square;
        }
        return nearest_square;
    }


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    if ( e1 < 0 || e1 > 99 ){return -99;}
    //convert int to double for rounding
    double test_EXP1, test_EXP2;
    test_EXP1 = exp1;
    test_EXP2 = exp2;
    
    //CASE 1
    if (e1<=3 && e1>=0){
        if(e1==0){test_EXP2 = test_EXP2 + 29; test_EXP2 = checkEXP(test_EXP2);}
        if(e1==1){test_EXP2 = test_EXP2 + 45; test_EXP2 = checkEXP(test_EXP2);}
        if(e1==2){test_EXP2 = test_EXP2 + 75; test_EXP2 = checkEXP(test_EXP2);}
        if(e1==3){test_EXP2 = test_EXP2 + 29 + 45 + 75; test_EXP2 = checkEXP(test_EXP2);}
        
        int D;
        D = (e1*3 + test_EXP1*7); 
        if ( D%2==0 ){test_EXP1 = test_EXP1 + D/200.0; test_EXP1 = checkEXP(test_EXP1);}
        else{test_EXP1 = test_EXP1 - D/100.0; test_EXP1 = checkEXP(test_EXP1);}
    }
    
    //CASE 2
    if (e1>=4 && e1<=99){
        if (e1>=4 && e1<=19)    {test_EXP2 = test_EXP2 + e1/4.0 + 19;  test_EXP2 = checkEXP(test_EXP2);}
        if (e1>=20 && e1<=49)   {test_EXP2 = test_EXP2 + e1/9.0 + 21;  test_EXP2 = checkEXP(test_EXP2);}
        if (e1>=50 && e1<=65)   {test_EXP2 = test_EXP2 + e1/16.0 + 17; test_EXP2 = checkEXP(test_EXP2);}
        if (e1>=66 && e1<=79){
            test_EXP2 = test_EXP2 + e1/4.0 + 19; test_EXP2 = checkEXP(test_EXP2);
            if (test_EXP2>200){test_EXP2 = test_EXP2 + e1/9.0 + 21; test_EXP2 = checkEXP(test_EXP2);}
        }
        if (e1>=80 && e1<=99){
            test_EXP2 = test_EXP2 + e1/4.0 + 19; test_EXP2 = checkEXP(test_EXP2);
            test_EXP2 = test_EXP2 + e1/9.0 + 21; test_EXP2 = checkEXP(test_EXP2);
            if (test_EXP2>400){
                test_EXP2 = test_EXP2 + e1/16.0 + 17; test_EXP2 = checkEXP(test_EXP2);
                test_EXP2 = test_EXP2*1.15; test_EXP2 = checkEXP(test_EXP2);
                }
        }
        test_EXP1 = test_EXP1 - e1; test_EXP1 = checkEXP(test_EXP1);
    }
    exp1 = test_EXP1;
    exp2 = test_EXP2;
    return exp1 + exp2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    
    if ( E2 < 0 || E2 > 99 ){return -99;}
    //convert int to double for rounding
    double test_HP1, test_EXP1, test_M1;
    test_HP1 = checkHP(HP1);
    test_EXP1 = checkEXP(EXP1);
    test_M1 = checkM(M1);
    
    //ROAD 1
    double P1;
    int S1;
    S1 = nearSQ(test_EXP1);
    if( EXP1 >= S1){P1 = 1.0;}
    else{ P1 = (test_EXP1/S1 + 80) / 123.0;}

    //ROAD 2
    int maxSpent = M1*0.5;
    do{
    //event1
    if(test_HP1<200){
        test_HP1 = checkHP(test_HP1*1.3);
        test_M1 = checkM(test_M1 - 150);
    }
    else{
    test_HP1 = checkHP(test_HP1*1.1);
    test_M1 = checkM(test_M1 - 70 );
    }
    if ( (E2%2==1 && test_M1 < maxSpent) || (test_M1 == 0) ){ break; }
   
    //event2
    if(test_EXP1<400){test_M1 = checkM(test_M1 - 200);}
    else             {test_M1 = checkM(test_M1 - 120);}
    test_EXP1 = checkEXP(test_EXP1*1.13);
    if ( (E2%2==1 && test_M1 < maxSpent) || (test_M1 == 0)){ break; }
   
    //event3
    if(test_EXP1<300){test_M1 = checkM(test_M1 - 100);}
    else             {test_M1 = checkM(test_M1 - 120);}
    test_EXP1 = checkEXP(test_EXP1*0.9);
    if ( (E2%2==1 && test_M1 < maxSpent) || (test_M1 == 0)){ break; }
    }
    while(E2%2 == 1);
   
    test_HP1 = checkHP(test_HP1*0.83);
    test_EXP1 = checkEXP(test_EXP1*1.17);

    double P2;
    int S2;
    S2 = nearSQ(test_EXP1);
    if(test_EXP1>=S2){P2=1;}
    else{P2=(test_EXP1/S2 + 80)/123.0;}
    
    //ROAD 3
    int rate[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int position = 0;
    if(E2>=0 && E2 <=9){ position = E2; }
    else{
    int chuc = E2/10;
    int donvi = E2%10;
    int tong = chuc + donvi;
    position = tong%10;}
    double P3 = rate[position]/100.0;
    
    //CHECK
    if(P1==1.0 && P2==1.0 && P3==1.0){test_EXP1 = checkEXP(test_EXP1*0.75);}
    else{
        double totalRate = (P1+P2+P3)/3.0;
        if(totalRate<0.5){
            test_HP1 = checkHP(test_HP1*0.85);
            test_EXP1 = checkEXP(test_EXP1*1.15);
        }
        else{
            test_HP1 = checkHP(test_HP1*0.9);
            test_EXP1 = checkEXP(test_EXP1*1.2);
        }
    }  

    HP1 = checkHP(test_HP1);
    EXP1 = checkEXP(test_EXP1);
    M1 = checkM(test_M1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    if ( E3 < 0 || E3 > 99 ){return -99;}
    //int to double for rounding
    double test_HP1, test_EXP1, test_HP2, test_EXP2;
    test_HP1 = HP1;
    test_EXP1 = EXP1;
    test_HP2 = HP2;
    test_EXP2 = EXP2;

    // Make matrix
    int matrix[10][10];
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            matrix[i][j] = ((E3*j)+(i*2))*(i-j); // Value with formula
            }
        }
  
    // Find the meeting point
    int meet_i = 0, meet_j = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(matrix[i][j] > E3 * 2 && matrix[i][j] > 0) {
                meet_i++;
            }
            if(matrix[i][j] < -E3 && matrix[i][j] <0) {
                meet_j++;
            }
        }
    }

    // i or j is a 2 digits number,repeat  until the sum is the one number
    while(meet_i >= 10) {
        meet_i = meet_i / 10 + meet_i % 10;
    }
    while(meet_j >= 10) {
        meet_j = meet_j / 10 + meet_j % 10;
    }
    
    int maxPoint = matrix[meet_i][meet_j];
    //Right Diagonal
    for(int i = 0; i < 10; i++) {
        int j = meet_i + meet_j - i;
        if(j >= 0 && j < 10) {
            if( matrix[i][j] > maxPoint){ maxPoint =matrix[i][j]; }}}
    //Left Diagonal
    for(int i = 0; i < 10; i++) {
        int j = i - meet_i + meet_j;
        if(j >= 0 && j < 10) {
            if( matrix[i][j] > maxPoint){ maxPoint =matrix[i][j]; }}}

    // Check if they can catch the taxi
    if (abs(matrix[meet_i][meet_j]) > maxPoint){ //They don't catch the taxi
        test_EXP1 = test_EXP1*(1-0.12); test_EXP1 = checkEXP(test_EXP1);
        test_EXP2 = test_EXP2*(1-0.12); test_EXP2 = checkEXP(test_EXP2);
        test_HP1 = test_HP1*(1-0.1); test_HP1 = checkHP(test_HP1);
        test_HP2 = test_HP2*(1-0.1); test_HP2 = checkHP(test_HP2);}
    else{
        test_EXP1 = test_EXP1*(1+0.12); test_EXP1 = checkEXP(test_EXP1);
        test_EXP2 = test_EXP2*(1+0.12); test_EXP2 = checkEXP(test_EXP2);
        test_HP1 = test_HP1*(1+0.1); test_HP1 = checkHP(test_HP1);
        test_HP2 = test_HP2*(1+0.1); test_HP2 = checkHP(test_HP2);}

    int return_value;
    if( abs(matrix[meet_i][meet_j]) <= maxPoint){ return_value = maxPoint;}
    else{ return_value = matrix[meet_i][meet_j];}

    EXP1 = test_EXP1;
    HP1 = test_HP1;
    EXP2 = test_EXP2;
    HP2 = test_HP2;
    
    return return_value;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
    //Find se
    char se[100];
    strncpy(se, email, strchr(email, '@') - email);
    se[strchr(email, '@') - email] = '\0'; // Null terminate the se string
    //Length?
    if(strlen(s) < 8) {return -1;}
    if(strlen(s) > 20) {return -2;}
    // s has se
    const char *pos = strstr(s, se);
    if(pos != NULL) { return -(300 + (pos - s));}
    // more than 2 char repeat
    for(int i = 0; i < strlen(s) - 2; i++) {
        if(s[i] == s[i+1] && s[i] == s[i+2]) {
            return -(400 + i);}}
    // have specChar?
    bool hasSpecialChar = false;
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            hasSpecialChar = true;}}
    // if yes return
    if(!hasSpecialChar) {return -5;}
    // valid pass have 0-9 a-z A-Z specChar
    for(int i = 0; i < strlen(s); i++) {
        if(!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || 
             (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')) {
            return i;
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    int max_count = 0;
    int max_length = 0;
    int position = -1;
    string correctPass;

    for (int i = 0; i < num_pwds; ++i) {
        string pass = arr_pwds[i];
        int count = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (pass == arr_pwds[j]) {
                count++;
            }
        }

        if (count > max_count || (count == max_count && pass.length() > max_length)) {
            correctPass = pass;
            max_count = count;
            max_length = pass.length();
            position = i;
        }
    }
    
    return position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////