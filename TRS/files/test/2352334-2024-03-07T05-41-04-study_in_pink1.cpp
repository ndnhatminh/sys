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
        int &E3
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
    } else {
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
	if (exp < 0)
	{
		exp = 0;
	}
	if (exp > 600)
	{
		exp = 600;
	}
}
void checkhp(int& hp)
{
	if (hp < 0)
	{
		hp = 0;
	}
	if (hp > 666)
	{
		hp = 666;
	}
}
void checkmoney(int& m)
{
	if (m < 0)
	{
		m = 0;
	}
	if (m > 3000)
	{
		m = 3000;
	}
}
int firstMeet(int& exp1, int& exp2, int e1)
{
	if ((e1 < 0) || (e1 > 99)) return -99;
	else {
		checkexp(exp1);
		checkexp(exp2);
		if ((e1 >= 0) && (e1 <= 3)) {
			if (e1 == 0) {
				exp2 += 29;
				checkexp(exp2);
			}
			else if (e1 == 1) {
				exp2 += 45;
				checkexp(exp2);
			}
			else if (e1 == 2) {
				exp2 += 75;
				checkexp(exp2);
			}
			else if (e1 == 3) {
				exp2 += 29 + 45 + 75;
				checkexp(exp2);
			}
			int D = e1 * 3 + exp1 * 7;
			if (D % 2 == 0) {
				exp1 = ceil(exp1 + (D / 200.0));
				checkexp(exp1);
			}
			else if (D % 2 != 0) {
				exp1 = ceil(exp1 - D / 100.0);
				checkexp(exp1);

			}
		}
		else {
			if ((e1 >= 4) && (e1 <= 19)) {
				exp2 = ceil(exp2 + (e1 / 4.0 + 19));
				checkexp(exp2);
			}
			else if ((e1 >= 20) && (e1 <= 49)) {
				exp2 = ceil(exp2 + (e1 / 9.0 + 21));
				checkexp(exp2);
			}
			else if ((e1 >= 50) && (e1 <= 65)) {
				exp2 = ceil(exp2 + (e1 / 16.0 + 17));
				checkexp(exp2);
			}
			else if ((e1 >= 66) && (e1 <= 79)) {
				exp2 = ceil(exp2 + (e1 / 4.0 + 19));
				checkexp(exp2);
				if (exp2 > 200) {
					exp2 = ceil(exp2 + (e1 / 9.0 + 21));
					checkexp(exp2);
				}
			}
			else if ((e1 >= 80) && (e1 <= 99)) {
				exp2 = ceil(exp2 + (e1 / 4.0 + 19));
				checkexp(exp2);
				exp2 = ceil(exp2 + (e1 / 9.0 + 21));
				checkexp(exp2);
				if (exp2 > 400) {
					exp2 = ceil(exp2 + (e1 / 16.0 + 17));
					checkexp(exp2);
					exp2 = ceil(exp2 + exp2 * 0.15);
					checkexp(exp2);
				}
			}
			exp1 = exp1 - e1;
			checkexp(exp1);


		}
	}
	return exp1 + exp2;
}

double calcT2(int EXP1)
{
	int S = 0, id = 0;
	for (int i = 0; i * i <= EXP1; i++)
	{
		S = i * i;
		id = i;
	}
	id++;
	if (id * id - EXP1 < EXP1 - S)
	{
		S = id * id;
	}
	double P;
	if (EXP1 >= S)
	{
		P = (double)1;
	}
	else P = (double)(EXP1 / S + 80) / 123;
	return P;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {

	if ((E2 < 0) || (E2 > 99)) return -99;
	else
	{
		checkexp(EXP1);
		checkhp(HP1);
		checkmoney(M1);
		double P1 = calcT2(EXP1);
		int m = 0, STARTF = M1;

		while (E2 % 2 == 1)
		{
			if (M1 == 0) break;
			if (HP1 < 200)
			{
				M1 -= 150;							
				m += 150;
				checkmoney(M1);
				HP1 = ceil(HP1 + HP1 * 30.0 / 100);
				checkhp(HP1);
				if (M1 == 0) break;
			}
			else
			{
				M1 -= 70;
				m += 70;
				checkmoney(M1);
				HP1 = ceil(HP1 + HP1 * 10.0 / 100);
				checkhp(HP1);
				if (M1 == 0) break;
			}
			if (m > STARTF / 2) break;

			if (EXP1 < 400)
			{
				M1 -= 200;
				m += 200;
				checkmoney(M1);
			}
			else
			{
				M1 -= 120;
				checkmoney(M1);
				m += 120;
			}
			EXP1 = ceil(EXP1 + EXP1 * 13.0 / 100);
			checkexp(EXP1);
			if (M1 == 0) break;
			if (m > STARTF / 2) break;

			if (EXP1 < 300)							
			{
				M1 -= 100;
				checkmoney(M1);
				m += 100;
			}
			else {
				M1 -= 120;
				checkmoney(M1);
				m += 120;
			}
			EXP1 = ceil(EXP1 - EXP1 * 10.0 / 100);
			checkexp(EXP1);
			if (M1 == 0) break;
			if (m > STARTF / 2) break;
		} 

		if (E2 % 2 == 0)
		{
			checkexp(EXP1);
			checkmoney(M1);
			if (M1 == 0) goto jump;
			if (HP1 < 200)
			{
				M1 -= 150;
				m += 150;
				checkmoney(M1);
				HP1 = ceil(HP1 + HP1 * 30.0 / 100);
				checkhp(HP1);
				if (M1 == 0) goto jump;
			}
			else
			{
				M1 -= 70;				
				m += 70;
				checkmoney(M1);
				HP1 = ceil(HP1 + HP1 * 10.0 / 100); 
				checkhp(HP1);
				if (M1 == 0) goto jump;
			}
			{
				if (EXP1 < 400)
				{
					M1 -= 200;							
					m += 200;
					checkmoney(M1);
				}
				else
				{
					M1 -= 120;
					checkmoney(M1);
					m += 120;
				}
				EXP1 = ceil(EXP1 + EXP1 * 13.0 / 100); 
				checkexp(EXP1);
				if (M1 == 0) goto jump;
			}
			
			// nguoi vo gia cu
			{
				if (EXP1 < 300)

				{
					M1 -= 100;
					checkmoney(M1);
					m += 100;

				}
				else
				{
					M1 -= 120;
					checkmoney(M1);
					m += 120;
				}
				EXP1 = ceil(EXP1 - EXP1 * 10.0 / 100);
				checkexp(EXP1);
				if (M1 <= 0) goto jump;
			}
		}
	jump:
		HP1 = ceil(HP1 - (HP1 * 17.0 / 100.0));						
		checkhp(HP1);
		EXP1 = ceil(EXP1 + (EXP1 * 17.0 / 100.0));
		checkexp(EXP1);

		double P2 = calcT2(EXP1);
		double P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
		double P3;
		int x = E2, i = 0;
		if (x < 10)
		{
			P3 = (double)P[x] /100;
		}
		else
		{
			i = (x / 10 + x % 10) % 10;
			P3 = (double)P[i] / 100;
		}
		double PTB = (P1 + P2 + P3) / 3.0;
		if (PTB == (double)1)
		{
			EXP1 = ceil(EXP1 - EXP1 * 25.0 / 100);
			checkexp(EXP1);
		}
		else if (PTB < 0.5)
		{
			HP1 = ceil(HP1 - HP1 * 15.0 / 100);
			checkhp(HP1);
			EXP1 = ceil(EXP1 + EXP1 * 15.0 / 100);
			checkexp(EXP1);
		}
		else
		{
			HP1 = ceil(HP1 - HP1 * 10.0 / 100);
			checkhp(HP1);
			EXP1 = ceil(EXP1 + EXP1 * 20.0 / 100.00);
			checkexp(EXP1);
		}
	}
	return HP1 + EXP1 + M1;
}

int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3)
{
    if (E3 < 0 || E3 > 99) 
    {
        return -99;
    }
    int taxiMap[10][10] = {0};
    int SW[10][10] = {0};

    for (int i = 0; i < 10; ++i) 
    {
        for (int j = 0; j < 10; ++j) 
        {
            taxiMap[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int leftTaxi, rightTaxi;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (i + j < 10) leftTaxi = taxiMap[i + j][0];
            else leftTaxi = taxiMap[10 - 1][i + j - 10 + 1];

            if (i < j) rightTaxi = taxiMap[i][j - i];
            else rightTaxi = taxiMap[i - j][10 - 1];

            int taxiScore = max(leftTaxi, rightTaxi);
            SW[i][j] = taxiScore;
        }
    }
    int more = 0, less = 0;
    for (int i = 0; i < 10; ++i) 
    {
        for (int j = 0; j < 10; ++j) 
        {
            if (taxiMap[i][j] > E3 * 2)
                more++;
            if (taxiMap[i][j] < -E3)
                less++;
        }
    }
    while (more >= 10) {
        more = more / 10 + more % 10;
    }
    while (less >= 10) {
        less = less / 10 + less % 10;
    }
	int meetI = 0, meetJ = 0;
    meetI = more;
    meetJ = less;

    int taxiGrade = taxiMap[meetI][meetJ];
    int SWGrade = SW[meetI][meetJ];

    checkexp(EXP1);
    checkhp(HP1);
    checkexp(EXP2);
    checkhp(HP2);
    if (abs(taxiGrade) > SWGrade)
    {
        HP1 = ceil(HP1 - HP1 * 0.1);
        EXP1 = ceil(EXP1 - EXP1 * 0.12);
        HP2 = ceil(HP2 - HP2 * 0.1);
        EXP2 = ceil(EXP2 - EXP2 * 0.12);
    }
    else 
    {
        HP1 = ceil(HP1 + HP1 * 0.1);
        EXP1 = ceil(EXP1 + EXP1 * 0.12);
        HP2 = ceil(HP2 + HP2 * 0.1);
        EXP2 = ceil(EXP2 + EXP2 * 0.12);
    }
    checkexp(EXP1);
    checkhp(HP1);
    checkexp(EXP2);
    checkhp(HP2); 
    int result;
    int n;
    n = abs(taxiGrade);
    if ( n > SWGrade ) result = taxiGrade;
    else result = SWGrade;
    return result;	
}

// Task 4
int checkPassword(const char* s, const char* email)
{
    string se(email);
    se = se.substr(0, se.find('@')); 
    int count = strlen(s); 
    if (count < 8) 
    {
        return -1;
    }
    else if (count > 20) {
        return -2;
    }
    else
    {
        int sei = strstr(s, se.c_str()) - s ;
        if (strstr(s, se.c_str()) != NULL) {
            return -(300 + sei);
            
        }

        for (int i = 0; i < (count - 2); i++) {
            if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
                return -(400 + i);
            }
        }
        bool specialChar = false;
        for (int j = 0; j < count; j++) {
            if (!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9') ||
                s[j] == '@' || s[j] == '#' || s[j] == '%' || s[j] == '$' || s[j] == '!')) {
                return j;
            }
            if (s[j] == '@' || s[j] == '#' || s[j] == '%' || s[j] == '$' || s[j] == '!') {
                specialChar = true;
            }
        }

        if (!specialChar)
        {
            return -5;
        }

        return -10;
    }
}

bool compare(const char* a, const char* b) {
    return strcmp(a, b) == 0;
}

int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int max_length = 0;
    int max_appear = 0;
    int first = num_pwds; 

    for (int i = 0; i < num_pwds; ++i) {
        int length = strlen(arr_pwds[i]);
        int appear = 1; 
        for (int j = i + 1; j < num_pwds; ++j) {
            if (compare(arr_pwds[i], arr_pwds[j])) {
                appear++; 
            }
        }
        if (appear > max_appear || (appear == max_appear && length > max_length)) {
            max_appear = appear;
            max_length = length;
            first = i;
        }
    }

    for (int i = 0; i < num_pwds; ++i) {
        int length = strlen(arr_pwds[i]);
        int appear = 1;
        for (int j = i + 1; j < num_pwds; ++j) {
            if (compare(arr_pwds[i], arr_pwds[j])) {
                appear++;
            }
        }
        if (appear == max_appear && length == max_length && i < first) {
            first = i;
        }
    }

    return first;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////