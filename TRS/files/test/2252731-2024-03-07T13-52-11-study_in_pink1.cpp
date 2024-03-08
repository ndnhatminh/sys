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

// Task 1
int firstMeet(int & exp1, int & exp2, int e1)
{
    //TODO: implement task
    if (e1 < 0 || e1 > 99) {
        return -99;
    } 
    if (exp1 > 600){
        exp1 = 600;
    } else if (exp1 < 0){
        exp1 = 0;
    }
    if (exp2 > 600){
        exp2 = 600;
    } else if (exp2 < 0){
        exp2 = 0;
    }
    int D = e1 * 3 + exp1 * 7;
    
    if (e1<4){
        switch(e1){
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
                exp2 = exp2 + 29 + 45 + 75;
                break;
        }
        if (exp2 > 600){
            exp2 = 600;
        }
        if (D%2==0){
            exp1 += ceil(float(D)/200); //check 
        } else exp1 -= floor(float(D)/100);
    } else {
        if (e1<=19) {
            exp2 += (ceil(float(e1)/4) + 19);
        } else if (e1 <= 49){
            exp2 += (ceil(float(e1)/9) + 21);
        } else if (e1 <= 65){
            exp2 += (ceil(float(e1)/16) + 17);
        } else if (e1 <= 79){
            exp2 += (ceil(float(e1)/4) + 19);
            if (exp2 > 200) exp2 += ceil(float(e1)/9 + 21);
        } else {
            exp2 += (ceil(float(e1)/4) + 19);
            exp2 += (ceil(float(e1)/9) + 21);
            if (exp2 > 400) {
                exp2 += (ceil(float(e1)/16) + 17);
                exp2 += ceil(float(exp2) * 15 / 100);
            }
        }
        exp1 -=e1;
    }
    if (exp1 > 600){
        exp1 = 600;
    } else if (exp1 < 0){
        exp1 = 0;
    }
    if (exp2 > 600){
        exp2 = 600;
    } else if (exp2 < 0){
        exp2 = 0;
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
    //TODO: implement task
    if (E2 < 0 || E2 > 99){
        return -99;
    }
    if (HP1<0) HP1 = 0;
    if (EXP1<0) EXP1 = 0;
    if (HP1>666) HP1 = 666;
    if (EXP1>600) EXP1 = 600; 
    if (M1<0){
        M1 = 0;
    }
    float P1, P2, P3, lastP;
//road 1
    //find nearest perfect square of exp1
    int temp = 0;
    int S = 0;
    do {
        temp++;
        S = temp*temp;
    } while (S <= EXP1);
    if ((temp*temp)-EXP1 < EXP1 - (temp-1)*(temp-1)) {
    } else {
        S = (temp-1)*(temp-1);
    }
    if (EXP1 >= S){
        P1 = 1;
    } else {
        P1 = (float(EXP1)/float(S)+80)/123;
    }
//road 2
    float halfOfTotalAtFirst = ceil(float(M1)/2);
    float paidMoney = 0;
    if (E2%2!=0){
        //E2 is odd
        while (paidMoney <= halfOfTotalAtFirst){
            //grocery store
            if (HP1 < 200){
                HP1 += ceil(float(HP1)*30/100);
                M1 -= 150;
                paidMoney += 150;
            } else {
                HP1 += ceil(float(HP1)*10/100);
                M1 -= 70;
                paidMoney += 70;
            }
            if (HP1>666) HP1 = 666;
            //taxi or carriage
            if (paidMoney > halfOfTotalAtFirst)
            break; 
            if (EXP1 < 400){
                M1 -= 200;
                paidMoney += 200;
                EXP1 += ceil(float(EXP1)*13/100);
            } else {
                M1 -= 120;
                paidMoney += 120;
                EXP1 += ceil(float(EXP1)*13/100);
            }
            
            if (EXP1>600) EXP1 = 600; 
            //homeless
            if (paidMoney > halfOfTotalAtFirst)
            break; 
            if (EXP1 < 300){
                M1 -= 100;
                paidMoney += 100;
            } else {
                M1 -= 120;
                paidMoney += 120;
            }
            EXP1 -= floor(float(EXP1)*10/100);
            if (EXP1<0) EXP1 = 0; 
        }
        HP1 -= floor(float(HP1)*17/100);
        EXP1 += ceil(float(EXP1)*17/100);
        if (HP1<0) HP1 = 0;
        if (EXP1>600) EXP1 = 600; 
    } else {
        //E2 is even
        //grocery store
            if (HP1 < 200 && M1 > 0){
                HP1 += ceil(float(HP1)*30/100);
                M1 -= 150;
                paidMoney += 150;
            } else if (M1 >0){
                HP1 += ceil(float(HP1)*10/100);
                M1 -= 70;
                paidMoney += 70;
            }
            if (HP1>666) HP1 = 666;
            //taxi or carriage
            if (EXP1 < 400 && M1 >0){
                M1 -= 200;
                paidMoney += 200;
                EXP1 += ceil(float(EXP1)*13/100);
            } else if (M1 >0){
                M1 -= 120;
                paidMoney += 120;
                EXP1 += ceil(float(EXP1)*13/100);
            }
            
            if (EXP1>600) EXP1 = 600; 
            //homeless
            if (EXP1 < 300 && M1 >0){
                M1 -= 100;
                paidMoney += 100;
                EXP1 -= floor(float(EXP1)*10/100);
            } else if (M1 >0){
                M1 -= 120;
                paidMoney += 120;
                EXP1 -= floor(float(EXP1)*10/100);
            }
            
            if (EXP1<0) EXP1 = 0; 
            //update hp and exp
            HP1 -= floor(float(HP1)*17/100);
            EXP1 += ceil(float(EXP1)*17/100);
            if (HP1<0) HP1 = 0;
            if (EXP1>600) EXP1 = 600; 
    }
    temp = 0;
    S = 0;
    do {
        temp++;
        S = temp*temp;
    } while (S <= EXP1);
    if ((temp*temp)-EXP1 < EXP1 - (temp-1)*(temp-1)) {
    } else {
        S = (temp-1)*(temp-1);
    }
    if (EXP1 >= S){
        P2 = 1;
    } else {
        P2 = (float(EXP1)/float(S)+80)/123;
    }
    //road 3
    int arrayP[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10) {
        P3 = float(arrayP[E2])/100;
    } else if (E2 < 100){
        temp = E2 / 10 + E2 - (E2/10)*10;
        temp = temp - (temp/10)*10;
        P3 = float(arrayP[temp])/100;
    }
    //after 3 routes
    if (P1 == 1 && P2 == 1 && P3 == 1){
        EXP1 -= floor(float(EXP1)*25/100);
    } else {
        lastP = (P1 + P2 + P3)/3;
        if (lastP < 0.5){
            HP1 -= floor(float(HP1)*15/100);
            EXP1 += ceil(float(EXP1)*15/100);
        } else {
            HP1 -= floor(float(HP1)*10/100);
            EXP1 += ceil(float(EXP1)*20/100);
        }
    }
    if (HP1>666) HP1 = 666;
    if (HP1<0) HP1=0;
    if (EXP1>600) EXP1 = 600; 
    if (EXP1<0) EXP1 = 0;
    if (M1<0){
        M1 = 0;
    }
    return HP1 + EXP1 + M1;
    //return -1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    //TODO: implement task
    if (E3 < 0 || E3>99) return -99;
    int taxiScore, detectiveScore;
    //initialize matrix
    int matrix[10][10];
    int countGreater = 0, countSmaller = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            matrix [i][j] = (E3*j + i*2)*(i - j);
            if (matrix [i][j] > E3*2) countGreater++;
            if (matrix [i][j] < -E3) countSmaller++;
        }
    }
    while (countGreater > 9){
        countGreater = countGreater/100 + countGreater/10 + countGreater - (countGreater/100)*100 - (countGreater/10)*10;
    }
    while (countSmaller > 9){
        countSmaller = countSmaller/100 + countSmaller/10 + countSmaller - (countSmaller/100)*100 - (countSmaller/10)*10;
    }
    taxiScore = matrix [countGreater][countSmaller];
    detectiveScore = matrix [countGreater][countSmaller];
    int temp = countGreater, temp1 = countSmaller;
    // cheo len ben phai
    while (temp >=0 && temp1 >= 0) {
        if (matrix[temp][temp1] > detectiveScore){
            detectiveScore = matrix[temp][temp1];
        }
        temp --;
        temp1 --;
    }
    // cheo len ben trai
    temp = countGreater, temp1 = countSmaller;
    while (temp >=0 && temp1 < 10) {
        if (matrix[temp][temp1] > detectiveScore){
            detectiveScore = matrix[temp][temp1];
        }
        temp --;
        temp1 ++;
    }
    // cheo xuong ben trai
    temp = countGreater, temp1 = countSmaller;
    while (temp <10 && temp1 >= 0) {
        if (matrix[temp][temp1] > detectiveScore){
            detectiveScore = matrix[temp][temp1];
        }
        temp ++;
        temp1 --;
    }
    // cheo xuong ben phai
    temp = countGreater, temp1 = countSmaller;
    while (temp < 10 && temp1 < 10) {
        if (matrix[temp][temp1] > detectiveScore){
            detectiveScore = matrix[temp][temp1];
        }
        temp ++;
        temp1 ++;
    }
    if (detectiveScore < 0) detectiveScore = abs(detectiveScore);
    if (abs(taxiScore) > detectiveScore ){
        //cant catch
        HP1 -= floor(float(HP1)*10/100);
        EXP1 -= floor(float(EXP1)*12/100);
        HP2 -= floor(float(HP2)*10/100);
        EXP2 -= floor(float(EXP2)*12/100);
        if (HP1 < 0 ) HP1 = 0;
        if (HP2 < 0 ) HP2 = 0;
        if (EXP1 < 0 ) EXP1 = 0;
        if (EXP2 < 0 ) EXP2 = 0;
        return taxiScore;
    } else {
        //catch
        HP1 += ceil(float(HP1)*10/100);
        EXP1 += ceil(float(EXP1)*12/100);
        HP2 += ceil(float(HP2)*10/100);
        EXP2 += ceil(float(EXP2)*12/100);
        if (HP1 >666 ) HP1 = 666;
        if (HP2 >666 ) HP2 = 666;
        if (EXP1 >600) EXP1 = 600;
        if (EXP2 > 600 ) EXP2 = 600;
        return detectiveScore;
    }
    return -99;
}

// Task 4
int checkPassword(const char * s, const char * email)
{
    //TODO: implement task
    //email condition: only 1 @ and mail.length max = 100
    if (strlen(s) < 8) //too short fine
        return -1; 
    char se[100];
    int count = 0;
    for (int i = 0; i < strlen(email); i++){
        if (email[i] == '@'){
            break;
        }
        count++;
    }
    strncpy(se, email, count);
    se [count] = '\0';
    
    //password condition: 
    
    // if (strlen(s) < 8) //too short fine
    //     return -1; 

    if (strlen(s) > 20) // too long fine
        return -2;
    if (strlen(se) == 0) return -300;
    const char* check = strstr(s, se);
    if (check != nullptr)  // contain se strstr tra ve 
        return (- (300 +strstr(s,se) - s));
    char tempchar = ' ';
    for (int i = 0; i < strlen(s)-2; i++){// 2 consecutive and identical character
        // if (s[i] == '@' || s[i] == '#' ||s[i] == '%' ||s[i] == '$' ||s[i] == '!' ) {
        //     if (tempchar == ' '){
        //         tempchar = s[i];
        //     } else if(s[i] == tempchar){
        //         return -(400+i);
        //     }
        // }
        if (s[i] == s[i+1]&&s[i] == s[i+2]){
            return -(400+i);
        }
    }

    if (!strstr(s, "@") && !strstr(s, "#") && !strstr(s, "%") && !strstr(s, "$") && !strstr(s, "!") ) // no special characters fine
        return -5;

    for (int i = 0; i < strlen(s); i++){ // left case
        if (s[i]<48 && (s[i] != 33 && s[i] != 35 && s[i] != 36 && s[i] != 37 && s[i] != 38) || s[i] > 122 || s[i] > 57 && s[i] < 64 || s[i] > 90 && s[i] < 97) {
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    // if (arr_pwds[0] == arr_pwds[1]) return 1;
    // return 0;
    //TODO: implement task
    int count[50] ={};
    int max = 0;
    //find max appear of each password: max
    for (int i = 0; i < num_pwds; i++){
        count[i] = 0;
        for (int j = 0; j < num_pwds; j++){
            if (strcmp(arr_pwds[j], arr_pwds[i]) == 0){
                count[i]++;
            }
        }
    }
    for (int i = 0; i < num_pwds; i++){
        if (count[i] > max) max = count[i];
    }
    //max is TRUE already
    const char* correctPassword = nullptr;
    //strcpy(correctPassword, arr_pwds[0]);
    for (int i = 0; i <num_pwds; i++){ // find correctPassword
        if (count[i] == max){
            if (!correctPassword){
                correctPassword = arr_pwds[i];
                //strcpy(correctPassword, arr_pwds[i]);
            } else if (strlen(arr_pwds[i]) > strlen(correctPassword)){
                correctPassword = arr_pwds[i];
                //correctPassword = arr_pwds[i];
            }
        }
    }

    for (int i = 0; i<num_pwds; i++){ //find location
        if (strcmp(arr_pwds[i], correctPassword) == 0 ) return i;
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
void tc_1333()
{
cout << "----- Testcase 333 -----" << endl;

char email[] = "cse2023@hcmut.edu.vn";
char s[] = "Abc12#";
cout << "email: \"" << email << "\", s: \"" << s << "\"\n";

int result = checkPassword(s, email);
cout << "email: \"" << email << "\", s: \"" << s
<< "\", result: " << result << endl;
}
int main(){
    tc_1333();
    return 0;
}