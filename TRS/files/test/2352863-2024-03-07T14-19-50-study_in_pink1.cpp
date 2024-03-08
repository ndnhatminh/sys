#include <study_in_pink1.h>

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & e1,
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
            >> e1 >> E2 >> E3;
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
    if (exp1>600) {exp1=600;}
    else if (exp2>600) {exp2=600;}
    if (exp1<0) {exp1=0;}
    else if (exp2<0) {exp2=0;}

    int D;
        
        if (e1>=0 && e1<=3)
            { 
            if (e1==0) {exp2 += 29; }
            else if (e1==1) {exp2 += 45;}
            else if (e1==2) {exp2 += 75;}
            else {exp2 += 149;}
            D=e1*3+exp1*7;

            if (D%2==0) { exp1 = ceil(exp1 + D/200);}
            else {exp1 = ceil(exp1 - D/100);}
            
            }
        else if(e1>3 && e1<=99)
            {
            if (e1>3 && e1<=19) { exp2 = ceil(exp2 + (float)e1/4 + 19);}
             else if(e1>=20 && e1<=49) { exp2 = ceil(exp2 + (float)e1/9 + 21);}
             else if(e1>=50 && e1<=65) { exp2 = ceil(exp2 + (float)e1/16 + 17);}
             else if(e1>=66 && e1<=79) 
                {
                    exp2 = ceil(exp2 + (float)e1/4 + 19);
                    if(exp2>200) {exp2 = ceil(exp2 + (float)e1/9 + 21);}  
                }
            else { exp2 = ceil(exp2 + (float)e1/4 + 19);
                   exp2 = ceil(exp2 + (float)e1/9 + 21);
                   if (exp2>400) 
                    { 
                        exp2 = ceil(exp2 + (float)e1/16 + 17);
                        exp2 = ceil((float)exp2*1.15);
                    }
                }
                exp1 = exp1 - e1;
                
                if (exp1>600) {exp1=600;}
                else if (exp2>600) {exp2=600;}
                if (exp1<0) {exp1=0;}
                else if (exp2<0) {exp2=0;}
            
            }
        else { exp1=0; exp2=-99;}
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
        float a1, a2;
        int b1, b2;
        int S1, S2;
        float P1;
        float P2;
        float P3;
        float P;
        

if (HP1<0) {HP1=0;}
else if (HP1>600) {HP1=600;}
if (EXP1<0) {EXP1=0;}
else if (EXP1>600) {EXP1=600;}
if (M1<0) {M1=0;}
else if (M1>3000) {M1=3000;}

if (E2>=0 && E2<=99){
        //Road 1
        a1 = sqrt(EXP1);
        b1 = round(a1);
        S1 = b1*b1;
        if (EXP1 >= S1) {P1 = 1;}
        else { P1 = ((float)EXP1/S1 + 80)/123;}
        
        int Q = M1;
        int n=0;

        if (HP1<0) {HP1=0;}
        else if (HP1>600) {HP1=600;}
        if (EXP1<0) {EXP1=0;}
        else if (EXP1>600) {EXP1=600;}
        if (M1<0) {M1=0;}
        else if (M1>3000) {M1=3000;}

        //Road 2
            //TH1
        if (E2%2==1)
        {
            for ( int i=0;true;i++)
            {
                if (HP1 < 200) 
                {
                    HP1 = ceil((float)HP1*1.3);
                    M1 = M1 - 150;
                }
                else
                {
                    HP1 = ceil((float)HP1*1.1);
                    M1 = M1 -70;
                } 

                if (HP1<0) {HP1=0;}
                else if (HP1>600) {HP1=600;}
                if (EXP1<0) {EXP1=0;}
                else if (EXP1>600) {EXP1=600;}
                if (M1<0) {M1=0;}
                else if (M1>3000) {M1=3000;}

                if (Q-M1>0.5*Q) break;

                if (EXP1 < 400) {M1 = M1 - 200;}
                else {M1 = M1 - 120;}
                EXP1 = ceil((float)EXP1*1.13);
                
                if (HP1<0) {HP1=0;}
                else if (HP1>600) {HP1=600;}
                if (EXP1<0) {EXP1=0;}
                else if (EXP1>600) {EXP1=600;}
                if (M1<0) {M1=0;}
                else if (M1>3000) {M1=3000;}

                if (Q-M1>0.5*Q) break;

                if (EXP1 < 300) {M1 = M1 - 100;}
                else {M1 = M1 - 120;}
                EXP1 = ceil((float)EXP1*0.9); 
                
                if (HP1<0) {HP1=0;}
                else if (HP1>600) {HP1=600;}
                if (EXP1<0) {EXP1=0;}
                else if (EXP1>600) {EXP1=600;}
                if (M1<0) {M1=0;}
                else if (M1>3000) {M1=3000;}

                if (Q-M1>0.5*Q) break;
            }
            HP1 = ceil(HP1*0.83);
            EXP1 = ceil(EXP1*1.17);
        
        }
            //TH2
        else {
            if (HP1 < 200) 
                {
                    HP1 = ceil((float)HP1*1.3);
                    M1 = M1 - 150;
                }
                else
                {
                    HP1 = ceil((float)HP1*1.1);
                    M1 = M1 -70;
                } 

                if (HP1<0) {HP1=0;}
                else if (HP1>600) {HP1=600;}
                if (EXP1<0) {EXP1=0;}
                else if (EXP1>600) {EXP1=600;}
                if (M1<0) {M1=0;}
                else if (M1>3000) {M1=3000;}

                if (M1<=0) goto end;

                if (EXP1 < 400) {M1 = M1 - 200;}
                else {M1 = M1 - 120;}
                EXP1 = ceil((float)EXP1*1.13);

                if (HP1<0) {HP1=0;}
                else if (HP1>600) {HP1=600;}
                if (EXP1<0) {EXP1=0;}
                else if (EXP1>600) {EXP1=600;}
                if (M1<0) {M1=0;}
                else if (M1>3000) {M1=3000;}

                if (M1<=0) goto end;
                
                if (EXP1 < 300) {M1 = M1 - 100;}
                else {M1 = M1 - 120;}
                EXP1 = ceil((float)EXP1*0.9); 

                if (HP1<0) {HP1=0;}
                else if (HP1>600) {HP1=600;}
                if (EXP1<0) {EXP1=0;}
                else if (EXP1>600) {EXP1=600;}
                if (M1<0) {M1=0;}
                else if (M1>3000) {M1=3000;}

                if (M1<=0) goto end;

            end: 
            HP1 = ceil((float)HP1*0.83);
            EXP1 = ceil((float)EXP1*1.17);
            
        }
        a2 = sqrt(EXP1);
        b2 = round(a2);
        S2 = b2*b2;
        if (EXP1 >= S2) {P2 = 1;}
        else { P2 = (float)(EXP1/S2 + 80)/123;}

        if (HP1<0) {HP1=0;}
        else if (HP1>600) {HP1=600;}
        if (EXP1<0) {EXP1=0;}
        else if (EXP1>600) {EXP1=600;}
        if (M1<0) {M1=0;}
        else if (M1>3000) {M1=3000;}
        
    
        //Road 3
        float PX[10] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
        int u, v, i;
        if (E2<10) {E2 = i;}
        else 
        {
            v = E2%10;
            u = (E2-v)/10;
            i = (u+v)%10;
            
        }
        P3 = PX[i];
        
        //Final
        if (P1==1 && P2==1 && P3==1) {EXP1 = EXP1*0.75;}
        else {
            P = (P1+P2+P3)/3;
            if (P<0.5) {
                HP1 = ceil((float)HP1*0.85);
                EXP1 = ceil((float)EXP1*1.15);
                }        
            else {
                HP1 = ceil((float)HP1*0.9);
                EXP1 = ceil((float)EXP1*1.2);
            }
        }

            if (HP1<0) {HP1=0;}
            else if (HP1>600) {HP1=600;}
            if (EXP1<0) {EXP1=0;}
            else if (EXP1>600) {EXP1=600;}
            if (M1<0) {M1=0;}
            else if (M1>3000) {M1=3000;}
}
else {HP1=-99; EXP1=0; M1=0;}

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

            if (HP1<0) {HP1=0;}
            else if (HP1>600) {HP1=600;}
            if (EXP1<0) {EXP1=0;}
            else if (EXP1>600) {EXP1=600;}
            if (HP2<0) {HP2=0;}
            else if (HP2>600) {HP2=600;}
            if (EXP2<0) {EXP2=0;}
            else if (EXP2>600) {EXP2=600;}

    int r;
    if (E3>=0 && E3<=99){
    int T[10][10];
        int M[10][10];
        int N[10][10];
        int  a;
        int  b;
        a=0; b=0;
        

        //Taxi
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                T[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                M[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                N[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }

        //PPL
        for (int n=9; n>=0; n--){
            for (int a=0; a<=n; a++) {
                if (M[a+9-n][a] > M[9-n][0]) { M[9-n][0]=T[a+9-n][a]+1-1;}
            } 
        }

        for (int n=9; n>=0; n--){
            for (int a=0; a<=n; a++) {
                M[a+9-n][a] = M[9-n][0] ;
            }
        }

        for (int n=9; n>=0; n--){
            for (int a=0; a<=n; a++) {
                if (M[a][a+9-n] > M[0][9-n]) {M[0][9-n]=T[a][a+9-n]+1-1;}
            } 
        }

        for (int n=9; n>=0; n--){
            for (int a=0; a<=n; a++) {
                M[a][a+9-n] = M[0][9-n]; 
            }
        }

        /////
        for (int n=9; n>=0; n--){
            for (int a=0; a<=n; a++) {
                if (N[a][n-a] > N[n][0]) {N[n][0]=T[a][n-a]+1-1 ;}
            }
        }

        for (int n=9; n>=0; n--){
            for (int a=0; a<=n; a++) {
                 N[a][n-a] = N[n][0];
            }
        }

        for (int n=9; n>=0; n--){
            for (int a=0; a<=n; a++) {
                if (N[a+9-n][9-a] > N[9-n][9]) {N[9-n][9]=T[a+9-n][9-a]+1-1;}
            } 
        }

        for (int n=9; n>=0; n--){
            for (int a=0; a<=n; a++) {
                N[a+9-n][9-a] = N[9-n][9];
            }
        }

        //Max
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (M[i][j]<N[i][j]) { M[i][j] = N[i][j];}
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (M[i][j]<0) { M[i][j] = abs(M[i][j]);}
            }
        }
        //

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (T[i][j] > E3*2) {a++;}
                else if (T[i][j] < -E3) {b++;}
            }
        }

        if (a>9) { 
            a = int(a/10)+(a%10);
            if (a>9) { a = int(a/10)+(a%10);}
                }
        if (b>9) { 
            b = int(b/10)+(b%10);
            if (b>9) { b = int(b/10)+(b%10);}
            }
        
        if (M[a][b]> abs(T[a][b])) { 
            EXP1 = EXP1*1.12 + 0.999999999;
            HP1 = HP1*1.1 + 0.999999999;
            EXP2 = EXP2*1.12 + 0.999999999;
            HP2 = HP2*1.1 + 0.999999999;
            r=M[a][b];        }
        else {
            EXP1 = EXP1*0.88 + 0.999999999;
            HP1 = HP1*0.9 + 0.999999999;
            EXP2 = EXP2*0.88 + 0.999999999;
            HP2 = HP2*0.9 + 0.999999999;
            r=T[a][b];
             }
        if (HP1<0) {HP1=0;}
            else if (HP1>600) {HP1=600;}
            if (EXP1<0) {EXP1=0;}
            else if (EXP1>600) {EXP1=600;}
            if (HP2<0) {HP2=0;}
            else if (HP2>600) {HP2=600;}
            if (EXP2<0) {EXP2=0;}
            else if (EXP2>600) {EXP2=600;}
    }
    else {r=-99;}
    return r;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
        int r;
        int count=0;
        int sci=-1;
        int wrong=-1;
        int num;
        int sei=-1;
        int t=0;
        
        for (int i=0; i<=strlen(email);i++)
            {
            if (email[i] != '@') {t=i;}
            else break;}

        char se[t];

        for (int i=0; i<=strlen(email);i++)
            {
            if (email[i] != '@') {se[i] = email[i];}
            else break;
            }
            
         for (int i=0;i<=strlen(s)-1;i++){
            num=0;
                for (int j=0;j<=strlen(se)-1;j++){
                if (s[i+j]==se[j]) num++;
            }
            if (num==strlen(se)) {sei=i; break;}
        }    
       

        for (int i = 0; i<strlen(s)-1; i++){
                if (s[i]==s[i+1] && s[i+1]==s[i+2]) {sci=i;}
            }
        for (int i = 0; i<21; i++){
                if (s[i]=='!' || s[i]=='@' || s[i]=='#' || s[i]=='$' || s[i]=='%') {count++;}
            }

        for (int i = 0; i<21; i++){
            if (s[i]==char{32} || s[i]==char{34} || s[i]==char{38} || s[i]==char{39} || s[i]==char{40} || s[i]==char{41} || s[i]==char{42} || s[i]==char{43} || s[i]==char{44} || s[i]==char{45} || s[i]==char{46} || s[i]==char{47} || s[i]==char{58} ||s[i]==char{59} || s[i]==char{60} || s[i]==char{61} || s[i]==char{62} || s[i]==char{63} ||s[i]==char{64} || s[i]==char{91} ||s[i]==char{92} || s[i]==char{93} || s[i]==char{94} || s[i]==char{95} || s[i]==char{96} || s[i]==char{123} || s[i]==char{124} || s[i]==char{125} || s[i]==char{126} )
            {wrong = i;}
        }

        
        if (strlen(s) < 8) {r=-1;}
        
         else if (strlen(s) > 20) {r=-2;}

        else if(sei > -1) {r = -300-sei;}
         else if(sci != -1) {r=-400-sci;}
            
         else if(count==0) {r=-5;}

         else if(wrong != -1) {r=wrong;}
        
        else {r=-10;}

    return r;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
        string b[num_pwds];
        
    for (int i=0;i<num_pwds;i++){
        b[i]=arr_pwds[i];
    }
    
    int num[num_pwds];
        int max;
        int count;
        
        for (int i=0; i<= num_pwds; i++){
            count=0;
            for (int j=0; j<=num_pwds; j++){
                if (b[i]==(b[j+1])) {
                    count++;}
                    num[i]=count;
                }
            }
       
        for (int i=0; i<= num_pwds; i++) {
            if (num[0]<num[i]) {
                num[0]=num[i];
                max = i;
            }
        }

    return max;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////