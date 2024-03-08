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
void expmax(int& a) {
    const int exp_max = 600;
    const int exp_min = 0;
    if (a > 600) {
        a = exp_max;
    }
    if (a < 0) {
        a = exp_min;
    }

}
void hpmax(int& a) {
    const int hp_max = 666;
    const int hp_min = 0;
    if (a > 666) {
        a = hp_max;
    }
    if (a < 0) {
        a = hp_min;
    }
}
void moneymax(int& a) {
    const int money_max = 3000;
    const int money_min = 0;
    if (a > 3000) {
        a = money_max;
    }
    if (a < 0) {
        a = money_min;
    }
}
int firstMeet(int& exp1, int& exp2, int e1) {
	// TODO: Complete this function
	expmax(exp1);
	expmax(exp2);
	int results = 0;
	int d = e1 * 3 + exp1 * 7;
	if (e1 >= 0 && e1 <= 3) {
		if (e1 == 0) {
			exp2 += 29;
			expmax(exp2);
		}
		if (e1 == 1) {
			expmax(exp2);
			exp2 += 45;
		}

		if (e1 == 2) {
			exp2 += 75;
			expmax(exp2);
		}

		if (e1 == 3) {
			exp2 = exp2 + 29 + 45 + 75;
			expmax(exp2);
		}

		if (d % 2 == 0) {
			exp1 = exp1 + ceil(d / 200.0);
			expmax(exp1);
		}
		else {
			int a = d / 100.0;
			exp1 = exp1 - a;
			expmax(exp1);

		}
		expmax(exp1);
		expmax(exp2);
		results = exp1 + exp2;
	}
	else if (e1 >= 4 && e1 <= 99) {
		if (e1 >= 4 && e1 <= 19) {
			exp2 = exp2 + ceil(e1 / 4.0 + 19);
			expmax(exp2);
		}
		else if (e1 >= 20 && e1 <= 49) {
			exp2 = exp2 + ceil(e1 / 9.0 + 21);
			expmax(exp2);
		}
		else if (e1 >= 50 && e1 <= 65) {
			exp2 = exp2 + ceil(e1 / 16.0 + 17);
			expmax(exp2);
		}
		else if (e1 >= 66 && e1 <= 79) {
			exp2 = exp2 + ceil(e1 / 4.0 + 19);
			expmax(exp2);
			if (exp2 > 200) {
				exp2 = exp2 + ceil(e1 / 9.0 + 21);
				expmax(exp2);
			}
		}
		else if (e1 >= 80 && e1 <= 99) {
			exp2 = exp2 + ceil(e1 / 4.0 + 19);
			expmax(exp2);
			exp2 = exp2 + ceil(e1 / 9.0 + 21);
			expmax(exp2);
			if (exp2 > 400) {
				exp2 = exp2 + ceil(e1 / 16.0 + 17);
				expmax(exp2);
				exp2 = ceil(exp2*1.15);
				expmax(exp2);
			}
		}
		expmax(exp1);
		expmax(exp2);
		exp1 = exp1 - e1;
		expmax(exp1);
		results = exp1 + exp2;
	}
	else results = -999;
	return results;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E3) {
	// TODO: Complete this function
	int array[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
	hpmax(HP1);
	expmax(EXP1);
	moneymax(M1);
	//Road 1
	double p1;
	int results = 0;
	int square = round(sqrt(EXP1));
	if (square * square <= EXP1) {
		p1 = 100;
	}
	else p1 = (EXP1 / (square * square) + 80.0) / 123.0 * 100.0;
	//Road 2
	int initial_money = M1 * 0.5;
	int pay = 0;
	if (E3 < 0 || E3 > 99) {
		results = -999;
	}
	else {
		while (M1 > 0) {
			//Event 1
			if (HP1 < 200) {
				int a = ceil(HP1 * 0.3);
				HP1 += a;
				hpmax(HP1);
				pay += 150;
				if (pay > initial_money && E3 % 2 != 0) {
					break;
				}
				if (pay >= M1) {
					break;
				}
			}
			else {
				int a = ceil(HP1 * 0.1);
				HP1 += a;
				hpmax(HP1);
				pay += 70;
				
				if (pay > initial_money && E3 % 2 != 0) {
					break;
				}
				if (pay >= M1) {
					break;
				}
			}
			//Event 2
			if (EXP1 < 400) {
				pay += 200;
				int a = ceil(EXP1*0.13);
				EXP1 += a;
				expmax(EXP1);
				if (pay > initial_money && E3 % 2 != 0) {
					break;
				}
				if (pay >= M1) {
					break;
				}
			}
			else {
				pay += 120;
				int a = ceil(EXP1 * 0.13);
				EXP1 += a;
				expmax(EXP1);
				if (pay > initial_money && E3 % 2 != 0) {
					break;
				}
				if (pay >= M1) {
					break;
				}
			}
			//Event 3
			if (EXP1 < 300) {
				pay += 100;
				int a = EXP1 * 0.1;
				EXP1 -= a;
				expmax(EXP1);
				if (pay > initial_money && E3 % 2 != 0) {
					break;
				}
				if (pay >= M1) {
					break;
				}
			}
			else {
				pay += 120;
				int a = EXP1 * 0.1;
				EXP1 -= a;
				expmax(EXP1);
				if ( pay >initial_money && E3 % 2 != 0) {
					break;
				}
				if (pay >= M1) {
					break;
				}
			}
			if (E3 % 2 == 0) {
				break;
			}
		}

		hpmax(HP1);
		expmax(EXP1);
		moneymax(M1);
		int x = HP1 * 0.17;
		HP1 -= x;
		hpmax(HP1);
		int y = EXP1 * 0.17;
		float z = EXP1 * 0.17;
		if (z / y == 1) {
			EXP1 += y;
		}
		else EXP1 += ceil(EXP1 * 0.17);
		expmax(EXP1);
		double p2;
		int square2 = round(sqrt(EXP1));
		if (square2 * square2 <= EXP1) {
			p2 = 100;
		}
		else p2 = (EXP1 / (square2 * square2) + 80.0) / 123.0 * 100.0;
		//Road 3
		double p3;
		if (E3 >= 0 && E3 <= 9) {
			p3 = array[E3];
		}
		else p3 = array[(E3 / 10 + E3 % 10) % 10];

	double avg_p = (p1 + p2 + p3) / 3.0;
	ceil(avg_p);
	if (p1 == 100 && p2 == 100 && p3 == 100) {
		int a = EXP1 * 25 / 100;
		EXP1 -= a;
		expmax(EXP1);
	}
	else {
		if (avg_p < 50) {
			int a = ceil(EXP1 * 0.15);
			EXP1 += a;
			expmax(EXP1);
			int b = HP1 * 0.15;
			HP1 -= b;
			hpmax(HP1);
		}
		else {
			int a = ceil(EXP1 * 0.2);
			EXP1 += a;
			expmax(EXP1);
			int b = HP1 * 0.1;
			HP1 -= b;
			hpmax(HP1);

		}
	}
	M1 -= pay;
	hpmax(HP1);
	expmax(EXP1);
	moneymax(M1);
	results = HP1 + EXP1 + M1;
	}
	return results;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {

	int arr[10][10];
	int max1 = INT_MIN;
	int max2 = INT_MIN;
	int max3 = INT_MIN;
	int max4 = INT_MIN;
	int i_meet = 0;
	int j_meet = 0;
	int positive_count = 0;
	int negative_count = 0;
	int results;
	hpmax(HP1);
	hpmax(HP2);
	expmax(EXP1);
	expmax(EXP2);
	if (E3 < 0 || E3 > 99) {
		results = -999;
	}
	else {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
			}
		}

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (arr[i][j] > (E3 * 2)) {
					positive_count++;
				}
			}
		}

		while (positive_count >= 10) {
			i_meet = positive_count / 10 + positive_count % 10;
			positive_count = positive_count / 10 + positive_count % 10;
		}

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (arr[i][j] < (E3 * (-1))) {
					negative_count++;
				}
			}
		}


		while (negative_count >= 10) {
			j_meet = negative_count / 10 + negative_count % 10;
			negative_count = negative_count / 10 + negative_count % 10;
		}

		for (int x = i_meet, y = j_meet ; x >= 0 && x <= 9 && y >= 0 && y <= 9; x--, y--) {
			if (arr[x][y] > max1) {
				max1 = arr[x][y];
			}
		}
		for (int x = i_meet , y = j_meet ; x >= 0 && x <= 9 && y >= 0 && y <= 9; x++, y++) {
			if (arr[x][y] > max2) {
				max2 = arr[x][y];
			}
		}
		for (int x = i_meet , y = j_meet ; x >= 0 && x <= 9 && y >= 0 && y <= 9; x++, y--) {
			if (arr[x][y] > max3) {
				max3 = arr[x][y];
			}
		}
		for (int x = i_meet , y = j_meet + 1; x >= 0 && x <= 9 && y >= 0 && y <= 9; x--, y++) {
			if (arr[x][y] > max4) {
				max4 = arr[x][y];
			}
		}
		int max5 = max1;
		if (max2 > max5) {
			max5 = max2;
		}
		if (max3 > max5) {
			max5 = max3;
		}

		if (max4 > max5) {
			max5 = max4;
		}
		if (max5 < 0) {
			max5 = abs(max5);
		}
		if (max5 >= abs(arr[i_meet][j_meet])) {
			int a = ceil(HP1 * 0.1);
			HP1 += a;
			int b = ceil(HP2 * 0.1);
			HP2 += b;
			int c = ceil(EXP1 * 0.12);
			EXP1 += c;
			int d = ceil(EXP2 * 0.12);
			EXP2 += d;
			results = max5;
		}
		else {
			int a = HP1 * 0.1;
			HP1 -= a;
			int b =HP2 * 0.1;
			HP2 -= b;
			int c = EXP1 * 0.12;
			EXP1 -= c;
			int d =EXP2 * 0.12;
			EXP2 -= d;
			results = arr[i_meet][j_meet];
		}
		hpmax(HP1);
		hpmax(HP2);
		expmax(EXP1);
		expmax(EXP2);
	}


	return results;
}

// Task 4
int checkPassword(const char* s, const char* email) {
	// TODO: Complete this function
	int results = 0;
	char i, x;
	string password = s;
	string gmail = email;
	string se;
	int flag = 0;
	int consecutive = -1;
	int se_check = -1;
	int string_max = 0;
	int string_min = 0;
	int invalid = -1;
	//Create string se
	for (char i : gmail) {
		if (i == '@') {
			break;
		}
		else se += i;
	}
	//Check if password contains se
	for (int z = 0; z <= password.length() - se.length(); z++) {
		if (password.substr(z, se.length()) == se) {
			se_check = z;
			break;
		}
	}
	//Check if x contains special characters
	for (char x : password) {
		if (x == '!' || x == '#' || x == '%' || x == '@' || x == '$') {
			flag = 0;
			break;
		}
		else flag = 1;
	}
	//Check if the password is invalid
	for (int t = 0; t < password.length(); t++) {
		if (password[t] == '&' || password[t] == '`' || password[t] == '(' || password[t] == ')') {
			invalid = t;
			break;
		}
		if (password[t] == '*' || password[t] == '+' || password[t] == '-' || password[t] == '/') {
			invalid = t;
			break;
		}
		if (password[t] == ':' || password[t] == ';' || password[t] == '=' || password[t] == '<' || password[t] == '>') {
			invalid = t;
			break;
		}
		if (password[t] == '{' || password[t] == '}' || password[t] == '[' || password[t] == ']' || password[t] == '~') {
			invalid = t;
			break;
		}
	}
	//Check if x has consecutive characters
	for (int z = 0; z < password.length(); z++) {
		if (password[z] == password[z + 1] && password[z] == password[z + 2]) {
			consecutive = z;
		}
	}
	//Check the length of password
	if (password.length() < 8) {
		string_min = 1;
	}
	else if (password.length() > 20) {
		string_max = 1;
	}

	if (string_min != 0) {
		results = -1;
		goto Quit;
	}
	else if (string_max != 0) {
		results = -2;
		goto Quit;
	}
	else if (se_check != -1) {
		results = -(300 + se_check);
		goto Quit;
	}
	else if (flag == 1) {
		results = -5;
		goto Quit;
	}
	else if (consecutive != -1) {
		results = -(400 + consecutive);
		goto Quit;
	}
	else if (invalid != -1) {
		results = invalid;
	}
	else if (string_min == string_max == flag == 0 && consecutive == -1 && se_check == -1) {
		results = -10;
		goto Quit;
	}
Quit:

	return results;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
	// TODO: Complete this function
	int occurence = 1;
	int max_occur = 1;
	int position = 0;
	string max_length = " ";
	string temp = " ";

	for (int i = 0; i < num_pwds; i++) {
		for (int j = i + 1; j < num_pwds; j++) {
			if (arr_pwds[i] == arr_pwds[j]) {
				occurence++;
			}
		}
		if (occurence > max_occur) {
			max_occur = occurence;
			temp = arr_pwds[i];
			position = i;
		}
		if (occurence == max_occur)
		{
			temp = arr_pwds[i];
			if (temp.length() > max_length.length()) {
				max_length = temp;
				position = i;
			}
			occurence = 1;
		}
	}
	return position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////