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
    int D;
    float exp11=exp1;
    float exp22=exp2;
    float e11=e1;
    if ((e1>=0) and (e1<=99))
    {
    if (e1<4)
    {
    switch(e1)
    {
    	case 0:
    		{
    			exp22=exp22+29;
    			D=e1*3+exp1*7;
    			float d=D;
    			if (D%2==0) 
				{
				exp11=exp11+d/200;
				exp11=ceil(exp11);
			    }
    			else 
				{
				exp11=exp11-d/100;
				exp11=ceil(exp11);
			    }
			     break;
			}
		case 1:
    		{
    			exp22=exp22+45;
    			D=e1*3+exp11*7;
    			float d=D;
    			if (D%2==0)
				{
				  exp11=exp11+d/200;
				  exp11=ceil(exp11);
			    }
    			else
				{
				 exp11=exp11-d/100;
				 exp11=ceil(exp11);
			    } 
			     break;
			}
		case 2:
    		{
    			exp22=exp22+75;
    			D=e1*3+exp11*7;
    			float d=D;
    			if (D%2==0)
				{
				  exp11=exp11+d/200;
				  exp11=ceilf(exp11);
			    } 
    			else
				{
				 exp11=exp11-d/100;
				 exp11=ceil(exp11);
			    }
			     break;
			}
		case 3:
    		{
    			exp22=exp22+75+45+29;
    			D=e1*3+exp11*7;
    			float d=D;
    			if (D%2==0)
				{
				 exp11=exp11+d/200;
				 exp11=ceil(exp11);
			    }
    			else
				{
				 exp11=exp11-d/100;
				 exp11=ceil(exp11);
			    }
			     break;
			}		
	}
    } else if (e1<=19)
    {
    	exp22=ceil(exp22+(e11/4+19));
    	exp11=exp11-e1;
    	exp22=ceil(exp22);
	} else if (e1<=49)
	{
		exp22=ceil(exp22+(e11/9+21));
    	exp11=exp11-e1;
    	exp22=ceil(exp22);
	} else if (e1<=65)
	{
		exp22=ceil(exp22+(e11/16+17));
    	exp11=exp11-e1;
    	exp22=ceil(exp22);
	}else if (e1<=79)
	{
		exp22=ceil(exp22+(e11/4+19));
		if (exp22>200) exp22=ceil(exp22+(e11/9+21));
		exp11=exp11-e1;
		exp22=ceil(exp22);
	}else if (e1<=99)
	{
		exp22=ceil(exp22+(e11/4+19));
		exp22=ceil(exp22+(e11/9+21));
		if (exp22>400)
		{
		exp22=ceil(exp22+(e11/16+17));
		exp22=ceil(exp22*1.15);
	    }
	     exp11=exp11-e1;
	    exp22=ceil(exp22);
	}
	exp1=exp11;
	exp2=exp22;
	if (exp1>600) exp1=600;
	if (exp2>600) exp2=600;
	if (exp1<0) exp1=0;
	if (exp2<0) exp2=0;
	return exp1 + exp2;
    }
    else
    {
    	e1=-99;
    	return -99;
	}
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
    // TODO: Complete this function
    float exp1,p1,p2,p3,hp1,p,A,s;
    int m1,m,i;
    float P3[10]={0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11};
    exp1=EXP1;
    hp1=HP1;
    m1=M1;
    A=M1*0.5;
     if ((E2>=0) and (E2<=99))
    {
    s=round(sqrt(exp1));
    if (exp1>=s*s) p1=1;
    else p1=(exp1/(s*s)+80)/123;
    if (E2%2!=0)
    {
    	while (1)
    	{
    	
    		if (HP1<200)
            {
            	hp1=hp1*1.3;
   	           HP1=ceil(hp1);
   	           M1=M1-150;
   	           m=m+150;
   	           hp1=HP1;
   	           if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
            }
            else 
            {
            	hp1=hp1*1.1;
   	           HP1=ceil(hp1);
   	           hp1=HP1;
   	           M1=M1-70;
   	           m=m+70;
   	           if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
            }
             if (M1<=0)
            {
            	hp1=hp1*0.83;
            		HP1=ceil(hp1);
   	        hp1=HP1;
   	        exp1=exp1*1.17;
   	        EXP1=ceil(exp1);
   	        exp1=EXP1;
   	        M1=0;
   	        if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
			    if (EXP1>600)
			   {
			      EXP1=600;
			      exp1=EXP1;
			   }
			   break;
			}
            if (m>A)
            {
            	hp1=hp1*0.83;
   	           HP1=ceil(hp1);
   	           hp1=HP1;
   	           exp1=exp1*1.17;
   	           EXP1=ceil(exp1);
   	           exp1=EXP1;
   	           if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
			   if (EXP1>600)
			   {
			      EXP1=600;
			      exp1=EXP1;
			   }
   	           break;
            }
            if (EXP1>400)
            {
   	            M1=M1-120;
   	            m=m+120;
   	            exp1=exp1*1.13;
   	            EXP1=ceil(exp1);
   	            exp1=EXP1;
   	            if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
			    if (EXP1>600)
			   {
			      EXP1=600;
			      exp1=EXP1;
			   }
            }
            else
            {
   	            M1=M1-200;
   	            m=m+200;
   	            exp1=exp1*1.13;
   	            EXP1=ceil(exp1);
   	            exp1=EXP1;
   	            if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
			    if (EXP1>600)
			   {
			      EXP1=600;
			      exp1=EXP1;
			   }
            }
             if (M1<=0)
            {
            	hp1=hp1*0.83;
            		HP1=ceil(hp1);
   	        hp1=HP1;
   	        exp1=exp1*1.17;
   	        EXP1=ceil(exp1);
   	        exp1=EXP1;
   	        M1=0;
   	        if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
			    if (EXP1>600)
			   {
			      EXP1=600;
			      exp1=EXP1;
			   }
			   break;
			}
            if (m>A)
            {
            	hp1=hp1*0.83;
   	            HP1=ceil(hp1);
   	            hp1=HP1;
   	            exp1=exp1*1.17;
   	            EXP1=ceil(exp1);
   	            exp1=EXP1;
   	            if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
			    if (EXP1>600)
			   {
			      EXP1=600;
			      exp1=EXP1;
			   }
   	            break;
            }
            if (EXP1<300)
            {
   	            M1=M1-100;
   	             m=m+100;
   	             exp1=exp1*0.9;
   	             EXP1=ceil(exp1);
   	            exp1=EXP1;
   	            if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
			    if (EXP1>600)
			   {
			      EXP1=600;
			      exp1=EXP1;
			   }
            }
            else
            {
   	              M1=M1-120;
   	              m=m+120;
   	              exp1=exp1*0.9;
   	              EXP1=ceil(exp1);
   	              exp1=EXP1;
   	              if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
			    if (EXP1>600)
			   {
			      EXP1=600;
			      exp1=EXP1;
			   }
            }
            if (M1<=0)
            {
            	hp1=hp1*0.83;
            		HP1=ceil(hp1);
   	        hp1=HP1;
   	        exp1=exp1*1.17;
   	        EXP1=ceil(exp1);
   	        exp1=EXP1;
   	        M1=0;
   	        if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
			    if (EXP1>600)
			   {
			      EXP1=600;
			      exp1=EXP1;
			   }
			   break;
			}
            if (m>A)
            {
            	hp1=hp1*0.83;
   	              HP1=ceil(hp1);
   	              hp1=HP1;
   	              exp1=exp1*1.17;
   	              EXP1=ceil(exp1);
   	              exp1=EXP1;
   	              if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
			    if (EXP1>600)
			   {
			      EXP1=600;
			      exp1=EXP1;
			   }
   	              break;
            }
		}
	}
	if (E2%2==0)
	{
		int dem=0;
		if (HP1<200)
        {
        	hp1=hp1*1.3;
   	       HP1=ceil(hp1);
   	       M1=M1-150;
   	       m=m+150;
   	       hp1=HP1;
   	       if ((HP1>666))
   	           {
   	           	 HP1=666;
   	           	 hp1=HP1;
			   }
        }
        else 
        {
        	hp1=hp1*1.1;
   	        HP1=ceil(hp1);
   	        hp1=HP1;
   	        M1=M1-70;
   	        m=m+70;
   	        if ((HP1>666))
   	           {
   	           	 HP1=666;
   	           	 hp1=HP1;
			   }
        }
        if (M1>0)
        {
        	if (EXP1>400)
           {
   	          M1=M1-120;
   	          m=m+120;
   	          exp1=exp1*1.13;
   	          EXP1=ceil(exp1);
   	          exp1=EXP1;
   	          if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
			    if (EXP1>600)
			   {
			      EXP1=600;
			      exp1=EXP1;
			   }
           }
           else
           {
        	  M1=M1-200;
   	          m=m+200;
   	          exp1=exp1*1.13;
   	          EXP1=ceil(exp1);
   	          exp1=EXP1;
   	          if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
			    if (EXP1>600)
			   {
			      EXP1=600;
			      exp1=EXP1;
			   }
           }
		}
		else 
		{
			hp1=hp1*0.83;
			HP1=ceil(hp1);
   	        hp1=HP1;
   	        exp1=exp1*1.17;
   	        EXP1=ceil(exp1);
   	        exp1=EXP1;
   	        M1=0;
   	        dem++;
   	        if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
			    if (EXP1>600)
			   {
			      EXP1=600;
			      exp1=EXP1;
			   }
		}
		if (M1>0)
		{
			if (EXP1<300)
            {
   	            M1=M1-100;
   	            m=m+100;
   	            exp1=exp1*0.9;
   	            EXP1=ceil(exp1);
   	            exp1=EXP1;
   	            if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
			    if (EXP1>600)
			   {
			      EXP1=600;
			      exp1=EXP1;
			   }
            } 
            else
            {
   	            M1=M1-120;
   	            m=m+120;
   	            exp1=exp1*0.9;
   	            EXP1=ceil(exp1);
   	            exp1=EXP1;
   	            if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
			    if (EXP1>600)
			   {
			      EXP1=600;
			      exp1=EXP1;
			   }
            }
            hp1=hp1*0.83;
            HP1=ceil(hp1);
   	        hp1=HP1;
   	        exp1=exp1*1.17;
   	        EXP1=ceil(exp1);
   	        exp1=EXP1;
   	        if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
			    if (EXP1>600)
			   {
			      EXP1=600;
			      exp1=EXP1;
			   }
	    }
	    else if (dem==0)
	    {
	    	 hp1=hp1*0.83;
	    	HP1=ceil(hp1);
	    	hp1=HP1;
	    	exp1=exp1*1.17;
   	        EXP1=ceil(exp1);
   	        exp1=EXP1;
   	        M1=0;
   	        if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
			    if (EXP1>600)
			   {
			      EXP1=600;
			      exp1=EXP1;
			   }
			   dem++;
		}
	}
	if (M1<0) M1=0;
	s=round(sqrt(exp1));
	if (exp1>=s*s) p2=1;
    else p2=(exp1/(s*s)+80)/123;
    i=E2%10+E2/10;
    p3=P3[i%10];
    p=(p1+p2+p3)/3;
    if (p==1) 
	{
		 exp1=exp1*0.75;
	  EXP1=ceil(exp1);
	 
    } 
    else if (p<0.5)
    {
    	hp1=hp1*0.85;
    	HP1=ceil(hp1);
    	hp1=HP1;
    	 exp1=exp1*1.15;
   	    EXP1=ceil(exp1);
   	    exp1=EXP1;
   	    if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
			    if (EXP1>600)
			   {
			      EXP1=600.0;
			      exp1=EXP1;
			   }
	} else 
	{
		hp1=hp1*0.9;
		HP1=ceil(hp1);
		hp1=HP1;
		exp1=exp1*1.2;
   	    EXP1=ceil(exp1);
   	    exp1=EXP1;
   	    if ((HP1>666))
   	           {
   	           	 HP1=666.0;
   	           	 hp1=HP1;
			   }
			    if (EXP1>600)
			   {
			      EXP1=600.0;
			      exp1=EXP1;
			   }
	}
    if (EXP1>600) EXP1=600;
	if (EXP1<0) EXP1=0;
    return HP1 + EXP1 + M1;
}
    else
    {
    	E2=-99;
    	return -99;
	}
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int P[10][10];
    int i,j,demi=0,demj=0,result,taxi,max;
    float exp1,exp2,hp1,hp2;
    exp1=EXP1;
    exp2=EXP2;
    hp1=HP1;
    hp2=HP2;
     if ((E3>=0) and (E3<=99))
    {
    for (i=0;i<10;i++)
    {
    	for (j=0;j<10;j++)
    	{
    		P[i][j]=((E3*j)+(i*2))*(i-j);
		}
	}
	for (i=0;i<10;i++)
    {
    	for (j=0;j<10;j++)
    	{
    		if (P[i][j]>E3*2) demi++;
    		if (P[i][j]<-E3)  demj++;
		}
	}
	while ((demi>9) or (demj>9))
    {
    	demi=demi%10+demi/10;
	   demj=demj%10+demj/10;
	}
    i=demi;j=demj;
    if (i+j<9)
    {
    	int a=0;
    	int b=i+j;
    	max=P[a][b];
    	while (b>=0)
    	{ 
		    if (max<P[a][b]) max=P[a][b];   
    	    a++;
    		b--;
		}
	}
	else
	{
		int a=i+j-9;
		int b=9;
		max=P[a][b];
		while (a<=9)
		{
			if (max<P[a][b]) max=P[a][b];
			a++;
			b--;
		}
	}
	if (i-j>0)
	{
		int a=9;
		int b=9-(i-j);
		while (b>=0)
		{
			if (max<P[a][b]) max=P[a][b];
			a--;
			b--;
		}
	}
	else
	{
		int a=9+(i-j);
		int b=9;
		while (a>=0)
		{
			if (max<P[a][b]) max=P[a][b];
			a--;
			b--;
		}
	}
	taxi=P[i][j];
	if (abs(taxi)>abs(max))
	{
		exp1=exp1*0.88;
		EXP1=ceil(exp1);
		hp1=hp1*0.9;
		HP1=ceil(hp1);
		exp2=exp2*0.88;
		EXP2=ceil(exp2);
		hp2=hp2*0.9;
		HP2=ceil(hp2);
		result=taxi;
	}
	else
	{
		exp1=exp1*1.12;
		EXP1=ceil(exp1);
		hp1=hp1*1.1;
		HP1=ceil(hp1);
		exp2=exp2*1.12;
		EXP2=ceil(exp2);
		hp2=hp2*1.1;
		HP2=ceil(hp2);
		result=max;
	}
    if (EXP1>600) EXP1=600;
    if (EXP2>600) EXP2=600;
    if (HP1>666) HP1=600;
	if (HP2>666) HP1=666;
	 return result;
}

else 
{
	E3=-99;
	return -99;
}
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se;
    string ss=s;
    string emaill=email;
    int sei=-1,sci=-1,result,dem=0,sf=-1,dem1=0,dem2=0;
    for (int i=0;i<strlen(email);i++)
    {
    	if (email[i]!='@') se=se+emaill[i];
    	else break;
	}
	sei=ss.find(se);
	for (int i=0;i<strlen(s);i++)
	{
		if ((ss[i]==s[i+1]) and (ss[i]==s[i+2]))
		{
			sci=i;
			break;
		}
	}
	for (int i=0;i<strlen(s);i++)
	{
		if (((ss[i]>='a') and (ss[i]<='z')) or ((ss[i]>='A') and (ss[i]<='Z')) or ((ss[i]>='0') and (ss[i]<='9')));
		else if ((ss[i]=='@') or (ss[i]=='#') or (ss[i]=='!') or (ss[i]=='%') or (ss[i]=='$'))
		{
			dem++;
		}
		else
		{ 
		    if (dem2==0)
		    {
		    	sf=i;
		    	dem2++;
			}
			
		}
	}
	if (strlen(s)<8) result=-1;
	else if (strlen(s)>20) result=-2;
	else if (sei>=0) result=-(300+sei);
	else if (sci>=0) result=-(400+sci);
	else if (dem==0) result=-5;
	else if (sf>=0) result=sf;
	else result=-10;
    return result;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int pwds[num_pwds];
    int max,maxi,b;
    for (int i=0;i<num_pwds;i++) pwds[i]=1;
    for (int i=0;i<num_pwds;i++)
    {
    	for (int j=0;j<num_pwds;j++)
    	{
    		if (i!=j)
    		{
    			if ((arr_pwds[i]==arr_pwds[j]) and (j>i))
				{
			      pwds[i]++;
			    }
    			 if ((arr_pwds[i]==arr_pwds[j]) and (j<i))
				{
				  break;
			    }
			}
		}
	}
	max=pwds[0];
	maxi=0;
	for (int i=1;i<num_pwds;i++)
	{
		if (max<pwds[i])
		{
			max=pwds[i];
			maxi=i;
			b=maxi;
		}
		else if (max==pwds[i])
		{
			if (strlen(arr_pwds[maxi])<strlen(arr_pwds[i]))
			{
				maxi=i;
				b=maxi;
			}
		}
	}
    return 	maxi;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
