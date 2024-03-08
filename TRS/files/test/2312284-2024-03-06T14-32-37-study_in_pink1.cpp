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



int CheckEXP(int a)
{
    if (a>600)
    {
        a=600;
    }
    else if(a<0)
    {
        a=0;
    }
    return a;
}

int CheckHP(int a)
{
    if (a>666)
    {
        a=666;
    }
    else if(a<0)
    {
        a=0;
    }
    return a;
}


int CheckMoney(int a)
{
    if (a>3000)
    {
        a=3000;
    }
    else if(a<0)
    {
        a=0;
    }
    return a;
}

int CheckE(int a)
{
    if ((a<0)||(a>99)){a=-99;}

    return a;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ((e1<0)&&(e1>99))return -99;
    int D;
    if ((e1>=0)&&(e1<=3))
    {
        if(e1==0)
        {
                exp2+=29;
                exp2=CheckEXP(exp2);
        }
        else if(e1==1)
        {
                exp2+=45;
                exp2=CheckEXP(exp2);
        }
        else if(e1==2)
        {
                exp2+=75;
                exp2=CheckEXP(exp2);
        }
        else if(e1==3)
        {
                exp2+=149;
                exp2=CheckEXP(exp2);
        }
        D = e1*3 + exp1*7;
        if (D%2==0)
        {
            exp1=ceil((float)exp1+D/200+1e-7);
            exp1=CheckEXP(exp1);
        }
        else
        {
            exp1=ceil((float)exp1-D/100-1e-7);
            exp1=CheckEXP(exp1);
        }
    }
    else if ((e1>=4)&&(e1<=99))
    {
        if ((e1<=19)&&(e1>=4))
        {
            exp2=ceil((float)exp2 + e1/4 + 19+1e-7);
            exp2=CheckEXP(exp2);
        }
        else if ((e1>=20)&&(e1<=49))
        {
            exp2=ceil((float)exp2 + e1/9 + 21 +1e-7);
            exp2=CheckEXP(exp2);
        }
        else if ((e1>=50)&&(e1<=65))
        {
            exp2=ceil((float)exp2 + e1/16 + 17 +1e-7);
            exp2=CheckEXP(exp2);
        }
        else if ((e1>=66)&&(e1<=79))
        {
            exp2=ceil((float)exp2 + e1/4 + 19+1e-7 );
            exp2=CheckEXP(exp2);
            if (exp2>200)
            {
                exp2=ceil((float)exp2 + e1/9 + 21+1e-7 );
                exp2=CheckEXP(exp2);
            }
        }
        else if ((e1>=80)&&(e1<=99))
        {
            exp2=ceil((float)exp2 + e1/4 + 19 +1e-7);
            exp2=CheckEXP(exp2);
            exp2=ceil((float)exp2 + e1/9 + 21+1e-7 );
            exp2=CheckEXP(exp2);
            if(exp2>400)
            {
                exp2=ceil((float)exp2 + e1/16 + 17+1e-7 );
                exp2= ceil((float)exp2*115/100+1e-7);
                exp2=CheckEXP(exp2);
            }
        }
        exp1= exp1-e1;
    }

    return exp1 + exp2;
}

// Task 2
int CloseSquarenum (int a)
{
  int x = 0, y = 0;
  int c, n;
  //duoi
  for (int i = a; i > 0; i--)
	{
	  n = sqrt (i);
	  if (sqrt (i) == n)
		{
		  x = i;

		  break;
		}

	}
  //tren
  for (int i = a; i < (a * 5); i++)
	{
	  n = sqrt (i);
	  if (sqrt (i) == n)
		{
		  y = i;

		  break;
		}
	}

  if ((y - a) < (a - x))
	{
	  c = y;
	}
  else
	{
	  c = x;
	}


  return c;
}

int one_or_two(int a,int b[])
    {
        int s,x;
        if ((a>0)&&(a<10))
        {
            s =b[a];
        }
        else if (a>=10)
        {
            x = (a/10) +  (a%10);
            if(x<10)
            {
                s=b[x];
            }
            else if(x>10)
            {
                x = x%10;
            s = b[x];
            }

        }
        return s;
    }


int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if ((E2<0)&&(E2>99))return -99;

    // --------Path1--------
    float p1;
    int s;
    s =CloseSquarenum(EXP1);
    if (EXP1 >=s)
    {
        p1=1;
    }
    else
    {
        p1=(float)((EXP1/s)+80)/123;
    }

    // --------Path2--------

    float n = (float) M1 * 0.5;
    float pay=0;

    if (E2 % 2 == 0)
  {
	while (true)
	  {
		if (HP1 < 200)
		  {
			HP1 =  CheckHP (ceil((float) HP1 * 1.3+1e-7));
			M1 = M1 - 150;
			M1 = CheckMoney (M1);
		  }
		else
		  {
			HP1 =  CheckHP (ceil((float) HP1 * 1.1+1e-7));
			M1 = M1 - 70;
			M1 = CheckMoney (M1);
		  }
		if (M1 == 0)
		  {
			break;
		  }
		if (EXP1 < 400)
		  {
			M1 -= 200;
			EXP1 =  CheckEXP (ceil((float) EXP1 * 1.13+1e-7));
			M1 = CheckMoney (M1);
		  }
		else
		  {
			M1 -= 120;
			EXP1 =  CheckEXP (ceil((float) EXP1 * 1.13+1e-7));
			M1 = CheckMoney (M1);
		  }
		if (M1 == 0)
		  {
			break;
		  }
		if (EXP1 < 300)
		  {
			EXP1 =  CheckEXP (ceil((float)EXP1 * 0.9+1e-7));
			M1 -= 100;
			M1 = CheckMoney (M1);
		  }
		else
		  {
			EXP1 =  CheckEXP (ceil((float)EXP1 * 0.9+1e-7));
			M1 -= 120;
			M1 = CheckMoney (M1);
		  }
		if (M1 == 0)
		  {
			break;
		  }
		break;
	  }
  }

else
    {
        while (true)
        {
            if (HP1 < 200)
            {
                HP1 =  CheckHP (ceil((float) HP1 * 1.3+1e-7));
                M1 = M1 - 150;
                M1 = CheckMoney (M1);
                pay+=150;
            }
            else
            {

                HP1 =  CheckHP (ceil((float) HP1 * 1.1+1e-7));
                M1 = M1 - 70;
                M1 = CheckMoney (M1);
                pay+=70;
            }
            if(pay>n)break;
            if (EXP1 < 400)
            {

                M1 -= 200;
                EXP1 =  CheckEXP (ceil((float) EXP1 * 1.13+1e-7));
                M1 = CheckMoney (M1);
                pay+=200;
            }
            else
            {

                M1 -= 120;
                EXP1 =  CheckEXP (ceil((float) EXP1 * 1.13+1e-7));
                M1 = CheckMoney (M1);
                pay+=120;
            }
            if(pay>n)break;
            if (EXP1 < 300)
            {

                EXP1 =  CheckEXP (ceil((float) EXP1 * 0.9+1e-7));
                M1 -= 100;
                M1 = CheckMoney (M1);
                pay+=100;
            }
            else
            {

                EXP1 =  CheckEXP (ceil((float) EXP1 * 0.9+1e-7));
                M1 -= 120;
                M1 = CheckMoney (M1);
                pay+=120;
            }
            if(pay>n)break;
        }
    }

    HP1 = CheckHP (ceil ((float) HP1 * 0.83));
    EXP1 = CheckEXP (ceil ((float) EXP1 * 1.17));

    int y;
    float p2;
    y = CloseSquarenum (EXP1);
    if (EXP1 >= y)
    {
        p2 = 1;
    }
    else
    {
        p2 = (float) ((EXP1 / y) + 80) / 123;
    }
    // --------Path3--------
    int p[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float p3;
    p3 = (float)(one_or_two(E2 , p)/100);
    if ((p1+p2+p3)==3)
    {
        EXP1 =CheckEXP(ceil((float)EXP1*0.75+1e-7));
    }
    else
    {
        float ptb;
        ptb =(float)(p1+p2+p3)/3;
        if (ptb <0.5)
        {
            HP1=CheckHP(ceil((float)HP1*0.85+1e-7));
            EXP1=CheckEXP(ceil((float)EXP1*1.15+1e-7));
        }
        else
        {
            HP1=CheckHP(ceil((float)HP1*0.9+1e-7));
            EXP1 =CheckEXP(ceil((float)EXP1*1.2+1e-7));
        }
    }


    return HP1 + EXP1 + M1;
}

// Task 3
int largest_left_cross(int a[10][10], int i, int j)
{
    int value=a[i][j];
    for (int t=1; ((t<10-i)&&(t<10-j)); t++)
    {
        if (value <a[i+t][j+t])
        {
            value = a[i+t][j+t];
        }
        else if (value<a[i-t][j-t])
        {
            value=a[i-t][j-t];
        }
    }
    return value;
}
int largest_right_cross(int a[10][10], int i, int j)
{
    int value=a[i][j];
    for (int t=1; ((t<10-i)&&(t<10-j)); t++)
    {
        if (value <a[i+t][j-t])
        {
            value = a[i+t][j-t];
        }
        else if (value<a[i-t][j+t])
        {
            value=a[i-t][j+t];
        }
    }
    return value;

}

int absolute(int a)
{
    if (a<0)
    {
        a = a*-1;
    }
    else {a=a;}
    return a;
}
int meeti(int a[10][10], int e3)
{
    int b=0;
    for (int i = 0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            if (a[i][j]>(e3*2))
            {
                b+=1;
            }
        }
    }
    while(b>=10)
    {
        b = (b/10)+(b%10);
    }

    return b;
}
int meetj(int a[10][10], int e3)
{
    int c=0;
    for (int i = 0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            if (a[i][j]<(-e3))
            {
                c+=1;
            }
        }
    }

    while (c>=10)
    {
        c = (c/10)+(c%10);
    }
    return c;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ((E3<0)&&(E3>99))return -99;
    int road[10][10]= {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};
    for (int i=0; i<10 ;i++)
    {
        for (int j=0; j<10;j++)
        {
            road[i][j]= (((E3*j)+(i*2))*(i-j));
        }
    }
    int homwas [10][10];
    for (int j=0; j<10;j++)
    {
        for (int i=0;i<10;i++)
        {
            if (largest_left_cross(road,i,j)>largest_right_cross(road,i,j))
            {
                homwas[i][j]=absolute(largest_left_cross(road,i,j));
            }
            else if (largest_left_cross(road,i,j)>largest_right_cross(road,i,j))
            {
                homwas[i][j]=absolute(largest_right_cross(road,i,j));
            }
            else
            {
                homwas[i][j]=absolute(largest_right_cross(road,i,j));
            }
        }
    }
    int point;
    if (absolute(road[meeti(road,E3)][meetj(road,E3)])> homwas[meeti(road,E3)][meetj(road,E3)])
    {
        point= road[meeti(road,E3)][meetj(road,E3)];
        EXP1*=0.88;
        EXP2*=0.88;
        HP1*=0.9;
        HP2*=0.9;
    }
    else
    {
        point = homwas[meeti(road,E3)][meetj(road,E3)];
        EXP1*=1.12;
        EXP2*=1.12;
        HP1*=1.1;
        HP2*=1.1;
    }
    //-1
    return point;
}

// Task 4
int len(const char *a)
{
    int t=1;
    for (int i=1;i<100;i++)
    {
        if (a[i]!='\0')
        {
            t +=1;
        }
        else {break;}
    }
    return t;
}
int lens(string a)
{
    string b;
    int t=1;
    a = a+ "?";
    b=a[0];
    for (int i=1;i<100;i++)
    {
        b = a[i];
        if (b!="?")
        {
            t +=1;
        }
        else {break;}
    }
    return t;
}

int checkse(string a, string se)
{
    string b;
    int t,v,x;
    x=lens(a)-lens(se)+1;
    v=lens(se);

    for ( int i=0;i<x;i++)
    {
       for (int j=i;j<v ; j++)
       {
           b =b + a[j];

       }
       if ( b==se)
       {
          t =-(300+i) ;
          break;
       }
       b = "";
       v+=1;

    }
    return t;
}

int checkspe(const char* a)
{
    string n,a1;
    a1=a;
    int b,c=0;
    for (int i=0;i<b;i++)
    {
        n=a1[i];
        if ((n!="@")&&(n!="#")&&(n!="%")&&(n!="$")&&(n!="!"))
        {
            c+=1;
        }
        if (c==(b-1)){c=-5;}
    }
    return c;
}
int checksam(const char* a)
{
    string a1,b,c;
    a1=a;
    int t,x,v;
    v=2;

    for ( int i=0;i<len(a);i++)
    {
       for (int j=i;j<v ; j++)
       {
           b =b + a1[j];
           c=a1[j];
           x=j;
       }
       c=c+c;
       if ( b==c)
       {
          t = -(400+x);
          break;
       }
       b = "";
       v+=1;

    }
    return t;
}

int checkremain(const char* a)
{
    string a1,c;
    a1=a;
    int n,b=len(a);
    for (int i=0; i<b;i++)
    {
        c=a1[i];
        if ((c=="^")||(c=="&")||(c=="*")||(c=="(")||(c==")")||(c=="-")||(c=="_")||(c=="+")||(c=="=")||(c=="[")||(c=="]")||(c=="{")||(c=="}")||(c=="?")||(c=="/")||(c==">")||(c=="<")||(c==".")||(c==",")||(c==" ;")||(c==" :")||(c=="'"))
            {
                n=i;
            }
    }
    return n;
}


int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string mail,se,q,s1;
    s1=s;
    mail=email;
    se = mail[0];
    for (int i=1;i<100;i++)
    {
        q = mail[i];
        if (q!="@")
        {
            se = se + q;
        }
        else{break;}
    }
    int result=0;

    result=checkremain(s);
    result=checkspe(s);
    result=checksam(s);
    result=checkse(s1,se);
    if (len(s)>20){result=-2; }
    else if ( len(s)<8){result = -1;}
    else if(result ==0){result=-10;}

    //-99
    return result;
}


// Task 5


int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
  // TODO: Complete this function
  string arr_pwds1[100];
  string t;
  for (int i = 0; i < num_pwds; i++)
	{
	  t = arr_pwds[i];
	  arr_pwds1[i] = t;
	}


  int g = 0, d = 0, result5;
  int hz[100];
  int addr[3][num_pwds];
  //so lan xuat hien
  for (int i = 0; i < num_pwds; i++)
	{
	  for (int j = 0; j < num_pwds; j++)
		{
		  if (arr_pwds1[i] == arr_pwds1[j])
			{
			  g += 1;
			}
		}
	  hz[i] = g;
	  g = 0;
	}
  // do dai & so lan xuat hien & vi tri
  for (int i = 0; i < num_pwds; i++)
	{


	  addr[0][i] = hz[i];
	  addr[1][i] = i;
	  addr[2][i] = lens (arr_pwds1[i]);
	  d += 1;

	}

  // 0:f; 1:vi_tri  2:dai  d:dai_mang

  int out = 0;
  for (int i = 0; i < d - 1; i++)
	{
	  if (addr[0][i] < addr[0][i + 1])
		{
		  addr[0][i] = addr[0][i + 1];
		  addr[1][i] = addr[1][i + 1];
		  addr[2][i] = addr[2][i + 1];
		  out += 1;
		}
	}
  d = d - out;

  for (int i = 0; i < d - 1; i++)
	{
	  if (addr[0][i] > addr[0][i + 1])
		{
		  result5 = addr[1][i];
		}
	  else if (addr[0][i] == addr[0][i + 1])
		{
		  if (addr[2][i] > addr[2][i + 1])
			{
			  result5 = addr[1][i];
			}
		  else if (addr[2][i] == addr[2][i + 1])
			{
			  result5 = addr[1][i];
			}

		}
	}


  //-1
  return result5;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
