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
void KiemtraDK1 (int & exp1, int & exp2)
{
	if( exp1 <0 )	exp1 = 0;
	if( exp1 >600 ) exp1 = 600;
	if( exp2 <0 )	exp2 = 0;
	if( exp2 >600 ) exp2 = 600;
}
int firstMeet(int & exp1, int & exp2, int e1) 
{
	if( e1 < 0 || e1 > 99)
		return -99 ;
	else if( e1 >= 0 && e1 <=3 )
	{
	    if( e1 == 0 )
	    	exp2 += 29;
	    else 
	    	if( e1 == 1)
	    		exp2 += 45;
	    	else
	    		if( e1 == 2 )
	    			exp2 += 75;
	    		else
	    			exp2 += 29 + 45 + 75;
	    if( exp2 > 600 )	exp2 = 600;
    	long long D = e1*3 + exp1*7 ;
    	if( D%2 == 0 ) 
    		exp1 = ceil(exp1 + D/200.0f) ; 
    	else
    		exp1 = ceil(exp1 - D/100.0f) ;
    	if( exp1 < 0)	exp1 = 0;
    	if( exp1 > 600)	exp1 = 600;
	}
	else
	{
		if( e1 >= 4 && e1 <= 19 )
			exp2 = ceil(exp2 + (e1/4.0f+19.0f));
		else
			if( e1 >= 20 && e1 <= 49 )
				exp2 = ceil((float)exp2 + (e1/9.0f+21.0f)) ;
			else
				if( e1 >= 50 && e1 <= 65 )
					exp2 = ceil(exp2 + (e1/16.0f+17.0f)) ;
				else
					if( e1 >= 66 && e1 <= 79 )
					{
						exp2 = ceil(exp2 + (e1/4.0f+19.0f)) ;
						if( exp2 > 200 )
							exp2 = ceil(exp2 + (e1/9.0f+21.0f)) ;
					}
					else
					{
						exp2 = ceil(exp2 + (e1/4.0f+19.0f)) ;
						exp2 = ceil(exp2 + (e1/9.0f+21.0f)) ;
						if( exp2 > 400)
						{
							exp2 = ceil(exp2 + (e1/16.0f+17.0f)) ;
							exp2 = ceil(1.15f*exp2) ;
						}
						if( exp2 > 600)
							exp2 = 600;
					}
		exp1 -= e1;
		if( exp1 < 0 ) exp1 = 0;
	}
	KiemtraDK1 (exp1, exp2) ; 
		return exp1 + exp2;
}
// Task 2
void KiemtraDK2 (int & HP1, int & EXP1, int & M1)
{
	if( EXP1 < 0 )	EXP1 = 0;
	if( EXP1 > 600 ) EXP1 = 600;
	
	if( HP1 < 0) HP1 = 0 ;
	if( HP1 > 666) HP1 = 666 ;

	if( M1 < 0) M1 = 0 ; 
	if( M1 > 3000) M1 = 3000 ; 
}
int findNearestSquare(int n)
{
    int m = (sqrt(n));
    int num1 = m * m;
    int num2 = (m + 1) * (m + 1);
    if (abs(num1 - n) <= abs(num2 - n))
    {
        return num1;
    }
    return num2;
}
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
	if (E2 < 0 || E2 > 99)
		return -99 ;
else
{
//Way1
    int P1;
    int S1 = findNearestSquare(EXP1);
    if (EXP1 >= S1) P1 = 100;
    else P1 = ceil(100.0f * (EXP1/ S1 + 80.0f) / 123.0f);
//Way2
	int spent = 0 ; 
	int check_M1 = M1/2 ; 
	if(E2 % 2 == 1)
	{
		do{
			if( HP1 < 200 )
				{
					HP1 = ceil(HP1 * 1.3f) ;
					M1 -= 150 ;
					spent += 150 ;
					KiemtraDK2 (HP1, EXP1, M1) ;
						if(spent > check_M1)
							break ;
				}
				else
					{
						HP1 = ceil(1.1f * HP1) ;
						M1 -= 70 ;
						spent += 70 ;
						KiemtraDK2 (HP1, EXP1, M1) ;
						if(spent > check_M1)
							break ;
					} 
			if( EXP1 < 400 )
				{
					M1 -= 200 ;
					spent += 200 ;
					EXP1 = ceil(1.13f * EXP1) ;
					KiemtraDK2 (HP1, EXP1, M1) ;
						if(spent > check_M1)
							break ;
				}
				else
					{
						M1 -= 120 ;
						spent += 120 ;
						EXP1 = ceil(1.13f * EXP1) ;
						KiemtraDK2 (HP1, EXP1, M1) ;
						if(spent > check_M1)
							break ; 
					}
			if( EXP1 < 300 )
				{
					M1 -= 100 ; 
					spent += 100 ;
					EXP1 = ceil(0.9f * (EXP1)) ;
					KiemtraDK2 (HP1, EXP1, M1) ;
						if(spent > check_M1)
							break ;
				}
				else
					{
						M1 -= 120 ;
						spent += 120 ;
						EXP1 = ceil(0.9f * (EXP1)) ;
						KiemtraDK2 (HP1, EXP1, M1) ;
						if(spent > check_M1)
							break ;
					} 
		}while(spent < check_M1) ; 
	}
		else if(E2 % 2 == 0)
		{
			int time = 1 ; 
			while(M1 >= 0 && time == 1){
				time -- ; 
				if( HP1 < 200 )
					{
						HP1 = ceil(HP1 * 1.3f) ;
						M1 -= 150 ;
						spent += 150 ;
						KiemtraDK2 (HP1, EXP1, M1) ;
						if(M1 <= 0)
							break ; 
					}
					else
						{
							HP1 = ceil(1.1f * HP1) ; 
							M1 -= 70, spent += 70 ;
							KiemtraDK2 (HP1, EXP1, M1) ;
							if(M1 <= 0)
								break ;
						}
				if( EXP1 < 400 )
					{
						M1 -= 200 ;
						spent += 200 ;
						EXP1 = ceil(1.13f * EXP1) ;
						KiemtraDK2 (HP1, EXP1, M1) ;
						if(M1 <= 0)
							break ;
					}
						else
						{
							M1 -= 120 ; 
							spent += 120 ;
							EXP1 = ceil(1.13f * EXP1) ; 
							KiemtraDK2 (HP1, EXP1, M1) ;
							if(M1 <= 0)
								break ;
						}
				if( EXP1 < 300 )
					{
						M1 -= 100 ; 
						spent += 100 ;
						EXP1 = ceil(0.9f * (EXP1)) ;
						KiemtraDK2 (HP1, EXP1, M1) ;
						if(M1 <= 0)
							break ;
					}
					else
						{
							M1 -= 120 ;
							spent += 120 ;
							EXP1 = ceil(0.9f * (EXP1)) ;
							KiemtraDK2 (HP1, EXP1, M1) ;
							if(M1 <= 0)
								break ;
						}
			}	
		}
	HP1 = ceil(0.83f * (HP1)) ;
	EXP1 = ceil(1.17f * (EXP1)) ;
	KiemtraDK2 (HP1, EXP1, M1) ;	
	int P2;
    S1 = findNearestSquare(EXP1);
    if (EXP1 >= S1) P2 = 100;
    else P2 = ceil(100.0f * (EXP1 / S1 + 80) / 123);
//Way3
	int P3 ; 
	int i ; 
	int p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11} ;    
	if (E2 - 10 < 0 ) 
	{
		i = E2 ; 
		P3 = p[i] ;
	} 
		else i = E2/10 + E2%10 ;
	if (i < 10) P3 = p[i] ; 
		else P3 = p[i%10] ; 
	KiemtraDK2 (HP1, EXP1, M1) ; 
//Final
	int P = ceil(1.0f*(P1 + P2 + P3)/3);
	if (P1 == P2 && P2 == P3) EXP1 = ceil(0.75f * (EXP1)) ; 
		else
			if (P < 50) 
			{
				HP1 = ceil(HP1 - 0.15f * (HP1)) ; 
				EXP1 = ceil(EXP1 + 0.15f * (EXP1)) ; 
			}
				else 
				{
					HP1 = ceil(HP1 - 0.10f * (HP1)) , 
					EXP1 = ceil(EXP1 + (EXP1) * 0.2f ) ;
				}

	KiemtraDK2 (HP1, EXP1, M1) ;  
    
return HP1 + EXP1 + M1 ;
}
}
// Task 3
void KiemtraDK3 (int & HP1, int & EXP1, int & HP2, int & EXP2)
{
	if( EXP1 <0 )	EXP1 = 0;
	if( EXP1 >600 ) EXP1 = 600;
	if( EXP2 <0 )	EXP2 = 0;
	if( EXP2 >600 ) EXP2 = 600;
	
	if( HP1 <0) HP1 = 0 ;
	if( HP1 >666) HP1 = 666 ;
	if( HP2 <0) HP1 = 0 ;
	if( HP1 >666) HP1 = 666 ;
}
int maxcheo(int map[10][10], int & duong, int & am)
{
    int Max = map[duong][am] ; 
    for (int i=0; i < 10; i++)
    {
        for(int j=0; j < 10; j++) 
        {
		
            if(i != duong && j != am )
            {
                if (abs(i-duong) == abs(j-am))
                {
                Max = max(Max, map[i][j]) ;
                }
            }
        }
    }
return Max ; 
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
//MAP
	if (E3 < 0 || E3 > 99)
		return -99 ;
    int map[10][10] , duong = 0, am = 0, PointTaxi = 0, PointSir = 0, rturn ; 
    for (int m = 0; m < 10; m ++)
    {
    	for (int n = 0; n < 10; n ++)
    	{
    		map[m][n] = ((E3*n) + 2*m)*(m - n) ; 
		}
	}
	for (int m = 0; m < 10; m ++)
    {
    	for (int n = 0; n < 10; n ++)
    	{
    		if (map[m][n] > 0 && map[m][n] > E3*2) duong += 1 ;
    		if (map[m][n] < 0 && map[m][n] < -E3) am += 1 ; 
		}
	}
	while(duong / 10 != 0) 
	{
		duong = duong/10 + duong%10 ;
	} 
	while(am / 10 != 0)
	{
		am = am/10 + am%10 ; 
	}
	
	PointSir = maxcheo( map, duong, am) ;
	PointTaxi = map[duong][am] ; 

	if (abs(PointTaxi) > PointSir) 
	{
		EXP1 = ceil(EXP1*0.88f) ; 
		EXP2 = ceil(EXP2*0.88f) ; 
		HP1 = ceil(HP1*0.9f) ; 
		HP2 = ceil(HP2*0.9f) ; 
		rturn = PointTaxi ; 
	}
	else 
	{
		EXP1 = ceil(EXP1*1.12f) ; 
		EXP2 = ceil(EXP2*1.12f) ; 
		HP1 = ceil(HP1*1.1f) ; 
		HP2 = ceil(HP2*1.1f) ;
		rturn = PointSir ; 
	}
KiemtraDK3 ( HP1, EXP1, HP2, EXP2) ; 
    return rturn;
}
// Task 4
int checkPassword(const char * s, const char * email) 
{
	int SElength = 0, Slength = strlen(s) ;
    while (email[SElength] != '@' && SElength < strlen(email)) 
	{
        SElength ++ ;
    }
    char SE[SElength + 1] ;
    strncpy(SE, email, SElength) ;
    SE[SElength] = '\0' ;
	//KT do dai mat khau
	if (Slength < 8)
		return -1;
		else 	
			if (Slength > 20)
				return -2 ;
	//chua chuoi se
	const char* chuoiSE = strstr(s, SE) ;
    if (chuoiSE != NULL) 
    {
    	return -(300 + (chuoiSE - s)) ;
	}
	//chua nhieu hon 2 ky tu lien tiep va giong nhau
	for (int i = 0; i < strlen(s) - 2; ++ i) 
	{
		if (s[i] == s[i + 1] && s[i] == s[i + 2])
		return -(400 + i) ;
	} 
	//Ky tu dac biet
	bool KTDB = false;
    for (int i = 0; i < strlen(s); i ++) 
	{
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') 
    	{
            KTDB = true ;
            break ;
        }
    }
    if (!KTDB) 
        return -5 ;
    //DK khac
    for (int i = 0; i < strlen(s); i ++) 
	{
        if ( !( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') )
            return i;
    }
    //if OK
    return -10 ;

    return -99;
}
// Task 5
int DodaiChuoi(const char* str) 
{
    int Dodai = 0 ;
    while (str[Dodai] != '\0') 
	{
        Dodai += 1 ;
    }
    return Dodai ;
}
int findCorrectPassword(const char * arr_pwds[], int num_pwds) 
{
	int times, length ;
	int maxTimes = 0, maxLength = 0 ; 
	string ans = "" ;

	//dem so lan XH & luu do dai cua mk va so Xh nhieu nhat & dai nhat
	for (int i = 0; i < num_pwds; i ++) 
	{
        times = 0;
        length = DodaiChuoi(arr_pwds[i]);
        for (int j = i; j < num_pwds; ++j) 
		{
            if (strcmp(arr_pwds[j], arr_pwds[i]) == 0) 
				times ++ ;
        }
		if (times > maxTimes || (times == maxTimes && length > maxLength)) 
		{
            maxTimes = times ;
            maxLength = length ;
            ans = arr_pwds[i] ;
        }
	}
	//vi tri Xh dau tien cua mk chinh xac
	for (int i = 0; i < num_pwds; ++i) 
	{
        if (arr_pwds[i] == ans) 
            return i;
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
