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
#define MIN_EXP 0
#define MAX_EXP 600
#define MIN_HP 0
#define MAX_HP 666
#define MIN_M 0
#define MAX_M 3000
int checkExp(int exp) {
	if (exp < MIN_EXP) {
		return MIN_EXP;
	} else if (exp > MAX_EXP) {
		return MAX_EXP;
	} else {
		return exp;
	}
}

int checkHP(int hp) {
	if (hp < MIN_HP) {
		return MIN_HP;
	} else if (hp > MAX_HP) {
		return MAX_HP;
	} else {
		return hp;
	}
}

int checkM(int m) {
	if (m < MIN_M) {
		return MIN_M;
	} else if (m > MAX_M) {
		return MAX_M;
	} else {
		return m;
	}
}

bool e1InRange(int e1, int start, int end) {
	if (e1 >= start && e1 <= end) {
		return true;
	} else {
		return false;
	}
	
}

int roundExp(double exp) {
	int iExp = int(exp);
	if (exp - iExp > 0) {
		return iExp + 1;
	} else {
		return iExp;
	}
}

int roundNum(double num) {
	int iNum = int(num);
	if (num - iNum > 0) {
		return iNum + 1;
	} else {
		return iNum;
	}
}

bool checkSquare(int n) {
	int i = 0;
	while (i*i < n) {
		i++;
	}
	if (i*i == n) {
		return true;
	} else {
		return false;
	}
}

int sqareSmallerThan(int n) {
	for (int i = n - 1; i > 0; i--) {
		if (checkSquare(i)) {
			return i;
		}
	}
	return 0;
}

int sqareLargerThan(int n) {
	while (true) {
		n++;
		if (checkSquare(n)) {
			return n;
		}
	}
}

int squareClosestTo(int n) {
	if (checkSquare(n)) {
		return n;
	}
	int smaller = sqareSmallerThan(n);
	int larger = sqareLargerThan(n);
	if (n - smaller < larger - n) {
		return smaller;
	} else {
		return larger;
	}
}

int amountOfNumbers(int n) {
	int i = int (n/10);
	if (i == 0) {
		return 1;
	} else {
		return 2;
	}
}

long check_se(char s1[], char se[], int i, int j)
{
    int rt=-1;
    for(int k =0; k<=j-i;k++) 
    {
        if(s1[k]==se[0])
        {
            
            int b=1;
            while(b<=i)
            {
                if(s1[k+b]==se[b])
                {
                    b++;
                }
            }
            if(b==i+1)
            {
                 rt = k;
                 break;
            }
        }
    }
    return rt;
}

int check_2_chars(char s1[], int j)
{
    int c=0;
    for(int d=0; d<j; d++)
    {
        if(s1[d]==s1[d+1])
        {
            c=d;
            break;
        }
    }
    return c;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
	if (e1 < 0 || e1 > 99) {
		return -99;
	}
	if (e1InRange(e1, 0, 3)) {
		if (e1 == 0) {
			exp2 += 29;
		} else if (e1 == 1) {
			exp2 += 45;
		} else if (e1 == 2) {
			exp2 += 75;
		} else {
			exp2 += 149;
		}
		exp2 = checkExp(exp2);

		int D = e1*3 + exp1*7;
		double temp = (D % 2 == 0) ? (double(exp1) + double(D)/200) : (double(exp1) - double(D)/100);

		exp1 = roundExp(temp);
		exp1 = checkExp(exp1);
	} else if (e1InRange(e1, 4, 99)) {
		double temp;
		if (e1InRange(e1, 4, 19)) {
			temp = double(exp2) + double(e1)/4 + 19;
			exp2 = roundExp(temp);
			exp2 = checkExp(exp2);
			exp1 -= e1;
			checkExp(exp1);
		} else if (e1InRange(e1, 20, 49)) {
			temp = double(exp2) + double(e1)/9 + 21;
			exp2 = roundExp(temp);
			exp2 = checkExp(exp2);
			exp1 -= e1;
			checkExp(exp1);
		} else if (e1InRange(e1, 50, 65)) {
			temp = double(exp2) + double(e1)/16 + 17;
			exp2 = roundExp(temp);
			exp2 = checkExp(exp2);
			exp1 -= e1;
			checkExp(exp1);
		} else if (e1InRange(e1, 66, 79)) {
            temp = double(exp2) + double(e1)/4 + 19;
            exp2 = roundExp(temp);
            if (exp2>200) {
                exp2 = checkExp(exp2);
                temp = double(exp2) + double(e1)/9 + 21;
                exp2 = roundExp(temp);
				exp1 -= e1;
				checkExp(exp1);
            } else {
                exp2 = checkExp(exp2);
				exp1 -= e1;
				checkExp(exp1);
                return exp2;
            }
		} else if (e1InRange(e1, 80, 99)) {
            temp = double(exp2) + double(e1)/4 + 19 + double(exp2) + double(e1)/9 + 21;
            exp2 = roundExp(temp);
            if (exp2 > 400) {
                exp2 = checkExp(exp2);
                temp = double(exp2) + double(e1)/16 + 17;
                exp2 = roundExp(temp);
				exp1 -= e1;
				checkExp(exp1);
            } else {
                exp2 = checkExp(exp2);
				exp1 -= e1;
				checkExp(exp1);
                return exp2;
            }
		}
	}
    if (exp1 > 600) exp1 = 600;
    if (exp2 > 600) exp2 = 600;
    if (exp1 < 0) exp1 = 0;
    if (exp1 < 0) exp1 = 0;
    return exp1 + exp2;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
	int S = squareClosestTo(EXP1);
	double P1 = 0;
	if (EXP1 >= S) {
		P1 = 1;
	} else {
		P1 = ((double(EXP1)/S) + 80)/123;
	}

	double halfMoney = double(M1)/2;
	halfMoney = roundNum(halfMoney);

	// Second Path
	if (E3 % 2 == 0) {
		// 1st Path
		if (HP1 < 200) {
			double newHP = double(HP1)*1.3;
			HP1 = roundNum(newHP);
			M1 -= 150;
		} else {
			double newHP = double(HP1)*1.1;
			HP1 = roundNum(newHP);
			M1 -= 70;
		}
		M1 = checkM(M1);
		HP1 = checkHP(HP1);

		// 2nd Path
		if (EXP1 < 400) {
			M1 -= 200;
		} else {	
			M1 -= 120;
		}
		M1 = checkM(M1);
		double newEXP1 = double(EXP1)*1.13;
		EXP1 = roundNum(newEXP1);
		EXP1 = checkExp(EXP1);

		// 3rd Path
		if (EXP1 < 300) {
			M1 -= 100;
		} else {
			M1 -= 120;
		}
		double newEXP = double(EXP1)*0.9;
		EXP1 = roundNum(newEXP);
		EXP1 = checkExp(EXP1);
		M1 = checkM(M1);
	} else {
		int m = 0;
		while (true) {
			// 1st Path
			if (HP1 < 200) {
				double newHP = double(HP1)*1.3;
				HP1 = roundNum(newHP);
				M1 -= 150;
				m += 150;
			} else {
				double newHP = double(HP1)*1.1;
				HP1 = roundNum(newHP);
				M1 -= 70;
				m += 70;
			}
			M1 = checkM(M1);
			HP1 = checkHP(HP1);

			if (m > halfMoney) {
				break;
			}

			// 2nd Path
			if (EXP1 < 400) {
				M1 -= 200;
				m += 200;
				double newEXP1 = double(EXP1)*1.13;
				EXP1 = roundNum(newEXP1);
				EXP1 = checkExp(EXP1);
			} else {	
				M1 -= 120;
				m += 120;
				double newEXP1 = double(EXP1)*1.13;
				EXP1 = roundNum(newEXP1);
				EXP1 = checkExp(EXP1);
			}
			M1 = checkM(M1);
		
			if (m > halfMoney) {
				break;
			}

			// 3rd Path
			if (EXP1 < 300) {
				M1 -= 100;
				m += 100;
			} else {
				M1 -= 120;
				m += 120;
			}
			double newEXP = double(EXP1)*0.9;
			EXP1 = roundNum(newEXP);
			EXP1 = checkExp(EXP1);
			M1 = checkM(M1);
			
			if (m > halfMoney) {
				break;
			}
			
		}
		double newHP = double(HP1)*0.83;
		HP1 = roundNum(newHP);
		double newEXP = double(EXP1)*1.17;
		EXP1 = roundExp(newEXP);
	}
	int S2 = squareClosestTo(EXP1);
	double P2 = 0;

	if (EXP1 >= S2) {
		P2 = 1;
	} else {
		P2 = ((double(EXP1)/S2) + 80)/123;
	}
	
	// Third Path
	int arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

	int index = 0;
	if (amountOfNumbers(E3) == 1) {
		index = E3;
	}
	if (amountOfNumbers(E3) == 2) {
		int sum = E3/10 + E3%10;
		index = sum%10;
	}
	
	double P3 = double(arr[index])/100;
	if (P1 == 1 && P2 == 1 && P3 == 1) {
		double newEXP = double(EXP1)*0.75;
		EXP1 = roundExp(newEXP);
		EXP1 = checkExp(EXP1);
	} else {
		double avg = (P1 + P2 + P3)/3;
		if (avg < 0.5) {
			double newHP = double(HP1)*0.85;
			HP1 = roundNum(newHP);
			HP1 = checkHP(HP1);
			double newEXP = double(EXP1)*1.15;
			EXP1 = roundExp(newEXP);
			EXP1 = checkExp(EXP1);
		} else {
			double newHP = double(HP1)*0.9;
			HP1 = roundNum(newHP);
			HP1 = checkHP(HP1);
			double newEXP = double(EXP1)*1.2;
			EXP1 = roundExp(newEXP);
			EXP1 = checkExp(EXP1);
		}
	}
	return HP1 + EXP1 + M1;  
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
	if (E3 < 0 || E3 > 99) {
		return -99;
	}
    //create matrix
    int m[10][10];
    int i=0,j=0;
    for(int x=0; x<10; x++)
    {
        for(int y=0; y<10; y++)
        {
            m[x][y] = ((E3*y) + (x*2))*(x-y);
            if(m[x][y]>E3*2)
            {
                i++;
            }
            if(m[x][y]<-E3)
            {
                j++;
            }
        }
    }
    //
    while(i>=10)
    {
        i=i/10+i%10;
    }
    while(j>=10)
    {
        j=j/10+j%10;
    }

    int max;
    //check left diag
    int start_i_left, start_j_left;
    if(i>=j)
    {
        start_i_left=i-j;
        start_j_left=0;
    }
    else if(i<j)
    {
        start_i_left=0;
        start_j_left=j-i;
    }
    max=m[start_i_left][start_j_left];
    start_i_left++;
    start_j_left++;
    while(start_i_left<10&&start_j_left<10)
    {
        if(m[start_i_left][start_j_left]>max)
        {
            max=m[start_i_left][start_j_left];
        }
        start_i_left++;
        start_j_left++;
    }

    //check right diag
    int start_i_right, start_j_right;
     if(i+j<=9)
    {
        start_i_left=i+j;
        start_j_left=0;
    }
    else if(i+j>9)
    {
        start_i_left=9;
        start_j_left=i+j-9;
    }
    while(start_i_right>=0&&start_j_right<10)
    {
        if(m[start_i_right][start_j_right]>max)
        {
            max=m[start_i_right][start_j_right];
        }
        start_i_right++;
        start_j_right++;
    }
    max=abs(max);
    if(abs(m[i][j])<max)
    {
        EXP1=int(roundNum(EXP1*1.12));
        EXP2=int(roundNum(EXP2*1.12));
        HP1=int(roundNum(HP1*1.10));
        HP2=int(roundNum(HP2*1.10));
        checkHP(HP1);
        checkHP(HP2);
        checkExp(EXP1);
        checkExp(EXP2);
        return max;
    }
    else
    {
        EXP1=int(roundNum(EXP1*0.88));
        EXP2=int(roundNum(EXP2*0.88));
        HP1=int(roundNum(HP1*0.90));
        HP2=int(roundNum(HP2*0.90));
        checkHP(HP1);
        checkHP(HP2);
        checkExp(EXP1);
        checkExp(EXP2);
        return m[i][j];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
char se[100];
    int i=0;
   while(*email != '@')
   {
        se[i]=*email;
        email=(email+1);
        i++;
   }
   i--;
    char s1[100];
    int k=0;
    int z;
    while(*s != '\0')
   {
        s1[k]=*s;
        s=(s+1);
        k++;
   }
   k--;
    if(k<7)
    {
        z = -1;
    }
    else if(k>19)
    {
        z = -2;
    }
    else if(check_se(s1, se, i, k)!=-1&&k>i)
    {
        z = -(300+check_se(s1, se, i, k));
    }
    else if(check_2_chars(s1, k)!=-1)
    {
        z=check_2_chars(s1, k);
    }
   
    return z;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string name[30];
    int time[30];
    int first[30];
    int m=0;
    for(int i=0; i<num_pwds; i++)
    {

        for(int a=0; a<30; a++)
        {
            if(a==m)                                                                      
            {
                name[a]= *(arr_pwds+i);
                first[a]=i;
                m++;
                break;
            }
            if(*(arr_pwds+i)==name[a])
            {
                time[a]+=1;
                break;
            }
            
        }
    }
    
    int correct=0;
    for(int k=1; k<m; k++)
    {
        if(time[k]>time[correct]||(time[k]==time[correct]&&name[k].length()>name[correct].length()))
        {
            correct=k++;
        }
    }
    return first[correct];
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////