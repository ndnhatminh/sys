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
////////////////////////////////////////////////////////////////34////////




// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {

    

    //Case1
    if (0 <= e1 && e1 <= 3){
        if (exp1 > 600){
                exp1 = 600;
            }
        else if (exp1 < 0){
                exp1 = 0;
            }
        if (exp2 > 600){
                exp2 = 600;
            }
        else if (exp2 < 0){
                exp2 = 0;
            }

        if (e1 == 0){
            exp2 += 29;
        }
        else if (e1 == 1){
            exp2 += 45;
        }
        else if (e1 == 2){
            exp2 += 75;
        }
        else {
            exp2 += 29 + 45 +  75;
        }

        exp1 += (e1 * 3 + exp1 * 7) % 2 == 0 ? ceil((double)(e1 * 3 + exp1 * 7)/200): ceil(-(double)(e1 * 3 + exp1 * 7)/100);
    }


    //Case 2
    else if ( (4 <= e1) and (e1 <= 99)){
        
        if (exp1 > 600){
                exp1 = 600;
            }
        else if (exp1 < 0){
                exp1 = 0;
            }
        if (exp2 > 600){
                exp2 = 600;
            }
        else if (exp2 < 0){
                exp2 = 0;
            }
        if ((4 <= e1) and (e1 <= 19)){
            exp2 += ceil((double)e1/4 + 19);
        }
        else if ((20 <= e1) and (e1 <= 49)){
            exp2 += ceil((double)e1/9 + 21);
        }
        else if ((50 <= e1) and (e1<= 65)){
            exp2 += ceil((double)e1/16 + 17);
        }
        else if ((66 <= e1) and (e1 <= 79)){
            exp2 += ceil((double)e1/4 + 19);
            if (exp2 > 600) {
                exp2 = 600;
            }

            if (exp2 > 200){
                exp2 += ceil((double)e1/9 + 21);
            }
        }
        else {
            exp2 += ceil((double)e1/4) + 19 + ceil((double)e1/9)+ 21;
            if (exp2 > 400){
                exp2 += ceil((double)e1/16 + 17);
                exp2 += ceil((double)exp2 * 0.15);
            }
        }
        exp1 -= e1;
        if (exp1 < 0){
            exp1 = 0;
        }
    
    }
    else {
        return -99;
    }

    if (exp2 > 600) {
        exp2 = 600;
    }
    if (exp1 > 600){
        exp1 = 600;
    }

    return exp1 + exp2;
    }
    

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {

    
    if (E2 < 0 || E2 > 99){
        return -99;
    }
    if (EXP1 > 600){
        EXP1 = 600;
        
    }
    else if (EXP1 < 0){
        EXP1 = 0;
    }
    if (HP1 > 666){
        HP1 = 666;
        
    }
    else if (HP1 < 0){
        HP1 = 0;
    }
    if (M1 < 0){
        M1 = 0;
    }
    else if (M1 > 3000){
        M1 = 3000;
    }

    // first road
    double p1, p2, p3;
    int s = sqrt(EXP1);
    s = (abs(s*s - EXP1) > abs((s+1)*(s+1) - EXP1)) ? (s+1)*(s+1) : s*s;
    p1 = (EXP1 >= s) ? 1 : ((double)EXP1/s + 80)/123; 


    // seccond road
    double MCondtion = M1/2;
    

    while (true){
        if (M1 == 0){
            break;
        }
        //first
        if (HP1 < 200){
            HP1 = ceil(double(HP1 * 1.3));
            M1 -= 150;
        }
        else {
            HP1 = ceil(double(HP1 * 1.1));
            M1 -= 70; 
        }

        if (HP1 > 666){
            HP1 = 666;
        }

        if (E2 % 2 != 0){
            if (M1 < MCondtion){
                break;
            }
        }
        else{
            if (M1 < 0){ 
                break;
            }
        }

        // seccond 
        if (EXP1 < 400){
            M1 -= 200;
        }
        else {
            M1 -= 120;
        }
        EXP1 = ceil((double)EXP1 * 1.13);
    
        if (EXP1 > 600){
            EXP1 = 600;

        }
        
        if (E2 % 2 != 0){
            if (M1 < MCondtion){
                break;
            }
        }
        else{
            if (M1 < 0){ 
                break;
            }
        }

        // third 
        if (EXP1 < 300){
            M1 -= 100;
        }
        else {
            M1 -= 120;
        }
        EXP1 = ceil((double)EXP1 * 0.9);

        if (E2 % 2 != 0){
            if (M1 < MCondtion){
                break;
            }
        }
        else{
            break;
        }
    }
    
    if (M1 < 0){
        M1 = 0;
    }

    HP1 = ceil((double)HP1 * 0.83);
    EXP1 = ceil((double)EXP1 * 1.17);

    if (EXP1 > 600){
        EXP1 = 600;

    }

    s = sqrt(EXP1);
    s = (abs(s*s - EXP1) > abs((s+1)*(s+1) - EXP1)) ? (s+1)*(s+1) : s*s;
    p2 = (EXP1 >= s) ? 1 : ((double)EXP1/s + 80)/123;

    // third road
    double p[10] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    int i;
    if (E2 < 10){
        p3 = p[E2];
    }
    else{
        i = E2 / 10 + E2 % 10;
        if (i > 9){
            i %= 10;
        }
        p3 = p[i];
    }
    double pAvr = (p1 + p2 + p3) / 3;

    if (p1 == 1 && p2 == 1 && p3 == 1){
        EXP1 = ceil((double)EXP1 * 0.75);
    }
    else if (pAvr < 0.5){
        HP1 = ceil((double)HP1 * 0.85);
        EXP1 = ceil((double)EXP1 * 1.15);
    }
    else{
        HP1 = ceil((double)HP1 * 0.9);
        EXP1 = ceil((double)EXP1 * 1.20);

    }
    if (EXP1 > 600){
        EXP1 = 600; 

    }

    return HP1 + EXP1 + M1;
   
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99){
        return -99;
    }
    if (HP1 > 666){
        HP1 = 666;
    }
    else if (HP1 < 0){
        HP1 = 0;
    }

    if (EXP1 > 600){
        EXP1 = 600;
    }
    else if (EXP1 < 0){
        EXP1 = 0;
    }

    if (HP2 < 0){
        HP2 = 0;
    }
    else if (HP2 > 666){
        HP2 = 666;
    }

    if (EXP2 > 600){
        EXP2 = 600;
    }
    else if (EXP2 < 0){
        EXP2 = 0;
    }
    int matrix[10][10], i = 0, j = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            matrix[i][j] = ((E3 * j)+(i * 2))*(i-j);
        }
    }
    int i_flag = 0, j_flag = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (matrix[i][j] > E3*2){
                i_flag++;
            }
            else if (matrix[i][j] < - E3){
                j_flag++;
            }
        }
    }

    

    while (i_flag > 9){
        i_flag = i_flag % 10 + i_flag / 10;
    }
    while (j_flag > 10){
        j_flag = j_flag % 10 + j_flag / 10;
    }

    int exp_max = 0;

    int i_test = i_flag, j_test = j_flag;
    while (i_test < 10 && j_test < 10){
        if (exp_max < matrix[i_test][j_test]){
            exp_max = matrix[i_test][j_test];
        }
        i_test++; j_test++;
    }
    
    i_test = i_flag; j_test = j_flag;

    while (i_test >= 0 && j_test >= 0){
        if (exp_max < matrix[i_test][j_test]){
            exp_max = matrix[i_test][j_test];
        }
        i_test--; j_test--;
    }

    i_test = i_flag; j_test = j_flag;

    while (i_test >= 0 && j_test < 10){
        if (exp_max < matrix[i_test][j_test]){
            exp_max = matrix[i_test][j_test];
        }
        i_test--; j_test++;
    }
    i_test = i_flag; j_test = j_flag;

    while (i_test < 10 && j_test >= 0){
        if (exp_max < matrix[i_test][j_test]){
            exp_max = matrix[i_test][j_test];
        }
        i_test ++; j_test--;
    }
    

    if (exp_max < 0){
        exp_max = - exp_max;
    }

    if (exp_max >= abs(matrix[i_flag][j_flag])){
        
        EXP1 = ceil((double)EXP1 * 1.12);
        EXP2 = ceil((double)EXP2 * 1.12);
        HP1 = ceil((double)HP1 * 1.1);
        HP2 = ceil((double)HP2 * 1.1);

        if (EXP1 > 600){
            EXP1 = 600;
        }
        if (EXP2 > 600){
            EXP2 = 600;
        }
        if (HP1 > 666){
            HP1 = 666;
        }
        if (HP2 > 666){
            HP2 = 666;
        }


        return exp_max;
    }
    else {
        EXP1 = ceil((double)EXP1 * 0.88);
        EXP2 = ceil((double)EXP2 * 0.88);
        HP1 = ceil((double)HP1 * 0.9);
        HP2 = ceil((double)HP2 * 0.9);

        if (EXP1 < 0){
            EXP1 = 0;
        }
        if (EXP2 < 0){
            EXP2 = 0;
        }
        if (HP1 < 0){
            HP1 = 0;
        }
        if (HP2 < 0){
            HP2 = 0;
        }

        return matrix[i_flag][j_flag];
    }
    
}

// Task 4

int checkPassword(const char * s, const char * email) {
    string str = s, e = email, se = "";
    bool c1 = false, c2 = false, c3 = false;
    int ca1 = 0, ca2 = 0;

    if (str.length() < 8){
        return -1;
    }
    else if (str.length() > 20){
        return -2;
    }

    int flag = 0;

    for (int i = 0; i < e.length(); i++){
        if (e[i] != '@'){
            se += e[i];
        }
        else {
            break;
        }
    }

    for (int i = 0; i < str.length(); i++){
        if ((str.length() > se.length()) && (i + se.length() <= str.length() - 1)){
            if ((str.substr(i, se.length())  == se) && (!c1)){
                c1 = true;
                ca1 = i;    
            }
        }
        if ((i > 1) && (str[i-1] == str[i]) && (str[i-2] == str[i]) && !c2){
            c2 = true;
            ca2 = i;
        }

        if (str[i] == '@'|| str[i] == '#' || str[i] == '%' || str[i] == '$' || str[i] == '!'){
            c3 = true;
        }     
    }

    if (c1){
       return -(300 + ca1); 

    }
    else if (c2){
        return -(400 + (ca2 - 2));
    }
    else if (!c3){
        return -5;
    }
  
    return -10;
} 
// Task 5
bool inside(const char* arr[], string n, int len){

    for (int i = 0; i < len; i++){
        if (arr[i] == n){
            return true;
        }
    }
    return false;
}



int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    struct{
        const char* list[100];
        int index[30], times[30];
    }duplicate;
    int position = 0;
   for (int i = 0; i < num_pwds; i++){
        for (int j = i + 1; j < num_pwds; j++ ){
            if ((arr_pwds[i] == arr_pwds[j]) && !(inside(duplicate.list, arr_pwds[i], position+1))){
              duplicate.list[position] = arr_pwds[i];
              duplicate.index[position] = i;
              duplicate.times[position] = 1;
              position ++;  
            }
        }
    }

    for (int j = 0; j < num_pwds; j++){
        for (int i = 0; i < position; i++){
            if (arr_pwds[j] == duplicate.list[i]){
                duplicate.times[i]++;
    
            }
        }
    }
    for (int i = 0; i < position; i++){
        }
    int max = 0;
    if (position == 1){
        return duplicate.times[0];
    }
    for (int i = 1; i < position; i++){
        if (duplicate.times[i-1] == duplicate.times[i]){
            max = ((duplicate.index[i] > duplicate.index[i-1]) ? duplicate.index[i] : duplicate.index[i-1]);
        }
        else{
            max =  ((duplicate.times[i] > duplicate.times[i-1]) ? duplicate.index[i] : duplicate.index[i-1]);
        }
    }

    return max;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////