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
// Task 1
     void test1(int &HP)
         {
         if (HP > 666)
         HP = 666;
         if (HP < 0)
         HP = 0;
         }
     void test2(int &EXP)
         {
         if (EXP > 600)
         EXP = 600;
         if (EXP < 0)
         EXP = 0;
         }
     void test3(int &M)
         {
         if (M > 3000)
         M = 3000;
         if (M < 0)
         M = 0;
         }
     int lamtron(float a)
         {
	     if(a!=(int)a)
	     return (int)a+1 ;
	     else
	     return (int)a;
         }
int firstMeet(int & exp1, int & exp2, int e1) {
      if (e1 < 0 || e1 > 99) 
	 return -99;
	else{
		test2(exp1);
		test2(exp2);
         if (e1>=0 && e1<=3)
       {
	     switch(e1) {
         case 0:
         exp2+=29;
         break; 
         case 1:
         exp2+=45;
         break;
         case 2:
         exp2+=75;
         break;
         case 3:
         exp2=exp2+29+45+75;
         break;
         }
         int D=e1*3 + exp1*7;
         if(D%2==0)
   	     exp1=lamtron(exp1+D*1.0/200);
         else
         exp1=lamtron(exp1-D*1.0/100);
        }
     else{
	     if(e1>=4&&e1<=19)
	     exp2=lamtron(exp2+(e1*1.0/4 + 19));
		 else if(e1>=20&&e1<=49)
		 exp2=lamtron(exp2+(e1*1.0/9 + 21));
		 else if(e1>=50&&e1<=65)
		 exp2=lamtron(exp2+(e1*1.0/16 + 17));
		 else if(e1>=66&&e1<=79){
		 exp2=lamtron(exp2+(e1*1.0/4 + 19));
		 if(exp2>200)
		 exp2=lamtron(exp2+(e1*1.0/9 + 21));
	     }
	     else {
	     exp2=lamtron(exp2+(e1*1.0/4 + 19));
		 exp2=lamtron(exp2+(e1*1.0/9 + 21));
		 if(exp2>400){
		 exp2=lamtron(exp2+(e1*1.0/16 + 17));
		 exp2 = lamtron(exp2 * 1.15);
	     }
		 }
         exp1=exp1-e1;
         }
     test2(exp1);
     test2(exp2);
     return exp1+exp2;
     }
}

// Task 2
     float xacsuat(int EXP){
	     int m,S;
     	m=(int)sqrt(EXP);
     	if((EXP-m*m)<=((m+1)*(m+1)-EXP))
     	S=m*m;
     	else 
     	S=(m+1)*(m+1);
     	if(EXP>=S)
     	return 1;
     	else
     	return (EXP*1.0/S+ 80)/123;
         }
     void an_uong(int &HP,int &M){
	     if(HP<200){
     	HP=lamtron(HP*1.3);
		 M-=150;
	    } 
		 else{
		 HP=lamtron(HP*1.1);
		 M-=70;
		 }	
         }
     void di_chuyen(int &EXP,int &M){
	     if(EXP<400)
	     M-=200;
	     else
	     M-=120;
	     EXP=lamtron(EXP*1.13);
         }
     void vogiacu(int &EXP,int&M){
	     if(EXP<300)
	     M-=100;
	     else
	     M-=120;
	     EXP=lamtron(EXP*0.9);
         }

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
      if (E2 < 0 || E2 > 99) 
	 return -99;
	 else{
		test2(EXP1);
        test1(HP1);
        test3(M1);
	    // con duong 1
     	float P1;
		 P1=xacsuat(EXP1);
     	//con duong 2
     	int n=M1;
     	if(E2%2!=0){
     	while(1){
     	    if(M1==0)
     		break;
     	an_uong(HP1,M1);
     	if(2*M1<n)
     	break;
		di_chuyen(EXP1,M1);
		if(2*M1<n)
     	break;
		test2(EXP1);	
		vogiacu(EXP1,M1);
		if(2*M1<n)
     	break;
		 }	
		 }
		 else{
		 for(int i=1;i<2;i++){
		 	if(M1==0)
     		break;
		 an_uong(HP1,M1);
		 test3(M1);
		 if(M1==0)
		 	break;
		 di_chuyen(EXP1,M1);
		 test3(M1);
		 if(M1==0)
		 	break;
		test2(EXP1);
		 vogiacu(EXP1,M1);
	   }
	   }
		 test1(HP1);
		 HP1=lamtron(HP1*0.83);
		 EXP1=lamtron(EXP1*1.17);
		 test2(EXP1);
		 float P2;
		 P2=xacsuat(EXP1);
		 // con duong 3
		 int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
		 int a=E2%10;
		 if(E2/10>0)
		 a+=E2/10;
		 float P3;
		 P3=P[a%10]*1.00/100;
		 if(P1==1&&P2==1&&P3==1)
		 	EXP1=lamtron(EXP1*0.75);
		 else{
		 	  if((P1+P2+P3)<0.5*3){
		 	  	HP1=lamtron(HP1*0.85);
		 	  	EXP1=lamtron(EXP1*1.15);
			   }
			   else{
			   	HP1=lamtron(HP1*0.9);
		 	  	EXP1=lamtron(EXP1*1.2);
			   }
		 }
		 test1(HP1);
		 test2(EXP1);
		 test3(M1);
		 return (HP1 + EXP1 + M1);
		 }
}

// Task 3
     
     int maximum(int A[10][10],int a, int b){
         int maxLeft = A[a][b];
         int maxRight = A[a][b];
            if(a<=b){
         for (int i =0;i<=9-(b-a) ; i++) {
         if(a==0&&b==9)
         break;
		 if(maxLeft<A[i][i+b-a])
		 maxLeft=A[i][i+b-a];
         }	
		 }
		    else{
		 for (int j=0;j<=9-(a-b) ; j++) {
         if(a==9&&b==0)
         break;
		 if(maxLeft<A[j+a-b][j])
		 maxLeft=A[j+a-b][j];
         }		
		 }
			if(a+b<=9){
		 for (int q = 0; q <=a+b;q++) {
		 if(a==0&&b==0)
         break;
         if(maxRight<A[q][a+b-q])
	   	 maxRight = A[q][a+b - q];
         }
		 }
            else{
         for (int m=0;m<=18-(a+b) ; m++) {
         if(a==9&&b==9)
         break;
		 if(maxRight<A[9-(18-(a+b))+m][9-m])
		 maxRight=A[9-(18-(a+b))+m][9-m];
         }	   	
		}
         if(maxLeft>=maxRight)
         return abs(maxLeft);
         else 
         return abs(maxRight);
         }	
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
     if (E3 < 0 || E3 > 99) 
	 return -99;
	 else{
		test1(HP1);
		test2(EXP1);
		test1(HP2);
	    test2(EXP2);
	 int A[10][10]={0};
	 int diem_taxi,diem_SW,a=0,b=0;
	 for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			A[i][j]= ((E3 * j) + (i * 2)) * (i - j);
			if(A[i][j] >2*E3)
			a+=1;
			if(A[i][j]<-E3)
			b+=1;
	     }
     }
     if(a==100)
     a=1;
     else{
    	a=a%10+a/10;
    	a=a%10+a/10;
	 }
	 if(b==100)
     b=1;
     else{
    	b=b%10+b/10;
    	b=b%10+b/10;
     }
     diem_taxi=A[a][b];
     diem_SW=maximum(A,a,b);
     if(abs(diem_taxi)>diem_SW){
    	HP1=lamtron(HP1*0.9);
    	EXP1=lamtron(EXP1*0.88);
    	HP2=lamtron(HP2*0.9);
    	EXP2=lamtron(EXP2*0.88);
    	return diem_taxi;
	 }
	 else{
	    HP1=lamtron(HP1*1.1);
    	EXP1=lamtron(EXP1*1.12);
    	HP2=lamtron(HP2*1.1);
    	EXP2=lamtron(EXP2*1.12);
    	test1(HP1);
		test2(EXP1);
		test1(HP2);
	    test2(EXP2);
    	return diem_SW;	
	 }
     }
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // Check password length
     int len = strlen(s);
     if (len < 8) {
        return -1;  
     }
     if (len > 20) {
        return -2; 
     }
    // Check for 'se'
	 int t;
     for (int j = 0; j < strlen(email); j++) {
        if (email[j] == '@') {
            t = j;
            break;
        }
     }
     char se[100];
     strncpy(se, email, t);
     se[t] = '\0'; 
     if (strstr(s, se) != NULL) {
        return -(300 + (strstr(s, se) - s));
     }
     for (int q = 0; q < len - 2; ++q) {
        if (s[q] == s[q + 1] && s[q + 1] == s[q + 2]) {
            return -(400 + q);  
        }
     }
   //Check ky tu dac biet
     const char *specialChars = "@#%$!";
     bool hasSpecialChar = false;
     for (int j = 0; j < len; ++j) {
        if (strchr(specialChars, s[j])) {
            hasSpecialChar = true;
            break;
        }
     }
     if (!hasSpecialChar) {
        return -5; 
     }
    //check ky tu ngoai le
	 for(int i=0;i<len;i++){
	 if(!((int)s[i]==33||((int)s[i]>=35&&(int)s[i]<=37)||((int)s[i]>=48&&(int)s[i]<=57)||((int)s[i]>=64&&(int)s[i]<=90)||((int)s[i]>=97&&(int)s[i]<=122))){
		return i;
		break;
	 }	
     }
     return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
     int max_n = 0;
     int max_cdai = 0;
     int max_chi_so = 0;

     for (int i = 0; i < num_pwds; ++i) {
        int n = 1;
        int cdai = strlen(arr_pwds[i]);

        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                n++;
            }
        }

        if (n > max_n || (n == max_n && cdai > max_cdai)) {
            max_n = n;
            max_cdai = cdai;
            max_chi_so = i;
        }
    }

    return max_chi_so;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
