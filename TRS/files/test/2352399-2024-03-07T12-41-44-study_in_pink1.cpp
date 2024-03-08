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
     int D;
    D = e1*3 + exp1*7;

    switch (e1){
        case 0: 
        exp2 +=29;
        if(D%2==0){
        exp1 = ceil(exp1+(double)D/200);
    }
    else{
        exp1 = ceil(exp1-(double)D/100);
    } 
    break;
        case 1:
        exp2 +=45;
            if(D%2==0){
        exp1 = ceil(exp1+(double)D/200);
    }
    else{
        exp1 = ceil(exp1-(double)D/100);
    } 
    break;
        case 2:
        exp2 +=75;
         if(D%2==0){
        exp1 = ceil(exp1+(double)D/200);
    }
    else{
        exp1 = ceil(exp1-(double)D/100);
    } 
    break;
        case 3:
        exp2=exp2+29+45+75;
        if(D%2==0){
        exp1 = ceil(exp1+(double)D/200);
    }
    else{
        exp1 = ceil(exp1-(double)D/100);
    } 
    break;
    }
    
    if(e1>=4 && e1<=19){
        exp2 += ceil((double)e1/4 + 19);
        exp1 = exp1 - e1;
    }
    else if(e1>=20 && e1<=49){
        exp2 += ceil((double)e1/9 + 21);
        exp1 = exp1 - e1;
    }
    else if(e1>=50 && e1<=65){
        exp2 += ceil((double)e1/16 + 17);
        exp1 = exp1 - e1;
    }
    else if(e1>=66 && e1<=79){
        exp2 += ceil((double)e1/4 + 19);
        if(exp2>200){
            exp2 += ceil((double)e1/9 + 21);

        }
        exp1 = exp1 - e1;
    }
    else if(e1>=80 && e1<=99){
        exp2 += ceil((double)e1/4 + 19);
        exp2 += ceil((double)e1/9 + 21);
        if(exp2>400){
        exp2 += ceil((double)e1/16 + 17);
        exp2 = ceil(exp2*1.15);
        }
        exp1 = exp1 - e1;
    }
    if(e1<0||e1>99){
        return -99;
    }
    if(exp1>600){
        exp1=600;
    }
    else if(exp1<0){
        exp1=0;
    }
    if(exp2>600){
        exp2=600;
    }
    else if(exp2<0){
        exp2=0;
    }
    return exp1+exp2;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2){
    //Con đường 1
        int Pi[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int lower = floor(sqrt(EXP1));
        int upper = ceil(sqrt(EXP1));
        int S,IM,i;
        double P1,P2,P3,P;
        
        IM=M1;
        
        if (EXP1 - lower*lower <= upper*upper - EXP1){
            S = lower*lower;
        }
        else{
            S = upper*upper;
        }

        if(EXP1>S || EXP1==S ){
            P1 = 1.0;
        }
        else{
            P1 = (((double)EXP1/S+ 80)/123);
        }
    //Con đường 2
    
    do{
        if(IM-M1>IM*0.5){
        HP1=ceil(HP1*0.83);
        EXP1=ceil(EXP1*1.17);
        lower = floor(sqrt(EXP1));
        upper = ceil(sqrt(EXP1));
        if (EXP1 - lower*lower <= upper*upper - EXP1){
            S = lower*lower;
        }
        else{
            S = upper*upper;
        }
        if(EXP1>S || EXP1==S ){
            P2 = 1.0;
        }
        else{
            P2 = (((double)(EXP1/S)+ 80)/123);
}
        break;
}


        if(HP1<200){
        HP1=ceil(HP1*1.3);
        M1 -=150;
    }
    else{
        HP1=ceil(HP1*1.1);
        M1 -=70;
    }

    if(IM-M1>IM*0.5){
        HP1=ceil(HP1*0.83);
        EXP1=ceil(EXP1*1.17);
        lower = floor(sqrt(EXP1));
        upper = ceil(sqrt(EXP1));
        if (EXP1 - lower*lower <= upper*upper - EXP1){
            S = lower*lower;
        }
        else{
            S = upper*upper;
        }
        if(EXP1>S || EXP1==S ){
            P2 = 1.0;
        }
        else{
            P2 = (((double)(EXP1/S)+ 80)/123);
}
        break;
}

    if(EXP1<400){
        M1 -=200;
        EXP1=ceil(EXP1*1.13);
    }

    else {
        M1 -=120;
        EXP1=ceil(EXP1*1.13);
    }

   if(IM-M1>IM*0.5){
        HP1=ceil(HP1*0.83);
        EXP1=ceil(EXP1*1.17);
        lower = floor(sqrt(EXP1));
        upper = ceil(sqrt(EXP1));
        if (EXP1 - lower*lower <= upper*upper - EXP1){
            S = lower*lower;
        }
        else{
            S = upper*upper;
        }
        if(EXP1>S || EXP1==S ){
            P2 = 1.0;
        }
        else{
            P2 = (((double)(EXP1/S)+ 80)/123);
}
        break;
}
   
    if(EXP1<300){
        M1 -=100;
        EXP1=ceil(EXP1*0.9);
    }
    else{
        M1 -=120;
        EXP1=ceil(EXP1*0.9);
    }


    
   if(IM-M1>IM*0.5){
        HP1=ceil(HP1*0.83);
        EXP1=ceil(EXP1*1.17);
        lower = floor(sqrt(EXP1));
        upper = ceil(sqrt(EXP1));
        
        if (EXP1 - lower*lower <= upper*upper - EXP1){
            S = lower*lower;
        }
        else{
            S = upper*upper;
        }
        if(EXP1>S || EXP1==S ){
            P2 = 1.0;
        }
        else{
            P2 = (((double)(EXP1/S)+ 80)/123);
}
        break;
}

    if(E2%2==0){
        HP1=ceil(HP1*0.83);
        EXP1=ceil(EXP1*1.17);
        lower = floor(sqrt(EXP1));
        upper = ceil(sqrt(EXP1));
        
        if (EXP1 - lower*lower <= upper*upper - EXP1){
            S = lower*lower;
        }
        else{
            S = upper*upper;
        }
        if(EXP1>S || EXP1==S ){
            P2 = 1.0;
        }
        else{
            P2 = (((double)(EXP1/S)+ 80)/123);
}
        break;
}
}
    while(E2%2!=0);

    //con đường 3
    if(E2<=10){
        i=E2;
    }

    else{
        i= E2/10 + E2%10;
    }

    if(i>10){
        i= i%10;
    }


    P3=Pi[i]*0.01;
    

    if(P1==1 && P2==1 && P3==1){
        EXP1 =ceil(EXP1*0.75);
        P=1;
    }
    else{
        P=((P1+P2+P3)/3);
    }


    if(P<0.5){
        HP1=ceil(HP1*0.85);
        EXP1=ceil(EXP1*1.15);
    }

    else{
        HP1=ceil(HP1*0.9);
        EXP1=ceil(EXP1*1.2);
    }

    if(EXP1>600) EXP1=600;
    if(EXP1<0) EXP1=0;
    if(HP1<0) HP1=0;
    if(HP1>666) HP1= 666;


    return HP1+EXP1+M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
     int taxi[10][10];
    int sherlock[10][10];
    int sw;
    int i=0;
    int j=0;
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            taxi[i][j] =((E3 * j) + (i * 2)) * (i - j);

    }
    }
    for (int x=0; x<10; x++) {
        for (int y=0; y<10; y++) {
            if (taxi[x][y] > E3*2)
            {
                i++;
            }
            else if(taxi[x][y] < -E3){
                j++;
            }
        }
    }
    

    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            sw = taxi[i][j];

            for (int k=0;  k < min(i, j) + 1; k++) {
                sw = max(sw, taxi[i - k][j - k]);
            }

            for (int k=0; k < min(i, 10 - j - 1) + 1; k++) {
                sw = max(sw, taxi[i - k][j + k]);
            }

            sherlock[i][j] = sw;

            
        }
    }
    
    if(i<10){
        i=i;
    }
    else{
        i=i/10+i%10;
    }
    if(i<10){
        i=i;
    }
    else{
        i=i/10+i%10;
    }
    if(j<10){
        j=j;
    }
    else{
        j=j/10+j%10;
    }
    if(j<10){
        j=j;
    }
    else{
        j=j/10+j%10;
    }
    if(abs(taxi[i][j]) > abs(sherlock[i][j])){
        EXP1= ceil(EXP1 * 0.88);
        HP1= ceil(HP1 * 0.9);
        EXP2= ceil(EXP2 * 0.88);
        HP2= ceil(HP2 * 0.9);
                    if(EXP1>600) EXP1=600;
    if(HP1<0) HP1=0;

    if(HP1>666){
        HP1=666;
    }
    if(EXP1<0){
        EXP1=0;
    }
        if(EXP2>600) EXP2=600;
    if(HP2<0) HP2=0;

    if(HP2>666){
        HP2=666;
    }
    if(EXP2<0){
        EXP2=0;
    }
    
        return taxi[i][j];
    }
    else{
        EXP1= (EXP1*1.12);
        HP1= (HP1*1.1);
        EXP2= (EXP2*1.12);
        HP2= (HP2*1.1);
        if(EXP1>600) EXP1=600;
    if(HP1<0) HP1=0;

    if(HP1>666){
        HP1=666;
    }
    if(EXP1<0){
        EXP1=0;
    }
        if(EXP2>600) EXP2=600;
    if(HP2<0) HP2=0;

    if(HP2>666){
        HP2=666;
    }
    if(EXP2<0){
        EXP2=0;
    }
        return sherlock[i][j];
    }   
    
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
        int ch = '@';
    const char* a= "@";
    char* target= strdup(email);
    char* atPos = strchr(target, ch);
    char *b4= strdup(email);
    const char* se=strtok(b4, a); 

    int len = strlen(s);
    if (len < 8) return -1;
    if (len > 20) return -2;

    bool hasSpecialChar = false;
    for (char c : (string)s) {
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) return -5;

    const char* sePos = strstr(s, b4);

    if (sePos) {
            int sei = sePos - s;
            return -(300 + sei);
        }

    for (int i = 0; i < len - 1; ++i) {
        if (s[i] == s[i + 1]) return -(400 + i);
    }

    return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_count = 0;
  int max_length = 0;
  int correct_index;

  for (int i = 0; i < num_pwds; i++) {
    int count = 0;
    for (int j = 0; j < num_pwds; j++) {
      if (arr_pwds[i] == arr_pwds[j]) {
        count++;
      }
    }

    int length = strlen(arr_pwds[i]);

    if (count > max_count || (count == max_count && length > max_length)) {
      max_count = count;
      max_length = length;
      correct_index = i;
    }
  }
    return correct_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////