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
//Exp1: Sherlock
int MAX_EXP = 600;
int MAX_HP = 666;
int MAX_MONEY = 3000;
void checkExp(int &exp){
    if(exp < 0) exp = 0;
    if(exp > MAX_EXP) exp = MAX_EXP;

} 
void checkHP(int &hp){
    if(hp < 0) hp = 0;
    if(hp > MAX_HP) hp = MAX_HP;

} 
void checkMoney(int &M){

    if(M < 0) M = 0;
    if(M > MAX_MONEY) M = MAX_MONEY;
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1 <0 || e1 > 99) return -99;

    
    checkExp(exp1);
    checkExp(exp2);
    if(e1 >= 0 && e1 <= 3){
        //Change Watson exp2
        if(e1 == 0){
            exp2 = (exp2 + 29);

        }else if(e1 == 1){
            exp2 = (exp2 + 45);
        }else if(e1 == 2){
            exp2 = (exp2 + 75) ;
        }else{
            exp2 = (exp2 + 29 + 45 + 75);
        }

        checkExp(exp2);
        int D = e1*3 + exp1*7;
        if(D % 2 == 0){
            exp1 = int(ceilf(exp1 + D*1.0/200));

            
        }else{
            exp1 = int(ceilf(exp1 - D*1.0/100));
            //if(exp1 < 0) exp1 = 0;
            //checkExp(exp1);

        }
        checkExp(exp1);
    }else if(e1 <= 99){

        if(e1 <= 19){

            exp2 = int(ceilf(exp2 + (e1*1.0/4 + 19)));

        }else if(e1 <= 49){

            exp2 = int(ceilf(exp2 + (e1*1.0/9 + 21)));

        }else if(e1 <= 65){

            exp2 = int(ceilf(exp2 + (e1*1.0/16 + 17)));

        }else if(e1 <= 79){
            exp2 = int(ceilf(exp2 + (e1*1.0/4 + 19)));

            if(exp2 > 200){
                exp2 = int(ceilf(exp2 + (e1*1.0/9 + 21)));

            }
            
        }else{
            exp2 = int(ceilf(exp2 + (e1*1.0/4 + 19)));

            exp2 = int(ceilf(exp2 + (e1*1.0/9 + 21)));
            if(exp2 > 400){
                exp2 = int(ceilf(exp2 + (e1*1.0/16 + 17)));

                exp2 = int(ceilf(exp2*1.15));

            }


        }

       // exp2 = exp2 % MAX_EXP;
        checkExp(exp2);
        exp1 = exp1-e1;
        checkExp(exp1);




    }

    ///////
    


    return exp1 + exp2;
}

// Task 2
int getClosestPerfectSquare(int N)
{
  int x = sqrt(N);
   
  //Checking if N is a perfect square
  if((x*x)==N){
    return N;
  }
   
  // If N is not a perfect square, 
  // squaring x and x+1 gives us the 
  // just below and above perfect squares
 
    // Variables to store perfect
    // square number just
    // above and below N
    int aboveN = (x+1)*(x+1), belowN = x*x;
 
    // Variables to store the differences
    int diff1 = aboveN - N;
    int diff2 = N - belowN;
 
    if (diff1 > diff2) return belowN;
    
    return aboveN;
}
void pathTwo(int & HP1, int & EXP1, int & M1, int E2){
    int money_limit = int(ceilf(M1*1.0/2));
    
    //Event 1
    while(true){

    
    if(HP1 < 200){

        HP1 = int(ceilf(HP1*1.3));
        M1 = M1- 150;

    }else{
        HP1 = int(ceilf(HP1*1.1));
        M1 = M1-70;

    }

    //HP1 = HP1% MAX_HP;
    checkHP(HP1);
    //if(M1 < 0) M1 = 0;

    if((E2% 2 == 1 && M1 < money_limit) || (E2 % 2 == 0 && M1 <= 0)) break;
    //Event 2
    if(EXP1 < 400){
        M1 = M1 - 200;

    }else{
        M1 = M1 - 120;
    }

   // if(M1 < 0) M1 = 0;
    EXP1 =int(ceilf( EXP1*1.13));
    checkExp(EXP1);
    if((E2% 2 == 1 && M1 < money_limit) || (E2 % 2 == 0 && M1 <= 0)) break;

    //Event 3
    if(EXP1 < 300){
        M1 = M1-100;
    }else{
        M1 = M1-120;
    }


    //if(M1 < 0) M1 = 0;
    EXP1 = int(ceilf(EXP1*0.9));
    if((E2% 2 == 1 && M1 < money_limit) || (E2 % 2 == 0)) break;
    }

}
double calProb(int EXP1){
    int S = getClosestPerfectSquare(EXP1);
    double P = 1;

    if(EXP1 < S){
        P = (EXP1*1.0/S + 80)/123;
    }
    return P;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 < 0 || E2 > 99) return -99;

    //Path 1
    checkExp(EXP1);
    checkHP(HP1);
    checkMoney(M1);
    double P1 = calProb(EXP1);
    
    ///Path 2
    
    if(M1 > 0) pathTwo(HP1, EXP1, M1, E2);
    
    checkMoney(M1);
    HP1 = int(ceilf(HP1*0.83));
    EXP1 = int(ceilf(EXP1*1.17));
   //End Path 2
   
    checkExp(EXP1);
    double P2 = calProb(EXP1);

    //Path 3

    double P[10] = {0.32, 0.47,0.28,0.79, 1, 0.50, 0.22, 0.83, 0.64, 0.11};
    double P3;
    if(E2 < 10){ // E2 co 1 chu so
        P3 = P[E2];

    }else{
        int sum = E2/10 + E2%10;

        P3 = P[sum%10];


    }


    if(P1 == 1 && P2 == 1 && P3 == 1){
        EXP1 = int(ceilf(EXP1 *0.75));

    }else{
        double P = (P1 +P2 + P3)/3;

        if(abs(P - 0.5) < 1e-9 || P > 0.5){
            
            HP1 = int(ceilf(HP1 * 0.9));
            EXP1 = int(ceilf(EXP1*1.2));

        }else{

            HP1 = int(ceilf(HP1*0.85));
            EXP1 = int(ceilf(EXP1*1.15));
        }

        checkExp(EXP1);
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int findMaxRight(int **matrix, int row, int col){
    int maxRight = matrix[row][col];

    int i = row+1, j = col-1;
    while(i < 10 && j >=0){
        if(matrix[i][j] > maxRight) maxRight = matrix[i][j];

        ++i;
        --j;
    }

    return maxRight;
}
int findMaxLeft(int **matrix, int row, int col){
    int maxLeft = matrix[row][col];

    int i = row+1, j = col+1;
    while(i < 10 && j < 10){
        if(matrix[i][j] > maxLeft) maxLeft = matrix[i][j];

        ++i;
        ++j;
    }

    return maxLeft;
}

void printMatrix(int **matrix, int row, int col){

    cout<<"Matrix: "<<endl;
    for(int i = 0; i < row; ++i){

        for(int j = 0; j < col; ++j){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    if(E3 <0 || E3 > 99) return -99;


    checkHP(HP1);
    checkHP(HP2);
    checkExp(EXP1);
    checkExp(EXP2);
    int **Matrix = new int*[10];
    for(int i = 0; i < 10; ++i){
        Matrix[i] = new int[10]();
    }

    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){

            Matrix[i][j] = ((E3*j) + (i*2)) * (i-j); 
        }
    }
    
   // printMatrix(Matrix, 10, 10);

    int I = 0, J = 0;
    for(int i = 0; i < 10; ++i){

        for(int j = 0; j < 10; ++j){
            if(Matrix[i][j] > E3*2) ++I;
            if(Matrix[i][j] < -E3) ++J;
        }
    }

    while(I / 10 > 0){
        I = (I/10) + (I%10);

    }
    while(J/10 > 0){
        J = (J/10) + (J%10);

    }

   // cout<<"(i, j) = "<<"("<<I<<", "<<J<<") "<<endl;
    int index = (I > J)?(I):J;
    
    //Find right most index
    int row = I, col =J;
    while(row-1 >= 0 && col+1 < 10){
        --row;
        ++col;
    }
   // cout<<"Row, Col:  "<<row<<" "<<col<<endl;
    int maxRight = findMaxRight(Matrix, row, col);
   // cout<<"Maxright: "<<maxRight<<endl;
    row = I, col = J;
    while(row-1 >= 0 && col-1 >=0){
        --row;
        --col;
    }
   // cout<<"Row, Col:  "<<row<<" "<<col<<endl;
    int maxLeft = findMaxLeft(Matrix, row, col);
    //cout<<"MaxLeft: "<<maxLeft<<endl;
   int point = abs((maxLeft > maxRight)?maxLeft:maxRight );

    //cout<<"Point: "<<point<<endl;
    int pointTaxi = Matrix[I][J];
    if(abs(pointTaxi) > point){// Can not chase succesfully
        HP1 = int(ceilf(HP1*0.9));
        HP2 = int(ceilf(HP2*0.9));
        EXP1 = int(ceilf(EXP1*0.88));
        EXP2 = int(ceilf(EXP2*0.88));

    } else{
        HP1 = int(ceilf(HP1*1.1));
        HP2 = int(ceilf(HP2*1.1));
        EXP1 = int(ceilf(EXP1*1.12));
        EXP2 = int(ceilf(EXP2*1.12));

    }

    checkHP(HP1);
    checkHP(HP2);
    checkExp(EXP1);
    checkExp(EXP2);

    for(int i = 0; i < 10; ++i){
        delete[] Matrix[i];
    }
    delete[] Matrix;
    Matrix = NULL;
    return (abs(pointTaxi) > point) ? pointTaxi: point;
}

// Task 4
bool validSpecChar(char c){
    if(c == '@' || c== '#' || c== '%' || c== '$' || c== '!') return true;

    return false;

}
bool validChar(char c){
    if((c >= 'A' && c <='Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') ||(validSpecChar(c))){
        return true;

    }
    return false;
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string ema(email);
    string str(s);
    int find = ema.find('@');
    string se = ema.substr(0, find);

    int len = str.size();
    //Check validLen
    //bool validLen = (len >= 8 && len <= 20)?(true):false;
    if(len < 8) return -1;
    else if(len > 20) return -2;

     //Check if password contain string se
    int sei = str.find(se);
    if(sei != string::npos){
        return -(300 + sei);
    } 
    //Check duplicate 3 times
    for(int i = 1; i < len-1; ++i){
        if(str[i] == str[i-1] && str[i] == str[i+1]){
            //duplicate = true;
            int sci = i-1;
            return -(400 + sci);
        }

    }


    bool valid_Char = true;

    bool specChar = false;

    for(int i = 0; i < len; ++i){
        if(validSpecChar(str[i])){
            specChar = true;
            break;
        }  
    }

    if(!specChar) return -5;
    //Check contain special Char and valid Character
    for(int i = 0 ; i < len; ++i){
        
        if(validChar(str[i]) == false){
            //valid_Char = false;
            return i;
            //break;
        }
        
    }
   
    
    

/////////////
    
    //bool duplicate =false;
    
    


    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxFreq = 0;
    int maxIdx = 0;
    bool *visited = new bool[num_pwds]();

    for(int i = 0; i < num_pwds; ++i){
        if(visited[i] == true) continue;
       
        int freq =  1;
        
        for(int j = i +1; j < num_pwds; ++j){
            
            if(strcmp(arr_pwds[i], arr_pwds[j]) == 0){
                ++freq;
                visited[j] = true;

            }
        }

        if(freq > maxFreq){
            maxFreq = freq;
            maxIdx = i;
        }else if(maxFreq == freq && strlen(arr_pwds[i]) > strlen(arr_pwds[maxIdx])){
            maxIdx = i;
        }

    }
    
    delete[] visited;
    visited = NULL;
    return maxIdx;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////