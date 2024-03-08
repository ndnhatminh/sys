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
          if (e1 == 0) {
        exp2 += 29;
    }
    if (e1 == 1) {
        exp2 += 45;
    }
    if (e1 == 2) {
        exp2 += 75;
    }
    if (e1==3){
     exp2 += 29 + 45 + 75;
     }
     if (exp2>600){
        exp2=600;
        }
        if ((0<=e1)&&(e1<=3)){
    int D = e1 * 3 + exp1 * 7;
    if (D % 2 == 0) {
        exp1 = ceil(exp1 + (float)D / 200);
    }
    else exp1 = ceil(exp1 - (float)D / 100);
    if (exp1>600){
        exp1=600;
    }
    if(exp1<0){
        exp1=0;
    }
    }
    if (4 <= e1 && e1 <= 19) {
        exp2 =ceil(exp2 + (float)e1 / 4 + 19);
        exp1 = exp1 - e1;
    }
    if (20 <= e1 && e1 <= 49) {
        exp2 =ceil(exp2 + (float)e1 / 9 + 21);
        exp1 = exp1 - e1;
    }
    if (50 <= e1 && e1 <= 65) {
        exp2 =ceil (exp2 + (float)e1 / 16 + 17);
        exp1 = exp1 - e1;
    }
    if (66 <= e1 && e1 <= 79) {
        exp2 =ceil (exp2 + (float)e1 / 4 + 19);
            if (exp2 > 200) {
                exp2 = ceil(exp2 + (float)e1 / 9 + 21);
            }
            exp1 = exp1 - e1;
    }
    if (80 <= e1 && e1 <= 99) {
        exp2 = ceil(exp2 + (float)e1 / 4 + 19 + (float)e1 / 9 + 21);
        if (exp2 > 400) {
            exp2 = ceil(exp2 + (float)e1 / 16 + 17);
            exp2 = ceil(1.15 * (float)exp2);
        }
        exp1 = exp1 - e1;
    }
    if(exp1>600){
    exp1=600;
    }
    if(exp1<0){
        exp1=0;
        }
    if(exp2>600){
        exp2=600;
    }
    if(exp2<0){
        exp2=0;
    }
    if (0>e1||e1>99){
        return -99;
    }
    
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
   	//street 1
	float P1;
	int i = sqrt(EXP1);
	float S1 = i * i;
	float S2 = (i + 1) * (i + 1);
	if ((EXP1 - S1) < (S2 - EXP1)) {
	    P1=1;
	}
	else
		 P1 =  roundf (((80 + (float)EXP1 / S2)/123)*100)/100 ;
	//street 2
	int tongtieu = 0;
	double x = M1 * 0.5;
	int halfmoney = ceilf(x);
	if (E2 % 2 == 1) {
		while (tongtieu<M1){
			if (HP1 < 200) {
				HP1 = ceilf(1.3 * HP1);
				M1 = M1 - 150;
				tongtieu = tongtieu + 150;
			}
			else {
				HP1 = ceilf(1.1 * HP1);
				M1 = M1 - 70;
				tongtieu = tongtieu + 70;
			}
			if (HP1>666){
			HP1=666;
			}
			if (tongtieu > halfmoney || tongtieu == halfmoney) {
				HP1 = ceilf(0.83 * HP1);
				EXP1 = ceilf(1.17 * EXP1);
				break;
			}
			if (EXP1 < 400) {
				M1 = M1 - 200;
				EXP1 = ceilf(1.13 * EXP1);
				tongtieu = tongtieu + 200;
			}
			else {
				M1 = M1 - 120;
				EXP1 = ceilf(1.13 * EXP1);
				tongtieu = tongtieu + 120;
			}
			if (EXP1>600){
				EXP1=600;
			}
			if (tongtieu > halfmoney || tongtieu == halfmoney) {
				HP1 = ceilf(0.83 * HP1);
				EXP1 = ceilf(1.17 * EXP1);
				break;
			}
			if (EXP1 < 300) {
				M1 = M1 - 100;
				EXP1 = ceilf(0.9 * EXP1);
				tongtieu = tongtieu + 100;
			}
			else {
				M1 = M1 - 120;
				EXP1 = ceilf(0.9 * EXP1);
				tongtieu = tongtieu + 120;
			}
			if (tongtieu > halfmoney || tongtieu == halfmoney) {
				HP1 = ceilf(0.83 * HP1);
				EXP1 = ceilf(1.17 * EXP1);
				break;
			}
	}
}
	else {
		for (int i = 0; i < 1; i++) {
			if (HP1 < 200) {
				HP1 = ceilf(1.3 * HP1);
				M1 = M1 - 150;
			}
			else {
				HP1 = ceilf(1.1 * HP1);
				M1 = M1 - 70;
			}
			if(HP1>666){
				HP1=666;
			}
			if (M1 == 0 || M1 < 0) {
				M1=0;
				HP1 = ceilf(0.83 * HP1);
				EXP1 = ceilf(1.17 * EXP1);
				break;
			}
			if (EXP1 < 400) {
				M1 = M1 - 200;
				EXP1 = ceilf(1.13 * EXP1);
			}
			else {
				M1 = M1 - 120;
				EXP1 = ceilf(1.13 * EXP1);
			}
			if (EXP1>600){
				EXP1=600;
			}
			if (M1 == 0 || M1 < 0) {
				HP1 = ceilf(0.83 * HP1);
				EXP1 = ceilf(1.17 * EXP1);
				break;
			}
			if (EXP1 < 300) {
				M1 = M1 - 100;
				EXP1 = ceilf(0.9 * EXP1);
			}
			else {
				M1 = M1 - 120;
				EXP1 = ceilf(0.9 * EXP1);
			}
			HP1 = ceilf(0.83 * HP1);
			EXP1 = ceilf(1.17 * EXP1);
		}
	}
	if (EXP1>600){
				EXP1=600;
			}
		if(HP1>666){
				HP1=666;
			}	
		if (EXP1<0){
				EXP1=0;
			}
		if(HP1<0){
				HP1=0;
			}
	float P2;
	int j = sqrt(EXP1);
	float S3 = j * j;
	float S4 = (j + 1) * (j + 1);
	if ((EXP1 - S3) < (S4 - EXP1)) {
	 P2=1;
	}
	else
 	P2 =  roundf (((80 + (float)EXP1 / S4)/123)*100)/100 ;
	//street3
	float P3;
	float X[10] = { 0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11 };
	if (E2 / 10 == 0) {
		P3 = X[E2];
	}
	else {
		int i = (E2 / 10 + E2 % 10) % 10;
		P3 = X[i];
	}

	//tong 3 street
	if (P1 == 1 && P2 == 1 && P3 == 1) {
		EXP1 = ceilf(0.75 * EXP1);
	}
	else {
		float P = (P1 + P2 + P3) / 3;
		if (P < 0.5) {
			HP1 = ceilf(0.85 * HP1);
			EXP1 = ceilf(1.15 * EXP1);
		}
		else {
			HP1 = ceilf(0.9 * HP1);
			EXP1 = ceilf(1.2 * EXP1);
		}
	}
	if(EXP1>600){
	EXP1=600;
	}
	if(EXP1<0){
		EXP1=0;
		}
	if(HP1>666){
		HP1=666;
	}
	if(HP1<0){
		HP1=0;
	}
	if(M1>3000){
		M1=3000;
	}
	if(M1<0){
		M1=0;
	}  
	if (E2<0||99<E2){
		return -99;
	}
	return HP1+EXP1+M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    int c = 0, b = 0, hanggap, cotgap;
	int a[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (a[i][j] > E3 * 2) {
				b = b + 1;
			}
			else if (a[i][j] < -E3) {
				c = c + 1;
			}
		}
	}
	if (b / 10 == 0) {
		hanggap = b;
	}
	else {
		hanggap = (((b / 10) + (b % 10)) / 10) + (((b / 10) + (b % 10)) % 10);
	}
	if (c / 10 == 0) {
		cotgap = c;
	}
	else {
		cotgap = (((c / 10) + (c % 10)) / 10) + (((c / 10) + (c % 10)) % 10);
	}
	int max1 = 0;
	int max2 = 0;
	int max3 = 0;
	int max4 = 0;
	int max = 0;
	for (int hg = hanggap, cg = cotgap; hg > -1 && cg < 10; hg = hg - 1, cg = cg + 1) {
		if (max1 < a[hg][cg]) {
			max1 = a[hg][cg];
		}
	}
	for (int hg=hanggap, cg=cotgap; hg < 10 && cg > -1; hg = hg + 1, cg = cg - 1) {
		if (max2 < a[hg][cg]) {
			max2 = a[hg][cg];
		}
	}
	for (int hg = hanggap, cg = cotgap; hg > -1 && cg > -1; hg = hg - 1, cg = cg - 1) {
		if (max3 < a[hg][cg]) {
			max3 = a[hg][cg];
		}
	}
	for (int hg = hanggap, cg = cotgap; hg < 10 && cg < 10; hg = hg + 1, cg = cg + 1) {
		if (max4 < a[hg][cg]) {
			max4 = a[hg][cg];
		}
	}

	if (max1 < max2) {
		if (max2 < max3) {
			if (max3 < max4) {
				max = max4;
			}
			else max = max3;
		}
		else {
			if (max2 > max4) {
				max = max2;
			}
			else max = max4;
		}
	}
	else {
		if (max1 < max3) {
			if (max3 < max4) {
				max = max4;
			}
			else max = max3;
		}
		else {
			if (max1 < max4) {
				max = max4;
			}
			else max = max1;
		}
	}
	if ((abs(a[hanggap][cotgap])) > max) {
		HP1 = 0.9 * HP1;
		HP2 = 0.9 * HP2;
		EXP1 = 0.88 * EXP1;
		EXP2 = 0.88 * EXP2;
	if(EXP1>600){
	    EXP1=600;
	}
	if(EXP1<0){
		EXP1=0;
		}
	if(HP1>666){
		HP1=666;
	}
	if(HP1<0){
		HP1=0;
	}
	if(EXP2>600){
		EXP2=600;
	}
	if(EXP2<0){
		EXP2=0;
	}
	if(HP2>666){
		HP2=666;
	}
	if(HP2<0){
		HP2=0;
	}
	if (E3<0||99<E3){
		return -99;
	}
		return a[hanggap][cotgap];
	}
	else {
		HP1 = 1.1 * HP1;
		HP2 = 1.1 * HP1;
		EXP1 = 1.12 * EXP1;
		EXP2 = 1.12 * EXP2;
			if(EXP1>600){
	    EXP1=600;
	}
	if(EXP1<0){
		EXP1=0;
		}
	if(HP1>666){
		HP1=666;
	}
	if(HP1<0){
		HP1=0;
	}
	if(EXP2>600){
		EXP2=600;
	}
	if(EXP2<0){
		EXP2=0;
	}
	if(HP2>666){
		HP2=666;
	}
	if(HP2<0){
		HP2=0;
	}
	if (E3<0||99<E3){
		return -99;
	}
		return max;
	}
   // return -1;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
  string v = string (email);
	string n = string (s);
    size_t a = v.find('@'); 
    string se = v.substr(0, a);  
    size_t kiemtra = n.find(se);
    int tong =0;
    if (8 > n.length()){
    	return -1;
    	
	}
    if (n.length()>20){
    	return -2;
    	
	}     
	if (kiemtra != string::npos){
		return -(300+n.find(se));
		
		}
	for (int i = 0; i < n.length() - 1; i++) {
        if ((s[i]==s[i+1]) && (s[i]==s[i+2])) {
            return -(400+i);
            break;
        }
	}
	for (int i = 0; i < n.length() - 1; i++) {
        if ((s[i] != '!' && s[i] != '@' && s[i] != '#' && s[i] != '$'&& s[i] == '%') ){
        	tong=tong+1;}
			if(tong==(n.length()-1)){
            	return -5;
            	break;
			}
			}
		return -10;
 //   return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max = 0;
    for (int i = 0; i < num_pwds; ++i) {
        int a = 1;
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                a++;
            }
        }
        if (a > max) {
            max = a;
        }
    }
    
   char allsave[100][100];
    int countsave = 0;

    for (int i = 0; i < num_pwds; ++i) {
        int a = 1;
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                a++;
            }
        }
        if (a == max) {
            strcpy(allsave[countsave], arr_pwds[i]);
            countsave++;
        }
    }
   
   
    int maxLength = 0;
    char longest[100][100];

  
      for(int i = 0; i < countsave; ++i) {
        int len = strlen(allsave[i]);
        if (len > maxLength) {
            maxLength = len;
            strcpy(longest[0], allsave[i]);
        }
		}

      for (int j = 0; j < num_pwds; ++j) {
         if (strcmp(arr_pwds[j],longest[0])==0) {
         return j;
          }
   }	
    return 0;

}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////