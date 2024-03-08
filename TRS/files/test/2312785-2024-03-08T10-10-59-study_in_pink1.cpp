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
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    if (e1 <= 0 || e1 >= 99) return -99;
    if (exp1 >= 600) exp1 = 600;
    if (exp1 <= 0) exp1 = 0;
    if (exp2 >= 600) exp2 = 600;
    if (exp2 <= 0) exp2 = 0;
    if (0 <= e1 && e1 <= 4) {
        {
            if (e1 == 0) exp2 += 29;
            if (e1 == 1) exp2 += 45;
            if (e1 == 2) exp2 += 75;
            if (e1 == 3) exp2 += 149; }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 += ceil(D / 200.0);
        }
        if (D % 2 == 1)
        {
            exp1 = ceil(exp1 - (D / 100.0));
        }
    }
    if (4 <= e1 && e1 <= 99) {
        if (4 <= e1 && e1 <= 19) exp2 = ceil(exp2 + e1 / 4.0 + 19);
        if (20 <= e1 && e1 <= 49) exp2 = ceil(exp2 + e1 / 9.0 + 21);
        if (50 <= e1 && e1 <= 65) exp2 = ceil(exp2 + e1 / 16.0 + 17);
        if (66 <= e1 && e1 <= 79) {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);
            if (exp2 > 200) exp2 = ceil(exp2 + e1 / 9.0 + 21);
            if (exp2 > 600) exp2 = 600;
        }
        if (80 <= e1 && e1 <= 99) {
            exp2 = ceil(ceil(exp2 + e1 / 4.0 + 19) + e1 / 9.0 + 21);
            if (exp2 > 400) {
                exp2 = ceil(ceil(exp2 + e1 / 16.0 + 17) * 1.15);

                if (exp2 >= 600) exp2 = 600;
            }
        }
        exp1 = exp1 - e1;
    }
	return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
	float avg, P1, P2, P3;
	P1 = 0; P2 = 0, P3 = 0;
	int S, S1, S2, money, mun, S3, S4, S5;
	//tim P1
	S1 = ceil(sqrt(EXP1));
	S2 = floorl(sqrt(EXP1));
	if (pow(S1, 2) > pow(S2, 2)) S = pow(S1, 2); else S = pow(S2, 2);
	if (EXP1 >= S) {
		P1 = 100;
	}
	if (EXP1 <= S) { P1 = (EXP1 / S + 80) / 123.0; }
	//tim P2
	mun = M1 / 2;
	money = 0;
	if (E2 % 2 != 0) {
		while (mun > money) {
			if (HP1 < 200) {
				HP1 = ceil(HP1 * 1.30);
				if (EXP1 > 600) EXP1 = 600;
				M1 = M1 - 150;
				money = money + 150;
				if (money > mun) break;
			}
			else if (HP1 > 200) {
				HP1 = ceil(HP1 * 1.10);
				if (EXP1 > 600) EXP1 = 600;
				M1 = M1 - 70;
				money = money + 70;
				if (money > mun) break;
			}
			if (EXP1 < 400) {
				EXP1 = ceil(EXP1 * 1.13);
				if (EXP1 > 600) EXP1 = 600;
				M1 = M1 - 200;
				money = money + 200;
				if (money > mun) break;
			}
			else if (EXP1 > 400) {
				EXP1 = ceil(EXP1 * 1.13);
				if (EXP1 > 600) EXP1 = 600;
				M1 = M1 - 120;
				money = money + 120;
				if (money > mun) break;
			}
			if (EXP1 < 300) {
				EXP1 = ceil(EXP1 * 0.9);
				M1 = M1 - 100;
				money = money + 100;
				if (money > mun) break;
			}
			else if (EXP1 > 300) {
				EXP1 = ceil(EXP1 * 0.9);
				M1 = M1 - 120;
				money = money + 120;
				if (money > mun) break;
			}
		}
		HP1 = ceil(HP1 * 0.83);
		EXP1 = ceil(EXP1 * 1.17);
	}
	if (E2 % 2 == 0) {
		if (HP1 < 200) {
			HP1 = ceil(HP1 * 1.30);
			if (EXP1 > 600) EXP1 = 600;
			M1 = M1 - 150;
			money = money + 150;
		}
		else if (HP1 > 200) {
			HP1 = ceil(HP1 * 1.10);
			if (EXP1 > 600) EXP1 = 600;
			M1 = M1 - 70;
			money = money + 150;
		}

		while (M1 > money) {
			if (EXP1 < 400) {
				EXP1 = ceil(EXP1 * 1.13);
				if (EXP1 > 600) EXP1 = 600;
				M1 = M1 - 200;
				money = money + 200;
				if (money > M1) break;
			}
			else if (EXP1 > 400) {
				EXP1 = ceil(EXP1 * 1.13);
				if (EXP1 > 600) EXP1 = 600;
				M1 = M1 - 120;
				money = money + 120;
				if (money > M1) break;
			}
		}
		while (M1 > money) {
			if (EXP1 < 300) {
				EXP1 = ceil(EXP1 * 0.9);
				M1 = M1 - 100;
				money = money + 100;
				if (money > M1) break;
			}
			else if (EXP1 > 300) {
				EXP1 = ceil(EXP1 * 0.9);
				M1 = M1 - 120;
				money = money + 120;
				if (money > M1) break;
			}
		}
		HP1 = ceil(HP1 * 0.83);
		EXP1 = ceil(EXP1 * 1.17);
	}
	S3 = ceil(sqrt(EXP1));
	S4 = floorl(sqrt(EXP1));
	if (pow(S3, 2) > pow(S4, 2)) S5 = pow(S1, 2); else S5 = pow(S2, 2);
	if (EXP1 >= S5) {
		P2 = 1;
	}
	if (EXP1 <= S5) { P2 = (EXP1 / S5 + 80) / 123.0; }
	//tim P3
	int T;
	int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
	if (E2 < 10) T = E2;
	else T = (E2 / 10 + E2 % 10) % 10;
	P3 = P[T] / 100.0;

	//tra ve ham
	if (P1 == 100 && P2 == 100 && P3 == 100) EXP1 = EXP1 * 0.75;
	else {
		avg = (P1 + P2 + P3) / 3;
		if (avg < 0.5) {
			HP1 = ceil(HP1 * 0.85);
			EXP1 = ceil(EXP1 * 1.15);
			if (EXP1 > 600) EXP1 = 600;
		}
		else if (avg >= 0.5) {
			HP1 = ceil(HP1 * 0.9);
			EXP1 = ceil(EXP1 * 1.20);
			if (EXP1 > 600) EXP1 = 600;
		}
	}
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
	int count1 = 0, count2 = 0;
	int m, n, max, max1;
	int matrix[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
			if (matrix[i][j] > (E3 * 2)) count1++;
			if (matrix[i][j] < (-E3)) count2++;
		}
	}
	//tim gia tri i
	if (count1 < 10) m = count1;
	else m = count1 % 10 + count1 / 10;
	if (m > 9) m = m % 10 + m / 10;
	else m;
	//tim gia tri j
	if (count2 < 10) n = count2;
	else n = count2 % 10 + count2 / 10;
	if (n > 10) n = n % 10 + n / 10;
	else n;
	//thay i,j vao ma tran, tim max 
	int result = matrix[m][n];
	max = matrix[m][n];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
			if (i + j == (m + n)) {
				if (matrix[i][j] > max) max = matrix[i][j];
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
			if (i - j == (m - n)) {
				if (matrix[i][j] > max) max = matrix[i][j];
			}
		}
	}
	//so sanh va suy ra ket qua
	if (result < 0) {
		int result1 = abs(result);
		if (result1 < max) {
			result = max;
			EXP1 = ceil(EXP1 * 1.12);
			if (EXP1 > 600) EXP1 = 600;
			HP1 = ceil(HP1 * 1.10);
			EXP2 = ceil(EXP2 * 1.12);
			if (EXP2 > 600) EXP2 = 600;
			HP2 = ceil(HP2 * 1.10);
		}
		if (result1 > max) {
			result = result;
			EXP1 = ceil(EXP1 * 0.88);
			if (EXP1 > 600) EXP1 = 600;
			HP1 = ceil(HP1 * 0.90);
			EXP2 = ceil(EXP2 * 0.88);
			if (EXP2 > 600) EXP2 = 600;
			HP2 = ceil(HP2 * 0.90);
		}
	}
	if (result > 0) {
		if (result > max) {
			result = result;
			EXP1 = ceil(EXP1 * 0.88);
			if (EXP1 > 600) EXP1 = 600;
			HP1 = ceil(HP1 * 0.90);
			EXP2 = ceil(EXP2 * 0.88);
			if (EXP2 > 600) EXP2 = 600;
			HP2 = ceil(HP2 * 0.90);
		}
		if (result < max) {
			result = max;
			EXP1 = ceil(EXP1 * 1.12);
			if (EXP1 > 600) EXP1 = 600;
			HP1 = ceil(HP1 * 1.10);
			EXP2 = ceil(EXP2 * 1.12);
			if (EXP2 > 600) EXP2 = 600;
			HP2 = ceil(HP2 * 1.10);
		}
	}
	return result;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
	int length = strlen(s);
	if (length < 8) return -1;
	if (length > 20) return -2;
	string sub(email);
	string str(s);
	string se = sub.substr(0, sub.find('@'));
	size_t pos = str.find(se);
	if (pos != string::npos) {
		return -(300 + static_cast<int>(pos));
	}
	for (int i = 0; i < length - 1; ++i) {
		if (s[i] == s[i + 1]) {
			int sci = i;
			return -(400 + sci);
		}
	}
	// check xem s co chua cac ki tu dac biet hay ko
	const char* specialChars = "@#$%!";
	for (int i = 0; i < length; i++) {
		if (strchr(specialChars, s[i]) == nullptr) {
			return -5;
		}
	}
	return -10;

	return -99;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
	// TODO: Complete this function
		// khởi chạy tên biến correct_pwd tương ứng với mật khẩu được chọn
	// khởi chạy tên biến max_count ứng với mật khẩu có số lượng lớn nhất trong chuỗi
	// khởi chạy tên biến max_length ứng với mật khẩu có lượng kí tự dài nhất
	// (trong trường hợp có nhiều hơn 1 mật khẩu có số lượng lớn nhất bằng nhau)
	const char* correct_pwd = nullptr;
	int max_count = 0;
	int max_length = 0;

	// sử dụng vòng lặp for để xét đếm các mật khẩu 
	for (int i = 0; i < num_pwds; ++i) {
		const char* current_pwd = arr_pwds[i]; // tạo biến mới để lưu giá trị của arr_pwds[i]
		int current_length = strlen(current_pwd); // do dai cua current_pwd
		int count = 0;
		for (int j = 0; j < num_pwds; ++j) {
			if (strcmp(arr_pwds[j], current_pwd) == 0) {
				count++;
			}
		}

		if (count > max_count || (count == max_count && current_length > max_length)) {
			max_count = count;
			max_length = current_length;
			correct_pwd = current_pwd;
		}
	}

		for (int i = 0; i < num_pwds; ++i) {
			if (strcmp(arr_pwds[i], correct_pwd) == 0) {
				return i;
			}
		}
		return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////