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
    else{
        if (exp1>600)
            exp1=600;
        if (exp1<0)
            exp1=0;

        if (exp2>600)
            exp2=600;
        if (exp2<0)
            exp2=0;
        float x=exp1, y=exp2, z=e1;
        if ((e1>=0)&&(e1<=3)){
            if (e1==0){
                exp2+=29;
                if (exp2>600)
                    exp2=600;
            }
            else if (e1==1){
                exp2+=45;
                if (exp2>600)
                    exp2=600;
            }
            else if (e1==2){
                exp2+=75;
                if (exp2>600)
                    exp2=600;
            }
            else if (e1==3){
                exp2=exp2+29+45+75;
                if (exp2>600)
                    exp2=600;
            }
            int d=e1*3+exp1*7;
            double a=d;
            if ((d%2)==0){
                x=exp1+a/200;
                exp1=exp1+d/200;
                if (x>exp1)
                    exp1+=1;
                if (exp1>600)
                    exp1=600;
            }
            else if ((d%2)==1){
                x=exp1-a/100;
                exp1=exp1-d/100;
                if (x>exp1)
                    exp1+=1;
                if (exp1<0)
                    exp1=0;
            }
        }
        else if ((e1>=4)&&(e1<=99)){
            if ((e1>=4)&&(e1<=19)){
                y=exp2+z/4+19;
                exp2=exp2+e1/4+19;
                if (y>exp2)
                    exp2+=1;
                if (exp2>600)
                    exp2=600;
            }
            else if ((e1>=20)&&(e1<=49)){
                y=exp2+z/9+21;
                exp2=exp2+e1/9+21;
                if (y>exp2)
                    exp2+=1;
                if (exp2>600)
                    exp2=600;
            }
            else if ((e1>=50)&&(e1<=65)){
                y=exp2+z/16+17;
                exp2=exp2+e1/16+17;
                if (y>exp2)
                    exp2+=1;
                if (exp2>600)
                    exp2=600;
            }
            else if ((e1>=66)&&(e1<=79)){
                y=exp2+z/4+19;
                exp2=exp2+e1/4+19;
                if (y>exp2)
                    exp2+=1;
                if (exp2>600)
                    exp2=600;
                if (exp2>200){
                    y=exp2+z/9+21;
                    exp2=exp2+e1/9+21;
                    if (y>exp2)
                        exp2+=1;
                    if (exp2>600)
                        exp2=600;
                    if (exp2<0)
                        exp2=0;
                }
            }
            else if ((e1>=80)&&(e1<=99)){
                y=exp2+z/4+19;
                exp2=exp2+e1/4+19;
                if (y>exp2)
                    exp2+=1;
                if (exp2>600)
                    exp2=600;
                if (exp2<0)
                    exp2=0;
                y=exp2+z/9+21;
                exp2=exp2+e1/9+21;
                if (y>exp2)
                    exp2+=1;
                if (exp2>600)
                    exp2=600;
                if (exp2<0)
                    exp2=0;
                if (exp2>400){
                    y=exp2+z/16+17;
                    exp2=exp2+e1/16+17;
                    if (y>exp2)
                        exp2+=1;
                    if (exp2>600)
                        exp2=600;
                    if (exp2<0)
                        exp2=0;
                    y=exp2*1.15;
                    exp2=exp2*115/100;
                    if (y>exp2)
                        exp2+=1;
                    if (exp2>600)
                        exp2=600;
                    if (exp2<0)
                        exp2=0;
                }
            }
            exp1=exp1-e1;
            if (exp1<0)
                exp1=0;

        }
        return exp1 + exp2;
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2<0||E2>99)
        return -99;
    else{
        float x=HP1, y=EXP1;
        if (EXP1>600)
            EXP1=600;
        if (EXP1<0)
            EXP1=0;

        if (HP1>666)
            HP1=666;
        if (HP1<0)
            HP1=0;

        if (M1>3000)
            M1=3000;
        if (M1<0)
            M1=0;
        double p, p1, p2, p3, h1, h2;
        for (int i=1;i<=3;i++){
            if (i==1){
                int f1=sqrt(EXP1);
                double s1=(f1+1)*(f1+1);
                if ((EXP1-f1*f1)<=(s1-EXP1))
                    p1=100;
                else{
                    h1=EXP1;
                    p1=round((h1/s1+80)*100/123);
                }
            }
            else if (i==2){
                if ((E2%2)==0){
                    for (int j=0;j<3;j++){
                        if (M1==0)
                            break;
                        if (j==0){
                            if (HP1<200){
                                x=x*1.30;
                                HP1=HP1*130/100;
                                if (x>HP1)
                                    HP1+=1;
                                x=HP1;
                                M1-=150;
                                if (M1<0)
                                    M1=0;
                            }
                            else{
                                x=x*1.10;
                                HP1=HP1*110/100;
                                if (x>HP1)
                                    HP1+=1;
                                if (HP1>666)
                                    HP1=666;
                                x=HP1;
                                M1-=70;
                                if (M1<0)
                                    M1=0;
                            }
                        }
                        if (M1==0)
                            break;
                        if (j==1){
                            if (EXP1<400){
                                M1-=200;
                                if (M1<0)
                                    M1=0;
                            }
                            else{
                                M1-=120;
                                if (M1<0)
                                    M1=0;
                            }
                            y=y*1.13;
                            EXP1=EXP1*113/100;
                            if (y>EXP1)
                                EXP1+=1;
                            if (EXP1>600)
                                EXP1=600;
                            y=EXP1;
                        }
                        if (M1==0)
                            break;
                        if (j==2){
                            if (EXP1<300)
                                M1-=100;
                            else
                                M1-=120;
                            if (M1<0)
                                M1=0;
                            y=y*0.9;
                            EXP1=EXP1*90/100;
                            if (y>EXP1)
                                EXP1+=1;
                            y=EXP1;
                        }
                    }
                    x=x*0.83;
                    HP1=HP1*83/100;
                    if (x>HP1)
                        HP1+=1;
                    x=HP1;
                    y=y*1.17;
                    EXP1=EXP1*117/100;
                    if (y>EXP1)
                        EXP1+=1;
                    if (EXP1>600)
                        EXP1=600;
                    y=EXP1;
                }
                else if ((E2%2)==1){
                    int a=0,c,d,e;
                    double b=M1/2;
                    if (M1>0){
                        while (a<=b){
                            if (HP1<200){
                                x=x*1.30;
                                HP1=HP1*130/100;
                                if (x>HP1)
                                    HP1+=1;
                                x=HP1;
                                M1-=150;
                                c=150;
                                if (M1<0)
                                    M1=0;
                            }
                            else{
                                x=x*1.10;
                                HP1=HP1*110/100;
                                if (x>HP1)
                                    HP1+=1;
                                if (HP1>666)
                                    HP1=666;
                                x=HP1;
                                M1-=70;
                                c=70;
                                if (M1<0)
                                    M1=0;
                            }
                            if (a+c>b)
                                break;

                            if (EXP1<400){
                                M1-=200;
                                d=200;
                                if (M1<0)
                                    M1=0;
                            }
                            else{
                                M1-=120;
                                d=120;
                                if (M1<0)
                                    M1=0;
                            }
                            y=y*1.13;
                            EXP1=EXP1*113/100;
                            if (y>EXP1)
                                EXP1+=1;
                            if (EXP1>600)
                                EXP1=600;
                            y=EXP1;
                            if ((a+c+d)>b)
                                break;

                            if (EXP1<300){
                                M1-=100;
                                e=100;
                            }
                            else {
                                M1-=120;
                                e=120;
                            }
                            if (M1<0)
                                M1=0;
                            y=y*0.90;
                            EXP1=EXP1*90/100;
                            if (y>EXP1)
                                EXP1+=1;
                            y=EXP1;
                            if ((a+c+d+e)>b)
                                break;
                            a=a+c+d+e;
                        }
                    }
                    x=x*0.83;
                    HP1=HP1*83/100;
                    if (x>HP1)
                        HP1+=1;
                    x=HP1;
                    y=y*1.17;
                    EXP1=EXP1*117/100;
                    if (y>EXP1)
                        EXP1+=1;
                    if (EXP1>600)
                        EXP1=600;
                    y=EXP1;
                }
                int f2=sqrt(EXP1);
                double s2=(f2+1)*(f2+1);
                if ((EXP1-f2*f2)<=(s2-EXP1))
                    p2=100;
                else{
                    h2=EXP1;
                    p2=round((h2/s2+80)*100/123);
                }
            }
            else if (i==3){
                int P[10] = {32,47,28,79,100,50,22,83,64,11};
                if ((E2>=0)&&(E2<=9))
                    p3=P[E2];
                else {
                    int f=E2/10+(E2-E2/10*10);
                    if ((f>=0)&&(f<=9)){
                        double k=P[f];
                        p3=k;
                    }
                    else{
                        double l=P[f-10];
                        p3=l;
                    }
                }
            }
        }
        if ((p1==100)&&(p2==100)&&(p3==100)){
            y=y*0.75;
            EXP1=EXP1*75/100;
            if (y>EXP1)
                EXP1+=1;
            y=EXP1;
        }
        else {
            p=(p1+p2+p3)/3;
            if (p<50){
                x=x*0.85;
                HP1=HP1*85/100;
                if (x>HP1)
                    HP1+=1;
                x=HP1;
                y=y*1.15;
                EXP1=EXP1*115/100;
                if (y>EXP1)
                    EXP1+=1;
                if (EXP1>600)
                    EXP1=600;
                y=EXP1;
            }
            else {
                x=x*0.90;
                HP1=HP1*90/100;
                if (x>HP1)
                    HP1+=1;
                y=y*1.20;
                EXP1=EXP1*120/100;
                if (y>EXP1)
                    EXP1+=1;
                if (EXP1>600)
                    EXP1=600;
            }
        }
        return HP1 + EXP1 + M1 ;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ((E3<0)||(E3>99))
        return -99;
    if (EXP1>600)
        EXP1=600;
    if (EXP1<0)
        EXP1=0;

    if (EXP2>600)
        EXP2=600;
    if (EXP2<0)
        EXP2=0;

    if (HP1>666)
        HP1=666;
    if (HP1<0)
        HP1=0;

    if (HP2>666)
        HP2=666;
    if (HP2<0)
        HP2=0;

    int matrix[10][10];
    int i, j;
    for (i=0;i<10;i++){
        for (j=0;j<10;j++)
            matrix[i][j]=((E3*j)+(i*2))*(i-j);
    }

    int x=0, y=0;
    for (i=0;i<10;i++){
        for (j=0;j<10;j++){
            if (matrix[i][j]>(E3*2))
                x+=1;
            if (matrix[i][j]<(-E3))
                y+=1;
        }
    }

    while (x>=10)
        x=x/10+(x-x/10*10);
    while (y>=10)
        y=y/10+(y-y/10*10);
    int a=matrix[x][y];
    int c=a;
    int x1=x,x2=x,x3=x,x4=x;
    int y1=y,y2=y,y3=y,y4=y;
    while ((x1>=0)&&(x1<=9)&&(y1>=0)&&(y1<=9)){
        if (matrix[x1][y1]>c)
            c=matrix[x1][y1];
        x1+=1; y1+=1;
    }
    while ((x2>=0)&&(x2>=0)&&(y2>=0)&&(y2<=9)){
        if (matrix[x2][y2]>c)
            c=matrix[x2][y2];
        x2-=1; y2-=1;
    }

    while ((x3>=0)&&(x3<=9)&&(y3>=0)&&(y3<=9)){
        if (matrix[x3][y3]>c)
            c=matrix[x3][y3];
        x3+=1; y3-=1;
    }

    while ((x4>=0)&&(x4<=9)&&(y4>=0)&&(y4<=9)){
        if (matrix[x4][y4]>c)
            c=matrix[x4][y4];
        x4-=1; y4+=1;
    }

    if (abs(a)>c){
        float q=EXP1;
        q=q*0.88;
        EXP1=EXP1*88/100;
        if (q>EXP1)
            EXP1+=1;
        float w=EXP2;
        w=w*0.88;
        EXP2=EXP2*88/100;
        if (w>EXP2)
            EXP2+=1;

        float e=HP1;
        e=e*0.90;
        HP1=HP1*90/100;
        if (e>HP1)
            HP1+=1;
        float r=HP2;
        r=r*0.90;
        HP2=HP2*90/100;
        if (r>HP2)
            HP2+=1;
    }
    else {
        float q=EXP1;
        q=q*1.12;
        EXP1=EXP1*112/100;
        if (q>EXP1)
            EXP1+=1;
        float w=EXP2;
        w=w*1.12;
        EXP2=EXP2*112/100;
        if (w>EXP2)
            EXP2+=1;

        float e=HP1;
        e=e*1.10;
        HP1=HP1*110/100;
        if (e>HP1)
            HP1+=1;
        float r=HP2;
        r=r*1.10;
        HP2=HP2*110/100;
        if (r>HP2)
            HP2+=1;

        if (EXP1>600)
            EXP1=600;
        if (EXP1<0)
            EXP1=0;

        if (EXP2>600)
            EXP2=600;
        if (EXP2<0)
            EXP2=0;

        if (HP1>666)
            HP1=666;
        if (HP1<0)
            HP1=0;

        if (HP2>666)
            HP2=666;
        if (HP2<0)
            HP2=0;
    }
    if (abs(a)>c)
        return a;
    else
        return c;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    std::string a=s, b=email;
    std::string se;
    int l=a.length();
    int k1=b.length();
    int sei, sci;
    for (int h=0;h<k1;h++){
        if (b[h]!='@')
            se=se+b[h];
        else
            break;
    }
    int k=se.length();
    if (l<8)
        return -1;
    else if (l>20)
        return -2;
    else {
        int z=0;
        if (l>=k){
            sei=a.find(se);
            if (sei>=0&&sei<l)
                z=1;
        }
        if (z==1)
            return -(300+sei);
        else{
            for (int i1=2;i1<l;i1++){
                if (((a[i1])==(a[i1-1])&&(a[i1]==a[i1-2]))){
                    sci=i1-2;
                    z=2;
                    break;
                }
            }
            if (z==2)
                return -(400+sci);
            else {
                int q=0;
                for (int i2=l-1;i2>=0;i2--){
                    if ((a[i2]!='@')&&(a[i2]!='#')&&(a[i2]!='%')&&(a[i2]!='$')&&(a[i2]!='!'))
                        q+=1;
                }
                if (q==l)
                    z=3;
                if (z==3)
                    return -5;
                else {
                    int m=-1;
                    for (int i3=l-1;i3>=0;i3--){
                        int x=int(a[i3]);
                        if (((x>=0)&&(x<=32))||(x==34)||((x>=38)&&(x<=47))||((x>=58)&&(x<=63))||((x>=91)&&(x<=96))||((x>=123)&&(x<=127)))
                            m=i3;
                    }
                    if (m==-1)
                        return -10;
                    else
                        return m;
                }
            }
        }
    }
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    std::string pass;
    int arr[num_pwds];
    int ar[num_pwds];
    for (int i=num_pwds-1;i>=0;i--){
        pass=arr_pwds[i];
        arr[i]=1;
        ar[i]=pass.length();
        for (int j=i+1;j<num_pwds;j++){
            if (arr_pwds[i]==arr_pwds[j]){
                arr[i]+=1;
            }
        }
    }
    int n=0;
    for (int i1=0;i1<num_pwds;i1++){
        if (arr[i1]>n)
            n=arr[i1];
    }
    int m=0;
    for (int i2=0;i2<num_pwds;i2++){
        if (arr[i2]==n)
            m+=1;
    }
    int a[m];
    int x=0;
    for (int i3=0;i3<num_pwds;i3++){
        if (arr[i3]==n){
            a[x]=i3;
            x+=1;
        }
    }
    int p=0,q=0;
    for (int i4=0;i4<m;i4++){
        if (ar[a[i4]]>p){
            p=ar[a[i4]];
            q=a[i4];
        }
    }
    return q;
}////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////