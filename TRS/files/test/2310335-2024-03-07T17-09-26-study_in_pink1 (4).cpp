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
int demphantu(int x){
    int k=x;
    int dem=0;
    while(k>0){
   k=k/10;
   dem++;
    }
    return dem;
}
int demchuso(int a){
int k=0;
 while(a>0){
 k+=a%10;
 a=a/10;
 }
 return k;
}
int chuanhoa(int x){
    while(demphantu(x)!=1){
  x= demchuso(x);
    }
    return x;
}
 void checktien(int &a){
if(a<0){
    a=0;
}
if(a>3000){
    a=3000;
}
} 
void checkHP(int &a){
if(a<0){
    a=0;
}
if(a>666){
    a=666;
}
} 
void checkEXP(int &a){
if(a<0){
    a=0;
}
if(a>600){
    a=600;
}
} 
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
     


    
    
    checkEXP(EXP1);
    checkEXP(EXP2);
    if(E1<0||E1>99){
        
        return -99;
    }
    if(E1>=0&&E1<=3){

    
    if(E1==0){
      EXP2+=29;
      checkEXP(EXP2);
    }
    if(E1==1){
        EXP2+=45;
        checkEXP(EXP2);
    }
    if(E1==2){
        EXP2+=75;
        checkEXP(EXP2);
    }
    if(E1==3){
        EXP2=EXP2+45+29+75;
        checkEXP(EXP2);
    }
    int D;
    D=E1*3+EXP1*7;
    if(D%2==0){
        EXP1=ceilf(EXP1+((float)D/200));
        checkEXP(EXP1);
    }
    if(D%2==1){
        EXP1=ceilf(EXP1-((float)D/100));
        checkEXP(EXP1);
        
    }
}
if(E1>=4&&E1<=99){
    if(E1>=4&&E1<=19){
        EXP2=EXP2+ceilf((float)E1/4)+19;
        checkEXP(EXP2);
    }
    if(E1>=20&&E1<=49){
        EXP2=EXP2+ceilf((float)E1/9)+21;
        checkEXP(EXP2);
    }
    if(E1>=50&&E1<=65){
        EXP2=EXP2+ceilf((float)E1/16)+17;
        checkEXP(EXP2);
    }
    if(E1>=66&&E1<=79){
        EXP2=EXP2+ceilf((float)E1/4)+19;
        checkEXP(EXP2);
        if(EXP2>200){
          EXP2=EXP2+ceilf((float)E1/9)+21;
          checkEXP(EXP2);
        }
    }
    if(E1>=80&&E1<=99){
        EXP2=EXP2+ceilf((float)E1/4)+19;
        checkEXP(EXP2);
        EXP2=EXP2+ceilf((float)E1/9)+21;
    checkEXP(EXP2);
    if(EXP2>400){
          EXP2=EXP2+ceilf((float)E1/16)+17;
          checkEXP(EXP2);
          EXP2=ceilf(EXP2+EXP2*0.15);
          checkEXP(EXP2);
        }
    }
    EXP1=EXP1-E1;
    checkEXP(EXP1);
}
    
    


    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
if(E2<0||E2>99){
        
        return -99;
    }

  checkHP(HP1);
  checkEXP(EXP1);
  checktien(M1);
  int a;
  a=sqrt(EXP1);
  int b=a+1;
  int S;
  float P1;
  float P2;
  float P3;
  if(E2<0||E2>99){

        return -99;
    }
    else{
  if((EXP1-a*a)<(b*b-EXP1)){
    S=a*a;
  }
  else{
    S=b*b;
  }
  if(EXP1>=S){
    P1=100/100;
  }
  else{
    P1=(((float)EXP1/S)+80)/123;
  }
   


  int moc=M1/2;
  int tienchitra=0;
 if(E2%2==0){
  for(int i=0;i<1;i++){
    if(HP1<200){
      HP1=ceilf(HP1*1.3);
      checkHP(HP1);
      M1=M1-150;
      checktien(M1);
      if(M1==0){
        break;
      }
    }
    else{
      HP1=ceilf(HP1*1.1);
      checkHP(HP1);
      M1=M1-70;
      checktien(M1);
      if(M1==0){
        break;
      }
    }
    if(EXP1<400){
      M1=M1-200;
      checktien(M1);
      EXP1=ceilf(EXP1*1.13);
      checkEXP(EXP1);
      if(M1==0){
        break;
      }
    }
    else{
      M1=M1-120;
      checktien(M1);
      EXP1=ceilf(EXP1*1.13);
      checkEXP(EXP1);
      if(M1==0){
        break;
      }
    }
    if(EXP1<300){
      M1=M1-100;
      checktien(M1);
      
    }
    else{
      M1=M1-120;
      checktien(M1);
      
    }
    EXP1=ceilf(EXP1*0.9);
    checkEXP(EXP1);
  }


  }
  
  else{
while(1){
if(HP1<200){
      HP1=ceilf(HP1*1.3);
      checkHP(HP1);
      M1=M1-150;
      tienchitra+=150;
      checktien(M1); 
     
      if(tienchitra>=(moc+1)){
        break;
      }
    }
    else{
      HP1=ceilf(HP1*1.1);
      
      checkHP(HP1);
      M1=M1-70;
      tienchitra+=70;
       
      checktien(M1);
      if(tienchitra>=(moc+1)){
        break;
      }
    }
    if(EXP1<400){
      M1=M1-200;
      tienchitra+=200;
      checktien(M1);
       EXP1=ceilf(EXP1*1.13);
       checkEXP(EXP1);
      if(tienchitra>=(moc+1)){
        break;
      }
    }
    else{
      M1=M1-120;
      tienchitra+=120;
       
      checktien(M1);
       EXP1=ceilf(EXP1*1.13);
       checkEXP(EXP1);
      if(tienchitra>=(moc+1)){
        break;
      }
    }
    if(EXP1<300){
      M1=M1-100;
      tienchitra+=100;
      checktien(M1);
      EXP1=ceilf(EXP1*0.9);
    checkEXP(EXP1);
      if(tienchitra>=(moc+1)){
        break;
      }
    }
    else{
      M1=M1-120;
      tienchitra+=120;
      checktien(M1);
      EXP1=ceilf(EXP1*0.9);
    checkEXP(EXP1);
      if(tienchitra>=(moc+1)){
        
        break;
      }
    }
    
}



  }
  EXP1=ceilf(EXP1*1.17);
  checkEXP(EXP1);
HP1=ceilf(HP1*0.83);
checkHP(HP1);

  
  a=sqrt(EXP1);
  b=a+1;
   
    
  if((EXP1-a*a)<(b*b-EXP1)){
    S=a*a;
  }
  else{
    S=b*b;
  }
  if(EXP1>=S){
    P2=100/100;
  }
  else{
    P2=(((float)EXP1/S)+80)/123;
  }
  
int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
 int k=(demchuso(E2))%10;
 
 P3=((float)P[k])/100;
 
if(P1==1&&P2==1&&P3==1){
  EXP1=ceilf(EXP1*0.75);
  checkEXP(EXP1);
}
else{
  float Pchung;
  
  Pchung=(P1+P2+P3)/3;
  
  if(Pchung<0.5){
  
    HP1=ceilf(HP1*0.85);
    checkHP(HP1);
     EXP1=ceilf(EXP1*1.15);
     checkEXP(EXP1);
  }
  else{ 
    HP1=ceilf(HP1*0.9);
    checkHP(HP1);
     EXP1=ceilf(EXP1*1.2);
     checkEXP(EXP1);
  }
}
 }
 
 
    
 
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0||E3>99){
        
        return -99;
    }
    checkHP(HP1);
    checkHP(HP2);
    checkEXP(EXP1);
    checkEXP(EXP2);
 int a[10][10];
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      a[i][j] = ((E3*j)+(i*2))*(i-j);
    }
  }
   int x=0;
   int y=0;
   for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if(a[i][j]>(2*(E3))){
        x++;
      }
      if(a[i][j]<(-(E3)))
      y++;
    }
  }
    
   
   x=chuanhoa(x);
   y=chuanhoa(y);
   
  int diem=a[x][y];
  int x1=x;
    int y1=y;
  while(x1>=0&&x1<=8&&y1>=0&&y1<=8){
    
    diem=max(diem,a[x1+1][y1+1]);
    x1=x1+1;
    y1=y1+1;
  }
  
   x1=x;
     y1=y;
  while(x1>=1&&x1<=9&&y1>=1&&y1<=9){
    
    diem=max(diem,a[x1-1][y1-1]);
    x1=x1-1;
    y1=y1-1;
  }
   x1=x;
     y1=y;
  while(x1>=1&&x1<=9&&y1>=0&&y1<=8){
    
    diem=max(diem,a[x1-1][y1+1]);
    x1=x1-1;
    y1=y1+1;
  }
   x1=x;
     y1=y;
  while(x1>=0&&x1<=8&&y1>=1&&y1<=9){
    
    diem=max(diem,a[x1+1][y1-1]);
    x1=x1+1;
    y1=y1-1;
    
  }
  
 
  
  if(abs(diem)<abs(a[x][y])){
    
    EXP1=ceilf(EXP1*0.88);
    checkEXP(EXP1);
    HP1=ceilf(HP1*0.9);
    checkHP(HP1);
    EXP2=ceilf(EXP2*0.88);
    checkEXP(EXP2);
    HP2=ceilf(HP2*0.9);
    checkHP(HP2);
    return a[x][y];
  }
else{
    
    EXP1=ceilf(EXP1*1.12);
    checkEXP(EXP1);
    HP1=ceilf(HP1*1.1);
    checkHP(HP1);
    EXP2=ceilf(EXP2*1.12);
  checkEXP(EXP2);
    HP2=ceilf(HP2*1.1);
 checkHP(HP2);
 return diem;
}


}
    

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    string se;
    string khoa="@";
    string kitudacbiet[5]={"@","#","$","%","!"};
    int n;
    string s1[n];
 
 n=strlen(s);
 for(int i=0;i<=strlen(s)-1;i++){
    s1[i]=s[i];
 }
 int i=0;
   while(1){
    if (email[i]==khoa[0]){
        break;
    }
    
 
 
 i++;
   }
int l=0;
   for(int k=0;k<i;k++){
    se[k]=email[k];
   }
   
   int h=0;
   while(l<strlen(email)){
    if (email[l]==khoa[0]){
        h++;
    }
    l++;
   }
   
   if(h!=1){
    return 0;
   }
   if(strlen(email)>100){
    return 0;
   }
   
if(strlen(s)<8){
 return-1;
 
}   
if(strlen(s)>20){
    return -2;
    
} 
int check=0;
int sei=0;
   for(int k=0;k<=(strlen(s)-1);k++){
    if(s[k]==se[0]){
        for(int l=0;l<=i-1;l++){
            if(s[k+l]!=se[l]){
             
             break;
            }
            if(l==i-1){
                check=1;
            }
        }
        if(check==1){
        sei=k;
        break;
    }
    
    }
   }
 if(check==1){
    return-(300+(sei));
    
 }
 check=0;
 int sci;
 for(int k=0;k<=strlen(s)-3;k++){
 if(s[k]==s[k+1]&&s[k+1]==s[k+2]){
    check=1;
 }
 if(check==1){
    sci=k;
    break;
 }
 }
if(check==1){
    return -(400+sci);
    
}
check=0;
for(int k=0;k<=strlen(s)-1;k++){
 for(int m=0;m<=4;m++){
    if(s1[k]==kitudacbiet[m]){
        check =1;
    }
 }
}
if(check==0){
    return -5;
    
}
return -10;

}
    


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    
    int l;
    
    
    int b;
    
    
    int nhieunhat=0;
    for(int i=0;i<num_pwds;i++){
        int a=0;
        for(int j=0;j<num_pwds;j++){
        if(arr_pwds[i]==arr_pwds[j]){
            a++;
            
        }

    }
    nhieunhat=max(nhieunhat,a-1);
    }
    
    int dainhat=0;
    for(int i=0;i<num_pwds;i++){
        int a=0;
        for(int j=0;j<num_pwds;j++){
        if(arr_pwds[i]==arr_pwds[j]){
            a++;
            
        }

    }
    if(a-1==nhieunhat){
        b=strlen(arr_pwds[i]);
            dainhat=max(dainhat,b);

    }
    
    }
    int tam;
    for(int i=0;i<num_pwds;i++){
        int a=0;
        for(int j=0;j<num_pwds;j++){
        if(arr_pwds[i]==arr_pwds[j]){
            a++;
            
        }
    
    }
l=strlen(arr_pwds[i]);
    if(a-1==nhieunhat&&l==dainhat){
        tam= i;
        break;
    }
   
    }
    return tam;
}

    


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////