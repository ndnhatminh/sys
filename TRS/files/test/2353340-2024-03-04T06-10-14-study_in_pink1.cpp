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
    //case 1
    if (e1 < 0 || e1 > 99 ){
        return -99;
    }
    if (exp1 > 600) {exp1 = 600;}
    if (exp2 > 600) {exp2 = 600;}
    if (exp1 < 0) {exp1 = 0;}
    if (exp2 < 0) {exp2 = 0;}
    switch (e1) {
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
    if (0 <= e1 && e1 <= 3){
        int D = (e1 * 3) + (exp1 * 7);
        if (D % 2 == 0) {
            exp1 += (D / 200.0) + 0.999;
        }
        else{
            exp1 -= (D / 100.0) - 0.999;
        }
    }
    if (exp1 > 600) {exp1 = 600;}
    if (exp2 > 600) {exp2 = 600;}
    if (exp1 < 0) {exp1 = 0;}
    if (exp2 < 0) {exp2 = 0;}
    else
    //case 2
    if (4 <= e1 && e1 <= 19){
        exp2 += ceil((e1/4.0) + 19);
        exp1 -= e1;
    }
    else if (20 <= e1 && e1 <= 49){
        exp2 += ceil((e1/9.0) + 21);
        exp1 -= e1;
    }
    else if (50 <= e1 && e1 <= 65){
        exp2 += ceil((e1/16.0) + 17);
        exp1 -= e1;
    }
    else if (66 <= e1 && e1 <= 79){
        exp2 += ceil((e1/4.0) + 19);
        exp1 -= e1;
        if (exp2 > 200){
            exp2 += ceil((e1/9.0) + 21);
        }
    }
    else if (80 <= e1 && e1 <= 99){
        exp2 += ceil((e1/4.0) + 19);
        exp2 += ceil((e1/9.0) + 21);
        exp1 -= e1;
        if (exp2 > 400){
            exp2 += ceil((e1/16.0) + 17);
            exp2 += ceil(exp2 * 0.15);
        }
    }
    if (exp1 > 600){
    exp1 = 600;
    }
    else if (exp1 < 0){
    exp1 = 0;
    }
    if (exp2 > 600){
        exp2 = 600;
    }
    else if (exp2 < 0){
        exp2 = 0;
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
if (E2 < 0 || E2 > 99 ){
        return -99;
    }
    
                        //con đường 1
    double S = ((ceil(float(sqrt(EXP1)))) * (ceil(float(sqrt(EXP1))))); //nearest perfect square
    double P1; // tính P1
if (EXP1 >= S){
     P1 = 1;
}
else {
     P1 = ((EXP1/S) + 80) / 123.0;
}
                        //con đường 2
    if (M1 > 3000) {M1 = 3000;}
    else if (M1 < 0) {M1 = 0;}
    if (HP1 > 666) {HP1 = 666;}
    else if (HP1 < 0) {HP1 = 0;}
    if (EXP1 > 600) {EXP1 = 600;}
    else if (EXP1 < 0) {EXP1 = 0;}
int M = (ceil(M1 * 0.5));
int M1used = M1;
// lẻ
if (E2 % 2 != 0){
while (M1 - M1used < M){
    // mua đồ ăn
if (HP1 < 200){
    HP1 = ceil(float(HP1 * 1.3));
    M1used -= 150;
}
else {
    HP1 = ceil(float(HP1 * 1.1));
    M1used -= 70;
}
if (HP1 > 666)  {HP1 = 666;}
else if (HP1 < 0)   {HP1 = 0;}

if (((M1 - M1used) > M) || M1used <= 0){
    break;
}
else
    // chọn xe
if (EXP1 < 400){
    M1used -= 200;
    EXP1 = ceil(float(EXP1 * 1.13));
}
else {
    M1used -= 120;
    EXP1 = ceil(float(EXP1 * 1.13));
}
if (EXP1 > 600) {EXP1 = 600;}
else if (EXP1 < 0)  {EXP1 = 0;}

if (((M1 - M1used) > M) || M1used <= 0){
    break;
}
else

    // homeless
if (EXP1 < 300){
    M1used -= 100;
    EXP1 = ceil(float(EXP1 * 0.9));
}
else {
    M1used -= 120;
    EXP1 = ceil(float(EXP1 * 0.9));
}
if (EXP1 > 600) {EXP1 = 600;}
else if (EXP1 < 0)  {EXP1 = 0;}

if (((M1 - M1used) > M) || M1used <= 0){
    break;
}
}

if (M1used < 0){
    M1 = 0;
}
HP1 = ceil(float(HP1 * 0.83));
EXP1 = ceil(float(EXP1 * 1.17));

if (EXP1 > 600) {EXP1 = 600;}
else if (EXP1 < 0)  {EXP1 = 0;}
if (HP1 > 666)  {HP1 = 666;}
else if (HP1 < 0)   {HP1 = 0;}
}
// chẵn
else if(E2 % 2 == 0){
    if (HP1 < 200){
    HP1 = ceil(float(HP1 * 1.3));
    M1used -= 150;
}
else {
    HP1 = ceil(float(HP1 * 1.1));
    M1used -= 70;
}
if (HP1 > 666)  {HP1 = 666;}
else if (HP1 < 0)   {HP1 = 0;}

if (EXP1 < 400){
    M1used -= 200;
    EXP1 = ceil(float(EXP1 * 1.13));
}
else {
    M1used -= 120;
    EXP1 = ceil(float(EXP1 * 1.13));
}
if (EXP1 > 600) {EXP1 = 600;}
else if (EXP1 < 0)  {EXP1 = 0;}

if (EXP1 < 300){
    M1used -= 100;
    EXP1 = ceil(float(EXP1 * 0.9));
}
else {
    M1used -= 120;
    EXP1 = ceil(float(EXP1 * 0.9));
}
if (EXP1 > 600) {EXP1 = 600;}
else if (EXP1 < 0)  {EXP1 = 0;}

M1 = M1used;
HP1 = ceil(float(HP1 * 0.83));
EXP1 = ceil(float(EXP1 * 1.17));

if (EXP1 > 600) {EXP1 = 600;}
else if (EXP1 < 0)  {EXP1 = 0;}
if (HP1 > 666)  {HP1 = 666;}
else if (HP1 < 0)   {HP1 = 0;}
}
// tính P2
double P2;
if (EXP1 >= S){
    P2 = 1.0;
}
else {
    P2 = ((EXP1/S) + 80) / 123.0;
}
                        // con đường 3 (tính P3)
double P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
int i = 0;
int sum = 0;
if (E2 < 10){
    i = E2;
}
else {
sum = (E2/10) + (E2%10); //tổng 2 số
i = sum % 10; // lấy số hàng đơn vị
}
double P3 = P[i] / 100.0;

// đi hết 3 con đường
double avg = (P1 + P2 + P3)/3.0;
if (avg == 1){
    EXP1 = ceil(float(EXP1 * 0.75)) ;
}
else if(avg < 0.5){
   HP1 = ceil(float(HP1 * 0.85));
    EXP1 = ceil(float(EXP1 * 1.15));
}
else if(avg > 0.5){
    HP1 = ceil(float(HP1 * 0.9));
   EXP1 = ceil(float(EXP1 * 1.2));
}

if (M1used < 0){
    M1used = 0;
}
M1 = M1used;
if (EXP1 > 600) {EXP1 = 600;}
else if (EXP1 < 0)  {EXP1 = 0;}
if (HP1 > 666)  {HP1 = 666;}
else if (HP1 < 0)   {HP1 = 0;}

    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
if (E3 < 0 || E3 > 99 ){
        return -99;
    }
    if (HP1 > 666) {HP1 = 666;}
    else if (HP1 < 0) {HP1 = 0;}
    if (EXP1 > 600) {EXP1 = 600;}
    else if (EXP1 < 0) {EXP1 = 0;}
    if (HP2 > 666) {HP2 = 666;}
    else if (HP2 < 0) {HP2 = 0;}
    if (EXP2 > 600) {EXP2 = 600;}
    else if (EXP2 < 0) {EXP2 = 0;}
            // tính taxi
    int matrix_taxi[10][10] = {0};
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            matrix_taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
        // taxi gặp 2 người
    int i_taxi = 0;
    int j_taxi = 0;
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
            if (matrix_taxi[i][j] > (E3 * 2)){
                i_taxi++;
            }
            else if (matrix_taxi[i][j] < -E3){
                j_taxi++;
            }    
        }        
    }
        
        while (i_taxi >= 10){
            i_taxi = (i_taxi /10) + (i_taxi %10);
            }
        
        while (j_taxi >= 10){
            j_taxi = (j_taxi /10) + (j_taxi %10);
            }
        
        // điểm taxi
    int taxi = matrix_taxi[i_taxi][j_taxi];
        // đường chéo (bắt đầu từ vị trí taxi)
    int highestscore = 0;
int i_cheo = i_taxi;
int j_cheo = j_taxi;
        // chéo trái
        while ((i_cheo >= 0) && (j_cheo >= 0) && (i_cheo < 10) && (j_cheo < 10)){
            highestscore = max(highestscore, matrix_taxi[i_cheo][j_cheo]);
            i_cheo++;
            j_cheo++;
        }
        
        // chéo phải
i_cheo = i_taxi;
j_cheo = j_taxi;
        // hàm tăng cột giảm
         while ((i_cheo < 10) && (j_cheo < 10) && (i_cheo >= 0) && (j_cheo >= 0)){
            highestscore = max(highestscore, matrix_taxi[i_cheo][j_cheo]);
            i_cheo++;
            j_cheo--;
        }
        
        // điểm 2 người
        int sherlock_watson = highestscore;
        // đuổi
        if (abs(taxi) > sherlock_watson){
            EXP1 = ceil(float(EXP1 * 0.88));
            EXP2 = ceil(float(EXP2 * 0.88));
            HP1 = ceil(float(HP1 * 0.9));
            HP2 = ceil(float(HP2 * 0.9));
        }
        else {
            EXP1 = ceil(float(EXP1 * 1.12));
            EXP2 = ceil(float(EXP2 * 1.12));
            HP1 = ceil(float(HP1 * 1.1));
            HP2 = ceil(float(HP2 * 1.1));
        }
if (EXP1 > 600){
    EXP1 = 600;
}
else if (EXP1 < 0){
    EXP1 = 0;
}
if (HP1 > 666){
    HP1 = 666;
}
else if (HP1 < 0){
    HP1 = 0;
}
if (EXP2 > 600){
    EXP2 = 600;
}
else if (EXP2 < 0){
    EXP2 = 0;
}
if (HP2 > 666){
    HP2 = 666;
}
else if (HP2 < 0){
    HP2 = 0;
}

if (abs(taxi) > sherlock_watson){
    return taxi;
}
else {
return sherlock_watson;
}
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
            // lấy chữ trước @
    string emails(email);
    string se(100, '\0');
se = emails.substr(0, emails.find("@"));
            // check pass
    string pass(s);
            // 8 - 20 ký tự
    if (pass.length() < 8){
        return -1; 
    }
    if (pass.length() > 20){
        return -2;
    }
            // contain se
    if (pass.find(se) != string::npos){
        int sei = pass.find(se);
        return -(300 + sei);
    }
            // 2 ký tự giống nhau liên tiếp
    for (int sci = 0; sci < pass.length() - 2; sci++){
        if ((pass[sci] == pass[sci+1]) && (pass[sci] == pass[sci+2])){
         return -(400 + sci); 
        }
    }
            // ký tự đặc biệt
        bool hasspecial = false;
        for (char special : pass){
            if (special == '@' || special == '#' || special == '%' || special == '$' || special == '!'){
                hasspecial = true;
                break;
            }
        }
        if (!hasspecial){
            return -5;
        }
            // trường hợp còn lại
        long long unsigned int pos[] = {pass.find('['), pass.find(']'), pass.find('{'), pass.find('}'), pass.find('^'), pass.find('&'), pass.find('*'), pass.find('('), pass.find(')'), pass.find('-'), pass.find('_'), pass.find('+'), pass.find('='), pass.find('|'), pass.find(':'), pass.find(';'), pass.find('"'), pass.find('<'), pass.find('>'), pass.find(','), pass.find('.'), pass.find('?'), pass.find('/'), pass.find('~'), pass.find('`') };
        for (int invalid : pos){
            if (invalid != string::npos){
                return invalid;
            }
        }
    
        return -10;
       
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int frequent[num_pwds] = {0}; //số lần xuất hiện
    int passlength[num_pwds] = {0}; // độ dài chữ
    int first_occur[num_pwds] = {0}; // vị trí đúng đầu tiên

    for (int i = 0; i < num_pwds; i++){
        int length = strlen(arr_pwds[i]);
        bool pass_exist = false;

        for (int j = 0; j < i; j++){
        if ( strcmp(arr_pwds[i],arr_pwds[j]) == 0 /*so sánh char*/){
            pass_exist = true;
            frequent[j]++;
            if (length > passlength[j]){
            passlength[j] = length;
        }
        break;
    }
}
        // chưa tồn tại mất khẩu đầu tiên
    if (!pass_exist){
        frequent[i]++;
        passlength[i] = length;
        first_occur[i] = i;
    }
}
    
    int maxfrequent = 0; // most occur
    int maxlength = 0; // pass dài nhất
    int result = num_pwds; // kq vị trí đúng đầu tiên

   for (int k = 0; k < num_pwds; k++){
    if ((frequent[k] > maxfrequent) || ( (frequent[k] == maxfrequent) && (passlength[k] > maxlength) )){
        maxfrequent = frequent[k];
        maxlength = passlength[k];
        result = first_occur[k];
    }
   }
   return result;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////