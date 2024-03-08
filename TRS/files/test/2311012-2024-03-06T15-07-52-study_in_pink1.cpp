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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;
    int D;
    switch (e1){
        case 3:
            exp2 += 74;
        case 2:
            exp2 += 30;
        case 1:
            exp2 += 16;
        case 0:
            exp2 += 29;
            if (exp2 > 600) exp2 = 600;
            D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0){
                exp1 += ceil(D/200.0);
                if (exp1 > 600) exp1 = 600;
            }
            else {
                exp1 -= D/100;
                if (exp1 < 0) exp1 = 0;
            }
            break;
        default:
            if (e1 <= 19){
                exp2 += (ceil(e1/4.0) + 19);
                if (exp2 > 600) exp2 = 600;
            }
            else if (e1 <= 49){
                exp2 += (ceil(e1/9.0) + 21);
                if (exp2 > 600) exp2 = 600;
            }
            else if (e1 <= 65){
                exp2 += (ceil(e1/16.0) + 17);
                if (exp2 > 600) exp2 = 600;
            }
            else if (e1 <= 79){
                exp2 += (ceil(e1/4.0) + 19);
                if (exp2 > 200) exp2 += (ceil(e1/9.0) + 21);
                if (exp2 > 600) exp2 = 600;
            }
            else {
                exp2 += (ceil(e1/4.0) + 19);
                exp2 += (ceil(e1/9.0) + 21);
                if (exp2 > 400) {
                    exp2 += (ceil(e1/16.0) + 17);
                    exp2 += ceil(0.15*exp2);
                    if (exp2 > 600) exp2 = 600;
                }
            }
            exp1 -= e1;
            if (exp1 < 0) exp1 = 0;
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;
    // Road 1
    int S = sqrt(EXP1);
    double P1;
    if ((EXP1 - S*S) > ((S+1)*(S+1) - EXP1)){
        S++;
        S *= S;
        P1 = ((double)EXP1/S + 80.0)/123.0;
    }
    else P1 = 1;

    // Road 2
    if (E2 % 2 == 0){
        do {
            //Event 1
            if (HP1 < 200) {
                HP1 += ceil(0.3 * HP1);
                M1 -= 150;
            }
            else {
                HP1 += ceil(0.1 * HP1);
                M1 -= 70;
            }
            if (HP1 > 666) HP1 = 666;
            if (M1 < 0){
                M1 = 0;
                break;
            }

            //Event 2
            if (EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            EXP1 += ceil(0.13 * EXP1);
            if(EXP1 > 600) EXP1 = 600;
            if (M1 < 0){
                M1 = 0;
                break;
            }

            //Event 3
            if (EXP1 < 300) M1 -= 100;
            else M1 -= 120;
            EXP1 -= (int)(0.1 * EXP1);
            if (EXP1 < 0) EXP1 = 0;
            if (M1 < 0){
                M1 = 0;
                break;
            }
        } while (false);
        HP1 -= (int)(0.17 * HP1);
        EXP1 += ceil(0.17* EXP1);
        if (HP1 < 0) HP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
    }
    else {
        double temp = M1*0.5;
        while (true){
            //Event 1
            if (HP1 < 200) {
                HP1 += ceil(0.3 * HP1);
                M1 -= 150;
            }
            else {
                HP1 += ceil(0.1 * HP1);
                M1 -= 70;
            }
            if (M1 < 0) M1 = 0;
            if (M1 < temp) break;
            if (HP1 > 666) HP1 = 666;

            //Event 2
            if (EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            EXP1 += ceil(0.13 * EXP1);
            if (M1 < 0) M1 = 0;
            if (M1 < temp) break;
            if(EXP1 > 600) EXP1 = 600;

            //Event 3
            if (EXP1 < 300) M1 -= 100;
            else M1 -= 120;
            EXP1 -= (int)(0.1 * EXP1);
            if (M1 < 0) M1 = 0;
            if (M1 < temp) break;
            if (EXP1 < 0) EXP1 = 0;
        }
        HP1 -= (int)(0.17 * HP1);
        EXP1 += ceil(0.17* EXP1);
        if (HP1 < 0) HP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
    }
    S = sqrt(EXP1);
    double P2;
    if ((EXP1 - S*S) > ((S+1)*(S+1) - EXP1)){
        S++;
        S *= S;
        P2 = ((double)EXP1/S + 80.0)/123.0;
    }
    else P2 = 1;

    //Road 3
    double P[] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    double P3;
    if (E2 < 10) P3 = P[E2];
    else P3 = P[(E2/10 + E2%10)%10];

    //Calculation
    if (P1 == 1 && P2 == 1 && P3 == 1) EXP1 -= (int)(0.25*EXP1);
    else {
        P1 = (P1 + P2 + P3)/3;
        if (P1 < 0.5){
            HP1 -= (int)(0.15*HP1);
            EXP1 += ceil(0.15*EXP1);
        }
        else {
            HP1 -= (int)(0.1*HP1);
            EXP1 += ceil(0.2*EXP1);
        }
    }
    if (EXP1 < 0) EXP1 = 0;
    if (HP1 < 0) HP1 = 0;
    if (EXP1 > 600) EXP1 = 600;

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    //Initialize matrix
    int arr[10][10], count_Yin = 0, count_Yang = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++) {
            arr[i][j] = ((E3*j) + (i*2)) * (i-j);
            if (arr[i][j] > (E3*2)) count_Yang++;
            if (arr[i][j] < -E3) count_Yin++;
        }
    }
    //Calculation
    while (count_Yin > 9) count_Yin = count_Yin/10 + count_Yin%10;
    while (count_Yang > 9) count_Yang = count_Yang/10 + count_Yang%10;
    
    int i = count_Yang, j = count_Yin, max = arr[i][j];
    while (i < 10 && j < 10){
        max = (arr[i][j] > max)? arr[i][j] : max;
        i++;
        j++;
    }
    i = count_Yang, j = count_Yin;
    while (i >= 0 && j >= 0){
        max = (arr[i][j] > max)? arr[i][j] : max;
        i--;
        j--;
    }
    i = count_Yang, j = count_Yin;
    while (i >= 0 && j < 10){
        max = (arr[i][j] > max)? arr[i][j] : max;
        i--;
        j++;
    }
    i = count_Yang, j = count_Yin;
    while (i < 10 && j >= 0){
        max = (arr[i][j] > max)? arr[i][j] : max;
        i++;
        j--;
    }
    max = abs(max);
    if (abs(arr[count_Yang][count_Yin]) > max) {
        EXP1 -= (int)(0.12*EXP1);
        EXP2 -= (int)(0.12*EXP2);
        HP1 -= (int)(0.1*HP1);
        HP2 -= (int)(0.1*HP2);
        return arr[count_Yang][count_Yin];
        if (EXP1 <0) EXP1 = 0;
        if (EXP2 < 0) EXP2 = 0;
        if (HP1 < 0) HP1 = 0;
        if (HP2 < 0) HP2 = 0;
    }
    else {
        EXP1 += ceil(0.12*EXP1);
        EXP2 += ceil(0.12*EXP2);
        HP1 += ceil(0.1*HP1);
        HP2 += ceil(0.1*HP2);
        if (EXP1 > 600) EXP1 = 600;
        if (EXP2 > 600) EXP2 = 600;
        if (HP1 > 666) HP1 = 666;
        if (HP2 > 666) HP2 = 666;
        return max;
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string S = s, Email = email;
    if (S.size() < 8) return -1;
    if (S.size() > 20) return -2;
    int count_1 = 1, count_2 = 0, pos_1 = 0, flag = 1;
    if ((S[0] < '0' || S[0] > '9') && (S[0] < 'A' || S[0] > 'Z') && (S[0] < 'a' || S[0] > 'z') && (S[0] != '@' && S[0] != '#' && S[0] != '%' && S[0] != '$' && S[0] != '!')) return 0;
    if (S[0] == '@' || S[0] == '#' || S[0] == '%' || S[0] == '$' || S[0] == '!') count_2++;
    for (int i = 1; i < S.size(); i++){
        if ((S[i] < '0' || S[i] > '9') && (S[i] < 'A' || S[i] > 'Z') && (S[i] < 'a' || S[i] > 'z') && (S[i] != '@' && S[i] != '#' && S[i] != '%' && S[i] != '$' && S[i] != '!')) cout << S[i-1] << '\n';
        if (S[i] == '@' || S[i] == '#' || S[i] == '%' || S[i] == '$' || S[i] == '!') count_2++;
        if (flag) {
            if (S[i] == S[i - 1]) {
            count_1++;
            if (count_1 >= 2) flag = 0;
            }
            else {
                count_1 = 1;
                pos_1 = i;
            }
        }
    }
    if (count_2 < 1) return -5;
    string se = Email.substr(0, Email.find('@'));
    if (S.find(se) != string::npos) {
        if (S.find(se) < pos_1) return -(300 + S.find(se));
        else return -(400 + pos_1);
    }
    if (count_1 >= 2) return -(400 + pos_1);
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string pwd[30];
    int count[30];
    int pos[30];
    int temp, max = 1, length_max = 0, size = 0;
    for (int i = 0; i < num_pwds; i++){
        temp = -1;
        for (int j = 0; j < size; j++) {
            if (arr_pwds[i] == pwd[j]) {
                temp = j;
                break;
            }
        }
        if (temp == -1) {
            pwd[size] = arr_pwds[i];
            pos[size] = i;
            count[size] = 1;
            size++;
        }
        else {
            count[temp]++;
            max = (count[temp] > max)? count[temp] : max;
        }
    }
    for (int i = 0; i < size; i++) {
        if (count[i] == max) {
            if (length_max < pwd[i].size()) {
                temp = pos[i];
                length_max = pwd[i].size();
            }
        }
    }
    return temp;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////