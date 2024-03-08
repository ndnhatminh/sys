#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

int checkexp(int exp){
    if (exp < 0){
        return 0;
    }
    else if(exp > 600){
        return 600;
    }
    return exp;
}
int checkhp(int hp){
    if (hp < 0){
        return 0;
    }
    else if (hp > 666){
        return 666;
    }
    return hp;
}
int checkmoney(int money){
    if (money < 0){
        return 0;
    }
    else if (money > 3000){
        return 3000;
    }
    return money;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1){
    // TODO: Complete this function
    if ((e1 <0) || (e1 > 99))
        return -99;
    exp1 = checkexp(exp1);
    exp2 = checkexp(exp2);
    if ((e1 >= 0) && (e1 <= 3)){
        int D = e1 * 3 + exp1 * 7;
        if (e1 == 0){
            exp2 += 29;
            }
        else if (e1 == 1){
            exp2 += 45;
            }
        else if (e1 == 2){
            exp2 += 75;
            }
        else if (e1 == 3){
            exp2 = exp2 + 29 + 45 + 75;
            }
        if (D % 2 == 0){
            exp1 = exp1 + ceil(double(D) / 200);
        }
        else{
            exp1 = exp1 - D / 100;
        }
        exp1 = checkexp(exp1);
        exp2 = checkexp(exp2);
    }
    else if ((e1 >= 4) && (e1 <= 99)){
        if ((e1 >= 4) && (e1 <= 19)){
            exp2 = exp2 + (ceil(double(e1) / 4) + 19); 
        }
        else if (e1 >= 20 && e1 <= 49){
            exp2 = exp2 + (ceil(double(e1) / 9) + 21); 
        }
        else if (e1 >= 50 && e1 <= 65){
            exp2 = exp2 + (ceil(double(e1) / 16) + 17); 
        }
        else if (e1 >= 66 && e1 <= 79){
            exp2 = exp2 + (ceil(double(e1) / 4) + 19);
            exp2 = checkexp(exp2);
            if (exp2 > 200){
                exp2 = exp2 + (ceil(double(e1) / 9) + 21);
                exp2 = checkexp(exp2);
            }
        }
        else if ((e1 >= 80) && (e1 <= 99)) {
            exp2 = exp2 + (ceil(double(e1) / 4) + 19);
            exp2 = checkexp(exp2);
            exp2 = exp2 +  (ceil(double(e1) / 9)+ 21);
            exp2 = checkexp(exp2);
            if (exp2 > 400){
                exp2 = exp2 + (ceil(double(e1) / 16) + 17);
                exp2 = ceil(double(exp2) * 115 / 100);
            }
        }
        exp1 -= e1;
        exp1 = checkexp(exp1);
        exp2 = checkexp(exp2);
    }
    return exp1 + exp2;
}

// Task 2
bool chinhphuong(int num){
    if ((sqrt(num) - floor(sqrt(num))) != 0)
        return false;
    return true;
}
int timso(int exp1){
    if (chinhphuong(exp1)){
        return exp1;
    }
    int up = -1, down = -1;
    int n1;
    n1 = exp1 + 1;
    while (true){
        if (chinhphuong(n1)){
            up = n1;
            break;
        }
        else
            n1++;
    }
    n1 = exp1 - 1;
    while (true){
        if (chinhphuong(n1)){
            down = n1;
            break;
        }
        else
            n1--;
    }
    if ((up - exp1) > (exp1 - down))
        return down;
    return up;
}
double path1(int exp1){
    int S;
    S = timso(exp1);
    if (exp1 >= S) return 1;
    double k = (double(exp1) / S + 80) / 123;
    return k;
}
double subpath2(int & HP1, int & EXP1, int & M1, int E2, int E2_50){
    if (HP1 < 200){
        HP1 = ceil(double(HP1)*130/100);
        M1 -= 150;
    }
    else{
        HP1 = ceil(double(HP1)*110/100);
        M1 -= 70;
    }
    HP1 = checkhp(HP1);
    M1 = checkmoney(M1);
    if (M1 == 0)
        return M1;
    if ((E2 % 2 == 1) && (E2_50 > M1)){
        return M1;
    }
    if (EXP1 < 400){
        EXP1 = ceil(double(EXP1)*113/100);
        M1 -= 200;
    }
    else{
       EXP1 = ceil(double(EXP1)*113/100);
       M1 -= 120;
    }
    EXP1 = checkexp(EXP1);
    M1 = checkmoney(M1);
    if (M1 <= 0)
        return M1;
    if (E2 % 2 == 1 && E2_50 > M1){
        return M1;
    }
    if (EXP1 < 300){
        M1 -= 100;
    }
    else{
        M1 -= 120;
    }
    M1 = checkmoney(M1);
    EXP1 = ceil(double(EXP1)*90/100);
    EXP1 = checkexp(EXP1);
    return M1;  
}
double path2(int & HP1, int & EXP1, int & M1, int E2){
    int daco = M1 / 2;
    if (E2 % 2 == 1){
        while (true){
            if ((M1 >= daco) && (M1>0)){
                M1 = subpath2(HP1, EXP1, M1, E2, daco);
            }
            else{
                HP1 = ceil(double(HP1)*83/100);
                HP1 = checkhp(HP1);
                EXP1 = ceil(double(EXP1)*117/100);
                EXP1 = checkexp(EXP1);
                break;
            }
        }
    }
    else if (E2 % 2 == 0){
        M1 = subpath2(HP1, EXP1, M1, E2, daco);
        HP1 = ceil(double(HP1)*83/100);
        HP1 = checkhp(HP1);
        EXP1 = ceil(double(EXP1)*117/100);
        EXP1 = checkexp(EXP1);
    }
    int S;
    S = timso(EXP1);
    if (EXP1 >= S)
        return 1;
    double k = (double(EXP1) / S + 80) / 123;
    return k;
}
double path3(int & HP1, int & EXP1, int & M1, int E2){
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = 0;
    if (E2 < 10)
        i = E2;
    else{
            i = (E2 / 10 + E2 % 10) % 10;
        }
    double k = double(P[i] / 100);
    return k;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2){   
    // TODO: Complete this function
    if((E2 < 0) || (E2 > 99))
        return -99;
    HP1 = checkhp(HP1);
    EXP1 = checkexp(EXP1);
    M1 = checkmoney(M1);
    double P1 = path1(EXP1);
    double P2 = path2(HP1, EXP1, M1, E2);
    double P3 = path3(HP1, EXP1, M1, E2);
    if (P1 == 1 && P2 == 1 && P3 == 1){
        EXP1 = ceil(double(EXP1) * 75 / 100);
        EXP1 = checkexp(EXP1);
        return HP1 + EXP1 + M1;
    }
    double average = (P1 + P2 + P3) / 3;
    if (average < 0.5){
        EXP1 = ceil(double(EXP1) * 115 / 100);
        EXP1 = checkexp(EXP1);
        HP1 = ceil(double(HP1) * 85 / 100);
        HP1 = checkhp(HP1);
    }
    else if(average >= 0.5){
        EXP1 = ceil(double(EXP1)*120/100);
        EXP1 = checkexp(EXP1);
        HP1 = ceil(double(HP1)*90/100);
        HP1 = checkhp(HP1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int giatrilonnhat(int matrix[10][10], int i, int j){
    int max = matrix[i][j];
    int h = i, c = j;
    while (h >= 0 && c >= 0){
        if (matrix[h][c] > max)
            max = matrix[h][c];
        h--;
        c--;
    }
    h = i;
    c = j;
    while (h < 10 && c < 10){
        if (matrix[h][c] > max)
            max = matrix[h][c];
        h++;
        c++;
    }
    h = i;
    c = j;
    while (h >= 0 && c< 10){
        if (matrix[h][c] > max)
            max = matrix[h][c];
        h--;
        c++;
    }
    h = i;
    c = j;
    while (h < 10 && c >= 0){
        if (matrix[h][c] > max)
            max = matrix[h][c];
        h++;
        c--;
    }
    if (max < 0)
        max = max * (-1);
    return max; 
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3){ 
    // TODO: Complete this function
    if((E3<0) || (E3>99))
        return -99;
    HP1 = checkhp(HP1);
    HP2 = checkhp(HP2);
    EXP1 = checkexp(EXP1);
    EXP1 = checkexp(EXP1);
    int matrix[10][10];
    int xJ = 0, yJ = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (matrix[i][j] > E3 * 2)
                xJ++;
            else if (matrix[i][j] < -E3)
                yJ++;
        }
    }
    if (xJ >= 10)
        xJ = xJ / 10 + xJ % 10;
    if (yJ >= 10)
        yJ = yJ / 10 + yJ % 10;
    if (xJ >= 10)
        xJ = xJ / 10 + xJ % 10;
    if (yJ >= 10)
        yJ = yJ / 10 + yJ % 10;
    if (abs(matrix[xJ][yJ]) > giatrilonnhat(matrix, xJ, yJ)){
        HP1 = ceil(double(HP1)*90/100); 
        HP2 = ceil(double(HP2)*90/100);
        EXP1 = ceil(double(EXP1)*88/100);
        EXP2 = ceil(double(EXP2)*88/100);       
    }
    else{
        HP1 = ceil(double(HP1)*110/100);
        HP2 = ceil(double(HP2)*110/100);
        EXP1 = ceil(double(EXP1)*112/100);
        EXP2 = ceil(double(EXP2)*112/100);
    }
    HP1 = checkhp(HP1);
    HP2 = checkhp(HP2);
    EXP1 = checkexp(EXP1);
    EXP2 = checkexp(EXP2); 
    if (abs(matrix[xJ][yJ]) > giatrilonnhat(matrix, xJ, yJ))
        return matrix[xJ][yJ];
    return giatrilonnhat(matrix, xJ, yJ);
}

// Task 4
int chuoicon(string se, string s){
    int found = s.find(se);
    if (s.find(se) != -1)
        return found;
    else
        return -1;
}
int chuoitrung(string str){
    for (int i = 0; i < str.size() - 2; i++){
        if ((str[i] == str[i + 1]) && (str[i] == str[i + 2])){
            return i;
        }
    }
    return -1;
}
bool kytudacbiet(string str){
    for (int i = 0; i < str.size(); i++){
        if ((str[i] == '@') || (str[i] == '#') || (str[i] == '%') || (str[i] == '$') || (str[i] == '!')){
            return true;
        }
    }
    return false;
}
int kytukhac(string str){
    bool flag;
    for (int i = 0; i < str.size(); i++){
        if ((str[i]>='a') && (str[i]<='z')){
            flag=true;
        }
        else if((str[i]>='A') && (str[i]<='Z')){
            flag=true;
        }
        else if((str[i]>='0') && (str[i]<='9')){
            flag=true;
        }
        else if ((str[i] == '@') || (str[i] == '#') || (str[i] == '%') || (str[i] == '$') || (str[i] == '!')){
            flag=true;
        }
        else{
            return i;
        }
    }
    return -1;
}
int checkPassword(const char * s, const char * email){
    // TODO: Complete this function
    if (strlen(s) < 8)
        return -1;
    if (strlen(s) > 20)
        return -2;
    string se = "";
    for (int i = 0; i < strlen(email); i++){
        if (email[i] == '@')
            break;
        se += email[i];
    }
    if (chuoicon(se, s) != -1)
        return -(300 + chuoicon(se, s));
    if (chuoitrung(s) != -1)
        return -(400 + chuoitrung(s));
    if (kytudacbiet(s) != true)
        return -5;
    if(kytukhac(s) != -1)
        return kytukhac(s);
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds){
    // TODO: Complete this function
    int maxCount = 0;
    int maxLength = 0;
    int index = 0;
    for (int i = 0; i < num_pwds; i++){
        int count = 0;
        for (int j = i; j < num_pwds; j++){
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0){
                count++;
            }
        }
        if ((count > maxCount) || ((count == maxCount) && (strlen(arr_pwds[i]) > maxLength))){
            maxCount = count;
            maxLength = strlen(arr_pwds[i]);
            index = i;
        }
    }
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////