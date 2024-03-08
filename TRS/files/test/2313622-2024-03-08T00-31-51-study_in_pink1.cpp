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

// making sure that 0 <= HP <= 666, 0 <= EXP <= 600, 0 <= M <= 3000
void checkHp(int& hp) {
	if (hp > 666) hp = 666;
	if (hp < 0) hp = 0;
}
void checkExp(int& exp) {
	if (exp > 600) exp = 600;
	if (exp < 0) exp = 0;
}
void checkM(int& m) {
	if (m > 3000) m = 3000;
	if (m < 0) m = 0;
}

int improvedCeil(double num) { // ceil function that turn numbers like 6.000000001 to 6 instead of 7
	double tolerance = 1e-9;
	if (num - floor(num) <= tolerance) {
		return floor(num);
	}
	else {
		return ceil(num);
	}
}


// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
	if (e1 < 0 || e1 > 99) { // E1 out of bound
		return -99;
	}

	checkExp(exp1);
	checkExp(exp2);

	if (e1 <= 3) { // E1 in [0;3]
		switch (e1)
		{
		case 0:
			exp2 += 29; // info 1
			break;
		case 1:
			exp2 += 45; // info 2
			break;
		case 2:
			exp2 += 75; // info 3
			break;
		case 3:
			exp2 += (29 + 45 + 75); // all there info
			break;

		default:
			break;
		}

		int d = e1 * 3 + exp1 * 7;
		exp1 = (d % 2 == 0) ? improvedCeil(exp1 + d / 200.0) : improvedCeil(exp1 - d / 100.0);
	}
	else { // E1 in [4;99]
		if (e1 <= 19) {
			exp2 = improvedCeil(exp2 + e1 / 4.0 + 19); // info 1
		}
		else if (e1 <= 49) {
			exp2 = improvedCeil(exp2 + e1 / 9.0 + 21); // info 2
		}
		else if (e1 <= 65) {
			exp2 = improvedCeil(exp2 + e1 / 16.0 + 17); // info 3
		}
		else if (e1 <= 79) {
			exp2 = improvedCeil(exp2 + e1 / 4.0 + 19); // info 1
			checkExp(exp2);
			if (exp2 > 200) exp2 = improvedCeil(exp2 + e1 / 9.0 + 21); // info 2
		}
		else {
			exp2 = improvedCeil(exp2 + e1 / 4.0 + 19); // info 1
			checkExp(exp2);
			exp2 = improvedCeil(exp2 + e1 / 9.0 + 21); // info 2
			checkExp(exp2);
			if (exp2 > 400) {
				exp2 = improvedCeil(exp2 + e1 / 16.0 + 17); // info 3
				checkExp(exp2);
				exp2 = improvedCeil(1.15 * exp2); // Sherlock explain all there info
			}
		}
		exp1 -= e1; // Harry is Watson's sister, not his brother
	}

	checkExp(exp1);
	checkExp(exp2);

	return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
	if (E2 < 0 || E2 > 99) { // E2 out of bound
		return -99;
	}

	checkHp(HP1);
	checkExp(EXP1);
	checkM(M1);

	double p1{ 0 }, p2{ 0 }, p3{ 0 }; // probabilities of road 1, 2, 3

	// Road 01
	int n = sqrt(EXP1); // largest integer n whose square is not larger than EXP1
	// n^2 <= EXP1 < (n+1)^2
	p1 = (EXP1 - pow(n, 2) < pow(n + 1, 2) - EXP1) ? 100
		: (static_cast<double>(EXP1) / pow(n + 1, 2) + 80) / 1.23;

	// Road 02
	int startMoney{ M1 };

	while (M1 != 0) { 
		// event 1
		if (HP1 < 200) {
			HP1 = improvedCeil(1.3 * HP1);
			M1 -= 150;
		}
		else {
			HP1 = improvedCeil(1.1 * HP1);
			M1 -= 70;
		}

		checkHp(HP1);
		checkM(M1);

		// Sherlock stops if he has no money left and E2 is even 
		if (E2 % 2 == 0 && M1 == 0) break;
		// Sherlock stops if total cost is larger than 50% of start money and E2 is odd 
		if (E2 % 2 != 0 && startMoney - M1 > 0.5 * startMoney) break;

		// event 2
		if (EXP1 < 400) {
			M1 -= 200;
		}
		else {
			M1 -= 120;
		}

		EXP1 = improvedCeil(1.13 * EXP1); 

		checkExp(EXP1);
		checkM(M1);

		if (E2 % 2 == 0 && M1 == 0) break;
		if (E2 % 2 != 0 && startMoney - M1 > 0.5 * startMoney) break;

		// event 3
		if (EXP1 < 300) {
			M1 -= 100;
		}
		else {
			M1 -= 120;
		}

		EXP1 = improvedCeil(0.9 * EXP1); 

		checkExp(EXP1);
		checkM(M1);

		if (E2 % 2 == 0) break;
		if (E2 % 2 != 0 && startMoney - M1 > 0.5 * startMoney) break;
	}

	HP1 = improvedCeil(0.83 * HP1);
	EXP1 = improvedCeil(1.17 * EXP1);

	checkHp(HP1);
	checkExp(EXP1);

	n = sqrt(EXP1); // same formular as road 01
	p2 = (EXP1 - pow(n, 2) < pow(n + 1, 2) - EXP1) ? 100
		: (static_cast<double>(EXP1) / pow(n + 1, 2) + 80) / 1.23;

	// Road 03
	int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
	// If E2 is a one-digit number, that value is the value of i. If E2 is a 2-digit
	// number, calculate the sum of those 2 digits and take the number of the unit place of this total
	// value as the value for i.
	int i = (E2 - 9 * (E2 / 10)) % 10;
	p3 = P[i];

	if (p1 == 100 && p2 == 100 && p3 == 100) {
		EXP1 = improvedCeil(0.75 * EXP1);
	}
	else if ((p1 + p2 + p3) / 3 < 50) { // the average probability is less than 50
		HP1 = improvedCeil(0.85 * HP1);
		EXP1 = improvedCeil(1.15 * EXP1);
	}
	else {
		HP1 = improvedCeil(0.9 * HP1);
		EXP1 = improvedCeil(1.2 * EXP1);
	}

	checkHp(HP1);
	checkExp(EXP1);

	return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
	if (E3 < 0 || E3 > 99) { // E3 out of bound
		return -99;
	}

	checkHp(HP1);
	checkHp(HP2);
	checkExp(EXP1);
	checkExp(EXP2);

	int matrix[10][10] = { 0 };
	int iCount{ 0 }, jCount{ 0 }; // the (i,j) position where Sherlock meets the taxi
	for (int i{ 0 }; i < 10; i++) {
		for (int j{ 0 }; j < 10; j++) {
			matrix[i][j] = (E3 * j + i * 2) * (i - j); // taxi's score at point (i,j)
			if (matrix[i][j] > E3 * 2) iCount++;
			else if (matrix[i][j] < -E3) jCount++;
		}
	}

	while (iCount >= 10) { // add two digits of number until it become a one digit number
		iCount = iCount % 10 + iCount / 10;
	}
	while (jCount >= 10) {
		jCount = jCount % 10 + jCount / 10;
	}

	int maxScore{ matrix[iCount][jCount] }; // the max score on the 2 diagonals from the meeting point
	int row{ iCount }, column{ jCount }; // index of elements on the diagonals

	while (row >= 0 && column >= 0) { // left diagonal
		if (matrix[row][column] > maxScore) maxScore = matrix[row][column];
		row--;
		column--;
	}

	row = iCount;
	column = jCount;

	while (row <= 9 && column <= 9) { // left diagonal
		if (matrix[row][column] > maxScore) maxScore = matrix[row][column];
		row++;
		column++;
	}

	row = iCount;
	column = jCount;

	while (row >= 0 && column <= 9) { // right diagonal
		if (matrix[row][column] > maxScore) maxScore = matrix[row][column];
		row--;
		column++;
	}

	row = iCount;
	column = jCount;

	while (row <= 9 && column >= 0) { // right diagonal
		if (matrix[row][column] > maxScore) maxScore = matrix[row][column];
		row++;
		column--;
	}

	if (abs(matrix[iCount][jCount]) > maxScore) { // if taxi's score is larger than Sherlock's
		EXP1 = improvedCeil(0.88 * EXP1);
		EXP2 = improvedCeil(0.88 * EXP2);
		HP1 = improvedCeil(0.9 * HP1);
		HP2 = improvedCeil(0.9 * HP2);

		checkHp(HP1);
		checkHp(HP2);
		checkExp(EXP1);
		checkExp(EXP2);

		return matrix[iCount][jCount];
	}
	else {
		EXP1 = improvedCeil(1.12 * EXP1);
		EXP2 = improvedCeil(1.12 * EXP2);
		HP1 = improvedCeil(1.1 * HP1);
		HP2 = improvedCeil(1.1 * HP2);

		checkHp(HP1);
		checkHp(HP2);
		checkExp(EXP1);
		checkExp(EXP2);

		return maxScore;
	}
}

// Task 4
int checkPassword(const char* s, const char* email) {
	int sLength = strlen(s); // password's length

	if (sLength < 8) { // password is too short
		return -1;
	}
	if (sLength > 20) { // password is too long
		return -2;
	}

	char se[100]{}; // the part of email before '@'
	int index{ 0 };
	while (email[index] != '@') {
		if (email[index] == '\0') {
			return -999;
		}
		se[index] = email[index];
		index++;
	}
	se[index] = '\0'; // null terminated

	const char* substring = strstr(s, se); // point to se in password
	if (substring != nullptr) { // if se is in password
		return -(300 + substring - s);
	}

	char* special = nullptr; // find special character in password
	char specialList[] = "!@#$%"; // list of allowed special characters
	int specialChar{ 0 }, illegalChar{ -1 }; // keep track of special and illegal characters

	for (int i{ 0 }; i < sLength; i++) {
		if (i <= sLength - 3) {
			if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) { // character rapeated 3 times consecutively
				return -(400 + i);
			}
		}

		special = strchr(specialList, s[i]); // check if character s[i] is a special character in the list
		if (special != nullptr) {
			specialChar++;
		}
		else if (illegalChar == -1 &&
			!(s[i] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122 || s[i] >= 48 && s[i] <= 57)) {
			illegalChar = i; // first character that is not allowed
		}
	}

	if (specialChar == 0) {
		return -5;
	}
	if (illegalChar != -1) {
		return illegalChar;
	}

	return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
	struct Record // record each unique password's first appearence and number of appearence
	{
		int firstIndex;
		int amount;
	};

	bool newPassword = true; // check if a password has already appeared before
	Record passwords[100]{};
	int passwordCount{ 0 }; // number of elements in passwords[] array

	for (int i{ 0 }; i < num_pwds; i++) {
		newPassword = true; // potential new password

		for (int j{ 0 }; j < passwordCount; j++) { // check if num_pwds[i] has appeared in passwords[]
			if (strcmp(arr_pwds[i], arr_pwds[passwords[j].firstIndex]) == 0) {
				passwords[j].amount++;
				newPassword = false; // not a new password
				break;
			}
		}

		if (newPassword) { // update new password to password[]
			passwordCount++;
			passwords[passwordCount - 1].firstIndex = i;
			passwords[passwordCount - 1].amount = 1;
		}
	}

	int mostFrequent{ 0 }; // find the largest passwords[i].amount
	for (int i{ 0 }; i < passwordCount; i++) {
		if (mostFrequent < passwords[i].amount) {
			mostFrequent = passwords[i].amount;
		}
	}

	int longestPasswordIndex{ 0 }, longestPasswordLength{ 0 }; // find the longest password within the most frequent passwords
	for (int i{ 0 }; i < passwordCount; i++) {
		if (passwords[i].amount == mostFrequent && 
			strlen(arr_pwds[passwords[i].firstIndex]) > longestPasswordLength) {
			longestPasswordLength = strlen(arr_pwds[passwords[i].firstIndex]);
			longestPasswordIndex = i;
		}
	}

	return passwords[longestPasswordIndex].firstIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////