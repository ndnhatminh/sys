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
int firstMeet(int & exp1, int & exp2, int e1) 
{
    // TODO: Complete this function
    //Kiem tra dieu kien
    	if(exp1>600) exp1=600;
		if (exp2>600) exp2=600;
		if(exp1<0) exp1=0;
		if (exp2<0) exp2=0;
    	const double k=0.999;
        if (e1<0 || e1>99) return -99;
        else
	        if (0<=e1 & e1<=3)
	        {
	            switch(e1)
	            {
	                case 0:
	                    exp2+=29;
	                    break;
	                case 1:
	                    exp2+=45;
	                    break;
	                case 2:
	                    exp2+=75;
	                    break;
	                case 3:
	                    exp2+=(29+45+75);
	                    break;
	                default:
	                    break;
	            }
	            int D;
	            D=e1*3+exp1*7;
	            if(D%2 ==0)
	            	{
	                	exp1=exp1+(double)D/200+k;
	            	}
	        	else
	            	{
	                	exp1=exp1-(double)D/100+k;
	            	}
	            if (exp2>600) exp2=600;
	            if (exp1<0) exp1=0; else if (exp1>600) exp1=600;
	        }
	        else
	        {
	        	if (4<=e1 & e1<=19)
	        		{
	        			exp2=exp2+(double)e1/4+19+k;
	        			if (exp2>600) exp2=600;
					}
				if (20<=e1 & e1<=49)
	        		{
	        			exp2=exp2+(double)e1/9+21+k;
	        			if (exp2>600) exp2=600;
					}
				if (50<=e1 & e1<=65)
	        		{
	        			exp2=exp2+(double)e1/16+17+k;
	        			if (exp2>600) exp2=600;
					}
				if (66<=e1 & e1<=79)	
					{
						exp2=exp2+(double)e1/4+19+k;
	        			if(exp2>200)
	        				{
	        					exp2=exp2+(double)e1/9+21+k;
	        					if (exp2>600) exp2=600;
							}
					}
				if (80<=e1 & e1<=99)
					{
						exp2=exp2+(double)e1/4+19+k;
	        			exp2=exp2+(double)e1/9+21+k;
	        			if(exp2>400)
	        				{
	        					exp2=exp2+(double)e1/16+17+k;
	        					exp2=exp2*1.15+k;
	        					if (exp2>600) exp2=600;
							}
					}
				exp1=exp1-e1;
				if (exp1<0) exp1=0;
			}
    return exp1 + exp2;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
    // TODO: Complete this function
    const double k=0.999;
	int x,n,y,z,a[10]={32,47,28,79,100,50,22,83,64,11};
    double p,p1,p2,p3;
    //Kiem tra dieu kien
    if(EXP1>600) EXP1=600;
	if (HP1>666) HP1=666;
	if (M1>3000) M1=3000;
	if(EXP1<0) EXP1=0;
	if (HP1<0) HP1=0;
	if (M1<0) M1=0;
    //Con duong 01
	x=round(sqrt(EXP1));
    n= (double) M1/2+k;
	if (EXP1<(x*x)) p1=double (EXP1/(x*x)+80)/123*100; else p1=100;
	//Con duong 02
    if (0<=E2 & E2<=99)
	    {
			if (E2%2 != 0)
		    {
				while(M1>=n)
			    {
				    if (HP1<200)
				    	{
				    		HP1=HP1*1.3+k;
				    		M1-=150;
							if (M1<0) M1=0;
				    		if(M1<n) break;
						}
					else 
						{
							HP1=HP1*1.1+k;
				    		M1-=70;	
							if (M1<0) M1=0;
				    		if(M1<n) break;
						}
					if (EXP1<400)
						{					
							M1-=200;
							if (M1<0) M1=0;
							EXP1=EXP1*1.13+k;
							if(M1<n) break;
						}
					else 
						{
							EXP1=EXP1*1.13+k;
							M1-=120;
							if (M1<0) M1=0;
							if (EXP1>600) EXP1=600;
							if(M1<n) break;	
						}
					if (EXP1<300)
						{
							M1-=100;
							if (M1<0) M1=0;
							EXP1=EXP1*0.9+k;
							if(M1<n) break;
						}
					else 
						{
							M1-=120;
							if (M1<0) M1=0;
							EXP1=EXP1*0.9+k;
							if(M1<n) break;
						}		
				}				
			}
			else 
			{
				for (int i=0; i<3; i++)
					{
						if(M1<=0) 
							{ 
								M1=0;
								continue;
							}
						switch(i)
						{
							case 0:
								if (HP1<200)
							    	{			
							    		HP1=HP1*1.3+k;
							    		M1-=150;
							    		break;
									}
								else 
									{
										HP1=HP1*1.1+k;
							    		M1-=70;
										break;	
									}
							case 1:
								if (EXP1<400)
									{
										EXP1=EXP1*1.13+k;
										M1-=200;
										break;
									}
								else 
									{
										EXP1=EXP1*1.13+k;
										M1-=120;
										if (EXP1>600) EXP1=600;
										break;
									}
							case 2:
								if (EXP1<300)
									{
										M1-=100;
										EXP1=EXP1*0.9+k;
										if (M1<0) M1=0;
										break;
									}
								else 
									{
										M1-=120;
										EXP1=EXP1*0.9+k;
										if (M1<0) M1=0;
										break;
									}	
						}
					}
			}
		if (HP1>666) HP1=666;
		EXP1=EXP1*1.17+k;
		if (EXP1>600) EXP1=600;
		HP1=HP1*(1-0.17)+k;
		y=round(sqrt(EXP1));
		if (EXP1<(y*y)) p2=double (EXP1/(y*y)+80)/123*100; else p2=100;
		//Con duong 03	
		if (0<=E2 & E2<10) p3=a[E2];
		else 
			if (10<=E2 &E2<100)
				{
					z=(E2-(E2/10)*9);
					p3=a[z-z/10*10];
				} 
		if (p1==100 & p2==100 & p3==100) EXP1=EXP1*0.75+k;
		else 
			{
				p=(double) (p1+p2+p3)/3;
				if (p<50)
					{
						HP1=HP1*0.85+k;
						EXP1=EXP1*1.15+k;
					}
				else
					{
						HP1=HP1*0.9+k;
						EXP1=EXP1*1.2+k;
					}
				if(EXP1>600) EXP1=600;
			}
		return EXP1 + HP1 + M1;
		}
	else return -99;
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) 
{
    // TODO: Complete this function
    //Kiem tra dieu kien
	if(EXP1>600) EXP1=600;
	if (EXP2>600) EXP2=600;
	if (HP1>666) HP1=666;
	if (HP2>666) HP2=666;
	if(EXP1<0) EXP1=0;
	if (EXP2<0) EXP2=0;
	if (HP1<0) HP1=0;
	if (HP2<0) HP2=0;
 	int max, x, m=0, n=0;
 	int m1,m2,m3,n1,n2,n3;
	int a[10][10];
	const double k=0.999;
	if (E3<0 || E3>99) return -99;
	else
	{
		for (int i=0 ; i < 10 ; i++)
			for(int j=0; j < 10; j++ )
				a[i][j]=((E3*j)+(i*2))*(i-j);
		for (int i=0; i < 10 ; i++)
			for(int j=0; j < 10; j++ )
				{
					if (a[i][j]>E3*2) m++;
					if (a[i][j]<-E3) n++;
				}
		while (9<m & m<100)
			{
				m=m/10+m%10;
			}	 
		while (9<n & n<100)
			{
				n=n/10+n%10;
			}
		max=a[m][n];
		x=a[m][n];
		m1=m2=m3=m;
		n1=n2=n3=n;
		while (n<10 & m<10)
		{
			if (max<a[m][n]) max=a[m][n];
			m++;
			n++;
		}
		while ( m1>=0 & n1<10)
		{
			if (max<a[m1][n1]) max=a[m1][n1];
			m1--;
			n1++;
		}
		while ( m2>=0 & n2>=0)
		{
			if (max<a[m2][n2]) max=a[m2][n2];
			m2--;
			n2--;
		}
		while ( m3<10 & n3>=0)
		{
			if (max<a[m3][n3]) max=a[m3][n3];
			m3++;
			n3--;
		}
		if (max>=abs(x)) 
		{
			EXP1=EXP1*1.12+k;
			EXP2=EXP2*1.12+k;
			HP1=HP1*1.1+k;
			HP2=HP2*1.1+k;
			if(EXP1>600) EXP1=600;
			if (EXP2>600) EXP2=600;
			if (HP1>666) HP1=666;
			if (HP2>666) HP2=666;
			return max;
		}
		else
		{
			EXP1=EXP1*0.88+k;
			EXP2=EXP2*0.88+k;
			HP1=HP1*0.9+k;
			HP2=HP2*0.9+k;
			return x;
		}
	}
}
// Task 4
int checkPassword(const char * s, const char * email) 
{
    // TODO: Complete this function
string s1=s, email1=email;
string se;
int k=0;
	for (int i=0; i<email1.find('@');i++)
		{
				se+=email1[i];
		}
	if (8<=s1.length() & s1.length()<=20)
		{	
			if (s1.find(se)<s1.size()) return -(300+s1.find(se));
			for (int i=0; i<s1.size()-2; i++)
			if(s1[i]==s1[i+1] & s1[i+1]==s1[i+2]) 
				{
					return -(400+i);
					break;
				} 
			for (int i=0; i<s1.size(); i++)
					if (s1[i] == '@'||s1[i] == '#'||s1[i] == '%'||s1[i] == '$'||s1[i] == '!') 	k++;
			if (k==0) return -5; 
			for (int i=0; i<s1.size(); i++)
			{
				if(s1[i]==33 || 35<=s1[i] & s1[i]<=37 || 48<=s1[i] & s1[i]<=57 
					|| 64<=s1[i] & s1[i]<=90 || 97<=s1[i] & s1[i]<=122) continue;
				else return i;
			}
			return -10;
		}
	else 
	 {
		if (s1.length()<8) return -1;
		else return -2;
	 }
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
	int m=0, n=0, t = 0, i=0;
	string k;
	string a[num_pwds];
	for (int i=0; i<num_pwds; i++)
	{
		a[i]=arr_pwds[i];
	}
	for (int i=0; i<num_pwds; i++)
	{
		int x=0;
		for (int j=0; j<num_pwds; j++)
		{
			if (a[j]==a[i]) x++;
		}
		if (x>m)
		{
			m=x;
			n=a[i].length();
			k=a[i];
			t = i;
		}
		else if(x == m & a[i].length()>n)
		{
			m= x;
			n=a[i].length();
			k=a[i];
			t = i;
		}
	}
	for (int h=0; h<num_pwds;h++)
	{
		if(a[h]==a[t])
		{
			t=h;
			break;
		}
	}
	return t;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////