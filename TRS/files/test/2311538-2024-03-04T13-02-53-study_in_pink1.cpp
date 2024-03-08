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



void checkHP(int &HP){
	if(HP<0){
		HP=0;
	}else{
		if(HP>666){
			HP=666;
		}
	}
	return;
}

void checkEXP(int &EXP){
	if(EXP<0){
		EXP=0;
	}else{
		if(EXP>600){
			EXP=600;
		}
	}
	return;
}

void checkM(int &M){
	if(M<0){
		M=0;
	}else{
		if(M>3000){
			M=3000;
		}
	}
	return;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1<0||e1>99){
    	return -99;
	}
    if(e1>=0&&e1<=3){
if(e1==0){
exp2+=29;
checkEXP(exp2);
}else{
if(e1==1){
exp2+=45;
checkEXP(exp2);
}else{
if(e1==2){
exp2+=75;
checkEXP(exp2);
}else{
exp2=exp2+29+45+75;
checkEXP(exp2);
}
}
}
int D=e1*3+exp1*7;
if(D%2==0){
exp1=ceil(exp1+D/200.0);
checkEXP(exp1);
}else{
exp1=ceil(exp1-D/100.0);
checkEXP(exp1);	
}
}else{
	/////////////
if(4<=e1&&e1<=99){
if(4<=e1&&e1<=19){
exp2=ceil(exp2+19+e1/4.0);
checkEXP(exp2);
}else{
if(20<=e1&&e1<=49){
exp2=ceil(exp2+21+e1/9.0);
checkEXP(exp2);
}else{
if(50<=e1&&e1<=65){
exp2=ceil(exp2+17+e1/16.0);
checkEXP(exp2);
}else{
if(66<=e1&&e1<=79){
exp2=ceil(exp2+19+e1/4.0);
checkEXP(exp2);
if(exp2>200){
exp2=ceil(exp2+21+e1/9.0);
checkEXP(exp2);
}
}else{
if(80<=e1&&e1<=99){
exp2=ceil(exp2+19+e1/4.0);
checkEXP(exp2);
exp2=ceil(exp2+21+e1/9.0);
checkEXP(exp2);
if(exp2>400){
exp2=ceil(exp2+17+e1/16.0);
checkEXP(exp2);
exp2=ceil(exp2*1.15);
checkEXP(exp2);
}
}}}}}
exp1=exp1-e1;
checkEXP(exp1);
}else{
return -99;
}
}
///////////////// viet ham check rieng
checkEXP(exp1);
checkEXP(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2<0||E2>99){
    	return -99;
	}
// con duong 1
double P1,P2,P3;
int S1;
if(sqrt(EXP1*1.0)==(int)sqrt(EXP1)){
P1=100;
}else{
int can1=sqrt(EXP1);
if(pow(can1+1,2)-EXP1>=-pow(can1,2)+EXP1){
P1=100;
}else{
	S1=pow(can1+1,2);
P1=100*(EXP1/(S1*1.0)+80)/123.0;
}
}
//con duong 2
int m=0;
int m1=ceil(M1*0.5);
if(E2%2==0){
if(M1>0){
if(HP1<200){
HP1=ceil(HP1+HP1*0.3);
M1-=150;
checkHP(HP1);
checkM(M1);
}else{
HP1=ceil(HP1+HP1*0.1);
M1-=70;
checkHP(HP1);
checkM(M1);
}
}else{
M1=0;
}

if(M1>0){
if(EXP1<400){
EXP1=ceil(EXP1*1.13);
M1-=200;
checkEXP(EXP1);
checkM(M1);
}else{
EXP1=ceil(EXP1*1.13);
M1-=120;
checkEXP(EXP1);
checkM(M1);
}
}else{
M1=0;
}

if(M1>0){
if(EXP1<300){
EXP1=ceil(EXP1*0.9);
M1-=100;
checkEXP(EXP1);
checkM(M1);
}else{
EXP1=ceil(EXP1*0.9);
M1-=120;
checkEXP(EXP1);
checkM(M1);
}
}else{
M1=0;
}
}else{
//E2 le:
while(m<=m1){
if(M1>0){
	if(m<=m1){
if(HP1<200){
HP1=ceil(HP1+HP1*0.3);
m+=150;
M1-=150;
checkHP(HP1);
checkM(M1);
}else{
HP1=ceil(HP1+HP1*0.1);
m+=70;
M1-=70;
checkHP(HP1);
checkM(M1);
}
}
}else{
M1=0;
}

if(M1>0){
	if(m<=m1){
if(EXP1<400){
EXP1=ceil(EXP1*1.13);
m+=200;
M1-=200;
checkEXP(EXP1);
checkM(M1);
}else{
EXP1=ceil(EXP1*1.13);
m+=120;
M1-=120;
checkEXP(EXP1);
checkM(M1);
}
}}else{
M1=0;
}

if(M1>0){
	if(m<=m1){
if(EXP1<300){
EXP1=ceil(EXP1*0.9);
m+=100;
M1-=100;
checkEXP(EXP1);
checkM(M1);
}else{
EXP1=ceil(EXP1*0.9);
m+=120;
M1-=120;
checkEXP(EXP1);
checkM(M1);
}
}}else{
M1=0;
}
}//ket thuc while
}
HP1=ceil(HP1-HP1*0.17);
EXP1=ceil(EXP1*1.17);
checkHP(HP1);
checkEXP(EXP1);

//}//
int S2;
if(sqrt(EXP1)==(int)sqrt(EXP1)){
P2=100;
}else{
int can2=sqrt(EXP1);
if(pow(can2+1,2)-EXP1>=-pow(can2,2)+EXP1){
 P2=100;
}else{
	S2=pow(can2+1,2);
 P2=100*(EXP1/(S2*1.0)+80)/123.0;
}
}



//con duong 3
int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
if(E2<10){
P3=P[E2];
}else{
E2=E2/10+E2%10;
E2=E2%10;
P3=P[E2];
}
if((P1==100)&&(P2==100)&&(P3==100)){
EXP1=ceil(EXP1*0.75);
checkEXP(EXP1);
}else{
if((P1+P2+P3)/3.0>=50){
HP1=ceil(HP1-HP1*0.1);/////////////////   CEIL(HP1*1.1)!=CEIL(HP1-HP1*0.1)?????????????
EXP1=ceil(EXP1*1.2);
checkHP(HP1);
checkEXP(EXP1);
}else{
HP1=ceil(HP1-HP1*0.15);
EXP1=ceil(EXP1*1.15);
checkHP(HP1);
checkEXP(EXP1);
}
}
    return HP1 + EXP1 + M1;
}



// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0||E3>99){
    	return -99;
	}
    checkHP(HP1);
    checkHP(HP2);
    checkEXP(EXP1);
    checkEXP(EXP2);
    	int mt[10][10];
    for(int i=0;i<=9;i++){
    	for(int j=0;j<=9;j++){
    		mt[i][j]=0;
		}
	}
	//them thong tin vao ma tran
	for(int i=0;i<=9;i++){
		for(int j=0;j<=9;j++){
			mt[i][j]=((E3*j) + (i*2))*(i-j);
		}
	}
	//tim vi tri gap nhau
	int x=0;
	int y=0;
	for(int i=0;i<=9;i++){
		for(int j=0;j<=9;j++){
			if(mt[i][j]>2*E3){
				x+=1;
			}
			if(mt[i][j]<-E3){
				y+=1;
			}
		}
	}
	while(x>=10){
		x=x/10+x%10;
	}
	while(y>=10){
		y=y/10+y%10;
	}

	int x1=0,x2=0,x3=0,x4=0;
	int m1=-1000000,m2=-1000000,m3=-1000000,m4=-1000000,m=-1000000;
	//luu cheo trai tren
	if(x<y){
		x1+=x;
	}else{
		x1+=y;
	}
	int vt1[x1];
	if(x<y){
		for(int i=0;i<=x1;i++){
			vt1[i]=mt[i][y-x+i];
		}
	}else{
		for(int i=0;i<=x1;i++){
			vt1[i]=mt[x-y+i][i];
		}
	}
	for(int i=0;i<=x1;i++){
		if(m1<=vt1[i]){
			m1=vt1[i];
		}
	}
	//luu cheo phai tren
	if(x<9-y){
		x2+=x;
	}else{
		x2+=9-y;
	}
	int vt2[x2];
	if(x<9-y){
		for(int i=0;i<=x2;i++){
			vt2[i]=mt[i][y+x-i];
		}
	}else{
		for(int i=0;i<=x2;i++){
			vt2[i]=mt[x-9+y+i][9-i];
		}
	}
	for(int i=0;i<=x2;i++){
		if(m2<=vt2[i]){
			m2=vt2[i];
		}
	}
	//luu cheo trai duoi
	if(9-x<9-y){
		x3+=9-x;
	}else{
		x3+=9-y;
	}
	int vt3[x3];
	if(9-x<9-y){
		for(int i=0;i<=x3;i++){
			vt3[i]=mt[9-i][y+9-x-i];
		}
	}else{
		for(int i=0;i<=x2;i++){
			vt3[i]=mt[x+9-y-i][9-i];
		}
	}
	for(int i=0;i<=x3;i++){
		if(m3<=vt3[i]){
			m3=vt3[i];
		}
	}
	//luu cheo phai duoi
	if(9-x<y){
		x4+=9-x;
	}else{
		x4+=y;
	}
	int vt4[x4];
	if(9-x<y){
		for(int i=0;i<=x4;i++){
			vt4[i]=mt[9-i][y+x-9+i];
		}
	}else{
		for(int i=0;i<=x4;i++){
			vt4[i]=mt[x+y-i][i];
		}
	}
	for(int i=0;i<=x4;i++){
		if(m4<=vt4[i]){
			m4=vt4[i];
		}
	}
	int vt[4]={m1,m2,m3,m4};
	for(int i=0;i<=3;i++){
		if(m<=vt[i]){
			m=vt[i];
		}
	}
	if(abs(mt[x][y])>abs(m)){
		HP1=ceil(HP1*0.9);
		EXP1=ceil(EXP1*0.88);
		HP2=ceil(HP2*0.9);
		EXP2=ceil(EXP2*0.88);
		checkHP(HP1);
    checkHP(HP2);
    checkEXP(EXP1);
    checkEXP(EXP2);
	}else{
	    HP1=ceil(HP1+HP1*0.1);  /////!=CEIL(HP1*1.1)
		 ////
		EXP1=ceil(EXP1+EXP1*0.12);
		HP2=ceil(HP2+HP2*0.1);//////
		EXP2=ceil(EXP2+EXP2*0.12);	
		checkHP(HP1);
    checkHP(HP2);
    checkEXP(EXP1);
    checkEXP(EXP2);
	}
if(abs(mt[x][y])>abs(m)){
	return mt[x][y];
}else{
	return m;
}
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
	int S=0;
	int S1=0;
	while (s[S] != '\0'){
	S++;
	}
	while(email[S1]!='@'){
		S1++;
	}
	char se[S1];
	for(int i=0;i<S1;i++){
		se[i]=email[i];
	}
	char s1[S1];
if(S<8){
    	return -1;
	}else{
		if(S>20){
			return -2;
		}else{
			//check mk chua se
			if(S1==0){
				return -300;
			}
			for(int i=0;i<S;i++){
						if(se[0]==s[i]){
							for(int j=0;j<S1;j++){
								s1[j]=s[j+i];
							}
							if(strncmp(s1,se,S1)==0){
								return -(300+i);
							}
						}       
			}
			//check chua nhieu hon hai ki tu lien tiep giong nhau
			for(int i=0;i<S;i++){
				if(s[i]==s[i+1]&&s[i+1]==s[i+2]){
					return -(400+i);
				}
			}
			//check khong chua ki tu dac biet
			int checkdb=0;
			for(int i=0;i<S;i++){
				if(s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!'){
					checkdb+=1;
				}
			}
			if(checkdb==0){
				return -5;
			}
			//check cac truong hop con lai
			for(int i=0;i<S;i++){
				if((s[i]>='0'&&s[i]<='9')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')
				||s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!'){
				}else{
					return i;
				}
			}
			//tra ve mk dung
			return -10;
		}
	}

    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    const int size=num_pwds;
    int a[size]={0};
    int b[size]={0};
    int c[size]={0};
    int max=-100000;
    int max1=-10000;
    for(int i=0;i<size;i++){
    	int tanso=1;
    	if(c[i]==0){
    		for(int j=i+1;j<size;j++){
    			int result=strcmp(arr_pwds[i],arr_pwds[j]);
    			if(result==0){
    				//return i;///////////////////// co chay den cho nay!
    				c[j]=1;//danh dau, neu c[j] bang 1 thi trung=> khong thuc hien vong for tai luc nay
    				tanso+=1;
				}
			}
		}
		a[i]=tanso;
		b[i]=strlen(arr_pwds[i]);// quet dc b[i]
	}
	for(int i=0;i<size;i++){
		if(max<a[i]){
			max=a[i];
		}
	}
	for(int i=0;i<size;i++){
		if(max==a[i]){
			if(max1<b[i]){
				max1=b[i];
			}
		}
	}
	for(int i=0;i<size;i++){
		if(max==a[i]){
			for(int j=0;j<size;j++){   ////
				if(max==a[j]){
					if(max1==b[j]){
						return j;
					}
				}
			}
			return i;
		}
	}
	

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////