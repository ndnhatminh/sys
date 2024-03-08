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


int checkdata(int data, int minvalue, int maxvalue) {
    data = (data < minvalue) ? minvalue : (data > maxvalue) ? maxvalue : data;
    return data;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    
    // Check if the score exceeds the maximum or minimum allowed!
    if (e1 < 0 || e1 > 99) return -99;
    exp1 = checkdata(exp1, 0, 600);
    exp2 = checkdata(exp2, 0, 600);
// Case 1
    switch (e1) {
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
			exp2 = exp2 + 29 + 45 + 75; 
			break;
		default: break;
	}
	if (e1 >= 0 && e1 <= 3) {
		exp2 = checkdata(exp2, 0, 600);
    
    	int D = e1 * 3 + exp1 * 7;
    	if (D % 2 == 0) exp1 = ceil(float(exp1 + (double)D/200));
    	else exp1 = ceil(float(exp1 - (double)D/100));
    	exp1 = checkdata(exp1, 0, 600);
	}	
	
	// Case 2
	if (e1 >= 4 && e1 <= 99) {
		if (e1 >= 4 && e1 <= 19) exp2 += ceil(float((double)e1/4)) + 19;
		else if (e1 >= 20 && e1 <= 49) exp2 += ceil(float((double)e1/9)) + 21;
		else if (e1 >= 50 && e1 <= 65) exp2 += ceil(float((double)e1/16)) + 17;
		else if (e1 >= 66 && e1 <= 79) {
			exp2 += ceil(float((double)e1/4)) + 19;
			if (exp2 > 200) exp2 += ceil(float((double)e1/9)) + 21; 
		}
		else if (e1 >= 80 && e1 <= 99) {
			exp2 += ceil(float((double)e1/4)) + 19 + ceil(float((double)e1/9)) + 21;
			if (exp2 > 400) {
				exp2 += ceil(float((double)e1/16 + 17));
				exp2 += ceil(float((double)exp2 * 0.15));
			}
		}
		exp2 = checkdata(exp2, 0, 600);
		exp1 = checkdata(exp1-e1, 0, 600);
	}	
	
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    
    if (E2 < 0 || E2 > 99) return -99;
    HP1 = checkdata(HP1, 0, 666);
    EXP1 = checkdata(EXP1, 0, 600);
    M1 = checkdata(M1, 0, 3000);
    double p1, p2, p3;
    double money = 0, target_money = M1/2;
    int event = 0;
    
    // Road 01
	int sqrnum1 = (int(sqrt(EXP1)+0.5))*(int(sqrt(EXP1)+0.5));
	if (EXP1 >= sqrnum1) p1 = 1.00;
	else p1 = ((double)EXP1/sqrnum1 + 80) / 123;
	
	// Road 02
	while (money <= target_money) {	
		if (event % 3 == 0) {
			if (HP1 < 200) {
				HP1 = ceil(float((double)HP1 * 1.3));
				M1 -= 150;
				money += 150;
			} else {
				HP1 = ceil(float((double)HP1 * 1.1));
				M1 -= 70;
				money += 70;
			}
			M1 = checkdata(M1, 0, 3000);
			HP1 = checkdata(HP1, 0, 666);
			if ((M1 == 0) && (E2 % 2 == 0)) break;
		}
		
		if (event % 3 == 1) {
			if (EXP1 < 400) {
				M1 -= 200;
				money += 200;
			}
			else {
				M1 -= 120;
				money += 120;
			} 
			EXP1 = ceil(float((double)EXP1 * 1.13));
			M1 = checkdata(M1, 0, 3000);
			EXP1 = checkdata(EXP1, 0, 600);
			if ((M1 == 0) && (E2 % 2 == 0)) break;
		}
	
		if (event % 3 == 2) {
			if (EXP1 < 300) {
				M1 -= 100;
				money += 100;
			}
			else {
				M1 -= 120;
				money += 120;
				EXP1 = ceil(float((double)EXP1 * 0.9));
			}
			M1 = checkdata(M1, 0, 3000);
			EXP1 = checkdata(EXP1, 0, 600);
			if ((M1 == 0) && (E2 % 2 == 0)) break;
		}
		if ((E2 % 2 == 0) && (event == 2)) break;
		event++;
	}	
	HP1 = ceil(float((double)HP1 * 0.83));
	EXP1 = ceil(float((double)EXP1 * 1.17));
	
	M1 = checkdata(M1, 0, 3000);
	HP1 = checkdata(HP1, 0, 666);
	EXP1 = checkdata(EXP1, 0, 600);
	
	int sqrnum2 = (int(sqrt(EXP1)+0.5))*(int(sqrt(EXP1)+0.5));
	if (EXP1 >= sqrnum2) p2 = 1.00;
	else p2 = ((double)EXP1/sqrnum2 + 80) / 123;
	
	// Road 03
	int prob3[10] = {32,47,28,79,100,50,22,83,64,11};
	if (E2 >= 10) {
		int i = ((E2 / 10) + (E2 % 10)) % 10;
		p3 = (double)prob3[i] / 100;
	}
	else p3 = (double)prob3[E2] / 100;
	
	// After 3 Roads
	if (p1 == 1.00 && p2 == 1.00 && p3 == 1.00) EXP1 = ceil(float((double)EXP1 * 0.75));
	else if (((double)(p1 + p2 + p3) / 3) < 0.5) {
		HP1 = ceil(float((double)HP1 * 0.85));
		EXP1 = ceil(float((double)EXP1 * 1.15));
	}
	else {
		HP1 = ceil(float((double)HP1 * 0.9));
		EXP1 = ceil(float((double)EXP1 * 1.2));
	}
	HP1 = checkdata(HP1, 0, 666);
	EXP1 = checkdata(EXP1, 0, 600);
	
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
	
    if (E3 < 0 || E3 > 99) return -99;
    HP1 = checkdata(HP1, 0, 666);
    EXP1 = checkdata(EXP1, 0, 600);
    HP2 = checkdata(HP2, 0, 666);
    EXP2 = checkdata(EXP2, 0, 600);
    
    int taxi[10][10];
    int pvalue = 0, nvalue = 0;
    for (int i = 0; i < 10; i++) {
    	for (int j = 0; j < 10; j++) {
    		taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
    		if (taxi[i][j] > (E3 * 2)) pvalue++;
    		else if (taxi[i][j] < (-E3)) nvalue++;
		}
	}
	
	pvalue = (pvalue / 10) + (pvalue % 10);
	pvalue = (pvalue / 10) + (pvalue % 10);
	nvalue = (nvalue / 10) + (nvalue % 10);
	nvalue = (nvalue / 10) + (nvalue % 10);
	
	int maxtaxivalue = 0;
    for (int i = 0; i < 10; i++) {
    	for (int j = 0; j < 10; j++) {
			if ((i + j) == (pvalue + nvalue) || (i + j) == (pvalue - nvalue)) {
				if (maxtaxivalue <= taxi[i][j]) maxtaxivalue = taxi[i][j];
			}
		}
	}
	
	if (abs(taxi[pvalue][nvalue]) <= maxtaxivalue) {
		EXP1 = ceil(float((double)EXP1 * 1.12)); HP1 = ceil(float((double)HP1 * 1.1));
		EXP2 = ceil(float((double)EXP2 * 1.12)); HP2 = ceil(float((double)HP2 * 1.1));
		HP1 = checkdata(HP1, 0, 666);
    	EXP1 = checkdata(EXP1, 0, 600);
    	HP2 = checkdata(HP2, 0, 666);
    	EXP2 = checkdata(EXP2, 0, 600);
    	
    	return maxtaxivalue;
	}
	else {
		EXP1 = ceil(float((double)EXP1 * 0.88)); HP1 = ceil(float((double)HP1 * 0.9));
		EXP2 = ceil(float((double)EXP2 * 0.88)); HP2 = ceil(float((double)HP2 * 0.9));
		HP1 = checkdata(HP1, 0, 666);
    	EXP1 = checkdata(EXP1, 0, 600);
    	HP2 = checkdata(HP2, 0, 666);
    	EXP2 = checkdata(EXP2, 0, 600);
    	
    	return taxi[pvalue][nvalue];
	}
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string pass(s);
    string mail(email);
    string se = mail.substr(0, mail.find("@"));
    
    if (pass.length() < 8 ) return -1;
    if (pass.length() > 20) return -2;
    if ((int)pass.find(se) != -1) return -(300 + (int)pass.find(se));
    for (int i = 0; i < pass.length() - 1; i++) {
    	if ((pass[i] == pass[i+1]) && (pass[i+1] == pass[i+2])) return -(400 + i);
	}
	if ((int)pass.find("@") == -1 && (int)pass.find("#") == -1 && (int)pass.find("%") == -1 && (int)pass.find("$") == -1 && (int)pass.find("!") == -1) return -5;
	for (int i = 0; i < pass.length(); i++) {
		char pass_letter = pass[i];
		switch (pass_letter) {
			case 0 ... 32: case 34: case 38 ... 47: case 58 ... 64: case 91 ... 96: case 123 ... 127:
				return i;
			default: 
				continue;	
		}	
	}
	return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
	
	int freq = 0;
	int maxpos = 0;
	string word;
	
	for (int i = 0; i < num_pwds; i++) {
		int count5 = 1;
		string pwd = arr_pwds[i];
		for (int j = i + 1; j < num_pwds; j++) {
			if (arr_pwds[j] == arr_pwds[i]) count5++;
		}
		if (count5 == freq) {
			if (word.length() < pwd.length()) {
				word = arr_pwds[i];
            	freq = count5;
            	maxpos = i;
			}
		}
		if (count5 > freq) {
            word = arr_pwds[i];
            freq = count5;
            maxpos = i;
        }
		
	}
    return maxpos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
