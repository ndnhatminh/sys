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

int nearestscp(int n){
    int lowersquare = 1, uppersquare = 1;
    for (int i = 0; i <= n; i++){
        if (i*i <= n){
            lowersquare = i*i;
        }
    }
    for (int i = n; i >= 1; i--) {
        if (i * i >= n) {
        uppersquare = i * i;
        }
    }
    if (n - lowersquare <= uppersquare - n){
        return lowersquare;
    }
    else return uppersquare;
}
int tonghaiso(int n){
    int chuc = n / 10;
    int donvi = n % 10;
    return chuc + donvi;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;
    int result;
    if (e1 >= 0 && e1 <= 3){
        if (e1 == 0)
            exp2 += 29;
        else if (e1 == 1)
            exp2 += 45;
        else if (e1 == 2)
            exp2 += 75;
        else if (e1 == 3)
            exp2 += 149;
        if (exp2 > 600) exp2 = 600; 
        int D = ceil(double(e1*3.0 + exp1*7.0));
        if (D % 2 == 0){
            exp1 += ceil(double(D/200.0));
            if (exp1 > 600) exp1 = 600;
        }
        else{
            exp1 -= D/100;
            if (exp1 < 0) exp1 = 0;
        }
        result = exp1 + exp2;
    }
    else if (e1 >= 4 && e1 <= 99){
        if (e1 >= 4 && e1 <= 19)
            exp2 += ceil(double(e1/4.0 + 19.0));
        else if (e1 >= 20 && e1 <= 49)
            exp2 += ceil(double(e1/9.0 + 21.0));
        else if (e1 >= 50 && e1 <= 65)
            exp2 += ceil(double(e1/16.0 + 17.0));
        else if (e1 >= 66 && e1 <= 79){
            exp2 += ceil(double(e1/4.0 + 19.0));
            if (exp2 > 200)
                exp2 += ceil(double(e1/9.0 + 21.0));
        }
        else if (e1 >= 80 && e1 <= 99){
            exp2 += ceil(double(e1/4.0 + 19.0));
            exp2 += ceil(double(e1/9.0 + 21.0));
            if (exp2 > 400){
                exp2 += ceil(double(e1/16.0 + 17.0));
                exp2 = ceil(double(exp2 *1.15));
            }
        }
        if (exp2 > 600) exp2 = 600;
        exp1 -= e1; if (exp1 < 0) exp1 = 0;
        result = exp1 + exp2;
    }
    return result;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    double P1 = 0, P2 = 0, P3 = 0;
    int paid = 0, budget = M1 / 2;
    //PATH 1
    int S = nearestscp(EXP1);
    if (EXP1 >= S)
        P1 = 1;
    else P1 = (static_cast<double>(EXP1/S) + 80.0) / 123.0;
    //PATH 2
    if (E3 % 2 != 0){
        while (paid < budget){
            if (paid < budget){ //mua food
                if (HP1 < 200){
                    HP1 = ceil(double(HP1 * 1.3)); 
                    paid += 150;
                }
                else{
                    HP1 = ceil(double(HP1 * 1.1)); if (HP1 > 666) HP1 = 666;
                    paid += 70;  
                }
            }
            if (paid < budget){ //rent vehicle
                if (EXP1 < 400){
                    paid += 200;
                }
                else paid += 120;
                EXP1 = ceil(double(EXP1 * 1.13)); if (EXP1 > 600) EXP1 = 600;
            }
            if (paid < budget){ //homeless
                if (EXP1 < 300) paid += 100;
                else paid += 120;
                EXP1 = ceil(double(EXP1 * 0.9));
            }
        }
        M1 -= paid;
    }
    else{
        if (M1 > 0){
            if (HP1 < 200){
                HP1 = ceil(double(HP1 * 1.3)); 
                M1 -= 150;
            }
            else{
                HP1 = ceil(double(HP1 * 1.1)); if (HP1 > 666) HP1 = 666;
                M1 -= 70;  
            }
            if (M1 < 0) M1 = 0;
        }
        if (M1 > 0){
            if (EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            if (M1 < 0) M1 = 0;
            EXP1 = ceil(double(EXP1 * 1.13)); if (EXP1 > 600) EXP1 = 600;
        }
        if (M1 > 0){
            if (EXP1 < 300) M1 -= 100;
            else M1 -= 120;
            EXP1 = ceil(double(EXP1 * 0.9));
            if (M1 < 0) M1 = 0;
        }
    }
    HP1 = ceil(double(HP1 * 0.83));
    EXP1 = ceil(double(EXP1 * 1.17)); if (EXP1 > 600) EXP1 = 600;
    S = nearestscp(EXP1);
    if (EXP1 >= S)
        P2 = 1;
    else P2 = (static_cast<double>(EXP1/S) + 80) / 123;
    //PATH 3
    int Prob[10] = {32,47,28,79,100,50,22,83,64,11};
    int i = 0;
    if (E3 < 10) i = E3;
    else i = tonghaiso(E3) % 10;
    P3 = Prob[i];
    if (P1 == P2 == P3 == 1) EXP1 = ceil(double(EXP1 * 0.75));
    int result = (P1 + P2 + P3) / 3;
    if (result < 0.5){
        HP1 = ceil(double(HP1 * 0.85));
        EXP1 = ceil(double(EXP1 * 1.15)); if (EXP1 > 600) EXP1 = 600;
    }
    else{
        HP1 = ceil(double(HP1 * 0.9));
        EXP1 = ceil(double(EXP1 * 1.2)); if (EXP1 > 600) EXP1 = 600;
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    int result;
    int map[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
    int countplus = 0, countminus = 0, x = 0, y = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (map[i][j] > E3 * 2) countplus++;
            else if (map[i][j] < -E3) countminus++; 
        }
    }
    if (countplus < 10) x = countplus;
    else{
        int tong = tonghaiso(countplus);
        x = tonghaiso(tong);
    }
    if (countminus < 10) y = countminus;
    else{
        int tong = tonghaiso(countminus);
        y = tonghaiso(tong);
    }
    //cheo trai
    int i = x;
    int j = y;
    int max = 0;
    while (i >= 0 && i < 10 && j < 10 && j >= 0){
        if (map[i][j] > max) max = map[i][j]; 
        i--;
        j++;
    }
    i = x, j = y;
    while (i >= 0 && i < 10 && j < 10 && j >= 0){
        if (map[i][j] > max) max = map[i][j];
        i++;
        j--;
    }
    //cheo phai
    i = x, j = y;
    while (i >= 0 && i < 10 && j < 10 && j >= 0){
        if (map[i][j] > max) max = map[i][j]; 
        i--;
        j--;
    }
    i = x, j = y;
    while (i >= 0 && i < 10 && j < 10 && j >= 0){
        if (map[i][j] > max) max = map[i][j];
        i++;
        j++;
    }
    if (abs(map[x][y]) < max){
        EXP1 = ceil(double(EXP1 * 1.12));
        HP1 = ceil(double(HP1 * 1.1));
        EXP2 = ceil(double(EXP2 * 1.12));
        HP2 = ceil(double(HP2 * 1.1));
        result = max;
    }
    else{
        EXP1 = ceil(double(EXP1 * 0.88));
        HP1 = ceil(double(HP1 * 0.9));
        EXP2 = ceil(double(EXP2 * 0.88));
        HP2 = ceil(double(HP2 * 0.9));
        result = map[x][y];
    }
    if (HP1 > 666) HP1 = 666;
    if (HP2 > 666) HP2 = 666;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP2 > 600) EXP2 = 600;
    return result;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int result = -10;
    string mail(email);
    string pass(s);
    //too short
    if (pass.size() < 8 && result == -10) result = -1;
    //too long
    else if (pass.size() > 20 && result == -10) result = -2;
    //chuoi con
    string se = mail.substr(0, mail.find("@"));
    int check = pass.find(se, 0);
    if(check < pass.size() && result == -10) result = -(300 + check);
    //trung lap
    if (result == -10){
        for (int i = 0; i < pass.size()-2; i++){
            char word = pass[i];
            char next = pass[i+1];
            char further = pass[i+2];
            if (word == next && next == further){
                result = -(400 + i);
                break;
            }
        }
    }
    //no special
    if (result == -10){
        int special = 0;
        for (int i = 0; i < pass.size(); i++){
            if (pass[i] == '@' || pass[i] == '#' || pass[i] == '$' || pass[i] =='%' || pass[i] =='!')
                special = 1;
        }
        if (special == 0) result = -5;
    }
    //invalid type
    for (int i = 0; i < pass.size(); i++){
        if (pass[i] < '@' || pass[i] > 'Z')
            if( pass[i] < 'a' || pass[i] > 'z') 
                if(pass[i] != 33)
                    if(pass[i] < 35 || pass[i] > 37)
                        if (pass[i] < '0' || pass[i] >'9')
                            if( result == -10)
                                result = i;
    }
    return result;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int most_appear = 0;
    int first_appear = 0;
    const char *most_pass;
    for (int i = 0; i < num_pwds; i++){
        int count = 0;
        for (int j = 0; j < num_pwds; j++)
            if (arr_pwds[i] == arr_pwds[j]) count++;
        if (count > most_appear){
                most_appear = count;
                most_pass = arr_pwds[i];
                first_appear = i;
            }
        else if (count == most_appear){
            if (most_pass != arr_pwds[i]){
                if (strlen(arr_pwds[i]) > strlen(most_pass)){
                    first_appear = i;
                    most_pass = arr_pwds[i];
                }
            }
        }
    }
    return first_appear;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////