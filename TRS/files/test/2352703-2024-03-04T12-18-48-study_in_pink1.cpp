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

int checkInvalid(int exp1){
    if(exp1 > 600){
        return 600;
    }
    else if(exp1 < 0){
        return 0;
    }
    else return exp1;
}

int checkInvalidHp(int HP1){
    if(HP1 > 666){
        return 666;
    }
    else if(HP1 < 0){
        return 0;
    }
    else return HP1;
}

int checkInvalidMoney(int M1){
    if(M1 > 3000){
        return 3000;
    }
    else if(M1 < 0){
        return 0;
    }
    else return M1;
}

int findCP(int & exp1){
    int a = exp1;
    a = round(sqrt(a));
    return a*a;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1 < 0 || e1 > 99){
        return -99;
    }
    exp1 = checkInvalid(exp1); exp2 = checkInvalid(exp2);
    if(e1 >= 0 && e1 <= 3){
        exp1 = checkInvalid(exp1); exp2 = checkInvalid(exp2);
        switch (e1)
        {
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
            exp2 = exp2 + 29 + 45 + 75;
            break;
        }
        exp1 = checkInvalid(exp1); exp2 = checkInvalid(exp2);
        int D = e1 * 3 + exp1*7;
        if(D % 2 == 0){
            exp1 = ceil(((float)exp1 + ((float)D/200)));
        }
        else{
            exp1 = ceil(((float)exp1 - ((float)D/100)));
        }
        exp1 = checkInvalid(exp1); exp2 = checkInvalid(exp2);
    }
    else if(e1 >= 4 && e1 <= 19){
        exp2 = ceil(((float)(exp2) +  ((float)e1/4) + 19));
        exp1 = checkInvalid(exp1); exp2 = checkInvalid(exp2);
    }
    else if(e1 >= 20 && e1 <= 49){
        exp2 = ceil(((float)(exp2) + ((float)e1/9) + 21));
        exp1 = checkInvalid(exp1); exp2 = checkInvalid(exp2);
    }
    else if(e1 >= 50 && e1 <= 65){
        exp2 = ceil(((float)(exp2) +  ((float)e1/16) + 17));
        exp1 = checkInvalid(exp1); exp2 = checkInvalid(exp2);
    }
    else if(e1 >= 66 && e1 <= 79){
        exp2 = ceil(((float)(exp2) +  ((float)e1/4) + 19));
        exp1 = checkInvalid(exp1); exp2 = checkInvalid(exp2);
        if(exp2 > 200){
            exp2 = ceil(((float)(exp2) +  ((float)e1/9) + 21));
            exp1 = checkInvalid(exp1); exp2 = checkInvalid(exp2);
        }
    }
    else if(e1 >= 80 && e1 <= 99){
        exp2 = ceil(((float)(exp2) +  ((float)e1/4) + 19));
        exp1 = checkInvalid(exp1); exp2 = checkInvalid(exp2);
        exp2 = ceil(((float)(exp2) +  ((float)e1/9) + 21));
        exp1 = checkInvalid(exp1); exp2 = checkInvalid(exp2);
        if(exp2 > 400){
            exp2 = ceil(((float)(exp2) +  ((float)e1/16) + 17));
            exp1 = checkInvalid(exp1); exp2 = checkInvalid(exp2);
            exp2 = ceil((float)(exp2*1.15));
            exp1 = checkInvalid(exp1); exp2 = checkInvalid(exp2);
        }
    }
    if(e1 > 3) exp1 -= e1;
    exp1 = checkInvalid(exp1); exp2 = checkInvalid(exp2);
    return exp1 + exp2;
}

// Task 2

float probCal(int & EXP1){
    int s = findCP(EXP1);
    if(EXP1 >= s){
        return 1;
    }
    else{
        return ((((float)EXP1)/s + 80) / 123);
    }
}

void road2(int & HP1, int & EXP1, int & M1, int E3, int & Mspent){
    float Mhalf = float(M1) * 0.5;

    if(E3 % 2 != 0){
        if(HP1 < 200){
            HP1 = ceil((float)HP1 + (float)HP1 * 0.3);
            HP1 = checkInvalidHp(HP1);
            Mspent += 150;
        }
        else{
            HP1 = ceil((float)HP1 + (float)HP1 * 0.1);
            HP1 = checkInvalidHp(HP1);
            Mspent += 70;
        }
        HP1 = checkInvalidHp(HP1);
        if(Mspent > Mhalf){
            
            M1 = M1 - Mspent;
            M1 = checkInvalidMoney(M1);
            HP1 = ceil((float)HP1 - (float)HP1 * 0.17);
            HP1 = checkInvalidHp(HP1);
            EXP1 = ceil((float)EXP1 + (float)EXP1 * 0.17);
            EXP1 = checkInvalid(EXP1);
            return;
        }
        if(EXP1 < 400){
            Mspent += 200;
        }
        else{
            Mspent += 120;
        }
        EXP1 = ceil((float)EXP1 + (float)EXP1 * 0.13);
        EXP1 = checkInvalid(EXP1);
        if(Mspent > Mhalf){
            
            M1 = M1 - Mspent;
            M1 = checkInvalidMoney(M1);
            HP1 = ceil((float)HP1 - (float)HP1 * 0.17);
            HP1 = checkInvalidHp(HP1);
            EXP1 = ceil((float)EXP1 + (float)EXP1 * 0.17);
            EXP1 = checkInvalid(EXP1);
            return;
        }
        if(EXP1 < 300){
            Mspent += 100;
        }
        else{
            Mspent += 120; 
        }
        EXP1 = ceil((float)EXP1 - (float)EXP1 * 0.1);
        EXP1 = checkInvalid(EXP1);
        if(Mspent > Mhalf){
            
            M1 = M1 - Mspent;
            M1 = checkInvalidMoney(M1);
            HP1 = ceil((float)HP1 - (float)HP1 * 0.17);
            HP1 = checkInvalidHp(HP1);
            EXP1 = ceil((float)EXP1 + (float)EXP1 * 0.17);
            EXP1 = checkInvalid(EXP1);
            return;
        }
    }
    else{
        if(M1 <= 0){
            M1 = checkInvalidMoney(M1);
            HP1 = ceil((float)HP1 - (float)HP1 * 0.17);
            HP1 = checkInvalidHp(HP1);
            EXP1 = ceil((float)EXP1 + (float)EXP1 * 0.17);
            EXP1 = checkInvalid(EXP1);
            return;
        }
        if(HP1 < 200){
            HP1 = ceil((float)HP1 + (float)HP1 * 0.3);
            M1 -= 150;
            M1 = checkInvalidMoney(M1);
        }
        else{
            HP1 = ceil((float)HP1 + (float)HP1 * 0.1);
            M1 -= 70;
            M1 = checkInvalidMoney(M1);
        }
        HP1 = checkInvalidHp(HP1);
        if(M1 <= 0){
            M1 = checkInvalidMoney(M1);
            HP1 = ceil((float)HP1 - (float)HP1 * 0.17);
            HP1 = checkInvalidHp(HP1);
            EXP1 = ceil((float)EXP1 + (float)EXP1 * 0.17);
            EXP1 = checkInvalid(EXP1);
            return;
        }
        if(EXP1 < 400){
            M1 -= 200;
            M1 = checkInvalidMoney(M1);
        }
        else{
            M1 -= 120;
            M1 = checkInvalidMoney(M1);
        }
        EXP1 = ceil((float)EXP1 + (float)EXP1 * 0.13);
        if(M1 <= 0){
            M1 = checkInvalidMoney(M1);
            HP1 = ceil((float)HP1 - (float)HP1 * 0.17);
            HP1 = checkInvalidHp(HP1);
            EXP1 = ceil((float)EXP1 + (float)EXP1 * 0.17);
            EXP1 = checkInvalid(EXP1);
            return;
        }
        if(EXP1 < 300){
            M1 -= 100;
            M1 = checkInvalidMoney(M1);
        }
        else{
            M1 -= 120;
            M1 = checkInvalidMoney(M1);
        }
        EXP1 = ceil((float)EXP1 - (float)EXP1 * 0.1);
        EXP1 = checkInvalid(EXP1);
        if(M1 <= 0){
            M1 = checkInvalidMoney(M1);
            HP1 = ceil((float)HP1 - (float)HP1 * 0.17);
            HP1 = checkInvalidHp(HP1);
            EXP1 = ceil((float)EXP1 + (float)EXP1 * 0.17);
            EXP1 = checkInvalid(EXP1);
            return;
        }
        HP1 = ceil((float)HP1 - (float)HP1 * 0.17);
        HP1 = checkInvalidHp(HP1);
        EXP1 = ceil((float)EXP1 + (float)EXP1 * 0.17);
        EXP1 = checkInvalid(EXP1);
        return;
    }
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    float p1, p2, p3, avg;
    float p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int Mspent = 0;
    int sumDigits = 0, e2 = E2;
    if(E2 < 0 || E2 > 99){
        return -99;
    }
    HP1 = checkInvalidHp(HP1);
    EXP1 = checkInvalid(EXP1);
    M1 = checkInvalidMoney(M1);
    int Mcheck = M1;
    p1 = probCal(EXP1);
    if(E2 % 2 != 0){
        HP1 = checkInvalidHp(HP1);
        EXP1 = checkInvalid(EXP1);
        M1 = checkInvalidMoney(M1);
        if(Mcheck == 0){
            M1 = 0;
            Mcheck = 1;
            HP1 = ceil((float)HP1 - (float)HP1 * 0.17);
            HP1 = checkInvalidHp(HP1);
            EXP1 = ceil((float)EXP1 + (float)EXP1 * 0.17);
            EXP1 = checkInvalid(EXP1);
        }
        while(M1 == Mcheck){
            road2(HP1, EXP1, M1, E2, Mspent);

        }
    }
    else{
        HP1 = checkInvalidHp(HP1);
        EXP1 = checkInvalid(EXP1);
        M1 = checkInvalidMoney(M1);
        road2(HP1, EXP1, M1, E2, Mspent);
        HP1 = checkInvalidHp(HP1);
        EXP1 = checkInvalid(EXP1);
        M1 = checkInvalidMoney(M1);
        
    }
    p2 = probCal(EXP1);
    if(e2 < 10){
        p3 = p[e2];
    }
    else{
        sumDigits = sumDigits + (e2 % 10);
        e2 /= 10;
        sumDigits = sumDigits + (e2 % 10);
        if(sumDigits < 10){
            p3 = p[sumDigits];
        }
        else{
            p3 = p[sumDigits % 10];
        }
    }
    if(p1 == 1 && p2 == 1 && round(p3) == 100){
        EXP1 = ceil((float)EXP1 - (float)EXP1 * 0.25);
        EXP1 = checkInvalid(EXP1);
        return HP1 + EXP1 + M1;
    }
    else{
        avg = (p1*100+p2*100+p3) / 3;
    }
    if(round(avg) < 50){
        HP1 = ceil((float)HP1 - (float)HP1 * 0.15);
        HP1 = checkInvalidHp(HP1);
        EXP1 = ceil((float)EXP1 + (float)EXP1 * 0.15);
        EXP1 = checkInvalid(EXP1);
    }
    else{
        HP1 = ceil((float)HP1 - (float)HP1 * 0.1);
        HP1 = checkInvalidHp(HP1);
        EXP1 = ceil((float)EXP1 + (float)EXP1 * 0.2);
        EXP1 = checkInvalid(EXP1);
    }
    HP1 = checkInvalidHp(HP1);
    EXP1 = checkInvalid(EXP1);
    M1 = checkInvalidMoney(M1);
    return HP1 + EXP1 + M1;
}

// Task 3

int diag(int a[][11], int i, int j){
    int result = INT_MIN;
    //Left
    int i_save = i;
    int j_save = j;
    while(i > -1  && i < 10 && j > -1 && j < 10){
        result = max(a[i][j], result);
        i--;
        j--;
    }
    i = i_save;
    j = j_save;
    while(i > -1  && i < 10 && j > -1 && j < 10){
        result = max(a[i][j], result);
        i++;
        j++;
    }
    //Right
    i = i_save;
    j = j_save;
    while(i > -1  && i < 10 && j > -1 && j < 10){
        result = max(a[i][j], result);
        i--;
        j++;
    }
    i = i_save;
    j = j_save;
    while(i > -1  && i < 10 && j > -1 && j < 10){
        result = max(a[i][j], result);
        i++;
        j--;
    }
    return result;
}

int sum_Digits(int a){
    int sumDigits = 0;
    sumDigits = sumDigits + (a % 10);
    a /= 10;
    sumDigits = sumDigits + (a % 10);
    return sumDigits;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int a[11][11];
    int sum_big = 0;
    int sum_small = 0;
    int point;
    if(E3 < 0 || E3 > 99){
        return -99;
    }
     HP1 = checkInvalidHp(HP1); HP2 = checkInvalidHp(HP2);
     EXP1 = checkInvalid(EXP1); EXP2 = checkInvalid(EXP2);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if(a[i][j] > (E3 * 2)){
                sum_big++;
            }
            else if(a[i][j] < E3 * -1){
                sum_small++;
            }
        }
    }
    while(sum_big > 9){
        sum_big = sum_Digits(sum_big);
    }
    while(sum_small > 9){
        sum_small = sum_Digits(sum_small);
    }
    point = diag(a, sum_big, sum_small);
    if(abs(a[sum_big][sum_small]) > point){
        EXP1 = ceil((float)EXP1 - (float)EXP1 * 0.12);
        HP1 = ceil((float)HP1 - (float)HP1 * 0.1);
        EXP2 = ceil((float)EXP2 - (float)EXP2 * 0.12);
        HP2 = ceil((float)HP2 - (float)HP2 * 0.1);
        EXP1 = checkInvalid(EXP1); EXP2 = checkInvalid(EXP2);
        HP1 = checkInvalidHp(HP1); HP2 = checkInvalidHp(HP2);
        return a[sum_big][sum_small];
    }
    else{
        EXP1 = ceil((float)EXP1 + (float)EXP1 * 0.12);
        HP1 = ceil((float)HP1 + (float)HP1 * 0.1);
        EXP2 = ceil((float)EXP2 + (float)EXP2 * 0.12);
        HP2 = ceil((float)HP2 + (float)HP2 * 0.1);
        EXP1 = checkInvalid(EXP1); EXP2 = checkInvalid(EXP2);
        HP1 = checkInvalidHp(HP1); HP2 = checkInvalidHp(HP2);
        return point;
    }
}

// Task 4

int checkRepeat(string s){
    for(int i = 0; i < s.length() - 2; i++){
        if(s[i] == s[i+1] && s[i+1] == s[i+2]){
            return i;
        }
    }
    return -1;
}

bool checkSpecialChar(string s){
    for(int i = 0; i < s.length(); i++){
        switch (s[i]){
            case '@':
                return true;
            case '#':
                return true;
            case '%':
                return true;
            case '$':
                return true;
            case '!':
                return true;
        }
    }
    return false;
}

bool checkSpecialChar2(char s){
    switch (s){
        case '@':
            return true;
        case '#':
            return true;
        case '%':
            return true;
        case '$':
            return true;
        case '!':
            return true;
        
    }
    return false;
}

int checkValid(string s){
    for(int i = 0; i < s.length(); i++){
        string a = s.substr(i, i+2);
        if(!isdigit(s[i]) && !islower(s[i]) && !isupper(s[i]) && !checkSpecialChar2(s[i])){
            return i;
        }
    }
    return -1;
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string emailAl = email;
    int posA = emailAl.find("@");
    string se = emailAl.substr(0, posA);
    string sCheck = "";
    string sAl = s;
    if(sAl.length() < 8){
        return -1;
    }
    else if(sAl.length() > 20){
        return -2;
    }
    else if(sAl.find(se) != -1){
        return -(300 + sAl.find(se));
    }
    else if(checkRepeat(sAl)!= -1){
        return -(400 + checkRepeat(sAl));
    }
    else if(!checkSpecialChar(sAl)){
        return -5;
    }
    else if(checkValid(sAl)!= -1){
        return checkValid(sAl);
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxFreq = 0;
    int maxIndex = 0;
    for (int i = 0; i < num_pwds; i++) {
        string a = arr_pwds[i];
        int count = 0;
        for (int j = i + 1; j < num_pwds; j++) {
            string b = arr_pwds[j];
            if (a == b) {
                count++;
            }
        }
        if (count > maxFreq) {
            maxIndex = i;
            maxFreq = count;
        } else if (count == maxFreq) {
            string b = arr_pwds[maxIndex];
            if (a.length() > b.length()) {
                maxIndex = i;
                maxFreq = count;
            }
        }
    }
    return maxIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////