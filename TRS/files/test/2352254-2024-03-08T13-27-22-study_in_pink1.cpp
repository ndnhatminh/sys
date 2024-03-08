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
void checkmax(int &a, int b){
    if (a>=b){
        a=b;
    }
}
void checkmin(int &c, int d){
    if(c<=d){
        c=d;
    }
}
int maxexp=600;
int minexp=0;
int maxhp=666;
int minhp=0;
int maxM=3000;
int minM=0;
// Task 1
int firstMeet(int & exp1, int & exp2, int e1)
{
    if ( e1>=0 && e1<= 3) {
        checkmax(exp1,maxexp);
        checkmax(exp2,maxexp);
        checkmin(exp1,minexp);
        checkmin(exp2,minexp);
        if (e1 == 0) {
            exp2 += 29;
        } else if (e1 == 1) {
            exp2 += 45;
        } else if (e1 == 2) {
            exp2 += 75;
        } else if (e1 == 3) {
            exp2 += 149;
        }
        checkmax(exp2,maxexp);
        int d;
        d = e1 * 3 + exp1 * 7;
        if (d % 2 == 0) {
            exp1 =  (exp1+(double)d / 200.00) +0.999;
        } else {
            exp1 = (exp1- (double) d / 100.00) +0.999;
        }
        checkmax(exp1,maxexp);
        checkmin(exp1,minexp);
    }
    else if (e1>3&&e1<=99){
        checkmax(exp1,maxexp);
        checkmax(exp2,maxexp);
        checkmin(exp1,minexp);
        checkmin(exp2,minexp);
        if (e1 < 20) {
            exp2 =  exp2 + ((double) e1 / 4.00 + 19) +0.999;
        } else if (e1 <= 49) {
            exp2 =   exp2+ ((double) e1 / 9.00 + 21)+0.999;
        } else if (e1 <= 65) {
            exp2 = exp2+((double) e1 / 16.00 + 17+0.999);
        } else if (e1 <= 79) {
            exp2 +=  ((double) e1 / 4.00 + 19)+0.999;
            if (exp2 > 200) {
                exp2 = exp2+((double) e1 / 9.00 + 21)+0.999;
            }
        } else {
            exp2 = exp2+ ((double)e1 / 4 + 19)+0.999;
            exp2 = exp2+ ((double) e1 / 9.00 + 21)+0.999;
            if (exp2 > 400) {
                exp2 =exp2+  ((double) e1 / 16.00 + 17)+0.999;
                exp2 = 1.15 * exp2 +0.999;
            }
        }

        exp1-=e1;
        checkmax(exp1,maxexp);
        checkmax(exp2,maxexp);
        checkmin(exp1,minexp);
        checkmin(exp2,minexp);}
    else {return -99;}


    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // Con duong thu 1
    if(E2<0||E2>99){
        return-99;
    }
    int S1,S2;
    float P,P1,P2,money;
    checkmax(HP1,maxhp);
    checkmin(HP1,minhp);
    checkmax(EXP1,maxexp);
    checkmin(EXP1,minexp);
    checkmax(M1,maxM);
    checkmin(M1,minM);
    S1 = round(sqrt(EXP1));
    S1 *= S1;
    if (EXP1 >= S1) {
        P1 = 1;
    } else {
        P1 = ((double)(EXP1 / S1) + 80) / 123.00;
    }
// Con duong thu 2
    money=M1;
    if(E2 %2 != 0) {
        while (M1 >= money/2) {
            if (M1<=0){
                break;
            }
            if (HP1 < 200) {
                HP1 = 1.3 * HP1 +0.999;
                M1 -= 150;
            } else {
                HP1 = 1.1 * HP1 +0.999;
                M1 -= 70;
            }
            checkmax(HP1,maxhp);
            if (M1<money/2){
                break;
            }
            if (EXP1 < 400) {
                M1 -= 200;
            } else {
                M1 -= 120;
            }
            EXP1 = 1.13 * EXP1 +0.999;
            checkmax(EXP1,maxexp);
            if (M1 < money/2){
                break;
            }
            if (EXP1 < 300) {
                M1 -= 100;
            } else {
                M1 -= 120;
            }
            EXP1 = 0.9 * EXP1+0.999;
            checkmin(EXP1,minexp);
            if(M1<money/2){
                break;
            }
        }
        HP1= 0.83* HP1+0.999;
        EXP1= 1.17 * EXP1+0.999;
        checkmax(EXP1,maxexp);
        checkmin(HP1,minhp);
    }
    else {
        for (int i=0; i<1; i++) {
            if (M1<=0){
                break;
            }
            if (HP1 < 200) {
                HP1 = 1.3 * HP1+0.999;
                M1 -= 150;
            } else {
                HP1 = 1.1 * HP1+0.999;
                M1 -= 70;
            }
            checkmax(HP1,maxhp);
            if (M1<=0){
                break;
            }
            if (EXP1 < 400) {
                M1 -= 200;
            } else {
                M1 -= 120;
            }
            EXP1 = 1.13 * EXP1+0.999;
            checkmax(EXP1,maxexp);
            if (M1<=0){
                break;
            }
            if (EXP1 < 300) {
                M1 -= 100;
            } else {
                M1 -= 120;
            }
            EXP1 = 0.9 * EXP1+0.999;
            checkmin(EXP1,minexp);
        }
        HP1= 0.83* HP1+0.999;
        EXP1= 1.17 * EXP1+0.999;
        checkmax(EXP1,maxexp);
        checkmin(HP1,minhp);
    }
    S2 = round(sqrt(EXP1));
    S2 *= S2;
    if (EXP1 >= S2) {
        P2 = 1;
    } else {
        P2 = ((double)(EXP1 / S2) + 80) / 123.00;
    }
    //Con duong 3
    float P3[10]= {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    int sum,i;
    sum=E2/10 +E2%10;
    i=sum%10;
    P= (P1+P2+P3[i])/3.00;
    if(P!=1){
        if (P>=0.5){
            HP1= 0.9* HP1+0.999;
            EXP1= 1.2* EXP1+0.999;
        }
        else{
            HP1= 0.85* HP1+0.999;
            EXP1= 1.15* EXP1+0.999;
        }
    }
    else {
        EXP1= 0.75 *EXP1+0.999;
    }
    checkmax(HP1,maxhp);
    checkmin(HP1,minhp);
    checkmax(EXP1,maxexp);
    checkmin(EXP1,minexp);
    checkmax(M1,maxM);
    checkmin(M1,minM);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

    int point[10][10],point1[10][10],point2[10][10],taxipoint[10][10];
    int max,tam1,tam2,tam3,tam4,a1,a2,a3,a4,f1,f2,f3,f4,j1,j2,j3,j4,count1,count2;
    if(E3<0||E3>99){
        return-99;
    }
    checkmax(EXP1,maxexp);
    checkmax(EXP2,maxexp);
    checkmax(HP1,maxhp);
    checkmax(HP2,maxhp);
    checkmin(EXP1,minexp);
    checkmin(EXP2,minexp);
    checkmin(HP1,minhp);
    checkmin(HP2,minhp);

    for(int i=0;i<10;i++){
        for(int j =0;j<10;j++){
            taxipoint[i][j]=((E3*j)+(i*2))*(i-j);
        }
    }
    // luu mang chua gia tri max cua dg cheo trai
    for (int i=0;i<10;i++){
        a1=0;
        max=taxipoint[i][a1];
        for( tam1=i; tam1<9;tam1++){
            if (taxipoint[tam1+1][a1+1]>max){
                max= taxipoint[tam1+1][a1+1];
            }
            a1++;
        }
        j1=0;
        for(f1=i;f1<10;f1++){
            point1[f1][j1]=max;
            j1++;
        }
    }

    for (int i=0;i<10;i++){
        a2=0;
        max=taxipoint[a2][i];
        for( tam2=i; tam2<9;tam2++){
            if (taxipoint[a2+1][tam2+1]>max){
                max= taxipoint[a2+1][tam2+1];
            }
            a2++;
        }
        j2=0;
        for (f2=i;f2<10;f2++)
        {
            point1[j2][f2]=max;
            j2++;
        }
    }
// luu mang chua gia tri max cua dg cheo phai
    for (int i = 0; i < 10; i++) {
        a3 = 9;
        max = taxipoint[i][a3];
        for(tam3=i;tam3<9;tam3++) {
            if (taxipoint[tam3+1][a3-1] > max) {
                max = taxipoint[tam3+1][a3-1];
            }
            a3--;
        }
        f3 = 9;
        for(j3=i;j3<10;j3++){
            point2[j3][f3] = max;
            f3--;
        }
    }
    for (int i = 9; i >= 0; i--) {
        a4 = 0;
        max = taxipoint[a4][i];
        for(tam4=i;tam4>=1;tam4--){
            if (taxipoint[a4+1][tam4-1] > max) {
                max = taxipoint[a4+1][tam4-1];
            }
            a4++;
        }
        f4 = 0;
        for(j4=i;j4>=0;j4--){
            point2[f4][j4] = max;
            f4++;
        }
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++)
            if (point1[i][j] > point2[i][j]) point[i][j] = point1[i][j];
            else point[i][j] = point2[i][j];

    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (point[i][j]<0) {
                point[i][j] = abs(point[i][j]);
            }
        }
    }
    count1=0;
    count2=0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (taxipoint[i][j]>E3*2) {
                count1++;
            }
            else if(taxipoint[i][j]<-E3){
                count2++;
            }
        }
    }
    int sum1,sum2;
    sum1=count1/10 +count1%10;
    sum2=count2/10+count2%10;
    while(sum1>=10||sum2>=10){
        sum1=sum1/10+sum1%10;
        sum2=sum2/10+sum2%10;
    }
    if (abs(taxipoint[sum1][sum2])>point[sum1][sum2]){

        EXP1=EXP1*0.88+0.99;
        checkmin(EXP1,minexp);
        HP1=HP1*0.9+0.99;
        checkmin(HP1,minhp);
        EXP2=EXP2*0.88+0.99;
        checkmin(EXP1,minexp);
        HP2=HP2*0.9+0.99;
        checkmin(HP2,minhp);
        return taxipoint[sum1][sum2];
    }
    else{
        EXP1=EXP1*1.12+0.99;
        HP1=HP1*1.1+0.99;
        EXP2=EXP2*1.12+0.99;
        HP2=HP2*1.1+0.99;
        checkmax(EXP1,maxexp);
        checkmax(EXP2,maxexp);
        checkmax(HP1,maxhp);
        checkmax(HP2,maxhp);
        return point[sum1][sum2];
    }
}

// Task 4

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    string s2, email2;
    int i,k,a, count1, position;
    s2 = s;
    email2 = email;
    position = -1;
    for (i=0;i<email2.length();i++){
        if (email2[i]=='@'){
            k=i;
            break;
        }
    }
    if (s2.length() < 8) {
        return -1;
    } else if (s2.length() > 20) {
        return -2;
    }
    for (i = 0; i < s2.length(); i++) {
        bool check = 1;
        for (int j = 0; j < k; j++) {
            if (s2[i + j] != email2[j]) {
                check = 0;
                break;
            }
        }

        if (check == 1) {
            position = i;
            break;
        }
    }

    if (position != -1) {
        return -(300 + position);
    }
    int count2 = 0;
    for (i = 0; i < s2.length(); i++) {
        if (s2[i] == s2[i + 1] && s2[i] == s2[i + 2]) {
            count2++;
            break;
        }
    }
    if (count2 != 0) {
        return -(400 + i);
    }
    count1 = 0;
    for (i = 0; i < s2.length(); i++) {
        if (s2[i] == '@' || s2[i] == '%' || s2[i] == '#' || s2[i] == '$' || s2[i] == '!') {
            count1++;
        }
    }
    if (count1 == 0) {
        return -5;
    }
    for (i = 0; i < s2.length(); i++) {
        a = int(s2[i]);
        if ((a <48) || (a>57) && (a < 64) || (a>90) && (a<97) || (a >122)){
            if ((a != 36) && (a!=35) && (a != 37) && (a != 33))
                return i;
        }

    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string password[num_pwds];
    int  i,j,max, posi;
    int count[num_pwds];
    posi=0;
    for ( i=0; i<num_pwds;i++){
        count[i]=0;
    }
    for ( i=0; i< num_pwds;i++){
        password[i]=arr_pwds[i];
    }
    for ( i =0 ; i<num_pwds;i++) {
        for ( j = i; j < num_pwds; j++) {
            if (password[i] == password[j]) {
                count[i]++;
            }
        }
    }
    max=count[0];
    for ( i=0; i<num_pwds;i++) {
        if (count[i] > max) {
            max = count[i];
            posi = i;
        }
        else if (count[i] == max) {
            if (password[posi].length() < password[i].length()) {
                max = count[i];
                posi = i;
            }
        }
    }
    return posi;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////