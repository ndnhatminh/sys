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

int sochinhphuong( int S ){
	
	int temp1=S;
	int temp2=S;
	while( (sqrt(temp1) - int(sqrt(temp1)))!=0 ){
		temp1++;
	}
	while( (sqrt(temp2) - int(sqrt(temp2)))!=0 ){
		temp2--;
	}
	if (abs(S-temp1)>abs(S-temp2)) S=temp2;
	else S=temp1;
	
 return S;	
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
	if (e1 >= 0 && e1 <= 99) {

		if (exp1 < 0) exp1 = 0;
		if (exp1 > 600) exp1 = 600;
		if (exp2 < 0) exp2 = 0;
		if (exp2 > 600) exp2 = 600;

		if (e1 == 0) {
		    exp2 = exp2 + 29;
		}
			else if (e1 == 1) {
		    exp2 = exp2 + 45;
		}
			else if (e1 == 2) {
		    exp2 = exp2 + 75;
		}
			else if (e1 == 3) {
		    exp2 = exp2 + 29 + 45 + 75;
		}
		
		if (e1 >= 4 && e1 <= 19) {
		    exp2 = exp2 + e1 / 4.0 + 19 + 0.999;
		}
			else if (e1 >= 20 && e1 <= 49) {
		    exp2 = exp2 + e1 / 9.0 + 21 + 0.999;
		}
			else if (e1 >= 50 && e1 <= 65) {
		    exp2 = exp2 + e1 / 16.0 + 17 + 0.999;
		}
			else if (e1 >= 66 && e1 <= 79) {
		    exp2 = exp2 + e1 / 4.0 + 19 + 0.999;
		    
		if (exp2 > 200) {
		        exp2 = exp2 + e1 / 9.0 + 21 + 0.999;
		    }
		}
		else if (e1 >= 80 && e1 <= 99) {
		    exp2 = exp2 + e1 / 4.0 + 19 + 0.999;
		    exp2 = exp2 + e1 / 9.0 + 21 + 0.999;
		    
		if (exp2 > 400) {
		        exp2 = exp2 + e1 / 16.0 + 17 + 0.999;
		        exp2 = exp2 * 1.15 + 0.999;
		    }
		}
		
		if (exp1 < 0) exp1 = 0;
		if (exp1 > 600) exp1 = 600;
		if (exp2 < 0) exp2 = 0;
		if (exp2 > 600) exp2 = 600;
		
		if (e1 >= 0 && e1 <= 3) {
		    int D = e1 * 3 + exp1 * 7;
		
		    if (D % 2 == 0)
		        exp1 = exp1 + (D / 200.0) + 0.999;
		    else
		        exp1 = exp1 - (D / 100.0) + 0.999;
		}


		if (e1 >= 4 && e1 <= 99) {

			exp1 = exp1 - e1;

		}

		if (exp1 < 0) exp1 = 0;
		if (exp1 > 600) exp1 = 600;
		if (exp2 < 0) exp2 = 0;
		if (exp2 > 600) exp2 = 600;
	}
	else return -99;
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
		if (E2 >= 0 && E2 <= 99) {
	
			if (HP1 < 0) HP1 = 0;
			if (HP1 > 666) HP1 = 666;
			if (EXP1 < 0) EXP1 = 0;
			if (EXP1 > 600) EXP1 = 600;
			if (M1 < 0) M1 = 0;
			if (M1 > 3000) M1 = 3000;
	
			double P1=0;
			double P2=0;
			double P3=0;
			int S = sochinhphuong(EXP1);
			if (EXP1 >= S) P1 = 1;
			else P1 = (EXP1 * 1.0 / S + 80) / 123.0;
	
	
			double money = M1 / 2.0;
	
			if (E2 % 2 != 0) {
		    while (M1 > money) {
		    	if (M1 == 0) {
		            break;
		        }
		
		        if (HP1 < 200 && HP1 >= 0) {
		            HP1 = HP1 * 1.3 + 0.999;
		            M1 -= 150;
		        }
		        else {
		            HP1 = HP1 * 1.1 + 0.999;
		            M1 -= 70;
		        }
		        if (M1 > 3000) M1 = 3000;
		        if (HP1 < 0) HP1 = 0;
		        if (HP1 > 666) HP1 = 666;
		        if (M1 < money) break;
		
		        if (EXP1 < 400 && EXP1 >= 0) {
		            M1 -= 200;
		            EXP1 = EXP1 * 1.13 + 0.999;
		        }
		        else {
		            M1 -= 120;
		            EXP1 = EXP1 * 1.13 + 0.999;
		        }
		        if (EXP1 > 600) EXP1 = 600;
		        if (EXP1 < 0) EXP1 = 0;
		        if (M1 > 3000) M1 = 3000;
		        if (M1 < money) break;
		
		        if (EXP1 < 300 && EXP1 >= 0) {
		            M1 -= 100;
		            EXP1 = EXP1 * 0.9 + 0.999;
		        }
		        else {
		            M1 -= 120;
		            EXP1 = EXP1 * 0.9 + 0.999;
		        }
		        if (EXP1 > 600) EXP1 = 600;
		        if (EXP1 < 0) EXP1 = 0;
		        if (M1 > 3000) M1 = 3000;
		        if (M1 < money) break;
		    }
		}
		else {
		    for (int j = 0; j < 1; j++) {
		    	if (M1 == 0) {
		            break;
		        }
		
		        if (HP1 < 200 && HP1 >= 0) {
		            HP1 = HP1 * 1.3 + 0.999;
		            M1 -= 150;
		        }
		        else {
		            HP1 = HP1 * 1.1 + 0.999;
		            M1 -= 70;
		        }
		        if (HP1 < 0) HP1 = 0;
		        if (HP1 > 666) HP1 = 666;
		        if (M1 > 3000) M1 = 3000;
		        if (M1 <= 0) {
		            M1 = 0;
		            break;
		        }
		
		        if (EXP1 < 400 && EXP1 >= 0) {
		            M1 -= 200;
		            EXP1 = EXP1 * 1.13 + 0.999;
		        }
		        else {
		            M1 -= 120;
		            EXP1 = EXP1 * 1.13 + 0.999;
		        }
		        if (EXP1 > 600) EXP1 = 600;
		        if (EXP1 < 0) EXP1 = 0;
		        if (M1 > 3000) M1 = 3000;
		        if (M1 <= 0) {
		            M1 = 0;
		            break;
		        }
		
		        if (EXP1 < 300 && EXP1 >= 0) {
		            M1 -= 100;
		            EXP1 = EXP1 * 0.9 + 0.999;
		        }
		        else {
		            M1 -= 120;
		            EXP1 = EXP1 * 0.9 + 0.999;
		        }
		        if (EXP1 > 600) EXP1 = 600;
		        if (EXP1 < 0) EXP1 = 0;
		        if (M1 > 3000) M1 = 3000;
		        if (M1 <= 0) {
		            M1 = 0;
		            break;
		        }
		    }
	}

		HP1 = HP1 * 0.83+0.999;
		EXP1 = EXP1 * 1.17+0.999;
		if (HP1 < 0) HP1 = 0;
		if (HP1 > 666) HP1 = 666;
		if (EXP1 < 0) EXP1 = 0;
		if (EXP1 > 600) EXP1 = 600;
		
		S = sochinhphuong(EXP1);
		
		

		if (EXP1 >= S) P2 = 1;
		else P2 = (EXP1 * 1.0 / S + 80) / 123.0;

		int P[10] = { 32,47,28,79,100,50,22,83,64,11 };
		double Ptb=0;
		int i=0;

		if (E2 < 10) {
			i = E2;
		}
		else {
			int chuc = E2 / 10;
			int donvi = E2 % 10;
			if ((donvi + chuc) < 10) {
				i = donvi + chuc;
			}
			else {
				i = (donvi + chuc) % 10;
			}
		}

		P3 = P[i]*1.0/100;

		if (P1 == 1 && P2 == 1 && P3 == 1) {
			EXP1 = EXP1 * 0.75+0.999;
		}
		else {
			Ptb = ((P1 + P2 + P3) * 1.0 / 3);
			if (Ptb < 0.5) {
				HP1 = HP1 * 0.85+0.999;
				EXP1 = EXP1 * 1.15+0.999;
			}
			else {
				HP1 = HP1 * 0.9+0.999;
				EXP1 = EXP1 * 1.2+0.999;
			}
		}


		if (HP1 < 0) HP1 = 0;
		if (HP1 > 666) HP1 = 666;
		if (EXP1 < 0) EXP1 = 0;
		if (EXP1 > 600) EXP1 = 600;
		if (M1 < 0) M1 = 0;
		if (M1 > 3000) M1 = 3000;
	}
	else return -99;

	return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
	if (E3 >= 0 && E3 <= 99) {

		int tx = 0, ty = 0;
		int x, y;
		int ex3[10][10];
		int temp1, temp2;
		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j <= 9; j++) {
				ex3[i][j] = ((E3 * j) + (i * 2)) * (i - j);
			}
		}

		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j <= 9; j++) {
				if (ex3[i][j] > (E3 * 2)) tx++;
				if (ex3[i][j] < (E3 - (E3 * 2))) ty++;
			}
		}

		x = tx / 10 + tx % 10;
		if (x > 9) {
			x = x / 10 + x % 10;
		}

		y = ty / 10 + ty % 10;
		if (y > 9) {
			y = y / 10 + y % 10;
		}

		int max = ex3[x][y];
		temp1 = x;
		temp2 = y;
		while (temp1 >= 0 && temp1 <= 9 && temp2 >= 0 && temp2 <= 9) {
			if (ex3[temp1][temp2] > max) max = ex3[temp1][temp2];
			temp1--;
			temp2++;
		}
		temp1 = x;
		temp2 = y;
		while (temp1 >= 0 && temp1 <= 9 && temp2 >= 0 && temp2 <= 9) {
			if (ex3[temp1][temp2] > max) max = ex3[temp1][temp2];
			temp1++;
			temp2--;
		}
		temp1 = x;
		temp2 = y;

		while (temp1 >= 0 && temp1 <= 9 && temp2 >= 0 && temp2 <= 9) {
			if (ex3[temp1][temp2] > max) max = ex3[temp1][temp2];
			temp1--;
			temp2--;
		}
		temp1 = x;
		temp2 = y;

		while (temp1 >= 0 && temp1 <= 9 && temp2 >= 0 && temp2 <= 9) {
			if (ex3[temp1][temp2] > max) max = ex3[temp1][temp2];
			temp1++;
			temp2++;
		}
		
		if (max<0) max=abs(max);
		if (HP1 < 0) HP1 = 0;
		if (HP1 > 666) HP1 = 666;
		if (HP2 < 0) HP2 = 0;
		if (HP2 > 666) HP2 = 666;
		if (EXP1 < 0) EXP1 = 0;
		if (EXP1 > 600) EXP1 = 600;
		if (EXP2 < 0) EXP2 = 0;
		if (EXP2 > 600) EXP2 = 600;

		if (max >= abs(ex3[x][y])) {
			EXP1 = EXP1 * 1.12 + 0.999;
			EXP2 = EXP2 * 1.12 + 0.999;
			HP1 = HP1 * 1.1 + 0.999;
			HP2 = HP2 * 1.1 + 0.999;
			if (HP1 < 0) HP1 = 0;
			if (HP1 > 666) HP1 = 666;
			if (HP2 < 0) HP2 = 0;
			if (HP2 > 666) HP2 = 666;
			if (EXP1 < 0) EXP1 = 0;
			if (EXP1 > 600) EXP1 = 600;
			if (EXP2 < 0) EXP2 = 0;
			if (EXP2 > 600) EXP2 = 600;
			return max;

		}
		else {
			EXP1 = EXP1 * 0.88 + 0.999;
			EXP2 = EXP2 * 0.88 + 0.999;
			HP1 = HP1 * 0.9 + 0.999;
			HP2 = HP2 * 0.9 + 0.999;
			if (HP1 < 0) HP1 = 0;
			if (HP1 > 666) HP1 = 666;
			if (HP2 < 0) HP2 = 0;
			if (HP2 > 666) HP2 = 666;
			if (EXP1 < 0) EXP1 = 0;
			if (EXP1 > 600) EXP1 = 600;
			if (EXP2 < 0) EXP2 = 0;
			if (EXP2 > 600) EXP2 = 600;
			return ex3[x][y];
		}
	}
	else return -99;
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
	char se[100]={0} ;

    if (strlen(s) < 8) return -1;
    if (strlen(s) > 20) return -2;

    int i = 0;
	while (email[i] != '@') {
		se[i] = email[i];
		i++;
	}

	if (strstr(s, se)) {
		return -(300 + strstr(s, se)-s);
	}

    for (int i = 0; i < strlen(s) - 1; i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2] ) {
            return -(400 + i);
        }
    }

    int t = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            t++;
        }
    }
    if (t == 0) return -5;

    for (int i = 0; i < strlen(s); i++) {
        if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))) {
            return i;
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
	int counter[100] = { 0 };
    int size[100] = { 0 };

   
    for (int i = 0; i < num_pwds; i++) {
        size[i] = strlen(arr_pwds[i]);
        for (int j = 0; j < num_pwds; j++) {
            if ( strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                counter[i]++;
            }
        }
    }

  	int max_count = 0;
	int max_size = 0;

	for (int i = 0; i < num_pwds; i++) {
        if (counter[i] > max_count) max_count = counter[i];
    }
    
    for (int i = 0; i < num_pwds; i++) {
        if (counter[i] == max_count) {
        	if (size[i] > max_size) {
            	max_size = size[i];
        	}
    	}
	}


	for (int i = 0; i < num_pwds; i++) {
		if (counter[i] == max_count && size[i] == max_size) {
			return i;
		}
	}

	for (int i = 0; i < num_pwds; i++) {
		if (counter[i] == max_count) {
			return i;
		}
	}
    return -1;
} 

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////