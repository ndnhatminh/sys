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
    if (e1 < 0 || e1 > 99)
    return -99;
    else 
    {   
        if (exp1 < 0) {exp1 = 0;} if (exp1 > 600) {exp1 = 600;}
        if (exp2 < 0) {exp2 = 0;} if (exp2 > 600) {exp2 = 600;}
        if (e1 >= 0 && e1 <= 3)
        {
            if (e1 == 0)     exp2 += 29;
            if (e1 == 1)     exp2 += 45;
            if (e1 == 2)     exp2 += 75;
            if (e1 == 3)     exp2 += 29 + 45 + 75;
            if (exp2 > 600) {exp2 = 600;}
            int D = e1*3 + exp1*7;
            if (D % 2 ==0)   exp1 = ceil(-1e-9 + exp1 + D*1.0f/200);
            else             exp1 = ceil(-1e-9 + exp1 - D*1.0f/100);
            if (exp1 < 0) {exp1 = 0;} if (exp1 > 600) {exp1 = 600;}
        }
        else if (e1 >=4 && e1 <=99)
        {
            if (e1 >=4 && e1 <= 19)     exp2 = ceil(-1e-9 + exp2 + (e1*1.0f/4 + 19));
            if (e1 >=20 && e1 <= 49)    exp2 = ceil(-1e-9 + exp2 + (e1*1.0f/9 + 21));
            if (e1 >=50 && e1 <= 65)    exp2 = ceil(-1e-9 + exp2 + (e1*1.0f/16 + 17));
            if (e1 >=66 && e1 <= 79)   {exp2 = ceil(-1e-9 + exp2 + (e1*1.0f/4 + 19)); if (exp2 > 600) exp2 = 600; if (exp2 > 200) exp2 = ceil(-1e-9 + exp2 + (e1*1.0f/9 + 21));};
            if (e1 >=80 && e1 <= 99)   {exp2 = ceil(-1e-9 + exp2 + (e1*1.0f/4 + 19)); exp2 = ceil(-1e-9 + exp2 + (e1*1.0f/9 + 21)); if (exp2 > 600) exp2 = 600; if (exp2 > 400) {exp2 = ceil(-1e-9 + exp2 + (e1*1.0f/16 + 17)); exp2= ceil(-1e-9 + exp2*1.15);}};
            if (exp2 > 600) {exp2 = 600;}
            exp1 -= e1;
            if (exp1 < 0) {exp1 = 0;}
        }
        return exp1 + exp2;
    }   
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    int S1,S2,s1,s2,M1_S=0,i;
    float P=1.00,P1,P2,P3;
    int Pi[10]={32,47,28,79,100,50,22,83,64,11};
    if (E2 < 0 || E2 > 99)
    return -99;
    else {
    if (HP1 < 0) {HP1 = 0;} if (HP1 > 666) {HP1 = 666;}
    if (EXP1 < 0) {EXP1 = 0;} if (EXP1 > 600) {EXP1 = 600;}
    if (M1 < 0) {M1 = 0;} if (M1 > 3000) {M1 = 3000;}    
    // Road 01
    s1 = sqrt(EXP1); s2 = ceil(-1e-9 + sqrt(EXP1));
    S1 = s1*s1; S2 = s2*s2;
    if (abs(EXP1-S1)>=abs(EXP1-S2))
    {
        if (EXP1 >= S2) P1 = 1.00;
        else P1 = (EXP1*1.0f/S2 + 80)/123;
    }
    else 
    {
        if (EXP1 >= S1) P1 = 1.00;
        else P1 = (EXP1*1.0f/S1 + 80)/123;
    }
    // Road 02
    if (E2 % 2 != 0)
    {
        while (M1_S <= M1 && M1 != 0)
        {
            if (HP1 < 200) {HP1 = ceil(-1e-9 + HP1*1.3); M1 -= 150; M1_S +=150; if (M1 < 0) M1 = 0; if (M1_S > M1) break;}
            else {HP1 = ceil(-1e-9 + HP1*1.1); if (HP1 > 666) HP1 = 666; M1 -= 70; M1_S += 70; if (M1 < 0) M1 = 0; if (M1_S > M1) break;}
            if (EXP1 < 400) {M1 -= 200; M1_S += 200; EXP1 = ceil(-1e-9 + EXP1*1.13); if (EXP1 > 600) EXP1 = 600; if (M1 < 0) M1 = 0; if (M1_S > M1) break;}
            else {M1 -= 120; M1_S += 120; EXP1 = ceil(-1e-9 + EXP1*1.13); if (EXP1 > 600) EXP1 = 600; if (M1 < 0) M1 = 0; if (M1_S > M1) break;}
            if (EXP1 < 300) {M1 -= 100; M1_S += 100; EXP1 = ceil(-1e-9 + EXP1*0.90); if (M1 < 0) M1 = 0; if (M1_S > M1) break;}
            else {M1 -= 120; M1_S += 120; EXP1 = ceil(-1e-9 + EXP1*0.90); if (M1 < 0) M1 = 0; if (M1_S > M1) break;}
        }
        HP1 = ceil(-1e-9 + HP1*0.83); EXP1 = ceil(-1e-9 + EXP1*1.17); if (EXP1 > 600) {EXP1 = 600;}
    }      
    else
    {
        do
        {
            if (M1 == 0) {break;}
            if (HP1 < 200) {HP1 = ceil(-1e-9 + HP1*1.3); M1 -= 150; M1_S +=150; if (M1 <= 0) {M1 = 0; break;}}
            else {HP1 = ceil(-1e-9 + HP1*1.1); if (HP1 > 666) HP1 = 666; M1 -= 70; M1_S += 70; if (M1 <= 0) {M1 = 0; break;}}
            if (EXP1 < 400) {M1 -= 200; M1_S += 200; EXP1 = ceil(-1e-9 + EXP1*1.13); if (EXP1 > 600) EXP1 = 600; if (M1 <= 0) {M1 = 0; break;}}
            else {M1 -= 120; M1_S += 120; EXP1 = ceil(-1e-9 + EXP1*1.13); if (EXP1 > 600) EXP1 = 600; if (M1 <= 0) {M1 = 0; break;}}
            if (EXP1 < 300) {M1 -= 100; M1_S += 100; EXP1 = ceil(-1e-9 + EXP1*0.90); if (M1 <= 0) {M1 = 0; break;}}
            else {M1 -= 120; M1_S += 120; EXP1 = ceil(-1e-9 + EXP1*0.90); if (M1 <= 0) {M1 = 0; break;}}
        } while(false);
        HP1 = ceil(-1e-9 + HP1*0.83); EXP1 = ceil(-1e-9 + EXP1*1.17); if (EXP1 > 600) {EXP1 = 600;}
    }
    s1 = sqrt(EXP1); s2 = ceil(-1e-9 + sqrt(EXP1));
    S1 = s1*s1; S2 = s2*s2;
    if (abs(EXP1-S1)>=abs(EXP1-S2))
    {
        if (EXP1 >= S2) P2 = 1.00;
        else P2 = (EXP1*1.0f/S2 + 80)/123;
    }
    else 
    {
        if (EXP1 >= S1) P2 = 1.00;
        else P2 = (EXP1*1.0f/S1 + 80)/123;
    }
    // Road 03
    if (E2 < 10) i = E2;
    else i = (E2%10 + E2/10)%10;
    P3 = Pi[i]*1.0f/100;
    if (P1 == 1.00 && P2 == 1.00 && P3 == 1.00) {EXP1 = ceil(-1e-9 + EXP1*0.75);}
    else {P = (P1 + P2 + P3)/3;
    if (P < 0.50) {HP1 = ceil(-1e-9 + HP1*0.85); EXP1 = ceil(-1e-9 + EXP1*1.15); if (EXP1 > 600) {EXP1 = 600;}}
    else {HP1 = ceil(-1e-9 + HP1*0.90); EXP1 = ceil(-1e-9 + EXP1*1.20); if (EXP1 > 600) {EXP1 = 600;}}}
    return HP1 + EXP1 + M1;
}}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    int const Matrix = 10;
    int MAP[Matrix][Matrix];
    int x=0,y=0,z,t;    // coordinates (x,y) for Taxi and (z,t) for Holmes and Waston
    if (E3 < 0 || E3 > 99)
    return -99;
    else {
    if (HP1 < 0) {HP1 = 0;} if (HP1 > 666) {HP1 = 666;}
    if (EXP1 < 0) {EXP1 = 0;} if (EXP1 > 600) {EXP1 = 600;}
    if (HP2 < 0) {HP2 = 0;} if (HP2 > 666) {HP2 = 666;}
    if (EXP2 < 0) {EXP2 = 0;} if (EXP2 > 600) {EXP2 = 600;}
    for (int i=0; i < Matrix; i++)
    {
        for (int j=0; j < Matrix; j++)
        {
            MAP[i][j] = ((E3*j)+(i*2))*(i-j);
            if (MAP[i][j] > E3*2) {x++;} 
            if (MAP[i][j] < -E3) {y++;}
        }
    }
    if (x > 9) {x = x%10 +x/10;}
    if (x > 9) {x = x%10 +x/10;}
    if (y > 9) {y = y%10 +y/10;}
    if (y > 9) {y = y%10 +y/10;}
    z = x, t = y;
    int Taxi = MAP[x][y];
    int H_W = MAP[x][y];
    if (x >= y)
        {
            for (int a = x-y; a < Matrix; a++)
            {
                if (H_W < MAP[a][a-(x-y)]) {H_W = MAP[a][a-(x-y)]; t = a-(x-y); z = a;}  
            }
            if (x+y < Matrix)
            {
                for (int b = x+y; b >= 0; b--)
                {if (H_W < MAP[b][(x+y)-b]) {H_W = MAP[b][(x+y)-b]; t = (x+y)-b; z = b;}}
            }
            else 
            { 
                for (int b = Matrix - 1; b > (x+y) - Matrix ; b--)
                {if (H_W < MAP[b][(x+y)-b]) {H_W = MAP[b][(x+y)-b]; t = (x+y)-b; z = b;}}
            }
        }
    else
        {
            for (int a = y-x; a < Matrix; a++)
            {
                if (H_W < MAP[a-(y-x)][a]) {H_W = MAP[a-(y-x)][a]; z = a-(y-x); t = a;}  
            }
            if (x+y < 10)
            {
                for (int b = x+y; b >= 0; b--)
                {if (H_W < MAP[(x+y)-b][b]) {H_W = MAP[(x+y)-b][b]; z = (x+y)-b; t = b;}}
            }
            else 
            { 
                for (int b = Matrix - 1; b > (x+y) - Matrix  ; b--)
                {if (H_W < MAP[(x+y)-b][b]) {H_W = MAP[(x+y)-b][b]; z = (x+y)-b; t = b;}}
            }
        }
    if (abs(Taxi) > abs(H_W)) 
    {
        HP1 = ceil(-1e-9 + HP1*0.90); EXP1 = ceil(-1e-9 + EXP1*0.88);
        HP2 = ceil(-1e-9 + HP2*0.90); EXP2 = ceil(-1e-9 + EXP2*0.88);
        return Taxi;
    }    
    else 
    {
        HP1 = ceil(-1e-9 + HP1*1.10); EXP1 = ceil(-1e-9 + EXP1*1.12); if (EXP1 > 600) {EXP1 = 600;}; if (HP1 > 666) {HP1 = 666;};
        HP2 = ceil(-1e-9 + HP2*1.10); EXP2 = ceil(-1e-9 + EXP2*1.12); if (EXP2 > 600) {EXP2 = 600;}; if (HP2 > 666) {HP2 = 666;};
        return H_W;
    }
}}

// Task 4
int checkPassword(const char * s, const char * email) {
    string S = s;
    string Email = email;
    char Check = S[0];
    int Found, count=1, stop, stop_2 = -1;
    bool special = false, val_type_fail = false; 
    size_t pos = Email.find('@');
    int I = S.length();
    char *se = new char[pos+1];
    strncpy(se,email,pos);
    se[pos]='\0';
    if (I < 8) {delete[] se; return -1;}
    else if (I > 20) {delete[] se; return -2;}
    else    
    {
        size_t found = S.find(se);
        if (found != string::npos) {delete[] se; Found = (int)found; return -(300 + Found);}
        else 
        {
            delete[] se; 
            for (int i =0; i < I; i++)
            {
                if (count == 3) {stop = i - 2; break;}
                Check = S[i];
                if (S[i+1] == Check) {count++;}
                else {count = 1;}
                if ((int)Check == 33 || (int)Check == 35 || (int)Check == 36 || (int)Check == 37 || (int)Check == 64) {special = true;}
                if ((Check >= 0 && Check <= 32) || Check == 34 || (Check >= 38 && Check <= 47) || (Check >= 58 && Check <= 63) || (Check >= 91 && Check <= 96) || (Check >= 123)) {val_type_fail = true; if (stop_2 == -1) {stop_2 = i;}}                
            }
            if (count == 3) {return -(400 + stop);}
            else {if (special == false) {return -5;}
            else {if (val_type_fail == true) {return stop_2;}
            else {return -10;}}}
        }
    }
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // Creating a 2D array that store the unique passwords and the number of their appearances 
    int a =0, ap = 0;
    const int MaxSize = num_pwds;
    string Pwds[MaxSize][2];
    Pwds[a][0] = arr_pwds[0];
    for (int i = 0; i < num_pwds; i++)
    {
        for (int b =0; b <= a; b++)
        {
            if (strcmp(arr_pwds[i], Pwds[b][0].c_str()) == 0) {Pwds[b][1] += "1"; break;}
            else if (b == a) {a++; Pwds[a][0] = arr_pwds[i];}
        }
    }
    // Comparing the number of appearances
    string S;
    int AP[a+1];
    AP[0] = Pwds[0][1].length();
    S = Pwds[0][1];
    size_t L = S.length();
    ap = (int)L;
    int Max = ap;
    int j;
    for (j = 1; j <= a; j++)
    {
        S = Pwds[j][1];
        size_t L = S.length();
        ap = (int)L;
        AP[j] = ap;
        if (Max < ap) {Max = ap;}
    }
    // Comparing the length of each password with the highest frequency
    int PwdL[a+1]; int c = 0;
    for (j = 0; j <= a; j++)
    {
        if (AP[j] == Max) {PwdL[c] = j; c++;}
    }
    // Find the position of the right password
    if (c != 1)
    {
        int MaxPL = (int)(Pwds[PwdL[0]][0]).length(), PL;
        for (int d = 0; d < c; d++)
        {
            PL = (int)(Pwds[PwdL[d]][0]).length();
            if (MaxPL < PL) {MaxPL = PL; PwdL[0] = PwdL[d];}
        }
    }
    int True_pos;
    for (int i = 0; i < num_pwds; i++)
    {
        if (strcmp(arr_pwds[i], Pwds[PwdL[0]][0].c_str())==0)
        {True_pos = i; break;}
    }
    return True_pos;
}
/*CURSE THIS FUCKING "ASS"IGNMENT*/
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////