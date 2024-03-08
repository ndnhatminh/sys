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
int checkChar(char x, int j){
    int class1 = 0;
    if(48 <= x && x <= 57 ){
        class1=1;
    }
    if(64 < x && x <= 90){
        class1=1;
    }
    if(97 <= x && x <= 122){
        class1=1;
    }
    if(x == 64 ){
        class1=2;
    }
    if ( x == 33 ){
        class1=2;
    }
    if ( 35 <= x && x <= 37 ){
        class1=2;
    }
    if(class1 == 2) return -1;
    if(class1 == 1) return -2;
    return j;
}
int turnunitRow(int x){
    while (x >= 10) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        x = sum;
    }
    return x;
}
int leftCross(int y, int x, int a[10][10]){
    int biggestofleftCross = 0;
    for(int u = 0; u <= 9;u++)
    {
        if ( 0 <= (y-x+u) && (y-x+u) <= 9 ){
            if (a[u][y-x+u]>= biggestofleftCross)
                biggestofleftCross=a[u][y-x+u];
        }
    }
    return abs(biggestofleftCross);
}
int rightCross(int y, int x, int a[10][10]){
    int biggestofrightCross=0;
    for(int u = 0; u<= 9; u++ )
    {
        if (0 <= (x+y-u) && (x+y-u) <=9 )
            {
                if (a[u][x+y-u]>= biggestofrightCross)
                biggestofrightCross = a[u][x+y-u];

            }
    }
    return abs(biggestofrightCross);
}
int findNearestSquare(int &EXP1) {
    int lowerSquareRoot = static_cast<int>(sqrt(EXP1));
    int lowerSquare = lowerSquareRoot * lowerSquareRoot;
    int upperSquare = (lowerSquareRoot + 1) * (lowerSquareRoot + 1);

    if (abs(EXP1 - lowerSquare) <= abs(EXP1 - upperSquare)) {
        return lowerSquare;
    } else {
        return upperSquare;
    }
}
void setLimits(int &variable, int lowerLimit, int upperLimit) {
    if (variable < lowerLimit) {
        variable = lowerLimit;
    }
    if (variable > upperLimit) {
        variable = upperLimit;
    }
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int d=0;
    if (e1 < 0 || 99 < e1 ) return -99;
    setLimits(exp1, 0, 600);
    setLimits(exp2, 0, 600);
    if (0 <= e1 && e1 <= 3 ){
        switch (e1) {
        case 0:
            exp2 += 29;
            setLimits(exp2, 0, 600);
            break;
        case 1:
            exp2 += 45;
            setLimits(exp2, 0, 600);
            break;
        case 2:
            exp2 += 75;
            setLimits(exp2, 0, 600);
            break;
        case 3:
            exp2 += 149;
            setLimits(exp2, 0, 600);
            break;
        }
        d = e1*3 + exp1*7;
        if( d%2 == 0 ) {
                exp1 = ceil(exp1 + d/200.00);
                setLimits(exp1, 0, 600);

        }
        else {
                exp1=ceil( exp1 - d/100.00);
                setLimits(exp1, 0, 600);
        }
     }
     if ( 4 <= e1 && e1 <= 99){
        if ( 4 <= e1 && e1 <= 19 ) {
                exp2 = ceil(exp2 + (e1/4.00 + 19));
                setLimits(exp2, 0, 600);
        }
        else if ( 20 <= e1 && e1 <= 49 ) {
                exp2 = ceil( exp2 + e1/9.00 +21);
                setLimits(exp2, 0, 600);
        }
        else if ( 50 <= e1 && e1 <= 65 ) {
                exp2 = ceil( exp2 + e1/16.00 +17);
                setLimits(exp2, 0, 600);

        }
        else if ( 66 <= e1 && e1 <= 79 ) {
            exp2= ceil(exp2 + (e1/4.00 + 19));
            setLimits(exp2, 0, 600);
            if (exp2 > 200) {
                exp2 = ceil( exp2 + e1/9.00 +21);
                setLimits(exp2, 0, 600);
            }
        }
        else if ( 80 <= e1 && e1 <= 99 ) {
            exp2 = ceil( exp2 + (e1/4.00 + 19));
            setLimits(exp2, 0, 600);
            exp2 = ceil( exp2 + (e1/9.00 +21));
            setLimits(exp2, 0, 600);
            if ( exp2 > 400 )  {
                exp2 = ceil( exp2 + e1/16.00 +17);
                setLimits(exp2, 0, 600);
                exp2 = ceil( exp2 + exp2*(0.15));
                setLimits(exp2, 0, 600);

            }
        }
        exp1 -= e1;
        setLimits(exp1, 0, 600);
     }
    setLimits(exp1, 0, 600);
    setLimits(exp2, 0, 600);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99 ) return -99;
    setLimits(HP1, 0, 666);
    setLimits(EXP1, 0, 600);
    setLimits(M1, 0, 3000);
    double P1=0, P2=0, P3=0;
    int checkPoint=0;
    int sumofMoney = 0;
    double S=findNearestSquare(EXP1);
    if (EXP1 >= S) P1=1.00;
    else P1 = ((double)EXP1/S + 80 )/123.00;
    if ( E2%2 != 0 ) {
        int j=M1;
        while (sumofMoney < j/2.00) {
                if ( HP1 < 200 ) {
                        HP1 = ceil(HP1+HP1*0.3);
                        M1 -= 150;
                        sumofMoney +=150;
                        setLimits(HP1, 0, 666);
                        setLimits(EXP1, 0, 600);
                }
                else  {
                    HP1 = ceil(HP1+HP1*0.1);
                    M1 -= 70;
                    sumofMoney+=70;
                    setLimits(HP1, 0, 666);
                    setLimits(EXP1, 0, 600);
                }
                if (sumofMoney > j/2.00) break;
                if (EXP1 < 400) {
                    M1 -= 200;
                    sumofMoney +=200;
                }
                else {
                    M1 -= 120;
                    sumofMoney += 120;
                }
                EXP1 = ceil(EXP1+EXP1*0.13);
                setLimits(EXP1, 0, 600);
                if (sumofMoney > j/2.00) break;
                if ( EXP1 < 300 ) {
                    M1 -= 100;
                    sumofMoney += 100;                }
                else {
                    M1 -= 120;
                    sumofMoney += 120;
                }
                EXP1 = ceil(EXP1 - EXP1*0.1);
                setLimits(EXP1, 0, 600);
                if (sumofMoney > j/2.00) break;
            }
        HP1 = ceil(HP1 - HP1*0.17);
        EXP1 = ceil(EXP1 + EXP1*0.17);
        setLimits(HP1, 0, 666);
        setLimits(EXP1, 0, 600);
    }
    else {
            if ( HP1 < 200 && checkPoint!=1) {
                    HP1 = ceil(HP1+HP1*0.3);
                    setLimits(HP1, 0, 666);
                    M1 -= 150;
                    if (M1 <= 0) {
                        checkPoint=1;
                    }
            }
            else {
                HP1 = ceil(HP1+HP1*0.1);
                setLimits(HP1, 0, 666);
                M1 -= 70;
                if (M1 <= 0) {
                        checkPoint=1;
                    }

            }
            if (EXP1 < 400 && checkPoint!=1) {
                M1 -= 200;
                EXP1 = ceil(EXP1+EXP1*0.13);
                if (M1 <= 0) {
                        checkPoint=1;
                    }
            }
            else {
                if(checkPoint!=1){
                    M1 -= 120;
                    EXP1 = ceil(EXP1+EXP1*0.13);
                    if (M1 <= 0) {
                            checkPoint=1;
                        }
                }
            }
            setLimits(EXP1, 0, 600);
            if ( EXP1 < 300 && checkPoint!=1) {
                EXP1 = ceil(EXP1 - EXP1*0.1);
                M1 -= 100;
                if (M1 <= 0) {
                        checkPoint=1;
                    }
            }
            else {
                    if(checkPoint!=1){
                        EXP1 = ceil(EXP1 - EXP1*0.1);
                        M1 -= 120;
                        if (M1 <= 0) {
                                checkPoint=1;
                            }
                    }
            }

            HP1 = ceil(HP1 - HP1*0.17);
            EXP1 = ceil(EXP1 + EXP1*0.17);
            setLimits(HP1, 0, 666);
            setLimits(EXP1, 0, 600);
        }
    S=findNearestSquare(EXP1);
    if (EXP1 >= S) P2=1.00;
    else P2 = ((double)EXP1/S + 80 )/123.00;
    int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (0 <= E2 && E2 <= 9 ) P3=P[E2]/100.00;
    else {
        int s=E2;
        s = s/10 + s%10;
        if(s>10) s%=10;
        P3=P[s]/100.00;
    }
    if ( P1 == 1 && P2 == 1 && P3 == 1 ) {
            EXP1 = ceil(EXP1-EXP1*0.25);
            setLimits(EXP1, 0, 600);

    }
    else{
        double ss = (P1+P2+P3)/3.00;
        if ( ss < 0.5 ) {
            HP1 = ceil(HP1 - HP1*0.15);
            EXP1 = ceil(EXP1+ EXP1*0.15);
            setLimits(HP1, 0, 666);
            setLimits(EXP1, 0, 600);
        }
        else {
            HP1 = ceil(HP1 - HP1*0.1);
            EXP1 = ceil(EXP1 + EXP1*0.2);
            setLimits(HP1, 0, 666);
            setLimits(EXP1, 0, 600);
        }
    }
    setLimits(HP1, 0, 666);
    setLimits(EXP1, 0, 600);
    setLimits(M1, 0, 3000);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    setLimits(HP1, 0, 666);
    setLimits(EXP1, 0, 600);
    setLimits(HP2, 0, 666);
    setLimits(EXP2, 0, 600);
    if(E3 < 0 || E3 > 99) return -99;
    int a[10][10]={0};
    int b[10][10]={0};
    for (int i = 0; i<=9;i++)
    {
        for(int j=0; j <= 9; j++)
        {
            a[i][j] = ((E3 * (j)) + (i * 2)) * (i - j);
        }
    }
    for(int i = 0; i <= 9; i++)
    {
        for(int j = 0; j<=9; j++)
        {
            if (abs(leftCross(i, j, a)) > abs(rightCross(i, j, a))) b[j][i]= abs(leftCross(i, j, a));
            else b[j][i] = abs(rightCross(i, j, a));
        }
    }
    int countpossitive=0;
    int countnegative=0;
    for (int i = 0; i<=9;i++)
    {
        for(int j=0; j <= 9; j++)
        {
            if(a[i][j] > (E3*2) ) countpossitive++;
            if(a[i][j] < -(E3)) countnegative++;
        }
    }
    countnegative=turnunitRow(countnegative);
    countpossitive=turnunitRow(countpossitive);
    if(abs(a[countpossitive][countnegative]) > abs(b[countpossitive][countnegative])) {
            EXP1=ceil(EXP1 - EXP1*0.12);
            HP1=ceil(HP1-HP1*0.1);
            EXP2=ceil(EXP2 - EXP2*0.12);
            HP2=ceil(HP2 - HP2*0.1);
            setLimits(HP1, 0, 666);
            setLimits(EXP1, 0, 600);
            setLimits(HP2, 0, 666);
            setLimits(EXP2, 0, 600);
            return a[countpossitive][countnegative];
    }
    else  {
            EXP1=ceil(EXP1 + EXP1*0.12);
            HP1=ceil(HP1 + HP1*0.1);
            EXP2=ceil(EXP2 + EXP2*0.12);
            HP2=ceil(HP2 + HP2*0.1);
            setLimits(HP1, 0, 666);
            setLimits(EXP1, 0, 600);
            setLimits(HP2, 0, 666);
            setLimits(EXP2, 0, 600);
            return b[countpossitive][countnegative];
    }
}
//task3 still missing check condition of each varible
// Task 4
int checkPassword(const char * s, const char * email) {
        // TODO: Complete this function
    int checkPoint = 0;
    for(int i = 0; email[i] != '\0' ; i++)
    {
        if(email[i]=='@') checkPoint=i;
    }
    char se[checkPoint + 1];
    strncpy(se, email, checkPoint);
    se[checkPoint] = '\0'; // Null-terminate the destination string
    //kiem tra do dai
    int length = strlen(s);
    if (length < 8) return -1;
    if (length > 20) return -2;
    //kiem tra s co chua trong email khong
    const char* checkS = strstr(s, se);
    if (checkS != nullptr ) {
       ptrdiff_t differinPointer = (checkS - s);
       checkPoint = -(300 + static_cast<int>(differinPointer));
       return checkPoint;
    }
    //kiem tra tu 3 ky tu lien tiep
    int possitionContinuous=0;
    for (int i = 1; i < strlen(s) - 1; ++i) {
        if (s[i-1] == s[i] && s[i] == s[i+1] ){
            possitionContinuous=-(400 +(i-1));
            break;
        }
    }
    if(possitionContinuous != 0) return possitionContinuous;
    //kiem tra co chua ky tu dac biet khong ket hop kiem tra xem coi ky tu co phu hop khong
    int checkktDb = 0;
    int checkKyTu = -1;
    for (int i=0; i < strlen(s); i++)
    {
        if(checkChar(s[i], i) == -1) checkktDb = 1;
        if(checkChar(s[i], i) == -2) checkKyTu = -1;
    }
    for (int i=0; i < strlen(s); i++)
    {
        if(checkChar(s[i], i) >= 0) {
                checkKyTu=i;
                break;
        }
    }
    if(checkktDb != 1) return -5;
    else if(checkKyTu >= 0) return checkKyTu;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
int countPass = 0, v = 0;
    int position = 0, lastPosition = 0;
    const char* pwdsCorrect = nullptr;
    const char* pwdsMostCorrect = nullptr;

    for (int i = 0; i < num_pwds; i++)
    {
        for (int j = 0; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                countPass++;
                pwdsCorrect = arr_pwds[i];
                position = i;
            }
        }

        if (countPass > v)
        {
            v = countPass;
            pwdsMostCorrect = pwdsCorrect;
            lastPosition = position;
        }
        else if (countPass == v)
        {
            if (strlen(pwdsMostCorrect) < strlen(pwdsCorrect))
            {
                lastPosition = position;
                pwdsMostCorrect = pwdsCorrect;
            }
        }

        countPass = 0;
    }

    return lastPosition;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
