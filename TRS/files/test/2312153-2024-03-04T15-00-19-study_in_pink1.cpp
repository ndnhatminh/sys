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
int firstMeet(int & exp1, int & exp2, int e1) 
{
    //input validation
    if (e1 < 0 || e1 > 99) return -99;
    if (exp1 < 0) exp1 = 0;
    if (exp1 > 600) exp1 = 600;
    if (exp2 < 0) exp2 = 0;
    if (exp2 > 600) exp2 = 600;
    if (e1 <= 3) //case 1
    {
        switch (e1)
        {
            case 0: exp2 += 29; break;
            case 1: exp2 += 45; break;
            case 2: exp2 += 75; break;
            case 3: exp2 += 149;
        }
        int d = e1*3 + exp1*7;
        if (d%2) exp1 -= d/100;
        else exp1 += ceil(float(d/200.0));
    }
    else //case 2
    {
        if (e1 <= 19) exp2 += ceil(float(e1/4.0)) + 19;
        if (e1 >= 20 && e1 <= 49) exp2 += ceil(float(e1/9.0)) + 21;
        if (e1 >= 50 && e1 <= 65) exp2 += ceil(float(e1/16.0)) + 17;
        if (e1 >= 66 && e1 <= 79) 
        {
            exp2 += ceil(float(e1/4.0) + 19);
            if (exp2 > 200) exp2 += ceil(float(e1/9.0)) + 21;
        }
        if (e1 >= 80)
        {
            exp2 += ceil(float(e1/4.0)) + 19;
            exp2 += ceil(float(e1/9.0)) + 21;
            if (exp2 > 400) 
            {
                exp2 += ceil(float(e1/16.0)) + 17;
                exp2 = ceil(float(exp2*1.15));
            }
        }
        exp1 -= e1;
    }
    //data validation
    if (exp1 < 0) exp1 = 0;
    if (exp1 > 600) exp1 = 600;
    if (exp2 > 600) exp2 = 600;
    return exp1 + exp2;
}

int findOdd(int exp1)
{
    int n = sqrt(exp1);
    if ((exp1 - n*n) > ((n+1)*(n+1) - exp1)) return 66;
    return 100;
}

int event(int & hp1, int & exp1, int & m1, int eventIndex)
{
    switch (eventIndex)
    {
        case 0: 
            if (hp1 < 200) 
            {
                hp1 = ceil(float(hp1*1.3));
                m1 -= 150;
                return 150;
            }
            else 
            {
                hp1 = ceil(float(hp1*1.1));
                m1 -= 70;
                return 70;
            }
        case 1: 
            if (exp1 < 400)
            {
                m1 -= 200;
                exp1 = ceil(float(exp1*1.13));
                return 200;
            } 
            else 
            {
                m1 -= 120;
                exp1 = ceil(float(exp1*1.13));
                return 120;
            }
        default:
            if (exp1 < 300) 
            {
                m1 -= 100;
                exp1 = ceil(float(exp1*0.9));
                return 100;
            }
            else 
            {
                m1 -= 120; 
                exp1 = ceil(float(exp1*0.9));
                return 120;
            }
    }  
}

// Task 2: 2 sub-func: event manager, find odds
int traceLuggage(int & hp1, int & exp1, int & m1, int e2) 
{
    //input validation
    if (e2 < 0 || e2 > 99) return -99;
    if (exp1 < 0) exp1 = 0;
    if (exp1 > 600) exp1 = 600;
    if (hp1 < 0) hp1 = 0;
    if (hp1 > 666) hp1 = 666;
    if (m1 < 0) m1 = 0;
    if (m1 > 3000) m1 = 3000;
    //road 1
    int p1 = findOdd(exp1);
    //road 2
    if (e2%2) 
    {
        int cost = 0, eventIndex = 0; //updating event and exit condition
        while (m1 != 0 && cost <= m1)
        {
            cost += event(hp1, exp1, m1, eventIndex);
            //data validation
            if (m1 < 0) m1 = 0;
            if (hp1 > 666) hp1 = 666;
            if (exp1 > 600) exp1 = 600;
            eventIndex = (++eventIndex)%3;
        }
    }
    else
    {
        for (int eventIndex = 0; eventIndex < 3; eventIndex++)
        {
            if (m1 == 0) break;
            event(hp1, exp1, m1, eventIndex);
            //data validation
            if (m1 < 0) m1 = 0;
            if (hp1 > 666) hp1 = 666;
            if (exp1 > 600) exp1 = 600;
        }
    }
    hp1 = ceil(float(hp1*0.83));
    exp1 = ceil(float(exp1*1.17));
    if (exp1 > 600) exp1 = 600;
    int p2 = findOdd(exp1);
    //road 3
    int arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int p3 = arr[(e2/10 + e2%10)%10];
    //summarize
    if (p1 == 100 && p2 == 100 && p3 == 100) 
    {
        exp1 = ceil(float(exp1*0.75));
        return hp1 + exp1 + m1;
    }
    double p = (p1 + p2 + p3)/3.0;
    if (p < 50.0)
    {
        hp1 = ceil(float(hp1*0.85)); 
        exp1 = ceil(float(exp1*1.15));
    }
    else
    {
        hp1 = ceil(float(hp1*0.9)); 
        exp1 = ceil(float(exp1*1.2));
    }
    if (exp1 > 600) exp1 = 600;
    return hp1 + exp1 + m1;
}

// Task 3
int chaseTaxi(int & hp1, int & exp1, int & hp2, int & exp2, int e3) 
{
    //input validation
    if (e3 < 0 || e3 > 99) return -99;
    if (exp1 < 0) exp1 = 0;
    if (exp1 > 600) exp1 = 600;
    if (hp1 < 0) hp1 = 0;
    if (hp1 > 666) hp1 = 666;
    if (exp2 < 0) exp2 = 0;
    if (exp2 > 600) exp2 = 600;
    if (hp2 < 0) hp2 = 0;
    if (hp2 > 666) hp2 = 666;
    int x = 0, y = 0; //find catch-up position.
    //create taxi map
    int taxi[10][10];
    for (int i = 0; i < 10; i ++)
    {
        for (int j = 0; j < 10; j++)
        {
            taxi[i][j] = (e3*j + i*2)*(i-j);
            if (taxi[i][j] > e3*2) x++;
            if (taxi[i][j] < -e3) y++;
        }
    }
    //updating x, y
    x = x/10 + x%10;
    x = x/10 + x%10;
    y = y/10 + y%10;
    y = y/10 + y%10;
    //loop to calculate holmes score
    int holmes = taxi[x][y], i = x, j = y;
    while (--i >= 0 && --j >= 0)
    {
        holmes = max(taxi[i][j], holmes); //upper left
    }
    i = x; j = y;
    while (--i >= 0 && ++j <= 9)
    {
        holmes = max(taxi[i][j], holmes); //upper right
    }
    i = x; j = y;
    while (++i <= 9 && --j >= 0)
    {
        holmes = max(taxi[i][j], holmes); //lower left
    }
    i = x; j = y;
    while (++i <= 9 && ++j <= 9)
    {
        holmes = max(taxi[i][j], holmes); //lower right
    }
    holmes = abs(holmes);
    if (abs(taxi[x][y]) > holmes)
    {
        exp1 = ceil(float(exp1*0.88));
        hp1 = ceil(float(hp1*0.9));
        exp2 = ceil(float(exp2*0.88));
        hp2 = ceil(float(hp2*0.9));
        return taxi[x][y];
    }
    else
    {
        exp1 = ceil(float(exp1*1.12));
        hp1 = ceil(float(hp1*1.1));
        if (exp1 > 600) exp1 = 600;
        if (hp1 > 666) hp1 = 666;
        exp2 = ceil(float(exp2*1.12));
        hp2 = ceil(float(hp2*1.1));
        if (exp2 > 600) exp2 = 600;
        if (hp2 > 666) hp2 = 666;
        return holmes;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) 
{
    string sNew = "";
    sNew += s;
    string emailNew = "";
    emailNew += email;
    string se = "";
    for (int i = 0; i < emailNew.size(); i++)
    {
        if (emailNew[i] == '@') break;
        se += emailNew[i];
    }
    if (sNew.size() < 8) return -1;
    if (sNew.size() > 20) return -2;
    int found = sNew.find(se);
    if (found != string::npos) return -(300 + found);
    int dupPos, invalidPos = -1;
    bool special = true; //true means not containing special characters
    for (int i = 0; i < sNew.size(); i++)
    {
        if (i < sNew.size() - 2 && sNew[i] == sNew[i+1] && sNew[i+1] == sNew[i+2]) return -(400+i);
        bool valid = false;
        if (sNew[i] >= '0' && sNew[i] <= '9') valid = true;
        if (sNew[i] >= 'a' && sNew[i] <= 'z') valid = true;
        if (sNew[i] >= 'A' && sNew[i] <= 'Z') valid = true;
        switch (sNew[i])
        {
            case '@': case '#': case '%': case '$': case '!':
                valid = true;
                special = false;
        }
        if (!valid && invalidPos == -1) invalidPos = i;
    }
    if (special) return -5;
    if (invalidPos != -1) return invalidPos;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) 
{
    string arr[num_pwds];
    for (int i = 0; i < num_pwds; i++)
    {
        arr[i] = "";
        arr[i] += arr_pwds[i];
    }
    int freq[30][2]; //first store pos, second store freq
    int pwdFound = 0, maxFreq = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        bool newPass = true;
        for (int j = 0; j < pwdFound; j++)
        {
            if (arr[i] == arr[freq[j][0]])
            {
                maxFreq = max(++freq[j][1], maxFreq);
                newPass = false;
                break;
            }
        }
        if (newPass)
        {
            freq[pwdFound][0] = i;
            freq[pwdFound][1] = 1;
            maxFreq = max(1, maxFreq);
            pwdFound++;
        }
    }
    //returning result
    int ans = -1, size = -1;
    for (int j = 0; j < pwdFound; j++)
    {
        if (freq[j][1] == maxFreq)
        {
            int length = arr[freq[j][0]].size();
            if (length > size) 
            {
                ans = freq[j][0];
                size = length;
            }
        }
    }
    return ans;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
