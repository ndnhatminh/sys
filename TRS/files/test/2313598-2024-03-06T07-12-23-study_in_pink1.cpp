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
void expvalue(int & exp1, int & exp2){
    if (exp1 > 600)exp1=600;
    if (exp1 < 0)exp1=0;
    if (exp2 > 600)exp2=600;
    if (exp2 < 0)exp2=0;
}
void EXPandHPvalue(int & EXP1, int & HP1){
    if (EXP1 > 600)EXP1=600;
    if (EXP1 < 0)EXP1=0;
    if (HP1 > 666)HP1=666;
    if (HP1 < 0)HP1=0;
}
void moneyvalue(int & M1){
    if (M1 > 3000)M1=3000;
    if (M1 < 0)M1=0;
}
int sochinhphuong(int a){
    float b = sqrt(a);
    if (b - 0.5 > int(b)){
        return (int(b)+1)*(int(b)+1);
    }
    else return int(b)*int(b);
}
int pos_of_duplicates(const char * str){
    for (int i = 0; str[i]!='\0'; i++){
        if (str[i] == str[i+1] && str[i] == str[i+2]){
            return i;
        }
    }
    return -1000;
}
int kitudacbiet(const char * str){
    int t = 0;
    for (int i = 0; str[i]!='\0'; i++){
        if (str[i] == '@' || str[i] == '#' || str[i] == '%' || str[i] == '$' || str[i] == '!' ){
            t++;
        }
    }
    return t;
}
int kituhople(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        char currentChar = str[i];
        if (!((currentChar >= '0' && currentChar <= '9') || 
              (currentChar >= 'a' && currentChar <= 'z') || 
              (currentChar >= 'A' && currentChar <= 'Z') || 
              (currentChar == '@' || currentChar == '#' || currentChar == '%' || currentChar == '$' || currentChar == '!'))) {
            return i;
        }
    }
    return -1000;
}
int triso(int a){
    int b;
    if (a >= 10){ 
        b = (int(a/10)+a%10);
        if(b >=10)return (int(b/10)+b%10);
        else return b;
    }
    else return a;
}
int diemso(int map[10][10], int i, int j){
    const int oi = i;
    const int oj = j;
    int max = map[i][j];
    int num = 0;
    while (true ){
        i++;
        j++;
        if (i == 10 || j == 10){i = oi; j = oj; break;}
        num = map[i][j];
        if (num > max)max = num;
    }
    while (true ){
        i--;
        j--;
        if (i == -1 || j == -1){i = oi; j = oj; break;}
        num = map[i][j];
        if (num > max)max = num;
    }
    while (true ){
        i--;
        j++;
        if (i == -1 || j == 10){i = oi; j = oj; break;}
        num = map[i][j];
        if (num > max)max = num;
    }
    while (true ){
        i++;
        j--;
        if (i == 10 || j == -1){i = oi; j = oj; break;}
        num = map[i][j];
        if (num > max)max = num;
    }
    return max;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    expvalue(exp1,exp2);
    if (0>e1 || e1 >99)return -99;
    if (0<=e1 && e1<=3){if(e1 == 0)exp2=exp2+29;
    if(e1 == 1)exp2=exp2+45;
    if(e1 == 2)exp2=exp2+75;
    if(e1 == 3)exp2=exp2+29+45+75;
    int D = e1*3 + exp1*7;
    if(D%2==0){exp1=int(0.999+exp1+D*1.00/200);}
    else {exp1=int(0.999+exp1-D*1.00/100);}}
    if (4<=e1 && e1<=99){
        if (4<=e1 && e1<=19)exp2=int(0.999+exp2+e1*1.00/4+19);
        if (20<=e1 && e1<=49)exp2=int(0.999+exp2+e1*1.00/9+21);
        if (50<=e1 && e1 <=65)exp2=int(0.999+exp2+e1*1.00/16+17);
        if (66<=e1 && e1<=79){exp2=int(0.999+exp2+e1*1.00/4+19);
        expvalue(exp1,exp2);
        if (exp2 > 200)exp2=int(0.999+exp2+e1*1.00/9+21);expvalue(exp1,exp2);}
        if (80<=e1 && e1 <=99){exp2=int(exp2+e1*1.00/4+19+0.999)+int(e1*1.00/9+21+0.999);expvalue(exp1,exp2);
        if(exp2 > 400){exp2=int(exp2+e1*1.00/16+17+0.999);expvalue(exp1,exp2);exp2=int(exp2 * 115 / 100.0 + 0.999);}
        }
        exp1 = exp1 - e1;
    }
    expvalue(exp1,exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {

    if (E2 < 0 || E2 > 99) return -99;
    float P1,P2,P3;
    bool first = true;
    if (EXP1 >= sochinhphuong(EXP1))
        P1 = 100;
    else
        P1 = 100 * (EXP1 / sochinhphuong(EXP1) + 80) / 123.00;
    moneyvalue(M1);
    EXPandHPvalue(EXP1, HP1);
    float avrm = M1 / 2;
    float moneyspent = 0;

    // Xử lý con đường 2
    if (E2 % 2 != 0) {
        while (true) {
            if (HP1 < 200) {
                HP1 = int(0.999 + HP1 * 1.3 / 1.00);
                EXPandHPvalue(EXP1, HP1);
                M1 = M1 - 150;
                moneyvalue(M1);
                moneyspent = moneyspent + 150;
                if (M1 == 0 || moneyspent > avrm) break;
            } else {
                HP1 = int(0.999 + HP1 * 1.1 / 1.00);
                EXPandHPvalue(EXP1, HP1);
                M1 = M1 - 70;
                moneyvalue(M1);
                moneyspent = moneyspent + 70;
                if (M1 == 0 || moneyspent > avrm) break;
            }
            if (EXP1 < 400) {
                M1 = M1 - 200;
                moneyvalue(M1);
                EXP1 = int(0.999+EXP1 * 1.13 / 1.00);
                moneyspent = moneyspent + 200;
                EXPandHPvalue(EXP1, HP1);
                if (M1 == 0|| moneyspent > avrm) break;
            } else {
                M1 = M1 - 120;
                moneyvalue(M1);
                moneyspent = moneyspent + 120;
                EXP1 = int(0.999+EXP1 * 1.13 / 1.00);
                EXPandHPvalue(EXP1, HP1);
                if (M1 == 0 || moneyspent > avrm) break;
            }
            if (EXP1 < 300) {
                M1 = M1 - 100;
                moneyvalue(M1);
                moneyspent = moneyspent + 100;
                EXP1 = int(0.999+EXP1 * 0.9 / 1.00);
                EXPandHPvalue(EXP1, HP1);
                if (M1 == 0 || moneyspent > avrm) break;
            } else {
                M1 = M1 - 120;
                moneyvalue(M1);
                if (M1 == 0) break;
                moneyspent = moneyspent + 120;
                EXP1 = int(0.999+EXP1 * 0.9 / 1.00);
                EXPandHPvalue(EXP1, HP1);
                if (M1 == 0 || moneyspent > avrm) break;
            }
        }
    }else {
        while (first) {
            if (HP1 < 200) {
                HP1 = int(0.999 + HP1 * 1.3 / 1.00);
                EXPandHPvalue(EXP1, HP1);
                M1 = M1 - 150;
                moneyvalue(M1);
                if (M1 == 0) break;
            } else {
                HP1 = int(0.999 + HP1 * 1.1 / 1.00);
                EXPandHPvalue(EXP1, HP1);
                M1 = M1 - 70;
                moneyvalue(M1);
                if (M1 == 0) break;
            }
            if (EXP1 < 400) {
                M1 = M1 - 200;
                moneyvalue(M1);
                EXP1 = int(0.999+EXP1 * 1.13 / 1.00);
                if (M1 == 0) break;
            } else {
                M1 = M1 - 120;
                moneyvalue(M1);
                EXP1 = int(0.999+EXP1 * 1.13 / 1.00);
                EXPandHPvalue(EXP1, HP1);
                if (M1 == 0) break;
            }
            if (EXP1 < 300) {
                M1 = M1 - 100;
                moneyvalue(M1);
                EXP1 = int(0.999+EXP1 * 0.9 / 1.00);
                EXPandHPvalue(EXP1, HP1);
                if (M1 == 0) break;
            } else {
                M1 = M1 - 120;
                moneyvalue(M1);
                EXP1 = int(0.999+EXP1 * 0.9 / 1.00);
                EXPandHPvalue(EXP1, HP1);
                if (M1 == 0) break;
            }
            first = false;
        }
    }

    HP1 = int(0.999+HP1 * 0.83 /1.00);
    EXP1 = int(0.999+EXP1 * 1.17 /1.00);
    
    EXPandHPvalue(EXP1,HP1);
    moneyvalue(M1);
    if (EXP1 >= sochinhphuong(EXP1))P2 = 1*100;
    else P2 = 100*(EXP1 / sochinhphuong(EXP1) + 80)/123.0;
    //con duong 3
    int P[10]={32,47,28,79,100,50,22,83,64,11};
    int i;
    if(0>= E2 && E2 <10)i = E2;
    else i = (int(E2/10) + (E2%10))%10;
    P3 = P[i];
    //
    if(P1 == P2 && P1 == P3 && P3 == 100){
        EXP1 = int(0.999+EXP1 * 0.75/1.00);
        EXPandHPvalue(EXP1,HP1);}
    else if((P1 + P2 + P3)/3 < 50){
        HP1 = int(0.999+HP1 * 0.85 /1.00);
        EXP1 = int(0.999+EXP1 * 1.15 / 1.00);
        EXPandHPvalue(EXP1,HP1);}
    else {
        HP1 = int(0.999+HP1 * 0.9 /1.00);
        EXP1 = int(0.999+EXP1 * 1.20 / 1.00);
        EXPandHPvalue(EXP1,HP1);}
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (0>E3 || E3 >99)return -99;
    int count_i = 0;
    int count_j = 0;
    int map[10][10]={0};
    for (int i = 0; i <=9; i++){
        for(int j = 0; j <= 9; j++){
            map[i][j]=((E3 * j)+(i*2))*(i-j);
            if (map[i][j] > E3 * 2)count_i++;
            if (map[i][j] < -E3)count_j++;
        }
    }
    count_i = triso(count_i);
    count_j = triso(count_j);
    int diemtaxi= map[count_i][count_j];
    int diem = diemso(map, count_i, count_j);
    if (abs(diemtaxi)>diem){
        HP1 = int(0.999+HP1 * 0.9 /1.00);
        EXP1 = int(0.999+EXP1 * 0.88 / 1.00);
        HP2 = int(0.999+HP2 * 0.9 /1.00);
        EXP2 = int(0.999+EXP2 * 0.88 / 1.00);
        EXPandHPvalue(EXP1,HP1);
        EXPandHPvalue(EXP2,HP2);
        return diemtaxi;
    }
    else {
        HP1 = int(0.999+HP1 * 1.1 /1.00);
        EXP1 = int(+0.999+EXP1 * 1.12 / 1.00);
        HP2 = int(0.999+HP2 * 1.1 /1.00);
        EXP2 = int(0.999+EXP2 * 1.12 / 1.00);
        EXPandHPvalue(EXP1,HP1);
        EXPandHPvalue(EXP2,HP2);
        return diem;
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email)
{
    //TODO: Complete this function
    const char* behind = strchr(email, '@');
    size_t length = behind - email;
    string se(email, length);
    size_t length_s = strlen(s);
    string str(s);
    size_t found = str.find(se);
    bool valid = true;
    if (length_s < 8)return -1;
    if (length_s >20)return -2;
    //se trong s
    if (found != string::npos){
        string front_se = str.substr(0, found);
        const char* charArray = front_se.c_str();
       size_t length_to_se = std::strlen(charArray);
        return -(300 + length_to_se);
    }
    if (pos_of_duplicates(s)>=0)return -(pos_of_duplicates(s) +400);
    if (kitudacbiet(s)==0)return -5;
    if (kituhople(s)>=0)return kituhople(s);
    if(kitudacbiet(s)>=1)return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    int count_max = 0;
    int stt = 0;
    for (int i = 0; i < num_pwds; i++) {
        int count = 1; 
        int str_length = strlen(arr_pwds[i]); 
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;}}
        if (count > count_max || (count == count_max && str_length > strlen(arr_pwds[stt]))) {
            count_max = count;
            stt = i;
        }
    }
    return stt;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////