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


void limitExp(int &EXP) {
    if (EXP > 600)
        EXP = 600;
    else if (EXP < 0)
        EXP = 0;
}
void limitHP(int &HP) {
    if (HP > 666)
        HP = 666;
    else if (HP < 0)
        HP = 0;
}


void limitM(int &M) {
    if (M > 3000)
        M = 3000;
    else if (M < 0)
        M = 0;
}

bool isAlnum(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}
int min(int a, int b) {
    return a < b ? a : b;
}
// Task 1
int firstMeet(int &EXP1, int &EXP2, int E1) {
    limitExp(EXP1);
    limitExp(EXP2);

    if ((E1 < 0) || (E1 > 99))
        return -99;

    if (E1 <= 3 && E1 >= 0) {
        if (E1 == 0)
           { EXP2 += 29;limitExp(EXP2);}
        else if (E1 == 1)
           { EXP2 += 45;limitExp(EXP2);}
        else if (E1 == 2)
            {EXP2 += 75;limitExp(EXP2);}
        else if (E1 == 3)
            {EXP2 += 149;limitExp(EXP2);}
        int D=0;
        D = E1 * 3 + EXP1 * 7;

        if (D % 2 == 0)
            {EXP1 = EXP1 + D / 200.0+0.999;limitExp(EXP1);}
        else
            {EXP1 = EXP1 - D / 100.0+0.999;limitExp(EXP1);}

    }

    if (E1 >= 4) {
        if (E1 <= 19)
           { EXP2 += E1 / 4.0 + 19+0.999;limitExp(EXP2);}
        else if (E1 >= 20 && E1 <= 49) {
            EXP2 += E1 / 9.0 + 21+0.999;
            limitExp(EXP2);
        } else if (E1 >= 50 && E1 <= 65) {
            EXP2 += E1 / 16.0 + 17+0.999;
            limitExp(EXP2);
        } else if (E1 >= 66 && E1 <= 79) {
           { EXP2 += E1 / 4.0 + 19+0.999; limitExp(EXP2);}
            if (EXP2 > 200)
                EXP2 +=E1 / 9.0 + 21+0.999;
            limitExp(EXP2);
        } else if (E1 >= 80) {
            EXP2 += E1 / 4.0 + 19+0.999; limitExp(EXP2);
            EXP2 += E1 / 9.0 + 21+0.999; limitExp(EXP2);
            if (EXP2 > 400) {
                EXP2 += E1 / 16.0 + 17+0.999; limitExp(EXP2);
                EXP2 = EXP2 * 1.15+0.999;
                limitExp(EXP2);
            }
        }
        EXP1 -= E1;limitExp(EXP1);

    }

    return EXP1 + EXP2;
}
// Task2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E3) {
    limitExp(EXP1);
    limitHP(HP1);

    if ((E3 < 0) || (E3 > 99))
       return -99;
       
    int S=0, q=0,v=0;
   double  p=0,p1=0,p2=0,p3=0,h=0;
    q = round(sqrt(EXP1));
    S = q * q;
    h =0.5*M1;
    if (EXP1>=S)
        p1 = 1.0;
    else
        p1 = (EXP1 / (S * 1.0) + 80) / 123;
        if  (E3%2==1){
        if (M1>0)
         {while (v <= h) {
        if (HP1 < 200) {
            if (v  <= h) {
                HP1 = 1.3 * HP1 + 0.999;limitHP(HP1);
                M1 -= 150;limitM(M1);
                v += 150;}
           else break;
            
        } else {
            if (v  <= h) {
                HP1 = 1.1 * HP1 + 0.999;limitHP(HP1);
                M1 -= 70;limitM(M1);
                v += 70;
            } else 
                break; 
            
        }
        
        if (EXP1 < 400) 
            if (v  <= h) {
                M1 -= 200;limitM(M1);
                v += 200;
                EXP1 = EXP1 * 1.13 + 0.999;limitExp(EXP1);
            } else 
                break; 
            else {
            if ( v<=h) {
                M1 -= 120;limitM(M1);
                v += 120;
                EXP1 = EXP1 * 1.13 + 0.999;limitExp(EXP1);
            } else 
                break; 
        }
         
        
        if (EXP1 < 300) {
            if (v  <= h) {
                M1 -= 100;limitM(M1);
                v += 100;
                EXP1 = EXP1 * 0.9 + 0.999;
            } else 
                break; 
        } else {
            if (v  <= h) {
                M1 -= 120;limitM(M1);
                v += 120;
                EXP1 = EXP1 * 0.9 + 0.999;
            } else 
                break; 
            }
    }
  }}
if (E3 % 2 == 0) {
    if (HP1 < 200) {
        if (M1 > 0) {
            HP1 = 1.3 * HP1 + 0.999;
            limitHP(HP1);
            M1 -= 150;
            limitM(M1);
            
        }
    } else {
        if (M1 > 0) {
            HP1 = 1.1 * HP1 + 0.999;
            limitHP(HP1);
            M1 -= 70;
            limitM(M1);
            
        }
    }

    if (EXP1 < 400) {
        if (M1 > 0) {
            M1 -= 200;
            limitM(M1);
           
            EXP1 = EXP1 * 1.13 + 0.999;
            limitExp(EXP1);
        }} else {
            if (M1 > 0) {
                M1 -= 120;
                limitM(M1);
               
                EXP1 = EXP1 * 1.13 + 0.999;
                limitExp(EXP1);
            }
        }
    
   if (EXP1 < 300) {
        if (M1 > 0) {
            M1 -= 100;
            limitM(M1);
            
            EXP1 = EXP1 * 0.9 + 0.999;
        }
    } else {
        if (M1 > 0) {
           M1-=120; limitM(M1);
         
            EXP1 = EXP1 * 0.9 + 0.999;
        }
    }
}

  HP1 =0.83*HP1+0.999;
  EXP1=1.17*EXP1+0.999;  limitExp(EXP1); 
    q = round(sqrt(EXP1));
    S = q * q;
    if ( EXP1 >=S)
        p2 = 1.0;
       else
        p2 = (EXP1 / (S * 1.0) + 80) / 123;
  double xx[10];
 xx[0]=0.32; xx[1]=0.47;xx[2]=0.28;xx[3]=0.79;xx[4]=1.0;
 xx[5]=0.5;xx[6]=0.22;
 xx[7]=0.83; xx[8]=0.64;xx[9]=0.11;
  int i,c,dv;
  if ( E3<10) i=E3;
  else {
  c=E3/10;
  dv=E3-10*c;
  if ( (c+dv) <10) i=c+dv;
  else i= (c+dv) -((c+dv)/10)*10; }
  p3=xx[i];
 
 if (p1==1.0 && p2==1.0 && p3==1.0)  EXP1=0.75*EXP1+0.999;
 else { p=(p1+p2+p3)/3;
 if (p < 0.5)
 { HP1=0.85*HP1+0.999;
  EXP1=1.15*EXP1+0.999; limitExp(EXP1); }
 else { HP1=0.9*HP1+0.999;
        EXP1=1.2*EXP1+0.999; limitExp(EXP1);}
        }
   return HP1 + EXP1 +M1;

    }

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{     limitExp(EXP1);
      limitExp(EXP2);
      limitHP(HP2);
      if ((E3 < 0) || (E3 > 99))
        return -99;
      
       int ma_tran [10][10];
     for (int i=0;i<10;i++)
{     for (int j=0;j<10;j++)
      {  ma_tran[i][j]=(E3*j +(i*2))*(i-j);
          }
    }
  
     int dem=0,dem1=0;
      for (int i=0;i<10;i++)
{     for (int j=0;j<10;j++)
      {  if (ma_tran[i][j]>(E3*2))
          dem++;
          }
    }

     for (int i=0;i<10;i++)
{     for (int j=0;j<10;j++)
      {  if (ma_tran[i][j]<(-E3))
         dem1++;
          }
    }
  int i=0,j=0;
   int d=0,c=0;
   int d1=0,c1=0,k=0;
    
    if ( dem<10) i=dem;
   
    c=dem/10;
    d=dem-c*10;
    
    if ( (d+c) <10) i=d+c;
    else 
    { k=d+c;
     c1=k/10;
     d1=k-c1*10;
      i=c1+d1;
        }
    
    if (dem1<10) j=dem1;
    c=dem1/10;
    d=dem1-c*10;
    
     if ( (d+c) <10) j=d+c;
    else 
    { k=d+c;
     c1=k/10;
     d1=k-c1*10;
      j=c1+d1;
        } 
    int a=i,b=j;
 // huong xanh la
 int max=ma_tran[i][j];
  while ( a>0 && b>0)
{   a--;
    b--;
    if (max < ma_tran[a][b] )
    max=ma_tran[a][b];
    }
//huong xanh duong
int a1,b1;
  a1=i;b1=j;
  while ( a1 <9 && b1>0)
{   a1++;
    b1--;
    if (max < ma_tran[a1][b1] )
    max=ma_tran[a1][b1];
    }
// huong mau hong
 int a2,b2;
  a2=i;b2=j;
  while ( a2 <9 && b2<9)
{   a2++;
    b2--;
    if (max < ma_tran[a2][b2] )
    max=ma_tran[a2][b2];
    }
// huong mau vang
int a3,b3;
  a3=i;b3=j;
  while ( a3 >0 && b3<9)
{   a3--;
    b3++;
    if (max < ma_tran[a3][b3] )
    max=ma_tran[a3][b3];
    }
  
  
  if ( fabs(max*1.0)  >= fabs (  ma_tran[i][j]*1.0 ) )
  
 {   EXP1=1.12*EXP1 +0.999; limitExp(EXP1);
     HP1= 1.1*HP1 +0.999; limitHP(HP1);
     EXP2=1.12*EXP2 +0.999; limitExp(EXP2);
     HP2= 1.1*HP2 +0.999; limitHP(HP2);
     
    return max;
     }
    else 
    {
     EXP1=0.88*EXP1 +0.999; 
     HP1= 0.9*HP1 +0.999; 
     EXP2=0.88*EXP2 +0.999; 
     HP2= 0.9*HP2 +0.999; 
         
      return ma_tran[i][j];
    }
}

// Task 4
int checkPassword(const char *s, const char *email) {
    string str_s = s;
    string str_email = email;
    string se;
    int se_pos;
    int k=0;
    
    size_t at_pos = str_email.find('@');
    se = str_email.substr(0, at_pos);

    int s_len = strlen(s);
    if (s_len < 8) {
        return -1; 
    }
    if (s_len > 20) {
        return -2; 
    }
   
    se_pos = str_s.find(se);
    if (se_pos != string::npos) {
        return -(300 + se_pos); 
    }
   
   for (int i = 0; i < s_len - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
           return -(400 + i); 
        }
    }
    
    bool kitudacbiet = false;
    for (int i = 0; i < s_len; ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            kitudacbiet = true;
            break;
        }
    }
    if (!kitudacbiet) {
       return -5; 
    }
   bool chu =false;
   int d=0;
    for (int i = 0; i < s_len; i++) {
        if ( (isalnum(s[i])==false) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!' ) {
           chu = true; d=i;
            break;
        }
    }
    if (chu) { 
       return d ; 
    }
       return -10;
      }




//task5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    string str_arr[255];
    for (int i = 0; i < num_pwds; ++i) {
        str_arr[i] = arr_pwds[i];
    }

    int n = num_pwds;
    int x = 1;
    string khac_nhau[30];
    int vt[30];
    vt[0] = 0;
    khac_nhau[0] = str_arr[0];

    for (int i = 1; i < n; i++) {
        int k = 0;
        for (int j = 0; j < x; j++) {
            if (str_arr[i] == khac_nhau[j])
                k++;
        }
        if (k == 0) {
            khac_nhau[x] = str_arr[i];
            vt[x] = i;
            x++;
        }
    }

    int ts[30] = {0};

    for (int j = 0; j < x; j++) {
        for (int i = 0; i < n; i++) {
            if (khac_nhau[j] == str_arr[i])
                ts[j]++;
        }
    }

    int max_tanso = ts[0];
    int max_dodai = khac_nhau[0].length();
    int max_tanso_index = 0;

    for (int i = 1; i < x; i++) {
        if (ts[i] > max_tanso || (ts[i] == max_tanso && khac_nhau[i].length() > max_dodai)) {
            max_tanso = ts[i];
            max_dodai = khac_nhau[i].length();
            max_tanso_index = i;
        }
    }

    int min_vt = vt[max_tanso_index];

    for (int i = 1; i < x; i++) {
        if (ts[i] == max_tanso && khac_nhau[i].length() == max_dodai) {
            min_vt = std::min(min_vt, vt[i]);
        }
    }

    return min_vt;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////