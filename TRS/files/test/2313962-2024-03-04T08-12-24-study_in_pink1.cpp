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
    if(e1<0 || e1>99) return -99;
    if( e1>=0 && e1<=3){
        switch(e1){
        case 0: 
        exp2+=29;
        break;
        case 1: 
        exp2+=45;
        break;
        case 2:
        exp2 +=75 ;
        break;
        case 3:
        exp2+=29+ 75 +45;
        break;}
          if(exp2<0) exp2=0;
     if(exp2>600) exp2=600;
       int d=e1*3 + exp1*7;
   if(d%2==0) exp1= ceil( exp1 + (double) d/200);
   else exp1= ceil( exp1 - (double) d/100);
   if(exp1<0) exp1=0;
    if(exp1>600) exp1=600;
     if(exp2<0) exp2=0;
     if(exp2>600) exp2=600;
       }
       else if(e1>=4 && e1<=99){
        switch(e1){
        case 4 ... 19:
        exp2+= ceil( (double) e1/4 +19);
        break;
        case 20 ... 49:
        exp2+= ceil( (double) e1/9 +21);
        break;
        case 50 ... 65:
        exp2+= ceil( (double) e1/16 +17);
        break;
        case 66 ... 79:
         exp2+= ceil( (double) e1/4 +19);
         if(exp2>200) exp2+= ceil( (double) e1/9 +21);
         break;
         case 80 ... 99:
          exp2+= ceil( (double) e1/4 +19);
          exp2+= ceil( (double) e1/9 +21);
          if(exp2<0) exp2=0;
     if(exp2>600) exp2=600;
          if(exp2>400)   { 
            exp2+= ceil( (double) e1/16 +17);
            exp2+= ceil( exp2 * 0.15);  }
            break;
            }
         exp1-=e1;
          if(exp1<0) exp1=0;
    if(exp1>600) exp1=600;
     if(exp2<0) exp2=0;
     if(exp2>600) exp2=600;
}
       
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
      if(E2<0 || E2>99) return -99;
     int  s1 = pow(round(sqrt(EXP1)),2);
    double p1;
    if ( EXP1>=s1) p1=1;
    else p1=  ((double) EXP1/s1 +80) /123 ;
   
    if(E2 %2 !=0){
        int M0=M1;
        while (1){ if(M1==0) break;
     if(HP1 < 200){
        HP1 = ceilf( (float)(0.3*HP1 +HP1));
        M1-=150;
       }
        else {
             HP1 = ceilf( (float)(0.1*HP1 +HP1));
        M1-=70;}
         if(HP1<0) HP1=0;
        if(HP1>666) HP1=666;
        if(M1<0) M1=0;
        if(M1>3000) M1=3000;
            if(M1 < (float)M0/2) break; 
    if(EXP1 <400) M1-=200;
    else M1-=120;
    EXP1 = ceilf( (float)(0.13*EXP1 +EXP1));
        if(EXP1<0) EXP1=0;
        if(EXP1>600) EXP1=600;
        if(M1<0) M1=0;
        if(M1>3000) M1=3000;
        if(M1 < (double)M0/2) break; 
    if(EXP1 < 300) M1-=100;
    else M1-=120;
      EXP1 = ceilf( EXP1 -  (float)0.1*EXP1 );
        if(EXP1<0) EXP1=0;
        if(EXP1>600) EXP1=600;
        if(M1<0) M1=0;
        if(M1>3000) M1=3000;
    if(M1 < (double)M0/2) break; }
     HP1 = ceilf( (float)(HP1 -0.17*HP1 ));
     EXP1 = ceilf( (float)0.17*EXP1 +EXP1);
        if(EXP1<0) EXP1=0;
        if(EXP1>600) EXP1=600;
        if(HP1<0) HP1=0;
        if(HP1>666) HP1=666;
       }
     else{
        while(1){
               if(M1==0) break;
            if(HP1<200){
        HP1 = ceilf( (float)(0.3*HP1 +HP1));
        M1-=150;}
        else {
             HP1 = ceilf( (float)(0.1*HP1 +HP1));
        M1-=70;}
         if(EXP1<0) EXP1=0;
        if(EXP1>600) EXP1=600;
        if(HP1<0) HP1=0;
        if(HP1>666) HP1=666;
        if(M1<0) M1=0;
        if(M1>3000) M1=3000;
        if(M1==0) break;
    if(EXP1 <400) M1-=200;
    else M1-=120;
    EXP1 = ceilf( (float)0.13*EXP1 +EXP1);
        if(EXP1<0) EXP1=0;
        if(EXP1>600) EXP1=600;
        if(M1<0) M1=0;
        if(M1>3000) M1=3000;
     if(M1==0) break;
    if(EXP1 < 300) M1-=100;
    else M1-=120;
      EXP1 = ceilf( EXP1 -  (float)0.1*EXP1 );
        if(EXP1<0) EXP1=0;
        if(EXP1>600) EXP1=600;
        if(M1<0) M1=0;
        if(M1>3000) M1=3000;
        break;
        }
         HP1 = ceilf( (float)(HP1- 0.17*HP1 ));
         EXP1 = ceilf( (float)0.17*EXP1 +EXP1);
        if(EXP1<0) EXP1=0;
        if(EXP1>600) EXP1=600;
        if(HP1<0) HP1=0;
        if(HP1>666) HP1=666;
        }
       int  s2 = pow(round(sqrt(EXP1)),2);
    double p2;
    if ( EXP1>=s2) p2=1;
    else p2= ((double) EXP1/s2 + 80 )/123 ;
    
    double arr[] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    double p3;
    if(E2 <10) p3= arr[E2];
    else {
   int  i = E2/10 +E2%10; 
   int j = i%10;
    p3=arr[j];
   
         }
         
   
   if(p1==1 && p2==1 && p3==1)  EXP1 = ceilf( -(float)0.25*EXP1 +EXP1);
   else{
    double p4 =  (double)(p1+p2+p3)/3;
    if(p4< 0.5){ HP1 = ceilf( (float)(HP1 -0.15*HP1) );
     EXP1 = ceilf( (float)0.15*EXP1 +EXP1);}
    else { HP1 = ceilf( ((float)HP1 - 0.1*HP1) );
     EXP1 = ceilf( (float)0.2*EXP1 +EXP1);}
   }
     if(EXP1<0) EXP1=0;
        if(EXP1>600) EXP1=600;
        if(HP1<0) HP1=0;
        if(HP1>666) HP1=666;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
      if(E3<0 || E3>99) return -99;
    int mt[10][10]={0};
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
       mt[i][j]= ((E3*j)+(i*2))*(i-j);
        }
    }
     int a=0,b=0;
       for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            if(mt[i][j]> E3*2) ++a;
            if(mt[i][j] < -E3) ++b;}}
      while(1){
        if(a>9) { a= a/10 + a%10;    
      }   
      else break;}
      while(1){
        if(b>9) {b= b/10 + b%10;    
      }   
      else break;}
      int a0=a;
      int b0=b;
      int point_t = abs(mt[a][b]);
      int point_t1 = mt[a][b];
      int point_s = mt[a][b];
      while(1){
        a-=1;
        b-=1;
        if(a<0) break;
        if(b<0) break;
        if(mt[a][b]> point_s ) point_s =mt[a][b];
     }
     a=a0;
     b=b0;
      while(1){
        a+=1;
        b+=1;
        if(a>9) break;
        if(b>9) break;
        if(mt[a][b]> point_s ) point_s =mt[a][b];
     }
     a=a0;
     b=b0;

           while(1){
        a-=1;
        b+=1;
        if(a<0) break;
        if(b>9) break;
        if(mt[a][b]> point_s ) point_s =mt[a][b];
     }
     a=a0;
     b=b0;
         while(1){
        a+=1;
        b-=1;
        if(a>9) break;
        if(b<0) break;
        if(mt[a][b]> point_s ) point_s =mt[a][b];
     }
     int point_s1 = point_s;
     if(point_s<0) point_s = abs(point_s);
     if(point_t >point_s){
        EXP1= ceil( EXP1 - EXP1*0.12);
         EXP2= ceil( EXP2 - EXP2*0.12);
          HP1= ceil( HP1 - HP1*0.1);
           HP2= ceil( HP2 - HP2*0.1);
     } 
     else{
         EXP1= ceil( EXP1 + EXP1*0.12);
         EXP2= ceil( EXP2 + EXP2*0.12);
          HP1= ceil( HP1 + HP1*0.1);
           HP2= ceil( HP2 + HP2*0.1);
}
   if(EXP1<0) EXP1=0;
        if(EXP1>600) EXP1=600;
        if(HP1<0) HP1=0;
        if(HP1>666) HP1=666;
           if(EXP2<0) EXP2=0;
        if(EXP2>600) EXP2=600;
        if(HP2<0) HP2=0;
        if(HP2>666) HP2=666;
if(point_t > point_s) return point_t1;
else return point_s1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
  int spt=0;
 for(int i=0; i<strlen(email);++i){
    
    if( email[i]=='@') break;
   ++spt;
   }
   char se[spt];
   for(int i=0; i<strlen(email);++i){
    
    if( email[i]=='@') break;
       se[i] = email[i];
   }
  if( strlen(s) <8 ) return -1;
   if( strlen(s)>20) return -2;
   int sei;
   int kq=0;
   for(int i=0;i< strlen(s);++i){
        int v=0;
        if( s[i] == se[0]){ 
            for(int j=0;j< spt;++j){
                if(s[i+j] != se[j] ) break;
                else v=j+1;
               } }
            if(v== spt){
                sei=i;
               ++kq;
                break;
             }
    }
    if(kq !=0) return -(300+sei);
int n1=0;
int sci;
for(int i=0;i< strlen(s);++i){
  if(s[i]==s[i+1] && s[i+1]==s[i+2]) {
    sci =i;
    ++n1;
    break;
  }
}
if(n1!=0) return -(400 + sci);
int n2=0;
for(int i=0;i<strlen(s);++i){
  if( s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!' ){
    ++n2;
  }
}
if(n2==0) return -5;
int n3=0;
int n4;
for(int i=0;i<strlen(s);++i){
  if(!(s[i]==64 || s[i]==33 || (s[i]>=35 && s[i] <=37)  || (s[i]>=48 && s[i] <=57)  || (s[i]>=65 && s[i] <=90)  || (s[i]>=95 && s[i] <=122) ))
  {
    ++n3;
     n4=i;
    break;
  }
}
if(n3!=0) return n4;
return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
 string a[num_pwds];
  int b[ num_pwds];
  int nhi=0;
   for( int i=0 ; i< num_pwds ;++i){
       bool kt=true;
       
    for( int j =0; j< nhi ;++j){
       if(arr_pwds[i] == a[j] ){
           kt=false;
           break;
           }
       }
     
      if(kt){
         a[nhi]= arr_pwds[i];
         b[nhi]= i;
         ++nhi;
      }
      
   }
 

   int xh[nhi]={0};
   

  for(int i=0; i<nhi;++i){
    
       for( int j=0 ; j< num_pwds;++j ){
        
       if( a[i] == arr_pwds[j] ) {++xh[i];}
   }
 }
 
 
   
   int max=0;
   for(int i=0; i<nhi;++i){
       if( xh[i]> max) max=xh[i];
   }
   
   int kq;
   int trung=0;
   for( int i=0; i<nhi;++i){
    if(xh[i] == max){
        kq = b[i];
      ++trung;
    }
   }
 
   if( trung >1){
       string c[30];
       int nhi2=0;
       for( int i=0; i<nhi;++i){
           if( xh[i] == max) {
               c[nhi2]= a[i];
               ++nhi2;
           }
       }
     
       int max1=0;
       for( int i=0;i< nhi2 ;++i){
           if(c[i].length() >=max1){
              
               max1= c[i].length();
      }
   }
      string d;
       for( int i=0; i< nhi2 ;++i){
            if( c[i].length() == max1) {d = c[i];
            break; }
       }
       for(int i=0;i< nhi;++i){
           if( a[i] == d) {kq= b[i];
           break;}
       }
       
   }      

  return kq;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
