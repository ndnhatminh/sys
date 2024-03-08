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
int hp(int &HP){
    if (HP < 0) HP = 0;
    else if (HP > 666) HP = 666;
    return HP;
}
int exp(int &EXP){
    if (EXP < 0) EXP = 0;
    else if (EXP > 600) EXP = 600;
    return EXP;
}

int moneyChecking(int &M){
    if (M < 0) M = 0;
    else if (M > 3000) M = 3000;
    return M;
}



int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function   
    if (e1 < 0 || e1 > 99) return -99;
    exp(exp1);  exp(exp2);
    if ((e1 >= 0) && (e1 <= 3)){
        if (e1 == 0)            {exp2 += 29;}
        else if (e1 == 1)       {exp2 += 45;}
        else if (e1 == 2)       {exp2 += 75;}
        else                    {exp2 += 149;}
        if (exp2 > 600) {exp2 = 600;}  
        int D = e1*3 + exp1 * 7;
        if (D % 2 == 0)         {exp1 += ceil((float)D/200 -1e-9);}
        else                    {exp1 -=floor((float)D/100 -1e-9);}
        if (exp1 < 0) {exp1 = 0;} if (exp1 > 600) {exp1 = 600;}
    }
    else if (e1 >= 4 && e1 <= 19)   {exp2 += ceil((float)e1/4 + 19 -1e-9);} 
    else if (e1 >=20 && e1 <= 49)   {exp2 += ceil((float)e1/9 + 21 -1e-9);}
    else if(e1 >= 50 && e1 <= 65)   {exp2 += ceil((float)e1/16 + 17 -1e-9);}
    else if (e1 >= 66 && e1 <= 79){
        exp2 += ceil((float)e1/4 + 19 -1e-9);   exp(exp2);
        if (exp2 > 200)             {exp2 += ceil((float)e1/9 + 21 - 1e-9);}    
    }
    else  {
        exp2 += ceil((float)e1/4 + 19 -1e-9);   exp(exp2);
        exp2 += ceil((float)e1/9 + 21 -1e-9);   exp(exp2);
        if (exp2 > 400){
            exp2 += ceil((float)e1/16 + 17 -1e-9);  exp(exp2);    
            exp2 +=ceil((exp2*1.0) * 0.15 -1e-9);                
        }
    }
    if (e1 >= 4 && e1 <= 99)    {exp1 -= e1; exp(exp1);}
    exp(exp2);
    return exp1 + exp2;
}

// Task 2
int nearestSquare(int &EXP1){
  int root = round (sqrt(EXP1));
  int square = root * root;
  return square;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
   float P1, P2, P3, P;
    if (E2 < 0 || E2 > 99) return -99;
     
    hp(HP1);
    exp(EXP1);
    moneyChecking(M1);  
        //Road No.1
    int S = nearestSquare(EXP1);
    if (EXP1 >= S){P1 = 1.00;}
    else {P1 = (EXP1*1.0f/S + 80)/123;}

        //Road No.2
    int sum = 0;
    double m1a;
    if (E2 % 2 == 1){
        m1a = (double)M1 * 0.5;
        while (sum <= m1a && M1 != 0){
            if (HP1 < 200){  //Food and drink
                HP1 = ceil(-1e-9 + HP1 * 1.3);
			    hp(HP1);
                M1 -= 150;
			    moneyChecking(M1);
                sum += 150;
			    }
			else {
			 	HP1 = ceil(-1e-9 + HP1*1.1);
				hp(HP1);
			 	M1 -= 70;
				moneyChecking(M1);
			 	sum += 70;
			}
		    if (sum <= m1a){
			    if (EXP1 < 400){  //Taxi or horse
			 	M1 -= 200;
				moneyChecking(M1);
			 	sum += 200;
			 	EXP1 = ceil(-1e-9 + EXP1 *1.13);	
				exp(EXP1);
			    }
			    else {
			 	M1 -= 120;
				moneyChecking(M1);
			 	sum += 120;
			 	EXP1 = ceil(-1e-9 + EXP1 *1.13);
				exp(EXP1);
			    } 
			} else {break;}
			if (sum <= m1a){
			    if (EXP1 < 300){  //Homelessman
			 	M1 -= 100;
				moneyChecking(M1);
			 	sum += 100;
			 	EXP1 = ceil(-1e-9 + EXP1*0.9);
				exp(EXP1); 
			    }
			    else {
			 	M1 -= 120;
				moneyChecking (M1); 
			 	sum += 120;
			 	EXP1 = ceil(-1e-9 + EXP1*0.9);
				exp (EXP1);
				}
			} else {break;}
        }
	}		 //E2 is even
	else {	
		do {	
			if (M1 == 0) break; 
			if (HP1 < 200){ //Food
             	HP1 = ceil(-1e-9 + HP1 * 1.3);
				hp(HP1);				
             	M1 -= 150;
                moneyChecking(M1);				
			}
			else {
			 	HP1 = ceil(-1e-9 + HP1*1.1);
				hp ( HP1);	
			 	M1 -= 70;
			 	moneyChecking(M1);	 
			}
		    if (M1 == 0) break;
			 	//Taxi or horse
			if (EXP1 < 400){
			 	M1 -= 200;
				moneyChecking(M1);
			 	EXP1 = ceil(-1e-9 + EXP1 *1.13);
			 	exp(EXP1);
			}
			else {
			 	M1 -= 120;
				moneyChecking(M1);
			 	EXP1 = ceil(-1e-9 + EXP1 *1.13);
				exp(EXP1);
			}	 
		    if (M1 == 0) break;
			 	//Homelessman
			 	if (EXP1 < 300){
			 	M1 -= 100;
				moneyChecking (M1);
			 	EXP1 = ceil(-1e-9 + EXP1*0.9);
				exp (EXP1); 
			}
			else {
			 	M1 -= 120;
				moneyChecking(M1);
			 	EXP1 = ceil(-1e-9 + EXP1*0.9);
				exp (EXP1);
			} 
		} while(false);
	}
	HP1 = ceil(-1e-9 + HP1*0.83); //Reduce 17%
	EXP1 = ceil(-1e-9 + EXP1*1.17); //Increase 17%	
    exp (EXP1);	 
    S = nearestSquare(EXP1);
    if (EXP1 >= S){P2 = 1.00;}
    else {P2 = (EXP1*1.0f/S + 80)/123;}
			 
    //Road No.3
    int arr_P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 >= 0 && E2 <= 9){
       i = E2;
    }     
    if (E2 >= 10 && E2 <= 99){
       
       i = (E2/10 + E2 % 10)% 10;
    }
	P3 = arr_P[i]*1.0f/100;
    //Calculating the percentage of chance for finding the luggage 
    if (P1 == 1.00 && P2 == 1.00 && P3 == 1.00){
        EXP1 = ceil(-1e-9 + EXP1 * 0.75);
        exp(EXP1);}
    else {
        P = (P1 + P2 + P3)/3;
        if (P >= 0.50){
            HP1 = ceil(-1e-9 + HP1 * 0.9);
			hp( HP1);
            EXP1 = ceil(-1e-9 + EXP1 * 1.2);
			exp (EXP1);	
        }
        else {
            HP1 = ceil(-1e-9 + HP1 * 0.85);
			hp( HP1);	
            EXP1 = ceil(-1e-9 + EXP1 * 1.15);
			exp (EXP1);	
        }    
    }  
    return HP1 + EXP1 + M1;
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
     if (E3 < 0 || E3 > 99) return -99;
    int map_taxi[10][10];
     int Mei = 0, Mej = 0; //Meeting point
     //Creating a matrix
     for ( int i = 0; i < 10; i++){
      for (int j = 0; j < 10; j++){
        map_taxi[j][i] = ((E3*j) + i * 2)*(i-j); 
        if(map_taxi[j][i] > 2 * E3){
          Mei++;
        }
        
        if (map_taxi[j][i] < -E3){
          Mej++;
        }
        
      }
     }
         while (Mei >= 10){
          Mei = Mei % 10 + Mei /10;
         }

         while (Mej >= 10){
          Mej = Mej % 10 + Mej /10;
         }

         int Max_score = 0;
         int Main_i = Mei, Main_j = Mej;
          
          //Left diagonal
          if (Main_i > Main_j){
            Main_i -= Main_j;
            Main_j = 0;
          }
          
          else{
            Main_j -= Main_i;
            Main_i = 0;
          }
          
          Max_score = map_taxi[Main_j][Main_i];
          while (Main_i != 10 && Main_j != 10){
            if (Max_score > map_taxi[Main_i][Main_j]){
              Max_score = Max_score;
            }
            else {Max_score = map_taxi[Main_i][Main_j];}
            Main_i++; Main_j++;
          }

          //Right diagonal
          Main_i = Mei, Main_j = Mej;
          if (Main_i > (10 - Main_j)){
            Main_i -= (10 - Main_j);
            Main_j = 10;
          }
          else {
                Main_j += Main_i;
                Main_i = 0;
          }

          while(Main_i != 10 && Main_j != -1){
            if (Max_score > map_taxi[Main_j][Main_i]){
              Max_score = Max_score;
            }
            else {Max_score = map_taxi[Main_j][Main_i];}
            Main_i++; Main_j--;
          }

             if (abs(map_taxi[Mej][Mei]) <= Max_score){
        	EXP1 += ceil(EXP1 *1.0* 0.12 - (1e-9));
        exp(EXP1);
        EXP2 += ceil(EXP2 * 1.0*0.12 - (1e-9));
        exp(EXP2);
        HP1 += ceil(HP1*1.0*0.1 -(1e-9));
         hp(HP1);
         HP2 += ceil(HP2*1.0*0.1 -(1e-9));
         hp(HP2);
      }
      else{
        EXP1 -= floor(EXP1 * 0.12*1.0 +1e-9);
        exp(EXP1);
        EXP2 -= floor(EXP2*1.0 * 0.12 +1e-9);
        exp(EXP2);
        HP1 -= floor(HP1*1.0*0.1 + 1e-9);
         hp(HP1);
         HP2 -= floor(HP2*1.0*0.1 + 1e-9);
         hp(HP2);
		}
		return (abs(map_taxi[Mej][Mei]) > Max_score) ? map_taxi[Mej][Mei] : Max_score;
}

// Task 4
int checkPassword(const char * s, const char * email) {
	string S = s;
	string Email = email;
	
	int Sei, result, index, index_other;
    string se;
    bool Special_char = false;

    if (strlen(s) < 8) return -1;
	if (strlen(s) > 20) return -2;
	
 size_t position = Email.find('@');
		if (position != string::npos)
	   se = Email.substr(0, position);
        
    size_t sei = S.find(se);
    if (sei != string::npos){
    Sei = (int)sei;
    result = -(300+sei);
	return result;}
	
	for (int i = 0; i < S.length(); i++){
		if (S[i] == S[i+1] && S[i+1] == S[i+2]){
		
		index = i;
		result = -(400+index);
		return result;}
	}
	
	for (char c : S){
	 if (c == '!'|| c == '@' || c == '#' || c == '$' || c == '%') 
		 {Special_char = true;}
	      }
		   if (!Special_char) return -5;
		 
for (int i = 0; i < S.length(); i++){
  if (!((s[i] >= 'A'&& s[i] <= 'Z')||(s[i] >= 'a' && s[i] <= 'z')||(s[i] >= '0' && s[i] <= '9')||s[i]== '!'||s[i] == '@' ||s[i] == '$' || s[i] == '#' || s[i] == '%')){
		index_other = i;
			return index_other;
	}
		 }
		 
	return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
   string ar[num_pwds];
   int pos[num_pwds];
   int count = 1;

   for (int i = 0; i < num_pwds; i++){
     if (i == 0){ar[i] = arr_pwds[i];
     pos[i] = 0;
     continue;
     }
     for (int j = 0; j < i; j++){
     if (strcmp(arr_pwds[j], arr_pwds[i]) == 0)
     break;
     if (j == (i-1)){
      ar[count] =arr_pwds[i];
      pos[count] = i;
      count++;
     }
     }
   }

   int frequency[count]; //Frequency of password's occurence
   for(int i = 0 ; i < count; i++){
     frequency[i] = 0;
       for (int j = 0; j < num_pwds; j++){
        if (ar[i]== arr_pwds[j]){
          frequency[i]++;
        }
       }
   }

    //Comparing groups of pwd to return first position
   int maximum = 0;
   for(int i = 0; i < count; i++){
    if (frequency[maximum] == frequency[i]){
      if (ar[maximum].length() < ar[i].length()){
        maximum = i;
      }
    }
    if(frequency[maximum] <frequency[i]) maximum = i;
   }
   return pos[maximum];
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////