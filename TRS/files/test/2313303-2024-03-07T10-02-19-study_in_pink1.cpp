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

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1<0||e1>99)
    return -99;
    if (exp1 >600)
    {
        exp1 =600;
    }
    if (exp1 <0)
    {
        exp1 =0;
    }
    if (exp2 > 600)
    {
        exp2 = 600;
    }
     if (exp2 < 0)
    {
        exp2 = 0;
    }
    if ( e1<=3 && e1>=0)
    {
        if (e1==0)
        {
            exp2 += 29;
        }
        if (e1==1)
        {
            exp2 += 45;
        }
        if (e1==2)
        {
            exp2 += 75;
        }
        if (e1==3)
        {
            exp2 += 29+45+75;
        }
        int D=e1*3 + exp1*7;
        if (D%2==0)
        {
            exp1 += ceil((double)D/200);
        }
        else
        {
            exp1 += ceil(-(double)D/100);
        }    
    }
    if ((e1>=4) && (e1<=99))
    {
        if ((e1>=4) && (e1<=19))
        {
            exp2 += ceil(((double)e1/4 + 19));
        }
        else if ((e1>=20) && (e1<=49))
        {
            exp2 += ceil(((double)e1/9 + 21));
        }
        else if ((e1>=50) && (e1<=65))
        {
        exp2 += ceil(((double)e1/16 + 17));

        }
        else if ((e1>=66) && (e1<=79))
        {
            exp2 += ceil(((double)e1/4 + 19));
            if (exp2 >200)
                exp2 += ceil(((double)e1/9 + 21));
        }
        else if ((e1>=80) && (e1<=99))
        {
            exp2 += ceil(((double)e1/4 + 19));
            exp2 += ceil(((double)e1/9 + 21));
            if (exp2 > 400)
            {
            exp2 +=ceil(((double)e1/16 + 17));
            exp2 = ceil((double)exp2*1.15);
            }
        }
        exp1 -=e1;
        

    }

    if (exp1 >600)
    {
        exp1 =600;
    }
    if (exp1 <0)
    {
        exp1 =0;
    }
    if (exp2 > 600)
    {
        exp2 = 600;
    }
     if (exp2 < 0)
    {
        exp2 = 0;
    }
    return exp1 + exp2;
    
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    
    if (E2<0||E2>99)
    return -99;
    if (EXP1>600)
    {
        EXP1=600;
    }
    if (EXP1<0)
    {
        EXP1=0;
    }
    if (HP1>666)
    {
        HP1=666;
    }
    if (HP1<0)
    {
        HP1=0;
    }
    if (M1>3000)
    {
        M1=3000;
    }
    if (M1<0)
    {
        M1=0;
    }
    int s1,s2,s3,s11,s12,s21,s22,s31,s32,sE2,a,b;
    double p,p1,p2,p3;
    s11=floor((double)sqrt(EXP1))*floor((double)sqrt(EXP1));
    s12=ceil((double)sqrt(EXP1))*ceil((double)sqrt(EXP1));
    if (abs(EXP1-s11)>abs(EXP1-s12))
    {
        s1=s12;
    }
    else 
    {
        s1=s11;
    }
    if (EXP1>=s1)
    p1=100;
    else
    p1=(((double)EXP1/s1 + 80)/123)*100;
    double k=0.5*M1;
    double K=ceil(k);
    int tM=0;
    if (E2%2==1)
    {
        while (tM<=K)
        {
            if (M1==0)
            {
                break;
            }
            if (HP1<200 )
            {
                HP1= ceil(HP1+0.3*HP1);
                tM+=150;
                M1-=150;
                if (tM>K)
                {
                    break;
                }
            }
            else if (HP1>=200)
            {
                HP1=ceil(HP1+0.1*HP1);
                tM+=70;
                M1-=70;
                cout<<HP1<<" ";
                if (HP1>666)
                {
                    HP1=666;
                }
                if (tM>K)
                {
                    break;
                }
            }
            if (EXP1<400 )
            {
                EXP1=ceil(EXP1 + 0.13*EXP1);
                M1-=200;
                tM+=200;
                if (tM>K)
                {
                    break;
                }
            }

            else if (EXP1>=400)
            {
                EXP1=ceil(EXP1 + 0.13*EXP1);
                M1-=120;
                tM+=120;
                if (EXP1>600)
                {
                    EXP1=600;
                }
                if (tM>K)
                {
                    break;
                }
            }
            if (EXP1<300)
            {
                M1-=100;
                tM+=100;
                EXP1=ceil(EXP1 - EXP1*0.1);
                if (tM>K)
                {
                    break;
                }
            }
            else 
            {
                M1-=120;
                tM+=120;
                EXP1=ceil(EXP1 - EXP1*0.1);
                if (tM>K)
                {
                    break;
                }
            }
        }
        HP1=ceil(HP1 - 0.17*HP1);
        EXP1=ceil(EXP1 + 0.17*EXP1);
        if (EXP1>600)
        {
            EXP1=600;
        }
    }
    if (E2%2==0)
    {
        if (M1>0)
        {
            if (HP1<200  )
            {
                HP1= ceil(HP1+0.3*HP1);
                tM+=150;
                M1-=150;
            }
            else if (HP1>=200)
            {
                HP1=ceil(HP1+0.1*HP1);
                tM+=70;
                M1-=70;
            }
            if (EXP1<400 && M1>0 )
            {
                EXP1=ceil(EXP1 + 0.13*EXP1);
                M1-=200;
                tM+=200;
            }

            else if (EXP1>=400 && M1>0 )
            {
                EXP1=ceil(EXP1 + 0.13*EXP1);
                M1-=120;
                tM+=120;
            }
            if (EXP1<300 && M1>0 )
            {
                M1-=100;
                tM+=100;
                EXP1=ceil(EXP1 - EXP1*0.1);
            }
            else if (EXP1>=300&& M1>0 )
            {
                M1-=120;
                tM+=120;
                EXP1=ceil(EXP1 - EXP1*0.1);
            }
        }
    if (EXP1>600)
    {
        EXP1=600;
    }
    if (EXP1<0)
    {
        EXP1=0;
    }
    if (HP1>666)
    {
        HP1=666;
    }
    if (HP1<0)
    {
        HP1=0;
    }
    if (M1>3000)
    {
        M1=3000;
    }
    if (M1<0)
    {
        M1=0;
    }
        HP1=ceil(HP1 - 0.17*HP1);
        EXP1=ceil(EXP1 + 0.17*EXP1);
        if (EXP1>600)
        {
            EXP1=600;
        }
    }
    
    s21=floor((double)sqrt(EXP1))*floor((double)sqrt(EXP1));
    s22=ceil((double)sqrt(EXP1))*ceil((double)sqrt(EXP1));
    if (abs(EXP1-s21)>abs(EXP1-s22))
    {
        s2=s22;
    }
    else 
    {
        s2=s21;
    }
    if (EXP1>=s2)
    p2=100;
    else
    p2=(((double)EXP1/s2 + 80)/123)*100;
    int ar[10]={32,47,28,79,100,50,22,83,64,11};
    if (E2<10)
    {
        p3=ar[E2];
    } 
    else 
    {
        a=E2%10+floor(E2/10);
        if (a>=10)
        {
            a%=10;
        }
        p3=ar[a];
    }
    if ((p1==100) && (p2==100) && (p3==100))
    {
        EXP1=ceil(double(EXP1)*0.75);
    }
    p=(p1+p2+p3)/3;

    if (p<50)
    {
        HP1=ceil(double(HP1)*0.85);
        EXP1=ceil(double(EXP1)*1.15);
    }
    if (p>=50&&p<100)
    {
        HP1=ceil(double(HP1)*0.9);
        EXP1=ceil(double(EXP1)*1.2);
    }
    if (EXP1>600)
    {
        EXP1=600;
    }
    if (EXP1<0)
    {
        EXP1=0;
    }
    if (HP1>666)
    {
        HP1=666;
    }
    if (HP1<0)
    {
        HP1=0;
    }
    if (M1>3000)
    {
        M1=3000;
    }
    if (M1<0)
    {
        M1=0;
    }



    return HP1 + EXP1 + M1;

}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3<0||E3>99)
    return -99;
    if (EXP1>600)
    {
        EXP1=600;
    }
    if (EXP1<0)
    {
        EXP1=0;
    }
    if (EXP2>600)
    {
        EXP2=600;
    }
    if (EXP2<0)
    {
        EXP2=0;
    }
    if (HP1>666)
    {
        HP1=666;
    }
    if (HP1<0)
    {
        HP1=0;
    }
    if (HP2>666)
    {
        HP2=666;
    }
    if (HP2<0)
    {
        HP2=0;
    }
    int matrix[10][10];
    int E32 = 2*E3;
    int E33 = 0-E3;
    int x=0,y=0,pointi,pointj;
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            matrix [i][j]=((E3*j) + (i*2)) * (i - j);
            if (matrix [i][j]>E32)
            {
                x+=1;
            }
            if (matrix [i][j]<E33)
            {
                y+=1;
            }
        }
    }
    pointi = x;
    pointj = y;
    while (pointi>=10)
    {
        pointi=pointi%10+floor(pointi/10);
    }
    while (pointj>=10)
    {
        pointj=pointj%10+floor(pointj/10);
    }
    int pointtaxi = matrix[pointi][pointj];
    int a=pointi,b=pointj;
    int pointSHERLOCK1=0;
    while ((a<9)&&(b<9))
    {
        a+=1;
        b+=1;
        if (matrix [a-1][b-1]<matrix[a][b])
        {
            pointSHERLOCK1 = matrix[a][b];
        }
        else
        {
            pointSHERLOCK1 = matrix[a-1][b-1];
        }
    }
    int c=pointi,d=pointj;
    int pointSHERLOCK2=0;
    while ((c>0)&&(d>0))
    {
        c-=1;
        d-=1;
        if (matrix [c][d]<matrix[c+1][d+1])
        {
            pointSHERLOCK2 = matrix[c+1][d+1];
        }
        else
        {
            pointSHERLOCK2 = matrix[c][d];
        }
    }
    int m=pointi,n=pointj;
    int pointSHERLOCK3=0;
    while ((m>0)&&(n<9))
    {
        m-=1;
        n+=1;
        if (matrix [m][n]<matrix[m+1][n-1])
        {
            pointSHERLOCK3 = matrix[m+1][n-1];
        }
        else
        {
            pointSHERLOCK3 = matrix[m][n];
        }
    }
    int z=pointi,t=pointj;
    int pointSHERLOCK4=0;
    while ((z<9)&&(t>0))
    {
        z+=1;
        t-=1;
        if (matrix [z][t]<matrix[z-1][t+1])
        {
            pointSHERLOCK4 = matrix[z-1][t+1];
        }
        else
        {
            pointSHERLOCK4 = matrix [z][t];
        }
    }
    int pointSHERLOCK=0;
    if (pointSHERLOCK1>pointSHERLOCK2 && pointSHERLOCK1>pointSHERLOCK3 && pointSHERLOCK1>pointSHERLOCK4 )
    {
        pointSHERLOCK=pointSHERLOCK1;
    }
    if (pointSHERLOCK2>pointSHERLOCK1 && pointSHERLOCK2>pointSHERLOCK3 && pointSHERLOCK2>pointSHERLOCK4 )
    {
        pointSHERLOCK=pointSHERLOCK2;
    }
    if (pointSHERLOCK3>pointSHERLOCK1 && pointSHERLOCK3>pointSHERLOCK2 && pointSHERLOCK3>pointSHERLOCK4 )
    {
        pointSHERLOCK=pointSHERLOCK3;
    }
    if (pointSHERLOCK4>pointSHERLOCK1 && pointSHERLOCK4>pointSHERLOCK2 && pointSHERLOCK4>pointSHERLOCK3 )
    {
        pointSHERLOCK=pointSHERLOCK4;
    }
    int pointmax;
    if (abs(pointtaxi)>abs(pointSHERLOCK))
    {
        EXP1=ceil(EXP1-0.12*EXP1);
        EXP2=ceil(EXP2-0.12*EXP2);
        HP1=ceil(HP1-0.1*HP1);
        HP2=ceil(HP2-0.1*HP2);
        pointmax=pointtaxi;
    }
    else
    {
        EXP1=ceil(EXP1+EXP1*0.12);
        EXP2=ceil(EXP2+EXP2*0.12);
        HP1=ceil(HP1+HP1*0.1);
        HP2=ceil(HP2+HP2*0.1);
        pointmax=pointSHERLOCK;
    }
    if (EXP1>600)
    {
        EXP1=600;
    }
    if (EXP1<0)
    {
        EXP1=0;
    }
    if (EXP2>600)
    {
        EXP2=600;
    }
    if (EXP2<0)
    {
        EXP2=0;
    }
    if (HP1>666)
    {
        HP1=666;
    }
    if (HP1<0)
    {
        HP1=0;
    }
    if (HP2>666)
    {
        HP2=666;
    }
    if (HP2<0)
    {
        HP2=0;
    }
    return pointmax;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string email1=email;
    string se;
    for (int i=0;i < email1.length();i++)
    {
        if (email1[i]=='@')
        {
            break;
        }
        else 
        {
            se+=email1[i];
        }     
    }
    string s1=s;
    int n=0,m=0,l;
    if (s1.length()<8)
    {
        return -1;
    }
    if (s1.length()>20)
    {
        return -2;
    }
    if (s1.find(se)<=s1.length() & s1.find(se)>=0)
    {
        return -(300+s1.find(se));
    }
    for (int k=0;k < (s1.length()-2);k++)
    {
        if ((s1[k]==s1[k+1]) && (s1[k+1]==s1[k+2]))
        {
            m=k;
            return  -(400+m);
            break;
        }
    }
    for (int j=0;j < s1.length();j++)
    {
        if (s1[j]=='@'||s1[j]=='#'||s1[j]=='%'||s1[j]=='$'||s1[j]=='!')
        {
            n+=1;
        }     
    }
    if (n==0)
    {
        return -5;
    }
    for (int h=0;h < s1.length();h++)
    {
        if (((s1[h]>='a') && (s1[h]<='z')) || ((s1[h]>='A') && (s1[h]<='Z')) || ((s1[h]>='0') && (s1[h]<='9'))||(s1[h]=='@')||(s1[h]=='#')||(s1[h]=='%')||(s1[h]=='$')||(s1[h]=='!'))
        {}
        else 
        {
            l=h;
            return l;
            break;
        }
    }
 
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
  int result = 0;
    int samePassword[num_pwds]={};
    int length[num_pwds]={};
    int samePasswordmax=0;
    for (int k=0;k<num_pwds;k++)
    {
        samePassword[k]=1;
    }

    for (int l=0;l<num_pwds;l++)
    {
        length[l]=0;
    }
    for (int i=0;i<(num_pwds);i++)
    {
        for (int j=i+1;j<num_pwds;j++)
        {
            if (strcmp(arr_pwds[i],arr_pwds[j])==0)
            {
                samePassword[i]+=1;
            }
        }
        string a;
        a=arr_pwds[i];
        length[i]=a.length();
    }
    for (int z=0;z<num_pwds;z++)
    {
        if (samePassword[z]>samePassword[result])
        {
            result = z;
        }
        else if (samePassword[z]==samePassword[result] && length[z]>length[result] )
        {
            result=z;
        }
    }
    return result;
}