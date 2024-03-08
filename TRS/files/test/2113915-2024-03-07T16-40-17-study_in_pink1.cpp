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
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
  if ((E1 < 0 ) || (E1 > 99)) return -99;
    //////////////////////////////////////////////////
    ////WATSON JUST CAME BACK FROM AFGHANISTAN OR IRAQ?
    //////////////////////////////////////////////////
    //CHECK EXP1
		if (EXP1 > 600) EXP1 = 600;
      else if (EXP1 < 0) EXP1 = 0;
    //CHECK EXP2
		if (EXP2 > 600) EXP2 = 600;
      else if (EXP2 < 0) EXP2 = 0;
    if ((E1 >= 0) && (E1 <= 3)){
    //UPDATE WATSON EXP
    if (E1 == 0) EXP2 += 29;
		  else if (E1 == 1) EXP2 += 45;
		  else if (E1 == 2) EXP2 += 75;
		  else if (E1 == 3) EXP2 += 149;
    EXP2 = ceil(EXP2);
    //CHECK EXP2
		if (EXP2 > 600) EXP2 = 600;
      else if (EXP2 < 0) EXP2 = 0;
    //EXTRA EXP
    int D;
    D=E1*3+EXP1*7;
    //UPDATE SHERLOCK EXP
    if ((D%2 ) == 0) {
    	EXP1 = EXP1 + 1.0*(D/200.0)+0.999;
		}
		 else if ((D%2) == 1){
			 EXP1 = EXP1 - 1.0*(D/100.0)+0.999;
		}
    //CHECK EXP1
		if (EXP1 > 600) EXP1 = 600;
      else if (EXP1 < 0) EXP1 = 0;}
        
	//////////////////////////////////////
	//DOES WATSON HAVE A BROTHER?
	/////////////////////////////////////
	else if ((E1 >= 4) && (E1 <= 99)){
    //EXTRA EXP
	  double D1 = E1/4.0 + 19.0, D2= E1/9.0 + 21.0, D3 = E1/16.0 + 17.0;
    //UPDATE WATSON EXP;
	  if ((E1 >= 4) && (E1 <= 19)) EXP2 = EXP2 + 1.0*D1+0.999;
		 else if ((E1 >= 20) && (E1 <= 49)) EXP2 = EXP2 + 1.0*D2+0.999;
		 else if ((E1 >= 50) && (E1 <= 65)) EXP2 = EXP2 + 1.0*D3+0.999;
		 else if ((E1 >= 66) && (E1 <= 79)){
		 	      EXP2 = EXP2 + 1.0*D1+0.999;
		 	      if (EXP2 > 200){
		 	      	  EXP2 = EXP2 + 1.0*D2+0.999;
				   }
		 }
		 else if ((E1 >= 80) && (E1 <= 99)){
		 	      EXP2 = EXP2 + 1.0*D1+0.999;
		 	      EXP2 = EXP2 + 1.0*D2+0.999;
		 	      if (EXP2 > 400){
		 	      	  EXP2 = EXP2 + 1.0*D3+0.999;}
		 	      	  EXP2 = EXP2*1.15+0.999;
				   
		 }
		//CHECK EXP2
		 if (EXP2 > 600) EXP2 = 600;
         else if (EXP2 < 0) EXP2 = 0;
    //UPDATE SHERLOCK EXP
		 EXP1 = ceil(EXP1 - 1.0*E1);
		 //CHECK EXP1
		 if (EXP1 > 600) EXP1 = 600;
         else if (EXP1 < 0) EXP1 = 0;
    }
    return EXP1 + EXP2;
}
//NEAREST SQUARE LOOP FUNCTION
int nearest_square_loop(int n) {
  int lower_bound = 1;
  int upper_bound = 1;
  while (upper_bound * upper_bound <= n) {
    lower_bound = upper_bound;
    upper_bound++;
  }
  return (n - lower_bound * lower_bound < upper_bound * upper_bound - n) ? 
  lower_bound * lower_bound : upper_bound * upper_bound;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
 if ((E2 < 0 ) || (E2 > 99)) return -99;
  //CHECK EXP1
	if (EXP1 > 600) EXP1 = 600;
      else if (EXP1 < 0) EXP1 = 0;
  //CHECK HP1
      if (HP1 > 666) HP1 = 666;
      else if (HP1 < 0) HP1 = 0;
  //CHECK M1
	    if (M1 > 3000) M1 = 3000;
      else if (M1 < 0) M1 = 0; 
    ////ROAD 1!
    int S=nearest_square_loop(EXP1);
    double P1;
    if (EXP1>=S) P1=1.0;
    else P1=(EXP1*1.0/S+80.0)/123.0;
    ////ROAD 2!
    int temp=0.5*M1;
    int paid=0;
    if((E2%2)==1){
     while(true){    
      ////EVENT1
      if (HP1<200) {
        HP1=1.3*HP1+0.999;
        M1-=150;
        paid+=150;}
      else {
        HP1=1.1*HP1;+0.999
        M1-=70; 
        paid+=70;}
       //CHECK HP1
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
      //CHECK M1
	      if (M1 > 3000) M1 = 3000;
        else if (M1 < 0) M1 = 0;
     if(paid>temp)   {break;}
     /////EVENT 2    
      if (EXP1<400) {
        M1-=200;
       EXP1=1.13*EXP1+0.999;
       paid+=200;}
      else {
        M1-=120;
       EXP1=1.13*EXP1+0.999;
       paid+=120;}
      //CHECK M1
	    if (M1 > 3000) M1 = 3000;
        else if (M1 < 0) M1 = 0;
      //CHECK EXP1
		  if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
      if(paid>temp)   {break;}
     /////EVENT 3    
      if (EXP1<300) {
        M1-=100;
       EXP1=0.9*EXP1+0.999;
       paid+=100;}
      else {
        M1-=120;
        EXP1=0.9*EXP1+0.999;
        paid+=120;}
       //CHECK M1
	    if (M1 > 3000) M1 = 3000;
        else if (M1 < 0) M1 = 0;
      //CHECK EXP1
		  if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
      if(paid>temp)   {break;}
    }}  
    else if((E2%2)==0){
    while(true){    
    ////EVENT1
    if (HP1<200) {
      HP1=1.3*HP1+0.999;
      M1-=150;}
    else {
      HP1=1.1*HP1+0.999;
      M1-=70;}
    //CHECK HP1
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
    //CHECK M1
	      if (M1 > 3000) M1 = 3000;
        else if (M1 < 0) M1 = 0;
     if(M1==0)   {break;}
    /////EVENT 2    
    if (EXP1<400) {
      M1-=200;
      EXP1=1.13*EXP1+0.999;}
    else {
      M1-=120;
     EXP1=1.13*EXP1+0.999;}
    //CHECK M1
	    if (M1 > 3000) M1 = 3000;
        else if (M1 < 0) M1 = 0;
    //CHECK EXP1
		if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
    if(M1==0)   {break;}
    /////EVENT 3    
    if (EXP1<300) {
      M1-=100;
    EXP1=0.9*EXP1+0.999;}
    else {
      M1-=120;
     EXP1=0.9*EXP1+0.999;}
    //CHECK M1
	  if (M1 > 3000) M1 = 3000;
        else if (M1 < 0) M1 = 0;
    //CHECK EXP1
		if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
    break;
    }}
    EXP1=1.17*EXP1+0.999;
    HP1=0.83*HP1+0.999;
    //CHECK EXP1
		   if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
    //CHECK HP1
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
    int S2=nearest_square_loop(EXP1);
    double P2;
    if (EXP1>=S2) P2=1.0;
    else P2=(EXP1/S2+80.0)/123.0;
    ////ROAD 3!
   int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = (E2 >= 10 && E2 <= 99) ? ((E2 / 10) + (E2 % 10)) % 10 : E2;
    double P3 = P[i] / 100.0;
    /////////////////////////////
    if (P1==P2==P3==1.0){
      EXP1=0.75*EXP1+0.999;  
    }
    else{double P=(P1+P2+P3)/3.0;
    if(P<0.5){
      EXP1=1.15*EXP1+0.999; 
      HP1=0.85*HP1+0.999;   
    }
    else{EXP1=1.2*EXP1+0.999; 
      HP1=0.9*HP1+0.999;}}
      //CHECK EXP1
		if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
    //CHECK HP1
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ((E3 < 0 ) || (E3 > 99)) return -99;
    //CHECK EXP1
		if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
    //CHECK EXP2
		if (EXP2 > 600) EXP2 = 600;
        else if (EXP2 < 0) EXP2 = 0;    
    //CHECK HP1
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
    //CHECK HP2
        if (HP2 > 666) HP2 = 666;
        else if (HP2 < 0) HP2 = 0;
    int matrix[10][10];

  ///INITIALIZE ARRAY 0
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      matrix[i][j] = 0;
    }
  }

  ///ASSIGN VALUE
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
    }}
  // COUNT ELEMENTS >E3*2
  int count = 0;
   for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if(matrix[i][j] > E3*2){
        count++;
      }
    }
  }
  if (count >= 10 && count <= 99){
    while (count >= 10) {
       int sum = 0;
        while (count != 0) {
            sum += count % 10;
            count /= 10;
        }
        count = sum;
    }
  }
    //// COUNT ELEMENTS < -E3
  int count2 = 0;
   for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if(matrix[i][j] < -E3){
        count2++;
      }
    }
  }
  if (count2 >= 10 && count2 <= 99){
    while (count2 >= 10) {
       int sum = 0;
        while (count2 != 0) {
            sum += count2 % 10;
            count2 /= 10;
        }
        count2 = sum;
    }
  }
  ///MEETING POSITION AND POINTS
  int taxiPoint=matrix[count][count2];
  //MAX LEFT DIAGONAL
      int max_left_diagonal1 = INT_MIN;
      for (int k = 0; k <= count && k <= count2; k++) {
        max_left_diagonal1 = max(max_left_diagonal1, matrix[count - k][count2 - k]);
      }
      int max_left_diagonal2 = INT_MIN;
      for (int k = 0; k <= 9-count && k <= 9 - count2; k++) {
        max_left_diagonal2 = max(max_left_diagonal2, matrix[count + k][count2 + k]);
      }
      int max_left_diagonal=max(max_left_diagonal1, max_left_diagonal2);
    //MAX RIGHT DIAGONAL
      int max_right_diagonal1 = INT_MIN;
      for (int k = 0; k <= 9-count && k <= count2; k++) {
        max_right_diagonal1 = max(max_right_diagonal1, matrix[count + k][count2 - k]);
      }
      int max_right_diagonal2 = INT_MIN;
      for (int k = 0; k <= count && k <= 9 - count2; k++) {
        max_right_diagonal2 = max(max_right_diagonal2, matrix[count - k][count2 + k]);
      }
      int max_right_diagonal=max(max_right_diagonal1, max_right_diagonal2);
    //SHERLOCK&WATSON POINT
    int SherlockPoint=max(max_left_diagonal2, max_right_diagonal);
    if (abs(taxiPoint)>abs(SherlockPoint)){
      EXP1=0.88*EXP1+0.999; 
      HP1=0.9*HP1+0.999;
      EXP2=0.88*EXP2+0.999; 
      HP2=0.9*HP2+0.999;
    }
    else{
      EXP1=1.12*EXP1+0.999; 
      HP1=1.1*HP1+0.999;
      EXP2=1.12*EXP2+0.999; 
      HP2=1.1*HP2+0.999;
    }
    //CHECK EXP1
		if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
    //CHECK EXP2
		if (EXP2 > 600) EXP2 = 600;
        else if (EXP2 < 0) EXP2 = 0;    
    //CHECK HP1
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
    //CHECK HP2
        if (HP2 > 666) HP2 = 666;
        else if (HP2 < 0) HP2 = 0;
     return (abs(taxiPoint)>abs(SherlockPoint)) ? taxiPoint : abs(SherlockPoint);

}
 string getUserName(const char* mail) {
  string username;
  for (int i = 0; mail[i] != '\0'; i++) {
        if (mail[i] == '@') {
            break;
        }
        username += mail[i];
  }
  return username;
 }
 int findSubstring(const char* s1, const char* s2) {
    //RETURN -1 IF NULL
    if (s1 == nullptr || s2 == nullptr) {
        return -1;
    }

    int s1Len = 0;
    int s2Len = 0;

    //S1 AND S2 LENGTH
    while (s1[s1Len] != '\0') {
        ++s1Len;
    }
    while (s2[s2Len] != '\0') {
        ++s2Len;
    }

    //BROWSE THROUGH S1
    for (int i = 0; i <= s1Len - s2Len; ++i) {
        //CHECK SIMILARITY
        int j;
        for (j = 0; j < s2Len; ++j) {
            if (s1[i + j] != s2[j]) {
                break;
            }
        }

        // IF SIMILAR, RETURN INDEX
        if (j == s2Len) {
            return i;
        }
    }

    // CANT BE FOUND RETURN -1
    return -1;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // GET USERNAME
  string se=getUserName(email);
  // CHECK PASSWORD LENGTH
  int len = strlen(s);
  if (len < 8) return -1;
  if (len > 20) return -2;
  // CHECK SPECIAL CHARACTERS
  bool hasSpecialChar = false;
  for (int i = 0; i < len; i++) {
    if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
      hasSpecialChar = true;
      break;
    }
  }
  if (!hasSpecialChar) return -5;
  // CHECK SE IN PASSWORD
if (findSubstring(s, se.c_str()) != -1) {
    return -(300 + ( findSubstring(s, se.c_str())));
  }
  // CHECK CONSECUTIVE AND IDENTICAL CHARACTERS
  for (int i = 0; i < len - 2; i++) {
    if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) return -(400 + i);
  }
  // CHECK VALID CHARACTER
  for (int i = 0; i < len; i++) {
  if (!isalnum(s[i])&&!((s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))) return i;
  }

  // VALID PASSWORD
  return -10;

}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
int max_count = 0;
    int max_length = 0;
    int result_index = -1;

    //BROWSE THROUGH PASSWORD ARRAY
    for (int i = 0; i < num_pwds; ++i) {
        const char* current_password = arr_pwds[i];
        int current_length = strlen(current_password);
        int current_count = 0;

        //COUNT THE NUMBER OF OCCURRENCES OF THE CURRENT PASSWORD
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(current_password, arr_pwds[j]) == 0) {
                current_count++;
            }
        }

        //COMPARE LONGEST AND MAX COUNT PASSWORD
        if (current_count > max_count || (current_count == max_count && current_length > max_length)) {
            max_count = current_count;
            max_length = current_length;
            result_index = i;
        }
    }

    return result_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////