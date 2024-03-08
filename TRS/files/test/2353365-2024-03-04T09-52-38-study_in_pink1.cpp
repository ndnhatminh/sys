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

/* ------ CHECK HP, EXP, M ------ */
int EXP_Check(int exp){
	if (exp < 0) return 0;
    else if (exp > 600) return 600;
    else return exp;
}
int HP_Check(int hp){
	if (hp < 0) return 0;
    else if (hp > 666) return 666;
    else return hp;
}
int M_Check(int m){
	if (m < 0) return 0;
    else if (m > 3000) return 3000;
    else return m;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1)
{
    //TODO: implement task
    if(e1 < 0 || e1 > 99) return -99;
    
    double a = 0;
    int d = 0;
    /* ----- CASE 1: E1 IN RANGE [0,3] -----*/
    if (e1 >= 0 && e1 <= 3) {
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
                exp2 += 29 + 45 + 75;
                break;
        }
        d = e1 * 3 + exp1 * 7;
        if (d % 2 == 0) exp1 = ceil(float(exp1) + float(d) / 200);
        else exp1 = ceil(float(exp1) - float(d) / 100);
        exp1 = EXP_Check(exp1);
        exp2 = EXP_Check(exp2);
    }
    /* ----- CASE 2: E1 IN RANGE [4,99] -----*/
    else 
    if (e1 >= 4 && e1 <= 99){
        if (e1 >= 4 && e1 <= 19){
            a = exp2 + double(e1) / 4 + 19;
            exp2 = ceil(a);
        }
        else if (e1 >= 20 && e1 <= 49){
            a = exp2 + double(e1) / 9 + 21;
            exp2 = ceil(a);
        } 
        else if (e1 >= 50 && e1 <= 65){
            a = exp2 + double(e1) / 16 + 17;
            exp2 = ceil(a);
        }
        else if (e1 >= 66 && e1 <= 79) {
            a = exp2 + double(e1) / 4 + 19;
            exp2 = ceil(a);
            exp2 = EXP_Check(exp2);
            if (exp2 > 200){
                a = exp2 + double(e1) / 9 + 21;
                exp2 = ceil(a);
            }
        } 
        else if (e1 >= 80 && e1 <= 99) {
            a = exp2 + double(e1) / 4 + 19;
            exp2 = ceil(a);
            exp2 = EXP_Check(exp2);
            a = exp2 + double(e1) / 9 + 21;
            exp2 = ceil(a);
            exp2 = EXP_Check(exp2);
            if (exp2 > 400){
                a = exp2 + double(e1) / 16 + 17;
                exp2 = ceil(a);
                exp2 = EXP_Check(exp2);
                exp2 = ceil(float(exp2) * 1.15);
            }
        }
        exp1 = exp1 - e1;
    }
    exp1 = EXP_Check(exp1);
    exp2 = EXP_Check(exp2);
    int t = exp1 + exp2;
    /* ----- RETURN VALUE ----- */
    return t;
}

// Task 2
bool perfect_square(int x){
	int temp = round(sqrt(x));
	bool check = false;
	for (int i = temp - 2; i < temp + 2; i++)
	if (i*i == x) check = true;
	return check;
}
double update_prob(int exp){
	int pos = exp, neg = exp;
	double p = 0;
	bool check = false;
	if (perfect_square(exp)){
		check = true;
		p = 1;
	}
	while (check == false){
		pos++;
		neg--;
		if (perfect_square(neg)){
			p = 1;
			check = true;
		}
		if (perfect_square(pos)){
			p = (float(exp) / pos + 80) / 123;
			check = true;
		} 		
	}
	return p;
}
void Health(int & HP, int & M){
    if (HP < 200) {
        HP = ceil(double(HP) * 1.3);
        M -= 150;
    }
    else {
        HP = ceil(double(HP) * 1.1);
        M -= 70;
    }
    HP = HP_Check(HP);
    M = M_Check(M);
}
void Transportation(int & EXP, int & M){
    if (EXP < 400) M -= 200;
    else M -= 120;
    EXP = ceil(double(EXP) * 1.13);
    EXP = EXP_Check(EXP);
    M = M_Check(M);
}
void Homeless(int & EXP, int & M){
    if (EXP < 300) M -= 100;
    else M -= 120;
    EXP = ceil(double(EXP) * 0.9);
    EXP = EXP_Check(EXP);
    M = M_Check(M);
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) 
{
    if ((E2 < 0) || (E2 > 99)) return -99; 
    /* ----- ROAD 1 ----- */
    double P1 = update_prob(EXP1);
    
    /* ----- ROAD 2 ----- */
    int temp = 1, initialM = M1;
    double Condition = M1 * 0.5;
    if (E2 % 2 == 1){
        while (temp == 1){
            if (initialM - M1 <= Condition) Health(HP1, M1);
            else break;
            
            if (initialM - M1 <= Condition) Transportation(EXP1, M1);
            else break;
            
            if (initialM - M1 <= Condition) Homeless(EXP1, M1);
            else break;
        }
    }
    else {
        while (temp == 1){
            if (M1 != 0) Health(HP1, M1);
            else break;
            if (M1 != 0) Transportation(EXP1, M1);
            else break;
            if (M1 != 0) Homeless(EXP1, M1);
            else break;
            temp--;
        }
    }
    
    HP1 = ceil(double(HP1) * 0.83);
    HP1 = HP_Check(HP1);
    EXP1 = ceil(double(EXP1) * 1.17);
    EXP1 = EXP_Check(EXP1);
    M1 = M_Check(M1);
    
    double P2 = update_prob(EXP1);
    
    /* ----- ROAD 3 ----- */
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 >= 10){
        E2 = (E2 % 10) + (E2 / 10);
        E2 = E2 % 10;
    }
    double P3 = double(P[E2]) / 100;
    
    double avg = (P1 + P2 + P3)/3;
    if (avg == 1) {
        EXP1 = ceil(double(EXP1) * 0.75);
        EXP1 = EXP_Check(EXP1);
    }
    else
    if (avg < 0.5) {
        EXP1 = ceil(double(EXP1) * 1.15);
        EXP1 = EXP_Check(EXP1);
        HP1 = ceil(double(HP1) * 0.85);
        HP1 = HP_Check(HP1);
    }
    else {
        EXP1 = ceil(double(EXP1) * 1.20);
        EXP1 = EXP_Check(EXP1);
        HP1 = ceil(double(HP1) * 0.90);
        HP1 = HP_Check(HP1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    if ((E3 < 0) || (E3 > 99)) return -99; 
    /* ----- TAXI POINTS MATRIX ----- */
    int arrTaxi[10][10] = {0};
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            arrTaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    
    /* ----- MEETING POSTITION ----- */
    int row = 0, col = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (arrTaxi[i][j] > (E3 * 2)) row++;
            if (arrTaxi[i][j] < (-E3)) col++;
        }
    }
    while (row >= 10){
        row = (row % 10) + (row / 10);
    }
    while (col >= 10){
        col = (col % 10) + (col / 10);
    }
    
    int pointSherWats = arrTaxi[row][col], pointTaxi = arrTaxi[row][col], plus_i = 0, plus_j = 0, minus_i = 0, minus_j = 0;

    for (int k = 0; k < 10; k++){
        plus_i = row + k;
        plus_j = col + k;
        minus_i = row - k;
        minus_j = col - k;
        if ((plus_i <= 9) && (plus_j <= 9) && arrTaxi[plus_i][plus_j] > pointSherWats)
            pointSherWats = arrTaxi[plus_i][plus_j];
        if ((plus_i <= 9) && (minus_j >= 0) && arrTaxi[plus_i][minus_j] > pointSherWats)
            pointSherWats = arrTaxi[plus_i][minus_j];
        if ((minus_i >= 0) && (plus_j <= 9) && arrTaxi[minus_i][plus_j] > pointSherWats)
            pointSherWats = arrTaxi[minus_i][plus_j];
        if ((minus_i >= 0) && (minus_j >= 0) && arrTaxi[minus_i][minus_j] > pointSherWats)
            pointSherWats = arrTaxi[minus_i][minus_j];
    }

        float num = 0;
    int abs_pointTaxi = abs(pointTaxi);
    if (pointSherWats >= abs_pointTaxi) {
        num = double(EXP1) * 1.12;
        EXP1 = ceil(num);
        EXP1 = EXP_Check(EXP1);  
        num = double(EXP2) * 1.12;
        EXP2 = ceil(num);
        EXP2 = EXP_Check(EXP2);
        num = double(HP1) * 1.10;
        HP1 = ceil(num);
        HP1 = HP_Check(HP1);   
        num = double(HP2) * 1.10;
        HP2 = ceil(num);
        HP2 = HP_Check(HP2); 
        return pointSherWats;
    }
    else{
        num = double(EXP1) * 0.88;
        EXP1 = ceil(num);
        EXP1 = EXP_Check(EXP1);  
        num = double(EXP2) * 0.88;
        EXP2 = ceil(num);
        EXP2 = EXP_Check(EXP2);
        num = double(HP1) * 0.90;
        HP1 = ceil(num);
        HP1 = HP_Check(HP1);   
        num = double(HP2) * 0.90;
        HP2 = ceil(num);
        HP2 = HP_Check(HP2);
        
        return pointTaxi;
    }
}

// Task 4

bool specialcharCheck(char c){
    if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') return true;
    else return false;
}

bool charCheck(char c){
    if ((48 <= c && c <= 57) || (65 <= c && c <= 90) || (97 <= c && c <= 122)) return true;
    else return false;
}

int checkPassword(const char *s, const char *email){
    string Email = email, se = "";
    string S = s;
    for (int i = 0; i < Email.length(); i++){
        if (Email[i] != '@') se = se + Email[i];
        else break;
    }
    int len = S.length();

    if (len < 8) return -1;
    else if (len > 20) return -2;
    else {
        
        
        int sei = S.find(se);
        if (0 <= sei && sei <= len) return -(300 + sei);
        
        for (int i = 0; i < len - 2; i++){
            if (S[i] == S[i+1] && S[i+1] == S[i+2]) return -(400 + i);
        }
        
        int count = 0;
        for (int i = 0; i < len; i++){
            if (specialcharCheck(S[i])) count++;
        }
        if (count == 0) return -5;
        for (int i = 0; i < len; i++){
            if ((!specialcharCheck(S[i])) && (!charCheck(S[i]))) return i;
        }
    }
    return -10;
}

// Task 5
bool check_length(const char *s1, const char *s2) {
    return strlen(s1) > strlen(s2);
}

int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    int count[num_pwds] = {0};

    for (int i = 0; i < num_pwds; i++) {
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
                count[i]++;
        }
    }

    int max = count[0], pos = 0;
    const char *correctPassword = arr_pwds[0];

    for (int i = 1; i < num_pwds; i++) {
        if (count[i] > max || (count[i] == max && check_length(arr_pwds[i], correctPassword))) {
            max = count[i];
            pos = i;
            correctPassword = arr_pwds[i];
        }
    }

    return pos;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////