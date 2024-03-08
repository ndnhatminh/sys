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
//Task 1
int firstMeet(int &EXP1, int &EXP2, int E1)
{
   
    if (
        E1<0||E1>99
    )
        return -99;
    else 
   {
      bool ok=false;
   
    {
    if (
       E1>=0&&E1<=3
    )
    
    {
        if (
           E1==0
        )
        {
             EXP2+=29;
        }
        else if (
            E1==1
        )
        {
             EXP2+=45;
        }
        else if (
           E1==2
        )
        {
             EXP2+=75;
        }
        else if (
           E1==3
        )
        {
           EXP2+=149;
           ok=true;
        }
        int D=E1*3 + EXP1*7;
        if (
            D%2==0
        )
        {
            D=ceilf(D/200.0);
            EXP1+=D;
        }
        else 
        {
            D=floor(D/100.0);
            EXP1-=D;
        }
        
    }
    else
    { 
         double temp1=E1/4.0 +19;
            temp1=ceilf(temp1);
            double temp2=E1/9.0 +21;
            temp2=ceilf(temp2);
              double temp3=E1/16.0 +17;
            temp3=ceilf(temp3);
        if (
           E1>=4&&E1<=19
        )
        {
            EXP2+=temp1;
        }
        else if (
              E1>=20&&E1<=49
        )
        {
            EXP2+=temp2;
        }
        else if (
               E1>=50&&E1<=65
        )
        {
            EXP2+=temp3;
        }
        else if (
           E1>=66&&E1<=79
           )
        {    
            EXP2+=temp1;
            if (
                EXP2>200
            )
            {
               EXP2+=temp2;
            }
        }
        else if (
            E1>=80&&E1<=99
        )
        {
           EXP2+=(temp1 + temp2);
            if (
                EXP2>400
            )
            {
              EXP2+=temp3;
              ok=true;
            }
        }
        EXP1-=E1;
    }
    }
    if (ok)
    EXP2=ceilf(EXP2*1.15);
}
    if (EXP1>600)
        EXP1=600;
        if (EXP2>600)
        EXP2=600;
    if (EXP1<0)
    EXP1=0;
    if (EXP2<0)
    EXP2=0;
    return EXP1 + EXP2;
}

//! Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{   
    if (E2<0||E2>99)
    return -99;
    double P1, P2, P3;
    int S = round(sqrt(EXP1));
    if ((S+1)*(S+1)-EXP1>EXP1-S*S)
    S=S*S;
    else
    S=(S*1)*(S+1);
    if (EXP1 >= S)
    {
        P1 = 100;
    }
    else
    {
        P1 = (100*(1.0*EXP1/S + 80)/123);
    }

    if (E2 % 2 == 0)
    {
        while (M1)
        {
            double tempHP,tempEXP;
            if (HP1<200)
            {
                tempHP=HP1*0.3;
                tempHP=ceilf(tempHP);
                HP1+=tempHP;
                M1-=150;
            }
            else 
            {
                tempHP=HP1*0.1;
                tempHP=ceilf(tempHP);
                HP1+=tempHP;
                M1-=70;
            }
            if (M1 <= 0)
                break;

           if (EXP1<400)
           M1-=200;
           else
           M1-=120;
           tempEXP=EXP1*0.13;
           tempEXP=ceilf(tempEXP);
           EXP1+=tempEXP;
            if (M1 <= 0)
                break;

           if (EXP1<300)
           M1-=100;
           else
           M1-=120;
           tempEXP=EXP1*0.1;
           tempEXP=floor(tempEXP);
           EXP1-=tempEXP;

            break;
        }
    }
    else
    {
        double halfM = 0.5 * M1;
        while (M1)
        {
           double tempHP,tempEXP;
            if (HP1<200)
            {
                tempHP=HP1*0.3;
                tempHP=ceilf(tempHP);
                HP1+=tempHP;
                M1-=150;
            }
            else 
            {
                tempHP=HP1*0.1;
                tempHP=ceilf(tempHP);
                HP1+=tempHP;
                M1-=70;
            }
            if (M1 <= 0 || M1 < halfM)
                break;
           if (EXP1<400)
           M1-=200;
           else
           M1-=120;
           tempEXP=EXP1*0.13;
           tempEXP=ceilf(tempEXP);
           EXP1+=tempEXP;

            if (M1 <= 0 || M1 < halfM)
                break;
            if (EXP1<300)
           M1-=100;
           else
           M1-=120;
           tempEXP=EXP1*0.1;
           tempEXP=floor(tempEXP);
           EXP1-=tempEXP;

            if (M1 <= 0 || M1 < halfM)
                break;
            }
        }

   if (HP1>666)
   HP1=666;
   HP1=ceilf(HP1*0.83);
   EXP1=ceilf(EXP1* 1.17);
   if (EXP1>600)
   EXP1=600;

    S = round(sqrt(EXP1));
    if ((S+1)*(S+1)-EXP1>EXP1-S*S)
    S=S*S;
    else
    S=(S*1)*(S+1);
    if (EXP1 >= S)
    {
        P2 = 100;
    }
    else
    {
        P2 =100*(1.0*EXP1/S +80)/123;
    }

    double P[10] = {32,47,28,69,100,50,22,83,64,11};

    int index = (E2 / 10 + E2 % 10) % 10;
    P3 = P[index];

    double Ptrungbinh = (P1+P2+P3)/3;

    if (
       P1==100&&P2==100&&P3==100
    )
    {
        EXP1=ceilf(EXP1*0.75);
    }
    else if (
         Ptrungbinh < 50
    )
    {
        HP1=ceilf(HP1*0.85);
        EXP1=ceilf(EXP1*1.15);
    }
    else
    {
        HP1=ceilf(HP1*0.9);
        EXP1=ceilf(EXP1*1.2);
    }
    if (EXP1>600)
    EXP1=600;
    if (M1<0)
    M1=0;
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
       int a[10][10];
       if (E3<0||E3>99)
        return -99;
   int e3=E3,lonhon=0,nhohon=0;
//   cin>>e3;
   for (int i=0;i<10;i++)
    for (int j=0;j<10;j++)
    {
        a[i][j]=((e3 * j) + (i * 2)) * (i - j);
        if (a[i][j]>e3*2)
        lonhon++;
        else if (a[i][j]<-e3)
        nhohon++;
    }
 //   cout<<lonhon<<" "<<nhohon;
    lonhon=(lonhon%10 + (lonhon/10)%10);
    lonhon=(lonhon%10 + (lonhon/10)%10);
   // cout <<lonhon;
    nhohon=(nhohon%10 + (nhohon/10)%10);
    nhohon=(nhohon%10 + (nhohon/10)%10);
  //  cout<<nhohon<<endl;
    int tong,hieu;
    tong=lonhon+nhohon;
    hieu=abs(lonhon-nhohon);
  //  cout<<tong<<" "<<hieu<<endl; 
  //  cout<<tong <<endl<<hieu<<endl;
     int dem=0,dem1=0;
   
        for (int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
            if ((i+j)==tong)
            dem++;
            if (abs(i-j)==hieu)
                dem1++;
        }
     //   cout<<dem+(dem1/2-1)<<endl;
    int b[dem+(dem1/2-1)];
  //  cout<<dem+(dem1/2-1);
    int dem_b=0;
    for (int i=0;i<=9;i++)
        for(int j=0;j<=9;j++)
        {
            if ((i+j)==tong)
            {
                b[dem_b]=a[i][j];
                 dem_b++;
            }
            else if (abs(i-j)==hieu)
            {
                if(lonhon>=nhohon)
            {   
                if ((i-j)==7)
                {
                b[dem_b]=a[i][j];
                dem_b++;
                }
            }
            else //if(lonhon<nhohon)
            {
                if ((j-i)==7)
                {
                b[dem_b]=a[i][j];
                dem_b++;
                }
            }
            }
        }
     //   cout<<"dem b la "<<dem_b<<endl;
    int max=b[0];
    for (int i=1;i<dem_b;i++)
    if (b[i]>max)
    max=b[i];
 /*  cout<<max;
   cout<<endl;
   for (int i=0;i<dem_b;i++)
   cout<<b[i]<<" ";
   cout<<endl;
    for (int i=0;i<10;i++)
    {
    for (int j=0;j<10;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
    */
   if (abs(a[lonhon][nhohon])>max)
    {
        EXP1=ceilf(EXP1*0.88);
        EXP2=ceilf(EXP2*0.88);
        HP1=ceilf(HP1*0.9);
        HP2=ceilf(HP2*0.9);
    }
    else 
    {
        EXP1=ceilf(EXP1*1.12);
        EXP2=ceilf(EXP2*1.12);
        HP1=ceilf(HP1*1.1);
        HP2=ceilf(HP2*1.1);
    }
    if (EXP1>600)
    EXP1=600;
    if (EXP2>600)
    EXP2=600;
    if (HP1>666)
    HP1=666;
    if (HP2>666)
    HP2=666;
    return a[lonhon][nhohon];
}

// Task 4
 int checkPassword(const char * s, const char * email)
{
 string se(email);
    se = se.substr(0, se.find("@"));
    string str(s);

    if (
       str.length()<8
    )
    {
        return -1;
    }

    if (
        str.length()>20
    )
    {
        return -2;
    }

    if (
        str.find(se) != string::npos
    )
    {
        return -(300 + str.find(se));
    }

    for (
       int i = 0;i<str.length()-2;i++
    )
    {
        if (
            str[i]==str[i+1]&&str[i+1]==str[i+2]
        )
        {
            return -(400+i);
        }
    }

    if (
        str.find("!")== string::npos && str.find("@")== string::npos && str.find("#")== string::npos && str.find("$")== string::npos && str.find("%")== string::npos 
    )
    {
        return -5;
    }

    for (int i = 0;i<str.length();i++)
    
        if (
             (str[i] >= 'a' && str[i] <= 'z')
             || (str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] >= '0' && str[i] <= '9')
            || (str[i] == '!' || str[i] == '@' || str[i] == '#' || str[i] == '$' || str[i] == '%')
        )
        int khong_lam_gi_ca;
        else return i;
       
        
        
        
    

    return -10;
}


// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) 
{
    int soLanXuatHienMax = 0;
    int viTriMax = 0;

    for (int i = 0; i < num_pwds; ++i) 
    {
        int soLanXuatHien = 0;

        for (int j = i; j < num_pwds; ++j) 
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) 
            {
                soLanXuatHien++;
            }
        }

        if (soLanXuatHien > soLanXuatHienMax) 
        {
            soLanXuatHienMax = soLanXuatHien;
            viTriMax = i;
        } 
        else if (soLanXuatHien == soLanXuatHienMax) 
        {
            if (strlen(arr_pwds[i]) > strlen(arr_pwds[viTriMax])) 
            {
                viTriMax = i;
            }
        }
    }

    return viTriMax;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////