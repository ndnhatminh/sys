#include "study_in_pink1.h"
#include "main.h"
int compare_string(char* str1,char *str2){
    if(strlen(str1) != strlen(str2)) return false;
    for(int i = 0; i < strlen(str1);i++){
        if(str1[i] != str2[i]) return false;
    }
    return true;
}


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

void renew_Attribute(int & HP1, int & HP2, int & EXP1, int & EXP2, int & M1, int & M2){
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    if (HP2 > 666) HP2 = 666;
    if (HP2 < 0) HP2 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP2 > 600) EXP2 = 600;
    if (EXP2 < 0) EXP2 = 0;
    if (M1 < 0) M1 = 0;
    if (M2 < 0) M2 = 0;
}

int max (int num1, int num2) {
    return (num1 > num2)?num1:num2;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)  return -99;
    if (e1 >= 0 && e1 <= 3) {
        switch (e1) {
            case 0: exp2 = exp2 + 29; break;
            case 1: exp2 = exp2 + 45; break;
            case 2: exp2 = exp2 + 75; break;
            case 3: exp2 = exp2 + 29 + 45 + 75; break;
        }
        int D = e1*3+exp1*7;
        if (D%2 == 0) {exp1 = ceil((float)exp1 + (float)D/200);} else {exp1 = ceil((float)exp1 - (float)D/100);}
    }
    
    float float_exp;
    if ((e1>=4) && (e1<=19)) {
        float_exp = (float)exp2 + (float)e1/4 + 19;
        exp2 = ceil(float_exp);
        exp1 = exp1 - e1;  
        }
    else if ((e1 >= 20) && (e1 <= 49)) {
        float_exp = (float)exp2 + (float)e1/9 + 21; 
        exp2 = ceil(float_exp);
        exp1 = exp1 - e1;  
        }
    else if ((e1 >= 50) && (e1 <= 65)) {
        float_exp = (float)exp2 + (float)e1/16 + 17; 
        exp2 = ceil(float_exp);
        exp1 = exp1 - e1;  
        }
    else if ((e1 >= 66) && (e1 <= 79)) {
        float_exp = (float)exp2 + (float)e1/4 + 19;
        exp2 = ceil(float_exp);
        if (exp2 > 200) {
            float_exp = (float)exp2 + (float)e1/9 + 21;
            exp2 = ceil(float_exp);
            }
        exp1 = exp1 - e1;  
        }
    else if ((e1 >= 80) && (e1 <= 99)) {
        float_exp = (float)exp2 + (float)e1/4 + 19; 
        exp2 = ceil(float_exp);
        float_exp = (float)exp2 + (float)e1/9 + 21; 
        exp2 = ceil(float_exp);
        if (exp2 > 400) {
                float_exp = (float)exp2 + (float)e1/16 + 17;
                exp2 = ceil(float_exp);
                float_exp = (float)exp2 * (float)1.15;
                exp2 = ceil(float_exp);
            }
        exp1 = exp1 - e1;  
        }
    
    int a1,a2,a3,a4;
    renew_Attribute(a1,a2,exp1,exp2,a3,a4);
    return exp1 + exp2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;
    float P1 = 1, P2 = 1, P3 = 1,P;

    int a1,a2,a3,a4;
    int num = pow(round(sqrt(EXP1)),2);

    if ((EXP1 < num)) {P1 = ((EXP1*1.0)/num + 80)/123;}
    else {P1 = 1;}

    int check = E2 % 2;
    if (check == 0) {
        while(true){
            if (HP1 < 200) {
                HP1 = ceil((float)(HP1 * 1.3));
                M1 = M1 - 150;
                renew_Attribute(HP1,a1,EXP1,a2,a3,a4);}
            else {
                HP1 = ceil((float)(HP1*1.1));
                M1 = M1 - 70;
                renew_Attribute(HP1,a1,EXP1,a2,a3,a4);}
            if(M1 >= 0){
                if (EXP1 < 400) {
                    M1 = M1 - 200;
                    EXP1 = ceil((float)(EXP1 * 1.13));
                    renew_Attribute(HP1,a1,EXP1,a2,a3,a4);}
                else if (EXP1 >= 400) {
                    M1 = M1 - 120;
                    EXP1 = ceil((float)(EXP1 * 1.13));
                    renew_Attribute(HP1,a1,EXP1,a2,a3,a4);}
                if (M1 > 0) {
                    if (EXP1 < 300) {
                        M1 = M1 - 100;
                        EXP1 = ceil((float)(EXP1 * 0.9));
                        renew_Attribute(HP1,a1,EXP1,a2,a3,a4);}
                    else if (EXP1 >= 300) {
                        M1 = M1 - 120;
                        EXP1 = ceil((float)(EXP1 * 0.9));
                        renew_Attribute(HP1,a1,EXP1,a2,a3,a4);} 
                }else {
                    M1 = 0;
                    break;
                }
            }else{
                M1 = 0;
                break;
            } 
            if (M1 < 0) M1 = 0; 
            break;
        }
    }
    else {
            int Money = 0, maxM1 = M1;
            while (true) {
                if (HP1 < 200) {
                    HP1 = ceil((float)(HP1 * 1.3)); 
                    M1 = M1 - 150;
                    Money += 150;
                    renew_Attribute(HP1,a1,EXP1,a2,M1,a4);}
                else {
                    HP1 = ceil((float)(HP1 * 1.1)); 
                    M1 = M1 - 70;
                    Money += 70;
                    renew_Attribute(HP1,a1,EXP1,a2,M1,a4);}
                if(Money > maxM1 * 0.5) break;
                if (EXP1 < 400) {
                    M1 = M1 - 200; 
                    Money += 200;
                    EXP1 = ceil((float)(EXP1 * 1.13));
                    renew_Attribute(HP1,a1,EXP1,a2,M1,a4);}
                else {
                    M1 = M1 - 120; 
                    Money += 120;
                    EXP1 = ceil((float)(EXP1 * 1.13));
                    renew_Attribute(HP1,a1,EXP1,a2,M1,a4);}
                if(Money > maxM1 * 0.5) break;
                if (EXP1 < 300) {
                    M1 = M1 - 100;
                    Money += 100;
                    EXP1 = ceil((float)(EXP1 * 0.9));
                    renew_Attribute(HP1,a1,EXP1,a2,M1,a4);}
                else {
                    M1 = M1 - 120;
                    Money += 120;
                    EXP1 = ceil((float)(EXP1 * 0.9));
                    renew_Attribute(HP1,a1,EXP1,a2,M1,a4);}
                if(Money > maxM1 * 0.5) break;
            }
    }

    HP1 = ceil((float)(HP1 * 0.83)); 
    EXP1 = ceil((float)(EXP1 * 1.17)); 
    renew_Attribute(HP1,a1,EXP1,a2,a3,a4);

    num = pow(round(sqrt(EXP1)),2);
    if ((EXP1 < num)) {P2 = ((EXP1*1.0)/num + 80)/123;}
    else {P2 = 1;}

    int array[10] = {32,47,28,79,100,50,22,83,64,11};

    if (E2 < 10) {P3 = (float)array[E2] / (float)100;} 
    else {
        int num1 = (E2 / 10) + (E2 % 10);
        P3 = (float)array[num1 % 10] / 100;
    }
    if (P1 == 1 && P2 == 1 && P3 == 1) {EXP1 = ceil((float)EXP1*0.75);}
    else{
        P = (P1 + P2 + P3)/3.0;

        if (P < 0.5) {
            HP1 = ceil((float)(HP1 * 0.85)); 
            EXP1 = ceil((float)(EXP1 * 1.15));}
        else {
            HP1 = ceil((float)(HP1 * 0.9)); 
            EXP1 = ceil((float)(EXP1 * 1.2));}

    }

    renew_Attribute(HP1,a1,EXP1,a2,a3,a4);
    return HP1+EXP1+M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    int taxi_path[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            taxi_path[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    int a = 0, b = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if (taxi_path[i][j] > (E3 * 2)) a = a + 1;
            if (taxi_path[i][j] < (-E3)) b = b + 1;    
        }
    }

    while (a >= 10) {a = (a / 10) + (a % 10);}
    while (b >= 10) {b = (b / 10) + (b % 10);}

    int max1 = INT16_MIN, max2 = INT16_MIN;
    int tmp_i = a,tmp_j = b;
    while(tmp_i < 9 && tmp_j > 0){
        if(tmp_i < 9){tmp_i += 1;}
        if(tmp_j > 0){tmp_j -= 1;}
    }

    while(tmp_i >= 0 && tmp_j <= 9){
        max1 = max(max1, taxi_path[tmp_i][tmp_j]);
        tmp_i -= 1;
        tmp_j += 1;
    }

    tmp_i = a,tmp_j = b;
    while(tmp_i > 0 && tmp_j > 0){
        if(tmp_i > 0){tmp_i -= 1;}
        if(tmp_j > 0){tmp_j -= 1;}
    }

    while(tmp_i <= 9 && tmp_j <= 9){
        max2 = max(max2, taxi_path[tmp_i][tmp_j]);
        tmp_i += 1;
        tmp_j += 1;
    }

    int Max = max(max1,max2);

    if (abs(taxi_path[a][b]) > abs(Max)) {
        EXP1 = ceil((float)EXP1 * (float)0.88);
        HP1 = ceil((float)HP1 * (float)0.9);
        EXP2 = ceil((float)EXP2 * (float)0.88);
        HP2 = ceil((float)HP2 * (float)0.9);
    }
    else {
        EXP1 = ceil((float)EXP1 * (float)1.12);
        HP1 = ceil((float)HP1 * (float)1.1);
        EXP2 = ceil((float)EXP2 * (float)1.12);
        HP2 = ceil((float)HP2 * (float)1.1);
    }
    
    int a1,a2;
    renew_Attribute(HP1,HP2,EXP1,EXP2,a1,a2);

    return abs(taxi_path[a][b]) > abs(Max)? taxi_path[a][b] : Max;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    //Tìm chuỗi se
    char se[100];
    int i = 0;
    while (email[i] != '@') {
        se[i] = email[i];
        i++;
    }
    se[i] = '\0';

    //Tìm mật khẩu đúng
    if (strlen(s) < 8) return -1; //bé hơn độ dài tối thiểu
    if (strlen(s) > 20) return -2; //lớn hơn độ dài tối đa
    //lặp chuỗi se
    char *position = strstr(s, se);
    if (position != nullptr) {
        int sei = position - s;
        return -(300 + sei);
    }
    //có nhiều hơn 2 kí tự giống nhau liên tiếp
    for (int j = 0; j < (strlen(s) - 1); j++) {
        if (s[j + 1] == s[j] && s[j + 2] == s[j]) return -(400 + j);
    }
    //xét các kí tự đặc biệt
    bool sp_char = false;
    for (int j = 0; j < strlen(s); j++) {
        if (s[j] == '@' || s[j] == '#' || s[j] == '%' || s[j] == '$' || s[j] == '!'){
            sp_char = true;
            break;
        }
    }
    if(!sp_char){
        return -5;
    }else{
        for(int i = 0; i < strlen(s); i++){
            if(s[i] == 34 || (s[i] >= 38 && s[i] <= 47) || (s[i] >= 58 && s[i] <= 63) ||
            (s[i] >= 91 && s[i] <= 96) || (s[i] >= 123 && s[i] <= 126) ) return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // Khởi tạo mảng tần suất của các chuỗi tự thông qua 2 mảng riêng biệt
    char new_arr[num_pwds][20];
    int f[num_pwds];
    for(int i = 0; i < num_pwds;i++){
        f[i] = 0;
    }

    //Đếm tần suất xuất hiện của các chuỗi mật khẩu
    int index = 0;
    for(int i = 0; i < num_pwds; i++){
        bool exist = false;
        for(int j = 0; j < index; j++){
            if(strcmp(arr_pwds[i], new_arr[j]) == 0){
                f[j] ++;
                exist = true;
            }
        }
        if(exist == false){
            strcpy(new_arr[index],arr_pwds[i]);
            f[index++] += 1;
        }
    }

    //Tìm chuỗi mật khẩu có tần suất lớn nhất, nếu bằng nhau thì trả về chuỗi mật khẩu dài nhất
    int max = INT16_MIN;
    int in = INT16_MIN;
    for(int i = 0; i < num_pwds; i++){
        if(f[i] > max) {
            max = f[i];
            in = i;
        }else if(f[i] == max){
            if(strlen(new_arr[in]) < strlen(new_arr[i])){
                in = i;
            }
        }
    }

    //in ra vị trí của chuỗi mật khẩu có tần suất dài nhất
    for(int i = 0; i < num_pwds; i++){
        if(strcmp(arr_pwds[i], new_arr[in]) == 0){
            return i;
        }
    }
    return 1;

}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////