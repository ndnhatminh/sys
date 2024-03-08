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

//Fucntion to modify HP, EXP and M
void modHP(int &HP){
    if(HP<0)
        HP=0;
    if(HP>666)
        HP=666;
}

void modEXP(int &EXP){
    if(EXP<0)
        EXP=0;
    if(EXP>600)
        EXP=600;
}

void modM(int &M){
    if(M<0)
        M=0;
    if(M>3000)
        M=3000;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1){
    // TODO: Complete this function
    if( e1<0 || e1>99)
        return -99;
    else if(e1>=0 && e1<=3){
       switch (e1)
       {
        case 0:
            exp2+=29;
            modEXP(exp2);
            break;
        case 1:
            exp2+=45;
            modEXP(exp2);
            break;
        case 2:
            exp2+=75;
            modEXP(exp2);
            break;
        case 3:
            exp2+=149;
            modEXP(exp2);
            break;
       }

        int D = e1*3 + exp1*7;

        if(D%2==0){
            exp1 = ceil( (float)exp1 + D*1.0 /200 );
            modEXP(exp1);
        }
        else{
            exp1 = ceil( (float)exp1 - D*1.0 /100 );
            modEXP(exp1);
        }
    }
    else{
        if(e1>=4 && e1<=19){
            exp2 = ceil( (float)exp2 + e1*1.0/4 + 19);
            modEXP(exp2);
        }
        else if(e1>=20 && e1<=49){
            exp2 = ceil( (float)exp2 + e1*1.0/9 + 21);
            modEXP(exp2);
        }
        else if(e1>=50 && e1<=65){
            exp2 = ceil( (float)exp2 + e1*1.0/16 + 17);
            modEXP(exp2);
        }
        else if(e1>=66 && e1<=79){
            exp2 = ceil( (float)exp2 + e1*1.0/4 + 19);
            modEXP(exp2);
            if(exp2>200){
                 exp2 = ceil( (float)exp2 + e1*1.0/9 + 21);
                 modEXP(exp2);
            }
        }
        else{
            exp2 = ceil( (float)exp2 + e1*1.0/4 + 19);
            modEXP(exp2);
            exp2 = ceil( (float)exp2 + e1*1.0/9 + 21);
            modEXP(exp2);
            if(exp2>400){
                exp2 = ceil( (float)exp2 + e1*1.0/16 + 17);
                modEXP(exp2);
                exp2 = ceil( (float)exp2*115/100);
                modEXP(exp2);
            }
        }
    exp1 -= e1;
    modEXP(exp1);
    }
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if( E2<0 || E2>99)
        return -99;   
   
    float P1=0,
          P2=0, 
          P3=0;

    // ROAD 1
    int S1 = round ( sqrt(EXP1) );
    S1 *= S1;
    if(EXP1>=S1)
        P1 = 1;
    else    
        P1 = ( (float) EXP1/S1 + 80) *1.0  / 123;

    // ROAD 2
    // E2 is even
    if(E2%2==0){
        while(M1!=0){
            //Event 1
            if(HP1<200){
                HP1 = ceil( (float) HP1*130/100 );
                modHP(HP1);
                M1-=150;
                modM(M1);
                if(M1==0)
                    break;
            }
            else{
                HP1 = ceil( (float) HP1*110/100 );
                modHP(HP1);
                M1-=70;
                modM(M1);
                if(M1==0)
                    break;
            }

            //Event 2
            if(EXP1<400){
                EXP1 = ceil( (float)EXP1*113/100 );
                modEXP(EXP1);
                M1-=200;
                modM(M1);
                if(M1==0)
                    break;
            }
            else{
                EXP1 = ceil( (float)EXP1*113/100 );
                modEXP(EXP1);
                M1-=120;
                modM(M1);
                if(M1==0)
                    break;
            }

            //Event 3
            if(EXP1<300){
                EXP1 = ceil( (float)EXP1*90/100 );
                modEXP(EXP1);
                M1-=100;
                modM(M1);
                if(M1==0)
                    break;
            }
            else{
                EXP1 = ceil( (float)EXP1*90/100 );
                modEXP(EXP1);
                M1-=120;
                modM(M1);
                if(M1==0)
                    break;
            }
            break;
        }

        HP1 = ceil( (float) HP1*83/100 );
        modHP(HP1);
        EXP1 = ceil( (float)EXP1*117/100 );
        modEXP(EXP1);

        int S2 = round ( sqrt(EXP1) );
        S2 *= S2;
        if(EXP1>=S2)
            P2 = 1;
        else    
            P2 = ( (float) EXP1/S2 + 80)*1.0/ 123;
    }

    // E2 is odd
    else{
        float paidMoney = 0;
        float breakMoney =  (float) M1*0.5;

        while(paidMoney<breakMoney){
            //Event 1
            if(HP1<200){
                HP1 = ceil( (float) HP1*130/100 );
                modHP(HP1);
                M1-=150;
                modM(M1);
                paidMoney+=150;
                if(paidMoney>breakMoney)
                    break;
            }
            else{
                HP1 = ceil( (float) HP1*110/100 );
                modHP(HP1);
                M1-=70;
                modM(M1);
                paidMoney+=70;
                if(paidMoney>breakMoney)
                    break;
            }

            //Event 2
            if(EXP1<400){
                EXP1 = ceil( (float)EXP1*113/100 );
                modEXP(EXP1);
                M1-=200;
                modM(M1);
                paidMoney+=200;
                if(paidMoney>breakMoney)
                    break;
            }
            else{
                EXP1 = ceil( (float)EXP1*113/100 );
                modEXP(EXP1);
                M1-=120;
                modM(M1);
                paidMoney+=120;
                if(paidMoney>breakMoney)
                    break;
            }

            //Event 3
            if(EXP1<300){
                EXP1 = ceil( (float)EXP1*90/100 );
                modEXP(EXP1);
                M1-=100;
                modM(M1);
                paidMoney+=100;
                if(paidMoney>breakMoney)
                    break;
            }
            else{
                EXP1 = ceil( (float)EXP1*90/100 );
                modEXP(EXP1);
                M1-=120;
                modM(M1);
                paidMoney+=120;
                if(paidMoney>breakMoney)
                    break;
            }
        }

        HP1 = ceil( (float) HP1*83/100 );
        modHP(HP1);
        EXP1 = ceil( (float)EXP1*117/100 );
        modEXP(EXP1);

        int S = round ( sqrt(EXP1) );
        S *= S;
        if(EXP1>=S)
            P2 = 1;
        else    
            P2 = ( (float) EXP1/S + 80)*1.0 / 123;
    }

    // ROAD 3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2>=0 && E2<10){
        P3 = (float) P[E2] / 100 ;
    } 
    else{
        int sum = E2/10 + E2%10;
        int i = sum%10;
        P3 = (float) P[i] / 100 ;
    }
    
    // Complete 3 road
    float avg = (P1+P2+P3)/3;
    if(avg==1){
        EXP1 = ceil( (float)EXP1*75/100 );
        modEXP(EXP1);
    }
    else if(avg<0.5){
        HP1 = ceil( (float) HP1*85/100 );
        modHP(HP1);
        EXP1 = ceil( (float)EXP1*115/100 );
        modEXP(EXP1);
    }
    else if(avg>=0.5){
        HP1 = ceil( (float) HP1*90/100 );
        modHP(HP1);
        EXP1 = ceil( (float)EXP1*120/100 );
        modEXP(EXP1);
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if( E3<0 || E3>99)
        return -99;   

    // Score of the taxi
    int scoreTaxi[10][10] = {0};
    for(int i=0; i<10; ++i){
        for(int j=0; j<10; ++j){
            scoreTaxi[i][j] = ( (E3*j) + (i*2) ) * (i-j);
        }
    }

    // Find meeting point
    int count_iMeet = 0,
        count_jMeet = 0,
        iMeet = 0,
        jMeet = 0;
    for(int i=0; i<10; ++i){
        for(int j=0; j<10; ++j){
           if(scoreTaxi[i][j]>(E3*2)){
            count_iMeet+=1;
           }
           if(scoreTaxi[i][j]<(0-E3)){
            count_jMeet+=1;
           }
        }
    }

    if(count_iMeet<10){
        iMeet = count_iMeet;
    }
    else{
        while(count_iMeet>=10){
            count_iMeet = count_iMeet/10 + count_iMeet%10;
        }
        iMeet = count_iMeet;
    }
    if(count_jMeet<10){
        jMeet = count_jMeet;
    }
    else{
        while(count_jMeet>=10){
            count_jMeet = count_jMeet/10 + count_jMeet%10;
        }
        jMeet = count_jMeet;
    }
    
    // Find S and W score at meeting point
    int scoreSW = scoreTaxi[iMeet][jMeet],
        x = iMeet,
        y = jMeet;
    
        // Left diagonal
    while( (x>=0 && x<=9) && (y>=0 && y<=9) ){
        if(scoreTaxi[x][y]>scoreSW)
            scoreSW=scoreTaxi[x][y];
            x+=1;
            y+=1; 
    }
    x = iMeet;
    y = jMeet;
    while( (x>=0 && x<=9) && (y>=0 && y<=9) ){
        if(scoreTaxi[x][y]>scoreSW)
            scoreSW=scoreTaxi[x][y];
            x-=1;
            y-=1; 
    }
    x = iMeet;
    y = jMeet;

        // Right diagonal
    while( (x>=0 && x<=9) && (y>=0 && y<=9) ){
        if(scoreTaxi[x][y]>scoreSW)
            scoreSW=scoreTaxi[x][y];
            x+=1;
            y-=1; 
    }
    x = iMeet;
    y = jMeet;
    while( (x>=0 && x<=9) && (y>=0 && y<=9) ){
        if(scoreTaxi[x][y]>scoreSW)
            scoreSW=scoreTaxi[x][y];
            x-=1;
            y+=1; 
    }

    if(scoreSW<0)
        scoreSW = abs(scoreSW);

    // Check if S and W can catch the taxi
    if( abs(scoreTaxi[iMeet][jMeet]) > scoreSW ){
        EXP1 = ceil( (float)EXP1*88/100 );
        modEXP(EXP1);
        EXP2 = ceil( (float)EXP2*88/100 );
        modEXP(EXP2);

        HP1 = ceil( (float) HP1*90/100 );
        modHP(HP1);
        HP2 = ceil( (float) HP2*90/100 );
        modHP(HP2);
    }
    else{
        EXP1 = ceil( (float)EXP1*112/100 );
        modEXP(EXP1);
        EXP2 = ceil( (float)EXP2*112/100 );
        modEXP(EXP2);
        
        HP1 = ceil( (float)HP1*110/100 );
        modHP(HP1);
        HP2 = ceil( (float)HP2*110/100 );
        modHP(HP2);
    }
    
    return ( abs(scoreSW)>=abs(scoreTaxi[iMeet][jMeet]) ? scoreSW : scoreTaxi[iMeet][jMeet] );
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    // Convert all the char into string
    string password = s;
    string mail = email;
    string se;

    // Find string se
    int pos = mail.find('@');
    se = mail.substr(0, pos);

    // Check if password contains more than 2 consecutive and identical characters
    int check1 = 0,
        checkIndex1 = 0;
    for(int i=0; i<password.length(); ++i){
        if( (password[i]==password[i+1]) && (password[i+1]==password[i+2]) ){
            check1 = 1;
            checkIndex1 = i;
            break;
        }
    }

    // Check if password contains invalid character
    int check2 = 0,
        checkIndex2 = 0;
    for(int i=0; i<password.length(); ++i){
       if(!((password[i]=='@') || (password[i]=='#') || (password[i]=='%') || (password[i]=='$') || (password[i]=='!') || (password[i]>='0' && password[i]<='9') || (password[i]>='a' && password[i]<='z') || (password[i]>='A' && password[i]<='Z')) ){
            check2 = 1;
            checkIndex2 = i;
            break;
       }
    }

    // Check valid password
    if(password.length()<8)
        return -1;
    else if(password.length()>20)
        return -2;
    else if(password.find(se)!=-1)
        return -(300 + password.find(se));
    else if(check1==1)
        return -(400+checkIndex1);
    else if( (password.find('@')==-1) && (password.find('#')==-1) && (password.find('%')==-1) && (password.find('$')==-1) && (password.find('!')==-1) )
        return -5;
    else if(check2==1)
        return checkIndex2;
    else 
        return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int resultIndex = 0;

    // Dynamic allocation
    int *countPass = new int[num_pwds];

    // Assume one password appears 1 time
    for(int i = 0; i < num_pwds; ++i) {
        countPass[i] = 1;
    }
    // Count how many times one password appears
    for(int i = 0; i < num_pwds; ++i) {
        if(countPass[i] == 0)
            continue;
        for(int j = i + 1; j < num_pwds; ++j) {
            if(strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                ++countPass[i];
                countPass[j] = 0;
            }
        }
    }
    // Variable to save most-time-appeared password and its index
    int mostAppear = -1;
    for(int i = 0; i < num_pwds; ++i) {
        if(countPass[i] > mostAppear) {
            mostAppear = countPass[i];
            resultIndex = i;
        }
    }

    // Loop to compare length if there are more than 1 valid passwords
    // Update index of the longer
    for(int i = 0; i < num_pwds; ++i) {
        if(countPass[i] == mostAppear && strlen(arr_pwds[i]) > strlen(arr_pwds[resultIndex])) {
            resultIndex = i;
        }
    }

    // Free-up memory after using count;
    delete[] countPass;

    return resultIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////