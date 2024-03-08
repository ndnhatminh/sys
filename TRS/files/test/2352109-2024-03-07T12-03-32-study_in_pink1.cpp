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

int resetEXP(int & EXP){
    if (EXP < 0){ EXP = 0;}

    else if (EXP > 600){ EXP = 600;}
    
    return EXP;
}
int resetHP(int & HP){
    if (HP < 0){ HP = 0;}

    else if (HP > 666){ HP = 666;}
    
    return HP;
}
int resetM(int & M){
    if (M < 0){ M = 0;}

    else if (M > 3000){ M = 3000;}

    return M;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    if (e1 >=0 && e1 <= 3) // case 1
        {
        resetEXP(exp1);
        resetEXP(exp2);
        if (e1 == 0) exp2 += 29;

        else if (e1 == 1) exp2 += 45;

        else if (e1 == 2) exp2 += 75;

        else if (e1 == 3) exp2 += (29+45+75);

        int D = e1*3 + exp1*7;

        if (D % 2 == 0)
        {
            exp1 += ceil((double)D/200);
        }
        else
        {
            exp1 -= floor((double)D/100);
        }

        resetEXP(exp1);
        resetEXP(exp2);
    }

    else if (e1 >= 4 && e1 <= 99) // case 2
    {
        resetEXP(exp1);
        resetEXP(exp2);
        if (e1 >=4 && e1 <= 19){ exp2 += ceil((e1/4.0 + 19));}

        else if (e1 >=20 && e1 <= 49){ exp2 += ceil((e1/9.0 + 21));}

        else if (e1 >= 50 && e1 <= 65){ exp2 += ceil((e1/16.0 + 17));}

        else if (e1 >=66 && e1 <= 79){ exp2 += ceil((e1/4.0 + 19)); if (exp2 > 200){ exp2 += ceil((e1/9.0 + 21));}}

        else if (e1 >= 80 && e1 <= 99){ exp2 += ceil((e1/4.0 + 19)); exp2 += ceil((e1/9.0+21)); if (exp2 > 400){  exp2 += ceil((e1/16.0 + 17));  exp2 += ceil((15*exp2)/100.0);}}

        exp1 -= e1; 

        resetEXP(exp1);
        resetEXP(exp2);
    }

   else{ return -99;}

    return exp1 + exp2;
}

int checknum(int E){
    int count = 0;
    while (E >= 10){
        E /= 10;
        count++;
    }
    return count +1;
}

// Task 2
int checkS(int EXP){
    int s1 = floor(sqrt(EXP));
    int s2 = floor(sqrt(EXP)) + 1;
    int A = EXP - pow(s1,2);
    int B = pow(s2,2)- EXP;
    int S;
    if (A>B){ S = s2;}
    else if (A<B){ S = s1;}
    return pow(S,2);
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

if (E2 >=0 && E2 <=99){

     resetHP(HP1);
     resetEXP(EXP1);
     resetM(M1);

    //Road 1
      float P1;
      int EXPi = EXP1;
      int Sa = checkS(EXP1);
      if (EXPi >= Sa){ P1 = 1;}
      else{ P1 = ((double)EXPi/Sa + 80)/123.0;}

    //Road 2
     int a = 1;
     double P2;
     float M1h = double(50*M1)/100.0;
     int M1i = M1;

     if (E2 % 2 != 0){
     while(a == 1)
     {

        if (M1 <=0){ M1 = 0; break;}

        if (M1 < M1h){ break;}

       if (HP1 < 200){ HP1 += ceil((double)(HP1*30)/100); M1 -= 150;}
       else{ HP1 += ceil((double)(HP1*10)/100); M1 -= 70;}

        resetHP(HP1);
        resetEXP(EXP1);

         if (M1 < M1h){ break;}

       if (EXP1 < 400){ EXP1 += ceil((double)(EXP1*13)/100); M1 -= 200;}
       else{ EXP1 += ceil((double)(EXP1*13)/100); M1 -= 120;}

        resetHP(HP1);
       resetEXP(EXP1);

         if (M1 < M1h){ break;}

       if (EXP1 < 300){ EXP1 -= floor((double)(EXP1*10)/100); M1 -= 100;}
       else{EXP1 -= floor((double)(EXP1*10)/100); M1 -= 120;}

       resetHP(HP1);
       resetEXP(EXP1);
     
     }

         EXP1 += ceil((double)(EXP1*17)/100); 
         HP1 -= floor((double)(HP1*17)/100);

       resetHP(HP1);
       resetEXP(EXP1);
    
     }
     
else if (E2 % 2 == 0){
        for (int n = 0;n <1;++n) {

       if (M1 <=0){ M1 = 0; break;}

       if (HP1 < 200){ HP1 += ceil((double)(HP1*30)/100); M1 -= 150;}
       else{ HP1 += ceil((double)(HP1*10)/100); M1 -= 70;}

        resetHP(HP1);
       resetEXP(EXP1);

       if (M1 <=0){ M1 = 0; break;}

       if (EXP1 < 400){ EXP1 += ceil((double)(EXP1*13)/100); M1 -= 200;}
       else{ EXP1 += ceil((double)(EXP1*13)/100); M1 -= 120;}

        resetHP(HP1);
       resetEXP(EXP1);

       if (M1 <=0){ M1 = 0; break;}

       if (EXP1 < 300){ EXP1 -= floor((double)(EXP1*10)/100); M1 -= 100;}
       else{EXP1 -= floor((double)(EXP1*10)/100); M1 -= 120;}

        resetHP(HP1);
       resetEXP(EXP1);

        if (M1 <=0){ M1 = 0; break;}

       resetHP(HP1);
       resetEXP(EXP1);
    
        }
        
     EXP1 += ceil((double)(EXP1*17)/100);
     HP1 -= floor((double)(HP1*17)/100);

    resetHP(HP1);
    resetEXP(EXP1);

     }

     int Sb = checkS(EXP1);

     if (EXP1 >= Sb){ P2 = 1;}
      else{ P2 = ((double)EXP1/Sb + 80)/123.0;}

    //Road 3

     double P3;

     int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

     int num = checknum(E2);
    
     int i;

     if (num == 1){ i = E2; P3 = (double)P[i]/100.0;}

     else if (num == 2){ i = ((E2/10) + (E2%10))%10; P3 = (double)P[i]/100.0;}
    
     double Pt = (double)(P1+P2+P3)/3.0;

     if (Pt == 1){ EXP1 -= floor((25*EXP1)/100);}

     else if (Pt < 0.5){ HP1 -= floor((double)(15*HP1)/100.0); EXP1 += ceil((double)(15*EXP1)/100.0);}

     else if (Pt >= 0.5){ HP1 -= floor((double)(10*HP1)/100.0); EXP1 += ceil((double)(20*EXP1)/100.0);}
 
    resetHP(HP1);
    resetEXP(EXP1);
    resetM(M1);

}    
else{ return -99;}

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
     // TODO: Complete this function

    int Map[10][10];

    if (E3 >= 0 && E3 <= 99){

       resetHP(HP1);
       resetEXP(EXP1);
       resetHP(HP2);
       resetEXP(EXP2);
        
    
         int n = 0;
         int m = 0;        

        for (int i = 0; i < 10; ++i){
            for (int j = 0; j < 10; ++j){

               Map[i][j] = ((E3 * j) + (i * 2)) * (i - j);

               if (Map[i][j] > (E3*2)){

                m++;

               }

                if (Map[i][j] < (-1.0*E3)){

                n++;

                }           

            }
          
        }
        
         int x;
         int y;
         int num1 = checknum(m);
         int num2 = checknum(n);

         if (num1 == 1){ x = m;}
         else if (num1 == 2){ x = ((m/10) + (m%10)); x = ((x/10) +(x%10));}

         if (num2 == 1){ y = n;}
         else if (num2 == 2){ y = ((n/10) + (n%10))%10; y = ((y/10) +(y%10));}
        
        int Taxipoint = Map[x][y];

        int p = x;
        int q = y;
        int r = x;
        int t = y;

        if (p <= 0){ p = 0;}
        if (q >= 9){ q = 9;}
        if (r <= 0){ r = 0;}
        if (t <= 0){ t = 0;}

        while (true){

            if (x == 9 && y == 9){ break;}
            if (x == 0 && y == 0){ break;}
            if (p <= 0){ p = 0; break;}
            if ( q >= 9){ q = 9; break;}

            p -= 1;
            q += 1;

            if (p <= 0){ p = 0; break;}
            if ( q >= 9){ q = 9; break;}
        }
        
         while (true){
            if (x == 9 && y == 9){ break;}
            if (x == 0 && y == 0){ break;}
            if (r <= 0){ r = 0; break;}
            if (t <= 0){ t = 0; break;}

            r -= 1;
            t -= 1;
            
           if (r <= 0){ r = 0; break;}
           if (t <= 0){ t = 0; break;}
        }
         
         int maxa = Taxipoint;

         while (true){

            if (x == 9 && y == 9){ maxa = 0; break;}
            if (x == 0 && y == 0){ maxa = 0; break;}
            if (q == 0 || p ==9){ break;}

            p += 1;
            q -= 1;
            
            if (Map[p][q] >= maxa){ maxa = Map[p][q];}
            else{ maxa = Taxipoint;}

            if (q == 0 || p ==9){ break;}
        }
         int maxb = Taxipoint;
        while (true){
            
            if (x == 9 && y == 9){ maxb = 0; break;}
            if (x == 0 && y == 0){ maxb = 0; break;}
            if (q == 9 || p ==9){ break;}

            r += 1;
            t += 1;
            
            if (Map[r][t] >= maxb){ maxb = Map[r][t];}
            else{ maxb = Taxipoint;}
            
            if (q == 9 || p ==9){ break;}
        }

        int HWpoint; 
        if (maxa >= maxb){ HWpoint = maxa;}
        else{ HWpoint = maxb;}

        if (abs(Taxipoint) > HWpoint)
        { 
            HP1 -= floor((double)(10*HP1)/100.0); EXP1 -= floor((double)(12*EXP1)/100.0);
            HP2 -= floor((double)(10*HP2)/100.0); EXP2 -= floor((double)(12*EXP2)/100.0);

             resetHP(HP1);
             resetEXP(EXP1);
             resetHP(HP2);
             resetEXP(EXP2);

            return Taxipoint;
        }

        else if (abs(Taxipoint) <= HWpoint){
             HP1 += ceil((double)(10*HP1)/100.0); EXP1 += ceil((double)(12*EXP1)/100.0);
             HP2 += ceil((double)(10*HP2)/100.0); EXP2 += ceil((double)(12*EXP2)/100.0);
             
             resetHP(HP1);
             resetEXP(EXP1);
             resetHP(HP2);
             resetEXP(EXP2);

             return HWpoint;
        }
    }
     return -99;
}

// Task 4

int checkSvalue(string a){
      int Sv = 0;
      int Sv1 = 0;
    for (int i=0;i < (a.length()); ++i){
               
        if (a[i] == a[i+1]){
                Sv++;
                Sv1 = i;
            }
            else{ Sv = 0; Sv1 = 0;}

            if (Sv == 2){ break;}
        }

        return Sv1;
}

int checkSpecialtext(string b){
    int St = 0;
    for (int i = 0;i < b.length(); ++i){

            if (b[i] == '#' || b[i] == '@' || b[i] == '%' || b[i] == '$' || b[i] == '!'){ St++; break;}

            else{ St = 0;}
            
        }

        return St;
}
int checktext(string c){
     int t = 0; 
     for (int i = 0;i < c.length(); ++i){

            if (!(c[i] == '#' || c[i] == '@' || c[i] == '%' || c[i] == '$' || c[i] == '!' || (c[i] >= 'a' && c[i] <= 'z') || (c[i] >= '0' && c[i] <= '9') || (c[i] >= 'A' && c[i] <= 'Z')))
            
            { t = i; break;}

            else{ t = -10;}
    }
     return t;
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    string S = s;

    string E = email;

    int Pos = E.find('@');
    
    string SE = E.substr(0,Pos);

  //Check Password;
      int sei = S.find(SE);

      int index = checkSvalue(S) - 1;

      if (S.length() < 8){ return -1;}

      else if (S.length() > 20){ return -2;}

      else if (sei != std::string::npos){ return -(300 + sei);}

      else if (checkSvalue(S) != 0){ return -(400 + index);}

      else if (checkSpecialtext(S) == 0){ return -5;}

     else if (checktext(S) != -10){ return checktext(S);}

     return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
     
   int mostapp = 0;
    int lenpass = 0;
    int index;

    for (int i = 0; i < num_pwds; ++i) {
        int app = 1; 
        string Password(arr_pwds[i]);

        for (int j = i + 1; j < num_pwds; ++j) {
            if (Password == arr_pwds[j]) {
                app++;
            }
        }

        if (app > mostapp || (app == mostapp && Password.length() > lenpass)) {
            mostapp = app;
            lenpass = Password.length();
            index = i;
        }
    }

    return index;

}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////