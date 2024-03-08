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

//XỬ LÍ THÔNG SỐ
void xu_li_HP(int& HP){
   if(HP>666) HP = 666;
    if (HP<0) HP = 0;
}

void xu_li_EXP(int& EXP){
   if(EXP>600) EXP = 600;
    if (EXP<0) EXP = 0;
}

void xu_li_M(int& M){
   if(M>3000) M = 3000;
    if (M<0) M = 0;
}

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) 
{
      //XỬ LÍ THÔNG SỐ
    xu_li_EXP(EXP1);
    xu_li_EXP(EXP2);
    if(E1>99 || E1<0) return -99;
    
    // TODO: Complete this function
       int D;
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
        
        D = E1*3 + EXP1*7;
        if(D%2==0) {EXP1 = ceil((float)D/200 + EXP1);}
        else {EXP1 = ceil(EXP1 - (float)D/100);}
         xu_li_EXP(EXP1);
    }
   else if (E1>=4 && E1<=99)
   {
      if(E1>=4 && E1<=19) EXP2 = ceil((float)E1/4 + 19 + EXP2);
      else if (E1>=20 && E1<=49) EXP2 = ceil((float)E1/9 + 21 + EXP2);
      else if(E1>=50 && E1<=65) EXP2= ceil(EXP2 + (float)E1/16 +  17);
      else if (E1>=66 && E1<=79) 
      {
        EXP2 = ceil(EXP2 + (float)E1/4 + 19);
        if(EXP2>200) EXP2 = ceil((EXP2 + (float)E1/9 + 21));
      }
      else if (E1>=80 && E1<=99)
      {
        EXP2= ceil(E1/4 + 19 + (float)E1/9 + 21 + EXP2);
        if(EXP2>400) EXP2 = ceil((EXP2 + (float)E1/16 + 17)*1.15);
    EXP1 = EXP1 - E1;
      }
        xu_li_EXP(EXP1);
        xu_li_EXP(EXP2);
   }
    return EXP1 + EXP2;

}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    
    xu_li_HP(HP1);
    xu_li_EXP(EXP1);
    xu_li_M(M1);
    if(E2>99 || E2<0) return -99;

     //TUYEN DUONG 1
    int CP;
    float P;
    CP = pow(round(sqrt(EXP1)),2);

    if(EXP1>=CP) P=100;
    else P=((EXP1/CP +80)/123)*100;

    //TUYEN DUONG 2
    int chi1 = 0;
    float P2;
    do
    {
        if(HP1<200) 
        {
            HP1 = ceil(HP1*1.3);
            M1 = M1 - 150;
            chi1 = chi1 + 150;
            if((M1*0.5)<=chi1) {break;};
        }
        else
        {
            HP1 = ceil(HP1*1.1);
            M1 = M1 - 70;
            chi1 = chi1 + 70;
            if((M1*0.5)<=chi1) {break;};
        }

            xu_li_HP(HP1);
            xu_li_M(M1);

        if(EXP1<400) 
        {
            M1 = M1 - 200;
            chi1 = chi1 + 200;
            if((M1*0.5)<=chi1) {break;};
        }
        else 
        {
            M1 = M1 - 120;
            chi1 = chi1 + 120;
            if((M1*0.5)<=chi1) {break;};
        }

        xu_li_HP(HP1);
        xu_li_M(M1);
        EXP1 = ceil(EXP1*1.13);
        
        if(EXP1<300) 
        {   
            M1 = M1 - 100;
            chi1 = chi1 + 100;
            if((M1*0.5)<=chi1) {break;};
        }
        else 
        {
            M1 = M1 - 120;
            chi1 = chi1 + 120;
            if((M1*0.5)<=chi1) {break;};
        }
    }
     while(E2%2==1&&((M1*0.5)>=chi1));
     
    xu_li_HP(HP1);
    xu_li_M(M1);
    xu_li_EXP(EXP1);
    
    if(E2%2==1||M1==0)
    {
        HP1 = ceil(HP1*0.83);
        EXP1 = ceil(EXP1*1.17);
    xu_li_HP(HP1);
    xu_li_M(M1);
    xu_li_EXP(EXP1);
    }
    

        //NHU TUYEN 1
    CP = pow(round(sqrt(EXP1)),2);

    if(EXP1>=CP) P2=100;
    else P2=((EXP1/CP +80)/123)*100;

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

    xu_li_HP(HP1);
    xu_li_EXP(EXP1);
         
    return HP1 + EXP1 + M1;
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

    //LAP BAN DO
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

    xu_li_HP(HP1);
    xu_li_HP(HP2); 
    xu_li_EXP(EXP1);
    xu_li_EXP(EXP2);

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