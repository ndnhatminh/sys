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
int firstMeet(int & exp1, int & exp2, int e1)
{
    // TODO: Complete this function
    if(e1 > 99 || e1 < 0)
        //nam ngoai pham vi cho phep
        return -99;

    exp1 = (0  > exp1) ? 0 : (exp1 > 600) ? 600 : exp1;
    exp2 = (0 > exp2) ? 0 : (exp2 > 600) ? 600 : exp2; 
    //from 0 to 3 
    if (e1>= 0 && e1 <= 3){
        if(e1 == 0) exp2+= 29;
        else if(e1 == 1) exp2 += 45; 
        else if(e1 == 2) exp2 += 75;
        else exp2 += 149;


        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0 ) 
            exp1 = ceil( exp1 +  (D + 0.0)/200) ;
        else 
            exp1 = ceil(exp1 -((D + 0.0)/100));
    }
    else
    {
    if (e1 >= 4 && e1 <= 19)
    { 
        exp2 = ceil(exp2 + (e1 + 0.0)/4 +19); //in range from 4 to 19
    }

    else if (e1 >= 20 && e1 <= 49)
    {
         exp2 =ceil(exp2 + (e1 + 0.0)/9 + 21);//in range from 20 to 49
    }
    else if (e1 >= 50 && e1 <= 65)
    {
         exp2 = ceil(exp2 + (e1+0.0)/16 + 17);//in range from 50 to 65
    }

    //range from 66 to 79
    if(e1 >= 66 && e1 <=79)
    {
        exp2 = ceil ( exp2 + (e1 + 0.0 ) / 4 + 19);
        if(exp2 > 200)
        {
            exp2 = ceil(exp2 + (e1 + 0.0) / 9 + 21);
        }       
    }


    //reange from 80 to 99
    if(e1>= 80 && e1 <= 99)
    {
        exp2 = ceil(exp2 + (e1 + 0.0) / 4 + 19);
        exp2 = ceil(exp2 + (e1 + 0.0) / 9 + 21);
        if(exp2>400)
        {
            exp2 = ceil(exp2 + (e1 +0.0) / 16 + 17);
            exp2 = ceil((exp2 +0.0) * 115 /100); 
        }
    }
    exp1 -= e1;
    }

    //sua exp cua 2 nguoi trong truong hop o ngoai 
    exp1 = (0  > exp1) ? 0 : (exp1 > 600) ? 600 : exp1;
    exp2 = (0 > exp2) ? 0 : (exp2 > 600) ? 600 : exp2; 
    
    return exp1 + exp2;
}
// Task 2
void buyingFood (int &HP1 , int &M1, int & usedM)
{
    if (HP1 < 200)
    {
        HP1 += ceil((HP1 + 0.0) * 0.3);
        M1 -= 150;
        usedM += 150;
    }
    else
    {
        HP1 += ceil((HP1 + 0.0) * 0.1);
        M1 -= 70;
        usedM +=70;
    }

    HP1 = (0 > HP1 ) ? 0 : ( HP1 > 666) ? 666 : HP1;
}
void transporting(int &EXP1,int & M1, int & usedM)
{
    if(EXP1 < 400)
    {
        M1 -= 200;
        usedM += 200;
    }
    else
    {
        M1 -= 120;
        usedM += 120;
    }
    EXP1 += ceil((EXP1 + 0.0) * 0.13); 
}
void meetTheHomeless(int &EXP1,int & M1, int & usedM)
{
    if (EXP1 < 300)
    {    
        M1 -= 100;
        usedM += 100;
    }
    else
    {   
        M1 -= 120;
        usedM += 120;
    }
    EXP1 = ceil((EXP1 + 0.0) * 0.9);
}
int traceLuggage(int &HP1, int &EXP1, int &M1, int e2)
{
    // Output initial values
    if (e2 > 99 || e2 < 0)
        //trong truong hop e2 nam ngoai pham vi cho phep
        return -99 ;
    


    M1 = (0 > M1) ? 0 : (M1 > 3000) ? 3000 : M1;
    EXP1 = ( 0 > EXP1) ? 0 : (EXP1 > 600) ? 600 : EXP1;
    HP1 = (0 > HP1) ? 0 : (HP1 > 666) ? 666 : HP1;

    
    
    //Road 1
    double p1; //probility for Sherlock on Road 1
    int S = round(sqrt(EXP1)) * round(sqrt(EXP1));
    if (EXP1 >= S)
        p1 = 1;
    else 
        p1 = ((EXP1 + 0.0) / S + 80) / 123.0;
    /*-------------------------------------------------------------------------*/

    //Road 2
    int usedM = 0 ;
    //e2 is odd
    if(e2 % 2 != 0)
    {
        int temp = ceil( (M1 + 0.0)  / 2 );
        while (temp > usedM)
        {
            //event 1
            buyingFood(HP1 ,M1 ,usedM);
            if(temp < usedM)
                break;
            
            M1 = (0 > M1) ? 0 : (M1 > 3000) ? 3000 : M1;
            HP1 = (0 > HP1 ) ? 0 : ( HP1 > 666) ? 666 : HP1;
            EXP1 = ( 0 > EXP1) ? 0 : (EXP1 > 600) ? 600 : EXP1;


            //event 2
            transporting(EXP1,M1, usedM);
            if(temp < usedM)
                break;
            
            M1 = (0 > M1) ? 0 : (M1 > 3000) ? 3000 : M1;
            HP1 = (0 > HP1 ) ? 0 : ( HP1 > 666) ? 666 : HP1;
            EXP1 = ( 0 > EXP1) ? 0 : (EXP1 > 600) ? 600 : EXP1;


            //event 3
            meetTheHomeless(EXP1, M1 , usedM);
            if(temp < usedM)
                break;

            M1 = (0 > M1) ? 0 : (M1 > 3000) ? 3000 : M1;
            HP1 = (0 > HP1 ) ? 0 : ( HP1 > 666) ? 666 : HP1;
            EXP1 = ( 0 > EXP1) ? 0 : (EXP1 > 600) ? 600 : EXP1;
        }
        HP1 = ceil((HP1 + 0.0) * 0.83);
        EXP1 = ceil((EXP1 + 0.0) * 1.17);
    }
    //e2 is even
    else
    {
        while (1)
        {
            buyingFood(HP1 ,M1 ,usedM);
            if( M1 <= 0)
                break;
            
            M1 = (0 > M1) ? 0 : (M1 > 3000) ? 3000 : M1;
            HP1 = (0 > HP1 ) ? 0 : ( HP1 > 666) ? 666 : HP1;
            EXP1 = ( 0 > EXP1) ? 0 : (EXP1 > 600) ? 600 : EXP1;

            transporting(EXP1,M1, usedM);
            if(M1 <= 0)
                break;
            
            M1 = (0 > M1) ? 0 : (M1 > 3000) ? 3000 : M1;
            HP1 = (0 > HP1 ) ? 0 : ( HP1 > 666) ? 666 : HP1;
            EXP1 = ( 0 > EXP1) ? 0 : (EXP1 > 600) ? 600 : EXP1;

            meetTheHomeless(EXP1,M1 ,usedM);
            if(M1 <= 0)
                break;

            M1 = (0 > M1) ? 0 : (M1 > 3000) ? 3000 : M1;
            HP1 = (0 > HP1 ) ? 0 : ( HP1 > 666) ? 666 : HP1;
            EXP1 = ( 0 > EXP1) ? 0 : (EXP1 > 600) ? 600 : EXP1;

            break;
        }

        HP1 = ceil((HP1 + 0.0) * 0.83);
        EXP1 = ceil((EXP1 + 0.0) * 1.17);
    }


    M1 = (0 > M1) ? 0 : (M1 > 3000) ? 3000 : M1;
    HP1 = (0 > HP1 ) ? 0 : ( HP1 > 666) ? 666 : HP1;
    EXP1 = ( 0 > EXP1) ? 0 : (EXP1 > 600) ? 600 : EXP1;
    double p2 ;
    S = round(sqrt(EXP1))* round(sqrt(EXP1));
    if ( EXP1 >= S)
        p2 = 1;
    else
        p2 = (( EXP1 + 0.0) / S  + 80 ) / 123;

    /*-----------------------------------------------------*/

    //Road 3
    int i = (e2 / 10 + e2 % 10) % 10;
    double P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double  p3  = P[i] /100;

    double average = (p1 + p2 + p3) / 3;

    //sherlock was wrong
    if (average == 1) {
        EXP1 = ceil((EXP1+0.0) * 0.75);
    } else if (average < 0.5) {
        HP1 = ceil((HP1 +0.0) * 0.85);
        EXP1 = ceil((EXP1 + 0.0) * 1.15);
    } else {
        HP1 = ceil((HP1 + 0.0) * 0.9);
        EXP1 = ceil((EXP1 + 0.0) * 1.2);
    }

    M1 = (0 > M1) ? 0 : (M1 > 3000) ? 3000 : M1;
    HP1 = (0 > HP1 ) ? 0 : ( HP1 > 666) ? 666 : HP1;
    EXP1 = ( 0 > EXP1) ? 0 : (EXP1 > 600) ? 600 : EXP1;

    return HP1 + EXP1 + M1;
}

// Task 3
int findthefinal(int n){
    while(n > 9)
    {
        n = n /10 + n % 10 ;
    }
    return n ;
}
int max(int n , int m){
    if(n > m ) return n ;
    return m ;
}
void findDiagnal(int matrix[10][10], int rowMeet, int columnMeet, int & sherlockWatson){
    for(int i = rowMeet ,  j = columnMeet ; i <= 9 && j <= 9 ; i++, j++){
        sherlockWatson = max( sherlockWatson , matrix[i][j]);
    }
    for(int i = rowMeet ,  j = columnMeet ; i >= 0 && j <= 9 ; i--, j++){
        sherlockWatson = max(sherlockWatson , matrix[i][j]);
    }
    for(int i = rowMeet ,  j = columnMeet ; i <= 9 && j >= 0 ; i++, j--){
        sherlockWatson = max(sherlockWatson , matrix[i][j]);
    }
    for(int i = rowMeet ,  j = columnMeet ; i >= 0 && j >= 0 ; i--, j--){
        sherlockWatson = max(sherlockWatson , matrix[i][j]);
    }
}
void creatematrixtaxi(int matrix[10][10], int E3,int &rowMeet , int & columnMeet ){ 
    for(int i = 0 ; i <10 ; i++){
        for (int j = 0; j < 10; j++)
        {
            matrix [i][j] = ((( E3 * j ) + ( 2 * i ) )*( i - j ));
            if(matrix[i][j] > E3 * 2) 
                rowMeet ++;
            if(matrix[i][j] < -E3)
                columnMeet++;
        }   

        
    }   
    rowMeet = findthefinal(rowMeet);
    columnMeet = findthefinal(columnMeet);
   
}
int changeEXPup(int n )
{
    n += ceil((n + 0.0) * 0.12);
    return n; 
}
int changeEXPdown(int n)
{
    n = ceil((n + 0.0) * 0.88);
    return n ;
}
int changeHPup(int n)
{
    n += ceil((n+0.0 ) * 0.1);
    return n ;
}
int changeHPdown(int n)
{
    n = ceil ((n +0.0) *0.9);
    return n ;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 > 99 || E3 < 0){
        //trong truong hop E3 nam ngoai pham vi cho phep
        return -99 ;
    }
    int matrix[10][10] = {0};
    int rowMeet = 0  , columnMeet = 0 ;


    creatematrixtaxi(matrix,E3,rowMeet , columnMeet);
   
    int sherlockWatson = -1000000;
    findDiagnal(matrix,rowMeet, columnMeet, sherlockWatson);
    int res;
    if(abs(matrix[rowMeet][columnMeet]) > sherlockWatson)
    {
        EXP1 = changeEXPdown(EXP1);
        HP1 = changeHPdown(HP1);
        EXP2 = changeEXPdown(EXP2);
        HP2 = changeHPdown(HP2);
        res = matrix[rowMeet][columnMeet];
    }
    else
    {
        EXP1 = changeEXPup(EXP1);
        HP1 = changeHPup(HP1);
        EXP2 = changeEXPup(EXP2);
        HP2 = changeHPup(HP2);
        res = sherlockWatson;
    }


    HP1 = (0 > HP1 ) ? 0 : ( HP1 > 666) ? 666 : HP1;
    EXP1 = ( 0 > EXP1) ? 0 : (EXP1 > 600) ? 600 : EXP1;
    HP2 = (0 > HP2 ) ? 0 : ( HP2 > 666) ? 666 : HP2;
    EXP2 = ( 0 > EXP2) ? 0 : (EXP2 > 600) ? 600 : EXP2;

    /*----------------------------------------------------------*/
    
    return res;
}

// Task 4
bool myLength(const char * s){
    int n = strlen(s);
    if ( n >= 8 && n <= 20) 
        return 1 ; 
    return 0 ;
}
bool  haveSpecialChar( const char * s){
    int temp = strlen(s);
    for(int i = 0 ; i < temp ; i++)
    {
        if(s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$') 
            return 1; 
    }
    return 0 ;
}
bool notHaveSe(const char *s, const char *se, int &pos) {
    int temp1 = strlen(s), temp2 = strlen(se);
    for (int i = 0; i < temp1; i++) {
        if (s[i] == se[0] && s[i] != '\0') {
            int j;
            for (j = 0; j < temp2; j++) {
                if (s[i + j] != se[j])
                {
                    break;
                }
            }
            if (j == temp2) 
            {
                pos = i;
                return 0; 
            }
        }
    }
    return 1; 
}
bool notHavesSameChar(const char * c, int & pos){
    int temp = strlen(c);
    for(int i = 0 ; i < temp ; i++){
        if(c[i] == c[i+1]  && c[i] == c[i+ 2]){
            pos =i;
            return 0; 
        }
    }
    return 1 ;
}
void haveViolatedChar(const char * s, int & pos , bool & violated){
    int temp = strlen(s);
    for(int i = 0 ; i < temp ; i++)
    {
        if(s[i] == 34 || (47 >= s[i] && s[i] >= 39) || (63 >= s[i] && s[i] >= 58) || (96 >= s[i] && s[i] >= 91) ||(126 >= s[i] && s[i] >= 123) )
        {
            violated = 1 ;
            pos = i ;
            break;  
        }
    }
}
void takeSe( char se[],const string & email){
    for (int i = 0; i < 100; i++)
    {
        if(email[i] == '@'){
            se[i] = '\0';
            break; 
        }
        se[i] = email[i];
    }
}

int checkPassword(const char * s, const char * email) 
{
    bool violated = 0 ;
    int pos = 0 ;
    char se[100];
    int temp = strlen(s);
    takeSe(se, email);
    haveViolatedChar(s, pos , violated);
    if(myLength(s) && haveSpecialChar(s) && notHaveSe(s,se,pos) && notHavesSameChar(s,pos))
        return -10;
    //do dai qua ngan
    else if(temp < 8)
        return -1;
    //too long
    else if(temp > 20)
        return -2;
    //have se
    if( !notHaveSe(s,se,pos))
        return -(300 + pos);
    //have more than 2 characters
    else if(!notHavesSameChar(s,pos))
        return -(400 + pos);
    //no special character
    else if(!haveSpecialChar(s))
        return -5;
    else if(violated)
        return pos;
    return -1000;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
        // TODO: Complete this function
        bool check[num_pwds] = {0};
        int count = 0 ;
        int result;
        int max = - 1;
        const char * reschar;
        for (int i = 0; i < num_pwds; i++)
        {
            if (check[i])
            {
                continue;
            }
            for(int j = i  ; j< num_pwds; j++)
            {
                if(check[j]) 
                    continue;
                if(arr_pwds[i] == arr_pwds[j] ){
                    count++ ; 
                    check[j] = 1;
                }
            }
            if(count == max && strlen(arr_pwds[i]) > strlen(reschar))
            {
                reschar = arr_pwds[i];
                result = i;
            }
            else if(count > max)
            {
                max = count;
                reschar = arr_pwds[i];
                result = i;
            }
            count = 0 ;   
        }      
        return result;
    }
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////