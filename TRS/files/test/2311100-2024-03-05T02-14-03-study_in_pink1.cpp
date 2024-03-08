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

//Three functions for checking out the range of those values

int check_HP(int &HP)
{
    if(HP >666)
    {
        HP = 666;
    }
    else if ( HP < 0 )
    {
        HP = 0;
    }

    return HP;
}

int check_exp(int &exp)
{
    if(exp > 600)
    {
        exp = 600;
    }
    else if ( exp < 0 )
    {
        exp = 0;
    }

    return exp;
}

int check_M(int & M)
{
    if(M > 3000)
    {
        M = 3000;
    }
    else if ( M < 0 )
    {
        M = 0;
    }

    return M;
}

// Round up the float number that bigger than it's interger position
int rounded(float k)
{
    if( k > (float)((int) k) )
    {
        k = (int) k + 1;
    }

    return k;
}


// Task 1

int identify_event(int E, int & exp1, int & exp2)
{
    int result = 0;
    switch (E)
    {
    // Bai 1.1
    case 0:
        exp2 += 29;
        check_exp(exp2);
        break;
    case 1:
        exp2 += 45;
        check_exp(exp2);
        break;
    case 2:
        exp2 += 75;
        check_exp(exp2);
        break;
    case 3:
        exp2 = exp2 + 29 + 45 + 75;
        check_exp(exp2);
        break;
        
    default: 
    {
        // Bai 1.2
        //Thong tin 1 
       if(E >= 4 && E <= 19){
            exp2 += rounded((float)E/4 + 19);
            check_exp(exp2);
       }
       // Thong tin 2
       else if(E >= 20 && E <= 49){
            exp2 += rounded((float)E/9 + 21);
            check_exp(exp2);
       }
       // Thong tin 3
       else if(E >= 50 && E <= 65)
       {
            exp2 += rounded((float)E/16 + 17);
            check_exp(exp2);
       }
       // Thong tin 4
       else if(E >= 66 && E <= 79)
       {
            exp2 += rounded((float)E/4 + 19);
            check_exp(exp2);

            if(exp2 > 200){
                exp2 += rounded((float)E/9 + 21);
                check_exp(exp2);
            }
       }
       // Thong tin 5
       else if(E >= 80 && E <= 99)
       {
            exp2 += rounded((float)E/4 + 19);
            check_exp(exp2);
            exp2 += rounded((float)E/9 + 21);
            check_exp(exp2);

            if(exp2 > 400)
            {
                exp2 += rounded((float)E/16 + 17);
                check_exp(exp2);
                exp2 += rounded((float)exp2*15/100);
                check_exp(exp2);
            }
       }
        else 
        result = -99;

        if ( E >= 4 && E <= 99 ){
            exp1 -= E;
            check_exp(exp1);
        }
    }
        break;
    }

    return result;
}

int case11(int & e1, int & exp1)
{
    int D = e1 * 3 + exp1 * 7;

    int k = D % 2;
    if(k)
    {
        exp1 = rounded((float)exp1 -D/100.0);
        check_exp(exp1);
    }
    else
    {
        exp1 = rounded((float)exp1 + D/200.0);
        check_exp(exp1);
    }
    return exp1;
}

// Main function in exercise 1
int firstMeet(int & exp1, int & exp2, int e1) 
{ 
    int result = identify_event(e1, exp1, exp2);

    if(result != -99)
    {
        if( e1 == 0 || e1 == 1 || e1 == 2 || e1 == 3 )
        {
            case11(e1, exp1);
        }
    }
    else 
    {
        return result;
    }

    return exp1 + exp2;
}






// Task 2

//Road 1
double road1(int EXP)
{
    double P;
    int S;
    int S1 ;
    int S2 ;
    for(int i = 0; i*i <= EXP ; i++)
    {
        S1 = i+1;
        S2 = i;
    }
    

    if(S1*S1 + S2*S2 > 2*EXP )
        S = (int) S2;
    else
        S = (int) S1;


    if((int) EXP >= (int) S*S )
        P = 100;
    else 
        P = (double)((double)EXP/(S*S) + 80.0 )*100.0/ 123.0;

    return P;
}

//Road 2 
//Buying foods, drinks 
void health(int & HP, int & M)
{
    if (HP < 200)
    {
        HP = rounded((float) HP *1.3);
        M -= 150;
    }
    else
    {
        HP = rounded((float) HP *1.1);
        M -= 70;
    }
    check_HP(HP);
    check_M(M);
}

//Car or horse
void transport(int & EXP , int & M)
{
    if( EXP < 400)
        M -= 200;
    else 
        M -= 120;

    check_M(M);
    EXP = rounded((float) EXP *1.13);
    check_exp(EXP);
}

// Help from a homeless man
void clue(int & EXP , int & M)
{
    if(EXP < 300)
        M -= 100;
    else 
        M -= 120;

    check_M(M);

    EXP = rounded((float) EXP * 0.9);
    check_exp(EXP);
}

// Checking the fee from 3 routes on case 2
void fee(int & HP, int & EXP, int & M, float amount)
{
    int k=0;
    int M0 = M*amount;
    for( ; (M >= M0 && M > 0 && k >= 0 ) ; )
    {   
        if( (k % 3) == 0)
            health(HP, M);
        else if ((k % 3) == 1 )
            transport(EXP, M);
        else if ((k % 3) == 2 )
            clue(EXP , M);

        k++;

        //for E2 even
        if(amount == 0 && k == 3)
            k = -1;
    }
}


double road2(int E, int & HP, int & EXP, int & M )
{
    if (E % 2)
        fee(HP, EXP, M, 0.5);
    else
        fee(HP, EXP, M, 0);

    HP = rounded((float) HP *0.83);
    EXP = rounded((float) EXP *1.17);
    check_HP(HP);
    check_exp(EXP);

    int result = road1(EXP);
    return result;
}

// Road 3 
double road3(int E)
{
    int P[10]= {32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    
        // Finding out idex num 
        int num1 =(int) E/10;
        int num2 = E%10;
        int num = num1 + num2;
        int i = num %10;

    return P[i];
}

//Main function in exercise 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {

    if(E2 <0 || E2 > 99)
    {
        return -99;
    }

    double P1 = road1(EXP1);
    double P2 = road2(E2, HP1, EXP1, M1);
    double P3 = road3(E2);
    double avgP = (P1 + P2 + P3)/3;

    if ( P1 == 100 && P2 == 100 && P3 == 100 )
    {
        EXP1 = rounded((float)EXP1 *0.75);
        check_exp(EXP1);
    }
    else if (avgP < 50 )
    {
        HP1 = rounded((float)HP1 *0.85);
        EXP1 = rounded((float)EXP1 *1.15);
        check_HP(HP1);
        check_exp(EXP1);
    }
    else
    {
        HP1 = rounded((float)HP1 *0.9);
        EXP1 = rounded((float)EXP1 *1.2);
        check_HP(HP1);
        check_exp(EXP1);
    }

    return HP1 + EXP1 + M1;
}






// Task 3

int evaluate_count(int & num)
{
    int num1 , num2; // decimal position values 
    for(int i=0; i < 2 ; i++)
    {
        num1 = num /10;
        num2 = num %10;
        num = num1 + num2;
    }
    
    return num;
}

int count_i_or_j(int point_array[10][10], int E, int amount)
{
    int k = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(amount >0){
                if(point_array[i][j] > amount*E) 
                    k++;
            }
            else {
                if(point_array[i][j] < amount*E)
                    k++;
            }
        }
    }
    return k;
}

int max_point(int point_array[10][10], int i, int j)
{
    // Assign max_point the lowest value of the matrix
    // Preventing 0 is the highest num in those range of negative values
    int max_point;
    for(int m = 0; m < 10; m++){
        for(int n = 0; n < 10; n++){
            if (max_point >= point_array[m][n])
                max_point = point_array[m][n];
        }
    }

    int m0 = 0;
    int n0 = 0;
    int left_right = 1;

    
    if( i >= j)
        m0= i - j;
    else 
        n0= j - i;


    // Checking the left diagonal 
    for( ; m0 >= 0 && m0 < 10; m0 += left_right )
    {
        for( ; n0 >= 0 && n0 < 10; )
        {
            if(max_point < point_array[m0][n0])
                max_point = point_array[m0][n0];

            // Checking the right diagonal
            if((n0 == 9 || m0 == 9) && (left_right == 1)) 
            {
                left_right = -1;

                if( (i+j) < 10  )
                {
                    m0 = i + j + 1;
                    n0 = -1;
                }
                else
                {
                    m0 = 10;
                    n0 = abs(i+j-9) - 1;
                }
            }
            
            n0++;
            break;
        }
    }

    return max_point;
}

int calculate(int point_taxi, int point_Holmes_John, int & EXP1, int & EXP2, int & HP1, int & HP2)
{
    int max;
    if(abs(point_taxi) > abs(point_Holmes_John)){
        EXP1 = rounded((float) EXP1 *0.88);
        EXP2 = rounded((float) EXP2 *0.88);
        HP1 = rounded((float) HP1 *0.9);
        HP2 = rounded((float) HP2 *0.9);
        max = point_taxi;
    }
    else{
        EXP1 = rounded((float) EXP1 *1.12);
        EXP2 = rounded((float) EXP2 *1.12);
        HP1 = rounded((float) HP1 *1.1);
        HP2 = rounded((float) HP2 *1.1);
        max = point_Holmes_John;
    }

    check_exp(EXP1);
    check_exp(EXP2);
    check_HP(HP1);
    check_HP(HP2);

    return max;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    if(E3 < 0 || E3 > 99)
    {
        return -99;
    }
    // i and j are dimensional positions
    //declaring the array that contain point of the taxi 
    int point_array[10][10];
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            point_array[i][j] = ((E3*j) + (i*2))*(i-j) ;
    
    int i = count_i_or_j(point_array, E3, 2);
    int j = count_i_or_j(point_array, E3, -1);

    i = evaluate_count(i);
    j = evaluate_count(j);

    int point_taxi = point_array[i][j];
    int point_Holmes_John = max_point(point_array,i,j);

    int result = calculate( point_taxi, point_Holmes_John, EXP1, EXP2, HP1, HP2);

    return result;
}







// Task 4
// Increasing index num for checking the size of s
int length_array(const char * s, int & size_s)
{
    int result = 0;
    
    while(s[size_s] != '\0') // While existing a letter, the size_s is  not stop increasing
        size_s++;
    
    //Conditions
    if( size_s < 8 )
        result =  -1;
    else if( size_s > 20  )
        result = -2;

    return result;
}

int check_se(const char * s, const char * email , int size_s)
{
    //Finding out se sequence
    char se[1000] ; 
    int size_se = 0;

    // Assign the value of sequence befor @ in email to se 
    while(email[size_se] != '@')
        size_se++;

    for(int i = 0; i < size_se ; i++)
        se[i] = email[i];

    se[size_se] = '\0';
    

    int same = 0;
    int result = 0;
    
    if(se[0] == '\0')
    {
        return -300;
    }

    for (int j = 0; j <= size_s - 1 ; j++ )
    {
        if( s[j] == se[0] )
        {
            for(int k = j; k <=  size_s  - 1;  k ++)
            {
                if( s[k] == se[k-j])
                    same ++;
                else 
                {
                    k = size_s  + 1;
                    same = 0;
                }
                
                if(same == size_se)
                {
                    result = -(300 + j);
                    return result;
                }
                
            }
        }

        
    }

    return result;
}

int two_letters(const char * s, int size_s)
{
    int result = 0;

    for(int i = 0; i <= size_s - 2; i++ )
    {
        if(s[i] == s[i+1])
        {
            if(s[i+1] == s[i+2])
            {
                result = -(400 + i);
                return result;
            }
        }
    
    }    
    
    return result;
}

int out_special_letter(const char* s, int size_s, int & position,int & out_special_at_first)
{
    int n = 0 ;
    for( ; n < size_s  ; n++)
    {
        char h = s[n];
        (int) h;

        if( (      (h >= 48 &&  h <= 57) 
                || (h >= 64 && h <= 90)  
                || (h >= 97 && h <= 122) 
                || h == 33 || h == 35 
                || h == 36 || h == 37  ) == 0 )
        {
            if(n == 0)
            out_special_at_first =1;
            
            return n ;
        }

    }

    return position;
}

int special_letter(const char * s, int size_s, int & out_special_at_first)
{
    int result = 0;
    char special[] = {'@', '#', '%', '$', '!','\0'};

    for(int i = 0; i <= size_s - 1; i++ ) //for s
    {
        for(int k = 0; k <= 5 ; k++ )
        {
            if(s[i] != special[k])
            {
                if(k == 5)
                {
                    if(i == size_s - 1)
                    {
                        return -5;
                    }
                }
            }
            else if(s[i] == special[k])
            {
                i = size_s + 1; // Because it contain all the needed letter, so can be out 
            }
        }
    }

    int position = 0;
    int m = out_special_letter(s, size_s,position,out_special_at_first);
    
    if((result == 0) && (out_special_at_first == 0))
    {
        if (m < size_s) // if s contains out_speacial letter 
            {
                return m;
            }
    }
    

    return result;
}

int checkPassword(const char * s, const char * email) 
{
    int result = 0;
    int size_s = 0;
    int out_special_at_first = 0;
    result = length_array(s, size_s);

    if(result == 0)
    {
        result = check_se(s,email, size_s);
        if(result == 0)
        {
            result = two_letters(s, size_s);
            if(result == 0)
            {
                result = special_letter(s, size_s,out_special_at_first);
                if((result == 0) && (out_special_at_first == 0))
                {
                    result = -10;
                }
            }
        }

    // LET'S FILL OUT MORE CONDITIONSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
    }
    
    return result;
}






// Task 5

struct password_count
{
    int count = 0;
    int length = 0;
};

void find_max_count_password(const char * arr_pwds[], int num_pwds, int & max_count, password_count member[])
{
    for(int i = 0; i < num_pwds ; i++)
    {  
        for(int k = 0; k < num_pwds ; k++)
        {
            if(strcmp(arr_pwds[k], arr_pwds[i])==0) // Compare two string whether its ascii value the same or not 
            {
                member[i].count ++;
            }
        }

        if(member[i].count > max_count )
        {
            max_count = member[i].count;
        }
    }
}

int find_length_of_max_count_password(const char * arr_pwds[] , int num_pwds, int max_count, int & max_length ,  password_count member[])
{
    int result = 0; // assigne the position of the needed password is 0

    for(int i = 0; i < num_pwds ; i ++)
    {
        member[i].length = strlen(arr_pwds[i]); // Figure out the length of the char string

        if(member[i].count == max_count )
        {
            if(member[i].length > max_length)
            {
                max_length = member[i].length;
                result = i;
            }
        }
    }

    return result;
}

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    
    
    int max_count = 0;
    int max_length = 0;
    password_count member[num_pwds];
    
    find_max_count_password(arr_pwds, num_pwds, max_count, member);

    int result = find_length_of_max_count_password( arr_pwds ,num_pwds, max_count, max_length, member); 


    return result;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////