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
int lt(float x) {
	if (x - int(x) == 0) {
		return int(x);
	}
	else {
		return int(x) + 1;
	}
}
//ham lam tron len
void ktHP(int& HP) {
	if (HP > 666) HP = 666;
	if (HP < 0) HP = 0;
}
void ktEXP(int& EXP) {
	if (EXP > 600) EXP = 600;
	if (EXP < 0) EXP = 0;
}
void ktM(int& M) {
	if (M > 3000) M = 3000;
	if (M < 0) M = 0;
}
int datlovedung(int x) {
	int a;
	if (x < 10) {
		return x;
	}
	else {
		a = x % 10 + (x - x % 10) / 10;
		if (a >= 10) {
			return (a % 10 + (a - a % 10) / 10);
		}
		else {
			return a;
		}
	}
}
int size(const char* x) {
	int i = 0;
	while (x[i] != '\0') {
		i++;
	}
	return i + 1;
}
int lientiep(const char* s) {
	int kt = 0;
	for (int i = 0; i < size(s) - 3; i++) {
		if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
			kt = 1;
		}
		if (kt == 1) return i;
	} 
	return -1;
}
int checkse(const char* s, const char* se) {
	for (int i = 0; i < size(s) - size(se) + 1; i++) {
		int kt = 0;
		for (int j = 0; j < size(se) - 1; j++) {
			if (se[j] == s[i + j]) {
				kt = 1;
			}
			else {
				kt = 0; break;
			}
		}
		if (kt == 1) return i;
	}
	return -1;
}

bool special(const char* s, int a) {
	for (int i = 0; i < a - 1; i++) {
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
			continue;
		}
		else if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
			continue;
		}
		return 0;
	}
	return 1;
}
bool kitu(const char* s, int a) {
	int duy = 0;
	for (int i = 0; i < a - 1; i++) {
		if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
			duy = 1;
		}
	}
	if (duy == 0) {
		return 0;
	}
	else return 1;
}
bool ss(const char* x, const char* y) {
	if (size(x) == size(y)) {
		for (int i = 0; i < size(x) - 1; i++) {
			if (x[i] != y[i]) {
				return 0;
			}
		}
		return 1;
	}
	return 0;
}
int abs(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}
// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {
	if (E1 >= 0 && E1 <= 3) {
		switch (E1) {
		case 0: EXP2 += 29;break;
		case 1: EXP2 += 45;break;
		case 2: EXP2 += 75;break;
		case 3: EXP2 = EXP2 + 149;break;
		}
		int D;
		D = lt(E1 * 3 + EXP1 * 7);
		if (D % 2 == 0) {
			EXP1 = lt(EXP1 + D * 1.0 / 200);
		}
		else {
			EXP1 = lt(EXP1 - D * 1.0 / 100);
		}
	}
	else {
		if (E1 >= 4 && E1 <= 19) {
			EXP2 += lt(E1 * 1.0 / 4 + 19);
		}
		else if (E1 >= 20 && E1 <= 49) {
			EXP2 += lt(E1 * 1.0 / 9 + 21);
		}
		else if (E1 >= 50 && E1 <= 65) {
			EXP2 += lt(E1 * 1.0 / 16 + 17);
		}
		else if (E1 >= 66 && E1 <= 79) {
			EXP2 += lt(E1 * 1.0 / 4 + 19);
			if (EXP2 > 200) {
				EXP2 += lt(E1 * 1.0 / 9 + 21);
			}
		}
		else if (E1 >= 80 && E1 <= 99) {
			EXP2 += lt(E1 * 1.0 / 4 + 19);
			EXP2 += lt(E1 * 1.0 / 9 + 21);
			if (EXP2 > 400) {
				EXP2 += lt(E1 * 1.0 / 16 + 17);
				EXP2 = lt(EXP2 * 1.15);
			}
		}
		EXP1 -= E1;
	}
	ktEXP(EXP1); ktEXP(EXP2);
	return EXP1 + EXP2;
}
//Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
	//cd1 
	int min = 1e9; int S1; float P1;
	for (int i = 0; i < 26; i++) {
		if ((abs(i * i - EXP1)) < min) {
			min = abs(i * i - EXP1);
			S1 = i * i;
		}
	}
	if (EXP1 >= S1) P1 = 1;
	else {
		P1 = (EXP1 * 1.0 / S1 + 80) / 123;
	}
	//cd2
	if (E2 % 2 == 0) {
		//sk1
		if (HP1 < 200) {
			HP1 = lt(HP1 * 1.3);
			M1 -= 150;
		}
		else {
			HP1 = lt(HP1 * 1.1);
			M1 -= 70;
		}
		ktHP(HP1);
		ktM(M1);
		if (M1 != 0) {
			//sk2
			if (EXP1 < 400) {
				M1 -= 200;
			}
			else {
				M1 -= 120;
			}
			EXP1 = lt(EXP1 * 1.13);
			ktM(M1); ktEXP(EXP1);
			if (M1 != 0) {
				//sk3
				if (EXP1 < 300) {
					M1 -= 100;
				}
				else {
					M1 -= 120;
				}
				EXP1 = lt(EXP1 * 0.9);
				ktM(M1);ktEXP(EXP1);
			}
		}
		HP1 = lt(HP1 * 0.83); EXP1 = lt(EXP1 * 1.17);
		ktHP(HP1); ktEXP(EXP1);
	}
	else {
		int tien;
		tien = M1 / 2;
		while (1) {
			//sk1
			if (HP1 < 200) {
				HP1 = lt(HP1 * 1.3);
				M1 -= 150;
			}
			else {
				HP1 = lt(HP1 * 1.1);
				M1 -= 70;
			}
			ktM(M1);ktHP(HP1);
			if (M1 < tien) {
				break;
			}
			//sk2
			if (EXP1 < 400) {
				M1 -= 200;
			}
			else {
				M1 -= 120;
			}
			EXP1 = lt(EXP1 * 1.13);
			ktM(M1); ktEXP(EXP1);
			if (M1 < tien) {
				break;
			}
			//sk3
			if (EXP1 < 300) {
				M1 -= 100;
			}
			else {
				M1 -= 120;
			}
			EXP1 = lt(EXP1 * 0.9);
			ktM(M1);ktEXP(EXP1);
			if (M1 < tien) {
				break;
			}
		}
		HP1 = lt(HP1 * 0.83); EXP1 = lt(EXP1 * 1.17);
		ktHP(HP1); ktEXP(EXP1);
	}
	//tinh sac xuat cd2
	float P2; int S2 = 1e9;
	for (int i = 0; i < 26; i++) {
		if ((abs(i * i - EXP1)) < min) {
			min = abs(i * i - EXP1);
			S2 = i * i;
		}
	}
	if (EXP1 >= S2) P2 = 1;
	else P2 = (EXP1 * 1.0 / S2 + 80) / 123;
	//cd3
	float P3;
	int a[10] = { 32,47,28,79,100,50,22,83,64,11 };
	if ((E2 - 10) < 0) {
		P3 = a[E2] * 1.0 / 100;
	}
	else {
		P3 = a[(E2 % 10 + (E2 - E2 % 10) / 10) % 10] * 1.0 / 100;
	}
	//tong ket Task 2
	if (P1 == 1 && P2 == 1 && P3 == 1) {
		EXP1 = lt(EXP1 * 0.75);
	}
	else {
		if ((P1 + P2 + P3) * 1.0 / 3 < 0.5) {
			HP1 = lt(HP1 * 0.85);
			EXP1 = lt(EXP1 * 1.15);
		}
		else {
			HP1 = lt(HP1 * 0.9);
			EXP1 = lt(EXP1 * 1.2);
		}
		ktHP(HP1); ktEXP(EXP1);
	}
	//  cout << P1 << " " << P2 << " " << P3;
	return HP1 + EXP1 + M1;
}
//Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
	int a[10][10] = { 0 };
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
		}
	}
	int dung = 0, dat = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (a[i][j] > (E3 * 2)) {
				++dung;
			}
			if (a[i][j] < (-E3)) {
				++dat;
			}
		}
	}
	dung = datlovedung(dung);
	dat = datlovedung(dat);
	int b[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int max = a[i][j];
			for (int x = -9; x < 10; x++) {
				if ((i + x) >= 0 && (j + x) >= 0 && (i + x) < 10 && (j + x) < 10) {
					if (a[i + x][j + x] > max) {
						max = a[i + x][j + x];
					}
				}
				if ((i - x) >= 0 && (j + x) >= 0 && (i - x) < 10 && (j + x) < 10) {
					if (a[i - x][j + x] > max) {
						max = a[i - x][j + x];
					}
				}
			}
			b[i][j] = abs(max);
		}
	}
	int trave;
	if (abs(a[dung][dat]) > b[dung][dat]) {
		EXP1 = lt(EXP1 * 0.88);
		EXP2 = lt(EXP2 * 0.88);
		HP1 = lt(HP1 * 0.9);
		HP2 = lt(HP2 * 0.9);
		trave = a[dung][dat];
	}
	else {
		EXP1 = lt(EXP1 * 1.12);
		EXP2 = lt(EXP2 * 1.12);
		HP1 = lt(HP1 * 1.1);
		HP2 = lt(HP2 * 1.1);
		trave = b[dung][dat];
	}
	ktEXP(EXP1);ktEXP(EXP2);
	return trave;
}
//Task 4
int checkPassword(const char* s, const char* email) {
	int kt;
	for (int i = 0; i < size(email) - 1; i++) {
		if (email[i] == '@') {
			kt = i;
		}
	}
	char* se = new char(kt + 1);
	for (int i = 0; i < kt; i++) {
		se[i] = email[i];
	}
	if (size(s) - 1 >= 8 && size(s) - 1 <= 20) {
		if (special(s, size(s))) {
			if (checkse(s, se) == -1) {
				if (lientiep(s) == -1) {
					if (kitu(s, size(s))) {
						return -10;
					}
				}
			}
		}
		else {
			for (int i = 0; i < size(s) - 1; i++) {
				if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
					continue;
				}
				else if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
					continue;
				}
				return i;
			}
		}
	}
	if (size(s) - 1 <= 8) {
		return -1;
	}
	else if (size(s) - 1 >= 20) return -2;

	if (checkse(s, se) != -1) {
		return -(300 + checkse(s, se));
	}
	if (lientiep(s) != -1) {
		return -(400 + lientiep(s));
	}
	if (kitu(s, size(s)) == 0) {
		return -5;
	}
	return -1;
}
// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
	int* a = new int(num_pwds);
	for (int i = 0; i < num_pwds; i++) {
		a[i] = 1;
	}
	for (int i = 0; i < num_pwds; i++) {
		for (int j = i + 1; j < num_pwds; j++) {
			if (ss(arr_pwds[i], arr_pwds[j])) {
				++a[i]; ++a[j];
			}
		}
	}

	int max1 = -1e9;
	for (int i = 0; i < num_pwds; i++) {
		if (a[i] > max1) {
			max1 = a[i];
		}
	}
	int b[30] = { 0 }, x = 0; int c[30] = { 0 }, y = 0;
	for (int i = 0; i < num_pwds; i++) {
		if (a[i] == max1) {
			b[x] = size(arr_pwds[i]);
			c[y] = i;
			x++;
			y++;
		}
	}
	int max2 = -1e9; int dem;
	for (int i = 0; i < x; i++) {
		if (b[i] > max2) {
			dem = i;
			max2 = b[i];
		}
	}
	return c[dem];
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////