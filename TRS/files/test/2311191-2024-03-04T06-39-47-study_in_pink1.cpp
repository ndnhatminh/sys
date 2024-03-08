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
double errorceil(double a)
{
    if (((int(a)-0.001)<a)&&(a<(int(a)+0.001)))
    {
        return int(a);
    }
    else
    {
        return ceil(a);
    }
}
////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
void CheckFunction1(int & EXP1, int & EXP2)
{
    if (EXP1>600)
    {
        EXP1=600;
    }
    else if(EXP1<0)
    {
        EXP1=0;
    }
    if (EXP2>600)
    {
        EXP2=600;
    }
    else if(EXP2<0)
    {
        EXP2=0;
    }

}
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    if (E1>99||E1<0)
    {
    return -99;
    }
    else if ((0<=E1)&& (E1<=3))
    {
    int D;
    switch(E1)
    {
    case 0:
    {
    EXP2=EXP2+29;
    CheckFunction1( EXP1,  EXP2);
    break;
    }
    case 1:
    {
    EXP2=EXP2+45;
   CheckFunction1( EXP1,  EXP2);
    break;
    }
    case 2:
    {
    EXP2=EXP2+75;
    CheckFunction1( EXP1,  EXP2);
    break;
    }
    case 3:
    {
    EXP2=EXP2+29+45+75;
    CheckFunction1( EXP1,  EXP2);
    break;
    }
    }
    D=E1*3+EXP1*7;
    
    if (D%2==0)
    {
        EXP1=errorceil(EXP1+D/200.0);
        CheckFunction1( EXP1,  EXP2);
    }
    else 
    {
        EXP1=errorceil(EXP1-D/100.0);
        CheckFunction1( EXP1,  EXP2);
    }
    }
    else if ((4<=E1)&&(E1<=99))
    {
    if ((4<=E1)&&(E1<=19))
    {
        EXP2=errorceil(EXP2+(E1/4.0+19));
        CheckFunction1( EXP1,  EXP2);
    }
    else if ((20<=E1)&&(E1<=49))
    {
        EXP2=errorceil(EXP2+(E1/9.0+21));
        CheckFunction1(EXP1,EXP2);
    }
    else if ((50<=E1)&&(E1<=65))
    {
        EXP2=errorceil(EXP2+(E1/16.0+17));
        CheckFunction1( EXP1,  EXP2);
    }
    else if ((66<=E1)&&(E1<=79))
    {
        EXP2=errorceil(EXP2+(E1/4.0+19));
        CheckFunction1( EXP1,  EXP2);
        if(EXP2>200)
        {
        EXP2=errorceil(EXP2+(E1/9.0+21));
        CheckFunction1( EXP1,  EXP2);
        }
        else{}
         
    }
    else if((80<=E1)&&(E1<=99))
    {
        EXP2=errorceil(EXP2+(E1/4.0+19)+(E1/9.0+21));
        CheckFunction1( EXP1,  EXP2);
        if (EXP2>400)
        {
        EXP2=errorceil(EXP2+(E1/16.0+17));
        CheckFunction1(EXP1,EXP2);
        }
        else{}
       
        EXP2=errorceil(EXP2*1.15);
        CheckFunction1( EXP1,  EXP2);
      
    }
    EXP1=EXP1-E1;
    CheckFunction1( EXP1,  EXP2);
    }
    
    
    
    return EXP1 + EXP2;
}
void CheckFunction2(int &HP1,int & EXP1,int & M1)
{
if (HP1>666)
{
    HP1=666;
}
else if (HP1<0)
{
    HP1=0;
}
if (EXP1>600)
{
    EXP1=600;
}
else if (EXP1<0)
{
    EXP1=0;
}
if (M1>3000)
{
    M1=3000;
}
else if (M1<0)
{
    M1=0;
}
}
int checknearestSquare(int & EXP1)
{
    
    if(EXP1==0)
    {
        return 0;
    }
    else{
    int diff=1000;
    int flag=0;
    int squareset[]={1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400,441,484,529,576};
    for (int i=0;i<24;i++)
    {
    if (EXP1>squareset[i])
    {
        if (EXP1-squareset[i]<diff)
        {
            flag=i;
            diff=EXP1-squareset[i];
        }
        else{}
    }
    else if (EXP1==squareset[i])
    {
        
        return squareset[i];
    }
    else if (EXP1<squareset[i])
    {
        if (squareset[i]-EXP1<diff)
        {
            flag=i;
            diff=squareset[i]-EXP1;
        }
        else{}
    }
    }
    
    return squareset[flag];
    }
}
double firstPath(int a,int & EXP1)
{
    
       if(a<=EXP1)
    {
    return 1;
    }
    else
    {
    return (EXP1/a+80)/123;
    }
}
double secondPath(int & M1,int & HP1,int & EXP1,int E2)
{   

if (E2%2==0)
{
    if(HP1<200)
    {
        HP1=errorceil(HP1*1.3);
        M1=M1-150;
        CheckFunction2(HP1,EXP1,M1);
    }
    else
    {
        HP1=errorceil(HP1*1.1);
        M1=M1-70;
        CheckFunction2(HP1,EXP1,M1);
    }
    if (M1==0)
    {
        HP1=errorceil(HP1*0.83);
        EXP1=errorceil(EXP1*1.17);
        CheckFunction2(HP1,EXP1,M1);
        return (firstPath(checknearestSquare(EXP1),EXP1));
    }
    else{}
    if (EXP1<400)
    {
        M1=M1-200;
        CheckFunction2(HP1,EXP1,M1);
    }
    else
    {
        M1=M1-120;
        CheckFunction2(HP1,EXP1,M1);
    }
    EXP1=errorceil(EXP1*1.13);
    CheckFunction2(HP1,EXP1,M1);
    if (M1==0)
    {
        HP1=errorceil(HP1*0.83);
        EXP1=errorceil(EXP1*1.17);
        CheckFunction2(HP1,EXP1,M1);
        return (firstPath(checknearestSquare(EXP1),EXP1));
    }
    else{} 
    if (EXP1<300)
    {
        M1=M1-100;
        CheckFunction2(HP1,EXP1,M1);
    }
    else
    {
        M1=M1-120;
        CheckFunction2(HP1,EXP1,M1);
    }
    EXP1=errorceil(EXP1*0.9);
    if (M1==0)
    {
        HP1=errorceil(HP1*0.83);
        EXP1=errorceil(EXP1*1.17);
        CheckFunction2(HP1,EXP1,M1);
        return (firstPath(checknearestSquare(EXP1),EXP1));
    }
    else{} 
}
else
{
    int flag=0;
    int a=M1;
    for (flag;flag<1;flag)
    {
        if(HP1<200)
        {
            HP1=errorceil(HP1*1.3);
            M1=M1-150;
            CheckFunction2(HP1,EXP1,M1);
    
        }
        else
        {
            HP1=errorceil(HP1*1.1);
            M1=M1-70;
            CheckFunction2(HP1,EXP1,M1);
        }
        if(M1<errorceil(a/2.0))
        {
            flag=flag+1;
            break;
        }
        else{}
        if(EXP1<400)
        {
            M1=M1-200;
            CheckFunction2(HP1,EXP1,M1);
        }
        else
        {
            M1=M1-120;
            CheckFunction2(HP1,EXP1,M1);
        }
        EXP1=errorceil(EXP1*1.13);
        CheckFunction2(HP1,EXP1,M1);
        if(M1<errorceil(a/2.0))
        {
            flag=flag+1;
            break;
        }
        else{}
        if(EXP1<300)
        {
            M1=M1-100;
            CheckFunction2(HP1,EXP1,M1);
        }
        else
        {
            M1=M1-120;
            CheckFunction2(HP1,EXP1,M1);
        }
        EXP1=errorceil(EXP1*1.1);
        CheckFunction2(HP1,EXP1,M1);
        if(M1<errorceil(a/2.0))
        {
            flag=flag+1;
            break;
        }
        else{}
    }
}
    HP1=errorceil(HP1*0.83);
    EXP1=errorceil(EXP1*1.17);
    CheckFunction2(HP1,EXP1,M1);
    return (firstPath(checknearestSquare(EXP1),EXP1));
}
double thirdPath(int E2)
{
    double array[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2<10)
    {
    return array[E2];
    }
    else 
    {
    return array[(E2%10+(E2-E2%10)/10)%10];
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2<0||E2>99)
    {
        return -99;
    }
    else{
    double P;
    CheckFunction2(HP1, EXP1, M1);
    double becauseitsthefirstpath=firstPath(checknearestSquare(EXP1),EXP1);
    P=(becauseitsthefirstpath+secondPath(M1,HP1,EXP1,E2)+thirdPath(E2)/100)/3;
    if (P==1)
    {
        EXP1=errorceil(EXP1*0.75);
        CheckFunction2(HP1, EXP1, M1);
    }
    else if (P<0.5)
    {
        HP1=errorceil(HP1*0.85);
        EXP1=errorceil(EXP1*1.15);
        CheckFunction2(HP1, EXP1, M1);
    }
    else if((P>=0.5)&&(P<1))
    {
        HP1=errorceil(HP1*0.9);
        EXP1=errorceil(EXP1*1.2);
        CheckFunction2(HP1, EXP1, M1);
    }
    return HP1 + EXP1 + M1;
    }
}

void checkFunction3(int & HP1,int & EXP1, int & HP2, int &EXP2)
{
    if (HP1>666)
    {
        HP1=666;
    }
    else if (HP1<0)
    {
        HP1=0;
    }
    if (EXP1>600)
    {
        EXP1=600;
    }
    else if(EXP1<0)
    {
        EXP1=0;
    }
    if (HP2>666)
    {
        HP2=666;
    }
    else if (HP2<0)
    {
        HP2=0;
    }
    if (EXP2>600)
    {
        EXP2=600;
    }
    else if(EXP2<0)
    {
        EXP2=0;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0||E3>99)
    {
    return -99;
    }
    else
    {
    int arr1[10][10];
    int arr2[10][10];
    for(int i=0;i<10;)
    {
        for(int j=0;j<10;j=j+1)
        {
            arr1[i][j]=((E3*j)+(i*2))*(i-j);
            if (j==9)
            {
                i++;
            }
        } 
    }
for (int j=0;j<10;)
    {
for (int i=0;i<10;i++)
{
    int a2=i,b2=j;
    int a1=i,b1=j;
    int a3=i,b3=j;
    int a4=i,b4=j;
    int max=arr1[i][j];
        for(int z=0;z<1;)
        {  
            if(arr1[a1][b1]>max)
            {
            max=arr1[a1][b1];
            }
            else{}
            if((a1==0)||(b1==0))
            {
                z++;
                break;
            }
            else
        {
            a1=a1-1;
            b1=b1-1;
           
            if((a1==0)||(b1==0))
            {
            if(arr1[a1][b1]>max)
            {
            max=arr1[a1][b1];
                z++;
                break;
            }
            }
        }
        }
        for(int z=0;z<1;)
        {
            if(arr1[a2][b2]>max)
            {
            max=arr1[a2][b2];
            }
            if((a2==9)||(b2==9))
            {
                z++;
                break;
            }
            else
            {
            a2=a2+1;
            b2=b2+1;
            
            if((a2==9)||(b2==9))
            { 
            if(arr1[a2][b2]>max)
            {
            max=arr1[a2][b2];
            }
                z++;
                break;
            }
            }
        }
        for (int z=0;z<1;)
        {            
            if(arr1[a3][b3]>max)
            {
            max=arr1[a3][b3];
            }
             if((a3==0)||(b3==9))
            {
                z++;
                break;
            }
            else
            {
            a3=a3-1;
            b3=b3+1;
            if((a3==0)||(b3==9))
            {
                if(arr1[a3][b3]>max)
            {
            max=arr1[a3][b3];
            }
                z++;
                break;
            }
            }
        }
        for(int z=0;z<1;)
        {
            if(arr1[a4][b4]>max)
            {
            max=arr1[a4][b4];
            }
            if((a4==9)||(b4==0))
            {
                z++;
                break;
            }
            else
            {
            a4=a4+1;
            b4=b4-1;
            if((a4==9)||(b4==0))
            {           
            if(arr1[a4][b4]>max)
            {
            max=arr1[a4][b4];
            }
                z++;
                break;
            }
            }
        }
    arr2[i][j]=max;
    if (i==9)
    {
        j=j+1;
    }
    }
    }
    int Meetingpointx=0;
    int Meetingpointy=0;
    for(int i=0;i<10;)
    {
        for(int j=0;j<10;j++)
        {
            if(arr1[i][j]>2*E3)
            {
                Meetingpointx=Meetingpointx+1;
            }
            if(j==9)
            {
                i++;
                break;
            }
        }
    }
        for(int i=0;i<10;)
    {
        for(int j=0;j<10;j++)
        {
            if(arr1[i][j]<-E3)
            {
                Meetingpointy=Meetingpointy+1;
            }
            if(j==9)
            {
                i++;
                break;
            }
        }
    }
    for (int flag=0;flag<1;)
    {
        if (Meetingpointx>=10)
        {
            Meetingpointx=Meetingpointx%10+(Meetingpointx-Meetingpointx%10)/10;
        }
        else
        {
            flag=flag+1;
            break;
        }
    }
    for (int flag=0;flag<1;)
    {
        if (Meetingpointy>=10)
        {
            Meetingpointy=Meetingpointy%10+(Meetingpointy-Meetingpointy%10)/10;
        }
        else
        {
            flag=flag+1;
            break;
        }
    }
    if (abs(arr1[Meetingpointx][Meetingpointy])>arr2[Meetingpointx][Meetingpointy])
    {
        EXP1=errorceil(EXP1*0.88);
        EXP2=errorceil(EXP2*0.88);
        HP1=errorceil(HP1*0.9);
        HP2=errorceil(HP2*0.9);
        checkFunction3(HP1,HP2,EXP1,EXP2);
    }
    else
    {
        EXP1=errorceil(EXP1*1.12);
        EXP2=errorceil(EXP2*1.12);
        HP1=errorceil(int(HP1*1.1));
        HP2=errorceil(HP2*1.1);
        checkFunction3(HP1,EXP1,HP2,EXP2);
    }
    return arr1[Meetingpointx][Meetingpointy];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int idx;
    string se;
    for (int i=0;i<100;i++)
    {
        if(email[i]!='@')
        {

        }
        else
        {
            idx=i;
        }
    }
    se.insert(0,email,0,idx);
    if (strlen(s)<8)
    {
        return -1;
    }
    else if (strlen(s)>20)
    {
        return -2;
    }
        for(int a=0;a<strlen(s);a++)
        {
            bool flag=0;
            for(int z=0;z<se.size();z++)
            {
            if (s[a+z]==se[z])
            {
                flag=1;
            }
            else
            {
                flag=0;
                break;
            }
            if (flag==1)
            {
                return -(300+a);
            }
            }
        }
        for (int a=0;a<strlen(s);a++)
        {
            if ((s[a]==s[a])&&(s[a]==s[a+1])&&(s[a]==s[a+2]))
            {
                return -(400+a);
            }
        }
       bool flag=0;
       for (int a=0;a<strlen(s);a++)
        {
            if(s[a]=='@'||s[a]=='#'||s[a]=='%'||s[a]=='$'||s[a]=='!')
            {
                flag=1;
            }
            else
            {
            }
        }
        if (flag==0)
        {
            return -5;
        }
    for(int a=0;a<strlen(s);a++)
    {
        if(s[a]=='0'||s[a]=='1'||s[a]=='2'||s[a]=='3'||s[a]=='4'||s[a]=='5'||s[a]=='6'||s[a]=='7'||s[a]=='8'||s[a]=='9'||s[a]=='A'||s[a]=='B'||s[a]=='C'||s[a]=='D'||s[a]=='E'||s[a]=='F'||s[a]=='G'||s[a]=='H'||s[a]=='I'||s[a]=='J'||s[a]=='K'||s[a]=='L'||s[a]=='M'||s[a]=='N'||s[a]=='O'||s[a]=='P'||s[a]=='Q'||s[a]=='R'||s[a]=='S'||s[a]=='T'||s[a]=='U'||s[a]=='V'||s[a]=='W'||s[a]=='X'||s[a]=='Y'||s[a]=='Z'||s[a]=='a'||s[a]=='b'||s[a]=='c'||s[a]=='d'||s[a]=='e'||s[a]=='f'||s[a]=='g'||s[a]=='h'||s[a]=='i'||s[a]=='j'||s[a]=='k'||s[a]=='l'||s[a]=='m'||s[a]=='n'||s[a]=='o'||s[a]=='p'||s[a]=='q'||s[a]=='r'||s[a]=='s'||s[a]=='t'||s[a]=='u'||s[a]=='v'||s[a]=='w'||s[a]=='x'||s[a]=='y'||s[a]=='z'||s[a]=='@'||s[a]=='#'||s[a]=='%'||s[a]=='$'||s[a]=='!')
        {

        }
        else
        {
            return a;
        }
    }
   return -10; 
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) 
{
    // TODO: Complete this function
string NOTFILLERARRAY[num_pwds];
int    FILLERARRAY[num_pwds];
int cursor=1;
for (int a=0;a<num_pwds;a++)
{
if (a==0)
{
    NOTFILLERARRAY[0]=arr_pwds[0];
}
else
{
    for(int i=0;i<a;i++)
    {
    if ((NOTFILLERARRAY[a-i-1].compare(arr_pwds[a]))==0)
    {
        break;
    }
    if (i==(a-1))
    {
        NOTFILLERARRAY[cursor]=arr_pwds[a];
        cursor=cursor+1;
    }
    }
}
}
for(int i=0;i<num_pwds;i++)
{
int a=0;
for (int z=0;z<num_pwds;z++)
if  (NOTFILLERARRAY[i].compare(arr_pwds[z])==0)
{
    a=a+1;
}
else
{}
FILLERARRAY[i]=a;
}
int max;
for(int i=0;i<num_pwds;i++)
{
if (i==0)
{
    max=FILLERARRAY[0];
}
else
{
    if(FILLERARRAY[i]>max)
    {
        max=FILLERARRAY[i];
    }
}
}
for (int i=0;i<num_pwds;i++)
{
    if (FILLERARRAY[i]==max)
    {
    }
    else
    {
        NOTFILLERARRAY[i]='0';
    }
}
 max=0;
for (int i=0;i<num_pwds;i++)
{
    if (i==0)
    {
        max=NOTFILLERARRAY[i].size();
    }
    else
    {
        if (NOTFILLERARRAY[i].size()>max)
        {
            max=NOTFILLERARRAY[i].size();
        }
    }
}

int because;
for (int i=0;i<num_pwds;i++)
{
    if (NOTFILLERARRAY[i].size()==max)
    {
        because=i;
        break;
    }
}
return because;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////