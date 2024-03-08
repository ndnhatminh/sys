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
   if (exp1<0){
        exp1=0;
    }
    else if(exp1>600){
        exp1=600;
    }
    if (exp2<0)
    {
        exp2=0;
    }
    else if(exp2>600)
    {
        exp2=600;
    }
    if((e1>99) || (e1<0))
    {
        return -99;
    }
    else if((e1>=0) && (e1<=3) )
    {
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
        exp2=exp2+29+45+75;
    }
    int D=e1*3+exp1*7;
    if(D%2==1)
    {
        exp1=ceil(exp1-D/100.0);
    }
    else
    {
        exp1=ceil(exp1+D/200.0);
    }
}
else
{
    if((e1>=4) && (e1<=19))
    {
        exp2=ceil(exp2+(e1/4.0+19.0));
    }
    else if((e1>=20) && (e1<=49))
    {
        exp2=ceil(exp2+(e1/9.0+21.0));
    
    }
    else if((e1>=50) && (e1<=65))
    {
        exp2=ceil(exp2+(e1/16.0+17.0));
    }
    else if((e1>=66) && (e1<=79))
    {
        exp2=ceil(exp2+(e1/4.0+19.0));
        if(exp2>200)
        {
            exp2=ceil(exp2+(e1/9.0+21.0));  
        }
    }
    else if((e1>=80) && (e1<=99))
    {
        exp2=ceil(exp2+(e1/4.0+19.0));
        exp2=ceil(exp2+(e1/9.0+21.0));
        if(exp2>400)
        {
            exp2=ceil(exp2+(e1/16.0+17.0));
            exp2=ceil(exp2+0.15*exp2);
        }
        
    
    }
    exp1=exp1-e1;
   if (exp1<0){
        exp1=0;
    }
    else if(exp1>600){
        exp1=600;
    }
    if (exp2<0)
    {
        exp2=0;
    }
    else if(exp2>600)
    {
        exp2=600;
    }
}
    return exp1 + exp2;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {

    float P;
    float P1;
    float P2;
    if (HP1<0)
	{
    	HP1=0;
	}
	else if(HP1>600)
	{
		HP1=666;
	}
	if (EXP1<0)
	{
    	EXP1=0;
	}
	else if(EXP1>600)
	{
		EXP1=600;
	}
	if (M1<0)
	{
    	M1=0;
	}
	else if(M1>3000)
	{
		M1=3000;
	}
	if((E2>99) || (E2<0))
	{
		return -99;
	}
//way1
    float g = sqrt(EXP1);
    int G=round(g);
    int S=G*G;
    if(EXP1>=S)
	{
        P1=100;
    }
    else
	{
        P1=((EXP1/S)+80.0)/123.0;
    }
//way2
int m=0;
int n=0.5*M1;

if((E2%2)==1)
{
	while(true)
	{
        //case1
	    if(HP1<200)
        {
	        HP1=ceil(HP1*1.3);
	        M1=M1-150;
	        m+=150;	
	    }
	    else
	    {
		    HP1=ceil(HP1*1.1);
		    M1=M1-70;
		    m+=70;
	    }
        
	    if(m>n)
	    {
		    break;
	HP1 = ceil(HP1 * 0.83);
    EXP1 = ceil(EXP1 * 1.17);
	    }
	    if (HP1<0)
	    {
    	    HP1=0;
	    }
	    else if(HP1>666)
	    {
		    HP1=666;
	    }
		if (M1<0){
    	    M1=0;
	    }
	    else if(M1>3000)
	    {
		    M1=3000;
	    }

        //task 2
	    if(EXP1<400)
	    {
		    M1=M1-200;
		    m+=200;
		    EXP1=ceil(1.13*EXP1);
	    }
	    else
	    {
		    M1=M1-120;
		    m+=120;
		    EXP1=ceil(1.13*EXP1);
	    }
		if(m>n)
	    {
		    break;
		HP1 = ceil(HP1 * 0.83);
    	EXP1 = ceil(EXP1 * 1.17);
	    }
	    if (HP1<0)
	    {
    	    HP1=0;
	    }
	    else if(HP1>666)
	    {
	    	HP1=666;
	    }
		if (M1<0){
    	    M1=0;
	    }
	    else if(M1>3000)
	    {
		    M1=3000;
	    }

        //task 3
	    if(EXP1<300)
    	{
		    M1=M1-100;
		    m+=100;
		    EXP1=ceil(0.9*EXP1);
	    }
	    else
	    {
		    M1=M1-120;
		    m+=120;
		    EXP1=ceil(0.9*EXP1);
	    }
	    if(m>n)
	    {
		    break;
    HP1 = ceil(HP1 * 0.83);
    EXP1 = ceil(EXP1 * 1.17);
	    }
	    if (HP1<0)
	    {
        	HP1=0;
	    }
	    else if(HP1>666)
	    {
		    HP1=666;
        }   
		if (M1<0){
    	    M1=0;
	    }
	    else if(M1>3000)
	    {
		    M1=3000;
	    }
	}
	if (EXP1<0){
    	EXP1=0;
	}
	else if(EXP1>600)
	{
		EXP1=600;
	}
}
else
{
    //task 1
    if(HP1<200)
	{
	    HP1=ceil(HP1*1.3);
	    M1=M1-150;
	    m+=150;	
	}
	else
	{
		HP1=ceil(HP1*1.1);
		M1=M1-70;
		m+=70;
	}
    
	if (M1<0){
    	M1=0;
	}
	else if(M1>3000)
	{
		M1=3000;
	}
	 if (HP1<0)
	{
    	HP1=0;
	}
	else if(HP1>666)
	{
		HP1=666;
	}
	
	if(M1>0)
	{

	    if(EXP1<400)
	    {
		    M1=M1-200;
		    m+=200;
		    EXP1=ceil(1.13*EXP1);
	    }
	    else
	    {
	    	M1=M1-120;
		    m+=120;
		    EXP1=ceil(1.13*EXP1);
	    }	
	}
    
	if (M1<0){
    	M1=0;
	}
	else if(M1>3000)
	{
		M1=3000;
	}
	if (HP1<0)
	{
    	HP1=0;
	}
	else if(HP1>666)
	{
		HP1=666;
	}
	
	if(M1>0)
	{   
	//task 3
	    if(EXP1<300)
	    {
	    	M1=M1-100;
		    m+=100;
		    EXP1=ceil(0.9*EXP1);
	    }
	    else
	    {
		    M1=M1-120;
		    m+=120;
		    EXP1=ceil(0.9*EXP1);
	    }	
	}
    if (M1<0){
    	M1=0;
	}
	else if(M1>3000)
	{
		M1=3000;
	}
	 if (HP1<0)
	{
    	HP1=0;
	}
	else if(HP1>666)
	{
		HP1=666;
	}

    HP1 = ceil(HP1 * 0.83);
    EXP1 = ceil(EXP1 * 1.17);
    
	if (EXP1<0){
    	EXP1=0;
	}
	else if(EXP1>600)
	{
		EXP1=600;
	}
}

	
    float k = sqrt(EXP1);
    int K=round(k);
    int S1=K*K;
    if(EXP1>=S1){
        P2=100;
    }
    else{
        P2=((EXP1/S)+80.0)/123.0;
    }
//way3
    int i;
    int c;
    int v;
    int I;
    int a[10]={32,47,28,79,100,50,22,83,64,11};
    if((E2>=0) && (E2<=9))
	{
		 i=E2;
	}
	else
	{
	c=E2/10;
    v=E2%10;
    I=c+v;
    i=I%10;
	}
    
    int P3= a[i];
    if((P1==100) && (P2==100) && (P3==100))
    {
    	EXP1=0.75*EXP1;
	}
	else
	{
        P=(P1+P2+P3)/3.0;
    
        if(P<50)
        {
    	    HP1=ceil(0.85*HP1);
    	    EXP1=ceil(1.15*EXP1);
	    }
	    else
	    {
		    HP1=ceil(0.9*HP1);
		    EXP1=ceil(1.2*EXP1);
	    }
	    if (EXP1<0){
    	    EXP1=0;
	    }
	    else if(EXP1>600)
	    {
		    EXP1=600;
	    }
    }
    return HP1 + EXP1 + M1;
}
// Task 3

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if((E3>=0 )&& (E3<=99)){
    E3=E3;
    }
    else{
    return -99;
    }
        if (HP1<0){
        HP1=0;
    }
    else if(HP1> 666)
    {
        HP1=666;
    }
    if (HP2<0){
        HP2=0;
    }
    else if(HP2> 666)
    {
        HP2=666;
    }
    if (EXP1<0){
        EXP1=0;
    }
    else if(EXP1> 600)
    {
        EXP1=600;
    }
    if (EXP2<0){
        EXP2=0;
    }
    else if(EXP2> 600)
    {
        EXP2=600;
    }
    int i;
    int j;
    int timx=0;
    int timy=0;


    int b[10][10];
    for( i=0; i<=9; i++){
        for( j=0;j<=9; j++){
         b[i][j]=((E3*j)+(i*2))*(i-j);

        if(b[i][j]> E3*2){
            timx=timx+1;
        }
        else if(b[i][j]<-E3){
            timy=timy+1;
        }
        }

    }
    
    while (timx>=10)
    {
        timx=(timx/10)+(timx%10);
    }
    while (timy>=10)
    {
        timy=(timy/10)+(timy%10);
    }
	int xe=b[timx][timy];
	int v;
	int maxo=b[timx][timy];
		for(v=0; ;v++)
	{
		if((timx+v)>=0 && (timx+v)<=9 && (timy+v)>=0 && (timy+v)<=9)
		{
			maxo=fmax(maxo,b[timx+v][timy+v]);
		}
		else
		{
			break;
		}
	}
	for(v=0; ;v++)
	{
		if((timx-v)>=0 && (timx-v)<10 && (timy-v)>=0 && (timy-v)<10)
		{
			maxo=fmax(maxo,b[timx-v][timy-v]);
		}
		else
		{
			break;
		}
	}
	for(v=0; ;v++)
	{
		if((timx+v)>=0 && (timx+v)<10 && (timy-v)>=0 && (timy-v)<10)
		{
			maxo=fmax(maxo,b[timx+v][timy-v]);
		}
		else
		{
			break;
		}
	}
	for(v=0; ;v++)
	{
		if((timx-v)>=0 && (timx-v)<10 && (timy+v)>=0 && (timy+v)<10)
		{
			maxo=fmax(maxo,b[timx-v][timy-v]);
		}
		else
		{
			break;
		}
	}
	int max;
	if(maxo<abs(b[timx][timy]))
	{
		EXP1=ceil(0.88*EXP1);
		EXP2=ceil(0.88*EXP2);
		HP1=ceil(0.9*HP1);
		HP2=ceil(0.9*HP2);
		max=b[timx][timy];
	}
	else
	{
		EXP1=ceil(1.12*EXP1);
		EXP2=ceil(1.12*EXP2);
		HP1=ceil(1.1*HP1);
		HP2=ceil(1.1*HP2);
		max=maxo;
	}
	if (HP1<0)
	{
    	HP1=0;
	}
	else if(HP1>666)
	{
		HP1=666;
	}
	if (EXP1<0){
    	EXP1=0;
	}
	else if(EXP1>600)
	{
		EXP1=600;
	}
	
	if (HP2<0)
	{
    	HP2=0;
	}
	else if(HP2>666)
	{
		HP2=666;
	}
	if (EXP2<0){
    	EXP2=0;
	}
	else if(EXP2>600)
	{
		EXP2=600;
	}
    return max;
}


// Task 4
int checkPassword(const char * s, const char * email) {
	int m = strlen(email);
	if (m > 100) {
        return -1;
    }
    const char* at = strchr(email,'@');
    if (at==nullptr ) {
        return -1; // not find @
    }
    int seLength = at - email;
    char se[98];//email=se@k
    strncpy(se, email, seLength);
    se[seLength] = '\0'; //finish with nullptr
    int n = strlen(s);
    if (n < 8) {
        return -1;
    } else if (n > 20) {
        return -2;
    }
    const char* found = strstr(s, se);
    if (found != nullptr) {
    	int sei=(found - s);
        return -(300 + sei);
    }
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == s[i + 1]&& s[i]== s[i + 2]) {
            return -(400 + i);
            break;
        }
    }
    bool hasSpecialChar = false;
    for (int i = 0; i < n; i++) {
        if (strchr("@#%$!", s[i]) != nullptr) {
            hasSpecialChar = true;
        } else if (!isalnum(s[i])) {
            
            return -5;
        }
    }

    if (!hasSpecialChar) {

        return -5;
    }
    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxFrequency = 0;
    int maxLength = 0;
    const char *longestPwd = NULL;
    int pwdFrequency[num_pwds];
    int pwdLength[num_pwds];
    memset(pwdFrequency, 0, sizeof(pwdFrequency));
    memset(pwdLength, 0, sizeof(pwdLength));
    for(int i = 0; i < num_pwds; i++){
        pwdLength[i] = strlen(arr_pwds[i]);
        for(int j = 0; j < num_pwds; j++){
            if(strcmp(arr_pwds[i], arr_pwds[j]) == 0){
                pwdFrequency[i]++;
            }
        }
        if(pwdFrequency[i] > maxFrequency || 
          (pwdFrequency[i] == maxFrequency && pwdLength[i] > maxLength)){
            maxFrequency = pwdFrequency[i];
            maxLength = pwdLength[i];
            longestPwd = arr_pwds[i];
        }
    }
    for(int i = 0; i < num_pwds; i++){
        if(longestPwd == arr_pwds[i]){
            return i;
        }
    }

    return -1;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////



