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
int firstMeet(int & exp1, int & exp2, int e1) {
    if (exp2>600) exp2=600;
    if (exp2<0)   exp2=0; 
    if (exp1>600) exp1=600;
    if (exp1<0)   exp1=0; 
    if (e1<0 || e1>99) return -99;
    
    if (e1>=0 && e1<=3){
        if (e1==0){
            exp2=exp2 + 29; 
            if (exp2>600) {exp2=600;}
            if (exp2<0)   {exp2=0; }
        }
        else if (e1==1){
            exp2=exp2 + 45;
            if (exp2>600) {exp2=600;}
            if (exp2<0)   {exp2=0; }
        }
        else if (e1==2){
            exp2=exp2 + 75;
            if (exp2>600) {exp2=600;}
            if (exp2<0)   {exp2=0; }
        }
        else if (e1==3){
            exp2=exp2 + 149;
            
        }
          
     int D=0;
     D= e1*3 + exp1*7;
     if (D%2==0){
         exp1= ceil(exp1 + (D/200.0));
         if (exp1>600) {exp1=600;}
         if (exp1<0)   {exp1=0; }
         
    }
     else {
         exp1= ceil(exp1 -(D/100.0));
         if (exp1>600) {exp1=600;}
         if (exp1<0)   {exp1=0;}
         

}
}


if (e1>=4 && e1<=99){
        if ( e1 >= 4 && e1 <= 19){
         exp2 = ceil(exp2 + (e1/4.0 + 19));
         
         exp1= exp1-e1;
         if (exp1>600) {exp1=600;}
         if (exp1<0)   {exp1=0; }
         if (exp2>600) {exp2=600;}
         if (exp2<0)   {exp2=0; }
}
     if ( e1 >= 20 && e1 <= 49){
         exp2 = ceil( exp2 + (e1/9.0 + 21));
         
         exp1= exp1-e1;
         if (exp1>600) {exp1=600;}
         if (exp1<0)   {exp1=0; }
         if (exp2>600) {exp2=600;}
         if (exp2<0)   {exp2=0; }
}
     if ( e1 >= 50 && e1 <= 65){
         exp2 = ceil(exp2 + (e1/16.0 + 17));
        
         exp1= exp1-e1;
         if (exp1>600) {exp1=600;}
         if (exp1<0)   {exp1=0; }
         if (exp2>600) {exp2=600;}
         if (exp2<0)   {exp2=0; }
}
     if ( e1 >=66 && e1<=79){
          exp2 = ceil(exp2 + (e1/4.0 + 19));
         
          exp1= exp1-e1;
          if (exp1>600) {exp1=600;}
          if (exp1<0)   {exp1=0; }
          if (exp2 > 200)  {exp2= ceil(exp2  + (e1/9.0 + 21));
                            }
          if (exp1>600) {exp1=600;}
          if (exp1<0)   {exp1=0; }
          if (exp2>600) {exp2=600;}
          if (exp2<0)   {exp2=0; }
}
     if ( e1 >=80 && e1<=99){
          exp2 = ceil(exp2 + (e1/4.0 + 19) );
          exp2 = ceil(exp2  + (e1/9.0 + 21));
          exp1= exp1-e1;
          if (exp2 > 400){exp2 = ceil(exp2 + (e1/16.0 + 17)) ;
                          
                          exp2=ceil(exp2 + (exp2*15/100.0));
                          
                          }
          if (exp1>600) {exp1=600;}
          if (exp1<0)   {exp1=0; }
          if (exp2>600) {exp2=600;}
          if (exp2<0)   {exp2=0; }
}
   
         
      
          

}
return exp1+exp2 ;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    
    // TODO: Complete this function
    double Tong,P1 ,P2, P3;
    int a,b,c;
    if (EXP1>600) EXP1=600;
    if (EXP1<0)   {EXP1=0;}
    if (HP1>666)  {HP1=666;}
    if (HP1<0)    {HP1=0;}
    if (M1>3000)  {M1=3000;}
    if (M1<0)     {M1=0;}
    if (E2>99)    {E2=99;}
    if (E2<0)     {E2=0;}

//conđg1
    a= sqrt(EXP1);
    b= a*a;
    c= (a+1)*(a+1);
    if ((c-EXP1)>=(EXP1-b))  P1=1;
    else {
        P1= (((EXP1/c) +80)/123.0);}
    
 //conđg2   
if (E2%2==0)
{
    if (HP1<200) 
    {
        HP1= ceil((HP1+(HP1*30/100.0)));
        M1= M1-150;
        if (HP1>666)  {HP1=666;}
        if (HP1<0)    {HP1=0;}
        if (M1<0)     {M1=0;}
    }

    else 
    {
        HP1= ceil((HP1+ (HP1*10/100.0)));
        M1= M1-70;
        if (HP1>666)  {HP1=666;}
        if (HP1<0)    {HP1=0;}
        if (M1>3000)  {M1=3000;}
        if (M1<0)     {M1=0;}
        
    }
    
    if (EXP1<400 && M1>0)
    {
        M1=M1-200;
        EXP1= ceil((EXP1+ (EXP1*13/100.0)));
        if (M1>3000)  {M1=3000;}
        if (M1<0)     {M1=0;}
        if (EXP1>600) {EXP1=600;}
        if (EXP1<0)   {EXP1=0;}
    }
    else if (EXP1>=400 && M1>0)
    {
        M1=M1-120;
        EXP1= ceil((EXP1+ (EXP1*13/100.0)));
          
        if (M1>3000)  {M1=3000;}
        if (M1<0)     {M1=0;}
        if (EXP1>600) {EXP1=600;}
        if (EXP1<0)   {EXP1=0;}
    }
    if (EXP1<300 && M1>0)
    {   
        M1=M1-100;
        EXP1= ceil((EXP1 -(EXP1*10/100.0)));
        if (M1>3000)  {M1=3000;}
        if (M1<0)     {M1=0;}
        if (EXP1>600) {EXP1=600;}
        if (EXP1<0)   {EXP1=0;}
    }
    else if (EXP1>=300 && M1>0)
    {
        M1=M1-120;
        EXP1= ceil((EXP1-(EXP1*10/100.0)));
        if (M1>3000)  {M1=3000;}
        if (M1<0)     {M1=0;}
        if (EXP1>600) {EXP1=600;}
        if (EXP1<0)   {EXP1=0;}
    }
    HP1= ceil(HP1- HP1*17/100.0);
    EXP1 = ceil((EXP1 + EXP1*17/100.0));
    if (HP1>666)  {HP1=666;}
    if (HP1<0)    {HP1=0;}
    if (EXP1>600) {EXP1=600;}
    if (EXP1<0)   {EXP1=0;}
}
else  {
    int k=0;
    float h = M1 / 2.0 ;
    
    while(k < h) 
    {
        if (HP1<200 && M1>0 && k<h) 
        {
            HP1= ceil((HP1+HP1*30/100.0));
            M1= M1-150;
            k += 150 ;
            if (HP1>666)  {HP1=666;}
            if (HP1<0)    {HP1=0;}
            if (M1<0)     {M1=0;}
        }
        else if (HP1 > 200 && M1>0 && k<h) 
        {
            HP1= ceil((HP1+ HP1*10/100.0));
            M1 = M1-70;
            k += 70 ;
            if (HP1>666)  {HP1=666;}
            if (HP1<0)    {HP1=0;}
            if (M1>3000)  {M1=3000;}
            if (M1<0)     {M1=0;}
        }
        if (EXP1<400 && M1>0 && k<h)
        {
            M1=M1-200;
            k += 200 ;
            EXP1= ceil((EXP1+ EXP1*13/100.0));
            if (M1>3000)  {M1=3000;}
            if (M1<0)     {M1=0;}
            if (EXP1>600) {EXP1=600;}
            if (EXP1<0)   {EXP1=0;}
        }
        else if (EXP1 > 400 && M1>0 && k<h) 
        {
            M1=M1-120;
            k += 120 ;
            EXP1= ceil((EXP1+ EXP1*13/100.0));
            if (M1>3000)  {M1=3000;}
            if (M1<0)     {M1=0;}
            if (EXP1>600) {EXP1=600;}
            if (EXP1<0)   {EXP1=0;}
        }
        if (EXP1<300 && M1>0 && k<h)
        {
            M1=M1-100;
            k += 100 ;
            EXP1= ceil((EXP1 -EXP1*10/100.0));
            if (M1>3000)  {M1=3000;}
            if (M1<0)     {M1=0;}
            if (EXP1>600) {EXP1=600;}
            if (EXP1<0)   {EXP1=0;}
        }
        else if (EXP1 > 300 && M1>0 && k<h) 
        {
            M1=M1-120;
            k += 120 ;
            EXP1= ceil((EXP1-EXP1*10/100.0));
            if (M1>3000)  {M1=3000;}
            if (M1<0)     {M1=0;}
            if (EXP1>600) {EXP1=600;}
            if (EXP1<0)   {EXP1=0;}
            }
    }

    HP1= ceil((HP1- HP1*17/100.0));
    EXP1 = ceil((EXP1 + EXP1*17/100.0));
    if (HP1>666)  {HP1=666;}
    if (HP1<0)    {HP1=0;}
    if (EXP1>600) {EXP1=600;}
    if (EXP1<0)   {EXP1=0;}
}
int d,e,f;
    if (EXP1>600) {EXP1=600;}
    if (EXP1<0)   {EXP1=0;}
    if (HP1>666)  {HP1=666;}
    if (HP1<0)    {HP1=0;}
    if (M1>3000)  {M1=3000;}
    if (M1<0)     {M1=0;}
    if (E2>99)    {E2=99;}
    if (E2<0)     {E2=0;}

//conđg2
    d= sqrt(EXP1);
    e= d*d;
    f= (d+1)*(d+1);
    if ((f-EXP1)>=(EXP1-e))  {P2=1;}
    else {P2= ((EXP1/f +80)/123.0);}

//con đg 3
double P[10]={32,47,28,79,100,50,22,83,64,11};
int i=(E2%10 + E2/10)%10;
P3=P[i]/100.0;

//tính tổng p
if (P1==1 && P2==1 && P3==1)
{
    EXP1= ceil(float(EXP1 -EXP1*25/100.0));
    if (EXP1>600) {EXP1=600;}
    if (EXP1<0)   {EXP1=0;}
}
else
{
Tong= (P1+P2+P3)/3.0;
if (Tong<0.5){
    HP1= ceil(float(HP1 - HP1*15/100.0));
    EXP1= ceil (float(EXP1 + EXP1*15/100.0));
    if (EXP1>600) {EXP1=600;}
    if (EXP1<0)   {EXP1=0;}
    if (HP1>666)  {HP1=666;}
    if (HP1<0)    {HP1=0;}
}
else
{
    HP1= ceil(float(HP1 - HP1*10/100.0));
    EXP1= ceil (float(EXP1 + EXP1*20/100.0));
    if (EXP1>600) {EXP1=600;}
    if (EXP1<0)   {EXP1=0;}
    if (HP1>666)  {HP1=666;}
    if (HP1<0)    {HP1=0;}
}
}


return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    
    if (EXP1>600) {EXP1=600;}
    if (EXP1<0)   {EXP1=0;}
    if (HP1>666)  {HP1=666;}
    if (HP1<0)    {HP1=0;}
    if (EXP2>600) EXP2=600;
    if (EXP2<0)   {EXP2=0;}
    if (HP2>666)  {HP2=666;}
    if (HP2<0)    {HP1=0;}
    if (E3>99)    {E3=99;}
    if (E3<0)     {E3=0;}
    // mang diem so tung vi tri di qua cua taxi
    int array[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            array[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // tim diem giao nhau
    int m=0;
    int n=0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (array[i][j]>E3*2)
            {
                m++;
            }
            else if (array[i][j]< (-E3))
            {
                n++;
            }
        }
    }
    // tim tong cac chu so
    while(m>=10)
    {
        if (m>=10)
        {
            m=m%10+m/10;
        }
    }
    while(n>=10)
    {
        if (n>=10)
        {
            n=n%10+n/10;
        }
    }
    // (c1, c2) la toa do can tim

    // Tim diem cua Sherlock va Watson tren o nay
    // tim diem 2 nguoi do
    int max=array[m][n];
    for ( int i=-9; i<10; i++)
    {
        if (m+i >=0 && m+i <10 && n+i >=0 && n+i <10 )
        {
            if (max < array[m+i][n+i])
            max = array[m+i][n+i];
        }
    }
    for ( int i=-9; i<10; i++)
    {
        if (m-i >=0 && m-i <10 && n+i >=0 && n+i <10 )
        {
            if (max < array[m-i][n+i])
            max = array[m-i][n+i];
        }
    }
    
    if (abs(array[m][n]) <= abs(max))
    {
        EXP1 += ceil(EXP1 * 0.12);
        HP1 += ceil(HP1 * 0.1);
        EXP2 += ceil(EXP2 * 0.12);
        HP2 += ceil(HP2 * 0.1);
        if (EXP1>600) EXP1 = 600;
    if (EXP2>600) EXP2 = 600;
    if (HP1>666) HP1 = 666;
    if (HP2>666) HP2=666;
        return max;
    }
    else
    {
        EXP1 = ceil(EXP1 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        EXP2 = ceil(EXP2 * 0.88);
        HP2 = ceil(HP2 * 0.9);
        return array[m][n];
    }
    
    
}



// Task 4
int timse(const char* s, char sh) {
    for (int i=0; i< strlen(s); i++) {
        if (s[i] == sh) return i; // vi tri ky tu can tim
    }
    return -1; // khong co ky tu can tim
}
// co ki tu db hay ko
bool ktdb(char sh) {
    char db[5] = {'@', '#', '$', '%', '!'};
    for (int i =0; i<5; i++) {
        if (sh == db[i]) return true;
    }
    return false;
}
bool bangascii(char sh) {
    bool chuhoa = ((65 <= sh) && (sh <= 90));
    bool chuthuong = ((97 <= sh) && (sh <= 122));
    bool chuso = ((48 <= sh) && (sh <= 57));
    if ( chuhoa || chuthuong || chuso) return true;
    else return false;
}

int checkPassword(const char * s, const char * email) {
    std::string str = s;
    std::string se ;
    

    int k = strlen(s);
    if (k<8) return -1;// ngan qua
    if (k>20) return -2;// dai qua
    
    for (int i=0; i<timse(email, '@'); i++)
    {
        se += email[i]; // tao chuoi se
    }
    // kiem tra se co nam o chuoi hay khong
    if (int(str.find(se)) != -1)
    {
        return - (300 + str.find(se));
    }
    // coi co hon 2 ki tu giong nhau ko
    for (int i=0; i<strlen(s); i++) 
    {
        if ((s[i] == s[i+1]) && (s[i+1] == s[i+2])) 
        return  - (400 + i);
    }
    // coi co ktdb ko
    int dem = 0;
    for (int i=0; i<k; i++) {
        if (!(ktdb(s[i]))) dem++;
    }
    if (dem == strlen(s)) return -5;
    //chusochucai
    for (int i=0; i<strlen(s); i++) 
    {
    if (!(bangascii(s[i])  || ktdb(s[i]))) return i;
    }
    return -10;
    
}


// Task 5
int dodai(const char *m)
{
    int dem=0;
    for (int i=0; m[i]!='\0'; i++)
    {
        dem++;
    }
    return dem;
}
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int k=0, h=0;
    for ( int i=0; i< num_pwds -1; i++)
    {
        int count=0;
        for (int j=i+1; j <num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0 )
            count ++;
        }
        if ( count> h)
        {
            h=count;
            k=i;
        }
        else if (count==h)
        {
            if( dodai(arr_pwds[i]) > dodai(arr_pwds[k]))
            k=i;
        }
    }
    return k;
    return -1;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////