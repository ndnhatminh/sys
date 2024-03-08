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
void checkHP(int & HP)
 {
 	if(HP > 666)
	 HP = 666;
	if(HP < 0)
	 HP = 0; 
 
  } 
void checkEXP(int & EXP)
  {
  	if(EXP >600)
  	 EXP=600;
  	 if( EXP <0)
  	 EXP=0;
   } 
 
void checkM(int & M)
  {
  	if(M>3000)
  	M=3000;
  	if(M<0)
  	M=0;
   } 
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
  return -99;
  if (e1>=0 && e1<=3)
    {
        checkEXP(exp1);
        checkEXP(exp2);
        if(e1==0)
        {
        exp2+=29.0;
        }
        else if(e1==1)
        { 
            exp2+=45.0;
        }
        else if(e1==2)
        {
            exp2+=75.0;
        }
        else if(e1==3)
        {
            exp2=exp2+29+45+75;
        }
        checkEXP(exp2);
        int D;
        D=e1*3+ exp1*7;
        if(D%2==0)
        {
            exp1 = ceil(exp1 + (D / 200.0)) ;
        }
        else
        {
             exp1 = ceil(exp1 - (D / 100.0));
        }
        checkEXP(exp1);
    }
    else if(e1>=4&&e1<=99)
    {
         checkEXP(exp1);
        checkEXP(exp2);
        if(e1>=4&&e1<=19)
        {
           exp2=ceil(exp2+e1/4.0 + 19.0);
        }
        else if(e1>=20&&e1<=49)
        {
            exp2=ceil(exp2+e1/9.0 + 21.0);
        }
        else if(e1>=50&&e1<=65)
        {
           exp2=ceil(exp2+e1/16.0 + 17.0);
        }
        else if(e1>=66&&e1<=79)
        {
           exp2=ceil(exp2+e1/4.0 + 19.0);
            if(exp2>200)
            {
                exp2=ceil(exp2+e1/9.0 + 21.0);
            }
        }
        else if(e1>=80&&e1<=99)
        {
            exp2=ceil(exp2+e1/4.0 + 19.0);
            exp2=ceil(exp2+e1/9.0 + 21.0);
            if(exp2>400)
            {
                exp2=ceil(exp2+e1/16.0 + 17.0);
                exp2=ceil(exp2*115.0/100);  
            }
             
                      
        }
        exp1-=e1;
        checkEXP(exp1);
        checkEXP(exp2);
    }
    
   
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
if (E2 < 0 || E2 > 99) 
     return -99;  
    
    checkEXP(EXP1);
    checkHP(HP1);
    checkM(M1);
    double  a=floor(sqrt(EXP1));
    double  b=1+a;
    int c=ceil(a*a);
    int d=ceil(b*b);
    int S;
    if( EXP1-c<d-EXP1)
    {
        S=c;
    }
    else 
    {
        S=d;
    }
    float P1;
    if(EXP1>=S)
    {
        P1=1.00;
    }
    else 
    {
        P1=((EXP1*1.00/S + 80)/123.00);
       
    }
   
    float P2;
    if( E2%2==0)
    {
        while(5){
            if(M1==0){break;}
            if(HP1<200)
            {
                HP1=ceil(HP1*130.0/100);
                checkHP(HP1);
                M1-=150;
            checkM(M1);
            }
            else
            {
                HP1=ceil(HP1*11.0/10);
                checkHP(HP1);
                M1-=70;
                checkM(M1);
             
            }
            if(M1==0){break;}
            if(EXP1<400)
            {   
                M1-=200;
                checkM(M1);
                    
            }          
            else 
            {
                M1-=120;
                checkM(M1);
                
            }
                EXP1=ceil(EXP1*113.0/100);
                checkEXP(EXP1);
            if(M1==0){break;}
            if(EXP1<300)
            {
                M1-=100;
                checkM(M1);
            }  
            else
            {
                M1-=120;  
                checkM(M1);
            }
            EXP1=ceil(EXP1*90.0/100);
            checkEXP(EXP1);
            
            break;
        }
         EXP1=ceil(EXP1*117.0/100);
        HP1=ceil(HP1*83.0/100);
            checkEXP(EXP1);
            checkHP(HP1);
    }
    else 
    {     
        int m=0;
        int n=(M1/2);
        
        while(5)
        {           
            if(M1==0){break;}
            if(m>n){break;}      
            if(HP1<200)
            {
                HP1=ceil(HP1*130.0/100);
                checkHP(HP1);
                M1-=150;
                m+=150;
            }
            else
            {
                HP1=ceil(HP1*11.0/10);
                checkHP(HP1);
                M1-=70;
                checkM(M1);
                m+=70;
            }
             if(m>n){break;} 
            if(EXP1<400)
            {
                M1-=200;
                checkM(M1);
                m+=200;    
            }          
            else 
            {
                M1-=120;
                checkM(M1);
                m+=120;
            }
                EXP1=ceil(EXP1*113.0/100);
                checkEXP(EXP1);
             if(m>n){break;} 
            if(EXP1<300)
            {
                M1-=100;
                m+=100;
                checkM(M1);
            }  
            else
            {
                M1-=120;
                m+=120;
                checkM(M1);
            }
            EXP1=ceil(EXP1*90.0/100);
              checkEXP(EXP1);
            }
             EXP1=ceil(EXP1*117.0/100);
            HP1=ceil(HP1*83.0/100);
            checkEXP(EXP1);
            checkHP(HP1);}

      
   
   double k=floor(sqrt(EXP1));
  double h=k+1;
     int u=ceil(k*k);
     int v=ceil(h*h);
    int R;
    if( EXP1-u<v-EXP1)
    {
        R=u;
    }
    else 
    {
        R=v;
    }
 
    if(EXP1>=R)
    {
        P2=1.00;
    }
    else 
    {
        P2=(EXP1*1.00/R+ 80)/123.00;
       
    }
    
static double P[10]= {0.32, 0.47, 0.28, 0.79, 1.00, 0.50, 0.22, 0.83, 0.64, 0.11};
float P3;
float Pt;
int i;
    if(E2<10)
    {
    i=E2;
    P3=P[i];

    }
    else
    {
        i=(E2/10+E2%10);
        if(i>=10){
        i=i%10;}
        P3=(P[i]);
       
    }
 
       
    if(P1==1.00 && P2==1.00 && P3==1.00)    {
       EXP1=ceil(EXP1*75.0/100);
       checkEXP(EXP1);
    }
    else 
    {
        
      Pt=((P1+P2+P3)/3.00);
        if(Pt<0.50)
        {
        HP1=ceil(HP1*85.0/100);
        EXP1=ceil(EXP1*115.0/100);
        }
        else
        {
        HP1=ceil(HP1*90.0/100);
        EXP1=ceil(EXP1*120.0/100);
        }
   
    }
     checkM(M1);
    checkEXP(EXP1);
    checkHP(HP1);
    return HP1 + EXP1 + M1;
   
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
  if(E3<0||E3>99){return -99;}
    int arr[10][10]={0};
    long int shelpoint;
   int taxipoint[10][10]={0};
    int bigger=0;
    int smaller=0;
    int posI=0;
    int posJ=0;
 for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
             arr[i][j]=((E3 * j) + (i * 2)) * (i - j);
             taxipoint[i][j]=arr[i][j];
            if(arr[i][j]>2*E3)
             {
               bigger++;
         }
             
             if(arr[i][j]<(-E3))
             {
             	smaller++;
            } 
             
        }
    }
   
while(2){
	if(bigger<10){
		posI=bigger;
		break;
	}else {
		bigger=(bigger%10) + bigger/10;
	}
}
while(2){
	if(smaller<10){
		posJ=smaller;
		break;
	}else{
		smaller=(smaller%10 )+ smaller/10;
	}
}           
	shelpoint=arr[posI][posJ];
	for( int i=0;i<10;++i)
    { 
    if(posI-i<0 || posJ-i<0){break;}
   if(shelpoint<arr[posI-i][posJ-i]){
       	shelpoint=arr[posI-i][posJ-i];
	   }
    }
   for(int i=0;i<10;++i){
   	
   	if(posI-i<0||posJ+i>9){break;}
	if(shelpoint<arr[posI-i][posJ+i]){
		shelpoint=arr[posI-i][posJ+i];
	}
   } 
   for(int i=0;i<10;++i){
   	if(posI+i>9 || posJ-i<0){break;}
	if(shelpoint<arr[posI+i][posJ-i]){
		shelpoint=arr[posI+i][posJ-i];
	}
   }
   for(int i=0;i<10;++i){
   	if(posI+i>9 ||posJ+i>9){break;}
	if(shelpoint<arr[posI+i][posJ+i]){
		shelpoint=arr[posI+i][posJ+i];
	}
   }

int Sherlockpoint=abs(shelpoint);
if(abs(taxipoint[posI][posJ])>Sherlockpoint)
{
HP1=ceil(HP1*90.0/100);
EXP1=ceil(EXP1*88.0/100);
HP2=ceil(HP2*90.0/100);
EXP2=ceil(EXP2*88.0/100);
}
else 
{
    HP1=ceil(HP1*11.0/10);
    EXP1=ceil(EXP1*112.0/100);  
    HP2=ceil(HP2*11.0/10);
    EXP2=ceil(EXP2*112.0/100);       
}
checkEXP(EXP1);
checkHP(HP1);
checkEXP(EXP2);
checkHP(HP2);
if(abs(taxipoint[posI][posJ])>shelpoint)
{
    return taxipoint[posI][posJ];
}
else 
{return shelpoint;}
   return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
char se[101];
 int i;
 for(i=0;email[i]!='\0' && email[i] !='@' ;++i)
 {
    se[i]=email[i];
 }
  se[i]='\0';
  
  
    if(strlen(s)<8)
    {
        return -1;
    }
     if(strlen(s)>20)
    {
        return -2;
    }

    const char* p;
    p=strstr(s,se);
    int sei;
    sei=p-s;
    if(p !=nullptr)
    {
        return -(300+sei);
    } 

    for (int i = 0; i < strlen(s) - 2; ++i) {
        if (s[i] == s[i+1] && s[i] == s[i+2])
            return -(400 + i);
    }
const char special[]="@#$%!";
bool e=0;
for(i=0;s[i]!='\0';++i)
{   
    for(int j=0;special[j]!='\0';++j)
    {
        if(s[i]==special[j]){
            e=1;
            
            break;
        }  
     } 
     }
     if(!e){
        return -5;
     }
    
  
for(i=0;s[i]!='\0';++i)
{
if(!(isdigit(s[i])||(islower(s[i]))||(isupper(s[i]))||s[i]=='@'||s[i]=='#'||s[i]=='$'||s[i]=='$'||s[i]=='!'))
{
    return i;
} 
}
return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
int count[num_pwds] = {0};
    for (int i = 0; i < num_pwds; ++i) {
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count[i]++;
            }
        }
    }
    int maxfrequency = 0;
    int maxlength = 0;
    int index = -1;
    for (int i = 0; i < num_pwds; ++i) {
       if (count[i] > maxfrequency || (count[i] == maxfrequency && strlen(arr_pwds[i]) > maxlength)) {
            maxfrequency = count[i];
            maxlength = strlen(arr_pwds[i]);
            index = i;
        }
    }

    return index;
    
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
