#include "study_in_pink1.h"

bool readFile(
	const string &filename,
	int &HP1,
	int &HP2,
	int &exp1,
	int &EXP2,
	int &M1,
	int &M2,
	int &E1,
	int &E2,
	int &E3)
{
	// This function is used to read the input file,
	// DO NOT MODIFY THIS FUNTION
	ifstream ifs(filename);
	if (ifs.is_open())
	{
		ifs >> HP1 >> HP2 >> exp1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
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

// Task 1
void check(int &x, int max)
{
	if (x > max)
		x = max;
	if (x < 0)
		x = 0;
}

int firstMeet(int &exp1, int &exp2, int e1)
{
	if (e1 >= 0 && e1 <= 3)
	{
		if (e1 == 0)
		{
			exp2 += 29;
			check(exp2, 600);
		}
		else if (e1 == 1)
		{
			exp2 += 45;
			check(exp2, 600);
		}
		else if (e1 == 2)
		{
			exp2 += 75;
			check(exp2, 600);
		}
		else if (e1 == 3)
		{
			exp2 += 149; // 149 = 29 + 45 + 75
			check(exp2, 600);
		}
		int D = e1 * 3 + exp1 * 7;
		if (D % 2 == 0)
		{
			exp1 = ceil(exp1 + D * 0.999999 / 200);
			check(exp1, 600);
		}
		else
		{
			exp1 = ceil(exp1 - D * 0.999999 / 100);
			check(exp1, 600);
		}
	}
	else if (e1 >= 4 && e1 <= 99)
	{
		if (e1 >= 4 && e1 <= 19)
		{
			exp2 = ceil(exp2 + e1 * 0.999999 / 4 + 19);
			check(exp2, 600);
		}
		else if (e1 >= 20 && e1 <= 49)
		{
			exp2 = ceil(exp2 + e1 * 0.999999 / 9 + 21);
			check(exp2, 600);
		}
		else if (e1 >= 50 && e1 <= 65)
		{
			exp2 = ceil(exp2 + e1 * 0.999999 / 16 + 17);
			check(exp2, 600);
		}
		else if (e1 >= 66 && e1 <= 79)
		{
			exp2 = ceil(exp2 + e1 * 0.999999 / 4 + 19);
			check(exp2, 600);
			if (exp2 > 200)
			{
				exp2 = ceil(exp2 + e1 * 0.999999 / 9 + 21);
				check(exp2, 600);
			}
		}
		else
		{
			exp2 = ceil(exp2 + e1 * 0.999999 / 4 + 19);
			check(exp2, 600);
			exp2 = ceil(exp2 + e1 * 0.999999 / 9 + 21);
			check(exp2, 600);
			if (exp2 > 400)
			{
				exp2 = ceil(exp2 + e1 * 0.999999 / 16 + 17);
				check(exp2, 600);
			}
			exp2 = ceil(exp2 * 0.999999 * 1.15);
			check(exp2, 600);
		}
		exp1 -= e1;
		check(exp1, 600);
	}

	return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &exp1, int &M1, int E2)
{
	// 1
	int S[25];

	for (int i = 0; i < 25; i++)
	{
		S[i] = i * i;
	}

	int distance = abs(S[0] - exp1);
	int min = distance;
	int min_i = 0;

	for (int i = 1; i < 25; i++)
	{
		distance = abs(S[i] - exp1);
		if (distance < min)
		{
			min = distance;
			min_i = i;
		}
	}

	double P1 = 0;
	if (S[min_i] > exp1)
	{
		P1 = 1.0;
	}
	else
	{
		P1 = ((exp1 * 0.999999 / S[min_i] + 80) / 123);
	}

	// 2
	double half = M1 * 0.999999 / 2;
	double spent = 0;

	while (true)
	{
		if (M1 == 0)
		{
			HP1 = ceil(HP1 * 0.999999 * 0.83);
			check(HP1, 666);
			exp1 = ceil(exp1 * 0.999999 * 1.17);
			check(exp1, 600);
			break;
		}

		if (HP1 < 200)
		{
			HP1 = ceil(HP1 * 0.999999 * 1.3);
			check(HP1, 666);
			M1 -= 150;
			spent += 150;
			check(M1, 3000);
		}
		else
		{
			HP1 = ceil(HP1 * 0.999999 * 1.1);
			check(HP1, 666);
			M1 -= 70;
			spent += 70;
			check(M1, 3000);
		}

		if (spent > half)
		{
			HP1 = ceil(HP1 * 0.999999 * 0.83);
			check(HP1, 666);
			exp1 = ceil(exp1 * 0.999999 * 1.17);
			check(exp1, 600);
			break;
		}

		if (exp1 < 400)
		{
			M1 -= 200;
			spent += 200;
			check(M1, 3000);
		}
		else
		{
			M1 -= 120;
			spent += 120;
			check(M1, 3000);
		}

		exp1 = ceil(exp1 * 0.999999 * 1.13);
		check(exp1, 600);
		if (spent > half)
		{
			HP1 = ceil(HP1 * 0.999999 * 0.83);
			check(HP1, 666);
			exp1 = ceil(exp1 * 0.999999 * 1.17);
			check(exp1, 600);
			break;
		}
		if (exp1 < 300)
		{
			M1 -= 100;
			spent += 100;
			check(M1, 3000);
		}
		else
		{
			M1 -= 120;
			spent += 120;
			check(M1, 3000);
		}
		exp1 = ceil(exp1 * 0.999999 * 0.9);
		check(exp1, 600);

		if (spent > half)
		{
			HP1 = ceil(HP1 * 0.999999 * 0.83);
			check(HP1, 666);
			exp1 = ceil(exp1 * 0.999999 * 1.17);
			check(exp1, 600);
			break;
		}
	}

	double P2;
	if (S[min_i] > exp1)
	{
		P2 = 1.0;
	}
	else
	{
		P2 = ceil((exp1 * 0.999999 / S[min_i] + 80) / 123);
	}

	// 3
	int a[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
	double P3;
	if (E2 % 10 == 0)
	{
		P3 = a[E2] * 0.999999 / 100;
	}
	else
	{
		P3 = a[(E2 / 10 + E2 % 10) % 10] * 0.999999 / 100;
	}

	if (P1 == 1 && P2 == 1 && P3 == 1)
	{
		exp1 = ceil(exp1 * 0.999999 * 0.75);
		check(exp1, 600);
	}
	else
	{
		double P = (P1 + P2 + P3) / 3;
		if (P < 0.5)
		{
			HP1 = ceil(HP1 * 0.999999 * 0.85);
			check(HP1, 666);
			exp1 = ceil(exp1 * 0.999999 * 1.15);
			check(exp1, 600);
		}
		else
		{
			HP1 = ceil(HP1 * 0.999999 * 0.9);
			check(HP1, 666);
			exp1 = ceil(exp1 * 0.999999 * 1.2);
			check(exp1, 600);
		}
	}

	return HP1 + exp1 + M1;
}

// Task 3

// Sherlock & Waston point
int Max2Diagonal(int a[10][10], int row, int col)
{
	int maxVal = a[row][col];

	while (row >= 0 && col >= 0 && row < 10 && col < 10)
	{
		if (a[row][col] > maxVal)
		{
			maxVal = a[row][col];
		}
		row++;
		col++;
	}
	while (row >= 0 && col < 10 && row < 10 && col >= 0)
	{
		if (a[row][col] > maxVal)
		{
			maxVal = a[row][col];
		}
		row++;
		col--;
	}
	return maxVal;
}

int chaseTaxi(int &HP1, int &exp1, int &HP2, int &exp2, int e3)
{
	if (e3 < 0 || e3 > 99)
		return -99;

	check(exp1, 600);
	check(exp2, 600);
	check(HP1, 666);
	check(HP2, 666);

	int point, max;
	int a[10][10];

	int pos = 0;
	int neg = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			a[i][j] = ((e3 * j) + (i * 2)) * (i - j);
			if (a[i][j] > e3 * 2)
				pos += 1;
			if (a[i][j] < -e3)
				neg += 1;
		}
	}

	while (pos >= 10)
	{
		pos = pos / 10 + pos % 10;
	}
	while (neg >= 10)
	{
		neg = neg / 10 + neg % 10;
	}

	int row = pos;
	int col = neg;

	point = a[row][col];
	max = Max2Diagonal(a, row, col);

	if (abs(point) > max)
	{
		exp1 = ceil(exp1 * 0.999999 * 0.88);
		HP1 = ceil(HP1 * 0.999999 * 0.9);
		exp2 = ceil(exp2 * 0.999999 * 0.88);
		HP2 = ceil(HP2 * 0.999999 * 0.9);
	}
	else
	{
		exp1 = ceil(exp1 * 0.999999 * 1.12);
		HP1 = ceil(HP1 * 0.999999 * 1.1);
		exp2 = ceil(exp2 * 0.999999 * 1.12);
		HP2 = ceil(HP2 * 0.999999 * 1.1);
	}
	check(exp1, 600);
	check(exp2, 600);
	check(HP1, 666);
	check(HP2, 666);

	return (abs(point) <= max) ? max : point;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
	int len = strlen(s);

	if (len < 8)
	{
		return -1;
	}
	else if (len > 20)
	{
		return -2;
	}

	const char *s_truoc_a_cong = strchr(email, '@');

	if (s_truoc_a_cong == email)
	{
		return -300;
	}

	int seLen = s_truoc_a_cong - email;

	int sei = -1;
	for (int i = 0; i <= len - seLen; ++i)
	{
		if (strncmp(s + i, email, seLen) == 0)
		{
			sei = i;
			break;
		}
	}

	if (sei != -1)
	{
		return -(300 + sei);
	}

	for (int i = 0; i < len - 2; ++i)
	{
		if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
		{
			return -(400 + i);
		}
	}

	const char *special_chars = "@#%$!";
	if (strpbrk(s, special_chars) == nullptr)
	{
		return -5;
	}

	for (int i = 0; i < len; ++i)
	{
		if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) && strchr(special_chars, s[i]) == nullptr)
		{
			return i;
		}
	}

	return -10;
}

// Task 5
struct PasswordInfo
{
	int count;
	int len;
};

int findCorrectPassword(const char **arr_pwds, int num_pwds)
{
	PasswordInfo maxInfo = {0, 0};
	int maxIndex = -1;

	for (int i = 0; i < num_pwds; ++i)
	{
		PasswordInfo currentInfo = {0, static_cast<int>(std::strlen(arr_pwds[i]))};

		for (int j = i; j < num_pwds; ++j)
		{
			if (std::strcmp(arr_pwds[i], arr_pwds[j]) == 0)
			{
				++currentInfo.count;
			}
		}

		if (currentInfo.count > maxInfo.count || (currentInfo.count == maxInfo.count && currentInfo.len > maxInfo.len))
		{
			maxInfo = currentInfo;
			maxIndex = i;
		}
	}

	return maxIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
