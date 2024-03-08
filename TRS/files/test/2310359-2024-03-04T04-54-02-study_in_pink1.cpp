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

int new_ceil(double x) {
	return (int)(x + 0.999);
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

    if (e1 < 0 || e1 > 99) return -99;
	
	if (0 <= e1 && e1 <= 3) {
		if (e1 == 0) exp2 += 29;
		else if (e1 == 1) exp2 += 45;
		else if (e1 == 2) exp2 += 75;
		else if (e1 == 3) exp2 += 29 + 45 + 75;
		if (exp2 > 600) exp2 = 600;

		double D = e1*3 + exp1*7;

		if ((int)D % 2 == 0) exp1 = (int)new_ceil(exp1 + D / 200.0);
		else exp1 = (int)new_ceil(exp1 - D / 100.0);
		if (exp1 > 600) exp1 = 600;
		if (exp1 < 0) exp1 = 0;

        return exp1 + exp2;
	} else if (4 <= e1 && e1 <= 99) {
		if (4 <= e1 && e1 <= 19) {
			exp2 = (int)new_ceil(exp2 + double(e1) / 4.0 + 19);
		} else if (20 <= e1 && e1 <= 49) {
			exp2 = (int)new_ceil(exp2 + double(e1) / 9.0 + 21);
		} else if (50 <= e1 && e1 <= 65) {
			exp2 = (int)new_ceil(exp2 + double(e1) / 16.0 + 17);
		} else if (66 <= e1 && e1 <= 79) {
			exp2 = (int)new_ceil(exp2 + double(e1) / 4.0 + 19);
			if (exp2 > 600) exp2 = 600;
			if (exp2 > 200) exp2 = (int)new_ceil(exp2 + double(e1) / 9.0 + 21);
		} else if (80 <= e1 && e1 <= 99) {
			exp2 = (int)new_ceil(exp2 + double(e1) / 4.0 + 19);
			exp2 = (int)new_ceil(exp2 + double(e1) / 9.0 + 21);
			if (exp2 > 600) exp2 = 600;
			if (exp2 > 400) {
				exp2 = (int)new_ceil(exp2 + double(e1) / 16.0 + 17);
				if (exp2 > 600) exp2 = 600;
				exp2 = (int)new_ceil(exp2 * 1.15);
				if (exp2 > 600) exp2 = 600;
			}
		}
		if (exp2 > 600) exp2 = 600;

        exp1 -= e1;
	    if (exp1 < 0) exp1 = 0;

        return exp1 + exp2;
	}

    return -99;
}

// Task 2

int EVENT1(int &HP1, int &M1) {
	if (HP1 < 200) {
		HP1 = new_ceil(HP1 * 1.3);
		M1 -= 150; 
		if (M1 < 0) M1 = 0;
		if (HP1 > 666) HP1 = 666;
		return 150;
	} else {
		HP1 = new_ceil(HP1 * 1.1);
		M1 -= 70;
		if (M1 < 0) M1 = 0;
		if (HP1 > 666) HP1 = 666;
		return 70;
	}
}

int EVENT2(int &EXP1, int &M1) {
	if (EXP1 < 400) {
		M1 -= 200;
		if (M1 < 0) M1 = 0;
		EXP1 = new_ceil(EXP1 * 1.13);
		if (EXP1 > 600) EXP1 = 600;
		return 200;
	} else {
		M1 -= 120;
		if (M1 < 0) M1 = 0;
		EXP1 = new_ceil(EXP1 * 1.13);
		if (EXP1 > 600) EXP1 = 600;
		return 120;
	}
}

int EVENT3(int &EXP1, int &M1) {
	if (EXP1 < 300) {
		M1 -= 100; if (M1 < 0) M1 = 0;
		EXP1 = new_ceil(EXP1 * 0.9);
		return 100;
	} else {
		M1 -= 120; if (M1 < 0) M1 = 0;
		EXP1 = new_ceil(EXP1 * 0.9);
		return 120;
	}
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    if (E2 < 0 || E2 > 99) return -99;
	
	long long S = sqrt(EXP1);
	if (EXP1 - S*S < (S+1)*(S+1) - EXP1) {
		S = S*S;
	} else S = (S+1)*(S+1);

	double P1;
	if (EXP1 >= S) P1 = 100;
	else P1 = (double(EXP1)/double(S) + 80) / 123 * 100;

	// con duong 2

	if (E2 % 2 == 1) {
		int initial = M1;
		int spent = 0;
		while (spent * 2 <= initial) {
			// mua thuc an nuoc uong
			//cout << "EVENT 1\n";
			spent += EVENT1(HP1, M1);
			if (spent * 2 > initial) break;

			//cout << "EVENT 2\n";
			spent += EVENT2(EXP1, M1);
			if (spent * 2 > initial) break;

			// ten vo gia cu
			//cout << "EVENT 3\n";
			spent += EVENT3(EXP1, M1);
			if (spent * 2 > initial) break;
		}
	} else {
        for (int i = 1; i <= 1; i++) {
            EVENT1(HP1, M1); if (!M1) break;
            EVENT2(EXP1, M1); if (!M1) break;
            EVENT3(EXP1, M1); if (!M1) break;
        }
	}

	HP1 = new_ceil(HP1 * 0.83);
	EXP1 = new_ceil(EXP1 * 1.17);
	if (EXP1 > 600) EXP1 = 600;

	S = sqrt(EXP1);
	if (EXP1 - S*S < (S+1)*(S+1) - EXP1) {
		S = S*S;
	} else S = (S+1)*(S+1);

	double P2;
	if (EXP1 >= S) P2 = 100;
	else P2 = (double(EXP1)/(double)S + 80) / 123 * 100;

	int PPP[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
	double P3;
	if (E2 <= 9) P3 = PPP[E2];
	else P3 = PPP[((E2 % 10) + (E2 / 10)) % 10];

	if ((int)P1 == 100 && (int)P2 == 100 && (int)P3 == 100) {
		EXP1 = new_ceil(EXP1 * .75);
	} else {
		double AVG = (P1 + P2 + P3) / 3.0;

		if ((int)AVG < 50) {
			HP1 = new_ceil(HP1 * .85);
			EXP1 = new_ceil(EXP1 * 1.15);
			if (EXP1 > 600) EXP1 = 600;
		} else {
			HP1 = new_ceil(HP1 * 0.9);
			EXP1 = new_ceil(EXP1 * 1.2);
			if (EXP1 > 600) EXP1 = 600;
		}
	}

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

    if (E3 < 0 || E3 > 99) return -99;
	
	int i = 0, j = 0;

    int mat[10][10];
    for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
	    	mat[x][y] = ((E3*y) + (x*2))*(x-y);
			if (mat[x][y] > E3 * 2) i++;
			if (mat[x][y] < -E3) j++;
		}
    }

	while (i > 9) i = i/10 + i%10; while (j > 9) j = j/10 + j%10;

	int points = mat[i][j];
	for (int x = i - min(i,j), y = j - min(i,j); x < 10 && y < 10; x++, y++) points = max(points, mat[x][y]);
	for (int x = i - min(i,9-j), y = j + min(i,9-j); x < 10 && y >= 0; x++, y--) points = max(points, mat[x][y]); 

	int taxi_points = abs(mat[i][j]);

	if (taxi_points > points) {
		EXP1 = new_ceil(EXP1 * 0.88); HP1 = new_ceil(HP1 * 0.9);
		EXP2 = new_ceil(EXP2 * 0.88); HP2 = new_ceil(HP2 * 0.9);
		return mat[i][j];
	} else {
		EXP1 = new_ceil(EXP1 * 1.12); HP1 = new_ceil(HP1 * 1.1);
		EXP2 = new_ceil(EXP2 * 1.12); HP2 = new_ceil(HP2 * 1.1);
        if (EXP1 > 600) EXP1 = 600;
        if (EXP2 > 600) EXP2 = 600;
        if (HP1 > 666) HP1 = 666;
        if (HP2 > 666) HP2 = 666;
		return points;
	}
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
	
	string se = "";

	for (int i = 0; i < strlen(email); i++) {
		if (email[i] == '@') break;
		se = se + email[i];
	}

	if (strlen(s) < 8) return -1;
	if (strlen(s) > 20) return -2;

	{
        if (se.size() == 0) return -300;

		//cout << se << endl;
		//cout << s << endl;
		for (int i = 0, s_len = strlen(s); i + se.size() - 1 < s_len; i++) {
			bool ok = false;
			for (int j = 0; j < se.size(); j++) {
				if (s[i + j] != se[j]) {ok = true; break;}
			}

			if (!ok) {
				return -300 - i;
			}
		}
	}

	{
		for (int i = 0, s_len = strlen(s); i < s_len - 2; i++) {
			if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
				return -400 - i;
			}
		}
	}


	{
		bool ok = false;

		for (int i = 0; i < strlen(s); i++) {
			if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
				ok = true;
				break;
			}
		}

		if (!ok) return -5;
	}

	{
		for (int i = 0, s_len = strlen(s); i < s_len; i++) {
			if ('0' <= s[i] && s[i] <= '9') {}
			else if ('a' <= s[i] && s[i] <= 'z') {}
			else if ('A' <= s[i] && s[i] <= 'Z') {}
			else if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {}
			else {
				return i;
			}
		}
	}

	return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
	
	int cnt[num_pwds];
	for (int i = 0; i < num_pwds; i++) cnt[i] = 0;

	for (int i = 0; i < num_pwds; i++) {
		for (int j = 0; j <= i; j++) {
			if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
				cnt[j]++;
			}
		}
	}

	int res = 0;
	for (int i = 1; i < num_pwds; i++) {
		if (cnt[i] == 0) continue;

		if (cnt[i] > cnt[res] || (cnt[i] == cnt[res] && strlen(arr_pwds[i]) > strlen(arr_pwds[res]))) {
			res = i;
		}
	}

    return res;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
