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
double round_dec(double num){
	double frac;
	frac = num*100 - int(num*100);
	if (frac >= 0.5) num = (int(num*100)+1)/100.0;
	else num = (int(num*100))/100.0;
	return num;
}

int max(int a, int b){
   return a >= b ? a : b;
}

int return_exp(double exp, int &inputexp){
    inputexp = int(exp + inputexp + 0.999);
    if (inputexp > 600) inputexp = 600;
    if (inputexp < 0) inputexp = 0;
    return inputexp;
}

int return_hp(double hp, int &inputhp){
    inputhp = int(hp + inputhp + 0.999);
    if (inputhp > 666) inputhp = 666;
    if (inputhp < 0) inputhp = 0;
    return inputhp;
}

int return_m(double m, int &inputm){
    inputm = int(m + inputm + 0.999);
    if (inputm > 3000) inputm = 3000;
    if (inputm < 0) inputm = 0;
    return inputm;
}

int count(int num){
    while (num/10 != 0){
        num = num%10 + num/10;
    }
    return num;
}

void loadMatrix(int a[][10], int e)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {a[i][j] = ((e*j)+(i*2))*(i-j);}
    }
}

bool inrange(int num, int a, int b){
    if ((a <= num) && (num <= b)) return true;
    else return false;
}

bool specialChar(string s, int s_len){
    for (int i=0; i< s_len;i++){
        if ((s[i] == '@') || (s[i] == '!') || (s[i] == '#') || (s[i] == '%') || (s[i] == '$')) 
            return true;
    }
    return false;  
}

bool checkChar_Password(string s, int s_len){
    for (int i=0; i< s_len;i++){
        if (((s[i] >= '0') && (s[i] <= '9')) || ((s[i] >= 'a') && (s[i] <= 'z')) || 
        ((s[i] >= 'A') && (s[i] <= 'Z')) || (specialChar(s,s_len))) {
            return true;
        }
    }
    return false;
}

int InvalidChar(string s, int s_len){
    for (int i=0; i< s_len;i++){
        if (!(
                ((s[i] >= '0') && (s[i] <= '9')) ||
                ((s[i] >= 'a') && (s[i] <= 'z')) || 
                ((s[i] >= 'A') && (s[i] <= 'Z')) || 
                (s[i] == '@') || (s[i] == '!')   || 
                (s[i] == '#') || (s[i] == '%') || 
                (s[i] == '$')           
            )
        ) {
            return i;
        }
    }
    return -1;
}


void TASK1::situation1(){
    EXP2 = return_exp((E1/4.0+19),EXP2);
}

void TASK1::situation2(){
    EXP2 = return_exp((E1/9.0+21),EXP2);
}

void TASK1::situation3(){
    EXP2 = return_exp((E1/16.0+17),EXP2);
}

int TASK1::case1_EXP1(){
    int D = E1*3 + EXP1*7;
    if (D%2==0) EXP1 = return_exp(D/200.0, EXP1);
    else if (D%2!=0) EXP1 = return_exp(-D/100.0, EXP1);
    return EXP1;
}
void TASK1::case1(){
    switch (E1)
    {
    case 0:{
        EXP2 = return_exp(29,EXP2);
        EXP1 = case1_EXP1();
    }
        break;
    case 1:{
        EXP2 = return_exp(45,EXP2);
        EXP1 = case1_EXP1();
    }
        break;
    case 2:{
        EXP2 = return_exp(75,EXP2);
        EXP1 = case1_EXP1();
    }
        break;
    case 3:{
        EXP2 = return_exp(149,EXP2);
        EXP1 = case1_EXP1();
    }
        break;
    }
}

void TASK1::case2(){
    if (inrange(E1,4,19)) situation1();
    if (inrange(E1,20,49)) situation2();
    if (inrange(E1,50,65)) situation3();
    if (inrange(E1,66,79)){
        situation1();
        if (EXP2 > 200) situation2();
    }
    if (inrange(E1,80,99)){
        situation1();
        situation2();
        if (EXP2 > 400){
            situation3();
            EXP2 = return_exp(0.15*EXP2,EXP2);
        }
    }
    if(inrange(E1,4,99)) EXP1 = return_exp(-E1, EXP1);
}

void TASK1::setValue(int &output1, int &output2){
    output1 = EXP1;
    output2 = EXP2;
}

int TASK2::count(){
    int sum = E2; 
	int temp = 0;
    while(sum != 0){
    	    temp += sum%10;
    	    sum /= 10;
    }
    return temp%10;
}

int TASK2::findSquare(){
    int up =  pow(ceil(sqrt(EXP1)),2);
    int down = pow(floor(sqrt(EXP1)),2);
    if (up - EXP1 <  EXP1 - down) return up;
    else return down;
}

double TASK2::Find_P(){
	int a,b,S;
	double P;

    S = findSquare();
	if (EXP1 >= S)	
        P = 1;
	else 
        P = (EXP1/(S*1.0) + 80)/123;

    return P;

}

double TASK2::First_Way(){
	return Find_P();
}

void TASK2::Second_Way_case1(){
	int m = 0;
	double pay = M1/2.0;
	if (E2%2!=0){
        while (m <= pay && M1 > 0){
            if (m <= pay && M1 > 0){
		        if(HP1<200){
			        HP1 = return_hp((0.3*HP1),HP1);
			        M1 = return_m(-150,M1);
			        m += 150; 
		        }
	            else {
			        HP1 = return_hp((0.1*HP1),HP1);
			        M1 = return_m(-70,M1);
			        m += 70;
		        }
            }
        
	        //doan 2
            if (m <= pay && M1 > 0){
		        if (EXP1 < 400){
			        M1 = return_m(-200,M1);
			        m += 200;
	            }
	            else if (EXP1 >= 400){
                    M1 = return_m(-120,M1);
		            m += 120;
		        }
		        EXP1 = return_exp((0.13*EXP1),EXP1);
            }

	        //doan 3
            if (m <= pay && M1 > 0){
		        if (EXP1 < 300){
			        M1 = return_m(-100,M1);
			        m += 100;
		        }
	            else if (EXP1 >= 300){
			        M1 = return_m(-120,M1);
			        m += 120;
		        }
		        EXP1 = return_exp((-0.1*EXP1),EXP1);
            }
        }
        HP1 = return_hp((-0.17*HP1),HP1);
        EXP1 = return_exp((0.17*EXP1),EXP1);
        
    }
}

void TASK2::Second_Way_case2(){
    int m = 0;
    if (E2%2==0){
        if (M1 > 0){
		    if(HP1<200){
			    HP1 = return_hp((0.3*HP1),HP1);
			    M1 = return_m(-150,M1);
			    m += 150; 
		    }
	        else if (HP1 >=200){
			    HP1 = return_hp((0.1*HP1),HP1);
			    M1 = return_m(-70,M1);
			    m += 70;
		    }
        }
        
	    //doan 2
        if (M1 > 0){
		    if (EXP1 < 400){
			    M1 = return_m(-200,M1);
			     m += 200;
            }
	        else if (EXP1 >=400){
                M1 = return_m(-120,M1);
		        m += 120;
		    }
		    EXP1 = return_exp((0.13*EXP1),EXP1);
        }

	    //doan 3
        if (M1 > 0){
		    if (EXP1 < 300){
			    M1 = return_m(-100,M1);
			    m += 100;
		    }
	        else if (EXP1 >= 300){
			    M1 = return_m(-120,M1);
			    m += 120;
		    }
		EXP1 = return_exp((-0.1*EXP1),EXP1);
        }
        HP1 = return_hp((-0.17*HP1),HP1);
        EXP1 = return_exp((0.17*EXP1),EXP1);
	}
}

double TASK2::Second_Way(){
    Second_Way_case1();
	Second_Way_case2();       
	return Find_P();
}

double TASK2::Third_Way(){
	double P3;
    int temp = count();
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
   
    P3 = P[temp]/100.0;
	return P3;
}

void TASK2::Result(){
	double P1, P2, P3, P_avg;

	P1 = First_Way();
	P2 = Second_Way();
	P3 = Third_Way();
	P_avg = (P1+P2+P3)/3.0;

	if ((P1==1.0) && (P2==1.0) && (P3==1.0))
        return_exp((-0.25*EXP1),EXP1);
    

    else if (P_avg < 0.5){
        return_hp((-0.15*HP1),HP1);
        return_exp((0.15*EXP1),EXP1);
    }
    else {
        return_hp((-0.1*HP1),HP1);
        return_exp((0.2*EXP1),EXP1);
	}
}

void TASK2::setValue(int &output1, int &output2, int &output3){
    output1 = HP1;
    output2 = EXP1;
    output3 = M1;
}

int TASK3::Pos_i_Taxi(){
    int count1 = 0;
    for (int i = 0; i<10; i++){
        for (int j = 0; j<10; j++){
            if (mt[i][j] > (E3*2)) count1++;
        }
    }
    return count(count1);
}

int TASK3::Pos_j_Taxi(){
    int count2 = 0;
    for (int i = 0; i<10; i++){
        for (int j = 0; j<10; j++){
            if (mt[i][j] < (-E3)) count2++;
        }
    }
    return count(count2);
}

int TASK3::TaxiPoint(){
    int x = Pos_i_Taxi();
    int y = Pos_j_Taxi();
    return mt[x][y]; 
}

int TASK3::MaxPoint(){
    int max_point = TaxiPoint();
    int x = Pos_i_Taxi();
    int y = Pos_j_Taxi();

    for(int i=0;(x-i>=0) && (y-i>=0); i++)
        if (max_point < mt[x-i][y-i]) max_point = mt[x-i][y-i];
    
    for(int i=0;(x+i<10) && (y+i<10); i++)
        if (max_point < mt[x+i][y+i]) max_point = mt[x+i][y+i];

    for(int i=0;(x-i>=0) && (y+i<10); i++)
        if (max_point < mt[x-i][y+i]) max_point = mt[x-i][y+i];

    for(int i=0;(x+i<10) && (y-i>=0); i++)
        if (max_point < mt[x+i][y-i]) max_point = mt[x+i][y-i];
    
    return max_point;
}
void TASK3::Result(){
    int max_point = MaxPoint();
    int taxi_point = TaxiPoint();

    if (max_point < abs(taxi_point)){
        EXP1 = return_exp((-EXP1*0.12),EXP1);
        EXP2 = return_exp((-EXP2*0.12),EXP2);
        HP1 = return_hp((-HP1*0.1),HP1);
        HP2 = return_hp((-HP2*0.1),HP2);
    } 
    else{
        EXP1 = return_exp((EXP1*0.12),EXP1);
        EXP2 = return_exp((EXP2*0.12),EXP2);
        HP1 = return_hp((HP1*0.1),HP1);
        HP2 = return_hp((HP2*0.1),HP2);
    }
}

int TASK3::Compare(){
    int max_point = MaxPoint();
    int taxi_point = TaxiPoint();
    if(abs(max_point) >= abs(taxi_point)) return max_point;
    else return taxi_point;
}

void TASK3::SetValue(int &output1, int &output2, int &output3, int &output4, int &output5){
    output1 = HP1;
    output2 = EXP1;
    output3 = HP2;
    output4 = EXP2;
    output5 = E3;
}


// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    if ((E1 > 99) || (E1 <0)) 
        return -99;
    EXP1 = return_exp(0,EXP1);
    EXP2 = return_exp(0,EXP2);
    TASK1 task1(EXP1,EXP2,E1);
    task1.case1();
    task1.case2();
    task1.setValue(EXP1,EXP2);
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
//     // TODO: Complete this function
    //ktra e
    // return_e(E2);
	if ((E2 > 99) || (E2 <0)) 
        return -99;

    HP1 = return_hp(0,HP1);
    EXP1 = return_exp(0,EXP1);
    M1 = return_m(0,M1);
    TASK2 task2(HP1,EXP1,M1,E2);
    task2.Result();
    task2.setValue(HP1,EXP1,M1);
    return HP1 + EXP1 + M1;
    
}

// // Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if ((E3 > 99) || (E3 <0)) 
        return -99;
    HP1 = return_hp(0,HP1);
    EXP1 = return_exp(0,EXP1);
    
    HP2 = return_hp(0,HP2);
    EXP2 = return_exp(0,EXP2);

    TASK3 task3(HP1,EXP1,HP2,EXP2,E3);
    task3.Result();
    task3.SetValue(HP1,EXP1,HP2,EXP2,E3);
    return task3.Compare();
}

// Task 4
int checkPassword(const char * s, const char * email) {

    // TODO: Complete this function
    string input_s(s);
    string input_email(email);
    string se = input_email.substr(0,input_email.find('@'));
    int email_len = input_email.length();
    int s_len = input_s.length();
    
    
    bool check_length = false, check_se = false, check_invalidChar=false,
        check_consecutive = false, invalidChar = false;
    int index = 0;
    int sei = 0;
    int pos = 0;
    
    //ktra va xuat vi tri dau tien cua se
    if (input_s.find(se) != std::string::npos){
        check_se = true;
        sei = input_s.find(se);
    }
    
    //ktra co nhiu hon 2 ki tu lien tiep
    for (int i=0; i<s_len; i++){
        if ((input_s[i] == input_s[i+1]) && (input_s[i] == input_s[i+2])){
            check_consecutive = true;
            index = i;
            break;
        }
    }

    //ktra neu co ki tu khac ki tu so, chu cai va ki tu dac biet
    if (InvalidChar(input_s,s_len)!=-1 && check_invalidChar == false){
        check_invalidChar = true;
        pos = InvalidChar(input_s,s_len);
    }
    
    if (s_len < 8)
        return -1;
    if (s_len > 20)
        return -2;
    if (check_se) 
        return -(300 + sei);
    if (check_consecutive)
        return -(400 + index);
    if (specialChar(input_s,s_len) == false)
        return -5;
    if (check_invalidChar)
        return pos;

    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int cnt=0, max = 0;
    int *count = new int[num_pwds];
    for(int i=0; i<num_pwds;i++){
        cnt = 0;
        for (int j=i; j<num_pwds;j++){
            if (strcmp(arr_pwds[i],arr_pwds[j])==0){
                cnt++;
            }
        count[i] = cnt;
        }
    }

    for (int i=1; i<num_pwds; i++){
        if (count[max] < count[i]){
            max = i;
        }
        else if (count[max] == count[i]){
            if (strlen(arr_pwds[i]) > strlen(arr_pwds[max])){ 
                max = i;
            }
        }
    }
    
    delete[] count;
    return max;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////