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
int firstMeet(int & EXP1, int & EXP2, int E1) 
{
    // TODO: Complete this function
    if (E1>99) {return -99;}
       int D;
       float e1 =E1;
       if (E1>=0&&E1<=3)
       {
 switch (E1)
        {
        case 0:  EXP2= EXP2 + 29; break;
        case 1:  EXP2= EXP2 + 45; break;
        case 2:  EXP2= EXP2 + 75; break;
        case 3:  EXP2= EXP2 + 29 + 45 + 75; break;
        }

    //XỬ LÍ D
        
        D = e1*3 + EXP1*7;
        if(D%2==0) {EXP1 = ceil(D/200 + EXP1);if(EXP1>600)EXP1 = 600;}
        else {EXP1 = ceil(EXP1 - D/100);if(EXP1<0) EXP1 = 0;}

    }

   else if (E1>=4 && E1<=99)
   {
      if(E1>=4 && E1<=19) EXP2 = ceil(e1/4 + 19 + EXP2);
      else if (E1>=20 && E1<=49) EXP2 = ceil(e1/9 + 21 + EXP2);
      else if(E1>=50 && E1<=65) EXP2= ceil(EXP2 + e1/16 + 17);
      else if (E1>=66 && E1<=79) 
      {
        EXP2 = ceil(EXP2 + e1/4 + 19);
        if(EXP2>200) EXP2 = ceil((EXP2 + e1/9 + 21));
      }
      else if (E1>=80 && E1<=99)
      {
        EXP2= ceil(e1/4 + 19 + e1/9 + 21 + EXP2);
        if(EXP2>400) EXP2 = ceil((EXP2 + e1/16 + 17)*1.15);
      };
    if(EXP2>600) EXP2 = 600;
    EXP1 = EXP1 - E1;

   }
   else return -99;
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    
     //TUYEN DUONG 1
     if (E2>99) {return -99;}
     float i,S;
    float calF,calB,F,B,P;
        for(i=0;i<50;i++)
    {
        F = EXP1 + i;
        B = EXP1 - i;
        calF = sqrt(F) - floor(sqrt(F));
        calB = sqrt(B) - floor(sqrt(B));
        if (calF==0) 
        {
            S = F;break;
        }
        else if (calB==0)
        {
            S = B;break;
        };
    }

    if(EXP1>=S) P=100;
    else P=((EXP1/S +80)/123)*100;

    //TUYEN DUONG 2
    int chi1 = 0, m1 = M1;
    float P2;
    do
    {
        if(HP1<200) 
        {
            HP1 = ceil(HP1*1.3);
            M1 = M1 - 150;
            chi1 = chi1 + 150;
            if((m1*0.5)<=chi1) {break;};
        }
        else
        {
            HP1 = ceil(HP1*1.1);
            M1 = M1 - 70;
            chi1 = chi1 + 70;
            if((m1*0.5)<=chi1) {break;};
        }
        if(EXP1<400) 
        {
            M1 = M1 - 200;
            chi1 = chi1 + 200;
            if((m1*0.5)<=chi1) {break;};
        }
        else 
        {
            M1 = M1 - 120;
            chi1 = chi1 + 120;
            if((m1*0.5)<=chi1) {break;};
        }
        EXP1 = ceil(EXP1*1.13);
        
        if(EXP1<300) 
        {   
            M1 = M1 - 100;
            chi1 = chi1 + 100;
            if((m1*0.5)<=chi1) {break;};
        }
        else 
        {
            M1 = M1 - 120;
            chi1 = chi1 + 120;
            if((m1*0.5)<=chi1) {break;};
        }
    }
     while(E2%2==1&&((m1*0.5)>=chi1));
     
    if(M1<0) M1=0;
    if(EXP1>600) EXP1 = 600;
    if(HP1>666) HP1=666;
     
    if(E2%2==1||M1==0)
    {
        HP1 = ceil(HP1*0.83);
        EXP1 = ceil(EXP1*1.17);
        if(EXP1>600) EXP1 = 600;
        if(HP1<0) HP1=0;
    }
    

        //NHU TUYEN 1

    for(i=0;i<50;i++)
    {
        F = EXP1 + i;
        B = EXP1 - i;
        calF = sqrt(F) - floor(sqrt(F));
        calB = sqrt(B) - floor(sqrt(B));
        if (calF==0) 
        {
            S = F;break;
        }
        else if (calB==0)
        {
            S = B;break;
        };
    }


    if(EXP1>=S) P2=100;
    else P2=((EXP1/S +80)/123)*100;

    //TUYEN DUONG 3
        int ar[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int dau,cuoi, tong;
        float P3;
    if(E2>10)
    {
    dau = E2/10;
    cuoi = E2%10;
    tong = (dau + cuoi)%10;
    P3 = ar[tong];
    }
     else P3 = ar[E2];

    //TONG KET
    float tb;
    if(P==P2&&P2==P3) EXP1 = ceil(EXP1*0.75);
    else
    {
        tb = (P + P2 + P3)/3;
        if(tb<50)
        {
            HP1 = ceil(HP1*0.85);
            EXP1 = ceil(EXP1*1.15);
        }
        else 
        {
            HP1 = ceil(HP1*0.9);
            EXP1 = ceil(EXP1*1.2);
        }
    }
    if(EXP1>600) EXP1 = 600;
    if(HP1>666) HP1=666;

    return HP1 + EXP1 + M1;
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

    //LAP BAN DO
    if (E3>99) {return -99;}
    int bando[10][10],i,j, lon=0, nho=0;
    int dau, duoi, tong, taxi;
     for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            bando[i][j]=((E3*j) + (i*2))*(i-j);
            if(bando[i][j]>(E3*2)) lon = lon + 1;
            else if(bando[i][j]<-(E3)) nho = nho + 1;
        }
    }

    //TINH DIEM TAXI
    if(lon>9)
    {
        dau = lon/10;
        duoi = lon%10;
        tong = dau + duoi; 
        if(tong>9) 
        {
            dau = tong/10;
            duoi = tong%10;
            i = dau + duoi;
        }  else i = tong;
    }
    else i = lon;
    
    if(nho>9)
    {
        dau = nho/10;
        duoi = nho%10;
        tong = dau + duoi; 
        if(tong>9) 
        {
            dau = tong/10;
            duoi = tong%10;
            j = dau + duoi;
        }  else j = tong;
    }
    else j = nho;

    taxi = bando[i][j];

    //TINH DIEM SHERLOCK
    int max_phai_tren,max_phai_duoi,max_trai_tren,max_trai_duoi,max;
    int jL = j,jT = j,iC;
    for(iC=i;iC<10;iC++)
    {
        if(max_phai_duoi<bando[iC][jT]&&iC<10&&jT<10) 
        {
            max_phai_duoi = bando[iC][jT];
            jT++;
        } else jT++;
        if(max_trai_duoi<bando[iC][jL]&&iC<10&&jL>=0)
        {
            max_trai_duoi = bando[iC][jL];
            jL=jL--;
        }   jL--;
    }

    if(max_phai_duoi>max_trai_duoi) max = max_phai_duoi;
    else max = max_trai_duoi;

 jT = j;jL=j;

    for(iC=i;iC>=0;iC--)
  {
        if(max_phai_tren<bando[iC][jT]&&iC>=0&&jT<10) 
        {
            max_phai_tren = bando[iC][jT];
            jT++;
        } else jT=jT++;
        if(max_trai_tren<bando[iC][jL]&&iC>=0&&jT>=0)
        {
            max_trai_tren = bando[iC][j];
             jL--;
        }   else jL--;

    }

    if(max_phai_tren>max) max = max_phai_tren;
    else if (max<max_trai_tren) max = max_phai_tren;

    //SO DIEM CA HAI
   if(abs(taxi)<max)
         {
            HP1 = ceil(HP1*1.1);
            EXP1 = ceil(EXP1*1.12);
            HP2 = ceil(HP2*1.1);
            EXP2 = ceil(EXP2*1.12); 
            return max;
         }
    else 
        {
            HP1 = ceil(HP1*0.9);
            EXP1 = ceil(EXP1*0.88);
            HP2 = ceil(HP2*0.9);
            EXP2 = ceil(EXP2*0.88); 
            return taxi;
        }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    string str = email;
    string se;
    
    //XỬ LÍ EMAIL
    se=str.erase(str.find("@"));

    //XỬ LÍ PASS
    string strs = s;
    
        //TRƯỜNG HỢP ĐỘ DÀI
        if(strs.size()<8) return -1;
            else if(strs.size()>20) return -2;

        //TRƯỜNG HỢP SE
        int findse = strs.find(se);
        if((strs.find(se)<=strs.size())&&(strs.find(se)>=0)) return -(300+findse);

        //TRƯỜNG HỢP NHIỀU KÍ TỰ GIỐNG NHAU
        for(int i = 0; i<=strs.size();i++)
        {
            int finds = strs.find(strs[i]);
            if(strs[i]==strs[i+1]&&s[i]==s[i+2]) return -(400+finds);
        }

        //TRƯỜNG HỢP KÍ TỰ ĐẶC BIỆT
        string special="@#%$!";
        for(int s = 0;s<=4;s++)
        {
            if(strs.find(special[s])>=0&&strs.find(special[s]<=strs.size())) break;
            else if (s==4) return -5;
        }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
string arr[num_pwds];
int p = 0;
while (p<num_pwds)
{
    arr[p] = arr_pwds[p];
    p++;
}

//XU LI
string pass;
int max = 0, trung =1, vitri;
 for(int i = 0; i<=num_pwds;i++)
 {
     for(int k=i+1;k<=num_pwds;k++)
     {
     if(arr[i].size()==arr[k].size()&&arr[k].find(arr[i])==0) trung++;
     }
     
     if (trung>max) 
     {
        pass= arr[i];
        max = trung;
        vitri = i;
     }
     else if(trung == max) 
     {
        if(arr[i].size()>pass.size()) 
        {
            pass = arr[i];
            vitri = i;
        }
     }
     trung = 1;
 }

    return vitri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////