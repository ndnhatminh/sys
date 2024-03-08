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
int firstMeet(int& exp1, int& exp2, int e1) {
	// TODO: Complete this function
	if (e1 < 0 || e1>99) return -99;
	if(exp1>600) exp1=600;
	if(exp1<0) exp1=0; 
	if(exp2>600) exp2=600;
	if(exp2<0) exp2=0; 
	if (e1 >= 0 && e1 <= 3) {
		if (e1 == 0) exp2 += 29;
		else if (e1 == 1) exp2 += 45;
		else if (e1 == 2) exp2 += 75;
		else if (e1 == 3) exp2 = exp2 + 29 + 45 + 75; 
		if (exp2 > 600)exp2 = 600;
		if (exp2 < 0) exp2 = 0;
		int D = e1 * 3 + exp1 * 7;  
		if (D % 2 == 0) exp1 = ceil(float(exp1 + D / (200 * 1.0)));
		else exp1 = ceil(float(exp1 - D / (100 * 1.0))); 
		if (exp1 > 600) exp1 = 600;
		if (exp1 < 0) exp1 = 0;
	}
	else if (e1 >= 4 && e1 <= 99) {
		if (e1 >= 4 && e1 <= 65) {
			if (e1 <= 19 && e1 >= 4) exp2 =ceil(float( exp2+ e1 / (4 * 1.0) + 19)); 
			else if (e1 >= 20 && e1 <= 49) exp2= ceil(float(exp2+ e1 / (9 * 1.0) + 21)); 
			else if (e1 >= 50 && e1 <= 65) exp2= ceil(float(exp2+ e1 / (16 * 1.0) + 17)); 
			if (exp2> 600) exp2= 600; 
			if (exp2< 0) exp2= 0; 
		}
		else if (e1 >= 66 && e1 <= 79) {
			exp2=ceil(float(exp2+ e1 / (4 * 1.0) + 19));
			if (exp2> 600) exp2= 600; 
			if (exp2< 0) exp2= 0; 
			if (exp2> 200) { 
				exp2= ceil(float(exp2+ e1 / (9 * 1.0) + 21));  
				if (exp2> 600) exp2= 600; 
				if (exp2< 0) exp2= 0; 
			}
		}
		else if (e1 >= 80 && e1 <= 99) {
			exp2=ceil(float( exp2+ e1 / (4 * 1.0) + 19));
			if (exp2> 600) exp2= 600;
			if (exp2< 0) exp2= 0;
			exp2= ceil(float(exp2+ e1 / (9 * 1.0) + 21)); 
			if (exp2> 600) exp2= 600;
			if (exp2< 0) exp2= 0;
			if (exp2> 400) {
				exp2= ceil(float(exp2+ e1 / (16 * 1.0) + 17));
				if (exp2> 600) exp2= 600; 
				if (exp2< 0) exp2= 0; 
				exp2 = ceil(float(exp2 * 1.15));  
				if (exp2> 600) exp2= 600;
				if (exp2< 0) exp2= 0;
			}
		}
		exp1 -= e1;
        if (exp1 < 0) exp1 = 0; 
	}
	return exp1 + exp2; 
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2>99) return -99;
    if(M1>3000) M1=3000; 
    if(M1<0) M1=0; 
    if(EXP1>600) EXP1=600;
    if(EXP1<0) EXP1=0;
    if(HP1>666)HP1=666;
    if(HP1<0)HP1=0; 
    float p[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int S;
    int count = 0;
    float P = 0;
    float temp = EXP1;
    S = round(sqrt(temp)) * round(sqrt(temp));
    if (S > EXP1) P = ((EXP1 * 1.0) / S + 80) / 123; 
    else {
        P += 1; 
        count++;
    }
    if (E2 % 2 != 0&&M1!=0) {
        float startM=M1/(2*1.0);      
        float fee = 0;  
        while (fee <= startM) {
            if (HP1 < 200) {
                HP1 = ceil(float(HP1 * 1.3)); 
                if (HP1 > 666) HP1 = 666;
                if (HP1 < 0)HP1 = 0;
                M1 -= 150;
                fee += 150;
                if(M1>3000) M1=3000; 
    			if(M1<0) M1=0; 
                if (fee > startM) break;
            }
            else {
                HP1 = ceil(float(HP1 * 1.1)); 
                if (HP1 > 666) HP1 = 666;
                if (HP1 < 0)HP1 = 0;
                M1 -= 70;
                fee += 70;
                if(M1>3000) M1=3000; 
    			if(M1<0) M1=0; 
                if (fee > startM) break;
            }
            if (EXP1 < 400) {
                EXP1 = ceil(float(EXP1 * 1.13)); 
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
                M1 -= 200;
                fee += 200;
                if(M1>3000) M1=3000; 
    			if(M1<0) M1=0; 
                if (fee > startM) break;
            }
            else {
                EXP1 = ceil(float(EXP1 * 1.13)); 
                if (EXP1 > 600) EXP1 = 600; 
                if (EXP1 < 0) EXP1 = 0;
                M1 -= 120;
                fee += 120;
                if(M1>3000) M1=3000; 
    			if(M1<0) M1=0; 
                if (fee > startM) break;
            }
            if (EXP1 < 300) {
                EXP1 = ceil(float(EXP1 * 0.9)); 
                if (EXP1 > 600) EXP1 = 600; 
                if (EXP1 < 0) EXP1 = 0;
                M1 -= 100;
                fee += 100;
                if(M1>3000) M1=3000; 
    			if(M1<0) M1=0; 
                if (fee > startM) break;
            }
            else {
                EXP1 = ceil(float(EXP1 * 0.9));  
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
                M1 -= 120;
                fee += 120;
                if(M1>3000) M1=3000; 
    			if(M1<0) M1=0; 
                if (fee > startM) break;
            }
        }
    }
    else if(E2 % 2== 0&&M1!=0) { 
        for (int i = 1; i <= 1; i++) {
            if (HP1 < 200) {
                HP1 = ceil(float(HP1 * 1.3));   
                if (HP1 > 666) HP1 = 666;
                if (HP1 < 0)HP1 = 0;
                M1 -= 150;
                if(M1>3000) M1=3000; 
    			if(M1<0) M1=0; 
                if (M1 <= 0) break;
            }
            else {
                HP1 = ceil(float(HP1 * 1.1));  
                if (HP1 > 666) HP1 = 666; 
                if (HP1 < 0)HP1 = 0;
                M1 -= 70;
                if(M1>3000) M1=3000; 
    			if(M1<0) M1=0; 
                if (M1 <= 0) break;
            }
            if (EXP1 < 400) {
                EXP1 = ceil(float(EXP1 * 1.13));  
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
                M1 -= 200;
                if(M1>3000) M1=3000; 
    			if(M1<0) M1=0; 
                if (M1 <= 0) break;
            }
            else {
                EXP1 = ceil(float(EXP1 * 1.13)); 
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
                M1 -= 120;
                if(M1>3000) M1=3000; 
    			if(M1<0) M1=0; 
                if (M1 <= 0) break;
            }
            if (EXP1 < 300) {
                EXP1 = ceil(float(EXP1 * 0.9));   
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
                M1 -= 100;
                if(M1>3000) M1=3000; 
    			if(M1<0) M1=0; 
                if (M1 <= 0) break;
            }
            else {
                EXP1 = ceil(float(EXP1 * 0.9));  
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
                M1 -= 120;
                if(M1>3000) M1=3000; 
    			if(M1<0) M1=0; 
                if (M1 <= 0) break;
            }
        }
    }
    if(M1>3000) M1=3000; 
    if(M1<0) M1=0; 
    EXP1 = ceil(float(EXP1 * 1.17)); 
    HP1 = ceil(float(HP1 * 0.83)); 
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0)HP1 = 0;
    temp = EXP1;
    S = round(sqrt(temp)) * round(sqrt(temp));
    if (S > EXP1) P += ((EXP1 * 1.0) / S + 80) / 123;
    else {
        P += 1;
        count++;
    }
    if (E2 >= 0 && E2 <= 9) {
        P += p[E2] / 100;
        if (p[E2] / 100 == 1.0) count++;
    }
    else {
        P += p[(E2 % 10 + E2 / 10) % 10] / 100;
        if (p[(E2 % 10 + E2 / 10) % 10] / 100 == 1.0) count++;  
    }
    if (count == 3) {
        EXP1 = ceil(float(EXP1 * 0.75)); 
        if (EXP1 > 600) EXP1 = 600;
        if (EXP1 < 0) EXP1 = 0;
    }
    else {
        if (P / 3 < 0.5) {
            EXP1 = ceil(float(EXP1 * 1.15));   
            HP1 = ceil(float(HP1 * 0.85));  
            if (EXP1 > 600) EXP1 = 600;
            if (EXP1 < 0) EXP1 = 0;
            if (HP1 > 666) HP1 = 666;
            if (HP1 < 0)HP1 = 0;
        }
        else {
            EXP1 = ceil(float(EXP1 * 1.2)); 
            HP1 = ceil(float(HP1 * 0.9));  
            if (EXP1 > 600) EXP1 = 600;
            if (EXP1 < 0) EXP1 = 0;
            if (HP1 > 666) HP1 = 666;
            if (HP1 < 0)HP1 = 0;
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0||E3>99) return -99;  
    if(EXP1>600) EXP1=600;
    if(EXP1<0) EXP1=0;
    if(HP1>666)HP1=666;
    if(HP1<0)HP1=0;
    if(EXP2>600)EXP2=600; 
    if(EXP2<0)EXP2=0; 
    if(HP2>666)HP2=666;
    if(HP2<0)HP2=0;
    int arr[10][10] = {0}; 
    int pos=0,neg=0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = ((E3 * j + i * 2)) * (i - j);    
            if (arr[i][j] > E3 * 2) pos++; 
            if (arr[i][j] < -E3) neg++;    
        } 
    }
    while (neg >= 10) {
        neg = neg / 10 + neg % 10; 
    }
    while (pos >= 10) {
        pos = pos / 10 + pos % 10; 
    } 
    int pointSW=INT_MIN; 
    int i = pos, j = neg;  
    while (i >= 0&&j>=0) {
        pointSW = max(pointSW, arr[i][j]);
        i--;
        j--;
    }
    i = pos;
    j = neg;  
    while (i < 10&&j<10) {  
        pointSW = max(pointSW, arr[i][j]); 
        i++;  
        j++; 
    }
    i = pos; 
    j = neg; 
    while (i < 10&&j>=0) {
        pointSW = max(pointSW, arr[i][j]); 
        i++;
        j--; 
    }
    i = pos;
    j = neg; 
    while (j < 10&&i>=0) { 
        pointSW = max(pointSW, arr[i][j]); 
        j++;
        i--; 
    }
    pointSW=abs(pointSW);  
    if (pointSW >= abs(arr[pos][neg])) {   
        EXP1=ceil(float(EXP1*1.12)); 
        HP1=ceil(float(HP1*1.1)); 
        EXP2=ceil(float(EXP2 * 1.12)); 
        HP2=ceil(float(HP2*1.1)); 
        if (EXP1 > 600) EXP1 = 600;
        if (EXP2 > 600) EXP2 = 600;
        if (HP1 > 666)HP1 = 666;
        if (HP2 > 666)HP2 = 666;
        if (EXP1 < 0)EXP1 = 0;
        if (EXP2 < 0)EXP2 = 0;
        if (HP1 < 0)HP1 = 0;
        if (HP2 < 0)HP2 = 0; 
        return pointSW; 
    }
    else {
        EXP1=ceil(float(EXP1 * 0.88)) ; 
        HP1=ceil(float(HP1 *0.9)); 
        EXP2=ceil(float(EXP2 * 0.88));
        HP2=ceil(float(HP2 * 0.9));  
        if (EXP1 > 600) EXP1 = 600; 
        if (EXP2 > 600) EXP2 = 600; 
        if (HP1 > 666)HP1 = 666; 
        if (HP2 > 666)HP2 = 666; 
        if (EXP1 < 0)EXP1 = 0; 
        if (EXP2 < 0)EXP2 = 0; 
        if (HP1 < 0)HP1 = 0;
        if (HP2 < 0)HP2 = 0; 
        return arr[pos][neg]; 
    } 
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    int lens = strlen(s);
    if (lens < 8) return -1;  
    if (lens > 20) return -2;  
    int lenmail = strlen(email); 
    string strmail=""; 
    for (int i = 0; i < lenmail; i++) {  
        if (email[i] == '@') {  
            break;
        }
        strmail += email[i];         
    } 
    if (strmail.length() <= lens) {     
        for (int i = 0; i <= lens - strmail.length(); i++) {
            string strs = ""; 
            for (int j = i; j < i+strmail.length(); j++) {  
                strs += s[j];  
            }
            if (strs == strmail) return -(300 + i); 
        }
    }
    int position=0; 
    int vipham=lens;  
    bool check=false;   
    for (int i = 0; i < lens; i ++ ) {          
        if (i > 0 && s[i] == s[i - 1]) {
     		if (i + 1 != lens && s[i + 1] == s[i]) return -(400 + i - 1); 
 		} 
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') check = true;
        else if (!isalpha(s[i])&&!isdigit(s[i])&& s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') vipham = min(vipham, i);
    }
    if (check == false) return -5; 
    if (vipham != lens)
       return vipham;
    else return -10; 
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function 
    int maxc=0;
    int x = 0; 
    int maxlen = 0; 
    for (int i = 0; i < num_pwds; i++) { 
        int crc = 0;  
        int crlen = strlen(arr_pwds[i]);   
        for (int j = i; j < num_pwds; j++) {  
            if (strcmp(arr_pwds[i],arr_pwds[j])==0) crc++;   
        }
        if (maxc < crc) {
            maxc = crc; 
            x = i; 
            maxlen = crlen; 
        }
        else if (maxc == crc) {
            if (maxlen < crlen) {
                maxlen = crlen;
                x = i;
            }
        }
    }
    return x;  
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////

