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
void ckEXP1(int & EXP1)
{
    if (EXP1<0)     EXP1=0;
    if (EXP1>600)   EXP1=600;
}
void ckEXP2(int & EXP2)
{
    if (EXP2<0)     EXP2=0;
    if (EXP2>600)   EXP2=600;
}
void ckHP1(int & HP1)
{
    if (HP1<0)     HP1=0;
    if (HP1>666)   HP1=666;
}
void ckHP2(int & HP2)
{
    if (HP2<0)     HP2=0;
    if (HP2>666)   HP2=666;
}
void ckM1(int & M1)
{
    if (M1<0)      M1=0;
    if (M1>3000)   M1=3000;
}
void ckM2(int & M2)
{
    if (M2<0)      M2=0;
    if (M2>3000)   M2=3000;
}
int firstMeet(int &EXP1, int &EXP2, int E1)
{
    if (E1 < 0 || E1 > 99) return -99;
    
    ckEXP1(EXP1);
    ckEXP2(EXP2);
    
    if (E1>=0 && E1<=3)
    {
        if (E1==0) EXP2+=29;
        else if (E1==1) EXP2+=45;
        else if (E1==2) EXP2+=75;
        else EXP2=EXP2+29+45+75;

        int D=E1*3+EXP1*7;
        if (D%2==0) EXP1=ceil(EXP1+(D/200.0));
        else EXP1=ceil(EXP1-(D/100.0));

        ckEXP1(EXP1);
        ckEXP2(EXP2);
    }
    else
    {
        if (E1<=19)
        {
            EXP2=ceil(EXP2+(E1/4.0+19));
            ckEXP2(EXP2);
        }
        else if (E1<=49)
        {
            EXP2=ceil(EXP2+(E1/9.0+21));
            ckEXP2(EXP2);
        }
        else if (E1<=65)
        {
            EXP2=ceil(EXP2+(E1/16.0+17));
            ckEXP2(EXP2);
        }
        else if (E1<=79)
        {
            EXP2=ceil(EXP2+(E1/4.0+19));
            ckEXP2(EXP2);
            if (EXP2>200)
            {
                EXP2=ceil(EXP2+(E1/9.0+21));
                ckEXP2(EXP2);
            }
        }
        else
        {
            EXP2=ceil(EXP2+(E1/4.0+19));
            ckEXP2(EXP2);
            EXP2=ceil(EXP2+(E1/9.0+21));
            ckEXP2(EXP2);
            if (EXP2>400)
            {
                EXP2=ceil(EXP2+(E1/16.0+17));
                ckEXP2(EXP2);
                EXP2=ceil(EXP2*1.15);
            }
        }
        EXP1-=E1;
        ckEXP1(EXP1);
        ckEXP2(EXP2);
    }
    return EXP1 + EXP2;
}
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (E2 < 0 || E2 > 99) return -99;
    
    ckEXP1(EXP1);
    ckHP1(HP1);
    ckM1(M1);

    double P1, P2, P3;
    
    //Con duong 1
    int n;
    int S, a, b, c, d, i;
    i=0;
    n=sqrt(EXP1);
    if (n*n==EXP1) S=EXP1;
    else while(true)
    {
        i+=1;
        a=EXP1-i;
        b=EXP1+i;
        c=sqrt(a);
        d=sqrt(b);
        if (c*c==a){
            S=a;
            break;
        }
        if (d*d==b){
            S=b;
            break;
        }
    }
    if (EXP1>=S) P1=100;
    else P1=((EXP1*1.0/S+80)/123.0)*100;

    //Con duong 2
    if (E2%2==0)
    {
        if (M1>0)
        {
            // Su kien 1
            if (HP1<200)
            {
                HP1=ceil(HP1*13.0/10);
                ckHP1(HP1);
                M1-=150;
                ckM1(M1);
            }
            else
            {
                HP1=ceil(HP1*11.0/10);
                ckHP1(HP1);
                M1-=70;
                ckM1(M1);
            }
        }
        if (M1>0)
        {
            // Su kien 2
            if (EXP1<400)
            {
                M1-=200;
                ckM1(M1);
                EXP1=ceil(EXP1*113.0/100);
                ckEXP1(EXP1);
            }
            else
            {
                M1-=120;
                ckM1(M1);
                EXP1=ceil(EXP1*113.0/100);
                ckEXP1(EXP1);
            }
        }
        if (M1>0)
        {
            // Su kien 3
            if (EXP1<300)
            {
                M1-=100;
                ckM1(M1);
                EXP1=ceil(EXP1*9.0/10);
                ckEXP1;
            }
            else
            {
                M1-=120;
                ckM1(M1);
                EXP1=ceil(EXP1*9.0/10);
                ckEXP1;
            }
        }
    }
    else
    {
        double tientra, tiendau;
        tiendau=M1;
        tientra=0;
        
        while(true)
        {
            if (M1<=0) break;
            //Su kien 1
            if (HP1<200)
            {
                HP1=ceil(HP1*13.0/10);
                ckHP1(HP1);
                M1-=150;
                ckM1(M1);
                tientra+=150;
            }
            else
            {
                HP1=ceil(HP1*11.0/10);
                ckHP1(HP1);
                M1-=70;
                ckM1(M1);
                tientra+=70;
            }
            if (tientra>tiendau/2.0) {break;}
            //Su kien 2
            if (EXP1<400)
            {
                M1-=200;
                ckM1(M1);
                tientra+=200;
                EXP1=ceil(EXP1*113.0/100);
                ckEXP1(EXP1);
            }
            else
            {
                M1-=120;
                ckM1(M1);
                tientra+=120;
                EXP1=ceil(EXP1*113.0/100);
                ckEXP1(EXP1);
            }
            if (tientra>tiendau/2.0) {break;}
            //Su kien 3
            if (EXP1<300)
            {
                M1-=100;
                ckM1(M1);
                tientra+=100;
                EXP1=ceil(EXP1*9.0/10);
                ckEXP1(EXP1);
            }
            else
            {
                M1-=120;
                ckM1(M1);
                tientra+=120;
                EXP1=ceil(EXP1*9.0/10);
                ckEXP1(EXP1);
            }
            if (tientra>tiendau/2.0) {break;}
        }
    }
    EXP1=ceil(EXP1*117.0/100);
    ckEXP1(EXP1);
    HP1=ceil(HP1*83.0/100);
    ckHP1(HP1);
    
    int n1;
    int S1, a1, b1, c1, d1, i1;
    i1=0;
    n1=sqrt(EXP1);
    if (n1*n1==EXP1) S1=EXP1;
    else while(true)
    {
        i1+=1;
        a1=EXP1-i1;
        b1=EXP1+i1;
        c1=sqrt(a1);
        d1=sqrt(b1);
        if (c1*c1==a1){
            S1=a1;
            break;
        }
        if (d1*d1==b1){
            S1=b1;
            break;
        }
    }
    if (EXP1>=S1) P2=100;
    else P2=((EXP1*1.0/S+80)/123.0)*100;

    //Con duong 3
    int P[10]{32,47,28,79,100,50,22,83,64,11};
    
    int t,s,k;
        t=E2/10;
        s=E2%10;
        k=(t+s)%10;
    
    if (E2<=9) P3=P[E2];
    else P3=P[k];

    //Tong ket
    double ava;
    ava=(P1+P2+P3)/3.0;

    if (ava==100)
    {
        EXP1=ceil(EXP1*75.0/100);
        ckEXP1(EXP1);
    }
    if (ava<50)
    {
        HP1=ceil(HP1*85.0/100);
        ckHP1(HP1);
        EXP1=ceil(EXP1*115.0/100);
        ckEXP1(EXP1);
    }
    if (ava>=50 && ava!=100)
    {
        HP1=ceil(HP1*9.0/10);
        ckHP1(HP1);
        EXP1=ceil(EXP1*12.0/10);
        ckEXP1(EXP1);
    }
    return HP1 + EXP1 + M1;
}
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3<0 || E3>99) return -99;
    
    ckEXP1(EXP1);
    ckEXP2(EXP2);
    ckHP1(HP1);
    ckHP2(HP2);

    int mang[10][10];
    int lon=0;
    int be=0;
    int x;
    int y;
    int diem;
    int diemtaxi;
    for (int i=0;i<=9;i++)
    {
        for (int j=0;j<=9;j++)
        {
            mang[i][j]=((E3*j)+(i*2))*(i-j);
            if (mang[i][j]>2*E3) lon+=1;
            if (mang[i][j]<(E3*(-1))) be+=1;
        }
    }
    //Vi tri gap nhau
    int a,b,c,d,e;
    if (lon<10) x=lon;
    if (lon>=10)
    {
        a=lon/10;
        b=lon%10;
        c=a+b;
        if (c>=10)
        {
            d=c/10;
            e=c%10;
            c=d+e;
        }
        x=c;
    }
    int a1,b1,c1,d1,e1;
    if (be<10) y=be;
    if (be>=10)
    {
        a1=be/10;
        b1=be%10;
        c1=a1+b1;
        if (c1>=10)
        {
            d1=c1/10;
            e1=c1%10;
            c1=d1+e1;
        }
        y=c1;
    }
    //Tinh diem lon nhat
    int k=x;
    int l=y;
    diem=mang[x][y];
    diemtaxi=mang[x][y];
    while (true)
    {
        k-=1;
        l-=1;
        if (k<0||k>9) break;
        if (l<0||l>9) break;
        if (mang[k][l]>diem) diem=mang[k][l];
    }
    k=x;
    l=y;
    while (true)
    {
        k+=1;
        l-=1;
        if (k<0||k>9) break;
        if (l<0||l>9) break;
        if (mang[k][l]>diem) diem=mang[k][l];
    }
    k=x;
    l=y;
    while (true)
    {
        k+=1;
        l+=1;
        if (k<0||k>9) break;
        if (l<0||l>9) break;
        if (mang[k][l]>diem) diem=mang[k][l];
    }
    k=x;
    l=y;
    while (true)
    {
        k-=1;
        l+=1;
        if (k<0||k>9) break;
        if (l<0||l>9) break;
        if (mang[k][l]>diem) diem=mang[k][l];
    }
    diem=abs(diem);
    if (abs(diemtaxi)>diem)
    {
        EXP1=ceil(EXP1*88.0/100);
        HP1=ceil(HP1*9.0/10);
        EXP2=ceil(EXP2*88.0/100);
        HP2=ceil(HP2*9.0/10);
        ckEXP1(EXP1);
        ckEXP2(EXP2);
        ckHP1(HP1);
        ckHP2(HP2);
        return diemtaxi;
    }
    else
    {
        EXP1=ceil(EXP1*112.0/100);
        HP1=ceil(HP1*11.0/10);
        EXP2=ceil(EXP2*112.0/100);
        HP2=ceil(HP2*11.0/10);
        ckEXP1(EXP1);
        ckEXP2(EXP2);
        ckHP1(HP1);
        ckHP2(HP2);
        return diem;
    }
}
int checkPassword(const char *s, const char *email)
{
    char* se = new char [101];
    int a;
    for (int i=0;i<=strlen(email)-1;i++)
    {
        a=i;
        if (email[i]=='@') break;
        se[i]=email[i];
    }
    se[a]='\0';
    if (strlen(s)<8) return -1;
    if (strlen(s)>20) return -2;
    const char* trung=strstr(s,se);
    if (trung != nullptr) return -(300+(trung-s));
    for (int i=0;i<=strlen(s)-2;i++)
    {
        if (s[i]==s[i+1] && s[i]==s[i+2]) return -(400+i);
    }
    int dem=0;
    for (int i=0;i<=strlen(s)-1;i++)
    {
        if (s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!') dem+=1;
    }
    if (dem==0) return -5;
    char ki_tu_dac_biet[28]{32,34,38,39,40,41,42,43,44,45,46,47,58,59,60,61,62,63,91,92,93,94,95,96,123,124,125,126};
    for (int i=0;i<=strlen(s)-1;i++)
    {
        if (s[i]<32 || s[i]>127) {return i;}
        else for (int k=0;k<=27;k++)
        {
            if (s[i]==ki_tu_dac_biet[k]) {return i;}
        }
    }
    return -10;
}

int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int tansuat[num_pwds];
    int dai[num_pwds];
    int a;
    for (int i=0;i<=num_pwds-1;i++)
    {
        tansuat[i]=0;
    }
    for (int i=0;i<=num_pwds-1;i++)
    {
        for (int j=0;j<=num_pwds-1;j++)
        {
            if (strcmp(arr_pwds[i],arr_pwds[j])==0) tansuat[i]+=1;
        }
        dai[i]=(strlen(arr_pwds[i]));
    }
    int max=0;
    for (int i=0;i<=num_pwds-1;i++)
    {
        if (tansuat[i]>max) max=tansuat[i];
    }
    int maxdai=0;
    for (int i=0;i<=num_pwds-1;i++)
    {
        if (tansuat[i]==max)
        {
            if (dai[i]>maxdai) maxdai=dai[i];
        }
    }
    for (int i=0;i<=num_pwds-1;i++)
    {
        if (tansuat[i]==max && dai[i]==maxdai)
        {
            a=i;
            break;
        }
    }
    return a;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////