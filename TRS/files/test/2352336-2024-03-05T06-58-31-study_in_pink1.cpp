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

void checkHP(int & hp){
    if(hp<0)
        hp=0;
    if(hp>666)
        hp=666;
}

void checkEXP(int & exp){
    if(exp<0)
        exp=0;
    if(exp>600)
        exp=600;
}

void checkM(int & m){
    if(m<0)
        m=0;
    if(m>3000)
        m=3000;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

    if(e1 <0 || e1 >99){
        return -99;
    }

    checkEXP(exp1);
    checkEXP(exp2);

    if(e1 >= 0 && e1 <= 3)
    {
        if(e1 == 0)
            exp2+=29;
        else if(e1 == 1)
            exp2+=45;            
        else if(e1 == 2)
            exp2+=75;
        else if(e1 == 3)
            exp2+=149;

        checkEXP(exp2);

        int D = e1*3 + exp1*7;
        if(D%2 == 0){
            exp1 = ceil(float(exp1 + D/200.0));
        } else {
            exp1 = ceil(float(exp1 - D/100.0));
        }

        checkEXP(exp1);
    } else if(e1 >= 4 && e1 <= 99){
        if(e1 >= 4 && e1 <= 19){
            exp2 = ceil(float(exp2 + e1/4.0 + 19));
        } else if(e1 >= 20 && e1 <= 49){
            exp2 = ceil(float(exp2 + e1/9.0 + 21));
        } else if(e1 >= 50 && e1 <= 65){
            exp2 = ceil(float(exp2 + e1/16.0 + 17));
        } else if(e1 >= 66 && e1 <= 79){
            exp2 = ceil(float(exp2 + e1/4.0 + 19));
            if(exp2 > 200){
                exp2 = ceil(float(exp2 + e1/9.0 + 21));
            }
        } else if(e1 >= 80 && e1 <= 99){
            exp2 = ceil(float(exp2 + e1/4.0 + 19));
            exp2 = ceil(float(exp2 + e1/9.0 + 21));
            if(exp2 > 400){
                exp2 = ceil(float(exp2 + e1/16.0 + 17));
                exp2 = ceil(float(exp2 + exp2*15/100.0));
            }
        } 

        checkEXP(exp2);

        exp1 -= e1;

        checkEXP(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    if(E2 <0 || E2 >99){
        return -99;
    }
        

    checkHP(HP1);
    checkEXP(EXP1);
    checkM(M1);

    double P1, P2, P3;

    //Official

    //Path 1
    int a = floor(float(sqrt(EXP1)));
    int S1 = a*a;
    int S2 = (a+1)*(a+1);
    int S;

    if((EXP1 - S1) < (S2 - EXP1)){
           S = S1;
        } else {
            S = S2;
        }

        if(EXP1 >= S){
            P1 = 100.0;
        } else {
            P1 = (float(EXP1/S) + 80)/123.0*100.0;
    }

    //Path 2


    //Odd case
    if(E2%2 == 1 && M1 != 0){
        int M_initial = M1;
        int moneyPaid = 0;

        while(true){

            //Event 1
            if(HP1 < 200){
            HP1 = ceil(float(HP1*130/100.0));
            M1 -= 150;
            checkHP(HP1);
            checkM(M1);
            moneyPaid += 150;
            } else {
            HP1 = ceil(float(HP1*110/100.0));
            M1 -= 70;
            checkHP(HP1);
            checkM(M1);
            moneyPaid += 70;
            }

            if(moneyPaid > M_initial/2.0){
                break;
            }
        



            //Event 2
        if(EXP1 < 400){
            M1 -= 200;
            checkM(M1);
            moneyPaid += 200;
        } else {
            M1 -= 120;
            checkM(M1);
            moneyPaid += 120;
        }
        

        EXP1 = ceil(float(EXP1*113/100.0));
        checkEXP(EXP1);
        if(moneyPaid > M_initial/2.0){
                break;
            }



            //Event 3
        if(EXP1 < 300){
            M1 -= 100;
            checkM(M1);
            moneyPaid += 100;
        } else {
            M1 -= 120;
            checkM(M1);
            moneyPaid += 120;            
        }
        
        EXP1 = ceil(float(EXP1*90/100.0));
        checkEXP(EXP1);

        if(moneyPaid > M_initial/2.0){
            break;
        }


        } //Finish events
    }

    //Even case
    
    if(E2%2 == 0 && M1 != 0){
        bool run = true;
        while(run){
        //Event 1
        if(HP1 < 200){
            HP1 = ceil(float(HP1*130/100.0));
            M1 -= 150;
        } else {
            HP1 = ceil(float(HP1*110/100.0));
            M1 -= 70;
        }
        checkHP(HP1);
        checkM(M1);
        if(M1 == 0)
            break;


        //Event 2
        if(EXP1 < 400){
            M1 -= 200;
        } else {
            M1 -= 120;
        }
        checkM(M1);

        EXP1 = ceil(float(EXP1*113/100.0));
        checkEXP(EXP1);
        if(M1 == 0)
            break;


        //Event 3
        if(EXP1 < 300){
            M1 -= 100;
        } else {
            M1 -= 120;
        }
        checkM(M1);
        EXP1 = ceil(float(EXP1*90/100.0));
        checkEXP(EXP1);

        run = false;

        }
    }

    HP1 = ceil(float(HP1*83/100.0));
    EXP1 = ceil(float(EXP1*117/100.0));
    checkHP(HP1);
    checkEXP(EXP1);

    //Find P2
    a = floor(float(sqrt(EXP1)));
    S1 = a*a;
    S2 = (a+1)*(a+1);

    if((EXP1 - S1) < (S2 - EXP1)){
           S = S1;
        } else {
            S = S2;
        }

        if(EXP1 >= S){
            P2 = 100.0;
        } else {
            P2 = (float(EXP1/S) + 80)/123.0*100.0;
    }

    //Path 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2 >= 0 && E2 <= 9)
        P3 = P[E2];
    else{
        int firstDigit = E2/10;
        int secondDigit = E2%10;
        P3 = P[(firstDigit + secondDigit)%10];
    }


    //Last step
    if(P1 == 100 && P2 == 100 && P3 == 100){
        EXP1 = ceil(float(EXP1*75/100.0));
        checkEXP(EXP1);

        return HP1 + EXP1 + M1;
    }
    
    double P_avg = (P1 + P2 +P3)/3.0;
    if(P_avg < 50){
        HP1 = ceil(float(HP1*85/100.0));
        EXP1 = ceil(float(EXP1*115/100.0));
    } else {
        HP1 = ceil(float(HP1*90/100.0));
        EXP1 = ceil(float(EXP1*120/100.0));
    }
    checkHP(HP1);
    checkEXP(EXP1);
    

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

    if(E3 <0 || E3 >99){
        return -99;
    }

    checkHP(HP1);
    checkEXP(EXP1);
    checkHP(HP2);
    checkEXP(EXP2);

    //Initialize
    int Taxi[10][10];
    int Sherlock[10][10];
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            Taxi[i][j] = 0;
        }
    }

    //Calculate Taxi
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            Taxi[i][j] = ((E3*j) + (i*2))*(i-j);
        }
    }

    //Calculate Sherlock
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){

            int firstPoint_x = j;
            int firstPoint_y = i;

            int max = Taxi[firstPoint_y][firstPoint_x];
            while(firstPoint_x >=0 && firstPoint_x <= 9 && firstPoint_y >=0 && firstPoint_y <= 9){
                if(Taxi[firstPoint_y][firstPoint_x] > max){
                    max = Taxi[firstPoint_y][firstPoint_x];
                }
                firstPoint_x++;
                firstPoint_y++;
            }

            firstPoint_x = j;
            firstPoint_y = i;

            while(firstPoint_x >=0 && firstPoint_x <= 9 && firstPoint_y >=0 && firstPoint_y <= 9){
                if(Taxi[firstPoint_y][firstPoint_x] > max){
                    max = Taxi[firstPoint_y][firstPoint_x];
                }
                firstPoint_x++;
                firstPoint_y--;
            }

            firstPoint_x = j;
            firstPoint_y = i;

            while(firstPoint_x >=0 && firstPoint_x <= 9 && firstPoint_y >=0 && firstPoint_y <= 9){
                if(Taxi[firstPoint_y][firstPoint_x] > max){
                    max = Taxi[firstPoint_y][firstPoint_x];
                }
                firstPoint_x--;
                firstPoint_y++;
            }

            firstPoint_x = j;
            firstPoint_y = i;

            while(firstPoint_x >=0 && firstPoint_x <= 9 && firstPoint_y >=0 && firstPoint_y <= 9){
                if(Taxi[firstPoint_y][firstPoint_x] > max){
                    max = Taxi[firstPoint_y][firstPoint_x];
                }
                firstPoint_x--;
                firstPoint_y--;
            }           
            Sherlock[i][j] = abs(max);        
        }
    }

    //Meeitng point
    int meetingI = 0;
    int meetingJ = 0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(Taxi[i][j] > (E3*2)){
                meetingI++;
            }
            if(Taxi[i][j] < (E3*(-1))){
                meetingJ++;
            }
        }
    }

    if(meetingI == 100){
        meetingI = 1;
    }

    if(meetingJ == 100){
        meetingJ = 1;
    }
    
    while(meetingI >= 10 && meetingI <= 99){
        meetingI = meetingI%10 + meetingI/10;
    }

    while(meetingJ >= 10 && meetingJ <= 99){
        meetingJ = meetingJ%10 + meetingJ/10;
    }

    bool chased;
    if(abs(Taxi[meetingI][meetingJ]) > Sherlock[meetingI][meetingJ]){
        chased = false;
    } else {
        chased = true;
    }

    if(chased){
        EXP1 = ceil(float(EXP1*112.0/100.0));
        HP1 = ceil(float(HP1*110.0/100.0));
        EXP2 = ceil(float(EXP2*112.0/100.0));
        HP2 = ceil(float(HP2*110.0/100.0));
    } else {
        EXP1 = ceil(float(EXP1*88.0/100.0));
        HP1 = ceil(float(HP1*90.0/100.0));
        EXP2 = ceil(float(EXP2*88.0/100.0));
        HP2 = ceil(float(HP2*90.0/100.0));
    }

    checkEXP(EXP1);
        checkHP(HP1);
        checkEXP(EXP2);
        checkHP(HP2);

    if(abs(Taxi[meetingI][meetingJ]) > Sherlock[meetingI][meetingJ]){
        return Taxi[meetingI][meetingJ];
    } else {
        return Sherlock[meetingI][meetingJ];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    string passwordStr = s;
    string emailStr = email;
    if(passwordStr.length() < 8){
        return -1;
    }
    if(passwordStr.length() > 20){
        return -2;
    }

    size_t seLenght = emailStr.find('@');
    string se = emailStr.substr(0, seLenght);

    size_t indexSe = passwordStr.find(se);
    if(indexSe != string::npos){
        int result = -(300 + int(indexSe));
        return result;
    }
    
    int i = 0;
    while(i <= (passwordStr.length() - 3)){
        if(passwordStr.at(i) == passwordStr.at(i+1) && passwordStr.at(i+1)  == passwordStr.at(i+2)){
            int result = -(400 + i);
            return result;
        } 
        i++;
    }

    bool containSpecial = false;
    for(int i = 0; i < passwordStr.length(); i++){
        if(passwordStr.at(i) == '@' ||
            passwordStr.at(i) == '#' ||
            passwordStr.at(i) == '%' ||
            passwordStr.at(i) == '$' ||
            passwordStr.at(i) == '!')
            containSpecial = true;
    }
    if(!containSpecial)
        return -5;
    
    for(int i = 0; i < passwordStr.length(); i++){
        if(!((passwordStr.at(i) >= 'a' && passwordStr.at(i) <= 'z') ||
            (passwordStr.at(i) >= 'A' && passwordStr.at(i) <= 'Z') ||
            (passwordStr.at(i) >= '0' && passwordStr.at(i) <= '9') ||
            passwordStr.at(i) == '@' ||
            passwordStr.at(i) == '#' ||
            passwordStr.at(i) == '%' ||
            passwordStr.at(i) == '$' ||
            passwordStr.at(i) == '!'))
            return i;
    }

    
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    string passArray[30];
    int frequencyArray[30];
    int firstIndex[30];
    for(int i=0; i<30; i++){
        passArray[i]="";
    }
    string tempString;
    tempString = arr_pwds[0];
    passArray[0] = tempString;
    frequencyArray[0] = 1;
    firstIndex[0] = 0;
    int possiblePass = 0;

    for(int i=1; i < num_pwds; i++){
        tempString = arr_pwds[i];
        bool appear = false;
        for(int j=0; j <= possiblePass; j++){
            if(tempString == passArray[j]){
                frequencyArray[j]++;
                appear = true;
                break;
            }
        }
        if(appear == false){
            possiblePass++;
            passArray[possiblePass] = tempString;
            frequencyArray[possiblePass] = 1;
            firstIndex[possiblePass] = i;
        }        
    }

    int maxIndex = 0;
    for(int i=0; i<=possiblePass; i++){
        if(frequencyArray[i] > frequencyArray[maxIndex]){
            maxIndex = i;
        } else if(frequencyArray[i] == frequencyArray[maxIndex] && passArray[i].length()>passArray[maxIndex].length()){
            maxIndex = i;
        }
    }

    return firstIndex[maxIndex];
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////