#include "study_in_pink1.h"

bool readFile(const string & filename, int & HP1, int & HP2, int & EXP1, int & EXP2,
              int & M1,int & M2,int & E1,int & E2,int & E3) 
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        ifs.close();
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

void condition(int & HP1, int & HP2, int & EXP1, int & EXP2,
              int & M1,int & M2,int & E1,int & E2,int & E3)
    {
    HP1 = min(max(HP1, 0), 666);
    HP2 = min(max(HP2, 0), 666);
    EXP1 = min(max(EXP1, 0), 600);
    EXP2 = min(max(EXP2, 0), 600);
    M1 = min(max(M1, 0), 3000);
    M2 = min(max(M2, 0), 3000);
    }
void conditionT2(int & HP1, int & EXP1,
              int & M1)
    {
    HP1 = min(max(HP1, 0), 666);
    EXP1 = min(max(EXP1, 0), 600);
    M1 = min(max(M1, 0), 3000);
    }
void conditionT3(int & HP1, int & EXP1,
              int & HP2, int& EXP2)
    {
    HP1 = min(max(HP1, 0), 666);
    EXP1 = min(max(EXP1, 0), 600);
    HP2 = min(max(HP2, 0), 666);
    EXP2 = min(max(EXP2, 0), 600);
    }

float squarenumforP(int &EXP1 )
{   int proto;
    int i=0; float P1;
    while (i*i<EXP1)
    {
        i++;
    }
    if(abs((i-1)*(i-1)-EXP1) < abs((i)*(i)-EXP1))
    {proto=(i-1)*(i-1);}
    else {proto=i*i;}

    if(EXP1>=proto)
        {
        P1=1;}
    else 
    {   float S=(i)*(i);
        P1 = (EXP1/S + 80.0)/123.0;
    }
     return P1;    
}

void  task2_3road( int & HP1, int & EXP1, int & M1, int E2, float &P1, float &P2, float &P3)
{
     //Road 1
   P1=round(squarenumforP(EXP1) * 100) / 100;        
      
    //roud 2
   if(E2%2 != 0)                           //E2=odd
   { 
   int iM1=M1;
   while(true)                       
    {
    if(HP1<200)                //food and water
    {
        float iHP1=HP1*1.3;
        HP1= ceil(iHP1); 
        M1=M1-150;
        conditionT2(HP1,EXP1,M1);  
                               
    }
    else                      
    {
        float iHP1=HP1*1.1;
        HP1= ceil(iHP1); 
        M1=M1-70;
        conditionT2(HP1,EXP1,M1); 
             
    }
    if(M1<0.5*iM1) {break;}
    
    if(EXP1<400) {M1=M1-200;}    // horse or taxi
    else {M1=M1-120;}
    float iEXP1=EXP1*1.13;
    EXP1= ceil(iEXP1);
    conditionT2(HP1,EXP1,M1);  
         
    if(M1<0.5*iM1) {break;}
   
    if(EXP1<300) {M1=M1-100;}    // beggar
    else {M1=M1-120;}
    iEXP1=EXP1*0.9;
    EXP1= ceil(iEXP1);
    conditionT2(HP1,EXP1,M1); 
    
    if(M1<0.5*iM1) {break;}
    }
   }
   else                                 //E2=even
   {                               
    int minus;int i=0;
    while(i==0){
    if(HP1<200)                //food and water
    {
        float iHP1=HP1*1.3;
        HP1= ceil(iHP1); 
        M1=M1-150;
        if(M1<0) {minus=1;}
        conditionT2(HP1,EXP1,M1);  
                              
    }
    else                      
    {
        float iHP1=HP1*1.1;
        HP1= ceil(iHP1); 
        M1=M1-70;
        if(M1<0) {minus=1;}
        conditionT2(HP1,EXP1,M1);          
    }
    if(minus==1) break;

    
    if(EXP1<400) {M1=M1-200;}    // horse or taxi
    else {M1=M1-120;}
    float iEXP1=EXP1*1.13;
    EXP1= ceil(iEXP1);
    if(M1<0) {minus=1;}
    conditionT2(HP1,EXP1,M1);     
    if(minus==1) break;
   
    if(EXP1<300) {M1=M1-100;}    // beggar
    else {M1=M1-120;}
    iEXP1=EXP1*0.9;
    EXP1= ceil(iEXP1);
    if(M1<0) {minus=1;}
    conditionT2(HP1,EXP1,M1); 
    if(minus==1) break;

    i=1;                        // to escape
    }
    }
    
    float iHP1=HP1*(1-0.17);
    HP1= ceil(iHP1);
    float iEXP1=EXP1*1.17;
    EXP1= ceil(iEXP1);
    conditionT2(HP1,EXP1,M1);
          
    P2=round(squarenumforP(EXP1) * 100) / 100;
     
    //road 3
   
    int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2<10)
    {
      P3=P[E2]/100.0;  
    }
    else 
    { int num1,num2;
      num1=E2/10;
      num2=E2%10;
      int sum=num1+num2;
      P3=P[sum%10]/100.0;
    }
}

int countchar(const char *string) {
    int count = 0;
    while (*string != '\0') {
        count++;
        string++;
    }
    return count;
}

int twocharsame(const char*s)
{   int nums=-1;
    int num=countchar(s);
    int repeat=0;
    for (int i=0;i<=num-1;i++)
    {
        if(s[i]==s[i+1])
        {
          repeat++;
          if(repeat==2)
          {
            nums=i-1; break;
          }
        }
        else repeat=0;
            
    }
   return nums;
}
int checkchar(const char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (!((s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= 'A' && s[i] <= 'Z') ||
              (s[i] >= '0' && s[i] <= '9') ||
              (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))) {
            return i;
        }
    }
    return -1;
}
bool specialchar(const char *s){
    for (int i = 0; s[i] != '\0'; i++) {
         if ((s[i] == '@' || s[i] == '#'|| s[i] == '%'|| s[i] == '$'|| s[i] == '!')){
                return true;
         }
     }
      return false;
}

   
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) 
{   
    // TODO: Complete this function
    exp1 = min(max(exp1, 0), 600);           // for condition
    exp2 = min(max(exp2, 0), 600);

    if      (e1>=0&&e1<=3 )
    { int D;
      D=e1 * 3 + exp1 * 7;
      if (D%2==0)
     {  
         float iexp1=exp1+D/200.0; 
         exp1= ceil(iexp1); 
     }
      else 
      { 
         float iexp1=exp1-D/100.0;
         exp1= ceil(iexp1); 
      }

    exp1 = min(max(exp1, 0), 600);           // for condition
    exp2 = min(max(exp2, 0), 600);

    if(e1==0)
    {
      exp2=exp2+29;
    }
    else if(e1==1)
    {
      exp2=exp2+45;    
    }
    else if(e1==2)
    {
     exp2=exp2+75;
    }
    else if(e1==3)
    {
     exp2=exp2+75+45+29;
    }
    }

    else if (e1>=4&&e1<=99)
    { float iexp1;
      float iexp2;
      if (e1>=4&&e1<=19)
      {
       iexp2=exp2+(e1/4.0)+19;
      }
      else if (e1>=20&&e1<=49)
      {
        iexp2=exp2+(e1/9.0)+21;
      }
       else if (e1>=50&&e1<=65)
      {
        iexp2=exp2+(e1/16.0)+17;
      }
      else if (e1>=66&&e1<=79)
      {
       iexp2=exp2+(e1/4.0)+19;
       iexp2=ceil(iexp2);
       if(iexp2>200)
       {
        iexp2=iexp2+(e1/9.0)+21;
        iexp2=ceil(iexp2);
       }
      }
      else if (e1>=80&&e1<=99)
      {
       iexp2=exp2+(e1/4.0)+19;
       iexp2=ceil(iexp2);
       iexp2=iexp2+(e1/9.0)+21;
       iexp2=ceil(iexp2);
       if(iexp2>400)
       {
        iexp2=iexp2+(e1/16.0)+17;
        exp2=ceil(iexp2);
        iexp2=exp2*(1.15);
       }
      } 
      exp2=ceil(iexp2);
      exp1=exp1-e1;
    }
    else return -99; //error in input


    exp1 = min(max(exp1, 0), 600);           // for condition
    exp2 = min(max(exp2, 0), 600);
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) 
{
    // TODO: Complete this function
if(E2<0||E2>99) return -99;
conditionT2(HP1,EXP1,M1);
if(M1==0) {       
    float iHP1=HP1*(1-0.17);
    HP1= ceil(iHP1);
    float iEXP1=EXP1*1.17;
    EXP1= ceil(iEXP1);
    conditionT2(HP1,EXP1,M1);
    return HP1 + EXP1 + M1;
}
while (true)
{
float P1,P2,P3;
task2_3road(HP1,EXP1,M1,E2,P1,P2,P3);

if(P1==1&&P2==1&&P3==1)   // wrong case - but not do again
{
float iEXP1=EXP1*0.75;
EXP1= ceil(iEXP1); 
conditionT2(HP1,EXP1,M1);
break;
}
else
{   
    float P_avr=(P1+P2+P3)/3.0;
    
     if(P_avr<0.5)
     {
     float iHP1=HP1*(1-0.15);
     HP1= ceil(iHP1);
     float iEXP1=EXP1*1.15;
     EXP1= ceil(iEXP1);
     }
     else 
     {
     float iHP1=HP1*(1-0.1);
     HP1= ceil(iHP1);
     float iEXP1=EXP1*1.2;
     EXP1= ceil(iEXP1); 
     }
     conditionT2(HP1,EXP1,M1);
     break;
}

}

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0||E3>99) return -99;
    conditionT3(HP1,EXP1,HP2,EXP2);
    int T[10][10]; int pointI=0,pointJ=0;
    for (int i = 0; i < 10; i++)                //point for taxi
    {
        for (int j = 0;j<10; j++) 
        {
          T[i][j]=((E3 * j) + (i * 2)) * (i - j);
          if(T[i][j]>E3*2) pointI++;
          if(T[i][j]<-E3) pointJ++;                     //if the value of T is less than
        }
    }
    while (pointI>9) 
    {
        int ones=pointI%10;
        int tens=pointI/10;
        pointI=ones+tens;
    }
    while (pointJ>9) 
    {
        int ones=pointJ%10;
        int tens=pointJ/10;
        pointJ=ones+tens;
    }
    

    int D[10][10]; int maxD=INT_MIN;
    for (int i = 0; i < 10; i++)                //point for detective
    {
        for (int j = 0; j <10; j++) 
        {
          int a=i-j;
          int b=i+j;
          for (int i = 0; i < 10; i++)                //point for taxi
           {
               for (int j = 0; j < 10; j++) 
               {
                 if(i-j==a||i+j==b)
                 {
                   if(T[i][j]>maxD)
                   {
                    maxD=T[i][j];
                   }
                 }
               }
           }
          if(maxD<0) { maxD=abs(maxD);}
          D[i][j]=maxD;
          maxD=INT_MIN;
        }
    }
    
    if(abs(T[pointI][pointJ])<=D[pointI][pointJ])
    {
     float iHP1=HP1*(1.1);
     HP1= ceil(iHP1);
     float iEXP1=EXP1*1.12;
     EXP1= ceil(iEXP1);

     float iHP2=HP2*(1.1);
     HP2= ceil(iHP2);
     float iEXP2=EXP2*1.12;
     EXP2= ceil(iEXP2); 
     conditionT3(HP1,EXP1,HP2,EXP2);
     return D[pointI][pointJ];
    }
    else
    {
     float iHP1=HP1*(0.9);
     HP1= ceil(iHP1);
     float iEXP1=EXP1*0.88;
     EXP1= ceil(iEXP1); 
     float iHP2=HP2*(0.9);
     HP2= ceil(iHP2);
     float iEXP2=EXP2*0.88;
     EXP2= ceil(iEXP2); 
     conditionT3(HP1,EXP1,HP2,EXP2);
     return T[pointI][pointJ];
    }   
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
    const char* p = strchr(email, '@');
    int a = p - email;
    char* se = new char[a + 1]; // Tạo một mảng đủ lớn cho chuỗi se
    strncpy(se, email, a);
    se[a] = '\0'; // Kết thúc chuỗi se bằng ký tự null
    

   int count_s=countchar(s);
   int p_se_s;
   const char *pp_se_s = strstr(s,se);
   if(pp_se_s==NULL)  p_se_s=-99;
   else p_se_s=pp_se_s-s;
   

   int tcs=twocharsame(s);
   bool spc=specialchar(s);
   int cc=checkchar(s);

   if(count_s<8) return -1;
   else if(count_s>20) return -2;
   else if(p_se_s!=-99) return (-300-p_se_s);
   else if(tcs!=-1) return (-400-tcs);
   else if(spc==false)  return -5;
   else if(cc!=-1) return (cc);
   else return -10;
  
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max = -1; int pos; int length=-1,length_max=-1;
    for (int i = 0; i < num_pwds; i++) 
    {
        int count = 1;               
        const char *proto = arr_pwds[i];
        length=countchar(proto);    
        for (int j = 0; j < num_pwds; j++) 
        {        
            if (i != j) {                                  // make sure it did not use be4
                const char *another = arr_pwds[j];
                if (strcmp(another, proto) == 0)          // compare 2 pointer
                {      
                    count++;                  
                }
            }
        }
          if (count > max || (count == max && length > length_max)) {
            max = count;
            length_max = length;
            pos= i;
        }
    }
    return pos;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////