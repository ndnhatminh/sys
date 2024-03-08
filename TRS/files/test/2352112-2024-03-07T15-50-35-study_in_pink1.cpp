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
int firstMeet(int & exp1, int & exp2, int e1) {

    if ( e1 < 0 || e1 > 99) return -99;
    else if ( e1 >= 0 && e1 <= 3){
        int D = ( e1 * 3 ) + ( exp1 * 7);
        if ( fmod ( D , 2.0 ) ==0 ){
            exp1 = ceil( exp1 + D / 200.0 );
        }
        else{
            exp1 = ceil( exp1 - D / 100.0);
        }
        if ( e1 == 0){
            exp2 += 29;
        }
        else if ( e1 == 1){
            exp2 += 45;
        }
        else if ( e1 == 2){
            exp2 += 75;
        }
        else if ( e1 == 3){
            exp2 += 149;
        }
    }
    else if ( e1 >= 4 && e1 <= 99){
        if ( e1 >=4 && e1 <= 19){
            exp2 = ceil( exp2 + (( e1 / 4.0) + 19));
        }
        else if ( e1 >= 20 && e1 <= 49){
            exp2 = ceil( exp2 + (( e1 / 9.0) + 21));
        }
        else if ( e1 >= 50 && e1 <= 65){
            exp2 = ceil( exp2 + (( e1 / 16.0) + 17));
        }
        else if ( e1 >= 66 && e1 <= 79){
            exp2 = ceil( exp2 + (( e1 / 4.0) + 19));
            if ( exp2 > 200){
                exp2 = ceil ( exp2 + (( e1 / 9.0) + 21));
            }
        }
        else if ( e1 >= 80 && e1 <= 99){
            exp2 = ceil ( exp2 + ((e1 / 4.0) + 19));
            exp2 = ceil ( exp2 + ((e1 / 9.0) + 21));
            if ( exp2 > 400){
                exp2 = ceil( exp2 + ((e1 / 16.0) + 17));
                exp2 = ceil( exp2 + ( exp2 * 0.15));
            }
        }
        exp1 -= e1;
    }
    if(exp1 > 600) exp1 = 600;
    else if (exp1 < 0) exp1 = 0;
    if(exp2 > 600) exp2 = 600;
    else if (exp2 < 0) exp2 = 0;
    return exp1 + exp2;
 
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    double P1, P2, P3, c, TBC;
    int S, a, b, d, e;
    a = floor( sqrt (EXP1));
    b = ceil ( sqrt (EXP1));
    if ( abs( EXP1 - a * a) < abs ( EXP1 - b * b)) {
        S = a * a;
    }
    else{
        S = b * b;
    }
    if ( EXP1 >= S){
        P1 = 1.0;
    }
    else{
        P1 = ( (EXP1 / ( S * 1.0) ) + 80.0 ) / 123.0;
    }
    c = M1 / 2.0;
    if ( E2 < 0 || E2 > 99) return -99;
    else if ( fmod( E2 , 2.0 ) == 0 ){
        if ( HP1 < 200 ){
            HP1 = ceil( HP1 + ( 30.0 / 100) * HP1);
            M1 -= 150;
        }
        else{
            HP1 = ceil( HP1 + ( 10.0 / 100) * HP1);
            M1 -= 70;
        }
        if ( M1 <= 0){
            M1 = 0;
        }
        else{
            if ( EXP1 < 400){
                M1 -= 200;
            }
            else{
                M1 -= 120;
            }
            EXP1 = ceil( EXP1 + (13.0 /100) * EXP1);
            if ( M1 <= 0){
                M1 = 0;
            }
            else{
                if ( EXP1 < 300){
                    M1 -= 100;
                }
                else{
                    M1 -= 120;
                }
                EXP1 = ceil ( EXP1 - ( 10.0 / 100) * EXP1);
            }
        }
    }
    else{
        while( M1 > c){
            if ( HP1 < 200){
                HP1 = ceil( HP1 + ( 30.0 / 100) * HP1);
                M1 -= 150;
            }
            else{
                HP1 = ceil( HP1 + ( 10.0 / 100) * HP1);
                M1 -= 70;
            }
            if ( M1 < c){
                break;
            }
            else{
                if (EXP1 < 400){
                    M1 -= 200;
                }
                else{
                    M1 -= 120;
                }
                EXP1 = ceil( EXP1 + (13.0 /100) * EXP1);
                if ( M1 < c){
                    break;
                }
                else{
                    if ( EXP1 < 300){
                        M1 -= 100;
                    }
                    else{
                        M1 -= 120;
                    }
                    EXP1 = ceil ( EXP1 - ( 10.0 / 100) * EXP1);
                }
            }
        }
    }
    HP1 = ceil( HP1 - ( 17.0 / 100) * HP1);
    EXP1 = ceil( EXP1 + ( 17.0 /100) * EXP1);
    d = floor( sqrt(EXP1));
    e = ceil( sqrt(EXP1));
    if ( abs( EXP1 - d*d) < abs( EXP1 - e*e) ){
        S = d * d;
    }
    else{
        S = e * e;
    }
    if (EXP1 >= S){
        P2 = 1.0;
    }
    else{
        P2 = ( (EXP1 / S * 1.0) + 80.0) / 123.0;
    }
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if ( E2 >= 0 && E2 <= 9){
        P3 = P[E2] / 100.0;
    }
    else if ( E2 >= 10 && E2 <= 99){
        int chuc = E2 / 10;
        int donvi = E2 % 10;
        int sum = chuc + donvi;
        int i = sum % 10;
        P3 = P[i] / 100.0;
    }
    if ( P1 == 1 && P2 == 1 && P3 == 1 ){
        EXP1 = ceil( EXP1 - ( 25.0 / 100) * EXP1);
    }
    else{
        TBC = (( P1 + P2 + P3) / 3.0 );
        if ( TBC < 0.5 ){
            HP1 = ceil(HP1 - (15.0 / 100) * HP1);
            EXP1 = ceil( EXP1 + (15.0 / 100) * EXP1);
        }
        else{
            HP1 = ceil(HP1 - (10.0 / 100) * HP1);
            EXP1 = ceil( EXP1 + ( 20.0 / 100) * EXP1);
        }
    }
    if ( EXP1 > 600) EXP1 = 600;
    else if ( EXP1 < 0) EXP1 = 0;
    if ( M1 > 3000) M1 = 3000;
    else if ( M1 < 0) M1 = 0;
    if ( HP1 > 666) HP1 = 666;
    else if ( HP1 < 0) HP1 = 0;


    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    int maxleft, maxright, diemSherlockvaWatson;
    int hanggap = 0;
    int cotgap =0;
    int matran[10][10];
    for ( int i =0; i < 10; i++){
        for ( int j =0; j < 10; j++){
            matran[i][j] = ((E3 * j) + (i * 2)) * ( i - j);
        }
    }
    for ( int i =0; i < 10; i++){
        for ( int j = 0; j < 10; j++){
            if ( matran[i][j] > (E3 * 2) ){
                hanggap++;
            }
            else if ( matran[i][j] < (-(E3))){
                cotgap++;
            }
        }
    }
    if ( hanggap >= 10){
        for ( int i = 0; hanggap >= 10; i++){
            int hanggapchuc = hanggap / 10;
            int hanggapdonvi = hanggap % 10;
            hanggap = hanggapchuc + hanggapdonvi;
        }
    }
    if ( cotgap >= 10){
        for ( int j =0; cotgap >= 10; j++){
            int cotgapchuc = cotgap / 10;
            int cotgapdonvi = cotgap % 10;
            cotgap = cotgapchuc + cotgapdonvi;
        }
    }
    int Taxipoint = matran[hanggap][cotgap];
    int maxleftpos = 0;
    int maxleftneg = 0;
    int maxrightpos = 0;
    int maxrightneg = 0;
    for ( int i =0; (hanggap + i) < 10 || ( cotgap + i) < 10; i++){
        if ( matran[hanggap + i][cotgap + i] > maxleftpos){
            maxleftpos = matran[hanggap + i][cotgap + i];
        }
    }
    for ( int i =0; (hanggap - i) >= 0 || (cotgap -i) >= 0; i++){
        if (matran[hanggap -i][cotgap -i] > maxleftneg){
            maxleftneg = matran[hanggap - i][cotgap - i];
        }
    }
    if ( maxleftpos > maxleftneg){
        maxleft = maxleftpos;
    }
    else{
        maxleft = maxleftneg;
    }
    for ( int i = 0; ( hanggap + i) < 10 || ( cotgap - i) >= 0; i++ ){
        if (matran[hanggap + i][cotgap - i] > maxrightpos){
            maxrightpos = matran[hanggap +i][cotgap -i];
        }
    }
    for ( int i =0; ( hanggap - i) >= 0 || ( cotgap + i) < 10; i++){
        if (matran[hanggap - i][cotgap + i] > maxrightneg){
            maxrightneg = matran[ hanggap - i][cotgap +i];
        }
    }
    if ( maxrightpos > maxrightneg){
        maxright = maxrightpos;
    }
    else{
        maxright = maxrightneg;
    }
    if ( maxleft > maxright){
        diemSherlockvaWatson = maxleft;
    }
    else{
        diemSherlockvaWatson = maxright;
    }
    if ( abs(Taxipoint) > abs(diemSherlockvaWatson)){
        EXP1 = ceil( EXP1 - (12.0 / 100) * EXP1);
        EXP2 = ceil( EXP2 - (12.0 / 100) * EXP2 );
        HP1 = ceil(HP1 - (10.0 / 100) * HP1);
        HP2 = ceil(HP2 - (10.0 / 100) * HP2);
        return Taxipoint;
    }
    else{
        EXP1 = ceil( EXP1 + (12.0 / 100) * EXP1);
        EXP2 = ceil( EXP2 + (12.0 / 100) * EXP2);
        HP1 = ceil( HP1 +( 10.0 / 100) * HP1);
        HP2 = ceil( HP2 +( 10.0 / 100) * HP2);
        return diemSherlockvaWatson;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string bassword = s;
    string bemp = email;
    string be = bemp.substr(0 , bemp.find("@"));
    if ( bassword.length() < 8) return -1;
    if ( bassword.length() > 20) return -2;
    size_t bao = bassword.find( be);
    if ( bao != string::npos){
        return -(300 + static_cast<int>(bao));
    }
    for ( int i = 0; i < bassword.length(); i++){
        if ( bassword[i] == bassword[i + 1] && bassword[i] == bassword[i + 2] ){
                return -(400 + i);
        }
    }
    bool kytudacbiet = false;   
    for ( int i = 0; i < bassword.length(); i++){
        char cl = s[i];
        if ( isalnum(cl)){
            continue;
        }
        int n = cl;
        if ( n == 64 || n == 35 || n == 37 || n == 36 || n == 33){
            kytudacbiet = true;
        }
        else{
            return i;
        }
    } 
    if (!kytudacbiet){
        return -5;
    } 
    return -10;

}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int position = -1;
    int solanxayra = 0;
    int solanxayranhieunhat = 0;
    int maxkytu = 0;
    for ( int i = 0; i < num_pwds; i++){
        solanxayra = 0;
        for ( int j = 0; j < num_pwds; j++){
            if ( strcmp(arr_pwds[i], arr_pwds[j]) == 0){
            solanxayra ++;
            }
        }
        int sokytu = strlen(arr_pwds[i]);
        if ( solanxayra > solanxayranhieunhat || solanxayra == solanxayranhieunhat && sokytu > maxkytu ){
            solanxayranhieunhat = solanxayra;
            maxkytu = sokytu;
            position = i;
        }
    }
    return position;

}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////