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

int exp( int & exp ){
	if ( exp<0 ){
		exp = 0 ;
	} 
	if ( exp>600 ){
		exp = 600 ;
	} 
	return exp;
}

int hp( int & hp ){
	if ( hp<0 ){
		hp = 0 ;
	} 
	if ( hp>666 ){
		hp = 666 ;
	} 
	return hp;
}

//-------------------so-chinh-phuong----------------
int Square_number(int&EXP1){
	int s, n, i;
	int min=EXP1;
	for ( i = 1; i<EXP1; i++){
		s=i*i;
		n= abs(EXP1 - s);
		if ( n < min ) {
			min = EXP1 - s;
		}
		else{
			s=(i-1)*(i-1);
			break ;
		}
	}
	return s ;
}

//-------------khoang-m-------------------------	
int M(int&m1) {
	if ( m1<0 ){
		m1 = 0 ;
	} 
	if ( m1>3000 ){
		m1 = 3000 ;
	} 
	return m1;
}

// Task 1-----------------------------------------------
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ( e1<0 || e1>99 ) return -99;
    // TODO: Complete this function
    int d;
//  TH1
    if ( e1 <= 3){
    	if ( e1 == 0 ){
    		d = e1*3 + exp1*7;
    		exp2 = exp2 + 29;
		}
		else if ( e1 == 1 ){
			d = e1*3 + exp1*7;
			exp2 = exp2 + 45;
		}
		else if ( e1 == 2 ){
			d = e1*3 + exp1*7;
			exp2 = exp2 + 75;
		}
		else if ( e1 == 3 ) {
			d = e1*3 + exp1*7;
			exp2 = exp2 + 29 + 45 + 75;
		}
//		Xet D:
		if ( d % 2 == 0 ){
			exp1 = ceil(exp1*1.0 + d*1.0/200);
		}
		else if ( d % 2 == 1 ){
			exp1 = ceil(exp1*1.0 - d*1.0/100);
		}
	}
//	TH2
	else if ( e1>=4 & e1<=99 ){
		if ( e1>=4 & e1<=19 ){
			exp2 = ceil(exp2*1.0 + e1*1.0/4 + 19);
		}
		else if ( e1>=20 & e1<=49 ){
			exp2 = ceil(exp2*1.0 + e1*1.0/9 + 21);
		}
		else if ( e1>=50 & e1<=65 ){
			exp2 = ceil(exp2*1.0 + e1*1.0/16 + 17);
		}
		else if ( e1>=66 & e1<=79 ){
			exp2 = ceil(exp2*1.0 + e1*1.0/4 + 19);
			if ( exp2>200 ){
				exp2 = ceil(exp2*1.0 + e1*1.0/9 + 21);
			} 
		}
		else if ( e1>=80 & e1<=99 ){
			exp2 = ceil(exp2*1.0 + e1*1.0/4 + 19);
			exp2 = ceil(exp2*1.0 + e1*1.0/9 + 21);
			if ( exp2>400 ){
				exp2 = ceil(exp2*1.0 + e1*1.0/16 + 17);
				exp2 = ceil(exp2*1.15);
			}
		}
		exp1 = exp1 - e1;
	}
	exp(exp1);
	exp(exp2);
    return exp1 + exp2;
}

// Task 2--------------------------------------------------------------------
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
	float p1, p2, p3, p;
	int s;
	float m2;
	m2 = M1*1.0/2;


//-----------------Con duong 1----------------------------------------------
	s = Square_number(EXP1);
	if ( EXP1 >= s ){
		p1 = 1;
	}
	else p1 = (EXP1*1.0/s + 80)/123;
	
	
//----------------Con duong 2-----------------------------------------------

	int j=0;
	int m;
	int x=0;
	if(E2 % 2 == 1 ){

		while ( j>=0 ){
//-------------------------thuc-an--------------------------
			if ( HP1<200 ){
				HP1 = ceil(HP1*1.3 - 1e-9);
				M1 -= 150;
				m = 150;
			}
			else {
				HP1 = ceil(HP1*1.1 - 1e-9);
				M1 -= 70;
				m = 70;
			}
			hp(HP1);
			x += m;
			M(M1);
			if ( x >= m2 ){
				HP1 = ceil(HP1*0.83 - 1e-9);
				EXP1 = ceil(EXP1*1.17 - 1e-9);
				exp(EXP1);
				hp(HP1);
				break;
			}
			else if ( M1==0 ){
				break;
			} 
//-----------------------xe---------------------------------
			else {
				if ( EXP1<400 ){
					M1 -= 200;
					m = 200;
				}
				else {
					M1 -= 120;
					m = 120;
				}
				EXP1 = ceil(EXP1*1.13 - 1e-9);
				exp(EXP1);
			}
			x += m;
			M(M1);
			if (  x >= m2 ){
				HP1 = ceil(HP1*0.83 - 1e-9);
				EXP1 = ceil(EXP1*1.17 - 1e-9);
				exp(EXP1);
				hp(HP1);
				break;
			}
			else if ( M1==0 ){
				break;
			} 
//----------------------vo-gia-cu----------------------------------
			else {
				if ( EXP1<300 ){
					M1 -= 100;
					m = 100;
				}
				else {
					M1 -= 120;
					m = 120;
				}
				EXP1 = ceil(EXP1*0.9 - 1e-9);
				exp(EXP1);
			}
			x += m;
			M(M1);
			if ( x >= m2 ){
				HP1 = ceil(HP1*0.83 - 1e-9);
				EXP1 = ceil(EXP1*1.17 - 1e-9);
				exp(EXP1);
				hp(HP1);
				break;
			}
			else if ( M1==0 ){
				break;
			} 
//			else if ( E2 % 2 == 0){
//				break;
//			}
//			else if ( E2 % 2 == 1) {
				j++;
//			}
		}
    }
//-----------------------------------------------------------------------------------------------------------------------
    else if ( E2 % 2 == 0 ){
    	for ( int i=0; i<1; i++){
	
    			if ( HP1<200 ){
				HP1 = ceil(HP1*1.3 - 1e-9);
				M1 -= 150;
				m = 150;
			}
			else {
				HP1 = ceil(HP1*1.1 - 1e-9);
				M1 -= 70;
				m = 70;
			}
			hp(HP1);
			x += m;
			M(M1);
			
			if ( M1==0 ){
				HP1 = ceil(HP1*0.83 - 1e-9);
				EXP1 = ceil(EXP1*1.17 - 1e-9);
				exp(EXP1);
				hp(HP1);
				break;
			} 
//-----------------------xe---------------------------------
			else {
				if ( EXP1<400 ){
					M1 -= 200;
					m = 200;
				}
				else {
					M1 -= 120;
					m = 120;
				}
				EXP1 = ceil(EXP1*1.13 - 1e-9);
				exp(EXP1);
			}
			x += m;
			M(M1);
			if ( M1==0 ){
				HP1 = ceil(HP1*0.83 - 1e-9);
				EXP1 = ceil(EXP1*1.17 - 1e-9);
				exp(EXP1);
				hp(HP1);
				break;
			} 
//----------------------vo-gia-cu----------------------------------
			else {
				if ( EXP1<300 ){
					M1 -= 100;
					m = 100;
				}
				else {
					M1 -= 120;
					m = 120;
				}
				EXP1 = ceil(EXP1*0.9 - 1e-9);
				exp(EXP1);
			}
			x += m;
			M(M1);
	}
	}
	s = Square_number(EXP1);
	if ( EXP1 >= s ){
		p2 = 1;
	}
	else p2 = (EXP1*1.0/s + 80)/123;	
	
//------------------------con-duong-3-----------------------------------

	int i;
	int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
	if ( E2<10 ){
		i = E2;
	}
	else{
		int sum = 0;
    	while (E2 != 0) {
        	sum += E2 % 10;
        	E2 /= 10;
    	}
    	i = sum % 10;
	}

	p3 = P[i]*1.0/100;
	p = ( p1+p2+p3 )/3;
	
//--------------------------------------------------------------
	if ( p1==1 & p2==1 & p3==1 ){
		EXP1 = ceil(EXP1*0.75 - 1e-9);
	}
	else {
		if ( p<0.5 ){
			HP1 = ceil(HP1*0.85 - 1e-9);
			EXP1 = ceil(EXP1*1.15 - 1e-9);
		}
		else{
			HP1 = ceil(HP1*0.9 - 1e-9);
			EXP1 = ceil(EXP1*1.2 - 1e-9);
		}
	}
	exp(EXP1);
	hp(HP1);	
    return HP1 + EXP1 + M1;
}

// Task 3-----------------------------------------------------------------------------------------------------
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ( E3<0 || E3>99 ) return -99;
    	int arr[10][10];
	for ( int i=0; i<10; i++){
		for ( int j=0; j<10; j++){
			arr[i][j]=((E3*j)+2*i)*(i-j);
		}
	}

//-----------tim-vi-tri-gap-nhau-------------------------------
	int s1=0;
	int s2=0;
	int i=0;
	int j=0;
	for ( int i=0; i<10; i++){
		for ( int j=0; j<10; j++){
			if ( arr[i][j]>0 & arr[i][j]>(E3*2)){
				s1+=1;
			}

		}
	}

	while (i>=0){
		while ( s1 != 0 ) {
        	i += s1 % 10;
        	s1 /= 10;
    	}
    	if( i<10 ) {
    		break;
		}
		else {
			s1=i;
			i=0;
		}
	}
	
	for ( int i=0; i<10; i++){
		for ( int j=0; j<10; j++){
			if ( arr[i][j]<0 & arr[i][j]<(-E3) ){
				s2+=1;
			}

		}
	}	 

	while (j>=0){
		while ( s2 != 0 ) {
        	j += s2 % 10;
        	s2 /= 10;
    	}
    	if( j<10 ) {
    		break;
		}
		else {
			s2=j;
			j=0;
		}
	}


//-------------diem--------------------
	int sT;
	sT=arr[i][j];
	int max,a,b;
	a=i;
	b=j;
	max=arr[i][j];
	while ( a!=9 || b!=9 ){
		a++;
		b++;
		if( arr[a][b]>max){
			max=arr[a][b];
		}
		else {
			break;
		}
	}
	while ( i!=9 || j!=0 ){
		i++;
		j--;
		if( arr[i][j]>max){
			max=arr[i][j];
		}
		else {
			break;
		}
	}


	if ( abs(sT)<=max ){
		EXP1 = ceil(EXP1*1.12 - 1e-9);
		HP1 = ceil(HP1*1.1 - 1e-9);
		EXP2 = ceil(EXP2*1.12 - 1e-9);
		HP2 = ceil(HP2*1.1 - 1e-9);
		hp(HP1);
		exp(EXP1);
		hp(HP2);
		exp(EXP2);
		return max;
	}
	else if ( abs(sT)>max ){
		EXP1 = ceil(EXP1*0.88 - 1e-9);
		HP1 = ceil(HP1*0.9 - 1e-9);
		EXP2 = ceil(EXP2*0.88 - 1e-9);
		HP2 = ceil(HP2*0.9 - 1e-9);
		hp(HP1);
		exp(EXP1);
		hp(HP2);
		exp(EXP2);
		max=sT;
		return max;
	}

  return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
	int Lenmail = strlen(email);

    int a = -1;
    for (int i = 0; i < Lenmail; ++i) {
        if (email[i] == '@') {
            a = i;
            break;
        }
    }

    if (a == -1 || Lenmail > 100)
        return -99; 


    char se[101];
    strncpy(se, email, a);
    se[a] = '\0'; 

    int Len_s = strlen(s);
    if (Len_s < 8)
        return -1; 
    if (Len_s > 20)
        return -2; 

   
    if (strstr(s, se) != NULL)
        return -(300 + (strstr(s, se) - s) ); 

 
    for (int i = 0; i < Len_s - 2; ++i) {
        if (s[i] == s[i+1] && s[i] == s[i+2])
            return -(400 + i); 
	}
   
    bool SpecialChar = false;
    for (int i = 0; i < Len_s; ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            SpecialChar = true;
    }
    if (!SpecialChar)
        return -5; 

    
    for (int i = 0; i < Len_s; ++i) {
        if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))
            return i; 
    }

    return -10;
    
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
//  mang so lan xuat hien
    int counts[num_pwds];
//   // cho mang counts co all gtri = 0 
    memset(counts, 0, sizeof(counts)); 

    // so lan xuat hien cua mat khau
    for (int i = 0; i < num_pwds; ++i) {
        for (int j = 0; j < num_pwds; ++j) {
            if (std::strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                counts[i]++;
            }
        }
    }

    // mk xhien nhiu va dai nhat
    int max_count = 0;
    int max_length = 0;
    int a = -1;
    for (int i = 0; i < num_pwds; ++i) {
        int length = std::strlen(arr_pwds[i]);
        if (counts[i] > max_count || (counts[i] == max_count && length > max_length)) {
            max_count = counts[i];
            max_length = length;
            a = i;
        }
    }

 
    return a;


    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
