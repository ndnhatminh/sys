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

void checkHP(int &HP){
    if(HP > 666) HP = 666;
    if(HP < 0) HP = 0;
}

void checkEXP(int &EXP){
    if(EXP > 600) EXP = 600;
    if(EXP < 0) EXP = 0;
}

void checkM(int &M){
    if(M > 3000) M = 3000;
    if(M < 0) M = 0;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1 < 0 || e1 > 99) return -99;
    checkEXP(exp1);
    checkEXP(exp2);
    // truong hop 1
    if(e1 >= 0 && e1 <= 3){
        if(e1 == 0){
            exp2 += 29;
        }
        else if(e1 ==1){
            exp2 += 45;
        }
        else if(e1 == 2){
            exp2 += 75;
        }
        else{
            exp2 = exp2 + 149;
        }
        checkEXP(exp2);
        int D = 0; D = e1*3 + exp1*7;
        if(D % 2 == 0){
            exp1 = exp1 + D*1.0/200 + 0.999;
        }else{
            exp1 = exp1 - D*1.0/100 + 0.999;
        }
    }
    // truong hop 2
    else{
        if(e1 >= 4 && e1 <= 19){
            exp2 = exp2 + (e1*1.0/4) + 19 + 0.999;
        }
        else if(e1 >= 20 && e1 <= 49){
            exp2 = exp2 + (e1*1.0/9) + 21 + 0.999;
        }
        else if(e1 >= 50 && e1 <= 65){
            exp2 = exp2 + (e1*1.0/16) + 17 + 0.999;
        }
        else if(e1 >= 66 && e1 <= 79){
            exp2 = exp2 + (e1*1.0/4) + 19 + 0.999;
            if(exp2 > 200) exp2 = exp2 + (e1*1.0/9) + 21 + 0.999;
        }
        else{
            exp2 = exp2 + (e1*1.0/4) + 19 + 0.999;
            exp2 = exp2 + (e1*1.0/9) + 21 + 0.999;
            if(exp2 > 400){
                exp2 = exp2 + (e1*1.0/16) + 17 + 0.999;
                exp2 = exp2*1.15 + 0.999;
            }
        }
        exp1 -= e1;
    }
    checkEXP(exp1);
    checkEXP(exp2);

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
    // con duong 1
    checkEXP(EXP1);
    checkHP(HP1);
    checkM(M1);
    if(E3 < 0 || E3 > 99) return -99;
    int i = 1;
    while(i*i <= EXP1){
        i++;
    }
    int x1 = (i-1) * (i-1), x2 = i*i;
    int S = (EXP1 - x1) > (x2 - EXP1)?x2:x1;
    double P1 = 0;
    if(EXP1 >= S){
        P1 = 100;
    }else{
        P1 = (1.0*EXP1/S + 80)/123 * 100;
    }
    // con duong 2
    double P2 = 0;
    double m1 = M1*0.5, tienTieu = 0;
    if(M1 != 0){
        if(E3 % 2 != 0){
            while(true){
                if(HP1 < 200){ // tim thuc an
                    HP1 = HP1*1.3 + 0.999;
                    checkHP(HP1);
                    M1 -= 150;
                    tienTieu += 150;
                    if(tienTieu > m1) break;
                }else{
                    HP1 = 1.1*HP1 + 0.999;
                    checkHP(HP1);
                    M1 -= 70;
                    tienTieu += 70;
                    if(tienTieu > m1) break;
                }

                if(EXP1 < 400){ // thue xe
                    M1 -= 200;
                    EXP1 = EXP1*1.13 + 0.999;
                    checkEXP(EXP1);
                    tienTieu += 200;
                    if(tienTieu > m1) break;
                }else{
                    M1 -= 120;
                    EXP1 = EXP1*1.13 + 0.999;
                    checkEXP(EXP1);
                    tienTieu += 120;
                    if(tienTieu > m1) break;
                }

                if(EXP1 < 300){// tim hanh ly
                    M1 -= 100;
                    EXP1 = EXP1*0.9 + 0.999;
                    checkEXP(EXP1);
                    tienTieu += 100;
                    if(tienTieu > m1) break;
                }else{
                    M1 -= 120;
                    EXP1 = EXP1*0.9 + 0.999;
                    checkEXP(EXP1);
                    tienTieu += 120;
                    if(tienTieu > m1) break;
                }

            }
            checkM(M1);

        }else{ // E2 la so chan
            while(true){
                if(HP1 < 200){ // tim thuc an
                    HP1 = HP1*1.3 + 0.999;
                    checkHP(HP1);
                    M1 -= 150;
                    if(M1 <= 0){
                        M1 = 0;
                        break;
                    }
                }else{
                    HP1 = 1.1*HP1 + 0.999;
                    checkHP(HP1);
                    M1 -= 70;
                    if(M1 <= 0){
                        M1 = 0;
                        break;
                    }
                }
                if(EXP1 < 400){ // thue xe
                    M1 -= 200;
                    EXP1 = EXP1*1.13 + 0.999;
                    checkEXP(EXP1);
                    if(M1 <= 0){
                        M1 = 0;
                        break;
                    }
                }else{
                    M1 -= 120;
                    EXP1 = EXP1*1.13 + 0.999;
                    checkEXP(EXP1);
                    if(M1 <= 0){
                        M1 = 0;
                        break;
                    }
                }
                if(EXP1 < 300){// tim hanh ly
                    M1 -= 100;
                    EXP1 = EXP1*0.9 + 0.999;
                    checkEXP(EXP1);
                    if(M1 <= 0){
                        M1 = 0;
                        break;
                    }
                }else{
                    M1 -= 120;
                    EXP1 = EXP1*0.9 + 0.999;
                    checkEXP(EXP1);
                    if(M1 <= 0){
                        M1 = 0;
                        break;
                    }
                }
                break;
            }
        }
    }
    // di bo den chet
    HP1 = HP1*0.83 + 0.999;
    EXP1 = EXP1*1.17 + 0.999;
    checkHP(HP1);
    checkEXP(EXP1);
    // xac suat tim thay hanh ly
    i = 1;
    while(i*i <= EXP1){
        i++;
    }
    x1 = (i-1) * (i-1); x2 = i*i;
    S = (EXP1 - x1) > (x2 - EXP1)?x2:x1;
    if(EXP1 >= S){
        P2 = 100;
    }else{
        P2 = (1.0*EXP1/S + 80)/123 * 100;
    }

    // con duong 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P3 = 0;
    if(E3<10){
        P3 = P[E3];
    }else{
        int sum = 0;
        while(E3 > 0){
            sum += E3%10;
            E3 = E3/10;
        }
        i = sum%10;
        P3 = P[i];
    }

    // di het 3 duong roi
    double p = 0;
    if(P1 == 100 && P2 == 100 && P3 == 100){
        EXP1 = EXP1*0.75 + 0.999;
    }
    else{
        p = (P1 + P2 + P3)/3;
        if(p < 50){
            HP1 = HP1*0.85 + 0.999;
            EXP1 = EXP1*1.15 + 0.999;
        }else{
            HP1 = HP1*0.9 + 0.999;
            EXP1 = EXP1*1.2 + 0.999;
        }
    }
    checkHP(HP1);
    checkEXP(EXP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    checkHP(HP2);
    checkHP(HP1);
    checkEXP(EXP2);
    checkEXP(EXP1);
    if(E3 < 0 || E3 > 99) return -99;
    int I = 0, J = 0; // vi tri gap nhau
    int arr[10][10]; // ma tran duong di cua taxi
    int arr2[10][10]; // ma tran luu diem cua sherlock va watson
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            arr[i][j] = 0;
            arr[i][j] = ((E3*j) + i*2) * (i -j);
            if(arr[i][j] > E3 * 2) I++;
            if(arr[i][j] < -E3) J++;
        }
    }
    if(I > 9){
        int sum = 0;
        while(I > 0){
            sum += I%10;
            I = I/10;
        }
        I = sum;
        if(I > 9){
            int sum = 0;
            while(I > 0){
                sum += I%10;
                I = I/10;
            }
            I = sum;
        }
    }
    if(J > 9){
        int sum = 0;
        while(J > 0){
            sum += J%10;
            J = J/10;
        }
        J = sum;
        if(J > 9){
            int sum = 0;
            while(J > 0){
                sum += J%10;
                J = J/10;
            }
            J = sum;
        }
    }
    // tim arr2
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int m = 0, left = arr[i][j], right = arr[i][j];
            // tim so lon nhat tren duong cheo trai
            int i1 = i, j1 = j;
            while(i1 > 0 && j1 > 0){
                i1--;
                j1--;
            }
            while(i1 <= 9 && j1 <= 9){
                if(arr[i1][j1] > left) left = arr[i1][j1];
                i1++;
                j1++;
            }
            // tim so lon nhat tren duong cheo phai
            int i2 = i, j2 = j;
            while(i2 > 0 && j2 < 9){
                i2--;
                j2++;
            }
            while(i2 <= 9 && j2 >= 0){
                if(arr[i2][j2] > right) right = arr[i2][j2];
                i2++;
                j2--;
            }
            m = max(right, left);
            arr2[i][j] = abs(m);
        }
    }

    if(abs(arr[I][J]) > arr2[I][J]){
        EXP1 = EXP1*0.88 + 0.999;
        HP1 = HP1*0.9 + 0.999;

        EXP2 = EXP2*0.88 + 0.999;
        HP2 = HP2*0.9 + 0.999;

        checkEXP(EXP1);
        checkHP(HP1);
        checkEXP(EXP2);
        checkHP(HP2);

        return arr[I][J];
    }
    else{
        EXP1 = EXP1*1.12 + 0.999;
        HP1 = HP1*1.1 + 0.999;

        EXP2 = EXP2*1.12 + 0.999;
        HP2 = HP2*1.1 + 0.999;

        checkEXP(EXP1);
        checkHP(HP1);
        checkEXP(EXP2);
        checkHP(HP2);

        return arr2[I][J];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    char se[101];
    int length = strlen(s);
    if(length < 8) return -1;
    if(length > 20) return -2;
    int i = 0;
    while(email[i] != '@'){
        se[i] = email[i];
        i++;
    }
    se[i] = '\0';
    int seLength = strlen(se);
    for(int i = 0; i <= length-seLength; i++){
        int j;
        for(j = 0; j < seLength; j++){
            if(s[i+j] != se[j]) break;
        }
        if(j == seLength) return -(300 + i);
    }
    i = 0;
    while(i < length - 2){
        if(s[i] == s[i+1] && s[i] == s[i+2]) return -(400 + i);
        i++;
    }
    int count = 0;
    for(int i = 0; i < length; i++){
        if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') count++;
    }
    if(count == 0) return -5;
    i = 0;
    while(i < length){
        if((s[i]<35 && s[i] != '!') || (s[i]>37 && s[i] < 48) || (s[i]>57 && s[i]<64) || (s[i]>90 && s[i]<97) || s[i]>122) return i;
        i++;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int cnt = 0, index = 0;
    string s = arr_pwds[0];
    string correctPwd = arr_pwds[0];
    int lenCrrPwd = strlen(arr_pwds[0]);
    for(int i = 0; i < num_pwds; i++){
        if(arr_pwds[i] == s) cnt++;
    }
    // tim cnt la so lan xuat hien nhieu nhat
    for(int i = 0; i < num_pwds; i++){
        int a = 0;
        s = arr_pwds[i];
        for(int j = 0; j < num_pwds; j++){
            if(s == arr_pwds[j]) a++;
        }
        if(a > cnt){
            cnt = a;
            correctPwd = s;
            lenCrrPwd = s.length();
            index = i;
        }
    }
    for(int i = 0; i < num_pwds; i++){
        int a = 0;
        s = arr_pwds[i];
        for(int j = 0; j < num_pwds; j++){
            if(s == arr_pwds[j]) a++;
        }
        if(a == cnt){
            if(s.length() > lenCrrPwd){
                correctPwd = s;
                lenCrrPwd = s.length();
                index = i;
            }
        }
    }

    return index;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
