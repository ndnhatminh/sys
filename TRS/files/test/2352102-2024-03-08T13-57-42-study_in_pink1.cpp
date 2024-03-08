#include "study_in_pink1.h"

bool readFile(
        const string &filename,
        int &HP1,
        int &HP2,
        int &EXP1,
        int &EXP2,
        int &M1,
        int &M2,
        int &E1,
        int &E2,
        int &E3
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
    } else {
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
int  firstMeet(int & exp1, int & exp2, int e1) {
	if(e1<0||e1>99) {
		return -99;
	}
	int D;
	if(exp1<0) {
		exp1=0;
	} else if(exp1>600) {
		exp1=600;
	}
	if(exp2<0) {
		exp2=0;
	} else if(exp2>600) {
		exp2=600;
	}

	if(e1>=0&&e1<=3) {
		if(e1==0) {
			exp2+=29;
		} else if(e1==1) {
			exp2+=45;
		} else if(e1==2) {
			exp2+=75;
		} else if(e1==3) {
			exp2+=149;
		}
		
		int k=exp1;
		D=(e1*3+k*7);
	if(exp1>600) {
		exp1=600;
	}
	if(exp2>600) {
		exp2=600;
	}
	
	
	if(D%2==0) {
		exp1+=ceil(D*1.0/200);
	} else {
		exp1-=D/100;
	}

	if(exp1>600) {
		exp1=600;
	} else if(exp1<0) {
		exp1=0;
	}
	if(exp2>600) {
		exp2=600;
	} else if(exp2<0) {
		exp2=0;
	}
		
		
	}
	

///////////////////////////////////////////////////////////////////
	

	///////////////////////////////////////////////////////////////////
	
	
	
	
	
	if(e1>=4&&e1<=99) {
		//1
		if(e1>=4&&e1<=19) {
            float k=e1;
			exp2 = exp2+ceil(ceil(k*1.0/4)+19);
		}
		//2
		if(e1      >=20  &&   e1  <=  49) {
			float k=e1;
            exp2 = exp2  +ceil (  ceil(  k   *1.0/9)   + 21    );
		}
		//3
		if(e1>=50&&e1<=65) {
			float k=e1;
            exp2=exp2+ceil(ceil(k*1.0/16)+17);
		}
		//4
		if(e1>=66&&e1<=79) {
			float k=e1;
            exp2=exp2+ceil(ceil(k*1.0/4)+19);
			if(exp2>200) {
				exp2=exp2+ceil(ceil(k*1.0/9)+21);
			}
		}
		//5
		if(e1>=80&&e1<=99) {
			float k=e1;
			exp2=exp2+ceil(ceil(k/4)+19);
			exp2=exp2+ceil(ceil(k/9)+21);
			if(exp2>400) {
				exp2=exp2+ceil((k/16)+17);
				exp2=ceil(exp2*1.15);
			}
		}



int op=e1;
		exp1=exp1-op;
	}
	if(exp2>=600) {
		exp2=600;
	}
	if(exp2<=0) {
		exp2=0;
	}
	if(exp1>=600) {
		exp1=600;
	}
	if(exp1<=0) {
		exp1=0;
	}
	
 return exp1+exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
	
	if(E2<0||E2>99){
		
		return -99;
	}	
	
	if(HP1<0){
		HP1= 0; 
		}
	else if(HP1>666){
		HP1=666; 
	} 
	if(EXP1<0){
		EXP1= 0; 
		}
	else if(EXP1>600){
		EXP1=600; 
	} 
		if(M1<0){
		M1= 0; 
		}
	else if(M1>3000){
	M1=3000; 
	} 
	double p1, p2, p3;
	short wallet = M1;	
	short P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
		
		if (((pow(ceil(sqrt(EXP1)), 2) - EXP1) > (EXP1 - pow((ceil(sqrt(EXP1)) - 1), 2))) || (pow(ceil(sqrt(EXP1)), 2) == EXP1)) p1 = 1;
		else p1 = (EXP1 / pow(ceil(sqrt(EXP1)), 2) + 80) / 123;
		do
		{
	
			if ((HP1 < 200) && (M1 > 0) && (((wallet - M1) < ceil(wallet / 2 + 0.5)) || (E2 % 2 == 0)))
			{
				HP1 += ceil(HP1 * 0.3);
				M1 -= 150;
			}
			else if ((HP1 >= 200) && (M1 > 0) && (((wallet - M1) < ceil(wallet / 2 + 0.5)) || (E2 % 2 == 0)))
				{
					HP1 += ceil(HP1 * 0.1);
					M1 -= 70;
				}
		
			if(HP1<0){
		HP1= 0; 
		}
	else if(HP1>666){
		HP1=666; 
	} 
	
	
			if(M1<0){
		M1= 0; 
		}
	else if(M1>3000){
	M1=3000; 
	} 
			

			if ((EXP1 < 400) && (M1 > 0) && (((wallet - M1) < ceil(wallet / 2 + 0.5)) || (E2 % 2 == 0)))
			{
				M1 -= 200;
				EXP1 += ceil(EXP1 * 0.13);
			}
			else if ((EXP1 >= 400) && (M1 > 0) && (((wallet - M1) < ceil(wallet / 2 + 0.5)) || (E2 % 2 == 0)))
				{
					M1 -= 120;
					EXP1 += ceil(EXP1 * 0.13);
				}
		
			if(HP1<0){
		HP1= 0; 
		}
	else if(HP1>666){
		HP1=666; 
	} 
			if(EXP1<0){
		EXP1= 0; 
		}
	else if(EXP1>600){
		EXP1=600; 
	} 
			if(M1<0){
		M1= 0; 
		}
	else if(M1>3000){
	M1=3000; 
	} 

			if ((EXP1 < 300) && (M1 > 0) && (((wallet - M1) < ceil(wallet / 2 + 0.5)) || (E2 % 2 == 0)))
			{
				M1 -= 100;
				EXP1 = ceil(EXP1 - EXP1 * 0.1);
			}
			else if ((EXP1 >= 300) && (M1 > 0) && (((wallet - M1) < ceil(wallet / 2 + 0.5)) || (E2 % 2 == 0))	)
				{
					M1 -= 120;
					EXP1 = ceil(EXP1 - EXP1 * 0.1);
				}
		
			if(HP1<0){
		HP1= 0; 
		}
	else if(HP1>666){
		HP1=666; 
	} 
				if(EXP1<0){
		EXP1= 0; 
		}
	else if(EXP1>600){
		EXP1=600; 
	} 
			if(M1<0){
		M1= 0; 
		}
	else if(M1>3000){
	M1=3000; 
	} 
			
			
		}
		while ((E2 % 2 == 1) && (M1 > 0) && ((wallet - M1) < ceil(wallet / 2 + 0.5)));
	HP1 = ceil(HP1 - HP1 * 0.17);
		EXP1 = ceil(EXP1 * 1.17);
	
			if(HP1<0){
		HP1= 0; 
		}
	else if(HP1>666){
		HP1=666; 
	} 
		if(EXP1<0){
		EXP1= 0; 
		}
	else if(EXP1>600){
		EXP1=600; 
	} 

		if (((pow(ceil(sqrt(EXP1)), 2) - EXP1) > (EXP1 - pow((ceil(sqrt(EXP1)) - 1), 2))) || (pow(ceil(sqrt(EXP1)), 2) == EXP1)) p2 = 1;
		else p2 = (EXP1 / pow(ceil(sqrt(EXP1)), 2) + 80) / 123;
		    

		if (E2 < 10) p3 = P[E2] / 100.0;
		else p3 = P[((E2 / 10) + (E2 % 10)) % 10] / 100.0;
	
		if ((p1 == 1.0) && (p2 == 1.0) && (p3 == 1.0)) EXP1 = ceil(EXP1 - EXP1 * 0.25);
		else if ((p1 + p2 + p3) / 3 >= 0.5)
			{
				HP1 = ceil(HP1 - HP1 * 0.1);
				EXP1 += ceil(EXP1 * 0.2);
			}
		else
		{
			HP1 = ceil(HP1 - HP1 * 0.15);
			EXP1 += ceil(EXP1 * 0.15);
		}	
		

		if(HP1<0){
		HP1= 0; 
		}
	else if(HP1>666){
		HP1=666; 
	} 
		if(EXP1<0){
		EXP1= 0; 
		}
	else if(EXP1>600){
		EXP1=600; 
	} 
	if(M1<0){
		M1= 0; 
		}
	else if(M1>3000){
	M1=3000; 
	} 







return HP1+EXP1+M1;

}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
	if(E3<0||E3>99) {
		return -99;
	}
     if(HP1<0){
		HP1= 0; 
		}
	else if(HP1>666){
		HP1=666; 
	} 
	if(EXP1<0){
		EXP1= 0; 
		}
	else if(EXP1>600){
		EXP1=600; 
	} 
    if(HP2<0){
		HP2= 0; 
		}
	else if(HP2>666){
		HP2=666; 
	} 
	if(EXP2<0){
		EXP2= 0; 
		}
	else if(EXP2>600){
		EXP2=600; 
	}
    int N=10;
	int dem=0,dem1=0;
	int taxi[N][N];
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			taxi[i][j]=((E3*j)+(i*2))*(i-j);
			if(taxi[i][j]>(E3*2)) {
				dem++;
			}
			if(taxi[i][j]<(-E3)) {
				dem1++;
			}

		}

	}


//tim toa do cua gap nhau
	int k=(dem/10)+(dem%10);
	int k1;
	if(k>=10) {
		k1=(k/10)+(k%10);
	} else {
		k1=k;
	}
	int k2=(dem1/10)+(dem1%10);
	int k3;
	if(k2>=10) {
		k3=(k2/10)+(k3%10);
	} else {
		k3=k2;
	}
	int a2[10];
	for(int i=0; i<10; i++) {
		a2[i]=0;

	}
	int o3=0;
	int o1=k1,o2=k3;

	while(o2>=0&&o1<10) {
		a2[o3]=taxi[o1++][o2--];

		o3++;
	}
	int st=0;
	for(int i=0;i<o3;i++){
		if(a2[i]<a2[i+1]){
			st=a2[i+1];
		}
	}

if(st==0){
	st=abs(taxi[k1][k3]);
}
	if(st<abs(taxi[k1][k3])) {
			EXP1 = ceil(EXP1-EXP1*0.12);
		HP1 =ceil(HP1-HP1*0.1);
		EXP2 = ceil( EXP2-EXP2*0.12);
		HP2 =ceil(HP2-HP2*0.1);
		if(HP1<0){
		HP1= 0; 
		}
	else if(HP1>666){
		HP1=666; 
	} 
	if(EXP1<0){
		EXP1= 0; 
		}
	else if(EXP1>600){
		EXP1=600; 
	} 
    if(HP2<0){
		HP2= 0; 
		}
	else if(HP2>666){
		HP2=666; 
	} 
	if(EXP2<0){
		EXP2= 0; 
		}
	else if(EXP2>600){
		EXP2=600; 
	} 


return taxi[k1][k3];
	}

	else {
				EXP1 = ceil(EXP1+EXP1*0.12);
		HP1 =ceil(HP1+HP1*0.1);
		EXP2 = ceil( EXP2+EXP2*0.12);
		HP2 =ceil(HP2+HP2*0.1);
		
        if(HP1<0){
		HP1= 0; 
		}
	else if(HP1>666){
		HP1=666; 
	} 
	if(EXP1<0){
		EXP1= 0; 
		}
	else if(EXP1>600){
		EXP1=600; 
	} 
    if(HP2<0){
		HP2= 0; 
		}
	else if(HP2>666){
		HP2=666; 
	} 
	if(EXP2<0){
		EXP2= 0; 
		}
	else if(EXP2>600){
		EXP2=600; 
	} 
return st;
	}


return -1;
}


// Task 4

int checkPassword(const char *s,const char *email) {

	char SE[strlen(s)];//luu ma SE
	int se=0;
	int demsl=1;
	int cou[strlen(s)];//so lan lap lai
	for(int i=0; i<strlen(s); i++) {
		cou[i]=0;

	}//so lan lap lai
	//lau se
	for(int i=0; i<strlen(email); i++) {
		if(email[i]!='@') {
			SE[se]=email[i];
			se++;
		} else {
			break;
		}

	}
	
	if(strlen(s)<8){
		return -1; 
	} 
	if(strlen(s)>20){
		return -2; 
	} 
		char S2[strlen(s)];
		int de=0;
		//kiem tra pass co se  hay ko
		for(int i=0; i<strlen(s); i++) {
			int po=0,po2=i; 
	
			if(s[i]==SE[po]) {
				for(int j=i;j<strlen(SE);j++){
					if(s[j]==SE[po]) {
				
					po++; 
					de++;
				}	 
				} 
				if(de==se) {
					return -(300+i); 
				}
				else{
					de=0;
					po=0;
				}
			}
	}
		for(int i=0; i<strlen(s); i++) {
			int po=0,po2=i;
		 
			int sed=strlen(SE)-1;
			if(s[i]==SE[po]) {
				while(sed-->0) {
					po++;
					po2++;
					if(s[po2]==SE[po]) {
						demsl++;
					}
				}
				if(demsl==strlen(SE)) {
					return -(300+i);
				} 
			}
	}
		   
		//ktr 2ky tu lien tiep
		for(int i=0 ; i<strlen(s)-1; i++) {
			for(int j=i+1; j<strlen(s); j++) {
				if(s[i]==s[j]) {
					cou[i]+=1;
				}
			}
		}
		for(int i=0; i<strlen(s); i++) {
			if(cou[i]>=2) {
				return -(400+i);
			
			}
		}
		int toi=0;
		for(int i=0; i<strlen(s); i++) {
			if(s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!') {
				toi++;
			}
		}
	
		if(toi==0) {
			return -5;
		}
	
	return -10;
}

// Task 5
int findCorrectPassword(const char arr_pwds[][31], int num_pwds) {
	// TODO: Complete this function
	int dem=0;
	bool k[num_pwds];//xacdinh da kiem tra
	for(int i=0; i<20; i++) {
		k[i]=false;
	}
	int  b[num_pwds];//dem so lan lap lai
	for(int i=0;i<num_pwds;i++){
		
		b[i]=0; 
	} 
	for(int i=0; i<num_pwds-1; i++) {
		for(int j=i+1; j<num_pwds; j++) {
			if(strcmp(arr_pwds[i],arr_pwds[j])==0&&(k[i]!=1||k[j]!=1)) {
				b[i]+=1;//dem so lan lap lai 
				k[j]=true;//tr ve gia tri true de khong phai kiem tra lai 
				k[i]=true;
			}
		}
	}
	int max1=b[0];
	int vtr,vtr2=-1;
	//lay vi tri max 1 
	for(int i=0; i<num_pwds; i++) {
		if(max1<b[i]) {
			max1=b[i];
			vtr=i;
		}
	}
	//lay vi tri max thu 2 
	for(int i=0; i<num_pwds; i++) {
		if(max1==b[i]&&i!=vtr) {
			vtr2=i;
		}
	}
	int poi;
	//neu la 2 ky tu co cung do lan lap lai thi ta so danh do dai
	 
	if(vtr2!=-1) {
		if(strlen(arr_pwds[vtr])>strlen(arr_pwds[vtr2])) {
			poi=vtr;
		} else {
			poi=vtr2;
		}
	} else {
		poi=vtr;
	}
	//truong hop tat ca cac gia tri co cung so lan lap lai va do dai cua no =1 
	if(poi==num_pwds-1&&k[poi]!=1) {
		poi=-1;
	}
	return poi;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
