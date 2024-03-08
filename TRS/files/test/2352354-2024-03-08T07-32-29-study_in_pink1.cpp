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

//HP
int hpf(double hp) {
    if (hp >= 666) {
        hp = 666;
    } else if (hp <= 0) {
        hp = 0;
    } else {
        hp = ceil (hp-0.000001);
    }
    return hp;
}
//EXP
int expa(double exp) {
    if (exp < 0) exp = 0;
    else if (exp > 600) exp = 600;
    else exp = ceil(exp - 0.0000001);
    return exp;
}
//M
int mf(double m) {
    if (m >= 3000) {
        m = 3000;
    } else if (m <= 0) {
        m = 0;
    } else {
        m = ceil(m-0.0000001);
    }
    return m;
}
void task1check(int &exp1, int &exp2) {
    exp1 = expa(exp1);
    exp2 = expa(exp2);
}
void task2check(int &hp1, int &exp1, int &m1) {
    exp1 = expa(exp1);
    hp1 = hpf(hp1);
    m1 = mf(m1);
}
void task3check(int &exp1, int &exp2, int &hp1, int &hp2) {
    exp1 = expa(exp1);
    exp2 = expa(exp2);
    hp1 = hpf(hp1);
    hp2 = hpf(hp2);
}
// int findMax(int taxiPoint[10][10], int x, int y) {
//     int max = taxiPoint[x][y];
//     int hangf = x, cotf = y;

//     while (true) { // tren trai
//         hangf--;
//         cotf--;
//         if (max < taxiPoint[hangf][cotf]) max = taxiPoint[hangf][cotf];
//         if (hangf == 0 || cotf == 0) break;
//     }

//     hangf = x; cotf = y;
//     while (true) { // tren phai
//         hangf--;
//         cotf++;
//         if (max < taxiPoint[hangf][cotf]) max = taxiPoint[hangf][cotf];
//         if (hangf == 0 || cotf == 9) break;
//     }

//     hangf = x; cotf = y;
//     while (true) { // duoi trai
//         hangf++;
//         cotf--;
//         if (max < taxiPoint[hangf][cotf]) max = taxiPoint[hangf][cotf];
//         if (hangf == 9 || cotf == 0) break;
//     }

//     hangf = x; cotf = y;
//     while (true) { // duoi phai
//         hangf++;
//         cotf++;
//         if (max < taxiPoint[hangf][cotf]) max = taxiPoint[hangf][cotf];
//         if (hangf == 9 || cotf == 9) break;
//     }
    
//     max = abs(max);
//     return max;
// }
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    //Case 1
    if (e1 < 0 || e1>99) return -99;
    task1check(exp1, exp2);

    if (e1 >= 0 && e1 <4) {
        if (e1==0) exp2 = expa(exp2+ 29.0);
        else if (e1==1) exp2 = expa(exp2 + 45.0);
        else if (e1==2) exp2 = expa(exp2 + 75.0);
        else if (e1==3) exp2 = expa(exp2 + 149.0);
        int D = e1*3.0 + exp1*7.0;
        if (D%2 == 1) {
            exp1 = expa(exp1 - static_cast<double>(D)/100.0);
        } else {
            exp1 = expa(exp1 + static_cast<double>(D)/200.0);
        }
        exp1 = expa(exp1);
    } else {
        if (e1 >= 4 && e1 < 20) exp2 = expa(exp2 + static_cast<double>(e1)/4.0 + 19);
        else if (e1 >= 20 && e1 < 50) exp2 = expa(exp2 + static_cast<double>(e1)/9.0 + 21);
        else if (e1 >= 50 && e1 < 66) exp2 = expa(exp2 + static_cast<double>(e1)/16.0 + 17);
        else if (e1 >= 66 && e1 < 80) {
            exp2 = expa(exp2 +static_cast<double>(e1)/4.0 +19);
            if (exp2>200) { exp2 = expa(exp2+ static_cast<double>(e1)/9.0 + 21);
            // } else {
            //     exp2 = expa(exp2 + e1/4.0 + 19);
            //     exp2 = expa(exp2 + e1/9.0 + 21);
            }
        }
        else if (e1 >=80 && e1 <= 99) {
            exp2 = expa(exp2 + static_cast<double>(e1)/4.0 +19);
            exp2 = expa(exp2 + static_cast<double>(e1)/9.0 +21);
            if (exp2>400) {
                exp2 = expa(exp2 + static_cast<double>(e1)/16.0 + 17);
                exp2 = expa(exp2 + exp2*0.15);
            }
        }
        
        exp1 = expa(exp1-e1);
    }
        return exp1 + exp2;
    }
    
    // Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
        //case 1
    if ((E2 < 0 || E2 > 99)) return -99;
    task2check(HP1, EXP1, M1);
    bool countchan = true;
    int DeFaultMoney = M1;
    int S;
    S = round(sqrt(EXP1));
    S = (S*S);
    double P1;
    if (EXP1>=S) {
        P1=1;
    } else {
        P1= ((EXP1/static_cast<double>(S) + 80)/123.0);
    }
    while (countchan) {
        if (M1 == 0) break;
        if (HP1<200) {
            HP1 = hpf(HP1*1+HP1*0.3);
            M1 = mf(M1 - 150);
        } else {
            HP1 = hpf(1*HP1+0.1*HP1);
            M1 = mf(M1-70);
        }
        if (((E2 % 2 == 0) && (M1 == 0)) || ((E2 % 2 != 0) && (M1 < 0.5 * DeFaultMoney))) break;
        if (EXP1<400) {
            M1 = mf(M1-200);
            EXP1 = expa(EXP1*1+EXP1*0.13);
        } else {
            M1 = mf(M1-120);
            EXP1 = expa(EXP1*1+EXP1*0.13);
        }
        if (((E2%2 == 0) && (M1 == 0)) || ((E2%2 != 0)&&(M1 < 0.5*DeFaultMoney))) break;
        if (EXP1<300){
            M1 = mf(M1-100);
            EXP1 = expa(EXP1*0.9);
        } else {
            M1 = mf(M1-120);
            EXP1 = expa(EXP1*0.9);
        }
        if (((E2%2 == 0) && (M1 == 0)) || ((E2%2 != 0)&&(M1 < 0.5*DeFaultMoney))) break;
        if (E2%2!=1) countchan = false;
    }
    HP1 = hpf(0.83*HP1);
    EXP1 = expa(1*EXP1+0.17*EXP1);
    S = round(sqrt(EXP1));
    S = (S*S);
    double P2;
        if (EXP1>=S) {
            P2 = 1;
        } else { P2=((EXP1/static_cast<double>(S) +80)/123.0);
        }
    //case 3
        double P3[10] = {32,47,28,79,100,50,22,83,64,11};
        int i = (E2 % 10 + E2 / 10) % 10;
    if (P1!= 1||P2 != 1||P3[i]!= 100) {
        double trb = (P1+P2+P3[i]/100.0) / 3.0;
            if (trb<0.5) {
                HP1 = hpf(0.85*HP1);
                EXP1 = expa(1*EXP1 + 0.15*EXP1);
    } else {
            HP1 = hpf(0.9*HP1);
            EXP1 = expa(1*EXP1 + 0.2*EXP1);
        }
    } else {
        EXP1 = expa(0.75*EXP1);
    }
    return HP1 + EXP1 + M1;
}
    
    // Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3<0 || E3>99){
        return -99;
    }
    task3check(EXP1, EXP2, HP1, HP2);
    const int hang = 10, cot = 10;
    int taxilocate[hang][cot];
    
    for (int a=0; a < hang; ++a) {
        for (int b = 0; b < cot; ++b) {
            taxilocate[a][b] = ((E3*b) + (a*2)) * (a-b);
            // cout << setw(6) << taxilocate[a][b];
        }
        // cout << endl;
    }
    int greaternum = 0, smallernum = 0;
    for (int a = 0; a < hang; ++a) {
        for (int b = 0; b < cot; ++b) {
            if (taxilocate[a][b] > (E3*2)){
                greaternum += 1;
            }
            if (taxilocate[a][b] < -E3) {
                smallernum += 1;
            }
        }
    }
    int hangup = (greaternum%10 + greaternum/10) % 10 + (greaternum%10 + greaternum/10) / 10;
    int cotup = (smallernum%10 + smallernum/10) % 10 + (smallernum%10 + smallernum/10) /10;
    // cout << "cotup: " << cotup << endl;
    // cout << "hangup: " << hangup << endl;
    // code goes here

    int max = taxilocate[hangup][cotup];
    int hangf = hangup, cotf = cotup;

    while (true) { // tren trai
        if (hangf == 0 || cotf == 0) break;
        hangf--;
        cotf--;
        if (max < taxilocate[hangf][cotf]) max = taxilocate[hangf][cotf];
    }

    hangf = hangup; cotf = cotup;
    while (true) { // tren phai
        if (hangf == 0 || cotf == 9) break;
        hangf--;
        cotf++;
        if (max < taxilocate[hangf][cotf]) max = taxilocate[hangf][cotf];
    }

    hangf = hangup; cotf = cotup;
    while (true) { // duoi trai
        if (hangf == 9 || cotf == 0) break;
        hangf++;
        cotf--;
        if (max < taxilocate[hangf][cotf]) max = taxilocate[hangf][cotf];
    }

    hangf = hangup; cotf = cotup;
    while (true) { // duoi phai
        if (hangf == 9 || cotf == 9) break;
        hangf++;
        cotf++;
        if (max < taxilocate[hangf][cotf]) max = taxilocate[hangf][cotf];
    }

    // cout << max << endl;

    max = abs(max);

    if (abs(taxilocate[hangup][cotup]) > max) {
        HP1 = hpf(HP1*0.9);
        EXP1 = expa(EXP1*0.88);
        HP2 = hpf(HP2*0.9);
        EXP2 = expa(EXP2*0.88);
    } else {
        HP1 = hpf(HP1 + HP1*0.1);
        EXP1 = expa(EXP1 + EXP1*0.12);
        HP2 = hpf(HP2 + HP2*0.1);
        EXP2 = expa(EXP2 + EXP2*0.12);
    }
    // // // // // // //
    if (max >= abs(taxilocate[hangup][cotup])) return max;
    else return taxilocate[hangup][cotup];
}

// Task 4
int validity(const string& s){
    int value = 0;
    // Kiểm tra các điều kiện khác
    bool hasSpecialChar = false;
    char prevChar = '\0';
    int passwordLength = s.length();
    for (int i = 0; i < passwordLength; i++) {
        char c = s[i];
        if (!(!isalnum(c) && c != '@' && c != '#' && c != '%' && c != '$' && c != '!')) {
//            value = -5; // Không chứa ký tự đặc biệt
            continue;
        }
        if (!hasSpecialChar && (c == '@' || c == '#' || c == '%' || c == '$' || c == '!')) {
            hasSpecialChar = true;
            value = 0;
        }
        if ((!isalnum(c) && c != '@' && c != '#' && c != '%' && c != '$' && c != '!')) {
            value = i; // ky tu la
            break;
        }
        prevChar = c;
    }
    return value;
}
int threeSame(const char* s){
    int a = -1;
    for (int i = 0; i < strlen(s)-2; i++){
        if (s[i] == s[i+1] && s[i] == s[i+2]){
            a = i;
            break;
        }
    }
    return a;
}
int checkPassword(const char *s, const char *email) {
    // Lấy chuỗi se từ email
    // Tìm kiếm ký tự '@'
    int MAX = 100;
        char se[MAX];
        int at;
        for (int i = 0; i < strlen(email); i++){
            if (email[i] == '@'){
                at = i;
                break;
            }
        }
        strncpy(se, email, at);
        se[at] = '\0';
    int passwordLength = strlen(s);
    const char *loopSE=strstr(s,se);
    int value =0;
       if (passwordLength < 8) {
           return -1; // Độ dài ngắn hơn độ dài tối thiểu
       }else if (passwordLength > 20) {
           return -2; // Độ dài dài hơn độ dài tối đa
       }else if (loopSE != nullptr) {
           value = -(300 + loopSE-s); // Chứa chuỗi se
       }else if(threeSame(s) != -1){
           value = -(400 + threeSame(s));
       }
       else if (validity(s)==-5){
           value  = -5;
       }
       else if(validity(s)!=-5){
           value = validity(s);
       }else value = -10;

    return value;
   }
// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    int* countArr = new int[num_pwds];
    int i = 0, j = 1, counter = 1;

    string *copyarr_pwds = new string[num_pwds];

    for (int i = 0; i < num_pwds; i++) {
        copyarr_pwds[i] = arr_pwds[i];
    }

    while (true) {
        if (copyarr_pwds[i] == copyarr_pwds[j]) {
            counter++;
        }
        if (j >= num_pwds - 1) {
            countArr[i] = counter;
            counter = 1;
            if (i >= num_pwds - 1) break;
            i++;
            j = i + 1;
        }
        else j++;
    }

    int pwd_location = 0;
    for (int i = 1; i < num_pwds; i++) {
        if (countArr[i] > countArr[pwd_location]) pwd_location = i;
        else if ((countArr[i] == countArr[pwd_location]) && (copyarr_pwds[i].length() > copyarr_pwds[pwd_location].length())) pwd_location = i;
    }

    delete[] countArr;
    delete[] copyarr_pwds;

    return pwd_location;
}
    
    ////////////////////////////////////////////////
    /// END OF STUDENT'S ANSWER
    ////////////////////////////////////////////////
