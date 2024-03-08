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
    // DO NOT MODIFY THIS FUNCTION
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

void checkEXP(int& EXP1,int& EXP2 )
{
	if(EXP1<0) EXP1=0;
	if (EXP1>600) EXP1=600;
	if(EXP2<0) EXP2=0;
	if (EXP2>600) EXP2=600; 
}
		
void checkM(int&M1, int& M2)
{
	if (M1<0) M1=0;
	if (M1>3000) M1=3000;
	if (M2<0) M2=0;
	if (M2>3000) M2=3000;
		
}

void checkHP(int&HP1,int&HP2)
{
	if (HP1<0) HP1=0;
	if (HP1>666) HP1=666;
	if (HP2<0) HP2=0;
	if (HP2>666) HP2=666;		
}

//sqr_least
int sqr_least(int num)
{
    int a = sqrt(num);
    int b = a + 1;
    if (abs(a*a - num) < abs(b*b - num)) return a*a;
    return b*b;
}

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) 
{
     // TH dac biet
    if((E1<0) || (E1>99)) {return -99;}
    checkEXP(EXP1, EXP2);
	// TH E1 tu 0 den 3
    int D;
    if ((E1>=0) && (E1<=3))
    {
    	if (E1==0) EXP2 += 29;
    	else if (E1==1) EXP2 += 45;
    	else if (E1==2) EXP2 += 75;
    	else EXP2 += 29 + 45 + 75;
    	checkEXP(EXP1, EXP2);
    	D=E1*3+EXP1*7;
    	if (D%2 == 0) EXP1 += 0.999 + D/200.0; 
        else EXP1 -= floor(D/100.0);
		checkEXP(EXP1, EXP2);
	}
	// TH E1 tu 4 den 99
	else 
    {
		if((E1>=4) && (E1<=19)) EXP2 += 0.999 + E1/4.0 + 19;
		else if ((E1>=20) && (E1<=49)) EXP2 += 0.999 + E1/9.0 + 21;
		else if ((E1>=50) && (E1<=65)) EXP2 += 0.999 + E1/16.0 + 17;
		else if ((E1>=66) && (E1<=79))
        {
            EXP2 += 0.999 + E1/4.0 + 19;
            checkEXP(EXP1, EXP2);
            if(EXP2>200) EXP2 += 0.999 + E1/9.0 + 21;
            checkEXP(EXP1, EXP2); 
        }
		else 
        {
			EXP2 += 0.999 + E1/4.0 + 19;
			checkEXP(EXP1, EXP2);
			EXP2 += 0.999 + E1/9.0 + 21;
			checkEXP(EXP1, EXP2);
			if (EXP2>400) 
            {
				EXP2 += 0.999 + E1/16.0 + 17;
				checkEXP(EXP1, EXP2);
				EXP2 += 0.999 + EXP2*0.15;
				checkEXP(EXP1, EXP2);
			}
	    }	
        EXP1 -= E1;
        checkEXP(EXP1, EXP2);
    }	
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) 
{
	 // TH dac biet
    int X = 0;
    if((E2 < 0) || (E2 > 99)) return -99;
	checkEXP(EXP1,X);
    checkM(M1,X);
    checkHP(HP1,X);
	float P1,P2,P3,P;
	// duong 1
    if (EXP1 >= sqr_least(EXP1)) P1 = 1.00; 
    else P1 = ((1.0*EXP1/sqr_least(EXP1)) + 80)/123.0;
    // duong 2
    int m_used = 0, k; 
    int m = ceil(1.0*M1/2);
    if (E2%2 == 0) k=0 ; else k=1;
	do 
    {
    // 3 su kien  
    // sk1
    if ((M1==0) || ((k==1)&&(m_used>m))) break;
    if(HP1<200)
    {
        HP1 += 0.999 + HP1*0.3;
        M1-=150;
        m_used+=150;
    }
    else
    {
        HP1 += 0.999 + HP1*0.1;
        M1-=70;
        m_used+=70;
    }
    checkHP(HP1,X);
    checkM (M1,X);
    if ((M1==0) || ((k==1)&&(m_used>m))) break;
    // sk2
    if (EXP1<400) 
    {
        M1-=200;
        m_used+=200;
	} 
    else
    {
		M1-=120;
		m_used+=120;
	}
    EXP1 += 0.999 + EXP1*0.13;
	checkEXP(EXP1,X);
    checkM(M1,X);
    if ((M1==0) || ((k==1)&&(m_used>m))) break;
    //sk3 
    if(EXP1<300)
    {
    	M1-=100;
    	m_used+=100;
	} 
    else 
    {
        M1-=120;
        m_used+=120;
	}
	EXP1 -= floor(EXP1*0.1);
	checkEXP(EXP1,X);
    checkM(M1,X);
    if ((M1==0) || ((k==1)&&(m_used>m))) break;
    }   
    while(k);
    HP1 -= floor(HP1*0.17);
    EXP1 += 0.999 + EXP1*0.17;
    checkHP(HP1,X);
    checkEXP(EXP1,X);
    if (EXP1 >= sqr_least(EXP1)) P2 = 1.00; 
    else P2 = (1.0*EXP1/sqr_least(EXP1) + 80)/123.0;
    // duong 3
    float array[10] ={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
	if (E2>=0 && E2<=9) P3 = 0.01*array[E2];
    else P3 = 0.01*array[(E2/10 + E2%10)%10];
    P = (P1+P2+P3)/3.0;
	if (P==1.0)
    {
	    EXP1 -= floor(0.25*EXP1);
    }
	else if (P<0.5)
    {
        HP1 -= floor(HP1*0.15);
        EXP1 += 0.999 + 0.15*EXP1;
    }
	else 
    {
        HP1 -= floor(HP1*0.1);
        EXP1 += 0.999 + 0.2*EXP1;
    }
    checkHP(HP1,X);
    checkEXP(EXP1,X);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) 
{   
    if((E3 < 0) || (E3 > 99)) return -99;
	checkEXP(EXP1,EXP2);
    checkHP(HP1,HP2);
	int map[10][10];
	int k=0;
	int q=0;
	for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
	map[i][j]= ((E3*j) + (i*2)) * (i - j);
	if (map[i][j]>E3*2) k=k+1;
	if (map[i][j]<-E3) q=q+1;
	}}
	while (k>9){
		k=k%10+k/10;
		}
	while (q>9){
		q=q%10+q/10;
		}	
	int i=k;
	int j=q;
	int diemTaxi=map[i][j];
	int maxLeft=map[i][j];
	int maxRight=map[i][j];
	while((i>0)&&(i<9)&&(j>0)&&(j<9)) {
		--i;
		--j;
		if(maxLeft<map[i][j]) maxLeft=map[i][j];
	}
    i=k; j=q;
	while((i>0)&&(i<9)&&(j>0)&&(j<9)) {
		++i;
		++j;
		if(maxLeft<map[i][j]) maxLeft=map[i][j];
	}
    i=k; j=q;
	while((i>0)&&(i<9)&&(j>0)&&(j<9)) {
		--i;
		++j;
		if(maxRight<map[i][j]) maxRight=map[i][j];
	}
    i=k; j=q;
	while((i>0)&&(i<9)&&(j>0)&&(j<9)) {
		++i;
		--j;
		if(maxRight<map[i][j]) maxRight=map[i][j];
	}
    i=k; j=q;
    int diemSo;
	if (maxLeft>maxRight) {diemSo=maxLeft;} else {diemSo=maxRight;}
	if (abs(diemTaxi)>diemSo){
		EXP1 -= floor(EXP1*0.12);
        EXP2 -= floor(EXP2*0.12);
        HP1 -= floor(HP1*0.1);
        HP2 -= floor(HP2*0.1);
	}
	else {
		EXP1 += 0.999 + EXP1*0.12;
        EXP2 += 0.999 + EXP2*0.12;
        HP1 += 0.999 + HP1*0.1;
        HP2 += 0.999 + HP2*0.1;
	}
    checkHP(HP1,HP2);
    checkEXP(EXP1,EXP2);
	if (diemSo >= abs(diemTaxi)) return diemSo;
    return diemTaxi;
}


bool isSpecial(char c) {
    return (c == '@' || c == '#' || c == '%' || c == '$' || c == '!');
}

bool isalnum(char c) {
    return ((c >= 'a'&& c<= 'z') || (c >= 'A'&& c<= 'Z') || (c >= '0'&& c<= '9'));
}

//Task 4
int checkPassword(const char *s, const char *email) 
{
    // Kiem tra do dai mat khau
    if (strlen(s) < 8) return -1;
    else if (strlen(s) > 20) return -2;
    
    // trich tu dau den @
    int k = 0;
    while (email[k] != '@' && k < strlen(email)) {
        k++;
    }
    char se[k + 1];
    memcpy(se, email, k);
    se[k] = '\0';
    
    // kiem tra se co ton tai trong s
    const char *position = strstr(s, se);
    if (position != nullptr) {
        return -(300 + (position - s));
    }

    // kiem tra co hai ky tu lien tiep giong nhau khong
    for (int i = 0; i < strlen(s) - 2; ++i) {
        if ((s[i] == s[i + 1]) && (s[i] == s[i + 2])) {
            return -(400 + i);
        }
    }

    // Kiem tra xem co it nhat mot ky tu dac biet khong
    bool hasSpecial = false;
    for (int i = 0; i < strlen(s); ++i) {
        if (isSpecial(s[i])) {
            hasSpecial = true;
            break;
        }
    }
    if (!hasSpecial) {
        return -5;
    }

    // Kiem tra xem co 
    for (int i = 0; i < strlen(s); ++i) {
        if (!isalnum(s[i]) && !isSpecial(s[i])) {
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
  // Mang luu so lan xuat hien cua moi mat khau
    int matKhau[num_pwds] = {0};

    // Đem so lan xuat hien cua moi mat khau
    for (int i = 0; i < num_pwds; ++i) {
        const char *lan = arr_pwds[i];
        for (int j = 0; j < num_pwds; ++j) {
            if (i != j && strcmp(lan, arr_pwds[j]) == 0) {
                matKhau[i]++;
            }
        }
    }

    int viTri = 0;
    size_t maxLength = 0;

    // Tim mat khau co so lan xuat hien nhieu nhat va co đo dai lon nhat
    for (int i = 0; i < num_pwds; ++i) {
        const char *lan = arr_pwds[i];
        if (matKhau[i] > matKhau[viTri] ||
            (matKhau[i] == matKhau[viTri] && strlen(lan) > maxLength)) {
            viTri = i;
            maxLength = strlen(lan);
        }
    }

    // Tra ve vi tri đau tien
    return viTri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
