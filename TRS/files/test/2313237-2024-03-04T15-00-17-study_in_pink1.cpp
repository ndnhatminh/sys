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
// Added Functions

int absolute(int a){

    if (a >= 0){
        return a;
    }

    else{
        return -a;
    }
}

int Sum_Of_Digits(int a) {

    int i = 0, sum = 0;

    if (a < 10) {
        return a;
    }

    else {
        while (a > 0) {
            i += a % 10;
            a /= 10;
        }

	while( i > 0 ){
            sum += i %10;
            i /= 10;
        }
  
	return sum; 
    }
    
}

int Sum_Of_Digits_2(int a) {

    int i = 0;

    if (a < 10) {
        return a;
    }

    else {
        while (a > 0) {
            i += a % 10;
            a /= 10;
        }

        return (i % 10);      
    }
}

int checkHP(int &HP){
    
    if(HP > 666){
        HP = 666;
    }

    else if(HP < 0){
        HP = 0;
    }

    return HP;
}
    
    
int checkEXP(int &EXP){
   
    if(EXP > 600){
        EXP = 600;
    }

    else if(EXP < 0){
        EXP = 0;
    }
    
    return EXP;
}
    
int checkmoney(int &M){
    
    if(M > 3000){
        M = 3000;
    }

    else if(M < 0){
        M = 0;
    }

    return M;
}
bool isPerfectSquare(int n){
    for (int i = 1; i * i <= n; i++) {
 
        if (n % i == 0 && n / i == i) {
            return true;
        }
    }
    return false;
}

int nearest_perfect_squre(int n){

    int lower_perfect = n;
    int upper_perfect = n;


    if(n < 0){
        n = 0;
    }

    while(isPerfectSquare(lower_perfect) == 0){  
        lower_perfect -= 1;
    }
    while(isPerfectSquare(upper_perfect) == 0){  
        upper_perfect += 1;
    }
    
    if (absolute(n - lower_perfect) < absolute(n - upper_perfect)) {
        return lower_perfect;
    }

    else{
        return upper_perfect;
    }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    checkEXP(exp1);
    checkEXP(exp2);

    if(e1 > 99 || e1 < 0){
        return -99;
    }

    else if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) {
            exp2 += 29;
            checkEXP(exp2);
        }
        
        else if (e1 == 1) {
            exp2 += 45;
            checkEXP(exp2);
        }

        else if (e1 == 2) {
            exp2 += 75;
            checkEXP(exp2);
        }

        else{
            exp2 += 149;
            checkEXP(exp2);
        }


        double D = e1*3 + exp1*7;

        if (int(D)%2 == 0) {
            exp1 = exp1 + D/200 + 0.999;
            checkEXP(exp1);
        }

        else{
            exp1 = exp1 - D/100 + 0.999;
            checkEXP(exp1);
        }
    }


    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 = exp2 + e1/(double)4 + 19 + 0.999; 
            checkEXP(exp2);
        }

        else if (e1 >= 20 && e1 <= 49) {
            exp2 = exp2 + e1/(double)9 + 21 + 0.999;
            checkEXP(exp2);
        }

        else if (e1 >= 50 && e1 <= 65) {
            exp2 = exp2 + e1/(double)16 + 17 + 0.999;
            checkEXP(exp2);
        }

        else if (e1 >= 66 && e1 <= 79) {
            exp2 = exp2 + e1/(double)4 + 19 + 0.999 ;
            checkEXP(exp2);

            if (exp2 > 200) {
                exp2 = exp2 + e1/(double)9 + 21 + 0.999;
                checkEXP(exp2);
            }

            
        }

        else{
            exp2 = exp2 + e1/(double)4 + 19 + 0.999;
            checkEXP(exp2);
            exp2 = exp2 + e1/(double)9 + 21 + 0.999;
            checkEXP(exp2);

            if (exp2 > 400) {
                exp2 = exp2 + e1/(double)16 + 17 + 0.999;
                checkEXP(exp2);

                exp2 = exp2*(double)1.15 + 0.999;
                checkEXP(exp2);
            }
            
        }


        exp1 -= e1;
        checkEXP(exp1);
        
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
	checkHP(HP1);
    checkEXP(EXP1);
    checkmoney(M1);


    int S = nearest_perfect_squre(EXP1);
    double P1,P2,P3,Pa;
    int i;
    int paid = 0,halfM1 = 0.5*M1;
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

    //Road 1
    if (EXP1 >= S) {
        P1 = 100;
    }

    else{
        P1 = ((EXP1/(double)S+80)/123)*100;
    }

    //Road 2

    if(M1 == 0){

        HP1 = HP1*0.83 + 0.999;
        EXP1 = EXP1*1.17 + 0.999;
        
        checkEXP(EXP1);
    }

    else{
        if(E2 %2 != 0){
            while(paid <= halfM1){
            
    //Event 1
    
    if (HP1 < 200) {
        HP1 = HP1*1.3 + 0.999;

        M1 -= 150;
        checkmoney(M1);

        paid +=150;
    }

    else {
        HP1 = HP1*1.1 + 0.999;
        checkHP(HP1);

        M1 -= 70;
        checkmoney(M1);

        paid += 70;
    }

    if(paid > halfM1){
        break;
    }
        //Event 2
    if (EXP1 < 400) {
        M1 -= 200;
        checkmoney(M1);

        paid += 200;
	EXP1 = EXP1*1.13 + 0.999; // Added
    }

    else{
        M1 -= 120;
        checkmoney(M1);
        
        paid += 120;

        EXP1 = EXP1*1.13 + 0.999;
        checkEXP(EXP1);
    }

    if(paid > halfM1){
        break;
    }

    // Event 3

    if (EXP1 < 300) {
        M1 -= 100;
        checkmoney(M1);

        paid += 100;
    }

    else{
        M1 -= 120;
        checkmoney(M1);

        paid += 120;
    }

    EXP1 = EXP1*0.9 + 0.999;

    if(paid > halfM1){
        break;
    }
    }

    HP1 = HP1*0.83 + 0.999;
    EXP1 = EXP1*1.17 + 0.999;

    checkEXP(EXP1);
    }

    else{
        
    bool out_of_money = false;

        //Event 1
    if(out_of_money == false){
        if (HP1 < 200) {
            HP1 = HP1*1.3 + 0.999;

            M1 -= 150;
            checkmoney(M1);

            paid +=150;
        }
        else if(HP1 >= 200) {
            HP1 = HP1*1.1 + 0.999;
            checkHP(HP1);

            M1 -= 70;
            checkmoney(M1);

            paid += 70;
        }
    
    }

    if(M1 == 0){
        out_of_money = true;
    }

    if(out_of_money == false){
        //Event 2
    if (EXP1 < 400) {
        M1 -= 200;
        checkmoney(M1);

        paid += 200;
	    EXP1 = EXP1*1.13 + 0.999; // Added
    }

    else if (EXP1 >= 400) {
        M1 -= 120;
        checkmoney(M1);
	    checkEXP(EXP1);

        paid += 120;

        EXP1 = EXP1*1.13 + 0.999;
        checkEXP(EXP1);
    }
    }

    if(M1 == 0){
        out_of_money = true;
    }

    if(out_of_money == false){
         // Event 3

    if (EXP1 < 300) {
        M1 -= 100;
        checkmoney(M1);

        paid += 100;
    }

    else if (EXP1 >= 300) {
        M1 -= 120;
        checkmoney(M1);

        paid += 120;
    }

    EXP1 = EXP1*0.9 + 0.999;
    }
    
    HP1 = HP1*0.83 + 0.999;
    EXP1 = EXP1*1.17 + 0.999;
    
    }
  
    S = nearest_perfect_squre(EXP1);
    if (EXP1 >= S) {
        P2 = 100;
    }

    else{
        P2 = (double(EXP1/S + 80)/123)*100;
    }

    //Road 3 
    i = Sum_Of_Digits_2(E2);

    P3 = P[i];
    
    if (P1 == 100 && P2 == 100 && P3 == 100) {
        EXP1 = EXP1*0.75 + 0.999;
    }
    else{
        Pa= (P1 + P2 + P3)/3;
    }

    if (Pa < 50) {
        HP1 = HP1*0.85 + 0.999;

        EXP1 = EXP1*1.15 + 0.999;
        checkEXP(EXP1);
    }
    else {
        HP1 = HP1*0.9 + 0.999;

        EXP1 = EXP1*1.2 + 0.999;
        checkEXP(EXP1);
    }

    } 
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
	
	checkEXP(EXP1);        
	checkEXP(EXP2);
        
	checkHP(HP1);
	checkHP(HP2);

    // initialize taxi's grade   
    int map[10][10];
    int SherlockandWatson[10][10];

    int count1 = 0, count2 = 0;
    int left_diagonal_max = 0, right_diagonal_max = 0;

    for(int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = (E3*j + (i*2)) * (i-j);
        }
    }
    // Scores for Sherlock and Watson

    for(int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {

            left_diagonal_max = map[i][j];
            right_diagonal_max = map[i][j];

            for(int a = i,b = j; a < 10 && b < 10 ; a++,b++){
                if(map[a][b] > left_diagonal_max){
                    left_diagonal_max = map[a][b];
                }
            }

            for(int a = i,b = j; (a < 10 && a >= 0) && (b < 10 && b >= 0) ; a++,b--){
                if(map[a][b] > right_diagonal_max){
                    right_diagonal_max = map[a][b];
                }
            }

            if(left_diagonal_max > right_diagonal_max){
                SherlockandWatson[i][j] = absolute(left_diagonal_max);            
            }

            else{
                SherlockandWatson[i][j] = absolute(right_diagonal_max);   
            }      

        }
    }
     

    // taxi meet check

    for(int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map[i][j] > E3*2){
                count1 += 1;
            }

            else if (map[i][j] < -E3){
                count2 += 1;
            }
        }
    }

    int index_i = Sum_Of_Digits(count1);
    int index_j = Sum_Of_Digits(count2);

    // catch taxi check 

        // Catch successfully

    if (absolute(map[index_i][index_j]) <= SherlockandWatson[index_i][index_j]){
        EXP1 = EXP1*1.12 + 0.999;
	checkEXP(EXP1);

        EXP2 = EXP2*1.12 + 0.999;
	checkEXP(EXP2);

        HP1 = HP1*1.1 + 0.999;
	checkHP(HP1);

        HP2 = HP2*1.1 + 0.999;
	checkHP(HP2);
    }
    

        // Catch Failed
    else{

        EXP1 = EXP1*0.88 + 0.999;
	    checkEXP(EXP1);

        EXP2 = EXP2*0.88 + 0.999;
	    checkEXP(EXP2);

        HP1 = HP1*0.9 + 0.999;
	    checkHP(HP1);

        HP2 = HP2*0.9 + 0.999;
	    checkHP(HP2);
    }
    

    // return result
    if (map[index_i][index_j] < 0 ||map[index_i][index_j] >= SherlockandWatson[index_i][index_j]){
        return map[index_i][index_j];
    }

    else{      
        return SherlockandWatson[index_i][index_j];       
    }
    
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
	bool contain_special_character = false;

    //Initialize se string

    std::string email_string(email);
    std::string s_string(s);

    int position = email_string.find("@");

    string se = email_string.substr(0 , position);

    // Get s_string's length

    int s_length = 0;     
    
    // s(s_string) check

    while (s_string[s_length] != '\0'){
        s_length++;
    }   

    if(s_length < 8){
        return -1;
    }
    
    else if(s_length > 20){
        return -2;
    }

    // s_string contains se check

    bool isFound = s_string.find(se) != string::npos;
    int index = s_string.find(se);

    if (isFound == true){      
        return -(300 + index);     
    }

    // 3 consecutive identical characters check

    bool consecutive;

    for (int i = 0; i < s_length - 2; i++){
        consecutive = (((s_string[i] == s_string[i+1]) && (s_string[i+1] == s_string[i+2])) == 1);

        if(consecutive == 1){
            return -(400+i);
            break;
            
        }
    }

    // Contain special character check

    for (int i = 0; i < s_length; i++){
        if(s_string[i] == '@'||s_string[i] == '#'||s_string[i] == '%'||s_string[i] == '$'||s_string[i] == '!'){
            contain_special_character = true;
            break;
        }
        
    }

    if(contain_special_character == false){
        return -5;
    }

    //Remaining cases check
    
    else{
        for(int i = 0; i < s_length; i++){
            if((s_string[i] >= 48 && s_string[i] <= 57)||
                (s_string[i] >= 65 && s_string[i] <= 90)||
                (s_string[i] >= 97 && s_string[i] <= 122)||
		        s_string[i] == '@'||s_string[i] == '#'||s_string[i] == '%'||s_string[i] == '$'||s_string[i] == '!'){
                    continue;
            }

            else{
                return i;
                break;
            }
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

	int freq = 1;
    int index = 0;

    string res;
    

    for (int i = 0; i < num_pwds; i++) {
        int count = 1;
        

        for (int j = i + 1; j < num_pwds; j++) {
            if (arr_pwds[j] == arr_pwds[i]) {
                count++;
            }
        }
        
        if (count >= freq) {
            res = arr_pwds[i];
            index = i;         
            freq = count;
        }

    }
    
    return index;  
    
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////