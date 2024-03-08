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
// Task 1 bonus function
void check_exp1(int & exp1){
    if(exp1 > 600)
        exp1 = 600;
    else if(exp1 < 0)
        exp1 = 0;
}

void check_exp2(int & exp2){
    if(exp2 > 600)
        exp2 = 600;
    else if(exp2 < 0)
        exp2 = 0;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    check_exp1(exp1);
    check_exp2(exp2);
    if(e1 <= 3 && e1 >= 0){
        if(e1 == 0)
            exp2 += 29;
        else if(e1 == 1)
            exp2 += 45;
        else if(e1 == 2)
            exp2 += 75;
        else if(e1 == 3)
            exp2 += 149;
        int D = e1 * 3 + exp1 * 7;
        if(D % 2 == 0){
            exp1 += ceil(D / 200.0);
        }else{
            exp1 = ceil(exp1 - D / 100.0); 
        }
        check_exp1(exp1);
        check_exp2(exp2);
    }else if(e1 >= 4 && e1 <= 99){
        if(e1 <= 19){
            exp2 += ceil(e1 / 4.0 + 19);
        }
        else if(e1 <= 49){
            exp2 += ceil(e1 / 9.0 + 21);
        }
        else if(e1 <= 65){
            exp2 += ceil(e1 / 16.0 + 17);
        }
        else if(e1 <= 79){
            exp2 += ceil(e1 / 4.0 + 19);
            if(exp2 > 200)
                exp2 += ceil(e1 / 9.0 + 21);
        }
        else{
            exp2 += ceil(e1 / 4.0 + 19);
            exp2 += ceil(e1 / 9.0 + 21);
            if(exp2 > 400){
                exp2 += ceil(e1 / 16.0 + 17);
                exp2 += ceil(exp2 * 15 /100.0);
            }
        }
        exp1 -= e1;
        check_exp1(exp1);
        check_exp2(exp2);
    }else
        return -99;
    return exp1 + exp2;
}
//Task 2 bonus function
void check_hp(int & hp1){
    if(hp1 > 666)
        hp1 = 666;
    else if(hp1 < 0)
        hp1 = 0;
}

void check_m(int & m){
    if(m > 3000)
        m = 3000;
    else if(m < 0)
        m = 0;
}

int way_2_1(int & HP1, int & EXP1, int & M1){
    if(HP1 < 200){
        HP1 += ceil(HP1 * 30 /100.0);
        M1 -= 150;
    }else{
        HP1 += ceil(HP1 * 10 /100.0);
        M1 -= 70;
    }
    check_hp(HP1);
    if(M1 <= 0)
        return 1;
    if(EXP1 < 400)
        M1 -= 200;
    else
        M1 -= 120;
    EXP1 += ceil(EXP1 * 13 /100.0);
    check_exp1(EXP1);
    if(M1 <= 0)
        return 1;
    if(EXP1 < 300)
        M1 -= 100;
    else
        M1 -= 120;
    EXP1 = ceil(EXP1 - EXP1* 10 /100.0);
    check_exp1(EXP1);
    if(M1 <= 0)
        return 1;
    return 1;
}

int way_2_2(int & HP1, int & EXP1, int & M1, float m1_s){
    if(HP1 < 200){
        HP1 += ceil(HP1 * 30 /100.0);
        M1 -= 150;
    }else{
        HP1 += ceil(HP1 * 10 /100.0);
        M1 -= 70;
    }
    check_hp(HP1);
    if(M1 < m1_s)
        return 1;
    if(EXP1 < 400)
        M1 -= 200;
    else
        M1 -= 120;
    EXP1 += ceil(EXP1 * 13 /100.0);
    check_exp1(EXP1);
    if(M1 < m1_s)
        return 1;
    if(EXP1 < 300)
        M1 -= 100;
    else
        M1 -= 120;
    EXP1 = ceil(EXP1 - EXP1* 10 /100.0);
    check_exp1(EXP1);
    if(M1 < m1_s)
        return 1;
    return 1;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 > 99 || E2 < 0)
        return -99;
    check_exp1(EXP1);
    check_hp(HP1);
    check_m(M1);
    //way 1
    float P1;
    float S1 = round(sqrt(EXP1));
    if(EXP1 >= S1*S1)
        P1 = 1;
    else
        P1 = ((EXP1 / (S1*S1*1.0)) + 80) / 123.0;
    //way 2
    float m1_s = M1 / 2.0;
    if(M1 == 0){
        HP1 = ceil(HP1 - HP1 * 17 / 100.0);
        EXP1 += ceil(HP1 * 17 / 100.0);
    }else if(E2 % 2 == 0){
        way_2_1(HP1, EXP1, M1);
        HP1 = ceil(HP1 - HP1 * 17 / 100.0);
        EXP1 += ceil(EXP1 * 17 / 100.0);
    }else{
        while(M1 >= m1_s){
            way_2_2(HP1, EXP1, M1, m1_s);
        }
        HP1 = ceil(HP1 - HP1 * 17 / 100.0);
        EXP1 += ceil(EXP1 * 17 / 100.0);
    }
    check_m(M1);
    check_exp1(EXP1);
    check_hp(HP1);
    float P2;
    float S2 = round(sqrt(EXP1));
    if(EXP1 >= S2*S2)
        P2 = 1;
    else
        P2 = ((EXP1 / (S2*S2*1.0)) + 80) / 123.0;
    //way 3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    float P3;
    if(E2 / 10 == 0)
        i = E2;
    else
        i = (E2 / 10 + E2 % 10)%10;
    P3 = P[i] / 100.0;
    if(P1 == 1 && P2 == 1 && P3 == 1)
        EXP1 = ceil(EXP1 - EXP1 * 25 / 100.0);
    else{
        float avg = (P1 + P2 + P3) / 3.0;
        if(avg < 0.5){
            HP1 = ceil(HP1 - HP1 * 15 / 100.0);
            EXP1 += ceil(EXP1 * 0.15);
        }else{
            HP1 = ceil(HP1 - HP1 * 10 / 100.0);
            EXP1 += ceil(EXP1 * 20 / 100.0);
        }
    }
    check_exp1(EXP1);
    check_hp(HP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 > 99 || E3 < 0)
        return -99;
    int cot_1 = 0, cot_2 = 0;
    int arr[10][10];
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            arr[i][j] = (E3 * j + i * 2) * (i - j);
            if(arr[i][j] > E3 * 2)
                ++cot_1;
            if(arr[i][j] < -E3)
                ++cot_2;
        }
    }
    while((cot_1 / 10) != 0){
        cot_1 = cot_1 / 10 + cot_1 % 10;
    }
    while((cot_2 / 10) != 0){
        cot_2 = cot_2 / 10 + cot_2 % 10;
    }
    int max_n = arr[cot_1][cot_2];
    int i = cot_1, j = cot_2;
    while(i >= 0 && j <= 9){
        if(max_n < arr[i][j])
            max_n = arr[i][j];
        --i;
        ++j;
    }
    i = cot_1;
    j = cot_2;
    while(i <= 9 && j >= 0){
        if(max_n < arr[i][j])
            max_n = arr[i][j];
        ++i;
        --j;
    }
    i = cot_1;
    j = cot_2;
    while(i >= 0 && j >= 0){
        if(max_n < arr[i][j])
            max_n = arr[i][j];
        --i;
        --j;
    }
    i = cot_1;
    j = cot_2;
    while(i <= 9 && j <= 9){
        if(max_n < arr[i][j])
            max_n = arr[i][j];
        ++j;
    }

    if(abs(arr[cot_1][cot_2]) <= max_n){
        EXP1 += ceil(EXP1 * 12 / 100.0);
        HP1 += ceil(HP1 * 10 / 100.0);
        EXP2 += ceil(EXP2 * 12 / 100.0);
        HP2 += ceil(HP2 * 10 / 100.0);
    }else{
        EXP1 = ceil(EXP1 - EXP1 * 12 / 100.0);
        HP1 = ceil(HP1 - HP1 * 10 / 100.0);
        EXP2 = ceil(EXP2 - EXP2 * 12 / 100.0);
        HP2 = ceil(HP2 - HP2 * 10 / 100.0);
        max_n = arr[cot_1][cot_2];
    }
    check_exp1(EXP1);
    check_exp1(EXP2);
    check_hp(HP1);
    check_hp(HP2);
    return max_n;
}


// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    //char *s_beta = const_cast<char *>(s);
    //char *email_beta = const_cast<char *>(email);
    int s_len = strlen(s);
    int email_len = strlen(email);
    int lenmax = max(s_len, email_len);
    char s_beta[lenmax] = "";
    char email_beta[lenmax] = "";

    for(int i = 0; i < s_len; i++)
        s_beta[i] = s[i];
    for(int i = 0; i < email_len; i++)
        email_beta[i] = email[i];    

    if(s_len < 8)
        return -1;

    if(s_len > 20)
        return -2;

    int s_count = 0;
    char s_char[] = "@#%$!";
    char * po = strchr(email_beta, '@');
    char sa[lenmax]; 

    for(int i = 0; i < email_len; ++i){
        if(email_beta[i] == '@'){
            email_beta[i] = 0;
        }
    }

    char *p = strstr(s_beta, email_beta);

    if(p)
        return -(300 + (p - s_beta));

    for(int i = 2; i < s_len; ++i){
        if(s[i] == s[i-1] && s[i] == s[i-2]){
            return -(400 + i - 2);
        }
    }
    
    for(int i = 0; i < s_len; ++i){
        char *sp = strchr(s_char, s[i]);
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){}
        else if(sp){
            ++s_count;
        }
    }
    if(!s_count)
        return -5;

    for(int i = 0; i < s_len; ++i){
        char *sp = strchr(s_char, s[i]);
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){}
        else if(sp){}
        else
            return i;
    }
   
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    char * pas_arr[30];
    int check_arr[30][3];
    for(int i = 0; i < 30; ++i)
        for(int j = 0; j < 3; ++j)
            check_arr[i][j] = 0;
    int n = 0;
    int flag = 0;
    int count_n = 0, max_len = 0;
    for(int i = 0; i < num_pwds; ++i){
        for(int j = 0; j < n; ++j){
            if(arr_pwds[i] == pas_arr[j]){
                check_arr[j][0] += 1;
                flag = 1;
            }
        }
        if(flag){
            continue;
            flag = 0;
        }
        pas_arr[n] = const_cast<char *>(arr_pwds[i]);
        check_arr[n][1] = strlen(arr_pwds[i]);
        check_arr[n][2] = i;
        check_arr[n][0] += 1;
        ++n;
    }
    int result;
    for(int i = 0; i < n; ++i){
        if(check_arr[i][0] > count_n){
            count_n = check_arr[i][0];
            max_len = check_arr[i][1];
            result = check_arr[i][2];
        }
        else if(check_arr[i][0] == count_n)
            if(check_arr[i][1] > max_len){
                max_len = check_arr[i][1];
                result = check_arr[i][2];
            }
    }
    if(n)
        return result;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////