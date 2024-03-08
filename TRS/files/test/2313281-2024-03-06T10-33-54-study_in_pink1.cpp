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
    //TH1
    if(0 <= e1 && e1 <= 3){
        if(e1 == 0){
            exp2 += 29;
        }else if(e1 == 1){
            exp2 += 45;
        }else if(e1 == 2){
            exp2 += 75;
        }else if(e1 == 3){
            exp2 += 149;
        }if(exp2 > 600){
            exp2 = 600;
        }if(exp2 < 0){
            exp2 = 0;
        }
        int D = e1*3 + exp1*7;
        if(D%2 == 0){
            exp1 = ceil(exp1 + D/200.0);
        }else{
            exp1 = ceil(exp1 - D/100.0);
        }if(exp1 > 600){
            exp1 = 600;
        }if(exp1 < 0){
            exp1 = 0;
        }
    }
    //TH2
    if(4 <= e1 && e1 <= 99){
        if (4 <= e1 && e1 <= 19)
        {
            exp2 += ceil((e1/4.0) + 19);
        }
        else if (20 <= e1 && e1 <= 49)
        {
            exp2 += ceil((e1/9.0) + 21);
        }
        else if (50 <= e1 && e1 <= 65)
        {
            exp2 += ceil((e1/16.0) + 17);
        }
        else if (66 <= e1 && e1 <= 79)
        {
            exp2 += ceil((e1/4.0) + 19);
            if(exp2 > 200)
            {
                exp2 += ceil((e1/9.0) + 21);
            }
        }
        else if (80 <= e1 && e1 <= 99)
        {
            exp2 += ceil((e1/4.0) + 19);
            exp2 += ceil((e1/9.0) + 21);
            if(exp2 > 400)
            {
                exp2 += ceil((e1/16.0) + 17);
                exp2 = ceil(exp2*1.15);
            }
        }
        exp1 = exp1 - e1;
        if(exp2 > 600) exp2 = 600;
        if(exp2 < 0) exp2 = 0;
    }
    return exp1 + exp2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2>=0 and E2<=99) {
    //Con đường 1
    float P1,P2,P3;
    float A=sqrt(EXP1);
    float S=round(A)*round(A);
    if(EXP1>=S) {
        P1=100;
    }
    else {
        P1=((EXP1/S+80)*100)/123.0;
    }
    //Con đường 2
    int M = M1;
    if(E2%2 != 0){
        while(1){
            if(HP1<200) {
                HP1 = ceil(HP1*1.3);
                M1 -= 150;
                if(M1<0) M1 = 0;
            }
            else{
                HP1 = ceil(HP1*1.1);
                M1 -= 70;
                if(M1<0) M1 = 0;
            }
            if(M -M1 > M*0.5) break;
            if(EXP1<400) {
                M1 -= 200;
                if(M1<0) M1 = 0;
                EXP1 = ceil(EXP1*1.13);
            }else {
                M1 -= 120;
                if(M1<0) M1 = 0;
                EXP1 = ceil(EXP1*1.13);
            }
            if(M -M1 > M*0.5) break;
            if(EXP1<300) {
                M1 -= 100;
                if(M1<0) M1 = 0;
                EXP1 = ceil(EXP1*0.9);
            }else{
                M1 -= 120;
                if(M1<0) M1 = 0;
                EXP1 = ceil(EXP1*0.9);
            }
            if(M -M1 > M*0.5) break;
        }
    }
    else{
        if(HP1<200) {
                HP1 = ceil(HP1*1.3);
                M1 -= 150;
                if(M1<0) M1 = 0;
        }
        else{
            HP1 = ceil(HP1*1.1);
            M1 -= 70;
            if(M1<0) M1 = 0;
        }
        if(M>0){
            if(EXP1<400) {
                M1 -= 200;
                if(M1<0) M1 = 0;
                EXP1 = ceil(EXP1*1.13);
            }else {
                M1 -= 120;
                if(M1<0) M1 = 0;
                EXP1 = ceil(EXP1*1.13);
            }
            if(M>0){
                if(EXP1<300) {
                    M1 -= 100;
                    if(M1<0) M1 = 0;
                    EXP1 = ceil(EXP1*0.9);
                }else{
                    M1 -= 120;
                    if(M1<0) M1 = 0;
                    EXP1 = ceil(EXP1*0.9);
                }
            }
        }
    }
    HP1 = ceil(HP1*0.83);
    EXP1 = ceil(EXP1*1.17);
    float a=sqrt(EXP1);
    float s=round(a)*round(a);
    if(EXP1>=s) {
        P2=100;
    }
    else {
        P2=((EXP1/s+80)*100)/123.0;
    }

    //Con đường 3
    int i;
    int P[]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2<10) {
        i=E2;
    }
    else {
        i=((E2/10)+(E2%10))%10;
    }
    P3=P[i];
    float Ps;
    if (P1==100 && P2==100 && P3==100) {
        EXP1=ceil(EXP1*0.75);
    }
    else {
        Ps = (P1+P2+P3)/3;
        if (Ps<50) {
            HP1=ceil(HP1*0.85);
            EXP1=ceil(EXP1*1.15);
        }
        else {
            HP1=ceil(HP1*0.9);
            EXP1=ceil(EXP1*1.2);
        }
    }
    if(EXP1>600) EXP1 = 600;
    if(EXP1<0) EXP1 = 0;
    }
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int taxi_i = E3 * 2;
    int taxi_j = -E3;
    int count_i = 0;
    int count_j = 0;
    int matrix[10][10] = {0};
    double res_hp1 = HP1;
    double res_hp2 = HP2;
    double res_exp1 = EXP1;
    double res_exp2 = EXP2;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (matrix[i][j] > taxi_i) count_i ++;
            if (matrix[i][j] < taxi_j) count_j ++;
        }
    }


    while (count_i >= 10){
        count_i = count_i % 10 + count_i / 10;
    }

    while (count_j >= 10){
        count_j = count_j % 10 + count_j / 10;
    }

    taxi_i = count_i;
    taxi_j = count_j;
    int max_diagonal_val = -2e9;
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if (i - j == taxi_i - taxi_j) {
                max_diagonal_val = max(max_diagonal_val, matrix[i][j]);
            }
            if (i + j == taxi_i + taxi_j){
                max_diagonal_val = max(max_diagonal_val, matrix[i][j]);
            }
        }
    }
    int score_taxi = matrix[taxi_i][taxi_j];
    int score = max_diagonal_val;
    if (score < abs(score_taxi)) {
        res_exp1 -= (ceil)(res_exp1 * 12) / 100.0;
        res_exp2 -= (ceil)(res_exp2 * 12) / 100.0;
        res_hp1 -= (ceil)(res_hp1 * 10) / 100.0;
        res_hp2 -= (ceil)(res_hp2 * 10) / 100.0;
        EXP1 = res_exp1;
        EXP2 = res_exp2;
        HP1 = res_hp1;
        HP2 = res_hp2;
        return score_taxi;
    } else {
        res_exp1 += (ceil)(res_exp1 * 12) / 100.0;
        res_exp2 += (ceil)(res_exp2 * 12) / 100.0;
        res_hp1 += (ceil)(res_hp1* 10) / 100.0;
        res_hp2 += (ceil)(res_hp2 * 10) / 100.0;
        EXP1 = res_exp1;
        EXP2 = res_exp2;
        HP1 = res_hp1;
        HP2 = res_hp2;
        return score;
    }
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int emailLength = strlen(email);
    int sLength = strlen(s);
    char se[100] = "";
    for (int i = 0; i < emailLength; i++)
    {
        if (email[i] != '@')
        {
            se[i] = email[i];
        } else break;
    }
    //dk1
    if (sLength < 8)
        return -1;
    //dk2
    if (sLength > 20)
        return -2;

    //dk 3
    int index = 0, firstIndex;
    int flag = 0;
    for (int i = 0; i < sLength; i++)
    {
        if (s[i] == se[index])
        {
            index++;
            flag = 1;
        }
        else
        {
            index = 0;
            flag = 0;
        }
        if (flag) firstIndex = i - index + 1;
        if (index == strlen(se)) return -(300 + firstIndex);
    }

    //dk4
    for (int i = 0; i < sLength - 3; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2] && s[i] == s[i + 3])
            return -(400 + i);
    }

    //dk5
    bool hasSpecialChar = false;
    for (int i = 0; i < sLength; ++i) {
        if (!isalnum(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!')
            return i;
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            hasSpecialChar = true;
    }
    if (!hasSpecialChar) return -5;

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds){
    // TODO: Complete this function
    int b[30];
    int c[30] = {0};
    for (int i = 0; i < 30; i++) b[i] = 1;
    for (int i = 0; i < num_pwds; i++)
    {
        c[i] = 1;
        for (int j = 1; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0 && c[j] == 0)
            {
                b[i]++;
                c[j] = 1;
            }
        }
    }
    int max = b[0];
    int maxIndex = 0;
    for (int i = 1; i < num_pwds; i++)
    {
        if (max < b[i])
        {
            max = b[i];
            maxIndex = i;
        }
        else if (max == b[i] && strcmp(arr_pwds[maxIndex], arr_pwds[i]) < 0)
        {
            maxIndex = i;
        }

    }
    return maxIndex;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
