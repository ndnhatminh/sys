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

int tong(int x) {
	int s = 0;
	if (x <= 9) return x;
	else {
		while (x != 0) {
			s += x % 10;
			x /= 10;
		}
		return s % 10;
	}
}

double check_HP(double x) {
	if (x > 666) return 666;
	else if (x < 0) return 0;
	else return x;
}
double check_EXP(double x) {
	if (x > 600) return 600;
	else if (x < 0) return 0;
	else return x;
}
double check_M(double x) {
	if (x > 3000) return 3000;
	else if (x < 0) return 0;
	else return x;
}

int sum(int x) {
	int s = 0;
	if (x == 0) return 0;
	while (x != 0) {
		s += x % 10;
		x /= 10;
	}
	if (s >= 10) {
		return sum(s);
	}
	else {
		return s;
	}
}

int find_max(int arr[10][10], int h, int c) {
	int max_trai = INT_MIN;
	int max_phai = INT_MIN;
	// trai
	for (int i = 0; i < 10; ++i) {
		int j = c - h + i;
		if (j >= 0 && j < 10 && arr[i][j] > max_trai) {
			max_trai = arr[i][j];
		}
	}

	//phai
	for (int i = 0; i < 10; ++i) {
		int j = c + h - i;
		if (j >= 0 && j < 10 && arr[i][j] > max_phai) {
			max_phai = arr[i][j];
		}
	}
	return max(max_trai, max_phai);
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
	double Exp1 = exp1;
	double Exp2 = exp2;
	if (e1 >= 0 && e1 < 4) {
		int d = e1 * 3 + exp1 * 7;
		if (d % 2 == 0) {
			double r = d / 200.0;
			Exp1 = Exp1 + r;
			if (Exp1 > 600) Exp1 = 600;
		}
		else {
			double r = d / 100.0;
			Exp1 = Exp1 - r;
			if (Exp1 < 0) Exp1 = 0;
		}
		if (e1 == 0) Exp2 += 29;
		if (e1 == 1) Exp2 += 45;
		if (e1 == 2) Exp2 += 75;
		if (e1 == 3) Exp2 = Exp2 + 29 + 45 + 75;
		if (Exp2 > 600) Exp2 = 600;
	}
	else if (e1 >= 4 && e1 <= 99) {
		if (e1 >= 4 && e1 <= 19) {
			Exp2 = Exp2 + (e1 / 4.0) + 19;
			Exp1 = Exp1 - e1;
			if (Exp2 > 600) Exp2 = 600;
			if (Exp2 < 0) Exp2 = 0;
			if (Exp1 > 600) Exp1 = 600;
			if (Exp1 < 0) Exp1 = 0;
		}
		if (e1 >= 20 && e1 <= 49) {
			Exp2 = Exp2 + (e1 / 9.0) + 21;
			Exp1 = Exp1 - e1;
			if (Exp2 > 600) Exp2 = 600;
			if (Exp2 < 0) Exp2 = 0;
			if (Exp1 > 600) Exp1 = 600;
			if (Exp1 < 0) Exp1 = 0;
		}
		if (e1 >= 50 && e1 <= 65) {
			Exp2 = Exp2 + (e1 / 16.0) + 17;
			Exp1 = Exp1 - e1;
			if (Exp2 > 600) Exp2 = 600;
			if (Exp2 < 0) Exp2 = 0;
			if (Exp1 > 600) Exp1 = 600;
			if (Exp1 < 0) Exp1 = 0;
		}
		if (e1 >= 66 && e1 <= 79) {
			Exp1 = Exp1 - e1;
			Exp2 = ceil(Exp2 + (e1 / 4.0 + 19));
			if (Exp2 > 600) Exp2 = 600;
			if (Exp2 < 0) Exp2 = 0;
			if (Exp1 > 600) Exp1 = 600;
			if (Exp1 < 0) Exp1 = 0;
			if (Exp2 > 200) {
				Exp2 = ceil(Exp2 + (e1 / 9.0) + 27);
				if (Exp2 > 600) Exp2 = 600;
				if (Exp2 < 0) Exp2 = 0;
				if (Exp1 > 600) Exp1 = 600;
				if (Exp1 < 0) Exp1 = 0;
			}
		}
		if (e1 >= 80 && e1 <= 99) {
			Exp1 = Exp1 - e1;
			Exp2 = ceil(Exp2 + (e1 / 4.0) + 19);
			Exp2 = ceil(Exp2 + (e1 / 9.0) + 21);
			if (Exp2 > 600) Exp2 = 600;
			if (Exp2 < 0) Exp2 = 0;
			if (Exp1 > 600) Exp1 = 600;
			if (Exp1 < 0) Exp1 = 0;
			if (Exp2 > 400) {
				Exp2 = ceil(Exp2 + (e1 / 16.0) + 17);
				Exp2 = ceil(Exp2 * 1.15);
				if (Exp2 > 600) Exp2 = 600;
				if (Exp2 < 0) Exp2 = 0;
				if (Exp1 > 600) Exp1 = 600;
				if (Exp1 < 0) Exp1 = 0;
			}
		}
	}
	else {
		exp1 = 0;
		exp2 = 0;
		return -99;
	}

	if (Exp1 > 600) Exp1 = 600;
	if (Exp1 < 0) Exp1 = 0;
	if (Exp2 > 600) Exp2 = 600;
	if (Exp2 < 0) Exp2 = 0;
	exp1 = ceil(Exp1);
	exp2 = ceil(Exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
	if (E3 < 0 || E3 > 99) return -99;
	double hp1 = HP1;
	double exp1 = EXP1;
	double m1 = M1;
	double p1 = 0;
	double p2 = 0;
	int b[24];
	int res = 1000;
	int s = 0;
	int t = 1;
	//con duong 01
	for (int i = 0; i <= 23; i++) {
		b[i] = t * t;
		t++;
	}
	for (int i = 0; i < 24; i++) {
		if (abs(b[i] - exp1) < res) {
			res = abs(b[i] - exp1);
			s = b[i];
		}
	}
	if (s <= exp1) {
		p1 = 1;
	}
	else {
		p1 = ((double)exp1 / s + 80) / 123.0;
	}
	//con duong 02

	if (E3 % 2 != 0) {
		double mo1 = m1 / 2.0;
		do {
			if (hp1 < 200) {
				hp1 = ceilf(hp1 * 1.3);
				m1 -= 150;
			}
			else {
				hp1 = ceilf(hp1 * 1.1);
				m1 -= 70;
			}
			if (m1 < mo1) break;
			hp1 = check_HP(hp1);
			m1 = check_M(m1);
			if (exp1 < 400) {
				m1 -= 200;
			}
			else {
				m1 -= 120;
			}
			exp1 = ceilf(exp1 * 1.13);
			if (m1 < mo1) break;
			exp1 = check_EXP(exp1);
			m1 = check_M(m1);
			if (exp1 < 300) {
				m1 -= 100;
			}
			else {
				m1 -= 120;
			}
			exp1 = ceilf(exp1 * 0.9);
			if (m1 < mo1) break;
			m1 = check_M(m1);
			exp1 = check_EXP(exp1);
		} while (true);
		hp1 = ceilf(hp1 * 0.83);
		exp1 = ceilf(exp1 * 1.17);
		hp1 = check_HP(hp1);
		exp1 = check_EXP(exp1);
	}
	else {
		for (int i = 0; i < 1; i++) {
			if (hp1 < 200) {
				if (m1 - 150 <= 0) break;
				hp1 = ceilf(hp1 * 1.3);
				m1 -= 150;
			}
			else {
				if (m1 - 70 <= 0) break;
				hp1 = ceilf(hp1 * 1.1);
				m1 -= 70;
			}
			hp1 = check_HP(hp1);
			m1 = check_M(m1);

			if (exp1 < 400) {
				if (m1 - 200 <= 0) break;
				m1 -= 200;
			}
			else {
				if (m1 - 120 <= 0) break;
				m1 -= 120;
			}
			exp1 = ceilf(exp1 * 1.13);
			exp1 = check_EXP(exp1);
			m1 = check_M(m1);

			if (exp1 < 300) {
				if (m1 - 100 <= 0) break;
				m1 -= 100;
			}
			else {
				if (m1 - 120 <= 0) break;
				m1 -= 120;
			}
			exp1 = ceilf(exp1 * 0.9);
			m1 = check_M(m1);
			exp1 = check_EXP(exp1);

		}
	}
	double res2 = 1000;
	for (int i = 0; i < 24; i++) {
		if (abs(b[i] - exp1) < res2) {
			res2 = abs(b[i] - exp1);
			s = b[i];
		}
	}
		if (s <= exp1) {
			p2 = 1;
		}
		else {
			p2 = ((double)exp1 / s + 80) / 123.0;
		}
		// con duong 3
		int a[] = { 32,47,28,79,100,50,22,83,64,11 };
		double p = a[tong(E3)];
		double p3 = p / 100.0;
		if (p1 == 1 && p2 == 1 && p3 == 1) {
			exp1 = ceilf(exp1 * 0.75);
			exp1 = check_EXP(exp1);
		}
		else {
			double ptb = (p1 + p2 + p3) / 3.0;
			if (ptb < 0.5) {
				hp1 = ceilf(hp1 * 0.85);
				exp1 = ceilf(exp1 * 1.15);
			}
			else {
				hp1 = ceilf(hp1 * 0.9);
				exp1 = ceilf(exp1 * 1.2);
			}
		}
		EXP1 = check_EXP(exp1);
		M1 = check_M(m1);
		HP1 = check_HP(hp1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
	// TODO: Complete this function
	if (E3 < 0 || E3 > 99) return -99;
	double exp1 = EXP1;
	double exp2 = EXP2;
	double hp1 = HP1;
	double hp2 = HP2;
	int a[10][10];
	int b[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			b[i][j] = abs(find_max(a, i, j));
		}
	}
	int x = 0;
	int y = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (a[i][j] > 2 * E3) ++x;
			if (a[i][j] < -1 * E3) ++y;
		}

	}
	x = sum(x);
	y = sum(y);
	int res = 0;
	if (abs(a[x][y]) > b[x][y]) res = a[x][y];
	else res = b[x][y];
	if (abs(a[x][y]) > b[x][y]) {
		exp1 = ceilf(exp1 * 0.88);
		exp2 = ceilf(exp2 * 0.88);
		hp1 = ceilf(hp1 * 0.9);
		hp2 = ceilf(hp2 * 0.9);
	}
	else {
		exp1 = ceilf(exp1 * 1.12);
		exp2 = ceilf(exp2 * 1.12);
		hp1 = ceilf(hp1 * 1.1);
		hp2 = ceilf(hp2 * 1.1);
	}
	HP1 = check_HP(hp1);
	HP2 = check_HP(hp2);
	EXP1 = check_EXP(exp1);
	EXP2 = check_EXP(exp2);
	return res;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
	//tim 'se'
	int pos = 0;
	string EMAIL = email;
	for (int i = 0; i < EMAIL.length(); i++) {
		if (EMAIL[i] == '@') {
			pos = i;
			break;
		}
	}
	string se = EMAIL.substr(0, pos);
	int length = 0;
	//
	while (s[length] != '\0') {
		length++;
	}

	if (length < 8 ) return -1;
	if (length > 20) return -2;

	string S = s;
	char checkkitu = '\0';
	int count = 1;
	bool spec = false;

	for (int i = 0; i < S.length(); i++) {
		char kitu = S[i];
		if (!((kitu >= 'a' && kitu <= 'z') || (kitu >= 'A' && kitu <= 'Z') || (kitu >= '0' && kitu <= '9') || kitu == '@' || kitu == '#' || kitu == '%' || kitu == '$' || kitu == '!')) {
			int res = i;
			return res;
		}

		if (kitu == '@' || kitu == '#' || kitu == '%' || kitu == '$' || kitu == '!') {
			spec = true;
		}

		if (kitu == checkkitu) {
			count++;
			if (count > 2) {
				int res = i - 2;
				return -(400 + res);
			}
		}
		else {
			count = 1;
		}

		checkkitu = kitu;
	}

	if (!spec) {
		return -5;
	}
	// s da pass nhung filter, kiem tra s co chua se hay khong
	int t = 1;
	int S_count = 0;
	int se_count = 0;
	int res = 0;
	bool flag = 0;
	while (S_count <= S.length() - 1) {
		if (S[S_count] == se[se_count]) {
			S_count++;
			se_count++;
			t++;
		}
		else {
			S_count++;
			t = 1;
			se_count = 0;
		}
		if (t == se.length()) {
			res = S_count - t + 1;
			flag = 1;
			break;
		}
	}
	if (!flag) return -10;
	else {
		return -(300 + res);
	}
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
	int chiso = 0;
	int n = num_pwds;
	int m = 1;
	int count = 1;
	string mk[n];
	for (int i = 0; i < n; i++) {
		mk[i] = arr_pwds[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (mk[i] == mk[j]) count++;
		}
		if (count > m || (count == m && mk[i].length() > mk[chiso].length())) {
			m = count;
			chiso = i;
		}
		count = 1;
	}
	return chiso;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////