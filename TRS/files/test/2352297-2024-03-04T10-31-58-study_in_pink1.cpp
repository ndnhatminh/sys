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

//
int roundupto(float num){
    return num + 0.999;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    //Check legitimate
    if (e1 < 0 || e1 > 99)
        return -99;

    //Check Cap
    exp1<0? exp1 = 0 : exp1 = exp1;
    exp1>600? exp1 = 600 : exp1 = exp1;
    exp2<0? exp2 = 0 : exp2 = exp2;
    exp2>600? exp2 = 600 : exp2 = exp2;

    switch (e1){
//Case 1:
    case 0:
        exp2+=29;
        break;
    
    case 1:
        exp2+=45;
        break;

    case 2:
        exp2+=75;
        break;

    case 3:
        exp2+=(29 + 45 + 75);
        break;
//End of Case 1.

//Check cap of EXP2
exp2 < 0? exp2 = 0 : exp2 = exp2;
exp2 > 600? exp2 = 600 : exp2 = exp2;
                        
//Case 2:
    case 4 ... 19:
        exp2 = roundupto(exp2 +((e1/4.0) + 19));
        break;

    case 20 ... 49:
        exp2 = roundupto(exp2 +((e1/9.0) + 21));
        break;

    case 50 ... 65:
        exp2 = roundupto(exp2 +((e1/16.0) + 17));
        break;

    case 66 ... 79:
        exp2 = roundupto(exp2 +((e1/4.0) + 19)); //Info 1

        //Check cap of EXP2
        exp2 < 0? exp2 = 0 : exp2 = exp2;
        exp2 > 600? exp2 = 600 : exp2 = exp2;

        exp2 > 200? exp2 = 0.99 + (exp2 + ((e1/9.0) + 21)) : exp2 = exp2;
        break;

    case 80 ... 99:
        exp2 = roundupto(exp2 +((e1/4.0) + 19)); //Info 1
        exp2 = roundupto(exp2 +((e1/9.0) + 21)); //Info 2

        //Check cap of EXP2
        exp2 < 0? exp2 = 0 : exp2 = exp2;
        exp2 > 600? exp2 = 600 : exp2 = exp2;

        if (exp2 > 400){
            exp2 = roundupto(exp2 +((e1/16.0) + 17));
            exp2 = roundupto(exp2*1.15);
        }
        break;

    default:
        break;
    }

    //Check cap of EXP2
    exp2 < 0? exp2 = 0 : exp2 = exp2;
    exp2 > 600? exp2 = 600 : exp2 = exp2;

    //Case 1:
    if (e1 <= 3 && e1 >= 0){
        int D = e1*3 + exp1*7 ; //Decision
        D%2==0? exp1 = roundupto(exp1 + (D/200.0)) : exp1 = roundupto(exp1 - (D/100.0));
    }

    //Case 2:
    if (e1 <= 99 && e1 >= 4){
        exp1-=e1;
    }
    
    //Check Cap
    exp1<0? exp1 = 0 : exp1 = exp1;
    exp1>600? exp1 = 600 : exp1 = exp1;
    exp2<0? exp2 = 0 : exp2 = exp2;
    exp2>600? exp2 = 600 : exp2 = exp2;

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    
    //Check legitimate
    if (E2 < 0 || E2 > 99)
        return -99;
    
    //Check Cap
    EXP1<0? EXP1 = 0 : EXP1 = EXP1;
    EXP1>600? EXP1 = 600 : EXP1 = EXP1;
    HP1 < 0? HP1 = 0 : HP1 = HP1;
    HP1 > 666? HP1 = 666 : HP1 = HP1;
    M1 < 0? M1 = 0 : M1 = M1;
    M1 > 3000? M1 = 3000 : M1 = M1;

        //Road 1:
    int P1; 
    float S = pow(round(sqrt(EXP1)), 2);
    EXP1 >= S? P1 = 100 : P1 = (((EXP1/S) + 80)/123.0)*100;

        //Road2:
    int temp = M1/2;

    if (M1 == 0)
        goto EndofRoad;
        
        Road2:
        //First
    if (HP1 < 200){
        HP1 += roundupto(HP1*0.3);
        M1-=150;
    }
    else{
        HP1 += roundupto(HP1*0.1);
        M1-=70;
    }

    //Check cap
    HP1 < 0? HP1 = 0 : HP1 = HP1;
    HP1 > 666? HP1 = 666 : HP1 = HP1;
    //M1 < 0? M1 = 0 : M1 = M1;
    M1 > 3000? M1 = 3000 : M1 = M1;

    if((E2%2==1 && M1 < temp) || (E2%2==0 && M1 < 0)){
        E2%2==0? M1 = 0 : M1 = M1;
        goto EndofRoad;
    }

        //Second                                            
    if (EXP1 < 400){
        M1-=200; //Taxi
    }
    else{
        M1-=120; //Horse
    }
    EXP1 = roundupto(EXP1*1.13);

    //Check cap
    //M1 < 0? M1 = 0 : M1 = M1;
    M1 > 3000? M1 = 3000 : M1 = M1;
    EXP1<0? EXP1 = 0 : EXP1 = EXP1;
    EXP1>600? EXP1 = 600 : EXP1 = EXP1;
    
    if((E2%2==1 && M1 < temp) || (E2%2==0 && M1 < 0)){
        E2%2==0? M1 = 0 : M1 = M1;
        goto EndofRoad;
    }

        //Third
    if (EXP1 < 300){
        M1-=100;
    }
    else{
        M1-=120;
    }
    EXP1 = roundupto(EXP1*0.9);

    //Check cap
    M1 < 0? M1 = 0 : M1 = M1;
    M1 > 3000? M1 = 3000 : M1 = M1;
    EXP1<0? EXP1 = 0 : EXP1 = EXP1;
    EXP1>600? EXP1 = 600 : EXP1 = EXP1;

    if(E2%2==1 && M1 >= temp)
        goto Road2;

        EndofRoad:
    HP1 = roundupto(HP1*0.83);
    EXP1 = roundupto(EXP1*1.17);

    //Check Cap
    EXP1<0? EXP1 = 0 : EXP1 = EXP1;
    EXP1>600? EXP1 = 600 : EXP1 = EXP1;
    HP1 < 0? HP1 = 0 : HP1 = HP1;
    HP1 > 666? HP1 = 666 : HP1 = HP1;

    int P2;
    float S2 = pow(round(sqrt(EXP1)), 2);
    EXP1 >= S2? P2 = 100 : P2 = (((EXP1/S2) + 80)/123.0)*100;

        //Road3:
    int P[]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int P3;
    switch (E2){
    case 0 ... 9:
        P3 = P[E2];
        break;
    
    case 10 ... 99:
        P3 = P[((E2/10) + (E2%10))%10];
        break;

    default:
        break;
    }

    if (P1 == 100 && P2 == 100 && P3 == 100)
        EXP1 = roundupto(EXP1*0.75);
    else{
        if (roundupto((P1 + P2 + P3)/3.0) < 50){
            HP1 = roundupto(HP1*0.85);
            EXP1 = roundupto(EXP1*1.15);
        }
        else{
            HP1 = roundupto(HP1*0.9);
            EXP1 = roundupto(EXP1*1.20);
        }
    }

    //Check Cap
    EXP1<0? EXP1 = 0 : EXP1 = EXP1;
    EXP1>600? EXP1 = 600 : EXP1 = EXP1;
    HP1 < 0? HP1 = 0 : HP1 = HP1;
    HP1 > 666? HP1 = 666 : HP1 = HP1;
    M1 < 0? M1 = 0 : M1 = M1;
    M1 > 3000? M1 = 3000 : M1 = M1;

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

    //Check legitimate
    if (E3 < 0 || E3 > 99)
    return -99;

    int Taxi[10][10];
    int iM = 0, jM = 0; //Meeting coors

    //Taxi's Point Matrix
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            Taxi[j][i] = ((E3*j) + (i*2))*(i - j);
            Taxi[j][i] > (E3*2)? iM++ : iM = iM;
            Taxi[j][i] < (-E3)? jM++ : jM = jM;
        }
    }
    //End of Matrix

    //Calculate the meeting point
    while (iM > 9)
        iM = iM/10 + iM%10;
    while (jM > 9)
        jM = jM/10 + jM%10;    
    //End of Caculation

    //Sherlock & Watson points
    int SWi = iM, SWj = jM; //Sherlock & Watson
    int max = 0;

        //Left diagonal
    if (SWi > SWj){
        SWi -= SWj;
        SWj = 0;
    }
    else{
        SWj -= SWi;
        SWi = 0;
    }
    max = Taxi[SWj][SWi];
    while (SWi != 10 && SWj != 10){
        max > Taxi[SWj][SWi]? max = max : max = Taxi[SWj][SWi];
        SWi++;
        SWj++;
        
    }

        //Right diagonal
    SWi = iM; SWj = jM; //Reset
    if (SWi > (10 - SWj)){
        SWi -= (10 - SWj);
        SWj = 10;
    }
    else{
        SWj += SWi;
        SWi = 0;
    }
    while (SWi != 10 && SWj != -1){
        max > Taxi[SWj][SWi]? max = max : max = Taxi[SWj][SWi];
        SWj--;
        SWi++;
    }

    //Whether meet or not
    if (abs(Taxi[jM][iM]) > max){
        EXP1 = roundupto(EXP1*0.88);
        HP1 = roundupto(HP1*0.9);
        EXP2 = roundupto(EXP2*0.88);
        HP2 = roundupto(HP2*0.9);
    }
    else{
        EXP1 += roundupto(EXP1*0.12);
        HP1 += roundupto(HP1*0.1);
        EXP2 += roundupto(EXP2*0.12);
        HP2 += roundupto(HP2*0.1);
    }

    //Check cap
    EXP1<0? EXP1 = 0 : EXP1 = EXP1;
    EXP1>600? EXP1 = 600 : EXP1 = EXP1;
    HP1<0? HP1 = 0 : HP1 = HP1;
    HP1>666? HP1 = 666 : HP1 = HP1;
    EXP2<0? EXP2 = 0 : EXP2 = EXP2;
    EXP2>600? EXP2 = 600 : EXP2 = EXP2;
    HP2<0? HP2 = 0 : HP2 = HP2;
    HP2>666? HP2 = 666 : HP2 = HP2;

    return abs(Taxi[jM][iM]) > max? Taxi[jM][iM] : max;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    bool haveSpecial = false;

    //Get se
    int lengthEmail = strlen(email);
    char se[lengthEmail];
    for (int i = 0; i < lengthEmail; i++){
        if (email[i] != '@'){
            se[i] = email[i];
        }
        else{
            se[i] = '\0';
            break;
        }
    }

    //Check length
    if (strlen(s) < 8)
        return -1; //Minimum Length
    if (strlen(s) > 20)
        return -2;  //Maximum Length
    
    //Contain se
    if (se[0] == '\0')
        return -300;

    for (int i = 0; i < strlen(s); i++){
        if (se[0] == s[i]){
            for (int j = 0; j < strlen(se); j++){
                if (s[i + j] != se[j]){
                    break;
                }
                if (j == strlen(se)- 1)
                    return - (300 + i);
            }  
        }
    }

    //Identical Characters
    for (int i = 0; i < strlen(s); i++){
        if (s[i + 1] == s[i] && s[i + 2] == s[i])
            return - (400 + i);
    }

    //Special characters
    for (int i = 0; i < strlen(s); i++){
        switch (s[i]){
            case '@':
            case '#':
            case '%':
            case '$':
            case '!':
                haveSpecial = true;
                break;

            default:
                break;
        }
    }
    
    //have Special
    if (!haveSpecial)
        return -5;
    
    for (int i = 0; i < strlen(s); i++){
        switch(s[i]){
            case 'a' ... 'z':
            case 'A' ... 'Z':
            case '0' ... '9':
            case '@':
            case '#':
            case '%':
            case '$':
            case '!':
                break;

            default:
                return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
        // TODO: Complete this function
    string arr[num_pwds]; 
    int firstPosition[num_pwds];
    int quantity = 1; //Number of passwords

    //Filtering Passwords
    for (int i = 0; i < num_pwds; i++){
        if (i == 0){
            arr[i] = arr_pwds[i];
            firstPosition[i] = 0;
            continue; 
        }
        for (int j = (i - 1); j >= 0; j--){
            if (arr_pwds[j] == arr_pwds[i])
                break;
            if (j == 0){
                arr[quantity] = arr_pwds[i];
                firstPosition[quantity] = i;
                quantity++;
            }
        }
    }

    //Numbers of occurance of each passwords
    int repeat[quantity]; //Repeat rate of each passwords
    for (int i = 0; i < quantity; i++){
        repeat[i] = 0;
        for (int j = 0; j < num_pwds; j++){
            if (arr[i] == arr_pwds[j])
                repeat[i]++;
        }
    }

    //Final Calc
    int max = 0;
    for (int i = 1; i < quantity; i++){
        if (repeat[max] == repeat[i])
            arr[max].length() < arr[i].length()? max = i : max = max;
        repeat[max] < repeat[i]? max = i : max = max;
    }

    return firstPosition[max];
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////