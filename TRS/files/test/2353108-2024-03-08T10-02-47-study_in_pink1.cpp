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
    // TODO: Complete this function
     if (e1 < 0 || e1 > 99) return -99;
     	if (exp2 > 600)
	{
		exp2=600;
	}
    if (exp2 < 0)
    {
        exp2=0;
    }
    if(exp1>600)
    {
        exp1=600;
    }
    if(exp1<0)
    {
        exp1=0;
    }
      if(e1==0) {
       exp2 = exp2 + 29;
     }
      if(e1==1) {
        exp2 = exp2 + 45;
      }
      if(e1==2) {
        exp2 = exp2 + 75;
      }
      if(e1==3) { 
        exp2 = exp2 + 149;
      }
    int D=ceil((e1*3)+(exp1*7));
	if (D%2==0 && e1>=0 && e1<=3)
	{
		exp1=ceil(exp1+D/200);
	}
	else if (D%2!=0 && e1>=0 && e1<=3)
	{
		exp1=ceil(exp1-D/100);
	}
    if (e1 > 3 && e1 < 100)
    {
        exp1 = exp1 - e1;
    }
	if (e1>=4 && e1<=19)
	{
		exp2 = exp2 + ceil((e1*1.00)/4+19);
	}
	if (e1>=20 && e1<=49)
	{
		exp2 = exp2 + ceil((e1*1.00)/9+21);
	}
	if (e1>=50 && e1<=65)
	{
		exp2 = exp2 + ceil((e1*1.00)/16+17);
	}
	if (e1>=66 && e1<=79)
	{
		exp2 = exp2 + ceil((e1*1.00)/4+19);
		if (exp2>200)
		{
			exp2 = exp2 + ceil((e1*1.00)/9+21);
		}
	}
	if (e1>=80 && e1<=99)
	{
	   exp2 = exp2 + (ceil((e1*1.00)/4+19)+ceil((e1*1.00)/9+21));
	   if (exp2>400)
	   {
	   	   exp2 = exp2 + ceil((e1*1.00)/16+17);
           exp2 = ceil (exp2* 1.15);
	   }	
       exp2=ceil(exp2);
    
	}
	if (exp2 > 600)
	{
		exp2=600;
	}
    if (exp2 < 0)
    {
        exp2=0;
    }
    if(exp1>600)
  {
      exp1=600;
  }
  if(exp1<0)
  {
      exp1=0;
  }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
if (E2 < 0 || E2 > 99) return -99;
  if(EXP1>600)
  {
      EXP1=600;
  }
  if(EXP1<0)
  {
      EXP1=0;
  }
  if(HP1>666)
  {
      HP1=666;
  }
  if(HP1<0)
  {
      HP1=0;
  }
  if(M1>3000)
  {
      M1=3000;
  }
    if(M1<0)
  {
      M1=0;
  }
 float P1,P2,P3,P;
 int spent=0;
  int S1,S2;
  int Mc=ceil(M1/2);
  S1=(ceil(sqrt(EXP1))) * (ceil(sqrt(EXP1)));
  if(S1 - EXP1>EXP1 - (floor(sqrt(EXP1))*floor(sqrt(EXP1))) )
  {
      S1=floor(sqrt(EXP1))*floor(sqrt(EXP1));
  }
  else{
      S1=(ceil(sqrt(EXP1))) * (ceil(sqrt(EXP1)));
  }
  if(EXP1>=S1)
  {
      P1=100;
  }
  else{
      P1=ceil(((EXP1/S1 + 80)/123.00)*100);
  }
 if(E2%2!=0){
   do{
  if(HP1>=200){
      HP1=ceil(HP1*1.1);
      M1=M1 - 70;
      spent=spent + 70;
  }
  else if(HP1<200){
      HP1=ceil(HP1*1.3);
      M1=M1 - 150;
      spent=spent + 150;
  }
  if(EXP1>=400){
      M1=M1 - 120;
      spent=spent + 120;
        EXP1=ceil(EXP1*1.13);
  }
  else if(EXP1<400){
      M1=M1 - 200;
      spent=spent + 200;
        EXP1=ceil(EXP1*1.13);
  }
  if(EXP1>=300){
      M1=M1 - 120;
      spent=spent + 120;
  }
  else if(EXP1<300){
      M1=M1 - 100;
      spent=spent + 100;
  }
  EXP1=ceil(EXP1*0.9);
  }while(!spent>Mc);
  if(HP1>=200  && spent<=Mc){
      HP1=ceil(HP1*1.1);
      M1=M1 - 70;
      spent=spent + 70;
  }
  else if(HP1<200 && spent<=Mc){
      HP1=ceil(HP1*1.3);
      M1=M1 - 150;
      spent = spent + 150;
  }
  if(EXP1>=400 && spent<=Mc){
      M1=M1 - 120;
       EXP1=ceil(EXP1*1.13);
       spent = spent + 120;
  }
  else if(EXP1<400 && spent<=Mc){
      M1=M1 - 200;
       EXP1=ceil(EXP1*1.13);
       spent = spent + 200;
  }
  if(EXP1>=300 && spent<=Mc){
      M1=M1 - 120;
      EXP1=ceil(EXP1*0.9);
      spent=spent + 120;
  }
  else if(EXP1<300 && spent<=Mc){
      M1=M1 - 100;
      EXP1=ceil(EXP1*0.9);
      spent=spent + 100;
    }
  } 
  if(E2%2==0){
  if(HP1>=200 && M1>0){
      HP1=ceil(HP1*1.1);
      M1=M1 - 70;
  }
  else if(HP1<200 && M1>0){
      HP1=ceil(HP1*1.3);
      M1=M1 - 150;
  }
  if(EXP1>=400 && M1>0){
    M1=M1 - 120;
     EXP1=ceil(EXP1*1.13);
  }
  else if(EXP1<400 && M1>0){
     M1=M1 - 200;
      EXP1=ceil(EXP1*1.13);
  }
  if(EXP1>=300 && M1>0){
      M1=M1 - 120;
      EXP1=ceil(EXP1*0.9);
  }
  else if(EXP1<300 && M1>0){
      M1=M1 - 100;
      EXP1=ceil(EXP1*0.9);
  }
  }
  HP1=ceil(HP1*0.83);
  EXP1=ceil(EXP1*1.17);
  S2=(ceil(sqrt(EXP1))) * (ceil(sqrt(EXP1)));
    if(S2 - EXP1>EXP1 - (floor(sqrt(EXP1))*floor(sqrt(EXP1))) )
  {
      S2=floor(sqrt(EXP1))*floor(sqrt(EXP1));
  }
  else{
      S2=(ceil(sqrt(EXP1))) * (ceil(sqrt(EXP1)));
  }
  if(EXP1>=S2)
  {
      P2=100;
  }
  else{
      P2=ceil(((EXP1/S2 + 80)/123.00)*100);
  }
  int Pn[15] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
  int a,b,i;
  if(E2>=10){
  a = E2/10;
  b = E2%10;
  }
  if(E2<10){
  i=E2;
  }
  if(E2>=10 && a+b>10){
  i = (a+b)%10;   
  }
  if(a+b==10){
  i = 1;
  }
  if(E2>=10 && a+b<10){
  i = a + b;
  }
  P3 = Pn[i];
  P = (P1+P2+P3)/3;
  if(P==100){
      EXP1=ceil(EXP1*0.75);
  }
  if(P>=50 && P<100){
      HP1=ceil(HP1*0.9);
      EXP1=ceil(EXP1*1.2);
  }
    if(P<50 && P>=0){
      HP1=ceil(HP1*0.85);
      EXP1=ceil(EXP1*1.15);
  }
   if(EXP1>600)
  {
      EXP1=600;
  }
  if(EXP1<0)
  {
      EXP1=0;
  }
  if(HP1>666)
  {
      HP1=666;
  }
  if(HP1<0)
  {
      HP1=0;
  }
  if(M1>3000)
  {
      M1=3000;
  }
    if(M1<0)
  {
      M1=0;
  }
  return EXP1+HP1+M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
      if(EXP1>600)
  {
      EXP1=600;
  }
  if(EXP1<0)
  {
      EXP1=0;
  }
  if(HP1>666)
  {
      HP1=666;
  }
  if(HP1<0)
  {
      HP1=0;
  }
  if(EXP2>600)
  {
      EXP2=600;
  }
  if(EXP2<0)
  {
      EXP2=0;
  }
  if(HP2>666)
  {
      HP2=666;
  }
  if(HP2<0)
  {
      HP2=0;
  }
int a=0, b=0;
int X1, Y1, X2, Y2, i1, i2;
int taxi, SW;
int result;
int i,j;
int A[10][10];
for(i=0;i<10;i++)
{
  for(j=0;j<10;j++)
  {
    A[i][j]= ((E3*j) + (i*2)) * (i - j);  
    if(A[i][j]>2*E3){
      a=a+1;  
    }
    if(A[i][j]<-E3){
      b=b+1;  
    }
  }
}
 if(a>=10){
  X1 = a/10;
  Y1= a%10;
  }
  else if(a<10){
  i1=a;
  }
  if(a>=10 && X1+Y1>10){
  i1 = (X1+Y1)%10;   
  }
  if(X1+Y1==10){
  i1 = 1;   
  }
  else if(a>=10 && X1+Y1<10){
  i1 = X1 + Y1;
  }
  
  if(b>=10){
  X2 = b/10;
  Y2= b%10;
  }
  else if(b<10){
  i2=b;
  }
  if(b>=10 && X2+Y2>10){
  i2 = (X2+Y2)%10;   
  }
  if(X2+Y2==10){
  i2 = 1;   
  }
  else if(b>=10 && X2+Y2<10){
  i2 = X2 + Y2;
  }
  taxi=abs(A[i1][i2]);
  int j1=i1,k1=i1,l1=i1,m1=i1;
  int j2=i2,k2=i2,l2=i2,m2=i2;
   int max1=A[i1][i2], max2=A[i1][i2], max3=A[i1][i2], max4=A[i1][i2], maxi;
    while(j1<9&&j2<9){
        if(A[j1+1][j2+1]>=A[j1][j2]&&A[j1+1][j2+1]>max1){
            max1=A[j1+1][j2+1];
        }
        else if(A[j1+1][j2+1]<A[j1][j2]&&A[j1][j2]>=max1){
            max1=A[j1][j2];
        }
        else if(A[j1+1][j2+1]<A[j1][j2]&&A[j1][j2]<max1){
            max1=max1;
        }
        j1++;j2++;
    }
    
    while(k1>=1&&k2>=1){
        if(A[k1-1][k2-1]>=A[k1][k2]&&A[k1-1][k2-1]>max2){
            max2=A[k1-1][k2-1];
        }
        else if(A[k1-1][k2-1]<A[k1][k2]&&A[k1][k2]>=max2){
            max2=A[k1][k2];
        }
        else if(A[k1-1][k2-1]<A[k1][k2]&&A[k1][k2]<max2){
            max2=max2;
        }
        k1--;k2--;
    }
    
    while(l1<9&&l2>=1){
        if(A[l1+1][l2-1]>=A[l1][l2]&&A[l1+1][l2-1]>max3){
            max3=A[l1+1][l2-1];
        }
        else if(A[l1+1][l2-1]<A[l1][l2]&&A[l1][l2]>=max3){
            max3=A[l1][l2];
        }
        else if(A[l1+1][l2-1]<A[l1][l2]&&A[l1][l2]<max3){
            max3=max3;
        }
        l1++;l2--;
    }
    
    while(m1>=1&&m2<9){
        if(A[m1-1][m2+1]>=A[m1][m2]&&A[m1-1][m2+1]>max4){
            max4=A[m1-1][m2+1];
        }
        else if(A[m1-1][m2+1]<A[m1][m2]&&A[m1][m2]>=max4){
            max4=A[m1][m2];
        }
        else if(A[m1-1][m2+1]<A[m1][m2]&&A[m1][m2]<max4){
            max4=max4;
        }
        m1--;m2++;
    }
      
  if(max1>=max2){
      maxi=max1;
  }
  else{
      maxi=max2;
  }
   if(maxi>=max3){
      maxi=maxi;
  }
  else{
      maxi=max3;
  }
   if(maxi>=max4){
      maxi=maxi;
  }
  else{
      maxi=max4;
  }
  SW=abs(maxi);
  if(taxi>SW){
    EXP1 = ceil(EXP1 * 0.88);
    HP1 = ceil(HP1 * 0.9);
    EXP2 = ceil(EXP2 * 0.88);
    HP2 = ceil(HP2 * 0.9);
    result = A[i1][i2];
  }
  if(taxi<SW){
    EXP1 = ceil(EXP1 * 1.12);
    HP1 = ceil(HP1 * 1.1);
    EXP2 = ceil(EXP2 * 1.12);
    HP2 = ceil(HP2 * 1.1);
    result = maxi;
  }
  if(EXP1>600)
  {
      EXP1=600;
  }
  if(EXP1<0)
  {
      EXP1=0;
  }
  if(HP1>666)
  {
      HP1=666;
  }
  if(HP1<0)
  {
      HP1=0;
  }
  if(EXP2>600)
  {
      EXP2=600;
  }
  if(EXP2<0)
  {
      EXP2=0;
  }
  if(HP2>666)
  {
      HP2=666;
  }
  if(HP2<0)
  {
      HP2=0;
  }
  return result;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int emailLen = strchr(email, '@') - email; 
    const char specialChars[] = {'@', '#', '%', '$', '!'};
    int len = strlen(s);
    if (len < 8) return -1;
    if (len > 20) return -2;

    char se[101];
    strncpy(se, email, emailLen);
    se[emailLen] = '\0';

    const char *found = strstr(s, se);
    if (found != nullptr) return -(300 + (found - s));

    for (int i = 0; i < len - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }

    bool hasSpecialChar = false;
    for (int i = 0; i < len; ++i) {
        if (strchr(specialChars, s[i]) != nullptr) {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) return -5;

    for (int i = 0; i < len; ++i) {
        char c = s[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || strchr(specialChars, c))) {
            return i;
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    const int maxpwdlen = 50;
    char correctpwd[maxpwdlen];
    int maxCount = 0;
    int maxLength = 0;
    int correctPos = -1;

    for (int i = 0; i < num_pwds; ++i) {
        const char* currentPassword = arr_pwds[i];
        int currentCount = 0;

        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(currentPassword, arr_pwds[j]) == 0) {
                currentCount++;
            }
        }

        if (currentCount > maxCount || (currentCount == maxCount && strlen(currentPassword) > maxLength)) {
            maxCount = currentCount;
            maxLength = strlen(currentPassword);
            strcpy(correctpwd, currentPassword);
            correctPos = i;
        }
    }
    return correctPos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////