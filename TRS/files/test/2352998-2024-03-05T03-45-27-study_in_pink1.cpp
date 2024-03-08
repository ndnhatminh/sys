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

//! Task 1
void checkHP(int& HP) {
    if (HP > 666)
        HP = 666;
    else if (HP < 0)
        HP = 0;
}
void checkEXP(int& EXP){
    if (EXP > 600)
        EXP = 600;
    else if (EXP < 0)
        EXP = 0;       
}   
void checkM(int& M){
    if (M > 3000)
        M = 3000;
    else if (M < 0)
        M = 0;    
}     

int firstMeet(int& EXP1, int& EXP2, int E1) {
    if (E1 < 0 || E1 > 99){
    return -99;
}

    if (E1 >= 0 && E1 <= 3){
        if (E1<3){
            int arr[] = {29, 45, 75};
            EXP2+=arr[E1];
        checkEXP(EXP2);    
        }
        else if (E1==3){
            EXP2+=149;
        checkEXP(EXP2);
        }   
        int D = E1 * 3 + EXP1 * 7;
        if ((D%2)==0){
            EXP1+=ceil(D/200.0);
        checkEXP(EXP1);
        
        } 
        else if ((D%2)!=0){
            EXP1-=floor(D/100.0);
        checkEXP(EXP1);    
        }  
    }
    else if (E1<=99){
        if (E1 <= 19){
            EXP2+=ceil(E1/4.0+19);   
        checkEXP(EXP2);
        }
        else if (E1<=49){
            EXP2+=ceil(E1/9.0+21);
        checkEXP(EXP2);    
        }
        else if (E1<=65){
            EXP2+=ceil(E1/16.0+17);
         checkEXP(EXP2);   
        }
        else if (E1<=79){
            EXP2+=ceil(E1/4.0+19);
            if (EXP2>200){
                EXP2+=ceil(E1/9.0+21);
            checkEXP(EXP2);    
            }   
        }
        else if (E1<=99){
            EXP2=ceil(EXP2+(E1/4.0)+19);
            EXP2=ceil(EXP2+(E1/9.0)+21);
            if (EXP2>400){
                EXP2=ceil(EXP2+(E1/16.0)+17);
                EXP2=ceil(EXP2+EXP2*0.15);
            checkEXP(EXP2);    
            }
        }
            EXP1-=E1;
            checkEXP(EXP1);
        
    }
    checkEXP(EXP1);
    checkEXP(EXP2);
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99){
    return -99;
    } 
    int S, a, b;
    float P1;
    a = floor(sqrt(EXP1));
    b = floor (sqrt(EXP1)+1);
    if ((EXP1 - pow(a,2)) > (pow(b,2) - EXP1)){
        S = pow(b,2);
    }
    else{
        S = pow(a,2);
    }
    if (EXP1 >= S){
        P1 = 1;
    }          
    else{
        P1 = (((EXP1 * 1.0 / S) + 80) / 123.0);
    }           
    int budget = ceil(M1 * 0.5);    
    int paid = 0; 
    if ((E2 % 2) != 0){  
    while ((E2 % 2) != 0){
        if (M1 == 0){
            break;
        }
        if (HP1 < 200){
            HP1=ceil(HP1+HP1*0.3);
            checkHP(HP1);
            M1 -= 150;
            checkM(M1);
            paid += 150;
            if (paid > budget){
            break;
        }
            if (M1 == 0){
            break;
        }
        }
        else{
            HP1=ceil(HP1+HP1*0.1);
            checkHP(HP1);
            M1-=70;
            checkM(M1);
            paid += 70;
            if (paid > budget){
            break;
        }
            if (M1 == 0){
            break;
        }
        }
        if (EXP1 < 400){
            EXP1 = ceil(EXP1+EXP1*0.13);
            checkEXP(EXP1);
            M1 -= 200;
            checkM(M1);
            paid += 200;
            if (paid > budget){
            break;
        }
            if (M1 == 0){
            break;
        }
        }
        else{
             EXP1 = ceil(EXP1+EXP1*0.13);
             checkEXP(EXP1);
             M1 -= 120;
             checkM(M1);
             paid += 120;
             if (paid > budget){
            break;
        }
             if (M1 == 0){
            break;
        }
        }
        if (EXP1 < 300){
             M1 -= 100;
             checkM(M1);
             paid += 100;
             EXP1 = ceil(EXP1 - 0.1 * EXP1);
             checkEXP(EXP1);
             if (paid > budget){
            break;
        }
             if (M1 == 0){
            break;
        }
        }
        else{
            M1 -= 120;
            checkM(M1);
            paid += 120;
            EXP1 = ceil(EXP1 - 0.1 * EXP1);
            checkEXP(EXP1);
            if (paid > budget){
            break;
        }
            if (M1 == 0){
            break;
        }
        }
        if (paid > budget){
            break;
        }
        if (M1 == 0){
            break;
        }
    }
    }
    else if (E2 % 2 == 0){
        while ((E2 % 2) == 0){
            if (M1 == 0){
            break;
        }
        if (HP1 < 200){
            HP1=ceil(HP1+HP1*0.3);
            checkHP(HP1);
            M1 -= 150;
            checkM(M1);
            if (M1 == 0){
            break;
        }
        }
        else{
            HP1=ceil(HP1+HP1*0.1);
            checkHP(HP1);
            M1-=70;
            checkM(M1);
            if (M1 == 0){
            break;
        }
        }
        if (EXP1 < 400){
            EXP1 = ceil(EXP1+EXP1*0.13);
            checkEXP(EXP1);
            M1 -= 200;
            checkM(M1);
            if (M1 == 0){
            break;
        }
        }
        else{
             EXP1 = ceil(EXP1+EXP1*0.13);
             checkEXP(EXP1);
             M1 -= 120;
             checkM(M1);
             if (M1 == 0){
            break;
        }
        }
        if (EXP1 < 300){
             M1 -= 100;
             checkM(M1);
             EXP1 = ceil(EXP1 - 0.1 * EXP1);
             checkEXP(EXP1);
             if (M1 == 0){
            break;
        }
        }
        else{
            M1 -= 120;
            checkM(M1);
            EXP1 = ceil(EXP1 - 0.1 * EXP1);
            checkEXP(EXP1);
            if (M1 == 0){
            break;
        }
        }
        if (M1 == 0){
            break;
        }
        break;
    }
    }
            HP1 = ceil(HP1 - 0.17 * HP1);
            checkHP(HP1);
            EXP1 = ceil(EXP1 + 0.17 * EXP1);
            checkEXP(EXP1);
    float P2;
    a = floor(sqrt(EXP1));
    b = floor (sqrt(EXP1)+1);
    if ((EXP1 - pow(a,2)) > (pow(b,2) - EXP1)){
        S = pow(b,2);
    }
    else{
        S = pow(a,2);
    }
    if (EXP1 >= S){
       P2 = 1;
    }
    else{
        P2 = (((EXP1 * 1.0 / S) + 80) / 123.0);
    }
    int i = 0;
    int Parr[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float P3;
    if (E2 < 10){
        i = E2;
    }
    else{
        i = (((E2 / 10) + (E2 % 10)) % 10);
    }
    P3 = Parr[i];
    P3 = P3/100.0;
    float P;
    P = P1 + P2 + P3;
     P = P/3.0;
    if (P==1)
        EXP1 = ceil(EXP1-EXP1 * 0.25);
    else if (P < 1){
        if (P < 0.5){
            HP1 = ceil(HP1-HP1*0.15);
            checkHP(HP1);
            EXP1 = ceil(EXP1+EXP1*0.15);
            checkEXP(EXP1);
        }
        else if (P >= 0.5){
            HP1 = ceil(HP1-HP1*0.10);
            checkHP(HP1);
            EXP1 = ceil(EXP1+EXP1*0.20);
            checkEXP(EXP1);
        }

    }
    
                                               
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99){
    return -99;
    } 
    int taxi[10][10] = {0};
    int c1 = 0;
    int c2 = 0;
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
           taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j); 
           if (taxi[i][j] > (E3 * 2)){
              c1++;
           }
           else if (taxi[i][j] < (-E3)){
              c2++;
           }
        if (c1 >= 10){
            while(c1 >= 10){
              c1=((c1 % 10)+(c1/10));
        }
    }
        else if (c2 >= 10){
            while(c2 >= 10){
              c2=((c2 % 10)+(c2/10));
        }
    }
        }
    }
    int SW;
    int a = c1;
    int b = c2;
    int c = c1;
    int d = c2;
    int x = c1;
    int y = c2;
    int e = c1;
    int f = c2;
    SW = taxi[c1][c2];
    for (int i = 0; i < 10; i++) {
        int a = c1 + i;
        int b = c2 + i;
        
        if (a >= 0 && a < 10 && b >= 0 && b < 10 && taxi[a][b] > SW) {
            SW = taxi[a][b];
        }
    }
    
    for (int i = 0; i < 10; i++) {
        int c = c1 - i;
        int d = c2 - i;
        
        if (c >= 0 && c < 10 && d >= 0 && d < 10 && taxi[c][d] > SW) {
            SW = taxi[c][d];
        }
    }
    
    for (int i = 0; i < 10; i++) {
        int x = c1 + i;
        int y = c2 - i;
        
        if (x >= 0 && x < 10 && y >= 0 && y < 10 && taxi[x][y] > SW) {
            SW = taxi[x][y];
        }
    }
    
    for (int i = 0; i < 10; i++) {
        int e = c1 - i;
        int f = c2 + i;
        
        if (e >= 0 && e < 10 && f >= 0 && f < 10 && taxi[e][f] > SW) {
            SW = taxi[e][f];
        }
    }
    int result;
    if (abs(SW) >= abs(taxi[c1][c2])){
        result = abs(SW);
        EXP1 = ceil(EXP1 + EXP1 * 12/100.0);
        HP1 = ceil(HP1 + 1.0/10 * HP1);
        EXP2 = ceil(EXP2 + EXP2 * 12/100.0);
        HP2 = ceil(HP2 + 1.0/10 * HP2);
        checkEXP(EXP1);
        checkEXP(EXP2);
        checkHP(HP1);
        checkHP(HP2);
    }
    else if (abs(SW) < abs(taxi[c1][c2])){
        result = taxi[c1][c2];
        EXP1 = ceil(EXP1 - EXP1 * 12/100.0);
        HP1 = ceil(HP1 - 1.0/10 * HP1);
        EXP2 = ceil(EXP2 - EXP2 * 12/100.0);
        HP2 = ceil(HP2 - 1.0/10 * HP2);
        checkEXP(EXP1);
        checkEXP(EXP2);
        checkHP(HP1);
        checkHP(HP2);
    }
      return result;
}




// Task 4
bool containspecialchar(const char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%') {
            return true;
        }
    }
    return false;
}

int checkPassword(const char * s, const char * email) {
    char se[101];
    int i;
    for(i = 0; email[i] != '@'; i++){
        se[i] = email[i];
    }
    se[i] = '\0';
    string S = s;

    if (S.length() < 8){
        return -1;
    }
    if (S.length() > 20){
        return -2;
    }
    if (strstr(s, se) != nullptr){
        return -(300 + (strstr(s, se) - s));
    }
    for (int i = 2; s[i] != '\0'; i++){
        if ((s[i] == s[i-1]) && (s[i-1] == s[i-2])){
            return -(400 + (i-2));
        }
    }
    if (!containspecialchar(s)){
        return -5;
    }
    for (int i = 0; s[i] != '\0'; i++){
        if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%')){
            return i;
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxlength = 0;
    int maxappear = 0;
    int maxposition;
    
    for (int i = 0; i < num_pwds; i++) {
        const char * password = arr_pwds[i];
        int count = 0;
        for (int i = 0; i < num_pwds; i++) {
            if (strcmp(arr_pwds[i], password) == 0) {
                count++;
            }
        }
        if (count > maxappear ) {
            maxappear = count;
            maxlength = strlen(password);\
            maxposition = i;
        }
        else if (count == maxappear) {
            if (strlen(password) > maxlength){
            maxlength = strlen(password);
            maxposition = i;
            }
        } 
    }
    return maxposition;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////