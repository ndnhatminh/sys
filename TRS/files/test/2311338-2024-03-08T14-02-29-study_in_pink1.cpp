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
int check(int a, int b, int c) {
    if(a<b) {
        return b;
    }
    else if(a>c) {
        return c;
    }
    else{return a;}
}
double chinhphuong(int n)  {
    int m = ceil(sqrt(n));
	int q = floor(sqrt(n));
	if (m*m == q*q) {
		return n; 
	} 
	else if (m*m-n > n-q*q) {
		return q*q; 
	} 
	else return m*m; 
}
int val(int i, int j, int E3) {
    return (E3 * j + 2 * i) * (i - j);
}
 
int them(int x, int per, int val) {
    int tmp = x * per / 100;
    if(tmp * 100 < per * x) tmp += val;
    return tmp;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;
exp1 = check(exp1, 0, 600);
exp2 = check(exp2, 0, 600);
double inform1, inform2, inform3;
inform1 = (e1/4) + 19;
inform2 = (e1/9) + 21;
inform3 = (e1/16) + 17;
double exp1_test = exp1; 
double exp2_test = exp2;
int D;
D = e1*3 + exp1*7; 
if(e1 >= 0 && e1 <=3) {
if(e1 == 0) {
    exp2 += 29 ;
}
if(e1 == 1) {
    exp2 += 45 ;
}
if(e1 == 2) {
    exp2 += 75;
}
if(e1 == 3) {
    exp2 += 149;
}
if(D % 2 == 0) {
     exp1_test = ceil(exp1_test + D/200);}
    else{ exp1_test = ceil(exp1_test - D /100);}
     exp1 = exp1_test;
}
if(e1 >= 4 && e1 <= 99) {
    if(e1 >= 4 && e1 <= 19) {
        exp2_test += inform1 ;
    }
    if(e1 >= 20 && e1 <= 49) {
        exp2_test += inform2;
    }    
    if(e1 >= 50 && e1 <= 65) {
        exp2_test += inform3;
    }
    if(e1 >= 66 && e1 <= 79) {
        exp2_test = ceil(exp2_test + inform1); 
        exp2 = exp2_test; 
        exp2 = check(exp2, 0, 600);
        exp2_test = exp2; 
        if (exp2_test > 200) {exp2_test += inform2;}
    }
    if(e1 >= 80 && e1 <= 99) {
        exp2 = exp2 + ceil(inform1);
        exp2 = check(exp2, 0, 600);
        exp2 = exp2 + ceil(inform2);
        exp2 = check(exp2, 0, 600);
        exp2_test = exp2;
        if (exp2_test > 400) {
        exp2_test = ceil(exp2_test + inform3);
        exp2 = exp2_test; 
        exp2 = check(exp2, 0, 600);
        exp2_test = exp2; 
        exp2_test = exp2_test * 1.15000;
    }

    }
    exp2_test = ceil(exp2_test*1.00001);
    exp2 = exp2_test;
    exp1_test = ceil(exp1_test - e1);
    exp1 = exp1_test;
}
    exp1 = check(exp1, 0, 600);
    exp2 = check(exp2, 0, 600);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & exp1, int & M1, int E2) {
    // TODO: Complete this function
 if(E2 < 0 || E2 > 99) return -99;
 HP1 = check(HP1, 0, 666);
 exp1 = check(exp1, 0, 600);
 M1 = check(M1, 0, 3000);
int Mt = 0;
double S = chinhphuong(exp1);
double P1;
double HP1_test = HP1;
double M1_test = M1;
double exp1_t = exp1; 
double Mt_test = Mt;
if(exp1 >= S) {
       P1 = 1;
    }
    else P1 = (exp1/S + 80)/123;
if(E2 % 2 == 0) {
        while(M1 > 0) {
    if(HP1 < 200) {
        HP1_test = HP1_test * 1.300000;
        M1_test -= 150;
    } 
    else {
        HP1_test = HP1_test * 1.100000;
        M1_test -= 170;
    }
        }
    HP1_test = check(HP1_test, 0, 666);
    M1 = M1_test;
    while(M1 > 0) {
    if(exp1 < 400) {
        M1_test -= 200;
    }
    else {
        M1_test -= 120;
    }
    }
    exp1_t = exp1_t * 1.130000;
    exp1_t = check(exp1_t, 0, 600);
    exp1 = exp1_t;
    M1 = M1_test;
    while(M1 > 0) {
    if(exp1 < 300) {
        M1_test -= 100;
    }
    else {
        M1_test -= 120;
    }
    }
    M1 = M1_test;
    exp1_t = exp1_t * 0.900000;
    exp1_t = check(exp1_t, 0, 600);
    exp1 = exp1_t;
}
    

    return HP1 + exp1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & exp1, int & HP2, int & exp2, int E3) {
    // TODO: Complete this function
 if(E3 < 0 || E3 > 99) return -99;
    HP1 = check(HP1, 0, 666);
    HP2 = check(HP2, 0, 666);
 
    exp1 = check(exp1, 0, 666);
    exp2 = check(exp2, 0, 666);
 
    int taxi[10][10];
    int Sher[10][10];
    int cheotrai[20], cheophai[20];
 
    for(int i = 0; i < 20; i++) {
        cheotrai[i] = -100000000;
        cheophai[i] = -100000000;
    }
 
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            taxi[i][j] = val(i, j, E3);
            cheophai[i + j] = min(cheophai[i + j], taxi[i][j]);
            cheotrai[i - j + 10] = min(cheotrai[i - j + 10], taxi[i][j]);
        }
    }
 
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            Sher[i][j] = abs(max(cheophai[i + j], cheotrai[i - j + 10]));
        }
    }
 
    int vt_i = 0, vt_j = 0;
 
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(taxi[i][j] > 2 * E3) vt_i++;
            if(taxi[i][j] < -E3) vt_j++;
        }
    }
    while(vt_i >= 10) {
        vt_i = vt_i / 10 + vt_i % 10;
    }
    while(vt_j >= 10) {
        vt_j = vt_j / 10 + vt_j % 10;
    }
 
    if(abs(taxi[vt_i][vt_j]) > Sher[vt_i][vt_j]) {
    
        exp1 += them(exp1, 12, 0);
        exp2 += them(exp2, 12, 0);
        HP1 += them(HP1, 10, 0);
        HP2 += them(HP2, 10, 0);
 
        HP1 = check(HP1, 0, 666);
        HP2 = check(HP2, 0, 666);
        exp1 = check(exp1, 0, 666);
        exp2 = check(exp2, 0, 666);
 
        return Sher[vt_i][vt_j];
    }
    else {
        exp1 -= them(exp1, 12, 1);
        exp2 -= them(exp2, 12, 1);
        HP1 -= them(HP1, 10, 1);
        HP2 -= them(HP2, 10, 1);
 
        HP1 = check(HP1, 0, 666);
        HP2 = check(HP2, 0, 666);
        exp1 = check(exp1, 0, 666);
        exp2 = check(exp2, 0, 666);
        return taxi[vt_i][vt_j];
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    const char* position = strchr(email, '@');
	char se[100];
	strncpy(se, email, position - email);
	se[position - email] = '\0';
	int len = strlen(s);
	if (len < 8) return -1;
	if (len > 20) return -2;
	if (strstr(s, se) != NULL) {
		return - (300 + (strstr(s, se) - s));
	}
	for (int i = 0; i < len; ++i) {
		if (s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') {
			return -5;
		}
	}
	for (int i = 0; i < len - 1; ++i) {
		for (int j = i + 1; j < len ; ++j) {
			if (s[i] == s[j]) {
				return -(400 + i);
			}
		}
	}
	return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int count[100] = {0};
	for (int i = 0; i < num_pwds; ++i) {
		for (int j = i + 1; j < num_pwds; ++j) {
			if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
				count[i]++;
			}
		}
	}
	int maxCount = count[0];
	int index = 0;
	for (int i = 1; i < num_pwds; ++i) {
		if (maxCount < count[i]) {
			maxCount = count[i];
			index = i;
		}
	}
	for (int i = 0; i < num_pwds; ++i) {
		if (count[i] == maxCount && strlen(arr_pwds[i]) > strlen(arr_pwds[index])) {
			index = i;
		}
	}
	return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////