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

void checkHP(int & hp){
    if (hp > 666){hp = 666;}
    if (hp < 0){hp = 0;}
}

void checkEXP(int & exp){
    if (exp > 600){exp = 600;}
    if (exp < 0){exp = 0;}
}

void checkM(int & m){
    if (m > 3000){m = 3000;}
    if (m < 0){m = 0;}
}

void findPersqr(int EXP1, double & p){ // Tim so chinh phuong
    int i = pow(round(sqrt(EXP1)),2);
    if (EXP1 >= i){
        p = 1;
    }
    else {
        p = (double(EXP1/i)+ 80)/123.0;
    }
}

bool checkChar1(string str, int & b){ // Xem ky tu co hop le hay khong
    for (int i = 0; i < str.length(); ++i){
        if ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 64 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || (str[i] >= 35 && str[i] <= 37) || str[i] == 33){

        }
        else {
            b = i;
            return false;
        }
    }
    return true;
}

bool checkChar2(string str, string se){ // Xem co trung chuoi ky tu str trong se hay khong
    if (str.find(se) == std::string::npos){
        return false;
    }
    return true;
}

bool checkChar3(string str, int  & a){ // Xem co nhieu hon 2 ky tu lien ke giong nhau khong
    for (int i = 0; i < str.length() - 2; ++i){
        if (str[i] == str[i+1] && str[i + 1] == str[i + 2]){
            a = i;
            return true;
        }
    }
    return false;
}

bool checkChar4(string str){ // Xem co chua it nhat 1 ky tu dac biet khong
    int a = 0;
    for (int i = 0; i < str.length(); ++i){
        if ((str[i] >= 35 && str[i] <= 37) || str[i] == 33 || str[i] == 64){
            ++a;
        }
    }
    if (a == 0) {return false;}
    return true;
}

bool checkPwds(string str[], string str1, int n){ // Kiem tra xem mat khau nay lan dau xuat hien hay khong
    for (int j = 0; j < n; ++j){
        if (str[j] == str1){
            return false;
        }
    }
    return true;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 <= 3 && e1 >= 0){
        if (e1 == 0){exp2 += 29;}
        else if (e1 == 1){exp2 += 45;}
        else if (e1 == 2){exp2 += 75;}
        else {
            exp2 = exp2 + 29 + 45 + 75;
        }
        int d = e1*3 + exp1*7;
        if (d % 2 == 0){
            exp1 = ceil(float( exp1 + d/200.0));
        }
        else {
            exp1 = ceil(float(exp1 - d/100.0));
        }
    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 <= 19){exp2 += ceil(float(e1/4.0 + 19));}
        else if (e1 <= 49){exp2 += ceil(float(e1/9.0 + 21));}
        else if (e1 <= 65){exp2 += ceil(float(e1/16.0 + 17));}
        else if (e1 <= 79){
            exp2 += ceil(float(e1/4.0 + 19));
            if (exp2 > 200){
                exp2 += ceil(float(e1/9.0 + 21));
            }
        }
        else {
            exp2 += ceil(float(e1/4.0 + 19) + ceil(e1/9.0 + 21));
            if (exp2 > 400){
                exp2 += ceil(float(e1/16.0 + 17));
                exp2 += ceil(float(exp2*0.15));
            }
            
        }
        exp1 -= e1;
    }
    else{
        return -99;
    }
    checkEXP(exp1);
    checkEXP(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
        double p1,p2,p3,p;
    // Path 1
        findPersqr(EXP1,p1);
    // Path 2
        int preM = M1;
        //
        if (E2 >= 0 && E2 <= 99){
            if (E2 % 2 != 0){
                while(M1 > 0.5*preM){
                    if (HP1 < 200){
                        HP1 = ceil(float(float(HP1*1.3)));
                        checkHP(HP1);
                        M1 -= 150;
                    }
                    else {
                        HP1 = ceil(float(HP1*1.1));
                        checkHP(HP1);
                        M1 -= 70;
                    }
                    if (M1 < 0.5*preM){break;}

                    //
                    if (EXP1 < 400){
                        M1 -= 200;
                    }
                    else {
                        M1 -= 120;
                    }
                    EXP1 = ceil(float(EXP1*1.13));
                    checkEXP(EXP1);
                    if (M1 < 0.5*preM){break;}

                    //
                    if (EXP1 < 300){
                        M1 -= 100;
                    }
                    else {
                        M1 -= 120;
                    }
                    EXP1 = ceil(float(EXP1*0.9));
                    checkEXP(EXP1);
                    if (M1 < 0.5*preM){break;}
                }
            }
            else {
                for (int i = 1; i < 2; ++i){
                    if (HP1 < 200){
                        HP1 = ceil(float(HP1*1.3));
                        checkHP(HP1);
                        M1 -= 150;
                    }
                    else {
                        HP1 = ceil(float(HP1*1.1));
                        checkHP(HP1);
                        M1 -= 70;
                    }
                    if (M1 <= 0){break;checkM(M1);} // Neu M1 = 0 thi thoat vong lap
                    //
                    if (EXP1 < 400){
                        M1 -= 200;
                    }
                    else {
                        M1 -= 120;
                    }
                    EXP1 = ceil(float(EXP1*1.13));
                    if (M1 <= 0){break; checkM(M1);}
                    //
                    if (EXP1 < 300){
                        M1 -= 100;
                    }
                    else {
                        M1 -= 120;
                    }
                    EXP1 = ceil(float(EXP1*0.9));
                    checkEXP(EXP1);
                }
            }
            HP1 = ceil(float(HP1*0.83));
            checkHP(HP1);
            EXP1 = ceil(float(EXP1*1.17));
            checkEXP(EXP1);
            findPersqr(EXP1,p2); // Tinh p2 
            // Path 3
            int arrP[10] = {32,47,28,79,100,50,22,83,64,11};
            if (E2 < 10 && E2 >= 0){
                p3 = double(arrP[E2])/100;
            }
            else if (E2 >= 10 && E2 <= 99){
                int i = E2/10 + (E2 - (E2/10)*10);
                int d = i - i/10*10;
                p3 = arrP[d]/100.0;
            }
            else{
                return -99;
            } 

            if (p1 == p2 && p2 == p3 && p3 == 1.0){
                EXP1 = ceil(float(EXP1*0.75));
                checkEXP(EXP1);
            }
            else {
                p = (p1 + p2 + p3)/3.0;
                if (p < 0.5){
                    HP1 = ceil(float(HP1*0.85));
                    EXP1 = ceil(float(EXP1*1.15));
                }
                else {
                    HP1 = ceil(float(HP1*0.9));
                    EXP1 = ceil(float(EXP1*1.2));
                }
            }
        checkHP(HP1);
        checkEXP(EXP1);
        checkM(M1);
        }    
        else {
            return -99;
        }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99){
        return -99;
    }
    // TODO: Complete this function
    int countDuong = 0;
    int countAm = 0;
    int max1 = 0, max2 = 0, Max = 0;
    int arrTax[10][10] = {0};
    for (int j = 0; j < 10; ++j){ //Nhap ma tran Taxi
        for (int i = 0; i < 10; ++i){
            arrTax[i][j] = (E3*j + (i*2))*(i - j);
        }
    }
    for (int j = 0; j < 10; ++j){ // Đếm để tìm i và j
        for (int i = 0; i < 10; ++i){
            if (arrTax[i][j] > E3*2){
                countDuong++;
            }
            if (arrTax[i][j] < -E3){
                countAm++;
            }
        }
    }
        while(countDuong > 9){ // Rút gọn i và j
            int s = countDuong/10 + (countDuong - countDuong/10*10);
            countDuong = s;
        }
        while(countAm> 9){
            int s = countAm/10 + (countAm - countAm/10*10);
            countAm = s;
        }   
        int i = countDuong;
        int j = countAm;
        max1 = arrTax[i][j]; // Giá trị lớn nhất theo chéo trái
        max2 = arrTax[i][j]; // Giá trị lớn nhất theo chéo phải
        if (i >= j){
            for (int b = 0, a = i - j;a < 10 && b < 10 ;++a,++b){
                if (max1 < arrTax[a][b]){
                    max1 = arrTax[a][b];
                }
            }
            if (j <= (9 - i)){
                for (int b = i + j, a = 0; b >= 0 ; ++a, --b){
                    if (max2 < arrTax[a][b]){
                        max2 = arrTax[a][b];
                    }
                }
            }
            else {
                for (int b = 9, a = i + j - b; a <= 9; ++a, --b){
                    if (max2 < arrTax[a][b]){
                        max2 = arrTax[a][b];
                    }
                }
            }
        }
        else {
            for (int a = 0, b = j - i;a < 10 && b < 10 ;++a,++b){
                if (max1 < arrTax[a][b]){
                    max1 = arrTax[a][b];
                }
            }
            if (j <= (9 - i)){
                for (int b = i + j, a = 0; b >= 0 ; ++a, --b){
                    if (max2 < arrTax[a][b]){
                        max2 = arrTax[a][b];
                    }
                }
            }
            else {
                for (int b = 9, a = i + j - b; a <= 9; ++a, --b){
                    if (max2 < arrTax[a][b]){
                        max2 = arrTax[a][b];
                    }
                }
            }
        }
        Max = abs(max(max1,max2)); // Max là giá trị tuyệt đối lớn nhất của max1 và max2
        if (Max >= abs(arrTax[i][j])){
            EXP1 = ceil(float(EXP1*1.12));
            HP1 = ceil(float(HP1*1.1));
            EXP2 = ceil(float(EXP2*1.12));
            HP2 = ceil(float(HP2*1.1));
        }
        else {
            EXP1 = ceil(float(EXP1*0.88));
            HP1 = ceil(float(HP1*0.9));
            EXP2 = ceil(float(EXP2*0.88));
            HP2 = ceil(float(HP2*0.9));
            Max = arrTax[i][j];
        }
    checkEXP(EXP1);
    checkEXP(EXP2);
    checkHP(HP1);
    checkHP(HP2);
    return Max;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string Email(email);
    string S(s);
    string se;
    int result;
    int a = 0; // Vi tri cua ky tu lien ke giong nhau (checkChar3)
    int b = 0; // Vi tri cua ky tu khong hop le (checkChar1)
    se = Email.substr(0,Email.find("@"));
    if ((S.length() >= 8 && S.length() <= 20) && checkChar1(S,b) && !checkChar2(S,se) && !checkChar3(S,a) && checkChar4(S)){
        result = -10;
    }
    else {
        
        if (S.length() < 8){
            result = -1;
        }
        else if (S.length() > 20){
            result = -2;
        }
        else if (checkChar2(S,se)){
            result = - (300 + S.find(se));
        }
        else if (checkChar3(S,a)){
            result = - (400 + a);   
        }
        else if (!checkChar4(S)){
            result = -5;
        }
        else {
            result = b;
        }
    }
    return result;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
   string arrDifPwds[30];
    int arrCountPwds[30] = { 0 };
    int s = 0; // Index of CountPwds
    int v = 0; // Index of DifPwds
    int max = 0; // Max number of CountPwds
    arrDifPwds[0] = arr_pwds[0];
    for (int i = 1; i < num_pwds; ++i){
        if (checkPwds(arrDifPwds,arr_pwds[i],i)){
            ++v;
            arrDifPwds[v] = arr_pwds[i];
        }
    }
    for (int i = 0; i <= v; ++i){
        for (int j = 0; j < num_pwds; ++j){
            if (arrDifPwds[i] == arr_pwds[j]){
                arrCountPwds[i]++;
            }
        }

    }
    string longestPwds = "a";
    for (int i = 0; i <= v; ++i){ //Find the max value countPwds
        if (arrCountPwds[i] > max){
            max = arrCountPwds[i];
        }
    }
    for (int i = 0; i <= v; ++i){ // Find the longest pass
        if (arrCountPwds[i] == max && arrDifPwds[i].length() > longestPwds.length()){
            longestPwds = arrDifPwds[i];
        }
    }
    int index = 0; // Index of longestPwds in arr_pwds
    for (int i = 0; i < num_pwds; ++i){
        if (longestPwds == arr_pwds[i]){
            index = i;
            break;
        }
    }
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////