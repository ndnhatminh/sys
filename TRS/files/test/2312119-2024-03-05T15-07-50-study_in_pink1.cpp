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
int check(int n, int minpoint, int maxpoint)
{
    n = (n < minpoint) ? minpoint : (n > maxpoint) ? maxpoint : n;
    return n;
}

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    //Check value of e1, EXP1, EXP2
    int minpoint = 0, maxpoint = 600;
    if (e1<0 || e1>99) return -99;
    exp1=check(exp1, minpoint, maxpoint);
    exp2=check(exp2, minpoint, maxpoint);
    
   
    //Some var
    const int gift1_1 = 29, gift1_2 = 45, gift1_3 = 75;
    float gift2_1, gift2_2, gift2_3;
    gift2_1 = e1 * 1.0000 / 4 + 19;
    gift2_2 = e1 * 1.0000 / 9 + 21;
    gift2_3 = e1 * 1.0000 / 16 + 17;
    int num1_2[5]={20,50,66,80,100};
    
    //Solution
	//Path1
    if(e1<=3)
    {
    	switch(e1)
    	{
    		case 0: 
    		{
				exp2 = ceil(exp2+gift1_1);
	    		break;
    	    }
    	    case 1: 
    		{
				exp2=ceil(exp2+gift1_2);
	    		break;
    	    }
    	    case 2: 
    		{
				exp2=ceil(exp2+gift1_3);
	    		break;
    	    }
    	    case 3: 
    		{
				exp2=ceil(exp2+gift1_1 + gift1_2 + gift1_3);
	    		break;
    	    }	  
			
		}
		int D = e1*3+exp1*7;
			if(D%2==0) exp1 = ceil(exp1 + D/200.0);
			else exp1 = ceil(exp1 - D/100.0);
			exp1=check(exp1, minpoint, maxpoint);
   			exp2=check(exp2, minpoint, maxpoint);
    }
		else  //Path2
	{
		if (e1<num1_2[0]) exp2 = ceil(exp2+gift2_1);
		else if (e1>=num1_2[0] && e1<num1_2[1])  exp2 = ceil(exp2+gift2_2);
		else if (e1>=num1_2[1] && e1<num1_2[2])  exp2 = ceil(exp2+gift2_3);
		else if (e1>=num1_2[2] && e1<num1_2[3])
		{
			exp2 = ceil(exp2+gift2_1);
		    exp2 = check(exp2, minpoint, maxpoint);
			if (exp2>200) exp2 = ceil(exp2 + gift2_2);
		}  
		else if (e1>=num1_2[3] && e1<num1_2[4])  
		{
			exp2 = ceil(exp2+gift2_1);
			exp2 = ceil(exp2+gift2_2);
		    exp2 = check(exp2, minpoint, maxpoint);
		
			if (exp2>400)
			{
				exp2 = ceil(exp2 + gift2_3);
				
				exp2=check(exp2, minpoint, maxpoint);
			
				exp2 = ceil(exp2 + exp2*0.1500);
			}
		}
        //caculate EXP1 
        exp1 = exp1 - e1;
		exp1=check(exp1, minpoint, maxpoint);
        exp2=check(exp2, minpoint, maxpoint);

	}
	exp1=check(exp1, minpoint, maxpoint);
    exp2=check(exp2, minpoint, maxpoint);
    return exp1 + exp2;
}


// Task 2

int update_money(int & M1)
{
	M1 = check(M1, 0, 3000);
	if (M1==0) return 0;
	else return 1;
}
int find_square(int a)
{
    int b = sqrt(a);
    if(a-b*b<(b+1)*(b+1)-a)
    { return b*b;

    }
    else return (b+1)*(b+1);
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    
    //Check value
	int M1_start = M1;
	if (E2<0 || E2>99) return -99;
	float P1,P2,P3;
	
    	// Path 1
	int S = find_square(EXP1);
    if(EXP1>=S)   P1 = 1.00;
	else	      P1=(EXP1/S +80.00)/123.00;
		// Path 2
	do 
	{
		if(HP1<200)
		{ 
			HP1=ceil(HP1 + HP1*0.3);
			M1-=150;
		}
		else 
		{
			HP1=ceil(HP1 + HP1*0.1);
			M1-=70;
		}
		HP1 = check(HP1,0,666);
		if (!update_money(M1)) break;
		if (E2%2!=0)
		{
			M1 = check(M1, 0, 3000);
			if (M1<M1_start*0.5) break;
		}
		
		
		
		if (EXP1<400) M1-=200;
		else M1-=120;
		EXP1 = ceil(EXP1 + EXP1*0.13);
		EXP1 = check(EXP1,0,600);
		if (!update_money(M1)) break;
		if (E2%2!=0)
		{
			M1 = check(M1, 0, 3000);
			if (M1<M1_start*0.5) break;
		}
		
		
		if (EXP1<300) M1-=100;
		else M1-=120;
		EXP1 = ceil(EXP1 - EXP1*0.1);
		EXP1 = check(EXP1,0,600);
		if (!update_money(M1)) break;
		if (E2%2!=0)
		{
			M1 = check(M1, 0, 3000);
			if (M1<M1_start*0.5) break;
		}
		
	}
	while (E2%2!=0);
	HP1 = ceil(HP1-HP1*0.17);
	EXP1 = ceil(EXP1 + EXP1*0.17);
	HP1 = check(HP1,0,666);
	EXP1 = check(EXP1,0,600);
	
	S = find_square(EXP1);
    if(EXP1>=S)   P2 = 1.00;
	else	      P2=(EXP1/S +80.00)/123.00;
	//Path 3
	float P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
	if (E2<10) P3 = P[E2]/100.00;
	else 
	{
		int E2_test = E2/10 + E2%10;
		P3 = P[E2_test%10]/100.00;	
	}
	if ((P1==1.000)&&(P2==1.000)&&(P3==1.000))
	{
		EXP1 = ceil(EXP1 - EXP1*0.25);
		EXP1 = check(EXP1,0,600);
		return HP1 + EXP1 + M1;
	}
	
	float P_final = (P1+P2+P3)/3.00;
	if (P_final>=0.500) 
	{
		HP1=ceil(HP1-HP1*0.1);
		EXP1=ceil(EXP1+EXP1*0.2);
	}
	else 
	{
		HP1=ceil(HP1 - HP1*0.15);
		EXP1=ceil(EXP1 + EXP1*0.15);
	}
	HP1 = check(HP1,0,666);
	EXP1 = check(EXP1,0,600);
    return HP1 + EXP1 + M1;
} 

// Task 3
int check_line(int x)
{
	if ((x>=0) && (x<=9)) return 1;
	else return 0;
}
int calc(int x,int a, int b, float c)
{
	x = ceil(x*c);
	x = check(x, a, b);
	return x;
};
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

	// Calculate the value of matrix points
    if (E3<0 || E3>99) return -99;
	int matrix[10][10];
	for (int i = 0; i<10;i++)
	{
		for (int j = 0; j<10;j++)
		{
			matrix[i][j]= ((E3*j)+(i*2))*(i-j);
		}
	}
	int a = 0, b = 0;
	for (int i = 0; i<10;i++)
	{
		for (int j = 0; j<10;j++)
		{
			if (matrix[i][j]>E3*2)     a++;
			else if (matrix[i][j]<-E3) b++;
		}
	}
	while (a > 9)
	{
		a = a/10 + a%10;
	}
	while (b > 9)
	{
		b = b/10 + b%10;
	}
	//Find sherlock point 
	int taxi = matrix[a][b];
	int max_left = matrix[a][b], max_right = matrix[a][b];
	int x = a, y = b;
	while(check_line(x-1)&&check_line(y-1))
	{
		if (max_left < matrix[x-1][y-1]) max_left = matrix[x-1][y-1];
		x--;
		y--;
	}
	x = a, y = b;
	while(check_line(x+1)&&check_line(y+1))
	{
		if (max_left < matrix[x+1][y+1]) max_left = matrix[x+1][y+1];
		x++;
		y++;
	}

	x = a, y = b;
	while(check_line(x+1)&&check_line(y-1))
	{
		if (max_right < matrix[x+1][y-1]) max_right = matrix[x+1][y-1];
		x++;
		y--;
	}
	x = a, y = b;
	while(check_line(x-1)&&check_line(y+1))
	{
		if (max_right < matrix[x-1][y+1]) max_right = matrix[x-1][y+1];
		x--;
		y++;
	}
	int max = (max_left>=max_right) ? max_left : max_right;
	// Result
	if (abs(taxi) > abs(max))
	{
		HP1 = calc(HP1, 0,666,0.9);
		HP2 = calc(HP2, 0,666,0.9);
		EXP1 = calc(EXP1, 0, 600,0.88);
		EXP2 = calc(EXP2, 0, 600,0.88);
		return taxi;
	}
	else
	{
		HP1 = calc(HP1, 0,666,1.1);
		HP2 = calc(HP2, 0,666,1.1);
		EXP1 = calc(EXP1, 0, 600,1.12);
		EXP2 = calc(EXP2, 0, 600,1.12);
		return max;
	}
    return -1;
}

// Task 4

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

	//Find se
	int k;
	for (int i = 0; i < strlen(email);i++)
	{
		if (email[i]=='@') 
		{
			k = i;
			break;
		}
	}
	
	char se[k];
	strncpy(se, email, k);
	se[k] = '\0';
	
	//Check length of se
	if (strlen(s)<8) return -1;
	if (strlen(s)>20) return -2;
	if (email[0]=='@') return -300;
	//Check se in s
	for(int i = 0; i < strlen(s); i++)
	{
		int a = 0;
		int tmp = i;
		while(s[tmp]==se[a])
		{
			tmp++;
			a++;
			if (a==strlen(se)) return -(300+tmp-a);
		} 
	}
	// Check more than two same char
	for(int i = 0; i < strlen(s)-2;i++)
	{
		if ((s[i]==s[i+1]) && (s[i]==s[i+2])) return -(400+i);
	}
	// Check special char
	int b = 0;
	for (int i = 0; i < strlen(s);i++)
	{
		if ((s[i]=='@')||(s[i]=='#')||(s[i]=='!')||(s[i]=='$')||(s[i]=='%')) b++;
	}
	if (b==0) return -5; 
	// Check valid char
	for (int i = 0; i < strlen(s);i++)
	{
		if (!(((s[i]>='A') && (s[i]<='Z')) || ((s[i]>='a') &&
		(s[i]<='z')) || ((s[i]>='0') && (s[i]<='9'))||(s[i]=='@')||(s[i]=='#')||(s[i]=='!')||(s[i]=='$')||(s[i]=='%')))
	    return i;
	}
	return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
	int freq = 0;
	string pass;
	for (int i = 0; i < num_pwds; i++) 
	{
        int count = 1;
        for (int j = i+1; j < num_pwds; j++)
		{
            if (strcmp(arr_pwds[j],arr_pwds[i])==0) {
                count++;
            }
        }
        if (count > freq)
		{
            freq = count;
			pass = arr_pwds[i];
		}
		else if (count == freq)
		{
			if (pass.size()<strlen(arr_pwds[i])) pass = arr_pwds[i];
		}
    }

	for (int i = 0; i < num_pwds; i++) 
	{
		if(arr_pwds[i]==pass) return i;
	}
    

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
