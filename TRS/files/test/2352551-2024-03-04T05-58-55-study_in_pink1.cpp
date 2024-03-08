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
void exp(int & exp)
{
    if (exp >= 600)
        exp = 600;
    else if (exp < 0)
        exp = 0; 
}
void money(int & m)
{
    if (m >= 3000)
        m = 3000;
    else if (m < 0)
         m = 0;
}
void hp(int & hp)
{
    if (hp >= 666)
     hp = 666;
    else if (hp < 0)
    hp = 0;
}
double nearestsquare(int exp)
{
    double z=sqrt(exp);
    int lower = pow(floor(z),2);
    int upper = pow(ceil(z),2);
    int a = exp - lower;
    int b = upper - exp;
    int c = min(a, b);
    if(c==b&&c!=0)
    return ((exp * 1.0 / upper) + 80) / 123;
    else if(c==a||c==0)
        return 1.0;
        else return 0.0;
}
void walk(int & hp, int & exp)
{
    double a=hp*0.17;
    double b=exp*0.17;
    hp = ceil((double)hp -(a));
    exp += ceil(b);
}
int sod(int e2) {
    int first = e2 / 10;    
    int second = e2 % 10;    
    int sum = first + second;  
    return sum;
}
void food_drink(int&HP1,int & M1) {
        double a=HP1*0.3;
        double b=0.1*HP1;
        if (HP1 < 200)
        {
            HP1 += ceil(a);
            M1 -= 150;
        }
        else
        {
            HP1 += ceil(b);
            M1 -= 70;
        }
        money(M1);
        hp(HP1);
        return;
}
void moving(int& EXP1, int& M1) {
    double a=0.13 * EXP1;
    
    if (EXP1 < 400)
    {
        EXP1 += ceil(a);
        M1 -= 200;
    }
    else
    {
        EXP1 += ceil(a);
        M1 -= 120;
    }
    return;
}
void homeless(int& EXP1, int& M1){
    double a=0.1 * EXP1;
    
    if (EXP1 < 300)
    {
        EXP1=ceil((double)EXP1- a);
        M1 -= 100;
    }
    else
    {
       EXP1=ceil((double)EXP1- a);
        M1 -= 120;
    }
    return;
}
int maxvalue(int taxi[10][10], int row, int col) {
    int max_value = taxi[row][col]; 
    for (int i = 0; row + i < 10 && col + i < 10; ++i) {
        max_value = max(max_value, taxi[row + i][col + i]);
    }
    for (int i = 0; row - i >= 0 && col + i < 10; ++i) {
        max_value = max(max_value, taxi[row - i][col + i]);
    }
    for (int i = 0; row + i <10 && col - i >= 10; ++i) {
        max_value = max(max_value, taxi[row + i][col - i]);
    }
    for (int i = 0; row - i >= 0 && col - i >= 0; ++i) {
        max_value = max(max_value, taxi[row - i][col - i]);
    }

    return max_value;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
   exp(exp1);
   exp(exp2);
    if (e1<0|| e1>99)
    {
        return -99;
    }
    if (e1 <= 3 && e1 >= 0) {
        switch (e1) 
        {
        case 0:
            exp2 += 29;
            break;
        case 1:
            exp2 += 45;
            break;
        case 2:
            exp2 += 75;
            break;
        case 3:
            exp2 += (29+45+75);
            break;
        }    
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            exp1 += ceil((double)D / 200);
        else exp1 =  ceil(exp1 - ((double)D / 100));
        }
    else if (e1 <= 99 && e1 >= 4) {
        if (e1 <= 19 && e1 >= 4)
        {
            exp2 +=ceil((double)(e1 / 4.0) + 19);
    
        }
        else if (e1 <= 49 && e1 >= 20)
        {
            exp2 += ceil((double)(e1 / 9.0) + 21);
    
        }
        else if (e1 <= 65 && e1 >= 50)
        {
            exp2 +=ceil((double)(e1 / 16.0) + 17);
    
        }
        else if (e1 <= 79 && e1 >= 66)
        {
            exp2 +=ceil((double)(e1 / 4.0) + 19);
            exp(exp2);
            if (exp2 > 200)
                exp2 += ceil((double)(e1 / 9.0) + 21);
                exp(exp2);
        }
        else if (e1 <= 99 && e1>= 80)
        {
            exp2 += ceil((double)(e1 / 4.0) + 19);
            exp(exp2);
            exp2 += ceil((double)(e1 / 9.0) + 21);
            exp(exp2);
            if (exp2 > 400)
            {
                exp2 += ceil((double)(e1 / 16.0) + 17);
                exp(exp2);
                exp2 += ceil(0.15*(double)exp2);
                exp(exp2);
            }

        }
        exp2 = ceil(exp2);
        exp1 -= e1;
    }
    exp(exp1);
    exp(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    //check part
  money(M1);
   hp(HP1);
   exp(EXP1);
    if (E2 < 0 || E2>99)
    {
        return -99;
    }
    //find p1
    double p1 = nearestsquare(EXP1);
    //find p2
    if (M1 == 0)
    {
        walk(HP1, EXP1);
        goto hehe;  
    }
    if (E2 % 2 == 0)
    {
        food_drink(HP1, M1); //food drink
       money(M1);
        hp(HP1);
        if (M1 == 0)
        {
            walk(HP1, EXP1);
            goto hehe; //here
        }
        moving(EXP1, M1);
        money(M1);
        exp(EXP1);
        if (M1 == 0)
        {
            walk(HP1, EXP1);
            goto hehe;   //here
        }
        homeless(EXP1, M1); //homeless
        money(M1);
        exp(EXP1);
        walk(HP1, EXP1);
        goto hehe;   //here
    }
    else if (E2 % 2 != 0)
    {
        double half = M1 / 2;
        again:
       food_drink(HP1, M1);
       money(M1);
       hp(HP1);
     
        if (M1 < half)
        {  walk(HP1, EXP1);
            goto hehe;}
        moving(EXP1, M1);
        money(M1);
        exp(EXP1);
      
        if (M1 < half)
        {  walk(HP1, EXP1);
            goto hehe;}
              
        homeless(EXP1, M1);
        money(M1);
        exp(EXP1);
         
        if (M1 < half)
          {    walk(HP1, EXP1);
              goto hehe;}
            goto again;
    }
    hehe:
    double p2 = nearestsquare(EXP1); 
    double p[]= {3.2,4.7,2.8,7.9,1.00,5.0,2.2,8.3,6.4,1.1};
    double p3;
    if (E2 >= 0 && E2 < 10)
        p3 = p[E2];
    else 
    {
       int sum= sod(E2);
       int one = sum % 10;
       p3 = p[one];
    }
    if (p1 == 1.0 && p2 == 1.0 && p3 == 1.0)
    {
        EXP1 =ceil((double)EXP1 - ((double)EXP1 * 0.25));
    }
    else
    {
        double pp = (p1 + p2 + p3) / 3;
        if (pp < 0.5)
        {
            HP1 =ceil((double)HP1 - ((double)HP1 * 0.15));
            EXP1 +=ceil((double)EXP1 * 0.15);
        }
        else
        {
            HP1 =ceil((double)HP1- ((double)HP1 * 0.1));
            EXP1 += ceil((double)EXP1 * 0.2);
        }
    }
    exp(EXP1);
    hp(HP1);
    money(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
    int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3){
    int i,j;
    int taxi[10][10];
    for(i=0;i<10;++i)
    {
        for(j=0;j<10;++j)
        {
            taxi[i][j]= ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int m,n;
    int men[10][10];
    for(m=0;m<10;++m)
    {
        for(n=0;n<10;++n)
        {
         men[n][m]=maxvalue(taxi,n,m);
         if(men[n][m]<0)
         {
            men[n][m]=abs(men[n][m]);
         }
        }
    }
    int x=0;
    int y=0;
    for(i=0;i<10;++i)
    {
        for(j=0;j<10;++j)
        {
            if(taxi[i][j]>(E3*2))
            {
                x+=1;
            }
            if(taxi[i][j]<-E3)
            {
                y+=1;
            }
        }
    }
    while(x>=10)
    {
       x= sod(x);
    }
    while(y>=10)
    {
       y= sod(y);
    }
    if(abs(taxi[x][y])>men[x][y])
    {
        EXP1=ceil((double)EXP1-(double)EXP1*0.12);
       EXP2=ceil((double)EXP2-(double)EXP2*0.12);
       HP1=ceil((double)HP1-(double)HP1*0.1);
       HP2=ceil((double)HP2-(double)HP2*0.1);
       return taxi[x][y];
    }else{
        EXP1+=ceil((double)EXP1*0.12);
       EXP2+=ceil((double)EXP2*0.12);
       HP1+=ceil((double)HP1*0.1);
       HP2+=ceil((double)HP2*0.1);
       return men[x][y];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
  char pass[100];
 char mail[101];
 strcpy(mail,email);
 strcpy(pass,s);
   int length = strlen(pass); 
   char *se = strtok(mail, "@");
   if(length<8)
   return -1;
   else if (length>20)
   return -2;
   else if (strstr(pass, se) != NULL)
   return -(300 + (int)(strstr(pass, se) - pass));
    for (int i = 0; i < length - 2; i++) {
        if (pass[i] == pass[i + 1] && pass[i] == pass[i + 2]) 
        return -(400 + i);
    }
    bool Special = false;
    const char *specialChars = "@#%$!";
    for (int i = 0; i < length; i++) {
        if (strchr(specialChars, pass[i]) != NULL) {
            Special = true;
            break;
        }
    }
    if (!Special) return -5;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
  int a=0;
  int most=0;
  const char* arraypass[num_pwds];
  for(int k=0;k<num_pwds;k++)
  {
     arraypass[k] = arr_pwds[k];
  }
  for(int i=0;i<num_pwds;i++)
      {
        int n=0;
        for(int j=i+1;j<num_pwds;j++)
      {
        bool x=strcmp(arraypass[i], arraypass[j]);
        if(!x)
        n+=1;
      }
      if(n>a)
      {
        a=n;
        most=i;
      } 
      if (n==a)
      {
        int len1=strlen(arraypass[i]);
        int len2=strlen(arraypass[most]);
        if(len1>len2)
        {
        a=n;
        most=i;
        }
      }
      }
    return most ;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////