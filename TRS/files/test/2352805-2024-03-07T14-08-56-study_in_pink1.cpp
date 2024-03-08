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
// Additinal Function
void resetEXP1(int &EXP1){
    if (EXP1 < 0)
        EXP1 = 0;
    if (EXP1 > 600)
        EXP1 = 600;
}
void resetEXP2(int &EXP2){
    if (EXP2 < 0)
        EXP2 = 0;
    if (EXP2 > 600)
        EXP2 = 600;
}
void resetHP1(int &HP1){
    if (HP1 < 0)
        HP1 = 0;
    if (HP1 > 666)
        HP1 = 666;
}
void resetHP2(int &HP2){
    if (HP2 < 0)
        HP2 = 0;
    if (HP2 > 666)
        HP2 = 666;
}
void resetM2(int &M2){
    if (M2 < 0)
        M2 = 0;
    if (M2 > 3000)
        M2 = 3000;
}
void resetM1(int &M1){
    if (M1 < 0)
        M1 = 0;
    if (M1 > 3000)
        M1 = 3000;
}


// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    if ((E1 < 0) || (E1 > 99)){
        return -99;
    }
    resetEXP1(EXP1);
    resetEXP2(EXP2);
    if ((E1 > -1) && (E1 < 4)){
        switch(E1){
            case 0:
                EXP2 += 29;
                resetEXP2(EXP2);
                break;
            case 1:
                EXP2 += 45;
                resetEXP2(EXP2);
                break;
            case 2:
                EXP2 += 75;
                resetEXP2(EXP2);
                break;
            case 3:
                EXP2 = EXP2 + 29 + 45 + 75;
                resetEXP2(EXP2);
                break;
        }
        if ((E1*3 + EXP1*7) % 2 == 0 ){
            EXP1 = ceil(float(EXP1 + (E1*3 + EXP1*7) / 200.0));
            resetEXP1(EXP1);
        } else {
            EXP1 = ceil(float(EXP1 - (E1*3 + EXP1*7) / 100.0));
            resetEXP1(EXP1);
        }
    }
    
    if ((E1 > 3) && (E1 < 100)){ // [4,99]
        if ((E1 > 3) && (E1 < 20)){ // [4,19]
            EXP2 += ceil(float(E1 / 4.0 + 19));
            resetEXP2(EXP2);
        } else if ((E1 > 19) && (E1 < 50)){// [20,49]
            EXP2 += ceil(float(E1 / 9.0 + 21));
            resetEXP2(EXP2);
        } else if ((E1 > 49) && (E1 < 66)){// [50,65]
            EXP2 += ceil(float(E1 / 16.0 + 17));
            resetEXP2(EXP2);
        } else if ((E1 > 65) && (E1 < 80)){// [66,79]
            EXP2 += ceil(float(E1 / 4.0 + 19));
            resetEXP2(EXP2);
            if (EXP2 > 200){
                EXP2 += ceil(float(E1 / 9.0 + 21));
                resetEXP2(EXP2);
            }
        } else {
            EXP2 += ceil(float(E1 / 4.0 + 19));
            resetEXP2(EXP2);
            EXP2 += ceil(float(E1 / 9.0 + 21));
            resetEXP2(EXP2);
            if (EXP2 > 400){
                EXP2 += ceil(float(E1 / 16.0 + 17));
                resetEXP2(EXP2);
                EXP2 = ceil(float(EXP2 * 1.15));
                resetEXP2(EXP2);
            }
        }
        EXP1 -= E1;
        resetEXP1(EXP1);
    }   
    return EXP1 + EXP2;
}

// Task 2
void recovery(int &HP1, int &M1){
        // Recovery
    if (HP1 < 200){
        HP1 = ceil(float(HP1*1.3));
        resetHP1(HP1);
        M1 -= 150;
        resetM1(M1);
    } else {
        HP1 = ceil(float(HP1*1.1));
        resetHP1(HP1);
        M1 -= 70;
        resetM1(M1);
    }
}
void transportation(int &HP1, int &M1, int &EXP1){
        // Transportation
    if (EXP1 < 400){
        M1 -= 200;
        resetM1(M1);
    } else {
        M1 -= 120;
        resetM1(M1);
    }
    EXP1 = ceil(float(EXP1*1.13));
    resetEXP1(EXP1);
}
void thebegger(int &HP1, int &M1, int &EXP1){
    // The begger
        if (EXP1 < 300){
        M1 -= 100;
        resetM1(M1);
    } else {
        M1 -= 120;
        resetM1(M1);
    }
    EXP1 = ceil(float(EXP1*0.9));
    resetEXP1(EXP1);
}
int getNearestSquare(int n){
    int a = sqrt(n);
    if ((n - a*a) > ((a+1)*(a+1) - n))
        return (a+1)*(a+1);
    else 
        return a*a;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if ((E2 < 0) || (E2 > 99)){
        return -99;
    } 
    resetEXP1(EXP1);
    resetHP1(HP1);
    resetM1(M1);

    double P1, P2, P3;
    
    // The first road
    int S1 = getNearestSquare(EXP1);
    if (EXP1 >= S1)
        P1 = 1;
    else 
        P1 =  (EXP1/(S1*1.0) + 80) / 123.0;

    // The second road
    if ((E2 % 2) != 0){
        int check = ceil(float(M1 / 2.0));
        while (1){
            if (M1 >= check)
                recovery(HP1, M1);
            else
                break;
            if (M1 >= check)
                transportation(HP1, M1, EXP1);
            else 
                break;
            if (M1 >= check)
                thebegger(HP1, M1, EXP1);
            else
                break;
        }
        HP1 = ceil(float(HP1*0.83));
        resetHP1(HP1);
        EXP1 = ceil(float(EXP1*1.17));
        resetEXP1(EXP1);
    } else {
        if (M1 != 0)
            recovery(HP1, M1);
        if (M1 != 0)
            transportation(HP1, M1, EXP1);
        if (M1 != 0)
            thebegger(HP1, M1, EXP1);
        HP1 = ceil(float(HP1*0.83));
        resetHP1(HP1);
        EXP1 = ceil(float(EXP1*1.17));
        resetEXP1(EXP1);
    }
    int S2 = getNearestSquare(EXP1);
    if (EXP1 >= S2)
        P2 = 1;
    else 
        P2 =  (EXP1 / (S2*1.0) + 80) / 123.0;
    // The third road
    
    double P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    
    P3 = P[(E2 % 10 + (E2 - E2 % 10 ) / 10) % 10] / 100;
        
    if ((P1 == 1) && (P2 == 1) && (P3 == 1)){
        EXP1 = ceil(float(EXP1 * 0.75));
        resetEXP1(EXP1);
    } else {
        double average = (P1 + P2 + P3)/3;
        if (average < 0.5){
            HP1 = ceil(float(HP1*0.85));
            resetHP1(HP1);           
            EXP1 = ceil(float(EXP1 * 1.15));
            resetEXP1(EXP1);
        } else {
            HP1 = ceil(float(HP1*0.9));
            resetHP1(HP1);           
            EXP1 = ceil(float(EXP1 * 1.2));
            resetEXP1(EXP1);   
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int absolute(int n){
    if (n < 0)
        return -n;
    else 
        return n;
}
void simple(int &n){
    while (n > 9)
        n = n % 10 + (n - n % 10 ) / 10;
}
int getLeftDiagnoal(int i, int j, int A[][10]){
    int iTemp = i, jTemp = j, max = A[i][j];
    while ((i > -1) && (i < 10) && (j > -1) && (j < 10)){
        if (A[i][j] > max)
            max = A[i][j];
        i++; j--;
    }
    while ((iTemp > -1) && (iTemp < 10) && (jTemp > -1) && (jTemp < 10)){
        if (A[iTemp][jTemp] > max)
            max = A[iTemp][jTemp];
        iTemp--; jTemp++;
    }    
    return max;
}
int getRightDiagnoal(int i, int j, int A[][10]){
    int iTemp = i, jTemp = j, max = A[i][j];
    while (((i > -1) && (i < 10)) && ((j > -1) && (j < 10))){
        if (A[i][j] > max)
            max = A[i][j];
        i++; j++;
    }
    while (((iTemp > -1) && (iTemp < 10)) && ((jTemp > -1) && (jTemp < 10))){
        if (A[iTemp][jTemp] > max)
            max = A[iTemp][jTemp];
        iTemp--; jTemp--;
    }    
    return max;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ((E3 < 0) || (E3 > 99)){
        return -99;
    } 
    resetEXP1(EXP1);
    resetEXP2(EXP2);
    resetHP1(HP1);
    resetHP2(HP2);
    int T[10][10], iMeet = 0, jMeet = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            T[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (T[i][j] > E3*2)
                iMeet++;
            if (T[i][j] < -E3)
                jMeet++;           
        }
    }
    simple(iMeet); simple(jMeet);
    int left = getLeftDiagnoal(iMeet, jMeet, T);
    int right = getRightDiagnoal(iMeet, jMeet, T);
    int WSpoint = (left < right) ? right : left;
    if (absolute(T[iMeet][jMeet]) > WSpoint){
        EXP1 = ceil(float(EXP1 * 0.88));
        resetEXP1(EXP1);
        EXP2 = ceil(float(EXP2 * 0.88));
        resetEXP2(EXP2);
        HP1 = ceil(float(HP1 * 0.9));
        resetHP1(HP1);
        HP2 = ceil(float(HP2 * 0.9));
        resetHP2(HP2);
    } else {
        EXP1 = ceil(float(EXP1 * 1.12));
        resetEXP1(EXP1);
        EXP2 = ceil(float(EXP2 * 1.12));
        resetEXP2(EXP2);
        HP1 = ceil(float(HP1 * 1.1));
        resetHP1(HP1);
        HP2 = ceil(float(HP2 * 1.1));
        resetHP2(HP2);
    }
    return (WSpoint >= absolute(T[iMeet][jMeet])) ? WSpoint : T[iMeet][jMeet];
}

// Task 4
// bool compareSE(string se, string temp1, int i){
//     if ((temp1[i] == se[0]) && (temp1.length() - i) >= se.length()){
//         int check = 1;
//         bool compare = 1;
//         while (check < se.length()){
//             if (temp1[i+check] != se[check]){
//                 compare = 0;
//                 break;
//             }
//             else 
//                 check++;
//         }
//         if (compare){
//             return 1;
//         } else
//             return 0;
//     } else 
//         return 0;
// }
// bool specialCharCheck(char n){
//     if ((n == '@') || (n == '#') ||
//     (n == '%') || (n == '$') || (n == '!'))
//         return 1;
//     else 
//         return 0;
// }
// bool repeatChar(string temp1, int i){
//     if (i > temp1.length() - 2)
//         return 0;
//     else 
//         return ((temp1[i+1] == temp1[i]) && (temp1[i] == temp1[i+2])) ? 1:0; 
// }
// int checkPassword(const char * s, const char * email) {
//     // TODO: Complete this function
//     // Create variable stored ìnformation 
//     string temp1 = s, temp2 = email;
//     int length = temp1.length();
//     int Passcheck = -10, mark;
//     bool specialChar = 0, seiCheck = 0, sciCheck = 0, otherCheck = 0;
//     int sei, sci, othercase ;
//     for(int i = 0; i < temp2.length(); i++){
//         if (temp2[i] == '@'){
//             mark = i;
//             break;
//         }
//     }
//     string se = temp2.substr(0,mark);

//     // Checking the range of password
//     if (length < 8)
//         return -1;
//     else if (length > 20) 
//         return -2;
//     // Checking the other demand.
//     else {
//         for (int i = 0; i < temp1.length(); i++){

//             // Checking for whether containing the special characters or not.
//             if (specialCharCheck(temp1[i]))
//                 specialChar = 1;
//             // Checking for the requỉred characters in the password.
//             if ( ((temp1[i] >= '0') && (temp1[i] <= '9')) || 
//                  ((temp1[i] >= 'a') && (temp1[i] <= 'z')) || 
//                  ((temp1[i] >= 'A') && (temp1[i] <= 'Z')) || 
//                  specialCharCheck(temp1[i]) || otherCheck ) {
//                 Passcheck = -10;
//             } else {
//                 othercase = i;
//                 otherCheck = 1;
//             }

//             // Checking for containing the string se and repeated characters.
//             if (se == ""){
//                 sei = 0;
//                 seiCheck = 1;
//             }
//             if (compareSE(se, temp1, i) && !seiCheck){
//                 sei = i;
//                 seiCheck = 1;                   
//             }
//             if (repeatChar(temp1, i) && !sciCheck){
//                 sci = i;
//                 sciCheck = 1;
//             }
                
//         }
//     }
//     if (seiCheck){
//         return -(300+sei);
//     }
//     if (sciCheck){
//         return -(400+sci);
//     }
//     if (!specialChar)
//         return -5;
//     if (otherCheck){
//         return othercase;
//     }
//     else 
//         return Passcheck;
// }
int checkPassword(const char * s, const char * email)
{
    //TODO: implement task
    //email condition: only 1 @ and mail.length max = 100
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
    // string temp1 = s;
    if (strlen(s) < 8) //too short fine
        return -1; 
    // if (temp1.length() < 8) //too short fine
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
bool repeatCheck(string* ptr, string member, int freqCount){
    bool checking = 0;
    if (ptr == nullptr){
        return 0;
    }
    for (int i = 0; i< freqCount; i++){
        if (member != *(ptr+i))
            continue;
        else
            checking = 1;
            break;
    }
    return checking;
}
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string *ptr = new string[num_pwds];
    
    string check, temp;
    int freqMax = 0, freqCount = 0, result = 0;

    for (int i = 0; i < num_pwds; i++) {
        if (!repeatCheck(ptr, *(arr_pwds+i),freqCount)){
            check = *(arr_pwds+i);
            *(ptr+freqCount) = *(arr_pwds+i);
            freqCount++;
        } else 
            continue;
        int count = 0;
        for (int j = i; j < num_pwds; j++){
            if (*(arr_pwds+j) == check) {
                count++;
            }
        }
        if (count > freqMax){
            freqMax = count;
            temp = check;
            result = i;
        }
        if ((count == freqMax) && (check.length() > temp.length())){
            temp = check;
            result = i;
        }
    }
    return result;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////