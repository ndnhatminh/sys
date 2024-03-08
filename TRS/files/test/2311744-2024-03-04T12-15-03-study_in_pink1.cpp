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

int check (int n, int min, int max){
    if (n < min){ 
        return min;}
    else if (n > max){
        return max;}
    else {
        return n;}
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1<0 || e1 >99) {return -99;} 
    double test_exp1 = exp1;  
    double test_exp2 = exp2; 
    test_exp1 = check(test_exp1,0,600); 
    test_exp2 = check(test_exp2,0,600);
    if (e1 >= 0 && e1 <= 3){
        if (e1 == 0) {test_exp2 =test_exp2 + 29;}
        else if (e1 == 1) {test_exp2 = test_exp2 + 45;}
        else if (e1 == 2) {test_exp2 = test_exp2 + 75;} 
        else if (e1 == 3) {test_exp2 = test_exp2 + 149;}
        int D = e1 * 3 + test_exp1 * 7; 
            if (D % 2 == 0){
                test_exp1 = test_exp1 + double(D)/200; 
                test_exp1 = ceil(test_exp1);
                exp1 = test_exp1;
                exp1 = check(exp1,0,600);
                test_exp1 = exp1;
            }
            else {
                test_exp1 = test_exp1 -double (D)/100;
                test_exp1 = ceil(test_exp1);
                exp1 = test_exp1;
                exp1 = check(exp1,0,600);
                test_exp1 = exp1;
            }
        test_exp2 = ceil(test_exp2);
        exp2 = test_exp2;
        exp2 = check(exp2,0,600);
        test_exp2 = exp2;
    }
    else if (e1 >=4 && e1 <= 99){
        if (e1 >=4 && e1 <= 19){ 
            test_exp2 = test_exp2 + double (e1)/4 +19;
            test_exp2 = ceil(test_exp2);
            exp2 = test_exp2;
            exp2 = check(exp2,0,600);
            test_exp2 = exp2;
        }
        else if (e1 >= 20 && e1 <= 49){
            test_exp2 = test_exp2 +double (e1)/9 +21;
            test_exp2 = ceil(test_exp2);
            exp2 = test_exp2;
            exp2 = check(exp2,0,600);
            test_exp2 = exp2;
        }
        else if (e1 >= 50 && e1 <= 65){ 
            test_exp2 = test_exp2 + double (e1)/16 + 17; 
            test_exp2 = ceil(test_exp2);
            exp2 = test_exp2; 
            exp2 = check(exp2,0,600);
            test_exp2 = exp2;
        }
        else if (e1 >= 66 && e1 <= 79){
            test_exp2 = test_exp2 + double (e1)/4 +19;
            test_exp2 = ceil(test_exp2);
            exp2 = test_exp2;
            exp2 = check(exp2,0,600);
            test_exp2 = exp2;
            if (test_exp2 > 200){
                test_exp2 = test_exp2 + double (e1)/9 +21;
                test_exp2 = ceil(test_exp2);
                exp2 = test_exp2;
                exp2 = check(exp2,0,600);
                test_exp2 = exp2;
            }
        }
        else if (e1>=80 && e1 <=99) {
            test_exp2 = test_exp2 + double (e1)/4 +19;
            test_exp2 = ceil(test_exp2);
            exp2 = test_exp2;
            exp2 = check(exp2,0,600);
            test_exp2 = exp2;
            test_exp2 = test_exp2 +double (e1)/9 +21;
            test_exp2 = ceil(test_exp2);
            exp2 = test_exp2;
            exp2 = check(exp2,0,600);
            test_exp2 = exp2;
            if (test_exp2 > 400){
                test_exp2 = test_exp2 +double (e1)/16 + 17;
                test_exp2 = ceil(test_exp2);
                test_exp2 = test_exp2 * 1.15;
                test_exp2 = ceil(test_exp2);
                exp2 = test_exp2;
                exp2 = check(exp2,0,600);
                test_exp2 = exp2;
            }
        }
    test_exp1 = test_exp1 - e1;
    test_exp1 = ceil(test_exp1); 
    exp1 = test_exp1;
    exp1 = check(exp1,0,600);
    test_exp1 = exp1; 
    }
    
    return exp1 + exp2;
}
//hàm cho Task2

int chinhphuong(int n) { 
    int sonho = floor(sqrt(n));
    int x1 = sonho * sonho; 
    int x2 = (sonho + 1) * (sonho + 1); 

    if (abs(n - x1) < abs(x2 - n)) {
        return x1;
    } else {
        return x2;
    }
}

double street1(int EXP1){
    int s= chinhphuong(EXP1); 
    double P1 ;
    if (EXP1 >= s){
        P1 = 100;
        return  P1;
    }
    else {
        P1 = ((EXP1/double(s) + 80)/123) *100;
        return P1;
    }
}

double street2(int &HP1, int &EXP1, int &M1, int E2) {
    if (E2 < 0 || E2 >99) {return -99;}
    double test_hp1 = HP1; 
    double test_exp1 = EXP1;
    test_exp1 = check(test_exp1,0,600);
    test_hp1 = check(test_hp1,0,666);
    if (E2 % 2 != 0){
        double M0 = M1/2; 
        while (M1 >= M0){
            // sự kiện 1
            if (test_hp1 < 200) {
                test_hp1 = test_hp1 * 130/100; 
                test_hp1 = ceil(test_hp1);
                HP1 = test_hp1;
                M1 = M1 - 150;
            } else {
                test_hp1 = test_hp1 * 110/100;
                test_hp1 = ceil(test_hp1);
                HP1 = test_hp1;
                M1 = M1 - 70;
            }
            HP1 = check(HP1,0,666);
            test_hp1 = HP1;
            M1 = check(M1,0,3000); 
            if (M1 < M0){ break;}
            // sự kiện 2
            if (test_exp1 < 400) {
                M1 = M1 - 200;
                test_exp1 = test_exp1 * 113/100; 
                test_exp1 = ceil(test_exp1);
                EXP1 = test_exp1; 
            } else {
                M1 = M1 - 120;
                test_exp1 = test_exp1 * 113/100;
                test_exp1 = ceil(test_exp1);
                EXP1 = test_exp1;
            }
            M1 = check(M1,0,3000);
            EXP1 = check(EXP1,0,600);
            test_exp1 = EXP1;
            if (M1 < M0){ break;}
            //sự kiện 3
            if (test_exp1 <300){
                M1 = M1 - 100;
                test_exp1 = test_exp1 * 90/100;
                test_exp1 = ceil(test_exp1);
                EXP1 = test_exp1 ;
            }
            else {
                M1 = M1 - 120;
                test_exp1 = test_exp1 * 90/100;
                test_exp1 = ceil(test_exp1);
                EXP1 = test_exp1;
            }
            M1 = check(M1,0,3000);
            EXP1 = check(EXP1,0,600); 
            test_exp1 = EXP1;
            if (M1 < M0){ break;}
        }
    }
    else {
        for (int i=0; i<1;i++){
            // sự kiện 1
            if (M1 == 0){ break;}
            if (test_hp1 < 200) {
                test_hp1 = test_hp1 * 130/100;
                test_hp1 =ceil(test_hp1);
                HP1 = test_hp1;
                M1 = M1 - 150;
            } else {
                test_hp1 = test_hp1 * 110/100;
                test_hp1 = ceil(test_hp1);
                HP1 = test_hp1;
                M1 = M1 - 70;
            }
            HP1 = check(HP1,0,666);
            test_hp1 = HP1;
            M1 = check(M1,0,3000);
            if (M1 == 0){ break;}
            // sự kiện 2
            if (test_exp1 < 400) {
                M1 = M1 - 200;
                test_exp1 =test_exp1 * 113/100;
                test_exp1 = ceil(test_exp1);
                EXP1 = test_exp1;
            } else {
                M1 = M1 - 120;
                test_exp1 = test_exp1 * 113/100;
                test_exp1 = ceil(test_exp1);
                EXP1 = test_exp1;
            }
            M1 = check(M1,0,3000);
            EXP1 = check(EXP1,0,600);
            test_exp1 = EXP1;
            if (M1 == 0){ break;}
            //sự kiện 3
            if (test_exp1 <300){
                M1 = M1 - 100;
                test_exp1 = test_exp1 * 90/100;
                test_exp1 = ceil(test_exp1);
                EXP1 = test_exp1;
            }
            else {
                M1 = M1 - 120;
                test_exp1 = test_exp1 * 90/100;
                test_exp1 = ceil(test_exp1);
                EXP1 = test_exp1;
            }
            M1 = check(M1,0,3000);
            EXP1 = check(EXP1,0,600);
            test_exp1 = EXP1;
            if (M1 == 0){ break;}
        }
        }
    test_hp1 = test_hp1 * 83/100;
    test_hp1 = ceil(test_hp1);
    HP1 =test_hp1;
    test_exp1 = test_exp1 * 117/100;
    test_exp1 = ceil(test_exp1);
    EXP1 = test_exp1;
    HP1 = check(HP1,0,666); test_hp1 = HP1;
    EXP1 = check(EXP1,0,600); test_exp1 =EXP1;
    int s2= chinhphuong(EXP1);
    double P2 ; 
    if (EXP1 >= s2){
        P2 = 100;
        return  P2;
    }
    else {
        P2 = ((EXP1/double(s2) + 80)/123)*100;
        return P2;
    }
}

double street3(int E2){
    if (E2 < 0 || E2 >99) {return -99;}    
    double P3;
    int P[] = {32,47,28,79,100,50,22,83,64,11};
    if (E2 < 10){
        P3 = P[E2];
        return P3;
    }
    else {
        int a = (E2/10) + (E2%10);//tổng hai chữ số
        int b = a % 10;
        P3 = P[b];
        return P3;
    }
}    

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 >99) {return -99;} 

    double p1 = street1(EXP1);
    double p2 = street2(HP1,EXP1,M1,E2);
    double p3 = street3(E2);
    double test_hp1 = HP1;
    double test_exp1 = EXP1;
    if (p1 == 100 && p2 == 100 && p3 == 100 ){
        test_exp1 = test_exp1 * 0.75;
        test_exp1 = ceil(test_exp1);
        EXP1 = test_exp1;
        EXP1 = check(EXP1,0,600);
        test_exp1 = EXP1;
    }
    else{
        double avg = (p1+p2+p3)/3;
        if (avg < 50){
            test_hp1 =test_hp1 * 0.85;
            test_hp1 =ceil(test_hp1);
            HP1 = test_hp1;
            test_exp1 = test_exp1 * 1.15;
            test_exp1 = ceil(test_exp1);
            EXP1 = test_exp1;
        }
        else {
            test_hp1 =test_hp1 * 0.9;
            test_hp1=ceil(test_hp1);
            HP1 = test_hp1;
            test_exp1 = test_exp1 * 1.2;
            test_exp1 = ceil(test_exp1);
            EXP1 = test_exp1; 
        }
    HP1 = check(HP1,0,666); 
    EXP1 = check(EXP1,0,600);
    }
    return HP1 + EXP1 + M1;
}  

//hàm cho Task 3
int kiemtraso(int number) {
    if (number < 10) {
        return number;
    }
    else {
        int sum = (number/10) + (number%10);
        while (sum >= 10) {
            sum = (sum/10) + (sum%10);
        }
        return sum;
    }
}

int cheophai(int a, int b, int arr[][10]) {
    int tong = a + b;
    int max = arr[a][b];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i + j == tong) {
                if (arr[i][j] > max) {
                    max = arr[i][j];
                }
            }
        }
    }

    return max;
}

int cheotrai(int a, int b, int arr[][10]) {
    int hieu = a - b;
    int max = arr[a][b];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i - j == hieu) {
                if (arr[i][j] > max) {
                    max = arr[i][j];
                }
            }
        }
    }

    return max;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) {return -99;}
    HP1 = check(HP1,0,666);
    HP2 = check(HP2,0,666);
    EXP1 = check(EXP1,0,600);
    EXP2 = check(EXP2,0,600);
    double test_hp1=HP1;
    double test_hp2=HP2;
    double test_exp1=EXP1;
    double test_exp2=EXP2;
    int mat[10][10] = {0};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            mat[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    int count1 = 0, count2 = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (mat[i][j] > (E3 * 2)) {
                count1 += 1;
            }
            if (mat[i][j] < (-E3)) {
                count2 += 1;
            }
        }
    }

    int a = kiemtraso(count1);
    int b = kiemtraso(count2); 
    int taxi = mat[a][b]; 
    int max1 = cheotrai(a, b, mat); 
    int max2 = cheophai(a, b, mat); 
    int holmes = (max1>max2) ? max1 : max2;
    holmes = abs(holmes);
    if(holmes>= abs(taxi)){
        test_hp1 = test_hp1 * 110/100;
        test_hp1 = ceil(test_hp1);
        HP1 = test_hp1;
        test_exp1 = test_exp1 * 112/100;
        test_exp1 = ceil(test_exp1);
        EXP1 = test_exp1;
        test_hp2 = test_hp2 * 110/100;
        test_hp2 = ceil(test_hp2);
        HP2 = test_hp2;
        test_exp2 = test_exp2 * 112/100;
        test_exp2 = ceil(test_exp2);
        EXP2 = test_exp2;
        HP1 = check(HP1,0,666);
        HP2 = check(HP2,0,666);
        EXP1 = check(EXP1,0,600);
        EXP2 = check(EXP2,0,600);
        return holmes;
    }
    else{
        test_hp1 = test_hp1 * 90/100;
        test_hp1 = ceil (test_hp1);
        HP1 = test_hp1;
        test_exp1 = test_exp1 * 88/100;
        test_exp1 = ceil(test_exp1);
        EXP1 = test_exp1;
        test_hp2 = test_hp2 * 90/100;
        test_hp2 = ceil(test_hp2);
        HP2 = test_hp2;
        test_exp2 = test_exp2 * 88/100;
        test_exp2 = ceil(test_exp2);
        EXP2 = test_exp2;
        HP1 = check(HP1,0,666);
        HP2 = check(HP2,0,666);
        EXP1 = check(EXP1,0,600);
        EXP2 = check(EXP2,0,600);
        return taxi;       
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    int a = 0;
    for (int i=0;email[i] != '\0';i++) {
        if (email[i] == '@'){
            a=i;
            break;
        }
    }
    char se[a+1];  
    strncpy(se, email, a);
    se[a] = '\0'; 
    int leng = strlen(s);
    if (leng < 8){ return -1;} // điều kiện 1
    if (leng > 20){ return -2;}// điều kiện 2
    const char *sei = strstr(s, se);
    if (sei != nullptr) {
        return -(300 + (sei - s)); //điều kiện 3
    }
    
    for (int i = 0; i < (leng - 2 ); i++) // điều kiện 4
    {
        if (s[i]==s[i+1] && s[i+1] == s[i+2]){
            return -(400+ i);
        }
    }
    bool hspc = false;//điều kiện 5
    const char spc[] = {'@', '#', '%', '$', '!'};
    for (int i=0; i< leng; i++){
        if (strchr(spc,s[i]) != nullptr)
        {
            hspc = true;
            break;
        }
        
    } 
    if (!hspc){
        return -5;
    }

    for (int i = 0;s[i] != '\0'; i++){
        if (!isalnum(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!')
        {
            return i;
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string password[num_pwds];
    int countpw[num_pwds]= {};
    int lengpw[num_pwds]= {};
    int lengmax=0;
    int vitri = 0;

    for (int i = 0; i < num_pwds; i++)
    {
        password[i] = arr_pwds[i];
        lengpw[i] = strlen(arr_pwds[i]);
        for (int  j = 0; j < num_pwds; j++)
        {
            if (arr_pwds[j] == password[i])
            {
                countpw[i]++;
            }
        }
    }
    int countmax = countpw[0];
    for (int i = 0; i < num_pwds; i++)
    {
        if (countpw[i] > countmax){
            countmax = countpw[i];
        }
    }
    for (int i = 0; i < num_pwds; i++)
    {
        if (countpw[i] == countmax)
        {
            if (lengpw[i] > lengmax)
            {
                lengmax = lengpw[i];
                vitri = i;
            }
        }  
    }
   return vitri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////