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

int tong2so( int a){
    if (a < 10) {return a;}
    else{
        a = a/10 +a%10;
        if (a<10 ) {return a;}
        else {return a/10 + a%10; }
    }
}
int lt(float x){
    int k = (int)x;
    if ((x - k)>0) {x=x+1;}
    return x;
}

void  fexp( int & n) {
    if (n > 600) { n= 600 ;}
    else if (n< 0 ) {n= 0 ;}
    else { n = lt(n);} // co the xoa
    
}
void fhp( int  & e) {
    if (e > 666) {e= 666;}
    else if (e< 0 ) {e= 0;}
    else {e= lt(e);}
}
void fm( int & e) {
    if (e > 3000) {e= 3000;}
    else if (e< 0 ) {e= 0;}
    else {e= lt(e);}
}
int fe( float e) {
    if (e > 99) {return 1;}
    else if (e< 0 ) {return 1;}
    else return 0;
}
int timsocp(int a){
int m= (int)sqrt(a);
if (((m+1)*(m+1) - a) >( a- (m*m) )) {
    return (m*m) ;
}
else if (((m+1)*(m+1) - a) <( a- (m*m) )) {
    return (m+1)*(m+1) ;
}
else return (m+1)*(m+1);
                     }
////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
///


// Task 1
int firstMeet(int & exp1, int & exp2, int e1){

    if(fe(e1)==0){
        fexp(exp1); fexp(exp2);
        if((e1>=0)&(e1<=3)) {
            if(e1==0) {exp2 += 29 ; fexp(exp2);}
            else if (e1==1) {exp2 += 45 ; fexp(exp2);}
            else if (e1==2) {exp2 += 75; fexp(exp2);}
            else if (e1==3) {exp2 += 149 ; fexp(exp2);}
            int D = e1*3 + exp1*7;
            if ((D%2)==0 ){ exp1=lt(exp1+ (float)D/200) ; fexp(exp1);}
            else {exp1 = lt(exp1- (float)D/100); fexp(exp1);}
        }
        else if((e1>=4)&(e1<=99)){
            if((e1 >= 4)&(e1<=19)){
                exp2 = lt(exp2+ (float)e1/4 +19); fexp(exp2);
            }
            if((e1 >= 20)&(e1<=49)){
                exp2 = lt(exp2 + (float)e1/9 +21); fexp(exp2);
            }
            if((e1 >= 50)&(e1<=65)){
                exp2 = lt(exp2 + (float)e1/16 +17); fexp(exp2);
            }
            if((e1 >= 66)&(e1<=79)){
                exp2 = lt(exp2 +(float)e1/4 +19); fexp(exp2);
                if (exp2 >200) {exp2= lt(exp2+(float)e1/9 +21); fexp(exp2); }
            }
            if((e1 >= 80)&(e1<=99)){
                exp2 = lt(exp2 +(float)e1/4 +19); fexp(exp2);
                exp2 = lt(exp2 +(float)e1/9 +21); fexp(exp2);
                if (exp2 >400) {exp2 = lt(exp2 + (float)e1/16 +17); fexp(exp2);
                    exp2 = lt(exp2+(float)0.15*exp2); fexp(exp2);
}
            }
            exp1 = exp1 - e1; fexp(exp1);
        }
        
        return exp1 + exp2;
    }
    
    
    else return -99;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    
   
    if (fe(E3) == 0){
        int P1, P2 ;
        // TODO: Complete this function
        fhp(HP1); fexp(EXP1); fm(M1);
        //Conduong 1
        if (EXP1 >= timsocp(EXP1)) {
            P1 = 100;
        }
        else {
            P1 =  (((float)EXP1/timsocp(EXP1) + 80) /123) *100;
        }
        
        
        //Conduong 2
        
        int nuasotien = M1/2; int mk = 1;
        int tongtienchi = 0;
   if(M1 != 0)     {
        if ((E3 % 2) != 0){
            while (mk ){//dg1
                if (HP1 < 200) {
                    HP1 =lt( HP1 + (float)0.3*HP1); fhp(HP1);
                    M1 = lt(M1 - 150); fm(M1); tongtienchi += 150;
                    if (tongtienchi > nuasotien) { mk = 0; continue;}
                }
                else {
                    HP1 =lt( HP1 + (float)0.1*HP1); fhp(HP1);
                    M1 = lt(M1 - 70); fm(M1); tongtienchi += 70;
                    if (tongtienchi > nuasotien) { mk = 0; continue;}
                }
                //gd2
                
                if (EXP1 < 400) {
                    M1 = lt(M1 - 200); fm(M1); tongtienchi += 200;
                    EXP1 = lt(EXP1 + (float)0.13*EXP1 ); fm(EXP1);
                    if (tongtienchi > nuasotien) { mk = 0; continue;}
                }
                else {
                    M1 = lt(M1 - 120); fm(M1); tongtienchi += 120;
                    EXP1 = lt(EXP1 + (float)0.13*EXP1 ); fm(EXP1);
                    if (tongtienchi > nuasotien) { mk = 0; continue;}
                }
                
                
                //gd3
                if(EXP1<300) {
                    M1 = lt( M1 - 100); fm(M1); tongtienchi += 100;
                    EXP1 = lt (EXP1 - (float)0.1*EXP1); fexp(EXP1);
                    if (tongtienchi > nuasotien) { mk = 0; continue;}
                }
                else {
                    M1 = lt( M1 - 120); fm(M1); tongtienchi +=120;
                    EXP1 = lt (EXP1 - (float)0.1*EXP1); fexp(EXP1);
                    if (tongtienchi > nuasotien) { mk = 0; continue;}
                    
                }
                
                
            }
            HP1 = lt(HP1 - (float)0.17*HP1); fhp(HP1);
            EXP1 = lt(EXP1 + (float)0.17*EXP1 ); fexp(EXP1);
        }
        else {
            //gd1
            int i=1;
            while (i){
                if (HP1 < 200) {
                    HP1 =lt( HP1 + (float)0.3*HP1); fhp(HP1);
                    M1 = lt(M1 - 150); fm(M1);
                    if (M1 ==0) {i = 0; continue;}
                }
                else {
                    HP1 =lt( HP1 + (float)0.1*HP1); fhp(HP1);
                    M1 = lt(M1 - 70); fm(M1);
                    if (M1 ==0) {i = 0; continue;}
                    
                }
                //gd2
                if (EXP1 < 400) {
                    M1 = lt(M1 - 200); fm(M1);
                    EXP1 = lt(EXP1 + (float)0.13*EXP1 ); fm(EXP1);
                    if (M1 ==0) {i = 0; continue;}
                }
                else {
                    M1 = lt(M1 - 120); fm(M1);
                    EXP1 = lt(EXP1 + (float)0.13*EXP1 ); fm(EXP1);
                    if (M1 ==0) {i = 0; continue;}
                }
                
                
                //gd3
                if(EXP1<300) {
                    M1 = lt( M1 - 100); fm(M1);
                    EXP1 = lt (EXP1 - (float)0.1*EXP1); fexp(EXP1);
                }
                else {
                    M1 = lt( M1 - 120); fm(M1);
                    EXP1 = lt (EXP1 - (float)0.1*EXP1); fexp(EXP1);
                    
                }
               
                i=0;
            }
             HP1 = lt(HP1 - (float)0.17*HP1); fhp(HP1);
            EXP1 = lt(EXP1 + (float)0.17*EXP1 ); fexp(EXP1);
            }
    }
   else{
       HP1 = lt(HP1 - (float)0.17*HP1); fhp(HP1);
       EXP1 = lt(EXP1 + (float)0.17*EXP1 ); fexp(EXP1); }
           
        if (EXP1 >= timsocp(EXP1)) {
            P2 = 100;
        }
        else {P2 = ( ( (float)(EXP1)/timsocp(EXP1) + 80 )/123) *100;
        }
        // con duong 03
        int mang[10]= {32,47,28,79,100,50,22,83,64,11};
        int i;
        if (E3<10) {i = E3;}
        else if (E3 >=10) {
            int tong = E3/10 + E3%10;
            i =tong%10;
            
        }
        if ( (P1 ==100) & (P2 ==100) & (mang[i] ==100 )) {
            EXP1 = lt(EXP1 - (float)0.25*EXP1 ); fexp(EXP1);
        }
        else {
            int P;
            P = lt((P1 + P2 +mang[i] )/3);
            if (P < 50){
                HP1 = lt(HP1 - (float)0.15*HP1); fhp(HP1);
                EXP1 = lt(EXP1 + (float)0.15*EXP1); fexp(EXP1);
                
            }
            else {
                HP1 = lt(HP1 - (float)0.1*HP1); fhp(HP1);
                EXP1 = lt(EXP1 + (float)0.2*EXP1); fexp(EXP1);
            }
        }
        
        return HP1 + EXP1 + M1;}
    
    else return -99 ;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {

    if(fe(E3) ==0){
        fexp(EXP1); fexp(EXP2); fhp(HP1); fhp(HP2);
        // TODO: Complete this function
        int matran[10][10] = {};
        for (int i=0; i<10; i++ ){
            for (int j=0; j<10 ; j++){
                matran[i][j] = ((E3 * j) + (i*2))*(i-j);
            }
        }
        int igapnhau=0, jgapnhau=0;
        for (int i=0; i<10; i++){
            for (int j=0 ; j<10; j++){
                if (matran[i][j] > (E3*2)){ igapnhau+= 1;}
                if (matran[i][j] < (-E3)){ jgapnhau+= 1;}
            }
            
        }
        igapnhau = tong2so(igapnhau); jgapnhau=tong2so(jgapnhau);
        
        int cheotraimax=matran[igapnhau][jgapnhau];  int cheophaimax=matran[igapnhau][jgapnhau],cheomax =0;
        //  int soptdc_phai = 0, soptdc_trai =0;
        for (int i = 0; i <10 ; i++){
            if ( ((igapnhau + i)==9) || ((jgapnhau +i) ==9) ) {
                if ( matran[igapnhau+i][jgapnhau +i] > cheophaimax ) {cheophaimax =matran[igapnhau+i][jgapnhau +i]; }
                break;
            }
            else{
                if ( matran[igapnhau+i][jgapnhau +i] > cheophaimax ) {cheophaimax =matran[igapnhau+i][jgapnhau +i]; }
                
            }}
        for (int i = 0; i<10 ; i++){
            if ( ((igapnhau - i)==0) || ((jgapnhau -i) ==0) ){
                if ( matran[igapnhau-i][jgapnhau -i] > cheophaimax ) {cheophaimax =matran[igapnhau-i][jgapnhau -i]; }
                
                break;}
            else {
                if (matran[igapnhau-i][jgapnhau -i] > cheophaimax ) {cheophaimax =matran[igapnhau-i][jgapnhau -i];
                }}}
                    
                
        for (int i = 0; i <10 ; i++){
            if ( ((igapnhau + i)==9) || ((jgapnhau -i) ==0) ) {
                if ( matran[igapnhau+i][jgapnhau -i] > cheotraimax ) {cheotraimax =matran[igapnhau+i][jgapnhau -i];}
                
                break;
            }else{
                if ( matran[igapnhau+i][jgapnhau -i] > cheotraimax ) {cheotraimax =matran[igapnhau+i][jgapnhau -i];}
                
            }}
        for (int i = 0; i<10 ; i++){
            if ( ((igapnhau - i)==0) || ((jgapnhau +i) ==9) ) {
                if ( matran[igapnhau-i][jgapnhau +i] > cheotraimax ) {cheotraimax =matran[igapnhau-i][jgapnhau +i] ;}
                break;
            }
            else{
                if ( matran[igapnhau-i][jgapnhau +i] > cheotraimax ) {cheotraimax =matran[igapnhau-i][jgapnhau +i] ;}
                
            }}        if (cheophaimax > cheotraimax) { cheomax = cheophaimax;}
        else cheomax = cheotraimax;
        if  ( abs(matran[igapnhau][jgapnhau])  > abs(cheomax) ) {
            EXP1 = lt(EXP1 - (float)0.12*EXP1 ); fexp(EXP1);
                        HP1 = lt(HP1 - (float)0.1*HP1); fhp(HP1);
                        EXP2 = lt(EXP2 - (float)0.12*EXP2 ); fexp(EXP2);
                        HP2 = lt(HP2 - (float)0.1*HP2); fhp(HP2);
                        return matran[igapnhau][jgapnhau];
                    }
                    else {
                        EXP1 = lt(EXP1 + (float)0.12*EXP1 ); fexp(EXP1);
                        HP1 = lt(HP1 + (float)0.1*HP1); fhp(HP1);
                        EXP2 = lt(EXP2 + (float)0.12*EXP2 ); fexp(EXP2);
                        HP2 = lt(HP2 + (float)0.1*HP2); fhp(HP2);
                        return cheomax;
                    }
                }
                else return -99;}

            // Task 4
            int checkPassword(const char * s, const char * email) {
                string se;
                string s1 = (string)s;
                string email1 = (string)email;
                for (int i=0; i< email1.length(); i++ ){
                    if (email1[i] == '@') {break;}
                     se+= email1[i];
                }
                int thu1 =0, thu2 =0, cohaykhong = 0; int position=0; int thu3=0;
                if(s1 == se) {cohaykhong = 1; position=0;}
                else{
                for (int i=0; i< s1.length()+1;i++ ){
                    if (thu1 == se.length() ){cohaykhong =1; break; }
                    if (s1[i] == se[i - thu2]) {
                        thu1 +=1 ; position =i; }
                    else {if(s1[i] == se[thu3]) {thu1 =1; thu2 =i;
                    }
                        else{ thu1 =0 ; thu2=i+1; }}
                }
                position=position-se.length()+1;}
                int cohaykhong2=0; int vitri ;
                for (int i =0 ; i< s1.length() -2; i++ ){
                    if ((s1[i] == s1[i+1])&(s1[i] == s1[i+2])){
                        vitri = i; cohaykhong2 =1 ; break;
                    }
                }
                int cohaykhong3=0;
                for (int i=0; i<s1.length() ; i++){
                    if ((s1[i] == '@')||(s1[i] == '#')||(s1[i] == '%')||(s1[i] == '$')||(s1[i] == '!')){cohaykhong3 =1; break;}
                }
                if (s1.length() < 8 ) return -1;
                if (s1.length() > 20 ) return -2;
                if (cohaykhong) return -(300 + position);
                if (cohaykhong2) return -(400 + vitri);
                if (!cohaykhong3) return -5;
                int vitri3=0; int cohaykhong4=0;
                for (int i=0; i<s1.length(); i++){
                    if ((s1[i] ==34)||(s1[i] == 38)||(((s1[i])>=39)&(s1[i]<=47))||((s1[i]>=58)&(s1[i]<=63))||((s1[i]>=91)&(s1[i]<=96))||((s1[i]>=123)&(s1[i]<=127)))
                   { vitri3 = i; cohaykhong4=1;
                    break;}
                }
                if(cohaykhong4) return vitri3;
                return -10;
            }

            // Task 5
    int findCorrectPassword(const char * arr_pwds[], int num_pwds) {


    string mangcopy[60] ={};
    for (int i=0; i<60; i++){
        if (i == num_pwds) {break;}
        mangcopy[i] = (string)arr_pwds[i] ;
                }
    
   string luu[30]={};
    int dem[30]={};
    luu[0]= mangcopy[0];
    int vitri=1;
    dem[0]=1;
       int vitrithuc[30]={} ;
       vitrithuc[0]=0;
    for (int j =1 ; j< num_pwds; j++){
     int   k =0;
        for (int i =0; i< j ; i++){
             if (mangcopy[j] == luu[i]) {
                 dem[i] +=1; k=i+1; break;
            }
        }
        if( !k ) {luu[vitri]  = mangcopy[j]; vitrithuc[vitri]=j; dem[vitri]+=1; vitri+=1;  }
    }
        
    int max = 0; int vitri1 = 0; int dodaichuoimax = 0;
        for (int i =0; i< 30; i++){
            if (dem[i] >= max){
                if(dem[i]==max){
                    if (luu[i].length() > dodaichuoimax ){
                        dodaichuoimax = luu[i].length(); max = dem[i]; vitri1 = i;}
                }
                
                
                else {dodaichuoimax = luu[i].length(); max = dem[i]; vitri1 = i; }}
            
            
        }
        
        
        
        
        
        
        
     /* for (int i=0;i<30;i++){
        if (luu[vitri1] == mangcopy[i]) {return i;}
    }*/
       /* for(int i=0; i<30; i++){
            cout<<luu[i]<<" ";
        }
        cout<<endl;
        for(int i=0; i<30; i++){
            cout<<dem[i]<<" ";
        }
        cout<<endl;
       for(int i=0; i<30; i++){
            cout<<vitrithuc[i]<<" ";
        }

  //      cout<<max;
      //  cout<<luu[vitri1].length(); */
    return vitrithuc[vitri1];

}


            ////////////////////////////////////////////////
            /// END OF STUDENT'S ANSWER
            ////////////////////////////////////////////////
