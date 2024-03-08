#include "study_in_pink1.h"
#include <string>

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
    // DO NOT MODIFY THIS FUNCTION
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

// Check value
int checkHP(int HP) {
    if (HP > 666) HP = 666;
    else if (HP < 0) HP = 0;
    return HP;
}

int checkEXP(int EXP) {
    if (EXP > 600) EXP = 600;
    else if (EXP < 0) EXP = 0;
    return EXP;
}

int checkM(int M) {
    if (M > 3000) M = 3000;
    else if (M < 0) M = 0;
    return M;
}

float roundedNumber(float num){
    float rounded_number = ceil(num);
    return rounded_number;
}

// Find nearest square number
int nearestSquareNumber(int EXP1) {
    int square_number = 0;
    int square_number_next = 0;
    int i = 1;
    while (i * i <= EXP1) {
        square_number = i * i;
        square_number_next = (i + 1) * (i + 1);
        i++;
    }
    if (square_number_next - EXP1 < EXP1 - square_number) square_number = square_number_next;
    return square_number;
}

int calculate_i(int E2) {
    if (E2 < 10) {
        return E2;
    } else {
        int sum = (E2 / 10) + (E2 % 10);
        return sum % 10;
    }
}

int changeNumber(int number){
    while (number >= 10){
        number = number / 10 + number % 10;
    }
    return number;
}

int findMax(int arr[][10], int index_i, int index_j){
    // left
    int max = arr[index_i][index_j];
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if(i - j == index_i - index_j){
                if (arr[i][j] > max) max = arr[i][j];
            }
        }
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if(i + j == index_i + index_j){
                if (arr[i][j] > max) max = arr[i][j];
            }
        }
    }
    return max;
}

bool isValidChar(char c) {
    return isalnum(c) || c == '@' || c == '#' || c == '%' || c == '$' || c == '!';
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;
    // TH1
    else if (e1 >= 0 && e1 <= 3) {
        // EXP of Watson
        exp2 += ((e1 == 0 || e1 == 3) ? 29 : 0) + ((e1 == 1 || e1 == 3) ? 45 : 0) + ((e1 == 2 || e1 == 3) ? 75 : 0);
        exp2 = checkEXP(exp2);
        // EXP of Sherlock
        int D = e1 * 3  + exp1 * 7;
        float pointD = D;
        float valueEXP1 = exp1;
        valueEXP1 += (D % 2 == 0) ? pointD / 200 : - pointD / 100;
        exp1 = checkEXP(roundedNumber(valueEXP1));
    }
    // TH2
    else if (e1 >= 4  && e1 <= 99) {
        float valueEXP2 = exp2;
        float valueE1 = e1;
        float even1 = roundedNumber(valueE1 / 4 + 19);
        float even2 = roundedNumber(valueE1 / 9 + 21);
        float even3 = roundedNumber(valueE1 / 16 + 17);
        valueEXP2 += ((e1 >= 4 && e1 <= 19 || e1 >= 66 && e1 <= 99 ) ? even1 : 0)
                    + ((e1 >= 20 && e1 <= 49) ? even2 : 0)
                    + ((e1 >= 50 && e1 <= 65) ? even3 : 0);
        exp2 = checkEXP(roundedNumber(valueEXP2));
        valueEXP2 = exp2;
        valueEXP2 += (e1 >= 80 && e1 <= 99) ? even2 : 0;
        exp2 = checkEXP(roundedNumber(valueEXP2));
        valueEXP2 += (((e1 >= 66 && e1 <= 79) && exp2 > 200) ? even2 : 0)
                    + (((e1 >= 80 && e1 <= 99) && exp2 > 400) ? even3 : 0);
        exp2 = checkEXP(roundedNumber(valueEXP2));
        valueEXP2 = exp2;
        valueEXP2 = ((e1 >= 80 && e1 <= 99) && exp2 > 400) ? valueEXP2 * 1.15 : valueEXP2;
        exp2 = checkEXP(roundedNumber(valueEXP2));
        exp1 = checkEXP(exp1 - e1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;
    else {
        int counter = 0;
        // Street 1
        double S = nearestSquareNumber(EXP1);
        double P1 = (EXP1 >= S) ? 1 : (EXP1 / S + 80.0) / 123.0;
        if (P1 == 1) counter++;
        // Street 2
        if (E2 % 2 == 0){
            // Even 1
            float valueHP1 = HP1;
            M1 += ((HP1 < 200 && M1 > 0) ? -150 : 0) + ((HP1 >= 200 && M1 > 0) ? -70 : 0);
            M1 = checkM(M1);
            valueHP1 = (HP1 < 200) ? HP1 * 1.3 : HP1 * 1.1;
            HP1 = checkHP(roundedNumber(valueHP1));
            // Even 2
            int valueM1 = M1;
            M1 += ((EXP1 < 400 && M1 > 0) ? -200 : 0) + ((EXP1 >= 400 && M1 > 0) ? -120 : 0);
            M1 = checkM(M1);
            float valueEXP1 = EXP1;
            valueEXP1 = (valueM1 > 0) ? EXP1 * 1.13 : valueEXP1;
            EXP1 = checkEXP(roundedNumber(valueEXP1));
            // Even 3
            valueM1 = M1;
            M1 += ((EXP1 < 300 && M1 > 0) ? -100 : 0) + ((EXP1 >= 300 && M1 > 0) ? -120 : 0);
            M1 = checkM(M1);
            valueEXP1 = EXP1;
            valueEXP1 = (valueM1 > 0) ? EXP1 * 0.9 : valueEXP1;
            EXP1 = checkEXP(roundedNumber(valueEXP1));
            //
            valueHP1 = HP1 * 0.83;
            HP1 = checkHP(roundedNumber(valueHP1));
            valueEXP1 = EXP1 * 1.17;
            EXP1 = checkEXP(roundedNumber(valueEXP1));
        } else {
            float M50 = M1 * 0.5;
            int M_pay = 0;
            while (1) {
                // even 1
                if (M_pay <= M50 && M1 > 0) {
                    M1 += (HP1 < 200) ? -150 : -70;
                    M1 = checkM(M1);
                    M_pay += (HP1 < 200) ? 150 : 70;
                    float valueHP1 = HP1;
                    valueHP1 = (HP1 < 200) ? HP1 * 1.3 : HP1 * 1.1;
                    HP1 = checkHP(roundedNumber(valueHP1));
                } else break;
                // even 2
                if (M_pay <= M50 && M1 > 0){
                    M1 += (EXP1 < 400) ? -200 : -120;
                    M1 = checkM(M1);
                    M_pay += (EXP1 < 400) ? 200 : 120;
                    float valueEXP1 = EXP1;
                    valueEXP1 = EXP1 * 1.13;
                    EXP1 = checkEXP(roundedNumber(valueEXP1));
                } else break;
                // even 3
                if (M_pay <= M50 && M1 > 0) {
                    M1 += (EXP1 < 300) ? -100 : -120;
                    M1 = checkM(M1);
                    M_pay += (EXP1 < 300) ? 100 : 120;
                    float valueEXP1 = EXP1;
                    valueEXP1 = EXP1 * 0.9;
                    EXP1 = checkEXP(roundedNumber(valueEXP1));
                } else break;
                if (M_pay > M50 || M1 == 0) break;
            }
            float valueHP1 = HP1;
            valueHP1 = HP1 * 0.83;
            HP1 = checkHP(roundedNumber(valueHP1));
            float valueEXP1 = EXP1;
            valueEXP1 = EXP1 * 1.17;
            EXP1 = checkEXP(roundedNumber(valueEXP1));
        }
        S = nearestSquareNumber(EXP1);
        double P2 = (EXP1 >= S) ? 1 : (EXP1 / S + 80) / 123;
        if (P2 == 1) counter++;
        // Street 3
        int P[] = {32,47,28,79,100,50,22,83,64,11};
        int i = calculate_i(E2);
        double P3 = P[i] * 0.01;
        if (P3 == 1) counter++;
        if (counter == 3) {
            float valueEXP1 = EXP1;
            valueEXP1 = EXP1 * 0.75;
            EXP1 = checkEXP(roundedNumber(valueEXP1));
        } else {
            float P_tb = (P1 + P2 + P3) / 3;
            float valueEXP1 = (P_tb < 0.5) ? EXP1 * 1.15 : EXP1 * 1.2;
            EXP1 = checkEXP(roundedNumber(valueEXP1));
            float valueHP1 = (P_tb < 0.5) ? HP1 * 0.85 : HP1 * 0.9;
            HP1 = checkHP(roundedNumber(valueHP1));
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    else {
        int arrayTaxi[10][10];
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                arrayTaxi[i][j] = 0;
            }
        }
        int counter_i = 0;
        int counter_j = 0;
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                arrayTaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                if (arrayTaxi[i][j] > (E3 * 2)) counter_i++;
                if (arrayTaxi[i][j] < -E3) counter_j++;
            }
        }
        int index_i = changeNumber(counter_i);
        int index_j = changeNumber(counter_j);

        int arrayMax[10][10];
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                arrayMax[i][j] = abs(findMax(arrayTaxi, i, j));
            }
        }
        if (arrayMax[index_i][index_j] >= abs(arrayTaxi[index_i][index_j])) {
            float valueEXP1 = EXP1 * 1.12;
            EXP1 = checkEXP(roundedNumber(valueEXP1));
            float valueEXP2 = EXP2 * 1.12;
            EXP2 = checkEXP(roundedNumber(valueEXP2));
            float valueHP1 = HP1 * 1.1;
            HP1 = checkHP(roundedNumber(valueHP1));
            float valueHP2 = HP2 * 1.1;
            HP2 = checkHP(roundedNumber(valueHP2));
            return arrayMax[index_i][index_j];
        } else {
            float valueEXP1 = EXP1 * 0.88;
            EXP1 = checkEXP(roundedNumber(valueEXP1));
            float valueEXP2 = EXP2 * 0.88;
            EXP2 = checkEXP(roundedNumber(valueEXP2));
            float valueHP1 = HP1 * 0.9;
            HP1 = checkHP(roundedNumber(valueHP1));
            float valueHP2 = HP2 * 0.9;
            HP2 = checkHP(roundedNumber(valueHP2));
            return arrayTaxi[index_i][index_j];
        }
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se;
    int index = 0;
    while (1){
        if (email[index] == '@') break;
        se += email[index];
        index++;
    }
    size_t size_se = strlen(s);
    if (size_se < 8) return -1;
    if (size_se > 20) return -2;
    string s_str(s);
    string se_str(se);
    size_t index_se = s_str.find(se_str);
    if (index_se != -1) return -(300 + index_se);
    for (int i = 0; i < s_str.size() - 2; i++) {
        if (s_str[i] == s_str[i + 1] && s_str[i] == s_str[i + 2]) return -(400 + i);
    }
    int counter = 0;
    for (int i = 0; i < s_str.size(); i++) {
        if (s_str[i] == '@') break;
        else if (s_str[i] == '#') break;
        else if (s_str[i] == '%') break;
        else if (s_str[i] == '$') break;
        else if (s_str[i] == '!') break;
        else counter++;
    }
    if (counter == s_str.size()) return -5;
    for (int i = 0; i < s_str.size(); i++){
        if (isValidChar(s_str[i]) == 0) return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    const int MAX_PASSWORDS = 30;
    string occurrences[MAX_PASSWORDS];
    int counts[MAX_PASSWORDS] = {0};
    int arr_index[MAX_PASSWORDS];
    int counter = 0;
    for (int i = 0; i < num_pwds; i++) {
        bool found = false;
        for (int j = 0; j < counter; j++) {
            if (occurrences[j] == arr_pwds[i]) {
                counts[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            occurrences[counter] = arr_pwds[i];
            counts[counter] = 1;
            arr_index[counter] = i;
            counter++;
        }
    }

    int max_count = 0;
    int max_length = 0;
    int correct_index = -1;
    for (int i = 0; i < counter; i++) {
        if (counts[i] >= max_count) {
            if (counts[i] > max_count || occurrences[i].size() > max_length) {
                max_count = counts[i];
                max_length = occurrences[i].size();
                correct_index = arr_index[i];
            }
        }
    }
    return correct_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////