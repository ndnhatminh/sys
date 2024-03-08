#include "study_in_pink1.h"



bool readFile(
    const string& filename,
    int& HP1,
    int& HP2,
    int& EXP1,
    int& EXP2,
    int& M1,
    int& M2,
    int& E1,
    int& E2,
    int& E3
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

//SO CHINH PHUONG
int cp(int n){
    int sqr1 = sqrt(n);
    if (sqr1 * sqr1 == n) {
        return 1;
    }
    return 0;
}

//SO CHINH PHUONG GAN NHAT
int nearestcp(int n){
    int lower = 0;
    int higher = 0;

    for(int i = n; ; i++){
        if(cp(i) == 1){
            higher = i;
            break;
        }
    }
    for(int i = n; i > 0; i--){
        if(cp(i) == 1){
            lower = i;
            break;
        }
    }
    if(higher - n <= n - lower){
        return higher;
    }else if(higher - n >= n - lower){
        return lower;
    }else if(higher == n){
        return n;
    }
    return 0;

}

//check M
int check_M(int M){
    if (M > 3000) {
        M = 3000;
        return M;
    }
    else if (M < 0) {
        M = 0;
        return M;
    }
    return M;
}

//check EXP
int check_EXP(int EXP){
    if (EXP > 600) {
        EXP = 600;
        return EXP;
    }
    else if (EXP < 0) {
        EXP = 0;
        return EXP;
    }
    return EXP;
}

//check HP
int check_HP(int HP){
    if (HP > 666) {
        HP = 666;
        return HP;
    }
    else if (HP < 0) {
        HP = 0;
        return HP;
    }
    return HP;
}

// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {
    // TODO: Complete this function
    //check e1
    if(E1 < 0 || E1 > 99){
        return -99;
    }

    //Check value of exp1 and exp2
    EXP1 = check_EXP(EXP1);
    EXP2 = check_EXP(EXP2);
     
    if(E1 >= 0 && E1 <= 3){
        int D = E1 * 3 + EXP1 * 7; //calculate D
        switch (E1) {
            case 0:
                EXP2 = EXP2 + 29;
                break;
            case 1:
                EXP2 = EXP2 + 45;
                break;
            case 2:
                EXP2 = EXP2 + 75;
                break;
            case 3:
                EXP2 = EXP2 + 149;
                break;
        }
        if (D % 2 == 0) { //Afghanistan
            EXP1 = EXP1 +  ceil(D / 200.0);
        }
        else { //Iraq
            EXP1 = EXP1 - ceil(D / 100.0);
        }
    }
    else if(E1 >= 4 && E1 <= 99){
        // calculate EXP2
        if (E1 >= 4 && E1 <= 19) {
            EXP2 = EXP2 + ceil(E1 / 4.0) + 19;
        }
        else if (E1 >= 20 && E1 <= 49) {
            EXP2 = EXP2 + ceil(E1 / 9.0) + 21;
        }
        else if (E1 >= 50 && E1 <= 65) {
            EXP2 = EXP2 + ceil(E1 / 16.0) + 17;
        }
        else if (E1 >= 66 && E1 <= 79) {
            EXP2 = EXP2 + ceil(E1 / 4.0) + 19;
            if (EXP2 > 200) {
                EXP2 = EXP2 + ceil(E1 / 9.0) + 21;
            }
        }
        else if (E1 >= 80 && E1 <= 99) {
            EXP2 = EXP2 + ceil(E1 / 4.0) + 19 + ceil(E1 / 9.0) + 21; //case 1 and case 2
            if (EXP2 > 400) {
                EXP2 = EXP2 + ceil(E1 / 16.0) + 17;
                EXP2 = ceil((EXP2 * 1.15)-0.005);
            }
        }
        //calculate EXP1
        if (E1 >= 4 && E1 <= 99) {
            EXP1 = EXP1 - E1;
        }
    }

    //Check value of exp1 and exp2 again
    EXP1 = check_EXP(EXP1);
    EXP2 = check_EXP(EXP2);

    return EXP1 + EXP2;
}

   

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    // check HP1
    HP1 = check_HP(HP1);
    // check M1
    M1 = check_M(M1);

    //Check E2
    if (E2 < 0 && E2 > 99) {
        return -99;
    }
    // check EXP1
    EXP1 = check_EXP(EXP1);
    //road1
    double P1;
    int S1 = nearestcp(EXP1);
    if(EXP1 >= S1){
        P1 = 100;
    }else{
        P1 = ((EXP1/S1 + 80)/123) * 100;
    }
   //Road2
    if(M1 == 0){
        HP1 = ceil(HP1 * 0.83 - 0.001);
        EXP1 = ceil(EXP1 * 1.17 - 0.001);
        //CHECK
        EXP1 = check_EXP(EXP1);
        HP1 = check_HP(HP1);
    }else{
        double m = M1*0.5;
        int cost = 0;
        if(E2 % 2 != 0){
            while(cost < m){
                //EVENT_1
                if(HP1 < 200){
                    HP1 = ceil(HP1*1.3 - 0.001);
                    M1 = M1 - 150;
                    cost += 150;
                    //CHECK
                    HP1 = check_HP(HP1);
                    M1 = check_M(M1);
                }else{
                    HP1 = ceil(HP1*1.1 - 0.001);
                    M1 = M1 - 70;
                    cost += 70;
                    //CHECK
                    HP1 = check_HP(HP1);
                    M1 = check_M(M1);
                }
                //CHECK M1
                if(cost > m){
                    HP1 = ceil(HP1*0.83 - 0.001);
                    EXP1 = ceil(EXP1*1.17 - 0.001);
                    //CHECK
                    HP1 = check_HP(HP1);
                    EXP1 = check_EXP(EXP1);
                    break;
                }
                //EVENT_2
                if(EXP1 < 400){
                    M1 = M1 - 200;
                    cost += 200;
                }else{
                    M1 = M1 - 120;
                    cost += 120;
                }
                EXP1 = ceil(EXP1*1.13 - 0.001);
                //CHECK
                M1 = check_M(M1);
                EXP1 = check_EXP(EXP1);
                //CHECK M1
                if(cost > m){
                    HP1 = ceil(HP1*0.83 - 0.001);
                    EXP1 = ceil(EXP1*1.17 - 0.001);
                    //CHECK
                    HP1 = check_HP(HP1);
                    EXP1 = check_EXP(EXP1);
                    break;
                }
                //EVENT_3
                if(EXP1 < 300){
                    M1 = M1 - 100;
                    cost += 100;
                }else{
                    M1 = M1 - 120;
                    cost += 120;
                }
                EXP1 = ceil(EXP1*0.9 - 0.001);
                //CHECK
                M1 = check_M(M1);
                EXP1 = check_EXP(EXP1);
                //CHECK M1
                if(cost > m){
                    HP1 = ceil(HP1*0.83 - 0.001);
                    EXP1 = ceil(EXP1*1.17 - 0.001);
                    //CHECK
                    HP1 = check_HP(HP1);
                    EXP1 = check_EXP(EXP1);
                    break;
                }
            }
        }else if(E2 % 2 == 0){ // EVEN
            //EVENT_1
            if(HP1 < 200){
                HP1 = ceil(HP1*1.3 - 0.001);
                M1 = M1 - 150;
                //CHECK
                HP1 = check_HP(HP1);
                M1 = check_M(M1);
            }else{
                HP1 = ceil(HP1*1.1 - 0.001);
                M1 = M1 - 70;
                //CHECK
                HP1 = check_HP(HP1);
                M1 = check_M(M1);
            }
            //CHECK M1
            if(M1<=0){
                HP1 = ceil(HP1*0.83 - 0.001);
                EXP1 = ceil(EXP1*1.17 - 0.001);
                //CHECK
                HP1 = check_HP(HP1);
                EXP1 = check_EXP(EXP1);
            }else{
                //EVENT_2
                if(HP1 < 400){
                    M1 = M1 - 200;
                }else{    
                    M1 = M1 - 120;
                }
                EXP1 = ceil(EXP1*1.13 - 0.001);
                //CHECK
                M1 = check_M(M1);
                EXP1 = check_EXP(EXP1);
                //CHECK M1
                if(M1<=0){
                    HP1 = ceil(HP1*0.83 - 0.001);
                    EXP1 = ceil(EXP1*1.17 - 0.001);
                    //CHECK
                    HP1 = check_HP(HP1);
                    EXP1 = check_EXP(EXP1);
                }else{
                    //EVENT_3
                    if(EXP1 < 300){
                        M1 = M1 - 100;
                    }else{
                        M1 = M1 - 120;
                    }
                    EXP1 = ceil(EXP1*0.9 - 0.001);
                    //CHECK
                    M1 = check_M(M1);
                    EXP1 = check_EXP(EXP1);
                }
            }
        }
    }
    
    double P2;
    int S2 = nearestcp(EXP1);
    if(EXP1 >= S2){
        P2 = 100;
    }else{
        P2 = ((EXP1/S2 + 80)/123) * 100;
    }
    //Road3
    int P3;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 >= 0 && E2 <= 9) {
        P3 = P[E2];
    }
    else {
        i = E2 / 10 + E2 % 10;
        if (i > 9) {
            P3 = P[i % 10];
        }
        else {
            P3 = P[i];
        }
    }
    //conclude
    if (P1 == 100 && P2 == 100 && P3 == 100) {
        EXP1 = ceil(EXP1 * 0.75 - 0.001);
    }
    else {
        double p = (P1 + P2 + P3) / 3;
        if (p < 50) {
            HP1 = ceil(HP1 * 0.85 - 0.001);
            EXP1 = ceil(EXP1 * 1.15 - 0.001);
        }
        else if(p >= 50){
            HP1 = ceil(HP1 * 0.9 - 0.001);
            EXP1 = ceil(EXP1 * 1.2 - 0.001);
        }
    }
    // check HP1
    HP1 = check_HP(HP1);
    // check M1
    M1 = check_M(M1);
    // check EXP1
    EXP1 = check_EXP(EXP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    // check HP1
    HP1 = check_HP(HP1);
    // check HP2
    HP2 = check_HP(HP2);
    //check E3
    if(E3 < 0 && E3 > 99){
        return -99;
    }
    //check EXP1, EXP2
    EXP1 = check_EXP(EXP1);
    EXP2 = check_EXP(EXP2);
    //initial matrix
    int map[10][10];
    int a = 0, b = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (map[i][j] > (E3 * 2)) {
                a = a + 1; //calculate number > E2*2
            }
            else if (map[i][j] < (-E3)) {
                b = b + 1; //calculate number < -E3
            }
        }
    }
    if(a > 9){
        a = a / 10 + a % 10; //value of taxi 
        if(a>9){
            a = a/10 + a % 10;
        }
    }
    if(b > 9){
        b = b / 10 + b % 10; //value of taxi
        if(b>9){
            b = b / 10 + b % 10;
        }
    }
    int max_left = map[a][b]; // position that Sherlock catch taxi
    // find max in left diagnol 
    for (int m = 0; m < 9; ++m) {
        if ((a - m) >= 0 && (b - m) >= 0) { //go up 
            if (map[a - m][b - m] > max_left) {
                max_left = map[a - m][b - m]; 
            }
        }
        if ((a + m) <= 9 && (b + m) <= 9) { //go down
            if (map[a + m][b + m] > max_left) {
                max_left = map[a + m][b + m];
            }
        }
    }
    // find max in right diagnol
    int max_right = map[a][b];
    for (int n = 0; n < 9; ++n) {
        if ((a - n) >= 0 && (b + n) <= 9) { //go up
            if (map[a - n][b + n] > max_right) {
                max_right = map[a - n][b + n];
            }
        }
        if ((a + n) <= 9 && (b - n) >= 0) { //go down
            if (map[a + n][b - n] > max_right) {
                max_right = map[a + n][b - n];
            }
        }
    }
    
    //find max of diagnols (value of Sherlock and Watson)
    if (max_left > max_right) {
        if (abs(map[a][b]) > abs(max_left)) { //didn't catch up
            EXP1 = ceil(EXP1 * 0.88 - 0.001);
            EXP2 = ceil(EXP2 * 0.88 - 0.001);
            HP1 = ceil(HP1 * 0.9 - 0.001);
            HP2 = ceil(HP2 * 0.9 - 0.001);
            return map[a][b];
        }
        else if (abs(map[a][b]) < abs(max_left)) { //catched up
            EXP1 = ceil(EXP1 * 1.12 - 0.001);
            EXP2 = ceil(EXP2 * 1.12 - 0.001);
            HP1 = ceil(HP1 * 1.1 - 0.001);
            HP2 = ceil(HP2 * 1.1 - 0.001);
            return max_left;
        }else{
            EXP1 = ceil(EXP1 * 1.12 - 0.001);
            EXP2 = ceil(EXP2 * 1.12 - 0.001);
            HP1 = ceil(HP1 * 1.1 - 0.001);
            HP2 = ceil(HP2 * 1.1 - 0.001);
            return max_left;
        }
    }
    else if (max_right > max_left) {
        if (abs(map[a][b]) > abs(max_right)) { //didn't catch up
            EXP1 = ceil(EXP1 * 0.88 - 0.001);
            EXP2 = ceil(EXP2 * 0.88 - 0.001);
            HP1 = ceil(HP1 * 0.9 - 0.001);
            HP2 = ceil(HP2 * 0.9 - 0.001);
            return map[a][b];
        }
        else if (abs(map[a][b]) < abs(max_right)) { //catched up
            EXP1 = ceil(EXP1 * 1.12 - 0.001);
            EXP2 = ceil(EXP2 * 1.12 - 0.001);
            HP1 = ceil(HP1 * 1.1 - 0.001);
            HP2 = ceil(HP2 * 1.1 - 0.001);
            return max_right;
        }else{
            EXP1 = ceil(EXP1 * 1.12 - 0.001);
            EXP2 = ceil(EXP2 * 1.12 - 0.001);
            HP1 = ceil(HP1 * 1.1 - 0.001);
            HP2 = ceil(HP2 * 1.1 - 0.001);
            return max_right;
        }
    }
    // check HP1
    HP1 = check_HP(HP1);
    // check HP2
    HP2 = check_HP(HP2);
    //check EXP1, EXP2
    EXP1 = check_EXP(EXP1);
    EXP2 = check_EXP(EXP2);
    
    return -1;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    //find se
    string se;
    string b = email;
    string a = s; //password
    int c = 0;

    for (char i : b) {
        if (i == 64) {
            break;
        }
        se += i;

    }
    if(strlen(s) < 8){
        return -1;
    }else if(strlen(s) > 20){
        return -2;
    }
    if (a.find(se) != string::npos) { // Wonder that se is in s ???
        return -(300 + a.find(se));
    }
    for (int g = 0; g < strlen(s); g++) {
        if ((s[g] == s[g + 1]) && (s[g + 1] == s[g + 2])) {
            return -(400 + g);
        }
        if (s[g] != 64 && s[g] != 35 && s[g] != 36 && s[g] != 37 && s[g] != 33) {
            c += 1;
        }
        if(c == strlen(s)){
            return -5;
        }
    }
    return -10;

}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max = 0;
    int max_length = 0;
    string valid_pwd;

    for (int i = 0; i < num_pwds; i++) {
        int a = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (arr_pwds[i] == arr_pwds[j]) {
                a+=1;
            }
        }
        if(max<a){
            max=a;
            valid_pwd = arr_pwds[i];
            max_length = strlen(arr_pwds[i]);
        }else if(max == a){
            if(max_length < strlen(arr_pwds[i])){
                max_length = strlen(arr_pwds[i]);
                valid_pwd = arr_pwds[i];
            }
        }

    }
    //
    for (int i = 0; i < num_pwds; i++) {
        if(arr_pwds[i] == valid_pwd){
            return i;
        }
    }
    return -1;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////