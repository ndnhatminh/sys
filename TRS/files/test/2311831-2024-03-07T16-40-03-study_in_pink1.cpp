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
void checkBound(int &data, int type ) // type: 1 for HP, 2 for EXP, 3 for M 
{if (type==1) {
 data= ((data<0)? 0: ((data>666)? 666: data));   
} 
if (type==2) {
    data= ((data<0)? 0: ((data>600)? 600: data));  
}
if (type==3) {
    data= ((data<0)? 0: ((data>3000)? 3000: data));}  
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ((e1<0)||(e1>99)) {return -99;}
    //TH1 
    if ((e1>=0)&&(e1<=3)) {
        if (e1==0) exp2=exp2+29; 
        if (e1==1) exp2=exp2+45;
        if (e1==2) exp2=exp2+75;
        if (e1==3) exp2=exp2+29+45+75;
        checkBound(exp2,2);
    int D; D=e1*3+exp1*7; 
    if ((D%2)==0) {
        exp1=ceil(exp1+(float)(D)/200);
    } 
    else exp1=ceil(exp1-(float)(D)/100);
    checkBound(exp1,2);
    }
    //TH2
    if ((e1>=4)&&(e1<=99)) {
       if ((e1>=4)&&(e1<=19)) {
       exp2=exp2+ceil((float)(e1)/4+19.0); checkBound(exp2,2) ;} //TT1
       if ((e1>=20)&&(e1<=49)) {
       exp2=exp2+ceil((float)(e1)/9+21.0);checkBound(exp2,2) ;}  //TT2
       if ((e1>=50)&&(e1<=65)) {
       exp2=exp2+ceil((float)(e1)/16+17.0);checkBound(exp2,2);}  //TT3
       if ((e1>=66)&&(e1<=79)) {                                  //TT4
        exp2=exp2+ceil((float)(e1)/4+19.0);checkBound(exp2,2);
        if (exp2>200) {exp2=exp2+ceil((float)(e1)/9+21.0);
        checkBound(exp2,2);}
       } 
       if ((e1>=80)&&(e1<=99)) {                                  //TT5
         exp2=exp2+ceil((float)(e1)/4+19.0);checkBound(exp2,2);
         exp2=exp2+ceil((float)(e1)/9+21.0);checkBound(exp2,2);
         if (exp2>400) {exp2=exp2+ceil((float)(e1)/16+17.0);checkBound(exp2,2);
         exp2=ceil(1.15*(float)(exp2));checkBound(exp2,2);
         }
       }  
      exp1-=e1; checkBound(exp1,2);
    }
     return exp1 + exp2;
}


// Task 2
int findS (int data) {
        int a=sqrt(data); 
        if (abs((a*a)-data) > abs((a+1)*(a+1)-data)) return (a+1)*(a+1);
        else return a*a;
    }
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    double P1, P2, P3; int spent=0; double half= M1/2.0;
    if ((E2<0)||(E2>99)) {return -99;}
    //Road1
    if  (EXP1 >= findS(EXP1))  P1=1;
    else  P1=(EXP1/findS(EXP1)+80.0)/123.0;
    //Road2
     do {
    /*dot1*/
    if (HP1<200) {
        HP1=(HP1*130 + 99)/100;checkBound(HP1,1);          
        M1=M1-150;checkBound(M1,3);
        spent+=150;} 
    else {
        HP1=(HP1*110 + 99)/100;checkBound(HP1,1);
        M1=M1-70;checkBound(M1,3);                  
        spent+=70;
    }
    if (E2%2==1) {
        if (spent>half)   break ;  
    } else {
        if (M1==0)    break;}
    /*dot2*/
    if (EXP1<400) {
        M1=M1-200;checkBound(M1,3);      
        spent+=200;}
    else {
        M1=M1-120;checkBound(M1,3);
        spent+=120;}
    EXP1=(EXP1 * 113 + 99) / 100;checkBound(EXP1,2);
     if (E2%2==1) {
        if (spent>half)   break ;  
    } else {
        if (M1==0)    break;}
    /*dot3*/
    if (EXP1<300) {
        M1-=100;checkBound(M1,3);
        spent+=100;}
        else {
             M1-=120;checkBound(M1,3);
             spent+=120;
        }
    EXP1=(EXP1 * 90 + 99) / 100;checkBound(EXP1,2);
     if (E2%2==1) {
        if (spent>half)   break ;  
    } else {
        if (M1==0)    break;}
    }
    while (E2%2==1);
    HP1=(HP1*83 + 99)/100;checkBound(HP1,1);
    EXP1=(EXP1 * 117 + 99) / 100;checkBound(EXP1,2);
    if  (EXP1 >= findS(EXP1))  P2=1;
    else  P2=(EXP1/findS(EXP1)+80.0)/123.0;
    //Road3
    double P[10]={0.32,0.47,0.28,0.79,1.0,0.5,0.22,0.83,0.64,0.11};
    int sum2num=(E2%10)+E2/10;
    if ((E2>=0)&&(E2<=9)) {P3=P[E2];}
    else {P3=P[sum2num%10];}
    //endroad
    if ((P1==1.0)&&(P2==1.0)&&(P3==1.0))
    {
        EXP1=(EXP1 * 75 + 99) / 100;checkBound(EXP1,2);

    }
    else { if ((P1+P2+P3)/3<0.5 )
    {  EXP1=(EXP1 * 115 + 99) / 100;checkBound(EXP1,2);
       HP1=(HP1*85 + 99)/100;checkBound(HP1,1);
    }
        else { HP1=(HP1*90 + 99)/100;checkBound(HP1,1);
               EXP1=(EXP1 * 120 + 99) / 100;checkBound(EXP1,2);}
    }

    return HP1 + EXP1 + M1;
}

// Task 3
//Sherlock and Watson point
int greatestValOnX( int a[10][10], int m, int n){
int i=m, j=n, maxR=INT_MIN ,maxL=INT_MIN;
for(;((i>0)&&(j>0)) ; i--,j--);
while ((i<10)&&(j<10)) {
    if (a[i][j]>maxL)
    maxL=a[i][j];
    i++;j++;  
}
i=m;j=n;
for(;((i>0)&&(j<9)) ; i--,j++);
while ((i<10)&&(j>=0)) {
    if (a[i][j]>maxR)
    maxR=a[i][j];
    i++;j--; 
}
return std::max(maxR,maxL);
} 


int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int a=0,b=0,m=0,n=0;
    if ((E3<0)||(E3>99)) {return -99;}
    //create map
    int map[10][10];
    for (int i=0;i<10; i++)
       {for (int j=0;j<10;j++)
           {map[i][j]=((E3*j)+(i*2))*(i-j);}
           }
    //find the meet point      
    for (int i=0;i<10; i++)
       {for (int j=0;j<10;j++) 
         { if ((map[i][j])>(E3*2))  a=a+1;
           if ((map[i][j])<(-E3))   b=b+1;   
       }
       }
    if ((a%10+a/10)<10) m=a%10+a/10;
    else m=(a%10+a/10)/10+(a%10+a/10)%10;
    if ((b%10+b/10)<10) n=b%10+b/10;
    else n=(b%10+b/10)/10+(b%10+b/10)%10;
    if ( abs(map[m][n])> abs(greatestValOnX(map,m,n)) ) {
        EXP1=(EXP1*88 + 99)/100;checkBound(EXP1,2);
        HP1=(HP1*9 + 9) / 10;checkBound(HP1,1);
        EXP2=(EXP2*88 + 99)/100;checkBound(EXP2,2);
        HP2=(HP2*9 + 9) / 10;checkBound(HP2,1);
        return map[m][n]; }
    else {
        EXP1=(112*EXP1 +99)/100;checkBound(EXP1,2);
        HP1=(HP1*11 + 9) / 10;checkBound(HP1,1);
        EXP2=(112*EXP2 +99)/100;checkBound(EXP2,2);
        HP2=(HP2*11 + 9) / 10;checkBound(HP2,1);
        return greatestValOnX(map,m,n); }
}

// Task 4
//find'se'
void findse( const char email[], char ans[]) {
    int len=strlen(email);
    int i=0;
    for (int cnt=0; email[i] != '@' && i<= len; i++,cnt++) {
        ans[cnt] = email[i];
    }
    ans[i] ='\0';
}
//find se in email
int findnameinPsw(const char* a, const char* b) {
    int len=strlen(a), lim= strlen(b) - strlen(a) + 1;
    for (int i=0; i < lim; i++) 
        for (int j=0; j < len; j++) {
            if (a[j] != b[j+i])
                break;
            if (j==len-1)
            return i;
        }  
        return -1;
}
//passcheck
int charPswCheck(const char* s) {
    int len=strlen(s);
    for (int i=0; i < len; i++) {
        if (int(s[i]) != 33 && (int(s[i]) < 35 || int(s[i]) >37) && (int(s[i]) <64 || int(s[i]) >90) && (int(s[i]) <97 || int(s[i]) >122) && (int(s[i]) <48 || int(s[i]) > 57))
        return i;
    }
    return -1;
}
//repeatcheck
int repeatingcharCHK(const char* s) {
   int len=strlen(s);
   for (int i=0; i< len-2; i++) {
        if ((s[i] == s[i+1]) && (s[i+1] == s[i+2]))
        return i;
   }
   return -1;
}   
//specialcharcheck
bool specialCharCHK(const char* s) {
    int len= strlen(s);
    for (int i=0; i< len; i++) {
        if (s[i] == '!' || s[i] == '$' || s[i]== '%' || s[i]== '#' || s[i] == '@')
        return true;
    }
    return false;
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
if (strlen(s)<8)  return -1;
else if (strlen(s)>20) return -2;
char se[100]{ "" };
findse(email, se);
if (findnameinPsw(se, s) != -1) 
return (-300 - findnameinPsw(se, s));
else if (repeatingcharCHK(s) != -1)
         return (-400 - repeatingcharCHK(s));
    else if (!specialCharCHK(s))
        return -5;
        else if (charPswCheck(s) != -1)
             return charPswCheck(s);
             else return -10;       
             
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
int appear[num_pwds] = {0};
int lenght[num_pwds] = {0};
string arr_pwds_cstr[num_pwds];

for (int i=0; i< num_pwds; i++) {
    arr_pwds_cstr[i] = arr_pwds[i];
}
for (int i=0; i< num_pwds; i++) {
    string password = arr_pwds_cstr[i];
    appear[i]++;
    for (int j=0; j<i; j++) {
        if (arr_pwds_cstr[j] == password) {
        appear[i]++;
        }
    }
    lenght[i] = strlen(password.c_str());
}
int max_app = 0;
int max_len = 0;
string rightpass;
for (int i = 0; i< num_pwds; i++) {
    if (appear[i] > max_app || (appear[i] == max_app && lenght[i] == max_len)) {
        max_app = appear[i];
        max_len = lenght[i];
        rightpass = arr_pwds[i];
    
    }
}
for (int i=0; i < num_pwds; i++) {
    if (rightpass == arr_pwds[i]) {
         return i; 
         }
}
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////