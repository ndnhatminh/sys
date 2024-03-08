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
bool isEven(int num)
{
    return num % 2 == 0;
}
void check_hp(int& hp)
{
    ceil(hp);
    if (hp <= 0) hp = 0;
    else if (hp >= 666) hp = 666;
}
void check_exp(int& exp)
{
    if (exp <= 0) exp = 0;
    else if (exp >= 600) exp = 600;

}
void check_money(int& m)
{
    ceil(m);
    if (m <= 0) m = 0;
    else if (m >= 3000) m = 3000;
}
/*bool is_perfect_square(int n) {
    int sqr = sqrt(n);
    return sqr * sqr == n;
}*/
int nearest_perfect_square(int n)
{
    float nearest_int = round(sqrt(n));
    return nearest_int * nearest_int;
}
int get_p3_pos(int n)
{
    float dv = n % 10;
    int c;
        if (n < 10) return n;
        else {
            c = (n % 10) + (n / 10);
        }
        return c % 10;
}
////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
int MaxDiagonals(int taxi_scores[10][10], int i, int j) {
    int row = i;
    int col = j;
    while (row > 0 && col > 0) {
        row--;
        col--;
    }
    int maxLeft = taxi_scores[row][col];
    while (row < 9 && col < 9) {

        row++;
        col++;
        maxLeft = std::max(maxLeft, taxi_scores[row][col]);
    }

    row = i;
    col = j;
    while (row > 0 && col < 9) {

        row--;
        col++;
    }

    int maxRight = taxi_scores[i][j];
    while (row < 9 && col > 0) {
        row++;
        col--;
        maxRight = std::max(maxRight, taxi_scores[row][col]);

    }
    return max(maxRight, maxLeft);

}
void meetpoint(int matrix[10][10], int& i, int& j, int E3)
{
    int count_greater = 0;
    int count_smaller = 0;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (matrix[i][j] > E3 * 2) count_greater++;
            if (matrix[i][j] < -E3) count_smaller++;
        }
    }
    i = count_greater;
    j = count_smaller;

    while (i >= 10)
    {
        int sum = 0;
        while (i > 0)
        {
            sum += i % 10;
            i = i / 10;
        }
        i = sum;
    }
    while (j >= 10)
    {
        int sum = 0;
        while (j > 0)
        {
            sum += j % 10;
            j = j / 10;
        }
        j = sum;
    }

}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    check_exp(exp1);
    check_exp(exp2);
    if (e1 == 0)
    {
        exp2 += 29;
        float d = e1 * 3 + exp1 * 7;
        if (isEven(d)) {         
            exp1 = ceil(exp1 + d / 200);
        }
        else {
           
            exp1 = ceil(exp1 - d / 100);
        }
    }
    else if (e1 == 1)
    {
        exp2 += 45;
        float d = e1 * 3 + exp1 * 7;
        if (isEven(d)) {
            
            exp1 = ceil(exp1 + d / 200);
        }
        else {
            
            exp1 = ceil(exp1 - d / 100);
        }
    }
    else if (e1 == 2)
    {
        exp2 += 75;
        float d = e1 * 3 + exp1 * 7;
        if (isEven(d)) {
          
            exp1 = ceil(exp1 + d / 200);
        }
        else {
      
            exp1 = ceil(exp1 - d / 100);
        }
    }
    else if (e1 == 3)
    {
        exp2 += 149;
        float d = e1 * 3 + exp1 * 7;
        if (isEven(d)) {
         
            exp1 = ceil(exp1 + d / 200);
        }
        else {
            
            exp1 = ceil(exp1 - d / 100);
        }
    }
    else if (e1 >= 4 && e1 <= 19)
    {
        
        exp2 = ceil(exp2 + (static_cast<float>(e1) / 4 + 19));
        exp1 -= e1;
    }
    else if (e1 >= 20 && e1 <= 49)
    {
       
        exp2 = ceil(exp2 + (static_cast<float>(e1) / 9 + 21));
        exp1 -= e1;
    }
    else if (e1 >= 50 && e1 <= 65)
    {
    
        exp2 = ceil(exp2 + (static_cast<float>(e1) / 16 + 17));
        exp1 -= e1;
    }
    else if (e1 >= 66 && e1 <= 79)
    {
        
        exp2 = ceil(exp2 + (static_cast<float>(e1) / 4 + 19));
        check_exp(exp2);
        if (exp2 > 200)
        {
            
            exp2 = ceil(exp2 + (static_cast<float>(e1) / 9 + 21));
        }
        exp1 -= e1;
    }
    else if (e1 >= 80 && e1 <= 99)
    {
       
        exp2 = ceil(exp2 + (static_cast<float>(e1) / 4 + 19));
        check_exp(exp2);
      
        exp2 = ceil(exp2 + (static_cast<float>(e1) / 9 + 21));
        check_exp(exp2);
        if (exp2 > 400)
        {
          
            exp2 = ceil(exp2 + (static_cast<float>(e1) / 16 + 17));
            check_exp(exp2);
            exp2 = ceil(exp2 * 1.15);
        }
        
        
        exp1 -= e1;
    }
    else return -99;
    check_exp(exp2);
    check_exp(exp1);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    check_money(M1);
    check_hp(HP1);
    check_exp(EXP1);
    float start_money = M1;
    int half_start_money = ceil(start_money * 0.5*0.999999);
    int spent_money = 0;
    float P, P1, P2, P3;
    

    if (E2 < 0 || E2 > 99) return -99;
    //P1
    int S = nearest_perfect_square(EXP1);
    if (EXP1 >= S)
        P1 = 1;
    else P1 = (static_cast<float>(EXP1) / S + 80) / 123;
    //END P1

    //P2
    if (isEven(E2))
    {
        //EVENT1
        if (HP1 < 200 && M1 > 0)
        {
            
            HP1 = ceil(HP1 * 1.3 * 0.9999999);
            M1 -= 150;
        }
        else if (HP1 >= 200 && M1 > 0)
        {
           
            HP1 = ceil(HP1 * 1.1 * 0.9999999);
            M1 -= 70;
        }
        check_money(M1);
        check_hp(HP1);
        //EVENT2
        if (EXP1 < 400 && M1 > 0)
        {
            M1 -= 200;
          
            EXP1 = ceil(EXP1 * 1.13 * 0.9999999);
        }
        else if (EXP1 >= 400 && M1 > 0)
        {
            M1 -= 120;
            
            EXP1 = ceil(EXP1 * 1.13 * 0.9999999);
        }
        check_money(M1);
        check_exp(EXP1);
        //EVENT3
        if (EXP1 < 300 && M1 > 0)
        {
            M1 -= 100;
            
            EXP1 = ceil(EXP1 * 0.9 * 0.9999999);
        }
        else if (EXP1 >= 300 && M1 > 0)
        {
            M1 -= 120;
            
            EXP1 = ceil(EXP1 * 0.9 * 0.9999999);
        }
        check_money(M1);
        check_exp(EXP1);
        
        EXP1 = ceil(EXP1 * 1.17 * 0.9999999);
        
        HP1 = ceil(HP1 * 0.83 * 0.9999999);
    }
    else
    {
        while (spent_money <= half_start_money)
        {
            //EVENT1
            if (HP1 < 200 && spent_money <= half_start_money)
            {
                
                HP1 = ceil(HP1 * 1.3 * 0.999999);
                M1 -= 150;
                spent_money += 150;
            }
            else if (HP1 >= 200 && spent_money <= half_start_money)
            {
                
                HP1 = ceil(HP1 * 1.1 * 0.999999);
                M1 -= 70;
                spent_money += 70;
            }
            check_money(M1);
            check_hp(HP1);


            //EVENT2
            if (EXP1 < 400 && spent_money <= half_start_money)
            {
                M1 -= 200;
             
                EXP1 = ceil(EXP1 * 1.13*0.999999);
                spent_money += 200;
            }
            else if (EXP1 >= 400 && spent_money <= half_start_money)
            {
                M1 -= 120;
               
                EXP1 = ceil(EXP1 * 1.13 * 0.999999);
                spent_money += 120;
            }
            check_money(M1);
            check_exp(EXP1);
            //EVENT3
            if (EXP1 < 300 && spent_money <= half_start_money)
            {
                M1 -= 100;
              
                EXP1 = ceil(EXP1 * 0.9*0.999999);
                spent_money += 100;
            }
            else if (EXP1 >= 300 && spent_money <= half_start_money)
            {
                M1 -= 120;
                
                EXP1 = ceil(EXP1 * 0.9 * 0.999999);
                spent_money += 120;
            }           
        }
        check_money(M1);
        check_exp(EXP1);
      
        EXP1 = ceil(EXP1 * 1.17* 0.999999);
     
        HP1 = ceil(HP1 * 0.83 * 0.999999);
        check_hp(HP1);
        check_exp(EXP1);

    }
     S = nearest_perfect_square(EXP1);
    if (EXP1 >= S)
        P2 = 1;
    else if (EXP1 < S) {
        P2 = (static_cast<float>(EXP1) / S + 80) / 123; //float
    }
    // END P2

    //P3
    float prob[] = { 0.32, 0.47, 0.28, 0.79, 1, 0.50, 0.22, 0.83, 0.64, 0.11 };
    
    P3 = prob[get_p3_pos(E2)];

    // RESULT
    P = (P1 + P2 + P3)/3;
    if (P == 1) EXP1 = ceil(EXP1 * 0.75 * 0.999999);
    else if ( P < 0.5)
    {
        HP1 = ceil(HP1 * 0.85 * 0.999999);
        EXP1 = ceil(EXP1 * 1.15 * 0.999999);
    }
    else if (P >= 0.5)
    {
        HP1 = ceil(HP1 * 0.90 * 0.999999);
        EXP1 = ceil(EXP1 * 1.20 * 0.999999);
    }
    check_exp(EXP1);
    check_hp(HP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    check_hp(HP1);
    check_exp(EXP1);
    check_hp(HP2);
    check_exp(EXP2);



    int rslt;
    int sherlock_watson_scores[10][10];
    int taxi_scores[10][10];
    int i_meetpoint, j_meetpoint;
    if (E3 < 0 || E3 > 99) return -99;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            taxi_scores[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < 10; ++i) {
            sherlock_watson_scores[i][j] = abs(MaxDiagonals(taxi_scores, i, j));
        }
    }
    meetpoint(taxi_scores,i_meetpoint,j_meetpoint,E3);
    if (abs(taxi_scores[i_meetpoint][j_meetpoint]) > sherlock_watson_scores[i_meetpoint][j_meetpoint])
    {
        EXP1 = ceil(EXP1 * 0.88 * 0.9999999);
        EXP2 = ceil(EXP2 * 0.88 * 0.9999999);
        HP1 = ceil(HP1 * 0.9 * 0.9999999);
        HP2 = ceil(HP2 * 0.9 * 0.9999999);
        rslt =  taxi_scores[i_meetpoint][j_meetpoint];
    }
    else {
        EXP1 = ceil(EXP1 * 1.12 * 0.9999999);
        EXP2 = ceil(EXP2 * 1.12 * 0.9999999);
        HP1 = ceil(HP1 * 1.1 * 0.9999999);
        HP2 = ceil(HP2 * 1.1 * 0.9999999);
        rslt = sherlock_watson_scores[i_meetpoint][j_meetpoint];
    }
    check_hp(HP1);
    check_hp(HP2);
    check_exp(EXP1);
    check_exp(EXP2);
    return rslt;
}
// Task 4
bool have_special_character(const char* s)
{
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 64 || s[i] == 33 || s[i] == 35 || s[i] == 36 || s[i] == 37)
            return true;
    }
    return false;
}
int checkPassword(const char * s, const char * email) {
    bool islock = false;
    int pos_a = -55;
    bool is_invalid = false;
    string se;
    
     //check email
    if (strlen(email) > 100)
    {
        return strlen(email);
    }
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@' && !islock)
        {
            pos_a = i;
            islock = true;
        }
        else if (email[i] == '@' && islock) // 2 @
        {

            is_invalid = true;
            return i;   //tra ve vi tri @ thu 2
            break;
        }
    }
    // lay chuoi se
    if (pos_a != -55 && !is_invalid)
    {
         string se_local(email, pos_a);
         se = se_local;
    }
    else if (pos_a == -55) // email co 2 '@' / ko co co @/len > 100
    {
        return 0;
    }
    
    
    
    //8 va 20 ky tu
    if (strlen(s) < 8) return -1;
    if (strlen(s) > 20) return -2;
    // S chua se
    const char * pos_ses = strstr(s, se.c_str());
    int sei = pos_ses - s;
    if (pos_ses != nullptr) {
        return -(300 + sei); 
    }
    //chua nhieu hon 2 ky tu lien tiep giong nhau
    for (int i = 0; i < strlen(s) - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }
    //ko chua ky tu dac biet
    if (!have_special_character(s))
        return -5;
    //vi pham dieu kien s( chua ky tu dac biet ngoai !#$%@)
    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];
        if (!((s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || s[i] == 64 || s[i] == 35 || s[i] == 36 || s[i] == 37 || s[i] == 33)) {
            return i;
            break;
        }
    }
    return -10;

}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int counts[100] = {0};
    for (int i = 0; i < num_pwds; i++) {
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                counts[i]++;
            }
        }
    }

    int max_count = 0;
    char correct_password[100];
    for (int i = 0; i <= num_pwds; i++) {
        if ((counts[i] > max_count) || (counts[i] == max_count && strlen(arr_pwds[i]) > strlen(correct_password)))
        {
            strcpy(correct_password, arr_pwds[i]);
            max_count = counts[i];           
        }

    }
    for (int i = 0; i <= num_pwds; i++) {
        if (strcmp(arr_pwds[i], correct_password) == 0) {
            return i;
        }
    }


    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////