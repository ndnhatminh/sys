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
    if(e1 < 0 || e1 > 99){return -99;}
    exp1 = checkEXP(exp1);
    exp2 = checkEXP(exp2);
    //Sherlock deducting where Watson came from
    if (e1 >= 0 && e1 <=3 ){
        if (e1 == 0){
           exp2 = checkEXP(exp2 += 29);
        }
        else if (e1 == 1){
          exp2 = checkEXP(exp2 += 45);
        }
        else if (e1 == 2){
           exp2 = checkEXP(exp2 += 75);
        }
        else{
           exp2 = checkEXP(exp2 += 29 + 45 + 75);
        }
        int D = ceil(e1 * 3 + exp1 * 7);
        if (D % 2 == 0){
           exp1 = checkEXP(ceil(exp1 + (D/200.0)));
        }
        else {
           exp1 = checkEXP(ceil(exp1 - (D/100.0)));
        }
    }
    //Sherlock deducting Watson has a sibling
    if (e1 >= 4 && e1 <= 99){
        if (e1 >= 4 && e1 <= 19){
           exp2 = case21(exp2, e1);
        }
        else if (e1 >= 20 && e1 <= 49){
           exp2 = case22(exp2, e1);
        }
        else if (e1 >= 50 && e1 <= 65){
           exp2 = case23(exp2, e1);
        }
        else if (e1 >= 66 && e1 <= 79){
           exp2 = case21(exp2, e1);
            if (exp2 > 200){
               exp2 = case22(exp2, e1);
            }
        }
        else{
           exp2 = case21(exp2, e1);
           exp2 = case22(exp2, e1);
            if (exp2 > 400){
               exp2 = case23(exp2, e1);
               exp2 = checkEXP(exp2 = ceil(exp2 + exp2*0.15));
            }
        }
        exp1 = checkEXP(exp1 -= e1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 < 0 || E2 > 99){
        return -99;
        }
    HP1 = checkHP(HP1);
    EXP1 = checkEXP(EXP1);
    M1 = checkMONEY(M1);
    double P = 0, P1 = 0, P2 = 0, P3 = 0, P03[10]={32,47,28,79,100,50,22,83,64,11};
    //Road 1
    P1 = calculateProbability(EXP1);
    //Road 2
    
    if (M1>0) {events(HP1, EXP1, M1, E2);}
    HP1 = checkHP(ceil(HP1*0.83));
    EXP1 = checkEXP(ceil(EXP1 + EXP1*0.17));
    P2 = calculateProbability(EXP1);
    //Road 3
    int i = 0;
    if (E2 < 10){
        i = E2;
    }
    else {
        i = (E2 % 10) + (E2 / 10);
        i = i % 10;
    }
    P3 = P03[i];
    P = (P1 + P2 + P3) / 3.0;
    if (P == 100){
        EXP1 = checkEXP(ceil(EXP1 * 0.75));
    }
    else if (P < 50){
        HP1 = checkHP(ceil(HP1 * 0.85));
        EXP1 = checkEXP(ceil(EXP1 + EXP1*0.15));
    }
    else if (P >= 50){
        HP1 = checkHP(ceil(HP1 * 0.90));
        EXP1 = checkEXP(ceil(EXP1 + EXP1* 0.2));
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 < 0 || E3 > 99){
        return -99;
        }
    HP1 = checkHP(HP1);
    EXP1 = checkEXP(EXP1);
    HP2 = checkHP(HP2);
    EXP2 = checkEXP(EXP2);
    int i = 0, j = 0, a = 0, b = 0, max = 0;
    int matrix[10][10] = {0};
    //Calculate the taxi score and find i and j (the coordinate where Sherlock and Watson meet the taxi)
    for(a = 0; a < 10; a++){
        for (b = 0; b < 10; b++){
            matrix[a][b] = ((E3 * b) + (a * 2)) * (a - b);
            if(matrix[a][b] > (E3 * 2)){i++;}
            if(matrix[a][b] < -(E3)){j++;}
        }
    }
    //Sum of i and j if they are double digit
    while (i > 9){i = (i / 10) + (i % 10);}
    while (j > 9){j = (j / 10) + (j % 10);}
    //Diagonal checking
    a = i;
    b = j;
    while(a < 10 && b < 10){
            if (max < matrix[a][b]){max = matrix[a][b];}
            a++;
            b++;        
    }
    a = i;
    b = j;
    while(a > -1 && b > -1){
            if (max < matrix[a][b]){max = matrix[a][b];}
            a--;
            b--;
    }
    a = i;
    b = j;
    while(a < 10 && b > -1){
            if (max < matrix[a][b]){max = matrix[a][b];}
            a++;
            b--;
    }
    a = i;
    b = j;
    while(a > -1 && b < 10){
            if (max < matrix[a][b]){max = matrix[a][b];}
            a--;
            b++;
    }
    //Check whether Sherlock and Watson can catch the taxi or not
    if (abs(matrix[i][j]) <= max) {
    EXP1 = checkEXP(ceil(EXP1 + EXP1 * 0.12));
    EXP2 = checkEXP(ceil(EXP2 + EXP2 * 0.12));
    HP1 = checkHP(ceil(HP1 + HP1 * 0.1));
    HP2 = checkHP(ceil(HP2 + HP2 * 0.1));
    return max;
    } else {
    EXP1 = checkEXP(ceil(EXP1 * 0.88));
    EXP2 = checkEXP(ceil(EXP2 * 0.88));
    HP1 = checkHP(ceil(HP1 * 0.9));
    HP2 = checkHP(ceil(HP2 * 0.9));
    return matrix[i][j];
    }



}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    //Finding @
    const char *pos = strchr(email, '@');
    int length = pos - email;
    //Declaring se
    char se[length+1];
    strncpy(se, email, length);
    se[length] = '\0';
    //Checking the validity of the password
    //Length of the password
    int passwordlength = strlen(s);
    if (passwordlength < 8){
        return -1;
        }
    if (passwordlength > 20){
        return -2;
        }
    //Check if se is in s
    const char *sei_1 = strstr(s, se);
    if (sei_1 != nullptr){
        int position = sei_1 - s;
        return -(300+position);
    }
    //Check for consecutive identical characters
    int num_ident = 1, sei_2 =0;
    for (int i = 1; i < passwordlength; i++){
        if(s[i - 1] == s[i]){
            sei_2 = i - num_ident;
            num_ident++;
            if (num_ident >= 3){
                return -(400+sei_2);
            }
        }
        else num_ident = 1;
    }
    //Check if the password does not have special character
    const char special_character[] = "@#%$!";
    const char *findspecial = strpbrk(s,special_character);
    if (findspecial == nullptr){
        return -5;
        }
    //Character, digit and special character
    for (int i = 0; i < passwordlength; i++){
        char character = s[i];
        if (isalnum(character)){
            continue;
            }
        else if (character == '@' || character == '#' || character == '%' || character == '$' || character == '!'){
            continue;
            }
        else{
            return i;
            } //Return the position of the invalid character
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    const char * uniq_pwds[num_pwds];
    int uniq_num = 0;
    int freq[num_pwds] = {0};
    for (int i = 0; i < num_pwds; i++){
        bool is_uniq = true;
        //Increase the frequency if the password is not unique
         for (int j = 0; j < uniq_num; j++) {
            if (!strcmp(arr_pwds[i], uniq_pwds[j])) {
                is_uniq = false;
                freq[j]++;
                break;
            }
        }

        // If password is unique, add it to unique passwords array
        if (is_uniq) {
            uniq_pwds[uniq_num] = arr_pwds[i];
            freq[uniq_num]++;
            uniq_num++;
        }
    }
    //Find the max frequency of the passwords and the max length
    int max_freq = 0;
    int max_length = 0;
    int correct_pwd_pos = -1;
    for (int i = 0; i < uniq_num; i++) {
        int current_length = strlen(uniq_pwds[i]);
        if (freq[i] > max_freq || (freq[i] == max_freq && current_length > max_length)) {
            max_freq = freq[i];
            max_length = current_length;
            correct_pwd_pos = i;
        }
    }

    //Find the position of the first occurrence of the valid password and return the position as the result
    if (correct_pwd_pos != -1) {
        for (int i = 0; i < num_pwds; i++) {
            if (strcmp(arr_pwds[i], uniq_pwds[correct_pwd_pos]) == 0) {
                return i; // Return position of the first occurrence
            }
        }
    }
    return -99;
}

int checkHP(int HP){
    if (HP > 666){return 666;}
    if (HP < 0){return 0;}
    return HP;
}

int checkEXP(int EXP){
    if (EXP > 600){return 600;}
    if (EXP < 0){return 0;}
    return EXP;
}

int checkMONEY(int M){
    if (M > 3000){return 3000;}
    if (M < 0){return 0;}
    return M;
}

int case21(int exp2, int e1) {
    double temp = ceil(exp2 + ((double(e1) / 4) + 19));
    return checkEXP(temp);
}

int case22(int exp2, int e1) {
    double temp = ceil(exp2 + ((double(e1) / 9) + 21));
    return checkEXP(temp);
}

int case23(int exp2, int e1) {
    double temp = ceil(exp2 + ((double(e1) / 16) + 17));
    return checkEXP(temp);
}

int calculateProbability(int EXP1){
    double temp = round(sqrt(EXP1));
    double S = temp * temp;
    double P = 0;
    if (EXP1 >= S){
        P = 100;
    }
    else if (S != 0){ 
        P = ((EXP1 / S + 80)/123)*100;
    }
    return P;
}

void events(int & HP1, int & EXP1, int & M1, int E2) {
    double paidmoney = 0, halfmoney = 0.5 * M1;
    bool complete = 1;
    while (complete) {
        //First Event
        if (HP1 < 200) {
            HP1 = checkHP(ceil(HP1 + HP1 * 0.3));
            M1 = checkMONEY(M1 - 150);
            paidmoney += 150;
        } else {
            HP1 = checkHP(ceil(HP1 + HP1 * 0.1));
            M1 = checkMONEY(M1 - 70);
            paidmoney += 70;
        }
        if (checkcomplete(paidmoney, halfmoney, M1, E2) == 0) {
            complete = false;
            break;
        }
        //Second event
        if (EXP1 < 400) {
            M1 = checkMONEY(M1 - 200);
            paidmoney += 200;
        } else {
            M1 = checkMONEY(M1 - 120);
            paidmoney += 120;
        }
        EXP1 = ceil(EXP1 + EXP1 * 0.13);
        if (checkcomplete(paidmoney, halfmoney, M1, E2) == 0) {
            complete = false;
            break;
        }
        //Third event
        if (EXP1 < 300) {
            M1 = checkMONEY(M1 - 100);
            paidmoney += 100;
        } else {
            M1 = checkMONEY(M1 - 120);
            paidmoney += 120;
        }
        EXP1 = checkEXP(ceil(EXP1 * 0.9));
        if (checkcomplete(paidmoney, halfmoney, M1, E2) == 0) {
            complete = false;
            break;
        }
        if (E2 % 2 == 0) {
            complete = false;
        }
    }
}


int checkcomplete(int paidmoney, int halfmoney, int M1, int E2){
    //If E2 is an odd number, rerun the events until paid money is larger than half the intial money
    if (E2 % 2 !=0){
            if (paidmoney > halfmoney){
                return 0;
            }  
    }
    else{
        //If the money is less or equal to zero, stop the events
        if (M1 <= 0){
            return 0;
        }
    }
    return 1;
}




////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////