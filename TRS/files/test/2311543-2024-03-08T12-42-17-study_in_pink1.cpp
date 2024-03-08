#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & exp1,
        int & exp2,
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
            >> exp1 >> exp2
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

int CheckEXP(int &x)
{
    if(x > 600)
    {
        x = 600;
    }
    else if(x < 0)
    {
        x = 0;
    }
    return x;
}

int CheckHP(int &y)
{
    if(y > 666)
    {
        y = 666;
    }
    else if(y < 0)
    {
        y = 0;
    }
    return y;
}

int CheckM(int &z)
{
    if(z > 3000)
    {
        z = 3000;
    }
    else if(z < 0)
    {
        z = 0;
    }
    return z;
}



float scp(int exp) 
{
    int s = sqrt(exp), S;
    if (exp - s * s < (s + 1) * (s + 1) - exp) 
    {
        S = s * s;
        return 100;
    }
    else 
    {
        S = (s + 1) * (s + 1);
        return (float(exp) / S + 80) / 123 * 100;
    }
}

bool timKiTuLap(const string & password, int & sci)
{
    for(int i = 0; i < password.length(); i++)
    {
        if(password[i] == password[i + 1] && password[i + 1] == password[i + 2])
        {
            sci = i;
            return true;
        }
    }
    return false;
}
bool koChuaKiTuDB(const string & password)
{
    for(int i = 0; i < password.length(); i++)
    {
        if(password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '!')
        {
            return false;
        }
    }
    return true;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {//done
    // TODO: Complete this function
    if(e1 < 0 || e1 > 99)
    {
        return -99;
    }
    else
    {
        if(e1 <= 3)
        {
            switch(e1)
            {
                case 0:
                {   
                    CheckEXP(exp2);
                    CheckEXP(exp1);
                    exp2 = exp2 + 29;
                    CheckEXP(exp2);
                    int D = e1*3 + exp1*7;
                    if(D % 2 == 0)
                    {
                        double T1 = exp1 + ((double)D/200);
                        exp1 = ceil(T1);
                        CheckEXP(exp1);
                    }
                    else
                    {
                        double T1 = exp1 - ((double)D/100);
                        exp1 = ceil(T1);
                        CheckEXP(exp1);
                    }
                    break;
                }
                case 1:
                {
                    CheckEXP(exp2);
                    CheckEXP(exp1);
                    exp2 = exp2 + 45;
                    CheckEXP(exp2);
                    int D = e1*3 + exp1*7;
                    if(D % 2 == 0)
                    {
                        double T1 = exp1 + ((double)D/200);
                        exp1 = ceil(T1);
                        CheckEXP(exp1);
                    }
                    else
                    {
                        double T1 = exp1 - ((double)D/100);
                        exp1 = ceil(T1);
                        CheckEXP(exp1);
                    }
                    break;
                }
                case 2:
                {
                    CheckEXP(exp2);
                    CheckEXP(exp1);
                    exp2 = exp2 + 75;
                    CheckEXP(exp2);
                    int D = e1*3 + exp1*7;
                    if(D % 2 == 0)
                    {
                        double T1 = exp1 + ((double)D/200);
                        exp1 = ceil(T1);
                        CheckEXP(exp1);
                    }
                    else
                    {
                        double T1 = exp1 - ((double)D/100);
                        exp1 = ceil(T1);
                        CheckEXP(exp1);
                    }
                    break;
                }
                case 3:
                {
                    CheckEXP(exp2);
                    CheckEXP(exp1);
                    exp2 = exp2 + 149;
                    CheckEXP(exp2);
                    int D = e1*3 + exp1*7;
                    if(D % 2 == 0)
                    {
                        double T1 = exp1 + ((double)D/200);
                        exp1 = ceil(T1);
                        CheckEXP(exp1);
                    }
                    else
                    {
                        double T1 = exp1 - ((double)D/100);
                        exp1 = ceil(T1);
                        CheckEXP(exp1);
                    }
                    break;
                }
            }
            return exp1 + exp2;
        }
        else
        {
            if(e1 <= 19 && e1 > 3)
            {
                CheckEXP(exp2);
                CheckEXP(exp1);
                double T1 = exp2 + ((double)e1/4) + 19;
                exp2 = ceil(T1);
                CheckEXP(exp2);
                exp1 = exp1 - e1;
                CheckEXP(exp1);
            }
            else
            {
                if(e1 <= 49  && e1 > 3)
                {
                    CheckEXP(exp2);
                    CheckEXP(exp1);
                    double T1 = exp2 + ((double)e1/9) + 21;
                    exp2 = ceil(T1);
                    CheckEXP(exp2);
                    exp1 = exp1 - e1;
                    CheckEXP(exp1);
                }
                else
                {
                    if(e1 <= 65 && e1 > 3 )
                    {
                        CheckEXP(exp2);
                        CheckEXP(exp1);
                        double T1 = exp2 + ((double)e1/16) + 17;
                        exp2 = ceil(T1);
                        CheckEXP(exp2);
                        exp1 = exp1 - e1;
                        CheckEXP(exp1);
                    }
                    else
                    {
                        if(e1 <= 79 && e1 > 3)
                        {
                            CheckEXP(exp2);
                            CheckEXP(exp1);
                            double T1 = exp2 + ceil((double)e1/4) + 19;
                            exp2 = ceil(T1);
                            CheckEXP(exp2);
                            if(exp2 > 200)
                            {
                                double T1 = exp2 + ceil((double)e1/9) + 21;
                                exp2 = ceil(T1);
                                CheckEXP(exp2);
                            }
                            exp1 = exp1 - e1;
                            CheckEXP(exp1);
                        }
                        else 
                        {
                            if(e1 <= 99 && e1 > 3)
                            {
                                CheckEXP(exp2);
                                CheckEXP(exp1);
                                double T1 = exp2 + ((double)e1/4) + 19;
                                exp2 = ceil(T1);
                                CheckEXP(exp2);
                                T1 = exp2 + ((double)e1/9) + 21;
                                exp2 = ceil(T1);
                                CheckEXP(exp2);
                                if(exp2 > 400)
                                {
                                    T1 = exp2 + ((double)e1/16) + 17;
                                    exp2 = ceil(T1);
                                    CheckEXP(exp2);
                                    exp2 = ceil((double)exp2*1.15);
                                }
                                CheckEXP(exp2);
                                exp1 = exp1 - e1;
                                CheckEXP(exp1);
                            }

                        }
                    }
                }
            }
            return exp1 + exp2;
        }
    }
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {//done
    // TODO: Complete this function
   if(E2 >= 0 && E2 <=99)
    {
    CheckEXP(EXP1);
    CheckHP(HP1);
    CheckM(M1);
    float P1 = scp(EXP1);

    //Path 02
    //E chan
    if(E2 % 2 == 0)
    {   if(M1 != 0)
        {
            for(int i = 0; i < 1; i++)
            {
            if(HP1 < 200)
            {
                HP1 = HP1*1.3 + 0.9999;
                CheckHP(HP1);
                M1 = M1 - 150;
                CheckM(M1);
            }
            else
            {
                HP1 = HP1*1.1 + 0.9999;
                CheckHP(HP1);
                M1 = M1 - 70;
                CheckM(M1);
            }
            if(M1 == 0)
            {
                break;
            }
            if(EXP1 < 400)
            {
                EXP1 = EXP1*1.13 + 0.9999;
                CheckEXP(EXP1);
                M1 = M1 - 200;
                CheckM(M1);
            }
            else
            {
                EXP1 = EXP1*1.13 + 0.9999;
                CheckEXP(EXP1);
                M1 = M1 - 120;
                CheckM(M1);
            }
            if(M1 == 0)
            {
                break;
            }
            if(EXP1 < 300)
            {
                EXP1 = EXP1*0.9 + 0.9999;
                CheckEXP(EXP1);
                M1 = M1 - 100;
                CheckM(M1);
            }
            else
            {
                EXP1 = EXP1*0.9 + 0.9999;
                CheckEXP(EXP1);
                M1 = M1 - 120;
                CheckM(M1);
            }
            if(M1 == 0)
            {
                break;
            }
            }
        }
        EXP1 = EXP1*1.17 + 0.9999;
        CheckEXP(EXP1);
        HP1 = HP1*0.83 + 0.9999;
        CheckHP(HP1);
    }
    //End E chan
    else // E le
    {
        CheckEXP(EXP1);
        CheckHP(HP1);
        CheckM(M1);
        int Tts = 0;
        float Start = (M1/2);
        if(M1 != 0)
        {
            while(1)
        {
            if(HP1 < 200)
            {
                HP1 = HP1*1.3 + 0.9999;
                CheckHP(HP1);
                M1 = M1 - 150;
                CheckM(M1);
                Tts = Tts + 150;
                if((float)Tts > Start)
                {
                    break;
                }
            }
            else
            {
                HP1 = HP1*1.1 + 0.9999;
                CheckHP(HP1);
                M1 = M1 - 70;
                CheckM(M1);
                Tts = Tts + 70;
                if((float)Tts > Start)
                {
                    break;
                }
            }
            if(EXP1 < 400)
            {
                EXP1 = EXP1*1.13 + 0.9999;
                CheckEXP(EXP1);
                M1 = M1 - 200;
                CheckM(M1);
                Tts = Tts + 200;
                if((float)Tts > Start)
                {
                    break;
                }
            }
            else
            {
                EXP1 = EXP1*1.13 + 0.9999;
                CheckEXP(EXP1);
                M1 = M1 - 120;
                CheckM(M1);
                Tts = Tts + 120;
                if((float)Tts > Start)
                {
                    break;
                }
            }
            if(EXP1 < 300)
            {
                EXP1 = EXP1*0.9 + 0.9999;
                CheckEXP(EXP1);
                M1 = M1 - 100;
                CheckM(M1);
                Tts = Tts + 100;
                if((float)Tts > Start)
                {
                    break;
                }
            }
            else
            {
                EXP1 = EXP1*0.9 + 0.9999;
                CheckEXP(EXP1);
                M1 = M1 - 120;
                CheckM(M1);
                Tts = Tts + 120;
                if((float)Tts > Start)
                {
                    break;
                }
            }
        }
        }
        EXP1 = EXP1*1.17 + 0.9999;
        CheckEXP(EXP1);
        HP1 = HP1*0.83 + 0.9999;
        CheckHP(HP1);
    }
    float P2 = scp(EXP1);
    //End Path02
    //Path 03
    float P3;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2 / 10 == 0)
    {
        P3 = (P[E2]);
    }
    else
    {   

        int dv = (E2 % 10);
        int hc = (E2 / 10);
        int i = ((hc + dv) % 10);
        P3 = (P[i]);
    }
    //End Path 03
    double Total = P1 + P2 + P3;
    if(P1 == P2 && P2 == P3 && P1 == 100)
    {
        EXP1 = ceil((float)EXP1*0.75);
        CheckEXP(EXP1);

    }
    else
    {
        double Pfinal = Total/3;
        if(Pfinal < 50)
        {
            HP1 = ceil((float)HP1*0.85);
            CheckHP(HP1);
            EXP1 = ceil((float)EXP1*1.15);
            CheckEXP(EXP1);
        }
        else
        {
            HP1 = ceil((float)HP1*0.9);
            CheckHP(HP1);
            EXP1 = ceil((float)EXP1*1.2);
            CheckEXP(EXP1);
        }
    }
    return HP1 + EXP1 + M1;

    }
    else 
    {
        return -99;
    }
}
//End Task 2

// Task 3
int chaseTaxi(int & HP1, int & exp1, int & HP2, int & exp2, int E3) {// still have 12.5% left
    // TODO: Complete this function
    CheckEXP(exp1);
    CheckEXP(exp2);
    CheckHP(HP1);
    CheckHP(HP2);
    if(E3 >= 0 && E3 <= 99)
    {
        int Taxi[10][10];
        for (int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                Taxi[i][j] = 0;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                Taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        int x = 0;
        int y = 0;
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(Taxi[i][j] > E3*2)
                {
                    x = x + 1;
                }
                else if(Taxi[i][j] < (-E3))
                {
                    y = y + 1;
                }
            }
        }
        while(x > 10)
        {
            x = x / 10 + x % 10;
        }
        while(y > 10)
        {
            y = y/10 + y % 10;
        }
        //X(i;j) la vi tri gap nhau
        int XTaxi = Taxi[x][y];
        int max = Taxi[x][y];
        int x1 = x, y1 = y, x2 = x, y2 = y, x3 = x, y3 = y, x4 = x, y4 = y;
        while(x1 >= 0 && y1 >= 0)
        {
            if(max < Taxi[x1][y1])
            {
                max = Taxi[x1][y1];
            }
            x1--;
            y1--;
        }
        while(x2 >= 0 && y2 <= 9)
        {
            if(max < Taxi[x2][y2])
            {
                max = Taxi[x2][y2];
            }
            x2--;
            y2++;
        }
        while(x3 <= 9  && y3 <= 9)
        {
            if(max < Taxi[x3][y3])
            {
                max = Taxi[x3][y3];
            }
            x3++;
            y3++;
        }
        while(x4 <= 9 && y4 >= 0)
        {
            if(max < Taxi[x4][y4])
            {
                max = Taxi[x4][y4];
            }
            x4++;
            y4--;
        }
        int XSW = abs(max);
        int absTaxi = abs(XTaxi);
        if(absTaxi > XSW)
        {
            exp1 = exp1*0.88 + 0.99999;
            CheckEXP(exp1);
            exp2 = exp2*0.88 + 0.99999;
            CheckEXP(exp2);
            HP1 = HP1*0.9 + 0.99999;
            CheckHP(HP1);
            HP2 = HP2*0.9 + 0.99999;
            CheckHP(HP2);
            return XTaxi;
        }
        else
        {
            exp1 = exp1*1.12 + 0.99999;
            CheckEXP(exp1);
            exp2 = exp2*1.12 + 0.99999;
            CheckEXP(exp2);
            HP1 = HP1*1.1 + 0.99999;
            CheckHP(HP1);
            HP2 = HP2*1.1 + 0.99999;
            CheckHP(HP2);
            return XSW;
        }
    }
    else
    {
        return -99;
    }
    
}

// Task 4
int checkPassword(const char * s, const char * email) {//done
    // TODO: Complete this function
    string password = s;
    string em = email;
    size_t location = em.find('@');
    string se = em.substr(0, location);
    size_t sei = password.find(se);
    int count = 0;
    int sci = 0;
    size_t length = strlen(s);
    //check pass
        if(length < 8)
        {
            return -1;
        }
        else if(length > 20)
        {
            return -2;
        }
        if(sei != string::npos)
        {
            return -(300 + (int)sei);
        }
        if(timKiTuLap(password, sci))
        {
            return -(400 + sci);
        }
        if(koChuaKiTuDB(password))
        {
            return -5;
        }
        for(int i = 0; i < password.length(); i++)
        {
            if(password[i] == '[' || password[i] == ']' || password[i] == '{'
                || password[i] == '}' || password[i] == ';' || password[i] == ':'
                || password[i] == '^' || password[i] == '&' || password[i] == '*'
                || password[i] == '(' || password[i] == ')' || password[i] == '/'
                || password[i] == '?' || password[i] == ',' || password[i] == '<'
                || password[i] == '.' || password[i] == '>' || password[i] == '-'
                || password[i] == '_' || password[i] == '=' || password[i] == '+'
                || password[i] == '|' || password[i] == '`' || password[i] == '~')
            {   
                return i;
            }
        }
        return -10;

        
    //end check pass
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int App = 0; 
    int PwdLength = 0; 
    int Position = 0; 

    for (int i = 0; i < num_pwds; ++i) 
    {
        const char* currentPwd = arr_pwds[i];
        int currentLength = strlen(currentPwd);
        int currentCount = 1;
        for (int j = i + 1; j < num_pwds; ++j) 
        {
            if (strcmp(currentPwd, arr_pwds[j]) == 0) 
            {
                ++currentCount;
            }
        }
        if ((currentCount > App) || (currentCount == App && currentLength > PwdLength)) 
        {
            App = currentCount;
            PwdLength = currentLength;
            Position = i;
        }
    }

    return Position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////