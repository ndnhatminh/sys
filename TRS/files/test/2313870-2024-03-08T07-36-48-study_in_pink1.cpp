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

//kiem tra dau vao task1
void kt(int & EXP1,int & EXP2){
    if(EXP1>600)EXP1=600;
	if(EXP1<0)EXP1=0;
	if(EXP2>600)EXP2=600;
	if(EXP2<0)EXP2=0;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1)
{
    if(e1<0||e1>99)return -99;
    kt(exp1,exp2);
    if(e1>=0&&e1<=3){
    	if(e1==0){exp2+=29;kt(exp1,exp2);}
    	else if(e1==1){exp2+=45;kt(exp1,exp2);}
    	else if(e1==2){exp2+=75;kt(exp1,exp2);}
    	else {exp2=exp2+29+45+75;kt(exp1,exp2);}
    	int d=e1*3+exp1*7;
    	if(d%2==0){exp1=ceil(exp1+1.0*d/200);kt(exp1,exp2);}
    	else {exp1=ceil(exp1-1.0*d/100);kt(exp1,exp2);}
	}
	else if(e1>=4&&e1<=99){
		if(e1<=19&&e1>=4){exp2=ceil(exp2+1.0*e1/4+19);kt(exp1,exp2);}
		else if(e1>=20&&e1<=49){exp2=ceil(exp2+1.0*e1/9+21);kt(exp1,exp2);}
		else if(e1>=50&&e1<=65){exp2=ceil(exp2+1.0*e1/16+17);kt(exp1,exp2);}
		else if(e1>=66&&e1<=79){
			exp2=ceil(exp2+1.0*e1/4+19);
            kt(exp1,exp2);
			if(exp2>200){exp2=ceil(exp2+1.0*e1/9+21);kt(exp1,exp2);}
		}
		else {
			exp2=ceil(exp2+1.0*e1/4+19);
			exp2=ceil(exp2+1.0*e1/9+21);
            kt(exp1,exp2);
			if(exp2>400){
			exp2=ceil(exp2+1.0*e1/16+17);
			exp2=ceil(exp2*115.0/100);
            kt(exp1,exp2);
		}}
	exp1-=e1;
    kt(exp1,exp2);	
	}
    return exp1+exp2;
}
//kt task2
void kt2(int & HP1,int & EXP2,int & M1){
    if(HP1<0)HP1=0;
    if(HP1>666)HP1=666;
    if(EXP2<0)EXP2=0;
    if(EXP2>600)EXP2=600;
    if(M1<0)M1=0;
    if(M1>3000)M1=3000;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
	// con duong 1
if(E2<0||E2>99)return -99;
kt2(HP1,EXP1,M1);
int a=round(sqrt(EXP1));
float p1;
int s=a*a;
if(EXP1>=s)p1=1;
else p1=(1.0*(1.0*EXP1/s + 80)/123);
	// con duong 2	
float b=1.0*M1*0.5;
if(E2%2==1){
while(M1>b){
	// hanh dong 1:
if(HP1<200){
HP1=ceil(HP1*13.0/10);
M1-=150;
kt2(HP1,EXP1,M1);
}
else {
	HP1=ceil(HP1*11.0/10);
	M1-=70;
    kt2(HP1,EXP1,M1);
}
	//kiem tra tien 
if(M1<b)break;
else{
	//hanh dong 2
if(EXP1<400)M1-=200;
else M1-=120;
EXP1=ceil(EXP1*113.0/100);
kt2(HP1,EXP1,M1);
	//kiem tra tien
if(M1<b)break;
else{
	//hanh dong 3
if(EXP1<300)M1-=100;
else M1-=120;
EXP1=ceil(EXP1*9.0/10);
kt2(HP1,EXP1,M1);}}}
}
//TH E2 chan
else {
    if(M1==0)M1=0;
    else{
	// hanh dong 1:
if(HP1<200){
HP1=ceil(HP1*13.0/10);
M1-=150;
kt2(HP1,EXP1,M1);
}
else {
	HP1=ceil(HP1*11.0/10);
	M1-=70;
    kt2(HP1,EXP1,M1);
}
	//kiem tra tien 
if(M1<=0)M1=0;
else{
	//hanh dong 2
if(EXP1<400)M1-=200;
else M1-=120;
EXP1=ceil(EXP1*113.0/100);
kt2(HP1,EXP1,M1);	
	//kt tien
if(M1<=0)M1=0;
else{
	//hanh dong 3
if(EXP1<300)M1-=100;
else M1-=120;
EXP1=ceil(EXP1*9.0/10);
}}}}
HP1=ceil(HP1*83.0/100);
EXP1=ceil(EXP1*117.0/100);	
kt2(HP1,EXP1,M1);
int c=round(sqrt(EXP1));
float p2=0;
if(EXP1>=c*c)p2=1;
 else p2=1.0*(1.0*(1.0*EXP1/(c*c) + 80)/123);
//con duong 3
float p3=0;
int P[10]={32,47,28,79,100,50,22,83,64,11};
if(E2>=0&&E2<=9)p3=1.0*P[E2]/100;
else if (E2>=10&&E2<=99){
int i=(E2%10+E2/10)%10;
p3=1.0*P[i]/100;}
float p=(p1+p2+p3)/3;
if(p1==1&&p2==1&&p3==1){EXP1=ceil(EXP1*75.0/100);kt2(HP1,EXP1,M1);}
else if (p<0.5){
	HP1=ceil(HP1*85.0/100);
	EXP1=ceil(EXP1*115.0/100);
    kt2(HP1,EXP1,M1);}
else if(p>=0.5){
	HP1=ceil(HP1*9.0/10);
	EXP1=ceil(EXP1*120.0/100);
    kt2(HP1,EXP1,M1);
}
return HP1+EXP1+M1;
}
//kiem tra task3
void kt3(int & HP1,int & EXP1,int & HP2,int & EXP2){
    if(EXP1>600)EXP1=600;
	if(EXP1<0)EXP1=0;
	if(EXP2>600)EXP2=600;
	if(EXP2<0)EXP2=0;
    if(HP1<0)HP1=0;
    if(HP1>666)HP1=666;
    if(HP2<0)HP2=0;
    if(HP2>666)HP2=666;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
if(E3<0||E3>99)return -99;
kt3(HP1,EXP1,HP2,EXP2);
long long x=0,y=0,dtx=0,max=0;
long long mt[10][10];
for(int i=0;i<=9;i++){
	for(int j=0;j<=9;j++)mt[i][j]=((E3*j)+(i*2))*(i-j);
}
for(int i=0;i<=9;i++){
for(int j=0;j<=9;j++){
	if(mt[i][j]>E3*2)x++;
	else if(mt[i][j]<-E3)y++;
}}
while(x>=10||y>=10){
 x=x%10+x/10;
 y=y%10+y/10;}
dtx=mt[x][y];
max=dtx;
for(int i=0;i<10;i++){
	int j=i+y-x; 
	if(j>=0&&j<10){
	if(mt[i][j]>max)max=mt[i][j];}
}
for(int i=0;i<10;i++){
	int j=x+y-i; 
	if(j>=0&&j<10)if(mt[i][j]>max)max=mt[i][j];
}
if(abs(dtx)>max){
	EXP1=ceil(EXP1*88.0/100);
	EXP2=ceil(EXP2*88.0/100);
	HP1=ceil(HP1*9.0/10);
	HP2=ceil(HP2*9.0/10);
    kt3(HP1,EXP1,HP2,EXP2);
	max=dtx;
}
else{
	EXP1=ceil(EXP1*112.0/100);
	EXP2=ceil(EXP2*112.0/100);
	HP1=ceil(HP1*11.0/10);
	HP2=ceil(HP2*11.0/10);
    kt3(HP1,EXP1,HP2,EXP2);
}
	return max;
}
// Task 4

bool kt(char k){
	if(k=='@'||k=='#'||k=='%'||k=='$'||k=='!')return true;
	else return false;
}
bool isAlpha(char c){
if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')||c=='@'||c=='#'||c=='%'||c=='$'||c=='!')return true;
else return false;
}
int checkPassword(const char * s, const char * email) {
string se;
int dem=0,count=0,a=-1,b=0,sei=-1,d=0,n=0;
string S(s);
string E(email);
int len=S.size();
//chieu dai mat khau
if(len<8) a=-1;//mat khau qua ngan
else if(len>20) a=-2;//mat khau qua dai
//chua ki tu se
else{
for(int i=0;i<E.size();i++){
if(E[i]=='@')break;
se+=E[i];}
if(se.size()==0)return-300;
for(int i=0;i<S.size();i++){
for(int j=0;j<se.size();j++){
if(S[i+j]!=se[j])break;
if(j==(se.size()-1)){
sei=i;return -(300+sei);}}}

//chua nhieu hon 2 ki tu lien tiep
for(int sci=0;sci<len-2;sci++){
if(S[sci]==S[sci+1]&&S[sci+1]==S[sci+2]){
d=sci;b++;break;}}
if(b!=0)a=-(400+d);
else{
// khong chua ki tu dac biet
for(int i=0;i<len;i++){
if(kt(S[i])==1)n++;}
if(n==0)a=-5;
else{
// ktr hop le
for(int i=0;i<len;i++)
if(isAlpha(S[i])==0){
count++;a=i;break;}
if(count==0)a=-10;
}}}
return a;
}
//task5
int findCorrectPassword(const char*arr_pwds[], int num_pwds) {
	string s;
	int max=0,maxsize=0,vt=-1;
for(int i=0;i<num_pwds;i++){
string c(arr_pwds[i]);
	int dem=0;
//dem so lan xuat hien cua mat khau hien tai
	for(int j=0;j<num_pwds;j++){
		string d(arr_pwds[j]);
		if(d==c){
			dem++;
		}
	}
if(dem > max){
	vt = i;
	maxsize = c.size();
	max = dem;
}
if(dem == max){
	if(c.size() > maxsize){
		 maxsize = c.size();
		 vt = i;
	}}}
return vt;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
