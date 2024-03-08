#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

void limit_exp(int &exp){
    if(exp>600){
        exp=600;
    }
    if(exp<0){
        exp=0;
    }
}

void limit_hp(int &hp){
    if(hp<0){
        hp=0;
    }
    if(hp>666){
        hp=666;
    }
}

void limit_money(int &m){
    if(m>3000){
        m=3000;
    }
    if(m<0){
        m=0;
    }
}

// Task 1

void firstMeet_case1(int &exp1, int &exp2, int e1){
    if(e1==0){
        exp2+=29;
        limit_exp(exp2);
    }
    if(e1==1){
        exp2+=45;
        limit_exp(exp2);
    }
    if(e1==2){
        exp2+=75;
        limit_exp(exp2);
    }
    if(e1==3){
        exp2+=29+45+75;
        limit_exp(exp2);
    }
    int D=e1*3 + exp1*7;
    if(D%2==0){
        exp1+=ceil(D/200.0-0.001);
        limit_exp(exp1);
    }
    else{
        exp1=ceil(exp1-D/100.0-0.001);
        limit_exp(exp1);
    }
}

void firstMeet_case2(int &exp1, int &exp2, int e1){
    if(e1>=4 && e1<=19){
        exp2+=ceil(e1/4.00 + 19-0.001);
        limit_exp(exp2);
    }
    if(e1>=20 &&  e1<=49){
        exp2+=ceil(e1/9.00 + 21-0.001);
        limit_exp(exp2);
    }
    if(e1>=50 && e1<=65){
        exp2+=ceil(e1/16.00 + 17-0.001);
        limit_exp(exp2);
    }
    if(e1>=66 && e1<=79){
        exp2+=ceil(e1/4.00 + 19-0.001);
        limit_exp(exp2);
        if(exp2>200){
            exp2+=ceil(e1/9.00 + 21-0.001);
            limit_exp(exp2);
        }
    }
    if(e1>=80 && e1<=99){
        exp2+=ceil(e1/4.00 + 19-0.001);
        limit_exp(exp2);
        exp2+=ceil(e1/9.00 + 21-0.001);
        limit_exp(exp2);
        if(exp2>400){
            exp2+=ceil(e1/16.00 + 17-0.001);
            limit_exp(exp2);
            exp2+=ceil(0.15*exp2-0.001);
            limit_exp(exp2);
        }
    }
    exp1-=e1;
    limit_exp(exp1);
}

int firstMeet(int & exp1, int & exp2, int e1)
{
    limit_exp(exp1);
	limit_exp(exp2);
    if(e1<0 || e1>99){
    	return -99;
	}
	if(e1>=0 && e1<=3){
		firstMeet_case1(exp1, exp2, e1);
	}
	if(e1>=4 && e1<=99){
		firstMeet_case2(exp1, exp2, e1);
	}
    return exp1 + exp2;
}


// Task 2

double percentage(int exp){
	if(exp==0){
		return 100;
	}
    int a=ceil((float)sqrt(exp)-0.001);
    int S;
    if((a*a-exp) <= (exp-(a-1)*(a-1))){
        S=a*a;
    }
    else{
        S=(a-1)*(a-1);
    }
    if(exp>=S){
        return 100;
    }
    else{
        int P=((exp/S + 80)/123.00)*100;
        return P;
    }
}

void traceLuggage_1(int exp1, double &P1){
    P1=percentage(exp1);
}

void update_in4(int &hp1, int &exp1, double &P2){
    hp1=ceil((float)hp1*0.83000-0.0001);
    limit_hp(hp1);
    exp1=ceil((float)exp1*1.17-0.0001);
    limit_exp(exp1);
    P2=percentage(exp1);
}

void traceLuggage_2(int &hp1, int &exp1, int &m1, int e2, double &P2, int &count, int copy_m1){
    if(hp1 < 200){
        hp1=ceil((float)hp1*1.3-0.0001);
        limit_hp(hp1);
        m1-=150;
        count+=150;
        limit_money(m1);
        if(count > copy_m1 && e2%2==1){
            update_in4(hp1, exp1, P2);
            return;
        }
        if(m1<=0 && e2%2==0){
            update_in4(hp1, exp1, P2);
            return;
        }
    }
    else if(hp1>=200){
        hp1=ceil((float)hp1*1.1-0.0001);
        limit_hp(hp1);
        m1-=70;
        count+=70;
        limit_money(m1);
        if(count > copy_m1 && e2%2==1){
            update_in4(hp1, exp1, P2);
            return;
        }
        if(m1<=0 && e2%2==0){
            update_in4(hp1, exp1, P2);
            return;
        }
    }
    if(exp1<400){
        m1-=200;
        count+=200;
        limit_money(m1);
        exp1=ceil((float)exp1*1.13-0.0001);
        limit_exp(exp1);
        if(count>copy_m1 && e2%2==1){
            update_in4(hp1, exp1, P2);
            return;
        }
        if(m1<=0 && e2%2==0){
            update_in4(hp1, exp1, P2);
            return;
        }
    }
    else if(exp1>=400){
        m1-=120;
        count+=120;
        exp1=ceil((float)exp1*1.13-0.0001);
        limit_exp(exp1);
        limit_money(m1);
        if(count > copy_m1 && e2%2==1){
            update_in4(hp1, exp1, P2);
            return;
        }
        if(m1<=0 && e2%2==0){
            update_in4(hp1, exp1, P2);
            return;
        }
    }
    if(exp1<300){
        m1-=100;
        count+=100;
        limit_money(m1);
        exp1=ceil((float)exp1*0.9-0.0001);
        limit_exp(exp1);
        if(count > copy_m1 && e2%2==1){
            update_in4(hp1, exp1, P2);
            return;
        }
        if(count <= copy_m1 && e2%2==1){
            traceLuggage_2(hp1, exp1, m1, e2, P2, count, copy_m1);
        }
        if(m1<=0 && e2%2==0){
            update_in4(hp1, exp1, P2);
            return;
        }
    }
    else if(exp1>=300){
        m1-=120;
        count+=120;
        limit_money(m1);
        exp1=ceil((float)exp1*0.9-0.0001);
        limit_exp(exp1);
        if(count > copy_m1 && e2%2==1){
            update_in4(hp1, exp1, P2);
            return;
        }
        if(count <= copy_m1 && e2%2==1){
            traceLuggage_2(hp1, exp1, m1, e2, P2, count, copy_m1);
        }
        if(m1<=0 && e2%2==0){
            update_in4(hp1, exp1, P2);
            return;
        }
    }
    if(m1>0 && e2%2==0){
        update_in4(hp1, exp1, P2);
        return;
    }
}

int sum_number(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        sum/=10;
    }
    if(sum>=10){
        sum_number(sum);
    }
    return sum;
}

void traceLuggage_3(int e2, double &P3){
    double arr[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int sum=0;
    while(e2>0){
        sum+=e2%10;
        e2/=10;
    }
    int pos=sum%10;
    P3=arr[pos];
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
    if(E2>99 || E2<0){
    	return -99;
	}
	limit_exp(EXP1);
	limit_hp(HP1);
	limit_money(M1);
	double P1, P2, P3;
	int P;
	traceLuggage_1(EXP1, P1);
	int count=0;
	int copy_m1=ceil((float)M1/2.00);
	traceLuggage_2(HP1, EXP1, M1, E2, P2, count, copy_m1);
	traceLuggage_3(E2, P3);
	if(P1==100 && P2==100 && P3==100){
		EXP1=ceil((float)EXP1*0.75-0.0001);
		limit_exp(EXP1);
		return HP1 + EXP1 + M1;
	}
	P=ceil((float)(P1+P2+P3)/3.00);
	if(P<50){
		HP1=ceil((float)HP1*0.85-0.0001);
		limit_hp(HP1);
		EXP1=ceil((float)EXP1*1.15-0.0001);
		limit_exp(EXP1);
		return HP1 + EXP1 + M1;
	}
	if(P>=50){
		HP1=ceil((float)HP1*0.9-0.0001);
		limit_hp(HP1);
		EXP1=ceil((float)EXP1*1.2-0.0001);
		limit_exp(EXP1);
		return HP1 + EXP1 + M1;
	}
    return HP1 + EXP1 + M1;
}

// Task 3

int find_point(int n){
	int sum_n=0;
    while(n>0){
        sum_n+=n%10;
        n/=10;
    }
    if (sum_n>9){
    	return find_point(sum_n);
	}
	return sum_n;
}
void meet_point(int arr[][10], int e3, int &i, int &j){
    int xi=0; int yj=0;
    for(int k=0; k<10; k++){
        for(int h=0; h<10; h++){
            if(arr[k][h]>e3*2){
                xi++;
            }
            if(arr[k][h]<-e3){
                yj++;
            }
        }
    }
    i=find_point(xi);
    j=find_point(yj);
}
void crime_point(int arr[][10], int e3){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            arr[i][j]=((e3*j)+(i*2))*(i-j);
        }
    }
}

int Sh_Wa_point(int arr[][10], int i, int j){
	int max=arr[i][j];
	for(int a=i, b=j; a>=0, b<=9; a--, b++){
		if(a<0 || b>9){
			break;
		}
		if(arr[a][b]>max){
			max=arr[a][b];
		}
	}
	for(int a=i, b=j; a<=9, b>=0; a++, b--){
		if(a>9 || b<0){
			break;
		}
		if(arr[a][b]>max){
			max=arr[a][b];
		}
	}
	for(int a=i, b=j; a>=0, b>=0; a--, b--){
		if(a<0 || b<0){
			break;
		}
		if(arr[a][b]>max){
			max=arr[a][b];
		}
	}
	for(int a=i, b=j; a<=9, b<=9; a++, b++){
		if(a>9 || b>9){
			break;
		}
		if(arr[a][b]>max){
			max=arr[a][b];
		}
	}
	return max;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    if(E3>99 || E3<0){
    	return -99;
	}
	int arr[10][10];
    crime_point(arr, E3);
    int i=0; int j=0;
    meet_point(arr, E3, i, j);
    int point2=Sh_Wa_point(arr, i, j);
    int point1=arr[i][j];
    if(abs(point1)>abs(point2)){
        HP1=ceil(HP1*0.9-0.0001);
        limit_hp(HP1);
        HP2=ceil(HP2*0.9-0.0001);
        limit_hp(HP2);
        EXP1=ceil(EXP1*0.88-0.0001);
        limit_exp(EXP1);
        EXP2=ceil(EXP2*0.88-0.0001);
        limit_exp(EXP2);
        return point1;
    }
    if(abs(point1)<=abs(point2)){
        HP1=ceil(HP1*1.1-0.0001);
        limit_hp(HP1);
        HP2=ceil(HP2*1.1-0.0001);
        limit_hp(HP2);
        EXP1=ceil(EXP1*1.12-0.0001);
        limit_exp(EXP1);
        EXP2=ceil(EXP2*1.12-0.0001);
        limit_exp(EXP2);
        return point2;
    }
    return -1;
}

// Task 4
string tach_se(string email){
    string se="";
    for(int i=0; i<email.size(); i++){
    	if(email[i]!='@'){
    		se+=email[i];
		}
		else if(email[i]=='@'){
			break;
		}
	}
	return se;
}
int find_se(string s, string se){
    for(int i=0; i<s.size(); i++){
        if(s[i]==se[0]){
            int count=0;
            int k=0;
            for(int j=i; j<i+se.size(); j++){
                if(s[j]==se[k]){
                    count++;
                    k++;
                }
                else{
                	break;
				}
            }
            if(count==se.size()){
                return i;
            }
        }
    }
    return -1;
}
int same_char(string s){
    for(int i=0; i<s.size()-2; i++){
        if(s[i]==s[i+1] && s[i]==s[i+2]){
            return i;
        }
    }
    return -1;
}
int special_char(string s){
    for(int i=0; i<s.size(); i++){
        if(s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!'){
            return 0;
        }
    }
    return -5;
}
int no_match_char(string s){
    for(int i=0; i<s.size(); i++){
        if(s[i]<'a' || s[i]>'z'){
            if(s[i] < 'A' || s[i] > 'Z'){
                if(s[i]<'0' || s[i]>'9'){
                    if(s[i]!='@' && s[i]!='#' && s[i]!='%' && s[i]!='$' && s[i]!='!'){
                        return i;
                    }
                }
            }
        }
    }
    return -1;
}

int checkPassword(const char * s, const char * email){
    string emaila=""; string sa="";
    emaila=email;
    sa=s;
    if(sa.size()<8){
        return -1;
    }
    if(sa.size()>20){
        return -2;
    }
    if(tach_se(emaila)==""){
    	return -300;
	}
    if(find_se(sa, tach_se(emaila))!=-1){
        return -(300 + find_se(sa, tach_se(emaila)));
    }
    if(same_char(sa)!=-1){
        return -(400 + same_char(sa));
    }
    if(special_char(sa)!=0){
        return -5;
    }
    if(no_match_char(sa)!=-1){
    	int x=no_match_char(sa);
        return x ;
    }
    else{
    	return -10;
	}
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    int max=0;
	int pos;
	string arr[num_pwds];
	string str_max="";
    for(int i=0; i<num_pwds; i++){
    	arr[i]=arr_pwds[i];
	}
	for(int i=0; i<num_pwds; i++){
		int count=0;
		for(int j=i; j<num_pwds; j++){
			if(arr[i]==arr[j]){
				count++;
			}
		}
		if(count>max){
			str_max=arr[i];
			max=count;
			pos=i;
		}
		else if(count==max && str_max.size()<arr[i].size()){
			max=count;
			str_max=arr[i];
			pos=i;
		}
	}
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
