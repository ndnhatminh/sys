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
)
{
	// This function is used to read the input file,
	// DO NOT MODIFY THIS FUNTION
	ifstream ifs(filename);
	if (ifs.is_open())
	{
		ifs >> HP1 >> HP2
			>> EXP1 >> EXP2
			>> M1 >> M2
			>> E1 >> E2 >> E3;
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
void checkexp(int& exp)
{
	if (exp > 600)
	{
		exp = 600;
	}
	else if (exp < 0)
	{
		exp = 0;
	}
}

int checkhp(int& hp)
{
	if (hp > 666)
	{
		hp = 666;
	}
	else if (hp < 0)
	{
		hp = 0;
	}
	return hp;
}

int checkm(int& m)
{
	if (m > 3000) {
		m = 3000;
	}
	else if (m < 0)
	{
		m = 0;
	}
	return m;
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1)
{
	if (e1 > 99 || e1 < 0)
	{
		return -99;
	}
	checkexp(exp1);
	checkexp(exp2);
	int D;
	if (e1 >= 0 && e1 <= 3)
	{
		if (e1 == 0)
		{
			exp2 += 29;
		}
		else if (e1 == 1)
		{
			exp2 += 45;
		}
		else if (e1 == 2)
		{
			exp2 += 75;
		}
		else if (e1 == 3)
		{
			exp2 += 29 + 45 + 75;
		}
		checkexp(exp2);
		checkexp(exp1);
		D = (int)(int)ceil((double)e1 * 3.0 - 1.192092896e-07F) + (int)(int)ceil((double)exp1 * 7.0 - 1.192092896e-07F);
		
		if (D % 2 == 0)
		{
			exp1 += (int)ceil((double)D / 200.0 - 1.192092896e-07F);
		}
		else
		{
			exp1 -= (int)floor((double)D / 100.0 + 1.192092896e-07F);
		}
		
	}
	else
	{
		if (e1 >= 4 && e1 <= 19)
		{
			exp2 += (int)(int)ceil((double)e1 / 4.0 - 1.192092896e-07F) + 19 ;
		}
		else if (e1 >= 20 && e1 <= 49)
		{
			exp2 += (int)(int)ceil((double)e1 / 9.0 - 1.192092896e-07F) + 21 ;
		}
		else if (e1 >= 50 && e1 <= 65)
		{
			exp2 += (int)(int)ceil((double)e1 / 16.0 - 1.192092896e-07F) + 17;
		}
		else if (e1 >= 66 && e1 <= 79)
		{
			exp2 += (int)(int)ceil((double)e1 / 4.0 - 1.192092896e-07F)+ 19 ;
			if (exp2 > 200)
			{
				exp2 += (int)(int)ceil((double)e1 / 9.0 - 1.192092896e-07F) + 21;
			}
		}
		else  //(e1 >= 80 && e1 <= 99)
		{
			exp2 += (int)(int)ceil((double)e1 / 4.0 - 1.192092896e-07F) + 19 + (int)(int)ceil((double)e1 / 9.0 - 1.192092896e-07F) + 21;
			if (exp2 > 400)
			{
				exp2 += (int)(int)ceil((double)e1 / 16.0 - 1.192092896e-07F) + 17;
				exp2 += (int)(int)ceil((double)exp2 * 0.15 - 1.192092896e-07F);
			}
		}
		exp1 = exp1 - e1;
	}
	checkexp(exp1);
	checkexp(exp2);
	return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
	if (E2 > 99 || E2 < 0)
	{
		return -99;
	}
	checkexp(EXP1);
	checkhp(HP1);
	checkm(M1);

	if (E2 > 99 || E2 < 0)
	{
		return -99;
	}

	int S1 = (int)ceil((double)pow((int)sqrt(EXP1), 2));
	int S2 = (int)ceil((double)pow((int)sqrt(EXP1) + 1, 2));
	int S;
	double P1, P2, P3;
	if (abs(S1 - EXP1) > abs(S2 - EXP1))
	{
		S = S2;
	}
	else
	{
		S = S1;
	}

	if (EXP1 >= S)
	{
		P1 = 1;
	}
	else
	{
		P1 = ((double)EXP1 / (double)S + 80) / 123;
	}
	//XONG CON DUONG 1

	if (M1 != 0)
	{


		if (E2 % 2 == 0)
		{
			if (M1 > 0)
			{
				if (HP1 < 200)
				{
					HP1 += (int)ceil((double)HP1 * 0.3 - 1.192092896e-07F);
					M1 -= 150;
				}
				else
				{
					HP1 += (int)ceil((double)HP1 * 0.1 - 1.192092896e-07F);
					M1 -= 70;
				}
				checkm(M1);
				checkhp(HP1);
			}
			if (M1 > 0)
			{
				if (EXP1 < 400)
				{
					M1 -= 200;
				}
				else
				{
					M1 -= 120;
				}
				EXP1 += (int)ceil((double)EXP1 * 0.13 - 1.192092896e-07F);
				checkm(M1);
				checkexp(EXP1);
			}
			if (M1 > 0)
			{
				if (EXP1 < 300)
				{
					M1 -= 100;
				}
				else
				{
					M1 -= 120;
				}
				EXP1 -= (int)floor((double)EXP1 * 0.1 + 1.192092896e-07F);
				checkm(M1);
				checkexp(EXP1);
			}
		}
		else
		{
			int temp = (int)ceil((double)M1 * 0.5 - 1.192092896e-07F);
			
			while (M1 >= temp)
			{
				if (M1 != 0 && M1 >= temp)
				{
					if (HP1 < 200)
					{
						HP1 = (int)ceil((double)HP1 + HP1 * 0.3 - 1.192092896e-07F);
						M1 -= 150;
					}
					else
					{
						HP1 = (int)ceil((double)HP1 + HP1 * 0.1 - 1.192092896e-07F);
						M1 -= 70;
					}
					checkm(M1);
					checkhp(HP1);
				}
				if (M1 != 0 && M1 >= temp)
				{
					if (EXP1 < 400)
					{
						M1 -= 200;
					}
					else
					{
						M1 -= 120;
					}
					EXP1 += (int)ceil((double)EXP1 * 0.13 - 1.192092896e-07F);
					checkm(M1);
					checkhp(EXP1); 
				}
				if (M1 != 0 && M1 >= temp)
				{
					if (EXP1 < 300)
					{
						M1 -= 100;
					}
					else
					{
						M1 -= 120;
					}
					EXP1 -= (int)floor((double)EXP1 * 0.1 + 1.192092896e-07F);
					checkm(M1);
					checkexp(EXP1);

				}
			}
		}
	}

	HP1 -= (int)floor((double)HP1 * 0.17 + 1.192092896e-07F);
	EXP1 += (int)ceil((double)EXP1 * 0.17 - 1.192092896e-07F);
	checkhp(HP1);
	checkexp(EXP1);
	S1 = pow((int)sqrt(EXP1), 2);
	S2 = pow((int)sqrt(EXP1) + 1, 2);
	

	if (abs(S1 - EXP1) > abs(S2 - EXP1))
	{
		S = S2;
	}
	else
	{
		S = S1;
	}
	if (EXP1 >= S)
	{
		P2 = 1;
	}
	else
	{
		P2 = ((double)EXP1 / (double)S + 80) / 123;
	}

	//XONG CON DUONG 2

	int arr[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
	int i;
	if (E2 <= 9)
	{
		i = E2;
	}
	else
	{
		i = ((E2 / 10) + (E2 % 10)) % 10;
	}
	P3 = arr[i]/100.0;
	//XONG CON DUONG 3
	
	if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0)
	{
		EXP1 -= (int)floor((double)EXP1 * 0.25 + 1.192092896e-07F);
	}
	else
	{
		double P = (P1 + P2 + P3) / 3.0;

		if (P < 0.5)
		{
			HP1 -= (int)floor((double)HP1 * 0.15 + 1.192092896e-07F);
			EXP1 += (int)ceil((double)EXP1 * 0.15 - 1.192092896e-07F);
		}
		else
		{
			HP1 -= (int)floor((double)HP1 * 0.1 + 1.192092896e-07F);
			EXP1 += (int)ceil((double)EXP1 * 0.2 - 1.192092896e-07F);
		}
	}
	checkexp(EXP1);
	checkhp(HP1);
	//KET THUC
	return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3)
{
	//BANG DIEM TAXI & HOLMES
	if (E3 > 99 || E3 < 0)
	{
		return -99;
	}
	checkhp(HP1);
	checkhp(HP2);
	checkexp(EXP1);
	checkexp(EXP2);

	int taxi[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
		}
	}
	
	/*   SHOW CAI BANG DIEM
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << taxi[i][j] << "\t";
		}
		cout << endl;
	}
	*/
	//TINH DIEM GAP NHAU
	int row = 0, col = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (taxi[i][j] > E3 * 2)
			{
				row++;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (taxi[i][j] < -E3)
			{
				col++;
			}
		}
	}
	while (row > 9)
	{
		row = row / 10 + row % 10;
	}
	while (col > 9)
	{
		col = col / 10 + col % 10;
	}
	//XET DIEM CUA HOMLES
	int row_save = row;
	int col_save = col;
	int MAX_1, MAX_2, MAX_3, MAX_4, POINT;

	MAX_1 = taxi[row][col];
	while (row > -1 && row < 10 && col >-1 && col < 10)
	{
		if (MAX_1 < taxi[row][col])
		{
			MAX_1 = taxi[row][col];
		}
		row++;
		col++;
	}
	row = row_save;
	col = col_save;

	MAX_2 = taxi[row][col];
	while (row > -1 && row < 10 && col >-1 && col < 10)
	{
		if (MAX_2 < taxi[row][col])
		{
			MAX_2 = taxi[row][col];
		}
		row--;
		col++;
	}
	row = row_save;
	col = col_save;

	MAX_3 = taxi[row][col];
	while (row > -1 && row < 10 && col >-1 && col < 10)
	{
		if (MAX_3 < taxi[row][col])
		{
			MAX_3 = taxi[row][col];
		}
		row++;
		col--;
	}
	row = row_save;
	col = col_save;

	MAX_4 = taxi[row][col];
	while (row > -1 && row < 10 && col >-1 && col < 10)
	{
		if (MAX_4 < taxi[row][col])
		{
			MAX_4 = taxi[row][col];
		}
		row--;
		col--;
	}
	row = row_save;
	col = col_save;
	
	int MAX[4] = { MAX_1, MAX_2, MAX_3, MAX_4 };
	POINT = MAX[0];
	for (int i = 0; i < 3; i++)
	{
		if (POINT < MAX[i])
		{
			POINT = MAX[i];
		}
		
	}
	//KET THUC
	if (abs(taxi[row][col]) <= abs(POINT))
	{
		EXP1 += (int)ceil((double)EXP1 * 0.12 - 1.192092896e-07F);
		EXP2 += (int)ceil((double)EXP2 * 0.12 - 1.192092896e-07F);
		HP1 += (int)ceil((double)HP1 * 0.1 - 1.192092896e-07F);
		HP2 += (int)ceil((double)HP2 * 0.1 - 1.192092896e-07F);
	}
	else
	{
		EXP1 -= (int)floor((double)EXP1 * 0.12 + 1.192092896e-07F);
		EXP2 -= (int)floor((double)EXP2 * 0.12 + 1.192092896e-07F);
		HP1 -= (int)floor((double)HP1 * 0.1 + 1.192092896e-07F);
		HP2 -= (int)floor((double)HP2 * 0.1 + 1.192092896e-07F);
	}
	checkexp(EXP1);
	checkexp(EXP2);
	checkhp(HP1);
	checkhp(HP2);

	
	if (abs(taxi[row][col]) <= abs(POINT))
	{
		return POINT;
	}
	else 
	{
		return taxi[row][col];
	}
}

// Task 4
int checkPassword(const char* s, const char* email) {
	string S = string(s);
	string Email = string(email);
	int location = Email.find("@");
	string se = Email.substr(0, location);
	if (strlen(s) < 8)
	{
		return -1;
	}
	if (strlen(s) > 20)
	{
		return -2;
	}
	if ((int)S.find(se) >= 0 || (int)S.find(se) >20 )
	{
		return -(300 + S.find(se));
	}
	for (int i = 2; i < strlen(s); i++)
	{
		if (S[i - 2] == S[i - 1] && S[i - 1] == S[i])
		{
			return -(400 + i - 2);
		}
	}
	bool special = false;
	for (int i = 0; i < strlen(s); i++)
	{
		if ((S[i] < '0' || S[i] > '9') && (S[i] < 'A' || S[i] > 'Z') && (S[i] < 'a' || S[i]>'z') && (S[i] != '!' && S[i] != '@' && S[i] != '#' && S[i] != '$' && S[i] != '%'))
		{
			return i;
		}
		if (S[i] == '!' || S[i] == '@' || S[i] == '#' || S[i] == '$' || S[i] == '%')
		{
			 special = true;
		}

	} 
	if (special)
	{
		return -10;
	}
	else
	{
		return -5;
	}
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
	string pwds[30];
	for (int i = 0; i < num_pwds; i++)
	{
		pwds[i] = arr_pwds[i];
	}
	int times[30] = { 0 };
	int leng[30] = { 0 }; 
	int mostfreq = 1;
	for (int i = 0; i < num_pwds; i++)
	{
		for (int j = 0; j < num_pwds; j++)
		{
			if (pwds[i] == pwds[j])
			{
				times[i] += 1;
				if (mostfreq < times[i])
				{
					mostfreq = times[i];
				}
			}
		}
	}
	int maxleng = 0;
	int found;
	for (int i = 0; i < num_pwds; ++i) {
		if (mostfreq == times[i])
		{
			if( (int)strlen(arr_pwds[i]) > maxleng)
			{
				maxleng = (int)strlen(arr_pwds[i]);
				found = i;
			}

		}
	}
	
	return found;


}

//////////////////////////////////////////////////
//////////// END OF STUDENT'S ANSWER ////////////
///////////////////////////////////////////////