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

void ceill(float &D){
	if (D > (int) D) D++;
}
void checkEXP (int &exp){
	if (exp<0) exp=0;
	if (exp>600) exp=600;
}
void checkHP (int &hp){
	if (hp<0) hp=0;
	if (hp>666) hp=666;
}
void checkM (int &m){
	if (m<0) m=0;
	if (m>3000) m=3000;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1<0 || e1>99) return -99;
	else {
		checkEXP (exp1);
		checkEXP (exp2);
}
	if (e1>=0 && e1<=3){
		if (e1==0) exp2+=29;
		if (e1==1) exp2+=45;
		if (e1==2) exp2+=75;
		if (e1==3) exp2+=(29+45+75);
		int D=e1*3+exp1*7;
		if (D%2==0) exp1+=ceill((float)D/200);
			else exp1=ceill((float)exp1-D/100);
}
	else {
		if (e1>=4 && e1<=19) exp2+=ceill((float)e1/4+19);
		if (e1>=20 && e1<=49) exp2+=ceill((float)e1/9+21);
		if (e1>=50 && e1<=65) exp2+=ceill((float)e1/16+17);
		if (e1>=66 && e1<=79){
			exp2+=ceill((float)e1/4+19);
			checkEXP (exp2);
			if (exp2>200) exp2+=ceill((float)e1/9+21);
}
		if (e1>=80 && e1<=99){
			exp2+=(ceill((float)e1/4+19)+ceill((float)e1/9+21));
			checkEXP (exp2);
			if (exp2>400){
				exp2+=ceill((float)e1/16+17);
				exp2+=ceill((float)exp2*0.15);
}
}
		exp1-=e1;
}
	checkEXP (exp1);
	checkEXP (exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
	if (E2<0 || E2>99) return -99;
	checkEXP (EXP1);
	checkHP (HP1);
	checkM (M1);
	int S=pow(round(sqrt(EXP1)),2);
	double P1, P2, P3;
	double P[10]= {0.32, 0.47, 0.28, 0.79, 1, 0.50, 0.22, 0.83, 0.64, 0.11};
	if (EXP1>=S) P1= 1;
		else P1= (((double)EXP1/S)+80)/123;
	int PAY=0, BEGIN=M1;
	if (E2%2==1){
		do{
			if (M1==0) break;
			if (HP1<200){
				HP1+=ceill((float)HP1*0.3);
				M1-=150;
				PAY+=150;
}
				else{
					HP1+=ceill((float)HP1*0.1);
					M1-=70;
					PAY+=70;
}
			checkHP (HP1);
			if (M1<=0 || PAY>0.5*BEGIN) break;
			if (EXP1<400){
				M1-=200;
				PAY+=200;
}
				else{
					M1-=120;
					PAY+=120;
}
			EXP1= ceill((float)EXP1*1.13);
			checkEXP (EXP1);
			if (M1<=0 || PAY>0.5*BEGIN) break;
			if (EXP1<300){
				M1-=100;
				PAY+=100;
}
				else{
					M1-=120;
					PAY+=120;
}
			EXP1= ceill((float)EXP1-EXP1*0.1);
			checkEXP (EXP1);
			if (M1<=0 || PAY>0.5*BEGIN) break; //du
}
		while (PAY<=0.5*BEGIN);
}
	else {
		do{
			if (M1==0) break;
			if (HP1<200){
				HP1+=ceill((float)HP1*0.3);
				M1-=150;
				PAY+=150;
}
				else{
					HP1+=ceill((float)HP1*0.1);
					M1-=70;
					PAY+=70;
}
			checkHP (HP1);
			if (M1<=0) break;
			if (EXP1<400){
				M1-=200;
				PAY+=200;
}
				else{
					M1-=120;
					PAY+=120;
}
			EXP1= ceill((float)EXP1*1.13);
			checkEXP (EXP1);
			if (M1<=0) break;
			if (EXP1<300){
				M1-=100;
				PAY+=100;
}
				else{
					M1-=120;
					PAY+=120;
}
			EXP1= ceill((float)EXP1-EXP1*0.1);
			checkEXP(EXP1);
			if (M1<=0) break; //du
}
		while (0);
}
		HP1=ceill((float)HP1-HP1*0.17);
		EXP1=ceill((float)EXP1*1.17);
		checkEXP (EXP1);
		checkHP (HP1);
		S=pow(round(sqrt(EXP1)),2);
		if (EXP1>=S) P2= 1;
		else P2= (((double)EXP1/S)+80)/123;

		if (E2>=0 && E2<=9) P3= P[E2];
			else P3= P[(E2/10+E2%10)%10];

		if (P1==1 && P2==1 && P3==1) EXP1= ceill((float)EXP1-EXP1*0.25);
			else{
				double PA= (P1+P2+P3)/3;
				if (PA<0.5){
					HP1=ceill((float)HP1-HP1*0.15);
					EXP1=ceill((float)EXP1*1.15);
}
				else{
					HP1=ceill((float)HP1-HP1*0.1);
					EXP1+=ceill((float)EXP1*0.2);
}
}
	checkEXP (EXP1);
	checkHP (HP1);
	checkM (M1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
	if (E3<0 || E3>99) return -99;
	checkEXP (EXP1);
	checkHP (HP1);
	checkEXP (EXP2);
	checkHP (HP2);
	int P[10][10], I=0, J=0;
	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			P[i][j]=(E3*j+i*2)*(i-j);
			if (P[i][j]>E3*2) I++;
			if (P[i][j]<-E3) J++;
}
}
	int y= (I/10+I%10)/10 + (I/10+I%10)%10;
	int x= (J/10+J%10)/10 + (J/10+J%10)%10;
	int MEET=P[y][x], MAX=P[y][x];
	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			if (y-i==x-j || y-i==j-x){
				if (P[i][j]>MAX) MAX=P[i][j];
}
}
}
	if (abs(MEET)>abs(MAX)){
		EXP1=ceill((float)EXP1-EXP1*0.12);
		HP1=ceill((float)HP1-HP1*0.1);
		EXP2=ceill((float)EXP2-EXP2*0.12);
		HP2=ceill((float)HP2-HP2*0.1);
		checkEXP (EXP1);
		checkHP (HP1);
		checkEXP (EXP2);
		checkHP (HP2);
    return MEET;
}
	else{
		EXP1+=ceill((float)EXP1*0.12);
		HP1+=ceill((float)HP1*0.1);
		EXP2+=ceill((float)EXP2*0.12);
		HP2+=ceill((float)HP2*0.1);
		checkEXP (EXP1);
		checkHP (HP1);
		checkEXP (EXP2);
		checkHP (HP2);
    return MAX;
}
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
	int LEN=strlen(s);
	if (LEN<8) return -1;
	if (LEN>20) return -2;

	const char *a=strstr(email, "@");
	int selen=a-email;
	char se[selen+1];
	strncpy(se, email, selen);
	se[selen]='\0';
	const char *checkpoint=strstr(s, se);
	if (checkpoint!=nullptr) return -(300+(checkpoint-s));

	for (int i=0; i<LEN-2; i++){
		if (s[i]==s[i+1] && s[i]==s[i+2]) return -(400+i);
}
	int special=0;
	for (int i=0; i<LEN; i++){
		if (s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!') special++;
}
	if (special==0) return -5;

	for (int i=0; i<LEN; i++){
		if (!((s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!') || (s[i]>='0' && s[i]<='9') || (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))) return i;
}
	return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
	int* pwd_count=new int[num_pwds];
	for (int i=0; i<num_pwds; i++){
		pwd_count[i]=0;
}
	for (int i=0; i<num_pwds; i++){
		const char* pwd=arr_pwds[i];
		for (int j=0; j<num_pwds; j++){
			if (strcmp(arr_pwds[j], pwd)==0) pwd_count[i]++;
}
}

	int freq=0;
	int position=-1;
	for (int i=0; i<num_pwds;i++){
		if (pwd_count[i]>freq || (pwd_count[i]==freq && strlen(arr_pwds[i])>strlen(arr_pwds[position]))){
			freq=pwd_count[i];
			position=i;
}
}
	delete[] pwd_count;
	return position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
