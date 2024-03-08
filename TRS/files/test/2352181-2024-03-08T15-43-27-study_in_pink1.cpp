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
/// 
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
void limitExp(int& exp) {
    if (exp > 600) { exp = 600; };
    if (exp < 0) { exp = 0; };
    
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    //First interaction between Sherlock and Watson
    int D;
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0)
        {
            exp2 += 29;
            limitExp(exp2);
        }
        else if (e1 == 1)
        {
            exp2 += 45;
            limitExp(exp2);
        }
        else if (e1 == 2)
        {
            exp2 += 75;
            limitExp(exp2);
        }
        else if (e1 == 3)
        {
            exp2 += 149;
            limitExp(exp2);
        };
        //The guess of Sherlock about the place Watson served the military
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 =ceil( exp1 + D / 200);
            
            limitExp(exp1);
        }
        else {
            exp1 =ceil(exp1- D / 100);
            limitExp(exp1);
        };
    }
    //The guess of Sherlock about Waston's brother
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 =ceil(exp2+ (e1 / 4.0 + 19));
            limitExp(exp2);
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 =exp2 +  ceil(e1 / 9.0) + 21;
            limitExp(exp2);
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 =exp2 + ceil( (e1 / 16.0 + 17));
            limitExp(exp2);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 =exp2 + ceil((e1 / 4.0 +19));
            limitExp(exp2);
            if (exp2 > 200) {
                exp2 =exp2+ceil( (e1 / 9.0 + 21));
                limitExp(exp2);
            };
        }
        else {
            exp2 =exp2 + ceil( (e1 / 4.0 + 19));
            
            limitExp(exp2);
            exp2 =exp2 +ceil( (e1 / 9.0 + 21));
            
            limitExp(exp2);
            if (exp2 > 400) {
                exp2 =exp2+ ceil((e1 / 16.0 + 17));
                
                limitExp(exp2);
                exp2 =ceil( 1.15*exp2);
                
                limitExp(exp2);
                
            };
            
        };
        exp1 =exp1- e1;

        limitExp(exp1);
    }
    return exp1 + exp2;
}

// Task 2
void limitHealth(int & HP)//Health limit
{
    if (HP > 666) {
        HP = 666;
    }
    else if (HP < 0) {
        HP = 0;
    };
    
}
void limitMoney(int& M)//Limit for money
{
    if (M < 0) { M = 0; }
    else if (M > 3000) {
        M = 3000;
    };
    
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
// TODO: Complete this function
//First Way 

{
    int  P1, P2, P3;
    int MS = 0, S = 0;
    S= round(sqrt(EXP1)) * round(sqrt(EXP1));
if (EXP1 >= S){
    P1 = 1;
}
else {
    P1 = (EXP1 / static_cast<float>(S) + 80) / 1.23;
};
//Second way
if (E2 % 2 != 0) {
    int HM = M1 / 2;
    while (MS <=HM) {
        if (HP1 < 200) //Restoring energy 
        {
            HP1 = ceil(HP1 * 1.3);
            
            limitHealth(HP1);
            M1 -= 200;
            limitMoney(M1);
            MS += 200;
            if (MS > HM) { break; }
        }
        else {
            HP1 = ceil(HP1 * 1.1);
            
            limitHealth(HP1);
            M1 -= 70;
            limitMoney(M1);
            MS += 70;
            if (MS > HM) { break; }

        };
        if (EXP1 < 400)//Chosing transport
        {
            M1 -= 200;
            limitMoney(M1);
            MS += 200;
            if (MS > HM) { break; }
        }
        else {
            M1 -= 120;
            limitMoney(M1);
            MS += 120;
            if (MS > HM) { break; }
        };

        EXP1 = ceil(1.13 * EXP1);
        
        limitMoney(EXP1);
        //Having aid from the homeless guy
        if (EXP1 < 300) {
            M1 -= 100;
            limitMoney(M1);
            MS += 100;
            if (MS > HM) { break; }
        }
        else {
            M1 -= 120;
            limitMoney(M1);
            MS += 120;
            if (MS > HM) { break; }
        };
        EXP1 = ceil(0.9 * EXP1);
        
        limitExp(EXP1);
    }
    HP1 =ceil (0.83 * HP1);
    
    limitHealth(HP1);
    EXP1 = ceil(1.17 * EXP1);
    
    limitExp(EXP1);
}

else {
    if (HP1 < 200 &&M1!=0)
    {
        HP1 = ceil(HP1 * 1.3);
       
        limitHealth(HP1);
        M1 -= 200;
        limitMoney(M1);
       
    }
    else {
        HP1 =ceil ( HP1 * 1.1);
       
        limitHealth(HP1);
        M1 -= 70;
        limitMoney(M1);
       
    };
    if (EXP1 < 400&&M1!=0)
    {
        M1 -= 200;
        limitMoney(M1);
        
    }
    else if(EXP1>=400 && M1!=0)
    {M1 -= 120;
        limitMoney(M1);
      
    };

    EXP1 = ceil(1.13 * EXP1);
    
    limitMoney(EXP1);
    //Having aid from the homeless guy
    if (EXP1 < 300 && M1!=0){
        M1 -= 100;
        limitMoney(M1);
        
    }
    else if(EXP1>=300 && M1!=0)
    {
        M1 -= 120;
        limitMoney(M1);
       
    };
    EXP1 =ceil (0.9 * EXP1);
    
    limitExp(EXP1);
    HP1 = ceil(0.83 * HP1);
    
    limitHealth(HP1);
    EXP1 =ceil (1.17 * EXP1);
    
    limitExp(EXP1);
};
S = round(sqrt(EXP1)) * round(sqrt(EXP1));
if (EXP1 >= S) {
    P2 = 100;
}
else {
    P2 = (EXP1 / (S) + 80) / 1.23;
};
//Third way
 int P[10] = { 32,47,28,79,100,50,22,83,64,11 };
if (E2 < 10) {
    P3 = P[E2];
}
else {
    P3 = P[((E2 % 10) + ((E2) - E2 % 10) / 10) % 10];
};
if ((P1 + P2 + P3 / 100) / 3 == 1) {
    EXP1 = ceil(0.75 * EXP1);
    
}
else if (((P1) + P2 + P3 / (100)) / 3 >= 0.5) {
    HP1 =ceil( HP1 * 0.9);
    
    limitHealth(HP1);
    EXP1 =ceil( EXP1 * 1.2);
   
    limitExp(EXP1);

}
else {
    HP1 =ceil (0.85 * HP1);
    
    limitHealth(HP1);
    EXP1 =ceil (EXP1 * 1.2);
   
    limitExp(EXP1);
};
    return HP1 + EXP1 + M1;
}

// Task 3
//Finding the place Sherlock catch up the taxi
void IP(int& C)
{
    while (C >= 10) {
        C = (C - (C % 10)) / 10 + (C % 10);
    }
    
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int MAX1, MAX2, MAX, C1, C2;
    int Taxi[10][10]{};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            Taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (Taxi[i][j] > (E3 * 2) && Taxi[i][j] >= 0) {
                 C1 = C1+1;
            };
            if (Taxi[i][j] < (-E3) && Taxi[i][j] < 0) {
                 C2 = C2+1;
            };
        }
    }
        //The place Sherlock catch up the taxi
        IP(C1);
        IP(C2);
        int PoT = Taxi[C1][C2];//Point of Taxi at the place
        //Calculating Sherlocks Point 
        int b = C2;
        MAX1 = Taxi[C1][C2];
        for (int a = C1; a < 10; a++)//dctx
        {
            if (Taxi[a][b] > MAX1) { MAX1 = Taxi[a][b]; }
            b--;
            if (b < 0) { break; }
        }
        b = C2;
        for (int a = C1; a >= 0; a--)//dctl
        {
            if (Taxi[a][b] > MAX1) { MAX1 = Taxi[a][b]; }
            b++;
            if (b >= 10) { break; }
        }
        b = C2;
        MAX2 = Taxi[C1][C2];
        for (int a = C1; a < 10; a++)//dcpx
        {
            if (Taxi[a][b] > MAX2) { MAX2 = Taxi[a][b]; }
            b++;
            if (b >= 10) { break; }
        }
        b = C2;
        for (int a = C1; a >= 0; a--)//dcpt
        {
            if (Taxi[a][b] > MAX2) { MAX2 = Taxi[a][b]; }
            b--;
            if (b < 0) { break; }
        }
        if (MAX1 > MAX2) { MAX = MAX1; }
        else { MAX = MAX2; };
        if (MAX > abs(PoT))
        {
            EXP1 =ceil( EXP1 * 1.12);
            limitExp(EXP1);
            EXP2 = ceil(EXP2 * 1.12);
            limitExp(EXP2);
            HP1 = ceil(HP1 * 1.1);
            limitHealth(HP1);
            HP2 = ceil(HP2 * 1.1);
            limitHealth(HP2);
            return MAX;
        }
        else {
            EXP1 = ceil(EXP1 * 0.88);
            limitExp(EXP1);
            EXP2 = ceil(EXP2 * 0.88);
            limitExp(EXP2);
            HP1 = ceil(HP1 * 0.9);
            limitHealth(HP1);
            HP2 = ceil(HP2 * 0.9);
            limitHealth(HP2);
            return PoT;
        }
    return -1;
}
   
// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    string username = email;
    string se = "";
    for (int i = 0; i < username.size(); i++)
    {
        se += username[i];
        if (username[i+1] == '@') { break; }
    }
    string password = s;
    if (password.size() < 8) { return -1; }
    else if (password.size() > 20) { return -2; }
    else if (password.find(se) != -1)//the place appears the repeat of username
    {
        return -(300 + password.find(se));
    }

    for (int i = 0; i < password.size() - 2; i++)
    {
        if (username[i] == username[i + 1] && username[i + 1] == username[i + 2])
        {
            return -(400 + i);
        }
    }


    for (int i = 0; i < password.size(); i++)
    {
        if (username[i] != '@' && username[i] != '#' && username[i] != '$' && username[i] != '%' && username[i] != '!')
        {
            return -5;
        }

    }


    for (int i = 0; i < password.size(); i++)
    {
        if (username[i] == '^' || username[i] == '&' || username[i] == '*' || username[i] == '(' || username[i] == ')' || username[i] == '-' || username[i] == '_' || username[i] == '+' || username[i] == '=' || username[i] == '{' || username[i] == '[' || username[i] == '}' || username[i] == ']' || username[i] == '|' || username[i] == ';' || username[i] == ':' || username[i] == '"' || username[i] == '?' || username[i] == '/' || username[i] == '.' || username[i] == ',')
            return i;
    }


    return -10;



    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string arr_likelyPassword[num_pwds];
    string correctPassword;
    int maxcount = 1;
    int correctPasswordIndex = -1;
    for (int i = 0; i < num_pwds; i++)
    {
         arr_likelyPassword[i] = arr_pwds[i];
    }
    for (int i = 0; i < num_pwds; i++)
    {
        int count = 1;
        for (int j = i + 1; j <= num_pwds-1; j++)
        {
            if (arr_likelyPassword[i] == arr_likelyPassword[j])
            {
                count++;
            }
        }
        if (count > maxcount)
        {
            correctPassword = arr_likelyPassword[i];
            maxcount = count;
            correctPasswordIndex = i;
        }
        else if (count == maxcount)
        {
            if (arr_likelyPassword[i].length() > correctPassword.length())
            {
                correctPassword = arr_likelyPassword[i];
                correctPasswordIndex = i;
            }
        }
        
    }
    return correctPasswordIndex;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////