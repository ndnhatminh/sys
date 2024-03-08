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
    
//Ham gioi han                                          //ok
        int limit(int gt, int gh)                                                                                                               //gt: value   gh: limit
    {   
    if (gt < 0) { gt = 0; }                      
       else { if ( gt > gh ) { gt = gh; } }
    return gt;
    }

// Task 1                                               //hoan thanh
        int firstMeet(int & exp1, int & exp2, int e1) 
    {
        int T;
        if ( e1 >= 0 && e1 <= 99)
        {
    // check value 1
        int gh = 600 ;
        exp1 = limit( exp1, gh );
        exp2 = limit( exp2, gh );

    //noi dung                                                                                             //gh: exp: 600  hp: 666 m:3000 e:99
        switch (e1)
            { 
                case 0: exp2 += 29; break;
                case 1: exp2 += 45; break;
                case 2: exp2 += 75; break;
                case 3: exp2 += 149;break;
                default: if(e1 >= 4 && e1 <= 19) { exp2 = ceil((float)(exp2)+((float)e1/4) + 19); exp2 = limit( exp2, gh ); }                                                 //infor 1
                            else { if (e1 <= 49) { exp2 = ceil((float)(exp2)+((float)e1/9) + 21); exp2 = limit( exp2, gh ); }                                                 //infor 2
                            else { if (e1 <= 65) { exp2 = ceil((float)(exp2)+((float)e1/16)) +17; exp2 = limit( exp2, gh ); }                                                 //infor 3
                            else { if (e1 <= 79) { exp2 = ceil((float)(exp2)+((float)e1/4)) + 19; exp2 = limit( exp2, gh );                                                   //infor 4
                                 if (exp2 > 200) { exp2 = ceil((float)(exp2)+((float)e1/9)) + 21; exp2 = limit( exp2, gh ); } }
                            else { if (e1 <= 99) { exp2 = ceil((float)(exp2)+((float)e1/4) + 19); exp2 = ceil(float(exp2)+((float)e1/9)+21); exp2 = limit( exp2 , gh );                                     //infor 5
                                 if (exp2 > 400) { exp2 = ceil(((float)(exp2)+((float)e1/16) +17)); exp2 = ceil((float)exp2*1.15); exp2 = limit( exp2 , gh ); } }
                                 } } } }
                        exp1 = exp1 - e1; exp1 = limit( exp1, gh );
                        break;
            }
        if(e1 >= 0 && e1 <= 3){
        int D = e1*3 + exp1*7;
        if ( D % 2 == 0 ) { exp1 = ceil((float)exp1 + ((float)D/200)); }
            else { exp1 = ceil((float)exp1 - ((float)D/100)); } }

    //check value 2
        exp1 = limit( exp1, gh );
        exp2 = limit( exp2, gh );  
        T = exp1 + exp2;
        }
              else { T = -99; }
        return T;
    }

// Task 2                                               //hoan thanh
    //Ham xac xuat                                          //ok
        double gannhat(int EXP)
        {
            int a;
            double P1, S;
            S = round(sqrt((double)EXP));
            a = S*S;
            if ( a <= EXP ) { P1 = 1; }
                else { P1 = ( ( (double)EXP/a ) + 80 ) / 123;
                    }
            return P1;
        }
        
    //ham cac su kien                                       //ok
        void event1(int & HP1, int & EXP1, int & M1)
        {
            int ghhp1 = 666, ghexp = 600, ghm = 3000;
            if (HP1 < 200) { HP1 = ceil(HP1*1.30f); M1 -= 150; }                                                                                                  //event 1
                else { HP1 = ceil(HP1*1.10f); M1 -= 70; }
            M1 = limit( M1,ghm ); EXP1= limit(EXP1,ghexp );HP1 = limit( HP1, ghhp1 );
        }
        
        void event2(int & HP1, int & EXP1, int & M1)
        {
            int ghhp1 = 666, ghexp = 600, ghm = 3000;
            if (EXP1 < 400) { M1 -= 200; }                                                                                                                 //event 2
                else { M1 -= 120; }
            EXP1 = ceil(EXP1*1.130f);
            M1 = limit( M1,ghm ); EXP1= limit(EXP1,ghexp );HP1 = limit( HP1, ghhp1 );
        }
        
        void event3(int & HP1, int & EXP1, int & M1)
        {
            int ghhp1 = 666, ghexp = 600, ghm = 3000;
            if (EXP1 < 300){M1-=100;}                                                                                                                 //event 3
                else {M1 -= 120;}
            EXP1 = ceil(EXP1*0.90f); 
            M1 = limit( M1,ghm ); EXP1= limit(EXP1,ghexp );HP1 = limit( HP1, ghhp1 );
        }
        
    //ham chinh                                             //ok
        int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) 
        {
            float T ;
            if ( E2 >= 0 && E2 <= 99)
            {
            int ghhp1 = 666, ghexp = 600, ghm = 3000, m, i, tc;
        
            //check value 1
            HP1 = limit( HP1, ghhp1 );
            EXP1 = limit( EXP1, ghexp );
            M1 = limit( M1, ghm );
            
            //way 1
            double P1 = gannhat( EXP1 );
            
            //way 2
            m = M1;
            if (E2%2 != 0){
                while(true) { event1( HP1,EXP1,M1 ); tc=m-M1; if (m < 2*tc ) { goto ketthuc; } 
                              event2( HP1,EXP1,M1 ); tc=m-M1; if (m < 2*tc ) { goto ketthuc; } 
                              event3( HP1,EXP1,M1 ); tc=m-M1; if (m < 2*tc ) { goto ketthuc; }
                            } }
            else {  if (M1 == 0) { goto ketthuc; }
                    event1( HP1,EXP1,M1 ); if (M1 == 0) { goto ketthuc; }
                    event2( HP1,EXP1,M1 ); if (M1 == 0) { goto ketthuc; }
                    event3( HP1,EXP1,M1 ); goto ketthuc; 
                    }
            ketthuc: HP1 = ceil(HP1*0.830f); EXP1 = ceil(EXP1*1.170f);
            HP1 = limit( HP1, ghhp1 );
            EXP1 = limit( EXP1, ghexp );
            M1 = limit( M1,ghm );
            double P2 = gannhat( EXP1 );
            
            //way 3
            double P3[10]={0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11}, P;
            if(E2 < 10) { i = E2; }
            else { i = ( E2/10 + E2%10 )%10; }
            
            //final
            P = P1 + P2 + P3[i];
            if(P == 3) { EXP1 = ceil(EXP1*0.750f); }
            else { if ( P/3.0f > 0.5f) { HP1 = ceil(HP1 * 0.90f); 
                                         EXP1 = ceil((float)EXP1 * 1.2); }
                    else { HP1 = ceil(HP1 * 0.850f);
                           EXP1 = ceil(EXP1 * 1.150f); }
                 }
            HP1 = limit( HP1, ghhp1 );
            EXP1 = limit( EXP1, ghexp );
            M1 = limit( M1, ghm );
            T = EXP1 + M1 + HP1 ;
            }
              else { T = -99; }
            return T;
        }

// Task 3
    //matran
        void matran(int matrix[10][10], int E3) 
        {
        for (int i = 0; i < 10; ++i) 
        {
            for (int j = 0; j < 10; ++j) {
                matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        }
        
    //tim vi tri
        void vitri(int matrix[10][10], int E3, int& max, int& TX) 
        {
              int  i = 0, j = 0;
        for (int a = 0; a < 10; ++a) 
        {
            for (int b = 0; b < 10; ++b) 
            {
                if (matrix[a][b] > (E3 * 2)) { i += 1; }
            }
        }
                
        for (int a = 0; a < 10; ++a) 
        {
            for (int b = 0; b < 10; ++b) 
            {
                if (matrix[a][b] < (-E3)) { j += 1; }
            }
        }
                
        do {i = i / 10 + i % 10;}
            while (i >= 10);
        do {j = j / 10 + j % 10;}
            while (j >= 10);
        TX = matrix[i][j]; max = 0;
        
        int n = i , m = j;
        for (; j >= 0; --j) 
        {
            if (matrix[i][j] > max) { max = matrix[i][j]; }
            if (i == 9) { break; } ++i;
        }
        i = n ; j = m;      
        for (; j < 10; ++j) 
        {
            if (matrix[i][j] > max) { max = matrix[i][j]; } 
            if (i == 0) { break; } --i;
        }
        i = n ; j = m;        
        for (; j < 10; ++j) 
        {
            if (matrix[i][j] > max) { max = matrix[i][j]; } 
            if (i == 9) { break; } ++i;
        }
        i = n ; j = m;          
        for (; j >= 0; --j) 
        {
            if (matrix[i][j] >= max) { max = matrix[i][j]; }
            if (i == 0) { break; } --i;
        }
        }

    //ham chinh
        int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) 
        {   
            int ghhp = 666, ghexp = 600, ghm = 3000, max, TX, matrix[10][10], a;
            if ( E3 >= 0 && E3 <= 99 )
            {
            //chuyen doi
            float EXP1f = (float)EXP1;
            float HP1f = (float)HP1;
            float EXP2f = (float)EXP2;
            float HP2f = (float)HP2;

            //check value
            EXP1f = limit( EXP1f, ghexp );
            EXP2f = limit( EXP2f, ghexp );
            HP1f = limit( HP1f, ghhp );
            HP2f = limit( HP2f, ghhp );

            matran(matrix, E3);
            vitri(matrix,E3,max,TX);
           
            if ( abs(TX) > abs(max)){EXP1f*=0.88; EXP2f*=0.88;
                                     HP1f*=0.9; HP2f*=0.9;
                                     a = TX;}
                else {EXP1f*=1.12; EXP2f*=1.12; HP1f*=1.1; HP2f*=1.1; a = max;}
            
            EXP1 = (int)ceil(EXP1f); HP1 = (int)ceil(HP1f);
            EXP2 = (int)ceil(EXP2f); HP2 = (int)ceil(HP2f);

            //check value
            EXP1 = limit( EXP1, ghexp );
            EXP2 = limit( EXP2, ghexp );
            HP1 = limit( HP1, ghhp );
            HP2 = limit( HP2, ghhp );
            if ( E3 == 0 ) { a = 0; }
            }
              else  a = -99;
    return a;
        }

// Task 4
        int checkPassword(const char * s, const char * email) 
        {
        const char *se = strchr( email, '@' );
        if ( se == nullptr ){ return -1; }
            
        int pwl = strlen( s );
        if ( pwl < 8 ) { return -1; }
        if ( pwl > 20 ) { return -2; }
            
        char sel[100];
        strncpy( sel, email, se - email );
        sel[se - email]='\0';
            
        const char* find = strstr(s, sel);
        if (find != nullptr) 
        {
            return -(300 + (find - s));
        }
            
        for (int i = 0; i < pwl - 2; ++i)
        {
            if ( s[i] == s[i+1] && s[i] == s[i+2] ) { return -(400 + i); }
        }
            
        bool nm = false;
        for (int i = 0; i < pwl; ++i )
        {
            char a = s[i];
            if ( a == '@' || a == '#' || a == '$' || a == '!' || s[i] == '%' )
            {   nm = true; break; }
        }
        if (!nm) { return -5; }
        for (int i = 0; i < pwl ; ++i)
        {   
            char a = s[i];
            if (!((a >= '0' && a <= '9') || 
                  (a >= 'a' && a <= 'z') || 
                  (a >= 'A' && a <= 'Z') ||
                   a == '@' || a == '#' || a == '$' || a == '!' || a == '%' ))
                { return i; }        
        }
        return -10;
        }

// Task 5
        int findCorrectPassword(const char * arr_pwds[], int num_pwds) 
        {
        int c, mc = 0, ml = 0;
        for ( int i = 0; i < num_pwds; ++i)
        {
            const char * an = arr_pwds[i];
            int a = 0;
            for ( int j = 0; j < num_pwds; ++j)
            {
                if (i != j && strcmp(an, arr_pwds[j]) == 0) { a++; }
            }
            int anl = strlen(arr_pwds[i]);
            if (a > mc || (a == mc && anl > ml)) 
            { 
                mc = a; ml = anl;
                c = i;
            }
        }        
        return c;
        }

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////