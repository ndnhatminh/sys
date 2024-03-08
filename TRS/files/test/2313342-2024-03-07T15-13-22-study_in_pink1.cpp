#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
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
int vi_tri(int& n) {
	while (n >= 10) {
		int a = n / 10;
		int b = n % 10;
		n = a + b;
	}
	return n;
}

int check(int& a, int firstpoint, int lastpoint) {
	a = (a > lastpoint) ? lastpoint : (a < firstpoint) ? firstpoint : a;
	return a;
}

double check_double(double& a, int firstpoint, int lastpoint) {
	a = (a > lastpoint) ? lastpoint : (a < firstpoint) ? firstpoint : a;
	return a;
}

int firstMeet(int& exp1, int& exp2, int e1) {
	if (e1 >= 0 && e1 <= 99) {
		double exp1_test = exp1;
		double exp2_test = exp2;
		if (e1 >= 0 && e1 <= 3) {
			switch (e1) {
			case 0:
				exp2_test = exp2_test + 29;
				break;
			case 1:
				exp2_test = exp2_test + 45;
				break;
			case 2:
				exp2_test = exp2_test + 75;
				break;
			case 3:
				exp2_test = exp2_test + 29 + 45 + 75;
				break;
			}
			check_double(exp2_test, 0, 600);
			int d = e1 * 3 + exp1 * 7;
			if (d % 2 == 0) {
				exp1_test = ceil((exp1_test + d * 1.00 / 200)-1e-7);
			}
			else {
				exp1_test = ceil((exp1_test - d * 1.00 / 100)-1e-7);
			}
			check_double(exp1_test, 0, 600);
		}
		else if (e1 >= 4 && e1 <= 99) {
			if (e1 >= 4 && e1 <= 19) {
				exp2_test = ceil((exp2_test + (e1 * 1.00 / 4 + 19))-1e-7);
				check_double(exp2_test, 0, 600);
			}
			else if (e1 >= 20 && e1 <= 49) {
				exp2_test = ceil((exp2_test + (e1 * 1.00 / 9 + 21))-1e-7);
				check_double(exp2_test, 0, 600);
			}
			else if (e1 >= 50 && e1 <= 65) {
				exp2_test = ceil((exp2_test + (e1 * 1.00 / 16 + 17))-1e-7);
				check_double(exp2_test, 0, 600);
			}
			else if (e1 >= 66 && e1 <= 79) {
				exp2_test = ceil((exp2_test + (e1 * 1.00 / 4 + 19))-1e-7);
				check_double(exp2_test, 0, 600);
				if (exp2_test > 200) {
					exp2_test = ceil((exp2_test + (e1 * 1.00 / 9 + 21))-1e-7);
					check_double(exp2_test, 0, 600);
				}
			}
			else if (e1 >= 80 && e1 <= 99) {
				exp2_test = ceil((exp2_test + (e1 * 1.00 / 4 + 19)-1e-7));
				check_double(exp2_test, 0, 600);
				//
				exp2_test = ceil((exp2_test + (e1 * 1.00 / 9 + 21))-1e-7);
				check_double(exp2_test, 0, 600);
				//
				if (exp2 > 400) {
					exp2_test = ceil((exp2_test + (e1 * 1.00 / 16 + 17))-1e-7);
					check_double(exp2_test, 0, 600);
					//
					exp2_test = ceil((exp2_test * 1.15)-1e-7);
					check_double(exp2_test, 0, 600);
				}
			}
			exp1_test = exp1_test - e1;
			check_double(exp1_test, 0, 600);
		}

		exp1 = exp1_test;
		exp2 = exp2_test;

		check(exp1, 0, 600);
		check(exp2, 0, 600);
		return exp2 + exp1;
	}
	else if (e1 < 0 && e1 > 99) return -99;
}

// Task 2
int traceLuggage(int& hp1, int& exp1, int& m1, int e2) {
	double hp1_test = hp1;
	double exp1_test = exp1;
	double m1_test = m1;
	double half_of_m1 = m1 * 0.5;
	double p1, p2, p3, p_tb;
	int m1_used = 0;
	bool kiem_tra_m1;
	// duong so 1
	// tinh p1
	int s1 = sqrt(exp1_test);
	s1 = (abs(pow(s1, 2) - exp1_test) > abs(pow(s1 + 1, 2) - exp1_test)) ? pow(s1 + 1, 2) : pow(s1, 2);
	p1 = (exp1_test >= s1) ? 100 / 100 : (exp1_test / s1 + 80) / 123;
	// duong so 2
	if (e2 % 2 == 1) {
		while (m1_used < half_of_m1) {
			if (hp1_test < 200) {
				hp1_test = ceil((1.3 * hp1_test) - 1e-7);
				m1 -= 150;
				m1_used += 150;
			}
			else {
				hp1_test = ceil((hp1_test * 1.1) - 1e-7);
				m1 -= 70;
				m1_used += 70;
			}
			check_double(hp1_test, 0, 666);
			check(m1, 0, 3000);
			kiem_tra_m1 = (m1_used > half_of_m1) ? true : false;
			if (kiem_tra_m1) break;
			//
			if (exp1_test < 400) {
				m1 -= 200;
				m1_used += 200;
			}
			else {
				m1 -= 120;
				m1_used += 120;
			}
			exp1_test = ceil((1.13 * exp1_test) - 1e-7);
			check_double(exp1_test, 0, 600);
			check(m1, 0, 3000);
			kiem_tra_m1 = (m1_used > half_of_m1) ? true : false;
			if (kiem_tra_m1) break;
			//
			if (exp1_test < 300) {
				m1 -= 100;
				m1_used += 100;
			}
			else {
				m1 -= 120;
				m1_used += 120;
			}
			exp1_test = ceil((exp1_test * 0.9) - 1e-7);
			check_double(exp1_test, 0, 600);
			check(m1, 0, 3000);
			kiem_tra_m1 = (m1_used > half_of_m1) ? true : false;
			if (kiem_tra_m1) break;
		}
		hp1_test = ceil((hp1_test * 0.83) - 1e-7);
		exp1_test = ceil((exp1_test * 1.17) - 1e-7);
		check_double(exp1_test, 0, 600);
		check_double(hp1_test, 0, 666);
	}
	else {
		for (int i = 0; i < 1; i++) {
			if (hp1_test < 200) {
				hp1_test = ceil((1.3 * hp1_test) - 1e-7);
				m1 -= 150;
			}
			else {
				hp1_test = ceil((hp1_test * 1.1) - 1e-7);
				m1 -= 70;
			}
			check_double(hp1_test, 0, 666);
			check(m1, 0, 3000);
			if (m1 == 0) break;
			//
			if (exp1_test < 400) {
				m1 -= 200;
			}
			else {
				m1 -= 120;
			}
			exp1_test = ceil((1.13 * exp1_test) - 1e-7);
			check_double(exp1_test, 0, 600);
			check(m1, 0, 3000);
			if (m1 == 0) break;
			//
			if (exp1_test < 300) {
				m1 -= 100;
			}
			else {
				m1 -= 120;
			}
			exp1_test = ceil((exp1_test * 0.9) - 1e-7);
			check_double(exp1_test, 0, 600);
			check(m1, 0, 3000);
			if (m1 == 0) break;
		}
		hp1_test = ceil((hp1_test * 0.83) - 1e-7);
		exp1_test = ceil((exp1_test * 1.13) - 1e-7);
		check_double(hp1_test, 0, 666);
		check_double(exp1_test, 0, 600);
	}
	// tinh p2
	int s2 = sqrt(exp1_test);
	s2 = (abs(pow(s2, 2) - exp1_test) > abs(pow(s2 + 1, 2) - exp1_test)) ? pow(s2 + 1, 2) : pow(s2, 2);
	p2 = (exp1_test >= s2) ? 100 / 100 : (exp1_test / s2 + 80) / 123;

	// duong so 3
	int p[10]{ 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
	int a = e2;
	if (a / 10 == 0) {
		p3 = p[a - 1] / 100;
	}
	else {
		a = a % 10;
		p3 = p[a - 1] / 100;
	}

	//
	if (p1 == 1 && p2 == 1 && p3 == 1) {
		exp1_test = ceil((0.75 * exp1_test) - 1e-7);
	}
	else {
		p_tb = (p1 + p2 + p3) / 3;
		if (p_tb < 0.5) {
			hp1_test = ceil((0.85 * hp1_test) - 1e-7);
			exp1_test = ceil((1.15 * exp1_test) - 1e-7);
		}
		else {
			hp1_test = ceil((0.9 * hp1_test) - 1e-7);
			exp1_test = ceil((1.2 * exp1_test) - 1e-7);
		}
	}
	check_double(exp1_test, 0, 600);
	check_double(hp1_test, 0, 666);
	exp1 = exp1_test;
	hp1 = hp1_test;
	return exp1 + hp1 + m1;
}

// Task 3
int chaseTaxi(int& hp1, int& exp1, int& hp2, int& exp2, int e3) {
	double exp1_test = exp1;
	double exp2_test = exp2;
	double hp1_test = hp1;
	double hp2_test = hp2;
	int array[10][10];
	int dem_duong = 0;
	int dem_am = 0;
	int tra_ve = 0;
	if (e3 >= 0 && e3 <= 99) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				array[i][j] = ((e3 * j) + (i * 2)) * (i - j);
			}
		}

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (array[i][j] > (e3 * 2)) dem_duong += 1;
				if (array[i][j] < (-e3)) dem_am += 1;
			}
		}

		vi_tri(dem_duong);
		vi_tri(dem_am);
		int biendem_i = dem_duong;
		int biendem_j = dem_am;
		int max = array[biendem_i][biendem_j];
		int diem_taxi = array[biendem_i][biendem_j];

		while (biendem_i < 10 && biendem_j < 10) {
			if (array[biendem_i][biendem_j] >= max) max = array[biendem_i][biendem_j];
			biendem_i++;
			biendem_j++;
		}

		biendem_i = dem_duong;
		biendem_j = dem_am;

		while (biendem_i >= 0 && biendem_j >= 0) {
			if (array[biendem_i][biendem_j] >= max) max = array[biendem_i][biendem_j];
			biendem_i--;
			biendem_j--;
		}

		biendem_i = dem_duong;
		biendem_j = dem_am;

		while (biendem_i >= 0 && biendem_j < 10) {
			if (array[biendem_i][biendem_j] >= max) max = array[biendem_i][biendem_j];
			biendem_i--;
			biendem_j++;
		}

		biendem_i = dem_duong;
		biendem_j = dem_am;

		while (biendem_i < 10 && biendem_j >= 0) {
			if (array[biendem_i][biendem_j] >= max) max = array[biendem_i][biendem_j];
			biendem_i++;
			biendem_j--;
		}

		if (abs(diem_taxi) > max) {
			exp1_test = ceil((0.88 * exp1_test) - 1e-7);
			exp2_test = ceil((0.88 * exp2_test) - 1e-7);
			hp1_test = ceil((0.9 * hp1_test) - 1e-7);
			hp2_test = ceil((0.9 * hp2_test) - 1e-7);
			tra_ve = diem_taxi;
		}
		else {
			exp1_test = ceil((1.12 * exp1_test) - 1e-7);
			exp2_test = ceil((1.12 * exp2_test) - 1e-7);
			hp1_test = ceil((1.1 * hp1_test) - 1e-7);
			hp2_test = ceil((1.1 * hp2_test) - 1e-7);
			tra_ve = max;
		}
		//check kq
		check_double(exp1_test, 0, 600);
		check_double(exp2_test, 0, 600);
		check_double(hp1_test, 0, 666);
		check_double(hp2_test, 0, 666);

		exp1 = exp1_test;
		exp2 = exp2_test;
		hp1 = hp1_test;
		hp2 = hp2_test;

		return tra_ve;
	}
	else return -99;
}


// Task 4
int check_string(string& str1, string& str2) {
	size_t found = str2.find(str1);
	if (found != std::string::npos) return static_cast<int>(found);
	else return -1;
}

bool check_string_bool(string& str1, string& str2) {
	size_t found = str2.find(str1);
	if (found != std::string::npos) return true;
	else return false;
}

int checkPassword(const char* s, const char* email) {

	string mat_khau = s;
	string email_test = email;
	string se;
	int sosanh1 = -1;
	int sosanh2 = 0;
	bool kt_ky_tu_dacbiet = true;
	int vi_tri = 0;
	// dieu kien 1
	if (mat_khau.length() < 8) return -1;
	else if (mat_khau.length() > 20) return -2;
	// dieu kien 2
	for (int i = 0; i < email_test.length(); i++) {
		if (email_test[i] == 64) { vi_tri = i; break; }
	}
	for (int i = 0; i < vi_tri; i++) {
		se = se + email_test[i];
	}
	// dieu kien 3
	if (check_string_bool(se, mat_khau)) {
		sosanh1 = check_string(se, mat_khau); return -(300 + sosanh1);
	}

	for (int i = 0; i < mat_khau.length(); i++) {
		if ((mat_khau[i] == mat_khau[i + 1]) && (mat_khau[i + 1] == mat_khau[i + 2])) {
			sosanh2 = i; break;
		}
	}
	if (sosanh2) return -(400 + sosanh2);




	// dieu kien cuoi
	for (int i = 0; i < mat_khau.length(); i++) {
	if (mat_khau[i] == 33 || mat_khau[i] == 64 || (mat_khau[i] >= 35 && mat_khau[i] <= 37)) {
		kt_ky_tu_dacbiet = false;
		break;
	}
	}
	if (kt_ky_tu_dacbiet) return -5;
	for (int i = 0; i < mat_khau.length(); i++) {
		if (mat_khau[i] >= 48 && mat_khau[i] <= 57) continue;
		else if (mat_khau[i] >= 64 && mat_khau[i] <= 90) continue;
		else if (mat_khau[i] >= 97 && mat_khau[i] <= 122) continue;
		else if (mat_khau[i] == 33 || (mat_khau[i] >= 35 && mat_khau[i] <= 37)) {
			continue;
		}
		else return i;
	}
	

	return -10;
}
// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
	int max = 0;
	int max_string = 0;
	int vi_tri_chuoi = 0;

	for (int i = 0; i < num_pwds; i++) {
		int bien_dem = 0;
		for (int j = 0; j < num_pwds; j++) {
			if (arr_pwds[i] == arr_pwds[j]) {
				bien_dem += 1;
			}
		}
		if ((bien_dem > max) || (bien_dem == max && strlen(arr_pwds[i]) > max_string)) {
			max = bien_dem;
			max_string = strlen(arr_pwds[i]);
			vi_tri_chuoi = i;
		}
	}

	return vi_tri_chuoi;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////