#include "study_in_pink1.h"

bool readFile(
	const string& filename,
	int& HP1,
	int& HP2,
	int& EXP1,
	int& EXP2,
	int& M1,
	int& M2,
	int& E1,
	int& E2,
	int& E3
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

//Function used to check HP
void checkHP(double& HP1, double& HP2) {
	// In case the index over limit
	if (HP1 > 666) {
		HP1 = 666;
	}
	else if (HP2 > 666) {
		HP2 = 666;
	}
	if (HP1 < 0) {
		HP1 = 0;
	}
	else if (HP2 < 0) {
		HP2 = 0;
	}
}

//Function used to check EXP
void checkEXP(double& EXP1, double& EXP2) {
	// In case the index over limit
	if (EXP1 > 600) {
		EXP1 = 600;
	}
	else if (EXP2 > 600) {
		EXP2 = 600;
	}
	// In case the index under limit
	else if (EXP1 < 0) {
		EXP1 = 0;
	}
	else if (EXP2 < 0) {
		EXP2 = 0;
	}
}

//Function used to check M
void checkM(double& M1, double& M2) {
	// In case the index over limit
	if (M1 > 3000) {
		M1 = 3000;
	}
	else if (M2 > 3000) {
		M2 = 3000;
	}
	// In case the index under limit
	else if (M1 < 0) {
		M1 = 0;
	}
	else if (M2 < 0) {
		M2 = 0;
	}
}

//Function used to check E
int checkE(int E = 0) {
	if (E > 99 && E < 0) {
		return -99;
	}
	return 0;
}

//Function to round up the index
double roundnum(double& n) {
	int m = n;
	if (n - m != 0) {
		n = m + 1;
	}
	if (n - m == 0) {
		n = m;
	}
	return n;
}

// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {
	// TODO: Complete this function
	//Change the data type from intergers to float numbers
	double exp1 = EXP1, exp2 = EXP2, e1 = E1;
	checkE(e1);
	checkEXP(exp1, exp2);
	int exp = 0, D = 0, type = 0, clue = 0;
	//The first encounter Case 1
	if (e1 == 0) {
		exp2 = exp2 + 29;
		type = 1;
	}
	else if (e1 == 1) {
		exp2 = exp2 + 45;
		type = 1;
	}
	else if (e1 == 2) {
		exp2 = exp2 + 75;
		type = 1;
	}
	else if (e1 == 3) {
		exp2 = exp2 + (29 + 45 + 75);
		type = 1;
	}
	checkEXP(exp1, exp2);
	if (type == 1) {
		D = e1 * 3 + exp1 * 7;
		if (D % 2 == 0) {
			exp1 = exp1 + D / 200;
			roundnum(exp1);
		}
		else if (D % 2 != 0) {
			exp1 = exp1 - (D / 100);
			roundnum(exp1);
		}
	}
	//The first encounter Case 2
	if (4 <= e1 && e1 <= 19) {
		exp2 = exp2 + (e1 / 4 + 19);
		roundnum(exp2);
		type = 2;
		clue = clue + 1;
	}
	if (20 <= e1 && e1 <= 49) {
		exp2 = exp2 + (e1 / 9 + 21);
		roundnum(exp2);
		type = 2;
		clue = clue + 2;
	}
	if (50 <= e1 && e1 <= 65) {
		exp2 = exp2 + (e1 / 16 + 17);
		roundnum(exp2);
		type = 2;
		clue = clue + 3;
	}
	//Special cases which have relation with to previous cases
	if (66 <= e1 && e1 <= 79) {
		exp2 = exp2 + (e1 / 4 + 19);
		roundnum(exp2);
		if (exp2 > 200) {
			exp2 = exp2 + (e1 / 9 + 21);
			roundnum(exp2);
			clue = clue + 2;
		}
		type = 2;
		clue = clue + 1;
	}
	if (80 <= e1 && e1 <= 99) {
		exp2 = exp2 + (e1 / 4 + 19);
		exp2 = exp2 + (e1 / 9 + 21);
		roundnum(exp2);
		if (exp2 > 400) {
			exp2 = exp2 + (e1 / 16 + 17);
			roundnum(exp2);
			clue = clue + 3;
		}
		type = 2;
		clue = clue + 3;
	}
	//Watson is added exp for having all clues
	checkEXP(exp1, exp2);
	if (type == 2 && clue == 6) {
		exp2 = exp2 + (exp2 * 15 / 100);
		roundnum(exp2);
	}
	//Holmes's mistake
	if (type == 2) {
		exp1 = exp1 - e1;
	}
	checkEXP(exp1, exp2);
	EXP1 = exp1;
	EXP2 = exp2;
	E1 = e1;
	return exp1 + exp2;
}

// Task 2
int traceLuggage(int& hp1, int& exp1, int& m1, int E2) {
	// TODO: Complete this function
	//Change the data type from intergers to float numbers
	double EXP1 = exp1, HP1 = hp1, M1 = m1;
	//Assign the the index which don't have in parameters
	double HP2 = 0, EXP2 = 0, M2 = 0;
	checkE(E2);
	checkHP(HP1, HP2);
	checkEXP(EXP1, EXP2);
	checkM(M1, M2);
	//Tracing the luggage Road 1(P)
	//Determine P1
	int S;
	int sqr[30], o = 0, l = 0, o2, l2, omin, lmin;
	double P1;
	for (o = 0; o * o <= EXP1; o++) {
		sqr[o] = o * o;
		l = o + 1;
		omin = EXP1 - o * o;
		lmin = l * l - EXP1;
		o2 = o * o;
		l2 = l * l;
	}
	int ch;
	if (omin <= lmin) {
		S = o2;
		P1 = 1;
		ch = 1;
	}
	else {
		S = l2;
		double EX1 = EXP1;
		P1 = (EX1 / S + 80) / 123;
		ch = 2;
	}
	//Tracing the luggage Road 2(EVENT)
	int M1sta = M1, kind = 0;
	//Check if E2 is an odd or even number
	if (E2 % 2 == 0) {
		kind = 2;
	}
	else {
		kind = 1;
	}
	//Another loop for odd E2
nextloop:
	//Event 1
	if (HP1 < 200) {
		HP1 = HP1 * 1.3;
		M1 = M1 - 150;
		roundnum(HP1);
	}
	else {
		HP1 = HP1 * 1.1;
		roundnum(HP1);
		M1 = M1 - 70;
	}
	checkHP(HP1, HP2);
	checkEXP(EXP1, EXP2);
	checkM(M1, M2);
	//Check for condition of M1 after Event 1
	if (M1 < (0.5 * M1sta) && kind == 1) {
		HP1 = HP1 * 0.83;
		EXP1 = EXP1 * 1.17;
		roundnum(HP1);
		roundnum(EXP1);
		goto outevent;
	}
	if (M1 == 0 && kind == 2) {
		HP1 = HP1 * 0.83;
		EXP1 = EXP1 * 1.17;
		roundnum(HP1);
		roundnum(EXP1);
		goto outevent;
	}
	//Event 2
	if (EXP1 < 400) {
		M1 = M1 - 200;
		EXP1 = EXP1 * 1.13;
		roundnum(EXP1);
	}
	else {
		M1 = M1 - 120;
		EXP1 = EXP1 * 1.13;
		roundnum(EXP1);
	}
	checkHP(HP1, HP2);
	checkEXP(EXP1, EXP2);
	checkM(M1, M2);
	//Check for condition of M1 after Event 2
	if (M1 < (0.5 * M1sta) && kind == 1) {
		HP1 = HP1 * 0.83;
		EXP1 = EXP1 * 1.17;
		roundnum(HP1);
		roundnum(EXP1);
		goto outevent;
	}
	if (M1 == 0 && kind == 2) {
		HP1 = HP1 * 0.83;
		EXP1 = EXP1 * 1.17;
		roundnum(HP1);
		roundnum(EXP1);
		goto outevent;
	}
	//Event 3
	if (EXP1 < 300) {
		M1 = M1 - 100;
		EXP1 = EXP1 * 0.9;
		roundnum(EXP1);
	}
	else {
		M1 = M1 - 120;
		EXP1 = EXP1 * 0.9;
		roundnum(EXP1);
	}
	checkHP(HP1, HP2);
	checkEXP(EXP1, EXP2);
	checkM(M1, M2);
	//Check for condition of M1 after Event 3
	if (M1 < (0.5 * M1sta) && kind == 1) {
		HP1 = HP1 * 0.83;
		EXP1 = EXP1 * 1.17;
		roundnum(HP1);
		roundnum(EXP1);
		goto outevent;
	}
	if (M1 >= (0.5 * M1sta) && kind == 1) {
		goto nextloop;
	}
	if (kind == 2) {
		HP1 = HP1 * 0.83;
		EXP1 = EXP1 * 1.17;
		roundnum(HP1);
		roundnum(EXP1);
		goto outevent;
	}
outevent:
	checkHP(HP1, HP2);
	checkEXP(EXP1, EXP2);
	checkM(M1, M2);
	//Determine P2
	for (o = 0; o * o <= EXP1; o++) {
		sqr[o] = o * o;
		l = o + 1;
		omin = EXP1 - o * o;
		lmin = l * l - EXP1;
		o2 = o * o;
		l2 = l * l;
	}
	double P2;
	if (omin <= lmin) {
		S = o2;
		P2 = 1;
		ch = 1;
	}
	else {
		S = l2;
		double EX2 = EXP1;
		P2 = (EX2 / S + 80) / 123;
		ch = 2;
	}
	//Tracing the luggage Road 3(E2)
	double arrP[20] = { 32,47,28,79,100,50,22,83,64,11 };
	int i = 0;
	double P3;
	if (E2 / 10 == 0) {
		i = E2;
	}
	if (1 <= E2 / 10 && E2 / 10 <= 9) {
		i = (E2 / 10 + E2 % 10) % 10;
	}
	P3 = arrP[i] / 100;
	//Conclusion after 3 roads
	double Ptt;
	if (P1 == 1 && P2 == 1 && P3 == 1) {
		EXP1 = EXP1 * 0.75;
		roundnum(EXP1);
	}
	else {
		Ptt = (P1 + P2 + P3) / 3;
		if (Ptt < 0.5) {
			HP1 = HP1 * 0.85;
			EXP1 = EXP1 * 1.15;
			roundnum(HP1);
			roundnum(EXP1);
		}
		else {
			HP1 = HP1 * 0.9;
			EXP1 = EXP1 * 1.2;
			roundnum(HP1);
			roundnum(EXP1);
		}
	}
	checkHP(HP1, HP2);
	checkEXP(EXP1, EXP2);
	checkM(M1, M2);
	exp1 = EXP1;
	hp1 = HP1;
	m1 = M1;
	return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& hp1, int& exp1, int& hp2, int& exp2, int E3) {
	// TODO: Complete this function
	//Change the data type from intergers to float numbers
	double HP1 = hp1, EXP1 = exp1, HP2 = hp2, EXP2 = exp2;
	checkE(E3);
	checkHP(HP1, HP2);
	checkEXP(EXP1, EXP2);
	//Create a 10x10 matrix with E3
	int minN, maxN, a, b = (9E3 + 18) * -9, matrix[10][10], i = 0, j = 0, x, y, taxi, HandW, big;
	for (int m = 0; m < 10; m++) {
		for (int n = 0; n < 10; n++) {
			a = ((E3 * n) + (m * 2)) * (m - n);
			matrix[m][n] = a;
			if (a > E3 * 2) {
				i = i + 1;
			}
			if (a < -E3) {
				j = j + 1;
			}
		}
	}
	//Find out i and j
	if (i / 10 > 0) {
		i = (i / 10) + (i % 10);
		i = (i / 10) + (i % 10);
	}
	if (j / 10 > 0) {
		j = j / 10 + j % 10;
		j = j / 10 + j % 10;
	}
	taxi = abs(matrix[i][j]);
	//Determine the Holmes and Watson point
	//Digonal line from point to top left
	x = i;
	y = j;
	while (x != 0 && y != 0) {
		x = x - 1;
		y = y - 1;
		if (matrix[x][y] > b) {
			b = matrix[x][y];
		}
	}
	//Digonal line from point to bottom right
	x = i;
	y = j;
	while (x != 9 && y != 9) {
		x = x + 1;
		y = y + 1;
		if (matrix[x][y] > b) {
			b = matrix[x][y];
		}
	}
	//Digonal line from point to top right
	x = i;
	y = j;
	while (x != 0 && y != 9) {
		x = x - 1;
		y = y + 1;
		if (matrix[x][y] > b) {
			b = matrix[x][y];
		}
	}
	//Digonal line from point to bottom left
	x = i;
	y = j;
	while (x != 9 && y != 0) {
		x = x + 1;
		y = y - 1;
		if (matrix[x][y] > b) {
			b = matrix[x][y];
		}
	}
	HandW = abs(b);
	if (taxi > HandW) {
		EXP1 = EXP1 * 0.88;
		HP1 = HP1 * 0.9;
		EXP2 = EXP2 * 0.88;
		HP2 = HP2 * 0.9;
		big = matrix[i][j];
	}
	else {
		EXP1 = EXP1 * 1.12;
		HP1 = HP1 * 1.1;
		EXP2 = EXP2 * 1.12;
		HP2 = HP2 * 1.1;
		big = HandW;
	}
	checkEXP(EXP1, EXP2);
	checkHP(HP1, HP2);
	roundnum(EXP1);
	roundnum(EXP2);
	roundnum(HP1);
	roundnum(HP2);
	hp1 = HP1;
	exp1 = EXP1;
	hp2 = HP2;
	exp2 = EXP2;
	return big;
	return -1;
}

// Task 4
int checkPassword(const char* s, const char* email) {
	// TODO: Complete this function
	int i, n;
	int sei = 0, sci = 0;
	char se[99] = "0", link[99] = "0";
	char* p;
	//Seperate the string email from email
	for (i = 0; i <= strlen(email) - 1; i++) {
		if (email[i] == '@') {
			break;
		}
		se[i] = email[i];
	}
	for (i = 0; i <= strlen(s); i++) {
	}
	//Check for the length of password(s)
	if (strlen(s) < 8) {
		return -1;
	}
	if (strlen(s) > 20) {
		return -2;
	}
	//Check for the duplicate of string email(se) in password(s)
	for (i = 0; i <= strlen(s); i++) {
		if (s[i] == se[0]) {
			sei = i;
			for (n = i; n <= i + strlen(se) - 1; n++) {
				link[n - i] = s[n];
			}
			if (strcmp(link, se) == 0) {
				return -(300 + sei);
			}
			if (strncmp(link, se, 20) == -1) {
				continue;
			}

		}
	}
	//Check for more than 2 duplicated charaters
	for (i = 0; i <= strlen(s) - 2; i++) {
		if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
			sci = i;
			return-(400 + sci);
		}
	}
	//Check for the special character
	for (i = 0; i < strlen(s); i++) {
		if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
			goto next;
		}
	}
	return(-5);
next:
	//Check if the password only have alphabets, numbers or special characters in the list 
	for (i = 0; i <= strlen(s) - 1; i++) {
		if (isalnum(s[i]) || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
			continue;
		}
		else {
			return i;
		}
	}
	return -10;
	return -99;
}

// Task 5
int countPassword(const char* arr_pwds[]) {
	int num_pwds = 0;
	for (int i = 0; i <= 30; i++) {
		if (arr_pwds[i] != NULL) {
			num_pwds++;
		}
	}
	return num_pwds - 1;
}
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
	// TODO: Complete this function
	int length[30] = { 0 }, appear[30] = { 0 }, list[50][50];
	int p = 0, maxappear = 0;
	//Check for the length of passwords 
	for (int i = 0; i <= num_pwds - 1; i++) {
		length[i] = strlen(arr_pwds[i]);
	}
	//Check for the appearances of passwords 
	for (int i = 0; i <= num_pwds - 1; i++) {
		int time = 0;
		for (int n = i; n <= num_pwds - 1; n++) {
			if (strcmp(arr_pwds[i], arr_pwds[n]) == 0) {
				time = time + 1;
			}
		}
		appear[i] = time;
	}
	//Create a list to check the password
	for (int i = 0; i <= num_pwds - 1; i++) {
		//The first column is the times a password appear
		list[i][0] = appear[i];
		//The second column is the length of password
		list[i][1] = length[i];
	}
	//Find out the correct password with list
	for (int i = 0; i <= num_pwds - 1; i++) {
		if (list[i][0] >= maxappear) {
			if (list[i][0] == maxappear) {
				if (list[i][1] > list[p][1]) {
					p = i;
					maxappear = list[p][0];
				}
			}
			else {
				p = i;
				maxappear = list[p][0];
			}
		}
	}
	return p;
	return -1;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
