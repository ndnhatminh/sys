#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
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
int firstMeet(int &EXP1, int &EXP2, int E1){
    if ((E1>99) || (E1<0)) {return -99;}
    int D;
    const int const_EXP1 = EXP1, const_EXP2 = EXP2;
    if ((E1>=0)&&(E1<=3)){
    switch (E1){
        case 0: EXP2+= 29; if (EXP2>=600) EXP2=600; break;
        case 1: EXP2+= 45; if (EXP2>=600) EXP2=600; break;
        case 2: EXP2+= 75; if (EXP2>=600) EXP2=600; break;
        case 3: EXP2+= 29 + 45 + 75; if (EXP2>=600) EXP2=600; break;
    }
    D = E1 * 3 + EXP1 * 7;
    if (D%2==0) {EXP1 = ceilf(EXP1*1.0 + D*1.0/200); if (EXP1>=600) EXP1=600;}
    else {EXP1 = ceilf(EXP1*1.0 - D*1.0/100); if (EXP1<=0) EXP1=0;}
    return EXP1 + EXP2;
    }
    else {EXP1 = const_EXP1; EXP2 = const_EXP2; 
        if ((E1>=4) && (E1<=19)) {
            EXP2 += ceilf(E1*1.0/4 + 19);
            if (EXP2>=600) EXP2=600;
        }
        else if ((E1>=20) && (E1<=49)) {
            EXP2 += ceilf(E1*1.0/9 + 21);
            if (EXP2>=600) EXP2=600;
        }
        else if ((E1>=50) && (E1<=65)) {
            EXP2 += ceilf(E1*1.0/16 + 17);
            if (EXP2>=600) EXP2=600;
        }
        else if ((E1>=66) && (E1<=79)) {
            EXP2 += ceilf(E1*1.0/4 + 19);
            if (EXP2>200) EXP2 += ceilf(E1*1.0/9 + 21);
            if (EXP2>=600) EXP2=600;
        }
        else if ((E1>=80) && (E1<=99)) {
            EXP2 += ceilf(E1*1.0/4 + 19);
            EXP2 += ceilf(E1*1.0/9 + 21);
            if (EXP2>400) {EXP2 += ceilf(E1*1.0/16 + 17);
            EXP2 = ceilf(EXP2*1.0*115/100);}
            if (EXP2>=600) EXP2=600;
        }
        EXP1 -= E1; if (EXP1<=0) EXP1=0;
        return EXP1 + EXP2;
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if ((E2>99)||(E2<0)) return -99;
    //Fisrt road
    int s = sqrt(EXP1);
    int dis1 = EXP1 - s*s;
    int dis2 = (s+1)*(s+1) - EXP1;
    int S; float P1;
    if (dis1<dis2) S = s*s;
    else S = (s+1)*(s+1);
    if (EXP1>=S) P1=1;
    else P1 = (EXP1/S + 80)*1.0/123;

    //Second road
    int halfm1 = ceilf(M1*1.0/2);
    int usem1 = 0; 

    if (E2%2==1){
        while (true){
        if (HP1<200) {HP1=ceilf(HP1*1.3); M1-=150; if (M1<0) {M1=0;} usem1+=150;}
        else {HP1 = ceilf(HP1*1.1); if (HP1>=666) {HP1=666;} M1-=70; if (M1<0) {M1=0;} usem1+=70; }
        if (usem1>halfm1) {break;}

        if (EXP1>400) {M1-=120;if (M1<0) {M1=0;} usem1+=120;}
        else {M1-=200; if (M1<0) {M1=0;} usem1+=200;}
        EXP1 = ceilf(EXP1*1.13); if (EXP1>=600) {EXP1=600;}
        if (usem1>halfm1) {break;}

        if (EXP1<300) {
            M1-=100; if (M1<0) {M1=0;} usem1+=100;  
        }
        else {M1-=120;if (M1<0) {M1=0;} usem1+=120;}
        EXP1 = ceilf(EXP1*0.9); if (EXP1<=0) {EXP1=0;}
        if (usem1>halfm1) {break;}
        }
        HP1 = ceilf(HP1*0.83);
        EXP1 = ceilf(EXP1*1.17); if (EXP1>=600) {EXP1=600;}
    }
    else {
        for (int i=0;i<1;i++){
        if (HP1<200) {HP1=ceilf(HP1*1.3); M1-=150; if (M1<0) {M1=0;}}
        else {HP1 = ceilf(HP1*1.1); if (HP1>=666) {HP1=666;} M1-=70; if (M1<0) {M1=0;}}
        if (M1==0) break;

        if (EXP1>400) {M1-=120;if (M1<0) {M1=0;} }
        else {M1-=200; if (M1<0) {M1=0;} }
        EXP1 = ceilf(EXP1*1.13); if (EXP1>=600) {EXP1=600;}
        if (M1==0) break;
        
        if (EXP1<300) {
            M1-=100; if (M1<0) {M1=0;} 
        }
        else {M1-=120; if (M1<0) {M1=0;} }
        EXP1 = ceilf(EXP1*0.9); if (EXP1<=0) {EXP1=0;}
        }
        HP1 = ceilf(HP1*0.83);
        EXP1 = ceilf(EXP1*1.17); if (EXP1>=600) {EXP1=600;}
    }

    float P2;
    s = sqrt(EXP1);
    dis1 = EXP1 - s*s;
    dis2 = (s+1)*(s+1) - EXP1;
    if (dis1<dis2) S = s*s;
    else S = (s+1)*(s+1);
    if (EXP1>=S) P2=1;
    else P2 = (EXP1/S + 80)*1.0/123;

    //Third road
    float P3;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2<10) {P3 = P[E2]*1.0/100;}
    else {
        int sum = E2/10 + E2%10;
        if (sum<10) P3 = P[sum]*1.0/100;
        else {sum=sum%10; P3 = P[sum]*1.0/100;}
    }

    //Possible
    if ((P1==1)&&(P2==1)&&(P3==1)) {
        EXP1 = ceilf(EXP1*0.75);
    }
    else {
        float average = (P1+P2+P3)/3;
        if (average<0.5) {HP1 = ceilf(HP1*0.85); EXP1 = ceilf(EXP1*1.15); if (EXP1>=600) {EXP1=600;}}
        else {HP1 = ceilf(HP1*0.9); EXP1 = ceilf(EXP1*1.2); if (EXP1>=600) {EXP1=600;}}
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if ((E3>99) || (E3<0)) {return -99;}
    int a[10][10];
    int i=0, j=0;
    for (int m=0;m<10;m++){
        for (int n=0;n<10;n++){
            a[m][n] = ((E3 * n) + (m*2))*(m-n);
            if (a[m][n]>(E3*2)) i++;
            if (a[m][n]<-E3) j++;
        }
    }

    while (i>=10) {i = i/10 + i%10;};
    while (j>=10) {j = j/10 + j%10;};
    

    int pointTaxi = a[i][j];
    int pointSherlock, max = a[i][j];

    int t1,t2;
    for (int m=-9;m<10;m++){
        int temp = a[i][j];
        if ((i+m<10)&&(i+m>=0)&&(j+m<10)&&(j+m>=0)) temp = a[i+m][j+m];
        if (temp>max) {max = temp;t1=i+m;t2=j+m;}
    }
    for (int n=-9;n<10;n++){
        int temp = a[i][j];
        if ((i-n<10)&&(i-n>=0)&&(j+n<10)&&(j+n>=0)) temp = a[i-n][j+n];
        if (temp>max) {max = temp;t1=i-n;t2=j+n;}
    }
    

    pointSherlock = max;
    if (abs(pointTaxi)>pointSherlock) {
        EXP1 = ceilf(EXP1*0.88);
        EXP2 = ceilf(EXP2*0.88);
        HP1=ceilf(HP1*0.9);
        HP2=ceilf(HP2*0.9); 
        return pointTaxi;
    }
    else {
        EXP1 = ceilf(EXP1*1.12); if (EXP1>600) EXP1= 600;
        EXP2 = ceilf(EXP2*1.12); if (EXP2>600) EXP2= 600;
        HP1=ceilf(HP1*1.1); if (HP1>666) HP1= 666;
        HP2=ceilf(HP2*1.1); if (HP2>666) HP2= 666;
        return pointSherlock;}
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string se = email;
    int length_se = 0;
    bool check = true;
    for (int i=0;i<strlen(email);i++){
        if (email[i] == '@') check = false;
        if (check == false) se.pop_back();
    }
    
    if (strlen(s)<8) return -1;
    if (strlen(s)>20) return -2;

    int count = 0; int index = -1;
    for (int i=0;i<strlen(s)-se.size()+1;i++){
        for (int j=0;j<se.size();j++){
            if (se[j] == s[i+j]) {count++;}
        }
        if (count == se.size()) {index = i; break;}
        else count = 0;
    }
    if (index!=-1) {return -(300+index);}

    int sci=-1;
    for (int i=0;i<strlen(s)-2;i++){
        if ((s[i]==s[i+1])&&(s[i+1]==s[i+2])) {sci = i;break;}
    }
    if (sci!=-1) return -(400+sci);

    string special = "#@!$%"; check = false;
    for (int i=0;i<strlen(s);i++){
        for (int j=0; j<5;j++){
            if (s[i] == special[j]) check = true;
        }
    }
    if (check == false) return -5;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int a[30]={0};
    for (int i=0; i<num_pwds;i++){
        for (int j = 0; j<num_pwds;j++){
            if (arr_pwds[i]==arr_pwds[j]) a[i]++;
        }
    }
    int max = a[0];
    for (int i=1;i<num_pwds;i++){
        if (a[i]>max) max = a[i];
    }
    const char * b[30]; const char * c[30][30]; const char *pass; 
    for (int i=0;i<num_pwds;i++){
        if (a[i] == max) {b[i] = arr_pwds[i];pass = arr_pwds[i]; break;}
    }
    
    for (int i=0;i<num_pwds;i++){
        if ((a[i] == max)&&(strlen(arr_pwds[i])>strlen(pass))) {b[i] = arr_pwds[i];pass = arr_pwds[i];}
    }
    int index;
    for (int i=0;i<num_pwds;i++){
        if (arr_pwds[i]==pass) {index=i;break;}
    }

    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////