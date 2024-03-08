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

// Check EXP
void trap_exp(int& exp) {
    if(exp < 0) exp = 0;
    else if(exp > 600) exp = 600;
}


// Check HP
void trap_hp(int& hp) {
    if(hp < 0) hp = 0;
    else if(hp > 666) hp = 666;
}


// Check Money
void trap_money(int& m) {
    if(m < 0) m = 0;
    else if(m > 3000) m = 3000;
}
 

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if(e1<0||e1>99) return -99;
    trap_exp(exp1);
    trap_exp(exp2);
    switch (e1){
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
        default:
            break;
    }
    if(e1<=3 && e1>=0){
        trap_exp(exp1);
        trap_exp(exp2);
        int D = e1*3 + exp1*7;
        if(D%2) exp1 = ceil((double)exp1 - D/100.0 -0.00000001);
        else exp1 = ceil((double) exp1 + D/200.0 -0.00000001);
    }
    else{
        if(e1 >= 4 && e1 <= 19){
            exp2 += ceil((double) e1/4 -0.00000001) + 19;
        }
        else if(e1 >= 20 && e1 <= 49){
            exp2 += ceil((double) e1/9 -0.00000001) + 21;
        }
        else if(e1>= 50 && e1 <= 65){
            exp2 += ceil((double) e1/16 -0.00000001) + 17;
        }
        else if(e1 >= 66 && e1 <= 79){
            exp2 += ceil((double) e1/4 -0.00000001) + 19;
            if(exp2 > 200) exp2 += ceil((double) e1/9 -0.00000001) + 21;
        }
        else if(e1 >=80 && e1<=99){
            exp2 += ceil((double) e1/4 -0.00000001) + 19;
            exp2 += ceil((double) e1/9 -0.00000001) + 21;
            if(exp2 > 400){
                exp2 += ceil((double) e1/16 -0.00000001) + 17;
                exp2 = ceil( (double) exp2*1.15 -0.00000001);
            }
        }
        exp1 -= e1;
    }
    trap_exp(exp1);
    trap_exp(exp2);
    return exp1 + exp2;
}


// Task 2 
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(E2<0||E2>99) return -99;
    double P1,P2,P3;
    trap_exp(EXP1);
    trap_money(M1);
    trap_hp(HP1);
    // Calculating P1
    if(EXP1 >= round(sqrt(EXP1))*round(sqrt(EXP1)) ) P1 = 1;
    else P1 = ( EXP1 / ( round(sqrt(EXP1))*round(sqrt(EXP1)) ) + 80)/123;
        if(E2%2){ // E2 is ODD
            int temp = M1/2;
            if(M1%2){
                while(1){
                    if(M1<=0) break;
                    // Path 2 first action
                    if(HP1 < 200 ){
                        HP1 = ceil(HP1*1.3 -0.00000001);
                        M1 -= 150;
                        trap_money(M1);
                        trap_hp(HP1);
                    }
                    else{
                        HP1 = ceil(HP1*1.1 -0.00000001);
                        M1 -= 70;
                        trap_money(M1);
                        trap_hp(HP1);
                    }
                    if(M1 <= temp || M1 <= 0) break; // check condition to walk
                
                    // Path 2 second action
                    if(EXP1 < 400) M1 -= 200;
                    else M1 -= 120;
                    trap_money(M1);
                    EXP1 = ceil(EXP1*1.13 -0.00000001);
                    trap_exp(EXP1);
                    if(M1 <= temp || M1 <= 0) break; // check condition to walk
                
                    // Path 2 third action
                    if(EXP1 < 300) M1 -= 100;
                    else M1 -= 120;
                    trap_money(M1);
                    EXP1 = ceil(EXP1*0.9 -0.00000001);
                    if(M1 <= temp || M1 <= 0) break; // check condition to walk
                }
            }
            else{
                while(1){
                    if(M1<=0) break;
                    // Path 2 first action
                    if(HP1 < 200 ){
                        HP1 = ceil(HP1*1.3 -0.00000001);
                        M1 -= 150;
                        trap_money(M1);
                        trap_hp(HP1);
                    }
                    else{
                        HP1 = ceil(HP1*1.1 -0.00000001);
                        M1 -= 70;
                        trap_money(M1);
                        trap_hp(HP1);
                    }
                    if(M1 < temp || M1 <= 0) break; // check condition to walk
                
                    // Path 2 second action
                    if(EXP1 < 400) M1 -= 200;
                    else M1 -= 120;
                    trap_money(M1);
                    EXP1 = ceil(EXP1*1.13 -0.00000001);
                    trap_exp(EXP1);
                    if(M1 < temp || M1 <= 0) break; // check condition to walk
                
                    // Path 2 third action
                    if(EXP1 < 300) M1 -= 100;
                    else M1 -= 120;
                    trap_money(M1);
                    EXP1 = ceil(EXP1*0.9 -0.00000001);
                    if(M1 < temp || M1 <= 0) break; // check condition to walk
                }
            }
            
            // Sherlock continues to walk
            
            HP1 = ceil(HP1*0.83 -0.00000001);
            EXP1 = ceil(EXP1*1.17 -0.00000001);
            trap_exp(EXP1);
            trap_hp(HP1);
         }
        else{ // E2 is even
           
            while(1){
                if(M1<=0) break;
                // first action once
                if(HP1 < 200){
                        HP1 = ceil(HP1*1.3 -0.00000001);
                        M1 -= 150;
                }
                else{
                    HP1 = ceil(HP1*1.1 -0.00000001);
                    M1 -= 70;
                }
                trap_hp(HP1);
                if(M1 <= 0) break;
                 
                // second action once
                if(EXP1 < 400 && M1 != 0) M1 -= 200;
                else if( M1 != 0) M1 -= 120;
                EXP1 = ceil(EXP1*1.13 -0.00000001);
                trap_exp(EXP1);
                if(M1 <= 0) break;
               
                // third action once
                if(EXP1 < 300 && M1 != 0) M1 -= 100;
                else if (M1 != 0) M1 -= 120;
                EXP1 = ceil(EXP1*0.9 -0.00000001);
                trap_exp(EXP1);
                if(M1 <= 0) break;
                break;
            }
            trap_money(M1);
            HP1 = ceil(HP1*0.83-0.00000001);
            EXP1 = ceil(EXP1*1.17 -0.00000001);
            trap_exp(EXP1);
            trap_hp(HP1);
    }
   
    // calculating P2
    if(EXP1 >= round(sqrt(EXP1))*round(sqrt(EXP1)) ) P2 = 1;
    else  P2 = ( EXP1 / ( round(sqrt(EXP1))*round(sqrt(EXP1)) ) + 80)/123;
   
    // calculating P3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2<=9&&E2>=0) P3 = (double) P[E2]/100;
    else P3 = (double) P[(E2%10 + E2/10)%10]/100;
   
    // Path 3
    if(P1 == 1 && P2 == 1 && P3 == 1) EXP1 = ceil(EXP1*0.75);
    else if( ( P1 + P2 + P3 ) < 1.5){
        HP1 = ceil(HP1*0.85 -0.00000001);
        EXP1 = ceil(EXP1*1.15 -0.00000001);
    }
    else{
        HP1 = ceil(HP1*0.9 -0.00000001);
        EXP1 = ceil(EXP1*1.2 -0.00000001);
    }
    trap_hp(HP1);
    trap_exp(EXP1);
    trap_money(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(E3>99 || E3 <0) return -99;
    trap_exp(EXP1);
    trap_exp(EXP2);
    trap_hp(HP1);
    trap_hp(HP2);
    // Initialize the 2D array
    int arr[10][10];
    for(int i = 0 ; i < 10 ;i++){
        for(int j = 0 ; j < 10 ; j++){
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
       
    // Counts of positive integers larger than 2*E3 and negative integers smaller than -E3
    int pos_count = 0, neg_count = 0;
    for(int i = 0 ; i < 10 ;i++){
        for(int j = 0 ; j < 10 ; j++){
            if(arr[i][j] > (E3*2)) pos_count++;
            if(arr[i][j] < (-E3)) neg_count++;
        }
    }
       
    // Find the coordinate of the Taxi
    int x,y;
    if(pos_count%9==0) x = 9;
    else x = pos_count%9;
    if(neg_count%9==0) y = 9;
    else y = neg_count%9;
       
    // Finding the maximum value along the diagonals
    int temp = INT_MIN;
    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            if(i+j==x+y) temp = max(temp,arr[i][j]);
            if(i-j==x-y) temp = max(temp,arr[i][j]);
        }
    }
       
    if(abs(arr[x][y])>abs(temp)){
        // Can't take the taxi
        EXP1 -= floor(EXP1*0.12);
        HP1 -= floor(HP1*0.1);
        EXP2 -= floor(EXP2*0.12);
        HP2 -= floor(HP2*0.1);
        trap_exp(EXP1);
        trap_exp(EXP2);
        trap_hp(HP1);
        trap_hp(HP2);
        return arr[x][y];
    }
    else{
        // Take the taxi
        EXP1 = EXP1 + ceil(  EXP1*0.12);
        HP1 = HP1 + ceil(HP1*0.1);
        EXP2 = EXP2 + ceil(EXP2*0.12);
        HP2 = HP2 + ceil(HP2*0.1);
        trap_exp(EXP1);
        trap_exp(EXP2);
        trap_hp(HP1);
        trap_hp(HP2);
        return temp;
    }


    return -1;
}


// Task 4
int checkPassword(const char * s, const char * email) {
   
    // Converting C string to C++ string
    string a = string(s);
    string b = string(email);
   
    // Checking length
    if(a.size()<8) return -1;
    else if(a.size()>20) return -2;
    else{
        // Finding the position of the @ to create a substring from the start to before the @
        string se = b.substr(0,b.find('@'));
        auto found = a.find(se);
        if(found != string::npos) return -(found+300); // When Found
        else{
            for(int i = 0 ; i < a.size()-2;i++){
                if(a[i] == a[i+1] && a[i+1] == a[i+2]) return -(400+i); // Checking two identical consecutive characters
            }
            if (a.find('@') == string::npos && a.find('#') == string::npos &&
                a.find('%') == string::npos && a.find('$') == string::npos &&
                a.find('!') == string::npos) return -5; // Special characters not found
        }
        for(int i = 0 ; i < a.size();i++){
            if(isalpha(a[i])==0&& isdigit(a[i])==0 && a[i] != '@' && a[i] != '#' && a[i] != '%' && a[i] != '$' && a[i] != '!') return i;
        }
    }
   
    return -10;
}


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int index=0, freq=0, size=0;
    for (int i=0; i<num_pwds; i++) {
        int count = 0;
        for (int j=0; j<num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) count++;
        }

        // Updating the max freq of longest string
        if (count > freq || (count == freq && strlen(arr_pwds[i]) > size)) {
            freq = count;
            size = strlen(arr_pwds[i]);
            index = i;
        }
    }
    return index;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////


