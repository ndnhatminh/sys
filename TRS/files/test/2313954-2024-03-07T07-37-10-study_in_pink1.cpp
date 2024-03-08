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
    // DO NOT MODIFY THIS FUNCTION
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


//Range of HP -> [0, 666]
void limitRangeHP(int &HP, int a, int b)
{
    if (HP < a) HP = a;
    if (HP > b) HP = b;
}

//Range of EXP -> [0, 600]
void limitRangeEXP(int &EXP, int a, int b)
{
    if (EXP < a) EXP = a;
    if (EXP > b) EXP = b;
}

//Range of M -> [0, 3000]
void limitRangeM(int &M, int a, int b)
{
    if (M < a) M = a;
    if (M > b) M = b;
}

//======================================================================= Task 1 =======================================================================//
int firstMeet(int & exp1, int & exp2, int e1) {
    if(e1 < 0 || e1 > 99) return -99;
    limitRangeEXP(exp1, 0, 600);
    limitRangeEXP(exp2, 0, 600);

    // Case 1: e1 -> [0;3]
    if (e1 >= 0 && e1 <= 3){
        // exp2
        if (e1 == 0) {
            exp2 += 29; limitRangeEXP(exp2, 0, 600);
        }
        else if (e1 == 1) {
            exp2 += 45; limitRangeEXP(exp2, 0, 600);
        }
        else if (e1 == 2) {
            exp2 += 75; limitRangeEXP(exp2, 0, 600);
        }
        else {
            exp2 = exp2 + 29 + 45 + 75; limitRangeEXP(exp2, 0, 600);
        }
        // exp1
        int d = e1 * 3 + exp1 * 7;
        if (d % 2 == 0) {
            float x1 = (float)exp1 + (float)d/200;
            exp1 = ceil(x1);
            limitRangeEXP(exp1, 0, 600);
        }
        else {
            float x1 = (float)exp1 - (float)d/100;
            exp1 = ceil(x1); 
            limitRangeEXP(exp1, 0, 600);
        }
    }

    // Case 2: e1 -> [4;99]
    else {
        if (e1 >= 4 && e1 <= 19) {
            float x1 = (float)exp2 + (float)e1/4 + 19;
            exp2 = ceil(x1);
            limitRangeEXP(exp2, 0, 600);
            exp1 -= e1;
            limitRangeEXP(exp1, 0, 600);
        }
        else if (e1 >= 20 && e1 <= 49) {
            float x2 = (float)exp2 + (float)e1/9 + 21;
            exp2 = ceil(x2);
            limitRangeEXP(exp2, 0, 600);
            exp1 -= e1;
            limitRangeEXP(exp1, 0, 600);
        }
        else if (e1 >= 50 && e1 <= 65) {
            float x3 = (float)exp2 + (float)e1/16 + 17;
            exp2 = ceil(x3);
            limitRangeEXP(exp2, 0, 600);
            exp1 -= e1;
            limitRangeEXP(exp1, 0, 600);
        }
        else if (e1 >= 66 && e1 <= 79) {
            float x4 = (float)exp2 + (float)e1/4 + 19;
            exp2 = ceil(x4);
            limitRangeEXP(exp2, 0, 600);
            if (exp2 > 200) {
                float x5 = (float)exp2 + (float)e1/9 + 21;
                exp2 = ceil(x5);
                limitRangeEXP(exp2, 0, 600);
            }
            exp1 -= e1;
            limitRangeEXP(exp1, 0, 600);
            }
        else {
            float x1 = (float)exp2 + (float)e1/4 + 19;
            exp2 = ceil(x1);
            limitRangeEXP(exp2, 0, 600);

            float x2 = (float)exp2 + (float)e1/9 + 21;
            exp2 = ceil(x2);
            limitRangeEXP(exp2, 0, 600);
            
            if (exp2 > 400) {
                float x3 = (float)exp2 + (float)e1/16 + 17;
                exp2 = ceil(x3);
                limitRangeEXP(exp2, 0, 600);

                float x4 = exp2*1.15;
                exp2 = ceil(x4);
                limitRangeEXP(exp2, 0, 600);
            }
            exp1 -= e1;
            limitRangeEXP(exp1, 0, 600);
        }
    }
    return exp1 + exp2;
}
//======================================================================= Task 2 =======================================================================//

//Task 2.1: Function used to find the nearest square number
int squareNumber(int x){
    int s;
    int sqrtx = (int)(sqrt(x));
    
    int diff1 = abs(x - sqrtx * sqrtx); 
    int diff2 = abs(x - (sqrtx + 1) * (sqrtx + 1));
    
    if (diff1 < diff2) return sqrtx * sqrtx;
    else return (sqrtx + 1) * (sqrtx + 1); 
}  

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(E2 < 0 || E2 > 99) return -99;
    limitRangeHP(HP1, 0, 666);
    limitRangeEXP(EXP1, 0, 600);
    limitRangeM(M1, 0, 3000);

    float P1, P2, P3;
    int S, S1, S2;
    
    //Road 1
    S1 = squareNumber(EXP1);
    if (EXP1 >= S1) P1 = 100;
    else P1 = ((float)EXP1/S1 + 80)*100/123;

    //Road 2
    if (M1 == 0) {
        float x = EXP1 * 1.17; EXP1 = ceil(x); limitRangeEXP(EXP1, 0, 600);
        float y = HP1 * 0.83; HP1 = ceil(y); limitRangeHP(HP1, 0, 666);
        
        S = squareNumber(EXP1);
        if (EXP1 >= S) P2 = 100;
        else P2 = ((float)EXP1/S + 80)*100/123;
    }
    //E2: even
    else if (E2 % 2 == 0) {
        while(M1>0) {
        //Event 1:
        if (HP1 < 200) {
            M1 = M1 - 150; limitRangeM(M1, 0, 3000);
            float x = HP1 * 1.3; HP1 = ceil(x); limitRangeHP(HP1, 0, 666);
        }
        else {
            M1 = M1 - 70; limitRangeM(M1, 0, 3000);
            float x = HP1 * 1.1; HP1 = ceil(x); limitRangeHP(HP1, 0, 666);
        }
        if (M1 <= 0) {
            M1 = 0;
            break;
        }
        else {
        //Event 2:
            if (EXP1 < 400) {
                M1 = M1 - 200; limitRangeM(M1, 0, 3000);
                float x = EXP1 * 1.13; EXP1 = ceil(x); limitRangeEXP(EXP1, 0, 600);
            }
            else {
                M1 = M1 - 120; limitRangeM(M1, 0, 3000);
                float x = EXP1 * 1.13; EXP1 = ceil(x); limitRangeEXP(EXP1, 0, 600);
            }
            if (M1 <= 0) {
                M1 = 0;
                break;
            }
            else {
                //Event 3:
                if (EXP1 < 300) {
                    M1 = M1 - 100; limitRangeM(M1, 0, 3000);
                    float x = EXP1 * 0.9; EXP1 = ceil(x); limitRangeEXP(EXP1, 0, 600);
                }
                else {
                    M1 = M1 - 120; limitRangeM(M1, 0, 3000);
                    float x = EXP1 * 0.9; EXP1 = ceil(x); limitRangeEXP(EXP1, 0, 600);
                }
            }
            if (M1 <= 0){
                    M1 = 0;
                    break;
            }
            else break;
            
        }
        }
    float x = EXP1 * 1.17; EXP1 = ceil(x); limitRangeEXP(EXP1, 0, 600);
    float y = HP1 * 0.83; HP1 = ceil(y); limitRangeHP(HP1, 0, 666);

    S1 = squareNumber(EXP1);
    if (EXP1 >= S1) P2 = 100;
    else P2 = ((float)EXP1/S1 + 80)*100/123;
    }    
    //E2: odd
    else {

        int sum = 0;
        double halfM1 = M1 * 0.5; //50% chi phí ban đầu
        int initM1 = M1; //M1 ban đầu

    while (sum <= halfM1) { 
        //Event 1:   
        if (HP1 < 200) {
            M1 = M1 - 150; limitRangeM(M1, 0, 3000);
            float x = HP1 * 1.3; HP1 = ceil(x); limitRangeHP(HP1, 0, 666);
        }
        else {
            M1 = M1 - 70; limitRangeM(M1, 0, 3000);
            float x = HP1 * 1.1; HP1 = ceil(x); limitRangeHP(HP1, 0, 666);
        }
        sum = initM1 - M1;
        if (sum > halfM1) {
            break;
        }
        else {
            //Event 2:
            if (EXP1 < 400) {
                M1 = M1 - 200; limitRangeM(M1, 0, 3000);
                float x = EXP1 * 1.13; EXP1 = ceil(x); limitRangeEXP(EXP1, 0, 600);
            }
            else {
                M1 = M1 - 120; limitRangeM(M1, 0, 3000);
                float x = EXP1 * 1.13; EXP1 = ceil(x); limitRangeEXP(EXP1, 0, 600);
            }
            sum = initM1 - M1;
            if (sum > halfM1) {
            break;
            }
            else {
                //Event 3:
                if (EXP1 < 300) {
                    M1 = M1 - 100; limitRangeM(M1, 0, 3000);
                    float x = EXP1 * 0.9; EXP1 = ceil(x); limitRangeEXP(EXP1, 0, 600);
                }
                else {
                    M1 = M1 - 120; limitRangeM(M1, 0, 3000);
                    float x = EXP1 * 0.9; EXP1 = ceil(x); limitRangeEXP(EXP1, 0, 600);
                }
                sum = initM1 - M1;
            }
        }
    }
    float x = EXP1 * 1.17; EXP1 = ceil(x); limitRangeEXP(EXP1, 0, 600);
    float y = HP1 * 0.83; HP1 = ceil(y); limitRangeHP(HP1, 0, 666);

    S2 = squareNumber(EXP1);
    if (EXP1 >= S2) P2 = 100;
    else P2 = ((float)EXP1/S2 + 80)*100/123;
    }

    //Road 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 >= 0 && E2 <= 9) P3 = P[E2];
    else {
        int sum = (E2 % 10) + (E2 / 10);
        P3 = P[sum % 10];
    }

    float Ptb = (P1 + P2 + P3) / 3;
    if (Ptb == 100) {
        float x = EXP1 * 0.75; EXP1 = ceil(x); limitRangeEXP(EXP1, 0, 600);
    }
    else if (Ptb < 50) {
        float x = EXP1 * 1.15; EXP1 = ceil(x); limitRangeEXP(EXP1, 0, 600);
        float y = HP1 * 0.85; HP1 = ceil(y); limitRangeHP(HP1, 0, 666);
    }
    else{
        float x = EXP1 * 1.2; EXP1 = ceil(x); limitRangeEXP(EXP1, 0, 600);
        float y = HP1 * 0.9; HP1 = ceil(y); limitRangeHP(HP1, 0, 666);
    }
    
    return HP1 + EXP1 + M1;
}

//======================================================================= Task 3 =======================================================================//

// Task 3.1: Reduce 2 digits to 1 digit
int reduce2to1(int x) {
    while((x/10) > 0) {
        x = (x/10) + (x%10);
    }
    return x;
}
// Task 3.2: Find maximum value of two intersecting diagonals
int findMax(int a[][10], int x, int y) {
    int maxValue = a[x][y];

    //Intersection of two diagonals
    //Left diagonal
    for (int k = 1; x + k < 10 && y + k < 10; k++) {
        if (a[x + k][y + k] > maxValue) maxValue = a[x + k][y + k];
    }
    
    for (int k = 1; x - k >= 0 && y - k >= 0; k++) {
        if (a[x - k][y - k] > maxValue) maxValue = a[x - k][y - k];
    }
    
    //Right diagonal
    for (int k = 1; x - k >= 0 && y + k < 10; k++) {
        if (a[x - k][y + k] > maxValue) maxValue = a[x - k][y + k];
    }
    
    for (int k = 1; x + k < 10 && y - k >= 0; k++) {
        if (a[x + k][y - k] > maxValue) maxValue = a[x + k][y - k];
    }
    return maxValue;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(E3 < 0 || E3 > 99) return -99;
    limitRangeHP(HP1, 0, 666);
    limitRangeHP(HP2, 0, 666);
    limitRangeEXP(EXP1, 0, 600);
    limitRangeEXP(EXP2, 0, 600);
    

    int taxiPoint;
    int sherlockPoint;
    
    //Matrix 10x10
    int a[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            a[i][j] = ((E3*j) + (i*2))*(i-j);
        }
    }

    int countPos = 0;
    int countNeg = 0;   

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (a[i][j] > 0 && a[i][j] > (E3*2)) countPos++;
            if (a[i][j] < 0 && a[i][j] < (-E3)) countNeg++;
        }
    }
    
    int m = reduce2to1(countPos);
    int n = reduce2to1(countNeg);

    taxiPoint = a[m][n];
    sherlockPoint = findMax(a, m, n);
    
    if(abs(taxiPoint) > sherlockPoint) {
        float x1 = EXP1*0.88; EXP1 = ceil(x1); limitRangeEXP(EXP1, 0, 600);
        float x2 = HP1*0.9; HP1 = ceil(x2); limitRangeHP(HP1, 0, 666); 
        float x3 = EXP2*0.88; EXP2 = ceil(x3); limitRangeEXP(EXP2, 0, 600);
        float x4 = HP2*0.9; HP2 = ceil(x4); limitRangeHP(HP2, 0, 666);    
        return taxiPoint;
    }
    else {
        float x1 = EXP1*1.12; EXP1 = ceil(x1); limitRangeEXP(EXP1, 0, 600);
        float x2 = HP1*1.1; HP1 = ceil(x2); limitRangeHP(HP1, 0, 666); 
        float x3 = EXP2*1.12; EXP2 = ceil(x3); limitRangeEXP(EXP2, 0, 600);
        float x4 = HP2*1.1; HP2 = ceil(x4); limitRangeHP(HP2, 0, 666); 
        return sherlockPoint;
    }
    return -1;
}

//======================================================================= Task 4 =======================================================================//
int checkPassword(const char * s, const char * email) {
    string se(email, strchr((email), '@') - email);
    //strchr((email), '@') - email: [0; @ - 1]
    //se = gmail - "@...";

    if (strlen(s) < 8) {
        return -1; 
    }
    else if (strlen(s) > 20) {
        return -2; 
    }

    //Checks se
    //strlen() --> size_t --> size_t = i để phù hợp
    for (size_t i = 0; i < strlen(s); ++i) {
        if (strncmp(s + i, se.c_str(), se.length()) == 0) {
        return -(300 + i); // Chứa chuỗi se
        }
    }
    //so sánh se.length() ký tự đầu tiên của chuỗi s bắt đầu từ vị trí i với chuỗi se
    //Vì s ở đây là một mảng ký tự, nên để so sánh một phần của nó với một chuỗi từ std::string (se), ta cần sử dụng c_str() để lấy con trỏ c-style của se.

    //Checks for 2 consecutive characters
    for (size_t i = 0; i < strlen(s); ++i) {
        if (s[i] == s[i - 1] && s[i] == s[i - 2]) {
            return -(400 + (i-2)); 
        }
    }

    //Check special characters
    const char specialCharacters[] = {'@', '#', '%', '$', '!'};
    bool hasSpecialCharacter = false;
    for (size_t i = 0; i < strlen(s); ++i)
    {
        for (char special_char : specialCharacters)
        {
            if (s[i] == special_char)
            {
                hasSpecialCharacter = true;
                break;
            }
        }
    }
    if (!hasSpecialCharacter) return -5;

    // Check each character in the password
    for (int i = 0; i < strlen(s); i++) {
        if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || 
            (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '@' || s[i] == '!' || s[i] == '#' ||
            s[i] == '$' || s[i] == '%')) {
            return i; 
        }
    }
    return -10; //Valid password
}

//======================================================================= Task 5 =======================================================================//
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxOccurrence = 0; //Maximum number of occurrences of a password
    int maxLength = 0; //Maximum length of a password
    int correctPasswordLocation = -1; //Location of the correct password

    for (int i = 0; i < num_pwds; i++) {
        const char *currentPassword = arr_pwds[i]; //Get the address of the current password by pointer
        int currentLength = strlen(currentPassword); //Length of current password

        //Check the number of occurrences of the current password
        int currentOccurrence = 1;
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(currentPassword, arr_pwds[j]) == 0) {
                currentOccurrence++;
            }
        }

        //If the number of occurrences is greater or equal and the length is greater, then the password is correct
        if ((currentOccurrence > maxOccurrence) || (currentOccurrence == maxOccurrence && currentLength > maxLength)) {
            maxOccurrence = currentOccurrence;
            maxLength = currentLength;
            correctPasswordLocation = i;
        }
    }

    return correctPasswordLocation;
}



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////