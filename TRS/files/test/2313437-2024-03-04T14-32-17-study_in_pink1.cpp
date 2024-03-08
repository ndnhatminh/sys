#include "study_in_pink1.h"

bool readFile(
	const string &filename,
	int &HP1,
	int &HP2,
	int &EXP1,
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

void checkHP(int &HP)
{
	if (HP < 0)
		HP = 0;
	if (HP > 666)
		HP = 666;
}

void checkEXP(int &EXP)
{
	if (EXP < 0)
		EXP = 0;
	if (EXP > 600)
		EXP = 600;
}

void checkMoney(int &M)
{
	if (M < 0)
		M = 0;
	if (M > 3000)
		M = 3000;
}

////////////////////////////////////////////////////////////////////////

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
	// TODO: Complete this function
	checkEXP(exp1);
	checkEXP(exp2);
	if (e1 < 0 || e1 > 99)
		return -99;
	if (e1 >= 0 && e1 <= 3)
		caseFirst(exp1, exp2, e1);
	if (e1 >= 4 && e1 <= 99)
		caseSecond(exp1, exp2, e1);
	return exp1 + exp2;
}
void caseFirst(int &exp1, int &exp2, int e1)
{
	switch (e1)
	{
	case 0:
		exp2 = exp2 + 29;
		checkEXP(exp2);
		break;
	case 1:
		exp2 = exp2 + 45;
		checkEXP(exp2);
		break;
	case 2:
		exp2 = exp2 + 75;
		checkEXP(exp2);
		break;
	case 3:
		exp2 = exp2 + 149;
		checkEXP(exp2);
		break;
	};
	int D = 0;
	D = e1 * 3 + exp1 * 7;
	if (D % 2 == 1)
		exp1 = ceil(exp1 - D / 100.0);
	else
		exp1 = ceil(exp1 + D / 200.0);
	checkEXP(exp1);
};
void caseSecond(int &exp1, int &exp2, int e1)
{
	if (e1 >= 4 && e1 <= 19)
	{
		exp2 = ceil(exp2 + (e1 / 4.0) + 19);
		checkEXP(exp2);
	};
	if (e1 >= 20 && e1 <= 49)
	{
		exp2 = ceil(exp2 + (e1 / 9.0) + 21);
		checkEXP(exp2);
	}
	if (e1 >= 50 && e1 <= 65)
	{
		exp2 = ceil(exp2 + (e1 / 16.0) + 17);
		checkEXP(exp2);
	}

	if (e1 >= 66 && e1 <= 79)
	{
		exp2 = ceil(exp2 + (e1 / 4.0) + 19);
		checkEXP(exp2);
		if (exp2 > 200)
		{
			exp2 = ceil(exp2 + (e1 / 9.0) + 21);
			checkEXP(exp2);
		}
	}

	if (e1 >= 80 && e1 <= 99)
	{
		exp2 = ceil(exp2 + (e1 / 4.0) + 19);
		checkEXP(exp2);
		exp2 = ceil(exp2 + (e1 / 9.0) + 21);
		checkEXP(exp2);
		if (exp2 > 400)
		{
			exp2 = ceil(exp2 + (e1 / 16.0) + 17);
			checkEXP(exp2);
			exp2 = ceil(exp2 * 1.15);
			checkEXP(exp2);
		}
	}
	exp1 = exp1 - e1;
	checkEXP(exp1);
};
// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
	// TODO: Complete this function

	if (E2 < 0 || E2 > 99)
		return -99;
	double p1{}, p2{}, p3{};
	checkHP(HP1);
	checkEXP(EXP1);
	checkMoney(M1);
	p1 = pathFirst(EXP1);
	p2 = pathSecond(HP1, EXP1, M1, E2);
	p3 = pathThird(E2);
	double p{};
	p = (p1 + p2 + p3) / 3.0;

	if (p == 1)
		EXP1 = ceil(EXP1 * 0.75);

	else if (p < 0.5)
	{
		HP1 = ceil(HP1 * 85.0 / 100.0);
		EXP1 = ceil(EXP1 * 1.15);
	}
	else
	{
		HP1 = ceil(HP1 * 90.0 / 100.0);
		EXP1 = ceil(EXP1 * 1.2);
	}
	checkHP(HP1);
	checkEXP(EXP1);
	return HP1 + EXP1 + M1;
};

double pathFirst(int EXP1)
{
	checkEXP(EXP1);
	int upNum{}, downNum{};
	for (int i = 0; pow(i, 2) < EXP1; i++)
	{
		upNum = pow(i + 1, 2);
		downNum = pow(i, 2);
	}
	int S{};
	if ((upNum - EXP1) < (EXP1 - downNum))
		S = upNum;
	else
		S = downNum;

	if (EXP1 >= S)
		return 1;
	double p1 = ((EXP1 / S + 80) / 123.0);
	return p1;
}

double pathSecond(int &HP1, int &EXP1, int &M1, int E2)
{
	int spendLimit{}, spent{};
	spendLimit = ceil(M1 / 2.0);
	bool breakCheck = 0;
	if (E2 % 2 == 1)
	{
		while (E2 % 2 == 1)
		{
			pathSecondTaskFirst(HP1, M1, spent);
			if (spent > spendLimit || M1 == 0)
			{
				breakCheck = 1;
				break;
			}
			pathSecondTaskSecond(EXP1, M1, spent);
			if (spent > spendLimit || M1 == 0)
			{
				breakCheck = 1;
				break;
			}
			pathSecondTaskThird(EXP1, M1, spent);
			if (spent > spendLimit || M1 == 0)
			{
				breakCheck = 1;
				break;
			}
		}
	}
	else
	{
		while (E2 % 2 == 0)
		{
			pathSecondTaskFirst(HP1, M1, spent);
			if (M1 == 0)
			{
				breakCheck = 1;
				break;
			}
			pathSecondTaskSecond(EXP1, M1, spent);
			if (M1 == 0)
			{
				breakCheck = 1;
				break;
			}
			pathSecondTaskThird(EXP1, M1, spent);
			breakCheck = 1;
			break;
		}
	}

	if (breakCheck)
	{
		HP1 = ceil(HP1 * 83.0 / 100.0);
		EXP1 = ceil(EXP1 * 1.17);
		checkHP(HP1);
		checkEXP(EXP1);
	}
	double p2 = pathFirst(EXP1);
	return p2;
}

void pathSecondTaskFirst(int &HP1, int &M1, int &spent)
{
	if (HP1 < 200)
	{
		HP1 = ceil(HP1 * 130.0 / 100.0);
		M1 = M1 - 150;
		spent = spent + 150;
	}
	else
	{
		HP1 = ceil(HP1 * 110.0 / 100);
		M1 = M1 - 70;
		spent = spent + 70;
	}
	checkHP(HP1);
	checkMoney(M1);
}

void pathSecondTaskSecond(int &EXP1, int &M1, int &spent)
{
	if (EXP1 < 400)
	{
		M1 = M1 - 200;
		spent = spent + 200;
	}
	else
	{
		M1 = M1 - 120;
		spent = spent + 120;
	}
	EXP1 = ceil(EXP1 * 1.13);
	checkMoney(M1);
	checkEXP(EXP1);
}

void pathSecondTaskThird(int &EXP1, int &M1, int &spent)
{
	if (EXP1 < 300)
	{
		M1 = M1 - 100;
		spent = spent + 100;
	}
	else
	{
		M1 = M1 - 120;
		spent = spent + 120;
	}
	EXP1 = ceil(EXP1 * 0.9);
	checkEXP(EXP1);
	checkMoney(M1);
}

double pathThird(int E2)
{
	const float arr[10]{32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
	double p3{};
	int pos{};
	if (E2 >= 10)
	{
		E2 = E2 / 10 + (E2 - (E2 / 10 * 10));
		pos = E2 - (E2 / 10 * 10);
	}
	else
		pos = E2;
	p3 = arr[pos] / 100.0;
	return p3;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
	// TODO: Complete this function
	if (E3 < 0 || E3 > 99)
		return -99;
	int taxi[10][10]{};

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			taxi[i][j] = ((E3 * j) + (2 * i)) * (i - j);
		}
	}

	int iPos{}, jPos{};
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (taxi[i][j] > (2 * E3))
			{
				iPos++;
			}
			if (taxi[i][j] < -E3)
			{
				jPos++;
			}
		}
	}

	while (iPos >= 10)
	{
		iPos = (iPos / 10) + (iPos - ((iPos / 10) * 10));
	}
	while (jPos >= 10)
	{
		jPos = (jPos / 10) + (jPos - ((jPos / 10) * 10));
	}

	int sherlockVal{};
	sherlockVal = max(maxLeftDownDiagonal(taxi, iPos, jPos), maxRightDownDiagonal(taxi, iPos, jPos));

	int absTaxi{};
	absTaxi = abs(taxi[iPos][jPos]);

	if (sherlockVal >= absTaxi)
	{
		HP1 = ceil(HP1 * 110.0 / 100.0);
		HP2 = ceil(HP2 * 110.0 / 100.0);
		EXP1 = ceil(EXP1 * 112.0 / 100.0);
		EXP2 = ceil(EXP2 * 112.0 / 100.0);
		checkHP(HP1);
		checkHP(HP2);
		checkEXP(EXP1);
		checkEXP(EXP2);
		return sherlockVal;
	}

	else
	{
		HP1 = ceil(HP1 * 90.0 / 100.0);
		HP2 = ceil(HP2 * 90.0 / 100.0);
		EXP1 = ceil(EXP1 * 88.0 / 100.0);
		EXP2 = ceil(EXP2 * 88.0 / 100.0);
		checkHP(HP1);
		checkHP(HP2);
		checkEXP(EXP1);
		checkEXP(EXP2);
		return taxi[iPos][jPos];
	}
}

int maxLeftDownDiagonal(int taxi[10][10], int i, int j)
{
	int maX{};
	while (i <= 9 && j >= 0)
	{
		if (maX < taxi[i][j])
			maX = taxi[i][j];
		i++;
		j--;
	}
	return maX;
}

int maxRightDownDiagonal(int taxi[10][10], int i, int j)
{
	int maX{};
	while (i <= 9 && j <= 9)
	{
		if (maX < taxi[i][j])
			maX = taxi[i][j];
		i++;
		j++;
	}
	return maX;
}
// Task 4
int checkPassword(const char *s, const char *email)
{
	// TODO: Complete this function

	string s1 = s;
	string email1 = email;
	int sePos = email1.find("@");
	bool isNoneSe = 0;
	if (sePos == 0)
		isNoneSe = 1;
	string se = email1.substr(0, sePos);

	bool isEmailSamePwd = 0;
	int emailInPwdLocation{};

	if (s1.length() < 8)
		return -1;
	if (s1.length() > 20)
		return -2;
	if (s1.find(se) != string::npos)
	{
		emailInPwdLocation = s1.find(se);
		return -(emailInPwdLocation + 300);
	}

	int dupeLocation{};
	int n{};
	n = s1.length();
	for (int i = 0; i < n - 2; i++)
	{
		if (s1.at(i) == s1.at(i + 1) && s1.at(i + 2) == s1.at(i))
		{
			dupeLocation = -(i + 400);
			return dupeLocation;
		}
	}

	char specChar[] = {'@', '!', '#', '$', '%'};
	bool specCharFlag = 0;
	bool isSpecChar = 0;
	bool invalidCharFlag = 0;
	int invalidCharLocation = 20;
	for (int i = 0; i < n; i++)
	{
		if (s1[i] >= 48 && s1[i] <= 57 ||
			s1[i] >= 65 && s1[i] <= 90 ||
			s1[i] >= 97 && s1[i] <= 122)
		{
			continue;
		}
		else
		{
			for (int j = 0; j < 5; ++j)
			{

				if (s1[i] == specChar[j])
				{
					specCharFlag = 1;
					isSpecChar = 1;
					break;
				}
			}
			if (!isSpecChar)
			{
				invalidCharFlag = 1;
				if (invalidCharLocation > i)
					invalidCharLocation = i;
			}
			isSpecChar = 0;
		}
	}
	if (!specCharFlag)
		return -5;
	else if (invalidCharFlag)
		return invalidCharLocation;
	return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds)
{
	// TODO: Complete this function
	int passwordLocation{};
	int countArr[100]{};
	int lengthArr[100]{};
	for (int i = 0; i < num_pwds; i++)
	{
		lengthArr[i] = strlen(arr_pwds[i]);
		const char* testChar = arr_pwds[i];
		for (int j = 0; j < num_pwds; j++)
		{
			if (strcmp(testChar, arr_pwds[j]) == 0)
			{
				countArr[i]++;
			}
		}
		
	}

	

	int maxLength{};
	int maxCount{};
	for (int i = 0; i < num_pwds; i++)
	{
		if (countArr[i] >= maxCount)
			maxCount = countArr[i];
		else countArr[i] = 0;
	}
	for (int i = 0; i < num_pwds; i++) {
		if (countArr[i] >= maxCount) {
			if (lengthArr[i] >= maxLength)
				maxLength = lengthArr[i];
			else lengthArr[i] = 0;
		}
	}
	for (int i = 0; i < num_pwds; i++)
	{
		if (countArr[i] == maxCount&&lengthArr[i]==maxLength)
		{
			passwordLocation = i;
			break;
		}
	}
	return passwordLocation;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////