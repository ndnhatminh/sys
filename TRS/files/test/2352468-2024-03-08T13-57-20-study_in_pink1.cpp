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

int check(int n, int firstpoint, int lastpoint) {
	if (n < firstpoint)
	{
		n = firstpoint;
	}
	else if (n > lastpoint)
	{
		n = lastpoint;
	}
	return n;
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
	if (e1 > 99 || e1 < 0)
	{
		return -99;
	}
	int firstpoint = 0;
	int lastpoint = 600;
	exp1 = check(exp1, firstpoint, lastpoint);
	exp2 = check(exp2, firstpoint, lastpoint);
	double exp1F = exp1, exp2F = exp2;

	if (e1 >= 0 && e1 <= 3)
	{
		switch (e1) {
		case 0:
			exp2F = exp2F + 29;
			break;
		case 1:
			exp2F = exp2F + 45;
			break;
		case 2:
			exp2F = exp2F + 75;
			break;
		case 3:
			exp2F = exp2F + 29 + 45 + 75;
			break;
		}
		exp2F = check(exp2F, firstpoint, lastpoint);

		int D = e1 * 3 + exp1 * 7;
		if (D % 2 == 0)
		{
			exp1F = ceil(exp1F + D / 200.0);
		}
		else if (D % 2 != 0)
		{
			exp1F = ceil(exp1F - D / 100.0);
		}
		exp1F = check(exp1F, firstpoint, lastpoint);
	}

	else if (e1 >= 4 && e1 <= 99)
	{
		if (e1 >= 4 && e1 <= 19)
		{
			exp2F = ceil(exp2F + e1 / 4.0 + 19);
		}
		else if (e1 >= 20 && e1 <= 49)
		{
			exp2F = ceil(exp2F + e1 / 9.0 + 21);
		}
		else if (e1 >= 50 && e1 <= 65)
		{
			exp2F = ceil(exp2F + e1 / 16.0 + 17);
		}
		else if (e1 >= 66 && e1 <= 79)
		{
			exp2F = ceil(exp2F + e1 / 4.0 + 19);
			if (exp2F > 200)
			{
				exp2F = ceil(exp2F + e1 / 9.0 + 21);
			}
		}
		else if (e1 >= 80 && e1 <= 99)
		{
			exp2F = ceil(exp2F + e1 / 4.0 + 19);
			exp2F = ceil(exp2F + e1 / 9.0 + 21);
			if (exp2F > 400)
			{
				exp2F = ceil(exp2F + e1 / 16.0 + 17);
				exp2F = ceil(exp2F + exp2F * 0.15);
			}
		}
		exp1F = exp1F - e1;
	}
	exp1 = exp1F;
	exp1 = check(exp1, firstpoint, lastpoint);
	exp2 = exp2F;
	exp2 = check(exp2, firstpoint, lastpoint);
	return exp1 + exp2;
}


// Task 2
int square(int exp1) {
	for (int i = 0; i < exp1; i++)
	{
		if (i * i > exp1)
		{
			int smaller = (i - 1) * (i - 1);
			int bigger = i * i;
			if (abs(smaller - exp1) < abs(bigger - exp1))
			{
				return smaller;
			}
			return bigger;
		}
		else if (i * i == exp1)
		{
			return i * i;
		}
	}
	return -1;
}
//int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
//	int P1;
//	int S = square(EXP1);
//	if (EXP1 >= S)
//	{
//		P1 = 1;
//	}
//	else P1 = (EXP1 / S + 80) / 123;
//	//first event
//	if (HP1 < 200)
//	{
//		HP1 = HP1 + HP1 * 0.3;
//		M1 = M1 - 150;
//	}
//	else
//	{
//		HP1 = HP1 + HP1 * 0.1;
//		M1 = M1 - 70;
//	}
//}
//
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
	if (E2 < 0 || E2 > 99)
	{
		return -99;
	}
	int expFirstpoint = 0;
	int expLastpoint = 600;
	int hpFirstpoint = 0;
	int hpLastpoint = 666;
	int moneyFirstpoint = 0;
	int moneyLastpoint = 3000;
	HP1 = check(HP1, hpFirstpoint, hpLastpoint);
	EXP1 = check(EXP1, expFirstpoint, expLastpoint);
	M1 = check(M1, moneyFirstpoint, moneyLastpoint);
	double exp1F = EXP1, hp1F = HP1, m1F = M1;
	bool flag = true;

	//con duong 1
	int S = square(exp1F);
	double P1 = 0;
	if (exp1F >= S)
	{
		P1 = 1;
	}
	else
	{
		P1 = (exp1F / S + 80) / 123;
	}

	//con duong 2
	int spending = 0;
	double limit = m1F * 0.5;
	while (E2 % 2 == 0) //E2 chan
	{
		//su kien 1
		if (hp1F < 200)
		{
			hp1F = check(ceil(hp1F + hp1F * 0.3), hpFirstpoint, hpLastpoint);
			m1F = m1F - 150;
			spending = spending + 150;
		}
		else
		{
			hp1F = check(ceil(hp1F + hp1F * 0.1), hpFirstpoint, hpLastpoint);
			m1F = m1F - 70;
			spending = spending + 70;
		}
		if (m1F <= 0)
		{
			flag = false;
			break;
		}

		//su kien 2
		if (exp1F < 400)
		{
			m1F = m1F - 200;
			spending = spending + 200;
		}
		else
		{
			m1F = m1F - 120;
			spending = spending + 120;
		}
		exp1F = ceil(exp1F + exp1F * 0.13);
		if (m1F <= 0)
		{
			flag = false;
			break;
		}

		//su kien 3
		if (exp1F < 300)
		{
			m1F = m1F - 100;
			spending = spending + 100;
		}
		else
		{
			m1F = m1F - 120;
			spending = spending + 120;
		}
		exp1F = ceil(exp1F - exp1F * 0.1);
		break;
	}

	while (E2 % 2 != 0) //E2 le
	{
		//su kien 1
		if (hp1F < 200)
		{
			hp1F = check(ceil(hp1F + hp1F * 0.3), hpFirstpoint, hpLastpoint);
			m1F = m1F - 150;
			spending = spending + 150;
		}
		else
		{
			hp1F = check(ceil(hp1F + hp1F * 0.1), hpFirstpoint, hpLastpoint);
			m1F = m1F - 70;
			spending = spending + 70;
		}
		if (spending > limit)
		{
			flag = false;
			break;
		}

		//su kien 2
		if (exp1F < 400)
		{
			m1F = m1F - 200;
			spending = spending + 200;
		}
		else
		{
			m1F = m1F - 120;
			spending = spending + 120;
		}
		exp1F = check(ceil(exp1F + exp1F * 0.13), expFirstpoint, expLastpoint);
		if (spending > limit)
		{
			flag = false;
			break;
		}

		//su kien 3
		if (exp1F < 300)
		{
			m1F = m1F - 100;
			spending = spending + 100;
		}
		else
		{
			m1F = m1F - 120;
			spending = spending + 120;
		}
		exp1F = check(ceil(exp1F - exp1F * 0.1), expFirstpoint, expLastpoint);
		if (spending > limit)
		{
			flag = false;
			break;
		}
	}
	if (flag == false)
	{
		hp1F = check(ceil(hp1F - hp1F * 0.17), hpFirstpoint, hpLastpoint);
		exp1F = check(ceil(exp1F + exp1F * 0.17), expFirstpoint, expLastpoint);
	}


	double P2 = 0;
	if (exp1F >= S)
	{
		P2 = 1;
	}
	else
	{
		P2 = (exp1F / S + 80) / 123;
	}

	//con duong 3
	double P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
	int idx = 0;
	double finalP = 0;
	if (E2 % 10 == E2) //1 chu so
	{
		idx = E2;
	}
	else
	{
		idx = (E2 / 10 + E2 % 10) % 10;
	}

	if (P1 == P2 && P2 == P[idx] / 100.0 && P[idx] == 100)
	{
		exp1F = check(ceil(exp1F - exp1F * 0.25), expFirstpoint, expLastpoint);
		finalP = 1;
	}
	else
	{
		finalP = (P1 + P2 + P[idx] / 100.0) / 3.0;
	}
	if (finalP < 0.5)
	{
		hp1F = check(ceil(hp1F - hp1F * 0.15), hpFirstpoint, hpLastpoint);
		exp1F = check(ceil(exp1F + exp1F * 0.15), expFirstpoint, expLastpoint);
	}
	else if (finalP >= 0.5 && finalP < 1)
	{
		hp1F = check(ceil(hp1F - hp1F * 0.1), hpFirstpoint, hpLastpoint);
		exp1F = check(ceil(exp1F + exp1F * 0.2), expFirstpoint, expLastpoint);
	}
	EXP1 = exp1F;
	EXP1 = check(EXP1, expFirstpoint, expLastpoint);
	HP1 = hp1F;
	HP1 = check(HP1, hpFirstpoint, hpLastpoint);
	M1 = m1F;
	M1 = check(M1, moneyFirstpoint, moneyLastpoint);
	return HP1 + EXP1 + M1;
}

// Task 3
int onenumber(int n) {
	if (n % 10 == n) return n;
	int newnumber = n / 10 + n % 10;
	return onenumber(newnumber);
}

int maxArray(int* arr)
{
	int max = -99999;
	for (int i = 0; i < 10; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}

int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
	if (E3 < 0 || E3 > 99)
	{
		return -99;
	}
	int expfirstpoint = 0;
	int explastpoint = 600;
	int hpfirstpoint = 0;
	int hplastpoint = 666;
	EXP1 = check(EXP1, expfirstpoint, explastpoint);
	EXP2 = check(EXP2, expfirstpoint, explastpoint);
	HP1 = check(HP1, hpfirstpoint, hplastpoint);
	HP2 = check(HP2, hpfirstpoint, hplastpoint);
	double exp1F = EXP1, exp2F = EXP2, hp1F = HP1, hp2F = HP2;
	int P[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			P[i][j] = 0;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			P[i][j] = ((E3 * j) + (i * 2)) * (i - j);
		}
	}
	int x = 0, y = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (P[i][j] > E3 * 2)
			{
				x++;
			}
			else if (P[i][j] < -E3)
			{
				y++;
			}
		}
	}
	x = onenumber(x);
	y = onenumber(y);
	int taxiscore = P[x][y];
	int left[10], right[10];
	for (int i = 0; i < 10; i++)
	{
		left[i] = 0;
		right[i] = 0;
	}
	int i = x;
	int j = y;
	int iter = 0;
	while (i > 0 && i < 9 && j > 0 && j < 9)
	{
		i--;
		j--;
	}
	while (i >= 0 && i < 10 && j >= 0 && j < 10)
	{
		left[iter] = P[i][j];
		i++;
		j++;
		iter++;
	}

	i = x;
	j = y;
	iter = 0;
	while (i > 0 && i < 9 && j > 0 && j < 9)
	{
		i--;
		j++;
	}
	while (i >= 0 && i < 10 && j >= 0 && j < 10)
	{
		right[iter] = P[i][j];
		i++;
		j--;
		iter++;
	}
	int sherlockscore = max(maxArray(left), maxArray(right));
	if (abs(taxiscore) > abs(sherlockscore))
	{
		exp1F = ceil(exp1F - exp1F * 0.12);
		exp2F = ceil(exp2F - exp2F * 0.12);
		hp1F = ceil(hp1F - hp1F * 0.1);
		hp2F = ceil(hp2F - hp2F * 0.1);
		EXP1 = exp1F;
		EXP1 = check(EXP1, expfirstpoint, explastpoint);
		HP1 = hp1F;
		HP1 = check(HP1, hpfirstpoint, hplastpoint);
		EXP2 = exp2F;
		EXP2 = check(EXP2, expfirstpoint, explastpoint);
		HP2 = hp2F;
		HP2 = check(HP2, hpfirstpoint, hplastpoint);
		return taxiscore;
	}
	else
	{
		exp1F = ceil(exp1F + exp1F * 0.12);
		exp2F = ceil(exp2F + exp2F * 0.12);
		hp1F = ceil(hp1F + hp1F * 0.1);
		hp2F = ceil(hp2F + hp2F * 0.1);
	}
	EXP1 = exp1F;
	EXP1 = check(EXP1, expfirstpoint, explastpoint);
	HP1 = hp1F;
	HP1 = check(HP1, hpfirstpoint, hplastpoint);
	EXP2 = exp2F;
	EXP2 = check(EXP2, expfirstpoint, explastpoint);
	HP2 = hp2F;
	HP2 = check(HP2, hpfirstpoint, hplastpoint);
	return sherlockscore;
}

// Task 4
int checkPassword(const char* s, const char* email) {
	string se;
	for (int i = 0; i < 100; i++)
	{
		if (email[i] != '@')
		{
			se = se + email[i];
		}
		else break;
	}
	string password(s);

	if (password.length() < 8)
	{
		return -1;
	}

	else if (password.length() > 20)
	{
		return -2;
	}

	if (password.find(se) != string::npos)
	{
		return (-1) * (300 + password.find(se));
	}

	char curr = ' ';
	int occur = 0;
	for (int i = 0; i < password.length(); i++)
	{
		if (password[i] != curr)
		{
			curr = password[i];
			occur = 1;
		}
		else
		{
			occur++;
		}
		if (occur == 3)
		{
			return (-1) * (400 + i - 2);
		}
	}

	bool flag = true;
	for (int i = 0; i < password.length(); i++)
	{
		if (password[i] == '@' || password[i] == '#' || password[i] == '%' || password[i] == '$' || password[i] == '!')
		{
			flag = false;
			break;
		}
	}
	if (flag == true)
	{
		return -5;
	}

	for (int i = 0; i < password.length(); i++)
	{
		if ((password[i] < 48 || password[i] > 57) &&
			(password[i] < 65 || password[i] > 90) &&
			(password[i] < 97 || password[i] > 122) &&
			password[i] != 64 && password[i] != 35 && password[i] != 37 &&
			password[i] != 36 && password[i] != 33
			)
		{
			return i;
		}
	}
	return -10;
}

// Task 5
const int MAX_PWD = 1000;
bool searchArray(char* arr[], const char* find)
{
	for (int i = 0; i < MAX_PWD; i++)
	{
		if (arr[i] == find)
		{
			return true;
		}
	}
	return false;
}

int findIndexInArray(char* arr[], const char* find)
{
	for (int i = 0; i < MAX_PWD; i++)
	{
		if (arr[i] == find)
		{
			return i;
		}
	}
	return -1;
}

int findMax(char* allpassword[], int* occurArr)
{
	int occur = 0;
	int maxOccur = maxArray(occurArr);
	//cout << "maxOccur: " << maxOccur << endl;
	int maxOccurIndex[MAX_PWD];
	for (int i = 0; i < MAX_PWD; i++)
	{
		maxOccurIndex[i] = 0;
	}
	for (int i = 0; i < MAX_PWD; i++)
	{
		if (occurArr[i] == maxOccur)
		{
			maxOccurIndex[i] = strlen(allpassword[i]);
		}
	}
	int longest = maxArray(maxOccurIndex);
	//cout << "longest: " << longest << endl;
	for (int i = 0; i < MAX_PWD; i++)
	{
		if (strlen(allpassword[i]) == longest && occurArr[i] == maxOccur)
		{
			return i;
		}
	}
	return -1;
}

int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
	char* allpassword[MAX_PWD];
	int occur[MAX_PWD];
	for (int i = 0; i < MAX_PWD; i++)
	{
		allpassword[i] = (char*)" ";
		occur[i] = 0;
	}
	int iter = 0;
	for (int i = 0; i < num_pwds; i++)
	{
		if (searchArray(allpassword, arr_pwds[i]) == true)
		{
			occur[findIndexInArray(allpassword, arr_pwds[i])]++;
		}
		else
		{
			allpassword[iter] = (char*)arr_pwds[i];
			occur[iter] = 1;
			iter++;
		}
	}
	//for (int i = 0; i < MAX_PWD; i++)
	//{
	//    cout << i << ". " << allpassword[i] << " " << occur[i] << endl;
	//}
	return findMax(allpassword, occur);
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////