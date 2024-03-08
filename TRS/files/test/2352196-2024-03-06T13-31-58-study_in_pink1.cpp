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
                         if (exp1 < 0) {exp1 = 0;}else if (exp1 > 600) {exp1 = 600;}
                         if (exp2 < 0) {exp2 = 0;}else if (exp2 > 600) {exp2 = 600;}
                         if (e1 < 0)    {e1 = 0;} else if (e1 > 99) {e1 = 99;}
 if ( e1 >= 0 && e1 <=3){
    	switch(e1) {
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
    		exp2+=29+45+75;
    		break;
      default:
    		return -1; 
	}
	int D = e1 * 3 + exp1 * 7; double exp11,d;  exp11=exp1*1.00;  d=D*1.00;
    if (D%2==0){     exp11=exp11 + d/200;     }
    else {           exp11=exp11 - d/100;     }
    double z= fmod(exp11, 1.00);
       if (z==0.00){exp1=exp11-z;}else{exp1=exp11-z+1;}
  }else if( e1 >= 4 && e1 <=99){  double exp21,e1f;  exp21=exp2*1.00; e1f=e1*1.00;
        if(e1 >= 4 && e1 <=19){          exp21 += e1f/4 +19;     }
        else if(e1 >= 20 && e1 <=49){    exp21 += e1f/9 +21;     }
        else if(e1 >= 50 && e1 <=65){    exp21 += e1f/16 +17;    }
        else if(e1 >= 66 && e1 <=79){    exp21 += e1f/4 +19;
             if (exp21>200.00){          exp21 += e1f/9 +21;    }}
        else if(e1 >= 80 && e1 <=99){    exp21 += e1f/4 +19;      exp21 += e1f/9 +21;
             if (exp21>400.00){          exp21 += (e1f/16 +17);   exp21= exp21 + 0.5*exp21;   }
        }
       double z= fmod(exp21, 1.00);
       if (z==0.00){exp2=exp21-z;}else{exp2=exp21-z+1;}
       exp1= exp1-e1;
    }else {       return -1;       }

    if (exp1 < 0) {exp1 = 0;}else if (exp1 > 600) {exp1 = 600;}
    if (exp2 < 0) {exp2 = 0;}else if (exp2 > 600) {exp2 = 600;}
    if (e1 < 0)    {e1 = 0;} else if (e1 > 99) {e1 = 99;}
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
    /*đoạn road 01*/
      double P1,P2,P3;
      int S1,S2,S,H,K=0;       H=ceil(M1*0.5);  
  int root = sqrt(EXP1); 
  int low = root * root;  int up = (root + 1) * (root + 1); 
                      if (E3 < 0) {E3 = 0;}      else if (E3 > 99) {E3 = 99;}    
                      if (HP1 < 0) {HP1 = 0;}  else if (HP1 > 666){HP1 = 666;}
                      if (EXP1 < 0) {EXP1 = 0;}else if (EXP1 > 600) {EXP1 = 600;}   
  if (EXP1 - low < up - EXP1) { S= low; } else { S= up; }
      if (EXP1 >= S) {   P1 = 1.0; }
           else { P1 = (EXP1/S + 80.0) / 123.0; }

    /*đoạn road 02*/
    double z, HP1F, EXP1F;
    if(E3 % 2 ==0){        HP1F=HP1*1.00; EXP1F=EXP1*1.00;
      /*Nhánh EVENT 1*/if (HP1<200){    HP1F=HP1F*1.3; M1=M1-150;   }else{  HP1F=HP1F*1.1; M1=M1-70;}

                                 z= fmod(HP1F, 1.00); 
                                if (z==0.00){HP1=HP1F-z;}else{HP1=HP1F-z+1;}
                                if (M1 < 0) {M1 = 0;}    else if (M1 > 3000) {M1 = 3000;}

                            HP1F=HP1*1.00; EXP1F=EXP1*1.00;
      /*Nhánh EVENT 2*/if (EXP1<400){   M1=M1-200;}else{M1=M1-120;}   EXP1F=EXP1F*1.13;

                                 z= fmod(EXP1F, 1.00); 
                                if (z==0.00){EXP1=EXP1F-z;}else{EXP1=EXP1F-z+1;}
                                if (M1 < 0) {M1 = 0;}    else if (M1 > 3000) {M1 = 3000;}
                                
                            HP1F=HP1*1.00; EXP1F=EXP1*1.00;
      /*Nhánh EVENT 3*/if (EXP1<300){   M1=M1-100;}else{M1=M1-120;}   EXP1F=EXP1F*0.9;

                                 z= fmod(EXP1F, 1.00); 
                                if (z==0.00){EXP1=EXP1F-z;}else{EXP1=EXP1F-z+1;}
                                if (M1 < 0) {M1 = 0;}    else if (M1 > 3000) {M1 = 3000;}
      
     
    }else{ do {             HP1F=HP1*1.00; EXP1F=EXP1*1.00;
        /*Nhánh EVENT 1*/if (HP1<200){    HP1F=HP1F*1.3; M1=M1-150; K=K+150;   }else{  HP1F=HP1F*1.1; M1=M1-70; K=K+70;}

                                z= fmod(HP1F, 1.00); 
                                if (z==0.00){HP1=HP1F-z;}else{HP1=HP1F-z+1;}
                                if (M1 < 0) {M1 = 0;}    else if (M1 > 3000) {M1 = 3000;}
                                if (K > H){break;}
                                
                            HP1F=HP1*1.00; EXP1F=EXP1*1.00;                
       /*Nhánh EVENT 2*/if (EXP1<400){   M1=M1-200; K=K+200;}else{ M1=M1-120; K=K+120;}   EXP1F=EXP1F*1.13;

                                 z= fmod(EXP1F, 1.00); 
                                if (z==0.00){EXP1=EXP1F-z;}else{EXP1=EXP1F-z+1;}
                                if (M1 < 0) {M1 = 0;}    else if (M1 > 3000) {M1 = 3000;}
                                if (K > H){break;}

                            HP1F=HP1*1.00; EXP1F=EXP1*1.00;
      /*Nhánh EVENT 3*/if (EXP1<300){   M1=M1-100; K=K+100;}else{M1=M1-120;K=K+120;}   EXP1F=EXP1F*0.9;

                                z= fmod(EXP1F, 1.00); 
                                if (z==0.00){EXP1=EXP1F-z;}else{EXP1=EXP1F-z+1;}
                                if (M1 < 0) {M1 = 0;}    else if (M1 > 3000) {M1 = 3000;}
                                if (K > H){break;}
       } while (K<=H);
      }                     HP1F=HP1*1.00; EXP1F=EXP1*1.00;
      HP1F=HP1F*0.83;   z= fmod(HP1F, 1.00); 
         if (z==0.00){HP1=HP1F-z;}else{HP1=HP1F-z+1;}
      EXP1F=EXP1F*1.17; z= fmod(EXP1F, 1.00); 
         if (z==0.00){EXP1=EXP1F-z;}else{EXP1=EXP1F-z+1;}

   root = sqrt(EXP1); 
   low = root * root;   up = (root + 1) * (root + 1); 
      if (EXP1 - low < up - EXP1) { S= low; } else { S= up; }
        if (EXP1 > S) {   P2 = 1.0; }
             else { P2 = (EXP1/S + 80.0) / 123.0; }

    /*đoạn road 3*/
    int i, array[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E3<10){   i=E3;   } else{  int s = 0;
                                   while (E3 != 0) {  s += E3 % 10;    E3 /= 10;   }
                                   i = s % 10;
    }
    P3=(array[i])/100.00;
    double P=(P1+P2+P3)/3;    HP1F=HP1*1.00; EXP1F=EXP1*1.00;
    if (P==1){EXP1F=EXP1F*0.75;}
        else{if(P>=0.5){      HP1F=HP1F*0.9; EXP1F=EXP1F*1.2;}
        else{                 HP1F=HP1F*0.85;EXP1F=EXP1F*1.15;}}

    z= fmod(HP1F, 1.00); 
         if (z==0.00)   {HP1=HP1F-z;}                else{HP1=HP1F-z+1;}
    z= fmod(EXP1F, 1.00); 
         if (z==0.00)   {EXP1=EXP1F-z;}              else{EXP1=EXP1F-z+1;}
    if (E3 < 0) {E3 = 0;}             else if (E3 > 99) {E3 = 99;}    
    if (HP1 < 0) {HP1 = 0;}           else if (HP1 > 666){HP1 = 666;}
    if (EXP1 < 0) {EXP1 = 0;}         else if (EXP1 > 600) {EXP1 = 600;}                           
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
                   if (E3 < 0) {E3 = 0;}        else if (E3 > 99) {E3 = 99;}    
                   if (HP1 < 0) {HP1 = 0;}      else if (HP1 > 666){HP1 = 666;}
                   if (EXP1 < 0) {EXP1 = 0;}    else if (EXP1 > 600) {EXP1 = 600;}   
                   if (HP2< 0) {HP2 = 0;}       else if (HP2 > 666){HP2 = 666;}
                   if (EXP2 < 0) {EXP2 = 0;}    else if (EXP2> 600) {EXP2 = 600;}  
     int taxi[10][10],sherwat[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);}}

    int posV = 0, negV = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (taxi[i][j] > E3 * 2) {   posV++;  }
            if (taxi[i][j] < -E3) {      negV++;  }
        }}
   
    int a = 0, b = 0;
    int temp_i = posV; int temp_j = negV;
    while (temp_i >= 10) { a += temp_i % 10;     temp_i /= 10;    }    a += temp_i; 
    while (temp_j >= 10) { b += temp_j % 10;     temp_j /= 10;    }    b += temp_j; 
    if (a % 10 ==0){a= a/10;}
    if (b % 10 ==0){b= b/10;}
    int taxipoint=taxi[a][b];
    int sherWatpoint = taxi[a][b];
                   for (int k = 1; a + k < 10 && b + k < 10; ++k) {
                       if (taxi[a + k][b + k] > sherWatpoint) {   sherWatpoint = taxi[a + k][b + k];  }   }
                   for (int k = 1; a + k < 10 && b - k >= 0; ++k) {
                       if (taxi[a + k][b - k] > sherWatpoint) {   sherWatpoint = taxi[a + k][b - k];  }   }
    
  if (abs(taxipoint) > abs(sherWatpoint)) {
    EXP1 = EXP1 * 0.88;   EXP2 = EXP2 * 0.88;
    HP1 = HP1 * 0.9;      HP2 = HP2 * 0.9;
                   if (E3 < 0) {E3 = 0;}      else if (E3 > 99) {E3 = 99;}    
                   if (HP1 < 0) {HP1 = 0;}    else if (HP1 > 666){HP1 = 666;}
                   if (EXP1 < 0) {EXP1 = 0;}  else if (EXP1 > 600) {EXP1 = 600;}   
                   if (HP2< 0) {HP2 = 0;}     else if (HP2 > 666){HP2 = 666;}
                   if (EXP2 < 0) {EXP2 = 0;}  else if (EXP2> 600) {EXP2 = 600;}  
     return taxipoint;
  }
  else {
    EXP1 = EXP1 * 1.12;     EXP2 = EXP2 * 1.12;
    HP1 = HP1 * 1.1;        HP2 = HP2 * 1.1;
                   if (E3 < 0) {E3 = 0;}        else if (E3 > 99) {E3 = 99;}    
                   if (HP1 < 0) {HP1 = 0;}      else if (HP1 > 666){HP1 = 666;}
                   if (EXP1 < 0) {EXP1 = 0;}    else if (EXP1 > 600) {EXP1 = 600;}   
                   if (HP2< 0) {HP2 = 0;}       else if (HP2 > 666){HP2 = 666;}
                   if (EXP2 < 0) {EXP2 = 0;}    else if (EXP2> 600) {EXP2 = 600;}  
         return sherWatpoint;
  }
   
   
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    //Phần 1 email
    int Emaillength = strlen(email);  if (Emaillength >100){return -2;} 
    char special ='@';
              if (strchr(email,special)-email <0 || strchr(email,special)-email != strrchr(email,special)-email     )
              {return -2;}                          
    
    //Phần 2 se
    char se[102];    strncpy(se, email,strchr(email,special)-email );
    se[strchr(email,special)-email ] ='\0';
    
    //Phần 3 Slength
    int Slength; 
    Slength = strlen(s);         
                if (Slength <8){ return -1;} else if (Slength >20){return -2;} 
                if (strstr(s, email) != NULL) {}
    bool special_satis = false;   bool error = false; int errorpos = -1; 
    char amoc[5] = {'@','#','%','$','!'}; 
    int count = 0;    char prev = '\0'; 
    for (int i = 0; i < Slength; i++) {
        if (strchr(amoc, s[i])) {    special_satis = true;   }
        if (s[i] == prev) {  
            count++; 
            if (count > 2 && errorpos == -1) { 
                error = true; 
                errorpos = i - 2; 
                return -(400 + errorpos);
            } } 
            else { count = 1;   prev = s[i]; }}

     if (strstr(s, se) != NULL) {      error = true;  errorpos = strstr(s, se) - s; return -(300 + errorpos);
    }if (!special_satis) {             error = true;  errorpos = -5;                return errorpos; 
    }if (!error) {                     return -10; }
    return errorpos;  
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int countMAX = 0; int Lmax = 0; int vi_tri = -1;
    for (int i = 0; i < num_pwds; i++) {
        
        int count = 0;
        for (int j = 0; j < num_pwds; j++) {   if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)   {count++;}}

        int length = strlen(arr_pwds[i]); 
        if (count > countMAX     || (  count == countMAX    &&    length > Lmax   )) {
            countMAX = count;
            Lmax = length;
            vi_tri = i;
        }} return vi_tri;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////