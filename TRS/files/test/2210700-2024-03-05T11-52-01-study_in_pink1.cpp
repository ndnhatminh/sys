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

int rounding(double a) {
       return int(a+0.9999);
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) { return -99;}
    exp1 = (exp1 > 600)? 600: exp1;
    exp1 = (exp1 < 0)? 0: exp1;

    exp2 = (exp2 > 600)? 600: exp2;
    exp2 = (exp2 < 0)? 0: exp2;
    if (e1 >= 0 && e1 <= 3) {
        switch(e1){
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
               exp2 += 149;
               break;

        }

        int D = e1*3+exp1*7;
        exp1 = (D%2 == 0)? rounding(exp1 + D/200.0): rounding(exp1 - D/100.0);
        
    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 <= 19) {
            exp2 = rounding(exp2 + e1/4.0 + 19);
        }
        else if (e1 <= 49) {
            exp2 = rounding(exp2 + e1/9.0 + 21);
        }
        else if (e1 <= 65) {
            exp2 = rounding(exp2 + e1/16.0 + 17);
        }
        else if (e1 <= 79) {
            exp2 = rounding(exp2 + e1/4.0 + 19);
            exp2 = (exp2 > 200)? rounding(exp2 + e1/9.0 + 21): exp2;
        }
        else {
            exp2 = rounding(exp2 + e1/4.0 + 19);
            exp2 = rounding(exp2 + e1/9.0 + 21);
            if (exp2 > 400) {
                exp2 = rounding(exp2 + e1/16.0 + 17);
                exp2 = rounding(1.15*exp2);
            }
    
        }
        exp1 -= e1;
    }
    else {
        return -99;
    }
    exp1 = (exp1 > 600)? 600: exp1;
    exp1 = (exp1 < 0)? 0: exp1;

    exp2 = (exp2 > 600)? 600: exp2;
    exp2 = (exp2 < 0)? 0: exp2;
    
    return exp1 + exp2;
}

double Pro(int exp1) {
    double P1;
    int i = sqrt(exp1);
    int S = (abs(i*i - exp1) < abs((i+1)*(i+1) - exp1))? i*i : (i+1)*(i+1);
    P1 = (exp1 >= S)? 100 : 100*((exp1/double(S) + 80)/123.0);
    return P1;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) { return -99;}
    EXP1 = (EXP1 > 600)? 600: EXP1;
    EXP1 = (EXP1 < 0)? 0: EXP1;

    HP1 = (HP1 > 666)? 666 : HP1;
    HP1 = (HP1 < 0)? 0 : HP1;

    M1 = (M1 > 3000)? 3000 : M1;
    M1 = (M1 < 0)? 0 : M1;

    double P1 = Pro(EXP1);
    
    if (E2%2 == 1) {
        int Limit = M1;
        int T = 0;

        if (M1 > 0) {
            while (T <= 0.5*Limit) {
        
                if (HP1 < 200) {
                HP1 = rounding(1.3*HP1);
                M1 -= 150;
                T += 150;
                }
                else {
                HP1 = rounding(1.1*HP1);
                M1 -= 70;
                T += 70;
                }
                HP1 = (HP1 > 666)? 666 : HP1;
                HP1 = (HP1 < 0)? 0 : HP1;

                M1 = (M1 > 3000)? 3000 : M1;
                M1 = (M1 < 0)? 0 : M1;

                if (T <= 0.5*Limit) {
                    if (EXP1 < 400) {
                        M1 -= 200;
                        T += 200;
                    }
                    else {
                        M1 -= 120;
                        T += 120;
                    }
                    EXP1 = rounding(1.13*EXP1);

                    EXP1 = (EXP1 > 600)? 600: EXP1;
                    EXP1 = (EXP1 < 0)? 0: EXP1;

                    M1 = (M1 > 3000)? 3000 : M1;
                    M1 = (M1 < 0)? 0 : M1;
                }

                if (T <= 0.5*Limit) {
                    if (EXP1 <300) {
                        M1 -= 100;
                        T += 100;
                    }
                    else {
                        M1 -= 120;
                        T += 120;
                    }
                    EXP1 = rounding(0.9*EXP1);
                    
                    EXP1 = (EXP1 > 600)? 600: EXP1;
                    EXP1 = (EXP1 < 0)? 0: EXP1;

                    M1 = (M1 > 3000)? 3000 : M1;
                    M1 = (M1 < 0)? 0 : M1;

                }
            }
        }
        HP1 = rounding(HP1*0.83);
        EXP1 = rounding(EXP1*1.17);
        EXP1 = (EXP1 > 600)? 600: EXP1;
        EXP1 = (EXP1 < 0)? 0: EXP1;

        HP1 = (HP1 > 666)? 666 : HP1;
        HP1 = (HP1 < 0)? 0 : HP1;
    }
    else {
        if (M1 > 0) {
            if (HP1 < 200) {
                HP1 = rounding(1.3*HP1);
                M1 -= 150;
            }
            else {
                HP1 = rounding(1.1*HP1);
                M1 -= 70;
            }
        }
        M1 = (M1 > 0)? M1 : 0;
        M1 = (M1 >3000)? 3000 : M1;

        HP1 = (HP1 > 666)? 666 : HP1;
        HP1 = (HP1 < 0)? 0 : HP1;

        if (M1 > 0) {
            if (EXP1 < 400) {
                M1 -= 200;
            }
            else {
                M1 -= 120;
            }
            EXP1 = rounding(1.13*EXP1);
            EXP1 = (EXP1 > 600)? 600: EXP1;
            EXP1 = (EXP1 < 0)? 0: EXP1;
        }
        M1 = (M1 > 0)? M1 : 0;
        M1 = (M1 >3000)? 3000 : M1;

        if (M1 > 0) {
            if (EXP1 <300) {
                M1 -= 100;
            }
            else {
                M1 -= 120;
            }
            EXP1 = rounding(0.9*EXP1);
            EXP1 = (EXP1 > 600)? 600: EXP1;
            EXP1 = (EXP1 < 0)? 0: EXP1;
        }
        HP1 = rounding(HP1*0.83);
        EXP1 = rounding(EXP1*1.17);

        EXP1 = (EXP1 > 600)? 600: EXP1;
        EXP1 = (EXP1 < 0)? 0: EXP1;

        HP1 = (HP1 > 666)? 666 : HP1;
        HP1 = (HP1 < 0)? 0 : HP1;
        M1 = (M1 > 0)? M1 : 0;
        M1 = (M1 >3000)? 3000 : M1;

    }
    double P2 = Pro(EXP1);
    //Con duong 3

    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int P3;
    if (E2 < 10) {
        P3 = P[E2];
    }
    else {
        int i = (E2/10 + E2%10)%10;
        P3 = P[i];
    }

    if ((P1 == 100) && (P2 == 100) && (P3 == 100)) {
        EXP1 = rounding(EXP1*0.75);
    }
    else {
        double p = (P1 + P2 + P3)/3.0;
        if (p < 50) {
            HP1 = rounding(HP1*0.85);
            EXP1 = rounding(1.15*EXP1);
        }
        else {
            HP1 = rounding(HP1*0.9);
            EXP1 = rounding(EXP1*1.2);
        }
    }
    EXP1 = (EXP1 > 600)? 600: EXP1;
    EXP1 = (EXP1 < 0)? 0: EXP1;

    HP1 = (HP1 > 666)? 666 : HP1;
    HP1 = (HP1 < 0)? 0 : HP1;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 <0 || E3 >99) {
        return -99;
    }

    HP1 = (HP1 > 666)? 666 : HP1;
    HP1 = (HP1 < 0)? 0 : HP1;

    EXP1 = (EXP1 > 600)? 600: EXP1;
    EXP1 = (EXP1 < 0)? 0: EXP1;

    HP2 = (HP2 > 666)? 666 : HP2;
    HP2 = (HP2 < 0)? 0 : HP2;

    EXP2 = (EXP2 > 600)? 600: EXP2;
    EXP2 = (EXP2 < 0)? 0: EXP2;

    int MT[10][10];
    int MTD[10][10];
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            MT[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            MTD[i][j] = MT[i][j];
            if (i<j) {
                for (int l=0; l<(10-j); l++) {
                    if (MTD[i][j] < MT[l][j-i+l]) {
                        MTD[i][j] = MT[l][j-i+l];
                    }

                }
            }
            else {
                for (int k=0; k<(10-i+j); k++) {
                    if (MTD[i][j] < MT[i-j+k][k]) {
                        MTD[i][j] = MT[i-j+k][k];
                    }
                }
            }
        }
    }

    

    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (i<9-j) {
                for (int l=0; l<=j+i; l++) {
                    if (MTD[i][j] < MT[l][j+i-l]) {
                        MTD[i][j] = MT[l][j+i-l];
                    }

                }
            }
            else {
                for (int k=0; k<=(18-i-j); k++) {
                    if (MTD[i][j] < MT[i+j+k-9][9-k]) {
                        MTD[i][j] = MT[i+j+k-9][9-k];
                    }
                }
            }
        }
    }

    int i=0;
    int j=0;
    for (int l=0; l<10; l++) {
        for (int k=0; k<10; k++) {
            if (MT[l][k] > E3*2) {
                i++;
            }
            else if (MT[l][k] < -E3) {
                j++;
            }
        }
    }

    while(i>=10) {
        i = i/10 + i%10;
    }
    while(j>=10) {
        j = j/10 + j%10;
    }

    if (MTD[i][j] >= abs(MT[i][j])) {

        EXP1 = rounding(EXP1*1.12);
        HP1 = rounding(HP1*1.1);

        EXP2 = rounding(EXP2*1.12);
        HP2 = rounding(HP2*1.1);

        HP1 = (HP1 > 666)? 666 : HP1;
        HP1 = (HP1 < 0)? 0 : HP1;

        EXP1 = (EXP1 > 600)? 600: EXP1;
        EXP1 = (EXP1 < 0)? 0: EXP1;

        HP2 = (HP2 > 666)? 666 : HP2;
        HP2 = (HP2 < 0)? 0 : HP2;

        EXP2 = (EXP2 > 600)? 600: EXP2;
        EXP2 = (EXP2 < 0)? 0: EXP2;
        
        return MTD[i][j];
    }
    else {
       EXP1 = rounding(EXP1*0.88);
       HP1 = rounding(HP1*0.9);

       EXP2 = rounding(EXP2*0.88);
       HP2 = rounding(HP2*0.9);

       HP1 = (HP1 > 666)? 666 : HP1;
       HP1 = (HP1 < 0)? 0 : HP1;

       EXP1 = (EXP1 > 600)? 600: EXP1;
       EXP1 = (EXP1 < 0)? 0: EXP1;

       HP2 = (HP2 > 666)? 666 : HP2;
       HP2 = (HP2 < 0)? 0 : HP2;

       EXP2 = (EXP2 > 600)? 600: EXP2;
       EXP2 = (EXP2 < 0)? 0: EXP2;
       return MT[i][j]; 
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    char se[200];
    for (int i=0; i<strlen(email); i++) {
        if (email[i] != '@') {
            se[i] =  email[i];
        }
        else {
            se[i] = '\0';
            break;
        }
    }

    if (strlen(s) < 8) {
        return -1;
    }
    else if (strlen(s) > 20) {
        return -2;
    }

    for (int i=0; i<strlen(s); i++) {
        if (s[i] == se[0]) {
            bool c= true;
            for (int j=0; j<strlen(se); j++) {
                if (s[i+j] != se[j]) {
                    c = false;
                }
            }
            if (c) {
                return -(300+i);
            }

        }
    }

    for (int i=0; i<strlen(s)-1; i++) {
        if (s[i]==s[i+1]) {
            if (s[i+2] != '\0') {
                if (s[i+1] == s[i+2]) {
                    return -(400+i);
                }
            }

        }
    }

    bool u=false;
    for (int i=0; i<strlen(s); i++) {
        if (s[i]=='@' || s[i]=='!' || s[i]=='$' || s[i]=='#' || s[i]=='%') {
            u = true;
        }
    }
    if (!u) {
        return -5;
    }

    for (int i=0; i<strlen(s); i++) {
        bool t = true;
        if ((s[i]<=57 && s[i]>=48) || (s[i]==33) || (s[i]>=35 && s[i]<=37) || (s[i]>=64 && s[i]<=90) || (s[i]>=97 && s[i]<=122)) {
            t = false;
        } 
        if (t) {
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int arr[num_pwds];
    for (int i=0; i<num_pwds; i++) {
        int count = 0;
        for (int j=0; j<num_pwds; j++) {
            if (arr_pwds[i]==arr_pwds[j]) {
                count++;
            }
        }
        arr[i] = count;
    }

    int max=0;
    for (int i=0; i<num_pwds; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int l=0;
    int vt;
    for (int i=0; i<num_pwds; i++) {
        if (arr[i]==max) {
            if (strlen(arr_pwds[i])>l) {
                l = strlen(arr_pwds[i]);
                vt = i;
            }
        }
    }
    return vt;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////