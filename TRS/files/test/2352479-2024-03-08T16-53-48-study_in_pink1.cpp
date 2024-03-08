#include "study_in_pink1.h"

bool readFile(
    const string& filename,
    int& HP1,
    int& HP2,
    int& EXP1,
    int& EXP2,
    int& M1,
    int& M2,
    int& E1,
    int& E2,
    int& E3
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
//Check variables
void checkHP(int &HP){
    if (HP<0) HP=0;
    if (HP>666) HP=666;
}
void checkEXP(int &EXP){
    if (EXP<0) EXP=0;
    if (EXP>600) EXP=600;
}
void checkM(int& M){
    if (M<0) M=0;
    if (M>3000) M=3000;
}
//round up
int up (float a) {
    int b = static_cast<int>(ceil(a));
    return b;
}
// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {
    // TODO: Complete this function
    
    if (E1 < 0 || E1>99) return -99;
    checkEXP(EXP1);
    checkEXP(EXP2);
    if (E1 <= 3) {
        switch (E1) {
        case 0: EXP2 += 29; break;
        case 1: EXP2 += 45; break;
        case 2: EXP2 += 75; break;
        case 3: EXP2 += 29 + 45 + 75; break;
        }
        int D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0) EXP1 =up(EXP1+D / 200.0);
        else EXP1 =up(EXP1-D/100.0);
    }
    else {
        if (E1 <= 19) EXP2 += up(E1 / 4.00 + 19);
        else if (E1 <= 49) EXP2 += up(E1 / 9.00 + 21);
        else if (E1 <= 65) EXP2 += up(E1 / 16.00 + 17);
        else if (E1 <= 79) {
            EXP2 += up(E1 / 4.00 + 19);
            if (EXP2 > 200) EXP2 += up(E1 / 9.00 + 21);
        }
        else if (E1 <= 99) {
            EXP2 += up(E1 / 4.00 + 19);
            EXP2 += up(E1 / 9.00 + 21);
            if (EXP2 > 400) {
                EXP2 += up(E1 / 16.00 + 17);
                EXP2 = up(EXP2*1.15);
            }
        }
        EXP1 -= E1;
    }
    checkEXP(EXP1);
    checkEXP(EXP2);
    return EXP1 + EXP2;
}

//Find nearest square number
int nearsqr(int &EXP1){
    int a, b;
    int S;
    a = static_cast<int>(pow(floor(sqrt(EXP1)), 2));
    b = static_cast<int>(pow(up(sqrt(EXP1)), 2));
    if ((EXP1-a) <= (b - EXP1)) S = a;
    else    S = b;
    return S;
}
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2>99) return -99;
    checkHP(HP1);
    checkEXP(EXP1);
    checkM(M1);
    int S1,S2,i;
    float hm1;
    int Pa[10] = {32,47,28,79,100,50,22,83,64,11 };
    float P1,P2,P3,P;
    //road 1
    S1=nearsqr( EXP1);
    if (EXP1 >= S1) P1 = 1;
    else P1 = (EXP1 *1.00/ S1 + 80) / 123;

    //road 2
    if (E2 % 2 == 1) {
        if(M1==0) goto A;
        hm1 = M1 / 2.0;
        B:
        //event2.1
        if (HP1 < 200) {
            HP1 =up(HP1* 1.3);
            M1 -= 150;
            hm1-=150;
        }
        else {
            HP1 =up(HP1* 1.1);
            M1 -= 70;
            hm1-=70;
        }
        checkHP(HP1);
        checkM(M1);
        if (hm1<0) goto A;
        
        //event2.2
        if (EXP1 < 400) {
            M1 -= 200;
            hm1-=200;
        }
        else {
            M1 -= 120;
            hm1-= 120;
        } 
        EXP1 =up(EXP1* 1.13);
        checkEXP(EXP1);
        checkM(M1);
        if (hm1<0) goto A;
        
        //event2.3
        if (EXP1<300) {
            M1 -= 100;
            hm1-= 100;
        }
        else {
            M1 -= 120;
            hm1-= 120;
        } 
        EXP1 =up(EXP1* 0.9);
        checkM(M1);
        if (hm1<0) goto A;
        
        goto B;
        A:
        HP1 =up(HP1* 0.83);
        EXP1 =up(EXP1* 1.17);
        checkEXP(EXP1);
    }
    else {
        if (M1==0) goto C;
        //event2.1
        if (HP1 < 200) {
            HP1 =up(HP1* 1.3); checkHP(HP1);
            M1 -= 150; checkM(M1);
            if (M1 == 0) goto C;
        }
        else {
            HP1 =up(HP1* 1.1); checkHP(HP1);
            M1 -= 70; checkM(M1);
            if (M1 == 0) goto C;
        }
        //event2.2
        if (EXP1 < 400) {
            M1 -= 200; checkM(M1);
            EXP1 =up(EXP1* 1.13); checkEXP(EXP1);
            if (M1 == 0) goto C;
        }
        else {
            M1 -= 120; checkM(M1);
            EXP1 =up(EXP1* 1.13); checkEXP(EXP1);
            if (M1 == 0) goto C;
        }
        //event2.3
        if (EXP1 < 300) {
            M1 -= 100; checkM(M1);
            EXP1 =up(EXP1* 0.9);
            if (M1 == 0) goto C;
        }
        else {
            M1 -= 120; checkM(M1);
            EXP1 =up(EXP1* 0.9);
            if (M1 == 0) goto C;
        }
    C:
        HP1 =up(HP1* 0.83); 
        EXP1 =up(EXP1* 1.17); checkEXP(EXP1);
    }
    S2=nearsqr(EXP1);
    if (EXP1 >= S2) P2 = 1;
    else P2 = (EXP1*1.00 / S2 + 80) / 123;
    //road 3
    if (E2 < 10) i = E2;
    else i = ((E2 / 10) + (E2 % 10)) % 10;
    P3 = (Pa[i])/100.00;

    //after 3 road
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = up(EXP1 * 0.75);
        P=1;
    }
    else {
        P = (P1 + P2 + P3) / 3;
        if (P < 0.5) {
            HP1 = up(HP1 * 0.85);
            EXP1 = up(EXP1 * 1.15); checkEXP(EXP1);
        }
        else {
            HP1 = up(HP1 * 0.9);
            EXP1 = up(EXP1 * 1.2); checkEXP(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Decrease to 1 digit
int digit1(int & num) {
    while (num >= 10) {
        num = num % 10 + num / 10;
    }
    return num;
}
// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3<0||E3>99) return-99;
    checkEXP(EXP1);
    checkEXP(EXP2);
    checkHP(HP1);
    checkHP(HP2);
    int taxi[10][10] = {{0}};
    int sh[10][10] = {{0}};
    int row=0, col=0;
    for (int i = 0; i <=9; i++) {
        for (int j = 0; j <= 9; j++) {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taxi[i][j] > E3 * 2) row += 1;
            if (taxi[i][j] < -E3) col += 1;
        }
    }
    digit1(row);
    digit1(col);
    int gt=taxi[row][col], a;
    if (row <= col) {for (a = 0; a <=9; a++) if (col - row + a <= 9) gt = max(gt,taxi[a][col-row+a]);}
    else {for (a = 0; a <= 9; a++) if (row - col + a <=9) gt = max(gt,taxi[row-col+a][a]);}
    if (row <= 9 - col) {for (a = 0; a <= 9; a++) if (col+row-a >=0) gt = max(gt, taxi[a][col + row - a]);}
    else {for (a = 0; a <= 9; a++) if (row-(9-col)+a <= 9) gt = max(gt, taxi[row - (9 - col) + a][9-a]);}
    sh[row][col] = abs(gt);
    if (abs(taxi[row][col]) > sh[row][col]) {
        EXP1 = up(EXP1 * 0.88);
        EXP2 = up(EXP2 * 0.88);
        HP1 = up(HP1 * 0.9);
        HP2 = up(HP2 * 0.9);
        return taxi[row][col];
    }
    else {
        EXP1 = up(EXP1 * 1.12);
        EXP2 = up(EXP2 * 1.12);
        HP1 = up(HP1 * 1.1);
        HP2 = up(HP2 * 1.1);
        checkEXP(EXP1);
        checkEXP(EXP2);
        checkHP(HP1);
        checkHP(HP2);
        return sh[row][col];
    }
}

//Compare s annd se
bool cmps_se(const char*s,char*se,int& indexcmp){
    int s_size=strlen(s);
    int se_size=strlen(se);
    if (se_size==0) {indexcmp=-300;return 1;}
    for (int i=0;i<=s_size-se_size;i++){
        int num=0;
        for (int j=0;j<se_size;j++){
            if (se[j]!=s[i+j]){
                break;
            }
            else num++;
        }
        if (num==se_size) {indexcmp=-(300+i);return 1;}
    }
    return 0;
}
//Check repeat
bool repeat(const char* s,int& indexrpt){
    int s_size=strlen(s);
    for (int i=0;i<s_size;i++) if (i<=s_size-3 && (s[i]==s[i+1])&& s[i]==s[i+2]) {indexrpt=-(400+i);return 1;}
    return 0;
}
//check special
bool checknospecial(const char*s,int&special){
    int s_size=strlen(s);
    for (int i=0;i<s_size;i++){
        int ascii=s[i];
        if (ascii==33||ascii==35||ascii==36||ascii==37||ascii==64) special++;
    }
    if (special==0) return 1;
    return 0;
}
//check character
bool checkcharacter(const char* s, int& index){
    int s_size=strlen(s);
    for (int i=0;i<s_size;i++){
        int ascii=s[i];
        if ((ascii!=33&&ascii!=35&&ascii!=36&&ascii!=37&&ascii!=64)&&(ascii<=47||(ascii>=58&&ascii<=64)||(ascii>=91&&ascii<=96)||ascii>=123)) {
            index=i;
            return 1;
        }
    }
    return 0;
}
// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    int special=0;
    int s_size=strlen(s);
    int email_size=strlen(email);
    char se[100]={'\0'};
    int se_size=0;
    int indexerror;
    for (int i=0;i<email_size;i++){
        if (email[i]=='@') {break;}
        else {se[i]=email[i]; se_size++;}
    }
    if (s_size<8) return -1;
    else if(s_size<=20){
        if (cmps_se(s,se,indexerror)) return indexerror;
        if (repeat(s,indexerror)) return indexerror;
        if (checknospecial(s,special)) return -5;
        if (checkcharacter(s,indexerror)) return indexerror; 
        return -10;
    }
    else return -2;
    return -99;
}
//Check if the password was listed
void iflisted(const char* arr_pwds[],int a, int &numdif, int containerindex[],int numrepeat[], int length[]){
    bool listed=false;
    for (int i=0;i<numdif;i++){
        if (strcmp(arr_pwds[a],arr_pwds[containerindex[i]])==0){
            numrepeat[i]++;
            listed=true;
            break;
        }
    }
    if (listed==false){
        numdif++;
        containerindex[numdif-1]=a;
        numrepeat[numdif-1]=1;
        length[numdif-1]=int(strlen(arr_pwds[a]));
    }
}
// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    if (num_pwds==1) return 0;
    int numdif=1;
    int containerindex[30]; for(int i=0;i<30;i++) containerindex[i]=-1;
    int numrepeat[30]={0};
    int length[30]={0};
    containerindex[0]=0;
    numrepeat[0]=1;
    length[0]=strlen(arr_pwds[0]);
    int maxrepeat=0,indexmaxrepeat=0;
    int maxlength=0,indexmaxlength=0;
    //Define different passwords and the number of being repeated;
    for (int i=1;i<num_pwds;i++){
        iflisted(arr_pwds,i,numdif,containerindex,numrepeat,length);
    }
    //Define max repeated;
    for (int i=0;i<numdif;i++){
        if(numrepeat[i]>maxrepeat) maxrepeat=numrepeat[i];
    }
    //Define max length of maxrepeat
    for (int i=0;i<numdif;i++){
        if (numrepeat[i]==maxrepeat&&length[i]>maxlength){
            maxlength=length[i];
        }
    }
    //Define password having maxlength and maxrepeat
    for (int i=0;i<numdif;i++){
        if (numrepeat[i]==maxrepeat && length[i]==maxlength){
            return containerindex[i];
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////