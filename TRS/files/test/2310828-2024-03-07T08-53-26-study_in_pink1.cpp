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
int setHP(int HP){
    if(HP < 0) HP = 0;
    if(HP > 666) HP = 666;
    return HP;
}

int setEXP(int EXP){
    if(EXP < 0) EXP = 0;
    if(EXP > 600) EXP = 600;
    return EXP;
}

int setM(int M){
    if(M < 0) M = 0;
    if(M > 3000) M = 3000;
    return M;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1){
    if(e1 < 0 || e1 > 99) return -99;
    if(e1 >= 0 && e1 <= 3){
        if(e1 == 0) exp2 += 29;
        if(e1 == 1) exp2 += 45;
        if(e1 == 2) exp2 += 75;
        if(e1 == 3) exp2 += 29 + 45 + 75;

        int D = e1*3 + exp1*7;
        if(D%2 == 0){
            if(D%200 == 0) exp1 += D/200;
            else exp1 += D/200 + 1; //lam tron len
        }
        else{
            exp1 -= D/100;
        }
    }

    if(e1 >= 4 && e1 <= 99){
        bool full = false;
        if(e1 >= 4 && e1 <= 19){
            if(e1%4 == 0) exp2 += (e1/4 + 19);
            else exp2 += (e1/4 + 19 + 1); //lam tron len
        }
        if(e1 >=20 && e1 <= 49){
            if(e1%9 == 0) exp2 += (e1/9 + 21);
            else exp2 += (e1/9 + 21 + 1);
        }
        if(e1 >= 50 && e1 <= 65){
            if(e1%16 == 0) exp2 += (e1/16 + 17);
            else exp2 += (e1/16 + 17 + 1);   
        }
        if(e1 >= 66 && e1 <= 79){
            if(e1%4 == 0) exp2 += (e1/4 + 19);
            else exp2 += (e1/4 +19 + 1);
            if(exp2 > 200){
                if(e1%9 == 0) exp2 += (e1/9 + 21);
                else exp2 += (e1/9 + 21 + 1);
            }
        }
        if(e1 >= 80 && e1 <= 99){
            if(e1%4 == 0) exp2 += (e1/4 + 19);
            else exp2 += (e1/4 +19 + 1);
            if(e1%9 == 0) exp2 += (e1/9 + 21);
            else exp2 += (e1/9 + 21 + 1);
            if(exp2 > 400){
                if(e1%16 == 0) exp2 += (e1/16 + 17);
                else exp2 += (e1/16 + 17 + 1);
                full= true;
            }
        }
        
        if(full){
            exp2 = exp2*2 - int(exp2*0.85);
        }
        exp1 -=  e1;
    }

    exp1 = setEXP(exp1);
    exp2 = setEXP(exp2);
    return exp1 + exp2;
}
//----------------------------------------------------------------//

double xs(int EXP1){
    double p1;
    int temp = sqrt(EXP1);
    if(EXP1 - pow(temp, 2) < pow(temp+1, 2) - EXP1) p1 = 1;
    else p1 = (EXP1/pow(temp+1, 2) + 80)/123;
    return p1;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
    //con duong 01
    double p1;
    p1 = xs(EXP1);
    //con duong 02
    double p2;
    int half = (M1+1)/2;
    if(E3%2 == 1){
        int charge = 0;
        while(charge <= half){
            if(HP1 < 200){
                HP1 = setHP(HP1*2 - int(HP1*0.7));
                M1 = setM(M1 - 150);
                charge += 150;
            }else{
                HP1 = setHP(HP1*2 - int(HP1*0.9));
                M1 = setM(M1 - 70);
                charge += 70;
            }

            if(charge > half) break;
            if(EXP1 < 400) {
                M1 = setM(M1 - 200);
                charge += 200;
            }
            else {
                M1 = setM(M1 - 120);
                charge += 120;
            }
            EXP1 = setEXP(EXP1*2 - int(EXP1*0.87));

            if(charge > half) break;
            if(EXP1 < 300) {
                M1 = setM(M1 - 100);
                charge += 100;
            }else{
                M1 = setM(M1 - 120);
                charge += 120;
            }
            EXP1 = setEXP(EXP1 - int(EXP1*0.1));
        }
    }else{
        while(true){
            if(HP1 < 200){
                HP1 = setHP(HP1*2 - int(HP1*0.7));
                M1 = setM(M1 - 150);
            }else{
                HP1 = setHP(HP1*2 - int(HP1*0.9));
                M1 = setM(M1 - 70);
            }

            if(M1 <= 0) break;
            if(EXP1 < 400) M1 = setM(M1 - 200);
            else M1 = setM(M1 - 120);
            EXP1 = setEXP(EXP1*2 - int(EXP1*0.87));

            if(M1 <= 0) break;
            if(EXP1 < 300) M1 = setM(M1 - 100);
            else M1 = setM(M1 - 120);            
            EXP1 = setEXP(EXP1 - int(EXP1*0.1));           
            break;
        }
    }
    HP1 = setHP(HP1 - int(HP1*0.17));
    EXP1 = setEXP(EXP1*2 - int(EXP1*0.83));
    p2 = xs(EXP1);

    //con duong 03
    double p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int idx = (E3/10 + E3%10) % 10;
    double p3 = p[idx]/100;

    //tong ket
    if(p1 == 1 && p2 == 1 && p3 == 1) {
        EXP1 -= int(EXP1*0.25);
    }else{
        if((p1+p2+p3)/3 < 0.5){
            HP1 -= int(HP1*0.15);
            EXP1 = setEXP(EXP1*2 - int(EXP1*0.85));
        }else{
            HP1 -= int(HP1*0.1);
            EXP1 = setEXP(EXP1*2 - int(EXP1*0.8));
        }
    }
    return HP1 + EXP1 + M1;
}
//----------------------------------------------------------------//

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int arr[10][10];
    int di = 0, dj = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            arr[i][j] = ((E3*j) + (i*2)) * (i-j);
            if(arr[i][j] > E3*2) di++;
            if(arr[i][j] < E3*(-1)) dj++;
        }
    }
    while(di > 9) di = (di%10) + (di/10);
    while(dj > 9) dj = (dj%10) + (dj/10);
    int TX = arr[di][dj], SL = arr[di][dj];

    //diem so of Sherlock
    for(int i = 0; i < 10; i++){ 
        if(i + (dj-di) >= 0 && i + (dj-di) < 10){
            if(arr[i][i+(dj-di)] > SL) SL = arr[i][i+(dj-di)];
        }
    }
    for(int i = 0; i < 10; i++){ 
        if(dj + (di-i) >= 0 && dj + (di-i) < 10){
            if(arr[i][dj+(di-i)] > SL) SL = arr[i][dj+(di-i)];
        }
    }
    if(abs(TX) > abs(SL)){
        HP1 = setHP(HP1 - int(HP1*0.1));
        HP2 = setHP(HP2 - int(HP2*0.1));
        EXP1 = setEXP(EXP1 - int(EXP1*0.12));
        EXP2 = setEXP(EXP2 - int(EXP2*0.12));
        return TX;
    }else{
        HP1 = setHP(HP1*2 - int(HP1*0.9));
        HP2 = setHP(HP2*2 - int(HP2*0.9));
        EXP1 = setEXP(EXP1*2 - int(EXP1*0.88));
        EXP1 = setEXP(EXP1*2 - int(EXP1*0.88));
        return SL;
    }
}
//----------------------------------------------------------------//

bool checkCharacter(char c){
    if(c >= '0' && c <= '9') return true;
    if(c >= 'a' && c <= 'z') return true;
    if(c >= 'A' && c <= 'Z') return true;
    if(c == '@' || c == '#' || c == '%' || c =='$' || c == '!') return true;
    return false;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int length = strlen(s);
    if(length < 8) return -1; 
    if(length > 20) return -2; 

    bool spec = false;
    string se = ""; //chuoi trc @
    string temp = ""; //mat khau
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '@' || s[i] == '#' ||  s[i] == '%' || s[i] == '$' || s[i] == '!') spec = true;
        temp.push_back(s[i]);
    }
    for(int i = 0; i < strlen(email); i++){
        if(email[i] == '@') break;
        se.push_back(email[i]);
    }
    if(temp.find(se) != -1){
        return -(temp.find(se) + 300);
    }
    for(int i = 0; i < length - 1; i++) {
        if(temp[i] == temp[i+1]) 
        return -(400+i); 
    }
    if(!spec) return -5; 
    for(int i = 0; i < length; i++) {
        if(!checkCharacter(temp[i])) return i;
    }
    return -10; 

}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max = 0, maxlength = 0, idx = 0;
    int check[num_pwds] = {};
    string ss = "";
    for(int i = 0; i < num_pwds; i++) {
        if(check[i] == 1) continue;
        int dem = 0;
        string temp = arr_pwds[i];
        for(int j = 0; j < num_pwds; j++) {
            if(temp == arr_pwds[j]){
                check[j] = 1;
                dem++;
            }
        }
        if(dem > max) {
            max = dem;
            ss = arr_pwds[i];
            maxlength = ss.length();
            idx = i;
        }
        else if(dem == max){
            if(strlen(arr_pwds[i]) > maxlength) {
                ss = arr_pwds[i];
                maxlength = ss.length();
                idx = i;
            }
        }
    }
    return idx;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////