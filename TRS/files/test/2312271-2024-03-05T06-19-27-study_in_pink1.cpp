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
int firstMeet(int & exp1, int & exp2, int e1) {
    if(e1>99 || e1<0) return -99;
     if(exp1 >600){
            exp1 =600;
        }
    if(exp2 >600){
            exp2 =600;
        }
    if(exp2 <00){
            exp2 =00;
        }    
    if(exp1 <0){
            exp1 =00;
        }
    float D;
    D = e1 *3 + exp1*7;
    if(e1>=0 && e1<=3){
    if(e1 == 0){
        exp2 = exp2 + 29;
    }
     if(e1 == 1){
        exp2 = exp2 + 45;
    }
     if(e1 == 2){
        exp2 = exp2 + 75;
    }
     if(e1 == 3){
        exp2 = exp2 + 29 + 45 +75;
    }
    if((int)(D)%2==0){
       exp1 =  exp1 + ceil((D/200));
    }
    else 
        exp1 =ceil( exp1 - (D/100));
    }
    if(e1>=4 && e1 <=19){
        exp2 =ceil(exp2 +  (float)(e1/4.0) +19);
         exp1 = exp1 -e1;
    }
     if(e1>=20 && e1 <=49){
        exp2 =ceil(exp2 +  (float)(e1/9.0) +21);
         exp1 = exp1 - e1;

    }
     if(e1>=50 && e1 <=65){
        exp2 =exp2 + ceil((float)(e1/16.0)) +17;
         exp1 = exp1 - e1;
    }
     if(e1>=66 && e1 <=79){
        exp2 =exp2 +  ceil((float)(e1/4.0)) +19;
        if(exp2>200){
             exp2 =exp2 +  ceil((float)(e1/9.0)) +21;
        }
         exp1 = exp1 -e1;
    }
    if(e1>=80 && e1 <=99){
        exp2 = ceil(exp2 +(float)(e1/4.0) +19);
         exp2 =ceil(exp2 +  (float)(e1/9.0) +21);
        if(exp2 >400){
             exp2 =ceil(exp2 +  (float)(e1/16.0) +17);
             exp2 =ceil(exp2*1.15);
        }
        
         exp1 = exp1 - e1;
    }
   
 
 if(exp1 >600){
            exp1 =600;
        }
    if(exp2 >600){
            exp2 =600;
        }
    if(exp2 <00){
            exp2 =00;
        }    
    if(exp1 <0){
            exp1 =00;
        }

   

    return exp1 + exp2;
}
// Task 2
int traceLuggage(int  & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 >99 || E2 < 0) return -99;
if(M1 <0){M1 = 0;}
if(M1 >3000){M1 = 3000;}
if(HP1 <0){HP1 = 0;}
if(HP1 >666){HP1 = 666;}
if(EXP1 <0){EXP1 = 0;}
if(EXP1 >600){EXP1 = 600;}
float P;
//duong1
int S;
float P1;
int a= round(sqrt(EXP1));
S=a*a;
if(EXP1 >=S){
    P1 =100;
}
else {
P1= ((((float)EXP1/S) +80)/123)*100;
}
//duong2
int Mlim = M1/2;
  int Mt = 0;
if(E2%2!=0){
    for(;Mt<=Mlim;){
        if(M1==0)break; 
        if( HP1 < 200 ){
    HP1=ceil(HP1*float(1.3));
    M1= M1-150;
    Mt= Mt+150;
}

else {
    HP1=ceil(HP1*float(1.1));
    M1= M1-70;
    Mt= Mt+70;
    
}
if(M1 <0){M1 = 0;}
if(M1 >3000){M1 = 3000;}
if(HP1 <0){HP1 = 0;}
if(HP1 >666){HP1 = 666;}
if(EXP1 <0){EXP1 = 0;}
if(EXP1 >600){EXP1 = 600;}
if(Mt>Mlim){
    break;}
if(EXP1<400){
    EXP1= ceil(EXP1*float(1.13));
    M1= M1-200;
    Mt= Mt+200;
}
else {
   EXP1=ceil(EXP1*float(1.13));
M1 =M1-120;
Mt =Mt+120;
}
if(M1 <0){M1 = 0;}
if(M1 >3000){M1 = 3000;}
if(HP1 <0){HP1 = 0;}
if(HP1 >666){HP1 = 666;}
if(EXP1 <0){EXP1 = 0;}
if(EXP1 >600){EXP1 = 600;}
    
 if(Mt>Mlim){
    break;
}
if(EXP1 < 300 ){
    EXP1 =ceil( EXP1*float(0.9));
    M1=M1 - 100;
    Mt=Mt + 100;
}
else{ 
    EXP1 =ceil( EXP1*float(0.9));
M1=M1- 120;
Mt=Mt+ 120;
}
}
HP1= ceil(HP1*float(0.83));
EXP1= ceil(EXP1*float(1.17));
if(M1 <0){M1 = 0;}
if(M1 >3000){M1 = 3000;}
if(HP1 <0){HP1 = 0;}
if(HP1 >666){HP1 = 666;}
if(EXP1 <0){EXP1 = 0;}
if(EXP1 >600){EXP1 = 600;}
    }
    
else{
    if( HP1 < 200 && M1>0 ){
    HP1=ceil(HP1*float(1.3));
    M1= M1-150;
}
    else {
        if(M1>0){
    HP1=ceil(HP1*float(1.1));
    M1= M1-70;
}
}
if(M1 <0){M1 = 0;}
if(M1 >3000){M1 = 3000;}
if(HP1 <0){HP1 = 0;}
if(HP1 >666){HP1 = 666;}
if(EXP1 <0){EXP1 = 0;}
if(EXP1 >600){EXP1 = 600;}
    if(EXP1 < 400 &&M1>0){
    M1=  M1 -200;
    EXP1= ceil(EXP1*float(1.13)); 
}
    else {
        if(M1>0){
    M1= M1 - 120;
    EXP1= ceil(EXP1*float(1.13)); 
}
    }
      
if(M1 <0){M1 = 0;}
if(M1 >3000){M1 = 3000;}
if(HP1 <0){HP1 = 0;}
if(HP1 >666){HP1 = 666;}
if(EXP1 <0){EXP1 = 0;}
if(EXP1 >600){EXP1 = 600;}
    if(EXP1 < 300 && M1>0 ){
    M1= M1 - 100;
    EXP1= ceil(EXP1*float(0.9));
}
    else{ 
        if(M1>0){
    M1= M1- 120;
   EXP1= ceil(EXP1*float(0.9));
}

    }
    
    HP1= ceil(HP1*float(0.83));
    EXP1= ceil(EXP1*float(1.17));
   
if(M1 <0){M1 = 0;}
if(M1 >3000){M1 = 3000;}
if(HP1 <0){HP1 = 0;}
if(HP1 >666){HP1 = 666;}
if(EXP1 <0){EXP1 = 0;}
if(EXP1 >600){EXP1 = 600;}
    }
    
    float  P2;
    int b= round(sqrt(EXP1));
    int S2=b*b;

if(EXP1>=S2){
    P2=100;
}
else {
    P2= ((((float)EXP1/S2) +80)/123)*100 ;

}

//duong 3
int arr[100]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
float P3;
int x;
if(E2<10){
 x = E2;
 P3 = arr[x];
}
else {
    int Tongchuso= (E2/10)+(E2%10);
    x = Tongchuso%10;
P3 = arr[x];
}

if(P3 == 100 && P1 == 100 && P2 == 100 ){
    EXP1 =ceil( (float)EXP1*0.75);
}
else{
    P=ceil((P1+P2+P3)/3);
    if(P<50){
       HP1= ceil((float)HP1*0.85);
      EXP1= ceil((float)EXP1*1.15);
    }
    else{
    HP1 =ceil( (float)HP1*0.9);
    EXP1 = ceil((float)EXP1*1.2);
    }
}

if(M1 <0){M1 = 0;}
if(M1 >3000){M1 = 3000;}
if(HP1 <0){HP1 = 0;}
if(HP1 >666){HP1 = 666;}
if(EXP1 <0){EXP1 = 0;}
if(EXP1 >600){EXP1 = 600;}

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {

    // TODO: Complete this function
        // TODO: Complete this function
        if(E3 >99 || E3 < 0) return -99;
if(EXP1 <0){EXP1 = 0;}
if(EXP1 >600){EXP1 = 600;}
if(EXP2 <0){EXP2 = 0;}
if(EXP2 >600){EXP2 = 600;}
if(HP1 <0){HP1 = 0;}
if(HP1 >666){HP1 = 666;}
if(HP2 <0){HP2 = 0;}
if(HP2 >666){HP2 = 666;}
    int a[10][10];
    int i1=0;
    int j1=0;
    int max =0;
    int countp = 0;
   int  countn =0;
    for(int i = 0;i<10;i++){
        for( int j = 0;j<10;j++){
            a[i][j]=((E3*j)+(i*2))*(i-j);
            if(a[i][j]>(E3*2)){
                countp ++;
            }
             if(a[i][j]<(-E3)){
                countn ++;
            }
    }
    }
for(int x =0;x<10;x++){
    i1 = (countp%10)+(countp/10);
    if(i1<10){
        break;
    }
        countp = i1;
}
for(int y =0;y<10;y++){
     j1 = (countn%10)+(countn/10);
    if(j1<10){
        break;
    }
    countn = j1;
}

    for (int i = i1,j = j1;i >= 0 && i < 10 && j >= 0 && j < 10;i--,j++) {
        if (max <a[i][j]) {
            max =a[i][j];
        }
    }

    for (int i = i1, j = j1; i >= 0 && i < 10 && j >= 0 && j < 10; i++, j++) {
        if (max <a[i][j]) {
            max =a[i][j];
        }
    }

    for (int i = i1, j = j1; i >= 0 && i < 10 && j >= 0 && j < 10; i++, j--) {
        if (max < a[i][j]) {
            max = a[i][j];
        }
    }

    for (int i = i1, j = j1; i >= 0 && i < 10 && j >= 0 && j < 10; i--, j--) {
        if (max<a[i][j]) {
            max=a[i][j];
        }
    }

    
    int ketqua;
if(abs(a[i1][j1])>max){
    ketqua = a[i1][j1];
    EXP1 = ceil((float)(EXP1 * 0.88)) ;
HP1 = ceil((float)(HP1 * 0.9)) ;
EXP2 = ceil((float)(EXP2 * 0.88 ));
HP2 = ceil((float)(HP2 * 0.9)) ;
}
else{
    ketqua = max;
 EXP1 = ceil((float)(EXP1 * 1.12)) ;
HP1 = ceil((float)(HP1 * 1.1)) ;
EXP2 = ceil((float)(EXP2 *1.12)) ;
HP2 = ceil((float)(HP2 * 1.1));
}
        if(EXP1 <0){ EXP1 = 0;}
        if(EXP1 >600){EXP1 = 600;}
        if(EXP2 <0){EXP2 = 0;}
        if(EXP2 >600){EXP2 = 600;}
        if(HP1 <0){HP1 = 0;}
        if(HP1 >666){HP1 = 666;}
        if(HP2 <0){HP2 = 0;}
        if(HP2 >666){HP2 = 666;}
    return ketqua;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODo: Complete this function
string pw(s);
string mail(email);
string se = mail.substr(0, mail.find('@'));
char ktdacbiet[] = {'!','@','#','$','%'};
int sci;



if(pw.length()<8) return -1;
if(pw.length()>20) return -2;
int sei = pw.find(se);
if(sei!=string::npos)  //kt trung voi mail
   {return -(300+sei);}
for(int i =0;i<pw.length()-2;i++){//kt neu co hon 2 ki tu lien tiep trung
    if(pw[i]==pw[i+1] && pw[i]==pw[i+2]  ){
    sci = i;
    return-(400+sci);
    }
}

int n = 0;//kt kitu dac biet
   for (int i=0; i<pw.length(); i++){
      for (int j=0; j<5; j++){ 
      if (pw.at(i) == ktdacbiet[j]){
      n++;
}
}
}

    if (n == 0) 
    return -5;
    //ktra con lai
     for (int i=0; i<pw.length(); i++){
         char kthople= pw.at(i);
       if (kthople == '!'||kthople=='@'|| kthople =='#'|| kthople =='$'|| kthople =='%'||(kthople>='1'&&kthople<='9')||(kthople>='A'&&kthople<='Z')||(kthople>='a'&&kthople<='z')){
        continue;
       }
       else return i;
       }
       return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    const char mkcheck[] ="hcmut2312271";
    int countmax = 0;// dem so lan  mk nhieu nhat
    int lenmax = 0;// luu tru mk dai nhat xuat hien nhieu nhat
    int apmax =-1; // luu tru vi tri mk 
    int count;
    for (int i = 0; i < num_pwds; i++) {
        if (strcmp(arr_pwds[i],mkcheck) == 0) continue;
        count = 1;
    for (int j = i + 1; j < num_pwds; j++) {
        if (strcmp(arr_pwds[i],mkcheck) == 0) continue;
        if(strcmp(arr_pwds[i],arr_pwds[j])==0){
            count++;
                arr_pwds[j]=mkcheck;
        }
    
}
        if(count>countmax ||(count == countmax && strlen(arr_pwds[i]) > lenmax)) {
            countmax = count;
            lenmax = strlen(arr_pwds[i]);
            apmax = i;
        }
    }
    return apmax;
    }

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////