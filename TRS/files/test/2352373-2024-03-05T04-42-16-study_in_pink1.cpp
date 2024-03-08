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

int raise_up(float& c) {
	return c+0.9999;
}
int fix(int& value, int min_value, int max_value) {
	if (value < min_value)
		return min_value;
	else if (value > max_value)
		return max_value;
	else
		return value;
}
void fix_HP(int & HP) {
	HP = fix(HP, 0, 666);
}

void fix_EXP(int & EXP) {
    EXP = fix(EXP, 0, 600);
}

void fix_M(int& M) {
	M = fix(M, 0, 3000);
}
int calculate(int& b, float So_lan) {
	float a = b * So_lan;
	b = raise_up(a);
	return b;
}
void event1(int& HP, int& M, int& M_pay) {
	float fake_HP;
	if (HP < 200) {  
		fake_HP = HP * 1.3;
		M -= 150;
		M_pay += 150;
	}
	else {
		fake_HP = HP* 1.1;
		M -= 70;
		M_pay += 70;
	}
	HP = raise_up(fake_HP);
	fix_HP(HP);
	fix_M(M);
}
void event2(int& EXP, int& M, int& M_pay) {
	float fake_EXP;
	if (EXP < 400) {
		M -= 200;
		M_pay += 200;
	}
	else {
		M -= 120;
		M_pay += 120;
	}
	fake_EXP = EXP * 1.13;
	EXP = raise_up(fake_EXP);
	fix_EXP(EXP);
	fix_M(M);
}
void event3(int& EXP, int& M, int& M_pay) {
	float fake_EXP;
	if (EXP < 300) {
		M -= 100;
		M_pay += 100;
	}
	else {
		M -= 120;
		M_pay += 120;
	}
	fake_EXP = EXP * 0.9;
	EXP = raise_up(fake_EXP);
	fix_EXP(EXP);
	fix_M(M);
}
int plus_2number(int& i) {
	while (i >=10) {
		int chuc = i / 10;
		int don_vi = i - chuc * 10;
		i = chuc + don_vi;
	}
    if (i < 10) return i;
    return plus_2number(i);
}
bool condition1(string s) {
	return s.size() <= 20 && s.size() >= 8;
}
bool condition2(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 33 || (s[i] > 34 && s[i] < 38) || (s[i] > 47 && s[i] < 58) || (s[i] > 63 && s[i] < 91) || (s[i] > 96 && s[i] < 123))
			continue;
		else
			return false;
	}
	return true;
}
bool condition3(string s, string se) {
	if (se.empty())
		return false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == se[0]) {
			string fake_s;
			fake_s.append(s, i, se.size());
			if (fake_s == se)
				return false;
		}
	}
	return true;
}
bool condition4(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == s[i + 1] && s[i] == s[i + 2])
			return false;
	}
	return true;
}
bool condition5(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 33 || (s[i] > 34 && s[i] < 38) || s[i] == 64)
			return true;
	}
	return false;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;
    fix_EXP(exp1);
    fix_EXP(exp2);
	float c;
	if (e1 < 4 && e1 >= 0) {
		if (e1 == 0)
			exp2 += 29;
		else if (e1 == 1)
			exp2 += 45;
		else if (e1 == 2)
			exp2 += 75;
		else
			exp2 = exp2 + 75 + 29 + 45;
		int D = e1 * 3 + exp1 * 7;
		if (D % 2 == 0) {
			c = exp1 + (float)D / 200;
			exp1 = raise_up(c);
		}
		else {
			c = exp1 - (float)D / 100;
			exp1 = raise_up(c);
		}
	}else if (e1 >= 4 && e1 <= 99) {
		if (e1 >= 4 && e1 <= 19)
			c = (float)e1 / 4 + 19 + exp2;
		else if (e1 >= 20 && e1 <= 49)
			c = (float)e1 / 9 + 21 + exp2;
		else if (e1 >= 50 && e1 <= 65)
			c = (float)e1 / 16 + 17 + exp2;
		else if (e1 >= 66 && e1 <= 79) {
			c = (float)e1 / 4 + 19 + exp2;
			c = (float)raise_up(c);
			if (c > 200)
				c = (float)e1 / 9 + 21 + c;
		}
		else if (e1 >= 80 && e1 <= 99) {
			c = (float)e1 / 4 + 19 + exp2;
			c = (float)raise_up(c);
			c = (float)e1 / 9 + 21 + c;
			c = (float)raise_up(c);
			if (c > 400) {
				c = (float)e1 / 16 + 17 + c;
				c = (float)raise_up(c);
				c = 1.15 * c;
			}
		}
		exp2 = raise_up(c);
		exp1 -= e1;
	}
	fix_EXP(exp1);
	fix_EXP(exp2);   
	return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
        // TODO: Complete this function
        if (E2 < 0 || E2 > 99) return -99;
        int M_pay=0;
        float P1, P2, P3;
        int  S1, S2;
        fix_HP(HP1);
        fix_EXP(EXP1);
        fix_M(M1);
		//road 1
		for (int i = 0; i * i <= EXP1; i++) {
			S1 = i * i;
			S2 = (i + 1) * (i + 1);
		}
		if (EXP1 - S1 < S2 - EXP1)
			P1 = 1;
		else
			P1 = ((float)EXP1 / S2 + 80) / 123;
		//road 2
        if (M1 != 0){
            float condition_M = 0.5 *M1;
            if (E2 % 2 != 0) {
                while (M_pay <= condition_M) {
                    event1(HP1, M1, M_pay);
                    if (M_pay > condition_M)
                        break;
                    event2(EXP1, M1, M_pay);
                    if (M_pay > condition_M)
                        break;
                    event3(EXP1, M1, M_pay);
                }

            } else {
                event1(HP1, M1, M_pay);
                if (M1 == 0)
                    goto exit_else;
                event2(EXP1, M1, M_pay);
                if (M1 == 0)
                    goto exit_else;
                event3(EXP1, M1, M_pay);
            }
        } else {
            goto exit_else;
        }
		exit_else:
		calculate(HP1, 0.83);
		calculate(EXP1, 1.17);
		fix_HP(HP1);
		fix_EXP(EXP1);
		fix_M(M1);
		for (int i = 0; i * i <= EXP1; i++) {
			S1 = i * i;
			S2 = (i + 1) * (i + 1);
		}
		if (EXP1 - S1 < S2 - EXP1)
			P2 = 1;
		else
			P2 = ((float)EXP1 / S2 + 80) / 123;
		
		//road 3
		int Arr[10] = { 32,47,28,79,100,50,22,83,64,11 };
		if (E2 < 10) {
			P3 = (float)Arr[E2] / 100;
		}
		else {
			int don_vi, chuc, i;
			chuc = E2 / 10;
			don_vi = E2 - chuc * 10;
			i = (chuc + don_vi) - (chuc + don_vi) / 10 * 10;

			P3 = (float)Arr[i] / 100;
		}

		if (P1 == 1 && P2 == 1 && P3 == 1) {
			calculate(EXP1, 0.75);
		}else if ((P1 + P2 + P3) / 3 < 0.5) {
			calculate(HP1, 0.85);
			calculate(EXP1, 1.15);
		}else {
			calculate(HP1, 0.90);
			calculate(EXP1, 1.20);
		}
		fix_HP(HP1);
		fix_EXP(EXP1);
		fix_M(M1);
		return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3>99||E3<0)
        return -99;
    else{
        fix_EXP(EXP1);
        fix_EXP(EXP2);
        fix_HP(HP1);
        fix_HP(HP2);
        int Arr[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++)
                Arr[i][j] = (E3 * j + i * 2) * (i - j);
        }
        int pvalue = 0, nvalue = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (Arr[i][j] > 0 && Arr[i][j] > E3 * 2)
                    pvalue += 1;
                else if (Arr[i][j] < 0 && Arr[i][j] < -E3)
                    nvalue += 1;
            }
        }
        plus_2number(pvalue);
        plus_2number(nvalue);
        int score_taxi = abs(Arr[pvalue][nvalue]), score_SW = Arr[pvalue][nvalue];
        int fake_pvalue = pvalue, fake_nvalue = nvalue;
        while (fake_pvalue >= 0 && fake_nvalue < 10) {
            if (Arr[fake_pvalue][fake_nvalue] > score_SW)
                score_SW = Arr[fake_pvalue][fake_nvalue];
            fake_pvalue -= 1;
            fake_nvalue += 1;
        }
        fake_pvalue = pvalue, fake_nvalue = nvalue;
        while (fake_pvalue < 10 && fake_nvalue < 10) {
            if (Arr[fake_pvalue][fake_nvalue] > score_SW)
                score_SW = Arr[fake_pvalue][fake_nvalue];
            fake_pvalue += 1;
            fake_nvalue += 1;
        }
        fake_pvalue = pvalue, fake_nvalue = nvalue;
        while (fake_pvalue >= 0 && fake_nvalue >= 0) {
            if (Arr[fake_pvalue][fake_nvalue] > score_SW)
                score_SW = Arr[fake_pvalue][fake_nvalue];
            fake_pvalue -= 1;
            fake_nvalue -= 1;
        }
        fake_pvalue = pvalue, fake_nvalue = nvalue;
        while (fake_pvalue < 10 && fake_nvalue >= 0) {
            if (Arr[fake_pvalue][fake_nvalue] > score_SW)
                score_SW = Arr[fake_pvalue][fake_nvalue];
            fake_pvalue += 1;
            fake_nvalue -= 1;
        }
        if (score_taxi > score_SW) {
            calculate(EXP1, 0.88);
            calculate(EXP2, 0.88);
            calculate(HP1, 0.90);
            calculate(HP2, 0.90);
			fix_EXP(EXP1);
			fix_EXP(EXP2);
			fix_HP(HP1);
			fix_HP(HP2);
            return Arr[pvalue][nvalue];
        }
        else {
            calculate(EXP1, 1.12);
            calculate(EXP2, 1.12);
            calculate(HP1, 1.10);
            calculate(HP2, 1.10);
			fix_EXP(EXP1);
			fix_EXP(EXP2);
			fix_HP(HP1);
			fix_HP(HP2);
            return score_SW;
        }
    }
            
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se;
    string s1=s, email1=email;
    for (int i = 0; i < email1.size(); i++) {
        if (email1[i] != '@')
            se.append(email1, i, 1);
        if (email1[i] == '@')
            break;
    }
    if (condition1(s1) && condition2(s1) && condition3(s1, se) && condition4(s1) && condition5(s1))
        return -10;
    if (!condition1(s1)) {
        if (s1.size() < 8)
            return -1;
        else if (s1.size() > 20)
            return -2;
    }
	if (se.empty())
		return -300;
    if (!condition3(s1,se)) {
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == se[0]) {
                string fake_s;
                fake_s.append(s1, i, se.size());
                if (fake_s == se)
                    return -(300 + i);
            }

        }
    }
    if (!condition4(s1)) {
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s1[i + 1] && s1[i] == s1[i + 2])
                return -(400 + i);
        }
    }
    if (!condition5(s1))
        return -5;
    if (!condition2(s1)) {
        for (int i = 0; i < s1.size(); i++) {
            if (!(s1[i] == 33 || (s1[i] > 34 && s1[i] < 38) || (s1[i] > 47 && s1[i] < 58) || (s1[i] > 63 && s1[i] < 91) || (s1[i] > 96 && s1[i] < 123)))
                return i;
        }
    }
	return -1;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
	int ans;
    string arr_pwds1[100];
    for(int i=0; i<num_pwds;i++){
        arr_pwds1[i]=arr_pwds[i];
    }
    string correct_password = arr_pwds1[0];
    int max_count = 0;
    for (int i = 0; i < num_pwds; i++) {
        int count = 1;
        for (int j = i + 1; j < num_pwds; j++) {
            if (arr_pwds1[j] == arr_pwds1[i]) {
                count += 1;
            }
        }
        if (count > max_count) {
            max_count = count;
            correct_password = arr_pwds1[i];
        }
        else if (count == max_count) {
            if (arr_pwds1[i].size() > correct_password.size())
                correct_password = arr_pwds1[i];
        }

    }
    for (int i = 0; i < num_pwds; i++) {
        if (correct_password == arr_pwds1[i]) {
            ans = i;
            break;
        }
    }
	return ans;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////