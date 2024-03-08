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

int max(int a, int b)
{
    int max;
    if (a > b) max = a;
    else max = b;
    return max;
}

int tim_i_j(int hang)
{
    int donvi, chuc = 0;
    donvi = hang;
    while (donvi >= 10)
    {
        donvi -= 10;
        chuc++;
    }
    int i = donvi + chuc;
    if (i >= 10)
    {
        chuc = 0;
        donvi = i;
        while (donvi >= 10)
        {
            donvi -= 10;
            chuc++;
        }
        i = donvi + chuc;
    }

    return i;
}
int calc_hp1(int &HP1, double a, int toantu)
{
    if (toantu == 1) HP1 += ceil(a);
    else if (toantu == 2) HP1 -= (int)a;
    else if (toantu == 3) HP1 *= ceil(a);
    else HP1 /= ceil(a);
    if (HP1 > 666) return 666;
    else if (HP1 < 0) return 0;
    else return HP1;
}

int calc_hp2(int &HP2, double a, int toantu)
{
    if (toantu == 1) HP2 += ceil(a);
    else if (toantu == 2) HP2 -= (int)a;
    else if (toantu == 3) HP2 *= ceil(a);
    else HP2 /= ceil(a);
    if (HP2 > 666) return 666;
    else if (HP2 < 0) return 0;
    else return HP2;
}

int calc_m1(int &M1, double a, int toantu)
{
    if (toantu == 1) M1 += ceil(a);
    else if (toantu == 2) M1 -= (int)a;
    else if (toantu == 3) M1 *= ceil(a);
    else M1 /= ceil(a);
    if (M1 > 3000) return 3000;
    else if (M1 < 0) return 0;
    else return M1;
}

int calc_m2(int &M2, double a, int toantu)
{
    if (toantu == 1) M2 += ceil(a);
    else if (toantu == 2) M2 -= (int)a;
    else if (toantu == 3) M2 *= ceil(a);
    else M2 /= ceil(a);
    if (M2 > 3000) return 3000;
    else if (M2 < 0) return 0;
    else return M2;
}

int calc_exp1(int &EXP1, double a, int toantu)
{
    if (toantu == 1) EXP1 += ceil(a);
    else if (toantu == 2) EXP1 -= (int)a;
    else if (toantu == 3) EXP1 *= ceil(a);
    else EXP1 /= ceil(a);
    if (EXP1 > 600) return 600;
    else if (EXP1 < 0) return 0;
    else return EXP1;
}

int calc_exp2(int &EXP2, double a, int toantu)
{
    if (toantu == 1) EXP2 += ceil(a);
    else if (toantu == 2) EXP2 -= (int) a;
    else if (toantu == 3) EXP2 *= ceil(a);
    else EXP2 /= ceil(a);
    if (EXP2 > 600) return 600;
    else if (EXP2 < 0) return 0;
    else return EXP2;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;
    else 
    {
        if (e1 >= 0 && e1 <= 3)
        {
           if (e1 == 0) exp2 = calc_exp2(exp2, 29, 1);
           else if (e1 == 1) exp2 = calc_exp2(exp2, 45, 1);
           else if (e1 == 2) exp2 = calc_exp2(exp2, 75, 1);
           else if (e1 == 3) exp2 = calc_exp2(exp2, 149, 1);
           int D = e1*3 + exp1*7;
           if (D % 2 == 0) exp1 = calc_exp1(exp1, (double)D/200, 1);
           else exp1 = calc_exp1(exp1, (double)D/100, 2);
        }
        else if (e1 > 3 && e1 <= 99)
        {
           exp1 = calc_exp1(exp1, (double)e1, 2);
           if (e1 > 3 && e1 <= 19) exp2 = calc_exp2(exp2, (double)e1/4 + 19, 1);
           else if (e1 > 19 && e1 <= 49) exp2 = calc_exp2(exp2, (double)e1/9 + 21, 1);
           else if (e1 > 49 && e1 <= 65) exp2 = calc_exp2(exp2, (double)e1/16 + 17, 1);
           else if (e1 > 65 && e1 <= 79) 
           {
              exp2 = calc_exp2(exp2, (double)e1/4 + 19, 1);
              if (exp2 > 200) exp2 = calc_exp2(exp2, (double)e1/9 + 21, 1);
           }
           else if (e1 > 79 && e1 <= 99) 
           {
              exp2 = calc_exp2(exp2, (double)e1/4 + 19, 1);
              exp2 = calc_exp2(exp2, (double)e1/9 + 21, 1);
              if (exp2 > 400)
              {
                 exp2 = calc_exp2(exp2, (double)e1/16 + 17, 1);
                 exp2 = calc_exp2(exp2, (double)exp2*0.15, 1);
              }
           }  
        }
        return exp1 + exp2;
    }
    
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
if (E2 < 0 || E2 > 99) return -99;
else
{
    int location;
    //con duong 1
   double P1,P2,P3,Ptb;
   double S;
   int t = sqrt(EXP1);
   int t_21 = t*t, t_22 = (t+1)*(t+1);
   int hieu_1 = abs(EXP1 - t_21);
   int hieu_2 = abs(EXP1 - t_22);
   if (hieu_1 > hieu_2) 
   {
    S = t_22;
    P1 = (double) ((double)EXP1/S + 80)/123;
   }
   else P1 = 1;
   
//con duong 2
   int tong_chi = 0;
   int m1 = ceil((double) 0.5*M1); //1094
   if (E2 % 2 != 0)
   {
    while (true)
    {
    //sukien 1
      if (HP1 < 200)
      {
       
        HP1 = calc_hp1(HP1, (double) HP1*0.3, 1);
        M1 = calc_m1(M1, 150, 2);
        tong_chi += 150;
         if (tong_chi > m1) 
        {
            HP1 = calc_hp1(HP1, (double) HP1*0.17, 2);
            EXP1 = calc_exp1(EXP1, (double)EXP1*0.17, 1);
            break;
        }
      }
      else 
      {
        HP1 = calc_hp1(HP1, (double)HP1*0.1, 1); //446
        M1 = calc_m1(M1, 70, 2); //2118
        tong_chi += 70; //70
        if (tong_chi > m1) //khong thuc hien
        {
            HP1 = calc_hp1(HP1, (double) HP1*0.17, 2);
            EXP1 = calc_exp1(EXP1, (double)EXP1*0.17, 1);
            break;
        }
      }
      //sukien 2
       if (EXP1 < 400) 
       {
        M1 = calc_m1(M1, 200, 2); //1918
        EXP1 = calc_exp1(EXP1, (double)EXP1*0.13, 1); //212
        tong_chi += 200; //270
         if (tong_chi > m1) 
        {
            HP1 = calc_hp1(HP1, (double) HP1*0.17, 2); 
            EXP1 = calc_exp1(EXP1, (double)EXP1*0.17, 1);
            break;
        }
       }
       else 
       {
        M1 = calc_m1(M1, 120, 2);
        tong_chi += 120;
        EXP1 = calc_exp1(EXP1, (double)EXP1*0.13, 1);
        if (tong_chi > m1) 
        {
            HP1 = calc_hp1(HP1, (double) HP1*0.17, 2);
            EXP1 = calc_exp1(EXP1, (double)EXP1*0.17, 1);
            break;
        }
       }
       
       //sukien 3
       if (EXP1 < 300) 
       {
        M1 = calc_m1(M1, 100, 2);//1818
        EXP1 = calc_exp1(EXP1, (double) EXP1*0.1, 2);
        tong_chi += 100;//370
        if (tong_chi > m1) 
        {
            HP1 = calc_hp1(HP1, (double) HP1*0.17, 2);
            EXP1 = calc_exp1(EXP1, (double)EXP1*0.17, 1);
            break;
        }
        
       }
       else 
       {
        M1 = calc_m1(M1, 120, 2);
        tong_chi += 120;
        EXP1 = calc_exp1(EXP1, (double) EXP1*0.1, 2);
        if (tong_chi > m1) 
        {
            HP1 = calc_hp1(HP1, (double) HP1*0.17, 2);
            EXP1 = calc_exp1(EXP1, (double)EXP1*0.17, 1);
            break;
        }
       }
    }
   }
   
   else //E2 LA SO CHAN
   {
    if (M1 > 0) //sukien 1
    {
        if (HP1 < 200) 
        {
            HP1 = calc_hp1(HP1, (double) HP1*0.3, 1);
            M1 = calc_m1(M1, 150, 2);
        }
        else 
        {
            HP1 = calc_hp1(HP1, (double) HP1*0.1, 1); //330
            M1 = calc_m1(M1, 70, 2); //430
        }
    }
    if (M1 > 0) //sukien 2
    {
        if (EXP1 < 400) 
        {
            M1 = calc_m1(M1, 200, 2); //230
            EXP1 = calc_exp1(EXP1, (double) EXP1*0.13, 1);
        }
        else 
        {
            M1 = calc_m1(M1, 120, 2); 
            EXP1 = calc_exp1(EXP1, (double) EXP1*0.13, 1);//451
        }

    }
    if (M1 > 0) //sukien 3
    {
        if (EXP1 < 300) 
        {
            M1 = calc_m1(M1, 100, 2);
            EXP1 = calc_exp1(EXP1, (double) EXP1*0.1, 2);
        }
        else 
        {
            M1 = calc_m1(M1, 120, 2); //110
            EXP1 = calc_exp1(EXP1, (double) EXP1*0.1, 2); //406
        }
    }
    EXP1 = calc_exp1(EXP1, (double) EXP1*0.17, 1);
    HP1 = calc_hp1(HP1, (double) HP1*0.17, 2);
   }
    t = sqrt(EXP1);//tinh P2
    t_21 = t*t, t_22 = (t+1)*(t+1);
    hieu_1 = abs(EXP1 - t_21);
    hieu_2 = abs(EXP1 - t_22);
   if (hieu_1 > hieu_2) 
   {
    S = t_22;
    P2 = ((float)EXP1/S + 80)/123;
   }
   else P2 = 1;
   //CON DUONG 3
   int chuc = 0, i = 0;
   float P[10] = {0.32, 0.47, 0.28, 0.79, 1, 0.50, 0.22, 0.83, 0.64, 0.11};
   if (E2 < 10)
   {
    P3 = P[E2];
   }
   else 
   {
    while (E2 >= 10)
    {
        E2 -= 10;
        chuc++;
    }
    location = E2 + chuc;
    if (location < 10) P3 = P[location];
    else 
    {
        while(location >= 10) location -= 10;
        P3 = P[location];
    }
   }
   if (P1 == 1 && P2 == 1 && P3 == 1) EXP1 = calc_exp1(EXP1, (double) EXP1*0.25, 2);
   else 
   {
    Ptb = (P1 + P2 + P3)/3;
    if (Ptb < 0.5)
    {
        HP1 = calc_hp1(HP1, (double) HP1*0.15, 2);
        EXP1 = calc_exp1(EXP1, (double) EXP1*0.15, 1);
    }
    else 
    {
        HP1 = calc_hp1(HP1, (double) HP1*0.1, 2); //297
        EXP1 = calc_exp1(EXP1, (double) EXP1*0.20, 1); //488
    }
   }
    return HP1 + EXP1 + M1;
}
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
if (E3 < 0 || E3 > 99) return -99;
else 
{
    int m[100][100], hang = 0, cot = 0, i, j, taxi_score, s[100], score, count = 0;
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            m[i][j] = (E3*j +(i*2))*(i-j);
        }
    }
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (m[i][j] > E3*2) hang++;
            if (m[i][j] < -E3) cot++;
        }
    }
    i = tim_i_j(hang);
    j = tim_i_j(cot);
    taxi_score = m[i][j];
    int a = i; int b = j;
    s[0] = taxi_score;
    count++;
    while (a < 9 && b < 9)
    {
        s[count] = m[a+1][b+1];
        count++; a++; b++;
    }
    a = i; b = j;
    while (a > 0 && b > 0)
    {
        s[count] = m[a-1][b-1];
        count++; a--; b--;
    }
    a = i; b = j;
    while (a < 9 && b > 0)
    {
        s[count] = m[a+1][b-1];
        count++; a++; b--;
    }
    a = i; b = j;
    while (a > 0 && b < 9)
    {
        s[count] = m[a-1][b+1];
        count++; a--; b++;
    }
    score = s[0];
    for (int i = 1; i <= count - 1; i++)
    {   
        if (score < s[i]) score = s[i];
    }
    int taxi_score1 = abs(taxi_score), score1 = abs(score);
    if (taxi_score1 > score1) 
    {
        HP1 = calc_hp1(HP1, (double) HP1*0.1, 2);
        HP2 = calc_hp2(HP2, (double) HP2*0.1, 2);
        EXP1 = calc_exp1(EXP1, (double) EXP1*0.12, 2);
        EXP2 = calc_exp2(EXP2, (double) EXP2*0.12, 2);
        return taxi_score;
    }
    else 
    {
        HP1 = calc_hp1(HP1, (double) HP1*0.1, 1);
        HP2 = calc_hp2(HP2, (double) HP2*0.1, 1);
        EXP1 = calc_exp1(EXP1, (double) EXP1*0.12, 1);
        EXP2 = calc_exp2(EXP2, (double) EXP2*0.12, 1);
        return score;
    }
}
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
char se[100];
    int length = 0, length_s = 0, same = 0, sei = 0, sci, count = 0, location_6;
    bool dieukien1 = false, dieukien2 = false, dieukien3 = false, dieukien4 = false, dieukien5, dieukien6 = false;
    for (length = 0; email[length] != '@'; length++)   se[length] = email[length];
    //for (int i = 0; i <= length - 1; i++) cout << se[i];
    for (int i = 0; s[i] != '\0'; i++) length_s++;
    if (length_s < 8) dieukien1 = true; // ngan hon 8
    else if (length_s > 20) dieukien2 = true; //dai hon 20
    for (int i = 0; s[i] != '\0'; i++) //s co chua se
    {
        if(s[i] == se[0]) 
        {
            sei = i;
            for (int j = 0; j <= length - 1; j++)
            {
                if (s[i + j] == se[j]) same++;
                else 
                {
                    same = 0;
                    break;
                }           
            }
            if (same == length) 
            {
                dieukien3 = true;
                break;
            }
        }
    }
     for (int i = 0; i <= length_s - 2; i++) //3 ki tu lap lai
    {
        if (s[i] == s[i+1] && s[i+1] == s[i+2]) 
        {
            dieukien4 = true;
            sci = i;
            break;
        }
    }

    for (int i = 0; i <= length_s - 1; i++) //khong chua ki tu dac biet
    {
        if(s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!')
        {
            count++;
        }
    }
    if (count == length_s) dieukien5 = true;
    else dieukien5 = false;
   
   for (int i = 0; i <= length_s - 1; i++) //dieukien cuoi
   {
    int num = s[i];
    //cout << num << " ";
    if (num != 33 && (num < 34 || num > 38) && (num < 47 || num > 57) && (num < 63 || num > 91) && (num < 96 || num > 123))
    {
        dieukien6 = true;
        location_6 = i;
        break;
    }
   }

   if (dieukien1) return -1;
   else if (dieukien2) return -2;
   else if (dieukien3) return -(300+sei);
   else if (dieukien4) return -(400+sci);
   else if (dieukien5) return -5;
   else if (dieukien6) return location_6;
   else  return -10;
    
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
int same = 0, k = 0, num_repeat[100], length[100], location_max, max_repeat;
    bool t;
    for (int i = 0; i <= num_pwds - 1; i++)
    {
        length[i] = 0;
        for (int j = 0; arr_pwds[i][j] != '\0'; j++)
        {
            length[i]++;
        }
    }
    for (int i = 0; i < num_pwds; i++)
    {
        int r = i + 1;
        num_repeat[i]=1;
        for (r; r <= num_pwds - 1; r++)
        {
            for (int j = 0; j <= max(length[i], length[r]) - 1; j++)
            {
                k++;
                if (arr_pwds[i][j] == arr_pwds[r][j]) same++;
                else same = 0;
            }
            if (same == k) 
            {
                num_repeat[i]++;
                same = 0;
            }
            else same = 0;
            k = 0;
        }
    }
    max_repeat = num_repeat[0];
    int max_length = length[0];
    for (int i = 1; i <= num_pwds - 1; i++) if (max_length < length[i]) max_length = length[i];
    for (int i = 1; i <= num_pwds - 1; i++)  if (max_repeat < num_repeat[i]) max_repeat = num_repeat[i];
    for(int i = 0; i <= num_pwds - 1; i++)
    {
        if (num_repeat[i] == max_repeat)
        {
            location_max = i;
            for (int j = i+1; j <= num_pwds - 1; j++)
            {
                t = false;
                if (num_repeat[j] == max_repeat && length[j] == max_length && length[j] > length [i]) 
                {
                    location_max = j;
                    break;
                }
                else 
                {
                    t = true;
                }
            }
        }
        if(t) break;
    }
    return location_max;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////