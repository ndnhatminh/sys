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

bool check(int e, int d, int u){
	if((e<d)||(e>u))
		return false;
	return true;
}

int calibrate(double a){
	if(a<0)
		return 0;
	double phannguyen,phantp;
	phantp = modf(a, &phannguyen);
	if(phantp!=0)
		return phannguyen+1;
	else
		return phannguyen;
}

int make(double a, int b){
	int x=calibrate(a);
	switch (b){
		case cexp:
			if(x>600)
				return 600;
		case chp:
			if(x>666)
				return 666;
		case cm:
			if(x>3000)
				return 3000;
	}
	return x;
}

bool contains(const std::string& str, char targetChar) {
    return str.find(targetChar) != std::string::npos;
}

int FF(const string arr[], int size, const string& target) {
    int freq=0;
    for (int i=0;i<size;i++){
        if (arr[i]==target){
            freq++;
        }
    }
    return freq;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(check(e1,0,99)==false)
    	return -99;
    	
    exp2=make(exp2,cexp);
    exp1=make(exp1,cexp);
	if(e1<4){
		double D=3*e1+7*exp1;
		switch (e1){
			case 0:
				exp2=make(exp2+29,cexp);
				break;
			case 1:
				exp2=make(exp2+45,cexp);
				break;
			case 2:
				exp2=make(exp2+75,cexp);
				break;
			case 3:
				exp2=make(exp2+149,cexp);
				break;
		}
		if (int(D)%2==0)
			exp1=make(exp1+(D/200),cexp);
		else
			exp1=make(exp1-(D/100),cexp);
		return exp1 + exp2;
	}
	exp1=make(exp1-e1,cexp);
	if(e1<20){
		exp2=make(exp2+double(e1)/4+19,cexp);
		return exp2+exp1;
	}
	if((e1>19)&&(e1<50)){
		exp2=make(exp2+double(e1)/9+21,cexp);
		return exp2+exp1;
	}
	if((e1>49)&&(e1<66)){
		exp2=make(exp2+double(e1)/16+17,cexp);
		return exp2+exp1;
	}
	if((e1>65)&&(e1<80)){
		exp2=make(exp2+double(e1)/4+19,cexp);	
		if (exp2>200)
			exp2=make(exp2+double(e1)/9+21,cexp);
		return exp2+exp1;
	}
	if(e1>79){
		exp2=make(exp2+double(e1)/4+19,cexp);	
		exp2=make(exp2+double(e1)/9+21,cexp);
		if (exp2>400){
			exp2=make(exp2+double(e1)/16+17,cexp);
			exp2=make(exp2+exp2*0.15,cexp);
		}
		return exp2+exp1;
	}
	return 0;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    
    if(check(E2,0,99)==false)
    	return -99;
    //EXP2=make(EXP2,cexp);
    EXP1=make(EXP1,cexp);
    //HP2=make(HP2,chp);
    HP1=make(HP1,chp);
    //M2=make(M2,cm);
    M1=make(M1,cm);
    
    //path1&3
	int temp=trunc(sqrt(EXP1));
	double P1,P2,P3,prop[10]={0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11};
	P3=prop[(E2/10+(E2%10))%10];
	//return P3;
	if (((temp+1)*(temp+1)-EXP1)<(EXP1-(temp*temp)))
		P1=(double(EXP1)/((temp+1)*(temp+1))+80)/123;
	else
		P1=1;
		
	//path2
	if((E2%2)==1){
		int used=0;
		double half=M1/2;
		//return half;
		bool check=true;
		while (used<=half){
			if(M1==0)
                break;
			//1st encounter
			if(HP1<200){
				HP1=make(HP1+HP1*0.3,chp);
				M1=make(M1-150,cm);
				used+=150;
				if ((M1==0) || (used > half))
					break;
			}
			else {
				HP1=make(HP1*0.1+HP1,chp);
				M1=make(M1-70,cm);
				used+=70;
				if ((M1==0) || (used > half))
					break;
			}
			//2nd encounter
			if(EXP1<400){
				used+=200;
				M1=make(M1-200,cm);
				EXP1=make(EXP1+EXP1*0.13,cexp);
				if ((M1==0) || (used > half))
					break;
			}
			else {
				used+=120;
				M1=make(M1-120,cm);
				EXP1=make(EXP1+EXP1*0.13,cexp);
				if ((M1==0) || (used > half))
					break;
			}
			//3rd encounter
			if(EXP1<300){
				used+=100;
				M1=make(M1-100,cm);
				EXP1=make(EXP1-EXP1*0.1,cexp);
				if ((M1==0) || (used > half))
					break;
			}
			else {
				used+=120;
				M1=make(M1-120,cm);
				EXP1=make(EXP1-EXP1*0.1,cexp);
				if ((M1==0) || (used > half))
					break;
			}
		}
	}
	else {
		//1st encounter
		if (M1==0)
			goto end;
		if(HP1<200){
			HP1=make(HP1+HP1*0.3,chp);
			M1=make(M1-150,cm);
			if (M1==0)
				goto end;
		}
		else {
			HP1=make(HP1*0.1+HP1,chp);
			M1=make(M1-70,cm);
			if (M1==0)
				goto end;
		}
		//2nd encounter
		if(EXP1<400){
			M1=make(M1-200,cm);
			EXP1=make(EXP1+EXP1*0.13,cexp);
			if (M1==0)
				goto end;
		}
		else {
			M1=make(M1-120,cm);
			EXP1=make(EXP1+EXP1*0.13,cexp);
			if (M1==0)
				goto end;
		}
		//3rd encounter
		if(EXP1<300){
			M1=make(M1-100,cm);
			EXP1=make(EXP1-EXP1*0.1,cexp);
			if (M1==0)
				goto end;
		}
		else {
			M1=make(M1-120,cm);
			EXP1=make(EXP1-EXP1*0.1,cexp);
			if (M1==0)
				goto end;
			}
		end:
			;
	}
	HP1=make(HP1-HP1*0.17,chp);
	EXP1=make(EXP1+EXP1*0.17,cexp);
	temp=trunc(sqrt(EXP1));
	//return EXP1;
	if (((temp+1)*(temp+1)-EXP1)<(EXP1-(temp*temp)))
		P2=(double(EXP1)/((temp+1)*(temp+1))+80)/123;
	else
		P2=1;
	//summary
	double sumrate=(P1+P2+P3)/3;
	if(sumrate==1)
		EXP1=make(EXP1-EXP1*0.25,cexp);
	if (sumrate<0.5){
		EXP1=make(EXP1+EXP1*0.15,cexp);
		HP1=make(HP1-HP1*0.15,chp);
	}
	if(sumrate>=0.5 && sumrate<1){
		EXP1=make(EXP1+EXP1*0.2,cexp);
		HP1=make(HP1-HP1*0.1,chp);
	}
	return M1+EXP1+HP1;
	//return P2;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(check(E3,0,99)==false)
    	return -99;
    	
    EXP2=make(EXP2,cexp);
    EXP1=make(EXP1,cexp);
    HP2=make(HP2,chp);
    HP1=make(HP1,chp);
    //M2=make(M2,cm);
    //M1=make(M1,cm);
    	
    int pos=0,neg=0,arrcar[10][10]={0},maxr[19]={0},maxl[19]={0},pdet;
    
    for(int i=0;i<=9;i++){
    	for(int j=0;j<=9;j++){
    		arrcar[i][j]=(i-j)*((E3*j)+(i*2));
    		if(arrcar[i][j]>2*E3)
    			pos++;
    		if(arrcar[i][j]<-E3)
    			neg++;	
    		//right diag max val
    		if(arrcar[i][j]>maxr[i+j])
    			maxr[i+j]=arrcar[i][j];
    		//left diag max val
    		if(arrcar[i][j]>maxl[i-j+9])
    			maxl[i-j+9]=arrcar[i][j];
		}
	}
	 	
	while(pos>9)
		pos=pos%10+pos/10;
	
	while(neg>9)
		neg=neg%10+neg/10;
	
	int temp1=pos+neg,temp2=pos-neg+9;
	
	if(maxr[temp1]>maxl[temp2])
		pdet=maxr[temp1];
	else
		pdet=maxl[temp2];
    
    if(pdet<abs(arrcar[pos][neg])){
    	EXP1=make(EXP1-EXP1*0.12,cexp);
    	EXP2=make(EXP2-EXP2*0.12,cexp);
    	HP1=make(HP1-HP1*0.1,chp);
    	HP2=make(HP2-HP2*0.1,chp);
    	return arrcar[pos][neg];
	}
	else {
		EXP1=make(EXP1+EXP1*0.12,cexp);
    	EXP2=make(EXP2+EXP2*0.12,cexp);
    	HP1=make(HP1*0.1+HP1,chp);
    	HP2=make(HP2*0.1+HP2,chp);
    	return pdet;
	}
    
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function	
	
	string se;
	bool spec=false;
	int len = strlen(email);
	string mail=email,pass=s,valid="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM!@#$%1234567890";
	
	for(int i=0;i<len;i++)
		if(mail[i]=='@')
			se=mail.substr(0,i);
			
	int plen=pass.length();
	
	size_t isFound = pass.find(se);
	
	if(plen<8)
		return -1;
	if(plen>20)
		return -2;
		
	if(strstr(pass.c_str(),se.c_str())){
   		size_t n = pass.find(se);
   		return -300-n;
	}
	
	for(int i=0;i<(plen-2);i++){
		string t1=pass.substr(i,1),t2=pass.substr(i+1,1),t3=pass.substr(i+2,1);
		if((t1==t2)&&(t1==t3))
			return -400-i;
	}
	for(int i=0;i<plen;i++)
		if(pass[i]=='!' || pass[i]=='@' || pass[i]=='#' || pass[i]=='$' || pass[i]=='%'){
			spec=true;
			break;
		}
	if (!spec)
		return -5;
	
	for(int i=0;i<plen;i++){
		char tmp=pass[i];
		if (!contains(valid,pass[i]))
			return i;
	}
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
	
	string cop[num_pwds];
	int most=0,mark=0,corlen=0,count[num_pwds];
	
	//coppy array
	for(int i=0;i<num_pwds;i++){
		cop[i]=arr_pwds[i];
	}
	
	//find the highest frequency of strings
	for(int i=0;i<num_pwds;i++){
		count[i]=FF(cop,num_pwds,cop[i]);
		if(count[i]>most)
			most=count[i];
	}
	
	for(int i=0;i<num_pwds;i++){
		if((count[i]==most) && ((cop[i].length())>corlen)){
			mark=i;
			corlen=cop[i].length();
		}
	}
    return mark;
	
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
