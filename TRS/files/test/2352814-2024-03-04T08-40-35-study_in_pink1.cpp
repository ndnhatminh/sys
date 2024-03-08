#include "study_in_pink1.h"
typedef unsigned long long int ulli;

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
int Hp_cap(int hp){
    hp = (hp > 666) ? 666 : ((hp < 0) ? 0 : hp);
    return hp;
}


int Exp_cap(int exp){
    exp = (exp > 600) ? 600 : ((exp < 0) ? 0 : exp);
    return exp;
}


int Money_cap(int m){
    m = (m > 3000) ? 3000 : ((m < 0) ? 0 : m);
    return m;
}


int Left_diagonal(int coor_x, int coor_y, int mat[10][10]){
    // Finding only a maximum value at positive points as a positive value > a negative value 
    int max_left = 0;
    
    if (coor_x > coor_y)
        for (int i = coor_x - coor_y, j = 0; i < 10; ++i, ++j)
            max_left = max(max_left, mat[i][j]);
    return max_left;
}


int Right_diagonal(int coor_x, int coor_y, int mat[10][10]){
    // Determining the start of the right diagonal position circumstantially by the sum of both coordinates x and y if x + y < 10 (using an isosceles right triangle's propertie)
    // Otherwise, y = x + y - 9 and x = 9 (y is calculated using an isosceles right triangle's propertie too)
    int i = (coor_x + coor_y < 10) ? coor_x + coor_y : 9,
        j = (coor_x + coor_y < 10) ? 0 : coor_x + coor_y - 9,
        max_right = 0;

    for (i, j; i > j; --i, ++j)
        max_right = max(max_right, mat[i][j]);
    return max_right;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;
    exp1 = Exp_cap(exp1);
    exp2 = Exp_cap(exp2);
    if (e1 >= 0 && e1 <= 3){
        exp2 = Exp_cap((e1 == 0) ? exp2 + 29 : ((e1 == 1) ? exp2 + 45 : ((e1 == 2) ? exp2 + 75 : exp2 + 149)));
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            exp1 = Exp_cap(ceil(exp1 + D / 200.0f));
        else
            exp1 = Exp_cap(ceil(exp1 - D / 100.0f));
    } 
    else if (e1 <= 19) exp2 = Exp_cap(exp2 + ceil(e1 / 4.0f + 19)); // Information 1
    else if (e1 <= 49) exp2 = Exp_cap(exp2 + ceil(e1 / 9.0f + 21)); // Information 2
    else if (e1 <= 65) exp2 = Exp_cap(exp2 + ceil(e1 / 16.0f + 17)); // Information 3
    else if (e1 <= 79){ // Information 1 + (Information 2 if satisfied the condition)
        exp2 = Exp_cap(exp2 + ceil(e1 / 4.0f + 19));
        if (exp2 > 200) 
            exp2 = Exp_cap(exp2 + ceil(e1 / 9.0f + 21));
    }
    else{ // Information 1 + Information 2 + (Information 3 if satisfied the condition)
        exp2 = Exp_cap(exp2 + ceil(e1 / 4.0f + 19) + ceil(e1 / 9.0f + 21));
        if (exp2 > 400){
            exp2 = Exp_cap((exp2 + ceil(e1 / 16.0f + 17)));
            exp2 = Exp_cap((exp2 % 20 == 0) ? exp2 * 1.15 : ceil(exp2 * 1.15f));
        }
    }
    if (e1 > 3) exp1 = Exp_cap(exp1 - e1);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    float tmp = EXP1, half_money = M1 / 2.0, fixed_M = M1, P1, P2, P3, final_P,
          P[10] = {0.32f, 0.47f, 0.28f, 0.79f, 1.0f, 0.5f, 0.22f, 0.83f, 0.64f, 0.11f};
    float S1 = ceil(sqrt(tmp)),
          S2 = floor(sqrt(tmp)),
          value = sqrt(tmp);
    //int e2 = E2;

    if (E2 < 0 || E2 > 99) return -99;
    HP1 = Hp_cap(HP1);
    EXP1 = Exp_cap(EXP1);

    // Road 1
    if (value == S1 || value == S2)
        P1 = 1;
    else
        P1 = (S1 - value > value - S2) ? 1 : (tmp / ((int)S1 * (int)S1 * 1.0f) + 80) / 123.0f;

    // Road 2
    M1 = Money_cap(M1);
    if (M1 > 0){
        if (E2 % 2 == 0){
            M1 = Money_cap((HP1 >= 200) ? M1 - 70 : M1 - 150);
            if (HP1 % 10 == 0)
                    HP1 = Hp_cap((HP1 >= 200) ? HP1 * 1.1 : HP1 * 1.3);
                else
                    HP1 = Hp_cap((HP1 >= 200) ? ceil(HP1 * 1.1f) : ceil(HP1 * 1.3f));
            if (M1 > 0){
                M1 = Money_cap((EXP1 >= 400) ? M1 - 120 : M1 - 200);
                EXP1 = Exp_cap(ceil(EXP1 * 1.13f));
                if (M1 > 0){
                    M1 = Money_cap((EXP1 >= 300) ? M1 - 120 : M1 - 100);
                    EXP1 = Exp_cap((EXP1 % 10 == 0) ? EXP1 * 0.9 : ceil(EXP1 * 0.9f));
                }
            }
        }
        else{
            while (half_money <= fixed_M){
                M1 = Money_cap((HP1 >= 200) ? M1 - 70 : M1 - 150);
                half_money += (HP1 >= 200) ? 70 : 150;
                if (HP1 % 10 == 0)
                    HP1 = Hp_cap((HP1 >= 200) ? HP1 * 1.1 : HP1 * 1.3);
                else
                    HP1 = Hp_cap((HP1 >= 200) ? ceil(HP1 * 1.1f) : ceil(HP1 * 1.3f));
                if (half_money > fixed_M)
                    break;
                M1 = Money_cap((EXP1 >= 400) ? M1 - 120 : M1 - 200);
                half_money += (EXP1 >= 400) ? 120 : 200;
                EXP1 = Exp_cap(ceil(EXP1 * 1.13f));
                if (half_money > fixed_M)
                    break;
                M1 = Money_cap((EXP1 >= 300) ? M1 - 120 : M1 - 100);
                half_money += (EXP1 >= 300) ? 120 : 100;
                EXP1 = Exp_cap((EXP1 % 10 == 0) ? EXP1 * 0.9 : ceil(EXP1 * 0.9f));
            }
        }
        HP1 = Hp_cap(ceil(HP1 * 0.83f));
        EXP1 = Exp_cap(ceil(EXP1 * 1.17f));
        tmp = EXP1;
        S1 = ceil(sqrt(tmp));
        S2 = floor(sqrt(tmp));
        value = sqrt(tmp);
        if (value == S1 || value == S2)
            P2 = 1;
        else
            P2 = (S1 - value > value - S2) ? 1 : (tmp / ((int)S1 * (int)S1 * 1.0f) + 80) / 123.0f;
    }
    else P2 = P1;

    // Road 3
    if (E2 > 9)
        E2 = (E2 / 10 + E2 % 10) % 10;
    P3 = P[E2];
    final_P = (P1 + P2 + P3) / 3.0f;
    if (P1 == P2 && P1 == P3) EXP1 = Exp_cap((EXP1 % 4 == 0) ? EXP1 * 0.75 : ceil(EXP1 * 0.75f));
    else if (final_P >= 0.5){
        HP1 = Hp_cap((HP1 % 10 == 0) ? HP1 * 0.9 : ceil(HP1 * 0.9f));
        EXP1 = Exp_cap((EXP1 % 5 == 0) ? EXP1 * 1.2 : ceil(EXP1 * 1.2f));
    }
    else{
        HP1 = Hp_cap((HP1 % 20 == 0) ? HP1 * 0.85 : ceil(HP1 * 0.85f));
        EXP1 = Exp_cap((EXP1 % 20 == 0) ? EXP1 * 1.15 : ceil(EXP1 * 1.15f));
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    HP1 = Hp_cap(HP1);
    HP2 = Hp_cap(HP2);
    EXP1 = Exp_cap(EXP1);
    EXP2 = Exp_cap(EXP2);
    
    // cnt_p represents coordinate x and cnt_n represents coordinate y of the meeting point after every calculation
    int i, j, cnt_p = 0, cnt_n = 0, temp;
    int matrix[10][10] = {};

    for (i = 0; i < 10; ++i)
        for (j = 0; j < 10; ++j){
            temp = (E3 * j + 2 * i) * (i - j);
            if (i != j){
                matrix[i][j] = temp;
                // Using temp as a decoy, so the increment does not matter if no condition is met
                ((temp > 2 * E3) ? cnt_p : ((temp < -E3) ? cnt_n : temp))++;
            }
        }

    // A matrix of 10 x 10 --> 100 elements - 10 0's on the i = j diagonal --> 45 negative and positive elements each
    // --> cnt_p and cnt_n each has a capped value at 45
    // --> Using div mod twice is enough (e.g. 38 -> 11 -> 2; 40 -> 4)
    cnt_p = cnt_p / 10 + cnt_p % 10;
    cnt_p = cnt_p / 10 + cnt_p % 10;
    cnt_n = cnt_n / 10 + cnt_n % 10;
    cnt_n = cnt_n / 10 + cnt_n % 10;

    int final_max = max(Left_diagonal(cnt_p, cnt_n, matrix), Right_diagonal(cnt_p, cnt_n, matrix));

    if (abs(matrix[cnt_p][cnt_n]) <= final_max){
        HP1 = Hp_cap((HP1 % 10 == 0) ? HP1 * 1.1 : ceil(HP1 * 1.1f));
        HP2 = Hp_cap((HP2 % 10 == 0) ? HP2 * 1.1 : ceil(HP2 * 1.1f));
        EXP1 = Exp_cap((EXP1 % 25 == 0) ? EXP1 * 1.12 : ceil(EXP1 * 1.12f));
        EXP2 = Exp_cap((EXP2 % 25 == 0) ? EXP2 * 1.12 : ceil(EXP2 * 1.12f));
        return final_max;
    }
    else{
        HP1 = Hp_cap((HP1 % 10 == 0) ? HP1 * 0.9 : ceil(HP1 * 0.9f));
        HP2 = Hp_cap((HP2 % 10 == 0) ? HP2 * 0.9 : ceil(HP2 * 0.9f));
        EXP1 = Exp_cap((EXP1 % 25 == 0) ? EXP1 * 0.88 : ceil(EXP1 * 0.88f));
        EXP2 = Exp_cap((EXP2 % 25 == 0) ? EXP2 * 0.88 : ceil(EXP2 * 0.88f));
        return matrix[cnt_p][cnt_n];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int i;
    string S = s, E = email, se = "", check = "@#%$!";
    const char *tmp;

    se = E.substr(0, strchr(email, '@') - email);
    
    const char* SE = se.c_str();

    if (S.length() < 8) return -1;
    else if (S.length() > 20) return -2;
    if (strstr(s, SE) != NULL) return -(300 + strstr(s, SE) - s);
    for (i = 0; i <= S.length() - 3; ++i)
        if (S[i] == S[i + 1] && S[i] == S[i + 2]) return -(400 + i);
    for (i = 0; i < 5; ++i){
        tmp = strchr(s, check[i]);
        if (tmp != NULL) break;
        else if (i == 4 && tmp == NULL) return -5;
    }
    for (i = 0; i < S.length(); ++i)
        if (!isalpha(S[i]) && !isdigit(S[i]))
            for (int j = 0; j < 5; ++j){
                if (S[i] == check[j]) break;
                else if (j == 4 && S[i] != check[j]) return i;
            }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    ulli max_length = 0;
	string s_temp, 
           sorted[num_pwds] = {}, 
           pass[num_pwds] = {};
	int i_temp,
        i, j, 
        min_occur = 31, max_cnt = 0, 
        cnt = 1, index = 0,
        index_sorted[num_pwds] = {};

    if (num_pwds == 1) return 0;
    else if (num_pwds == 2) return ((strlen(arr_pwds[0]) < strlen(arr_pwds[1])) ? 1 : 0);
    else{
        for (i = 0; i < num_pwds; ++i)
            pass[i] = arr_pwds[i];
        for (i = 0; i + 1 < num_pwds; ++i)
			for (j = i + 1; j < num_pwds; ++j) {
				if (pass[i] == pass[i - 1] && i != 0)
					break;
				if (pass[i].length() <= pass[j].length() && pass[i] != pass[j]) {
					s_temp = pass[i];
					pass[i] = pass[j];
					pass[j] = s_temp;
				}
			}
        for (i = 0; i + 1 < num_pwds; ++i) {
			if (pass[i] != pass[i + 1] && i + 2 == num_pwds){
				if (max_length < pass[i + 1].length() && max_cnt == 1)
					max_length = pass[i + 1].length();
				sorted[index] = pass[i + 1];
				index_sorted[index] = 1;
				index++;
			}
			if (pass[i] != pass[i + 1]){
				if (max_cnt < cnt) {
					max_length = pass[i].length();
					max_cnt = cnt;
				}
				sorted[index] = pass[i];
				index_sorted[index] = cnt;
				index++;
				cnt = 1;
			} else if (pass[i] == pass[i + 1] && i + 2 == num_pwds){
				cnt++;
				if (max_cnt < cnt) {
					max_length = pass[i].length();
					max_cnt = cnt;
				}
				sorted[index] = pass[i];
				index_sorted[index] = cnt;
				index++;
			} else cnt++;
        }
        for (i = 0; i < index; ++i)
            for (j = i + 1; j < index; ++j)
                if (index_sorted[i] < index_sorted[j] || sorted[i].length() < sorted[j].length() && index_sorted[i] == index_sorted[j]){
                    i_temp = index_sorted[i];
                    index_sorted[i] = index_sorted[j];
                    index_sorted[j] = i_temp;
                    s_temp = sorted[i];
                    sorted[i] = sorted[j];
                    sorted[j] = s_temp;
                }
        for (i = num_pwds - 1; i >= 0; --i)
			for (j = 0; j < index; ++j)
				if (arr_pwds[i] == sorted[j] && index_sorted[j] == max_cnt && strlen(arr_pwds[i]) == max_length)
					min_occur = (min_occur > i) ? i : min_occur;
    }
    return min_occur;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////