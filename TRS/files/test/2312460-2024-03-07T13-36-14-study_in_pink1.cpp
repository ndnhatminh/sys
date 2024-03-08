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
void kt(int & exp1, int & exp2)
{
    if (exp1<0) exp1=0;
    if (exp1>600) exp1=600;
    if (exp2<0) exp2=0;
    if (exp2>600) exp2=600;
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1<0||e1>99) return -99;
    kt(exp1,exp2);
    if (e1>=0&&e1<=3)
    {
        if (e1==0)
            exp2=exp2+29;
            kt(exp1,exp2);
        if (e1==1)
            exp2=exp2+45;
            kt(exp1,exp2);
        if (e1==2)
            exp2=exp2+75;
            kt(exp1,exp2);
        if (e1==3)
            exp2=exp2+29+45+75;
            kt(exp1,exp2);
        int d=e1*3+exp1*7;
        if (d%2==0)
        {
            exp1=exp1+int(d/200)+(d%200>0);
            kt(exp1,exp2);
        } else
        {
            exp1=exp1-int(d/100);
            kt(exp1,exp2);
        }
    }
    if (e1>3&&e1<=99)
    {
        if (e1>=4&&e1<=19)
        {
            exp2=exp2+(e1/4+19)+(e1%4>0);
            kt(exp1,exp2);
        }
        
        if (e1>=20&&e1<=49)
        {
            exp2=exp2+(e1/9+21)+(e1%9>0);
            kt(exp1,exp2);        
        }
        
        if (e1>=50&&e1<=65)
        {
            exp2=exp2+(e1/16+17)+(e1%16>0);
            kt(exp1,exp2);
        }
        
        if (e1>=66&&e1<=79)
        {
            exp2=exp2+(e1/4+19)+(e1%4>0);
            kt(exp1,exp2);
            if (exp2>200)  { exp2=exp2+(e1/9+21)+(e1%9>0);
            kt(exp1,exp2); }
        }
        
        if (e1>=80&&e1<=99)
        {
            exp2=exp2+(e1/4+19)+(e1%4>0);
            kt(exp1,exp2);
            exp2=exp2+(e1/9+21)+(e1%9>0);
            kt(exp1,exp2);
            if (exp2>400)  
            {
                exp2=exp2+(e1/16+17)+(e1%16>0);
                kt(exp1,exp2);
                exp2=exp2*1.15+0.999;
                kt(exp1,exp2);
                
            }
            kt(exp1,exp2);

        }
        exp1=exp1-e1;
        kt(exp1,exp2);
    }
    return exp1 + exp2;
}

// Task 2

void kte(int & EXP1)
{
    if (EXP1<0) EXP1=0;
    if (EXP1>600) EXP1=600;
}
void kth(int & HP1)
{
    if (HP1<0) HP1=0;
    if (HP1>666) HP1=666;
}
void ktm(int & M1)
{
    if (M1<0) M1=0;
    if (M1>3000) M1=3000;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2<0||E2>99) return -99;
    //TH1
    kte(EXP1);
    kth(HP1);
    ktm(M1);
    int m=sqrt(EXP1);
    double s1,s2,s3,t1,t2,t3;
    s1=(m-1)*(m-1);
    s2=m*m;
    s3=(m+1)*(m+1);
    t1=abs(EXP1-s1);
    t2=abs(EXP1-s2);
    t3=abs(EXP1-s3);
    int res=min(t1,min(t2,t3));
    double p1,p2,p3,pp;
    p1=0; p2=0;p3=0;
    if (t1==res)
    {
        if (EXP1>=s1) p1=100;
        else p1=(EXP1/s1+80)/123.0;
    }
    else
    if (t2==res)
    {
        if (EXP1>=s2) p1=100;
        else p1=(EXP1/s2+80)/123.0;
    }
    else
    if (t3==res)
    {
        if (EXP1>=s3) p1=100;
        else p1=(EXP1/s3+80)/123.0;
    }
    //TH2
    if (E2%2==1)
    {
        int n=M1*0.5;
        int t=0;
        while (t<=n&&M1>0)
        {
            if (HP1<200)
            {
                HP1=HP1*1.3+0.999;
                kth(HP1);
                t=t+150;
                if (t>n) break;
            } else
            {
                HP1=HP1*1.1+0.999;
                kth(HP1);
                t=t+70;
                if (t>n) break;
            }
            if (EXP1<400)
            {
                t=t+200;
                EXP1=EXP1*1.13+0.999;
                kte(EXP1);
                if (t>n) break;
            } else
            {
                t=t+120;
                EXP1=EXP1*1.13+0.999;
                kte(EXP1);
                if (t>n) break;
            }
            if (EXP1<300)
            {
                t=t+100;
                EXP1=EXP1*0.9+0.999;
                kte(EXP1);
                if (t>n) break;
            }
            else 
            {
                t=t+120;
                EXP1=EXP1*0.9+0.999;
                kte(EXP1);
                if (t>n) break;
            }
        }
        HP1=HP1*0.83+0.999;
        kth(HP1);
        EXP1=EXP1*1.17+0.999;
        kte(EXP1);
        M1=M1-t;
        ktm(M1);
    }
    else
    {
        int t=0;
        if (M1>0)
        {
            if (HP1<200)
            {
                HP1=HP1*1.3+0.999;
                kth(HP1);
                //t=t+150;
                M1=M1-150;
                ktm(M1);
                if (M1<=0) M1=0;
            } else
            {
                HP1=HP1*1.1+0.999;
                kth(HP1);
                //t=t+70;
                M1=M1-70;
                ktm(M1);
                if (M1<=0) M1=0;   
            }
        }
        if (M1>0)
        {
            if (EXP1<400)
            {
                //t=t+200;
                M1=M1-200;
                ktm(M1);
                EXP1=EXP1*1.13+0.999;
                kte(EXP1);
                if (M1<=0) M1=0;
            } else
            {
                //t=t+120;
                M1=M1-120;
                ktm(M1);
                EXP1=EXP1*1.13+0.999;
                kte(EXP1);
                if (M1<=0) M1=0;
            }
        }
        if (M1>0)
        {
            if (EXP1<300)
            {
               // t=t+100;
               M1=M1-100;
               ktm(M1);
                EXP1=EXP1*0.9+0.999;
                kte(EXP1);
                if (M1<=0) M1=0;
            }
            else 
            {
               // t=t+120;
               M1=M1-120;
               ktm(M1);
                EXP1=EXP1*0.9+0.999;
                kte(EXP1);
                if (M1<=0) M1=0;
            }
        }
        HP1=HP1*0.83+0.999;
        kth(HP1);
        EXP1=EXP1*1.17+0.999;
        kte(EXP1);
    }

    m=sqrt(EXP1);
    //double s1,s2,s3,t1,t2,t3;
    s1=(m-1)*(m-1);
    s2=m*m;
    s3=(m+1)*(m+1);
    t1=abs(EXP1-s1);
    t2=abs(EXP1-s2);
    t3=abs(EXP1-s3);
    res=min(t1,min(t2,t3));
    //double p1,p2,p3;
    //p1=0; p2=0;p3=0;
    if (t1==res)
    {
        if (EXP1>=s1) p2=100;
        else p2=(EXP1/s1+80)/123.0;
    }
    else
    if (t2==res)
    {
        if (EXP1>=s2) p2=100;
        else p2=(EXP1/s2+80)/123.0;
    }
    else
    if (t3==res)
    {
        if (EXP1>=s3) p2=100;
        else p2=(EXP1/s3+80)/123.0;
    }
    // TH3
    int a[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2<10)
    {
        p3=a[E2];
    } else
    {
        int x=E2/10;
        int y=E2%10;
        int z=x+y;
        int kq=z%10;
        p3=a[kq];
    }
    // all
    if (p1<1) p1=p1*100;
    if (p2<1) p2=p2*100;
    if (p1==100&&p2==100&&p3==100)
    {
        EXP1=EXP1*0.75+0.999;
        kte(EXP1);
    } else
    {
        pp=(p1+p2+p3)/3.0;
        if (pp<50.0)
        {
            HP1=HP1*0.85+0.999;
            kth(HP1);
            EXP1=EXP1*1.15+0.999;
            kte(EXP1);
        } else
        {
            HP1=HP1*0.9+0.999;
            kth(HP1);
            EXP1=EXP1*1.2+0.999;
            kte(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
void ktee(int & EXP1,int & EXP2)
{

    if (EXP1<0) EXP1=0;
    if (EXP1>600) EXP1=600;
    if (EXP2<0) EXP2=0;
    if (EXP2>600) EXP2=600;

}
void kthh(int & HP1, int & HP2)
{
    if (HP1<0) HP1=0;
    if (HP1>666) HP1=666;
    if (HP2<0) HP2=0;
    if (HP2>666) HP2=666;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    if (E3<0||E3>99) return -99;
    ktee(EXP1,EXP2);
    kthh(HP1,HP2);
    int a[20][20];
    //cin>>HP1>>EXP1>>HP2>>EXP2>>E3;
    for (int i=0; i<=9; i++)
        for (int j=0; j<=9; j++)
    a[i][j]=((E3*j)+(i*2))*(i-j);
   /* for (int i=0; i<=9; i++)
    {
        for (int j=0; j<=9;j++)
            cout<<setw(5)<<a[i][j]<<" ";
        cout<<endl;
    }*/
    int h,c; h=0; c=0;
    for (int i=0; i<=9; i++)
    {
        for (int j=0; j<=9; j++)
        {
            if (a[i][j]>(E3*2)) h++;
            if (a[i][j]<(-E3)) c++;
        }
    }
    int dv,dd;
    while (h>=10)
    {
        dv=h%10;
        dd=h/10;
        h=dv+dd;
    }
    while (c>=10)
    {
        dv=c%10;
        dd=c/10;
        c=dd+dv;
    }
    int res=a[h][c];
    int i,j;
    i=h; j=c;
    while (i>=0&&j>=0)
    {
        res=max(res,a[i][j]);
        i--;
        j--;
    }
    i=h; j=c;
    while (i>=0&&j<=9)
    {
        res=max(res,a[i][j]);
        i--;
        j++;
    }
    i=h; j=c;
    while (i<=9&&j>=0)
    {
        res=max(res,a[i][j]);
        i++;
        j--;
    }
    i=h; j=c;
    while (i<=9&&j<=9)
    {
        res=max(res,a[i][j]);
        i++;
        j++;
    }
    int ans=abs(a[h][c]);
    int dap=0;
    if (ans>res)
    {
        EXP1=EXP1*0.88+0.999;
        EXP2=EXP2*0.88+0.999;
        ktee(EXP1,EXP2);
        HP1=HP1*0.9+0.999;
        HP2=HP2*0.9+0.999;
        kthh(HP1,HP2);
        dap=a[h][c];

    } else
    {
        EXP1=EXP1*1.12+0.999;
        EXP2=EXP2*1.12+0.999;
        ktee(EXP1,EXP2);
        HP1=HP1*1.1+0.999;
        HP2=HP2*1.1+0.999;
        kthh(HP1,HP2);
        dap=res;
    }
/*

    cout<<EXP1<< " " << EXP2<<endl;
    cout<<HP1<< " " << HP2<<endl;
    cout<<h<< " " << c<<endl;
    cout<<res<<endl;
    cout<<dap<<endl; */
     return dap;


    //return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function


  // TODO: Complete this function
    string mk=s;
    string ss=email;
    string st="";
    for (int i=0; i<ss.size(); i++)
    {
        if (ss[i]=='@') break;
        else st=st+ss[i];
    }
    int n=mk.size();
    int kt=0;
    int co=0; int vtsp=0;
    int ktse=0;
    int vtse=0;
    int vtgn=0; int ktgn=0;
    if (n>=8&&n<=20)
    {
        for (int i=0; i<n;i++)
        {
            int m=mk[i]; int tt=0;
            if ((m>=65&&m<=90)||(m>=97&&m<=122)||(m>=48&&m<=57))
            {
                tt=1;
            } else
            if (mk[i]=='@'||mk[i]=='#'||mk[i]=='%'||mk[i]=='!'||mk[i]=='$')
            {
                co++;
            } else
            {
                if (kt==0) vtsp=i;
                kt=1;
            }
        }
        if(mk.find(st) == string::npos)
        {
            ktse=0;
        }
        else
        {
            ktse=1;
            vtse=mk.find(st);
        }
        //giong nhau
        int x=0; int y=1; int z=2;
        while (z<=n-1)
        {
            if (mk[x]==mk[y]&&mk[y]==mk[z])
            {
                vtgn=x;
                ktgn=1;
                break;
            }
            x++; y++; z++;
        }
        if (kt==0&&co>=1&&ktse==0&ktgn==0) return -10;
    }
    if (n<8) return -1;
    if (n>20) return -2;
    if (ktse==1) return -(300+vtse);
    if (ktgn==1) return -(400+vtgn);
    if (co==0) return -5;
    return vtsp;

}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    // TODO: Complete this function
    int m=0; int ln=0; int ans=0;
    /*for (int i=i; i<num_pwds; i++)
        cout<<arr_pwds[i];
    */ for (int i=0; i<num_pwds; i++)
    {
        int d=0; string ss=arr_pwds[i];
        //cout<<ss<<endl;
        for (int j=0; j<num_pwds; j++)
        {
            string sa=arr_pwds[j];
            if (ss==sa)
            d++;
        }
        if (m<=d)
        {
            if (m==d&&ln<ss.size()) ln=ss.size();
            if (m<d)
            {
                m=d;
                ln=ss.size();
            }
        }
    }
    for (int i=0; i<num_pwds; i++)
    {
        int d=0; string ss=arr_pwds[i];
        for (int j=0; j<num_pwds; j++)
         {
            string sa=arr_pwds[j];
            if (ss==sa)
            d++;
         }
        if ((m==d)&&(ss.size()==ln))
        {
            ans=i;
            return i;
            break;
        }

    }
    return ans;


}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////