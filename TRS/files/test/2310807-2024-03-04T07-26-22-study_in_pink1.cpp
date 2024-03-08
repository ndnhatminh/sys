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
void chinhgiatrichoexp(int &exp){
    if(exp>600)exp=600;
    if(exp<0)exp=0;
    exp=ceil(exp);

}
void chinhgiatrichohp(int &hp){
    if(hp>666)hp=666;
    if(hp<0)hp=0;
    hp=ceil(hp);
    
}
void chinhgiatrichomoney(int &m){
    if(m>3000)m=3000;
    if(m<0)m=0;
    m=ceil(m);
    
}

//! Task 1
int firstMeet(int &EXP1, int &EXP2, int E1)
{int D=E1*3+EXP1*7;
    if (E1 < 0 || E1 > 99) return -99;
if(E1>=0&&E1<=3){
    switch(E1){
        case 0:
        EXP2+=29;
        break;
        case 1:
        EXP2+=45;
        break;
        case 2:
        EXP2+=75;
        break;
        case 3:
        EXP2=EXP2+29+45+75;
        break;
    }
 //Sherlock sẽ đưa ra dự đoán thiên về Afghanistan   
   if(D%2==0){
    EXP1=ceil(EXP1+D/200.0);
   }
   else  EXP1 = ceil(EXP1 - D/100.0);
   EXP1=ceil(EXP1); 
}
if(E1>=4&&E1<=99){
    if(E1>=4&&E1<=19)EXP2+=ceil(E1/4.0+19);
    if(E1>=20&&E1<=49)EXP2+=ceil(E1/9.0+21);
    if(E1>=50&&E1<=65)EXP2+=ceil(E1/16.0+17);
    if(E1>=66&&E1<=79){EXP2+=ceil(E1/4.0+19);
    if(EXP2>200)EXP2+=ceil(E1/9.0+21);}
    if(E1>=80&&E1<=99){
        EXP2+=ceil(E1/4.0+19);
        EXP2+=ceil(E1/9.0+21);
        if(EXP2>400){EXP2+=ceil(E1/16.0+17);
        EXP2+=ceil(EXP2*15.0/100);
    }
}

EXP1-=E1;
}   
if(EXP1>600)EXP1=600;
if(EXP1<0)EXP1=0;
if(EXP2>600)EXP2=600;
if(EXP2<0)EXP2=0;
    return EXP1 + EXP2;
}
//Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{if (E2 < 0 || E2 > 99) return -99;
    chinhgiatrichoexp(EXP1);
    chinhgiatrichohp(HP1);
    chinhgiatrichomoney(M1);
  /*con duonng 1*/  
    //giai thuat duyet va so sanh
    int n=floor(sqrt(EXP1));
   int s1;
   if(EXP1-n*n>(n+1)*(n+1)-EXP1)s1=pow(n+1,2);
   else s1=pow(n,2);
int tienbandau,tienchitra=0;
    float P1,P2,P3;
    tienbandau=M1;
    if(EXP1>=s1)P1=100.0;
    else P1=((1.0*EXP1/s1+80)/123)*100;
    /*con duong 2*/
    //e2 le
    while(E2%2==1){ 
        //SU KIEN 1
        if(M1==0)break;
        if(HP1<200){
        HP1=ceil(float(HP1*130.0/100));
       chinhgiatrichohp(HP1);
        M1-=150;
        chinhgiatrichomoney(M1);
        tienchitra+=150;
    }
    else {
        HP1=ceil(float(HP1*110.0/100));
        chinhgiatrichohp(HP1);
        M1-=70;
        tienchitra+=70;
        chinhgiatrichomoney(M1);
    } if(tienchitra>(float(tienbandau/2.0)))break;
    //SU KIEN 2
  if(EXP1<400){M1-=200;
  chinhgiatrichomoney(M1);
  tienchitra+=200;}
  else{M1-=120;
  chinhgiatrichomoney(M1);
  tienchitra+=120;}
  EXP1=ceil(float(EXP1*113.0/100));
  chinhgiatrichoexp(EXP1);
  if(tienchitra>(tienbandau/2.0))break;
//SU KIEN 3
if(EXP1<300){M1-=100;
chinhgiatrichomoney(M1);
tienchitra+=100;}
else{M1-=120;
chinhgiatrichomoney(M1);
tienchitra+=120;}
EXP1=ceil(float(EXP1*90.0/100));
chinhgiatrichoexp(EXP1);
if(tienchitra>tienbandau/2.0)break;
}
;
//e2 chan
while(E2%2==0){
        //SU KIEN 1
        if(M1==0)break;
        if(HP1<200){
        HP1=ceil(float(HP1*130.0/100));
        chinhgiatrichohp(HP1);
        M1-=150;
        chinhgiatrichomoney(M1);
        tienchitra+=150;
    }
    else {
        HP1=ceil(float(HP1*110.0/100));
        chinhgiatrichohp(HP1);
        M1-=70;
        chinhgiatrichomoney(M1);
        tienchitra+=70;
    } if(M1==0)break;
    //SU KIEN 2
  if(EXP1<400){M1-=200;
  chinhgiatrichomoney(M1);
  tienchitra+=200;}
  else{M1-=120;
  chinhgiatrichomoney(M1);
  tienchitra+=120;}
  EXP1=ceil(float(EXP1*113.0/100));
  chinhgiatrichoexp(EXP1);
  if(M1==0)break;
//SU KIEN 3
if(EXP1<300){M1-=100;
chinhgiatrichomoney(M1);
tienchitra+=100;}
else{M1-=120;
chinhgiatrichomoney(M1);
tienchitra+=120;}
EXP1=ceil(float(EXP1*90.0/100));
chinhgiatrichoexp(EXP1);
break;
};
HP1=ceil(float(HP1*83.0/100));
chinhgiatrichohp(HP1);
EXP1=ceil(float(EXP1*117.0/100));
chinhgiatrichoexp(EXP1);
   int s2;
   int n1=floor(sqrt(EXP1));
   if(EXP1-n1*n1>(n1+1)*(n1+1)-EXP1)s2=pow(n1+1,2);
   else s2=pow(n1,2);
    if(EXP1>=s2)P2=100.0;
    else P2=((1.0*EXP1/s2+80)/123.0)*100.0;
 /*con duong 3*/
  int p[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
  int i;
  if(E2<10){
    i=E2;
    P3=p[i];
  }
  if(E2>=10){i=((E2/10)+(E2%10))%10;
  P3=p[i];}
  /*ket thuc*/ 
  if(P1==100&&P2==100&&P3==100){EXP1=ceil(float(EXP1*75.0/100));
  chinhgiatrichoexp(EXP1);}
else{
    float P=1.0*(P1+P2+P3)/3;
    if(P<50){
        HP1=ceil(float(HP1*85.0/100));
        chinhgiatrichohp(HP1);
        EXP1=ceil(float(EXP1*115.0/100));
        chinhgiatrichoexp(EXP1);
    }
    else{
        HP1=ceil(float(HP1*90.0/100));
        EXP1=ceil(float(EXP1*120.0/100));
        chinhgiatrichoexp(EXP1);
        chinhgiatrichohp(HP1);
    }
    
}

    return HP1 + EXP1 + M1;
}
//Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{ if (E3 < 0 || E3 > 99) return -99;
int arr[10][10];
int a,b,taxipoint,sherlockpoint,giatritrave;//dong va cot cua taxi point
int bigger=0,smaller=0;
for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){arr[i][j]=((E3*j)+(i*2))*(i-j);
if(arr[i][j]>E3*2)bigger+=1;
if(arr[i][j]<-E3)smaller+=1;
    }
}
a=(bigger/10)+(bigger%10);
if(a>=10)a=(a/10)+(a%10);
b=(smaller/10)+(smaller%10);
if(b>=10)b=(b/10)+(b%10);
taxipoint=arr[a][b];
sherlockpoint=arr[a][b];
for(int i=0;i<10;i++){
    if(arr[a+i][b+i]>sherlockpoint)sherlockpoint=arr[a+i][b+i];
    if(a+i==9||b+i==9)break;
}
for(int i=0;i<10;i++){
        if(arr[a-i][b+i]>sherlockpoint)sherlockpoint=arr[a-i][b+i];
        if(a-i==0||b+i==9)break;
}
for(int i=0;i<10;i++){
        if(arr[a+i][b-i]>sherlockpoint)sherlockpoint=arr[a+i][b-i];
if(a+i==9||b-i==0)break;
}
for(int i=0;i<10;i++){
        if(arr[a-i][b-i]>sherlockpoint)sherlockpoint=arr[a-i][b-i];
    if(a-i==0||b-i==0)break;
}
if(abs(taxipoint)>sherlockpoint){
    EXP1=ceil(EXP1-EXP1*12.0/100);
    EXP2=ceil(EXP2-EXP2*12.0/100);
    HP1=ceil(HP1-HP1*10.0/100);
    HP2=ceil(HP2-HP2*10.0/100);
    chinhgiatrichoexp(EXP1);
    chinhgiatrichoexp(EXP2);
    chinhgiatrichohp(HP1);
    chinhgiatrichohp(HP2);
    giatritrave=taxipoint;
}
else{ EXP1=ceil(EXP1+EXP1*12.0/100);
    EXP2=ceil(EXP2+EXP2*12.0/100);
    HP1=ceil(HP1+HP1*10.0/100);
    HP2=ceil(HP2+HP2*10.0/100);
    chinhgiatrichoexp(EXP1);
    chinhgiatrichoexp(EXP2);
    chinhgiatrichohp(HP1);
    chinhgiatrichohp(HP2);
giatritrave=sherlockpoint;
}
    return giatritrave;
}
//Task 4
int checkPassword(const char *s, const char *email)
{char *se;
const char *tro;
se=new char[101];
char search='@';
tro=strchr(email,search);
if (tro != nullptr){int n=tro-email;
strncpy(se,email,n);
se[n] = '\0';}
if(strlen(s)<8)return -1;
if(strlen(s)>20)return -2;
//kiem tra s co chua se hay ko
const char *check=strstr(s,se);
if(check!=NULL){int sei=check-s;
     return -(300+sei);}
//kiem tra co nhieu  hơn 3 ki tu lien tiep bang nhay hay ko
for(int i=0;i<strlen(s)-1;i++){
    if((*(s+i)==*(s+i+1))&&(*(s+i)==*(s+i+2)))return -(400+i);
}
// kiem tra s co ki tu dac biet hay ko
bool thoamandieukien3 = false;
char kitudacbiet[] = "@#%$!";
for (int i = 0; i < strlen(s); i++) {
    if (strchr(kitudacbiet, *(s + i))!= nullptr) {
        thoamandieukien3 = true;
        break;  // Ngưng vòng lặp 
    }
}

if (!thoamandieukien3) {
    return -5;
}
//kiem tra cac dieu kien con lai
bool thoaManDieuKien4 = true;
int kitudautien;
for(int i=0;i<strlen(s);i++){
    if(!((*(s+i)>='0'&&*(s+i)<='9')||(*(s+i)>='a'&&*(s+i)<='z')||(*(s+i)>='A'&&*(s+i)<='Z')||(strchr(kitudacbiet, *(s + i)) != NULL))
){thoaManDieuKien4 = false;
    kitudautien=i;
    break;
}
}
if (thoaManDieuKien4) {
    return -10;
} else {
    return kitudautien;
}
}
//Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{int position = -1;  // vi tri cua mat khau dung
    int maxFrequency = 0;  // tan suat max
    int maxLength = 0;  // do dai max

    for (int i = 0; i < num_pwds; i++) {
        int currentFrequency = 0;//tan suat phan tu i
        int currentLength = strlen(arr_pwds[i]);//do dai phan tu i

        // dem tan suat
        for (int j = i+1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                currentFrequency++;
            }
        }
        // check dieu kien va do dai
        if (currentFrequency > maxFrequency || (currentFrequency == maxFrequency && currentLength > maxLength)) {
            maxFrequency = currentFrequency;
            maxLength = currentLength;
            position = i;
        }
}

    return position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////