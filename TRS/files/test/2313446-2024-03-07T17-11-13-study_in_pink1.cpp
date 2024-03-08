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

void checkEXP(int& exp)
{
	if (exp > 600) exp = 600;
	if (exp < 0) exp = 0;
	
}
void checkHP(int& hp)
{
	if (hp > 666) hp = 666;
	if (hp < 0) hp = 0;
}
void checkM(int& m)
{
	if (m > 3000) m = 3000;
	if (m < 0) m = 0;
}
double maxval(double a, double b)
{
	double max = a;
	if (b > a) max = b;
	return max;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
	if (e1 < 0 && e1>99) return -99;
	//truong hop 1
	double n, m;
	double k = e1;
	if (e1 < 4)
	{
		if (e1 == 0) { n = exp2 + 29; exp2 = ceil(n); }
		if (e1 == 1) { n = exp2 + 45; exp2 = ceil(n); }
		if (e1 == 2) { n = exp2 + 75; exp2 = ceil(n); }
		if (e1 == 3) { n = exp2 + 29 + 45 + 75; exp2 = ceil(n); }
		int D = k * 3 + exp1 * 7;
		if (D % 2 == 0) { m = exp1 + D / 200; exp1 = ceil(m); }
		if (D % 2 == 1) { m = exp1 - D / 100; exp1 = ceil(m); }
		checkEXP(exp1);
		checkEXP(exp2);


	}
	else
	{
		if (e1 >= 4 && e1 <= 19) { n = exp2 + (k / 4 + 19); exp2 = ceil(n); }
		if (e1 >= 20 && e1 <= 49) { n = exp2 + (k / 9 + 21); exp2 = ceil(n); }
		if (e1 >= 50 && e1 <= 65) { n = exp2 + (k / 16 + 17); exp2 = ceil(n); }
		if (e1 >= 66 && e1 <= 79)
		{
			n = exp2 + (k / 4 + 19);
			exp2 = ceil(n);
			if (exp2 > 200) { n = exp2 + (k / 4 + 19); exp2 = ceil(n); }
		}
		if (e1 >= 80 && e1 <= 99)
		{
			n = exp2 + (k / 4 + 19);
			n = n + (k / 9 + 21);
			exp2 = ceil(n);
			if (exp2 > 400) { n = exp2 + (k / 16 + 17); exp2 = ceil(n); }
			n = exp2 * 1.15;
			exp2 = ceil(n);
		}
		exp1 = exp1 - e1;
		exp1 = ceil(exp1);
		checkEXP(exp1);
		checkEXP(exp2);

	}
    return exp1 + exp2;
}
double findNum(int e)
{
	int S;
	int a = sqrt(e);
	int b = a + 1;
	if (abs(e - a * a) <= abs(e - b * b)) S = a * a;
	else S = b * b;
	double p1;
	if (e >= S) p1 = 1;
	else p1 = (e / S + 80) / 123;
	return p1;
}

int adddigits(int a)
{
	while (a >= 10)
	{
		int sum = 0;
		sum += a % 10;
		a /= 10;
		sum += a % 10;
		a /= 10;
		a += sum;
	}
	return a;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
	//conduong1
	double p1, p2, p3;
	p1 = findNum(EXP1);
	//conduong2
	double h = static_cast<double>(HP1);
	double e = static_cast<double>(EXP1);
	if (E2 % 2 != 0)
	{
		double t = 0;
		double n = static_cast<double>(M1) / 2;
		while (t >= 0)
		{
			if (h < 200)
			{
				h = h * 1.3;
				M1 = M1 - 150;
				t = t + 150;
			}
			else
			{
				h = h * 1.1;
				M1 = M1 - 70;
				t = t + 70;
			}

			h = ceil(h);
			if (t > n) break;
			if (e < 400)
			{
				M1 = M1 - 200;
				t = t + 200;
				e = e * 1.13;
			}
			else
			{
				M1 = M1 - 120;
				t = t + 120;
				e = e * 1.13;
			}
			e = ceil(e);
			if (t > n) break;
			if (e < 300)
			{
				M1 = M1 - 100;
				t = t + 100;
				e = e * 0.9;
			}
			else
			{
				M1 = M1 - 120;
				t = t + 120;
				e = e * 0.9;
			}
			e = ceil(e);
			if (t > n) break;
		}
		h = h * 0.83;
		e = e * 1.17;
		HP1 = ceil(h);
		EXP1 = ceil(e);
		h = HP1;
		e = EXP1;
	}
	else
	{
		if (h < 200)
		{
			h = h * 1.3;
			M1 = M1 - 150;
		}
		else
		{
			h = h * 1.1;
			M1 = M1 - 70;
		}
		h = ceil(h);
		if (M1 <= 0) { M1 = 0; goto x; }
		if (e < 400)
		{
			M1 = M1 - 200;
			e = e * 1.13;
		}
		else
		{
			M1 = M1 - 120;
			e = e * 1.13;
		}
		e = ceil(e);
		if (M1 <= 0) { M1 = 0; goto x; }
		if (e < 300)
		{
			M1 = M1 - 100;
			e = e * 0.9;
		}
		else
		{
			M1 = M1 - 120;
			e = e * 0.9;
		}
		e = ceil(e);
		if (M1 <= 0) { M1 = 0; goto x; }
	x:      h = h * 0.83;
		e = e * 1.17;
		HP1 = ceil(h);
		EXP1 = ceil(e);
		e = EXP1;
		h = HP1;
	}
	p2 = findNum(EXP1);
	//conduong3
	int P[10] = { 32,47,28,79,100,50,22,83,64,11 };
	int i;
	if (E2 / 10 == 0)
	{
		i = E2;
		p3 = static_cast<double>(P[i]) / 100;
	}
	if (E2 / 10 > 0)
	{
		int sum = 0;
		int a = E2;
		sum += a % 10;
		a /= 10;
		sum += a % 10;
		a /= 10;
		a += sum;
		i = a % 10;
		p3 = static_cast<double>(P[i]) / 100;
	}
	//final
	if (p1 == 1 && p2 == 1 && p3 == 1) { e = e * 0.75; EXP1 = ceil(e); }
	else
	{
		double p = (p1 + p2 + p3) / 3;
		if (p < 0.5) { h = h * 0.85; e = e * 1.15; }
		else { h = h * 0.9; e = e * 1.20; }
		HP1 = ceil(h);
		EXP1 = ceil(e);
	}
	checkHP(HP1);
	checkEXP(EXP1);
	checkM(M1);
	return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
	double P[10][10];
	int p = 0; int q = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			P[i][j] = ((E3 * j) + (i * 2)) * (i - j);
			if (P[i][j] > (E3 * 2)) p++;
			if (P[i][j] < (0 - E3)) q++;
		}
	p = adddigits(p);
	q = adddigits(q);
	int max = P[p][q];
	for (int i = 1; i < min(p, q) + 1; i++)
	{
		if (P[p - i][q - i] > max) max = P[p - i][q - i];
	}
	for (int i = 1; i < 10 - maxval(p, q); i++)
	{
		if (P[p + i][q + i] > max) max = P[p + i][q + i];
	}
	for (int i = 1; i < 10; i++)
	{
		if (p + i > 9 || q - i < 0) break;
		else if (P[p + i][q - i] > max) max = P[p + i][q - i];
	}
	for (int i = 1; i < 10; i++)
	{
		if (p - i < 0 || q + i > 9) break;
		else if (P[p - i][q + i] > max) max = P[p - i][q + i];
	}
	if (abs(P[p][q]) > max)
	{
		EXP1 = EXP1 * 0.88; EXP1 = ceil(EXP1);
		HP1 = HP1 * 0.9; HP1 = ceil(HP1);
		EXP2 = EXP2 * 0.88; EXP2 = ceil(EXP2);
		HP2 = HP2 * 0.9; HP2 = ceil(HP2);
		max = P[p][q];
	}
	else
	{
		EXP1 = EXP1 * 1.12; EXP1 = ceil(EXP1);
		HP1 = HP1 * 1.1; HP1 = ceil(HP1);
		EXP2 = EXP2 * 1.12; EXP2 = ceil(EXP2);
		HP2 = HP2 * 1.1; HP2 = ceil(HP2);
	}
	checkEXP(EXP1);
	checkHP(HP1);
	checkEXP(EXP2);
	checkHP(HP2);
	return max;
  
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
	if (strlen(s) < 8) return -1;
	if (strlen(s) > 20) return -2;
	const char* temp = strchr(email, '@');
	int len = temp - email;
	char* se = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		se[i] = email[i];
	}
	se[len] = '\0';
	int f = strstr(s, se) - s;
	bool special = false;
	for (int j = 0; j < strlen(s); j++)
	{
		if (s[j] == '@' || s[j] == '#' || s[j] == '%' || s[j] == '$' || s[j] == '!')
		{
			special = true;
			break;
		}
	}
	if (!special) return -5;
	for (int i = 0; i < strlen(s) - 2; i++)
	{
		if (s[i] == s[i + 1] && s[i] == s[i + 2]) return -(400 + i);

	}
	for (int k = 0; k < strlen(s); k++)
	{
		if (!(isdigit(s[k]) || isalpha(s[k]) || s[k] == '@' || s[k] == '#' || s[k] == '%' || s[k] == '$' || s[k] == '!')) {
			return k + 1;
		}
	}
	if (f > 0 && f < 100) return  -(300 + f);
	return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

	int mc = 0;
	int s = -1;
	for (int i = 0; i < num_pwds; i++)
	{
		int c = 0;
		for (int j = 0; j < num_pwds; j++)
		{
			if (arr_pwds[i] == arr_pwds[j]) c++;

		}
		if (c > mc)
		{
			mc = c;
			s = i;
		}
		if (c == mc)
		{
			if (strlen(arr_pwds[i]) > strlen(arr_pwds[s]))
				s = i;
		}
	}
	return s;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////