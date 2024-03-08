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

// Built-in functions
int expChecker(double exp) {
	if (exp < 0) exp = 0;
	else if (exp > 600) exp = 600;
	else exp = ceil(exp - 0.00001);
	return exp;
}

int hpChecker(double hp) {
	if (hp < 0) hp = 0;
	else if (hp > 666) hp = 666;
	else hp = ceil(hp - 0.00001);
	return hp;
}

int moneyChecker(double money) {
	if (money < 0) money = 0;
	else if (money > 3000) money = 3000;
	else money = ceil(money - 0.00001);
	return money;
}

// // Some testing functions
// void leftDiagCoor(int & a, int & b, int x, int y) {
// 	a = x - min(x, y);
// 	b = y - min(x, y);
// }

// void rightDiagCoor(int & a, int & b, int x, int y, int cols) {
// 	a = ((x + y > cols - 1) ? (x + y - cols + 1) : 0);
// 	b = ((x + y > cols - 1) ? (cols - 1) : (x + y));
// }

// Task 1 - Done
int firstMeet(int & exp1, int & exp2, int e1) {
	// TODO: Complete this function
	
	if (!(e1 >= 0 && e1 <= 99)) {
		return -99;
	}

	exp1 = expChecker(exp1);
	exp2 = expChecker(exp2);

	if (e1 >= 0 && e1 <= 3) {
		// expChecker() is in the end of these 4 conditions
		if (e1 == 0) exp2 += 29;
		else if (e1 == 1) exp2 += 45;
		else if (e1 == 2) exp2 += 75;
		else if (e1 == 3) exp2 += (29 + 45 + 75);
		
		exp2 = expChecker(exp2); // it's here

		int D = e1 * 3 + exp1 * 7;

		if (D % 2 == 0) {
			exp1 = expChecker(exp1 + D / 200.0);
		}
		else exp1 = expChecker(exp1 - D / 100.0);
	}

	else {
		if (e1 >= 4 && e1 <= 19) exp2 = expChecker(exp2 + e1 / 4.0 + 19);
		else if (e1 >= 20 && e1 <= 49) exp2 = expChecker(exp2 + e1 / 9.0 + 21);
		else if (e1 >= 50 && e1 <= 65) exp2 = expChecker(exp2 + e1 / 16.0 + 17);
		else if (e1 >= 66 && e1 <= 79) {
			exp2 = expChecker(exp2 + e1 / 4.0 + 19);
			
			if (exp2 > 200) {
				exp2 = expChecker(exp2 + e1 / 9.0 + 21);
			}
		}
		// Maximum 3 info
		else {
			exp2 = expChecker(exp2 + e1 / 4.0 + 19);
			exp2 = expChecker(exp2 + e1 / 9.0 + 21);

			if (exp2 > 400) {
				exp2 = expChecker(exp2 + e1 / 16.0 + 17);
				exp2 = expChecker(1.15 * exp2);
			}
		}

		exp1 = expChecker(exp1 - e1);
	}

	return exp1 + exp2;
}

// Task 2 - Done
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
	// TODO: Complete this function

	if (!(E2 >= 0 && E2 <= 99)) {
		return -99;
	}

	HP1 = hpChecker(HP1);
	EXP1 = expChecker(EXP1);
	M1 = moneyChecker(M1);

	// Road 01
	double S = pow(round(sqrt(EXP1)), 2);
	double P1 = (EXP1 >= S) ? 1 : (((EXP1 / S) + 80.0) / 123.0);

	// // Case 2
	// double squareRoot = sqrt(EXP1);
	// int roundedNum = round(squareRoot);
	// int S = roundedNum * roundedNum; // S is the nearest perfect square

	// if (EXP1 >= S) P1 = 1;
	// else double P1 = (EXP1 / static_cast<double>(S) + 80) / 123.0;
	// -----------------------------------------------------------

	// Road 02
	int totalMoney = M1;

	do {
		// Section 1
		if (totalMoney == 0) break;

		if (HP1 < 200) {
			HP1 = hpChecker(1.3 * HP1);
			M1 = moneyChecker(M1 - 150);
		}
		else {
			HP1 = hpChecker(1.1 * HP1);
			M1 = moneyChecker(M1 - 70);
		}
		
		if (((E2 % 2 == 0) && (M1 == 0)) || ((E2 % 2 != 0) && (M1 < totalMoney / 2.0))) break;

		// Section 2
		if (EXP1 < 400) M1 = moneyChecker(M1 - 200);
		else M1 = moneyChecker(M1 - 120);

		EXP1 = expChecker(1.13 * EXP1);

		if (((E2 % 2 == 0) && (M1 == 0)) || ((E2 % 2 != 0) && (M1 < totalMoney / 2.0))) break;

		// Section 3
		if (EXP1 < 300) {
			int m = 100;
			M1 = moneyChecker(M1 - m);
		}
		else {
			int m = 120;
			M1 = moneyChecker(M1 - m);
		}

		EXP1 = expChecker(0.9 * EXP1);

		if (((E2 % 2 == 0) && (M1 == 0)) || ((E2 % 2 != 0) && (M1 < totalMoney / 2.0))) break;
	} while (E2 % 2 != 0);

	HP1 = hpChecker(0.83 * HP1);
	EXP1 = expChecker(1.17 * EXP1);

	S = pow(round(sqrt(EXP1)), 2);
	double P2 = (EXP1 >= S) ? 1 : (((EXP1 / S) + 80.0) / 123.0);

	// Road 03
	double P3[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

	int i = (E2 % 10 + E2 / 10) % 10;

	if (P1 != 1 || P2 != 1 || P3[i]/100.0 != 1) {
		double avg = (P1 + P2 + P3[i]/100.0) / 3.0;
		if (avg < 0.5) {
			HP1 = hpChecker(0.85 * HP1);
			EXP1 = expChecker(1.15 * EXP1);
		}
		else {
			HP1 = hpChecker(0.9 * HP1);
			EXP1 = expChecker(1.2 * EXP1);
		}
	}
	else {
		EXP1 = expChecker(0.75 * EXP1);
	}

	return HP1 + EXP1 + M1;
}

// Task 3 - Done
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
	// TODO: Complete this function

	if (!(E3 >= 0 && E3 <= 99)) {
		return -99;
	}
	
	HP1 = hpChecker(HP1);
	HP2 = hpChecker(HP2);
	EXP1 = expChecker(EXP1);
	EXP2 = expChecker(EXP2);

	// Generate Taxi's scoreboard
	const int ROWS = 10, COLS = 10;
	int taxiScore[ROWS][COLS];

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			taxiScore[i][j] = 0;
		}
	}

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			taxiScore[i][j] = ((E3 * j) + (i * 2)) * (i - j);
		}
	}

	// Meeting point

	// Explain goes here:
	// I notice that in a square matrix, the difference between the sum of rows and columns values is equal along the main diagonal
	// Also, the sum of row and column values will be equal along the other diagonal
	// Of course, you can also use 4 while loops and run along the 4 diagonal directions of the matrix from Sherlock's coordinates
	// Such as: left up, left down, right up, right down.

	int greaterAmount = 0, smallerAmount = 0;
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			greaterAmount = (taxiScore[i][j] > (E3 * 2)) ? greaterAmount + 1 : greaterAmount;
			smallerAmount = (taxiScore[i][j] < - E3) ? smallerAmount + 1 : smallerAmount;
		}
	}

	int meetingRow = (greaterAmount % 10 + greaterAmount / 10) % 10 + (greaterAmount % 10 + greaterAmount / 10) / 10;
	int meetingCol = (smallerAmount % 10 + smallerAmount / 10) % 10 + (smallerAmount % 10 + smallerAmount / 10) / 10;

	int maxLeftDiagonal = 0, maxRightDiagonal = 0;

	int a = meetingRow - min(meetingRow, meetingCol);
	int b = meetingCol - min(meetingRow, meetingCol);
	while (true) {
		maxLeftDiagonal = (maxLeftDiagonal < taxiScore[a][b]) ? taxiScore[a][b] : maxLeftDiagonal;
		if (a == ROWS - 1 || b == COLS - 1) break;
		a++;
		b++;
	}

	a = ((meetingRow + meetingCol > COLS - 1) ? (meetingRow + meetingCol - COLS + 1) : 0);
	b = ((meetingRow + meetingCol > COLS - 1) ? (COLS - 1) : (meetingRow + meetingCol));
	while (true) {
		maxRightDiagonal = (maxRightDiagonal < taxiScore[a][b]) ? taxiScore[a][b] : maxRightDiagonal;
		if (a == ROWS - 1 || b == 0) break;
		a++;
		b--;
	}

	int SherWatScore = max(maxRightDiagonal, maxLeftDiagonal);

	if (abs(taxiScore[meetingRow][meetingCol]) > SherWatScore) {
		HP1 = hpChecker(HP1 * 0.9);
		EXP1 = expChecker(EXP1 * 0.88);
		HP2 = hpChecker(HP2 * 0.9);
		EXP2 = expChecker(EXP2 * 0.88);
	}
	else {
		HP1 = hpChecker(HP1 * 1.1);
		EXP1 = expChecker(EXP1 * 1.12);
		HP2 = hpChecker(HP2 * 1.1);
		EXP2 = expChecker(EXP2 * 1.12);
	}

	return (SherWatScore >= abs(taxiScore[meetingRow][meetingCol])) ? SherWatScore : taxiScore[meetingRow][meetingCol];
}

// Task 4 - Done... Right ?
int checkPassword(const char * s, const char * email) {
	// TODO: Complete this function
	
	string se = "";
	int i = 0;

	// The pointer is like uhm... the array...
	// So for example *(email + 1) is like email[1]
	while ( *(email + i) != '@') {
		se += *(email + i);
		i++;
	}

	if (strlen(s) >= 8 && strlen(s) <= 20) {
		int charCounter = 0, specCharCounter = 0, consecCharCounter = 1, elseCasePointer = -1;
		bool normalCase;
		
		if (se == "") return -300;

		while (*(s + charCounter) != 0) { // 0 is null character '\0' in the ASCII code
			if (*(s + charCounter) == se[0]) {
				int matchCharCounter = 0;

				for (int i = 0; i < se.length(); ++i) {
					if (se[i] != *(s + charCounter + i)) break;
					else {
						matchCharCounter++;
						
						if (matchCharCounter == se.length()) return -(300 + charCounter);
					}
				}
			}
			charCounter++;
		}

		charCounter = 0;

		while (*(s + charCounter) != 0) { // 0 is null character '\0' in the ASCII code	
			if ((charCounter >= 1) && (*(s + charCounter) == *(s + charCounter - 1))) {
				consecCharCounter++;

				if (consecCharCounter == 3) return -(400 + charCounter - 2); // 3rd location - 2 = 1st location
			}
			else consecCharCounter = 1;
			
			normalCase = (islower(*(s + charCounter)) || isupper(*(s + charCounter)) || isdigit(*(s + charCounter)));

			if ((*(s + charCounter) == '@') || (*(s + charCounter) == '#') || (*(s + charCounter) == '%') || (*(s + charCounter) == '$') || (*(s + charCounter) == '!')) {
				specCharCounter++;
			}
			else if (!normalCase && (elseCasePointer == -1)) {
				elseCasePointer = charCounter;
			}

			charCounter++;
		}

		if (specCharCounter == 0) return -5;
		if (elseCasePointer != -1) return elseCasePointer;
	}

	else {  
		if (strlen(s) < 8) return -1;
		else return -2;
	}

	return -10;
}

// Task 5 - Done... I think so,...
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
	// TODO: Complete this function

	const int SIZE = num_pwds;
	int countArr[SIZE];
	int countOccur, firstAppearIndex = 0, maxAppearTime = 0;
	string cloneArr[SIZE];

	for (int i = 0; i < SIZE; i++) {
		countArr[i] = 0;
		cloneArr[i] = arr_pwds[i];
	}

	for (int i = 0; i < SIZE; i++) {
		countOccur = 0;

		for (int j = 0; j < SIZE; j++) {
			if ((cloneArr[i] == cloneArr[j]) && (i <= j)) {
				countOccur++;
			}

			else if ((cloneArr[i] == cloneArr[j]) && (i > j)) {
				countOccur = 0;
				break;
			}
		}
		countArr[i] = countOccur;
	}

	for (int i = 0; i < SIZE; i++) {
		if (countArr[i] > maxAppearTime) {
			firstAppearIndex = i;
			maxAppearTime = countArr[i];
		}
		else if ((countArr[i] == maxAppearTime) && (cloneArr[i].length() > cloneArr[firstAppearIndex].length())) {
			firstAppearIndex = i;
		}
	}
	return firstAppearIndex;
}

// last time checked: 15:17 06/03/2024

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////