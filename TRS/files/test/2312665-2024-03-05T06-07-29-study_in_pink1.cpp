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

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

    check_limit_of_EXP(exp1);
    check_limit_of_EXP(exp2);
    if (check_limit_of_E(e1)){
        return -99;
    }
    //case 1: e1 [0; 3]
    if (e1 < 4){

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
            exp2 += 149;
        }

        int D = e1 * 3 + exp1 * 7;
        if ((D % 2) == 0)
            exp1 += ceilf(D / 200.0);
        else 
            exp1 = ceilf(exp1 - (D / 100.0));  
    }
    //case 2: e1 [4; 99]
    else {
        if ((e1 >= 4) && (e1 <= 19)){
            exp2 += ceilf((e1 / 4.0) + 19);
        }
        else if ((e1 >= 20) && (e1 <= 49)){
            exp2 += ceilf((e1 / 9.0) + 21);
        }
        else if ((e1 >= 50) && (e1 <= 65)){
            exp2 += ceilf((e1 / 16.0) + 17);
        }
        else if ((e1 >= 66) && (e1 <= 79)){
            exp2 += ceilf((e1 / 4.0) + 19);
            if (exp2 > 200){
                exp2 += ceilf((e1 / 9.0) + 21);
            }
        }
        else if ((e1 >= 80) && (e1 <= 99)){
            exp2 += ceilf((e1 / 4.0) + 19);
            exp2 += ceilf((e1 / 9.0) + 21);
            if (exp2 > 400){
                exp2 += ceilf((e1 / 16.0) + 17);
                exp2 = ceilf(exp2 * 1.15);
            }
        }
        exp1 -= e1;
    }
    check_limit_of_EXP(exp1);
    check_limit_of_EXP(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    //Case 1:
    check_limit_of_HP(HP1);
    check_limit_of_EXP(EXP1);
    check_limit_of_M(M1);
    if (check_limit_of_E(E2)){
        return -99;
    }
    double P1 = 100 * probability(EXP1);

    //Case 2:
    if (E2 % 2 == 1){
        float paid = M1 /2;
        while (M1 >= paid){
            if (M1 == 0){
                break;
            }
            if (HP1 < 200){
                HP1 = ceilf(HP1 * 1.3);
                M1 -= 150;
                check_limit_of_M(M1);
                if (M1 < paid)
                    break;
            }
            else {
                HP1 = ceilf(HP1 * 1.1);
                check_limit_of_HP(HP1);
                M1 -= 70;
                check_limit_of_M(M1);
                if (M1 < paid)
                    break;
            }
            if (EXP1 < 400){
                M1 -= 200;
                check_limit_of_M(M1);
                EXP1 = ceilf(EXP1 * 1.13);
                check_limit_of_EXP(EXP1);
                if (M1 < paid)
                    break;
            }
            else {
                M1 -= 120;
                check_limit_of_M(M1);
                EXP1 = ceilf(EXP1 * 1.13);
                check_limit_of_EXP(EXP1);
                if (M1 < paid)
                    break;
            }
            if (EXP1 < 300){
                M1 -= 100;
                check_limit_of_M(M1);
                EXP1 = ceilf(EXP1 * 0.9);
                check_limit_of_EXP(EXP1);
                if (M1 < paid)
                    break;
            }
            else {
                M1 -= 120;
                check_limit_of_M(M1);
                EXP1 = ceilf(EXP1 * 0.9);
                check_limit_of_EXP(EXP1);
                if (M1 < paid)
                    break;
            }
        }
    }
    else {

        while (M1 > 0){
            if (HP1 < 200){
                HP1 = ceilf(HP1 * 1.3);
                M1 -= 150;
                check_limit_of_M(M1);
                if (M1 == 0)
                    break;
            }
            else {
                HP1 = ceilf(HP1 * 1.1);
                check_limit_of_HP(HP1);
                M1 -= 70;
                check_limit_of_M(M1);
                if (M1 == 0)
                    break;
            }
            if (EXP1 < 400){
                M1 -= 200;
                check_limit_of_M(M1);
                EXP1 = ceilf(EXP1 * 1.13);
                check_limit_of_EXP(EXP1);
                if (M1 == 0)
                    break;
            }
            else {
                M1 -= 120;
                check_limit_of_M(M1);
                EXP1 = ceilf(EXP1 * 1.13);
                check_limit_of_EXP(EXP1);
                if (M1 == 0)
                    break;
            }
            if (EXP1 < 300){
                M1 -= 100;
                check_limit_of_M(M1);
                EXP1 = ceilf(EXP1 * 0.9);
                check_limit_of_EXP(EXP1);
                if (M1 == 0)
                    break;
            }
            else {
                M1 -= 120;
                check_limit_of_M(M1);
                EXP1 = ceilf(EXP1 * 0.9);
                check_limit_of_EXP(EXP1);
                if (M1 == 0)
                    break;
            }
            break;
        }
    }
    HP1 = ceilf(HP1 * 0.83);
    EXP1 = ceilf(EXP1 * 1.17);
    check_limit_of_HP(HP1);
    check_limit_of_EXP(EXP1);
    double P2 = 100 * probability(EXP1);

    //Case 3:
    double P3 = 0;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 > 9){
        int a = E2 / 10;
        int b = E2 % 10;
        int i = (a + b) % 10;
        P3 = P[i];
    }
    else {
        P3 = P[E2];
    }

    //Final:
    double P0 = 0;
    if ((P1 == 100) && (P2 == 100) && (P3 == 100)){
        EXP1 = ceilf(EXP1 * 0.75);
        check_limit_of_EXP(EXP1);
    }
    else{
        P0 = (P1 + P2 + P3) / 3;
        if (P0 < 50){
            HP1 = ceilf(HP1 * 0.85);
            EXP1 = ceilf(EXP1 * 1.15);
            check_limit_of_HP(HP1);
            check_limit_of_EXP(EXP1);
        }
        else{
            HP1 = ceilf(HP1 * 0.9);
            EXP1 = ceilf(EXP1 * 1.2);
            check_limit_of_HP(HP1);
            check_limit_of_EXP(EXP1);
        }
    }
    return (HP1 + EXP1 + M1);
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    check_limit_of_HP(HP1);
    check_limit_of_EXP(EXP1);
    check_limit_of_HP(HP2);
    check_limit_of_EXP(EXP2);
    if (check_limit_of_E(E3)){
        return -99;
    }

    int location[10][10];
    int points_SherLock = 0;
    int points_Crime = 0;
    int x = 0, y = 0;
    int i,j;
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            location[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (location[i][j] > E3 * 2){
                x++;
            }
            if (location[i][j] < - E3){
                y++;
            }
        }

    }
    if (x > 9){
        x = x / 10 + x % 10;
        if (x > 9){
            x = x / 10 + x % 10;
        }
    }
    if (y > 9){
        y = y / 10 + y % 10;
        if (y > 9){
            y = y / 10 + y % 10;
        }
    }
    points_Crime = location[x][y];
    if (x >= y){
        i = x -y;
        j = 0;
    }
    else {
        i = 0;
        j = y - x;
    }
    while ((i < 10) && (j < 10)){
        if (points_SherLock < location[i][j]){
            points_SherLock = location[i][j];
        }
        i++;
        j++;
    }
    if (x + y >= 9){
        i = 9;
        j = y - (9 - x);
    }
    else {
        i = x + y;
        j = 0;
    }
    while ((i >= 0) && (j <= 9)){
        if (points_SherLock < location[i][j]){
            points_SherLock = location[i][j];
        }
        i--;
        j++;
    }
    if (abs(points_Crime) > abs(points_SherLock)){
        EXP1 = ceilf(EXP1 * 0.88);
        EXP2 = ceilf(EXP2 * 0.88);
        HP1 = ceilf(HP1 * 0.9);
        HP2 = ceilf(HP2 * 0.9);
        check_limit_of_HP(HP1);
        check_limit_of_EXP(EXP1);
        check_limit_of_HP(HP2);
        check_limit_of_EXP(EXP2);
        return points_Crime;
    }
    else {
        EXP1 = ceilf(EXP1 * 1.12);
        EXP2 = ceilf(EXP2 * 1.12);
        HP1 = ceilf(HP1 * 1.1);
        HP2 = ceilf(HP2 * 1.1);
        check_limit_of_HP(HP1);
        check_limit_of_EXP(EXP1);
        check_limit_of_HP(HP2);
        check_limit_of_EXP(EXP2);
        return points_SherLock;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int sLength = strlen(s);
    if (sLength < 8){
        return -1;
    }
    else if(sLength > 20){
        return -2;
    }

    int seLength = strchr(email, '@') - email;
    char se[seLength + 1];
    strncpy(se, email, seLength);
    se[seLength] = '\0';
    const char* result = strstr(s, se);
    if (result != NULL){
        return -(300 + result - s);   
    }
    int counter = 1;
    bool spec = 0; 
    bool valid = 1;
    int index = 0;
    for (int i = 0; i < sLength; i++){
        if (s[i] == s[i + 1]){
            counter++;
            if (counter > 2){
            return -(400 + i - 1);
            }
        }
        else {
            counter = 1;
        }
    }
    for (int i = 0; i < sLength; i++){
        if ((s[i] == '!')  || (s[i] == '@') || (s[i] == '%')  || (s[i] == '#') || (s[i] == '$')){
            spec = 1;
        }
        else if (((s[i] >= 48) && (s[i] <= 57)) || ((s[i] >= 65) && (s[i] <= 90)) || ((s[i] >= 97) && (s[i] <= 122))){
        }
        else {
            if (valid != 0){
            valid = 0;
            index = i;
            }
        }
    }
    if (spec == 0){
        return -5;
    }
    else if (valid == 0){
        return index;
    }
    else {
        return -10;
    }
    return -99;
}


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    int data[3][num_pwds];
    // Tạo một mảng 2 chiều dùng để lưu dữ liệu của mỗi mật khẩu 
    // Gồm chỉ số của mật khẩu trong mảng arr, số lần lặp lại, độ dài mật khẩu
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < num_pwds; j++){
            data[i][j] = 0;
        }
    }
    int counter = 1;
    data[0][0] = 0;
    data[1][0]++;
    data[2][0] = strlen(arr_pwds[0]);            

    for (int i = 1; i < num_pwds; i++){
        for (int j = 0; j <= i; j++){
            if ((strcmp(arr_pwds[i], arr_pwds[data[0][j]])) == 0){
                data[1][j]++;
                break;
            }
            if (data[1][j] == 0){
                data[0][j] = i;
                data[1][j]++;
                data[2][j] = strlen(arr_pwds[i]);
                counter++;
                break;
            }
        }
        
    }
    // Tìm mật khẩu có số lần lặp lại nhiều nhất
    int max = 0;
    int count1 = 0;
    for (int i = 0; i < counter; ++i){
        if (data[1][i] > max) {
            max = data[1][i];
            count1 = 1;
        }
        else if (data[1][i] == max){
            count1++;
        }
    }


    if (count1 == 1){
        for (int i = 0; i < counter; i++){
            if (max == data[1][i]){
                return data[0][i];
            }
        }
    }
    else {
        int longest = 0;
        for (int i = 0; i < counter; i++){
            if (max == data[1][i]){
                if (data[2][i] > longest){                
                    longest = data[2][i];
                }
            }
        } 
        for (int i = 0; i < counter; i++){
            if ((max == data[1][i]) && (longest == data[2][i])){
                return data[0][i];
            }
        }
    }
    return -1;
}



//Check limit of HP, EXP, M
void check_limit_of_HP(int & HP){
    if (HP < 0) 
        HP = 0;
    if (HP > 666) 
        HP = 666;
}

void check_limit_of_EXP(int & EXP){
    if (EXP < 0) 
        EXP = 0;
    if (EXP > 600) 
        EXP = 600;;
}

void check_limit_of_M(int & M){
    if (M < 0) 
        M = 0;
    if (M > 3000) 
        M = 3000;
}
bool check_limit_of_E(int E){
    if ((E < 0) || (E > 99))
        return true;
    else 
        return false;
}

//Calculate probability
double probability(int EXP){
    double sqrt_exp = sqrt(EXP);
    int lower_sqrt = floor(sqrt_exp);
    int upper_sqrt = ceil(sqrt_exp);
    double S = 0;

    if ((lower_sqrt * lower_sqrt == EXP) || (upper_sqrt * upper_sqrt == EXP)) {
        S = EXP;
    }

    if (abs(EXP - lower_sqrt * lower_sqrt) < abs(EXP - upper_sqrt * upper_sqrt)) {
        S = lower_sqrt * lower_sqrt;
    } else {
        S = upper_sqrt * upper_sqrt;
    }
    if (EXP >= S){
        return 1;
    }
    else{
        return (EXP / S + 80) / 123;
    }
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////