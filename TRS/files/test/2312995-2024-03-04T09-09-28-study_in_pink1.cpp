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
//lam tron so
int lam_tron (float &a)
{
    int b;
    b = round(a);

    if(a-b<=0 )
    {
        a=b;
    }
    else {a=b+1;}
    return 6001;
}
//kiem tra exp,hp,m
int check_int(int & HP1, int & HP2, int & EXP1, int & EXP2, int & M1, int & M2)
{   
    if(HP1 > 666) HP1 =666;
    else if (HP1 <0) HP1 = 0;
   
    if(HP2 > 666) HP2 =666;
    else if (HP2 <0) HP2 = 0;


    if(EXP1 > 600) EXP1 =600;
    else if (EXP1 <0) EXP1 = 0;
    
    if (EXP2 > 600) EXP2 =600;
    else if (EXP2 <0) EXP2 = 0;
    
    if (M1 > 3000) EXP2 =3000;
    else if (M1< 0) M1 = 0;
   
    if (M1 > 3000) EXP2 =3000;
    else if (M1< 0) M1 = 0;
    
    return 6002;
}
int check_float(float & HP1, float & HP2, float & EXP1, float & EXP2, float & M1, float & M2)
{   
    if(HP1 > 666) HP1 =666;
    else if (HP1 <0) HP1 = 0;
   
    if(HP2 > 666) HP2 =666;
    else if (HP2 <0) HP2 = 0;


    if(EXP1 > 600) EXP1 =600;
    else if (EXP1 <0) EXP1 = 0;
    
    if (EXP2 > 600) EXP2 =600;
    else if (EXP2 <0) EXP2 = 0;
    
    if (M1 > 3000) EXP2 =3000;
    else if (M1< 0) M1 = 0;
   
    if (M1 > 3000) EXP2 =3000;
    else if (M1< 0) M1 = 0;
    
    return 6003;
}
// Task 1
// Task 1.1
int firstMeet1(int & exp1, int & exp2, int e1){
    float a = exp1, b = exp2; /////gan so/////
    int d;
    int x=0,y=0,z=0,t=0;
    switch (e1)
    {
    case 0:
        b = b + 29; 
        break;
    case 1:
        b = b + 45; 
        break;
    case 2:
        b = b + 75; 
        break;
    case 3:
        b = b + 29 + 45 + 75; 
        break;
    }
    d= e1*3 +a*7;
    if(d%2==0) {a = (float) a + (d/200.0);}
    else a = (float) a - (d/100.0);
    lam_tron(a);
    exp1 =a ;
    exp2 =b ;
    check_int(x,y,exp1,exp2,z,t);
    return 6011;

}
//task 1.2
int firstMeet2(int & exp1, int & exp2, int e1){
    float a = exp1, b = exp2; /////gan so/////
    float x=0,y=0,z=0,t=0;
    if(e1<20) {b=(float) b + e1/4.0 +19; }
    else if (e1<50) b=(float) b + e1/9.0 + 21;
    else if (e1<66) b=(float) b + e1/16.0 + 17;
    else if (e1<80) 
        {
            b=(float) b + e1/4.0 +19;
            lam_tron(b);
            check_float(x,y,a,b,z,t);
            if(b>200)
            b= (float) b+ e1/9.0 + 21;
        }
    else 
    {
            b=(float) b + e1/4.0 +19;
            lam_tron(b);
            check_float(x,y,a,b,z,t);
            b= (float) b+ e1/9.0 + 21;
            lam_tron(b);
            check_float(x,y,a,b,z,t);
            if(b>400)
            {b= (float) b+ e1/16.0 + 17;
            lam_tron(b);
            check_float(x,y,a,b,z,t);
            b= (float) b+ 0.15*b;
            lam_tron(b);
            check_float(x,y,a,b,z,t);}
    }
    a = a - e1;
        lam_tron(b);
        check_float(x,y,a,b,z,t);
    exp1 = a;
    exp2 =b;
    return 6012;
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int x=0,y=0,z=0,t=0;
    check_int(x,y,exp1,exp2,z,t);
    if(e1 < 0 || e1 > 99){
    return -99;
    }
    else if (e1 <4)
    {
     firstMeet1(exp1, exp2, e1);   
    }
    else
    {
        firstMeet2(exp1, exp2, e1);
    }
    return exp1 + exp2;
}

// Task 2
bool so_cp(float a)
{
    if (a<0) return 0;
    else{
    int b=  sqrt(a);
    if(b*b<a) return 0; else return 1;
    }
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    float a = HP1, b = EXP1, c=M1, x = 0, y = 0, z = 0,s,c1=0,Ptb,i,j;
    int idx;
    check_float(a,x,b,y,c,z);
    if(E2<0 || E2> 99) return -99;
    float p1, p2, p3;
    float P[10] ={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    //con duong 1
    
    for(i=b;;i++) if(so_cp(i)) break;
    for(j=b;;j--) if(so_cp(j)) break;
    if(i-b >= b - j)
    {
        s=j;
        p1 = 1;
    } else 
    {
        s=i;
        p1 = (b/s + 80)/123.00;
    }
    // con duong 2
    /////////////////////////////////////////////
if(E2 % 2 ==0 ){ 
    if (c==0)
{   
    a = a - 0.17*a;
    b = b + 0.17*b;
    lam_tron(a);
    lam_tron(b);
    check_float(a,x,b,y,c,z);
}
else {
    if(a<200)
    {   a = a + 0.3*a;
        c = c - 150;
        lam_tron(a);
        check_float(a,x,b,y,c,z);
    }
    else
    {   a = a + 0.1*a;
        c = c - 70;
        lam_tron(a);
        check_float(a,x,b,y,c,z);
    }
if (c==0)
{   
    a = a - 0.17*a;
    b = b + 0.17*b;
    lam_tron(a);
    lam_tron(b);
    check_float(a,x,b,y,c,z);
}
else{
    if(b<400)
    {
        b = b + 0.13*b;
        c = c - 200;
        lam_tron(b);
        check_float(a,x,b,y,c,z);
    }
    else{
        b = b + 0.13*b;
        c = c - 120;
        lam_tron(b);
        check_float(a,x,b,y,c,z);
        }

if (c==0)
{   

    a = a - 0.17*a;
    b = b + 0.17*b;
    lam_tron(a);
    lam_tron(b);
    check_float(a,x,b,y,c,z);
}
else
{if (b<300) c=c-100;
 else c=c-120;
 b=b-0.1*b;
 lam_tron(b);
 check_float(a,x,b,y,c,z);
    a = a - 0.17*a;
    b = b + 0.17*b;
    lam_tron(a);
    lam_tron(b);
    check_float(a,x,b,y,c,z);

}
    }

}
}
//////////////////////////////////////////////////////////
else {
    c1=c;
    for(;;){
    if (c==0||c<0.5*c1)
{   
    a = a - 0.17*a;
    b = b + 0.17*b;
    lam_tron(a);
    lam_tron(b);
    check_float(a,x,b,y,c,z);
    break;
    
}
else {
    if(a<200)
    {   a = a + 0.3*a;
        c = c - 150;
        lam_tron(a);
        check_float(a,x,b,y,c,z);
    }
    else
    {   a = a + 0.1*a;
        c = c - 70;
        lam_tron(a);
        check_float(a,x,b,y,c,z);
    }
if (c<0.5*c1)
{   
    a = a - 0.17*a;
    b = b + 0.17*b;
    lam_tron(a);
    lam_tron(b);
    check_float(a,x,b,y,c,z);
    break;
}
else{
    if(b<400)
    {
        b = b + 0.13*b;
        c = c - 200;
        lam_tron(b);
        check_float(a,x,b,y,c,z);
    }
    else{
        b = b + 0.13*b;
        c = c - 120;
        lam_tron(b);
        check_float(a,x,b,y,c,z);
        }

if (c<0.5*c1)
{   
    a = a - 0.17*a;
    b = b + 0.17*b;
    lam_tron(a);
    lam_tron(b);
    check_float(a,x,b,y,c,z);
    break;
}
else
{if (b<300) c=c-100;
 else c=c-120;
 b=b-0.1*b;
 lam_tron(b);
 check_float(a,x,b,y,c,z);
if (c<0.5*c1)
{   
    a = a - 0.17*a;
    b = b + 0.17*b;
    lam_tron(a);
    lam_tron(b);
    check_float(a,x,b,y,c,z);
    break;
}

}
    }

}
}
    }
for(i=b;;i++) if(so_cp(i)) break;
    for(j=b;;j--) if(so_cp(j)) break;
    if(i-b >= b - j)
    {
        s=j;
        p2 = 1;
    } else 
    {
        s=i;
        p2 = (b/s + 80)/123.00;
    }
//con duong 3///////////////////////////////////////////////////////
if (E2<10)
{
    idx=E2;
}
else
{ 
 idx = (E2/10) + (E2%10);
 idx = idx % 10;
}
p3=(float) P[idx]/100.00;
if (p1==1&&p2==1&&p3==1)
{
    b = b -0.25*b;
    lam_tron(b);
    check_float(a,x,b,y,c,z);
    
}
else
{
 Ptb=(float)(p1+p2+p3)/3.0;
 if (Ptb<0.5)
 {
    a=(float) a - 0.15*a;
    b=(float) b + 0.15*b;
    lam_tron(a);
    lam_tron(b);
    check_float(a,x,b,y,c,z);
 }
 else
 {  a=(float) a - 0.1*a;
    b=(float) b + 0.2*b;
    lam_tron(a);
    lam_tron(b);
    check_float(a,x,b,y,c,z);

 }
}
HP1 = a; EXP1 = b; M1 = c;

    return  HP1 + EXP1 + M1;
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int M1=0,M2=0,i,j;
    int so_hang, so_cot, max;
    int arr[10][10];
    check_int(HP1,HP2,EXP1,EXP2,M1,M2);
    if(E3<0 || E3> 99) return -99;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++)
        arr[i][j]= ((E3*j)+(i*2))*(i-j);
    }
    so_lon_nho(arr,so_hang,so_cot,E3);
    check_duongcheo (arr,so_hang,so_cot,max);
    if(abs(arr[so_hang][so_cot])>max){
        EXP1=0.88*EXP1+0.999;
        EXP2=0.88*EXP2+0.999;
        HP1=0.9*HP1+0.999;
        HP2=0.9*HP2+0.999;
        return arr[so_hang][so_cot];
    }
    else{
        EXP1= 1.12*EXP1 +0.999;
        EXP2= 1.12*EXP2+0.999;
        HP1= 1.1*HP1+0.9999;
        HP2= 1.1*HP2 +0.9999;
        check_int(HP1,HP2,EXP1,EXP2,M1,M2);
        return max;
    }
    
}
int check_duongcheo(int arr[10][10],int so_lon,int so_nho,int & max )
{   int i=so_lon,j=so_nho;
    max = arr[so_lon][so_nho];
   for(i= 0 ;i<10;i++)
    {   
        for(j= 0 ;j<10;j++)
        {
            if(max<arr[i][j] && (abs(i-so_lon)==abs(j-so_nho))) max=arr[i][j];

        } 
    }
   
    return 6004;
}

int so_lon_nho(int arr[10][10],int &so_lon,int &so_nho,int E3 ){
int i =0,j=0;
so_lon = 0; so_nho=0;
for(i=0;i<10;i++){
        for(j=0;j<10;j++)
        {
            if(arr[i][j]>(E3*2)) so_lon = so_lon + 1;
            if(arr[i][j]<((-1)*E3)) so_nho = so_nho + 1;
        }
    
    }
for(;so_lon>9;) so_lon = (so_lon/10) + (so_lon%10);
for(;so_nho>9;) so_nho = (so_nho/10) + (so_nho%10);
return 6005;
}
    
// Task 4
int checkPassword(const char * s, const char * email) {
    char se[strlen(email)];
    int a=0,sei=0,sci,b;
    bool t = false;
    for(int i =0;i<strlen(email);i++)
    {
        if(email[i]=='@') break;
        else {se[i]=email[i]; a=i+1;}
    }
    if (strlen(s)<8) return -1;
    if (strlen(s)>20) return -2;
    for(int i=0;i<(strlen(s));i++){
    for(int j=i;j<(i+a);j++)
    {   b=i;
        if(se[j-b]!=s[j]) break;
        if(j==i+a-1) {sei =i; t=1;}
    }
    if(t) break;
    }
    if(a==0){sei =0 ; t=1;}
if(t) return -(300+sei);
for(int i=0;i<strlen(s)-2;i++)
{
    if (s[i]==s[i+1] && s[i]==s[i+2])
    {
        sci=i;
        return -(400+sci);
    }
    
}
for(int i=0;i<strlen(s);i++){
    if(s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!') break;
    if (i== strlen(s)-1) return-5;

}
for(int i=0;i<strlen(s);i++){
if ((s[i]<30|| (s[i]>57 && s[i]<65) || (s[i]>90 && s[i]<97)|| s[i]>122)&&!(s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!')) return i;

    }
    
return -10;


}
// Task 5
struct passinfor
{
    int dodai, solan;
    string pass;
};
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    passinfor pass[num_pwds];
    int a=0;
    for(int i=0;i<num_pwds;i++) pass[i].solan=0;
    for(int i=0;i<num_pwds;i++){
        pass[i].pass=arr_pwds[i]; pass[i].dodai= strlen(arr_pwds[i]);
        for (int j=0;j<num_pwds;j++){
            if(pass[i].pass==arr_pwds[j]) pass[i].solan++;
        }

    }
    passinfor lastpass =pass[0];
    for(int i = 0;i < num_pwds;i++){
        if(lastpass.solan>pass[i].solan) continue;
        if(lastpass.solan<pass[i].solan) {lastpass = pass[i]; a=i;}
        if(lastpass.solan == pass[i].solan && lastpass.dodai<pass[i].dodai) {lastpass = pass[i]; a=i;}
        

    }

    

    return a;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////