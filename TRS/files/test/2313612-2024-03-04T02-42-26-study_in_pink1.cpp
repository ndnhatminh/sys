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

int roundUp(double a)
{
	int b = round(a);
	if (a - b > 0)
		return b + 1;
	else return b;
}

int checkValueExp(double exp)
{
	if (exp < 0)
		return 0;
	if (exp > 600)
		return 600;
	else return roundUp(exp);
}

int checkValueHp(double hp)
{
	if (hp < 0)
		return 0;
	if (hp > 666)
		return 666;
	else return roundUp(hp);
}

int checkValueM(double M)
{
	if (M < 0)
		return 0;
	if (M > 3000)
		return 3000;
	else return roundUp(M);
}

bool isSquare(int n) {
	if (n <= 1)
		return false;
	if (sqrt(n) == roundUp(sqrt(n)))
		return true;
	else return false;
}

int nearestSquare(int n) {
	if (isSquare(n) == 1)
		return n;
	else {
		int a = n;
		int b = n;
		do {
			a--;
			b++;
		} while (isSquare(a) == 0 && isSquare(b) == 0);
		if (isSquare(a) == 1)
			return a;
		else return b;
	}
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
	// TODO: Complete this function
	if (e1 >= 0 && e1 <= 99) {
		if (e1 <= 3) {
			if (e1 == 0)
				exp2 = checkValueExp(exp2 + 29);
			if (e1 == 1)
				exp2 = checkValueExp(exp2 + 45);
			if (e1 == 2)
				exp2 = checkValueExp(exp2 + 75);
			if (e1 == 3)
				exp2 = checkValueExp(exp2 + 29 + 45 + 75);
			int D = e1 * 3 + exp1 * 7;
			if (D % 2 == 0)
				exp1 = checkValueExp(exp1 + float(D) / 200);
			else
				exp1 = checkValueExp(exp1 - float(D) / 100);
		}
		if (e1 >= 4 && e1 <= 99) {
			if (e1 >= 4 && e1 <= 19)
				exp2 = checkValueExp(exp2 + float(e1) / 4 + 19);
			if (e1 >= 20 && e1 <= 49)
				exp2 = checkValueExp(exp2 + float(e1) / 9 + 21);
			if (e1 >= 50 && e1 <= 65)
				exp2 = checkValueExp(exp2 + float(e1) / 16 + 17);
			if (e1 >= 66 && e1 <= 79) {
				exp2 = checkValueExp(exp2 + float(e1) / 4 + 19);
				if (exp2 > 200)
					exp2 = checkValueExp(exp2 + float(e1) / 9 + 21);
			}
			if (e1 >= 80 && e1 <= 99) {
				exp2 = checkValueExp(exp2 + float(e1) / 4 + 19);
				exp2 = checkValueExp(exp2 + float(e1) / 9 + 21);
				if (exp2 > 400)
				{
					exp2 = checkValueExp(exp2 + float(e1) / 16 + 17);
					exp2 = checkValueExp(exp2 * 1.15);
				}
			}
			exp1 = checkValueExp(exp1 - e1);
		}
		return exp1 + exp2;
	}
	else return-99;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
	// TODO: Complete this function
	if (E2 >= 0 && E2 <= 99) {
		float cost = M1 / 2;
		float p1, p2, p3, p;
		int sp = 0;
		//1ST WAY
		int S = nearestSquare(EXP1);
		if (EXP1 >= S)
			p1 = 1;
		else p1 = (float(EXP1 / S) + 80) / 123;


		// 2ND WAY
		// Stage 1
		if (E2 % 2 == 0) {
			for (int i = 1; i < 2; i++) {
				if (HP1 < 200) {
					HP1 = checkValueHp(HP1 * 1.3);
					M1 = M1 - 150;
					if (checkValueM(M1) == 0)
						break;
				}
				else {
					HP1 = checkValueHp(HP1 * 1.1);
					M1 = checkValueM(M1 - 70);
					if (checkValueM(M1) == 0)
						break;
				}

				//Stage 2
				if (EXP1 < 400)
					M1 = checkValueM(M1 - 200);
				else
					M1 = checkValueM(M1 - 120);

				EXP1 = checkValueExp(EXP1 * 1.13);
				if (checkValueM(M1) == 0) break;

				//Stage 3
				if (EXP1 < 300)
					M1 = checkValueM(M1 - 100);
				else M1 = checkValueM(M1 - 120);

				EXP1 = checkValueExp(EXP1 * 0.9);
				M1 = checkValueM(M1);
			}
			HP1 = checkValueHp(HP1 * 0.83);
			EXP1 = checkValueExp(EXP1 * 1.17);

			S = nearestSquare(EXP1);
			if (EXP1 >= S)
				p2 = 1;
			else p2 = (EXP1 / S + 80) / 123;
		}


		if (E2 % 2 != 0) {
			for (int i = 0; i < 6; i++) {
				if (HP1 < 200) {
					HP1 = checkValueHp(HP1 * 1.3);
					sp += 150;
					if (sp > cost)
						break;
				}
				else {
					HP1 = checkValueHp(HP1 * 1.1);
					sp += 70;
					if (sp > cost)
						break;
				}

				//Stage 2
				if (EXP1 < 400) {
					EXP1 = checkValueExp(EXP1 * 1.13);
					sp += 200;
					if (sp > cost)
						break;
				}
				else {
					EXP1 = checkValueExp(EXP1 * 1.13);
					sp += 120;
					if (sp > cost)
						break;
				}

				//Stage 3
				if (EXP1 < 300) {
					EXP1 = checkValueExp(EXP1 * 0.9);
					sp += 100;
					if (sp > cost)
						break;
				}
				else {
					EXP1 = checkValueExp(EXP1 * 0.9);
					sp += 120;
					if (sp > cost)
						break;
				}
			}

			M1 = checkValueM(M1 - sp);
			HP1 = checkValueHp(HP1 * 0.83);
			EXP1 = checkValueExp(EXP1 * 1.17);
			S = nearestSquare(EXP1);
			if (EXP1 >= S)
				p2 = 1;
			else p2 = (EXP1 / S + 80) / 123;
		}


		//3RD WAY
		float P[10] = { 0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11 };
		if (E2 < 10)
			p3 = P[E2];
		else {
			int a = E2 % 10;
			int b = (E2 - a) / 10;
			int c = a + b;
			if (c < 10)
				p3 = P[c];
			if (c >= 10)
				p3 = P[c % 10];
		}

		if (p1 == 1 && p2 == 1 && p3 == 1)
			EXP1 = checkValueExp(EXP1 * 0.75);
		else {
			p = (p1 + p2 + p3) / 3;
			if (p < 0.5) {
				HP1 = checkValueHp(HP1 * 0.85);
				EXP1 = checkValueExp(EXP1 * 1.15);
			}
			else {
				HP1 = checkValueHp(HP1 * 0.9);
				EXP1 = checkValueExp(EXP1 * 1.2);
			}
		}
		return HP1 + EXP1 + M1;
	}
	else return -99;
}


//Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
	// TODO: Complete this function
	if (E3 >= 0 && E3 <= 99) {
		int ta[10][10];
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				ta[i][j] = (E3 * j + i * 2) * (i - j);

		int duong = 0;
		int am = 0;

		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++) {

				if (ta[i][j] > 0 && ta[i][j] > (E3 * 2))
					duong += 1;
				if (ta[i][j] < 0 && ta[i][j] < (-E3))
					am += 1;
			}

		while (duong >= 10) {
			int a = duong % 10;
			int b = (duong - a) / 10;
			duong = a + b;
		}
		int i = duong;
		while (am >= 10) {
			int c = am % 10;
			int d = (am - c) / 10;
			am = c + d;
		}

		int j = am;
		int const m = i;
		int const n = j;

		int cmax = ta[i][j];
		while (i + 1 <= 9 && j + 1 <= 9) {
			cmax = max(ta[i][j], ta[i + 1][j + 1]);
			i++;
			j++;
		}
		i = m;
		j = n;

		while (i - 1 >= 0 && j - 1 >= 0) {
			cmax = max(cmax, ta[i - 1][j - 1]);
			i--;
			j--;
		}
		i = m;
		j = n;

		while (i - 1 >= 0 && j + 1 <= 9) {
			cmax = max(cmax, ta[i - 1][j + 1]);
			i--;
			j++;
		}
		i = m;
		j = n;

		while (i + 1 <= 9 && j - 1 >= 0) {
			cmax = max(cmax, ta[i + 1][j - 1]);
			i++;
			j--;
		}
		i = m;
		j = n;

		if (cmax < 0)
			cmax = abs(cmax);

		if (cmax < abs(ta[i][j])) {
			EXP1 = checkValueExp(EXP1 * 0.88);
			EXP2 = checkValueExp(EXP2 * 0.88);
			HP1 = checkValueHp(HP1 * 0.9);
			HP2 = checkValueHp(HP2 * 0.9);
			return ta[i][j];
		}
		else {
			EXP1 = checkValueExp(EXP1 * 1.12);
			EXP2 = checkValueExp(EXP2 * 1.12);
			HP1 = checkValueHp(HP1 * 1.1);
			HP2 = checkValueHp(HP2 * 1.1);
			return cmax;
		}
	}
	else return -99;
}


//TASK 4
int checkPassword(const char* s, const char* email) {
	// TODO: Complete this function
	string passw = s;
	string mail = email;
	int a = 0;
	string valid = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#%$!";

	string se;
	for (int i = 0; i < mail.length(); i++)
		if (mail[i] != '@')
			se.push_back(mail[i]);
		else break;

	if (passw.length() < 8)
		return -1;
	if (passw.length() > 20)
		return -2;

	for (int i = 0; i < passw.length(); i++)
		for (int j = 0; j < 67; j++)
			if (passw[i] != valid[j])
				return i + 1;


	for (int i = 0; i < passw.length(); i++) {
		if (passw[i] == se[0]) {
			for (int j = 0; j < se.length() && j + i + 1 < passw.length(); j++) {
				if (passw[j + i] == se[j])
					a += 1;
				else break;
			}
			if (a == se.length()) {
				return -(300 + i + 1);
			}
		}
	}

	for (int i = 2; i < passw.length(); i++) {
		if (passw[i] == passw[i - 1])
			if (passw[i - 1] == passw[i - 2])
				return -(400 + i - 1);
	}

	string m = "@#%$!";

	for (int i = 0; i < passw.length(); i++) {
		for (int j = 0; j < m.length(); j++) {
			if (passw[i] == m[j])
				return -10;
		}
	}
	return -5;
}


//TASK 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
	string pw1 = arr_pwds[0];
	string pw2;
	int fre1 = 1;
	int len1 = pw1.length();
	int index = 0;
	int len2 = 0;
	int fre2 = 0;
	int imax = 0;

	for (int i = 1; i < num_pwds; i++) {
		if (pw1 == arr_pwds[i]) {
			fre1 += 1;
		}
		else {
			pw2 = arr_pwds[i];
			fre2 = 1;
			len2 = pw2.length();

			for (int j = i + 1; j < num_pwds; j++) {
				if (pw2 == arr_pwds[j]) {
					fre2 += 1;
				}
			}

			if (fre1 < fre2 || (fre1 == fre2 && len1 < len2)) {
				pw1 = pw2;
				fre1 = fre2;
				len1 = len2;
				imax = i;
			}
			fre2 = 0;
			len2 = 0;
		}
	}

	return imax;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////