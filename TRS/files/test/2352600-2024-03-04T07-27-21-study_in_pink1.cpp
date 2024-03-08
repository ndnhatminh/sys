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
int checkhp(int& hp) {
	if (hp > 666) {
		return 666;
	}
	else if (hp < 0) {
		return 0;
	}
	else {
		return hp;
	}
}
int checkexp(int& exp) {
	if (exp > 600) {
		return 600;
	}
	else if (exp < 0) {
		return 0;
	}
	else {
		return exp;
	}
}
int checkm(int& m){
	if (m > 3000) {
		return 3000;
	}
	else if (m < 0) {
		return 0;
	}
	else {
		return m;
	}
}
int checkE1(int EXP1,int& EXP2, int E1) {
	if (E1 >= 0 && E1 <= 99) {
		return EXP1 + EXP2;
	}
	else
		return -99;
}
int checkE2(int HP1, int EXP1, int M1, int E2) {
	if (E2 >= 0 && E2 <= 99) {
		return (HP1 + EXP1 + M1);
	}
	else
		return -99;
}
int checkE3(int scores, int E3) {
	if (E3 >= 0 && E3 <= 99) {
		return scores;
	}
	else
		return -99;
}
// Task 1
void c1(int& EXP1, int& EXP2, int E1) {
	if (E1 == 0 || E1 == 3)
		EXP2 += 29;
	if (E1 == 1 || E1 == 3)
		EXP2 += 45;
	if (E1 == 2 || E1 == 3)
		EXP2 += 75;
	int d = E1 * 3 + EXP1 * 7;
	if (d % 2 == 0)
		EXP1 += d / 200;
	else
		EXP1 -= d / 100;
}
void c2(int& EXP1, int& EXP2, int E1) {
	if (E1 >= 4 && E1 <= 19) {
		EXP2 += ceil(E1 / 4 + 19 + 0.5);
	}
	if (E1 >= 20 && E1 <= 49) {
		EXP2 += ceil(E1 / 9 + 21 + 0.5);
	}
	if (E1 >= 50 && E1 <= 65) {
		EXP2 += ceil(E1 / 16 + 17 + 0.5);
	}
	if (E1 >= 66 && E1 <= 79) {
		EXP2 += ceil(E1 / 4 + 19 + 0.5);
		if (EXP2 > 200) {
			EXP2 += ceil(E1 / 9 + 21 + 0.5);
		}
	}
	if (E1 >= 80 && E1 <= 99) {
		EXP2 += ceil(E1 / 4 + 19 + 0.4);
		EXP2 += ceil(E1 / 9 + 21 + 0.5);
		if (EXP2 > 400) {
			EXP2 += ceil(E1 / 16 + 17 + 0.5);
			EXP2 += 0.15 * EXP2;
		}
	}
	EXP1 -= E1;
}
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
	EXP1 = checkexp(EXP1);
	EXP2 = checkexp(EXP2);
	if (E1 >= 0 && E1 <= 3)
		c1(EXP1, EXP2, E1);
	else if (E1 >= 4 && E1 <= 99)
		c2(EXP1, EXP2, E1);
	EXP1 = checkexp(EXP1);
	EXP2 = checkexp(EXP2);
	return checkE1(EXP1, EXP2, E1);
}

// Task 2
int Road1(int EXP1) {
	int S= pow(round(sqrt(EXP1)), 2), P;
	if (S > EXP1) {
		P = (EXP1 / S + 80) / 123;
	}
	else {
		P = 100;
	}
	return P;
}
int Road2(int& HP1, int& EXP1, int& M1, int E2) {
	int m1 = M1;
	for (int i = 0; M1 > 0.5 * m1; i++) {
		if (HP1 < 200) {
			HP1 = 1.3 * HP1;
			M1 -= 150;
		}
		else {
			HP1 = 1.1 * HP1;
			M1 -= 70;
		}
		if (EXP1 < 400) {
			M1 -= 200;
		}
		else {
			M1 -= 120;
		}
		EXP1 = 0.87 * EXP1;
		if (EXP1 < 300) {
			M1 -= 100;
		}
		else {
			M1 -= 120;
		}
		EXP1 = 0.9 * EXP1;
	}
}
int Road3(int& HP1, int& EXP1, int& M1, int E2) {
	int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
	int i = E2;
	if (E2 >= 10) {
		i = (E2 / 10) + (E2 % 10);
	}
	return P[i - 1];
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
	int p1 = Road1(EXP1), p2 = Road2(HP1, EXP1, M1, E2), p3 = Road3(HP1, EXP1, M1, E2);
	int ave = (p1 + p2 + p3) / 3;
	if (ave < 50) {
		HP1 = 0.4 + 0.85 * HP1;
		EXP1 = 0.4 + 1.15 * EXP1;
	}
	else {
		HP1 = 0.4 + 0.9 * HP1;
		EXP1 = 0.4 + 1.2 * EXP1;
	}
	if (p1 == 100 && p2 == 100 && p3 == 100) {
		EXP1 = 0.4 + 0.75 * EXP1;
	}
	HP1 = checkhp(HP1);
	EXP1 = checkexp(EXP1);
	M1 = checkm(M1);
    return checkE2(HP1,EXP1,M1,E2);
}
// Task 3
int icount(int map[10][10], int E3) {
	int count = 0;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			if (map[i][j] > (E3 * 2))
				count++;
		}
	}
	return count;
}
int jcount(int map[10][10], int E3) {
	int count = 0;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			if (map[i][j] < (-E3))
					count++;
		}
	}
	return count;
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
	// TODO: Complete this function
	int map[10][10] = { 0 }, i, j, sherlockscores = 0, taxiscores=0;
	for (int x = 0; x <= 9; x++) {
		for (int y = 0; y <= 9; y++) {
			map[x][y] = ((E3 * y) + (x * 2)) * (x - y);
		}
	}
	i = icount(map, E3);
	j = jcount(map, E3);
	while (i >= 10) {
		i = i / 10 + i % 10;
	}
	while (j >= 10) {
		j = j / 10 + j % 10;
	}
	taxiscores = map[i][j];
	for (int n = 0; (i + n) <= 9 && (j + n) <= 9;n++) {
		if (sherlockscores < map[i + n][j + n]) {
			sherlockscores = map[i + n][j + n];
		}
	}
	for (int n = 0; (i + n) <= 9 && (j - n) >= 0;n++) {
		if (sherlockscores < map[i + n][j - n]) {
			sherlockscores = map[i + n][j - n];
		}
	}
	for (int n = 0; (i - n) >= 0 && (j + n) <= 9;n++) {
		if (sherlockscores < map[i - n][j + n]) {
			sherlockscores = map[i - n][j + n];
		}
	}
	for (int n = 0; (i - n) >= 0 && (j - n) >= 0;n++) {
		if (sherlockscores < map[i - n][j - n]) {
			sherlockscores = map[i - n][j - n];
		}
	}
	if (abs(sherlockscores) >= abs(taxiscores)) {
		EXP1 = 0.4 + 1.12 * EXP1;
		EXP2 = 0.4 + 1.12 * EXP2;
		HP1 = 0.4 + 1.1 * HP1;
		HP2 = 1.1 * HP2;
		return checkE3(sherlockscores,E3);
	}
	else {
		EXP1 = 0.4 + 0.88 * EXP1;
		EXP2 = 0.4 + 0.88* EXP2;
		HP1 = 0.4 + 0.9 * HP1;
		HP2 = 0.4 + 0.9 * HP2;
		return checkE3(taxiscores,E3);
	}
}
// Task 4
int checkPassword(const char* s, const char* email) {
	// TODO: Complete this function
	string pwstr(s);
	string emailstr(email);
	string se = emailstr.substr(0, emailstr.find('@'));
	if (pwstr.length() < 8) {
		return -1;
	}
	if (pwstr.length() > 20) {
		return -2;
	}
	size_t sei = pwstr.find(se);
	if (sei != string::npos) {
		return -(300 + static_cast<int>(sei));
	}
	for (int i = 0; i < pwstr.length() - 2; ++i) {
		if (pwstr[i] == pwstr[i + 1] && pwstr[i] == pwstr[i + 2]) {
			return -(400 + i);
	}		
}

	if (pwstr.find_first_of("!@#$%") == string::npos) {
		return -5;
	}
	return -10;
}



// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
	// TODO: Complete this function
	int posmc = 0, posml = 0, maxcount = 0, maxlength = 0, count = 0;
	for (int i = 0; i < num_pwds; i++) {
		if (strlen(arr_pwds[i]) > maxlength) {
			maxlength = strlen(arr_pwds[i]);
			posml = i;
		}
	}
	for (int i = 0; i < num_pwds; i++) {
		for (int j = 0; j < num_pwds; j++) {
			if (arr_pwds[i] == arr_pwds[j]) {
				count++;
			}
		}
		if (count > maxcount) {
			maxcount = count;
			posmc = i;
		}
		count = 0;
	}
	if (posml > posmc) {
		return posml;
	}
	else {
		return posmc;
	}
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////