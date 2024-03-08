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

//Ranging values//
   int ranging(int input, int low, int high){
    if(input<=low){
        input=low;
    } else if(input>=high){
        input=high;
    }
    return input;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
if(e1<0 || e1>99){
    return -99;
}
exp1 = ranging(exp1,0,600);
exp2 = ranging(exp2,0,600);

float exp1f,exp2f,e1f;

e1f=e1;
exp1f=exp1;
exp2f=exp2;

  if(e1f>=0 && e1f<=99){
        //Case 1//
        if(e1<=3){
            switch(e1){
            case 0:
                exp2f += 29;
                break;
            case 1:
                exp2f += 45;
                break;
            case 2:
                exp2f += 75;
                break;
            case 3:
                exp2f += 149;
                break;
                
            } 
      //Sherlock's decision//      
      int D;
      float Df=D;
      Df=e1f*3 + exp1f*7;
       if(D%2==0){
        exp1f += Df/200;
       }
       else{
        exp1f -= Df/100;
       }
       
    }
        //Case 2//
    if(e1f>=4){
        if(e1f<=19){
            exp2f += e1f/4 + 19;
        }
        if(e1f>=20&&e1f<=49){
            exp2f += e1f/9 + 21;
        }
        if(e1f>=50&&e1f<=65){
            exp2f += e1f/16 + 17;
        }
        if(e1f>=66&&e1f<=79){
            exp2f += e1f/4 + 19;
            exp2=ceil(exp2f);
            exp1=ceil(exp1f);
            
            if(exp2f>200){
                exp2f += e1f/9 + 21;
            }
        }
        if(e1f>=80&& e1f<=99){
            exp2f += (e1f*13)/36 + 40; //Both Info 1 & 2//
            exp2=ceil(exp2f);
            exp1=ceil(exp1f);
            
            if(exp2f>400){
                exp2f += e1f/16 + 17;
                exp2f *= 1.15; 
            }
        }
    exp2=ceil(exp2f);
    exp1=ceil(exp1f);
        //Sherlock's mistake//
        exp1f -= e1f;
    }
   
}
 else{
        return -99;
    }
    
    //Round the values//
    exp2=ceil(exp2f);
    exp1=ceil(exp1f);
    
    exp1 = ranging(exp1,0,600);
    exp2 = ranging(exp2,0,600);
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

if(E2<0 || E2>99){
    return -99;
}
   EXP1 = ranging(EXP1,0,600);
   HP1 = ranging(HP1,0,666);
   M1 = ranging(M1,0,3000);
   
   //Road 01//
   float EXP1f=EXP1;
   float P1,P2,P3,P;
 
   //Determine perfect square S//
   int S;
   double sqrtnum1 = sqrt(EXP1f);
   
   int lowersqrt = floor(sqrtnum1);
   int highersqrt = lowersqrt + 1;
   
   int lowernum = lowersqrt * lowersqrt;
   int highernum = highersqrt * highersqrt;
   
   if(EXP1f-lowernum<highernum-EXP1f){
       S=lowernum;
   }
   else{
       S=highernum;
   }
    
    //Suitcase finding probability//
    if(EXP1f>=S){
        P1=1;
    }
    else{
        P1= (EXP1f/S+80)/123;
    }
 
 
   //ROAD 02//
   float HP1f=HP1;
   float M1_spent=0;
   const float M1_initial=M1;
    while(true){
    
    //Buying supplements//
    if(E2%2==1 && M1_spent>M1_initial/2){
        HP1f *= 0.83;
        EXP1f *= 1.17;
        break;
    }
    else if(E2%2==0 && M1<=0){
        HP1f *= 0.83;
        EXP1f *= 1.17;
        break;
    }
    EXP1f=ceil(EXP1f);
    HP1f=ceil(HP1f);

    if(HP1f<200){         //Food//
        HP1f *= 1.3;
        M1 -= 150;
        M1_spent += 150;
    }
    else{                 //Drink//
        HP1f *= 1.1;
        M1 -= 70;
        M1_spent += 70;
    }
    EXP1f=ceil(EXP1f);
    HP1f=ceil(HP1f);


        //Taxi or Carriage//
        if(E2%2==1 && M1_spent>M1_initial/2){
        HP1f *= 0.83;
        EXP1f *= 1.17;
        break;
    }
    else if(E2%2==0 && M1<=0){
        HP1f *= 0.83;
        EXP1f *= 1.17;
        break;
    }
    EXP1f=ceil(EXP1f);
    HP1f=ceil(HP1f);

    if(EXP1f<400){        //Taxi//
        M1 -= 200;
        M1_spent += 200;
        EXP1f *= 1.13;
    }
    else{                //Carriage//
        M1 -= 120;
        M1_spent += 120;
        EXP1f *= 1.13;
    }
    EXP1f=ceil(EXP1f);
    HP1f=ceil(HP1f);

    //Hint from homeless person//
    if(E2%2==1 && M1_spent>M1_initial/2){
        HP1f *= 0.83;
        EXP1f *= 1.17;
        break;
    }
    else if(E2%2==0 && M1<=0){
        HP1f *= 0.83;
        EXP1f *= 1.17;
        break;
    }
    EXP1f=ceil(EXP1f);
    HP1f=ceil(HP1f);
    
    if(EXP1f<300){     //bro lost money for nothing lol//
        M1 -= 100;
        M1_spent += 100;
        EXP1f *= 0.9; 
    }
    else{
        M1 -= 120;
        M1_spent += 120;
        EXP1f *= 0.9;
    }

 }
    EXP1f=ceil(EXP1f);
    HP1f=ceil(HP1f);


   //Calculate P2//
   sqrtnum1 = sqrt(EXP1f);
   
   lowersqrt = floor(sqrtnum1);
   highersqrt = lowersqrt + 1;
   
   lowernum = lowersqrt * lowersqrt;
   highernum = highersqrt * highersqrt;
   
   if(EXP1f-lowernum<highernum-EXP1f){
       S=lowernum;
   }
   else{
       S=highernum;
   }
    if(EXP1f>=S){
        P2=1;
    }
    else{
        P2= (EXP1f/S+80)/123;
    }


    //ROAD 03//
    float P_array[10]={32,47,28,79,100,50,22,83,64,11};
    int i;
    
    if(E2<10){
        i = E2;
    } else{
        int sum = E2/10 + E2%10;
        i = sum%10;     //i equal to the first digit//
    }
    P3 = P_array[i]/100;
    
    if(P1==1 && P2==1 && P3==1){
        EXP1f *= 0.75;
    } else{
        P = (P1+P2+P3)/3;
    }
    EXP1f=ceil(EXP1f);
    HP1f=ceil(HP1f);
    
    if (P<0.5){
        HP1f *= 0.85;
        EXP1f *= 1.15;
    } else{
        HP1f *= 0.90;
        EXP1f *= 1.20;
    }
    EXP1f=ceil(EXP1f);
    HP1f=ceil(HP1f);
    
    EXP1=ceil(EXP1f);
    HP1=ceil(HP1f);
     
    EXP1 = ranging(EXP1,0,600);
    HP1 = ranging(HP1,0,666);
    M1 = ranging(M1,0,3000);
    
    return HP1 + EXP1 + M1;
}

// Task 3

//Find the max value//
int maxDiag(int matrix[10][10], int i, int j){
    int maxnum=matrix[i][j]; //Assume maxnum at X(i,j)
    int r=i;
    int c=j;
    
  //LEFT//
  while (r<10 && c<10){ //Up
	  --r;
	  --c;
	  if (r<0){
		  ++r;
		  ++c;
		  maxnum = max(maxnum, matrix[r][c]);
		  break;
		}
	  else if (c<0){
		  ++r;
		  ++c;
		  maxnum = max(maxnum, matrix[r][c]);
		  break;
		}
	  else
		maxnum = max(maxnum, matrix[r][c]);
	}

  r=i; c=j;
  while (r<10 && c<10){  //Down
	  ++r;
	  ++c;
	  if (r<0){
		  --r;
		  --c;
		  maxnum = max(maxnum, matrix[r][c]);
		  break;
		}
	  else if (c<0){
		  --r;
		  --c;
		  maxnum = max(maxnum, matrix[r][c]);
		  break;
		}
	  else
		maxnum = max(maxnum, matrix[r][c]);
	}
  r=i; c=j;
  //RIGHT//
  while (r<10 && c<10){							//Up
	  --r;
	  ++c;
	  if (r < 0){
		  ++r;
		  --c;
		  maxnum = max (maxnum, matrix[r][c]);
		  break;
		}
	  else if (c < 0){
		  ++r;
		  --c;
		  maxnum = max (maxnum, matrix[r][c]);
		  break;
		}
	  else
		maxnum = max (maxnum, matrix[r][c]);
	}
  r=i; c=j;
  while (r < 10 && c < 10){							//Down
	  ++r;
	  --c;
	  if (r < 0){
		  --r;
		  ++c;
		  maxnum = max (maxnum, matrix[r][c]);
		  break;
		}
	  else if (c < 0){
		  --r;
		  ++c;
		  maxnum = max (maxnum, matrix[r][c]);
		  break;
		}
	  else
		maxnum = max (maxnum, matrix[r][c]);
	}
    return maxnum;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0 || E3>99){
    return -99;
}
    EXP1 = ranging(EXP1,0,600);
    HP1 = ranging(HP1,0,666);
    EXP2 = ranging(EXP2,0,600);
    HP2 = ranging(HP2,0,666);
    
    float EXP1f=EXP1;
    float EXP2f=EXP2;
    float HP1f=HP1;
    float HP2f=HP2;
    
    //Create matrix//
    int matrixTaxi[10][10]={0}; //Initial value = 0//
    int matrixSherlock[10][10]={0};
    
    for(int i=0; i<10; ++i){
        for(int j=0; j<10; ++j){
            matrixTaxi[i][j] = ((E3*j)+(i*2))*(i-j);
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrixSherlock[i][j] = maxDiag(matrixTaxi, i, j);
        }
    }
    
    int larger_n, smaller_n;
    for(int i=0; i<10; ++i){
        for(int j=0; j<10; ++j){
            if(matrixTaxi[i][j]>E3*2){
                ++larger_n;
            }
            if(matrixTaxi[i][j]<0 && matrixTaxi[i][j]<-E3){
                ++smaller_n;
            }
        }
    }
    int i_after;
    int j_after;
    
    if(larger_n<10){
        i_after = larger_n;
    } else {
        i_after=larger_n/10 + larger_n%10;
        if(i_after>9){
            i_after = i_after/10 + i_after%10;
        }
    }
    if(smaller_n<10){
        j_after=smaller_n;
    } else{
        j_after=smaller_n/10 + smaller_n%10;
        if(j_after>9){
            j_after = j_after/10 + j_after%10;
        }
    }
    
    if(abs(matrixTaxi[i_after][j_after])>=maxDiag(matrixTaxi,i_after,j_after)){
        EXP1f*=0.88;
        EXP2f*=0.88;
        HP1f*=0.9;
        HP2f*=0.9;
    EXP1=ceil(EXP1f);
    EXP2=ceil(EXP2f);
    HP1=ceil(HP1f);
    HP2=ceil(HP2f);
        return matrixTaxi[i_after][j_after];
    } else{
        EXP1f*=1.12;
        EXP2f*=1.12;
        HP1f*=1.1;
        HP2f*=1.1;
    EXP1=ceil(EXP1f);
    EXP2=ceil(EXP2f);
    HP1=ceil(HP1f);
    HP2=ceil(HP2f);
        return maxDiag(matrixTaxi,i_after,j_after);
    }
    
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
    //Declare temporary strings//
    char email_t[strlen(email)];
    strcpy(email_t,email);
    char s_t[strlen(s)];
    strcpy(s_t,s);
    char *se;
    
    if(strlen(email)<=100)
        {
    se = strtok(email_t, "@");
    
    int len_s=strlen(s);
    if(len_s<8){
        return -1;
    } else if(len_s>20){
        return -2;
    }
    
    char * position;
    position = strstr(s_t,se);
    int sei=position-s_t;
    
    if(position != NULL){
        return -(300+sei);
    }
    
    for(int sci=0; sci<len_s - 2; ++sci){
        if(s_t[sci]==s_t[sci+1] && s_t[sci]==s_t[sci+2]){
            return -(400+sci);
        }
    }
    
    bool special = false;
    for (int i = 0; i < len_s; ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            special = true;
            break;
        }
    }
    if (!special) {
        return -5;
    }
    
    return -10;
}else
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int passnum=0,passlen,maxlen=0,maxnum=0,passpos=-1;

    for(int i=0; i<num_pwds;++i){
        passlen=strlen(arr_pwds[i]);
        passnum=0;
        
        for(int j=0; j<num_pwds;++j){
            if(strcmp(arr_pwds[i], arr_pwds[j])==0){
                ++passnum;
            }
        }
         if(passnum>maxnum || (passnum==maxnum && passlen>maxlen)){
         maxnum=passnum;
         maxlen=passlen;
         passpos=i;    //Correct password position
         
            }
        }
    return passpos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////