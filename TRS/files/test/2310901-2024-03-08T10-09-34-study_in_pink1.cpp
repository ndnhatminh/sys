#include "study_in_pink1.h"

bool readFile(
	const string& filename,
	int& HP1,
	int& HP2,
	int& EXP1,
	int& EXP2,
	int& M1,
	int& M2,
	int& E1,
	int& E2,
	int& E3
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

int CHECK_HP(int& hp) {               // ham check hp
	if (hp > 666) hp = 666;
	else if (hp < 0) hp = 0;
	return hp;
}
int CHECK_EXP(int& exp) {            // ham check exp
	if (exp > 600) exp = 600;
	else if (exp < 0) exp = 0;
	return exp;
}
int CHECK_M(int& m) {               // ham check m
	if (m > 3000) m = 3000;
	else if (m < 0) m = 0;
	return m;
}
// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
	// TODO: Complete this function
	int d;
	if (e1 < 0 || e1 > 99) return -99;
	else {
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
				exp2 = exp2 + 29 + 45 + 75;
				break;
			}
			d = e1 * 3 + exp1 * 7;
			if (d % 2 == 0) exp1 = ceilf(exp1 + d / 200.0);
			else exp1 = ceilf(exp1 - d / 100.0);
		}
		else {
			if (e1 <= 19)  exp2 = exp2 + ceilf(e1 / 4.0 + 19);
			else if (e1 <= 49) exp2 = exp2 + ceilf(e1 / 9.0 + 21);
			else if (e1 <= 65) exp2 = exp2 + ceilf(e1 / 16.0 + 17);
			else if (e1 <= 79) {
				exp2 = exp2 + ceilf(e1 / 4.0 + 19);
				exp2 = CHECK_EXP(exp2);
				if (exp2 > 200) exp2 = exp2 + ceilf(e1 / 9.0 + 21);
			}
			else if (e1 <= 99) {
				exp2 = exp2 + ceilf(e1 / 4.0 + 19) + ceilf(e1 / 9.0 + 21);
				CHECK_EXP(exp2);
				if (exp2 > 400) exp2 = ceilf(1.15 * (exp2 + ceilf(e1 / 16.0 + 17)));

			}
			exp1 -= e1;
		}


		CHECK_EXP(exp1);
		CHECK_EXP(exp2);
		return  exp1 + exp2;
	}
}
// TASK2
double CALCULATE_P1_P2(int& EXP1) {          // ham tinh xac suat p1, p2
	int  s1, t, i;
	float s, ptb;                         // t la phan nguyen can bac 2 cua EXP1
	double p;
	s1 = ceilf(sqrt(EXP1)) * ceilf(sqrt(EXP1));
	t = sqrt(EXP1);
	s = t * t;
	if ((s1 - EXP1) < (EXP1 - s)) s = s1;
	if (EXP1 >= s) p = 100;
	else p = round(100 * (EXP1 / s + 80) / 123);
	return p;
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
	int arrP[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
	int M1_const, sum, tens, j;                //M1_const là giá tri M1 ban dau                    
	double p1, p2, p3;
	float ptb;
	M1_const = M1;
	// con duong 1
	p1 = CALCULATE_P1_P2(EXP1);
	// con duong 2
	if (E2 < 0 || E2>99) return -99;
	else {
		if (E2 % 2 == 1) {
			while (M1 >= 0.5 * M1_const) {
				if (HP1 < 200) {
					HP1 = ceilf(HP1 * 1.3);
					M1 -= 150;
				}
				else {
					HP1 = ceilf(HP1 * 1.1);
					M1 -= 70;
				}
				CHECK_HP(HP1);
				CHECK_M(M1);
				if (M1 < 0.5 * M1_const) break;
				if (EXP1 < 400)
					M1 -= 200;
				else M1 -= 120;
				EXP1 = ceilf(EXP1 * 1.13);

				CHECK_M(M1);
				CHECK_EXP(EXP1);
				if (M1 < 0.5 * M1_const) break;
				if (EXP1 < 300) M1 -= 100;
				else M1 -= 120;

				EXP1 = ceilf(EXP1 * 0.9);
				CHECK_EXP(EXP1);
				CHECK_M(M1);
				if (M1 < 0.5 * M1_const) break;
			}
		}
		else {
			for (int i = 1;i < 2;i++) {
				if (HP1 < 200) {
					HP1 = ceilf(HP1 * 1.3);
					M1 -= 150;
				}
				else {
					HP1 = ceilf(HP1 * 1.1);
					M1 -= 70;
				}
				CHECK_HP(HP1);
				CHECK_M(M1);
				if (M1 == 0) break;
				if (EXP1 < 400) M1 -= 200;
				else M1 -= 120;
				EXP1 = ceilf(EXP1 * 1.13);
				CHECK_M(M1);
				CHECK_EXP(EXP1);
				if (M1 == 0) break;
				if (EXP1 < 300) M1 -= 100;
				else M1 -= 120;
				EXP1 = ceilf(EXP1 * 0.9);
				CHECK_EXP(EXP1);
				CHECK_M(M1);
			}
		}
		HP1 = ceilf(HP1 * 0.83);
		EXP1 = ceilf(EXP1 * 1.17);
		CHECK_HP(HP1);
		CHECK_EXP(EXP1);
		p2 = CALCULATE_P1_P2(EXP1);
		// con duong 3
		tens = E2 / 10;
		sum = tens + (E2 % 10); // tens la chu so hang chuc cua E2, sum la tong 2 chu so cua E
		j = sum % 10;
		p3 = arrP[j];
	}
	ptb = (p1 + p2 + p3) / 3;

	if (ptb == 100)
		EXP1 = ceilf(EXP1 * 0.75);
	else if (ptb < 50) {
		HP1 = ceilf(HP1 * 0.85);
		EXP1 = ceilf(EXP1 * 1.15);
		CHECK_HP(HP1);
		CHECK_EXP(EXP1);
	}
	else {
		HP1 = ceilf(HP1 * 0.9);
		EXP1 = ceilf(EXP1 * 1.2);
		CHECK_HP(HP1);
		CHECK_EXP(EXP1);
	}

	return  HP1 + EXP1 + M1;
}
// Task 3
int CALCULATE_I_J(int& m) {
	while (m >= 10)
		m = m / 10 + m % 10;
	return m;
}
int CHECK_LEFT1(int m, int n, int& holmes, int array[10][10]) {
	while (m >= 0 && n >= 0) {
		if (array[m][n] >= holmes) {
			holmes = array[m][n];
		}
		m--;
		n--;
	}
	return holmes;
}
int CHECK_LEFT2(int m, int n, int& holmes, int array[10][10]) {
	while (m < 10 && n < 10) {
		if (array[m][n] >= holmes) {
			holmes = array[m][n];
		}
		m++;
		n++;
	}
	return holmes;
}
int CHECK_RIGHT1(int m, int n, int& holmes, int array[10][10]) {
	while (m < 10 && n >= 0) {
		if (array[m][n] >= holmes) {
			holmes = array[m][n];
		}
		m++;
		n--;
	}
	return holmes;
}
int CHECK_RIGHT2(int m, int n, int& holmes, int array[10][10]) {
	while (m >= 0 && n < 10) {
		if (array[m][n] >= holmes) {
			holmes = array[m][n];
		}
		m--;
		n++;
	}
	return holmes;
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
	// TODO: Complete this function
	int array[10][10];
	int m = 0, n = 0, a, b, taxi, holmes;
	if (E3 < 0 || E3 > 99) return -99;
	else {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				array[i][j] = ((E3 * j) + (i * 2)) * (i - j);
				if (array[i][j] > E3 * 2) m++;
				if (array[i][j] < -E3) n++;
			}
		}
		a = CALCULATE_I_J(m);
		b = CALCULATE_I_J(n);
		taxi = array[a][b];
		holmes = array[m][n];
		CHECK_LEFT2(a, b, holmes, array);
		CHECK_LEFT1(a, b, holmes, array);
		CHECK_RIGHT1(a, b, holmes, array);
		CHECK_RIGHT2(a, b, holmes, array);
		if (abs(taxi) > holmes) {
			holmes = taxi;
			EXP1 = ceilf(EXP1 * 0.88);
			HP1 = ceilf(HP1 * 0.9);
			EXP2 = ceilf(EXP2 * 0.88);
			HP2 = ceilf(HP2 * 0.9);
		}
		else {
			EXP1 = ceilf(EXP1 * 1.12);
			HP1 = ceilf(HP1 * 1.1);
			EXP2 = ceilf(EXP2 * 1.12);
			HP2 = ceilf(HP2 * 1.1);
		}
		CHECK_EXP(EXP1);
		CHECK_HP(HP1);
		CHECK_EXP(EXP2);
		CHECK_HP(HP2);
	}
	return holmes;
}


// Task 4
int checkPassword(const char *s, const char *email) {
	string s1(s);
    string se;
    int x = -10;
    int vt1 = -1;
    int size1, size2, count = 0;
    size1 = strlen(s);
    size2 = strlen(email);
    for (int i = 0; i < size2; i++) {
        if (email[i] != '@') {
            se += email[i];
        } else {
            break;
        }
    }
    if (size1 < 8) {
        x = -1;
    } else if (size1 > 20) {
        x = -2;
    } else {
        vt1 = s1.find(se);
        if(vt1!=-1) x=-300-vt1;
        else{
        for (int i = 0; i < size1; i++) {
            if (s[i - 1] == s[i] && s[i] == s[i + 1]) {
                x= -400-i + 1;
                break;
            }}
            if (x==-10){
        for (int i = 0; i < size1; i++) {
            if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
                break;
            } else {
                count++;
            }}
        if (count == size1) {
            x = -5;}
    }
        if(x==-10){
        for (int i = 0; i < size1; i++) {
        if(s[i]<33||s[i]>37&&s[i]<48||s[i]>57&&s[i]<64||s[i]>90&&s[i]<97||s[i]>122||s[i]==34){
        	x=i;
        	break;}
		}}
        }}
    return x;
	}



// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int maxappear = 0;
    int Index = -1;
    int maxLength = 0;
    for (int i = 0; i < num_pwds; i++) {
        int count = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
            
			 count++;}
        }
        if (count > maxappear || (count == maxappear && strlen(arr_pwds[i]) > maxLength)) {
            maxappear = count;
            maxLength = strlen(arr_pwds[i]);
            Index = i;
        }
    }

    return Index;
}




////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////

