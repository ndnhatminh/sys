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
//Ham kiem tra dieu kien
int check(int &n, int max)
{
    if(n<0) n=0;
	else if(n>max) n = max;	
 return n;	
}
//Ham lay mot chu so bai 2
int laymotchuso2(int n)
{
	int m;
	if(n/10) {
	m=n/10+n%10;
	 return m%10;
	 }
	 else return n;
}
//Ham xac suat 
float Xacsuat(int EXP1){
	int n=sqrt(EXP1);
	int S;
	float P;
	if((n+1)*(n+1)-EXP1>EXP1-n*n) S =n;
	else S =n+1;
	if (EXP1>=S) P=100;
	else P=(1.0*EXP1/S+80)/123;
return P;	
}
//Ham hd1
int hd1(int & HP1, int & EXP1, int & M1, int E2){
	if (HP1<200) 
	{
		HP1=ceil(HP1+HP1*0.3);
		M1-=120;
		return 120;
	}
	else 
	{
		HP1=ceil(HP1+HP1*0.1);
		M1-=70;
		return 70;
	}
	HP1=check(HP1,666);
	M1=check(M1,3000);
}
//Ham hd2
int hd2(int & HP1, int & EXP1, int & M1, int E2){
	if(EXP1<400){
		M1-=200;
		return 200;
	}
	else 
	{
		M1-=120;
		return 120;
	}
	EXP1=ceil(EXP1+EXP1*0.13);
	M1=check(M1,3000);
	EXP1=check(EXP1,600);
}
//Ham hd3
int hd3(int & HP1, int & EXP1, int & M1, int E2){
	if(EXP1<300)
	{
		M1-=100;
		return 100;
	}
	else
	{
		M1-=120;
		return 120;
	}
	EXP1=ceil(EXP1-0.1*EXP1);
	EXP1=check(EXP1,600);
	M1=check(M1,3000);
}
// Ham lay mot chu so bai 3
int laymotcs3(int &n)
{
	while(n/10)
	{
		n=n/10+n%10;
	}
	return n;
}
//Ham tim GTLN cua cheo trai 
int maxtrai(int arr[10][10],int n1,int n2)
{
	int max=arr[n1][n2];
	while ((n1!=0)&&(n2!=0))
	{
		n1-=1;
		n2-=1;
	}
	while ((n1!=10)&&(n2!=10))
	{
		if(arr[n1][n2]>max) max=arr[n1][n2];
		n1+=1;
		n2+=1;
	}
	return max;
}
//Ham  tim GTLN cua cheo phai
int maxphai(int arr[10][10],int n1, int n2)
{
	int max=arr[n1][n2];
	if((n1+n2)<9){
		while(n1)
		{
			n1-=1;
			n2+=1;
		}
		while (n2<0)
		if(arr[n1][n2]>max) max=arr[n1][n2];
		n1+=1;
		n2-=1;
	}
	else 
	{
		while(n2!=9)
		{
			n1-=1;
			n2+=1;
			
		}
		while(n1!=10)
		{
			if(arr[n1][n2]>max) max=arr[n1][n2];
		n1+=1;
		n2-=1;
		}
	}
	return max;
}
//Ham kiem tra ki tu db
bool Spec(const char a)
{
	bool check=false;
	char spec[]="@#%$!";
	for (int i=0;i<strlen(spec);i++){
		if (a==spec[i]) {
			check=true;
			break;
		}
	}
	return check;
}
//Ham kiem tra ki tu thuong hoa so
bool kt(const char a)
{
	if (((a>47)&&(a<58))||((a>64)&&(a<91))||((a>96)&&(a<123)) )return true;
	else return false;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
     if ((e1<0)||(e1>99)) return -99;
 else 
 { 
  exp1=check(exp1,600);
  exp2=check(exp2,600);
  if (e1<4)//Truong hop 1
  {
  	if(e1==0) exp2+=29;
  	else if (e1==1) exp2+=45;
  	else if (e1==2) exp2+=75;
  	else exp2+=(29+45+75);
  	
  	int D=e1*3 + exp1*7;
  	if(D%2) 	exp1=ceil(exp1-1.0*D/100);
  	else        exp1=ceil(exp1+1.0*D/200);
  }
  else //Truong hop 2
  {
  	if (e1<20) exp2=ceil(exp2 + 1.0*e1/4 + 19);
  	else if (e1<50) exp2=ceil(exp2 + 1.0*e1/9 + 21);
  	else if (e1<66) exp2=ceil(exp2 + 1.0*e1/16 + 17);
  	else if (e1<80) { exp2=ceil(exp2 + 1.0*e1/4 + 19);
	                  if(exp2>200) exp2=ceil(exp2 + 1.0*e1/9 + 21);
					   }
  	else { exp2=ceil(exp2 + 1.0*e1/4 + 19); 
  	       exp2=ceil(exp2 + 1.0*e1/9 + 21);
  	       if (exp2>400){ exp2=ceil(exp2 +1.0*e1/16 + 17);
  	       	              exp2=check(exp2,600);
  	       	              exp2=ceil(exp2+exp2*0.15);
  	       }
  	}
  	
  }
  exp1-=e1;
  exp1=check(exp1,600);
  exp2=check(exp2,600);
  return exp1+exp2;
 }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
if ((E2<0)||(E2>99)) return -99;
 else
 {
 	HP1=check(HP1,666);
 	M1=check(M1,3000);
 	//con duong 1
 	int P1 = Xacsuat(EXP1);
 	//con duong 2
 	int N=M1;
 	int M=0;
 	if(E2%2) 
 	{
 		while (M<0.5*N){
 			M+=hd1(HP1,EXP1,M1,E2);
 			if(M<0.5*N)
 			{
 				M+=hd2(HP1,EXP1,M1,E2);
 				if(M<0.5*N) M+=hd3(HP1,EXP1,M1,E2);
 			}
 		}
 		
 	}
 	else 
 	{
 		if(M1!=0){
 			hd1(HP1,EXP1,M1,E2);
 			if(M1!=0)
 			{
 				hd2(HP1,EXP1,M1,E2);
 				if(M1!=0) hd3(HP1,EXP1,M1,E2);
 			}
 		}
 	}
 	EXP1=ceil(EXP1+EXP1*0.17);
 	HP1=ceil(HP1-HP1*0.17);
 	HP1=check(HP1,666);
 	EXP1=check(EXP1,600);
 	float P2=Xacsuat(EXP1);
 	//con duong 3
 	int P[10]={32,47,28,79,100,50,22,83,64,11};
 	int P3=P[laymotchuso2(E2)];
 	int PT;
 	if((P1==100)&&(P2==100)&&(P3==100)) EXP1=ceil(EXP1-EXP1*0.25);
 	else {
 	PT=(P1+P2+P3)/3;
 	if (PT<50)
 	{
 		HP1=ceil(HP1-HP1*0.15);
 		EXP1=ceil(EXP1+EXP1*0.15);
 	}
 	else 
 	{
	 HP1=ceil(HP1-HP1*0.1);
 		EXP1=ceil(EXP1+EXP1*0.2);
 		
 	}
 }
 HP1=check(HP1,666);
 EXP1=check(EXP1,600);	
 return HP1+EXP1+M1;
} }
   


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if((E3<0)||(E3>99)) return -99;
	else 
	{
		int n1=0,n2=0;
		int taxi[10][10];
		for (int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				taxi[i][j]=((E3*j)+(i*2))*(i-j);
				if (taxi[i][j]>2*E3) n1+=1;
				if (taxi[i][j]<-1.0*E3) n2+=1;
				
				
			}
		}
	 n1=laymotcs3(n1);
	 n2=laymotcs3(n2);
	 int sher;
	 if(maxphai(taxi,n1,n2)>maxtrai(taxi,n1,n2)) sher=abs(maxphai(taxi,n1,n2));
	 else sher=abs(maxtrai(taxi,n1,n2));
	 cout<<maxphai(taxi,n1,n2);
	 if (abs(taxi[n1][n2])>sher) 
	 {
	 	EXP1=ceil(EXP1-EXP1*0.12);
	 	EXP2=ceil(EXP2-EXP2*0.12);
	 	HP1=ceil(HP1-HP1*0.1);
	 	HP2=ceil(HP2-HP2*0.1);
	 	return taxi[n1][n2];
	 }	
	 else
	 {
	 	EXP1=ceil(EXP1+EXP1*0.12);
	 	EXP2=ceil(EXP2+EXP2*0.12);
	 	HP1=ceil(HP1+HP1*0.1);
	 	HP2=ceil(HP2+HP2*0.1);
	 	return sher;
	 }
	 
	}
}

   

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

	int i=0;
	char se[strlen(email)];
	while (email[i]!='@')
	{
		se[i]=email[i];
		i+=1;
	}
	se[i]='\0';
if (strlen(s)<8) return -1;
if (strlen(s)>20) return -2;
char *result=strstr(s,se);
if (result!=NULL) return -(300+result-s);
for(int n=2; n<strlen(s);n++)
{
	if((s[n]==s[n-1])&&(s[n-1]==s[n-2])) return -(400+n-2);
	
}
bool ktdb=false;
for ( int i=0;i<strlen(s);i++)
{
	if (Spec(s[i])==1){
		ktdb=true;
		break;
	}
	}
	if (ktdb) return -5;
for ( int i=0;i<strlen(s);i++)	
	{
		if (kt(s[i])==0) {
		return i;
		break;
	}
}
return -10;

}

int countsl(const char *arr_pwds[],const char *arr,int num )
{
	int count=0;
	for(int i=0;i<num;i++)
	{
		if (arr_pwds[i]==arr) count++;
	}
	return count;
}
int demchu1(const char *arr,int num )
{
	int i=0;
	while(arr[i]!='\0')
	i++;
	return i;
}


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
int max1=0,max2=0;
    int count[num_pwds];
for ( int i=0;i<num_pwds;i++)
{
	count[i]=countsl(arr_pwds,arr_pwds[i],num_pwds);
	if(count[i]>max1) max1=count[i];
}
int demchu[num_pwds];
for ( int i=0;i<num_pwds;i++)
{
	demchu[i]=demchu1(arr_pwds[i],num_pwds);
	if((demchu[i]>max2)&&(count[i]==max1)) max2=demchu[i];
}
for(int i=0;i<num_pwds;i++)
{
	if((count[i]==max1)&&(demchu[i]==max2)) return i;
}

}

  


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
