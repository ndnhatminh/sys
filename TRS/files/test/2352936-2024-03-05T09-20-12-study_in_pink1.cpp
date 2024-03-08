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

//Task 1
//check EXP range
void checkEXP(int & exp){
    if (exp>600){
        exp = 600;
    }
    if (exp<0){
        exp = 0;
    }
}
//check HP
void checkHP(int & hp){
    if (hp>666){
        hp = 666;
    }
    if (hp<0){
        hp = 0;
    }
}
//check Money
void checkM(int & m){
    if (m>3000){
        m = 3000;
    }
    if (m<0){
        m = 0;
    }
}
//check E range
bool checkE(int E){
    if (E<0||E>99){
        return false;
    }
    return true;
}
//check even
bool checkEven(int d){
    if (d%2==0){
        return true;
    }
    return false;
}
//round up the number
int roundUp(float r){
    if (r<0)
    {
        return 0;
    }
    int r_int=r;
    if (r-r_int==0){
        return r_int;
    } else return r_int+1;
}
//Decode and check E1
int decodeE1(int e){
    if (e>=0&&e<=3){
        return e; //these cases are of mission 1
    }
    if (e>=4&&e<=19){
        return 11; //case 1 of mission 2
    }
    if (e>=20&&e<=49){
        return 12; //case 2 of mission 2
    }
    if (e>=50&&e<=65){
        return 13; //case 3 of mission 2
    }
    if (e>=66&&e<=79){
        return 14; //case 4 of mission 2
    }
    if (e>=80&&e<=99){
        return 15; //case 5 of mission 2
    }
    return -99;
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int D; //D is the decision of Sherlock
    //change Watson's EXP
    if (e1<0||e1>99){
        return -99;
    }
    checkEXP(exp1);
    checkEXP(exp2);
    switch (decodeE1(e1)){
        case 0: //case 1 mission 1
            exp2+=29;
            break;
        case 1: //case 2 mission 1
            exp2+=45;
            break;
        case 2: //case 3 mission 1
            exp2+=75;
            break;
        case 3: //case 4 mission 1
            exp2+=149;
            break;
        case 11: //case 1 mission 2
            exp2+=roundUp(e1/4.0+19);
            break;
        case 12: //case 2 mission 2
            exp2+=roundUp(e1/9.0+21);
            break;
        case 13: //case 3 mission 2
            exp2+=roundUp(e1/16.0+17);
            break;
        case 14: //case 4 mission 2
            exp2+=roundUp(e1/4.0+19);
            checkEXP(exp2);
            if (exp2>200){
                exp2+=roundUp(e1/9.0+21);
                checkEXP(exp2);
            }
            break;
        default: //case 5 mission 2
            exp2+=roundUp(e1/4.0+19);
            checkEXP(exp2);
            exp2+=roundUp(e1/9.0+21);
            checkEXP(exp2);
            if (exp2>400){
                exp2+=roundUp(e1/16.0+17);
                checkEXP(exp2);
                exp2=roundUp(exp2*1.15);
                checkEXP(exp2);
            }
            break;
    }
    checkEXP(exp1);
    checkEXP(exp2);
    D=e1*3+exp1*7;
    if (decodeE1(e1)<=3){ //Sherlock's changes in mission 1
    if (checkEven(D)){
        exp1+=roundUp(D/200.0);
    } else {
        exp1=roundUp(exp1-(D/100.0));
    }
    } else { //Sherlock's changes in mission 2
        exp1-=e1; //Sherlock is surprised that Harry is a woman
    }
    checkEXP(exp1);
    return exp1 + exp2;
}
//Task 2
//find closest Square number 
int findCloseSquare(int exp1){
    int gap[26], min=576; //because 25*25=625 larger than max EXP=600, and 600 is closest to 24*24
    for(int i=0; i<=25; i++){
        gap[i]=abs(i*i-exp1);
        if (min>gap[i]){
            min=gap[i];
        }
    }
    for(int i=0; i<=25; i++){
        if (min==gap[i]){
            min=i*i;
            break;
        }
    }
    return min;
}
//Calculate P for path 1
double pathOne(int exp1){
    if (exp1>=findCloseSquare(exp1)){
        return 100;
    } else {
        return ((exp1/(double)findCloseSquare(exp1)+80)/1.23);
    }
}
//Check if Sherlock has used more than half the initial money
bool checkHalf(int iniM1, int m1){
    if (m1<(0.5*iniM1)){
        return true; //the used money is currently > 50%
    }
    return false; //the used money is currently < 50%
}
//Change vars for event 1 of path 2
void event1(int & hp1, int & m1){
    if (hp1<200){
        hp1=roundUp(1.3*hp1);
        checkHP(hp1);
        m1-=150;
        checkM(m1);
    } else {
        hp1=roundUp(1.1*hp1);
        checkHP(hp1);
        m1-=70;
        checkM(m1);
    }
}
//Change vars for event 2 of path 2
void event2(int & exp1, int & m1){
    if (exp1<400){
        m1-=200;
        checkM(m1);
    } else {
        m1-=120;
        checkM(m1);
    }
    exp1=roundUp(1.13*exp1);
    checkEXP(exp1);
}
//Change vars for event 3 of path 2
void event3(int & exp1, int & m1){
    if (exp1<300){
        m1-=100;
        checkM(m1);
    } else {
        m1-=120;
        checkM(m1);
    }
    exp1=roundUp(0.9*exp1);
    checkEXP(exp1);
}
//Calculate HP1, EXP1, M1 and P2 for path 2
double pathTwo(int & hp1, int & exp1, int & m1, int e2){
    int iniM1=m1;
    if (m1<=0){
        hp1=roundUp(0.83*hp1);
        exp1=roundUp(1.17*exp1);
        checkM(m1);
        checkHP(hp1);
        checkEXP(exp1);
        return pathOne(exp1);
    }
    if (e2%2!=0){
        while(!checkHalf(iniM1, m1)){
            event1(hp1, m1);
            if (checkHalf(iniM1, m1)){
                hp1=roundUp(0.83*hp1);
                exp1=roundUp(1.17*exp1);
                checkM(m1);
                checkHP(hp1);
                checkEXP(exp1);
                return pathOne(exp1);
            }
            event2(exp1, m1);
            if (checkHalf(iniM1, m1)){
                hp1=roundUp(0.83*hp1);
                exp1=roundUp(1.17*exp1);
                checkM(m1);
                checkHP(hp1);
                checkEXP(exp1);
                return pathOne(exp1);
            }
            event3(exp1, m1);
            if (checkHalf(iniM1, m1)){
                hp1=roundUp(0.83*hp1);
                exp1=roundUp(1.17*exp1);
                checkM(m1);
                checkHP(hp1);
                checkEXP(exp1);
                return pathOne(exp1);
            }
        }
    } else {
        event1(hp1, m1);
        if (m1<=0){
            hp1=roundUp(0.83*hp1);
            exp1=roundUp(1.17*exp1);
            checkM(m1);
            checkHP(hp1);
            checkEXP(exp1);
            return pathOne(exp1);
        }
        event2(exp1, m1);
        if (m1<=0){
            hp1=roundUp(0.83*hp1);
            exp1=roundUp(1.17*exp1);
            checkM(m1);
            checkHP(hp1);
            checkEXP(exp1);
            return pathOne(exp1);
        }
        event3(exp1, m1);
        if (m1<=0){
            hp1=roundUp(0.83*hp1);
            exp1=roundUp(1.17*exp1);
            checkM(m1);
            checkHP(hp1);
            checkEXP(exp1);
            return pathOne(exp1);
        }
    }
    hp1=roundUp(0.83*hp1);
    exp1=roundUp(1.17*exp1);
    checkHP(hp1);
    checkEXP(exp1);
    checkM(m1);
    return pathOne(exp1);
}
//Calculate P of path 3
double pathThree(int e2){
    double P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (e2/10<1){
        return (P[e2]);
    } 
    return (P[(e2/10+e2%10)%10]);
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (!checkE(E2)){
        return -99;
    }
    checkHP(HP1);
    checkEXP(EXP1);
    checkM(M1);
    double P1, P2, P3, Avg;
    P1=pathOne(EXP1); //go through path 1
    P2=pathTwo(HP1, EXP1, M1, E2); //go through path 2
    P3=pathThree(E2); //go through path 3
    //if all 3 P are 100%, Sherlock is wrong and his EXP changes
    if (P1==100&&P2==100&&P3==100){
        EXP1=roundUp(EXP1*0.75);
        checkEXP(EXP1);
    } else {
        Avg=(P1+P2+P3)/3;
        if (Avg<50){
            HP1=roundUp(0.85*HP1);
            EXP1=roundUp(1.15*EXP1);
            checkHP(HP1);
            checkEXP(EXP1);
        } else {
            HP1=roundUp(0.9*HP1);
            EXP1=roundUp(1.2*EXP1);
            checkHP(HP1);
            checkEXP(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}
//Task 3
//Find the maximum num on the left diagonal line
int findMaxLeft(int r, int c, int taxiMatrix[][10]){
    int M=taxiMatrix[r][c];
    //Jump Down to the last Row/Column
    while (r!=9&&c!=9){
        r++;
        c++;
    }
    //After Jump Down, Check Up to the first Row/Column to get the Max
    while (r!=0&&c!=0)
    {
        M=max(M, taxiMatrix[r][c]);
        r--;
        c--;
    }
    return M;
}
//Find the maximum num on the right diagonal line
int findMaxRight(int r, int c, int taxiMatrix[][10]){
    int M=taxiMatrix[r][c];
    //Jump Down to the last Row/the firs Column
    while (r!=9&&c!=0){
        r++;
        c--;
    }
    //After Jump Down, Check Up to the first Row/the last Column
    while (r!=0&&c!=9)
    {
        M=max(M, taxiMatrix[r][c]);
        r--;
        c++;
    }
    return M;
}
//Find the meeting Row of the taxi and Sherlock
int findMeetingRow(int taxiMatrix[][10], int e3){
    int i=0; //the number of position that is larger than e3*2
    for (int r=0; r<=9; r++){
        for (int c=0; c<=9; c++){
            if (taxiMatrix[r][c]>(e3*2)){
                i++;
            }
        }
    }
    while (i>=10){
        i=(i/10+i%10);
    }
    return i;
}
//Find the meeting Columns of the taxi and Sherlock
int findMeetingColumn(int taxiMatrix[][10], int e3){
    int j=0; //the number of position that is larger than e3*2
    for (int r=0; r<=9; r++){
        for (int c=0; c<=9; c++){
            if (taxiMatrix[r][c]<(-1*e3)){
                j++;
            }
        }
    }
    while (j>=10){
        j=(j/10+j%10);
    }
    return j;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (!checkE(E3)){
        return -99;
    }
    checkEXP(EXP1);
    checkEXP(EXP2);
    checkHP(HP1);
    checkHP(HP2);
    int taxiMatrix[10][10]={0};
    int swMatrix[10][10], i, j;
    for (int r=0; r<=9; r++){
        for (int c=0; c<=9; c++){
            if (r==0&&c==0){
                continue;
            }
            taxiMatrix[r][c]=(((E3*c)+(r*2))*(r-c));
        }
    }
    for (int c=0; c<=9; c++){
        for (int r=0; r<=9; r++){
            swMatrix[r][c]=max(findMaxLeft(r, c, taxiMatrix), findMaxRight(r, c, taxiMatrix));
            if (swMatrix[r][c]<0){
                swMatrix[r][c]=abs(swMatrix[r][c]);
            }
        }
    }
    i=findMeetingRow(taxiMatrix, E3);
    j=findMeetingColumn(taxiMatrix, E3);
    if (abs(taxiMatrix[i][j])>swMatrix[i][j]){
        EXP1=roundUp(EXP1*0.88);
        EXP2=roundUp(EXP2*0.88);
        HP1=roundUp(HP1*0.9);
        HP2=roundUp(HP2*0.9);
        checkEXP(EXP1);
        checkEXP(EXP2);
        checkHP(HP1);
        checkHP(HP2);
        return taxiMatrix[i][j];
    } else {
        EXP1=roundUp(EXP1*1.12);
        EXP2=roundUp(EXP2*1.12);
        HP1=roundUp(HP1*1.1);
        HP2=roundUp(HP2*1.1);
        checkEXP(EXP1);
        checkEXP(EXP2);
        checkHP(HP1);
        checkHP(HP2);
        return swMatrix[i][j]; 
        //because all elements in swMatrix is >= 0 so we don't need to get the abs
    }
    return -1;
}
// Task 4
//Check the length of the password
int checkLength(string s){
    if (s.length()<8){
        return -1;
    }
    if (s.length()>20){
        return -2;
    }
    return -10; //this means s satisfied this condition
}
//Check each character is valid or not
int checkValidChar(string s){
    for (int i=0; i<s.length(); i++){
        if (isdigit(s[i])){
            continue;
        }
        if (isalpha(s[i])){
            continue;
        }
        if (s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!'){
            continue;
        }
        return i;
    }
    return -10; //this means s satisfied this condition 
}
//Check if the password contains se or not
int checkSe(string s, string se){
    int i=0, j=0;
    for (int i=0; i<s.length(); i++){
        if (s[i]==se[j]){
            j++;
        } else {
            i=i-j;
            j=0;
        }
        if (j==se.length()){
            return (i-j+1);
        }
    }
    return -10; //this means s satisfied this condition
}
//Check if the password have more than 2 consecutive characrer
int checkConseChar(string s){
    for (int i=0; i<=(s.length()-3); i++){
        if (s[i]==s[i+1]&&s[i+1]==s[i+2]){
            return i;
        }
    }
    return -10; //this means s satisfied this condition
}
//Check if the password contain special character or not
int checkSpeChar(string s){
    for (int i=0; i<s.length(); i++){
        if (s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!'){
                return -10; //this means the password contains special character
            }
    }
    return -5; //this means the password does not contain special character
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    //string S=s, Email=email;
    int i;
    for (i=0; i<=100; i++){
        if (email[i]=='@'){
            break;
        }
    }
    string se(email, 0, i);
    if (checkLength(s)==-1){
        return checkLength(s);
    }
    if (checkLength(s)==-2){
        return checkLength(s);
    }
    if (checkSe(s, se)!=-10){
        if (i==0){
        return -300;
        }
        return (-300-checkSe(s, se));
    }
    if (checkConseChar(s)!=-10){
        return (-400-checkConseChar(s));
    }
    if (checkSpeChar(s)==-5){
        return checkSpeChar(s);
    }
    if (checkValidChar(s)!=-10){
        return checkValidChar(s);
    }
    return -10; //this means the password is valid
}
// Task 5
//To check if the 2 strings are the same or not, we use strcmp

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxPlace=0;
    const int num=num_pwds;
    int time[num];
    for (int i=0; i<num_pwds; i++){
        time[i]=0;
    }
    for (int i=0; i<num_pwds; i++){
        for (int j=i+1; j<num_pwds; j++){
            if (strcmp(arr_pwds[i], arr_pwds[j])==0){
                time[i]++;
            }
        }
        if (i!=0){
            if (time[i]<time[maxPlace]){
                continue;
            }
            if (time[i]>time[maxPlace]){
                maxPlace=i;
                continue;
            }
            if (strlen(arr_pwds[i])>strlen(arr_pwds[maxPlace])){
                maxPlace=i; 
            } 
            //when this if not occur, the length of i is smaller or = the length of the arr_pwds[maxPlace]
            /*because maxPlace will always <= i so if the length is smaller of =
             the function will return the one appear first, which is maxPlace*/
        }
    }
    return maxPlace;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////