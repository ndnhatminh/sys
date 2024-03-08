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
/// STUDE:NT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
//additional function
int OddOrEven(int num){ // 1 if Odd 0 if Even
	if (num % 2 != 0){
		return 1;
	}else{
		return 0;
	}
}
void checkHP(int & hp){
	if (hp<0){
		hp = 0;
	}
	if (hp>666){
		hp=666;
	}	
}
void checkEXP(int & exp){
	if (exp<0){
		exp = 0;
	}
	if (exp>600){
		exp =600;
	}
}
void checkMN(int & Mn){
	if (Mn<0){
		Mn = 0;
	}
	if (Mn>3000){
		Mn = 3000;
	}
}
float FindP(int num) {
	int a = sqrt(num);
	if (a * a == num) {
		return 100;
	}
	else {
		if ((ceil(sqrt(num)) - sqrt(num)) > (sqrt(num) - (ceil(sqrt(num)) - 1))) {
			return 100;
		}
		else return ((num / (ceil(sqrt(num))*ceil(sqrt(num))) + 80) / 123)*100;
	}
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    if((e1<=99) && (e1>=0)){
    checkEXP(exp1);
    checkEXP(exp2);
// Case1
    	if (e1<4) {
    	    	switch(e1){
			case 0:{exp2 +=29; break;} 
			case 1:{exp2 +=45; break;}
			case 2:{exp2 +=75; break;}
			case 3:{exp2 = exp2 + 29 + 45 + 75; break;}
    		}
		checkEXP(exp2);
		int D;
    		D = e1*3 +exp1*7;
	
		if (OddOrEven(D)==1) {
			exp1 = ceil(exp1 - D/100.0);
		}else{
			exp1 = ceil(exp1 + D/200.0);
		}
		checkEXP(exp1);
//case2
	}else{
		if((e1>3)&&(e1<20)){
			exp2 += ceil(e1/4.0+19);
		}
		if ((e1>19)&&(e1<50)){
			exp2 += ceil(e1/9.0+21);
		}
		if((e1>49)&&(e1<66)){
			exp2 += ceil(e1/16.0+17);		
		}
		if((e1>65)&&(e1<80)){
			exp2 += ceil(e1/4.0+19);
			if(exp2>200){
				exp2 += ceil(e1/9.0+21);	
			}
		}
		if(e1>79){
			exp2 += ceil(e1/4.0+19);
			exp2 += ceil(e1/9.0+21);
			if(exp2>400){
				exp2 += ceil(e1/16.0+17);
				exp2 =exp2 +ceil(exp2*15/100.0);
			}

		}
		exp1 -=e1;
		checkEXP(exp1);
		checkEXP(exp2);
	}

    return exp1 + exp2;

    }else
    {
        
	    return -99;
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if((E2<100)&&(E2>=0)){
    	//Path1
    checkEXP(EXP1);
    checkHP(HP1);
    checkMN(M1);
	float P1 =FindP(EXP1);

	//Path2
	int M0 = M1;
	
	if (OddOrEven(E2)==1){
		for(int loan = 0; ; ){
            if (M0==0) break;
			//Event1
			if (HP1<200){
				
				HP1 = ceil(HP1 + HP1*30/100.0);
				M1 = M1 - 150;
				loan += 150;
			}else{
				HP1 = ceil(HP1 + HP1*10/100.0);
				M1 = M1 - 70;
				loan += 70;
			}
			checkHP(HP1);
			checkMN(M1);
			if (loan>M0*50/100.0) break;

			//Event2
			if (EXP1<400) {
				M1 = M1 -200;
				EXP1 = ceil(EXP1 + EXP1*13/100.0);
				loan += 200;
			}else {
				M1 = M1 -120;
				EXP1 = ceil(EXP1 +EXP1*13/100.0);
				loan += 120;
			}
			checkMN(M1);
			checkEXP(EXP1);
			if (loan>M0*50/100.0) break;

			//Event3
			if (EXP1<300) {
				M1 = M1 -100;
				EXP1 = ceil(EXP1 - EXP1*10/100.0);
				loan += 100;
			}else {
				M1 = M1 -120;
				EXP1 = ceil(EXP1 - EXP1*10/100.0);
				loan += 120;
			}
			checkMN(M1);
			checkEXP(EXP1);
			if (loan>M0*50/100.0) break;
		}
	}else{
		for (int i=0;i<1;i++){
            if (M0==0) break;
            int loan = 0;
			if (HP1<200){
				
				HP1 = ceil(HP1 + HP1*30/100.0);
				M1 = M1 - 150;
				loan += 150;
			}else{
				HP1 = ceil(HP1 + HP1*10/100.0);
				M1 = M1 - 70;
				loan += 70;
			}
			checkHP(HP1);
			checkMN(M1);
			if (M1==0) break;

			//Event2
			if (EXP1<400) {
				M1 = M1 -200;
				EXP1 = ceil(EXP1 + EXP1*13/100.0);
				loan += 200;
			}else {
				M1 = M1 -120;
				EXP1 = ceil(EXP1 +EXP1*13/100.0);
				loan += 120;
			}
			checkMN(M1);
			checkEXP(EXP1);
			if (M1==0) break;
			//Event3
			if (EXP1<300) {
				M1 = M1 -100;
				EXP1 = ceil(EXP1 - EXP1*10/100.0);
				loan += 100;
			}else {
				M1 = M1 -120;
				EXP1 = ceil(EXP1 - EXP1*10/100.0);
				loan += 120;
			}
			checkMN(M1);
			checkEXP(EXP1);
			if (M1==0) break;
		}
	}
	HP1 = ceil(HP1 - HP1*17/100.0);
	EXP1 = ceil(EXP1 + EXP1*17/100.0);
	checkEXP(EXP1);
	checkHP(HP1);

	float P2 = FindP(EXP1);
	//Path 3
	float P3 = 0;
	int P[10] = {32,47,28,79,100,50,22,83,64,11};
	if (E2>9){
		int index1 = (E2/10 + E2%10)%10;
		P3 = P[index1];
	}else P3 = P[E2];
	//maintraceluggage
	if ((P1==100) && (P2==100) && (P3 ==100)){
		EXP1 = ceil(EXP1 - EXP1*25/100.0);
		checkEXP(EXP1);
	}else {
		float avgP = (P1+P2+P3)/3;
		if(avgP<50){
			HP1 = ceil(HP1 -HP1*15/100.0);
			EXP1 = ceil(EXP1 + EXP1*15/100.0);

		}else{
			HP1 =ceil(HP1 - HP1*10/100.0);
			EXP1 = ceil(EXP1 + EXP1*20/100.0);
		}
	}
	checkEXP(EXP1);
	checkHP(HP1);
    return HP1 + EXP1 + M1;

}else{
    return -99;
}
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
	// TODO: Complete this function
	if ((E3 <= 99) && (E3 >= 0)) {
		checkEXP(EXP1);
		checkEXP(EXP2);
		checkHP(HP1);
		checkHP(HP2);
		//Matrix car
		int Car[10][10] = {};

		//create value of Car
		for (int i = 0; i <= 9; ++i) {
			for (int j = 0; j <= 9; ++j) {
				Car[i][j] = ((E3 * j) + (i * 2)) * (i - j);
			}
		}
		
		//find the X(i,j)
		int counti = 0;
		int countj = 0;
		for (int i = 0; i <= 9; ++i) {
			for (int j = 0; j <= 9; ++j) {
				if (Car[i][j] > (E3 * 2)) counti = counti + 1;
				if (Car[i][j] < (0 - E3)) countj = countj + 1;
			}
		}
		
		if (counti > 9) {
			counti = (counti / 10 + counti % 10) ;
		}
		if (counti > 9) {
			counti = (counti / 10 + counti % 10);
		}
		if (countj > 9) {
			countj = (countj / 10 + countj % 10);
		}
		if (countj > 9) {
			countj = (countj / 10 + countj % 10);
		}
		
		
		int pointWS = 0;
		int i1 = counti;
		int j1 = countj;
		for (;;) {
			
			if (pointWS < Car[i1][j1]) {
				pointWS = Car[i1][j1];
			}
			i1 = i1 - 1;
			j1 = j1 - 1;
			if (i1 < 0) break;
			if (j1 < 0) break;
		}
		i1 = counti;
		j1 = countj;
		for (;;) {
			
			if (pointWS < Car[i1][j1]) {
				pointWS = Car[i1][j1];
			}
			i1 = i1 - 1;
			j1 = j1 + 1;
			if (i1 < 0) break;
			if (j1 > 9) break;
		}
		i1 = counti;
		j1 = countj;
		for (;;) {
			
			if (pointWS < Car[i1][j1]) {
				pointWS = Car[i1][j1];
			}
			i1 = i1 + 1;
			j1 = j1 - 1;
			if (i1 > 9) break;
			if (j1 < 0) break;
		}
		i1 = counti;
		j1 = countj;
		for (;;) {
			
			if (pointWS < Car[i1][j1]) {
				pointWS = Car[i1][j1];
			}
			i1 = i1 + 1;
			j1 = j1 + 1;
			if (i1 > 9) break;
			if (j1 > 9) break;
		}
		if (abs(Car[counti][countj]) > pointWS) {
			EXP1 = ceil(EXP1 - EXP1 * 12 / 100.0);
			EXP2 = ceil(EXP2 - EXP2 * 12 / 100.0);
			HP1 = ceil(HP1 - HP1 * 10 / 100.0);
			HP2 = ceil(HP2 - HP2 * 10 / 100.0);
			checkEXP(EXP1);
		    	checkEXP(EXP2);
		    	checkHP(HP1);
		    	checkHP(HP2);
			return Car[counti][countj];
		}
		else {
			EXP1 = ceil(EXP1 + EXP1 * 12 / 100.0);
			EXP2 = ceil(EXP2 + EXP2 * 12 / 100.0);
			HP1 = ceil(HP1 + HP1 * 10 / 100.0);
			HP2 = ceil(HP2 + HP2 * 10 / 100.0);
			checkEXP(EXP1);
		    	checkEXP(EXP2);
		    	checkHP(HP1);
		    	checkHP(HP2);
			return pointWS;
		}
			}
	else {
		return -99;
	}
}
// Task 4
int checkPassword(const char* s, const char* email) {
	// TODO: Complete this function
	// find length of s
	int sizes = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		sizes++;
	}
	//cut email se

	char se[99] = {};
	for (int i = 0; email[i] != '@'; i++) {
		se[i] = email[i];
	}
	// find Length of email
	int sizeemail = 0;

	for (int i = 0; se[i] != '\0'; i++) {
		sizeemail++;
	}
	if (sizes < 8) return -1;
	if (sizes > 20) return -2;

	for (int i = 0; i <= sizes - sizeemail; i++) {
		int flag = 0;
		for (int j = 0; j <= sizeemail; j++) {
			if (s[i + j] != se[j]) {
				flag = 0;
				break;
			}
			flag++;
			if (flag == sizeemail) {
				flag = i;
				return 0-(300 + flag);
			}
		}
	}
	for (int i = 0; i <= sizes - 3; i++) {
		if ((s[i] == s[i + 1]) && (s[i + 1] == s[i + 2])) {
			return 0-(400 + i);
		}
	}
	int flagSymbol = 0;

	for (int i = 0; i <= sizes-1; ++i) {
		if ((s[i]=='@') ||(s[i]=='%') ||(s[i]=='#')||(s[i]=='$')||(s[i]=='!')){
            flagSymbol++;
        }
	}
    if (flagSymbol == 0) return -5;
	
    for (int i = 0; i <= sizes-1; ++i) {
		
			    if( ((s[i]>=97) && (s[i]<=122)) || ((s[i]>=65) && (s[i]<=90)) || ((s[i]>=48) && (s[i]<=57)) ||(s[i]=='@') ||(s[i]=='%') ||(s[i]=='#')||(s[i]=='$')||(s[i]=='!')){
		    } else return i;
        
	}
	
		return -10;
}
//task5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
	num_pwds = num_pwds - 1;
	// TODO: Complete this function
		// create array count password 
	int countvalue[100] = {0};
	for (int i = 0; i <= num_pwds; i++) {
		 countvalue[i] = 0;
	}
	//create flag that password had count
	int flag[100] = {0};
	for (int i = 0; i <= num_pwds; i++) {
		flag[i] = 0;
	}

	for (int i = 0; i <= num_pwds; i++) {
		for (int j = i + 1; j <= num_pwds; j++) {
			if (flag[i] == 1) break;
			else
				if (strcmp(arr_pwds[i], arr_pwds[j])==0) {
					countvalue[i]++;
					flag[j] = 1;
					arr_pwds[j] = "\0";
                    
				}
		}


	}
	// count most show password
	int max = 0;
	int value = 0;
	int maxstring = 0;
	
	for (int i = 0; i <= num_pwds; i++) {
		if (max < countvalue[i]) {
			max = countvalue[i];
		}
	}
	string a[100] = {"\0"};
	for (int i = 0; i <= num_pwds; i++) {
		a[i] = arr_pwds[i];
	}
	
	
	for (int i = 0; i <= num_pwds; i++) {
		if (max == countvalue[i]) {
			int lengthstring = a[i].length();
			if (maxstring < lengthstring) {
				maxstring = lengthstring;
				value = i;
			}
		}
	}
	return value;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
