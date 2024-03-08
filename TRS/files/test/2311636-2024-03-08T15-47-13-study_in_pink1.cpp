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

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

int UP(double x) {
	double n, y;
	y = modf(x, &n);
	if (y < 0.5 && y > 0) {
		x += 0.5;
	}
	x = round(x);
	return x;
}

int EXP(double x) {
	if (x > 600) {
		x = 600;
	}
	if (x < 0) {
		x = 0;
	}
	return x;
}

int HP(double x) {
	if (x > 666) {
		x = 666;
	}
	if (x < 0) {
		x = 0;
	}
	return x;
}

int M(double x) {
	if (x > 3000) {
		x = 3000;
	}
	if (x < 0) {
		x = 0;
	}
	return x;
}

int nearestPerfectSquare(int num) {
	// Tìm c?n b?c hai c?a s? ?ã cho
	double sqrtNum = sqrt(num);

	// Làm tròn c?n b?c hai này lên và xu?ng
	int lower = floor(sqrtNum);
	int upper = ceil(sqrtNum);

	// Tính kho?ng cách ??n s? chính ph??ng g?n nh?t t? phía trên và d??i
	int distLower = abs(num - lower * lower);
	int distUpper = abs(num - upper * upper);

	// So sánh kho?ng cách và tr? v? s? chính ph??ng g?n nh?t
	return (distLower < distUpper) ? (lower * lower) : (upper * upper);
}

// Task 1

int firstMeet(int& EXP1, int& EXP2, int E1) {
	// TODO: Complete this function
	int d, D, sum;
	double b1 = EXP1, b2 = EXP2, n, y;
	double x1 = E1;
	if (E1 < 0 || E1 > 99) {
		sum = -99;
		
	}
	else {
		if (E1 >= 0 && E1 <= 3) {
			
			if (E1 == 0) {
				d = 29;
			}
			else if (E1 == 1) {
				d = 45;
			}
			else if (E1 == 2) {
				d = 75;
			}
			else {
				d = 29 + 45 + 75;
			}
			b2 = b2 + d;
			b2 = EXP(b2);
			
			D = x1 * 3 + b1 * 7;
			if (D % 2 == 1) {
				
				b1 = b1 - (D / 100);
				y = modf(b1, &n);
				if (y < 0.5 && y > 0) {
					b1 += 0.5;
				}
				b1 = round(b1);
				
			}
			else {
				
				b1 = b1 + (D / 200);
				y = modf(b1, &n);
				if (y < 0.5 && y > 0) {
					b1 += 0.5;
				}
				b1 = round(b1);
				
			}
		}
		else if (E1 >= 4 && E1 <= 99) {
			// THONG TIN 1////////////////////////
			if (E1 >= 4 && E1 <= 19) {
				b2 = b2 + (x1 / 4 + 19);
				y = modf(b2, &n);
				if (y < 0.5 && y > 0) {
					b2 += 0.5;
				}
				b2 = round(b2);
				b2 = EXP(b2);
				
				b1 = b1 - E1;
				EXP1 = EXP(b1);
				
			}
			// THONG TIN 2///////////////////////
			if (E1 >= 20 && E1 <= 49) {
				b2 = b2 + (x1 / 9 + 21);
				y = modf(b2, &n);
				if (y < 0.5 && y > 0) {
					b2 += 0.5;
				}
				b2 = round(b2);
				b2 = EXP(b2);
				
				b1 = b1 - x1;
				b1 = EXP(b1);
				
			}
			// THONG TIN 3///////////////////////
			if (E1 >= 50 && E1 <= 65) {
				b2 = b2 + (x1 / 16 + 17);
				y = modf(b2, &n);
				if (y < 0.5 && y > 0) {
					b2 += 0.5;
				}
				b2 = round(b2);
				b2 = EXP(b2);
				
				b1 = b1 - x1;
				b1 = EXP(b1);
				
			}
			// THONG TIN 4///////////////////////
			if (E1 >= 66 && E1 <= 79) {
				b2 = b2 + (x1 / 4 + 19);
				y = modf(b2, &n);
				if (y < 0.5 && y > 0) {
					b2 += 0.5;
				}
				b2 = round(b2);
				b2 = EXP(b2);
				
				if (b2 > 200) {
					b2 = b2 + (x1 / 9 + 21);
					
					y = modf(b2, &n);
					if (y < 0.5 && y > 0) {
						b2 += 0.5;
					}
					b2 = round(b2);
					b2 = EXP(b2);
					
				}
				b1 = b1 - x1;
				b1 = EXP(b1);
				
			}
			//THONG TIN 5///////////////////////
			if (E1 >= 80 && E1 <= 99) {
				b2 = b2 + (x1 / 4 + 19);
				y = modf(b2, &n);
				if (y < 0.5 && y > 0) {
					b2 += 0.5;
				}
				b2 = round(b2);
				b2 = EXP(b2);
				
				b2 = b2 + (x1 / 9 + 21);
				y = modf(b2, &n);
				if (y < 0.5 && y > 0) {
					b2 += 0.5;
				}
				b2 = round(b2);
				b2 = EXP(b2);
				
				if (b2 > 300) {
					b2 = b2 + (x1 / 16 + 17);
					
					y = modf(b2, &n);
					if (y < 0.5 && y > 0) {
						b2 += 0.5;
					}
					b2 = round(b2);
					b2 = EXP(b2);
					
				}
				b2 = b2 + b2* 0.15;
				y = modf(b2, &n);
				if (y < 0.5 && y > 0) {
					b2 += 0.5;
				}
				b2 = round(b2);
				b2 = EXP(b2);
				
				b1 = b1 - x1;
				b1 = EXP(b1);
				
				
				
			}
			
		}
		EXP1 = b1;
		EXP2 = b2;
		sum = b1 + b2;

	}

	return sum;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
	// TODO: Complete this function
	int i, sum;
	double P1, P2, P3, S;
	if (E2 < 0 || E2 > 99) {//////////////////////////NHIEM VU II///////////////////////////////
		sum = -99;
		
	}
	else {
		HP1 = HP(HP1);
		EXP1 = EXP(EXP1);
		M1 = M(M1);
		double x1 = HP1, y1 = EXP1, z1 = M1, d, D = 0;
		/////////TREN DUONG 1///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		S = nearestPerfectSquare(y1);
		
		if (y1 >= S) {
			P1 = 100;
			
		}
		else {
			P1 = ((y1 / S + 80) / 123) * 100;
			P1 = round(P1);
			
		}
		/////////TREN DUONG 2///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		if (E2 % 2 == 1) {
			d = z1 / 2;
			
			do {
				if (x1 < 200) {
					
					x1 = x1 + x1 * 0.3;
					x1 = UP(x1);
					x1 = HP(x1);
					
					z1 = z1 - 150;
					z1 = UP(z1);
					z1 = M(z1);
					
					D = D + 150;
					

				}
				if (x1 >= 200) {
					
					x1 = x1 + x1 * 0.1;
					x1 = UP(x1);
					x1 = HP(x1);
					
					z1 = z1 - 70;
					z1 = UP(z1);
					z1 = M(z1);
					
					D = D + 70;
					

				}
				if (D > d) {
					break;
				}
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				if (y1 < 400) {
					
					z1 = z1 - 200;
					z1 = UP(z1);
					z1 = M(z1);
					
					D = D + 200;
					

				}
				if (y1 >= 400) {
					
					z1 = z1 - 120;
					z1 = UP(z1);
					z1 = M(z1);
					
					D = D + 120;
					

				}
				y1 = y1 + y1 * 0.13;
				y1 = UP(y1);
				y1 = EXP(y1);
				
				if (D > d) {
					break;
				}
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				if (y1 < 300) {
					
					z1 = z1 - 100;
					z1 = UP(z1);
					z1 = M(z1);
					
					D = D + 100;
					

				}
				if (y1 >= 300) {
					
					z1 = z1 - 120;
					z1 = UP(z1);
					z1 = M(z1);
					
					D = D + 120;
					

				}
				y1 = y1 * 0.9;
				y1 = UP(y1);
				y1 = EXP(y1);
				
				if (D > d) {
					break;
				}
				
			} while (D <= d);
			
			x1 = x1 * 0.83;
			x1 = UP(x1);
			x1 = HP(x1);
			
			y1 = y1 * 1.17;
			y1 = UP(y1);
			y1 = EXP(y1);
			
		}
		else {
			if (z1 != 0) {
				if (x1 < 200) {
					
					x1 = x1 + x1 * 0.3;
					x1 = UP(x1);
					x1 = HP(x1);
					
					z1 = z1 - 150;
					z1 = UP(z1);
					z1 = M(z1);
					
				}
				if (x1 >= 200) {
					
					x1 = x1 + x1 * 0.1;
					x1 = UP(x1);
					x1 = HP(x1);
					
					z1 = z1 - 70;
					z1 = UP(z1);
					z1 = M(z1);
					

				}
			}//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if (z1 != 0) {
				if (y1 < 400) {
					
					z1 = z1 - 200;
					z1 = UP(z1);
					z1 = M(z1);
					

				}
				if (y1 >= 400) {
					
					z1 = z1 - 120;
					z1 = UP(z1);
					z1 = M(z1);
					

				}
				y1 = y1 + y1 * 0.13;
				y1 = UP(y1);
				y1 = EXP(y1);
				
			}
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if (z1 != 0) {
				if (y1 < 300) {
					
					z1 = z1 - 100;
					z1 = UP(z1);
					z1 = M(z1);
					

				}
				if (y1 >= 300) {
					
					z1 = z1 - 120;
					z1 = UP(z1);
					z1 = M(z1);
					

				}
				y1 = y1 * 0.9;
				y1 = UP(y1);
				y1 = EXP(y1);
				
			}
		}
		S = nearestPerfectSquare(y1);
		
		if (y1 >= S) {
			P2 = 100;
			
		}
		else {
			P2 = ((y1 / S + 80) / 123) * 100;
			P2 = round(P2);
			
		}
		/////////TREN DUONG 3///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
		if (E2 >= 0 && E2 <= 9) {
			i = E2;
		}
		if (E2 >= 10) {
			int a = E2 / 10;
			int b = E2 % 10;
			int c = a + b;
			i = (c % 10);
		}
		
		P3 = P[i];
		
		if (P1 == 100 && P2 == 100 && P3 == 100) {
			y1 = y1 * 0.75;
			y1 = UP(y1);
			y1 = EXP(y1);
			

		}
		else {
			double P = (P1 + P2 + P3) / 3;
			P = round(P);
			if (P < 50) {
				
				x1 = x1 * 0.85;
				x1 = UP(x1);
				x1 = HP(x1);
				
				y1 = y1 * 1.15;
				y1 = UP(y1);
				y1 = EXP(y1);
				
			}
			if (P >= 50) {
				
				x1 = x1 * 0.9;
				x1 = UP(x1);
				x1 = HP(x1);
				
				y1 = y1 * 1.2;
				y1 = UP(y1);
				y1 = EXP(y1);
				
			}
		}
		HP1 = x1;
		EXP1 = y1;
		M1 = z1;
		sum = HP1 + EXP1 + M1;
	}

	return sum;
}

// Task 3
int taxiScore(int x, int y, int z) {
	return ((x * z) + (y * 2)) * (y - z);
}

int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
	// TODO: Complete this function
	int d = 0, k = 0, result;
	if (E3 < 0 || E3 > 99) {//////////////////////////NHIEM VU III///////////////////////////////
		result = -99;
	}
	else {
		HP1 = HP(HP1);
		EXP1 = EXP(EXP1);
		HP2 = HP(HP2);
		EXP2 = EXP(EXP2);
		int map[10][10] = {};//ma tran diem so cua taxi
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				map[i][j] = taxiScore(E3, i, j);
			}
		}
		
		

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (map[i][j] > (E3 * 2)) {
					d += 1;
				}
			}
		}
		
		do {//tim vi tri Sherlock va Watson gap taxi
			d = d / 10 + d % 10;
		} while (d >= 10);
		

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (map[i][j] < (-E3)) {
					k += 1;
				}
			}
		}
		
		do {
			k = k / 10 + k % 10;
		} while (k >= 10);
		

		int WSscore[10][10] = {};//ma tran diem so cua Sherlock va Watson
		int maxLeft;
		int maxRight;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				maxLeft = 0;
				maxRight = 0;
				/////////
				for (int k = 0; k < 10; k++) {
					if (k <= i && k <= j) {
						maxLeft = max(maxLeft, map[i - k][j - k]);
					}
				}
				for (int k = 0; k < 10; k++) {
					if ((i + k <= 9) && (j + k <= 9)) {
						maxLeft = max(maxLeft, map[i + k][j + k]);
					}
				}
				/////////
				for (int k = 0; k < 10; k++) {
					if (k <= i && (k + j < 10)) {
						maxRight = max(maxRight, map[i - k][j + k]);
					}
				}
				for (int k = 0; k < 10; k++) {
					if (k <= j && (k + i < 10)) {
						maxRight = max(maxRight, map[i + k][j - k]);
					}
				}
				/////////
				WSscore[i][j] = abs(max(maxLeft, maxRight));
			}
		}
		

		
		if (abs(map[d][k]) > WSscore[d][k]) {
			
			double x1 = EXP1 * 0.88;
			x1 = UP(x1);
			EXP1 = EXP(x1);
			
			//////
			double y1 = HP1 * 0.9;
			y1 = UP(y1);
			HP1 = HP(y1);
			
			//////
			double x2 = EXP2 * 0.88;
			x2 = UP(x2);
			EXP2 = EXP(x2);
			
			//////
			double y2 = HP2 * 0.9;
			y2 = UP(y2);
			HP2 = HP(y2);
			
			result = map[d][k];
		}
		else {
			
			double x1 = EXP1 * 1.12;
			x1 = UP(x1);
			EXP1 = EXP(x1);
			
			//////
			double y1 = HP1 * 0.1 + HP1;
			y1 = UP(y1);
			HP1 = HP(y1);
			
			//////
			double x2 = EXP2 * 1.12;
			x2 = UP(x2);
			EXP2 = EXP(x2);
			
			//////
			double y2 = HP2 * 0.1 + HP2;
			y2 = UP(y2);
			HP2 = HP(y2);
			
			result = WSscore[d][k];
		}

	}
	return result;
}

// Task 4
int checkPassword(const char* s, const char* email) {
	// TODO: Complete this function
	//Kiem tra do dai mat khau
	int len = strlen(s);
	if (len < 8) {
		return -1;
	}
	if (len > 20) {
		return -2;
	}
	//Tach chuoi se tu email

	char se[101];
	int i;

	for (i = 0; email[i] != '@'; i++) {
		se[i] = email[i];
	}
	se[i] = '\0'; // Kết thúc chuỗi "se"

	

	// Kiểm tra ký tự đặc biệt
	bool has_special_char = false;
	for (int i = 0; i < len; ++i) {
		if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
			has_special_char = true;
			break;
		}
	}
	if (!has_special_char) return -5; // Không chứa ký tự đặc biệt

	//Chua chuoi se
	for (int j = 0; j < len; j++) {
		if (strncmp(&s[j], se, i) == 0) {
			return -(300 + j);
		}

	}
	int y = 1;
	for (int k = 0; k < len; k++) {
		if ((k < len - 1) && (s[k] == s[k + 1])) {
			y += 1;
		}
		if (y > 2) {
			return -(400 + k - 1);
		}
	}
	return -10;


}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
	
	int* array = new int[num_pwds];
	//Tinh so lan xuat hien cua tung mat khau
	int i, n = 0;
	for (i = 0; i < num_pwds; i++) {
		int times = 0;
		for (int j = i; j < num_pwds; j++) {
			int dem = 0;
			if (i == 0) {
				if (arr_pwds[i] == arr_pwds[j]) {
					times += 1;
				}
			}

			if (i == num_pwds - 1) {
				for (int k = 0; k < i; k++) {
					if (arr_pwds[i] == arr_pwds[k]) {
						break;
					}
					dem += 1;
				}
				if (dem == 4) {
					times += 1;
				}
			}

			if (i > 0 && i < num_pwds - 1) {
				for (int k = 0; k < i; k++) {
					if (arr_pwds[i] == arr_pwds[k]) {
						break;
					}
					if ((arr_pwds[i] == arr_pwds[j]) && (arr_pwds[i] != arr_pwds[k])) {
						dem += 1;
						if (dem == i) {
							times += 1;
						}
					}
				}
			}
		}

		if (times > 0) {
			
			array[n] = times;
			n += 1;
		}
	}



	int* arr = new int[num_pwds];
	int h, m = 0;
	for (h = 0; h < num_pwds; h++) {
		int times = 0;
		for (int j = 0; j < num_pwds; j++) {
			if (arr_pwds[h] == arr_pwds[j]) {
				times += 1;
			}
		}
		arr[m] = times;
		m += 1;
	}



	int Max = 0;
	for (int t = 0; t < n; t++) {
		if (Max < array[t]) {
			Max = array[t];
		}
	}


	int numberMax = 0;
	for (int t = 0; t < n; t++) {
		if (Max == array[t]) {
			numberMax += 1;
		}
	}


	int t;
	if (numberMax == 1) {
		for (t = 0; t < m; t++) {
			if (Max == arr[t]) {
				break;
			}
		}

	}

	if (numberMax != 1) {
		int max_length = 0, Length;
		for (int v = 0; v < m; v++) {
			if (Max == arr[v]) {
				Length = strlen(arr_pwds[v]);
				if (max_length < Length) {
					max_length = Length;
					t = v;
				}
			}
		}

	}

	delete[] arr;
	delete[] array;
	return t;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////