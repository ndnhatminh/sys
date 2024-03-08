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
void setEXP(int& EXP){
    EXP = (EXP > 600) ? 600 : ((EXP < 0) ? 0 : EXP);
}
void setHP(int& HP){
    HP = (HP > 666) ? 666 : ((HP < 0) ? 0 : HP);
}
void setM(int& M){
    M = (M > 3000) ? 3000 : ((M < 0) ? 0 : M);
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 > 99 || e1 < 0)
        return -99;

    setEXP(exp1);
    setEXP(exp2);

    if (e1 == 0)
        exp2 += 29;

    if (e1 == 1)
        exp2 += 45;

    if (e1 == 2)
        exp2 += 75;

    if (e1 == 3)
        exp2 += 149;
    setEXP(exp2);

        
    if (e1 < 4){
        int D = e1*3 + exp1*7;

        if (D%2)
            exp1 = ceilf(exp1-D/100.0);
        else
            exp1 = ceilf(exp1+D/200.0);
        setEXP(exp1);
     
    }

    if (e1 > 3)
    {
        if (e1 < 20 || e1 > 65)
            exp2 += ceilf(e1/4.0) + 19;

        if (e1 > 19 && e1 < 50 || e1 > 79 || e1 > 65 && exp2 > 200)
            exp2 +=  ceilf(e1/9.0) + 21;

        if (e1 > 49 && e1 < 66 || e1 > 79 && exp2 > 400)
            exp2 += ceilf(e1/16.0) + 17;

        if (exp2 > 400 && e1 > 79)
            exp2 = ceilf(exp2 * 1.15);

        exp1 -= e1;
    }
    setEXP(exp1);
    setEXP(exp2);

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99)
        return -99;

    #define REPEATED_CONDITION \
        if ((initM1 - M1 > 0.5 * initM1 && E2%2) || (M1 <= 0 && !(E2%2))) \
            break
    #define SET_VALUE \
    setEXP(EXP1);\
    setM(M1);\
    setHP(HP1)\
    
    SET_VALUE;
    float P1 = calcProbability(EXP1);     
    int initM1 = M1;

    do {
        REPEATED_CONDITION;
        if (HP1 < 200) {
            HP1 = ceilf(HP1 * 1.3);
            M1 -= 150;
        }
        else {
            HP1 = ceilf(HP1 * 1.1);
            M1 -= 70;
        }
        SET_VALUE;
        REPEATED_CONDITION;

        if (EXP1 < 400)
            M1 -= 200;
        else
            M1 -= 120;
        EXP1 = ceilf(EXP1 * 1.13);

        SET_VALUE;
        REPEATED_CONDITION;

        M1 -= ((EXP1 < 300) ? 100 : 120);
        EXP1 = ceilf(EXP1 * 0.9);

        SET_VALUE;


    } while (E2 % 2);

    HP1 = ceilf(HP1*0.83);
    EXP1 = ceilf(EXP1*1.17); 
    SET_VALUE;

    float P2 = calcProbability(EXP1);
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float P3 = 0;
    if (E2 < 10)
        P3 = P[E2]/100.0;
    else {
        int sum = E2%10 + E2/10;
        P3 = P[sum%10]/100.0;
    }
    if (P1 == 1 && P2 == 1 && P3 == 1)
        EXP1 = ceilf(EXP1*0.75);
    else {
        float prob = (P1 + P2 + P3)/3;
        if (prob < 0.5){
            HP1 = ceilf(HP1*0.85);
            EXP1 = ceilf(EXP1*1.15);
        }
        else{
            HP1 = ceilf(HP1*0.9);
            EXP1 = ceilf(EXP1*1.2);
        }
    }
    SET_VALUE;
    return HP1 + EXP1 + M1;
}

float calcProbability(int EXP1) {
    int S = perfectSquare(EXP1);
    if (EXP1 >= S)
        return 1; 
    return ((float)EXP1/S + 80) / 123.0;
}

int perfectSquare(int upper) {
    int lower = upper;
    while (sqrt(upper) != (int)sqrt(upper))
    {
        upper++;
        lower--;
        if (sqrt(lower) == (int)sqrt(lower))
            return lower;
    }
    return upper;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99)
        return -99;
    #define SET_VALUE_3 \
    setHP(HP1); \
    setHP(HP2); \
    setEXP(EXP1); \
    setEXP(EXP2) \

    SET_VALUE_3;
    int mtx[10][10] = {};
    int pos = 0, neg = 0;
    for (int i = 0; i < 10 ; i++) {
        for (int j = 0 ; j < 10 ; j++) {
            mtx[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (mtx[i][j] > E3 * 2)
                pos++;
            else if (mtx[i][j] < -E3)
                neg++;
        }
    }
    while (pos > 9){
        pos = pos/10 + pos%10;
    }
    while (neg > 9){
        neg = neg/10 + neg%10;
    }
    int taxi = mtx[pos][neg];
    int sherlock = sherlockScore(pos,neg,mtx);
    
    if (abs(taxi) > abs(sherlock)){
        HP1 = ceilf(HP1*0.9);
        HP2 = ceilf(HP2*0.9);
        EXP1 = ceilf(EXP1*0.88);
        EXP2 = ceilf(EXP2*0.88);
        return taxi;
    }
    HP1 = ceilf(HP1*1.1);
    HP2 = ceilf(HP2*1.1);
    EXP1 = ceilf(EXP1*1.12);
    EXP2 = ceilf(EXP2*1.12);
    SET_VALUE_3;
    return sherlock;
    
}
int sherlockScore(int i,int j, int mtx[10][10]){
    int max = mtx[i][j], x=i, y=j;
    //left diagonal
    if (x > y) {
        x -= y;
        y = 0;
    }
    else {
        y -= x;
        x = 0;
    }
    while (x != 10 && y != 10) {
        if (mtx[x][y] > max)
            max = mtx[x][y];
        x++;
        y++;
    }

    //right diagonal
    if (i + j < 9) {
        j += i;
        i = 0;
    }
    else {
        i += j-9;
        j = 9;
    }
    while (i != 10 && j != -1) {
        if (mtx[i][j] > max)
            max = mtx[i][j];
        i++;
        j--;
    }
    return max;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    std::string username(email);
    std::string password(s);

    stringstream ss(username);
    std::getline(ss, username, '@');

    int len = password.length();
    if (len < 8)
        return -1;
    if (len > 20)
        return -2;
    if (password.find(username) != std::string::npos)
        return -300 - password.find(username);

    int same = -1, illegal = -1;
    bool special = false;
    #define IS_SPECIAL_CHAR x == '!' || x == '@' || x == '#' || x == '$' || x == '%'

    for (int i = 0; i < len; i++) {
        char x = password[i];
        if (IS_SPECIAL_CHAR)
            special = true;
        if (!(isalnum(x) || IS_SPECIAL_CHAR) && illegal == -1)
            illegal = i;

        if (i == len - 2)
            continue;
        if (x == password[i + 1] && x == password[i+2] && same == -1) 
            same = i;
    }
    if (same != -1)
        return -400-same;

    if (!special)
        return -5;

    if (illegal != -1)
        return illegal;

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int max = 0;
    const int num = num_pwds;
    int count[num] = {};
    for (int i = 0; i < num_pwds; i++) {
        for (int j = 0; j < num_pwds; j++) {
            if (!strcmp(arr_pwds[i], arr_pwds[j]))
                count[i]++;
        }
        if (count[i] > max)
            max = count[i];
    }
    int position = 0, maxlen = 0;
    for (int i = 0; i < num_pwds; i++){
        if (max == count[i] && strlen(arr_pwds[i]) > maxlen) {
            position = i;
            maxlen = strlen(arr_pwds[i]);
        }
    }
    return position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////