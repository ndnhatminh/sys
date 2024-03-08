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
int roundup(float x)
{
	if ( (x - (int)x) != 0 ) return ((int)x + 1) ;
	else return (int)x ;
}
int checkHP(int HP) {
	if ( HP > 666) return 666 ;
	else if ( HP < 0) return 0 ;
	else return HP ;
}

int checkEXP(int EXP){
	if ( EXP > 600) return 600 ;
	else if (EXP < 0) return 0 ; 
	else return EXP ;
}
int checkM ( int M) {
	if ( M > 3000) return 3000 ; 
	else if ( M < 0 ) return 0 ;
	else return M ;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ( e1 <= 99 && e1 >= 0  ){
    
	    if ( e1 >=0 && e1 <= 3) 
		{
	    	if(e1==0) exp2 = checkEXP(exp2 + 29) ;
	    	else if (e1==1) exp2 = checkEXP( exp2 + 45) ; 
	    	else if (e1 ==2 ) exp2 = checkEXP(exp2 + 75) ;
	    	else exp2 = checkEXP(exp2 + 29 + 45 + 75) ;
	    	int D ;
	    	D = e1 *3 + exp1*7 ; 
	    	if(D%2==0)
			{
	    		exp1 = checkEXP(roundup( exp1 + D/200.0) ) ; 
	   		}
	   		else 
			{
	    		exp1 = checkEXP(roundup (exp1 - D/100.0) )  ;
	    	}
	     
	    
	    }
	    else if ( e1 >=4 && e1 <=99) 
	    {
	    	if( e1 >=4 && e1<=19)
	    	{
	    		exp2 =  checkEXP(roundup(exp2 + e1/4.0 + 19)) ;
	    	}
	    	if(e1>=20 && e1 <=49) 
	    	{
	    		exp2 = checkEXP(roundup(exp2 + e1/9.0 + 21)) ;
	    	}
	    	if ( e1 >=50 && e1 <=65)
	    	{
	    		exp2 = checkEXP(roundup(exp2 + e1/16.0 + 17)) ;
	    	}
	    	if (e1 >=66 && e1 <=79)
	    	{
	    		exp2 = checkEXP(roundup(exp2 + e1/4.0 + 19)) ;
	    		if ( exp2 >200) 
	    		{
	    			exp2 = checkEXP(roundup( exp2 + e1/9.0 +21)) ;   				
	    		}
	    	}
	    	if( e1 >= 80 && e1 <= 99)
	    	{
	    		exp2 = checkEXP(roundup(exp2 + e1/4.0 + 19));
	    		exp2 = checkEXP(roundup(exp2 + e1/9.0 + 21)) ;
	    		if (exp2 > 400)
	    		{
	    			exp2 = checkEXP(roundup(exp2 + e1/16.0 + 17)) ;
	    			exp2 = checkEXP(roundup(exp2*1.15)) ;    	   			
	    		}
	    	}
	    	exp1 =checkEXP(exp1 - e1) ;
	    }
	    return exp1 + exp2;
	}
	else return -99 ; 
}
	


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
if ( E2 > 99 || E2 < 0) return -99 ;
	else {
	
	    int S ;
	    float P1 ;
	    // con duong 1 
	    for ( int i = 0 ; i <= EXP1 ; i++)
	    {
	    	if(( i*i <= EXP1 ) && ((i+1)*(i+1) >=EXP1) ) 
	    	{
	    		if ( (EXP1 - i*i) <= ((i+1)*(i+1) - EXP1)) 
				{
					S= i*i ; 
					P1 = 1.0 ;
				} 
	    		else 
	    		{
	    			if( EXP1 == (i+1)*(i+1)) P1 = 1.0 ;
	    			else{
	    			S = (i+1)*(i+1) ; 
	    			P1 = (EXP1*1.0/S + 80)/123.0 ;   
					}   			
		 		}
	    		break ;
	    	}
	    }
	    // con duong 2
	    
	    int temp = M1 ;
	    do 
	    {
	    	if ( M1 == 0 && E2%2==0) break ;
	     //su kien 1
	    	if(HP1 < 200){
	    		HP1 = checkHP(roundup(HP1*1.3)) ; 
	    		M1 = checkM(M1 - 150 );
			}
			else {
				HP1 = checkHP(roundup(HP1*1.1)) ;
				M1 = checkM(M1 - 70) ;
			}
			
			if ( M1 < temp/2.0 ) 
			{
				if ( M1 <= 0 && E2%2 == 0 ) break ; 
				else if ( E2 %2== 1 ) break ; 
			}
		//su kien 2
	    	if(EXP1 < 400) 
	    	{
	    		M1 = checkM(M1 -200 );
	    	}
	    	else {
	    		M1 =checkM( M1 - 120) ;
	    	}
	    	
	    	EXP1 = checkEXP(roundup(EXP1 *1.13)) ;
	    	
	    	if ( M1 < temp/2.0 ) 
			{
				if ( M1 <= 0 && E2%2 == 0 ) break ; 
				else if ( E2 %2== 1 ) break ; 
			}
		// su kien 3
	    	if ( EXP1 < 300) 
	    	{
	    		M1 = checkM(M1 - 100 );
	    	}
	    	else M1 = checkM(M1 -120) ;
	    	
	    	EXP1 = checkEXP(roundup(EXP1*0.9));
	    	
	    	if ( M1 < temp/2.0 ) 
			{
				if ( M1 <= 0 && E2%2 == 0 ) break ; 
				else if ( E2 %2== 1 ) break ; 
			}
		}
		while (E2%2==1);
		

		HP1 = checkHP(roundup(HP1*0.83)) ; 
		EXP1 = checkEXP(roundup(EXP1*1.17)) ;

		// tinh xac suat P2
		float P2 ;
		for ( int i = 0 ; i <= EXP1 ; i++)
	    {
	    	if( i*i <= EXP1 && (i+1)*(i+1) >=EXP1)
	    	{
	    		if ( ((EXP1 - i*i)) <= (((i+1)*(i+1) - EXP1)) )
				{
					S = i*i ; 
					P2 = 1.0 ;
				} 
	    		else 
	    		{
	    			if (EXP1 == (i+1)*(i+1)) P2 = 1.0 ;
	    			else {
	    			S = (i+1)*(i+1) ; 
	    			P2 = (EXP1*1.0/S + 80)/123.0 ;  
					}   			
		 		}
	    		break ;
	    	}
	    }
		// con duong 3 
		int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11} ;
		int i; 
		float P3 ; 
		i = (E2/10 + E2%10) %10 ;
		P3 = P[i]*1.0/100 ; 
		if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0 ) EXP1 = checkEXP(roundup(EXP1*0.75)) ;
		else 
		{
			if(((P1+P2+P3)/3.0)<0.5) {
				HP1 = checkHP(roundup(HP1*0.85)) ;
				EXP1 = checkEXP(roundup(EXP1*1.15));
			}
			else {
				HP1 = checkHP(roundup(HP1*0.9)) ;
				EXP1 = checkEXP(roundup(EXP1*1.2)) ;
			}
		}
		
	    return HP1 + EXP1 + M1;
	}
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function]
    if ( E3 <=99 && E3 >= 0 )
    {
	    
	    int const rows = 10 ;
	    int const cols = 10 ;
	    int count1 = 0;
	    int count2 = 0;
	    int matrix[rows][cols] ;
	    for (int i=0 ; i< rows ; i++){
	    	for (int j= 0 ; j <cols ; j++){
	    		matrix[i][j] = ((E3*j)+(i*2))*(i-j) ;
	    		if (matrix[i][j] > E3*2 ) count1++ ; // dong
	    		if (matrix[i][j] < -E3 ) count2++ ;// cot
	    	}
	    }
	    if(count1 > 9) count1 = (count1/10 + count1%10)%10 + ( count1/10 + count1%10)/10 ;
	    if(count2 > 9) count2 = (count2/10 + count2%10)%10 + ( count2/10 + count2%10)/10 ;
	    int max = matrix[count1][count2] ; // gan max = [][] , sau do kiem tra tat ca gia tri cua matrix, xem gia tri nao thuoc duong cheo, lon hon max thi gan max
	    int a = count1 - count2 ; // kiem tra xem diem [][] thuoc duong cheo trai nao
	    int b = count1 + count2 - (rows-1) ; // kiem tra xem diem [][] thuoc duong cheo phai nao
	
	    for ( int i = 0 ; i< rows; i++){
	    	for ( int j = 0 ;j < cols ; j++ ) {
	    		if ( (i - j) == a || (i + j - rows + 1 ) == b ) // kiem tra xem co thuoc duong cheo trai hoac duong cheo phai cua [][] khong
				{
	    			if ( max < matrix[i][j]) max = matrix[i][j] ;
	    		}
	    	}
	    	
	    }
	    if ( abs(matrix[count1][count2]) <= abs(max)) {
	    	EXP1 = checkEXP(roundup(EXP1 * 1.12)) ;
	    	EXP2 = checkEXP(roundup(EXP2 *1.12)) ;
	    	HP1 = checkHP(roundup(HP1 * 1.10)) ;
	    	HP2 = checkHP(roundup(HP2 *1.10)) ;
	    	return max ; 
	    }
	    else {
	    	EXP1 = checkEXP(roundup(EXP1 * 0.88)) ;
	    	EXP2 = checkEXP(roundup(EXP2 * 0.88)) ;
	    	HP1 = checkHP(roundup(HP1 * 0.9)) ;
	    	HP2 = checkHP(roundup(HP2 * 0.9)) ;
	    	return matrix[count1][count2] ; 
	    }
	}
	else return -99 ;
}

int checkPassword(const char * s, const char * email){
    // TODO: Complete this function
    char se[100] ;
	for (int i=0 ; i <strlen(email) ; i++) {
		if ( email[i+1] != '@') {
			se[i] =  email[i] ;
		}
		else break ; 
	}
	//
	int a = strlen(s) ; 
	if ( strlen(s) < 8 ) return -1 ;
	else if ( strlen(s) > 20) return -2 ;
	else {
		for ( int i= 0 ; i < strlen(s) ; i++) {
			if (s[i] >= '0' && s[i] <= '9' ||
			 	s[i] >= 'a' && s[i] <= 'z' ||
			  	s[i] >= 'A' && s[i] <= 'Z' ||
			  	s[i]=='@'  || s[i] == '!'   ||
			   	s[i]== '#' || s[i] == '%'  ||
			    s[i]=='$'){
				if ( s[i] == se[0]){
					int temp = i ;
					int count = 0 ;
					for ( int j = 0; j< strlen(se); j++){
						if (s[temp] == se[j]) {
							count++ ;
							temp++;
						}
						else break ; 
					}
					if ( count == strlen(se)) return -(300+i) ;
				}
				else if (s[i]==s[i+1] && s[i]==s[i+2]) return -(400 + i) ;
				else if (s[i]!='@' && s[i] != '!' &&s[i]!= '#' && s[i] != '%' && s[i] !='$' ) a=a-1  ;
			}
			else if(a==0) return -5 ; 
			else {
				return i ; 
			}
		}
		return - 10 ; 
	}
}
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
	string pwds[num_pwds] ;
	int  soLan[num_pwds] ; 
	for ( int i = 0; i <num_pwds ; i++) {
		pwds[i] = "" ;
		soLan[i] = 0 ;
	} 
	for ( int i= 0 ; i < num_pwds ; i++) {
		for ( int j=0 ; j< num_pwds ; j++){
			if(arr_pwds[i] == pwds[j]){
				soLan[j]++ ; 
				break ; 
			}
			else if(pwds[j] == ""){
				pwds[j] = arr_pwds[i] ;
				soLan[j]++ ;
				break ;	
			}
		}
	}
	int max = soLan[0] ; 
	int addr = 0 ;
	for( int i = 1  ; i < num_pwds ; i++) {
		if ( max < soLan[i]) {
			max = soLan[i] ; 
			addr = i ;
		}
		else if ( max==soLan[i]){
			if ( pwds[addr].length() < pwds[i].length() ){
				addr = i ;
			}
		}
	}
	int a ; 
	for ( int i = 0 ; i< num_pwds ; i++) {
		if (arr_pwds[i] == pwds[addr]){
			a = i ; 
			break ; 
		} 
	}
	return a ; 
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
