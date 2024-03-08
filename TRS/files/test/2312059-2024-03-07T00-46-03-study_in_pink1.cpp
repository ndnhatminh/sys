#include "study_in_pink1.h"



//  MAIN:
using namespace std;




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

void reset_Int(int &Var1, int Limit0, int Limit1){
    if (Var1 < Limit0 || Var1 > Limit1){
        if (Var1 < Limit0) Var1 = Limit0;
        if (Var1 > Limit1) Var1 = Limit1;
    }
}

int round_up(float Var){
    if (Var != (int) Var) return (int) Var + 1;
    else return (int) Var;
}

//Default Functions:

void reset_HP(int &HP1, int &HP2){
    reset_Int(HP1,0,666);
    reset_Int(HP2,0,666);
}

void reset_EXP(int &EXP1, int &EXP2){
    reset_Int(EXP1,0,600);
    reset_Int(EXP2,0,600);
}

void reset_M(int &M1, int &M2){
    reset_Int(M1,0,3000);
    reset_Int(M2,0,3000);
}

bool reset_E(int &E, int Limit0, int Limit1){
    if (E > Limit1 || E < Limit0) return true;
    else return false;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    //Declaration:
    reset_EXP(exp1, exp2);
    int temp_EXP = 0;//EXP prepared to be added
    int D;
    //Main:
    if( reset_E(e1, 0, 99) ) return -99;
    //TH1:
    if(e1 <= 3){//TH1
        reset_EXP(exp1, exp2);
        if (e1 == 0) exp2 += 29;
        else if (e1 == 1) exp2 += 45;
        else if (e1 == 2) exp2 += 75;
        else if (e1 == 3) exp2 += 29+45+75;
        reset_EXP(exp1, exp2);
        D = round_up((float)(e1 * 3 + exp1 * 7) );
        reset_EXP(exp1, exp2);
        if (D % 2 == 0) exp1 = round_up((float)(exp1 + round_up((float)D/200)) );
        else exp1 = round_up((float)(exp1 - D/100) );
    }
    //TH2:
    else {//TH2
        reset_EXP(exp1, exp2);
        if(e1 <= 19) exp2 = round_up((float)(exp2 + (round_up((float)e1/4) + 19)) );
        else if(e1 <= 49) exp2 = round_up((float)(exp2 + (round_up((float)e1/9) + 21)) );
        else if(e1 <= 65) exp2 = round_up((float)exp2 + (round_up((float)e1/16) + 17) );
        else if(e1 <= 79){ 
            exp2 = round_up((float)(exp2 + (round_up((float)e1/4) + 19)) );
            if(exp2 > 200) exp2 = round_up((float)(exp2 + (round_up((float)e1/9) + 21)) );
        }
        else {
            exp2 = round_up((float)(exp2 + (round_up((float)e1/4) + 19)) );
            if(exp2 > 200) exp2 = round_up((float)(exp2 + (round_up((float)e1/9) + 21)) );
            if(exp2 > 400) exp2 = round_up((float)exp2 + (round_up((float)e1/16) + 17) );
            exp2 = round_up((float)exp2 * 1.15);
        }
        reset_EXP(exp1, exp2);
        exp1 -= e1;
    }
    //End:
    reset_EXP(exp1, exp2);
    return exp1 + exp2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    //Declaration:
    reset_Int(HP1, 0, 666); reset_Int(EXP1, 0, 600); reset_Int(M1, 0, 3000);
    int S = find_SquareNumber(EXP1);
    int used_Money = 0;
    int P1, P2;
    bool road2_End = false;
    int Money_Had = M1;
    
    //Main:
    if( reset_E(E2, 0, 99) ) return -99;
    //  1st road:
    if (EXP1 >= S) P1 = 1;
    else P1 = (EXP1/S + 80)/123;
    //  2nd road:
    while (true){
        //      1st event:
        if (HP1 < 200) {
            reset_Int(HP1, 0, 666); reset_Int(EXP1, 0, 600); reset_Int(M1, 0, 3000);
            HP1 = round_up((float)HP1 * 1.3);
            M1 -= 150;
            if (!enough_Money(Money_Had, used_Money += 150, E2, M1)) break;
        }
        else {
            reset_Int(HP1, 0, 666); reset_Int(EXP1, 0, 600); reset_Int(M1, 0, 3000);
            M1 -= 70;
            HP1 = round_up((float)HP1 * 1.1);
            if (!enough_Money(Money_Had, used_Money += 70, E2, M1)) break;
        }
        //      2nd event:
        reset_Int(HP1, 0, 666); reset_Int(EXP1, 0, 600); reset_Int(M1, 0, 3000);
        if (EXP1 < 400) {
            M1 -= 200;
            EXP1 = round_up((float)EXP1 * 1.13);
            if (!enough_Money(Money_Had, used_Money += 200, E2, M1)) break;
        }
        else {
            M1 -= 120;
            EXP1 = round_up((float)EXP1 * 1.13);
            if (!enough_Money(Money_Had, used_Money += 120, E2, M1)) break;
        }
        
        
        //      3rd event:
        reset_Int(HP1, 0, 666); reset_Int(EXP1, 0, 600); reset_Int(M1, 0, 3000);
        if (EXP1 < 300) {
            M1 -= 100;
            EXP1 = round_up((float)EXP1 * 0.9);
            if (!enough_Money(Money_Had, used_Money += 100, E2, M1)) break;
        }
        else {
            M1 -= 120;
            EXP1 = round_up((float)EXP1 * 0.9);
            if (!enough_Money(Money_Had, used_Money += 120, E2, M1)) break;
        }
        
        //      Break Loop:
        if (E2 % 2 == 0) break;
        if (road2_End) break;
    }
    //      End Road2:
    reset_Int(HP1, 0, 666); reset_Int(EXP1, 0, 600); reset_Int(M1, 0, 3000);
    HP1 = round_up((float)HP1 * 0.83);
    EXP1 = round_up((float)EXP1 * 1.17);
    S = find_SquareNumber(EXP1);
    if (EXP1 >= S) P2 = 1;
    else P2 = (EXP1/S + 80)/123;
    //  3rd Road:
    int i;
    const int P3[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    //      Calculate i value:
    reset_Int(HP1, 0, 666); reset_Int(EXP1, 0, 600); reset_Int(M1, 0, 3000);
    i = ( (E2 % 10) + E2/10 ) % 10;
    //End:
    reset_Int(HP1, 0, 666); reset_Int(EXP1, 0, 600); reset_Int(M1, 0, 3000);
    if (P1 == P2 == P3[i] == 1){
        EXP1 = round_up((float)EXP1 * 0.75);
        traceLuggage(HP1, EXP1, M1, E2);
    }
    else {
        if( (float)(P1 + P2 + P3[i])/3 < 0.5 ){
            HP1 = round_up((float)HP1 * 0.85);
            EXP1 = round_up((float)EXP1 * 1.15);
        }
        else{
            HP1 = round_up((float)HP1 * 0.9);
            EXP1 = round_up((float)EXP1 * 1.2);
        }
    }
    reset_Int(HP1, 0, 666); reset_Int(EXP1, 0, 600); reset_Int(M1, 0, 3000);
    return HP1 + EXP1 + M1;
 
    return HP1 + EXP1 + M1;
}

int squareRoot(int n) {
    for (int i = 0; i*i <=n; i++){
        if (i*i == n) return i;
    }
    return 0;
}

int abs(int Var){
    if (Var < 0) return (-Var);
    else return Var;
}

int find_SquareNumber(int Var){//Find the Nearest SquareNumber of Var
    //Find the smaller SN, bigger SN. Then compare which is the nearest
    int SquareNumber1, SquareNumber2;
    for (SquareNumber1 = Var; SquareNumber1 > 1; SquareNumber1--){
        int i = squareRoot(SquareNumber1);
        if(i * i == SquareNumber1) break;
    }
    for (SquareNumber2 = Var; ; SquareNumber2++){
        int i = squareRoot(SquareNumber2);
        if(i * i == SquareNumber2) break;
    }
    if ( abs(Var - SquareNumber1) < abs(Var - SquareNumber2) ) return SquareNumber1;
    else return SquareNumber2;
}

bool enough_Money(int Money_Had, int Money_Need, int E2, int M1){//Check if Sherlock had enough money
    if (E2 % 2 == 1){    
        if (Money_Need > Money_Had * 0.5) return false;
        else return true;
    }
    else{
        if (M1 > 0) return true;
        else return false;
    }
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    //Declaration:
    int TaxiPoints[10][10];
    int line, row;//line, row of the point Sherlock meet taxi
    int Numbers_GreaterThan_E3x2 = 0, Numbers_SmallerThan_negE3 = 0;
    //Main:
    reset_HP(HP1, HP2); reset_EXP(EXP1, EXP2);
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            TaxiPoints[i][j] = 0;
        }
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            TaxiPoints[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            // cout << TaxiPoints[i][j] << "|";
            if (TaxiPoints[i][j] > E3*2) Numbers_GreaterThan_E3x2 ++;
            else if (TaxiPoints[i][j] < -E3) Numbers_SmallerThan_negE3 ++;
        }
        // cout << "\n";
    }
    line = find_SumUnit(Numbers_GreaterThan_E3x2);
    row = find_SumUnit(Numbers_SmallerThan_negE3);
    // cout << line << " " << row;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++) int k = TaxiPoints[i][j];
        // cout << "\n"; 
    }
    reset_HP(HP1, HP2); reset_EXP(EXP1, EXP2);
    if ( abs(TaxiPoints[line][row]) > Score(line, row, TaxiPoints) ){
        HP1 = round_up((float)HP1 * 0.9);
        HP2 = round_up((float)HP2 * 0.9);
        EXP1 = round_up((float)EXP1 * 0.88);
        EXP2 = round_up((float)EXP2 * 0.88);
        reset_HP(HP1, HP2); reset_EXP(EXP1, EXP2);
        return TaxiPoints[line][row];
    }
    else {
        HP1 = round_up((float)HP1 * 1.1);
        HP2 = round_up((float)HP2 * 1.1);
        EXP1 = round_up((float)EXP1 * 1.12);
        EXP2 = round_up((float)EXP2 * 1.12);
        reset_HP(HP1, HP2); reset_EXP(EXP1, EXP2);
        return Score(line, row, TaxiPoints);
    }
    return -1;
}
int Score(int line,int row,int TaxiPoints[10][10]){//Calculate the score Sherlock & Watson get
    int res;
    int Points[1000];
    int count = -1;
    for (int i = line + 1, j = row - 1 ;; i++, j--, count++){
        if (i >= 10 || j < 0) break;
        Points[count] = TaxiPoints[i][j];
    }
    for (int i = line - 1, j = row + 1 ;; i--, j++, count++){
        if (j >= 10 || i < 0) break;
        Points[count] = TaxiPoints[i][j];
    }
    for (int i = line - 1, j = row - 1 ;; i--, j--, count++){
        if (j < 0 || i < 0) break;
        Points[count] = TaxiPoints[i][j];
    }
    for (int i = line + 1, j = row + 1 ;; i++, j++, count++){
        if (j >= 10 || i >= 10) break;
        Points[count] = TaxiPoints[i][j];
    }
    res = Points[0];
    for (; count >= 0; count--) {
        if (res < Points[count]) {res = Points[count];}
    }
    // cout << res << " ";
    return abs(res);
}

int find_SumUnit(int Var){//Find sum of all unit numbers of a number
    while (Var >= 10){
        int res[2];
        res[1] = Var/10;
        res[0] = Var % 10;
        Var = res[1] + res[0];
    }
    return Var;
}


// Task 4
int checkPassword(const char * s, const char * email){
    int  special_Chars = 0;
    if (lenSTR(s) < 8) return -1;//2
    else if (lenSTR(s) > 20) return -2;//3
    // cout << lenSTR(s) << " ";

    //CHECK SE #4:
    int SE_End = find(email, '@');
    // cout << SE_End << " ";
    char se[SE_End];
    for (int i = 0; i <= SE_End; i++){
        if (email[i] == '@') break;
        se[i] = email[i];
        // cout << se << " ";
    }


    int se_s = 0;//counting the same letter of se in s
    for (int i = 0, j = -1; ; i++){
        if (se_s == SE_End){
            return -(300 + j);
            
        }
        
        if (se_s !=0 && s[i] != se[se_s]) {se_s = 0;cout << SE_End << " ";}
        if (s[i] == se[se_s] && j == -1) {se_s++; j = i;}
        if (s[i] == se[se_s] && j != -1) {se_s++;}
        if (i == lenSTR(s)) break;
    }
    

    for (int i = 1; i < lenSTR(s); i++){//5
        if (s[i] == s[i-1] == s[i-2]) return -(400 + (i-1));
    }
    
    for (int i = 0; i < lenSTR(s); i++){
        if (s[i] == '@' || s[i] == '#' || s[i] == '%') special_Chars++;
        else if (s[i] == '$' || s[i] == '!') special_Chars++;
    }
    
    if (special_Chars == 0) return -5;//6
    
    if (lenSTR(email) > 100) return 101;//7
   
    for (int i = 0; i < lenSTR(s); i++){
        if (!(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')){
            if ( (s[i] > 57 || s[i] < 48) && (s[i] > 90 || s[i] < 65) && (s[i] > 122 || s[i] < 97) ) return i;
        }
    }
    
    for (int i = 0, j = 0; i < lenSTR(email); i++){
        if (email[i] == '@') j ++;
        if (j == 2) return i;
    }

    return -10;
}

int find(const char * Var, char letter){
    for (int i = 0; i <= lenSTR(Var); i++)
        if (Var[i] == letter) return i;
    return -1;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    //Declaration:
    int mostAppeared_pwd = 0, pwds_sizes[num_pwds];
    int pwds[num_pwds], longest_pwd = 0; //Array to count the pwds that appeared more than once
    string appearing_pwds;//The pwd to compare
    
    Main:
    for (int i = 0; i < num_pwds; i++) {//Set the Array pwds that appeared more than once & set sizes
        pwds_sizes[i] = lenSTR(arr_pwds[i]);
        pwds[i] = 1;
    }
    for (int i = 0; i < num_pwds; i++) {//Count pwds appearance
        appearing_pwds = arr_pwds[i];
        for (int j = 1; j < num_pwds; j++){
            if (pwds[i] != 1) break;
            else if (arr_pwds[j] == appearing_pwds) {
                pwds[i]++; pwds[j]++;
                }
        }
    }
    for (int i = num_pwds - 1; i >= 0; i--){//Find the most appeared pwds
        if (mostAppeared_pwd < pwds[i]) mostAppeared_pwd = pwds[i];
    }
    for (int i = num_pwds - 1; i >= 0; i--){//Find the longest pwd inside the most appeared
        if (mostAppeared_pwd == pwds[i]) {
            if (longest_pwd < pwds_sizes[i]) longest_pwd = pwds_sizes[i];
        }
    }
    for (int res = 0; res < num_pwds; res++){//Return the result
        if (longest_pwd == pwds_sizes[res] && mostAppeared_pwd == pwds[res]) return res;
    }
    return -1;
}

int lenSTR(const char * Var){
    int i = 0;
    for (i = 0; Var[i] != '\0'; ++i);
    return i;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////