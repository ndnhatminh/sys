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

void TEST_HP(int &a){
    a = max((int)0,a);
    a = min((int)666,a);
}

void TEST_EXP(int &a){
    a = max((int)0,a);
    a = min((int)600,a);
}

void TEST_M(int &a){
    a = max((int)0,a);
    a = min((int)3000,a);
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

    if(e1 < 0 || e1 > 99){
        return -99;
    }

    if(e1 >= 0 && e1 <= 3){
        //TH1:
        if(e1 == 0){
            exp2 += (int)29;
            exp2 = ceil(exp2);
            TEST_EXP(exp2);
        }else if(e1 == 1){
            exp2 += (int)45;
            exp2 = ceil(exp2);
            TEST_EXP(exp2);
        }else if(e1 == 2){
            exp2 += (int)75;
            exp2 = ceil(exp2);
            TEST_EXP(exp2);
        }else if(e1 == 3){
            exp2 += (int)(29 + 45 + 75);
            exp2 = ceil(exp2);
            TEST_EXP(exp2);
        }


        int D = 3 * e1 + exp1 * 7;
        if(D % 2 == 0){
            exp1 += (D % 200 == 0 ? D / 200 : (D / 200) + 1);
            TEST_EXP(exp1);
        }else {
            exp1 -= (D / 100);
            TEST_EXP(exp1);
        }
    }else {
        //TH2:
        if(e1 >= 4 && e1 <= 19){
            exp2 += (e1 % 4 == 0 ? e1 / 4 : (e1 / 4) + 1) + (int)19;
            TEST_EXP(exp2);
        }else if(e1 >= 20 && e1 <= 49){
            exp2 += (e1 % 9 == 0 ? e1 / 9 : (e1 / 9) + 1) + (int)21;
            TEST_EXP(exp2);
        }else if(e1 >= 50 && e1 <= 65){
            exp2 += (e1 % 16 == 0 ? e1 / 16 : (e1 / 16) + 1) + (int)17;
            TEST_EXP(exp2);
        }else if(e1 >= 66 && e1 <= 79){
            exp2 += (e1 % 4 == 0 ? e1 / 4 : (e1 / 4) + 1) + (int)19;
            TEST_EXP(exp2);
            if(exp2 > 200){
                exp2 += (e1 % 9 == 0 ? e1 / 9 : (e1 / 9) + 1) + (int)21;
                TEST_EXP(exp2);
            }
        }else if(e1 >= 80 && e1 <= 99){
            exp2 += (e1 % 4 == 0 ? e1 / 4 : (e1 / 4) + 1) + (int)19;
            TEST_EXP(exp2);
            exp2 += (e1 % 9 == 0 ? e1 / 9 : (e1 / 9) + 1) + (int)21;
            TEST_EXP(exp2);
            if(exp2 > 400){
                exp2 += (e1 % 16 == 0 ? e1 / 16 : (e1 / 16) + 1) + (int)17;
                TEST_EXP(exp2);
                int tmp = exp2 * 15;
                exp2 += (tmp % 100 == 0 ? tmp / 100 : (tmp / 100) + 1);
                TEST_EXP(exp2);
            }
        }

        exp1 -= e1;
        TEST_EXP(exp1);
    }
    return exp1 + exp2;
}

// Hàm tính xác suất cho task 2
double Probability(int &EXP){
    int tmp = sqrt(EXP);
    int S = -1;
    if(EXP - (tmp * tmp) < (tmp + 1) * (tmp + 1) - EXP){
        S = (tmp * tmp);
    }else S = (tmp + 1) * (tmp + 1);
    double P = 1.0;
    if(EXP < S){
        P = (double)(EXP / S + 80) / (double)123;
    }
    return P;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    if(E2 < 0 || E2 > 99){
        return -99;
    }

    // PATH 1: 
    double P1 = Probability(EXP1);

    // PATH 2:
    if(E2 % 2 == 1){
        double h = 0.5 * M1,sum = 0;
        while(sum <= h){
            // Chi phí cho thức ăn và nước uống 
            if(HP1 < 200){
                if(sum <= h){
                    int inc = HP1 * 30;
                    HP1 += (inc % 100 == 0 ? inc / 100 : inc / 100 + 1);
                    TEST_HP(HP1);
                    M1 -= 150;
                    TEST_M(M1);
                    sum += 150;
                }
                else break;
            }else {
                if(sum <= h){
                    int inc = HP1 * 10;
                    HP1 += (inc % 100 == 0 ? inc / 100 : inc / 100 + 1);
                    TEST_HP(HP1);
                    M1 -= 70;
                    TEST_M(M1);
                    sum += 70;
                }else break;
            }

            // Chi phí cho phương tiện di chuyển 
            if(EXP1 < 400){
                if(sum <= h){
                    M1 -= 200;
                    TEST_M(M1);
                    sum += 200;
                }else break;
            }else {
                if(sum <= h){
                    M1 -= 120;
                    TEST_M(M1);
                    sum += 120;
                }else break;
            }

            int inc = EXP1 * 13;
            EXP1 += (inc % 100 == 0 ? inc / 100 : inc / 100 + 1);
            TEST_EXP(EXP1);

            // Chi phí giúp đỡ người vô gia cư 
            if(EXP1 < 300){
                if(sum <= h){
                    M1 -= 100;
                    TEST_M(M1);
                    sum += 100;
                }else break;
            }else {
                if(sum <= h){
                    M1 -= 120;
                    TEST_M(M1);
                    sum += 120;
                }else break;
            }

            int dec = EXP1 * 10;
            EXP1 -= (dec / 100);
        }
        int hp_dec = HP1 * 17;
        HP1 -= (hp_dec / 100);
        TEST_HP(HP1);
        int exp_inc = EXP1 * 17;
        EXP1 += (exp_inc % 100 == 0 ? (exp_inc / 100) : (exp_inc / 100) + 1);
        TEST_EXP(EXP1);
    }else {

        if(M1 > 0){
            if(HP1 < 200){
                int inc = HP1 * 30;
                HP1 += (inc % 100 == 0 ? inc / 100 : inc / 100 + 1);
                TEST_HP(HP1);
                M1 -= 150;
                TEST_M(M1);
            }else {
                int inc = HP1 * 10;
                HP1 += (inc % 100 == 0 ? inc / 100 : inc / 100 + 1);
                TEST_HP(HP1);
                M1 -= 70;
                TEST_M(M1);   
            }
        }

        if(M1 > 0){
            if(EXP1 < 400){
                M1 -= 200;
                TEST_M(M1);
            }else {
                M1 -= 120;
                TEST_M(M1);
            }

            int inc = EXP1 * 13;
            EXP1 += (inc % 100 == 0 ? inc / 100 : inc / 100 + 1);
            TEST_EXP(EXP1);
        }

        if(M1 > 0){
            if(EXP1 < 300){
                M1 -= 100;
                TEST_M(M1);
            }else {
                M1 -= 120;
                TEST_M(M1);
            }
            int dec = EXP1 * 10;
            EXP1 -= (dec / 100);
        }


        int hp_dec = HP1 * 17;
        HP1 -= (hp_dec / 100);
        TEST_HP(HP1);
        int exp_inc = EXP1 * 17;
        EXP1 += (exp_inc % 100 == 0 ? (exp_inc / 100) : (exp_inc / 100) + 1);
        TEST_EXP(EXP1);
    }

    double P2 = Probability(EXP1);

    // PATH 3:
    
    // Mảng số cố định 10 giá trị xác suất cho path 3:
    double prob[10] = {32,47,28,79,100,50,22,83,64,11};

    int I = ((E2 % 10) + ((E2 / 10) % 10)) % 10;
    double P3 = prob[I] / 100.0;

    double P = (P1 + P2 + P3) / 3.0;

    if(P == 1.0){
        int per = EXP1 * 25;
        EXP1 -= (per / 100);
        TEST_EXP(EXP1);
    } else if(P < 0.5){
        int hp_dec = HP1 * 15;
        HP1 -= (hp_dec / 100);
        TEST_HP(HP1);
        int exp_inc = EXP1 * 15;
        EXP1 += (exp_inc % 100 == 0 ? (exp_inc / 100) : (exp_inc / 100) + 1);
        TEST_EXP(EXP1);
    }else if(P >= 0.5){
        int hp_dec = HP1 * 10;
        HP1 -= (hp_dec / 100);
        TEST_HP(HP1);
        int exp_inc = EXP1 * 20;
        EXP1 += (exp_inc % 100 == 0 ? (exp_inc / 100) : (exp_inc / 100) + 1);
        TEST_EXP(EXP1);
    }

    return HP1 + EXP1 + M1;
}

// Task 3

int compressed(int n){
    while(n / 10 > 0){
        int tmp = n,sum = 0;
        while(tmp){
            sum += (tmp % 10);
            tmp /= 10;
        }
        n = sum;
    }
    return n;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

    if(E3 < 0 || E3 > 99){
        return -99;
    }

    int a[10][10] = {0};
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    int I = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(a[i][j] > (E3 * 2) && a[i][j] > 0)
                I++;
        }
    }

    I = compressed(I);

    int J = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(a[i][j] < 0 && a[i][j] < -E3){
                J++;
            }
        }
    }

    J = compressed(J);

    int spot = a[I][J];

    int mx = -1e9;
    int idx1 = I,idx2 = J,idx3 = I,idx4 = J;
    while(idx1 >= 0 && idx2 >= 0){
        mx = max(mx,a[idx1][idx2]);
        idx1--;
        idx2--;
    }

    while(idx3 <= 9 && idx4 <= 9){
        mx = max(mx,a[idx3][idx4]);
        idx3++;
        idx4++;
    }

    idx1 = I,idx2 = J,idx3 = I,idx4 = J;
    while(idx1 <= 9 && idx2 >= 0){
        mx = max(mx,a[idx1][idx2]);
        idx1++;
        idx2--;
    }

    while(idx3 >= 0 && idx4 <= 9){
        mx = max(mx,a[idx3][idx4]);
        idx3--;
        idx4++;
    }

    mx = abs(mx);

    if(abs(spot) > mx){
        int tmp1 = HP1 * 10;
        HP1 -= (tmp1 / 100);
        TEST_HP(HP1);
        int tmp2 = EXP1 * 12;
        EXP1 -= (tmp2 / 100);
        TEST_EXP(EXP1);

        int tmp3 = HP2 * 10;
        HP2 -= (tmp3 / 100);
        TEST_HP(HP2);
        int tmp4 = EXP2 * 12;
        EXP2 -= (tmp4 / 100);
        TEST_EXP(EXP2);
    }else {
        int tmp1 = HP1 * 10;
        HP1 += (tmp1 % 100 == 0 ? tmp1 / 100 : tmp1 / 100 + 1);
        TEST_HP(HP1);
        int tmp2 = EXP1 * 12;
        EXP1 += (tmp2 % 100 == 0 ? tmp2 / 100 : tmp2 / 100 + 1);
        TEST_EXP(EXP1);

        int tmp3 = HP2 * 10;
        HP2 += (tmp3 % 100 == 0 ? tmp3 / 100 : tmp3 / 100 + 1);
        TEST_HP(HP2);
        int tmp4 = EXP2 * 12;
        EXP2 += (tmp4 % 100 == 0 ? tmp4 / 100 : tmp4 / 100 + 1);
        TEST_EXP(EXP2);
    }

    if(abs(spot) > mx)
        return spot;
    else return mx;

    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    int index = -1;
    for(int i = 0; email[i] != '\0'; i++){
        if(email[i] == '@'){
            index = i;
            break;
        }
    }

    char se[100];
    strncpy(se,email,index);

    se[index] = '\0';

    if(strlen(s) < 8){
        return -1;
    }

    if(strlen(s) > 20){
        return -2;
    }

    const char *firstIdx = strstr(s,se); // strstr cho phép tìm chuỗi con se trong s,
    //nếu có thì sẽ trả về một chuối kí tự không thay đổi
    if(firstIdx != NULL){
        return -(300 + (firstIdx - s));
    }

    for(int i = 0; i < strlen(s) - 2; i++){
        if(s[i] == s[i + 1] && s[i + 1] == s[i + 2]){
            return -(400 + i);
        }
    }

    bool ok = false;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'){
            ok = true;
            break;
        }
    }

    if(!ok)
        return -5;


    for(int i = 0; i < strlen(s); i++){
        if(!(s[i] >= 'a' && s[i] <= 'z')
           && !(s[i] >= 'A' && s[i] <= 'Z')
           && !(s[i] >= '0' && s[i] <= '9')
           && !(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')){
            return i;
           }
    }

    return -10;
}


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int cnt[1000] = {0};
    int arr[1000] = {0};

    int ans = -1,Idx = -1;
    string f = "";
    for(int i = 0; i < num_pwds; i++){
        if(cnt[i] != -1){
            int dem = 1;
            for(int j = i + 1; j < num_pwds; j++){
                if(strcmp(arr_pwds[i],arr_pwds[j]) == 0){
                    dem++;
                    cnt[j] = -1;
                }
            }
            arr[i] = dem;
            ans = max(ans,dem);
        }
    }
    for(int i = 0; i < num_pwds; i++){
        if(arr[i] == ans){
            if(strlen(arr_pwds[i]) > (int)f.size()){
                f = arr_pwds[i];
                Idx = i;
            }
        }
    }
    return Idx;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////






