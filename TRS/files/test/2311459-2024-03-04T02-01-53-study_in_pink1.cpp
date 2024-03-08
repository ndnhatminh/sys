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
//////////// Extra
int checkExp(int& EXP)
{
	if (EXP > 600)
	{
		EXP = 600;
	}
	if (EXP < 0)
	{
		EXP = 0;
	}
	return EXP;
}

int checkHp(int& HP)
{
	if (HP > 666)
	{
		HP = 666;
	}
	if (HP < 0)
	{
		HP = 0;
	}
	return HP;
}
int checkM(int& M)
{
	if (M > 3000)
	{
		M = 300;
	}
	if (M < 0)
	{
		M = 0;
	}
	return M;
}


// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1)
{
	int check;
	if (E1 > 99 || E1 < 0)
	{
		return -99;
	}
	if (E1 < 4) /////////// 4.1.1
	{
		if (E1 == 0)
		{
			check = EXP2 + 29;
			EXP2 = checkExp(check);
		}
		else if (E1 == 1)
		{
			check = EXP2 + 45;
			EXP2 = checkExp(check);
		}
		else if (E1 == 2)
		{
			check = EXP2 + 75;
			EXP2 = checkExp(check);
		}
		else
		{
			check = EXP2 + 29 + 45 + 75;
			EXP2 = checkExp(check);
		}
		int D = E1 * 3 + EXP1 * 7;
		if (D % 2 == 0)
		{
			check = EXP1 + ceil(D / 200);
			EXP1 = checkExp(check);
		}
		else
		{
			check = EXP1 - ceil(D / 100);
			EXP1 = checkExp(check);
		}
		return EXP1 + EXP2;
	}
	else /////////////// 4.1.2
	{
		if (E1 >= 4 && E1 <= 19)
		{
			check = EXP2 + ceil(E1 / 4.0 + 19);
			EXP2 = checkExp(check);
		}
		if (E1 >= 20 && E1 <= 49)
		{
			check = EXP2 + ceil(E1 / 9.0 + 21);
			EXP2 = checkExp(check);
		}
		if (E1 >= 50 && E1 <= 65)
		{
			check = EXP2 + ceil(E1 / 16.0 + 17);
			EXP2 = checkExp(check);
		}
		if (E1 >= 66 && E1 <= 79)
		{
			check = EXP2 + ceil(E1 / 4.0 + 19);
			EXP2 = checkExp(check);
			if (EXP2 > 200)
			{
				check = EXP2 + ceil(E1 / 9.0 + 21);
				EXP2 = checkExp(check);
			}
		}
		if (E1 >= 80 && E1 <= 99)
		{
			check = EXP2 + ceil(E1 / 4.0 + 19);
			EXP2 = checkExp(check);
			check = EXP2 + ceil(E1 / 9.0 + 21);
			EXP2 = checkExp(check);
			if (EXP2 > 400)
			{
				check = EXP2 + ceil(E1 / 16.0 + 17);
				EXP2 = checkExp(check);
				check = EXP2 + ceil(EXP2 * 0.15);
				EXP2 = checkExp(check);
			}
		}
		check = EXP1 - E1;
		EXP1 = checkExp(check);
		return EXP1 + EXP2;
	}
}
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
	if (E2 > 99 || E2 < 0)
	{
		return -99;
	}
	double S = pow(2, round(sqrt(EXP1)));
	int startMoney = M1;
	int spentMoney = 0;
	int temp;
	double P1;////////4.2.1

	if (EXP1 >= S)
	{
		P1 = 1;
	}
	else
	{
		P1 = ((EXP1 * 1.0 / S) + 80) / 123;
	}

	if (E2 % 2 == 1)/////////////4.2.2
	{
		for (int j = 0; j < 10; )// infinite loop
		{
			if (HP1 < 200)
			{
				temp = ceil(HP1 * 1.3);
				HP1 = checkHp(temp);
				temp = M1 - 150;
				M1 = checkM(temp);
				spentMoney = spentMoney + 150;
				if (spentMoney > startMoney / 2)
				{
					break;
				}
			}
			else
			{
				temp = ceil(HP1 * 1.1);
				HP1 = checkHp(temp);
				temp = M1 - 70;
				M1 = checkM(temp);
				spentMoney = spentMoney + 70;
				if (spentMoney > startMoney / 2)
				{
					break;
				}
			}

			if (EXP1 < 400)
			{
				temp = M1 - 200;
				M1 = checkM(temp);
				spentMoney = spentMoney + 200;
				if (spentMoney > startMoney / 2)
				{
					break;
				}

			}
			else
			{
				temp = M1 - 120;
				M1 = checkM(temp);
				spentMoney = spentMoney + 120;
				temp = ceil(EXP1 * 1.13);
				EXP1 = checkExp(temp);
				if (spentMoney > startMoney / 2)
				{
					break;
				}
			}

			if (EXP1 < 300)
			{
				temp = M1 - 100;
				M1 = checkM(temp);
				spentMoney = spentMoney + 100;
				temp = ceil(EXP1 * 0.9);
				EXP1 = checkExp(temp);
				if (spentMoney > startMoney / 2)
				{
					break;
				}
			}
			else
			{
				temp = M1 - 120;
				M1 = checkM(temp);
				spentMoney = spentMoney + 120;
				temp = ceil(EXP1 * 0.9);
				EXP1 = checkExp(temp);
				if (spentMoney > startMoney / 2)
				{
					break;
				}
			}
		}
	}
	else
	{
		if (M1 > 0)
		{
			if (HP1 < 200) // 4.2.2
			{
				temp = ceil(HP1 * 1.3);
				HP1 = checkHp(temp);
				temp = M1 - 150;
				M1 = checkM(temp);
			}
			else
			{
				temp = ceil(HP1 * 1.1);
				HP1 = checkHp(temp);
				temp = M1 - 70;
				M1 = checkM(temp);
			}
		}

		if (M1 > 0)
		{
			if (EXP1 < 400) // 4.2.2
			{
				temp = M1 - 200;
				M1 = checkM(temp);
			}
			else
			{
				temp = M1 - 120;
				M1 = checkM(temp);
				temp = ceil(EXP1 * 1.13);
				EXP1 = checkExp(temp);
			}
		}

		if (M1 > 0)
		{
			if (EXP1 < 300) // 4.2.2
			{
				temp = M1 - 100;
				M1 = checkM(temp);
				temp = ceil(EXP1 * 0.9);
				EXP1 = checkExp(temp);
			}
			else
			{
				temp = M1 - 120;
				M1 = checkM(temp);
				temp = ceil(EXP1 * 0.9);
				EXP1 = checkExp(temp);
			}
		}
	}

	if (spentMoney > startMoney / 2)
	{
		temp = ceil(HP1 * 0.83);
		HP1 = checkHp(temp);
		temp = ceil(EXP1 * 1.17);
		EXP1 = checkExp(temp);
	}

	if (E2 % 2 == 0 && M1 == 0)
	{
		temp = ceil(HP1 * 0.83);
		HP1 = checkHp(temp);
		temp = ceil(EXP1 * 1.17);
		EXP1 = checkExp(temp);
	}

	double P2;
	S = pow(2, round(sqrt(EXP1)));
	if (EXP1 >= S)
	{
		P2 = 1;
	}
	else
	{
		P2 = ((EXP1 * 1.0 / S) + 80) / 123;
	}
	//////////4.2.3
	double P3[] = { 0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11 };
	int i;
	if (E2 < 10)
	{
		i = E2;
	}
	else
	{
		i = ((E2 / 10) + (E2 % 10)) % 10;
	}
	if (P1 == 1 && P2 == 1 && P3[i] == 1)
	{
		temp = ceil(EXP1 * 0.75);
		EXP1 = checkExp(temp);
	}
	else
	{
		double P = (P1 + P2 + P3[i]) / 3.0;
		if (P < 0.5)
		{
			temp = ceil(HP1 * 0.85);
			HP1 = checkHp(temp);
			temp = ceil(EXP1 * 1.15);
			EXP1 = checkExp(temp);
		}
		else
		{
			temp = ceil(HP1 * 0.9);
			HP1 = checkHp(temp);
			temp = ceil(EXP1 * 1.20);
			EXP1 = checkExp(temp);
		}
	}
	return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3)
{
	if (E3 > 99 || E3 < 0)
	{
		return -99;
	}
	int check;
	int map[10][10] = { 0 };
	int I = 0;
	int J = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
			if (map[i][j] > 0)
			{
				if (map[i][j] > (E3 * 2))
				{
					I++;
				}
			}
			if (map[i][j] < 0)
			{
				if (map[i][j] < (-E3))
				{
					J++;
				}
			}
		}
	}

	while (J > 9 || I > 9)
	{
		J = (J % 10) + (J / 10);
		I = (I % 10) + (I / 10);
	}

	int temp = map[I][J];
	int m = 0;
	int n = 0;

	while (m >= 0 && n >= 0 && m < 10 && n < 10)//down left
	{
		if (map[m][n] > temp)
		{
			temp = map[m][n];
		}
		m++;
		n++;
	}
	m = 0;
	n = 0;

	while (m >= 0 && n >= 0 && m < 10 && n < 10)//up right
	{
		if (map[m][n] > temp)
		{
			temp = map[m][n];
		}
		m--;
		n--;
	}
	m = 0;
	n = 0;

	while (m >= 0 && n >= 0 && m < 10 && n < 10)//up left
	{
		if (map[m][n] > temp)
		{
			temp = map[m][n];
		}
		m--;
		n++;
	}
	m = 0;
	n = 0;

	while (m >= 0 && n >= 0 && m < 10 && n < 10)//down right
	{
		if (map[m][n] > temp)
		{
			temp = map[m][n];
		}
		m++;
		n--;
	}

	if (abs(map[I][J]) > temp)
	{
		check = ceil(EXP1 * 0.88);
		EXP1 = checkExp(check);
		check = ceil(EXP2 * 0.88);
		EXP2 = checkExp(check);
		check = ceil(HP1 * 0.9);
		HP1 = checkHp(check);
		check = ceil(HP2 * 0.9);
		HP2 = checkHp(check);
		return map[I][J];
	}
	else
	{
		check = ceil(EXP1 * 1.12);
		EXP1 = checkExp(check);
		check = ceil(EXP2 * 1.12);
		EXP2 = checkExp(check);
		check = ceil(HP1 * 1.1);
		HP1 = checkHp(check);
		check = ceil(HP2 * 1.1);
		HP2 = checkHp(check);
		return temp;
	}
}
// Task 4
int checkPassword(const char* s, const char* email)
{
	char se[100];
	int i = 0;
	while (email[i] != '@')
	{
		i++;
	}
	strncpy(se, email, i);
	se[i] = '\0';

	if (strlen(s) < 8)// check length
	{
		return -1;
	}
	else if (strlen(s) > 20)
	{
		return -2;
	}

	for (int t = 0; t < strlen(s); t++)
	{
		if (se[0] == s[t])// check if s contain se
		{
			int q = 0;
			while ((s[t + q] == se[q]) && s[t + q] != '\0' && se[q] != '\0')
			{
				q++;
				if (q == i)
				{
					return -(300 + t);
				}
			}
		}

		if (t + 2 <= strlen(s))//no more than 2 of the same letter appear consecutively
		{
			if (s[t] == s[t + 1] && s[t] == s[t + 2])
			{
				return -(400 + t);
			}
		}

		int count = 0;// check for special character
		if (s[t] == '@' || s[t] == '!' || (s[t] >= 35 && s[t] <= 37))
		{
			count++;
		}
		if (t == strlen(s) - 1 && count == 0)
		{
			return -5;
		}

		// others
		if (s[t] < 33 || (s[t] > 33 && s[t] < 35) || (s[t] > 37 && s[t] < 48) || (s[t] > 57 && s[t] < 64) || (s[t] > 90 && s[t] < 97) || s[t]>122)
		{
			return t;
		}

	}

	return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds)
{
	int location[30];
	int loca = -1;
	int y = 0;
	int freqency[30] = { 0 };
	const char* element[30];
	for (int i = 0; i < num_pwds; i++)//check if pass already appear, check how many time it appear, store when it first appear
	{
		int count = 0;
		for (int j = 0; j <= y; j++)
		{
			if (j == y && count == 0)
			{
				element[y] = arr_pwds[i];
				location[y] = i;
				freqency[y]++;
				count++;
				y++;
				break;
			}
			if (strcmp(arr_pwds[i], element[j]) == 0)
			{
				freqency[j]++;
				break;
			}
		}
	}
	const char* tempEle = element[0];// find the pass that is correct
	int tempFre = freqency[0];
	for (int t = 0; t < y; t++)
	{
		if (freqency[t] > tempFre || (freqency[t] == tempFre && strlen(element[t]) > strlen(tempEle)))
		{
			tempFre = freqency[t];
			tempEle = element[t];
			loca = t;
		}
	}

	return location[loca];
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////