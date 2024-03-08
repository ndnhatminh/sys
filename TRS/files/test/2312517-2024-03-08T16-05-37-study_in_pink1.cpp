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
int tong(int a){
   int  i = ((a%100) / 10) + ((a%100) % 10);
    while (i > 9){
     i = ((i%100) / 10) + ((i%100) % 10);
    }
    return i;
}

int limit(int min, int max, int &val){
    if (val < min) {
        val = min;
    }
    else if (val > max){
        val = max;
    }
    return val;
}
// Task 1

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1<0 || e1 > 99){
        return -99;
    }
    limit(0,600,exp1);
    limit(0,600,exp2);
     
     if (e1>=0 && e1 <=3){
    int D = e1*3 + exp1*7;
     if (D%2==0){
        exp1 += ceil( D/200.0 -0.0000001);
    limit(0,600,exp1);
    limit(0,600,exp2);
     }
      else {
    exp1 += ceil( - D/100.0 -0.0000001);
    limit(0,600,exp1);
    limit(0,600,exp2);
     }
     }
    if(e1==0){
     exp2 += 29;
      limit(0,600,exp1);
    limit(0,600,exp2);
    }
    else if (e1==1){
        exp2+= 45;
        limit(0,600,exp1);
    limit(0,600,exp2);
    }
    else if (e1==2){
        exp2 +=75;
        limit(0,600,exp1);
    limit(0,600,exp2);
    }
    else if (e1 == 3){
        exp2 += (29 + 45 + 75);
      limit(0,600,exp1);
    limit(0,600,exp2);
    }
    if(e1>=4 && e1 <=99){
     if (e1 >= 4 && e1 <= 19){
        exp2 = ceil(exp2+(1.0*e1/4.0 + 19)-0.0001);
       limit(0,600,exp1);
    limit(0,600,exp2);
    }
    else if(e1 >= 20 && e1 <= 49 ){
       exp2 = ceil(exp2 + (1.0*e1/9.0 + 21)-0.0001);
      limit(0,600,exp1);
    limit(0,600,exp2);
        
    }
    else if(e1 >= 50 && e1 <= 65 ){
        exp2 = ceil(exp2+(1.0*e1/16.0 + 17)-0.0001);
       limit(0,600,exp1);
    limit(0,600,exp2);
    }
    else if(e1 >= 66 && e1 <= 79 ){
        exp2 = ceil(exp2+(1.0*e1/4.0 +19)-0.0001);
       limit(0,600,exp1);
    limit(0,600,exp2);
        if (exp2 > 200){
            exp2= ceil(exp2+(1.0*e1/9.0+21)-0.000001);
           limit(0,600,exp1);
    limit(0,600,exp2);
        }
    }
    else{
        exp2 = ceil(exp2 + (1.0*e1/4.0 +19) -0.0001);
         limit(0,600,exp1);
    limit(0,600,exp2);
        exp2 = ceil(exp2+(1.0*e1/9.0+21)-0.00001);
       limit(0,600,exp1);
    limit(0,600,exp2);
    if (exp2 >400){
        exp2 = ceil(exp2+(1.0*e1/16.0+17)-0.0001);
        limit(0,600,exp1);
    limit(0,600,exp2);
        exp2 =  ceil(exp2+exp2*0.15 - 0.0001);
    limit(0,600,exp1);
    limit(0,600,exp2);
    }
    }
    exp1 -= e1;
    }
    limit(0,600,exp1);
    limit(0,600,exp2);
    return exp1 + exp2;
}


// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
    if (E2 < 0 || E2 > 99) {
        return -99;
    }
    limit(0, 666, HP1);
    limit(0, 3000, M1);
     limit(0, 600, EXP1);
    double ans;
    double P1;

    int S1 = round(sqrt(EXP1));
    S1 *= S1;
    if (EXP1 >= S1) {
        P1 = 100;
    }
    else {
        P1 = (EXP1/S1 + 80)*100 / 123;
    }

    float tmp = M1 / 2.0;
    int paid = 0; 
    if(E2%2!=0){
    while (paid <= tmp) { 
         if (M1==0) {
            break;
        }
        if (HP1 < 200) {
            HP1 = ceil( 1.3*HP1 - 0.00001);
            M1 -= 150;
            paid += 150;
            limit(0, 666, HP1);
            limit(0, 3000, M1);
        }
        else {
            HP1 = ceil(1.1*HP1 - 0.00001);
            M1 -= 70;
            paid += 70;
            limit(0, 666, HP1);
            limit(0, 3000, M1);
        }

        if (paid > tmp) {
            break;
        }

        if (EXP1 < 400) {
            M1 -= 200;
            paid += 200;
            limit(0, 3000, M1);
        }
        else {
            M1 -= 120;
            paid += 120;
            limit(0, 3000, M1);
        }
        EXP1 = ceil(1.13*EXP1 - 0.0001);
        limit(0, 600, EXP1);

        if (paid > tmp) {
            break;
        }

        if (EXP1 < 300) {
            M1 -= 100;
            paid += 100;
            limit(0, 3000, M1);
        }
        else {
            M1 -= 120;
            paid += 120;
            limit(0, 3000, M1);
        }
        EXP1 = ceil(0.9*EXP1 - 0.0001);
        limit(0, 600, EXP1);
        limit(0, 666, HP1);
        limit(0, 3000, M1);
        if (paid > tmp) {
            break;
        }
    }
    }
    else {
       while(true){
    if (M1 ==0){
        break;
    }
 if (HP1 < 200)  {
    HP1 = ceil(1.3*HP1-0.00001);
    M1 -= 150;
     limit(0,666,HP1);
     limit(0,3000,M1);
}
else{
    HP1 = ceil(1.1*HP1-0.0001);
    M1 -= 70;
     limit(0,666,HP1);
     limit(0,3000,M1);
}
    if (M1 == 0){
        break;
    }
if (EXP1 < 400){
    M1 -= 200;
    limit(0,3000,M1);
}
else{
    M1 -= 120;
    limit(0,3000,M1);
}
EXP1 = ceil(1.13*EXP1 - 0.00001);
limit(0,600,EXP1);
limit(0,3000,M1);
 if (M1 ==0){
        break;
    }
if(EXP1 < 300){
    M1 -= 100;
    limit(0,3000,M1);
}
else {
    M1 -= 120;
    limit(0,3000,M1);
}
limit(0, 666, HP1);
    limit(0, 3000, M1);
EXP1 = ceil(0.9*EXP1-0.00001);
limit(0,600,EXP1);
    break;
        }
        }   
    HP1 = ceil(0.83*HP1 - 0.00001);
    limit(0, 666, HP1);
    EXP1 = ceil(1.17*EXP1 - 0.00001);
    limit(0, 600, EXP1);

    double P2;
    int S2 = round(sqrt(EXP1));
    S2 *= S2;
    if (EXP1 >= S2) {
        P2 = 100;
    }
    else {
        P2 = (EXP1/S2 + 80)*100 / 123;
    }

    float a[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 >= 0 && E2 <= 9) {
        i = E2;
    }
    else {
    int donvi=E2%10;
    int chuc=E2/10;
    i=(chuc+donvi)%10;
    }
    double P3 = a[i];
    if (P1 == 100 && P2 == 100 && P3 == 100) {
        EXP1 = ceil(0.75 * EXP1 - 0.00001);
        limit(0, 600, EXP1);
    }
    else {
        ans = (P1 + P2 + P3) / 3;
        if (ans < 50) {
            HP1 = ceil(0.85*HP1 - 0.00001);
            EXP1 = ceil(1.15*EXP1 - 0.00001);
            limit(0, 666, HP1);
            limit(0, 600, EXP1);
        }
        else {
            HP1 = ceil(0.9*HP1 - 0.00001);
            EXP1 = ceil(1.2*EXP1 - 0.0001);
            limit(0, 666, HP1);
            limit(0, 600, EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}


// Task 3
int maxofmatrix(int a[10][10], int r, int c ){
    int max = a[r][c];
    for (int k =1 ; r - k > 0 && c + k < 10; k++){
        if(a[r-k][c+k] > max) {
            max = a[r-k][c+k];
        }
    }
    for (int k =1 ; r + k < 10 && c - k > 0; k++){
        if(a[r+k][c-k] > max) {
            max = a[r+k][c-k];
        }
    }
    for (int k =1 ; r - k > 0 && c - k > 0; k++){
        if(a[r-k][c-k] > max) {
            max = a[r-k][c-k];
        }
    }
    for (int k =1 ; r + k < 10  && c + k < 10; k++){
        if(a[r+k][c+k] > max) {
            max = a[r+k][c+k];
        }
    }
    return max;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3>99){
        return -99;
    }
        HP1 = limit(0, 666, HP1);
        HP2 = limit(0, 666, HP2);
        EXP1 = limit(0, 600, EXP1);
        EXP2 = limit(0, 600, EXP2);
    int pos = 0 ;
    int nega = 0;
    int a[10][10];
     for (int i = 0 ; i < 10; i ++){
        for (int j = 0 ; j < 10 ; j ++){
           a[i][j] = ((E3 * j) + (2*i)) * (i - j);
        }
     }
    for (int i = 0 ; i < 10; i ++){
        for (int j = 0 ; j < 10 ; j ++){
            if (a[i][j] > E3 * 2){
                pos ++;
            }
            if (a[i][j] < -E3 ){
                nega ++;
            }
        }
    }
    int i = tong(pos);
    int j = tong(nega);
    int taxiPoint = a[i][j];
    int cPoint= abs(maxofmatrix(a,i,j));
    if (abs(taxiPoint) > cPoint){
        EXP1 = ceil (0.88*EXP1 - 0.0001);
        HP1 = ceil(0.9*HP1 - 0.0001);
        EXP2 = ceil(0.88*EXP2 - 0.0001);
        HP2 = ceil(0.9*HP2 - 0.0001);
        return taxiPoint;
    }
    else {
         EXP1 = ceil (1.12*EXP1 - 0.0001);
        HP1 = ceil(1.1*HP1 - 0.0001);
        EXP2 = ceil(1.12 *EXP2 - 0.0001);
        HP2 = ceil(1.1* HP2  - 0.0001);
         HP1 = limit(0, 666, HP1);
        HP2 = limit(0, 666, HP2);
        EXP1 = limit(0, 600, EXP1);
        EXP2 = limit(0, 600, EXP2);
        return cPoint;
    }
}

bool valid(string s) {
    for (char c : s) {
        if (!isalnum(c) && c != '@' && c != '#' && c != '%' && c != '$' && c != '!') {
            return false;
        }
    }
    return true;
}


bool check(const string se, const string s){
     int found = s.find(se);
    
    if (found != -1) {
        return true;
    } 

       return false;
   

}

bool same(string s) {
    int n = s.length();
    for (int i = 0; i <= n - 3; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) return false;
        
    }
    return true;
}

bool notfound(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            return true;
        }
    }
    return false;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
     string mk(s);
    int sei ;
     string se;
     int res =0;
    while (email[res] != '@' && email[res] != '\0') { 
    se += email[res];
    res++; 
}
   
  if(mk.length() < 8){
        return -1;
    }
    else if(mk.length() > 20){
        return -2;
    }
    else if (valid(mk) && !(check(se, mk)) &&
        same(mk) && notfound(mk)) {
        return -10;
    }
    else if(check(se,mk)){
        sei = mk.find(se);
        return -(300+sei);
    }
    else if (!same(mk)){
         for (int i = 0; i <= mk.length() - 3; i++) {
            if (mk[i] == mk[i + 1] && mk[i] == mk[i + 2]) {
                return -(400 + i);
            }
    }
    }
    else if(!notfound(mk)){
        return -5;
    }
    else{
        for (int i = 0; i < mk.length(); i++) {
        if (!isalnum(mk[i]) && mk[i] != '@' && mk[i] != '#' &&
            mk[i] != '%' && mk[i] != '$' && mk[i] != '!') 
            {
            return i;
        }
    }
   
}
 return 0;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    
    string a[num_pwds];
    for (int i = 0; i  < num_pwds; i++){
        a[i] = arr_pwds[i];
    }
    int pos=0;
    int countmax = 0;
    int length = 0;
    
    for(int i = 0 ; i < num_pwds; i ++){
        string snow = a[i];
     int count = 1;
       for(int j = i + 1; j < num_pwds;j++){
        if(a[j] == a[i]){
            count++;
     }
       }
    if(count > countmax){
        pos = i;
        countmax = count;
        length=a[i].length();
    }
    else if (count == countmax && a[i].length() > length ){
        pos = i ;
        length = a[i].length();
    } 
}
return pos;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////