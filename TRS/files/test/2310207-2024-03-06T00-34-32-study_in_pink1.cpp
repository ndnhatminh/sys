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
int check_hp(int a){
    if(a<0) return 0;
    if(a>666) return 666;
    return a;
}
int check_exp(int a){
    if(a<0) return 0;
    if(a>600) return 600;
    return a;
}
int check_money(int a){
    if(a<0) return 0;
    if(a>3000) return 3000;
    return a;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    // Check input
    if(e1<0 || e1>99) return -99;
    exp1=check_exp(exp1);
    exp2=check_exp(exp2);
    // ==========================
    if(e1>=0 && e1<=3){
        if(e1==0) exp2=exp2+29;
        else if(e1==1) exp2=exp2+45;
        else if(e1==2) exp2=exp2+75;
        else  exp2=exp2+29+45+75;
        int D;
        D=e1*3+exp1*7;
        if(D%2==0) exp1=ceil(float(exp1+D/200.0));
        else exp1=ceil(float(exp1-D/100.0));
    }
    else{
    if(e1>=4 && e1<=19){
        exp2=ceil(float(exp2+(e1/4.0+19))); //in1
        exp1=exp1-e1;
    }
    else if(e1>=20 && e1<=49){
        exp2=ceil(float(exp2+(e1/9.0+21))); //in2
        exp1=exp1-e1;
    }
    else if(e1>=50 && e1<=65){
        exp2=ceil(float(exp2+(e1/16.0+17))); //in3
        exp1=exp1-e1;
    }
    else if(e1>=66 && e1<=79){ //in4
        exp2=ceil(float(exp2+(e1/4.0+19)));
        if(exp2>200) {
            exp2=ceil(float(exp2+(e1/9.0+21)));
        }
        exp1=exp1-e1;
    }
    else{
        exp2=ceil(float(exp2+(e1/4.0+19)));
        exp2=ceil(float(exp2+(e1/9.0+21)));
        if(exp2>400){
            exp2=ceil(float(exp2+(e1/16.0+17)));
            exp2=ceil(float(exp2*1.15));
        }
        exp1=exp1-e1;
    }
}
    exp1=check_exp(exp1);
    exp2=check_exp(exp2);
    return exp1 + exp2;
}

// Task 2
// 
bool isPerfectSquare(int n) {
    int sqrt_n = sqrt(n);
    return sqrt_n * sqrt_n == n;
}

// 
int nearestPerfectSquare(int exp1) {
    if (exp1 == 0) return 0;
    int lower = exp1 - 1;
    int upper = exp1 + 1;

    while (true) {
        if (isPerfectSquare(lower))
            return lower;
        else if (isPerfectSquare(upper))
            return upper;
        else {
            lower--;
            upper++;
        }
    }
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // Check input
    if(E2<0 || E2>99) return -99;
    HP1=check_hp(HP1);
    EXP1=check_exp(EXP1);
    M1=check_money(M1);
    //==========================
    // Way 1
    int S1; 
    float P1;
    S1=nearestPerfectSquare(EXP1);
    if(EXP1>=S1) P1=100;
    else {P1=(float(EXP1)/S1 + 80)/123.0;P1*=100;}
    // Way 2
    int S2;
    float P2;
    const float m1=M1*0.5; // số tiền 50%
    float money_pay=0;
    if(E2%2!=0){
        if(M1==0){
            HP1=ceil(float(HP1*0.83));HP1=check_hp(HP1);
            EXP1=ceil(float(EXP1*1.17));EXP1=check_exp(EXP1);
        }else{
        while(money_pay<=m1){
            if(HP1<200){
                HP1=ceil(float(HP1*1.3));
                HP1=check_hp(HP1);
                M1=M1-150;
                M1=check_money(M1);
                money_pay+=150;
                if(money_pay>m1) break;
            }else{
                HP1=ceil(float(HP1*1.1));
                HP1=check_hp(HP1);
                M1=M1-70;
                M1=check_money(M1);
                money_pay+=70;
                if(money_pay>m1) break;
            }
            if(EXP1<400){
                EXP1=ceil(float(EXP1*1.13));
                EXP1=check_exp(EXP1);
                M1=M1-200;M1=check_money(M1);
                money_pay+=200;if(money_pay>m1) break;
            }else{
                EXP1=ceil(float(EXP1*1.13));
                EXP1=check_exp(EXP1);
                M1=M1-120;M1=check_money(M1);
                money_pay+=120;if(money_pay>m1) break;
            }
            if(EXP1<300){
                EXP1=ceil(float(EXP1*0.9));EXP1=check_exp(EXP1);
                M1=M1-100;M1=check_money(M1);
                money_pay+=100;if(money_pay>m1) break;
            }else{
                EXP1=ceil(float(EXP1*0.9));EXP1=check_exp(EXP1);
                M1=M1-120;M1=check_money(M1);
                money_pay+=120;if(money_pay>m1) break;
            }
        }
        HP1=ceil(float(HP1*0.83));HP1=check_hp(HP1);
        EXP1=ceil(float(EXP1*1.17));EXP1=check_exp(EXP1);}
    }else{
        if(M1==0){
        HP1=ceil(float(HP1*0.83));HP1=check_hp(HP1);
        EXP1=ceil(float(EXP1*1.17));EXP1=check_exp(EXP1);   
        }else{
        while(M1!=0){
            if(HP1<200){
                HP1=ceil(float(HP1*1.3));
                HP1=check_hp(HP1);
                M1=M1-150;
                M1=check_money(M1);
                if(M1==0) break;
            }else{
                HP1=ceil(float(HP1*1.1));
                HP1=check_hp(HP1);
                M1=M1-70;
                M1=check_money(M1);
                if(M1==0) break;
            }
            if(EXP1<400){
                EXP1=ceil(float(EXP1*1.13));
                EXP1=check_exp(EXP1);
                M1=M1-200;M1=check_money(M1);
                if(M1==0) break;
            }else{
                EXP1=ceil(float(EXP1*1.13));
                EXP1=check_exp(EXP1);
                M1=M1-120;M1=check_money(M1);
                if(M1==0) break;
            }
            if(EXP1<300){
                EXP1=ceil(float(EXP1*0.9));EXP1=check_exp(EXP1);
                M1=M1-100;M1=check_money(M1);
                if(M1==0) break;
            }else{
                EXP1=ceil(float(EXP1*0.9));EXP1=check_exp(EXP1);
                M1=M1-120;M1=check_money(M1);
                if(M1==0) break;
            }
            break;
        }
        HP1=ceil(float(HP1*0.83));HP1=check_hp(HP1);
        EXP1=ceil(float(EXP1*1.17));EXP1=check_exp(EXP1);}
    }
    S2=nearestPerfectSquare(EXP1);
    if(EXP1>=S2) P2=100;
    else {P2=(float(EXP1)/S2 + 80)/123.0;P2*=100;}
    // Way 3
    float P_first[10]={32,47,28,79,100,50,22,83,64,11};
    float P3;
    float P_ave;
    int c,d,e;
    if(E2/10==0) P3=P_first[E2];
    else {
        c=E2/10;
        d=E2%10;
        if(c+d>=10) {e=(c+d)%10;P3=P_first[e];}
        else P3=P_first[c+d];
    }
    //
    if(P1==100 && P2==100 && P3==100) {EXP1=ceil(float(EXP1*0.75));EXP1=check_exp(EXP1);}
    else{
        P_ave=(P1+P2+P3)/3;
        if(P_ave<50){
            HP1=ceil(float(HP1*0.85));HP1=check_hp(HP1);
            EXP1=ceil(float(EXP1*1.15));EXP1=check_exp(EXP1);
        }else{
            HP1=ceil(float(HP1*0.9));HP1=check_hp(HP1);
            EXP1=ceil(float(EXP1*1.2));EXP1=check_exp(EXP1);
        }
    }
    M1=check_money(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    // Check input
    if(E3<0 || E3>99) return -99;
    HP1=check_hp(HP1);
    EXP1=check_exp(EXP1);
    HP2=check_hp(HP2);
    EXP2=check_exp(EXP2);
    //==========================
    int met_i,met_j;
    int greater_e3=0,less_e3=0;
    int matrix_taxi[10][10];
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            matrix_taxi[i][j]=((E3*j)+(i*2))*(i-j);
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(matrix_taxi[i][j]>(E3*2)){
                greater_e3++;
            }
            if(matrix_taxi[i][j]<(-E3)){
                less_e3++;
            }
        }
    }
    int first_part,second_part,sum_part,first_part_2,second_part_2,sum_part_2;
    if(greater_e3>=10){
        first_part=greater_e3/10;
        second_part=greater_e3%10;
        sum_part=first_part+second_part;
        if(sum_part>=10){
            first_part_2=sum_part/10;
            second_part_2=sum_part%10;
            sum_part_2=first_part_2+second_part_2;
            met_i=sum_part_2;
        }else{
            met_i=sum_part;
        }
    }else{
        met_i=greater_e3;
    }
    //less_e3
    if(less_e3>=10){
        first_part=less_e3/10;
        second_part=less_e3%10;
        sum_part=first_part+second_part;
        if(sum_part>=10){
            first_part_2=sum_part/10;
            second_part_2=sum_part%10;
            sum_part_2=first_part_2+second_part_2;
            met_j=sum_part_2;
        }else{
            met_j=sum_part;
        }
    }else{
        met_j=less_e3;
    }
    int taxi_score;
    taxi_score=matrix_taxi[met_i][met_j];
    int max_score_Sherlock;
    max_score_Sherlock=matrix_taxi[met_i][met_j];
    for(int i=met_i;i<10;i++){
        for(int j=met_j;j>=0;j--){
            if(matrix_taxi[i][j]>max_score_Sherlock){
                max_score_Sherlock=matrix_taxi[i][j];
            }
            ++i;
            if(i>=10) break;
        }
        break;
    }
    for(int i=met_i;i>=0;i--){
        for(int j=met_j;j<10;j++){
            if(matrix_taxi[i][j]>max_score_Sherlock){
                max_score_Sherlock=matrix_taxi[i][j];
            }
            --i;
            if(i<0) break;
        }
        break;
    }
    for(int i=met_i;i>=0;i--){
        for(int j=met_j;j>=0;j--){
            if(matrix_taxi[i][j]>max_score_Sherlock){
                max_score_Sherlock=matrix_taxi[i][j];  
            }
            --i;
            if(i<0) break;
        }
        break;
    }
    for(int i=met_i;i<10;i++){
        for(int j=met_j;j<10;j++){
            if(matrix_taxi[i][j]>max_score_Sherlock){
                max_score_Sherlock=matrix_taxi[i][j];    
            }
            ++i;
            if(i>=10) break;
        }
        break;
    }
    if(abs(taxi_score)>max_score_Sherlock){
        EXP1=ceil(float(EXP1*0.88));EXP1=check_exp(EXP1);
        HP1=ceil(float(HP1*0.9));HP1=check_hp(HP1);
        EXP2=ceil(float(EXP2*0.88));EXP2=check_exp(EXP2);
        HP2=ceil(float(HP2*0.9));HP2=check_hp(HP2);
        return taxi_score;
    }else{
        EXP1=ceil(float(EXP1*1.12));EXP1=check_exp(EXP1);
        HP1=ceil(float(HP1*1.1));HP1=check_hp(HP1);
        EXP2=ceil(float(EXP2*1.12));EXP2=check_exp(EXP2);
        HP2=ceil(float(HP2*1.1));HP2=check_hp(HP2);
        return max_score_Sherlock;
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    const char *atSymbol = strchr(email, '@');
    //
    char se[100];
    strncpy(se, email, atSymbol - email);
    se[atSymbol - email] = '\0';
    //
    int password_Length = strlen(s);
    if (password_Length < 8) return -1;
    if (password_Length > 20) return -2;
    //
    const char *se_Position = strstr(s, se);
    if (se_Position != nullptr) return -(300 + (se_Position - s));
    //
    for (int i = 0; i < password_Length - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) return -(400 + i);
    }
    //
    bool has_Special_Char = false;
    for (const char *ptr = s; *ptr != '\0'; ptr++) {
        if (*ptr == '@' || *ptr == '#' || *ptr == '%' || *ptr == '$' || *ptr == '!') {
            has_Special_Char = true;
            break;
        }
    }
    if (has_Special_Char==false) return -5;
    //
    for (int i = 0; i < password_Length; i++) {
        if (!isalnum(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') {
            return i; 
        }
    }
    //
    return -10;
    //
    return -99;
}

// Task 5
//
bool exists_In_Array(const char *arr[], int size, const char *target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], target) == 0) {
            return true;
        }
    }
    return false;
}
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxCount = 0; 
    int maxLength = 0; 
    const char *most_Frequent_Password = nullptr; 

    for (int i = 0; i < num_pwds; i++) {
        const char *password = arr_pwds[i];
        int count = 1; 
        int length = strlen(password); 

        if (exists_In_Array(arr_pwds, i, password)) {
            continue;
        }

        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[j], password) == 0) {
                ++count; 
            }
        }

        if (count > maxCount || (count == maxCount && length > maxLength)) {
            maxCount = count;
            maxLength = length;
            most_Frequent_Password = password;
        }
    }

    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(arr_pwds[i], most_Frequent_Password) == 0) {
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////