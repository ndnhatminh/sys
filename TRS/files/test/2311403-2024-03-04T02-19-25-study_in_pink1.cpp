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
        // char & email,
        // char & s
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
void modE(int & a){
    if (a > 600){
        a = 600;
    }
    else if (a < 0){
        a = 0;
    }
};
void modH(int & b){
    if (b > 666){
        b = 666;
    }
    else if (b < 0){
        b = 0;
    }
}
void modM(int & c){
    if (c > 3000){
        c = 3000;
    }
    else if (c < 0){
        c = 0;
    }
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    int D;
    // TODO: Complete this function
        if (e1 < 0 || e1 > 99){
        return -999;
    }
    // CASE 1
    if (e1 <= 3) {
        switch (e1)
        {
        case 1:
            exp2 += 45;
            D = e1 * 3.0 + exp1 * 7.0;
            if (D % 2 == 0){
                exp1 = ceil((float) exp1 + ((D * 1.0) / 200));
                modE(exp1);
            }
            else {
                exp1 = ceil((float) exp1 - ((D * 1.0) / 100));
                modE(exp1);
            }
                break;
        case 2:
            exp2 += 75;
            D = e1 * 3.0 + exp1 * 7.0;
            if (D % 2 == 0){
                exp1 = ceil((float) exp1 + D * 1.0 / 200);
                modE(exp1);
            }
            else {
                exp1 = ceil((float) exp1 - D * 1.0 / 100);
                modE(exp1);
            }
            break;
        case 3:
            exp2 += 149;
            D = e1 * 3.0 + exp1 * 7.0;
            if (D % 2 == 0){
                exp1 = ceil((float) exp1 + D * 1.0 / 200);
                modE(exp1);
            }
            else {
                exp1 = ceil((float) exp1 - D * 1.0 / 100);
                modE(exp1);
            }
            break;
        default:
            exp2 += 29;
            D = e1 * 3.0 + exp1 * 7.0;
            if (D % 2 != 0){
                exp1 = ceil((float) exp1 + D * 1.0 / 200);
                modE(exp1);
            }
            else {
                exp1 = ceil((float) exp1 - D * 1.0 / 100);
                modE(exp1);
            }
            break;
        }
    }
    // CASE 2
    else if (e1 > 3) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 = ceil((float) exp2 + ((e1/4.0) + 19.0));
            modE(exp2);
            exp1 -= e1;
            modE(exp1);
        }
        else if (e1 >= 20 && e1 <= 49){
            exp2 = ceil((float) exp2 + ((e1/9.0) + 21.0));
            modE(exp2);
            exp1 -= e1;
            modE(exp1);
        }
        else if (e1 >= 50 && e1 <= 65){
            exp2 = ceil((float) exp2 + ((e1/16.0) + 17.0));
            modE(exp2);
            exp1 -= e1;
            modE(exp1);
        }
        else if (e1 >= 66 && e1 <= 79){ 
            exp2 = ceil( (float) exp2 + ((e1/4.0) + 19.0));\
            modE(exp2);
            if (exp2 > 200){
                exp2 = ceil((float)exp2 + (e1/9.0) + 21.0);
                modE(exp2);
            }
            else {
                exp2 = ceil( (float) exp2);
                modE(exp2);
            }
            exp1 -= e1;
            modE(exp1);
        }
        else if (e1 >= 80 && e1 <= 99){
            exp2 = ceil((float) exp2 + ((e1/4.0) + 19.0));
            modE(exp2);
            exp2 = ceil((float) exp2 + ((e1/9.0) + 21.0));
            modE(exp2);
            if (exp2 > 400) {
                exp2 = ceil((float) exp2 + (e1/16.0) + 17.0);
                modE(exp2);
                exp2 = ceil((float) exp2 * 1.15);
                modE(exp2);
            }
            exp1 -= e1;
            modE(exp1);
        }
    }
    return exp1 + exp2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    float S;
    int x = sqrt(EXP1);
    float P1,P2;
    // ROAD 1
    if (x * x == EXP1){
        S = EXP1;
    }
    else {
        int above = (x+1) * (x+1), below = x*x;
        int diff1 = above - EXP1;
        int diff2 = EXP1 - below;
        if (diff1 < diff2){
            S = above;
        }
        else {
            S = below;
        }
    }
    if (EXP1 > S) {
        P1 = 100;
    }
    else {
        P1 = (((float) EXP1 / S + 80.0) / 123.0) * 100;
    }
    // ROAD 2
    int paidMoney = 0;
    int stopMoney = 0.5 * M1;
    if (E2 % 2 != 0){
        while (paidMoney < stopMoney) {
            if (HP1 < 200){
                HP1 = ceil((float)HP1 * 130 / 100);
                modH(HP1);
                M1 = M1 - 150;
                modM(M1);
                paidMoney += 150;
                if (paidMoney > stopMoney){
                    break;
                }
            }
            else {
                HP1 = ceil((float)HP1 * 110 / 100);
                modH(HP1);
                M1 = M1 - 70;
                modM(M1);
                paidMoney += 70;
                if (paidMoney > stopMoney){
                    break;
                }
            }
            if (EXP1 > 400){
                M1 -= 120;
                modM(M1);
                paidMoney += 120;
                EXP1 = ceil((float) EXP1 * 113 / 100);
                modE(EXP1);
                if (paidMoney > stopMoney){
                    break;
                }
            }
            else {
                M1 -= 200;
                modM(M1);
                paidMoney += 200;
                EXP1 = ceil((float) EXP1 * 113 / 100);
                modE(EXP1);
                if (paidMoney > stopMoney){
                    break;
                }
            }
            if (EXP1 >= 300){
                M1 -= 120;
                modM(M1);
                paidMoney += 120;
                EXP1 = ceil((float) EXP1 * 90 / 100);
                modE(EXP1);
            if (paidMoney > stopMoney){
                    break;
                }
            }
            else {
                M1 = M1 - 100;
                modM(M1);
                paidMoney += 100;
                EXP1 = ceil((float)EXP1 * 90 / 100);
                modE(EXP1);
                if (paidMoney > stopMoney){
                    break;
                }
            }
        }
    }
    // else {
    //     while (M1 > 0){
    //           if (HP1 < 200){
    //             M1 = M1 - 150;                
    //             HP1 = ceil((float)HP1 * 130 / 100);
    //             if (M1 == 0){
    //                 break;
    //             }
    //         }
    //         else {
    //             M1 = M1 - 70;
    //             HP1 = ceil((float)HP1 * 110 / 100);
    //             if (M1 == 0){
    //                 break;
    //             }
    //         }
    //         if (EXP1 > 400){
    //             M1 -= 120;
    //             EXP1 = ceil((float) EXP1 * 113 / 100);
    //             if (M1 == 0){
    //                 break;
    //             }
    //         }
    //         else {
    //             M1 -= 200;
    //             EXP1 = ceil((float) EXP1 * 113 / 100);
    //             if (M1 == 0){
    //                 break;
    //             }
    //         }
    //         if (EXP1 >= 300){
    //             M1 -= 120;
    //             EXP1 = ceil((float) EXP1 * 90 / 100);
    //             if (M1 == 0){
    //                 break;
    //             }
    //         }
    //         else {
    //             M1 -= 100;
    //             EXP1 = ceil((float)EXP1 * 90 / 100);
    //             if (M1 == 0){
    //                 break;
    //             }
    //         }
    //         break;
    //     }
    // }
    else {
        while (M1 != 0){
            if (HP1 >= 200 ){
                HP1 = ceil((float)HP1 * 110 / 100);
                modH(HP1);
                M1 -= 70;
                modM(M1);
                if (M1 == 0){
                    break;
                }
            }
            else {
                HP1 = ceil((float) HP1 * 130 / 100);
                modH(HP1);
                M1 -= 150;
                modM(M1);
                if (M1 == 0){
                    break;
                }
            }
            if (EXP1 < 400){
                M1 -= 200;
                modM(M1);
                EXP1 = ceil((float) EXP1 * 113 / 100);
                modE(EXP1);
                if (M1 == 0){
                    break;
                }
            }
            else {
                M1 -= 120;
                modM(M1);
                EXP1 = ceil((float) EXP1 * 113 / 100);
                modE(EXP1);
                if (M1 == 0){
                    break;
                }
            }

            if (EXP1 < 300){
                M1 -= 100;
                modM(M1);
                EXP1 = ceil((float) EXP1 * 90 / 100);
                modE(EXP1);
                if (M1 == 0){
                    break;
                }
            }
            else {
                M1 -= 120;
                modM(M1);
                EXP1 = ceil((float) EXP1 * 90 / 100);
                modE(EXP1);
                if (M1 == 0){
                    break;
                }
            }
            break;
        }
    }
    // ADJUST HP AND EXP
    HP1 = ceil((float) HP1 * 83 / 100);
    modH(HP1);
    EXP1 = ceil((float) EXP1 * 117 / 100);
    modE(EXP1);
    if (x * x == EXP1){
        S = EXP1;
    }
    else {
        int above = (x+1) * (x+1), below = x*x;
        int diff1 = above - EXP1;
        int diff2 = EXP1 - below;
        if (diff1 < diff2){
            S = above;
        }
        else {
            S = below;
        }
    }
    if (EXP1 > S) {
        P2 = 100;
    }
    else {
        P2 = (((float) EXP1 / S + 80.0) / 123.0) * 100;
    }
    // ROAD 3
    float P3;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 / 10 < 1){
        P3 = P[E2];
    }
    else {
        int digit1 = E2 % 10;
        int digit2 = E2 / 10 % 10;
        int sum = digit1 + digit2;
        int i;
        if (sum >= 10){
            i = sum % 10;
        }
        else {
            i = sum;
        }
        P3 = P[i];
    }
    // END ROAD
    int avg = ceil(((float)P1 + (float)P2 + (float)P3) / 3);
    if (avg == 100){
        EXP1 = ceil((float) EXP1 * 75 / 100);
        modE(EXP1);
    }
    else if (avg < 50) {
        HP1 = ceil((float) HP1 * 85 / 100);
        modH(HP1);
        EXP1 = ceil((float) EXP1 * 115 / 100);
        modE(EXP1);
    }
    else {
        HP1 = ceil((float) HP1 * 90 / 100);
        modH(HP1);
        EXP1 = ceil((float) EXP1 * 120 / 100);
        modE(EXP1);
    }
    if (E2 < 0 || E2 > 99){
        return -999;
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int T[10][10];
    int S;
    int a = 0 ,b = 0; 
    int n;  
    int Maxr = -2147483648; 
    int Maxl = -2147483648;
    int comp = 0;
    // SCORE OF TAXI
    for (int j = 0; j < 10; j++){
        for (int i = 0; i < 10; i++ ){
            T[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    // MEETING LOCATION
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){       
            if (T[i][j] > (E3*2)){
                a++;
            }
            else if ((-E3) > T[i][j]) {
                b++;
            }
        }
    }
    while (a / 10 >= 1){
        a = a % 10 + (a / 10 % 10);    
    }
    while (b / 10 >= 1){
        b = b % 10 + (b /10 % 10);
    }
    // SCORE OF SHER AND WATSON
    /// RIGHT DIAG 
    int tempa = a;
    int tempb = b;
    while (tempa >= 0 && tempb <= 9 ){
        Maxr = max(Maxr, T[tempa][tempb]);
        tempa --;
        tempb ++;
    }
    tempa = a;
    tempb = b;
    while (tempa <= 9 && tempb >= 0){
        Maxr = max(Maxr, T[tempa][tempb]);
        tempa++;
        tempb--;
    }
    // LEFT DIAG
    tempa = a;
    tempb = b;
    while (tempa <= 9 && tempb <= 9){
        Maxl = max(Maxl, T[tempa][tempb]);
        tempa++;
        tempb++;
    }
    tempa = a;
    tempb = b;
    while (tempa >= 0 && tempb >= 0){
        Maxl = max(Maxl, T[tempa][tempb]);
        tempa--;
        tempb--;
    }
    if (Maxr > Maxl){
        S = Maxr;
    }
    else {
        S = Maxl;
    }
    // COMPARE BOTH SCORE
    if (abs(T[a][b]) > S){
        comp = T[a][b];
        EXP1 = ceil((float) EXP1 * 88 / 100) ;
        EXP2 = ceil((float) EXP2 * 88 / 100);
        HP1 = ceil((float) HP1 * 90 / 100);
        HP2 = ceil((float) HP2 * 90 / 100);
    }
    else {
        comp = S;
        EXP1 = ceil((float) EXP1 * 112 / 100);
        EXP2 = ceil((float) EXP2 * 112 / 100);
        HP1 = ceil((float) HP1 * 110 / 100);
        HP2 = ceil((float) HP2 * 110 / 100);
    }
    if (E3 >= 0 || E3 <= 99){    
        if (EXP1 > 600 || EXP2 > 600 || HP1 > 666 || HP2 > 666){
            if (EXP1 > 600){
                EXP1 = 600;
            }
            if (EXP2 > 600){
                EXP2 = 600;
            }
            if (HP1 > 666){
                HP1 = 666;
            }
            if (HP2 > 666){
                HP2 = 666;
            }
        }
        if (EXP1 < 0 || EXP2 < 0 || HP1 < 0 || HP2 < 0){
            if (EXP1 < 0){
                EXP1 = 0;
            }
            if (EXP2 < 0){
                HP1 = 0;
            }
            if (HP1 < 0){
                HP1 = 0;
            }
            if (HP2 < 0){
                HP2 = 0;
            }
        }
    }
    if (E3 < 0 || E3 > 99){
        return -999;
    }
    return comp;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // FIND THE STRING BEFORE @ OF EMAIL
    string str = (string) email;
    string pass = (string) s;
    int a = 0;
    string se;
    int index = str.find("@");
    while (a < index){
        se = se + str[a];
        a++;
    }
    // CHECK IF THE PASSWORD VALID OR NOT

    // CHECK LENGTH
    if (pass.length() < 8){
        return -1;
    }
    else if (pass.length() > 20){
        return -2;
    }
    // CHECK IF HAS SE INSIDE OR NOT
    if (pass.find(se) != -1 ){
        return -(300+ pass.find(se)); 
    }
    // CHECK IF HAVE SPECIAL CHARACTERS OR NOT 
    if (pass.find("@") == -1 && pass.find("#") == -1 && pass.find("%") == -1 && pass.find("$") == -1 && pass.find("!") == -1){
        return -5;
    }
    // CHECK IF S HAVE MORE THAN 2 CONSECUTIVE CHAR 
        a = 0;
        while (a <= pass.length()){
            if (( (int)pass[a] == (int)pass[a+1])) {
                return -(400 + a);
            }
            a++;
        }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////