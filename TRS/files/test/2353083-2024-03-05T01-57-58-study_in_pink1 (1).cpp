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

//Pre Code
    void MaxHP(int &HP) {
        if (HP < 0) HP = 0;
        else if (HP > 666) HP = 666; }

    void MaxEXP(int &EXP) {
        if (EXP < 0) EXP = 0;
        else if (EXP > 600) EXP = 600; }

    void MaxMoney(int &M) {
        if (M < 0) M = 0;
        else if (M > 3000) M = 3000; }

//Pre Task 1
        void Data1(int &EXP2, float E1) {
            EXP2 = ceil(EXP2 + (E1/4 + 19));
            MaxEXP(EXP2); 
        } 

        void Data2(int &EXP2, float E1) {
            EXP2 = ceil(EXP2 + (E1/9 + 21));
            MaxEXP(EXP2);
        } 
    
        void Data3(int &EXP2, float E1) {
            EXP2 = ceil(EXP2 + (E1/16 + 17));
            MaxEXP(EXP2);
        } 

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
        // TODO: Complete this function
    MaxEXP(exp1);
    MaxEXP(exp2);
    
    if (e1 >= 0 && e1 <= 3) 
    {
        switch (e1) 
        {
            case 0: 
                exp2 += 29;
                MaxEXP(exp2);
                break;
                    
            case 1:
                exp2 += 45;
                MaxEXP(exp2);
                break;
                    
            case 2: 
                exp2 += 75;
                MaxEXP(exp2);
                break;
                    
            case 3: 
                exp2 = exp2 + (29 + 45 + 75);
                MaxEXP(exp2);
                break;
        }

        int D;
        D = e1 * 3 + exp1 * 7;
        if ( D % 2 == 0) {
        exp1 = ceil(exp1 + D/200); 
        }
            else { 
        exp1 = ceil(exp1 - D/100);
        }
        MaxEXP(exp1);
    }
    
    else if (e1 >= 4 && e1 <= 99) 
    {
        switch (e1)
        {
        case 4 ... 19: 
             Data1(exp2, e1);
            break;
            
        case 20 ... 49: 
             Data2(exp2, e1);
            break;
            
        case 50 ... 65: 
             Data3(exp2, e1);
            break;
            
        case 66 ... 79: 
             Data1(exp2, e1);
            if (exp2 > 200) {
             Data2(exp2, e1); 
            }
            break;
            
        case 80 ... 99: 
             Data1(exp2, e1);
             Data2(exp2, e1);
            if (exp2 > 400) {
                Data3(exp2, e1);
            exp2 = ceil(exp2 + exp2 * 0.15); 
            MaxEXP(exp2);
            }
            break;
        }

    exp1 = exp1 - e1;
    MaxEXP(exp1);
    }
    
    else {
    return -99; 
    }
    return exp1 + exp2;
}

//Pre Task 2
        bool Inspect(int EXP1) {
            if (sqrt(EXP1) - floor(sqrt(EXP1)) == 0) {
                return true;
            }
            
            else {
                return false;
            }
        }

        int Up, Down, n; 

        void Find(int EXP1, int &S) {
        
         if (Inspect(EXP1) == false) 
        {
        n = EXP1 - 1;

         while (!Inspect(n)) {
             n--;
         }
        Down = n;
        
        n = EXP1 + 1;

         while (!Inspect(n)) {
             n++;
         }
        Up = n;

         if (Up - EXP1 <= EXP1 - Down ) { 
             S = Up;
         }

         else {
             S = Down;
         }
        }

         else { 
             S = EXP1;
         }
        }
        
        void Odds(float EXP1, float S, float &P) {
         if (EXP1 >= S) {
             P = 100;
         }
         else P = (((EXP1/S)+80)/123)*100;
        }
        
        void Food(int &HP1, int &M1, int &Spare) {
            if (HP1 < 200) {
                HP1 = ceil(HP1 + HP1 * 0.3);
                MaxHP(HP1);
                
                M1 -= 150;
                Spare += 150;
                MaxMoney(M1);
            }

            else {
                HP1 = ceil(HP1 + HP1 * 0.1);
                MaxHP(HP1);
                
                M1 -= 70;
                Spare += 70;
                MaxMoney(M1);
            }
        }

        void Ride(int &EXP1, int &M1, int &Spare) {
            if (EXP1 < 400) {
                M1 -= 200;
                Spare += 200;
                MaxMoney(M1);
            }

            else {
                M1 -= 120;
                Spare += 120;
                MaxMoney(M1);
            }
            EXP1 = ceil(EXP1 + EXP1 * 0.13);
            MaxEXP(EXP1);
        }

        void Believe(int &EXP1, int &M1, int &Spare) {
            if (EXP1 < 300) {
                M1 -= 100;
                Spare += 100;
                MaxMoney(M1);
            }

            else {
                M1 -= 120;
                Spare += 120;
                MaxMoney(M1);
            }
            EXP1 = ceil(EXP1 - EXP1 * 0.1);
            MaxEXP(EXP1); 
        }
        
        void Lvlup(int &EXP1, int &HP1) {
            HP1 = ceil(HP1 - HP1 * 0.17);
            MaxHP(HP1);
            
            EXP1 = ceil(EXP1 + EXP1 * 0.17);
            MaxEXP(EXP1);
        }

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    MaxHP(HP1);
    MaxEXP(EXP1);
    MaxMoney(M1);
    
    if (E2 < 0 || E2 > 99) {
        return -99; 
    }
    float P1, P2, P3;
    int S;
    
    Find(EXP1, S);
    
    Odds(EXP1, S, P1);
    
    int Spare = 0;
    if (E2 % 2 == 0) {
        while (M1 == 0) {
            break;
        }
        
        Food(HP1, M1, Spare);
        
        while (M1 == 0) {
            break;
        }
        
        Ride(EXP1, M1, Spare);
        
        while (M1 == 0) { 
            break;
        }
        
        Believe(EXP1, M1, Spare);
        
        while (M1 == 0) {
            break;
        }
    }

    else {
        if (M1 != 0) {
            int M0 = M1; 
            
        while (true) {
            if (Spare > M0 * 0.5) {
                break;
            }
            
            Food(HP1, M1, Spare);
            
            if (Spare > M0 * 0.5) {
                break;
            }
            
            Ride(EXP1, M1, Spare);
            
            if (Spare > M0 * 0.5) {
                break;
            }
            
            Believe(EXP1, M1, Spare);
        }
        }
    }
    
    Lvlup(EXP1, HP1); 

    Find(EXP1, S);

    Odds(EXP1, S, P2);

    int i;
    float P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10) {
        i = E2;
    }
    else {
        i = (E2%10 + E2/10)%10; 
    }
    
    if (P1 == P2 && P2 == P[i] && P[i] == 100) {
        EXP1 = ceil(EXP1 + EXP1 * 0.25);
        MaxEXP(EXP1);
    }
    else {
        if (((P1+P2+P[i])/3) < 50) {
            HP1 = ceil(HP1 - HP1 * 0.15);
            MaxHP(HP1);
            
            EXP1 = ceil(EXP1 + EXP1 * 0.15);
            MaxEXP(EXP1);
        }
        else {
            HP1 = ceil(HP1 - HP1 * 0.1);
            MaxHP(HP1);
            
            EXP1 = ceil(EXP1 + EXP1 * 0.2);
            MaxEXP(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    MaxHP(HP1);
    MaxEXP(EXP1);
    MaxHP(HP2);
    MaxEXP(EXP2);

    if (E3 < 0 || E3 > 99) {
        return -99;
        }
        
    int Taxi[10][10] = {0}; 
    
    int x, y; 
    for (x = 0; x < 10; ++x) {
        for (y = 0; y < 10; ++y) {
            Taxi[x][y] = ((E3*y) + (x*2))*(x - y);
        }
    }

    int rise = 0, fall = 0; 
    for (x = 0; x < 10; ++x) {
        for (y = 0; y < 10; ++y) {
            if (Taxi[x][y] > (E3*2)) { 
                rise++; 
            }
            if (Taxi[x][y] < 0 - E3) {
                fall++; 
            }
        }
    }

    while ((fall/10) != 0) {
        fall = (fall%10 + fall/10);
    }
    while ((rise/10) != 0) {
        rise = (rise%10 + rise/10);
    }
    
    int Max = 0;

    x = rise;
    y = fall;
    while (true) {
        x--;
        y--;
        
        if (x < 0 || y < 0) {
            break;
        }
        
        if (Max < Taxi[x][y]) {
            Max= Taxi[x][y];
        }
    }

    x = rise;
    y = fall;
    while (true) {
        x++;
        y++;
        
        if (x > 9 || y > 9) {
            break;
        }
        
        if(Max < Taxi[x][y]) {
            Max = Taxi[x][y];
        }
    }

    x = rise;
    y = fall;
    while (true) {
        x--;
        y++;
        
        if (x < 0 || y > 9) {
            break;
        }
        
        if(Max < Taxi[x][y]) {
            Max= Taxi[x][y];
        }
    }

    x = rise;
    y = fall;
    while (true) {
        x++;
        y--;
        
        if (x > 9 || y < 0) {
            break;
        }
        
        if (Max < Taxi[x][y]) {
            Max= Taxi[x][y];
        }
    }

    if (abs(Taxi[rise][fall]) > abs(Max)) {
        HP1 = ceil(HP1 - HP1*0.1);
        MaxHP(HP1);
        
        EXP1 = ceil(EXP1 - EXP1*0.12);
        MaxEXP(EXP1);
                
        HP2 = ceil(HP2 - HP2*0.1);
        MaxHP(HP2);

        EXP2 = ceil(EXP2 - EXP2*0.12);
        MaxEXP(EXP2);

        Max = Taxi[rise][fall]; 
    }
    else {
        HP1 = ceil(HP1 + HP1*0.1);
        MaxHP(HP1);
        
        EXP1 = ceil(EXP1 + EXP1*0.12);
        MaxEXP(EXP1);
        
        EXP2 = ceil(EXP2 + EXP2*0.12);
        MaxEXP(EXP2);
        
        HP2 = ceil(HP2 + HP2*0.1);
        MaxHP(HP2);
    }
    return Max;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    char se[100];
    const char* Point = strchr(email, '@');
    int length = Point - email;

    strncpy(se, email, length);
    se[length] = '\0';

    int length0 = strlen(s);
    if (length0 > 20) {
        return -2; 
    } 
    if (length0 < 8) {
        return -1;
    }

    const char* seInst = strstr(s, se);
    if (seInst != nullptr) {
        return -(seInst - s + 300); 
    }

    for (int z = 0; z < length0 - 2; z++) { 
        if (s[z] == s[z + 2] && s[z] == s[z + 1]) {
            return -(z + 400);
        }
    }

    const char* Special = "!@#$%";
    if (strpbrk(s, Special) == nullptr) {
        return -5;
    }

    for (int z = 0; z < length0; z++) { 
        char Checking = s[z];
        if (!(toupper(Checking) || isdigit(Checking) || tolower(Checking) || Checking == '$' || Checking == '#' || Checking == '!' || Checking == '@' || Checking == '%')) {
            return z;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int* freq = new int[num_pwds]();  
    int max_freq = 0; 
    int max_len = 0; 
    int correct_pos;
    int* len = new int[num_pwds](); 

    for (int i = 0; i < num_pwds; i++) { 
        const char * pwd = arr_pwds[i];
        len[i] = strlen(pwd); 
        freq[i] = 1;
        for (int j = i; j < num_pwds; j++) {
            if (strcmp(pwd, arr_pwds[j]) == 0) { 
                freq[i]++;
            }
        }
    }

    for (int i = 0; i < num_pwds; ++i) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            max_len = len[i];
            correct_pos = i;
        }
        else if (freq[i] == max_freq && len[i] > max_len)
        {
            max_freq = freq[i];
            max_len = len[i];
            correct_pos = i;
        }
    }

    delete[] len;
    delete[] freq;
    return correct_pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////