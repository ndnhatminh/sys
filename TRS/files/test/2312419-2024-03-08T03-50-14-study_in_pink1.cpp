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

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
	if (!(e1 >= 0 && e1 <= 99)) return -99;
    if (exp1 > 600) exp1 = 600;
    if (exp1 < 0) exp1 = 0;
    if (exp2 > 600) exp2 = 600;
    if (exp2 < 0) exp2 = 0;
	
    if ( e1 >= 0 && e1 <= 3 )
    {
    	switch (e1)
    	{
    		case 0:
    			exp2 += 29;
    			break;
    		case 1: 
    			exp2 += 45;
    			break;
    		case 2: 
    			exp2 += 75;
    			break;
    		case 3: 
    			exp2 += 149;
    			break;
		}
		if(exp2 > 600) exp2 = 600;
		
		int d = e1 * 3 + exp1 * 7;
		
		if ( d % 2 == 0)
		{
			exp1 += ceil(float(d)/200); if(exp1 > 600) exp1 = 600;
		}
		else 
		{
			exp1 = ceil(exp1 - float(d)/100); if(exp1 < 0) exp1 = 0;
		}
		
	}
	else if ( e1 >= 4 && e1 <= 99)
	{
		if (e1 <= 19)
		{
			exp2 += ceil(float(e1)/4 +  19);
		}
		else if (e1 <= 49)
		{
			exp2 += ceil(float(e1)/9 +  21);
		}
		else if (e1 <= 65)
		{
			exp2 += ceil(float(e1)/16 +  17);
		}
		else if ( e1 <= 79 )
		{
			exp2 += ceil(float(e1)/4 +  19);if(exp2 > 600) exp2 = 600;
			if (exp2 > 200)
			{
				exp2 += ceil(float(e1)/9 +  21);
			}
		}
		else if (e1 <= 99)
		{
			exp2 += ceil(float(e1)/4 +  19);if(exp2 > 600) exp2 = 600;
			exp2 += ceil(float(e1)/9 +  21);if(exp2 > 600) exp2 = 600;
			if (exp2 > 400)
			{
				exp2 += ceil(float(e1)/16 + 17); if(exp2 > 600) exp2 = 600;
				exp2 += ceil(0.15 * exp2); 
			}
		}
		if(exp2 > 600) exp2 = 600;
		exp1 -= e1; if(exp1 < 0) exp1 = 0;
	}

    
    return exp1 + exp2;
    
    
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (!(E2 >= 0 && E2 <= 99)) return -99;
	if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    if (M1 > 3000) M1 = 3000;
    if (M1 < 0) M1 = 0;
 //1 con duong 1
    
	float p1;
	
    int s1 = pow(round(sqrt(EXP1)),2);
   	
    if ( EXP1 >= s1)
    {
    	p1 = 1;
	}
	else 
	{
		p1 = float((float(EXP1)/s1) + 80)/123;
	}
	
	
	
	//2 con duong 2
	if ( E2 % 2 != 0)
	{
		float M = 0.5 * M1; 
		while (M1 > 0)
		{
			
			if (HP1 < 200)//1
			{
				HP1 = ceil( HP1 + 0.3 * HP1);
				M1 -= 150;
			}
			else 
			{
				HP1 = ceil(HP1 + 0.1 * HP1);
				M1 -= 70;
			}
			
			if (HP1 > 666) HP1 = 666;
			
			if ( M1 < M ) break;
			
			if (EXP1 < 400)//2
			{
				M1 -= 200;
			}
			else 
			{
				M1 -= 120;
			}
			EXP1 = ceil(EXP1 + 0.13 * EXP1); if (EXP1 > 600) EXP1 = 600;
			if ( M1 < M ) break;
			
			if (EXP1 < 300)//3
			{
				M1 -= 100;
			}
			else 
			{
				M1 -= 120;
			}
			EXP1 = ceil(EXP1 - 0.1 * EXP1); 
			if ( M1 < M ) break;
		}
		
	}
	else 
	{
		do
		{
			if (M1 == 0) break;
			if (HP1 < 200)//1
			{
				HP1 = ceil(HP1 + 0.3 * HP1);
				M1 -= 150;
			}
			else 
			{
				HP1 = ceil(HP1 + 0.1 * HP1);
				M1 -= 70; 
			}
			if (HP1 > 666) HP1 = 666;
			if ( M1 <= 0 ) break;
		
			
			if (EXP1 < 400)//2
			{
				M1 -= 200;
			}
			else 
			{
				M1 -= 120;
			}
			EXP1 = ceil(EXP1 + 0.13 * EXP1); if (EXP1 > 600) EXP1 = 600;
			if ( M1 <= 0 ) break;
			
		
			if (EXP1 < 300)//3
			{
				M1 -= 100;
			}
			else 
			{
				M1 -= 120;
			}
			EXP1 = ceil(EXP1 - 0.1 * EXP1); 
			if ( M1 <= 0 ) break;
		
		}
		while(0);
		
		
	}
	
	HP1 = ceil(HP1 - 0.17 * HP1); 
	EXP1 = ceil(EXP1 + 0.17* EXP1); if (EXP1 > 600) EXP1 = 600;
	if (M1 < 0) M1 = 0;
	
	float p2;

    int s2 = pow(round(sqrt(EXP1)),2); 	
   
    if ( EXP1 >= s2)
    {
    	p2 = 1;
	}
	else 
	{
		p2 = float((float(EXP1)/s2) + 80)/123;
	}
	
	
	//3 con duong 3
	
	int  arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
	float p3;
	if (E2 < 10) 
	{
		p3 = float(arr[E2])/100;	
	}
	else
	{	
		p3 = float(arr[(E2/10 + E2%10 )%10])/100;
	}

	if (p1 == 1 && p2 == 1 && p3 == 1)
	{
		EXP1 = ceil(EXP1 - 0.25 * EXP1);
	}
	else 
	{
		float result = (p1 + p2 +p3)/3;
		if (result < 0.5)
		{
			HP1 = ceil(HP1 - 0.15 * HP1);
			EXP1 = ceil(EXP1 + 0.15 * EXP1); 
		}
		else 
		{
			HP1 = ceil(HP1 - 0.1 * HP1) ;
			EXP1 = ceil(EXP1 + 0.2 * EXP1); 
		}
	}
	if (EXP1 > 600) EXP1 = 600;
	
	return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
	if (!(E3 >= 0 && E3 <= 99)) return -99;
	if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    if (EXP2 > 600) EXP2 = 600;
    if (EXP2 < 0) EXP2 = 0;
    if (HP2 > 666) HP2 = 666;
    if (HP2 < 0) HP2 = 0;
    
	int arr[10][10];
    int n = 0 ,m = 0;
    
    for (int i = 0; i < 10; i++)
    {
    	for (int j = 0; j < 10; j++)
    	{
    		arr[i][j] = 0;
		}
	}
	
	for (int i = 0; i < 10; i++)
    {
    	for (int j = 0; j < 10; j++)
    	{
    		arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
		}
	}
	
	for (int i = 0; i < 10; i++)
    {
    	for (int j = 0; j < 10; j++)
    	{
    		if (arr[i][j] > E3 * 2) n ++;
    		else if (arr[i][j] < -E3 ) m++;
		}
	}
	
	while ( n >= 10)
	{
		n = (n / 10 + n % 10);
	}
	while ( m >= 10)
	{
		m = (m / 10 + m % 10);
	}
	
	int a = n, b = m;
	int c = n, d = m;
	int x = n, y = m;
	int i = n, j = m;
	
	// Trai
	int temp = arr[n][m];
	while (n != 0 && m!= 0)
	{
		n--; m--;
		if (arr[n][m] > temp) temp = arr[n][m];
	}
	while (a != 9 && b!= 9)
	{
		a++; b++;
		if (arr[a][b] > temp) temp = arr[a][b];
	}
	
	//phai
	while (1)
	{
		if (c == 9 || d == 0) break;
		c++; d--;
		if (arr[c][d] > temp) temp = arr[c][d];
		
	}
	while (1)
	{
		if (x == 0 || y == 9) break;
		x--; y++;
		if (arr[x][y] > temp) temp = arr[x][y];
		
	}
	
	temp = abs(temp);
	if (abs(arr[i][j]) > temp) 
	{
		EXP1 = ceil(EXP1 - 0.12 * EXP1);
		EXP2 = ceil(EXP2 - 0.12 * EXP2);
		HP1 = ceil(HP1 - 0.1 * HP1);
		HP2 = ceil(HP2 - 0.1 * HP2);
	}
	else 
	{
		EXP1 = ceil(EXP1 + 0.12 * EXP1); if (EXP1 > 600) EXP1 = 600;
		EXP2 = ceil(EXP2 + 0.12 * EXP2); if (EXP2 > 600) EXP2 = 600;
		HP1 = ceil(HP1 + 0.1 * HP1); if (HP1 > 666) HP1 = 666;
		HP2 = ceil(HP2 + 0.1 * HP2);if (HP2 > 666) HP2 = 666;
	}
	
	if (abs(arr[i][j]) > temp) 
	{
		return arr[i][j];
	}
	else 
	{
		return temp;
	}
    
    
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // tim se
	string s1 = s; 
	string email1 = email;
	string se = email1 ;
    int a = se.length() - se.find('@') ;
	se.erase(se.find('@'), a);
	
	//yeu cau hop le
	if (s1.length() < 8) return -1;
	
	if ( s1.length() > 20) return -2;
	
	int b = s1.find(se);
	if (b >= 0 && b < s1.length()) return - ( 300 + b);
	
	for (int i = 0; i < s1.length() - 2; i++)
	{
		if (s1[i] == s1[i + 1] && s1[i] == s1[i + 2]) return -(400 + i);
	}
	
	int c = 0;
	for (int i = 0; i < s1.length() ; i++)
	{
		
		if (s1[i] == '@' ||  s1[i] == '#' || s1[i] == '%' || s1[i] == '$' || s1[i] == '!' ) c++;
		
	}
	if ( c == 0 ) return -5;
	
	for (int i = 0; i < s1.length(); i++)
	{
		int d = s1[i];
		if (!((d >= 48 && d <= 57) || d == 33 || d == 35 || d == 37 || d == 36 ||  (d >= 64 && d <= 90 ) || (d >= 97 && d <= 122 )))
		return i;
	}
	
	
	

    return -10;



}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) 
{
   	
   	
	string arr[num_pwds] ; 
	for (int i = 0; i < num_pwds; i++)
	{
		arr[i] = arr_pwds[i];
	}
	

    int arr2[num_pwds];
    for (int i = 0; i < num_pwds; i++)
    {
    	arr2[i] = 1;
	}
	
	
	
    for (int i = 0; i < num_pwds; i++)
    {
    	for (int j = 0; j < num_pwds; j++)
    	{
    		if (i != j) 
    		{
    			if (arr[i] == arr[j]) 
    			{
    				arr2[i] ++;
				}
			}
		}
	}
	
	

	int a = arr2[0];
	for (int i = 1; i < num_pwds ; i++)
	{
		if (a < arr2[i])
		{
			a = arr2[i];
		}
	}
	


	int arr3[num_pwds]; 
	for (int i = 0; i < num_pwds; i++)
    {
    	arr3[i] = 0;
	}
	
	int c = 0;
	for (int i = 0; i < num_pwds ; i++)
	{
		
		if (arr2[i] == a )
		{
			
			arr3[c] = i; 
			c++;
		}
	}
	
	

	

	int b = arr[arr3[0]].length(); 

	for (int i = 0; i < num_pwds  ; i++)
	{
		if (arr3[i] != 0)
		{
			if (b < arr[arr3[i]].length()) b = arr[arr3[i]].length();
		}
	}
	
	if (arr3[0] == 0)
	{
		if (arr[arr3[0]].length() == b) return 0;
	}
	
	for (int i = 0; i < num_pwds    ; i++)
	{
		if (arr3[i] != 0  )
		{
			if (arr[arr3[i]].length() == b) return arr3[i];
		}
	}
	return 0;

	
	

    
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
