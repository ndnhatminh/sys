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

// Is HP in [0;600] FUNCTION
int hp_limit(int hp){
    if(hp < 0){
        return 0;
    }
    else if(hp > 666){
        return 600;
    }
    else return hp;
}
int exp_limit(int exp){
    if(exp < 0){
        return 0;
    }
    else if(exp > 600){
        return 600;
    }
    else return exp;
}
int money_limit(int money){
    if(money < 0){
        return 0;
    }
    else if(money > 3000){
        return 3000;
    }
    else return money;
}
// Task 1 - DONE 19/2
int firstMeet(int & exp1, int & exp2, int e1) { 
    // TODO: Complete this function
    cout <<"This is first meet" <<"\n";
    if((e1 < 0) || (e1 > 99)) return -99;
    else{
        if((e1 >= 0) && (e1 <= 3)){ // case 1
        cout<<exp1<<endl;
            if(e1 == 0){
                exp2 += 29;
                exp2 = exp_limit(exp2);
            }
            else if(e1 == 1){
                exp2 += 45;
                exp2 = exp_limit(exp2);
            }
            else if(e1 == 2){
                exp2 += 75;
                exp2 = exp_limit(exp2);
            }
            else{
                exp2 += 149; // 149 = 29 + 45 + 75
                exp2 = exp_limit(exp2);
            }
            int d;
            d = ceil(e1*3 + exp1*7);
            if(d % 2 == 0){
                exp1 += ceil(d/200);
                exp1 = exp_limit(exp1);
            }
            else{
                exp1 -= ceil(d/100);
                exp1 = exp_limit(exp1);
            }
        }
        else{ // case 2: e1 = [4;99] the rest of the e1
            if((e1 >= 4) && (e1 <= 19)){ // information 1
                exp2 += ceil((float)e1/4 + 19);
                exp2 = exp_limit(exp2);
            }
            else if((e1 >= 20) && (e1 <= 49)){ // information 2
                exp2 += ceil((float)e1/9 + 21);
                exp2 = exp_limit(exp2);
            }
            else if((e1 >= 50) && (e1 <= 65)){ // information 3
                exp2 = exp2 + ceil((float)e1/16) + 17;
                exp2 = exp_limit(exp2);
            }
            else if((e1 >= 65) && (e1 <= 79)){ // information 4
                exp2 += ceil((float)e1/4 + 19); // information 1
                if(exp2 > 200){
                    exp2 += ceil((float)e1/9 + 21);
                }
                exp2 = exp_limit(exp2);
            }
            else{ // information 5: e1 = [80;99] 
                exp2 += ceil((float)e1/4 + 19); // information 1
                exp2 += ceil((float)e1/9 + 21); // information 2
                if(exp2 > 400){
                    exp2 += ceil((float)e1/16 + 17); // information 3
                    // Explain 3 information
                    exp2 = ceil(exp2*1.15);
                    if(exp2 > 600){
                        exp2 = 600;
                    }
                }
                exp2 = exp_limit(exp2);
            }
            // exp of Sherlock decreases
            exp1 -= e1;
            exp1 = exp_limit(exp1);
        }
        return exp1 + exp2;
    }
}

//Find square number FUNCTION
int find_square_number(int exp1){
    int i=1;
    int S, S1, S2; // S: The CLOSEST Square number TO EXP1
    while(i*i <= exp1){
        i += 1;
    }
    S1 = i*i; // S1 is the square number > EXP1
    S2 = (i-1)*(i-1); // S2 is the square number < EXP1
    if((S1 - exp1) < (exp1 - S2)){
        S = S1;
    }
    else S = S2;
    return S;
}
// Task 2 - DONE 21/2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) { //E2???
    // TODO: Complete this function
    if((E3 < 0) || (E3 > 99)) return -99;
    else{
        
        // 1st road
        int S; // S: The CLOSEST Square number TO EXP1
        float P1, P2, P3; // P1-2-3: found percentage of Sherlock road1-2-3
        float P; // Final percentage in case of Road 3
        // Find square number for P1
        S = find_square_number(EXP1);
        if(EXP1 >= S){
            P1 = 1; // P1 = 100%  
        }
        else P1 = ((EXP1/S) + 80)/123;

        // 2nd road
        //E2 is odd -> loop occurs
        if(E3%2 != 0){
            int limit_M1, cur_fee;
            limit_M1 = M1*0.5; // Limitation of Sherlock's money
            cur_fee = 0;
            while(E3%2 != 0){// Stop if money need to pay > 50% first money
                // 1st EVENT: food and drink
                if(HP1 < 200){
                    int fee;
                    fee = 150;
                    cur_fee += fee;
                    HP1 += ceil(HP1*0.3);
                    HP1 = hp_limit(HP1); 
                    M1 -= 150;
                    M1 = money_limit(M1);
                    if (cur_fee > limit_M1){
                        break;
                    }
                }
                else{
                    int fee;
                    fee = 70;
                    cur_fee += fee;
                    HP1 += ceil(HP1*0.1);
                    HP1 = hp_limit(HP1); 
                    M1 -= 70;
                    M1 = money_limit(M1);
                    if (cur_fee > limit_M1){
                        break;
                    }
                }
                // 2nd EVENT: taxi or horse
                if(EXP1 < 400){ // Choose taxi
                    int fee;
                    fee = 200;
                    cur_fee += fee; // Fee1 + fee2
                    M1 -= 200; // taxi fee
                    M1 = money_limit(M1);
                    EXP1 += EXP1*0.13; //exp increase 13%
                    EXP1 = exp_limit(EXP1);
                    if (cur_fee > limit_M1){
                        break;
                    }
                }
                else{
                    int fee;
                    fee = 120;
                    cur_fee += fee; 
                    M1 -= 120; // horse fee
                    M1 = money_limit(M1);
                    EXP1 += EXP1*0.13; 
                    EXP1 = exp_limit(EXP1);
                    if (cur_fee > limit_M1){
                        break;
                    }
                }
                // 3rd EVENT: help homeless
                if(EXP1 < 300){
                    int fee;
                    fee = 100;
                    cur_fee += fee; 
                    M1 -= 100; // fee = 100
                    M1 = money_limit(M1);
                    EXP1 -= ceil(EXP1*0.1); // exp decrease 10%
                    EXP1 = exp_limit(EXP1);
                    if (cur_fee > limit_M1){
                        break;
                    }
                }
                else {
                    int fee;
                    fee = 120;
                    cur_fee += fee;
                    M1 -= 120; // fee = 120
                    M1 = money_limit(M1);
                    EXP1 -= ceil(EXP1*0.1);
                    EXP1 = exp_limit(EXP1);
                    if (cur_fee > limit_M1){
                        break;
                    } 
                }
            }
            // Sherlock walk
            HP1 = ceil(HP1 - (HP1*0.17));
            HP1 = hp_limit(HP1);
            EXP1 = ceil(EXP1 + (EXP1*0.17));
            EXP1 = exp_limit(EXP1);
            S = find_square_number(EXP1); // NEW square number for P2
            if(EXP1 >= S){
                P2 = 1;
            }
            else P2 = ((EXP1/S)+80)/123;
        }
        //E2 is even - 1 time
        else{
            // 1st event: food and drink
            int init_M1 = M1; // Initial money
            if(HP1 < 200){
                HP1 += ceil(HP1*0.3);
                HP1 = hp_limit(HP1);
                M1 -= 150;
                M1 = money_limit(M1);
            }
            else{
                HP1 += ceil(HP1*0.1);
                HP1 = hp_limit(HP1);
                M1 -= 70;
                M1 = money_limit(M1);
            }
                
            // 2nd event: taxi or horse
            if(EXP1 < 400){ // Choose taxi
                M1 -= 200; // taxi fee
                M1 = money_limit(M1);
                EXP1 += EXP1*0.13; 
                EXP1 = exp_limit(EXP1);
            }
            else{
                M1 -= 120; // horse fee
                M1 = money_limit(M1);
            }
                
            // 3rd event: help homeless
            if(EXP1 < 300){
                M1 -= 100; // fee = 100
                M1 = money_limit(M1);
            }
            else {
                M1 -= 120; // fee = 120
                M1 = money_limit(M1);
            }
            EXP1 -= ceil(EXP1*0.1); // exp decrease 10%
            EXP1 = exp_limit(EXP1);
            S = find_square_number(EXP1); // NEW square number for P2
            if(EXP1 >= S){
                P2 = 1;
            }
            else P2 = ((EXP1/S)+80)/123;
        }
        
        //3rd road
        // An array includes 10 values
        int p[10]={32,47,28,79,100,50,22,83,64,11};
        int i; // i: index of probability
        // Find i
        // E2 = [0;9]
        if(E3/10 < 1){
            i = E3;
        }
        // E2 > 9 : decimal
        else{
            int sum = 0;
            while (E3 > 0 || sum > 9) {
                if (E3 == 0) {
                    E3 = sum;
                    sum = 0;
                }
                sum += E3 % 10;
                E3 /= 10;
            }
            i = sum;
        }
        P3 = p[i]*0.01;
        // After 3 roads
        if((P1 == 1) && (P2 == 1) && (P3 == 1)){ // Re-calculate
            EXP1 = ceil(EXP1 - (EXP1*0.25));
            EXP1 = exp_limit(EXP1);
        }
        else{
            P = (P1 + P2 + P3)/3; //Arithmetic mean
            if(P < 0.5){
                HP1 = ceil(HP1 - (HP1*0.15));
                HP1 = hp_limit(HP1);
                EXP1 = ceil(EXP1 + (EXP1*0.15));
                EXP1 = exp_limit(EXP1);
            }
            else{
                HP1 = ceil(HP1 - (HP1*0.1));
                HP1 = hp_limit(HP1);
                EXP1 = ceil(EXP1 + (EXP1*0.2));
                EXP1 = exp_limit(EXP1);
            }
        }
        return HP1 + EXP1 + M1;
    }
}

// Find max number FUNCTION
int find_max(int n[10]){
    int max;
    max = n[0];
    for(int i=0; i<10; i++){ 
        if(n[i] > max){
            max = n[i];
        }
    }
    return max;
}

// Devide left line and right line into 4 line: left_down, left_up, right_down, right_up 

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    // Initiate matrix (Taxi) m[10][10] each element = 0;
    int m_taxi[10][10];
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            m_taxi[i][j] = ((E3*j) + (i*2))*(i-j);
        }
    }
    // Initiate matrix (Sherlock & Watson)
    int m_SW[10][10];
    int count = 0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            int x, y;
            int n=10; //Max number of an array
            int* a = new int[n];
            x=i; y=j;
            // left_down
            while((x > 0) && (y < 9)){
                a[count] = m_taxi[x+1][y+1];
                count++;
                x++; y++;
            }
            x=i; y=j;
            // left_up
            while((x > 0) && (y > 0)){
                a[count] = m_taxi[x-1][y-1];
                count++;
                x--; y--;
            }
            x=i; y=j;
            // right_down
            while((x < 9) && (y < 9)){
                a[count] = m_taxi[x+1][y-1];
                count++;
                x++; y--;
            }
            x=i; y=j;
            // right_up
            while((x > 0) && (y < 9)){
                a[count] = m_taxi[x-1][y+1];
                count++;
                x--; y++;
            }
            m_SW[i][j] = find_max(a);
            delete[] a;
        }
    }
    // Sherlock + Watson meet taxi A(i,j)
    // i = x_meet
    int x_meet = 0;
    for(int i = 0; i <10; i++){
        for(int j = 0; j < 10; j++){
            if(m_taxi[i][j] > (E3*2)){
                x_meet++;
            }
        }
    }
    if(x_meet > 9){ // No 3 digits number
        int sum = 0;
        while (x_meet > 0 || sum > 9) {
            if (x_meet == 0) {
                x_meet = sum;
                sum = 0;
            }
            sum += x_meet % 10;
            x_meet /= 10;
        }
        x_meet = sum;
    }
    int y_meet = 0;
    for(int i = 0; i <10; i++){
        for(int j = 0; j < 10; j++){
            if(m_taxi[i][j] < (-E3)){
                y_meet++;
            }
        }
    }
    if(y_meet > 9){ // No 3 digits number
        y_meet = (y_meet%10) + (y_meet-10*(y_meet%10));
    }
    if(abs(m_taxi[x_meet][y_meet]) > m_SW[x_meet][y_meet]){ //Chase fail
        EXP1 = ceil(EXP1 - (EXP1*0.12));
        EXP1 = exp_limit(EXP1);
        EXP2 = ceil(EXP2 - (EXP2*0.12));
        EXP2 = exp_limit(EXP2);
        HP1 = ceil(HP1 - (HP1*0.1));
        HP1 = hp_limit(HP1);
        HP2 = ceil(HP2 - (HP2*0.1));
        HP2 = hp_limit(HP2);
    }
    else{ // Chase successfully
        EXP1 = ceil(EXP1 + (EXP1*0.12));
        EXP1 = exp_limit(EXP1);
        EXP2 = ceil(EXP2 + (EXP2*0.12));
        EXP2 = exp_limit(EXP2);
        HP1 = ceil(HP1 + (HP1*0.1));
        HP1 = hp_limit(HP1);
        HP2 = ceil(HP2 + (HP2*0.1));
        HP2 = hp_limit(HP2);
    }
    int score;
    if(abs(m_taxi[x_meet][y_meet]) > m_SW[x_meet][y_meet]){
        score = m_taxi[x_meet][y_meet];
    }
    else{
        score = m_SW[x_meet][y_meet];
    }
    return score;
}

// If c is a character
bool IsCharacter(char c){
    if((c == '@') || (c == '#') || (c == '%') || (c == '$') || (c == '!')){
        return true;
    }
    else return false;
}
bool IsContain(const char* s, string se){
    for (int i = 0; i < strlen(s) - se.length(); i++){
        //find string that has same length of se to compare with 'se' in s
        string temp_s;
        for(int j=i; j<se.length()+i; j++){
            temp_s += s[j];
        }
        if(temp_s == se){
            return true;
        }    
    }
    return false;
}
bool Is2Consecutive(const char* s){
    for(int i=0; i<strlen(s)-1; i++){
        if((IsCharacter(s[i]) == 1) && (IsCharacter(s[i+1]) == 1)){
            return true;
        }
    }
    return false;
}
bool IsSpecialCharacter(const char* s){
    for(int i=0; i<strlen(s); i++){
        if(IsCharacter(s[i]) == 1){
            return true;
        }
    }
    return false;
}
// Task 4 DONE Temporarily
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // Find se string in email;
    string se;
    int i=0;
    while(email[i] != '@'){
        se += email[i];
        i++;
    }    
    // Length of s < 8 return -1
    if(strlen(s) < 8){
        return -1;
    }
    // Length of s > 20 return -2
    else if(strlen(s) > 20){
        return -2;
    }
    // If s contains se
    else if(IsContain(s, se)){
        for (int i = 0; i < strlen(s) - se.length(); i++){
            string temp_s;
            for(int j=i; j<se.length()+i; j++){
                temp_s += s[j];
            }
            if(temp_s == se){
                return -(300+i); // Return 1st position that se appears
            }    
        }
    }
    // s contains at least 2 consecutive characters
    else if(Is2Consecutive(s)){
        for(int i=0; i<strlen(s)-1; i++){
            if((IsCharacter(s[i]) == 1) && (IsCharacter(s[i+1]) == 1)){
                return -(400 + i); // i: 1st position that string contains more than 2 consecutive characters
            }
        }
    }
    //if s doesn't contain special characters
    else if(!IsSpecialCharacter(s)){
        return -5;
    }
    return -10;
}

// Check if the string appeared FUNCTION
bool IsAppear(const char* arr[], const char* curr_pwd, int curr_pos){
    for(int pos=0; pos < curr_pos; pos++){
        if(strcmp(curr_pwd, arr[pos]) == 0){
            return true;
        }
    }
    return false;
}
// Task 5 - DONE Temporarily
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function 
    int max_pwd_length = 20;   
    int max_count = 0;
    int max_length = 0;
    int result_index;

    // Array store number of the appearance (count) and length of each password
    int count[1000]; // Number of appearance of password
    int length[1000]; //Length of password corresponding with the appeared password

    for (int i = 0; i < num_pwds; ++i) {
        const char *curr_pwd = arr_pwds[i];
        int curr_pwd_length = strlen(curr_pwd);

        // If the password has been counted already. (Appeared means be counted)
        if(IsAppear(arr_pwds, curr_pwd, i) == true) {
            break;
        }
        else{
            // Start counting the appearance and the length arrays
            for (int j = 0; j < num_pwds; j++) {// why not j = i??
                if (strcmp(curr_pwd, arr_pwds[j]) == 0) { // The same password appears
                    count[i] += 1; // count the appearance of password and save it to the array
                    length[i] = curr_pwd_length;
                }
            }

            // If the current password has more occurrences or the same occurrences with >= length
            if ((count[i] > max_count) || ((count[i] == max_count) && (length[i] >= max_length))) {
                max_count = count[i];
                max_length = length[i];
                result_index = i;
            }
        }
    }
    return result_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////