#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

/* Task 1 ******************************************************************************************/
void fixEXP(int & exp1, int & exp2){
    if(exp1 < 0) exp1 = 0;
    else if( exp1 > 600) exp1 = 600;
    if(exp2 < 0) exp2 = 0;
    else if( exp2 > 600) exp2 = 600;
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if((e1 > 99) || (e1 < 0)) return -99;
    else{
        fixEXP(exp1, exp2);
        if(e1 < 4){//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~E1 < 4
            if(e1 - 3){
                exp2 += 7*e1*e1 + 9*e1 + 29; fixEXP(exp1, exp2);
            }
            else{
                exp2 += 149; fixEXP(exp1, exp2);
            }
            int D = e1 * 3 + exp1 * 7;
            if(D % 2){
                double exp =  exp1 - (double)D/100; exp1 = (exp) + (double) 0.999;
                fixEXP(exp1, exp2);
            }
            else{
                double exp =  exp1 + (double)D/200; exp1 = (exp) + (double) 0.999;
                fixEXP(exp1, exp2);
            }
        }
        else{//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~E1 > 3
            if(e1 < 20){ //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CASE 1
                double exp = exp2 + (double)e1/4 + 19; exp2 = (exp)+ (double) 0.999;
                fixEXP(exp1, exp2);
            }else if((e1 > 19) && (e1 < 50)){ //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CASE 2
                double exp = exp2 + (double)e1/9 + 21; exp2 = (exp)+ (double) 0.999;
                fixEXP(exp1, exp2);
            }else if((e1 > 49) && (e1 < 66)){ //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CASE 3
                double exp = exp2 + (double)e1/16 + 17; exp2 = (exp)+ (double) 0.999;
                fixEXP(exp1, exp2);
            }else if((e1 > 65) && (e1 < 80)){//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CASE 4
                double exp = exp2 + (double)e1/4 + 19; exp2 = (exp)+ (double) 0.999;
                fixEXP(exp1, exp2);
                if(exp2 > 200){
                    double exp = exp2 + (double)e1/9 + 21;
                    exp2 = (exp) + (double) 0.999;
                    fixEXP(exp1, exp2);
                }
            }else{//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CASE 5
                double exp = exp2 + (double)e1/4 +19; exp2 = exp + (double) 0.999 ; //case 1
                exp = exp2 +(double)e1/9 + 21; exp2 = exp + (double) 0.999; //case 2
                fixEXP(exp1, exp2);
                if(exp2 > 400){
                    double exp = exp2 + (double)e1/16 + 17;
                    exp2 = (exp) + (double) 0.999;
                    exp2 = (1.15 * exp2) + (double) 0.999;
                    fixEXP(exp1, exp2);
                }
            }
            exp1 -= e1;
            fixEXP(exp1, exp2);
        }
        return exp1 + exp2; } }
/* Task 2******************************************************************************************/
void fixNumber(int &HP1, int & EXP1, int & M1){
    if(EXP1 < 0) EXP1 = 0;
    else if( EXP1 > 600) EXP1 = 600;
    if(HP1 < 0) HP1 = 0;
    else if( HP1 > 666) HP1 = 666;
    if(M1 < 0) M1 = 0;
    else if( M1 > 3000) M1 = 3000;
}
// TO CHECK WHETHER SQUARENUMBER <= EXP1 or > (return true if squareNumber <= EXP1 and return false if contrast)
bool checkSquareNumber(int EXP1, int &S){
    bool n;
        int sn1, sn2;
        // FINE THE SQUARENUMBER <= EXP1 AND NEAREST (sn1)
        for(int i = EXP1; 1; i--){
            int SquarerootNumber = sqrt(i);
            if(SquarerootNumber == sqrt(i)){
                sn1 = i;
                break;
            }else continue;
        }
        // FINE THE SQUARENUMBER >= EXP1 AND NEAREST (sn2)
        for(int i = EXP1; 1; i++){
            int SquarerootNumber = sqrt(i);
            if(SquarerootNumber == sqrt(i)){
                sn2 = i;
                break;
            }else continue;
        }
        int LeftDistance = EXP1 - sn1; //DISTANCE BETWEEN EXP1 AND sn1
        int RightDistance = sn2 - EXP1;//DISTANCE BETWEEN EXP1 AND sn2
        //CHECK WHICH IS SHORTER
        if( LeftDistance <= RightDistance)
            n = 1;
        else{
            n = 0;
            S = sn2;
        }
    return n;
}
//CASESES OF PATH 2
int path2(int & HP1, int & EXP1, int & M1, int E2, double M){
        if(HP1 < 200){
            HP1 = (HP1*1.3) + (double) 0.999;
            M1 -= 150;
            fixNumber(HP1, EXP1, M1);
            if((M1 < M)&&(E2%2)){
                HP1 = (0.83 * HP1) + (double) 0.999;
                EXP1 = (1.17 * EXP1) + (double) 0.999;
                fixNumber(HP1, EXP1, M1);
                return EXP1;
            }
            else if((M1 <= 0)&&(!(E2%2))){
                HP1 = (0.83 * HP1) + (double) 0.999;
                EXP1 = (1.17 * EXP1) + (double) 0.999;
                fixNumber(HP1, EXP1, M1);
                return EXP1;
            }
        }
        else {
            HP1 = (HP1*1.1) + (double) 0.999;
            M1 -= 70;
            fixNumber(HP1, EXP1, M1);
            if((M1 < M)&&(E2%2)){
                HP1 = (0.83 * HP1) + (double) 0.999;
                EXP1 = (1.17 * EXP1) + (double) 0.999;
                fixNumber(HP1, EXP1, M1);
                return EXP1;
            }
            else if((M1 <= 0)&&(!(E2%2))){
                HP1 = (0.83 * HP1) + (double) 0.999;
                EXP1 = (1.17 * EXP1) + (double) 0.999;
                fixNumber(HP1, EXP1, M1);
                return EXP1;
            }
        }
        if(EXP1 < 400) {
            M1 -= 200;
            EXP1 = (1.13*EXP1) + (double) 0.999;
            fixNumber(HP1, EXP1, M1);
            if((M1 < M)&&(E2%2)){
                HP1 = (0.83 * HP1) + (double) 0.999;
                EXP1 = (1.17 * EXP1) + (double) 0.999;
                fixNumber(HP1, EXP1, M1);
                return EXP1;
            }
            else if((M1 <= 0)&&(!(E2%2))){
                HP1 = (0.83 * HP1) + (double) 0.999;
                EXP1 = (1.17 * EXP1) + (double) 0.999;
                fixNumber(HP1, EXP1, M1);
                return EXP1;
            }
        }
        else {
            M1 -= 120;
            EXP1 = (1.13*EXP1) + (double) 0.999;
            fixNumber(HP1, EXP1, M1);
            if((M1 < M)&&(E2%2)){
                HP1 = (0.83 * HP1) + (double) 0.999;
                EXP1 = (1.17 * EXP1) + (double) 0.999;
                fixNumber(HP1, EXP1, M1);
                return EXP1;
            }
            else if((M1 <= 0)&&(!(E2%2))){
                HP1 = (0.83 * HP1) + (double) 0.999;
                EXP1 = (1.17 * EXP1) + (double) 0.999;
                fixNumber(HP1, EXP1, M1);
                return EXP1;
            }
        }
        if(EXP1 < 300){
            M1 -= 100;
            EXP1 = (EXP1*0.9) + (double) 0.999;
            fixNumber(HP1, EXP1, M1);
            if((M1 < M)&&(E2%2)){
                HP1 = (0.83 * HP1) + (double) 0.999;
                EXP1 = (1.17 * EXP1) + (double) 0.999;
                fixNumber(HP1, EXP1, M1);
                return EXP1;
            }
            else if((!(E2%2))){
                HP1 = (0.83 * HP1) + (double) 0.999;
                EXP1 = (1.17 * EXP1) + (double) 0.999;
                fixNumber(HP1, EXP1, M1);
                return EXP1;
            }
        }
        else{
            M1 -= 120;
            EXP1 = (EXP1*0.9) + (double) 0.999;
            fixNumber(HP1, EXP1, M1);
            if((M1 < M)&&(E2%2)){
                HP1 = (0.83 * HP1) + (double) 0.999;
                EXP1 = (1.17 * EXP1) + (double) 0.999;
                fixNumber(HP1, EXP1, M1);
                return EXP1;
            }
            else if(!(E2%2)){
                HP1 = (0.83 * HP1) + (double) 0.999;
                EXP1 = (1.17 * EXP1) + (double) 0.999;
                fixNumber(HP1, EXP1, M1);
                return EXP1;
            }
        }
    fixNumber(HP1, EXP1, M1);
    return 0;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if((E2 < 0)|| (E2 > 99)) return - 99;
    else{
        // for(int j = 0; 1; j ++){
        fixNumber(HP1, EXP1,  M1);
            double p1, p2, p3;
            int S = 4; // optional value
            double M = (double)M1/2;
            //probability of path 1
            if(checkSquareNumber(EXP1, S)) p1 = 1;
            else p1 = ((double)EXP1/S + 80)/123;
            // probability of path 2
            for(int i = 0; 1; i ++){
                if((M1 > M)&&(E2%2)) {path2(HP1, EXP1, M1, E2, M);if(M1 < M) break;}
                else if(M1 == 0){
                    HP1 = (0.83 * HP1) + (double) 0.999;
                    EXP1 = (1.17 * EXP1) + (double) 0.999;
                    fixNumber(HP1, EXP1, M1);
                    break;
                }
                else if(!(E2%2)){
                    path2(HP1, EXP1, M1, E2, M);
                    break;
                }else break;
            }
            if(checkSquareNumber(EXP1, S)) p2 = 1;
            else p2 = ((double)EXP1/S + 80)/123;
            //probability of path 3
            int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}, i = 0;
            if(E2 < 10) i = E2;
            else{
                int a, b;
                a = E2%10;
                b = (E2 - a)/10;
                i = (a + b)%10;
            }
            p3 = (double)P[i]/100;
            if((p1 == 1)&&(p2 == 1)&&(p3 == 1)){
                EXP1 = (EXP1 * 0.75) + (double) 0.999;
                fixNumber(HP1, EXP1, M1);
               // continue;
            }
            else{
                double P = (p1 + p2 + p3)/3;
                if(P < 0.5){
                    HP1 = (HP1*0.85) + (double) 0.999;
                    EXP1 = (EXP1*1.15) + (double) 0.999;
                    fixNumber(HP1, EXP1, M1);
                }else{
                    HP1 = (0.9*HP1) + (double) 0.999;
                    EXP1 = (EXP1*1.2) + (double) 0.999;
                    fixNumber(HP1, EXP1, M1);
                }
               // break;
            }
        // }
        fixNumber(HP1, EXP1, M1);
        return HP1 + EXP1 + M1;
    }
}
/* Task 3 ******************************************************************************************/
void fixNum(int &HP1, int & EXP1, int &HP2, int &EXP2){
    if(EXP1 < 0) EXP1 = 0;
    else if( EXP1 > 600) EXP1 = 600;
    if(EXP2 < 0) EXP2 = 0;
    else if( EXP2 > 600) EXP2 = 600;
    if(HP1 < 0) HP1 = 0;
    else if( HP1 > 666) HP1 = 666;
    if(HP2 < 0) HP2 = 0;
    else if( HP2 > 666) HP2 = 666;
}
//FIND THE MATRIX CONTAINNING THE SCORES OF SHERLOCK & WATSON.
void computeGrade(int E3, int i, int j, int & grade){
    int gradeTaxi[10][10];
    for(int m = 0; m < 10; m++)
        for(int n = 0; n < 10; n++){
            gradeTaxi[m][n] = ((E3 * n) + (m * 2)) * ((m - n));
        }
    int max = gradeTaxi[i][j];
    for(int m = 1; m < 10; m++){
        if((i == 0)||(j == 0)) break;
        else{
            if(gradeTaxi[i - m][j - m] > max)
                max = gradeTaxi[i - m][j - m];
            if((i - m == 0)||(j - m == 0)) break;
        }
    }
    for(int m = 1; m < 10; m++){
        if((i == 9)||(j == 0)) break;
        else{
            if(gradeTaxi[i + m][j - m] > max)
                max = gradeTaxi[i + m][j - m];
            if((i + m == 9)||(j - m == 0)) break;
        }
    }
    for(int m = 1; m < 10; m++){
        if((i == 0)||(j == 9)) break;
        else{
            if(gradeTaxi[i - m][j + m] > max)
                max = gradeTaxi[i - m][j + m];
            if((i - m == 0)||(j + m == 9)) break;
        }
    }
    for(int m = 1; m < 10; m++){
        if((i == 9)||(j == 9)) break;
        else{
            if(gradeTaxi[i + m][j + m] > max)
                max = gradeTaxi[i + m][j + m];
            if((i + m == 9)||(j + m == 9)) break;
        }
    }
    grade = abs(max);
}
//FINE I AND J
void ref(int &i, int &j){
    for(int m = 1; 1; m++){
        if((i < 10)&&(j < 10)){return;}
        else{
            if(i > 9){
                int a, b;
                a = i%10;
                b = (i - a)/10;
                i = a + b;
            }
            if(j > 9){
                int a, b;
                a = j%10;
                b = (j - a)/10;
                j = a + b;
            }
        }
    }
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if((E3 > 99) || (E3 < 0)) return -99;
    else{
        fixNum(HP1, EXP1, HP2, EXP2);
        // THE MATRIX OF TAXI'S GRADE
        int gradeTaxi[10][10], gradeSher[10][10], gradeWat[10][10], grade;
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++)
                gradeTaxi[i][j] = ((E3 * j) + (i * 2)) * ((i - j));
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++){
                computeGrade(E3, i, j, grade);
                gradeSher[i][j] = grade;
                gradeWat[i][j] = grade;
            }
        int i = 0, j = 0;
        for(int m = 0; m < 10; m++){
            for(int n = 0; n < 10; n ++){
                if(n > m){ if(gradeTaxi[m][n] < (E3 * (-1))) j += 1;}
                else{
                    if(gradeTaxi[m][n] > (E3*2)) i += 1;
                }
            }
        }
        ref(i, j);
        if(abs(gradeTaxi[i][j]) > gradeSher[i][j]){
            EXP1 = (0.88*EXP1)+ (double) 0.999;
            EXP2 = (0.88*EXP2)+ (double) 0.999;
            HP1 = (0.9*HP1)+ (double) 0.999;
            HP2 = (0.9*HP2)+ (double) 0.999;
            fixNum(HP1, EXP1, HP2, EXP2);
            return gradeTaxi[i][j];
        }else{
            EXP1 = (1.12*EXP1)+ (double) 0.999;
            EXP2 = (1.12*EXP2)+ (double) 0.999;
            HP1 = (1.1*HP1)+ (double) 0.999;
            HP2 = (1.1*HP2)+ (double) 0.999;
            fixNum(HP1, EXP1, HP2, EXP2);
            if((gradeTaxi[i][j]<0) && (abs(gradeTaxi[i][j])==gradeTaxi[i][j])) return gradeTaxi[i][j];
            else return gradeSher[i][j];
        }
    }
}
/*Task 4 ******************************************************************************************/
//TO CHECK THE SEPECIAL CHARACTER OF PASSWORD (return 0 if password has sepecial character and contrast return 1)
bool checkSepecialChar(int Char){
    int i = 0;
    if((Char != 33) && (Char != 35)&&(Char != 36)&&(Char != 37)&&(Char != 64)) i++;
    if((Char < 48) || (Char > 57)) i++;
    if((Char < 65) || (Char > 90)) i++;
    if((Char < 97) || (Char > 122)) i++;
    if(i == 4) return true;
    else return false;
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string pass = s, E = email, se;
    int sei, sci = -1;
    bool sepecialChar = 1;
    for(int i = 0; i < E.length(); i ++)
        if(E[i] == '@') se = E.substr(0,i);
    for(int i = 0; i < pass.length(); i++){
        if(i == pass.length() - 2){ break;}
        if((pass[i]==pass[i+1])&&(pass[i+1]==pass[i+2])){
            sci = i;
            break;
        }
    }
    for(int i =0; i < pass.length(); i++){
        int x = pass[i];
        if((x == 33)||(x == 35)||(x == 36)||(x == 37)||(x == 64))
            sepecialChar = 0;
    }
    if(pass.length() < 8) return -1;
    if(pass.length() > 20) return -2;
    if(pass.length() >= se.length()){
        if(pass == se){return -300;}
        else if(pass.length() > se.length()){
           for(int i = 0; i <= pass.length() - se.length(); i++)
               if(pass.substr(i, se.length()) == se){
                   sei = i;
                   return -(300+sei);
               }
       }
    }
    if(sci >= 0) return -(400 + sci);
    if(sepecialChar) return -5;
    for(int i =0; i < pass.length(); i++){
        if(checkSepecialChar((int)pass[i])) return i;
    }
    return -10;
}
/*Task 5 ******************************************************************************************/
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string* str = new string[num_pwds];
    for(int i = 0; i < num_pwds; i ++) str[i] = arr_pwds[i];
    int* A = new int[num_pwds]; //THIS MATRIX CONTAINS THE NUMBER OF STRINGS's OCCURRENCE
    int k = 1;
    for(int i = 0; i < num_pwds; i++) A[i] = 0; //INITIALIZE MATRIX A[] CONTAINS THE ZEROS VALUE
    for(int i = 0; i < num_pwds - 1; i ++)
        for(int j = i+1; j < num_pwds; j++){
            if(str[i] == "*") break;
            if((str[i] == str[j])){
                k += 1; // THE NUMBER OF STRINGS's OCCURRENCE
                str[j] = "*";// Strings that are identical to the previous string will be replaced with '*''
            }
            if(j == num_pwds - 1){A[i] = k; k = 1;break;}
        }
    int max = A[0];//Representing the most frequent occurrence
    int localMax = 0, k2 = 0;
    for(int i = 0; i < num_pwds; i++)  if(A[i] > max) max = A[i];
    for(int i = 0; i < num_pwds; i++)  if(A[i] == max){ k2+=1; localMax = i;}
    if(k2 == 1){ delete[] str; delete[] A;  return localMax;}
    if(k2 > 1){
        /* The localMax[] array stores the positions of the most frequently occurring strings (if not, assign the value -1)*/
        int* localMax = new int[num_pwds];
        for(int i = 0; i < num_pwds; i++) localMax[i] = -1;
        for(int i = 0; i < num_pwds; i++) if(A[i] == max) localMax[i] = i;
        int strMax = 0;
        for(int i = 0; i< num_pwds; i++)
            if(localMax[i] != -1){ strMax = (int)str[i].length(); break;}
        for(int i = 1; i < num_pwds; i++)
            if(((int)str[i].length() > strMax)&&(localMax[i] != -1)) strMax = (int)str[i].length();
        for(int i = 0; i < num_pwds; i++)
            if((strMax == (int)str[i].length())&&(localMax[i] != -1)){delete[] str; delete[] A; delete[] localMax; return i;}
    }
    return 1000;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
