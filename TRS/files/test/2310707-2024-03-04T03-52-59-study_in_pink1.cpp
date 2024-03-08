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
int firstMeet(int & EXP1, int & EXP2, int e1) {
	if(e1<0 || e1>99) return -99;
	int D;
	double e = 1.0*e1, exp1 = 1.0*EXP1, exp2 = 1.0*EXP2;
	checkVar1(exp1, exp2);
	if(e>=0 && e<=3){
		if(e==0) exp2+=29;
		else if(e==1) exp2+=45;
		else if(e==2) exp2+=75;
		else exp2+=149;
		D = e * 3 + exp1 * 7;
		if(D%2==0) exp1 += 1.0*D/200; 
		else exp1 -= 1.0*D/100; 
		roundUp(exp1);
		checkVar1(exp1, exp2);
	}
	else{
		if(e>=4 && e<=19){
			exp2+=(e/4+19); roundUp(exp2);
			exp1-=e;
		checkVar1(exp1, exp2);
		}
		else if(e>=20 && e<=49){
			exp2+=(e/9+21); roundUp(exp2);
			exp1-=e;
		checkVar1(exp1, exp2);
		}
		else if(e>=50 && e<=65){
			exp2+=(e/16+17); roundUp(exp2);
			exp1-=e;
		checkVar1(exp1, exp2);
		}
		else if(e>=66 && e<=79){
			exp2+=(e/4+19); roundUp(exp2);
			if(exp2>200) exp2+=(e/9+21); roundUp(exp2);
			exp1-=e;
			checkVar1(exp1, exp2);
		}
		else{
			exp1-=e;
			exp2+=(e/4+19); roundUp(exp2);
            checkVar1(exp1, exp2);
			exp2+=(e/9+21); roundUp(exp2);
            checkVar1(exp1, exp2);
			if(roundUp(exp2)>400){
				exp2+=(e/16+17); roundUp(exp2);
                checkVar1(exp1, exp2);
				exp2+=exp2*0.15; roundUp(exp2);
			}	
		}
		checkVar1(exp1, exp2);
	}
	checkVar1(exp1, exp2);
	EXP1=(int)exp1; EXP2=(int)exp2; 
	return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int e2) {
    // TODO: Complete this function
	if(e2>99 || e2<0) return -99;
	double hp1=1.0*HP1, exp1=1.0*EXP1, m1=1.0*M1;
    checkVar2(hp1, exp1, m1);
	int S1, S2; double temp;
	temp = 0.5*m1; roundUp(temp);
	double p[3];
//----------------------------------------------------
	if(checkSqNum(exp1)) S1=exp1;
	else S1=finalFind(exp1);
	if(exp1>=S1) p[0]=1;
	else p[0]=(exp1/S1+80)/123;

//----------------------------------------------------
	do{
		if(m1 < temp || m1 <= 0) break;
		if(hp1<200){
			hp1+= hp1*0.3; roundUp(hp1);
			m1-=150;
			checkVar2(hp1, exp1, m1);
		}
		else{
			hp1 += hp1*0.1; roundUp(hp1);
			m1-=70;
			checkVar2(hp1, exp1, m1);
		}
		if((m1 < temp && e2%2!=0) || (m1 <= 0 && e2%2==0)) break;
		if(exp1<400) m1-=200;
		else m1-=120;
		exp1+=exp1*0.13; roundUp(exp1);
		checkVar2(hp1, exp1, m1);
		if((m1 < temp && e2%2==1) || (m1 <= 0 && e2%2==0)) break;
		if(exp1<300) m1-=100;
		else m1-=120; 
		exp1-=exp1*0.1; roundUp(exp1);
		checkVar2(hp1, exp1, m1);
		if((m1 < temp && e2%2!=0) || (m1 <= 0 && e2%2==0)) break;
	}while(e2%2!=0);
		hp1-=(hp1*0.17); roundUp(hp1);
		exp1+=exp1*0.17; roundUp(exp1);
		checkVar2(hp1, exp1, m1);
	if(exp1!=0 && checkSqNum(exp1)) S2=exp1;
	else S2=finalFind(exp1);
	if(exp1>=S2) p[1]=1;
	else p[1]=(exp1/S2+80)/123;
//--------------------------------------------------------
	int p3[10]={32,47,28,79,100,50,22,83,64,11};
	if(e2<10) p[2]=1.0*p3[e2]/100;
	else p[2]=1.0*p3[totalDigits(e2)%10]/100;
	if(p[0]==1 && p[1]==1 && p[2]==1){
		exp1*=0.75;
		roundUp(exp1);
		checkVar2(hp1, exp1, m1);
	}
	else{
		double average = (p[1]+p[0]+p[2])/3;
		if(average<0.5){
			hp1-=hp1*0.15; roundUp(hp1);
			exp1+=exp1*0.15; roundUp(exp1);
			checkVar2(hp1, exp1, m1);
		}
		else{
			hp1-=hp1*0.1; roundUp(hp1);
			exp1+=exp1*0.2; roundUp(exp1);
			checkVar2(hp1, exp1, m1);
		}
	}
	checkVar2(hp1, exp1, m1);
	HP1=(int) hp1; EXP1=(int) exp1; M1=(int) m1 ;
    return HP1 + EXP1 + M1;
}
// Task 3

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int e3) {
		if(e3<0 || e3>99) return -99;
	double hp1=1.0*HP1, exp1=1.0*EXP1, hp2=1.0*HP2, exp2=1.0*EXP2;
	checkVar3(hp1, exp1, hp2, exp2);
	const int size=10; int array[size][size];
	taxiMatrix(array, size, e3);
	int ab, ord, total, sub; 
	ab = findAbscissa(array, size, e3);
	ord = findOrdinate(array, size, e3);
	total = ab + ord;
	sub = abs(ab - ord);
	int maxValue = array[ab][ord];
	for(int j=ord; j<size; j++){
		if(total-j<10 && total>=j)
		if(array[total-j][j]>maxValue) maxValue=array[total-j][j];
		if(j>=sub)
		if(array[j-sub][j]>maxValue) maxValue=array[j-sub][j];
	}
	for(int j=ord-1; j>=0; j--){
		if(total-j<10 && total>=j)
		if(array[total-j][j]>maxValue) maxValue=array[total-j][j]; 
		if(j>=sub)
		if(array[j-sub][j]>maxValue) maxValue=array[j-sub][j];
	}
	if(abs(array[ab][ord])>maxValue){
        exp1-=exp1*0.12; roundUp(exp1);
		hp1-=hp1*0.1; roundUp(hp1);
		exp2-=exp2*0.12; roundUp(exp2);
		hp2-=hp2*0.1; roundUp(hp2);
		checkVar3(hp1, exp1, hp2, exp2);
		EXP1=(int)exp1; EXP2=(int)exp2; HP1=(int)hp1; HP2=(int)hp2;
		return array[ab][ord];
	}
	else{
		exp1+=exp1*0.12; roundUp(exp1);
		hp1+=hp1*0.1; roundUp(hp1);
		exp2+=exp2*0.12; roundUp(exp2);
		hp2+=hp2*0.1; roundUp(hp2);
		checkVar3(hp1, exp1, hp2, exp2);
		EXP1=(int)exp1; EXP2=(int)exp2; HP1=(int)hp1; HP2=(int)hp2;
		return maxValue;
	} 
}

// Task 4
int checkPassword(const char * password, const char * email) {
    // TODO: Complete this function
	if(check1(password)==-10 && check2(password, email)==-10 && check3(password)==-10 && check4(password)==-10 && check5(password)==-10) return -10;
	else{
		if(check1(password)!=-10) return check1(password);
		else if(check2(password, email)!=-10) return check2(password, email);
		else if(check3(password)!=-10) return check3(password);
		else if(check4(password)!=-10) return check4(password);
		else if(check5(password)!=-10) return check5(password);
	}
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
	int temp=0, count[num_pwds];
	string str[num_pwds];
	for(int index=0; index<num_pwds; index++) str[index]=arr_pwds[index];
	for(int index=0; index<num_pwds; index++) count[index]=1;
	for(int i=0; i<num_pwds; i++)
		for(int j=0; j<num_pwds; j++)
			if(str[j]==str[i] && i!=j){
				count[i]++;
				str[j]="0";
			}
	if(findMax(str, count, num_pwds)<num_pwds && findMax(str, count, num_pwds)>=0) return findMax(str, count, num_pwds);
	else return -1;
}
double roundUp(double &number)
{
	if(round(number)>number) number=round(number);
	else if(number>round(number)) number = round(number)+1;
	else return number;
	return number;
}
int check5(const char password[])
{
	for(int index=0; index<strlen(password); index++){
		if(password[index]!='@' && password[index]!='#' && password[index]!='%' && password[index]!='$' && password[index]!='!' && (password[index]<48 || (password[index]>57 && password[index]<65) || (password[index]>90 && password[index]<97) || password[index]>122)) return index;
	}
	return -10;
}
int check4(const char password[])
{
	int count=0; 
	for(int index=0; index<strlen(password); index++){
		if(password[index]=='@' || password[index]=='#' || password[index]=='%' || password[index]=='$' || password[index]=='!')
			count++;
	}
	if(count==0) return -5;
	else return -10;
}
int check3(const char password[])
{
	for(int index=0; index<strlen(password); index++)
		if(password[index+1]==password[index] && password[index]==password[index+2]) 
			return -(400+index);
	return -10;
}
int check2(const char password[], const char email[])
{
	string temp;
	temp=(string) password;
	if(temp.find(find_se(email))>=0 && temp.find(find_se(email))<=strlen(password))
	return -(300+temp.find(find_se(email)));
	else return -10;
}
string find_se(const char email[])
{
	int count=0, length = strlen(email);
	string se, temp;
	temp=(string) email;
	while(email[count]!='@') count++;
	se = temp.erase(count, temp.length()-count);
	return se;
}
int check1(const char password[])
{
	if(strlen(password)<8) return -1;
	if(strlen(password)>20) return -2;
	else return -10;
}
int findMax(string str[], int array[], int num_pwds)
{
	int temp1, temp2, temp3, count;
	for(int index=0; index<num_pwds; index++) if(str[index]!="0") count=index+1;
	temp1 = array[0];
	for(int index=0; index<num_pwds; index++)
		if(array[index]>temp1&&str[index]!="0") temp1 = array[index];
	for(int index=0; index<count; index++)
		if(array[index]!=temp1)
			str[index]="0";
	temp2=str[0].length();
	temp3=0;
	for(int index=0; index<count; index++)
		if(str[index].length()>temp2 && str[index].length()>1){
			temp2=str[index].length();
			temp3=index;
		} 	
	return temp3;
}
bool checkSqNum(int number)
{
	if(number==pow(round(sqrt(number)),2)) return true;
	else return false;
}	
int findLeft(int number)
{ 
	if(checkSqNum(number)) return number;
	else return findLeft(number-1);
}

int findRight(int number)
{
	if(checkSqNum(number)) return number;
	else return findRight(number+1);
}
int finalFind(int number)
{
	int left, right;
	left = abs(findLeft(number)-number);
	right = abs(findRight(number)-number);
	if(left<right) return findLeft(number);
	else return findRight(number); 
}
int totalDigits(int number)
{
	int temp, total = 0;
	while(number!=0){
		temp=number%10;
		total+=temp;
		number/=10;
	}
	return total;
}
int findAbscissa(int array[][10], int size, int e)
{
	int count=0, temp;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(array[i][j]>(e*2)) count++;
		}
	}
	return totalDigits(totalDigits(count));
}
int findOrdinate(int array[][10], int size, int e)
{
	int count=0;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(array[i][j]<(-e)) count++;
		}
	}
	return totalDigits(totalDigits(count));
}
void taxiMatrix(int array[][10], int size, int e)
{
	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			array[i][j]=(e*j+i*2)*(i-j);
		}
	}
}
void checkVar2(double &hp1, double &exp1, double &m1)
{
	if(hp1>666) hp1=666;
	if(hp1<0) hp1=0;
	if(exp1<0) exp1=0;
	if(exp1>600) exp1=600;
	if(m1<0) m1=0;
	if(m1>3000) m1=3000;
}
void checkVar1(double &exp1, double &exp2)
{
	if(exp1>600) exp1=600;
	if(exp1<0) exp1=0;
	if(exp2>600) exp2=600;
	if(exp2<0) exp2=0;
}
void checkVar3(double& hp1, double &exp1, double &hp2, double &exp2)
{
	if(hp1>666) hp1=666;
	if(hp1<0) hp1=0;
	if(exp1<0) exp1=0;
	if(exp1>600) exp1=600;
    if(hp2>666) hp2=666;
	if(hp2<0) hp2=0;
	if(exp2<0) exp2=0;
	if(exp2>600) exp2=600;
}



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////