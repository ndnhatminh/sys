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

void setHP(int &hp, int value) {
	if (value < 0)
		hp = 0;
	else if (value > 666)
		hp = 666;
	else hp = value;
}

void setEXP(int &exp, int value) {
	if (value < 0)
		exp = 0;
	else if (value > 600)
		exp = 600;
	else exp = value;
}

void setMoney(int &m, int value) {
	if (value < 0)
		m = 0;
	else if (value > 3000)
		m = 3000;
	else m = value;
}

int calc(int value, int percent) {
	return (value * percent + 99) / 100;
}

bool equalString(const char *s1, const char *s2) {
	int idx = 0;
	while (s1[idx] && s2[idx]) {
		if (s1[idx] != s2[idx])
			return false;
		idx++;
	}

	if (s1[idx] || s2[idx])
		return false;
	else return true;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
	// TODO: Complete this function

	if (0 <= e1 && e1 <= 3) {
		if (e1 == 0) setEXP(exp2, exp2 + 29);
		else if (e1 == 1) setEXP(exp2, exp2 + 45);
		else if (e1 == 2) setEXP(exp2, exp2 + 75);
		else setEXP(exp2, exp2 + 29 + 45 + 75);

		int D = e1 * 3 + exp1 * 7;
		if (D % 2 == 0) setEXP(exp1, exp1 + D / 200);
		else setEXP(exp1, (exp1 * 100 - D + 99) / 100);
	}
	else if (4 <= e1 && e1 <= 99) {
		if (4 <= e1 && e1 <= 19) setEXP(exp2, exp2 + (e1 + 3) / 4 + 19);
		else if (20 <= e1 && e1 <= 49) setEXP(exp2, exp2 + (e1 + 8) / 9 + 21);
		else if (50 <= e1 && e1 <= 65) setEXP(exp2, exp2 + (e1 + 15) / 16 + 17);
		else if (66 <= e1 && e1 <= 79) {
			setEXP(exp2, exp2 + (e1 + 3) / 4 + 19);
			if (exp2 > 200)
				setEXP(exp2, exp2 + (e1 + 8) / 9 + 21);
		}
		else {
			setEXP(exp2, exp2 + (e1 + 3) / 4 + 19);
			setEXP(exp2, exp2 + (e1 + 8) / 9 + 21);
			if (exp2 > 400) {
				setEXP(exp2, exp2 + (e1 + 15) / 16 + 17);
				setEXP(exp2, calc(exp2, 115));
			}
		}

		setEXP(exp1, exp1 - e1);
	}
	else return -99;

	return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
	// TODO: Complete this function

	if (E2 < 0 || E2 > 99) return -99;

	//route 01
	int s1 = (int)sqrt(EXP1);
	int S1 = abs(s1 * s1 - EXP1) < abs((s1 + 1) * (s1 + 1) - EXP1) ? (s1 * s1) : ((s1 + 1) * (s1 + 1));
	int EX1 = EXP1;
	float P1 = EX1 >= S1 ? 1.0 : (((float)EX1 / (float)S1 + 80) / 123);

	//route 02
	int initialMoney = M1;
	while (true) {
		//first
		if (HP1 < 200) {
			setHP(HP1, calc(HP1, 130));
			setMoney(M1, M1 - 150);
		}
		else {
			setHP(HP1, calc(HP1, 110));
			setMoney(M1, M1 - 70);
		}

		if (E2 % 2 == 1) {
			if (M1 * 2 < initialMoney) break;
		}
		else {
			if (M1 == 0) break;
		}

		//second
		if (EXP1 < 400) setMoney(M1, M1 - 200);
		else setMoney(M1, M1 - 120);
		setEXP(EXP1, calc(EXP1, 113));

		if (E2 % 2 == 1) {
			if (M1 * 2 < initialMoney) break;
		}
		else {
			if (M1 == 0) break;
		}

		//third
		if (EXP1 < 300) setMoney(M1, M1 - 100);
		else setMoney(M1, M1 - 120);
		setEXP(EXP1, calc(EXP1, 90));

		if (E2 % 2 == 1) {
			if (M1 * 2 < initialMoney) break;
		}
		else {
			if (M1 == 0) break;
		}

		if (E2 % 2 == 0) break;
	}

	setHP(HP1, calc(HP1, 83));
	setEXP(EXP1, calc(EXP1, 117));

	int s2 = (int)sqrt(EXP1);
	int S2 = abs(s2 * s2 - EXP1) < abs((s2 + 1) * (s2 + 1) - EXP1) ? (s2 * s2) : ((s2 + 1) * (s2 + 1));
	int EX2 = EXP1;
	float P2 = EX2 >= S2 ? 1.0 : (((float)EX2 / (float)S2 + 80) / 123);

	//route 3
	int arr[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
	int P3;
	if (E2 < 10)
		P3 = arr[E2];
	else P3 = arr[(E2 / 10 + E2 % 10) % 10];

	if (EX1 >= S1 && EX2 >= S2 && P3 == 100)
		setEXP(EXP1, (EXP1 * 75 + 99) / 100);
	else {
		float P = (P1 + P2 + P3 / 100.0f) / 3;
		if (P < 0.5) {
			setHP(HP1, calc(HP1, 85));
			setEXP(EXP1, calc(EXP1, 115));
		}
		else {
			setHP(HP1, calc(HP1, 90));
			setEXP(EXP1, calc(EXP1, 120));
		}
	}

	return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
	// TODO: Complete this function

	if (E3 < 0 || E3 > 99) return -99;

	int mat[10][10];
	int row = 0, col = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			mat[i][j] = ((E3 * j) + (i * 2)) * (i - j);

			if (mat[i][j] > E3 * 2) row++;
			if (mat[i][j] < -E3) col++;
		}
	}

	while (row >= 10) row = row / 10 + row % 10;
	while (col >= 10) col = col / 10 + col % 10;

	int max_point = mat[row][col];
	int r, c;

	r = row;
	c = col;
	while (true) {
		r += 1;
		c += 1;
		if (r < 0 || r >= 10 || c < 0 || c >= 10) break;
		if (mat[r][c] > max_point)
			max_point = mat[r][c];
	}

	r = row;
	c = col;
	while (true) {
		r -= 1;
		c += 1;
		if (r < 0 || r >= 10 || c < 0 || c >= 10) break;
		if (mat[r][c] > max_point)
			max_point = mat[r][c];
	}

	r = row;
	c = col;
	while (true) {
		r -= 1;
		c -= 1;
		if (r < 0 || r >= 10 || c < 0 || c >= 10) break;
		if (mat[r][c] > max_point)
			max_point = mat[r][c];
	}

	r = row;
	c = col;
	while (true) {
		r += 1;
		c -= 1;
		if (r < 0 || r >= 10 || c < 0 || c >= 10) break;
		if (mat[r][c] > max_point)
			max_point = mat[r][c];
	}

	max_point = abs(max_point);

	if (abs(mat[row][col]) > max_point) {
		setHP(HP1, calc(HP1, 90));
		setHP(HP2, calc(HP2, 90));

		setEXP(EXP1, calc(EXP1, 88));
		setEXP(EXP2, calc(EXP2, 88));

		return mat[row][col];
	}
	else {
		setHP(HP1, calc(HP1, 110));
		setHP(HP1, calc(HP1, 110));

		setEXP(EXP1, calc(EXP1, 112));
		setEXP(EXP1, calc(EXP1, 112));

		return max_point;
	}
}

// Task 4
int checkPassword(const char * s, const char * email) {
	// TODO: Complete this function

	int count = 0;
	while (s[count])
		count++;
	if (count < 8) return -1;
	if (count > 20) return -2;

	int len = 0;
	while (email[len] != '@') {
		len++;
	}
	if (len > 0 && len <= count) {
		for (int i = 0; i < count - len + 1; i++) {
			bool contain = true;
			for (int j = 0; j < len; j++) {
				if (s[i + j] != email[j]) {
					contain = false;
					break;
				}
			}
			if (contain) return -(300 + i);
		}
	}

	for (int i = 0; i < count - 2; i++) {
		if (s[i] == s[i + 1] && s[i] == s[i + 2])
			return -(400 + i);
	}

	bool contain = false;
	for (int i = 0; i < count; i++) {
		char c = s[i];
		if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
			contain = true;
			break;
		}
	}
	if (!contain) return -5;

	for (int i = 0; i < count; i++) {
		char c = s[i];
		if (c >= '0' && c <= '9') continue;
		if (c >= 'a' && c <= 'z') continue;
		if (c >= 'A' && c <= 'Z') continue;
		if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') continue;

		return i;
	}

	return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
	// TODO: Complete this function

	int *counts = new int[num_pwds]();
	for (int i = 0; i < num_pwds; i++) {
		const char *si = arr_pwds[i];
		counts[i]++;
		for (int j = i + 1; j < num_pwds; j++) {
			const char *sj = arr_pwds[j];
			if (equalString(si, sj)) {
				counts[i]++;
				counts[j]++;
			}
		}
	}

	int max_count = 0;
	int max_index = -1;
	for (int i = 0; i < num_pwds; i++) {
		if (counts[i] > max_count) {
			max_count = counts[i];
			max_index = i;
		}
		else if (counts[i] == max_count) {
			if (strlen(arr_pwds[i]) > strlen(arr_pwds[max_index]))
				max_index = i;
		}
	}

	delete[] counts;
	return max_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////