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




// Kiem tra va dieu chinh gia tri EXP neu no vuot qua hoac duoi gioi han
void checkEXP(int &EXP1, int &EXP2)
{
    if (EXP1<=0) EXP1=0;
    if (EXP1>=600) EXP1=600;
    if (EXP2<=0) EXP2=0;
    if (EXP2>=600) EXP2=600;
}


// Kiem tra va dieu chinh gia tri HP neu no vuot qua hoac duoi gioi han
void checkHP(int &HP1, int &HP2)
{
    if (HP1<=0) HP1=0;
    if (HP1>=666) HP1=666;
    if (HP2<=0) HP2=0;
    if (HP2>=666) HP2=666;
}


// Kiem tra va dieu chinh gia tri M neu no vuot qua hoac duoi gioi han
void checkM(int &M1, int &M2)
{
    if (M1<=0) M1=0;
    if (M1>=3000) M1=3000;
    if (M2<=0) M2=0;
    if (M2>=3000) M2=3000;
}


//Viet ham lam tron so len
int lts(double s)
{
    if (abs(s-int(s))>1e-9) {
        s=ceil(s);
    }
    return s;
}


/////////////////////////// Task 1 ///////////////////////////




// Truong hop dau tien, dieu chinh gia tri EXP dua tren gia tri e1. EXP2 tang dua tren e1, EXP1 thay doi dua tren D (tinh tu e1 va EXP1). Cuoi cung, kiem tra gia tri EXP.
void firstMeet_Case1(int &EXP1, int &EXP2, int e1)
{
    if (e1==0) EXP2+=29;
    if (e1==1) EXP2+=45;
    if (e1==2) EXP2+=75;
    if (e1==3) EXP2+=149;
    int D=e1*3+EXP1*7;
    if (D%2==0) EXP1+=lts(double(D)/200);
    else EXP1=lts(double(EXP1)-double(D)/100);
}




// Truong hop thu hai, dieu chinh gia tri EXP dua tren gia tri e1. EXP tang, giam dua tren e1. Cuoi cung, kiem tra gia tri EXP.
void firstMeet_Case2(int &EXP1, int &EXP2, int e1)
{
    if ((e1>=4) && (e1<=19)) EXP2+=lts(double(e1)/4)+19;
    else if ((e1>=20) && (e1<=49)) EXP2+=lts(double(e1)/9)+21;
    else if ((e1>=50) && (e1<=65)) EXP2+=lts(double(e1)/16)+17;
    else if ((e1>=66) && (e1<=79)) {
        EXP2+=lts(double(e1)/4)+19;
        if (EXP2>200) EXP2+=lts(double(e1)/9)+21;
    }
    else if ((e1>=80) && (e1<=99)) {
        EXP2+=lts(double(e1)/4)+19;
        EXP2+=lts(double(e1)/9)+21;
        if (EXP2>400) {
		    EXP2+=lts(double(e1)/16)+17;
            EXP2+=lts(EXP2*0.15);
        }
    }
    EXP1=EXP1-e1;
}




// Xu ly cuoc gap go dau tien dua tren gia tri e1. Neu e1 tu 0 den 3, su dung ham firstMeet_Case1. Neu e1 tu 4 den 99, su dung ham firstMeet_Case2. Neu khong, tra ve -99. Cuoi cung, tra ve tong cua EXP1 va EXP2.
int firstMeet(int &EXP1, int &EXP2, int e1)
{
	checkEXP(EXP1, EXP2);
    if ((e1>=0) && (e1<=3)) {
        firstMeet_Case1(EXP1, EXP2, e1);
        checkEXP(EXP1, EXP2);
        return EXP1+EXP2;
    }
    else if ((e1>=4) && (e1<=99)) {
        firstMeet_Case2(EXP1, EXP2, e1);
        checkEXP(EXP1, EXP2);
        return EXP1+EXP2;
    }
    else return -99;
}

/////////////////////////// Task 2 ///////////////////////////
double traceLuggage_Street1(int EXP1)
{
    if (round(sqrt(EXP1))*round(sqrt(EXP1))<=EXP1) return 100;
    else return ((double(EXP1)/((round(sqrt(EXP1))*round(sqrt(EXP1))))+80)/123)*100;
}

// Xu ly hanh ly o Street2 dua tren cac gia tri HP1, EXP1, M1 va e2. Cac su kien khac nhau se thay doi gia tri cua HP1, EXP1 va M1. Cu the, su kien 1 tang HP1 va giam M1, su kien 2 giam M1 va tang EXP1, va su kien 3 giam M1 va giam EXP1. Neu M1 giam xuong duoi mot muc nhat dinh hoac M1 het, thi tang EXP1 va giam HP1. Cuoi cung, kiem tra gia tri cua EXP1 va HP1, va tra ve gia tri tu ham traceLuggage_Street1.
double traceLuggage_Street2(int &HP1, int &EXP1, int &M1, int e2)
{
    double k=double(M1)/2;
if (e2%2!=0) {
    while (double(M1)>=k) {
    if (HP1<200) {
        HP1=lts(1.3*HP1);
        M1-=150;
    }
    else {
        HP1=lts(1.1*HP1);
        M1-=70;
    }
    checkM(M1, M1);
    checkHP(HP1, HP1);
    if (double(M1)<k) break;

//
    if (EXP1<400) {
        M1-=200;
    }
    else {
        M1-=120;
    }
    checkM(M1, M1);
    EXP1=lts(1.13*double(EXP1));
    checkEXP(EXP1, EXP1);
    if (double(M1)<k) break;

//
    if (EXP1<300) {
        M1-=100;
    }
    else {
        M1-=120;
    }
    checkM(M1, M1);
    EXP1=lts(0.9*double(EXP1));
    checkEXP(EXP1, EXP1);
}
} else {          
    if (M1>0) {
    if (HP1<200) {
        HP1=lts(1.3*HP1);
        M1-=150;
    }
    else {
        HP1=lts(double(HP1)*1.1);
        M1-=70;
    }
    checkM(M1, M1);
    checkHP(HP1, HP1);
    }
    if (M1>0)  {
//
    if (EXP1<400) {
        M1-=200;
    }
    else {
        M1-=120;
    }
    checkM(M1, M1);
    EXP1=lts(1.13*EXP1);
    checkEXP(EXP1, EXP1);
    }
    if (M1>0) {
//
    if (EXP1<300) {
        M1-=100;
    }
    else {
        M1-=120;
    }
    checkM(M1, M1);
    EXP1=lts(0.9*EXP1);
    checkEXP(EXP1, EXP1);
}
}

HP1=lts(double(HP1)*0.83);
EXP1=lts(double(EXP1)*1.17);
checkHP(HP1, HP1);
checkEXP(EXP1, EXP1);
return traceLuggage_Street1(EXP1);

}

double traceLuggage_Street3(int e2)
{
    int a[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int x,y,z,i;
    if ((e2>=100) || (e2<0)) cout<<"-99";
    else if ((e2>=0) && (e2<=9)) i=e2;
    else {
            x=e2%10;
            y=e2/10;
            z=x+y;
            i=z%10;
    }
int P3=a[i];
return a[i];
}
// Xu ly hanh ly dua tren cac gia tri HP1, EXP1, M1 va e2. Dau tien, tinh toan cac gia tri P1, P2 va P3 tu cac ham traceLuggage_Street1, traceLuggage_Street2 va traceLuggage_Street3. Neu tat ca P1, P2 va P3 deu bang 100, giam EXP1 xuong 75%. Ngoc lai, tinh trung binh cua P1, P2 va P3. Neu P nho hon 50, tang EXP1 len 15% va giam HP1 xuong 85%. Neu khong, tang EXP1 len 20% va giam HP1 xuong 90%. Cuoi cung, kiem tra gia tri cua EXP1 va HP1, va tra ve tong cua HP1, EXP1 va M1.
int traceLuggage(int &HP1, int &EXP1, int &M1, int e2)
{
	checkHP(HP1, HP1);
    checkEXP(EXP1, EXP1);
    checkM(M1, M1);
    if (e2<0 || e2>99) return -99;
else {
    double P1=traceLuggage_Street1(EXP1);
    double P2=traceLuggage_Street2(HP1, EXP1, M1, e2);
    double P3=traceLuggage_Street3(e2);
    if ((P1==100) && (P2==100) && (P3==100)) EXP1=lts(double(EXP1)*0.75);
    else {
        double P=double(P1+P2+P3)/3;
    if (P<50) {
        HP1=lts(HP1*0.85);
        EXP1=lts(EXP1*1.15);
        checkHP(HP1, HP1);
        checkEXP(EXP1, EXP1);
    }
    else {
        HP1=lts(HP1*0.9);
        EXP1=lts(EXP1*1.2);
        checkHP(HP1, HP1);
        checkEXP(EXP1, EXP1);
    }
    }
    return HP1+EXP1+M1;
}
}

/////////////////////////// Task 3 ///////////////////////////
// Xu ly viec duoi theo taxi dua tren cac gia tri HP1, EXP1, HP2, EXP2 va E3. Dau tien, tinh diem cho taxi va sherlock dua tren cong thuc cho truoc. Sau do, tim vi tri gap nhau dua tren diem cua taxi. Tiep theo, neu i hoac j la so co 2 chu so, thi chuyen doi chung thanh so co 1 chu so. Cuoi cung, tinh diem cuoi cung dua tren diem cua taxi va sherlock tai vi tri gap nhau, dieu chinh gia tri cua HP1, EXP1, HP2 va EXP2 tuong ung, kiem tra gia tri cua EXP1, EXP2, HP1 va HP2, va tra ve diem cuoi cung.
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int e3) {
    // TODO: Complete this function
    checkHP(HP1, HP2);
    checkEXP(EXP1, EXP2);
if (e3<0 || e3>99) return -99;
else {
    int i,j;
// khoi tao mang ma tran duong di cua taxi
    int matrix[10][10];
    for (int i=0; i<=9; i++) {
        for (int j=0; j<=9; j++) {
            matrix[i][j]=((e3*j)+(i*2))*(i-j);
        }
    }
    
// tim kiem vi tri gap nhau thong qua so cac gia tri duong va am cua ma tran taxi thoa man yeu cau
int duong=0;
int am=0;
    for (int i=0; i<=9; i++) {
        for (int j=0; j<=9; j++) {
            if (matrix[i][j]>e3*2) duong++;
            if (matrix[i][j]<0-e3) am++;
        }
    }
    duong=(duong/10)+(duong%10);
    if (duong>=10) duong=(duong/10)+(duong%10);
    am=(am/10)+(am%10);
    if (am>=10) am=(am/10)+(am%10);
    i=duong;
    j=am;
int row = i, col = j, maxVal=matrix[i][j];
    while (row >= 0 && col >= 0) {
        if (matrix[row][col] > maxVal) {
            maxVal = matrix[row][col];
        }
        row--;
        col--;
    }
    
    row = i, col = j;
    while (row <= 9 && col <= 9) {
        if (matrix[row][col] > maxVal) {
            maxVal = matrix[row][col];
        }
        row++;
        col++;
    }
    
    row = i, col = j;
    while (row <= 9 && col >= 0) {
        if (matrix[row][col] > maxVal) {
            maxVal = matrix[row][col];
        }
        row++;
        col--;
    }
    
    row = i, col = j;
    while (row >= 0 && col <= 9) {
        if (matrix[row][col] > maxVal) {
            maxVal = matrix[row][col];
        }
        row--;
        col++;
    }
    
    
    if (abs(matrix[duong][am])>maxVal) {
        EXP1=lts(EXP1*0.88);
        HP1=lts(HP1*0.9);
        EXP2=lts(EXP2*0.88);
        HP2=lts(HP2*0.9);
        checkHP(HP1, HP2);
        checkEXP(EXP1, EXP2);
        return matrix[duong][am];
    }
    else {
        EXP1=lts(EXP1*1.12);
        HP1=lts(HP1*1.1);
        EXP2=lts(EXP2*1.12);
        HP2=lts(HP2*1.1);
        checkHP(HP1, HP2);
        checkEXP(EXP1, EXP2);
        return maxVal;
    }
}
}




/////////////////////////// Task 4 ///////////////////////////


int checkPassword(const char *s, const char *email)
{
    // kiem tra do dai mat khau
    int len = strlen(s);
    if (len < 8) return -1; // mat khau qua ngan
    if (len > 20) return -2; // mat khau qua dai
    
    
    // kiem tra ten nguoi dung co nam trong mat khau hay khong
    const char* pos = strchr(email, '@');    
    size_t email_len = pos - email; 
    char username[email_len];
    strncpy(username, email, email_len);
    const char* substr_pos = strstr(s, username);
	if (substr_pos != nullptr) return 0 - (300 + (substr_pos - s));
	
    // Kiem tra mat khau co chua nhieu hon 2 ki tu lien tiep giong nhau hay khong
    for (int i = 0; i < len - 2; ++i) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            return -(400 + i); 
        }
    }
    
    // Kiem tra mat khau co chua it nhat mot ki tu dac biet hay khong
    
    bool SpecialCharacter = false;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            SpecialCharacter = true;
            break;
        }
    }
    if (!SpecialCharacter) {
        return -5;
    }
    
    // Giai quyet cac truong hop khac
    int k=0, t=0;
    for (int i = 0; i < len; ++i) {
    if (s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!')
    if (!isdigit(s[i]) && !islower(s[i]) && !isupper(s[i])) {
        return i;
        break;
    }
    else {
        t++;
    }
    }
    if (t==len-1) return -10;
    else return -10;
}

/////////////////////////// Task 5 ///////////////////////////

// Tim mat khau dung tu mot mang cac mat khau. Dau tien, khoi tao cac bien de theo doi so luong lon nhat cua mot mat khau xuat hien trong mang, do dai lon nhat cua mat khau va vi tri dau tien cua mat khau do trong mang. Sau do, duyet qua moi mat khau trong mang, dem so luong lan xuat hien cua no va luu do dai cua no. Neu mat khau nay xuat hien nhieu hon hoac cung so lan nhung dai hon mat khau hien tai, cap nhat cac bien theo doi. Cuoi cung, tra ve vi tri dau tien cua mat khau xuat hien nhieu nhat va dai nhat trong mang.
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int dem=0;
    int maxfre=0;
    int fre[num_pwds];
    int skt[num_pwds];
    int maxskt=0;
    for (int i=0; i<num_pwds; i++) {
        skt[i]=0;
        fre[i]=0;
    }
    //so luong lon nhat cua mot mat khau xuat hien trong mang
    for (int i=0; i<num_pwds; i++) {
        for (int j=0; j<num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j])==0) 
                dem++;
        }
        fre[i]=dem;
        dem=0;
        maxfre=max(maxfre, fre[i]);
    }
// tai chi so nao co tan so lap lai lon nhat thi cho mang dem so ki tu cua cac phan tu do thoi
    for (int i=0; i<num_pwds; i++) {
        if (fre[i]==maxfre) {
            skt[i]=strlen(arr_pwds[i]);
            maxskt=max(maxskt, skt[i]);
        }
        else skt[i]=0;
    }
    
     for (int i=0; i<num_pwds; i++) {
        if (skt[i]==maxskt) {
            return i;
        }
     }
    return 0;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////










