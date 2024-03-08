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

//ham tim so chinh phuong
int findSquareNumber_S(int & EXP1){
   int squareroot_EXP1 = sqrt(EXP1);
   int option1= (squareroot_EXP1*squareroot_EXP1);
   int option2= (squareroot_EXP1+1)*(squareroot_EXP1+1);
   int S= abs(option1-EXP1)<abs(option2-EXP1)? option1:option2;
   return S;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1>=0 && e1<=99)
    {
        if (e1>=0 && e1<=3)
        {
            if(e1==0) exp2+=29;
            else if(e1==1) exp2+=45;
            else if (e1==2) exp2+=75;
            else exp2+=(29+45+75);
            int D=e1*3 + exp1*7;
            if (D%2==0) exp1= (exp1+(D/200)) + 0.999;
            else exp1= (exp1-(D/100)) + 0.999;
        }
        else
        {
            if (e1>=4 && e1<=19)        
            {
                double replace_exp2= (exp2+ (e1/4.0+19)) + 0.999;
                exp2= replace_exp2;
            }
            else if ( e1>=20 && e1<=49)
            {
                double replace_exp2= (exp2+ (e1/9.0+21)) + 0.999;
                exp2= replace_exp2;
            }
            else if (e1>=50 && e1<=65)  
            {
                double replace_exp2= (exp2+ (e1/16.0+17)) + 0.999;
                exp2= replace_exp2;
            }
            else if (e1>=66 && e1<=79)
            {
                double replace_exp2= (exp2+ (e1/4.0+19)) + 0.999;
                exp2= replace_exp2;
                if (exp2>200) 
                {
                   double replace_exp2= (exp2+ (e1/9.0+21)) + 0.999;
                   exp2= replace_exp2;
                }
            }
            else 
            {
                double replace_exp2= (exp2+ (e1/4.0+19)) + 0.999;
                exp2= replace_exp2;
                replace_exp2= (exp2+ (e1/9.0+21)) + 0.999;
                exp2=replace_exp2;
                if (exp2>400)
                {
                    double replace_exp2= (exp2+ (e1/16.0+17)) + 0.999;
                    exp2= replace_exp2;
                    replace_exp2= (exp2+ exp2*(15.0/100)) + 0.999;
                    exp2=replace_exp2;
                }
            }
            exp1= (exp1-e1);
        }
        if (exp1>600)   exp1=600;
        if (exp1<0)     exp1=0;
        if (exp2>600)   exp2=600;
        if (exp2<0)     exp2=0;
    }
    else return -99;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2>=0 && E2<=99)
    {
        //Con duong 1
        int S1= findSquareNumber_S(EXP1);
        double P1= (EXP1>=S1) ? 1:((EXP1*1.0/S1 + 80)/123);

        //Con duong 2

        if (E2%2==0)
        {
            //HP1: DO AN
            if (HP1<200)
            {
                double replace_HP1=HP1*1.3+0.999;
                HP1= replace_HP1;
                if (HP1>666)  HP1=666;
                if (HP1<0)    HP1=0;
                M1-=150;
                if (M1>3000)    M1=3000;
                if (M1<0)       M1=0;
            }
            else
            {
                double replace_HP1=HP1*1.1+0.999;
                HP1= replace_HP1;
                if (HP1>666)  HP1=666;
                if (HP1<0)    HP1=0;
                M1-=70;
                if (M1>3000)    M1=3000;
                if (M1<0)       M1=0;
            }

            //EXP1: PHUONG TIEN DI CHUYEN
            if (M1>0)
            {
                if (EXP1<400)  M1-=200;
                else  M1-=120;
                if (M1>3000)    M1=3000;
                if (M1<0)       M1=0;
                double replace_EXP1=EXP1*1.13+0.999;
                EXP1= replace_EXP1;
                if (EXP1>600)   EXP1=600;
                if (EXP1<0)     EXP1=0;
            }

            //EXP1: NGUOI VO GIA CU
            if (M1>0) 
            {
                if (EXP1<300)  M1-=100;
                else           M1-=120;
                if (M1>3000)    M1=3000;
                if (M1<0)       M1=0;
                double replace_EXP1=EXP1*0.9+0.999;
                EXP1= replace_EXP1;
                if (EXP1>600)   EXP1=600;
                if (EXP1<0)     EXP1=0;
            }
        }
        else
        {
            int M_SH=M1;
            do
            {
                //HP1: DO AN
                if (HP1<200)
                {
                    double replace_HP1=HP1*1.3+0.999;
                    HP1=replace_HP1;
                    if (HP1>666)  HP1=666;
                    if (HP1<0)    HP1=0;
                    M1-=150;
                    if (M1>3000)    M1=3000;
                    if (M1<0)       M1=0;
                }
                else
                {
                    double replace_HP1=HP1*1.1+0.999;
                    HP1=replace_HP1;
                    if (HP1>666)  HP1=666;
                    if (HP1<0)    HP1=0;
                    M1-=70;
                    if (M1>3000)    M1=3000;
                    if (M1<0)       M1=0;
                }

                //EXP1: PHUONG TIEN DI CHUYEN
                if(M1>=0.5*M_SH)
                {
                    if (EXP1<400)  M1-=200;
                    else  M1-=120;
                    if (M1>3000)    M1=3000;
                    if (M1<0)       M1=0;
                    double replace_EXP1=EXP1*1.13+0.999;
                    EXP1= replace_EXP1;
                    if (EXP1>600)   EXP1=600;
                    if (EXP1<0)     EXP1=0;
                }
                else break;

                //EXP1: NGUOI VO GIA CU
                if(M1>=0.5*M_SH)
                {
                    if (EXP1<300)  M1-=100;
                    else  M1-=120;
                    if (M1>3000)    M1=3000;
                    if (M1<0)       M1=0;
                    double replace_EXP1= EXP1*0.9+0.999;
                    EXP1= replace_EXP1;
                    if (EXP1>600)   EXP1=600;
                    if (EXP1<0)     EXP1=0;
                }
                else break;
            }
            while (M1>=0.5*M_SH);
        }
        double replace_HP1=HP1*0.83+0.999;
        HP1= replace_HP1;
        if (HP1>666)  HP1=666;
        if (HP1<0)    HP1=0;
        double replace_EXP1=EXP1*1.17+0.999;
        EXP1=replace_EXP1;
        if (EXP1>600)   EXP1=600;
        if (EXP1<0)     EXP1=0;
        int S2= findSquareNumber_S(EXP1);
        double P2= (EXP1>=S2) ? 1:((EXP1*1.0/S2 + 80)/123);


        //Con duong 3
        int P[10]={32,47,28,79,100,50,22,83,64,11};
        int P3;
        if (E2>=0 && E2<=9)
        {
            for(int i=0;i<10;i++)
            {
                if (i==E2)
                {
                    P3= P[i];
                    break;
                }
            }
        }
        else{
            int ChiSo=(E2%10+E2/10)%10;
            P3= P[ChiSo];
        }

        //Tong ket NV2
        if(P1==1 && P2==1 && P3==100)
        {
            double replace_EXP1=EXP1*0.75+0.999;
            EXP1= replace_EXP1;
            if (EXP1>600)   EXP1=600;
            if (EXP1<0)     EXP1=0;
        }
        else 
        {
            double P= (P1+P2+P3/100)/3;
            if(P<0.5)
            {
                double replace_HP1=HP1*0.85+0.999;
                HP1= replace_HP1;
                if (HP1>666)  HP1=666;
                if (HP1<0)    HP1=0;
                double replace_EXP1=EXP1*1.15+0.999;
                EXP1= replace_EXP1;
                if (EXP1>600)   EXP1=600;
                if (EXP1<0)     EXP1=0;
            }
            else
            {
                double replace_HP1=HP1*0.9+0.999;
                HP1= replace_HP1;
                if (HP1>666)  HP1=666;
                if (HP1<0)    HP1=0;
                double replace_EXP1=EXP1*1.2+0.999;
                EXP1= replace_EXP1;
                if (EXP1>600)   EXP1=600;
                if (EXP1<0)     EXP1=0;
            }
        }
    }
    else return -99;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int KQ;
    int meet_i=0, meet_j=0;
    int diemTaxi[10][10]= {};
    int diemSherlockWatson[10][10]={};
    if (E3>=0 && E3<=99)
    {
        //thet lap mt diem taxi
        for (int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                diemTaxi[i][j]=((E3*j)+(i*2))*(i-j);
                if (diemTaxi[i][j]>E3*2)    meet_i+=1;
                if (diemTaxi[i][j]<(-E3))   meet_j+=1;
            }
        }
        while (meet_i>9)
        {
            meet_i= (meet_i%10)+(meet_i/10);
        }
        while (meet_j>9)
        {
            meet_j= (meet_j%10)+(meet_j/10);
        }
        
        //thiet lap mt diem sherlock watson
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10;j++)
            {
                int arr[50]={};
                int a=0;
                int m=i;
                int n=j;
            while (m>=0 && n>=0)                 //tim dct phia tren
            {
                    arr[a]=diemTaxi[m][n];
                    m-=1;
                    n-=1;
                    a+=1;
            }
            m=i; n=j;
            while (m<10 && n<10)                 //tim dct phia duoi
            {
                    arr[a]=diemTaxi[m][n];
                    m+=1;
                    n+=1;
                    a+=1;
            }
            m=i; n=j;
            while (m<10 && n>=0)                 //tim dcp phia duoi
            {
                    arr[a]=diemTaxi[m][n];
                    m+=1;
                    n-=1;
                    a+=1;
            }
            m=i; n=j;
            while (m>=0 && n<10)                 //tim dcp phia tren
            {
                    arr[a]=diemTaxi[m][n];
                    m-=1;
                    n+=1;
                    a+=1;
            }
            for (int x=0; x<50; x++)
            {
                if (arr[x]>diemSherlockWatson[i][j]) 
                    diemSherlockWatson[i][j]=arr[x];
            }
            }
        }
        if (abs(diemTaxi[meet_i][meet_j])>abs(diemSherlockWatson[meet_i][meet_j]))
        {
            double replace_HP1=HP1*0.9+0.999;
            HP1= replace_HP1;
            double replace_EXP1=EXP1*0.88+0.999;
            EXP1= replace_EXP1;
            double replace_HP2=HP2*0.9+0.999;
            HP2= replace_HP2;
            double replace_EXP2=EXP2*0.88+0.999;
            EXP2= replace_EXP2;
            KQ= diemTaxi[meet_i][meet_j];
        }
        else
        {
            double replace_HP1=HP1*1.1+0.999;
            HP1= replace_HP1;
            double replace_EXP1=EXP1*1.12+0.999;
            EXP1= replace_EXP1;
            double replace_HP2=HP2*1.1+0.999;
            HP2= replace_HP2;
            double replace_EXP2=EXP2*1.12+0.999;
            EXP2= replace_EXP2;
            KQ= diemSherlockWatson[meet_i][meet_j];
        }
        if (HP1>666)    HP1=666;
        if (HP1<0)      HP1=0;
        if (EXP1>600)   EXP1=600;
        if (EXP1<0)     EXP1=0;
        if (HP2>666)    HP2=666;
        if (HP2<0)      HP2=0;
        if (EXP2>600)   EXP2=600;
        if (EXP2<0)     EXP2=0;
    }
    else return -99;
    return KQ;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int KQ=0, sei=0, sci=0, cut=0;
    string re_s=string(s);
    string re_email=string(email);
    for (int i=0; i<re_email.length(); i++)             //tim vi tri '@'
    {
        if (re_email[i]=='@')  {cut=i;  break;} 
    }
    string se=re_email.substr(0,cut);                   //cat email tu ki tu dau den @
    if (re_s.length()<8)    KQ=-1;
    if (re_s.length()>20)   KQ=-2;
    if (KQ==0)
    {
        if (re_s.find(se)!=string::npos)    {sei=re_s.find(se);     KQ=-(300+sei);}
        //ham find tra ve vi tri dau tien cua chuoi se trong s
    }
    if (KQ==0)
    {
        int count=0;
        char a;
        for (int i=0; i<re_s.length(); i++)
        {
            if (re_s[i]==a)             //so sanh tung ki tu voi ki tu truoc do
            {                          
            count+=1;                   //neu ki tu sau giong thi dem 1
            if (count==2)     {sci=i-2; KQ=-(400+sci);  break;}
                                //truong hop co hon 2 ki tu lien tiep giong nhau
            }
            else count=0;
            a=re_s[i];                  //luu ki tu de so sanh voi ki tu sau
        }
    }
    if(KQ==0)
    {
        int counter=0;
        for (int j=0; j<re_s.length(); j++)
        {
            if (re_s[j]==33                     //33:"!"
                ||(re_s[j]>=35&&re_s[j]<=37)    //35,36,37:"#","$","%"
                ||re_s[j]==64)                  //64:"@"
                counter+=1;     //neu co ki tu DB counter=1
        }
        if (counter==0)       KQ=-5;      //ko co KTDB
    }
    if (KQ==0)
    {   //Truong hop: s chua ki tu khac chu so, chu thuong, chu hoa, KTDB
        //ham tra ve vi tri ki tu do
        for (int n=0; n<re_s.length(); n++)
        {
            if (re_s[n]==33
                ||(re_s[n]>=35 && re_s[n]<=37)
                ||re_s[n]==64                      //cac KTDB
                ||(re_s[n]>=48 && re_s[n]<=57)     //chu so 0->9
                ||(re_s[n]>=65 && re_s[n]<=90)     //chu hoa A->Z
                ||(re_s[n]>=97 && re_s[n]<=122))   //chu thuong a->z
                continue;
            else {KQ=n;     break;}   
        }
    }
    if (KQ==0) KQ=-10;      //s hop le
    return KQ;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int counter[30]={};    //tao mang chua so lan xuat hien
    int max=0, value_max=0;
    for (int i=0; i<num_pwds; i++)
    {
        for (int j=0; j<num_pwds;j++)
        {
            if (*arr_pwds[j]==*arr_pwds[i])  counter[i]+=1;
        }
        if ((counter[i])>max)    max=counter[i];    //max: so lan xuat hien nhieu nhat
    }
        int i=0, a=0;
        while(i<num_pwds)
        {
            if ((counter[i])==max)
            {
                value_max=a;
                if (strlen(arr_pwds[i])>strlen(arr_pwds[a]))    value_max=i;
            }
            a=i;
            i+=1;
        }
    for(int k=0; k<num_pwds; k++)
    {
        if (arr_pwds[k]==arr_pwds[value_max])   {value_max=k;    break;}
    }
    return value_max;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////