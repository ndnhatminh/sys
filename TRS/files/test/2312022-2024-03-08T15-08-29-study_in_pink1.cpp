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

//Ham gioi han HP
int rangeHP(int & HP)
{
	if (HP < 0) HP = 0;
	if (HP > 666) HP = 666;
	return HP; 
}

//Ham gioi han EXP
int rangeEXP(int & EXP)
{
	if (EXP < 0) EXP = 0;
	if (EXP > 600) EXP = 600;
	return EXP; 
}

//Ham gioi han M
int rangeM(int & M)
{
	if (M < 0) M = 0;
	if (M > 3000) M = 3000;
	return M; 
} 

//TASK 1 
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ((e1<0)||(e1>99)) return (-99); 
    if (e1 < 4) 
    {
     switch(e1)
       {
        case 0:
          exp2 = exp2 + 29;
          break;
        case 1:
          exp2 = exp2 + 45;
          break;
        case 2:
          exp2 = exp2 + 75;
          break;
        case 3:
          exp2 = exp2 + 29 + 45 + 75;
          break;
       }
     exp2 = rangeEXP(exp2); 
     int D;
     D = e1*3 + exp1*7;
     if (D%2==0) exp1 = exp1 + D/200.0 + 0.999;
     else exp1 = exp1 - D/100.0 + 0.999; 
    }
    else 
    {
     if (e1 < 20) exp2 = exp2 + e1/4.0 + 19 + 0.999;
     else if (e1 < 50) exp2 = exp2 + e1/9.0 + 21 + 0.999;
     else if (e1 < 66) exp2 = exp2 + e1/16.0 + 17 + 0.999;
     else if (e1 < 80) 
        {
         exp2 = exp2 + e1/4.0 + 19 + 0.999;
         exp2 = rangeEXP(exp2); 
         if (exp2 > 200) exp2 = exp2 + e1/9.0 + 21 + 0.999;
        }    
     else 
        {
         exp2 = exp2 + e1/4.0 + 19 + 0.999;
         exp2 = rangeEXP(exp2);
         exp2 = exp2 + e1/9.0 + 21 + 0.999;
         exp2 = rangeEXP(exp2);
         if (exp2 > 400) 
          {
           exp2 = exp2 + e1/16.0 + 17 + 0.999;
           exp2 = rangeEXP(exp2);
           exp2 = exp2*1.15 + 0.999;
          }
        }
     exp2 = rangeEXP(exp2);
     exp1 = exp1 - e1;
    }
    exp1 = rangeEXP(exp1);
    return exp1 + exp2;
}

// Task 2
int square_number(int EXP1) {
   int square_number = round(sqrt(EXP1))*round(sqrt(EXP1));
   return square_number;
}

void event1(int & HP1, int & M1) {
   if (HP1 < 200)
    {
     HP1 = HP1*1.3 + 0.999;
     M1 = M1 - 150;
    }
    else 
    {
     HP1 = HP1*1.1 + 0.999;
     M1 = M1 - 70;
    }
    HP1 = rangeHP(HP1);
	M1 = rangeM(M1); 
}

void event2(int & EXP1, int & M1) {
   if (EXP1 < 400) M1 = M1 -200;
   else M1 = M1 - 120;
   EXP1 = EXP1*1.13+0.999;
   M1 = rangeM(M1);
   EXP1 = rangeEXP(EXP1); 
}

void event3(int & EXP1, int & M1) {
   if (EXP1 < 300) M1 = M1 - 100;
   else M1 = M1 - 120;
   EXP1 = EXP1*0.9+0.999;
   M1 = rangeM(M1);
   EXP1 = rangeEXP(EXP1);
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if ((E2<0)||(E2>99)) return (-99);
    float P1, P2, P3, P; 
//Con duong 01
    int S1 = square_number(EXP1);
    if (EXP1 >= S1) P1 = 1;
    else P1 = (EXP1*1.0/S1 + 80)/123;
//Con duong 02
    int So_tien_ban_dau = M1;
    if (E2%2==1) 
    	for (;;)  
        {
        event1(HP1, M1);
        if ((So_tien_ban_dau - M1) > So_tien_ban_dau*0.5) break;
        event2(EXP1, M1);
        if ((So_tien_ban_dau - M1) > So_tien_ban_dau*0.5) break;
        event3(EXP1, M1);
        if ((So_tien_ban_dau - M1) > So_tien_ban_dau*0.5) break;
        }
	else 
		for (;;)
		{
		event1(HP1, M1);
        if (M1 == 0) break; 
        event2(EXP1, M1);
        if (M1 == 0) break;
        event3(EXP1, M1);
        break;
		} 
    HP1 = HP1*0.83+0.999;
    HP1 = rangeHP(HP1); 
    EXP1 = EXP1*1.17+0.999;
    EXP1 = rangeEXP(EXP1);
    S1 = square_number(EXP1);
    if (EXP1 >= S1) P2 = 1;
    else P2 = (EXP1*1.0/S1 + 80)/123;
//Con duong 03
    int Xac_suat[10] = {32,47,28,79,100,50,22,83,64,11};
    int i;
    if (E2/10 == 0) i = E2;
    else i = (E2/10 + E2%10)%10;
    P3 = Xac_suat[i]*1.0/100;
//Final
    if ((P1 == 1)&(P2 == 1)&(P3 == 1)) EXP1 = EXP1*0.75+0.999;
    else 
    {
     P = (P1 + P2 + P3)/3;
     if (P < 0.5) 
     {
      HP1 = HP1*0.85+0.999;
      EXP1 = EXP1*1.15+0.999;
     }
     else
     {
      HP1 = HP1*0.9+0.999;
      EXP1 = EXP1*1.2+0.999;
     }
    }
    HP1 = rangeHP(HP1);
	EXP1 = rangeEXP(EXP1); 
    return HP1 + EXP1 + M1;
}

// Task 3
int largest(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) 
		max = arr[i];
   return max;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ((E3<0)||(E3>99)) return (-99); 
    int mapTaxi[10][10] = {0};
    int mapSherLock[10][10]; 
    int num_arr,arr[29],k,i_1,j_1;
	int m = 0;
	int n = 0; 
    for (int i=0; i<10; i++)
	{
		for (int j=0; j<10; j++)
		{
			mapTaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j); 
			if (mapTaxi[i][j] > (E3*2)) m++; 
			if (mapTaxi[i][j] < (-E3)) n++; 
		}
	} 
	while ((m>=10)||(n>=10)) 
	{
		m = m/10 + m%10; 
		n = n/10 + n%10; 
	} 
	for ( int p=0; p<10; p++)
		for ( int q=0; q<10; q++)
		{
			k = 1; 
			i_1 = p-1;
			j_1 = q-1; 
			arr[0] = mapTaxi[p][q];
			while ((j_1>=0)&&(i_1>=0)) 
		{
			arr[k] = mapTaxi[i_1][j_1];
			j_1--;
			i_1--; 
			k++; 
		}
			i_1 = p+1;
			j_1 = q+1; 
			while ((j_1<=9)&&(i_1<=9)) 
		{ 
			arr[k] = mapTaxi[i_1][j_1];
			j_1++;
			i_1++; 
			k++; 
		}
			i_1 = p+1;
			j_1 = q-1; 
			while ((j_1>=0)&&(i_1<=9))  
		{ 
			arr[k] = mapTaxi[i_1][j_1];
			j_1--;
			i_1++; 
			k++; 
		}
			i_1 = p-1;
			j_1 = q+1; 
			while ((j_1<=9)&&(i_1>=0))  
		{ 
			arr[k] = mapTaxi[i_1][j_1];
			j_1++;
			i_1--; 
			k++; 
		}
		    for (num_arr = k; num_arr < 29; num_arr++) arr[num_arr] = mapTaxi[p][q];
			mapSherLock[p][q] = abs(largest(arr, 29));
		}	 
	int max; 
	if (abs(mapTaxi[m][n]) > mapSherLock[m][n]) 
	{
		EXP1 = EXP1*0.88+0.999;
		EXP2 = EXP2*0.88+0.999;
		HP1 = HP1*0.9+0.999;
		HP2 = HP2*0.9+0.999;
	    max =  mapTaxi[m][n];
	}
	else  
	{
		EXP1 = EXP1*1.12+0.999;
		EXP2 = EXP2*1.12+0.999;
		HP1 = HP1*1.1+0.999;
		HP2 = HP2*1.1+0.999;
		max =  mapSherLock[m][n];
	}
	EXP1 = rangeEXP(EXP1);
	EXP2 = rangeEXP(EXP2);
	HP1 = rangeHP(HP1); 
	HP2 = rangeHP(HP2); 
	return max; 
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string copy_s = string(s);
	string copy_email = string(email); 
    int len_se; 
    for (int idx1 = 0; idx1 < strlen(email); idx1++) 
	    if (int(email[idx1]) == 64) len_se = idx1;   
    string se = copy_email.substr(0,len_se);  
	if (strlen(s) < 8) return -1;
	if (strlen(s) > 20) return -2;   
	string t; 
    if (strlen(s) >= len_se)
	for (int sei=0; sei < (strlen(s) - len_se +1 ); sei++) 
	{
		t = copy_s.substr(sei,len_se);  
		if (se == t) return (-(300 + sei));
	}  
	for (int sci=0; sci < strlen(s) ; sci++)
		if ((int(s[sci])==int(s[sci+1])) && (int(s[sci+2])==int(s[sci+1])))
		    return (-(400+sci)); 
	for (int idx2=0; idx2 < strlen(s); idx2++) 
	{
		if ((int(s[idx2])==33)||(int(s[idx2])==35)||(int(s[idx2])==36)||(int(s[idx2])==37)||(int(s[idx2])==64)) break; 
		if (idx2 == (strlen(s)-1)) return (-5); 
	}
	for (int idx3=0; idx3 < strlen(s); idx3++) 
		if (!(
		(int(s[idx3])==33)
		||(int(s[idx3])==35)
		||(int(s[idx3])==36)
		||(int(s[idx3])==37)
		||(int(s[idx3])==64)
		||((int(s[idx3])>47)&&(int(s[idx3])<58))
		||((int(s[idx3])>64)&&(int(s[idx3])<91))
		||((int(s[idx3])>96)&&(int(s[idx3])<123))))
		    return idx3; 
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string copyarr_pwds[num_pwds];
	for (int idx1 = 0; idx1 < num_pwds; idx1++)  copyarr_pwds[idx1] = arr_pwds[idx1]; 
    int ArrayCount[num_pwds];
    for (int i = 0; i < num_pwds; i++)
	{
		ArrayCount[i] = 1;
		for (int j = (i+1); j<num_pwds; j++)
			if (copyarr_pwds[i]==copyarr_pwds[j])  
				ArrayCount[i] = ++ArrayCount[i]; 
	} 
    int max = largest(ArrayCount,num_pwds); 
    int length = 0, idx3 = 0; 
    for (int idx2 = 0; idx2 < num_pwds; idx2++)
    	if (ArrayCount[idx2] == max) 
    		if (length < copyarr_pwds[idx2].size())
			{
    			length =  copyarr_pwds[idx2].size();
    			idx3 = idx2; 
			}
	return idx3;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
