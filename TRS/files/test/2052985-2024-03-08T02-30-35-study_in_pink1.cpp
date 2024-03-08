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
	int& E3)
{
	// This function is used to read the input file,
	// DO NOT MODIFY THIS FUNTION
	ifstream ifs(filename);
	if (ifs.is_open())
	{
		ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
		return true;
	}
	else
	{
		cerr << "The file is not found" << endl;
		return false;
	}
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////


//////////////////// Support Functions ///////////////////////////
void checkLimit(int* hp1, int* hp2, int* exp1, int* exp2, int* m1, int* m2) {
	if (hp1 != NULL) {
		if (*hp1 > MAXHP) *hp1 = MAXHP;
		else if (*hp1 < MINHP) *hp1 = MINHP;
	}
	if (hp2 != NULL) {
		if (*hp2 > MAXHP) *hp2 = MAXHP;
		else if (*hp2 < MINHP) *hp2 = MINHP;
	}
	if (exp1 != NULL) {
		if (*exp1 > MAXEXP) *exp1 = MAXEXP;
		else if (*exp1 < MINEXP) *exp1 = MINEXP;
	}
	if (exp2 != NULL) {
		if (*exp2 > MAXEXP) *exp2 = MAXEXP;
		else if (*exp2 < MINEXP) *exp2 = MINEXP;
	}
	if (m1 != NULL) {
		if (*m1 > MAXMONEY) *m1 = MAXMONEY;
		else if (*m1 < MINMONEY) *m1 = MINMONEY;
	}
	if (m2 != NULL) {
		if (*m2 > MAXMONEY) *m2 = MAXMONEY;
		else if (*m2 < MINMONEY) *m2 = MINMONEY;
	}
}
bool checkValidE(int e) {
	return (e >= 0 && e <= 99);
}

bool checkPerfectSqr(int num)
{
	if (sqrt(num) - floor(sqrt(num)) == 0)
		return true;
	return false;
}
int findClosestPerfectSqr(int num)
{
	if (checkPerfectSqr(num))
		return num;

	int gtNum = num + 1;
	int stNum = num - 1;

	while (true)
	{
		if (checkPerfectSqr(gtNum))
			break;
		gtNum++;
	}
	while (true)
	{
		if (checkPerfectSqr(stNum)) break;
		stNum--;
	}
	if (abs(gtNum - num) > abs(stNum - num))
		return stNum;
	return gtNum;
}

int getOnedigitCoor(int num) {
	if (num < 10) return num;
	return getOnedigitCoor(num = num / 10 + (num - (num / 10) * 10));
}

int findMaxDet(int x, int y, int arr[][MAXCOL]) {
	int maxDet = arr[x][y];
	int x_walker = x;
	int y_walker = y;

	while (x_walker >= 0 && y_walker >= 0) {
		if (arr[x_walker][y_walker] > maxDet) maxDet = arr[x_walker][y_walker];
		x_walker--;
		y_walker--;
	}
	x_walker = x;
	y_walker = y;
	while (x_walker < MAXROW && y_walker < MAXCOL) {
		if (arr[x_walker][y_walker] > maxDet) maxDet = arr[x_walker][y_walker];
		x_walker++;
		y_walker++;
	}
	x_walker = x;
	y_walker = y;
	while (x_walker >= 0 && y_walker < MAXCOL) {
		if (arr[x_walker][y_walker] > maxDet) maxDet = arr[x_walker][y_walker];
		x_walker--;
		y_walker++;
	}
	x_walker = x;
	y_walker = y;
	while (x_walker < MAXROW && y_walker >= 0) {
		if (arr[x_walker][y_walker] > maxDet) maxDet = arr[x_walker][y_walker];
		x_walker++;
		y_walker--;
	}
	return maxDet;
}
//////////////////////////////////////////////////////////////////
// Task 1
int firstMeet(int& exp1, int& exp2, int e1)
{
	// TODO: Complete this function
	if (!checkValidE(e1)) return -99;
	if (e1 >= 0 && e1 <= 3)
	{
		switch (e1)
		{
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
			exp2 += 29 + 45 + 75;
			break;
		}
		(exp2 > 600) ? exp2 = 600 : exp2;
		int D;
		D = e1 * 3 + exp1 * 7;
		(D % 2 == 0) ? exp1 = ceil(float(exp1 + (D / 200))) : exp1 = ceil(float(exp1 - (D / 100)));
	}
	else if (e1 >= 4 && e1 <= 99)
	{
		if (e1 >= 4 && e1 <= 19)
		{
			exp2 = ceil(float(exp2 + e1 / 4.0 + 19));
		}
		else if (e1 >= 20 && e1 <= 49)
		{
			exp2 = ceil(float(exp2 + e1 / 9.0 + 21));
		}
		else if (e1 >= 50 && e1 <= 65)
		{
			exp2 = ceil(float(exp2 + e1 / 16.0 + 17));
		}
		else if (e1 >= 66 && e1 <= 79)
		{
			exp2 = ceil(float(exp2 + e1 / 4.0 + 19));
			if (exp2 > 200)
			{
				exp2 = ceil(float(exp2 + e1 / 9.0 + 21));
			}
		}
		else
		{
			exp2 = ceil(float(exp2 + e1 / 4.0 + 19));

			exp2 = ceil(float(exp2 + e1 / 9.0 + 21));
			if (exp2 > 400)
			{
				exp2 = ceil(float(exp2 + e1 / 16.0 + 17));
				exp2 = ceil(float(exp2 * 1.15));
			}
		}
		exp1 -= e1;
	}
	checkLimit(NULL, NULL, &exp1, &exp2, NULL, NULL);
	return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
	if (!checkValidE(E2)) return -99;
	int S = findClosestPerfectSqr(EXP1);
	float P1;
	if (EXP1 >= S)
		P1 = 1;
	else
		P1 = ((EXP1 / S) + 80) / 123.0;
	//Event 1
	int halfM1 = ceil(float(M1 / 2));
	int paidM1 = 0;
	int paidM1_1event = 0;
	while (true) {
		if (HP1 < 200)
		{
			HP1 = ceil(float(HP1 * 1.3));
			M1 -= 150;
			paidM1_1event = 150;
		}
		else
		{
			HP1 = ceil(float(HP1 * 1.1));
			M1 -= 70;
			paidM1_1event = 70;
		}
		if (M1 < MINMONEY) {
			M1 = 0;
			break;
		}
		if (E2 % 2 != 0) {
			paidM1 += paidM1_1event;
			if (paidM1 > halfM1) {
				break;
			}
		}
		//Event 2
		if (EXP1 < 400) {
			M1 -= 200;
			paidM1_1event = 200;
		}
		else {
			M1 -= 120;
			paidM1_1event = 120;
			EXP1 = ceil(float(EXP1 * 1.13));
			if (paidM1 > halfM1) {
				break;
			}
		}
		if (M1 < MINMONEY) {
			M1 = 0;
			break;
		}
		if (E2 % 2 != 0) {
			paidM1 += paidM1_1event;
			if (paidM1 > halfM1) {
				break;
			}
		}
		//Event 3
		if (EXP1 < 300) {
			M1 -= 100;
			paidM1_1event = 100;
		}
		else {
			M1 -= 120;
			paidM1_1event = 120;
		}
		EXP1 = ceil(float(EXP1 * 0.9));
		if (M1 < MINMONEY) {
			M1 = 0;
			break;
		}
		if (E2 % 2 != 0) {
			paidM1 += paidM1_1event;
			if (paidM1 > halfM1) {
				break;
			}
		}
		////////////////////
		if (E2 % 2 == 0) break;
	}

	HP1 = ceil(float(HP1 * 0.83));
	EXP1 = ceil(float(EXP1 * 1.17));
	S = findClosestPerfectSqr(EXP1);
	float P2;
	if (EXP1 >= S)
		P2 = 1;
	else
		P2 = ((EXP1 / S) + 80) / 123.0;

	float P3[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
	float P = 0;
	int idx = (E2 / 10) + (E2 - ((E2 / 10) * 10));
	float sumP = P1 + P2 + P3[idx] / 100.0;
	if (sumP == 3) EXP1 = ceil(float(EXP1 * 0.75));
	else {
		P = sumP / 3.0;
		if (P < 0.5) {
			HP1 = ceil(float(HP1 * 0.85));
			EXP1 = ceil(float(EXP1 * 1.15));
		}
		else {
			HP1 = ceil(float(HP1 * 0.9));
			EXP1 = ceil(float(EXP1 * 1.2));
		}
	}
	checkLimit(&HP1, NULL, &EXP1, NULL, &M1, NULL);
	return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3)
{
	// TODO: Complete this function
	int map[MAXROW][MAXCOL];
	int x_meet, y_meet;
	x_meet = y_meet = 0;
	for (int j = 0;j < MAXCOL;j++) {
		for (int i = 0;i < MAXROW;i++) {
			map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
			if (map[i][j] > E3 * 2) x_meet++;
			if (map[i][j] < -E3) y_meet++;
		}
	}
	x_meet = getOnedigitCoor(x_meet);
	y_meet = getOnedigitCoor(y_meet);

	int maxDet = findMaxDet(x_meet, y_meet, map);
	if (maxDet >= abs(map[x_meet][y_meet])) {
		EXP1 = ceil(float(EXP1 * 1.12));
		EXP2 = ceil(float(EXP2 * 1.12));
		HP1 = ceil(float(HP1 * 1.1));
		HP2 = ceil(float(HP2 * 1.1));
		checkLimit(&HP1, &HP2, &EXP1, &EXP2, NULL, NULL);
		return maxDet;
	}
	else {
		EXP1 = ceil(float(EXP1 * 0.88));
		EXP2 = ceil(float(EXP2 * 0.88));
		HP1 = ceil(float(HP1 * 0.9));
		HP2 = ceil(float(HP2 * 0.9));
	}
	checkLimit(&HP1, &HP2, &EXP1, &EXP2, NULL, NULL);
	return map[x_meet][y_meet];
}

// Task 4
int checkPassword(const char* s, const char* email)
{
	// TODO: Complete this function
	int length_s = strlen(s);
	if (length_s > 20) return -2;
	else if (length_s < 8) return -1;
	else {
		string str_s, str_email, se;
		int length_email = strlen(email);
		for (int i = 0;i < length_s;i++) {
			str_s += s[i];
		}
		for (int i = 0;i < length_email;i++) {
			str_email += email[i];
		}
		for (int i = 0;i < str_email.find('@');i++) {
			se += str_email[i];
		}

		if (se != "") {
			int se_pos = str_s.find(se);
			if (se_pos >= 0) return -(300 + se_pos);
		}
		string con_str;
		int con_walker = 0;
		while (con_walker < length_s - 2) {
			con_str = "";
			for (int i = 0;i < 3;i++) {
				con_str += str_s[con_walker];
			}
			int con_str_pos = str_s.find(con_str);
			if (con_str_pos >= 0) return -(400 + con_str_pos);
			con_walker++;
		}
		bool flag_special = false;
		string spec_char = "@#%$!";
		for (int i = 0;i < spec_char.length();i++) {
			int spec_pos = str_s.find(spec_char[i]);
			if (spec_pos >= 0) flag_special = true;
		}
		if (!flag_special) return -5;
		for (int i = 0;i < length_s;i++) {
			char invalid_char = str_s[i];
			int ascii_val = invalid_char - 0;
			if ((ascii_val < 48 && ascii_val>57) && (ascii_val < 35 && ascii_val>37) && (ascii_val < 64 && ascii_val>90) && (ascii_val < 97 && ascii_val>122) && ascii_val != 33 && ascii_val != 64)
				return i;
		}
	}
	return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds)
{
	// TODO: Complete this function
	string concat_str;
	for (int i = 0;i < num_pwds;i++) {
		concat_str += arr_pwds[i];
	}
	int max_appear = 0;
	string correctpwd;
	for (int i = 0;i < num_pwds;i++) {
		int count_appear = 0;
		int appear_pos = concat_str.find(arr_pwds[i]);
		while (appear_pos != -1) {
			count_appear++;
			appear_pos = concat_str.find(arr_pwds[i], appear_pos + 1);
		}
		if (count_appear > max_appear) {
			correctpwd = arr_pwds[i];
			max_appear = count_appear;
		}
		else if (count_appear == max_appear) {
			string current_pwd = arr_pwds[i];
			if (current_pwd.length() > correctpwd.length()) {
				correctpwd = current_pwd;
				max_appear = count_appear;
			}
		}
	}
	int f_idx;
	for (f_idx = 0;f_idx < num_pwds;f_idx++) {
		string current_element = arr_pwds[f_idx];
		if (current_element.find(correctpwd) != -1) break;
	}
	return f_idx;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////