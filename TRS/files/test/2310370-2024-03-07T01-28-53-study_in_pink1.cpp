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

int dieukien(int n, int dau, int cuoi){
    n=(n<dau)?dau:(n>cuoi)?cuoi:n;
    return n;
}

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    int dau=0, cuoi=600;
    EXP1 = dieukien(EXP1, dau, cuoi);
    EXP2 = dieukien(EXP2, dau, cuoi);
    if(E1 < 0 || E1>99)
        return -99;

    //--------chia truong hop---------

    int inf11 = 29, inf12 = 45, inf13 = 75, D ;
    float inf21, inf22, inf23;
    inf21 = E1/4.0 + 19;
    inf22 = E1/9.0 + 21;
    inf23 = E1/16.0+ 17;
    D = E1*3 + EXP1*7;
    float testexp1, testexp2, testD;
    testD = D * 1.0;
    //-----Case 1-----
    if(E1<=3)
    {
        if(E1==0){
            EXP2 += inf11;
            EXP2 = dieukien(EXP2, dau, cuoi);
        }
        else if(E1==1){
            EXP2 += inf12;
            EXP2 = dieukien(EXP2, dau, cuoi);
        }
        else if(E1==2){
            EXP2 += inf13;
            EXP2 = dieukien(EXP2, dau, cuoi);
        }
        else{
            EXP2 = EXP2 + inf11 + inf12 + inf13;
            EXP2 = dieukien(EXP2, dau, cuoi);
        }

        if(D%2==0){
            EXP1 = ceil(EXP1 + testD/200);
            EXP1 = dieukien(EXP1, dau, cuoi);
        }
        else{
            EXP1 = ceil(EXP1 - testD/100);
            EXP1 = dieukien(EXP1, dau, cuoi);
    }
}
    //-----Case 2-----
    else{
        if(E1<=19){
            testexp2 = ceil(EXP2 + inf21);
            EXP2 = testexp2;
            EXP2 = dieukien(EXP2, dau, cuoi);
        }
        else if(E1<=49){
            testexp2 = ceil(EXP2 + inf22);
            EXP2 = testexp2;
            EXP2 = dieukien(EXP2, dau, cuoi);
        }
        else if(E1<=65){
            testexp2 = ceil(EXP2 + inf23);
            EXP2 = testexp2;
            EXP2 = dieukien(EXP2, dau, cuoi);
        }
        else if(E1<=79){
            testexp2 = ceil(EXP2 + inf21);
            if(testexp2>200){
                testexp2 = ceil(testexp2 + inf22);
            }
            EXP2 = testexp2;
            EXP2 = dieukien(EXP2, dau, cuoi);
        }
        else{
            testexp2 = ceil(EXP2 + inf21);
            testexp2 = ceil(testexp2 + inf22);
            EXP2 = testexp2;
            EXP2 = dieukien(EXP2, dau, cuoi);
            if(EXP2>400){
                EXP2 = ceil(EXP2 + inf23);
                EXP2 = ceil(EXP2 * 1.15);
                EXP2 = dieukien(EXP2, dau, cuoi);
            }
        }
        EXP1 = EXP1 - E1;
        EXP1 = dieukien(EXP1, dau, cuoi);
}
    int output;
    output = EXP1 + EXP2;
    return output;
}

bool lascp(int n) {
    int sqrt_n = sqrt(n);
    return sqrt_n * sqrt_n == n;
}

// tim so chinh phuong gan voi s nhat
int scpgannhat(int num) {
    int scp_nhohon = sqrt(num);
    int scp_lonhon = scp_nhohon + 1;

    if (lascp(num)) {
        return num; // neu s la so chinh phuong
    }
    else {
        int kc_nhohon = abs(num - scp_nhohon * scp_nhohon);
        int kc_lonhon = abs(num - scp_lonhon * scp_lonhon);

        if (kc_nhohon < scp_lonhon) {
            return scp_nhohon * scp_nhohon;
        }
        else {
            return scp_lonhon * scp_lonhon;
        }
    }
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2){

int dauhp=0, cuoihp=666, dauexp=0, cuoiexp=600, daum=0, cuoim=3000;
    HP1 = dieukien(HP1, dauhp, cuoihp);
    EXP1 = dieukien(EXP1, dauexp, cuoiexp);
    M1 = dieukien(M1, daum, cuoim);
    if(E2 < 0 || E2>99)
        return -99;


//-----con duong 1-----

int S1 = scpgannhat(EXP1);
float testexp1, testS1, P1, p1;
testexp1 = EXP1*1.0;
testS1= S1*1.0;
p1 = (testexp1/testS1+80.0)/123.0;
P1 = (EXP1>=S1)?1:p1;
P1 = P1 * 100;

//-----con duong 2-----
int nuoc1 = 150, nuoc2 = 70, taxi = 200, ngua = 120, giup1 = 100, giup2 = 120, tieu = 0;
    int m1 = ceil(M1 / 2.0);

    // Xử lý các trường hợp cho E2 là số lẻ
if (E2 % 2 != 0) {
    while (tieu < m1) {
        // Ăn uống và di chuyển
        if (HP1 < 200) {
            HP1 = ceil(HP1 + HP1 * 0.3);
            HP1 = dieukien(HP1, dauhp, cuoihp);
            M1 -= nuoc1;
            M1 = dieukien(M1, daum, cuoim);
            tieu += nuoc1;
        }
        else {
            HP1 = ceil(HP1 + HP1*0.1);
            HP1 = dieukien(HP1, dauhp, cuoihp);
            M1 -= nuoc2;
            M1 = dieukien(M1, daum, cuoim);
            tieu += nuoc2;
        }
        if (tieu > m1) break;
            // Chọn phương tiện di chuyển
        if (EXP1 < 400) {
            M1 -= taxi;
            M1 = dieukien(M1, daum, cuoim);
            tieu += taxi;
            EXP1 = ceil(EXP1 * 1.13);
        }
        else {
            M1 -= ngua;
            M1 = dieukien(M1, daum, cuoim);
            tieu += ngua;
            EXP1 = ceil(EXP1 * 1.13);
        }
            if (tieu > m1) break;
                // Gặp người vô gia cư
            if (EXP1 < 300) {
                M1 -= giup1;
                M1 = dieukien(M1, daum, cuoim);
                tieu += giup1;
                EXP1 = ceil(EXP1 * 0.9);
            }
            else {
                M1 -= giup2;
                M1 = dieukien(M1, daum, cuoim);
                tieu += giup2;
                EXP1 = ceil(EXP1 * 0.9);
            }

        }
    }
// nếu E2 là số chẵn
else{
    if (HP1 < 200) {
            HP1 = ceil(HP1 + HP1*0.3);
            HP1 = dieukien(HP1, dauhp, cuoihp);
            M1 -= nuoc1;
            M1 = dieukien(M1, daum, cuoim);
            tieu += nuoc1;
        }
        else {
            HP1 = ceil(HP1 + HP1*0.1);
            HP1 = dieukien(HP1, dauhp, cuoihp);
            M1 -= nuoc2;
            M1 = dieukien(M1, daum, cuoim);
            tieu += nuoc2;
        }
        if (M1<=0) goto dibothoi;
            // Chọn phương tiện di chuyển
            if (EXP1 < 400) {
                M1 -= taxi;
                M1 = dieukien(M1, daum, cuoim);
                tieu += taxi;
                EXP1 = ceil(EXP1 + EXP1*0.1 + EXP1 * 0.03);
                EXP1 = dieukien(EXP1, dauexp, cuoiexp);
            }
            else {
                M1 -= ngua;
                M1 = dieukien(M1, daum, cuoim);
                tieu += ngua;
                EXP1 = ceil(EXP1 + EXP1*0.1 + EXP1 * 0.03);
                EXP1 = dieukien(EXP1, dauexp, cuoiexp);
            }
            if (M1<=0) goto dibothoi;
                // Gặp người vô gia cư
                if (EXP1 < 300) {
                    M1 -= giup1;
                    M1 = dieukien(M1, daum, cuoim);
                    tieu += giup1;
                    EXP1 = ceil(EXP1 * 0.9);
                    EXP1 = dieukien(EXP1, dauexp, cuoiexp);
                }
                else {
                    M1 -= giup2;
                    M1 = dieukien(M1, daum, cuoim);
                    tieu += giup2;
                    EXP1 = ceil(EXP1 * 0.9);
                    EXP1 = dieukien(EXP1, dauexp, cuoiexp);
                }
}
       dibothoi:
        HP1 = ceil(HP1*0.83);
        HP1 = dieukien(HP1, dauhp, cuoihp);
        EXP1 = ceil(EXP1*1.17);
        EXP1 = dieukien(EXP1, dauexp, cuoiexp);


//--xac suat duong 2--

int S2 = scpgannhat(EXP1);
float testS2, P2, p2;
testexp1 = EXP1*1.0;
testS2= S2*1.0;
p2 = (testexp1/testS2+80.0)/123.0;
P2 = (EXP1>=S2)?1:p2;
P2 = P2*100;

//-----con duong 3-----

int P[10]={32,47,28,79,100,50,22,83,64,11};
float Ptb, P3, gtri, gtri2;
gtri = 100.0;
gtri2 = 50.0;
int chuc, donvi, tong;
if(E2/10==0){
    P3 = P[E2];
}
else{
    chuc = E2/10;
    donvi = E2%10;
    tong = chuc + donvi;
    tong = tong%10;
    P3 = P[tong];
}
if(P1 == gtri&&P2 == gtri&&P3 == gtri){
    EXP1 = ceil(EXP1*0.75);
    EXP1 = dieukien(EXP1, dauexp, cuoiexp);
}
else{
    Ptb = (P1 + P2 + P3)/3.0;
    if(Ptb<gtri2){
        HP1 = ceil(HP1*0.85);
        HP1 = dieukien(HP1, dauhp, cuoihp);
        EXP1 = ceil(EXP1*1.15);
        EXP1 = dieukien(EXP1, dauexp, cuoiexp);
    }
    else{
        HP1 = ceil(HP1*0.9);
        HP1 = dieukien(HP1, dauhp, cuoihp);
        EXP1 = ceil(EXP1*1.2);
        EXP1 = dieukien(EXP1, dauexp, cuoiexp);
    }
}

 return EXP1 + HP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
/*
    int dauhp=0, cuoihp=666, dauexp=0, cuoiexp=600;
    HP1 = dieukien(HP1, dauhp, cuoihp);
    HP2 = dieukien(HP2, dauhp, cuoihp);
    EXP1 = dieukien(EXP1, dauexp, cuoiexp);
    EXP2 = dieukien(EXP2, dauexp, cuoiexp);
    if(E3 < 0 || E3>99)
        return -99;

int A[10][10];
int i, j, i0=0, j0=0;
for(i=0; i<10; i++){
    for(j=0; j<10; j++){
        A[i][j] = ((E3*j) + (i*2))*(i-j);
        if(A[i][j]>(E3*2)) i0++;
        else if(A[i][j]<(0-E3)) j0++;
    }
}
    while(i0>9){
        i0 = i0/10 + i0%10;
    }
    while(j0>9){
        j0 = j0/10 + j0%10;
    }
    int max1 = A[i0][j0];
    int ix, jx;

    // duong cheo o tren ben trai
    ix=i0;
    jx=j0;
    while(ix>0&&jx>0){
        ix--;
        jx--;
        if(A[ix][jx]>max1) max1 = A[ix][jx];
    }

    // duong cheo o duoi ben trai
    ix=i0;
    jx=j0;
    while(ix<9&&jx>0){
        ix++;
        jx--;
        if(A[ix][jx]>max1) max1 = A[ix][jx];
    }

    // duong cheo tren ben phai
    ix=i0;
    jx=j0;
    while(ix>0&&jx<9){
        ix--;
        jx++;
        if(A[ix][jx]>max1) max1 = A[ix][jx];
    }

    // duong cheo duoi ben phai
    ix=i0;
    jx=j0;
    while(ix<9&&jx<9){
        ix++;
        jx++;
        if(A[ix][jx]>max1) max1 = A[ix][jx];
    }
     // duoi kip taxi hay khong???
    int output;
   if(abs(A[i0][j0])>abs(max1)){
       EXP1 = ceil(EXP1-EXP1*0.12);
       EXP1 = dieukien(EXP1, dauexp, cuoiexp);
       EXP2 = ceil(EXP2-EXP2*0.12);
       EXP2 = dieukien(EXP2, dauexp, cuoiexp);
       HP1 = ceil(HP1*0.9);
       HP1 = dieukien(HP1, dauhp, cuoihp);
       HP2 = ceil(HP2*0.9);
       HP2 = dieukien(HP2, dauhp, cuoihp);
       output = A[i0][j0];
       }
    else{
        EXP1 = ceil(EXP1+EXP1*0.12);
        EXP1 = dieukien(EXP1, dauexp, cuoiexp);
        EXP2 = ceil(EXP2+EXP2*0.12);
        EXP2 = dieukien(EXP2, dauexp, cuoiexp);
        HP1 = ceil(HP1+HP1*0.1);
        HP1 = dieukien(HP1, dauhp, cuoihp);
        HP2 = ceil(HP2+HP2*0.1);
        HP2 = dieukien(HP2, dauhp, cuoihp);
        output = max1;
    }
    int trave = output;
    return trave;
}
*/
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
int i = 0;
    while(s[i]!='\0'){
        i++;
    }
    if (i < 8) {
        return -1; // Mật khẩu quá ngắn
    } else if (i > 20) {
        return -2; // Mật khẩu quá dài
    }

    // lay phan user tu email
    i = 0;
    while (email[i] != '@' && email[i] != '\0') {
        i++;
    }
    char se[101];
    strncpy(se, email, i);
    se[i]='\0';

    // kiem tra xem trong mat khau co chua chuoi se khong
    const char *p = strstr(s, se);
    if(p!=NULL) return -(300+ p-s);

    // kiem tra cac ki tu trong mat khau
    // kiem tra cac ki tu lien tiep
    i = 0;
    bool kitudacbiet = false;
    bool kitulientiep = false;
    int vitrikitulientiep;


    for (int i = 2; i < strlen(s); ++i) {
        if(i>1&& s[i]==s[i-1]&&s[i]==s[i-2]){
            vitrikitulientiep = i-2;
            return -(400 + vitrikitulientiep);
        }
    }

    for (const char *ptr = s; *ptr != '\0'; ++ptr)
     {
         if (*ptr == '@' || *ptr == '#' || *ptr == '%' || *ptr == '$' || *ptr == '!')
         {
             kitudacbiet = true;
             break;
         }
     }
     if (!kitudacbiet)
     {
         return -5;
     }


    /*Mỗi ký tự trong mật khẩu chỉ có thể là chữ số, hoặc chữ cái thường, hoặc chữ cái in
    hoa, hoặc ký tự đặc biệt. Ký tự đặc biệt là một trong các ký tự sau: ’@’, ’#’, ’%’, ’$’, ’!’*/


    for (int i = 0; i < strlen(s); ++i) {
        if (!isalnum(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') {
            return i;
        }

    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    //tao mang luu so lan xuat hien cua mkhau
    int xuathien[50]={0};

    //tao mang luu do dai cua 1 mkhau
    int dodai[50]={0};

    //tinh so lan xuat hien va do dai tung mkhau
    for(int i=0; i<num_pwds; i++){
        const char *mkhau = arr_pwds[i];
        int len=strlen(mkhau);
        dodai[i] = len;
        for(int j=0;j<num_pwds;j++){
            if(strcmp(mkhau, arr_pwds[j])==0){
                xuathien[i]++;
            }
        }
    }
    //tim so lan xuat hien nhieu nhat
    int maxoccur=0;
    for(int i=0;i<num_pwds;i++){
        maxoccur = (maxoccur>xuathien[i])?maxoccur:xuathien[i];
    }

    //tim mkhau co so lan xuat hien nhieu nhat va co so ki tu dai nhat
    int vitrimkdainhat = 0;
    int dodaicuamkdainhat=0;
    for(int i=0;i<num_pwds;i++){
        if(xuathien[i]==maxoccur&&dodai[i]>dodaicuamkdainhat){
            vitrimkdainhat=i;
            dodaicuamkdainhat=dodai[i];
        }
    }
    return vitrimkdainhat;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
