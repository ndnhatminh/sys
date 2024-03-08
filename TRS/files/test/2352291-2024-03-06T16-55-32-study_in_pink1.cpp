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
    if(e1 < 0 || e1 > 99){
        return -99;
    }

    if(exp1 > 600){exp1 = 600;}else if(exp1 < 0){exp1 = 0;}
    if(exp2 > 600){exp2 = 600;}else if(exp2 < 0){exp2 = 0;}

    if(0 <= e1 && e1 <= 3){//[0,3]
        switch(e1){
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
            exp2 += (29 + 45 + 75);
            break;
        }
        if(exp2 > 600){exp2 = 600;}else if(exp2 < 0){exp2 = 0;}

        int D = e1*3 + exp1*7;
        if(D % 2 == 0){
            exp1 = ceil(exp1 + (D*1.0)/200);
            if(exp1 > 600){exp1 = 600;}else if(exp1 < 0){exp1 = 0;}
        }else{
            exp1 = ceil(exp1 - (D*1.0)/100);
            if(exp1 > 600){exp1 = 600;}else if(exp1 < 0){exp1 = 0;}
        }
    }else{//[4,99]
        if(4 <= e1 && e1 <= 19){
            exp2 = ceil(exp2 + (e1*1.0)/4 + 19);
            if(exp2 > 600){exp2 = 600;}else if(exp2 < 0){exp2 = 0;}
        }else if(20 <= e1 && e1 <= 49){
            exp2 = ceil(exp2 + (e1*1.0)/9 + 21);
            if(exp2 > 600){exp2 = 600;}else if(exp2 < 0){exp2 = 0;}
        }else if(50 <= e1 && e1 <= 65){
            exp2 = ceil(exp2 + (e1*1.0)/16 + 17);
            if(exp2 > 600){exp2 = 600;}else if(exp2 < 0){exp2 = 0;}
        }else if(66 <= e1 && e1 <= 79){
            exp2 = ceil(exp2 + (e1*1.0)/4 + 19);
            if(exp2 > 600){exp2 = 600;}else if(exp2 < 0){exp2 = 0;}
            if(exp2 > 200){
            exp2 = ceil(exp2 + (e1*1.0)/9 + 21);
            if(exp2 > 600){exp2 = 600;}else if(exp2 < 0){exp2 = 0;}
            }
        }else if(80 <= e1 && e1 <= 99){
            exp2 = ceil(exp2 + (e1*1.0)/4 + 19);
            if(exp2 > 600){exp2 = 600;}else if(exp2 < 0){exp2 = 0;}
            exp2 = ceil(exp2 + (e1*1.0)/9 + 21);
            if(exp2 > 600){exp2 = 600;}else if(exp2 < 0){exp2 = 0;}
            if(exp2 > 400){
            exp2 = ceil(exp2 + (e1*1.0)/16 + 17);
            if(exp2 > 600){exp2 = 600;}else if(exp2 < 0){exp2 = 0;}
            exp2 = ceil(exp2 * 1.15);
            if(exp2 > 600){exp2 = 600;}else if(exp2 < 0){exp2 = 0;}
            }
        }
            
        exp1 -= e1;
        if(exp1 > 600){exp1 = 600;}else if(exp1 < 0){exp1 = 0;}
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(E2 < 0 || E2 > 99){
        return -99;
    }

    if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
    if(HP1 > 666){HP1 = 666;}else if(HP1 < 0){HP1 = 0;}
    if(M1 > 3000){M1 = 3000;}else if(M1 < 0){M1 = 0;}

    double P1,P2,P3;
    int S;//nearest sqrt

    //Road 1
    bool sqrtup1 = false;
    bool sqrtdown1 = false;
    int a;
    int up = 0;
    int down = 0;
    int temp = EXP1;
    
    while(sqrtup1 == false){
        if(temp >= 0){
        a = sqrt(temp);
        if(a * a == temp){
            sqrtup1 = true;
        }else{temp += 1; up += 1;} 
        if(temp > 600){up = 1000; break;}
        } 
    }
    temp = EXP1;
    while(sqrtdown1 == false){
        if(temp >= 0){
        a = sqrt(temp);
        if(a * a == temp){
            sqrtdown1 = true;
        }else{temp -= 1; down += 1;}
        if(temp < 0){down = 1000; break;} 
        } 
    }
    
    if(up < down){//Road1 %
        S = EXP1 + up;
        P1 = ((double)EXP1/(double)S + 80)/123;
    }else if(up > down || up == down){P1 = 1;}

    //Road 2
    if(E2 % 2 == 0){//E2 is an even number
        if(M1 != 0){//Check the budget before moving to action1
            if(HP1 < 200){//action1
                HP1 = ceil(HP1 * 1.3);
                if(HP1 > 666){HP1 = 666;}else if(HP1 < 0){HP1 = 0;}
                M1 -= 150;
                if(M1 > 3000){M1 = 3000;}else if(M1 < 0){M1 = 0;}
                }else{
                HP1 = ceil((float)(HP1 * 1.1));
                if(HP1 > 666){HP1 = 666;}else if(HP1 < 0){HP1 = 0;}
                M1 -= 70;
                if(M1 > 3000){M1 = 3000;}else if(M1 < 0){M1 = 0;}
            }
            if(M1 != 0){//Check the budget before moving to action2
                if(EXP1 < 400){//action2
                M1 -= 200;
                if(M1 > 3000){M1 = 3000;}else if(M1 < 0){M1 = 0;}
                EXP1 = ceil(EXP1 * 1.13);
                if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
                }else{
                M1 -= 120;
                if(M1 > 3000){M1 = 3000;}else if(M1 < 0){M1 = 0;}
                EXP1 = ceil(EXP1 * 1.13);
                if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
                }
                if(M1 != 0){//Check the budget before moving to action3
                    if(EXP1 < 300){//action3
                    M1 -= 100;
                    if(M1 > 3000){M1 = 3000;}else if(M1 < 0){M1 = 0;}
                    EXP1 = ceil(EXP1 * 0.9);
                    if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
                    }else{
                    M1 -= 120;
                    if(M1 > 3000){M1 = 3000;}else if(M1 < 0){M1 = 0;}
                    EXP1 = ceil(EXP1 * 0.9);
                    if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
                    }
                    HP1 = ceil(HP1 * 0.83);
                    if(HP1 > 666){HP1 = 666;}else if(HP1 < 0){HP1 = 0;}
                    EXP1 = ceil(EXP1 * 1.17);
                    if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
                }else{
                HP1 = ceil(HP1 * 0.83);
                if(HP1 > 666){HP1 = 666;}else if(HP1 < 0){HP1 = 0;}
                EXP1 = ceil(EXP1 * 1.17);
                if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
                }
            }else{
            HP1 = ceil(HP1 * 0.83);
            if(HP1 > 666){HP1 = 666;}else if(HP1 < 0){HP1 = 0;}
            EXP1 = ceil(EXP1 * 1.17);
            if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
            }
        }else{
        HP1 = ceil(HP1 * 0.83);
        if(HP1 > 666){HP1 = 666;}else if(HP1 < 0){HP1 = 0;}
        EXP1 = ceil(EXP1 * 1.17);
        if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
        }
    }else{//E2 is an odd number
    if(M1 != 0){
        int sumM = 0;
        double halfM = (double)M1/2;
        while(sumM <= halfM){
            if(HP1 < 200){//action1
                HP1 = ceil(HP1 * 1.3);
                if(HP1 > 666){HP1 = 666;}else if(HP1 < 0){HP1 = 0;}
                M1 -= 150;
                if(M1 > 3000){M1 = 3000;}else if(M1 < 0){M1 = 0;}
                sumM += 150;
                if(sumM > halfM)break;
            }else{
                HP1 = ceil((float)(HP1 * 1.1));
                if(HP1 > 666){HP1 = 666;}else if(HP1 < 0){HP1 = 0;}
                M1 -= 70;
                if(M1 > 3000){M1 = 3000;}else if(M1 < 0){M1 = 0;}
                sumM += 70;
                if(sumM > halfM)break;
            }
            if(EXP1 < 400){//action2
                M1 -= 200;
                if(M1 > 3000){M1 = 3000;}else if(M1 < 0){M1 = 0;}
                sumM += 200;
                EXP1 = ceil(EXP1 * 1.13);
                if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
                if(sumM > halfM)break;
            }else{
                M1 -= 120;
                if(M1 > 3000){M1 = 3000;}else if(M1 < 0){M1 = 0;}
                sumM += 120;
                EXP1 = ceil(EXP1 * 1.13);
                if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
                if(sumM > halfM)break;
            }
            if(EXP1 < 300){//action3
                M1 -= 100;
                if(M1 > 3000){M1 = 3000;}else if(M1 < 0){M1 = 0;}
                sumM += 100;
                EXP1 = ceil(EXP1 * 0.9);
                if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
                if(sumM > halfM)break;
            }else{
                M1 -= 120;
                if(M1 > 3000){M1 = 3000;}else if(M1 < 0){M1 = 0;}
                sumM += 120;
                EXP1 = ceil(EXP1 * 0.9);
                if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
                if(sumM > halfM)break;
            } 
        }
        HP1 = ceil(HP1 * 0.83);
        if(HP1 > 666){HP1 = 666;}else if(HP1 < 0){HP1 = 0;}
        EXP1 = ceil(EXP1 * 1.17);
        if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
    }else{
        HP1 = ceil(HP1 * 0.83);
        if(HP1 > 666){HP1 = 666;}else if(HP1 < 0){HP1 = 0;}
        EXP1 = ceil(EXP1 * 1.17);
        if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
    }
    }
    bool sqrtup2 = false;
    bool sqrtdown2 = false;
    temp = EXP1;
    up = 0; down = 0;
    while(sqrtup2 == false){
        if(temp >= 0){
        a = sqrt(temp);
        if(a * a == temp){
            sqrtup2 = true;
        }else{temp += 1; up += 1;}
        if(temp > 600){up = 1000; break;} 
        } 
    }
    temp = EXP1;
    while(sqrtdown2 == false){
        if(temp >= 0){
        a = sqrt(temp);
        if(a * a == temp){
            sqrtdown2 = true;
        }else{temp -= 1; down += 1;}
        if(temp < 0){down = 1000; break;} 
        } 
    }
    if(up < down){//Road2 %
        S = EXP1 + up;
        P2 = ((double)EXP1/(double)S + 80)/123;
    }else if(up > down || up == down){P2 = 1;}
    
    //Road3
    int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i,m,n,j;
    if(E2 - 10 < 0){
        i = E2;
    }else{
        m = E2 / 10;
        n = E2 % 10;
        j = m + n;
        if(j - 10 < 0){
            i = j;
        }else{i = j % 10;}
    }

    P3 = (double)P[i]/100;//Road3 %
    double finalP;
    if(P1 == 1 && P2 == 1 && P3 == 1){
        EXP1 = ceil(EXP1 * 0.75);
    }else{
        finalP = (P1 + P2 + P3)/3;
        if(finalP < 0.5){
            HP1 = ceil(HP1 * 0.85);
            if(HP1 > 666){HP1 = 666;}else if(HP1 < 0){HP1 = 0;}
            EXP1 = ceil(EXP1 * 1.15);
            if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
        }else{
            HP1 = ceil(HP1 * 0.9);
            if(HP1 > 666){HP1 = 666;}else if(HP1 < 0){HP1 = 0;}
            EXP1 = ceil(EXP1 * 1.2);
            if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(E3 < 0 || E3 > 99){
        return -99;
    }

    if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
    if(EXP2 > 600){EXP2 = 600;}else if(EXP2 < 0){EXP2 = 0;}
    if(HP1 > 666){HP1 = 666;}else if(HP1 < 0){HP1 = 0;}
    if(HP2 > 666){HP2 = 666;}else if(HP2 < 0){HP2 = 0;}

    int point[10][10];
    int taxipoint;
    int SandWpoint;
    int meetingi = 0;
    int meetingj = 0;
    int i,j;

    for(i = 0; i < 10; i++){//the matrix
        for(j = 0; j < 10; j++){
            point[i][j] = ((E3 * j) + (i * 2))*(i-j);
            if(point[i][j] > 0){
                if(point[i][j] > E3*2){
                    meetingi++;
                }
            }else if(point[i][j] < 0){
                if(point[i][j] < -E3){
                    meetingj++;
                }
            }
        }
    }
    
    int a,b;

    while(meetingi - 10 >= 0){
        a = meetingi / 10;
        b = meetingi % 10;
        meetingi = a + b;
    }
    i = meetingi;//i coordinate of the meeting point
    while(meetingj - 10 >= 0){
        a = meetingj / 10;
        b = meetingj % 10;
        meetingj = a + b;
    }
    j = meetingj;//j coordinate of the meeting point

    taxipoint = point[i][j];//taxi's point
    int abstaxi = abs(taxipoint);

    int max = point[i][j];

    while(i != 0 && j != 0){//largest value from left diagonal
        i--; j--;//go to top left
        if(max < point[i][j]){
            max = point[i][j];
        }
    }
    while(i != 9 && j != 9){
        i++; j++;//go to bottom right
        if(max < point[i][j]){
            max = point[i][j];
        }
    }
    i = meetingi; j = meetingj;//return the meeting point
    while(i != 0 && j != 9){//largest value from right diagonal
        i--; j++;//go to top right
        if(max < point[i][j]){
            max = point[i][j];
        }
    }
    while(i != 9 && j != 0){
        i++; j--;//go to bottom left
        if(max < point[i][j]){
            max = point[i][j];
        }
    }
    SandWpoint = max;//Sherlock and Watson's point

    if(abstaxi > SandWpoint){
        EXP1 = ceil(EXP1 * 0.88);
        if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
        EXP2 = ceil(EXP2 * 0.88);
        if(EXP2 > 600){EXP2 = 600;}else if(EXP2 < 0){EXP2 = 0;}
        HP1 = ceil(HP1 * 0.9);
        if(HP1 > 666){HP1 = 666;}else if(HP1 < 0){HP1 = 0;}
        HP2 = ceil(HP2 * 0.9);
        if(HP2 > 666){HP2 = 666;}else if(HP2 < 0){HP2 = 0;}
        return taxipoint;
    }else{
        EXP1 = ceil(EXP1 * 1.12);
        if(EXP1 > 600){EXP1 = 600;}else if(EXP1 < 0){EXP1 = 0;}
        EXP2 = ceil(EXP2 * 1.12);
        if(EXP2 > 600){EXP2 = 600;}else if(EXP2 < 0){EXP2 = 0;}
        HP1 = ceil((float)(HP1 * 1.1));
        if(HP1 > 666){HP1 = 666;}else if(HP1 < 0){HP1 = 0;}
        HP2 = ceil((float)(HP2 * 1.1));
        if(HP2 > 666){HP2 = 666;}else if(HP2 < 0){HP2 = 0;}
        return SandWpoint;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    int seLength = 0;

    for(int i = 0; i < 100; i++){
        if(email[i] == '@'){
            break;
        }else{
            seLength++;//Length of se
        }
    }
    
    int sLength = strlen(s);//length of the password (s)
    if(sLength < 8){return -1;}
    if(sLength > 20){return -2;}

    string se;
    string pass;
    
    for(int i = 0; i < seLength; i++){
        se.push_back(email[i]);
    }

    for(int j = 0; j < strlen(s); j++){
        pass.push_back(s[j]);
    }
    
    size_t findse = pass.find(se);
    if((findse != string::npos)){
        return -(300+findse);
    }

    for(int i = 0; i < sLength-2; i++){//more than 2 consecutive and identical characters
        if(s[i] == s[i+1] && s[i+1] == s[i+2]){
            return -(400 + i);
        }
    }
    
    bool containSChar = false;
    for(int i = 0; i < sLength; i++){
        if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'){
            containSChar = true;
        }
    }
    if(containSChar == false){
        return -5;
    }

    for(int o = 0; o < sLength; o++){
        if(s[o] == '^' || s[o] == '&' || s[o] == '*' || s[o] == '(' || s[o] == ')' || s[o] == '_' || s[o] == ';' || s[o] == ':' || s[o] == '<' || s[o] == '>' || s[o] == ',' || s[o] == '.' || s[o] == '?' || s[o] == '/' || s[o] == '"' || s[o] == '{' || s[o] == '}' || s[o] == '[' || s[o] == ']' || s[o] == '|' || s[o] == '`' || s[o] == '~' || s[o] == '+' || s[o] == '-' || s[o] == '*' || s[o] == ' '){
            return o;
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int numpwdscase = 0;//number of different pwds

    const int sizeappear = 30;
    int pwdsappear[sizeappear];//appear time of each different pwds
    fill(pwdsappear , pwdsappear + sizeappear, 0);

    const int sizelength = 30;
    int pwdslength[sizelength];//length of each different pwds
    fill(pwdslength , pwdslength + sizelength, 0);

    const int size1stappear = 30;
    int pwds1stappear[size1stappear];//frist appear of each different pwds
    fill(pwds1stappear , pwds1stappear + size1stappear, 0);

    int pwdsIndex = 0;
    bool checkdif = true;

    for(int i = 0; i < num_pwds; i++){
        for(int v = i-1; v >= 0; v--){
            if(arr_pwds[i] == arr_pwds[v]){//Check if the pwds already appeared
                checkdif = false;
            }
        }
        if(checkdif == true){
            pwdslength[pwdsIndex] = strlen(arr_pwds[i]);//length of new pwds
            pwds1stappear[pwdsIndex] = i;//frist appear of the new pwds
            for(int j = 0; j < num_pwds; j++){
                if(arr_pwds[i] == arr_pwds[j]){
                    pwdsappear[pwdsIndex]++;//count how many time the pwds appear
                }
            }
            pwdsIndex++;
            numpwdscase++;
        }
    }

    int maxappear = pwdsappear[0];
    int maxappearIndex = 0;
    for(int k = 0; k < numpwdscase; k++){
        if(maxappear < pwdsappear[k]){
            maxappear = pwdsappear[k];//find the most appear time
            maxappearIndex = k;//index of the pwds having the most appear time
        }
    }
    int maxappearCount = 0;
    for(int l = 0; l < numpwdscase; l++){
        if(pwdsappear[l] == maxappear){
            maxappearCount++;
        }
    }
    if(maxappearCount == 1){
        return pwds1stappear[maxappearIndex];
    }else{
        int pwdsLengthIndex[maxappearCount];
        int pwdsIndex2 = 0;
        for(int h = 0; h < numpwdscase; h++){
            if(pwdsappear[h] == maxappear){
                pwdsLengthIndex[pwdsIndex2] = h;
                pwdsIndex2++;
            }
        }
        int maxlength = pwdslength[pwdsLengthIndex[0]];
        int maxlengthIndex = pwdsLengthIndex[0];
        for(int f = 0; f < maxappearCount; f++){
            if(maxlength < pwdslength[pwdsLengthIndex[f]]){
                maxlength = pwdslength[pwdsLengthIndex[f]];
                maxlengthIndex = pwdsLengthIndex[f];
            }
        }
        int maxlengthCount = 0;
        for(int l = 0; l < maxappearCount; l++){
            if(pwdslength[pwdsLengthIndex[l]] == maxlength){
                maxlengthCount++;
            }
        }
        if(maxlengthCount == 1){
            return pwds1stappear[maxlengthIndex];
        }else{
            int pwdsIndexFinal[maxlengthCount];
            int pwdsIndex3 = 0;
            for(int g = 0; g < maxappearCount; g++){
                if(pwdslength[pwdsLengthIndex[g]] == maxlength){
                    pwdsIndexFinal[pwdsIndex3] = g;
                }
            }
            return pwds1stappear[pwdsLengthIndex[0]];
        }
    } 
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////