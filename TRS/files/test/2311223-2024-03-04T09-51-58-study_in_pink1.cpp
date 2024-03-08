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
int verifyValue(int num, int bottom, int top)
{
	if (num < bottom) return bottom;
	else if (num > top) return top;
	else return num;
}
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
	EXP1 = verifyValue(EXP1, 0,600);
	EXP2 = verifyValue(EXP2, 0, 600);
	if ((E1 < 0) || (E1 > 99)) return -99;
	int D;
	if ((E1 >= 0) && (E1 <= 3)) {
		switch (E1)
		{
		case 0:
		{
			EXP2 = verifyValue(EXP2 + 29, 0, 600);
			break;
		}
		case 1:
		{
			EXP2 = verifyValue(EXP2 + 45, 0, 600);
			break;
		}
		case 2:
		{
			EXP2 = verifyValue(EXP2 + 75, 0, 600);
			break;
		}
		case 3:
		{
			EXP2 = verifyValue(EXP2 + 29 + 45 + 75, 0, 600);
			break;
		}
		}
		D = E1 * 3 + EXP1 * 7;
		if  (D % 2 == 0)
		{
			EXP1 = verifyValue(EXP1 + (float)D / 200 + 0.999, 0, 600);
		}
		else 
		{
				EXP1 = verifyValue(EXP1 - (float)D / 100 + 0.999, 0, 600);
		}
	}
	else
	{
		if ((E1 >= 4) && (E1 <= 19))
		{
			EXP2 = verifyValue(EXP2 + (float)E1 / 4 + 19 + 0.999, 0, 600);
		}
		else if ((E1 >= 20) && (E1 <= 49))
		{
			EXP2 = verifyValue(EXP2 + (float)E1 / 9 + 21 + 0.999, 0, 600);

		}
		else if ((E1 >= 50) && (E1 <= 65))
		{
			EXP2 = verifyValue(EXP2 + (float)E1 / 16 + 17 + 0.999, 0, 600);
		}
		else if ((E1 >= 66) && (E1 <= 79))
		{
			EXP2 = verifyValue(EXP2 + (float)E1 / 4 + 19 + 0.999, 0, 600);
			if (EXP2 > 200)
			{
				EXP2 = verifyValue(EXP2 + (float)E1 / 9 + 21 + 0.999, 0, 600);
			}
		}
		else if ((E1 >= 80) && (E1 <= 99))
		{
			EXP2 = verifyValue(EXP2 + (float)E1 / 4 + 19 + 0.999, 0, 600);
			EXP2 = verifyValue(EXP2 + (float)E1 / 9 + 21 + 0.999, 0, 600);
			if (EXP2 > 400)
			{
				EXP2 = verifyValue(EXP2 + (float)E1 / 16 + 17 +0.999, 0, 600);
				EXP2 = verifyValue((float)EXP2 * 1.15+0.999, 0, 600);
			}

		}
		EXP1 = verifyValue(EXP1 - E1, 0, 600);

	}
    return EXP1 + EXP2;
}
float scp(float& P, int EXP1)
{
	int scpt, scps, S;
	scpt = sqrt(EXP1);
	scps = scpt + 1;
	scpt = scpt * scpt;
	scps *= scps;
	if (abs(scpt - EXP1) < abs(scps - EXP1))
	{
		S = scpt;
	}
	else S = scps;
	if (EXP1 >= S)
	{
		return P = 1;
	}
	else return P = (((float)EXP1 / S) + 80) / 123;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
	HP1 = verifyValue(HP1,0,666);
	EXP1 = verifyValue(EXP1, 0, 600);
	M1 = verifyValue(M1, 0, 3000);
	if ((E2 < 0) || (E2 > 99)) return -99;
	int P[10] = { 32,47,28,79,100,50,22,83,64,11 };
	float P1, P2, P3, Haft;
	P1 = scp(P1, EXP1);
	// .................................................................
	Haft = (float)M1 / 2;
	do
	{
		if (HP1 < 200)
		{
			HP1 = verifyValue((float)HP1 * 1.3+0.999, 0, 666);
			M1 = verifyValue(M1 - 150, 0, 3000);
		}
		else
		{
			HP1 = verifyValue((float)HP1 * 1.1+0.999, 0, 666);
			M1 = verifyValue(M1 - 70, 0, 3000);
		}
		if (((E2 % 2 == 1) && (M1 < Haft)) || ((E2 % 2 == 0) && (M1 == 0))) break;
		if (EXP1 < 400)
		{
			M1 = verifyValue(M1 - 200, 0, 3000);
		}
		else
		{
			M1 = verifyValue(M1 - 120, 0, 3000);
		}
		EXP1 = verifyValue((float)EXP1 * 1.13+0.999, 0, 600);
		if (((E2 % 2 == 1) && (M1 < Haft)) || ((E2 % 2 == 0) && (M1 == 0))) break;
		if (EXP1 < 300)
		{
			M1 = verifyValue(M1 - 100, 0, 3000);
		}
		else
		{
			M1 = verifyValue(M1 - 120, 0, 3000);
		}
		EXP1 = verifyValue((float)EXP1 * 0.9+0.999, 0, 600);
		if (((E2 % 2 == 1) && (M1 < Haft)) || ((E2 % 2 == 0) && (M1 == 0))) break;
	} while ((E2 % 2 == 1) && (M1 >= Haft));
	HP1 = verifyValue((float)HP1 * 0.83+0.999, 0, 666);
	EXP1 = verifyValue((float)EXP1 * 1.17+ 0.999, 0, 600);
	P2 = scp(P2, EXP1);
	
	//..............................................................
		E2 = ((E2 % 10) + (E2 / 10)) % 10;
		P3 = P[E2];
	
	
	//...............................................................
	if ((P1 == 1) && (P2 == 1) && (P3 == 1))
	{
		EXP1 = verifyValue((float)EXP1 * 0.75+0.999, 0, 600);
	}
	else
	{
		P1 = (P1 + P2 + (float)P3/100) / 3;
		if (P1 < 0.5)
		{
			HP1 = verifyValue((float)HP1 * 0.85+0.999, 0, 666);
			EXP1 = verifyValue((float)EXP1 * 1.15+0.999, 0, 600);
		}
		else
		{
			HP1 = verifyValue((float)HP1 * 0.9+0.999, 0, 666);
			EXP1 = verifyValue((float)EXP1 * 1.2+0.999, 0, 600);
		}
	}

	
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
	HP1 = verifyValue(HP1, 0, 666);
	EXP1 = verifyValue(EXP1, 0, 600);
	HP2 = verifyValue(HP2, 0, 666);
	EXP2 = verifyValue(EXP2, 0, 600);
	if ((E3 < 0) || (E3 > 99)) return -99;
	int xi = 0, yi = 0, TAXI, SHERLOCK, i, j;
	int MT[10][10];
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			MT[i][j] = ((E3 * j) + (i * 2)) * (i - j);
			if (MT[i][j] > (E3 * 2)) xi++;
			if (MT[i][j] < (-E3)) yi++;
		}
	}
	
		xi = (xi % 10) + (xi / 10);
		xi = (xi % 10) + (xi / 10);
	
		yi = (yi % 10) + (yi / 10);
		yi = (yi % 10) + (yi / 10);
	
	TAXI = MT[xi][yi];
	SHERLOCK = MT[xi][yi];
	i = xi;
	j = yi;
	while ((i >= 0) && (j <= 9))
	{
		if (MT[i][j] > SHERLOCK) SHERLOCK = MT[i][j];
		i--;
		j++;
	}
	i = xi;
	j = yi;
	while ((i <= 9) && (j >= 0))
	{
		if (MT[i][j] > SHERLOCK) SHERLOCK = MT[i][j];
		i++;
		j--;
	}
	i = xi;
	j = yi;
	while ((i >= 0) && (j >= 0))
	{
		if (MT[i][j] > SHERLOCK) SHERLOCK = MT[i][j];
		i--;
		j--;
	}
	i = xi;
	j = yi;
	while ((i <= 9) && (j <= 9))
	{
		if (MT[i][j] > SHERLOCK) SHERLOCK = MT[i][j];
		i++;
		j++;
	}
	if (abs(TAXI) > SHERLOCK)
	{
		EXP1 = verifyValue((float)EXP1 * 0.88+ 0.999, 0, 600);
		HP1 = verifyValue((float)HP1 * 0.9 + 0.999, 0, 666);
		EXP2 = verifyValue((float)EXP2 * 0.88+ 0.999, 0, 600);
		HP2 = verifyValue((float)HP2 * 0.9+ 0.999, 0, 600);
		return TAXI;
	}
	else
	{
		EXP1 = verifyValue((float)EXP1 * 1.12+ 0.999, 0, 600);
		HP1 = verifyValue((float)HP1 * 1.1+ 0.999, 0, 666);
		EXP2 = verifyValue((float)EXP2 * 1.12+ 0.999, 0, 600);
		HP2 = verifyValue((float)HP2 * 1.1+0.999, 0, 666);
		return SHERLOCK ;
	}
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
	int l=0, sei, sci,d2=-1,sll;
	size_t n, m, c = 1, ktdb = 0,d1=0;
	for (int i = 0; email[i] != '@'; i++)
	{
		l++;
	}
	if (strlen(s) < 8) {return -1; }
	else
	{
		if (strlen(s) > 20) { return -2; }
		else
		{
			for (int i = 0; i < strlen(s); i++)
			{
				if (s[i] == email[0])
				{
					sei = i;
					n = i + 1;
					m = 1;
					c = 1; sll = l;
					while (sll > 1)
					{
						if (s[n] == email[m])
						{
							c++; n++; m++; sll--;
						}
						else break;
					}
				}
				if (c == l ) { return -300 - sei; }
				if ((i >= 2) && (s[i] == s[i - 1]) && (s[i] == s[i -2]) &&(d1 != 1))
				{
					sci = i - 2;
					d1 =1 ;
				}
				if ((s[i] == '@')||(s[i] == '$')||(s[i] == '%')||(s[i] == '#')||(s[i] == '!')) ktdb++;
				
				if (
					!(((s[i] >= '0') && (s[i] <= '9'))
					|| ((s[i] >= 'a') && (s[i] <= 'z'))
					|| ((s[i] >= '@') && (s[i] <= 'Z'))
					|| ((s[i] >= '#') && (s[i] <= '%')) || (s[i] == '!')))
				{
				 if(d2 == -1 ) d2 = i; 
				}
			}
			if (d1 == 1 ) { return -400 - sci; }
			if (ktdb == 0) { return -5; }
			if (d2 != -1) { return d2; }
			return -10; 
		}
	} 
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max = 0, k = 0;
    int arr[250];
    for (int i = 0; i < num_pwds; i++)
        arr[i] = 1;
    for (int i = 0; i < num_pwds; i++)
    {
        for (int j = i + 1; j < num_pwds; j++)
        {
            if ((arr_pwds[i] == arr_pwds[j]))
            {
                arr[i]++;
                arr[j] = 0;
            }
        }
    }
    for (int i = 0; i < num_pwds; i++)
    {
        if ((arr[i] > max) || ((arr[i] == max) && (strlen(arr_pwds[i]) > strlen(arr_pwds[k]))))
        {
            max = arr[i];
            k = i;
        }
    }

    return k;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////