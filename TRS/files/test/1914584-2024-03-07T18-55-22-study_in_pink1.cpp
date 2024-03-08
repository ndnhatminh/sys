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

/// add

bool isPerfectSquare(int n) {
    int sqrt_n = sqrt(n);
    return sqrt_n * sqrt_n == n;
}
int nearestPerfectSquare(int num) {
    int lower = num - 1;
    int upper = num + 1;

    while (true) {
        if (isPerfectSquare(lower))
            return lower;
        else if (isPerfectSquare(upper))
            return upper;
        else {
            lower--;
            upper++;
        }
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
	int D;
	if ( exp1 >600) { exp1 =600;}	
	if ( exp2 >600) { exp2 =600;}
	if ( e1 > 99 || e1 < 0 ) {return -99;} 
	if( e1==0){
		exp2= exp2 + 29;
		D = e1*3 + exp1*7;
	if ( D%2==0){
		exp1 = exp1 + D/200+1;
	}
	if ( D%2==1) {
		exp1 = exp1 - D/100;
	}

	if ( exp1 >600) { exp1 =600;}	
		if ( exp2 >600) { exp2 =600;}
	}


	if( e1==1){
		exp2= exp2 +  45;
		D = e1*3 + exp1*7;
	if ( D%2==0){
		exp1 = exp1 + D/200+1;
	}
	if ( D%2==1) {
		exp1 = exp1 - D/100;
	}
		if ( exp1 >600) { exp1 =600;}	
		if ( exp2 >600) { exp2 =600;}
	}
    	if( e1==2){
		exp2= exp2 + 75;
		D = e1*3 + exp1*7;
	if ( D%2==0){
		exp1 = exp1 + D/200+1;
	}
	if ( D%2==1) {
		exp1 = exp1 - D/100;
	}
		if ( exp1 >600) { exp1 =600;}	
		if ( exp2 >600) { exp2 =600;}
	}
    
   
	if( e1==3){
		exp2= exp2 + 29 + 45 + 75;
		D = e1*3 + exp1*7;
	if ( D%2==0){
		exp1 = exp1 + D/200+1;
	}
	if ( D%2==1) {
		
		exp1 = exp1 - D/100 ;
		
	}
		if ( exp1 >600) { exp1 =600;}	
		if ( exp2 >600) { exp2 =600;}
	}

	if ( e1 >= 4 && e1 <= 19 ){
		exp2 = exp2 + ( e1/4 + 19 )+1;
		exp1 = exp1 -e1;	
		if ( exp1 >600) { exp1 =600;}	
		if ( exp2 >600) { exp2 =600;}
	}
	if ( e1 >= 20 && e1 <= 49 ){
		exp2 = exp2 + ( e1/9 + 21 ) +1;
		exp1 = exp1 -e1;
		if ( exp1 >600) { exp1 =600;}	
		if ( exp2 >600) { exp2 =600;}	
	}
	if ( e1 >= 50 && e1 <= 65 ){
		exp2 = exp2 + ( e1/16 + 17 ) +1;
		exp1 = exp1 -e1;
		if ( exp1 >600) { exp1 =600;}	
		if ( exp2 >600) { exp2 =600;}	
	}
	if ( e1 >= 66 && e1 <= 79 ){
		exp2 = exp2 + ( e1/4 + 19 )+1;
		if ( exp2 > 200 ) {
			exp2 = exp2 + ( e1/9 + 21 ) +1;		
		}
		exp1 = exp1 -e1;
		if ( exp1 >600) { exp1 =600;}	
		if ( exp2 >600) { exp2 =600;}		
	}
	if ( e1 >= 80 && e1 <= 99 ){
		exp2 = exp2 + ( e1/4 + 19 ) +1;
		exp2 = exp2 + ( e1/9 + 21 ) +1;		
		if ( exp2 > 400 ) {
			exp2 = exp2 + ( e1/16 + 17 )+1;
			exp2 = exp2 + exp2*15/100+1;
			exp1 = exp1 -e1;
			
		}
		if ( exp1 >600) { exp1 =600;}	
		if ( exp2 >600) { exp2 =600;}
				
	}
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {


int Msum=0;


	float Pend;
	int M0= M1*50/100;
	float P1;
	int S;
	 if (isPerfectSquare(EXP1)) {
        S=EXP1;
    	}	
 	else {S=nearestPerfectSquare(EXP1);}
	 if ( EXP1 >= S) {
		P1 = 100/100	;
	}
	else { P1 =(static_cast<float>(EXP1)/S + 80 )/123; }

// road 2

	
	
if ( E2 %2 == 1) {

	while ( Msum <= M0)
	{

	if (HP1< 200){
		HP1= HP1 + HP1*30/100+1;
		M1= M1 - 150;
		Msum = Msum + 150;	
		if (Msum > M0){break;}
	cout<<HP1<<endl;
	} 
	if ( HP1 >= 200){
		HP1= HP1 + HP1*10/100+1;
		M1= M1 -70;
		Msum = Msum + 70;
		if (Msum > M0){break;}
	}
	if ( EXP1 < 400){
		M1= M1 - 200;
		EXP1 = EXP1 + EXP1*13/100+1 ;	
		Msum = Msum + 200;
		if (Msum > M0){break;}
	}
	if ( EXP1 >= 400){
		M1= M1 - 120;	
		EXP1 = EXP1 + EXP1*13/100 +1;
		Msum = Msum + 120;
		if (Msum > M0){break;}

	}

	if ( EXP1 < 300){
		M1= M1-100;
		Msum = Msum + 100;
		if (Msum > M0){break;}	
	}
	if ( EXP1 >= 300){
		M1= M1-120;
		EXP1= EXP1-EXP1*10/100 ;	
		Msum = Msum + 120;
		if (Msum > M0){break;}
	}

	}
	HP1 = HP1- HP1*17/100;
	EXP1= EXP1 + EXP1*17/100+1;
//	cout <<  " HP1: " << HP1 <<" EXP1: " << EXP1<< " M1: " <<M1<< " Msum: " <<Msum<<endl;
}

if ( E2%2 == 0) {
	if (HP1< 200){
		if ( M1 < 150 ) {
			HP1 = HP1- HP1*17/100;
			EXP1= EXP1 + EXP1*17/100+1;
			return HP1 + EXP1 + M1;			
		}
		HP1= HP1 + HP1*30/100+1;
		M1= M1 - 150;		
	} 
	if ( HP1 >= 200){
		if ( M1 < 70 ) {
			HP1 = HP1- HP1*17/100;
			EXP1= EXP1 + EXP1*17/100+1;
			return HP1 + EXP1 + M1;			
		}
		HP1= HP1 + HP1*10/100+1;
		M1= M1 -70;
	}
	if ( EXP1 < 400){
		if ( M1 < 200 ) {
			HP1 = HP1- HP1*17/100;
			EXP1= EXP1 + EXP1*17/100+1;
			return HP1 + EXP1 + M1;			
		}
		M1= M1 - 200;
		EXP1 = EXP1 + EXP1*13/100+1;	
	}	
	if ( EXP1 >= 400){
		if ( M1 < 120 ) {
			HP1 = HP1- HP1*17/100;
			EXP1= EXP1 + EXP1*17/100+1;
			return HP1 + EXP1 + M1;			
		}
		M1= M1 - 120;	
		EXP1 = EXP1 + EXP1*13/100+1;
	}
	if ( EXP1 < 300){
		if ( M1 < 100 ) {
			HP1 = HP1- HP1*17/100;
			EXP1= EXP1 + EXP1*17/100+1;
			return HP1 + EXP1 + M1;			
		}
		M1= M1-100;	
	}
	if ( EXP1 >= 300){
		if ( M1 < 120 ) {
			HP1 = HP1- HP1*17/100;
			EXP1= EXP1 + EXP1*17/100+1;
			return HP1 + EXP1 + M1;			
		}
		M1= M1-120;
		EXP1= EXP1-EXP1*10/100;	
	}
}
float P2;
 if (isPerfectSquare(EXP1)) {
        S=EXP1;
    	}	
 	else {S=nearestPerfectSquare(EXP1);}
	 if ( EXP1 >= S) {
		P2 = 100/100	;
	}
	else { P2 =(static_cast<float>(EXP1)/S + 80 )/123; }

//cout <<  " HP1: " << HP1 <<" EXP1: " << EXP1<< " M1: " <<M1<< " Msum: " <<Msum<<endl;

//  road 3
float P3;
int x;
int y;
int z;
 int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};	

x= E2/10;
y= E2%10;

if ( x==0) {
P3= P[x];
P3 =(static_cast<float>(P3))/100;
}

if( x !=0){
z=(x+y)%10;
P3=P[z];
P3 =(static_cast<float>(P3))/100;

}


//end task 2
if ( P1 == 1 && P2 == 1 && P3 == 1){
	EXP1= EXP1- EXP1*25/100;
}
else { 
	Pend =(P1+ P2 + P3)/3 ;
	
	if ( Pend < 0.5) { 
		HP1=HP1-HP1*15/100;
		EXP1= EXP1 +EXP1*15/100	+1;
		if ( EXP1 >600) {EXP1 =600;}	
		if ( HP1 > 666) {HP1=666;}

	}
	else {
		HP1=HP1-HP1*10/100;
		EXP1= EXP1 +EXP1*20/100+1	;
		if ( EXP1 >600) {EXP1 =600;}
		if ( HP1 > 666) {HP1=666;}		

	}
}	

  return HP1 + EXP1 + M1;
}





// Task 3






int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
      // Initialize matrix to represent taxi's map


    int taxiMap[10][10] = {0};

    // Fill taxi's map with scores
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            taxiMap[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // Initialize maxScore and coordinates of meeting point
    int maxScore ;
	int stopTaxi;
	
    





   
int a = 0; // sum duong
int b = 0; // sum am

      for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if ( taxiMap[i][j] > E3*2 && taxiMap[i][j] > 0 ) { a= a+ 1;}
			if ( taxiMap[i][j] < -E3 && taxiMap[i][j] < 0) { b= b+ 1;}
			
		}
	}

a= a/10 + a%10;
a= a/10 + a%10;
b= b/10+b%10;
b= b/10+b%10;
	
stopTaxi= taxiMap[a][b];
maxScore= taxiMap[a][b];


	for (int i = 1; i < 10- a ; i++) {	
		if (taxiMap[a+i][b-i] > maxScore) {
           	 maxScore = taxiMap[a+i][b-i];
        	}
	
	}

	
	for (int i = 1; a>=i  ; i++) {	
		if (taxiMap[a-i][b-i] > maxScore) {
           	 maxScore = taxiMap[a-i][b-i];
        	}
	}
	
	for (int i = 1; a>=i  ; i++) {	
		if (taxiMap[a-i][b+i] > maxScore) {
           	 maxScore = taxiMap[a-i][b+i];
        	}
	}
	for (int i = 1; i < 10- b ; i++) {
		if (taxiMap[a+i][b+i] > maxScore) {
           	 maxScore = taxiMap[a+i][b+i];
        	}
	
	}
	
	
	
	if ( maxScore < 0 ) { maxScore= -maxScore;}





if ( abs(stopTaxi) >  maxScore ){
	EXP1= EXP1 - EXP1*12/100;
	HP1= HP1 -  HP1*10/100;
	EXP2= EXP2 - EXP2*12/100;
	HP2= HP2 -  HP2*10/100;
	if ( HP1 > 666) { HP1=666;}
	if ( HP2 > 666) { HP2=666;}
	if ( EXP1 > 600) { EXP1=600;}
	if ( EXP2 > 600) { EXP2=600;}
	return stopTaxi;
}      

if ( abs(stopTaxi) <= maxScore ){
	EXP1= EXP1 + EXP1*12/100+1;
	HP1= HP1 +  HP1*10/100+1;
	EXP2= EXP2 + EXP2*12/100+1;
	HP2= HP2 +  HP2*10/100+1;
	if ( HP1 > 666) { HP1=666;}
	if ( HP2 > 666) { HP2=666;}
	if ( EXP1 > 600) { EXP1=600;}
	if ( EXP2 > 600) { EXP2=600;}
	return maxScore;
}  
   
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
   const char *at_symbol_position = strchr(email, '@');
    int se_index = at_symbol_position - email;

    // Extract se from the email
    char se[se_index + 1];
    strncpy(se, email, se_index);
    se[se_index] = '\0';

    // Check if password length is valid
    int password_length = strlen(s);
    if (password_length < 8)
        return -1;
    if (password_length > 20)
        return -2;

    // Check if password contains se
    if (strstr(s, se) != NULL)
        return -(300 + (strstr(s, se) - s));

    // Check if password contains consecutive characters
    for (int i = 0; i < password_length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
            return -(400 + i);
    }

    // Check if password contains special character
    bool contains_special_char = false;
    for (int i = 0; i < password_length; ++i) {
        if (!isalnum(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!')
            contains_special_char = true;
    }
    if (!contains_special_char)
        return -5;

    // Check if password contains invalid characters
    for (int i = 0; i < password_length; ++i) {
        if (!isalnum(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!' && s[i] != '.')
            return i;
    }

    return -10;
}

// Task 5

struct PasswordInfo {
    const char* password;
    int count;
};
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
 PasswordInfo password_info[num_pwds];

    // Khởi tạo thông tin mật khẩu và đếm số lần xuất hiện
    for (int i = 0; i < num_pwds; ++i) {
        password_info[i].password = arr_pwds[i];
        password_info[i].count = 1; // Khởi tạo đếm lần đầu
        // Kiểm tra các mật khẩu trước đó
        for (int j = 0; j < i; ++j) {
            if (strcmp(password_info[j].password, arr_pwds[i]) == 0) {
                // Nếu mật khẩu đã tồn tại, tăng số lần xuất hiện
                password_info[j].count++;
                password_info[i].count = 0; // Đánh dấu mật khẩu này không cần đếm nữa
                break;
            }
        }
    }

    // Tìm mật khẩu có số lần xuất hiện nhiều nhất và độ dài lớn nhất
    int max_count = 0;
    const char* max_password = nullptr;
    for (int i = 0; i < num_pwds; ++i) {
        if (password_info[i].count > max_count || (password_info[i].count == max_count && strlen(password_info[i].password) > strlen(max_password))) {
            max_count = password_info[i].count;
            max_password = password_info[i].password;
        }
    }

    // Tìm vị trí đầu tiên của mật khẩu đúng trong mảng arr_pwds
    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(arr_pwds[i], max_password) == 0) {
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////