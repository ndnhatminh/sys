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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
////////////////// CHECK E1/////////////////////////
if ((e1<0) || (e1>=100)) return -99;
//--------------------------------------------------
////////////// CHECK EXP1 & EXP2 ///////////////////
if (exp1<0) exp1=0;
else if (exp1>600) exp1=600;
if (exp2<0) exp2=0;
else if (exp2>600) exp2=600;
////////////////////////////////////////////////////

    //// TRUONG HOP 1
    if ((e1<=3)&&(e1>=0))
    {
    	if (e1==0)
    	{
    		exp2+=29;
		}
		else if (e1==1)
		{
			exp2+=45;
		}
		else if (e1==2)
		{
			exp2+=75;
		}
		else if (e1==3)
		{
			exp2+=149;
		}
////////////// CHECK EXP1 & EXP2 ///////////////////
if (exp1<0) exp1=0;
else if (exp1>600) exp1=600;
if (exp2<0) exp2=0;
else if (exp2>600) exp2=600;
////////////////////////////////////////////////////		
	int D;
	float exp1_float;
	D= e1*3 + exp1*7;
		if (D%2==0) 
			{
			exp1_float= exp1 + D/200.0;
			exp1=ceil(exp1_float);
			}
		else 
			{
			exp1_float= exp1 - D/100.0;
			exp1=ceil(exp1_float);
			}	
	}
	//// TRUONG HOP 2
    else if ((e1>=4)&&(e1<=99))	
    {
    	float EXP2_float;
    	if ((e1>=4)&&(e1<=19)) // thong tin 1
    	{
    		EXP2_float=exp2+e1/4.0+19; 
    		exp2 = ceil(EXP2_float);
		}
    	else if ((e1>=20)&&(e1<=49)) // thong tin 2
    	{
    		EXP2_float=exp2+e1/9.0+21;
    		exp2 = ceil(EXP2_float);
		}
    	else if ((e1>=50)&&(e1<=65)) // thong tin 3
    	{
    		EXP2_float=exp2+e1/16.0+17;
    		exp2 = ceil(EXP2_float);
		}
    	else if ((e1>=66)&&(e1<=79)) // thong tin 4 (1+2)
    	{
    		EXP2_float=exp2+e1/4.0+19;
    		exp2 = ceil(EXP2_float);
    		if (exp2>200) 
    		{
    		    EXP2_float=exp2+e1/9.0+21;
    		    exp2 = ceil(EXP2_float);
    		}
		}
		else if ((e1>=80)&&(e1<=99)) // thong tin 5 (1+2+3)
	    {
			EXP2_float=exp2+e1/4.0+19; exp2=ceil(EXP2_float);
			EXP2_float=exp2+e1/9.0+21; exp2=ceil(EXP2_float);
			if (exp2>400) 
			{
				EXP2_float=exp2+e1/16.0+17; 
				exp2=ceil(EXP2_float);
			    EXP2_float=exp2*1.15;
			    exp2 = ceil(EXP2_float);
			}
		}
	exp1-=e1;
	}
	
////////////////// CHECK EXP1 & EXP2 /////////////////////
if (exp1<0) exp1=0;
else if (exp1>600) exp1=600;
if (exp2<0) exp2=0;
else if (exp2>600) exp2=600;
//////////////////////////////////////////////////////////

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
        
////////////////// CHECK E2/////////////////////////
if ((E2<0) || (E2>=100)) return -99;
//------------------------------------------------//
//////////////  CHECK EXP1 & HP1 & M1 //////////////
if (EXP1<0) EXP1=0;
else if (EXP1>600) EXP1=600;
if (HP1<0) HP1=0;
else if (HP1>666) HP1=666;
if (M1<0) M1=0;
else if (M1>3000) M1=3000;
////////////////////////////////////////////////////


float P1,P2; 
/////////// NEAREST SQUARE NUMBER TO EXP1 ///////////
double square_check;
double S;
square_check=sqrt(EXP1); 
square_check=round(square_check); 
S=square_check*square_check;
////////////////////////////////////////////////////

//// CON DUONG 1
if (EXP1>=S) {P1 = 1;}
else 
{
	P1=(EXP1/S+80)/123;
}

//// CON DUONG 2
float HP1_float,EXP1_float_2;
float half_money;
int initial_money,used_money;
initial_money=M1;
half_money=0.5*initial_money;
int count=0;
if (M1==0) 
{
   HP1=HP1;
   EXP1=EXP1;
   M1=M1;
}
else 
{
if (E2%2==0)
{
    while (count==0)
    {
	    //---------------------------------1
            	if (HP1<200)
            	{
            		HP1_float=HP1*1.3;
            		HP1=ceil(HP1_float);
            		M1-=150;
					//////////////  CHECK EXP1 & HP1 & M1 //////////////
					if (EXP1<0) EXP1=0;
					else if (EXP1>600) EXP1=600;
					if (HP1<0) HP1=0;
					else if (HP1>666) HP1=666;
					if (M1<0) M1=0;
					else if (M1>3000) M1=3000;
					////////////////////////////////////////////////////
            		if (M1==0) {break;}
            	}
            	else if (HP1>=200)
            	{
            		HP1_float=HP1*1.1;
            		HP1=ceil(HP1_float);
            		M1-=70; 
					//////////////  CHECK EXP1 & HP1 & M1 //////////////
					if (EXP1<0) EXP1=0;
					else if (EXP1>600) EXP1=600;
					if (HP1<0) HP1=0;
					else if (HP1>666) HP1=666;
					if (M1<0) M1=0;
					else if (M1>3000) M1=3000;
					////////////////////////////////////////////////////
            		if (M1==0) {break;}
            	}
        //---------------------------------
            
        //---------------------------------2
                if (EXP1<400)
                {
                    M1-=200; 
                    EXP1_float_2=EXP1*1.13;
                    EXP1=ceil(EXP1_float_2);
					//////////////  CHECK EXP1 & HP1 & M1 //////////////
					if (EXP1<0) EXP1=0;
					else if (EXP1>600) EXP1=600;
					if (HP1<0) HP1=0;
					else if (HP1>666) HP1=666;
					if (M1<0) M1=0;
					else if (M1>3000) M1=3000;
					////////////////////////////////////////////////////
            		if (M1==0) {break;}
                }
                else if (EXP1>=400) 
                {
                    M1-=120;
                    EXP1_float_2=EXP1*1.13;
                    EXP1=ceil(EXP1_float_2);
					//////////////  CHECK EXP1 & HP1 & M1 //////////////
					if (EXP1<0) EXP1=0;
					else if (EXP1>600) EXP1=600;
					if (HP1<0) HP1=0;
					else if (HP1>666) HP1=666;
					if (M1<0) M1=0;
					else if (M1>3000) M1=3000;
					////////////////////////////////////////////////////
            		if (M1==0) {break;}
                }
        //---------------------------------
            
        //---------------------------------3
                if (EXP1<300) 
                {
                    M1-=100;
                    EXP1_float_2=0.9*EXP1;
                    EXP1=ceil(EXP1_float_2);
					//////////////  CHECK EXP1 & HP1 & M1 //////////////
					if (EXP1<0) EXP1=0;
					else if (EXP1>600) EXP1=600;
					if (HP1<0) HP1=0;
					else if (HP1>666) HP1=666;
					if (M1<0) M1=0;
					else if (M1>3000) M1=3000;
					////////////////////////////////////////////////////
            		if (M1==0) {break;}
                }
                else if (EXP1>=300) 
                {
                    M1-=120;
                    EXP1_float_2=0.9*EXP1;
                    EXP1=ceil(EXP1_float_2);
					//////////////  CHECK EXP1 & HP1 & M1 //////////////
					if (EXP1<0) EXP1=0;
					else if (EXP1>600) EXP1=600;
					if (HP1<0) HP1=0;
					else if (HP1>666) HP1=666;
					if (M1<0) M1=0;
					else if (M1>3000) M1=3000;
					////////////////////////////////////////////////////
            		if (M1==0) {break;}
                }
        //---------------------------------
    count+=1;
    }
}
else if (E2%2!=0)
{
	used_money=0;
	while(used_money<=half_money)
	{
	    //---------------------------------1
            	if (HP1<200)
            	{
            		HP1_float=HP1*1.3;
            		HP1=ceil(HP1_float);
            		M1-=150;
					//////////////  CHECK EXP1 & HP1 & M1 //////////////
					if (EXP1<0) EXP1=0;
					else if (EXP1>600) EXP1=600;
					if (HP1<0) HP1=0;
					else if (HP1>666) HP1=666;
					if (M1<0) M1=0;
					else if (M1>3000) M1=3000;
					////////////////////////////////////////////////////
            		used_money+=150;
                    if (M1==0) {break;}
            	    if (used_money>half_money) {break;}
            	}
            	else if (HP1>=200)
            	{
            		HP1_float=HP1*1.1;
            		HP1=ceil(HP1_float);
            		M1-=70; 
					 //////////////  CHECK EXP1 & HP1 & M1 //////////////
					if (EXP1<0) EXP1=0;
					else if (EXP1>600) EXP1=600;
					if (HP1<0) HP1=0;
					else if (HP1>666) HP1=666;
					if (M1<0) M1=0;
					else if (M1>3000) M1=3000;
					////////////////////////////////////////////////////
            		used_money+=70;
                    if (M1==0) {break;}
            	    if (used_money>half_money) {break;}
            	}
        //---------------------------------
            
        //---------------------------------2
                if (EXP1<400)
                {
                    M1-=200; 
                    EXP1_float_2=EXP1*1.13;
                    EXP1=ceil(EXP1_float_2);
					//////////////  CHECK EXP1 & HP1 & M1 //////////////
					if (EXP1<0) EXP1=0;
					else if (EXP1>600) EXP1=600;
					if (HP1<0) HP1=0;
					else if (HP1>666) HP1=666;
					if (M1<0) M1=0;
					else if (M1>3000) M1=3000;
					////////////////////////////////////////////////////
            	    used_money+=200;            		
                    if (M1==0) {break;}

            	    if (used_money>half_money) {break;}
                }
                else if (EXP1>=400) 
                {
                    M1-=120;
                    EXP1_float_2=EXP1*1.13;
                    EXP1=ceil(EXP1_float_2);
					//////////////  CHECK EXP1 & HP1 & M1 //////////////
					if (EXP1<0) EXP1=0;
					else if (EXP1>600) EXP1=600;
					if (HP1<0) HP1=0;
					else if (HP1>666) HP1=666;
					if (M1<0) M1=0;
					else if (M1>3000) M1=3000;
					////////////////////////////////////////////////////
            	    used_money+=120;            		
                    if (M1==0) {break;}
            	    if (used_money>half_money) {break;}
                }
        //---------------------------------
            
        //---------------------------------3
                if (EXP1<300) 
                {
                    M1-=100;
                    EXP1_float_2=0.9*EXP1;
                    EXP1=ceil(EXP1_float_2);
					//////////////  CHECK EXP1 & HP1 & M1 //////////////
					if (EXP1<0) EXP1=0;
					else if (EXP1>600) EXP1=600;
					if (HP1<0) HP1=0;
					else if (HP1>666) HP1=666;
					if (M1<0) M1=0;
					else if (M1>3000) M1=3000;
					////////////////////////////////////////////////////
             	    used_money+=100;           		
                    if (M1==0) {break;}
            	    if (used_money>half_money) {break;}
                }
                else if (EXP1>=300) 
                {
                    M1-=120;
                    EXP1_float_2=0.9*EXP1;
                    EXP1=ceil(EXP1_float_2);
					//////////////  CHECK EXP1 & HP1 & M1 //////////////
					if (EXP1<0) EXP1=0;
					else if (EXP1>600) EXP1=600;
					if (HP1<0) HP1=0;
					else if (HP1>666) HP1=666;
					if (M1<0) M1=0;
					else if (M1>3000) M1=3000;
					////////////////////////////////////////////////////
            	    used_money+=120;
                    if (M1==0) {break;}
            	    if (used_money>half_money) {break;}
                }
        //---------------------------------
	}
}
}
HP1_float=0.83*HP1;
HP1=ceil(HP1_float);
EXP1_float_2=1.17*EXP1;
EXP1=ceil(EXP1_float_2);
//////////////  CHECK EXP1 & HP1 & M1 //////////////
if (EXP1<0) EXP1=0;
else if (EXP1>600) EXP1=600;
if (HP1<0) HP1=0;
else if (HP1>666) HP1=666;
if (M1<0) M1=0;
else if (M1>3000) M1=3000;
////////////////////////////////////////////////////
/////////// NEAREST SQUARE NUMBER TO EXP1 - PART 2 ///////////
double square_check_2;
double S_2;
square_check_2=sqrt(EXP1); 
square_check_2=round(square_check_2); 
S_2=square_check_2*square_check_2;
//////////////////////////////////////////////////////////////
// Calculate P2
if (EXP1>=S_2) {P2 = 1;}
else 
{
	P2=(EXP1/S_2+80)/123;
}

//// CON DUONG 3
int P[10] = {32,47,28,79,100,50,22,83,64,11};
int i;
int E2_check_1, E2_check_2, E2_check_3;
float digit_check, P3;
float avg_P;
E2_check_1=E2/10;
E2_check_2=E2%10;
E2_check_3= E2_check_1 + E2_check_2;
digit_check=E2/10.0;
if (digit_check>=1)
{
	i=E2_check_3%10;
}
else {i=E2;}
P3=P[i];
float P3_2;
P3_2=P3/100;

//////////////////////////////////////////OVERALL
if ((P1==1)&&(P2==1)&&(P3_2==1)) 
	{
		EXP1_float_2=0.75*EXP1;
		EXP1=ceil(EXP1_float_2);
		//////////////  CHECK EXP1 & HP1 & M1 //////////////
		if (EXP1<0) EXP1=0;
		else if (EXP1>600) EXP1=600;
		if (HP1<0) HP1=0;
		else if (HP1>666) HP1=666;
		if (M1<0) M1=0;
		else if (M1>3000) M1=3000;
		////////////////////////////////////////////////////
	}
else 
{
	avg_P=(P1+P2+P3_2)/3.0;
	if (avg_P<0.5)
	{
		HP1_float=0.85*HP1;
		HP1=ceil(HP1_float);
		EXP1_float_2=1.15*EXP1;
		EXP1=ceil(EXP1_float_2);
		//////////////  CHECK EXP1 & HP1 & M1 //////////////
		if (EXP1<0) EXP1=0;
		else if (EXP1>600) EXP1=600;
		if (HP1<0) HP1=0;
		else if (HP1>666) HP1=666;
		if (M1<0) M1=0;
		else if (M1>3000) M1=3000;
		////////////////////////////////////////////////////
	}
	else if (avg_P>=0.5)
	{
		HP1_float=0.9*HP1;
		HP1=ceil(HP1_float);
		EXP1_float_2=1.2*EXP1;
		EXP1=ceil(EXP1_float_2);
		//////////////  CHECK EXP1 & HP1 & M1 //////////////
		if (EXP1<0) EXP1=0;
		else if (EXP1>600) EXP1=600;
		if (HP1<0) HP1=0;
		else if (HP1>666) HP1=666;
		if (M1<0) M1=0;
		else if (M1>3000) M1=3000;
		////////////////////////////////////////////////////
	}
}

return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
////////////////// CHECK E3/////////////////////////
if ((E3<0) || (E3>=100)) return -99;
//------------------------------------------------//
///////  CHECK EXP1 & HP1 AND EXP2 & HP2 ///////////
if (EXP1<0) EXP1=0;
else if (EXP1>600) EXP1=600;
if (HP1<0) HP1=0;
else if (HP1>666) HP1=666;
if (EXP2<0) EXP2=0;
else if (EXP2>600) EXP2=600;
if (HP2<0) HP2=0;
else if (HP2>666) HP2=666;
////////////////////////////////////////////////////  

int map[10][10];
////// GENERATE THE ARRAY
    for (int i=0; i<10; ++i) 
	{
        for (int j=0; j<10; ++j) 
		{
            map[i][j] = ((E3*j) + (i*2)) * (i-j);
        }
    }
    
int E3_check_1, E3_check_2;
int count_positive, count_negative;
E3_check_1=E3*2;
E3_check_2=-E3;
count_positive=0;
count_negative=0;

///// Finding position (i,j)
     for (int i=0; i<10; ++i) 
	{
        for (int j=0; j<10; ++j) 
		{
            if (map[i][j]>E3_check_1) 
				{
            		count_positive+=1;
				}
			if (map[i][j]<E3_check_2)
				{
					count_negative+=1;	
				}
        }
    }   
    
///// Find position i (a)
int a;
a=count_positive;
    while (a>=10) 
	{
        int sum_1=0;
        while (a>0) 
        {
            sum_1+=a%10; 
            a/=10; 
        }
        a=sum_1; 
    }    
///// Find position j (b)
int b;
b=count_negative; 
    while (b>=10) 
	{
        int sum_2=0;
        while (b>0) 
        {
            sum_2+=b%10; 
            b/=10; 
        }
        b=sum_2; 
    }
  
//// Calculate Sherlock&Watson grade-------------------------------------------------------------
// Calculate the maximum value from the left diagonal////////////////////////////////////////////
int leftdiagonal_max=INT_MIN;
int left_row=a, left_col=b;
    while (left_row>=0 && left_col>=0) 
	{
        leftdiagonal_max=max(leftdiagonal_max,map[left_row][left_col]);
        left_row--;
        left_col--;
    }
    left_row=a+1;
    left_col=b+1;
        while (left_row<10 && left_col<10) 
    {
        leftdiagonal_max=max(leftdiagonal_max,map[left_row][left_col]);
        left_row++;
        left_col++;
    }
//////////////////////////////////////////////////////////////////////////////////////////////////    
// Calculate the maximum value from the right diagonal
int rightdiagonal_max = INT_MIN;
int right_row=a, right_col=b;
    while (right_row>=0 && right_col<10) 
    {
        rightdiagonal_max = max(rightdiagonal_max, map[right_row][right_col]);
        right_row--;
        right_col++;
    }
    right_row = a + 1;
    right_col = b - 1;
    while (right_row<10 && right_col>=0) 
    {
        rightdiagonal_max = max(rightdiagonal_max, map[right_row][right_col]);
        right_row++;
        right_col--;
    }
//////////////////////////////////////////////////////////////////////////////////////////////////
int sherlock_grade;
int sherlock_grade_abs;
// Maximum value from both diagonals
if (rightdiagonal_max>leftdiagonal_max) {sherlock_grade=rightdiagonal_max;}
else {sherlock_grade=leftdiagonal_max;}
////-----------------------------------------------------------------------------------------------
float EXP1_task_3, HP1_task_3, EXP2_task_3, HP2_task_3;  
int taxi_grade, taxi_grade_abs;
taxi_grade_abs=abs(map[a][b]);
taxi_grade=map[a][b];
sherlock_grade_abs=abs(sherlock_grade);
if (taxi_grade_abs>sherlock_grade_abs)
    {
    	EXP1_task_3=EXP1*0.88; EXP1=ceil(EXP1_task_3);
    	EXP2_task_3=EXP2*0.88; EXP2=ceil(EXP2_task_3);
    	HP1_task_3=HP1*0.9; HP1=ceil(HP1_task_3);
    	HP2_task_3=HP2*0.9; HP2=ceil(HP2_task_3);
    	//////// CHECK EXP1 & HP1 AND EXP2 & HP2 ///////////
		if (EXP1<0) EXP1=0;
		else if (EXP1>600) EXP1=600;
		if (HP1<0) HP1=0;
		else if (HP1>666) HP1=666;
		if (EXP2<0) EXP2=0;
		else if (EXP2>600) EXP2=600;
		if (HP2<0) HP2=0;
		else if (HP2>666) HP2=666;
		////////////////////////////////////////////////////  
    	return taxi_grade;
	}
else 
	{
    	EXP1_task_3=EXP1*1.12; EXP1=ceil(EXP1_task_3);
    	EXP2_task_3=EXP2*1.12; EXP2=ceil(EXP2_task_3);
    	HP1_task_3=HP1*1.1; HP1=ceil(HP1_task_3);
    	HP2_task_3=HP2*1.1;	HP2=ceil(HP2_task_3);
    	///////  CHECK EXP1 & HP1 AND EXP2 & HP2 ///////////
		if (EXP1<0) EXP1=0;
		else if (EXP1>600) EXP1=600;
		if (HP1<0) HP1=0;
		else if (HP1>666) HP1=666;
		if (EXP2<0) EXP2=0;
		else if (EXP2>600) EXP2=600;
		if (HP2<0) HP2=0;
		else if (HP2>666) HP2=666;
		////////////////////////////////////////////////////  
     	return sherlock_grade_abs;
	}

}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
string password(s);
string check_email(email);
// Find se
string se = check_email.substr(0, check_email.find('@'));
//////////////////////// 1) CHECK LENGTH ///////////////////////////////
if (password.length() < 8) return -1;
if (password.length() > 20) return -2;
//--------------------------------------------------------------------//
//////////////////////// 2) CHECK SE ///////////////////////////////////
int pos=password.find(se);
if (pos!=string::npos) return -(300 + pos);
//--------------------------------------------------------------------//
/////////////////////// 3) CHECK IDENTICAL CHAR ////////////////////////
for (int i=0; i<password.length() - 2; ++i) 
    {
        if (password[i]==password[i+1]&&password[i]==password[i+2])
            {return -(400 + i);}
    }
//--------------------------------------------------------------------//
/////////////////////// 4) CHECK SPECIAL CHAR //////////////////////////
bool check_special_char = false;
for (int i = 0; i < password.length(); ++i) 
	{
        char c = password[i];
        if (!(((c>='0')&&(c<='9')) || (((c>='a')&&(c<='z'))||((c>='A')&&(c<='Z'))) || c=='@' || c=='#' || c=='%' || c=='$' || c=='!')) 
        {
            return i; 
        } 
        else if (!((c>='0')&&(c<='9')) && !(((c>='a')&&(c<='z'))||((c>='A')&&(c<='Z'))) && (c=='@' || c=='#' || c=='%' || c=='$' || c=='!')) 
        {
            check_special_char = true;
        }
    }
if (!check_special_char) {return -5;}
//// Valid pass
return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
///////////////// Count the occurrences of each password///////////////////////
const char * check_pwds[30]; 
int password_counts[30]={0};
int unique_count=0;
    for (int i=0;i<num_pwds;++i) 
    {
        bool found=false;
        for (int j=0; j<unique_count; ++j) 
        {
            if (strcmp(arr_pwds[i], check_pwds[j])==0) 
            {
                password_counts[j]++;
                found=true;
                break;
            }
        }
        if (!found) 
        {
            check_pwds[unique_count]=arr_pwds[i];
            password_counts[unique_count]++;
            unique_count++;
        }
    }
////////////////////////////////////////////////////////////////////////////////
//////////////////Check the most frequently occurring password//////////////////
    int max_count=0;
    for (int i=0;i<unique_count;++i) {
        max_count=max(max_count,password_counts[i]);
    }
////////////////////////////////////////////////////////////////////////////////    
////////////////////Check passwords with maximum occurrences////////////////////
const char * most_frequent_passwords[30]; 
int most_frequent_count=0;
    for (int i=0;i<unique_count;++i) 
	{
        if (password_counts[i]==max_count) 
		{
            most_frequent_passwords[most_frequent_count]=check_pwds[i];
            most_frequent_count++;
        }
    }
////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////Check longest password///////////////////////////// 
int max_length=0;
const char * correct_password;
    for (int i=0;i<most_frequent_count;++i) 
    {
        if (strlen(most_frequent_passwords[i])>max_length) 
        {
            max_length=strlen(most_frequent_passwords[i]);
            correct_password=most_frequent_passwords[i];
        }
    }
///////////////////////////////Find the position//////////////////////////////// 
    for (int i=0;i<num_pwds;++i) 
    {
        if (strcmp(arr_pwds[i],correct_password)==0) 
		{
            return i;
        }
    }
return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
