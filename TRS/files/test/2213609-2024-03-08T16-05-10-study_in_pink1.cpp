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
//Value checking
void moneyCheck (int &M)
{
  if (M < 0)
	M = 0;
  if (M > 3000)
	M = 3000;
}

void HPCheck (int &HP)
{
  if (HP < 0)
	HP = 0;
  if (HP > 666)
	HP = 666;
}

void EXPCheck (int &EXP)
{
  if (EXP < 0)
	EXP = 0;
  if (EXP > 600)
	EXP = 600;
}

bool eventCheck (int E)
{
  if (E < 0 || E > 99)
	return false;
  else
	return true;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if(!eventCheck(e1)) return -99; // Checking if the event code is in the range or not
    // Event code is in between [0,3]
    if (e1>=0 && e1<= 3) {
        switch (e1) 
        {
            case 0:
                exp2 += 29;
                break;
            case 1:
                exp2 += 45;
                break;
            case 2:
                exp2 += 75;
                break;
            case 3:
                exp2 += 149;
                break;
        }
        double D = e1*3 + exp1*7;
        if ((int)(D)%2==0) exp1 = ceil(exp1 + D/200);
        else exp1 = ceil(exp1 - D/100);
    } else if (e1>=4 && e1 <=19)  {             // Event code is in between [4,19]
        exp2 = ceil(exp2 + (double)(e1)/4 + 19);
        exp1 -= e1;
    } else if(e1>=20 && e1 <= 49) {             // Event code is in between [20,49]
        exp2  = ceil(exp2 + (double)(e1)/9 + 21);
        exp1 -= e1;
    } else if(e1>=50 && e1<=65)   {             // Event code is in between [50,65]
        exp2 = ceil(exp2 + (double)(e1)/16 + 17);
        exp1 -= e1;
    } else if(e1>=66 && e1<=79) {             // Event code is in between [66,79]
        exp2 = ceil(exp2 + (double)(e1)/4 + 19);
        if(exp2>200) exp2  = ceil(exp2 + (double)(e1)/9 + 21);
        exp1 -= e1;
    } else if(e1>=80 && e1<= 99) {             // Event code is in between [80,99]
        exp2 = ceil(exp2 + (double)(e1)/4 + 19);
        exp2 = ceil(exp2 + (double)(e1)/9 + 21);
        if(exp2>400) exp2 = ceil(exp2 + (double)(e1)/16 + 17);
        exp2 = ceil(exp2 + (double)(exp2)*0.15);
        exp1 -= e1;
    }
    EXPCheck(exp1);
    EXPCheck(exp2);                // Checking if Sherlock and Watson's exp have gone out of the range 
    return exp1 + exp2;
}

// Task 2
// First road of the 2nd task
int closestSquareNumber(int S) {
    if(sqrt(S)==ceil(sqrt(S))) return S;
    int smaller = S, bigger = S;
    while (true) {
       if(sqrt(smaller) == ceil(sqrt(smaller))) break;
       smaller --;
    }
    while(true) {
        if(sqrt(bigger) == ceil(sqrt(bigger))) break;
        bigger ++;
    }
    if(S - smaller < bigger - S) return smaller;
    else return bigger;

}
double firstRoad(int &EXP1) {
    int S1 = closestSquareNumber(EXP1);
    double P1;
    if(EXP1 >= S1) P1 = 1;
    else P1 = ((double)(EXP1/S1) + 80)/123;
    return P1;
}


// Second road of the 2nd task
double secondRoad(int & HP1, int & EXP1, int & M1, int E2) {
    if(!eventCheck(E2)) return -99; 
    if(E2%2==0) {
        if(M1>0) {
            firstEvent(HP1,M1);
            if(M1>0) {
                secondEvent(EXP1, M1);
                if(M1>0) thirdEvent(EXP1, M1);
            }
        }
    } else {
        if(M1>0) {
            int budget = ceil((double)(M1)/2);
            while(true) {
                firstEvent(HP1, M1);
                if(M1<budget) break;
                else secondEvent(EXP1, M1);
                if(M1<budget) break;
                else thirdEvent(EXP1, M1);
            }
        }
    }
    HP1 = ceil(HP1 - (double)(HP1)*0.17);
    EXP1 = ceil(EXP1 + (double)(EXP1)*0.17);
    int S2 = closestSquareNumber(EXP1);
    double P2;
    if(EXP1 >= S2) P2 = 1;
    else P2 = ((double)(EXP1/S2) + 80)/123;
    return P2;
}

// Third road of the 2nd task
double thirdRoad(int E2) {
    double P[] = {0.32,0.47,0.28,0.79,1,0.50,0.22,0.83,0.64,0.11};
    double P3;
    if (E2/10==0) P3 = P[E2];
    else {
        int temp1, temp2;
        temp1 = E2%10;
        temp2 = E2/10;
        P3 = P[(temp1 + temp2)%10];
    }
    return P3;
}

// The three event of the second road of the 2nd task
void firstEvent(int &HP1, int &M1) {
    if(HP1<200) {
        HP1 = ceil(HP1 + (double)(HP1)*0.3);
        M1 -= 150;
    } else {
        HP1 = ceil(HP1 + (double)(HP1)*0.1);
        M1 -= 70;
    }
    moneyCheck(M1);
    HPCheck(HP1);
}
void secondEvent(int &EXP1, int& M1) {
    (EXP1 < 400) ? (M1 -= 200) : (M1 -= 120);
    EXP1 = ceil(EXP1 + (double)(EXP1)*0.13);
    moneyCheck(M1);
    EXPCheck(EXP1);
}
void thirdEvent(int &EXP1, int& M1) {
    (EXP1 < 300) ? (M1 -= 100) : (M1 -= 120);
    EXP1 = ceil(EXP1 - (double)(EXP1)*0.1);
    moneyCheck(M1);
    EXPCheck(EXP1);
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(!eventCheck(E2)) return -99;
    double P1 = firstRoad(EXP1), P2 = secondRoad(HP1, EXP1, M1, E2), P3 = thirdRoad(E2), P;
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = ceil(EXP1 - (double)(EXP1)*0.25);
        traceLuggage(HP1, EXP1, M1, E2);
    } else P = (P1 + P2 + P3)/3;
    if (P<0.5) {
        HP1 = ceil(HP1 - (double)(HP1)*0.15);
        EXP1 = ceil(EXP1 + (double)(EXP1)*0.15);
    } else {
        HP1 = ceil(HP1 - (double)(HP1)*0.1);
        EXP1 = ceil(EXP1 + (double)(EXP1)*0.2);
    }
    HPCheck(HP1);
    EXPCheck(EXP1);
    return HP1 + EXP1 + M1;
}

// Task 3
// Create a matrix 
int matrixValue (int E, int i, int j)
{
  int value = ((E * j) + (i * 2)) * (i - j);;
  return value;
}

void countingValue (int value, int E, int &column, int &row)
{
  if (value > E * 2)
	row++;
  if (value < (-E))
	column++;
}

void findingCoordinate (int &result)
{
  if (result > 0 && result / 10 != 0)
	{
	  result = result / 10 + result % 10;
	  findingCoordinate (result);
	}
}
   
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
 int matrix[10][10];
  int column = 0, row = 0;
  for (int i = 0; i < 10; i++)
	{
	  for (int j = 0; j < 10; j++)
		{
		  matrix[i][j] = matrixValue (E3, i, j);
		  countingValue (matrix[i][j], E3, row, column);

		}

	}
  findingCoordinate (column);
  findingCoordinate (row);
  int maxValue = matrix[column][row], taxi = matrix[column][row];
  //finding the largest on the main diagonal
  if (row == column)
	{
	  for (int k = 0; k < 10; k++)
		{
		  if (maxValue < matrix[k][k])
			maxValue = matrix[k][k];
		}
	}
  else
	{
	  if (row < column)
		{
		  for (int k = 0; k < 9 - row; k++)
			{
			  if (maxValue < matrix[k][column - row + k])
				maxValue = matrix[k][column - row];
			}
		}
	  else
	{
	  if (row > column)
		{
		  for (int k = 0; k < 9 - row + column; k++)
			{
			  if (maxValue < matrix[k][column - row + k])
				maxValue = matrix[k][column - row + k];
			}
		}
	  if(row < column) {
		for (int k = 0; k < 9 - column + row; k++)
		  {
			if (maxValue < matrix[row - column + k][k])
			  maxValue = matrix[row - column + k][k];
		  }
	}
	}
	}
  // finding the largest on the second diagonal
  if (row == 9 - column)
	{
	  for (int k = 0; k < 10; k++)
		{
		  if (maxValue < matrix[k][9 - k])
			maxValue = matrix[k][9 - k];
		}
	}
  else
	{
	  if (row + column >= 9)
		{
		  for (int k = 0; k < 19 - row - column; k++)
			{
			  if (maxValue < matrix[9 - k][row + column - 9 + k])
				maxValue = matrix[9 - k][row + column - 9 + k];
			}
		}
	  else
		{
		  for (int k = 0; k < column + row + 1; k++)
			{
			  if (maxValue < matrix[k][row + column - k])
				maxValue = matrix[k][row + column - k];
			}
		}
	}
  if (maxValue > abs (taxi))
	{
	 EXP1 = ceil (EXP1 + (double) (EXP1) * 0.12);
	  HP1 = ceil (HP1 + (double) (HP1) * 0.1);
	  EXP2 = ceil (EXP2 + (double) (EXP2) * 0.12);
	  HP2 = ceil (HP2 + (double) (HP2) * 0.1);
	  EXPCheck (EXP1);
	  EXPCheck (EXP2);
	  HPCheck (HP1);
	  HPCheck (HP2);
	  return maxValue;
	}
  else
	{
	  EXP1 = ceil (EXP1 - (double) (EXP1) * 0.12);
	  HP1 = ceil (HP1 - (double) (HP1) * 0.1);
	  EXP2 = ceil (EXP2 - (double) (EXP2) * 0.12);
	  HP2 = ceil (HP2 - (double) (HP2) * 0.1);
	  EXPCheck (EXP1);
	  EXPCheck (EXP2);
	  HPCheck (HP1);
	  HPCheck (HP2);
	  
	  return taxi;
	}
}
// Task 4
bool findSpecialCharacter(string s){
  if(s[s.find("@")]==64 ||s[s.find("#")]==35||s[s.find("%")]==37||s[s.find("$")]==36||s[s.find("!")]==33 ) 
     return 1;
  else return 0;
}
int checkPassword(const char * s, const char * email) {
    string s_1=s;
    string email_1=email;
  
  string result;
  bool temp=false;
  
  string se;
  se= email_1.substr(0,email_1.find("@"));
  
  
  for (int i=s_1.length(); i>=1; i--){
        for (int j=0; j < s_1.length() - i + 1; j++ ){
            string temp_1= s_1.substr(j, i);
            if (se.find(temp_1) != -1) {              
                result = temp_1;
                temp = true;
                break;
            }
        }
        if (temp) break;
    }    
    

  int a;
  bool test;
  test=false;
  for(int i=0;i<s_1.length();i++){
    
    if(s_1[i]>=1 && s_1[i]<=47){
        if((s_1[i]!=35 && s_1[i]!=36 && s_1[i]!=37 && s_1[i]!=33))
                            {test= true;
                              a=i;
                              break;}
        }
    else if(s_1[i]>=58 && s_1[i]<=63 ) {test= true;
                              a=i;
                              break;}
    else if(s_1[i]>=91 && s_1[i]<=96) {test= true;
                              a=i;
                              break;}
    else if(s_1[i]>=123 && s_1[i]<=255) {test= true;
                              a=i;
                              break;}
  }
  
  
                                  
  int g=0;
  int index;
  for(int i=0;i<s_1.length()-1;i++){
    if(s_1[i]==s_1[i+1]){
        g+=1;
        if(s_1[i+1]==s_1[i+2]){ 
            g+=1; 
            index=i; 
            break;}
        else g=0;
  }
  }
  
    int x;
  if(s_1.length()>=8 && s_1.length()<=20){
    if(result!=se){
      if(g<=1){
        if(findSpecialCharacter(s_1)) {
          if(test) x= a;
          else x= -10;
        }
        else x= -5;
      }
      else x= -(400+index);
    }
    else x= -(300+int(s_1.find(se)));
  }
  else if(s_1.length()<8) x=-1;
  else if(s_1.length()>20) x= -2;


  return x;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    string arr[100];

for(int i=0;i<num_pwds;i++){
    string a=arr_pwds[i];
    arr[i]=a;
}

int g=1;
int z=0;
int index=0;
for(int i=0;i<num_pwds;i++){
    for(int j=num_pwds-1;j>=i+1;j--){
        if(arr[i]==arr[j]){
            g=g+1;
        }          
    }
   
    if(g==z){
        if(arr[i].length()>arr[index].length())
        {
            index=i;
        }
    } 
    if(g>z) {
        z=g;
        index=i;
    }
    
    
    g=1;
}
return index;

}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////