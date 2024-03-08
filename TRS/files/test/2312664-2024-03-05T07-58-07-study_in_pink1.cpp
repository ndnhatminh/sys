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
    if((e1>=0)&&(e1<=3)){
    	if(e1==0) exp2+=29;
    	else if(e1==1) exp2+=45;
    	else if(e1==2) exp2+=75;
    	else exp2+=149;
    	int d=e1*3+exp1*7;
    	if(d%2==0) exp1=ceil(float(exp1+d/200.0));
    	else exp1=ceil(float(exp1-d/100.0));
    }
    else if((e1>=4)&&(e1<=99)){
    	if((e1>=4)&&(e1<=19)) exp2=ceil(float(exp2+e1/4.0+19));
    	else if((e1>=20)&&(e1<=49)) exp2=ceil(float(exp2+e1/9.0+21));
    	else if((e1>=50)&&(e1<=65)) exp2=ceil(float(exp2+e1/16.0+17));
    	else if((e1>=66)&&(e1<=79)) {
    		exp2=ceil(float(exp2+e1/4.0+19));
    		if(exp2>200) exp2=ceil(float(exp2+e1/9.0+21)); 
		}
		else if((e1>=80)&&(e1<=99)){
			exp2=ceil(float(exp2+e1/4.0+19));
			exp2=ceil(float(exp2+e1/9.0+21));
			if(exp2>400) {
				exp2=ceil(float(exp2+e1/16.0+17));
				exp2=ceil(float(exp2+exp2*15/100.0));
			}
		}
		exp1-=e1;
	}
	else return -99;
	if(exp1>600) exp1=600; if(exp1<0) exp1=0;
	if(exp2>600) exp2=600; if(exp2<0) exp2=0;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // CON DUONG 1
    if(E2>=100) return -99;
	int sobe=sqrt(EXP1), solon=ceil(float(sqrt(EXP1))), sochinhphuong;
	float P1;
	if((EXP1-sobe*sobe)>(solon*solon-EXP1)) P1=(EXP1*1.0/(solon*solon)+80)*100/123; 
	else P1=100;
	// CON DUONG 2
	int BANDAU=M1;
	if(E2%2!=0)
	while((BANDAU-M1)<=(0.5*BANDAU)){
		if(HP1<200){
			HP1=ceil(float(HP1*1.3));
			M1-=150;
			if(M1<=0) M1=0;
		}
		else{
			HP1=ceil(float(HP1*1.1));
			if(HP1>666) HP1=666;
			M1-=70;
			if(M1<=0) M1=0;
		}
		if((BANDAU-M1)>(0.5*BANDAU)) goto dibo;
		if(EXP1<400) M1-=200; 
		else M1-=120; 
		if(M1<=0) M1=0;
		EXP1=ceil(float(EXP1*1.13));
		if(EXP1>600) EXP1=600;
		if((BANDAU-M1)>(0.5*BANDAU)) goto dibo;
		if(EXP1<300) M1-=100;
		else M1-=120;
		if(M1<=0) M1=0;
		EXP1=ceil(float(EXP1*0.9));
		if((BANDAU-M1)>(0.5*BANDAU)) goto dibo;
	}
	else{
		if(HP1<200){
			HP1=ceil(float(HP1*1.3));
			M1-=150;
		}
		else{
			HP1=ceil(float(HP1*1.1));
			if(HP1>666) HP1=666;
			M1-=70;
		}
		if(M1<=0) {
			M1=0;
			goto dibo;
		}
		if(EXP1<400) M1-=200;
		else M1-=120;
		EXP1=ceil(float(EXP1*1.13));
		if(EXP1>600) EXP1=600;
		if(M1<=0) {
			M1=0;
			goto dibo;
		}
		if(EXP1<300) M1-=100;
		else M1-=120;
		EXP1=ceil(float(EXP1*0.9));
		if(M1<=0) {
			M1=0;
			goto dibo;
		}
	}
	dibo:
	HP1=ceil(float(HP1*0.83));
	EXP1=ceil(float(EXP1*1.17));
	if(EXP1>600) EXP1=600;
	sobe=sqrt(EXP1), solon=ceil(float(sqrt(EXP1)));
	float P2;
	if((EXP1-sobe*sobe)>(solon*solon-EXP1)) P2=(EXP1*1.0/(solon*solon)+80)*100/123;
	else P2=100;
	// CON DUONG 3
	float arr[10]={32,47,28,79,100,50,22,83,64,11} ,P3;
	int U,F;
	if(E2<10) P3=arr[E2];
	else{
		U=E2%10+E2/10;
		F=U%10;
		P3=arr[F];
	}
	float P=(P1+P2+P3)/3;
	if(P==100) EXP1=ceil(float(EXP1*0.75));
	else if(P<50) {
		HP1=ceil(float(HP1*0.85));
		EXP1=ceil(float(EXP1*1.15));
	}
	else{
		HP1=ceil(float(HP1*0.9));
		EXP1=ceil(float(EXP1*1.2));	
	}
	if(EXP1>600) EXP1=600;
	if(HP1>666) HP1=666;
    return HP1 + EXP1 + M1;  
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
	// TODO: Complete this function
	int arr[10][10] = { 0 }, i, j, ii = 0, jj = 0, diemtx, diem, max;
	for (i = 0; i <= 9; i++) {
		for (j = 0; j <= 9; j++) {
			arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
			if (arr[i][j] > E3 * 2) ii++;
			if (arr[i][j] < (-E3)) jj++;
		}
	}
	while (ii >= 10) ii = ii % 10 + ii / 10;
	while (jj >= 10) jj = jj % 10 + jj / 10;
	diemtx = arr[ii][jj];
	int tong = ii + jj, hieu = ii - jj;
	if (tong <= 9) {
		max = arr[tong][0];
		for (i = 0; i <= tong; i++) if (max < arr[tong - i][i]) max = arr[tong - i][i];
	}
	else {
		max = arr[9][tong - 9];
		for (i = 0; i <= 18 - tong; i++) if (max < arr[9 - i][tong - 9 + i]) max = arr[9 - i][tong - 9 + i];
	}
	if (hieu >= 0) for (i = 0; i <= 9 - hieu; i++) if (max < arr[hieu + i][i]) max = arr[hieu + i][i];
	else for (i = 0; i <= 9 + hieu; i++) if (max < arr[i][i - hieu]) max = arr[i][i - hieu];
	if (max >= abs(diemtx)) {
		EXP1 = ceil(float(EXP1 * 1.12));
		EXP2 = ceil(float(EXP2 * 1.12));
		HP1 = ceil(float(HP1 * 1.1));
		HP2 = ceil(float(HP2 * 1.1));
	}
	else {
		EXP1 = ceil(float(EXP1 * 0.88));
		EXP2 = ceil(float(EXP2 * 0.88));
		HP1 = ceil(float(HP1 * 0.9));
		HP2 = ceil(float(HP2 * 0.9));
	}
	if (EXP1 > 600) EXP1 = 600;
	if (EXP2 > 600) EXP2 = 600;
	if (HP1 > 666) HP1 = 666;
	if (HP2 > 666) HP2 = 666;
	if (max >= abs(diemtx)) return max;
	else return diemtx;
}

// Task 4
int checkPassword(const char* s, const char* email) {
	// TODO: Complete this function
	string a = email, mk = s;
	int i, u;
	string se = a.substr(0, a.find('@'));
	if (mk.length() < 8) return -1;
	if (mk.length() > 20) return -2;
	int vitri = mk.find(se);
	if (vitri != string::npos) return -(300 + vitri);
	for (i = 0; i <= mk.length() - 3; i++)
		if ((mk[i] == mk[i + 1]) && (mk[i] == mk[i + 2])) return -(400 + i);
	int dieukien = 1;
	for (i = 0; i <= mk.length() - 1; i++) if ((mk[i] == '@') || (mk[i] == '#') || (mk[i] == '%') || (mk[i] == '$') || (mk[i] == '!')) {
		dieukien = 0;
		break;
	}
	if (dieukien == 1) return -5;
	for (i = 0; i <= mk.length() - 1; i++) {
		u = int(mk[i]);
		if (((u < 33) || (u == 34)) || ((u > 37) && (u < 48)) || ((u > 57) && (u < 64)) || ((u > 90) && (u < 97)) || (u > 122)) return i;
	}
	return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string arr[num_pwds]={};
    for(int i=0;i<=num_pwds-1;i++) arr[i]=arr_pwds[i];
    int tansuat[num_pwds], max=0;
    for(int i=0;i<=num_pwds-1;i++){
    	tansuat[i]=0;
    	for(int k=0;k<=num_pwds-1;k++) if(arr[i]==arr[k]) tansuat[i]+=1;
		if(tansuat[i]>max) max=tansuat[i];	
	}
	int chieudaichuoi=0;
	for(int i=0;i<=num_pwds-1;i++) if(tansuat[i]==max) if(arr[i].length()>chieudaichuoi) chieudaichuoi=arr[i].length();
	for(int i=0;i<=num_pwds-1;i++) if((tansuat[i]==max)&&(arr[i].length()==chieudaichuoi)) return i;
	return -1;	
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
