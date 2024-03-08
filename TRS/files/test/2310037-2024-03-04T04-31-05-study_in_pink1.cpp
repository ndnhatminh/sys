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

void HP(int & HP1, int & HP2){
    if(HP1 > 666) {HP1 = 666;}
    if(HP1 < 0) {HP1 = 0;}
    if(HP2 > 666) {HP2 = 666;}
    if(HP2 < 0) {HP2 = 0;}
}
void M(int & M1, int & M2){
    if(M1 > 3000) {M1 = 3000;}
    if(M1 < 0) {M1 = 0;}
    if(M2 > 3000) {M2 = 3000;}
    if(M2 < 0) {M2 = 0;}
}
void EXP(int & EXP1, int & EXP2){
    if(EXP1 > 600) {EXP1 = 600;}
    if(EXP1 < 0) {EXP1 = 0;}
    if(EXP2 > 600) {EXP2 = 600;}
    if(EXP2 < 0) {EXP2 = 0;}
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    EXP(exp1, exp2);
    if(e1 < 0 || e1 > 99) {return -99;}
    //TH1
    else if(e1 >=0 && e1 <=3){
        if(e1 == 0) {exp2 += 29;}
        else if(e1 == 1) {exp2 += 45;}
        else if(e1 == 2) {exp2 += 75;}
        else {exp2 += 29 + 45 + 75;}
        EXP(exp1, exp2);
        int D = e1*3 + exp1*7;
        if(D%2 == 0) {
            exp1 += (float)D/200.0 + 0.999;
            EXP(exp1, exp2);          
        }
        else {
            exp1 -= floor((float)(D/100.0));
            EXP(exp1, exp2);
        }
    } //TH2
    else {
        if(e1>=4 && e1 <=19) {
            exp2 += (float)e1/4.0 + 0.999 + 19;
            EXP(exp1, exp2);
        } else if(e1>=20 && e1<=49) {
            exp2 += (float)e1/9.0 +0.999 + 21;
            EXP(exp1, exp2);
        } else if(e1>=50 && e1<=65) {
            exp2 += (float)e1/16.0 + 0.999 + 17;
            EXP(exp1, exp2);
        } else if(e1>=66 && e1<=79) {
            exp2 += (float)e1/4.0 + 0.999 + 19;
            EXP(exp1, exp2);
            if(exp2 > 200) {
                exp2 += (float)e1/9.0 + 0.999 + 21;
                EXP(exp1, exp2);
            }
        } else {
            exp2 += (float)e1/4.0 + 0.999 + 19;
            EXP(exp1, exp2);
            exp2 += (float)e1/9.0 + 0.999 + 21;
            EXP(exp1, exp2);
            if(exp2 > 400) {
                exp2 += (float)e1/16.0 + 0.999 + 17;
                EXP (exp1, exp2);
                exp2 += (float)exp2*0.15 + 0.999; 
                EXP(exp1, exp2);     
            }
        } exp1 -= e1;
        EXP(exp1, exp2);
    }
    return exp1 + exp2;
}
int find_sqr(int num){
    int a, b;
    a = sqrt(num);
    b = a + 1;
    if(abs(a*a-num)<abs(b*b-num)) {return a*a;}
    return b*b;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    int m1 = 0;
    float m2 = (float)M1*0.5;
    int a = 0;
    float P, P1, P2, P3;
    HP (HP1, a);
    M (M1, a);
    EXP (EXP1, a);
    if(E2<0 || E2>99) {return -99;}
    //road 1
    if (find_sqr(EXP1) <= EXP1) P1 =1;
    else P1 = ((1.0*EXP1/find_sqr(EXP1))+80)/123;
    //road 2
    if(E2%2 != 0 )
    {
        while (1)
        {   
            if (M1 == 0) {break;}
            if (HP1 < 200) {
                HP1 += (float)HP1*0.3 + 0.999;
                M1 -= 150;
                m1 += 150;
                HP(HP1, a);
                M (M1, a);
            } else {
                HP1 += (float)HP1*0.1 + 0.999;
                M1 -= 70;
                m1 += 70;
                HP(HP1, a);
                M (M1, a);
            }
            if(M1 == 0 || m1 > m2) {break;}
            if(EXP1 < 400) {
                M1 -= 200;
                m1 += 200;
                EXP1 += (float)EXP1*0.13 + 0.999;
                EXP(EXP1, a);
                M (M1, a);
            } else {
                M1 -= 120;
                m1 += 120;
                EXP1 += (float)EXP1*0.13 + 0.999;
                EXP(EXP1, a);
                M (M1, a);
            }
            if(M1 == 0 || m1 > m2) {break;}
            if(EXP1 < 300) {
                M1 -= 100;
                m1 += 100;
                EXP1 -= floor((float)EXP1*0.1);
                EXP(EXP1, a);                   
                M (M1, a);
                
            } else {
                M1 -= 120;
                m1 += 120;
                EXP1 -= floor((float)EXP1*0.1);
                EXP(EXP1, a);
                M (M1, a);
            }
            if(M1 == 0 || m1 > m2) {break;}
        }
    } 
    else 
    {
        while(1)
        {
            if (M1 == 0) {break;}
            if (HP1 < 200) {
                HP1 += (float)HP1*0.3 + 0.999;
                M1 -= 150;
                m1 += 150;
                HP(HP1, a);
                M (M1, a);
            } else {
                HP1 += ceil((float)HP1*0.1);
                M1 -= 70;
                m1 += 70;
                HP(HP1, a);
                M (M1, a);
            }
            if(M1 == 0) {break;}
            if(EXP1 < 400) {
                M1 -= 200;
                m1 += 200;
                EXP1 += (float)EXP1*0.13 + 0.999;
                EXP(EXP1, a);
                M (M1, a);
            } else {
                M1 -= 120;
                m1 += 120;
                EXP1 += (float)EXP1*0.13 + 0.999;
                EXP(EXP1, a);
                M (M1, a);
            }
            if(M1 == 0) {break;}
            if(EXP1 < 300) {
                M1 -= 100;
                m1 += 100;
                EXP1 -= floor((float)EXP1*0.1);
                EXP(EXP1, a);                   
                M (M1, a);
                
            } else {
                M1 -= 120;
                m1 += 120;
                EXP1 -= floor((float)EXP1*0.1);
                EXP(EXP1, a);
                M (M1, a);   
            }
            break;
        }
    }
        HP1 -= floor((float)HP1*0.17);
        HP (HP1, a);
        EXP1 += (float)EXP1*0.17+0.999;
        EXP (EXP1, a);
        if (find_sqr(EXP1) <= EXP1) P2 = 1;
        else P2= ((1.0*EXP1/find_sqr(EXP1))+80)/123;
        //road 3
        int arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        if(0<=E2 && E2<=9) {P3 = arr[E2]/100.0;}
        else {P3 = arr[(E2%10 + E2/10)%10]/100.0;}
        P = (P1 + P2 + P3)/3;
        if(P == 1.00){
            EXP1 -= floor((float)EXP1*0.25);
        } else if (P < 0.5){
            HP1 -= floor((float)HP1*0.15);
            EXP1 += (float)EXP1*0.15 + 0.999;
        } else {
            HP1 -= floor((float)HP1*0.1);
            EXP1 += (float)EXP1*0.2 + 0.999;
        }
        HP (HP1, a);
        EXP (EXP1, a);
        M (M1, a);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    HP (HP1, HP2);
    EXP (EXP1, EXP2);
    if (E3 < 0 || E3 > 99){
        return -99;
    }
    int matrix[10][10];
    int cmax = 0;
    int cmin = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            matrix[i][j] = ((E3*j) + (i*2))*(i-j);
        }
    }
    for (int i = 0; i < 10; i ++){
        for (int j = 0; j < 10; j++){
            if (matrix[i][j] > E3*2){cmax++;}
            if (matrix[i][j] < (-E3)){cmin++;}
        }
    }
    while (cmax >= 10) {cmax = cmax/10 + cmax%10;}
    while (cmin >= 10) {cmin = cmin/10 + cmin%10;}
    int max3 = matrix[cmax][cmin];
    int x = cmax;
    int y = cmin;
    while (0 <= x && x <= 9 && 0 <= y && y <= 9){
        if(matrix[x][y] > max3) {max3 = matrix[x][y];}
        x++;
        y++;
    }
    x = cmax;
    y = cmin;
    while (0 <= x && x <= 9 && 0 <= y && y <= 9){
        if(matrix[x][y] > max3) {max3 = matrix[x][y];}
        x++;
        y--;
    }
    x = cmax;
    y = cmin;
    while (0 <= x && x <= 9 && 0 <= y && y <= 9){
        if(matrix[x][y] > max3) {max3 = matrix[x][y];}
        x--;
        y++;
    }
    x = cmax;
    y = cmin;
    while (0 <= x && x <= 9 && 0 <= y && y <= 9){
        if(matrix[x][y] > max3) {max3 = matrix[x][y];}
        x--;
        y--;
    }//TH: duoi kip
    if(max3 >= abs(matrix[cmax][cmin])){
        EXP1 += ceil((float)EXP1*0.12);
        EXP2 += ceil((float)EXP2*0.12);
        HP1 += ceil((float)HP1*0.1);
        HP2 += ceil((float)HP2*0.1);
    } else {//TH: khong duoi kip
        EXP1 -= floor((float)EXP1*0.12);
        EXP2 -= floor((float)EXP2*0.12);
        HP1 -= floor((float)HP1*0.1);
        HP2 -= floor((float)HP2*0.1);
    }
    HP (HP1, HP2);
    EXP (EXP1, EXP2);
    if(max3 >= abs(matrix[cmax][cmin])){return max3;}
    else {return matrix[cmax][cmin];}
}

// Task 4
bool Special_Char(char c) {
    return (c == '@' || c == '#' || c == '%' || c == '$' || c == '!');
}
bool Normal_Char(char c) {
    if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
        return true;
    } return false;
}
bool Number(char c){
    if('0' <= c && c <= '9'){
        return true;
    } return false;
}
int checkPassword(const char * s, const char * email) {
    int pos = 0;
    while (email[pos] != '@' && email[pos] != '\0') {
        pos++;
    }
    char se[pos];
    for (int i = 0; i < pos; i++) {
        se[i] = email[i];
    }
    se[pos] = '\0';

    if (strlen(s) < 8) {return -1;}
    if (strlen(s) > 20) {return -2;}

    const char * find = strstr(s, se);
    if (find != NULL) {
        return -(300 + (find - s));
    }

    for (int sci = 0; sci < strlen(s) - 2; sci++) {
        if (s[sci] == s[sci + 1] && s[sci + 1] == s[sci + 2]) {
            return -(400 + sci);
        }
    }

    bool has_special_char = false;
    for (int i = 0; i < strlen(s); i++) {
        if (Special_Char(s[i])) {
            has_special_char = true;
            break;
        }
    }
    if (!has_special_char) return -5;

    for (int i = 0; i < strlen(s); i++) {
        if (!Normal_Char(s[i]) && !Special_Char(s[i]) && !Number(s[i])) {
            return i;
        }
    }
    return -10;
}

// Task 5
struct Password_Infor {
    int count; 
    int length;
};
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    Password_Infor password_infor[num_pwds];
    for (int i = 0; i < num_pwds; i++) {
        password_infor[i].count = 0;
        password_infor[i].length = 0;
    }
    for (int i = 0; i < num_pwds; i++) {
        const string& pwd = arr_pwds[i];
        int idx = -1;
        for (int j = 0; j < num_pwds; j++) {
            if (arr_pwds[j] == pwd) {
                idx = j;
                break;
            }
        }
        if (idx != -1) {
            password_infor[idx].count++;
            password_infor[idx].length = strlen(arr_pwds[idx]);
        }
    }
    int max_count = 0;
    int max_length = 0;
    int correct_idx = -1;
    for (int i = 0; i < num_pwds; ++i) {
        if (password_infor[i].count > max_count ||
            (password_infor[i].count == max_count && password_infor[i].length > max_length)) {
            max_count = password_infor[i].count;
            max_length = password_infor[i].length;
            correct_idx = i;
        }
    }
    return correct_idx;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////