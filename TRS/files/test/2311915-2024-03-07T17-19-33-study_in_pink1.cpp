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
    if(ifs.is_open()) {
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
void task1_value_check(int & exp1, int & exp2){
    exp1 = max(exp1,0); exp1 = min(exp1,600);
    exp2 = max(exp2,0); exp2 = min(exp2,600);
}

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1 < 0 || e1 > 99) return -99;
    if(e1 >= 0 && e1 <= 3){
        switch(e1) {
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
        int d = e1 *3 + exp1*7;
        if(d%2==0) exp1 = ceilf((float)exp1 + d/200.0);
        else exp1 = ceilf((float)exp1 - d/100.0);
        task1_value_check(exp1, exp2);
    } else if(e1 >= 4 && e1 <= 99){
        if(e1 >= 4 && e1 <= 19) exp2 = ceilf((float)exp2 + e1/4.0 + 19.0);
        else if(e1 >= 20 && e1 <= 49) exp2 = ceilf((float)exp2 + e1/9.0 + 21.0);
        else if(e1 >= 50 && e1 <= 65) exp2 = ceilf((float)exp2 + e1/16.0 + 17.0);
        else if(e1 >= 66 && e1 <= 79){
            exp2 = ceilf((float)exp2 + e1/4.0 + 19.0);
            task1_value_check(exp1, exp2);
            if(exp2 > 200) exp2 = ceilf((float)exp2 + e1/9.0 + 21.0);
        } 
        else if(e1 >= 80 && e1 <= 99){
            exp2 = ceilf((float)exp2 + e1/4.0 + 19.0);
            task1_value_check(exp1, exp2);
            exp2 = ceilf((float)exp2 + e1/9.0 + 21.0);
            task1_value_check(exp1, exp2);
            if(exp2 > 400) {
                exp2 = ceilf((float)exp2 + e1/16.0 + 17.0);
                task1_value_check(exp1, exp2);
                exp2 = ceilf((float)exp2*1.15);
            }
        }
        exp1 -= e1;
        task1_value_check(exp1, exp2);
    }
    return exp1 + exp2;
}

// Task 2
void task2_value_check(int & HP1, int & EXP1, int & M1){
    HP1 = max(HP1,0); HP1 = min(HP1,666);
    EXP1 = max(EXP1,0); EXP1 = min(EXP1,600);
    M1 = max(M1,0); M1 = min(M1,3000);
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 < 0 || E2 > 99) return -99;
    task2_value_check(HP1, EXP1, M1);
    // Road 01
    int S = (EXP1 - pow((int)sqrt(EXP1),2)<=pow((int)sqrt(EXP1)+1,2) - EXP1)?pow((int)sqrt(EXP1),2):pow((int)sqrt(EXP1)+1,2);
    float P1 = (EXP1 >= S)? 1.0 : ((float)EXP1/S+80.0)/123.0;
    // Road 02
    bool status = (E2%2==1);
    int init_money = M1;
    int paid_money = 0;
    while(true){
        // event 1
        if(HP1 < 200){
            HP1 = ceilf((float)HP1*1.3);
            M1 -= 150;
            paid_money += 150;
        } else{
            HP1 = ceilf((float)HP1*1.1);
            M1 -= 70;
            paid_money += 70;
        }
        task2_value_check(HP1, EXP1, M1);
        if(status){
            if(paid_money>init_money*50/100) break; 
        } else{
            if(M1 == 0) break;
        }
        
        // event 2
        if(EXP1 < 400) {
            M1 -= 200;
            paid_money += 200;
        } else{
            M1 -= 120;
            paid_money += 120;
        }
        EXP1 = ceilf((float)EXP1*1.13);
        task2_value_check(HP1, EXP1, M1);
        if(status){
            if(paid_money>init_money*50/100) break;
        } else{
            if(M1 == 0) break;
        }

        // event 3
        if(EXP1 < 300){
            M1 -= 100;
            paid_money += 100;
        } 
        else {
            M1 -= 120;
            paid_money += 120;
        }
        EXP1 = ceilf((float)EXP1*0.9);
        task2_value_check(HP1, EXP1, M1);
        if(status){
            if(paid_money>init_money*50/100) break;
        }
        else break; 
    }
    HP1 = ceilf((float)HP1*0.83);
    EXP1 = ceilf((float)EXP1*1.17);
    task2_value_check(HP1, EXP1, M1);
    S = (EXP1 - pow((int)sqrt(EXP1),2)<=pow((int)sqrt(EXP1)+1,2) - EXP1)?pow((int)sqrt(EXP1),2):pow((int)sqrt(EXP1)+1,2);
    float P2 = (EXP1 >= S)? 1.0 : ((float)EXP1/S+80.0)/123.0;
    
    // Road 03
    int P_arr[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = (E2/10 + E2 %10)%10;
    float P3 = P_arr[i]/100.0;
    if(P1*P2*P3 == 1.0) EXP1 = ceilf((float)EXP1*0.75);
    else {
        float P = (P1+P2+P3)/3;
        if(P < 0.5){
            HP1 = ceilf((float)HP1*0.85);
            EXP1 = ceilf((float)EXP1*1.15);
        } else{
            HP1 = ceilf((float)HP1*0.9);
            EXP1 = ceilf((float)EXP1*1.2);
        }
        task2_value_check(HP1, EXP1, M1);
    }    
    return HP1 + EXP1 + M1;
}


// Task 3
void task3_value_check(int & HP1, int & EXP1, int & HP2, int & EXP2){
    HP1 = max(HP1,0); HP1 = min(HP1,666);
    EXP1 = max(EXP1,0); EXP1 = min(EXP1,600);
    HP2 = max(HP2,0); HP2 = min(HP2,666);
    EXP2 = max(EXP2,0); EXP2 = min(EXP2,600);
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(E3 < 0 || E3 > 99) return -99;
    task3_value_check(HP1, EXP1, HP2, EXP2);
    int matrix[10][10];
    int upper_num = 0;
    int lower_num = 0; 
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            matrix[i][j] = ((E3*j)+(i*2))*(i-j);
            if(matrix[i][j] > E3*2) upper_num++;
            else if(matrix[i][j] < -E3) lower_num++;
        }
    }
    int i = (upper_num/10 + upper_num%10)/10+(upper_num/10 + upper_num%10)%10, j = (lower_num/10 + lower_num%10)/10+(lower_num/10 + lower_num%10)%10;
    int left_diagonal_index = i-j, right_diagonal_index = i+j;
    int taxi_point = matrix[i][j];
    int SW_point = matrix[i][j];
    for(int x = 0; x < 10; x++){
        int y = left_diagonal_index + x;
        if(y >= 0 && y <= 10){
            if(matrix[y][x]>SW_point) SW_point=matrix[y][x];
        }
    }
    for(int x = 0; x < 10; x++){
        int y = right_diagonal_index - x;
        if(y >= 0 && y <= 10){
            if(matrix[y][x]>SW_point) SW_point=matrix[y][x];
        }
    }
    if(abs(taxi_point)>SW_point){
        EXP1 = ceilf((float)EXP1*0.88);
        EXP2 = ceilf((float)EXP2*0.88);
        HP1 = ceilf((float)HP1*0.9);
        HP2 = ceilf((float)HP2*0.9);
        task3_value_check(HP1, EXP1, HP2, EXP2);
        return taxi_point;
    } else{
        EXP1 = ceilf((float)EXP1*1.12);
        EXP2 = ceilf((float)EXP2*1.12);
        HP1 = ceilf((float)HP1*1.1);
        HP2 = ceilf((float)HP2*1.1);
        task3_value_check(HP1, EXP1, HP2, EXP2);
        return SW_point;
    }
}

// Task 4
int is_se_contained(const char * s, char * se, int s_len, int se_len){
    for(int i = 0; i < s_len-se_len+1; i++){
        for(int j = 0; j < se_len; j++){
            if(s[i+j]!=se[j]) break;
            if(j == se_len-1) return i;
        }
    }
    return -1;
}

int is_similar_char(const char * s, int s_len){
    for(int i = 0; i < s_len-1; i++){
        if(s[i] == s[i+1]) return i;
    }
    return -1;
}

bool is_special_char_contained(const char * s, int s_len){
    char special_char_array[] = {'!', '@', '#', '$', '%'};
    for(int i = 0; i < s_len; i++){
        for(char& sc : special_char_array) {
            if(s[i]==sc) return true;
        }
    }
    return false;
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int s_len = strlen(&s[0]);
    int se_len = 0;
    while(email[se_len]!='@') se_len++;
    char se[se_len];
    for(int i = 0; i < se_len; i++) se[i] = email[i];
    se[se_len] = '\0';

    int se_contained = is_se_contained(s, se, s_len, se_len);
    int similar_char = is_similar_char(s, s_len);
    bool special_char_contained = is_special_char_contained(s, s_len);
    if(s_len < 8) return -1;
    else if(s_len > 20) return -2;
    else if (se_contained != -1) return -(300+se_contained);
    else if (similar_char != -1) return -(400+similar_char);
    else if (special_char_contained) return -5;
    else return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxcount=0;
    for(int i = 0; i < num_pwds; i++){
        int count = -1;
        for(int j = 0; j < num_pwds; j++){
            if(arr_pwds[i] == arr_pwds[j]){
                count++;
            }
        }
        maxcount=max(maxcount,count);
    }
    
    int maxlen=0;
    for(int i = 0;i < num_pwds; i++){
        int count = -1;
        for(int j = 0 ; j < num_pwds;j++){
            if(arr_pwds[i] == arr_pwds[j]){
                count++;    
            }
        }
        if(count == maxcount){
            maxlen = max(maxlen, (int)strlen(arr_pwds[i]));
        }
    
    }
    for(int i = 0; i < num_pwds; i++){
        int count = -1;
        for(int j = 0; j < num_pwds; j++){
            if(arr_pwds[i] == arr_pwds[j]){
                count++;   
            }
        }
        if(count == maxcount && (int)strlen(arr_pwds[i]) == maxlen){
            return i;
        }
    }
    return -99;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////