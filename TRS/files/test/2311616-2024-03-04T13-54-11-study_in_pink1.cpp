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

int value(int n, int min, int max)
{
    if(n >= max) n = max;

    if(n <= min) n = min;

    return n;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int min = 0, max = 600; 

    if(e1 < 0 || e1 > 99) return -99;

    // ======== kiem tra gia tri =========
    exp1 = value(exp1, min, max);
    exp2 = value(exp2, min, max);


    // ======== cac bien =========
    int info; 
    bool case1;
    if(e1 <= 3)
    {
        case1 = 1;
        info = e1 + 1;
    }

    else
    {
        if(4 <= e1 && e1 <= 19) info = 1;
        else if(20 <= e1 && e1 <= 49) info = 2;
        else if(50 <= e1 && e1 <= 65) info = 3;
        else if(66 <= e1 && e1 <= 79) info = 4;
        else info = 5;

        case1 = 0;
    }

    float info2_1 = (float)e1 / 4 + 19;
    float info2_2 = (float)e1 / 9 + 21;
    float info2_3 = (float)e1 / 16 + 17;
    float exp1_1 = exp1;
    float exp2_1 = exp2;

    if(case1)
    {
        switch(info)
        {
            case 1: 
                exp2 += 29; 
                break;

            case 2: 
                exp2 += 45;
                break;

            case 3: 
                exp2 += 75;
                break;

            case 4: 
                exp2 += 149;
                break;
        }

        exp2 = value(exp2, min, max);

        int d = e1 * 3 + exp1 * 7;

        if(d % 2 == 0)
            exp1_1 = ceil(exp1_1 + 1.0 * d / 200);

        else 
            exp1_1 = ceil(exp1_1 - 1.0 * d / 100);

        exp1 = exp1_1; 

        exp1 = value(exp1, min, max);

        exp1_1 = exp1;
    }

    else
    {
        switch(info)
        {
            case 1: 
                exp2_1 += info2_1;
                break;

            case 2:
                exp2_1 += info2_2;
                break;

            case 3:
                exp2_1 += info2_3;
                break;

            case 4:
                exp2_1 = ceil(exp2_1 + info2_1);
                exp2 = exp2_1;
                exp2 = value(exp2, min, max);
                exp2_1 = exp2;

                if(exp2_1 > 200) exp2_1 += info2_2;

                break;

            case 5:
                exp2_1 = ceil(exp2_1 + info2_1);
                exp2_1 = ceil(exp2_1 + info2_2);
                exp2 = exp2_1;
                exp2 = value(exp2, min, max);
                exp2_1 = exp2;

                if(exp2 > 400)
                {
                    exp2_1 += info2_3;
                    exp2_1 = ceil(exp2_1);
                    exp2 = exp2_1;
                    exp2 = value(exp2, min, max);

                    exp2_1 = exp2; 

                    exp2_1 += (0.15 * exp2_1);
                    exp2_1 = ceil(exp2_1);
                    exp2 = exp2_1;
                    exp2 = value(exp2, min, max);

                    exp2_1 = exp2;
                    
                }

                break;
        }

        exp2 = ceil(exp2_1);
        exp2 = value(exp2, min, max);

        exp1 -= e1;
        exp1 = value(exp1, min, max);
    }
    exp1 = value(exp1, min, max);
    exp2 = value(exp2, min, max);
    
    return exp1 + exp2;
}


// Task 2
int CP(int n)
{
    int a[25] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 
                289, 324, 361, 400, 441, 484, 529, 576};
    int n1, n2;

    if(n == 0) return 0; 

    else if(n >= 576) return 576;

    else
    {
        for(int i = 0; i < 25; i++)
        {
            if(a[i] <= n && n <= a[i + 1])
            {
                n1 = a[i];
                n2 = a[i + 1];
            }
        }

        int r1 = abs(n - n1);
        int r2 = abs(n - n2);

        if(r1 < r2) return n1; 
            
        return n2; 
    }
}

int road3(int n)
{
    if(0 <= n && n <= 9)
        return n;

    else
    {
        int n1 = n / 10;
        int n2 = n % 10;

        int sum = n1 + n2;

        return sum % 10;
    }
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int minHP = 0, maxHP = 666;
    int minEXP = 0, maxEXP = 600;
    int minM = 0, maxM = 3000;

    if(E2 < 0 || E2 > 99) return -99;

    // ======== kiem tra gia tri ========== 
    HP1 = value(HP1, minHP, maxHP);
    EXP1 = value(EXP1, minEXP, maxEXP);
    M1 = value(M1, minM, maxM);


    // ========= cac bien =================
    float p1, p2, p3; 
    float HP_tmp = HP1, EXP_tmp = EXP1;

    // ========== con duong 1 ==============
    int S1 = CP(EXP1); 
    if(EXP1 >= S1) p1 = 1; 
    else p1 = 1.0 * (1.0 * EXP1 / S1 + 80) / 123;

    // ========== con duong 2 ===============
    float midM = 0.5 * M1;
    int pay = 0;

    if(M1 == 0);

    else if(E2 % 2 == 1)
    {
        while(pay <= midM)
        {
            // ------ su kien 1 ---------
            if(HP_tmp < 200)
            {
                HP_tmp += 0.3 * HP_tmp;
                M1 -= 150;
                pay += 150;
            }

            else
            {
                HP_tmp += 0.1 * HP_tmp;
                M1 -= 70;
                pay += 70;
            }

            HP_tmp = ceil(HP_tmp);
            HP1 = HP_tmp;
            HP1 = value(HP1, minHP, maxHP);
            HP_tmp = HP1;
            M1 = value(M1, minM, maxM); 

            if(pay > midM) break;


            // ------ su kien 2 -----------
            if(EXP_tmp < 400)
            {
                M1 -= 200;
                pay += 200;
            }

            else 
            {
                M1 -= 120;
                pay += 120;
            }

            EXP_tmp = ceil(EXP_tmp + 0.13 * EXP_tmp);
            EXP1 = EXP_tmp; 
            EXP1 = value(EXP1, minEXP, maxEXP);
            EXP_tmp = EXP1;
            M1 = value(M1, minM, maxM);

            if(pay > midM) break;

            // -------- su kien 3 ------------
            if(EXP_tmp < 300)
            {
                M1 -= 100;
                pay += 100;
            }

            else
            {
                M1 -= 120;
                pay += 120;
            }

            EXP_tmp = ceil(EXP_tmp - 0.1 * EXP_tmp);
            EXP1 = EXP_tmp;
            EXP1 = value(EXP1, minEXP, maxEXP);
            EXP_tmp = EXP1;
            M1 = value(M1, minM, maxM);

            if(pay > midM) break;
            
        }
    }

    else
    {
        // -------- su kien 1 -----------
        if(HP_tmp < 200)
        {
            HP_tmp += 0.3 * HP_tmp;
            M1 -= 150;
        }

        else
        {
            HP_tmp += 0.1 * HP_tmp;
            M1 -= 70;
        }

        HP_tmp = ceil(HP_tmp);
        HP1 = HP_tmp;
        HP1 = value(HP1, minHP, maxHP);
        HP_tmp = HP1;
        M1 = value(M1, minM, maxM);

        if(M1 != 0)
        {
            // --------- su kien 2 ----------
            if(EXP_tmp < 400)
                M1 -= 200;
        
            else 
                M1 -= 120;

            EXP_tmp = ceil(EXP_tmp + 0.13 * EXP_tmp);
            EXP1 = EXP_tmp; 
            EXP1 = value(EXP1, minEXP, maxEXP);
            EXP_tmp = EXP1;
            M1 = value(M1, minM, maxM);

            if(M1 != 0) 
            {
                // ------------ su kien 3 -----------
                if(EXP_tmp < 300)
                    M1 -= 100;

                else        
                    M1 -= 120;
    
                EXP_tmp = ceil(EXP_tmp - 0.1 * EXP_tmp);
                EXP1 = EXP_tmp;
                EXP1 = value(EXP1, minEXP, maxEXP);
                EXP_tmp = EXP1;
                M1 = value(M1, minM, maxM);
            }
        }
    }

    HP_tmp = ceil(HP_tmp - 0.17 * HP_tmp);
    HP1 = HP_tmp;
    HP1 = value(HP1, minHP, maxHP);
    HP_tmp = HP1;

    EXP_tmp = ceil(EXP_tmp + 0.17 * EXP_tmp);
    EXP1 = EXP_tmp;
    EXP1 = value(EXP1, minEXP, maxEXP);
    EXP_tmp = EXP1;

    int S2 = CP(EXP1); 
    if(EXP1 >= S2) p2 = 1; 
    else p2 = 1.0 * (1.0 * EXP1 / S2 + 80) / 123;   

    // ========= con duong 3 =============
    float p[10] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    int i = road3(E2);
    p3 = p[i];

    // ========== tinh xac xuat ===========
    if(p1 == 1 && p2 == 1 && p3 == 1) 
    {
        EXP_tmp = ceil(EXP_tmp - 0.25 * EXP_tmp);
        EXP1 = EXP_tmp;
        EXP1 = value(EXP1, minEXP, maxEXP);
        EXP_tmp = EXP1;
    }

    else
    {
        float p_avg = (p1 + p2 + p3) / 3;

        if(p_avg < 0.5)
        {
            HP_tmp = ceil(HP_tmp - 0.15 * HP_tmp);
            HP1 = HP_tmp;
            HP1 = value(HP1, minHP, maxHP);
            HP_tmp = HP1;

            EXP_tmp = ceil(EXP_tmp + 0.15 * EXP_tmp);
            EXP1 = EXP_tmp;
            EXP1 = value(EXP1, minEXP, maxEXP);
            EXP_tmp = EXP1;
        }

        else
        {
            HP_tmp = ceil(HP_tmp - 0.1 * HP_tmp);
            HP1 = HP_tmp;
            HP1 = value(HP1, minHP, maxHP);
            HP_tmp = HP1;

            EXP_tmp = ceil(EXP_tmp + 0.2 * EXP_tmp);
            EXP1 = EXP_tmp;
            EXP1 = value(EXP1, minEXP, maxEXP);
            EXP_tmp = EXP1;
        }
    }

    HP1 = value(HP1, minHP, maxHP);
    EXP1 = value(EXP1, minEXP, maxEXP);
    M1 = value(M1, minM, maxM);

    return HP1 + EXP1 + M1;
}

// Task 3
int trans(int n)
{
    if(0 <= n && n <= 9)
        return n;

    else
    {
        int n1 = n / 10;
        int n2 = n % 10;

        int sum = n1 + n2;

        if(0 <= sum && sum <= 9) 
            return sum;

        int sum1 = sum / 10;
        int sum2 = sum % 10;

        return sum1 + sum2;
    }
}

int maxVal(int a[], int size)
{
    int max = a[0];

    for(int i = 1; i < size; i++)
    {
        if(a[i] > max) 
            max = a[i];
    }

    return max;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 < 0 || E3 > 99) return -99;

    int minHP = 0, maxHP = 666;
    int minEXP = 0, maxEXP = 600;
    
    // ========= kiem tra gia tri ==========
    HP1 = value(HP1, minHP, maxHP);
    HP2 = value(HP2, minHP, maxHP);
    EXP1 = value(EXP1, minEXP, maxEXP);
    EXP2 = value(EXP2, minEXP, maxEXP);

    // ========= cac bien =============
    float HP1_tmp, HP2_tmp, EXP1_tmp, EXP2_tmp;
    HP1_tmp = HP1;
    HP2_tmp = HP2;
    EXP1_tmp = EXP1;
    EXP2_tmp = EXP2;
    int taxiPoint, sPoint; 

    // =========== khoi tao mang diem cho taxi ========
    int a[10][10];

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // =========== tinh diem cho taxi va Sherlock =========

    // ----------- diem cua taxi --------------
    int i_meet = 0, j_meet = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(a[i][j] > 2 * E3)
                i_meet++;

            else if(a[i][j] < -E3)
                j_meet++;
        }
    }

    i_meet = trans(i_meet);
    j_meet = trans(j_meet);
    taxiPoint = a[i_meet][j_meet];

    // ----------- diem cua Sherlock ------------
    int point[30];
    int k = 0;
    int i_tmp = i_meet, j_tmp = j_meet;

    while(i_tmp >= 0 && j_tmp >= 0)
    {
        point[k] = a[i_tmp][j_tmp];
        i_tmp--;
        j_tmp--;
        k++;
    }

    i_tmp = i_meet + 1; 
    j_tmp = j_meet + 1;
    
    while(i_tmp <= 9 && j_tmp <= 9)
    {
        point[k] = a[i_tmp][j_tmp];
        i_tmp++;
        j_tmp++;
        k++;
    }

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if((i + j == i_meet + j_meet) && (i != i_meet) && (j != j_meet))
            {
                point[k] = a[i][j];
                k++;
            }
        }
    }

    sPoint = maxVal(point, k);
    sPoint = abs(sPoint);

    // ----------- so sanh diem ---------- 
    if(abs(taxiPoint) > sPoint)
    {
        EXP1_tmp = ceil(EXP1_tmp - 0.12 * EXP1_tmp);
        EXP1 = EXP1_tmp;
        EXP1 = value(EXP1, minEXP, maxEXP);

        EXP2_tmp = ceil(EXP2_tmp - 0.12 * EXP2_tmp);
        EXP2 = EXP2_tmp;
        EXP2 = value(EXP2, minEXP, maxEXP);

        HP1_tmp = ceil(HP1_tmp - 0.1 * HP1_tmp);
        HP1 = HP1_tmp;
        HP1 = value(HP1, minHP, maxHP);

        HP2_tmp = ceil(HP2_tmp - 0.1 * HP2_tmp);
        HP2 = HP2_tmp;
        HP2 = value(HP2, minHP, maxHP);

        return taxiPoint;
    }

    else
    {
        EXP1_tmp = ceil(EXP1_tmp + 0.12 * EXP1_tmp);
        EXP1 = EXP1_tmp;
        EXP1 = value(EXP1, minEXP, maxEXP);

        EXP2_tmp = ceil(EXP2_tmp + 0.12 * EXP2_tmp);
        EXP2 = EXP2_tmp;
        EXP2 = value(EXP2, minEXP, maxEXP);

        HP1_tmp = ceil(HP1_tmp + 0.1 * HP1_tmp);
        HP1 = HP1_tmp;
        HP1 = value(HP1, minHP, maxHP);

        HP2_tmp = ceil(HP2_tmp + 0.1 * HP2_tmp);
        HP2 = HP2_tmp;
        HP2 = value(HP2, minHP, maxHP);

        return sPoint;
    }

    HP1 = value(HP1, minHP, maxHP);
    HP2 = value(HP2, minHP, maxHP);
    EXP1 = value(EXP1, minEXP, maxEXP);
    EXP2 = value(EXP2, minEXP, maxEXP);

    return -1;
}

// Task 4
int subString(string a, string son)
{
    int x = son.length();                                
    for (int i = 0; i < a.length(); i++) 
    {          
        if (son == a.substr(i, x)) 
        {          
            return i;                                  
        }
    }
    
    return -1;
}

int index(string s)
{
    int n = s.length();

    char key = s[0]; 
    int count = 1, res = -1;

    for(int i = 1; i < n; i++)
    {
        if(s[i] != key)
        {
            key = s[i];
            count = 1;
        }

        else count++;

        if(count == 3) 
        {
            res = i - 2;
            break;
        }
    }

    return res;
}

bool check1(string s)
{
    int n = s.length();

    bool flag = 0;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            flag = 1;
            break;
        }
    }

    return flag;
}

bool validChar(char c)
{
    if(('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '@' || c == '#' || c == '%' || c == '$' || c == '!')
        return 1;
    return 0; 
}

int check2(string s)
{
    int n = s.length();
    int res = -1; 

    for(int i = 0; i < n; i++)
    {
        if(!validChar(s[i]))
        {
            res = i;
            break;
        }
    }

    return res;
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
    // ====== doi sang string ========
    string s1 = s;
    string email1 = email; 

    // ======= cac bien ==============
    int n = s1.length();
    int m = email1.length();
    string se;

    // ======== tao ra string se ======
    for(int i = 0; i < m; i++)
    {
        if(email1[i] != '@')
            se.push_back(email1[i]);

        else break;
    }

    int k = se.length();

    // ========= kiem tra s1 =========
    int r1 = subString(s1, se);
    int r2 = index(s1);
    int r3 = check2(s1);

    if(n < 8) return -1;

    if(n > 20) return -2;

    if(r1 != -1) return -(300 + r1);

    if(r2 != -1) return -(400 + r2);

    if(!check1(s1)) return -5;

    if(r3 != -1) return r3;

    return -10;
}

// Task 5
int frequency(string a[], int size, string s)
{
    if(size == 0) return 0;

    int res = 0;

    for(int i = 0; i < size; i++)
    {
        if(s == a[i])
            res++;
    }

    return res;
}

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string* arr = new string[num_pwds];
    for(int i = 0; i < num_pwds; i++)
        arr[i] = arr_pwds[i];

    int f[30]; // luu tan so cua cac chuoi
    string s[30]; // luu cac chuoi phan biet

    // ========= tim tan so cua tung phan tu phan biet ========
    int f1 = 0, s1 = 0;

    for(int i = 0; i < num_pwds; i++)
    {
        if(frequency(s, s1, arr[i]) == 0)
        {
            s[s1] = arr[i];
            s1++;
            f[f1] = frequency(arr, num_pwds, arr[i]);
            f1++;
        }
    }

    // ========== tim phan tu co tan so lon nhat =============
    int M = maxVal(f, f1);
    string res1[30]; // luu cac chuoi co tan so lon nhat
    int res2[30]; // luu do dai cua cac chuoi ay 
    string res3[30]; // luu cac chuoi hop le
    int r1 = 0, r2 = 0, r3 = 0;

    for(int i = 0; i < f1; i++)
    {
        if(f[i] == M)
        {
            res1[r1] = s[i];
            r1++;
        }
    }

    for(int i = 0; i < r1; i++)
    {
        res2[r2] = res1[i].length();
        r2++;
    }

    int M1 = maxVal(res2, r2);

    for(int i = 0; i < r1; i++)
    {
        if(res1[i].length() == M1)
        {
            res3[r3] = res1[i];
            r3++;
        }
    }

    int final = 0;

    for(int i = 0; i < num_pwds; i++)
    {
        if(frequency(res3, r3, arr[i]) != 0)
        {
            final = i;
            break;
        }
    }

    delete [] arr;

    return final;
}

////////////////////////////////////////////////
/// max OF STUDENT'S ANSWER
////////////////////////////////////////////////