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

//Constants and Var
const int MAX_EXP = 600;
const int MIN_EXP = 0;
const int MAX_HP = 666;
const int MIN_HP = 0;
const int MAX_MONEY = 3000;
const int MIN_MONEY = 0;
const int SIZE = 10;
const int ROW_SIZE = 10;
const int COLUMN_SIZE = 10;
const int MIN_ROW = 0;
const int MAX_ROW = 10;
const int MIN_COLS = 0;
const int MAX_COLS =10;
//Check Events Code
/*if(e1 =< 0 || e1 >= 99)
return -99;*/

//Check Valid and Substitute  Function
void check(int& exp){
 if (exp<MIN_EXP)   
    exp = MIN_EXP; //assign new value to exp
 if(exp>MAX_EXP)
    exp = MAX_EXP; //assign new value to exp
}
void checkMoney(int& mon){
 if (mon<MIN_MONEY)   
    mon = MIN_MONEY; //assign new value to mon
 if(mon>MAX_MONEY)
    mon = MAX_MONEY; //assign new value to mon
}
void checkHP(int& hp){
 if (hp<MIN_HP)   
    hp = MIN_HP; //assign new value to hp
 if(hp>MAX_HP)
    hp = MAX_HP; //assign new value to hp
}




// Task 1 ====================================
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

//Check Events Code
if(e1 < 0 || e1 > 99)
return -99;

//Case 1
if(0 <= e1 && e1 <= 3){
check(exp1);
check(exp2);
switch (e1)
{
case 0:
 exp2 += 29;
    break;
case 1:
 exp2 +=45;
    break;
case 2:
 exp2 +=75;
    break;
case 3:
 exp2 += (29 + 45 + 75);
    break; 
default:
    break;
}
check(exp2);
int D = e1*3 + exp1*7; //Decision value
if (D%2==0)
    exp1 = ceil(exp1*1.0 + D/200.0);
else 
    exp1 = ceil(exp1*1.0 - D/100.0);
check(exp1);
}

//Case 2
if(4 <= e1 && e1 <= 99){
check(exp1);
check(exp2);
 if (4 <= e1 && e1 <= 19) //info1
 {
    exp2 += ceil(e1/4.0 + 19);
    check(exp2);
 }   
 if (20 <= e1 && e1 <= 49) //info2
 {
    exp2 += ceil(e1/9.0 +21);
    check(exp2);
 }   
 if (50 <= e1 && e1 <= 65) //info3
 {
    exp2 += ceil(e1/16.0 + 17);
    check(exp2);
 }
 if (66 <= e1 && e1 <= 79) //info4
{
    exp2 += ceil(e1/4.0 + 19); 
    check(exp2);
    if (exp2 > 200)  //checkifexp>200
    {
     exp2 += ceil(e1/9.0 +21);
         check(exp2);
    }
}
 if (80 <= e1 && e1 <= 99) //info5
{
    exp2 += ceil(e1/4.0 + 19);  
    exp2 += ceil(e1/9.0 +21);
        check(exp2);
    if (exp2 > 400)      ////checkifexp>400
    {
     exp2 += ceil(e1/16.0 + 17);
         check(exp2);
     exp2 = ceil(exp2* 1.15);    //increase15%
         check(exp2);
    }
}
exp1 -= e1; //decrease exp1 of Sherlock
check(exp1);
}
    return exp1 + exp2;
}


// Task 2 ===================================================
//CheckTheNearestPerfectSquare and Calculate the Possibility
double checkP(int EXP1) {
    // Nearest perfect square----------
    int S;
    double P;
    // Calculate the square root of the input
    int squareRoot = static_cast<int>(sqrt(EXP1));

    // Check the nearest square number
    int lowerSquare = squareRoot * squareRoot;
    int upperSquare = (squareRoot + 1) * (squareRoot + 1);

    // Choose the nearest perfect square number
    if (EXP1 - lowerSquare < upperSquare - EXP1) {
         S =  lowerSquare;
    } else {
         S = upperSquare;
    }
//-----------
// Calculate Possibility
    if(EXP1 >= S)
         P = 100;
    else
         P = (((EXP1/(S * 1.0)) + 80)/123.0)*100.0;
return P;
}
// Check the money after each events
bool checkMoneyToContinue(int &spentMoney,int &M1, int & HP1, int & EXP1, int INITIAL_M, int E2){
    checkMoney(M1);
    bool outOfMoney = false;
    if(M1 == 0 ||  (spentMoney > INITIAL_M/2.0 && E2 % 2) ){
       HP1 = ceil((float)HP1 * 83 / 100);  checkHP(HP1);
       EXP1 = ceil(EXP1 * 1.17); check(EXP1);
       outOfMoney = true;    
    }
return outOfMoney;
}
//Road 02 Events
void calculateRoad02Events_1(int & HP1, int & EXP1, int & M1, int E2, int INITIAL_M, int &spentMoney) {
    check(EXP1); checkHP(HP1) ; checkMoney(M1); // check the input value
if(checkMoneyToContinue(spentMoney, M1, HP1, EXP1, INITIAL_M, E2))
return;
//Event_1=========== Buy Foods and Drinks
if(HP1 < 200){
   HP1 = ceil((float)HP1 * 130 / 100); checkHP(HP1);
   M1 -= 150; 
   spentMoney += 150;
}
else {
   HP1 = ceil((float)HP1 * 110 / 100); checkHP(HP1);
   M1 -= 70; 
   spentMoney += 70;
}
if(checkMoneyToContinue(spentMoney, M1, HP1, EXP1, INITIAL_M, E2))
return;
//Event_2 ======== Buy Transport
if(EXP1 < 400){
    M1 -= 200; 
    spentMoney += 200;
    EXP1 = ceil(EXP1 * 1.13); check(EXP1);}
else{
    M1 -= 120;
    spentMoney += 120;
    EXP1 = ceil(EXP1 * 1.13); check(EXP1);}
if(checkMoneyToContinue(spentMoney, M1, HP1, EXP1, INITIAL_M, E2)){
return;}
//Event3=== Homeless Man
if(EXP1 < 300){
M1 -= 100;
spentMoney += 100;}
else{
M1 -= 120;
spentMoney += 120;}
EXP1 = ceil(EXP1 * 0.9); check(EXP1);
if(checkMoneyToContinue(spentMoney, M1, HP1, EXP1, INITIAL_M, E2))
return;
    HP1 = ceil((float)HP1 * 83 / 100);  checkHP(HP1);
    EXP1 = ceil(EXP1 * 1.17); check(EXP1);
return;
}

//Function to calculate the number E2 for P3 selection
int chooseNumberE2(int E2){ // 
if (10 <= E2 && E2 <= 99)
{
    int firstDigit = E2 % 10;
    int secondDigit = E2 / 10;
    int sumDigit = firstDigit + secondDigit;
    int finalDigit = sumDigit % 10;
    return finalDigit;
}
return E2;
}

// The final probability for Sherlock to find the luggage
void finalProbability(double P1, double P2, double P3, int& EXP1, int & HP1){
int averageOfProbability = 0;
int maxPercent = 100;
averageOfProbability = (P1 + P2 + P3)/3;
if(P1 == maxPercent && P2 == maxPercent && P3 == maxPercent){ //the first case when all the probability are 100%
EXP1 = ceil(EXP1 * 0.75); check(EXP1);
}
else if (averageOfProbability < 50){
    EXP1 = ceil(EXP1 * 1.15); check(EXP1);
    HP1 = ceil((float)HP1 * 85 / 100); checkHP(HP1);
}
else if (averageOfProbability > 50 && averageOfProbability != 100){
 EXP1 = ceil(EXP1 * 1.2); check(EXP1);
 HP1 = ceil((float)HP1 * 90 / 100); checkHP(HP1);  
} 
}
// Main trace luggage function

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
// TODO: Complete this function
//Check Events Code
if(E2 < 0 || E2 > 99)
return -99;
//Declare initial money for later
checkMoney(M1);
const int INITIAL_M = M1;
const int HALF_OF_INITIAL_M = INITIAL_M/2;
int spentMoney = 0;
int count = 0;
    check(EXP1); checkHP(HP1) ; checkMoney(M1); // check the input value

//Road01==============
double P1 = checkP(EXP1); 
check(EXP1); checkHP(HP1) ; checkMoney(M1); // check the value after road01

//Road02=============
if (E2 % 2 == 0){ // if e2 is an even number, Sherlock only go for 1 time.
calculateRoad02Events_1(HP1, EXP1, M1, E2, INITIAL_M, spentMoney);
}
else{
while (spentMoney <= HALF_OF_INITIAL_M){ //if e2 is an odd number, the process repeat until money spent > initial money
//Event_1=========== Buy Foods and Drinks
count++;
if(checkMoneyToContinue(spentMoney, M1, HP1, EXP1, INITIAL_M, E2))
break;
if(HP1 < 200){
   HP1 = ceil((float)HP1 * 130 / 100); checkHP(HP1);
   M1 -= 150; 
   spentMoney += 150;
}
else {
   HP1 = ceil((float)HP1 * 110 / 100); checkHP(HP1);

   M1 -= 70; 
   spentMoney += 70;
}
if(checkMoneyToContinue(spentMoney, M1, HP1, EXP1, INITIAL_M, E2))
break;
//Event_2 ======== Buy Transport
if(EXP1 < 400){
   M1 -= 200; 
   spentMoney += 200;}
else{
   M1 -= 120;
   spentMoney += 120;}
EXP1 = ceil(EXP1 * 1.13); check(EXP1);
if(checkMoneyToContinue(spentMoney, M1, HP1, EXP1, INITIAL_M, E2)){
break;}
//Event3=== Homeless Man
if(EXP1 < 300){
M1 -= 100;
spentMoney += 100;}
else{
M1 -= 120;
spentMoney += 120;}
EXP1 = ceil(EXP1 * 0.9); check(EXP1);
if(checkMoneyToContinue(spentMoney, M1, HP1, EXP1, INITIAL_M, E2))
break;
}
}
//Calculate P2 after road 2
check(EXP1);
double P2 = checkP(EXP1);
        check(EXP1);
        checkHP(HP1) ; 
        checkMoney(M1); // check the value after road02
//Road03=============
int pArray[10] =  {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

//Choose value from the array
double P3 = pArray[chooseNumberE2(E2)];
// Call the final Probability function

finalProbability(P1, P2, P3, EXP1, HP1);
        check(EXP1); 
        checkHP(HP1) ; 
        checkMoney(M1); // check the value after all
    return HP1 + EXP1 + M1;
}






// Task 3 ======================================
// Prototype
// Func to calculate max 
int checkMaxValue(const int taxiArray[][COLUMN_SIZE], int row, int column){
    int maxPoint = taxiArray[row][column];
    // LeftDiagonal_01
    for (int i = row, j = column; i < MAX_ROW && j < MAX_COLS; i++ , j++)
    {
        if (taxiArray[i][j] > maxPoint)
        {
            maxPoint = taxiArray[i][j];
        }
    }
    //LeftDiagonal_02
    for (int i = row, j = column; i > MIN_ROW && j < MIN_COLS; i-- , j--)
    {
        if (taxiArray[i][j] > maxPoint)
        {
            maxPoint = taxiArray[i][j];
        }
    }
    //RightDiagonal_01
    for (int i = row, j = column; i > MIN_ROW && j < MAX_COLS; i-- , j++)
    {
        if (taxiArray[i][j] > maxPoint)
        {
            maxPoint = taxiArray[i][j];
        }
    }
    //RightDiagonal_02
    for (int i = row, j = column; i < MAX_ROW && j > MIN_COLS; i++ , j--)
    {
        if (taxiArray[i][j] > maxPoint)
        {
            maxPoint = taxiArray[i][j];
        }
    }
return maxPoint;
}
// Function to assign points to Sherlock array
void assignPointSherlock(const int taxiArray[][COLUMN_SIZE], int sherlockPoints [][COLUMN_SIZE]){
for ( int i = 0; i < ROW_SIZE; i++)
{
    for (int j = 0; j < COLUMN_SIZE; j++)
    {
        sherlockPoints[i][j] = abs(checkMaxValue(taxiArray, i, j));
    }    
}
}

// Function to minimize the digit number
int minimizeNumber(int num) {
    int finalDigit = 0;
    if (num < 10) {
        return num;
    } else {
        while (num > 10) {
            int firstDigit = num % 10;
            int secondDigit = num / 10;
            int sumDigit = firstDigit + secondDigit;

            if (sumDigit == 10) {
                sumDigit = 1;
            }

            num = sumDigit;  
            finalDigit = sumDigit;
        }
    }
    return finalDigit;
}

// Function to count the value of the Meet Point Meet(i,j);
// First function for i - row
int countIndex_i(const int taxiPoints[][COLUMN_SIZE], int E3){
    int count_i = 0; //declare count number
    for (int i = 0; i < MAX_ROW; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            if (taxiPoints[i][j] > E3*2) //Comparing condition
            {
                count_i++;
            }
        }
    }
    count_i = minimizeNumber(count_i);
    return count_i;
}
//second function for j - column
int countIndex_j(const int taxiPoints[][COLUMN_SIZE], int E3){
    int count_j = 0; //declare count number
    for (int i = 0; i < MAX_ROW; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            if (taxiPoints[i][j] < - E3) //Comparing condition
            {
                count_j++;
            }
        }
    }
    count_j = minimizeNumber(count_j);
    return count_j;
}

// Function to compare VAlue at the meeting point
int comparingPoints(const int taxiPoints[][COLUMN_SIZE], const int sherlockPoint[][COLUMN_SIZE], bool& caughtTaxi, int index_i, int index_j){
    //----var----
    int sherlockComparingPoint = abs(sherlockPoint[index_i][index_j]);
    int taxiComparingPoint = abs(taxiPoints[index_i][index_j]);
    int sherlockRealPoint = sherlockPoint[index_i][index_j];
    int taxiRealPoint = taxiPoints[index_i][index_j];
    // compare
    if (sherlockComparingPoint >= taxiComparingPoint)
    {
        caughtTaxi = true;
        return sherlockRealPoint;
    }
    else{
        caughtTaxi = false;
        return taxiRealPoint;
    }
}

//Chase Taxi Function___________
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
//Check Events Code
if(E3 < 0 || E3 > 99)
return -99;
    check(EXP1);
    check(EXP2);
    checkHP(HP1);
    checkHP(HP2); 
//------------Var-----------
// bool variable to check if Sherlock catch the taxi or not
bool caughtTaxi = true;
//Create Array for Taxi Points
    int taxiPoints[ROW_SIZE][COLUMN_SIZE] = {};
// Assign value for the Array taxiPoints
    for ( int i = 0 ; i < ROW_SIZE; i++){
        for ( int j = 0 ; j < COLUMN_SIZE; j++)
            {
                taxiPoints[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
}
//Create Array for Sherlock Points
    int sherlockPoints [ROW_SIZE][COLUMN_SIZE] = {};
assignPointSherlock(taxiPoints, sherlockPoints);

//Declare Var for index and final results
int i = countIndex_i(taxiPoints, E3);
int j = countIndex_j(taxiPoints, E3);
int result = 0;
//Start compare

result = comparingPoints(taxiPoints, sherlockPoints, caughtTaxi, i, j);

// Upload the value of HP and EXP
if (caughtTaxi)
{
    EXP1 = ceil((float)EXP1 * 112/100); check(EXP1);
    HP1 = ceil((float)HP1 * 110/100); checkHP(HP1);
    EXP2 = ceil((float)EXP2 * 112/100); check(EXP2);
    HP2 = ceil((float)HP2 * 110/100); checkHP(HP2);
}
else{
    EXP1 = ceil((float)EXP1 * 88/100); check(EXP1);
    HP1 = ceil((float)HP1 * 90/100); checkHP(HP1);
    EXP2 = ceil((float)EXP2 * 88/100); check(EXP2);
    HP2 = ceil((float)HP2 * 90/100); checkHP(HP2);
}
    return result;
}

// Task 4 ===================================================
// Function for email

void passingEmailToArray( string email, string & email_str){
    int count = 0;
    for (char m : email){
        if ( m == '@'){
            break;
        }
        email_str.push_back(m);
        count ++;
    }
}

// Func for password
/*void passingPasswordToArray(const string s, char sArray[], int& elementCount2){
    for (char m : s){
        sArray[elementCount2++] = m;
    }
}*/

// Function to check Password
//1. check min len
int _1checkMinLength(const string s){
    if (s.length() < 8 ){
    int result = -1;
    return result;}
    else return 99;
}

int _2checkMaxLength(const string s){
    if (s.length() > 20 ){
    int result = -2;
    return result;}
    else return 99;    
}
//3. check identical
int _3checkIdenticalPassAndEmail(const string s, int mainArraySize,const string emailArray, int subArraySize ){
    for (int i = 0; i <= mainArraySize - subArraySize; i++) {
        bool match = true;
        for (int j = 0; j < subArraySize; j++) {
            if (s[i + j] != emailArray[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return i; 
        }
    }
    return -99;
}
//4. check 2 consecutive identical 
int _4check2Consecutive (const string s){   
    int result = 0;
    for (int i = 0; i < (s.length() - 1); i++){
            if (s.at(i + 1) == s.at(i)){
            result = i;
            return result;}
    }
return -99;
}
//5. check symbol
bool _5checkSymbol(const string s){
string symbol = "@%#$!"; //Declare symbol list
for (char passwordChar : s) {
        for (char symbolChar : symbol) {
            if (passwordChar == symbolChar) {
                return true;
            }
        }
    }
return false;
}
//6. check if char not in domain
bool isInDomain(char c) {
    return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c == '@') || (c >= '#' && c < '&') || (c == '!');
}
// function to return the abnormal index
int _6findAbnormalPosition(const string s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (!isInDomain(s[i])) {
            return i; //the first position
        }
    }
return - 99;
}
//=====================================================

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

// Save s and email len
const int passwordLen = strlen(s);
const int emailLen = strlen(email);

string email_str;

/*/ Declare array for email
char emailArray[emailLen] = {};
int elementCount1 = 0;
// Declare array for password;
char sArray[passwordLen] = {};
int elementCount2 = 0;*/

// Passing string email to a new string
passingEmailToArray(email, email_str); 
const int email_strLen = email_str.length();

// Checking password criteria
if (_1checkMinLength(s) < 0)
{
    int final = _1checkMinLength(s);
    return final;
}
else if (_2checkMaxLength(s) < 0)
{
    int final = _2checkMaxLength(s);
    return final;
} 
else if (_3checkIdenticalPassAndEmail(s, passwordLen, email_str, email_strLen) >= 0)
{
    int final = _3checkIdenticalPassAndEmail(s, passwordLen, email_str, email_strLen);
    
    return -(300 + final) ;
}
else if(!(_4check2Consecutive(s) < 0)){
    return - (400 + _4check2Consecutive(s));
}
else if(!(_5checkSymbol(s))){
    return -5;
}
else if(_6findAbnormalPosition(s) >= 0){
    return _6findAbnormalPosition(s);
}

return -10;     
}


// Task 5==========================================

int findFirstIndexOfMostFrequentElement(const char* arr_pwds[], int size) {
    // create array to save the number of elements
    int count[size] = {0};

   // count the number of appearance of each elements
    for (int i = 0; i < num_pwds; ++i) {
        for (int j = 0; j < num_pwds; ++j) {
            if (arr_pwds[i] == arr_pwds[j]) {
                count[i]++;
            }
        }
    }
   // find the most frequent and its first index
    int firstIndex = 0;
    for (int i = 1; i < num_pwds; ++i) {
        if (count[i] > count[firstIndex] || 
        count[i] == count[firstIndex] && // compare condition when there are same number of frequency
        strlen(arr_pwds[i]) > strlen(arr_pwds[firstIndex])) { 
            firstIndex = i;
        }
    }
    return firstIndex;
}
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
const int sizeOfArrayForPass = num_pwds;
return findFirstIndexOfMostFrequentElement(arr_pwds, sizeOfArrayForPass);
}




////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////