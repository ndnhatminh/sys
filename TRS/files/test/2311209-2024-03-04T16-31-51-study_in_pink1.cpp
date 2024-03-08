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
void check_exp1_exp2(int & exp1,int & exp2){
    if (exp1 < 0) exp1 = 0;
    if (exp1 > 600) exp1 = 600;
    if (exp2 < 0) exp2 = 0;
    if (exp2 > 600) exp2 = 600;
}
void check_HP1_EXP1(int & HP1,int & exp1){
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (exp1 < 0) exp1 = 0;
    if (exp1 > 600) exp1 = 600;
}
void check_HP1_EXP1_M1(int & HP1,int & exp1, int & M1){
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (exp1 < 0) exp1 = 0;
    if (exp1 > 600) exp1 = 600;
    if (M1 < 0) M1 = 0;
    if (M1 > 3000) M1 = 3000;
}
void M1_M2(int & M1, int & M2){
    if (M1 < 0) M1 = 0;
    if (M1 > 3000) M1 = 3000;
    if (M2 < 0) M2 = 0;
    if (M2 > 3000) M2 = 3000;
}
void check_HP_EXP(int & HP1,int & exp1,int & HP2, int & exp2){
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (exp1 < 0) exp1 = 0;
    if (exp1 > 600) exp1 = 600;
    if (HP2 < 0) HP2 = 0;
    if (HP2 > 666) HP2 = 666;
    if (exp2 < 0) exp2 = 0;
    if (exp2 > 600) exp2 = 600;
}
bool isPerfectSquare(int num) {
    int sqrtNum = sqrt(num);
    return sqrtNum * sqrtNum == num;
}


int findNearestPerfectSquare(int n) {
    if (isPerfectSquare(n)) {
        return n;
    }

    int lowerSquare = 0;
    int upperSquare = 0;
    for (int i = n - 1; i > 0; --i) {
        if (isPerfectSquare(i)) {
            lowerSquare = i;
            break;
        }
    }

    for (int i = n + 1;; ++i) {
        if (isPerfectSquare(i)) {
            upperSquare = i;
            break;
        }
    }

    if (abs(lowerSquare - n) < abs(upperSquare - n)) {
        return lowerSquare;
    } else {
        return upperSquare;
    }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    if (e1 < 0 || e1 > 99) return -99;
    check_exp1_exp2(exp1, exp2);
    if ( e1 <= 3)
    {
         switch (e1) {
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
                exp2 += 149;
                break;
        }
        int D = e1*3 + exp1 * 7;
        if (D % 2 == 0) exp1 = int(exp1 + D/200.0 + 0.9999);
        else exp1 = int(exp1 - D/100.0 + 0.9999);
        
    }
    else if (e1 > 3){
        if (e1 <= 19)
        {
            exp2 = int(exp2 + (e1/4.0 + 19) + 0.9999);
        }
        else if (e1 <= 49)
        {
            exp2 = int(exp2 + (e1/9.0 + 21) + 0.9999);
        }
        else if (e1 <= 65)
        {
            exp2 = int(exp2 + (e1/16.0 + 17) + 0.9999);
        }
        else if (e1 <= 79)
        {
            exp2 = int(exp2 + (e1/4.0 + 19) + 0.9999);
            if (exp2 > 200)
            {
                exp2 = int(exp2 + (e1/9.0 + 21) + 0.9999);
            }
            
        }
        else {
            exp2 = int(exp2 + (e1/4.0 + 19) + 0.9999);
            exp2 = int(exp2 + (e1/9.0 + 21) + 0.9999);
            if (exp2 > 400)
            {
                exp2 = int(exp2 + (e1/16.0 + 17) + 0.9999);
                exp2 = int(exp2*1.15 + 0.9999);
            }
            
        }
        exp1 = exp1 - e1;
        
    }
    check_exp1_exp2(exp1, exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    
    if (E2 < 0 || E2 > 99) return -99;
    check_HP1_EXP1_M1( HP1, EXP1, M1);
    int S;
    float P1,P2,P3;
    float Money = M1 * 0.5;
    //Con đường 1
    if (findNearestPerfectSquare(EXP1) <= EXP1 ) P1 = 1;
    else {
        P1 = (EXP1*1.0/findNearestPerfectSquare(EXP1) + 80.0)/123.0;
    }
    
    //Con đường 2
    if (E2 % 2 != 0){
        while (Money > 0)
        {
            if (HP1 < 200)      
            {   
                HP1 = int(HP1*1.3 + 0.9999);
                Money -= 150;
                M1 -= 150;
            }
            else {
                HP1 = int(HP1*1.1 + 0.9999);
                Money -= 70;
                M1 -= 70;
            }
            check_HP1_EXP1( HP1, EXP1);
            if (Money < 0) break;

            if (EXP1 < 400) {
                Money -= 200;
                M1 -= 200;
            }
            else {
                Money -= 120;
                M1 -= 120;
            }
            EXP1 = int(EXP1*1.13 + 0.9999);
            check_HP1_EXP1( HP1, EXP1);
            if (Money <= 0) break;

            if (EXP1 < 300 ) {
                Money -= 100;
                M1 -= 100;
            }
            else {
                Money -= 120;
                M1 -= 120;
            }
            EXP1 = int(EXP1*0.9 + 0.9999);
            check_HP1_EXP1( HP1, EXP1);
            if (Money < 0) break;
        }
    }
    else {
        int i = 1;
        while (i && M1 > 0)
        {
            if (HP1 < 200)      
            {   
                HP1 = int(HP1*1.3 + 0.9999);
                Money -= 150;
                M1 -= 150;
            }
            else {
                HP1 = int(HP1*1.1 + 0.9999);
                Money -= 70;
                M1 -= 70;
            }
            check_HP1_EXP1( HP1, EXP1);
            if (M1 <= 0) break;

            if (EXP1 < 400) {
                Money -= 200;
                M1 -= 200;
            }
            else {
                Money -= 120;
                M1 -= 120;
            }
            EXP1 = int(EXP1*1.13 + 0.9999);
            check_HP1_EXP1( HP1, EXP1);
            if (M1 <= 0) break;

            if (EXP1 < 300 ) {
                Money -= 100;
                M1 -= 100;
            }
            else {
                Money -= 120;
                M1 -= 120;
            }
            EXP1 = int(EXP1*0.9 + 0.9999);
            check_HP1_EXP1( HP1, EXP1);
            if (M1 <= 0) break;
            i--;
        }  
    }
    HP1 = int(HP1 * 0.83 + 0.9999);
    EXP1 = int(EXP1 * 1.17 + 0.9999);
    check_HP1_EXP1_M1( HP1, EXP1, M1);
    if (findNearestPerfectSquare(EXP1) <= EXP1 ) P2 = 1;
    else {
        P2 = (EXP1*1.0/findNearestPerfectSquare(EXP1) + 80.0)/123.0;
    }

    //Con đường 3
    float P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int dem = E2;
    dem = dem/10 + dem%10;
    dem = dem% 10;
    P3 = P[dem]*0.01;
    float P_aver=(P1+P2+P3)/3.0;
    if (P_aver == 1) EXP1 = int(EXP1*0.75 + 0.9999);
    else if(P_aver < 0.5) {
        HP1 = int(HP1*0.85 + 0.9999);
        EXP1 = int(EXP1*1.15 + 0.9999);
    }
    else {
        HP1 = int(HP1*0.9 + 0.9999);
        EXP1 = int(EXP1*1.2 + 0.9999);
    }
    check_HP1_EXP1_M1( HP1, EXP1, M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    if (E3 < 0 || E3 > 99) return -99;
    check_HP_EXP( HP1, EXP1,  HP2, EXP2);
    int map[10][10];
    for (int i = 0;i<10;i++)
    {
        for (int j = 0; j < 10; j++)
        {
            map[i][j]=((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int count_i=0,count_j=0;
    for (int i = 0;i<10;i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j]>E3*2) count_i++;
            if (map[i][j]<-E3) count_j++;
        }
    }
    while (count_i>=10)
    {
        count_i=count_i/10+count_i%10;
    }
    while (count_j>=10)
    {
        count_j=count_j/10+count_j%10;
    }
    int max_value=map[count_i][count_j],i=count_i,j=count_j;
    while (i<10&&i>0&&j>0&&j<10)
    {
        if (map[i][j]>=max_value) max_value = map[i][j];
        i++;j++;
    }
    i = count_i - 1;j= count_j - 1;
    while (i<10&&i>0&&j>0&&j<10)
    {
        if (map[i][j]>=max_value) max_value = map[i][j];
        i--;j--;
    }
    i = count_i + 1;j= count_j - 1;
    while (i<10&&i>0&&j>0&&j<10)
    {
        if (map[i][j]>=max_value) max_value = map[i][j];
        i++;j--;
    }
    i = count_i - 1;j= count_j + 1;
    while (i<10&&i>0&&j>0&&j<10)
    {
        if (map[i][j]>=max_value) max_value = map[i][j];
        i--;j++;
    }
    if (max_value >= abs(map[count_i][count_j]) ) {
        EXP1 = int(EXP1*1.12  + 0.9999);
        HP1 = int(HP1*1.1  + 0.9999);
        EXP2 = int(EXP2*1.12  + 0.9999);
        HP2 = int(HP2*1.1  + 0.9999);
        check_HP_EXP( HP1, EXP1,  HP2, EXP2);
        return max_value;
    }
    else {
        EXP1 = int(EXP1*0.88 + 0.9999 );
        HP1 = int(HP1*0.9 + 0.9999 );
        EXP2 = int(EXP2*0.88  + 0.9999);
        HP2 = int(HP2*0.9 + 0.9999 );
        check_HP_EXP( HP1, EXP1,  HP2, EXP2);
        return map[count_i][count_j];
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string emailStr(email);
    int atPosition = emailStr.find('@');
    string se = emailStr.substr(0, atPosition);
    int len = strlen(s);
    if (len < 8) {
        return -1; 
    }
    if (len > 20) {
        return -2; 
    }
    bool hasDigit = false;
    bool hasLower = false;
    bool hasUpper = false;
    bool hasSpecial = false;
    int a = -1,first_time = 0;
    string sStr(s);
    if (sStr.find(se) != string::npos) {
        return -(300 + sStr.find(se));     
    }
    for (int i = 0; i < len; i++) {
        char ch = s[i];
        if (s[i] == s[i + 1] && s[i] == s[i + 2] && i < len - 2) {
            return -(400+i);
        }
        if (isalnum(ch)) {
            if (isdigit(ch)) {
                hasDigit = true;
            } 
            else if (islower(ch)) {
                hasLower = true;
            } 
            else if (isupper(ch)) {
                hasUpper = true;
            }
        } 
        else {
            if(ch =='@' || ch == '!'|| ch == '#' || ch == '%' || ch == '$') hasSpecial = true;
            else {
                if (first_time == 0){
                    a = i;
                    first_time++;
                }
            } ;
        }
    }
    if (!hasSpecial) {
        return -5; 
    }
    if (a != -1)
    {
        return a;
    }
    
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_count = 0;
    int max_length = 0;
    int correct_index = 0;
    for (int i = 0; i < num_pwds; ++i) {
        const char *current_pwd = arr_pwds[i];
        int current_length = strlen(current_pwd);
        int count = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(current_pwd, arr_pwds[j]) == 0) {
                count++;
            }
        }
        if (count > max_count || (count == max_count && current_length > max_length)) {
            max_count = count;
            max_length = current_length;
            correct_index = i;
        }
    }
    return correct_index;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////