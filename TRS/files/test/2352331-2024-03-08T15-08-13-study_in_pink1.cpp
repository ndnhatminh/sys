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
void expcheck(int & n)
{
    if(n > 600)
    {
        n = 600;
    }

    if(n < 0)
    {
        n = 0;
    }
}
void hpcheck(int & n)
{
    if(n > 666)
    {
        n = 666;
    }

    if(n < 0)
    {
        n = 0;
    }
}
void mcheck(int & n)
{
    if(n > 3000)
    {
        n = 3000;
    }

    if(n < 0)
    {
        n = 0;
    }
}

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    if(E1 < 0 || E1 > 99)
    {
        return -99;
    }
    expcheck(EXP1);
    expcheck(EXP2);
    if (E1 >=0 && E1 <= 3)
    {
        if (E1 == 0)
        {
            EXP2 += 29;
        }
        else if (E1 == 1)
        {
            EXP2 += 45;
        }
        else if (E1 == 2)
        {
            EXP2 += 75;
        }
        else if (E1 == 3)
        {
            EXP2 = EXP2 + 29 + 45 + 75;
        }
    }
    int D = E1 * 3 + EXP1 * 7;
    if(E1 >=0 && E1 <=3)
    {
        if (D % 2 == 0)
        {
            EXP1 = ceil((EXP1) + float(D)/200);
        }
        else EXP1 = ceil((EXP1) - float(D)/100);
    }
    expcheck(EXP1);
    expcheck(EXP2);
    if(E1 >= 4 && E1 <= 99)
    {
        if (E1 >= 4 && E1 <= 19)
        {
            EXP2 = ceil(EXP2 + float(E1)/4 + 19);
        }
        else if (E1 >= 20 && E1 <= 49)
        {
            EXP2 = ceil(EXP2 + float(E1)/9 + 21);
        }
        else if (E1 >= 50 && E1 <= 65)
        {
            EXP2 = ceil(EXP2 + float(E1)/16 + 17);
        }
        else if (E1 >= 66 && E1 <= 79)
        {
            EXP2 = ceil(EXP2 + float(E1)/4 + 19);
            if (EXP2 > 200)
            {
                EXP2 = ceil(EXP2 + float(E1)/9 + 21);
            }
        }
        else if (E1 >= 80 && E1 <= 99)
        {
            EXP2 = ceil(EXP2 + float(E1)/4 + 19);
            EXP2 = ceil(EXP2 + float(E1)/9 + 21);
            if (EXP2 > 400)
            {
                EXP2 = ceil(EXP2 + float(E1)/16 + 17);
                EXP2 = ceil(float(EXP2)*115/100);
            }
        }
        expcheck(EXP1);
        expcheck(EXP2);
        EXP1 -= E1;
    }
    expcheck(EXP1);
    expcheck(EXP2);
    return EXP1 + EXP2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int  S, temp, MS = 0;
    float P1, P2, P3, P;
    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }
    expcheck(EXP1);
    hpcheck(HP1);
    mcheck(M1);

    int a = round(sqrt(EXP1));
    
    if (pow(a,2) <= EXP1)
    {
        P1 = 1;
    }
    else P1 = (((EXP1/pow(a,2)) + 80)/123.0);

    if(M1 != 0)
    {
        goto r2;
    }
    else goto endr2;
    r2:
    if (HP1 < 200)
    {
        HP1 = ceil(float(HP1)*130/100);
        MS += 150; 
        hpcheck(HP1);
    }
    else 
    {
        HP1 = ceil(float(HP1)*110/100);
        MS += 70;
        hpcheck(HP1);
    }
    if(MS > M1/2 && E2 % 2 != 0 || MS >= M1)
    {
        M1 = M1 - MS;
        goto endr2;
    }
    if (EXP1 < 400)
    {
        MS +=200;
    }
    else 
    {
        MS +=120;
    }
    EXP1 = ceil(float(EXP1)*113/100);
    expcheck(EXP1);
    if(MS > M1/2 && E2 % 2 != 0 || MS >= M1)
    {
        M1 = M1 - MS;
        goto endr2;
    }
    if (EXP1 < 300)
    {
        MS += 100;
    }
    else 
    {
        MS += 120;
    }
    EXP1 = ceil(float(EXP1)*90/100);
    expcheck(EXP1);
    if(MS > M1/2 && E2 % 2 != 0 || MS >= M1)
    {
        M1 = M1 - MS;
        goto endr2;
    }
    else if (E2 % 2 != 0)
    {
        goto r2;
    }
    else 
    {
        M1 = M1 - MS;
        goto endr2;
    }
    endr2:
    HP1 = ceil(float(HP1)*83/100);
    EXP1 = ceil(float(EXP1)*117/100);
    expcheck(EXP1);
    hpcheck(HP1);
    int b = round(sqrt(EXP1));
    if (pow(b,2) <= EXP1)
    {
        P2 = 1;
    }
    else P2 = (((EXP1/pow(a,2)) + 80)/123.0);

    int Pi[10] = {32,47,28,79,100,50,22,83,64,11};
    if (E2 <= 9)
    {
        P3 = Pi[E2]/100.0;
    }
    temp = E2/10 + E2%10;
    temp = temp % 10;
    P3 = Pi[temp]/100.0;
    float Ps = (P1 + P2 + P3)/3;
    if (int(P1) == 1 && int(P2) == 1 && int(P3) == 1)
    {
        EXP1 = ceil(float(EXP1)*75/100);
        expcheck(EXP1);
    }
    else if (Ps < 0.5)
    {
        HP1 = ceil(float(HP1)*85/100);
        EXP1 = ceil(float(EXP1)*115/100);
        expcheck(EXP1);
        hpcheck(HP1);
    }
    else 
    {
        HP1 = ceil(float(HP1)*90/100);
        EXP1 = ceil(float(EXP1)*120/100);
        expcheck(EXP1);
        hpcheck(HP1);
    }

    expcheck(EXP1);
    hpcheck(HP1);
    mcheck(M1);
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 < 0 || E3 > 99)
    {
        return -99;
    }
    expcheck(EXP1);
    expcheck(EXP2);
    hpcheck(HP1);
    hpcheck(HP2);
    int minus = 0;
    int plus = 0;
    int i,j;
    int a[10][10] = {};
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            a[i][j] = ((E3*j)+(i*2))*(i-j);
        }
    }
    
    for( i = 0; i < 10; i++)
    {
        for( j = 0; j < 10; j++)
        {
            if(a[i][j] > E3*2)
            {
                plus++;
            }
            else if(a[i][j] < -E3)
            {
                minus++;
            }
        }
    }
    int x,y;
    if(plus < 10)
    {
        x = plus;
    }
    else if(plus >= 10)
    {
        x = plus%10 + plus/10;
        if(x > 9)
        {
            x = x%10 + x/10;
        }
    }
    
    if(minus < 10)
    {
        y = minus;
    }
    if(minus >= 10)
    {
        y = minus/10 + minus%10;
        if(y > 9)
        {
            y = y%10 + y/10;
        }
    }
    int taxi = a[x][y];
    int max = 0;
    int x1 = x;
    int y1 = y;
    while(x1 < 9 && x1 > 0 &&  y1 < 9 &&  y1 > 0)
    {
        x1++;
        y1++;
        if(a[x1][y1] > max)
        {
            max = a[x1][y1];
        }
    }
    x1 = x;
    y1 = y;
    while(x1 < 9 && x1 > 0 &&  y1 < 9 &&  y1 > 0)
    {
        x1--;
        y1++;
        if(a[x1][y1] > max)
        {
            max = a[x1][y1];
        }
    }
    x1 = x;
    y1 = y;
    while(x1 < 9 && x1 > 0 && y1 < 9 &&  y1 > 0)
    {
        x1++;
        y1--;
        if(a[x1][y1] > max)
        {
            max = a[x1][y1];
        }
    }
    x1 = x;
    y1 = y;
    while(x1 < 9 && x1 > 0 &&  y1 < 9 &&  y1 > 0)
    {
        x1--;
        y1--;
        if(a[x1][y1] > max)
        {
            max = a[x1][y1];
        }
    }
    if(a[x][y] > max){
        max = a[x][y];
    }
    int result = 0;
    if(abs(taxi) <= max)
    {
        result = max;
        HP1 = ceil(float(HP1)*110/100);
        EXP1 = ceil(float(EXP1)*112/100);
        HP2 = ceil(float(HP2)*110/100);
        EXP2 = ceil(float(EXP2)*112/100);
    }
    else 
    {
        result = taxi;
        HP1 = ceil(float(HP1)*90/100);
        EXP1 = ceil(float(EXP1)*88/100);
        HP2 = ceil(float(HP2)*90/100);
        EXP2 = ceil(float(EXP2)*88/100);
    }
    expcheck(EXP1);
    expcheck(EXP2);
    hpcheck(HP1);
    hpcheck(HP2);
    return result;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string a = s;
    string b = email;
    int atpos = b.find('@');
    string se = b.substr(0, atpos);
    if(a.length() < 8)
    {
        return -1;
    }
    else if(a.length() > 20)
    {
        return -2;
    }
    int sepos = a.find(se);
    if(sepos != string::npos)
    {
        return -(300 + sepos);
    }
    else for(int i = 0; i < a.length() - 2; i++)
    {
        if(a[i] == a[i+1] && a[i] == a[i+2])
        {
            return -(400 + i);
        }
    }
    if(a.find('@') == string::npos && a.find('#') == string::npos && a.find('%') == string ::npos && a.find('$') == string::npos && a.find('!') == string::npos)
    {
        return -5;
    }
    else for(int i = 0; i < a.length(); i++)
    {
        if(!isalnum(a[i])&&a[i] != '@' && a[i] != '#' && a[i] != '%' && a[i] != '$' && a[i] != '!')
        {
            return i;
        }
    }
    return -10;

}



// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_num = 0;
    int max_length = 0;
    string cpass = "";
    int cpass_place = -1;
    for(int i = 0; i < num_pwds; i++)
    {
        const string& pass = arr_pwds[i];
        int pl = pass.length();
        int pass_num = 1;
    
        for (int j = i + 1; j < num_pwds; j++)
        {
            if(arr_pwds[j] == pass)
            {
                ++pass_num;
            }
        }
        if (pass_num > max_num || pass_num == max_num && pl > max_length)
        {
            max_num = pass_num;
            max_length = pl;
            cpass = pass;
            cpass_place = i;
        }
    }
    return cpass_place;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////