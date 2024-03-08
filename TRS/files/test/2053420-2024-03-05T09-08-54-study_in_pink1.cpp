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
#define DEBUG_PRINTING 0
int roundFloatToInt(float number){
#if DEBUG_PRINTING == 1
    cout << "Rounding " << number << " to " << static_cast<int>(std::ceil(number)) << endl;
#endif
    return static_cast<int>(std::ceil(number));
}

void checkValidExp(int& exp1){
    if(exp1 > 600){
        exp1 = 600;
    }
    else if(exp1 < 0){
        exp1 = 0;
    }
}

void checkValidHp(int& hp1){
    if(hp1 > 666){
        hp1=666;
    }
    else if(hp1 < 0){
        hp1=0;
    }
}

void checkValidMoney(int& m){
    if(m > 3000){
        m = 3000;
    }
    else if(m < 0){
        m = 0;
    }
}

int closetPerfectSquare(int num){
    int squareRoot = static_cast<int>(sqrt(num));
    int candidate1 = squareRoot * squareRoot;
    int candidate2 = (squareRoot+1) * (squareRoot+1);
    return (num - candidate1 < candidate2 - num) ? candidate1 : candidate2;
}

int sumOfDigits(int number){
    int sum = 0;
    number = (number < 0) ? -number : number;
    while(number > 0){
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

#if DEBUG_PRINTING == 1
void print2DArray(int arr[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
#endif
//TASK 2 Helpers
float road1(int & HP1, int & EXP1, int & M1, int E3){
    //Return propability of road 1
    int s = closetPerfectSquare(EXP1);
#if DEBUG_PRINTING == 1
    cout << "EXP: " << EXP1 << endl;
    cout << "closes perfect square: " << s << endl;
#endif
    if(s >= EXP1){
        return 1.0;
    }
    else return (((float)EXP1/(float)s)+80.0)/123.0;
}

float road2(int & HP1, int & EXP1, int & M1, int E2){
    //return prob of Road 2
    int totalMoneySpent = 0;
    int moneySpendingCap = roundFloatToInt((float)M1/2);
#if DEBUG_PRINTING == 1
    int iteration = 0;
    std::cout << "Money spend cap: " << moneySpendingCap << endl;
#endif
    if(E2%2 == 0){
        if(HP1 < 200){
            if(M1 > 0){
                HP1 += roundFloatToInt(0.3*(float)HP1);
                checkValidHp(HP1);
                M1 -= 150;
                checkValidMoney(M1);
            }
        }
        else{
            if(M1 > 0){
                HP1 += roundFloatToInt(0.1*(float)HP1);
                checkValidHp(HP1);
                M1 -= 70;
                checkValidMoney(M1);
            }
        }
        if(EXP1 < 400){
            if(M1 > 0){
                M1 -= 200;
                checkValidMoney(M1);
                EXP1 += roundFloatToInt((float)EXP1*0.13);
                checkValidExp(EXP1);
            }
        }
        else{
            if(M1 > 0){
                M1 -= 120;
                checkValidMoney(M1);
                EXP1 += roundFloatToInt((float)EXP1*0.13);
                checkValidExp(EXP1);
            }
        }
        if(EXP1 < 300){
            if(M1 > 0){
                M1 -= 100;
                checkValidMoney(M1);
                EXP1 = roundFloatToInt((float)EXP1 - (float)EXP1*0.1);
                checkValidExp(EXP1);
            }
        }
        else{
            if(M1 > 0){
                M1 -= 120;
                checkValidMoney(M1);
                EXP1 = roundFloatToInt((float)EXP1 - (float)EXP1*0.1);
                checkValidExp(EXP1);
            }
        }
    }
    else{
#if DEBUG_PRINTING == 1
        cout << "E2 = " << E2 << ", Start looping rn" << endl;
#endif
        while(totalMoneySpent <= moneySpendingCap){
#if DEBUG_PRINTING == 1
            cout << "Iteration: " << iteration << endl;
#endif
            if(HP1 < 200){
                if(M1 > 0 && totalMoneySpent <= moneySpendingCap){
                    HP1 += roundFloatToInt((float)HP1*0.3);
                    checkValidHp(HP1);
                    M1 -= 150;
                    totalMoneySpent+=150;
                    checkValidMoney(M1);
                }
            }
            else{
                if(M1 > 0 && totalMoneySpent <= moneySpendingCap){
                    HP1 += roundFloatToInt(0.1*(float)HP1);
                    checkValidHp(HP1);
                    M1 -= 70;
                    totalMoneySpent += 70;
                    checkValidMoney(M1);
                }
            }
#if DEBUG_PRINTING == 1
            cout << "First Section: ";
            cout << "EXP1: " << EXP1 << ", HP1: " << HP1 << ", M1: " << M1 << endl;
            cout << "Total spent: " << totalMoneySpent << endl;
#endif 
            if(EXP1 < 400){
                if(M1 > 0 && totalMoneySpent <= moneySpendingCap){
                    M1 -= 200;
                    totalMoneySpent += 200;
                    checkValidMoney(M1);
                    EXP1 += roundFloatToInt((float)EXP1*0.13);
                }
            }
            else{
                if(M1 > 0 && totalMoneySpent <= moneySpendingCap){
                    M1-=120;
                    totalMoneySpent+=120;
                    checkValidMoney(M1);
                    EXP1 += roundFloatToInt((float)EXP1*0.13);
                }
            }
#if DEBUG_PRINTING == 1
            cout << "Second Section: ";
            cout << "EXP1: " << EXP1 << ", HP1: " << HP1 << ", M1: " << M1 << endl;
            cout << "Total spent: " << totalMoneySpent << endl;
#endif
            if(EXP1 < 300){
                if(M1 > 0 && totalMoneySpent < moneySpendingCap){
                    M1 -= 100;
                    totalMoneySpent += 100;
                    checkValidMoney(M1);
                    EXP1 = roundFloatToInt((float)EXP1 - (float)EXP1*0.1);
                }
            }
            else{
                if(M1 > 0 && totalMoneySpent < moneySpendingCap){
                    M1 -= 120;
                    totalMoneySpent += 120;
                    checkValidMoney(M1);
                    EXP1 = roundFloatToInt((float)EXP1 - (float)EXP1*0.1);
                }
            }
#if DEBUG_PRINTING == 1
            cout << "Third Section: ";
            cout << "EXP1: " << EXP1 << ", HP1: " << HP1 << ", M1: " << M1 << endl;
            cout << "Total spent: " << totalMoneySpent << endl;
            iteration++;
#endif
        }
    }
    HP1 = roundFloatToInt((float)HP1 -(float)HP1*0.17);
    checkValidHp(HP1);
    EXP1 += roundFloatToInt((float)EXP1*0.17);
    checkValidExp(EXP1);
#if DEBUG_PRINTING == 1
    cout << "END OF ROAD: ";
    cout << "EXP1: " << EXP1 << ", HP1: " << HP1 << ", M1: " << M1 << endl;
#endif
    return road1(HP1,EXP1,M1,E2);
}

float road3(int & HP1, int & EXP1, int & M1, int E2){
    //return prob of Road 3x
    const float P[] = {32.0, 47.0, 28.0, 79.0, 100.0, 50.0, 22.0, 83.0, 64.0, 11.0};
    int pIdx = sumOfDigits(E2) % 10;
    return P[pIdx];
}
//TASK 3 Helpers
void generateTable(int t[10][10], int E3){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            t[i][j] = ((E3*j)+(i*2))*(i-j);
        }
    }
}

int countGreater(int t[10][10], int rows, int cols, int n) {
    int count = 0;
    for (int i=0; i<rows; ++i) {
        for (int j = 0; j<cols; ++j) {
            if (t[i][j] > n) {
                count++;
            }
        }
    }
    return count;
}

int countSmaller(int t[10][10], int rows, int cols, int n) {
    int count = 0;
    for (int i=0; i<rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (t[i][j] < n) {
                count++;
            }
        }
    }
    return count;
}

int getBiggestInLeftDiagonal(int t[10][10], int rows, int cols, int row, int col) {
    int biggestUpwards = t[row][col];
    int biggestDownwards = t[row][col];
    // Upwards direction
    for (int i=row, j=col; i>=0 && j>=0; --i, --j) {
        if (t[i][j] > biggestUpwards) {
            biggestUpwards = t[i][j];
        }
    }
    // Downwards direction
    for (int i=row, j=col; i<rows && j<cols; ++i, ++j) {
        if (t[i][j] > biggestDownwards) {
            biggestDownwards = t[i][j];
        }
    }
    // Return the maximum of the two directions
    return (biggestUpwards > biggestDownwards) ? biggestUpwards : biggestDownwards;
}

int getBiggestInRightDiagonal(int t[10][10], int rows, int cols, int row, int col) {
    int biggestUpwards = t[row][col];
    int biggestDownwards = t[row][col];
    // Upwards direction
    for (int i=row, j=col; i>=0 && j<cols; --i, ++j) {
        if (t[i][j] > biggestUpwards) {
            biggestUpwards = t[i][j];
        }
    }
    // Downwards direction
    for (int i=row, j=col; i<rows && j>=0; ++i, --j) {
        if (t[i][j] > biggestDownwards) {
            biggestDownwards = t[i][j];
        }
    }
    // Return the maximum of the two directions
    return (biggestUpwards > biggestDownwards) ? biggestUpwards : biggestDownwards;
}

//TASK 4 Helper
int isSpeacialCharPresent(const char* str){
    char specialChar[5] =  {'@', '#', '%', '$', '!'};
    int length = 0;
    while (str[length] != '\0') {
        for(int i=0; i<5; i++){
            if(str[length] == specialChar[i]) return 1;
        }
        length++;
    }
    return 0;
}

int stringLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

bool isSubstringMatch(const char* str, const char* substr, int i) {
    // Check if the index is valid
    if (i < 0 || i >= strlen(str)) {
        return false;
    }
    // Calculate the length of the substring
    size_t substrLength = strlen(substr);
    // Check if the substring fits in the remaining part of the string
    if (strlen(str) - i < substrLength) {
        return false;
    }
    // Compare the substring with the portion of the string starting from index i
    if (strncmp(str + i, substr, substrLength) == 0) {
        return true;
    } else {
        return false;
    }
}

//Task 5 data structure and helpers
passwordStorageObject::passwordStorageObject(){
    this->count = 0;
}

passwordStorageObject::~passwordStorageObject(){

}

void passwordStorageObject::add(const char* t, int firstIdx){
    if(this->count==30){
        return;
    }
    this->array[this->count] = {
        .count = 1,
        .passwdLength = stringLength(t),
        .firstIdx = firstIdx,
        .passwd = t
    };
    this->count++;
}

int passwordStorageObject::search(const char* t){
    if(this->count ==0){
        return 0;
    }
    for(int i=0; i<this->count; i++){
        if(strcmp(this->array[i].passwd,t)==0){
            this->array[i].count++;
            return 1;
        }
    }
    return 0;
}

int passwordStorageObject::mostFrequentPasswd(){
    int maxCount = 0;
    int retIdx = 0;
    int maxLen = 0;
    for(int i=0; i<this->count; i++){
        if(this->array[i].count > maxCount){
            retIdx = this->array[i].firstIdx;
            maxCount = this->array[i].count;
        }
    }
    for(int i=0; i< this->count; i++){
        if(this->array[i].count == maxCount && this->array[i].passwdLength > maxLen){
            retIdx = this->array[i].firstIdx;
            maxLen = this->array[i].passwdLength;
        }
    }
    return retIdx;
}
//Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int d;
    if(e1 < 0 | e1 > 99){
        return -99;
    }
    if(0<=e1 && e1 <=3){
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
                exp2+=149;
                break;
        }
        checkValidExp(exp2);
        d = e1*3 + exp1*7;
        if(d%2==0){
            exp1 += roundFloatToInt(((float)d)/200);
        }
        else{
            exp1 = roundFloatToInt((float)exp1 - ((float)d)/100);
        }
        checkValidExp(exp1);
    }
    else{
        if(4<=e1 && e1 <= 19){
            exp2 += roundFloatToInt(19+((float)e1)/4);
            checkValidExp(exp2);
        }
        else if(20 <= e1 && e1 <= 49){
            exp2 += roundFloatToInt(21+((float)e1)/9);
            checkValidExp(exp2);
        }
        else if(50<= e1 && e1 <= 65){
            exp2 += roundFloatToInt(17+((float)e1)/16);
            checkValidExp(exp2);
        }
        else if(66<= e1 && e1 <= 79){
            exp2+=roundFloatToInt(19+((float)e1)/4);
            checkValidExp(exp2);
            if(exp2>200){
                exp2 += roundFloatToInt(21+((float)e1)/9);
                checkValidExp(exp2);
            }
        }
        else{
            exp2+=roundFloatToInt(19+((float)e1)/4);
            checkValidExp(exp2);
            exp2+=roundFloatToInt(21+((float)e1)/9);
            checkValidExp(exp2);
            if(exp2>400){
                exp2 += roundFloatToInt(17+((float)e1)/16);
                checkValidExp(exp2);
                exp2 += roundFloatToInt(exp2*0.15);
                checkValidExp(exp2);
            }
        }
        exp1-=e1;
        checkValidExp(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    float P1 = 100*road1(HP1,EXP1,M1,E2);
    float P2 = 100*road2(HP1,EXP1,M1,E2);
    float P3 = road3(HP1,EXP1,M1,E2);
    float Paverage = 0.0;
    if(E2 < 0 || E2 > 99){
        return -99;
    }
#if DEBUG_PRINTING == 1
    cout << P1 << " " << P2 << " " << P3 << " " <<  endl;
#endif
    if(P1 == 100 && P2 == 100 && P3 == 100){
        EXP1 = roundFloatToInt((float)EXP1 - (float)EXP1*0.25);
        checkValidExp(EXP1);
    }
    else{
        Paverage = (P1+P2+P3)/3.0;
#if DEBUG_PRINTING == 1
        cout << Paverage << endl;
#endif
        if(Paverage < 50.0){
            HP1 = roundFloatToInt((float)HP1 - (float)HP1*0.15);
            checkValidHp(HP1);
            EXP1 += roundFloatToInt(EXP1*0.15);
            checkValidExp(EXP1);
        }
        else{
            HP1 = roundFloatToInt((float)HP1 - (float)HP1*0.1);
            checkValidHp(HP1);
            EXP1 += roundFloatToInt(EXP1*0.20);
            checkValidExp(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    int taxiScoreTable[10][10];
    generateTable(taxiScoreTable, E3);
    int numOfLargerNumbers = countGreater(taxiScoreTable,10,10,E3*2);
    int numOfSmallerNumbers = countSmaller(taxiScoreTable,10,10,0-E3);
    int meetUpICoordinate = sumOfDigits(numOfLargerNumbers);
    int meetUpJCoordinate = sumOfDigits(numOfSmallerNumbers);
    int watsonScore = 0;
    int watsonLeftwardDiagScore = 0;
    int watsonRightwardDiagScore = 0;
    int taxiScore = 0;
    int ret = 0;
    if(E3 < 0 || E3 > 99){
        return -99;
    }
    while(meetUpICoordinate >= 10){
        meetUpICoordinate = sumOfDigits(meetUpICoordinate);
    }
    while(meetUpJCoordinate >= 10){
        meetUpJCoordinate = sumOfDigits(meetUpJCoordinate);
    }
    watsonLeftwardDiagScore = getBiggestInLeftDiagonal(taxiScoreTable,10,10,meetUpICoordinate,meetUpJCoordinate);
    watsonRightwardDiagScore = getBiggestInRightDiagonal(taxiScoreTable,10,10,meetUpICoordinate,meetUpJCoordinate);
    watsonScore = (watsonLeftwardDiagScore > watsonRightwardDiagScore) ? watsonLeftwardDiagScore : watsonRightwardDiagScore;
    taxiScore = taxiScoreTable[meetUpICoordinate][meetUpJCoordinate];
#if DEBUG_PRINTING == 1
    cout << "Score table: " << endl;
    print2DArray(taxiScoreTable,10,10);
    cout << "Num of greater and smaller number: " << numOfLargerNumbers << "," << numOfSmallerNumbers << endl;
    cout << "Meetup coordinate(i,j): " << meetUpICoordinate << "," << meetUpJCoordinate << endl;
    cout << "Watson left diag and right diag score: " << watsonLeftwardDiagScore << "," << watsonRightwardDiagScore << endl;
    cout << "Watson Final Score: " << watsonScore << endl;
    cout << "taxi Score: " << taxiScore << endl;
#endif
    if(watsonScore >= abs(taxiScore)){
        EXP1 += roundFloatToInt((float)EXP1*0.12);
        checkValidExp(EXP1);
        EXP2 += roundFloatToInt((float)EXP2*0.12);
        checkValidExp(EXP2);
        HP1 += roundFloatToInt((float)HP1*0.1);
        checkValidHp(HP1);
        HP2 += roundFloatToInt((float)HP2*0.1);
        checkValidHp(HP2);
        ret = watsonScore;
    }
    else{
        EXP1 = roundFloatToInt((float)EXP1 - (float)EXP1*0.12);
        checkValidExp(EXP1);
        EXP2 = roundFloatToInt((float)EXP2 - (float)EXP2*0.12);
        checkValidExp(EXP2);
        HP1 = roundFloatToInt((float)HP1 - (float)HP1*0.1);
        checkValidHp(HP1);
        HP2 = roundFloatToInt((float)HP2 - (float)HP2*0.1);
        checkValidHp(HP2);
        ret = taxiScore;
    }
    // TODO: Complete this function
    return ret;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int passLen = stringLength(s);
    int mailLen = stringLength(email);
    int specialChar = isSpeacialCharPresent(s);
    int i=1;
    char sCopy[100];
    memcpy(sCopy,email,mailLen);
    char* se = strtok(sCopy,"@");
    int seLen = stringLength(se);
    if(passLen < 8){
        return -1;
    }
    else if(passLen > 20){
        return -2;
    }
    else{
        for(int i=0; i < passLen -2; i++){
            if(s[i] == s[i+1] && s[i+1] == s[i+2]){
                return -(400+i);
            }
            else if(isSubstringMatch(s,se,i)){
                return -(300+i);
            }
        }
        if(specialChar == 0){
            return -5;
        }
    }
#if DEBUG_PRINTING == 1
    printf("Password: %s\n",s);
    printf("Pasword Length: %d\n", passLen);
    printf("Se: %s\n", se);
#endif
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    passwordStorageObject passwdStrObj;
    for(int i=0; i<num_pwds; i++){
        if(passwdStrObj.search(arr_pwds[i])==0){
            passwdStrObj.add(arr_pwds[i],i);
        }
    }
    return passwdStrObj.mostFrequentPasswd();
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
