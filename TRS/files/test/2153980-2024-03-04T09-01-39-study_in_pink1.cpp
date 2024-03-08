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
int cus_ceil(double a){
    int dec = a;
    if (a - dec <0.00001){
        return dec;
    }
    else {
        return ceil(a);
    }
}

//Check the range 
void check_money_range(int & m){
    if (m < 0){
        m = 0;
    }
    else if (m > 3000){
        m = 3000;
    }
}

void check_hp_range (int & hp){
    if (hp < 0){
        hp  = 0;
    }
    else if (hp > 666) {
        hp = 666;
    }
}

void check_exp_range(int & exp ){
    if (exp < 0 ) {
        exp = 0;
    }
    else if (exp  > 600){
        exp  = 600;
    }
}

// Task 1 
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 <0 || e1 > 99){
        return -99;
    }
    check_exp_range(exp1);
    check_exp_range(exp2);
    if ( 0 <= e1 && e1 <= 3){
        if (e1 == 0) {
            exp2 = exp2 + 29.0;
        }
        if (e1 == 1) {
            exp2 = exp2 + 45.0;
        }
        if (e1 == 2) {
            exp2 = exp2 + 75.0;
        }
        if (e1 == 3) {
            exp2 = exp2 + 29.0 + 45.0 + 75.0;
        }
        check_exp_range(exp2);
        int D = e1*3 + exp1*7;
        if (D % 2 == 0) {
            exp1 = cus_ceil(exp1 + D/200.0);
        }
        else {
            exp1 = cus_ceil(exp1 - D/100.0);
        }
        check_exp_range(exp2);
    }
    else if ( 4 <= e1 && e1 <= 99){
        if (4 <= e1 && e1 <= 19){
            exp2 = cus_ceil(exp2 + e1/4.0 +19.0);
            check_exp_range(exp2);
        }
        else if (20 <= e1 && e1 <= 49){ 
            exp2 = cus_ceil(exp2 + e1/9.0 + 21.0);
            check_exp_range(exp2);
        }
        else if (50 <= e1 && e1 <= 65){
            exp2 = cus_ceil(exp2 + e1/16.0 + 17.0);
            check_exp_range(exp2);
        }
        else if (66 <= e1 && e1 <= 79){
            exp2 = cus_ceil(exp2 + e1/4.0 +19.0);
            check_exp_range(exp2);
            if (exp2 > 200){
                exp2 = cus_ceil(exp2 + e1/9.0 + 21.0);
                check_exp_range(exp2);
            }
        }
        else if (80 <= e1 && e1 <= 99){
            exp2 = cus_ceil(exp2 + e1/4.0 +19.0);
            exp2 = cus_ceil(exp2 + e1/9.0 + 21.0);
            if (exp2 > 400){
                exp2 = cus_ceil(exp2 + e1/16.0 + 17.0);
                exp2 = cus_ceil(exp2*1.15);
            }
        }
        exp1 = exp1 - e1;
    }  
    check_exp_range(exp1);
    check_exp_range(exp2);
    return exp1 + exp2;
}

// Task 2
int nearest_perfect_square(int n){
    int i = 1;
    while (i*i < n ){
        i++;
    }
    int upper = i*i; 
    int lower = (i-1) * (i-1);
    if (n - lower < upper - n){
        return lower;
    }
    else if (n - lower > upper - n){
        return upper;
    }
    else {
        return lower;
    }
}

void first_event(int & HP1, int & M1){
    //First description
    if (HP1 < 200){
        HP1 = cus_ceil(HP1*1.3);
        M1 = M1 -150;
    }
    else {
        HP1 = cus_ceil(HP1*1.1);
        M1 = M1 - 70;
    }
}

void second_event(int & EXP1, int & HP1, int & M1){
    //Second description
    if (EXP1 < 400 ){
        M1 = M1 - 200;
    }
    else {
        M1 = M1 - 120;
    }
    EXP1 = cus_ceil(EXP1*1.13);
}

void third_event(int & EXP1, int & HP1, int & M1){
    //Third description
    if (EXP1 < 300){
        M1= M1 -100;
    }
    else {
        M1 = M1 - 120;
    }
    EXP1 = cus_ceil(EXP1*0.9);
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 <0 || E2 > 99){
        return -99;
    }
    check_exp_range(EXP1);
    check_hp_range(HP1);
    check_money_range(M1);

    int S;

    //Road 1
    S = nearest_perfect_square(EXP1);
    float P1;
    if (EXP1 >= S){
        P1 = 100;
    }
    else {
        P1 = (EXP1/S+80.0)/1.23;
    }

    //Road 
    if (E2 % 2 == 0){
        first_event(HP1, M1);
        check_hp_range(HP1);
        check_money_range(M1);
        if (M1 > 0){
            second_event(EXP1, HP1, M1);
            check_exp_range(EXP1);
            check_hp_range(HP1);
            check_money_range(M1);
        }
        if (M1 > 0){
            third_event(EXP1, HP1, M1);
            check_exp_range(EXP1);
            check_hp_range(HP1);
            check_money_range(M1);
        }
        HP1 = cus_ceil(HP1*0.83);
        EXP1 = cus_ceil(EXP1*1.17);
        check_exp_range(EXP1);
        check_hp_range(HP1);
    }
    else {
        if (M1 > 0){
            int initial_money = M1;
            while (initial_money - M1 <= initial_money/2){
                first_event(HP1, M1);
                check_hp_range(HP1);
                check_money_range(M1);
                if (initial_money - M1 > initial_money/2){
                    break;
                } 
                if (M1 > 0){
                    second_event(EXP1, HP1, M1);
                    check_exp_range(EXP1);
                    check_hp_range(HP1);
                    check_money_range(M1);
                }
                if (initial_money - M1 > initial_money/2){
                    break;
                }
                if (M1 > 0){
                    third_event(EXP1, HP1, M1);
                    check_exp_range(EXP1);
                    check_hp_range(HP1);
                    check_money_range(M1);
                }
            }
            HP1 = cus_ceil(HP1*0.83);
            EXP1 = cus_ceil(EXP1*1.17);
            check_exp_range(EXP1);
            check_hp_range(HP1);
        }
    }
    S = nearest_perfect_square(EXP1);
    float P2;
    if (EXP1 >= S){
        P2 = 100;
    }
    else {
        P2 = cus_ceil((EXP1/S+80.0)/1.23);
    }


    //Road 3
    float P3;
    int P_array[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10){
        P3 = P_array[E2];
    }
    else{
        int b = E2%10;
        int a = (E2-b)/10;
        int index = (a+b)%10;
        P3 = P_array[index];
    }

    //Final
    if (P1 == 100 && P2 == 100 && P3 == 100){
        EXP1 = cus_ceil(EXP1*0.75);
        check_exp_range(EXP1);
    }
    else {
        float P_average = (P1 + P2 + P3) / 3.0;
        if (P_average < 50) {
            HP1 = cus_ceil(HP1*0.85);
            EXP1 = cus_ceil(EXP1*1.15);
            check_exp_range(EXP1);
            check_hp_range(HP1);
        }
        else{
            HP1 = cus_ceil(HP1*0.9);
            EXP1 = cus_ceil(EXP1*1.2);
            check_exp_range(EXP1);
            check_hp_range(HP1);
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int reduce_sum(int & n){
    if (n == 100){
        return 1;
    }
    while (n >= 10){
        int sum = 0;
        sum = sum + n%10;
        sum = sum + (n-sum)/10;
        n = sum;
    }
    return n;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 <0 || E3 > 99){
        return -99;
    }

    //Init matrix
    int i_meet, j_meet;
    i_meet = 0;
    j_meet = 0;
    int taxi_matrix[10][10] = {};
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            taxi_matrix[i][j] = (E3*j + i*2)*(i-j);
            if (taxi_matrix[i][j] > 2*E3){
                i_meet++;
            }
            if (taxi_matrix[i][j] < - E3){
                j_meet++;
            }
        }
    }

    i_meet = reduce_sum(i_meet);
    j_meet = reduce_sum(j_meet);

    int taxi_loc = abs(taxi_matrix[i_meet][j_meet]);

    //Find the positio of Sherlock and Waston
    int sher_loc = taxi_matrix[i_meet][j_meet];
    
    for (int i = 0; i < 10; ++i) {
        int j = i_meet + j_meet - i;
        if (i >= 0 && i < 10 && j >= 0 && j < 10) {
            if (sher_loc < taxi_matrix[i][j]){
                sher_loc = taxi_matrix[i][j];    
            }
        }
    }
    
    for (int i = 0; i < 10; ++i) {
        int j = i_meet - j_meet + i;
        if (i >= 0 && i < 10 && j >= 0 && j < 10) {
            if (sher_loc < taxi_matrix[i][j]){
                sher_loc = taxi_matrix[i][j];
            }
        }
    }

    //cout << i_meet << " " << j_meet << endl;

    if (taxi_loc > sher_loc) {
        EXP1 = cus_ceil(EXP1*0.88);
        HP1 = cus_ceil(HP1*0.9);
        EXP2 = cus_ceil(EXP2*0.88);
        HP2 = cus_ceil(HP2*0.9);
        return taxi_matrix[i_meet][j_meet];
    }   
    else {
        //cout << cus_ceil(EXP1*1.12) << endl;
        EXP1 = cus_ceil(EXP1*1.12);
        HP1 = cus_ceil(HP1*1.1);
        EXP2 = cus_ceil(EXP2*1.12);
        HP2 = cus_ceil(HP2*1.1);
        check_exp_range(EXP1);
        check_exp_range(EXP2);
        check_hp_range(HP1);
        check_hp_range(HP2);
        return sher_loc;
    }
    
}

// Task 4
bool check_special_char(char c){
    return (c == '@' || c == '#' || c == '%' || c == '$' || c == '!');
}

bool check_valid_char(char c){
    return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || check_special_char(c));
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    //Initial variables
    int pass_length = strlen(s);
    bool contain_se = false;
    bool consecutive = false;
    bool present_special_char = false;
    bool find_invalid_char = false;
    int se_index, consecutive_index, invalid_index;
    
    const char* tail_gmail = strchr(email, '@');
    int se_length = tail_gmail - email;
    const char* se = email;

    //Check length
    if (pass_length < 8){
        return -1;
    }
    if (pass_length > 20){
        return -2;
    }

    //Check inside the string s
    for (int i = 0; i < pass_length; i++){
        //Check whether s contains se
        if (i + se_length <= pass_length && strncmp(s + i, se, se_length) == 0 && !contain_se) {
            se_index = i;
            contain_se = true;
        }

        if (i < pass_length - 2) {
            if (s[i] == s[i + 1] && s[i] == s[i + 2] && !consecutive) {
                consecutive = true;
                consecutive_index = i;
            }
        }
        
        //Check whether s contains special characters
        if (check_special_char(s[i]) && !present_special_char){
            present_special_char = true;
        }

        if (!check_valid_char(s[i]) && !find_invalid_char){
            find_invalid_char = true;
            invalid_index = i;
        }
        
    }
    
    if (contain_se){
        return -(300+se_index);
    }

    if (consecutive){
        return -(400 + consecutive_index);
    }

    if (!present_special_char){
        //Not contain special characters
        return -5;
    }

    if (find_invalid_char){
        return invalid_index;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    const int MAX_UNIQUE_PWDS = 30;
    int freq[MAX_UNIQUE_PWDS] = {0}; 
    int length[MAX_UNIQUE_PWDS] = {0}; 
    const char *unique_pwds[MAX_UNIQUE_PWDS]; 
    int unique_count = 0; 

    for (int i = 0; i < num_pwds; i++) {
        int found = -1;
        for (int j = 0; j < unique_count; j++) {
            if (strcmp(arr_pwds[i], unique_pwds[j]) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            freq[found]++;
        } else {
            unique_pwds[unique_count] = arr_pwds[i];
            freq[unique_count] = 1;
            length[unique_count] = strlen(arr_pwds[i]);
            unique_count++;
        }
    }

    int max_freq = 0;
    int max_length = 0;
    int ans = -1;

    for (int i = 0; i < unique_count; i++) {
        if (freq[i] > max_freq || (freq[i] == max_freq && length[i] > max_length)) {
            max_freq = freq[i];
            max_length = length[i];
            ans = i;
        }
    }

    for (int i = 0; i < num_pwds; i++) {
        if (strcmp(arr_pwds[i], unique_pwds[ans]) == 0) {
            return i;
        }
    }

    return -1;
    
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////