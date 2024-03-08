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
//Ham kiem tra gia tri EXP co thuoc khoang [0,600]
void checkEXP(int &EXP)
{ 	if (EXP<0) EXP=0; 
	else if (EXP>600) EXP=600;
}

//Ham kiem tra gia tri HP co thuoc khoang [0,666]
void checkHP(int &HP)
{  	if (HP<0) 
	HP=0; 
	else if (HP>666) 
	HP=666; 
}
//Ham kiem tra gia tri EXP co thuoc khoang [0,3000]
void checkM(int &M)
{	if (M<0) 
	M=0; 
	else if (M>3000) 
	M=3000; 
}
/////////////////////////// ***TASK 1*** ///////////////////////////

//Ham tinh diem exp1 trong TH1
void calexp1(int& exp1, int e1) {
    int D(0);
    D = exp1*7+ e1*3;
    if (D % 2 == 0)
        exp1 += ceil(D/200.0);
    else 
	exp1-= floor(D/100.00);}
//Ham tinh toan truong hop 1// 
void firstmeet1(int &exp1, int &exp2, int e1){
	const int arr1a[]={29,45,75,149};
	switch (e1) {
    case 0:
        exp2 += arr1a[0];
        calexp1(exp1, e1);
        break;
    case 1:
        exp2 += arr1a[1];
        calexp1(exp1, e1);
        break;
    case 2:
        exp2 += arr1a[2];
        calexp1(exp1, e1);
        break;
    case 3:
        exp2 += arr1a[3];
        calexp1(exp1, e1);
        break;
}
}
//Ham tinh toan truong hop 2// 
void firstmeet2(int &exp1, int &exp2, int e1)
{ 	if (e1<=19)
	exp2+= ceil(e1/4.0) + 19; 
	else if (e1>=20 && e1<=49)
	exp2+= ceil(e1/9.00) + 21; 
    else if (e1>=50 && e1<=65)
	exp2+= ceil(e1/16.0) + 17;
    else if (e1>=66 && e1<=79){
    exp2+= ceil(e1/4.0) + 19;
        if (exp2 >200)
        exp2+= ceil(e1/9.0) + 21; }
    else if (e1>=80 && e1<=99){
	exp2+= ceil(e1/4.0) + 19; 
    exp2+= ceil(e1/9.00) + 21; 
        if (exp2>400){
        exp2+= ceil(e1/16.0) + 17;
        exp2= ceil(exp2*11.5/10.0);}
        
    }
	exp1-=e1;
} 
///////////////////// XU LI NHIEM VU 1////////////////////////
int firstMeet(int &exp1, int &exp2, int e1){
	if (e1>=0 && e1<=3){
	firstmeet1(exp1,exp2,e1);
   checkEXP(exp1);
checkEXP(exp2);
}
	else if (e1>=4 && e1<=99){
	firstmeet2(exp1,exp2,e1); 
	checkEXP(exp1);
checkEXP(exp2);
	}
   else return -99; 
   return exp1 + exp2; 
}

/////////////////////////// ***TASK 2*** ///////////////////////////

/////Con duong 1////// 
double traceLuggage_Street1(int & exp1){
   // double P1;
	int S(0), sqr; 
	S= round(sqrt(exp1));
	S=S*S;  
    if (exp1>=S) 
        return 100 ;
    else 
        return ((exp1/S + 80.0)/123.0) *100.0;
}
//////Con duong 2////// 
void sk1(int & hp1,int & m1){ //Ham xu su kien 1 
	if (hp1<200) {
		hp1=ceil(hp1*13.0/10.0); 
		m1-=150;}
	else {
		hp1=ceil(hp1*11.0/10.0);
		m1-=70;}
		checkHP(hp1);
	    checkM(m1);
}
void sk2(int & exp1 , int & m1 ){ // Ham xu li su kien 2
	if (exp1<400) {
		m1-=200;
		exp1=ceil(exp1*11.3/10.0);}
	else {
		m1-=120; 
		exp1=ceil(exp1*11.3/10.0);}
		checkEXP(exp1);
        checkM(m1);
}
void sk3(int & exp1 , int & m1){ // Ham xu li su kien 3
		if (exp1<300) 
		m1-=100; 
		else 
		m1-=120; 
		exp1=ceil(exp1*9.0/10.0);
		checkEXP(exp1);
        checkM(m1);
}
//// Ham xu li con duong 2///////
double traceLuggage_Street2(int &hp1, int &exp1, int &m1, int e2){
	double P2(0);  
	int m = ceil(m1/2.0); 
	if (e2%2==0){
	while(m1>0){
	sk1(hp1,m1);
	if(m1<=0) 
	 break; 
	sk2(exp1,m1);
	if(m1<=0) 
	 break; 
	sk3(exp1,m1);
	if(m1<=0) 
	 break; 
	 break;}
}
	else  {
	while (m1>0) {
	sk1(hp1,m1);
	if (m1<m) 
	 break; 
	sk2(exp1,m1);
	if(m1<m) 
	 break; 
	sk3(exp1,m1);
	if(m1<m) 
	 break;}}
	exp1=ceil(exp1*11.7/10.0);
	hp1 =ceil(hp1*8.3/10.0);
    checkHP(hp1);
	checkEXP(exp1);
	checkM(m1);
	P2= traceLuggage_Street1(exp1); 
	return P2 ;
}
// Ham xu li con duong 3///
double traceLuggage_Street3(int e2)
{ int Pi[]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
  int a,b,c;
  	if (e2>=0 && e2<10)
  	return Pi[e2];
  	else{
  	a= floor(e2/10.0); 
  	b= e2- a*10; 
  	c= (a+b)%10;
  	return Pi[c];}
}
///////////////////// XU LI NHIEM VU 2////////////////////////
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
   if (E2>=0 && E2<=99){
    double p1,p2,p;
 	int p3;
 p1= traceLuggage_Street1(EXP1);  // Xac xuat tim duoc hanh li o con duong 1
 p2= traceLuggage_Street2(HP1,EXP1,M1,E2);  // Xac xuat tim duoc hanh li o con duong 2
 p3= traceLuggage_Street3(E2);  // Xac xuat tim duoc hanh li o con duong 3
 if (p1 == 100 && p2 == 100 && p3 == 100)
 EXP1=ceil(EXP1*7.5/10);
 else {
 	p= ceil((p1+p2+p3)/3.0);
 	if (p<50){
 	HP1 = ceil(HP1*8.5/10.0);
 	EXP1=ceil(EXP1*11.5/10);
	}
	else {
	HP1= ceil(HP1*9.0/10);
 	EXP1=ceil(EXP1*12.0/10);
	}}
	checkEXP(EXP1);
	checkHP(HP1);
	checkM(M1);
	return EXP1 + HP1 + M1;}
    else 
    return -99;
}
/////////////////////////// ***TASK 3*** ///////////////////////////

///Ham tim vi tri gap nhau cua sherlock waston va taxi
int loca( int s){
	int a,b,c;
	while(s>=10){
  	a= floor(s/10.0); 
  	b= s%10; 
  	c= a+b;
  	s=c;}
  	return s;}
///// Ham tinh diem cua Sherlock va Watson
int swPoint(int arr[10][10], int x, int y){ 
	int max=arr[x][y];
	 ///Tim gia tri lon nhat tren duong cheo phai
	for ( int i=0; i<10;i++ ){
		if (x<y)  { ///neu x<y thi xet tu vi tri [0][hieu cua xy]
		if (arr[i][i+(y-x)]> max)
		max =arr[i][i+(y-x)] ; 
		if (i+(y-x)>=9) 
		 break;  }
		else { /// xet tu vi tri [hieu cua xy][0]
		if (arr[i+x-y][i] > max)
		max = arr[i+x-y][i]; 
		if (i+(x-y) >= 9)
		 break;   }
		} 
 	///Tim gia tri lon nhat tren duong cheo trai
	for (int i=0; i<10;i++){  
		if (x+y-i<10){ 
		if (arr[i][x+y-i] > max)
		max= arr[i][x+y-i]; 
		if(x+y+i<0 || i >9) 
		break;  
		}}
	return max;	 
}
///////////////////// XU LI NHIEM VU 3////////////////////////
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int e3){
    if (e3>99 || e3<0) //kiem tra e3
        return -99; 
    else{
	int s1(0),s2(0);
    //tao mang chua diem cua taxi 
    int taxiArr[10][10]={0};
	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			taxiArr[i][j]=((e3*j)+(i*2))*(i-j);
			if (taxiArr[i][j]> e3*2)
			s1+=1;
			if (taxiArr[i][j] < -e3)
			s2+=1;}}
    //tao mang chua diem sherlock,watson   
	int swArr[10][10]={0}; 
	for (int x=0; x<10; x++){
		for (int y=0; y<10; y++){
			swArr[x][y]=abs(swPoint(taxiArr,x,y));
		}
	}
    //So sanh diem cua taxi va sherlock watson & tinh lai diem exp, hp 
    if ( abs(taxiArr[loca(s1)][loca(s2)]) > swArr[loca(s1)][loca(s2)] ){
        EXP1=ceil(EXP1 - EXP1*12.0/100);
        EXP2=ceil(EXP2- EXP2*12.0/100);
        HP1=ceil(HP1*9.0/10);
        HP2=ceil(HP2*9.0/10);
        checkEXP(EXP1);
        checkEXP(EXP2);
        checkHP(HP1); 
        checkHP(HP2);
        return taxiArr[loca(s1)][loca(s2)];}
    else {
        EXP1=ceil(EXP1*11.2/10.0);
        EXP2=ceil(EXP2*11.2/10.0);
        HP1=ceil(HP1*11.0/10);
        HP2=ceil(HP2*11.0/10);
        checkEXP(EXP1);
        checkEXP(EXP2);
        checkHP(HP1); 
        checkHP(HP2);
        return swArr[loca(s1)][loca(s2)]; 
    }}
}
/////////////////////////// ***TASK 4*** ///////////////////////////
// Ham kiem tra su hop le cua mat khau
int checkPass( string pass, string Email){
 string se;  
 // kiem tra do dai 
 size_t founda= Email.find('@'); 
 se =  Email.substr(0,founda) ; 
 if (pass.length() < 8) {
    return -1; 
}
 else if (pass.length()>20)
 return -2;
 else { 
 	// kiem tra chua ki tu se 
 	size_t foundse =  pass.find(se); 
 	if (foundse !=  string::npos) 
 	return -(300+foundse); 
 	else {
 		// kiem tra 2 ky tu giong nhau lien tiep 
 		for (int i=0; i<pass.length(); i++){
 		if (pass[i]==pass[i+1]){ 
 			if (pass[i+1]==pass[i+2])
 			return -(400+i);
 			else 
 			i++; 
		 }}
		//kiem tra s co chua ki tu dac biet khong 	 
	 	string specialChar = "@#%$!";
	 	if (pass.find_first_of(specialChar) == string::npos )
	 	return -5;
        else {
            //kiem tra mat khau co chua ki tu dac biet 
	    for (int i=0; i<pass.length(); i++){
		if ( pass[i]<33 ||pass[i]==34 || (pass[i]>37 && pass[i] <48 ) || (pass[i]>57 && pass[i]<64) || (pass[i] >90 && pass[i]< 97) || pass[i]>122  ) {
		return i; 
		break; }
	} 
        }   
	 }}
    
 return -10; 
 }
 ///////////////////// XU LI NHIEM VU 4////////////////////////
int checkPassword(const char * s, const char * email) {
 int a; 
 string Email(email);
 string pass(s); 
 size_t founda; 
 size_t foundse; 
 a= checkPass(pass, Email);
 return a;
 }
/////////////////////////// ***TASK 5*** ///////////////////////////
// Ham tim vi tri cua mat khau
 int vitriMK( int array1[], int array2[], int num_pwds){
	int maxfe = array1[0]; //So lan xuat hien cua mat khau xuat hien nhieu nhat
	int maxlen= 0; // Do dai cua mat khau xuat hien nhieu nhat va dai nhat 
	int index(0);  
	// Tim so lan xuat hien cua mat khau xuat hien nhieu nhat
	for (int i=0; i<num_pwds;i++ ){
		if ( array1[i] > maxfe){ 
		index = i; 
		maxfe= array1[i];
		maxlen= array2[i];} 
		//index=i; 
	} 
	//Tim vi tri cua mat khau co do dai dai nhat trong cac mat khau co so lan xuat hien nhieu nhat
	for (int i=0; i<num_pwds; i++){
		if (array1[i]==maxfe && array2[i] > maxlen ) {
			maxlen= array2[i]; 
			index = i;}}
            return index; 
}
///////////////////// XU LI NHIEM VU 5////////////////////////
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int arr_fe[100]={0};// Mang chua so lan xuat hien cua cac mat khau duoc nhap vao 
    int arr_length[100]={0}; //Mang chua do dai cua cac mat khau duoc nhap vao
    int x; 
	for (int i=0; i< num_pwds; i++){
		for (int j=0; j<num_pwds; j++){
		if ( strcmp(arr_pwds[i], arr_pwds[j]) == 0) //
		arr_fe[i] += 1;}
		arr_length[i]= strlen(arr_pwds[i]);
		}
    x= vitriMK(arr_fe,arr_length,num_pwds);
	return x;
}

