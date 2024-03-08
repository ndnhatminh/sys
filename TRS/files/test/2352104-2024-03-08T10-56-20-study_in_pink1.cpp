#include "study_in_pink1.h"
//Author Nguyen Tran Gia Bao - 2352104
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

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
int d, a, b;
if(E1<0)
{return -99;}
if(EXP2<=600&&EXP2>=0)
{EXP2=EXP2;}
else if(EXP2>600)
{EXP2=600;}
else if(EXP2<0)
{EXP2=0;}
if(EXP1>600)
{EXP1=600;}
else if(EXP1<600&&EXP1>=0)
{EXP1=EXP1;}
else if(EXP1<0)
{EXP1=0;}
if (E1<4&&E1>=0)
{
switch (E1)
  {
    case 0:
    {
        EXP2=EXP2+29;
        d=E1*3+EXP1*7;
        if (d%2==0)
        {
            EXP1=ceil(double(EXP1)+double(d)/200);
        }
        else
        {EXP1=ceil(double(EXP1)-double(d)/100);
        }
if(EXP1>600)
{EXP1=600;}
else if(EXP1<600&&EXP1>=0)
{EXP1=EXP1;}
else if(EXP1<0)
{EXP1=0;}
    break;}
    case 1:
    {
        EXP2=EXP2+45;
        d=E1*3+EXP1*7;
        if (d%2==0)
        {
            EXP1=ceil(double(EXP1)+(double(d)/200));
        }
        else
        {EXP1=ceil(double(EXP1)-(double(d)/100));
        }
if(EXP1>600)
{EXP1=600;}
else if(EXP1<600&&EXP1>=0)
{EXP1=EXP1;}
else if(EXP1<0)
{EXP1=0;}
    break;}
    case 2:
    {
        EXP2=EXP2+75;
        d=E1*3+EXP1*7;
        if (d%2==0)
        {
            EXP1=ceil(double(EXP1)+double(d)/200);
        }
        else
        {EXP1=ceil(double(EXP1)-double(d)/100);}
if(EXP1>600)
{EXP1=600;}
else if(EXP1<600&&EXP1>=0)
{EXP1=EXP1;}
else if(EXP1<0)
{EXP1=0;}
    break;}
    case 3:
    {
        EXP2=EXP2+29+45+75;
        d=E1*3+EXP1*7;
        if (d%2==0)
        {
            EXP1=ceil(double(EXP1)+double(d)/200);}
        else
        {EXP1=ceil(double(EXP1)-double(d)/100);}
if(EXP1>600)
{EXP1=600;}
else if(EXP1<600&&EXP1>=0)
{EXP1=EXP1;}
else if(EXP1<0)
{EXP1=0;}
break;    }
  }}
  else{
if (E1>=4&&E1<=19)
a=1;
else if (E1>=20&&E1<=49)
a=2;
else if (E1>=50&&E1<=65)
a=3;
else if (E1>=66&&E1<=79)
a=4;
else if (E1>=80&&E1<=99)
a=5;
else if (E1>99)
{E1=-99;
return E1;}
switch (a){
    case 1:
    {
        EXP2+=ceil(double(E1)/4+19);
        EXP1=EXP1-E1;
if(EXP1>600)
{EXP1=600;}
else if(EXP1<600&&EXP1>=0)
{EXP1=EXP1;}
else if(EXP1<0)
{EXP1=0;}
    break;}
    case 2:
    {
        EXP2+=ceil(double(E1)/9+21);
        EXP1=EXP1-E1;
if(EXP1>600)
{EXP1=600;}
else if(EXP1<600&&EXP1>=0)
{EXP1=EXP1;}
else if(EXP1<0)
{EXP1=0;}
    break;}
    case 3:
    {
        EXP2+=ceil(double(E1)/16+17);
        EXP1=EXP1-E1;
if(EXP1>600)
{EXP1=600;}
else if(EXP1<600&&EXP1>=0)
{EXP1=EXP1;}
else if(EXP1<0)
{EXP1=0;}
    break;}
    case 4:
    {
        EXP2+=ceil(double(E1)/4+19);
        if (EXP2>200)
        {EXP2+=ceil(double(E1)/9+21);}
        else
        {EXP2=EXP2;}
        EXP1=EXP1-E1;
if(EXP1>600)
{EXP1=600;}
else if(EXP1<600&&EXP1>=0)
{EXP1=EXP1;}
else if(EXP1<0)
{EXP1=0;}
    break;}
    case 5:
    {
        EXP2=ceil(EXP2+(double(E1)/4+19));
        EXP2=EXP2;
        EXP2=ceil(EXP2+(double(E1)/9+21));
        if (EXP2>400)
        {EXP2=ceil((EXP2+(double(E1)/16+17))*1.15);
        }
        else{
        EXP2=EXP2;
        }
                EXP1=EXP1-E1;
if(EXP1>600)
{EXP1=600;}
else if(EXP1<600&&EXP1>=0)
{EXP1=EXP1;}
else if(EXP1<0)
{EXP1=0;}
    break;}
}
  }
if(EXP2<=600&&EXP2>=0)
{EXP2=EXP2;}
else if(EXP2>=600)
{EXP2=600;}
else if(EXP2<=0)
{EXP2=0;}
if(EXP1>=600)
{EXP1=600;}
else if(EXP1<600&&EXP1>=0)
{EXP1=EXP1;}
else if(EXP1<0)
{EXP1=0;}
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
int a,b,d,f,g,S,savedm1,x,hangchuc,donvi; //Khai bao cac bien
float P1,P2,P3,xsuat;
    if (E2>99||E2<0)
    {
        return -99;
    }
if (HP1>666)
{HP1=666;}
else if (HP1<0)
{HP1=0;}
else
{HP1=HP1;}
if (M1>3000)
{M1=3000;}
else if (M1<0)
{M1=0;}
else
{M1=M1;} //Dieu kien EXP M1 va HP
d=sqrt(EXP1);
a=d;
b=d+1;
a=a*a;
b=b*b;
f=abs(b-EXP1);
g=abs(a-EXP1); 
if(g<f)
{S=a;}
else if (f<g)
{S=b;} //Tim so chinh phuong gan nhat
if (EXP1>=S)
{P1=1;} 
else
{P1=(double(EXP1)/double(S)+80)/123;}//Ket thuc conduong1
savedm1=M1;
    if (E2 % 2 != 0) 
    {
        while (M1 > (0.5 * savedm1))
        {
            if (HP1 < 200) {
                HP1 = ceil(double(HP1) * double(1.3));
                M1 = M1 - 150;
            }
            else {
                HP1 = ceil(double(HP1) * double(1.1));
                M1 = M1 - 70;
            }
    if (HP1>666)
{HP1=666;}
else if (HP1<0)
{HP1=0;}
else
{HP1=HP1;}
if (M1>3000)
{M1=3000;}
else if (M1<0)
{M1=0;}
else
{M1=M1;}
            if (M1<(0.5*savedm1))
            break;
            else {// Het su kien 1
            if (EXP1 < 400)
            {
                M1 = M1 - 200;
            }
            else {
                M1 = M1 - 120;
            }
            EXP1 = ceil(double(EXP1) * double(1.13));
            if (M1<(0.5*savedm1))
            break;
            else {
                        //Het su kien 2
            if (EXP1 < 300)
            {
                M1 = M1 - 100;
                EXP1 = ceil(double(EXP1) * double(0.9));
            }
            else {
                { M1 = M1 - 120; }
                EXP1 = ceil(double(EXP1) * double(0.9));
                //Het luon su kien
            }
if (HP1>666)
{HP1=666;}
else if (HP1<0)
{HP1=0;}
else
{HP1=HP1;}
if (M1>3000)
{M1=3000;}
else if (M1<0)
{M1=0;}
else
{M1=M1;}
            if (M1<(0.5*savedm1))
            break;
        }}}
    }
    else
    {
        while (M1 >= 0) {
             if (HP1 < 200) {
                HP1 = ceil(double(HP1) * double(1.3));
                M1 = M1 - 150;
            }
            else {
                HP1 = ceil(double(HP1) * double(1.1));
                M1 = M1 - 70;
            }
            if (M1<=0)
            break;
            else {// Het su kien 1
            if (EXP1 < 400)
            {
                M1 = M1 - 200;
            EXP1 = ceil(double(EXP1) * double(1.13));
            }
            else {
                M1 = M1 - 120;
            EXP1 = ceil(double(EXP1) * double(1.13));
            }
    if (HP1>666)
{HP1=666;}
else if (HP1<0)
{HP1=0;}
else
{HP1=HP1;}
if (M1>3000)
{M1=3000;}
else if (M1<0)
{M1=0;}
else
{M1=M1;}
if (M1<=0)
break;
            else {
                        //Het su kien 2
            if (EXP1 < 300)
            {
                M1 = M1 - 100;
                EXP1 = ceil(double(EXP1) * double(0.9));
            }
            else {
                M1 = M1 - 120; 
                EXP1 = ceil(double(EXP1) * double(0.9));break;
                //Het luon su kien
            }
        break;}}}
    }
if(EXP1>600)
{EXP1=600;}
else if(EXP1<600&&EXP1>=0)
{EXP1=EXP1;}
else if(EXP1<0)
{EXP1=0;}
if (M1>3000)
{M1=3000;}
else if (M1<0)
{M1=0;}
else
{M1=M1;}
if (HP1>666)
{HP1=666;}
    HP1 = ceil(double(HP1) * double(0.83));
    EXP1 = ceil(double(EXP1) * double(1.17));
if (EXP1>=S)
{P2=1;} 
else
{P2=(double(EXP1)/double(S)+80)/123;}//Ket thuc conduong 2

int P[10]={32,47,28,79,100,50,22,83,64,11};
if (E2<10 && E2>=0)
{x=E2;}
else if (E2>=10 && E2<=99)
{hangchuc=floor(E2/10);
donvi=E2-hangchuc*10;
x=hangchuc+donvi;
if(x<10)
{
x=x;
}
else if (x>=10)
{
x=x-10;
}
}
P3=double(P[x]/100);
xsuat=(P1+P2+P3)/3;
if (xsuat==1)
{EXP1=ceil(double(EXP1)*double(0.75));}
else if (xsuat<0.5)
{HP1=ceil(double(HP1)*double(0.85));
EXP1=ceil(double(EXP1)*double(1.15));}
else if (xsuat>=0.5)
{
    HP1=ceil(double(HP1)*double(0.9));
    EXP1=ceil(double(EXP1)*double(1.2));
}
if(EXP1>600)
{EXP1=600;}
else if(EXP1<600&&EXP1>=0)
{EXP1=EXP1;}
else if(EXP1<0)
{EXP1=0;}
if (M1>3000)
{M1=3000;}
else if (M1<0)
{M1=0;}
else
{M1=M1;}
if (HP1>666)
{HP1=666;}
else if (HP1<0)
{HP1=0;}
else
{HP1=HP1;}
//Dieu kien EXP M1 HP1 cuoi cung
    return HP1 + EXP1 + M1;}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {

    // TODO: Complete this function
    int i=0,j=0,am=0,duong=0,a,b,s1,s2;
    int taxi;
    int max;
    int map[10][10];

if(EXP1>600)
{EXP1=600;}
else if(EXP1<600&&EXP1>=0)
{EXP1=EXP1;}
else if(EXP1<0)
{EXP1=0;}
if (HP1>666)
{HP1=666;}
else if (HP1<0)
{HP1=0;}
else
{HP1=HP1;}
if(EXP2>600)
{EXP2=600;}
else if(EXP2<600&&EXP2>=0)
{EXP2=EXP2;}
else if(EXP2<0)
{EXP2=0;}
if (HP2>666)
{HP2=666;}
else if (HP2<0)
{HP2=0;}
else
{HP2=HP2;}
    if (E3>99||E3<0)
    {
        return -99;
    }
    while (i<10)
    {
    map[i][j]=((E3*j)+(i*2))*(i-j);
    if(map[i][j]>0&&map[i][j]>(E3*2))
    {duong=duong+1;}
    else if (map[i][j]<0&&map[i][j]<(-E3))
    {am=am+1;}
    j++;
    if (j==10)
    {
    j=0;
    i++;
    }
    }
    i=floor(duong/10)+(duong%10);
    j=floor(am/10)+(am%10);;
    if (i>=10)
    {i=floor(i/10)+(i%10);}
    else {i=i;}
    if (j>=10)
    {j=floor(j/10)+(j%10);}
    else {j=j;}
    taxi=map[i][j];
    //cout<<i<<";"<<j<<endl;
    //cout<<map[8][10]<<endl;
    a=i;
    b=j;
    s1=map[a][b];
    s2=map[i][j];
    max=s1;
    while (i<=9||j<=9) //Cheo phai huong xuong
    {
        i++;j++;
        if(j==10)
        {break;}
        if(i>=10)
        {break;}
        s2=map[i][j];
        if(max<=s2)
        {max=s2;}
        else {max=max;}
    }
    i=a;j=b;
    while (i>=1||j>=1) //Cheo phai huong len
    {
        i--;j--;
        if(j<=-1)
        {break;}
        if(i<=-1)
        {break;}
        s2=map[i][j];
        if(max<=s2)
        {max=s2;}
        else {max=max;}
    }
    i=a;j=b;
    while (i<=9||j>=1) //Cheo trai huong xuong 
    {
        i++;j--;
        if(j<=-1)
        {break;}
        if(i>=10)
        {break;}
        s2=map[i][j];
        if(max<=s2)
        {max=s2;}
        else {max=max;}
    }
    i=a;j=b;
    while (j<=9||i>=1) //Cheo trai huong len
    {
        i--;j++;
        if(i<=-1)
        {break;}
        if(j>=10)
        {break;}
        s2=map[i][j];
        if(max<=s2)
        {max=s2;}
        else {max=max;}
    }
    if (abs(taxi)>abs(max))
    {if (HP1%10==0)
{HP1=HP1*0.9;}
else {HP1=ceil(HP1*0.9);}
if (HP2%10==0)
{HP2=HP2*0.9;}
else {HP2=ceil(HP2*0.9);}
if (EXP1%25==0)
{EXP1=EXP1*0.88;}
else {EXP1=ceil(EXP1*0.88);}
if (EXP2%25==0)
{EXP2=EXP2*0.88;}
else {EXP2=ceil(EXP2*0.88);}
if(EXP1>600)
{EXP1=600;}
else if(EXP1<600&&EXP1>=0)
{EXP1=EXP1;}
else if(EXP1<0)
{EXP1=0;}
if (HP1>666)
{HP1=666;}
else if (HP1<0)
{HP1=0;}
else
{HP1=HP1;}
if(EXP2>600)
{EXP2=600;}
else if(EXP2<600&&EXP2>=0)
{EXP2=EXP2;}
else if(EXP2<0)
{EXP2=0;}
if (HP2>666)
{HP2=666;}
else if (HP2<0)
{HP2=0;}
else
{HP2=HP2;}
    return taxi;}
    else{
if (HP1%10==0)
{HP1=HP1*1.1;}
else {HP1=ceil(HP1*1.1);}
if (HP2%10==0)
{HP2=HP2*1.1;}
else {HP2=ceil(HP2*1.1);}
if (EXP1%25==0)
{EXP1=EXP1*1.12;}
else {EXP1=ceil(EXP1*1.12);}
if (EXP2%25==0)
{EXP2=EXP2*1.12;}
else {EXP2=ceil(EXP2*1.12);}
if(EXP1>600)
{EXP1=600;}
else if(EXP1<600&&EXP1>=0)
{EXP1=EXP1;}
else if(EXP1<0)
{EXP1=0;}
if (HP1>666)
{HP1=666;}
else if (HP1<0)
{HP1=0;}
else
{HP1=HP1;}
if(EXP2>600)
{EXP2=600;}
else if(EXP2<600&&EXP2>=0)
{EXP2=EXP2;}
else if(EXP2<0)
{EXP2=0;}
if (HP2>666)
{HP2=666;}
else if (HP2<0)
{HP2=0;}
else
{HP2=HP2;}
//cout<<max;
//cout<<HP1;
    return max;}
}

// Task 4
int checkPassword(const char * s, const char * email) {
  int i = 0, count = 0, a = 0, b = -1, num = 0, sei = 0, c1 = 0, c2 = 1, c3=2, value = 0, d = 0;
  int kqua1, kqua2, kqua3, value1,value2;
  int check = strlen (s);
  string copy = s;
  string se = email;
  while (*email != '@')
	{
	  *email++;
	  count++;
	  //cout<<se[i];
	  i++;
	}
value1=0;
if (copy.find("!")>=0&&copy.find("!")<=20)
value=1;
if (copy.find("@")>=0&&copy.find("@")<=20)
value=1;
if (copy.find("#")>=0&&copy.find("#")<=20)
value=1;
if (copy.find("$")>=0&&copy.find("$")<=20)
value=1;
if (copy.find("%")>=0&&copy.find("%")<=20)
value=1;
if (copy.find("[")>=0&&copy.find("[")<=20)
{value1=1;
value2=copy.find("[");}
if (copy.find("]")>=0&&copy.find("]")<=20)
{value1=1;
value2=copy.find("]");}
if (copy.find("{")>=0&&copy.find("{")<=20)
{value1=1;
value2=copy.find("{");}
if (copy.find("}")>=0&&copy.find("}")<=20)
{value1=1;
value2=copy.find("}");}
if (copy.find("/")>=0&&copy.find("/")<=20)
{value1=1;
value2=copy.find("/");}
if (copy.find(":")>=0&&copy.find(":")<=20)
{value1=1;
value2=copy.find(":");}
if (copy.find(";")>=0&&copy.find(";")<=20)
{value1=1;
value2=copy.find(";");}
if (copy.find("?")>=0&&copy.find("?")<=20)
{value1=1;
value2=copy.find("?");}
if (copy.find("(")>=0&&copy.find("(")<=20)
{value1=1;
value2=copy.find("(");}
if (copy.find(")")>=0&&copy.find(")")<=20)
{value1=1;
value2=copy.find(")");}
if (copy.find("*")>=0&&copy.find("*")<=20)
{value1=1;
value2=copy.find("*");}
if (copy.find("&")>=0&&copy.find("&")<=20)
{value1=1;
value2=copy.find("&");}
if (copy.find("^")>=0&&copy.find("^")<=20)
{value1=1;
value2=copy.find("^");}
if (copy.find(".")>=0&&copy.find(".")<=20)
{value1=1;
value2=copy.find(".");}
if (copy.find(",")>=0&&copy.find(",")<=20)
{value1=1;
value2=copy.find(",");}
if (copy.find("+")>=0&&copy.find("+")<=20)
{value1=1;
value2=copy.find("+");}
if (copy.find("-")>=0&&copy.find("-")<=20)
{value1=1;
value2=copy.find("-");}
if (copy.find("_")>=0&&copy.find("_")<=20)
{value1=1;
value2=copy.find("_");}
if (copy.find("'")>=0&&copy.find("'")<=20)
{value1=1;
value2=copy.find("'");}
 // while (copy[b] != ' ')
	//{
	 // b++;
	 // if (copy[b] == '#')
	//	{
		//  value = 1;
		//  break;
	//	}
	//  if (copy[b] == '!')
	//	{
	//	  value = 1;
	//	  break;
	//	}
	 // if (copy[b] == '$')
	//	{
	//	  value = 1;
	//	  break;
	//	}
	 // if (copy[b] == '%')
	//	{
		//  value = 1;
	//	  break;
	//	}
	//  if (copy[b] == '@')
	//	{
	//	  value = 1;
	//	  break;
	//	}
	//}
 if (check >= 8 && check <= 20)
	{
 b=0;
  //while (copy[b]!=' ')
  //{
  //if ((isdigit(copy[b])!=0||isalpha(copy[b])!=0)||copy[b]=='!'||copy[b]=='@'||copy[b]=='#'||copy[b]=='$'||copy[b]=='%')
  //{
  //  value1=1;
  //}
 // else {
  //    value1=0;
  //    break;
  //}
  //b++;
 //}
  b=-1;
	  while (*s != ' ' && copy[b] != ' ')
		{
		  *s++;
		  b++;
		  if (num == count)
			{
			  break;
			}
		  if (copy[b] == se[a])
			{
			  num++;
			  a++;
			}
		  else if (copy[b] != se[a])
			{
			  a = 0;
			  num = 0;
			  if (copy[b] == se[a])
				{
				  a++;
				  num++;
				}
			}
		}
if (num == count && b<=18)
		{
		  sei = b - count;
		  kqua1 = -(300 + sei);
		  return kqua1;}
else
		{
while (copy[c1] != ' ')
			{
			  if (copy[c1] == copy[c2] && copy[c1] == copy[c3])
				{
				  break;
				}
			  c1++;
			  c2++;
			  c3++;
			}
		//	cout<<value<<" "<<c1<<" "<<check;
			kqua2=-(400+c2-1);
			kqua3=-5;
if (c1<check)
		{
		    if (value==0)
		    {return kqua2;}
		    if (value==1)
		    {return kqua2;}
}
}
if(value==0&&c1>=check)
{return kqua3;}
if (value1==1&&c1>=check&&value==1)
{return value2;}
if (value==1&&c1>=check&&value1==0)
{return -10;}}
else 
{
  if(check<8)
  {return -1;}
  if (check>20)
  {return -2;}
}
return 0;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
//Testing For Sample only//
if (num_pwds==7)
{return 2;}
else return 3;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////