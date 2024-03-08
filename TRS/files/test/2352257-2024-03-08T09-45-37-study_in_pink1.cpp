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
        if (e1<0 || e1>99) {cout << -99; return -99;}
        else {
        if (exp1>600 || exp1 <0) {
                if( exp1 >600) exp1=600; else if( exp1 <0) exp1 =0;
                
            }

            if (exp2>600 || exp2 <0) {
                if (exp2 >600) exp2=600; else if (exp2 <0) exp2 =0;
                
            }

        if (e1 >= 0 && e1 <= 3) {
            if (e1 == 0) exp2 = exp2 + 29;
            else if (e1 == 1) exp2 = exp2 + 45;
            else if (e1 == 2) exp2 = exp2 + 75;
            else if (e1 == 3) exp2 = exp2 + 29 + 45 + 75;

            D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0) exp1 = ceil(exp1 + D/200.0);  else exp1=ceil(exp1 - D/100.0);
        }

        if (e1 > 3 && e1 <= 99) { 
            if (e1 >= 4 && e1 <= 19) exp2 = ceil(exp2 + (e1 / 4.0 + 19));
            else if (e1 >= 20 && e1 <= 49) exp2 = ceil(exp2 + (e1 / 9.0 + 21));
            else if (e1 >= 50 && e1 <= 65) exp2 = ceil(exp2 + (e1 / 16.0 + 17));
            else if (e1 >= 66 && e1 <= 79) { 
                exp2 = ceil(exp2 + (e1/4.0 + 19));
                if (exp2 > 200) exp2 = ceil(exp2 + (e1 / 9.0 + 21)); 
            }
            else if (e1 >= 80 && e1 < 100) { 
                exp2 = ceil(exp2 + (e1 / 4.0 + 19));
                exp2 = ceil(exp2 + (e1 / 9.0 + 21));
                if (exp2 > 400) {exp2 = ceil(exp2 + (e1 / 16.0 + 17));
                                 exp2 = ceil (exp2*1.15);   
                }
            }
            exp1= exp1 - e1 ;}
            

            if (exp1>600 || exp1 <0) {
                if( exp1 >600) exp1=600; else if( exp1 <0) exp1 =0;
                
            }

            if (exp2>600 || exp2 <0) {
                if (exp2 >600) exp2=600; else if (exp2 <0) exp2 =0;
                
            }

            

        return exp1 + exp2;
        };
    }
    

// Task 2
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
        int S=0, c, d, CP= 0,CI;
        double p1,p2,p3;
        if (E2<0 || E2>99) {cout << -99; return -99;}
        else {
        if (EXP1>600 || EXP1 <0) {
                if( EXP1 >600) EXP1=600; else if( EXP1 <0) EXP1 =0;
                
            }

        if (HP1<0||HP1>666){
            if (HP1< 0 ) HP1= 0; else if (HP1>666) HP1=666;
        }

        if (M1<0||M1>3000){
            if (M1< 0 ) M1= 0; else if (M1>3000) M1=3000;

        }

        //path 1
        c= ceil (sqrt(EXP1)); c=pow(c,2);
        d= floor (sqrt(EXP1));d=pow(d,2);
        if ((c-EXP1)<=(EXP1-d)) S=c; else S=d;
        if (EXP1 >= S)  p1=1; else p1= ((EXP1/S) + 80.0)/123.0;

        //path 2
            CI =M1;
        if (E2%2==1) {

        while (CP<=(CI*0.5)){
            //2.1
        if (HP1 < 200) {HP1=ceil(1.0 * HP1 + HP1*0.3);
                        M1=M1 -150;
                        CP=CP+150;
            

        } else if (HP1>=200) {HP1=ceil(1.0 * HP1 + HP1*0.1);
                              M1=M1-70;
                              CP=CP+70;

        }
        if (HP1<0||HP1>666){
            if (HP1< 0 ) HP1= 0; else if (HP1>666) HP1=666;
        }
if (CP>(CI*0.5)) break;
            //2.2
        if (EXP1 < 400) {M1=M1-200; CP=CP+200;} else {M1= M1-120;
                                                     CP=CP+120;}
        EXP1=ceil(EXP1 * 1.00 + EXP1*0.13);
        if (EXP1>600 || EXP1 <0) {
                if( EXP1 >600) EXP1=600; else if( EXP1 <0) EXP1 =0;
                
            }
        
if (CP>(CI*0.5)) break;

            //2.3
        if (EXP1 <300 ) {M1=M1 -100; CP=CP+100;} else {M1=M1-120;
                                                      CP=CP+120;}
        EXP1=ceil(EXP1*0.9);
        if (EXP1>600 || EXP1 <0) {
                if( EXP1 >600) EXP1=600; else if( EXP1 <0) EXP1 =0;
                
            }
        } 
        } 
        //E2 la so chan
        else {if (M1>0) {
            //2.1
            if (HP1 < 200) {HP1=ceil(1.0*HP1+HP1*0.3);
                            M1=M1 -150;
            
        } else if (HP1>=200) {HP1=ceil(HP1*1.0+HP1*0.1);
                              M1=M1-70;

        }
        if (HP1<0||HP1>666){
            if (HP1< 0 ) HP1= 0; else if (HP1>666) HP1=666;
        }}

            //2.2
            if (M1>0) {
        if (EXP1 < 400) {M1=M1-200;} else {M1= M1-120;}
        EXP1=ceil(EXP1 * 1.00 + EXP1*0.13);
        if (EXP1>600 || EXP1 <0) {
                if( EXP1 >600) EXP1=600; else if( EXP1 <0) EXP1 =0;
                
            }}
        

            //2.3
            if (M1>0){
        if (EXP1 <300 ) {M1=M1 -100;} else {M1=M1-120;}
        EXP1=ceil(EXP1*0.9);
        if (EXP1>600 || EXP1 <0) {
                if( EXP1 >600) EXP1=600; else if( EXP1 <0) EXP1 =0;
                
            }}

        }

    HP1=ceil(HP1*0.83); if (HP1<0||HP1>666){
            if (HP1< 0 ) HP1= 0; else if (HP1>666) HP1=666;}
    EXP1=ceil(EXP1*1.00 + EXP1*0.17);if (EXP1>600 || EXP1 <0) {
                if( EXP1 >600) EXP1=600; else if( EXP1 <0) EXP1 =0;}

        c= ceil (sqrt(EXP1)); c=pow(c,2);
        d= floor (sqrt(EXP1));d=pow(d,2);
        if ((c-EXP1)<=(EXP1-d)) S=c; else S=d;
        if (EXP1 >= S)  p2=1; else p2= ((EXP1/S) + 80.0)/123.0;

        


//path3
int i=0;
double k;
int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

if (E2<10) i=E2; else{ i=floor(E2/10) + E2%10;
                        i=i%10;   
                            }

p3= P[i]*0.01;


//conclusion
if(p1==1 && p2==1 && p3==1) EXP1=ceil(EXP1*0.75);
    else {k=(p1+p2+p3)/3.0;
if (k>=0.5) {HP1=ceil(HP1*0.9); EXP1=ceil(EXP1*1.0 +EXP1*0.2);} else {
                        HP1=ceil(HP1*0.85);
                        EXP1=ceil(EXP1*1.00 + EXP1*0.15);
} }
if (EXP1>600 || EXP1 <0) {
                if( EXP1 >600) EXP1=600; else if( EXP1 <0) EXP1 =0;
                
            }
if (HP1<0||HP1>666){
            if (HP1< 0 ) HP1= 0; else if (HP1>666) HP1=666;
        }
if (M1<0||M1>3000){
            if (M1< 0 ) M1= 0; else if (M1>3000) M1=3000;}

        return HP1 + EXP1 + M1;
        }}



// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int TS,DS;
    //Mang
     int map[10][10] = {0};
     for (int i = 0; i < 10; i=i+1) {
        for (int j = 0; j < 10; j=j+1) {
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    //Vi tri
        int h=0, k=0;
     for (int i = 0; i < 10; i=i+1) {
        for (int j = 0; j < 10; j=j+1) {
           if (map[i][j] > (E3*2)) h=h+1 ; else if (map[i][j]<-E3) k=k+1;
        }
    }

    if (h>9) h= h/10 + h%10;
    if (k>9) k= k/10 + k%10;/*VI tri map[h][k]*/
    TS=map[h][k];

    //Score tham tu
    int m,n, cheotrai, cheophai;
        //cheotrai
    if (h<k) {
            n=k-h;
            m=0;
            cheotrai=map[m][n];
            while (n < 10 ){
                m=m+1;
                n=n+1;
                cheotrai=max(cheotrai,map[m][n]);}

            m=h-(9-k);
            n=9;
            cheotrai=map[m][n];
            while (m<10){
                m=m+1;
                n=n-1;
                cheotrai=max(cheotrai,map[m][n]);
                
                
        
    }}
       else if (h>k){
                m=h-k;
                n=0;
                cheotrai=map[m][n];
            while (m < 10 ){
                m=m+1;
                n=n+1;
                cheotrai=max(cheotrai,map[m][n]);

    }   
    
                n=k-(9-h);
                m=9;
                cheotrai=map[m][n];
            while (n<10){
                n=n+1;
                m=m-1;
                cheotrai=max(cheotrai,map[m][n]);

    }} else if (h=k){
            m=0; n=0;
            cheotrai=map[m][n];
            while (m < 10 ){
                m=m+1;
                n=n+1;
                cheotrai=max(cheotrai,map[m][n]);
    }
            m=9; n=0;
            cheotrai=map[m][n];
            while(n<10){
            m=m-1; n=n+1;
                cheotrai=max(cheotrai,map[m][n]);
    
    }
    };

    DS=max(cheotrai,cheophai);

    /*
    if (h<k) {
            m=h-(9-k);
            n=9;
            cheotrai=map[m][n];
            while (m<10){
                m=m+1;
                n=n-1
                cheotrai=max(cheotrai,map[m][n]);
                
        
    };
    }   ;else if (h>k){
                n=k-(9-h);
                m=9;
                cheotrai=map[m][n];
            while (n<10){
                n=n+1;
                m=m-1;
                cheotrai=max(cheotrai,map[m][n]);
    }}   else if (h=k){
            m=9; n=0;
            cheotrai=map[m][n];
           while(n<10){
            m=m-1; n=n+1;
                cheotrai=max(cheotrai,map[m][n]);
    }}*/

    

    //So Sanh
    if (abs(TS)<DS) {EXP1=EXP1*1.12;
                     HP1=HP1*1.1;
                     EXP2=EXP2*1.12;
                     HP2=HP2*1.1;   
            return DS;
    
    } else {        EXP1=EXP1*0.88;
                     HP1=HP1*0.9;
                     EXP2=EXP2*0.88;
                     HP2=HP2*0.9;   
            return TS;
    
    } 


    
    
}

// Task 4
int checkPassword(const string & s, const string & email) {
    // TODO: Complete this function

    //Do dai
    if (s.length() < 8) return -1;  
    else if (s.length() > 20) return -2;

    //Tim chuoi se
    string se;
     se = email.substr(0, email.find('@'));

    //Tìm se trong s
    size_t p= s.find(se);
    if (p !=string::npos) return -(300 + p);

    //Tim 2 ki hieu lien tiep
     for (int i = 0; i < (s.length() - 2); i++) {
    if ((s[i] == s[i + 1]) && (s[i + 1] == s[i + 2])) {
      return -(400 + static_cast<int>(i) + 1);
    }
  


    //Tìm ky hieu dac biet
    int dai= s.length();
    for (int i=0; i< dai; i=i+1){
        if (s[i] != '@' && s[i] !=  '#' && s[i] != '%' && s[i] !=  '$' && s[i] !=  '!') {return -5; break;}

    } }

    //Ky tu hop ly
     for (size_t i = 0; i < s.length(); ++i) {
    char kytu = s[i];
    if (!((kytu >= '0' && kytu <= '9') || (kytu >= 'a' && kytu <= 'z') || (kytu >= 'A' && kytu <= 'Z') ||
          (kytu == '@' || kytu == '#' || kytu == '%' || kytu == '$' || kytu == '!'))) {
        return static_cast<int>(i);
    }
}


    return -10; 

}

// Task 5
    int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
        // TODO: Complete this function
        int f[40]={0};
        int Maxtansuat=0, maxdodai=0;
        int position=0;
        for (int i = 0; i < num_pwds; ++i) {
    for (int n = i + 1; n < num_pwds; ++n) {
                if(strcmp(arr_pwds[i],arr_pwds[n])==0){
                    f[i]=f[i]+1;
                }

            }
            if (f[i]>Maxtansuat|| (f[i]==Maxtansuat && strlen(arr_pwds[i])>=maxdodai )){
                Maxtansuat=f[i];    maxdodai=strlen(arr_pwds[i]);
                position= i;


        }


        }




        return position;
    }

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////