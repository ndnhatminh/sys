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
//Mc và hpexp là hàm kiểm tra các chỉ số
void Mc(int & M1,int & M2){
    if(M1<0)M1=0;
        if(M2<0)M2=0;
        if(M1>3000)M1=3000;
        if(M2>2000)M2=3000;
        return;
}
void hpexp(int & EXP1, int & EXP2,int & HP1,int & HP2){
        if(EXP1<0)EXP1=0;
        if(EXP1>600)EXP1=600;
        if(EXP2<0)EXP2=0;
        if(EXP2>600)EXP2=600;
        if(HP1<0)HP1=0;
        if(HP1>666)HP1=666;
         if(HP2>666)HP2=666;
          if(HP2<0)HP2=0;
          return;
}
    

int firstMeet(int & exp1, int & exp2, int e1) {
   
   //case 0-3
if (e1==0){
        exp2+=29;}
if (e1==1){
        exp2+=45;}
if (e1==2){
        exp2+=75;}
if (e1==3){
        exp2+=29+45+75;}           
    
    
if(e1<4)
    {
        if ((3*e1+exp1*7)%2==1)
        {exp1=ceil(exp1-((3*e1+exp1*7)/100.0));}
        else {exp1=ceil(exp1+((3*e1+exp1*7)/200.0));}
    }
//case 4+
if (e1>3&&e1<20)
    {
        exp2=ceil(exp2+e1/4.0+19);
    }
if (e1<50&&e1>19)
    { exp2=ceil(exp2+e1/9.0+21);
    exp1+=-e1;
    }
if (e1<66&&e1>49)
    { exp2 =ceil(exp2+e1/16.0+17);}
if (e1<80&&e1>65)
    {exp2=ceil(exp2+e1/4.0+19);
if (exp2>200)
       {exp2=ceil(exp2+e1/9.0+21);}
    }
if (e1<100&&e1>79)
    {exp2=ceil(exp2+e1/4.0+19);
      exp2=ceil(exp2+e1/9.0+21);
         if(exp2>400)
         {exp2 =ceil(exp2+e1/16.0+17);}
         exp2=ceil(exp2*1.15);
         exp1+=-e1;   }
    // kiểm tra exp
if(exp1<0)exp1=0;
        if(exp2<0)exp2=0;
        if(exp1>600)exp1=600;
        if(exp2>600)exp2=600;
    return exp1 + exp2;

}
// Task 2
void r1(int & EXP1x, double & P1x)  //hàm tính p1 hoặc p2
{
    int l1 = floor(sqrt(EXP1x));
    int l2 = ceil(sqrt(EXP1x));
   
    if ( (EXP1x - l1*l1) < (l2*l2-EXP1x))
        P1x = 1.0000000;
    else
        P1x = (EXP1x / (l2*l2*1.0000000000) + 80) /123;  
        return; 
}
//



void r2(int & HP1, int & EXP1, int & M1, int E2) //hàm con đường 2
{ 
    int x1=M1; //x1 là biến tiền phụ ,tính toán xong trả trả về cho M1, để cho M1/2 cố định trong các vòng lặp
 if (E2%2==1)
 {
    while(x1>M1/2)
 {
   
     
        if (HP1<200&&x1>=M1/2)
       {
           HP1=ceil(HP1*1.3);
           x1+=-150;
       }
        if(HP1>=200&&x1>=M1/2)
       {
           HP1=ceil(HP1*1.1);
           x1+=-70;
       } 
        if(HP1<0)HP1=0;
        if(HP1>666)HP1=666;
        if(HP1<0)HP1=0;
        if(HP1>666)HP1=666;
 
        if(EXP1<400&&x1>=M1/2)
            x1+=-200;
        if(EXP1>=400&&x1>=M1/2)
            {x1+=-120; EXP1=ceil(EXP1*1.13);}
 

        if(EXP1<300&&x1>=M1/2)
             x1+=-100;
        if (EXP1>=300&&x1>=M1/2)
           {x1+=-120;
            EXP1=ceil(EXP1*0.9);}
 
 }
if(HP1<0)HP1=0;
if(HP1>666)HP1=666;
 }
 
 
 
 
 
 
 if (E2%2==0)
 {
     if (HP1<200&&x1>0)
       {
          HP1=ceil(HP1*1.3);
          x1+=-150;
       }
 else if(HP1>=200&&x1>0)
       {
          HP1=ceil(HP1*1.1);
          x1+=-70;
       }
 if (x1<=0) x1=0;
 
 
 if(EXP1<400&&x1>0)
          x1+=-200;
 else if(EXP1>=400&&x1>=0)
          {M1+=-120; EXP1=ceil(EXP1*1.13);} 
 
 if (x1<=0) x1=0;
 if(EXP1<300&&x1>0)
           x1+=-100;
 else if (EXP1>=300&&x1>=120)
          {x1+=-120;  EXP1=ceil(EXP1*0.9);}
 if (x1<=0) x1=0;
 
 }
 //chạy bộ
     HP1=ceil(HP1*0.83);
     EXP1=ceil(EXP1*1.17);
 
 M1=x1; // trả về M1;

  
    return;
}
void r3(int E2, double & P3)  //hàm tính p3
{
    double P[10] = {0.32, 0.47, 0.28, 0.79, 0.100, 0.50, 0.22, 0.83, 0.64, 0.11};
    if (E2 / 10 == 0)
        P3 = P[E2];
    else
    {
        int d = E2 % 10;
        E2 = d + E2/10;
        E2 %= 10;
        P3 = P[E2];
        return;
    }
    
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    double P1, P2, P3, Pa;
   
    r1(EXP1, P1);
    r2(HP1, EXP1, M1, E2);
    r1(EXP1,P2);
    r3(E2, P3);
    if (P1 == 0.100 && P2 == 0.100 && P3 == 0.100){
        EXP1=ceil(EXP1*0.75);
        traceLuggage(HP1, EXP1, M1, E2);}
    else
        Pa = (P1 + P2 + P3) / 3;
        if(EXP1<0)EXP1=0;
        if(EXP1>600)EXP1=600;
    if (Pa < 0.50)
    {
        HP1 =ceil(HP1*0.85);
        EXP1 = ceil(EXP1*1.15);
    }
    else
    {
        HP1 =ceil(HP1*0.9);
        EXP1 = ceil(EXP1*1.2);
        
    }
    if(EXP1<0)EXP1=0;
        if(EXP1>600)   EXP1=600;
    return HP1 + EXP1 + M1;
}

// Task 3

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int taxi,max; //taxi là điểm taxi tại điểm dừng,max là gtln của 2 người đuổi theo
   int cp=0;int cn=0;// 258-270 tính tất cả điểm trên ma trận 
int X[10][10],i,j,x,y; 
     

for(i=0;i<=9;i++)
{
    for(j=0;j<=9;j++)
    {
        X[i][j]=((E3 * j) + (i * 2)) * (i - j);
       if(X[i][j]>E3*2)cp+=1;
       if(X[i][j]<-E3)cn+=1;
    }
}
x=(cp/10+cp%10)/10+(cp/10+cp%10)%10; // tìm tọa độ điểm dừng, lấy tổng hàng chục và hàng đơn vị 2 lần

y=(cn/10+cn%10)/10+(cn/10+cn%10)%10;

 taxi=((E3 * y) + (x * 2)) * (x - y);
 max=0; // tìm max
for((i=x,j=y);i>0;(i-=1,j+=1))
{
    if(X[i][j]>max)max=X[i][j];

}
for((i=x,j=y);j>0;(i+=1,j-=1))
{
    if(X[i][j]>max)max=X[i][j];

}
for((i=x,j=y);i>0&&j>0;(i-=1,j-=1))
{
    if(X[i][j]>max)max=X[i][j];

}
for((i=x,j=y);i<=9&&j<=9;(i+=1,j+=1))
{
    if(X[i][j]>max)max=X[i][j];

}




  
    if (abs(taxi)>max)
    {
        EXP1=ceil(EXP1*0.88);
        EXP2=ceil(EXP2*0.88);
        HP1=ceil(HP1*0.9);
        HP2=ceil(HP2*0.9);
return taxi;
    }
    else
    {
         EXP1=ceil(EXP1*1.12);
        EXP2=ceil(EXP2*1.12);
        HP1=ceil(HP1*1.1);
        HP2=ceil(HP2*1.1);
        return max;
    }
hpexp( EXP1, EXP2, HP1, HP2); // kiểm tra chỉ số
    
}

// Task 4
int checkPassword(const char * s, const char * email) {
 const char *tt= strstr( email,"@");//tiến hành tạo chuỗi se
  char se[100];
 strncpy( se,  email, (tt-email)); 
 se[tt - email] = '\0'; // thêm kí tự null vào, để se được xác định trên c++
if (strlen(s)<8) { return -1;} // so sánh đọ dài password  có lớn hơn 20 hay bé hơn 8 không?
   else if (strlen(s)>20) {return -2;}
 // kiểm tra se có trong s không và tìm tọa độ
  const char *pse = strstr(s, se); // khảo sát s tìm se
   ptrdiff_t oo=pse-s; //tọa độ hóa vị trí se trong s
    if (pse != nullptr) //nếu pse có giá trị nghĩa là đã tìm ra se trong s
    {
      
        return -(300 + oo);
    }
   for(int l=0;l<strlen(s);l++) //kiểm tra kí tự đặc biệt
     {
          if (*s != '#' && *s != '%' && *s != '$'&& *s != '!'&& *s != '@')
          return -5;
     }
  
    for(int u=0;u<strlen(s);u++) //kiểm tra hơn 2 kí tự giống và kề nhau
   {
       if (s[u]==s[u+1]&&s[u]==s[u+2]) {
           
           return -400-u;
           break;
       }
   }
    
     return -10; // kết quả đúng
    
}

// Task 5
#define LIMIT_ 30 // điều kiện giới hạn input


int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
   
    string mcp;
    int mc = 0;
    
    for (int i = 0; i < num_pwds; ++i) {    
        int count = 0;
        for (int j = 0; j < num_pwds; j ++)  //tìm số lặp lớn nhất
            if (arr_pwds[i] == arr_pwds[j])
                count ++;
        if (count > mc || (count == mc && strlen(arr_pwds[i]) > mcp.length())) {  //tìm password dài nhất
            mc = count;
            mcp = arr_pwds[i]; // ghi lại kết quả cuối cùng
        }
    }

    
    for (int i = 0; i < num_pwds; ++i) 
        if (arr_pwds[i] == mcp) //tìm tọa độ kết quả cuối cùng
            return i;
    
    
    
    return -1;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////