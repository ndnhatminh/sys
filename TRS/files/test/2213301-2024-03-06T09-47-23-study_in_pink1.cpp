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



















void checkHP(int & HP) {
    if ( HP < 0 )             {   HP = 0   ;     }
    else if ( HP > 666 )      {   HP = 666 ;     }

    return ;
}
void checkEXP(int & EXP) {
    if ( EXP < 0 )             {   EXP = 0    ;    }
    else if ( EXP > 600 )      {   EXP = 600  ;    }

    return;
}
void checkMONEY(int & M){
    if ( M < 0 )               {   M = 0      ;     }   
    else if ( M > 3000 )       {   M = 3000   ;     }

    return;
}

// task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    if( e1 < 0 || e1 > 99 ) return -99; // Check if the event code is valid
          
        // case 1 : e1 = [0,3]

      if(e1>=0 && e1<=3){                 
               if( e1 == 0 )      {  exp2 += 29; }
          else if( e1 == 1 )      {  exp2 += 45; } 
          else if( e1 == 2 )      {  exp2 += 75; }  
          else                    {  exp2 += (29+45+75); }  
                    
        int D = e1 * 3 + exp1 * 7  ;
            D % 2 == 0 ? exp1 = ceil(exp1+static_cast<double>(D)/200) : exp1 = ceil(exp1-static_cast<double>(D)/100);
        
        checkEXP(exp1);
        checkEXP(exp2);

      }
      else{                            
            
            // case 2: e1 = [4,99]       

          if( e1 >= 4 && e1 <= 19 )             { exp2 += ceil( e1/4.0 + 19 ); }
          else if(e1>=20 && e1<=49)             { exp2 += ceil( e1/9.0 + 21 ); }
          else if(e1>=50 && e1<=65)       { exp2 += ceil( e1/16.0 + 17 );}
          else if(e1>=66 && e1<=79)       { exp2 += ceil( e1/4.0 + 19); if(exp2 > 200) exp2 += ceil( e1/9.0 + 21 ); }
          else { exp2 += ceil( e1/4.0 + 19 ); exp2 += ceil( e1/9.0 + 21 ); if(exp2 > 400) { exp2 += ceil( e1/16.0 + 17 ); exp2 = ceil(exp2*1.15);  }  }

          exp1 -= e1;

        checkEXP(exp1);
        checkEXP(exp2);
      }
    
   
    return exp1 + exp2;
}

// Task 2
int near_SquareNum(int num)
{   
    if(num == 0) return 1; // số 0 không phải số chính phương

    // Nếu num là số chính phương
    int sqrtTarget = static_cast<int>(sqrt(num));
    if (sqrtTarget * sqrtTarget == num) {
        return num;
    }

    // Nếu không, tìm số chính phương gần nhất
    int lowerSquare = sqrtTarget * sqrtTarget;
    int upperSquare = (sqrtTarget + 1) * (sqrtTarget + 1);

    if (abs(num - lowerSquare) < abs(num - upperSquare)) {
        return lowerSquare;
    } else {
        return upperSquare;
    }
}
double path_1(int & EXP1)
{
    int S;

    S = near_SquareNum(EXP1);
    double result = static_cast<double>(EXP1) / S;

    EXP1 >= S ? result = 1 : result = (result + 80) / 123;

    return result; 
}
double path_2(int & HP1, int & EXP1, int & M1, int & E2)
{
    
    /* do
    {   
        // event : get into a grocery store
        if(HP1 < 200){
            
            M1 -= 150 ;
            HP1 = ceil(static_cast<double>(HP1)*1.30) ;

            pay += 150 ;
            
            checkHP(HP1);
            checkMONEY(M1) ;
            
            if(M1 <= 0 ) break;
            if(pay > wallet) break;
        }
        else{

            M1 -= 70 ;
            HP1 = ceil(static_cast<double>(HP1)*1.10) ;

            pay += 70 ;

            checkHP(HP1);
            checkMONEY(M1) ;
            
            if(M1 <= 0) break;
            if(pay > wallet) break;

        }
       
        

        // event : rent a taxi or carriage
        if(EXP1 < 400){

            M1 -= 200 ;
            EXP1 = ceil(static_cast<double>(EXP1)*1.13) ;

            pay += 200 ;

            checkEXP(EXP1) ; 
            checkMONEY(M1) ;
            
            if(M1 <= 0) break;
            if(pay > wallet) break;
        }
        else{

            M1 -= 120 ;
            EXP1 = ceil(static_cast<double>(EXP1)*1.13) ;

            pay += 120 ;

            checkEXP(EXP1) ; 
            checkMONEY(M1) ;
            
            if(M1 <= 0) break;
            if(pay > wallet) break;

        }
        
        

        // event :  help this homeless person
        if( EXP1 < 300){
            
            M1   -= 100 ;
            EXP1 = ceil(static_cast<double>(EXP1)*0.90) ;

            pay += 100 ;

            checkEXP(EXP1) ;
            checkMONEY(M1) ;
            
            if(M1 <= 0) break;
            if(pay > wallet) break;
        }
        else{

            M1   -= 120 ;
            EXP1 = ceil(static_cast<double>(EXP1)*0.90) ;

            pay += 120 ;

            checkEXP(EXP1) ;
            checkMONEY(M1) ;
            
           
            if(M1 <= 0) break;
            if(pay > wallet) break;
        }

        

    }while( E2 % 2 != 0) ;
    */

    switch( E2 % 2 ){
        case 0 : 
        {
                // event : get into a grocery store
                if( HP1 < 200) {
            
                            M1 -= 150 ;
                            HP1 = ceil(HP1*1.3) ;

            
                            checkHP(HP1);
                            checkMONEY(M1) ;
            
                            if(M1 <= 0 ) break;
                }
                else {

                            M1 -= 70 ;
                            HP1 = ceil(static_cast<double>(HP1+0.1*HP1)) ;

                            checkHP(HP1);
                            checkMONEY(M1) ;
            
                            if(M1 <= 0) break;
           
                    }
       
                // event : rent a taxi or carriage
                if(EXP1 < 400){

                            M1  -= 200 ;
                            EXP1 = ceil(static_cast<double>(EXP1)*1.13) ;

                            checkEXP(EXP1) ; 
                            checkMONEY(M1) ;
            
                            if(M1 <= 0) break;
           
                }
                else {

                            M1  -= 120 ;
                            EXP1 = ceil(static_cast<double>(EXP1)*1.13) ;

                            checkEXP(EXP1) ; 
                            checkMONEY(M1) ;
            
                            if(M1 <= 0) break;
        
                    }
        
                // event :  help this homeless person
                if( EXP1 < 300){
            
                            M1  -= 100 ;
                            EXP1 = ceil(static_cast<double>(EXP1)*0.90) ;

                           
                            checkEXP(EXP1) ;
                            checkMONEY(M1) ;
                            
                            if(M1 <= 0) break;
            
                }
                else {

                            M1  -= 120 ;
                            EXP1 = ceil(static_cast<float>(EXP1)*0.90) ;

                           

                            checkEXP(EXP1) ;
                            checkMONEY(M1) ;
                            
                        
                            if(M1 <= 0) break;
                        
                    }
        }
            break;

        default: 
        {
                        int wallet = M1 * 0.5;
                        int pay = 0 ;
                while(M1) {
                    
                // event : get into a grocery store
                if(HP1 < 200){
                            
                        M1 -= 150 ;
                        HP1 = ceil(HP1*1.3) ;

                        pay += 150 ;
                            
                        checkHP(HP1);
                        checkMONEY(M1) ;
                             
                }
                else {

                        M1 -= 70 ;
                        HP1 = ceil(static_cast<float>(HP1+HP1*0.1)) ;

                        pay += 70 ;

                        checkHP(HP1);
                        checkMONEY(M1) ;
                                 
                }
                    
                if( pay > wallet ) break;

                // event : rent a taxi or carriage
                if(EXP1 < 400){

                        M1 -= 200 ;
                        EXP1 = ceil(static_cast<double>(EXP1)*1.13) ;

                        pay += 200 ;

                        checkEXP(EXP1) ; 
                        checkMONEY(M1) ;
                            
                    }
                    else{

                        M1 -= 120 ;
                        EXP1 = ceil(static_cast<double>(EXP1)*1.13) ;

                        pay += 120 ;

                        checkEXP(EXP1) ; 
                        checkMONEY(M1) ;
                            
                        
                        

                    }
                        
                        if( pay > wallet ) break;

                        // event :  help this homeless person
                        if( EXP1 < 300){
                            
                            M1   -= 100 ;
                            EXP1 = ceil(static_cast<double>(EXP1)*0.9) ;

                            pay += 100 ;

                            checkEXP(EXP1) ;
                            checkMONEY(M1) ;
                            
                        
                        
                        }
                        else{

                            M1   -= 120 ;
                            EXP1 = ceil(static_cast<double>(EXP1)*0.9) ;

                            pay += 120 ;

                            checkEXP(EXP1) ;
                            checkMONEY(M1) ;
                            
                        
                        
                            
                        }

                        if( pay > wallet ) break;
            }

        }
            break;

    }

    // Update after reaching the end of the road 
    HP1  = ceil(static_cast<double>(HP1*0.83))  ;
    EXP1 = ceil(EXP1*1.17) ;

    checkHP(HP1)      ;
    checkEXP(EXP1)    ;
    checkMONEY(M1)    ;

    return path_1(EXP1);
}
double path_3(int arr[], int E2)
{
    int i=0;
    E2 <= 9 ? i = E2 : i = ((E2/10) + (E2%10))%10 ;

    return arr[i]/100.0; 
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    if(E2<0 || E2>99) return -99;

    double P1=0,P2=0,P3=0;

    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

    P1 = path_1(EXP1);
    P2 = path_2(HP1, EXP1, M1, E2);
    P3 = path_3(P, E2);

    if( (P1+P2+P3)/3 == 1 ){
        EXP1 = ceil(static_cast<double>(EXP1)*0.75) ;
    }
    else    if( (P1+P2+P3)/3 >= 0.5 ){

                HP1  = ceil(static_cast<double>(HP1*0.9));
                EXP1 = ceil(static_cast<double>(EXP1)*1.2);
           
            }
            else{

                HP1  = ceil(HP1*0.85);
                EXP1 = ceil(static_cast<double>(EXP1)*1.15);
            }

    checkHP(HP1);
    checkEXP(EXP1);
    checkMONEY(M1);

    return HP1 + EXP1 + M1;
}

// Task 3
int LeftDiagonal(int taxi_scores[10][10],int i, int j)
{
    int sw_LeftDiagonal =  INT_MIN;
    for (int k = 0; k <= i && k <= j; k++) {
        if((i-k) < 0) break;
        if((j-k) < 0) break ;
        sw_LeftDiagonal = std::max(sw_LeftDiagonal,taxi_scores[i-k][j-k]);
        
      }
     
      for(int k = 0 ; k <= 9-i  && k <= 9-j ; k++) {
        if((i+k) < 0) break ;
        if((j+k) < 0) break ;
        sw_LeftDiagonal = std::max(sw_LeftDiagonal,taxi_scores[i-k][j-k]);
       
    }
    return sw_LeftDiagonal;
}
int RightDiagonal(int taxi_scores[10][10],int i, int j)
{   
    int sw_RightDiagonal = INT_MIN;
    for(int p = i, q = j; p >= 0 && q < 10; p--, q++) {
        sw_RightDiagonal = std::max(sw_RightDiagonal, taxi_scores[p][q]);
        
      }
      
      for (int p = i, q = j; p < 10  && q >= 0; p++, q--) {
        sw_RightDiagonal = std::max(sw_RightDiagonal, taxi_scores[p][q]);
        
      }
     return sw_RightDiagonal ;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    if(E3 < 0 || E3 > 99) return -99;

    int taxi_scores[10][10] = {0} ; 
    
    // Tính điểm cho taxi
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxi_scores[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
  
    int lockson_scores[10][10] = {0} ; 

  

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int max_score = 0;
            int sw_LeftDiagonal =  INT_MIN;
            int sw_RightDiagonal = INT_MIN;

      sw_LeftDiagonal = LeftDiagonal(taxi_scores,i, j);
      sw_RightDiagonal = RightDiagonal(taxi_scores,i, j);
      max_score = max(sw_LeftDiagonal,sw_RightDiagonal);
      lockson_scores[i][j] = abs(max_score);
    }
  }

    int i = 0 , j =0 ;

    for (int p = 0; p < 10; p++) {
    for (int q = 0; q < 10; q++) {
      if( taxi_scores[p][q] > E3 * 2 ) { i++ ; }
        }
         }
  
  while(i >= 10) {
      i = i/10 + i%10 ;
  }
  
  for (int p = 0; p < 10; p++) {
    for (int q = 0; q < 10; q++) {
      if( taxi_scores[p][q] < -E3 ) { j++ ; }
    }
  }
 
  while(j >= 10) {
      j = j/10 + j%10 ;
  }


    int taxi_score = abs(taxi_scores[i][j]);
    int lockson_score = lockson_scores[i][j];

  // Xác định kết quả
  bool is_caught = false;
  if (taxi_score > lockson_score) {
    is_caught = false;
  } else {
    is_caught = true;
  }

  // Cập nhật EXP và HP
  if (is_caught) {
    HP1   = ceil(static_cast<float>(HP1+HP1*0.10))  ;
    EXP1  = ceil(static_cast<float>(EXP1+EXP1*0.12)) ;
    HP2   = ceil(static_cast<float>(HP2+HP2*0.10));
    EXP2  = ceil(static_cast<float>(EXP2+EXP2*0.12));

    checkHP(HP1)    ;
    checkHP(HP2)    ;
    checkEXP(EXP1)  ;
    checkEXP(EXP2)  ;
  } else {
    HP1   = ceil(static_cast<float>(HP1-HP1*0.1))  ;
    EXP1  = ceil(static_cast<float>(EXP1-EXP1*0.12)) ;
    HP2   = ceil(static_cast<float>(HP2-HP2*0.1))  ;
    EXP2  = ceil(static_cast<float>(EXP2-EXP2*0.12)) ;

    checkHP(HP1)    ;
    checkHP(HP2)    ;
    checkEXP(EXP1)  ;
    checkEXP(EXP2)  ;
  }

  return !is_caught ? taxi_scores[i][j] : lockson_scores[i][j] ;
  return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    // Loop to find the position of '@' in the email string.
    int at_ps = 0 ;
      while( *email != '\0' && *(email+at_ps) != '@' ){
              
            at_ps++ ;
            
      }

    // Creating a substring 'se' from the start of 'email' up to the '@'.
    
    // The cursor has pointed to the position of the character ' @' need to revert the cursor
    
    const char* start_se = email; 
    string se(start_se, start_se + at_ps); 
  

    // Returning error codes based on the length of string 's'.
    int s_length = strlen(s);
    
    if (s_length < 8) { return -1; }
    if (s_length > 20) { return -2; }

    // Checking if the substring 'se' is present in string 's' and returning a specific error code if true.
    if ( strstr(s, se.c_str()) != NULL ){

        return -(300 + strstr(s, se.c_str()) - s);
    
    }

    // Checking for consecutive triple characters in string 's' and returning a specific error code if found.
    for ( int i = 0; i < s_length - 2; i++ ){

      if ( s[i] == s[i + 1] && s[i] == s[i + 2] ){

        return -(400 + i);

      }

    }
  // Checking if string 's' contains at least one special character and returning an error code if not.
  bool has_special_char = false;
  for ( int i = 0; i < s_length; i++ ){
    if(isalnum(s[i]) || isalpha(s[i])) continue;
    
    else if (  s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!' ){
      
        has_special_char = true;
        break;

            }else {
                return i;
            }
    
  }
  if ( !has_special_char )   { return -5; }
  
  
  // Valid password
    return -10;
    
    
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    // return  first index of true password 
    // true password = Most repeated + the longest of the most repeated sequences
    // Testcase : MAX password <= 30 in arr_pwds

    int* count_pwds = new int[num_pwds]() ;
    
    for(int i = 0; i < num_pwds; i++ ){
        for (int j = 0; j < num_pwds; j++){
            if (strcmp(*(arr_pwds+i), *(arr_pwds+j)) == 0) {
            count_pwds[i]++;
      }
        }
    }

    int max_count = 0;
    int max_idx = -1;
    
    for (int i = 0; i < num_pwds; i++) {
        if (count_pwds[i] > max_count) {
            max_count = count_pwds[i];
            max_idx = i;
        }
    }

    for (int i = 0; i < num_pwds; i++) {
    if (count_pwds[i] == max_count && strlen(arr_pwds[i]) > strlen(arr_pwds[max_idx])){
            max_idx = i;
        }
    }

    delete[] count_pwds;
    return max_idx;

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////