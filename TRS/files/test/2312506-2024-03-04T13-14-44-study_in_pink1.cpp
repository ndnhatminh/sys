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
int roundEXP (float EXP) {
    if (EXP>600) return 600;
    if (EXP<0) return 0;
    return ceil(EXP);
}
int roundHP (float HP) {
    if (HP>666) return 666;
    if (HP<0) return 0;
    return ceil(HP);
}
int roundM (int M) {
    if (M>3000) return 3000;
    if (M<0) return 0;
    return M;
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    //check E1
    if (e1<0 || e1>99) return -99;
    //check value
    exp1=roundEXP(exp1);
    exp2=roundEXP(exp2);
    //start
    if (e1>=0 && e1<=3) {
        int explain[4]={29,45,75,149};
        exp2=roundEXP(exp2+explain[e1]);
        int D=e1*3+exp1*7;
        if (D&1) {
            exp1=roundEXP(exp1-D/100.0);
        }
        else {
            exp1=roundEXP(exp1+D/200.0);
        }
    }
    else if (e1>=4 && e1<=99) {
        if (e1<=19) exp2=roundEXP(exp2+e1/4.0+19);
        else if (e1<=49) exp2=roundEXP(exp2+e1/9.0+21);
        else if (e1<=65) exp2=roundEXP(exp2+e1/16.0+17);
        else if (e1<=79) {
            exp2=roundEXP(exp2+e1/4.0+19);
            if (exp2>200) exp2=roundEXP(exp2+e1/9.0+21);
        }
        else {
            exp2=roundEXP(exp2+e1/4.0+19);
            exp2=roundEXP(exp2+e1/9.0+21);
            if (exp2>400) {
                exp2=roundEXP(exp2+e1/16.0+17);
                exp2=roundEXP(exp2*1.15);
            }
        }
        exp1=roundEXP(exp1-e1);
    }
    return exp1 + exp2;
}

// Task 2
float firstWay (int & EXP1) {
    float S=pow(round(sqrt(EXP1)),2);
    if (S<=EXP1) return 1;
    else return (EXP1/S+80)/123;
}
int secondWayStore (int & HP1, int & M1) {
    if (HP1<200) {
        HP1=roundHP(HP1*1.3);
        M1=roundM(M1-150);
        return 150;
    }
    else {
        HP1=roundHP(HP1*1.1);
        M1=roundM(M1-70);
        return 70;
    }
}
int secondWayVehicle (int & EXP1, int & M1) {
    if (EXP1<400) {
        M1=roundM(M1-200);
        EXP1=roundEXP(EXP1*1.13);
        return 200;
    }
    else {
        M1=roundM(M1-120);
        EXP1=roundEXP(EXP1*1.13);
        return 120;
    }
}
int secondWayHomeless (int & EXP1, int & M1) {
    if (EXP1<300) {
        M1=roundM(M1-100);
        EXP1=roundEXP(EXP1*0.9);
        return 100;
    }
    else {
        M1=roundM(M1-120);
        EXP1=roundEXP(EXP1*0.9);
        return 120;
    }
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    //check E2
    if (E2<0 || E2>99) return -99;
    //check value
    HP1=roundHP(HP1);
    EXP1=roundEXP(EXP1);
    M1=roundM(M1);
    //First way
    float P1=firstWay(EXP1);
    
    //Second way
    float P2;
    int usedM=0; 
    if (M1>0) {
        if (E2%2!=0) {
            while (usedM<=M1) {
                //Store
                usedM+=secondWayStore(HP1, M1);
                if (usedM>M1) break;
                //Vehicle
                usedM+=secondWayVehicle(EXP1, M1);
                if (usedM>M1) break;
                //Homeless
                usedM+=secondWayHomeless(EXP1, M1);
            }
        }
        else {
            if (M1>0) secondWayStore(HP1,M1);
            if (M1>0) secondWayVehicle(EXP1, M1);
            if (M1>0) secondWayHomeless(EXP1, M1);
        }
    }
    HP1=roundHP(HP1*0.83);
    EXP1=roundEXP(EXP1*1.17);
    P2=firstWay(EXP1);


    //Third way
    float P[10]={32,47,28,79,100,50,22,83,64,11};
    float P3=(E2<10)? (P[E2]/100.0):(P[(E2%10+E2/10)%10]/100.0);


    //End
    if (P1==1 && P2==1 && P3==1) {
        EXP1=roundEXP(EXP1*0.75);
    }
    else {
        float Prob=(P1+P2+P3)/3;
        if (Prob<0.5) {
            HP1=roundHP(HP1*0.85);
            EXP1=roundEXP(EXP1*1.15);
        }
        else {
            HP1=roundHP(HP1*0.9);
            EXP1=roundEXP(EXP1*1.20);
        }
    }   
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    //check E3
    if (E3<0 || E3>99) return -99;
    //check value
    HP1=roundHP(HP1);
    EXP1=roundEXP(EXP1);
    HP2=roundHP(HP2);
    EXP2=roundEXP(EXP2);    
    //initialize taxi's score
    int M[10][10];
    int imeet=0, jmeet=0;
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            M[i][j]=(E3*j+i*2)*(i-j);
            if (M[i][j]>E3*2) imeet++;
            else if (M[i][j]<-E3) jmeet++;
        }
    }
    //find meet point
    while (imeet>9) imeet=imeet%10+imeet/10;
    while (jmeet>9) jmeet=jmeet%10+jmeet/10;
    int maxleft=M[imeet][jmeet], maxright=M[imeet][jmeet];
    //left
    int i,j;
    if (imeet>jmeet) {
        j=0;
        i=imeet-jmeet;
        while (i<10) {
            if (M[i][j]>maxleft) maxleft=M[i][j];
            i++;
            j++;
        }
    }
    else {
        i=0;
        j=jmeet-imeet;
        while (j<10) {
            if (M[i][j]>maxleft) maxleft=M[i][j];
            i++;
            j++;
        }
    }
    //right
    if (imeet+jmeet<10) {
        i=0;
        j=imeet+jmeet;
        while (j>-1) {
            if (M[i][j]>maxright) maxright=M[i][j];
            i++;
            j--;
        }
    }
    else {
        i=9;
        j=imeet+jmeet-9;
        while (j<10) {
            if (M[i][j]>maxright) maxright=M[i][j];
            i--;
            j++;
        }
    }


    int scoreSH=(maxright>maxleft)? maxright:maxleft;
    scoreSH=abs(scoreSH);

    if (abs(M[imeet][jmeet])>scoreSH) {
        EXP1=roundEXP(EXP1*0.88);
        EXP2=roundEXP(EXP2*0.88);
        HP1=roundHP(HP1*0.9);
        HP2=roundHP(HP2*0.9);
        return M[imeet][jmeet];
    }
    else {
        EXP1=roundEXP(EXP1*1.12);
        EXP2=roundEXP(EXP2*1.12);
        HP1=roundHP(HP1*1.1);
        HP2=roundHP(HP2*1.1);
        return scoreSH;
    }
    return -1;
}

// Task 4
bool checkSpecialChar (char s) {
    if (s=='@'|| s=='#' || s=='%'||s=='$'||s=='!') return 1;
    return 0;
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    //copy
    string s1=s, email1=email;

    //checkSize
    if (s1.length()<8) return -1;
    if (s1.length()>20) return -2;
    int sSize=s1.length();

    //find se
    string se;
    int seSize=0;
    while (email1[seSize]!='@') seSize++;
    se=email1.substr(0,seSize);
    for (int i=0; i<=sSize-seSize; i++) {
        if (s1.substr(i,seSize)==se) return -(300+i);
    }

    //consecutive letters
    int cons=1;
    for (int i=0; i<sSize; i++) {
        cons=1;
        while (s[i]==s[i+cons]) cons++;
        if (cons>2) return -(400+i);
    }

    //special character
    bool checkSpe=0;
    for (int i=0; i<sSize; i++) {
        if (checkSpecialChar(s[i])) {
            checkSpe=1;
            break;
        }
    }
    if (!checkSpe) return -5;

    //unvalid character
    for (int i=0; i<sSize; i++) {
        if (!(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' 
           || s[i]>='0' && s[i]<='9' || checkSpecialChar(s[i])))
        return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string pwds[num_pwds];
    for (int i=0; i<num_pwds; i++) {
        pwds[i]=arr_pwds[i];
    }
    int arr_inf[num_pwds][2];
    for (int i=0; i<num_pwds; i++) {
        for (int j=0; j<2; j++) {
            arr_inf[i][j]=0;
        }
    }
    //0 times
    //1 length
    for (int i=0; i<num_pwds; i++) {
        if (pwds[i]!="") {
            arr_inf[i][0]++;
            arr_inf[i][1]=pwds[i].length();
            //count
            for (int j=i+1; j<num_pwds; j++) {
                if (pwds[i]==pwds[j]){
                    arr_inf[i][0]++;
                    pwds[j]="";
                }
            }
        }
    }
    int max_index=0;
    for (int i=0; i<num_pwds; i++) {
        if (arr_inf[i][0]>arr_inf[max_index][0]) {
            max_index=i;
        }
        else if (arr_inf[i][0]==arr_inf[max_index][0] && arr_inf[i][1]>arr_inf[max_index][1]) {
            max_index=i;
        }
    }
    return max_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////