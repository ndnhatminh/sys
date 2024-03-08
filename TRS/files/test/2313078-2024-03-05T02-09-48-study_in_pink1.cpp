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
void check_HP(int & HP){
if(HP < 0) HP = 0;
if(HP > 666) HP = 666;
}
void check_EXP(int & EXP){
if(EXP < 0) EXP = 0;
if(EXP > 600) EXP = 600;
}
void check_M(int & M){
if(M < 0) M = 0;
if(M > 3000) M = 3000;
}
int round_value(double a){
int b = a;
if((a - b) > 0.000001) return b + 1;
else return b;
}
int count_string(string a[], int b, string x){
    int c=0;
    for(int i=0; i<b; i++) if(x==a[i]) c++;
    return c;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

   int D;
    check_EXP( exp1 );
    check_EXP( exp2 );
    if((e1 >= 0) && (e1 <=3)){
    if(e1 == 0) exp2 += 29;
    else if(e1 == 1) exp2 += 45;
    else if(e1 == 2) exp2 += 75;
    else exp2 += 29 + 45 + 75;
    D = e1*3 + exp1*7;
    if(D % 2 == 0) exp1 = round_value(exp1 + D/200.0);
    else exp1 = round_value(exp1 - D/100.0);
    }
    if((e1 >= 4) && (e1 <= 99)){
        if(e1 <= 19) exp2 = round_value(e1/4.0 + 19 + exp2);
        else if(e1 <= 49) exp2 = round_value(e1/9.0 + 21 + exp2);
        else if(e1 <= 65) exp2 = round_value(e1/16.0 + 17 + exp2);
        else if(e1 <= 79){
            exp2 = round_value(e1/4.0 + 19 + exp2);
            if(exp2 > 200) exp2 = round_value(e1/9.0 + 21 + exp2);
        }
        else {
            exp2 = round_value(e1/4.0 + 19 + exp2);
            exp2 = round_value(e1/9.0 + 21 + exp2);
            if(exp2 > 400){ exp2 = round_value(e1/16.0 + 17 + exp2);
            exp2 = round_value(exp2*115/100.0);
         }
        }
        exp1 -= e1;
    }
    check_EXP( exp1 );
    check_EXP( exp2 );
    if((e1 >= 0) && (e1 <= 99)) return exp1 + exp2;
    else return -99;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 < 0 || E2 > 99) return -99;
int S, k;
double P1, P2, P3;
check_EXP( EXP1 );
check_HP( HP1 );
check_M( M1 );
k = sqrt(EXP1);
if ((EXP1 - k*k) > ((k + 1)*(k + 1) - EXP1)) S = (k + 1)*(k+1);
else S = k*k;
if(EXP1 >= S) P1 = 1;
else P1 = ((double)EXP1/S + 80)/123.0;
int M = M1;
do{
if(HP1 < 200){
    HP1 = round_value(1.3*HP1);
    M1 -= 150;
}
else {
    HP1 = round_value(1.1*HP1);
    M1 -= 70;
}
check_EXP( EXP1 );
check_HP( HP1 );
check_M( M1 );
if((E2 % 2 == 0) && (M1 <= 0)) break;
if((E2 % 2 == 1) && ((M-M1) > 0.5*M)) break;
if(EXP1 < 400) M1 -= 200;
else M1 -= 120;
EXP1 = round_value(1.13*EXP1);
check_EXP( EXP1 );
check_HP( HP1 );
check_M( M1 );
if((E2 % 2 == 0) && (M1 <= 0)) break;
if((E2 % 2 == 1) && ((M-M1) > 0.5*M)) break;
if(EXP1 < 300) M1 -= 100;
else M1 -= 120;
EXP1 = round_value(0.9*EXP1);
check_EXP( EXP1 );
check_HP( HP1 );
check_M( M1 );
if(E2 % 2 == 0) break;
if((E2 % 2 == 1) && ((M-M1) > 0.5*M)) break;
}
while((M-M1) <= 0.5*M);
check_EXP( EXP1 );
check_HP( HP1 );
check_M( M1 );
EXP1 = round_value(1.17*EXP1);
HP1 = round_value(0.83*HP1);
check_EXP( EXP1 );
check_HP( HP1 );
check_M( M1 );
k = sqrt(EXP1);
if ((EXP1 - k*k) > ((k + 1)*(k + 1) - EXP1)) S = (k + 1)*(k+1);
else S = k*k;
if(EXP1 >= S) P2 = 1;
else P2 = ((double)EXP1/S + 80)/123.0;
int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
int test2 = E2;
if(test2 >= 10) {test2 = test2/10 + test2%10;
  P3 = P[test2%10]/100.0;}
else P3 = P[test2]/100.0;

if((P1 >= 1) && (P2 >= 1) &&(P3 >= 1)) EXP1 = round_value(EXP1*0.75);
else if((P1 + P2 + P3)/3.0 < 0.5) {
    HP1 = round_value(HP1*0.85);
    EXP1 = round_value(EXP1*1.15);
}
else {
    HP1 = round_value(HP1*0.9);
    EXP1 = round_value(EXP1*1.2);
}
check_EXP( EXP1 );
check_HP( HP1 );
check_M( M1 );
 return HP1 + EXP1 + M1;
    }

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 < 0 || E3 > 99) return -99;
check_EXP( EXP2);
check_EXP( EXP1);
check_HP( HP1);
check_HP( HP2 );
int A[10][10] = {0}, B[10][10] = {0};
int max, m, n;
//tao ma tran de luu diem cua Sherlock va Watson
for(int i = 0; i <= 9; i++) for(int j = 0; j <= 9; j++) A[i][j] = ((E3*j)+(i*2))*(i-j);
for(int j = 0; j <= 9; j++) for(int i = 0; i <= 9; i++){
//tim gia tri lon nhat tren duong cheo phai di qua A[i][j]
 if(i + j <= 9){
        m = i + j;
        n = 0;
    }
    else {
        m = 9;
        n = i + j - 9;
    }
    max = A[i][j];
while((m >= 0)&&(n >= 0)&&(m <= 9)&&(n <= 9)){
if(max < A[m][n]) max = A[m][n];
m--;
n++;
}
//tim gia tri lon nhat tren duong cheo trai di qua A[i][j]
if(j - i >= 0){
        m = 0;
        n = j - i;
    }
    else {
        m = i - j;
        n = 0;
    }
while((m >= 0)&&(n >= 0)&&(m <= 9)&&(n <= 9)){
if(max < A[m][n]) max = A[m][n];
m++;
n++;
}
B[i][j] = max;
}
//
int a = 0, b = 0;
for(int i = 0; i <= 9; i++) for(int j = 0; j <= 9; j++){
if(A[i][j] > E3*2) a++;
if(A[i][j] < -E3) b++;
}
while(a > 9) a = a%10 + a/10;
while(b > 9) b = b%10 + b/10;
if(abs(A[a][b]) > B[a][b]){
    EXP1 = round_value(EXP1*0.88);
    HP1 = round_value(HP1*0.9);
    EXP2 = round_value(EXP2*0.88);
    HP2 = round_value(HP2*0.9);
}
else{
    EXP1 = round_value(EXP1*1.12);
    HP1 = round_value(HP1*1.1);
    EXP2 = round_value(EXP2*1.12);
    HP2 = round_value(HP2*1.1);
}
check_EXP( EXP2);
check_EXP( EXP1);
check_HP( HP1);
check_HP( HP2 );
    return ((abs(A[a][b]) > B[a][b])? A[a][b] : B[a][b]) ;

}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se, password, name_email;
    char test1;
    password = s;
    name_email = email;
    int a = password.length(), b = name_email.length();
    int c = name_email.find("@");
    se = name_email.substr(0, c);
    bool rq1 = 0, rq2 = 1, rq3 = 1, rq4 = 1, rq5 = 0;
    int pos_error2, pos_error4,pos_error3;
//
    if((a >= 8) && (a <= 20)) rq1 = 1;
    for(int i= a - 1; i >= 0; i--){
        test1 = password[i];
       if (!((test1 == '@')||(test1 == '#')||(test1 == '%')||(test1 == '$')||(test1 == '!')||((test1 >= '0')&&(test1 <= '9'))||((test1 >= 'A')&&(test1 <= 'Z'))||((test1 >= 'a')&&(test1 <= 'z')))) {
        rq2 = 0;
        pos_error2 = i;
       }
       if(i <= a-3) if(password[i] == password[i+1] && password[i]==password[i+2]) {
        rq4 = 0;
        pos_error4 = i;
       }
       if((test1 == '@')||(test1 == '#')||(test1 == '%')||(test1 == '$')||(test1 == '!')) rq5 = 1;
       }
      if((password.find(se) <= a)&&(password.find(se) >= 0)) {
        rq3 = 0;
        pos_error3 = password.find(se);
      }
      if(!(rq1)) if(a < 8) return -1; else return -2;
      if(!(rq3)) return -(300 + pos_error3);
      if(!(rq4)) return -(400 + pos_error4);
      if(!(rq5)) return -5;
      if(!(rq2)) return pos_error2;
      return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string password[num_pwds], true_pasword;
for(int i=0; i< num_pwds; i++) password[i]=arr_pwds[i];
true_pasword = password[0];
for(int i = 0;  i < num_pwds; i++){
    if(count_string(password, num_pwds, true_pasword) < count_string(password, num_pwds, password[i])) true_pasword = password[i];
    else if(count_string(password, num_pwds, true_pasword) == count_string(password, num_pwds, password[i])) 
if(true_pasword.length()<password[i].length()) true_pasword = password[i];
}
int pos;
for(int i=0; i<num_pwds; i++) if(password[i]== true_pasword) {
    pos =i;
    break;}
return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
