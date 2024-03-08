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
////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

int check(int n, int startpoint, int endpoint) {
    n = (n < startpoint) ? startpoint : (n > endpoint) ? endpoint : n;
    return n;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
	int startpoint = 0, endpoint = 600;

	//check the input
	if (e1 < 0 || e1 > 99) return -99;
	exp1 = check(exp1, startpoint, endpoint);
	exp2 = check(exp2, startpoint, endpoint);

//=========this is mission 1===================
	// calc value mission 1
	const int val1_1 = 29, val1_2 = 45, val1_3 = 75;

	// calc value mission 1
	float val2_1, val2_2, val2_3;
	val2_1 = e1 * 1.0000 / 4 + 19;
	val2_2 = e1 * 1.0000 / 9 + 21;
	val2_3 = e1 * 1.0000 / 16 + 17;

	// use float to calc exp
	float exp1_float = exp1;
	float exp2_float = exp2;

     // calc exp2
	if (e1 <= 3){
	switch (e1)
	   {
	case 0: exp2 =  exp2 + val1_1; break;
	case 1: exp2 =  exp2 + val1_2; break;
	case 2: exp2 =  exp2 + val1_3; break;
	case 3: exp2 =  exp2 + val1_1 + val1_2 + val1_3; break;
	    }

	//calc D
	int D;
	D = e1 * 3 + exp1 * 7;

	// calc exp1 (need to round up)
	if(D%2==0) exp1 = ceil(exp1 + D/200.0);
	else exp1 = ceil(exp1 - D/100.0);
	}

//=========this is mission 2===================
	else{
		if (e1 < 20) exp2 = ceil(exp2 + val2_1);
		else if (e1 >= 20 && e1 <50) exp2 = ceil(exp2 + val2_2);
		else if (e1 >= 50 && e1 < 66) exp2 = ceil(exp2 + val2_3);
		else if (e1 >= 66 && e1 < 80){
			exp2 = ceil(exp2 + val2_1); //exp2 when Sherlock explains information 1
			//exp2 = exp2_float; //convert to int
			exp2 = check(exp2, startpoint, endpoint);
			//exp2_float = exp2;
			if (exp2 > 200) exp2 = ceil(exp2 + val2_2);
			}
		else if (e1 >= 80 && e1 <100)
		{
			exp2 = ceil(exp2 + val2_1);
			exp2 = ceil(exp2 + val2_2);
		//exp2 when Sherlock explains information 1 and 2
			//exp2 = exp2_float; //convert to int
			exp2 = check(exp2, startpoint, endpoint);
			//exp2_float = exp2;
			if (exp2 > 400) {
			exp2 = ceil(exp2 + val2_3);
			//exp2 = exp2_float;
			exp2 = check(exp2, startpoint, endpoint);
			//exp2_float = exp2;
			exp2 = ceil(exp2 + exp2 * 0.1500);
			}
		}
		//exp2_float = ceil(exp2_float);
		//exp2 = exp2_float;
		// calc exp1
		exp1 = exp1 - e1;
	}
	exp1 = check(exp1, startpoint, endpoint);
	exp2 = check(exp2, startpoint, endpoint);
    return exp1 + exp2;
}

/*int check_nearestSquare(int EXP1){
    int S = sqrt(EXP1); 
    if(EXP1 - S*S < (S+1)*(S+1) - EXP1) return S*S;
    else return (S+1)*(S+1);
}*/


/*int check_nearestSquare(int EXP1){
 
	int S = sqrt(EXP1);
	S = pow(S,2);
	return S;
	}*/

int check_nearestSquare(int s){
    int e = int(sqrt(s)); 
    if(s - e*e< (e+1)*(e+1) - s) return e*e;
    return (e+1)*(e+1);
}




	// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    //check input
	if(E2 < 0 || E2 > 99) return -99;
	HP1 = check(HP1, 0, 666);
	EXP1 = check(EXP1, 0, 600);
	M1 = check(M1, 0, 3000);

	//find the nearest pềct square
	int S1 = check_nearestSquare(EXP1);

	//road 01
	float P1;
	if(EXP1 >= S1) P1 = 1.00;
	else P1 = (EXP1/S1 + 80.0)/123.0;

	//some price
	int price_food = 150;
	int price_water = 70;
	int price_taxi = 200;
	int price_carriage = 120;
	int price_help1 = 100;
	int price_help2 = 120;
	
	//road 02
	int M_total, M1_spent;
	const int M1_half = 0.5 * M1;
	M1_spent =  0;

	do{
	    
	if(HP1 < 200) {
	    HP1 = ceil(HP1 + HP1 * 0.3);
	    M1 = M1 - price_food;
	    M1_spent += price_food;
	    }
	else{
	    HP1 = ceil(HP1 + HP1 * 0.1);
	    M1 = M1 - price_water;
	    M1_spent += price_water;
	}
    	HP1 = check(HP1, 0, 666);
	M1_spent += M1_spent;
	
	if(E2 % 2 != 0 || M1 <= 0){
	    M1 = check(M1, 0, 3000);
	    if (M1 < M1_half) break;
	    else{ 
		if(M1 == 0){
	   	M1 = check(M1, 0, 3000);
	   	break;
		    }
		}
	    }
	
	if(EXP1 < 400){ 
	M1 = M1 - price_taxi;
	M1_spent += price_taxi;
	
	}
	else{
	M1 = M1 - price_carriage;
	M1_spent += price_carriage;
	}
	EXP1 = ceil(EXP1 + EXP1 * 0.13);
	EXP1 = check(EXP1, 0, 600);
	M1_spent += M1_spent;
	
	if(E2 % 2 != 0 || M1 <= 0){
	    M1 = check(M1, 0, 3000);
	    if (M1 < M1_half) break;
	    else{ 
		if(M1 == 0){
	   	M1 = check(M1, 0, 3000);
	   	break;
		    }
		}
	    }
 	
	if(EXP1 < 300){
	M1 = M1 - price_help1;
	M1_spent += price_help1;
	
	}
	else{
	M1 = M1 - price_help2;
	M1_spent += price_help2;
	
	}
	
	EXP1 = ceil(EXP1 - EXP1 * 0.1);
	EXP1 = check(EXP1, 0, 600);
	M1_spent += M1_spent;

	if(E2 % 2 != 0 || M1 <= 0){
	    M1 = check(M1, 0, 3000);
	    if (M1 < M1_half) break;
	    else{ 
		if(M1 == 0){
	   	M1 = check(M1, 0, 3000);
	   	break;
		    }
		}
	    }
 	  } while (E2%2!=0);
 	   
    	HP1 = ceil(HP1 - HP1*0.17);
	EXP1 = ceil(EXP1 + EXP1*0.17);
    	HP1 = check(HP1, 0, 666);
    	EXP1 = check(EXP1, 0, 600);


	//find the nearest pềct square
	int S2 = check_nearestSquare(EXP1);

	//calc P2
	float P2;
	if(EXP1 >= S2) P2 = 1.00;
	else P2 = ((EXP1/S2) + 80.0)/123.0;

	//road 03

	int arr_P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
	float P3;
	int i = 0;
	if(E2 >= 0 && E2 < 10){
		i = E2;	
		}
	else{
		int first_digit = E2/10;
		int last_digit = E2%10;
		//take the number of the unit place of 2-digit number
		int pos_i = (first_digit + last_digit)%10;
		i = pos_i;
		
		}
	P3 = arr_P[i]/100.0;
	
	//calc P_avg
	float P_avg;

	P_avg = (P1 + P2 + P3)/3;
	if(P_avg == 1.0000){
	    EXP1 = ceil(EXP1 - 0.25 * EXP1);
	    EXP1 = check(EXP1, 0, 600);
	    return HP1 + EXP1 + M1;
	    }
	    
	if(P_avg < 0.5000){
		HP1 = ceil(HP1 - 0.15 * HP1);
		EXP1 = ceil(EXP1 + 0.15 * EXP1);
		}
	else{
		HP1 = ceil(HP1 - 0.1 * HP1);
		EXP1 = ceil(EXP1 + 0.2 * EXP1);
		}
	
	//check the value of EXP1 and HP1 after going through all 03 routes
	M1 = check(M1, 0, 3000);
	HP1 = check(HP1, 0, 666);
	EXP1 = check(EXP1, 0, 600);
    return HP1 + EXP1 + M1;
}

int check_thesize(int n){
	if ((n >=0) && (n <= 9)) return true;
	else return false;
	}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

	if (E3 < 0 || E3 > 99) return -99;
	int matrix[10][10];

	//calc the matrix value
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
		   matrix[i][j]= ((E3*j)+(i*2))*(i-j);
		  }
		}
	int r = 0, c = 0;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(matrix[i][j]>E3*2) r++;
			else if (matrix[i][j]<-E3) c++;
			}
		     }

	//repeating the stage sum of two digits until the sum is the one-digit number
	while(r > 9){
		r = r/10 + r%10;
		}
	while(c > 10){
		c = c/10 + c%10;
		}	
    	int taxi_score = matrix[r][c];
	int left_diagonal  = matrix[r][c], right_diagonal  = matrix[r][c];
	
	// calc rigth below val on right diagonal
	while(check_thesize(r+1) && check_thesize(c-1)){
		if(right_diagonal < matrix[r+1][c-1]) right_diagonal = matrix[r+1][c-1];
		r++;
		c--;
		} 
	
	// calc rigth above val on right diagonal
	
	while(check_thesize(r-1) && check_thesize(c+1)){
		if(right_diagonal < matrix[r-1][c+1]) right_diagonal = matrix[r+1][c+1];
		r--;
		c++;
		} 

	
	// calc left below val on left diagonal
	while(check_thesize(r-1) && check_thesize(c-1)){
		if(left_diagonal < matrix[r-1][c-1]) left_diagonal = matrix[r-1][c-1];
		r--;
		c--;
		} 

	
	// calc left below val on left diagonal
	while(check_thesize(r+1) && check_thesize(c+1)){
		if(left_diagonal < matrix[r+1][c+1]) left_diagonal = matrix[r+1][c+1];
		r++;
		c++;
		}

	

	//check the max value ò tãi score
	int max_score = (left_diagonal >= right_diagonal)? left_diagonal : right_diagonal;
	
	
	//check if they can catch the tãi
	//would not catched the taxi
	if(abs(taxi_score) > abs(max_score)){
		EXP1 = ceil(EXP1 - EXP1 * 0.12);
		EXP2 = ceil(EXP2 - EXP2 * 0.12);
		EXP1 = check(EXP1, 0, 600);
		EXP2 = check(EXP2, 0, 600);

		HP1 = ceil(HP1 - HP1 * 0.1);
		HP2 = ceil(HP2 - HP2 * 0.1);
	 	HP1 = check(HP1, 0, 666);
		HP2 = check(HP2, 0, 666);
 		
		return taxi_score;
		}
	//would catch the taxi
	else {
		EXP1 = ceil(EXP1 + EXP1 * 0.12);
		EXP2 = ceil(EXP2 + EXP2 * 0.12);
		EXP1 = check(EXP1, 0, 600);
		EXP2 = check(EXP2, 0, 600);

		HP1 = ceil(HP1 + HP1 * 0.1);
		HP2 = ceil(HP2 + HP2 * 0.1);
	 	HP1 = check(HP1, 0, 666);
		HP2 = check(HP2, 0, 666);
 		
		return max_score;
		}

    return -1;
}

// Task 4

 	bool ifspecialChar(char c){
	return (c == '@' || c == '#' || c == '%' || c == '$' || c == '!');
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

	//get the string before @
	
	int se_length = 0;
	while (email[se_length] != '@') se_length++;
 
	//create substring ò email
	char se_substring[se_length + 1];
	strncpy(se_substring, email, se_length);
	se_substring[se_length] = '\0';
	

	//check the length of pwd
	
	int len = strlen(s);
	if(len < 8) return -1;
	if(len > 20) return -2;
	
	
	//check if string se found in s
	const char* found = strstr(s, se_substring);
    	if(found != nullptr) return -(300 + (found - s));

	//check if s contains more than 2 consecutive and identical characters
	for(int i = 0; i < len - 2; i++){
		if(s[i] == s[i+1] && s[i] == s[i+2]){
		return -(400 + i);
		
		}
	}
	
	//check contain special chẩcters
	bool checkspecialChar = false;
		for(int i = 0; i < len; i++){
		   if (ifspecialChar(s[i])){
		   checkspecialChar = true;
		   break;
		}
	}
	if (!checkspecialChar) return -5;
	
	//check valid char
	for(int i = 0; i < len; i++){
	char c = s[i];
	if (!(isdigit(c) || islower(c) || isupper(c) || ifspecialChar(c) > 0)) {
		return i;
		}
	
	}	
	//check valid pwd

    return -10;

}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
	string pw;
	int num_occurence = 0;
	
	
	for (int i = 0; i < num_pwds; i++){
           int cnt = 1;
           for (int j = i + 1; j < num_pwds; j++){
            if (strcmp(arr_pwds[j], arr_pwds[i]) == 0) cnt++;
        }

        if (cnt > num_occurence){		
            pw = arr_pwds[i];
            num_occurence = cnt;
        }
    	else if(cnt == num_occurence){
	if(pw.size() < strlen(arr_pwds[i])) pw = arr_pwds[i];
	   }
	}

	for (int i = 0; i < num_pwds; i++) 
	{
		if(arr_pwds[i] == pw) return i;
	} 
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////