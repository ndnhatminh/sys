#include "study_in_pink1.h"
#include <math.h>
#include <iostream>
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


int checkHp(int &hp) {
    if (hp < 0) 
       return -1;
    if (hp > 666) 
        return 666;
    else 
        return hp;
}

int checkMon(int &m) {
    if (m < 0) 
       return -1;
    if (m > 3000) 
        return 3000;
    else 
        return m;
}

int checkExp(int &exp) {
    if (exp < 0) 
       return -1;
    if (exp > 600) 
        return 600;
    else 
        return exp;
}

bool checkE (int e) {
    if(e < 0 || e > 99) 
        return true;
    else 
        return false;
}
//funtion RoundUp
int RoundUp(double a) {
    if (a != (int)a) {
        a += 1;
    }
    return a;
} 

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (checkE(e1)) {
        return -99;
    }
    if (e1 < 4) {

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
            exp2 = exp2 + 29 + 45 + 75;
            break;
            default:
            break;
        }
        int d = e1*3 + exp1*7;
        if (d % 2 == 0) {
            exp1 = RoundUp(exp1 + d*1.00/200);
        } else {
            exp1 = RoundUp(exp1 - d*1.00/100);
        }
    
    }
   else {        
    if (e1 >= 4 && e1 < 20) {
        exp2 = RoundUp(exp2 +  ((e1*1.00/4) + 19));
    } 
    else if (e1 >= 20 && e1 < 50) {
        exp2 =  RoundUp(exp2 + (e1*1.00/9 + 21));
    } 
    else if (e1 >= 50 && e1 < 66) {
        exp2 = RoundUp(exp2 + (e1*1.00/16 + 17));
    } 
    else if (e1 >= 66 && e1 < 80) {
        exp2 = RoundUp(exp2 + (e1*1.00/4 + 19));
        if (exp2 > 200) {
            exp2 = RoundUp(exp2 + (e1*1.00/9 + 21));
        }
    } else {
        exp2 = RoundUp(exp2 + (e1*1.00/4 + 19));
        exp2 = RoundUp(exp2 + (e1*1.00/9 + 21));
        if (exp2 > 400) {
            exp2 = RoundUp(exp2 + (e1*1.00/16 + 17));
            exp2 = RoundUp(exp2 + exp2*0.15);
        }
    }   
        exp1 -= e1;
        }
        if (checkExp(exp1) == -1) 
        exp1 = 0;
        else  exp1 = checkExp(exp1);
        if (checkExp(exp2) == -1) 
        exp2 = 0;
        else 
        exp2 = checkExp(exp2);
    return exp1 + exp2;
    
}

int PerfectSquare(int exp1) {
    int small, big;
    for (int i = 2; i < sqrt(exp1); i++) {
        if (i*i <= exp1) {
            small = i;
        }
    }
    big = small + 1;
    if((exp1 - small*small) <= (big*big - exp1)){
        return 1;
    }
    else 
        return RoundUp((exp1*1.00/big + 80.00)/123);
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
       if (checkE(E2)) {
        return -99;
    }

    double p1,p2,p3;
    //TH1
    p1 = PerfectSquare(EXP1);
    //TH2
    int mon = M1/2;
    do {
    if(HP1 < 200) {
        HP1 = RoundUp(HP1 + 0.30*HP1);
        M1 -= 150;
    }
    else {
        HP1= RoundUp(HP1 + 0.10*HP1);
        M1 -= 70;
    }
    HP1 = checkHp(HP1);
    
    if (M1 < mon)
    {
        break;
    }
    
    if(checkMon(M1) == -1)
    {
        M1 = 0;
        break;
    } else M1 = checkMon(M1);

    if(EXP1 < 400) {
        M1 -= 200;
    } else {
        M1 -= 120;
    }
    EXP1 = RoundUp(EXP1 + EXP1*0.13);
    EXP1 = checkExp(EXP1);

    if (M1 < mon)
    {
        break;
    }
    if(checkMon(M1) == -1)
    {
        M1 = 0;
        break;
    } else M1 = checkMon(M1);

    if(EXP1 < 300) {
        M1 -= 100;
    } else {
        M1 -= 120;
    }
    EXP1 = RoundUp(EXP1 - EXP1*0.10);
    if(checkExp(EXP1) == -1)
    {
        EXP1 = 0;
    } else EXP1 = checkExp(EXP1);

    if (M1 < mon)
    {
        break;
    }
    if(checkMon(M1) == -1)
    {
        M1 = 0;
        break;
    } else M1 = checkMon(M1);

    if (M1 < mon)
    {
        break;
    }
    
} while (E2 % 2 != 0);

    HP1 = RoundUp(HP1 - HP1*0.17);
    EXP1 = RoundUp(EXP1 + EXP1*0.17);
    if(checkHp(HP1) == -1)
    {
        HP1 = 0;
    }    HP1 = checkHp(HP1);
    if(checkExp(EXP1) == -1)
    {
        EXP1 = 0;
    }    EXP1 = checkExp(EXP1);

    p2 = PerfectSquare(EXP1);
    

    //TH3
    int p[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 >= 0 && E2 < 10) {
        p3 = p[E2]*0.01;
    }
    else
        p3 = p[E2/10 + E2%10]*0.01;

    //Solution
    if (p1 == 1 && p2 == 1 && p3 == 1)
    {
        EXP1 = RoundUp(EXP1 - 0.25*EXP1);
    } else if ((p1+p2+p3)*1.00/3 < 0.50)
    {
        HP1 = RoundUp(HP1 - 0.15*HP1);
        EXP1 = RoundUp(EXP1 + 0.15*EXP1);
    } else {
        HP1 = RoundUp(HP1 - 0.10*HP1);
        EXP1 = RoundUp(EXP1 + 0.20*EXP1);
    }

    if(checkHp(HP1) == -1)
    {
        M1 = 0;

    } else HP1 = checkHp(HP1);

    if(checkExp(EXP1) == -1)
    {
        EXP1 = 0;

    } else EXP1 = checkExp(EXP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
       if (checkE(E3)) {
        return -99;
    }
    int m1 = 0;
    int m2 = 0;
    int SW;
    //Taxi matrix
    int Taxi[10][10];
    for (int i = 0; i <10; i++){
        for (int j = 0; j <10; j++){
           Taxi[i][j] = ((E3*(j)) + (i*2))*(i-j);
           if( Taxi[i][j] > E3*2) {
                m1++;
                }
            if (Taxi[i][j] < -E3) {
                m2++;
            } 
    }
    }

    

    //meeting point
   
    while (m1 > 9) {
        m1 = ((m1)/10 + m1%10);
    }
    while (m2 > 9) {
        m2 = ((m2)/10 + m2%10);
        }

    //ComparePoint
    SW = abs(Taxi[m1][m2]);
    for (int i = 0; i < 10; i++){
        //for (int j = 0; j < 10; j++){
            
                if((Taxi[m1][m2] < Taxi[m1 - i][m2 - i]) && m1 - i  >= 0 && m2 - i >= 0) {
                    SW = Taxi[m1 - i][m2 - i];
                    //continue;
                }
            
                if((Taxi[m1][m2] < Taxi[m1 + i][m2 + i]) && i + m1 <10 && i + m2 <10) {
                    SW = Taxi[m1 + i][m2 + i];
                    //continue;
                }
             
                if((Taxi[m1][m2] < Taxi[m1 + i][m2 - i]) && i + m1 <10 && m2 - i >=0) {
                    SW = Taxi[m1 + i][m2 - i];
                    //continue;
                }
                
                    if((Taxi[m1][m2] < Taxi[m1 - i][m2 + i]) && m1 - i >=0 && i + m2 <10) {
                    SW = Taxi[m1 - i][m2 + i];
                    //continue;
                }
            }
    SW = abs(SW);

    if (abs(Taxi[m1][m2]) > SW) {
        EXP1 = RoundUp(EXP1 - 0.12*EXP1);
        EXP2 = RoundUp(EXP2 - 0.12*EXP2);
        if(checkExp(EXP1) == -1){
        EXP1 = 0;
    } else EXP1 = checkExp(EXP1);
    
    if(checkExp(EXP2) == -1) {
        EXP2 = 0;
    } else EXP2 = checkExp(EXP2);
        
        HP1 = RoundUp(HP1 - 0.10*HP1);
        HP2 = RoundUp(HP2 - 0.10*HP2);
        if(checkExp(HP1) == -1){
        HP1 = 0;
    } else HP1 = checkHp(HP1);
        if(checkExp(HP2) == -1){
        HP2 = 0;
    } else HP2 = checkHp(HP2);

        return Taxi[m1][m2];
    } else {
        EXP1 = RoundUp(EXP1 + 0.12*EXP1);
        EXP2 = RoundUp(EXP2 + 0.12*EXP2);
        HP1 = RoundUp(HP1 + 0.10*HP1);
        HP2 = RoundUp(HP2 + 0.10*HP2);
        EXP1 = checkExp(EXP1);
        EXP2 = checkExp(EXP2);
        HP1 = checkHp(HP1);
        HP2 = checkHp(HP2);
        return SW;
    }
}

//Funtion size of string
int SizeString(const char * s) {
    int size = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        size += 1;
    }
    return size;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se;
    int S = SizeString(s);
    int Email = SizeString(email);

    for (int i = 0; i < Email; i++){
        if (email[i] == '@') {
            break;
        }
        se[i] = email[i];
    }
    if (S < 8) {
        return -1;
    } if (S > 20) {
        return -2;
    }
    //check if email in password
    string s1;
    for (int i = 0; i < SizeString(s); i++){
        s1[i] = s[i];
    }
    if (se[0] == '\0') {
       return -300;
    }
    for (int i = 0; i < SizeString(s); i++){
        //s1[i] = s[i];
        if (s1[i] == se[0]) {
            int count = 0;
            for (int j = 0; j < se.size(); j++) {
                if (s1[j + i] == se[j])
                    count += 1;
            }
            if (count == se.size()) 
                return -(300 + i);
        }
    }  
    
    for (int i = 0; i < S; i++)
    {
        if (s[i] == s[i+1] && s[i+1] == s[i+2]) {
            return -(400 + i);
        }
    }
    for (int i = 0; i < S; i++)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%' || s[i] == '!') {
            break;
        } if (i == (S - 1)) {
            return -5;
        }

    }

    for (int i = 0; i < S; i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%' || s[i] == '!') {
            continue;
        }
        else if (s[i] < 48 && s[i] > 57) {
            if(s[i] < 64 && s[i] > 90) {
                if(s[i] < 97 && s[i] > 122) {
                    return i;
                }
            }
        }
        
    }

    return -10;
}


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string check[num_pwds];
    int count[num_pwds];
    int size[num_pwds];

    for (int i = 0; i < num_pwds; i++) {
        count[i] = 0;
        size[i] = 0;
    }

    for (int i = 0; i < num_pwds; i++) {
        check[i] = arr_pwds[i];
        for (int j = 1; j < num_pwds; j++){
        if (arr_pwds[i] == arr_pwds[i + j]) {
           // check[i] = arr_pwds[i];
            count[i] += 1;
            size[i] = SizeString(arr_pwds[i]);
        }
    }}
    int m = 0;
    int checkCount = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (checkCount < count[i]) { 
            checkCount = count[i];
            m = i; 
            }
            if (checkCount == count[i]) {
                if(size[m] < size[i]){
            m = i;
            }
        }
    }
    return m;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////