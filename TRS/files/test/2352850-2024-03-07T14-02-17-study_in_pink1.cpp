#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

//! Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    if (e1 < 0 || e1 > 99) return -99;
    else if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0)
        {
            exp2 += 29;
        }
        else if (e1 == 1)
        {
            exp2 += 45;
        }
        else if (e1 == 2)
        {
            exp2 += 75;
        }
        else if (e1 == 3)
        {
            exp2 += 29 + 45 + 75;
        }
        int  D = e1 * 3 + exp1 * 7;
        if ((D % 2) == 0.0)
        {
            exp1 =ceil(exp1+ D / 200.0);
        }
        else
        {
            exp1 = ceil(exp1 - D / 100.0);
        }
    }
        else if (e1 >= 4 && e1 <= 99)
        {
            if (e1 >= 4 && e1 <= 19)
            {
                exp2 += ceil(e1 / 4.0) + 19;
            }
            else if (e1 >= 20 && e1 <= 49)
            {
                exp2 += ceil (e1 / 9.0) + 21;
            }
            else if (e1 >= 50 && e1 <= 65)
            {
                exp2 += ceil(e1 / 16.0) + 17;
            }
            else if (e1 >= 66 && e1 <= 79)
            {
                exp2 += ceil(e1 / 4.0) + 19;
                if (exp2 > 200)
                {
                    exp2 += ceil(e1 / 9.0) + 21;
                }
            }
            else if (e1 >= 80 && e1 <= 99)
            {
                exp2 += ceil(e1 / 4.0) + 19;
                exp2 += ceil(e1 / 9.0) + 21;
                if (exp2 > 400)
                {
                    exp2 += ceil(e1 / 16.0) + 17;
                    exp2 = ceil(exp2 * 1.15);                    
                }
            }
            exp1 -= e1;
        }
    if (exp1 > 600)
    {
        exp1 = 600;
    }
    else if (exp1<0) { exp1 =0;}
    if (exp2 > 600)
    {
        exp2 = 600;
    }
     else if (exp2<0) { exp2 =0;}

    return exp1 + exp2;

    return 1;
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
 double P1, P2; 
 int P3;
 if (E2 > 99 || E2 < 0)
     return -99;
     int S;
     //find S;
     double k = floor(sqrt(EXP1));
     int a = EXP1 - k * k;
     int b = (k + 1) * (k + 1) - EXP1;
     if (a > b)
     {
         S = (k + 1) * (k + 1);
     }
     else { S = k * k; }
     if (EXP1 >= S)
     {
         P1 = 1;
     }
     else
     {
         P1 = (EXP1 / S + 80.0) / 123.0;
     }
     //con duong 2
     //TH1 lẻ
     {
         int M = M1 / 2;
         int sum = 0;
         if (E2 % 2 == 1)
         {
             while (true)
             {
                if(M1 == 0) break;
                 if (HP1 < 200)
                 {
                     HP1 = ceil(HP1 + 0.3 * HP1);
                     M1 -= 150;
                     sum += 150;
                     if (EXP1 > 600)
                     {
                         EXP1 = 600;
                     }
                     if (M1 < 0 || M1 == 0) { M1 = 0; }
                     if (HP1 > 666)
                     {
                         HP1 = 666;
                     }
                     if (sum > M)
                     {
                         break;
                     }
                 }
                 else if (HP1 >= 200)
                 {
                     HP1 = ceil(HP1 + 0.1 * HP1);
                     M1 -= 70;
                     sum += 70;
                     if (EXP1 > 600)
                     {
                         EXP1 = 600;
                     }
                     if (HP1 > 666)
                     {
                         HP1 = 666;
                     }
                     if (sum > M)
                     {
                         break;
                     }
                 }
                 if (EXP1 < 400)
                 {
                     M1 -= 200;
                     EXP1 = ceil(EXP1 + 0.13 * EXP1);
                     sum += 200;
                     if (EXP1 > 600)
                     {
                         EXP1 = 600;
                     }
                     if (HP1 > 666)
                     {
                         HP1 = 666;
                     }
                     if (sum > M)
                     {
                         break;
                     }
                 }
                 else if (EXP1 >= 400)
                 {
                     M1 -= 120;
                     EXP1 = ceil(EXP1 + 0.13 * EXP1);
                     sum += 120;
                     if (EXP1 > 600)
                     {
                         EXP1 = 600;
                     }
                     if (HP1 > 666)
                     {
                         HP1 = 666;
                     }
                     if (sum > M)
                     {
                         break;
                     }
                 }
                 if (EXP1 < 300)
                 {
                     M1 -= 100;
                     sum += 100;
                     EXP1 = ceil(EXP1 - 0.1 * EXP1);
                     if (EXP1 > 600)
                     {
                         EXP1 = 600;
                     }
                     if (HP1 > 666)
                     {
                         HP1 = 666;
                     }
                     if (sum > M)
                     {
                         break;
                     }
                 }
                 else  if (EXP1 >= 300)
                 {
                     M1 -= 120;
                     sum += 120;
                     EXP1 = ceil(EXP1 - 0.1 * EXP1);
                     if (EXP1 > 600)
                     {
                         EXP1 = 600;
                     }
                     if (HP1 > 666)
                     {
                         HP1 = 666;
                     }
                     if (sum > M)
                     {
                         break;
                     }
                 }
             }
             HP1 = ceil(HP1 * 0.83);
             EXP1 = ceil(EXP1 * 1.17);
         }
         else if (E2 % 2 == 0)
         {
             for (int j=0; j<1; j++)
             {
                 if(M1 == 0) break;
                 if (HP1 < 200)
                 {
                     HP1 = ceil(HP1 + 0.3 * HP1);
                     M1 -= 150;
                     if (M1 <= 0)
                     {
                         break;
                     }
                 }
                 else if (HP1 >= 200)
                 {
                     HP1 = ceil(HP1 + 0.1 * HP1);
                     M1 -= 70;
                     if (EXP1 > 600)
                     {
                         EXP1 = 600;
                     }
                     if (HP1 > 666)
                     {
                         HP1 = 666;
                     }
                     if (M1 <= 0)
                     {
                         break;
                     }
                 }
                 if (EXP1 < 400)
                 {
                     M1 -= 200;
                     EXP1 = ceil(EXP1 + 0.13 * EXP1);
                     if (EXP1 > 600)
                     {
                         EXP1 = 600;
                     }
                     if (HP1 > 666)
                     {
                         HP1 = 666;
                     }
                     if (M1 <= 0)
                     {
                         break;
                     }
                 }
                 else if (EXP1 >= 400)
                 {
                     M1 -= 120;
                     EXP1 = ceil(EXP1 + 0.13 * EXP1);
                     if (M1 <= 0)
                     {
                         break;
                     }
                 }
                 if (EXP1 < 300)
                 {
                     M1 -= 100;
                     sum += 100;
                     EXP1 = ceil(EXP1 - 0.1 * EXP1);
                     if (EXP1 > 600)
                     {
                         EXP1 = 600;
                     }
                     if (HP1 > 666)
                     {
                         HP1 = 666;
                     }
                     if (M1 <= 0)
                     {
                         break;
                     }
                 }
                 else  if (EXP1 >= 300)
                 {
                     M1 -= 120;
                     sum += 120;
                     EXP1 = ceil(EXP1 - 0.1 * EXP1);
                     if (EXP1 > 600)
                     {
                         EXP1 = 600;
                     }
                     if (HP1 > 666)
                     {
                         HP1 = 666;
                     }
                     if (M1 <= 0)
                     {
                         break;
                     }
                 }
             }
             HP1 = ceil(HP1 * 0.83);
             EXP1 = ceil(EXP1 * 1.17);
         }
         if (EXP1 > 600)
         {
             EXP1 = 600;
         }
         if (HP1 > 666)
         {
             HP1 = 666;
         }
         int S1;
         //find S;
         double k1 = floor(sqrt(EXP1));
         int a1 = EXP1 - k1 * k1;
         int b1 = (k1 + 1) * (k1 + 1) - EXP1;
         if (a1 > b1)
         {
             S1 = (k1 + 1) * (k1 + 1);
         }
         else { S1 = k1 * k1; }
         if (EXP1 >= S1)
         {
             P2 = 1;
         }
         else
         {
             P2 = (EXP1 / S1 + 80.0) / 123.0;
         }
         int P[] = { 32,47,28,79,100,50,22,83,64,11 };
         int i;
         if (E2 < 10)
         {
             i = E2;
             P3 = P[i];
         }
         else if (E2 >= 10)
         {
             int m = (E2 / 10) + (E2 % 10);
             i = m % 10;
             P3 = P[i];
         }
         if (P1 == 1 && P2 == 1 && P3 == 100)
         {
             if (EXP1 > 600)
             {
                 EXP1 = 600;
             }
             if (HP1 > 666)
             {
                 HP1 = 666;
             }
             EXP1 = ceil(EXP1 - EXP1 * 0.25);
         }
         else
         {
             double P = (P1 * 100 + P2 * 100 + P3) / 3;
             if (P < 50)
             {
                 if (EXP1 > 600)
                 {
                     EXP1 = 600;
                 }
                 if (HP1 > 666)
                 {
                     HP1 = 666;
                 }
                 HP1 = ceil(HP1 - 0.15 * HP1);
                 EXP1 = ceil(EXP1 + 0.15 * EXP1);

             }
             else if (P >= 50)
             {
                 if (EXP1 > 600)
                 {
                     EXP1 = 600;
                 }
                 if (HP1 > 666)
                 {
                     HP1 = 666;
                 }
                 HP1 = ceil(HP1 - 0.1 * HP1);
                 EXP1 = ceil(EXP1 + 0.2 * EXP1);
                 if (EXP1 > 600)
                 {
                     EXP1 = 600;
                 }
                 if (HP1 > 666)
                 {
                     HP1 = 666;
                 }
             }
         }
     }
         if (M1 < 0 || M1 == 0)
 {
     M1 = 0;
 }
     return HP1 + EXP1 + M1;
    return 1;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3>=0&&E3<=99)
{int bigger = 0;
int smaller = 0;
int x[10][10] = { 0 };
for (int i = 0;i < 10;i++)
{
    for (int j = 0;j < 10;j++)
    {
        x[i][j] = (E3 * j + (i * 2)) * (i - j);
        if (x[i][j] > E3 * 2)
        {
            ++bigger;
        }
        if (x[i][j] < -E3)
        {
            ++smaller;
        }
    }
}
int posI, posJ;
if (bigger < 10)
{
    posI = bigger;
}
else
{
    int m = bigger / 10 + bigger % 10;
    if (m < 10)
    {
        posI = m;
    }
    else
    {
        int n = m / 10 + m % 10;
        posI = n;
    }
}
if (smaller < 10)
{
    posJ = smaller;
}
else
{
    int h = smaller / 10 + smaller % 10;
    if (h < 10)
    {
        posJ = h;
    }
    else
    {
        int k = h / 10 + h % 10;
        posJ = k;
    }
}
int diem = x[posI][posJ];
int j = posJ;
for (int i = posI;i >= 0;i--)
{
    if (x[i][j] > diem)
    {
        diem = x[i][j];
    }
    j = j - 1;
    if (i < 0 || j < 0)
    {
        break;
    }
}
int k = posJ;
for (int i = posI;i < 10;i++)
{
    if (x[i][k] > diem)
    {
        diem = x[i][k];
    }
    k = k - 1;
    if (i > 10 || k < 0)
    {
        break;
    }
}
int h = posJ;
for (int i = posI;i < 10;i++)
{
    if (x[i][h] > diem)
    {
        diem = x[i][h];
    }
    h = h + 1;
    if (i > 10 || h > 0)
    {
        break;
    }
}
int g = posJ;
for (int i = posI;i >= 0;i--)
{
    if (x[i][g] > diem)
    {
        diem = x[i][g];
    }
    g = g + 1;
    if (i < 0 || g>=10)
    {
        break;
    }
}
  if (diem < abs(x[posI][posJ]))
  {
      EXP1 = ceil(EXP1 * 0.88);
      HP1 = ceil(HP1 * 0.9);
      EXP2 = ceil(EXP2 * 0.88);
      HP2 = ceil(HP2 * 0.9);
        if (EXP1 > 600)
  {
    EXP1 = 600;
  }
   if (HP1 > 666)
    {
    HP1 = 666;
    }
    if (EXP2 > 600)
  {
    EXP2 = 600;
  }
   if (HP2 > 666)
    {
    HP2 = 666;
    }
      return x[posI][posJ];

  }
   else 
  {
      EXP1 = ceil(EXP1 * 112.0/100);
      HP1 = ceil(HP1 * 11.0/10);
      EXP2 = ceil(EXP2 * 112.0/100);
      HP2 = ceil(HP2 * 11.0/10);
        if (EXP1 > 600)
  {
    EXP1 = 600;
  }
   if (HP1 > 666)
    {
    HP1 = 666;
    }
    if (EXP2 > 600)
  {
    EXP2 = 600;
  }
   if (HP2 > 666)
    {
    HP2 = 666;
    }
      return diem;
  }
  return -1;      
}
else { return -99;}
}


int checkPassword(const char *s, const char *email)
{ static char se[101];
 int i;
 for (i = 0; email[i] != '@';i++)
 {
     se[i] = email[i];
 }
 se[i] = '\0';
 if (strlen(s) < 8)
 {
     return -1;
 }
 else if (strlen(s) > 20)
 {
     return -2;
 }
 const char* p = strstr(s, se);
 if (p != nullptr)
 {
     return -(300 + (p - s)); // Trả về vị trí của p trong chuỗi s
 }
 for (int j = 0; s[j] != '\0';j++)
 {
     if (s[j] == s[j + 1] && s[j] == s[j + 2])
     {
         return -(400 + j);
     }
 }
    bool specialchar = false;
 for (int k = 0; s[k] != '\0'; k++)
 {
     if (s[k] == '@' || s[k] == '#' || s[k] == '%' || s[k] == '$' || s[k] == '!')
     {
         specialchar = true;
         break;
     }
 }
 if (!specialchar)
 {
     return -5;
 }
 for (int n = 0;s[n] != '\0';n++)
 {
     if (!(s[n] == '!' || s[n] == '@' || s[n] == '#' || s[n] == '$' || s[n] == '%' || (s[n] >= 'A' && s[n] <= 'Z') || (s[n] >= 'a' && s[n] <= 'z') || (s[n] >= '0' && s[n] <= '9')))
     {
         {
             return n;
         }
     }
 }
 return -10;
 
}

int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
      int tansuat;
  int dai;
  int max = 0;
  int matkhau;
  for (int i = 0; i < num_pwds;i++)
  {
      tansuat = 0;
      for (int j = 0; j < num_pwds; j++)
      {
          if (strstr(arr_pwds[i], arr_pwds[j])!=nullptr && strlen(arr_pwds[i]) == strlen(arr_pwds[j]))
          {
              ++tansuat;
          }
      }
      if (tansuat > max)
      {
          max = tansuat;
          matkhau = i;
      }
      else if (tansuat == max)
      {
          if (strlen(arr_pwds[i]) > strlen(arr_pwds[matkhau]))
          {
              matkhau = i;
          }
      }
  }
  return matkhau;
 
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////