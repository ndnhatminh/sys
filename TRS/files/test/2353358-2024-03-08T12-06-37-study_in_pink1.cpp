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

//Chinh input
void chinh_hp(int & hp){
    if (hp < 0) hp = 0;
    if (hp > 666) hp = 666;
}

void chinh_exp(int & exp){
    if (exp < 0) exp = 0;
    if (exp > 600) exp = 600;
}

void chinh_m(int & m){
    if (m < 0) m = 0;
    if (m > 3000) m = 3000;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    // Truong hop 1
     chinh_exp(exp1); chinh_exp(exp2);
    int D;
    if ((e1 < 0) || (e1 > 99)) return -99; else 
    if (e1>=0 && e1<=3) {
    switch (e1)
    { case 0: exp2= exp2 + 29; break;
    case 1: exp2 = exp2 + 45; break;
    case 2: exp2 = exp2 + 75; break;
    case 3: exp2 = exp2 + 29 + 45 + 75; }
    chinh_exp(exp2);
    D= e1 * 3 + exp1 * 7;
    if (D%2==0) exp1 = ceil(exp1 + D/200.00);
   // if (exp1>600) exp1 = 600;
    else {exp1 = ceil(exp1 - D/100.00);}
    chinh_exp(exp1); 
    std::cout<< exp1 + exp2;
} else

    // Truong hop 2
    
{ 
    if (e1>=4 && e1<=19 ) exp2=ceil(exp2 + e1/4.00 +19);
    else if (e1>=20 && e1<=49) exp2=ceil(exp2+e1/9.00 +21);
    else if (e1>=50 && e1<=65) exp2=ceil(exp2 + e1/16.00 +17);
    else if (e1>=66 && e1<=79) 
    {
    exp2 = ceil (exp2+e1/4.00+19);
    if(exp2 >200)exp2=ceil(exp2+e1/9.00+21);
    }
    else if (e1>=80 && e1<=99)
    {exp2= ceil(exp2 + e1/4.00 +19 + e1/9.00 +21);
    if (exp2>400) exp2=ceil((exp2 +e1/16.00 +17)*1.15);
    }
    if (exp2>600) exp2=600;
    exp1 =exp1 -e1;
    chinh_exp(exp1); chinh_exp(exp2);
    return exp1 + exp2;
    



}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // CON DUONG 01---------------------------------------------------------------------------------------
    if ((E2 < 0) && (E2 > 99)) return -99; else{
    chinh_hp(HP1); chinh_exp(EXP1); chinh_m(M1);
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

    // CON DUONG 2---------------------------------------------------------------------------------------
    int chitra = 0, m1 = M1;
    float P2;
    do
    {
        if(HP1<200) 
        {
            HP1 = ceil(HP1+HP1*0.3);
            M1 = M1 - 150;
            chinh_hp(HP1); chinh_exp(EXP1); chinh_m(M1);
            chitra = chitra + 150;
            if(chitra>=(m1*0.5)) {break;};
        }
        else
        {
            HP1 = ceil(HP1+HP1*0.1);
            M1 = M1 - 70;
            chinh_hp(HP1); chinh_exp(EXP1); chinh_m(M1);
            chitra = chitra + 70;
            if(chitra>=(m1*0.5)) {break;};
        }
        if(EXP1<400) 
        {
            M1 = M1 - 200;
            chinh_hp(HP1); chinh_exp(EXP1); chinh_m(M1);
            chitra = chitra + 200;
            if(chitra>=(m1*0.5)) {break;};
        }
        else 
        {
            M1 = M1 - 120;
            chinh_hp(HP1); chinh_exp(EXP1); chinh_m(M1);
            chitra = chitra + 120;
            if(chitra>=(m1*0.5)) {break;};
        }
        EXP1 = ceil(EXP1+EXP1*0.13);
        chinh_hp(HP1); chinh_exp(EXP1); chinh_m(M1);
        if(EXP1<300) 
        {   
            M1 = M1 - 100;
            chinh_hp(HP1); chinh_exp(EXP1); chinh_m(M1);
            chitra = chitra + 100;
            if(chitra>=(m1*0.5)) {break;};
        }
        else 
        {
            M1 = M1 - 120;
            chinh_hp(HP1); chinh_exp(EXP1); chinh_m(M1);
            chitra = chitra + 120;
            if(chitra>=(m1*0.5)) {break;};
        }
    }
    //
     while(E2%2==1&&((m1*0.5)>=chitra));
     
  
     
    if(E2%2==1||M1==0)
    {
        HP1 = ceil(HP1-HP1*0.17);
        EXP1 = ceil(EXP1+EXP1*0.17);
        chinh_hp(HP1); chinh_exp(EXP1); chinh_m(M1);
    }
    //TINH XAC SUAT
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

     // CON DUONG 3
 int ar[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int dau, cuoi, tong;
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
            chinh_hp(HP1); chinh_exp(EXP1); chinh_m(M1);
        }
        else 
        {
            HP1 = ceil(HP1*0.9);
            EXP1 = ceil(EXP1*1.2);
            chinh_hp(HP1); chinh_exp(EXP1); chinh_m(M1);
        }
    }
    chinh_hp(HP1); chinh_exp(EXP1); chinh_m(M1);

    return HP1 + EXP1 + M1;}
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ((E3 < 0) && (E3 > 99)) return -99; else{
        chinh_hp(HP1); chinh_hp(HP2); chinh_exp(EXP1); chinh_exp(EXP2);
    int map[10][10] = {};
    int i, j;
    int pos = 0, neg = 0;
    int dau, cuoi, sum, taxi;
    
    for ( i = 0; i < 10; i++)
    {
        for ( j = 0; j < 10; j++)
        {
            map[i][j] = (i - j) * ((E3 * j)+ (i * 2));
            if (map[i][j] > (E3 * 2))
                pos ++;
            else if (map[i][j] < (-E3))
                neg ++;
        }
    }
    //TINH DIEM SHERLOCK --------------------------------------------------------------------------------
    int maxPT,maxPD,maxTT,maxTD,max;
    int jL = j,jT = j,iC;
    for(iC=0;iC<10;iC++)
    { if(maxPD<map[iC][jT] && iC<10 && jT<10) 
        {
            maxPD = map[iC][jT];
            jT++;
        } else jT++;
        if(maxTD<map[iC][jL] && iC<10 && jL>=0)
        {
            maxTD = map[iC][jL];
            jL--;
        }   jL--;
    }

    if(maxPD>maxTD) 
    max = maxPD;
    else max = maxTD;

 jT = j;jL=j;

    for(iC=i;iC>=0;iC--)
    { if(maxPT<map[iC][jT] && iC>=0 && jT<10) 
        {
            maxPT = map[iC][jT];
            jT++;
        } else jT = jT++;
        if(maxTT<map[iC][jL] && iC>=0 && jT>=0)
        {
            maxTT = map[iC][j];
             jL--;
        }   else jL--;

    }

   if(maxPT>max) max = maxPT;
    else if (max<maxTT) max = maxPT;

    //DIEM CA HAI-------------------------------------------------------------------------------------------
   if(abs(taxi)<max)
         {
            HP1 = ceil(HP1+HP1*0.1);
            EXP1 = ceil(EXP1+EXP1*0.12);
            HP2 = ceil(HP2+HP2*0.1);
            EXP2 = ceil(EXP2+EXP2*0.12); 
            chinh_hp(HP1); chinh_hp(HP2); chinh_exp(EXP1); chinh_exp(EXP2);
            return max;
         }
    else 
        {
            HP1 = ceil(HP1-HP1*0.1);
            EXP1 = ceil(EXP1-EXP1*0.12);
            HP2 = ceil(HP2-HP2*0.1);
            EXP2 = ceil(EXP2-EXP2*0.12); 
            chinh_hp(HP1); chinh_hp(HP2); chinh_exp(EXP1); chinh_exp(EXP2);
            return taxi;
        }
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    string str = email;
    string se;
    
  
    se=str.erase(str.find("@"));

  
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
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////