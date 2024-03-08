
#include "study_in_pink1.h"

using namespace std;
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
 
	if (e1<0 || e1 >99) 	return -99;

		if (exp1 > 600) exp1 = 600;
		if (exp1 < 0) exp1 = 0;
		if (exp2 > 600) exp2 = 600;
		if (exp2 < 0) exp2 = 0;
	if (e1<=3) {
	switch (e1) {
		case 0: 
			exp2+=29;
			break;
			
		case 1:
			exp2+=45;
			break;
		case 2:
			
			exp2+=75;
			break;
		case 3:
			
			exp2 = exp2 + 29 +45 + 75;
			break;
	} 
		if (exp2 > 600) exp2 = 600;
		if (exp2 < 0) exp2 = 0;
	int D= e1 * 3 + exp1 * 7;
	if (D%2==0) {
		exp1 += D/200;
		exp1= ceil (exp1);
	}
	else {
		exp1 -= D/100;
		exp1= ceil (exp1);
	}
		if (exp1 > 600) exp1 = 600;
		if (exp1 < 0) exp1 = 0;
}
	//task 4.1.2
	else {
		switch (e1) {
			
			 case 4 ... 19:
			 	//static_cast<float>(exp2);
                exp2 += (ceil(static_cast<float>(e1)/4.0) + 19);
                break;
                
            case 20 ... 49:
            	//static_cast<float>(exp2);
                exp2 += (ceil(static_cast<float>(e1)/9.0) + 21);
                break;
                
            case 50 ... 65:
                exp2 += (ceil(static_cast<float>(e1)/16.0) + 17);
                break;
                
            case 66 ... 79:\
            //	static_cast<float>(exp2);
                exp2 += (ceil(static_cast<float>(e1)/4.0) + 19);
                	if (exp2 > 600) exp2 = 600;
					if (exp2 < 0) exp2 = 0;
                if (exp2 > 200)
                {	
            //    	static_cast<float>(exp2);
                    exp2 += (ceil(static_cast<float>(e1)/9.0) + 21);
                }
                break;
                
            case 80 ... 99:
                exp2 += (ceil(static_cast<float>(e1)/4.0) + 19);
                exp2 += (ceil(static_cast<float>(e1)/9.0) + 21);
                	if (exp2 > 600) exp2 = 600;
					if (exp2 < 0) exp2 = 0;
                if (exp2 > 400)
                {
                    exp2 += (ceil(static_cast<float>(e1)/16.0) + 17);
                    exp2 += ceil(exp2*0.15);
                }
            }
			exp1-=e1;
		if (exp1 > 600) exp1 = 600;
		if (exp1 < 0) exp1 = 0;
		if (exp2 > 600) exp2 = 600;
		if (exp2 < 0) exp2 = 0;
		
				
}

    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    	if (E2 < 0 || E2 >99 ) return -99;
		if (HP1 > 666) HP1 =666;
		if (HP1 < 0) HP1=0;
		if (M1>3000) M1 = 3000;
		if( M1 < 0) M1 = 0;
		if (EXP1 > 600) EXP1 = 600;
		if (EXP1 < 0) EXP1 = 0;
	// con duong 01
	double P1;
	double S1;
	int sqrtEXP1 = floor(sqrt(EXP1));
	if (sqrtEXP1 * sqrtEXP1	== EXP1) {
		S1=sqrtEXP1*sqrtEXP1;
	}
	else {
	int lowerSquare= (sqrtEXP1) * (sqrtEXP1) ;
	int upperSquare= (sqrtEXP1 + 1) * (sqrtEXP1 + 1);
	S1= (abs(EXP1-lowerSquare) < abs (EXP1-upperSquare)) ? lowerSquare : upperSquare;
}	
	if (EXP1 >= S1)		P1=100;
	else {
		P1=(( EXP1 / S1 +80) / 123) *100;
	}
	//con duong 02
	double limit = M1*0.5;
	int totalSpent= 0;
if (E2 % 2 !=0) {
		
		while (true) {
			//nhiemvuthu1	
			if (HP1<200) {
				HP1 = ceil(HP1 * 1.3);
				M1 -=150;
				totalSpent +=150;
				if (HP1 > 666) HP1 =666;
				if (HP1 < 0) HP1=0;
				if (M1>3000) M1 = 3000;
				if( M1 < 0) M1 = 0;
				if ( totalSpent> limit ) break; 
			}
			else {
				HP1 = ceil(HP1* 1.1);
				M1 -= 70;
				totalSpent +=70;
				if (HP1 > 666) HP1 =666;
				if (HP1 < 0) HP1=0;
				if (M1>3000) M1 = 3000;
				if( M1 < 0) M1 = 0;
				if ( totalSpent> limit ) break; 
			}
	
					
			//nhiemvuthuhai
			if (EXP1 <400) {
				M1 -= 200;
				totalSpent+=200;
				if (M1>3000) M1 = 3000;
				EXP1 =ceil(EXP1 * 1.13);
				if (EXP1 > 600) EXP1 = 600;
				if (EXP1 < 0) EXP1 = 0;
				if( M1 < 0) M1 = 0;
				if ( totalSpent> limit ) break; 
			}
			else {
				M1 -= 120; 
				totalSpent += 120;
				if (M1>3000) M1 = 3000;
				EXP1 =ceil(EXP1 * 1.13);
				if (EXP1 > 600) EXP1 = 600;
				if (EXP1 < 0) EXP1 = 0;
				if( M1 < 0) M1 = 0;
				if ( totalSpent> limit ) break; 
			}

			//nhiemvuthuba
			if (EXP1 < 300 ) {
				M1 -= 100;
				totalSpent += 100;
				if (M1>3000) M1 = 3000;
				if( M1 < 0) M1 = 0;
				EXP1 = ceil(EXP1 * 0.9);
				if (EXP1 > 600) EXP1 = 600;
				if (EXP1 < 0) EXP1 = 0;	
				if ( totalSpent> limit ) break; 
				
			}
			else {
				M1 -= 120;
				totalSpent +=120;
				if (M1>3000) M1 = 3000;
				if( M1 < 0) M1 = 0;
				EXP1 = ceil(EXP1 * 0.9);
				if (EXP1 > 600) EXP1 = 600;
				if (EXP1 < 0) EXP1 = 0;
				if ( totalSpent> limit ) break;
			}

			}
				}			
	
if (E2 % 2 == 0) {
	int tienBandau = M1;
	int tiensai =0;
	while (true) {

				//nhiem vu thu1
				if (HP1<200) {
					HP1 = ceil(HP1 * 1.3);
					M1 -= 150;
					tiensai +=150;
					if (HP1 > 666) HP1 =666;
					if (HP1 < 0) HP1=0;
					if (M1>3000) M1 = 3000;
					if( M1 < 0) M1 = 0;
					if (tiensai>= tienBandau) break;
					
				}
				else {
					HP1 =ceil(HP1 * 1.1);
					M1 -= 70;
					tiensai +=70;
					if (HP1 > 666) HP1 =666;
					if (HP1 < 0) HP1=0;
					if (M1>3000) M1 = 3000;
					if( M1 < 0) M1 = 0;
					if (tiensai>= tienBandau) break;
					
				} 
				//nhiem vu thu2
				if (EXP1 <400) {
					M1 -= 200;
					tiensai +=200;
					EXP1 =ceil(EXP1 * 1.13);
					if (EXP1 > 600) EXP1 = 600;
					if (EXP1 < 0) EXP1 = 0;
					if (M1>3000) M1 = 3000;
					if( M1 < 0) M1 = 0;
					if (tiensai>= tienBandau) break;
				}
				else {
					M1 -= 120;
					tiensai +=120;
					EXP1 =ceil(EXP1 * 1.13);
					if (EXP1 > 600) EXP1 = 600;
					if (EXP1 < 0) EXP1 = 0;
					if (M1>3000) M1 = 3000;
					if( M1 < 0) M1 = 0;
					if (tiensai>= tienBandau) break;
				}
				
				//nhiem vu thu3
				if (EXP1 < 300 ) {
					M1 -= 100;
					tiensai+=100;
					EXP1= ceil(EXP1*0.9);
					if (EXP1 > 600) EXP1 = 600;
					if (EXP1 < 0) EXP1 = 0;
					if (M1>3000) M1 = 3000;
					if( M1 < 0) M1 = 0;
					if (tiensai>= tienBandau) break;
				}
				else {
					M1 -= 120;
					tiensai+=120;
					if (M1>3000) M1 = 3000;
					if( M1 < 0) M1 = 0;
					EXP1= ceil(EXP1*0.9);
					if (EXP1 > 600) EXP1 = 600;
					if (EXP1 < 0) EXP1 = 0;
					if (tiensai>= tienBandau) break;
				} 
				break;
				}	
			}
				
				HP1 = ceil(HP1 * 0.83);
				EXP1 =ceil(EXP1 *1.17);
				if (HP1 > 666) HP1 =666;
				if (HP1 < 0) HP1=0;
				if (EXP1 > 600) EXP1 = 600;
				if (EXP1 < 0) EXP1 = 0;	
	
	double P2;
	double S2;
	int sqrtEXP2 = floor(sqrt(EXP1));
	if (sqrtEXP2 * sqrtEXP2	== EXP1) {
		S2= sqrtEXP2*sqrtEXP2;
	}
	else {
	int lowerSquareY= (sqrtEXP2) * (sqrtEXP2) ;
	int upperSquareY= (sqrtEXP2 + 1) * (sqrtEXP2 + 1);
	S2= (abs(EXP1-lowerSquareY) < abs (EXP1-upperSquareY)) ? lowerSquareY : upperSquareY;
}	
	if (EXP1 >= S2) {
		P2=100;
	}
	else {
		P2=((EXP1/S2 +80) / 123)*100;
	}
	//con duong 03
	float P3;
	int i=0;
	int P[10]={32,47,28,79,100,50,22,83,64,11};
	if (E2 <10) {
		i+=E2;
		P3 = *(P+i) / 100;
	}
	else  {
		int phannguyen= E2 /10;
		int phandu = E2 %10;
		int sum = phannguyen + phandu;
		i += (sum % 10 );
		P3 = * (P+i)/100;
	}	
	double Ptb= (P1 + P2 + P3 )/3;
	if (P1==P2&&P2==P3&&P3 == 1.0) {
		EXP1= ceil(EXP1 * 0.75);
		if (EXP1 > 600) EXP1 = 600;
		if (EXP1 < 0) EXP1 = 0;	
		return 0;
	}
	if( Ptb < 0.5) {
		HP1 = ceil(HP1*0.85);
		EXP1 = ceil(EXP1 * 1.15);
	}
	else  {
		HP1 =ceil(HP1* 0.9);
		EXP1 = ceil(EXP1*1.2);
	}
	if (EXP1 >600) {
		EXP1 = 600;
	}

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    	if (E3 < 0 || E3 > 99)  return -99;
		int i=0; int j=0;
		int swP;
  		int taxi_scores[10][10]={0};
		int x=0;int y=0;
  		for (int i = 0; i < 10; i++) {
   			 for (int j = 0; j < 10; j++) {
     			 taxi_scores[i][j] = ((E3 * j) + (i * 2)) * (i - j);
   			}
  		}

int positveNumber = 0 ;
int negativeNumber = 0;
  for (int i=0; i<10;i++) {
            for (int j=0;j<10;j++) {
                if (taxi_scores[i][j] > (E3*2)) {
                    positveNumber ++;
                }
                if (taxi_scores [i][j] < (-E3)) {
                    negativeNumber ++;
                }
            }
        }
        
        if (positveNumber >10) {
        int sumPositiveNumber=positveNumber/10 + positveNumber%10;
        	if (sumPositiveNumber>=10) {
            x= sumPositiveNumber/10 + sumPositiveNumber%10;
        	}
        	else {
        x=sumPositiveNumber;
       		}
        
    	}
    	else {
        x = positveNumber;
    	}
    
  
    if(negativeNumber >= 10) {
        int sumNegativeNumber= negativeNumber/10 + negativeNumber%10;
        if (sumNegativeNumber>10) {
           y= sumNegativeNumber/10+sumNegativeNumber%10;
        }
        else {
           y=sumNegativeNumber;
        }
    } 
    else {
        y=negativeNumber;
    }	
    int TaxiP= taxi_scores[x][y];

    int mt1[10]={0};
    int sum=x+y;
	int k=0;
    for (int i =0; i<10;i++) {
    	for(int j=0; j <10; j++) {	
    		if (i+j==sum) {
    			mt1[k]= taxi_scores[i][j];
    			k++;
			}
		}
	}
	for (int i=0; i<10; i++) {
		if (swP < mt1[i]) {
			swP= mt1[i];
		}
	} 

	int mt2[10]={0};
	while ( i>=0 && i<=9 && j >=0 && j<=9) {
		int h=0;
		mt2[h] = taxi_scores[i][j];
		h+=1;
		i+=1;
		j+=1;
	}
	while ( i>=0 && i<=9 && j >=0 && j<=9) {
		int h=0;
		mt2[h] = taxi_scores[i][j];
		h-=1;
		i-=1;
		j-=1;
	}
	for (int i=0; i<10; i++) {
		if ( swP<mt2[i]) {
			swP = mt2[i];
		}
	}
	if ( abs(TaxiP) > abs(swP) ) {
		EXP1 *= 0.88;
		EXP2 *= 0.88;
		HP1 *= 0.9;
		HP2 *= 0.9;
	}
	else {
		EXP1 *= 1.12;
		EXP2 *= 1.12;
		HP1 *= 1.1;
		HP2 *= 1.1;
	}
		if (HP1 > 666) HP1 =666;
		if (HP1 < 0) HP1=0;
		if (HP2 > 666) HP1 = 666;
		if (HP2 < 0) HP2 = 0;
		if (EXP1 > 600) EXP1 = 600;
		if (EXP1 < 0) EXP1 = 0;
		if (EXP2 > 600) EXP2 = 600;
		if (EXP2 < 0) EXP2 = 0;
    return TaxiP;
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    
    int min = 8;
    int max = 20;

    char se[100];
    int i;
    for (i = 0; email[i] != '@'; ++i) {
        se[i] = email[i];
    }
    se[i] = '\0';

    if (strlen(s) < min) return -1;
    if (strlen(s) > max) return -2;

    const char * cochuase = strstr(s, se);
    if (cochuase != nullptr) return -(300 + (cochuase - s));

    for (i = 0; s[i] != '\0'; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }

    bool hasKTDB = false;
    for (i = 0; s[i] != '\0'; ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            hasKTDB = true;
            break;
        }
    }
    if (!hasKTDB) return -5;

    for (i = 0; s[i] != '\0'; ++i) {
        if (s[i] == '^' || s[i] == '&' || s[i] == '*' || s[i] == '(' || s[i] == ')') {
            return i;
        }
    }
    return -10;




}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
     int freq[num_pwds];
    memset(freq, 0, sizeof(freq));

    
    for (int i = 0; i < num_pwds; i++) {
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                freq[i]++;
                freq[j]++;
            }
        }
    }

    
    int maxFreqIndex = -1;
    int maxFreqLength = strlen(arr_pwds[0]);

    for (int i = 1; i < num_pwds; i++) {
        int currLength = strlen(arr_pwds[i]);
        if (freq[i] > freq[maxFreqIndex] ||
            (freq[i] == freq[maxFreqIndex] && currLength > maxFreqLength)) {
            maxFreqIndex = i;
            maxFreqLength = currLength;
        }
    }

 
    return maxFreqIndex;


 //   return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
