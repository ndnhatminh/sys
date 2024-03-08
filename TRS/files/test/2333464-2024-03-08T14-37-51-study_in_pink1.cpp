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
    
    
    if(e1 <0 || e1>99)
        return -99;
    if(e1>=0 && e1 <=3)
    {
        switch (e1)
        {
        case 0:
            exp2+=29;
            exp2 = chuanhoaexp(exp2);
            break;
        case 1:
            exp2+=45;
            exp2 = chuanhoaexp(exp2);
            break;
        case 2:
            exp2+=75;
            exp2 = chuanhoaexp(exp2);
            break;
        default:
            exp2+=29+45+75;
            exp2 = chuanhoaexp(exp2);
            break;
        }

        int d = e1*3+exp1*7;
        if(d%2==0)
        {
            float exp1_tam = 1.0*exp1 + 1.0*d/200;
            exp1 = ceil(exp1_tam);
            exp1 = chuanhoaexp(exp1);
        }
        else{
            float exp1_tam = 1.0*exp1 - 1.0*d/100;
            exp1 = ceil(exp1_tam);
            exp1 = chuanhoaexp(exp1);
        }

    }

    if(e1>=4 && e1<=99)
    {
        float exp2_tam=0.0;
        if(e1 >=4 && e1<=19) //thong tin 1
        {
            exp2_tam = 1.0*(exp2 + 19)+1.0*e1/4;
            exp2 = ceil(exp2_tam);
            exp2 = chuanhoaexp(exp2);
            
        }
        if(e1 >=20 && e1<=49) //thong tin 2
        {
            exp2_tam = 1.0*(exp2 + 21) + 1.0*e1/9;
            exp2 = ceil(exp2_tam);
            exp2 = chuanhoaexp(exp2);
        }
        if(e1 >=50 && e1<=65) //thong tin 3
        {
            exp2_tam = 1.0*(exp2 + 17)+ 1.0*e1/16;
            exp2 = ceil(exp2_tam);
            exp2 = chuanhoaexp(exp2);
        }
        if(e1 >=66 && e1<=79) // thong  tin 4
        {
            //thong tin 1
            exp2_tam = 1.0*exp2 + 1.0*e1/4 +19;
            exp2 = ceil(exp2_tam);
            exp2 = chuanhoaexp(exp2);
            if(exp2>200)
            {
                exp2_tam = 1.0*exp2 + 1.0*e1/9 +21; //thong tin 2
                exp2 = ceil(exp2_tam);
                exp2 = chuanhoaexp(exp2);
            }   
        }
        if(e1 >=80 && e1<=99) //thong tin 5
        {
            //thong tin 1
            exp2_tam = 1.0*exp2 + 1.0*e1/4 +19;
            exp2 = ceil(exp2_tam);
            exp2 = chuanhoaexp(exp2);

            //thong tin 2
            exp2_tam = 1.0*exp2 + 1.0*e1/9 +21;
            exp2 = ceil(exp2_tam);
            exp2 = chuanhoaexp(exp2);

            if(exp2>400)
            {
                //thong tin 3
                exp2_tam = 1.0*exp2 + 1.0*e1/16 +17;

                //exp2 tang 15% exp 
                exp2_tam = exp2_tam*1.15;

                exp2 = ceil(exp2_tam);
                exp2 = chuanhoaexp(exp2);
            }
        }

        //exp sherlock sau khi giai thich thong tin
        exp1 = exp1 - e1;
        exp1 = chuanhoaexp(exp1);

    }
    exp1 = chuanhoaexp(exp1);
    exp2 = chuanhoaexp(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    
    float p1=0.00,p2=0.0,p3=0.0;

    if(E2<0 || E2 >99)
        return -99;

    //con duong 1
    int s = sochinhphuonggannhat(EXP1);
    if(EXP1>=s)
    {
        p1 = 1.00;
    }
    else
    {
        p1 = 1.00*(EXP1/s + 80)/123;
    }

    //con duong 2
    float nuasotien = M1*0.5;
    float tongtienchi = 0.0;
    if(E2%2!=0)
    {
        while (tongtienchi<nuasotien)
        {
            if (HP1<200)
            {   
                HP1 =ceil(HP1*1.30); //tang 30%
                M1 = M1 - 150;
                tongtienchi+=150;
                HP1 = chuanhoahp(HP1);
                //EXP1 = chuanhoaexp(EXP1);
                M1 = chuanhoam(M1);
            }
            else{
                HP1 = ceil(HP1*1.1);
                M1= M1 - 70;
                tongtienchi+=70;
                HP1 = chuanhoahp(HP1);
                M1 = chuanhoam(M1);
            }
            if(tongtienchi<nuasotien)
            {

                if(EXP1<400) //di taxi
                {
                    M1 = M1 - 200;
                    tongtienchi+=200;
                    M1 = chuanhoam(M1);
                }
                else //di xe ngua
                {
                    M1 = M1 -120;
                    tongtienchi+=120;
                    M1 = chuanhoam(M1);
                }
                EXP1 = ceil(EXP1*1.13);
                EXP1 = chuanhoaexp(EXP1);
            }

            if(tongtienchi<nuasotien)
            {
                if(EXP1<300) //nguoi huong dan
                {
                    M1 = M1 - 100;
                    tongtienchi +=100;
                    M1 = chuanhoam(M1);
                }
                else{
                    M1 = M1 -120;
                    tongtienchi +=120;
                    M1 = chuanhoam(M1);
                }
                EXP1 = ceil(EXP1*0.9);
                EXP1 = chuanhoaexp(EXP1);
            }
        }
        
    }
    else
    {
        if(M1 >0)
        {
            if (HP1<200) //an uong
            {   
                HP1 =ceil(HP1*1.30); //tang 30%
                M1 = M1 - 150;
                M1 = chuanhoam(M1);
                HP1 = chuanhoahp(HP1);

            }
            else{
                HP1 = ceil(HP1*1.1);
                M1= M1 - 70;
                M1 = chuanhoam(M1);
                HP1 = chuanhoahp(HP1);
                    
            }
        }
        else
        {
            M1 = 0;
        }
        if(M1>0)
        {
            if(EXP1<400) //di taxi
            {
                M1 = M1 - 200;
                M1 = chuanhoam(M1);
                    
            }
            else //di xe ngua
            {
                M1 = M1 -120;
                M1 = chuanhoam(M1);
                    
            }
            EXP1 = ceil(EXP1*1.13);
            EXP1 = chuanhoaexp(EXP1);
        }
        else{
            M1 = 0;
        }       
        if(M1>0)
        {

            if(EXP1<300) //nguoi huong dan
            {
                M1 = M1 - 100;
                M1 = chuanhoam(M1);
                    
            }
            else{
                M1 = M1 -120;
                M1 = chuanhoam(M1);
            }
            EXP1 = ceil(EXP1*0.9);
            EXP1 = chuanhoaexp(EXP1);
        }
        else
        {
            M1 = 0;
        }
        
    }
    //di bo cuoi duong
    HP1 =ceil(HP1*0.83);
    HP1 = chuanhoahp(HP1);

    EXP1 = ceil(EXP1*1.17);
    EXP1 = chuanhoaexp(EXP1);

    s = sochinhphuonggannhat(EXP1);
    if(EXP1>=s)
    {
        p2 = 1.00;
    }
    else
    {
        p2 = 1.00*(EXP1/s + 80)/123;
    }
    
    //con duong 3
    int p[10]={32,47,28,79,100,50,22,83,64,11};
    int i=0;
    if(E2>=0 && E2<=9)
    {
        i=E2;
    }
    else
    {
        i=(E2/10 + E2%10)%10;
    }
    p3 = 1.00*p[i]/100;
    float ptb = p1+p2+p3;
    if(ptb==3.00)
    {
        EXP1 = ceil(EXP1*0.75);
        EXP1 = chuanhoaexp(EXP1);
    }
    if ((ptb/3.0)<0.50)
    {
        HP1 = ceil(HP1*0.85);
        HP1 = chuanhoahp(HP1);

        EXP1 = ceil(EXP1*1.15);
        EXP1 = chuanhoaexp(EXP1);
    }
    else{
        HP1 = ceil(HP1*0.9);
        HP1 = chuanhoahp(HP1);

        EXP1 = ceil(EXP1*1.2);
        EXP1 = chuanhoaexp(EXP1);

    }
    
    //chuan hoa dau ra
    HP1 = chuanhoahp(HP1);
    EXP1 = chuanhoaexp(EXP1);
    M1 = chuanhoam(M1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int kq = -99;
    if(E3 <0 || E3 >99)
    {
        return -99;
    }
    
    //xu li ma tran
    int taxima[10][10];
    //khoi tao ma tran taxi= 0
    for(int i = 0; i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            taxima[i][j]=0;
        }
    }

    //khoi tao ma tran taxi
    for(int i = 0; i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            taxima[i][j]=((E3*j)+(i*2))*(i-j);
        }
    }

    //khoi tao maa tran sherlock-waston
    int sherlock[10][10];
    for(int i = 0; i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            sherlock[i][j]=0;
        }
    }

    //xu li ma tran sherlock
    
    for(int j = 0; j<10;j++)
    {
        for(int i=0;i<10;i++)
        {
            int maxcheot = maxcheotrai(taxima,i,j);
            int maxcheop = maxcheophai(taxima,i,j);
            if(maxcheot < maxcheop)
            {
                sherlock[i][j]=maxcheop;
            }
            else
            {
                sherlock[i][j]=maxcheot;
            }
            if(sherlock[i][j]<0)
            {
                sherlock[i][j] =abs(sherlock[i][j]);
            }
               
        }
    }

    //vi tri gap nhau
    int dem1=0, dem2=0;
    for(int i = 0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(taxima[i][j]>E3*2)
            {
                dem1++;
            }
            if(taxima[i][j]<(-1*E3))
            {
                dem2++;
            }
        }
    }
    //xu ly i,j
    while(dem1>9 && dem1<100)
    {
        int k =dem1%10;
        dem1 = dem1/10;
        dem1 = k+dem1;
    }
    int k = dem1;
    while(dem2>9 && dem2<100)
    {
        int k =dem2%10;
        dem2 = dem2/10;
        dem2 = k+dem2;
    }
    int q = dem2;
    kq = taxima[k][q];
    if(abs(taxima[k][q])>sherlock[k][q])
    {
        EXP1 = round(EXP1*0.88);
        EXP2 = round(EXP2*0.88); 
        HP1 = round(HP1*0.9);
        HP2 = round(HP2*0.9);
    }
    else
    {
        EXP1 = round(EXP1*1.12);
        EXP2 = round(EXP2*1.12); 
        HP1 = round(HP1*1.1);
        HP2 = round(HP2*1.1);

        kq = sherlock[k][q];
    }
    EXP1 = chuanhoaexp(EXP1);
    EXP2 = chuanhoaexp(EXP2);
    HP1 = chuanhoahp(HP1);
    HP2 = chuanhoahp(HP2);

    return kq;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int kq = -10;
    string se = tachchuoi(email,"@");
    kq = passlen(s);
    if (kq!=-10)
    {
        return kq;
    }
    kq = passchuoise(s,se);
    if (kq!=-10)
    {
        return kq;
    }
    kq = passchuoisc(s);
    if(kq!=-10)
    {
        return kq;
    }
    kq = passchuoidb(s);
    if(kq!=-10)
    {
        return kq;
    }
    kq = passchuoi(s);
    if(kq!=-10)
    {
        return kq;
    }
    return kq;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int chiso = num_pwds;
    //int kq = -1;
    if(chiso<=0)
    {
        chiso = 0;
        return -1;
    }
        
    int *tanso = new int[chiso]; //tao mang co tan so =0
    for (int k = 0; k<chiso; k++)
    {
        tanso[k]=1;
    }
    
    for(int i=0;i<chiso;i++)
    {
        for(int j=i+1;j<chiso;j++)
        {
            if(strcmp(arr_pwds[i],arr_pwds[j])==0)
            {
                tanso[i]+=1;
            }
        }
    }
    //tan so lon nha
    int tanso_max = 0;
    for (int k = 0; k<chiso; k++)
    {   
        if(tanso_max<tanso[k])
        {
            tanso_max=tanso[k];
        }
    }

    int vitri=0,dodai_max=0;
    bool co_max = false;

    for (int i= 0; i < chiso; i++)
    {
        if(tanso_max == tanso[i])
        {
            if(co_max==false)
            {
                dodai_max = strlen(arr_pwds[i]);
                vitri = i;
                co_max = true;
            }
            else
            {
                if (dodai_max<strlen(arr_pwds[i]))
                {
                    vitri = i;
                    dodai_max = strlen(arr_pwds[i]);
                }
                
            }         
        }
    }
    

    return vitri;
}

int chuanhoahp(int hp)
{
    if(hp <0)
        return 0;
    if(hp>666)
        return 666;
    return hp;
}

int chuanhoaexp(int exp0)
{
    if(exp0 <0)
        return 0;
    if(exp0>600)
        return 600;

    return exp0;
}

int chuanhoam(int m0)
{
    if(m0<0)
        return 0;
    if(m0>3000)
        return 3000;
    return m0;
}
int sochinhphuonggannhat(int cp)
{
    int kq=0;

    if(cp>0)
    {
        double tam = sqrtl(cp);
        int tam2 = floor(tam);
        if(abs(tam2*tam2-cp)<=abs((tam2+1)*(tam2+1)-cp))
        {
            kq=tam2*tam2;
        }
        else{
            kq=(tam2+1)*(tam2+1);
        }
    }
    return kq;
}
int maxcheophai(int data[10][10], int i1, int j1)
{
    int i = i1,j=j1;
    int kq = data[i][j];
    while (i<10 && j>=0)
    {
        if(kq<data[i][j])
        {
            kq = data[i][j];
        }
        i++;
        j--;
    }
    i = i1,j=j1;
    while (i>=0 && j<10)
    {
        if(kq<data[i][j])
        {
            kq = data[i][j];
        }
        i--;
        j++;
    }
    return kq;
}
int maxcheotrai(int data[10][10], int i1, int j1)
{
    int i = i1,j=j1;
    int kq = data[i][j];
    while (i<10 && j<10)
    {
        if(kq<data[i][j])
        {
            kq = data[i][j];
        }
        i++;
        j++;
    }
    i = i1,j=j1;
    while (i>=0 && j>=0)
    {
        if(kq<data[i][j])
        {
            kq = data[i][j];
        }
        i--;
        j--;
    }
    
    return kq;
}

string tachchuoi(string s, string giatri)
{
    string kq="";
    kq = s.substr(0,s.find(giatri));
    return kq;
}
int passlen(string s)
{
    int len = s.length();
    if(len<8)
        return -1;
    if(len>20)
        return -2;
    
    return -10;
}
int passchuoi(string s)
{
    int vitri=-10;
    string chuoi ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#%$!";
    for(int i = 0;i<s.length(); i++)
    {
        bool flag = false;
        for(int j =0; j<chuoi.length();j++)
        {
            if(s[i]==chuoi[j])
            {
                flag = true;
                break;
            }
        }
        if(flag == false)
        {
            vitri = i;
            break;
        }
    }
    return vitri;
}
int passchuoise(string matkhau, string se)
{
    int vitri = matkhau.find(se);
    if(vitri<0)
        return -10;
    return -(300+vitri);
}
int passchuoisc(string matkhau)
{
    int vitri = -10;
    for(int i =0;i<matkhau.length()-1;i++)
    {
        if(matkhau[i]==matkhau[i+1])
        {
            vitri = i;
            break;
        }
    }
    if(vitri == -10)
        return vitri;
    return -(400+vitri);
}
int passchuoidb(string s)
{
    int vitri=-10;
    bool flag = false;
    std::string chuoi ="@#%$!";
    for(int i = 0;i<s.length(); i++)
    {
        for(int j =0; j<chuoi.length();j++)
        {
            if(s[i]==chuoi[j])
            {
                flag = true;
                break;
            }
        }
        if(flag == true)
        {
            vitri = -10;
            break;
        }
    }
    if(flag ==false)
        vitri = -5;
    return vitri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////