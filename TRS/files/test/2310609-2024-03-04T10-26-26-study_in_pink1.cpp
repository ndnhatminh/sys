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

// Task 1
int datLaiExp(int exp)
{
	if (exp < 0)
		return 0;
	else if (exp > 600)
		return 600;
	return exp;
}
int datLaiHP(int HP)
{
	if (HP < 0)
		return 0;
	else if (HP > 666)
		return 666;
	return HP;

}
int datLaiTien(int M)
{
	if (M < 0)
		return 0;
	else if (M > 3000)
		return 3000;
	return M;

}
int firstMeet(int& exp1, int& exp2, int e1)
{
	// TODO: Complete this function
	if (e1 < 0 || e1>99)
	{
		return -99;
	}
	exp1 = datLaiExp(exp1);
	exp2 = datLaiExp(exp2);
	if (e1 >= 0 && e1 <= 3)
	{
		switch (e1)
		{
		case 0:
			exp2 += 29;
			exp2 = datLaiExp(exp2);
			break;
		case 1:
			exp2 += 45;
			exp2 = datLaiExp(exp2);
			break;
		case 2:
			exp2 += 75;
			exp2 = datLaiExp(exp2);
			break;
		case 3:
			exp2 += 149;
			exp2 = datLaiExp(exp2);
		default:
			break;
		}
		int D = e1 * 3 + exp1 * 7;
		if (D % 2 == 0)
			exp1 = ceil(exp1 + (D / 200.0));//Lưu ý về làm tròn lên
		else
			exp1 = ceil(exp1 - (D / 100.0));//Lưu ý về làm tròn lên
	}
	else if (e1 >= 4 && e1 <= 99)
	{
		if (e1 >= 4 && e1 <= 19)
		{
			exp2 += ceil(e1 / 4.0 + 19);
			exp2 = datLaiExp(exp2);
		}
		else if (e1 >= 20 && e1 <= 49)
		{
			exp2 += ceil(e1 / 9.0 + 21);
			exp2 = datLaiExp(exp2);
		}
		else if (e1 >= 50 && e1 <= 65)
		{
			exp2 += ceil(e1 / 16.0 + 17);
			exp2 = datLaiExp(exp2);
		}
		else if (e1 >= 66 && e1 <= 79)
		{
			exp2 += ceil(e1 / 4.0 + 19);
			exp2 = datLaiExp(exp2);
			if (exp2 > 200)
			{
				exp2 += ceil(e1 / 9.0 + 21);
				exp2 = datLaiExp(exp2);

			}

		}
		else if (e1 >= 80 && e1 <= 99)
		{
			exp2 += ceil(e1 / 4.0 + 19);
			exp2 = datLaiExp(exp2);
			exp2 += ceil(e1 / 9.0 + 21);
			exp2 = datLaiExp(exp2);
			if (exp2 > 400)
			{
				exp2 += ceil(e1 / 16.0 + 17);
				exp2 = datLaiExp(exp2);
				exp2 = ceil(exp2 * 1.15);
				exp2 = datLaiExp(exp2);

			}



		}
		exp1 = exp1 - e1;
	}
	exp1 = datLaiExp(exp1);
	exp2 = datLaiExp(exp2);


	return exp1 + exp2;
}
int soChinhPhuong(float n)
{
	int dem = 0;
	for (int i = 0; i <= sqrt(n); i++)
	{
		dem++;
	}
	if (n - ((dem - 1) * (dem - 1)) > ((dem * dem) - n))
		return dem * dem;
	else
		return (dem - 1) * (dem - 1);
}
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
	// TODO: Complete this function
	if (E2 < 0 || E2>99)
	{
		return -99;
	}
	EXP1 = datLaiExp(EXP1);
	HP1 = datLaiHP(HP1);
	M1 = datLaiTien(M1);
	float S1 = soChinhPhuong(EXP1);
	float p1, p2, p3;
	//road 1:
	if (EXP1 >= S1)
		p1 = 100;
	else
		p1 = ((EXP1 / S1 + 80) / 123.0) * 100;
	//road 2:
	int M01 = M1;
	if (E2 % 2 != 0)
	{
		while (M1 >= (M01 / 2.0))
		{
			if (M1 == 0)
				break;
			if (HP1 < 200)
			{
				HP1 = ceil(HP1 * 1.3);
				HP1 = datLaiHP(HP1);
				M1 -= 150;
			}
			else
			{
				HP1 = ceil(HP1 + (HP1 / 10.0));
				HP1 = datLaiHP(HP1);
				M1 -= 70;
			}
			if (M1 < (M01 / 2.0))
				break;
			if (EXP1 < 400)
			{
				M1 -= 200;
			}
			else
				M1 -= 120;
			EXP1 = ceil(EXP1 * 1.13);
			EXP1 = datLaiExp(EXP1);
			if (M1 < (M01 / 2.0))
				break;
			if (EXP1 < 300)
			{
				M1 -= 100;
			}
			else
				M1 -= 120;
			EXP1 = ceil(EXP1 * 0.9);
		}
		HP1 = ceil(HP1 * 0.83);
		EXP1 = ceil(EXP1 * 1.17);
		EXP1 = datLaiExp(EXP1);
	}
	else if (E2 % 2 == 0)
	{
		if (HP1 < 200 && M1 > 0)
		{
			HP1 = ceil(HP1 * 1.3);
			HP1 = datLaiHP(HP1);
			M1 -= 150;
		}
		else if (HP1 >= 200 && M1 > 0)
		{
			HP1 = ceil(HP1 + HP1 / 10.0);
			HP1 = datLaiHP(HP1);
			M1 -= 70;
		}
		if (EXP1 < 400 && M1 > 0)
		{
			M1 -= 200;
			EXP1 = ceil(EXP1 * 1.13);
			EXP1 = datLaiExp(EXP1);
		}
		else if (EXP1 >= 400 && M1 > 0)
		{
			M1 -= 120;
			EXP1 = ceil(EXP1 * 1.13);
			EXP1 = datLaiExp(EXP1);
		}
		if (EXP1 < 300 && M1 > 0)
		{
			M1 -= 100;
			EXP1 = ceil(EXP1 * 0.9);
		}
		else if (EXP1 >= 300 && M1 > 0)
		{
			M1 -= 120;
			EXP1 = ceil(EXP1 * 0.9);
		}
		HP1 = ceil(HP1 * 0.83);
		EXP1 = ceil(EXP1 * 1.17);
		EXP1 = datLaiExp(EXP1);
		if (M1 <= 0)
			M1 = 0;
	}
	if (M1 <= 0)
		M1 = 0;
	float S2 = soChinhPhuong(EXP1);
	if (EXP1 >= S2)
		p2 = 100;
	else
		p2 = ((EXP1 / S2 + 80) / 123.0) * 100;

	//Road 3:
	int M[10] = { 32,47,28,79,100,50,22,83,64,11 };
	int i, sum;
	if (E2 < 10)
		i = E2;
	else if (E2 >= 10)
	{
		sum = (E2 / 10) + (E2 % 10);
		i = sum % 10;
	}
	p3 = M[i];
	//finished road 1,2,3
	float p;
	if (p1 == 100 && p2 == 100 && p3 == 100)
	{
		EXP1 = ceil(EXP1 * 0.75);
		return HP1 + EXP1 + M1;
	}
	p = (p1 + p2 + p3) / 3;
	if (p < 50)
	{
		HP1 = ceil(HP1 * 0.85);
		EXP1 = ceil(EXP1 * 1.15);
		EXP1 = datLaiExp(EXP1);
	}
	else
	{
		HP1 = ceil(HP1 - (HP1 / 10.0));
		EXP1 = ceil(EXP1 * 1.2);
	}
	EXP1 = datLaiExp(EXP1);
	HP1 = datLaiHP(HP1);
	M1 = datLaiTien(M1);

	return HP1 + EXP1 + M1;
}
// Task 3
int rutGon(int a)
{

	while (a >= 10)
	{
		a = (a / 10) + (a % 10);
	}
	return a;

}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
	// TODO: Complete this function
	
	if (E3 < 0 || E3>99)
	{
		return -99;
	}
	HP1 = datLaiHP(HP1);
	HP2 = datLaiHP(HP2);
	EXP1 = datLaiExp(EXP1);
	EXP2 = datLaiExp(EXP2);
	int scoreTaxi[10][10];
	int scoreSher;
	int demDuong = 0;
	int demAm = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			scoreTaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
			if (scoreTaxi[i][j] > (E3 * 2))
			{
				demDuong += 1;
			}
			else if (scoreTaxi[i][j] < (-E3))
				demAm += 1;
		}
		// okela
	}
	int maxRight = 0;
	int maxLeft = 0;
	int x = rutGon(demDuong);
	int y = rutGon(demAm);
	if (y >= x)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (j == (i + (y - x)))
				{

					if (maxLeft < scoreTaxi[i][j])
						maxLeft = scoreTaxi[i][j];
				}

			}
		}
	}
	if (y < x)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (i == (j + (x - y)))
				{

					if (maxLeft < scoreTaxi[i][j])
						maxLeft = scoreTaxi[i][j];
				}

			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i + j == x + y)
			{

				if (maxRight < scoreTaxi[i][j])
					maxRight = scoreTaxi[i][j];
			}

		}
	}
	if (maxLeft > maxRight)
		scoreSher = maxLeft;
	else
		scoreSher = maxRight;
	if (abs(scoreTaxi[x][y]) > scoreSher)
	{
		EXP1 = ceil(EXP1 - EXP1 * 12.00 / 100.00);
		EXP2 = ceil(EXP2 - EXP2 * 12.00 / 100.00);
		HP1 = ceil(HP1 - (HP1 / 10.0));
		HP2 = ceil(HP2 - (HP2 / 10.0));
		HP1 = datLaiHP(HP1);
		HP2 = datLaiHP(HP2);
		EXP1 = datLaiExp(EXP1);
		EXP2 = datLaiExp(EXP2);
		return scoreTaxi[x][y];

	}
	else
	{
		EXP1 = ceil(EXP1 + EXP1 * 12.00 / 100.00);
		EXP2 = ceil(EXP2 + EXP2 * 12.00 / 100.00);
		HP1 = ceil(HP1 + (HP1 / 10.0));
		HP2 = ceil(HP2 + (HP2 / 10.0));
		HP1 = datLaiHP(HP1);
		HP2 = datLaiHP(HP2);
		EXP1 = datLaiExp(EXP1);
		EXP2 = datLaiExp(EXP2);
		return scoreSher;
	}


	return -1;
}

// Task 4
int doDai(const char* M)
{
	int length = 0;

	while (M[length] != '\0') {
		length++;
	}
	return length;
}
int checkPassword(const char* s, const char* email) {
	// TODO: Complete this function
	char se[100];
	char mk[101];
	mk[doDai(s)] = '\0';
	for (int i = 0; i < doDai(s); i++)
	{
		mk[i] = s[i];
	}
	int dem = 0;
	for (int i = 0; i < 100; i++)
	{
		if (email[i] == '@')
		{
			break;
		}
		else
		{
			se[i] = email[i];
			dem++;
		}

	}
	se[dem] = '\0';
	if (doDai(s) < 8)
		return -1;
	else if (doDai(s) > 20)
		return -2;
	char* thuTu;
	thuTu = strstr(mk, se);
	int sei;
	if (thuTu != NULL)
	{
		sei = (thuTu - mk);
		return -(300 + sei);
	}
	for (int i = 0; i < doDai(s); i++)
	{
		if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
		{
			return -(400 + i);
		}
	}
	int e = 0;
	for (int i = 0; i < doDai(s); i++)
	{
		if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
			e++;
	}
	if (e == 0)
		return -5;
	int f = 0;
	int KoHopLe = 0;
	for (int i = 0; i < doDai(s); i++)
	{
		if (((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) || (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))
		{
			e++;
		}
		else
		{
			KoHopLe++;
			f = i;
			break;
		}
	}
	if (KoHopLe != 0)
		return f;

	return -10;
	return -99;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds)
{
	int* demMk = new int[num_pwds];
	for (int i = 0; i < num_pwds; i++)
	{
		demMk[i] = 0;
	}

	for (int i = 0; i < num_pwds; i++)
	{
		for (int j = 0; j < num_pwds; j++)
		{
			if (i != j && strcmp(arr_pwds[i], arr_pwds[j]) == 0)
			{
				demMk[i]++;
			}
		}
	}

	int maxDem = 0;
	int maxDai = 0;
	int mkDung = -1;

	for (int i = 0; i < num_pwds; i++)
	{
		if (demMk[i] > maxDem || (demMk[i] == maxDem && doDai(arr_pwds[i]) > maxDai))
		{
			maxDem = demMk[i];
			maxDai = doDai(arr_pwds[i]);
			mkDung = i;
		}
	}

	delete[] demMk;

	return mkDung;
	return -1;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////