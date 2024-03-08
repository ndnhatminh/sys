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

int limitHP(int HP){
	if (HP>666){
		return 666;}
	else if (HP <0){
		return 0;}
	 else return HP;}

int limitEXP(int EXP){
	if (EXP > 600){
		return 600;}
	else if (EXP < 0){
		return 0;}
	else {return EXP;}}

int limitM(int M){
	if (M > 3000){
		return 3000;}
	else if (M < 0){
		return 0;}
	else return M;}

int limitE(int E){
	if (E<0 || E>99){
		return -99;}
	else return E;}
	
int findsquarenum(int S){
	int lower = sqrt(S);
	int upper = lower +1;
	
	if ((S-lower*lower)<=(upper*upper-S)){
		return lower*lower;}
	else return upper*upper;}

int meet(int a[10][10],int E3,int & Row,int & Col){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            a[i][j]=(E3*j+i*2)*(i-j);
            if (a[i][j]>E3*2){
				Row++;}
            if (a[i][j]<-E3){
				Col++;}
        }
    }
    while (Row>9){
        Row=Row/10+Row%10;
    }
    while (Col>9){
        Col=Col/10+Col%10;
    }
    return a[Row][Col];
}

int absoluteValue(int x) {
    return (x < 0) ? -x : x;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1){
    // TODO: Complete this function
    float fexp2= static_cast<float>(exp2);
    float fe1= static_cast<float>(e1);
    limitE(fe1);
    if (fe1==0){
    	fexp2+=29;}
    if (fe1==1){
    	fexp2+=45;}
    if (fe1==2){
    	fexp2+=75;}
    if (fe1==3){
    	fexp2+=149;}
    int D = e1*3+exp1*7;
    if ((fe1==0 || fe1==1 || fe1==2 || fe1==3) && D%2==0){
    	exp1+=D/200;
		exp1= ceil(exp1);}
    if ((fe1==0 || fe1==1 || fe1==2 || fe1==3) && D%2!=0){
		exp1-=D/100;
		exp1= ceil(exp1);}
	if (e1 >=4 && e1<=99){
    	if (fe1 >= 4 && fe1 <= 19){
    		fexp2+=fe1/4+19;
			}
    	else if ( fe1 >= 20 && fe1 <= 49){
    		fexp2+=fe1/9+21;
			}
    	else if ( fe1>= 50 && fe1 <= 65){
    		fexp2+=e1/16+17;
			}
    	else if (fe1 >= 66 && fe1 <= 79){
    		fexp2+=fe1/4+19;
    		if (fexp2>200){
    			fexp2+=fe1/9+21;
				}
			}
    	else if ( fe1>= 80 && fe1<= 99){
    		fexp2+=fe1/4+fe1/9+40;
    		if (fexp2>400){
    			fexp2+=fe1/16+17;
				fexp2=fexp2*1.15;
				}
			}
	exp1-=e1;}
	exp2=ceil(fexp2);
	exp1=limitEXP(exp1);
	exp2=limitEXP(exp2);
    
    return exp1 + exp2;
}		



// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    int S, spent, N;
    S = findsquarenum(EXP1);
    spent=0;
    float P1, P2, P3, avr;
    float fHP1= static_cast<float>(HP1);
    float fEXP1= static_cast<float>(EXP1);
    if (fEXP1 >= S){
    	P1=100;}
    else {P1=(fEXP1/S+80)/123*100;}
    int limit=M1/2;
    if (E2%2!=0){
    	for (int i=0;i<10;i++){
			if (fHP1 < 200){
				fHP1*=1.3;
				fHP1=ceil(fHP1);
				spent+=150;}
			else { 
				fHP1*=1.1;
				spent+=70;
				fHP1=ceil(fHP1);}
			if (spent > limit)break;
			if (fEXP1 < 400){
				spent+=200;}
			else {spent+=120;}
				fEXP1*=1.13;
				fEXP1=ceil(fEXP1);
			if (spent > limit)break;
			if (fEXP1 < 300){
				spent+=100;}
			else { spent+=120;}
			fEXP1*=0.9;
			fEXP1=ceil(fEXP1);
			if (spent > limit)break;}
	}
	else{
		if (M1>0){
			if (fHP1 < 200){
				fHP1*=1.3;
				fHP1=ceil(fHP1);
				spent+=150;}
			else { 
				fHP1*=1.1;
				spent+=70;
				fHP1=ceil(fHP1);}}
		if (M1>0){
			if (fEXP1 < 400){
				spent+=200;}
			else {spent+=120;}
				fEXP1*=1.13;
				fEXP1=ceil(fEXP1);}
		if (M1>0){
			if (fEXP1 < 300){
				spent+=100;}
			else { spent+=120;}
			fEXP1*=0.9;
			fEXP1=ceil(fEXP1);}}
	M1-=spent;
	M1=limitM(M1);
	fHP1*=0.83;
	fEXP1*=1.17;
	fHP1=ceil(fHP1);
	fEXP1*=ceil(fEXP1);
	
	if (fEXP1>S){
		P2=100;}
    else {P2=(fEXP1/S+80)/123*100;}
    
    int P[10]={32,47,28,79,100,50,22,83,64,11};
	if (E2<10){
		P3=P[E2];}
	else {
		N=0;
		N= N + E2/10 +E2%10;
		N= N%10;
		P3=P[N];}

	avr=(P1+P2+P3)/3;
	avr=ceil(avr);
	
	if (avr==100){
		fEXP1*=0.75;}
	else if (avr<50){
		fHP1*=0.85;
		fEXP1*=1.15;}
	else {
		fHP1*=0.9;
		fEXP1*=1.2;}
	EXP1=ceil(fEXP1);
	HP1=ceil(fHP1);
	HP1=limitHP(HP1);
	EXP1=limitEXP(EXP1);
	
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    int row=0,col=0;
    int a[10][10];
    int max1, max2;
    max1=meet(a,E3,row,col);
    max2=max1;
    for (int i=0;row-i>=0;i++){
        if (col-i<0){
			break;}
        if (a[row-i][col-i]>max1){
			max1=a[row-i][col-i];}
    }
    for (int i=0;col+i<10;i++){
        if (row+i>9){
			break;}
        if (a[row+i][col+i]>max1){
			max1=a[row+i][col+i];}
    }
    for (int i=0;row+i<10;i++){
        if (col-i<0){
			break;}
        if (a[row+i][col-i]>max1){
			max1=a[row+i][col-i];}
    }
    for (int i=0;col+i<10;i++){
        if (row-i<0){
			break;}
        if (a[row-i][col+1]>max1){
			max1=a[row-i][col+i];}
    }
    float fEXP1, fEXP2, fHP1, fHP2;
    fEXP1=EXP1;
    fEXP2=EXP2;
    fHP1=HP1;
    fHP2=HP2;
    if (absoluteValue(max1)<=absoluteValue(max2)){
    	fEXP1*=0.88;
		fEXP2*=0.88;
		fHP1*=0.9;
		fHP2*=0.9;}
	else {
		fEXP1*=1.12;
		fEXP2*=1.12;
		fHP1*=1.1;
		fHP2*=1.1;}
	EXP1=ceil(fEXP1);
	EXP2=ceil(fEXP2);
	HP1=ceil(fHP1);
	HP2=ceil(fHP2);
	EXP1=limitEXP(EXP1);
	EXP2=limitEXP(EXP2);
	HP1=limitHP(HP1);
	HP2=limitHP(HP2);		
			
    return max2;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
	string se;
	string emailstr(email);
	emailstr.resize(100);
	string sstr(s);
	size_t RoundA=emailstr.find('@');
	if (RoundA != string::npos){
		se=emailstr.substr(0,RoundA);}
	if (sstr.length() < 8){
		return -1;}
	if (sstr.length() > 20){
		return -2;}
	size_t searchse= sstr.find(se);
	if (searchse != string::npos){
		return -(300+searchse);}
	for (int i=0; i < sstr.length(); i++){
		if (sstr[i] == sstr[i+1] && sstr[i+1] == sstr[i+2]){
			return -(400+i);}}
	bool specialchar= false;
	for ( char c : sstr ){
		if (!isalnum(c) && c!= '@' && c!='#' && c!='%' && c!='$' && c!='!'){
			specialchar = true;
			break;}
		if (!specialchar){
			return -5;}
	for (size_t i=0; i< sstr.length(); i++){
		char a=s[i];
		if (!(isalnum(a) || a=='@' || a=='#' || a=='$' || a=='%' || a=='!')){
			return i;}}}
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string password[30];
    int frequency[30];
    password[0]=arr_pwds[0];
    int x,y;
    y=1;
    for (int i=1; i<num_pwds; i++){
    	x=0;
    	for (int j=0; j<y; j++){
    		if (arr_pwds[i]!=password[j]){
    			x+=1;
			}
			else break;
		}
		if (x==y){
			password[y]=arr_pwds[i];
			y+=1;
		}
	}
	for (int i=0;i<y;i++){
		frequency[i]=0;
    	for (int j=0; j<num_pwds;j++){
    		if (password[i]==arr_pwds[j]){
    			frequency[i]+=1;}
		}
	}
    int max=frequency[0];
    for (int i=1; i<y; i++){
    	if (frequency[i]>max){
    		max = frequency[i];
		}
	}
	int index[30];
	int z=0;
	int k=0;
	for (int i=0; i<y; i++){
		if (max==frequency[i]){
			index[z]=0;
			index[z]=i;
			z+=1;
			k+=1;
		}
	}
	int maxlength = password[index[0]].length();
	int position=0;
	if (k>1){
		for (int i=0; i<k; i++){
			if (maxlength<password[index[i]].length()){
				maxlength=password[index[i]].length();
				position=i;
			}
		}
	}
    int a;
    for (int i=0; i<num_pwds;i++){
    	if (password[index[position]]==arr_pwds[i]){
    	a=i;
    	break;}
	}
    return a;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
