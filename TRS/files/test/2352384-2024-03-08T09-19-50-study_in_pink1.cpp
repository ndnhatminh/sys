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
//Task1
int firstMeet(int &EXP1, int &EXP2, int E1)
{
    if (E1 < 0 || E1 > 99)
    {
        return -99;
    }

    if (E1 >= 0 && E1 <= 3)
    {
        switch (E1)
        {
        case 0:
            EXP2 += 29;
            break;
        case 1:
            EXP2 += 45;
            break;
        case 2:
            EXP2 += 75;
            break;
        case 3:
            EXP2 += 149;
            break;
        }
        int D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0)
        {
            EXP1 += ceil((double)D / 200);
        }
        else
        {
            EXP1 -= D / 100;
        }
    }
    else if (E1 <= 99)
    {
        EXP1 -= E1;
        switch (E1)
        {
        case 4 ... 19:
            EXP2 += ceil(((double)E1 / 4) + 19);
            break;
        case 20 ... 49:
            EXP2 += ceil(((double)E1 / 9) + 21);
            break;
        case 50 ... 65:
            EXP2 += ceil(((double)E1 / 16) + 17);
            break;
        case 66 ... 79:
            EXP2 += ceil(((double)E1 / 4) + 19);
            if (EXP2 > 200)
            {
                EXP2 += ceil(((double)E1 / 9) + 21);
            }
            break;
        case 80 ... 99:
            EXP2 = ceil(EXP2 + ((double)E1 / 4) + 19);
            EXP2 = ceil(EXP2 + ((double)E1 / 9) + 21);
            if (EXP2 > 400)
            {
                EXP2 += ceil(((double)E1 / 16) + 17);
                EXP2 += ceil((double)EXP2 * 0.15);
            }
            break;
        }
    }
    if (EXP1 < 0)
    {
        EXP1 = 0;
    }
    else if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    if (EXP2 < 0)
    {
        EXP2 = 0;
    }
    else if (EXP2 > 600)
    {
        EXP2 = 600;
    }
    return EXP1 + EXP2;
}
//Task2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E3)
{
     if (E3 > 99 || E3 < 0)
        return -99;
      if (EXP1<0){
        EXP1=0;
    }
    else if (EXP1>600){
        EXP1=600;
    }
if (M1<0){
    M1=0;
}
else if (M1>3000){
    M1=3000;
}
if(HP1<0){
    HP1=0;
}
else if(HP1>666){
    HP1=666;
}  

        //con duong 1

    int S= sqrt(EXP1);
    double P1;
    if((EXP1-S*S)>((S+1)*(S+1)-EXP1)){
        S=(S+1)*(S+1);
    }
    else S=S*S;
if (EXP1>=S){
  P1=100;
}
else P1=((((double)EXP1/S)+80)/123)*100;


//con duong 2

if(M1>0){
if(E3%2!=0){
double half_money=M1*50.0/100;
int used_money=0;
if (M1>0)
while (true){
    
if (HP1<200){
  if (used_money > half_money)
break;
  HP1+=ceil((double)HP1*30.0/100);
  M1-=150;
  used_money+=150;
}
else {
    HP1+=ceil((double)HP1*10.0/100);
M1-=70;
used_money+=70;
}
if(HP1<0){
    HP1=0;
}
else if(HP1>666){
    HP1=666;
}  
if (used_money > half_money)
break;
if(EXP1<400){
   M1-=200;
  EXP1+=ceil((double)EXP1*13.0/100);
  used_money+=200;
}
else {
  M1-=120;
  EXP1+=ceil((double)EXP1*13.0/100);
  used_money+=120;
}
if (used_money > half_money)
break;
if (EXP1<300){
    M1-=100;
    
    used_money+=100;
}
else{
    M1-=120;

    used_money+=120;
}
EXP1-=floor((double)EXP1*10.0/100);
if (used_money > half_money)
break;
}
if(HP1<0){
    HP1=0;
}
else if(HP1>666){
    HP1=666;
}  
HP1-=floor((double)HP1*17.0/100);
EXP1+=ceil((double)EXP1*17.0/100);
    
}
else {
  while (true){
    if (M1>0){
    if (HP1<200){
  HP1+=ceil((double)HP1*30.0/100);
  M1-=150;
}
else {
    HP1+=ceil((double)HP1*10.0/100);
M1-=70;
}
}
else{
  M1=0;
  break;
}

if (M1>0){
if (EXP1<400){
  M1-=200;
  EXP1+=ceil((double)EXP1*13.0/100);
}
else {
  M1-=120;
  EXP1+=ceil((double)EXP1*13.0/100);
}
}
else {
  M1=0;
  break;
  }
if (M1>0){
if (EXP1<300){
    M1-=100;
    EXP1-=floor((double)EXP1*10.0/100);
}
else{
    M1-=120;
    EXP1-=floor((double)EXP1*10.0/100);
}
}

else {
  M1=0;
break;}
break;
}
if(HP1<0){
    HP1=0;
}
else if(HP1>666){
    HP1=666;
}  
HP1-=floor((double)HP1*17.0/100);
EXP1+=ceil((double)EXP1*17.0/100);
}
}
else if (M1==0) {
    HP1-=floor((double)HP1*17.0/100);
EXP1+=ceil((double)EXP1*17.0/100);
}
if (EXP1<0){
        EXP1=0;
    }
    else if (EXP1>600){
        EXP1=600;
    }
if (M1<0){
    M1=0;
}
else if (M1>3000){
    M1=3000;
}
if(HP1<0){
    HP1=0;
}
else if(HP1>666){
    HP1=666;
}
int a= sqrt(EXP1);
double P2;
    if((EXP1-a*a)>((a+1)*(a+1)-EXP1)){
        a=(a+1)*(a+1);
    }
    else a=a*a;
if (EXP1>=a){
  P2=100;
}
else P2=((((double)EXP1/a)+80)/123)*100;
if (EXP1<0){
        EXP1=0;
    }
    else if (EXP1>600){
        EXP1=600;
    }
if (M1<0){
    M1=0;
}
else if (M1>3000){
    M1=3000;
}
if(HP1<0){
    HP1=0;
}
else if(HP1>666){
    HP1=666;
}

//con duong 3

double P3;
int P[]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
int i;
if (E3<=9){
  i=E3;
  P3=P[i];
}
else if (E3<=99){
  i= E3%10 + E3/10;
  i= i%10;
  P3=P[i];
}
//Tong ket

double xac_suat;
if (P1==100 && P2==100 && P3==100){
  EXP1-=floor((double)EXP1*25.0/100);
}
else {
  xac_suat=(P1+P2+P3)/3;
if( xac_suat <50){
  HP1-=floor((double)HP1*15.0/100);
  EXP1+=ceil((double)EXP1*15.0/100);
}
else {
  HP1-=floor((double)HP1*10.0/100);
  EXP1+=ceil((double)EXP1*20.0/100);
}
if (EXP1<0){
        EXP1=0;
    }
    else if (EXP1>600){
        EXP1=600;
    }
if (M1<0){
    M1=0;
}
else if (M1>3000){
    M1=3000;
}
if(HP1<0){
    HP1=0;
}
else if(HP1>666){
    HP1=666;
}
   
    return HP1 + EXP1 + M1;
}
return HP1 + EXP1 + M1;
}
//Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 > 99 || E3 < 0)
        return -99;

int array [10][10]={0};
int bigger=0;
int smaller=0;
for (int i=0; i<10;i++){
    for(int j=0;j<10;j++){
        array[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        if (array[i][j]>2*E3){
            bigger++;
        }
        else if(array[i][j]< -E3){
            smaller++;
        }
    }}
    while (true){
        bigger = bigger/10 + bigger%10;
        if (bigger<10)
        break;
    }
     while (true){
        smaller = smaller/10 + smaller%10;
        if (smaller<10)
        break;
    }
    int diem_cua_taxi_khi_gap_nhau= array[bigger][smaller];
    //Th1
    int diem_cua_sherlock=diem_cua_taxi_khi_gap_nhau;
for (int i=0;i<10;i++){
    if (bigger-i <0 || smaller-i<0)
    break;
   if (array[bigger-i][smaller-i]> diem_cua_sherlock){
     diem_cua_sherlock=array[bigger-i][smaller-i];
   }
}
//Th2
for (int i=0;i<10;i++){ 
    if (bigger-i <0 || smaller+i>9)
    break;
    if(array[bigger-i][smaller+i]>diem_cua_sherlock){
    diem_cua_sherlock=array[bigger-i][smaller+i];
    }
}
//Th3
for(int i=0;i<10;i++){
    if (bigger+i >9 || smaller-i<0)
    break;
    if(array[bigger+i][smaller-i]>diem_cua_sherlock){ 
    diem_cua_sherlock=array[bigger+i][smaller-i];
    }
}
//Th4
for(int i=0;i<10;i++){
    if (bigger+i >9 || smaller+i>9)
        break;
    if(array[bigger+i][smaller+i]>diem_cua_sherlock){
        diem_cua_sherlock=array[bigger+i][smaller+i];
}
}
if (abs(diem_cua_sherlock) < abs (diem_cua_taxi_khi_gap_nhau)){
    EXP1-=floor((double)EXP1*12.0/100);
    EXP2-=floor((double)EXP2*12.0/100);
    HP1-=floor ((double)HP1*10.0/100);
    HP2-=floor ((double)HP2*10.0/100);
    if (EXP1<0){
        EXP1=0;
    }
    else if (EXP1>600){
        EXP1=600;
    }
if(HP1<0){
    HP1=0;
}
else if(HP1>666){
    HP1=666;
}
if (EXP2<0){
        EXP2=0;
    }
    else if (EXP2>600){
        EXP2=600;
    }
if(HP2<0){
    HP2=0;
}
else if(HP2>666){
    HP2=666;
}
    return diem_cua_taxi_khi_gap_nhau;
}
else {
    EXP1+=ceil((double)EXP1*12.0/100);
    EXP2+=ceil((double)EXP2*12.0/100);
    HP1+=ceil((double)HP1*10.0/100);
    HP2+=ceil((double)HP2*10.0/100);
    if (EXP1<0){
        EXP1=0;
    }
    else if (EXP1>600){
        EXP1=600;
    }
if(HP1<0){
    HP1=0;
}
else if(HP1>666){
    HP1=666;
}
if (EXP2<0){
        EXP2=0;
    }
    else if (EXP2>600){
        EXP2=600;
    }
if(HP2<0){
    HP2=0;
}
else if(HP2>666){
    HP2=666;
}
    return abs(diem_cua_sherlock);
}

}
//Task 4
int checkPassword(const char *s, const char *email)
{
char se[101];
 const char* result= strchr(email ,'@');
if(result != nullptr){
    size_t length = result - email; // Độ dài của chuỗi se
   if (length>=100){
    length=100;
   }

    strncpy(se, email, length); 
    se[length] ='\0';}

int do_dai_chuoi_s;
do_dai_chuoi_s=strlen(s);
if(do_dai_chuoi_s<8)
return -1;
else if (do_dai_chuoi_s>20)
return -2;
const char * p =strstr(s,se);
if ( p != nullptr)
return -(300+(p-s));
else {
    for (int i=0; i < do_dai_chuoi_s -2;i++){
if ((s[i]==s[i+1] )&& (s[i]==s[i+2]))
return -(400+i);
}
}
bool SpecialChar= false;
for (int i=0; i < do_dai_chuoi_s ; i++){
    char c= s[i];
    if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
     SpecialChar=true;
     break;
}}
if (!SpecialChar){
return -5;
}
for (int i=0; i < do_dai_chuoi_s  ; i++){
    char b=s[i];
     if (!((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z') || (b >= '0' && b <= '9') || b == '@' || b == '#' || b == '%' || b == '$' || b == '!'))
{
        return i;
        break;
    }
}

return -10;
}
//Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    int xuat_hien_nhieu_nhat = 0; 
    int mat_khau_dai_nhat = 0;
    int vi_tri_mat_khau ; 

    for (int i = 0; i < num_pwds; i++) {
        const char* passwords = arr_pwds[i];
        int do_dai_mat_khau = strlen(passwords);
        int count=0;
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(passwords, arr_pwds[j]) == 0) {
                count++;
            }
            
        }
        if (count > xuat_hien_nhieu_nhat) {
    xuat_hien_nhieu_nhat = count;
    mat_khau_dai_nhat = do_dai_mat_khau;
    vi_tri_mat_khau = i;
} 
else if (count == xuat_hien_nhieu_nhat && do_dai_mat_khau > mat_khau_dai_nhat) {
    mat_khau_dai_nhat = do_dai_mat_khau;
    vi_tri_mat_khau = i;
}
    }

    return vi_tri_mat_khau;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////