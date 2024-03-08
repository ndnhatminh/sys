#include "study_in_pink1.h"
#include <cmath>
#include <math.h>
#include <cstring>
#include <cctype> 

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

int one_num(int n){
	if (n > 9) {
    	n = n/10 + n%10;
	};
	if (n > 9) {
    	n = n/10 + n%10;
	};
	return n;
}

int ceil_s(double s)
{
    if (abs(s-int(s))>1e-9) {
        s=ceil(s);
    }
    return s;
}

int reset_hp(int hp){
	if (hp < 0){
		hp = 0;
	};
	if (hp > 666){
		hp = 666;	
	};
	return hp;
}
int reset_exp(int exp){
	if (exp < 0){
		exp = 0;
	};
	if (exp > 600){
		exp = 600;	
	};
	return exp;
}
int reset_m(int m){
	if (m < 0){
		m = 0;
	};
	if (m > 3000){
	m = 3000;	
	};
	return m;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    
    int d = 0;
  	if ((e1 > 99) || (e1 < 0)) return -99;
  	else {
    	exp1 = reset_exp(exp1);
    	exp2 = reset_exp(exp2);
    
    	if (e1 < 4) {
    		switch(e1) {
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
			};
	
			d = e1*3 + exp1*7;
			if (d % 2 == 0) { 
				exp1 = ceil_s(exp1 + double(d)/200);
			} 
			else { 
				exp1 = ceil_s(exp1 - double(d)/100);
			};
		}
		else {
			if (e1 < 20) {exp2 = ceil_s(exp2 + double(e1)/4 + 19);}
			else 
				if (e1 < 50) {exp2 = ceil_s(exp2 + double(e1)/9  + 21);}
				else 
					if (e1 < 66) {exp2 = ceil_s(exp2 + double(e1)/16 + 17);}
			 		else 
						if (e1 < 80) {
				   			exp2 = ceil_s(exp2 + double(e1)/4 + 19);
				   			if (exp2 > 200) {exp2 = ceil_s(exp2 + double(e1)/9 + 21);};
				   		} 
						else 
						    if (e1 < 100) {
				   			exp2 = ceil_s(exp2 + double(e1)/4 + 19);
				   			exp2 = ceil_s(exp2 + double(e1)/9 + 21);
				   			if (exp2 > 400) {
							   exp2 = ceil_s(exp2 + double(e1)/16 + 17);
							   exp2 = ceil_s(double(exp2) * 1.15);
							};				   			
					    }
		exp1 -= e1;
		}
    
    exp1 = reset_exp(exp1);
    exp2 = reset_exp(exp2);
    
    
    return exp1 + exp2;
 	}
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
	
	if ((E2 > 99) || (E2< 0)) return -99;
  	else {
		HP1 = reset_hp(HP1);
    	EXP1 = reset_exp(EXP1);
   	 	M1 = reset_m(M1);
    
    	//stage 1
 		int s;
    	float p1;
    
    	s = pow(round(sqrt(double(EXP1))), 2);
   	 	if (EXP1 >= s) p1 = 100;
		else p1 = (double(EXP1) / s + 80) / 1.23;
	
		HP1 = reset_hp(HP1);
    	EXP1 = reset_exp(EXP1);
    	M1 = reset_m(M1);
	
		//stage 2
		int m;
    	float p2;
    	m = M1;
    
    	do {
    		if (M1 <= 0) break;
    	
	    	//act 1
	    	if (HP1 < 200){
	    		HP1 = ceil_s(double(HP1) * 1.3);
	    		M1 -= 150;
	    		HP1 = reset_hp(HP1);
			}
			else {
				HP1 = ceil_s(double(HP1) * 1.1);
				HP1 = reset_hp(HP1);
	    		M1 -= 70;
			};
			
			
			if (M1 < 0) {
				HP1 = ceil_s(double(HP1) * 0.83);
				EXP1 = ceil_s(double(EXP1) * 1.17);
				HP1 = reset_hp(HP1);
	    		EXP1 = reset_exp(EXP1);
				break;
			};
			if ((M1 < m/2)&&(E2 % 2 != 0)) {
				HP1 = ceil_s(double(HP1) * 0.83);
				EXP1 = ceil_s(double(EXP1) * 1.17);
				HP1 = reset_hp(HP1);
	    		EXP1 = reset_exp(EXP1);
				break;
			};
			
			//act 2
			if (EXP1 < 400) M1 -= 200;
			else M1 -= 120;
			EXP1 = ceil_s(double(EXP1) * 1.13);
			HP1 = reset_hp(HP1);
	    	EXP1 = reset_exp(EXP1);
	    	if (M1 < 0) {
				HP1 = ceil_s(double(HP1) * 0.83);
				EXP1 = ceil_s(double(EXP1) * 1.17); 
				HP1 = reset_hp(HP1);
	   			EXP1 = reset_exp(EXP1);
				break;
			};
			if ((M1 < m/2)&&(E2 % 2 != 0)) {
				HP1 = ceil_s(double(HP1) * 0.83);
				EXP1 = ceil_s(double(EXP1) * 1.17);
				HP1 = reset_hp(HP1);
	    		EXP1 = reset_exp(EXP1);
				break;
			};
			
			//act 3
			if (EXP1 < 300) M1 -= 100;
			else M1 -= 120;
	    	EXP1 = ceil_s(double(EXP1) * 0.9);
	    	HP1 = reset_hp(HP1);
	    	EXP1 = reset_exp(EXP1);
	    	if (M1 < 0) {
				HP1 = ceil_s(double(HP1) * 0.83);
				EXP1 = ceil_s(double(EXP1) * 1.17); 
				HP1 = reset_hp(HP1);
	    		EXP1 = reset_exp(EXP1);
				break;
			};
			if ((M1 < m/2)&&(E2 % 2 != 0)) {
				HP1 = ceil_s(double(HP1) * 0.83);
				EXP1 = ceil_s(double(EXP1) * 1.17);
				HP1 = reset_hp(HP1);
	    		EXP1 = reset_exp(EXP1);
				break;
			};
	    	
	    	
			if (E2 % 2 == 0) {
				HP1 = ceil_s(double(HP1) * 0.83);
				EXP1 = ceil_s(double(EXP1) * 1.17);
				HP1 = reset_hp(HP1);
	    		EXP1 = reset_exp(EXP1);
				break;
			}
		} 
		while (E2 % 2 != 0);
		
		HP1 = reset_hp(HP1);
	    EXP1 = reset_exp(EXP1);
	    M1 = reset_m(M1);
		
	    s = pow(round(sqrt(double(EXP1))), 2);
	    if (EXP1 >= s) p2 = 100;
		else p2 = (double(EXP1) / s + 80) / 1.23;
	    
		//stage 3
	    int a[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
	    float p3;
	    
	    if (E2<10) p3 = a[E2];
	    else {
	    	s = E2/10 + E2%10;
	    	p3 = a[s%10];
		};
		    
	    //conclution
	    float p;
	    if ((p1==100) && (p2==100) && (p3==100)) EXP1 = ceil_s(double(EXP1) * 0.75);
	    else {
	    	p = (p1 + p2 + p3) /  3;
	    	if (p < 50) {
	    		HP1 = ceil_s(double(HP1) * 0.85);
				EXP1 = ceil_s(double(EXP1) * 1.15);
			}
			else{
				HP1 = ceil_s(double(HP1) * 0.9);
				EXP1 = ceil_s(double(EXP1) * 1.2);
			}
		}
		 
	    HP1 = reset_hp(HP1);
	    EXP1 = reset_exp(EXP1);
	    M1 = reset_m(M1);
	    
	    
	    return HP1 + EXP1 + M1;
	}
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if ((E3 > 99) || (E3 < 0)) return -99;
    else {
    	
		//create map
    	int a[10][10];
    	
    	for (int i = 0; i < 10; i++){
    		for (int j = 0; j < 10; j++){
				a[i][j] =  ((E3 * j) + (i * 2)) * (i - j);    	
			}
		}
		
		//locate position 
		int point_max, point_min;
		int point_row, point_col = 0;
		int row_ind, col_ind;
		
		point_max = E3 * 2;
		point_min = 0 - E3;
		for (int i = 0; i < 10; i++){
    		for (int j = 0; j < 10; j++){
				if (a[i][j] > point_max) point_row++;
				if (a[i][j] < point_min) point_col++;
			}
		}
		
		row_ind = one_num(point_row);
		col_ind = one_num(point_col);
		
		//calculate point
		int taxi_point, det_point = 0;
		int max_left, max_right;
		taxi_point = a[row_ind][col_ind];
			
			//left diagonal line
			int temp_i, temp_j;
			
			if (row_ind >= col_ind){
				temp_i = row_ind - col_ind;
				temp_j = col_ind - col_ind;
			}
			else {
				temp_i = row_ind - row_ind;
				temp_j = col_ind - row_ind;
			};
			
			max_left = a[temp_i][temp_j];
			do{
				if (a[temp_i][temp_j] > max_left) max_left = a[temp_i][temp_j];
				temp_i++;
				temp_j++;
			} while ((temp_i < 10) &&(temp_j < 10));
			
			//right diagonal line
			col_ind = 9 - col_ind;
			if (row_ind >= col_ind){
				temp_i = row_ind - col_ind;
				temp_j = col_ind - col_ind;
			}
			else {
				temp_i = row_ind - row_ind;
				temp_j = col_ind - row_ind;
			};
			
			temp_j = 9 - temp_j;
			max_right = a[temp_i][temp_j];
			do{
				if (a[temp_i][temp_j] > max_left) max_right = a[temp_i][temp_j];
				temp_i++;
				temp_j--;
			} while ((temp_i < 10) &&(temp_j > -1));
		if (max_right > max_left) det_point = max_right;
		else det_point = max_left;
		
		//conclusion
		
    	
		if (abs(taxi_point) > det_point){
			HP1 = ceil_s(double(HP1) * 0.9);
			EXP1 = ceil_s(double(EXP1) * 0.88);
			HP2 = ceil_s(double(HP2) * 0.9);
			EXP2 = ceil_s(double(EXP2) * 0.88);
		
			HP1 = reset_hp(HP1);
    		EXP1 = reset_exp(EXP1);
   			HP2 = reset_hp(HP2);
    		EXP2 = reset_exp(EXP2);
		
			return taxi_point;
		}
		else {
			HP1 = ceil_s(double(HP1) * 1.1);
			EXP1 = ceil_s(double(EXP1) * 1.12);
			HP2 = ceil_s(double(HP2) * 1.1);
			EXP2 = ceil_s(double(EXP2) * 1.12);
			
			HP1 = reset_hp(HP1);
    		EXP1 = reset_exp(EXP1);
   			HP2 = reset_hp(HP2);
    		EXP2 = reset_exp(EXP2);
    
        	return det_point;
        }
        
	};
}

// Task 4
int checkPassword(const char * s, const char * email) {
    const char* pos_email = strchr(email, '@');    
    size_t email_length = pos_email - email; 
    char username[email_length+3];
    strncpy(username, email, email_length);
    size_t pass_length = strlen(s);
	int pos, c = 0;  
    
	
	if (pass_length < 8) return -1;
	else if(pass_length > 20) return -2;
    	else {
			const char* substr_pos = strstr(s, username);
			if (substr_pos != nullptr) return 0 - (300 + (substr_pos - s));
			else {
				for (int i = 0; i < pass_length - 3; ++i) {
					if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {return -(400 + i);}
				}
				
				c = 0;
				for (int i = 0; i < pass_length; i++ ) {
					if (((s[i] == '@' )|| (s[i] == '#' )|| (s[i] == '%' )|| (s[i] == '$' )|| (s[i] == '!'))) c = 1;
					
				}			
				if (c == 0) {return -5;}
				int pos=0;
				for (int i = 0; i < pass_length; i++ ) {
					if ((isdigit(s[i])) || (islower(s[i])) || (isupper(s[i])) || (s[i] == '@' )|| (s[i] == '#' )|| (s[i] == '%' )|| (s[i] == '$' )|| (s[i] == '!')) {
					} 
					else {
						return i;
					}
				}
					
    		}
    
 		}
	return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds){
	
	int max_fre, max_pos, max_length, fre, pos, length = 0;
	max_fre = 0;
	max_pos = 0;
	max_length = 0;
	for (int i = 0; i < num_pwds - 1; i++){
		pos = i;
		fre = 1;
		length = strlen(arr_pwds[i]);
		
		for (int j = i + 1; j < num_pwds; j++){
			if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) fre++;
			if (fre > max_fre){
				max_fre = fre;
				max_pos = pos;
				max_length = length;
			}
			else{
				if (fre == max_fre){
					if (length > max_length){
						max_fre = fre;
						max_pos = pos;
						max_length = length;
					}
				}
			}
		}		
	}
	
	return max_pos;
}
