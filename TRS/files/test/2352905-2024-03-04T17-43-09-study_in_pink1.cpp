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

// Task 1
// cout = kiem loi
void check(int& x, int min, int max) {
	if (x < min) {
		x = min;
	}
	if (x > max) {
		x = max;
	}
}

//vi doi so int ra float may bi sai so vo cung nho nen dung round de loai tru
// do do ta sua sai bang cach A = round(1.0 * A * 10000)/10000

//int int_float(float x) {
//	x = round(10000.0 * x) / 10000;
//	return x;
//}


int firstMeet(int& exp1, int& exp2, int e1) {
	// TODO: Complete this function
	if (e1 < 0 || e1>99) {
		return -99;
	}
	check(exp1, 0, 600);
	check(exp2, 0, 600);


	if (e1 >= 0 && e1 <= 3 && e1 != -99) {
		if (e1 == 0) {
			exp2 += 29;
			check(exp2, 0, 600);
		}
		else if (e1 == 1) {
			exp2 += 45;
			check(exp2, 0, 600);
		}
		else if (e1 == 2) {
			exp2 += 75;
			check(exp2, 0, 600);
		}
		else if (e1 == 3) {
			exp2 += (29 + 45 + 75);
			check(exp2, 0, 600);
		}
		int d = e1 * 3 + exp1 * 7;
		if (d % 2 == 0) {
			exp1 += ceil((round(10000.0 * d)/10000) / 200);
			//cout <<"a: "<< exp1<<endl;
			check(exp1, 0, 600);
		}
		else {
			exp1 = ceil(1.0 * exp1 - (round(10000.0 * d) / 10000) / 100);
			//cout <<"b: "<< exp1<<endl;		
			check(exp1, 0, 600);
		}

	}
	else if (4 <= e1 && e1 <= 99) {
		if (4 <= e1 && e1 <= 19) {
			exp2 += ceil((round(10000.0 * e1) / 10000) / 4 + 19);
			//cout <<"c: "<< exp2 <<endl;
			check(exp2, 0, 600);
		}
		else if (20 <= e1 && e1 <= 49) {
			exp2 += ceil((round(10000.0 * e1) / 10000) / 9 + 21);		
			//cout <<"d: "<< exp2 <<endl;
			check(exp2, 0, 600);
		}
		else if (50 <= e1 && e1 <= 65) {
			exp2 += ceil((round(10000.0 * e1) / 10000) / 16 + 17);
			//cout <<"e: "<< exp2 <<endl;
			check(exp2, 0, 600);
		}
		else if (66 <= e1 && e1 <= 79) {
			exp2 += ceil((round(10000.0 * e1) / 10000) / 4 + 19);
			check(exp2, 0, 600);
			if (exp2 > 200) {
				exp2 += ceil((round(10000.0 * e1) / 10000) / 9 + 21);
				//cout <<"g: "<< exp2 <<endl;
				check(exp2, 0, 600);
			}
		}
		else if (80 <= e1 && e1 <= 99) {
			exp2 += ceil((round(10000.0 * e1)/10000) / 4 + 19);
			//cout <<"h: "<< exp2 <<endl;
			check(exp2, 0, 600);
			exp2 += ceil((round(10000.0 * e1)/10000) / 9 + 21);
			//cout <<"i: "<< exp2 <<endl;
			check(exp2, 0, 600);
			if (exp2 > 400) {		
				exp2 += ceil((round(10000.0 * e1) / 10000) / 16 + 17);
				check(exp2, 0, 600);
				exp2 = ceil(round(1.15 * 10000.0 * exp2) / 10000);
				//cout <<"k: "<< exp2 <<endl;
				check(exp2, 0, 600);
			}
		}
		exp1 -= e1;
		check(exp1, 0, 600);
	}
	check(exp1, 0, 600);
	check(exp2, 0, 600);
	//cout <<"kq: "<< exp1  + exp2 <<endl;
	return exp1 + exp2;

}

int cp(int n) {
	int s = sqrt(n);
	if (abs(s * s - n) > abs((s + 1) * (s + 1) - n)) {
		return (s + 1) * (s + 1);
	}
	else {
		return s * s;
	}

}


// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
	if (E2 < 0 || E2>99) {
		return -99;
	}
	check(HP1, 0, 666);
	check(EXP1, 0, 600);
	check(M1, 0, 3000);
	//pattern 1
	int s;
	double P1;
	s = cp(EXP1);
	if (EXP1 >= s) {
		P1 = 100;
	}
	else {
		P1 = 100.0 * (1.0 * EXP1 / s + 80.0) / 123.0;
	}
	//pattern 2

	int m = M1;

	if (E2 % 2 == 0) {
		if (HP1 < 200) {
			HP1 += ceil(round(0.3 * 10000.0 * HP1) / 10000);
			check(HP1, 0, 666);
			M1 -= 150;
			check(M1, 0, 3000);
		}
		else {
			HP1 += ceil(round(0.1 * 10000.0 * HP1) / 10000);
			check(HP1, 0, 666);
			M1 -= 70;
			check(M1, 0, 3000);
		}
		if (M1 > 0) {

			if (EXP1 < 400) {
				M1 -= 200;
				check(M1, 0, 3000);
			}
			else {
				M1 -= 120;
				check(M1, 0, 3000);
			}
  			EXP1 += ceil(round(0.13 * 10000.0 * EXP1) / 10000);
			check(EXP1, 0, 600);
			//cout<<"exp1a: "<<EXP1<<endl;

		}
		else {
			M1 = 0;
		}
		if (M1 > 0) {
			if (EXP1 < 300) {
				M1 -= 100;
				check(M1, 0, 3000);
			}
			else {
				M1 -= 120;
				check(M1, 0, 3000);
			}
			EXP1 = ceil(round(0.9 * 10000.0 * EXP1) / 10000);
			check(EXP1, 0, 600);
			//cout<<"exp1b: "<<EXP1<<endl;

		}
		else {
			M1 = 0;
		}
	}
	else {
		while (true) {
			if (HP1 < 200) {
				HP1 += ceil(round(0.3 * 10000.0 * HP1) / 10000);
				check(HP1, 0, 666);
				M1 -= 150;
				check(M1, 0, 3000);
			}
			else {
				HP1 += ceil(round(0.1 * 10000.0 * HP1) / 10000);
				check(HP1, 0, 666);
				M1 -= 70;
				check(M1, 0, 3000);
			}
			if (M1 <= (m / 2)) {
				break;
			}
			if (EXP1 < 400) {
				M1 -= 200;
				check(M1, 0, 3000);
			}
			else {
				M1 -= 120;
				check(M1, 0, 3000);
			}
			EXP1 += ceil(round(0.13 * 10000.0 * EXP1) / 10000);
			check(EXP1, 0, 600);
			if (M1 <= (m / 2)) {
				break;
			}
			if (EXP1 < 300) {
				M1 -= 100;
				check(M1, 0, 3000);
			}
			else {
				M1 -= 120;
				check(M1, 0, 3000);
			}
			EXP1 = ceil(round(0.9 * 10000.0 * EXP1) / 10000);
			check(EXP1, 0, 600);
			if (M1 <= (m / 2)) {
				break;
			}
		}
	}

	EXP1 = ceil(round(1.17 * 10000.0 * EXP1) / 10000);
	check(EXP1, 0, 600);
	HP1 = ceil(round(0.83 * 10000.0 * HP1) / 10000);
	check(HP1, 0, 666);
	if (M1 < 0) {
		M1 = 0;
	}
	int s2; double P2;
	s2 = cp(EXP1);
	if (EXP1 >= s2) {
		P2 = 100;
	}
	else {
		P2 = 100.0 * (1.0 * EXP1 / s + 80.0) / 123.0;
	}
	if (EXP1 >= s2) {
		P2 = 100;
	}
	else {
		P2 = 100.0 * (1.0 * EXP1 / s2 + 80.0) / 123.0;
	}
	//con duong 3
	int Pi[10] = { 32,47,28,79,100,50,22,83,64,11 };
	int P3;
	if (E2 < 10) {
		P3 = Pi[E2];
	}
	else {
		int sum2number = (int)(E2 / 10) + (E2 % 10);
		int temp = sum2number % 10;
		P3 = Pi[temp];
	}
	double P = 1.0 * (P1 + P2 + P3) / 3.0;
	if (P == 100) {
		EXP1 = ceil(round(0.75 * 10000.0 * EXP1) / 10000);
		check(EXP1, 0, 600);
		// cout<<"exp1f: "<<EXP1<<endl;
	}
	else {
		// cout<<"p: "<<P<<"p1: "<<P1<<"p2: "<<P2<<"p3: "<<P3<<endl;

		if (P < 50) {
			EXP1 = ceil(round(1.15 * 10000.0 * EXP1) / 10000);
			check(EXP1, 0, 600);
			HP1 = ceil(round(0.85 * 10000.0 * HP1) / 10000);
			check(HP1, 0, 666);
		}
		else {
			EXP1 = ceil(round(1.2 * 10000.0 * EXP1) / 10000);
			check(EXP1, 0, 600);
			HP1 = ceil(round(0.9 * 10000.0 * HP1) / 10000);
			check(HP1, 0, 666);
		}
	}
	//cout << "HP1: " << HP1 << " EXP1: " << EXP1 << " M1: " << M1 << " kq: " << EXP1 + M1 + HP1<<endl;
	return HP1 + EXP1 + M1;
}



// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
	if (E3 < 0  || E3 > 99)
		return -99;
	int cheotrai;
	int cheophai;
	int kq;
	int taxi[10][10];
	int sw[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);//ma tran taxi
			//cout<<taxi[i][j]<<"  ";
		}
		//cout<<endl;
	}

	for (int j = 0; j <= 9; j++) {
		for (int i = 0; i <= 9; i++) {
			// duong cheo trai
			if (i < j) {
				cheotrai = taxi[0][j - i];
				for (int k = 0; k < 10 - j + i; k++) {
					if (cheotrai < taxi[k][k + j - i]) {
						cheotrai = taxi[k][k + j - i];
					}
				}
			}
			else {
				cheotrai = taxi[i - j][0];
				for (int k = 0; k < 10 - i + j; k++) {
					if (cheotrai < taxi[k + i - j][k]) {
						cheotrai = taxi[k + i - j][k];
					}
				}
			}
			//duong cheo phai
			if (i > 9 - j) {
				cheophai = taxi[i + j - 9][9];
				for (int k = 0; k < 10 - (i + j - 9); k++) {
					if (cheophai < taxi[k + i + j - 9][9 - k]) {
						cheophai = taxi[k + i + j - 9][9 - k];
					}
				}
			}
			else {
				cheophai = taxi[0][i + j];
				for (int k = 0; k <= i + j; k++) {
					if (cheophai < taxi[k][i + j - k]) {
						cheophai = taxi[k][i + j - k];
					}
				}
			}
			sw[i][j] = abs(max(cheotrai, cheophai));
		}
	}
	//cout<<"cheotrai: "<<cheotrai<<" cheophai: "<<cheophai<<endl;
	int n = 0;//sl >e3*2
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (taxi[i][j] > E3 * 2)
				n++;

		}
	}
	int m = 0;//sl < -e3
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (taxi[i][j] < -E3)
				m++;
		}
	}
	if (n > 9) {
		n = n / 10 + n % 10;
		n = n / 10 + n % 10;
	}
	if (m > 9) {
		m = m / 10 + m % 10;
		m = m / 10 + m % 10;
	}
	// vi tri gap nhau tai(n,m)
	if (abs(taxi[n][m]) > sw[n][m]) {
		EXP1 = ceil(round(0.88 * EXP1 * 10000) / 10000);
		check(EXP1, 0, 600);
		//cout<<"exp1a: "<<EXP1<<endl;
		EXP2 = ceil(round(0.88 * EXP2 * 10000) / 10000);
		check(EXP2, 0, 600);
		//cout<<"exp2a: "<<EXP2<<endl;
		HP1 = ceil(round(0.9 * HP1 * 10000) / 10000);
		check(HP1, 0, 666);
		//cout<<"hp1a: "<<HP1<<endl;
		HP2 = ceil(round(0.9 * HP2 * 10000) / 10000);
		check(HP2, 0, 666);
		//cout<<"hp2a: "<<HP2<<endl;
		kq = taxi[n][m];
		//cout<<"kq1: "<<kq<<endl;
	}
	else {
		EXP1 = ceil(round(1.12 * EXP1 * 10000) / 10000);
		check(EXP1, 0, 600);
		//cout << "exp1b: " << EXP1 << endl;
		EXP2 = ceil(round(1.12 * EXP2 * 10000) / 10000);
		check(EXP2, 0, 600);
		//cout << "exp2b: " << EXP2 << endl;
		HP1 = ceil(round(1.1 * HP1 * 10000) / 10000);
		check(HP1, 0, 666);
		//cout << "hp1b: " << HP1 << endl;
		HP2 = ceil(round(1.1 * HP2 * 10000) / 10000);
		check(HP2, 0, 666);
		//cout << "hp2b: " << HP2 << endl;
		kq = sw[n][m];
		//cout<<"kq2: "<<kq<<endl;
	}
	return kq;
}



// Task 4

int checkPassword(const char* s, const char* email) {
	// TODO: Complete this function
	string pw = s;
	string mail = email;
	string se = mail.substr(0, mail.find("@"));
	//nho hon 8
	if (pw.length() < 8) {
		return-1;
	}
	//lon hon 20
	if (pw.length() > 20) {
		return -2;
	}
	//pass khong chua se
	int vitri = pw.find(se);
	//if (vitri < pw.length()) {
	if (pw.find(se) != string::npos) {
		return -(300 + vitri);
	}
	//chua nhieu hon 2 kt lien tiep thi khong thoa
	for (int i = 0; i < pw.length() - 2; i++) {
		if (pw[i] == pw[i + 1] && pw[i + 1] == pw[i + 2]) { //yc de bai:khong chua NHIEU HON 2 ki tu,2 ki tu lien tiep giong nhau van hop le
			return -(400 + i);
		}
	}
	//bat buoc chua it nhat 1 ki tu dac biet
	string ky_tu_dacbiet = "@#%$!";
	//cout << "lenght: " << pw.length()<<endl;
	for (int i = 0; i < pw.length(); i++) {
		char c = pw[i];
		int dk = ky_tu_dacbiet.find(c); // nếu c có xuat hien trong chuoi ky_tu_dacbiet thi tra ve so thu tu, khong co tra ve -1
		if (dk !=-1){
			break;
		}
		if (i == (pw.length() - 1)) {
			//cout << "   " << -5 << "   " << endl;
			return -5;
		}
	}
	// bac buoc phai la chu thuong hoac chu Hoa hoac so hoac ky tu dac biet
		
	for (int i = 0; i < pw.length(); i++) {
		char c = pw[i];
		int dk1 = isdigit(c); // kiem tra ky tu pw[i], neu la so tra ve 1, khong la so tra ve 0
		int dk2 = isalpha(c); // kiem tra ky tu pw[i], neu la chu tra ve 1, khong la chu tra ve 0
		int dk3 = ky_tu_dacbiet.find(c); // nếu c có xuat hien trong chuoi ky_tu_dacbiet thi tra ve so thu tu, khong co tra ve -1
		if (dk1 == 0 && dk2 == 0 && dk3 == -1){		// kiem tra c, neu khong la chu va khong la so va khong la ky tu dac biet la khong hop le
		//cout << "khong la chu-so-ktdb   " << i << "  " << pw <<endl;
			return i;
		}
	}
	return -10;
}


// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
	// TODO: Complete this function
	string count[30]={""}; // tao mang phu de ghi mk khac biet
	int count_val[30] = { 0 }; // tao mang phu chu so lan xuat hien tuong ung mang tren
	int m = 0;
	for (int i = 0; i < num_pwds; ++i) {
		bool found = false;
		for (int j = 0; j < 30; ++j) {
			if (arr_pwds[i] == count[j]) {	// neu mk mang phu co mk phan tu mang chinh thi tang so lan len 1
				count_val[j]++;
				found = true;
				break;
			}
		}
		if (!found) {
			count[m] = arr_pwds[i];	// neu mk mang countng phu chua co thi ghi vao va so luong duoc gan bang 1
			count_val[m]++;
			m += 1;
			
		}
	}
	//cout << m<<' ';

	//for (int i=0; i<30; i++){
	//	cout << count[i] << " " << count[i].length() << " " << count_val[i] << "\n";
	//}
	//cout << "\n";

	int dem_max = -1;
	for (int i = 0; i < 30; ++i) {
		//if (!count[i].empty()) { //quet trong mang chua so lan, neu phan tu nao lon hon dem_mã thi gan vao, muc dich tim so lon nhat
			if (dem_max < count_val[i]) {
				dem_max = count_val[i];
			}
		//}
	}
	//cout << "\n";
	//cout << dem_max;
	// tim all ptu co sl =  dem max
	string pw_dai_max;
	int do_dai = 0;
	int vitri = -1;
	for (int i = 0; i < 30; ++i) {
		if (count_val[i] == dem_max) {	// khi quet den phan tu thu i co gia tri bang dem_max thi..
			if (do_dai < count[i].length()) {	// so sanh cac mk cung so luong neu cai nao dai hon thi cap nhat lai gia tri vao bien
				do_dai = count[i].length();
				pw_dai_max = count[i];
			}
		}
	}
	for (int i = 0; i<num_pwds; i++){
		if (arr_pwds[i] == pw_dai_max) {
			vitri = i;
			break;
		}
	}
	//cout<<"\nkq:"<<vitri<<endl;

	return vitri;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////