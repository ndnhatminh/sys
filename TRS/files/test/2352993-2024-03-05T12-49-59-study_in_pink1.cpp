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
    if (e1 > 99 || e1 < 0) {
        
        return -99;
    }
    if (exp1 > 600)
	{
	  exp1 = 600;
	}
   if (exp1 < 0)
	{
	  exp1 = 0;
	}
  if (exp2 > 600)
	{
	  exp2 = 600;
	}
   if (exp2 < 0)
	{
	  exp2 = 0;
	}
    if (e1 > 99 || e1 < 0) {
        
        return -99;
    }
    if (0 <= e1 && e1 <= 3)
	{
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
		  exp2 += 29 + 45 + 75;
		  break;
		}

	   int D = e1 * 3 + exp1 * 7;
	  double exp1fake=exp1;
	  if (D % 2 == 0)
		{
		  exp1fake += D / 200.0;
		}
	  else {
		exp1fake -= D / 100.0;
	}
	exp1 = ceil(exp1fake);
	    
	}
	 if (exp1 > 600)
	{
	  exp1 = 600;
	}
  else if (exp1 < 0)
	{
	  exp1 = 0;
	}
  else if (4 <= e1 && e1 <= 99)
	{
	  switch (e1)
		{
		case 4 ... 19:
		  exp2 += ceil (e1 / 4.0 + 19.0);

		  break;
		case 20 ... 49:
		  exp2 += ceil (e1 / 9.0 + 21.0);

		  
		  break;

		case 50 ... 65:
		  exp2 += ceil (e1 / 16.0 + 17.0);

		  
		  break;

		case 66 ... 79:
		  exp2 += ceil (e1 / 4.0 + 19.0);


		  if (exp2 > 200)
			{
			  exp2 += ceil (e1 / 9.0 + 21.0);
			}

		  
		  break;

		case 80 ... 99:
		double exp2fake = exp2;
		  exp2fake = exp2 + (e1 / 4.0 + 19.0) ;
		  exp2fake = ceil(exp2fake);
		  exp2fake = exp2fake +  (e1 / 9.0 + 21.0);
		  exp2 = ceil(exp2fake);
		  if (exp2 > 400)
			{
			  exp2fake = exp2 + (e1 / 16.0 + 17.0);
			  exp2fake = ceil (exp2fake);
			  	  exp2fake *= 1.15;
		  exp2 = ceil (exp2fake);
			}
         
         
	

		  
		  break;



		}
	  exp1 -= e1;
	  
	}
	if (e1 > 99 || e1 < 0) {
        
        return -99;
    }
  if (exp1 > 600)
	{
	  exp1 = 600;
	}
   if (exp1 < 0)
	{
	  exp1 = 0;
	}
  if (exp2 > 600)
	{
	  exp2 = 600;
	}
   if (exp2 < 0)
	{
	  exp2 = 0;
	}
  

    return exp1 + exp2;
}

 // Task 2
int traceLuggage (int &HP1, int &EXP1, int &M1, int E2) {
  // TODO: Complete this function


  // con duong 1
  double P1;
  double S1 = pow ((ceil (sqrt (EXP1))), 2); 
  if (EXP1 >= S1)
	{
	  P1 = 100;
	}
  else
	{
	  P1 = ((EXP1 / S1 + 80) / 123)*100;
	}

  //// con duong 2
  int M4 = M1/2;
  int M3=0;
  double HP = HP1; 
  double EXP = EXP1; 
  if (E2 % 2 == 0)
	{ //1111111111111111111111111
	  if (HP1 < 200)
		{
		  HP *= 1.3;
		  M1 -= 150;
		}
	  else
		{
		  HP *= 1.1;
		  M1 -= 70;
		}
		HP =ceil (HP); 
		if (HP>666) {
    HP = 666; }
    else if ( HP <0) {
        HP = 0; }
		while (M1 < 0)
		{
		  M1 = 0;
		  break;
		}
		//22222222222222222222
	  if (EXP < 400)
		{
		  M1 -= 200;
		}
	  else
		{
		  M1 -= 120;
		}
	  EXP *= 1.13; EXP =ceil (EXP);
	  if (EXP>600) {
    EXP = 600;}
    else if ( EXP <0) {
        EXP =0;}
	  while (M1 < 0)
		{
		  M1 = 0;
		  break;
		}
	  //333333333333333333333
	  if (EXP < 300)
		{
		  M1 -= 100;
		}
	  else
		{
		  M1 -= 120;
		}
	  EXP *= 0.9; EXP =ceil (EXP);
	  if (EXP>600) {
    EXP = 600;}
    else if ( EXP <0) {
        EXP =0;}
	  while (M1 < 0)
		{
		  M1 = 0;
		  break;
		}
	}                                 // TH2
	else { 
	    do  {
	        if (M3 >= M4){
	            break;}
	   
	    if (HP < 200)
		{
		  HP *= 1.3; 
		  M1 -= 150;
		  M3 += 150;
		}
	  else
		{
		
		  HP *= 1.1;

		  M1 -= 70;
		  M3 += 70;
		} HP= ceil (HP); 
		if (HP>666) {
    HP = 666; }
    else if ( HP <0) {
        HP = 0; }
		                                
		 if (M3 >= M4 ) {
		     break;}
		     if (EXP < 400)
		{
		  M1 -= 200;
		  M3 += 200;
		}
	  else
		{
		  M1 -= 120;
		  M3 += 120;
		}
	  EXP *= 1.13; EXP =ceil (EXP); 
	   if (EXP>600) {
    EXP = 600;}
    else if ( EXP <0) {
        EXP =0;}
	         if (M1 >3000) { M1 = 3000;}
else if (M1 <0) {M1=0;}                                 
	  // cout<<"M3:"<<M3<<"M4"<<M4<<endl;
	  if (M3 >= M4) { 
	      break; }
	  if (EXP < 300)
		{
		  M1 -= 100;
		  M3 += 100;
		}
	  else
		{
		  M1 -= 120;
		  M3 += 120;            
		  
		}
	  EXP *= 0.9;EXP= ceil (EXP); 
	  if (EXP>600) {
    EXP = 600;}
    else if ( EXP <0) {
        EXP =0;}
        if (M1 >3000) { M1 = 3000;}
else if (M1 <0) {M1=0;} 
	 
	 }
	  while(M3<=M4); 
	  HP *= 0.83;HP= ceil (HP); 
	  EXP *=1.17;EXP= ceil (EXP);
	             if (EXP>600) {
    EXP = 600;}
    else if ( EXP <0) {
        EXP =0;}
        if (HP>666) {
    HP = 666; }
    else if ( HP <0) {
        HP = 0; }
        
	}
  double P2;
  double S2 = pow (round(sqrt(EXP)),2); 

  if (EXP >= S2)
	{
	  P2 = 100;
	}
  else
	{
	  P2 = ((EXP / S2 + 80) / 123)*100;
	}
  
  EXP1 = EXP; 
  HP1 = HP; 
  // con duong 3
  int P3;
  int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i; 

    if (E2 < 10) {
        i = E2;
    } else {
        
        int sum = (E2 / 10) + (E2 % 10);
        
        i = sum % 10;}
       P3 = P[i];
      double Ptb = (P1+P2+P3)/3;
      Ptb = ceil (Ptb);
    
      double HP3 = HP1; ;
      double EXP3 = EXP1;
    if (Ptb == 100) {EXP3 *= 0.75; }
    else if (Ptb <50) { HP3 *= 0.85; EXP3 *= 1.15; }
    else { HP3 *= 0.9 ; EXP3 *= 1.2; }
    
    HP1 = ceil(HP3); 
    EXP1 = ceil (EXP3);
    if (HP1>666) {
    HP1 = 666; }
    else if ( HP1 <0) {
        HP1 = 0; }
if (EXP1>600) {
    EXP1 = 600;}
    else if ( EXP1 <0) {
        EXP1 =0;}
 if (E2 > 99 && E2 < 0)
	{
	  E2 = -99;
	}
if (M1 >3000) { M1 = 3000;}
else if (M1 <0) {M1=0;}

 return HP1 + EXP1 + M1;
}

// Task 3
// Tính taxi Matrix
void TaxiScore(int TaxiMatrix[10][10], int E3) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            TaxiMatrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
}

int maxInLeftRightDiagonalTaxiMatrix(int TaxiMatrix[10][10], int i, int j){
    int max = TaxiMatrix[i][j];
    
    //Left
    int positionI = i;
    int positionJ = j;
    while(positionI!=10 && positionJ!=10){
        if(TaxiMatrix[positionI][positionJ] > max){
            max = TaxiMatrix[positionI][positionJ];
        }
        positionI++;
        positionJ++;
    }
    positionI = i;
    positionJ = j;
    while (positionI >= 0 && positionJ >= 0) {
        if (TaxiMatrix[positionI][positionJ] > max) {
            max = TaxiMatrix[positionI][positionJ];
        }
        positionI--;
        positionJ--;
    }
    
    //Right
    positionI = i;
    positionJ = j;
    while(positionI!=10 && positionJ>=0){
        if(TaxiMatrix[positionI][positionJ] > max){
            max = TaxiMatrix[positionI][positionJ];
        }
        positionI++;
        positionJ--;
    }
    positionI = i;
    positionJ = j;
    while (positionI >= 0 && positionJ != 10) {
        if (TaxiMatrix[positionI][positionJ] > max) {
            max = TaxiMatrix[positionI][positionJ];
        }
        positionI--;
        positionJ++;
    }
    return abs(max);
} 

//Tính chase matrix
void createSecondMatrix(int SecondMatrix[10][10], int TaxiMatrix[10][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            SecondMatrix[i][j] = maxInLeftRightDiagonalTaxiMatrix(TaxiMatrix,i,j);
        }
    }   
}
 


int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    int TaxiMatrix[10][10]={0};
    int SecondMatrix[10][10]={0};
    TaxiScore(TaxiMatrix, E3);
    
//     //  taxi scored
//     for (int i = 0; i < 10; ++i) {
//         for (int j = 0; j < 10; ++j) {
//             cout << TaxiMatrix[i][j] << "\t";
//         }
//         cout << endl;
//     }
//  cout << endl;cout << endl;
    // Second scored
    createSecondMatrix(SecondMatrix, TaxiMatrix);
    // for (int i = 0; i < 10; ++i) {
    //     for (int j = 0; j < 10; ++j) {
    //         cout << SecondMatrix[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    //tinh i va j noi gap nhau giua taxi va 2 guys
    int ifake = 0;
    int jfake = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) { 
            if (TaxiMatrix[i][j]> E3*2) { ifake++;}
            else if (TaxiMatrix[i][j] < -E3) { jfake++;}
        }}
        while (ifake >9) {
            ifake = ifake/10 + ifake%10;
        }
        while (jfake >9){
            jfake = jfake/10 + jfake%10;
        }
       int i= ifake;
       int j=jfake;
        if (SecondMatrix[i][j]>abs (TaxiMatrix[i][j]))
        { EXP1 *= 1.12;
           EXP2 *= 1.12;
           HP1 *=1.1;
           HP2 *=1.1; 
        //    cout <<endl;
            return SecondMatrix[i][j];
        }
           else if (abs (TaxiMatrix[i][j])>SecondMatrix[i][j] ){
               EXP1 *=0.88; 
               EXP2 *= 0.88;
               HP1 *= 0.9; 
               HP2 *= 0.9;
            //    cout<<endl;
               return TaxiMatrix[i][j];}
          
      if (EXP1 > 600)
	{
	  EXP1 = 600;
	}
  else if (EXP1 < 0)
	{
	  EXP1 = 0;
	}
  if (EXP2 > 600)
	{
	  EXP2 = 600;
	}
  else if (EXP2 < 0)
	{
	  EXP2 = 0;
	}
	
	
  if (E3 > 99 && E3 < 0)
	{
	  E3 = -99;    
if (HP1>666) {
    HP1 = 666; }
    else if ( HP1 <0) {
        HP1 = 0; }
    if (HP2>666) {
    HP2 = 666; }
    else if ( HP2 <0) {
        HP2 = 0; }

	}

    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
  char inputEmail[strlen(email) + 1];
    strcpy(inputEmail, email);

    
    string inputEmailStr(inputEmail);

    
    
        if (strlen(s) < 8 ) {
            return -1; 
        }

        if (strlen(s) > 20) {
            return -2; 
        }

        // check 
        char* se;
        se = strtok(inputEmail, "@"); //sepa
        const char* LOL = strstr(s, se);
        if (LOL) {
            int sei = LOL - s;
            return -(300 + sei);
        }

        // check specialchars
        const char* blablabla = "@#%$!";  //add 
        const char* symbol = strpbrk(s, blablabla);
        if (symbol == nullptr) {
            return -5;
        }

        // check 2 the same chars
        for (int sci = 0; sci < strlen(email) - 2; ++sci) {
            if (s[sci] == s[sci + 1] && s[sci] == s[sci + 2]) {
                return -(400 + sci);
            }
        }
        
        return -10;
    return -99;
}
// Task 5
 
int findCorrectPassword (const char *arr_pwds[], int num_pwds)
{
  
 
int tansuatlonnhat = 0;
  
int dodailonnhat = 0;
  
int tansuat_recent;
  
int vitridautiencuarealpass;
  
 
 
for (int x = 0; x < num_pwds; x++)
	{
	  
tansuat_recent = 0;
	  
for (int y = 0; y < num_pwds; y++)
		{
		  
if (arr_pwds[x] == arr_pwds[y])
			{
			  
tansuat_recent++;
			
}
		
}
	  
 
int dodai_recent = strlen (arr_pwds[x]);
	  
if (tansuat_recent > tansuatlonnhat
		   || (tansuat_recent == tansuatlonnhat
			   && dodai_recent > dodailonnhat))
		{
		  
dodailonnhat = dodai_recent;
		  
tansuatlonnhat = tansuat_recent;
		  
vitridautiencuarealpass = x;
		
}
	
}
  
return vitridautiencuarealpass;
  
return -1;

}


 



 
 


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////