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


// FUNCTIONS TO CHECK STANDARD OF E, M EXP AND HP1
void check_EXP(int &a){
    if(a>600){
        a = 600;
    }
    else if (a<0){
        a = 0;
    }}

void check_HP(int &d){
    if(d>666){
        d = 666;
    }
    else if (d<0){
        d = 0;
    }}

void checkM(int &b){
    if(b>3000){
        b=3000;
    }
    else if (b<0){
        b=0;
    }}

bool checkE(int c){
    if (c<0 || c >99){
        return 1;
    }
    return 0;
}

//FUNCTION TO FIND THE NEAREST PERFECT SQUARE NUMBER
int nearestPerfectSquare(int exp1) {

    int root = sqrt(exp1);
    if(root*root == exp1){
        return root*root;
    }
    int lower = root * root;
    int higher = (root + 1) * (root + 1);
    if (abs(lower-exp1)< abs(higher - exp1)){
        return lower;
    }
    else{
        return higher;}}




// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
// TODO: Complete this function

//CHECK THE STANDARD OF E, EXP1 AND EXP2
    if(checkE(e1)){
        return -99;
    };
    check_EXP(exp1);
    check_EXP(exp2);

//CALCULATIONS FOR CASE 1
    if (0<= e1 && e1 <= 3){ 
        switch (e1) {
            case 0:
                exp2 = exp2 + 29;
                
                break;
            case 1:
                exp2 = exp2 + 45;
                break;
            case 2:
                exp2 = exp2 + 75;
                break;
            case 3:
                exp2 = exp2 + 29 + 45 + 75;
    
            default:
                
                break; 
            }

    check_EXP(exp1);
    check_EXP(exp2);

//CALCULATE D            
        int D = e1*3 + exp1*7;
        if ((D % 2) == 0){
            exp1 = ceil(float(exp1 + D/200.0)-1e-10);
             
        }
        else {
            exp1 = ceil(float(exp1 - D/100.0)-1e-10);
            
    
        }}
        
        
//CALCULATION FOR CASE 2
    else if(4<=e1 && e1 <= 19){
                exp2 = ceil(float(exp2 + e1/4.0 + 19)-1e-10);

                exp1 = exp1 - e1;
            }
    else if(20<= e1 && e1<= 49){
                exp2 = ceil(float(exp2+ e1/9.0 + 21)-1e-10);
            

                exp1 = exp1 - e1;              
            }
    else if(50 <= e1 && e1 <= 65){
                exp2 = ceil(float(exp2 + e1/16.0 + 17)-1e-10);

                exp1 = exp1 - e1;              
            }
    else if(66<= e1 && e1 <= 79){
                exp2 = ceil(float(exp2 + e1/4.0 + 19)-1e-10);
                check_EXP(exp2);  
                if (exp2 > 200){
                    exp2 = ceil(float(exp2 + e1/9.0 + 21)-1e-10);
                
                }
                exp1 = exp1 - e1;           
            } 
    else{
                exp2 = ceil(float(exp2 + (e1/4.0 + 19))-1e-10);
                check_EXP(exp2);
                exp2 = ceil(float(exp2 + (e1/9.0 + 21))-1e-10);
                check_EXP(exp2); 
                if (exp2 > 400){
                    exp2 = ceil(float(exp2 + (e1/16.0 + 17))-1e-10); 
                
                    check_EXP(exp2);
                    exp2 = ceil(float(exp2*1.15)-1e-10);
                      
                     
                }  
                exp1 = exp1 - e1;                       
            }               
    check_EXP(exp1);
    check_EXP(exp2);
    return exp1 + exp2;
    
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
// TODO: Complete this function
//CHECK THE STANDARD OF HP1, EXP1, M1 AND E2
    if(checkE(E2)){
        return -99;
    };
    check_EXP(EXP1);
    checkM(M1);
    check_HP(HP1);

//CALCULATION FOR P1
//THE FIRST ROAD
    float S = nearestPerfectSquare(EXP1);
    float p1 = 1.0;
    if (S<= EXP1){
        p1 = 1.0 ;
    }
    else {
        
        p1 = double((EXP1/S +80))/123;
        
    }

//THE SECOND ROAD
    float Half_money = M1*0.5;
    if(M1>0){
    if (E2%2 == 0){
        if(M1>0){
        if(HP1<200){
            M1 = M1 -150;
            HP1 = ceil(float(HP1*1.30)-1e-10);
            }
        else {
            M1 = M1 -70;
            HP1 = ceil(float(HP1*1.10)-1e-10);
            }
        check_HP(HP1);
        checkM(M1);
        }
        if(M1>0){
        if(EXP1<400){
            M1 = M1-200;
            }
        else {
            M1 = M1-120;
            }
        EXP1 = ceil(float(EXP1*1.13)-1e-10);
        check_HP(HP1);
        checkM(M1);
        check_EXP(EXP1);
        }
        if(M1>0){
        if(EXP1<300){
            M1 = M1-100;
            }
        else {
            M1 = M1-120;
            }
        EXP1 = ceil(float(EXP1*0.9)-1e-10);
        check_HP(HP1);
        checkM(M1);
        check_EXP(EXP1);
        }
    }
    else{
        int money_spent = 0;
        while (money_spent<=Half_money){
            if(HP1<200){
                M1 = M1 -150;
                money_spent = money_spent + 150;
                HP1 = ceil(float(HP1*1.30)-1e-10);
            }
            else {
                M1 = M1 -70;
                money_spent = money_spent + 70;
                HP1 = ceil(float(HP1*1.10)-1e-10);
            }
            check_HP(HP1);
            checkM(M1);
            if(money_spent>Half_money){
                break;
            }
            if(EXP1<400){
                M1 = M1-200;
                money_spent = money_spent + 200;
            }
            else {
                M1 = M1-120;
                money_spent = money_spent + 120;
                
            }
            EXP1 = ceil(float(EXP1*1.13)-1e-10);
            check_HP(HP1);
            checkM(M1);
            check_EXP(EXP1);
            
            if(money_spent>Half_money){
                break;}
            if(EXP1<300){
                M1 = M1-100;
                money_spent = money_spent + 100;
            }
            else {
                
                M1 = M1-120;
                money_spent = money_spent + 120;
                
               
            }
            EXP1 = ceil(float(EXP1*0.9)-1e-10);
            check_HP(HP1);
            checkM(M1);
            check_EXP(EXP1);
        }    
        
    }
    }
    HP1 = ceil(float(HP1*0.83)-1e-10);
    EXP1 = ceil(float(EXP1*1.17)-1e-10);
    check_HP(HP1);
    check_EXP(EXP1);

    float K = nearestPerfectSquare(EXP1);
    float p2 = 1.0;
    if (K<= EXP1){
        p2 = 1.0 ;
    }
    else {
        p2 = double((EXP1/K +80))/123;
        
    }
//THE THIRD ROAD
    float array[10] = {0.32,0.47,0.28,0.79,1.0,0.50,0.22,0.83,0.64,0.11};
    float p3;
    if(0<= E2 && E2 <10 ) {
        p3 = array[E2];
    }      
    else{
        int total = (E2/10) + (E2%10);
        total = total%10;
        p3 = array[total];
    }
    
    if ((p1 + p2 + p3)/3 == 1.0){
        EXP1 = ceil(float(EXP1*0.75)-1e-10);
        
    } 
    else if((p1 + p2 + p3)/3 <0.5){
        EXP1 = ceil(float(EXP1*1.15)-1e-10);
        HP1 = ceil(float(HP1*0.85)-1e-10);        
    }
    else if((p1 + p2 + p3)/3 >=0.5){
        EXP1 = ceil(float(EXP1*1.20)-1e-10);
        HP1 = ceil(float(HP1*0.90)-1e-10);
        
            }
    
    check_EXP(EXP1);
    checkM(M1);
    check_EXP(EXP1);
    
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
// TODO: Complete this function
// CHECKING STANDARD OF HP1, EXP1, HP2, EXP2 AND E3

    if(checkE(E3)){
        return -99;
    }
    check_HP(HP1);
    check_HP(HP2);
    check_EXP(EXP1);
    check_EXP(EXP2);
//CREATION OF THE MATRIX OF THE TAXI'S SCORE
    int taximatrix[10][10];
    for(int i=0; i<10;i++){
        for(int j=0;j<10;j++){
            taximatrix[i][j] = ((E3*j)+(i*2))*(i-j);
        }
    }

//FINDING THE MEETING POINT
    int pos_points =0;
    int neg_points =0;
    for(int i=0; i<10;i++){
        for(int j=0;j<10;j++){
            if(taximatrix[i][j]>(E3*2)){
                pos_points++;
            }
            if(taximatrix[i][j]<(-E3)) {
                neg_points++;
            }
            
        }
    }
    while(pos_points >= 10){
        pos_points = (pos_points/10) + (pos_points%10);
    }
    while(neg_points >= 10){
        neg_points = (neg_points/10) + (neg_points%10);
    }

/*FINDING THE SCORE OF SHERLOCK
EXPLAINATION FOR THE ALGORITHM OF FINDING LEFT AND RIGHT DIAGONAL
FOR EVERY POINTS ON THE LEFT DIAGONAL, THEY HAVE THE SAME EXPRESION (i-j) WHILE 'i' AND 'j' ARE THE COORDINATE OF THAT POINTS
FOR EVERY POINTS ON THE LEFT DIAGONAL, THEY HAVE THE SAME EXPRESION (i+j) WHILE 'i' AND 'j' ARE THE COORDINATE OF THAT POINTS
SO  USING THAT, WE CAN FIND EVERY POINTS ON THE TWO DIAGONAL AT THE MEETING POINT

*/

    int sherlock_score = -10000000;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if (((i-j) == (pos_points - neg_points)) || ((i+j)==(pos_points+neg_points))){
                if(taximatrix[i][j]>=sherlock_score){
                    sherlock_score = taximatrix[i][j];
                }
                 
                
                
            }
        }
    }

    if(sherlock_score<0){
        sherlock_score = abs(sherlock_score);
    }
//SETTING EXP1, EXP2, HP1, HP2
    if((abs(taximatrix[pos_points][neg_points])) > sherlock_score){
        EXP1=ceil(float(EXP1*0.88)-1e-10);
        EXP2=ceil(float(EXP2*0.88)-1e-10);
        HP1=ceil(float(HP1*0.9)-1e-10);
        HP2= ceil(float(HP2*0.9)-1e-10);        

    }
    else {
        EXP1=ceil((float)EXP1*1.12-1e-10);
        EXP2=ceil((float)EXP2*1.12-1e-10);
        HP1=ceil(float(HP1*1.10)-1e-10);
        HP2= ceil(float(HP2*1.10)-1e-10);
    }

    check_HP(HP1);
    check_HP(HP2);
    check_EXP(EXP1);
    check_EXP(EXP2);

    if((abs(taximatrix[pos_points][neg_points])) > sherlock_score){
        return taximatrix[pos_points][neg_points];
    }
    else {
        return sherlock_score;
    }    
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
// TODO: Complete this function
//MAKING A COPY OF 's' AND 'email' WITH TYPE 'STRING'

    string Strs = string(s);
    string Stremail = string(email);
    int size = strlen(s);
//CHECKING THE LENGTH OF THE PASSWORD
    if (size < 8) {
        return -1; 
    }
    if (size > 20) {
        return -2; 
    }
//FINDING THE POSITION OF '@' AND CREATE 'SE'
    int pos_alpha = Stremail.find('@');
    string se = Stremail.substr(0, pos_alpha);
//CHECKING IF 'SE' BELONG TO 's'
    if (Strs.find(se) != string::npos) {
    return -(300 + Strs.find(se)); 
    }

//CHEKING IF THE PASSWORD HAVE THE IVALID SYMBOL OR DO NOT HAVE ANY SPECIFIC SYMBOL
    bool atleast1symbol = false;
    bool hasivalidchar = false;

    for (int i = 0; i < size ; ++i) {
        
        char c = s[i];
        if (!(('0'<=c && c<='9') || ('a'<=c && c<='z') || ('A'<=c&&c<='Z')|| (c == '@') || (c == '#') || (c == '%') || (c == '$') || (c == '!'))) {
            hasivalidchar = true;
        }        
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
            atleast1symbol = true;
        }        
                 
    }
//CHECKING IF THE PASSWORD HAVE 2 CONSECUTIVE CHARACTER
    for(int i=1;i<size;i++){
        if (s[i]==s[i-1]){
            if(s[i+1]==s[i]){
                return -(400 + (i-1));
            }
        }
    }

    if(!atleast1symbol) {
        return -5;
    }
//CHEKING IF THE PASSWORD IS INVALID IN THE OTHER CASES

    for (int i = 0; i < size ; ++i) {
        char c = s[i];
        if (!(('0'<=c && c<='9') || ('a'<=c && c<='z') || ('A'<=c&&c<='Z')|| c == '@' || c == '#' || c == '%' || c == '$' || c == '!')) {
            return i;
        }}
//RETURN THE VALID PASSWORD
    if (atleast1symbol&& (!hasivalidchar)) {
        return -10;
    }




    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
// TODO: Complete this function
//CREATION OF AN ARRAY CANTAIN ALL PASSWORD AND CONVERT THEM TO THE "STRING" TYPE
    int arrsize = num_pwds;
    string newpass[arrsize];
    for(int i=0;i<arrsize;i++){
        newpass[i] = arr_pwds[i];
    }
//CHECKING THE PASSWORD BASE ON THE REQUIREMENT OF THE TASK
    int repeat=1;
    int repeatmax=1;
    string correctpass;

    for(int i=0;i<arrsize;++i){
        for(int j=i+1;j<arrsize;j++){
            if(newpass[i] == newpass[j]){
                repeat = repeat +1;
                }
           
            }
            
        if(repeat>repeatmax){
            repeatmax=repeat;    
            correctpass = newpass[i];
            
        }

        if(repeat == repeatmax){
            if(newpass[i].length()>correctpass.length()){
                correctpass = newpass[i];
                repeat = 1;
            }
        }

    repeat = 1;
        

               
           
    }               
//FINDING THE POSITION OF THE CORRECT PASSWORD
    for(int i=0; i<arrsize;i++){
        if(newpass[i] == correctpass){
            return i;
        }
        
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////