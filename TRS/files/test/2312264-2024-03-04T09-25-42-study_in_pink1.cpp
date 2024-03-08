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
    checkExp(exp1);
    checkExp(exp2);
    if( (e1 > 99) || (e1 < 0) ) return -99;
    if( e1 <= 3 ){
        return firstMeetCase1(exp1, exp2, e1);
    }
     else if( e1 >= 4){
        return firstMeetCase2(exp1, exp2, e1);
     }
     return 0;
}
void checkExp(int &exp){
    if( exp > 600 ) exp = 600;
    if( exp < 0 ) exp = 0;
}
int firstMeetCase1(int &exp1, int &exp2, int e1){
    switch(e1){
            case 0:
                exp2 += 29;
                checkExp(exp2);
                break;
            case 1:
                exp2 += 45;
                checkExp(exp2);
                break;
            case 2:
                exp2 += 75;
                checkExp(exp2);
                break;
            case 3:
                exp2 = exp2 + 29 + 45 + 75;
                checkExp(exp2);
                break;
        }
        int D = e1 * 3 + exp1 * 7;
        if( D % 2 == 0){
            float x = (D * 1.0) / 200;
            exp1 += ceil(x);
        }
        else{
            float x = (D * 1.0) / 100;
            exp1 += ceil(-x);
        }
        checkExp(exp1);
        return exp1 + exp2;
}
int firstMeetCase2(int &exp1, int &exp2, int e1){
    float x = 0;
        if(e1 <= 19){
            x = ((e1 * 1.0) / 4);
            exp2 += ceil(x) + 19; 
            checkExp(exp2);
        }
        else if( (e1 >= 20) && (e1 <= 49) ){
            x = ((e1 * 1.0) / 9);
            exp2 += ceil(x) + 21; 
            checkExp(exp2);
        }
        else if( (e1 >= 50) && (e1 <= 65) ){
            x = ((e1 * 1.0) / 16) ;
            exp2 += ceil(x) + 17; 
            checkExp(exp2);
        }
        else if( (e1 >= 66) && (e1 <= 79) ){
            x = ((e1 * 1.0) / 4) ; //Giải thích thông tin 1
            exp2 += ceil(x) + 19; 
            checkExp(exp2);
            if(exp2 > 200){
                x = ((e1 * 1.0) / 9); //Giải thích thông tin 2
                exp2 += ceil(x) + 21; 
                checkExp(exp2);
            }
        }
        else if(e1 >= 80){
            x = ((e1 * 1.0) / 4) ; //Giải thích thông tin 1
            exp2 += ceil(x) + 19; 
            checkExp(exp2);
            x = ((e1 * 1.0) / 9) ; //Giải thích thông tin 2
            exp2 += ceil(x) + 21; 
            checkExp(exp2);
            if(exp2 > 400){
                x = ((e1 * 1.0) / 16) ; //Giải thích thông tin 3
                exp2 += ceil(x) + 17 ; 
                checkExp(exp2);
                x = 0.15 * exp2;
                exp2 += ceil(x);
                checkExp(exp2);
            }
        }
        exp1 -= e1;
        checkExp(exp1);
        return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    checkHP(HP1);
    checkExp(EXP1);
    checkMoney(M1);
    if( (E2 > 99) || (E2 < 0) ) return -99;
    float path1 = traceLuggage1(EXP1);
    float path2 = traceLuggage2(HP1, EXP1, M1, E2);
    float path3 = traceLuggage3(E2);
    float x;
    if( (path1 == 1) && (path2 == 1) && (path3 == 1) ){
        x = 0.25 * EXP1;
        EXP1 += ceil(-x);
        checkExp(EXP1);
    }
    else{
        float averageOfPath = (path1 + path2 + path3) / 3;
        if(averageOfPath < 0.5){
            x = 0.15 * HP1;
            HP1 += ceil(-x);
            checkHP(HP1); 
            x = 0.15 * EXP1;
            EXP1 += ceil(x);
            checkExp(EXP1);
        }
        else{
            x = 0.1 * HP1;
            HP1 += ceil(-x);
            checkHP(HP1); 
            x = 0.2 * EXP1;
            EXP1 += ceil(x);
            checkExp(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}
void checkMoney(int &m){
    if(m > 3000)  m = 3000;
    if(m < 0) m = 0;
}
void checkHP(int &HP){
    if(HP > 666) HP = 666;
    if(HP < 0 ) HP = 0;
}
int findPerfectNumber(int x){
    float sqrtX = sqrt(x);
    int x1 = ceil(sqrtX);
    int x2 = floor(sqrtX);
    if(x - x2 * x2 < x1 * x1 - x) return x2 * x2;
    else return x1 * x1;
}
float traceLuggage1(int exp1){
    checkExp(exp1);
    int x = findPerfectNumber(exp1);
    float P1;
    if(exp1 >= x){
        P1 = 1;
    }
    else{
        P1 = (((exp1 * 1.0) / x) + 80 * 1.0) / 123;
    }
    return P1;
}
void wayOfFindingLuggage(int &HP1, int &exp1, int &m1, int i){
    float x;
    if(i == 1){
        if(HP1 < 200){
            m1 -= 150;
            checkMoney(m1);
            x = 0.3 * HP1;
            HP1 += ceil(x);
            checkHP(HP1);
            }
        else{
            m1 -= 70;
            checkMoney(m1);
            x = 0.1 * HP1;
            HP1 += ceil(x);
            checkHP(HP1);
        }
    }
    else if( i == 2){
        if(exp1 < 400){
            m1 -= 200;
            checkMoney(m1);
            }
        else{
            m1 -= 120;
            checkMoney(m1);
            }
        x = 0.13 * exp1;
        exp1 += ceil(x);
    }
    else{
        if(exp1 < 300){
            m1 -= 100;
            checkMoney(m1);
        }
        else{
            m1 -= 120;
            checkMoney(m1);
        }
        x = 0.1 * exp1;
        exp1 += ceil(-x);
        checkExp(exp1);
    }
}
float traceLuggage2(int &HP1, int &exp1, int &m1, int e2){
    checkMoney(m1);
    checkExp(exp1);
    checkHP(HP1);
    int j = 1;
    float haflM1 = 0.5 * m1, x;
    if(m1 != 0){
        if(e2 % 2 == 1){
            while(m1 >= haflM1){
                wayOfFindingLuggage(HP1, exp1, m1, 1);
                if(m1 < haflM1) break;
                wayOfFindingLuggage(HP1, exp1, m1, 2);
                if(m1 < haflM1) break;
                wayOfFindingLuggage(HP1, exp1, m1, 3);
                if(m1 < haflM1) break;
            }
        }
        else{
            while(j != 0){
                j--;
                wayOfFindingLuggage(HP1, exp1, m1, 1);
                if(m1 == 0) break;
                wayOfFindingLuggage(HP1, exp1, m1, 2);
                if(m1 == 0) break;
                wayOfFindingLuggage(HP1, exp1, m1, 3);
                if(m1 == 0) break;
            }
        }
    }
    x = 0.17 * HP1;
    HP1 += ceil(-x);
    checkHP(HP1);
    x = 0.17 * exp1;
    exp1 += ceil(x);
    checkExp(exp1);
    return traceLuggage1(exp1);
}
float traceLuggage3(int e2){
    float P[10] = {0.32, 0.47, 0.28, 0.79, 1.0, 0.5, 0.22, 0.83, 0.64, 0.11};
    if(e2 < 10){
        return P[e2];
    }
    else{
        int a = e2 % 10;
        int b = (e2 - a) / 10;
        if(a + b < 10){
            return P[a+b];
        }
        else{
            return P[(a + b) % 10];;
        }
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    checkExp(EXP1);
    checkHP(HP1);
    checkExp(EXP2);
    checkHP(HP2);
    if( (E3 > 99) || (E3 < 0) ) return -99;
    int arrOfTaxi[10][10];
    for(int i = 0; i < 10; i++){ //Khỏi tạo mảng 2 chiều có giá trị là điểm số kỹ năng của taxi
        for(int j = 0; j < 10; j++){
            arrOfTaxi[i][j] = ( (E3 * j) + (i * 2) ) * (i - j);
        }
    }
    int a = haflUnderTriangle(arrOfTaxi, E3);
    int b = haflAboveTriangle(arrOfTaxi, E3);
    int maxLeft = maxOfLeftDiagonal(arrOfTaxi, a, b);
    int maxRight = maxOfRightDiagonal(arrOfTaxi, a, b);
    int max = (maxLeft > maxRight) ? maxLeft : maxRight;
    if( abs(arrOfTaxi[a][b]) > abs(max)) {
        float x = 0.12 * EXP1;
        EXP1 += ceil(-x);
        checkExp(EXP1);
        x = 0.12 * EXP2;
        EXP2 += ceil(-x);
        checkExp(EXP2);
        x = 0.1 * HP1;
        HP1 += ceil(-x);
        checkHP(HP1);
        x = 0.1 * HP2;
        HP2 += ceil(-x);
        checkHP(HP2);
        return arrOfTaxi[a][b] ;
    }
    else{
        float x = 0.12 * EXP1;
        EXP1 += ceil(x);
        checkExp(EXP1);
        x = 0.12 * EXP2;
        EXP2 += ceil(x);
        checkExp(EXP2);
        x = 0.1 * HP1;
        HP1 += ceil(x);
        checkHP(HP1);
        x = 0.1 * HP2;
        HP2 += ceil(x);
        checkHP(HP2);
        return max;
    }
}
int findIndex(int x){
    if(x < 10) return x;
    else{
        int a = x % 10;
        int b = (x - a) / 10;
        if(a + b >= 10) return findIndex(a+b);
        else return (a + b);
    }
}
int haflUnderTriangle(int a[10][10], int e3){
    int count = 0;
    for(int i = 1; i < 10; i++){
        for(int j = 0; j < i; j++){
            if( a[i][j] > (2*e3) ) count ++;
        }
    }
    return findIndex(count);
}
int haflAboveTriangle(int a[10][10], int e3){
    int count = 0;
    for(int j = 1; j < 10; j++){
        for(int i = 0; i < j; i++){
            if( a[i][j] < (-e3) ) count ++;
        }
    }
    return findIndex(count);
}
int maxOfLeftDiagonal(int a[10][10], int x, int y){
    int distRowLast = 9 - x;
    int distColLast = 9 - y;
    int minLast = ((distColLast < distRowLast) ? distColLast : distRowLast);
    int minFirst = ((x < y) ? x : y);
    int max = a[x + minLast][y + minLast];
    for(int i = 1; i <= minLast + minFirst; i++){
        if(max < a[x + minLast - i][y + minLast -i]) max = a[x + minLast - i][y + minLast -i];
    }
    return max;
}
int maxOfRightDiagonal(int a[10][10], int x, int y){
    int minLast = ((9 - x < y) ? 9 - x : y);
    int max = a[x + minLast][y - minLast];
    int minFirst = ((x < 9 - y) ? x : 9 - y);
    for(int i = 1; i <= minFirst + minLast; i++){
        if(max < a[x + minLast - i][y - minLast + i]) max = a[x + minLast - i][y - minLast + i];
    }
    return max;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string stringS = s, stringEmail = email;
    string se = beforeCharAt(stringEmail);
    if(checkChar(stringS) == -1 && checkDuplicateChar(stringS) == 0 && checkDuplicateString(stringS, se) == 0 && checkLength(stringS) == 0) return -10;
    if( checkLength(stringS) != 0) return checkLength(stringS); 
    if(checkDuplicateString(stringS, se) != 0) return checkDuplicateString(stringS, se);
    if(checkDuplicateChar(stringS) != 0) return checkDuplicateChar(stringS);
    if(checkChar(stringS) != 0) return checkChar(stringS);
    return 0;
}
string beforeCharAt(string email){
    string beforeEmail;
    int index;
    for(int i = 0; i < email.size(); i++){
        if(email[i] == '@'){ 
            index = i;
            break;
        }
    }
    beforeEmail = email.substr(0, index); 
    return beforeEmail;
}
int checkLength(string s){
    if(s.size() < 8) return -1;
    if(s.size() > 20) return -2;
    return 0;
}
int checkDuplicateString(string s, string beforeEmail){
    size_t indexDuplicate = s.find(beforeEmail);
    if(indexDuplicate == string :: npos) return 0;
    else return -(300 + indexDuplicate);
}
int checkDuplicateChar(string s){
    for(int i = 0; i < s.size() - 2; i++){
        if(s[i] == s[i + 1] && s[i + 1] == s[i + 2]) return -(400 + i);
    }
    return 0;
}
int checkChar(string s){
    int count = 0, position = -1, j = 1;
    for(int i = 0; i  < s.size(); i++){
        if((s[i] == '#') || (s[i] == '!') || (s[i] == '@') || (s[i] == '$') || (s[i] == '%')){
            count ++;
            continue;
        }
        if( (s[i] != '#') && (s[i] != '!') && (s[i] != '@') && (s[i] != '$') && (s[i] != '%') && ((s[i] < 'a') || (s[i] > 'z')) && ((s[i] < 'A') || (s[i] > 'Z')) && ((s[i] < '0') || (s[i] > '9'))){
            if(j != 0){
                position = i;
                j--;
            }
        } 
    }
    if(count != 0 && position == -1) return -1;
    else if(count == 0) return -5;
    else return position;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string arrayOfPassword[num_pwds];
    int arrayOfFrequency[num_pwds];
    for(int  i = 0; i < num_pwds; i++){
        arrayOfPassword[i] = arr_pwds[i];
    }
    for(int i = 0; i < num_pwds - 1; i++){
        for(int j = i + 1; j < num_pwds; j++){
            if(arrayOfPassword[i] > arrayOfPassword[j]){
                string temp = arrayOfPassword[i];
                arrayOfPassword[i] = arrayOfPassword[j];
                arrayOfPassword[j] = temp;
            }
        }
    }
    //Khởi tạo mảng lưu tần số xuất hiện của các phần tử
    for(int i = 0; i < num_pwds; i++){
        arrayOfFrequency[i] = 1;
    }
    int max = 1, indexMax = 0;
    //Lưu tần số các phần tử vào mảng
    for(int i = 0; i < num_pwds - 1; i++){
        if(arrayOfPassword[i] == arrayOfPassword[i + 1]){
            arrayOfFrequency[i + 1] += arrayOfFrequency[i];
        }
        if(arrayOfFrequency[i + 1] > max){
            max = arrayOfFrequency[i + 1];
            indexMax = i + 1;
        }
    }
    string truePassword = arrayOfPassword[indexMax];
    int count = 0;
    for(int i = 0; i < num_pwds; i++){
        if(arrayOfFrequency[i] == max){
            if(arrayOfPassword[i].size() > truePassword.size()){
                truePassword = arrayOfPassword[i];
            }
        }
    }
    //Tìm giá trị count
    for(int i = 0; i < num_pwds; i++){
        if(arrayOfFrequency[i] == max){
            if(arrayOfPassword[i].size() == truePassword.size()){
                count ++;
            }
        }
    }
    //Lưu các phần tử thỏa điều kiện tần số xuất hiện lớn nhất và có độ dài chuỗi dài nhất
    string arrayOfTruePassword[count];
    int k = 0;
    for(int i = 0; i < num_pwds; i++){
        if(arrayOfFrequency[i] == max){
            if(arrayOfPassword[i].size() == truePassword.size()){
                arrayOfTruePassword[k] = arrayOfPassword[i];
                k++;
            }
        }
    }
    for(int i = 0; i < num_pwds; i++){
        for(int j = 0; j < count; j++){
            if(arr_pwds[i] == arrayOfTruePassword[j]) return i;
        }
    }
    return 0;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////