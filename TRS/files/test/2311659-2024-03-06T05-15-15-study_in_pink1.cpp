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

int clamp_result(int x, int b) {
	return max(0, min(x, b));
}

int ceil_(double x) {
	int y = static_cast<int>(x);
	if (x - static_cast<double>(y) >= 0.001) {
		return y + 1;
	}
	return y;
	
//	return static_cast<int>(x + 0.999);
}

int scale(int x, double f) {
	if (f > 0.0) {
		return ceil_(x + static_cast<double>(x) * f);
	} else {
		return ceil_(x - static_cast<int>(static_cast<double>(x) * abs(f)));
	}
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    if (e1 < 0 || e1 > 99) {
    	return -99;
    }
    
	exp2 = clamp_result(exp2, 600);
   	exp1 = clamp_result(exp1, 600);
    
    if (e1 <= 3) {
	
		switch (e1) {
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
				exp2 += 29 + 45 + 75;
				break;
    	}
    	
    	int d = e1 * 3 + exp1 * 7;
    	double exp1_f = static_cast<double>(exp1);
    	double df = static_cast<double>(d);
    	if (d % 2 != 0) {
    		exp1 = exp1 - (int)(df / 100.0);
    	} else {
    		exp1 = exp1 + ceil_(df / 200.0);
    	}
    
    	exp2 = clamp_result(exp2, 600);
   		exp1 = clamp_result(exp1, 600);
    	
    	return exp1 + exp2;
    
    }
    
    
    double e1f = (double)(e1);
    int exp_possible_bonuses[3] = {
    	(int)ceil(e1f / 4.0)  + 19,
    	(int)ceil(e1f / 9.0)  + 21,
    	(int)ceil(e1f / 16.0) + 17
    };
        
    if (e1 <= 19) { // 1
    	
    	exp2 += exp_possible_bonuses[0];
    
    } else if (e1 <= 49) { // 2
    	
    	exp2 += exp_possible_bonuses[1];
    
    } else if (e1 <= 65) { // 3
    	
    	exp2 += exp_possible_bonuses[2];
    
    } else if (e1 <= 79) { // 4
		
		exp2 += exp_possible_bonuses[0];
		
		if (exp2 > 200) {
			exp2 += exp_possible_bonuses[1];
		}
		
   	} else { // 5
   		
   		exp2 += exp_possible_bonuses[0];
   		
   		exp2 += exp_possible_bonuses[1];
   		
   		if (exp2 > 400) {
			exp2 += exp_possible_bonuses[2];
			exp2 = scale(exp2, 0.15);
   		}
   	}
   	
   	exp1 -= e1;
   	
   	exp2 = clamp_result(exp2, 600);
   	exp1 = clamp_result(exp1, 600);
   	
    return exp1 + exp2;
}

int nearest_perfect_square(int x) {
	int sqrt_ = sqrt(x);
	// cout << sqrt_ << '\n';
	
	int sqr_low  = sqrt_ * sqrt_;
	
	if (sqr_low == x) return sqr_low;
	
	sqrt_ += 1; int sqr_high = sqrt_ * sqrt_;
	
	return (sqr_high - x < x - sqr_low) ? sqr_high : sqr_low; 
}

bool check_m1(int m1, int m1_ori, int e2) {
	if (m1 <= 0) {
		return true;
	}
	
	if (e2 % 2 != 0) {
		return static_cast<double>(m1) < static_cast<double>(m1_ori/2.0);
	} else {
		return m1 <= 0;
	}
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    
    if (E2 < 0 || E2 > 99) {
    	return -99;	
   	}
    
 	EXP1 = clamp_result(EXP1, 600);
	HP1 = clamp_result(HP1, 666);
	M1 = clamp_result(M1, 3000);
     
    bool e2_odd = E2 % 2 != 0;
    
    // Road 1
   	double P1 = 0.0;
    { 
		int S = nearest_perfect_square(EXP1);
		// cout << S << '\n';
		
		if (EXP1 >= S) {
			P1 = 1.0;
		} else {
			P1 = ((double)EXP1 / (double)S + 80.0) / 123.0;
		}
		
		// cout << P1 << '\n';
	}

	
	// Road 2 
	double P2 = 0.0;
	{
		int m1_ori = M1;
		for (;;) {
		
			if (check_m1(M1, m1_ori, E2)) break;

			if (HP1 < 200) {
				HP1 = scale(HP1, 0.3);
				M1 -= 150;
			} else {
				HP1 = scale(HP1, 0.1);
				M1 -= 70;
			}
			
			HP1 = clamp_result(HP1, 666);
			
			//cout << HP1 << ' ' << EXP1 << ' ' << M1 << ' ' << m1_ori << '\n';
			
			if (check_m1(M1, m1_ori, E2)) break;
			
			if (EXP1 < 400) {
				M1 -= 200;
			} else {
				M1 -= 120;
			}
			
			EXP1 = scale(EXP1, 0.13);
			EXP1 = clamp_result(EXP1, 600);
			
			//cout << HP1 << ' ' << EXP1 << ' ' << M1 << ' ' << m1_ori << '\n';
			
			if (check_m1(M1, m1_ori, E2)) break;
			
			if (EXP1 < 300) {
				M1 -= 100;
			} else {
				M1 -= 120;
			}
				
			EXP1 = scale(EXP1, -0.1);
			EXP1 = clamp_result(EXP1, 600);
			HP1 = clamp_result(HP1, 666);
			
			//cout << HP1 << ' ' << EXP1 << ' ' << M1 << ' ' << m1_ori << '\n';
			
			if (check_m1(M1, m1_ori, E2)) break;
			
			if (!e2_odd) break;
		}
				
		HP1  = scale(HP1,  -0.17);
		EXP1 = scale(EXP1,  0.17);
		EXP1 = clamp_result(EXP1, 600);
		
		//cout << HP1 << ' ' << EXP1 << ' ' << M1 << '\n';
		
		
		int S = nearest_perfect_square(EXP1);
		P2 = (EXP1 >= S)? (1.0) : (((double)EXP1 / (double)S + 80.0) / 123.0);

	}
	
	// cout << HP1 << ' ' << EXP1 << ' ' << M1 << '\n';
	
	// Road 3
	double P3 = 0.0;
	{
		const double Parray[] = {0.32, 0.47, 0.28, 0.79, 1.0, 0.5, 0.22, 0.83, 0.64, 0.11};
		int i = 0;
		
		if (E2 < 10) {
			
			i = E2;
			
		} else {
			
			i = ( E2 / 10 + (E2 % 10) ) % 10;
			
			
		}
		
		// cout << i << '\n';
		P3 = Parray[i];
	}
	
	
	//cout << P1 << ' ' << P2 << ' ' << P3 << '\n';
	
	if (P1 == 1.0 && P1 == P2 && P1 == P3) {
		EXP1 = scale(EXP1, -0.25);
	
	} else {
	
		double Paverage = (P1 + P2 + P3) / 3.0;

		if (Paverage < 0.5) {
			HP1  = scale(HP1 , -0.15);
			EXP1 = scale(EXP1,  0.15);
		} else {
			HP1  = scale(HP1,  -0.1);
			EXP1 = scale(EXP1,  0.2);
		}
	
	}
	EXP1 = clamp_result(EXP1, 600);
	HP1 = clamp_result(HP1, 666);
	M1 = clamp_result(M1, 3000);
	
    return HP1 + EXP1 + M1;
}

int stage_sum(int x) {
	while (x >= 10) {
		int o = 0;
		while (x > 0) {
			o += x % 10;
			x /= 10;
		}
		x = o;
	}
	return x;
}

bool in_bound(int i, int j) {
	return 
		i >= 0 &&
		i < 10 &&
		j >= 0 &&
		j < 10
	;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {

	if (E3 < 0 || E3 > 99) {
    	return -99;	
   	}

 	EXP1 = clamp_result(EXP1, 600);
	HP1 = clamp_result(HP1, 666);
	
	EXP2 = clamp_result(EXP2, 600);
	HP2 = clamp_result(HP2, 666);
    
    int matrix[10][10];
    for (int i = 0; i < 10; i++) {
	    for (int j = 0; j < 10; j++) {
    		matrix[i][j] = (E3*j + i*2)*(i-j);
    		// cout << matrix[i][j] << '\t';
    	}
    	// cout << '\n';
    }
    
    int num_of_greater = 0;
    int num_of_lesser  = 0;
    for (int i = 0; i < 10; i++) {
	    for (int j = 0; j < 10; j++) {
    		num_of_greater += (matrix[i][j] >  E3*2);
    		num_of_lesser  += (matrix[i][j] < -E3  );
    	}
    }
    
    // cout << num_of_greater << '\n' << num_of_lesser << '\n';
    
    int i = stage_sum(num_of_greater);
    int j = stage_sum(num_of_lesser );
    
    // cout << i << ' ' << j << '\n';
    
    int taxi_grade		= matrix[i][j];
    int sherlock_grade 	= matrix[i][j];
    
    {
    	int i_ = i-1, j_ = j-1;
    	// Left diag
    	while (in_bound(i_, j_)) {
    		
    		sherlock_grade = max(sherlock_grade, matrix[i_][j_]);
    		
    		i_ -= 1;
    		j_ -= 1;
    	}
    	
    	i_ = i+1; j_ = j+1;

    	while (in_bound(i_, j_)) {
    		
    		sherlock_grade = max(sherlock_grade, matrix[i_][j_]);
    		
    		i_ += 1;
    		j_ += 1;
    	}
    	
    	// Right diag
    	i_ = i+1; j_ = j-1;

    	while (in_bound(i_, j_)) {
    		
    		sherlock_grade = max(sherlock_grade, matrix[i_][j_]);
    		
    		i_ += 1;
    		j_ -= 1;
    	}
    	
    	i_ = i-1; j_ = j+1;

    	while (in_bound(i_, j_)) {
    		
    		sherlock_grade = max(sherlock_grade, matrix[i_][j_]);
    		
    		i_ -= 1;
    		j_ += 1;
    	}
    }
    
    // cout << taxi_grade << ' ' << sherlock_grade << '\n';
        
    if (abs(taxi_grade) > sherlock_grade) {
    	EXP1 = scale(EXP1, - 0.12);
    	HP1  = scale(HP1,  - 0.1);
    	
    	EXP2 = scale(EXP2, - 0.12);
    	HP2  = scale(HP2,  - 0.1);
    } else {
    	EXP1 = scale(EXP1, + 0.12);
    	HP1  = scale(HP1,  + 0.1);
    	
    	EXP2 = scale(EXP2, + 0.12);
    	HP2  = scale(HP2,  + 0.1);
    	
    	EXP1 = clamp_result(EXP1, 600);
    	HP1 = clamp_result(HP1, 666);
    	
    	EXP2 = clamp_result(EXP2, 600);
    	HP2 = clamp_result(HP2, 666);
    }
    
    return (abs(taxi_grade) > sherlock_grade)?(taxi_grade):(sherlock_grade);
}

// Task 4
int checkPassword(const char * s, const char * email) {
    
    
    size_t l = strlen(s);
    if (l < 8) return -1;
    if (l > 20) return -2;

	int length = 0;
	int consecutive = 0;	
	int se = 0;
	
	for (const char *c = s; *c; c++) {
		
		if (email[0] == *c) {
			
			const char* j = email;
			const char* i = c;
			
			while (*j && *i && *j == *i) {
			
				if (*(j+1) == '@') {
					return -300 - (int)(c - s - se);
				}
				
				i++;
				j++;
			
				// cout << *i;
			}
			
			// cout << '\n';
		}
		
		
		//  cout << *c << ' ' << email[se] << '\n';
	}
	
	for (const char* c = s+2; *c; c++) {	
		if (*(c-2) == *(c-1) && *(c-1) == *c) {
			return -400 - ((int)(c - s) -2);
		}
	}
	
	bool no_special = true;
	bool has_invalid = false;
	
	for (const char* c = s; *c; c++) {
		switch (*c) {
			case '@':
			case '#':
			case '%':
			case '$': 
			case '!':
				no_special = false;
				break;
			
			default: 
				// if c is not a special character nor an
				// alphanumeric, return immediately.
				if (!isalnum(*c)) {
					return (int)(c - s);
				}
		}
	}
	
	if (no_special) {
		return -5;
	}
	
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    
    const int l = 30;
    
    int occurrences[l];
    for (int i = 0; i < l; i++) occurrences[i] = 1;
	
	for (int i = 0; i < num_pwds-1; i++) {
		
		if (occurrences[i] == 0) continue;
		
		for (int j = i+1; j < num_pwds; j++) {
			if (!strcmp(arr_pwds[i], arr_pwds[j])) {
				occurrences[i] += 1;
				occurrences[j]  = 0;
			}
		}
	}
	
	/*for (int i = 0; i < num_pwds; i++) {
		cout << occurrences[i] << ' ';
	}
	cout << '\n';*/
	

	int max_occurrence = 1;
	for (int i = 0; i < num_pwds; i++) {
		if (max_occurrence < occurrences[i]) {
			max_occurrence = occurrences[i];
		}
	}

	int max_length = 0;
	int correct_password_index = 0;
	for (int i = 0; i < num_pwds; i++) {
		
		int l = strlen(arr_pwds[i]);
		
		if (
			max_occurrence == occurrences[i] && 
			max_length < l
		) {
			max_length = l;
			correct_password_index = i;
		}
	}
	
    return correct_password_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
