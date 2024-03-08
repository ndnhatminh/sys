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
void clampHP(int &hp)
{
    if (hp > 666) hp = 666;
    else if (hp < 0) hp = 0;
    else return;
}
void clampEXP(int & exp)
{
    if (exp > 600) exp = 600;
    else if (exp < 0) exp = 0;
    else return;
}
void clampM(int & m)
{
    if (m > 3000) m = 3000;
    else if (m < 0) m = 0;
    else return;
} 
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1<0 || e1>99) return -99;
    clampEXP(exp1);
    clampEXP(exp2);
    // Case E1 : [0,3]
    if (e1>=0 && e1<=3)
    { 
        if (e1 == 0)
        {
            exp2 += 29;
            clampEXP(exp2);
        }
        else if (e1 == 1)
        {
            exp2 += 45;
            clampEXP(exp2);
        }
        else if (e1 == 2)
        {
            exp2 += 75;
            clampEXP(exp2);
        }
        else
        {
            exp2 += 149;
            clampEXP(exp2);
        }
        int D;
        D = e1*3 + exp1*7;
        if (D%2 == 0)
        {
            exp1 = ceil(exp1 + D/200.0);
            clampEXP(exp1);
        }
        else
        {
            exp1 = ceil(exp1-D/100.0);
            clampEXP(exp1);
        }
    }

    // Case E1: [4,99]
    else
    {
        if (e1>=4 && e1<=19)
        {
            exp2 += ceil(e1/4.0 + 19);
            clampEXP(exp2);
        }
        else if (e1>=20 && e1<=49)
        {
            exp2 += ceil(e1/9.0 + 21);
            clampEXP(exp2);
        }
        else if (e1>=50 && e1<=65)
        {
            exp2 += ceil(e1/16.0 + 17);
            clampEXP(exp2);
        }
        else if (e1>=66 && e1<=79)
        {
            exp2 += ceil(e1/4.0 + 19);
            clampEXP(exp2);
            if (exp2 > 200)
            {
                exp2 += ceil(e1/9.0 + 21);
                clampEXP(exp2);
            }
        }
        else if (e1>=80 && e1<=99)
        {
            exp2 += ceil(e1/4.0 + 19);
            clampEXP(exp2);
            exp2 += ceil(e1/9.0 + 21);
            clampEXP(exp2);
            if (exp2 > 400)
            {
                exp2 += ceil(e1/16.0 + 17);
                clampEXP(exp2);
                exp2 = ceil(exp2*115/100.0);
                clampEXP(exp2);
            }
        }
        exp1 -= e1;
        clampEXP(exp1);
    }

    return exp1 + exp2;
}

// Task 2
int findSquareNum(int num){
    int S;
    S = round(sqrt(num));
    return pow(S,2);
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2<0 || E2>99) return -99;
    clampHP(HP1);
    clampEXP(EXP1);
    clampM(M1);
    //Street 1
    int S;
    float P1,P2,P3,P;
    S = findSquareNum(EXP1);
    if (EXP1 >= S) P1 = 1.0;
    else
    {
        P1 = (EXP1/S + 80)/123.0;
    }

    //Street 2
    float limitM; // < M1/2
    float usedM = 0.0;
    limitM = M1*0.5;
    if (E2%2 != 0)
    {
        while ((usedM < limitM))
        {
            // Event 1
            if (HP1 < 200)
            {
                HP1 = ceil(HP1*130/100.0);
                clampHP(HP1);
                M1 -= 150;
                usedM += 150;
                clampM(M1);
            } 
            else 
            {
                HP1 = ceil(HP1*110/100.0);
                clampHP(HP1);
                M1 -= 70;
                usedM += 70;
                clampM(M1);
            }
            // Event 2
            if (usedM <= limitM)
            {
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    usedM += 200;
                    clampM(M1);
                }
                else
                {
                    M1 -= 120;
                    usedM += 120;
                    clampM(M1);
                }
                EXP1 = ceil(EXP1*113/100.0);
                clampEXP(EXP1);
            }
            else break;
            // Event 3
            if (usedM <= limitM)
            {
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    usedM += 100;
                    clampM(M1);
                }
                else
                {
                    M1 -= 120;
                    usedM += 120;
                    clampM(M1);
                }
                EXP1 = ceil(EXP1*90/100.0);
                clampEXP(EXP1);
            }
            else break;
        }
    }
    else if (E2%2==0 && M1>0)
    {
        // Event 1
        if (HP1 < 200)
        {
            HP1 = ceil(HP1*130/100.0);
            clampHP(HP1);
            M1 -= 150;
            clampM(M1);
        } 
        else 
        {
            HP1 = ceil(HP1*110/100.0);
            clampHP(HP1);
            M1 -= 70;
            clampM(M1);
        }
        if (M1 > 0)
        {
            // Event 2
            if (EXP1 < 400)
            {
                M1 -= 200;
                clampM(M1);
            }
            else
            {
                M1 -= 120;
                clampM(M1);
            }
            EXP1 = ceil(EXP1*113/100.0);
            clampEXP(EXP1);
            if (M1 > 0)
            {
                // Event 3
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    clampM(M1);
                }
                else
                {
                    M1 -= 120;
                    clampM(M1);
                }
                EXP1 = ceil(EXP1*90/100.0);
                clampEXP(EXP1);
            }
            else M1 = 0;
        }
        else M1 = 0;
    }
    else;
    HP1 = ceil(HP1*83/100.0);
    EXP1 = ceil(EXP1*117/100.0);
    clampHP(HP1);
    clampEXP(EXP1);
    S = findSquareNum(EXP1);
    if (EXP1 >= S) P2 = 1;
    else
    {
        P2 = (EXP1/S + 80)/123.0;
    }
    
    // Street 3
    int P_array[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10) P3 = P_array[E2]/100.0;
    if (E2>=10 && E2<=99)
    {
        int sumNum = E2/10 + E2%10;
        int unitDigit = sumNum%10;
        P3 = P_array[unitDigit]/100.0;
    }

    //Finish 3 Street
    if (P1==1 && P2==1 && P3==1)
    {
        EXP1 = ceil(EXP1*75/100.0);
        clampEXP(EXP1);
    }
    else 
    {
        P = (P1 + P2 + P3)/3.0;
        if (P < 0.5)
        {
            HP1 = ceil(HP1*85/100.0);
            clampHP(HP1);
            EXP1 = ceil(EXP1*115/100.0);
            clampEXP(EXP1);
        }
        else
        {
            HP1 = ceil(HP1*90/100.0);
            clampHP(HP1);
            EXP1 = ceil(EXP1*120/100.0);
            clampEXP(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
    // Add
    // Max Range is 100
void convertToUnit(int &num)
{
    if (num == 100)
    {
        num = 1;
        return;
    }
    if (num<0) return;
    if (num > 9)
    {
        num = num/10 + num%10;
        if (num > 9) num = num/10 + num%10;
    }
}
int pointSherWatson(int arr[10][10], int row, int col)
{
    int maxRight = arr[row][col];
    int maxLeft = arr[row][col];
    
    // Max Right diagonal
    for (int i = row, j = col; i >= 0 && j < 10; i--, j++) {
        if (maxRight < arr[i][j]) maxRight = arr[i][j];
    }
    for (int i = row, j = col; i < 10 && j >= 0; i++, j--) {
        if (maxRight < arr[i][j]) maxRight = arr[i][j];
    }
    
    // Max Left diagonal
    for (int i = row, j = col; i < 10 && j < 10; i++, j++) {
        if (maxLeft < arr[i][j]) maxLeft = arr[i][j];
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (maxLeft < arr[i][j]) maxLeft = arr[i][j];
    }
    
    return (maxRight > maxLeft) ? maxRight : maxLeft;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3<0 || E3>99) return -99;
    clampHP(HP1);
    clampEXP(EXP1);
    clampHP(HP2);
    clampEXP(EXP2);
    int rowMeet = 0;
    int colMeet = 0;
    int valueMeet;
    int routeTaxi[10][10] = {};
    int routeSAW[10][10]={};
    for (int i = 0 ; i < 10 ; i++)
    {
        for (int j = 0 ; j < 10 ; j++)
        {
            routeTaxi[i][j] = ((E3*j) + (i*2)) * (i-j);
        }
    }
    for (int i = 0 ; i < 10 ; i++)
    {
        for (int j = 0 ; j < 10 ; j++)
        {
            if (routeTaxi[i][j] > (E3*2)) rowMeet++;
            if (routeTaxi[i][j] < -E3) colMeet++;
        }
    }
    convertToUnit(rowMeet);
    convertToUnit(colMeet);
    valueMeet = routeTaxi[rowMeet][colMeet];
    for (int i = 0 ; i < 10 ; i++)
    {
        for (int j = 0 ; j < 10 ; j++)
        {
            routeSAW[i][j] = routeTaxi[i][j];
        }
    }
    for (int j = 0 ; j < 10 ; j++)
    {
        for (int i = 0 ; i < 10 ; i++)
        {
            routeSAW[i][j] = abs(pointSherWatson(routeTaxi,i,j));
        }
    }
    if (abs(valueMeet) > routeSAW[rowMeet][colMeet])
    {
        EXP1 = ceil(EXP1*88/100.0);
        EXP2 = ceil(EXP2*88/100.0);
        HP1 = ceil(HP1*90/100.0);
        HP2 = ceil(HP2*90/100.0);
        clampEXP(EXP1);
        clampEXP(EXP2);
        clampHP(HP1);
        clampHP(HP2);
        return valueMeet;
    }
    else
    {
        EXP1 = ceil(EXP1*112/100.0);
        EXP2 = ceil(EXP2*112/100.0);
        HP1 = ceil(HP1*110/100.0);
        HP2 = ceil(HP2*110/100.0);
        clampEXP(EXP1);
        clampEXP(EXP2);
        clampHP(HP1);
        clampHP(HP2);
        return routeSAW[rowMeet][colMeet];
    }    
    return -1;
}

// Task 4
bool availbleCharacter(char s) 
{
    return ((s >= 48 && s <= 57) || (s >= 65 && s <= 90) || (s >= 97 && s <= 122) || s == '!' || s == '@' || s == '#' || s == '$' || s == '%');
}
bool testHaveSpecialCharacter(const char * string)
{
    for (int i = 0 ; i < strlen(string) ; i++)
    {
        if (string[i]=='@' || string[i]=='#' || string[i]=='$' || string[i]=='%' || string[i]=='!') return true;
    }
    return false;
} 
bool test3ConsecutiveCharacter(const char *string) {
    for (int i = 0; i < (strlen(string) - 2); i++) {
        if (string[i] == string[i + 1] && string[i + 1] == string[i + 2]) {
            return true;
        }
    }
    return false;
}
int indexConsecutiveCharacter(const char * string)
{
    for (int i = 0 ; i < ((strlen(string)-2)) ; i++)
    {
        if (string[i]==string[i+1] && string[i+1]==string[i+2]) return i;
    }
    return -1;
}
int findIndexString(string s, const char *string) {
    const char *foundIndex = strstr(string, s.c_str());
    if (foundIndex != nullptr) {
        return foundIndex - string; // size char = 1
    } else {
        return -1;
    }
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int sizePassword = strlen(s);
    if (sizePassword < 8) return -1;
    if (sizePassword > 20) return -2;
    string se;
    for (int i = 0 ; i < strlen(email) ; i++)
    {
        if (email[i] != '@') {
            se += email[i];
        } else break;
    }
    if (findIndexString(se, s) != -1) 
    {
        return  -(300 + findIndexString(se,s));
    }
    if (test3ConsecutiveCharacter(s))
    {
        return -(400 + indexConsecutiveCharacter(s));
    }
    if (!testHaveSpecialCharacter(s)) return -5;
    for (int i = 0 ; i < strlen(s) ; i++)
    {
        if (!availbleCharacter(s[i])) return i;
    }   
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    if (num_pwds == 0) return -1;
    int useElement = 1;
    const char *TypePassword[30];
    int numInTypePassword[30] = {};
    TypePassword[0] = arr_pwds[0];
    numInTypePassword[0]++;

    for (int i = 1; i < num_pwds; i++) {
        bool isFound = false;
        for (int j = 0; j < useElement; ++j) {
            if (strcmp(arr_pwds[i], TypePassword[j]) == 0) {
                numInTypePassword[j]++;
                isFound = true;
                break;
            }
        }
        if (!isFound) {
            TypePassword[useElement] = arr_pwds[i];
            numInTypePassword[useElement]++;
            useElement++;
        }
    }
    
    int maxNumInType = 0;
    for (int i = 0 ; i < useElement ; i++)
    {
        if (numInTypePassword[i] > maxNumInType) maxNumInType = numInTypePassword[i];
    }
    int maxIndexes[30] = {}; // Array contain length of string whose index of element have same maxNumType
    for (int i = 0 ; i < useElement ; i++)
    {
        if (numInTypePassword[i] == maxNumInType) maxIndexes[i] = strlen(TypePassword[i]);
    }
    int indexResult = 0;
    for (int i = 0 ; i < useElement ; i++)
    {
        if (maxIndexes[i] > maxIndexes[indexResult]) indexResult = i;
    }
    for (int i = 0 ; i < num_pwds ; i++)
    {
        if (arr_pwds[i] == TypePassword[indexResult]) return i;
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////