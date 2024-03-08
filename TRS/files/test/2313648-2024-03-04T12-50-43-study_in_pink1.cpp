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
//setup 
    int checkexp(int n) {
    n = (n < 0) ? 0 : (n > 600) ? 600 : n;
    return n;
    }
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
// check the input
     if (e1 <0 || e1 >99) return -99;
     exp1=checkexp(exp1);
     exp2=checkexp(exp2);
     //using expt to calculate the exp that need rounded for more precision
     float exp1t=exp1;
     float exp2t=exp2;
     //informations and cases
     int in4;
     int k;
     if (e1>=0 && e1<4){
        in4=e1+1;
        k=1;
     }
     else {
        if (e1>=4 && e1<=19) in4=1;
        else if (e1>=20 && e1<=49) in4=2;
        else if (e1>=50 && e1<=65) in4=3;
        else if (e1>=66 && e1<=79) in4=4;
        else if (e1>=80 && e1<=99) in4=5;
        k=2;
     }
     //case 1
     //calculate exp2 
     if (k==1){
        switch(in4){
            case 1:
            {
                exp2+=29;
                exp2=checkexp(exp2);
                break;
            }
            case 2:{
                exp2+=45;
                exp2=checkexp(exp2);
                break;
            }
            case 3:{
                exp2+=75;
                exp2=checkexp(exp2);
                break;
            }
            case 4:{
                exp2=exp2+29+45+75;
                exp2=checkexp(exp2);
                break;
            }

        }
        //calculate exp1
        int D;
        D=e1*3+exp1*7;
        if (D%2==0) exp1t=ceil(exp1t-D*1.0000/200);
        else exp1t=ceil(exp1t-D*1.0000/100);
        exp1=exp1t;
        exp1=checkexp(exp1);
        }
        //case 2
        //calculate exp2
        else if (k==2){
            switch(in4){
                case 1:{
                    exp2t=ceil(exp2t+e1*1.0000/4+19);
                    exp2=exp2t;
                    exp2=checkexp(exp2);
                    break;
                    }
                case 2:{
                    exp2t=ceil(exp2t+e1*1.0000/9+21);
                    exp2=exp2t;
                    exp2=checkexp(exp2);
                    break;
                    }
                case 3:{
                    exp2t=ceil(exp2t+e1*1.0000/16+17);
                    exp2=exp2t;
                    exp2=checkexp(exp2);
                    break;
                }
                case 4:{
                    exp2t=ceil(exp2t+e1*1.0000/4+19);
                    exp2=exp2t;
                    exp2=checkexp(exp2);
                    exp2t=exp2;
                 if (exp2>200) exp2t=ceil(exp2t+e1*1.0000/9+21);
                    exp2=exp2t;
                    exp2=checkexp(exp2);
                    break;
                }
                case 5:{
                     exp2t=ceil(exp2t+e1*1.0000/4+19+e1*1.0000/9+21);
                     exp2=exp2t;
                     exp2=checkexp(exp2);
                     exp2t=exp2;
                     
                     if (exp2>400) exp2t=ceil(exp2t+e1*1.0000/16+17);
                     exp2=exp2t;
                     exp2=checkexp(exp2);
                     exp2t=exp2;
                     exp2t=ceil(exp2t*1.15);
                
                     
                     break;
                }    
            }
            //calculate exp1
            exp1=exp1-e1;
            exp2=ceil(exp2t);
        
            

        }
        //check the output
        exp1=checkexp(exp1);
        exp2=checkexp(exp2);
        

        

    
    
    return exp1 + exp2;
}
int checkhp(int n) {
n = (n>666) ? 666 : (n<0) ? 0 :n;
return n;
}
int checkmoney(int n) {
    n = (n>3000) ? 3000 : (n<0) ? 0 :n;
    return n;
}
// Task 2
//calculateP1
float route_1(int EXP1) {
    int S = 0, S1 = 0, S2 = 0, k1 = 0, k2 = 0;
    for (int i = 0; i * i <= EXP1; i++) {
        S1 = i * i;
        S2 = (i + 1) * (i + 1);
        k1 = EXP1 - S1;
        k2 = S2 - EXP1;
        if (k1 > k2) S = S2;
        else S = S1;
    }
    return (EXP1 >= S) ? 1 : (EXP1 / S * 1.0000 + 80) / 123;
}
float route_2(int &HP1, int &EXP1, int &M1, int E2) {
    int M_intitial = M1;
    if (E2 % 2 == 1) {
        while (M1 > M_intitial*0.5) {

            if (HP1 < 200) {
                HP1 = ceil(HP1 * 1.3);
                M1 -= 150;
                HP1=checkhp(HP1);
                if(M1<M_intitial*0.5) break;
            } else {
                HP1 = ceil(HP1 * 1.1);
                M1 -= 70;
                HP1=checkhp(HP1);
                if(M1<M_intitial*0.5) break;
            }
            if (EXP1 < 400) {
                M1 -= 200;
                EXP1 = ceil(EXP1 * 1.13);
                EXP1=checkexp(EXP1);
                HP1=checkhp(HP1);
                if(M1<M_intitial*0.5) break;
            } else {
                EXP1 = ceil(EXP1 * 1.13);
                M1 -= 120;
                EXP1=checkexp(EXP1);
                HP1=checkhp(HP1);
                if(M1<M_intitial*0.5) break;
            }
            if (EXP1 < 300) {
                EXP1 = ceil(EXP1 * 0.9);
                M1 -= 100;
                EXP1=checkexp(EXP1);
                HP1=checkhp(HP1);
                if(M1<M_intitial*0.5) break;
            } else {
                EXP1 = ceil(EXP1 * 0.9);
                M1-=120;
                EXP1=checkexp(EXP1);
                HP1=checkhp(HP1);
                if(M1<M_intitial*0.5) break;
            }

        }

            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            EXP1=checkexp(EXP1);
            HP1=checkhp(HP1);
    } else {
        while(M1>0) {
        if (HP1 < 200) {
            HP1 = ceil(HP1 * 1.3);
            M1 -= 150;
            EXP1=checkexp(EXP1);
            HP1=checkhp(HP1);
            M1=checkmoney(M1);
            if (M1==0) break;
        } else {
            HP1 = ceil(HP1 * 1.1);
            M1 -= 70;
            EXP1=checkexp(EXP1);
            HP1=checkhp(HP1);
            M1=checkmoney(M1);
            if (M1==0) break;
        }
        if (EXP1 < 400) {
            M1 -= 200;
            EXP1 = ceil(EXP1 * 1.13);
            EXP1=checkexp(EXP1);
            HP1=checkhp(HP1);
            M1=checkmoney(M1);
            if (M1==0) break;
        
        } else {
            M1 -= 120;
            EXP1 = ceil(EXP1 * 1.13);
            EXP1=checkexp(EXP1);
            HP1=checkhp(HP1);
            M1=checkmoney(M1);
            if (M1==0) break;
        }
        if (EXP1 < 300) {
            M1 -= 100;
            EXP1 = ceil(EXP1 * 0.9);
            EXP1=checkexp(EXP1);
            HP1=checkhp(HP1);
            M1=checkmoney(M1);
            if (M1==0) break;
        } else {
            M1 -= 120;
            EXP1 = ceil(EXP1 * 0.9);
            EXP1=checkexp(EXP1);
            HP1=checkhp(HP1);
            M1=checkmoney(M1);
            if (M1==0) break;
        }
        HP1 = ceil(HP1 * 0.83);
        EXP1 = ceil(EXP1 * 1.17);
        EXP1=checkexp(EXP1);
        HP1=checkhp(HP1);

    }
    }
    return route_1(EXP1);
}

float route_3(int E2) {
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float P3;
    int first_digit = E2 / 10;
    int second_digit = E2 % 10;
    int sum;
    if (first_digit+second_digit<10)
     sum = first_digit + second_digit;
    else sum=(first_digit+second_digit) %10;
    if (E2 >= 0 && E2 <= 9) P3 = P[E2];
    if (E2 >= 10 && E2 <= 99) P3 = P[sum];
    return P3 / 100;
}



int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    //check the input
   if (E2 < 0 || E2 > 99) return -99;
    EXP1 = checkexp(EXP1);
    HP1 = checkhp(HP1);
    M1 = checkmoney(M1);
    float P1 = route_1(EXP1);
    float P2 = route_2(HP1, EXP1, M1, E2);
    float P3 = route_3(E2);
    float P;
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = ceil(EXP1 * 0.75);
    } else {
        P = (P1 + P2 + P3) / 3;
    }
    if (P < 0.5) {
        HP1 = ceil(HP1 * 0.85);
        EXP1 = ceil(EXP1 * 1.15);
       EXP1=checkexp(EXP1);
        HP1=checkhp(HP1);
    } else {
        HP1 = ceil(HP1 * 0.9);
        EXP1 = ceil(EXP1 * 1.2);
        EXP1=checkexp(EXP1);
        HP1=checkhp(HP1);
    }
    return HP1 + EXP1 + M1;

}

// Task 3
//find position 
int find_position(int a) {
int b=a / 10; //first digit
int c=a % 10; //second digit
int d;
int e;
if (b+c>=10) {
    d=(b+c) /10; //new first digit
    e=(b+c) %10; //new second digit
     return d+e;
     }
     return b+c;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    int a[10][10];
    int score=0;
    int SW_grade=0;
    int i=0;
    int j=0;
    int c=0;
    int d=0;
    for (int m=0;m<10;m++){
        for (int n=0;n<10;n++){
        a[m][n]=((E3*n)+(m*2))*(m-n);
        if (a[m][n]>=E3*2) i++;
        if (a[m][n]<E3*(-1)) j++;
        }
        
    }
    if (i>9 && i <100) i=find_position(i);
    if (j>9 && j <100) j=find_position(j);
    int X=a[i][j];
    //dianogal matrix
    int b[10][10]={0};
   //calculate score 
    while (i+c<10 || j-d>=0){
        if (i+c==10 || j-d==0){ 
            break;
        }
    b[i+c][j-d]=a[i+c][j-d];
    c++;
    d++;
    }
    c=0;d=0;
    while (i-c>=0 || j-d>=0){
        if (i-c==0 || j-d==0){ 
            break;
        }
    b[i-c][j-d]=a[i-c][j-d];
    c++;
    d++;
    }
    c=0;d=0;
    while (i+c<10 || j+d<10){
        if (i+c==10 || j+d==10){
             break;
        }
    b[i+c][j+d]=a[i+c][j+d];
    c++;
    d++;
     }
     c=0;d=0;
     while (i-c>=0 || j+d<10){
        if (i-c==0 || j+d==10){
             break; 
             }
     b[i-c][j+d]=a[i-c][j+d];
     c++;
     d++;
     }
     for (int m=0;m<10;m++){
        for (int n=0;n<10;n++){
            score=b[m][n];
            if(score>SW_grade) SW_grade=score;
        }
     }
    if (abs(X)>SW_grade) {
        EXP1=EXP1*0.88;
        HP1 = HP1 * 0.9; 
        EXP2 = EXP2 * 0.88; 
        HP2 = HP2 * 0.9; 
        HP1=checkhp(HP1);
        HP2=checkhp(HP2);
        EXP1=checkexp(EXP1);
        EXP2=checkexp(EXP2);
       return X;
    } 
    else { 
        EXP1=EXP1*1.12;
        HP1 = HP1 * 1.1; 
        EXP2 = EXP2 * 1.12; 
        HP2 = HP2 * 1.1; 
        HP1=checkhp(HP1);
        HP2=checkhp(HP2);
        EXP1=checkexp(EXP1);
        EXP2=checkexp(EXP2);
       return SW_grade;
    }
    return -1;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    //find se part in the email
    string se;
    for (int i=0;email[i] != '\0' && email[i] != '@';i++) {
        se+=email[i];
    }
    int slength=0;
    for (int i=0;s[i]!='\0';i++) {
        slength++;
    }
    //checking if password valid
    if (slength <8) return -1 ;//s have less than minium char
   else if(slength > 20) return -2; //s have more than maximun char
   string password(s);
    if(password.find(se) != string :: npos) return -(300 + password.find(se));
   //s contains se
    for (int i=0;i<slength -2;i++) {
        if (s[i]== s[i+1] && s[i]==s[i+2]) return -(400 + i); //s contains more than 2 consecutive and identical char
    }
    // Special character check in the password
    string specialchar = "@#%$!";
    bool found = false;
    for (int i = 0; i < slength ; i++) {

        for (int j = 0; j < 6; j++) {
            if (s[i] == specialchar[j]&& s[i]!='\0'&& specialchar[j] !='\0') {
                found = true;

                break;
            }
        }
        }
        if (!found) return -5; // Password does not have special character
       return -10; //Password is valid

}




// Task 5
const int max_num=30;
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string passwords[max_num];
    int counts[max_num] = {0};
    int lengths[max_num] = {0};
    int maxcount = 0, maxlength = 0;
    int position = -1;

    for (int i = 0; i < num_pwds; i++) {
        const string pwd = arr_pwds[i];
        bool isNewPassword = true;

        for (int j = 0; j < max_num; j++) {
            if (passwords[j] == pwd) {
                isNewPassword = false;
                counts[j]++;
                lengths[j] = max(lengths[j], int(pwd.length()));

                if (counts[j] > maxcount || (counts[j] == maxcount && lengths[j] > maxlength)) {
                    maxcount = counts[j];
                    maxlength = lengths[j];
                    position = j;
                }

                break;
            }
        }

        if (isNewPassword) {
            for (int j = 0; j < max_num; j++) {
                // Check if the password slot is not occupied
                if (passwords[j].length() == 0) {
                    passwords[j] = pwd;
                    counts[j]++;
                    lengths[j] = max(lengths[j], int(pwd.length()));

                    if (counts[j] > maxcount || (counts[j] == maxcount && lengths[j] > maxlength)) {
                        maxcount = counts[j];
                        maxlength = lengths[j];
                        position = j;
                    }

                    break;
                }
            }
        }
    }

    if (maxcount > 0) {
        return position;
    } else {
        return -1;
    }
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////