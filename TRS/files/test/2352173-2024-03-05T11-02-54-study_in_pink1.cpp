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
//Additional function
void limitHP(int & HP)
{
    if (HP > 666)
    {
        HP = 666;
    }
    else if(HP < 0)
    {
        HP = 0;
    }
}
void limitEXP(int & EXP)
{
    if (EXP > 600)
    {
        EXP = 600;
    }
    else if(EXP < 0)
    {
        EXP = 0;
    }
}
void limitMoney(int & M)
{
    if (M > 3000)
    {
        M = 3000;
    }
    else if(M < 0)
    {
        M = 0;
    }
}
int find_S(int EXP) {
    int square = sqrt(EXP);
    if (square * square == EXP) {
        return EXP;
    }
    int lower = square * square;
    int higher = (square + 1) * (square + 1);
    // Return the closest perfect square
    if ((EXP - lower) < (higher - EXP) ) {
        return lower;
    } else {
        return higher;
    }
}
//Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    //Float variable for calculation
    double exp1_d = exp1;
    double exp2_d = exp2;
    double e1_d = e1;
    
    //Case 4.1.1
    if(e1_d >= 0 and e1_d <= 3)
    {
        switch(e1)
        {
            case 0:
                {
                    exp2_d = exp2_d + 29;
                    break;
                }
                case 1:
                {
                    exp2_d = exp2_d + 45;
                    break;
                }
                case 2:
                {
                    exp2_d = exp2_d + 75;
                    break;
                }
                case 3:
                {
                    exp2_d = exp2_d + 149;
                    break;
                }
        }
        int D = e1_d*3 + exp1_d*7;
        if (D % 2 == 0)
        {
            exp1_d = exp1_d + D/200;
            
            //cout << exp1 <<endl;
        }
        else
        {
            exp1_d = exp1_d - D/100;
        }
    }
    //Case 4.1.2
    else if(e1_d >= 4 and e1_d <= 19)//info 1
    {
        exp2_d = exp2_d + (e1_d /4 + 19);
        exp1_d = exp1_d - e1_d;
        
    }
    else if(e1_d >= 20 and e1_d <= 49)//info 2
    {
        exp2_d = exp2_d + (e1_d /9 + 21);
        exp1_d = exp1_d - e1;
    }
    else if(e1_d >= 50 and e1_d <= 65)//info 3
    {
        exp2_d = exp2_d + (e1_d /16 + 17);
        exp1_d = exp1_d - e1_d;
    }
    else if(e1_d >= 66 and e1_d <= 79)//info 1+2
    {
        exp2_d = exp2_d + (e1_d /4 + 19);
        if(exp2_d > 200)
        {
            exp2_d = exp2_d + (e1_d /9 + 21);
        }
        exp1_d = exp1_d - e1_d;
        
    }
    else if(e1_d >= 80 and e1_d <= 99)//info 1+2+3
    {
        exp2_d = ceil(exp2_d + (e1_d /4 + 19));
        
        exp2_d = ceil(exp2_d + (e1_d /9 + 21));
        
        if(exp2_d > 400)
        {
            exp2_d = ceil(exp2_d + (e1_d /16 + 17));
            exp2_d = ceil(exp2_d * 1.15);
            
        }
        exp1_d = exp1_d - e1_d;
    }
    else
    {
        return -99;
    }
    //Round up final result
    exp1 = ceil(exp1_d);
    exp2 = ceil(exp2_d);
    limitEXP(exp1);
    limitEXP(exp2);
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
// TODO: Complete this function
    double HP1_d = HP1;
    double EXP1_d = EXP1;
    //Road 1
        int S1 = find_S(EXP1);
        double P1;
        if (EXP1 >= S1)
        {
            P1 = 1;
        }
        else
        {
            P1 = (EXP1_d / S1 + 80)/123;
        }
    //Road 2
        int total_cost = 0;
        const int M1_start = M1;
        if (E2 % 2 == 1)//E2 is odd
        {
            while (total_cost <= 0.5 * M1_start)
                {
                //Event 1
                    if (HP1_d < 200)
                    {
                        HP1_d = ceil(HP1_d * 1.3);
                        M1 = M1 - 150;
                        total_cost = total_cost + 150;
                    }
                    else
                    {
                        HP1_d = ceil(HP1_d * 1.1);
                        M1 = M1 - 70;
                        total_cost = total_cost + 70;
                    }
                    if(total_cost > 0.5 * M1_start) 
                    {
                    break;
                    }
                //Event 2
                    if (EXP1_d < 400)
                    {
                        M1 = M1 - 200;
                        total_cost = total_cost + 200;
                    }
                    else
                    {
                        M1 = M1 - 120;
                        total_cost = total_cost + 120;
                    }
                    EXP1_d = ceil(EXP1_d * 1.13);
                    if(total_cost > 0.5 * M1_start) 
                    {
                        break;
                    }    
                //Event 3
                    if (EXP1_d < 300)
                    {
                        M1 = M1 - 100;
                        total_cost = total_cost + 100;
                    }
                    else
                    {
                        M1 = M1 - 120;
                        total_cost = total_cost + 120;
                    }
                    EXP1_d = ceil(EXP1_d * 0.9);
                    if(total_cost > 0.5 * M1_start) 
                    {
                        break;
                    }    
                }
            HP1_d = ceil(HP1_d * 0.83);
            EXP1_d = ceil(EXP1_d * 1.17);
        }
        else//E2 is even
        {
            //Event 1
                if (HP1_d < 200)
                {
                    HP1_d = ceil(HP1_d * 1.3);
                    M1 = M1 - 150;
                    total_cost = total_cost + 150;
                }
                else
                {
                    HP1_d = ceil(HP1_d * 1.1);
                    M1 = M1 - 70;
                    total_cost = total_cost + 70;
                }
            //Event 2
                if (EXP1_d < 400)
                {
                    M1 = M1 - 200;
                    total_cost = total_cost + 200;
                    }
                else
                {
                    M1 = M1 - 120;
                    total_cost = total_cost + 120;
                }
                EXP1_d = ceil(EXP1_d * 1.13);
            //Event 3
                if (EXP1_d < 300)
                {
                    M1 = M1 - 100;
                    total_cost = total_cost + 100;
                }
                else
                {
                    M1 = M1 - 120;
                    total_cost = total_cost + 120;
                }
                EXP1_d = ceil(EXP1_d * 0.9);
            if (total_cost > M1_start)
            {
                M1 = 0;
            }
        }
        int S2 = find_S(EXP1_d);
        double P2;
        if (EXP1_d >= S2)
        {
            P2 = 1;
        }
        else
        {
            P2 = (EXP1_d / S2 + 80)/123;
        }
    //Road 3
            double P3;
            int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
            if(E2 >= 0 and E2 <= 9)
            {
                P3 = P[E2] * 0.01;
            }
            else
            {
                int digit_sum = (E2 % 10 ) + (E2 / 10);
                int unit_place = digit_sum % 10;
                P3 = P[unit_place] * 0.01;
            }
    //Final percentage
    if( P1 == 1 and P2 == 1 and P3 == 1)
    {
        EXP1_d = EXP1_d * 0.75;
    }
    else 
    {
        double P_avg = (P1 + P2 + P3) / 3;
        if (P_avg < 0.5)
        {
            HP1_d= HP1_d * 0.85;
            EXP1_d = EXP1_d * 1.15;
        }
        else
        {
            HP1_d = HP1_d * 0.9;
            EXP1_d = EXP1_d * 1.2;
        }
    }
    //Round up final results
    HP1 = ceil(HP1_d);
    EXP1 = ceil(EXP1_d);
    limitHP(HP1);
    limitEXP(EXP1);
    limitMoney(M1);
    
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
// TODO: Complete this function
//Create 10 * 10  map. All initial value = 0
    int map_taxi[10][10];
    for (int i = 0; i < 10;i++)
    {
        for (int j = 0; j < 10;j++)
        {
            map_taxi[i][j] =  0;
        }
    }
//Calculate point for taxi
    for (int i = 0; i < 10;i++)
    {
        for (int j = 0; j < 10;j++)
        {
            map_taxi[i][j] =  ((E3 * j) + (i * 2)) * (i - j);
        }
    }
//Find meet coordinates
    int i_meet = 0;
    int j_meet = 0;
    for (int i = 0; i < 10;i++)
    {
        for (int j = 0; j < 10;j++)
        {
            if (map_taxi[i][j] > (E3 * 2) )
            {
                i_meet = i_meet + 1;
            }
            else if(map_taxi[i][j] < -E3 )
            {
                j_meet = j_meet + 1;
            }
        }
    }
    while(true)
        {
            if(i_meet >= 0 and i_meet <= 9)
            {
                break;
            }
            else
            {
                i_meet = (i_meet % 10 ) + (i_meet / 10);
            }
        }
    while(true)
        {
            if(j_meet >= 0 and j_meet <= 9)
            {
                break;
            }
            else
            {
                j_meet = (j_meet % 10 ) + (j_meet / 10);
            }
        }    
//Calculate point for Sherlock and Watson
    //Max point on left diagonal
    int i_left = i_meet;
    int j_left = j_meet;
    int left1 = map_taxi[i_meet][j_meet];
    while (i_left >= 0 and i_left <= 9 and j_left >= 0 and j_left <= 9  )
    {
        if(map_taxi[i_left][j_left] > left1)
        {
            left1 = map_taxi[i_left][j_left];
        }   
        i_left--;
        j_left--;
    }
    i_left = i_meet;
    j_left = j_meet;
    int left2 = map_taxi[i_meet][j_meet];
    while (i_left >= 0 and i_left <= 9 and j_left >= 0 and j_left <= 9  )
    {
        if(map_taxi[i_left][j_left] > left2)
        {
            left2 = map_taxi[i_left][j_left];
        }
        i_left++;
        j_left++;
    }
    int max_left;
    if (left1 >= left2)
    {
        max_left = left1;
    }
    else
    {
         max_left = left2;
    }
    //Max point on right diagonal
    int i_right = i_meet;
    int j_right = j_meet;
    int right1 = map_taxi[i_meet][j_meet];
    while (i_right >= 0 and i_right <= 9 and j_right >= 0 and j_right <= 9  )
    {
        if(map_taxi[i_right][j_right] > right1)
        {
            right1 = map_taxi[i_right][j_right];
        }   
        i_right++;
        j_right--;
    }
    i_right = i_meet;
    j_right = j_meet;
    int right2 = map_taxi[i_meet][j_meet];
    while (i_right >= 0 and i_right <= 9 and j_right >= 0 and j_right <= 9  )
    {
        if(map_taxi[i_right][j_right] > right2)
        {
            right2 = map_taxi[i_right][j_right];
        }
        i_right--;
        j_right++;
    }
    int max_right;
    if (right1 >= right2)
    {
        max_right = right1;
    }
    else
    {
         max_right = right2;
    }
    //Point of Sherlock and Watson at meet point
    int point_SW;
    if (max_left >= max_right)
    {
        point_SW = max_left;
    }
    else
    {
        point_SW = max_right;
    }
//Return final result
    if ( abs(map_taxi[i_meet][j_meet]) > point_SW )
    {
        EXP1 = EXP1 * 0.88;
        HP1 = HP1 * 0.9;
        EXP2 = EXP2 * 0.88;
        HP2 = HP2 * 0.9;
        
        limitEXP(EXP1);
        limitHP(HP1);
        limitEXP(EXP2);
        limitHP(HP2);
        return map_taxi[i_meet][j_meet];
    }
    else
    {
        EXP1 = EXP1 * 1.12;
        HP1 = HP1 * 1.1;
        EXP2 = EXP2 * 1.12;
        HP2 = HP2 * 1.1;
        
        limitEXP(EXP1);
        limitHP(HP1);
        limitEXP(EXP2);
        limitHP(HP2);
        return point_SW;
    }
    return -99;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    //Declare se
    char se[strlen(email)] ;
    for (int i = 0; i < strlen(email); i++)
    {
        if ( email[i] == '@' )
        {
            break;
        }
        else
        {
            se[i] = email[i];
        }
    }
    //Check length of s
    bool checkLength;
    if ( strlen(s) < 8 )
    {
        return -1;
    }
    else if (strlen(s) > 20)
    {
        return -2;
    }
    else
    {
        checkLength = true;
    }
    //Check all character
    bool checkAllChar = true;
    char character[] = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@#%$!";
    size_t allChar =strlen(character);
    for (int i = 0; i < strlen(s); i++)
    {
        bool checkEachChar = false;
        for (int j = 0; j < allChar;j++)
        {
            if (s[i] == character[j] )
            {
                checkEachChar = true;
                break;
            }
            else
            {
                checkEachChar = false;
            }
        }
        if (checkEachChar == true)
        {
            checkAllChar  = true;
        }
        else
        {
            return i;
        }
    }
    //check for se in s
    bool check_se;
    int length_s = strlen(s);
    int length_se = strlen(se);

    for (int i = 0; i <= length_s - length_se; ++i) {
        int j;
        for (j = 0; j < length_se; ++j) {
            if (s[i + j] != se[j])
            {
                break;
            }
        }
        if (j == length_se)
        {
            return -(300 + i);
        }
        else
        {
            check_se = true;
        }
    }
    //Check 2 consecutive and identical characters
    bool checkTwo;
    for (int i = 0; i < strlen(s);i++)
    {
        if (s[i] != s[i + 1])
        {
            checkTwo = true;
        }
        else
        {
            return -(400 + i);
        }
        
    }
    //Check special character
    bool checkSpecial = false;
    char special[] = "@#%$!";
    size_t allSpecial =strlen(special);
    for (int i = 0; i < strlen(s); i++)
    {
        bool checkSpecialEach = false;
        for (int j = 0; j < allSpecial;j++)
        {
            if (s[i] == special[j] )
            {
                checkSpecialEach = true;
                break;
            }
            else
            {
                checkSpecialEach = false;
            }
        }
        if (checkSpecialEach == true)
        {
            checkSpecial  = true;
            break;
        }
    }
    if (checkSpecial == false)
        {
            return -5;
        }
    if(checkLength == 1 && checkAllChar == 1 && check_se == 1 && checkTwo == 1 && checkSpecial == 1 )
    {
        return -10;
    }
    
    return -99;
}

int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    //Declare max variable
    int max_freq = 0;
    int max_length = 0;
    const char* correct_pwd = nullptr;
    for (int i = 0; i < num_pwds; ++i) {
        //Update frequency of each password
        const char* current_pwd = arr_pwds[i];
        int current_freq = 1;
        int current_length = strlen(current_pwd);
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(current_pwd, arr_pwds[j]) == 0)
            {
                current_freq = current_freq + 1;
            }
        }
        //Check and update max values    
        if (current_freq > max_freq or (current_freq == max_freq and current_length > max_length) )
        {
            max_freq = current_freq;
            max_length = current_length;
            correct_pwd = current_pwd;
        }
    }
    //return index of corect pasword
    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(correct_pwd, arr_pwds[i]) == 0) {
            return i;
        }
    }
    return -1; // If no correct password found
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////