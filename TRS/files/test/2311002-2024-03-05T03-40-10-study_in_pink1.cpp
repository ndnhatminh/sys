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
    if (e1<0 or e1>99){
        return -99;
    }
    if (exp1>666)
        exp1=600;
    if (exp1<0)
        exp1=0;
    if (exp2>666)
        exp2=600;
    if (exp2<0)
        exp2=0;
    if (e1>=0 and e1<=3)
    {
        if (e1==0)
            exp2=exp2+29;
        if (e1==1)
            exp2=exp2+45;
        if (e1==2)
            exp2=exp2+75;
        if (e1==3)
            exp2=exp2+29+45+75;
        if (exp2>600)
            exp2=600;
        int D=e1*3+exp1*7;
        if (D%2==0){
        exp1=ceil(exp1+D*1.0/200);
        }
        else
        {
        exp1=ceil(exp1-D*1.0/100);
        }
        if (exp1>600)
        exp1=600;
        if (exp1<0)
        exp1=0;
    }
    if (e1>=4 and e1<=99){
        if (e1>=4 and e1<=19)
        exp2=ceil(exp2+e1*1.0/4+19);
        if (e1>=20 and e1<=49)
        exp2=ceil(exp2+e1*1.0/9+21);
        if (e1>=50 and e1<=65)
        exp2=ceil(exp2+e1*1.0/16+17);
        if (e1>=66 and e1<=79)
        {
            exp2=ceil(exp2+e1*1.0/4+19);
            if (exp2>200)
            exp2=ceil(exp2+e1*1.0/9+21);
        }
        if (e1>=80 and e1<=99)
        {
            exp2=ceil(exp2+e1*1.0/4+19);
            if (exp2>600)
                exp2=600;
            exp2=ceil(exp2+e1*1.0/9+21);
            if (exp2>600)
                exp2=600;
            if (exp2>400){
            exp2=ceil(exp2+e1*1.0/16+17);
            if (exp2>600)
               exp2=600;
            exp2=ceil(exp2*1.15);
            if (exp2>600)
                exp2=600;
            }
        }
        if (exp2>600)
        exp2=600;
        exp1=exp1-e1;
        if (exp1<0)
        exp1=0;
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
    float p,p1,p2,p3;
    int a=0,i;
    int M=M1;
    if (HP1>666)
        HP1=666;
    if (HP1<0)
        HP1=0;
    if (EXP1>666)
        EXP1=600;
    if (EXP1<0)
        EXP1=0;
    if (M1<0) M1=0;
    if (M1>3000) M=3000;
    //Road 1 and calculate P1
    size_t S=round(sqrt(EXP1))*round(sqrt(EXP1));
    if (EXP1>=S)
        p1=1;
    else
        p1=(EXP1*1.0/S+80)*1.0/123;
    // the special case
    if (E3<0 or E3>99)
        return -99;
    // Road 2   
    // E2 is odd, we show how EXP1 and HP1 change.
    if (E3%2!=0){
    do{
      if (M1==0) break;
      if (HP1<200){
        M1-=150;
        HP1=ceil(HP1*130.0/100);
        if (M1<=0){
          M1=0;
          break;
        }
        if (M1<ceil(M*1.0/2)){
          break;
        }
      }
      else {
        M1-=70;
        HP1=ceil(HP1*110.0/100);
          if (HP1>666)
          HP1=666;
        if (M1<=0){
          M1=0;
          break;
        }
        if (M1<ceil(M*1.0/2)){
          break;
        }
      }
      if (EXP1<400){
        M1-=200;
        EXP1=ceil(EXP1*113.0/100);
          if (EXP1>600)
              EXP1=600;
        if (M1<=0){
          M1=0;
          break;
        }
        if (M1<ceil(M*1.0/2)){
          break;
        }
      }
      else{
        M1-=120;
        EXP1=ceil(EXP1*113.0/100);
          if (EXP1>600)
              EXP1=600;
        if (M1<=0){
          M1=0;
          break;
        }
        if (M1<ceil(M*1.0/2)){
          break;
        }
      }
      if (EXP1<300){
        M1-=100;
        EXP1=ceil(EXP1*0.9);
        if (M1<=0){
          M1=0;
          break;
        }
        if (M1<ceil(M*1.0/2)){
          break;
        }
      }
      else{
        M1-=120;
        EXP1=ceil(EXP1*0.9);
        if (M1<=0){
          M1=0;
          break;
        }
        if (M1<ceil(M*1.0/2)){
          break;
        }
      } 
    }
    while (M1>=(M/2));
    HP1=ceil(HP1*0.83);
    EXP1=ceil(EXP1*117.0/100);
    if (EXP1>600)
        EXP1=600;
    }
    // E2 is even, we show how EXP1 and HP1 change.
    else{
      while(a<3){
      if (M1==0) break;
      if (HP1<200){
        M1-=150;
        ++a;
        HP1=ceil(HP1*130.0/100);
        if (HP1>666)
          HP1=666;
        if (M1<=0){
          M1=0;
          break;
        }
    }
      else {
        M1-=70;
        ++a;
        HP1=ceil(HP1*110.0/100);
        if (HP1>666)
          HP1=666;
        if (M1<=0){
          M1=0;
          break;
        }
    }
    if (EXP1<400){
        M1-=200;
        ++a;
        EXP1=ceil(EXP1*113.0/100);
        if (EXP1>600)
            EXP1=600;
        if (M1<=0){
          M1=0;
          break;
        }
      }
      else{
        M1-=120;
        ++a;
        EXP1=ceil(EXP1*113.0/100);
        if (EXP1>600)
            EXP1=600;
        if (M1<=0){
          M1=0;
          break;
        }
      }
      if (EXP1<300){
        M1-=100;
        ++a;
        EXP1=ceil(EXP1*0.9);
        if (M1<=0){
          M1=0;
          break;
        }
      }
      else{
        M1-=120;
        ++a;
        EXP1=ceil(EXP1*0.9);
        if (M1<=0){
          M1=0;
          break;
        }
      }
      }
      HP1=ceil(HP1*0.83);
      EXP1=ceil(EXP1*117.0/100);
      if (EXP1>600)
        EXP1=600;
    }
    // Calculate P2
    S=round(sqrt(EXP1))*round(sqrt(EXP1));
    if (EXP1>=S)
        p2=1;
    else
        p2=(EXP1*1.0/S+80)*1.0/123;
    // Road 3
    int Probability[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E3<10)
        i=E3;
    else{
        i=(E3/10)+(E3%10); //Euclidean algorithm
        i=i%10;
    }
    p3=Probability[i]*1.0/100;
    // All.
    p=(p1+p2+p3)/3;
    if (p==1)
        EXP1=ceil(EXP1*0.75);
    else{
        if (p<0.5){
          HP1=ceil(HP1*0.85);
          EXP1=ceil(EXP1*115.0/100);
          if (EXP1>600)
          EXP1=600;
        }
        else{
          HP1=ceil(HP1*0.9);
          EXP1=ceil(EXP1*120.0/100);
          if (EXP1>600)
          EXP1=600;
        }
    }
    return HP1+EXP1+M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int i=0,j=0;
    int a=0,b=0;
    int Taxivalue[10][10];
    int maximumValue[i][j];
    int S=0;
    // the special case
    if (E3<0 or E3>99)
        return -99;
    // taxi's scores and determine point(i,j)
    if (HP1>666)
        HP1=600;
    if (HP2>666)
        HP2=600;
    if (EXP1<0)
        EXP1=0;
    if (EXP2>666)
        EXP2=600;
    if (EXP2<0)
        EXP2=0;
    for (i=0;i<10;i++){
      for (j=0;j<10;j++){
        Taxivalue[i][j]=((E3*j)+(i*2))*(i-j);
        if (Taxivalue[i][j]>2*E3){
          ++a;
        }
        if (Taxivalue[i][j]<-E3){
          ++b;
        }
      }
    }
    // Convert i,j to 1-digit numbers
    do
      a=a/10+a%10;
    while (a>=10);
    do
      b=b/10+b%10; 
    while (a>=10);
    i=a;
    j=b;
    //Sherlock and Watson's score
    maximumValue[a][b]=Taxivalue[i][j];
    while(i<9 and j<9){
      if (maximumValue[a][b]<Taxivalue[i+1][j+1])
        maximumValue[a][b]=Taxivalue[i+1][j+1];
        ++i;
        ++j;
    } //(1,1)
    i=a;
    j=b;
    while(i>0 and j>0){
      if (maximumValue[a][b]<Taxivalue[i-1][j-1])
        maximumValue[a][b]=Taxivalue[i-1][j-1];
        --i;
        --j;
    }//(-1;-1)
    i=a;
    j=b;
    while(i<9 and j>0){
      if (maximumValue[a][b]<Taxivalue[i+1][j-1])
        maximumValue[a][b]=Taxivalue[i+1][j-1];
        ++i;
        --j;
    }//(1;-1)
    i=a;
    j=b;
    while(i>0 and j<9){
      if (maximumValue[a][b]<Taxivalue[i-1][j+1])
        maximumValue[a][b]=Taxivalue[i-1][j+1];
        --i;
        ++j;
    }//(-1;1)
    if (maximumValue[a][b]<0) maximumValue[a][b]=abs(maximumValue[a][b]);
    if(abs(Taxivalue[a][b])<=maximumValue[a][b]){
      EXP1=ceil(EXP1*112.0/100);
      if (EXP1>600)
          EXP1=600;
      HP1=ceil(HP1*110.0/100);
      if (HP1>666)
          HP1=666;
      EXP2=ceil(EXP2*112.0/100);
      if (EXP2>600)
          EXP2=600;
      HP2=ceil(HP2*110.0/100);
      if (HP2>666)
          HP2=666;
      S=maximumValue[a][b];
    }
    else{
      EXP1=ceil(EXP1*0.88);
      HP1=ceil(HP1*0.9);
      EXP2=ceil(EXP2*0.88);
      HP2=ceil(HP2*0.9);
      S=Taxivalue[a][b];
    }
    return S;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // Extract the string before '@' from the email
    const char* se = strchr(email, '@');
    char username[100];
    strncpy(username, email, se-email);
    username[se - email] = '\0';
    se=username;
    // Check password length
    size_t len = strlen(s);
    if (len<8) {
        return -1; // Length too short
    }
    if (len>20) {
        return -2; // Length too long
    }
    // Check if it contains se
    if (strstr(s, se) != nullptr) {
        return -(300 + (strstr(s, se) - s));
    }

    // Check for consecutive identical characters
    for (size_t i = 0; i < len - 2; ++i) {
        if (s[i] == s[i+1] && s[i] == s[i+2]) {
            return -(400 + i); // Consecutive identical characters
        }
    }
    // Check for special characters
    const char* specialChars = "@#%$!";
    bool hasSpecialChar = false;
    for (size_t i=0; i<len; ++i) {
        if (strchr(specialChars, s[i]) != nullptr) {
            hasSpecialChar = true;
            break;
        }
    }
    // No special character
    if (!hasSpecialChar) {
        return -5;
    }
    //The remaining case
    size_t othercase=0;
    for (size_t i=0;i<len;i++){
      char c=s[i];
      ++othercase;
      if (!isalnum(c) && c!='@' && c!='#' && c!='%' && c!='$' && c!='!'){
        return othercase-1;
        break;
      }
    }
    // Valid password
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    size_t s[1000];
    size_t Maxfrequency=0;
    size_t Maxlength=0;
    const size_t n=num_pwds;
    string p[n];
    int Index=-1;
    for (size_t i=0; i<n; ++i)
    {
        p[i]=arr_pwds[i];
    }
    for (size_t i=0; i<n; ++i){
        s[i]=0;
    }
    // 
    for (size_t i=0; i<n; ++i) {
        for (size_t j=0; j<n; ++j) {
            if (p[i] == p[j]) {
                ++s[i];
            }
        }
    }
    // Find max frequency of a string
    for (size_t i=0; i<n;++i){
        if (Maxfrequency<s[i])
        Maxfrequency=s[i];
    }
    // Find max lenght of the max frequency one
    for (size_t i=0; i<n;++i){
        if (s[i]==Maxfrequency){
            if (Maxlength<p[i].length()){
                Maxlength=p[i].length();
            }
        }
    }
    for (size_t i=0; i<n;++i){
      if (s[i]==Maxfrequency and p[i].length()==Maxlength){
        Index=i;
        break;
      }
    }
    return Index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
