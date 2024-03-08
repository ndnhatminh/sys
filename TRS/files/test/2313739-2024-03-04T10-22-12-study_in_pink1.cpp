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
//Hàm kiểm tra EXP
void checkEXP(int &EXP1)
{  if (EXP1<0) EXP1=0;
   else if (EXP1>600) EXP1=600;  
}
//Ham kiểm tra HP
void checkHP(int &HP1)
{  if (HP1<0) HP1=0;
   else if (HP1>666) HP1=666; 
}
// Hàm kiểm tra M
void checkM(int &M1)
{  if (M1<0) M1=0;
   else if (M1>3000) M1=3000; 
}
//Trường hợp 1 
void firstMeet_Case1(int &EXP1, int &EXP2, int E1)
{   checkEXP(EXP1);checkEXP(EXP2);
    int arr[4]={29,45,75,149},D=E1*3+EXP1*7;
    EXP2+=arr[E1];
    if(D%2) EXP1-=floor(D/100.0);
    else EXP1+=ceil(D/200.0);
    checkEXP(EXP1);checkEXP(EXP2);
}
//Trường hợp 2
void firstMeet_Case2(int &EXP1, int &EXP2, int E1)
{   checkEXP(EXP1);checkEXP(EXP2);
    EXP1-=E1;
        if(E1<=19)  EXP2+=19+ceil(E1/4.0);
   else if(E1<=49)  EXP2+=21+ceil(E1/9.0);
   else if(E1<=65)  EXP2+=17+ceil(E1/16.0);
   else if(E1<=79)  {EXP2+=19+ceil(E1/4.0);checkEXP(EXP1);checkEXP(EXP2);if (EXP2>200) EXP2+=21+ceil(E1/9.0);}
   else if(E1<=99)  {EXP2+=19+ceil(E1/4.0);
                     checkEXP(EXP1);checkEXP(EXP2);
                     EXP2+=21+ceil(E1/9.0);
                     checkEXP(EXP1);checkEXP(EXP2);
                     if(EXP2>400) {EXP2+=17+ceil(E1/16.0);checkEXP(EXP1);checkEXP(EXP2);EXP2=ceil(EXP2*23.0/20);} }
     checkEXP(EXP1);checkEXP(EXP2);
}
//Hoàn thành task1: Tùy theo giá trị E1 mà thực hiện TH1 hoặc TH2
int firstMeet(int & exp1, int & exp2, int e1) {
     if (e1 < 0 || e1 > 99) return -99;
else if (e1<=3) firstMeet_Case1(exp1,exp2,e1);
else if (e1<=99) firstMeet_Case2(exp1,exp2,e1);
    return exp1 + exp2;
}
// Task 2
//Con đường 1
//Trả về giá trị P1
double traceLuggage_Street1(int EXP1)
{checkEXP(EXP1);
    int N=sqrt(EXP1),N1=EXP1-N*N,N2=(N+1)*(N+1)-EXP1;
 double P1;
     if (N1<N2) P1=1;
     else P1=(EXP1/(EXP1+N2)+80)/123.0;
    return P1;    
}
//Con đường 2
//Gồm 3 sự kiện riêng biệt với thứ tự thực hiện phụ thuộc vào E2
//Sự kiện 1
void traceLuggage_Street2_Event1(int &HP1,int &M1)
{checkHP(HP1);checkM(M1);
 if (HP1<200) {HP1=ceil(HP1*13.0/10);M1-=150;}
 else {HP1=ceil(HP1*11.0/10);M1-=70;}
 checkHP(HP1);checkM(M1);
}
//Sự kiện 2
void traceLuggage_Street2_Event2(int &EXP1,int &M1)
{checkEXP(EXP1);checkM(M1);
    if (EXP1<400) M1-=200;
 else M1-=120;
 EXP1=ceil(EXP1*113.0/100);
 checkEXP(EXP1);checkM(M1);
}
//Sự kiện 3
void traceLuggage_Street2_Event3(int &EXP1,int &M1)
{ checkEXP(EXP1);checkM(M1);
 if (EXP1<300) M1-=100;
 else M1-=120;
 EXP1=ceil(EXP1*9.0/10);
 checkEXP(EXP1);checkM(M1);
}
//Tính toán thay đổi HP1,EXP1,M1 sau chuỗi sự kiện
void traceLuggage_Street2(int &HP1, int &EXP1, int &M1, int E2)
{ checkM(M1);checkHP(HP1);checkEXP(EXP1);
 int M=M1;
 if (M1!=0)
    {if (E2%2){ 
     while(1)
        {traceLuggage_Street2_Event1(HP1,M1);
        if (2*M1<M) break;
        traceLuggage_Street2_Event2(EXP1,M1);
        if (2*M1<M) break;
        traceLuggage_Street2_Event3(EXP1,M1);
        if (2*M1<M) break;
        }
               }
    
 else  {traceLuggage_Street2_Event1(HP1,M1);
                   if (M1!=0) {traceLuggage_Street2_Event2(EXP1,M1);
                               if (M1!=0) {traceLuggage_Street2_Event3(EXP1,M1);}
                              }
                  }
    }
      
       
 HP1=ceil(HP1*83.0/100);EXP1=ceil(EXP1*117.0/100);
 checkEXP(EXP1);
}
//Vì giá trị P2 tính giống P1 nên dùng lại hàm P1 cho P2
//Con đường 3
//Trả về giá trị P3
double traceLuggage_Street3(int E2)
{double P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11},P3;
if (E2>=10) {E2=E2%10+(E2-E2%10)/10;E2=E2%10;}
P3=P[E2];
return P3;
}
//Các thay đổi khi biết P - gọi là debuff
//P=100%
void debuff1(int &EXP1)
{EXP1=ceil(EXP1*75.0/100);
}
//P<50%
void debuff2(int &EXP1,int &HP1)
{EXP1=ceil(EXP1*115.0/100);checkEXP(EXP1);
 HP1=ceil(HP1*85.0/100);
}
//P>=50%
void debuff3(int &EXP1,int &HP1)
{EXP1=ceil(EXP1*12.0/10);checkEXP(EXP1);
 HP1=ceil(HP1*90.0/100);
}
//Hoàn thành Task2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
   if (E2 < 0 || E2 > 99) return -99;
else {double P1,P2,P3,P;
P1=traceLuggage_Street1(EXP1);
traceLuggage_Street2(HP1, EXP1, M1, E2);
P2=traceLuggage_Street1(EXP1);
P3=traceLuggage_Street3(E2)/100;
P=(P1+P2+P3)/3;
if (P==1) debuff1(EXP1);
else if (P<0.5) debuff2(EXP1,HP1);
else if (P>=0.5) debuff3(EXP1,HP1);}
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    //Tạo ma trận 10x10, gán giá trị từng ô
int matrix10[10][10];
for (int i=0;i<=9;i++)
{
    for (int j=0;j<=9;j++)
    {
        matrix10[i][j]=((E3 * j) + (i * 2)) * (i - j);
    }
}
//Tìm số giá trị >2*E3 và số giá trị<-E3
int bigger=0,smaller=0;
for (int i=0;i<=9;i++)
{
    for (int j=0;j<=9;j++)
    {
        if (matrix10[i][j]>E3*2) bigger+=1;
        else if (matrix10[i][j]<-E3) smaller+=1;
    }
}
//Tìm vị trí của taxi
while (bigger>=10) bigger=(bigger - (bigger%10))/10+bigger%10;
while (smaller>=10) smaller=(smaller - (smaller%10))/10+smaller%10;
//Chia các ô chứa giá trị của 2 thám tử làm 4 đường chéo
//Tính MAX tại 4 đường chéo
int MAX=matrix10[bigger][smaller];
int i1=bigger,j1=smaller,i2=bigger,j2=smaller,i3=bigger,j3=smaller,i4=bigger,j4=smaller,trave;
while (i1>=0&&j1>=0)
{
    if (matrix10[i1][j1]>MAX) MAX=matrix10[i1][j1];
    i1--;j1--;
}
while (i2<=9&&j2>=0)
{
    if (matrix10[i2][j2]>MAX) MAX=matrix10[i2][j2];
    i2++;j2--;
}
while (i3>=0&&j3<=9)
{
    if (matrix10[i3][j3]>MAX) MAX=matrix10[i3][j3];
    i3--;j3++;
}
while (i4<=9&&j4<=9)
{
    if (matrix10[i4][j4]>MAX) MAX=matrix10[i4][j4];
    i4++;j4++;
}
//Hoàn thành task3
   if (E3 < 0 || E3 > 99) return -99;
else if (abs(matrix10[bigger][smaller])>MAX) 
{   checkHP(HP1);checkEXP(EXP1);checkHP(HP2);checkEXP(EXP2);
    EXP1=ceil(EXP1*88.0/100);HP1=ceil(HP1*90.0/100);
    EXP2=ceil(EXP2*88.0/100);HP2=ceil(HP2*90.0/100);
    checkHP(HP1);checkEXP(EXP1);checkHP(HP2);checkEXP(EXP2);
    trave=matrix10[bigger][smaller]; 
}
else {checkHP(HP1);checkEXP(EXP1);checkHP(HP2);checkEXP(EXP2);
      EXP1=ceil(EXP1*112.0/100);HP1=ceil(HP1*110.0/100);
      EXP2=ceil(EXP2*112.0/100);HP2=ceil(HP2*110.0/100);
      checkHP(HP1);checkEXP(EXP1);checkHP(HP2);checkEXP(EXP2);
      trave=MAX;}
    
   return trave;
    return -1;
}
// Task 4
int checkPassword(const char * s, const char * email) {
 
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string s;
    int max = 0, maxsize=0, vt=-1;
    for(int i =0; i< num_pwds; i++){
        int size = 0;
        string c = arr_pwds[1];
        int dem = 0;
        for(int j = 0; j < num_pwds; j++){
            if(arr_pwds[j]==c){
                dem++;
            }
        }
        if(dem > max) vt=1;
        else if(dem >= max){
            max = dem;
            s = c;
            size = c.size();
        }
        if(size > maxsize){
            maxsize = size;
            vt = 1;
        }
    } return vt;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////