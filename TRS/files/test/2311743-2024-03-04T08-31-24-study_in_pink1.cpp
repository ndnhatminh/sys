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
int cell(double nu){ return nu+0.999;}
void check_hp( int & exp) {
    if (exp > 666) exp = 666;
    if (exp < 0) exp = 0;
}
void check_exp(int & exp) {
    if (exp > 600) exp = 600;
    if (exp < 0) exp = 0;
}
void check_mon( int & exp) {
    if (exp > 3000) exp = 3000;
    if (exp < 0) exp = 0;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
   if (e1<0||e1>99) return -99;
   if(e1<=3) { 
        switch(e1){
        case 3: exp2 = exp2 + 29 + 45 + 75;
                break;
        case 2: exp2 = exp2 + 75;
                break;
        case 1: exp2 = exp2 + 45;
                break;
        case 0: exp2 = exp2 + 29;
                break;
        default: exp2 = exp2; 
                break;

         }
    
   
    int deci=0; 
    deci =  e1*3 + exp1*7;
    if (deci % 2 == 0) exp1 = cell((float)exp1 + deci/200.0);
    else exp1 = cell((float)exp1 - deci/100.0);
   }
   bool flag=0;
    //th2
    if( e1 > 3 && e1 < 100) {
        if ( e1 >= 4 && e1 <= 19 )    exp2 = cell(exp2 + ( e1/4.0 + 19));
       else if ( e1 > 19 && e1 <=49 ) exp2 = cell(exp2 + ( e1/9.0 + 21));
       else if ( e1 >=50 && e1 <= 65) exp2 = cell(exp2 + ( e1/16.0 + 17));
       else if ( e1 >= 66 && e1 <=79) { 
         exp2 = cell(exp2 + ( e1/4.0 + 19));
         if (exp2 > 200) exp2 = cell(exp2 + ( e1/9.0 + 21));
          
       }
      else if ( e1 >=80 && e1<= 99) {
        exp2 = cell(exp2 + ( e1/4.0 + 19));
        exp2 = cell(exp2 + ( e1/9.0 + 21));
        if (exp2 > 400) {
         exp2 = cell(exp2 + ( e1/16.0 + 17));
         flag = 1;
        }
       
      }
    
    if (flag) exp2= cell(exp2*1.15);
    exp1 = exp1 - e1;
    }
    check_exp(exp1);
    check_exp(exp2); 
    return exp1 + exp2;

}
int hangdonvi( int a){
    if (a<10) return a;
    else {
        int to=a/10 + (a-(a/10)*10);
        if (to>=10) return to - 10;
        else return to;
    }
}
int findsquare(int a){
    
    int n=a, grt=0, lwr=0;
    while (((int)sqrt(n)*(int)sqrt(n))!=n) n++;
    grt=n; 
    n=a;
    while (((int)sqrt(n)*(int)sqrt(n))!=n) n--;
    lwr=n;
    if (grt-a <= a-lwr) {return grt;}
    else return lwr;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2<0||E2>99) return -99;
    // TODO: Complete this function
    float P1=0, P2=0, P3=0, P0=0;
    int S=0;
    int total = 0;
    S=findsquare(EXP1);
   if (S<= EXP1) P1=1;
   else P1=((EXP1*1.0/S)+80.0)/123.0;
    float half= M1/2.0;
    //conduong2
    bool eve=1;
    if (E2%2==0) eve=0;
   do {
    //hp<200 b
    if (HP1<200) {
        HP1=cell(HP1*1.3);
        check_hp( HP1);
        M1= M1 - 150;
        total += 150;
        if ((M1<=0 && eve==0)||(total>half && eve==1)) {
        HP1=cell(HP1*0.83);
        EXP1 = cell(EXP1*1.17);
        check_exp(EXP1);       
        break;
        
        }
    }
    else { 
        HP1=cell(HP1*1.1);
        check_hp(HP1);
        M1=M1-70;
        total += 70;
        if ((M1<=0 && eve==0)||(total>half && eve==1)) {
        HP1=cell(HP1*0.83);
        EXP1 = cell(EXP1*1.17);
        check_exp(EXP1);
        break;
        }
    } // hp<200 e
    //exp<400 b
    if (EXP1<400) {
        M1=M1-200; 
        total+=200;
    }
    else {
        M1=M1-120;
        total+=120;
       
    }
     EXP1 = cell(EXP1*1.13);
     check_exp(EXP1);
    if ((M1<=0 && eve==0)||(total>half && eve==1)) {
        HP1 = cell(HP1*0.83);
        EXP1 = cell(EXP1*1.17);
        check_exp(EXP1);
        break;
     } 
         // exp<400 e
         //nguoi khong da cu b
    if (EXP1<300) {
        M1=M1-100;
        total+=100;
    }
    else {
        M1=M1-120;
        total+=120;
    }
    EXP1 = cell(EXP1*0.9);
     if ((eve==0)||(total>half && eve==1)) {
        HP1=cell(HP1*0.83);
        EXP1 = cell(EXP1*1.17);
        check_exp(EXP1);
        break;
        }
   /*  if (eve==0) {
         HP1=cell(HP1*0.83);
        EXP1 = cell(EXP1*1.17);
        check_exp(EXP1);
        break;
    } */
   } while (total<=half && eve==1);
   //nguoi khong da cu end
    S=findsquare(EXP1);
   if (S<= EXP1) P2=1;
   else P2=(EXP1*1.0/S+80)/123.0;
    int P[10]={32,47,28,79,100,50,22,83,64,11};
    P3=P[hangdonvi(E2)]/100.0;
    P0=(P1+P2+P3)/3;
    if (P0==1) EXP1 = cell(EXP1*0.75);
    else if (P0<0.5) {
        HP1=cell(HP1*0.85);
        EXP1 = cell(EXP1*1.15);
    }
    else if(P0>=0.5) {
        HP1=cell(HP1*0.9);
        EXP1 = cell(EXP1*1.2);
    }
    check_hp(HP1);
    check_mon(M1);
    check_exp(EXP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int baka(int a[10][10], int m, int n){
    int i=m,j =n;
    int flag=(a[i][j]);
    //cheo phai check tren
    while (i>=0 && j<10) {
        if (a[i][j]>=flag) flag = a[i][j];
        j++;
        i--;
    }
    i=m; j=n;
    //check phai duoi
    while (i<10 && j>=0) {
        if (a[i][j]>=flag) flag = a[i][j];
        j--;
        i++;
    }
    //check trai tren
    i=m; j=n;
     while (i>=0 && j>=0) {
        if (a[i][j]>=flag) flag = a[i][j];
        j--;
        i--;
    }
    //
    i=m; j=n;
     while (i<10 && j<10) {
        if (a[i][j]>=flag) flag = a[i][j];
        j++;
        i++;
    }
   
    
    return abs(flag);
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
  if (E3<0||E3>99) return -99;
   int T[10][10],Homes[10][10];//tai thiet lap
    for (int i=0;i<10;i++) {
        for (int j =0; j<10;j++){
            T[i][j]=0;
            Homes[i][j]=0;
        }
    }
    

    //duong di cuar taxi
    for (int i=0;i<10;i++) {
        for (int j =0; j<10;j++){
            T[i][j]=((E3*j)+(i*2))*(i-j);
        }}
    

        //duong di cua homes
    for (int o=0;o<10;o++) {
        for (int u =0; u<10;u++){
            Homes[u][o]=baka(T, o, u);
        }}
   
    int y=0,x=0;
    for (int i=0; i<10; i++){
        for (int j=0; j<10 ; j++){
            if (T[i][j] <-E3) y+=1;
            if (T[i][j] > E3*2) x+=1;
            
        }}
       
     while (x>=10) {
     x = x /10 + x%10;
  }
  

   while (y>=10) {
     y = y /10 + y%10;
  } 
        
     if (Homes[x][y]<abs(T[x][y]))
   {
    HP1=cell(HP1*0.9);
    HP2=cell(HP2*0.9);
    EXP1=cell(EXP1*0.88);
    EXP2=cell(EXP2*0.88);
   }
   else {
    HP1=cell(HP1*1.1);
    HP2=cell(HP2*1.1);
    EXP1=cell(EXP1*1.12);
    EXP2=cell(EXP2*1.12);
   }
 
  check_exp(EXP1);
  check_exp(EXP2);
  check_hp(HP1);
  check_hp(HP2);

    
if (Homes[x][y]<abs(T[x][y])) return T[x][y];
    else return Homes[x][y];
   
   
}

// Task 4


int checkPassword(const char * s, const char * email) {

    string S=s, E=email,se=""; 
    
    for (int i=0; i<E.size() && E[i]!='@';i++){se+=E[i];}//catmail
    int pos=0;
    bool aibiet=0;
    if (S.size()<8) return -1; else if (S.size()>20) return -2;
    if (E[0]=='@') return (-300);
    for (int i=0; i<S.size(); i++){
        
         if (S[i]==se[0]) {
            for (int j=0; j<se.size();j++){
                if((S[i+j]==se[j])&& (j==se.size()-1)) return -(300+i);
                if (S[i+j+1]!=se[j+1]) j= se.size();
            }
        }
      }//   hhh
      aibiet=0;
    for (int i=0; i<S.size(); i++){
            if ((S[i]=='@'||S[i]=='#'||S[i]=='%'||S[i]=='$'||S[i]=='!')) aibiet=1;
            if (S[i]==S[i+1] && S[i+1]== S[i+2]) return -(400+i);// check ki tu lien tiep
     }
     // check ki tu dac biet
    if (!aibiet) return -5;
    for (int i=0; i< S.size(); i++){
        if ((S[i]==32)|| S[i]==34|| (S[i]>=38&& S[i]<=47)|| (S[i]>=58 && S[i]<=63) || (S[i]>=91&& S[i]<=96)||(S[i]>=123&&S[i]<=126)) return i;
    }  
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {// sua lai
    string arr[100];
     int app[100], big=0, pos =0;
   //  cout<< "gtao beinr"<<endl;
    for (int i=0;i<num_pwds;i++){
        arr[i]=arr_pwds[i];
    }
    //cout<< "gans arr"<<endl;
    for (int i=0;i<100;i++){
        app[i]=0;
    }
    int num=num_pwds;
    for (int i=0; i< num;i++){
        for (int j=0;j<num;j++){
            if (arr[i] == arr[j]) app[i]+=1;
        }
    }
  
    for (int i=0; i< num ; i++){
        if (app[i]>=big) {
            big= app[i];
        }

    }
 //    cout<< " tim big"<<endl;
    int longp=0;
    for (int i=0; i< num ; i++){
        if (app[i]==big) { 
            for (int j=i; j<num; j++){
                if (arr[j].size()>=longp && app[j]== big) longp = arr[j].size();
            }
        }
    }
   
    for (int i=0; i<num;i++){
        if (arr[i].size()==longp && app[i]== big) return i;
    }
    return 0;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////