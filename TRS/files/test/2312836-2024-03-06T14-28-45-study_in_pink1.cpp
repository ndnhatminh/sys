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

void checkrange(int& v, int lowerbound, int higherbound)
{
    if (v < lowerbound) v = lowerbound;
    if (v > higherbound) v = higherbound;
};
void situation(int& v, int lowerbound, int higherbound)
{
    if (v<lowerbound || v>higherbound)
    {
        v = -99;
    }
};
// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
	// TODO: Complete this function

	checkrange(exp1, 0, 600);
	checkrange(exp2, 0, 600);
	situation(e1, 0, 99);
	float Exp1 = exp1;
	float Exp2 = exp2;
	float D;
	float E1 = e1;
	if (E1 <= 3)
	{
		if (E1 == 0) Exp2 += 29;
		else if (E1 == 1) Exp2 += 45;
		else if (E1 == 2) Exp2 += 75;
		else if (E1 == 3) Exp2 += 149;
		D = E1 * 3 + Exp1 * 7;
		if ((int)D % 2 == 0) Exp1 = ceil(Exp1 + D / 200);
		else Exp1 = ceil(Exp1 - D / 100);
	}
	else 
	{
		if ((E1 >= 4) && (E1 <= 19)) Exp2 = ceil(Exp2 + E1 / 4 + 19);
		else if ((E1 >= 20) && (E1 <= 49)) Exp2 = ceil(Exp2 + E1 / 9 + 21);
		else if ((E1 >= 50) && (E1 <= 65)) Exp2 = ceil(Exp2 + E1 / 16 + 17);
		else if ((E1 >= 66) && (E1 <= 79))
		{
			Exp2 += E1 / 4 + 19 + 0.999;
			if (Exp2 > 200) Exp2 = ceil(Exp2 + E1 / 9 + 21);
		}
		else if ((E1 >= 80) && (E1 <= 99))
		{
			Exp2 = ceil(Exp2 + 13 * E1 / 36 + 40);
			if (Exp2 > 400)
			{
				Exp2 = ceil(Exp2 * E1 / 16 + 17);
				Exp2 = ceil(Exp2 * 1.15);
			}
		}
		Exp1 -= E1;
	}
	
	exp1 = Exp1;
	exp2 = Exp2;
	checkrange(exp1, 0, 600);
	checkrange(exp2, 0, 600);
	situation(e1, 0, 99);
	return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

		checkrange(HP1, 0, 666);
		checkrange(EXP1, 0, 600);
		checkrange(M1, 0, 3000);
		situation(E2, 0, 99);
		float m1 = M1;
		//tuyen01
		int a1 = ceil(sqrt(EXP1));
		int a2 = floor(sqrt(EXP1));
		int S;
		if (abs(a1 * a1 - EXP1) > abs(a2 * a2 - EXP1)) S = a2 * a2;
		else S = a1 * a1;
		float P1;
		if (EXP1 >= S) P1 = 100;
		else
		{
			P1 = (EXP1 / S + 80) / 1.23;
			P1 = std::ceil(P1 * 100) / 100; 
			//tuyen02
			do
			{
				if (HP1 < 200)
				{
					HP1 = std::ceil(HP1 * 1.3);
					M1 = std::ceil(M1 - 150); 
					if ((M1 <= 0) && (E2 / 2 == 0))
					{
						M1 = 0;
						break;
					}
					if ((M1 < 0.5 * m1) && (E2 / 2 != 0))
					{
						HP1 = std::ceil(HP1 * 0.87);
						EXP1 = std::ceil(EXP1 * 1.17);
						break;
					}
				}
				else
				{
					HP1 = std::ceil(HP1 * 1.1);
					M1 = std::ceil(M1 - 70);
					if ((M1 <= 0) && (E2 / 2 == 0))
					{
						M1 = 0;
						break;
					}
					if ((M1 < 0.5 * m1) && (E2 / 2 != 0))
					{
						HP1 = std::ceil(HP1 * 0.87);
						EXP1 = std::ceil(EXP1 * 1.17);
						break;
					}
				}
				if (EXP1 < 400)
				{
					M1 = std::ceil(M1 - 200); 
					if ((M1 <= 0) && (E2 / 2 == 0))
					{
						M1 = 0;
						break;
					}
					if ((M1 < 0.5 * m1) && (E2 / 2 != 0))
					{
						HP1 = std::ceil(HP1 * 0.87); 
						EXP1 = std::ceil(EXP1 * 1.17);
						break;
					}
				}
				else
				{
					M1 = std::ceil(M1 - 120); 
					EXP1 = std::ceil(EXP1 * 1.13); 
					if ((M1 <= 0) && (E2 / 2 == 0))
					{
						M1 = 0;
						break;
					}
					if ((M1 < 0.5 * m1) && (E2 / 2 != 0))
					{
						HP1 = std::ceil(HP1 * 0.83);
						EXP1 = std::ceil(EXP1 * 1.17);
						break;
					}
				}
				if (EXP1 < 300)
				{
					M1 = std::ceil(M1 - 100); 
					if ((M1 <= 0) && (E2 / 2 == 0))
					{
						M1 = 0;
						break;
					}
					if ((M1 < 0.5 * m1) && (E2 / 2 != 0))
					{
						HP1 = std::ceil(HP1 * 0.87); 
						EXP1 = std::ceil(EXP1 * 1.17);
						break;
					}
				}
				else
				{
					M1 = std::ceil(M1 - 120);
					EXP1 = std::ceil(EXP1 * 0.9);
					if ((M1 <= 0) && (E2 / 2 == 0))
					{
						M1 = 0;
						break;
					}
					if ((M1 < 0.5 * m1) && (E2 / 2 != 0))
					{
						HP1 = std::ceil(HP1 * 0.87); 
						EXP1 = std::ceil(EXP1 * 1.17); 
						break;
					}
				}
			} while (E2 % 2 != 0);

			int a3 = ceil(sqrt(EXP1));
			int a4 = floor(sqrt(EXP1));
			int S2;
			if (abs(a3 * a3 - EXP1) > abs(a4 * a4 - EXP1)) S2 = a4 * a4;
			else S2 = a3 * a3;
			
			float P2;
			if (EXP1 >= S2) P2 = 100;
			else P2 = (EXP1 / S2 + 80) / 1.23;
			
			//tuyen03
			int p[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
			float P3;
			if (E2 / 10 != 0)
			{
				int i = (E2 / 10 + E2 % 10) % 10;
				P3 = p[i];
			}
			else
			{
				int i = E2;
				P3 = p[i];
			}
			
			//xacsuat
			float P;
			if ((P1 == 100) && (P2 == 100) && (P3 == 100)) EXP1 *= 0.75;
			else
			{
				P = (P1 + P2 + P3) / 3;
				if (P < 50)
				{
					HP1 = std::ceil(HP1 * 0.85);
					EXP1 = std::ceil(EXP1 *= 1.15);
				}
				else
				{
					HP1 = std::ceil(HP1 * 0.9);
					EXP1 = std::ceil(EXP1 * 1.2);
				}
			}
			HP1 = ceil(HP1);
			EXP1 = ceil(EXP1);
			M1 = ceil(M1);
			checkrange(HP1, 0, 666);
			checkrange(EXP1, 0, 600);
			checkrange(M1, 0, 3000);
			situation(E2, 0, 99);
		}
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

		checkrange(HP1, 0, 666);
		checkrange(HP2, 0, 666);
		checkrange(EXP1, 0, 600);
		checkrange(EXP2, 0, 600);
		situation(E3, 0, 99);
		float chasing[10][10][2];
		//fillthefirstmatix
		for (int i = 0; i <= 9; i++)
		{
			for (int j = 0; j <= 9; j++)
			{
				chasing[i][j][0] = ((E3 * j) + (i * 2)) * (i - j);
			}
		}
		//fillthesecondmatrix
		for (int i = 0; i <= 9; i++)
		{
			for (int j = 0; j <= 9; j++)
			{
				float MaxL = chasing[i][j][0];
				for (int k = 0; k <= 9; k++)
				{
					if ((i + k) > 9 || (i - k) < 0 || (j + k > 9) || (j - k < 0))break;
					if (MaxL < chasing[i + k][j + k][0]) MaxL = chasing[i + k][j + k][0];
					if (MaxL < chasing[i - k][j - k][0]) MaxL = chasing[i - k][j - k][0];
				}
				float MaxR = chasing[i][j][0];
				for (int l = 0; l <= 9; l++)
				{
					if ((i + l) > 9 || (i - l) < 0 || (j + l > 9) || (j - l < 0))break;
					if (MaxR < chasing[i - l][j + l][0]) MaxR = chasing[i - l][j + l][0];
					if (MaxR < chasing[i + l][j - l][0]) MaxR = chasing[i + l][j - l][0];
				}
				float Max;
				if (MaxR >= MaxL) Max = MaxR;
				else Max = MaxL;
				chasing[i][j][1] = Max;
			}
		}
		//thenot
		int X = 0, Y = 0;
		for (int i = 0; i <= 9; i++)
		{
			for (int j = 0; j <= 9; j++)
			{
				if (chasing[i][j][0] > E3 * 2) X += 1;
				if (chasing[i][j][0] < E3 * -1) Y += 1;
			}
		}
		while (X / 10 != 0)
		{
			X = ((X / 10) + (X % 10));
		} while (Y / 10 != 0)
		{
			Y = ((Y / 10) + (Y % 10));
		}
		if (abs(chasing[X][Y][0]) < abs(chasing[X][Y][1]))
		{
			HP1 *= 1.1;
			HP2 *= 1.1;
			EXP1 *= 1.12;
			EXP2 *= 1.12;
			return chasing[X][Y][1];
		}
		else
		{
			HP1 *= 0.9;
			HP2 *= 0.9;
			EXP1 *= 0.88;
			EXP2 *= 0.88;
			return chasing[X][Y][0];
		}
		checkrange(HP1, 0, 666);
		checkrange(EXP1, 0, 600);
		checkrange(HP2, 0, 666);
		checkrange(EXP2, 0, 600);
		situation(E3, 0, 99);
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

	std::string password = s;
	std::string Email = email;
	int C = 0;

	//ktradodaipassword
	if (password.length() >= 8)
	{
		if (password.length() <= 20)
		{
			//trichpassword
			char pass[20];
			for (int i = 0; i <= password.length() - 1; i++) pass[i] = password[i];
			char se[100];
			//trichemail
			for (int i = 0; i <= 99; i++)
			{
				if ((int)email[i] != 64) se[i] = email[i];
				else
				{
					se[i] = (char)64;
					break;
				}
			}
			//ktrakitucuapssword
			for (int i = 0; i <= password.length() - 1; i++)
			{
				if ((((int)pass[i] >= 64) && ((int)pass[i] <= 90)) || ((int)pass[i] >= 97) && ((int)pass[i] <= 122) || ((int)pass[i] >= 48 && ((int)pass[i] <= 57) || ((int)pass[i] == 33) || ((int)pass[i] >= 35) && ((int)pass[i] <= 37)))
				{
					pass[i] = password[i];
					//ktrapasscoitnhat1kitudacbiet
					if ((int)pass[i] == 64 || (int)pass[i] == 33 || ((int)pass[i] >= 35) && ((int)pass[i] <= 37)) C += 1;
				}
				else
				{
					return i;
				}
			}
			//ktrapasscotrungemailkhong
			for (int i = 0; i <= password.length() - 1; i++)
			{
				if ((int)pass[i] == (int)se[0])
				{
					for (int j = i + 1; j <= password.length() - 1; j++)
					{

						if ((int)pass[j] == (int)se[j - i])
						{
							if ((int)se[j - i + 1] == 64)
							{
								return -(300 + i);
							}
							continue;
						}
						else break;
					}
				}
			}
			//ktrapasscokitutrungnhaukhong
			for (int i = 2; i <= password.length() - 1; i++)
			{
				if (((int)pass[i - 1] == (int)pass[i]) && ((int)pass[i - 2] == (int)pass[i]))
				{
					return -(400 + i - 2);
				}
			}
			if (C == 0)
			{
				return -5;
			}
		}
		else
		{
			return -2;
		}
		return -10;
	}
	else
	{
		return-1;
	}
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

	int array[100] = {};
	for (int i = 0; i <= num_pwds - 1; i++)
	{
		std::string password = arr_pwds[i];
		int count = 0;
		for (int j = i + 1; j <= num_pwds - 1; j++)
		{
			std::string Password = arr_pwds[j];
			int CountL = 0;
			if (password.length() == Password.length())
			{
				for (int k = 0; k <= password.length() - 1; k++)
				{
					if (password[k] == Password[k]) CountL++;
					else break;
				}
			}
			if (CountL == password.length()) count += 1;
		}
		array[i] = count;
	}
	int common = 0;
	for (int i = 0; i <= num_pwds; i++)
	{
		if (common < array[i]) common = array[i];
	}
	int maxL = 0;
	for (int i = 0; i <= num_pwds - 1; i++)
	{
		std::string password = arr_pwds[i];
		if ((array[i] == common) && ((int)password.length() > maxL)) maxL = (int)password.length();
	}
	for (int i = 0; i <= num_pwds; i++)
	{
		std::string password = arr_pwds[i];
		if ((array[i] == common) && ((int)password.length() == maxL)) return i;
	}
	return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////