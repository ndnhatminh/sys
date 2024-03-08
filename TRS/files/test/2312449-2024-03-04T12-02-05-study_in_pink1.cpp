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
        int D ;
        if ( 0 <= e1 && e1 <= 3) {
            if (e1 == 0) exp2 = exp2 + 29;
            else if (e1 == 1) exp2 = exp2 + 45;
            else if (e1 == 2) exp2 = exp2 + 75;
            else exp2 = exp2 + 29 +45 + 75;
            D = ceil( e1*3 + exp1*7);
            if (D % 2 == 0) exp1 = ceil(exp1 + (double)D/200);
            else exp1 = ceil(exp1 -(double) D/100);
            exp2 = ceil(exp2);
        }
        else if ( (4 <= e1) && (e1 <= 99) ) {
            if ((4 <= e1) && (e1 <= 19)) exp2 =ceil(exp2 + ((double)e1/4 + 19));
            else if (20 <= e1 && e1 <= 49) exp2 = ceil((exp2 + (double)e1/9 + 21));
            else if (50 <= e1 && e1 <= 65) exp2 = ceil(exp2 + ((double)e1/16 + 17));
            else if (66 <= e1 && e1 <= 79) {
                exp2 =ceil(exp2+(double)e1/4 + 19);
                if (exp2 > 200) exp2 =ceil( exp2 + ((double)e1/9 + 21));
            }
            else if (80<=e1 && e1<=99){
                exp2 = ceil(exp2 + (e1/4.0 + 19) ) ;
            exp2 = ceil(exp2 + ((double)e1       /9.0 + 21));
                if (exp2 > 400) {
                    exp2 = ceil(exp2 + ((double)e1/16.0 + 17));
                    exp2 = ceil((double)exp2*115/100);
                }
            }
            exp1 = exp1 - e1; 
        }
        else return -99;
        //Kiem tra dieu kien
        if ( exp1 > 600 ) exp1 = 600;    
        if ( exp2 > 600 ) exp2 = 600;
        if ( exp1 < 0 ) exp1 = 0;  
        if ( exp2 < 0 ) exp2 = 0;    
        return exp2 + exp1;
    }

    // Task 2
    int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
        // TODO: Complete this function
        // con duong 1
        int S;
        double P1 , P2;  
        S = sqrt(EXP1);
        double n = (S+1)*(S+1);
        if (((EXP1 - (S*S) >= ((S+1)*(S+1)) - EXP1))){
            P1 = (((EXP1 /n)+80)/123)*100;
            
        } 
        else P1 = 100;
        //Co duong 2
        int k = M1;
        //E3 le
        if(E2 < 0 || E2 > 99) return -99;
        if (E2 % 2 != 0){
        while(M1 > (k/2)){
        
        if (HP1 < 200) {
            HP1 = ceil((double)HP1 * 130 / 100); 
            
            if ( HP1 > 666) HP1 = 666;
            M1 = M1 -150; 
        
        }
        else {
            HP1 = ceil((double)HP1 * 110 / 100) ; 
            if ( HP1 > 666) HP1 = 666;
            M1 = M1 - 70;
        }
        if (M1 < (k/2)) break;
        //if ( HP1 > 600 ) HP1 = 600;
        //if ( M1 < 0 ) M1 = 0;

        if (EXP1 < 400) M1= M1 - 200;
        else M1 = M1 - 120; 
        EXP1 = ceil((double)EXP1* 113/100) ; if(EXP1 > 600) EXP1 = 600;
        if (M1 < (k/2)) break;
        
        if (EXP1 < 300) M1 = M1 - 100;
        else M1 = M1 - 120;
        EXP1 =ceil((double)EXP1*90/100);
        }
        
        }
        //E3 chan
        else {
            if (M1 <= 0 ) goto banana;
            if (HP1 < 200) {
            HP1 =ceil((double)HP1 * 130 / 100);
            if ( HP1 > 666) HP1 = 666;
            M1 = M1 -150; 
        }
            else {
            HP1 = ceil((double)HP1 * 110 / 100) ; if ( HP1 > 666) HP1 = 666;
            M1 = M1 - 70;
        }
            if (M1 <= 0 ) goto banana;
        //if ( HP1 > 600 ) HP1 = 600;
        //if ( M1 < 0 ) M1 = 0;

            if (EXP1 < 400) M1= M1 - 200;
            else M1 = M1 - 120;
            EXP1 = ceil((double)EXP1 * 113 / 100) ; if(EXP1 > 600) EXP1 = 600;
            if (M1 <= 0 ) goto banana;
            if (EXP1 < 300) M1 = M1 - 100;
            else M1 = M1 - 120;
            
            EXP1 = ceil((double)EXP1*90/100);
        if (M1 <= 0 ) goto banana;
        }
    banana: 
        if( M1 <= 0) M1 = 0;
        HP1 = ceil((double)HP1*83/100); 
        EXP1 = ceil((double)EXP1*117/100); if (EXP1 > 600) EXP1 = 600;
        S = sqrt(EXP1);
        double l = (S+1)*(S+1);
        if (((EXP1 - (S*S) >= ((S+1)*(S+1)) - EXP1))){
            P2 = (((EXP1 /l)+80)/123)*100;
            
        } 
        else P2 = 100;
    //con duong 3
    int A[10] ={32,47,28,79,100,50,22,83,64,11};
    float P3;
    int m;
    m= ((E2 % 10) + (E2 / 10))%10;
    if (E2 < 10) P3 = A[E2];
    else {
        P3 = A[m];
    }   
    //cuoi cung
    if ( (P1 == 100)&& (P2 == 100) && (P3 == 100)){
        EXP1 = ceil((double)EXP1 *75/100 );
    }
    else{
        if ((P1 + P2 + P3)/3 < 50) {
            HP1 = ceil((double)HP1*85/100);
            EXP1 = ceil((double)EXP1*115/100);if (EXP1 > 600) EXP1 = 600;
        } 
        else {
            HP1 = ceil((double)HP1*90/100);
            EXP1 = ceil((double)EXP1*120/100); if (EXP1 > 600) EXP1 = 600;
        }
    }
    return EXP1 + HP1 + M1;
    }

    // Task 3
    int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
        // TODO: Complete this function
        if (E3 < 0 || E3 > 99) return -99;
        int A[10][10];
        int i, j, d = 0, a=0;
        for( i = 0; i <= 9; i++){
            for( j = 0; j <= 9; j++){
            
                if (i == j) A[i][j]=0; 
                else  A[i][j]= (E3*j + i*2)*(i - j);
                if ((A[i][j] > 0) && (A[i][j] > (E3*2))) ++d;
                if ((A[i][j] < 0) && (A[i][j] < (0 - (E3)))) ++a;

            }
        }
        while((d>9) || (a > 9)){
                a = (a/10) + (a%10);
                d = (d/10) + (d%10);
            }
        int max = A[d][a];
        int m ,n;
        //cheo duoi trai
        m = d ;
        n = a ;
        while ((m<9) && (n>0)){
            ++m;
            --n;
            if(A[m][n] > max) max = A[m][n];
        }
        //cheo tren phai
        m = d ;
        n = a ;
        while ((m>0) && (n<9)){
            --m;
            ++n;
            if(A[m][n] > max) max = A[m][n];
        }
        //cheo duoi phai
        m = d ;
        n = a ;
        while ((m<9) && (n<9)){
            ++m;
            ++n;
            if(A[m][n] > max) max = A[m][n];
        }
        //cheo tren trai
        m = d ;
        n = a ;
        while ((m>0) && (n>0)){
            --m;
            --n;
            if(A[m][n] > max) max = A[m][n];
        }
        if (abs(A[d][a]) > max){
            EXP1 = ceil((double)EXP1*88/100);
            HP1 = ceil((double)HP1*90/100);
            EXP2 = ceil((double)EXP2*88/100);
            HP2 = ceil((double)HP2*90/100);
            return A[d][a];
        }
        else {
            EXP1 = ceil((double)EXP1*112/100); if(EXP1 > 600) EXP1=600;
            HP1 = ceil((double)HP1*110/100); if(HP1 > 666) HP1=666;
            EXP2 = ceil((double)EXP2*112/100);if(EXP2 > 600) EXP2=600;
            HP2 = ceil((double)HP2*110/100);if(HP1 > 666) HP1=666;
            return max;

        }

        
        
    }

    // Task 4
    int checkPassword(const char * s, const char * email) {
        // TODO: Complete this function
        int length = strlen(s);
        if (length < 8) return -1;
        if (length > 20) return -2;
        string se = "";
        for (int i = 0; i < strlen(email); i++) {
            if (email[i] != '@') se += email[i];
            else break;
        }
        string check = string(s);
        bool temp = false ;  
        if( check.find(se) <= strlen(s)) return -(check.find(se) + 300);
        for (int sec = 0; sec < strlen(s) - 2; sec++){
            if(s[sec]== s[sec+1] && s[sec+1]==s[sec+2]) return -(400 + sec);

        }
        for (int n = 0; n < strlen(s); n++){
            switch (s[n]){
                case '@' : temp = true;
                case '#' : temp = true;
                case '%' : temp = true;
                case '$' : temp = true;
                case '!' : temp = true;
            }

            }
        if( temp == false ) return -5;   
        for (int n = 0; n < strlen(s); n++){
            if ( !('0' <= s[n] && '9'>= s[n]) && !('a' <= s[n] && 'z'>= s[n]) &&!('A' <= s[n] && 'Z'>= s[n]) && s[n] != '@'
            && s[n] != '#' && s[n] != '%' && s[n] != '$' && s[n] != '!') return n; 
        }
        return -10;

    }

    // Task 5
    int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
        // TODO: Complete this function
        string A[num_pwds];
        string temp ="";
        bool avai= false;
        int count[num_pwds] ={}, number[num_pwds];
        int n= 0;
        number[0]=0;
        A[0]= string (arr_pwds[0]); 
        for (int i = 1; i < num_pwds; i++){
            temp = string (arr_pwds[i]); 
            for (int j = 0; j <= n; j++){
                if (temp == A[j]){
                    avai = true;
                    count[j]+=1;
                }
                
            }
            if (avai == false) {
                n += 1; 
                A[n] = temp ;
                avai = false;
                number[n]= i;
                temp="";
            }
            avai=false;
        }
        int max =0;
        int ht = 0;
        for (int k = 0; k <= n; k++){
            if(count[k] > max ){
                max = count[k];
                ht=k;
            }
            if (count[k]== max){
                if(A[k].length() > A[ht].length()){
                max = count[k];
                ht = k;
                }
            }
        }
        
        return number[ht];
    }