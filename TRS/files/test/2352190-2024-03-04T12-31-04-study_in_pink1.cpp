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
void checkEXP(int &a) {
    if (a > 600) a = 600;
    else if (a < 0) a= 0;
}
void checkHP(int &b) {
    if (b > 666) b= 666;
    else if (b < 0) b = 0;
}
void checkM(int &c) {
    if (c > 3000) c = 3000;
    else if (c < 0) c = 0;
}
int firstMeet(int & EXP1, int & EXP2, int E1) {
    if(E1<0 || E1>99) return -99;
    checkEXP(EXP2);
    checkEXP(EXP1);
    switch (E1) {
        case 0:
            EXP2 += 29;
            break;
        case 1:
            EXP2 += 45;
            break;
        case 2:
            EXP2 += 75;
            break;
        case 3:
            EXP2 += 29 + 45 + 75;
            break;
    }
    checkEXP(EXP2);
    checkEXP(EXP1);
    int D = E1 * 3 + EXP1 * 7;
    if(E1>=0 && E1<=3){
   	 if (D % 2 == 0)
        EXP1 = ceil((EXP1 + (float)(D) / 200)-0.000000001);
  	  else
        EXP1 = ceil((EXP1 - (float)(D) / 100)-0.000000001);
   checkEXP(EXP2);
   checkEXP(EXP1);
	}
	if (E1>=4 && E1<=19) {
		EXP2 = ceil((EXP2 + (float)(E1) / 4+19)-0.000000001);
		checkEXP(EXP2);
	}
	else if ( E1>=20 && E1<=49){
		EXP2 = ceil((EXP2 + (float)(E1) / 9+21)-0.000000001);
		checkEXP(EXP2);
	}
	else if (E1>=50 && E1<=65){
		EXP2 = ceil((EXP2 + (float)(E1) / 16+17)-0.000000001);
	  checkEXP(EXP2);
	}
	else if (E1>=66 && E1<=79){
		EXP2 = ceil((EXP2 + (float)(E1) / 4+19)-0.000000001);
		checkEXP(EXP2);
		 	if(EXP2>200){
				EXP2 = ceil((EXP2 + (float)(E1) / 9+21)-0.000000001);
		 		checkEXP(EXP2);
		 }
	}
	else if (E1>=80 && E1<=99) {
		EXP2 = ceil((EXP2 + (float)(E1) / 4+19)-0.000000001);
		EXP2 = ceil((EXP2 + (float)(E1) / 9+21)-0.000000001);
			checkEXP(EXP2);
		if (EXP2>400) {
			EXP2 = ceil((EXP2 + (float)(E1) / 16+17)-0.000000001);
				checkEXP(EXP2);
			EXP2 = ceil((EXP2 + (float)(EXP2)*0.15)-0.000000001);
		}
	}
	checkEXP(EXP2);
	if (E1>=4 && E1<=99){
		EXP1=EXP1- E1;
		checkEXP(EXP2);
        checkEXP(EXP1);
	}	
return EXP1+EXP2 ;
}
//Task 2	
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(E2<0 || E2>99) return -99;
    checkM(M1);
    checkHP(HP1);
    checkEXP(EXP1);
// Road 1
    int S1 = round(sqrt(EXP1));
    S1*=S1;
    float P1;
    if (EXP1>=S1) {
        P1 = 1.0;
    } 
    else {
        P1 = ((EXP1/S1)+80.0)/123.0;
    }
// Road 2
    int initialMoney = M1, spent = 0;
    if (M1!=0){
        if (E2%2==1) {
        while (spent<=initialMoney/2) {
            if (HP1<200) {
                HP1 = ceil((HP1*1.3)-0.00000000001);
                M1 -= 150;
                spent += 150;
            } 
            else {
                HP1 = ceil((HP1*1.1)-0.00000000001);
                M1 -= 70;
                spent += 70;//
            }
            checkHP(HP1);
            checkM(M1);
            if (spent>initialMoney/2) {
                break;
            }
            if (EXP1<400) {
                M1 -= 200;
                spent += 200;
            } 
            else {
                M1 -= 120;
                spent += 120;
            }
            EXP1 = ceil((EXP1*1.13)-0.00000000001);
            checkM(M1);
            checkEXP(EXP1);
            if (spent>initialMoney/2) {
                break;
            }
            if (EXP1<300) {
                M1 -= 100;
                spent += 100;
            } 
            else {
                M1 -= 120;
                spent += 120;
            }
            EXP1 = ceil((EXP1*0.9)-0.00000000001);
            checkM(M1);
            checkEXP(EXP1);
            if (spent>initialMoney/2) {
                break;
            }
        }
        HP1 = ceil((HP1*0.83)-0.00000000001);
        EXP1 = ceil((EXP1*1.17)-0.00000000001);
        checkHP(HP1);
        checkEXP(EXP1);
    } 
        else {
        if (M1>0) {
            if (HP1<200) {
                HP1 = ceil((HP1*1.3)-0.00000000001);
                M1 -= 150;
            } 
            else {
                HP1 = ceil((HP1*1.1)-0.00000000001);
                M1 -= 70;
            }
        }
        checkHP(HP1);
        checkM(M1);
        if (M1>0) {
            if (EXP1<400) {
                M1 -= 200;
            } else {
                M1 -= 120;
            }
            EXP1 = ceil((EXP1*1.13)-0.00000000001);
        }
        checkM(M1);
        checkEXP(EXP1);
        if (M1>0) {
            if (EXP1<300) {
                M1 -= 100;
            } 
            else {
                M1 -= 120;
            }
            EXP1 = ceil((EXP1*0.9)-0.00000000001);
        }
        checkM(M1);
        checkEXP(EXP1);
        HP1 = ceil((HP1*0.83)-0.00000000001);
        EXP1 = ceil((EXP1*1.17)-0.00000000001);
        checkHP(HP1);
        checkEXP(EXP1);
    }
    }
    else {
        HP1 = ceil((HP1*0.83)-0.00000000001);
        EXP1 = ceil((EXP1*1.17)-0.00000000001);
        checkHP(HP1);
        checkEXP(EXP1);
    }
//road 2 continued
    int S2 = (round(sqrt(EXP1)));
    S2*=S2;
    float P2;
    if (EXP1>=S2) {
        P2 = 1.0;
    } 
    else {
        P2 = ((EXP1/S2)+80.0)/123.0;
    }
// Road 3
    const int P[10] = {32,47,28,79,100,50,22,83,64,11};
    float P3;
    int a = E2%10 + E2/10;
    int i = a%10;
    P3 = P[i]/100.00;
    float P_final = (P1+P2+P3)/3.0;
// Final
    if (P1==1 && P2==1 && P3==1) {
        EXP1 = ceil((EXP1*0.75)-0.00000000001);
    } 
    else if (P_final<0.5) {
        HP1 = ceil((HP1*0.85)-0.00000000001);
        EXP1 = ceil((EXP1*1.15)-0.00000000001);
    } 
    else {
        HP1 = ceil((HP1*0.9)-0.00000000001);
        EXP1 = ceil((EXP1*1.2)-0.00000000001);
    }
    checkM(M1);
    checkHP(HP1);
    checkEXP(EXP1);
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(E3<0 || E3>99) return -99;
    checkEXP(EXP1);
    checkHP(HP2);
    checkEXP(EXP2);
    checkHP(HP1);
    int Arr[10][10]={0};
     for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            Arr[i][j] = ((E3 * j) + (i * 2) )* (i - j);
        }
    }
    int count_i = 0, count_j = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int value = ((E3 * j) + (i * 2) )* (i - j);
            if (value > E3 * 2) {
                count_i++;
            }
            else if (value < -E3) {
                count_j++;
            }
        }
    }
    int sum_i = (count_i / 10) + (count_i % 10);
    while (sum_i >= 10) {
        sum_i = (sum_i / 10) + (sum_i % 10);
    }

    int sum_j = (count_j / 10) + (count_j % 10);
    while (sum_j >= 10) {
        sum_j = (sum_j / 10) + (sum_j % 10);
    }
    int max=-99999999;
    int i=sum_i, m=sum_i, j=sum_j, n=sum_j;
    while (i>-1 && j>-1) {
        if (Arr[i][j]>max) {
            max = Arr[i][j];
        }
        i--;
        j--;
    }
    i = sum_i + 1,
    j = sum_j + 1;
    while (i<10 && j<10) {
        if (Arr[i][j]>max) {
            max = Arr[i][j];
        }
        i++;
        j++;
    }
    while (m<10 && n>-1 ) {
        if (Arr[m][n]>max) {
            max = Arr[m][n];
        }
        m++;
        n--;
    }
    m = sum_i - 1;
    n = sum_j + 1;
    while (m>-1 && n<10) {
        if (Arr[m][n]>max) {
            max = Arr[m][n];
        }
        m--;
        n++;
    }
    if ( abs(Arr[sum_i][sum_j])>max){
        HP1 = ceil((HP1*0.90)-0.00000000001);
        EXP1 = ceil((EXP1*0.88)-0.00000000001);
        HP2 = ceil((HP2*0.90)-0.00000000001);
        EXP2 = ceil((EXP2*0.88)-0.00000000001);
        checkHP(HP1);
        checkEXP(EXP1);
        checkHP(HP2);
        checkEXP(EXP2);
    }
    else {
        HP1 = ceil((HP1*1.10)-0.00000000001);
        EXP1 = ceil((EXP1*1.12)-0.00000000001);
        HP2 = ceil((HP2*1.10)-0.00000000001);
        EXP2 = ceil((EXP2*1.12)-0.00000000001);
        checkHP(HP1);
        checkEXP(EXP1);
        checkHP(HP2);
        checkEXP(EXP2);

    }
    if ( abs(Arr[sum_i][sum_j])>max) {
        return Arr[sum_i][sum_j];
    }
    else return max;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    string se;
    string EMAIL=email;
    string S=s;
    if (strlen(s)<8) {
        return -1;
    } 
    else if (strlen(s)>20) {
        return -2;
    }
    int b;
    for (int i=0; i<strlen(email); i++) {
        if (email[i]=='@') {
            b=i;
            break;
        }
    }
    se=EMAIL.substr(0,b);
    size_t find = S.find(se);
    if (find!=string::npos) {
        return -(300+find);
    }

    for (int i = 0; i < strlen(s) - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i); 
    }
    }
    int specialChar=0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            specialChar++;
            break;
        }
    }
    if (specialChar==0) {
        return -5; 
    }
    int count=0;
    int index=0;
    for (int i=0; i<strlen(s); i++) {
        if (!isalnum(s[i])) {
                if (s[i]!='!' && s[i]!='@' && s[i]!='#' && s[i]!='$' && s[i]!='%') {
                    index=i;
                    count++;
                    break;
                }
        }
    }
if (count!=0) {
        return index;
    } 
    else {
        return -10;
    }
    return -99;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxfre = 0;
    int maxlength = 0;
    int length=0;
    int countfre ;
    string most_frequent_password;
    string pwd ;
    for (int i = 0; i < num_pwds; i++) {
        pwd = arr_pwds[i];
        length = pwd.length();
        countfre = 1;

        for (int j = i + 1; j < num_pwds; j++) {
            if (arr_pwds[j] == pwd) {
                countfre++;
            }
        }

        if (( countfre> maxfre) || (countfre == maxfre && length > maxlength)) {
            most_frequent_password = pwd;
            maxfre = countfre;
            maxlength = length;
        }
    }

    for (int i = 0; i < num_pwds; ++i) {
        if (arr_pwds[i] == most_frequent_password) {
            return i;
        }
    }
return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////