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


    if ( exp1 < 0 ){
         exp1 = 0;
} 
    if ( exp2 <0 ){
         exp2 = 0;
}
    if ( exp1 > 600 ){
         exp1 = 600;
}
    if ( exp2 > 600 ){
         exp2 = 600;
}
    if( e1 < 0 || e1 > 99 ){
    return -99;
}


switch ( e1 ) {
case 0: exp2 = exp2 + 29; break;

case 1: exp2 = exp2 + 45; break;

case 2: exp2 = exp2 + 75; break;

case 3: exp2 = exp2 + 29 + 45 + 75; break;
}

int D;
D = e1 * 3 + exp1 * 7;

    if( e1 >= 0 && e1 <= 3 ){
    if( D % 2 == 0 ){
    exp1 = (exp1 + D * 1.0 / 200) + 0.999;
}
    else
    exp1 = (exp1 - D * 1.0 / 100) + 0.999;
}
    if( e1 >= 4 && e1 <= 19 ){
    exp2 = (exp2 + ((e1*1.0/4)+19)) + 0.999;
    exp1 = (exp1 - e1) + 0.999;
}
    else if( e1 <= 49 && e1 >= 20 ){
    exp2 = (exp2 + ((e1*1.0/9)+21)) + 0.999;
    exp1 = (exp1 - e1)+ 0.999;
}
    else if( e1 >= 50 && e1 <= 65 ){
    exp2 = (exp2 + ((e1*1.0/16)+17)) + 0.999;
    exp1 = (exp1 - e1) + 0.999;
}
    else if( e1 >= 66 && e1 <= 79 ){
    exp2 = (exp2 + ((e1*1.0/4)+19)) + 0.999;
    
    if(exp2 > 200 ){
    exp2 = (exp2 + ((e1*1.0/9)+21)) + 0.999;
}
    exp1 = (exp1 - e1) + 0.999;
}
    else if( e1 >= 80 && e1 <= 99){
    exp2 = (exp2 + ((e1*1.0/4)+19))+ 0.999;
    exp2 = (exp2 + ((e1*1.0/9)+21))+ 0.999;
    
    if( exp2 > 400 ){
    exp2 = (exp2 + ((e1*1.0/16)+17)) + 0.999;
    
    exp2 = (exp2 + 0.15 * exp2) + 0.999;
    
}
    
    exp1 = (exp1 - e1) + 0.999;
}
if ( exp1 < 0 ){
    exp1 = 0;
}
if ( exp2 < 0 ){
    exp2 = 0;
}
if ( exp1 > 600 ){
    exp1 = 600;
}
if( exp2 > 600 ){
    exp2 = 600;
}

//exp1 = exp1 ;
//exp2 = exp2 ;



return exp1 + exp2;
}
    
    
    
    


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 > 99 || E2 < 0){
       return -99;
    }
    double S1;
    double S2;
    double S3;
    double P1;     
    double P2;
    double P3;
    double Pi[10] = {0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11};
    double P;
    float tienchi;
    float nuatien;
    double SqrtExp11 = (sqrt(EXP1));
    int Low1 = floor(SqrtExp11) * floor(SqrtExp11);
    int High1 = ceil(SqrtExp11) * ceil(SqrtExp11);
    
    if (EXP1 > 600){
        EXP1 = 600;
    }
    else if(EXP1 < 0){
        EXP1 = 0;
    }

    if (HP1 > 666){
        HP1 = 666;
    }
    else if(HP1 < 0){
        HP1 = 0;
    }

    if (M1 > 3000){
        M1 = 3000;
    }
    else if(M1 < 0){
        M1 = 0;
    }
    
    nuatien = M1/2;

    // Duong 1
    if(abs(EXP1 - Low1) < abs(EXP1 - High1)){
      S1 = Low1;
    }
    else{
      S1 = High1;
    }

    if(EXP1 >= S1){
      P1 = 1;
    }
    else{
      P1 = (((EXP1/S1) + 80)/123);
    }

    // Duong 2
    
    
    if(E2 % 2 == 0){ // Chan
        
       if(HP1 < 200 && M1 > 0){ //Mua nuoc
        HP1 = (HP1 + 0.3*HP1) + 0.999;
        M1 = (M1 - 150) + 0.999;
       }
       else if(HP1 >= 200 && M1>0){
        HP1 = (HP1 + 0.1*HP1) + 0.999;
        M1 = (M1 - 70) + 0.999;
       }
        if (EXP1 > 600){
        EXP1 = 600;
    }
    else if(EXP1 < 0){
        EXP1 = 0;
    }

    if (HP1 > 666){
        HP1 = 666;
    }
    else if(HP1 < 0){
        HP1 = 0;
    }

    if (M1 > 3000){
        M1 = 3000;
    }
    else if(M1 < 0){
        M1 = 0;
    }
       
       if(EXP1 < 400 && M1 > 0){ //Di xe
        M1 = (M1 - 200) + 0.999;
        EXP1 = (EXP1 + 0.13*EXP1) + 0.999;
       }
       else if(EXP1 >= 400 && M1 > 0){
        M1 = (M1 - 120) + 0.999;
        EXP1 = (EXP1 + 0.13*EXP1) + 0.999;
       }
       if (EXP1 > 600){
        EXP1 = 600;
    }
    else if(EXP1 < 0){
        EXP1 = 0;
    }

    if (HP1 > 666){
        HP1 = 666;
    }
    else if(HP1 < 0){
        HP1 = 0;
    }

    if (M1 > 3000){
        M1 = 3000;
    }
    else if(M1 < 0){
        M1 = 0;
    }
       

       if(EXP1 < 300 && M1 >0){
            M1 = (M1 - 100) + 0.999;
            EXP1 = (EXP1 - 0.1*EXP1) + 0.999;
       }
       else if(EXP1 >= 300 && M1 > 0){
            M1 = (M1 - 120) + 0.999;
            EXP1 = (EXP1 - 0.1*EXP1) + 0.999;
       }
       if (EXP1 > 600){
        EXP1 = 600;
    }
    else if(EXP1 < 0){
        EXP1 = 0;
    }

    if (HP1 > 666){
        HP1 = 666;
    }
    else if(HP1 < 0){
        HP1 = 0;
    }

    if (M1 > 3000){
        M1 = 3000;
    }
    else if(M1 < 0){
        M1 = 0;
    }
       EXP1 = (EXP1 + 0.17*EXP1) + 0.999;
       HP1 = (HP1 - 0.17*HP1) + 0.999;
    if (EXP1 > 600){
        EXP1 = 600;
    }
    else if(EXP1 < 0){
        EXP1 = 0;
    }

    if (HP1 > 666){
        HP1 = 666;
    }
    else if(HP1 < 0){
        HP1 = 0;
    }

    if (M1 > 3000){
        M1 = 3000;
    }
    else if(M1 < 0){
        M1 = 0;
    }
       EXP1 = EXP1 + 0.999;
       HP1 = HP1 + 0.999;
       M1 = M1 + 0.999;
    }
    else{ // Le
        tienchi = 0;
        while(tienchi <= nuatien){
            if(HP1 < 200){
                HP1 = (HP1 + 0.3*HP1) + 0.999;
                M1 = (M1 - 150) + 0.999;
                tienchi = tienchi + 150;
            }
            else{
                HP1 = (HP1 + 0.1*HP1) + 0.999;
                M1 = (M1 - 70) + 0.999;
                tienchi = tienchi + 70;
            }
            if (EXP1 > 600){
        EXP1 = 600;
    }
    else if(EXP1 < 0){
        EXP1 = 0;
    }

    if (HP1 > 666){
        HP1 = 666;
    }
    else if(HP1 < 0){
        HP1 = 0;
    }

    if (M1 > 3000){
        M1 = 3000;
    }
    else if(M1 < 0){
        M1 = 0;
    }
            if(tienchi > nuatien){
                break;
            }
            if(EXP1 < 400){
                M1 = (M1 - 200) + 0.999;
                EXP1 = (EXP1 + 0.13*EXP1) + 0.999;
                tienchi = tienchi + 200;
            }
            else{
                M1 = (M1 - 120) + 0.999;
                EXP1 = (EXP1 + 0.13*EXP1) + 0.999;
                tienchi = tienchi + 120;
            }
            if (EXP1 > 600){
        EXP1 = 600;
    }
    else if(EXP1 < 0){
        EXP1 = 0;
    }

    if (HP1 > 666){
        HP1 = 666;
    }
    else if(HP1 < 0){
        HP1 = 0;
    }

    if (M1 > 3000){
        M1 = 3000;
    }
    else if(M1 < 0){
        M1 = 0;
    }
            if(tienchi > nuatien){
                break;
            }
            if(EXP1 < 300){
                M1 = (M1 - 100) + 0.999;
                EXP1 = (EXP1 - 0.1*EXP1) + 0.999;
                tienchi = tienchi + 100;
            }
            else{
                M1 = (M1 - 120) + 0.999;
                EXP1 = (EXP1 - 0.1*EXP1) + 0.999;
                tienchi = tienchi + 120;
            }
            if (EXP1 > 600){
        EXP1 = 600;
    }
    else if(EXP1 < 0){
        EXP1 = 0;
    }

    if (HP1 > 666){
        HP1 = 666;
    }
    else if(HP1 < 0){
        HP1 = 0;
    }

    if (M1 > 3000){
        M1 = 3000;
    }
    else if(M1 < 0){
        M1 = 0;
    }
            if(tienchi > nuatien){
                break;
            }
        }
        EXP1 = (EXP1 + 0.17*EXP1) + 0.999;
        HP1 = (HP1 - 0.17*HP1) + 0.999;
    if (EXP1 > 600){
        EXP1 = 600;
    }
    else if(EXP1 < 0){
        EXP1 = 0;
    }

    if (HP1 > 666){
        HP1 = 666;
    }
    else if(HP1 < 0){
        HP1 = 0;
    }

    if (M1 > 3000){
        M1 = 3000;
    }
    else if(M1 < 0){
        M1 = 0;
    }
        EXP1 = EXP1 + 0.999;
        HP1 = HP1 + 0.999;
        M1 = M1 + 0.999;
    }
    
    if (EXP1 > 600){
        EXP1 = 600;
    }
    else if(EXP1 < 0){
        EXP1 = 0;
    }

    if (HP1 > 666){
        HP1 = 666;
    }
    else if(HP1 < 0){
        HP1 = 0;
    }

    if (M1 > 3000){
        M1 = 3000;
    }
    else if(M1 < 0){
        M1 = 0;
    }
    
    EXP1 = EXP1 + 0.999;
    HP1 = HP1 + 0.999;
    M1 = M1 + 0.999;

    double SqrtExp12 = (sqrt(EXP1));
    int Low2 = floor(SqrtExp12) * floor(SqrtExp12);
    int High2 = ceil(SqrtExp12) * ceil(SqrtExp12);
    if(abs(EXP1 - Low2) < abs(EXP1 - High2)){
      S2 = Low2;
    }
    else{
      S2 = High2;
    }

    if(EXP1 >= S2){
      P2 = 1;
    }
    else{
      P2 = (((EXP1*1.0/S2) + 80)/123);
    }
    
    // Duong 3
    int i;
    if (E2 >= 0 && E2 < 10){
      i = E2;
      P3 = Pi[i];
    }
    else{
      int sum = E2 / 10 + E2 % 10;
      i = sum % 10;
      P3 = Pi[i];
    }
    
    

    if(P1 == 1 && P2 == 1 && P3 == 1){
      EXP1 = (EXP1*1.0 - 0.25 * EXP1*1.0) + 0.999;
      EXP1 = EXP1 + 0.999;
    }
    
    P = (P1 + P2 + P3) / 3;

      if(P < 0.5){
        HP1 = (HP1*1.0 - 0.15*HP1*1.0) + 0.999;
        EXP1 = (EXP1*1.0 + 0.15*EXP1*1.0) + 0.999;
        if (EXP1 > 600){
        EXP1 = 600;
    }
    else if(EXP1 < 0){
        EXP1 = 0;
    }

    if (HP1 > 666){
        HP1 = 666;
    }
    else if(HP1 < 0){
        HP1 = 0;
    }

    if (M1 > 3000){
        M1 = 3000;
    }
    else if(M1 < 0){
        M1 = 0;
    }
        HP1 = HP1 + 0.999;
        EXP1 = EXP1 + 0.999;
      }
      else if(P >= 0.5 && P < 1){
        HP1 = (HP1*1.0 - 0.1*HP1*1.0) + 0.999;
        EXP1 = (EXP1*1.0 + 0.2*EXP1*1.0) + 0.999;
        if (EXP1 > 600){
        EXP1 = 600;
    }
    else if(EXP1 < 0){
        EXP1 = 0;
    }

    if (HP1 > 666){
        HP1 = 666;
    }
    else if(HP1 < 0){
        HP1 = 0;
    }

    if (M1 > 3000){
        M1 = 3000;
    }
    else if(M1 < 0){
        M1 = 0;
    }
        HP1 = HP1 + 0.999;
        EXP1 = EXP1 + 0.999;

      }
    if (EXP1 > 600){
        EXP1 = 600;
    }
    else if(EXP1 < 0){
        EXP1 = 0;
    }

    if (HP1 > 666){
        HP1 = 666;
    }
    else if(HP1 < 0){
        HP1 = 0;
    }

    if (M1 > 3000){
        M1 = 3000;
    }
    else if(M1 < 0){
        M1 = 0;
    }
    
    HP1 = HP1 + 0.999;
    EXP1 = EXP1 + 0.999;
    M1 = M1 + 0.999;
     

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 > 99 || E3 < 0){
       return -99;
    }
    if (EXP1 > 600){
        EXP1 = 600;
    }
    else if(EXP1 < 0){
        EXP1 = 0;
    }

    if (HP1 > 666){
        HP1 = 666;
    }
    else if(HP1 < 0){
        HP1 = 0;
    }
    if (EXP2 > 600){
        EXP2 = 600;
    }
    else if(EXP2 < 0){
        EXP2 = 0;
    }

    if (HP2 > 666){
        HP2 = 666;
    }
    else if(HP2 < 0){
        HP2 = 0;
    }

    int a[10][10];

    for ( int i = 0; i < 10; i++){
    for ( int j = 0; j < 10; j++){
       a[i][j] = 0;
    }
    }   

    int i = 0, j = 0;
    while (i < 10 && j < 10) {
    a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
    if (j < 9) {
      j++;
    } else {
      i++;
      j = 0;
    }
  }
     
   
   int i_gap, j_gap;
  int lon = 0;
  int nho = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (a[i][j] > E3*2) {
        lon++;
        i_gap = lon;
      }

      if (a[i][j] < -E3) {
        nho++;
        j_gap = nho;
      }
    }
  }
    
    
    while (i_gap >= 10) {
    int sum = 0;
    while (i_gap > 0) {
      sum += i_gap % 10;
      i_gap /= 10;
    }
    i_gap = sum;
  }

  while (j_gap >= 10) {
    int sum = 0;
    while (j_gap > 0) {
      sum += j_gap % 10;
      j_gap /= 10;
    }
    j_gap = sum;
  }

    int i_gapnhau = i_gap;
    int j_gapnhau = j_gap;
    
    int DiemTaxi;
    int DiemSW;

    DiemTaxi = (a[i_gapnhau][j_gapnhau]);

    int maxLeft = a[i_gapnhau][j_gapnhau];
    for (int i = i_gapnhau + 1, j = j_gapnhau - 1; i < 10 && j >= 0; i++, j--) {
    maxLeft = max(maxLeft, a[i][j]);
    }
    
    int maxRight = a[i_gapnhau][j_gapnhau];
    for (int i = i_gapnhau - 1, j = j_gapnhau+ 1; i >= 0 && j < 10; i--, j++) {
    maxRight = max(maxRight, a[i][j]);
    }
    

    DiemSW = (max(maxLeft, maxRight));
    

    
    if(DiemSW >= abs(DiemTaxi)){
      HP1 = (HP1 + 0.1*HP1*1.0) + 0.999;
      HP2 = (HP2 + 0.1*HP2*1.0) + 0.999;
      EXP1 = (EXP1 + 0.12*EXP1*1.0) + 0.999;
      EXP2 = (EXP2 + 0.12*EXP2*1.0) + 0.999;
      if (EXP1 > 600){
        EXP1 = 600;
    }
    else if(EXP1 < 0){
        EXP1 = 0;
    }

    if (HP1 > 666){
        HP1 = 666;
    }
    else if(HP1 < 0){
        HP1 = 0;
    }
    if (EXP2 > 600){
        EXP2 = 600;
    }
    else if(EXP2 < 0){
        EXP2 = 0;
    }

    if (HP2 > 666){
        HP2 = 666;
    }
    else if(HP2 < 0){
        HP2 = 0;
    }
      HP1 = HP1 + 0.999;
      HP2 = HP2 + 0.999;
      EXP1 = EXP1 + 0.999;
      EXP2 = EXP2 + 0.999;
    }
    else{
      HP1 = (HP1 - 0.1*HP1*1.0) + 0.999;
      HP2 = (HP2 - 0.1*HP2*1.0) + 0.999;
      EXP1 = (EXP1 - 0.12*EXP1*1.0) + 0.999;
      EXP2 = (EXP2 - 0.12*EXP2*1.0) + 0.999;
      if (EXP1 > 600){
        EXP1 = 600;
    }
    else if(EXP1 < 0){
        EXP1 = 0;
    }

    if (HP1 > 666){
        HP1 = 666;
    }
    else if(HP1 < 0){
        HP1 = 0;
    }
    if (EXP2 > 600){
        EXP2 = 600;
    }
    else if(EXP2 < 0){
        EXP2 = 0;
    }

    if (HP2 > 666){
        HP2 = 666;
    }
    else if(HP2 < 0){
        HP2 = 0;
    }
      HP1 = HP1 + 0.999;
      HP2 = HP2 + 0.999;
      EXP1 = EXP1 + 0.999;
      EXP2 = EXP2 + 0.999;
    }

    if (EXP1 > 600){
        EXP1 = 600;
    }
    else if(EXP1 < 0){
        EXP1 = 0;
    }

    if (HP1 > 666){
        HP1 = 666;
    }
    else if(HP1 < 0){
        HP1 = 0;
    }
    if (EXP2 > 600){
        EXP2 = 600;
    }
    else if(EXP2 < 0){
        EXP2 = 0;
    }

    if (HP2 > 666){
        HP2 = 666;
    }
    else if(HP2 < 0){
        HP2 = 0;
    }
      HP1 = HP1 + 0.999;
      HP2 = HP2 + 0.999;
      EXP1 = EXP1 + 0.999;
      EXP2 = EXP2 + 0.999;

    
    
    int diemlonhon;
    if(DiemTaxi < DiemSW && abs(DiemTaxi) < DiemSW){
      diemlonhon = DiemSW;
    }
    else if(DiemTaxi < DiemSW && abs(DiemTaxi) > DiemSW){
      diemlonhon = DiemTaxi;
    }
    else if(DiemTaxi > DiemSW && abs(DiemTaxi) > DiemSW){
      diemlonhon = DiemTaxi;
    }
    else if(DiemSW == DiemTaxi){
      diemlonhon = DiemSW;
    }
    else if(DiemTaxi < DiemSW && abs(DiemTaxi) == DiemSW){
      diemlonhon = DiemSW;
    }
    
    

    return diemlonhon;
    
}

// Task 4
int checkPassword(const char * s, const char * email) {

    string mail(email);
    int pos = mail.find('@');
    string se;
    for(int i = 0; i < pos; ++i){
        se += mail[i];
    }

    if(strlen(s) < 8){
       return -1;
    } 
    if(strlen(s) > 20){
       return -2;
    }

    if(strstr(s, se.c_str()) != nullptr){
        const char* timthay = strstr(s, se.c_str());
        int vitri1st = timthay - s;
        return -(300 + vitri1st);
    }

    char pre = '\0';
    int kitulientiep = 1;
    for(int i = 0; s[i] != '\0'; i++){
        char c = s[i];
    if(c == pre){
        kitulientiep++;
    if(kitulientiep > 2){
        return -(400 + i - 2);
    } 
    } 
    else{
        pre = c;
        kitulientiep = 1;
    }
    }

    if(strpbrk(s, "@#$%!") == nullptr){
      return -5;
    }
    
    for(int i = 0; s[i] != '\0'; i++){
        char c = s[i];
        if(!isalnum(c) && !strchr("@#$%!", c)) 
        return i; 
    }

    return -10; 
}


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    int PosPass = -1;
    int MosApp = 0;
    int MaxLen = 0;

    for(int i = 0; i < num_pwds; ++i){
        int app = 0;
        int length = strlen(arr_pwds[i]); 

    for(int j = 0; j < num_pwds; ++j){
    if(std::string(arr_pwds[i]) == std::string(arr_pwds[j])){
        app++;
    }
    }

    if(app > MosApp || (app == MosApp && length > MaxLen)){
            PosPass = i;
            MosApp = app;
            MaxLen = length;
    }
    }

    return PosPass;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////