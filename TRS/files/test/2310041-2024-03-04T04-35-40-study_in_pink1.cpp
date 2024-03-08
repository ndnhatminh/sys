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

//FIX HP
void fixHP(int & HP1, int & HP2)
{
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (HP2 < 0) HP2 = 0;
    if (HP2 > 666) HP2 = 666;
}

//FIX EXP
void fixEXP(int & EXP1, int & EXP2)
{
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 600) EXP2 = 600;
}

//FIX M
void fixM(int & M1, int & M2)
{
    if (M1 < 0) M1 = 0;
    if (M1 > 3000) M1 = 3000;
    if (M2 < 0) M2 = 0;
    if (M2 > 3000) M2 = 3000;
}

//FIND LEAST SQR
int find_least_sqr(int NUM)
{
    int NUMSQRT = sqrt(NUM*1.0);
    int A = NUMSQRT;
    int B = NUMSQRT + 1;
    int NUM_A = abs(NUM-A*A);
    int NUM_B = abs(NUM-B*B);
    if (NUM_A > NUM_B) return B*B;
    else return A*A;
}



// Task 1 
int firstMeet(int & EXP1, int & EXP2, int E1) 
{
    //CHECK EXP1, E1
    if (E1 < 0 || E1 > 99) return -99; 
    fixEXP(EXP1, EXP2);

    // TH1: E1 = [0;3]
    if (E1 >= 0 && E1 <= 3)  
    {
        //CAL EXP2
        if (E1 == 0) 
        {
            EXP2 += 29;
            fixEXP(EXP1, EXP2);
        }
        else if (E1 == 1)
        {
            EXP2 += 45;
            fixEXP(EXP1, EXP2);
        }
        else if (E1 == 2)
        {
            EXP2 += 75;
            fixEXP(EXP1, EXP2);
        }
        else if (E1 == 3)
        {
            EXP2 = EXP2 + 29 + 45 + 75;
            fixEXP(EXP1, EXP2);
        }
        //CAL EXP1
        int D = E1*3 + EXP1*7;
        if (D % 2 == 0) 
        {
        EXP1 += 0.999+D/200.0; 
        fixEXP(EXP1, EXP2);
        }
        else 
        {
        EXP1 -= floor(D/100.0); 
        fixEXP(EXP1, EXP2);
        }
    }

    // TH2: E1 = [4;99]
    else    
    {
        //CAL EXP2
        if (E1 >= 4 && E1 <= 19)
        {
            EXP2 += 0.999 + E1 / 4.0 + 19;
            fixEXP(EXP1, EXP2);
        }
        else if (E1 >= 20 && E1 <= 49)
        {
            EXP2 += 0.999 + E1 / 9.0 + 21;
            fixEXP(EXP1, EXP2);
        }
        else if (E1 >= 50 && E1 <= 65)
        {
            EXP2 += 0.999 + E1 / 16.0 + 17;
            fixEXP(EXP1, EXP2);
        }
        else if (E1 >= 66 && E1 <= 79)
        {
            EXP2 += 0.999 + E1 / 4.0 + 19;
            fixEXP(EXP1, EXP2);
            if (EXP2 > 200) 
            {
                EXP2 += 0.999 + E1 / 9.0 + 21;
                fixEXP(EXP1, EXP2);
            }
        }
        else if (E1 >= 80 && E1 <= 99)
        {
            EXP2 += 0.999 + E1 / 4.0 + 19;
            EXP2 += 0.999 + E1 / 9.0 + 21;
            fixEXP(EXP1, EXP2);
            if (EXP2 > 400)
            {
                EXP2 += 0.999 + E1 / 16.0 + 17;
                EXP2 += 0.999 + 0.15*EXP2;
                fixEXP(EXP1, EXP2);
            }
        }
        //CAL EXP1
        EXP1 -= E1;
        fixEXP(EXP1, EXP2);
    }
    return EXP1 + EXP2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) 
{
	int X=0;
    //CHECK HP, EXP, M, E
    if (E2 < 0 || E2 > 99) return -99; 
    fixHP(HP1, X);
    fixEXP(EXP1, X);
    fixM(M1,X);

    //ROAD 1
    float P1;
    if (find_least_sqr(EXP1) <= EXP1) P1 = 1;
    else P1 = ((1.0*EXP1/find_least_sqr(EXP1)) + 80 )/123;


    //ROAD 2 
    int K;
    int M0 = ceil(0.5*M1);
    int M_USE = 0;
    if (E2 % 2 == 0) K = 0; else K = 1;
    do {
        if ((K == 1 && M_USE > M0) || (M1 == 0)) break; //CHECK DIEU KIEN
        //EVENT 1
        if (HP1 < 200) 
        {
            HP1 += 0.3*HP1 + 0.999;
            M1 -= 150;
            M_USE += 150;
            fixHP(HP1, X);
            fixM(M1, X);
        }
        else 
        {
            HP1 += 0.1*HP1 + 0.999;
            M1 -= 70;
            M_USE += 70;
            fixHP(HP1, X);
            fixM(M1, X);
        }
        if ((K == 1 && M_USE > M0) || (M1 == 0)) break; //CHECK DIEU KIEN
        //EVENT 2
        if (EXP1 < 400) 
        {
            M1 -= 200;
            M_USE += 200;
            fixM(M1, X);
        } 
        else 
        {
            M1 -= 120;
            M_USE += 120;
            fixM(M1, X);
        }
        EXP1 += 0.999 + 0.13*EXP1;
        fixEXP(EXP1, X);
        if ((K == 1 && M_USE > M0) || (M1 == 0)) break; //CHECK DIEU KIEN
        ////EVENT 3
        if (EXP1 < 300)
        {
            M1 -= 100;
            M_USE += 100;
            EXP1 -= floor(0.1*EXP1);
            fixM(M1, X);
            fixEXP(EXP1, X);
        }
        else 
        {
            M1 -= 120;
            M_USE += 120;
            EXP1 -= floor(0.1*EXP1);
            fixM(M1, X);
            fixEXP(EXP1, X);
        }
        if ((K == 1 && M_USE > M0) || (M1 == 0)) break; //CHECK DIEU KIEN
    }
    while (K); //NEU E2 LA SO CHAN THI DUNG LAI

    //CAP NHAT HP EXP SAU KHI HET ROAD 2
    EXP1 += 0.17*EXP1 + 0.999;
    fixEXP(EXP1, X);
    HP1 -= floor(0.17*HP1);
    fixHP(HP1, X);
	
    //TINH XAC SUAT P2
    float P2;
    if (find_least_sqr(EXP1) <= EXP1) P2 = 1;
    else P2 = ( (1.0*EXP1/find_least_sqr(EXP1)) + 80 )/123;
 

    //ROAD 3
    int i;
    float P_ARRAY [10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2/10 == 0) i = E2; 
    else i = E2/10 + E2%10;
    if (i/10 != 0) i = i%10;
    float P3;
    P3 = 0.01*P_ARRAY[i];
    //THE LAST CAL
    
    float P = (P1 + P2 + P3)/3.0;
    if (P == 1) 
    {
        EXP1 -= floor(0.25*EXP1);
        fixEXP(EXP1, X);
    }
    else if (P < 0.5) 
    {
        HP1 -= floor(0.15*HP1);
        EXP1 += 0.999 + 0.15*EXP1;
        fixHP(HP1, X);
        fixEXP(EXP1, X);
    }
    else
    {
        HP1 -= floor(0.1*HP1);
        EXP1 += 0.999 + 0.2*EXP1;
        fixHP(HP1, X);
        fixEXP(EXP1, X);
    }
    return HP1 + EXP1 + M1;
}

//Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) 
{
    //KIEM TRA KHOI DAU
	if (E3 < 0 || E3 > 99) return -99; 
    fixHP(HP1, HP2);
    fixEXP(EXP1, EXP2);
    
    int taxi[10][10];
	int i = 0, j = 0;
	for (int a = 0; a < 10; a++)
	{
		for (int b = 0; b < 10; b++)
		{
			taxi[a][b]=((E3*b)+(a*2))*(a-b);
			if (taxi[a][b] > E3*2)
			{
				i++;
			}
			else if (taxi[a][b] < -E3)
			{
				j++;
			}
		}	
	}
	while (i >= 10 || j >= 10)
	{
		i = i/10 + i%10;
		j = j/10 + j%10;
	}
	int max = taxi[i][j];
	int itg = i, jtg= j;
	while (i >= 0 && i <= 9 && j >= 0 && j <= 9)
	{
		if(taxi[i][j] > max) 
		{
			max = taxi[i][j];
		}
		i++;
		j--;
	}
	i = itg; j = jtg;
	while (i >= 0 && i <= 9 && j >= 0 && j <= 9)
	{
		if(taxi[i][j]> max) 
		{
			max = taxi[i][j];
		}
		i--;
		j++;
	}
	i = itg; j = jtg;
	while (i >= 0 && i <= 9 && j >= 0 && j <= 9)
	{
		if(taxi[i][j]> max) 
		{
			max = taxi[i][j];
		}
		i++;
		j++;
	}
	i = itg; j = jtg;
	while (i >= 0 && i <= 9 && j >= 0 && j <= 9)
	{
		if(taxi[i][j]> max) 
		{
			max = taxi[i][j];
		}
		i--;
		j--;
	}
	i = itg; j = jtg;
	if (max >= abs(taxi[i][j])) 
	{
		HP1 += 0.999 + 0.1*HP1;
		fixHP(HP1, HP2);
		HP2 += 0.999 + 0.1*HP2;
		fixHP(HP1, HP2);
		EXP1 += 0.999 + 0.12*EXP1;
		fixEXP(EXP1, EXP2);
		EXP2 += 0.999 + 0.12*EXP2;
		fixEXP(EXP1, EXP2);
	}
	else 
	{
		HP1 -= floor(0.1*HP1);
		fixHP(HP1, HP2);
		HP2 -= floor(0.1*HP2);
		fixHP(HP1, HP2);
		EXP1 -= floor(0.12*EXP1);
		fixEXP(EXP1, EXP2);
		EXP2 -= floor(0.12*EXP2);
		fixEXP(EXP1, EXP2);
	}
	if (abs(taxi[i][j]) <= max) return max;
	else return taxi[i][j];
}

// Task 4
//Condition 1: Ki tu thuong
	bool normal_char(char c) 
	{
	    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
	}
	
//Condition 1&5: Ki tu dac biet
	bool special_char(char c) 
	{
	    return (c == '@') || (c == '#') || (c == '%') || (c == '$') || (c == '!');
	}
	
 //Conditionl 2: Do dai toi thieu - toi da
	int check_length (const char * s)
	{
		if (strlen(s) < 8) return -1;
		else if (strlen(s) > 20) return -2;
		else return 1;
	}
		
//Condition 3: Chua chuoi se?
    int include_se (const char * s, const char * email)
	{
		int i = 0, r = 0, k = 0;
	    for (i = 0; i < strlen(email); i++) 
		{
	       if (email[i] == '@') break;
	    }
	
	    if (strlen(s) >= i) 
		{
	        for (int j = 0; j <= strlen(s) - i; j++) 
			{
	            r = 1;
	            for (k = j; k < i + j; k++) 
				{
	                int m = k - j;
	                if (s[k] != email[m]) 
					{
	                    r = 0;
	                    break;
	                }
	            }
	            if (r == 1) break; 
	        }
	    }
	    if (r == 0) return -1;
	    else return k-i;
	}
	
//Condition 4: Nhieu hon 2 ki tu lien tiep giong nhau
    int same (const char * s)
	{
		for (int i = 0; i < strlen (s) - 1; i++)
		{
			if ((s[i] == s[i+1]) && (s[i+1] == s[i+2])) {return i; break;}
    	}
		return -1;
	}
//Main task 4
int checkPassword(const char * s, const char * email) 
{
	if (check_length(s) != 1) return check_length(s);
	if (include_se(s, email) != -1) return -(300+include_se(s,email));
	if (same(s) != -1) return -(400+same(s));
	int count = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (special_char(s[i]) == 1) 
		{
			++count;
			break;
		}
	}
	if (count == 0) return -5;
	count = 0;
	for (int j = 0; j < strlen(s); j++)
	{
		if ((normal_char(s[j]) == 0) && (special_char(s[j]) == 0))
		{
			return count;
		}
        count ++;
	}
	return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    int appear[num_pwds]; // So lan xuat hien
    int max_appear = 0;
    int pwd_length[num_pwds]; // Do dai password
    int max_length = 0;
    int correct_password_index = -1; // Luu vi tri dung cua mat khau
    
    // Tinh so lan xuat hien va do dai cua moi mat khau
    for (int i = 0; i < num_pwds; i++)
    {
        const char * current_pwd = arr_pwds[i];
        pwd_length[i] = strlen(current_pwd); // Do dai password tuong ung
        int d = 0;
        for (int j = 0; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[j], current_pwd) == 0) d++;
        }
        appear[i] = d; //So lan xuat hien tuong ung
    }

    // Tim so lan xuat hien nhieu nhat
    for (int k = 0; k < num_pwds; k++)
    {
        if (appear[k] > max_appear) 
        {
            max_appear = appear[k];
        }
    }

    // Tim do dai password lon nhat ung voi so lan xuat hien nhieu nhat
    for (int m = 0; m < num_pwds; m++)
    {
        if (appear[m] == max_appear) 
        {
            if (pwd_length[m] > max_length) {
                max_length = pwd_length[m];
            }
        }
    }
    
    // Tim vi tri cua mat khau dung
    for (int n = 0; n < num_pwds; n++)
    {
        if (appear[n] == max_appear && pwd_length[n] == max_length) 
        {
            correct_password_index = n;
            break; 
        }
    }
    
    return correct_password_index;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
