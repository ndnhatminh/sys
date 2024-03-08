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

//Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    if (e1<0 || e1>99) return -99; else {
    if (exp2 > 600) exp2 = 600;
    if (exp1 > 600) exp1 = 600;
    if (exp1 < 0) exp1 = 0;
    if (exp2 < 0) exp2 = 0;
    int D;
    switch (e1)
    {
    case 0: 
        exp2 += 29 ;
        if (exp2 > 600) exp2 = 600;
        break;
    case 1:
        exp2 += 45 ;
        if (exp2 > 600) exp2 = 600; 
        break;
    case 2:
        exp2 += 75;
        if (exp2 > 600) exp2 = 600;
        break;
    case 3: 
        exp2 += 29 + 45 + 75;
        if (exp2 > 600) exp2 = 600;
        break;
    }
    if (e1 <= 3) {
    D = e1*3 + exp1*7;
    if ((D % 2) == 0) {exp1 = ceil(exp1*1.00 + D*1.00/200);
    if (exp1 > 600) exp1 = 600;
    if (exp1 < 0) exp1 = 0;} 

    if ((D % 2) != 0) {exp1 = ceil(exp1*1.00 - (D*1.00/100)); 
    if (exp1 > 600) exp1 = 600;
    if (exp1 < 0) exp1 = 0;}
    }

    if ((e1 >= 4) && (e1 <= 19)) {
        exp2 = ceil(exp2*1.00 + e1*1.00/4 + 19);
        if (exp2 > 600) exp2 = 600;
        exp1 = exp1 - e1;}  

    if ((e1 >= 20) && (e1 <= 49)) {
        exp2 = ceil(exp2*1.00 + e1*1.00/9 + 21);
        if (exp2 > 600) exp2 = 600;
        exp1 = exp1 - e1;} 

    if ((e1 >= 50) && (e1 <= 65)) {
        exp2 = ceil(exp2*1.00 + e1*1.00/16 + 17);
        if (exp2 > 600) exp2 = 600;
        exp1 = exp1 - e1;}

    if ((e1 >= 66) && (e1 <= 79)) {
        exp2 = ceil(exp2*1.00 + e1*1.00/4 + 19);
        if (exp2 > 600) exp2 = 600; 
        if (exp2 > 200) exp2 = ceil(exp2*1.00 + e1*1.00/9 + 21);
        if (exp2 > 600) exp2 = 600;
        exp1 = exp1 - e1;
    }

    if ((e1 >= 80) && (e1 <= 99)) {
        exp2 = ceil(exp2*1.00 + e1*1.00/4 + 19);
        if (exp2 > 600) exp2 = 600; 
        exp2 = ceil(exp2*1.00 + e1*1.00/9 + 21);
        if (exp2 > 600) exp2 = 600; 
        if (exp2 > 400) {
            exp2 = ceil(exp2*1.00 + e1*1.00/16 + 17);
            if (exp2 > 600) exp2 = 600;
            exp2 = ceil(exp2 * 1.15);
            if (exp2 > 600) exp2 = 600;
            };
        exp1 = exp1 - e1;
    };
    
    if (exp2 > 600) exp2 = 600;
    if (exp1 > 600) exp1 = 600;
    if (exp1 < 0) exp1 = 0;
    if (exp2 < 0) exp2 = 0;
    return exp1 + exp2;}
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    ///Road 1
    if ((E2<0) || (E2>99)) return -99; else {
    
    if (HP1 > 666) HP1 = 666;
    else if (HP1 < 0) HP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    else if (EXP1 < 0) EXP1 = 0;
    if (M1 < 0) M1 = 0; 
    else if ( M1 > 3000) M1 = 3000;

    int t = 0; 
    int t1 = 0, t2 = 0;
    t = sqrt(EXP1);
    t1 = abs(t*t - EXP1);
    t2 = abs((t+1)*(t+1) - EXP1);
    int S = 0;
    float P1 = 0.0;
    if (t1 > t2) S = (t+1)*(t+1);
    else S = t*t;
    if (EXP1 >= S) P1 = 100; 
    else {
        P1 = ((EXP1*1.00)/(S*1.00) + 80.0)/(123.0)*100.0; 
    }; 
    ///Road 2
    int M = 0;
    if ((E2 % 2) == 0) {
    for (int j = 0; j <= 0; j++)
    {
    if (M1 == 0) break;
    if (HP1 < 200) {
        HP1 = ceil(HP1 + HP1*30/100.0);
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        M1 = M1 - 150;
        
    }
    else {
        HP1 = ceil(HP1 + HP1*10/100.0);
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        M1 = M1 - 70;
        
    };
    
    if (M1 < 0) M1 = 0; 
    else if ( M1 > 3000) M1 = 3000;
    if (M1 == 0) break; 

    if (EXP1 < 400) {
        M1 = M1 - 200;
        EXP1 = ceil(EXP1+ EXP1*13/100.0);
    }
    else {
        M1 = M1 - 120;
        EXP1 = ceil(EXP1+ EXP1*13/100.0);
    };
    if (M1 < 0) M1 = 0; 
    else if ( M1 > 3000) M1 = 3000;
    if (EXP1 > 600) EXP1 = 600;
    else if (EXP1 < 0) EXP1 = 0;
    if (M1 == 0) break;

    if (EXP1 < 300) {
        M1 = M1 - 100;
        EXP1 = ceil(EXP1 - EXP1*10/100.0);
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
    }
    else {
        M1 = M1 - 120;
        EXP1 = ceil(EXP1 - EXP1*10/100.0);
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
    }
    
    if (M1 < 0) M1 = 0; 
    else if ( M1 > 3000) M1 = 3000;
   
    if (M1 == 0) break;
    }
    }
    if ((E2 % 2) != 0)
    {   for (int j = 0 ; j >= 0 ; j++){
        if (M1 == 0) break;
        float M2 = M1*50/100.0;
        if (HP1 < 200) {
        HP1 = ceil(HP1 + HP1 * 30/100.0);
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        M = M + 150;
    }
    else {
        HP1 = ceil(HP1 + HP1*10/100.0);
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        M = M + 70;
    };
    if (M1 < 0) M1 = 0; 
    else if ( M1 > 3000) M1 = 3000; 
    if (M > M2) break;

    if (EXP1 < 400) {
        M = M + 200;
        EXP1 = ceil(EXP1 + EXP1*13/100.0);
    }
    else {
        M = M + 120;
        EXP1 = ceil(EXP1 + EXP1*13/100.0);
    };
    
    if (M1 < 0) M1 = 0; 
    else if ( M1 > 3000) M1 = 3000;
    
    if (EXP1 > 600) EXP1 = 600;
    else if (EXP1 < 0) EXP1 = 0;   
    if (M > M2) break;

    if (EXP1 < 300) {
        M = M + 100;
       
        EXP1 = ceil(EXP1 - EXP1*10/100.0);
    }
    else {
        M = M + 120;
        
        EXP1 = ceil(EXP1 - EXP1*10/100.0);
    }
    
    if (EXP1 > 600) EXP1 = 600;
    else if (EXP1 < 0) EXP1 = 0;
    if (M1 < 0) M1 = 0; 
    else if ( M1 > 3000) M1 = 3000; 
    if (M > M2) break;
    }
    }

    HP1 = ceil(HP1 - HP1*17/100.0);
    if (HP1 > 666) HP1 = 666;
    else if (HP1 < 0) HP1 = 0;  
    EXP1 = ceil(EXP1 + EXP1*17/100.0);
    if (EXP1 > 600) EXP1 = 600;
    else if (EXP1 < 0) EXP1 = 0;
    if( (E2 % 2) != 0)M1 = M1 - M;
    float P2 = 0.00;
    int S2 = 0;
    int T = 0, T1 = 0, T2 = 0;
    T = sqrt(EXP1);
    T1 = abs(T*T - EXP1);
    T2 = abs((T+1)*(T+1) - EXP1);
    if (T1 > T2) S2 = (T+1)*(T+1);
    else S2 = T*T;
    if (EXP1 >= S2) P2 = 100; 
    else {
        P2 = (((EXP1*1.00)/(S2*1.00) + 80)/(123*1.00))*100.0; 
    };

    ///Road 3
    float Ptb = 0;
    float P3 = 0;
    float P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10) {
        P3 = P[E2];} 
    else {
        {int i = ((E2 / 10) + (E2 % 10)) % 10;
        P3 = P[i];}
    }

    if ((P1 == 100) && (P2 == 100) && (P3 == 100)) {
        EXP1 = ceil(EXP1- EXP1*25/100);
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;

    }
    else {Ptb = (P1 + P2 + P3) / 3.0;
    
        if (Ptb < 50) {
        HP1 = ceil(HP1 - HP1*15/100.0);
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;

        EXP1 = ceil(EXP1 + EXP1*15/100.0);
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;

        }
        else {
        HP1 = ceil(HP1 - HP1*10/100.0);
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;

        EXP1 = ceil(EXP1 + EXP1*20/100.0);
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
        }
    }
    if (HP1 > 666) HP1 = 666;
    else if (HP1 < 0) HP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    else if (EXP1 < 0) EXP1 = 0;
    if (M1 < 0) M1 = 0; 
    else if ( M1 > 3000) M1 = 3000;
    return HP1 + EXP1 + M1;
}
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 < 0 || E3 > 99) return -99; else {
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
        if (HP2 > 666) HP2 = 666;
        else if (HP2 < 0) HP2 = 0;
        if (EXP2 > 600) EXP2 = 600;
        else if (EXP2 < 0) EXP2 = 0;
    int i, j, x = 0, y = 0;
    int A[10][10];
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            A[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (A[i][j] > (E3 * 2)) x = x + 1;
            if (A[i][j] < (-E3)) y = y + 1;
        };
    };
    
    while (x >= 10 ) x = (x % 10) + (x / 10);
    while (y >= 10 ) y = (y % 10) + (y / 10);
    
    int x1 = x, x2 = x, x3 = x, x4 = x;
    int y1 = y, y2 = y, y3 = y, y4 = y;
    int max = A[x][y];
    int max1 = A[x1][y1];
    while (x1 < 10 && y1 < 10 ){
        if (x1 == 9 || y1 == 9) break;
        if (max1 >= A[x1+1][y1+1]) max1 = max1;
        else max1 = A[x1+1][y1+1];
        x1 = x1 + 1;
        y1 = y1 + 1;
        if (x1 == 9 || y1 == 9) break;
    };

    int max2 = A[x2][y2];
    while (x2 >= 0 && y2 >= 0 ){
        if (x2 == 0 || y2 == 0) break;
        if (max2 >= A[x2-1][y2-1]) max2 = max2;
        else max2 = A[x2-1][y2-1];
        x2 = x2 - 1;
        y2 = y2 - 1;
        if (x2 == 0 || y2 == 0) break;
    };

    int max3 = A[x3][y3];
    while (x3 >= 0 && y3 <= 9 ){
        if (x3 == 0 || y3 == 9) break;
        if (max3 >= A[x3-1][y3+1]) max3 = max3;
        else max3 = A[x3-1][y3+1];
        x3 = x3 - 1;
        y3 = y3 + 1;
        if (x3 == 0 || y3 == 9) break;
    };

    int max4 = A[x4][y4];
    while (x4 >= 0 && y4 <= 9 ){
        if (x4 == 9 || y4 == 0) break;
        if (max4 >= A[x4+1][y4-1]) max4 = max4;
        else max4 = A[x4+1][y4-1];
        x4 = x4 + 1;
        y4 = y4 - 1;
        if (x4 == 9 || y4 == 0) break;
    };
    int B[4] = {max1, max2, max3, max4};
    max = B[0];
    for (int b = 1; b <= 3; b++){
        if (max > B[b]) max = max;
        else max = B[b];
    }
    if (abs(A[x][y]) <= max) {
        EXP1 = ceil(EXP1 + EXP1*12/100.0); 
        HP1 = ceil(HP1 + HP1*10/100.0);
        EXP2 = ceil(EXP2 + EXP2*12/100.0); 
        HP2 = ceil(HP2 + HP2*10/100.0);
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
        if (HP2 > 666) HP2 = 666;
        else if (HP2 < 0) HP2 = 0;
        if (EXP2 > 600) EXP2 = 600;
        else if (EXP2 < 0) EXP2 = 0;
        return max;
    }
    else {
        EXP1 = ceil(EXP1 - EXP1*12/100.0); 
        HP1 = ceil(HP1 - HP1*10/100.0);
        EXP2 = ceil(EXP2 - EXP2*12/100.0); 
        HP2 = ceil(HP2 - HP2*10/100.0);
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
        if (HP2 > 666) HP2 = 666;
        else if (HP2 < 0) HP2 = 0;
        if (EXP2 > 600) EXP2 = 600;
        else if (EXP2 < 0) EXP2 = 0;
        return A[x][y];
    }    
}
}

// Task 4
int checkPassword(const char* s, const char* email){
    char se[100] = {};
    int n = strlen(s), m = 0;

    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] != '@') {
            se[i] = email[i];
            m = m + 1;
        }
        else break;
    }
    if (n < 8) return -1;
    else if (n > 20)  return -2;
    
    for (int x = 0; x < n - m + 1; x++) {
        int t;
        for (t = 0; t < m; t++) {
            if (se[t] != s[t + x]) 
            break;
        }
    if (t == m) 
        return -(300 + x); 
    }
    for (int y = 0; y < n; y++) {
            if (!((s[y] == 64) || (s[y] == 35) || (s[y] == 37) || (s[y] == 36) || (s[y] == 33) || ((s[y] > 47) && (s[y] < 58)) || ((s[y] > 64) && (s[y] < 91)) || ((s[y] > 96) && (s[y] < 123))))
                return y;
        }
    

    for (int t = 0; t < n - 2; t++) {
            if ((s[t] == s[t + 1]) && (s[t + 1] == s[t + 2])) 
                return -(400 + t); 
        }
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    for (int u = 0; u < n; u++) {
        if(s[u] == 64 ) a = a + 1;
        if(s[u] == 33 ) b = b + 1;
        if(s[u] == 35 ) c = c + 1;
        if(s[u] == 36 ) d = d + 1;
        if(s[u] == 37 ) e = e + 1;         
    }
    if ((a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0))
    return -5;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int dem[1000][2];
    int maxHere[1000][2];
    for (int i = 0; i < num_pwds; i++) {
        dem[i][0] = 0;
        maxHere[i][0] = 0;
    }
    
    for (int i = 0; i < num_pwds ; i++) {
        int count = 0;
        for (int j = i + 1; j < num_pwds; j++) {
            if (arr_pwds[i] == arr_pwds[j]) {
                count++;
            }
        }
        dem[i][0] = count;
    }
    for (int i = 0; i < num_pwds ; i++){
    dem [i][1] = strlen(arr_pwds[i]); 
    }

    int max = dem[0][0];
    
    int tam = 0;
    int trung = 0;

    for (int n = 0; n < num_pwds; n++){
        if (max < dem[n][0]) {
            max = dem[n][0];
        }     
        
    }
    for (int m = 0; m < num_pwds; m++){
        if (max == dem[m][0]) trung = trung + 1;
    }
    if (trung == 1) {
        for (int a = 0; a < num_pwds; a++){
            if (max == dem[a][0]) return a;
        }
    }
    else {
        for (int a = 0; a < num_pwds; a++){
            if (max == dem[a][0]) {
                maxHere[a][0] = a;
                maxHere[a][1] = dem[a][1];
            }
        }
        int tam = 0;
        for (int b = 0; b < num_pwds; b++){
            if (tam < maxHere[b][1]) tam = maxHere[b][1];
        } 
        for (int b = 0; b < num_pwds; b++){
            if (tam == maxHere[b][1]) return b;
        }
    };
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////