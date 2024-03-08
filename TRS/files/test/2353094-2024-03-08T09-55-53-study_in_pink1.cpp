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
    // DO NOT MODIFY THIS FUNCTION
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

// SUPPORT FUNCTIONS

// Fix HP Value
void fixHP(int & HP)
{
    if (HP > 666) HP = 666;
    else if (HP < 0) HP = 0;
    
    return;
}

// Fix EXP Value
void fixEXP(int & EXP)
{
    if (EXP > 600) EXP = 600;
    else if (EXP < 0) EXP = 0;
    
    return;
}

// Fix Money Value
void fixMoney(int & M)
{   
    if (M > 3000) M = 3000;
    else if (M < 0) M = 0;

    return;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    if ((e1 < 0) || (e1 > 99)) return -99; //error
	
    // case 1
    fixEXP(exp1);
    fixEXP(exp2);
	if (0 <= e1 && e1 <= 3)
	{
		//sherlock observation
		switch (e1)
		{
        	// change watson exp2
			case 0: 
				{
					exp2 += 29;
					break;	
				}
		    
			case 1:
				{
					exp2 += 45;
				 	break;
				}
		    
			case 2: 
				{
					exp2 += 75;
					break;
				}	
		    
			case 3:
		        {
		        	exp2 += (29 + 45 + 75);
		        	break;
				}    
		}
	
		// sherlock conclusion
		if ((e1 * 3 + exp1 * 7) % 2 == 0) exp1 += ceil(((e1 * 3 + exp1 * 7) / 200.0));
		else exp1 = ceil(exp1 - ((e1 * 3 + exp1 * 7) / 100.0));
	}
	
	// case 2
	else if (4 <= e1 && e1 <= 99)
	{
		// change watson exp2 
		if (4 <= e1 && e1 <= 19) exp2 += ceil(e1 / 4.0 + 19);
		else if (20 <= e1 && e1 <= 49) exp2 += ceil(e1 / 9.0 + 21);
		else if (50 <= e1 && e1 <= 65) exp2 += ceil(e1 / 16.0 + 17); 
		else if (66 <= e1 && e1 <= 79)
		{
			exp2 += ceil(e1 / 4.0 + 19);	// explain in4 1
			if (exp2 > 200) exp2 += ceil(e1 / 9.0 + 21);	// explain in4 2
		}
		else if (80 <= e1 && e1 <= 99)	
		{
			exp2 += ceil(e1 / 4.0 + 19);	// explain in4 1
			exp2 += ceil(e1 / 9.0 + 21);	// explain in4 2
			if (exp2 > 400)
			{
				exp2 += ceil(e1 / 16.0 + 17);	// explain in4 3
				exp2 = ceil(exp2 * 1.15);	// bonus after 3 in4
			}	
		}
	
		// sherlock mistake
		exp1 -= e1;
	}
	
	// Fix EXP values
	fixEXP(exp1);
	fixEXP(exp2);
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

	if ((E2 < 0) || (E2 > 99)) return -99;	//error
	
	// FIX STATS
	fixHP(HP1);
	fixEXP(EXP1);
	fixMoney(M1);

	// Var declaration
	double p1, p2, p3;	// probabilities of 3 roads
	short wallet = M1;	// for Road 2 calculation
	short P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};	// for Road 3 calculation
	
		// Road 01
		// Check Perfect Square Number
		if (((pow(ceil(sqrt(EXP1)), 2) - EXP1) > (EXP1 - pow((ceil(sqrt(EXP1)) - 1), 2))) || (pow(ceil(sqrt(EXP1)), 2) == EXP1)) p1 = 1;
		else p1 = (EXP1 / pow(ceil(sqrt(EXP1)), 2) + 80) / 123;
			
		// Road 02
		do
		{
			// Event 1
			if ((HP1 < 200) && (M1 > 0) && (((wallet - M1) < ceil(wallet / 2 + 0.5)) || (E2 % 2 == 0)))
			{
				HP1 += ceil(HP1 * 0.3);
				M1 -= 150;
			}
			else if ((HP1 >= 200) && (M1 > 0) && (((wallet - M1) < ceil(wallet / 2 + 0.5)) || (E2 % 2 == 0)))
				{
					HP1 += ceil(HP1 * 0.1);
					M1 -= 70;
				}
			// Fix Stats
			fixHP(HP1);
			fixMoney(M1);

			// Event 2
			if ((EXP1 < 400) && (M1 > 0) && (((wallet - M1) < ceil(wallet / 2 + 0.5)) || (E2 % 2 == 0)))
			{
				M1 -= 200;
				EXP1 += ceil(EXP1 * 0.13);
			}
			else if ((EXP1 >= 400) && (M1 > 0) && (((wallet - M1) < ceil(wallet / 2 + 0.5)) || (E2 % 2 == 0)))
				{
					M1 -= 120;
					EXP1 += ceil(EXP1 * 0.13);
				}
			// Fix Stats
			fixHP(HP1);
			fixEXP(EXP1);
			fixMoney(M1);

			// Event 3
			if ((EXP1 < 300) && (M1 > 0) && (((wallet - M1) < ceil(wallet / 2 + 0.5)) || (E2 % 2 == 0)))
			{
				M1 -= 100;
				EXP1 = ceil(EXP1 - EXP1 * 0.1);
			}
			else if ((EXP1 >= 300) && (M1 > 0) && (((wallet - M1) < ceil(wallet / 2 + 0.5)) || (E2 % 2 == 0))	)
				{
					M1 -= 120;
					EXP1 = ceil(EXP1 - EXP1 * 0.1);
				}
			// Fix Stats
			fixHP(HP1);
			fixEXP(EXP1);
			fixMoney(M1);
		}
		while ((E2 % 2 == 1) && (M1 > 0) && ((wallet - M1) < ceil(wallet / 2 + 0.5)));
		// Sherlock walk to the End of Road 2
		HP1 = ceil(HP1 - HP1 * 0.17);
		EXP1 = ceil(EXP1 * 1.17);
        // Fix Stats
		fixHP(HP1);
        fixEXP(EXP1);
		// Possibility on Road 2
		if (((pow(ceil(sqrt(EXP1)), 2) - EXP1) > (EXP1 - pow((ceil(sqrt(EXP1)) - 1), 2))) || (pow(ceil(sqrt(EXP1)), 2) == EXP1)) p2 = 1;
		else p2 = (EXP1 / pow(ceil(sqrt(EXP1)), 2) + 80) / 123;
		    		    
		// Road 3
		if (E2 < 10) p3 = P[E2] / 100.0;
		else p3 = P[((E2 / 10) + (E2 % 10)) % 10] / 100.0;
						
		// Finding Suitcase
		if ((p1 == 1.0) && (p2 == 1.0) && (p3 == 1.0)) EXP1 = ceil(EXP1 * 0.75);
		else if ((p1 + p2 + p3) / 3 >= 0.5)
			{
				HP1 = ceil(HP1 * 0.9);
				EXP1 += ceil(EXP1 * 0.2);
			}
		else
		{
			HP1 = ceil(HP1 * 0.85);
			EXP1 += ceil(EXP1 * 0.15);
		}	
	

	// FIX STATS
	fixHP(HP1);
	fixEXP(EXP1);
	fixMoney(M1);

	return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
	if ((E3 < 0) || (E3 > 99)) return -99;	// error
    
	// FIX STATS
	fixHP(HP1);
	fixEXP(EXP1);
    fixHP(HP2);
    fixEXP(EXP2);

	// Var declaration
	short taxi[10][10], chaser[10][10], temp[10], a, b;
				
	// Taxi score
	for (short i = 0; i < 10; i++)
	{
		for (short j = 0; j < 10; j++)
		{
			taxi[i][j] = (((E3 * j) + (i * 2)) * (i - j));
		}
	}
		
	// Sherlock & Watson score
	for (short i = 0; i < 10; i++)
	{
		for (short j = 0; j < 10; j++)
		{
			// LEFT DIAGONAL
			a = i;
			b = j;
			// pos(a, b) to Most LEFT
			while ((a > 0) && (b > 0))
			{
				a--;
				b--;
			}
			// reset array
			for (short count = 0; count < 10; count++)
			{
				temp[count] = taxi[a][b];
			}
			// most left to Most Right
			while ((a < 10) && (b < 10))
			{
				temp[a] = taxi[a][b];	
				a++;
				b++;
			}
			// find Max Value of LEFT DIAGONAL
			chaser[i][j] = temp[0];
			for (a = 1; a < 10; a++)
			{
				if (temp[a] > chaser[i][j]) chaser[i][j] = temp[a]; 
			}
				
			// RIGHT DIAGONAL
			a = i;
			b = j;
			// pos(a, b) to Most LEFT
			while ((a < 9) && (b > 0))
			{
				a++;
				b--;
			}
			// reset array
			for (short count = 0; count < 10; count++)
			{
				temp[count] = taxi[a][b];
			}
			// most left to Most Right
			while ((a >= 0) && (b < 10))
			{
				temp[b] = taxi[a][b];
				a--;
				b++;
			}
			// find Max Value of LEFT and RIGHT Diagonal
			for (a = 0; a < 10; a++)
			{
				if (temp[a] > chaser[i][j]) chaser[i][j] = temp[a]; 
			}
		}
	}
		
	// RESET a, b 
	a = 0;
	b = 0;
	
	// MEETING LOCATION
	// check taxi matrix
	for (short i = 0; i < 10; i++)
	{
		for (short j = 0; j < 10; j++)
		{
			if (taxi[i][j] > (E3 * 2)) a++;
			else if (taxi[i][j] < (- E3)) b++;
		}
	}
	// find coordinates
	while((a >= 10) || (b >= 10))
	{
		a = ((a / 10) + (a % 10));
		b = ((b / 10) + (b % 10));
	}
	// chase result
	if (abs(taxi[a][b]) > abs(chaser[a][b]))
	{
		HP1 = ceil(HP1 - HP1 * 0.1);
		HP2 = ceil(HP2 - HP2 * 0.1);
		EXP1 = ceil(EXP1 * 0.88);
		EXP2 = ceil(EXP2 * 0.88);

		// FIX STATS
		fixHP(HP1);
		fixEXP(EXP1);
        fixHP(HP2);
        fixEXP(EXP2);

		return taxi[a][b];
	}
	else
	{
		HP1 += ceil(HP1 * 0.1);
		HP2 += ceil(HP2 * 0.1);
		EXP1 += ceil(EXP1 * 0.12);
		EXP2 += ceil(EXP2 * 0.12);
		
		// FIX STATS
		fixHP(HP1);
		fixEXP(EXP1);
        fixHP(HP2);
        fixEXP(EXP2);

		return chaser[a][b];
	}
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    // declare var
    string address = email;
    short size;
    
    // GET STRING se
    // get se size
	for (short i = (address.length() - 1); i >= 0; i-- )
	{
		if (address[i] == '@')
		{
			size = i;
			break;
		}
	}
	// declare se
	char se[size];
	
    // passing 'address' to 'se'
    for (short i = 0; i < size; i++)
    {
        se[i] = address[i];
    }
    
    // GET STRING pass
    address = s;
    // get pass size
    size = address.length();
    // declare pass
    char pass[size];
    // passing 'address' to 'pass'
    for (short i = 0; i < size; i++)
    {
        pass[i] = address[i];
    }

    // CHECK PASS
    if (sizeof(pass) < 8) return -1;	// too short
    else if (sizeof(pass) > 20) return -2;	// too long
    
    size = 0;   // reset size -> counter var
        
    for (short i = 0; i < sizeof(pass); i++)
    {
        if (size == sizeof(se))	return -(300 + i - size);   // contains string 'se'
		// check if contain string 'se'
        if (pass[i] == se[size]) size += 1;
        else size = 0;   
    }

	size = 0;	// reset size -> counter var
	for (short i = 0; i < sizeof(pass); i++)
	{    
		// check consecutive & identical
        if ((pass[i] == pass[i + 1]) && (pass[i + 1] == pass[i + 2])) return -(400 + i);	// contains more 2 (at least 3) consecutive + idendical characters 

		// check special character (except character '@' will be used for later case)
        if ((pass[i] == '#') || (pass[i] == '%') || (pass[i] == '$') || (pass[i] == '!')) size += 1;
	}
	if (size == 0) return -5;	// Not include special character
	for (short i = 0; i < sizeof(pass); i++)
	{
		// check other cases - OUT OF VALID CHARACTERS
		size = static_cast<int>(pass[i]);
		if ((size < 33) || (size == 34) || ((size > 37) && (size < 48)) || ((size > 57) && (size < 65)) || ((size > 90) && (size < 97)) || (size > 122)) return i;
	}
	return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    // var DECLARATION
	string pass[num_pwds];	// array of passwords
	string mostFreq;	// the correct pass
	short maxCount = 0; // numbers of occurence
	
	// PASSING "arr_pwds"'s values to "pass"
	for (short i = 0; i < num_pwds; i++) pass[i] = arr_pwds[i];
	
	//CHECK PASS
	for (short i = 0; i < num_pwds; i++)
	{
		short count = 0;	//counter var
		for (short j = 0; j < num_pwds; j++) if (pass[i] == pass[j]) count++;
		if ((count > maxCount) || ((count == maxCount) && pass[i].length() > mostFreq.length()))
		{
			maxCount = count;
			mostFreq = pass[i];
		}
	}
	// return the correct pass
	for (short i = 0; i < num_pwds; i++) if(pass[i] == mostFreq) 
	{
		maxCount = i;
		break;
	}
	return maxCount;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
