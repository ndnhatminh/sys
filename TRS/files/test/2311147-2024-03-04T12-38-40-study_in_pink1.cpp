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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    // TODO: Complete this function
	if (e1 < 0 or e1 > 99) return -99;
	else {
		//4.1.1 truong hop 1
		double exp1_, exp2_ = 0;
		if (e1 == 0) exp2 = exp2 + 29;
		else if (e1 == 1) exp2 = exp2 + 45;
		else if (e1 == 2) exp2 = exp2 + 75;
		else if (e1 == 3) exp2 = exp2 + 29 + 45 + 75;
		switch (e1) {
		case 0: case 1: case 2: case 3:
			int D = 3 * e1 + exp1 * 7;
			if (D % 2 == 0) exp1_ = exp1 + D / 200.0;
			else exp1_ = exp1 - D / 100.0;
			exp1 = ceil(exp1_);
		}

		// 4.1.2 truong hop 2

		if (4 <= e1 and e1 <= 19) exp2_ = exp2 + e1 / 4.0 + 19;
		else if (20 <= e1 and e1 <= 49) exp2_ = exp2 + e1 / 9.0 + 21;
		else if (50 <= e1 and e1 <= 65) exp2_ = exp2 + e1 / 16.0 + 17;

		if (66 <= e1 and e1 <= 79) {
			exp2_ = exp2 + e1 / 4.0 + 19;
			exp2 = ceil(exp2_);
			if (exp2 > 200) {
				exp2_ = exp2 + e1 / 9.0 + 21;
				exp2 = ceil(exp2_);
			}
		}
		else if (80 <= e1 and e1 <= 99) {
			exp2_ = exp2 + e1 / 4.0 + 19;
			exp2 = ceil(exp2_);
			exp2_ = exp2 + e1 / 9.0 + 21;
			exp2 = ceil(exp2_);
			if (exp2 > 400) {
				exp2_ = exp2 + e1 / 16.0 + 17;
				exp2 = ceil(exp2_);
				exp2_ = exp2 * 1.15;
				exp2 = ceil(exp2_);
			}
		}
		else if (4 <= e1 and e1 <= 65) exp2 = ceil(exp2_);

		if (e1 > 3) exp1 = exp1 - e1;
		if (exp1 < 0) exp1 = 0;
		else if (exp1 > 600) exp1 = 600;
		if (exp2 < 0) exp2 = 0;
		else if (exp2 > 600) exp2 = 600;

		return exp1 + exp2;
	}
    
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
	if (E2 < 0 or E2 >99) return -99;
	else {
		int  S = 0;
		double P1, P2, P3, EXP1_, HP1_;

		// con duong 1
		int d = sqrt(EXP1);
		if (abs(EXP1 - d * d) < abs(EXP1 - (d + 1) * (d + 1))) S = d * d;
		else S = (d + 1) * (d + 1);
		if (EXP1 >= S) P1 = 1;
		else P1 = (EXP1 / (S * 1.0) + 80.0) / 123.0;
		// con duong 2
		double m1_ = M1 / 2.0;
		int M_Used = 0;
		if (E2 % 2 == 0) {
			// truong hop e2 la so cha
			for (int a = 0; a < 1; a++) {

				if (HP1 < 200) {
					M1 = M1 - 150;
					HP1_ = HP1 * 130 / 100.0;
					HP1 = ceil(HP1_);
				}
				else {
					M1 = M1 - 70;
					HP1_ = HP1 * 110 / 100.0;
					HP1 = ceil(HP1_);
				}
				if (M1 < 0) break;
				if (EXP1 < 400) {
					M1 = M1 - 200;
				}
				else {
					M1 = M1 - 120;
				}
				EXP1_ = EXP1 * 113 / 100.0;
				EXP1 = ceil(EXP1_);
				if (M1 < 0) break;
				{
					if (EXP1 < 300) {
						M1 = M1 - 100;
					}
					else {
						M1 = M1 - 120;
					}
					EXP1_ = EXP1 * 90 / 100.0;
					EXP1 = ceil(EXP1_);
					if (M_Used > m1_) break;
				}
			}
		}
		else {
			// truong hop e la so le
			for (int a = 0;; a++) {
				if (E2 % 2 == 1) {
					if (HP1 < 200) {
						M1 = M1 - 150;
						HP1_ = HP1 * 130 / 100.0;
						HP1 = ceil(HP1_);
						M_Used = M_Used + 150;
					}
					else {
						M1 = M1 - 70;
						HP1_ = HP1 * 110 / 100.0;
						HP1 = ceil(HP1_);
						M_Used = M_Used + 70;
					}
					if (M_Used > m1_) break;
					if (EXP1 < 400) {
						M1 = M1 - 200;
						M_Used = M_Used + 200;
					}
					else {
						M1 = M1 - 120;
						M_Used = M_Used + 120;
					}
					EXP1_ = EXP1 * 113 / 100.0;
					EXP1 = ceil(EXP1_);
					if (M_Used > m1_) break;
					{
						if (EXP1 < 300) {
							M1 = M1 - 100;
							M_Used = M_Used + 100;
						}
						else {
							M1 = M1 - 120;
							M_Used = M_Used + 120;
						}
						EXP1_ = EXP1 * 90 / 100.0;
						EXP1 = ceil(EXP1_);
						if (M_Used > m1_) break;
						// truong hop 2
					}
				}
			}
		}
		if (M1 < 0) M1 = 0;
		else if (M1 > 3000) M1 = 3000;
		if (HP1 < 0) HP1 = 0;
		else if (HP1 > 666) HP1 = 666;

		EXP1_ = EXP1 * 117 / 100.0;
		EXP1 = ceil(EXP1_);
		HP1_ = HP1 * 83 / 100.0;
		HP1 = ceil(HP1_);

		if (EXP1 < 0) EXP1 = 0;
		else if (EXP1 > 600) EXP1 = 600;
		if (HP1 < 0) HP1 = 0;
		else if (HP1 > 666) HP1 = 666;

		d = sqrt(EXP1);
		if (abs(EXP1 - d * d) < abs(EXP1 - (d + 1) * (d + 1))) S = d * d;
		else S = (d + 1) * (d + 1);
		if (EXP1 >= S) P2 = 1;
		else P2 = (EXP1 / (S * 1.0) + 80.0) / 123.0;
		// con duong 3
		int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
		if (E2 < 10) {
			P3 = P[E2] / 100.0;
		}
		else {
			int a = E2 / 10;
			int b = E2 % 10;
			int c = a + b;
			int d = c % 10;
			P3 = P[d] / 100.0;
		}
		double P_tb = (P1 + P2 + P3) / 3;
		if (P_tb == 1) {
			EXP1_ = EXP1 * 75 / 100.0;
			EXP1 = ceil(EXP1_);
		}
		else {
			if (P_tb < 0.5) {
				EXP1_ = EXP1 * 115 / 100.0;
				EXP1 = ceil(EXP1_);
				HP1_ = HP1 * 85 / 100.0;
				HP1 = ceil(HP1_);
			}
			else {
				EXP1_ = EXP1 * 120 / 100.0;
				EXP1 = ceil(EXP1_);
				HP1_ = HP1 * 90 / 100.0;
				HP1 = ceil(HP1_);
			}
		}
		if (EXP1 < 0) EXP1 = 0;
		else if (EXP1 > 600) EXP1 = 600;
		if (HP1 < 0) HP1 = 0;
		else if (HP1 > 666) HP1 = 666;
		return HP1 + EXP1 + M1;
	}
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
	if (E3 < 0 or E3 > 99) return -99;
	else {
		int arr[10][10], col = 0, row = 0;
		int diem_sherlock;
		double exp1_, exp2_, hp1_, hp2_;
		//
		// khoi tao ma tran va tim diem cua taxi
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				arr[i][j] = 0;
			}
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				arr[i][j] = ((E3 * j) + i * 2) * (i - j);
			}
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (arr[i][j] > (E3 * 2)) {
					row = row + 1;
				}
				else if (arr[i][j] < (-E3)) {
					col = col + 1;
				}
			}
		}
		for (int i = 0; ; i++) {
			if (row >= 10) {
				int a = row / 10;
				int b = row % 10;
				row = a + b;
			}
			else {
				break;
			}
		}
		for (int i = 0; ; i++) {
			if (col >= 10) {
				int a = col / 10;
				int b = col % 10;
				col = a + b;
			}
			else {
				break;
			}
		}
		// tim diem cua Sherlock va Watson
		// duong cheo trai
		int i = row, j = col;
		diem_sherlock = arr[i][j];
		for (int a = 0; ; a++) {
			if (diem_sherlock < arr[i][j]) diem_sherlock = arr[i][j];
			i = i + 1;
			j = j - 1;
			if (i > 9 or j < 0) break;
		}

		i = row, j = col;
		for (int a = 0; ; a++) {
			if (diem_sherlock < arr[i][j]) diem_sherlock = arr[i][j];
			i = i - 1;
			j = j + 1;
			if (i < 0 or j > 9) break;
		}
		// duong cheo phai
		i = row, j = col;
		for (int a = 0; ; a++) {
			if (diem_sherlock < arr[i][j]) diem_sherlock = arr[i][j];
			i = i + 1;
			j = j + 1;
			if (i > 9 or j > 9) break;
		}
		i = row, j = col;
		for (int a = 0; ; a++) {
			if (diem_sherlock < arr[i][j]) diem_sherlock = arr[i][j];
			i = i - 1;
			j = j - 1;
			if (i < 0 or j < 0) break;
		}
		diem_sherlock = abs(diem_sherlock);
		// dieu kien co duoi kip taxi k
		if (abs(arr[row][col]) > diem_sherlock) {
			// sherlock
			exp1_ = EXP1 * 88 / 100.0;
			EXP1 = ceil(exp1_);
			hp1_ = HP1 * 90 / 100.0;
			HP1 = ceil(hp1_);
			// watson
			exp2_ = EXP2 * 88 / 100.0;
			EXP2 = ceil(exp2_);
			hp2_ = HP2 * 90 / 100.0;
			HP2 = ceil(hp2_);
		}
		else {
			// sherlock
			exp1_ = EXP1 * 112 / 100.0;
			EXP1 = ceil(exp1_);
			hp1_ = HP1 * 110 / 100.0;
			HP1 = ceil(hp1_);
			// watson
			exp2_ = EXP2 * 112 / 100.0;
			EXP2 = ceil(exp2_);
			hp2_ = HP2 * 110 / 100.0;
			HP2 = ceil(hp2_);

		}

		if (EXP1 < 0) EXP1 = 0;
		else if (EXP1 > 600) EXP1 = 600;
		if (HP1 < 0) HP1 = 0;
		else if (HP1 > 666) HP1 = 666;

		if (EXP2 < 0) EXP2 = 0;
		else if (EXP2 > 600) EXP2 = 600;
		if (HP2 < 0) HP2 = 0;
		else if (HP2 > 666) HP2 = 666;

		if (abs(arr[row][col]) > diem_sherlock) return  arr[row][col];
		else return diem_sherlock;
	}

}

// Task 4
int checkPassword(const char*  s,  const char*  email) {
    // TODO: Complete this function
	string se;
	int t = 0;
	for (int i = 0; i < strlen(email); i++) {
		if (email[i] == '@') {
			for (int a = 0; a < i; a++) {
				se = se + email[a];
				if (a == (i - 1)) break;
			}
		}
	}
	string s_ = s;
	// chua so ky tu khong thoa yeu cau

	if (strlen(s) < 8) {
		return -1;
	}
	else if (strlen(s) > 20) {
		return -2;
	}
	if (se.length() == 0) return -300;
	// chua chuoi se
	//
	if (s_.length() >= se.length()) {
		for (int i = 0; i < s_.length(); i++) {
			if (s_[i] == se[0]) {
				if ((s_.length() - i) < se.length()) break;
				string s1 = s_.substr(i, se.length());
				if (s1 == se) {
					return -(300 + i);
					break;
				}
			}
		}
	}
	// hai ky tu lien tiep giong nhau
	for (int i = 0; i < (strlen(s) - 2); i++) {
		if (s[i] == s[i + 1] and s[i + 1] == s[i + 2]) {
			return -(400 + i);
			break;
		}
	}
	// ky tu dac biet
	int err_saiKyTu = -1;
	int count_T = 0;

	for (int i = 0; i < strlen(s); i++) {
		if (int(s[i]) == 33 or int(s[i]) == 35 or int(s[i]) == 36 or
			int(s[i]) == 37 or int(s[i]) == 64) 
			count_T = count_T + 1;
	}


	for (int i = 0; i < strlen(s); i++) {
		if (int(s[i]) == 33 or int(s[i]) == 35 or int(s[i]) == 36 or
			int(s[i]) == 37 or int(s[i]) == 64) {
		}
		else if ((48 <= int(s[i]) and int(s[i]) <= 57) or (65 <= int(s[i]) and int(s[i]) <= 90) or (97 <= int(s[i]) and int(s[i]) <= 122)) {

		}
		else {
			err_saiKyTu = i;
			break;
		}
	}
	if (count_T == 0) return -5;
	if (err_saiKyTu > -1) return err_saiKyTu;

	return -10;
}
// tim so lan mat khau xuat hien
int SoLanXuatHien_matKhau(string a[], int n,string x)
{
	int DemPTuX = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			DemPTuX = DemPTuX + 1;
	return DemPTuX;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
	string arr[num_pwds];
	for (int i = 0; i < num_pwds; i++) {
		arr[i] = arr_pwds[i];
	}
	string a = arr[0];
	int c = 0;
	int b = SoLanXuatHien_matKhau(arr, num_pwds, arr[0]);
	int vi_tri = 0;
	for (int i = 1; i < num_pwds; i++) {
		c = SoLanXuatHien_matKhau(arr, num_pwds, arr[i]);
		if (a == arr[i]) continue;
		if (b < c) {
			a = arr[i];
			b = c;
			vi_tri = i;
		}
		else if (b == c) {
			if (a.length() < arr[i].length()) {
				a = arr[i];
				vi_tri = i;
			}
		}
	}
	/*const char* a = arr_pwds[0];
	int c = 0;
	int b = SoLanXuatHien_matKhau(arr_pwds, num_pwds, a);
	int vi_tri = 0;
	for (int i = 1; i < num_pwds; i++) {
		c = SoLanXuatHien_matKhau(arr_pwds, num_pwds, a);
		if (a == arr_pwds[i]) continue;
		if (b < c) {
			a = arr_pwds[i];
			b = c;
			vi_tri = i;
		}
		else if (b == c) {
			if (strlen(a) < strlen(arr_pwds[i])) {
				a =  arr_pwds[i] ;
				vi_tri = i ;
			}
		}
	}*/
	return vi_tri;
    
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////