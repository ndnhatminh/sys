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
void check(int & n, int max, int min) {
    if (n > max)  n = max;
    else if (n < min)  n = min;  
}
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    if (E1 >= 0 && E1 <=3) {
        check(EXP1, 600, 0);
        check(EXP2, 600, 0);
        if (E1 == 0)  EXP2 += 29;
        else if (E1 == 1)  EXP2 += 45;
        else if (E1 == 2)  EXP2 += 75;
        else if (E1 == 3)  EXP2 += 29+45+75;
        check(EXP2, 600, 0);

        int D = E1*3 + EXP1*7;
        if (D % 2 == 0)  EXP1 += ceil(D/200.00);
        else  EXP1 = ceil(EXP1 - D/100.00);
        check(EXP1, 600, 0);
        return EXP1 + EXP2;
    }
    else if (E1 >=4 && E1 <= 99) {
        check(EXP1, 600, 0);
        check(EXP2, 600, 0);
        if (E1 >= 4 && E1 <= 19) {
            EXP2 += ceil(E1 / 4.00 + 19.00);          
            check(EXP2, 600, 0);
        } else if (E1 >= 20 && E1 <= 49.00) {
            EXP2 += ceil(E1 / 9.00 + 21);           
            check(EXP2, 600, 0);
        } else if (E1 >= 50 && E1 <= 65) {
            EXP2 += ceil(E1 / 16.00 + 17.00);           
            check(EXP2, 600, 0);
        } else if (E1 >= 66 && E1 <= 79) {
            EXP2 += ceil(E1 / 4.00 + 19.00);         
            check(EXP2, 600, 0);
            if (EXP2 > 200)   
                EXP2 += ceil(E1 / 9.00 + 21.00);               
                check(EXP2, 600, 0);
        } else if (E1 >= 80 && E1 <= 99) {
            EXP2 += ceil(E1 / 4.00 + 19.00);           
            EXP2 += ceil(E1 / 9.00 + 21.00);           
            check(EXP2, 600, 0);
            if (EXP2 > 400) { 
                EXP2 += ceil(E1 / 16.00 + 17.00);
                EXP2 += ceil(0.15*EXP2);                  
                check(EXP2, 600, 0);
            }
        }
        EXP1 -= E1;
        check(EXP1, 600, 0);
        return EXP1 + EXP2;
    } else return -99;
}

// Task 2
int S(int n){
    if ((n-floor(sqrt(n))*floor(sqrt(n))) < (ceil(sqrt(n))*ceil(sqrt(n)) -n)){
        return floor(sqrt(n))*floor(sqrt(n));
    } else {
        return ceil(sqrt(n))*ceil(sqrt(n));
    }
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 >= 0 && E2 <=99){
        check(HP1, 666, 0);
        check(EXP1, 600, 0);
        check(M1, 3000, 0);
        double P1, P2, P3, P;
        if (S(EXP1) <= EXP1)  {
            P1=1;
        }
        else P1= (EXP1/S(EXP1)*1.00 + 80.00)/123.00 ;

        int N=0;
        double M=M1*0.50;
        if (M!=0){
            if (E2 % 2 == 1){
            while(N <= M){
                if (HP1 < 200) {
                    HP1 += ceil(0.30*HP1);
                    M1 -= 150;
                    N += 150;    
                } else {
                    HP1 += ceil(0.10*HP1);
                    M1 -= 70;
                    N += 70;
                } 
                check(HP1, 666, 0);
                check(M1, 3000, 0);
                if (N > M){
                   break;
                }

                if (EXP1 < 400) {
                    M1 -= 200;
                    N += 200;
                } else {
                    M1 -= 120;
                    N += 120;
                } 
                EXP1 += ceil(0.13*EXP1);
                check(M1, 3000, 0);
                check(EXP1, 600, 0);
                if (N > M){
                   break;
                }

                if (EXP1 < 300){
                    M1 -= 100;
                    N += 100;
                } else {
                    M1 -= 120;
                    N += 120;
                } 
                EXP1 = ceil(EXP1*0.90);
                check(M1, 3000, 0);
                check(EXP1, 600, 0);
            }     
        } else {
            while(true){
                if (HP1 < 200) {
                   HP1 += ceil(0.30*HP1);
                   M1 -= 150;   
                } else {
                   HP1 += ceil(0.10*HP1);
                   M1 -= 70;
                } 
                check(HP1, 666, 0);
                if (M1 <= 0){
                   M1=0;
                   break;
                }
                check(M1, 3000, 0);

                if (EXP1 < 400) {
                   M1 -= 200;
                } else {
                   M1 -= 120;
                } 
                EXP1 += ceil(0.13*EXP1);
                check(EXP1, 600, 0);
                if (M1 <= 0){
                   M1=0;
                   break;
                }
                check(M1, 3000, 0);

                if (EXP1 < 300){
                  M1 -= 100;
                } else {
                  M1 -= 120;
                } 
                EXP1 = ceil(EXP1*0.90);
                check(M1, 3000, 0);
                check(EXP1, 600, 0);
                break;
            }
        }
        }
        HP1 = ceil(HP1*0.83);
        EXP1 = ceil(EXP1*1.17);
        check (EXP1,600,0);
        if (S(EXP1) <= EXP1)  P2=1;
        else P2= (EXP1/S(EXP1)*1.00 + 80.00)/123.00 ;

        int arrayP[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int i;
        if (E2 < 10) {
            i = E2;
        } else {
            int sum = E2 / 10 + E2 % 10;
            i = sum % 10;
        }
        P3 = arrayP[i]*0.01;

        if(P1==P2 && P2==P3 && P1==1)  EXP1 = ceil(EXP1*0.75);
        else {
            P=(P1+P2+P3)/3;
            if(P<0.50) {
                HP1= ceil(HP1*0.85);
                EXP1 += ceil(0.15*EXP1);
            } else {
                HP1= ceil(HP1*0.90);
                EXP1 += ceil(0.20*EXP1);           
            }
            check (EXP1, 600, 0);
        }

        return HP1 + EXP1 + M1;
    } else {
        return -99;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 >= 0 && E3 <=99){
        check(EXP1, 600, 0);
        check(EXP2, 600, 0);
        check(HP1, 666, 0);
        check(HP2, 666, 0);
        int a=0;
        int b=0;
        int matrix[10][10];
        for (int i=0; i<10 ; i++){
            for (int j=0; j<10; j++){
                matrix[i][j]=((E3*j)+(i*2))*(i-j);
                if (matrix[i][j] > E3*2)  a += 1;
                if (matrix[i][j] < -E3)  b += 1;
            }
        }
        while (a>9){
            a = a/10 + a%10;
        }
        while (b>9){
            b = b/10 + b%10;
        }
        int TAXI= matrix[a][b];
        int SW= matrix[a][b];
        for (int i=0; i<10 ; i++){
            for (int j=0; j<10; j++){
                if ((i+j == a+b)||(i-j == a-b)){
                    if(SW < matrix[i][j]) SW= matrix[i][j];
                }                          
            }
        }
        int kq;
        if (abs(TAXI)>abs(SW)){
            EXP1 = ceil(EXP1*0.88);
            EXP2 = ceil(EXP2*0.88);
            HP1 = ceil(HP1*0.9);
            HP2 = ceil(HP2*0.9);
            kq = TAXI;
        } else {
            EXP1 += ceil(EXP1*0.12);
            EXP2 += ceil(EXP2*0.12);
            HP1 += ceil(HP1*0.1);
            HP2 += ceil(HP2*0.1);
            kq = SW;      
        } 
        check(EXP1, 600, 0);
        check(EXP2, 600, 0);
        check(HP1, 666, 0);
        check(HP2, 666, 0);
        return kq;
    } else {
        return -99;
    }
}

// Task 4
bool checkkitu(char x){
    if (((x>='0')&&(x<='9')) || ((x>='a')&&(x<='z')) || ((x>='A')&&(x<='Z')) || (x=='@') || (x=='#') || (x=='%') || (x=='$') || (x=='!')){
        return true;
    } else {
        return false;
    }
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    char se[100];
    int a;
    for( a=0; a< strlen(email); a++){
        if ( email[a] == '@')  break;
        se[a] = email[a];
    } 
    se[a]='\0';
    const char *chua_se = strstr(s, se);
    
    if (strlen(s)<8) {
        return -1;
    }
    
    if (strlen(s)>20) {
        return -2;
    }
    
    if (chua_se != NULL){
        int sei = chua_se - s;
        return - (300 + sei);
    }

    for( int i=0; i< strlen(s)-2; i++){
        if (s[i] == s[i+1] && s[i] == s[i+2]){
            int sci = i;
            return - (400 + sci);
        }
    }
    
    int b=0;
    for( int i=0; i< strlen(s); i++){
        if (!((s[i] =='@') || (s[i]=='#') || (s[i]=='%') || (s[i]=='$') || (s[i]=='!'))){   
            b+=1;  
        } 
    }
    if(b==strlen(s)) {
        return -5;
    }
        
    for( int i=0; i< strlen(s); i++){
        if (!checkkitu(s[i])){
            return i;       
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    //TODO: implement task
    int count[100]={0};

    for (int i=0; i<num_pwds; i++){
        for (int j=i; j<num_pwds; j++){
            if(strcmp(arr_pwds[j], arr_pwds[i]) == 0){
                count[i] +=1;
            }
        }
    }
 
    int kq;
    int maxcount = 0;
    int longest = 0;
    for(int k=0; k<num_pwds; k++){
        if ((count[k]>maxcount) || ((count[k]==maxcount) && (strlen(arr_pwds[k])>longest))){
            maxcount = count[k];
            longest = strlen(arr_pwds[k]);
            kq=k;
        }
    }
    return kq;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////