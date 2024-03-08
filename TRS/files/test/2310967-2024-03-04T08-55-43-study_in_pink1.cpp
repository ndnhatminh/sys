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

// Task 1
float checkinput(float a, float firstindex, float lastindex) {
	if (a < firstindex) {
		a = firstindex;
	}
	else if (a > lastindex) {
		a = lastindex;
	}
	return a;
}
// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {
	int firstexp = 0;
	int lastexp = 600;
	// Check the input
	if (E1 < 0 || E1 > 99)
		return -99;

	const int information1_case1 = 29, information2_case1 = 45, information3_case1 = 75;
	float information1_case2, information2_case2, information3_case2;
	information1_case2 = (float)E1 / 4 + 19;
	information2_case2 = (float)E1 / 9 + 21;
	information3_case2 = (float)E1 / 16 + 17;
	float EXP1_temp = EXP1;
	float EXP2_temp = EXP2;
	int information;
	if (E1 <= 3) {
		int D = (E1 * 3 + EXP1 * 7);
		if (E1 == 0) EXP2_temp += information1_case1;
		if (E1 == 1) EXP2_temp += information2_case1;
		if (E1 == 2) EXP2_temp += information3_case1;
		if (E1 == 3) EXP2_temp += information1_case1 + information3_case1 + information2_case1;
		if ((D % 2) == 0) {
			EXP1_temp = (EXP1_temp + D / 200.0);
			EXP1_temp = ceilf(EXP1_temp);
		}
		else {
			EXP1_temp = (EXP1_temp - D / 100);
			EXP1_temp = ceilf(EXP1_temp);
		}
		EXP1 = EXP1_temp;
		EXP2 = EXP2_temp;
	}
	else {
		if (4 <= E1 && E1 <= 19) information = 1;
		else if (20 <= E1 && E1 <= 49) information = 2;
		else if (50 <= E1 && E1 <= 65) information = 3;
		else if (66 <= E1 && E1 <= 79) information = 4;
		else if (80 <= E1 && E1 <= 99) information = 5;
		switch (information) {
		case 1:
		{
			EXP2_temp = ceilf(EXP2_temp + information1_case2);
			EXP2_temp = checkinput(EXP2_temp, firstexp, lastexp);
			break;
		}
		case 2:
		{
			EXP2_temp = ceilf(EXP2_temp + information2_case2);
			EXP2_temp = checkinput(EXP2_temp, firstexp, lastexp);
			break;
		}
		case 3:
		{
			EXP2_temp = ceilf(EXP2_temp + information3_case2);
			EXP2_temp = checkinput(EXP2_temp, firstexp, lastexp);
			break;
		}
		case 4:
		{
			EXP2_temp = ceilf(EXP2_temp + information1_case2);
			EXP2_temp = checkinput(EXP2_temp, firstexp, lastexp);
			if (EXP2_temp > 200)
				EXP2_temp = ceilf(EXP2_temp + information2_case2);
			EXP2_temp = checkinput(EXP2_temp, firstexp, lastexp);
			break;
		}
		case 5:
		{
			EXP2_temp = ceilf(EXP2_temp + information1_case2);
			EXP2_temp = checkinput(EXP2_temp, firstexp, lastexp);
			EXP2_temp = ceilf(EXP2_temp + information2_case2);
			EXP2_temp = checkinput(EXP2_temp, firstexp, lastexp);
			if (EXP2_temp > 400) {
				EXP2_temp = ceilf(EXP2_temp + information3_case2);
				EXP2_temp = checkinput(EXP2_temp, firstexp, lastexp);
				EXP2_temp = ceilf(EXP2_temp * 1.15);
				EXP2_temp = checkinput(EXP2_temp, firstexp, lastexp);

			}
			break;
		}
		}
		EXP1_temp = ceilf(EXP1_temp - E1);
		EXP1 = EXP1_temp;
	}
	//check the result
	EXP1 = checkinput(EXP1_temp, firstexp, lastexp);
	EXP2 = checkinput(EXP2_temp, firstexp, lastexp);
	return EXP1 + EXP2;
}

// Task 2
double Probability(double EXP1) {
	double P1;
	int S = round(sqrt(EXP1)) * round(sqrt(EXP1));
	if (EXP1 >= S)
		P1 = 1.00;
	else
		P1 = (EXP1 / S + 80) / 123;
	return P1;
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
	int firstexp = 0;
	int lastexp = 600;
	int firstHP = 0;
	int lastHP = 666;
	int firstM = 0;
	int lastM = 3000;
	int half_initial_money = 0.50 * M1;
	double P1, P2, P3;
	double P_average;
	int EXP1_temp = EXP1;

	// Check the input
	if (E2 < 0 || E2 > 99)
		return -99;
	//secondway
	int HP1_temp = HP1;
	int M1_temp = M1;
	int expend = 0;
	//con duong 1
	P1 = Probability(EXP1);
	//con duong 2
	if ((E2 % 2) != 0) {
		while (1 == 1) {
			HP1_temp = checkinput(HP1_temp, firstHP, lastHP);
			if (HP1_temp < 200) {
				HP1_temp = ceilf(1.3 * HP1_temp);
				HP1_temp = checkinput(HP1_temp, firstHP, lastHP);
				M1_temp = M1_temp - 150;
				M1_temp = checkinput(M1_temp, firstM, lastM);
				expend += 150;
			}
			else {
				HP1_temp = ceilf(1.1 * HP1_temp);
				HP1_temp = checkinput(HP1_temp, firstHP, lastHP);
				M1_temp = M1_temp - 70;
				M1_temp = checkinput(M1_temp, firstM, lastM);
				expend += 70;
			}
			if (expend > half_initial_money)
				break;
			if (EXP1_temp < 400) {
				M1_temp -= 200;
				M1_temp = checkinput(M1_temp, firstM, lastM);
				expend += 200;
			}
			else {
				M1_temp -= 120;
				M1_temp = checkinput(M1_temp, firstM, lastM);
				expend += 120;
			}
			EXP1_temp = ceilf(EXP1_temp * 1.13);
			EXP1_temp = checkinput(EXP1_temp, firstexp, lastexp);
			if (expend > half_initial_money)
				break;
			if (EXP1_temp < 300) {
				M1_temp -= 100;
				M1_temp = checkinput(M1_temp, firstM, lastM);
				expend += 100;
			}
			else
			{
				M1_temp -= 120;
				M1_temp = checkinput(M1_temp, firstM, lastM);
				expend += 120;
			}
			EXP1_temp = ceilf(0.9 * EXP1_temp);
			EXP1_temp = checkinput(EXP1_temp, firstexp, lastexp);
			if (expend > half_initial_money)
				break;

		}
	}
	else if ((E2 % 2) == 0) {
		for (int i = 0; i < 1; i++) {
			if (HP1_temp < 200) {
				HP1_temp = ceilf(1.3 * HP1_temp);
				HP1_temp = checkinput(HP1_temp, firstHP, lastHP);
				M1_temp = M1_temp - 150;
				M1_temp = checkinput(M1_temp, firstM, lastM);
			}
			else {
				HP1_temp = ceilf(1.1 * HP1_temp);
				HP1_temp = checkinput(HP1_temp, firstHP, lastHP);
				M1_temp = M1_temp - 70;
				M1_temp = checkinput(M1_temp, firstM, lastM);
			}
			if (M1_temp == 0)
				break;
			if (EXP1_temp < 400) {
				M1_temp -= 200;
				M1_temp = checkinput(M1_temp, firstM, lastM);
			}
			else {
				M1_temp -= 120;
				M1_temp = checkinput(M1_temp, firstM, lastM);
			}
			EXP1_temp = ceilf(EXP1_temp * 1.13);
			EXP1_temp = checkinput(EXP1_temp, firstexp, lastexp);
			if (M1_temp == 0)
				break;

			if (EXP1_temp < 300) {
				M1_temp -= 100;
				M1_temp = checkinput(M1_temp, firstM, lastM);
			}
			else {
				M1_temp -= 120;
				M1_temp = checkinput(M1_temp, firstM, lastM);
			}
			EXP1_temp = ceilf(0.9 * EXP1_temp);
			EXP1_temp = checkinput(EXP1_temp, firstexp, lastexp);
			if (M1_temp == 0)
				break;
		}
	}
	HP1_temp = ceilf(0.83 * HP1_temp);
	HP1_temp = checkinput(HP1_temp, firstHP, lastHP);
	EXP1_temp = ceilf(1.17 * EXP1_temp);
	EXP1_temp = checkinput(EXP1_temp, firstexp, lastexp);
	P2 = Probability(EXP1_temp);
	M1_temp = ceilf(M1_temp);
	M1 = checkinput(M1_temp, firstM, lastM);
	//con duong 3
	int i;
	float P[10] = { 0.32, 0.47, 0.28, 0.79, 1.0, 0.5, 0.22, 0.83, 0.64, 0.11 };
	if (E2 < 10) {
		i = E2;
		P3 = P[i];
	}
	if (E2 >= 10) {
		int sum = E2 / 10 + E2 % 10;
		i = sum % 10;
		P3 = P[i];
	}
	P_average = (P1 + P2 + P3) / 3;
	if (P_average == 1.0) {
		EXP1_temp = ceilf(0.75 * EXP1_temp);
	}
	else {
		if (P_average < 0.5) {
			HP1_temp = ceilf(0.85 * HP1_temp);
			EXP1_temp = ceilf(1.15 * EXP1_temp);
		}
		else {
			HP1_temp = ceilf(0.9 * HP1_temp);
			EXP1_temp = ceilf(1.2 * EXP1_temp);
		}


	}
	HP1 = checkinput(HP1_temp, firstHP, lastHP);
	EXP1 = checkinput(EXP1_temp, firstexp, lastexp);
	return HP1 + EXP1 + M1;
}

// Task 3
int Maxvalue(int x, int y, int E3) {
	int diagonal[19] = {};
	int count = 0;
	int matrix[10][10] = { 0 };
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
		}
	}


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (x > y) {
				if ((i - j == x - y) || (i + j == x + y)) {
					diagonal[count] = matrix[i][j];
					count++;
				}
			}
			else if (x < y) {
				if ((j - i == y - x) || (i + j == x + y)) {

					diagonal[count] = matrix[i][j];
					count++;
				}
			}
			else if (x == y) {
				if ((i - j == 0) || (i + j == x + y)) {
					diagonal[count] = matrix[i][j];
					count++;
				}
			}
		}
	}
	int max = diagonal[0];
	for (int i = 1; i < 19; i++) {
		if (diagonal[i] > max)
			max = diagonal[i];
	}
	return max;
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
	float firstexp = 0;
	float lastexp = 600;
	float firstHP = 0;
	float lastHP = 666;
	int count = 0;
	int count_i = 0;
	int count_j = 0;
	int i;
	int j;
	int sum_i, sum_j;
	float EXP1_temp = EXP1;
	float EXP2_temp = EXP2;
	float HP1_temp = HP1;
	float HP2_temp = HP2;
	if (E3 < 0 || E3 > 99)
		return -99;
	int matrix[10][10] = { 0 };
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (matrix[i][j] > (2 * E3))
				count_i++;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (matrix[i][j] < (-E3))
				count_j++;
		}
	}
	if (count_i < 10)
		i = count_i;
	else {
		sum_i = count_i / 10 + count_i % 10;
		if (sum_i < 10)
			i = sum_i;
		else
			i = sum_i / 10 + sum_i % 10;
	}
	if (count_j < 10)
		j = count_j;
	else {
		sum_j = count_j / 10 + count_j % 10;
		if (sum_j < 10)
			j = sum_j;
		else
			j = sum_j / 10 + sum_j % 10;
	}
	int pointPerson = Maxvalue(i, j, E3);
	if (abs(matrix[i][j]) > abs(pointPerson)) {
		EXP1_temp = (0.88 * EXP1);
		EXP1_temp = ceilf(EXP1_temp);
		EXP1 = checkinput(EXP1_temp, firstexp, lastexp);
		HP1_temp = (0.9 * HP1);
		HP1_temp = ceilf(HP1_temp);
		HP1 = checkinput(HP1_temp, firstHP, lastHP);
		EXP2_temp = (0.88 * EXP2);
		EXP2_temp = ceilf(EXP2_temp);
		EXP2 = checkinput(EXP2_temp, firstexp, lastexp);
		HP2_temp = (0.9 * HP2);
		HP2_temp = ceilf(HP2_temp);
		HP2 = checkinput(HP2_temp, firstHP, lastHP);
		return matrix[i][j];
	}
	else {
		EXP1_temp = (1.12 * EXP1);
		EXP1_temp = ceilf(EXP1_temp);
		EXP1 = checkinput(EXP1_temp, firstexp, lastexp);
		HP1_temp = (1.10 * HP1);
		HP1_temp = ceilf(HP1_temp);
		HP1 = checkinput(HP1_temp, firstHP, lastHP);
		EXP2_temp = (1.12 * EXP2);
		EXP2_temp = ceilf(EXP2_temp);
		EXP2 = checkinput(EXP2_temp, firstexp, lastexp);
		HP2_temp = (1.1 * HP2);
		HP2_temp = ceilf(HP2_temp);
		HP2 = checkinput(HP2_temp, firstHP, lastHP);
		return abs(pointPerson);

	}
}

// Task 4
int checkPassword(const char* s, const char* email) {
	string se = "";
	int n = strlen(email);
	const char* alphabet = "1234567890asdfghjklzxcvbnmqwertyuiopASDFGHJKLZXCVBNMQWERTYUIOP@#$%!";
	int size_of_al = strlen(alphabet);
	for (int i = 0; i < n; i++) {
		if (email[i] == '@') {
			break;
		}
		se += email[i];
	}
	int size_of_s = strlen(s);
	int count = 0;
	int position = 0;
	if (size_of_s < 8) {
		return -1;
	}
	if (size_of_s > 20) {
		return -2;
	}
	if (size_of_s >= 8 && size_of_s <= 20) {
		for (int i = 0; i < size_of_s; i++) {
			if (strncmp(s + i, se.c_str(), se.length()) == 0) {
				count++;
				if (position == 0) {
					position = i;
				}
				if (count >= 1) {
					return -(300 + (position));
				}
			}
		}
		for (int i = 0; i < size_of_s - 2; i++) {
			if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
				return -(400 + i);
			}
		}
		if (strpbrk(s, "@#$%!") == NULL) {
			return -5;
		}
		for (int i = 0; i < size_of_s; i++) {
			bool found = false;
			for (int j = 0; j < size_of_al; j++) {
				if (s[i] == alphabet[j]) {
					found = true;
					break;
				}
			}
			if (!found) {
				return i;
			}
		}
	}
	return -10;
}
// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
	int maxIndex = 0;
	int maxCount = 0;
	int maxLength = 0;

	for (int i = 0; i < num_pwds; i++) {
		int currentCount = 1;
		int currentLength = strlen(arr_pwds[i]);

		for (int j = i + 1; j < num_pwds; j++) {
			if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
				currentCount++;
			}
		}

		if (currentCount > maxCount || (currentCount == maxCount && currentLength > maxLength)) {
			maxIndex = i;
			maxCount = currentCount;
			maxLength = currentLength;
		}
	}

	return maxIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////