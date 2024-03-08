#include "study_in_pink1.h"

void update_money(int &money){
    if (money < 0) money = 0;

    if (money > 3000) money = 3000;
}

void update_health(int &hp){
    if (hp < 0) hp = 0;

    if (hp > 666) hp = 666;
}

void update_exp (int &exp) {
    if (exp < 0) exp = 0;

    if (exp > 600) exp = 600;
}

// for second road
void regen(int &HP1, int &M1) {
    if (M1 == 0) return;
    
    if (HP1 < 200) {
            M1 -= 150;
            int adder = ceilf(double(HP1)*0.3);
            HP1 += adder;

            update_money(M1);
            update_health(HP1);
        }
        else {
            // ceil up the amount
            int adder = ceilf(double(HP1)*0.1);
            HP1 += adder;

            M1 -= 70;
            update_money(M1);
            update_health(HP1);
        }
}
void vehicle(int &EXP1, int &M1){
    if (M1 == 0) return;
    // phương tiện đi lại
        if (EXP1 < 400) {   // chọn đi taxi
            M1 -= 200;
            update_money(M1);
        }
        else {  // chọn đi xe ngựa 
            M1 -= 120;
            update_money(M1);
        }
    EXP1 = ceilf(double(EXP1)*1.13);
    update_exp(EXP1);
}

void homeless(int &EXP1, int &M1) {
    if (M1 == 0) return;

    if (EXP1 <300) {
        M1 -= 100;
        update_money(M1);
    }
    else {
        M1 -= 120;
        update_money(M1);
    }

    EXP1 = ceilf(EXP1*0.9);
    update_exp(EXP1);
}
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
    update_exp(exp1);
    update_exp(exp2);

    if (e1 > 99 || e1 < 0) return -99;  // mã sự kiện không hợp lệ

    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0){
            exp2 += 29;
        }
        else if (e1 == 1) {
            exp2 += 45;
        }
        else if (e1 == 2){
            exp2 += 75;
        }
        else if (e1 == 3){
            exp2 += 149;
        }
        double D = e1*3 + exp1*7;
        int C = e1*3 + exp1*7;
        if (C % 2 == 0)  exp1 += ceilf(D/200);
        else exp1 -= floorf(D/100);
    }


    if (e1 >= 4 && e1 <= 99){
        float adder = 0;
        if (e1 >= 4 && e1 <= 19){  // thông tin 1
            adder = ceilf(float(e1)/4) + 19;
            exp2 += adder;
        }
        else if (e1 >= 20 && e1 <= 49){ // thông tin 2
            adder = ceilf(float(e1)/9) + 21;
            exp2 += adder;

        }
        else if (e1 >= 50 && e1 <= 65){ // thông tin 3
            adder = ceilf(float(e1)/16) + 17;
            exp2 += adder;

        }
        else if (e1 >= 66 && e1 <= 79){ // thông tin 4
            adder = ceilf(float(e1)/4) + 19;
            exp2 += adder;

            if (exp2 > 200) {
                adder = ceilf(float(e1)/9) + 21;
                exp2 += adder;
            }
        }
        else if (e1 >= 80 && e1 <= 99){ // thông tin 5
            adder = ceilf(float(e1)/4) + ceilf(float(e1)/9) + 19 + +21; 
            exp2 += adder;

            if  (exp2 > 400) {
                adder = ceilf (float(e1)/16) + 17;
                exp2 += adder;
                exp2 = exp2*115;
                exp2 = ceilf(float(exp2)/100);
            }
        }
        if (exp2 > 600) exp2 = 600;
        
        exp1 -= e1; // exp của Sherlock bị trừ đi e1 đơn vị vì đoán sai giới tính
        if (exp1 < 0) exp1 = 0;

    }

    update_exp(exp1);
    update_exp(exp2);

    return exp1 + exp2;
}

// Task 2
int closestSquareNum (int num){
    int Sqrt = sqrt(num);
    if (Sqrt*Sqrt == num) return num;


    int small = floor(sqrt(float(num)));
    int large = small +1;

    return ((large*large - num) < (num-small*small))? large*large : small*small;

}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    update_exp(EXP1);
    update_health(HP1);
    update_money(M1);
    if (E2 < 0 || E2 > 99 || M1 == 0) return -99;
    // TODO: Complete this function
    int S = closestSquareNum(EXP1);
    double P1 = 100, P2= 100, P3 = 100;
    
    // xử lý con đường thứ 1
    if (EXP1 < S) {
        P1 = (double(EXP1)/ double(S) + 80)/123; 
        P1 *= 100;
    }

    // xử lý con đường thứ 2
    if (E2 % 2 == 0) {
        regen(HP1, M1);
        vehicle(EXP1, M1);
        homeless(EXP1,M1);        
    }
    else {
        int cost = 0, left = M1/2;
        while (M1 > left) {
            regen(HP1, M1);
            if (M1 < left) break;
            vehicle(EXP1, M1);
            if (M1 < left) break;
            homeless(EXP1,M1); 
            
        }
    }
    HP1 = ceilf(double(HP1)*0.83);
    EXP1 = ceilf(EXP1 * 1.17);

    update_exp(EXP1);
    S = closestSquareNum(EXP1);
    if (EXP1 < S) {
        P2 = (double(EXP1)/ double(S) + 80)/123; 
        P2 *= 100;
        // P2 = roundf(P2*100);
    }


    // Xử lý con đường thứ 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 <= 9) P3 = P[E2];
    else {
        int temp = E2;
        int cnt = 0;
        cnt += temp%10;
        temp /= 10;
        cnt += temp%10;
        cnt %= 10;
        P3 = P[cnt];
    }  


    double Prob = ((P1+P2+P3)/3);
    if (Prob == 100) {
        EXP1 = ceilf (EXP1*0.75);
    }
    else if (Prob >= 50) {
        EXP1 = ceilf (float(EXP1)*1.2);
        update_exp(EXP1);
        HP1 = ceilf (double(HP1)*0.9);
    }
    else {
        EXP1 = ceilf (EXP1*1.15);
        update_exp(EXP1);
        HP1 = ceilf (double(HP1) * 0.85);
    }
    return HP1 + EXP1 + M1;
}



// Task 3
void update_score(int (&race)[10][10], int (&score)[10][10]) {
    for (int i = 0 ; i < 10 ; i++){
        for (int j = 0 ; j < 10 ; j++){
            int largest = race[i][j];

            int row = i , col = j;
            while (row > 0 && col > 0) {
                largest = (race[row][col] > largest)? race[row][col] : largest;
                row--; col--;
            }

            row = i, col = j;
            while (row < 10 && col < 10) {
                largest = (race[row][col] > largest)? race[row][col] : largest;
                row++; col++;
            }

            row = i, col = j;
            while (row > 0 && col < 10) {
                largest = (race[row][col] > largest)? race[row][col] : largest;
                row--; col++;
            }

            row = i, col = j;
            while (row < 10 && col > 0) {
                largest = (race[row][col] > largest)? race[row][col] : largest;
                row++; col--;
            }
            score[i][j] = abs(largest);
        }

    }
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    update_health(HP1);
    update_health(HP2);
    update_exp(EXP1);
    update_exp(EXP2);
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;
    
    // khởi tạo ma trận 10X10

    const int cols = 10, rows = 10;
    int race[cols][rows] = {0};
    int score[cols][rows] = {0};
    int getI =0 , getJ =0;
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            race[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (race[i][j] > E3*2)
                getI+=1;
            if (race[i][j] < -E3)
                getJ+=1;
        }

    }
    update_score(race, score);

    // cập nhật (i,j)
    
    while (getI >= 10){
        getI = getI%10 + getI/10;
    }
    while (getJ >= 10){
        getJ = getJ%10 + getJ/10;
    }

    if (abs(race[getI][getJ]) > score[getI][getJ]) {
        EXP1 = ceilf (float(EXP1)*0.88);
        EXP2 = ceilf (float(EXP2)*0.88);
        HP1 = ceil (HP1*0.9);
        HP2 = ceil (HP2*0.9);
    }
    else {
        EXP1 = ceilf (float(EXP1)*1.12);
        EXP2 = ceilf (float(EXP2)*1.12);
        HP1 = ceilf (HP1*1.1);
        HP2 = ceilf (HP2*1.1);
        update_exp(EXP1);
        update_exp(EXP2);
        update_health(HP1);
        update_health(HP2);

    }
    return (abs(race[getI][getJ]) > score[getI][getJ])? race[getI][getJ] :score[getI][getJ];
}

// Task 4
bool check_valid_char (char s){
    int ascii = int(s);
    if (ascii == 33 || ascii == 64 || ascii == 35 || ascii == 36 || ascii == 37) return 1;
    if (    (s>='A' && s<='Z')  ||  (s>='a' && s<='z')   ||  (s>='0' && s<='9')) return 1;

    return 0;
}
int check_valid_pass (string password, string email) {
    if (password.length() < 8) return -1;
    if (password.length() > 20) return -2;

    size_t found = password.find(email);
    if (found != string::npos) return -(300+found);
     
    for  (unsigned i = 0 ; i < password.length()-1;i++){
        if (password[i] == password[i+1] && password[i+2] == password[i])
            return -(400+i);
    }

    // tìm ký tự đặc biệt
    
    bool met = 0;
    for (unsigned int i = 0 ; i < password.length() ; i++){
        if (password[i] == '!' || password[i] == '@' || password[i] == '#'
        || password[i] == '$' || password[i] == '%')
        {
            met = 1;
            break;
        }
    }

    if (met == 0) return -5;

    for (unsigned int i = 0 ; i < password.length() ; i++){
        if (check_valid_char(password[i]) == 0){
            return i;}
    }
    return -10;
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string TEMP = email, PASS = s;
    string EMAIL="";
    for (char c : TEMP){
        if (c == '@')
            break;
        EMAIL += c;
    }
    int res = -10;
    res = check_valid_pass(PASS, EMAIL);
    return res;
}


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxcount = 0, res = 0; 
	string element_having_max_freq =""; 
	for (int i = 0; i < num_pwds; i++) { 
		int count = 1; 
        string temp = arr_pwds[i]; 
		for (int j = i+1; j < num_pwds; j++) { 
            string temp1 = arr_pwds[j]; 
			if (temp == temp1) 
				count++; 
		} 

		if (count > maxcount) { 
			maxcount = count; 
			element_having_max_freq = arr_pwds[i]; 
            res = i;
		}
        else if (count == maxcount) {
            string temp = arr_pwds[i];
            if (temp.length() > element_having_max_freq.length()){
                element_having_max_freq = temp;
                res = i;
            }
        }
	} 

	return res;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////