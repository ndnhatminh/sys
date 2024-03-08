#include "study_in_pink1.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <climits>
#include <string>
#include <fstream>
#include <sstream>

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
void checksmallexp(int & exp1, int & exp2) 
{
    if (exp1 < 0 || exp2 < 0)//
    {
        if (exp1 < 0)
        {
            exp1 = 0;
        }
        else if (exp2 < 0)
        {
            exp2 = 0;
        }
    }
    if (exp1 > 600 || exp2 > 600)
    {
        if (exp1 > 600)
        {
            exp1 = 600;
        }
        else if (exp2 > 600)
        {
            exp2 = 600;
        }
    }
    
}
void checkEXP(int & EXP1, int & EXP2)
{
    if (EXP1 < 0 || EXP2 < 0)
    {
        if (EXP1 < 0)
        {
            EXP1 = 0;
        }
        else if (EXP2 < 0)
        {
            EXP2 = 0;
        }
    }
    if (EXP1 > 600 || EXP2 > 600)
    {
        if (EXP1 > 600)
        {
            EXP1 = 600;
        }
        else if (EXP2 > 600)
        {
            EXP2 = 600;
        }
    }
}
void checkMoney(int & M1, int & M2)
{
    if (M1 < 0 || M2 < 0)
    {
        if (M1 < 0)
        {
            M1 = 0;
        }
        else if (M2 < 0)
        {
            M2 = 0;
        }
    }
    if (M1 > 3000 || M2 > 3000)
    {
        if (M1 > 3000)
        {
            M1 = 3000;
        }
        else if (M2 > 3000)
        {
            M2 = 3000;
        }
    }
}
void checkHP(int & HP1, int & HP2)
{
    if (HP1 < 0 || HP2 < 0)
    {
        if (HP1 < 0)
        {
            HP1 = 0;
        }
        else if (HP2 < 0)
        {
            HP2 = 0;
        }
    }
    if (HP1 > 666 || HP2 > 666)
    {
        if (HP1 > 666)
        {
            HP1 = 666;
        }
        else if (HP2 > 666)
        {
            HP2 = 666;
        }
    }
}
void checkHP1(int & HP1){
    if (HP1 < 0)
    {
        HP1 = 0;
    }
    if (HP1 > 666)
    {
        HP1 = 666;
    }

}
void checkEXP1(int & EXP1){
    if (EXP1 < 0)
    {
        EXP1 = 0;
    }
    if (EXP1 > 600)
    {
        EXP1 = 600;
    }
}
void checkM1(int & M1){
    if (M1 < 0)
    {
        M1 = 0;
    }
    if (M1 > 3000)
    {
        M1 = 3000;
    }
}
int restrict(int x, int lowerLimit, int upperLimit){
x = (x < lowerLimit) ? lowerLimit : (x > upperLimit ? upperLimit : x);
return x;
}
// Task 1

int firstMeet(int & exp1, int & exp2, int e1) {
    int lowerLimit = 0, upperLimit = 600;
    
    
    if (e1 < 0 || e1 > 99) return -99;
    if (e1 >= 0 && e1 <= 3){
        exp1 = restrict(exp1, lowerLimit, upperLimit);
        exp2 = restrict(exp2, lowerLimit, upperLimit);
        if (e1 == 0){
            exp2 += 29;
        }
        else if (e1 == 1){
            exp2 += 45;
        }
        else if (e1 == 2){
            exp2 += 75;
        }
        else if (e1 == 3){
            exp2 += 149;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0){
            double temp = exp1 + D/200.0;
            exp1 = ceil(temp);
        }
        else{
            double temp = exp1 - double(D)/100.0;
            exp1 = ceil(temp);
        }
        exp2 = restrict(exp2, lowerLimit, upperLimit);
        exp1 = restrict(exp1, lowerLimit, upperLimit);
    }
    else if (e1 >= 4 && e1 <= 99){
        exp1 = restrict(exp1, lowerLimit, upperLimit);
        exp2 = restrict(exp2, lowerLimit, upperLimit);
        if (e1 >= 4 && e1 <= 19){
            exp2 = ceil(double(exp2 + e1/4.0 + 19));
        }
        else if (e1 >= 20 && e1 <= 49){
            exp2 = ceil(double(exp2 + e1/9.0 + 21));
        }
        else if (e1 >= 50 && e1 <= 65){
            exp2 = ceil(double(exp2 + e1/16.0 + 17));
        }
        else if (e1 >= 66 && e1 <= 79){
            exp2 = ceil(double(exp2 + e1/4.0 + 19));
            if (exp2 > 200){
                exp2 = ceil(double(exp2 + e1/9.0 + 21));
            }
        }
        else if (e1 >= 80 && e1 <= 99){
            exp2 = ceil(exp2 + (double(e1)/4 + 19));
            exp2 = ceil(exp2 + (double(e1)/9 + 21));
            if (exp2 > 400){
                exp2 = ceil(double(exp2 + double(e1)/16 + 17));
                exp2 = ceil(double(exp2 + exp2*0.15));
            }
        
        }
        exp1 = restrict(exp1, lowerLimit, upperLimit);
        exp2 = restrict(exp2, lowerLimit, upperLimit);
        exp1 -= e1;
    }
    
    exp1 = restrict(exp1, lowerLimit, upperLimit);
    exp2 = restrict(exp2, lowerLimit, upperLimit);
    return exp1 + exp2;
}


// Task 2



int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    int lowerLimit = 0, upperLimit = 600;
    if (E2 < 0 || E2 > 99) return -99;
    EXP1 = restrict(EXP1, lowerLimit, upperLimit);
    HP1 = restrict(HP1, 0, 666);
    M1 = restrict(M1, 0, 3000);
    //road1
    double sqrtEx1 = sqrt(EXP1);
    int y1 = pow(trunc(sqrtEx1), 2);
    int y2 = pow(trunc(sqrtEx1) + 1, 2);
    double P1;
    if (abs(EXP1 - y1)<abs(EXP1 - y2)){
        P1 = 100.0;
    }
    else if (abs(EXP1 - y1)>abs(EXP1 - y2)) {
        P1 = ((EXP1/y2) + 80)/1.230;
    }

    //road2
        int M = M1;
    while (E2%2 != 0)
    {
        EXP1 = restrict(EXP1, lowerLimit, upperLimit);
        HP1 = restrict(HP1, 0, 666);
        M1 = restrict(M1, 0, 3000);
      if (M1 < (0.5*M) || M1 == 0) {
       HP1 = ceil(HP1 - 0.17*HP1);
       EXP1 = ceil(EXP1 + 0.17*EXP1);
       EXP1 = restrict(EXP1, lowerLimit, upperLimit);
        HP1 = restrict(HP1, 0, 666);
       break;
    }
      if (HP1 < 200) {
        HP1 = ceil(HP1 + 0.3*HP1);
        M1 -= 150;
        M1 = restrict(M1, 0, 3000);
        HP1 = restrict(HP1, 0, 666);
    }
    else {
        HP1 = ceil(HP1 + 0.1*HP1);
        M1 -= 70;
        M1 = restrict(M1, 0, 3000);
        HP1 = restrict(HP1, 0, 666);
    }
    EXP1 = restrict(EXP1, lowerLimit, upperLimit);
    HP1 = restrict(HP1, 0, 666);
    M1 = restrict(M1, 0, 3000);
   if (M1 < (0.5*M) || M1 == 0) {
       HP1 = ceil(HP1 - 0.17*HP1);
       EXP1 = ceil(EXP1 + 0.17*EXP1);
       EXP1 = restrict(EXP1, lowerLimit, upperLimit);
        HP1 = restrict(HP1, 0, 666);
       break;
    }
    if (EXP1 < 400) {
        M1 -= 200;
        M1 = restrict(M1, 0, 3000);
    }
    else {
        M1 -= 120;
        M1 = restrict(M1, 0, 3000);
    }
    EXP1 = ceil(EXP1 + 0.13*EXP1);
    EXP1 = restrict(EXP1, lowerLimit, upperLimit);
    if (M1 < (0.5*M) || M1 == 0) {
        HP1 = ceil(HP1 - 0.17*HP1);
       EXP1 = ceil(EXP1 + 0.17*EXP1);
       EXP1 = restrict(EXP1, lowerLimit, upperLimit);
        HP1 = restrict(HP1, 0, 666);
       break;
    }
    if (EXP1 < 300) {
        M1 -= 100;
        M1 = restrict(M1, 0, 3000);
    }
    else {
        M1 -= 120;
        M1 = restrict(M1, 0, 3000);
    }
    EXP1 = ceil(EXP1 - 0.1*EXP1);
    EXP1 = restrict(EXP1, lowerLimit, upperLimit);
    M1 = restrict(M1, 0, 3000);
    }
    
    while (E2%2 == 0)
    {
        EXP1 = restrict(EXP1, lowerLimit, upperLimit);
        HP1 = restrict(HP1, 0, 666);
        M1 = restrict(M1, 0, 3000);
        if (M1 <= 0) {
            HP1 = ceil(HP1-0.17*HP1);
            EXP1 = ceil(EXP1+0.17*EXP1);
            EXP1 = restrict(EXP1, lowerLimit, upperLimit);
            HP1 = restrict(HP1, 0, 666);
        break;
        }
        if (HP1 < 200) {
        HP1 = ceil(HP1 + 0.3*HP1);
        M1 -= 150;
        M1 = restrict(M1, 0, 3000);
        HP1 = restrict(HP1, 0, 666);
        }
        else {
        HP1 = ceil(HP1 + 0.1*HP1);
        M1 -= 70;
        M1 = restrict(M1, 0, 3000);
        HP1 = restrict(HP1, 0, 666);
        }
        if (M1 <= 0) {
            HP1 = ceil(HP1-0.17*HP1);
            EXP1 = ceil(EXP1+0.17*EXP1);
            EXP1 = restrict(EXP1, lowerLimit, upperLimit);
            HP1 = restrict(HP1, 0, 666);
        break;
        }
        if (EXP1 < 400) {
        M1 -= 200;
        M1 = restrict(M1, 0, 3000);
        }
        else {
        M1 -= 120;
        M1 = restrict(M1, 0, 3000);
        }
        EXP1 = ceil(EXP1 + 0.13*EXP1);
        EXP1 = restrict(EXP1, lowerLimit, upperLimit);
        if (M1 <= 0) {
            HP1 = ceil(HP1-0.17*HP1);
            EXP1 = ceil(EXP1+0.17*EXP1);
            EXP1 = restrict(EXP1, lowerLimit, upperLimit);
            HP1 = restrict(HP1, 0, 666);
        break;
        }
     
        if (EXP1 < 300) {
        M1 -= 100;
        M1 = restrict(M1, 0, 3000);
        }
        else {
        M1 -= 120;
        M1 = restrict(M1, 0, 3000);
        }
        EXP1 = ceil(EXP1- 0.1*EXP1);
        HP1 = ceil(HP1-0.17*HP1);
        EXP1 = ceil(EXP1+0.17*EXP1);
        EXP1 = restrict(EXP1, lowerLimit, upperLimit);
        HP1 = restrict(HP1, 0, 666);
        M1 = restrict(M1, 0, 3000);
        break;
    }

 double sqrtEXP1 = sqrt(EXP1);
    int x1 = pow(trunc(sqrtEXP1), 2);
    int x2 = pow(trunc(sqrtEXP1) + 1, 2);
    double P2;
    if (abs(EXP1 - x1)<abs(EXP1 - x2)){
        P2 = 100.0;
    }
    else if (abs(EXP1 - x1)>abs(EXP1 - x2)) {
        P2 = ((EXP1/x2) + 80)/1.230;
    }

        //road3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int P3i;
    int i;
    if (E2 < 10)
    {
        i = E2;
        P3i = P[i];
    }
    else
    {
        
        if (E2 > 9) {
        E2 = E2 % 10 + E2 / 10;
        }
        i = E2%10;
        P3i = P[i];
    }
    double P3 = P3i;
    if (P1 == 100 && P2 == 100 && P3 == 100)
    {
        EXP1 = ceil(double(EXP1 - 0.25*EXP1));
        EXP1 = restrict(EXP1, lowerLimit, upperLimit);

    }
    else
    {
        double finalP = (P1 + P2 + P3) / 3.0;
        if (finalP > 50.0)
        {
            HP1 = ceil(double(HP1 - 0.1*HP1));
            EXP1 = ceil(double(EXP1 + 0.2*EXP1));
            EXP1 = restrict(EXP1, lowerLimit, upperLimit);
            HP1 = restrict(HP1, 0, 666);
        }
        else
        {
            HP1 = ceil(double(HP1 - 0.15*HP1));
            EXP1 = ceil(double(EXP1 + 0.15*EXP1));
            EXP1 = restrict(EXP1, lowerLimit, upperLimit);
            HP1 = restrict(HP1, 0, 666);
        }
       EXP1 = restrict(EXP1, lowerLimit, upperLimit);
    HP1 = restrict(HP1, 0, 666);

    }
    EXP1 = restrict(EXP1, lowerLimit, upperLimit);
    HP1 = restrict(HP1, 0, 666);
    return HP1 + EXP1 + M1;
}

// Task 3
int tonghaichuso(int so) {
    while (so > 9) {
        so = so / 10 + so % 10;
    }
    return so;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) return -99;
    int lowerLimit = 0, upperLimit = 600;
    EXP1 = restrict(EXP1, lowerLimit, upperLimit);
    EXP2 = restrict(EXP2, lowerLimit, upperLimit);
    HP1 = restrict(HP1, 0, 666);
    HP2 = restrict(HP2, 0, 666);
    const int rows = 10;
    const int cols = 10;

    int matrix[rows][cols] = {0};
    int diemsotaxi[rows][cols] = {0};
    int diemsosherlock[rows][cols] = {0};
    int countP = 0;
    int countN = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            int value = matrix[i][j];
            diemsotaxi[i][j] = value; 
            if (value > E3 * 2 && value > 0) {
                countP++;
            }
            if (value < -E3){
                countN++;
            }
        }
    }
    for (int j = 0; j < cols; ++j){
        for (int i = 0; i < rows; ++i){
            int giatrilonnhat = diemsotaxi[i][j];
            // Check the left diagonal
            for (int k = 1; k <= i && k <= j; ++k) {
                giatrilonnhat = max(giatrilonnhat, diemsotaxi[i - k][j - k]);
            }
            // Check the right diagonal
            for (int k = 1; k < rows - i && k <= j; ++k) {
                giatrilonnhat = max(giatrilonnhat, diemsotaxi[i + k][j - k]);
            }
            diemsosherlock[i][j] = abs(giatrilonnhat);
        }
    }
    countP = tonghaichuso(countP);
    countN = tonghaichuso(countN);
    int diemtaxi = diemsotaxi[countP][countN];
    int diemsherlock = diemsosherlock[countP][countN];
    if (abs(diemtaxi) > diemsherlock){
        EXP1 = ceil(EXP1 - EXP1*0.12);
        EXP2 = ceil(EXP2 - EXP2*0.12);
        HP1 = ceil(HP1 - HP1*0.1);
        HP2 = ceil(HP2 - HP2*0.1);
        EXP1 = restrict(EXP1, lowerLimit, upperLimit);
        HP1 = restrict(HP1, 0, 666);
        EXP2 = restrict(EXP2, lowerLimit, upperLimit);
        HP2 = restrict(HP2, 0, 666);
        return diemtaxi;
    }
    else if (abs(diemtaxi) <= diemsherlock){
        EXP1 = ceil(EXP1 + EXP1*0.12);
        EXP2 = ceil(EXP2 + EXP2*0.12);
        HP1 = ceil(HP1 + HP1*0.1);
        HP2 = ceil(HP2 + HP2*0.1);
        EXP1 = restrict(EXP1, lowerLimit, upperLimit);
        HP1 = restrict(HP1, 0, 666);
        EXP2 = restrict(EXP2, lowerLimit, upperLimit);
        HP2 = restrict(HP2, 0, 666);
        return diemsherlock;
    }
    return -1;
}

// Task 4
bool islegal(char t) {
    return (t >= 'A' && t <= 'Z') || (t >= 'a' && t <= 'z') || (t >= '0' && t <= '9');
}
int checkPassword(const char * s, const char * email) {
    string password(s);
    string Email(email);
    string se = Email.substr(0, Email.find('@'));
    if (password.length() < 8){
        return -1;
    }
    if (password.length() > 20){
        return -2;
    }
    if (password.find(se) != string::npos){
        return -(300 + password.find(se));
    }
    for (int i = 0; i < password.length() - 2; i++){
        if (password[i] == password[i+1] && password[i+1] == password[i+2]){
            return -(400 + i);
        }
    }
    string chars = "@#$%!";
    size_t spec = password.find_first_of(chars);
    if (spec == string::npos) {
        return -5;
    }
    for (int i = 0; i < password.length(); i++){
        if (chars.find(password[i]) == string::npos){
            if (islegal(password[i]) == false){
            return i;
            break;
            }
        }
    } 

    return -10;
    
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string passwords[30];
    int freq[30] = {0}; 
    int firstposition[30] = {0};
    int freqMax = 0;
    string correctpw;
    int pwcount = 0;
    for (int i = 0; i < num_pwds; i++){
        string pw = arr_pwds[i]; 
        int index = -1;
        for (int j = 0; j < pwcount; j++){
            if (passwords[j] == pw){
                index = j;
                break;
            }
        }
        if (index == -1){
            passwords[pwcount] = pw;
            firstposition[pwcount] = i;
            freq[pwcount] = 1;
            index = pwcount;
            pwcount++;
        }
        else{
            freq[index]++;
        }

        bool higherfreq = freq[index] > freqMax;
        bool equalfreqbutlonger = freq[index] == freqMax && pw.length() > correctpw.length();
        if (higherfreq || equalfreqbutlonger){
            freqMax = freq[index];
            correctpw = passwords[index];
        }
    } 
    for (int i = 0; i < pwcount; i++){
        if (passwords[i] == correctpw){
            return firstposition[i];
        }
    }

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////