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

//ham phu de xet HP
int setHP(int &HP){
	if (HP < 0) HP = 0;
	if (HP > 666) HP = 666;
	return HP;
}

//ham phu de xet EXP
int setEXP(int &EXP){
	if (EXP < 0) EXP = 0;
	if (EXP > 600) EXP = 600;
	return EXP;
}

//ham phu de xet so tien M
int setM(int &M){
	if (M < 0) M = 0;
	if (M > 3000) M = 3000;
	return M;
}
//ham lam tron len
int round_up(float a){
	if(((a-(int)a) < 0.5) && ((a-(int)a)!=0)) a+=0.5;
	return round(a);
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
	
    // TODO: Complete this function
    	if (e1 < 0 || e1 > 99) return -99;
		setEXP(exp1);
    	setEXP(exp2);
    	if (e1 >=0 && e1<=3){
    		switch(e1){
    			case 0 :{
    				exp2+=29;
					break;
				}
				case 1 :{
    				exp2+=45;
					break;
				}
				case 2 :{
    				exp2+=75;
					break;
				}
				case 3 :{
    				exp2+=149;
					break;
				}
			}
			int D = e1 * 3 + exp1 * 7;
		
			if (D % 2 == 0){
				exp1 = round_up(exp1 + D/200.0);
			}
			else exp1 = round_up(exp1 - D/100.0);
		}
		
		else {
			if (e1 >= 4 && e1 <= 19){
				exp2+= round_up(e1 / 4.0 + 19);
			}
			if (e1 >= 20 && e1 <= 49){
				exp2+= round_up(e1 / 9.0 + 21);
			}
			if (e1 >= 50 && e1 <= 65){
				exp2+= round_up(e1 / 16.0 + 17);
			}
			if (e1 >= 66 && e1 <= 79){
				exp2+= round_up(e1 / 4.0 + 19);
				if (exp2 > 200) exp2+= round_up(e1 / 9.0 + 21);
			}
			if (e1 >= 80 && e1 <= 99){
				exp2+= round_up(e1 / 4.0 + 19);
				exp2+= round_up(e1 / 9.0 + 21);
				if (exp2 > 400) {
					exp2+= round_up(e1 / 16.0 + 17);
					exp2+= round_up(exp2 * 15 / 100.0);
				}
			}
			exp1-= e1;
		}
		
	setEXP(exp2);
	setEXP(exp1);
	
    
    return exp1 + exp2;
}

/// Task 2
float Px(int &EXP1){
	int nS=0; // can bac 2 cua so chinh phuong
	int S1, S2; // S1 la khoang cach cua so chinh phuong be hon va gan EXP1 nhat, S2 la khoang cach cua so chinh phuong lon hon va gan EXP1 nhat
	while (nS*nS <= EXP1){
		S1 = abs(EXP1 - nS*nS);
		S2 = abs(EXP1 - (nS+1)*(nS+1));
		if(S1 == 0) return 1;
		nS++;
	}
	//neu S1 > S2 thi S se lon hon EXP1, neu khac thi S se be hon EXP1
	if (S1 > S2){
		return ((float)(EXP1 / (EXP1+S2)) + 80.0) / 123.0;
	}
	else {
		return 1;
	}
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
	
    // TODO: Complete this function
	if (E3 < 0 || E3 > 99) return -99;
    // TODO: Complete this function
    setHP(HP1);
	setEXP(EXP1);
	setM(M1);
    //con duong 1
	float P1 = Px(EXP1);
	//con  duong 2
	//truong hop 1
	if (E3 % 2 == 1){
		float hM = M1 * 0.5; //fM la M1 ban dau
		while (1){
			if (M1 == 0) break;
		//cham 1
			if (HP1 < 200){
				HP1= round_up((float)HP1 * 1.3);
				M1-= 150;
			} else {
				HP1 = round_up((float)HP1 * 1.1);
				M1-= 70;
			}
			setM(M1);
			setHP(HP1);
			if( hM >  M1) break; //break khi so tien can tra lon hon 50% so tien ban dau
			// cham 2
			if (EXP1 < 400){
				M1-=200;
			} else {
				M1-=120;
			}
			setM(M1);
			EXP1= round_up((float)EXP1 * 1.13);
			setEXP(EXP1);
			
			if( hM >  M1) break; //break khi so tien can tra lon hon 50% so tien ban dau
			// cham 3
			if (EXP1 < 300){
				M1-= 100;
			} else {
				M1-= 120;
			}
			setM(M1);
			EXP1= round_up((float)EXP1 * 0.9);
			setEXP(EXP1);
			if( hM >  M1) break; //break khi so tien can tra lon hon 50% so tien ban dau
		} 
	} else {
		for(int i=0; i < 1 ; i++){
		//cham 1
			if(M1 == 0) break; //break khi so tien con 0
			
			if (HP1 < 200){
				HP1 = round_up((float)HP1 * 1.3);
				M1-= 150;
			} else {
				HP1 = round_up((float)HP1 * 1.1);
				M1-= 70;
			}
			setHP(HP1);
			setM(M1);
			if(M1 == 0) break; //break khi so tien con 0
			// cham 2
			if (EXP1 < 400){
				M1-=200;
			} else {
				M1-=120;
			}
			setM(M1);
			EXP1= round_up((float)EXP1 * 1.13);
			setEXP(EXP1);
			
			if(M1 == 0) break; //break khi so tien con 0
			// cham 3
			if (EXP1 < 300){
				M1-=100;
			} else {
				M1-=120;
			}
			setM(M1);
			EXP1= round_up((float)EXP1 * 0.9);
			setEXP(EXP1);
			if(M1 == 0) break; //break khi so tien con 0
		} 
		
	}
	//EXP sau con duong 2
	HP1 = round_up ((float)HP1 * 0.83); 
	EXP1 = round_up ((float)EXP1 * 1.17); 
	setHP(HP1);
	setEXP(EXP1);

	//tinh P2
	float P2 = Px(EXP1);

	//con duong 3
	int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
	float P3;
	if (E3 < 10){
		P3 = P[E3] / 100.0;
	} else {
		P3 = P[(E3 / 10 + E3 % 10) % 10]/100.0;
	}
	
	//giai doan tinh toan
	
	if (P1 == 1 && P2 == 1 && P3 == 1){
		EXP1= round_up((float)EXP1 * 0.75);
	} else {
		float avrP= ((float)P1 + P2 + P3) / 3.0; // tinh trung binh
		if(avrP < 0.5){
			HP1= round_up((float)HP1 * 0.85);
			EXP1= round_up((float)EXP1 * 1.15);
		} else {
			HP1= round_up((float)HP1 * 0.9);
			EXP1= round_up((float)EXP1 * 1.2);
		}
	}
	setHP(HP1);
	setEXP(EXP1);
	
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
	
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    setHP(HP1);
    setHP(HP2);
    setEXP(EXP1);
    setEXP(EXP2);
    int mapTaxi[10][10]={};
	int mapSW[10][10]={};
    for (int i=0; i<10; i++){
    	for(int j=0; j<10; j++){
    			mapTaxi[i][j]=((E3*j)+(i*2))*(i-j); //gan gia tri cho o Taxi di 
		}
	}
	
	//gan gia tri cho o cua S va W
	for (int i=0; i<10; i++){
    	for(int j=0; j<10; j++){
    			int k=i, t=j;
    			int maxmT = mapTaxi[i][j];
    			while(k < 10 && t < 10){				//tim max duong cheo phai theo huong xuong
    				if (maxmT < mapTaxi[k][t]){ 
    					maxmT = mapTaxi[k][t];
					}
					k++;
					t++;
				}
				k=i;
				t=j;
				while(k >= 0 && t >=0 ){				//tim max duong cheo phai theo huong len
    				if (maxmT < mapTaxi[k][t]){
    					maxmT = mapTaxi[k][t];
					}
					k--;
					t--;
				}
				k=i;
				t=j;
				while(k < 10 && t >= 0){				//tim max duong cheo trai theo huong len
    				if (maxmT < mapTaxi[k][t]){
    					maxmT = mapTaxi[k][t];
					}
					k++;
					t--;
				}
				k=i;
				t=j;
				while(k >=0 && t < 10){				//tim max duong cheo trai theo huong xuong
    				if (maxmT < mapTaxi[k][t]){
    					maxmT = mapTaxi[k][t];
					}
					k--;
					t++;
				}
    			mapSW[i][j] = maxmT;				//tim duoc max cua vi tri do voi ca duong cheo trai va phai
    			if (mapSW[i][j] < 0) mapSW[i][j]= abs(mapSW[i][j]);
		}
	}
	
	int demI=0,demJ=0;				//bat dau tim toa do I va J
	for (int i=0; i<10; i++){
    	for(int j=0; j<10; j++){
    		if(mapTaxi[i][j] > E3 * 2 && mapTaxi[i][j] > 0) demI++;
    		if(mapTaxi[i][j] < -E3 && mapTaxi[i][j] < 0) demJ++;
		}
	}
	
	while(demI > 9){		//tim I
		demI= (demI / 10 + demI%10);
	}
	
	while(demJ > 9){		//tim J
		demJ= (demJ / 10 + demJ%10);
	}	

	if(abs(mapTaxi[demI][demJ]) > mapSW[demI][demJ]){		// tinh toan trong truong hop khong duoi kip taxi
		EXP1= round_up(EXP1 * 0.88);
		HP1= round_up(HP1 * 0.9);
		EXP2= round_up(EXP2 * 0.88);
		HP2= round_up(HP2 * 0.9);
		setHP(HP1);
		setHP(HP2);
		setEXP(EXP1);
		setEXP(EXP2);
		return mapTaxi[demI][demJ];
	}

	else {													// tinh toa trong truong hop duoi kip taxi
		EXP1= round_up(EXP1*1.12);
		HP1= round_up(HP1*1.1);
		EXP2= round_up(EXP2 * 1.12);
		HP2= round_up(HP2 * 1.1);
		setHP(HP1);
		setHP(HP2);
		setEXP(EXP1);
		setEXP(EXP2);
		return mapSW[demI][demJ];
	}

    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
	int lengSe, ki_tu=0;
    for (int i=0; i < strlen(email); i++){
    	if (email[i] == '@'){
 			lengSe=i;
		}
	}
	char se[lengSe];
	
	for (int i=0; i < lengSe; i++){
		se[i]=email[i];
	}
	
	int sai=-1,sei=-1,sci=-1;
	for (int i=0; i < strlen(s); i++){
				
		int dem=0;
		if (s[i] == se[0] && sei == -1){
			for (int j=0; j < lengSe; j++){
				if (s[i+j] == se[j]) dem++;
			}
			
		}
		
		if (dem == lengSe && sei ==-1){
			sei=i;
		}	
		
		if (s[i] == s[i+1] && s[i] == s[i+2] && i != strlen(s)-1 && sci == -1){
			sci=i;
		}
		
		if ((s[i]=='#') || (s[i]=='%' )|| (s[i]=='$')|| (s[i]=='@' )|| (s[i]=='!')) ki_tu++;
		
		if ((((int)s[i] < 35 && (int)s[i] != 33) || 
				((int)s[i] > 37 && (int)s[i] < 48) ||
				((int)s[i] > 57 && (int)s[i] < 64) ||
				((int)s[i] > 90 && (int)s[i] < 97) ||
				((int)s[i] > 122)) && sai == -1) {
					sai=i;
				}
	}
	
	if(strlen(s) < 8) return -1;
	if(strlen(s) > 20) return -2;
	if(sei != -1) return -(300 + sei);
	if(sci != -1) return -(400 + sci);
	if(ki_tu == 0) return -5;
	if(sai != -1) return sai;
	return -10;
	
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
	int result;
    int so_luong[num_pwds] = {};
    for (int i = 0; i < num_pwds; i++) { //de so luon tu lap lai cua tu thu i
        for (int j =0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i],arr_pwds[j]) == 0) so_luong[i]++;
        }
    }

    int max = so_luong[0];
    for (int i = 0; i < num_pwds; i++) { //tim so luong tu lap lai lon nhat
        if (max < so_luong[i])	max = so_luong[i];
    }
    
    for (int i = 0; i < num_pwds; i++) {  // gan nhung chuoi co so luong khac max la ""
        if (so_luong[i] < max)	arr_pwds[i]="";
    }

    int maxleng = strlen(arr_pwds[0]);
    for (int i = 0; i < num_pwds; i++) { //tim tu co do dai dai nhat trong so cac tu co so luong lap lai nhieu nhat
        if (maxleng < strlen(arr_pwds[i])) maxleng = strlen(arr_pwds[i]);
    }

    for (int i = 0; i < num_pwds; i++) { //tu vua thoa dieu kien co so luong lap lai nhieu nhat va do dai dai nhat la tu can tim
        if (so_luong[i] == max && strlen(arr_pwds[i]) == maxleng) {
            result = i;
            break;
        }
    }
    return result;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
