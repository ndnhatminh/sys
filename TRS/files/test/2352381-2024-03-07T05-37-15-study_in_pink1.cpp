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

//Additional functions
int HP_InRange(float decimalHP){
	int HP = ceil(decimalHP);
	if (HP>666){
		HP = 666;
	}
	if (HP<0){
		HP=0;
	}
	return HP;
}
int EXP_InRange(float decimalEXP){
	int EXP = ceil(decimalEXP);
	if (EXP>600){
		EXP = 600;
	}
	if (EXP<0){
		EXP=0;
	}
	return EXP;
}
int Money_InRange(float decimalM){
	int M = ceil(decimalM);
	if (M>3000){
		M = 3000;
	}
	if (M<0){
		M=0;
	}
	return M;
}

int findMax(int arr[], int n){
	int Max = arr[0]; 
	for (int i=0; i < n; ++i){
		if (Max < arr[i]){
			Max = arr[i];
		}
	}
	return Max;
}

int findSherlockScore(int taxiScore[][10], int i, int j){
	int upperLeft[10]={0};
	int lowerLeft[10]={0};
	int upperRight[10]={0};
	int lowerRight[10]={0};
	for (int k = 0; k + i < 10 && j - k >= 0; ++k){
		lowerLeft[k] = taxiScore[i+k][j-k];
	}
	for (int k = 0; i - k >= 0 && j - k >= 0; ++k){
		upperLeft[k] = taxiScore[i-k][j-k];
	}
	for (int k = 0; i - k >= 0 && k + j < 10; ++k){
		upperRight[k] = taxiScore[i-k][j+k];
	}
	for (int k = 0; k + i < 10 && k + j < 10; ++k){
		lowerRight[k] = taxiScore[i+k][j+k];
	}
	int maxValues[4] = {
        findMax(lowerLeft, 10),
        findMax(upperLeft, 10),
        findMax(upperRight, 10),
        findMax(lowerRight, 10)
    };
    return abs(findMax(maxValues, 4));
}

int return1digit(int num){
	while (num >= 10) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;	
	}
	
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
	//case 1
    if(e1>99||e1<0){
		return -99;
	}
	exp1 = EXP_InRange(exp1);
    exp2 = EXP_InRange(exp2);

	if (e1<=3){
    	switch(e1){
		case 0:
			exp2 +=29;
			break;
		case 1:
			exp2 +=45;
			break;
		case 2:
			exp2 +=75;
			break;
		case 3:
			exp2 +=29+45+75;
			break;
		}
	exp2 = EXP_InRange(exp2);
	int D = e1*3 + exp1*7;
	(D%2==0)?(exp1=EXP_InRange(exp1+D/200.0)):(exp1=EXP_InRange(exp1-D/100.0));	
	exp1 = EXP_InRange(exp1);
	
	
	//case 2
	}else {
		exp1 = EXP_InRange(exp1-e1);
		if (e1<=19){
		exp2 = EXP_InRange(exp2+e1/4.0 +19.0);
	}else if (e1<=49){
		exp2 = EXP_InRange(exp2+e1/9.0 +21.0);
	}else if (e1<=65){
		exp2 = EXP_InRange(exp2+e1/16.0 +17.0);
	}else if (e1<=79){
		exp2 = EXP_InRange(exp2+e1/4.0 +19.0);
		if (exp2>200){
			exp2 = EXP_InRange(exp2+e1/9.0 +21.0);
		}
	}else{
		exp2 = EXP_InRange(exp2+e1/4.0 +19.0);
		exp2 = EXP_InRange(exp2+e1/9.0 +21.0);
		if (exp2>400){
			exp2 = EXP_InRange(exp2+e1/16.0 +17.0);
			exp2 = EXP_InRange(exp2 * 1.15);
		}
	}
	}
	exp1 = EXP_InRange(exp1);
    exp2 = EXP_InRange(exp2);
    return exp1 + exp2;
}
	
	

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
	
	//road 1
	if(E2<0||E2>99){
		return -99;
	}
	HP1 = HP_InRange(HP1);
	EXP1 = EXP_InRange(EXP1);
	M1 = Money_InRange(M1);
	double P1=0;
	int S = pow(round(sqrt(EXP1)),2);
	(EXP1 >= S)?(P1 = 100):(P1 = (static_cast<double>(EXP1)/S+80)/123*100);	
	
	
	//road 2
	//E2 is odd
if (E2%2==1){
	double TempM1 = M1;
	while(M1 * 2.0 >= TempM1){
	//food and beverage
		if (M1 <=0){
	        break;
	    }
		if (HP1<200){
			HP1 = HP_InRange(HP1*1.3); 
			M1-=150;
		}
		else{
			HP1 = HP_InRange(HP1*1.1);
			M1-=70;
		}
		if (M1 * 2.0 < TempM1){
		    break;
		}
	//taxi or carriage
		if (EXP1<400){
			EXP1 = EXP_InRange(EXP1*1.13);
			M1-=200;
		}
		else{
			EXP1 = EXP_InRange(EXP1*1.13);	
			M1-=120;
		}
		if (M1 * 2.0 < TempM1){
		    break;
		}
	//homeless people
	if (EXP1<300){
		EXP1 = EXP_InRange(EXP1*0.9);
		M1-=100;
		}
	else{
		EXP1 = EXP_InRange(EXP1*0.9);	
		M1-=120;
		}
	}
}

	//E2 is even 
else{
	while(M1>0){
	
	//food and beverage
		if (HP1<200){
			HP1 = HP_InRange(HP1*1.3); 
			M1-=150;
		}
		else{
			HP1 = HP_InRange(HP1*1.1);
			M1-=70;
		}
		if (M1 <= 0){
		    break;
		}
	//taxi or carriage
		if (EXP1<400){
			EXP1 = EXP_InRange(EXP1*1.13);
			M1-=200;
		}
		else{
			EXP1 = EXP_InRange(EXP1*1.13);	
			M1-=120;
		}
		if (M1 <= 0){
		    break;
		}
	//homeless people
		if (EXP1<300){
		EXP1 = EXP_InRange(EXP1*0.9);
		M1-=100;
		}
		else{
		EXP1 = EXP_InRange(EXP1*0.9);	
		M1-=120;
		}
	break;
	}
}

	M1 = Money_InRange((float)M1);
	HP1 = HP_InRange(HP1*0.83);
	EXP1 = EXP_InRange(EXP1*1.17);
	//calculate P2 with the same function in road 1
	double P2=0;
	S = pow(round(sqrt(EXP1)),2);
	(EXP1 >= S)?(P2 = 100):(P2 = (static_cast<double>(EXP1)/S+80)/123*100);


	//road 3
	int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
	int i = 0;
	double avgP = 0; 
	if (E2>9){
		int digitSum = (E2/10) + (E2%10);
		i = (digitSum%10);
	}
	else{ 
		i = E2;
	}
	avgP = (P1 + P2 + P[i]) / 3.0;
	if (avgP == 100) {
		EXP1 = EXP_InRange(EXP1*0.75);
	}else if (avgP >=50){
		HP1 = HP_InRange(HP1*0.9);
		EXP1 = EXP_InRange(EXP1*1.2);
	}else{
		HP1 = HP_InRange(HP1*0.85);
		EXP1 = EXP_InRange(EXP1*1.15); 
	}
	return HP1 + EXP1 + M1;
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
	if(E3<0||E3>99){
		return -99;
	}
	HP1 = HP_InRange(HP1);
	EXP1 = EXP_InRange(EXP1);
    HP2 = HP_InRange(HP2);
	EXP2 = EXP_InRange(EXP2);
	const int ROW = 10;
	const int COLUMN = 10;
	int taxiScore[ROW][COLUMN];
	int SherlockScore[ROW][COLUMN];
	int xCoordinate = 0;
	int yCoordinate =0;
	for (int i=0; i < 10; ++i){
		for (int j=0; j < 10; ++j){
			taxiScore[i][j] = 0;
			taxiScore[i][j] = ((E3 * j) + (i * 2)) * (i - j);
			if (taxiScore[i][j] > E3*2){
				++xCoordinate;
			}
			if (taxiScore[i][j] < -E3){
				++yCoordinate;
			}
			
		}
	}
	int x = return1digit(xCoordinate);
	int y = return1digit(yCoordinate);
	for (int i=0; i < 10; ++i){
		for (int j=0; j < 10; ++j){
			SherlockScore[i][j] = 0;
			SherlockScore[i][j] = findSherlockScore(taxiScore,i,j);
		}
	}
	if (abs(taxiScore[x][y])>abs(SherlockScore[x][y])){
		EXP1=EXP_InRange(EXP1*0.88);  EXP2=EXP_InRange(EXP2*0.88);
		HP1=HP_InRange(HP1*0.9);  	  HP2=HP_InRange(HP2*0.9);
	}else{
		EXP1=EXP_InRange(EXP1*1.12);	EXP2=EXP_InRange(EXP2*1.12);
		HP1=HP_InRange(HP1*1.1);		HP2=HP_InRange(HP2*1.1);
	}
    return (abs(taxiScore[x][y])>SherlockScore[x][y])?taxiScore[x][y]:SherlockScore[x][y];
}


// Task 4
int checkPassword(const char * s, const char * email) {
	string se = string(email).substr(0,string(email).find("@"));
	//minimum
	if (strlen(s) < 8){
		return -1;
	}
	//maximum
	if (strlen(s) > 20){
		return -2;
	}
	//contain se
	if (string(s).find(se) != string::npos) {
        return -(300 + string(s).find(se)); 
    }
	//contain more than 2 consecutive and similar elements
	for (int i =0; i < strlen(s)-2; ++i){ 
		if (s[i] == s[i+1] && s[i+1] == s[i+2]) {
            return -(400+i);
        }
	}
	//contain special character
	const char* specialCharacters = "@!%$#";
	const char* ogs = s;
	while (*s) {
        if (strchr(specialCharacters, *s)) {
            break;
        }
        s++;
		if (!*s){
			return-5;
		}
    }
    //function requirements
	// return pointer to beginning of string
   int pos = 0;
   s = ogs;
    while (*s) {
        if (!((*s >= '0' && *s <= '9') ||
            (*s >= 'a' && *s <= 'z') ||
            (*s >= 'A' && *s <= 'Z') ||
    (strchr(specialCharacters, *s) != nullptr))) {
            return pos; 
        }
        ++s;
        ++pos;
    }
    return -10;
}


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
	const int max_pwds = 100;
	int max_occurrences = 0;
    int max_length = 0;
    int max_index = 0;
    int length = 0;
    int occurrences[max_pwds] = {0};
    for (int i = 0; i < num_pwds; i++) { 
        int length = strlen(arr_pwds[i]);
        for (int j = i ; j < num_pwds; j++) {
		 	if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                occurrences[i] ++; 
            }
        }
        if (occurrences[i] > max_occurrences || (occurrences[i] == max_occurrences && length > max_length)) {
            max_occurrences = occurrences[i];
            max_length = length;
            max_index = i;
        }
    }
    for (int i = 0; i < num_pwds; i++) {
        int length = strlen(arr_pwds[i]);
        if (occurrences[i] == max_occurrences && length == max_length) {
            return i; 
        }
    }

    return max_index; 
}
  

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
