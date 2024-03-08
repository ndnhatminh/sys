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
int rangeEXP(int & exp)
{
    if (exp > 600)
    {
        exp = 600;
    }
    else if (exp < 0)
    {
        exp = 0;
    }
    return exp;
}
int rangeHP(int & hp)
{
    if (hp > 666)
    {
        hp = 666;
    }
    else if (hp < 0)
    {
        hp = 0;
    }
    return hp;
}
int rangeM(int& m)
{
    if (m > 3000)
    {
        m = 3000;
    }
    else if (m<0)
    {
        m = 0;
    }
    return m;
}
int oneDigit(int&num)
{
    
    while (num >= 10)
    {
        num = num / 10 + num % 10;
    }
    return num;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 < 0 || e1>99)
    {
        return -99;
    }
    // TODO: Complete this function
    double k;
    if (e1 >= 0 && e1 <= 3)
    {
        switch (e1)
        {
        case 0:exp2 += 29;         
            break;
        case 1:exp2 += 45;
            break;

        case 2:exp2 += 75;
            break;
        case 3:exp2 += 149;
            break;
        }
        int d = e1 * 3 + exp1 * 7;
        if (d % 2 == 0)
        {
            k = static_cast<double>(exp1) + static_cast<double>(d) / 200;
            
            exp1 = ceil(k);
        }
        else
        {
            k = static_cast<double>(exp1) - static_cast<double>(d) / 100;

            exp1 = ceil(k);
            
        }
    }
    else if (e1 >= 4 && e1 <= 19)
    {

        
        k += (static_cast<double>(e1) / 4 + 19);

        exp2 += ceil(k);
        exp1 -= e1;
    }
    else if (e1 >= 20 && e1 <= 49)

    {
       
        k += (static_cast<double>(e1) / 9 + 21);

        exp2 += ceil(k);
        exp1 -= e1;
    }
    else if (e1 >= 50 && e1 <= 65)
    {
        
        k += (static_cast<double>(e1) / 16 + 17);

        exp2 += ceil(k);
        exp1 -= e1;
    }
    else if (e1 >= 66 && e1 <= 79)
    {
        exp2 += e1 / 4 + 19;
        k += (static_cast<double>(e1) / 4 + 19);

        exp2 += ceil(k);
        
        if (exp2 > 200) 
        {
            k += (static_cast<double>(e1) / 9 + 21);

            exp2 += ceil(k);

        }
            
        exp1 -= e1;
    }
    else if (e1 >= 80 && e1 <= 99)
    {
        exp2 += e1 / 4 + e1 / 9 + 40;
        k += (static_cast<double>(e1) / 9+ static_cast<double>(e1)/4 + 40);

        exp2 += ceil(k);
        if (exp2 > 400)
        {
            double l;
            k += (static_cast<double>(e1) / 16 + 17);

            exp2 += ceil(k);
            l=static_cast<double>(exp2)*1.15;
            exp2 = ceil(l);
           
        }
        exp1 -= e1;
    }
    rangeEXP(exp1);
    rangeEXP(exp2);
        return exp1 + exp2;
    
}
int roundup(int & num1, double rate)
{
    double khoa;
    khoa = static_cast<double>(num1) * rate;
   
    return ceil(khoa);

}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2>99)
    {
        return -99;
    }
    // TODO: Complete this function
    double P1 = 0;
    double k1 = sqrt(EXP1);
    k1=round(k1);
    int S1 = k1 * k1;
    if (S1<= EXP1)
        P1 = 1;
    else
        P1 = (static_cast<double>(EXP1) / static_cast<double>(S1) + 80) / 123;
    if (E2 % 2 != 0)
    {
        int halfmoney;
        int paid = 0;
        halfmoney = roundup(M1, 0.5);
        while (true)
        {
            if (HP1 < 200)
            {
               
                HP1 = roundup(HP1, 1.3);
                M1 -= 150;
                paid += 150;
                rangeM(M1);
                if (paid > halfmoney)
                    break;
            }
            else if (HP1>=200)
            {
               
                HP1 = roundup(HP1, 1.1);
                M1 -= 70;
                paid += 70;
                rangeM(M1);
                if (paid > halfmoney)
                    break;
            }
            if (EXP1 < 400)
            {
                M1 -= 200;
                paid += 200;
                rangeM(M1);
                if (paid > halfmoney)
                    break;
            }
            else if(EXP1>=400)
            {
                M1 -= 120;
                paid += 120;
               EXP1= roundup(EXP1, 1.13);
               rangeM(M1);
               if (paid > halfmoney)
                   break;
            }
            if (EXP1 < 300)
            {
                M1 -= 100;
                paid += 100;
               
                EXP1 = roundup(EXP1, 0.9);
                rangeM(M1);
                if (paid > halfmoney)
                    break;
            }
            else if(EXP1>=300)
            {
                M1 -= 120;
                paid += 120;
               
                EXP1 = roundup(EXP1, 0.9);
                rangeM(M1);
                if (paid > halfmoney)
                    break;
            }
            
        }
        rangeHP(HP1);
        rangeEXP(EXP1);
        HP1 = roundup(HP1, 0.83);
        EXP1 = roundup(EXP1, 1.17);
        rangeHP(HP1);
        rangeEXP(EXP1);
        
    }
    else
    {
        while (true)
        {
            if (HP1 < 200)
            {
                
                HP1 = roundup(HP1, 1.3);
                M1 -= 150;
                if (M1 <= 0)
                {
                    M1 = 0;
                    break;
                }
            }
            else

            {
               
                HP1 = roundup(HP1, 1.1);
                M1 -= 70;
                if (M1 <= 0)
                {
                    M1 = 0;
                    break;
                }
            }
            if (EXP1 < 400)
            {
                M1 -= 200;
                if (M1 <= 0)
                {
                    M1 = 0;
                    break;
                }
            }
            else
            {
                M1 -= 120;
                if (M1 <= 0)
                {
                    M1 = 0;
                    break;
                }
                EXP1 = roundup(EXP1, 1.13);
               
            }
            if (EXP1 < 300)
            {
                M1 -= 100;
              
                EXP1 = roundup(EXP1, 0.9);
                if (M1 <= 0)
                {
                    M1 = 0;
                    break;
                }
            }
            else
            {
                M1 -= 120;
                
                EXP1 = roundup(EXP1, 0.9);
                if (M1 <= 0)
                {
                    M1 = 0;
                    break;
                }
            }
        }
        rangeHP(HP1);
        rangeEXP(EXP1);
        HP1 = roundup(HP1, 0.83);
        EXP1 = roundup(EXP1, 1.17);
        rangeHP(HP1);
        rangeEXP(EXP1);


    }
   
    double P2 = 0;
    double k2 = sqrt(EXP1);
    k2=round(k2);
    int S2= k2 * k2;
    if (S2<=EXP1)
        P2 = 1;
    else
        P2 = (static_cast<double>(EXP1) / static_cast<double>(S2) + 80) / 123;
    int P[] = { 32,47,28,79,100,50,22,83,64,11 };
    double P3 = 0;
    int sum = 0;
    int minisum = 0;
    if (E2 < 10)
    {
        P3 = static_cast<double>(P[E2])/100;
    }
    else
    {
        sum = sum + E2 / 10 + E2 % 10;
        minisum = sum % 10;
        P3 = static_cast<double>(P[minisum]) / 100;

    }
    if (P1 == P2 && P1 == 1 && P2 == P3)
    {
        
        EXP1 = roundup(EXP1, 0.75); 
    }
    else
    {
        if (((P1 + P2 + P3) / 3) < 0.5)
        {
           
            HP1 = roundup(HP1, 0.85);
            EXP1 = roundup(EXP1, 1.15);
            

        }
        else
        {
           
            HP1 = roundup(HP1, 0.9);
            EXP1 = roundup(EXP1, 1.2);

        }

    }
    rangeHP(HP1);
    rangeEXP(EXP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    if (E3 < 0 || E3>99)
    {
        return -99;
    }
    // TODO: Complete this function
    int a[10][10];
    int k = 0;
    int l = 0;
    int Taxi = 0;
    int maxleft = 0;
    int maxright = -9999;
    int maxS = 0;
    int save = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (a[i][j] > 2 * E3)
            {
                k++;
            }
            else if (a[i][j] < -E3)
            {
                l++;
            }
        }

    }
    k = oneDigit(k);
    l = oneDigit(l);
    Taxi = a[k][l];
    //left dia
    for (int m = 0; m < 10; m++)
    {
        for (int n = 0; n < 10; n++)
        {
            if (m + n == k+l)
            {
                if (a[m][n] > maxleft)
                {
                    maxleft = a[m][n];
                }
            }
        }
    }
   


    //right dia
    if (k == l)
    {
        for (int p = 0; p < 10; p++)
        {
            if (maxright < a[p][p])
            {
                maxright = a[p][p];
            }
        }
    }
    else if (k < l)
    {
        int vip = abs(k - l);
        for (int o = 0; o < 10 - vip; o++)
        {
            if (maxright < a[o][o + vip])
                maxright = a[o][o + vip];

        }
    }
    else if (k > l)
    {
        int vip = abs(k - l);
        for (int o = 0; o < 10 - vip; o++)
        {
            if (maxright < a[o + vip][o])
                maxright = a[o + vip][o];

        }
    }
    if (maxright > maxleft)
    {
        maxS = maxright;
    }
    else
    {
        maxS = maxleft;
    }
    if (maxS < abs(a[k][l]))
    {
        
        EXP1 = roundup(EXP1, 0.88);
        EXP2 = roundup(EXP2, 0.88);
        
        
        HP1 = roundup(HP1, 0.9);
        
        HP2 = roundup(HP2, 0.9);
        rangeEXP(EXP1);
        rangeEXP(EXP2);
        rangeHP(HP1);
        rangeHP(HP2);
        save = a[k][l];
        
    }
    else if (maxS>=abs(a[k][l]))
    {
       
        EXP1 = roundup(EXP1, 1.12);
        EXP2 = roundup(EXP2, 1.12);


        HP1 = roundup(HP1, 1.1);

        HP2 = roundup(HP2, 1.1);
        rangeEXP(EXP1);
        rangeEXP(EXP2);
        rangeHP(HP1);
        rangeHP(HP2);
        save = maxS;
    }
    return save;
    

   
    
}

    // Driver code
    
    


// Task 4
char* substr(const char* arr, int ers)
{
    char* res = new char[31];
    for (int i = 0; i < ers; ++i)

    {
        res[i] = arr[i];
    }

    return res;
}
int checkPassword(const char* s, const char* email)
{
    // TODO: Complete this function
    size_t len = strlen(s);
    if (static_cast<int>(len) < 8)
    {
        return -1;
    }
    else if (static_cast<int>(len) > 20)
    {
        return -2;
    }
    const char* se;
    const char* find = strstr(email, "@");
    if (find != nullptr)
    {
        // Found '@', extract substring before it
        se = substr(email, find - email);

    }

    const char* sec;
    sec = strstr(s, se);
    if (sec != nullptr)
    {
        size_t sei = strlen(sec) - strlen(se) + 1;
        return -(300 + static_cast<int>(sei)); // First occurrence of 'se'
    }
    for (int i = 0; i < len - 2; i++)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + static_cast<int>(i)); // First position of consecutive identical characters
        }
    }
    bool hasSpecialChar = false;
    for (int i = 0; i < sizeof(s); i++)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar)
    {
        return -5;
    }
    return -10;
}

// Task 5
int findMAX(int num1, int num2)
{
    int max;
    if (num1 > num2)
    {
        max = num1;
    }
    else
    {
        max = num2;
    }
    return max;
}
int findCorrectPassword(const char * arr_pwds[], int num_pwds) 
{
    const int MAX_SIZE = 100;
    int frequency[MAX_SIZE] = { 0 };
    int largest[MAX_SIZE] = { 0 };
    int maxexit = 0;
    int position = -1;
    int maxlen = 0;
    

    for (int i = 0; i < num_pwds; i++)
    {
        for (int j = i + 1; j < num_pwds; j++)
        {
            if (arr_pwds[i] == arr_pwds[j])
            {

                frequency[i]++;
                arr_pwds[j] = "";
            }
        }
    }



    for (int i = 0; i < num_pwds; i++)
    {
        if (strcmp(arr_pwds[i], "")!=0)
        {
            maxexit = findMAX(maxexit, frequency[i] + 1);
        }
    }

    for (int i = 0; i < num_pwds; i++)
    {
        if (frequency[i] + 1 == maxexit)
        {
            largest[i] = -1;
        }
    }
    for (int i = 0; i < num_pwds; i++)
    {
        if (largest[i] == -1)
        {
            maxlen = findMAX(static_cast<int>(strlen(arr_pwds[i])), maxlen);
        }

    }
    for (int i = 0; i < num_pwds; i++)
    {
        if (static_cast<int>(strlen(arr_pwds[i])) == maxlen && largest[i] == -1)
        {
            position = i;
        }
    }

    return position;





    
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////