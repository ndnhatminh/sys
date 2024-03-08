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
int roundValue(double value) {
    int decimalPlaces=6;
    const double epsilon = pow(10, -decimalPlaces);
    if (fabs(fmod(value, 1)) > epsilon) {
        return ceil(value);
    } else {
        return value; 
    }
}
double void1(int a, int b, int c){
int D=a*3 + b*7;
if (D%2==0) {  
    double d=b+D*1.00/200;
    return d;
}
	else {
	    double d=b-D*1.00/100;
	    return d;
	}
}
int checkM(int a){
    if (a >= 3000){ 
        return 3000;
    }
    if (a <= 0){ 
        a=0;
        return a;
    }
	return a;
}
int checkEXP(int a){
    if (a >= 600){ 
        return 600;
    }
    if (a <= 0){ 
        a=0;
        return a;
    }
	return a;
}
int checkHP(int a){
    if (a >= 666){ 
        return 666;
    }
    if (a <= 0){ 
        a=0;
        return a;
    }
	return a;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) 
{
//Truong hop 1.1
if (e1>99||e1<0){ return -99;}
if (e1==0){
	exp2=exp2+29;
	exp1=static_cast<int>(ceil(void1(e1,exp1,exp2)));
	} if (e1==1){ 
		exp2=exp2+45;
		exp1=static_cast<int>(ceil(void1(e1,exp1,exp2)));
		} if (e1==2){
			exp2=exp2+75;
		    exp1=static_cast<int>(ceil(void1(e1,exp1,exp2)));
				} if (e1==3){
					exp2=exp2+29+45+75;
					exp1=static_cast<int>(ceil(void1(e1,exp1,exp2)));
					
}
//Truong hop 1.2
if (e1 >= 4 && e1 <= 19){
	double EXP_2 = exp2 + e1*1.00/4 + 19;
	exp2=static_cast<int>(ceil(EXP_2));
	exp1 = exp1 - e1;
} if ( e1 >= 20 && e1 <= 49){ 
	double EXP_2 = exp2 + e1*1.00/9 + 21;
	exp2=static_cast<int>(ceil(EXP_2));
	exp1 = exp1 - e1;
} if (e1 >= 50 && e1 <= 65){
    float EXP_2 = exp2 + e1*1.00/16 + 17;
	exp2=static_cast<int>(ceil(EXP_2));
	exp1 = exp1 - e1;
} if ( e1 >= 66 && e1 <= 79 ) {
	float EXP_2 = exp2 + e1*1.00/4 + 19;
	exp2=static_cast<int>(ceil(EXP_2));
	exp1 = exp1 - e1;
		if ( exp2 > 200 ) {
			exp2 = exp2 + e1*1.00/9 + 21;}
} if ( e1 >= 80 && e1 <= 99 ){
	double EXP_21 = exp2 + e1*1.00/4 + 19;
	exp2=static_cast<int>(ceil(EXP_21));
	double EXP_2 = exp2 + e1*1.00/9 + 21;
	exp2=static_cast<int>(ceil(EXP_2));
	exp1 = exp1 - e1;
		if ( exp2 > 400 ){ 
		    double EXP_21 = exp2 + e1*1.00/16 + 17;
			exp2=static_cast<int>(ceil(EXP_21));
			double EXP_2 = exp2*1.15;
			exp2=static_cast<int>(ceil(EXP_2));
			}
}
exp1=checkEXP(exp1);
exp2=checkEXP(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
int S;
int fee=0;
float P1,P2,P3;
int m=M1/2;
if (E2<0||E2>99){return -99;}
HP1=checkHP(HP1);
EXP1=checkEXP(EXP1);
M1=checkM(M1);
S=round(sqrt(EXP1))*round(sqrt(EXP1));
if (EXP1 >= S){ P1=1; }
else { P1=((EXP1/(S*1.00))+80)/(123*1.00);}
if(S==0){S=1;}
if (E2%2 != 0){
while (true) {
	if (HP1 < 200){
			M1=M1-150;
            double changeHP1=1.3*HP1;
			HP1=static_cast<int>(ceil(changeHP1));
			HP1=checkHP(HP1);
			fee=fee+150;
			if (fee > m) break;
			} else {
			M1=M1-70;
			double changeHP1=1.1*HP1;
			HP1=static_cast<int>(ceil(changeHP1));
			fee=fee+70;
			if (fee > m) break;
			}
	if (EXP1 < 400){
			double changeEXP1=1.13*EXP1;
			EXP1=static_cast<int>(ceil(changeEXP1));
			EXP1=checkEXP(EXP1);
			M1=M1-200;
			fee=fee+200;
			if (fee > m) break;
			}else{
			double changeEXP1=1.13*EXP1;
			EXP1=static_cast<int>(ceil(changeEXP1));
			EXP1=checkEXP(EXP1);
			M1=M1-120;
			fee=fee+120;
			if (fee > m) break;
			}
	if (EXP1 < 300){
			double changeEXP1=0.9*EXP1;
			EXP1=static_cast<int>(ceil(changeEXP1));
			EXP1=checkEXP(EXP1);
			M1=M1-100;
			fee=fee+100;
			if (fee > m) break;
			}else{
			double changeEXP1=0.9*EXP1;
			EXP1=static_cast<int>(ceil(changeEXP1));
			EXP1=checkEXP(EXP1);
			M1=M1-120;
			fee=fee+120;
			if (fee > m) break;
			}
	}
}else{
while(M1>0){
	if (HP1 < 200){
			M1=M1-150;
			double changeHP1=1.3*HP1;
			HP1=static_cast<int>(roundValue(changeHP1));
			HP1=checkHP(HP1);
			fee=fee+150;
			if (M1<=0) {
			M1=0;
			break;}
			}
	else if (HP1 >=  200){ 
			M1=M1-70;
			double changeHP1=1.1*HP1;
			HP1=static_cast<int>(roundValue(changeHP1));
			HP1=checkHP(HP1);
			fee=fee+70;
			if (M1<=0) {
			M1=0;
			break;}
			}
			break;
}
while(M1>0){
	if (EXP1 < 400){
	    	double changeEXP1=1.13*EXP1;
			EXP1=static_cast<int>(roundValue(changeEXP1));
			EXP1=checkEXP(EXP1);
			M1=M1-200;
			fee=fee+200;
			if (M1<=0) {
			M1=0;
			break;}
			}
else	if (EXP1 >= 400){
			double changeEXP1=1.13*EXP1;
			EXP1=static_cast<int>(roundValue(changeEXP1));
			EXP1=checkEXP(EXP1);
			M1=M1-120;
			fee=fee+120;
			if (M1<=0) {
			M1=0;
			break;}
			}
			break;
}
while(M1>0){
	if (EXP1 < 300){
			double changeEXP1=0.9*EXP1;
			EXP1=static_cast<int>(roundValue(changeEXP1));
			EXP1=checkEXP(EXP1);
			M1=M1-100;
			fee=fee+100;
			if (M1<=0) {
			M1=0;
			break;}
			}
else	if (EXP1 >= 300){
			double changeEXP1=0.9*EXP1;
			EXP1=static_cast<int>(roundValue(changeEXP1));
			EXP1=checkEXP(EXP1);
			M1=M1-120;
			fee=fee+120;
			if (M1<=0) {
			M1=0;
			break;
			}}
		break;	
	}
}
double changeHP1=0.83*HP1;
HP1=static_cast<int>(roundValue(changeHP1));
HP1=checkHP(HP1);
double changeEXP1=1.17*EXP1;
EXP1=static_cast<int>(roundValue(changeEXP1));
EXP1=checkEXP(EXP1);
S=round(sqrt(EXP1))*round(sqrt(EXP1));
if (EXP1 >= S){ P2=1; }
else { P2=((EXP1/(S*1.00))+80)/(123*1.00);}
if(S==0){S=1;}
int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
int i;
if (E2 < 10) { 
	 i = E2;
} else {  i = E2%10+(E2-E2%10)/10;
		  i = i%10;
		 }
 P3= P[i]*1.00/100;
//cout<<P1<<"  "<<P2<<"  "<<P3<<endl;
float P_Mid;
if( P3==1 && P2==1 && P1==1){ 
double changeEXP1=0.75*EXP1;
EXP1=static_cast<int>(roundValue(changeEXP1));
EXP1=checkEXP(EXP1);
return HP1 + EXP1 + M1;
}
P_Mid=(P1+P2+P3)*1.00/3;
if (P_Mid < 0.5){ 
		double changeHP1=0.85*HP1;
        HP1=static_cast<int>(roundValue(changeHP1));
        HP1=checkHP(HP1);
		double changeEXP1=1.15*EXP1;
        EXP1=static_cast<int>(roundValue(changeEXP1));
        EXP1=checkEXP(EXP1);
        //cout<<HP1<<"  "<<EXP1<<"  "<<M1<<endl;
		return HP1+ EXP1+ M1;
		} else { 	double changeHP1=0.9*HP1;
                    HP1=static_cast<int>(roundValue(changeHP1));
                    HP1=checkHP(HP1);
					double changeEXP1=1.2*EXP1;
                    EXP1=static_cast<int>(roundValue(changeEXP1));
                    EXP1=checkEXP(EXP1);
                    //cout<<HP1<<"  "<<EXP1<<"  "<<M1<<endl;
					return HP1 + EXP1 + M1;}

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
if(E3>99||E3<0){return -99;}
int A[99];
int a=0;
int b=0;
int c=0;
int Negative=0;
int Positive=0;
for (int i=0;i<=9;i++){
	for (int j=0;j<=9;j++) { 
						A[a]=((E3*j)+(i*2))*(i-j);
					    a=a+1;
					    
						if (A[a-1] > E3*2){ b=b+1; 
						} else {
						    if (A[a-1] < -E3){c=c+1;}}
						}
					}
if (b < 10) { 
	 Positive = b;
} else {  Positive = b%10+(b-b%10)/10;
		 while(Positive>9){ Positive = Positive%10+(Positive-Positive%10)/10;}
		 }
if (c < 10) { 
	 Negative = c;
} else {  Negative = c%10+(c-c%10)/10;
		 while(Negative>9){ Negative = Negative%10+(Negative-Negative%10)/10;}
		 }
int Tong1=abs(A[Positive*10+Negative]);
int Positive1=Positive;
int Negative1=Negative;
int Tong2=A[Positive*10+Negative];
while(true){
     Positive1=Positive1-1;
     Negative1=Negative1-1;
    if(Positive1 < 0){ Positive1=Positive;Negative1=Negative;break;}
    if(Negative1 < 0){ Positive1=Positive;Negative1=Negative; break;}
    if (A[Positive1*10+Negative1] >= Tong2){Tong2 = A[Positive1*10+Negative1];};
}

while(true){
     Positive1=Positive1+1;
     Negative1=Negative1+1;
    if(Positive1 > 9){ Positive1=Positive;Negative1=Negative; break;}
    if(Negative1 > 9){ Positive1=Positive;Negative1=Negative; break;}
    if (A[Positive1*10+Negative1] >= Tong2){Tong2 = A[Positive1*10+Negative1];}
    
}

while(true){
     Positive1=Positive1+1;
     Negative1=Negative1-1;
    
    if(Positive1 > 9){ Positive1=Positive;Negative1=Negative; break;}
    if(Negative1 < 0){ Positive1=Positive;Negative1=Negative; break;}
   
    if (A[Positive1*10+Negative1] >= Tong2){Tong2 = A[Positive1*10+Negative1];}
    
}
while(true){
     Positive1=Positive1-1;
     Negative1=Negative1+1;
    if(Positive1 < 0){ Positive1=Positive;Negative1=Negative; break;}
   
    if(Negative1 > 9){ Positive1=Positive;Negative1=Negative; break;}
    if (A[Positive1*10+Negative1] >= Tong2){Tong2 = A[Positive1*10+Negative1];}
    
}
if(Tong1 > abs(Tong2) ){
    double changeEXP1=0.88*EXP1;
    EXP1=roundValue(changeEXP1);
    EXP1=checkEXP(EXP1);
    double changeEXP2=0.88*EXP2;
    EXP2=roundValue(changeEXP2);
    EXP2=checkEXP(EXP2);
    double changeHP1=0.9*HP1;
    HP1=roundValue(changeHP1);
    HP1=checkHP(HP1);
    double changeHP2=0.9*HP2;
    HP2=roundValue(changeHP2);
    HP2=checkHP(HP2);
}else {
    double changeEXP1=1.12*EXP1;
    EXP1=roundValue(changeEXP1);
    EXP1=checkEXP(EXP1);
    double changeEXP2=1.12*EXP2;
    EXP2=roundValue(changeEXP2);
    EXP2=checkEXP(EXP2);
    double changeHP1 = 1.1* HP1;
    HP1 = roundValue(changeHP1);
    HP1=checkHP(HP1);
    double changeHP2 = 1.1*HP2;
    HP2 = roundValue(changeHP2);
    HP2=checkHP(HP2);
}
if (Tong1 > abs(Tong2) ){ 
    return A[Positive*10+Negative];
}else return Tong2;

    
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
string a=s;
string b=email;
size_t selength = b.find('@');
//tim ham se
string se=b.substr(0, selength);
//kiem tra mat khau
if (a.length() < 8 ){ 
    return -1;
}
if (a.length() > 20 ){
    return -2;
}
//kiem tra email
if( selength == string::npos || b.find('@', selength + 1) != string::npos || b.length() > 100) {
    return -3;
}
//kiem tra s co chua se
size_t sePos=a.find(se);
if ( sePos != string::npos){ 
    return -(300+static_cast<int>(sePos));
}

//kiem tra 2 ki tu lien tiep giong nhau
for (size_t i = 0; i < a.length() - 2; ++i) {
        if (a[i] == a[i + 1] && a[i] == a[i + 2]) {
            return -(400 + static_cast<int>(i));
        }
}
//kiem tra ki tu dac biet
string specialChars = "@#%$!";
if(a.find_first_of(specialChars) == string::npos){
        return -5;
}
// kiem tra mat khau hop le hay khong
for (size_t i = 0; i < a.length(); ++i) {
        if (!isdigit(a[i]) && !islower(a[i]) && !isupper(a[i]) && specialChars.find(a[i]) == string::npos) {
            
				return static_cast<int>(i); 
			}else { 
				//mat khau binh thuong
				return -10;
			}
}
return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    const int MaxPASSWORD = 30;
    string uniquePasswords[MaxPASSWORD];
    int occurrences[MaxPASSWORD] = {0};
    int maxCount = 0;
    int maxLength = 0;
    int FirstPos = 0;

    for (int i = 0; i < num_pwds; ++i) {
        const string currentPassword = arr_pwds[i];
        int j;

        // Kiểm tra mật khẩu
        for (j = 0; j < MaxPASSWORD; ++j) {
            if (uniquePasswords[j] == currentPassword) {
                occurrences[j]++;
                break;
            }
        }

        // Thêm vào mảng unique nếu chưa xuất hiện
        if (j == MaxPASSWORD) {
            for (j = 0; j < MaxPASSWORD; ++j) {
                if (uniquePasswords[j].empty()) {
                    uniquePasswords[j] = currentPassword;
                    occurrences[j]++;
                    break;
                }
            }
        }

        int currentLength = static_cast<int>(currentPassword.length());

        if (occurrences[j] > maxCount || (occurrences[j] == maxCount && currentLength > maxLength)) {
            maxCount = occurrences[j];
            maxLength = currentLength;
            FirstPos = i;
        }
    }

    for (int a = 0; a < num_pwds; ++a) {
        const string currentPassword = arr_pwds[a];
        if (currentPassword == arr_pwds[FirstPos]) {
            FirstPos = a;
            return FirstPos;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////