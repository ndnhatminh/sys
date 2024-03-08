#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & e1,
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
            >> e1 >> E2 >> E3;
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
    // TODO: Complete this function
        if (e1 < 0 || e1 > 99) return -99;
        else if (e1 >= 0 && e1  <= 3){
        if (e1 == 0 ) exp2 += 29;
        else if (e1 == 1) exp2 += 45;
        else if (e1 == 2) exp2 += 75;
        else exp2 = exp2 + 29 + 45 +75;

        int D = e1*3 + exp1*7;
        if (D%2 == 1) exp1 = ceil(exp1 - D*1.0/100);
        else exp1 = ceil(exp1 +  D*1.0/200);

        if (exp1 > 600) exp1 = 600;
        if (exp1 < 0) exp1 = 0;
        if (exp2 > 600) exp2 = 600;
        if (exp2 < 0) exp2 = 0;
    }
    else {
        if (e1>=4 && e1<=19) exp2 = ceil( exp2 + (e1*1.0/4 + 19) );
        else if (e1 <= 49) exp2 = ceil( exp2 + (e1*1.0/9 + 21) );
        else if (e1 <= 65) exp2 = ceil( exp2 + (e1*1.0/16 + 17) );
        else if (e1 <= 79) {
            exp2 = ceil ( exp2 + (e1*1.0/4 + 19) );
            if (exp2 > 200) exp2 = ceil ( exp2 + (e1*1.0/9 + 21) );
        }
        else{
            exp2 = ceil (exp2 + (e1*1.0/4 + 19));
            exp2 = ceil (exp2 + (e1*1.0/9 + 21));
            if (exp2 > 400 ){ 
                exp2 = ceil (exp2 + (e1*1.0/16 + 17) );
                exp2 = ceil ( exp2 + exp2*15.0/100 );
            }
        }
        exp1 -= e1 ;
        if (exp1 > 600) exp1 = 600;
        if (exp1 < 0) exp1 = 0;
        if (exp2 > 600) exp2 = 600;
        if (exp2 < 0) exp2 = 0;
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
        if (E2 > 99 || E2 < 0) return -99;

    int S = 0;
    float P1;
    S = int(sqrt(EXP1));
    if (EXP1 - S*S < (S+1)*(S+1) - EXP1 ) P1 = 1;
    else P1 = (EXP1*1.0/((S+1)*(S+1)) + 80)/123;

    float M0 = M1*0.5;
    if(E2%2 == 1){
        while (M1 >= M0 && M1 != 0){
            if (HP1 < 200 ){
                HP1 = ceil(HP1*130.0/100);
                M1 -= 150;
            }
            else{
                HP1 = ceil(HP1*110.0/100);
                M1 -= 70;
            }
            if (EXP1 < 0) EXP1 = 0;
            if (EXP1 > 600) EXP1 = 600;
            if (HP1 < 0) HP1 = 0;
            if (HP1 > 666) HP1 = 666;
            if (M1 < 0) M1 = 0;
            if (M1 > 3000) M1 = 3000;
            if (M1 < M0) break;

            if(EXP1 < 400){
                M1 -= 200;
                EXP1 = ceil(EXP1*113.0/100);
            }
            else {
                M1 -= 120;
                EXP1 = ceil(EXP1*113.0/100);
            }
            if (EXP1 < 0) EXP1 = 0;
            if (EXP1 > 600) EXP1 = 600;
            if (HP1 < 0) HP1 = 0;
            if (HP1 > 666) HP1 = 666;
            if (M1 < 0) M1 = 0;
            if (M1 > 3000) M1 = 3000;
            if(M1 < M0) break;

            if (EXP1 < 300){
                M1 -= 100;
                EXP1 = ceil(EXP1*90.0/100);
            }
            else {
                M1 -= 120;
                EXP1 = ceil(EXP1*90.0/100);
            if (EXP1 < 0) EXP1 = 0;
            if (EXP1 > 600) EXP1 = 600;
            if (HP1 < 0) HP1 = 0;
            if (HP1 > 666) HP1 = 666;
            if (M1 < 0) M1 = 0;
            if (M1 > 3000) M1 = 3000;
            }

        }
            HP1 = ceil(HP1*83.0/100);
            EXP1 = ceil(EXP1*117.0/100);
            if (EXP1 < 0) EXP1 = 0;
            if (EXP1 > 600) EXP1 = 600;
            if (HP1 < 0) HP1 = 0;
            if (HP1 > 666) HP1 = 666;
            if (M1 < 0) M1 = 0;
            if (M1 > 3000) M1 = 3000;
    }
    else {
        if(M1 != 0){
            do{
                if (HP1 < 200 ){
                    HP1 = ceil(HP1*130.0/100);
                    M1 -= 150;
                }
                else{
                    HP1 = ceil(HP1*110.0/100);
                    M1 -= 70;
                }
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
                if (M1 < 0) M1 = 0;
                if (M1 > 3000) M1 = 3000;
                if(M1 <= 0) break;

                if(EXP1 < 400){
                    M1 -= 200;
                    EXP1 = ceil(EXP1*113.0/100);
                }
                else {
                    M1 -= 120;
                    EXP1 = ceil(EXP1*113.0/100);
                }
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
                if (M1 < 0) M1 = 0;
                if (M1 > 3000) M1 = 3000;
                if(M1 <= 0) break; 

                if (EXP1 < 300){
                    M1 -= 100;
                    EXP1 = ceil(EXP1*90.0/100);
                }
                else {
                    M1 -= 120;
                    EXP1 = ceil(EXP1*90.0/100);
                }
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
                if (M1 < 0) M1 = 0;
                if (M1 > 3000) M1 = 3000;
            }while(false);
        }
        HP1 = ceil(HP1*83.0/100);
        EXP1 = ceil(EXP1*117.0/100);
    }

    float P2;
    S = int(sqrt(EXP1));
    if (EXP1 - S*S < (S+1)*(S+1) - EXP1 ) P2 = 1;
    else P2 = (EXP1*1.0/((S+1)*(S+1)) + 80)/123;

    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float P3;
    if (E2 < 10) P3 = P[E2]*1.0/100;
    else{
        int i = E2/10 + E2%10;
        if (i>=10) P3 = P[i%10]*1.0/100;
        else P3 = P[i]*1.0/100;
    }
    if (P1 == 1 && P2 == 1 && P3 == 1) EXP1 = ceil(EXP1*75.0/100);
    else {
        if ((P1 + P2 + P3)/3 < 0.5){
            HP1 = ceil(HP1*85.0/100);
            EXP1 = ceil(EXP1*115.0/100);
        }
        else{
            HP1 = ceil(HP1*90.0/100);
            EXP1 = ceil(EXP1*120.0/100);
        }
    }
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (M1 < 0) M1 = 0;
    if (M1 > 3000) M1 = 3000;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
        if(E3 < 0 || E3 > 99) return -99;
    int arr[10][10] = {0};
    int big = 0, small = 0, posI, posJ;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            arr[i][j] = ((E3*j)+(i*2))*(i-j);
            if(arr[i][j] > E3*2) big++;
            else if(arr[i][j] < -E3) small++;
        } 
    }

    if(big <= 9) posI = big;
    else{
        big = int(big/10) + big%10;
        if(big <= 9) posI = big;
        else{
            big = int(big/10) + big%10;
            posI = big;
        }
    }
    if(small <= 9) posJ = small;
    else{
        small = int(small/10) + small%10;
        if(small <= 9) posJ = small;
        else{
            small = int(small/10) + small%10;
            posJ = small;
        }
    }

    int grade = arr[posI][posJ];
    for(int k = 0; k < 9; k++){
        posI++;
        posJ--;
        if(posI >= 0 && posI <=9 && posJ >=0 && posJ <=9){
            if(arr[posI][posJ] > grade) grade = arr[posI][posJ];       
        }
        else break;
    }
    for(int l = 0; l < 9; l++){
        posI++;
        posJ++;
        if(posI >= 0 && posI <=9 && posJ >=0 && posJ <=9){
            if(arr[posI][posJ] > grade) grade = arr[posI][posJ];       
        }
        else break;
    }
    for(int m = 0; m < 9; m++){
        posI--;
        posJ++;
        if(posI >=0 && posI <=9 && posJ >=0 && posJ <=9){
            if(arr[posI][posJ] > grade) grade = arr[posI][posJ];
        }
        else break;      
    }
    for(int n = 0; n < 9; n++){
        posI--;
        posJ--;
        if(posI >=0 && posI <=9 && posJ >=0 && posJ <=9){
            if(arr[posI][posJ] > grade) grade = arr[posI][posJ];
        }
        else break;      
    }    

    if(abs(arr[big][small]) <= grade){
        EXP1 = ceil(EXP1*11.2/10);
        HP1 = ceil(HP1*11.0/10);
        EXP2 = ceil(EXP2*11.2/10);
        HP2 = ceil(HP2*11.0/10);
    }
    else{
        EXP1 = ceil(EXP1*0.88);
        HP1 = ceil(HP1*0.9);
        EXP2 = ceil(EXP2*0.88);
        HP2 = ceil(HP2*0.9);
        grade = arr[big][small];
    }
    if(HP1 > 666) HP1 = 666;
    if(HP2 > 666) HP2 = 666;
    if(EXP1 > 600) EXP1 = 600;
    if(EXP2 > 600) EXP2 = 600;
    if(HP1 < 0) HP1 = 0;
    if(HP2 < 0) HP2 = 0;
    if(EXP1 < 0) EXP1 = 0;
    if(EXP2 < 0) EXP2 = 0;

    return grade;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    char se[101];
    for (int i = 0; email[i] != '\0'; i++){
        if (email[i] != '@') se[i] = email[i];
        else{
            se[i] = '\0';
            break;
        }    
    }

    int check = 0;
    if (strlen(s) < 8) return -1;
    else if (strlen(s) > 20) return -2;
    else{
        const char* a = strstr(s,se);
        if(a != nullptr) return  - (300 + (a - s));
        else{
            for (int j = 0;  s[j] != '\0'; j++ ){
                if (s[j] == s[j+1]){
                    if(s[j+1] == s[j+2]){
                    return -(400 + j);
                    break;
                    }
                }
            }
                if(strstr(s,"!") == nullptr && strstr(s,"@") == nullptr && strstr(s,"#") == nullptr && strstr(s,"$") == nullptr && strstr(s,"%") == nullptr)
                return -5;
                for(int k = 0; s[k] != '\0'; k++){
                if(!((s[k] >= 'A' && s[k] <= 'Z')||(s[k] >= 'a' && s[k] <= 'z') || (s[k] >= '0' && s[k] <= '9'))){
                    if (s[k] != '!' && s[k] != '@' && s[k] != '#' && s[k] != '$' && s[k] != '%') return k;
                    }
                }
        return -10;
        }
    }   
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
        int index , lengthMAX = 0, ungcuvien = 0;
    for (int i = 0; i < num_pwds; i++){
        int lengthUngcuvien = strlen(arr_pwds[i]), f = 1;
            for(int j = i + 1; j < num_pwds; j++){
                if(strcmp(arr_pwds[i], arr_pwds[j]) == 0) f++;
            }
            if( f > ungcuvien){
                ungcuvien = f;
                lengthMAX = lengthUngcuvien;
                index = i;
            }
            else if ( f == ungcuvien){
                if(lengthUngcuvien>lengthMAX){
                    lengthMAX = lengthUngcuvien;
                    index = i;
                }
            }
    }
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////