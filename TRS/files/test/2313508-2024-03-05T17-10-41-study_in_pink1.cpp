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

//! Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
 // TODO: Complete this function
    //check e1
    if ((e1<0)||(e1>99))  return -99;
    
    //Trường hợp 1
    if ((e1>=0)&&(e1<=3))
    {
    switch (e1) {  
      case 0: exp2= exp2+ 29  ; break;   
      case 1: exp2= exp2+ 45  ; break;    
      case 2: exp2= exp2+ 75  ; break;    
      case 3: exp2= exp2+ 149 ; break;    
    }    
    if (exp2>600) exp2 =600; if (exp2<0) exp2=0;//cập nhật
    if ((e1 * 3 + exp1 * 7)%2==0) 
        exp1 = ceil(exp1+      (e1 * 3 + exp1 * 7)/200.0);
        else   exp1 = ceil(exp1- (e1 * 3 + exp1 * 7)/100.0);
    if (exp1>600) exp1 =600; if (exp1<0) exp1=0;//cập nhật
    }    

    //Trường hợp 2
    if ((e1>=4)&&(e1<=99))

    {
    if      ((e1>=4) &&(e1<=19))       exp2 = ceil(exp2+(e1/4.0+ 19)) ;
    else if ((e1>=20)&&(e1<=49))       exp2 = ceil(exp2+(e1/9.0 + 21)) ;
    else if ((e1>=50)&&(e1<=65))       exp2 = ceil(exp2+(e1/16.0 + 17));
    else if ((e1>=66)&&(e1<=79))      
    {
     exp2 = ceil(exp2+(e1/4.0 + 19)); 
     if (exp2>600) exp2 =600; if (exp2<0) exp2=0;//cập nhật L1
     if (exp2>200) exp2 = ceil(exp2+(e1/9.0+ 21));
     if (exp2>600) exp2 =600; if (exp2<0) exp2=0;//cập nhật L2
    }

    else if ((e1>=80)&&(e1<=99))
    {
    exp2 = ceil(exp2+(e1/4.0 + 19));  
    if (exp2>600) exp2 =600; if (exp2<0) exp2=0;//cập nhật L1
    exp2 = ceil(exp2+(e1/9.0 + 21));
    if (exp2>600) exp2 =600; if (exp2<0) exp2=0;//cập nhật L2

    if (exp2>400) 
    {
       exp2 = ceil(exp2+(e1/16.0 + 17));
       if (exp2>600) exp2 =600; if (exp2<0) exp2=0;//cập nhật L3
       exp2 = ceil(exp2*115.0/100);//BONUS 15%
       if (exp2>600) exp2 =600; if (exp2<0) exp2=0;//cập nhật
    }
    }
    
    if (exp2>600) exp2 =600; if (exp2<0) exp2=0;//cập nhật
    exp1=ceil(exp1-e1);
    if (exp1>600) exp1 =600; if (exp1<0) exp1=0;//cập nhật
    } 
    
    return exp1 + exp2;

}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
//Tìm số chính phương gần với EXP1
   if ((E2<0)  || (E2>99))  return -99;

   int S1, S2;
   double S;
   S1=ceil(sqrt(EXP1)) ;//số tròn lên
   S2=floor(sqrt(EXP1));//số tròn xuống
   S =sqrt(EXP1);
   if (abs(S1-S)>abs(S2-S)) S=S2*S2;
                       else S=S1*S1;
   double P1, P2, P3, P;
  
   // Con đường 01
   if (EXP1>=S) P1=100.0;
           else P1= (EXP1/S+80)*100.0/123; 
  
   // Con đường 02
   int M=M1;//số tiền ban đầu hiện có
   int I=0;// số tiên chi trả
  
    if (M1==0) {            HP1 =ceil(HP1*83.0/100);   if (HP1>666) HP1 =666; if (HP1<0) HP1=0;
                            EXP1=ceil(EXP1*117.0/100); if (EXP1>600) EXP1 =600; if (EXP1<0) EXP1=0;
                            if (EXP1>=S) P2=100.0;
                                    else P2= (EXP1/S+80)*100.0/123;}



    //E2 là số lẻ   
  else if(E2%2==1)

   {
   while (E2%2==1){

    //sự kiện 1
   if (HP1<200) {HP1=ceil(HP1*13.0/10); M1=M1-150;I=I+150;}
           else {HP1=ceil(HP1*11.0/10); M1=M1-70; I=I+70;}

    //cập nhật
    if (HP1>666) HP1 =666; if (HP1<0) HP1=0;
    if (M1>3000) M1 =3000; if (M1<0) M1=0;
    if (I>(M*50.0/100)) {   HP1 =ceil(HP1*83.0/100);   if (HP1>666) HP1 =666; if (HP1<0) HP1=0;
                            EXP1=ceil(EXP1*117.0/100); if (EXP1>600) EXP1 =600; if (EXP1<0) EXP1=0; 
                            S1=ceil(sqrt(EXP1)) ;//số tròn lên
                            S2=floor(sqrt(EXP1));//số tròn xuống
                            S =sqrt(EXP1);
                            if (abs(S1-S)>abs(S2-S)) S=S2*S2;
                                                else S=S1*S1;
                            if (EXP1>=S) P2=100.0;
                                    else P2= (EXP1/S+80)*100.0/123;
                            break;}

   //sự kiện 2
   if (EXP1<400) {M1=M1-200;I=I+200;}
            else {M1=M1-120;I=I+120;}
    EXP1=ceil(EXP1*113.0/100);
 
    //cập nhật
    if (M1>3000) M1 =3000; if (M1<0) M1=0;
    if (EXP1>600) EXP1 =600; if (EXP1<0) EXP1=0; 
    if (I>(M*50.0/100)) {   HP1 =ceil(HP1*83.0/100);   if (HP1>666) HP1 =666; if (HP1<0) HP1=0;
                            EXP1=ceil(EXP1*117.0/100); if (EXP1>600) EXP1 =600; if (EXP1<0) EXP1=0; 
                            S1=ceil(sqrt(EXP1)) ;//số tròn lên
                            S2=floor(sqrt(EXP1));//số tròn xuống
                            S =sqrt(EXP1);
                            if (abs(S1-S)>abs(S2-S)) S=S2*S2;
                                                else S=S1*S1; 
                            if (EXP1>=S) P2=100.0;
                                    else P2= (EXP1/S+80)*100.0/123; 
                            break;}
    
   //sự kiện 3
    if (EXP1<300) {M1=M1-100;I=I+100;}
             else {M1=M1-120;I=I+120;}
    EXP1=ceil(EXP1*9.0/10);

  // 356 36
    //cập nhật
    if (M1>3000) M1 =3000; if (M1<0) M1=0;
    if (EXP1>600) EXP1 =600; if (EXP1<0) EXP1=0;
    if (I>(M*50.0/100)) {   HP1 =ceil(HP1*83.0/100);   if (HP1>666) HP1 =666; if (HP1<0) HP1=0;
                            EXP1=ceil(EXP1*117.0/100); if (EXP1>600) EXP1 =600; if (EXP1<0) EXP1=0; 
                            S1=ceil(sqrt(EXP1)) ;//số tròn lên
                            S2=floor(sqrt(EXP1));//số tròn xuống
                            S =sqrt(EXP1);
                            if (abs(S1-S)>abs(S2-S)) S=S2*S2;
                                                else S=S1*S1;
                            if (EXP1>=S) P2=100.0;
                                    else P2= (EXP1/S+80)*100.0/123;
                            break;}

     
   }
   }
   
   else //E2 là số chẵn
   { 
     //sự kiện 1
     if (HP1<200) {HP1=ceil(HP1*13.0/10); M1=M1-150;}
             else {HP1=ceil(HP1*11.0/10); M1=M1-70;}

    //cập nhật
    if (HP1>666) HP1 =666; if (HP1<0) HP1=0;
    if (M1>3000) M1 =3000; if (M1<0) M1=0;
    if (M1==0) {            HP1 =ceil(HP1*83.0/100);   if (HP1>666) HP1 =666; if (HP1<0) HP1=0;
                            EXP1=ceil(EXP1*117.0/100); if (EXP1>600) EXP1 =600; if (EXP1<0) EXP1=0;
                            S1=ceil(sqrt(EXP1)) ;//số tròn lên
                            S2=floor(sqrt(EXP1));//số tròn xuống
                            S =sqrt(EXP1);
                            if (abs(S1-S)>abs(S2-S)) S=S2*S2;
                                                else S=S1*S1; 
                            if (EXP1>=S) P2=100.0;
                                    else P2= (EXP1/S+80)*100.0/123; }

    else
    //sự kiện 2
    {if (EXP1<400) M1=M1-200;
              else M1=M1-120;
    EXP1=ceil(EXP1*113.0/100);
                
    //cập nhật
    if (M1>3000) M1 =3000; if (M1<0) M1=0;
    if (EXP1>600) EXP1 =600; if (EXP1<0) EXP1=0;
        if (M1==0) {        HP1 =ceil(HP1*83.0/100);   if (HP1>666) HP1 =666; if (HP1<0) HP1=0;
                            EXP1=ceil(EXP1*117.0/100); if (EXP1>600) EXP1 =600; if (EXP1<0) EXP1=0;
                            S1=ceil(sqrt(EXP1)) ;//số tròn lên
                            S2=floor(sqrt(EXP1));//số tròn xuống
                            S =sqrt(EXP1);
                            if (abs(S1-S)>abs(S2-S)) S=S2*S2;
                                                else S=S1*S1; 
                            if (EXP1>=S) P2=100.0;
                                    else P2= (EXP1/S+80)*100.0/123; }
              else {
                                                   
                           //sự kiện 3
                            if (EXP1<300) M1=M1-100;
                                     else M1=M1-120;
                            EXP1=ceil(EXP1*90.0/100);
                                    
                            //cập nhật
                            if (M1>3000) M1 =3000; if (M1<0) M1=0;
                            if (EXP1>600) EXP1 =600; if (EXP1<0) EXP1=0;
                            HP1 =ceil(HP1*83.0/100);   if (HP1>666) HP1 =666; if (HP1<0) HP1=0;
                            EXP1=ceil(EXP1*117.0/100); if (EXP1>600) EXP1 =600; if (EXP1<0) EXP1=0;
                            S1=ceil(sqrt(EXP1)) ;//số tròn lên
                            S2=floor(sqrt(EXP1));//số tròn xuống
                            S =sqrt(EXP1);
                            if (abs(S1-S)>abs(S2-S)) S=S2*S2;
                                                else S=S1*S1; 
                            if (EXP1>=S) P2=100.0;
                                    else P2= (EXP1/S+80)*100.0/123; 
                    }
    }
   }

   

    if (M1>3000) M1 =3000; if (M1<0) M1=0;
    if (HP1>666) HP1 =666; if (HP1<0) HP1=0;
    if (EXP1>600) EXP1 =600; if (EXP1<0) EXP1=0;
    
                        
    //Con đường 03
    int K[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};  
    if ((E2>=0)&&(E2<=9)) P3=K[E2];
                     else P3=K[((E2/10)+(E2%10))%10];  

    if ((P1==100.0)&&(P2==100.0)&&(P3==100))  {EXP1=ceil(EXP1*75.0/100);if (EXP1>600) EXP1 =600; if (EXP1<0) EXP1=0;}
                                        else  {P=(P1+P2+P3)/3; 
    if (P<50) {HP1=ceil(HP1*85.0/100);EXP1=ceil(EXP1*115.0/100); 
               // cập nhật
               if (HP1>666) HP1 =666; if (HP1<0) HP1=0;if (EXP1>600) EXP1 =600; if (EXP1<0) EXP1=0;}

        else  {HP1=ceil(HP1*90.0/100);EXP1=ceil(EXP1*120.0/100);
               // cập nhật
               if (HP1>666) HP1 =666; if (HP1<0) HP1=0;if (EXP1>600) EXP1 =600; if (EXP1<0) EXP1=0;}}
    //cập nhật
    if (HP1>666) HP1 =666; if (HP1<0) HP1=0;
    if (EXP1>600) EXP1 =600; if (EXP1<0) EXP1=0;
    if (M1>3000) M1 =3000; if (M1<0) M1=0;

    return HP1 + EXP1 + M1;
}


int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
if ((E3<0)  || (E3>99))  return -99;
int mt[10][10];
for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			mt[i][j] = ((E3 * j) + (i * 2)) * (i - j);
		}
	}

        int duong, am;
        duong=0; am=0;
for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ((mt[i][j]>0)&&(mt[i][j]>(E3*2))) duong= duong+1;
                        if ((mt[i][j]<0)&&(mt[i][j]<(0-E3))) am=am+1;
		}
	}        
while (duong>9) {duong=duong/10+duong%10;}
while (am>9)    {am=am/10+am%10;}
int taxi=abs(mt[duong][am]);
int diemcu=mt[duong][am];
int diem=0;
int i=duong;
int j=am;
if (duong<=am) {while ((i!=10)&&(j!=-1)) {if (diem<mt[i][j]) diem=mt[i][j];i=i+1;j=j-1;}}

else { while ((i!=10)&&(j!=-1)) {if (diem<mt[i][j]) diem=mt[i][j];i=i+1;j=j-1;} 
       i=duong; j=am;
       
       while  ((i!=j)&&(i<j)) {if (diem<mt[i][j]) diem=mt[i][j];i=i-1;j=j+1;}
        i=duong; j=am;
       while ((i!=10)&&(j!=10))  {if (diem<mt[i][j]) diem=mt[i][j];i=i+1;j=j+1;}
       i=duong; j=am;
        while ((i!=-1)&&(j!=-1)) {if (diem<mt[i][j]) diem=mt[i][j];i=i-1;j=j-1;}
}





if (taxi<=diem) {EXP1=ceil(EXP1*112.0/100);
                EXP2=ceil(EXP2*112.0/100);
                HP1=ceil(HP1*110.0/100);
                HP2=ceil(HP2*110.0/100);
                if (HP1>666) HP1 =666; if (HP1<0) HP1=0;
                if (EXP1>600) EXP1 =600; if (EXP1<0) EXP1=0;
                if (HP2>666) HP2 =666; if (HP2<0) HP2=0;
                if (EXP2>600) EXP2 =600; if (EXP2<0) EXP2=0;
                return diem;}
               


        else   {EXP1=ceil(EXP1*88.0/100);
                EXP2=ceil(EXP2*88.0/100);
                HP1=ceil(HP1*90.0/100);
                HP2=ceil(HP2*90.0/100);
                if (HP1>666) HP1 =666; if (HP1<0) HP1=0;
                if (EXP1>600) EXP1 =600; if (EXP1<0) EXP1=0;
                if (HP2>666) HP2 =666; if (HP2<0) HP2=0;
                if (EXP2>600) EXP2 =600; if (EXP2<0) EXP2=0;
                return diemcu;}    
return 0;
}

int checkPassword(const char *s, const char *email)
{
  char se[101];
int a;
int b=0;
int e=-1;
int d=0;
int sai;
string emailstr(email);
string ses(se);
int f=emailstr.find('@');
ses=emailstr.substr(0,f);
string sstr(s);
int l= ses.length();
for (int i=0; i < strlen(s); i++){
 if (!(((s[i]>=48)&&(s[i]<=57))||((s[i]>=65)&&(s[i]<=90))||((s[i]>=97)&&(s[i]<=122))||(s[i]==64)||(s[i]==33)||((s[i]>=35)&&(s[i]<=37))))
       {b=b+1; sai=i; break;}
 } // xét có kí tự k hợp lệ k

for(int i=0;i<strlen(s);i++){ if(s[i] == s[i+1] && s[i+1] == s[i+2]){e=i;break;}}//hàm trùng lập
 
for (int i=0; i<strlen(s);i++){ if ((s[i]==33)||(s[i]==64)||(s[i]==35)||(s[i]==36)||(s[i]==37)) d=d+1;}//xét có kí tự đặc biệt


int check =sstr.find(ses);
if ((strlen(s)>=8)&&(strlen(s)<=20)&&(b==0)&&(e==-1)&&(d!=0)&&(check==-1)) return -10;
if ((strlen(s)<8)) return -1;
if ((strlen(s)>20)) return -2;
if (check!=-1) return(-(300+check));
if (e!=-1) return (-(400+e));
if (d==0) return -5;
if (b!=0) return sai;    
    return 1;  
}

int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int max = 0;
  int lengmax = 0;
  int most = 0;
  for(int i=0;i<num_pwds;i++){
      int count = 0;
      for(int j=0;j<num_pwds;j++){
          if((strstr(arr_pwds[i], arr_pwds[j] ) != nullptr && strlen(arr_pwds[i]) == strlen(arr_pwds[j]))){
             count=count+1;
          }
      }       
      if(count > max){
           max = count;
           most = i;
           lengmax = strlen(arr_pwds[i]);
      }
      else if((count == max) && (lengmax < strlen(arr_pwds[i]))){
           max = count;
           most = i;
           lengmax = strlen(arr_pwds[i]);
      } 
  } 
  return most;
}