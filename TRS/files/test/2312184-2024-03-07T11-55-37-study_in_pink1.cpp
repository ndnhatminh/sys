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
void checkHP(int &HP){
	if(HP<0 || HP>666){
		if(HP<0) HP=0;
		else HP=666;
	}
}

void checkEXP(int &EXP){
	if(EXP<0 || EXP>600){
		if(EXP<0) EXP=0;
		else EXP=600;
	}
}
void checkM(int &M){
	if(M<0 || M>3000){
		if(M<0) M=0;
		else M=3000;
	}
}
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    checkEXP(EXP1);
    checkEXP(EXP2);
    if(E1>=0 && E1<=99){
		if(E1<=3){
			if(E1==0) EXP2 += 29;
			else if(E1==1) EXP2 += 45;
			else if(E1==2) EXP2 += 75;
			else if(E1==3) EXP2 += 149;
			checkEXP(EXP2);
			int D;
			D = E1 * 3 + EXP1 * 7;
			float temp;
			if(D % 2 == 0){
				temp = EXP1 + (1.0*D/200);
				EXP1 = ceil(temp);
			} 
			else{
				temp = EXP1 - (1.0*D/100);
				EXP1 = ceil(temp);
			}
			checkEXP(EXP1);
			return EXP1 + EXP2;
		}
		else{
			if(E1<20) EXP2 += ceil(1.0*E1/4 + 19);
			else if(E1<50) EXP2 += ceil(1.0*E1/9 + 21);
			else if(E1<66) EXP2 += ceil(1.0*E1/16 + 17);
			else if(E1<80){
				EXP2 += ceil(1.0*E1/4 + 19);
				if(EXP2>200) EXP2 += ceil(1.0*E1/9 + 21);
			} 
			else{
				EXP2 += ceil(1.0*E1/4 + 19);
				EXP2 += ceil(1.0*E1/9 + 21);
				if(EXP2>400){
					EXP2 += ceil(1.0*E1/16 + 17);
					EXP2 = ceil(EXP2*1.15);
				}
			}
			checkEXP(EXP2);
			EXP1 -= E1;
			checkEXP(EXP1);
			return EXP1 + EXP2;
		}
	}
	else return -99;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    checkHP(HP1);
    checkEXP(EXP1);
    checkM(M1);
	if(E2<0 || E2>99) return -99;
	int x1, S1;
	x1 = round(sqrt(EXP1));
	S1 = x1*x1;
	float P1;
	if(EXP1>=S1) P1=100;
	else P1 = (1.0*EXP1/S1 + 80)/123*100;
	if(E2 % 2 != 0){
		float half = M1*0.5;
		int pay;
		while(1){
			if(M1==0) break;
			if(HP1<200){
				HP1 = ceil(HP1*1.3);
				pay += 150;
			}
			else{
				HP1 = ceil(HP1*1.1);
				pay += 70;
			}	
			if(pay>half) break;
			if(EXP1<400) pay += 200;
			else pay += 120;
			EXP1 = ceil(EXP1*1.13);
			if(pay>half) break;
			if(EXP1<300) pay += 100;
			else pay += 120;
			EXP1 = ceil(EXP1*0.9);
			if(pay>half) break;
		}
		M1 -= pay;
	}
	else{
		for(int i=1; i<2; i++){
			if(M1==0) break;
			if(HP1<200){
				HP1 = ceil(HP1*1.3);
				M1 -= 150;
			}
			else{
				HP1 = ceil(HP1*1.1);
				M1 -= 70;
			}	
			if(M1<=0) break;
			if(EXP1<400) M1 -= 200;
			else M1 -= 120;
			EXP1 = ceil(EXP1*1.13);
			if(M1<=0) break;
			if(EXP1<300) M1 -= 100;
			else M1 -= 120;
			EXP1 = ceil(EXP1*0.9);
		}
	}
	checkM(M1);
	checkEXP(EXP1);
	checkHP(HP1);
	HP1 = ceil(HP1*0.83);
	checkHP(HP1);
	EXP1 = ceil(EXP1*1.17);
	checkEXP(EXP1);
	int x2, S2;
	x2 = round(sqrt(EXP1));
	S2 = x2*x2; float P2;
	if(EXP1>=S2) P2=100;
	else P2 = (1.0*EXP1/S2 +80)/123*100;
	int A[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}; float P3;
	if(E2<10) P3 = A[E2];
	else{
		int y = E2/10 + E2 % 10;
		P3 = A[y%10];
	}
	if(P1 == P2 == P3 == 100){
		EXP1 = ceil(EXP1*0.75); 
		checkEXP(EXP1);
	}
	float P = (P1 + P2 + P3) / 3;
	if(P<50){
		HP1 = ceil(HP1*0.85);
		EXP1 = ceil(EXP1*1.15);
	}
	else{
		HP1 = ceil(HP1*0.9);
		EXP1 = ceil(EXP1*1.2);
	}
	checkHP(HP1);
	checkEXP(EXP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    checkHP(HP1);
    checkHP(HP2);
    checkEXP(EXP1);
    checkEXP(EXP2);
    if(E3<0 || E3>99) return -99;
    int a[10][10]={}; 
    int x=0, y=0;
    for(int i=0; i<10; i++){
    	for(int j=0; j<10; j++){
    		a[i][j] = ((E3*j) + (i*2)) * (i-j);
    		if(a[i][j]>0){
    			if(a[i][j] > (E3*2)) x++;
			}
			else if(a[i][j]<0){
				if(a[i][j] < (-E3)) y++;
			}
		}
	}
	while(x>9){
		x = x/10 + x%10;
	}
	while(y>9){
		y = y/10 + y%10;
	}
	int b[10][10]={};
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			int k=i, z=j;
			while(k<9 && z<9){
				++k; ++z;				
				b[i][j] = max(b[i][j], a[k][z]);
			}
			k=i; z=j;
			while(k>0 && z<9){			
				--k; ++z;	
				b[i][j] = max(b[i][j], a[k][z]);
			}
			k=i; z=j;
			while(k>0 && z>0){
				--k; --z;
				b[i][j] = max(b[i][j], a[k][z]);
			}
			k=i; z=j;
			while(k<9 && z>0){
				++k; --z;
				b[i][j] = max(b[i][j], a[k][z]);
			}
			if(b[i][j]<0) b[i][j] = abs(b[i][j]);
		}
	}
	if(abs(a[x][y]) > b[x][y]){
		EXP1 = ceil(EXP1*0.88);
		EXP2 = ceil(EXP2*0.88);
		HP1 = ceil(HP1*0.9);
		HP2 = ceil(HP2*0.9);
		checkEXP(EXP1);
		checkEXP(EXP2);
		checkHP(HP1);
		checkHP(HP2);
		return a[x][y];
	}
	else{
		EXP1 = ceil(EXP1*1.12);
		EXP2 = ceil(EXP2*1.12);
		HP1 = ceil(HP1*1.1);
		HP2 = ceil(HP2*1.1);
		checkEXP(EXP1);
		checkEXP(EXP2);
		checkHP(HP1);
		checkHP(HP2);
		return b[x][y];
	}
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
	string se;
	string s1 = s;
	string email1 = email;
	se = email1.substr(0, email1.length()-10);
	if(s1.length()<8) return -1;
	else if(s1.length()>20) return -2;
	bool check = false;
	int pos;
	for(int i=0; i<s1.length(); i++){
		int k=i;
		if(s1[k] == se[0]){
			check = true;
			for(int j=1; j<se.length(); j++){
				if(s1[++k] != se[j] ){
					check = false; break;
				}
			}
		}
		if(check){
			pos=i; return -(300+pos);
		}
	}
	int count=0;
	for(int i=0; i<s1.length()-1; i++){
		if(s1[i]==s1[i+1]) count++;
		else count = 0;
		if(count>=2) return -(400+i-2);
	}
	bool check2 = false;
	for(int i=0; i<s1.length(); i++){
		if(s1[i] == '@' || s1[i] == '#' || s1[i] == '%' || s1[i] == '$' || s1[i]=='!'){
			check2 = true;
		}
	}
	if(check2==false) return -5;
	for(int i=0; i<s1.length(); i++){
		if(s1[i]==34 || s1[i]<33 || (s1[i]>=38 && s1[i]<=47) || (s1[i]>=58 && s1[i]<=63) || (s1[i]>=91 && s1[i]<=96) || s1[i]>122){
			return i;
		} 
	}
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
	int max=0, idx;
	for(int i=0; i<num_pwds; i++){
		int cnt =1;
		for(int j=i+1; j<num_pwds; j++){
			if(strcmp(arr_pwds[i], arr_pwds[j])==0){
				++cnt;
			}
		}
		if(cnt>max){
			max = cnt;
			idx = i;
		}
		else if(cnt==max){
			if(strlen(arr_pwds[idx])<strlen(arr_pwds[i])) idx = i;
		}
	}
	for(int i=0; i<num_pwds; i++){
		if(strcmp(arr_pwds[idx], arr_pwds[i])==0){
			return i; break;
		}
	}
    return -1;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
