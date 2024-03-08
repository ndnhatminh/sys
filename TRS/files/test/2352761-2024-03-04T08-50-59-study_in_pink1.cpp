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

void resetValue(int &value, int maxValue) {
    if (value > maxValue) {
        value = maxValue;
    } 
    else if (value < 0) {
        value = 0;
    } 
}

void adjustHP(int &hp) {
     resetValue(hp, 666);
}

void adjustEXP(int &exp) {
     resetValue(exp, 600);
}

void adjustMoney(int &money) {
     resetValue(money, 3000);
}

int check12(string s1, string s2) {
    auto it = s1.begin();
    auto sub_it = s2.begin();
    int index = 0; 
    while (it != s1.end()) {
        if (*it == *sub_it) {
            auto temp = it;
            while (temp != s1.end() && sub_it != s2.end() && *temp == *sub_it) {
                ++temp;
                ++sub_it;
            }
            if (sub_it == s2.end()) {
                return index; 
            }
            sub_it = s2.begin(); 
        }
        ++it;
        ++index;
    }
    return -11; 
}

int layhangdonvi(int n){
	return n % 10;
}

int rou1(float n){
    if ( (n-int(n)) <= 0.5 && (n-int(n) != 0)){
        return (n+1);
    }
    else if((n-int(n)) > 0.5) {
        return(n+0.5);
    }
    else if ((n-int(n)) == 0){
        return n;
    }
    
    return 0;
} 

int closestSquare(int n) {

    int lower_square = 0;
    int higher_square = 0;

    // Find the lower and higher square roots
    int i = 0;
    while (i * i <= n) {
        lower_square = i * i;
        i++;
    }
    int a = (i * i) - n;
    higher_square = lower_square;
    if (a >  abs(higher_square - n)) {
        return higher_square;
    }
    else {
        return i*i;
    } 
}

int tinhsodu(int E2){
    int du = 0;
    while(E2 != 0){
        du += E2%10;
        E2 /= 10;
    }
     if ((du / 10) != 0){
        return(tinhsodu(du));
    }
    else{
        return du;
    }
}

int check(int a[10][10], int n){
    int tong = 0;
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            if(a[i][j] > n){
                tong++;
            }
        }
        
    }
    return tong;
}

int check1(int a[10][10], int n){
    int tong = 0;
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            if(a[i][j] < n){
                tong++;
            }
        }
        
    }
    return tong;
}

int left(int a[10][10], int n1 , int n2){
    int a1 = n1, b = n2, max = a[n1][n2];
    while( n1 >= 0 && n2 >= 0 ) {
         if (a[n1][n2] > max) {
            max = a[n1][n2];
        }
        n1--;
        n2++;
    }
     
     
    while( a1 < 10    && b < 10 ) {
        
       if (a[a1][b] > max) {
            max = a[a1][b];
        }
        a1++;
        b--;
        
    }
    return max;
    
}

int strlen1(const char* str) {
    int length = 0;
    while (*str != '\0') {
        ++length;
        ++str;
    }
    return length;
}

int right(int a1[10][10], int n1, int n2) {

    int a = n1, b = n2, max = a1[n1][n2];
    
   
    while (n1 < 10 && n2 < 10) {
        if (a1[n1][n2] > max) {
            max = a1[n1][n2];
        }
        n1++;
        n2++;
    }

   
    n1 = a;
    n2 = b;

   
    while (a >= 0 && b >= 0) {
        if (a1[a][b] > max) {
            max = a1[a][b];
        }
        a--;
        b--;
    }
    
    return max;
}

const char* my_strstr(const char* str, const char* substr) {
    for (int i = 0; str[i] != '\0'; i++) {
        bool found = true;
        for (int j = 0; substr[j] != '\0'; j++) {
            if (str[i + j] != substr[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return  str + i;
        }
    }
    return nullptr;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 < 0 || e1 >= 100){
        return -99;
    }
    adjustEXP(exp1);
    adjustEXP(exp2);
    if( (e1 >= 0) && (e1 <= 3) ) {
    int D = e1*3 + exp1*7;
    if(e1 == 0){
        exp2 += 29;
        adjustEXP(exp2);
    }
    else if(e1 == 1) {
        exp2 += 45;
        adjustEXP(exp2);
    }

    else if(e1 == 2){
        exp2 += 75;
        adjustEXP(exp2);
    }

    else {
        exp2 += 149;
        adjustEXP(exp2);
    }
    

   

    if (D%2){
        float D3 = exp1 - D/100.0;
        exp1 = rou1(D3);
        adjustEXP(exp1);
    }
    else {
        float D3 = exp1 + D/200.0;
        exp1 = rou1(D3);
        adjustEXP(exp1);
    }
    }

    else if((e1>=4)&&(e1<= 99)) {
        float D1 = 0;
        if((e1>=4)&&(e1<= 19)){
            D1 += (e1/4.0) + 19;
            exp2 += rou1(D1);
            exp1 -= e1;
            adjustEXP(exp1);
    adjustEXP(exp2);
        }
        else if ((e1>=20)&&(e1<= 49)){
            D1 += (e1/9.0) + 21;
            exp2 += rou1(D1);
             exp1 -= e1;
             adjustEXP(exp1);
    adjustEXP(exp2);
        }
        else if ((e1>=50)&&(e1<= 65)) {
            D1 += (e1/16.0) + 17;
            exp2 += rou1(D1);
             exp1 -= e1;
             adjustEXP(exp1);
    adjustEXP(exp2);
        }

        else if ((e1>=66)&&(e1<= 79)){
             D1 += (e1/4.0) + 19;
            exp2 += rou1(D1);
            
            if (exp2 > 200) {
                exp2 += rou1((e1/9.0) + 21);
            }
             exp1 -= e1;
             adjustEXP(exp1);
    adjustEXP(exp2);
        }
        
        else if((e1>=80)&&(e1<= 99)) {
             D1 += (e1/4.0) + 19;
            exp2 += rou1(D1);
            exp2 += rou1((e1/9.0) + 21);
            adjustEXP(exp1);
    adjustEXP(exp2);
            if (exp2 > 400){
                exp2 += rou1(((e1/16.0) + 17));
                adjustEXP(exp1);
                int D2 = rou1(exp2*1.15);
                 adjustEXP(D2);

            exp2 = D2;
            
            }
            exp1 -= e1;
            adjustEXP(exp1);
            
    adjustEXP(exp2);
   
            
            
           
        }
    }

    return exp1 + exp2;
}
// Task 2

   int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    adjustEXP(EXP1);
    adjustHP(HP1);
    adjustMoney(M1);
    if (E2 < 0 || E2 >= 100){
        return -99;
    }
    // TODO: Complete this function
    float P1,P2,P3;
    int Dm = 0, Dm1 = 0;
    //4.2.1
    if (EXP1 >= closestSquare(EXP1)) {
        P1 = 100;
    }
   
    else {
     Dm = rou1(EXP1/(closestSquare(EXP1) * 1.0));
        P1 = ((Dm+80)/123.0)*100.0;
    }
 	
    //4.2.2
    int half = rou1(M1*0.5);
	int a = 1, tien = 0;
	do{
		if(E2 % 2 == 0){
			a = 0;
		}
		if(M1 <= 0 || tien > half){
			break;
		}
		if(HP1 < 200){
			tien += 150;
			M1 -= 150;
			HP1 = rou1(HP1*1.3);
		}
		else if (HP1 >= 200){
			tien += 70;
			M1 -= 70;
			HP1 = rou1(HP1*1.1);
		}
	
		adjustHP(HP1);
		adjustMoney(M1);
		if(M1 <= 0 || tien > half){
			break;
		}
		
		if(EXP1 < 400){
			tien += 200;
			M1 -= 200;
		}
		else if(EXP1 >= 400){
			tien += 120;
			M1 -= 120;
		}
		EXP1 = rou1(EXP1*1.13);
		
		adjustEXP(EXP1);
		adjustMoney(M1);
		if(M1 <= 0 || tien > half){
			break;
		}
		
		if(EXP1<300){
			tien += 100;
			M1 -= 100;
		}
		else if (EXP1 >= 300){
			M1 -= 120;
			tien += 120;
		}
		
		EXP1 = rou1(EXP1*0.9);
		adjustEXP(EXP1);
		adjustMoney(M1);
		
		}while(a == 1);
	
	
	
	
	    HP1 = rou1(HP1*0.83);
	   EXP1 = rou1(EXP1 + 0.17*EXP1);
        adjustEXP(EXP1);
        adjustHP(HP1);
        

    if (EXP1 >= closestSquare(EXP1)) {
        P2 = 100;
    }
    else {
        Dm = rou1(EXP1/(closestSquare(EXP1) * 1.0));
        P2 = ((Dm+80)/123.0)*100.0;;
    }

    adjustEXP(EXP1);
    adjustMoney(M1);

    //4.2.3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if((10-E2)>0){
        P3 = P[E2];
    }
    else {
        P3 = P[layhangdonvi(tinhsodu(E2))];
    }
    

    if (((P1+P2+P3)/3)==100){
        EXP1 = rou1(EXP1*0.75);

    }
    else if ((P1+P2+P3)/3.0 < 50.0) {
       EXP1 = rou1(EXP1*1.15);
         HP1 = rou1(HP1*0.85);
    }

     else if ((P1+P2+P3)/3.0 >= 50.0) {
        EXP1 = rou1(EXP1*1.2);
        HP1 = rou1(HP1*0.9);
    }
    
    adjustEXP(EXP1);
    adjustHP(HP1);

    return HP1 + EXP1 + M1; 

    //4.2.3
} 

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    adjustEXP(EXP1);
    adjustHP(HP1);
    adjustEXP(EXP2);
    adjustHP(HP2);
    if (E3 < 0 || E3 >= 100){
        return -99;
    }
    // TODO: Complete this function
    int a[10][10];
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            a[i][j] = ((E3*j)+(i*2))*(i-j);
        }

    }
    int diem = a[tinhsodu(check(a,E3*2))][tinhsodu(check1(a,-E3))];
    int diem2thamtu = 0;
    if (left(a, tinhsodu(check(a, E3*2)), tinhsodu(check1(a,-E3))) > right(a, tinhsodu(check(a, E3*2)), tinhsodu(check1(a,-E3)))){
       diem2thamtu = left(a, tinhsodu(check(a, E3*2)), tinhsodu(check1(a,-E3)));
   }
   else {
       diem2thamtu = right(a, tinhsodu(check(a, E3*2)), tinhsodu(check1(a,-E3)));
   }
	
   if (abs(diem)>diem2thamtu) {
    EXP1 = rou1(EXP1*0.88);
    HP1 = rou1(HP1*0.9);
    EXP2 = rou1(EXP2*0.88);
    HP2 =rou1(HP2*0.9);
    adjustEXP(EXP1);
    adjustHP(HP1);
    adjustEXP(EXP2);
    adjustHP(HP2);
    return diem;
   }

   else {
    EXP1 = rou1(EXP1*1.12);
    HP1 = rou1(HP1*1.1);
    EXP2 = rou1(EXP2*1.12);
    HP2 =rou1(HP2*1.1);
    adjustEXP(EXP1);
    adjustHP(HP1);
    adjustEXP(EXP2);
    adjustHP(HP2);
    return diem2thamtu;
   }
   
    return -1;
}


// Task 4
int checkPassword(const char* s, const char* email) {
     int len = strlen1(s);
   string s1 = s;
   string s2 = email;
    // Check password length
    if (len < 8)
        return -1; 
    if (len > 20)
        return -2; 
    
    char username[30];
    int a = 0;
    for(int i = 0;i<strlen1(email);i++){
    	if (email[i]=='@'){
    		a = i;
		}
	}
	
	for(int i = 0;i<a;i++){
		username[i] = email[i];
	}
	username[a] = '\0'; // Null terminate the username string
	string s3 = username;
	if(check12(s,s3) != -11){
	    int a1 = check12(s,s3);
		return -(300+a1);
	}
	
  //consecutive 
    for (int i = 0; i < len - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
		
            return -(400 + i); 
    }
}
   

    bool hasSpecialChar = false;
    const char* specialChars = "@#%$!";
   
    for (int i = 0; i < strlen1(s); i++) {
        for (int j = 0; j < strlen1(specialChars); j++) {
            if (s[i] == specialChars[j]) {
                hasSpecialChar = true;
                break;
            }
        }
        if (hasSpecialChar == true) {
            break;
        }
    }
    
    if (hasSpecialChar == false) {
        return -5;
    }
    
    return -10; // Password is valid

    
} 



// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int counts[num_pwds] = {0}; //dem so lan mat khau xuat hien, mang counts co kich co = arr_pwds
    for (int i = 0;i<num_pwds;i++){
        for(int j = 0;j<num_pwds;j++){
            if(arr_pwds[i] == arr_pwds[j]){ 
                counts[i]++;
            }
        }
    }
    int max_count = 0;
    int max_length = 0;
    int max_index = 0;
    for(int i = 0;i<num_pwds;i++){
        int length = strlen1(arr_pwds[i]);
        if((counts[i]>max_count) || (counts[i] == max_count && length > max_length)){
            max_length = length;
            max_count = counts[i];
            max_index = i;
        }
    }
    return max_index;

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////