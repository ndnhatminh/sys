#include "study_in_pink1.h"

using namespace std;

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


int adjustHP(int hp)
{
    return max(0, min(666, hp));
}

int adjustEXP(int exp){
    return max(0, min(600, exp));
}

int adjustMoney(int m){
    return max(0, min(3000, m));
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {

    if (e1<0){
        return -99;
    }
    exp1 = adjustEXP(exp1);
    exp2 = adjustEXP(exp2);
    // Case 1:

    if (0 <= e1 && e1 <= 3){
        if (e1==0){
            exp2+=29;
            exp2 = adjustEXP(exp2);
        }
        else if (e1==1){
            exp2+=45;
            exp2 = adjustEXP(exp2);
        }
        else if (e1==2){
            exp2+=75;
            exp2 = adjustEXP(exp2);
        }
        else if(e1==3){
            exp2+= 29 + 45 + 75;
            exp2 = adjustEXP(exp2);
        }
        int D=3*e1 + 7*exp1;
        if (D%2==0){
            exp1 = ceil(exp1+ float(D)/200);
            exp1 = adjustEXP(exp1);
        }
        else if (D%2!=0){
            exp1 = ceil(exp1- float(D)/100);
            exp1 = adjustEXP(exp1);
        }
    }

        // Case 2
    else if (4 <= e1 && e1 <= 99){
        if (4 <= e1 && e1 <= 19){
            exp2 += ceil(float(e1)/4 + 19);
            exp2 = adjustEXP(exp2);
        }
        else if (20 <= e1 && e1 <= 49){
            exp2 += ceil(float(e1)/9 + 21);
            exp2 = adjustEXP(exp2);
        }
        else if (50 <= e1 && e1 <= 65){
            exp2 += ceil(float(e1)/16 + 17);
            exp2 = adjustEXP(exp2);
        }
        else if (66 <= e1 && e1 <= 79){
            exp2 += ceil(float(e1)/4 + 19);
            exp2 = adjustEXP(exp2);
            if (exp2>200){
                exp2 += ceil(float(e1)/9 + 21);
                exp2 = adjustEXP(exp2);
            }
        }
        else if (80 <= e1 && e1 <= 99){
            exp2 += ceil(float(e1)/4 + 19.0);
            exp2 = adjustEXP(exp2);
            exp2 += ceil(float(e1)/9.0 + 21.0);
            exp2 = adjustEXP(exp2);
            if (exp2>400){
                exp2 += ceil(float(e1)/16.0 + 17.0);
                exp2 = adjustEXP(exp2);
                exp2 = ceil(float(exp2)*1.15);
                exp2 = adjustEXP(exp2);
            }

        }
        exp1 -= e1;
        exp1 = adjustEXP(exp1);
    }

    else{
        return -99;
    }
    return exp1 + exp2;

}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    EXP1 = adjustEXP(EXP1);
    HP1 = adjustHP(HP1);
    M1 = adjustMoney(M1);

    if (E2<0){
        return -99;
    }

    // Road 1
    int total_paid;
    int initial_half_budget = adjustMoney(ceil(M1*0.5));
    int S = 0;
    int diff = EXP1;
    float P1;
    float P2;
    for(int i=1;(i*i)<= 626; ++i)
    {
        if (diff > abs(EXP1 - (i*i)))
        {
            diff = abs(EXP1 - (i*i));
            S = i*i;
        }
    }

    if (EXP1 >= S){
        P1 = 1;
    }
    else if (EXP1 < S){
        P1 = (float(EXP1)/float(S) + 80)/123;
    }

    // Road 2:
    if (E2%2!=0){
        while (total_paid < initial_half_budget){
            if (HP1 < 200){
                HP1 = adjustHP(ceil(float(HP1)*1.3));
                M1 = adjustMoney(M1 - 150);
                total_paid += 150;
            }

            else {
                HP1 = adjustHP(ceil(float(HP1)*1.1));
                M1 = adjustMoney(M1 - 70);
                total_paid += 70;
            }

            if (total_paid > initial_half_budget){
                break;
            }

            if (EXP1 < 400){
                M1 = adjustMoney(M1 - 200);
                total_paid += 200;
            }
            else {
                M1 = adjustMoney(M1 - 120);
                total_paid += 120;
            }
            EXP1 = adjustEXP(ceil(float(EXP1)*1.13));

            if (total_paid > initial_half_budget){
                break;
            }

            if (EXP1 < 300){
                M1 = adjustMoney(M1 - 100);
                total_paid += 100;
            }
            else {
                M1 = adjustMoney(M1 - 120);
                total_paid += 120;
            }

            EXP1 = adjustEXP(ceil(float(EXP1)*0.9));
        }
        HP1 = adjustHP(ceil(float(HP1)*0.83));
        EXP1 = adjustEXP(ceil(float(EXP1)*1.17));
    }

    while (E2%2==0){
        if (HP1 < 200){
            HP1 = adjustHP(ceil(float(HP1)*1.3));
            M1 = adjustMoney(M1 - 150);
        }

        else {
            HP1 = adjustHP(ceil(float(HP1)*1.1));
            M1 = adjustMoney(M1 - 70);
        }

        if (M1==0){
            HP1 = adjustHP(ceil(float(HP1)*0.83));
            EXP1 = adjustEXP(ceil(float(EXP1)*1.17));
            break;
        }

        if (EXP1 < 400){
            M1 = adjustMoney(M1 - 200);
        }
        else {
            M1 = adjustMoney(M1 - 120);
        }
        EXP1 = adjustEXP(ceil(float(EXP1)*1.13));

        if (M1==0){
            HP1 = adjustHP(ceil(float(HP1)*0.83));
            EXP1 = adjustEXP(ceil(float(EXP1)*1.17));
            break;
        }

        if (EXP1 < 300){
            M1 = adjustMoney(M1 - 100);
        }
        else {
            M1 = adjustMoney(M1 - 120);
        }
        EXP1 = adjustEXP(ceil(float(EXP1)*0.9));

        HP1 = adjustHP(ceil(float(HP1)*0.83));
        EXP1 = adjustEXP(ceil(float(EXP1)*1.17));
        break;
    }

    if (EXP1 >= S){
        P2 = 1;
    }
    else if (EXP1 < S){
        P2 = (float(EXP1)/float(S) + 80)/123;
    }

    // Road 3:
    int digit_sum;
    int P_arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float P3;
    float avg_p;
    int j;
    int unit_place;
    bool all100s = true;
    if (E2<10){
        P3 = float(P_arr[E2])/100;
    }
    else{
        digit_sum = (E2%10) + (E2/10);
        unit_place = digit_sum%10;
        P3 = float(P_arr[unit_place])/100;
    }
    float Ps[3] = {P1, P2, P3};
    for (j=0;j<3;++j){
        if (Ps[j]!=0){
            all100s = false;
            break;
        }
    }
    if (all100s){
        EXP1 = adjustEXP(ceil(float(EXP1)*0.75));
    }
    else {
        avg_p = (P1 + P2 + P3)/3;
    }

    if (avg_p < 0.5){
        HP1 = adjustHP(ceil(float(HP1)*0.85));
        EXP1 = adjustEXP(ceil(float(EXP1)*1.15));
    }
    else{
        HP1 = adjustHP(ceil(float(HP1)*0.90));
        EXP1 = adjustEXP(ceil(float(EXP1)*1.20));
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    const int rows = 10;
    const int cols = 10;

    // Initialize a 10x10 matrix with each element set to 0
    int matrix[rows][cols];
    int greater_count = 0;
    int smaller_count = 0;

    if (E3<0){
        return -99;
    }
    // Access and print elements (optional)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (matrix[i][j]>(E3*2)){
                greater_count += 1;
            }
            else if (matrix[i][j] < (-E3)){
                smaller_count += 1;
            }
        }
    }

    int i_corr = greater_count;
    int j_corr = smaller_count;

    while (i_corr/10!=0){
        // Is a 2-digit number
        i_corr = i_corr/10 + i_corr%10;
    }

    while (j_corr/10!=0){
        // Is a 2-digit number
        j_corr = j_corr/10 + j_corr%10;
    }

    int taxi_grade = matrix[i_corr][j_corr];

    // Array to store elements in both left and right diagonals
    int diagonalElements[2 * rows];

    // Counters for left and right diagonals
    int diagonalCount = 0;

    // Iterate down the left diagonal
    for (int k = 0; i_corr + k < rows && j_corr + k < rows ; ++k) {
        diagonalElements[diagonalCount++] = matrix[i_corr + k][j_corr + k];
    }

    // Iterate up the left diagonal
    for (int k = 1; i_corr - k >= 0 && j_corr - k >= 0 ; ++k) {
        diagonalElements[diagonalCount++] = matrix[i_corr - k][j_corr - k];
    }

    // Iterate down the right diagonal
    for (int k = 1; i_corr + k < rows && j_corr - k >=0 ; ++k) {
        diagonalElements[diagonalCount++] = matrix[i_corr + k][j_corr - k];
    }

    // Iterate up the right diagonal
    for (int k = 1;i_corr - k >= 0 && j_corr + k < rows ; ++k) {
        diagonalElements[diagonalCount++] = matrix[i_corr - k][j_corr + k];
    }

    int max_grade = diagonalElements[0];
    for (int k = 0; k < diagonalCount; ++k) {
        if (diagonalElements[k] > max_grade){
            max_grade = diagonalElements[k];
        }
    }
    max_grade = abs(max_grade);

    if (abs(taxi_grade) > max_grade){
        EXP1 = adjustEXP(ceil(float(EXP1)*0.88));
        HP1 = adjustHP(ceil(float(HP1)*0.9));
        EXP2 = adjustEXP(ceil(float(EXP2)*0.88));
        HP2 = adjustHP(ceil(float(HP2)*0.9));
    }

    else
    {
        EXP1 = adjustEXP(ceil(float(EXP1)*1.12));
        HP1 = adjustHP(ceil(float(HP1)*1.1));
        EXP2 = adjustEXP(ceil(float(EXP2)*1.12));
        HP2 = adjustHP(ceil(float(HP2)*1.1));
    }

    if (max_grade>abs(taxi_grade)){
        return max_grade;
    }
    else if(max_grade<abs(taxi_grade)){
        return taxi_grade;
    }
    else{
        return max_grade;
    }

}

// Task 4
int checkPassword(const char * s, const char * email) {
    // s: string to check if valid
    // email: email string
    char se[100];
    int i;
    for (i=0; i< strlen(email); ++i){
        if (email[i] == '@'){
            break;
        }
        else{
            se[i] = email[i];
        }
    }
    se[i] = '\0';

    bool hasSpecialchar = false;

    // Check if has special chars
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            hasSpecialchar = true;
        }
    }

    // Check password length
    if (strlen(s) < 8){
        return -1;
    }
    else if (strlen(s)>20){
        return -2;
    }

    // check if s contains se
    const char* found = strstr(s, se);
    int negative_sei_val;
    if (found != nullptr) {
        // Calculate the index
        size_t index = found - s;
        negative_sei_val = -(300 + index);
        return negative_sei_val;
    }

    // Check if contains more than 2 consecutive identical letters
    int negative_sci_val;
    for (int i=0; i < strlen(s); ++i){
        if (s[i] == s[i+1] && s[i] == s[i+2]){
            negative_sci_val = -(400 + i);
            return negative_sci_val;
        }
    }

    if (not hasSpecialchar){
        return -5;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // Return the element that occurs most frequently and has the longest length
    int password_length=0;
    int max_count=1;
    int position = 0;
    int num_occurence = 0;
    const char *temp = nullptr;
    for (int i=0; i<num_pwds; ++i) {
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0){
                num_occurence += 1;
            }
        }
        if (num_occurence>max_count) {
            position = i;
            max_count = num_occurence;
            temp = arr_pwds[i];
            password_length = strlen(temp);

        }
        else if (num_occurence==max_count){
            if (temp!=arr_pwds[i]){
                if (strlen(arr_pwds[i]) > password_length){
                    temp = arr_pwds[i];
                    position = i;
                    password_length = strlen(temp);
                }
                else{
                    continue;
                }
            }

        }

        num_occurence = 0;
    }

    return position;
}