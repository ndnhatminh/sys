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
int kiemTra(int n, int soDau, int soCuoi)
{
	if (n<soDau) 
	{
		n=soDau;
	}
	else if (n>soCuoi)
	{
		n=soCuoi;
	}
	return n;
}
/////////////////////////////

 int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int soDau=0, soCuoi=99;
    if (e1 < 0 || e1 > 99) return -99;
    exp1 = kiemTra(exp1, 0, 600);
    exp2 = kiemTra(exp2, 0, 600);
    /////////////////////
    if (e1>=0 && e1<=3)
	{	
		if (e1==0){
	    	exp2+=29;
		}
	    if (e1==1){
	    	exp2+=45;
		}
	    if (e1==2){
	    	exp2+=75;
		}	
	    if (e1==3){
	    	exp2=exp2+29+45+75;
		}
		int d=e1*3+exp1*7;
		if (d%2==0){
			exp1=ceil(exp1+(float)d/200);
		}
		else exp1=ceil(exp1-(float)d/100);
		//exp1 =ceil(exp1);
	}
	/////
	if (e1>=4 && e1<=99)
	{
		if (e1>=4 && e1<=19)
		{
			exp2=ceil(exp2+(float)e1/4 + 19);
			
		}
		if (e1>=20 && e1<=49)
		{
			exp2=ceil(exp2+(float)e1/9 + 21);
			
		}
		if (e1>=50 && e1<=65)
		{
			exp2=ceil(exp2+(float)e1/16 + 17);
			
		}
		if (e1>=66 && e1<=79)
		{
			exp2=ceil(exp2+ (float)e1/4 + 19);
			exp2 = kiemTra(exp2, 0, 600);
			if (exp2>200)
			{
			exp2=ceil(exp2+(float)e1/9 + 21);	
			}
		}
		if (e1>=80&& e1<=99)
		{
			exp2=ceil(exp2+ (float)e1/4 + 19);
			exp2 = kiemTra(exp2, 0, 600);
			exp2=ceil(exp2+ (float)e1/9 + 21);
		    exp2 = kiemTra(exp2, 0, 600);
			if(exp2>400)
			{
			exp2=ceil(exp2+ (float)e1/16 + 17);
			exp2 = kiemTra(exp2, 0, 600);
			exp2=ceil((float)1.15*exp2);
			
			}
			
		}	
		
		exp1-=e1;
		exp1=ceil(exp1);
		exp2=ceil(exp2);
		exp1 = kiemTra(exp1, 0, 600);
		exp2 = kiemTra(exp2, 0, 600);
	
	}
    return exp1 + exp2;
}
// Task 2
int timSoChinhPhuong(int s)
{
	float m;
	m= floor(sqrt(s));
	if (sqrt(s)-m>=0.5)
	{
		return (m+1)*(m+1);
	}
	else return m*m;
}
//
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int soDau=0, soCuoi=99;
    if (E2 < 0 || E2 > 99) return -99;
    EXP1 = kiemTra(EXP1, 0, 600);
    M1 = kiemTra(M1, 0, 3000);
    HP1 = kiemTra(HP1, 0, 666);
    //con duong 01
    float p1,p2,p3;
	int s=timSoChinhPhuong(EXP1);
	if (EXP1>=s)
	{
		p1=1;
	}
	else p1=(float)((float)EXP1/s+ 80)/123;
	// con duong 02
	float nuaBanDau=0.5*M1;
	float tienDaTra;
	if (E2%2!=0)
	{
		while(tienDaTra<=nuaBanDau)
		{
		
			if (HP1<200)
			{
				HP1=ceil((float)HP1*1.3); HP1 = kiemTra(HP1, 0, 666);
				M1-=150;
				tienDaTra+=150;
			}
			else {
				HP1=ceil((float)HP1*1.1); HP1 = kiemTra(HP1, 0, 666);
				M1-=70;
				tienDaTra+=70;
			}
			if (tienDaTra>nuaBanDau) break;
			if (EXP1<400)
			{
				M1-=200;
				tienDaTra+=200;
			}
			else 
			{
				M1-=120;
				tienDaTra+=120;
		    }
		    
			EXP1=ceil((float)1.13*EXP1);  EXP1 = kiemTra(EXP1, 0, 600);
			if (tienDaTra>nuaBanDau) break;
			if (EXP1<300)
			{
				M1-=100;
				tienDaTra+=100;
			}
			else 
			{
				M1-=120;
				tienDaTra+=120;
			}
		
			EXP1=ceil((float)0.9*EXP1);  EXP1 = kiemTra(EXP1, 0, 600);
			if (tienDaTra>nuaBanDau) break;
		}
		HP1=ceil((float)0.83*HP1);   HP1 = kiemTra(HP1, 0, 666);
		EXP1=ceil((float)1.17*EXP1);   EXP1 = kiemTra(EXP1, 0, 600);
		
    }
    else 
	{
    	if (HP1<200)
			{
				HP1=ceil((float)HP1*1.3); HP1 = kiemTra(HP1, 0, 666);
				M1-=150;
				if (M1<=0) exit ;
			}
		else {
				HP1=ceil((float)HP1*1.1); HP1 = kiemTra(HP1, 0, 666);
				M1-=70;
				if (M1<=0) exit;
			}
		if (EXP1<400)
			{
				M1-=200;
				if (M1<=0) exit;
			}
		else 
			{
				M1-=120;
				if (M1<=0) exit;
		    }
		EXP1=ceil((float)1.13*EXP1); EXP1 = kiemTra(EXP1, 0, 600);
		if (EXP1<300)
			{
				M1-=100;
				if (M1<=0) exit ;
			}
		else 
			{
				M1-=120;
				if (M1<=0) exit;
			}
		EXP1=ceil((float)0.9*EXP1); EXP1 = kiemTra(EXP1, 0, 600);
		HP1=ceil((float)0.83*HP1);  HP1 = kiemTra(HP1, 0, 666);
		EXP1=ceil((float)1.17*EXP1); EXP1 = kiemTra(EXP1, 0, 600);
	}
	s=timSoChinhPhuong(EXP1);
	if (EXP1>=s)
	{
		p2=1;
	}
	else p2=(float)((float)EXP1/s+ 80)/123;
	// con duong 03
	int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
	int i;
	if (E2>=0&&E2<10) 
	{
		i=E2;
	}
	else 
	{
		int sum = E2 / 10 + E2 % 10;
    	i = sum % 10;
	}
	p3=P[i]/100;
	if (p1==1&&p2==1&&p3==1)
	{
		EXP1=ceil((float)0.75*EXP1); EXP1 = kiemTra(EXP1, 0, 600);
	}
	else 
	{
		float avg=(p1+p2+p3)/3;
		if (avg<0.5)
		{
		HP1 =ceil((float)0.85*HP1);     HP1 = kiemTra(HP1, 0, 666);
		EXP1 =ceil((float)1.15*EXP1);	EXP1 = kiemTra(EXP1, 0, 600);
		}
		else 
		{
		HP1 =ceil((float)0.9*HP1);      HP1 = kiemTra(HP1, 0, 666);
		EXP1 =ceil((float)1.2*EXP1);	EXP1 = kiemTra(EXP1, 0, 600);	
		}
	}
	M1 = kiemTra(M1, 0, 3000);
	HP1 = kiemTra(HP1, 0, 666);
	EXP1 = kiemTra(EXP1, 0, 600);
    return HP1 + EXP1 + M1;
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int array_task3[10][10];
    for (int i=0; i<10; i++)
	{
    	for (int j=0; j<10; j++)
		{
    	 array_task3[i][j]=((E3 * j) + (i * 2)) * (i - j);
    	//cout<<array_task3[i][j]<<" ";
		}
		//cout<<endl;
	}
	int soDuong=0, soAm=0;
	for (int i=0; i<10; i++)
	{
    	for (int j=0; j<10; j++)
		{
    	 if (array_task3[i][j]>0 && array_task3[i][j]>E3*2) soDuong++;
    	 else if (array_task3[i][j]<0 && array_task3[i][j]<-E3) soAm++;
		}
		
	}
	//cout<<soDuong<<" "<< soAm<<endl;
	//////////
	int i, j, sum, a, b;
	sum=soDuong/10+soDuong%10;
	if (sum==10) sum=1;
	i=sum%10;a=i;
	sum=soAm/10+soAm%10;
	if (sum==10) sum=1;
	j=sum%10;b=j;
	//cout<<i<<" "<<j<<endl;
	int diemTaxi;
	diemTaxi=array_task3[i][j];
	//cout<< diemTaxi<<endl;
	int diemHaW=diemTaxi;
	while (i >= 0 && j >= 0)
	 {
	    if (array_task3[i][j]>diemHaW) 
		{
	    diemHaW=array_task3[i][j];
	    }
	    i--;
	    j--;	
		
	  }
	//cout<< diemHaW<<endl;
	i=a; j=b;
	while (i >=0 && j < 10)
	 {
	    if (array_task3[i][j]>diemHaW) 
		{
	    diemHaW=array_task3[i][j];
	    }
	    i--;
	    j++;	
		
	  }
	//cout<< diemHaW<<endl;
	i=a; j=b;
	while (i < 10 && j < 10)
	 {
	    if (array_task3[i][j]>diemHaW) 
		{
	    diemHaW=array_task3[i][j];
	    }
	    i++;
	    j++;	
		
	  }
	//cout<< diemHaW<<endl;
	i=a; j=b;
	while (i<10 && j >= 0)
	 {
	    if (array_task3[i][j]>diemHaW) 
		{
	    diemHaW=array_task3[i][j];
	    }
	    i++;
	    j--;	
		
	  }
	//cout<< diemHaW<<endl;
	if ( abs(diemTaxi)>diemHaW) 
	{
		EXP1 = ceil((float)EXP1 * 0.88);   EXP1 = kiemTra(EXP1, 0, 600);
		HP1 = ceil((float)HP1 * 0.9);      HP1 = kiemTra(HP1, 0, 666);
		EXP2 = ceil((float)EXP2 * 0.88);   EXP2 = kiemTra(EXP2, 0, 600);
		HP2 = ceil((float)HP2 * 0.9) ;     HP2 = kiemTra(HP2, 0, 666);
		return diemTaxi;
	}
	else 
	{
		EXP1 = ceil((float)EXP1 * 1.12);   EXP1 = kiemTra(EXP1, 0, 600);
		HP1 = ceil((float)HP1 * 1.1);      HP1 = kiemTra(HP1, 0, 666);
		EXP2 = ceil((float)EXP2 * 1.12);   EXP2 = kiemTra(EXP2, 0, 600);
		HP2 = ceil((float)HP2 * 1.1) ;     HP2 = kiemTra(HP2, 0, 666);
		return diemHaW;
	}
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
          string s1, email1;
          s1=s; email1=email;
          int value;
		  int n = s1.length();
		  int pos=email1.find('@');
		  string se = email1.substr(0,pos);
		  bool trungNhau, haiKiTu;
		  if (n < 8) 
		  {
		  value=-1;
          }
		  if (n > 20) 
          {
		  value=-2;
          }
		  //
		  if (n>=8 && n<=20)
        {
		  if (s1.find(se) != string::npos) 
		  {
    			value= -(300 + s1.find(se));trungNhau=true;
    			
		  } else  trungNhau=false;
		  //
		  bool kyTuDacBiet = false;
		  for (int i = 0; i < n; i++) 
		  {
		    if ( s1[i] == '@' || s1[i] == '#' || s1[i] == '%' || s1[i] == '$' || s1[i] == '!') 
			{
		      kyTuDacBiet = true;
		      break;
		    }
		  }
		  if (kyTuDacBiet==false) 
		  {	
			  value= -5;
	      }
		  //
		  if (trungNhau==true && haiKiTu==true && kyTuDacBiet==true) value= -10;
          }
    return value;
}
// Task 5
int SoLanXuatHien(string x,string arr[], int n)
{
	int dem = 0;
	for(int i=0;i<n;i++)
	{
		if (arr[i] == x)
			dem++;
	}
	return dem;
}
int findCorrectPassword(const char* arr_pwds[], int num_pwds) 
{
    string arr_pwds1[num_pwds];
    for (int i=0;i<num_pwds;i++)
    {
    	arr_pwds1[i]=arr_pwds[i];
	}
	int chieuDaiMax = 0;
	int soLanMax = 0;
	int res = 0;
 	for (int i=0;i<num_pwds;i++)
 	{
 		int cnt = SoLanXuatHien(arr_pwds1[i],arr_pwds1,num_pwds);
 		if (cnt > soLanMax )
 		{
			res = i;
			chieuDaiMax = arr_pwds1[i].size();
 			soLanMax = cnt;
		}
		else if (cnt == soLanMax)
		{
			if (arr_pwds1[i].size() > chieuDaiMax)
 			{
 				res = i;
	 			chieuDaiMax = arr_pwds1[i].size();
	 			soLanMax = cnt;
		 	}
		}
	}
	return res;
} 

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////