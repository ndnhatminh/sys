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
void resetexp(int &exp)
{  
    if (exp<0) exp=0;
    if (exp>600) exp=600;
}
  
void resethp(int &hp)
{  
    if (hp<0) hp=0;
    if (hp>666) hp=666;
}

void resetm(int &m)
{  
    if (m<0) m=0;
    if (m>3000) m=3000;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
        if ((e1<0 ) || (e1>99)) return -99;
    resetexp(exp1); resetexp(exp2);
    if ((e1>=0)&&(e1<=3)) 
    {    
            int d=e1*3+exp1*7;
                switch (e1)
            {
            case 0: exp2+=29; resetexp(exp2); break;
            case 1: exp2+=45; resetexp(exp2); break;
            case 2: exp2+=75; resetexp(exp2); break;
            case 3: exp2+=149; resetexp(exp2); break;
            }
            if (d%2==0) {exp1=ceil(exp1+d/200.0); resetexp(exp1);}
            else {exp1=ceil(exp1-d/100.0); resetexp(exp1);}
    }
    else 
    {
        if ((e1>=4)&&(e1<=19)) 
        {
            exp2=ceil(exp2+ e1/4.0 + 19); resetexp(exp2);
        }
        else if ((e1>=20)&&(e1<=49))  
        { 
            exp2=ceil(exp2+ e1/9.0 + 21); resetexp(exp2);
        }
        else if ((e1>=50)&&(e1<=65))  
        { 
            exp2=ceil(exp2+ e1/16.0 + 17); resetexp(exp2);
        }
        else if ((e1>=66)&&(e1<=79)) 
        { 
            exp2=ceil(exp2+ e1/4.0 + 19); resetexp(exp2);
            if (exp2>200) 
            {
                exp2=ceil(exp2+ e1/9.0 + 21); 
                resetexp(exp2);
            } 
        }
        else 
        {
            exp2=ceil(exp2+ e1/4.0 + 19); resetexp(exp2);
            exp2=ceil(exp2+ e1/9.0 + 21); resetexp(exp2);
            if (exp2>400) 
            {
                exp2=ceil(exp2+ e1/16.0 + 17); resetexp(exp2);
                exp2=ceil(exp2*1.15); resetexp(exp2);
            }
        }
        exp1-=e1; resetexp(exp1);
   }

    return exp1 + exp2;
}
double tinh (int EXP1)
{
    double p;
    int s=round(sqrt(EXP1))*round(sqrt(EXP1));
    if (EXP1>=s) p=1;
    else p=(80.0+EXP1/s)/123;
    return p;
}
int cceil(float a) { return ceilf(a);}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
if ((E2<0 ) || (E2>99)) return -99;
    resetexp(EXP1); resethp(HP1); resetm(M1);
    const double a=M1/2;
    int sum=0;
    double p1,p2,p3;
    //con duong 1
    p1=tinh(EXP1); 
    // con duong 2
    if ((E2%2)==1)
    {
         while (1)
         {
            if(M1==0) break;
                if (HP1<200) 
                {
                    HP1=cceil(1.3*HP1); resethp(HP1); 
                    M1-=150; resetm(M1);
                    sum+=150;
                    if (sum>a) break;
                }
                else 
                {
                    HP1=cceil(1.1*HP1);   resethp(HP1); 
                    M1-=70;  resetm(M1);
                    sum+=70;  
                    if (sum>a) break;
                }
                if (EXP1<400) 
                {
                    M1-=200; resetm(M1);
                    sum+=200;  
                    EXP1=cceil(EXP1*1.13); resetexp(EXP1);
                    if (sum>a) break;
                }
                else 
                {
                    M1-=120;  resetm(M1);
                    sum+=120;  
                    EXP1=cceil(EXP1*1.13); resetexp(EXP1);
                    if (sum>a) break;
                } 
                if (EXP1<300) 
                {
                    M1-=100; resetm(M1);
                    sum+=100;  
                    EXP1=cceil(0.9*EXP1);  resetexp(EXP1);
                    if (sum>a) break;
                }
                else 
                {
                    M1-=120; resetm(M1);
                    sum+=120;  
                    EXP1=cceil(0.9*EXP1);  resetexp(EXP1);
                    if (sum>a) break;
                }            
         }           
        EXP1=cceil(EXP1*1.17);
        HP1=cceil(HP1*0.83); 
        resethp(HP1); resetexp(EXP1);     
    }     
    else 
    {       
        for (int i=0; i<1;i++)
        {
            if(M1==0) break;
                if (HP1<200) 
            {
                HP1=cceil(1.3*HP1);  resethp(HP1);
                M1-=150;  
                if (M1<=0) { M1=0; break;}
            }
            else 
            {
                HP1=cceil(1.1*HP1);   resethp(HP1);
                M1-=70;  
                if (M1<=0) { M1=0; break;}
            }
             

            if (EXP1<400) 
            {
                M1-=200;  
                EXP1=cceil(EXP1*1.13); resetexp(EXP1);
                if (M1<=0) { M1=0; break;}
            }
            else 
            {
                M1-=120;  
                EXP1=cceil(EXP1*1.13); resetexp(EXP1);
                if (M1<=0) { M1=0; break;}
            } 
            if (EXP1<300) 
            {
                M1-=100; 
                EXP1=cceil(EXP1*0.9); resetexp(EXP1);
                if (M1<=0) { M1=0; break;}
            }
            else 
            {
                M1-=120; 
                EXP1=cceil(EXP1*0.9); resetexp(EXP1);
                if (M1<=0) { M1=0; break;}
            }                        
        }
        EXP1=cceil(EXP1*1.17);
        HP1=cceil(HP1*0.83); 
        resethp(HP1); resetexp(EXP1);        
    }    
    p2=tinh(EXP1);
    //con duong 3
    double p[10]={0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11};
    if (E2/10==0) p3=p[E2];
    else 
    {
        int x=E2/10+E2%10;
        p3=p[x%10]; 
    } 
    //tong ket
    if ((p1==1)&&(p2==1)&&(p3==1)) 
    {
        EXP1=cceil(EXP1*0.75);
    }
    else 
    {
        if (((p1+p2+p3)/3.0)<0.5) 
        {
            HP1=cceil(0.85*HP1);  
            EXP1=cceil(EXP1*1.15);
        }
        else 
        {
            HP1=cceil(0.9*HP1);  
            EXP1=cceil(EXP1*1.2);
        }
    }
    resetexp(EXP1); resethp(HP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) 
    // TODO: Complete this function
    {
        int m[10][10], a, b; int dmax[10][10];
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
                m[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }

        for (int k = 0; k < 9; k++)
        {

            for (int i = 0; i < 9; i++)
            {
                if (i >= k)
                {
                    for (int j = 1; j < 10 - i; j++)
                    {
                        if (m[k][i] < m[k + j][i + j])
                            dmax[k][i] = m[k + j][i + j];
                        else
                            dmax[k][i] = m[k][i];
                    }
                }
                else
                {
                    for (int j = 1; j < 10 - k; j++)
                    {
                        if (m[k][i] < m[k + j][i + j])
                            dmax[k][i] = m[k + j][i + j];
                        else
                            dmax[k][i] = m[k][i];
                    }
                }
            }
        }
        for (int k = 0; k < 10; k++)
        {
            for (int i = 1; i < 10; i++)
            {
                for (int j = 1; j < 10 - k; j++)
                {
                    if (dmax[k][i] < m[k + j][i - j])
                        dmax[k][i] = m[k + j][i - j];
                }
            }
        }
        for (int k = 1; k < 10; k++)
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 1; j <= k; j++)
                {
                    if (dmax[k][i] < m[k - j][i + j])
                        dmax[k][i] = m[k - j][i + j];
                }
            }
        }

        for (int k = 1; k < 10; k++)
        {
            for (int i = 1; i < 10; i++)
            {
                for (int j = 1; j <= k; j++)
                {
                    if (dmax[k][i] < m[k - j][i - j])
                        dmax[k][i] = m[k - j][i - j];
                }
            }
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (m[i][j] > 0 && m[i][j] > (E3 * 2))
                    a += 1;
                else if (m[i][j] < 0 && m[i][j] < (-E3))
                    b += 1;
            }
        }
        while (a >= 10)
            a = a / 10 + a % 10;
        while (b >= 10)
            b = b / 10 + b % 10;
        if (abs(dmax[a][b]) > abs(m[a][b]))
        {
            EXP1 *= 1.12;
            EXP2 *= 1.12;
            HP1 *= 1.1;
            HP2 *= 1.1;
            return dmax[a][b];
        }
        else
        {
            EXP1 *= 0.88;
            EXP2 *= 0.88;
            HP1 *= 0.9;
            HP2 *= 0.9;
            return m[a][b];
        }
    }

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    if (strlen(s) < 8)
    return -1;
    else if (strlen(s) > 20)
    return -2;
    char *se;
    se = new char[300];
    for (int i =0; i < strlen(email);i++)
    {
        if (email[i]==64)
        break;
        se[i] = email[i];
    }
    const char* a;
    a = new char[300];
    a = strstr(email,se);
    int sei = strlen(email) - strlen(a);
    if (a != NULL)
    {
        return -(300 + 6);
    }
    int sci;
    for (int i =0; i < strlen(s) ; i++)
    {
        if (s[i] == s[i+1])
        {
        sci = i+1;
        return -(400+sci);
        }
    }
    for (int i =0; i < strlen(s) ; i++)
    {
        if (s[i] != 33 && s[i] != 35 && s[i] != 36 && s[i] != 37 && s[i] != 64)
        return -5;
    }
    int count=0;
    for (int i =0; i< strlen(s); i ++)
    {
        if (s[i] >0 && s[i]< 9 || s[i] == 33 || s[i]==35 || s[i]==36 || s[i]==37 || s[i]==64 || s[i] > 64 && s[i] < 91 
        || s[i] >96 && s[i]<123)
        count +=1;
        else break;
    }
    if (count == strlen(s))
    return -10;
    else return s[count];
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int n = num_pwds;
    int maxCount = 0;
    string mostCommonStr;
    for (int i = 0; i < n; ++i) {
        int count = 1;
        for (int j = i + 1; j < n; ++j) {
            if (arr_pwds[i] == arr_pwds[j]) {
                ++count;
            }
        }
        if (count > maxCount || (count == maxCount && strlen(arr_pwds[i]) > mostCommonStr.length())) {
            maxCount = count;
            mostCommonStr = arr_pwds[i];
        }
    }

    // Tìm vị trí đầu tiên của chuỗi xuất hiện nhiều nhất
    int firstOccurrenceIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (arr_pwds[i] == mostCommonStr) {
            firstOccurrenceIndex = i;
            break;
        }
    }
    return firstOccurrenceIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////