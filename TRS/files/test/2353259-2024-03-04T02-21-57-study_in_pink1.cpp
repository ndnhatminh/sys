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

//round up
void roundUp (double &a){
   int b;
   b=round(a);
   if (a<=b)
        a=b;
   else
        a=b+1;
}

//check condition
void checkEXPint (int &EXP){
    
    if (EXP<0)
        EXP=0;
    if (EXP>600)
        EXP=600;
}

void checkEXPdou (double &EXP){
    roundUp(EXP);
    if (EXP<0)
        EXP=0;
    if (EXP>600)
        EXP=600;
}

void checkHPdou (double &HP){
    roundUp(HP);
    if (HP<0)
        HP=0;
    if (HP>666)
        HP=666;
}

void checkHPint (int &HP){
    if (HP<0)
        HP=0;
    if (HP>666)
        HP=666;
}

void checkMdou (double &M){
    roundUp(M);
    if (M<0)
        M=0;
    if (M>3000)
        M=3000;
}

void checkMint (int &M){
    if (M<0)
        M=0;
    if (M>3000)
        M=3000;
}


// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    
    double sD,sEXP1,sEXP2;
    checkEXPint(EXP1);
    checkEXPint(EXP2);
    
    //case 1
    sEXP1=(double)EXP1;
    if (E1<0 || E1>99)
        return -99;
    if (E1>=0 && E1<=3) {
        if (E1==0)
            EXP2+=29;
        else if (E1==1)
            EXP2+=45;
        else if (E1==2)
            EXP2+=75;
        else
            EXP2+=(29+45+75);
        checkEXPint(EXP2);
        int D=E1*3+EXP1*7;
        sD=(double)D;
        if (D%2==0)
            sEXP1+=sD/200;
        else
            sEXP1-=sD/100;
        checkEXPdou(sEXP1);
        EXP1=(int)sEXP1;
    }
    
    //case 2
    else if (E1<=99) {
        sEXP2=(double)EXP2;
        if (E1<=19)       //E1 = [4;19]  info1
            sEXP2+=(double)E1/4+19;
        else if (E1<=49)  //E1 = [20;49] info2
            sEXP2+=(double)E1/9+21;
        else if (E1<=65)  //E1 = [50;65] info3
            sEXP2+=(double)E1/16+17;
        else if (E1<=79) {  //E1 = [66;79] info4
            sEXP2+=(double)E1/4+19;   //Sherlock explains info1
            checkEXPdou(sEXP2);
            if (sEXP2>200)  //if EXP2>200 --> continues info2
                sEXP2+=(double)E1/9+21;
        }
        else  {             //E1 = [80;99] info 5
            sEXP2+=(double)E1/4+19;   //explain info1
            checkEXPdou(sEXP2);
            sEXP2+=(double)E1/9+21;  //explain info2
            checkEXPdou(sEXP2);
            if (sEXP2>400) { //if EXP2>400 --> continues info3 --> explain all 3 infos
                sEXP2+=(double)E1/16+17;
                checkEXPdou(sEXP2);
                sEXP2*=1.15; //--> add 15% of current EXP2
                checkEXPdou(sEXP2);
            }
        }
        checkEXPdou(sEXP2);
        EXP2=sEXP2;
        EXP1-=E1;
        checkEXPint(EXP1);//Sherlock's mistake --> EXP1 is reduced by an amount of E1
    }
    
    return EXP1 + EXP2;
}

// Task 2
//find the nearest perfect square
int nearestSquare(double EXP1) {
    double n = sqrt(EXP1);
    double up=round(n+0.5), down=round(n-0.5);
    if (up*up-EXP1 > EXP1-down*down)
        return down*down;
    else
        return up*up;
}

void groceryStore(double &sHP1, int &M1, int&paidM1){
    if (sHP1<200) {
        sHP1*=1.3;
        checkHPdou(sHP1);
        M1-=150;
        paidM1+=150;
    }
    else {
        sHP1*=1.1;
        checkHPdou(sHP1);
        M1-=70;
        paidM1+=70;
    }
    checkMint(M1);
}

void rentCar(double &sEXP1, int &M1, int&paidM1){
    if (sEXP1<400) {
        M1-=200;
        paidM1+=200;
    }
    else {
        M1-=120;
        paidM1+=120;
    }
    checkMint(M1);
    sEXP1*=1.13;
    checkEXPdou(sEXP1);
}

void metHomeless(double &sEXP1, int &M1, int &paidM1){
    if (sEXP1<300) {
        M1-=100;
        paidM1+=100;
    }
    else {
        M1-=120;
        paidM1+=120;
    }
        checkMint(M1);
        sEXP1*=0.9;
        checkEXPdou(sEXP1);
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    double P1=0,P2=0,P3=0,finalP=0;
    checkHPint(HP1); checkEXPint(EXP1); checkMint(M1);
    
    double sHP1=(double)HP1;
    double sEXP1=(double)EXP1;
    if (E2<0 || E2>99)
        return -99;
    else {
        //road1: calculate P1
        if (EXP1>=nearestSquare(sEXP1))
            P1=1;
        else
            P1=(sEXP1/nearestSquare(sEXP1)+80)/123;
            
        //road2
        double temp=(double)M1*0.5;
        int paidM1=0;
        
        //if E2 is odd
        if (E2%2!=0) {
            while (paidM1 <= temp) {
                groceryStore(sHP1,M1,paidM1);
                //check if paid money is greater than 50% the total
                if (paidM1 <= temp) {
                    // rent a taxi or carriage
                    rentCar(sEXP1,M1,paidM1);
                    if (paidM1 <= temp) {
                        //met a homeless person
                        metHomeless(sEXP1,M1,paidM1);
                        continue;
                    }
                    else break;
                }
                else break;
            }
        }
        //if E2 is even
        else {
            if (M1<=0) M1=0;
            else {
                groceryStore(sHP1,M1,paidM1);
                if (M1<=0) M1=0;
                else {
                    rentCar(sEXP1,M1,paidM1);
                    
                    // if budget is under 0
                    if (M1<=0)
                        M1=0;
                    // if there is still money --> plus EXP & do next action
                    else {
                    //met a homeless person
                        metHomeless(sEXP1,M1,paidM1);
                        // if budget is under 0
                        if (M1<=0) M1=0;
                    }
                }
            }
            //updating HP1 & EXP1
        }
        sHP1*=0.83; checkHPdou(sHP1);
        sEXP1*=1.17; checkEXPdou(sEXP1);
        EXP1=(int)sEXP1;
        //calculate P2
        if (EXP1>=nearestSquare(sEXP1))
            P2=1;
        else
            P2=((double)EXP1/nearestSquare(sEXP1)+80)/123;
    }
        //road 3
        int arP[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        // if E2 is 1 one digit
        if (E2<10) P3=(double)arP[E2]/100;
        //if E2 is 2 digit
        else {
            int i=E2/10;
            int j=i+(E2-i*10);
            if (j<10)
                P3=(double)arP[j]/100;
            else {
                int k=j/10;
                P3=(double)arP[j-k*10]/100;
            }
        }
        //check P1 P2 P3
        if (P1==1 && P2==1 && P3==1) {
            sEXP1*=0.75;
            checkEXPdou(sEXP1);
        }
        else
            finalP=(P1+P2+P3)/3;
        
        //check the average
        if (finalP<0.5) {
            sHP1*=0.85;
            sEXP1*=1.15;
        }
        else {
            sHP1*=0.9;
            sEXP1*=1.2;
        }
        checkHPdou(sHP1);
        checkEXPdou(sEXP1);
        HP1=(int)sHP1;
        EXP1=(int)sEXP1;
    return HP1 + EXP1 + M1;
}

// Task 3
int oneDigit(int n) {
    if (n<10)
        return n;
    else {
        int m=n/10;
        return oneDigit(n-m*10+m);
    }
}

int leftDiagonal(int arr[][10], int i, int j) {
    int maxL=0;
    while (i>=0 && j>=0) {
        maxL=max(maxL,arr[i][j]);
        i--;
        j--;
    }
    i++;
    j++;
    while (i<10 && j<10) {
        maxL=max(maxL,arr[i][j]);
        i++;
        j++;
    }
    return maxL;
}

int rightDiagonal(int arr[][10], int i, int j) {
    int maxR=0;
    while (i<10 && j>=0) {
        maxR=max(maxR,arr[i][j]);
        i++;
        j--;
    }
    i--;
    j++;
    while (i>=0 && j<10) {
        maxR=max(maxR,arr[i][j]);
        i--;
        j++;
    }
    return maxR;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    double sHP1=(double)HP1;
    double sEXP1=(double)EXP1;
    double sHP2=(double)HP2;
    double sEXP2=(double)EXP2;
    
    int counti=0, countj=0,result=0;
    if (E3<0 || E3>99)
        return -99;
    else {
        int arrTaxi[10][10];
        for (int i=0; i<10; i++)
            for (int j=0; j<10; j++) {
                arrTaxi[i][j]=((E3*j + i*2)*(i-j));
                if (arrTaxi[i][j] > E3*2)
                    counti++;
                if (arrTaxi[i][j] < -E3)
                    countj++;
            }
        
        int arrPoint[10][10];
        for (int i=0; i<10; i++)
            for (int j=0; j<10; j++) {
                arrPoint[i][j]=max(leftDiagonal(arrTaxi, i, j),rightDiagonal(arrTaxi, i, j));
            }
        
        int iMeet=oneDigit(counti);
        int jMeet=oneDigit(countj);
        
        if (abs(arrTaxi[iMeet][jMeet]) > arrPoint[iMeet][jMeet]) {
            sEXP1*=0.88; checkEXPdou(sEXP1);
            sEXP2*=0.88; checkEXPdou(sEXP2);
            sHP1*=0.9; checkHPdou(sHP1);
            sHP2*=0.9; checkHPdou(sHP2);
            EXP1=(int)sEXP1;
            EXP2=(int)sEXP2;
            HP1=(int)sHP1;
            HP2=(int)sHP2;
            return arrTaxi[iMeet][jMeet];
        }

        else {
            sEXP1*=1.12; checkEXPdou(sEXP1);
            sEXP2*=1.12; checkEXPdou(sEXP2);
            sHP1*=1.1; checkHPdou(sHP1);
            sHP2*=1.1; checkHPdou(sHP2);
            EXP1=(int)sEXP1;
            EXP2=(int)sEXP2;
            HP1=(int)sHP1;
            HP2=(int)sHP2;
            return arrPoint[iMeet][jMeet];
        }
    }
    return -1;
}

// Task 4

bool includeSE(string s, string se, int &sei){
    int size=se.length();
    for (int i=0; i<s.length(); i++) {
        if (s[i]==se[0]) {
            string temp(s,i,size);
            if (temp==se) {
                sei=i;
                return true;
            }
            else
                continue;
        }
        else
            continue;
    }
    return false;
}

bool sameChar(string s, int &sci){
    for (int i=0; i<(s.length()-2); i++) {
        if (s[i]==s[i+1] && s[i]==s[i+2]) {
            sci=i;
            return true;
        }
        else
            continue;
    }
    return false;
}

bool isNumber(char a){
    if (a>='0' && a <='9')
        return true;
    else
        return false;
}

bool isChar(char a){
    if ((a>='a' && a<='z') || (a>='A' && a<='Z'))
        return true;
    else
        return false;
}

bool isSpecial(char a){
    if (a=='@' || a=='#' || a=='%' || a=='$' || a=='!')
        return true;
    else
        return false;
}

bool notSpecialChar(string s) {
    for (int i=0; i<s.length(); i++) {
        char a=s[i];
        if (isSpecial(a))
            return false;
        else
            continue;
    }
    return true;
}

bool invalidChar(string s, int &count){
    for (int i=0; i<s.length(); i++) {
        char a=s[i];
        if (!isNumber(a) && !isChar(a) && !isSpecial(a)) {
            count=i;
            return true;
        }
        else
            continue;
    }
    return false;
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string ss, semail;
    ss = (string)s;
    semail = (string)email;
    
    int n=0, sei=0, sci=0, count=0;
    
    for (int i=0; i<semail.length(); i++) {
        char temp=semail[i];
        if (temp == '@') {
            n=i;
            break;
        }
    }
    string se=semail.substr(0,n);
    
    if (ss.length()<8)
        return -1;
    else if (ss.length()>20)
        return -2;
    else if (includeSE(ss, se, sei))
        return (-(300+sei));
    else if (sameChar(ss, sci))
        return (-(400+sci));
    else if (notSpecialChar(ss))
        return -5;
    else if (invalidChar(ss, count))
        return count;
    else
        return -10;

    return -99;
}

// Task 5

int findMax(int arr[], int size){
    int maxNum=0;
    for (int i=0; i<size; i++)
        maxNum=max(maxNum,arr[i]);
    return maxNum;
}

bool onlyMax(int arr[], int size){
    int maxNum = findMax(arr, size);
    int count=0;
    for (int i=0; i<size; i++)
        if (maxNum==arr[i])
            count++;
        else
            continue;
    
    if (count==1)
        return true;
    else
        return false;
}

int findIndex(int arr[], int size, int num){
    int index;
    for (int i=0; i<size; i++)
        if (num==arr[i]) {
            index=i;
            return index;
            break;
        }
    return 0;
}

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int arrAppear[num_pwds], arrSize[num_pwds];
    string arrPass[num_pwds];
    for (int i = 0; i < num_pwds; i++){
        arrPass[i] = (string)arr_pwds[i];
    }
    int maxNum=0;
    
    //size
    for (int i=0; i<num_pwds; i++) {
        string temp=arrPass[i];
        arrSize[i]=temp.length();
    }
    
    //initialize arrAppear
    for (int i=0; i<num_pwds; i++)
        arrAppear[i]=0;
    
    //count appearance
        for (int i=0; i<num_pwds; i++)
            for (int j=i+1; j<num_pwds; j++)
                if (arrPass[i] == arrPass[j]) {
                    arrAppear[i]++;
            }
    
    //
    if (onlyMax(arrAppear, num_pwds)) {
        int maxNum = findMax(arrAppear, num_pwds);
        return findIndex(arrAppear, num_pwds, maxNum);
    }
    
    else {
        int maxNum = findMax(arrSize, num_pwds);
        return findIndex(arrSize, num_pwds, maxNum);
    }
    
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
