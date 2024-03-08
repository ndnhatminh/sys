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
    if (e1 >= 0 && e1 <= 3) {    
    int D;
    switch (e1) {
            case 0: // Information 1
                exp2 += 29;
                break;
            case 1: // Information 2
                exp2 += 45;
                break;
            case 2: // Information 3
                exp2 += 75;
                break;
            case 3: // Information 4
                exp2 += 29 + 45 + 75;
        }

        D = e1 * 3 + exp1 * 7;

        if (D % 2 == 0) {  
            exp1 += ceil((float)D/200);
        } else {
            exp1 -= floor((float)D/100);
        }
        
	// Check EXP condition.
	if (exp1 > 600) { 
    exp1 = 600;
	} else if (exp1 < 0) {
    exp1 = 0;
	}

	if (exp2 > 600) { 
    exp2 = 600;
	} else if (exp2 < 0) {
    exp2 = 0;
	}
 	return exp1 + exp2;

    }else if(e1 >= 4 && e1 <= 99){
        if(e1 >= 4 && e1 <= 19){ // Information 1
            exp2 += ceil((float)e1/4 + 19);
        }
        else if(e1 >= 20 && e1 <= 49){ // Information 2
            exp2 += ceil((float)e1/9 + 21);
        }
        else if(e1 >= 50 && e1 <= 65){ // Information 3
            exp2 += ceil((float)e1/16 + 17);
        }
        else if(e1 >= 66 && e1 <= 79){ // Information 4
            exp2 += ceil((float)e1/4 + 19);
            if(exp2 > 200){
                exp2 += ceil((float)e1/9 + 21);
            }
        }
        else if(e1 >= 80 && e1 <= 99){ // Information 5
            exp2 += ceil((float)e1/4 + 19);
            exp2 += ceil((float)e1/9 + 21);
            if(exp2 > 400){
                exp2 += ceil((float)e1/16 + 17);
                exp2 = ceil((float)exp2 * 1.15);
            }
        }

    exp1 = exp1 - e1; 
    //Check EXP condition.
    if (exp1 > 600 || exp2 > 600) {
            if (exp1 > 600) { 
                exp1 = 600;
            } else {
                exp2 = 600;
            }
        } 
    if (exp1 < 0 || exp2 < 0) {
            if (exp1 < 0) { 
                exp1 = 0;
            } else {
                exp2 = 0;
            }
        }

    return exp1 + exp2;
    }else{
    return -99;
    }
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 >= 0 && E2 <= 99){

    float P_average; /*the average probability for Sherlock to find the
    suitcase on all 3 routes;*/

    // Road 1:
    float S = 0; // the nearest perfect square to the value EXP1
    int temp1;
    int temp2;
    float P1; /*the probability for Sherlock to find the suitcase on
    this route*/ 
    
    // The probability P1 of finding the suitcase on this route.
    temp1 = floor(sqrt(EXP1));
    temp2 = ceil(sqrt(EXP1));
    if((EXP1 - temp1*temp1) > (temp2*temp2 - EXP1)){
        // EXP1 < S
        S = temp2*temp2;
        P1 = ((float)EXP1/S + 80)/123;
    }
    else{ // EXP1 >= S
        S = temp1*temp1;
        P1 = 1;
    }

    // Road 2:
    // FOOD or DRINK:
    int m = 0; // MONEY SPENT.
    if(E2 % 2 != 0){

    m = ceil(M1 / 2);
    while(M1 >= m){
    // FOOD or DRINK:
    if(HP1 < 200){ //Food
        HP1 += ceil(HP1*0.3);
        M1 -= 150; //Food
        if(M1 < m){
            break;
        }
    }else{ //Beverage
        HP1 += ceil(HP1*0.1);
        M1 -= 70; //Drink
        if(M1 < m){
            break;
        }
    }

    // RENTAL TRANSPORTATION:
    if(EXP1 < 400){ //Sherlock will choose to take a taxi
        M1 -= 200; // The price to rent a taxi
        EXP1 += ceil(EXP1*0.13);
        if(M1 < m){
            break;
        }   
    }else{ //Sherlock will choose to take a horse-drawn carriage
        M1 -= 120; // The price to rent a horse-drawn carriage
        EXP1 += ceil(EXP1*0.13);
        if(M1 < m){
            break;
        }    
    }
   
    // SHERLOCK MET A HOMELESS PERSON:
    if(EXP1 < 300){ //Listen to a homeless person's instructions.
        M1 += 100;
        EXP1 -= floor(EXP1*0.1);       
        if(M1 < m){
            break;
        }  
    }else{ //Ask this person to lead the way
        M1 -= 120;
        EXP1 -= floor(EXP1*0.1); 
        if(M1 < m){
            break;
        }  
    }
    }

    HP1  -= floor(HP1*0.17); 
    EXP1 += ceil(EXP1*0.17);
    }else{

    // FOOD or DRINK:
    if(M1 > 0){
    if (HP1 < 200) { // Food
            
        HP1 += ceil(HP1 * 0.3);
        M1 -= 150; // Food
    } else { // Beverage
                
        HP1 += ceil(HP1 * 0.1);
        M1 -= 70; // Drink
        }    
    }

    // RENTAL TRANSPORTATION:
    if(M1 > 0){
    if (EXP1 < 400) { // Sherlock will choose to take a taxi
        M1 -= 200; // The price to rent a taxi
        EXP1 += ceil(EXP1 * 0.13);
    } else { // Sherlock will choose to take a horse-drawn carriage
                        
        M1 -= 120; // The price to rent a horse-drawn carriage
        EXP1 += ceil(EXP1 * 0.13);
        }    
    }   

    // SHERLOCK MET A HOMELESS PERSON:
    if(M1 > 0){
        if (EXP1 < 300) { // Listen to a homeless person's instructions
            M1 -= 100;
            EXP1 -= floor(EXP1 * 0.1);
        } else { // Ask this person to lead the way
            M1 -= 120;
            EXP1 -= floor(EXP1 * 0.1);
        }    
    }

    HP1  -= floor(HP1*0.17); 
    EXP1 += ceil(EXP1*0.17);
    }

    // The probability P2 of finding the suitcase on this route.
    temp1 = floor(sqrt(EXP1));
    temp2 = ceil(sqrt(EXP1));
    float P2; /*the probability for Sherlock to find the suitcase on
    this route */
    if((EXP1 - temp1*temp1) > (temp2*temp2 - EXP1)){
        S = temp2*temp2;
        P2 = ((float)EXP1/S + 80)/123;
    }
    else{
        S = temp1*temp1;
        P2 = 1;
    }

    //Road 3:
    float P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int P3;
    int i;
    if(E2 >= 0 && E2 < 10){
        i = E2;
        P3 = P[i];
    }else{
        if((E2/10 + E2%10) >= 10){
            i = (E2/10 + E2%10) -10;
            P3 = P[i];
        }else{
            i = E2/10 + E2%10;
            P3 = P[i];
        }        
    }

    //Average probability:
    P_average = (P1*100 + P2*100 + P3)/3;

    if(P_average == 100){
        EXP1 -= floor(EXP1*0.25);
    }else if(P_average < 50){
        HP1 -= floor(HP1*0.15);
        EXP1 += ceil(EXP1*0.15);
    }else{
        HP1 -= floor(HP1*0.1);
        EXP1 += ceil(EXP1*0.2);        
    } 

    // Check HP, Money and EXP1 condition
    if (HP1 > 666 || M1 > 3000 || EXP1 > 600) {
        if(HP1 > 666){
            HP1 = 666;
        }
        else if (M1 > 3000){
            M1 = 3000;
        }
        else{
            EXP1 = 600;
        }
    } 
    if (HP1 < 0 || M1 < 0 || EXP1 < 0) {
        if(HP1 < 0){
            HP1 = 0;
        }
        else if (M1 = 0){
            M1 = 0;
        }else{
            EXP1 = 0;
        }
    }
    return HP1 + EXP1 + M1;
}else{
return -99;
}
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 >=0 && E3 < 100){
    
    //Meeting location.
    int location_rows;
    int i = 0; // Use to assign rows location to avoid errors
    int location_columns;
    int j = 0; // Use to assign colunms location to avoid errors
    //Taxi's grade.
    int Taxi_grade;
    //Sherlock_Watson_grade.
    int Sherlock_Watson_grade;

    int count_positive = 0; /*The number of positive values in the matrix
    greater than (E3*2)*/
    int count_negative = 0; /*The number of negative values in the matrix
    smaller than (-E3)*/

    /*Initialize a 10x10 matrix with each element of the array being an
    integer initialized to the value 0*/
    const int rows = 10; // ROWS 
    const int columns = 10; // COLS 

    int matrix[rows][columns] = {0};
    //Assign a value to each element in the matrix
    /*The value of each location is the skill score of that taxi at that
    location*/
    //Taxi running map:
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j) {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if(matrix[i][j] > E3 * 2) {
                count_positive++;
            }
            if(matrix[i][j] < (-E3)) {
                count_negative++;
            }
        }
    }

    //Find meeting location.
    if(count_positive >= 10) {
        i = (count_positive / 10) + (count_positive % 10);
        if(i >= 10) {
            i = i / 10 + i % 10;
        }
    } else {
        i = count_positive;
    }  	
	
    if(count_negative >= 10) {
        j = (count_negative / 10) + (count_negative % 10);
        if(j >= 10) {
            j = j / 10 + j % 10;
        }
    } else {
        j = count_negative;
    }

    location_rows = i;
    location_columns = j;

    int max_value = matrix[location_rows][location_columns];

	// Find the maximum value on the left diagonal.
    while(i >= 0 && j >= 0) {
        if(matrix[i][j] > max_value)
            max_value = matrix[i][j];
        i--;
        j--;            
    }
    i = location_rows;
    j = location_columns;
    while(i < 10 && j < 10) {
        if(matrix[i][j] > max_value)
            max_value = matrix[i][j];
        i++;
        j++;
    }
    i = location_rows;
    j = location_columns;
	// Find the maximum value on the right diagonal.
    while(i < 10 && j >= 0){
        if(matrix[i][j] > max_value)
            max_value = matrix[i][j];
        i++;
        j--;    	
	}
    i = location_rows;
    j = location_columns;
    while(i >= 0 && j < 10){
        if(matrix[i][j] > max_value)
            max_value = matrix[i][j];
        i--;
        j++;    	
	}
           
    //Sherlock's value at the meeting location
    Sherlock_Watson_grade = max_value;
    //The taxi's value at the meeting location
    Taxi_grade = matrix[location_rows][location_columns];
    
	if(abs(Taxi_grade) > Sherlock_Watson_grade){
		EXP1 = ceil(EXP1*0.88);
		HP1 = ceil(HP1*0.9);
		EXP2 = ceil(EXP2*0.88);
		HP2 = ceil(HP2*0.9);		
		return Taxi_grade;
	}else{
		EXP1 = ceil(EXP1*1.12);
		HP1 = ceil(HP1*1.1);
		EXP2 = ceil(EXP2*1.12);
		HP2 = ceil(HP2*1.1);		
		
		return Sherlock_Watson_grade; 
	}

    // Check Sherlock Holmes HP and EXP condition
    if (HP1 > 666 || EXP1 > 600) {
        if(HP1 > 666){
            HP1 = 666;
        }
        else{EXP1 = 600;}
    } 
    if (HP1 < 0 || EXP1 < 0) {
        if(HP1 < 0){
            HP1 = 0;
        }
        else{EXP1 = 0;}
    }

    // Check Watson HP and EXP condition
    if (HP2 > 666 || EXP2 > 600) {
        if(HP2 > 666){
            HP2 = 666;
        }
        else{EXP2 = 600;}
    } 
    if (HP2 < 0 || EXP2 < 0) {
        if(HP2 < 0){
            HP2 = 0;
        }
        else{EXP2 = 0;}
    }
    
    }else{
    return -99;       
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int valid_password = 0;

    int split_string = 0; // split string before @ character.
    int sei = 0; // the first occurrence of se.
    char se[100];
    for(int i = 0; email[i] != '@'; i++){
        se[i] = email[i];
        split_string++;
    }
    se[split_string] = '\0';
    
    const char *position = strstr(s, se);

    if (position != NULL) {
        sei = position - s; 
    }

    if(strlen(s) < 8 || strlen(s) > 20){
        if(strlen(s) < 8){
            valid_password = -1;
        }else{
            valid_password = -2;
        }
    }else{ // After satisfying the length condition 
        // Check to see if the password has "se" or not?
        if(strstr(s, se) != NULL){
            valid_password = -(300 + sei);
        }else{ 
            // Check to see if the password has more than 2 identical characters
            bool two_similar_characters = false;
            for(int i = 0; i < strlen(s) - 2; ++i){
                if(s[i] == s[i + 1] && s[i] == s[i + 2]){
                    valid_password = -(400 + i);
                    two_similar_characters = true;
                    break;
                }
            }
            if (!two_similar_characters) { // After satisfying the condition that there are no more than 2 identical characters
                bool valid_character = true;
                bool has_special_character = false;
                int Invalid_character_position;
                
                for(int i = 0; s[i] != '\0'; ++i){
                    if (!((s[i]>= 'a' && s[i] <= 'z') ||
                        (s[i] >= 'A' && s[i] <= 'Z') ||
                        (s[i] >= '0' && s[i] <= '9') ||
                        (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))) {
                        Invalid_character_position = i;
                        valid_character = false;
                    }
                    // Check if the password contains special characters
                    if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
                        has_special_character = true;
                    }
                }
                if (valid_character == false) {
                        valid_password = Invalid_character_position;
                } else {
                    if (has_special_character) {
                        valid_password = -10;
                    } else {
                        valid_password = -5;
                    }
                }
            }
        }
    }
    return valid_password;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    // Craete an array to store the frequency of passwords
    int frequency_count[num_pwds];
    // Initialize the frequency_count array with the value 0
    memset(frequency_count, 0, sizeof(frequency_count));
    // Find the highest frequency of occurrence of the password
    int max_frequency = 0;
    for (int i = 0; i < num_pwds; ++i){
        int count = 0;
        for (int j = 0; j < num_pwds; ++j){
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0){
                count++;
            }
        }
        frequency_count[i] = count;
        if(count > max_frequency){
            max_frequency = count;
        }
    }

    // Find the longest length of the password
    size_t max_length = 0;
    for (int i = 0; i < num_pwds; ++i){
        /*Check whether the frequency at i coincides with the highest
        frequency and whether the length of the password at i is greater
        than the maximum length.*/
        if(frequency_count[i] == max_frequency && strlen(arr_pwds[i]) > max_length){
            max_length = strlen(arr_pwds[i]);
        } 
    }

    // Find the password that meets the condition and output the first appearing position
    for(int i = 0; i < num_pwds; ++i){
        if (frequency_count[i] == max_frequency && strlen(arr_pwds[i]) == max_length){
        return i;        
        }
    }
    // If no suitable password is found.
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////